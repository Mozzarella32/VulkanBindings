#include "FunctionInfo.hpp"

#include <map>
#include <ranges>
#include <unordered_set>

std::unordered_map<std::string, std::string> FunctionInfo::handleOwner;
std::unordered_map<std::string, Function> FunctionInfo::destroyFunctions;

bool FunctionInfo::operator<(const FunctionInfo &other) const {
    return std::tie(depends.platform, depends.feature, depends.extensions, function.name) <
           std::tie(other.depends.platform, other.depends.feature, other.depends.extensions,
                    other.function.name);
}

FunctionInfo::SignaturePrep FunctionInfo::prepareSignature() const {
    SignaturePrep out;

    auto prepareStr = [](std::string str) {
        if (str[0] != 'p')
            return str;
        str = str.substr(1);
        str[0] = std::tolower(str[0]);
        return str;
    };

    auto decl = function;
    auto mapping = decl;
    std::string vk = decl.name.substr(0, 2);
    assert(vk == "vk");
    std::string name = decl.name.substr(2);
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
        name[0] = std::tolower(name[0]);

    decl.replaceName(name);

    std::map<size_t, size_t> argsToDelete;
    for (size_t i = 0; i < decl.args.size(); i++) {
        auto &arg = decl.args[i];
        if (arg.arrayWithLengthOf.has_value()) {
            if (!argsToDelete.contains(arg.arrayWithLengthOf.value())) {
                argsToDelete[arg.arrayWithLengthOf.value()] = i;
            }
            std::string baseType = arg.baseType;
            if (baseType == "void") {
                baseType = "uint8_t";
            }
            if (arg.postType == "*") {
                arg.baseType = "std::vector<" + baseType + ">";
            } else if (arg.postType == "* const*") {
                arg.baseType = "std::vector<const " + baseType + " *>";
            } else {
                assert(false);
            }
            arg.name = prepareStr(arg.name);
            arg.postType = "&";
            mapping.replaceArg(i, arg.name + ".data()");
        }
    }

    for (auto [i, replace] : argsToDelete | std::views::reverse) {
        mapping.replaceArg(i, decl.args[replace].name + ".size()");
        decl.args.erase(decl.args.begin() + i);
    }

    if (handle != "") {
        assert(decl.args.size() >= 1);
        assert(decl.args[0].baseType == handle);
        decl.deleteArg(0);
        mapping.replaceArg(0, "handle");
    }

    static const std::unordered_set<std::string> ignorList{
        "getExternalComputeQueueDataNV", "getDescriptorEXT", "getDescriptorSetHostMappingVALVE",
        "getQueryPoolResults"};

    if ((name.starts_with("create") || name == "allocateMemory") &&
        handleOwner.contains(decl.args.back().baseType)) {
        Function::Argument nowReturn = decl.args.back();
        assert(decl.returnType == "VkResult");
        decl.replaceReturnType("std::expected<Handle" + nowReturn.baseType + ", VkResult>");

        decl.deleteArg(decl.args.size() - 1);
        out.nowReturn = nowReturn;
        out.type = SignaturePrep::Type::Create;
    } else if (name.starts_with("create") &&
               decl.args.back().baseType.starts_with("std::vector<")) {
        std::string type = decl.args.back().baseType.substr(std::string("std::vector<").size(),
                                                            decl.args.back().baseType.size() -
                                                                std::string(">").size() -
                                                                std::string("std::vector<").size());
        type = "std::vector<Handle" + type + ">";
        out.additional = decl.args.back();
        out.additional.replaceName(decl.args.back().name + "Raw");
        decl.replaceReturnType("std::expected<" + type + ", VkResult>");
        out.nowReturn = decl.args.back().replaceBaseType(type);
        out.type = SignaturePrep::Type::CreateVec;
        decl.deleteArg(decl.args.size() - 1);
    } else if ((name.starts_with("get") || name.starts_with("enumerate")) &&
               !ignorList.contains(name)) {
        if (decl.returnType == "void") {
            decl.replaceReturnType(decl.args.back().baseType);
            out.nowReturn = decl.args.back();
            decl.deleteArg(decl.args.size() - 1);
            out.type = SignaturePrep::Type::Get;
        } else if (decl.returnType == "VkResult" && decl.args.back().baseType != "void" &&
                   !name.contains("Status") && !name.contains("Result")) {
            if (decl.args.size() >= 2 && decl.args.back().baseType.starts_with("std::vector<") &&
                decl.args[decl.args.size() - 2].baseType.starts_with("std::vector") &&
                name.starts_with("enumerate")) {
                Function::Argument nowReturn = decl.args.back();
                Function::Argument additional = decl.args[decl.args.size() - 2];

                decl.replaceReturnType("std::expected<std::tuple<" + nowReturn.baseType + ", " +
                                       additional.baseType + ">, VkResult>");

                decl.deleteArg(decl.args.size() - 1);
                decl.deleteArg(decl.args.size() - 1);
                out.nowReturn = nowReturn;
                out.additional = additional;
                out.type = SignaturePrep::Type::GetResultVec2;
            } else {
                Function::Argument nowReturn = decl.args.back();
                decl.replaceReturnType("std::expected<" + nowReturn.baseType + ", VkResult>");

                decl.deleteArg(decl.args.size() - 1);
                out.nowReturn = nowReturn;
                out.type = SignaturePrep::Type::GetResult;
            }
        }
    }
    out.mapping = mapping;
    out.decl = decl;
    return out;
}

