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

    auto operator<(const StructTemplateInstanceInfo &other) const -> bool;

    void writeAssert(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
};

struct StructInfo {
    struct Member : public TypeAndName {
        auto operator=(TypeAndName &&tan) -> Member & {
            *static_cast<TypeAndName *>(this) = std::move(tan);
            return *this;
        }
        std::string value;
        std::string len;
        std::string vulkanName;
        std::string accessor; // for size and alignment(.size)
        std::string offsetOf;
        std::optional<size_t> arrayWithLengthOf;
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

    auto operator<(const StructInfo &other) const -> bool;

    void writeHeader(CppGenerator &gen) const;
    void writeForward(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
    void writeAssert(CppGenerator &gen) const;
};

extern auto parseAllStructs(tinyxml2::XMLElement &registry)
    -> const std::unordered_set<std::string> &;
extern auto parseAllUnions(tinyxml2::XMLElement &registry)
    -> const std::unordered_set<std::string> &;
extern auto parseStructInfosAndTemplateInstantiations(tinyxml2::XMLElement &registry)
    -> const std::tuple<std::set<StructInfo>, std::set<StructTemplateInstanceInfo>> &;
