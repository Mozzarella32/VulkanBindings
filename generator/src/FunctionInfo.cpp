#include "FunctionInfo.hpp"
#include "CppGenerator.hpp"
#include "ParseXml.hpp"
#include "StructInfo.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <map>
#include <queue>
#include <ranges>
#include <set>
#include <string>
#include <unordered_set>

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

auto FunctionInfo::operator<(const FunctionInfo &other) const -> bool {
    bool notIsStatic = !function.isStatic;
    bool otherNotIsStatic = !other.function.isStatic;
    return std::tie(rank, notIsStatic, depends, function.name, function.isConst) <
           std::tie(other.rank, otherNotIsStatic, other.depends, other.function.name,
                    other.function.isConst);
}

auto FunctionInfo::prepareSignature() const -> FunctionInfo::SignaturePrep {
    SignaturePrep out;

    auto removeP = [](std::string str) -> std::string {
        if (str[0] != 'p')
            return str;
        str = str.substr(1);
        str[0] = static_cast<char>(std::tolower(str[0]));
        return str;
    };

    out.decl = function;

    out.mapping = function;
    std::string mappingName = out.mapping.name.substr(2);
    mappingName[0] = static_cast<char>(std::tolower(mappingName[0]));
    switch (level) {
    case Level::Exported:
        // out.mapping.name =

        break;
    case Level::Global:
        out.mapping.name = "impl_Loader::" + mappingName;

        break;
    case Level::Instance:
        out.mapping.name = mappingName;
        out.mapping.objectIsPointer = false;
        out.mapping.objectName = "dispatcher->instanceTable";
        break;
    case Level::Device:
        out.mapping.name = mappingName;
        out.mapping.objectIsPointer = false;
        out.mapping.objectName = "dispatcher->deviceTable";
        break;
    }

    assert(out.decl.name.substr(0, 2) == "vk");
    std::string name = out.decl.name.substr(2);
    if (name.starts_with("Cmd")) {
        name = name.substr(3);
    }

    if (handle != "") {
        auto handleWithoutVk = handle.substr(2);
        if (auto it = name.find(handleWithoutVk);
            it != std::string::npos && handleWithoutVk != "") {
            name.erase(it, handleWithoutVk.size());
        }
    }

    if (!name.empty())
        name[0] = static_cast<char>(std::tolower(name[0]));

    out.decl.replaceName(name);

    auto translateType = [&](std::string &baseType) -> void {
        if (auto it = alias.find(baseType); it != alias.end()) {
            baseType = it->second;
        }
        if (allEnums.contains(baseType.substr(2)) || allEnumFlags.contains(baseType.substr(2))) {
            baseType = baseType.substr(2);
        } else if (allStructs.contains(baseType) || allUnions.contains(baseType)) {
            baseType = baseType.substr(2);
        } else if (auto it = baseTypeMapping.find(baseType); it != baseTypeMapping.end()) {
            baseType = it->second;
        }
    };

    for (auto &arg : out.decl.args) {
        if (handleOwner.contains(arg.baseType)) {

            if (!arg.arrayWithLengthOf && arg.postType != "*") {
                assert(arg.leading == "" && arg.postType == "" && arg.trailing == "");
                arg.leading = "const";
                arg.baseType = arg.baseType.substr(2);
                arg.postType = "&";
            } else if (arg.arrayWithLengthOf) {
                arg.baseType = arg.baseType.substr(2);
            } else {
                arg.baseType = arg.baseType.substr(2);
            }
        }
        translateType(arg.baseType);
    }

    translateType(out.decl.returnType);
    std::map<size_t, size_t> argsToDelete;
    for (size_t i = 0; i < out.decl.args.size(); i++) {
        auto &arg = out.decl.args[i];
        if (!arg.arrayWithLengthOf.has_value())
            continue;
        if (!argsToDelete.contains(arg.arrayWithLengthOf.value())) {
            argsToDelete[arg.arrayWithLengthOf.value()] = i;
        }
        std::string baseType = arg.baseType;
        if (baseType == "void") {
            baseType = "uint8_t";
        }
        const auto &len = out.decl.args[arg.arrayWithLengthOf.value()];
        if (arg.postType == "*") {
            if (handleOwner.contains("Vk" + arg.baseType)) {
                baseType = "Handle::" + baseType;
            }
            arg.baseType = "impl_Struct::VecView<" + len.baseType + ", " + baseType + ">";
        } else {
            break;
            // assert(arg.postType == "* const*");
            // arg.baseType = "std::vector<const " + baseType + " *>";
        }
        arg.name = removeP(arg.name);
        arg.postType = "&";
        out.mapping.replaceArg(i, arg.name + ".data()");
        // assert(out.mapping.args[i].postType == "*");
        // out.mapping.args[i].postType = "";
    }

    for (auto [i, replace] : argsToDelete | std::views::reverse) {
        out.mapping.replaceArg(i, out.decl.args[replace].name + ".size()");
        out.decl.args.erase(out.decl.args.begin() +
                            static_cast<decltype(out.decl.args)::iterator::difference_type>(i));
    }

    // for (auto &arg : out.mapping.args) {
    // if (allStructs.contains(arg.baseType) || allUnions.contains(arg.baseType) ||
    //     allEnumFlags.contains(arg.baseType.substr(2)) ||
    //     allEnums.contains(arg.baseType.substr(2))) {
    //     arg.name = "std::bit_cast<" + arg.fullType() +
    //                (arg.trailing.starts_with("[") ? std::string("*") : std::string("")) +
    //                ">(" + arg.name + ")";
    // }
    // if (handleOwner.contains(arg.baseType) && arg.postType == "*") {
    //     arg.name = arg.name + "->rawHandlePtr()"; // TODO this is wrong
    // }
    // }

    if (handle != "") {
        assert(out.decl.args.size() >= 1);
        assert(out.decl.args[0].baseType == handle.substr(2));
        out.decl.deleteArg(0);
        out.mapping.replaceArg(0, "handle");
    }

    auto prepareReturnVec = [](Function::Argument &arg) -> void {
        static const std::string find = "impl_Struct::VecView";
        if (arg.baseType.starts_with(find)) {
            arg.baseType.erase(0, find.size());
            assert(arg.baseType.find(","));
            arg.baseType.erase(0, arg.baseType.find(",") + 2);
            arg.baseType = "std::vector<" + arg.baseType;
        }
    };

    if (out.decl.args.size() >= 2) {
        for (size_t i = 0; i < out.decl.args.size() - 1; i++) {
            if (out.decl.args[i].name == "data" && out.decl.args[i + 1].name == "stride") {
                prepareReturnVec(out.decl.args[i]);
            }
        }
    }

    static const std::unordered_set<std::string> ignorList{
        "getExternalComputeQueueDataNV", "getDescriptorEXT", "getDescriptorSetHostMappingVALVE",
        "getQueryPoolResults"};

    if (name == "getCalibratedTimestampsKHR") {
        assert(out.decl.args.size() == 3);
        assert(out.decl.returnType == "Result");

        out.nowReturn = out.decl.args[1];
        out.additional = out.decl.args[2];

        out.additional.name = removeP(out.additional.name);

        prepareReturnVec(out.nowReturn);
        prepareReturnVec(out.additional);
        out.decl.deleteArg(2);
        out.decl.deleteArg(1);

        out.decl.replaceReturnType("std::expected<std::tuple<" + out.nowReturn.baseType + ", " +
                                   out.additional.baseType + ">, Result>");

        out.type = SignaturePrep::Type::GetCalibratedTimestampsKHR;
        return out;
    }
    if (name == "getDescriptorEXT") {
        assert(out.decl.args.size() == 2);
        assert(out.decl.returnType == "void");

        out.nowReturn = out.decl.args[1];
        prepareReturnVec(out.nowReturn);

        prepareReturnVec(out.nowReturn);
        out.decl.deleteArg(1);
        out.decl.addArg(1, Function::Argument{TypeAndName{.name = "size",
                                                          .baseType = "size_t",
                                                          .leading = "const",
                                                          .postType = "",
                                                          .trailing = ""},
                                              std::nullopt, false});

        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::GetDescriptorEXT;
        return out;
    }
    if (name.contains("OpaqueCaptureData")) {
        assert(out.decl.args.size() == 2);
        assert(out.decl.returnType == "Result");

        out.nowReturn = out.decl.args[1];
        prepareReturnVec(out.nowReturn);
        out.decl.deleteArg(1);

        out.additional = out.decl.args[0];

        out.decl.replaceReturnType("std::expected<" + out.nowReturn.baseType + ", Result>");

        out.type = SignaturePrep::Type::OpaqueCaptureData;
        return out;
    }
    if ((name.starts_with("create") || name.starts_with("register") || name == "allocateMemory" ||
         name == "getDrmDisplayEXT" || name == "acquirePerformanceConfigurationINTEL") &&
        handleOwner.contains("Vk" + out.decl.args.back().baseType)) {
        out.nowReturn = out.decl.args.back();
        if (out.nowReturn.baseType != "DisplayModeKHR") {
            out.nowReturn.baseType = "Unique" + out.nowReturn.baseType;
        }
        assert(out.decl.returnType == "Result");
        out.decl.replaceReturnType("std::expected<" + out.nowReturn.baseType + ", Result>");

        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::CreateResult;
        return out;
    }
    if (name.starts_with("allocate")) {
        out.nowReturn = out.decl.args.back();

        assert(out.decl.returnType == "Result");
        out.decl.replaceReturnType("std::expected<" + out.nowReturn.baseType + "s, Result>");
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::Allocate;
        return out;
    }
    if (name.starts_with("create") &&
        out.decl.args.back().baseType.starts_with("impl_Struct::VecView<")) {
        prepareReturnVec(out.decl.args.back());
        std::string type = out.decl.args.back().baseType.substr(
            std::string("std::vector<").size(), out.decl.args.back().baseType.size() -
                                                    std::string(">").size() -
                                                    std::string("std::vector<").size());
        assert(type.starts_with("Handle::"));
        assert(out.decl.returnType == "Result");
        type = type.substr(std::string("Handle::").size());

        std::string vecType = "std::vector<Unique" + type + ">";
        out.additional.baseType = "std::vector<Handle::" + type + ">";
        out.additional.name = out.decl.args.back().name + "Raw";
        out.decl.replaceReturnType("std::expected<" + vecType + ", Result>");
        out.nowReturn = out.decl.args.back();

        out.nowReturn.baseType = vecType;
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::CreateResultVec;
        return out;
    }
    if (name.starts_with("get") && out.decl.returnType == "void" && !out.decl.args.empty() &&
        out.decl.args.back().baseType.starts_with("impl_Struct::VecView<")) {
        out.nowReturn = out.decl.args.back();

        prepareReturnVec(out.nowReturn);
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::Get;
        return out;
    }
    if ((!name.starts_with("get") && !name.starts_with("enumerate")) || ignorList.contains(name))
        return out;
    if (out.decl.returnType == "void" &&
        handleOwner.contains("Vk" + out.decl.args.back().baseType)) {

        out.nowReturn = out.decl.args.back();

        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::Create;
        return out;
    }
    if (out.decl.returnType == "void") {
        out.nowReturn = out.decl.args.back();
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.replaceReturnType(out.nowReturn.baseType);

        out.type = SignaturePrep::Type::Get;
        return out;
    }
    if (out.decl.returnType != "Result" || out.decl.args.back().baseType == "void" ||
        name.contains("Status") || name.contains("Result"))
        return out;
    if (out.decl.args.size() >= 2 &&
        out.decl.args.back().baseType.starts_with("impl_Struct::VecView<") &&
        out.decl.args[out.decl.args.size() - 2].baseType.starts_with("impl_Struct::VecView") &&
        name.starts_with("enumerate")) {

        out.nowReturn = out.decl.args.back();
        out.additional = out.decl.args[out.decl.args.size() - 2];
        prepareReturnVec(out.nowReturn);
        prepareReturnVec(out.additional);
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.deleteArg(out.decl.args.size() - 1);

        out.decl.replaceReturnType("std::expected<std::tuple<" + out.nowReturn.baseType + ", " +
                                   out.additional.baseType + ">, Result>");

        out.type = SignaturePrep::Type::GetResultVec2;
        return out;
    }
    out.nowReturn = out.decl.args.back();
    prepareReturnVec(out.nowReturn);
    out.decl.deleteArg(out.decl.args.size() - 1);

    out.decl.replaceReturnType("std::expected<" + out.nowReturn.baseType + ", Result>");

    out.nowReturn = out.nowReturn;
    out.type = SignaturePrep::Type::GetResult;
    return out;
}

