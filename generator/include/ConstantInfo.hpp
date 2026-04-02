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

    bool operator<(const ConstantInfo &other) const;

    void writeHeader(CppGenerator &gen) const;
};

extern const std::unordered_map<std::string, std::string> &getConstantMapping();
extern const std::unordered_map<std::string, std::string> &getConstantValues();
extern const std::set<ConstantInfo> &parseConstantInfos(tinyxml2::XMLElement &vkRegistry,
                                                        tinyxml2::XMLElement &videoRegistry);
