#include "ParseXml.hpp"
#include "ConstantInfo.hpp"
#include "Depens.hpp"
#include "EnumInfo.hpp"
#include "FunctionInfo.hpp"
#include "ObjectInfo.hpp"
#include "StructInfo.hpp"
#include "TypeInfo.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "XmlUtils.hpp"

using namespace tinyxml2;

static const std::unordered_map<std::string, std::string> &parseHandles(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> handles;
    if (!handles.empty())
        return handles;
    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (HasAttributeValue(type, "category", "handle") && !HasAttribute(type, "alias")) {
            std::string name = FirstChildElement(type, "name").GetText();
            if (HasAttribute(type, "parent")) {
                handles[name] = Attribute(type, "parent");
            } else {
                handles[name] = "";
            }
        }
    });
    return handles;
}

static const std::unordered_map<std::string, std::string> &parseObjectType(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> objectTypes;
    if (!objectTypes.empty())
        return objectTypes;
    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "handle"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        std::string name = FirstChildElement(type, "name").GetText();
        assert(HasAttribute(type, "objtypeenum"));
        objectTypes[name] = Attribute(type, "objtypeenum");
    });
    return objectTypes;
}

static TypeAndName parseTypeAndName(XMLElement &param) {
    std::string name;
    std::string baseType;
    std::string leading;
    std::string postType;
    std::string trailing;
    std::string commentText;

    int state = 0; // 0 = before <type>, 1 = after <type> before <name>, 2 = after <name>
    for (XMLNode *node = param.FirstChild(); node; node = node->NextSibling()) {
        if (XMLText *txt = node->ToText()) {
            const char *v = txt->Value();
            std::string text = v ? v : "";
            if (state == 0) {
                leading += text;
            } else if (state == 1) {
                postType += text;
            } else {
                trailing += text;
            }
        } else if (XMLElement *el = node->ToElement()) {
            std::string_view ename = el->Name();
            if (ename == "type") {
                state = 1;
                if (const char *t = el->GetText())
                    baseType += t;
            } else if (ename == "name") {
                state = 2;
                if (const char *n = el->GetText())
                    name += n;
            } else if (ename == "comment") {
                if (const char *c = el->GetText())
                    commentText += c;
            } else {
                if (const char *t = el->GetText()) {
                    if (state == 0)
                        leading += t;
                    else if (state == 1)
                        postType += t;
                    else
                        trailing += t;
                }
            }
        } else if (XMLComment *xc = node->ToComment()) {
            (void)xc;
        }
    }

    return TypeAndName(trim_copy(name), trim_copy(baseType), trim_copy(leading),
                       trim_copy(postType), trim_copy(trailing));
}

static const std::unordered_set<std::string> &parseNotInternalFeatureNames(XMLElement &registry) {
    static std::unordered_set<std::string> notInternelFeatureNames;
    if (!notInternelFeatureNames.empty())
        return notInternelFeatureNames;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal"))
            return;
        notInternelFeatureNames.insert(Attribute(feature, "name"));
    });
    return notInternelFeatureNames;
}

static const std::unordered_map<std::string, std::string> &
parsePlatformMacros(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> platformMakros;
    if (!platformMakros.empty())
        return platformMakros;
    XMLElement &platforms = FirstChildElement(registry, "platforms");
    ForEach(platforms, "platform", [&](XMLElement &platform) {
        if (!HasAttribute(platform, "name"))
            return;
        if (!HasAttribute(platform, "protect"))
            return;
        platformMakros[Attribute(platform, "name")] = Attribute(platform, "protect");
    });
    return platformMakros;
}

static std::unordered_set<std::string> splitCSL(const std::string &s) {
    return s | std::views::split(',') | std::ranges::to<std::unordered_set<std::string>>();
}

