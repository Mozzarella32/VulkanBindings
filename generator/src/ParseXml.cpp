#include "ParseXml.hpp"
#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "EnumInfo.hpp"
#include "FunctionInfo.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <cctype>
#include <dlfcn.h>
#include <functional>
#include <ranges>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

#include "XmlUtils.hpp"

using namespace tinyxml2;

XMLElement *vkXml;
XMLElement *videoXml;

const std::unordered_map<std::string, std::string> &parseHandles() {
    static std::unordered_map<std::string, std::string> handles;
    if (!handles.empty())
        return handles;

    auto &registry = *vkXml;
    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "handle"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        std::string name = FirstChildElement(type, "name").GetText();
        if (HasAttribute(type, "parent")) {
            handles[name] = Attribute(type, "parent");
        } else {
            handles[name] = "";
        }
    });
    return handles;
}

const std::unordered_set<std::string> &parseDispatchableHandles() {
    static std::unordered_set<std::string> dispatchableHandles;
    if (!dispatchableHandles.empty())
        return dispatchableHandles;
    auto &registry = *vkXml;
    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "handle"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        if (FirstChildElement(type, "type").GetText() != std::string_view{"VK_DEFINE_HANDLE"})
            return;
        std::string name = FirstChildElement(type, "name").GetText();
        dispatchableHandles.insert(name);
    });
    return dispatchableHandles;
}

