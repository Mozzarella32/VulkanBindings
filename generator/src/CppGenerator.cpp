#include "CppGenerator.hpp"

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

auto TypeAndName::preTypePrint() const -> std::string {
    std::string ret = leading;
    if (!ret.empty()) {
        if (ret.back() != ' ')
            ret.push_back(' ');
    }
    return ret;
}

auto TypeAndName::postTypePrint() const -> std::string {
    std::string ret = postType;
    if (!ret.empty()) {
        if (ret.front() != ' ')
            ret.insert(ret.begin(), ' ');
        if (ret.back() != ' ')
            ret.push_back(' ');
    } else {
        ret = " ";
    }
    return ret;
}

auto TypeAndName::postArgumentPrint() const -> std::string { return trailing; }

auto TypeAndName::fullType(bool insertSpace) const -> std::string {
    std::string ret = leading;
    if (!ret.empty())
        ret += " ";
    ret += baseType;
    if (!postType.empty()) {
        if (postType.front() != ' ')
            ret += " ";
        ret += postType;
    } else if (insertSpace) {
        ret += " ";
    }
    return ret;
}

auto Function::deleteArg(size_t idx) -> Function & {
    assert(idx < args.size());
    args.erase(args.begin() + static_cast<decltype(args)::iterator::difference_type>(idx));
    return *this;
}
auto Function::addArg(size_t idx, const Argument &arg) -> Function & {
    assert(idx <= args.size());
    args.insert(args.begin() + static_cast<decltype(args)::iterator::difference_type>(idx), arg);
    return *this;
}
auto Function::replaceArg(size_t idx, const Argument &arg) -> Function & {
    args.at(idx) = arg;
    return *this;
}

auto Function::replaceArg(size_t idx, std::string_view str) -> Function & {
    args.at(idx).name = str;
    return *this;
}

auto Function::replaceReturnType(std::string_view newReturnType) -> Function {
    returnType = newReturnType;
    return *this;
}

auto Function::replaceName(std::string_view newName) -> Function {
    name = newName;
    return *this;
}

Function::Function(std::string name, std::vector<std::string> successcodes,
                   std::vector<std::string> errorcodes, bool isStatic, bool isConst,
                   bool isNoexcept, bool objectIsPointer, std::vector<Argument> args,
                   std::string returnType, std::string className, std::string objectName)
    : name(std::move(name)), successcodes(std::move(successcodes)),
      errorcodes(std::move(errorcodes)), isStatic(isStatic), isConst(isConst),
      isNoexcept(isNoexcept), objectIsPointer(objectIsPointer), args(std::move(args)),
      returnType(std::move(returnType)), className(std::move(className)),
      objectName(std::move(objectName)) {}

auto Function::getName() const -> std::string { return name; }

auto Function::toSignature(bool inClassBody) const -> std::string {
    std::stringstream buffer;

    if (isStatic && inClassBody) {
        buffer << "static ";
    }

    if (isConst && inClassBody && returnType != "void") {
        buffer << "[[nodiscard]] ";
    }

    if (returnType == "void") {
        buffer << "void ";
    } else {
        buffer << "auto ";
    }

    if (!inClassBody && !className.empty()) {
        buffer << className << "::";
    }

    buffer << name << "("
           << std::ranges::to<std::string>(
                  args | std::views::transform([](const auto &arg) -> std::string {
                      return arg.fullType() + arg.name + arg.postArgumentPrint();
                  }) |
                  std::views::join_with(std::string_view(", ")))
           << ")";

    if (isConst)
        buffer << " const";
    if (isNoexcept)
        buffer << " noexcept";

    if (returnType != "void" && !returnType.empty()) {
        buffer << " -> " << returnType;
    }

    return buffer.str();
}

auto Function::toArgList() const -> std::vector<std::string> {
    return args |
           std::views::transform([](const Argument &arg) -> std::string { return arg.name; }) |
           std::ranges::to<std::vector>();
}

auto Function::toCall() const -> std::string {
    std::stringstream buffer;
    if (!objectName.empty()) {
        buffer << objectName;
        if (objectIsPointer) {
            buffer << "->";
        } else {
            buffer << ".";
        }
    }
    buffer << name << "("
           << std::ranges::to<std::string>(
                  args |
                  std::views::transform([](const auto &arg) -> std::string { return arg.name; }) |
                  std::views::join_with(std::string_view(", ")))
           << ")";
    return buffer.str();
}

auto Function::toCallReturn() const -> std::string {
    if (returnType == "void") {
        return toCall();
    }
    return "return " + toCall();
}

