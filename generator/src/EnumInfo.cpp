#include "EnumInfo.hpp"
#include "CppGenerator.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"
#include "Writing.hpp"
#include "XmlUtils.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdint>
#include <cstdlib>
#include <format>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace tinyxml2;

EnumElementInfo::EnumElementInfo(std::string original, std::string name, std::string value,
                                 std::string comment, Depends depends)
    : originalName(std::move(original)), name(std::move(name)), value(std::move(value)),
      comment(std::move(comment)), depends(std::move(depends)) {}
[[nodiscard]] auto EnumElementInfo::getDepends() const -> const Depends & { return depends; }
auto EnumElementInfo::operator<(const EnumElementInfo &other) const -> bool {
    bool isAll = name == "AllBits";
    bool otherIsAll = other.name == "AllBits";
    return std::tie(value, isAll) < std::tie(other.value, otherIsAll);
}

void EnumElementInfo::writeAssert(CppGenerator &gen, const EnumInfo &enumInfo) const {
    const std::string type =
        enumInfo.bitwidth == EnumInfo::Bitwidth::BW64 ? "std::uint64_t" : "std::int32_t";
    if (name == "AllBits") {
        for (const auto &elem : enumInfo.elements) {
            if (elem.name == "AllBits")
                continue;
            if (!elem.depends.platform.empty() || !elem.depends.guard.empty()) {
                gen.doWriteLine("// AllBits is not tested because " + elem.name + " has " +
                                elem.depends.platform + elem.depends.guard);
                return;
            }
        }
        std::stringstream line;
        line << "static_assert(static_cast<" << type
             << ">(VkBindings::" << EnumInfo::getEnumName(enumInfo.name + enumInfo.vendor)
             << "::" << name << ") == ";
        if (enumInfo.elements.size() > 2) // Because of All Bits
            line << "(";

        bool first = true;
        for (const auto &elem : enumInfo.elements) {
            if (elem.name == "AllBits")
                continue;
            if (!first)
                line << " | ";
            line << elem.originalName;
            first = false;
        }
        if (enumInfo.elements.size() > 2) // Because of All Bits
            line << ")";
        line << ");";
        gen.doWriteLine(line);
        return;
    }
    gen.doWriteLine("static_assert(static_cast<" + type +
                    ">(VkBindings::" + EnumInfo::getEnumName(enumInfo.name + enumInfo.vendor) +
                    "::" + name + ") == " + originalName + ");");
}

void EnumElementInfo::writeHeader(CppGenerator &gen, size_t longestName) const {
    std::stringstream buffer;
    buffer << std::left << std::setw(static_cast<int>(longestName)) << name;
    if (deprecated) {
        buffer << std::format(" [[deprecated(\"{}\")]]", deprecated.value());
    }
    buffer << " = " << value << ",";
    if (!comment.empty())
        buffer << " // " << comment;
    gen.doWriteLine(buffer);
}

void EnumElementInfo::writeBitmaskSizeToString(CppGenerator &gen, bool bitmask) const {
    assert(bitmask);
    if (name == "AllBits")
        return;
    gen.doIf("flags & " + name);
    gen.doWriteLine("count++;");
    gen.doWriteLine(std::format("bytes += {};", name.size()));
    gen.doIfEnd();
};

void EnumElementInfo::writeBitmaskDataToString(CppGenerator &gen, bool bitmask,
                                               std::string_view first,
                                               std::string_view last) const {
    assert(bitmask);
    if (name == "AllBits")
        return;
    gen.doIf("flags & " + name);

    if (name != first) {
        gen.doIf("!first");
        gen.doWriteLine("ret += \" | \";");
    }
    if (name != last) {
        if (name != first) {
            gen.doElse();
        }
        gen.doWriteLine("first = false;");
    }
    if (name != first) {
        gen.doIfEnd();
    }
    gen.doWriteLine("ret += \"" + name + "\";");
    gen.doIfEnd();
};

void EnumElementInfo::writeToStringView(CppGenerator &gen) const {
    gen.doSwitchCase(name);
    if (name == "AllBits") {
        gen.doReturn("\"AllBits is no single bit value to pass arount\"sv");
    } else {
        gen.doReturn("\"" + name + "\"sv");
    }
    gen.doSwitchEndCase();
};

auto EnumInfo::getName() const -> const std::string & { return name; }
auto EnumInfo::getBitwidth() const -> Bitwidth { return bitwidth; }