static std::string composeGuard(const std::string &extension, const std::string &depends,
                                XMLElement &registry) {
    const std::unordered_set<std::string> &notInternal = parseNotInternalFeatureNames(registry);

    std::unordered_set<std::string> allFeatures;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;
        allFeatures.insert(Attribute(feature, "name"));
    });

    std::unordered_set<std::string> internalFeatures;
    for (auto &f : allFeatures) {
        if (!notInternal.contains(f))
            internalFeatures.insert(f);
    }

    const std::string &s = depends;
    std::vector<std::string> parts;
    parts.reserve(32);
    size_t i = 0;
    auto isAtomChar = [](char c) {
        return std::isalnum(static_cast<unsigned char>(c)) || c == '_' || c == ':';
    };
    while (i < s.size()) {
        char c = s[i];
        if (std::isspace(static_cast<unsigned char>(c))) {
            ++i;
            continue;
        }
        if (c == '(' || c == ')') {
            parts.emplace_back(1, c);
            ++i;
            continue;
        }
        if (c == '+' || c == '&' || c == ',' || c == '|') {
            parts.emplace_back(1, c);
            ++i;
            continue;
        }
        // atom
        size_t start = i;
        while (i < s.size() && isAtomChar(s[i]))
            ++i;
        parts.emplace_back(s.substr(start, i - start));
    }

    auto is_and_op = [](const std::string &op) {
        return op.size() == 1 && (op[0] == '+' || op[0] == '&');
    };
    auto is_or_op = [](const std::string &op) {
        return op.size() == 1 && (op[0] == ',' || op[0] == '|');
    };

    std::string out;
    out.reserve(128);

    auto append_token = [&](const std::string &tok) {
        if (!out.empty())
            out += ' ';
        out += tok;
    };

    auto next_meaningful_index = [&](size_t from) -> size_t {
        for (size_t j = from; j < parts.size(); ++j) {
            const auto &p = parts[j];
            if (p.empty())
                continue;
            if (p == "(" || p == ")")
                return j;
            if (is_and_op(p) || is_or_op(p))
                continue;
            if (p.find("::") != std::string::npos)
                continue;
            if (internalFeatures.contains(p))
                continue;
            return j;
        }
        return parts.size();
    };

    bool prev_was_piece = false;
    for (size_t idx = 0; idx < parts.size(); ++idx) {
        const std::string &p = parts[idx];
        if (p.empty())
            continue;
        if (p == "(") {
            size_t nx = next_meaningful_index(idx + 1);
            if (nx < parts.size()) {
                append_token("(");
                prev_was_piece = false;
            }
            continue;
        }
        if (p == ")") {
            if (prev_was_piece) {
                append_token(")");
                prev_was_piece = true;
            }
            continue;
        }
        if (is_and_op(p) || is_or_op(p)) {
            std::string mapped = is_and_op(p) ? "&&" : "||";
            size_t nx = next_meaningful_index(idx + 1);
            if (prev_was_piece && nx < parts.size()) {
                append_token(mapped);
                prev_was_piece = false;
            }
            continue;
        }
        const std::string atom = p;
        if (atom.find("::") != std::string::npos) {
            continue;
        }
        if (internalFeatures.contains(atom)) {
            continue;
        }
        std::string def = std::string("defined(") + atom + ")";
        append_token(def);
        prev_was_piece = true;
    }

    auto trim = [](std::string &str) {
        size_t a = 0;
        while (a < str.size() && std::isspace(static_cast<unsigned char>(str[a])))
            ++a;
        size_t b = str.size();
        while (b > a && std::isspace(static_cast<unsigned char>(str[b - 1])))
            --b;
        if (a == 0 && b == str.size())
            return;
        str = str.substr(a, b - a);
    };
    trim(out);

    std::string extCheck;
    if (!extension.empty()) {
        extCheck = "defined(" + extension + ")";
    }

    if (extCheck.empty() && out.empty()) {
        return std::string();
    }
    if (!extCheck.empty() && out.empty()) {
        return extCheck;
    }
    if (extCheck.empty() && !out.empty()) {
        return out;
    }
    return "(" + extCheck + " && (" + out + "))";
}

// string_view to prevent dangling refrence, when passing a string literal
static const std::unordered_map<std::string, Depends> &
parseObjectDepents(XMLElement &registry, std::string_view objectSV) {

    static std::unordered_map<std::string, std::unordered_map<std::string, Depends>>
        allObjectDepends;
    std::string object{objectSV};
    std::unordered_map<std::string, Depends> &objectDepends = allObjectDepends[object];
    if (!objectDepends.empty())
        return objectDepends;

    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;
        std::string featureName = Attribute(feature, "name");
        ForEach(feature, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                std::string typeName = Attribute(type, "name");
                auto &objDepends = objectDepends[typeName];
                std::string featureGuard = composeGuard(std::string(), featureName, registry);
                if (featureGuard.empty())
                    return;
                if (!objDepends.guard.empty()) {
                    objDepends.guard = objDepends.guard + " || " + featureGuard;
                } else {
                    objDepends.guard = featureGuard;
                }
            });
        });
    });

    const std::unordered_map<std::string, std::string> &platformMakros =
        parsePlatformMacros(registry);

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            std::string depends;
            if (HasAttribute(require, "depends")) {
                depends = Attribute(require, "depends");
            }
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                auto &objDepends = objectDepends[Attribute(type, "name")];
                if (HasAttribute(extension, "platform")) {
                    std::string platform = Attribute(extension, "platform");
                    assert(objDepends.platform == "" ||
                           objDepends.platform == platformMakros.at(platform));
                    objDepends.platform = platformMakros.at(platform);
                }
            });
        });
    });

    return objectDepends;
}

