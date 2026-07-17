#include "ConstantInfo.hpp"

#include "ParseXml.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

using namespace tinyxml2;

auto ConstantInfo::operator<(const ConstantInfo &other) const -> bool {
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

auto getConstantMapping() -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty())
        return mapping;

    const auto &constantInfos = parseConstantInfos(*vkXml, *videoXml);
    for (const auto &constantInfo : constantInfos) {
        mapping[constantInfo.originalName] = constantInfo.name;
    }

    return mapping;
}

auto getConstantValues() -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty())
        return mapping;

    const auto &constantInfos = parseConstantInfos(*vkXml, *videoXml);
    for (const auto &constantInfo : constantInfos) {
        mapping[constantInfo.name] = constantInfo.value;
    }

    return mapping;
}

static auto parseConstantInfos_impl(XMLElement &registry) -> const std::set<ConstantInfo> & {
    static std::unordered_map<XMLElement *, std::set<ConstantInfo>> regConstants;
    auto &constants = regConstants[&registry];
    if (!constants.empty())
        return constants;

    const std::unordered_set<std::string> &vendorTags = parseVendorTags();

    const auto &depnedsEnum = parseObjectDepents(registry, "enum");

    XMLElement &constantEnums = FirstChildElement(registry, "enums");
    assert(HasAttribute(constantEnums, "type"));

    auto handleEnum = [&](XMLElement &enumElem) -> void {
        ConstantInfo info;
        info.originalName = Attribute(enumElem, "name");
        info.name = info.originalName;
        if (depnedsEnum.contains(info.name)) {
            info.depends = depnedsEnum.at(info.name);
        }
        info.value = Attribute(enumElem, "value");
        // std::string replace = "VK_";
        // for (auto pos = info.value.find(replace); pos != std::string::npos;
        //      pos = info.value.find(replace, pos)) {
        //     pos += replace.size();
        //     info.value.insert(pos, "BINDINGS_");
        // }
        // replace = "VKSC_";
        // for (auto pos = info.value.find(replace); pos != std::string::npos;
        //      pos = info.value.find(replace, pos)) {
        //     pos += replace.size();
        //     info.value.insert(pos, "BINDINGS_");
        // }

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
        std::string replace = "VK_";
        for (auto pos = info.name.find(replace); pos != std::string::npos;
             pos = info.name.find(replace, pos)) {
            pos += replace.size();
            info.name.insert(pos, "BINDINGS_");
        }
        replace = "VKSC_";
        for (auto pos = info.name.find(replace); pos != std::string::npos;
             pos = info.name.find(replace, pos)) {
            pos += replace.size();
            info.name.insert(pos, "BINDINGS_");
        }
        constants.insert(std::move(info));
    };

    if (HasAttributeValue(constantEnums, "type", "constants")) {
        ForEach(constantEnums, "enum", [&](XMLElement &enumElem) -> void {
            assert(HasAttribute(enumElem, "type"));
            assert(HasAttribute(enumElem, "value"));
            assert(HasAttribute(enumElem, "name"));
            handleEnum(enumElem);
        });
    }

    ForEach(registry, "feature", [&](XMLElement &feature) -> void {
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

                handleEnum(enumElem);
            });
        });
    });

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        std::string extension_name = Attribute(extension, "name");
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

                handleEnum(enumElem);
            });
        });
    });

    return constants;
}

auto parseConstantInfos(XMLElement &vkRegistry, XMLElement &videoRegistry)
    -> const std::set<ConstantInfo> & {
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
