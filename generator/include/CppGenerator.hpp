#pragma once

#include <cassert>
#include <filesystem>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <vector>

struct TypeAndName {
    std::string name;
    std::string baseType;
    std::string leading;
    std::string postType;
    std::string trailing;

    [[nodiscard]] auto preTypePrint() const -> std::string;
    [[nodiscard]] auto postTypePrint() const -> std::string;
    [[nodiscard]] auto postArgumentPrint() const -> std::string;
    [[nodiscard]] auto fullType(bool insertSpace = true) const -> std::string;
};

struct Function {
    std::string name;
    std::vector<std::string> successcodes;
    std::vector<std::string> errorcodes;

    struct Argument : public TypeAndName {
        auto operator=(TypeAndName &&tan) -> Argument & {
            *static_cast<TypeAndName *>(this) = std::move(tan);
            return *this;
        }

        std::optional<size_t> arrayWithLengthOf;
        bool optional : 1 = false;
    };

    auto deleteArg(size_t i) -> Function &;
    auto addArg(size_t i, const Argument &arg) -> Function &;
    auto addArg(size_t i, const std::string &arg) -> Function &;
    auto replaceArg(size_t i, const Argument &arg) -> Function &;
    auto replaceArg(size_t i, const std::string &str) -> Function &;
    auto replaceReturnType(const std::string &newReturnType) -> Function;
    auto replaceName(const std::string &newName) -> Function;

    bool isStatic : 1 = false;
    bool isConst : 1 = false;
    bool isNoexcept : 1 = false;
    bool objectIsPointer : 1 = false;

    std::vector<Argument> args;
    std::string returnType;

    std::string className;
    std::string objectName;

    [[nodiscard]] auto toSignature(bool inClassBody = false) const -> std::string;
    [[nodiscard]] auto toArgList() const -> std::vector<std::string>;
    [[nodiscard]] auto toCall() const -> std::string;
    [[nodiscard]] auto toCallReturn() const -> std::string;
    [[nodiscard]] auto toFunctionPtr(const std::string &convention,
                                     const std::string &namePrefix) const -> std::string;
    [[nodiscard]] auto toModernFunctionPtr(const std::string &convention) const -> std::string;
};

struct CppGenerator {
    std::stringstream buff;
    size_t depth = 0;

  private:
    enum class ValidationToken {
        If,
        For,
        RangedFor,
        Makro,
        Namespace,
        Struct,
        Union,
        EnumClass,
        Switch,
        SwitchCase
    };

    std::vector<ValidationToken> validationStack;

    void pushValidation(ValidationToken vt);
    void popValidation(ValidationToken vt);

    // empty means it was covered by a previouse makro
    std::vector<std::string> makros;

    // true if corresponding frame in `makros` actually emitted #if/#ifdef
    std::vector<bool> makroOpened;

    struct PendingMakro {
        enum class Kind { Ifdef, If } kind;
        std::string expr;
        size_t frameIndex; // index into makros/makroOpened
    };
    std::vector<PendingMakro> pendingMakros;

    auto isMakroAlreadyUsed(const std::string &makro) const -> bool;
    void pushMakroFrame(const std::string &makro, bool duplicate);
    struct PoppedMakroFrame {
        std::string makro;
        bool opened = false;
    };
    auto popMakroFrame() -> PoppedMakroFrame;
    void flushPendingMakros();

    std::vector<std::string> namespaces;
    void pushNamespace(const std::string &namespace_);
    auto popNamespace() -> std::string;

    bool ifDefContainsSth = true;

    void beginLine();
    void endLine();

  public:
    void beginScope(bool indent = true, const std::string &comment = "");
    void doLineBeginScope(const std::string &s, const std::string &comment = "");
    void doLineBeginScope(std::stringstream &s);
    void endScope(bool indent = true, bool semicolon = false);

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

    void doSwitch(const std::string &var);
    void doSwitchCase(const std::string &val);
    void doSwitchEndCase();
    void doEndSwitch();

    void doMakroIfdef(const std::string &makro);
    void doMakroIf(const std::string &makro);
    void doMakroEndif();

    void doBeginNamespace(const std::string &namespace_);
    void doEndNamespace();

    void doBeginStruct(const std::string &name, bool empty = false);
    void doEndStruct();

    void doBeginUnion(const std::string &name, bool empty = false);
    void doEndUnion();

    void doBeginEnumClass(const std::string &name, const std::string &basetype = "",
                          bool empty = false);
    void doEndEnumClass();

    void startHeader();
    void doIncludesLocal(const std::set<std::string> &includes);
    void doIncludesGlobal(const std::set<std::string> &includes);

    void doEmptyLine();

    void doCode(const std::string &code);
    void doWriteLine(const std::string &line);
    void doWriteLine(std::stringstream &line);

    static auto makeConditionOneOf(const std::string &var, const std::vector<std::string> &vals)
        -> std::string;
    static auto makeConditionNotOneOf(const std::string &var, const std::vector<std::string> &vals)
        -> std::string;

    void write(const std::filesystem::path &path);
};
