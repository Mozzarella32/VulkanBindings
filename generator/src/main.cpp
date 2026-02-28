#include <cassert>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <print>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#include <tinyxml2.h>

using namespace tinyxml2;

XMLElement &FirstChildElement(XMLElement &element, const std::string &elementValue) {
    XMLElement *elem = element.FirstChildElement(elementValue.c_str());
    if (!elem) {
        std::cerr << "failed to find: " << elementValue << "\n";
        exit(EXIT_FAILURE);
    }
    return *elem;
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

int main(int argc, char **argv) {
    if (argc != 3) {
        return EXIT_FAILURE;
    }
    std::filesystem::path xml = argv[1];
    std::filesystem::path genDir = argv[2];
    std::println("xml: {}", xml.string());
    std::println("genDir: {}", genDir.string());

    XMLDocument doc;
    doc.LoadFile(xml.string().c_str());

    XMLElement &registry = *doc.RootElement();
    XMLElement &types = FirstChildElement(registry, "types");

    std::unordered_set<std::string> notInternelFeatureNames;
    std::unordered_map<std::string, std::string> typeFeatureMacro;
    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "apitype")) {
            if (HasAttributeValue(feature, "apitype", "internal"))
                return;
        }
        std::string notInternelFeatureName = feature.Attribute("name");
        notInternelFeatureNames.insert(notInternelFeatureName);
        ForEach(feature, "require", [&](XMLElement &require) {
            ForEach(require, "type", [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                std::string typeName = type.Attribute("name");
                assert(typeFeatureMacro.find(typeName) == typeFeatureMacro.end());
                typeFeatureMacro[typeName] = notInternelFeatureName;
            });
        });
    });

    std::unordered_map<std::string, std::string> typeStructureName;
    std::unordered_map<std::string, std::tuple<std::string, std::set<std::string>>>
        typeDependMacros;

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

            if (typeFeatureMacro.contains((name))) {
                auto &[feature, _] = typeDependMacros[name];
                feature = typeFeatureMacro.at(name);
            }
            typeStructureName[name] = std::move(structureType);
        }
    });

    std::unordered_map<std::string, std::string> platformMakros;
    XMLElement &platforms = FirstChildElement(registry, "platforms");
    ForEach(platforms, "platform", [&](XMLElement &platform) {
        if (!HasAttribute(platform, "name"))
            return;
        if (!HasAttribute(platform, "protect"))
            return;
        platformMakros[platform.Attribute("name")] = platform.Attribute("protect");
    });

    std::unordered_map<std::string, std::string> typePlatformMacro;
    std::unordered_set<std::string> extensionNames;
    std::unordered_set<std::string> extensionMacros;
    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        std::string extension_name = extension.Attribute("name");
        extensionNames.insert(extension_name);
        std::string extension_enum_name = "\"" + extension_name + "\"";
        XMLElement &first_require = FirstChildElement(extension, "require");
        std::string extension_name_macro = "";
        ForEachBreak(first_require, "enum", [&](XMLElement &enumEntry) {
            if (!HasAttribute(enumEntry, "value"))
                return false;
            if (!HasAttributeValue(enumEntry, "value", extension_enum_name)) {
                return false;
            }
            if (!HasAttribute(enumEntry, "name"))
                return false;
            extension_name_macro = enumEntry.Attribute("name");
            extensionMacros.insert(enumEntry.Attribute("name"));
            return false;
        });

        ForEach(extension, "require", [&](XMLElement &require) {
            std::string depends;
            if (HasAttribute(require, "depends")) {
                depends = require.Attribute("depends");
                if (!notInternelFeatureNames.contains(depends)) {
                    depends = "";
                }
            }
            ForEach(require, "type", [&](XMLElement &type) {
                if (!HasAttribute(type, "name"))
                    return;
                std::string typeName = type.Attribute("name");
                if (HasAttribute(extension, "platform")) {
                    std::string platform = extension.Attribute("platform");
                    if ((typePlatformMacro.find(typeName) != end(typePlatformMacro)) &&
                        typePlatformMacro.find(typeName)->second != platformMakros.at(platform)) {
                        assert(false);
                    }
                    typePlatformMacro[typeName] = platformMakros.at(platform);
                }
                if (extension_name_macro != "") {
                    auto &[_, extensionMacros] = typeDependMacros[typeName];
                    extensionMacros.insert(extension_name_macro);
                }
                if (depends != "" && notInternelFeatureNames.contains((depends))) {
                    auto &[feature, _] = typeDependMacros[typeName];
                    if (feature == depends)
                        return;
                    assert(feature == "");
                    feature = depends;
                }
            });
        });
    });

    std::filesystem::path structureTypes = genDir / "Structures.hpp";
    std::cout << "Generating: " << structureTypes.filename() << "\n";
    std::ofstream o(structureTypes);
    o << R"--(#pragma once

