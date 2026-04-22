#include "ObjectInfo.hpp"
#include "FunctionInfo.hpp"
#include "ParseXml.hpp"
#include "Writing.hpp"

#include <functional>
#include <iostream>
#include <queue>
#include <ranges>
#include <utility>

using namespace tinyxml2;

std::unordered_map<std::string, std::string> ObjectInfo::enumElementMapping;

bool ObjectInfo::operator<(const ObjectInfo &other) const {

    return std::tie(other.rank, depends, name) < std::tie(rank, other.depends, other.name);
}
void ObjectInfo::writeHeader(CppGenerator &gen) const {
    assert(!functions.empty());
    auto epilog = [&]() {
        if (name == "Instance") {
            gen.doCode(R"(
private:
impl_Loader::Dispatcher instanceDispatcher;
Instance(impl_Objects::HandleInstance &&h);
public:
)");
        } else if (name == "Device") {
            gen.doCode(R"(
private:
impl_Loader::Dispatcher deviceDispatcher;
friend PhysicalDevice;
Device(impl_Objects::HandleDevice &&h, impl_Loader::Dispatcher *dispatch);
public:
    )");
        }
        writeDepends(gen, functions, std::bind_back(&FunctionInfo::writeHeader));
        gen.doEndStruct();
    };

    assert(!functions.empty());
    if (destroyFunction.name.empty()) {
        gen.doBeginStruct(name + " : public " + templateType + templateArgs);
        gen.doWriteLine("using NonOwned::NonOwned;");
        epilog();
        return;
    }

    if (destroyFunction.args.size() == 3) {
        assert(owner != "");
        gen.doBeginStruct(name + " : public " + templateType + templateArgs);
        gen.doWriteLine("using OwnedUnique::OwnedUnique;");
        epilog();
        return;
    }
    assert(destroyFunction.args.size() == 2);
    gen.doBeginStruct(name + " : public " + templateType + templateArgs);
    epilog();
}
void ObjectInfo::writeHandle(CppGenerator &gen) const {
    if (isDispatchable) {
        gen.doWriteLine("VK_BINDINGS_DEFINE_HANDLE(Handle" + name + ")");
    } else {
        gen.doWriteLine("VK_BINDINGS_DEFINE_NON_DISPATCHABLE_HANDLE(Handle" + name + ")");
    }
}
void ObjectInfo::writeForwardDecl(CppGenerator &gen) const {
    if (!functions.empty()) {
        gen.doWriteLine("struct " + name + ";");
        return;
    }
    gen.doWriteLine("using " + name + " = " + templateType + templateArgs + ";");
}

void ObjectInfo::writeImpl(CppGenerator &gen) const {
    assert(!functions.empty());
    if (name == "Instance") {
        gen.doCode(R"(Instance::Instance(impl_Objects::HandleInstance &&h)
    : Unique(std::move(h), nullptr),
      instanceDispatcher(impl_Loader::LoadInstanceTable(h)) {
    dispatcher = &instanceDispatcher;
}
)");
    } else if (name == "Device") {
        gen.doCode(
            R"(Device::Device(impl_Objects::HandleDevice &&h, impl_Loader::Dispatcher *instanceDispatcher)
        : Unique(std::move(h), nullptr), deviceDispatcher(impl_Loader::LoadDeviceTable(h, *instanceDispatcher)) {
        dispatcher = &deviceDispatcher; 
    }
)");
    }
    if (!functions.empty())
        writeDepends(gen, functions, &FunctionInfo::writeImpl);
}

void ObjectInfo::writeMethodImpl(CppGenerator &gen) const {
    gen.doWriteLine("template<> struct " + templateType + templateArgs + ";");
}

void ObjectInfo::writeObjectTypes(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s"))
        return;
    gen.doWriteLine("template<> ObjectType HandleObjectType<" + name +
                    ">() { return ObjectType::" + enumElementMapping.at(objectType) + "; }");
}

void ObjectInfo::writeHandeType(CppGenerator &gen) const {
    if (owner.ends_with("Pool") && name.ends_with("s")) {
        gen.doWriteLine("template<> struct HandleType<" + name +
                        "> { using t = impl_Objects::Handle" + name.substr(0, name.size() - 1) +
                        "; };");
        return;
    }
    gen.doWriteLine("template<> struct HandleType<" + name + "> { using t = impl_Objects::Handle" +
                    name + "; };");
}

void setTemplate(ObjectInfo &info) {
    if (info.owner.ends_with("Pool") && info.name.ends_with("s")) {
        const std::string handleName = info.name.substr(0, info.name.size() - 1);
        info.templateType = "impl_Objects::PoolAllocated";
        info.templateArgs = "<" + handleName +
                            ", Device, impl_Objects::HandleDevice, impl_Objects::Handle" +
                            info.owner.substr(2) + ">";
        return;
    }
    if (!info.functions.empty()) {
        if (info.destroyFunction.name.empty()) {
            info.templateType = "impl_Objects::NonOwned";
            info.templateArgs = "<impl_Objects::Handle" + info.name + ">";
            return;
        }

        if (info.destroyFunction.args.size() == 3) {
            assert(info.owner != "");
            info.templateType = "impl_Objects::OwnedUnique";
            info.templateArgs = "<impl_Objects::Handle" + info.name + ", " + info.owner.substr(2) +
                                ", impl_Objects::Handle" + info.owner.substr(2) + ">";
            return;
        }
        assert(info.destroyFunction.args.size() == 2);
        info.templateType = "impl_Objects::Unique";
        info.templateArgs = "<impl_Objects::Handle" + info.name + ", " + info.owner.substr(2) + ">";
        return;
    }
    if (info.destroyFunction.name.empty()) {
        info.templateType = "impl_Objects::NonOwnedWithoutFunctions";
        if (info.name == "DisplayModeKHR") {
            info.templateArgs = "<impl_Objects::Handle" + info.name + ", PhysicalDevice>";
        } else {
            info.templateArgs = "<impl_Objects::Handle" + info.name + ", Device>";
        }
        return;
    }
    if (info.destroyFunction.args.size() == 3 ||
        info.destroyFunction.name.starts_with("vkRelease")) {
        assert(info.owner != "");

        info.templateType = "impl_Objects::OwnedUniqueWithoutFunctions";
        info.templateArgs = "<impl_Objects::Handle" + info.name + ", " + info.owner.substr(2) +
                            ", impl_Objects::Handle" + info.owner.substr(2) + ">";
        return;
    }
    assert(false);
}

const std::set<ObjectInfo> &parseObjectInfos(XMLElement &registry) {
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

    auto buildRankFromParent = [](const std::unordered_map<std::string, std::string> &parent) {
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
        roots.push_back("VkInstance");

        std::unordered_map<std::string, int> lvl;
        lvl.reserve(all.size());

        std::queue<std::pair<std::string, int>> q;
        std::unordered_set<std::string> visited;
        visited.reserve(all.size());

        for (auto const &r : roots) {
            q.push({r, 0});
            visited.insert(r);
        }

        while (!q.empty()) {
            auto [node, d] = q.front();
            q.pop();
            lvl[node] = d;
            for (auto const &c : children[node]) {
                if (!visited.insert(c).second)
                    continue;
                q.push({c, d + 1});
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