auto EnumInfo::getDepends() const -> const Depends & { return depends; }
auto EnumInfo::operator<(const EnumInfo &other) const -> bool {
    return std::tie(depends, name, vendor) < std::tie(other.depends, other.name, other.vendor);
}
auto EnumInfo::hasElements() const -> bool { return !elements.empty(); }
auto EnumInfo::isEnum() const -> bool { return type == Type::Enum; }
auto EnumInfo::isBitmask() const -> bool { return type == Type::Bitmask; }
auto EnumInfo::isDeprecated() const -> bool { return deprecated.has_value(); }

void EnumInfo::writeHeader(CppGenerator &gen) const {
    const std::string baseType = bitwidth == Bitwidth::BW32 ? "std::int32_t" : "std::uint64_t";

    const std::string enumName = getEnumName(name + vendor);

    gen.doBeginEnumClass(CppGenerator::EnumClass{
        .name = enumName, .attributes = "", .basetype = baseType, .empty = elements.empty()});

    if (!elements.empty()) {
        const size_t longestName =
            std::ranges::max(elements | std::views::transform([](const auto &enumElementInfo) {
                                 return enumElementInfo.name.size();
                             }));
        writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeHeader, longestName));
        gen.doEndEnumClass();
    }
}

void EnumInfo::writeHeaderFlags(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("using " + getFlagsName(name + vendor) + " = impl_Enum::Flags<" +
                    getEnumName(name + vendor) + ">;");
}

void EnumInfo::writeForwardDecl(CppGenerator &gen) const {
    assert(type == Type::Enum);
    const std::string baseType = bitwidth == Bitwidth::BW32 ? "std::int32_t" : "std::uint64_t";
    gen.doWriteLine("enum class " + getEnumName(name + vendor) + " : " + baseType + ";");
}

void EnumInfo::writeAssert(CppGenerator &gen) const {
    writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeAssert, *this));
}

void EnumInfo::writeFlagsImpl(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template struct impl_Enum::Flags<" + getEnumName(name + vendor) + ">;");
    const auto &enumName = getEnumName(name + vendor);
    const auto &flagsName = getFlagsName(name + vendor);
    for (const auto &[firstFlag, secondFlag] :
         std::to_array<std::tuple<bool, bool>>({{false, false}, {false, true}, {true, false}})) {
        for (const auto &sym : {"|", "&", "^"}) {
            const auto &firstArg = firstFlag ? flagsName : enumName;
            const auto &secondArg = secondFlag ? flagsName : enumName;
            gen.doWriteLine(std::format("template auto operator{}<{}>({}, {}) -> {};", sym,
                                        enumName, firstArg, secondArg, flagsName));
        }
    }
}

void EnumInfo::writeToStringHeaderEnum(CppGenerator &gen) const {
    assert(type == Type::Enum);
    gen.doWriteLine("template <> auto enumToString(" + getEnumName(name + vendor) +
                    " enumVal) -> std::string_view;");
}

void EnumInfo::writeToStringHeaderBit(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template <> auto bitToString(" + getEnumName(name + vendor) +
                    " bit) -> std::string_view;");
}

void EnumInfo::writeToStringHeaderFlags(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template <> auto flagsToString(" + getFlagsName(name + vendor) +
                    " flags) -> std::string;");
}

void EnumInfo::writeIsEnum(CppGenerator &gen) const {
    assert(type == Type::Enum);
    gen.doWriteLine("template<> struct IsEnum<" + getEnumName(name + vendor) +
                    "> :  std::true_type{};");
}

void EnumInfo::writeIsBits(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct IsBits<" + getEnumName(name + vendor) +
                    "> : std::true_type{};");
}

void EnumInfo::writeIsFlag(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct IsFlag<" + getFlagsName(name + vendor) +
                    "> : std::true_type{};");
}

void EnumInfo::writeBitsToFlag(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct BitsToFlag<" + getEnumName(name + vendor) +
                    "> { using t = " + getFlagsName(name + vendor) + "; };");
}

void EnumInfo::writeFlagToBits(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doWriteLine("template<> struct FlagToBits<" + getFlagsName(name + vendor) +
                    "> { using t = " + getEnumName(name + vendor) + "; };");
}
auto EnumInfo::getEnumName(const std::string &nameAndVendor) -> std::string {
    constinit static const std::string_view flagBits = "FlagBits";
    constinit static const std::string_view bits = "Bits";
    std::string newName = nameAndVendor;
    auto pos = newName.find(flagBits);
    if (pos == std::string::npos) {
        return nameAndVendor;
    }
    newName.erase(pos, flagBits.size());
    newName.insert(pos, bits);
    return newName;
}

