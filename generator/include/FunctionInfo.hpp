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
    int rank = 0;

    enum class Level { Exported, Global, Instance, Device };

    Level level;

    static std::unordered_map<std::string, std::string> handleOwner;
    static std::unordered_set<std::string> handleHasFunctions;
    static std::unordered_map<std::string, FunctionInfo> destroyFunctions;
    static std::unordered_set<std::string> allEnums;
    static std::unordered_set<std::string> allEnumFlags;
    static std::unordered_set<std::string> allStructs;
    static std::unordered_set<std::string> allUnions;
    static std::unordered_map<std::string, std::string> enumZeroElements;
    static std::unordered_map<std::string, std::string> enumSizeTypes;
    static std::unordered_map<std::string, std::string> baseTypeMapping;
    static std::unordered_map<std::string, std::string> alias;

    auto operator<(const FunctionInfo &other) const -> bool;

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

    [[nodiscard]] auto prepareSignature() const -> SignaturePrep;

    void writeFunctionPointerDecl(CppGenerator &gen) const;
    void writeFunctionPointerObject(CppGenerator &gen) const;
    void writeFunctionPointerMember(CppGenerator &gen) const;
    void writeLoadGlobal(CppGenerator &gen) const;
    void writeLoadInstance(CppGenerator &gen) const;
    void writeLoadDevice(CppGenerator &gen) const;

    void writeHeader(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;
};

extern auto getFunctionPtrsStructs(tinyxml2::XMLElement &registry)
    -> std::unordered_set<std::string>;
extern auto parseFunctionPtrs(tinyxml2::XMLElement &registry) -> std::set<FunctionInfo>;

struct FunctionLevels {
    FunctionInfo getInstanceProcAddr;
    FunctionInfo getDeviceProcAddr;
    std::set<FunctionInfo> exported;
    std::set<FunctionInfo> global;
    std::set<FunctionInfo> instance;
    std::unordered_map<std::string, std::set<FunctionInfo>> device;
};

extern auto parseFunctionLevels(tinyxml2::XMLElement &registry) -> const FunctionLevels &;
