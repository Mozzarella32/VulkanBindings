#include "ObjectInfo.hpp"
#include "Writing.hpp"

#include <functional>

bool ObjectInfo::operator<(const ObjectInfo &other) const {

    return std::tie(other.rank, depends.platform, depends.feature, depends.extensions, name) <
           std::tie(rank, other.depends.platform, other.depends.feature, other.depends.extensions,
                    other.name);
}
void ObjectInfo::writeHeader(CppGenerator &gen, const ObjectInfo &info) {
    assert(!info.functions.empty() || !info.staticFunctions.empty());
    auto epilog = [&]() {
        writeDepends(gen, info.staticFunctions, std::bind_back(FunctionInfo::writeHeader, true));
        writeDepends(gen, info.functions, std::bind_back(FunctionInfo::writeHeader, false));
        gen.doEndStruct();
    };

    if (info.destroyFunction.name == "") {
        gen.doBeginStruct(info.name + " : public impl_Objects::NonOwned<Vk" + info.name + ", " +
                          info.objectType + ">");
        gen.doWriteLine("using NonOwned::NonOwned;");
        epilog();
        return;
    }
    if (info.destroyFunction.args.size() == 3) {
        assert(info.owner != "");
        gen.doBeginStruct(info.name + " : public impl_Objects::OwnedUnique<Vk" + info.name + ", " +
                          info.objectType + ", " + info.owner.substr(2) + ", " + info.owner +
                          ", &" + info.destroyFunction.name + ">");
        gen.doWriteLine("using OwnedUnique::OwnedUnique;");
        epilog();
        return;
    }
    assert(info.destroyFunction.args.size() == 2);
    if (info.owner == "") {
        gen.doBeginStruct(info.name + " : public impl_Objects::Unique<Vk" + info.name + ", " +
                          info.objectType + ", &" + info.destroyFunction.name + ">");
        epilog();
        return;
    }
    gen.doBeginStruct(info.name + " : public impl_Objects::Unique<Vk" + info.name + ", " +
                      info.objectType + ", &" + info.destroyFunction.name + ", " +
                      info.owner.substr(2) + ">");
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
        gen.doWriteLine("using " + info.name + " = impl_Objects::NonOwned<Vk" + info.name + ", " +
                        info.objectType + ">;");
        return;
    }
    if (info.destroyFunction.args.size() == 3) {
        assert(info.owner != "");
        gen.doWriteLine("using " + info.name + " = impl_Objects::OwnedUnique<Vk" + info.name +
                        ", " + info.objectType + ", " + info.owner.substr(2) + ", " + info.owner +
                        ", &" + info.destroyFunction.name + ">;");
        return;
    }
    assert(info.destroyFunction.args.size() == 2);
    if (info.owner == "") {
        gen.doBeginStruct(info.name + " : public impl_Objects::Unique<Vk" + info.name + ", " +
                          info.objectType + ", &" + info.destroyFunction.name + ">");
        return;
    }
    gen.doBeginStruct(info.name + " : public impl_Objects::Unique<Vk" + info.name + ", " +
                      info.objectType + ", &" + info.destroyFunction.name + ", " +
                      info.owner.substr(2) + ">");
}

void ObjectInfo::writeImpl(CppGenerator &gen, const ObjectInfo &info) {
    assert(!info.functions.empty() || !info.staticFunctions.empty());
    if (!info.staticFunctions.empty())
        writeDepends(gen, info.staticFunctions,
                     std::bind_back(FunctionInfo::writeImpl, info.name, true));
    if (!info.functions.empty())
        writeDepends(gen, info.functions,
                     std::bind_back(FunctionInfo::writeImpl, info.name, false));
}
