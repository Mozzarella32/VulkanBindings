#include "FunctionInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"
#include "StructInfo.hpp"
#include "XmlUtils.hpp"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <format>
#include <iterator>
#include <map>
#include <optional>
#include <queue>
#include <ranges>
#include <set>
#include <stdexcept>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace tinyxml2;

std::unordered_map<std::string, std::string> FunctionInfo::handleOwner;
std::unordered_set<std::string> FunctionInfo::handleHasFunctions;
std::unordered_map<std::string, FunctionInfo> FunctionInfo::destroyFunctions;
std::unordered_set<std::string> FunctionInfo::allEnums;
std::unordered_set<std::string> FunctionInfo::allEnumFlags;
std::unordered_set<std::string> FunctionInfo::allStructs;
std::unordered_set<std::string> FunctionInfo::allUnions;
std::unordered_map<std::string, std::string> FunctionInfo::enumZeroElements;
std::unordered_map<std::string, std::string> FunctionInfo::enumSizeTypes;
std::unordered_map<std::string, std::string> FunctionInfo::baseTypeMapping;
std::unordered_map<std::string, std::string> FunctionInfo::alias;

[[nodiscard]] auto FunctionInfo::getDepends() const -> const Depends & { return depends; }
[[nodiscard]] auto FunctionInfo::getFunction() const -> const Function & { return function; }

auto FunctionInfo::operator<(const FunctionInfo &other) const -> bool {
    bool notIsStatic = !function.isStatic;
    bool otherNotIsStatic = !other.function.isStatic;
    return std::tie(rank, notIsStatic, depends, function.name, function.isConst) <
           std::tie(other.rank, otherNotIsStatic, other.depends, other.function.name,
                    other.function.isConst);
}
FunctionInfo::FunctionInfo(Function function) : function(std::move(function)) {}

namespace {
auto removeP(std::string str) -> std::string {
    if (str.at(0) != 'p') {
        return str;
    }
    str = str.substr(1);
    str.at(0) = static_cast<char>(std::tolower(str.at(0)));
    return str;
};

[[nodiscard]] auto removeAssert(const std::string &str, std::string_view toRemove) -> std::string {
    assert(str.starts_with(toRemove));
    return str.substr(toRemove.size());
}

[[nodiscard]] auto removeIfStarts(const std::string &str, std::string_view toRemove)
    -> std::string {
    if (!str.starts_with(toRemove)) {
        return str;
    }
    return str.substr(toRemove.size());
}

[[nodiscard]] auto firstToLower(std::string str) -> std::string {
    str.at(0) = static_cast<char>(std::tolower(str.at(0)));
    return str;
}

auto isHandle(const std::string &str, bool strHasVk = false) -> bool {
    if (!strHasVk) {
        return FunctionInfo::handleOwner.contains("Vk" + str);
    }
    return FunctionInfo::handleOwner.contains(str);
}

auto hasFunctions(const std::string &str, bool strHasVk = false) -> bool {
    if (strHasVk) {
        return FunctionInfo::handleHasFunctions.contains(removeIfStarts(str, "Vk"));
    }
    return FunctionInfo::handleHasFunctions.contains(str);
}

auto isStruct(const std::string &str, bool strHasVk = false) -> bool {
    if (!strHasVk) {
        return FunctionInfo::allStructs.contains("Vk" + str);
    }
    return FunctionInfo::allStructs.contains(str);
}

auto isUnion(const std::string &str, bool strHasVk = false) -> bool {
    if (!strHasVk) {
        return FunctionInfo::allUnions.contains("Vk" + str);
    }
    return FunctionInfo::allUnions.contains(str);
}

auto isEnumFlag(const std::string &str, bool strHasVk = false) -> bool {
    if (strHasVk) {
        return FunctionInfo::allEnumFlags.contains(removeIfStarts(str, "Vk"));
    }
    return FunctionInfo::allEnumFlags.contains(str);
}

auto isEnum(const std::string &str, bool strHasVk = false) -> bool {
    if (strHasVk) {
        return FunctionInfo::allEnums.contains(removeIfStarts(str, "Vk"));
    }
    return FunctionInfo::allEnums.contains(str);
}

auto translateType(std::string baseType) -> std::string {
    if (auto iter = FunctionInfo::alias.find(baseType); iter != FunctionInfo::alias.end()) {
        baseType = iter->second;
    }
    if (isEnum(baseType, true)) {
        return EnumInfo::getEnumName(removeIfStarts(baseType, "Vk"));
    }
    if (isEnumFlag(baseType, true) || isStruct(baseType, true) || isUnion(baseType, true)) {
        return removeIfStarts(baseType, "Vk");
    }
    if (auto iter = FunctionInfo::baseTypeMapping.find(baseType);
        iter != FunctionInfo::baseTypeMapping.end()) {
        return iter->second;
    }
    if (FunctionInfo::handleOwner.contains(baseType)) {
        return removeIfStarts(baseType, "Vk");
    }
    return baseType;
};
} // namespace

void FunctionInfo::renameArgs(Function &function) {
    static const std::unordered_map<std::string_view, std::string_view> renames = {
        {"fd", "fileDescriptor"}};

    std::ranges::for_each(function.args, [](auto &arg) {
        if (auto iter = renames.find(arg.name); iter != renames.end()) {
            arg.name = iter->second;
        }
    });
}

auto FunctionInfo::generateMapping(const Function &function, FunctionInfo::Level level)
    -> Function {
    Function mapping = function;

    renameArgs(mapping);
    mapping.name = removeAssert(mapping.name, "vk");
    mapping.name = firstToLower(mapping.name);

    using enum FunctionInfo::Level;
    switch (level) {
    case Exported:
        // mapping.name =

        break;
    case Global:
        mapping.name = "impl_Loader::" + mapping.name;

        break;
    case Instance:
        mapping.name = mapping.name;
        mapping.objectIsPointer = false;
        mapping.objectName = "getInstanceTable()";
        break;
    case Device:
        mapping.name = mapping.name;
        mapping.objectIsPointer = false;
        mapping.objectName = "getDeviceTable()";
        break;
    }

    return mapping;
}

void FunctionInfo::translateDeclTypes(Function &decl) {
    for (auto &arg : decl.args) {
        if (FunctionInfo::handleOwner.contains(arg.baseType)) {
            // not optional ptr arg to const ref
            if (!arg.arrayWithLengthOf && arg.postType != "*") {
                assert(arg.leading.empty() && arg.postType.empty() && arg.trailing.empty());
                arg.leading = "const";
                arg.postType = "&";
            }
        }
        arg.baseType = translateType(arg.baseType);
    }

    decl.returnType = translateType(decl.returnType);
}

