#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <print>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <sys/types.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#include <tinyxml2.h>
#include <utility>
#include <vector>
#include <vulkan/vulkan_core.h>

#include "CppGenerator.hpp"

using namespace tinyxml2;

XMLElement &FirstChildElement(XMLElement &element, const std::string &elementValue) {
    XMLElement *elem = element.FirstChildElement(elementValue.c_str());
    if (!elem) {
        std::cerr << "failed to find: " << elementValue << "\n";
        exit(EXIT_FAILURE);
    }
    return *elem;
}
XMLElement *FirstChildElementOrNullptr(XMLElement &element, const std::string &elementValue) {
    return element.FirstChildElement(elementValue.c_str());
}

void ForEachBreak(XMLElement &elem, const std::string &elementValue,
                  std::function<bool(XMLElement &)> fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        if (fun(*elems))
            break;
    }
}

void ForEach(XMLElement &elem, const std::string &elementValue,
             std::function<void(XMLElement &)> fun) {
    for (XMLElement *elems = elem.FirstChildElement(elementValue.c_str()); elems;
         elems = elems->NextSiblingElement(elementValue.c_str())) {
        fun(*elems);
    }
}

class CollectPrinter {
    std::set<std::string> collection;

  public:
    void add(const std::string &s) { collection.insert(s); }
    void add(const char *str) {
        if (!str)
            return;
        collection.insert(std::string(str));
    }
    ~CollectPrinter() { std::println("{}", collection); }
};

void printChildTypes(XMLElement &elem) {
    CollectPrinter c;
    for (XMLElement *elems = elem.FirstChildElement(); elems; elems = elems->NextSiblingElement()) {
        c.add(elems->ToElement()->Value());
    }
}

void Print(XMLElement &elem) {
    XMLPrinter p;
    elem.Accept(&p);
    std::println("{}", p.CStr());
}

bool HasAttributeValue(XMLElement &elem, const std::string &name, const std::string &value) {
    const char *attrib = elem.Attribute(name.c_str());
    if (attrib == nullptr)
        return false;
    return std::string_view(attrib) == value;
}
bool HasAttribute(XMLElement &elem, const std::string &name) {
    const char *attrib = elem.Attribute(name.c_str());
    return attrib != nullptr;
}

