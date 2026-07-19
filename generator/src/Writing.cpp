#include "Writing.hpp"
#include "BaseTypeInfo.hpp"
#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "FunctionInfo.hpp"
#include "ObjectInfo.hpp"
#include "ParseXml.hpp"
#include "StructInfo.hpp"
#include "tinyxml2.h"

#include <chrono>
#include <filesystem>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <utility>

using namespace tinyxml2;

template <typename T, typename MemFn>
    requires requires(const T &t, CppGenerator &gen, MemFn m) {
        { t.depends } -> std::same_as<const Depends &>;
        { std::invoke(m, t, gen) };
    }
void writeDepends(CppGenerator &gen, const T &t, MemFn print, bool reversed = false) {
    writeDepends(gen, std::set<T>{t}, print, reversed);
}

auto include(const std::filesystem::path &genDir) -> std::filesystem::path {
    return genDir / "include" / "VkBindings";
}

auto src(const std::filesystem::path &genDir) -> std::filesystem::path { return genDir / "src"; }

auto privatInclude(const std::filesystem::path &genDir) -> std::filesystem::path {
    return include(genDir) / "private";
}

void writeHandles(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                  const std::filesystem::path &genDir) {
    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);
    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Defines.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Handle");
    writeDepends(gen, objectInfos, &ObjectInfo::writeHandle, true);
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(include(genDir) / "Handles.hpp");
}

void writeObjects(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                  const std::filesystem::path &genDir) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);
    // const auto &[structInfos, templateInstances] =
    // parseStructInfosAndTemplateInstantiations(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/private/ObjectTemplates.hpp", "VkBindings/Handles.hpp"});
    gen.doIncludesGlobal({"vulkan/vk_platform.h"});
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, objectInfos, &ObjectInfo::writeForwardDecl, true);
    gen.doEndNamespace();

    gen.write(include(genDir) / "ObjectsForward.hpp");

    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Structs.hpp"});
    gen.doIncludesGlobal({"cassert", "cstdint", "expected"});
    gen.doBeginNamespace("VkBindings");

    std::set<ObjectInfo> objectsWithFuns =
        objectInfos |
        std::views::filter([](const ObjectInfo &info) -> bool { return !info.functions.empty(); }) |
        std::ranges::to<std::set<ObjectInfo>>();

    writeDepends(gen, objectsWithFuns, &ObjectInfo::writeHeader);

    gen.doEndNamespace();
    gen.write(include(genDir) / "Objects.hpp");

    gen.doIncludesLocal(
        {"VkBindings/ObjectsForward.hpp", "VkBindings/private/ObjectTemplates.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Objects");

    writeDepends(gen, objectInfos, &ObjectInfo::writeTemplateImpl);

    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(src(genDir) / "ObjectTemplates.cpp");

    auto implPre = [&] -> void {
        gen.doIncludesLocal({"VkBindings/Objects.hpp", "VkBindings/private/Loader.hpp"});
        gen.doBeginNamespace("VkBindings");
    };

    auto implPost = [&](const std::filesystem::path &path) -> void {
        gen.doEndNamespace();
        gen.write(path);
    };

    const std::unordered_set<std::string> ownFile = {"Instance", "PhysicalDevice", "Device",
                                                     "CommandBuffer"};

    for (const auto &objectInfo : objectInfos) {
        if (!ownFile.contains(objectInfo.name))
            continue;
        std::filesystem::path path = src(genDir) / (objectInfo.name + ".cpp");
        implPre();
        writeDepends(gen, objectInfo, &ObjectInfo::writeImpl);
        implPost(path);
    }

    std::erase_if(objectsWithFuns,
                  [&](const ObjectInfo &info) -> bool { return ownFile.contains(info.name); });

    implPre();
    writeDepends(gen, objectsWithFuns, &ObjectInfo::writeImpl);
    implPost(src(genDir) / "Objects.cpp");
}

void writeObjectReflections(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                            [[maybe_unused]] const std::filesystem::path &genDir) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/ObjectsForward.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doWriteLine("enum class ObjectType;");
    gen.doBeginNamespace("Reflections");
    gen.doCode(R"--(
template <typename T>
constexpr auto HandleObjectType() -> ObjectType;
template <typename T> struct HandleType;
template <typename T> using HandleType_t = HandleType<T>::t;
               )--");
    ObjectInfo::enumElementMapping = getEnumElementMapping(vkRegistry);
    writeDepends(gen, objectInfos, &ObjectInfo::writeHandeType);
    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(include(genDir) / "ObjectReflections.hpp");

    gen.doIncludesLocal({"VkBindings/ObjectReflections.hpp", "VkBindings/Enums.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Reflections");

    writeDepends(gen, objectInfos, &ObjectInfo::writeObjectTypes);

    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(src(genDir) / "ObjectReflections.cpp");
}