void FunctionInfo::writeFunctionPointerDecl(CppGenerator &gen) const {
    Function f = function;
    f.className = "";

    auto translateType = [&](std::string &baseType) -> void {
        if (auto it = alias.find(baseType); it != alias.end()) {
            baseType = it->second;
        }
        if (allEnums.contains(baseType.substr(2)) || allEnumFlags.contains(baseType.substr(2))) {
            baseType = baseType.substr(2);
        } else if (allStructs.contains(baseType) || allUnions.contains(baseType)) {
            baseType = baseType.substr(2);
        } else if (auto it = baseTypeMapping.find(baseType); it != baseTypeMapping.end()) {
            baseType = it->second;
        }
    };

    for (auto &arg : f.args) {
        if (handleOwner.contains(arg.baseType)) {
            arg.baseType = "Handle::" + arg.baseType.substr(2);
        }
        translateType(arg.baseType);
    }
    if (f.returnType.starts_with("Vk")) {
        f.returnType = f.returnType.substr(2);
    }
    static const std::string pfn = "PFN_vk";
    if (auto it = f.returnType.find(pfn); it != std::string::npos) {
        f.returnType.erase(it, pfn.size());
        f.returnType.insert(0, "PFN::");
    }
    if (f.name.starts_with("vk")) {
        f.name = f.name.substr(2);
    }

    gen.doWriteLine("using " + f.name + " = " + f.toModernFunctionPtr("VKAPI_PTR") + ";");
}