const std::unordered_map<std::string, std::string> &parseObjectType(XMLElement &registry) {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regObjectTypes;
    auto &objectTypes = regObjectTypes[&registry];
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

TypeAndName parseTypeAndName(XMLElement &param) {
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
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>>
        regNotInternelFeatureNames;
    auto &notInternelFeatureNames = regNotInternelFeatureNames[&registry];
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

static const std::unordered_map<std::string, std::string> &parsePlatformMacros() {
    static std::unordered_map<std::string, std::string> platformMakros;
    XMLElement &registry = *vkXml;
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

static std::string composeGuard(const std::string &extension, const std::string &depends,
                                XMLElement &registry) {
    const std::unordered_set<std::string> &notInternal = parseNotInternalFeatureNames(registry);

    std::unordered_set<std::string> allFeatures;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (!checkApi(feature))
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
const std::unordered_map<std::string, Depends> &parseObjectDepents(XMLElement &registry,
                                                                   std::string_view objectSV) {

    static std::unordered_map<
        XMLElement *, std::unordered_map<std::string, std::unordered_map<std::string, Depends>>>
        regAllObjectDepends;
    auto &allObjectDepends = regAllObjectDepends[&registry];
    std::string object{objectSV};
    std::unordered_map<std::string, Depends> &objectDepends = allObjectDepends[object];
    if (!objectDepends.empty())
        return objectDepends;

    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal"))
            return;
        if (!checkApi(feature))
            return;
        std::string featureName = Attribute(feature, "name");
        ForEach(feature, "require", [&](XMLElement &require) {
            if (!checkApi(require))
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

    const std::unordered_map<std::string, std::string> &platformMakros = parsePlatformMacros();

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) {
            if (!checkApi(require))
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
const std::unordered_set<std::string> &parseObjectsDisabled(XMLElement &registry,
                                                            std::string_view objectSV) {

    static std::unordered_map<XMLElement *,
                              std::unordered_map<std::string, std::unordered_set<std::string>>>
        regAllObjectsDisabled;
    auto &allObjectsDisabled = regAllObjectsDisabled[&registry];
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

const std::unordered_map<std::string, FunctionInfo> &parseDestroyFunctions(XMLElement &registry) {
    static std::unordered_map<std::string, FunctionInfo> destroyFunctions;
    if (!destroyFunctions.empty())
        return destroyFunctions;

    const auto &groupedFunctions = parseGroupedFunctions(registry);
    const auto &vendorTags = parseVendorTags();

    for (const auto &[_, funs] : groupedFunctions) {
        for (const auto &finfo : funs) {
            const auto &f = finfo.function;
            if (f.name.starts_with("vkDestroy")) {
                if (f.args.size() == 2) { // VkDevice
                    destroyFunctions[f.args[0].baseType] = finfo;
                } else {
                    assert(f.name.starts_with("vkDestroy") && f.args.size() == 3);
                    destroyFunctions[f.args[1].baseType] = finfo;
                }
                continue;
            }
            if (f.name.starts_with("vkRelease") && f.args.size() == 2) {
                std::string_view baseName = f.args[1].baseType;
                baseName.remove_prefix(2);
                for (const auto &vendorTag : vendorTags) {
                    if (auto it = baseName.find(vendorTag); it != std::string::npos) {
                        baseName.remove_suffix(vendorTag.size());
                        break;
                    }
                }
                if (f.name.contains(baseName)) {
                    destroyFunctions[f.args[1].baseType] = finfo;
                }
            }
            if (f.name.starts_with("vkFree")) {
                if (f.name == "vkFreeMemory") {
                    destroyFunctions[f.args[1].baseType] = finfo;
                } else {
                    auto name = f.args[3].baseType.substr(2) + "s";
                    destroyFunctions[name] = finfo;
                }
                continue;
            }
        }
    }

    return destroyFunctions;
}

std::unordered_map<std::string, std::set<FunctionInfo>>
parseGroupedFunctions(XMLElement &registry) {
    static std::unordered_map<std::string, std::set<FunctionInfo>> groupedFunctions;
    if (!groupedFunctions.empty())
        return groupedFunctions;
    const std::unordered_map<std::string, std::string> &handles = parseHandles();
    std::vector<Function> functions;

    const auto &enumElementMappings = getEnumElementMapping(registry);
    const std::unordered_set<std::string> objectsDisabled =
        parseObjectsDisabled(registry, "command");

    const auto &vendorTags = parseVendorTags();

    auto processing =
        std::views::split(',') | std::views::transform([](auto subr) {
            return std::string(std::ranges::begin(subr), std::ranges::end(subr));
        }) |
        std::views::transform(
            [&](const std::string &token) { // This is a very hacky way to resolve aliases of the
                                            // VkResult enum elements
                std::string token_mut = token;
                if (auto it = enumElementMappings.find(token); it != enumElementMappings.end()) {
                    return "Result::" + it->second;
                }
                for (const auto &tag : vendorTags) {
                    if (token_mut.ends_with(tag)) {
                        token_mut = token_mut.substr(0, token.size() - tag.size() - 1);
                    }
                }
                return "Result::" + enumElementMappings.at(token_mut);
            }) |
        std::ranges::to<std::vector<std::string>>();

    XMLElement &commands = FirstChildElement(registry, "commands");
    ForEach(commands, "command", [&](XMLElement &command) {
        if (HasAttribute(command, "alias"))
            return;
        if (!checkApi(command))
            return;
        XMLElement &proto = FirstChildElement(command, "proto");

        std::string name = FirstChildElement(proto, "name").GetText();
        if (objectsDisabled.contains(name))
            return;

        functions.emplace_back();
        Function &function = functions.back();
        function.name = name;
        if (HasAttribute(command, "successcodes")) {
            function.successcodes = Attribute(command, "successcodes") | processing;
        }
        if (HasAttribute(command, "errorcodes")) {
            function.errorcodes = Attribute(command, "errorcodes") | processing;
        }
        function.returnType = FirstChildElement(proto, "type").GetText();
        ForEach(command, "param", [&](XMLElement &param) {
            if (!checkApi(param))
                return;
            Function::Argument arg;
            arg = parseTypeAndName(param);
            if (HasAttribute(param, "len")) {
                const std::string len = Attribute(param, "len");
                if (len != "null-terminated" && len != "1" && !len.contains("->") &&
                    !len.starts_with("latexmath")) {
                    auto it =
                        std::ranges::find_if(function.args, [&len](const Function::Argument &arg) {
                            return arg.name == len;
                        });
                    assert(it != function.args.end());
                    arg.arrayWithLengthOf = std::distance(function.args.begin(), it);
                }
            }
            if (HasAttribute(param, "optional")) {
                arg.optional = splitCSL(Attribute(param, "optional")).contains("true");
            }
            arg.name = FirstChildElement(param, "name").GetText();
            function.args.push_back(std::move(arg));
        });
    });

    const std::unordered_map<std::string, Depends> &functionDepends =
        parseObjectDepents(registry, "command");

    for (const auto &f : functions) {
        std::string handle = f.args[0].baseType;
        FunctionInfo fInfo;
        fInfo.function = f;
        if (auto it = functionDepends.find(f.name); it != functionDepends.end()) {
            fInfo.depends = it->second;
        }
        if (handles.contains(handle)) {
            fInfo.handle = handle;
            fInfo.function.isConst = true;
            fInfo.function.className = handle.substr(2);
            groupedFunctions[f.args[0].baseType].insert(fInfo);
        } else {
            fInfo.function.isStatic = true;
            groupedFunctions[""].insert(fInfo);
        }
    }

    return groupedFunctions;
}

const std::unordered_map<std::string, std::string> &parseTypeStructureName(XMLElement &registry) {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regTypeStructureName;
    auto &typeStructureName = regTypeStructureName[&registry];
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

const std::unordered_set<std::string> parseVendorTags() {
    static std::unordered_set<std::string> vendorTags;

    XMLElement &registry = *vkXml;
    XMLElement &tags = FirstChildElement(registry, "tags");
    ForEach(tags, "tag", [&](XMLElement &tag) {
        assert(HasAttribute(tag, "name"));
        vendorTags.insert(Attribute(tag, "name"));
    });
    return vendorTags;
}

std::string screamingSnakeCaseToPascalCase(const std::string &name,
                                           const std::unordered_set<std::string> &vendorTags) {
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

const std::unordered_map<std::string, std::string> &parseAlias(XMLElement &registry) {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regEnumAlias;
    auto &alias = regEnumAlias[&registry];
    if (!alias.empty())
        return alias;

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        alias[Attribute(type, "name")] = Attribute(type, "alias");
    });
    return alias;
}

void parseFunctionPointers(XMLElement &registry);

const std::string &parseDefines(XMLElement &registry) {
    static std::unordered_map<XMLElement *, std::string> regRet;
    auto &ret = regRet[&registry];
    if (!ret.empty())
        return ret;
    std::stringstream s;

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "define"))
            return;
        if (!checkApi(type))
            return;
        if (type.FirstChildElement("name") == nullptr) {
            s << type.GetText() << "\n";
            return;
        }
        XMLElement &name = FirstChildElement(type, "name");
        s << "#define " << name.GetText();
        XMLNode *node = name.NextSibling();
        bool first = true;
        while (node) {
            if (XMLText *txt = node->ToText()) {
                const char *val = txt->Value();
                if (val && *val) {
                    if (first && val[0] != '(') {
                        first = false;
                        s << " ";
                    }
                    s << val;
                }
            } else if (XMLElement *el = node->ToElement()) {
                if (const char *t = el->GetText()) {
                    if (first && t[0] != '(') {
                        first = false;
                        s << " ";
                    }
                    s << t;
                }
            }
            node = node->NextSibling();
        }
        s << "\n";
    });
    ret = s.str();
    std::string replace = "VK_";
    for (auto pos = ret.find(replace); pos != std::string::npos; pos = ret.find(replace, pos)) {
        pos += replace.size();
        ret.insert(pos, "BINDINGS_");
    }
    replace = "VKSC_";
    for (auto pos = ret.find(replace); pos != std::string::npos; pos = ret.find(replace, pos)) {
        pos += replace.size();
        ret.insert(pos, "BINDINGS_");
    }
    return ret;
}
