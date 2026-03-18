#include "EnumInfo.hpp"
#include "ParseXml.hpp"
#include "Writing.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace tinyxml2;

bool EnumElementInfo::operator<(const EnumElementInfo &other) const { return value < other.value; }

void EnumElementInfo::writeAssert(CppGenerator &gen, const EnumElementInfo &eei,
                                  const std::string &enumName, bool size64) {
    std::string type = size64 ? "uint64_t" : "int32_t";
    gen.doWriteLine("static_assert(static_cast<" + type + ">(VkBindings::" + enumName +
                    "::" + eei.name + ") == " + eei.originalName + ");");
}

void EnumElementInfo::writeHeader(CppGenerator &gen, const EnumElementInfo &eei, int longestName) {
    std::stringstream s;
    s << std::left << std::setw(longestName) << eei.name << " = " << eei.value << ",";
    if (!eei.comment.empty())
        s << " // " << eei.comment;
    gen.doWriteLine(s);
}

bool EnumInfo::operator<(const EnumInfo &other) const {
    return std::tie(depends, name, vendor) < std::tie(other.depends, other.name, other.vendor);
}

void EnumInfo::writeHeader(CppGenerator &gen, const EnumInfo &ei) {
    const std::string bitwidth = ei.bitwidth == Bitwidth::BW32 ? "32" : "64";
    const std::string type = ei.type == Type::Enum ? "Enum" : "Bitmask";
    const std::string baseType = ei.bitwidth == Bitwidth::BW32 ? "int32_t" : "uint64_t";

    std::string flagsUsing;
    if (ei.type == Type::Bitmask) {
        std::string flagsName = ei.name + ei.vendor;
        static const std::string FlagBits = "FlagBits";
        auto it = flagsName.find(FlagBits);
        if (it != std::string::npos) {
            flagsName.erase(it, FlagBits.size());
            flagsName.insert(it, "Flags");
        }
        flagsUsing = "using " + flagsName + " = impl_Enum::Flags<" + ei.name + ei.vendor + ">;";
    }

    if (ei.elements.empty()) {
        gen.doWriteLine("enum class " + ei.name + ei.vendor + " : " + baseType + " {};");
        if (ei.type == Type::Bitmask) {
            gen.doWriteLine(flagsUsing);
        }
        return;
    }
    gen.doLineBeginScope("enum class " + ei.name + ei.vendor + " : " + baseType);
    int longestName = 0;
    for (const auto &element : ei.elements) {
        longestName = std::max(longestName, static_cast<int>(element.name.size()));
    }
    writeDepends(gen, ei.elements, std::bind_back(EnumElementInfo::writeHeader, longestName));
    gen.endScope(true);
    if (ei.type == Type::Bitmask) {
        gen.doWriteLine(flagsUsing);
    }
}

void EnumInfo::writeAssert(CppGenerator &gen, const EnumInfo &ei) {
    writeDepends(gen, ei.elements,
                 std::bind_back(EnumElementInfo::writeAssert, ei.name + ei.vendor,
                                ei.bitwidth == Bitwidth::BW64));
}

// According to
// https://registry.khronos.org/vulkan/specs/latest/styleguide.html#extensions-assigning-token-values
static int64_t enumElementNumber(int64_t extensionNumber, int64_t offset, bool dirNegative) {
    static const constinit int64_t baseValue = 1000000000;
    static const constinit int64_t rangeSize = 1000;
    if (!dirNegative) {
        return baseValue + (extensionNumber - 1) * rangeSize + offset;
    } else {
        return -(baseValue + (extensionNumber - 1) * rangeSize + offset);
    }
}
static uint64_t enumElementUNumber(uint64_t extensionNumber, uint64_t offset, bool dirNegative) {
    static const constinit uint64_t baseValue = 1000000000;
    static const constinit uint64_t rangeSize = 1000;
    if (!dirNegative) {
        return baseValue + (extensionNumber - 1) * rangeSize + offset;
    } else {
        return -(baseValue + (extensionNumber - 1) * rangeSize + offset);
    }
}

