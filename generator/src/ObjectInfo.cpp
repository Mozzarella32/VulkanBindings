#include "ObjectInfo.hpp"
#include "BaseTypeInfo.hpp"
#include "CppGenerator.hpp"
#include "FunctionInfo.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"
#include "StructInfo.hpp"
#include "Writing.hpp"

#include <cassert>
#include <cctype>
#include <functional>
#include <iostream>
#include <queue>
#include <ranges>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace tinyxml2;

std::unordered_map<std::string, std::string> ObjectInfo::enumElementMapping;

auto ObjectInfo::getDepends() const -> const Depends & { return depends; }
auto ObjectInfo::hasFunctions() const -> bool { return !functions.empty(); }
auto ObjectInfo::getName() const -> const std::string & { return name; }

auto ObjectInfo::operator<(const ObjectInfo &other) const -> bool {

    return std::tie(other.rank, depends, name) < std::tie(rank, other.depends, other.name);
}
void ObjectInfo::writeHeader(CppGenerator &gen) const {
    assert(!functions.empty());
    auto epilog = [&]() -> void {
        if (name == "Instance") {
            gen.doCode(R"-(
static const constexpr bool has_handle_constructor = true;
private:
impl_Loader::Dispatcher instanceDispatcher;
protected:
void resetDispatcher() noexcept;
private:
friend impl_Objects::Creator;
Instance(Handle::Instance &&handle);
public:

[[nodiscard]] auto adoptForignSurfaceKHR(SurfaceKHR&& surface) const -> UniqueSurfaceKHR;
)-");
        } else if (name == "Device") {
            gen.doCode(R"-(
static const constexpr bool has_handle_constructor = true;
private:
impl_Loader::Dispatcher deviceDispatcher;
protected:
void resetDispatcher() noexcept;
private:
friend impl_Objects::Creator;
Device(Handle::Device &&handle, const impl_Loader::Dispatcher &instanceDispatcher);
public:
)-");
        }
        if (name == "Instance" || name == "Device") {
            gen.doCode(std::format(R"-({0}(const {0} &other) noexcept;
{0}({0} &&other) noexcept;

auto operator=(const {0} &other) noexcept -> {0} &;
auto operator=({0} &&other) noexcept -> {0} &;

~{0}() = default;
)-",
                                   name));
        }
        gen.doWriteLine(std::format("{}() = default;", name));
        writeDepends(gen, functions, std::bind_back(&FunctionInfo::writeHeader));
        gen.doEndStruct();
    };

    assert(!functions.empty());
    if (destroyFunction.name.empty()) {
        gen.doBeginStruct(name + " : public impl_Objects::" + templateType + templateArgs);
        gen.doWriteLine("using Object::Object;");
        epilog();
        return;
    }

    if (destroyFunction.args.size() == 3) {
        assert(!owner.empty());
        gen.doBeginStruct(name + " : public impl_Objects::" + templateType + templateArgs);
        gen.doWriteLine("using Object::Object;");
        epilog();
        return;
    }
    assert(destroyFunction.args.size() == 2);
    gen.doBeginStruct(name + " : public impl_Objects::" + templateType + templateArgs);
    epilog();
}

void ObjectInfo::writeHandle(CppGenerator &gen) const {
    if (isDispatchable) {
        gen.doWriteLine("VK_BINDINGS_DEFINE_HANDLE(" + name + ")");
    } else {
        gen.doWriteLine("VK_BINDINGS_DEFINE_NON_DISPATCHABLE_HANDLE(" + name + ")");
    }
}

void ObjectInfo::writeForwardDecl(CppGenerator &gen) const {
    if (templateType.empty()) {
        gen.doWriteLine("using " + name + " = impl_Objects::" + templateTypeUnique +
                        templateArgsUnique + ";");
        return;
    }
    if (!functions.empty()) {
        gen.doWriteLine("struct " + name + ";");
    } else {
        gen.doWriteLine("using " + name + " = impl_Objects::" + templateType + templateArgs + ";");
    }
    if (!templateTypeUnique.empty()) {
        gen.doWriteLine("using Unique" + name + " = impl_Objects::" + templateTypeUnique +
                        templateArgsUnique + ";");
    }
}

