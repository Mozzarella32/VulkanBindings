#include "ParseXml.hpp"
#include "Depens.hpp"
#include "FunctionInfo.hpp"
#include "ObjectInfo.hpp"
#include "TypeInfo.hpp"

#include <functional>
#include <queue>
#include <ranges>
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

static std::unordered_map<std::string, std::string> parseHandles(XMLElement &registry) {
    std::unordered_map<std::string, std::string> handles;
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

static std::unordered_map<std::string, std::string> parseObjectType(XMLElement &registry) {
    std::unordered_map<std::string, std::string> objectTypes;
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

static std::unordered_set<std::string> parseNotInternelFeatureNames(XMLElement &registry) {
    std::unordered_set<std::string> notInternelFeatureNames;
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

static std::unordered_map<std::string, Depends>
parseObjectFeatureMacros(XMLElement &registry, const std::string &object) {
    std::unordered_map<std::string, Depends> objectDepends;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, "apitype", "internal"))
            return;
        std::string notInternelFeatureName = feature.Attribute("name");
        ForEach(feature, "require", [&](XMLElement &require) {
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                std::string typeName = type.Attribute("name");
                assert(objectDepends.find(typeName) == objectDepends.end());
                objectDepends[typeName].feature = notInternelFeatureName;
            });
        });
    });
    return objectDepends;
}

static std::unordered_map<std::string, std::string> parsePlatformMakros(XMLElement &registry) {
    std::unordered_map<std::string, std::string> platformMakros;
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

static std::unordered_map<std::string, Depends> parseObjectDepents(XMLElement &registry,
                                                                   const std::string &object) {

    std::unordered_set<std::string> notInternelFeatureNames =
        parseNotInternelFeatureNames(registry);
    std::unordered_map<std::string, Depends> objectDepends =
        parseObjectFeatureMacros(registry, object);
    std::unordered_map<std::string, std::string> platformMakros = parsePlatformMakros(registry);

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        std::string extension_name = extension.Attribute("name");
        std::string extension_enum_name = "\"" + extension_name + "\"";
        XMLElement &first_require = FirstChildElement(extension, "require");
        std::string extension_name_macro = "";
        ForEachBreak(first_require, "enum", [&](XMLElement &enumEntry) {
            if (!HasAttributeValue(enumEntry, "value", extension_enum_name) ||
                !HasAttribute(enumEntry, "name"))
                return false;
            extension_name_macro = enumEntry.Attribute("name");
            return true;
        });

        ForEach(extension, "require", [&](XMLElement &require) {
            std::string feature;
            if (HasAttribute(require, "depends")) {
                feature = require.Attribute("depends");
                if (!notInternelFeatureNames.contains(feature)) {
                    feature = "";
                }
            }
            ForEach(require, object, [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                std::string typeName = type.Attribute("name");
                if (HasAttribute(extension, "platform")) {
                    std::string platform = extension.Attribute("platform");
                    if ((objectDepends.find(typeName) != end(objectDepends)) &&
                        objectDepends.find(typeName)->second.platform !=
                            platformMakros.at(platform)) {
                        assert(false);
                    }
                    objectDepends[typeName].platform = platformMakros.at(platform);
                }
                if (extension_name_macro != "") {
                    objectDepends[typeName].extensions.insert(extension_name_macro);
                }
                if (feature != "" && notInternelFeatureNames.contains(feature)) {
                    auto &depends = objectDepends[typeName];
                    if (feature == depends.feature)
                        return;
                    assert(depends.feature == "");
                    depends.feature = feature;
                }
            });
        });
    });
    return objectDepends;
}

static std::tuple<std::unordered_map<std::string, Function>,
                  std::unordered_map<std::string, std::set<FunctionInfo>>>
parseGropuedFunctions(XMLElement &registry) {
    auto handles = parseHandles(registry);
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

    std::unordered_map<std::string, Depends> functionDepends =
        parseObjectDepents(registry, "command");

    std::unordered_map<std::string, std::set<FunctionInfo>> groupedFunctions;

    std::unordered_map<std::string, Function> destroyFunctions;

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

static std::unordered_map<std::string, std::string> parseTypeStructureName(XMLElement &registry) {
    std::unordered_map<std::string, std::string> typeStructureName;
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

std::set<TypeInfo> parseTypeInfos(XMLElement &registry) {

    std::unordered_map<std::string, std::string> typeStructureName =
        parseTypeStructureName(registry);

    std::unordered_map<std::string, Depends> typeDepends = parseObjectDepents(registry, "type");

    auto CreateTypeInfo = [&](std::string name) {
        TypeInfo info;
        info.name = name;
        info.structureType = typeStructureName.at(name);
        if (auto it = typeDepends.find(name); it != typeDepends.end()) {
            info.depends = it->second;
        }
        return info;
    };
    std::set<TypeInfo> typeInfos;

    for (const auto &[name, _] : typeStructureName) {
        typeInfos.emplace(CreateTypeInfo(name));
    }
    return typeInfos;
}

std::set<ObjectInfo> parseObjectInfos(XMLElement &registry) {
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

    std::unordered_map<std::string, Depends> typeDepends = parseObjectDepents(registry, "type");

    auto [destroyFunctions, functions] = parseGropuedFunctions(registry);
    FunctionInfo::destroyFunctions = destroyFunctions;

    auto objectTypes = parseObjectType(registry);

    std::set<ObjectInfo> objectInfos;
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
