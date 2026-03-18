#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"

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

    static void writeHeader(CppGenerator &gen, const FunctionInfo &info,
                            bool staticMemberFunctions);

    static void writeImpl(CppGenerator &gen, const FunctionInfo &info,
                          const std::string &containingClass, bool staticMemberFunctions);
};
