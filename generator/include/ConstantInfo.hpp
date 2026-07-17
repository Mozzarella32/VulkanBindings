#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>

struct ConstantInfo {
    std::string type;
    std::string originalName;
    std::string name;
    std::string value;
    Depends depends;

    auto operator<(const ConstantInfo &other) const -> bool;

    void writeHeader(CppGenerator &gen) const;
};

extern auto getConstantMapping() -> const std::unordered_map<std::string, std::string> &;
extern auto getConstantValues() -> const std::unordered_map<std::string, std::string> &;
extern auto parseConstantInfos(tinyxml2::XMLElement &vkRegistry,
                               tinyxml2::XMLElement &videoRegistry)
    -> const std::set<ConstantInfo> &;
