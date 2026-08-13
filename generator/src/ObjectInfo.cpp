#include "ObjectInfo.hpp"
#include "CppGenerator.hpp"
#include "FunctionInfo.hpp"
#include "ParseXml.hpp"
#include "Writing.hpp"

#include <functional>
#include <iostream>
#include <queue>
#include <ranges>
#include <string>
#include <utility>

using namespace tinyxml2;

std::unordered_map<std::string, std::string> ObjectInfo::enumElementMapping;

auto ObjectInfo::operator<(const ObjectInfo &other) const -> bool {

    return std::tie(other.rank, depends, name) < std::tie(rank, other.depends, other.name);
}
void ObjectInfo::writeHeader(CppGenerator &gen) const {
    assert(!functions.empty());
    auto epilog = [&]() -> void {
        if (name == "Instance") {
            gen.doCode(R"(
static const constexpr bool has_handle_constructor = true;
private:
impl_Loader::Dispatcher instanceDispatcher;
friend impl_Objects::Creator;
Instance(Handle::Instance &&handle);
public:

[[nodiscard]] auto adoptForignSurfaceKHR(SurfaceKHR&& surface) const -> UniqueSurfaceKHR;

)");
        } else if (name == "Device") {
            gen.doCode(R"(
static const constexpr bool has_handle_constructor = true;
private:
impl_Loader::Dispatcher deviceDispatcher;
friend impl_Objects::Creator;
Device(Handle::Device &&handle, const impl_Loader::Dispatcher &instanceDispatcher);
public:
    )");
        }
        gen.doWriteLine(name + "() = default;");
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
        assert(owner != "");
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
    Function f{.name = "cleanup",
               .successcodes = {},
               .errorcodes = {},
               .isNoexcept = true,
               .args = {},
               .returnType = "void",
               .className = templateTypeUnique + templateArgsUnique,
               .objectName = ""};
    gen.doWriteLine("template<>");
    gen.doLineBeginScope(f.toSignature());
    FunctionInfo fi;
    fi.function = destroyFunction;
    auto prep = fi.prepareSignature().decl;

    if (name == "Device" || name == "Instance") {
        prep.args.erase(prep.args.begin());
        prep.objectName = "getObject()";
    } else if ("Vk" + prep.args.front().baseType == owner ||
               prep.args.front().baseType == "Device") {
        prep.args.erase(prep.args.begin());
        prep.objectName = "owner";
    }
    if (owner.ends_with("Pool") && name.ends_with("s")) {
        gen.doWriteLine("// auto poolHandle = pool;");
        prep.args[0].name = "std::move(poolHandle)";
        prep.args[1].name = "handles";
        gen.doWriteLine("// " + prep.toCall() + ";");
    } else {
        if (prep.args[0].baseType == name) {
            prep.args[0].name = "getObject()";
        }
        if (prep.args.back().baseType == "AllocationCallbacks") {
            prep.args.back().name = "allocationCallbacks";
        }
        if (prep.returnType == "Result") {
            gen.doIfWithInitializer("auto res = " + prep.toCall(), "res != Result::eSuccess");
            gen.doWriteLine("std::cerr << \"VkBindings: releaseDisplayEXT: \" << "
                            "Reflections::enumToString(res) << \"\\n\";");
            gen.doIfEnd();
        } else {
            gen.doWriteLine(prep.toCall() + ";");
        }
    }
    gen.endScope();
}

void ObjectInfo::writeHandleToObjectTypeDecl(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s"))
        return;
    gen.doWriteLine("template<> auto HandleToObjectType<" + name + ">() -> ObjectType;");
}

void ObjectInfo::writeObjectType(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s"))
        return;
    gen.doWriteLine("template<> auto HandleToObjectType<" + name +
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
    if (templateType != "" && templateType.contains("Object")) {
        gen.doWriteLine("template<> struct IsObject<" + name + "> : std::true_type{};");
    }
    if (templateTypeUnique != "") {
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
    if (templateType != "" && templateType.contains("Unique")) {
        gen.doWriteLine("template<> struct IsUnique<" + name + "> :  std::true_type{};");
    }
    if (templateTypeUnique != "") {
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
    if (templateTypeUnique != "") {
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

void setTemplate(ObjectInfo &info) {
    if (info.owner.ends_with("Pool") && info.name.ends_with("s")) {
        const std::string handleName = info.name.substr(0, info.name.size() - 1);
        if (info.name == "DescriptorSets") {
            info.templateTypeUnique = "PoolAllocatedWithoutFunctions";
        } else if (info.name == "CommandBuffers") {
            info.templateTypeUnique = "PoolAllocated";
        } else {
            assert(false);
        }
        info.templateArgsUnique =
            "<" + handleName + ", Device, Handle::" + info.owner.substr(2) + ">";
        return;
    }
    if (!info.functions.empty()) {
        if (info.destroyFunction.name.empty()) {
            info.templateType = "Object";
            info.templateArgs = "<Handle::" + info.name + ">";
            return;
        }

        if (info.destroyFunction.args.size() == 3) {
            assert(info.owner != "");
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
        assert(info.owner != "");
        info.templateType = "ObjectWithoutFunctions";
        info.templateArgs = "<Handle::" + info.name + ">";

        info.templateTypeUnique = "OwnedUnique";
        info.templateArgsUnique = "<" + info.owner.substr(2) + ", " + info.name + ">";
        return;
    }
    assert(false);
}

auto parseObjectInfos(XMLElement &registry) -> const std::set<ObjectInfo> & {
    static std::set<ObjectInfo> objectInfos;
    if (!objectInfos.empty())
        return objectInfos;

    const auto &functions = parseGroupedFunctions(registry);
    const auto &destroyFunctions = parseDestroyFunctions(registry);
    FunctionInfo::destroyFunctions = destroyFunctions;

    auto handleOwner = parseHandles();

    for (auto &[handle, owner] : handleOwner) {
        if (auto it = destroyFunctions.find(handle);
            it != destroyFunctions.end() && handle != "VkInstance" && handle != "VkDevice" &&
            it->second.function.args.front().baseType != owner) {
            std::cout
                << "Info: " << handle << " is owned by " << owner
                << " according to the parent property of the vk.xml type but is destroyed by: "
                << it->second.function.args.front().baseType << " using that instead\n";
            owner = it->second.function.args.front().baseType;
        }
    }

    auto buildRankFromParent = [](const std::unordered_map<std::string, std::string> &parent)
        -> std::unordered_map<std::string, int> {
        std::unordered_set<std::string> all;
        all.reserve(parent.size() * 2);
        for (auto const &p : parent) {
            all.insert(p.first);
            if (!p.second.empty())
                all.insert(p.second);
        }

        std::unordered_map<std::string, std::vector<std::string>> children;
        children.reserve(all.size() * 2);
        for (auto const &n : all)
            children.emplace(n, std::vector<std::string>{});
        for (auto const &p : parent) {
            if (!p.second.empty())
                children[p.second].push_back(p.first);
        }

        std::vector<std::string> roots;
        roots.emplace_back("VkInstance");

        std::unordered_map<std::string, int> lvl;
        lvl.reserve(all.size());

        std::queue<std::pair<std::string, int>> q;
        std::unordered_set<std::string> visited;
        visited.reserve(all.size());

        for (auto const &r : roots) {
            q.emplace(r, 0);
            visited.insert(r);
        }

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            lvl[node] = d;
            for (auto const &c : children[node]) {
                if (!visited.insert(c).second)
                    continue;
                q.emplace(c, d + 1);
            }
        }

        return lvl;
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
    const auto &dispatchableHandles = parseDispatchableHandles();
    const auto &functionLevels = parseFunctionLevels(registry);
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
            objectInfo.destroyFunction = destroyFunctions.at(handle).function;
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
        for (const auto &f : objectInfo.functions) {
            if (functionLevels.instance.contains(f))
                objectInfo.hasInstanceFunctions = true;
            if (deviceFunctions.contains(f))
                objectInfo.hasDeviceFunctions = true;
        }
        setTemplate(objectInfo);
        objectInfos.insert(objectInfo);
    }
    return objectInfos;
}
