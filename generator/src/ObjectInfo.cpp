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
        gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::NonOwned<" + info.name +
                          ", " + info.objectType + ">");
        gen.doWriteLine("using NonOwned::NonOwned;");
        epilog();
        return;
    }
    if (info.destroyFunction.args.size() == 3) {
        assert(info.owner != "");
        gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::OwnedUnique<" +
                          info.name + ", " + info.objectType + ", Handle" + info.owner + ", " +
                          info.owner + ", &" + info.destroyFunction.name + ">");
        gen.doWriteLine("using OwnedUnique::OwnedUnique;");
        epilog();
        return;
    }
    assert(info.destroyFunction.args.size() == 2);
    if (info.owner == "") {
        gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name +
                          ", " + info.objectType + ", &" + info.destroyFunction.name + ">");
        epilog();
        return;
    }
    gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name + ", " +
                      info.objectType + ", &" + info.destroyFunction.name + ", Handle" +
                      info.owner + ">");
    epilog();
}

void ObjectInfo::writeForwardDecl(CppGenerator &gen, const ObjectInfo &info) {
    if (info.owner.ends_with("Pool") && info.name.ends_with("s")) {
        const std::string handleName = "HandleVk" + info.name.substr(0, info.name.size() - 1);
        gen.doWriteLine("using HandleVk" + info.name +
                        " = impl_Objects::PoolAllocated<impl_Objects::" + handleName +
                        ", HandleVkDevice, VkDevice, Handle" + info.owner + ", &" +
                        info.destroyFunction.name + ">;");
        return;
    }
    if (!info.functions.empty()) {
        gen.doWriteLine("struct Handle" + info.name + ";");
        return;
    }
    if (info.destroyFunction.name == "") {
        gen.doWriteLine("using Handle" + info.name + " = impl_Objects::NonOwned<" + info.name +
                        ", " + info.objectType + ">;");
        return;
    }
    if (info.destroyFunction.args.size() == 3) {
        assert(info.owner != "");
        gen.doWriteLine("using Handle" + info.name + " = impl_Objects::OwnedUnique<" + info.name +
                        ", " + info.objectType + ", Handle" + info.owner + ", " + info.owner +
                        ", &" + info.destroyFunction.name + ">;");
        return;
    }
    assert(info.destroyFunction.args.size() == 2);
    if (info.owner == "") {
        gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name +
                          ", " + info.objectType + ", &" + info.destroyFunction.name + ">");
        return;
    }
    gen.doBeginStruct("Handle" + info.name + " : public impl_Objects::Unique<" + info.name + ", " +
                      info.objectType + ", &" + info.destroyFunction.name + ", Handle" +
                      info.owner + ">");
}

void ObjectInfo::writeImpl(CppGenerator &gen, const ObjectInfo &info) {
    assert(!info.functions.empty() || !info.staticFunctions.empty());
    if (!info.staticFunctions.empty())
        writeDepends(gen, info.staticFunctions,
                     std::bind_back(FunctionInfo::writeImpl, "Handle" + info.name, true));
    if (!info.functions.empty())
        writeDepends(gen, info.functions,
                     std::bind_back(FunctionInfo::writeImpl, "Handle" + info.name, false));
}
