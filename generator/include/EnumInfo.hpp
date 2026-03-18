#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>

struct EnumElementInfo {
    std::string originalName;
    std::string name;
    std::string value;
    std::string comment;

    Depends depends;
    bool operator<(const EnumElementInfo &other) const;

    static void writeHeader(CppGenerator &gen, const EnumElementInfo &eei, int longestName);
    static void writeAssert(CppGenerator &gen, const EnumElementInfo &eei,
                            const std::string &enumName, bool size64);
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

    Depends depends;
    bool operator<(const EnumInfo &other) const;

    static void writeHeader(CppGenerator &gen, const EnumInfo &ei);
    static void writeAssert(CppGenerator &gen, const EnumInfo &ei);
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