auto EnumInfo::getFlagsName(const std::string &nameAndVendor) -> std::string {
    std::string flagsName = nameAndVendor;
    constinit static const std::string_view FlagBits = "FlagBits";
    auto pos = flagsName.find(FlagBits);
    if (pos == std::string::npos) {
        return flagsName;
    }
    flagsName.erase(pos, FlagBits.size());
    flagsName.insert(pos, "Flags");
    return flagsName;
}

void EnumInfo::writeToStringEnum(CppGenerator &gen) const {
    assert(type == Type::Enum);
    gen.doLineBeginScope("template<> auto enumToString(" + getEnumName(name + vendor) +
                         " enumVal) -> std::string_view");
    gen.doWriteLine("using enum " + getEnumName(name + vendor) + ";");
    gen.doSwitch("enumVal");
    writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeToStringView));
    gen.doEndSwitch();
    gen.doReturn("\"EnumElement not part of: " + getEnumName(name + vendor) + "\"");
    gen.endScope();
};

void EnumInfo::writeToStringBit(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    gen.doLineBeginScope("template<> auto bitToString(" + getEnumName(name + vendor) +
                         " bit) -> std::string_view");
    gen.doWriteLine("using enum " + getEnumName(name + vendor) + ";");
    gen.doSwitch("bit");
    auto stringViewElements = elements;
    auto allBits = std::ranges::find_if(stringViewElements,
                                        [](const auto &info) { return info.name == "AllBits"; });
    if (std::ranges::find_if(stringViewElements, [&](const auto &info) {
            return info.name != "AllBits" && info.value == allBits->value;
        }) != stringViewElements.end()) {
        stringViewElements.erase(allBits);
    }
    writeDepends(gen, stringViewElements, std::bind_back(&EnumElementInfo::writeToStringView));
    gen.doEndSwitch();
    gen.doReturn("\"bit not part of: " + getEnumName(name + vendor) + "\"");
    gen.endScope();
};

void EnumInfo::writeToStringFlags(CppGenerator &gen) const {
    assert(type == Type::Bitmask);
    if (elements.empty()) {
        gen.doLineBeginScope("template<> auto flagsToString(" + getFlagsName(name + vendor) +
                             " flags) -> std::string");
        gen.doIf("flags");
        gen.doReturn("\"" + getFlagsName(name + vendor) + " has no bits, it sould be empty\"");
        gen.doIfEnd();
        gen.doReturn("\"\"");
        gen.endScope();
        return;
    }

    gen.doLineBeginScope("template<> auto flagsToString(" + getFlagsName(name + vendor) +
                         " flags) -> std::string");
    gen.doWriteLine("using enum " + getEnumName(name + vendor) + ";");
    if (allValue != 0) {
        gen.doIf("(flags & AllBits) != flags");
        gen.doReturn("\"" + getEnumName(name + vendor) +
                     " does contain a bit that is not possible to be set\"");
        gen.doIfEnd();
    }

    const bool containsAllBits = std::ranges::find_if(elements, [](const auto &info) {
                                     return info.name == "AllBits";
                                 }) != elements.end();
    const bool hasOnlyOneBit = elements.size() - (containsAllBits ? 1 : 0) == 1;
    if (hasOnlyOneBit) {
        const auto &first = elements.begin()->name;
        gen.doIf("flags & " + first);
        gen.doReturn("\"" + first + "\"");
        gen.doIfEnd();
        gen.doReturn("\"\"");
        gen.endScope();
        return;
    }

    gen.doWriteLine("size_t count = 0;");
    gen.doWriteLine("size_t bytes = 0;");
    writeDepends(gen, elements, std::bind_back(&EnumElementInfo::writeBitmaskSizeToString, true));
    gen.doWriteLine("std::string ret;");
    gen.doIf("count == 0");
    gen.doReturn("\"\"");
    gen.doIfEnd();
    gen.doWriteLine("ret.reserve(bytes + (3 * (count - 1)));");
    gen.doWriteLine("bool first = true;");
    writeDepends(gen, elements,
                 std::bind_back(&EnumElementInfo::writeBitmaskDataToString, true,
                                elements.begin()->name, std::prev(elements.end(), 2)->name));
    gen.doReturn("ret");
    gen.endScope();
};

