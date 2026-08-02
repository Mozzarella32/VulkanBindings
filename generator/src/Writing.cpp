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

auto reflectionInclude(const std::filesystem::path &genDir) -> std::filesystem::path {
    return include(genDir) / "Reflection";
}

void writeHandles(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                  const std::filesystem::path &genDir) {
    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);
    CppGenerator gen;

    // Handles.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Defines.hpp"});
    gen.doBeginNamespace("VkBindings::Handle");
    writeDepends(gen, objectInfos, &ObjectInfo::writeHandle, true);
    gen.doEndNamespace();
    gen.write(include(genDir) / "Handles.hpp");
}

void writeObjects(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                  const std::filesystem::path &genDir) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);
    auto hasFunctions =
        std::views::filter([](const ObjectInfo &info) -> bool { return !info.functions.empty(); });

    CppGenerator gen;

    // ObjectsForward.hpp
    gen.startHeader();
    gen.doIncludesLocal(
        {"VkBindings/private/ObjectTemplatesIntreface.hpp", "VkBindings/Handles.hpp"});
    gen.doIncludesGlobal({"vulkan/vk_platform.h"});
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, objectInfos, &ObjectInfo::writeForwardDecl, true);
    gen.doEndNamespace();

    // Objects.hpp
    gen.write(include(genDir) / "ObjectsForward.hpp");

    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Structs.hpp"});
    gen.doIncludesGlobal({"cassert", "cstdint", "expected"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, objectInfos | hasFunctions | std::ranges::to<std::set<ObjectInfo>>(),
                 &ObjectInfo::writeHeader);

    gen.doEndNamespace();
    gen.write(include(genDir) / "Objects.hpp");

    // ObjectTemplates.cpp
    gen.doIncludesLocal(
        {"VkBindings/ObjectsForward.hpp", "VkBindings/private/ObjectTemplates.hpp"});
    gen.doBeginNamespace("VkBindings::impl_Objects");

    writeDepends(gen, objectInfos, &ObjectInfo::writeTemplateImpl);

    gen.doEndNamespace();
    gen.write(src(genDir) / "ObjectTemplates.cpp");

    // {Instance, PhysicalDevice, Device, CommandBuffer, Objects}.cpp
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

    auto hasOwnFile = std::views::filter(
        [&](const ObjectInfo &info) -> bool { return ownFile.contains(info.name); });

    for (const auto &objectInfo : objectInfos) {
        if (!ownFile.contains(objectInfo.name))
            continue;
        std::filesystem::path path = src(genDir) / (objectInfo.name + ".cpp");
        implPre();
        writeDepends(gen, objectInfo, &ObjectInfo::writeImpl);
        implPost(path);
    }

    implPre();
    writeDepends(gen,
                 objectInfos | hasFunctions | hasOwnFile | std::ranges::to<std::set<ObjectInfo>>(),
                 &ObjectInfo::writeImpl);
    implPost(src(genDir) / "Objects.cpp");
}

void writeObjectReflections(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                            [[maybe_unused]] const std::filesystem::path &genDir) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);

    CppGenerator gen;

    // Reflection/HandleToObjectType.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/ObjectsForward.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doWriteLine("enum class ObjectType;");
    gen.doBeginNamespace("Reflections");
    gen.doCode(R"--(
template <typename T>
constexpr auto HandleToObjectType() -> ObjectType;
)--");
    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(reflectionInclude(genDir) / "HandleToObjectType.hpp");

    auto genTypeIntrospec = [&gen, &genDir](const std::string &name, const auto &collection,
                                            auto fn) -> void {
        gen.startHeader();
        gen.doIncludesLocal({"VkBindings/ObjectsForward.hpp"});
        gen.doBeginNamespace("VkBindings::Reflections");
        gen.doBeginNamespace("Reflections_impl");
        gen.doCode("template <typename T> struct " + name + ";");
        gen.doEndNamespace();
        gen.doEmptyLine();
        gen.doCode("template <typename T> using " + name + " = Reflections_impl::" + name +
                   "<T>::t;");
        gen.doEmptyLine();
        gen.doBeginNamespace("Reflections_impl");
        writeDepends(gen, collection, fn);
        gen.doEndNamespace();
        gen.doEndNamespace();

        gen.write(reflectionInclude(genDir) / (name + ".hpp"));
    };

    // Reflection/ObjectToHandle.hpp
    genTypeIntrospec("ObjectToHandle", objectInfos, &ObjectInfo::writeObjectToHandleImpl);
    // Reflection/HandleToObject.hpp
    genTypeIntrospec("HandleToObject", objectInfos, &ObjectInfo::writeHandleToObjectImpl);

    // ObjectReflections.cpp
    gen.doIncludesLocal(
        {reflectionInclude(genDir) / "HandleToObjectType.hpp", "VkBindings/Enums.hpp"});
    gen.doBeginNamespace("VkBindings::Reflections");

    ObjectInfo::enumElementMapping = getEnumElementMapping(vkRegistry);

    writeDepends(gen, objectInfos, &ObjectInfo::writeObjectTypeImpl);

    gen.doEndNamespace();

    gen.write(src(genDir) / "ObjectReflections.cpp");
}

