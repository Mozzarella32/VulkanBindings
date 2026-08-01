#pragma once

#include "CppGenerator.hpp"
#include "FunctionInfo.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>

struct ObjectInfo {
    std::string name;
    std::string objectType;
    Depends depends;
    Function destroyFunction;
    std::set<FunctionInfo> functions;
    int rank;
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

    static std::unordered_map<std::string, std::string> enumElementMapping;

  public:
    auto operator<(const ObjectInfo &other) const -> bool;
    void writeHeader(CppGenerator &gen) const;
    void writeHandle(CppGenerator &gen) const;
    void writeForwardDecl(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
    void writeTemplateImpl(CppGenerator &gen) const;

    void writeHandleToObjectTypeDecl(CppGenerator &gen) const;
    void writeObjectTypeImpl(CppGenerator &gen) const;
    void writeObjectToHandleImpl(CppGenerator &gen) const;
    void writeHandleToObjectImpl(CppGenerator &gen) const;
};

extern auto parseObjectInfos(tinyxml2::XMLElement &registry) -> const std::set<ObjectInfo> &;
