#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <string>

struct ConstantInfo {
    std::string type;
    std::string name;
    std::string value;
    Depends depends;

    bool operator<(const ConstantInfo &other) const;

    static void writeHeader(CppGenerator &gen, const ConstantInfo &ci);
    static void writeImpl(CppGenerator &gen, const ConstantInfo &ci);
};
