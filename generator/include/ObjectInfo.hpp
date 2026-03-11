#pragma once

#include <set>
#include <string>

#include "CppGenerator.hpp"
#include "FunctionInfo.hpp"

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
