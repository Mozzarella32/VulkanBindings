#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <cstdint>
#include <set>
#include <string>

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
