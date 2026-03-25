#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <set>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>

struct FunctionInfo {
    std::string handle;
    Function function;
    Depends depends;

    static std::unordered_map<std::string, std::string> handleOwner;
    static std::unordered_map<std::string, Function> destroyFunctions;
    static std::unordered_set<std::string> allEnums;
    static std::unordered_set<std::string> allEnumFlags;
    static std::unordered_set<std::string> allStructs;
    static std::unordered_set<std::string> allUnions;
    static std::unordered_map<std::string, std::string> enumZeroElements;
    static std::unordered_map<std::string, std::string> enumSizeTypes;

    bool operator<(const FunctionInfo &other) const;

    struct SignaturePrep {
        Function decl;
        Function mapping;
        enum Type {
            Normal,
            Create,
            CreateVec,
            Get,
            GetResult,
            GetResultVec2,
        } type = Type::Normal;
        Function::Argument nowReturn;
        Function::Argument additional;
    };

    SignaturePrep prepareSignature() const;

    void writeFunctionPointer(CppGenerator &gen) const;

    void writeHeader(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
};

extern std::unordered_set<std::string> getFunctionPtrsStructs(tinyxml2::XMLElement &registry);
extern std::set<FunctionInfo> parseFunctionPtrs(tinyxml2::XMLElement &registry);
