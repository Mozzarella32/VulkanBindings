#include "ConstantInfo.hpp"

#include "EnumInfo.hpp"
#include "ParseXml.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

bool ConstantInfo::operator<(const ConstantInfo &other) const {
    bool isDefine = type == "#define";
    bool otherIsDefine = other.type == "#define";
    return std::tie(isDefine, depends, name, type, value) <
           std::tie(otherIsDefine, other.depends, other.name, other.type, other.value);
}
void ConstantInfo::writeHeader(CppGenerator &gen) const {
    if (type != "#define") {
        gen.doWriteLine("inline const constexpr " + type + " " + name + " = " + value + ";");
        return;
    }
    gen.doWriteLine(type + " " + name + " " + value);
}

const std::unordered_map<std::string, std::string> &getConstantMapping() {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty())
        return mapping;

    const auto &constantInfos = parseConstantInfos(*vkXml, *videoXml);
    for (const auto &constantInfo : constantInfos) {
        mapping[constantInfo.originalName] = constantInfo.name;
    }

    return mapping;
}

const std::unordered_map<std::string, std::string> &getConstantValues() {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty())
        return mapping;

    const auto &constantInfos = parseConstantInfos(*vkXml, *videoXml);
    for (const auto &constantInfo : constantInfos) {
        mapping[constantInfo.name] = constantInfo.value;
    }

    return mapping;
}

static const std::set<ConstantInfo> &parseConstantInfos_impl(XMLElement &registry) {
    static std::unordered_map<XMLElement *, std::set<ConstantInfo>> regConstants;
    auto &constants = regConstants[&registry];
    if (!constants.empty())
        return constants;

    const std::unordered_set<std::string> &vendorTags = parseVendorTags();

    const auto &depnedsEnum = parseObjectDepents(registry, "enum");

    XMLElement &constantEnums = FirstChildElement(registry, "enums");
    assert(HasAttribute(constantEnums, "type"));

    auto handleEnum = [&](XMLElement &enumElem) {
        ConstantInfo info;
        info.originalName = Attribute(enumElem, "name");
        info.name = info.originalName;
        if (depnedsEnum.contains(info.name)) {
            info.depends = depnedsEnum.at(info.name);
        }
        info.value = Attribute(enumElem, "value");
        std::string replace = "VK_";
        for (auto pos = info.value.find(replace); pos != std::string::npos;
             pos = info.value.find(replace, pos)) {
            pos += replace.size();
            info.value.insert(pos, "BINDINGS_");
        }
        replace = "VKSC_";
        for (auto pos = info.value.find(replace); pos != std::string::npos;
             pos = info.value.find(replace, pos)) {
            pos += replace.size();
            info.value.insert(pos, "BINDINGS_");
        }

        if (HasAttribute(enumElem, "type")) {
            info.name = screamingSnakeCaseToPascalCase(info.name, vendorTags);
            if (info.name.starts_with("Vk")) {
                info.name = info.name.substr(2);
            }
            info.type = Attribute(enumElem, "type");
        } else {
            info.name = info.name;
            info.type = "#define";
        }
        constants.insert(std::move(info));
    };

    if (HasAttributeValue(constantEnums, "type", "constants")) {
        ForEach(constantEnums, "enum", [&](XMLElement &enumElem) {
            assert(HasAttribute(enumElem, "type"));
            assert(HasAttribute(enumElem, "value"));
            assert(HasAttribute(enumElem, "name"));
            handleEnum(enumElem);
        });
    }

    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;
        ForEach(feature, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElem) {
                if (HasAttribute(enumElem, "extends"))
                    return;
                if (!HasAttribute(enumElem, "value"))
                    return;
                assert(HasAttribute(enumElem, "name"));

                handleEnum(enumElem);
            });
        });
    });

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElem) {
                if (HasAttribute(enumElem, "extends"))
                    return;
                if (!HasAttribute(enumElem, "value"))
                    return;
                assert(HasAttribute(enumElem, "name"));

                handleEnum(enumElem);
            });
        });
    });

    return constants;
}

const std::set<ConstantInfo> &parseConstantInfos(XMLElement &vkRegistry,
                                                 XMLElement &videoRegistry) {
    static std::unordered_map<XMLElement *,
                              std::unordered_map<XMLElement *, std::set<ConstantInfo>>>
        regInfos;
    auto &infos = regInfos[&vkRegistry][&videoRegistry];
    if (!infos.empty())
        return infos;
    const auto &vk = parseConstantInfos_impl(vkRegistry);
    const auto &video = parseConstantInfos_impl(videoRegistry);

    infos.insert(vk.begin(), vk.end());
    infos.insert(video.begin(), video.end());
    return infos;
}
