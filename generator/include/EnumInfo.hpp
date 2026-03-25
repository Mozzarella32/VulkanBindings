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
    bool operator<(const EnumElementInfo &other) const;

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
    bool operator<(const EnumInfo &other) const;

    void writeHeader(CppGenerator &gen) const;
    void writeAssert(CppGenerator &gen) const;
    void writeToString(CppGenerator &gen) const;
};

extern const std::unordered_map<std::string, std::string> &
getEnumElementMapping(tinyxml2::XMLElement &registry);
extern const std::unordered_map<std::string, std::string> &
parseEnumZeroElement(tinyxml2::XMLElement &registry);
extern const std::unordered_set<std::string> &parseAllEnums(tinyxml2::XMLElement &registry);
extern const std::unordered_set<std::string> &parseAllEnumFlags(tinyxml2::XMLElement &registry);
extern const std::unordered_map<std::string, std::string> &
getEnumSizeTypes(tinyxml2::XMLElement &registry);
extern const std::set<EnumInfo> &parseEnumInfos(tinyxml2::XMLElement &registry);
extern const std::set<EnumInfo> &parseEnumInfosDepends(tinyxml2::XMLElement &registry);
