#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct CppGenerator {
    std::stringstream buff;
    int depth = 0;

  private:
    enum class ValidationToken { If, For, RangedFor, Makro, Namespace, Struct };

    std::vector<ValidationToken> validationStack;

    void pushValidation(ValidationToken vt) { validationStack.push_back(vt); }

    void popValidation(ValidationToken vt) {
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

    // empty means it was covered by a previouse makro
    std::vector<std::string> makros;

    // return true if already in use
    bool pushMakro(const std::string &makro) {
        if (auto it = std::ranges::find(makros, makro); it != std::end(makros)) {
            makros.push_back("");
            return true;
        }
        makros.push_back(makro);
        return false;
    }

    std::string popMakro() {
        if (makros.empty()) {
            std::cerr << "CppGenerator: makros empty on pop\n";
            assert(false);
            return "";
        }

        std::string s = makros.back();
        makros.pop_back();
        return s;
    }

    std::vector<std::string> namespaces;
    void pushNamespace(const std::string &namespace_) { namespaces.push_back(namespace_); }

    std::string popNamespace() {
        if (namespaces.empty()) {
            std::cerr << "CppGenerator: namespaces empty on pop\n";
            assert(false);
            return "";
        }
        std::string namespace_ = namespaces.back();
        namespaces.pop_back();
        return namespace_;
    }

    bool ifDefContainsSth = true;

    void beginLine() { buff << std::string(depth, '\t'); }
    void endLine() {
        buff << '\n';
        ifDefContainsSth = true;
    }

  public:
    void beginScope() {
        buff << " {";
        endLine();
        depth++;
    }
    void doLineBeginScope(const std::string &s) {
        beginLine();
        buff << s;
        beginScope();
    }
    void doLineBeginScope(std::stringstream &s) {
        beginLine();
        buff << s.rdbuf();
        beginScope();
    }
    void endScope(bool semicolon = false) {
        depth--;
        beginLine();
        buff << "}";
        if (semicolon) {
            buff << ";";
        }
        endLine();
    }

  public:
    void doIf(const std::string &cond) {
        pushValidation(ValidationToken::If);
        beginLine();
        buff << "if (" << cond << ")";
        beginScope();
    }

    void doIfWithInitializer(const std::string &init, const std::string &cond) {
        pushValidation(ValidationToken::If);
        beginLine();
        buff << "if (" << init << "; " << cond << ")";
        beginScope();
    }

    void doElseIf(const std::string &cond) {
        popValidation(ValidationToken::If);
        endScope();
        beginLine();
        buff << "else if(" << cond << ")";
        beginScope();
        pushValidation(ValidationToken::If);
    }

    void doElse() {
        popValidation(ValidationToken::If);
        endScope();
        beginLine();
        buff << "else";
        beginScope();
        pushValidation(ValidationToken::If);
    }

    void doIfEnd() {
        popValidation(ValidationToken::If);
        endScope();
    }

    void doReturn(const std::string &expr) {
        beginLine();
        buff << "return " << expr << ";";
        endLine();
    }

    void doFor(const std::string &initilizer, const std::string &condition,
               const std::string &increment) {
        pushValidation(ValidationToken::For);
        beginLine();
        buff << "for (" << initilizer << "; " << condition << "; " << increment << ")";
        beginScope();
    }

    void doRangedFor(const std::string &var, const std::string &container) {
        pushValidation(ValidationToken::For);
        beginLine();
        buff << "for (" << var << " : " << container << ")";
        beginScope();
    }

    void doForEnd() {
        popValidation(ValidationToken::For);
        endScope();
    }

    void doMakroIfdef(const std::string &makro) {
        pushValidation(ValidationToken::Makro);
        if (pushMakro(makro))
            return;
        beginLine();
        buff << "#ifdef " << makro;
        depth++;
        endLine();
        ifDefContainsSth = false;
    }

    void doMakroIf(const std::string &makro) {
        pushValidation(ValidationToken::Makro);
        if (pushMakro(makro))
            return;
        beginLine();
        buff << "#if " << makro;
        depth++;
        endLine();
        ifDefContainsSth = false;
    }

    void doMakroEndif() {
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

    void doBeginNamespace(const std::string &namespace_) {
        pushValidation(ValidationToken::Namespace);
        pushNamespace(namespace_);
        beginLine();
        buff << "namespace " << namespace_ << " {";
        endLine();
    }

    void doEndNamespace() {
        popValidation(ValidationToken::Namespace);
        beginLine();
        buff << "} // " << popNamespace();
        endLine();
    }

    void doBeginStruct(const std::string &name, bool empty = false) {
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

    void doEndStruct() {
        popValidation(ValidationToken::Struct);
        endScope(true);
    }

    void startHeader() {
        beginLine();
        buff << "#pragma once";
        endLine();
        doEmptyLine();
    }

    void doIncludeLocal(const std::string &include) {
        beginLine();
        buff << "#include \"" << include << "\"";
        endLine();
    }

    void doIncludeGlobal(const std::string &include) {
        beginLine();
        buff << "#include <" << include << ">";
        endLine();
    }

    void doEmptyLine() {
        beginLine();
        endLine();
    }

    void doCode(const std::string &code) {
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

    void doWriteLine(const std::string &line) {
        beginLine();
        buff << line;
        endLine();
    }
    void doWriteLine(std::stringstream &line) {
        beginLine();
        buff << line.rdbuf();
        endLine();
    }
};