void ObjectInfo::writeImpl(CppGenerator &gen) const {
    assert(!functions.empty());
    if (name == "Instance") {
        gen.doCode(R"(Instance::Instance(Handle::Instance &&handle)
    : Object(std::move(handle), {}),
      instanceDispatcher(impl_Loader::LoadInstanceTable(getHandle())) {
        setDispatcher(instanceDispatcher);
}

auto Instance::adoptForignSurfaceKHR(SurfaceKHR &&surface) const -> UniqueSurfaceKHR {
    return impl_Objects::Creator::create<UniqueSurfaceKHR>(std::move(surface), *this, nullptr);
}
)");
    } else if (name == "Device") {
        gen.doCode(
            R"(Device::Device(Handle::Device &&handle, const impl_Loader::Dispatcher &instanceDispatcher)
    : Object(std::move(handle), {}), deviceDispatcher(impl_Loader::LoadDeviceTable(getHandle(), instanceDispatcher)) {
        setDispatcher(deviceDispatcher);
}
)");
    }
    if (name == "Instance" || name == "Device") {
        auto lower = name;
        lower.at(0) = static_cast<char>(std::tolower(lower.at(0)));
        gen.doCode(std::format(R"-(
void {0}::resetDispatcher() noexcept {{
    {1}Dispatcher = {{}};
}}
{0}::{0}(const {0}& other) noexcept
    : Object(other),
      {1}Dispatcher(other.{1}Dispatcher) {{
    if (getHandle() != VK_BINDINGS_NULL_HANDLE) {{
        setDispatcher({1}Dispatcher);
    }}
}}

{0}::{0}({0}&& other) noexcept
    : Object(std::move(other)),
      {1}Dispatcher(std::move(other.{1}Dispatcher)) {{
    if (getHandle() != VK_BINDINGS_NULL_HANDLE) {{
        setDispatcher({1}Dispatcher);
    }}
    other.resetDispatcher();
}}

auto {0}::operator=(const {0}& other) noexcept -> {0}& {{
    if (this != &other) {{
        Object::operator=(other);
        {1}Dispatcher = other.{1}Dispatcher;

        if (getHandle() != VK_BINDINGS_NULL_HANDLE) {{
            setDispatcher({1}Dispatcher);
        }} else {{
            resetDispatcher();
        }}
    }}
    return *this;
}}

auto {0}::operator=({0}&& other) noexcept -> {0}& {{
    if (this != &other) {{
        Object::operator=(std::move(other));
        {1}Dispatcher = std::move(other.{1}Dispatcher);

        if (getHandle() != VK_BINDINGS_NULL_HANDLE) {{
            setDispatcher({1}Dispatcher);
        }} else {{
            resetDispatcher();
        }}

        other.resetDispatcher();
    }}
    return *this;
}}
)-",
                               name, lower));
    }
    if (!functions.empty())
        writeDepends(gen, functions, &FunctionInfo::writeImpl);
}

void ObjectInfo::writeTemplateDecl(CppGenerator &gen) const {
    if (!templateArgs.empty())
        gen.doWriteLine("template<> struct " + templateType + templateArgs + ";");
    if (!templateArgsUnique.empty())
        gen.doWriteLine("template<> struct " + templateTypeUnique + templateArgsUnique + ";");
}

void ObjectInfo::writeTemplateImpl(CppGenerator &gen) const {
    if (!templateArgs.empty())
        gen.doWriteLine("template struct " + templateType + templateArgs + ";");
    if (!templateArgsUnique.empty())
        gen.doWriteLine("template struct " + templateTypeUnique + templateArgsUnique + ";");
}