static std::string enumElementValue(int64_t val, EnumInfo::Bitwidth bitwidth, EnumInfo::Type type) {
    const int hexDigits = (bitwidth == EnumInfo::Bitwidth::BW32) ? 8 : 16;

    std::stringstream s;
    if (val < 0) {
        s << "-";
    }
    if (type == EnumInfo::Type::Enum) {
        assert(bitwidth == EnumInfo::Bitwidth::BW32);
        s << std::right << std::dec << std::setw(10) << std::setfill(' ') << std::llabs(val);
        return s.str();
    }

    s << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0')
      << std::llabs(val);
    return s.str();
}

static std::string enumElementUValue(uint64_t val, EnumInfo::Bitwidth bitwidth,
                                     EnumInfo::Type type) {
    const int hexDigits = (bitwidth == EnumInfo::Bitwidth::BW32) ? 8 : 16;

    std::stringstream s;
    if (type == EnumInfo::Type::Enum) {
        assert(bitwidth == EnumInfo::Bitwidth::BW32);
        s << std::right << std::dec << std::setw(10) << std::setfill(' ');
        return s.str();
    }

    s << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0') << val;
    return s.str();
}

const std::unordered_map<std::string, std::string> &getEnumElementMapping(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty())
        return mapping;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &enumInfo : enumInfos) {
        for (const auto &element : enumInfo.elements) {
            mapping[element.originalName] = element.name;
        }
    }

    return mapping;
}

const std::unordered_map<std::string, std::string> &parseEnumZeroElement(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> zeroElements;
    if (!zeroElements.empty())
        return zeroElements;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &enumInfo : enumInfos) {
        std::string zeroValue = enumInfo.type == EnumInfo::Type::Enum
                                    ? enumElementValue(0, enumInfo.bitwidth, enumInfo.type)
                                    : enumElementUValue(0, enumInfo.bitwidth, enumInfo.type);
        if (enumInfo.elements.empty())
            continue;
        for (const auto &element : enumInfo.elements) {
            if (element.value == zeroValue) {
                zeroElements[enumInfo.originalName] =
                    enumInfo.name + enumInfo.vendor + "::" + element.name;
            }
        }
        if (!zeroElements.contains(enumInfo.originalName)) {
            zeroElements[enumInfo.originalName] =
                "static_cast<" + enumInfo.name + enumInfo.vendor + ">(0)";
        }
    }

    return zeroElements;
}

const std::unordered_set<std::string> &parseAllEnums(XMLElement &registry) {
    static std::unordered_set<std::string> allEnums;
    if (!allEnums.empty())
        return allEnums;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &enumInfo : enumInfos) {
        allEnums.insert(enumInfo.name + enumInfo.vendor);
    }

    return allEnums;
}

const std::unordered_set<std::string> &parseAllEnumFlags(XMLElement &registry) {
    static std::unordered_set<std::string> allEnumFlags;
    if (!allEnumFlags.empty())
        return allEnumFlags;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &ei : enumInfos) {
        if (ei.type != EnumInfo::Type::Bitmask)
            continue;
        std::string flagsName = ei.name + ei.vendor;
        static const std::string FlagBits = "FlagBits";
        auto it = flagsName.find(FlagBits);
        if (it != std::string::npos) {
            flagsName.erase(it, FlagBits.size());
            flagsName.insert(it, "Flags");
        }
        allEnumFlags.insert(flagsName);
    }

    return allEnumFlags;
}

const std::unordered_map<std::string, std::string> &getEnumSizeTypes(XMLElement &registry) {
    static std::unordered_map<std::string, std::string> enumSizeTypes;
    if (!enumSizeTypes.empty())
        return enumSizeTypes;

    const auto &enumInfos = parseEnumInfos(registry);

    for (const auto &enumInfo : enumInfos) {
        enumSizeTypes[enumInfo.name + enumInfo.vendor] =
            enumInfo.bitwidth == EnumInfo::Bitwidth::BW32 ? "int32_t" : "uint64_t";
    }

    return enumSizeTypes;
}

