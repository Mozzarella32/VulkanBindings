#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "FunctionInfo.hpp"
#include "Registry.hpp"

#include <set>
#include <string>
#include <unordered_map>

struct StructTemplateInstanceInfo;

struct ObjectInfo {
  private:
    std::string name;
    std::string objectType;
    Depends depends;
    Function destroyFunction;
    std::set<FunctionInfo> functions;
    int rank = 0;
    std::string owner;
    std::string templateType;
    std::string templateArgs; // With <>
    std::string templateTypeUnique;
    std::string templateArgsUnique; // With <>
    bool isDispatchable : 1 = false;
    bool hasInstanceFunctions : 1 = false;
    bool hasDeviceFunctions : 1 = false;
    bool isInstanceFunctionTableOwner : 1 = false;
    bool isDeviceFunctionTableOwner : 1 = false;

  public:
    static std::unordered_map<std::string, std::string> enumElementMapping;

    [[nodiscard]] auto getDepends() const -> const Depends &;
    [[nodiscard]] auto getName() const -> const std::string &;

    [[nodiscard]] auto hasFunctions() const -> bool;

    auto operator<(const ObjectInfo &other) const -> bool;
    void writeHeader(CppGenerator &gen) const;
    void writeHandle(CppGenerator &gen) const;
    void writeForwardDecl(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
    void writeTemplateDecl(CppGenerator &gen) const;
    void writeTemplateImpl(CppGenerator &gen) const;
    void writeCleanup(CppGenerator &gen) const;

    void writeObjectToObjectTypeDecl(CppGenerator &gen) const;
    void writeObjectToObjectTypeImpl(CppGenerator &gen) const;
    void writeObjectToHandle(CppGenerator &gen) const;
    void writeHandleToObject(CppGenerator &gen) const;
    void writeIsObject(CppGenerator &gen) const;
    void writeIsUnique(CppGenerator &gen) const;
    void writeIsPool(CppGenerator &gen) const;
    void writeHasDispatcher(CppGenerator &gen) const;

  private:
    static void setTemplate(ObjectInfo &info);

  public:
    static auto parseObjectInfos(Registry registry) -> const std::set<ObjectInfo> &;
    static auto parseObjectInfoStructTemplates(Registry registry)
        -> const std::set<StructTemplateInstanceInfo> &;
};