// string_view to prevent dangling refrence, when passing a string literal
static const std::unordered_set<std::string> &parseObjectsDisabled(XMLElement &registry,
                                                                   std::string_view objectSV) {

    static std::unordered_map<std::string, std::unordered_set<std::string>> allObjectsDisabled;
    std::string object{objectSV};
    std::unordered_set<std::string> &objectsDisabled = allObjectsDisabled[object];
    if (!objectsDisabled.empty())
        return objectsDisabled;

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        bool extensionUnsupported = HasAttribute(extension, "supported") &&
                                    !splitCSL(Attribute(extension, "supported")).contains("vulkan");
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) {
            bool apiUnsupported = HasAttribute(require, "api") &&
                                  !splitCSL(Attribute(require, "api")).contains("vulkan");
            if (!extensionUnsupported && !apiUnsupported)
                return;
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.insert(Attribute(type, "name"));
            });
        });
    });

    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal"))
            return;
        bool featureUnsupported =
            HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan");

        ForEach(feature, "require", [&](XMLElement &require) {
            bool apiUnsupported = HasAttribute(require, "api") &&
                                  !splitCSL(Attribute(require, "api")).contains("vulkan");
            if (!featureUnsupported && !apiUnsupported)
                return;
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.insert(Attribute(type, "name"));
            });
        });
    });

    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.erase(Attribute(type, "name"));
            });
        });
    });

    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;

        ForEach(feature, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.erase(Attribute(type, "name"));
            });
        });
    });

    return objectsDisabled;
}

static std::tuple<std::unordered_map<std::string, Function>,
                  std::unordered_map<std::string, std::set<FunctionInfo>>>
parseGroupedFunctions(XMLElement &registry) {
    static std::unordered_map<std::string, std::set<FunctionInfo>> groupedFunctions;
    static std::unordered_map<std::string, Function> destroyFunctions;
    if (!groupedFunctions.empty() || !destroyFunctions.empty())
        return std::make_tuple(destroyFunctions, groupedFunctions);
    const std::unordered_map<std::string, std::string> &handles = parseHandles(registry);
    std::vector<Function> functions;

    const std::unordered_set<std::string> objectsDisabled =
        parseObjectsDisabled(registry, "command");

    XMLElement &commands = FirstChildElement(registry, "commands");
    ForEach(commands, "command", [&](XMLElement &command) {
        if (HasAttribute(command, "alias"))
            return;
        std::vector<std::string> success;
        if (HasAttribute(command, "successcodes")) {
            std::string successcodes = Attribute(command, "successcodes");
            success =
                successcodes | std::views::split(',') | std::ranges::to<std::vector<std::string>>();
        }
        std::vector<std::string> error;
        if (HasAttribute(command, "errorcodes")) {
            std::string errorcodes = Attribute(command, "errorcodes");
            error =
                errorcodes | std::views::split(',') | std::ranges::to<std::vector<std::string>>();
        }

        XMLElement &proto = FirstChildElement(command, "proto");
        std::string name = FirstChildElement(proto, "name").GetText();
        if (name == "vkCreateDisplayModeKHR")
            return; // TODO FIX
        if (objectsDisabled.contains(name))
            return;
        std::string returnType = FirstChildElement(proto, "type").GetText();
        std::vector<Function::Argument> args;
        ForEach(command, "param", [&](XMLElement &param) {
            if (HasAttribute(param, "api") && !splitCSL(Attribute(param, "api")).contains("vulkan"))
                return;
            Function::Argument arg;
            arg = parseTypeAndName(param);
            if (HasAttribute(param, "len")) {
                const std::string len = Attribute(param, "len");
                if (len != "null-terminated" && len != "1" && !len.contains("->") &&
                    !len.starts_with("latexmath")) {
                    auto it = std::ranges::find_if(
                        args, [&len](const Function::Argument &arg) { return arg.name == len; });
                    assert(it != args.end());
                    arg.arrayWithLengthOf = std::distance(args.begin(), it);
                }
            }
            if (HasAttribute(param, "optional")) {
                arg.optional = splitCSL(Attribute(param, "optional")).contains("true");
            }
            arg.name = FirstChildElement(param, "name").GetText();
            args.push_back(std::move(arg));
        });
        functions.emplace_back(name, std::move(success), std::move(error), std::move(args),
                               returnType);
    });

    const std::unordered_map<std::string, Depends> &functionDepends =
        parseObjectDepents(registry, "command");

    for (const auto &f : functions) {
        if (f.name.starts_with("vkDestroy")) {
            if (f.args.size() == 2) { // VkDevice
                destroyFunctions[f.args[0].baseType] = f;
            } else {
                assert(
                    (f.name.starts_with("vkDestroy") && f.args.size() == 3) ||
                    (f.name.starts_with("vkFree") && (f.args.size() == 3 || f.args.size() == 4)));
                destroyFunctions[f.args[1].baseType] = f;
            }
            continue;
        }
        if (f.name.starts_with("vkFree")) {
            if (f.name == "vkFreeMemory") {
                destroyFunctions[f.args[1].baseType] = f;
            } else {
                auto name = f.args[3].baseType.substr(2) + "s";
                destroyFunctions[name] = f;
            }
            continue;
        }
        std::string handle = f.args[0].baseType;
        FunctionInfo fInfo;
        fInfo.function = f;
        if (functionDepends.contains(f.name)) {
            fInfo.depends = functionDepends.at(f.name);
        }
        if (handles.contains(handle)) {
            fInfo.handle = handle;
            groupedFunctions[f.args[0].baseType].insert(fInfo);
        } else {
            groupedFunctions[""].insert(fInfo);
        }
    }
    return std::make_tuple(destroyFunctions, groupedFunctions);
}