void FunctionInfo::generateDeclName(Function &decl, const std::string &handle) {
    decl.name = removeAssert(decl.name, "vk");
    decl.name = removeIfStarts(decl.name, "Cmd");

    // remove handle from name
    if (!handle.empty() && decl.name != "DestroyInstance" && decl.name != "DestroyDevice") {
        auto handleWithoutVk = removeAssert(handle, "Vk");
        if (auto iter = decl.name.find(handleWithoutVk); iter != std::string::npos) {
            decl.name.erase(iter, handleWithoutVk.size());
        }
    }

    decl.name = firstToLower(decl.name);
}

auto FunctionInfo::generateDecl(const Function &function, const std::string &handle) -> Function {
    Function decl = function;

    renameArgs(decl);
    generateDeclName(decl, handle);
    translateDeclTypes(decl);

    return decl;
}

constinit const std::string_view vecPrefix = "VEC{";
constinit const std::string_view vecSuffix = "}";
constinit const char vecMiddel = '|';

auto FunctionInfo::VEC(std::string_view type, std::string_view len) -> std::string {
    return std::format("{}{}{}{}{}", vecPrefix, type, vecMiddel, len, vecSuffix);
}

auto FunctionInfo::parseVEC(std::string_view str)
    -> std::optional<std::tuple<std::string, std::string>> {
    if (!str.starts_with(vecPrefix) || !str.ends_with(vecSuffix)) {
        return std::nullopt;
    }

    str.remove_prefix(vecPrefix.size());
    str.remove_suffix(vecSuffix.size());

    auto barPos = str.find(vecMiddel);
    if (barPos == std::string_view::npos) {
        return std::nullopt;
    }

    const std::string_view type = str.substr(0, barPos);
    const std::string_view len = str.substr(barPos + 1);

    if (type.empty() || len.empty()) {
        return std::nullopt;
    }

    return std::make_tuple(std::string(type), std::string(len));
}

auto FunctionInfo::parseAssignableHandle(std::string_view str) -> std::optional<std::string> {
    static constinit const std::string_view prefix = "impl_Struct::AssignableHandle<";
    static constinit const std::string_view suffix = ">";
    if (!str.starts_with(prefix) || !str.ends_with(suffix)) {
        return std::nullopt;
    }

    str.remove_prefix(prefix.length());
    str.remove_suffix(suffix.length());

    if (str.empty()) {
        return std::nullopt;
    }

    return std::string(str);
}

auto FunctionInfo::mapCArray(Function::Argument &declArg, std::string &mappingArgName) {
    if (declArg.leading != "const" || declArg.optional || declArg.trailing.empty() ||
        declArg.trailing.front() != '[' || declArg.trailing.back() != ']') {
        return;
    }

    const auto nStr = declArg.trailing.substr(1, declArg.trailing.size() - 2);
    assert(!nStr.empty() && std::ranges::all_of(nStr, ::isdigit));
    const size_t arraySize = std::stoul(nStr);

    declArg.baseType = std::format("std::array<{}, {}>", declArg.baseType, arraySize);
    declArg.trailing.clear();
    declArg.postType = "&";
    mappingArgName = std::format("{}.data()", removeP(mappingArgName));
}

auto FunctionInfo::mapUnionStructPtrToRef(Function::Argument &declArg,
                                          std::string &mappingArgName) {
    if (declArg.leading == "const" && declArg.postType == "*" &&
        (isStruct(declArg.baseType) || isUnion(declArg.baseType)) && !declArg.optional) {
        declArg.postType = "&";
        declArg.name = removeP(declArg.name);
        mappingArgName = std::format("(&{})", removeP(mappingArgName));
    }
}

void FunctionInfo::mapFirstArgHandle(Function &decl, std::string &mappingName,
                                     const std::string &handle) {
    if (handle.empty()) {
        return;
    }
    assert(!decl.args.empty());
    assert(decl.args.at(0).baseType == handle.substr(2));
    decl.deleteArg(0);
    mappingName = "getHandle()";
}

auto FunctionInfo::mapArgs(Function &decl, Function &mapping, const std::string &handle) {
    // Combine Length and Data
    std::map<size_t, size_t> argsToDelete;
    for (size_t i = 0; i < decl.args.size(); i++) {
        auto &arg = decl.args.at(i);
        if (!arg.arrayWithLengthOf.has_value()) {
            continue;
        }
        if (!argsToDelete.contains(arg.arrayWithLengthOf.value())) {
            argsToDelete[arg.arrayWithLengthOf.value()] = i;
        }

        const auto &lenArg = decl.args.at(arg.arrayWithLengthOf.value());

        if (arg.baseType == "void") { // POD
            arg.name = removeP(arg.name);
            mapping.replaceArg(i, std::format("{}.data()", arg.name));
            arg.baseType = std::format("impl_Struct::POD<{}>", lenArg.baseType);
            arg.postType = "&";
        } else if (arg.postType == "*") { // VEC
            arg.name = removeP(arg.name);
            if (isHandle(arg.baseType)) { // VEC of AssignableHandle
                if (arg.leading == "const") {
                    mapping.replaceArg(i,
                                       std::format("reinterpret_cast<const Handle::{}*>({}.data())",
                                                   arg.baseType, arg.name));
                } else {
                    mapping.replaceArg(i, std::format("reinterpret_cast<Handle::{}*>({}.data())",
                                                      arg.baseType, arg.name));
                }
                arg.baseType = std::format("impl_Struct::AssignableHandle<{}>", arg.baseType);
            } else { // VEC
                mapping.replaceArg(i, std::format("{}.data()", arg.name));
            }
            arg.baseType = VEC(arg.baseType, lenArg.baseType);
            arg.postType = "&";
        }
    }

    for (auto [idx, replace] : argsToDelete | std::views::reverse) {
        if (mapping.args.at(idx).baseType != "size_t") {
            mapping.replaceArg(idx, std::format("static_cast<{}>({}.size())",
                                                translateType(mapping.args.at(idx).baseType),
                                                decl.args.at(replace).name));
        } else {
            mapping.replaceArg(idx, std::format("{}.size()", decl.args.at(replace).name));
        }
        decl.args.erase(decl.args.begin() +
                        static_cast<decltype(decl.args)::iterator::difference_type>(idx));
    }

    for (size_t i = 0; i < decl.args.size(); i++) {
        auto &declArg = decl.args.at(i);
        auto &mappingArg = mapping.args.at(i);
        mapUnionStructPtrToRef(declArg, mappingArg.name);
        mapCArray(declArg, mappingArg.name);
    }

    mapFirstArgHandle(decl, mapping.args.at(0).name, handle);
}