namespace {
// According to
// https://registry.khronos.org/vulkan/specs/latest/styleguide.html#extensions-assigning-token-values
auto enumElementNumber(int64_t extensionNumber, int64_t offset, bool dirNegative) -> int64_t {
    static const constinit int64_t baseValue = 1000000000;
    static const constinit int64_t rangeSize = 1000;
    if (!dirNegative) {
        return baseValue + ((extensionNumber - 1) * rangeSize) + offset;
    }
    return -(baseValue + ((extensionNumber - 1) * rangeSize) + offset);
}
auto enumElementUNumber(uint64_t extensionNumber, uint64_t offset,
                        [[maybe_unused]] bool dirNegative) -> uint64_t {
    static const constinit uint64_t baseValue = 1000000000;
    static const constinit uint64_t rangeSize = 1000;
    assert(!dirNegative);
    return baseValue + ((extensionNumber - 1) * rangeSize) + offset;
}

auto enumElementValue(int64_t val, EnumInfo::Bitwidth bitwidth, EnumInfo::Type type)
    -> std::string {
    const int hexDigits = (bitwidth == EnumInfo::Bitwidth::BW32) ? 8 : 16;

    std::stringstream buffer;
    if (val < 0) {
        buffer << "-";
    }
    if (type == EnumInfo::Type::Enum) {
        assert(bitwidth == EnumInfo::Bitwidth::BW32);
        buffer << std::right << std::dec << std::setw(std::numeric_limits<int32_t>::digits10 + 1)
               << std::setfill(' ') << std::llabs(val);
        return buffer.str();
    }

    buffer << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0')
           << std::llabs(val);
    return buffer.str();
}

auto enumElementUValue(uint64_t val, EnumInfo::Bitwidth bitwidth, EnumInfo::Type type)
    -> std::string {
    const int hexDigits = (bitwidth == EnumInfo::Bitwidth::BW32) ? 8 : 16;

    std::stringstream buffer;
    if (type == EnumInfo::Type::Enum) {
        assert(bitwidth == EnumInfo::Bitwidth::BW32);
        buffer << std::right << std::dec << std::setw(std::numeric_limits<int32_t>::digits10 + 1)
               << std::setfill(' ');
        return buffer.str();
    }

    buffer << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0') << val;
    return buffer.str();
}
} // namespace

auto EnumInfo::getEnumElementMapping(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regMapping;
    auto &mapping = regMapping[&registry.getActive()];
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

auto EnumInfo::parseEnumZeroElement(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regZeroElements;
    auto &zeroElements = regZeroElements[&registry.getActive()];
    if (!zeroElements.empty())
        return zeroElements;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &enumInfo : enumInfos) {
        const std::string zeroValue = enumInfo.type == Type::Enum
                                          ? enumElementValue(0, enumInfo.bitwidth, enumInfo.type)
                                          : enumElementUValue(0, enumInfo.bitwidth, enumInfo.type);
        if (enumInfo.elements.empty())
            continue;
        for (const auto &element : enumInfo.elements) {
            if (element.value == zeroValue) {
                zeroElements[enumInfo.originalName] =
                    getEnumName(enumInfo.name + enumInfo.vendor) + "::" + element.name;
                break;
            }
        }
        if (!zeroElements[enumInfo.originalName].empty())
            continue;
        if (auto iter = std::ranges::find_if(
                enumInfo.elements, [](const auto &element) { return element.name == "Default"; });
            iter != enumInfo.elements.end()) {
            zeroElements[enumInfo.originalName] =
                getEnumName(enumInfo.name + enumInfo.vendor) + "::" + iter->name;
            continue;
        }
        if (auto iter = std::ranges::find_if(
                enumInfo.elements, [](const auto &element) { return element.name == "Invalid"; });
            iter != enumInfo.elements.end()) {
            zeroElements[enumInfo.originalName] =
                getEnumName(enumInfo.name + enumInfo.vendor) + "::" + iter->name;
            continue;
        }
        zeroElements[enumInfo.originalName] =
            getEnumName(enumInfo.name + enumInfo.vendor) + "::" + enumInfo.elements.begin()->name;
    }

    return zeroElements;
}

auto EnumInfo::parseAllEnums(Registry registry) -> const std::unordered_set<std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>> regAllEnums;
    auto &allEnums = regAllEnums[&registry.getActive()];
    if (!allEnums.empty())
        return allEnums;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &enumInfo : enumInfos) {
        allEnums.insert(enumInfo.name + enumInfo.vendor);
    }

    return allEnums;
}

