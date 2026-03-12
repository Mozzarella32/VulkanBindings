#include "ParseXml.hpp"
#include "ConstantInfo.hpp"
#include "Depens.hpp"
#include "EnumInfo.hpp"
#include "FunctionInfo.hpp"
#include "ObjectInfo.hpp"
#include "TypeInfo.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <queue>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace tinyxml2;

static XMLElement &FirstChildElement(XMLElement &element, const std::string &elementValue) {
    XMLElement *elem = element.FirstChildElement(elementValue.c_str());
    if (!elem) {
        std::cerr << "failed to find: " << elementValue << "\n";
        exit(EXIT_FAILURE);
    }
    return *elem;
}

static void ForEachBreak(XMLElement &elem, const std::string &elementValue,
                         std::function<bool(XMLElement &)> fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        if (fun(*elems))
            break;
    }
}

static void ForEach(XMLElement &elem, const std::string &elementValue,
                    std::function<void(XMLElement &)> fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        fun(*elems);
    }
}

static void Print [[maybe_unused]] (XMLElement &elem) {
    XMLPrinter p;
    elem.Accept(&p);
    std::cout << p.CStr() << "\n";
}

static bool HasAttributeValue(XMLElement &elem, const std::string &name, const std::string &value) {
    const char *attrib = elem.Attribute(name.c_str());
    if (attrib == nullptr)
        return false;
    return std::string_view(attrib) == value;
}
static bool HasAttribute(XMLElement &elem, const std::string &name) {
    const char *attrib = elem.Attribute(name.c_str());
    return attrib != nullptr;
}

static bool HasText(XMLElement &elem, const std::string &value) {
    const char *text = elem.GetText();
    if (text == nullptr)
        return false;
    return std::string_view(text) == value;
}

static std::string trim_copy(std::string s) {
    auto not_space = [](unsigned char c) { return !std::isspace(c); };
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), not_space));
    s.erase(std::find_if(s.rbegin(), s.rend(), not_space).base(), s.end());
    return s;
}

static const std::unordered_map<std::string, std::string> &parseHandles(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> handles;
    if (!handles.empty())
        return handles;
    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (HasAttributeValue(type, "category", "handle") && !HasAttribute(type, "alias")) {
            std::string name = FirstChildElement(type, "name").GetText();
            const char *pParent = type.Attribute("parent");
            std::string parent;
            if (pParent != nullptr) {
                parent = pParent;
            }
            handles[name] = parent;
        }
    });
    handles.erase(handles.find("VkDisplayModeKHR"));
    return handles;
}

static const std::unordered_map<std::string, std::string> &parseObjectType(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> objectTypes;
    if (!objectTypes.empty())
        return objectTypes;
    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (HasAttributeValue(type, "category", "handle") && !HasAttribute(type, "alias")) {
            std::string name = FirstChildElement(type, "name").GetText();
            const char *pObjectType = type.Attribute("objtypeenum");
            assert(pObjectType != nullptr);
            std::string objectType = pObjectType;
            objectTypes[name] = objectType;
        }
    });
    objectTypes.erase(objectTypes.find("VkDisplayModeKHR"));
    return objectTypes;
}

static Function::Argument parseParam(XMLElement &param,
                                     const std::vector<Function::Argument> &prevArgs) {
    Function::Argument arg;

    std::string leading;
    std::string type_inner;
    std::string between;
    std::string name_text;
    std::string after;

    if (HasAttribute(param, "len")) {
        const std::string len = param.Attribute("len");
        if (len != "null-terminated" && len != "1" && !len.contains("->") &&
            !len.starts_with("latexmath")) {
            auto it = std::ranges::find_if(
                prevArgs, [&len](const Function::Argument &arg) { return arg.name == len; });
            assert(it != prevArgs.end());
            arg.arrayWithLengthOf = std::distance(prevArgs.begin(), it);
        }
    }
    if (HasAttribute(param, "optional")) {
        const std::string optional = param.Attribute("optional");
        if (optional.contains("true")) {
            arg.optional = true;
        }
    }

    int state = 0; // 0 = before <type>, 1 = after <type> before <name>, 2 = after <name>
    for (XMLNode *node = param.FirstChild(); node; node = node->NextSibling()) {
        if (XMLText *txt = node->ToText()) {
            const char *v = txt->Value();
            std::string text = v ? v : "";
            if (state == 0) {
                leading += text;
            } else if (state == 1) {
                between += text;
            } else {
                after += text;
            }
        } else if (XMLElement *el = node->ToElement()) {
            std::string_view ename = el->Name();
            if (ename == "type") {
                // switch into "after type" mode for subsequent text nodes
                state = 1;
                if (const char *t = el->GetText())
                    type_inner += t;
            } else if (ename == "name") {
                // capture the name and switch to "after name"
                state = 2;
                if (const char *n = el->GetText())
                    name_text += n;
            } else {
                // unexpected nested elements are tolerated; capture their inner text as appropriate
                if (const char *t = el->GetText()) {
                    if (state == 0)
                        leading += t;
                    else if (state == 1)
                        between += t;
                    else
                        after += t;
                }
            }
        }
    }

    arg.leading = trim_copy(leading);
    arg.baseType = trim_copy(type_inner);
    arg.postType = trim_copy(between);
    arg.name = trim_copy(name_text);
    arg.trailing = trim_copy(after);

    return arg;
}

