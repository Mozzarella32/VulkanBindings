#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"

#include <cstddef>
#include <functional>
#include <optional>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

struct StructInfo;

struct StructTemplateInstanceInfo {
  private:
    Depends depends;
    std::string type;

  public:
    StructTemplateInstanceInfo(Depends depends, std::string type)
        : depends(std::move(depends)), type(std::move(type)) {}

    [[nodiscard]] auto getDepends() const -> const Depends &;
    [[nodiscard]] auto isInstance(std::string_view prefix) const -> bool;

    auto operator<(const StructTemplateInstanceInfo &other) const -> bool;

    void writeAssert(CppGenerator &gen) const;
    void writeDecl(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;

    friend StructInfo;
    friend ObjectInfo;
};

struct StructMember;

struct StructInfo {
    struct FunctionWithBody : public Function {
        std::string body;
    };

  private:
    std::vector<FunctionWithBody> functions;

    int rank;
    std::string name;
    std::string originalName;
    std::vector<StructMember> members;
    Depends depends;
    std::optional<std::string> deprecated;
    bool isUnion : 1;

  public:
    [[nodiscard]] auto getDepends() const -> const Depends &;
    [[nodiscard]] auto getName() const -> const std::string &;
    [[nodiscard]] auto getMembers() const -> const std::vector<StructMember> &;
    [[nodiscard]] auto hasFunctions() const -> bool;
    [[nodiscard]] auto hasMembers() const -> bool;
    [[nodiscard]] static auto isPfnStruct(const std::unordered_set<std::string> &pfnStruct)
        -> std::function<bool(StructInfo)>;

    auto operator<(const StructInfo &other) const -> bool;

    void writeHeader(CppGenerator &gen) const;
    void writeForward(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
    void writeAssert(CppGenerator &gen) const;

    static auto parseAllStructs(Registry registry) -> const std::unordered_set<std::string> &;
    static auto parseAllUnions(Registry registry) -> const std::unordered_set<std::string> &;
    static auto parseStructInfosAndTemplateInstantiations(Registry registry)
        -> const std::tuple<std::set<StructInfo>, std::set<StructTemplateInstanceInfo>> &;

    friend StructMember;
};

struct StructMember : public TypeAndName {
  private:
    std::string value;
    std::string len;
    std::string vulkanName;
    std::string accessor; // for size and alignment(.size)
    std::string offsetOf;
    std::optional<std::string> deprecated;
    std::optional<size_t> arrayWithLengthOf;
    bool optional : 1 = false;
    bool removed : 1 = false;

  public:
    StructMember() = default;

    StructMember(TypeAndName &&typeAndName);

    friend StructInfo;
};