void FunctionInfo::writeFunctionPointerObject(CppGenerator &gen) const {
    std::string name = function.name;
    if (name.starts_with("vk")) {
        name = name.substr(2);
    }
    std::string pfn = name;
    pfn[0] = static_cast<char>(std::tolower(pfn[0]));
    gen.doWriteLine("extern PFN::" + name + " " + pfn + ";");
}

void FunctionInfo::writeFunctionPointerMember(CppGenerator &gen) const {
    std::string name = function.name;
    if (name.starts_with("vk")) {
        name = name.substr(2);
    }
    std::string pfn = name;
    pfn[0] = static_cast<char>(std::tolower(pfn[0]));
    gen.doWriteLine("PFN::" + name + " " + pfn + ";");
}

void FunctionInfo::writeLoadGlobal(CppGenerator &gen) const {
    std::string name = function.name;
    if (name.starts_with("vk")) {
        name = name.substr(2);
    }
    std::string pfn = name;
    pfn[0] = static_cast<char>(std::tolower(pfn[0]));
    gen.doWriteLine(pfn + " = (PFN::" + name + ") getInstanceProcAddr(nullptr, \"" + function.name +
                    "\");");
}

void FunctionInfo::writeLoadInstance(CppGenerator &gen) const {
    std::string name = function.name;
    if (name.starts_with("vk")) {
        name = name.substr(2);
    }
    std::string pfn = name;
    pfn[0] = static_cast<char>(std::tolower(pfn[0]));
    gen.doWriteLine("table." + pfn + " = (PFN::" + name + ") getInstanceProcAddr(instance, \"" +
                    function.name + "\");");
}