static const std::unordered_map<std::string, std::string> &
parseTypeStructureName(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> typeStructureName;
    if (!typeStructureName.empty())
        return typeStructureName;

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "struct"))
            return;
        if (!HasAttribute(type, "name"))
            return;
        std::string name = Attribute(type, "name");
        std::string structureType;
        ForEachBreak(type, "member", [&](XMLElement &member) {
            bool hasStructureType = false;
            ForEachBreak(member, "type", [&](XMLElement &memberType) {
                if (HasText(memberType, "VkStructureType")) {
                    hasStructureType = true;
                    if (!HasAttribute(member, "values"))
                        return false;
                    structureType = Attribute(member, "values");
                }
                return false;
            });
            return hasStructureType;
        });
        if (structureType != "") {
            typeStructureName[name] = std::move(structureType);
        }
    });
    return typeStructureName;
}

const std::set<TypeInfo> &parseTypeInfos(XMLElement &registry) {
    static std::set<TypeInfo> typeInfos;
    if (!typeInfos.empty())
        return typeInfos;

    const std::unordered_map<std::string, std::string> &typeStructureName =
        parseTypeStructureName(registry);

    const std::unordered_map<std::string, Depends> &typeDepends =
        parseObjectDepents(registry, "type");

    const std::unordered_set<std::string> &objectsDisabled = parseObjectsDisabled(registry, "type");

    auto CreateTypeInfo = [&](std::string name) {
        TypeInfo info;
        info.name = name;
        info.structureType = typeStructureName.at(name);
        if (auto it = typeDepends.find(name); it != typeDepends.end()) {
            info.depends = it->second;
        }
        return info;
    };
    for (const auto &[name, _] : typeStructureName) {
        if (objectsDisabled.contains(name))
            continue;
        typeInfos.emplace(CreateTypeInfo(name));
    }
    return typeInfos;
}

const std::set<ObjectInfo> &parseObjectInfos(XMLElement &registry) {
    static std::set<ObjectInfo> objectInfos;
    if (!objectInfos.empty())
        return objectInfos;

    auto [destroyFunctions, functions] = parseGroupedFunctions(registry);
    FunctionInfo::destroyFunctions = destroyFunctions;

    std::unordered_map<std::string, std::string> handleOwner = parseHandles(registry);

    for (auto &[handle, owner] : handleOwner) {
        if (auto it = destroyFunctions.find(handle);
            it != destroyFunctions.end() && handle != "VkInstance" && handle != "VkDevice" &&
            it->second.args.front().baseType != owner) {
            std::cout
                << "Info: " << handle << " is owned by " << owner
                << " according to the parent property of the vk.xml type but is destroyed by: "
                << it->second.args.front().baseType << " using that instead\n";
            owner = it->second.args.front().baseType;
        }
    }

    auto buildRankFromParent = [](const std::unordered_map<std::string, std::string> &parent) {
        std::unordered_set<std::string> all;
        all.reserve(parent.size() * 2);
        for (auto const &p : parent) {
            all.insert(p.first);
            if (!p.second.empty())
                all.insert(p.second);
        }

        std::unordered_map<std::string, std::vector<std::string>> children;
        children.reserve(all.size() * 2);
        for (auto const &n : all)
            children.emplace(n, std::vector<std::string>{});
        for (auto const &p : parent) {
            if (!p.second.empty())
                children[p.second].push_back(p.first);
        }

        std::vector<std::string> roots;
        roots.push_back("VkInstance");

        std::unordered_map<std::string, int> lvl;
        lvl.reserve(all.size());

        std::queue<std::pair<std::string, int>> q;
        std::unordered_set<std::string> visited;
        visited.reserve(all.size());

        for (auto const &r : roots) {
            q.push({r, 0});
            visited.insert(r);
        }

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            lvl[node] = d;
            for (auto const &c : children[node]) {
                if (!visited.insert(c).second)
                    continue;
                q.push({c, d + 1});
            }
        }

        return lvl;
    };

    auto rank = buildRankFromParent(handleOwner);

    std::unordered_map<std::string, std::string> handlesToInstert;
    std::unordered_map<std::string, int> rankToInstert;
    for (const auto &[handle, owner] : handleOwner) {
        if (owner.ends_with("Pool")) {
            auto name = handle.substr(2) + "s";
            handlesToInstert[name] = owner;
            rankToInstert[name] = rank.at(handle) + 1;
        }
    }
    handleOwner.insert_range(std::move(handlesToInstert));
    rank.insert_range(rankToInstert);

    FunctionInfo::handleOwner = handleOwner;

    const std::unordered_map<std::string, Depends> &typeDepends =
        parseObjectDepents(registry, "type");

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");

    const auto &objectTypes = parseObjectType(registry);

    for (const auto &[handle, owner] : handleOwner) {
        if (objectsDisabled.contains(handle))
            continue;
        ObjectInfo objectInfo;
        if (handle.starts_with("Vk")) {
            objectInfo.name = handle.substr(2);
        } else {
            objectInfo.name = handle;
        }
        if (!owner.ends_with("Pool") || !handle.ends_with("s")) {
            objectInfo.objectType = objectTypes.at(handle);
        }
        if (typeDepends.contains(handle)) {
            objectInfo.depends = typeDepends.at(handle);
        }
        if (functions.contains(handle)) {
            objectInfo.functions = functions.at(handle);
        }
        if (handle == "VkInstance") {
            objectInfo.staticFunctions = functions.at("");
        }
        if (destroyFunctions.contains(handle)) {
            objectInfo.destroyFunction = destroyFunctions.at(handle);
        }
        if (rank.contains(handle)) {
            objectInfo.rank = rank.at(handle);
        }
        objectInfo.owner = owner;
        if (handle == "VkInstance") {
            objectInfo.owner = "VkInstance";
        }
        objectInfos.insert(objectInfo);
    }
    return objectInfos;
}