void ObjectInfo::writeCleanup(CppGenerator &gen) const {
    if (templateArgsUnique.empty())
        return;
    const Function function{"cleanup", {},    {}, false,  false,
                            true,      false, {}, "void", templateTypeUnique + templateArgsUnique,
                            ""};
    gen.doWriteLine("template<>");
    gen.doLineBeginScope(function.toSignature());
    auto prep = FunctionInfo{destroyFunction}.prepareSignature().decl;

    if (name == "Device" || name == "Instance") {
        prep.args.erase(prep.args.begin());
        prep.objectName = "getObject()";
    } else if ("Vk" + prep.args.front().baseType == owner ||
               prep.args.front().baseType == "Device") {
        prep.args.erase(prep.args.begin());
        prep.objectName = "owner";
    }
    if (owner.ends_with("Pool") && name.ends_with("s")) {
        gen.doIf("pool == VK_BINDINGS_NULL_HANDLE");
        gen.doReturn();
        gen.doIfEnd();
        // gen.doWriteLine("// auto poolHandle = pool;");
        // prep.args.at(0).name = "std::move(poolHandle)";
        // prep.args.at(1).name = "handles";
        // gen.doWriteLine("// " + prep.toCall() + ";");
        gen.doWriteLine(std::format(
            "dispatcherOwner->deviceTable.free{}s(owner, pool, handles.size(), handles.data());",
            name.substr(0, name.size() - 1)));
        gen.doWriteLine("handles.clear();");
        gen.doWriteLine("pool = VK_BINDINGS_NULL_HANDLE;");
        gen.doWriteLine("owner = VK_BINDINGS_NULL_HANDLE;");
        gen.doWriteLine("dispatcherOwner = nullptr;");
    } else {
        gen.doIf("getHandle() == VK_BINDINGS_NULL_HANDLE");
        gen.doReturn();
        gen.doIfEnd();
        if (prep.args.at(0).baseType == name) {
            prep.args.at(0).name = "getObject()";
        }
        if (prep.args.back().baseType == "AllocationCallbacks") {
            prep.args.back().name = "allocationCallbacks";
        }
        if (prep.returnType == "Result") {
            gen.doIfWithInitializer("auto res = " + prep.toCall(), "res != Result::Success");
            gen.doWriteLine("std::cerr << \"VkBindings: releaseDisplayEXT: \" << "
                            "Reflections::enumToString(res) << \"\\n\";");
            gen.doIfEnd();
        } else {
            gen.doWriteLine(prep.toCall() + ";");
        }
        gen.doWriteLine("this->allocationCallbacks = nullptr;");
        gen.doWriteLine("*static_cast<object_type *>(this) = {};");

        if (templateTypeUnique.contains("Owned")) {
            gen.doWriteLine("this->owner = {};");
        }
        if (name == "Instance" || name == "Device") {
            gen.doWriteLine("resetDispatcher();");
        }
    }
    gen.endScope();
}

void ObjectInfo::writeObjectToObjectTypeDecl(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s"))
        return;
    gen.doWriteLine("template<> auto ObjectToObjectType<" + name + ">() -> ObjectType;");
}

void ObjectInfo::writeObjectToObjectTypeImpl(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s"))
        return;
    gen.doWriteLine("template<> auto ObjectToObjectType<" + name +
                    ">() -> ObjectType { return ObjectType::" + enumElementMapping.at(objectType) +
                    "; }");
}

void ObjectInfo::writeObjectToHandle(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s"))
        return;
    gen.doWriteLine("template<> struct ObjectToHandle<" + name + "> { using t = Handle::" + name +
                    "; };");
}

void ObjectInfo::writeHandleToObject(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s"))
        return;
    gen.doWriteLine("template<> struct HandleToObject<Handle::" + name + "> { using t = " + name +
                    "; };");
}

void ObjectInfo::writeIsObject(CppGenerator &gen) const {
    if (!templateType.empty() && templateType.contains("Object")) {
        gen.doWriteLine("template<> struct IsObject<" + name + "> : std::true_type{};");
    }
    if (!templateTypeUnique.empty()) {
        std::string Unique = "Unique";
        if (owner.ends_with("Pool") && name.ends_with("s")) {
            Unique = "";
        }
        if (templateTypeUnique.contains("Object")) {
            gen.doWriteLine("template<> struct IsObject<" + Unique + name +
                            "> : std::true_type{};");
        }
    }
}

void ObjectInfo::writeIsUnique(CppGenerator &gen) const {
    if (!templateType.empty() && templateType.contains("Unique")) {
        gen.doWriteLine("template<> struct IsUnique<" + name + "> :  std::true_type{};");
    }
    if (!templateTypeUnique.empty()) {
        std::string Unique = "Unique";
        if (owner.ends_with("Pool") && name.ends_with("s")) {
            Unique = "";
        }
        if (templateTypeUnique.contains("Unique")) {
            gen.doWriteLine("template<> struct IsUnique<" + Unique + name +
                            "> : std::true_type{};");
        }
    }
}
void ObjectInfo::writeIsPool(CppGenerator &gen) const {
    if (!templateTypeUnique.empty()) {
        if (owner.ends_with("Pool") && name.ends_with("s")) {
            gen.doWriteLine("template<> struct IsPool<" + name + "> : std::true_type{};");
        }
    }
}

void ObjectInfo::writeHasDispatcher(CppGenerator &gen) const {
    if (templateType == "Object") {
        gen.doWriteLine("template<> struct HasDispatcher<" + name + "> : std::true_type{};");
    }
}

