#include "CppGenerator.hpp"
#include <fstream>
#include <iostream>

std::string TypeAndName::preTypePrint() const {
    std::string s = leading;
    if (!s.empty()) {
        if (s.back() != ' ')
            s.push_back(' ');
    }
    return s;
}

std::string TypeAndName::postTypePrint() const {
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

std::string TypeAndName::postArgumentPrint() const { return trailing; }

std::string TypeAndName::fullType() const {
    std::string s = leading;
    if (!s.empty())
        s += " ";
    s += baseType;
    std::string pt = postType;
    if (!pt.empty()) {
        if (pt.front() != ' ')
            s += " ";
        s += pt;
    } else {
        s += " ";
    }
    return s;
}

Function &Function::deleteArg(size_t i) {
    assert(i < args.size());
    args.erase(args.begin() + static_cast<decltype(args)::iterator::difference_type>(i));
    return *this;
}
Function &Function::addArg(size_t i, const Argument &arg) {
    assert(i < args.size());
    args.insert(args.begin() + static_cast<decltype(args)::iterator::difference_type>(i), arg);
    return *this;
}
Function &Function::replaceArg(size_t i, const Argument &arg) {
    assert(i < args.size());
    args[i] = arg;
    return *this;
}

Function &Function::replaceArg(size_t i, const std::string &str) {
    assert(i < args.size());
    args[i].name = str;
    return *this;
}

Function Function::replaceReturnType(const std::string &newReturnType) {
    returnType = newReturnType;
    return *this;
}

Function Function::replaceName(const std::string &newName) {
    name = newName;
    return *this;
}

std::string Function::toSignature(const std::string &className) {
    std::stringstream s;
    s << returnType << " ";
    if (className != "") {
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
    return s.str();
}

std::string Function::toSignatureConst(const std::string &className) {
    return toSignature(className) + " const";
}

std::vector<std::string> Function::toArgList() const {
    std::vector<std::string> argList;
    for (const auto &arg : args) {
        argList.push_back(arg.name);
    }
    return argList;
}

std::string Function::toCall(const std::string &obj) {
    std::stringstream s;
    if (obj != "") {
        s << obj << ".";
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

std::string Function::toCallReturn(const std::string &obj) {
    if (returnType == "void") {
        return toCall(obj);
    } else {
        return "return " + toCall(obj);
    }
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

bool CppGenerator::pushMakro(const std::string &makro) {
    if (auto it = std::ranges::find(makros, makro); it != std::end(makros)) {
        makros.push_back("");
        return true;
    }
    makros.push_back(makro);
    return false;
}

std::string CppGenerator::popMakro() {
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

std::string CppGenerator::popNamespace() {
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

void CppGenerator::beginScope(const std::string &comment) {
    buff << " {";
    if (comment != "") {
        buff << " // " << comment;
    }
    endLine();
    depth++;
}
void CppGenerator::doLineBeginScope(const std::string &s, const std::string &comment) {
    beginLine();
    buff << s;
    beginScope(comment);
}
void CppGenerator::doLineBeginScope(std::stringstream &s) {
    beginLine();
    buff << s.rdbuf();
    beginScope();
}
void CppGenerator::endScope(bool semicolon) {
    depth--;
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
    endScope(true);
}

void CppGenerator::doBeginUnion(const std::string &name, bool empty) {
    pushValidation(ValidationToken::Union);
    beginLine();
    buff << "union " << name;
    if (empty) {
        buff << " {};";
        endLine();
        popValidation(ValidationToken::Struct);
    } else {
        beginScope();
    }
}

void CppGenerator::doEndUnion() {
    popValidation(ValidationToken::Union);
    endScope(true);
}

void CppGenerator::startHeader() {
    beginLine();
    buff << "#pragma once";
    endLine();
    doEmptyLine();
}

void CppGenerator::doIncludeLocal(const std::string &include) {
    beginLine();
    buff << "#include \"" << include << "\"";
    endLine();
}

void CppGenerator::doIncludeGlobal(const std::string &include) {
    beginLine();
    buff << "#include <" << include << ">";
    endLine();
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

std::string CppGenerator::makeConditionOneOf(const std::string &var,
                                             const std::vector<std::string> &vals) {
    std::stringstream s;
    for (size_t i = 0; i < vals.size(); i++) {
        s << var << " == " << vals[i];
        if (i != vals.size() - 1) {
            s << " || ";
        }
    }
    return s.str();
}

std::string CppGenerator::makeConditionNotOneOf(const std::string &var,
                                                const std::vector<std::string> &vals) {
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
    std::ofstream o(path);
    o << buff.rdbuf();
}
