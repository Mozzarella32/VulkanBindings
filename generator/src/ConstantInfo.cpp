#include "ConstantInfo.hpp"

#include "ParseXml.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"
#include <unordered_map>

using namespace tinyxml2;

bool ConstantInfo::operator<(const ConstantInfo &other) const {
    return std::tie(depends, name, type, value) <
           std::tie(other.depends, other.name, other.type, other.value);
}
void ConstantInfo::writeHeader(CppGenerator &gen, const ConstantInfo &info) {
    gen.doWriteLine("inline const constexpr " + info.type + " " + info.name + " = " + info.value +
                    ";");
}

const std::unordered_map<std::string, std::string> &getConstantMapping(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty())
        return mapping;

    const auto &constantInfos = parseConstantInfos(registry);
    for (const auto &constantInfo : constantInfos) {
        mapping[constantInfo.originalName] = constantInfo.name;
    }

    return mapping;
}

const std::set<ConstantInfo> &parseConstantInfos(XMLElement &registry) {
    static std::set<ConstantInfo> constants;
    if (!constants.empty())
        return constants;

    const std::unordered_set<std::string> &vendorTags = parseVendorTags(registry);

    const auto &depnedsEnum = parseObjectDepents(registry, "enum");

    XMLElement &constantEnums = FirstChildElement(registry, "enums");
    assert(HasAttribute(constantEnums, "type"));
    assert(Attribute(constantEnums, "type") == "constants");

    ForEach(constantEnums, "enum", [&](XMLElement &enumElem) {
        assert(HasAttribute(enumElem, "type"));
        assert(HasAttribute(enumElem, "value"));
        assert(HasAttribute(enumElem, "name"));

        ConstantInfo info;
        info.originalName = Attribute(enumElem, "name");
        info.name = info.originalName;
        if (depnedsEnum.contains(info.name)) {
            info.depends = depnedsEnum.at(info.name);
        }
        info.name = screamingSnakeCaseToPascalCase(info.name, vendorTags).substr(2);
        info.value = Attribute(enumElem, "value");
        info.type = Attribute(enumElem, "type");
        constants.insert(std::move(info));
    });
    return constants;
}
