#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>

struct TypeInfo {
    std::string name;
    std::string structureType;
    Depends depends;

    bool operator<(const TypeInfo &other) const;

    static void writeSpecialisation(CppGenerator &gen, const TypeInfo &ti);
};

extern const std::set<TypeInfo> &parseTypeInfos(tinyxml2::XMLElement &registry);