static const std::unordered_set<std::string> &parseNotInternalFeatureNames(XMLElement &registry) {
    static std::unordered_set<std::string> notInternelFeatureNames;
    if (!notInternelFeatureNames.empty())
        return notInternelFeatureNames;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal")) {
            return;
        }
        std::string notInternelFeatureName = feature.Attribute("name");
        notInternelFeatureNames.insert(notInternelFeatureName);
    });
    return notInternelFeatureNames;
}

// string_view to prevent dangling refrence, when passing a string literal
// static const std::unordered_map<std::string, Depends> &
// parseObjectFeatureMacros(XMLElement &registry, std::string_view objectSV) {
//     static std::unordered_map<std::string, std::unordered_map<std::string, Depends>>
//         allObjectDepends;
//     std::string object{objectSV};
//     std::unordered_map<std::string, Depends> &objectDepends = allObjectDepends[object];
//     if (!objectDepends.empty())
//         return objectDepends;
//     ForEach(registry, "feature", [&](XMLElement &feature) {
//         if (!HasAttribute(feature, "name"))
//             return;
//         if (HasAttributeValue(feature, "apitype", "internal"))
//             return;
//         std::string notInternelFeatureName = feature.Attribute("name");
//         ForEach(feature, "require", [&](XMLElement &require) {
//             ForEach(require, object, [&](XMLElement &type) {
//                 if (!HasAttribute(type, "name"))
//                     return;
//                 std::string typeName = type.Attribute("name");
//                 assert(objectDepends.find(typeName) == objectDepends.end());
//                 objectDepends[typeName].feature = notInternelFeatureName;
//             });
//         });
//     });
//     return objectDepends;
// }

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
        platformMakros[platform.Attribute("name")] = platform.Attribute("protect");
    });
    return platformMakros;
}

