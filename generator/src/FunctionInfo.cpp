#include "FunctionInfo.hpp"

#include <map>
#include <ranges>
#include <unordered_set>

std::unordered_map<std::string, std::string> FunctionInfo::handleOwner;
std::unordered_map<std::string, Function> FunctionInfo::destroyFunctions;
std::unordered_set<std::string> FunctionInfo::allEnums;
std::unordered_set<std::string> FunctionInfo::allEnumFlags;
std::unordered_set<std::string> FunctionInfo::allStructs;
std::unordered_set<std::string> FunctionInfo::allUnions;
std::unordered_map<std::string, std::string> FunctionInfo::enumZeroElements;
std::unordered_map<std::string, std::string> FunctionInfo::enumSizeTypes;

bool FunctionInfo::operator<(const FunctionInfo &other) const {
    bool notIsStatic = !function.isStatic;
    bool otherNotIsStatic = !other.function.isStatic;
    return std::tie(notIsStatic, depends, function.name, function.isConst) <
           std::tie(otherNotIsStatic, other.depends, other.function.name, other.function.isConst);
}

FunctionInfo::SignaturePrep FunctionInfo::prepareSignature() const {
    SignaturePrep out;

    auto removeP = [](std::string str) {
        if (str[0] != 'p')
            return str;
        str = str.substr(1);
        str[0] = static_cast<char>(std::tolower(str[0]));
        return str;
    };

    out.decl = function;
    out.mapping = function;
    std::string vk = out.decl.name.substr(0, 2);
    assert(vk == "vk");
    std::string name = out.decl.name.substr(2);
    if (name.rfind("Cmd", 0) == 0) {
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

    for (size_t i = 0; i < out.decl.args.size(); i++) {
        auto &arg = out.decl.args[i];
        if (handleOwner.contains(arg.baseType)) {

            if (!arg.arrayWithLengthOf && arg.postType != "*") {
                assert(arg.leading == "" && arg.postType == "" && arg.trailing == "");
                arg.leading = "const";
                arg.baseType = arg.baseType.substr(2);
                arg.postType = "&";
            } else if (arg.arrayWithLengthOf) {
                // arg.baseType = arg.baseType.substr(2);
            }
        } else if (allEnums.contains(arg.baseType.substr(2)) ||
                   allEnumFlags.contains(arg.baseType.substr(2))) {
            arg.baseType = arg.baseType.substr(2);
        } else if (allStructs.contains(arg.baseType) || allUnions.contains(arg.baseType)) {
            arg.baseType = arg.baseType.substr(2);
        }
    }

    if (out.decl.returnType.starts_with("Vk")) {
        out.decl.returnType = out.decl.returnType.substr(2);
    }

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
        if (arg.postType == "*") {
            arg.baseType = "std::vector<" + baseType + ">";
        } else {
            assert(arg.postType == "* const*");
            arg.baseType = "std::vector<const " + baseType + " *>";
        }
        arg.name = removeP(arg.name);
        arg.postType = "&";
        out.mapping.replaceArg(i, arg.name + ".data()");
    }

    for (auto [i, replace] : argsToDelete | std::views::reverse) {
        out.mapping.replaceArg(i, +"static_cast<" + out.decl.args[i].baseType + ">(" +
                                      out.decl.args[replace].name + ".size())");
        out.decl.args.erase(out.decl.args.begin() +
                            static_cast<decltype(out.decl.args)::iterator::difference_type>(i));
    }

    for (auto &arg : out.mapping.args) {
        if (allStructs.contains(arg.baseType) || allUnions.contains(arg.baseType) ||
            allEnumFlags.contains(arg.baseType.substr(2)) ||
            allEnums.contains(arg.baseType.substr(2))) {
            arg.name = "std::bit_cast<" + arg.fullType() +
                       (arg.trailing.starts_with("[") ? std::string("*") : std::string("")) + ">(" +
                       arg.name + ")";
        }
    }

    if (handle != "") {
        assert(out.decl.args.size() >= 1);
        assert(out.decl.args[0].baseType == handle.substr(2));
        out.decl.deleteArg(0);
        out.mapping.replaceArg(0, "handle");
    }

    static const std::unordered_set<std::string> ignorList{
        "getExternalComputeQueueDataNV", "getDescriptorEXT", "getDescriptorSetHostMappingVALVE",
        "getQueryPoolResults"};

    if ((name.starts_with("create") || name == "allocateMemory") &&
        handleOwner.contains("Vk" + out.decl.args.back().baseType)) {
        out.nowReturn = out.decl.args.back();
        assert(out.decl.returnType == "Result");
        out.decl.replaceReturnType("std::expected<" + out.nowReturn.baseType + ", Result>");

        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::Create;
        return out;
    }
    if (name.starts_with("create") && out.decl.args.back().baseType.starts_with("std::vector<")) {
        std::string type = out.decl.args.back().baseType.substr(
            std::string("std::vector<").size(), out.decl.args.back().baseType.size() -
                                                    std::string(">").size() -
                                                    std::string("std::vector<").size());
        std::string vecType = "std::vector<" + type.substr(2) + ">";
        out.additional.baseType = "std::vector<Vk" + type.substr(2) + ">";
        out.additional.name = out.decl.args.back().name + "Raw";
        out.decl.replaceReturnType("std::expected<" + vecType + ", Result>");
        out.nowReturn = out.decl.args.back();
        out.nowReturn.baseType = vecType;
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::CreateVec;
        return out;
    }
    if ((!name.starts_with("get") && !name.starts_with("enumerate")) || ignorList.contains(name))
        return out;
    if (out.decl.returnType == "void") {
        out.decl.replaceReturnType(out.decl.args.back().baseType);
        out.nowReturn = out.decl.args.back();
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::Get;
        return out;
    }
    if (out.decl.returnType != "Result" || out.decl.args.back().baseType == "void" ||
        name.contains("Status") || name.contains("Result"))
        return out;
    if (out.decl.args.size() >= 2 && out.decl.args.back().baseType.starts_with("std::vector<") &&
        out.decl.args[out.decl.args.size() - 2].baseType.starts_with("std::vector") &&
        name.starts_with("enumerate")) {
        out.nowReturn = out.decl.args.back();
        out.additional = out.decl.args[out.decl.args.size() - 2];

        out.decl.replaceReturnType("std::expected<std::tuple<" + out.nowReturn.baseType + ", " +
                                   out.additional.baseType + ">, Result>");

        out.decl.deleteArg(out.decl.args.size() - 1);
        out.decl.deleteArg(out.decl.args.size() - 1);
        out.type = SignaturePrep::Type::GetResultVec2;
        return out;
    }
    out.nowReturn = out.decl.args.back();
    out.decl.replaceReturnType("std::expected<" + out.nowReturn.baseType + ", Result>");

    out.decl.deleteArg(out.decl.args.size() - 1);
    out.nowReturn = out.nowReturn;
    out.type = SignaturePrep::Type::GetResult;
    return out;
}

