#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>
#include <vector>

struct StructInfo {
    struct Member : public TypeAndName {
        Member &operator=(TypeAndName &&tan) {
            *static_cast<TypeAndName *>(this) = std::move(tan);
            return *this;
        }
        std::string value;
    };

    static std::unordered_map<std::string, std::string> enumAlias;

    int rank;
    std::string name;
    std::string originalName;
    std::vector<Member> members;
    Depends depends;
    bool isUnion : 1;

    bool operator<(const StructInfo &other) const;

    static void writeHeader(CppGenerator &gen, const StructInfo &inf);

    static void writeAssert(CppGenerator &gen, const StructInfo &info);
};

extern const std::set<StructInfo> &parseStructInfos(tinyxml2::XMLElement &registry);