static const std::unordered_set<std::string> parseVendorTags(XMLElement &registry) {
    static std::unordered_set<std::string> vendorTags;

    XMLElement &tags = FirstChildElement(registry, "tags");
    ForEach(tags, "tag", [&](XMLElement &tag) {
        assert(HasAttribute(tag, "name"));
        vendorTags.insert(Attribute(tag, "name"));
    });
    return vendorTags;
}

static std::unordered_set<std::string> vendorTags;

static std::string screamingSnakeCaseToPascalCase(const std::string &name) {
    std::string out;
    out.reserve(name.size());

    static const std::unordered_set<std::string> ignorList = {"AV1"};

    for (auto token_range : name | std::views::split('_')) {
        std::string token(token_range.begin(), token_range.end());
        if (token.empty())
            continue;

        if (vendorTags.contains(token)) {
            out += token;
            continue;
        }
        if (ignorList.contains(token)) {
            out += token;
            continue;
        }

        std::ranges::transform(token, token.begin(),
                               [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

        if (!token.empty()) {
            token[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(token[0])));
        }

        out += token;
    }

    return out;
}

const std::set<ConstantInfo> &parseConstantInfos(XMLElement &registry) {
    static std::set<ConstantInfo> constants;
    if (!constants.empty())
        return constants;

    vendorTags = parseVendorTags(registry);

    const auto &depnedsEnum = parseObjectDepents(registry, "enum");

    XMLElement &constantEnums = FirstChildElement(registry, "enums");
    assert(HasAttribute(constantEnums, "type"));
    assert(Attribute(constantEnums, "type") == "constants");

    ForEach(constantEnums, "enum", [&](XMLElement &enumElem) {
        assert(HasAttribute(enumElem, "type"));
        assert(HasAttribute(enumElem, "value"));
        assert(HasAttribute(enumElem, "name"));

        ConstantInfo info;
        info.name = Attribute(enumElem, "name");
        if (depnedsEnum.contains(info.name)) {
            info.depends = depnedsEnum.at(info.name);
        }
        info.name = screamingSnakeCaseToPascalCase(info.name).substr(2);
        info.value = Attribute(enumElem, "value");
        info.type = Attribute(enumElem, "type");
        constants.insert(std::move(info));
    });
    return constants;
}

// According to
// https://registry.khronos.org/vulkan/specs/latest/styleguide.html#extensions-assigning-token-values
static int64_t enumElementNumber(int64_t extensionNumber, int64_t offset, bool dirNegative) {
    static const constinit int64_t baseValue = 1000000000;
    static const constinit int64_t rangeSize = 1000;
    if (!dirNegative) {
        return baseValue + (extensionNumber - 1) * rangeSize + offset;
    } else {
        return -(baseValue + (extensionNumber - 1) * rangeSize + offset);
    }
}
static uint64_t enumElementUNumber(uint64_t extensionNumber, uint64_t offset, bool dirNegative) {
    static const constinit uint64_t baseValue = 1000000000;
    static const constinit uint64_t rangeSize = 1000;
    if (!dirNegative) {
        return baseValue + (extensionNumber - 1) * rangeSize + offset;
    } else {
        return -(baseValue + (extensionNumber - 1) * rangeSize + offset);
    }
}

static std::string enumElementValue(int64_t val, EnumInfo::Bitwidth bitwidth, EnumInfo::Type type) {
    const int hexDigits = (bitwidth == EnumInfo::Bitwidth::BW32) ? 8 : 16;

    std::stringstream s;
    if (val < 0) {
        s << "-";
    }
    if (type == EnumInfo::Type::Enum) {
        assert(bitwidth == EnumInfo::Bitwidth::BW32);
        s << std::right << std::dec << std::setw(10) << std::setfill(' ') << std::llabs(val);
        return s.str();
    }

    s << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0')
      << std::llabs(val);
    return s.str();
}

static std::string enumElementUValue(uint64_t val, EnumInfo::Bitwidth bitwidth,
                                     EnumInfo::Type type) {
    const int hexDigits = (bitwidth == EnumInfo::Bitwidth::BW32) ? 8 : 16;

    std::stringstream s;
    if (type == EnumInfo::Type::Enum) {
        assert(bitwidth == EnumInfo::Bitwidth::BW32);
        s << std::right << std::dec << std::setw(10) << std::setfill(' ');
        return s.str();
    }

    s << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0') << val;
    return s.str();
}

const std::set<EnumInfo> &parseEnumInfos(XMLElement &registry) {
    static std::set<EnumInfo> enumInfos;
    if (!enumInfos.empty())
        return enumInfos;

    vendorTags = parseVendorTags(registry);
    std::unordered_map<std::string, EnumInfo> enumInfosMap;

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");

    auto handleEnum = [&](XMLElement &element, const std::string &enumName,
                          int64_t extensionNumber = 0) {
        assert(HasAttribute(element, "name"));
        if (HasAttribute(element, "alias"))
            return;
        auto itEnumInfo = enumInfosMap.end();
        auto enumInfoMapKey = enumName;
        if (enumInfoMapKey == "") {
            if (!HasAttribute(element, "extends")) // some kind of version makro or sth
                return;
            enumInfoMapKey = Attribute(element, "extends");
        }
        EnumInfo &enumInfo = enumInfosMap.at(enumInfoMapKey);

        EnumElementInfo elem;
        elem.originalName = Attribute(element, "name");
        elem.name = screamingSnakeCaseToPascalCase(elem.originalName.substr(2));
        std::string enumNoFlagsName = enumInfo.name;
        std::string Flags = "Flags";
        if (auto it = enumNoFlagsName.find(Flags); it != std::string::npos) {
            enumNoFlagsName.erase(it, Flags.size());
        }
        if (elem.name.starts_with(enumNoFlagsName)) {
            elem.name = elem.name.substr(enumNoFlagsName.size());
        }
        if (enumInfo.vendor != "" && elem.name.ends_with(enumInfo.vendor)) {
            elem.name = elem.name.substr(0, elem.name.size() - enumInfo.vendor.size());
        }
        if (enumInfo.type == EnumInfo::Type::Bitmask && elem.name.ends_with("Bit")) {
            elem.name = elem.name.substr(0, elem.name.size() - 3);
        }
        elem.name.insert(0, "e");
        if (HasAttribute(element, "value")) {
            std::string value = Attribute(element, "value");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value = enumElementValue(std::stoll(value, nullptr, 0), enumInfo.bitwidth,
                                              enumInfo.type);
            } else {
                elem.value = enumElementUValue(std::stoull(value, nullptr, 0), enumInfo.bitwidth,
                                               enumInfo.type);
            }
        } else if (HasAttribute(element, "bitpos")) {
            std::string bitpos = Attribute(element, "bitpos");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value =
                    enumElementValue(1LL << std::stoi(bitpos), enumInfo.bitwidth, enumInfo.type);
            } else {
                elem.value =
                    enumElementUValue(1ULL << std::stoi(bitpos), enumInfo.bitwidth, enumInfo.type);
            }
        } else {
            assert(HasAttribute(element, "offset"));
            int64_t offset = std::stoll(Attribute(element, "offset"));
            if (HasAttribute(element, "extnumber")) {
                extensionNumber = std::stoi(Attribute(element, "extnumber"));
            }
            bool dirNegative = HasAttribute(element, "dir");
            if (dirNegative)
                assert(HasAttributeValue(element, "dir", "-"));
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value =
                    enumElementValue(enumElementNumber(extensionNumber, offset, dirNegative),
                                     enumInfo.bitwidth, enumInfo.type);
            } else {
                elem.value = enumElementUValue(
                    enumElementUNumber(static_cast<uint64_t>(extensionNumber),
                                       static_cast<uint64_t>(offset), dirNegative),
                    enumInfo.bitwidth, enumInfo.type);
            }
        }
        if (HasAttribute(element, "comment")) {
            elem.comment = Attribute(element, "comment");
        }
        if (itEnumInfo != enumInfosMap.end()) {
            itEnumInfo->second.elements.insert(std::move(elem));
        } else {
            enumInfo.elements.insert(std::move(elem));
        }
    };

    ForEach(registry, "enums", [&](XMLElement &enums) {
        EnumInfo enumInfo;
        assert(HasAttribute(enums, "name"));
        enumInfo.originalName = Attribute(enums, "name");
        if (objectsDisabled.contains(enumInfo.originalName))
            return;
        enumInfo.name = enumInfo.originalName.substr(2);
        assert(HasAttribute(enums, "type"));
        std::string type = Attribute(enums, "type");
        if (type == "constants")
            return;
        if (type == "enum") {
            enumInfo.type = EnumInfo::Type::Enum;
        } else {
            assert(type == "bitmask");
            enumInfo.type = EnumInfo::Type::Bitmask;
            static const std::string FlagBits = "FlagBits";
            auto it = enumInfo.name.find(FlagBits);
            assert(it != std::string::npos);
            enumInfo.name.erase(it, FlagBits.size());
            enumInfo.name.insert(it, "Flags");
        }
        if (HasAttribute(enums, "bitwidth")) {
            assert(Attribute(enums, "bitwidth") == "64");
            enumInfo.bitwidth = EnumInfo::Bitwidth::BW64;
        } else {
            enumInfo.bitwidth = EnumInfo::Bitwidth::BW32;
        }
        for (const auto &vendorTag : vendorTags) {
            if (enumInfo.name.ends_with(vendorTag)) {
                enumInfo.vendor = vendorTag;
                enumInfo.name = enumInfo.name.substr(0, enumInfo.name.size() - vendorTag.size());
            }
        }
        std::string originalName = enumInfo.originalName;
        enumInfosMap[enumInfo.originalName] = std::move(enumInfo);
        ForEach(enums, "enum", std::bind_back(handleEnum, originalName));
    });

    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;
        if (!HasAttribute(feature, "name"))
            return;
        std::string featureName = Attribute(feature, "name");
        ForEach(feature, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElement) { handleEnum(enumElement, ""); });
        });
    });

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        int64_t extensionNumber = std::stoll(Attribute(extension, "number"));
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum",
                    [&](XMLElement &enumElement) { handleEnum(enumElement, "", extensionNumber); });
        });
    });

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "bitmask"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        if (HasAttribute(type, "bitvalues"))
            return;
        // if (HasAttribute(type, "requires"))
        // return;
        std::string typeType = FirstChildElement(type, "type").GetText();
        std::string typeName = FirstChildElement(type, "name").GetText();
        static std::string Flags = "Flags";
        static std::string FlagBits = "FlagBits";
        std::string searchString = typeName;
        if (auto it = searchString.find(Flags); it != std::string::npos) {
            searchString.erase(it, Flags.length());
            searchString.insert(it, FlagBits);
        }
        if (enumInfosMap.contains(searchString)) {
            return;
        }
        EnumInfo info;
        if (typeType == "VkFlags") {
            info.bitwidth = EnumInfo::Bitwidth::BW32;
        } else {
            assert(typeType == "VkFlags64");
            info.bitwidth = EnumInfo::Bitwidth::BW64;
        }
        info.type = EnumInfo::Type::Bitmask;
        info.originalName = typeName;
        info.name = info.originalName.substr(2);
        enumInfosMap[info.originalName] = std::move(info);
    });

    for (const auto &[_, enumInfo] : enumInfosMap) {
        enumInfos.insert(enumInfo);
    }
    return enumInfos;
}