auto FunctionInfo::prepareSignature() const -> FunctionInfo::SignaturePrep {
    SignaturePrep out;
    out.decl = function;
    out.mapping = generateMapping(function, level);
    out.decl = generateDecl(function, handle);

    mapArgs(out.decl, out.mapping, handle);

    auto prepareReturnVec = [](Function::Argument &arg) -> void {
        if (auto optVec = parseVEC(arg.baseType); optVec) {
            auto [type, _] = optVec.value();
            arg.baseType = std::move(type);
            static const std::string assignable = "impl_Struct::AssignableHandle<";
            if (arg.baseType.starts_with(assignable)) {
                arg.baseType.erase(0, assignable.size());
                arg.baseType = arg.baseType.substr(0, arg.baseType.size() - 1);
            }
            arg.baseType = std::format("std::vector<{}>", arg.baseType);
        }
        if (arg.baseType.starts_with("impl_Struct::POD")) {
            arg.baseType = "std::vector<std::byte>";
        }
    };

    auto prepArgs = [](Function &fun) -> void {
        for (auto &arg : fun.args) {
            if (auto optVec = parseVEC(arg.baseType); optVec) {
                auto [type, _] = optVec.value();
                arg.baseType = std::format("impl_Struct::ArrayProxy<{}>", type);
            }
        }
    };

    if (out.decl.args.size() >= 2) {
        for (size_t i = 0; i < out.decl.args.size() - 1; i++) {
            if (out.decl.args.at(i).name == "data" && out.decl.args.at(i + 1).name == "stride") {
                prepareReturnVec(out.decl.args.at(i));
            }
        }
    }

    static const std::unordered_set<std::string> ignorList{
        "getExternalComputeQueueDataNV", "getDescriptorEXT", "getDescriptorSetHostMappingVALVE",
        "getQueryPoolResults", "getLatencyTimingsLegacyNV"};

    if (out.decl.name == "getCalibratedTimestampsKHR") {
        assert(out.decl.args.size() == 3);
        assert(out.decl.returnType == "Result");

        out.nowReturn = out.decl.args.at(1);
        out.additional = out.decl.args.at(2);

        out.additional.name = removeP(out.additional.name);

        prepareReturnVec(out.nowReturn);
        prepareReturnVec(out.additional);
        out.decl.deleteArg(2);
        out.decl.deleteArg(1);

        out.decl.replaceReturnType(std::format("std::expected<std::tuple<{}, {}>, Result>",
                                               out.nowReturn.baseType, out.additional.baseType));

        out.type = SignaturePrep::Type::GetCalibratedTimestampsKHR;
        prepArgs(out.decl);
        return out;
    }
    auto vecOpt = [&]() -> std::optional<std::string> {
        if (out.decl.args.empty())
            return std::nullopt;
        return out.decl.args.back().baseType;
    }()
                               .and_then([](const auto &baseType) { return parseVEC(baseType); });

    if (out.decl.name == "getDescriptorEXT" ||
        out.decl.name == "getRayTracingCaptureReplayShaderGroupHandlesKHR" ||
        out.decl.name == "getAccelerationStructureHandleNV" ||
        out.decl.name == "getRayTracingShaderGroupHandlesKHR" ||
        out.decl.name == "getDataGraphPipelinePropertiesARM") {
        // assert(out.decl.returnType == "void");

        out.nowReturn = out.decl.args.back();
        prepareReturnVec(out.nowReturn);

        prepareReturnVec(out.nowReturn);
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.addArg(out.decl.args.size(), Function::Argument{TypeAndName{.name = "size",
                                                                             .baseType = "size_t",
                                                                             .leading = "",
                                                                             .postType = "",
                                                                             .trailing = ""},
                                                                 std::nullopt, false});

        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::GetVecFromSize;
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.name.contains("OpaqueCaptureData")) {
        assert(out.decl.args.size() == 2);
        assert(out.decl.returnType == "Result");

        out.nowReturn = out.decl.args.at(1);
        prepareReturnVec(out.nowReturn);
        out.decl.deleteArg(1);

        out.additional = out.decl.args.at(0);

        out.decl.replaceReturnType(
            std::format("std::expected<{}, Result>", out.nowReturn.baseType));

        out.type = SignaturePrep::Type::OpaqueCaptureData;
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.name.starts_with("mapMemory")) {
        assert(out.decl.returnType == "Result");
        assert(out.decl.args.back().name == "ppData");

        out.nowReturn = out.decl.args.back();
        out.decl.deleteArg(out.decl.args.size() - 1);

        out.decl.replaceReturnType("std::expected<void *, Result>");

        out.type = SignaturePrep::Type::GetResult;
        prepArgs(out.decl);
        return out;
    }
    if ((out.decl.name.starts_with("create") || out.decl.name.starts_with("register") ||
         out.decl.name == "allocateMemory" || out.decl.name == "getDrmDisplayEXT" ||
         out.decl.name == "acquirePerformanceConfigurationINTEL") &&
        handleOwner.contains("Vk" + out.decl.args.back().baseType)) {
        out.nowReturn = out.decl.args.back();
        if (out.nowReturn.baseType != "DisplayModeKHR") {
            out.nowReturn.baseType = "Unique" + out.nowReturn.baseType;
        }
        assert(out.decl.returnType == "Result");
        out.decl.replaceReturnType(
            std::format("std::expected<{}, Result>", out.nowReturn.baseType));

        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::CreateResult;
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.name.starts_with("allocate")) {
        out.nowReturn = out.decl.args.back();

        assert(out.decl.returnType == "Result");
        out.decl.replaceReturnType(
            std::format("std::expected<{}s, Result>", out.nowReturn.baseType));
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::Allocate;
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.name.starts_with("create") && vecOpt) {
        auto [type, _] = vecOpt.value();
        if (auto optHandle = parseAssignableHandle(type); optHandle) {
            type = optHandle.value();
        }
        assert(isHandle(type));
        assert(out.decl.returnType == "Result");

        std::string vecType = std::format("std::vector<Unique{}>", type);
        out.additional.baseType = std::format("std::vector<Handle::{}>", type);
        out.additional.name = std::format("{}Raw", out.decl.args.back().name);
        out.decl.replaceReturnType(std::format("std::expected<{}, Result>", vecType));
        out.nowReturn = out.decl.args.back();

        out.nowReturn.baseType = vecType;
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::CreateResultVec;
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.name.starts_with("get") && out.decl.returnType == "void" &&
        !out.decl.args.empty() && vecOpt) {
        out.nowReturn = out.decl.args.back();

        prepareReturnVec(out.nowReturn);
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::Get;
        prepArgs(out.decl);
        return out;
    }
    if ((!out.decl.name.starts_with("get") && !out.decl.name.starts_with("enumerate")) ||
        ignorList.contains(out.decl.name)) {
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.returnType == "void" && isHandle(out.decl.args.back().baseType)) {
        out.nowReturn = out.decl.args.back();

        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::Create;
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.returnType == "void") {
        out.nowReturn = out.decl.args.back();
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::Get;
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.returnType != "Result" || out.decl.args.back().baseType == "void" ||
        out.decl.name.contains("Status")) {
        prepArgs(out.decl);
        return out;
    }
    if (out.decl.args.back().baseType.starts_with("VEC") && out.decl.args.size() >= 2 &&
        out.decl.args.at(out.decl.args.size() - 2).baseType.starts_with("VEC") &&
        out.decl.name.starts_with("enumerate")) {
        out.nowReturn = out.decl.args.back();
        out.additional = out.decl.args.at(out.decl.args.size() - 2);
        prepareReturnVec(out.nowReturn);
        prepareReturnVec(out.additional);
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.deleteArg(out.decl.args.size() - 1);

        out.decl.replaceReturnType(std::format("std::expected<std::tuple<{}, {}>, Result>",
                                               out.nowReturn.baseType, out.additional.baseType));

        out.type = SignaturePrep::Type::GetResultVec2;
        prepArgs(out.decl);
        return out;
    }
    auto assignableHandleOpt = vecOpt.and_then([](const auto &tuple) {
        const auto &[type, _] = tuple;
        return parseAssignableHandle(type);
    });
    if (assignableHandleOpt && isHandle(assignableHandleOpt.value()) &&
        hasFunctions(assignableHandleOpt.value())) {
        out.additional.baseType = assignableHandleOpt.value();
        out.nowReturn = out.decl.args.back();
        prepareReturnVec(out.nowReturn);
        out.decl.deleteArg(out.decl.args.size() - 1);

        out.type = SignaturePrep::Type::GetObjectResultVec;
        out.decl.replaceReturnType(
            std::format("std::expected<{}, Result>", out.nowReturn.baseType));

        auto &lastName = out.mapping.args.back().name;
        lastName = lastName.substr(lastName.find('(') + 1, lastName.find(')') - lastName.find('('));

        out.nowReturn = out.nowReturn;
        prepArgs(out.decl);
        return out;
    }
    out.nowReturn = out.decl.args.back();
    prepareReturnVec(out.nowReturn);
    out.decl.deleteArg(out.decl.args.size() - 1);

    out.decl.replaceReturnType(std::format("std::expected<{}, Result>", out.nowReturn.baseType));

    out.nowReturn = out.nowReturn;
    out.type = SignaturePrep::Type::GetResult;
    prepArgs(out.decl);
    return out;
}

