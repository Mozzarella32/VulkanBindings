#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <sys/types.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <tinyxml2.h>

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

void Print(XMLElement &elem) {
    XMLPrinter p;
    elem.Accept(&p);
    std::cout << p.CStr() << "\n";
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
    handles.erase(handles.find("VkDisplayModeKHR"));
    return handles;
}

std::unordered_map<std::string, std::string> parseObjectType(XMLElement &registry) {
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

Function::Argument parseParam(XMLElement &param, const std::vector<Function::Argument> &prevArgs) {
    Function::Argument arg;

    std::string leading;
    std::string type_inner;
    std::string between;
    std::string name_text;
    std::string after;

    if (HasAttribute(param, "len")) {
        std::string len = param.Attribute("len");
        if (len != "null-terminated" && len != "1" && !len.contains("->") &&
            !len.starts_with("latexmath")) {
            auto it = std::ranges::find_if(
                prevArgs, [&len](const Function::Argument &arg) { return arg.name == len; });
            assert(it != prevArgs.end());
            arg.arrayWithLengthOf = std::distance(prevArgs.begin(), it);
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
struct Depends {
    std::string m_namespace;
    std::string platform;
    std::string feature;
    std::set<std::string> extensions;
};

std::unordered_set<std::string> parseNotInternelFeatureNames(XMLElement &registry) {
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

std::unordered_map<std::string, Depends> parseObjectFeatureMacros(XMLElement &registry,
                                                                  const std::string &object) {
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

struct FunctionInfo {
    std::string handle;
    Function function;
    Depends depends;

    static std::unordered_map<std::string, std::string> handleOwner;
    static std::unordered_map<std::string, Function> destroyFunctions;

    bool operator<(const FunctionInfo &other) const {
        return std::tie(depends.platform, depends.feature, depends.extensions, function.name) <
               std::tie(other.depends.platform, other.depends.feature, other.depends.extensions,
                        other.function.name);
    }

    static inline std::string capitalizeFirst(std::string s) {
        if (s.empty())
            return s;
        s[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(s[0])));
        return s;
    }

    struct SignaturePrep {
        Function decl;
        Function mapping;
        enum Type {
            Normal,
            Create,
            CreateVec,
            Get,
            GetResult,
            GetResultVec2,
        } type = Type::Normal;
        Function::Argument nowReturn;
        Function::Argument additional;
    };

    static SignaturePrep prepareSignature(const FunctionInfo &info) {
        SignaturePrep out;

        auto prepareStr = [](std::string str) {
            if (str[0] != 'p')
                return str;
            str = str.substr(1);
            str[0] = std::tolower(str[0]);
            return str;
        };

        auto function = info.function;
        auto mapping = info.function;
        std::string vk = function.name.substr(0, 2);
        assert(vk == "vk");
        std::string name = function.name.substr(2);
        if (name.rfind("Cmd", 0) == 0) {
            name = name.substr(3);
        }

        if (info.handle != "") {
            auto handleWithoutVk = info.handle.substr(2);
            if (auto it = name.find(handleWithoutVk);
                it != std::string::npos && handleWithoutVk != "") {
                name.erase(it, handleWithoutVk.size());
            }
        }

        if (!name.empty())
            name[0] = std::tolower(name[0]);

        function.replaceName(name);

        std::map<size_t, size_t> argsToDelete;
        for (size_t i = 0; i < function.args.size(); i++) {
            auto &arg = function.args[i];
            if (arg.arrayWithLengthOf.has_value()) {
                if (!argsToDelete.contains(arg.arrayWithLengthOf.value())) {
                    argsToDelete[arg.arrayWithLengthOf.value()] = i;
                }
                std::string baseType = arg.baseType;
                if (baseType == "void") {
                    baseType = "uint8_t";
                }
                if (arg.postType == "*") {
                    arg.baseType = "std::vector<" + baseType + ">";
                } else if (arg.postType == "* const*") {
                    arg.baseType = "std::vector<const " + baseType + " *>";
                } else {
                    assert(false);
                }
                arg.name = prepareStr(arg.name);
                arg.postType = "&";
                mapping.replaceArg(i, arg.name + ".data()");
            }
        }

        for (auto [i, replace] : argsToDelete | std::views::reverse) {
            mapping.replaceArg(i, function.args[replace].name + ".size()");
            function.args.erase(function.args.begin() + i);
        }

        if (info.handle != "") {
            assert(function.args.size() >= 1);
            assert(function.args[0].baseType == info.handle);
            function.deleteArg(0);
            mapping.replaceArg(0, "handle");
        }

        static const std::unordered_set<std::string> ignorList{
            "getExternalComputeQueueDataNV", "getDescriptorEXT", "getDescriptorSetHostMappingVALVE",
            "getQueryPoolResults"};

        if ((name.starts_with("create") || name == "allocateMemory") &&
            handleOwner.contains(function.args.back().baseType)) {
            Function::Argument nowReturn = function.args.back();
            assert(function.returnType == "VkResult");
            function.replaceReturnType("std::expected<Handle" + nowReturn.baseType + ", VkResult>");

            function.deleteArg(function.args.size() - 1);
            out.nowReturn = nowReturn;
            out.type = SignaturePrep::Type::Create;
        } else if (name.starts_with("create") &&
                   function.args.back().baseType.starts_with("std::vector<")) {
            std::string type = function.args.back().baseType.substr(
                std::string("std::vector<").size(), function.args.back().baseType.size() -
                                                        std::string(">").size() -
                                                        std::string("std::vector<").size());
            type = "std::vector<Handle" + type + ">";
            out.additional = function.args.back();
            out.additional.replaceName(function.args.back().name + "Raw");
            function.replaceReturnType("std::expected<" + type + ", VkResult>");
            out.nowReturn = function.args.back().replaceBaseType(type);
            out.type = SignaturePrep::Type::CreateVec;
            function.deleteArg(function.args.size() - 1);
        } else if ((name.starts_with("get") || name.starts_with("enumerate")) &&
                   !ignorList.contains(name)) {
            if (function.returnType == "void") {
                function.replaceReturnType(function.args.back().baseType);
                out.nowReturn = function.args.back();
                function.deleteArg(function.args.size() - 1);
                out.type = SignaturePrep::Type::Get;
            } else if (function.returnType == "VkResult" &&
                       function.args.back().baseType != "void" && !name.contains("Status") &&
                       !name.contains("Result")) {
                if (function.args.size() >= 2 &&
                    function.args.back().baseType.starts_with("std::vector<") &&
                    function.args[function.args.size() - 2].baseType.starts_with("std::vector") &&
                    name.starts_with("enumerate")) {
                    Function::Argument nowReturn = function.args.back();
                    Function::Argument additional = function.args[function.args.size() - 2];

                    function.replaceReturnType("std::expected<std::tuple<" + nowReturn.baseType +
                                               ", " + additional.baseType + ">, VkResult>");

                    function.deleteArg(function.args.size() - 1);
                    function.deleteArg(function.args.size() - 1);
                    out.nowReturn = nowReturn;
                    out.additional = additional;
                    out.type = SignaturePrep::Type::GetResultVec2;
                } else {
                    Function::Argument nowReturn = function.args.back();
                    function.replaceReturnType("std::expected<" + nowReturn.baseType +
                                               ", VkResult>");

                    function.deleteArg(function.args.size() - 1);
                    out.nowReturn = nowReturn;
                    out.type = SignaturePrep::Type::GetResult;
                }
            }
        }
        out.mapping = mapping;
        out.decl = function;
        return out;
    }

    static void writeHeader(CppGenerator &gen, const FunctionInfo &info,
                            bool staticMemberFunctions) {
        auto decl = prepareSignature(info).decl;
        if (!decl.args.empty() && decl.args.back().name == "pAllocator") {
            decl.args.back().trailing += " = nullptr";
        }
        if (staticMemberFunctions) {
            gen.doCode("static " + decl.toSignature() + ";");
        } else {
            gen.doCode(decl.toSignature() + " const;");
        }
    }

    static void writeImpl(CppGenerator &gen, const FunctionInfo &info,
                          const std::string &containingClass, bool staticMemberFunctions) {
        SignaturePrep prep = prepareSignature(info);

        auto capitilizeFirst = [](const std::string &s) {
            std::string copy = s;
            if (!copy.empty())
                copy[0] = std::toupper(copy[0]);
            return copy;
        };

        std::stringstream sigLine;
        if (staticMemberFunctions) {
            gen.doLineBeginScope(prep.decl.toSignature(containingClass));
        } else {
            gen.doLineBeginScope(prep.decl.toSignature(containingClass) + " const");
        }

        if (prep.type == SignaturePrep::Type::Get) {
            const auto &getArg = prep.nowReturn;
            if (getArg.baseType.starts_with("std::vector")) {
                Function call = prep.mapping;
                gen.doWriteLine(call.args[call.args.size() - 2].baseType + " count = 0;");
                call.replaceArg(call.args.size() - 2, "&count");
                call.replaceArg(call.args.size() - 1, "nullptr");
                gen.doWriteLine(call.toCall() + ";");
                gen.doWriteLine(getArg.baseType + " " + getArg.name + "(count);");
                call.replaceArg(call.args.size() - 1, getArg.name + ".data()");
                gen.doWriteLine(call.toCall() + ";");
                gen.doWriteLine(getArg.name + ".resize(count);");
                gen.doReturn(getArg.name);
            } else {
                gen.doWriteLine(getArg.baseType + " " + getArg.name + ";");
                Function call = prep.mapping;
                call.replaceArg(call.args.size() - 1, "&" + getArg.name);
                gen.doWriteLine(call.toCall() + ";");
                gen.doReturn(getArg.name);
            }
        } else if (prep.type == SignaturePrep::Type::GetResult) {
            const auto &getArg = prep.nowReturn;
            if (getArg.baseType.starts_with("std::vector")) {
                auto call = prep.mapping;
                if (!prep.decl.args.empty() &&
                    prep.decl.args.begin()->baseType.starts_with("std::vector")) {
                    gen.doWriteLine(getArg.baseType + " " + getArg.name + "(" +
                                    prep.decl.args.begin()->name + ".size());");
                    gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                            gen.makeConditionNotOneOf("res", call.successcodes));
                    gen.doReturn("std::unexpected(res)");
                    gen.doIfEnd();
                    gen.doReturn(getArg.name);
                } else {
                    gen.doWriteLine(call.args[call.args.size() - 2].baseType + " count = 0;");
                    if (call.args[call.args.size() - 2].postType != "*") {
                        call.replaceArg(call.args.size() - 2, "count");
                    } else {
                        call.replaceArg(call.args.size() - 2, "&count");
                    }
                    call.replaceArg(call.args.size() - 1, "nullptr");
                    gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                            gen.makeConditionNotOneOf("res", call.successcodes));
                    gen.doReturn("std::unexpected(res)");
                    gen.doIfEnd();
                    gen.doWriteLine(getArg.baseType + " " + getArg.name + "(count);");
                    call.replaceArg(call.args.size() - 1, getArg.name + ".data()");
                    gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                            gen.makeConditionNotOneOf("res", call.successcodes));
                    gen.doReturn("std::unexpected(res)");
                    gen.doIfEnd();
                    gen.doWriteLine(getArg.name + ".resize(count);");
                    gen.doReturn(getArg.name);
                }
            } else {
                gen.doWriteLine(getArg.baseType + " " + getArg.name + ";");
                Function call = prep.mapping;
                call.replaceArg(call.args.size() - 1, "&" + getArg.name);
                gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                        gen.makeConditionNotOneOf("res", call.successcodes));
                gen.doReturn("std::unexpected(res)");
                gen.doIfEnd();
                gen.doReturn(getArg.name);
            }
        } else if (prep.type == SignaturePrep::Type::GetResultVec2) {
            const auto &vec1 = prep.nowReturn;
            const auto &vec2 = prep.additional;
            Function call = prep.mapping;
            gen.doWriteLine(call.args[call.args.size() - 3].baseType + " count = 0;");
            call.replaceArg(call.args.size() - 3, "&count");
            call.replaceArg(call.args.size() - 2, "nullptr");
            call.replaceArg(call.args.size() - 1, "nullptr");
            gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                    gen.makeConditionNotOneOf("res", call.successcodes));
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
            gen.doWriteLine(vec1.baseType + " " + vec1.name + "(count);");
            gen.doWriteLine(vec2.baseType + " " + vec2.name + "(count);");
            call.replaceArg(call.args.size() - 2, vec2.name + ".data()");
            call.replaceArg(call.args.size() - 1, vec1.name + ".data()");
            gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                    gen.makeConditionNotOneOf("res", call.successcodes));
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
            gen.doWriteLine(vec1.name + ".resize(count);");
            gen.doWriteLine(vec2.name + ".resize(count);");
            gen.doReturn("std::make_tuple(" + vec1.name + ", " + vec2.name + ")");

        } else if (prep.type == SignaturePrep::Type::Create) {
            const auto &createArg = prep.nowReturn;
            gen.doWriteLine(createArg.baseType + " " + createArg.name + " = VK_NULL_HANDLE;");

            Function call = prep.mapping;
            call.replaceArg(call.args.size() - 1, "&" + createArg.name);

            gen.doIfWithInitializer("VkResult res = " + call.toCall(), "res != VK_SUCCESS");

            std::string handleVar = "handle" + capitilizeFirst(createArg.name);
            if (destroyFunctions[createArg.baseType].args.size() == 3) {
                gen.doWriteLine("Handle" + createArg.baseType + " " + handleVar + "{std::move(" +
                                createArg.name + "), handle};");
            } else {
                gen.doWriteLine("Handle" + createArg.baseType + " " + handleVar + "{std::move(" +
                                createArg.name + ")};");
            }
            gen.doReturn(handleVar);
            gen.doElse();
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
        } else if (prep.type == SignaturePrep::Type::CreateVec) {
            const auto &nowReturn = prep.nowReturn;
            const auto &additional = prep.additional;

            gen.doWriteLine(
                additional.baseType + " " + additional.name + "{" +
                prep.mapping
                    .args[prep.mapping.args[prep.mapping.args.size() - 1].arrayWithLengthOf.value()]
                    .name +
                "};");
            Function call = prep.mapping;
            call.replaceArg(call.args.size() - 1, additional.name + ".data()");

            gen.doIfWithInitializer("VkResult res = " + call.toCall(), "res != VK_SUCCESS");

            gen.doWriteLine(nowReturn.baseType + " " + nowReturn.name + ";");
            gen.doRangedFor("auto& h", additional.name);
            std::string type =
                additional.baseType.substr(std::string("std::vector<").size(),
                                           additional.baseType.size() - std::string(">").size() -
                                               std::string("std::vector<").size());

            gen.doWriteLine(nowReturn.name + ".emplace_back(Handle" + type +
                            "{std::move(h), handle});");
            gen.doForEnd();

            gen.doReturn(nowReturn.name);
            gen.doElse();
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();

        } else if (prep.type == SignaturePrep::Type::Normal) {
            Function call = prep.mapping;
            gen.doWriteLine(call.toCallReturn() + ";");
        }

        gen.endScope();
    }
};