bool HasText(XMLElement &elem, const std::string &value) {
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

struct Function {
    std::string name;
    struct Argument {
        std::string name;
        std::string baseType;
        std::string leading;
        std::string postType;
        std::string trailing;

        std::string preTypePrint() const {
            std::string s = leading;
            if (!s.empty()) {
                if (s.back() != ' ')
                    s.push_back(' ');
            }
            return s;
        }

        std::string postTypePrint() const {
            std::string s = postType;
            if (!s.empty()) {
                if (s.front() != ' ')
                    s.insert(s.begin(), ' ');
                if (s.back() != ' ')
                    s.push_back(' ');
            } else {
                s = " ";
            }
            return s;
        }

        // [sth]
        std::string postArgumentPrint() const { return trailing; }

        std::string fullType() const {
            std::string s = leading;
            if (!s.empty())
                s += " ";
            s += baseType;
            std::string pt = postType;
            if (!pt.empty()) {
                if (pt.front() != ' ')
                    s += " ";
                s += pt;
            } else {
                s += " ";
            }
            return s;
        }
    };

    Function dropFirstArgument() const {
        assert(args.size() >= 1);
        Function f;
        f.returnType = returnType;
        f.name = name;
        f.args = std::vector<Argument>{args.begin() + 1, args.end()};
        return f;
    }

    Function dropLastArgument() const {
        assert(args.size() >= 1);
        Function f;
        f.returnType = returnType;
        f.name = name;
        f.args = std::vector<Argument>{args.begin(), args.end() - 1};
        return f;
    }

    std::vector<Argument> args;
    std::string returnType;

    // Function& operator=(Function&& other) {
    //     name = std::exchange(other.name, "");
    //     name = std::exchange(other.name, "");
    // }
};

// template <> struct std::formatter<Function> {
//     // accept default/no format spec
//     constexpr auto parse(std::format_parse_context &ctx) { return ctx.begin(); }

//     // Must be const and return the context's iterator type
//     template <typename FormatContext> auto format(const Function &f, FormatContext &ctx) const {
//         auto out = ctx.out();
//         out = std::format_to(out, "{} {}(", f.returnType, f.name);
//         for (size_t i = 0; i < f.args.size(); ++i) {
//             const auto &a = f.args[i];
//             if (a.isConst)
//                 out = std::format_to(out, "const ");
//             out = std::format_to(out, "{}", a.type);
//             if (a.isPtr)
//                 out = std::format_to(out, "*");
//             out = std::format_to(out, " {}", a.name);
//             if (i + 1 < f.args.size())
//                 out = std::format_to(out, ", ");
//         }
//         out = std::format_to(out, ")");
//         return out;
//     }
// };

std::unordered_map<std::string, std::string> parseHandles(XMLElement &registry) {
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
    return handles;
}

Function::Argument parseParam(XMLElement &paramEl) {
    Function::Argument arg;

    std::string leading;
    std::string type_inner;
    std::string between;
    std::string name_text;
    std::string after;

    int state = 0; // 0 = before <type>, 1 = after <type> before <name>, 2 = after <name>
    for (XMLNode *node = paramEl.FirstChild(); node; node = node->NextSibling()) {
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
struct Depends {
    std::string platform;
    std::string feature;
    std::set<std::string> extensions;
};

std::unordered_set<std::string> parseNotInternelFeatureNames(XMLElement &registry) {
    std::unordered_set<std::string> notInternelFeatureNames;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "apitype")) {
            if (HasAttributeValue(feature, "apitype", "internal")) {
                return;
            }
        }
        std::string notInternelFeatureName = feature.Attribute("name");
        notInternelFeatureNames.insert(notInternelFeatureName);
    });
    return notInternelFeatureNames;
}

std::unordered_map<std::string, Depends> parseObjectFeatureMacros(XMLElement &registry,
                                                                  const std::string &object) {
    std::unordered_map<std::string, Depends> objectDepends;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "apitype")) {
            if (HasAttributeValue(feature, "apitype", "internal"))
                return;
        }
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

