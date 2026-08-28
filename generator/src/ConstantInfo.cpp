#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"
#include "XmlUtils.hpp"

#include <cassert>
#include <cctype>
#include <format>
#include <set>
#include <string>
#include <tinyxml2.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace tinyxml2;

auto ConstantInfo::operator<(const ConstantInfo &other) const -> bool {
    bool isDefine = type == "#define";
    bool otherIsDefine = other.type == "#define";
    return std::tie(isDefine, depends, name, type, value) <
           std::tie(otherIsDefine, other.depends, other.name, other.type, other.value);
}

[[nodiscard]] auto ConstantInfo::getDepends() const -> const Depends & { return depends; }

void ConstantInfo::writeHeader(CppGenerator &gen) const {
    if (type != "#define") {
        gen.doWriteLine(std::format("inline constinit const {} {} = {};", type, name, value));
        return;
    }
    gen.doWriteLine(std::format("{} {}  {}", type, name, value));
}

auto ConstantInfo::getConstantMapping(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty()) {
        return mapping;
    }

    const auto &constantInfos = parseConstantInfos(registry);
    for (const auto &constantInfo : constantInfos) {
        mapping[constantInfo.originalName] = constantInfo.name;
    }

    return mapping;
}

auto ConstantInfo::getConstantValues(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty()) {
        return mapping;
    }

    const auto &constantInfos = parseConstantInfos(registry);
    for (const auto &constantInfo : constantInfos) {
        mapping[constantInfo.name] = constantInfo.value;
    }

    return mapping;
}

auto ConstantInfo::parseConstantInfo(Registry registry, XMLElement &element) -> ConstantInfo {
    const std::vector<std::string> &vendorTags = parseVendorTags(registry);
    const auto &depnedsEnum = parseObjectDepents(registry, "enum");

    ConstantInfo info;
    info.originalName = Attribute(element, "name");
    info.name = info.originalName;
    if (depnedsEnum.contains(info.name)) {
        info.depends = depnedsEnum.at(info.name);
    }
    info.value = Attribute(element, "value");
    info.name = screamingSnakeCaseToPascalCase(info.name, vendorTags);
    if (HasAttribute(element, "type")) {
        if (info.name.starts_with("Vk")) {
            info.name = info.name.substr(2);
        }
        info.type = Attribute(element, "type");
        if (info.type == "float" && info.value.back() == 'f') {
            info.value.back() = 'F';
        }
        return info;
    }
    info.name = info.name;
    if (info.name.starts_with("Vk")) {
        info.name = info.name.substr(2);
    }
    for (const auto &vendorTag : vendorTags) {
        if (info.name.starts_with(vendorTag)) {
            info.name = info.name.substr(vendorTag.size()) + vendorTag;
        }
    }
    if (std::isdigit(info.name.at(0)) != 0) {
        info.name = "v" + info.name;
    }
    if (info.value.starts_with('\"')) {
        info.type = "std::string_view";
    } else {
        info.type = "std::uint32_t";
    }
    if (info.value.starts_with("VK_")) {
        info.value.insert(3, "BINDINGS_");
    }

    return info;
};

auto ConstantInfo::parseConstantInfosActive(Registry registry) -> const std::set<ConstantInfo> & {
    static std::unordered_map<XMLElement *, std::set<ConstantInfo>> regConstants;
    auto &constants = regConstants[&registry.getActive()];
    if (!constants.empty()) {
        return constants;
    }

    XMLElement &constantEnums = FirstChildElement(registry.getActive(), "enums");
    assert(HasAttribute(constantEnums, "type"));

    if (HasAttributeValue(constantEnums, AttributeName{"type"}, AttributeValue{"constants"})) {
        ForEach(constantEnums, "enum", [&](XMLElement &enumElem) -> void {
            assert(HasAttribute(enumElem, "type"));
            assert(HasAttribute(enumElem, "value"));
            assert(HasAttribute(enumElem, "name"));
            constants.insert(parseConstantInfo(registry, enumElem));
        });
    }

    ForEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;
        ForEach(feature, "require", [&](XMLElement &require) -> void {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElem) -> void {
                if (HasAttribute(enumElem, "extends"))
                    return;
                if (!HasAttribute(enumElem, "value"))
                    return;
                assert(HasAttribute(enumElem, "name"));

                constants.insert(parseConstantInfo(registry, enumElem));
            });
        });
    });

    XMLElement &extensions = FirstChildElement(registry.getActive(), "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        ForEach(extension, "require", [&](XMLElement &require) -> void {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElem) -> void {
                if (HasAttribute(enumElem, "extends"))
                    return;
                if (!HasAttribute(enumElem, "value"))
                    return;
                assert(HasAttribute(enumElem, "name"));

                constants.insert(parseConstantInfo(registry, enumElem));
            });
        });
    });

    return constants;
}

auto ConstantInfo::parseConstantInfos(Registry registry) -> const std::set<ConstantInfo> & {
    static std::unordered_map<XMLElement *,
                              std::unordered_map<XMLElement *, std::set<ConstantInfo>>>
        regInfos;
    auto &infos = regInfos[&registry.getVk()][&registry.getVideo()];
    if (!infos.empty()) {
        return infos;
    }
    const auto &vkInfos = parseConstantInfosActive(registry.setVkActive());
    const auto &videoInfos = parseConstantInfosActive(registry.setVideoActive());

    infos.insert(vkInfos.begin(), vkInfos.end());
    infos.insert(videoInfos.begin(), videoInfos.end());
    return infos;
}