std::unordered_map<std::string, std::string> FunctionInfo::handleOwner;
std::unordered_map<std::string, Function> FunctionInfo::destroyFunctions;

std::tuple<std::unordered_map<std::string, Function>,
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
    // for (const auto &f : functions) {
    //     if (f.name.starts_with("vkGet") && f.returnType == "void") {
    //         if ((f.args.end() - 2)->name.ends_with("Count")) {
    //             std::println("Count : {}", f);

    //         } else {

    //             std::println("{}", f);
    //         }
    //     }
    // }
    return std::make_tuple(destroyFunctions, groupedFunctions);
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
        return std::tie(depends.m_namespace, depends.platform, depends.feature, depends.extensions,
                        name) < std::tie(other.depends.m_namespace, other.depends.platform,
                                         other.depends.feature, other.depends.extensions,
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
void writeDepends(CppGenerator &gen, const std::set<T> &set, F print, bool reversed = false);

struct ObjectInfo {
    std::string name;
    std::string objectType;
    Depends depends;
    Function destroyFunction;
    std::set<FunctionInfo> functions;
    std::set<FunctionInfo> staticFunctions;
    int rank;
    std::string owner;

  private:
  public:
    bool operator<(const ObjectInfo &other) const {

        return std::tie(other.rank, depends.platform, depends.feature, depends.extensions, name) <
               std::tie(rank, other.depends.platform, other.depends.feature,
                        other.depends.extensions, other.name);
    }
    static void writeHeader(CppGenerator &gen, const ObjectInfo &info) {
        assert(!info.functions.empty() || !info.staticFunctions.empty());
        auto epilog = [&]() {
            writeDepends(gen, info.staticFunctions,
                         std::bind_back(FunctionInfo::writeHeader, true));
            writeDepends(gen, info.functions, std::bind_back(FunctionInfo::writeHeader, false));
            gen.doEndStruct();
        };

        if (info.destroyFunction.name == "") {
            gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::NonOwned<" +
                              info.name + ", " + info.objectType + ">");
            gen.doWriteLine("using NonOwned::NonOwned;");
            epilog();
            return;
        }
        if (info.destroyFunction.args.size() == 3) {
            assert(info.owner != "");
            gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::OwnedUnique<" +
                              info.name + ", " + info.objectType + ", Handle" + info.owner + ", " +
                              info.owner + ", &" + info.destroyFunction.name + ">");
            gen.doWriteLine("using OwnedUnique::OwnedUnique;");
            epilog();
            return;
        }
        assert(info.destroyFunction.args.size() == 2);
        if (info.owner == "") {
            gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name +
                              ", " + info.objectType + ", &" + info.destroyFunction.name + ">");
            epilog();
            return;
        }
        gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name +
                          ", " + info.objectType + ", &" + info.destroyFunction.name + ", Handle" +
                          info.owner + ">");
        epilog();
    }

    static void writeForwardDecl(CppGenerator &gen, const ObjectInfo &info) {
        if (info.owner.ends_with("Pool") && info.name.ends_with("s")) {
            const std::string handleName = "HandleVk" + info.name.substr(0, info.name.size() - 1);
            gen.doWriteLine("using HandleVk" + info.name + " = impl_Objects::PoolAllocated<impl_Objects::" +
                            handleName + ", HandleVkDevice, VkDevice, Handle" + info.owner + ", &" +
                            info.destroyFunction.name + ">;");
            return;
        }
        if (!info.functions.empty()) {
            gen.doWriteLine("struct Handle" + info.name + ";");
            return;
        }
        if (info.destroyFunction.name == "") {
            gen.doWriteLine("using Handle" + info.name + " = impl_Objects::NonOwned<" + info.name +
                            ", " + info.objectType + ">;");
            return;
        }
        if (info.destroyFunction.args.size() == 3) {
            assert(info.owner != "");
            gen.doWriteLine("using Handle" + info.name + " = impl_Objects::OwnedUnique<" +
                            info.name + ", " + info.objectType + ", Handle" + info.owner + ", " +
                            info.owner + ", &" + info.destroyFunction.name + ">;");
            return;
        }
        assert(info.destroyFunction.args.size() == 2);
        if (info.owner == "") {
            gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name +
                              ", " + info.objectType + ", &" + info.destroyFunction.name + ">");
            return;
        }
        gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name +
                          ", " + info.objectType + ", &" + info.destroyFunction.name + ", Handle" +
                          info.owner + ">");
    }
    static void writeImpl(CppGenerator &gen, const ObjectInfo &info) {
        assert(!info.functions.empty() || !info.staticFunctions.empty());
        if (!info.staticFunctions.empty())
            writeDepends(gen, info.staticFunctions,
                         std::bind_back(FunctionInfo::writeImpl, "Handle" + info.name, true));
        if (!info.functions.empty())
            writeDepends(gen, info.functions,
                         std::bind_back(FunctionInfo::writeImpl, "Handle" + info.name, false));
    }
};