void FunctionInfo::writeFunctionPointerDecl(CppGenerator &gen) const {
    Function fptr = function;
    fptr.className = "";

    for (auto &arg : fptr.args) {
        if (handleOwner.contains(arg.baseType)) {
            arg.baseType = "Handle::" + translateType(arg.baseType);
        }
        arg.baseType = translateType(arg.baseType);
    }
    fptr.returnType = translateType(fptr.returnType);
    static const std::string pfn = "PFN_vk";
    if (auto iter = fptr.returnType.find(pfn); iter != std::string::npos) {
        fptr.returnType.erase(iter, pfn.size());
        fptr.returnType.insert(0, "PFN::");
    }
    fptr.name = removeIfStarts(fptr.name, "vk");

    gen.doWriteLine(
        std::format("using {} = {};", fptr.name, fptr.toModernFunctionPtr("VKAPI_PTR")));
}

auto FunctionInfo::namePfn(const Function &function) -> std::tuple<std::string, std::string> {
    const std::string name = removeIfStarts(function.name, "vk");
    return {name, firstToLower(name)};
}

void FunctionInfo::writeFunctionPointerObjectDecl(CppGenerator &gen) const {
    const auto &[name, pfn] = namePfn(function);
    gen.doWriteLine(std::format("extern PFN::{} {};", name, pfn));
}

void FunctionInfo::writeFunctionPointerObjectImpl(CppGenerator &gen) const {
    const auto &[name, pfn] = namePfn(function);
    gen.doWriteLine(std::format("PFN::{} {} = {{}};", name, pfn));
}

void FunctionInfo::writeFunctionPointerMember(CppGenerator &gen) const {
    const auto &[name, pfn] = namePfn(function);
    gen.doWriteLine(std::format("PFN::{} {};", name, pfn));
}

void FunctionInfo::writeLoadGlobal(CppGenerator &gen) const {
    const auto &[name, pfn] = namePfn(function);
    gen.doWriteLine(
        std::format("{} = reinterpret_cast<PFN::{}>(getInstanceProcAddr(nullptr, \"{}\"));", pfn,
                    name, function.name));
}

void FunctionInfo::writeLoadInstance(CppGenerator &gen) const {
    const auto &[name, pfn] = namePfn(function);
    gen.doWriteLine(
        std::format("table.{} = reinterpret_cast<PFN::{}>(getInstanceProcAddr(instance, \"{}\"));",
                    pfn, name, function.name));
}

void FunctionInfo::writeLoadDevice(CppGenerator &gen) const {
    const auto &[name, pfn] = namePfn(function);
    gen.doWriteLine(std::format("table.{} = "
                                "reinterpret_cast<PFN::{}>(instanceDispatcher.instanceTable."
                                "getDeviceProcAddr(device, \"{}\"));",
                                pfn, name, function.name));
}

namespace {
[[maybe_unused]] auto prepTypeToString(FunctionInfo::SignaturePrep::Type type) -> std::string {
    using enum FunctionInfo::SignaturePrep::Type;
    switch (type) {
    case Normal:
        return "Normal";
    case Allocate:
        return "Allocate";
    case Create:
        return "Create";
    case CreateResult:
        return "CreateResult";
    case CreateResultVec:
        return "CreateResultVec";
    case Get:
        return "Get";
    case GetResult:
        return "GetResult";
    case GetResultVec2:
        return "GetResultVec2";
    case GetObjectResultVec:
        return "GetObjectResultVec";
    case GetCalibratedTimestampsKHR:
        return "GetCalibratedTimestampsKHR";
    case GetVecFromSize:
        return "GetDescriptorEXT";
    case OpaqueCaptureData:
        return "OpaqueCaptureData";
    }
    std::unreachable();
};
} // namespace

void FunctionInfo::writeHeader(CppGenerator &gen) const {
    if (function.returnType.starts_with("PFN")) {
        return; // Loading Functions
    }

    auto decl = prepareSignature().decl;

    // For Debugging
    // auto prep = prepareSignature();
    // gen.doWriteLine("// " + prepTypeToString(prep.type));

    for (auto &arg : decl.args | std::views::reverse) {
        if (!arg.optional) {
            break;
        }
        if (arg.baseType.starts_with("impl_Struct::VecView") || isHandle(arg.baseType) ||
            isEnumFlag(arg.baseType) ||
            (arg.postType == "&" &&
             isStruct(arg.baseType))) { // vector need higher precedence than Flags
            arg.trailing += " = {}";
        } else if (isEnum(arg.baseType)) {
            arg.trailing += enumZeroElements.at(arg.baseType);
        } else if (arg.baseType == "uint32_t" && arg.postType.empty()) {
            arg.trailing += " = 0";
        } else {
            arg.trailing += " = nullptr";
        }
    }
    if (deprecated) {
        gen.doCode(std::format("\n[[deprecated(\"{}\")]]", deprecated.value()));
    }
    gen.doCode(decl.toSignature(true) + ";");
}

