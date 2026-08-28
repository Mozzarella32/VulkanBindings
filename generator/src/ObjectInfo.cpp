#include "ObjectInfo.hpp"
#include "BaseTypeInfo.hpp"
#include "CppGenerator.hpp"
#include "FunctionInfo.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"
#include "StructInfo.hpp"
#include "Writing.hpp"

#include <cassert>
#include <format>
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

    const std::string structName =
        std::format("{} : public impl_Objects::{}{}", name, templateType, templateArgs);

    gen.doBeginStruct(CppGenerator::Struct{.name = structName, .attributes = ""});
    gen.doWriteLine("using Object::Object;");
    if (name == "Instance") {
        gen.doWriteLine("[[nodiscard]] auto adoptForignSurfaceKHR(SurfaceKHR&& surface) const "
                        "-> UniqueSurfaceKHR;");
    }
    gen.doWriteLine(std::format("{}() = default;", name));
    writeDepends(gen, functions, std::bind_back(&FunctionInfo::writeHeader));
    gen.doEndStruct();
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
        gen.doCode(R"(
auto Instance::adoptForignSurfaceKHR(SurfaceKHR &&surface) const -> UniqueSurfaceKHR {
    return impl_Objects::Creator::create<UniqueSurfaceKHR>(std::move(surface), getHandle(), getDispatcher(), nullptr);
}
)");
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
    const Function cleanupFunction{
        "cleanup", {},    {}, false,  false,
        true,      false, {}, "void", templateTypeUnique + templateArgsUnique,
        ""};
    gen.doWriteLine("template<>");
    gen.doLineBeginScope(cleanupFunction.toSignature());
    auto prep = FunctionInfo{destroyFunction}.prepareSignature().decl;
    auto mapping = FunctionInfo{destroyFunction}.prepareSignature().mapping;

    if (name == "Device" || name == "Instance") {
        prep.args.erase(prep.args.begin());
        prep.objectName = "getObject()";
    } else if ("Vk" + prep.args.front().baseType == owner ||
               prep.args.front().baseType == "Device") {
        prep.args.erase(prep.args.begin());
        prep.objectName = "owner";
    }
    if (owner.ends_with("Pool") && name.ends_with("s")) {
        gen.doIf("poolHandle == VK_BINDINGS_NULL_HANDLE");
        gen.doReturn();
        gen.doIfEnd();
        gen.doWriteLine(std::format("dispatcherOwner->deviceTable.free{}s(ownerHandle, poolHandle, "
                                    "static_cast<{}>(objectHandles.size()), objectHandles.data());",
                                    name.substr(0, name.size() - 1), mapping.args.at(2).baseType));
        gen.doWriteLine("objectHandles.clear();");
        gen.doWriteLine("poolHandle = VK_BINDINGS_NULL_HANDLE;");
        gen.doWriteLine("ownerHandle = VK_BINDINGS_NULL_HANDLE;");
        gen.doWriteLine("dispatcherOwner = nullptr;");
    } else {
        gen.doIf("getHandle() == VK_BINDINGS_NULL_HANDLE");
        gen.doReturn();
        gen.doIfEnd();
        gen.doWriteLine("// owner: " + owner);
        std::string dispatch;
        if (name == "Instance") {
            dispatch = "getInstanceTable()";
        } else if (name == "Device") {
            dispatch = "getDeviceTable()";

        } else if (owner == "VkDevice") {
            dispatch = "ownerDispatcher->deviceTable";
        } else {
            dispatch = "ownerDispatcher->instanceTable";
        }
        Function function(mapping.name, {}, {}, false, false, false, false, {}, "", "className",
                          dispatch);
        if (templateTypeUnique.contains("Owned")) {
            function.addArg(function.args.size(),
                            Function::Argument(TypeAndName{.name = "ownerHandle",
                                                           .baseType = "",
                                                           .leading = "",
                                                           .postType = "",
                                                           .trailing = ""}));
        }
        function.addArg(function.args.size(), Function::Argument(TypeAndName{.name = "getHandle()",
                                                                             .baseType = "",
                                                                             .leading = "",
                                                                             .postType = "",
                                                                             .trailing = ""}));
        if (prep.returnType == "Result") {
            gen.doIfWithInitializer("auto res = " + function.toCall(), "res != Result::Success");
            gen.doWriteLine("std::cerr << \"VkBindings: " + function.name +
                            ": \" << "
                            "Reflections::enumToString(res) << \"\\n\";");
            gen.doWriteLine("assert(false && \"" + function.name + "\");");
            gen.doIfEnd();
        } else {

            function.addArg(function.args.size(),
                            Function::Argument(TypeAndName{.name = "allocationCallbacks",
                                                           .baseType = "",
                                                           .leading = "",
                                                           .postType = "",
                                                           .trailing = ""}));
            gen.doWriteLine(function.toCall() + ";");
        }
        gen.doWriteLine("this->allocationCallbacks = nullptr;");
        gen.doWriteLine("*static_cast<object_type *>(this) = {};");
        if (templateTypeUnique.contains("Owned")) {
            gen.doWriteLine("ownerHandle = VK_BINDINGS_NULL_HANDLE;");
            gen.doWriteLine("ownerDispatcher = nullptr;");
        }
        if (name == "Instance" || name == "Device") {
            gen.doWriteLine("dispatcherObj = {};");
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
            info.templateArgsUnique = "<Handle::" + info.owner.substr(2) + ", " + info.name + ">";
            return;
        }
        assert(info.destroyFunction.args.size() == 2);
        info.templateType = "Object";
        info.templateArgs = "<Handle::" + info.name + ">";
        if (info.name == "Instance" || info.name == "Device") {
            info.templateTypeUnique = "UniqueWithDispatcher";
        } else {
            info.templateTypeUnique = "Unique";
        }
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
        info.templateArgsUnique = "<Handle::" + info.owner.substr(2) + ", " + info.name + ">";
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