std::set<ObjectInfo> parseObjectInfos(XMLElement &registry) {
    std::unordered_map<std::string, std::string> handleOwner = parseHandles(registry);

    std::unordered_map<std::string, std::string> handlesToInstert;
    for (const auto &[handle, owner] : handleOwner) {
        if (owner.ends_with("Pool")) {
            auto name = handle.substr(2) + "s"; // Split Vk off + s
            handlesToInstert[name] = owner;
        }
    }
    handleOwner.insert_range(std::move(handlesToInstert));

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
    FunctionInfo::handleOwner = handleOwner;

    std::unordered_map<std::string, Depends> typeDepends = parseObjectDepents(registry, "type");

    auto [destroyFunctions, functions] = parseGropuedFunctions(registry);
    FunctionInfo::destroyFunctions = destroyFunctions;

    auto objectTypes = parseObjectType(registry);

    std::set<ObjectInfo> objectInfos;
    for (const auto &[handle, owner] : handleOwner) {
        ObjectInfo objectInfo;
        objectInfo.name = handle;
        if (!owner.ends_with("Pool") || !handle.ends_with("s")) {
            objectInfo.objectType = objectTypes.at(handle);
        }
        if (typeDepends.contains(handle)) {
            objectInfo.depends = typeDepends.at(handle);
        }
        if (owner.ends_with("Pool") && !handle.ends_with("s")) {
            std::cout << "namespace impl_Objects: " << handle << "\n";
            objectInfo.depends.m_namespace = "impl_Objects";
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

template <typename T, typename F>
    requires requires(const T &t, std::ostream &o, CppGenerator &gen, F print) {
        { t.depends } -> std::same_as<const Depends &>;
        print(gen, std::declval<T>());
    }
void writeDepends(CppGenerator &gen, const std::set<T> &set, F print, bool reversed) {
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
    auto close_namespace_if_open = [&]() {
        if (!currendDepends.m_namespace.empty()) {
            gen.doEndNamespace();
            currendDepends.m_namespace.clear();
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

    auto processElement = [&](const T &t) {
        if (t.depends.m_namespace != currendDepends.m_namespace) {
            close_depends_if_open();
            close_platform_if_open();
            close_namespace_if_open();
            if (!t.depends.m_namespace.empty()) {
                gen.doBeginNamespace(t.depends.m_namespace);
                currendDepends.m_namespace = t.depends.m_namespace;
            }
        }

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
    };

    if (!reversed) {
        for (const T &t : set) {
            processElement(t);
        }
    } else {
        for (const T &t : set | std::views::reverse) {
            processElement(t);
        }
    }

    close_depends_if_open();
    close_platform_if_open();
    close_namespace_if_open();
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
    gen.doEmptyLine();

    std::ofstream o(structureTypes);
    o << gen.buff.rdbuf();
}

void writeObjects(XMLElement &registry, [[maybe_unused]] const std::filesystem::path &genSrc,
                  [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(registry);

    std::filesystem::path objectsHpp = genInclude / "Objects.hpp";
    std::filesystem::path objectsCpp = genSrc / "Objects.cpp";

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("cassert");
    gen.doIncludeGlobal("cstdint");
    gen.doIncludeGlobal("expected");
    gen.doIncludeGlobal("tuple");
    gen.doIncludeGlobal("utility");
    gen.doIncludeGlobal("vector");
    gen.doEmptyLine();
    gen.doIncludeLocal("Vulkan.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Objects");

    gen.doCode(R"--(
template<typename Handle_T, VkObjectType Obj_T, auto Destroy_Fun, typename Creator_T>
struct Unique {
    using handle_type = Handle_T;
    static constexpr const VkObjectType objectType = Obj_T;

  protected:
    Handle_T handle = VK_NULL_HANDLE;
    Unique(Handle_T&& h) : handle(h) {}

    friend Creator_T;

  public:
    Unique() {}
    Unique(Unique&& other) : handle(std::exchange(other.handle, VK_NULL_HANDLE)) {}
    Unique& operator=(Unique&& other) noexcept {
        cleanup();
        handle = std::exchange(other.handle, VK_NULL_HANDLE);
    }
    void cleanup() noexcept {
        if (handle != VK_NULL_HANDLE) {
            (*Destroy_Fun)(handle, nullptr);
            handle = VK_NULL_HANDLE;
        }
    }
    ~Unique() noexcept { cleanup(); }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template<typename Handle_T, VkObjectType Obj_T, typename Owner_T, typename Owner_Handle_T, auto Destroy_Fun>
struct OwnedUnique {
    using handle_type = Handle_T;
    static constexpr const VkObjectType objectType = Obj_T;

  protected:
    Handle_T handle = VK_NULL_HANDLE;
    Owner_Handle_T owner = VK_NULL_HANDLE;
    OwnedUnique(Handle_T&& h, Owner_Handle_T o) : handle(h), owner(o) {}

    friend Owner_T;

  public:
    OwnedUnique() {}
    OwnedUnique(OwnedUnique&& other) : handle(std::exchange(other.handle, VK_NULL_HANDLE)), owner(std::exchange(other.owner, VK_NULL_HANDLE)) {}
    OwnedUnique& operator=(OwnedUnique&& other) noexcept {
        cleanup();
        handle = std::exchange(other.handle, VK_NULL_HANDLE);
        owner = std::exchange(other.owner, VK_NULL_HANDLE);
    }
    void cleanup() noexcept {
        if (handle != VK_NULL_HANDLE) {
            (*Destroy_Fun)(owner, handle, nullptr);
            handle = VK_NULL_HANDLE;
            owner = VK_NULL_HANDLE;
        }
    }
    ~OwnedUnique() noexcept { cleanup(); }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template <typename Handle_T, VkObjectType Obj_T> struct NonOwned {
    using handle_type = Handle_T;
    static constexpr const VkObjectType objectType = Obj_T;

  protected:
    Handle_T handle{VK_NULL_HANDLE};
    NonOwned(Handle_T &&handle) : handle(std::move(handle)) {}

  public:
    NonOwned() {}
    operator Handle_T() const { return handle; }
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T,
          auto Free_fun>
struct PoolAllocated {
    using handle_type = typename Handle_T::handle_type;
    static constexpr const VkObjectType objectType = Handle_T::Obj_T;
    bool is_pool_allocated = true;

  private:
    std::vector<Handle_T> handles{};
    Pool_Handle_T pool = VK_NULL_HANDLE;
    Owner_Handle_T owner = VK_NULL_HANDLE;

    PoolAllocated(std::vector<Handle_T> &&handles, Pool_Handle_T pool, Owner_Handle_T owner)
        : handles(std::move(handles)), pool(pool), owner(owner) {}

    friend Owner_T;

  public:
    PoolAllocated() {}
    PoolAllocated(PoolAllocated &&other)
        : handles(std::exchange(other.handles, {})),
          pool(std::exchange(other.pool, VK_NULL_HANDLE)),
          owner(std::exchange(other.owner), VK_NULL_HANDLE) {}
    PoolAllocated &operator=(PoolAllocated &&other) noexcept {
        cleanup();
        handles = std::exchange(other.handles, {});
        pool = std::exchange(other.pool, VK_NULL_HANDLE);
        owner = std::exchange(other.owner, VK_NULL_HANDLE);
    }
    void cleanup() {
        if (!handles.empty()) {
            (*Free_fun)(owner, pool, handles.size(), handles.data());
            handles.clear();
            pool = VK_NULL_HANDLE;
            owner = VK_NULL_HANDLE;
        }
    }
    ~PoolAllocated() noexcept { cleanup(); }
    explicit operator bool() const { return !handles.empty(); }
   Handle_T &operator[](size_t n) {
        assert(n < handles.size());
        return handles[n];
    }
    const Handle_T &operator[](size_t n) const {
        assert(n < handles.size());
        return handles[n];
    }
    decltype(handles)::iterator begin() { return handles.begin(); }
    decltype(handles)::iterator end() { return handles.end(); }
    decltype(handles)::const_iterator cbegin() const { return handles.cbegin(); }
    decltype(handles)::const_iterator cend() const { return handles.cend(); }
    decltype(handles)::reverse_iterator rbegin() { return handles.rbegin(); }
    decltype(handles)::reverse_iterator rend() { return handles.rend(); }
    decltype(handles)::const_reverse_iterator crbegin() const { return handles.crbegin(); }
    decltype(handles)::const_reverse_iterator crend() const { return handles.crend(); }
};

)--");

    gen.doEndNamespace();

    std::set<ObjectInfo> objectsWithFuns =
        objectInfos |
        std::views::filter([](const ObjectInfo &info) { return !info.functions.empty(); }) |
        std::ranges::to<std::set<ObjectInfo>>();

    writeDepends(gen, objectInfos, ObjectInfo::writeForwardDecl, true);
    writeDepends(gen, objectsWithFuns, ObjectInfo::writeHeader);

    gen.doEndNamespace();

    std::ofstream o(objectsHpp);
    o << gen.buff.rdbuf();
    o.close();

    gen.doIncludeLocal("Objects.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doEmptyLine();

    writeDepends(gen, objectsWithFuns, ObjectInfo::writeImpl);

    gen.doEndNamespace();

    o.open(objectsCpp);
    o << gen.buff.rdbuf();
}

void writeFiles(
    const std::filesystem::path &genSrc, std::filesystem::path &genInclude, XMLElement &registry,
    const std::vector<std::tuple<std::vector<std::string>,
                                 std::function<void(XMLElement &, const std::filesystem::path &,
                                                    const std::filesystem::path &)>>> &functions) {
    for (const auto &[filenames, function] : functions) {
        std::cout << "Writing : [";
        for (size_t i = 0; i < filenames.size(); i++) {
            std::cout << filenames[i];
            if (i != filenames.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "] ";
        auto start = std::chrono::high_resolution_clock::now();
        function(registry, genSrc, genInclude);
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::high_resolution_clock::now() - start)
                  << "\n";
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    std::filesystem::path xml = argv[1];
    std::filesystem::path genDir = argv[2];
    std::cout << "xml: " << xml.string() << "\n";
    std::cout << "genDir: " << genDir.string() << "\n";
    std::filesystem::path genInclude = genDir / "include";
    std::filesystem::path genSrc = genDir / "src";
    std::filesystem::create_directories(genInclude);
    std::filesystem::create_directories(genSrc);

    XMLDocument doc;
    doc.LoadFile(xml.string().c_str());

    XMLElement &registry = *doc.RootElement();

    writeFiles(
        genSrc, genInclude, registry,
        {{{"Structures.cpp"}, writeStructures}, {{"Objects.hpp", "Objects.cpp"}, writeObjects}});

    writeStructures(registry, genSrc, genInclude);

    // auto functions = parseFunctions(registry);
}