auto Function::toFunctionPtr(std::string_view convention, std::string_view namePrefix) const
    -> std::string {
    std::stringstream buffer;

    if (!className.empty() && !isStatic) {
        buffer << returnType << " (" << convention << " " << className << "::*" << namePrefix
               << name << ")(";
    } else {
        buffer << returnType << " (" << convention << " *" << namePrefix << name << ")(";
    }

    if (args.empty()) {
        buffer << "void";
    } else {
        buffer << std::ranges::to<std::string>(args | std::views::transform([](const auto &arg) {
                                                   return arg.fullType(false) +
                                                          arg.postArgumentPrint();
                                               }) |
                                               std::views::join_with(std::string_view{", "}));
    }

    buffer << ")";

    if (!className.empty() && !isStatic && isConst) {
        buffer << " const";
    }

    if (isNoexcept) {
        buffer << " noexcept";
    }

    return buffer.str();
}

auto Function::toModernFunctionPtr(std::string_view convention) const -> std::string {
    std::stringstream buffer;

    buffer << "auto (";
    if (!convention.empty())
        buffer << convention << " ";

    buffer << "*"
           << ")("
           << std::ranges::to<std::string>(args | std::views::transform([](const auto &arg) {
                                               return arg.fullType(false) + arg.postArgumentPrint();
                                           }) |
                                           std::views::join_with(std::string_view{", "}))
           << ")";

    if (!className.empty() && !isStatic && isConst) {
        buffer << " const";
    }
    if (isNoexcept) {
        buffer << " noexcept";
    }

    buffer << " -> " << returnType;

    return buffer.str();
}

CppGenerator::CppGenerator(bool dummy) : dummy(dummy) {}
void CppGenerator::pushValidation(ValidationToken validationToken) {
    validationStack.push_back(validationToken);
}

void CppGenerator::popValidation(ValidationToken validationToken) {
    if (validationStack.empty()) {
        std::cerr << "CppGenerator: validation stack empty (expected different token)\n";
        assert(false);
        return;
    }
    auto vt_stack = validationStack.back();
    validationStack.pop_back();
    if (validationToken != vt_stack) {
        std::cerr << "CppGenerator: syntax validation failed (expected different token)\n";
        assert(false);
        return;
    }
}

auto CppGenerator::isMakroAlreadyUsed(std::string_view makro) const -> bool {
    auto hasMakro = [&](std::string_view str) -> bool { return str == makro; };

    return std::ranges::any_of(makros, hasMakro) ||
           std::ranges::any_of(pendingMakros, [&](const PendingMakro &pendingMakro) -> bool {
               return pendingMakro.expr == makro;
           });
}

void CppGenerator::pushMakroFrame(std::string_view makro, bool duplicate) {
    makros.emplace_back(duplicate ? "" : makro);
    makroOpened.push_back(false);
}

auto CppGenerator::popMakroFrame() -> PoppedMakroFrame {
    if (makros.empty() || makroOpened.empty() || makros.size() != makroOpened.size()) {
        std::cerr << "CppGenerator: makro stacks inconsistent on pop\n";
        assert(false);
        return {};
    }

    PoppedMakroFrame out;
    out.makro = makros.back();
    out.opened = makroOpened.back();

    makros.pop_back();
    makroOpened.pop_back();

    return out;
}

void CppGenerator::flushPendingMakros() {
    if (pendingMakros.empty()) {
        return;
    }

    for (const auto &pendingMakro : pendingMakros) {
        beginLine();
        if (pendingMakro.kind == PendingMakro::Kind::Ifdef) {
            buff << "#ifdef " << pendingMakro.expr;
        } else {
            buff << "#if " << pendingMakro.expr;
        }
        depth++;
        endLine();

        if (pendingMakro.frameIndex >= makroOpened.size()) {
            std::cerr << "CppGenerator: pending makro frame index out of range\n";
            assert(false);
            return;
        }
        makroOpened.at(pendingMakro.frameIndex) = true;
    }

    pendingMakros.clear();
}

void CppGenerator::pushNamespace(std::string_view namespace_) {
    namespaces.emplace_back(namespace_);
}

auto CppGenerator::popNamespace() -> std::string {
    if (namespaces.empty()) {
        std::cerr << "CppGenerator: namespaces empty on pop\n";
        assert(false);
        return "";
    }
    std::string namespace_ = namespaces.back();
    namespaces.pop_back();
    return namespace_;
}

void CppGenerator::beginLine() { buff << std::string(depth, '\t'); }
void CppGenerator::endLine() {
    buff << '\n';
    ifDefContainsSth = true;
}

void CppGenerator::beginScope(bool indent, std::optional<std::string_view> comment) {
    if (dummy)
        return;
    flushPendingMakros();
    buff << " {";
    if (comment) {
        assert(!comment.value().empty());
        buff << " // " << comment.value();
    }

    endLine();
    if (indent)
        depth++;
}

