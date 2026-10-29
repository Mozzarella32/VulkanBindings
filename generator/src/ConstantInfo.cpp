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
    info.originalName = attribute(element, "name");
    info.name = info.originalName;
    if (depnedsEnum.contains(info.name)) {
        info.depends = depnedsEnum.at(info.name);
    }
    info.value = attribute(element, "value");
    info.name = screamingSnakeCaseToPascalCase(info.name, vendorTags);
    if (hasAttribute(element, "type")) {
        if (info.name.starts_with("Vk")) {
            info.name = info.name.substr(2);
        }
        info.type = attribute(element, "type");
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

    XMLElement &constantEnums = firstChildElement(registry.getActive(), "enums");
    assert(hasAttribute(constantEnums, "type"));

    if (hasAttributeValue(constantEnums, AttributeName{"type"}, AttributeValue{"constants"})) {
        forEach(constantEnums, "enum", [&](XMLElement &enumElem) -> void {
            assert(hasAttribute(enumElem, "type"));
            assert(hasAttribute(enumElem, "value"));
            assert(hasAttribute(enumElem, "name"));
            constants.insert(parseConstantInfo(registry, enumElem));
        });
    }

    forEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
        if (!hasAttribute(feature, "name"))
            return;
        if (hasAttribute(feature, "api") && !splitCSL(attribute(feature, "api")).contains("vulkan"))
            return;
        forEach(feature, "require", [&](XMLElement &require) -> void {
            if (hasAttribute(require, "api") &&
                !splitCSL(attribute(require, "api")).contains("vulkan"))
                return;
            forEach(require, "enum", [&](XMLElement &enumElem) -> void {
                if (hasAttribute(enumElem, "extends"))
                    return;
                if (!hasAttribute(enumElem, "value"))
                    return;
                assert(hasAttribute(enumElem, "name"));

                constants.insert(parseConstantInfo(registry, enumElem));
            });
        });
    });

    XMLElement &extensions = firstChildElement(registry.getActive(), "extensions");
    forEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(hasAttribute(extension, "name"));
        if (hasAttribute(extension, "supported") &&
            !splitCSL(attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(hasAttribute(extension, "number"));
        forEach(extension, "require", [&](XMLElement &require) -> void {
            if (hasAttribute(require, "api") &&
                !splitCSL(attribute(require, "api")).contains("vulkan"))
                return;
            forEach(require, "enum", [&](XMLElement &enumElem) -> void {
                if (hasAttribute(enumElem, "extends"))
                    return;
                if (!hasAttribute(enumElem, "value"))
                    return;
                assert(hasAttribute(enumElem, "name"));

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
