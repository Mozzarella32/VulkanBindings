#include "BaseTypeInfo.hpp"
#include "ParseXml.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

bool BaseTypeInfo::operator<(const BaseTypeInfo &other) const {
    return std::tie(depends, name) < std::tie(other.depends, other.name);
}

void BaseTypeInfo::write(CppGenerator &gen) const { gen.doCode(code); }

extern const std::set<BaseTypeInfo> &
parseBaseTypeInfo([[maybe_unused]] tinyxml2::XMLElement &registry) {
    static std::set<BaseTypeInfo> infos;

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");
    const std::unordered_map<std::string, Depends> &objectDepends =
        parseObjectDepents(registry, "type");

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "basetype"))
            return;
        if (!checkApi(type))
            return;
        assert(type.FirstChildElement("name") != nullptr);
        BaseTypeInfo info;

        XMLElement *name = type.FirstChildElement("name");
        std::string rawName = name->GetText();
        std::string strippedName = (rawName.rfind("Vk", 0) == 0) ? rawName.substr(2) : rawName;
        info.name = rawName;

        if (objectsDisabled.contains(info.name))
            return;

        XMLNode *node = type.FirstChild();
        while (node) {
            if (XMLText *txt = node->ToText()) {
                const char *val = txt->Value();
                if (val && *val) {
                    info.code += val;
                }
            } else if (XMLElement *el = node->ToElement()) {
                const char *t = (el == name) ? strippedName.c_str() : el->GetText();
                if (t && *t) {
                    if (!info.code.empty() &&
                        !std::isspace(static_cast<unsigned char>(info.code.back())))
                        info.code.push_back(' ');
                    info.code += t;
                }
            }
            node = node->NextSibling();
        }
        if (auto it = objectDepends.find(info.name); it != objectDepends.end()) {
            info.depends = it->second;
        }
        infos.insert(std::move(info));
    });

    return infos;
}
