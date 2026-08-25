#pragma once

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <filesystem>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

// NOLINTBEGIN(misc-non-private-member-variables-in-classes)
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
// NOLINTEND(misc-non-private-member-variables-in-classes)

struct FunctionInfo;
struct StructInfo;
struct ObjectInfo;

struct Function {
  private:
    std::string name;
    std::vector<std::string> successcodes;
    std::vector<std::string> errorcodes;

  public:
    struct Argument : public TypeAndName {
        static auto fromTypeAndName(TypeAndName &&typeAndName) -> Argument {
            Argument argument;
            *static_cast<TypeAndName *>(&argument) = std::move(typeAndName);
            return argument;
        }
        std::optional<size_t> arrayWithLengthOf;
        bool optional : 1 = false;
    };

    auto deleteArg(size_t idx) -> Function &;
    auto addArg(size_t idx, const Argument &arg) -> Function &;
    auto addArg(size_t idx, std::string_view arg) -> Function &;
    auto replaceArg(size_t idx, const Argument &arg) -> Function &;
    auto replaceArg(size_t idx, std::string_view str) -> Function &;
    auto replaceReturnType(std::string_view newReturnType) -> Function;
    auto replaceName(std::string_view newName) -> Function;

  private:
    bool isStatic : 1 = false;
    bool isConst : 1 = false;
    bool isNoexcept : 1 = false;
    bool objectIsPointer : 1 = false;

    std::vector<Argument> args;
    std::string returnType;

    std::string className;
    std::string objectName;

  public:
    Function() = default;
    Function(std::string name, std::vector<std::string> successcodes,
             std::vector<std::string> errorcodes, bool isStatic, bool isConst, bool isNoexcept,
             bool objectIsPointer, std::vector<Argument> args, std::string returnType,
             std::string className, std::string objectName);

    [[nodiscard]] auto getName() const -> std::string;

    [[nodiscard]] auto toSignature(bool inClassBody = false) const -> std::string;
    [[nodiscard]] auto toArgList() const -> std::vector<std::string>;
    [[nodiscard]] auto toCall() const -> std::string;
    [[nodiscard]] auto toCallReturn() const -> std::string;
    [[nodiscard]] auto toFunctionPtr(std::string_view convention, std::string_view namePrefix) const
        -> std::string;
    [[nodiscard]] auto toModernFunctionPtr(std::string_view convention) const -> std::string;

    friend FunctionInfo; // These are bad and should be replaced with actuall accessors
    friend StructInfo;
    friend ObjectInfo;
};

class CppGenerator {
    std::stringstream buff;
    size_t depth = 0;

  private:
    enum class ValidationToken : std::uint8_t {
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

    void pushValidation(ValidationToken validationToken);
    void popValidation(ValidationToken validationToken);

    // empty means it was covered by a previouse makro
    std::vector<std::string> makros;

    // true if corresponding frame in `makros` actually emitted #if/#ifdef
    std::vector<bool> makroOpened;

    struct PendingMakro {
        enum class Kind : std::uint8_t { Ifdef, If } kind;
        std::string expr;
        size_t frameIndex; // index into makros/makroOpened
    };
    std::vector<PendingMakro> pendingMakros;

    auto isMakroAlreadyUsed(std::string_view makro) const -> bool;
    void pushMakroFrame(std::string_view makro, bool duplicate);
    struct PoppedMakroFrame {
        std::string makro;
        bool opened = false;
    };
    auto popMakroFrame() -> PoppedMakroFrame;
    void flushPendingMakros();

    std::vector<std::string> namespaces;
    void pushNamespace(std::string_view namespace_);
    auto popNamespace() -> std::string;

    bool ifDefContainsSth = true;

    void beginLine();
    void endLine();

  public:
    void beginScope(bool indent = true, std::optional<std::string_view> comment = std::nullopt);

    void doLineBeginScope(std::string_view line,
                          std::optional<std::string_view> comment = std::nullopt);
    void doLineBeginScope(std::stringstream &line);
    void endScope(bool indent = true, bool semicolon = false);

    void doIf(std::string_view cond);
    void doIfWithInitializer(std::string_view init, std::string_view cond);
    void doElseIf(std::string_view cond);
    void doElse();
    void doIfEnd();

    void doReturn(std::string_view expr = "");

    void doFor(std::string_view initilizer, std::string_view condition, std::string_view increment);

    void doRangedFor(std::string_view var, std::string_view container);
    void doForEnd();

    void doSwitch(std::string_view var);
    void doSwitchCase(std::string_view val);
    void doSwitchEndCase();
    void doEndSwitch();

    void doMakroIfdef(std::string_view makro);
    void doMakroIf(std::string_view makro);
    void doMakroEndif();

    void doBeginNamespace(std::string_view namespace_);
    void doEndNamespace();

    struct Struct {
        std::string_view name;
        std::string_view attributes;
        bool empty = false;
    };
    void doBeginStruct(const Struct &structInfo);
    void doEndStruct();

    struct Union {
        std::string_view name;
        std::string_view attributes;
        bool empty = false;
    };
    void doBeginUnion(const Union &unionInfo);
    void doEndUnion();

    struct EnumClass {
        std::string_view name;
        std::string_view attributes;
        std::string_view basetype;
        bool empty = false;
    };
    void doBeginEnumClass(const EnumClass &enumClass);
    void doEndEnumClass();

    void startHeader();
    void doIncludesLocal(const std::set<std::string> &includes);
    void doIncludesGlobal(const std::set<std::string> &includes);

    void doEmptyLine();

    void doCode(std::string_view code);
    void doWriteLine(std::string_view line);
    void doWriteLine(std::stringstream &line);

    static auto makeConditionOneOf(std::string_view var, const std::vector<std::string> &vals)
        -> std::string;
    static auto makeConditionNotOneOf(std::string_view var, const std::vector<std::string> &vals)
        -> std::string;

    void write(const std::filesystem::path &path) const;
};