const std::set<EnumInfo> &parseEnumInfosDepends(XMLElement &registry) {
    static std::set<EnumInfo> enumInfos;
    if (!enumInfos.empty())
        return enumInfos;
    const auto &typeDepends = parseObjectDepents(registry, "type");
    const auto &enumDepends = parseObjectDepents(registry, "enum");

    auto parsed = parseEnumInfos(registry);

    std::set<EnumInfo> tmp;
    std::ranges::transform(parsed, std::inserter(tmp, tmp.end()), [&](EnumInfo const &info) {
        EnumInfo copy = info;

        if (auto it = typeDepends.find(copy.originalName); it != typeDepends.end()) {
            copy.depends = it->second;
        }

        std::set<EnumElementInfo> newElems;
        std::ranges::transform(
            copy.elements, std::inserter(newElems, newElems.end()), [&](EnumElementInfo const &el) {
                EnumElementInfo elcopy = el;
                if (auto it2 = enumDepends.find(elcopy.originalName); it2 != enumDepends.end()) {
                    elcopy.depends = it2->second;
                }
                return elcopy;
            });
        copy.elements = std::move(newElems);
        return copy;
    });

    enumInfos = std::move(tmp);
    return enumInfos;
}

const std::unordered_map<std::string, std::string> &parseEnumAlias(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> enumAlias;
    if (!enumAlias.empty())
        return enumAlias;

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "bitmask"))
            return;
        if (!HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        enumAlias[Attribute(type, "name")] = Attribute(type, "alias");
    });
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "enum"))
            return;
        if (!HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        enumAlias[Attribute(type, "name")] = Attribute(type, "alias");
    });

    return enumAlias;
}

