#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Function {
    std::string name;
    std::vector<std::string> successcodes;
    std::vector<std::string> errorcodes;

    struct Argument {
        std::string name;
        std::string baseType;
        std::string leading;
        std::string postType;
        std::string trailing;
        std::optional<size_t> arrayWithLengthOf;

        std::string preTypePrint() const {
            std::string s = leading;
            if (!s.empty()) {
                if (s.back() != ' ')
                    s.push_back(' ');
            }
            return s;
        }

        std::string postTypePrint() const {
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

        // [sth]
        std::string postArgumentPrint() const { return trailing; }

        std::string fullType() const {
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

        Argument& replaceName(const std::string &name) {
            this->name = name;
            return *this;
        }
        Argument& replaceBaseType(const std::string &name) {
            this->baseType = name;
            return *this;
        }
    };

    Function &deleteArg(size_t i) {
        assert(i < args.size());
        args.erase(args.begin() + i);
        return *this;
    }
    Function &addArg(size_t i, const Argument &arg) {
        assert(i < args.size());
        args.insert(args.begin() + i, arg);
        return *this;
    }
    Function &addArg(size_t i, const std::string &arg) { return addArg(i, Argument{arg}); }

    Function &replaceArg(size_t i, const Argument &arg) {
        assert(i < args.size());
        args[i] = arg;
        return *this;
    }

    Function &replaceArg(size_t i, const std::string &str) {
        assert(i < args.size());
        args[i].replaceName(str);
        return *this;
    }

    // Function &replaceArg(size_t i, const std::string &arg) { return replaceArg(i, Argument{arg}); }

    Function replaceReturnType(const std::string &newReturnType) {
        returnType = newReturnType;
        return *this;
    }

    Function replaceName(const std::string &newName) {
        name = newName;
        return *this;
    }

    std::vector<Argument> args;
    std::string returnType;

    std::string toSignature(const std::string &className = "") {
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

    std::string toSignatureConst(const std::string &className = "") {
        return toSignature(className) + " const";
    }

    std::vector<std::string> toArgList() const {
        std::vector<std::string> argList;
        for (const auto &arg : args) {
            argList.push_back(arg.name);
        }
        return argList;
    }

    std::string toCall(const std::string &obj = "") {
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

    std::string toCallReturn(const std::string &obj = "") {
        if (returnType == "void") {
            return toCall(obj);
        } else {
            return "return " + toCall(obj);
        }
    }
};

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

    static std::string makeConditionOneOf(const std::string &var,
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

    static std::string makeConditionNotOneOf(const std::string &var,
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
};
