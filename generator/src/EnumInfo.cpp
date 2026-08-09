#include "EnumInfo.hpp"
#include "CppGenerator.hpp"
#include "ParseXml.hpp"
#include "Writing.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace tinyxml2;

auto EnumElementInfo::operator<(const EnumElementInfo &other) const -> bool {
    bool isAll = name == "eAllBits";
    bool otherIsAll = other.name == "eAllBits";
    return std::tie(value, isAll) < std::tie(other.value, otherIsAll);
}

void EnumElementInfo::writeAssert(CppGenerator &gen, const EnumInfo &ei) const {
    std::string type = ei.bitwidth == EnumInfo::Bitwidth::BW64 ? "uint64_t" : "int32_t";
    if (name == "eAllBits") {
        for (const auto &elem : ei.elements) {
            if (elem.name == "eAllBits")
                continue;
            if (elem.depends.platform != "" || elem.depends.guard != "") {
                gen.doWriteLine("// eAllBits is not tested because " + elem.name + " has " +
                                elem.depends.platform + elem.depends.guard);
                return;
            }
        }
        std::stringstream line;
        line << "static_assert(static_cast<" << type << ">(VkBindings::" << ei.name << ei.vendor
             << "::" << name << ") == (";

        bool first = true;
        for (const auto &elem : ei.elements) {
            if (elem.name == "eAllBits")
                continue;
            if (!first)
                line << " | ";
            line << elem.originalName;
            first = false;
        }
        line << "));";
        gen.doWriteLine(line);
        return;
    }
    gen.doWriteLine("static_assert(static_cast<" + type + ">(VkBindings::" + ei.name + ei.vendor +
                    "::" + name + ") == " + originalName + ");");
}

void EnumElementInfo::writeHeader(CppGenerator &gen, int longestName) const {
    std::stringstream s;
    s << std::left << std::setw(longestName) << name << " = " << value << ",";
    if (!comment.empty())
        s << " // " << comment;
    gen.doWriteLine(s);
}

void EnumElementInfo::writeToString(CppGenerator &gen, bool bitmask) const {
    if (!bitmask) {
        gen.doSwitchCase(name);
        gen.doReturn("\"" + name + "\"");
        gen.doSwitchEndCase();
    } else {
        if (name == "eAllBits")
            return;
        gen.doIf("bitmask & " + name);
        gen.doWriteLine("value_data[value_size++] = \"" + name + "\";");
        gen.doIfEnd();
    }
};

auto EnumInfo::operator<(const EnumInfo &other) const -> bool {
    return std::tie(depends, name, vendor) < std::tie(other.depends, other.name, other.vendor);
}

auto flagName(const std::string &nameAndVendor) -> std::string {
    std::string flagsName = nameAndVendor;
    static const std::string FlagBits = "FlagBits";
    auto it = flagsName.find(FlagBits);
    if (it != std::string::npos) {
        flagsName.erase(it, FlagBits.size());
        flagsName.insert(it, "Flags");
    }
    return flagsName;
}

void EnumInfo::writeHeader(CppGenerator &gen) const {
    const std::string bitwidthStr = bitwidth == Bitwidth::BW32 ? "32" : "64";
    const std::string typeName = type == Type::Enum ? "Enum" : "Bitmask";
    const std::string baseType = bitwidth == Bitwidth::BW32 ? "int32_t" : "uint64_t";

    std::string flagsUsing;
    if (type == Type::Bitmask) {
        flagsUsing =
            "using " + flagName(name + vendor) + " = impl_Enum::Flags<" + name + vendor + ">;";
    }

    gen.doBeginEnumClass(name + vendor, baseType, elements.empty());
    if (!elements.empty()) {
        int longestName = 0;
        for (const auto &element : elements) {
            longestName = std::max(longestName, static_cast<int>(element.name.size()));
        }
        writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeHeader, longestName));
        gen.doEndEnumClass();
    }
    if (type == Type::Bitmask) {
        gen.doWriteLine(flagsUsing);
    }
}

