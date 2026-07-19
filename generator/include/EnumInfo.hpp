#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>

struct EnumInfo;

struct EnumElementInfo {
    std::string originalName;
    std::string name;
    std::string value;
    std::string comment;

    Depends depends;
    auto operator<(const EnumElementInfo &other) const -> bool;

    void writeHeader(CppGenerator &gen, int longestName) const;
    void writeAssert(CppGenerator &gen, const EnumInfo &ei) const;
    void writeToString(CppGenerator &gen, bool bitmask) const;
};

struct EnumInfo {
    std::set<EnumElementInfo> elements;

    enum class Type : unsigned char {
        Enum,
        Bitmask,
    } type : 1;
    enum class Bitwidth : unsigned char {
        BW32,
        BW64,
    } bitwidth : 1;
    std::string originalName;
    std::string name;
    std::string vendor;
    uint64_t allValue = 0; // only on Bitmask

    Depends depends;
    auto operator<(const EnumInfo &other) const -> bool;

    void writeHeader(CppGenerator &gen) const;
    void writeForwardDecl(CppGenerator &gen) const;
    void writeAssert(CppGenerator &gen) const;
    void writeToString(CppGenerator &gen) const;
};

extern auto getEnumElementMapping(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> &;
extern auto parseEnumZeroElement(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> &;
extern auto parseAllEnums(tinyxml2::XMLElement &registry)
    -> const std::unordered_set<std::string> &;
extern auto parseAllEnumFlags(tinyxml2::XMLElement &registry)
    -> const std::unordered_set<std::string> &;
extern auto getEnumSizeTypes(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> &;
extern auto parseEnumInfos(tinyxml2::XMLElement &registry) -> const std::set<EnumInfo> &;
extern auto parseEnumInfosDepends(tinyxml2::XMLElement &registry) -> const std::set<EnumInfo> &;