void CppGenerator::doLineBeginScope(std::string_view line,
                                    std::optional<std::string_view> comment) {
    if (dummy)
        return;
    flushPendingMakros();
    beginLine();
    buff << line;
    beginScope(true, comment);
}

void CppGenerator::doLineBeginScope(std::stringstream &line) {
    if (dummy)
        return;
    flushPendingMakros();
    beginLine();
    buff << line.rdbuf();
    beginScope();
}

void CppGenerator::endScope(bool indent, bool semicolon) {
    if (dummy)
        return;
    if (indent)
        depth--;

    beginLine();
    buff << "}";
    if (semicolon)
        buff << ";";

    endLine();
}

void CppGenerator::doIf(std::string_view cond) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::If);
    beginLine();
    buff << "if (" << cond << ")";
    beginScope();
}

void CppGenerator::doIfWithInitializer(std::string_view init, std::string_view cond) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::If);
    beginLine();
    buff << "if (" << init << "; " << cond << ")";
    beginScope();
}

void CppGenerator::doElseIf(std::string_view cond) {
    if (dummy)
        return;
    popValidation(ValidationToken::If);
    endScope();
    beginLine();
    buff << "else if(" << cond << ")";
    beginScope();
    pushValidation(ValidationToken::If);
}

void CppGenerator::doElse() {
    if (dummy)
        return;
    popValidation(ValidationToken::If);
    endScope();
    beginLine();
    buff << "else";
    beginScope();
    pushValidation(ValidationToken::If);
}

void CppGenerator::doIfEnd() {
    if (dummy)
        return;
    popValidation(ValidationToken::If);
    endScope();
}

void CppGenerator::doReturn(std::string_view expr) {
    if (dummy)
        return;
    flushPendingMakros();
    beginLine();
    if (expr.empty()) {
        buff << "return;";
    } else {
        buff << "return " << expr << ";";
    }
    endLine();
}

void CppGenerator::doFor(std::string_view initilizer, std::string_view condition,
                         std::string_view increment) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::For);
    beginLine();
    buff << "for (" << initilizer << "; " << condition << "; " << increment << ")";
    beginScope();
}

void CppGenerator::doRangedFor(std::string_view var, std::string_view container) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::For);
    beginLine();
    buff << "for (" << var << " : " << container << ")";
    beginScope();
}

void CppGenerator::doForEnd() {
    if (dummy)
        return;
    popValidation(ValidationToken::For);
    endScope();
}

void CppGenerator::doSwitch(std::string_view var) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::Switch);
    beginLine();
    buff << "switch (" << var << ")";
    beginScope(false);
}

void CppGenerator::doSwitchCase(std::string_view val) {
    if (dummy)
        return;
    popValidation(ValidationToken::Switch);
    pushValidation(ValidationToken::Switch);
    beginLine();
    buff << "case " << val << ":";
    beginScope();
    pushValidation(ValidationToken::SwitchCase);
}

void CppGenerator::doSwitchEndCase() {
    if (dummy)
        return;
    popValidation(ValidationToken::SwitchCase);
    endScope();
}

void CppGenerator::doEndSwitch() {
    if (dummy)
        return;
    popValidation(ValidationToken::Switch);
    endScope(false);
}

void CppGenerator::doMakroIfdef(std::string_view makro) {
    if (dummy)
        return;
    pushValidation(ValidationToken::Makro);

    const bool duplicate = isMakroAlreadyUsed(makro);
    pushMakroFrame(makro, duplicate);

    if (duplicate) {
        return; // preserve existing "" no-op frame behavior
    }

    pendingMakros.push_back(PendingMakro{.kind = PendingMakro::Kind::Ifdef,
                                         .expr = std::string(makro),
                                         .frameIndex = makros.size() - 1});
    ifDefContainsSth = false;
}

void CppGenerator::doMakroIf(std::string_view makro) {
    if (dummy)
        return;
    pushValidation(ValidationToken::Makro);

    const bool duplicate = isMakroAlreadyUsed(makro);
    pushMakroFrame(makro, duplicate);

    if (duplicate) {
        return;
    }

    pendingMakros.push_back(PendingMakro{.kind = PendingMakro::Kind::If,
                                         .expr = std::string(makro),
                                         .frameIndex = makros.size() - 1});
    ifDefContainsSth = false;
}

void CppGenerator::doMakroEndif() {
    if (dummy)
        return;
    popValidation(ValidationToken::Makro);

    auto frame = popMakroFrame();

    // duplicate/no-op frame -> no output
    if (frame.makro.empty()) {
        return;
    }

    // If still pending (never flushed), remove pending entry and emit nothing.
    auto iter = std::ranges::find_if(pendingMakros, [&](const PendingMakro &pendingMakro) -> bool {
        return pendingMakro.expr == frame.makro;
    });
    if (iter != pendingMakros.end() && !frame.opened) {
        pendingMakros.erase(iter);
        return;
    }

    // only close macros that actually started
    if (frame.opened) {
        depth--;
        beginLine();
        buff << "#endif // " << frame.makro;
        endLine();
    }
}