void FunctionInfo::writeImpl(CppGenerator &gen) const {
    if (function.returnType.starts_with("PFN")) {
        return; // Loading Functions
    }

    SignaturePrep prep = prepareSignature();
    gen.doLineBeginScope(prep.decl.toSignature());

    auto getDispatcherArg = [](const std::string &handle) -> std::string {
        if (handleHasFunctions.contains(handle)) {
            return ", getDispatcher()";
        }
        return "";
    };

    auto getAllocatorArg = [](const Function &fun) -> std::string {
        if (fun.args.back().baseType == "AllocationCallbacks") {
            return ", pAllocator";
        }
        return ", nullptr";
    };

    // For Debugging
    // gen.doWriteLine("// " + prepTypeToString(prep.type));
    // gen.doWriteLine("// original: " + function.toSignature());
    // gen.doWriteLine("// decl:     " + prep.decl.toSignature());
    // gen.doWriteLine("// mapping:  " + prep.mapping.toSignature());

    if (prep.type == SignaturePrep::Type::Normal) {
        const Function call = prep.mapping;
        if (call.returnType == "VkResult") {
            gen.doReturn(call.toCall());
        } else {
            gen.doWriteLine(call.toCallReturn() + ";");
        }
        gen.endScope();
        return;
    }

    if (prep.type == SignaturePrep::Type::Get) {
        const auto &getArg = prep.nowReturn;
        if (!getArg.baseType.starts_with("std::vector")) {
            gen.doWriteLine(std::format("{} {} = {};", getArg.baseType, getArg.name, "{}"));
            Function call = prep.mapping;
            std::string &lastName = call.args.back().name;
            lastName.insert(lastName.find(getArg.name), "&");
            gen.doWriteLine(call.toCall() + ";");
            gen.doReturn(getArg.name);
            gen.endScope();
            return;
        }
        Function call = prep.mapping;
        gen.doWriteLine(std::format("{} count = 0;", call.args.at(call.args.size() - 2).baseType));
        call.replaceArg(call.args.size() - 2, "&count");
        const std::string back = call.args.back().name;
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doWriteLine(call.toCall() + ";");
        gen.doWriteLine(std::format("{} {}(count);", getArg.baseType, getArg.name));
        call.replaceArg(call.args.size() - 1, back);
        gen.doWriteLine(call.toCall() + ";");
        gen.doWriteLine(std::format("{}.resize(count);", getArg.name));
        gen.doReturn(getArg.name);
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetResult) {
        const auto &getArg = prep.nowReturn;
        auto call = prep.mapping;
        if (!getArg.baseType.starts_with("std::vector")) {
            if (getArg.baseType == "void" && getArg.postType == "**") {
                gen.doWriteLine(std::format("void *{} = nullptr;", getArg.name));
                call.replaceArg(call.args.size() - 1, "&" + getArg.name);
            } else {
                gen.doWriteLine(std::format("{} {} = {};", getArg.baseType, getArg.name, "{}"));

                if (call.args.back().postType == "*") {
                    std::string &lastName = call.args.back().name;
                    lastName.insert(lastName.find(getArg.name), "&");
                }
            }
            gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                    CppGenerator::makeConditionNotOneOf("res", call.successcodes));
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
            gen.doReturn(getArg.name);
            gen.endScope();
            return;
        }
        if (!prep.decl.args.empty() &&
            prep.decl.args.begin()->baseType.starts_with("std::vector")) {
            gen.doWriteLine(std::format("{} {}({}.size())", getArg.baseType, getArg.name,
                                        prep.decl.args.begin()->name));
            gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                    CppGenerator::makeConditionNotOneOf("res", call.successcodes));
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
            gen.doReturn(getArg.name);
            gen.endScope();
            return;
        }
        gen.doWriteLine(call.args.at(call.args.size() - 2).baseType + " count = 0;");
        if (call.args.at(call.args.size() - 2).postType != "*") {
            gen.doWriteLine("// WARNING"); // TODO BEGIN HERE
            call.replaceArg(call.args.size() - 2, "count");
        } else {
            call.replaceArg(call.args.size() - 2, "&count");
        }
        const std::string back = call.args.back().name;
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                CppGenerator::makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(std::format("{} {}(count);", getArg.baseType, getArg.name));
        call.replaceArg(call.args.size() - 1, back);
        gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                CppGenerator::makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(std::format("{}.resize(count);", getArg.name));
        gen.doReturn(getArg.name);
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetObjectResultVec) {

        const auto &getArg = prep.nowReturn;
        auto call = prep.mapping;
        const auto &handle = prep.additional.baseType;
        gen.doWriteLine(std::format("{} count = 0;", call.args.at(call.args.size() - 2).baseType));
        call.replaceArg(call.args.size() - 2, "&count");
        const std::string back = call.args.back().name;
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                CppGenerator::makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(std::format("std::vector<Handle::{}> {}(count);", prep.additional.baseType,
                                    getArg.name));
        call.replaceArg(call.args.size() - 1, back);
        gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                CppGenerator::makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doCode(std::format(
            R"-(return {} |
       std::views::transform(
           [this](Handle::{} handle) -> {} {{
               return impl_Objects::Creator::create<{}>(handle{});
           }}) |
       std::ranges::to<std::vector>();
)-",
            getArg.name, prep.additional.baseType, handle, handle, getDispatcherArg(handle)));
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetResultVec2) {
        const auto &vec1 = prep.nowReturn;
        const auto &vec2 = prep.additional;
        Function call = prep.mapping;
        gen.doWriteLine(std::format("{} count = 0;", call.args.at(call.args.size() - 3).baseType));
        call.replaceArg(call.args.size() - 3, "&count");
        const std::string &back2 = call.args.at(call.args.size() - 2).name;
        const std::string &back = call.args.at(call.args.size() - 1).name;
        call.replaceArg(call.args.size() - 2, "nullptr");
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                CppGenerator::makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(std::format("{} {}(count);", vec1.baseType, vec1.name));
        gen.doWriteLine(std::format("{} {}(count);", vec2.baseType, vec2.name));
        call.replaceArg(call.args.size() - 2, back2);
        call.replaceArg(call.args.size() - 1, back);
        gen.doIfWithInitializer("const Result res = " + call.toCall(),
                                CppGenerator::makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(std::format("{}.resize(count);", vec1.name));
        gen.doWriteLine(std::format("{}.resize(count);", vec2.name));
        gen.doReturn(std::format("std::make_tuple({}, {})", vec1.name, vec2.name));
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::CreateResult) {
        const auto &createArgUnique = prep.nowReturn;
        auto createArg = prep.nowReturn;
        static constinit const std::string_view unique = "Unique";
        if (createArg.baseType.starts_with(unique)) {
            createArg.baseType = createArg.baseType.substr(unique.size());
        }
        gen.doWriteLine(std::format("Handle::{} {} = VK_BINDINGS_NULL_HANDLE;", createArg.baseType,
                                    createArg.name));

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + createArg.name);

        gen.doIfWithInitializer("const Result res = " + call.toCall(), "res != Result::Success");
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();

        if (!destroyFunctions.contains("Vk" + createArg.baseType)) {
            gen.doReturn(std::format("impl_Objects::Creator::create<{}>({})", createArg.baseType,
                                     createArg.name));
        } else if (createArg.baseType == "Instance") {
            gen.doWriteLine("const impl_Loader::Dispatcher empty;");
            gen.doReturn(std::format("impl_Objects::Creator::create<{}>(impl_Objects::Creator::"
                                     "create<{}>({}, empty){})",
                                     createArgUnique.baseType, createArg.baseType, createArg.name,
                                     getAllocatorArg(prep.decl)));
        } else if (createArg.baseType == "Device") {
            gen.doReturn(std::format("impl_Objects::Creator::create<{}>(impl_Objects::Creator::"
                                     "create<{}>({}, getDispatcher()){})",
                                     createArgUnique.baseType, createArg.baseType, createArg.name,
                                     getAllocatorArg(prep.decl)));
        } else if ((destroyFunctions.contains("Vk" + createArg.baseType) &&
                    destroyFunctions.at("Vk" + createArg.baseType).function.args.size() == 3) ||
                   prep.decl.name.starts_with("acquire") || prep.decl.name == "getDrmDisplayEXT") {
            gen.doReturn(std::format("impl_Objects::Creator::create<{}>(impl_Objects::Creator::"
                                     "create<{}>({}{}), getHandle(), getDispatcher(){})",
                                     createArgUnique.baseType, createArg.baseType, createArg.name,
                                     getDispatcherArg(createArg.baseType),
                                     getAllocatorArg(prep.decl)));
        } else {
            gen.doReturn(std::format("impl_Objects::Creator::create<{}>(impl_Objects::Creator::"
                                     "create<{}>({}{}){})",
                                     createArgUnique.baseType, createArg.baseType, createArg.name,
                                     getDispatcherArg(createArg.baseType),
                                     getAllocatorArg(prep.decl)));
        }
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::Allocate) {
        const auto &nowReturn = prep.nowReturn;
        const auto &handleName = nowReturn.baseType;
        auto handleNameSnailCase = nowReturn.baseType;
        handleNameSnailCase.at(0) = static_cast<char>(std::tolower(handleNameSnailCase.at(0)));

        auto firstWordLower = [](const std::string &str) -> std::string {
            size_t split = 0;
            for (size_t i = 1; i < str.size(); ++i) {
                if (std::isupper(str.at(i))) {
                    split = i;
                    break;
                }
            }
            std::string out = str.substr(0, split);
            out.at(0) = static_cast<char>(out.at(0));
            return out;
        };

        const auto &allocInfoName = prep.mapping.args.at(1).name;
        gen.doWriteLine(std::format("std::vector<Handle::{}> handles({}->{}Count);", handleName,
                                    allocInfoName, handleNameSnailCase));
        Function call = prep.mapping;
        call.replaceArg(2, "handles.data()");
        gen.doIfWithInitializer("const Result res = " + call.toCall(), "res != Result::Success");
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doReturn(std::format("impl_Objects::Creator::create<{}s>(std::move(handles), "
                                 "{}->{}Pool, getHandle(), getDispatcher())",
                                 handleName, allocInfoName, firstWordLower(handleNameSnailCase)));
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::Create) {
        const auto &nowReturn = prep.nowReturn;
        const auto &handleName = nowReturn.baseType;
        auto handleNameSnailCase = nowReturn.baseType;
        handleNameSnailCase.at(0) = static_cast<char>(std::tolower(handleNameSnailCase.at(0)));

        gen.doWriteLine(std::format("Handle::{} {} = VK_BINDINGS_NULL_HANDLE;", handleName,
                                    handleNameSnailCase));

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + handleNameSnailCase);
        gen.doWriteLine(call.toCall() + ";");

        gen.doReturn(std::format("impl_Objects::Creator::create<{}>({}{})", handleName,
                                 handleNameSnailCase, getDispatcherArg(handleName)));
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetCalibratedTimestampsKHR) {
        const auto &vec = prep.nowReturn;
        const auto &deviation = prep.additional;

        gen.doWriteLine(std::format("{} {} = 0;", deviation.baseType, deviation.name));
        gen.doWriteLine(
            std::format("{} {}({}.size());", vec.baseType, vec.name, prep.decl.args.at(0).name));

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + deviation.name);
        gen.doWriteLine(call.toCall() + ";");

        gen.doReturn(std::format("{{{{{}, {}}}}}", vec.name, deviation.name));
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetVecFromSize) {
        const auto &nowReturn = prep.nowReturn;

        gen.doWriteLine(std::format("{} {}(size);", nowReturn.baseType, nowReturn.name));
        const Function call = prep.mapping;
        gen.doWriteLine(prep.mapping.toCall() + ";");
        gen.doReturn(nowReturn.name);
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::OpaqueCaptureData) {
        const auto &nowReturn = prep.nowReturn;
        const auto &objects = prep.additional;

        gen.doWriteLine(std::format("{} datas({}.size());", nowReturn.baseType, objects.name));
        const Function call = prep.mapping;
        gen.doIfWithInitializer("const Result res = " + call.toCall(), "res != Result::Success");
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doReturn("datas");
        gen.endScope();
        return;
    }
    assert(prep.type == SignaturePrep::Type::CreateResultVec);
    const auto &additional = prep.additional;

    const auto &lengthIndexOpt =
        prep.mapping.args.at(prep.mapping.args.size() - 1).arrayWithLengthOf;
    assert(lengthIndexOpt);

    if (!lengthIndexOpt) {
        throw std::runtime_error("Unexpected empty optional");
    }

    gen.doWriteLine(std::format("{} {}{{{}}};", additional.baseType, additional.name,
                                prep.mapping.args.at(lengthIndexOpt.value()).name));
    Function call = prep.mapping;
    call.replaceArg(call.args.size() - 1, additional.name + ".data()");

    gen.doIfWithInitializer("const Result res = " + call.toCall(), "res != Result::Success");
    gen.doReturn("std::unexpected(res)");
    gen.doIfEnd();

    std::string type = additional.baseType
                           .substr(std::string("std::vector<").size(),
                                   additional.baseType.size() - std::string(">").size() -
                                       std::string("std::vector<").size())
                           .substr(std::string("Handle::").size());

    gen.doCode(std::format(R"-(return {0} |
       std::views::transform([this, &pAllocator](Handle::{1} handle) -> Unique{1} {{
           return impl_Objects::Creator::create<Unique{1}>(
               impl_Objects::Creator::create<{1}>(handle), getHandle(), getDispatcher(), pAllocator);
       }}) |
       std::ranges::to<std::vector>();)-",
                           additional.name, type));
    gen.endScope();
}

