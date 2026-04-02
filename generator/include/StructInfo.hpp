#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_set>
#include <vector>

struct StructTemplateInstanceInfo {
    Depends depends;
    std::string type;

    bool operator<(const StructTemplateInstanceInfo &other) const;

    void writeAssert(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
};

struct StructInfo {
    struct Member : public TypeAndName {
        Member &operator=(TypeAndName &&tan) {
            *static_cast<TypeAndName *>(this) = std::move(tan);
            return *this;
        }
        std::string value;
        std::string len;
        std::string vulkanName;
        std::string accessor; // for size and alignment(.size)
        std::string offsetOf;
        bool optional : 1 = false;
        bool removed : 1 = false;
    };

    struct FunctionWithBody : public Function {
        std::string body;
    };

    std::vector<FunctionWithBody> functions;

    int rank;
    std::string name;
    std::string originalName;
    std::vector<Member> members;
    Depends depends;
    bool isUnion : 1;

    bool operator<(const StructInfo &other) const;

    void writeHeader(CppGenerator &gen) const;
    void writeForward(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
    void writeAssert(CppGenerator &gen) const;
};

extern const std::unordered_set<std::string> &parseAllStructs(tinyxml2::XMLElement &registry);
extern const std::unordered_set<std::string> &parseAllUnions(tinyxml2::XMLElement &registry);
extern const std::tuple<std::set<StructInfo>, std::set<StructTemplateInstanceInfo>> &
parseStructInfosAndTemplateInstantiations(tinyxml2::XMLElement &registry);