void EnumInfo::writeForwardDecl(CppGenerator &gen) const {
    assert(type == Type::Enum);
    const std::string baseType = bitwidth == Bitwidth::BW32 ? "int32_t" : "uint64_t";
    gen.doWriteLine("enum class " + name + vendor + " : " + baseType + ";");
}

void EnumInfo::writeAssert(CppGenerator &gen) const {
    writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeAssert, *this));
}
void EnumInfo::writeToStringHeader(CppGenerator &gen) const {
    switch (type) {
    case Type::Enum:
        gen.doWriteLine("template <> auto enumToString(" + name + vendor +
                        " enumVal) -> std::string;");
        break;
    case Type::Bitmask:
        gen.doWriteLine("template <> auto bitmaskToString(" + name + vendor +
                        " bitmask) -> std::string;");
        break;
    }
}

void EnumInfo::writeIsEnum(CppGenerator &gen) const {
    assert(type == Type::Enum);
    gen.doWriteLine("template<> struct IsEnum<" + name + vendor + "> :  std::true_type{};");
}

void EnumInfo::writeIsBits(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct IsBits<" + name + vendor + "> : std::true_type{};");
}

void EnumInfo::writeIsFlag(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct IsFlag<" + flagName(name + vendor) +
                    "> : std::true_type{};");
}

void EnumInfo::writeBitsToFlag(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct BitsToFlag<" + name + vendor +
                    "> { using t = " + flagName(name + vendor) + "; };");
}

void EnumInfo::writeFlagToBits(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct FlagToBits<" + flagName(name + vendor) +
                    "> { using t = " + name + vendor + "; };");
}

void EnumInfo::writeToString(CppGenerator &gen) const {
    if (type == Type::Enum) {
        gen.doLineBeginScope("template<> auto enumToString(" + name + vendor +
                             " enumVal) -> std::string");
        gen.doWriteLine("using enum " + name + vendor + ";");
        gen.doSwitch("enumVal");
        writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeToString, false));
        gen.doEndSwitch();
        gen.doReturn("\"EnumElement not part of: " + name + vendor + "\"");
        gen.endScope();
        return;
    }
    std::string flagsName = name + vendor;
    static const std::string FlagBits = "FlagBits";
    auto it = flagsName.find(FlagBits);
    if (it != std::string::npos) {
        flagsName.erase(it, FlagBits.size());
        flagsName.insert(it, "Flags");
    }

    if (elements.empty()) {
        gen.doLineBeginScope("template<> auto bitmaskToString(" + flagsName +
                             " bitmask) -> std::string");
        gen.doIf("bitmask");
        gen.doReturn("\"" + flagsName + " has no bits, it sould be empty\"");
        gen.doIfEnd();
        gen.doReturn("\"\"");
        gen.endScope();
        return;
    }

    gen.doLineBeginScope("template<> auto bitmaskToString(" + flagsName +
                         " bitmask) -> std::string");
    gen.doWriteLine("using enum " + name + vendor + ";");
    if (allValue != 0) {
        gen.doIf("(bitmask & eAllBits) != bitmask");
        gen.doReturn("\"" + name + vendor + " does contain a bit that is not possible to be set\"");
        gen.doIfEnd();
    }
    gen.doWriteLine("size_t value_size = 0;");
    gen.doWriteLine("std::array<std::string_view, " + std::to_string(elements.size()) +
                    "> value_data;");
    writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeToString, true));
    gen.doReturn("std::ranges::subrange(value_data.begin(), value_data.begin() + value_size) | "
                 "std::views::join_with(std::string(\" | \")) | std::ranges::to<std::string>()");

    gen.endScope();
};