void writeConstants(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                    [[maybe_unused]] const std::filesystem::path &genDir) {

    std::set<ConstantInfo> constantInfos = parseConstantInfos(vkRegistry, videoRegistry);

    CppGenerator gen;

    // Constants.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Defines.hpp"});
    gen.doIncludesGlobal({"cstdint"});

    gen.doBeginNamespace("VkBindings::Constants");

    writeDepends(gen, constantInfos, &ConstantInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(include(genDir) / "Constants.hpp");
}

void writeEnums(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                const std::filesystem::path &genDir) {

    auto nonEmpty =
        std::views::filter([](const EnumInfo &info) -> bool { return !info.elements.empty(); });
    auto isEnum = std::views::filter(
        [](const EnumInfo &info) -> bool { return info.type == EnumInfo::Type::Enum; });
    auto isBitmask = std::views::filter(
        [](const EnumInfo &info) -> bool { return info.type == EnumInfo::Type::Bitmask; });

    auto allEnums = parseEnumInfos(vkRegistry);
    allEnums.insert_range(parseEnumInfos(videoRegistry));

    CppGenerator gen;

    auto writeBoth =
        [&gen, vkDep = parseEnumInfosDepends(vkRegistry),
         videoDep = parseEnumInfosDepends(videoRegistry), vk = parseEnumInfos(vkRegistry),
         video = parseEnumInfos(videoRegistry)]<class Filters = decltype(std::views::all)>(
            auto fn, bool depends, Filters filters = std::views::all) -> void {
        if (depends) {
            writeDepends(gen, vkDep | filters | std::ranges::to<std::set<EnumInfo>>(), fn);
            writeDepends(gen, videoDep | filters | std::ranges::to<std::set<EnumInfo>>(), fn);

        } else {
            writeDepends(gen, vk | filters | std::ranges::to<std::set<EnumInfo>>(), fn);
            writeDepends(gen, video | filters | std::ranges::to<std::set<EnumInfo>>(), fn);
        }
    };

    // Enums.hpp
    gen.startHeader();
    gen.doIncludesGlobal({"vulkan/vk_platform.h"});
    gen.doIncludesLocal({"VkBindings/private/EnumFlagsTemplate.hpp"});
    gen.doBeginNamespace("VkBindings");

    writeBoth(&EnumInfo::writeHeader, false);

    gen.doEndNamespace();

    gen.write(include(genDir) / "Enums.hpp");

    // EnumsCorrectAsserts.cpp
    gen.doIncludesGlobal({"vulkan/vulkan.h"});
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});

    writeBoth(&EnumInfo::writeAssert, true, nonEmpty | isEnum);

    gen.write(src(genDir) / "EnumsCorrectAsserts.cpp");

    // BitmaskCorrectAsserts.cpp
    gen.doIncludesGlobal({"vulkan/vulkan.h"});
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});

    writeBoth(&EnumInfo::writeAssert, true, nonEmpty | isBitmask);

    gen.write(src(genDir) / "BitmaskCorrectAsserts.cpp");

    // EnumToString.hpp
    gen.startHeader();
    gen.doIncludesGlobal({"string"});
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});
    gen.doBeginNamespace("VkBindings::Reflections");
    gen.doCode("\ntemplate <typename T> auto enumToString(T enumVal) -> std::string;\n");

    writeBoth(&EnumInfo::writeToStringHeader, false, isEnum);

    gen.doEndNamespace();

    gen.write(include(genDir) / "EnumToString.hpp");

    // BitmaskToString.hpp
    gen.startHeader();
    gen.doIncludesGlobal({"string"});
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});
    gen.doBeginNamespace("VkBindings::Reflections");
    gen.doCode("\ntemplate <typename T> auto bitmaskToString(T enumVal) -> std::string;\n");

    writeBoth(&EnumInfo::writeToStringHeader, false, isBitmask);

    gen.doEndNamespace();

    gen.write(include(genDir) / "BitmaskToString.hpp");

    // EnumToString.cpp
    gen.doIncludesLocal({"VkBindings/Enums.hpp", "VkBindings/EnumToString.hpp"});
    gen.doBeginNamespace("VkBindings::Reflections");

    writeBoth(&EnumInfo::writeToString, false, isEnum);

    gen.doEndNamespace();

    gen.write(src(genDir) / "EnumToString.cpp");

    // BitmaskToString.cpp
    gen.doIncludesLocal({"VkBindings/Enums.hpp", "VkBindings/BitmaskToString.hpp"});
    gen.doIncludesGlobal({"vector", "ranges"});
    gen.doBeginNamespace("VkBindings::Reflections");

    writeBoth(&EnumInfo::writeToString, false, isBitmask);

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

    // Structs.hpp
    gen.startHeader();
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, structInfosVideo, &StructInfo::writeForward);
    writeDepends(gen, structInfos, &StructInfo::writeForward);
    gen.doEndNamespace();
    gen.write(include(genDir) / "StructsForward.hpp");

    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/FunctionPtrs.hpp", "VkBindings/Constants.hpp",
                         "VkBindings/private/StructTemplatesInterface.hpp"});
    gen.doIncludesGlobal({"array"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfosVideo, &StructInfo::writeHeader);
    writeDepends(gen, structInfos, &StructInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(include(genDir) / "Structs.hpp");

    // Structs.cpp
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

    // StructTemplates.cpp
    gen.doIncludesLocal({"VkBindings/Structs.hpp", "VkBindings/Objects.hpp",
                         "VkBindings/private/StructTemplates.hpp"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, templateInstances, &StructTemplateInstanceInfo::writeImpl);

    gen.doEndNamespace();
    gen.write(src(genDir) / "StructTemplates.cpp");

    // StructsCorrectAsserts.cpp
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

    // Defines.hpp
    gen.startHeader();
    gen.doCode(parseDefines(vkRegistry));
    gen.doCode(parseDefines(videoRegistry));
    gen.write(include(genDir) / "Defines.hpp");
}

void writeFunctionPtrs(XMLElement &vkRegistry, [[maybe_unused]] XMLElement &videoRegistry,
                       [[maybe_unused]] const std::filesystem::path &genDir) {

    const auto &[structInfos, _] = parseStructInfosAndTemplateInstantiations(vkRegistry);
    const auto &pfnStructs = getFunctionPtrsStructs(vkRegistry);

    auto isPfnStruct = std::views::filter(
        [&](const StructInfo &info) -> bool { return pfnStructs.contains(info.originalName); });

    CppGenerator gen;

    // FunctionPtrs.hpp
    gen.startHeader();
    gen.doIncludesLocal(
        {"VkBindings/BaseTypes.hpp", "VkBindings/Enums.hpp", "VkBindings/Handles.hpp"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfos | isPfnStruct | std::ranges::to<std::set<StructInfo>>(),
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

    // BaseTypes.hpp
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

    // FunctionTables.hpp
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

    // LoadGlobals.cpp
    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Loader");
    gen.doLineBeginScope("void LoadGlobals()");
    writeDepends(gen, functionLevels.global, &FunctionInfo::writeLoadGlobal);
    gen.endScope();
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(src(genDir) / "LoadGlobals.cpp");

    // LoadInstanceTable.cpp
    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp", "VkBindings/private/Loader.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("impl_Loader");

    gen.doLineBeginScope("auto LoadInstanceTable(Handle::Instance instance) -> Dispatcher");
    gen.doWriteLine("Dispatcher dispatcher = {};");
    gen.doWriteLine("InstanceTable& table = dispatcher.instanceTable;");
    writeDepends(gen, functionLevels.instance, &FunctionInfo::writeLoadInstance);
    gen.doReturn("dispatcher");
    gen.endScope();
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(src(genDir) / "LoadInstanceTable.cpp");

    // LoadDeviceTable.cpp
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
    std::filesystem::remove_all(reflectionInclude(genDir));
    std::filesystem::remove_all(src(genDir));

    std::filesystem::create_directories(src(genDir));
    std::filesystem::create_directories(include(genDir));
    std::filesystem::create_directories(reflectionInclude(genDir));
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