void FunctionInfo::writeHeader(CppGenerator &gen, const FunctionInfo &info,
                               bool staticMemberFunctions) {
    auto decl = info.prepareSignature().decl;
    if (!decl.args.empty() && decl.args.back().name == "pAllocator") {
        decl.args.back().trailing += " = nullptr";
    }
    if (staticMemberFunctions) {
        gen.doCode("static " + decl.toSignature() + ";");
    } else {
        gen.doCode(decl.toSignature() + " const;");
    }
}

void FunctionInfo::writeImpl(CppGenerator &gen, const FunctionInfo &info,
                             const std::string &containingClass, bool staticMemberFunctions) {
    SignaturePrep prep = info.prepareSignature();

    auto capitilizeFirst = [](const std::string &s) {
        std::string copy = s;
        if (!copy.empty())
            copy[0] = std::toupper(copy[0]);
        return copy;
    };

    std::stringstream sigLine;
    if (staticMemberFunctions) {
        gen.doLineBeginScope(prep.decl.toSignature(containingClass));
    } else {
        gen.doLineBeginScope(prep.decl.toSignature(containingClass) + " const");
    }

    if (prep.type == SignaturePrep::Type::Get) {
        const auto &getArg = prep.nowReturn;
        if (getArg.baseType.starts_with("std::vector")) {
            Function call = prep.mapping;
            gen.doWriteLine(call.args[call.args.size() - 2].baseType + " count = 0;");
            call.replaceArg(call.args.size() - 2, "&count");
            call.replaceArg(call.args.size() - 1, "nullptr");
            gen.doWriteLine(call.toCall() + ";");
            gen.doWriteLine(getArg.baseType + " " + getArg.name + "(count);");
            call.replaceArg(call.args.size() - 1, getArg.name + ".data()");
            gen.doWriteLine(call.toCall() + ";");
            gen.doWriteLine(getArg.name + ".resize(count);");
            gen.doReturn(getArg.name);
        } else {
            gen.doWriteLine(getArg.baseType + " " + getArg.name + ";");
            Function call = prep.mapping;
            call.replaceArg(call.args.size() - 1, "&" + getArg.name);
            gen.doWriteLine(call.toCall() + ";");
            gen.doReturn(getArg.name);
        }
    } else if (prep.type == SignaturePrep::Type::GetResult) {
        const auto &getArg = prep.nowReturn;
        if (getArg.baseType.starts_with("std::vector")) {
            auto call = prep.mapping;
            if (!prep.decl.args.empty() &&
                prep.decl.args.begin()->baseType.starts_with("std::vector")) {
                gen.doWriteLine(getArg.baseType + " " + getArg.name + "(" +
                                prep.decl.args.begin()->name + ".size());");
                gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                        gen.makeConditionNotOneOf("res", call.successcodes));
                gen.doReturn("std::unexpected(res)");
                gen.doIfEnd();
                gen.doReturn(getArg.name);
            } else {
                gen.doWriteLine(call.args[call.args.size() - 2].baseType + " count = 0;");
                if (call.args[call.args.size() - 2].postType != "*") {
                    call.replaceArg(call.args.size() - 2, "count");
                } else {
                    call.replaceArg(call.args.size() - 2, "&count");
                }
                call.replaceArg(call.args.size() - 1, "nullptr");
                gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                        gen.makeConditionNotOneOf("res", call.successcodes));
                gen.doReturn("std::unexpected(res)");
                gen.doIfEnd();
                gen.doWriteLine(getArg.baseType + " " + getArg.name + "(count);");
                call.replaceArg(call.args.size() - 1, getArg.name + ".data()");
                gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                        gen.makeConditionNotOneOf("res", call.successcodes));
                gen.doReturn("std::unexpected(res)");
                gen.doIfEnd();
                gen.doWriteLine(getArg.name + ".resize(count);");
                gen.doReturn(getArg.name);
            }
        } else {
            gen.doWriteLine(getArg.baseType + " " + getArg.name + ";");
            Function call = prep.mapping;
            call.replaceArg(call.args.size() - 1, "&" + getArg.name);
            gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                    gen.makeConditionNotOneOf("res", call.successcodes));
            gen.doReturn("std::unexpected(res)");
            gen.doIfEnd();
            gen.doReturn(getArg.name);
        }
    } else if (prep.type == SignaturePrep::Type::GetResultVec2) {
        const auto &vec1 = prep.nowReturn;
        const auto &vec2 = prep.additional;
        Function call = prep.mapping;
        gen.doWriteLine(call.args[call.args.size() - 3].baseType + " count = 0;");
        call.replaceArg(call.args.size() - 3, "&count");
        call.replaceArg(call.args.size() - 2, "nullptr");
        call.replaceArg(call.args.size() - 1, "nullptr");
        gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(vec1.baseType + " " + vec1.name + "(count);");
        gen.doWriteLine(vec2.baseType + " " + vec2.name + "(count);");
        call.replaceArg(call.args.size() - 2, vec2.name + ".data()");
        call.replaceArg(call.args.size() - 1, vec1.name + ".data()");
        gen.doIfWithInitializer("VkResult res = " + call.toCall(),
                                gen.makeConditionNotOneOf("res", call.successcodes));
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
        gen.doWriteLine(vec1.name + ".resize(count);");
        gen.doWriteLine(vec2.name + ".resize(count);");
        gen.doReturn("std::make_tuple(" + vec1.name + ", " + vec2.name + ")");

    } else if (prep.type == SignaturePrep::Type::Create) {
        const auto &createArg = prep.nowReturn;
        gen.doWriteLine(createArg.baseType + " " + createArg.name + " = VK_NULL_HANDLE;");

        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, "&" + createArg.name);

        gen.doIfWithInitializer("VkResult res = " + call.toCall(), "res != VK_SUCCESS");

        std::string handleVar = "handle" + capitilizeFirst(createArg.name);
        if (destroyFunctions[createArg.baseType].args.size() == 3) {
            gen.doWriteLine("Handle" + createArg.baseType + " " + handleVar + "{std::move(" +
                            createArg.name + "), handle};");
        } else {
            gen.doWriteLine("Handle" + createArg.baseType + " " + handleVar + "{std::move(" +
                            createArg.name + ")};");
        }
        gen.doReturn(handleVar);
        gen.doElse();
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();
    } else if (prep.type == SignaturePrep::Type::CreateVec) {
        const auto &nowReturn = prep.nowReturn;
        const auto &additional = prep.additional;

        gen.doWriteLine(
            additional.baseType + " " + additional.name + "{" +
            prep.mapping
                .args[prep.mapping.args[prep.mapping.args.size() - 1].arrayWithLengthOf.value()]
                .name +
            "};");
        Function call = prep.mapping;
        call.replaceArg(call.args.size() - 1, additional.name + ".data()");

        gen.doIfWithInitializer("VkResult res = " + call.toCall(), "res != VK_SUCCESS");

        gen.doWriteLine(nowReturn.baseType + " " + nowReturn.name + ";");
        gen.doRangedFor("auto& h", additional.name);
        std::string type =
            additional.baseType.substr(std::string("std::vector<").size(),
                                       additional.baseType.size() - std::string(">").size() -
                                           std::string("std::vector<").size());

        gen.doWriteLine(nowReturn.name + ".emplace_back(Handle" + type +
                        "{std::move(h), handle});");
        gen.doForEnd();

        gen.doReturn(nowReturn.name);
        gen.doElse();
        gen.doReturn("std::unexpected(res)");
        gen.doIfEnd();

    } else if (prep.type == SignaturePrep::Type::Normal) {
        Function call = prep.mapping;
        gen.doWriteLine(call.toCallReturn() + ";");
    }

    gen.endScope();
}
