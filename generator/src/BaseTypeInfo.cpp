#include "BaseTypeInfo.hpp"
#include "ParseXml.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"
#include <algorithm>
#include <unordered_set>

using namespace tinyxml2;

auto BaseTypeInfo::operator<(const BaseTypeInfo &other) const -> bool {
    return std::tie(depends, name) < std::tie(other.depends, other.name);
}

void BaseTypeInfo::write(CppGenerator &gen) const { gen.doCode(code); }

auto getBaseTypeMapping(XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty())
        return mapping;

    const auto &baseTypeInfos = parseBaseTypeInfo(registry);
    for (const auto &baseTypeInfo : baseTypeInfos) {
        mapping[baseTypeInfo.originalName] = baseTypeInfo.name;
    }

    return mapping;
}

auto getIntTypedefs(XMLElement &registry) -> const std::unordered_set<std::string> {
    static std::unordered_set<std::string> types;
    const auto &baseTypeInfos = parseBaseTypeInfo(registry);
    std::array intTypes = {"uint32_t", "uint64_t"};
    for (const auto &info : baseTypeInfos) {
        if (std::ranges::any_of(intTypes, [&](const std::string &intType) -> bool {
                return info.code.contains(intType);
            })) {
            types.insert(info.name);
        }
    }
    return types;
}

auto parseBaseTypeInfo(XMLElement &registry) -> const std::set<BaseTypeInfo> & {
    static std::set<BaseTypeInfo> infos;
    if (!infos.empty())
        return infos;

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");
    const std::unordered_map<std::string, Depends> &objectDepends =
        parseObjectDepents(registry, "type");

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, "category", "basetype"))
            return;
        if (!checkApi(type))
            return;
        assert(type.FirstChildElement("name") != nullptr);
        BaseTypeInfo info;

        XMLElement *name = type.FirstChildElement("name");
        std::string rawName = name->GetText();
        info.originalName = rawName;
        info.name = info.originalName;
        if (info.name.starts_with("Vk")) {
            info.name = info.name.substr(2);
        }

        if (objectsDisabled.contains(info.originalName))
            return;

        XMLNode *node = type.FirstChild();
        while (node) {
            if (XMLText *txt = node->ToText()) {
                const char *val = txt->Value();
                if (val && *val) {
                    info.code += val;
                }
            } else if (XMLElement *el = node->ToElement()) {
                const char *t = (el == name) ? info.name.c_str() : el->GetText();
                if (t && *t) {
                    if (!info.code.empty() &&
                        !std::isspace(static_cast<unsigned char>(info.code.back())))
                        info.code.push_back(' ');
                    info.code += t;
                }
            }
            node = node->NextSibling();
        }
        if (auto it = objectDepends.find(info.originalName); it != objectDepends.end()) {
            info.depends = it->second;
        }
        infos.insert(std::move(info));
    });

    return infos;
}
