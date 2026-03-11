#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <string>

struct TypeInfo {
    std::string name;
    std::string structureType;
    Depends depends;

    bool operator<(const TypeInfo &other) const;

    static void writeHeader(CppGenerator &gen, const TypeInfo &ti);
};
