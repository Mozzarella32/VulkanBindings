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
    bool isDispatchable : 1 = false;
    bool hasInstanceFunctions : 1 = false;
    bool hasDeviceFunctions : 1 = false;
    bool isInstanceFunctionTableOwner : 1 = false;
    bool isDeviceFunctionTableOwner : 1 = false;

    static std::unordered_map<std::string, std::string> enumElementMapping;

  public:
    bool operator<(const ObjectInfo &other) const;
    void writeHeader(CppGenerator &gen) const;
    void writeHandle(CppGenerator &gen) const;
    void writeForwardDecl(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
    void writeMethodImpl(CppGenerator &gen) const;

    void writeObjectTypes(CppGenerator &gen) const;
    void writeHandeType(CppGenerator &gen) const;
};

extern const std::set<ObjectInfo> &parseObjectInfos(tinyxml2::XMLElement &registry);