void CppGenerator::doBeginNamespace(std::string_view namespace_) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::Namespace);
    pushNamespace(namespace_);
    beginLine();
    buff << "namespace " << namespace_ << " {";
    endLine();
}

void CppGenerator::doEndNamespace() {
    if (dummy)
        return;
    popValidation(ValidationToken::Namespace);
    beginLine();
    buff << "} // namespace " << popNamespace();
    endLine();
}

void CppGenerator::doBeginStruct(std::string_view name, bool empty) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::Struct);
    beginLine();
    buff << "struct " << name;
    if (empty) {
        buff << " {};";
        endLine();
        popValidation(ValidationToken::Struct);
    } else {
        beginScope();
    }
}

void CppGenerator::doEndStruct() {
    if (dummy)
        return;
    popValidation(ValidationToken::Struct);
    endScope(true, true);
}

void CppGenerator::doBeginUnion(std::string_view name, bool empty) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::Union);
    beginLine();
    buff << "union " << name;
    if (empty) {
        buff << " {};";
        endLine();
        popValidation(ValidationToken::Union);
    } else {
        beginScope();
    }
}

void CppGenerator::doEndUnion() {
    if (dummy)
        return;
    popValidation(ValidationToken::Union);
    endScope(true, true);
}

void CppGenerator::doBeginEnumClass(EnumClass enumClass, bool empty) {
    if (dummy)
        return;
    flushPendingMakros();
    pushValidation(ValidationToken::EnumClass);
    beginLine();
    buff << "enum class " << enumClass.name;
    if (!enumClass.basetype.empty()) {
        buff << " : " << enumClass.basetype;
    }
    if (empty) {
        buff << " {};";
        endLine();
        popValidation(ValidationToken::EnumClass);
    } else {
        beginScope();
    }
}

void CppGenerator::doEndEnumClass() {
    if (dummy)
        return;
    popValidation(ValidationToken::EnumClass);
    endScope(true, true);
}

void CppGenerator::startHeader() {
    if (dummy)
        return;
    flushPendingMakros();
    beginLine();
    buff << "#pragma once";
    endLine();
    doEmptyLine();
}

void CppGenerator::doIncludesLocal(const std::set<std::string> &includes) {
    if (dummy)
        return;
    flushPendingMakros();
    for (const auto &include : includes) {
        beginLine();
        buff << "#include \"" << include << "\"";
        endLine();
    }
    doEmptyLine();
}

void CppGenerator::doIncludesGlobal(const std::set<std::string> &includes) {
    if (dummy)
        return;
    flushPendingMakros();
    for (const auto &include : includes) {
        beginLine();
        buff << "#include <" << include << ">";
        endLine();
    }
    doEmptyLine();
}

void CppGenerator::doEmptyLine() {
    if (dummy)
        return;
    flushPendingMakros();
    beginLine();
    endLine();
}

void CppGenerator::doCode(std::string_view code) {
    if (dummy)
        return;
    if (code.empty())
        return;
    flushPendingMakros();
    beginLine();
    for (const char character : code) {
        if (character == '\r') {
            continue;
        }
        if (character == '\n') {
            endLine();
            beginLine();
        } else {
            buff << character;
        }
    }
    endLine();
}

void CppGenerator::doWriteLine(std::string_view line) {
    if (dummy)
        return;
    flushPendingMakros();
    beginLine();
    buff << line;
    endLine();
}

void CppGenerator::doWriteLine(std::stringstream &line) {
    if (dummy)
        return;
    flushPendingMakros();
    beginLine();
    buff << line.rdbuf();
    endLine();
}

auto CppGenerator::makeConditionOneOf(std::string_view var, const std::vector<std::string> &vals)
    -> std::string {
    return std::ranges::to<std::string>(vals | std::views::transform([&var](const auto &val) {
                                            return std::format("{} == {}", var, val);
                                        }) |
                                        std::views::join_with(std::string_view{" ||"}));
}

auto CppGenerator::makeConditionNotOneOf(std::string_view var, const std::vector<std::string> &vals)
    -> std::string {
    return std::ranges::to<std::string>(vals | std::views::transform([&var](const auto &val) {
                                            return std::format("{} != {}", var, val);
                                        }) |
                                        std::views::join_with(std::string_view{" &&"}));
}

void CppGenerator::write(const std::filesystem::path &path) const {
    if (dummy)
        return;
    std::ofstream out(path);
    out << buff.rdbuf();
}