void writeConstants(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                    [[maybe_unused]] const std::filesystem::path &genDir) {

    std::set<ConstantInfo> constantInfos = parseConstantInfos(vkRegistry, videoRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Defines.hpp"});
    gen.doIncludesGlobal({"cstdint"});

    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Constants");

    writeDepends(gen, constantInfos, &ConstantInfo::writeHeader);

    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(include(genDir) / "Constants.hpp");
}

void writeEnums(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                const std::filesystem::path &genDir) {

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesGlobal({"vulkan/vk_platform.h"});
    gen.doIncludesLocal({"VkBindings/private/EnumFlagsTemplate.hpp"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, parseEnumInfos(vkRegistry), &EnumInfo::writeHeader);
    writeDepends(gen, parseEnumInfos(videoRegistry), &EnumInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(include(genDir) / "Enums.hpp");

    gen.doIncludesGlobal({"vulkan/vulkan.h"});
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});

    writeDepends(
        gen,
        parseEnumInfosDepends(vkRegistry) | std::views::filter([](const EnumInfo &info) -> bool {
            return !info.elements.empty();
        }) | std::ranges::to<std::set<EnumInfo>>(),
        &EnumInfo::writeAssert);
    writeDepends(
        gen,
        parseEnumInfosDepends(videoRegistry) | std::views::filter([](const EnumInfo &info) -> bool {
            return !info.elements.empty();
        }) | std::ranges::to<std::set<EnumInfo>>(),
        &EnumInfo::writeAssert);

    gen.write(src(genDir) / "EnumsCorrectAsserts.cpp");

    gen.doIncludesLocal({"VkBindings/Enums.hpp", "VkBindings/EnumToString.hpp"});
    gen.doIncludesGlobal({"vector", "ranges"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Reflections");

    writeDepends(gen,
                 parseEnumInfos(vkRegistry) | std::views::filter([](const EnumInfo &info) -> bool {
                     return info.type == EnumInfo::Type::Enum;
                 }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeToString);
    writeDepends(
        gen, parseEnumInfos(videoRegistry) | std::views::filter([](const EnumInfo &info) -> bool {
                 return info.type == EnumInfo::Type::Enum;
             }) | std::ranges::to<std::set<EnumInfo>>(),
        &EnumInfo::writeToString);

    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(src(genDir) / "EnumToString.cpp");
    gen.doIncludesLocal({"VkBindings/Enums.hpp", "VkBindings/EnumToString.hpp"});
    gen.doIncludesGlobal({"vector", "ranges"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Reflections");

    writeDepends(gen,
                 parseEnumInfos(vkRegistry) | std::views::filter([](const EnumInfo &info) -> bool {
                     return info.type == EnumInfo::Type::Bitmask;
                 }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeToString);
    writeDepends(
        gen, parseEnumInfos(videoRegistry) | std::views::filter([](const EnumInfo &info) -> bool {
                 return info.type == EnumInfo::Type::Bitmask;
             }) | std::ranges::to<std::set<EnumInfo>>(),
        &EnumInfo::writeToString);

    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(src(genDir) / "BitmaskToString.cpp");
}

void writeStructs(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                  const std::filesystem::path &genDir) {

    const auto &[structInfos, vkTemplateInstances] =
        parseStructInfosAndTemplateInstantiations(vkRegistry);
    const auto &[structInfosVideo, templateInstancesVideo] =
        parseStructInfosAndTemplateInstantiations(videoRegistry);

    std::set<StructTemplateInstanceInfo> templateInstances = vkTemplateInstances;
    templateInstances.insert(templateInstancesVideo.begin(), templateInstancesVideo.end());

    const auto &pfnStructs = getFunctionPtrsStructs(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, structInfosVideo, &StructInfo::writeForward);
    writeDepends(gen, structInfos, &StructInfo::writeForward);
    gen.doEndNamespace();
    gen.write(include(genDir) / "StructsForward.hpp");

    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/FunctionPtrs.hpp", "VkBindings/ObjectReflections.hpp",
                         "VkBindings/ObjectsForward.hpp", "VkBindings/Constants.hpp",
                         "VkBindings/private/StructTemplatesInterface.hpp"});
    gen.doIncludesGlobal({"array"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfosVideo, &StructInfo::writeHeader);
    writeDepends(gen, structInfos, &StructInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(include(genDir) / "Structs.hpp");

    gen.doIncludesLocal({
        "VkBindings/Structs.hpp",
        "VkBindings/Objects.hpp",
    });
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfos | std::views::filter([](const StructInfo &info) -> bool {
                          return !info.functions.empty();
                      }) | std::ranges::to<std::set<StructInfo>>(),
                 &StructInfo::writeImpl);

    gen.doEndNamespace();
    gen.write(src(genDir) / "Structs.cpp");

    gen.doIncludesLocal({"VkBindings/Structs.hpp", "VkBindings/Objects.hpp",
                         "VkBindings/private/StructTemplates.hpp"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, templateInstances, &StructTemplateInstanceInfo::writeImpl);

    gen.doEndNamespace();
    gen.write(src(genDir) / "StructTemplates.cpp");

    gen.doIncludesGlobal({"vulkan/vulkan.h"});
    gen.doIncludesLocal({"VkBindings/Structs.hpp"});

    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, templateInstances, &StructTemplateInstanceInfo::writeAssert);
    writeDepends(gen, structInfos | std::views::filter([](const StructInfo &info) -> bool {
                          return !info.members.empty();
                      }) | std::ranges::to<std::set<StructInfo>>(),
                 &StructInfo::writeAssert);

    gen.doEndNamespace();

    gen.write(src(genDir) / "StructsCorrectAsserts.cpp");
}

void writeDefines(XMLElement &vkRegistry, XMLElement &videoRegistry,
                  [[maybe_unused]] const std::filesystem::path &genDir) {
    CppGenerator gen;
    gen.startHeader();
    gen.doCode(parseDefines(vkRegistry));
    gen.doCode(parseDefines(videoRegistry));
    gen.write(include(genDir) / "Defines.hpp");
}

void writeFunctionPtrs(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                       [[maybe_unused]] const std::filesystem::path &genDir) {

    const auto &[structInfos, _] = parseStructInfosAndTemplateInstantiations(vkRegistry);
    const auto &pfnStructs = getFunctionPtrsStructs(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesLocal(
        {"VkBindings/BaseTypes.hpp", "VkBindings/Enums.hpp", "VkBindings/Handles.hpp"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfos | std::views::filter([&](const StructInfo &info) -> bool {
                          return pfnStructs.contains(info.originalName);
                      }) | std::ranges::to<std::set<StructInfo>>(),
                 &StructInfo::writeForward);

    gen.doBeginNamespace("PFN");
    writeDepends(gen, parseFunctionPtrs(vkRegistry), &FunctionInfo::writeFunctionPointerDecl);
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(include(genDir) / "FunctionPtrs.hpp");
}

void writeBaseTypes(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                    [[maybe_unused]] const std::filesystem::path &genDir) {
    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesGlobal({"vulkan/vk_platform.h"});
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, parseBaseTypeInfo(vkRegistry), &BaseTypeInfo::write);
    gen.doEndNamespace();
    gen.write(include(genDir) / "BaseTypes.hpp");
}

void writeFunctionTables([[maybe_unused]] XMLElement &vkRegistry,
                         [[maybe_unused]] XMLElement &videoRegistry,
                         [[maybe_unused]] const std::filesystem::path &genDir) {
    const auto &functionLevels = parseFunctionLevels(vkRegistry);
    CppGenerator gen;
    gen.startHeader();
    gen.doIncludesGlobal({"vulkan/vk_platform.h"});
    gen.doIncludesLocal({"VkBindings/Handles.hpp", "VkBindings/StructsForward.hpp",
                         "VkBindings/BaseTypes.hpp", "VkBindings/Enums.hpp",
                         "VkBindings/FunctionPtrs.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("PFN");
    gen.doWriteLine("// exported");
    writeDepends(gen, functionLevels.exported, &FunctionInfo::writeFunctionPointerDecl);
    gen.doEmptyLine();
    gen.doWriteLine("// global");
    writeDepends(gen, functionLevels.global, &FunctionInfo::writeFunctionPointerDecl);
    gen.doEmptyLine();
    gen.doWriteLine("// instance");
    writeDepends(gen, functionLevels.instance, &FunctionInfo::writeFunctionPointerDecl);
    gen.doEmptyLine();
    gen.doWriteLine("// device");
    for (const auto &[_, functions] : functionLevels.device) {
        writeDepends(gen, functions, &FunctionInfo::writeFunctionPointerDecl);
    }
    gen.doEndNamespace();
    gen.doBeginNamespace("impl_Loader");
    gen.doWriteLine("// exported");
    writeDepends(gen, functionLevels.exported, &FunctionInfo::writeFunctionPointerObject);
    gen.doEmptyLine();
    gen.doWriteLine("// Globals");
    writeDepends(gen, functionLevels.global, &FunctionInfo::writeFunctionPointerObject);
    gen.doEmptyLine();
    gen.doBeginStruct("InstanceTable");
    writeDepends(gen, functionLevels.instance, &FunctionInfo::writeFunctionPointerMember);
    gen.doEndStruct();
    gen.doEmptyLine();
    gen.doBeginStruct("DeviceTable");
    for (const auto &[handle, infos] : functionLevels.device) {
        gen.doWriteLine("// " + handle);
        writeDepends(gen, infos, &FunctionInfo::writeFunctionPointerMember);
        gen.doEmptyLine();
    }
    gen.doEndStruct();
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(privatInclude(genDir) / "FunctionTables.hpp");

    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Loader");
    gen.doLineBeginScope("void LoadGlobals()");
    writeDepends(gen, functionLevels.global, &FunctionInfo::writeLoadGlobal);
    gen.endScope();
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(src(genDir) / "LoadGlobals.cpp");

    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp", "VkBindings/private/Loader.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Loader");
    // Dispatcher LoadDeviceTable(impl_Objects::HandleDevice device, Dispatcher*
    // instanceDispatcher);

    gen.doLineBeginScope("auto LoadInstanceTable(Handle::Instance instance) -> Dispatcher");
    gen.doWriteLine("Dispatcher dispatcher = {};");
    gen.doWriteLine("InstanceTable& table = dispatcher.instanceTable;");
    writeDepends(gen, functionLevels.instance, &FunctionInfo::writeLoadInstance);
    gen.doReturn("dispatcher");
    gen.endScope();
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(src(genDir) / "LoadInstanceTable.cpp");

    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp", "VkBindings/private/Loader.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Loader");
    gen.doLineBeginScope("auto LoadDeviceTable(Handle::Device device, const "
                         "Dispatcher& instanceDispatcher) -> Dispatcher");
    gen.doWriteLine("Dispatcher dispatcher = instanceDispatcher;");
    gen.doWriteLine("DeviceTable& table = dispatcher.deviceTable;");
    writeDepends(gen,
                 functionLevels.device | std::views::values | std::views::join |
                     std::ranges::to<std::set<FunctionInfo>>(),
                 &FunctionInfo::writeLoadDevice);
    gen.doReturn("dispatcher");
    gen.endScope();
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(src(genDir) / "LoadDeviceTable.cpp");
}

void initStatics(XMLElement &vkRegistry) {
    FunctionInfo::allEnums = parseAllEnums(vkRegistry);
    FunctionInfo::allEnumFlags = parseAllEnumFlags(vkRegistry);
    FunctionInfo::allStructs = parseAllStructs(vkRegistry);
    FunctionInfo::allUnions = parseAllUnions(vkRegistry);
    FunctionInfo::enumZeroElements = parseEnumZeroElement(vkRegistry);
    FunctionInfo::enumSizeTypes = getEnumSizeTypes(vkRegistry);
    FunctionInfo::baseTypeMapping = getBaseTypeMapping(vkRegistry);
    FunctionInfo::alias = parseAlias(vkRegistry);
    FunctionInfo::handleHasFunctions =
        parseObjectInfos(vkRegistry) |
        std::ranges::views::filter(
            [](const ObjectInfo &info) -> bool { return !info.functions.empty(); }) |
        std::ranges::views::transform(
            [](const ObjectInfo &info) -> std::string { return info.name; }) |
        std::ranges::to<std::unordered_set<std::string>>();
}

void writeFiles(
    const std::filesystem::path &genDir, XMLElement &vkRegistry, XMLElement &video_registey,
    const std::vector<
        std::tuple<std::vector<std::string>,
                   std::function<void(XMLElement &, XMLElement &, const std::filesystem::path &)>>>
        &functions) {

    std::filesystem::remove_all(privatInclude(genDir));
    std::filesystem::remove_all(include(genDir));
    std::filesystem::remove_all(src(genDir));

    std::filesystem::create_directories(src(genDir));
    std::filesystem::create_directories(include(genDir));
    std::filesystem::create_directories(privatInclude(genDir));

    for (const auto &[filenames, function] : functions) {
        std::cout << "Writing : [";
        for (size_t i = 0; i < filenames.size(); i++) {
            std::cout << filenames[i];
            if (i != filenames.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "] ";
        auto start = std::chrono::high_resolution_clock::now();
        function(vkRegistry, video_registey, genDir);
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::high_resolution_clock::now() - start)
                  << "\n";
    }
}
