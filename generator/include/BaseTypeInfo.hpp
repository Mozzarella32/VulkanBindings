#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>

struct BaseTypeInfo {
    Depends depends;
    std::string originalName;
    std::string name;
    std::string code;

    bool operator<(const BaseTypeInfo &other) const;

    void write(CppGenerator &gen) const;
};

extern const std::unordered_map<std::string, std::string> &
getBaseTypeMapping(tinyxml2::XMLElement &registry);
extern const std::set<BaseTypeInfo> &parseBaseTypeInfo(tinyxml2::XMLElement &registry);
