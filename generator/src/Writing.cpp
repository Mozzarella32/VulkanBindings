#include "Writing.hpp"
#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "ObjectInfo.hpp"
#include "ParseXml.hpp"
#include "StructInfo.hpp"

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

void writeObjects(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                  const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(registry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doIncludeLocal("ObjectTemplates.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
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

    FunctionInfo::allEnums = parseAllEnums(registry);
    FunctionInfo::allEnumFlags = parseAllEnumFlags(registry);
    FunctionInfo::allStructs = parseAllStructs(registry);
    FunctionInfo::allUnions = parseAllUnions(registry);
    FunctionInfo::enumZeroElements = parseEnumZeroElement(registry);
    FunctionInfo::enumSizeTypes = getEnumSizeTypes(registry);
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

void writeObjectReflections(tinyxml2::XMLElement &registry,
                            [[maybe_unused]] const std::filesystem::path &genSrc,
                            [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(registry);

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
    ObjectInfo::enumElementMapping = getEnumElementMapping(registry);
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

void writeConstants(tinyxml2::XMLElement &registry,
                    [[maybe_unused]] const std::filesystem::path &genSrc,
                    const std::filesystem::path &genInclude) {

    std::set<ConstantInfo> constantInfos = parseConstantInfos(registry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("cstdint");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Constants");

    writeDepends(gen, constantInfos, &ConstantInfo::writeHeader);

    gen.doEndNamespace();
    gen.doEndNamespace();

    gen.write(genInclude / "Constants.hpp");
}

void writeEnums(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                const std::filesystem::path &genInclude) {

    std::set<EnumInfo> enumInfos = parseEnumInfos(registry);
    std::set<EnumInfo> enumInfosDepends = parseEnumInfosDepends(registry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("cstdint");
    gen.doEmptyLine();
    gen.doIncludeLocal("EnumFlagsTemplate.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, enumInfos, &EnumInfo::writeHeader);

    gen.doEndNamespace();

    gen.write(genInclude / "Enums.hpp");

    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doEmptyLine();

    writeDepends(gen, enumInfosDepends | std::views::filter([](const EnumInfo &info) {
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

    writeDepends(gen, enumInfos | std::views::filter([](const EnumInfo &info) {
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

    writeDepends(gen, enumInfos | std::views::filter([](const EnumInfo &info) {
                          return info.type == EnumInfo::Type::Bitmask;
                      }) | std::ranges::to<std::set<EnumInfo>>(),
                 &EnumInfo::writeToString);

    gen.doEndNamespace();
    gen.doEndNamespace();
    gen.write(genSrc / "BitmaskToString.cpp");
}

void writeStructs(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                  const std::filesystem::path &genInclude) {

    const auto &[structInfos, templateInstances] =
        parseStructInfosAndTemplateInstantiations(registry);

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/ObjectReflections.hpp");
    gen.doIncludeLocal("VkBindings/Objects_Forward.hpp");
    gen.doIncludeLocal("VkBindings/Constants.hpp");
    gen.doIncludeLocal("StructTemplates.hpp");
    gen.doEmptyLine();
    gen.doIncludeGlobal("array");
    gen.doIncludeGlobal("cstdint");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    gen.doWriteLine("typedef uint32_t SampleMask;");
    gen.doWriteLine("typedef uint32_t Bool32;");
    gen.doWriteLine("typedef uint32_t Flags;");
    gen.doWriteLine("typedef uint64_t Flags64;");
    gen.doWriteLine("typedef uint64_t DeviceSize;");
    gen.doWriteLine("typedef uint64_t DeviceAddress;");

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

void writeFiles(
    const std::filesystem::path &genSrc, std::filesystem::path &genInclude,
    tinyxml2::XMLElement &registry,
    const std::vector<
        std::tuple<std::vector<std::string>,
                   std::function<void(tinyxml2::XMLElement &, const std::filesystem::path &,
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
        function(registry, genSrc, genInclude);
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(
                         std::chrono::high_resolution_clock::now() - start)
                  << "\n";
    }
}