auto FunctionInfo::getFunctionPtrsStructs(Registry registry) -> std::unordered_set<std::string> {
    static std::unordered_set<std::string> pfnStructs;
    if (!pfnStructs.empty()) {
        return pfnStructs;
    }
    const auto &pfns = parseFunctionPtrs(registry);
    const auto &[structInfos, _] = StructInfo::parseStructInfosAndTemplateInstantiations(registry);
    std::queue<std::string> work;
    for (const auto &pfn : pfns) {
        for (const auto &arg : pfn.function.args) {
            if (!isStruct(arg.baseType, true)) {
                continue;
            }
            work.push(arg.baseType);
        }
    }

    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    for (const auto &structInfo : structInfos) {
        auto &pre = prerequisits[structInfo.getName()];
        pre.insert_range(structInfo.getMembers() |
                         std::views::transform([](const auto &member) { return member.baseType; }));
    }

    while (!work.empty()) {
        const std::string cur = work.front();
        work.pop();
        if (!isStruct(cur, true)) {
            continue;
        }
        pfnStructs.insert(cur);
        work.push_range(prerequisits.at(cur.substr(2)));
    }

    return pfnStructs;
}

auto FunctionInfo::parseFunctionPtrs(Registry registry) -> std::set<FunctionInfo> {
    static std::set<FunctionInfo> functionPtrInfos;
    if (!functionPtrInfos.empty()) {
        return functionPtrInfos;
    }

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");
    const std::unordered_map<std::string, Depends> &functionDepends =
        parseObjectDepents(registry, "type");

    std::vector<Function> functionPtrs;

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (HasAttribute(type, "alias")) {
            return;
        }
        if (!checkApi(type)) {
            return;
        }
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"funcpointer"})) {
            return;
        }

        XMLElement &proto = FirstChildElement(type, "proto");

        const std::string name = FirstChildElement(proto, "name").GetText();
        if (objectsDisabled.contains(name)) {
            return;
        }

        Function functionPtr;
        functionPtr.name = name;
        functionPtr.returnType = FirstChildElement(proto, "type").GetText();
        ForEach(type, "param", [&](XMLElement &param) -> void {
            if (!checkApi(param))
                return;
            Function::Argument arg = Function::Argument::fromTypeAndName(parseTypeAndName(param));
            static constinit const std::string_view pfn = "PFN_vk";
            if (auto iter = arg.baseType.find(pfn); iter != std::string::npos) {
                arg.baseType.erase(iter, pfn.size());
            }
            functionPtr.args.push_back(std::move(arg));
        });
        static constinit const std::string_view pfn = "PFN_vk";
        if (auto iter = functionPtr.name.find(pfn); iter != std::string::npos) {
            functionPtr.name.erase(iter, pfn.size());
        }
        if (auto iter = functionPtr.returnType.find(pfn); iter != std::string::npos) {
            functionPtr.returnType.erase(iter, pfn.size());
        }

        functionPtrs.push_back(std::move(functionPtr));
    });

    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    for (const auto &pfn : functionPtrs) {
        for (const auto &arg : pfn.args) {
            prerequisits[pfn.name].insert(arg.baseType);
        }
        prerequisits[pfn.name].insert(pfn.returnType);
    }

    std::unordered_set<std::string> toRemove;
    std::unordered_map<std::string, int> rank;
    int currentRank = 0;

    for (const auto &[_, pre] : prerequisits) {
        toRemove.insert_range(pre);
    }
    for (const auto &[name, _] : prerequisits) {
        toRemove.erase(name);
    }

    while (!toRemove.empty()) {

        for (const auto &key : toRemove) {
            rank[key] = currentRank;
        }
        currentRank += 1;

        std::ranges::for_each(prerequisits, [&](auto &pair) -> auto {
            std::erase_if(pair.second, [&](const std::string &requirement) -> bool {
                return toRemove.contains(requirement);
            });
        });
        toRemove.clear();

        for (const auto &[name, pre] : prerequisits) {
            if (pre.empty())
                toRemove.insert(name);
        }
        std::erase_if(prerequisits, [&](const auto &pair) -> auto { return pair.second.empty(); });
    }
    assert(prerequisits.empty());

    for (auto &&functionPtr : functionPtrs) {
        FunctionInfo info;
        info.function = std::move(functionPtr);
        if (auto iter = functionDepends.find(info.function.name); iter != functionDepends.end()) {
            info.depends = iter->second;
        }
        if (auto iter = rank.find(info.function.name); iter != rank.end()) {
            info.rank = iter->second;
        }

        functionPtrInfos.insert(std::move(info));
    }

    return functionPtrInfos;
}

