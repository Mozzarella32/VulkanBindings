#pragma once

#include "CppGenerator.hpp"
#include "FunctionInfo.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>

struct ObjectInfo {
    std::string name;
    std::string objectType;
    Depends depends;
    Function destroyFunction;
    std::set<FunctionInfo> functions;
    std::set<FunctionInfo> staticFunctions;
    int rank;
    std::string owner;

  public:
    bool operator<(const ObjectInfo &other) const;
    static void writeHeader(CppGenerator &gen, const ObjectInfo &info);
    static void writeForwardDecl(CppGenerator &gen, const ObjectInfo &info);
    static void writeImpl(CppGenerator &gen, const ObjectInfo &info);

    static void writeObjectTypes(CppGenerator &gen, const ObjectInfo &info);
};

extern const std::set<ObjectInfo> &parseObjectInfos(tinyxml2::XMLElement &registry);