static std::string composeGuard(const std::string &extension, const std::string &depends,
                                XMLElement &registry) {
    const std::unordered_set<std::string> &notInternal = parseNotInternalFeatureNames(registry);

    std::unordered_set<std::string> allFeatures;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        const char *n = feature.Attribute("name");
        if (n)
            allFeatures.insert(std::string(n));
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
        std::string featureName = feature.Attribute("name");
        if (featureName == "")
            return;
        ForEach(feature, "require", [&](XMLElement &require) {
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                std::string typeName = type.Attribute("name");
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
        std::string extension_name = extension.Attribute("name");
        ForEach(extension, "require", [&](XMLElement &require) {
            std::string depends;
            if (HasAttribute(require, "depends")) {
                depends = require.Attribute("depends");
            }
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                std::string typeName = type.Attribute("name");
                auto &objDepends = objectDepends[typeName];
                if (HasAttribute(extension, "platform")) {
                    std::string platform = extension.Attribute("platform");
                    if (objDepends.platform != "" &&
                        objDepends.platform != platformMakros.at(platform)) {
                        assert(false);
                    }
                    objDepends.platform = platformMakros.at(platform);
                }
                std::string extGuard = composeGuard(extension_name, depends, registry);
                if (extGuard.empty())
                    return;
                if (objDepends.guard != "") {
                    objDepends.guard = objDepends.guard + " || " + extGuard;
                } else {
                    objDepends.guard = extGuard;
                }
            });
        });
    });

    return objectDepends;
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

    XMLElement &commands = FirstChildElement(registry, "commands");
    ForEach(commands, "command", [&](XMLElement &command) {
        if (HasAttribute(command, "alias"))
            return;
        std::vector<std::string> success;
        if (HasAttribute(command, "successcodes")) {
            std::string successcodes = command.Attribute("successcodes");
            success =
                successcodes | std::views::split(',') | std::ranges::to<std::vector<std::string>>();
        }
        std::vector<std::string> error;
        if (HasAttribute(command, "errorcodes")) {
            std::string errorcodes = command.Attribute("errorcodes");
            error =
                errorcodes | std::views::split(',') | std::ranges::to<std::vector<std::string>>();
        }

        XMLElement &proto = FirstChildElement(command, "proto");
        std::string name = FirstChildElement(proto, "name").GetText();
        std::string returnType = FirstChildElement(proto, "type").GetText();
        std::vector<Function::Argument> args;
        ForEach(command, "param", [&](XMLElement &param) {
            if (HasAttributeValue(param, "api", "vulkansc"))
                return;
            Function::Argument a = parseParam(param, args);
            a.name = FirstChildElement(param, "name").GetText();
            args.push_back(std::move(a));
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
        std::string structureType;
        ForEachBreak(type, "member", [&](XMLElement &member) {
            bool hasStructureType = false;
            ForEachBreak(member, "type", [&](XMLElement &memberType) {
                if (HasText(memberType, "VkStructureType")) {
                    hasStructureType = true;
                    if (!HasAttribute(member, "values"))
                        return false;
                    structureType = member.Attribute("values");
                }
                return false;
            });
            return hasStructureType;
        });
        if (structureType != "") {
            std::string name = type.Attribute("name");

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
        typeInfos.emplace(CreateTypeInfo(name));
    }
    return typeInfos;
}

const std::set<ObjectInfo> &parseObjectInfos(XMLElement &registry) {
    static std::set<ObjectInfo> objectInfos;
    if (!objectInfos.empty())
        return objectInfos;

    std::unordered_map<std::string, std::string> handleOwner = parseHandles(registry);

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

    auto [destroyFunctions, functions] = parseGroupedFunctions(registry);
    FunctionInfo::destroyFunctions = destroyFunctions;

    const auto &objectTypes = parseObjectType(registry);

    for (const auto &[handle, owner] : handleOwner) {
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
        std::string name = tag.Attribute("name");
        vendorTags.insert(std::move(name));
    });
    return vendorTags;
}

static std::unordered_set<std::string> vendorTags;

static std::string screamingSnakeCaseToPascalCase(const std::string &name) {
    std::string out;
    out.reserve(name.size());

    for (auto token_range : name | std::views::split('_')) {
        std::string token(token_range.begin(), token_range.end());
        if (token.empty())
            continue;

        if (!vendorTags.empty() && vendorTags.find(token) != vendorTags.end()) {
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
    assert(std::string(constantEnums.Attribute("type")) == "constants");

    ForEach(constantEnums, "enum", [&](XMLElement &enumElem) {
        assert(HasAttribute(enumElem, "type"));
        assert(HasAttribute(enumElem, "value"));
        assert(HasAttribute(enumElem, "name"));

        ConstantInfo info;
        info.name = enumElem.Attribute("name");
        if (depnedsEnum.contains(info.name)) {
            info.depends = depnedsEnum.at(info.name);
        }
        info.name = screamingSnakeCaseToPascalCase(info.name).substr(2);
        info.value = enumElem.Attribute("value");
        info.type = enumElem.Attribute("type");
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

static std::string enumElementValue(int64_t val, EnumInfo::Bitwidth bitwidth) {
    const int hexDigits = bitwidth == EnumInfo::Bitwidth::BW32 ? 8 : 16;
    std::stringstream s;
    if (val < 0) {
        s << "-";
    }
    s << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0')
      << std::abs(val);
    return s.str();
}

static std::string enumElementUValue(uint64_t val, EnumInfo::Bitwidth bitwidth) {
    const int hexDigits = bitwidth == EnumInfo::Bitwidth::BW32 ? 8 : 16;
    std::stringstream s;
    s << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0') << val;
    return s.str();
}

const std::set<EnumInfo> &parseEnumInfos(XMLElement &registry) {
    static std::set<EnumInfo> enumInfos;
    if (!enumInfos.empty())
        return enumInfos;

    vendorTags = parseVendorTags(registry);
    std::unordered_map<std::string, EnumInfo> enumInfosMap;

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
            std::string extends = element.Attribute("extends");
            enumInfoMapKey = extends;
        }
        EnumInfo &enumInfo = enumInfosMap.at(enumInfoMapKey);

        EnumElementInfo elem;
        elem.originalName = element.Attribute("name");
        elem.name = screamingSnakeCaseToPascalCase(elem.originalName.substr(2));
        if (elem.name.starts_with(enumInfo.name)) {
            elem.name = elem.name.substr(enumInfo.name.size());
        }
        if (enumInfo.extensions != "" && elem.name.ends_with(enumInfo.extensions)) {
            elem.name = elem.name.substr(0, elem.name.size() - enumInfo.extensions.size());
        }
        if (enumInfo.type == EnumInfo::Type::Bitmask && elem.name.ends_with("Bit")) {
            elem.name = elem.name.substr(0, elem.name.size() - 3);
        }
        elem.name.insert(0, "e");
        if (HasAttribute(element, "value")) {
            std::string value = element.Attribute("value");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value = enumElementValue(std::stoll(value, nullptr, 0), enumInfo.bitwidth);
            } else {
                elem.value = enumElementUValue(std::stoull(value, nullptr, 0), enumInfo.bitwidth);
            }
        } else if (HasAttribute(element, "bitpos")) {
            std::string bitpos = element.Attribute("bitpos");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value = enumElementValue(1LL << std::stoi(bitpos), enumInfo.bitwidth);
            } else {
                elem.value = enumElementUValue(1ULL << std::stoi(bitpos), enumInfo.bitwidth);
            }
        } else {
            assert(HasAttribute(element, "offset"));
            int64_t offset = std::stoll(std::string(element.Attribute("offset")));
            if (HasAttribute(element, "extnumber")) {
                extensionNumber = std::stoi(std::string(element.Attribute("extnumber")));
            }
            bool dirNegative = HasAttribute(element, "dir");
            if (dirNegative)
                assert(HasAttributeValue(element, "dir", "-"));
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value = enumElementValue(
                    enumElementNumber(extensionNumber, offset, dirNegative), enumInfo.bitwidth);
            } else {
                elem.value = enumElementUValue(
                    enumElementUNumber(static_cast<uint64_t>(extensionNumber),
                                       static_cast<uint64_t>(offset), dirNegative),
                    enumInfo.bitwidth);
            }
        }
        if (HasAttribute(element, "comment")) {
            elem.comment = element.Attribute("comment");
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
        enumInfo.originalName = enums.Attribute("name");
        enumInfo.name = enumInfo.originalName.substr(2);
        if (enumInfo.originalName == "VkAccelerationStructureBuildTypeKHR") {
            [[maybe_unused]] int i = 0;
        }
        assert(HasAttribute(enums, "type"));
        std::string type = enums.Attribute("type");
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
        }
        if (HasAttribute(enums, "bitwidth")) {
            assert(std::string(enums.Attribute("bitwidth")) == "64");
            enumInfo.bitwidth = EnumInfo::Bitwidth::BW64;
        } else {
            enumInfo.bitwidth = EnumInfo::Bitwidth::BW32;
        }
        for (const auto &vendorTag : vendorTags) {
            if (enumInfo.name.ends_with(vendorTag)) {
                enumInfo.extensions = vendorTag;
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
        std::string featureName = feature.Attribute("name");
        if (featureName == "")
            return;
        ForEach(feature, "require", [&](XMLElement &require) {
            ForEach(require, "enum", [&](XMLElement &enumElement) {
                handleEnum(enumElement, "");
            });
        });
    });

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        assert(HasAttribute(extension, "number"));
        int64_t extensionNumber = std::stoll(std::string(extension.Attribute("number")));
        std::string extension_name = extension.Attribute("name");
        ForEach(extension, "require", [&](XMLElement &require) {
            ForEach(require, "enum", [&](XMLElement &enumElement) {
                handleEnum(enumElement,  "", extensionNumber);
            });
        });
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
