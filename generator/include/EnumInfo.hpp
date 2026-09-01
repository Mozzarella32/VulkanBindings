#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"

#include <cstddef>
#include <cstdint>
#include <optional>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

struct EnumInfo;

struct EnumElementInfo {
  private:
    std::string originalName;
    std::string name;
    std::string value;
    std::string comment;
    std::optional<std::string> deprecated;

    Depends depends;

  public:
    EnumElementInfo(std::string original, std::string name, std::string value, std::string comment,
                    Depends depends);
    EnumElementInfo() = default;

    [[nodiscard]] auto getDepends() const -> const Depends &;

    auto operator<(const EnumElementInfo &other) const -> bool;

    void writeHeader(CppGenerator &gen, size_t longestName) const;
    void writeAssert(CppGenerator &gen, const EnumInfo &enumInfo) const;
    void writeBitmaskSizeToString(CppGenerator &gen, bool bitmask) const;
    void writeBitmaskDataToString(CppGenerator &gen, bool bitmask, std::string_view first,
                                  std::string_view last) const;
    void writeToStringView(CppGenerator &gen) const;

    friend EnumInfo;
};

struct EnumInfo {
  public:
    enum class Type : std::uint8_t {
        Enum,
        Bitmask,
    };
    enum class Bitwidth : std::uint8_t {
        BW32,
        BW64,
    };

  private:
    std::set<EnumElementInfo> elements;

    std::string originalName;
    std::string name;
    std::string vendor;
    uint64_t allValue = 0; // only on Bitmask

    Type type : 1 = Type::Enum;
    Bitwidth bitwidth : 1 = Bitwidth::BW32;

    Depends depends;
    std::optional<std::tuple<std::string, std::string>> deprecated;

  public:
    [[nodiscard]] auto getName() const -> const std::string &;
    [[nodiscard]] auto getBitwidth() const -> Bitwidth;

    [[nodiscard]] auto getDepends() const -> const Depends &;

    [[nodiscard]] auto hasElements() const -> bool;
    [[nodiscard]] auto isEnum() const -> bool;
    [[nodiscard]] auto isBitmask() const -> bool;
    [[nodiscard]] auto isDeprecated() const -> bool;

    auto operator<(const EnumInfo &other) const -> bool;

    void writeHeader(CppGenerator &gen) const;
    void writeHeaderFlags(CppGenerator &gen) const;
    void writeForwardDecl(CppGenerator &gen) const;
    void writeAssert(CppGenerator &gen) const;
    void writeFlagsImpl(CppGenerator &gen) const;
    void writeToStringEnum(CppGenerator &gen) const;
    void writeToStringBit(CppGenerator &gen) const;
    void writeToStringFlags(CppGenerator &gen) const;
    void writeToStringHeaderEnum(CppGenerator &gen) const;
    void writeToStringHeaderBit(CppGenerator &gen) const;
    void writeToStringHeaderFlags(CppGenerator &gen) const;

    void writeIsEnum(CppGenerator &gen) const;
    void writeIsBits(CppGenerator &gen) const;
    void writeIsFlag(CppGenerator &gen) const;

    void writeBitsToFlag(CppGenerator &gen) const;
    void writeFlagToBits(CppGenerator &gen) const;

    static auto getEnumName(const std::string &nameAndVendor) -> std::string;
    static auto getFlagsName(const std::string &nameAndVendor) -> std::string;

    friend EnumElementInfo;

    static auto getEnumElementMapping(Registry registry)
        -> const std::unordered_map<std::string, std::string> &;
    static auto parseEnumZeroElement(Registry registry)
        -> const std::unordered_map<std::string, std::string> &;
    static auto parseAllEnums(Registry registry) -> const std::unordered_set<std::string> &;
    static auto parseAllEnumFlags(Registry registry) -> const std::unordered_set<std::string> &;
    static auto getEnumSizeTypes(Registry registry)
        -> const std::unordered_map<std::string, std::string> &;
    static auto parseEnumInfos(Registry registry) -> const std::set<EnumInfo> &;
    static auto parseEnumInfosDepends(Registry registry) -> const std::set<EnumInfo> &;
};