void FunctionInfo::writeLoadDevice(CppGenerator &gen) const {
    std::string name = function.name;
    if (name.starts_with("vk")) {
        name = name.substr(2);
    }
    std::string pfn = name;
    pfn[0] = static_cast<char>(std::tolower(pfn[0]));
    gen.doWriteLine("table." + pfn + " = (PFN::" + name + ") getDeviceProcAddr(device, \"" +
                    function.name + "\");");
}

void FunctionInfo::writeHeader(CppGenerator &gen) const {
    if (function.returnType.starts_with("PFN"))
        return; // Loading Functions

    auto decl = prepareSignature().decl;
    for (auto &arg : decl.args | std::views::reverse) {
        if (!arg.optional)
            break;
        if (arg.baseType.starts_with(
                "impl_Struct::VecView")) { // vector need higher precedence than Flags
            arg.trailing += " = {}";
        } else if (handleOwner.contains("Vk" + arg.baseType)) {
            arg.trailing += " = {}";
        } else if (allEnumFlags.contains(arg.baseType)) {
            arg.trailing += " = {}";
        } else if (allEnums.contains(arg.baseType)) {
            arg.trailing += enumZeroElements.at(arg.baseType);
        } else if (arg.baseType == "uint32_t" && arg.postType == "") {
            arg.trailing += " = 0";
        } else {
            arg.trailing += " = nullptr";
        }
    }
    gen.doCode(decl.toSignature(true) + ";");
}

