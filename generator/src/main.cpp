#include <cassert>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <print>
#include <queue>
#include <set>
#include <string>
#include <string_view>

#include <tinyxml2.h>
#include <tuple>

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

    std::vector<std::tuple<std::string, std::string>> structureAndStructureType;

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
            structureAndStructureType.push_back(
                std::make_tuple(std::move(name), std::move(structureType)));
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
    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        if (!HasAttribute(extension, "platform"))
            return;
        XMLElement &require = FirstChildElement(extension, "require");
        ForEach(require, "type", [&](XMLElement &type) {
            if (!HasAttribute(type, "name"))
                return;
            assert(typePlatformMacro.find(type.Attribute("name")) == end(typePlatformMacro));
            typePlatformMacro[type.Attribute("name")] =
                platformMakros.at(std::string(extension.Attribute("platform")));
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
requires requires () { typename Reflections::StructureType<T>::t; }
auto Init() {
  T t = {};
  t.sType = Reflections::StructureType<T>::t;
  return t;
}

namespace Reflections {

)--";
    std::string currentPlatform = "";
    for (const auto &[structure, structureType] : structureAndStructureType) {
        auto it = typePlatformMacro.find(structure);
        if (it != typePlatformMacro.end()) {
            if (currentPlatform != it->second) {
                if (currentPlatform != "") {
                    o << "#endif\n";
                }
                o << "#ifdef " << it->second << "\n";
                currentPlatform = it->second;
            }
        } else {
            if (currentPlatform != "") {
                o << "#endif\n";
                currentPlatform = "";
            }
        }
        o << "template <> struct StructureType<" << structure << "> { "
          << "static const constexpr VkStructureType t = " << structureType << ";"
          << " };\n";
    }
    if (currentPlatform != "") {
        o << "#endif\n";
    }

    o << "} // namespace Refelctions\n" << "} // namespace VulkanBindings\n";
}