#define VK_NO_PROTOTYPES
#include <volk.h>

namespace VulkanBindings {

namespace Reflections {
template <typename T> struct StructureType;
} // namespace Reflections

template <typename T>
requires requires () { Reflections::StructureType<T>::t; }
auto Init() {
  T t = {};
  t.sType = Reflections::StructureType<T>::t;
  return t;
}

namespace Reflections {

)--";

    std::tuple<std::string, std::set<std::string>> currentDepends;
    std::string currentPlatform = "";

    int depth = 0;

    auto close_platform_if_open = [&]() {
        if (!currentPlatform.empty()) {
            o << std::string(--depth, '\t') << "#endif\n";
            currentPlatform.clear();
        }
    };
    auto close_depends_if_open = [&]() {
        auto &[currentFeature, currentExtSet] = currentDepends;
        if (currentFeature != "" || !currentExtSet.empty()) {
            o << std::string(--depth, '\t') << "#endif\n";
            currentFeature = "";
            currentExtSet.clear();
        }
    };

    auto make_extension_condition = [](const std::string &feature,
                                       const std::set<std::string> &exts) -> std::string {
        std::string extCond;
        bool firstExt = true;
        for (auto &e : exts) {
            if (!firstExt)
                extCond += " || ";
            extCond += "defined(" + e + ")";
            firstExt = false;
        }
        if (!extCond.empty()) {
            extCond = "(" + extCond + ")";
        }

        std::string featCond;
        if (!feature.empty()) {
            featCond = "defined(" + feature + ")";
        }

        if (!featCond.empty() && !extCond.empty()) {
            return featCond + " && " + extCond;
        } else if (!featCond.empty()) {
            return featCond;
        } else {
            return extCond;
        }
    };

    struct TypeInfo {
        std::string name;
        std::string structureType;
        std::string platform;
        std::tuple<std::string, std::set<std::string>> dependsMacros;

        bool operator<(const TypeInfo &other) const {
            return std::tie(platform, std::get<0>(dependsMacros), std::get<1>(dependsMacros),
                            name) < std::tie(other.platform, std::get<0>(other.dependsMacros),
                                             std::get<1>(other.dependsMacros), other.name);
        }
    };

    auto CreateTypeInfo = [&](std::string name) {
        TypeInfo info;
        info.name = name;
        info.structureType = typeStructureName.at(name);
        if (auto it = typePlatformMacro.find(name); it != typePlatformMacro.end()) {
            info.platform = it->second;
        }
        if (auto it = typeDependMacros.find(name); it != typeDependMacros.end()) {
            info.dependsMacros = it->second;
        }
        return info;
    };

    std::set<TypeInfo> typeInfos;

    for (const auto &[name, _] : typeStructureName) {
        typeInfos.emplace(CreateTypeInfo(name));
    }

    for (const TypeInfo &info : typeInfos) {
        if (info.platform != currentPlatform) {
            close_depends_if_open();
            close_platform_if_open();
            if (!info.platform.empty()) {
                o << std::string(depth++, '\t') << "#ifdef " << info.platform << "\n";
                currentPlatform = info.platform;
            }
        }

        if (info.dependsMacros != currentDepends) {
            close_depends_if_open();

            auto &[thisFeature, thisExtSet] = info.dependsMacros;
            if (thisFeature != "" || !thisExtSet.empty()) {
                std::string cond = make_extension_condition(thisFeature, thisExtSet);
                o << std::string(depth++, '\t') << "#if " << cond << "\n";
                currentDepends = info.dependsMacros;
            }
        }

        o << std::string(depth, '\t') << "template <> struct StructureType<" << info.name << "> { "
          << "static const constexpr VkStructureType t = " << info.structureType << ";"
          << " };\n";
    }

    close_depends_if_open();
    close_platform_if_open();

    o << "} // namespace Refelctions\n" << "} // namespace VulkanBindings\n";
}