// According to
// https://registry.khronos.org/vulkan/specs/latest/styleguide.html#extensions-assigning-token-values
static auto enumElementNumber(int64_t extensionNumber, int64_t offset, bool dirNegative)
    -> int64_t {
    static const constinit int64_t baseValue = 1000000000;
    static const constinit int64_t rangeSize = 1000;
    if (!dirNegative) {
        return baseValue + (extensionNumber - 1) * rangeSize + offset;
    } else {
        return -(baseValue + (extensionNumber - 1) * rangeSize + offset);
    }
}
static auto enumElementUNumber(uint64_t extensionNumber, uint64_t offset,
                               [[maybe_unused]] bool dirNegative) -> uint64_t {
    static const constinit uint64_t baseValue = 1000000000;
    static const constinit uint64_t rangeSize = 1000;
    assert(!dirNegative);
    return baseValue + (extensionNumber - 1) * rangeSize + offset;
}

static auto enumElementValue(int64_t val, EnumInfo::Bitwidth bitwidth, EnumInfo::Type type)
    -> std::string {
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

static auto enumElementUValue(uint64_t val, EnumInfo::Bitwidth bitwidth, EnumInfo::Type type)
    -> std::string {
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

auto getEnumElementMapping(XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regMapping;
    auto &mapping = regMapping[&registry];
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

auto parseEnumZeroElement(XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regZeroElements;
    auto &zeroElements = regZeroElements[&registry];
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

auto parseAllEnums(XMLElement &registry) -> const std::unordered_set<std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>> regAllEnums;
    auto &allEnums = regAllEnums[&registry];
    if (!allEnums.empty())
        return allEnums;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &enumInfo : enumInfos) {
        allEnums.insert(enumInfo.name + enumInfo.vendor);
    }

    return allEnums;
}

auto parseAllEnumFlags(XMLElement &registry) -> const std::unordered_set<std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>> regAllEnumFlags;
    auto &allEnumFlags = regAllEnumFlags[&registry];
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

auto getEnumSizeTypes(XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regEnumSizeTypes;
    auto &enumSizeTypes = regEnumSizeTypes[&registry];
    if (!enumSizeTypes.empty())
        return enumSizeTypes;

    const auto &enumInfos = parseEnumInfos(registry);

    for (const auto &enumInfo : enumInfos) {
        enumSizeTypes[enumInfo.name + enumInfo.vendor] =
            enumInfo.bitwidth == EnumInfo::Bitwidth::BW32 ? "int32_t" : "uint64_t";
    }

    return enumSizeTypes;
}

auto parseEnumInfos(XMLElement &registry) -> const std::set<EnumInfo> & {
    static std::unordered_map<XMLElement *, std::set<EnumInfo>> regEnumInfos;
    auto &enumInfos = regEnumInfos[&registry];
    if (!enumInfos.empty())
        return enumInfos;

    const std::unordered_set<std::string> &vendorTags = parseVendorTags();
    std::unordered_map<std::string, EnumInfo> enumInfosMap;

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");

    auto handleEnum = [&](XMLElement &element, const std::string &enumName,
                          int64_t extensionNumber = 0) -> void {
        assert(HasAttribute(element, "name"));
        if (HasAttribute(element, "alias"))
            return;
        auto enumInfoMapKey = enumName;
        if (enumInfoMapKey == "") {
            if (!HasAttribute(element, "extends")) // some kind of version makro or sth
                return;
            enumInfoMapKey = Attribute(element, "extends");
        }
        EnumInfo &enumInfo = enumInfosMap.at(enumInfoMapKey);

        EnumElementInfo elem;
        elem.originalName = Attribute(element, "name");
        elem.name = elem.originalName;
        if (elem.name.starts_with("VK")) {
            elem.name = elem.name.substr(2);
        }
        elem.name = screamingSnakeCaseToPascalCase(elem.name, vendorTags);
        std::string enumNoFlagsName = enumInfo.name;
        static const std::string FlagBits = "FlagBits";
        static const std::string Flags = "Flags";
        if (auto it = enumNoFlagsName.find(FlagBits); it != std::string::npos) {
            enumNoFlagsName.erase(it, FlagBits.size());
        } else if (auto it2 = enumNoFlagsName.find(Flags); it2 != std::string::npos) {
            enumNoFlagsName.erase(it2, Flags.size());
        }

        if (!enumNoFlagsName.empty() && elem.name.starts_with(enumNoFlagsName)) {
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
                enumInfo.allValue |= std::stoull(value, nullptr, 0);
                elem.value = enumElementUValue(std::stoull(value, nullptr, 0), enumInfo.bitwidth,
                                               enumInfo.type);
            }
        } else if (HasAttribute(element, "bitpos")) {
            std::string bitpos = Attribute(element, "bitpos");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value =
                    enumElementValue(1LL << std::stoi(bitpos), enumInfo.bitwidth, enumInfo.type);
            } else {
                enumInfo.allValue |= 1ULL << std::stoi(bitpos);
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
                enumInfo.allValue |= enumElementUNumber(static_cast<uint64_t>(extensionNumber),
                                                        static_cast<uint64_t>(offset), dirNegative);
                elem.value = enumElementUValue(
                    enumElementUNumber(static_cast<uint64_t>(extensionNumber),
                                       static_cast<uint64_t>(offset), dirNegative),
                    enumInfo.bitwidth, enumInfo.type);
            }
        }
        if (HasAttribute(element, "comment")) {
            elem.comment = Attribute(element, "comment");
        }
        enumInfo.elements.insert(std::move(elem));
    };

    ForEach(registry, "enums", [&](XMLElement &enums) -> void {
        EnumInfo enumInfo;
        assert(HasAttribute(enums, "name"));
        enumInfo.originalName = Attribute(enums, "name");
        if (objectsDisabled.contains(enumInfo.originalName))
            return;
        enumInfo.name = enumInfo.originalName;
        if (enumInfo.name.starts_with("Vk")) {
            enumInfo.name = enumInfo.name.substr(2);
        }
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

    ForEach(registry, "feature", [&](XMLElement &feature) -> void {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;
        ForEach(feature, "require", [&](XMLElement &require) -> void {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum",
                    [&](XMLElement &enumElement) -> void { handleEnum(enumElement, ""); });
        });
    });

    XMLElement &extensions = FirstChildElement(registry, "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        int64_t extensionNumber = std::stoll(Attribute(extension, "number"));
        std::string extension_name = Attribute(extension, "name");
        ForEach(extension, "require", [&](XMLElement &require) -> void {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElement) -> void {
                handleEnum(enumElement, "", extensionNumber);
            });
        });
    });

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, "category", "bitmask"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        if (HasAttribute(type, "bitvalues"))
            return;
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

    for (auto &[_, enumInfo] : enumInfosMap) {
        if (enumInfo.type == EnumInfo::Type::Bitmask && enumInfo.allValue != 0) {
            enumInfo.elements.insert(EnumElementInfo{
                .originalName = "",
                .name = "eAllBits",
                .value = enumElementUValue(enumInfo.allValue, enumInfo.bitwidth, enumInfo.type),
                .comment = "generated for ~(not), error checking and for convenience",
                .depends = {}});
        }
        enumInfos.insert(enumInfo);
    }
    return enumInfos;
}

auto parseEnumInfosDepends(XMLElement &registry) -> const std::set<EnumInfo> & {
    static std::unordered_map<XMLElement *, std::set<EnumInfo>> regEnumInfos;
    auto &enumInfos = regEnumInfos[&registry];
    if (!enumInfos.empty())
        return enumInfos;
    const auto &typeDepends = parseObjectDepents(registry, "type");
    const auto &enumDepends = parseObjectDepents(registry, "enum");

    auto parsed = parseEnumInfos(registry);

    std::set<EnumInfo> tmp;
    std::ranges::transform(
        parsed, std::inserter(tmp, tmp.end()), [&](EnumInfo const &info) -> EnumInfo {
            EnumInfo copy = info;

            if (auto it = typeDepends.find(copy.originalName); it != typeDepends.end()) {
                copy.depends = it->second;
            }

            std::set<EnumElementInfo> newElems;
            std::ranges::transform(copy.elements, std::inserter(newElems, newElems.end()),
                                   [&](EnumElementInfo const &el) -> EnumElementInfo {
                                       EnumElementInfo elcopy = el;
                                       if (auto it2 = enumDepends.find(elcopy.originalName);
                                           it2 != enumDepends.end()) {
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
