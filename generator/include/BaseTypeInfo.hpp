#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>

struct BaseTypeInfo {
    Depends depends;
    std::string originalName;
    std::string name;
    std::string code;

    auto operator<(const BaseTypeInfo &other) const -> bool;

    void write(CppGenerator &gen) const;
};

extern auto getBaseTypeMapping(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> &;
extern auto getIntTypedefs(tinyxml2::XMLElement &registry) -> const std::unordered_set<std::string>;
extern auto parseBaseTypeInfo(tinyxml2::XMLElement &registry) -> const std::set<BaseTypeInfo> &;