void ObjectInfo::setTemplate(ObjectInfo &info) {
    if (info.owner.ends_with("Pool") && info.name.ends_with("s")) {
        const std::string handleName = info.name.substr(0, info.name.size() - 1);
        info.templateTypeUnique = "PoolAllocated";
        info.templateArgsUnique =
            "<" + handleName + ", Handle::Device, Handle::" + info.owner.substr(2) + ">";
        return;
    }
    if (!info.functions.empty()) {
        if (info.destroyFunction.name.empty()) {
            info.templateType = "Object";
            info.templateArgs = "<Handle::" + info.name + ">";
            return;
        }

        if (info.destroyFunction.args.size() == 3) {
            assert(!info.owner.empty());
            info.templateType = "Object";
            info.templateArgs = "<Handle::" + info.name + ">";
            info.templateTypeUnique = "OwnedUnique";
            info.templateArgsUnique = "<" + info.owner.substr(2) + ", " + info.name + ">";
            return;
        }
        assert(info.destroyFunction.args.size() == 2);
        info.templateType = "Object";
        info.templateArgs = "<Handle::" + info.name + ">";
        info.templateTypeUnique = "Unique";
        info.templateArgsUnique = "<" + info.name + ">";
        return;
    }
    if (info.destroyFunction.name.empty()) {
        info.templateType = "ObjectWithoutFunctions";
        info.templateArgs = "<Handle::" + info.name + ">";
        return;
    }
    if (info.destroyFunction.args.size() == 3 ||
        info.destroyFunction.name.starts_with("vkRelease")) {
        assert(!info.owner.empty());
        info.templateType = "ObjectWithoutFunctions";
        info.templateArgs = "<Handle::" + info.name + ">";

        info.templateTypeUnique = "OwnedUnique";
        info.templateArgsUnique = "<" + info.owner.substr(2) + ", " + info.name + ">";
        return;
    }
    assert(false);
}