const std::set<StructInfo> &parseStructInfos(XMLElement &registry) {
    static std::set<StructInfo> structInfos;
    if (!structInfos.empty())
        return structInfos;

    std::unordered_map<std::string, StructInfo> infos;
    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    const auto &handles = parseHandles(registry);

    StructInfo::enumAlias = parseEnumAlias(registry);

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (HasAttributeValue(type, "category", "struct") && !HasAttribute(type, "alias")) {
            assert(HasAttribute(type, "name"));
            StructInfo s;
            s.isUnion = false;
            s.originalName = Attribute(type, "name");
            s.name = s.originalName.substr(2);
            std::vector<StructInfo::Member> members;
            ForEach(type, "member", [&](XMLElement &member) {
                if (HasAttribute(member, "api") &&
                    !splitCSL(Attribute(member, "api")).contains("vulkan"))
                    return;
                StructInfo::Member m;
                m = parseTypeAndName(member);
                prerequisits[s.originalName].insert(m.baseType);
                if (!HasAttribute(member, "len") && handles.contains(m.baseType)) {
                    if (m.postType == "*") {
                        assert(m.leading == "const");
                        m.postType = "";
                        m.leading = "";

                        assert(m.name[0] == 'p');
                        m.name = m.name.substr(1);
                        m.name[0] = static_cast<char>(std::tolower(m.name[0]));
                    } else {
                        assert(m.leading == "");
                        assert(m.postType == "");
                        assert(m.trailing == "");
                    }
                    m.baseType = "AssignableHandle<" + m.baseType.substr(2) + ">";
                }
                members.emplace_back(std::move(m));
            });
            s.members = std::move(members);
            infos[s.originalName] = std::move(s);
        }
    });
    ForEach(types, "type", [&](XMLElement &type) {
        if (HasAttributeValue(type, "category", "union") && !HasAttribute(type, "alias")) {
            assert(HasAttribute(type, "name"));
            StructInfo s;
            s.isUnion = true;
            s.originalName = Attribute(type, "name");
            s.name = s.originalName.substr(2);
            std::vector<StructInfo::Member> members;
            ForEach(type, "member", [&](XMLElement &member) {
                if (HasAttribute(member, "api") &&
                    !splitCSL(Attribute(member, "api")).contains("vulkan"))
                    return;
                StructInfo::Member m;
                m = parseTypeAndName(member);
                prerequisits[s.originalName].insert(m.baseType);
                members.emplace_back(std::move(m));
            });
            s.members = std::move(members);
            infos[s.originalName] = std::move(s);
        }
    });

    std::ranges::for_each(prerequisits, [&](auto &pair) { // remove reflecifity
        std::erase_if(pair.second, [&](const std::string &s) { return s == pair.first; });
    });

    std::unordered_set<std::string> toRemove; // Roots of the dependency tree
    std::unordered_map<std::string, int> rank;
    int currentRank = 0;

    std::unordered_set<std::string> roots;
    for (const auto &[_, pre] : prerequisits) {
        toRemove.insert_range(pre);
    }
    for (const auto &[name, _] : prerequisits) {
        toRemove.erase(name);
    }

    while (!toRemove.empty()) {

        for (const auto &key : toRemove) {
            rank[key] = currentRank;
        }
        currentRank += 1;

        std::ranges::for_each(prerequisits, [&](auto &pair) {
            std::erase_if(pair.second, [&](const std::string &s) { return toRemove.contains(s); });
        });
        toRemove.clear();

        for (const auto &[name, pre] : prerequisits) {
            if (pre.empty())
                toRemove.insert(name);
        }
        std::erase_if(prerequisits, [&](const auto &pair) { return pair.second.empty(); });
    }
    assert(prerequisits.empty());

    const auto &typeDepends = parseObjectDepents(registry, "type");
    const auto &typeDisabled = parseObjectsDisabled(registry, "type");

    for (const auto &[_, info] : infos) {
        assert(rank.contains(info.originalName));
        if (typeDisabled.contains(info.originalName))
            continue;
        StructInfo si = info;
        si.rank = rank.at(info.originalName);
        if (auto it = typeDepends.find(info.originalName); it != typeDepends.end()) {
            si.depends = it->second;
        }
        structInfos.emplace(std::move(si));
    }

    return structInfos;
}
