#include "ObjectInfo.hpp"
#include "ParseXml.hpp"
#include "Writing.hpp"
#include "XmlUtils.hpp"

#include <functional>
#include <iostream>
#include <queue>
#include <utility>

using namespace tinyxml2;

std::unordered_map<std::string, std::string> ObjectInfo::enumElementMapping;

bool ObjectInfo::operator<(const ObjectInfo &other) const {

    return std::tie(other.rank, depends, name) < std::tie(rank, other.depends, other.name);
}
void ObjectInfo::writeHeader(CppGenerator &gen, const ObjectInfo &info) {
    assert(!info.functions.empty());
    auto epilog = [&]() {
        writeDepends(gen, info.functions, std::bind_back(FunctionInfo::writeHeader));
        gen.doEndStruct();
    };

    if (info.destroyFunction.name == "") {
        gen.doBeginStruct(info.name + " : public impl_Objects::NonOwned<Vk" + info.name + ">");
        gen.doWriteLine("using NonOwned::NonOwned;");
        epilog();
        return;
    }
    if (info.destroyFunction.args.size() == 3) {
        assert(info.owner != "");
        gen.doBeginStruct(info.name + " : public impl_Objects::OwnedUnique<Vk" + info.name + ", " +
                          info.owner.substr(2) + ", " + info.owner + ", &" +
                          info.destroyFunction.name + ">");
        gen.doWriteLine("using OwnedUnique::OwnedUnique;");
        epilog();
        return;
    }
    assert(info.destroyFunction.args.size() == 2);
    if (info.owner == "") {
        gen.doBeginStruct(info.name + " : public impl_Objects::Unique<Vk" + info.name + ", &" +
                          info.destroyFunction.name + ">");
        epilog();
        return;
    }
    gen.doBeginStruct(info.name + " : public impl_Objects::Unique<Vk" + info.name + ", &" +
                      info.destroyFunction.name + ", " + info.owner.substr(2) + ">");
    epilog();
}

void ObjectInfo::writeForwardDecl(CppGenerator &gen, const ObjectInfo &info) {
    if (info.owner.ends_with("Pool") && info.name.ends_with("s")) {
        const std::string handleName = info.name.substr(0, info.name.size() - 1);
        gen.doWriteLine("using " + info.name + " = impl_Objects::PoolAllocated<" + handleName +
                        ", Device, VkDevice, " + info.owner + ", &" + info.destroyFunction.name +
                        ">;");
        return;
    }
    if (!info.functions.empty()) {
        gen.doWriteLine("struct " + info.name + ";");
        return;
    }
    if (info.destroyFunction.name == "") {
        gen.doWriteLine("using " + info.name + " = impl_Objects::NonOwned<Vk" + info.name + ">;");
        return;
    }
    if (info.destroyFunction.args.size() == 3 ||
        info.destroyFunction.name.starts_with("vkRelease")) {
        assert(info.owner != "");
        gen.doWriteLine("using " + info.name + " = impl_Objects::OwnedUnique<Vk" + info.name +
                        ", " + info.owner.substr(2) + ", " + info.owner + ", &" +
                        info.destroyFunction.name + ">;");
        return;
    }
    assert(false);
}

void ObjectInfo::writeImpl(CppGenerator &gen, const ObjectInfo &info) {
    assert(!info.functions.empty());
    if (!info.functions.empty())
        writeDepends(gen, info.functions, FunctionInfo::writeImpl);
}

void ObjectInfo::writeObjectTypes(CppGenerator &gen, const ObjectInfo &info) {
    if (info.owner.ends_with("Pool") && info.name.ends_with("s"))
        return;
    gen.doWriteLine("template<> ObjectType HandleObjectType<" + info.name +
                    ">() { return ObjectType::" + enumElementMapping.at(info.objectType) + "; }");
}

void ObjectInfo::writeHandeType(CppGenerator &gen, const ObjectInfo &info) {
    if (info.owner.ends_with("Pool") && info.name.ends_with("s")) {
        gen.doWriteLine("template<> struct HandleType<" + info.name + "> { using t = Vk" +
                        info.name.substr(0, info.name.size() - 1) + "; };");
        return;
    }
    gen.doWriteLine("template<> struct HandleType<" + info.name + "> { using t = Vk" + info.name +
                    "; };");
}

const std::set<ObjectInfo> &parseObjectInfos(XMLElement &registry) {
    static std::set<ObjectInfo> objectInfos;
    if (!objectInfos.empty())
        return objectInfos;

    auto [destroyFunctions, functions] = parseGroupedFunctions(registry);
    FunctionInfo::destroyFunctions = destroyFunctions;

    std::unordered_map<std::string, std::string> handleOwner = parseHandles(registry);

    for (auto &[handle, owner] : handleOwner) {
        if (auto it = destroyFunctions.find(handle);
            it != destroyFunctions.end() && handle != "VkInstance" && handle != "VkDevice" &&
            it->second.args.front().baseType != owner) {
            std::cout
                << "Info: " << handle << " is owned by " << owner
                << " according to the parent property of the vk.xml type but is destroyed by: "
                << it->second.args.front().baseType << " using that instead\n";
            owner = it->second.args.front().baseType;
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

    for (const auto &[handle, owner] : handleOwner) {
        if (objectsDisabled.contains(handle))
            continue;
        ObjectInfo objectInfo;
        if (handle.starts_with("Vk")) {
            objectInfo.name = handle.substr(2);
        } else {
            objectInfo.name = handle;
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
            objectInfo.destroyFunction = destroyFunctions.at(handle);
        }
        if (rank.contains(handle)) {
            objectInfo.rank = rank.at(handle);
        }
        objectInfo.owner = owner;
        if (handle == "VkInstance") {
            objectInfo.owner = "VkInstance";
        }
        objectInfos.insert(objectInfo);
    }
    return objectInfos;
}