auto ObjectInfo::parseObjectInfos(Registry registry) -> const std::set<ObjectInfo> & {
    static std::set<ObjectInfo> objectInfos;
    if (!objectInfos.empty())
        return objectInfos;

    const auto &functions = FunctionInfo::parseGroupedFunctions(registry);
    const auto &destroyFunctions = FunctionInfo::parseDestroyFunctions(registry);
    FunctionInfo::destroyFunctions = destroyFunctions;

    auto handleOwner = parseHandles(registry);

    for (auto &[handle, owner] : handleOwner) {
        if (auto iter = destroyFunctions.find(handle);
            iter != destroyFunctions.end() && handle != "VkInstance" && handle != "VkDevice" &&
            iter->second.getFunction().args.front().baseType != owner) {
            const auto &function = iter->second.getFunction();
            std::cout
                << "Info: " << handle << " is owned by " << owner
                << " according to the parent property of the vk.xml type but is destroyed by: "
                << function.args.front().baseType << " using that instead\n";
            owner = function.args.front().baseType;
        }
    }

    auto buildRankFromParent = [](const std::unordered_map<std::string, std::string> &parents)
        -> std::unordered_map<std::string, int> {
        std::unordered_set<std::string> allObjects;
        allObjects.reserve(parents.size() * 2);
        for (auto const &[child, parent] : parents) {
            allObjects.insert(child);
            if (!parent.empty())
                allObjects.insert(parent);
        }

        std::unordered_map<std::string, std::vector<std::string>> children;
        children.reserve(allObjects.size() * 2);
        for (auto const &object : allObjects)
            children.emplace(object, std::vector<std::string>{});
        for (auto const &[child, parent] : parents) {
            if (!parent.empty())
                children[parent].push_back(child);
        }

        std::vector<std::string> roots;
        roots.emplace_back("VkInstance");

        std::unordered_map<std::string, int> levels;
        levels.reserve(allObjects.size());

        std::queue<std::pair<std::string, int>> queue;
        std::unordered_set<std::string> visited;
        visited.reserve(allObjects.size());

        for (auto const &root : roots) {
            queue.emplace(root, 0);
            visited.insert(root);
        }

        while (!queue.empty()) {
            auto [node, level] = queue.front();
            queue.pop();
            levels[node] = level;
            for (auto const &child : children[node]) {
                if (!visited.insert(child).second)
                    continue;
                queue.emplace(child, level + 1);
            }
        }

        return levels;
    };

    auto rank = buildRankFromParent(handleOwner);

    std::unordered_map<std::string, std::string> handlesToInstert;
    std::unordered_map<std::string, int> rankToInstert;
    for (const auto &[handle, owner] : handleOwner) {
        if (owner.ends_with("Pool")) {
            auto name = handle.substr(2) + "s";
            handlesToInstert[name] = owner;
            rankToInstert[name] = rank.at(handle) + 1;
        }
    }
    handleOwner.insert_range(std::move(handlesToInstert));
    rank.insert_range(rankToInstert);

    FunctionInfo::handleOwner = handleOwner;

    const std::unordered_map<std::string, Depends> &typeDepends =
        parseObjectDepents(registry, "type");

    const std::unordered_set<std::string> objectsDisabled = parseObjectsDisabled(registry, "type");

    const auto &objectTypes = parseObjectType(registry);
    const auto &dispatchableHandles = parseDispatchableHandles(registry);
    const auto &functionLevels = FunctionLevels::parseFunctionLevels(registry);
    const auto deviceFunctions = functionLevels.device | std::views::values | std::views::join |
                                 std::ranges::to<std::set<FunctionInfo>>();

    for (const auto &[handle, owner] : handleOwner) {
        if (objectsDisabled.contains(handle))
            continue;
        ObjectInfo objectInfo;
        if (handle.starts_with("Vk")) {
            objectInfo.name = handle.substr(2);
        } else {
            // Command Buffers
            objectInfo.name = handle;
        }
        if (dispatchableHandles.contains(handle)) {
            objectInfo.isDispatchable = true;
        }
        if (!owner.ends_with("Pool") || !handle.ends_with("s")) {
            objectInfo.objectType = objectTypes.at(handle);
        }
        if (typeDepends.contains(handle)) {
            objectInfo.depends = typeDepends.at(handle);
        }
        if (functions.contains(handle)) {
            objectInfo.functions = functions.at(handle);
        }
        if (handle == "VkInstance") {
            objectInfo.functions.insert_range(functions.at(""));
        }
        if (destroyFunctions.contains(handle)) {
            objectInfo.destroyFunction = destroyFunctions.at(handle).getFunction();
        }
        if (rank.contains(handle)) {
            objectInfo.rank = rank.at(handle);
        }
        objectInfo.owner = owner;
        if (handle == "VkInstance") {
            objectInfo.owner = "VkInstance";
            objectInfo.isInstanceFunctionTableOwner = true;
        }
        if (handle == "VkDevice") {
            objectInfo.isDeviceFunctionTableOwner = true;
        }
        for (const auto &function : objectInfo.functions) {
            if (functionLevels.instance.contains(function))
                objectInfo.hasInstanceFunctions = true;
            if (deviceFunctions.contains(function))
                objectInfo.hasDeviceFunctions = true;
        }
        setTemplate(objectInfo);
        objectInfos.insert(objectInfo);
    }
    return objectInfos;
}

auto ObjectInfo::parseObjectInfoStructTemplates(Registry registry)
    -> const std::set<StructTemplateInstanceInfo> & {
    static std::set<StructTemplateInstanceInfo> sturctTemplateInstanceInfos;
    if (!sturctTemplateInstanceInfos.empty())
        return sturctTemplateInstanceInfos;
    constinit static const std::string_view arrayProxy = "impl_Struct::ArrayProxy<";
    sturctTemplateInstanceInfos.emplace(Depends{}, std::string(arrayProxy) + "uint64_t>");

    const auto &objectInfos = parseObjectInfos(registry);
    const auto &intTypedefs = BaseTypeInfo::getIntTypedefs(registry);

    for (const auto &objectInfo : objectInfos) {
        for (const auto &functionInfo : objectInfo.functions) {
            const FunctionInfo::SignaturePrep prep = functionInfo.prepareSignature();
            for (const auto &arg : prep.decl.args) {
                constinit static const std::string_view prefix = "impl_Struct::";
                constinit static const std::string_view arrayProxy = "impl_Struct::ArrayProxy<";
                constinit static const std::string_view postfix = ">";
                if (arg.baseType.starts_with(arrayProxy) &&
                    intTypedefs.contains(arg.baseType.substr(
                        arrayProxy.size(),
                        arg.baseType.size() - arrayProxy.size() - postfix.size())))
                    continue;
                if (arg.baseType.starts_with(prefix)) {
                    sturctTemplateInstanceInfos.emplace(functionInfo.getDepends(), arg.baseType);
                }
            }
        }
    }

    return sturctTemplateInstanceInfos;
}
