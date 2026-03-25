#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>

struct BaseTypeInfo {
    Depends depends;
    std::string name;
    std::string code;

    bool operator<(const BaseTypeInfo &other) const;

    void write(CppGenerator &gen) const;
};

extern const std::set<BaseTypeInfo> &parseBaseTypeInfo(tinyxml2::XMLElement &registry);
