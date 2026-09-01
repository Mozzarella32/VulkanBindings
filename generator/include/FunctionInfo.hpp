#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "Registry.hpp"

#include <cstdint>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

struct FunctionLevels;

struct FunctionInfo {
  public:
    enum class Level : std::uint8_t { Exported, Global, Instance, Device };

  private:
    std::string handle;
    Function function;
    Depends depends;
    int rank = 0;
    Level level = Level::Device;
    std::optional<std::string> deprecated;

  public:
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

    [[nodiscard]] auto getDepends() const -> const Depends &;
    [[nodiscard]] auto getFunction() const -> const Function &;

    auto operator<(const FunctionInfo &other) const -> bool;

    FunctionInfo() = default;
    FunctionInfo(Function function);

    struct SignaturePrep {
        Function decl;
        Function mapping;
        enum class Type : std::uint8_t {
            Normal,
            Allocate,
            Create,
            CreateResult,
            CreateResultVec,
            Get,
            GetResult,
            GetResultVec2,
            GetObjectResultVec,
            GetCalibratedTimestampsKHR,
            GetVecFromSize,
            OpaqueCaptureData,
        } type = Type::Normal;
        Function::Argument nowReturn;
        Function::Argument additional;
    };

    [[nodiscard]] auto prepareSignature() const -> SignaturePrep;

    void writeFunctionPointerDecl(CppGenerator &gen) const;
    void writeFunctionPointerObjectDecl(CppGenerator &gen) const;
    void writeFunctionPointerObjectImpl(CppGenerator &gen) const;
    void writeFunctionPointerMember(CppGenerator &gen) const;
    void writeLoadGlobal(CppGenerator &gen) const;
    void writeLoadInstance(CppGenerator &gen) const;
    void writeLoadDevice(CppGenerator &gen) const;

    void writeHeader(CppGenerator &gen) const;
    void writeImpl(CppGenerator &gen) const;

    static auto getFunctionPtrsStructs(Registry registry) -> std::unordered_set<std::string>;
    static auto parseFunctionPtrs(Registry registry) -> std::set<FunctionInfo>;
    static auto parseGroupedFunctions(Registry registry)
        -> const std::unordered_map<std::string, std::set<FunctionInfo>> &;
    static auto parseDestroyFunctions(Registry registry)
        -> const std::unordered_map<std::string, FunctionInfo> &;

  private:
    static void renameArgs(Function &function);
    static auto generateMapping(const Function &function, FunctionInfo::Level level) -> Function;

    static void translateDeclTypes(Function &decl);

    static void generateDeclName(Function &decl, const std::string &handle);

    static auto generateDecl(const Function &function, const std::string &handle) -> Function;

    static auto VEC(std::string_view type, std::string_view len) -> std::string;
    static auto parseVEC(std::string_view str)
        -> std::optional<std::tuple<std::string, std::string>>;

    static auto parseAssignableHandle(std::string_view str) -> std::optional<std::string>;

    static auto mapCArray(Function::Argument &declArg, std::string &mappingArgName);
    static auto mapUnionStructPtrToRef(Function::Argument &declArg, std::string &mappingArgName);
    static void mapFirstArgHandle(Function &decl, std::string &mappingName,
                                  const std::string &handle);
    static auto mapArgs(Function &decl, Function &mapping, const std::string &handle);

    static auto namePfn(const Function &function) -> std::tuple<std::string, std::string>;

  public:
    friend FunctionLevels;
};

struct FunctionLevels {
    FunctionInfo getInstanceProcAddr;
    std::set<FunctionInfo> exported;
    std::set<FunctionInfo> global;
    std::set<FunctionInfo> instance;
    std::map<std::string, std::set<FunctionInfo>> device;
    static auto parseFunctionLevels(Registry registry) -> const FunctionLevels &;
};