void FunctionInfo::writeImpl(CppGenerator &gen) const {
    if (function.returnType.starts_with("PFN"))
        return; // Loading Functions

    SignaturePrep prep = prepareSignature();

    auto capitilizeFirst = [](const std::string &s) -> std::string {
        std::string copy = s;
        if (!copy.empty())
            copy[0] = static_cast<char>(std::toupper(copy[0]));
        return copy;
    };

    std::stringstream sigLine;
    gen.doLineBeginScope(prep.decl.toSignature());

    if (prep.type == SignaturePrep::Type::Normal) {
        Function call = prep.mapping;
        if (call.returnType == "VkResult") {
            gen.doWriteLine("return " + call.toCall() + ";");
        } else {
            gen.doWriteLine(call.toCallReturn() + ";");
        }
        gen.endScope();
        return;
    }

    auto getDispatcherArg = [](const Function::Argument &arg) -> std::string {
        std::string dispatcherArg;
        if (handleHasFunctions.contains(arg.baseType)) {
            dispatcherArg = ", dispatcher";
        }
        return dispatcherArg;
    };

    if (prep.type == SignaturePrep::Type::Get) {
        const auto &getArg = prep.nowReturn;
        if (!getArg.baseType.starts_with("std::vector")) {
            gen.doWriteLine(getArg.baseType + " " + getArg.name + ";");
            Function call = prep.mapping;
            std::string &lastName = call.args.back().name;
            lastName.insert(lastName.find(getArg.name), "&");
            gen.doWriteLine(call.toCall() + ";");
            gen.doReturn(getArg.name);
            gen.endScope();
            return;
        }
        Function call = prep.mapping;
        gen.doWriteLine(call.args[call.args.size() - 2].baseType + " count = 0;");
        call.replaceArg(call.args.size() - 2, "&count");
        std::string back = call.args.back().name;
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doWriteLine(call.toCall() + ";");
        gen.doWriteLine(getArg.baseType + " " + getArg.name + "(count);");
        call.replaceArg(call.args.size() - 1, back);
        gen.doWriteLine(call.toCall() + ";");
        gen.doWriteLine(getArg.name + ".resize(count);");
        gen.doReturn(getArg.name);
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetResult) {
        const auto &getArg = prep.nowReturn;
        auto call = prep.mapping;
        if (!getArg.baseType.starts_with("std::vector")) {
            gen.doWriteLine(getArg.baseType + " " + getArg.name + ";");

            if (call.args.back().postType == "*") {
                std::string &lastName = call.args.back().name;
                lastName.insert(lastName.find(getArg.name), "&");
            }
            gen.doIfWithInitializer("Result res = " + call.toCall(),
                                    gen.makeConditionNotOneOf("res", call.successcodes));
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
            gen.doReturn(getArg.name);
            gen.endScope();
            return;
        }
        if (!prep.decl.args.empty() &&
            prep.decl.args.begin()->baseType.starts_with("std::vector")) {
            gen.doWriteLine(getArg.baseType + " " + getArg.name + "(" +
                            prep.decl.args.begin()->name + ".size());");
            gen.doIfWithInitializer("Result res = " + call.toCall(),
                                    gen.makeConditionNotOneOf("res", call.successcodes));
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
            gen.doReturn(getArg.name);
            gen.endScope();
            return;
        }
        gen.doWriteLine(call.args[call.args.size() - 2].baseType + " count = 0;");
        if (call.args[call.args.size() - 2].postType != "*") {
            call.replaceArg(call.args.size() - 2, "count");
        } else {
            call.replaceArg(call.args.size() - 2, "&count");
        }
        std::string back = call.args.back().name;
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doIfWithInitializer("Result res = " + call.toCall(),
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(getArg.baseType + " " + getArg.name + "(count);");
        call.replaceArg(call.args.size() - 1, back);
        gen.doIfWithInitializer("Result res = " + call.toCall(),
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(getArg.name + ".resize(count);");
        gen.doReturn(getArg.name);
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetResultVec2) {
        const auto &vec1 = prep.nowReturn;
        const auto &vec2 = prep.additional;
        Function call = prep.mapping;
        gen.doWriteLine(call.args[call.args.size() - 3].baseType + " count = 0;");
        call.replaceArg(call.args.size() - 3, "&count");
        std::string back2 = call.args[call.args.size() - 2].name;
        std::string back = call.args[call.args.size() - 1].name;
        call.replaceArg(call.args.size() - 2, "nullptr");
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doIfWithInitializer("Result res = " + call.toCall(),
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(vec1.baseType + " " + vec1.name + "(count);");
        gen.doWriteLine(vec2.baseType + " " + vec2.name + "(count);");
        call.replaceArg(call.args.size() - 2, back2);
        call.replaceArg(call.args.size() - 1, back);
        gen.doIfWithInitializer("Result res = " + call.toCall(),
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(vec1.name + ".resize(count);");
        gen.doWriteLine(vec2.name + ".resize(count);");
        gen.doReturn("std::make_tuple(" + vec1.name + ", " + vec2.name + ")");
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::CreateResult) {
        const auto &createArgUnique = prep.nowReturn;
        auto createArg = prep.nowReturn;
        static std::string unique = "Unique";
        if (createArg.baseType.starts_with(unique)) {
            createArg.baseType = createArg.baseType.substr(unique.size());
        }
        gen.doWriteLine("Handle::" + createArg.baseType + " " + createArg.name +
                        " = VK_BINDINGS_NULL_HANDLE;");

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + createArg.name);

        gen.doIfWithInitializer("Result res = " + call.toCall(), "res != Result::eSuccess");
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();

        std::string uniqueVar = "unique" + capitilizeFirst(createArg.name.substr(1));
        if (createArg.baseType == "Instance") {
            gen.doWriteLine(createArgUnique.baseType + " " + uniqueVar + "{Instance{std::move(" +
                            createArg.name + ")}};");
        } else if ((destroyFunctions.contains("Vk" + createArg.baseType) &&
                    destroyFunctions.at("Vk" + createArg.baseType).function.args.size() == 3) ||
                   prep.decl.name.starts_with("acquire") || prep.decl.name == "getDrmDisplayEXT") {
            gen.doWriteLine(createArgUnique.baseType + " " + uniqueVar + "{" + createArg.baseType +
                            "{std::move(" + createArg.name + ")" + getDispatcherArg(createArg) +
                            "}, handle};");
        } else {
            gen.doWriteLine(createArgUnique.baseType + " " + uniqueVar + "{" + createArg.baseType +
                            "{std::move(" + createArg.name + ")" + getDispatcherArg(createArg) +
                            "}};");
        }
        gen.doReturn(uniqueVar);
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::Allocate) {
        const auto &nowReturn = prep.nowReturn;
        const auto &handleName = nowReturn.baseType;
        auto handleNameSnailCase = nowReturn.baseType;
        handleNameSnailCase[0] = static_cast<char>(std::tolower(handleNameSnailCase[0]));

        auto firstWordLower = [](const std::string &s) -> std::string {
            size_t split = 0;
            for (size_t i = 1; i < s.size(); ++i) {
                if (std::isupper(s[i])) {
                    split = i;
                    break;
                }
            }
            std::string out = s.substr(0, split);
            out[0] = static_cast<char>(out[0]);
            return out;
        };

        const auto &allocInfoName = prep.mapping.args[1].name;
        gen.doWriteLine("std::vector<Handle::" + handleName + "> handles(" + allocInfoName + "->" +
                        handleNameSnailCase + "Count);");
        Function call = prep.mapping;
        call.replaceArg(2, "handles.data()");
        gen.doIfWithInitializer("Result res = " + call.toCall(), "res != Result::eSuccess");
        gen.doWriteLine(handleName + "s buffers{std::move(handles), " + allocInfoName + "->" +
                        firstWordLower(handleNameSnailCase) + "Pool.handle, *this};");
        gen.doReturn("buffers");
        gen.doElse();
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::Create) {
        const auto &nowReturn = prep.nowReturn;
        const auto &handleName = nowReturn.baseType;
        auto handleNameSnailCase = nowReturn.baseType;
        handleNameSnailCase[0] = static_cast<char>(std::tolower(handleNameSnailCase[0]));

        gen.doWriteLine("Handle::" + handleName + " " + handleNameSnailCase +
                        " = VK_BINDINGS_NULL_HANDLE;");

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + handleNameSnailCase);
        gen.doWriteLine(call.toCall() + ";");

        gen.doReturn("{std::move(" + handleNameSnailCase + "), dispatcher}");
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetCalibratedTimestampsKHR) {
        const auto &vec = prep.nowReturn;
        const auto &deviation = prep.additional;

        gen.doWriteLine(deviation.baseType + " " + deviation.name + " = 0;");
        gen.doWriteLine(vec.baseType + " " + vec.name + "(" + prep.decl.args[0].name + ".size());");

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + deviation.name);
        gen.doWriteLine(call.toCall() + ";");

        gen.doReturn("{{" + vec.name + ", " + deviation.name + "}}");
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::GetDescriptorEXT) {
        const auto &nowReturn = prep.nowReturn;

        gen.doWriteLine(nowReturn.baseType + " descriptor(size);");
        Function call = prep.mapping;
        gen.doWriteLine(prep.mapping.toCall() + ";");
        gen.doReturn("descriptor");
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::OpaqueCaptureData) {
        const auto &nowReturn = prep.nowReturn;
        const auto &objects = prep.additional;

        gen.doWriteLine(nowReturn.baseType + " datas(" + objects.name + ".size());");
        Function call = prep.mapping;
        gen.doIfWithInitializer("Result res = " + call.toCall(), "res != Result::eSuccess");
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doReturn("datas");
        gen.endScope();
        return;
    }
    assert(prep.type == SignaturePrep::Type::CreateResultVec);
    const auto &nowReturn = prep.nowReturn;
    const auto &additional = prep.additional;

    gen.doWriteLine(
        additional.baseType + " " + additional.name + "{" +
        prep.mapping.args[prep.mapping.args[prep.mapping.args.size() - 1].arrayWithLengthOf.value()]
            .name +
        "};");
    Function call = prep.mapping;
    call.replaceArg(call.args.size() - 1, additional.name + ".data()");

    gen.doIfWithInitializer("Result res = " + call.toCall(), "res != Result::eSuccess");

    gen.doWriteLine(nowReturn.baseType + " " + nowReturn.name + ";");
    gen.doRangedFor("auto& h", additional.name);
    std::string type = additional.baseType
                           .substr(std::string("std::vector<").size(),
                                   additional.baseType.size() - std::string(">").size() -
                                       std::string("std::vector<").size())
                           .substr(std::string("Handle::").size());

    gen.doWriteLine(nowReturn.name + ".emplace_back(Unique" + type + "{" + type +
                    "{std::move(h)}, handle" + getDispatcherArg(additional) + "});");
    gen.doForEnd();

    gen.doReturn(nowReturn.name);
    gen.doElse();
    gen.doReturn("std::unexpected(res)");
    gen.doIfEnd();
    gen.endScope();
}

auto getFunctionPtrsStructs(XMLElement &registry) -> std::unordered_set<std::string> {
    static std::unordered_set<std::string> pfnStructs;
    if (!pfnStructs.empty())
        return pfnStructs;
    const auto &pfns = parseFunctionPtrs(registry);
    const auto &allStructs = parseAllStructs(registry);
    const auto &[structInfos, _] = parseStructInfosAndTemplateInstantiations(registry);
    std::queue<std::string> work;
    for (const auto &pfn : pfns) {
        for (const auto &arg : pfn.function.args) {
            if (!allStructs.contains(arg.baseType))
                continue;
            work.push(arg.baseType);
        }
    }

    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    for (const auto &s : structInfos) {
        auto &pre = prerequisits[s.name];
        for (const auto &m : s.members) {
            pre.insert(m.baseType);
        }
    }

    while (!work.empty()) {
        std::string cur = work.front();
        work.pop();
        if (!allStructs.contains(cur))
            continue;
        pfnStructs.insert(cur);
        work.push_range(prerequisits.at(cur.substr(2)));
    }

    return pfnStructs;
}

auto parseFunctionPtrs(XMLElement &registry) -> std::set<FunctionInfo> {
    static std::set<FunctionInfo> functionPtrInfos;
    if (!functionPtrInfos.empty())
        return functionPtrInfos;

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");
    const std::unordered_map<std::string, Depends> &functionDepends =
        parseObjectDepents(registry, "type");

    std::vector<Function> functionPtrs;

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (HasAttribute(type, "alias"))
            return;
        if (!checkApi(type))
            return;
        if (!HasAttributeValue(type, "category", "funcpointer"))
            return;

        XMLElement &proto = FirstChildElement(type, "proto");

        std::string name = FirstChildElement(proto, "name").GetText();
        if (objectsDisabled.contains(name))
            return;

        Function functionPtr;
        functionPtr.name = name;
        functionPtr.returnType = FirstChildElement(proto, "type").GetText();
        ForEach(type, "param", [&](XMLElement &param) -> void {
            if (!checkApi(param))
                return;
            Function::Argument arg;
            arg = parseTypeAndName(param);
            static const std::string pfn = "PFN_vk";
            if (auto it = arg.baseType.find(pfn); it != std::string::npos) {
                arg.baseType.erase(it, pfn.size());
            }
            functionPtr.args.push_back(std::move(arg));
        });
        static const std::string pfn = "PFN_vk";
        if (auto it = functionPtr.name.find(pfn); it != std::string::npos) {
            functionPtr.name.erase(it, pfn.size());
        }
        if (auto it = functionPtr.returnType.find(pfn); it != std::string::npos) {
            functionPtr.returnType.erase(it, pfn.size());
        }

        functionPtrs.push_back(std::move(functionPtr));
    });

    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    for (const auto &f : functionPtrs) {
        for (const auto &arg : f.args) {
            prerequisits[f.name].insert(arg.baseType);
        }
        prerequisits[f.name].insert(f.returnType);
    }

    std::unordered_set<std::string> toRemove;
    std::unordered_map<std::string, int> rank;
    int currentRank = 0;

    std::unordered_set<std::string> roots;
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
            std::erase_if(pair.second,
                          [&](const std::string &s) -> bool { return toRemove.contains(s); });
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
        if (auto it = functionDepends.find(info.function.name); it != functionDepends.end()) {
            info.depends = it->second;
        }
        if (auto it = rank.find(info.function.name); it != rank.end()) {
            info.rank = it->second;
        }

        functionPtrInfos.insert(std::move(info));
    }

    return functionPtrInfos;
}

auto parseFunctionLevels(XMLElement &registry) -> const FunctionLevels & {
    using enum FunctionInfo::Level;

    static FunctionLevels functions;
    if (!functions.exported.empty())
        return functions;

    auto groupedFunctions = parseGroupedFunctions(registry);
    for (const auto &[handle, infos] : groupedFunctions) {
        for (const auto &info : infos) {
            if (info.function.name == "vkGetInstanceProcAddr") {
                functions.getInstanceProcAddr = info;
                functions.exported.insert(info);
                continue;
            }
            if (info.function.name == "vkGetDeviceProcAddr") {
                functions.getDeviceProcAddr = info;
                functions.exported.insert(info);
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
