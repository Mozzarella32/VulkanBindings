#include "ConstantInfo.hpp"

#include "ParseXml.hpp"
#include "XmlUtils.hpp"

using namespace tinyxml2;

bool ConstantInfo::operator<(const ConstantInfo &other) const {
    return std::tie(depends, name, type, value) <
           std::tie(other.depends, other.name, other.type, other.value);
}
void ConstantInfo::writeHeader(CppGenerator &gen, const ConstantInfo &info) {
    gen.doWriteLine("extern const constinit " + info.type + " " + info.name + ";");
}

void ConstantInfo::writeImpl(CppGenerator &gen, const ConstantInfo &info) {
    gen.doWriteLine("const constinit " + info.type + " " + info.name + " = " + info.value + ";");
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
        info.name = Attribute(enumElem, "name");
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