auto EnumInfo::parseAllEnumFlags(Registry registry) -> const std::unordered_set<std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>> regAllEnumFlags;
    auto &allEnumFlags = regAllEnumFlags[&registry.getActive()];
    if (!allEnumFlags.empty())
        return allEnumFlags;

    const auto &enumInfos = parseEnumInfos(registry);
    for (const auto &enumInfo : enumInfos) {
        if (enumInfo.type != EnumInfo::Type::Bitmask)
            continue;
        std::string flagsName = enumInfo.name + enumInfo.vendor;
        static const std::string FlagBits = "FlagBits";
        auto iter = flagsName.find(FlagBits);
        if (iter != std::string::npos) {
            flagsName.erase(iter, FlagBits.size());
            flagsName.insert(iter, "Flags");
        }
        allEnumFlags.insert(flagsName);
    }

    return allEnumFlags;
}

auto EnumInfo::getEnumSizeTypes(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regEnumSizeTypes;
    auto &enumSizeTypes = regEnumSizeTypes[&registry.getActive()];
    if (!enumSizeTypes.empty())
        return enumSizeTypes;

    const auto &enumInfos = parseEnumInfos(registry);

    for (const auto &enumInfo : enumInfos) {
        enumSizeTypes[enumInfo.name + enumInfo.vendor] =
            enumInfo.bitwidth == Bitwidth::BW32 ? "int32_t" : "uint64_t";
    }

    return enumSizeTypes;
}

