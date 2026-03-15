#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>

struct ConstantInfo {
    std::string type;
    std::string name;
    std::string value;
    Depends depends;

    bool operator<(const ConstantInfo &other) const;

    static void writeHeader(CppGenerator &gen, const ConstantInfo &ci);
    static void writeImpl(CppGenerator &gen, const ConstantInfo &ci);
};

extern const std::set<ConstantInfo> &parseConstantInfos(tinyxml2::XMLElement &registry);
