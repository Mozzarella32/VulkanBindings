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
        bool optional : 1 = false;

        std::string preTypePrint() const;
        std::string postTypePrint() const;
        // [sth]
        std::string postArgumentPrint() const;
        std::string fullType() const;

        Argument &replaceName(const std::string &name);
        Argument &replaceBaseType(const std::string &name);
    };

    Function &deleteArg(size_t i);
    Function &addArg(size_t i, const Argument &arg);
    Function &addArg(size_t i, const std::string &arg);
    Function &replaceArg(size_t i, const Argument &arg);
    Function &replaceArg(size_t i, const std::string &str);
    Function replaceReturnType(const std::string &newReturnType);
    Function replaceName(const std::string &newName);

    std::vector<Argument> args;
    std::string returnType;

    std::string toSignature(const std::string &className = "");
    std::string toSignatureConst(const std::string &className = "");
    std::vector<std::string> toArgList() const;
    std::string toCall(const std::string &obj = "");
    std::string toCallReturn(const std::string &obj = "");
};

struct CppGenerator {
    std::stringstream buff;
    size_t depth = 0;

  private:
    enum class ValidationToken { If, For, RangedFor, Makro, Namespace, Struct };

    std::vector<ValidationToken> validationStack;

    void pushValidation(ValidationToken vt);

    void popValidation(ValidationToken vt);

    // empty means it was covered by a previouse makro
    std::vector<std::string> makros;

    // return true if already in use
    bool pushMakro(const std::string &makro);

    std::string popMakro();

    std::vector<std::string> namespaces;
    void pushNamespace(const std::string &namespace_);

    std::string popNamespace();

    bool ifDefContainsSth = true;

    void beginLine();
    void endLine();

  public:
    void beginScope(const std::string& comment = "");
    void doLineBeginScope(const std::string &s, const std::string& comment = "");
    void doLineBeginScope(std::stringstream &s);
    void endScope(bool semicolon = false);

  public:
    void doIf(const std::string &cond);
    void doIfWithInitializer(const std::string &init, const std::string &cond);
    void doElseIf(const std::string &cond);
    void doElse();
    void doIfEnd();

    void doReturn(const std::string &expr);

    void doFor(const std::string &initilizer, const std::string &condition,
               const std::string &increment);
    void doRangedFor(const std::string &var, const std::string &container);
    void doForEnd();

    void doMakroIfdef(const std::string &makro);
    void doMakroIf(const std::string &makro);
    void doMakroEndif();

    void doBeginNamespace(const std::string &namespace_);
    void doEndNamespace();

    void doBeginStruct(const std::string &name, bool empty = false);
    void doEndStruct();

    void startHeader();
    void doIncludeLocal(const std::string &include);
    void doIncludeGlobal(const std::string &include);

    void doEmptyLine();

    void doCode(const std::string &code);
    void doWriteLine(const std::string &line);
    void doWriteLine(std::stringstream &line);

    static std::string makeConditionOneOf(const std::string &var,
                                          const std::vector<std::string> &vals);
    static std::string makeConditionNotOneOf(const std::string &var,
                                             const std::vector<std::string> &vals);
};