auto EnumInfo::parseEnumInfos(Registry registry) -> const std::set<EnumInfo> & {
    static std::unordered_map<XMLElement *, std::set<EnumInfo>> regEnumInfos;
    auto &enumInfos = regEnumInfos[&registry.getActive()];
    if (!enumInfos.empty())
        return enumInfos;

    const std::vector<std::string> &vendorTags = parseVendorTags(registry);
    std::unordered_map<std::string, EnumInfo> enumInfosMap;

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");
    // const auto &deprecations = parseDeprecation(registry);

    auto handleEnum = [&](XMLElement &element, const std::string &enumName,
                          int64_t extensionNumber = 0) -> void {
        assert(HasAttribute(element, "name"));
        if (HasAttribute(element, "alias"))
            return;
        auto enumInfoMapKey = enumName;
        if (enumInfoMapKey.empty()) {
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
        if (auto iter = enumNoFlagsName.find(FlagBits); iter != std::string::npos) {
            enumNoFlagsName.erase(iter, FlagBits.size());
        } else if (auto it2 = enumNoFlagsName.find(Flags); it2 != std::string::npos) {
            enumNoFlagsName.erase(it2, Flags.size());
        }

        if (!enumNoFlagsName.empty() && elem.name.starts_with(enumNoFlagsName)) {
            elem.name = elem.name.substr(enumNoFlagsName.size());
        }
        if (!enumInfo.vendor.empty() && elem.name.ends_with(enumInfo.vendor)) {
            elem.name = elem.name.substr(0, elem.name.size() - enumInfo.vendor.size());
        }
        if (enumInfo.type == EnumInfo::Type::Bitmask && elem.name.ends_with("Bit")) {
            elem.name = elem.name.substr(0, elem.name.size() - 3);
        }
        if (std::isdigit(elem.name.at(0)))
            elem.name.insert(0, "v");
        if (HasAttribute(element, "value")) {
            const std::string value = Attribute(element, "value");
            if (enumInfo.type == EnumInfo::Type::Enum) {
                elem.value = enumElementValue(std::stoll(value, nullptr, 0), enumInfo.bitwidth,
                                              enumInfo.type);
            } else {
                enumInfo.allValue |= std::stoull(value, nullptr, 0);
                elem.value = enumElementUValue(std::stoull(value, nullptr, 0), enumInfo.bitwidth,
                                               enumInfo.type);
            }
        } else if (HasAttribute(element, "bitpos")) {
            const std::string bitpos = Attribute(element, "bitpos");
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
            const int64_t offset = std::stoll(Attribute(element, "offset"));
            if (HasAttribute(element, "extnumber")) {
                extensionNumber = std::stoi(Attribute(element, "extnumber"));
            }
            const bool dirNegative = HasAttribute(element, "dir");
            if (dirNegative)
                assert(HasAttributeValue(element, AttributeName{"dir"}, AttributeValue{"-"}));
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
        if (HasAttribute(element, "deprecated")) {
            elem.deprecated = Attribute(element, "deprecated");
            if (elem.deprecated == "true") {
                elem.deprecated = "legacy without explanation";
            } else if (elem.deprecated == "unused") {
                elem.deprecated = "unused, must not be passed to the api";
            } else if (elem.deprecated == "aliased") {
                assert(false && "This sould not happen as we dont procude aliases");
            } else {
                assert(false);
            }
        }
        enumInfo.elements.insert(std::move(elem));
    };

    ForEach(registry.getActive(), "enums", [&](XMLElement &enums) -> void {
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
        const std::string enumElmentType = Attribute(enums, "type");
        if (enumElmentType == "constants")
            return;
        if (enumElmentType == "enum") {
            enumInfo.type = EnumInfo::Type::Enum;
        } else {
            assert(enumElmentType == "bitmask");
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
        const std::string originalName = enumInfo.originalName;
        enumInfosMap[enumInfo.originalName] = std::move(enumInfo);
        ForEach(enums, "enum", std::bind_back(handleEnum, originalName));
    });

    ForEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
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

    XMLElement &extensions = FirstChildElement(registry.getActive(), "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        int64_t extensionNumber = std::stoll(Attribute(extension, "number"));
        ForEach(extension, "require", [&](XMLElement &require) -> void {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, "enum", [&](XMLElement &enumElement) -> void {
                handleEnum(enumElement, "", extensionNumber);
            });
        });
    });

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"bitmask"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        if (HasAttribute(type, "bitvalues"))
            return;
        const std::string typeType = FirstChildElement(type, "type").GetText();
        std::string typeName = FirstChildElement(type, "name").GetText();
        static constinit const std::string_view Flags = "Flags";
        static constinit const std::string_view FlagBits = "FlagBits";
        if (auto iter = typeName.find(Flags); iter != std::string::npos) {
            typeName.erase(iter, Flags.length());
            typeName.insert(iter, FlagBits);
        }
        if (enumInfosMap.contains(typeName)) {
            return;
        }
        EnumInfo info;
        if (typeType == "VkFlags") {
            info.bitwidth = Bitwidth::BW32;
        } else {
            assert(typeType == "VkFlags64");
            info.bitwidth = Bitwidth::BW64;
        }
        info.type = Type::Bitmask;
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
                "",
                "AllBits",
                enumElementUValue(enumInfo.allValue, enumInfo.bitwidth, enumInfo.type),
                "generated for ~(not), error checking and for convenience",
                {}});
        }
        // Dont deprecate Enums as
        // https://docs.vulkan.org/spec/latest/appendices/legacy.html#legacy-flagbits exists, and
        // they are still used
        //  if (auto iter = deprecations.find(enumInfo.originalName); iter !=
        // deprecations.end()) {
        //     if (iter->second.empty()) {
        //         enumInfo.deprecated = std::make_tuple("", "");
        //     } else {
        //         std::string name = iter->second.substr(2);
        //         std::string vendor;
        //         for (const auto &vendorTag : vendorTags) {
        //             if (name.ends_with(vendorTag)) {
        //                 vendor = vendorTag;
        //                 name = name.substr(0, name.size() - vendorTag.size());
        //             }
        //         }

        //         enumInfo.deprecated = std::make_tuple(name, vendor);
        //     }
        // }
        enumInfos.insert(enumInfo);
    }
    return enumInfos;
}

auto EnumInfo::parseEnumInfosDepends(Registry registry) -> const std::set<EnumInfo> & {
    static std::unordered_map<XMLElement *, std::set<EnumInfo>> regEnumInfos;
    auto &enumInfos = regEnumInfos[&registry.getActive()];
    if (!enumInfos.empty())
        return enumInfos;
    const auto &typeDepends = parseObjectDepents(registry, "type");
    const auto &enumDepends = parseObjectDepents(registry, "enum");

    auto parsed = parseEnumInfos(registry);

    std::set<EnumInfo> tmp;
    std::ranges::transform(
        parsed, std::inserter(tmp, tmp.end()), [&](EnumInfo const &info) -> EnumInfo {
            EnumInfo copy = info;

            if (auto iter = typeDepends.find(copy.originalName); iter != typeDepends.end()) {
                copy.depends = iter->second;
            }

            std::set<EnumElementInfo> newElems;
            std::ranges::transform(copy.elements, std::inserter(newElems, newElems.end()),
                                   [&](EnumElementInfo const &enumElementInfo) -> EnumElementInfo {
                                       EnumElementInfo elcopy = enumElementInfo;
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