auto FunctionLevels::parseFunctionLevels(Registry registry) -> const FunctionLevels & {
    using enum FunctionInfo::Level;

    static FunctionLevels functions;
    if (!functions.exported.empty())
        return functions;

    auto groupedFunctions = FunctionInfo::parseGroupedFunctions(registry);
    for (const auto &[handle, infos] : groupedFunctions) {
        for (const auto &info : infos) {
            if (info.function.getName() == "vkGetInstanceProcAddr") {
                functions.getInstanceProcAddr = info;
                functions.exported.insert(info);
                continue;
            }
            if (info.function.getName() == "vkGetDeviceProcAddr") {
                functions.instance.insert(info);
                continue;
            }
            switch (info.level) {
            case Exported:
                assert(false);
                break;
            case Global:
                functions.global.insert(info);
                break;
            case Instance:
                functions.instance.insert(info);
                break;
            case Device:
                functions.device[handle].insert(info);
                break;
            }
        }
    }
    return functions;
}

auto FunctionInfo::parseGroupedFunctions(Registry registry)
    -> std::unordered_map<std::string, std::set<FunctionInfo>> {
    static std::unordered_map<std::string, std::set<FunctionInfo>> groupedFunctions;
    if (!groupedFunctions.empty())
        return groupedFunctions;
    const std::unordered_map<std::string, std::string> &handles = parseHandles(registry);
    std::vector<Function> functions;
    std::unordered_map<std::string, std::string> deprecated;

    const auto &enumElementMappings = EnumInfo::getEnumElementMapping(registry);
    const std::unordered_set<std::string> objectsDisabled =
        parseObjectsDisabled(registry, "command");

    const auto &handleParents = parseHandles(registry);

    auto isDescendant = [&](const std::string &name, const std::string &base) -> bool {
        if (name == base)
            return true;
        auto cur = name;
        std::unordered_set<std::string> visited;
        while (!cur.empty()) {
            if (cur == base)
                return true;
            if (visited.contains(cur))
                break; // avoid cycles
            visited.insert(cur);
            auto iter = handleParents.find(cur);
            if (iter == handleParents.end())
                break;
            cur = iter->second;
        }
        return false;
    };

    const auto &vendorTags = parseVendorTags(registry);

    auto processing =
        std::views::split(',') | std::views::transform([](auto subr) -> auto {
            return std::string(std::ranges::begin(subr), std::ranges::end(subr));
        }) |
        std::views::transform(
            [&](const std::string &token) -> std::string { // This is a very hacky way to resolve
                                                           // aliases of the VkResult enum elements
                std::string token_mut = token;
                if (auto iter = enumElementMappings.find(token);
                    iter != enumElementMappings.end()) {
                    return "Result::" + iter->second;
                }
                for (const auto &tag : vendorTags) {
                    if (token_mut.ends_with(tag)) {
                        token_mut = token_mut.substr(0, token.size() - tag.size() - 1);
                    }
                }
                return "Result::" + enumElementMappings.at(token_mut);
            }) |
        std::ranges::to<std::vector<std::string>>();

    XMLElement &commands = FirstChildElement(registry.getActive(), "commands");
    ForEach(commands, "command", [&](XMLElement &command) -> void {
        if (HasAttribute(command, "alias"))
            return;
        if (!checkApi(command))
            return;
        XMLElement &proto = FirstChildElement(command, "proto");

        const std::string name = FirstChildElement(proto, "name").GetText();
        if (objectsDisabled.contains(name))
            return;

        functions.emplace_back();
        Function &function = functions.back();
        function.name = name;
        if (HasAttribute(command, "successcodes")) {
            function.successcodes = Attribute(command, "successcodes") | processing;
        }
        if (HasAttribute(command, "errorcodes")) {
            function.errorcodes = Attribute(command, "errorcodes") | processing;
        }
        if (HasAttribute(command, "supersededby")) {
            deprecated[function.name] = Attribute(command, "supersededby");
        }
        function.returnType = FirstChildElement(proto, "type").GetText();
        ForEach(command, "param", [&](XMLElement &param) -> void {
            if (!checkApi(param))
                return;
            Function::Argument arg = Function::Argument::fromTypeAndName(parseTypeAndName(param));
            if (HasAttribute(param, "len")) {
                const std::string lens = Attribute(param, "len");
                for (const auto &len : splitCSL(lens)) {
                    if (len != "null-terminated" && len != "1" && !len.contains("->") &&
                        !len.starts_with("latexmath")) {
                        auto iter = std::ranges::find_if(
                            function.args, [&len](const Function::Argument &arg) -> bool {
                                return arg.name == len;
                            });
                        assert(iter != function.args.end());
                        assert(!arg.arrayWithLengthOf);
                        arg.arrayWithLengthOf = std::distance(function.args.begin(), iter);
                    }
                }
            }
            if (HasAttribute(param, "optional")) {
                arg.optional = splitCSL(Attribute(param, "optional")).contains("true");
            }
            arg.name = FirstChildElement(param, "name").GetText();
            function.args.push_back(std::move(arg));
        });
    });

    XMLElement &extensions = FirstChildElement(registry.getActive(), "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        assert(HasAttribute(extension, "number"));
        ForEach(extension, "deprecate", [&](XMLElement &deprecate) -> void {
            if (HasAttribute(deprecate, "api") &&
                !splitCSL(Attribute(deprecate, "api")).contains("vulkan"))
                return;
            ForEach(deprecate, "command", [&](XMLElement &command) -> void {
                assert(HasAttribute(command, "name"));
                if (HasAttribute(command, "supersededby")) {
                    deprecated[Attribute(command, "name")] = Attribute(command, "supersededby");
                }
            });
        });
    });

    const std::unordered_map<std::string, Depends> &functionDepends =
        parseObjectDepents(registry, "command");

    for (const auto &function : functions) {
        assert(!function.args.empty());
        const std::string &handle = function.args.at(0).baseType;
        FunctionInfo functionInfo;
        functionInfo.function = function;
        if (auto iter = functionDepends.find(function.name); iter != functionDepends.end()) {
            functionInfo.depends = iter->second;
        }
        if (auto iter = deprecated.find(function.name); iter != deprecated.end()) {
            Function translation;
            translation.name = iter->second;
            generateDeclName(translation, handle);
            functionInfo.deprecated = "supersededby: " + translation.name;
        }
        if (handles.contains(handle)) {
            functionInfo.handle = handle;
            functionInfo.function.isConst = true;
            assert(handle.starts_with("Vk"));
            functionInfo.function.className = handle.substr(2);

            if (isDescendant(handle, "VkDevice")) {
                functionInfo.level = FunctionInfo::Level::Device;
            } else if (isDescendant(handle, "VkInstance")) {
                functionInfo.level = FunctionInfo::Level::Instance;
            } else {
                functionInfo.level = FunctionInfo::Level::Exported;
            }

            groupedFunctions[function.args.at(0).baseType].insert(functionInfo);
        } else {
            functionInfo.function.isStatic = true;
            functionInfo.function.className = "Instance";
            functionInfo.level = FunctionInfo::Level::Global;
            groupedFunctions[""].insert(functionInfo);
        }
    }

    return groupedFunctions;
}

