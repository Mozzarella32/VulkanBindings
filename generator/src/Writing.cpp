#include "Writing.hpp"
#include "BaseTypeInfo.hpp"
#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "FunctionInfo.hpp"
#include "ObjectInfo.hpp"
#include "ParseXml.hpp"
#include "StructInfo.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

#include <chrono>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <utility>

template <typename T, typename MemFn>
    requires requires(const T &t, CppGenerator &gen, MemFn m) {
        { t.depends } -> std::same_as<const Depends &>;
        { std::invoke(m, t, gen) };
    }
void writeDepends(CppGenerator &gen, const T &t, MemFn print, bool reversed = false) {
    writeDepends(gen, std::set<T>{t}, print, reversed);
}

void writeObjects(tinyxml2::XMLElement &vkRegistry,
                  [[maybe_unused]] tinyxml2::XMLElement &videoRegistry,
                  const std::filesystem::path &genSrc, const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);
    const auto &[structInfos, templateInstances] =
        parseStructInfosAndTemplateInstantiations(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("ObjectTemplates.hpp");
    gen.doEmptyLine();
    gen.doIncludeGlobal("vulkan/vk_platform.h");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, structInfos | std::views::filter([&](const StructInfo &info) {
                          return info.name == "AllocationCallbacks";
                      }) | std::ranges::to<std::set<StructInfo>>(),
                 &StructInfo::writeForward);
    writeDepends(gen, parseEnumInfos(vkRegistry) | std::views::filter([&](const EnumInfo &info) {
                          return info.originalName == "VkResult";
                      }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeForwardDecl);

    gen.doBeginNamespace("impl_Objects");
    writeDepends(gen, objectInfos, &ObjectInfo::writeHandle, true);
    gen.doEndNamespace();
    gen.doBeginNamespace("PFN");
    auto destroyFunctions = parseDestroyFunctions();
    writeDepends(gen, destroyFunctions, &FunctionInfo::writeFunctionPointerDecl);
    writeDepends(gen, destroyFunctions, &FunctionInfo::writeFunctionPointerObject);
    gen.doEndNamespace();
    writeDepends(gen, objectInfos, &ObjectInfo::writeForwardDecl, true);
    gen.doEndNamespace();

    gen.write(genInclude / "Objects_Forward.hpp");

    gen.startHeader();
    gen.doIncludeGlobal("cassert");
    gen.doIncludeGlobal("cstdint");
    gen.doIncludeGlobal("expected");
    gen.doEmptyLine();
    gen.doIncludeLocal("VkBindings/Structs.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    std::set<ObjectInfo> objectsWithFuns =
        objectInfos |
        std::views::filter([](const ObjectInfo &info) { return !info.functions.empty(); }) |
        std::ranges::to<std::set<ObjectInfo>>();

    FunctionInfo::allEnums = parseAllEnums(vkRegistry);
    FunctionInfo::allEnumFlags = parseAllEnumFlags(vkRegistry);
    FunctionInfo::allStructs = parseAllStructs(vkRegistry);
    FunctionInfo::allUnions = parseAllUnions(vkRegistry);
    FunctionInfo::enumZeroElements = parseEnumZeroElement(vkRegistry);
    FunctionInfo::enumSizeTypes = getEnumSizeTypes(vkRegistry);
    writeDepends(gen, objectsWithFuns, &ObjectInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(genInclude / "Objects.hpp");

    auto implPre = [&] {
        gen.doIncludeLocal("VkBindings/Objects.hpp");
        gen.doEmptyLine();
        gen.doIncludeGlobal("bit");
        gen.doEmptyLine();
        gen.doBeginNamespace("VkBindings");
    };

    auto implPost = [&](const std::filesystem::path &path) {
        gen.doEndNamespace();
        gen.write(path);
    };

    const std::unordered_set<std::string> ownFile = {"Instance", "PhysicalDevice", "Device",
                                                     "CommandBuffer"};

    for (const auto &objectInfo : objectInfos) {
        if (!ownFile.contains(objectInfo.name))
            continue;
        std::filesystem::path path = genSrc / (objectInfo.name + ".cpp");
        implPre();
        writeDepends(gen, objectInfo, &ObjectInfo::writeImpl);
        implPost(path);
    }

    std::erase_if(objectsWithFuns,
                  [&](const ObjectInfo &info) { return ownFile.contains(info.name); });

    implPre();
    writeDepends(gen, objectsWithFuns, &ObjectInfo::writeImpl);
    implPost(genSrc / "Objects.cpp");
}

void writeObjectReflections(tinyxml2::XMLElement &vkRegistry,
                            [[maybe_unused]] tinyxml2::XMLElement &videoRegistry,
                            [[maybe_unused]] const std::filesystem::path &genSrc,
                            [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("VkBindings/Objects_Forward.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doEmptyLine();
    gen.doWriteLine("enum class ObjectType;");
    gen.doEmptyLine();
    gen.doBeginNamespace("Reflections");
    gen.doCode(R"--(
template <typename T>
constexpr ObjectType HandleObjectType();
template <typename T> struct HandleType;
template <typename T> using HandleType_t = HandleType<T>::t;
               )--");
    ObjectInfo::enumElementMapping = getEnumElementMapping(vkRegistry);
    writeDepends(gen, objectInfos, &ObjectInfo::writeHandeType);
    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(genInclude / "ObjectReflections.hpp");

    gen.doIncludeLocal("VkBindings/ObjectReflections.hpp");

    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Reflections");

    writeDepends(gen, objectInfos, &ObjectInfo::writeObjectTypes);

    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(genSrc / "ObjectReflections.cpp");
}

void writeConstants(tinyxml2::XMLElement &vkRegistry,
                    [[maybe_unused]] tinyxml2::XMLElement &videoRegistry,
                    [[maybe_unused]] const std::filesystem::path &genSrc,
                    const std::filesystem::path &genInclude) {

    std::set<ConstantInfo> constantInfos = parseConstantInfos(vkRegistry, videoRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("cstdint");
    gen.doEmptyLine();
    gen.doIncludeLocal("VkBindings/Defines.hpp");
    gen.doEmptyLine();

    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Constants");

    writeDepends(gen, constantInfos, &ConstantInfo::writeHeader);

    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(genInclude / "Constants.hpp");
}

void writeEnums(tinyxml2::XMLElement &vkRegistry,
                [[maybe_unused]] tinyxml2::XMLElement &videoRegistry,
                const std::filesystem::path &genSrc, const std::filesystem::path &genInclude) {

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("vulkan/vk_platform.h");
    gen.doEmptyLine();
    gen.doIncludeLocal("EnumFlagsTemplate.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, parseEnumInfos(vkRegistry), &EnumInfo::writeHeader);
    writeDepends(gen, parseEnumInfos(videoRegistry), &EnumInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(genInclude / "Enums.hpp");

    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doEmptyLine();

    writeDepends(gen,
                 parseEnumInfosDepends(vkRegistry) | std::views::filter([](const EnumInfo &info) {
                     return !info.elements.empty();
                 }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeAssert);
    writeDepends(
        gen, parseEnumInfosDepends(videoRegistry) | std::views::filter([](const EnumInfo &info) {
                 return !info.elements.empty();
             }) | std::ranges::to<std::set<EnumInfo>>(),
        &EnumInfo::writeAssert);

    gen.write(genSrc / "EnumsCorrectAsserts.cpp");

    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/EnumToString.hpp");
    gen.doEmptyLine();
    gen.doIncludeGlobal("vector");
    gen.doIncludeGlobal("ranges");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Reflections");

    writeDepends(gen, parseEnumInfos(vkRegistry) | std::views::filter([](const EnumInfo &info) {
                          return info.type == EnumInfo::Type::Enum;
                      }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeToString);
    writeDepends(gen, parseEnumInfos(videoRegistry) | std::views::filter([](const EnumInfo &info) {
                          return info.type == EnumInfo::Type::Enum;
                      }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeToString);

    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(genSrc / "EnumToString.cpp");
    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/EnumToString.hpp");
    gen.doEmptyLine();
    gen.doIncludeGlobal("vector");
    gen.doIncludeGlobal("ranges");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Reflections");

    writeDepends(gen, parseEnumInfos(vkRegistry) | std::views::filter([](const EnumInfo &info) {
                          return info.type == EnumInfo::Type::Bitmask;
                      }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeToString);
    writeDepends(gen, parseEnumInfos(videoRegistry) | std::views::filter([](const EnumInfo &info) {
                          return info.type == EnumInfo::Type::Bitmask;
                      }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeToString);

    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(genSrc / "BitmaskToString.cpp");
}

void writeStructs(tinyxml2::XMLElement &vkRegistry,
                  [[maybe_unused]] tinyxml2::XMLElement &videoRegistry,
                  const std::filesystem::path &genSrc, const std::filesystem::path &genInclude) {

    const auto &[structInfos, vkTemplateInstances] =
        parseStructInfosAndTemplateInstantiations(vkRegistry);
    const auto &[structInfosVideo, templateInstancesVideo] =
        parseStructInfosAndTemplateInstantiations(videoRegistry);

    std::set<StructTemplateInstanceInfo> templateInstances = vkTemplateInstances;
    templateInstances.insert(templateInstancesVideo.begin(), templateInstancesVideo.end());

    const auto &pfnStructs = getFunctionPtrsStructs(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("VkBindings/FunctionPtrs.hpp");
    gen.doIncludeLocal("VkBindings/ObjectReflections.hpp");
    gen.doIncludeLocal("VkBindings/Objects_Forward.hpp");
    gen.doIncludeLocal("VkBindings/Constants.hpp");
    gen.doIncludeLocal("StructTemplates.hpp");
    gen.doEmptyLine();
    gen.doEmptyLine();
    gen.doIncludeGlobal("array");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfosVideo, &StructInfo::writeHeader);
    writeDepends(gen, structInfos, &StructInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(genInclude / "Structs.hpp");

    gen.doIncludeLocal("VkBindings/Structs.hpp");
    gen.doIncludeLocal("VkBindings/Objects.hpp");
    gen.doIncludeLocal("StructTemplatesMethodImpl.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, templateInstances, &StructTemplateInstanceInfo::writeImpl);
    writeDepends(gen, structInfos | std::views::filter([](const StructInfo &info) {
                          return !info.functions.empty();
                      }) | std::ranges::to<std::set<StructInfo>>(),
                 &StructInfo::writeImpl);

    gen.doEndNamespace();
    gen.write(genSrc / "Structs.cpp");

    gen.doIncludeLocal("VkBindings/Structs.hpp");
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doEmptyLine();

    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, templateInstances, &StructTemplateInstanceInfo::writeAssert);
    writeDepends(gen, structInfos | std::views::filter([](const StructInfo &info) {
                          return !info.members.empty();
                      }) | std::ranges::to<std::set<StructInfo>>(),
                 &StructInfo::writeAssert);

    gen.doEndNamespace();

    gen.write(genSrc / "StructsCorrectAsserts.cpp");
}

void writeDefines(tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &videoRegistry,
                  [[maybe_unused]] const std::filesystem::path &genSrc,
                  const std::filesystem::path &genInclude) {
    CppGenerator gen;
    gen.startHeader();
    gen.doCode(parseDefines(vkRegistry));
    gen.doCode(parseDefines(videoRegistry));
    gen.write(genInclude / "Defines.hpp");
}

void writeFunctionPtrs(tinyxml2::XMLElement &vkRegistry,
                       [[maybe_unused]] tinyxml2::XMLElement &videoRegistry,
                       [[maybe_unused]] const std::filesystem::path &genSrc,
                       const std::filesystem::path &genInclude) {

    const auto &[structInfos, _] = parseStructInfosAndTemplateInstantiations(vkRegistry);
    const auto &pfnStructs = getFunctionPtrsStructs(vkRegistry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("VkBindings/BaseTypes.hpp");
    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/Objects_Forward.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfos | std::views::filter([&](const StructInfo &info) {
                          return pfnStructs.contains(info.name);
                      }) | std::ranges::to<std::set<StructInfo>>(),
                 &StructInfo::writeForward);

    gen.doBeginNamespace("PFN");
    writeDepends(gen, parseFunctionPtrs(vkRegistry), &FunctionInfo::writeFunctionPointerDecl);
    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(genInclude / "FunctionPtrs.hpp");
}

void writeBaseTypes(tinyxml2::XMLElement &vkRegistry,
                    [[maybe_unused]] tinyxml2::XMLElement &videoRegistry,
                    [[maybe_unused]] const std::filesystem::path &genSrc,
                    const std::filesystem::path &genInclude) {
    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("vulkan/vk_platform.h");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, parseBaseTypeInfo(vkRegistry), &BaseTypeInfo::write);
    gen.doEndNamespace();
    gen.write(genInclude / "BaseTypes.hpp");
}

void writeFiles(
    const std::filesystem::path &genSrc, std::filesystem::path &genInclude,
    tinyxml2::XMLElement &vkRegistry, tinyxml2::XMLElement &video_registey,
    const std::vector<std::tuple<std::vector<std::string>,
                                 std::function<void(tinyxml2::XMLElement &, tinyxml2::XMLElement &,
                                                    const std::filesystem::path &,
                                                    const std::filesystem::path &)>>> &functions) {
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
        function(vkRegistry, video_registey, genSrc, genInclude);
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::high_resolution_clock::now() - start)
                  << "\n";
    }
}