void FunctionInfo::writeHeader(CppGenerator &gen) const {
    auto decl = prepareSignature().decl;
    for (auto &arg : decl.args | std::views::reverse) {
        if (!arg.optional)
            break;
        if (arg.baseType.starts_with("std::vector")) { // vector need higher precedence than Flags
            arg.trailing += " = {}";
        } else if (handleOwner.contains("Vk" + arg.baseType)) {
            arg.trailing += " = {}";
        } else if (allEnumFlags.contains(arg.baseType)) {
            arg.trailing += " = {}";
        } else if (allEnums.contains(arg.baseType)) {
            arg.trailing += enumZeroElements.at(arg.baseType);
        } else {
            arg.trailing += " = nullptr";
        }
    }
    gen.doCode(decl.toSignature(true) + ";");
}

void FunctionInfo::writeImpl(CppGenerator &gen) const {
    SignaturePrep prep = prepareSignature();

    auto capitilizeFirst = [](const std::string &s) {
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
            gen.doWriteLine("return std::bit_cast<Result>(" + call.toCall() + ");");
        } else {
            gen.doWriteLine(call.toCallReturn() + ";");
        }
        gen.endScope();
        return;
    }

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
            std::string &lastName = call.args.back().name;
            lastName.insert(lastName.find(getArg.name), "&");
            gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
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
            gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
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
        gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(getArg.baseType + " " + getArg.name + "(count);");
        call.replaceArg(call.args.size() - 1, back);
        gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
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
        gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(vec1.baseType + " " + vec1.name + "(count);");
        gen.doWriteLine(vec2.baseType + " " + vec2.name + "(count);");
        call.replaceArg(call.args.size() - 2, back2);
        call.replaceArg(call.args.size() - 1, back);
        gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(vec1.name + ".resize(count);");
        gen.doWriteLine(vec2.name + ".resize(count);");
        gen.doReturn("std::make_tuple(" + vec1.name + ", " + vec2.name + ")");
        gen.endScope();
        return;
    }
    if (prep.type == SignaturePrep::Type::Create) {
        const auto &createArg = prep.nowReturn;
        gen.doWriteLine("Vk" + createArg.baseType + " " + createArg.name + " = VK_NULL_HANDLE;");

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + createArg.name);

        gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
                                "res != Result::eSuccess");

        std::string handleVar = "handle" + capitilizeFirst(createArg.name);
        if (destroyFunctions[createArg.baseType].args.size() == 3 ||
            prep.decl.name.starts_with("acquire")) {
            gen.doWriteLine(createArg.baseType + " " + handleVar + "{std::move(" + createArg.name +
                            "), handle};");
        } else {
            gen.doWriteLine(createArg.baseType + " " + handleVar + "{std::move(" + createArg.name +
                            ")};");
        }
        gen.doReturn(handleVar);
        gen.doElse();
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.endScope();
        return;
    }
    assert(prep.type == SignaturePrep::Type::CreateVec);
    const auto &nowReturn = prep.nowReturn;
    const auto &additional = prep.additional;

    gen.doWriteLine(
        additional.baseType + " " + additional.name + "{" +
        prep.mapping.args[prep.mapping.args[prep.mapping.args.size() - 1].arrayWithLengthOf.value()]
            .name +
        "};");
    Function call = prep.mapping;
    call.replaceArg(call.args.size() - 1, additional.name + ".data()");

    gen.doIfWithInitializer("Result res = std::bit_cast<Result>(" + call.toCall() + ")",
                            "res != Result::eSuccess");

    gen.doWriteLine(nowReturn.baseType + " " + nowReturn.name + ";");
    gen.doRangedFor("auto& h", additional.name);
    std::string type = additional.baseType.substr(
        std::string("std::vector<").size(),
        additional.baseType.size() - std::string(">").size() - std::string("std::vector<").size());

    gen.doWriteLine(nowReturn.name + ".emplace_back(" + type.substr(2) +
                    "{std::move(h), handle});");
    gen.doForEnd();

    gen.doReturn(nowReturn.name);
    gen.doElse();
    gen.doReturn("std::unexpected(res)");
    gen.doIfEnd();
    gen.endScope();
}