std::unordered_map<std::string, std::string> parsePlatformMakros(XMLElement &registry) {
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

std::unordered_map<std::string, Depends> parseObjectDepents(XMLElement &registry,
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
            if (!HasAttribute(enumEntry, "value") ||
                !HasAttributeValue(enumEntry, "value", extension_enum_name) ||
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

struct FunctionInfo {
    std::string handle;
    Function function;
    Depends depends;

    bool operator<(const FunctionInfo &other) const {
        return std::tie(depends.platform, depends.feature, depends.extensions, function.name) <
               std::tie(other.depends.platform, other.depends.feature, other.depends.extensions,
                        other.function.name);
    }

    static void writeHeader(CppGenerator &gen, const FunctionInfo &info) {
        auto function = info.function;
        std::string vk = function.name.substr(0, 2);
        assert(vk == "vk");
        std::string name = function.name.substr(2);
        if (name.starts_with("Cmd")) {
            name = name.substr(3);
        }
        if (info.handle != "") {
            assert(function.args[0].baseType == info.handle);
            function = function.dropFirstArgument();
        }
        name[0] = std::tolower(name[0]);
        std::optional<Function::Argument> createArg;
        std::stringstream line;
        if (name.starts_with("create")) {
            createArg = function.args.back();
            createArg.value().name = createArg.value().name.substr(1);
            createArg.value().name[0] = std::tolower(createArg.value().name[0]);
            assert(function.returnType == "VkResult");
            line << "std::expected<" << createArg.value().baseType << ", VkResult>";
            function = function.dropLastArgument();
        } else {
            line << function.returnType;
        }
        line << " " << name << "(";
        for (size_t i = 0; i < function.args.size(); i++) {
            auto &arg = function.args[i];
            line << arg.fullType();
            line << arg.name << arg.postArgumentPrint();
            if (i != function.args.size() - 1)
                line << ", ";
        }
        line << ") const";
        gen.doLineBeginScope(line);
        if (createArg) {
            assert(!function.args.empty());
            gen.doWriteLine(createArg.value().baseType + " " + createArg.value().name +
                            " = VK_NULL_HANDLE;");
            std::stringstream init;
            init << "VkResult res = " << function.name << "(handle, ";
            for (size_t i = 0; i < function.args.size(); i++) {
                auto &arg = function.args[i];
                init << arg.name;
                init << ", ";
            }
            init << "&" << createArg.value().name << ")";
            gen.doIfWithInitializer(init.str(), "res != VK_SUCCESS");
            gen.doReturn(createArg.value().name);
            gen.doElse();
            gen.doReturn("std::unexpected(res);");
            gen.doIfEnd();
        } else {
            if (function.returnType != "void") {
                line << "return ";
            }
            line << function.name << "(";
            if (info.handle != "") {
                line << "handle";
                if (function.args.size() != 0) {
                    line << ", ";
                }
            }
            for (size_t i = 0; i < function.args.size(); i++) {
                auto &arg = function.args[i];
                line << arg.name;
                if (i != function.args.size() - 1)
                    line << ", ";
            }
            line << ");";
            gen.doWriteLine(line);
        }
        gen.endScope();
    }
};

std::unordered_map<std::string, std::set<FunctionInfo>>
parseGropuedFunctions(XMLElement &registry) {
    auto handles = parseHandles(registry);
    std::vector<Function> functions;

    XMLElement &commands = FirstChildElement(registry, "commands");
    ForEach(commands, "command", [&](XMLElement &command) {
        if (HasAttribute(command, "alias"))
            return;
        XMLElement &proto = FirstChildElement(command, "proto");
        std::string name = FirstChildElement(proto, "name").GetText();
        std::string returnType = FirstChildElement(proto, "type").GetText();
        std::vector<Function::Argument> args;
        ForEach(command, "param", [&](XMLElement &param) {
            if (HasAttribute(param, "api") && HasAttributeValue(param, "api", "vulkansc"))
                return;
            Function::Argument a = parseParam(param);
            a.name = FirstChildElement(param, "name").GetText();
            args.push_back(std::move(a));
        });
        functions.emplace_back(name, std::move(args), returnType);
    });

    std::unordered_map<std::string, Depends> functionDepends =
        parseObjectDepents(registry, "command");

    std::unordered_map<std::string, std::set<FunctionInfo>> groupedFunctions;
    for (const auto &f : functions) {
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
    return groupedFunctions;
}

std::unordered_map<std::string, std::string> parseTypeStructureName(XMLElement &registry) {
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

struct TypeInfo {
    std::string name;
    std::string structureType;
    Depends depends;

    bool operator<(const TypeInfo &other) const {
        return std::tie(depends.platform, depends.feature, depends.extensions, name) <
               std::tie(other.depends.platform, other.depends.feature, other.depends.extensions,
                        other.name);
    }

    static void header(CppGenerator &gen, const TypeInfo &ti) {
        gen.doWriteLine("template <> struct StructureType<" + ti.name + "> { " +
                        "static const constexpr VkStructureType t = " + ti.structureType + ";" +
                        " };");
        gen.doWriteLine("template " + ti.name + " Init<" + ti.name + ">();");
    }
};

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

template <typename T, typename F>
    requires requires(const T &t, std::ostream &o, CppGenerator &gen, F print) {
        { t.depends } -> std::same_as<const Depends &>;
        print(gen, std::declval<T>());
    }
void writeDepends(CppGenerator &gen, const std::set<T> &set, F print);

struct ObjectInfo {
    std::string name;
    Depends depends;
    std::set<FunctionInfo> functions;

    static std::unordered_map<std::string, std::unordered_set<std::string>> transitiveOwner;
    static std::unordered_map<std::string, std::string> handleOwner;

  private:
  public:
    bool operator<(const ObjectInfo &other) const {
        bool thisIsOwnedByOther = transitiveOwner[name].contains(other.name);
        bool otherIsOwnedByThis = transitiveOwner[other.name].contains(name);

        if (thisIsOwnedByOther) {
            std::println("{} > {}", name, other.name);
            return false;
        }
        if (otherIsOwnedByThis) {
            std::println("{} < {}", name, other.name);
            return true;
        }

        return std::tie(depends.platform, depends.feature, depends.extensions, name) <
               std::tie(other.depends.platform, other.depends.feature, other.depends.extensions,
                        other.name);
    }

    static void writeHeader(CppGenerator &gen, const ObjectInfo &info) {
        gen.doBeginStruct("Handle" + info.name);
        gen.doWriteLine(info.name + " handle = VK_NULL_HANDLE;");
        if (handleOwner[info.name] != "") {
            gen.doWriteLine("Handle" + handleOwner[info.name] + " owner;");
        }
        writeDepends(gen, info.functions, FunctionInfo::writeHeader);
        gen.doEndStruct();
    }
};

std::unordered_map<std::string, std::unordered_set<std::string>> ObjectInfo::transitiveOwner;
std::unordered_map<std::string, std::string> ObjectInfo::handleOwner;

void parse([[maybe_unused]] XMLElement &registry) {}

std::set<ObjectInfo> parseObjectInfos(XMLElement &registry) {
    std::unordered_map<std::string, std::string> handleOwner = parseHandles(registry);

    std::unordered_map<std::string, std::unordered_set<std::string>> transitiveOwner;
    for (const auto &h : handleOwner) {
        transitiveOwner[h.first].insert(h.second);
    }
    std::unordered_map<std::string, std::unordered_set<std::string>> newPairs;
    do {
        for (const auto &h : newPairs) {
            transitiveOwner[h.first].insert_range(h.second);
        }
        newPairs.clear();
        for (const auto &h1 : transitiveOwner) {
            for (const auto &h2 : transitiveOwner) {
                if (h1.second.contains(h2.first)) {
                    for (const auto &h3 : h2.second) {
                        if (!h1.second.contains(h3)) {
                            newPairs[h1.first].insert(h3);
                        }
                    }
                }
            }
        }
    } while (!newPairs.empty());

    ObjectInfo::transitiveOwner = transitiveOwner;
    ObjectInfo::handleOwner = handleOwner;

    std::unordered_map<std::string, Depends> typeDepends = parseObjectDepents(registry, "type");

    std::unordered_map<std::string, std::set<FunctionInfo>> functions =
        parseGropuedFunctions(registry);

    std::set<ObjectInfo> objectInfos;
    for (const auto &[handle, _] : handleOwner) {
        ObjectInfo objectInfo;
        objectInfo.name = handle;
        if (typeDepends.contains(handle)) {
            objectInfo.depends = typeDepends.at(handle);
        }
        if (functions.contains(handle)) {
            objectInfo.functions = functions.at(handle);
        }
        objectInfos.insert(objectInfo);
    }
    return objectInfos;
}

template <typename T, typename F>
    requires requires(const T &t, std::ostream &o, CppGenerator &gen, F print) {
        { t.depends } -> std::same_as<const Depends &>;
        print(gen, std::declval<T>());
    }
void writeDepends(CppGenerator &gen, const std::set<T> &set, F print) {
    Depends currendDepends;

    auto close_platform_if_open = [&]() {
        if (!currendDepends.platform.empty()) {
            gen.doMakroEndif();
            currendDepends.platform.clear();
        }
    };
    auto close_depends_if_open = [&]() {
        if (currendDepends.feature != "" || !currendDepends.extensions.empty()) {
            gen.doMakroEndif();
            currendDepends.feature = "";
            currendDepends.extensions.clear();
        }
    };

    auto make_extension_condition = [](const Depends &depends) -> std::string {
        std::string extCond;
        bool firstExt = true;
        for (auto &e : depends.extensions) {
            if (!firstExt)
                extCond += " || ";
            extCond += "defined(" + e + ")";
            firstExt = false;
        }
        if (!extCond.empty()) {
            extCond = "(" + extCond + ")";
        }

        std::string featCond;
        if (!depends.feature.empty()) {
            featCond = "defined(" + depends.feature + ")";
        }

        if (!featCond.empty() && !extCond.empty()) {
            return featCond + " && " + extCond;
        } else if (!featCond.empty()) {
            return featCond;
        } else {
            return extCond;
        }
    };

    for (const T &t : set) {
        if (t.depends.platform != currendDepends.platform) {
            close_depends_if_open();
            close_platform_if_open();
            if (!t.depends.platform.empty()) {
                gen.doMakroIfdef(t.depends.platform);
                currendDepends.platform = t.depends.platform;
            }
        }

        if (t.depends.feature != currendDepends.feature ||
            t.depends.extensions != currendDepends.extensions) {
            close_depends_if_open();

            if (t.depends.feature != "" || !t.depends.extensions.empty()) {
                gen.doMakroIf(make_extension_condition(t.depends));
                currendDepends.feature = t.depends.feature;
                currendDepends.extensions = t.depends.extensions;
            }
        }

        print(gen, t);
    }

    close_depends_if_open();
    close_platform_if_open();
}

void writeStructures(XMLElement &registry, [[maybe_unused]] const std::filesystem::path &genSrc,
                     [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<TypeInfo> typeInfos = parseTypeInfos(registry);

    std::filesystem::path structureTypes = genSrc / "Structures.cpp";

    CppGenerator gen;

    gen.doIncludeLocal("Structures.hpp");
    gen.doIncludeLocal("Vulkan.hpp");
    gen.doIncludeLocal("Objects.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doEmptyLine();

    gen.doCode(R"--(
template <typename T> struct StructureType;

template <typename T>
T Init() {
  T t = {};
  t.sType = StructureType<T>::t;
  return t;
}

)--");

    writeDepends(gen, typeInfos, TypeInfo::header);

    gen.doEndNamespace();

    std::ofstream o(structureTypes);
    o << gen.buff.rdbuf();
}

void writeObjects(XMLElement &registry, [[maybe_unused]] const std::filesystem::path &genSrc,
                  [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(registry);

    std::filesystem::path objects = genInclude / "Objects.hpp";

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("expected");
    gen.doEmptyLine();
    gen.doIncludeLocal("Vulkan.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Objects");
    gen.doEmptyLine();

    writeDepends(gen, objectInfos, ObjectInfo::writeHeader);

    gen.doEndNamespace();
    gen.doEndNamespace();

    std::ofstream o(objects);
    o << gen.buff.rdbuf();
}

void writeFiles(
    const std::filesystem::path &genSrc, std::filesystem::path &genInclude, XMLElement &registry,
    const std::vector<std::tuple<std::vector<std::string>,
                                 std::function<void(XMLElement &, const std::filesystem::path &,
                                                    const std::filesystem::path &)>>> &functions) {
    for (const auto &[filenames, function] : functions) {
        std::print("Writing {}:", filenames);
        auto start = std::chrono::high_resolution_clock::now();
        function(registry, genSrc, genInclude);
        std::println("{}", std::chrono::duration_cast<std::chrono::milliseconds>(
                               std::chrono::high_resolution_clock::now() - start));
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    std::filesystem::path xml = argv[1];
    std::filesystem::path genDir = argv[2];
    std::println("xml: {}", xml.string());
    std::println("genDir: {}", genDir.string());
    std::filesystem::path genInclude = genDir / "include";
    std::filesystem::path genSrc = genDir / "src";
    std::filesystem::create_directories(genInclude);
    std::filesystem::create_directories(genSrc);

    XMLDocument doc;
    doc.LoadFile(xml.string().c_str());

    XMLElement &registry = *doc.RootElement();

    writeFiles(genSrc, genInclude, registry,
               {{{"Structures.cpp"}, writeStructures}, {{"Objects.hpp"}, writeObjects}});

    writeStructures(registry, genSrc, genInclude);

    // auto functions = parseFunctions(registry);
}
