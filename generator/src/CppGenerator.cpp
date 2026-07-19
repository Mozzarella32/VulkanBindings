#include "CppGenerator.hpp"
#include <fstream>
#include <iostream>

auto TypeAndName::preTypePrint() const -> std::string {
    std::string s = leading;
    if (!s.empty()) {
        if (s.back() != ' ')
            s.push_back(' ');
    }
    return s;
}

auto TypeAndName::postTypePrint() const -> std::string {
    std::string s = postType;
    if (!s.empty()) {
        if (s.front() != ' ')
            s.insert(s.begin(), ' ');
        if (s.back() != ' ')
            s.push_back(' ');
    } else {
        s = " ";
    }
    return s;
}

auto TypeAndName::postArgumentPrint() const -> std::string { return trailing; }

auto TypeAndName::fullType(bool insertSpace) const -> std::string {
    std::string s = leading;
    if (!s.empty())
        s += " ";
    s += baseType;
    std::string pt = postType;
    if (!pt.empty()) {
        if (pt.front() != ' ')
            s += " ";
        s += pt;
    } else if (insertSpace) {
        s += " ";
    }
    return s;
}

auto Function::deleteArg(size_t i) -> Function & {
    assert(i < args.size());
    args.erase(args.begin() + static_cast<decltype(args)::iterator::difference_type>(i));
    return *this;
}
auto Function::addArg(size_t i, const Argument &arg) -> Function & {
    assert(i < args.size());
    args.insert(args.begin() + static_cast<decltype(args)::iterator::difference_type>(i), arg);
    return *this;
}
auto Function::replaceArg(size_t i, const Argument &arg) -> Function & {
    assert(i < args.size());
    args[i] = arg;
    return *this;
}

auto Function::replaceArg(size_t i, const std::string &str) -> Function & {
    assert(i < args.size());
    args[i].name = str;
    return *this;
}

auto Function::replaceReturnType(const std::string &newReturnType) -> Function {
    returnType = newReturnType;
    return *this;
}

auto Function::replaceName(const std::string &newName) -> Function {
    name = newName;
    return *this;
}

auto Function::toSignature(bool inClassBody) const -> std::string {
    std::stringstream s;

    if (isStatic && inClassBody) {
        s << "static ";
    }

    if (isConst && inClassBody && returnType != "void") {
        s << "[[nodiscard]] ";
    }

    s << "auto ";

    if (!inClassBody && className != "") {
        s << className << "::";
    }

    s << name << "(";
    for (size_t i = 0; i < args.size(); i++) {
        const auto &arg = args[i];
        s << arg.fullType() << arg.name << arg.postArgumentPrint();
        if (i != args.size() - 1) {
            s << ", ";
        }
    }
    s << ")";

    if (isConst)
        s << " const";
    if (isNoexcept)
        s << " noexcept";

    if (!returnType.empty()) {
        s << " -> " << returnType;
    }

    return s.str();
}

auto Function::toArgList() const -> std::vector<std::string> {
    std::vector<std::string> argList;
    for (const auto &arg : args) {
        argList.push_back(arg.name);
    }
    return argList;
}

auto Function::toCall() const -> std::string {
    std::stringstream s;
    if (objectName != "") {
        s << objectName;
        if (objectIsPointer)
            s << "->";
        else
            s << ".";
    }
    s << name << "(";
    for (size_t i = 0; i < args.size(); i++) {
        s << args[i].name;
        if (i != args.size() - 1) {
            s << ", ";
        }
    }
    s << ")";
    return s.str();
}

auto Function::toCallReturn() const -> std::string {
    if (returnType == "void") {
        return toCall();
    } else {
        return "return " + toCall();
    }
}

auto Function::toFunctionPtr(const std::string &convention, const std::string &namePrefix) const
    -> std::string {
    std::stringstream s;

    if (!className.empty() && !isStatic) {
        s << returnType << " (" << convention << " " << className << "::*" << namePrefix << name
          << ")(";
    } else {
        s << returnType << " (" << convention << " *" << namePrefix << name << ")(";
    }

    if (args.empty()) {
        s << "void";
    } else {
        for (size_t i = 0; i < args.size(); ++i) {
            const auto &arg = args[i];

            s << arg.fullType(false);
            s << arg.postArgumentPrint();

            if (i + 1 != args.size())
                s << ", ";
        }
    }

    s << ")";

    if (!className.empty() && !isStatic && isConst) {
        s << " const";
    }

    if (isNoexcept) {
        s << " noexcept";
    }

    return s.str();
}