auto FunctionInfo::parseDestroyFunctions(Registry registry)
    -> const std::unordered_map<std::string, FunctionInfo> & {
    static std::unordered_map<std::string, FunctionInfo> destroyFunctions;
    if (!destroyFunctions.empty())
        return destroyFunctions;

    const auto &groupedFunctions = parseGroupedFunctions(registry);
    const auto &vendorTags = parseVendorTags(registry);

    for (const auto &[_, functionInfos] : groupedFunctions) {
        for (const auto &functionInfo : functionInfos) {
            const auto &function = functionInfo.getFunction();
            if (function.name.starts_with("vkDestroy")) {
                if (function.args.size() == 2) { // VkDevice
                    destroyFunctions[function.args.at(0).baseType] = functionInfo;
                } else {
                    assert(function.name.starts_with("vkDestroy") && function.args.size() == 3);
                    destroyFunctions[function.args.at(1).baseType] = functionInfo;
                }
                continue;
            }
            if (function.name.starts_with("vkRelease") && function.args.size() == 2) {
                std::string_view baseName = function.args.at(1).baseType;
                baseName.remove_prefix(2);
                for (const auto &vendorTag : vendorTags) {
                    if (auto iter = baseName.find(vendorTag); iter != std::string::npos) {
                        baseName.remove_suffix(vendorTag.size());
                        break;
                    }
                }
                if (function.name.contains(baseName)) {
                    destroyFunctions[function.args.at(1).baseType] = functionInfo;
                }
            }
            if (function.name.starts_with("vkFree")) {
                if (function.name == "vkFreeMemory") {
                    destroyFunctions[function.args.at(1).baseType] = functionInfo;
                } else {
                    auto name = function.args.at(3).baseType.substr(2) + "s";
                    destroyFunctions[name] = functionInfo;
                }
                continue;
            }
        }
    }

    return destroyFunctions;
}