const std::set<EnumInfo> &parseEnumInfos(XMLElement &registry) {
    static std::set<EnumInfo> enumInfos;
    if (!enumInfos.empty())
        return enumInfos;

    const std::unordered_set<std::string> &vendorTags = parseVendorTags(registry);
    std::unordered_map<std::string, EnumInfo> enumInfosMap;

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");

    auto handleEnum = [&](XMLElement &element, const std::string &enumName,
                          int64_t extensionNumber = 0) {
        assert(HasAttribute(element, "name"));
        if (HasAttribute(element, "alias"))
            return;
        auto itEnumInfo = enumInfosMap.end();
        auto enumInfoMapKey = enumName;
        if (enumInfoMapKey == "") {
            if (!HasAttribute(element, "extends")) // some kind of version makro or sth
                return;
            enumInfoMapKey = Attribute(element, "extends");
        }
        EnumInfo &enumInfo = enumInfosMap.at(enumInfoMapKey);

        EnumElementInfo elem;
        elem.originalName = Attribute(element, "name");
        elem.name = screamingSnakeCaseToPascalCase(elem.originalName.substr(2), vendorTags);
        std::string enumNoFlagsName = enumInfo.name;
        std::string Flags = "Flags";
        if (auto it = enumNoFlagsName.find(Flags); it != std::string::npos) {
            enumNoFlagsName.erase(it, Flags.size());
        }
        if (elem.name.starts_with(enumNoFlagsName)) {
            elem.name = elem.name.substr(enumNoFlagsName.size());
        }
        if (enumInfo.vendor != "" && elem.name.ends_with(enumInfo.vendor)) {
            elem.name = elem.name.substr(0, elem.name.size() - enumInfo.vendor.size());
        }
        if (enumInfo.type == EnumInfo::Type::Bitmask && elem.name.ends_with("Bit")) {
            elem.name = elem.name.substr(0, elem.name.size() - 3);
        }
        elem.name.insert(0, "e");
        if (HasAttribute(element, "value")) {
            std::string value = Attribute(element, "value");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value = enumElementValue(std::stoll(value, nullptr, 0), enumInfo.bitwidth,
                                              enumInfo.type);
            } else {
                elem.value = enumElementUValue(std::stoull(value, nullptr, 0), enumInfo.bitwidth,
                                               enumInfo.type);
            }
        } else if (HasAttribute(element, "bitpos")) {
            std::string bitpos = Attribute(element, "bitpos");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value =
                    enumElementValue(1LL << std::stoi(bitpos), enumInfo.bitwidth, enumInfo.type);
            } else {
                elem.value =
                    enumElementUValue(1ULL << std::stoi(bitpos), enumInfo.bitwidth, enumInfo.type);
            }
        } else {
            assert(HasAttribute(element, "offset"));
            int64_t offset = std::stoll(Attribute(element, "offset"));
            if (HasAttribute(element, "extnumber")) {
                extensionNumber = std::stoi(Attribute(element, "extnumber"));
            }
            bool dirNegative = HasAttribute(element, "dir");
            if (dirNegative)
                assert(HasAttributeValue(element, "dir", "-"));
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value =
                    enumElementValue(enumElementNumber(extensionNumber, offset, dirNegative),
                                     enumInfo.bitwidth, enumInfo.type);
            } else {
                elem.value = enumElementUValue(
                    enumElementUNumber(static_cast<uint64_t>(extensionNumber),
                                       static_cast<uint64_t>(offset), dirNegative),
                    enumInfo.bitwidth, enumInfo.type);
            }
        }
        if (HasAttribute(element, "comment")) {
            elem.comment = Attribute(element, "comment");
        }
        if (itEnumInfo != enumInfosMap.end()) {
            itEnumInfo->second.elements.insert(std::move(elem));
        } else {
            enumInfo.elements.insert(std::move(elem));
        }
    };

    ForEach(registry, "enums", [&](XMLElement &enums) {
        EnumInfo enumInfo;
        assert(HasAttribute(enums, "name"));
        enumInfo.originalName = Attribute(enums, "name");
        if (objectsDisabled.contains(enumInfo.originalName))
            return;
        enumInfo.name = enumInfo.originalName.substr(2);
        assert(HasAttribute(enums, "type"));
        std::string type = Attribute(enums, "type");
        if (type == "constants")
            return;
        if (type == "enum") {
            enumInfo.type = EnumInfo::Type::Enum;
        } else {
            assert(type == "bitmask");
            enumInfo.type = EnumInfo::Type::Bitmask;
        }
        if (HasAttribute(enums, "bitwidth")) {
            assert(Attribute(enums, "bitwidth") == "64");
            enumInfo.bitwidth = EnumInfo::Bitwidth::BW64;
        } else {
            enumInfo.bitwidth = EnumInfo::Bitwidth::BW32;
        }
        for (const auto &vendorTag : vendorTags) {
            if (enumInfo.name.ends_with(vendorTag)) {
                enumInfo.vendor = vendorTag;
                enumInfo.name = enumInfo.name.substr(0, enumInfo.name.size() - vendorTag.size());
            }
        }
        std::string originalName = enumInfo.originalName;
        enumInfosMap[enumInfo.originalName] = std::move(enumInfo);
        ForEach(enums, "enum", std::bind_back(handleEnum, originalName));
    });

    ForEach(registry, "feature", [&](XMLElement &feature) {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;
        ForEach(feature, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElement) { handleEnum(enumElement, ""); });
        });
    });

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        int64_t extensionNumber = std::stoll(Attribute(extension, "number"));
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum",
                    [&](XMLElement &enumElement) { handleEnum(enumElement, "", extensionNumber); });
        });
    });

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (!HasAttributeValue(type, "category", "bitmask"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        if (HasAttribute(type, "bitvalues"))
            return;
        // if (HasAttribute(type, "requires"))
        // return;
        std::string typeType = FirstChildElement(type, "type").GetText();
        std::string typeName = FirstChildElement(type, "name").GetText();
        static std::string Flags = "Flags";
        static std::string FlagBits = "FlagBits";
        if (auto it = typeName.find(Flags); it != std::string::npos) {
            typeName.erase(it, Flags.length());
            typeName.insert(it, FlagBits);
        }
        if (enumInfosMap.contains(typeName)) {
            return;
        }
        EnumInfo info;
        if (typeType == "VkFlags") {
            info.bitwidth = EnumInfo::Bitwidth::BW32;
        } else {
            assert(typeType == "VkFlags64");
            info.bitwidth = EnumInfo::Bitwidth::BW64;
        }
        info.type = EnumInfo::Type::Bitmask;
        info.originalName = typeName;
        info.name = info.originalName.substr(2);
        for (const auto &vendorTag : vendorTags) {
            if (info.name.ends_with(vendorTag)) {
                info.vendor = vendorTag;
                info.name = info.name.substr(0, info.name.size() - vendorTag.size());
            }
        }
        enumInfosMap[info.originalName] = std::move(info);
    });

    for (const auto &[_, enumInfo] : enumInfosMap) {
        enumInfos.insert(enumInfo);
    }
    return enumInfos;
}

const std::set<EnumInfo> &parseEnumInfosDepends(XMLElement &registry) {
    static std::set<EnumInfo> enumInfos;
    if (!enumInfos.empty())
        return enumInfos;
    const auto &typeDepends = parseObjectDepents(registry, "type");
    const auto &enumDepends = parseObjectDepents(registry, "enum");

    auto parsed = parseEnumInfos(registry);

    std::set<EnumInfo> tmp;
    std::ranges::transform(parsed, std::inserter(tmp, tmp.end()), [&](EnumInfo const &info) {
        EnumInfo copy = info;

        if (auto it = typeDepends.find(copy.originalName); it != typeDepends.end()) {
            copy.depends = it->second;
        }

        std::set<EnumElementInfo> newElems;
        std::ranges::transform(
            copy.elements, std::inserter(newElems, newElems.end()), [&](EnumElementInfo const &el) {
                EnumElementInfo elcopy = el;
                if (auto it2 = enumDepends.find(elcopy.originalName); it2 != enumDepends.end()) {
                    elcopy.depends = it2->second;
                }
                return elcopy;
            });
        copy.elements = std::move(newElems);
        return copy;
    });

    enumInfos = std::move(tmp);
    return enumInfos;
}