auto Function::toModernFunctionPtr(const std::string &convention) const -> std::string {
    std::stringstream s;

    s << "auto (";
    if (!convention.empty())
        s << convention << " ";

    s << "*";

    s << ")(";
    if (args.empty()) {
        s << "void";
    } else {
        for (size_t i = 0; i < args.size(); ++i) {
            const auto &arg = args[i];
            s << arg.fullType(false);
            s << arg.postArgumentPrint();
            if (i + 1 != args.size())
                s << ", ";
        }
    }
    s << ")";

    if (!className.empty() && !isStatic && isConst) {
        s << " const";
    }
    if (isNoexcept) {
        s << " noexcept";
    }

    s << " -> " << returnType;

    return s.str();
}

void CppGenerator::pushValidation(ValidationToken vt) { validationStack.push_back(vt); }

void CppGenerator::popValidation(ValidationToken vt) {
    if (validationStack.empty()) {
        std::cerr << "CppGenerator: validation stack empty (expected different token)\n";
        assert(false);
        return;
    }
    auto vt_stack = validationStack.back();
    validationStack.pop_back();
    if (vt != vt_stack) {
        std::cerr << "CppGenerator: syntax validation failed (expected different token)\n";
        assert(false);
        return;
    }
}

auto CppGenerator::pushMakro(const std::string &makro) -> bool {
    if (auto it = std::ranges::find(makros, makro); it != std::end(makros)) {
        makros.emplace_back("");
        return true;
    }
    makros.push_back(makro);
    return false;
}

auto CppGenerator::popMakro() -> std::string {
    if (makros.empty()) {
        std::cerr << "CppGenerator: makros empty on pop\n";
        assert(false);
        return "";
    }

    std::string s = makros.back();
    makros.pop_back();
    return s;
}

void CppGenerator::pushNamespace(const std::string &namespace_) {
    namespaces.push_back(namespace_);
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

void CppGenerator::beginScope(bool indent, const std::string &comment) {
    buff << " {";
    if (comment != "") {
        buff << " // " << comment;
    }
    endLine();
    if (indent) {
        depth++;
    }
}
void CppGenerator::doLineBeginScope(const std::string &s, const std::string &comment) {
    beginLine();
    buff << s;
    beginScope(true, comment);
}
void CppGenerator::doLineBeginScope(std::stringstream &s) {
    beginLine();
    buff << s.rdbuf();
    beginScope();
}
void CppGenerator::endScope(bool indent, bool semicolon) {
    if (indent) {
        depth--;
    }
    beginLine();
    buff << "}";
    if (semicolon) {
        buff << ";";
    }
    endLine();
}

void CppGenerator::doIf(const std::string &cond) {
    pushValidation(ValidationToken::If);
    beginLine();
    buff << "if (" << cond << ")";
    beginScope();
}

void CppGenerator::doIfWithInitializer(const std::string &init, const std::string &cond) {
    pushValidation(ValidationToken::If);
    beginLine();
    buff << "if (" << init << "; " << cond << ")";
    beginScope();
}

void CppGenerator::doElseIf(const std::string &cond) {
    popValidation(ValidationToken::If);
    endScope();
    beginLine();
    buff << "else if(" << cond << ")";
    beginScope();
    pushValidation(ValidationToken::If);
}

void CppGenerator::doElse() {
    popValidation(ValidationToken::If);
    endScope();
    beginLine();
    buff << "else";
    beginScope();
    pushValidation(ValidationToken::If);
}

void CppGenerator::doIfEnd() {
    popValidation(ValidationToken::If);
    endScope();
}

void CppGenerator::doReturn(const std::string &expr) {
    beginLine();
    buff << "return " << expr << ";";
    endLine();
}

void CppGenerator::doFor(const std::string &initilizer, const std::string &condition,
                         const std::string &increment) {
    pushValidation(ValidationToken::For);
    beginLine();
    buff << "for (" << initilizer << "; " << condition << "; " << increment << ")";
    beginScope();
}

void CppGenerator::doRangedFor(const std::string &var, const std::string &container) {
    pushValidation(ValidationToken::For);
    beginLine();
    buff << "for (" << var << " : " << container << ")";
    beginScope();
}

void CppGenerator::doForEnd() {
    popValidation(ValidationToken::For);
    endScope();
}

void CppGenerator::doSwitch(const std::string &var) {
    pushValidation(ValidationToken::Switch);
    beginLine();
    buff << "switch (" << var << ")";
    beginScope(false);
}

void CppGenerator::doSwitchCase(const std::string &val) {
    popValidation(ValidationToken::Switch);
    pushValidation(ValidationToken::Switch);
    beginLine();
    buff << "case " << val << ":";
    beginScope();
    pushValidation(ValidationToken::SwitchCase);
}

void CppGenerator::doSwitchEndCase() {
    popValidation(ValidationToken::SwitchCase);
    endScope();
}

void CppGenerator::doEndSwitch() {
    popValidation(ValidationToken::Switch);
    endScope(false);
}

void CppGenerator::doMakroIfdef(const std::string &makro) {
    pushValidation(ValidationToken::Makro);
    if (pushMakro(makro))
        return;
    beginLine();
    buff << "#ifdef " << makro;
    depth++;
    endLine();
    ifDefContainsSth = false;
}

void CppGenerator::doMakroIf(const std::string &makro) {
    pushValidation(ValidationToken::Makro);
    if (pushMakro(makro))
        return;
    beginLine();
    buff << "#if " << makro;
    depth++;
    endLine();
    ifDefContainsSth = false;
}

void CppGenerator::doMakroEndif() {
    popValidation(ValidationToken::Makro);
    if (std::string makro = popMakro(); makro != "") {
        if (!ifDefContainsSth) {
            std::cerr << "Makro guard " << makro << " did not contain sth\n";
            assert(false);
        }
        depth--;
        beginLine();
        buff << "#endif // " << makro;
        endLine();
    }
}

void CppGenerator::doBeginNamespace(const std::string &namespace_) {
    pushValidation(ValidationToken::Namespace);
    pushNamespace(namespace_);
    beginLine();
    buff << "namespace " << namespace_ << " {";
    endLine();
}

void CppGenerator::doEndNamespace() {
    popValidation(ValidationToken::Namespace);
    beginLine();
    buff << "} // " << popNamespace();
    endLine();
}

void CppGenerator::doBeginStruct(const std::string &name, bool empty) {
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
    popValidation(ValidationToken::Struct);
    endScope(true, true);
}

void CppGenerator::doBeginUnion(const std::string &name, bool empty) {
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
    popValidation(ValidationToken::Union);
    endScope(true, true);
}

void CppGenerator::doBeginEnumClass(const std::string &name, const std::string &basetype,
                                    bool empty) {
    pushValidation(ValidationToken::EnumClass);
    beginLine();
    buff << "enum class " << name;
    if (basetype != "") {
        buff << " : " << basetype;
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
    popValidation(ValidationToken::EnumClass);
    endScope(true, true);
}

void CppGenerator::startHeader() {
    beginLine();
    buff << "#pragma once";
    endLine();
    doEmptyLine();
}

void CppGenerator::doIncludesLocal(const std::set<std::string> &includes) {
    for (const auto &include : includes) {
        beginLine();
        buff << "#include \"" << include << "\"";
        endLine();
    }
    doEmptyLine();
}

void CppGenerator::doIncludesGlobal(const std::set<std::string> &includes) {
    for (const auto &include : includes) {
        beginLine();
        buff << "#include <" << include << ">";
        endLine();
    }
    doEmptyLine();
}

void CppGenerator::doEmptyLine() {
    beginLine();
    endLine();
}

void CppGenerator::doCode(const std::string &code) {
    if (code.empty())
        return;
    beginLine();
    for (char ch : code) {
        if (ch == '\r') {
            continue;
        }
        if (ch == '\n') {
            endLine();
            beginLine();
        } else {
            buff << ch;
        }
    }
    endLine();
}

void CppGenerator::doWriteLine(const std::string &line) {
    beginLine();
    buff << line;
    endLine();
}

void CppGenerator::doWriteLine(std::stringstream &line) {
    beginLine();
    buff << line.rdbuf();
    endLine();
}

auto CppGenerator::makeConditionOneOf(const std::string &var, const std::vector<std::string> &vals)
    -> std::string {
    std::stringstream s;
    for (size_t i = 0; i < vals.size(); i++) {
        s << var << " == " << vals[i];
        if (i != vals.size() - 1) {
            s << " || ";
        }
    }
    return s.str();
}

auto CppGenerator::makeConditionNotOneOf(const std::string &var,
                                         const std::vector<std::string> &vals) -> std::string {
    std::stringstream s;
    for (size_t i = 0; i < vals.size(); i++) {
        s << var << " != " << vals[i];
        if (i != vals.size() - 1) {
            s << " && ";
        }
    }
    return s.str();
}

void CppGenerator::write(const std::filesystem::path &path) {
    std::ofstream out(path);
    out << buff.rdbuf();
}
