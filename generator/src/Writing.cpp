#include "Writing.hpp"
#include "BaseTypeInfo.hpp"
#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "FunctionInfo.hpp"
#include "ObjectInfo.hpp"
#include "ParseXml.hpp"
#include "StructInfo.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <concepts>
#include <filesystem>
#include <format>
#include <fstream>
#include <functional>
#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <vector>

namespace {
template <typename T, typename MemFn>
    requires requires(const T &type, CppGenerator &gen, MemFn print) {
        { type.getDepends() } -> std::same_as<const Depends &>;
        { std::invoke(print, type, gen) };
    }
void writeDepends(CppGenerator &gen, const T &type, MemFn print, bool reversed = false) {
    writeDepends(gen, std::set<T>{type}, print, reversed);
}

auto include(WriteCtx &ctx) -> std::filesystem::path {
    return ctx.genDir / "include" / "VkBindings";
}

auto src(WriteCtx &ctx) -> std::filesystem::path { return ctx.genDir / "src"; }

auto validation(WriteCtx &ctx) -> std::filesystem::path { return ctx.genDir / "validation"; }

auto privatInclude(WriteCtx &ctx) -> std::filesystem::path { return include(ctx) / "private"; }

auto reflectionInclude(WriteCtx &ctx) -> std::filesystem::path {
    return include(ctx) / "Reflection";
}

auto cmake(WriteCtx &ctx) -> std::filesystem::path { return ctx.genDir / "cmake"; }

auto write(CppGenerator &gen, const std::function<std::filesystem::path(WriteCtx &)> &baseDirFun,
           const std::string &filename, WriteCtx &ctx) -> void {
    gen.write(baseDirFun(ctx) / filename);
    if (!ctx.firstWrite) {
        std::cout << ", ";
    }
    std::cout << (baseDirFun(ctx) / filename).filename();
    ctx.generatedFiles.push_back(baseDirFun(ctx) / filename);
    ctx.firstWrite = false;
}

auto genTypeIntrospec(CppGenerator &gen, WriteCtx &ctx, const std::string &name,
                      const auto &collection, auto fun, bool is_bool,
                      const std::set<std::string> &includes, bool default_bool = false) -> void {
    gen.startHeader();
    gen.doIncludesLocal(includes);
    if (is_bool)
        gen.doIncludesGlobal({"type_traits"});

    gen.doBeginNamespace("VkBindings::Reflections");
    gen.doBeginNamespace("Reflections_impl");
    if (is_bool) {
        if (default_bool) {
            gen.doCode("template <typename T> struct " + name + " : std::true_type {};");
        } else {

            gen.doCode("template <typename T> struct " + name + " : std::false_type {};");
        }
    } else {
        gen.doCode("template <typename T> struct " + name + ";");
    }
    gen.doEndNamespace();
    gen.doEmptyLine();
    if (is_bool) {
        gen.doCode("template <typename T> constexpr bool " + name + " = Reflections_impl::" + name +
                   "<T>::value;");
        gen.doEndNamespace();
        gen.doEmptyLine();
        gen.doBeginNamespace("VkBindings::Concepts");
        gen.doCode("template <typename T> concept " + name + " = Reflections::" + name + "<T>;");
        gen.doEndNamespace();
    } else {
        gen.doCode("template <typename T> using " + name + " = Reflections_impl::" + name +
                   "<T>::t;");
    }

    gen.doEmptyLine();
    if (is_bool) {
        gen.doBeginNamespace("VkBindings::Reflections::Reflections_impl");
    } else {
        gen.doBeginNamespace("Reflections_impl");
    }

    writeDepends(gen, collection, fun);
    gen.doEndNamespace();
    if (!is_bool)
        gen.doEndNamespace();

    write(gen, reflectionInclude, (name + ".hpp"), ctx);
};
} // namespace

void writeHandles(WriteCtx &ctx) {
    const std::set<ObjectInfo> objectInfos =
        ObjectInfo::parseObjectInfos(ctx.registry.setVkActive());

    auto &gen = ctx.gen.get();

    // Handles.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Defines.hpp"});
    gen.doBeginNamespace("VkBindings::Handle");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)");
    writeDepends(gen, objectInfos, &ObjectInfo::writeHandle, true);
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)");
    gen.doEndNamespace();
    write(gen, include, "Handles.hpp", ctx);
}

auto closePlatformIfOpen(CppGenerator &gen, Depends &currendDepends) -> void {
    if (!currendDepends.platform.empty()) {
        gen.doMakroEndif();
        currendDepends.platform.clear();
    }
}
auto closeDependsIfOpen(CppGenerator &gen, Depends &currendDepends) -> void {
    if (!currendDepends.guard.empty()) {
        gen.doMakroEndif();
        currendDepends.guard = "";
    }
}
auto closeNamespaceIfOpen(CppGenerator &gen, Depends &currendDepends) -> void {
    if (!currendDepends._namespace.empty()) {
        gen.doEndNamespace();
        currendDepends._namespace.clear();
    }
};

void writeObjects(WriteCtx &ctx) {

    std::set<ObjectInfo> objectInfos = ObjectInfo::parseObjectInfos(ctx.registry.setVkActive());
    auto hasFunctions = std::views::filter(&ObjectInfo::hasFunctions);

    auto &gen = ctx.gen.get();

    // ObjectsForward.hpp
    gen.startHeader();
    gen.doIncludesLocal(
        {"VkBindings/private/ObjectTemplatesIntreface.hpp", "VkBindings/Handles.hpp"});
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, objectInfos, &ObjectInfo::writeForwardDecl, true);
    gen.doEndNamespace();

    // Objects.hpp
    write(gen, include, "ObjectsForward.hpp", ctx);

    gen.startHeader();
    gen.doIncludesLocal(
        {"VkBindings/Structs.hpp", "VkBindings/ObjectsForward.hpp", "VkBindings/Enums.hpp",
         "VkBindings/Handles.hpp", "VkBindings/private/StructTemplatesInterface.hpp",
         "VkBindings/BaseTypes.hpp", "VkBindings/private/ObjectTemplatesIntreface.hpp"});
    gen.doIncludesGlobal({"cassert", "cstdint", "expected", "array", "vector", "tuple", "cstddef"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, objectInfos | hasFunctions | std::ranges::to<std::set>(),
                 &ObjectInfo::writeHeader);

    gen.doEndNamespace();
    write(gen, include, "Objects.hpp", ctx);

    // ObjectTemplates.cpp
    gen.doIncludesLocal({"VkBindings/Objects.hpp", "VkBindings/EnumToString.hpp",
                         "VkBindings/ObjectsForward.hpp",
                         "VkBindings/private/ObjectTemplatesIntreface.hpp",
                         "VkBindings/Handles.hpp", "VkBindings/Enums.hpp", "VkBindings/Defines.hpp",
                         "VkBindings/StructsForward.hpp", "VkBindings/private/Loader.hpp"});
    gen.doWriteLine("// NOLINTBEGIN(misc-include-cleaner)");
    gen.doWriteLine("// Needed for getting implmenetations");
    gen.doIncludesLocal({"VkBindings/private/ObjectTemplates.hpp"});
    gen.doWriteLine("// NOLINTEND(misc-include-cleaner)");
    gen.doIncludesGlobal({"iostream", "utility", "cstdint", "cassert"});
    gen.doBeginNamespace("VkBindings::impl_Objects");

    auto writeUniqueWithDispatcherConstructor = [&](const std::string &name) -> void {
        std::string getDispatcher;
        if (name == "Instance") {
            getDispatcher = "impl_Loader::LoadInstanceTable(getHandle())";
        } else if (name == "Device") {
            getDispatcher = "impl_Loader::LoadDeviceTable(getHandle(), getDispatcher())";
        }
        gen.doCode(std::format(R"-(
template <>
UniqueWithDispatcher<{}>::UniqueWithDispatcher(
    object_type &&obj, const AllocationCallbacks *allocationCallbacks)
    : object_type(std::move(obj)), allocationCallbacks(allocationCallbacks),
      dispatcherObj({}) {{
    setDispatcher(dispatcherObj);
}}
)-",
                               name, getDispatcher));
    };
    writeUniqueWithDispatcherConstructor("Instance");
    writeUniqueWithDispatcherConstructor("Device");

    writeDepends(gen, objectInfos, &ObjectInfo::writeCleanup);
    writeDepends(gen, objectInfos, &ObjectInfo::writeTemplateImpl);

    gen.doEndNamespace();
    write(gen, src, "ObjectTemplates.cpp", ctx);

    // {Instance, PhysicalDevice, Device, CommandBuffer, Objects}.cpp
    auto implPre = [&](const std::string &file) -> void {
        if (file == "Device") {
            gen.doIncludesLocal(
                {"VkBindings/Objects.hpp", "VkBindings/private/Creator.hpp",
                 "VkBindings/Handles.hpp", "VkBindings/private/ObjectTemplatesIntreface.hpp",
                 "VkBindings/StructsForward.hpp", "VkBindings/Enums.hpp",
                 "VkBindings/ObjectsForward.hpp", "VkBindings/Defines.hpp",
                 "VkBindings/private/StructTemplatesInterface.hpp", "VkBindings/BaseTypes.hpp"});
            gen.doIncludesGlobal(
                {"utility", "cstdint", "expected", "vector", "ranges", "cstddef", "tuple"});
        } else if (file == "PhysicalDevice") {
            gen.doIncludesLocal({"VkBindings/Objects.hpp", "VkBindings/private/Creator.hpp",
                                 "VkBindings/ObjectsForward.hpp", "VkBindings/StructsForward.hpp",
                                 "VkBindings/Defines.hpp", "VkBindings/Handles.hpp",
                                 "VkBindings/Enums.hpp", "VkBindings/BaseTypes.hpp"});
            gen.doIncludesGlobal({"cstdint", "expected", "vector", "tuple"});
        } else if (file == "CommandBuffer") {
            gen.doIncludesLocal({"VkBindings/Objects.hpp", "VkBindings/StructsForward.hpp",
                                 "VkBindings/Enums.hpp", "VkBindings/ObjectsForward.hpp",
                                 "VkBindings/private/StructTemplatesInterface.hpp",
                                 "VkBindings/Handles.hpp", "VkBindings/BaseTypes.hpp"});
            gen.doIncludesGlobal({"cstdint", "array"});
        } else if (file == "Instance") {
            gen.doIncludesLocal({"VkBindings/Objects.hpp", "VkBindings/private/Creator.hpp",
                                 "VkBindings/Handles.hpp",
                                 "VkBindings/private/ObjectTemplatesIntreface.hpp",
                                 "VkBindings/private/Loader.hpp", "VkBindings/Handles.hpp",
                                 "VkBindings/ObjectsForward.hpp", "VkBindings/StructsForward.hpp",
                                 "VkBindings/Defines.hpp", "VkBindings/Enums.hpp",
                                 "VkBindings/private/FunctionTables.hpp"});
            gen.doIncludesGlobal({"utility", "expected", "vector", "cstdint", "cstddef", "ranges"});
        } else if (file == "Queue") {
            gen.doIncludesLocal({"VkBindings/Objects.hpp", "VkBindings/StructsForward.hpp",
                                 "VkBindings/ObjectsForward.hpp", "VkBindings/Enums.hpp",
                                 "VkBindings/private/StructTemplatesInterface.hpp"});
            gen.doIncludesGlobal({"vector", "cstdint"});
        } else if (file == "Objects") {
            gen.doIncludesLocal({"VkBindings/Objects.hpp", "VkBindings/StructsForward.hpp"});
        } else {
            assert(false);
        }
        gen.doBeginNamespace("VkBindings");
        gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)");
        if (file == "Device") {
            gen.doWriteLine("// NOLINTBEGIN(bugprone-easily-swappable-parameters)");
        }
    };

    auto implPost = [&](const std::string &file,
                        const std::function<std::filesystem::path(WriteCtx &)> &baseDirFun,
                        const std::string &filename) -> void {
        if (file == "Device") {
            gen.doWriteLine("// NOLINTEND(bugprone-easily-swappable-parameters)");
        }
        gen.doWriteLine("// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)");
        gen.doEndNamespace();
        write(gen, baseDirFun, filename, ctx);
    };

    const std::unordered_set<std::string> ownFile = {"Instance", "PhysicalDevice", "Device",
                                                     "CommandBuffer", "Queue"};

    auto hasOwnFile = std::views::filter(
        [&](const ObjectInfo &info) -> bool { return ownFile.contains(info.getName()); });
    auto hasNoOwnFile = std::views::filter(
        [&](const ObjectInfo &info) -> bool { return !ownFile.contains(info.getName()); });

    for (const auto &objectInfo : objectInfos | hasOwnFile) {
        implPre(objectInfo.getName());
        writeDepends(gen, objectInfo, &ObjectInfo::writeImpl);
        implPost(objectInfo.getName(), src, (objectInfo.getName() + ".cpp"));
    }

    implPre("Objects");
    writeDepends(gen, objectInfos | hasFunctions | hasNoOwnFile | std::ranges::to<std::set>(),
                 &ObjectInfo::writeImpl);
    implPost("Objects", src, "Objects.cpp");
}

void writeObjectReflections(WriteCtx &ctx) {

    const std::set<ObjectInfo> objectInfos =
        ObjectInfo::parseObjectInfos(ctx.registry.setVkActive());

    auto &gen = ctx.gen.get();

    // Reflection/ObjectToObjectType.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/ObjectsForward.hpp"});
    gen.doBeginNamespace("VkBindings");
    gen.doWriteLine("enum class ObjectType;");
    gen.doBeginNamespace("Reflections");
    gen.doCode(R"--(
template <typename T>
constexpr auto ObjectToObjectType() -> ObjectType;
)--");
    writeDepends(gen, objectInfos, &ObjectInfo::writeObjectToObjectTypeDecl);
    gen.doEndNamespace();
    gen.doEndNamespace();

    write(gen, reflectionInclude, "ObjectToObjectType.hpp", ctx);

    // Reflection/ObjectToHandle.hpp
    genTypeIntrospec(gen, ctx, "ObjectToHandle", objectInfos, &ObjectInfo::writeObjectToHandle,
                     false, {"VkBindings/ObjectsForward.hpp", "VkBindings/Handles.hpp"});
    // Reflection/HandleToObject.hpp
    genTypeIntrospec(gen, ctx, "HandleToObject", objectInfos, &ObjectInfo::writeHandleToObject,
                     false, {"VkBindings/ObjectsForward.hpp", "VkBindings/Handles.hpp"});
    // Reflection/IsObject.hpp
    genTypeIntrospec(gen, ctx, "IsObject", objectInfos, &ObjectInfo::writeIsObject, true,
                     {"VkBindings/ObjectsForward.hpp"});
    // Reflection/IsUnique.hpp
    genTypeIntrospec(gen, ctx, "IsUnique", objectInfos, &ObjectInfo::writeIsUnique, true,
                     {"VkBindings/ObjectsForward.hpp"});
    // Reflection/IsPool.hpp
    genTypeIntrospec(gen, ctx, "IsPool", objectInfos, &ObjectInfo::writeIsPool, true,
                     {"VkBindings/ObjectsForward.hpp"});
    // Reflection/HasDispatcher.hpp
    genTypeIntrospec(gen, ctx, "HasDispatcher", objectInfos, &ObjectInfo::writeHasDispatcher, true,
                     {"VkBindings/ObjectsForward.hpp"});

    // ObjectToObjectType.cpp
    gen.doIncludesLocal({reflectionInclude(ctx) / "ObjectToObjectType.hpp", "VkBindings/Enums.hpp",
                         "VkBindings/ObjectsForward.hpp"});
    gen.doBeginNamespace("VkBindings::Reflections");

    ObjectInfo::enumElementMapping = EnumInfo::getEnumElementMapping(ctx.registry.setVkActive());

    writeDepends(gen, objectInfos, &ObjectInfo::writeObjectToObjectTypeImpl);

    gen.doEndNamespace();

    write(gen, src, "ObjectToObjectType.cpp", ctx);
}

void writeConstants(WriteCtx &ctx) {

    const std::set<ConstantInfo> &constantInfos =
        ConstantInfo::ConstantInfo::parseConstantInfos(ctx.registry);

    auto &gen = ctx.gen.get();

    // Constants.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Defines.hpp"});
    gen.doIncludesGlobal({"cstdint", "string_view"});

    gen.doBeginNamespace("VkBindings::Constants");

    writeDepends(gen, constantInfos, &ConstantInfo::writeHeader);

    gen.doEndNamespace();

    write(gen, include, "Constants.hpp", ctx);
}

void writeEnums(WriteCtx &ctx) {

    auto nonEmpty = std::views::filter(&EnumInfo::hasElements);
    auto isEnum = std::views::filter(&EnumInfo::isEnum);
    auto isBitmask = std::views::filter(&EnumInfo::isBitmask);

    auto &gen = ctx.gen.get();

    const auto &enumsVk = EnumInfo::parseEnumInfos(ctx.registry.setVkActive());
    const auto &enumsVideo = EnumInfo::parseEnumInfos(ctx.registry.setVideoActive());

    auto writeBoth =
        [&gen, &enumsVk, &enumsVideo,
         enumsVkDep = EnumInfo::parseEnumInfosDepends(ctx.registry.setVkActive()),
         enumsVideoDep = EnumInfo::parseEnumInfosDepends(
             ctx.registry.setVideoActive())]<class Filters = decltype(std::views::all)>(
            auto fun, bool depends, Filters filters = std::views::all) -> void {
        if (depends) {
            writeDepends(gen, enumsVkDep | filters | std::ranges::to<std::set>(), fun);
            writeDepends(gen, enumsVideoDep | filters | std::ranges::to<std::set>(), fun);

        } else {
            writeDepends(gen, enumsVk | filters | std::ranges::to<std::set>(), fun);
            writeDepends(gen, enumsVideo | filters | std::ranges::to<std::set>(), fun);
        }
    };

    // Enums.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/private/EnumFlagsTemplate.hpp"});
    gen.doIncludesGlobal({"cstdint"});
    gen.doBeginNamespace("VkBindings");
    gen.doWriteLine("// NOLINTBEGIN(performance-enum-size)");

    writeBoth(&EnumInfo::writeHeader, false);
    gen.doWriteLine("// NOLINTEND(performance-enum-size)");

    gen.doEndNamespace();

    write(gen, include, "Enums.hpp", ctx);

    // EnumsCorrectAsserts.cpp
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});
    {
        std::set<std::string> includes = parseCodecEnumIncludes(ctx.registry);
        includes.insert("validation/vulkan/vulkan_core.h");
        includes.insert("validation/vk_video/vulkan_video_codec_h264std_decode.h");
        gen.doIncludesLocal(includes);
    }
    gen.doIncludesGlobal({"cstdint"});
    writeBoth(&EnumInfo::writeAssert, true, nonEmpty | isEnum);

    write(gen, validation, "EnumsCorrectAsserts.cpp", ctx);

    // BitmaskCorrectAsserts.cpp
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});
    gen.doIncludesLocal({"validation/vulkan/vulkan_core.h"});
    gen.doIncludesGlobal({"cstdint"});

    writeBoth(&EnumInfo::writeAssert, true, nonEmpty | isBitmask);

    write(gen, validation, "BitmaskCorrectAsserts.cpp", ctx);

    // EnumToString.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Enums.hpp"});
    gen.doIncludesGlobal({"string"});
    gen.doBeginNamespace("VkBindings::Reflections");
    gen.doCode("\ntemplate <typename T> auto enumToString(T enumVal) -> std::string;\n");

    writeBoth(&EnumInfo::writeToStringHeader, false, isEnum);

    gen.doEndNamespace();

    write(gen, include, "EnumToString.hpp", ctx);

    // FlagsToString.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Enums.hpp", "VkBindings/Reflection/IsFlag.hpp",
                         "VkBindings/Reflection/BitsToFlag.hpp",
                         "VkBindings/Reflection/IsBits.hpp"});
    gen.doIncludesGlobal({"string"});
    gen.doBeginNamespace("VkBindings::Reflections");
    gen.doCode("\ntemplate <Concepts::IsFlag T> auto flagsToString(T flags) -> std::string;\n");
    gen.doCode(R"-(template <Concepts::IsBits T> auto flagsToString(T bits) -> std::string {
    return flagsToString(BitsToFlag<T>(bits));
}
)-");

    writeBoth(&EnumInfo::writeToStringHeader, false, isBitmask);

    gen.doEndNamespace();

    write(gen, include, "FlagsToString.hpp", ctx);

    // EnumToString.cpp
    gen.doIncludesLocal({"VkBindings/Enums.hpp", "VkBindings/EnumToString.hpp"});
    gen.doIncludesGlobal({"string"});
    gen.doBeginNamespace("VkBindings::Reflections");
    gen.doWriteLine("// NOLINTBEGIN(readability-function-size)");
    writeBoth(&EnumInfo::writeToString, false, isEnum);
    gen.doWriteLine("// NOLINTEND(readability-function-size)");
    gen.doEndNamespace();

    write(gen, src, "EnumToString.cpp", ctx);

    // FlagsToString.cpp
    gen.doIncludesLocal({"VkBindings/Enums.hpp", "VkBindings/FlagsToString.hpp"});
    gen.doIncludesGlobal({"array", "ranges", "string_view", "cstddef", "span", "string"});
    gen.doBeginNamespace("VkBindings::Reflections");
    gen.doWriteLine("// NOLINTBEGIN(readability-function-cognitive-complexity, "
                    "cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)");
    writeDepends(gen, enumsVk | isBitmask | std::ranges::to<std::set>(), &EnumInfo::writeToString);
    gen.doWriteLine("// NOLINTEND(readability-function-cognitive-complexity, "
                    "cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)");
    gen.doEndNamespace();

    write(gen, src, "FlagsToString.cpp", ctx);

    // Reflection/IsEnum.hpp
    genTypeIntrospec(gen, ctx, "IsEnum",
                     std::ranges::to<std::set<EnumInfo>>(std::ranges::join_view(std::array{
                         std::views::all(enumsVk | isEnum), std::views::all(enumsVideo | isEnum)})),
                     &EnumInfo::writeIsEnum, true, {"VkBindings/Enums.hpp"});

    // Reflection/IsBits.hpp
    genTypeIntrospec(
        gen, ctx, "IsBits",
        std::ranges::to<std::set<EnumInfo>>(std::ranges::join_view(std::array{
            std::views::all(enumsVk | isBitmask), std::views::all(enumsVideo | isBitmask)})),
        &EnumInfo::writeIsBits, true, {"VkBindings/Enums.hpp"});

    // Reflection/IsFlag.hpp
    genTypeIntrospec(
        gen, ctx, "IsFlag",
        std::ranges::to<std::set<EnumInfo>>(std::ranges::join_view(std::array{
            std::views::all(enumsVk | isBitmask), std::views::all(enumsVideo | isBitmask)})),
        &EnumInfo::writeIsFlag, true, {"VkBindings/Enums.hpp"});

    // Reflection/BitsToFlag.hpp
    genTypeIntrospec(
        gen, ctx, "BitsToFlag",
        std::ranges::to<std::set<EnumInfo>>(std::ranges::join_view(std::array{
            std::views::all(enumsVk | isBitmask), std::views::all(enumsVideo | isBitmask)})),
        &EnumInfo::writeBitsToFlag, false, {"VkBindings/Enums.hpp"});

    // Reflection/FlagToBits.hpp
    genTypeIntrospec(
        gen, ctx, "FlagToBits",
        std::ranges::to<std::set<EnumInfo>>(std::ranges::join_view(std::array{
            std::views::all(enumsVk | isBitmask), std::views::all(enumsVideo | isBitmask)})),
        &EnumInfo::writeFlagToBits, false, {"VkBindings/Enums.hpp"});
}

void writeStructs(WriteCtx &ctx) {

    const auto &[structInfos, vkTemplateInstances] =
        StructInfo::parseStructInfosAndTemplateInstantiations(ctx.registry.setVkActive());
    const auto &[structInfosVideo, templateInstancesVideo] =
        StructInfo::parseStructInfosAndTemplateInstantiations(ctx.registry.setVideoActive());
    const auto &objectInfoStructTemplates =
        ObjectInfo::parseObjectInfoStructTemplates(ctx.registry);

    std::set<StructTemplateInstanceInfo> templateInstances = vkTemplateInstances;
    templateInstances.insert(templateInstancesVideo.begin(), templateInstancesVideo.end());
    templateInstances.insert(objectInfoStructTemplates.begin(), objectInfoStructTemplates.end());

    const auto &pfnStructs = FunctionInfo::getFunctionPtrsStructs(ctx.registry.setVkActive());

    auto &gen = ctx.gen.get();

    // StructsForward.hpp
    gen.startHeader();
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, structInfosVideo, &StructInfo::writeForward);
    writeDepends(gen, structInfos, &StructInfo::writeForward);
    gen.doEndNamespace();
    write(gen, include, "StructsForward.hpp", ctx);

    // Structs.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/FunctionPtrs.hpp", "VkBindings/ObjectsForward.hpp",
                         "VkBindings/Constants.hpp", "VkBindings/Enums.hpp",
                         "VkBindings/private/StructTemplatesInterface.hpp",
                         // "VkBindings/private/StructTemplatesDecl.hpp",
                         "VkBindings/BaseTypes.hpp"});
    gen.doIncludesGlobal({"array", "cstdint", "cstddef"});
    gen.doBeginNamespace("VkBindings");
    gen.doWriteLine(
        "// NOLINTBEGIN(cppcoreguidelines-non-private-member-variables-in-classes, "
        "misc-non-private-member-variables-in-classes, "
        "cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, "
        "cppcoreguidelines-pro-type-member-init, bugprone-invalid-enum-default-initialization)");

    writeDepends(gen, structInfosVideo, &StructInfo::writeHeader);
    writeDepends(gen, structInfos, &StructInfo::writeHeader);

    gen.doWriteLine(
        "// NOLINTEND(cppcoreguidelines-non-private-member-variables-in-classes, "
        "misc-non-private-member-variables-in-classes, "
        "cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, "
        "cppcoreguidelines-pro-type-member-init, bugprone-invalid-enum-default-initialization)");
    gen.doEndNamespace();

    write(gen, include, "Structs.hpp", ctx);

    // Structs.cpp
    gen.doIncludesLocal({"VkBindings/Structs.hpp", "VkBindings/Objects.hpp",
                         "VkBindings/private/StructTemplatesInterface.hpp", "VkBindings/Enums.hpp",
                         "VkBindings/ObjectsForward.hpp", "VkBindings/BaseTypes.hpp"});
    gen.doIncludesGlobal({"cstdint"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen,
                 structInfos | std::views::filter(&StructInfo::hasFunctions) |
                     std::ranges::to<std::set>(),
                 &StructInfo::writeImpl);

    gen.doEndNamespace();
    write(gen, src, "Structs.cpp", ctx);

    // // StructTemplatesDecl.hpp
    // gen.doIncludesLocal({"VkBindings/ObjectsForward.hpp",
    //                      "VkBindings/private/StructTemplatesInterface.hpp",
    //                      "VkBindings/Enums.hpp", "VkBindings/StructsForward.hpp"});
    // gen.doIncludesGlobal({"cstdint"});
    // gen.doBeginNamespace("VkBindings::impl_Struct");
    // gen.doWriteLine(
    //     "// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)");
    // writeDepends(gen, templateInstances, &StructTemplateInstanceInfo::writeDecl);
    // gen.doWriteLine(
    //     "// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)");
    // gen.doEndNamespace();
    // write(gen, privatInclude, "StructTemplatesDecl.hpp", ctx);

    // StructTemplates.cpp
    auto writeStructTemplates = [&](std::string_view templateName) -> void {
        if (templateName == "AssignableHandle") {
            gen.doIncludesLocal({"VkBindings/ObjectsForward.hpp",
                                 "VkBindings/private/StructTemplatesInterface.hpp",
                                 "VkBindings/ObjectsForward.hpp"});
        } else if (templateName == "FixedString") {
            gen.doIncludesLocal({"VkBindings/private/StructTemplatesInterface.hpp"});
        } else if (templateName == "VecView" || templateName == "ArrayProxy") {
            gen.doIncludesLocal({"VkBindings/ObjectsForward.hpp",
                                 "VkBindings/private/StructTemplatesInterface.hpp",
                                 "VkBindings/Structs.hpp", "VkBindings/Enums.hpp"});
            gen.doIncludesGlobal({"cstdint"});
        } else {
            assert(false);
        }
        gen.doWriteLine("// NOLINTBEGIN(misc-include-cleaner)");
        gen.doWriteLine("// Needed for getting implmenetations");
        gen.doIncludesLocal({"VkBindings/private/StructTemplates.hpp"});
        gen.doWriteLine("// NOLINTEND(misc-include-cleaner)");

        gen.doBeginNamespace("VkBindings");
        if (templateName == "FixedString") {
            gen.doWriteLine(
                "// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)");
        }

        writeDepends(
            gen,
            templateInstances |
                std::views::filter([&](const StructTemplateInstanceInfo &templateInstance) -> bool {
                    return templateInstance.isInstance(templateName);
                }) |
                std::ranges::to<std::set>(),
            &StructTemplateInstanceInfo::writeImpl);

        if (templateName == "FixedString") {
            gen.doWriteLine(
                "// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)");
        }
        gen.doEndNamespace();
        write(gen, src, std::format("StructTemplates{}.cpp", templateName), ctx);
    };
    writeStructTemplates("AssignableHandle");
    writeStructTemplates("FixedString");
    writeStructTemplates("VecView");
    writeStructTemplates("ArrayProxy");

    // StructsCorrectAsserts.cpp
    gen.doIncludesLocal({"VkBindings/Structs.hpp", "VkBindings/private/LayoutChecker.hpp",
                         "VkBindings/Enums.hpp", "VkBindings/ObjectsForward.hpp",
                         "VkBindings/private/StructTemplatesInterface.hpp",
                         "VkBindings/Constants.hpp", "VkBindings/BaseTypes.hpp"});
    gen.doIncludesLocal({"validation/vulkan/vulkan_core.h"});
    gen.doIncludesGlobal({"utility", "type_traits", "cstdint", "cstddef"});

    gen.doBeginNamespace("VkBindings::impl_Struct");
    gen.doWriteLine("// NOLINTBEGIN(readability-function-size, "
                    "cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, "
                    "cppcoreguidelines-pro-type-union-access)");
    gen.doLineBeginScope("void LayoutChecker::checkStructsCorrectAsserts() ");
    writeDepends(gen, templateInstances, &StructTemplateInstanceInfo::writeAssert);
    writeDepends(gen,
                 structInfos | std::views::filter(&StructInfo::hasMembers) |
                     std::ranges::to<std::set>(),
                 &StructInfo::writeAssert);
    gen.endScope();
    gen.doWriteLine("// NOLINTEND(readability-function-size, "
                    "cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, "
                    "cppcoreguidelines-pro-type-union-access)");
    gen.doEndNamespace();
    write(gen, validation, "StructsCorrectAsserts.cpp", ctx);
}

void writeDefines(WriteCtx &ctx) {

    auto &gen = ctx.gen.get();

    // Defines.hpp
    gen.startHeader();
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-macro-usage, cppcoreguidelines-macro-to-enum "
                    ",modernize-macro-to-enum, bugprone-macro-parentheses)");
    gen.doCode(parseDefines(ctx.registry.setVkActive()));
    gen.doCode(parseDefines(ctx.registry.setVideoActive()));
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-macro-usage, cppcoreguidelines-macro-to-enum "
                    ",modernize-macro-to-enum, bugprone-macro-parentheses)");
    write(gen, include, "Defines.hpp", ctx);
}

void writeFunctionPtrs(WriteCtx &ctx) {
    const auto &[structInfos, _] =
        StructInfo::parseStructInfosAndTemplateInstantiations(ctx.registry.setVkActive());
    const auto &pfnStructs = FunctionInfo::getFunctionPtrsStructs(ctx.registry.setVkActive());

    auto isPfnStruct = std::views::filter(StructInfo::isPfnStruct(pfnStructs));

    auto &gen = ctx.gen.get();

    // FunctionPtrs.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/BaseTypes.hpp", "VkBindings/Enums.hpp",
                         "VkBindings/private/vk_platform.h", "VkBindings/Handles.hpp"});
    gen.doIncludesGlobal({"cstdint", "cstddef"});
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, structInfos | isPfnStruct | std::ranges::to<std::set>(),
                 &StructInfo::writeForward);

    gen.doBeginNamespace("PFN");
    writeDepends(gen, FunctionInfo::parseFunctionPtrs(ctx.registry.setVkActive()),
                 &FunctionInfo::writeFunctionPointerDecl);
    gen.doEndNamespace();
    gen.doEndNamespace();
    write(gen, include, "FunctionPtrs.hpp", ctx);
}

void writeBaseTypes(WriteCtx &ctx) {

    auto &gen = ctx.gen.get();

    // BaseTypes.hpp
    gen.startHeader();
    gen.doIncludesGlobal({"cstdint"});
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, BaseTypeInfo::parseBaseTypeInfo(ctx.registry.setVkActive()),
                 &BaseTypeInfo::write);
    gen.doEndNamespace();
    write(gen, include, "BaseTypes.hpp", ctx);
}

void writeFunctionTables(WriteCtx &ctx) {
    const auto &functionLevels = FunctionLevels::parseFunctionLevels(ctx.registry.setVkActive());

    auto &gen = ctx.gen.get();

    // FunctionTables.hpp
    gen.startHeader();
    gen.doIncludesLocal({"VkBindings/Handles.hpp", "VkBindings/StructsForward.hpp",
                         "VkBindings/BaseTypes.hpp", "VkBindings/Enums.hpp",
                         "VkBindings/FunctionPtrs.hpp", "VkBindings/private/vk_platform.h"});
    gen.doIncludesGlobal({"cstdint", "cstddef"});
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("PFN");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)");
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
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)");
    gen.doBeginNamespace("impl_Loader");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)");
    gen.doWriteLine("// exported");
    writeDepends(gen, functionLevels.exported, &FunctionInfo::writeFunctionPointerObjectDecl);
    gen.doEmptyLine();
    gen.doWriteLine("// Globals");
    writeDepends(gen, functionLevels.global, &FunctionInfo::writeFunctionPointerObjectDecl);
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)");
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
    write(gen, privatInclude, "FunctionTables.hpp", ctx);

    // LoaderExportedImpl.cpp
    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp"});
    gen.doBeginNamespace("VkBindings::impl_Loader");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)");
    writeDepends(gen, functionLevels.exported, &FunctionInfo::writeFunctionPointerObjectImpl);
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)");
    gen.doEndNamespace();
    write(gen, src, "LoaderExportedImpl.cpp", ctx);

    // LoadGlobals.cpp
    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp", "VkBindings/private/Loader.hpp"});
    gen.doBeginNamespace("VkBindings::impl_Loader");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)");
    writeDepends(gen, functionLevels.global, &FunctionInfo::writeFunctionPointerObjectImpl);
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)");
    gen.doLineBeginScope("void LoadGlobals()");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)");
    writeDepends(gen, functionLevels.global, &FunctionInfo::writeLoadGlobal);
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)");
    gen.endScope();
    gen.doEndNamespace();
    write(gen, src, "LoadGlobals.cpp", ctx);

    // LoadInstanceTable.cpp
    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp", "VkBindings/private/Loader.hpp",
                         "VkBindings/Handles.hpp"});
    gen.doBeginNamespace("VkBindings::impl_Loader");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)");
    gen.doLineBeginScope("auto LoadInstanceTable(Handle::Instance instance) -> Dispatcher");
    gen.doWriteLine("Dispatcher dispatcher = {};");
    gen.doWriteLine("InstanceTable& table = dispatcher.instanceTable;");
    writeDepends(gen, functionLevels.instance, &FunctionInfo::writeLoadInstance);
    gen.doReturn("dispatcher");
    gen.endScope();
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)");
    gen.doEndNamespace();
    write(gen, src, "LoadInstanceTable.cpp", ctx);

    // LoadDeviceTable.cpp
    gen.doIncludesLocal({"VkBindings/private/FunctionTables.hpp", "VkBindings/private/Loader.hpp",
                         "VkBindings/Handles.hpp"});
    gen.doBeginNamespace("VkBindings::impl_Loader");
    gen.doWriteLine("// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)");
    gen.doLineBeginScope("auto LoadDeviceTable(Handle::Device device, const "
                         "Dispatcher& instanceDispatcher) -> Dispatcher");
    gen.doWriteLine("Dispatcher dispatcher = instanceDispatcher;");
    gen.doWriteLine("DeviceTable& table = dispatcher.deviceTable;");
    writeDepends(gen,
                 functionLevels.device | std::views::values | std::views::join |
                     std::ranges::to<std::set>(),
                 &FunctionInfo::writeLoadDevice);
    gen.doReturn("dispatcher");
    gen.endScope();
    gen.doWriteLine("// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)");
    gen.doEndNamespace();
    write(gen, src, "LoadDeviceTable.cpp", ctx);
}

void initStatics(Registry registry) {
    FunctionInfo::allEnums = EnumInfo::parseAllEnums(registry.setVkActive());
    FunctionInfo::allEnumFlags = EnumInfo::parseAllEnumFlags(registry.setVkActive());
    FunctionInfo::allStructs = StructInfo::parseAllStructs(registry.setVkActive());
    FunctionInfo::allUnions = StructInfo::parseAllUnions(registry.setVkActive());
    FunctionInfo::enumZeroElements = EnumInfo::parseEnumZeroElement(registry.setVkActive());
    FunctionInfo::enumSizeTypes = EnumInfo::getEnumSizeTypes(registry.setVkActive());
    FunctionInfo::baseTypeMapping = BaseTypeInfo::getBaseTypeMapping(registry.setVkActive());
    FunctionInfo::alias = parseAlias(registry.setVkActive());
    FunctionInfo::handleHasFunctions = ObjectInfo::parseObjectInfos(registry.setVkActive()) |
                                       std::views::filter(&ObjectInfo::hasFunctions) |
                                       std::views::transform(&ObjectInfo::getName) |
                                       std::ranges::to<std::unordered_set>();
}

void writeFiles(const std::filesystem::path &genDir, Registry registry,
                const std::vector<std::function<void(WriteCtx &ctx)>> &functions) {
    CppGenerator gen;
    WriteCtx ctx{.firstWrite = true,
                 .generatedFiles = {},
                 .registry = registry,
                 .gen = gen,
                 .genDir = genDir};

    std::filesystem::remove_all(privatInclude(ctx));
    std::filesystem::remove_all(include(ctx));
    std::filesystem::remove_all(reflectionInclude(ctx));
    std::filesystem::remove_all(src(ctx));
    std::filesystem::remove_all(validation(ctx));
    std::filesystem::remove_all(cmake(ctx));

    std::filesystem::create_directories(cmake(ctx));
    std::filesystem::create_directories(validation(ctx));
    std::filesystem::create_directories(src(ctx));
    std::filesystem::create_directories(include(ctx));
    std::filesystem::create_directories(reflectionInclude(ctx));
    std::filesystem::create_directories(privatInclude(ctx));

    for (const auto &function : functions) {
        std::cout << "Writing : [";
        ctx.firstWrite = true;
        auto start = std::chrono::high_resolution_clock::now();
        function(ctx);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "] ";
        std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start) << "\n";
    }

    auto filterExtension = [](const std::string &extension) -> auto {
        return std::views::filter([&extension](const std::filesystem::path &path) -> bool {
            return path.extension() == extension;
        });
    };

    auto hasValidation = std::views::filter([](const std::filesystem::path &path) -> bool {
        return std::ranges::find(path, "validation") != path.end();
    });

    auto hasNoValidation = std::views::filter([](const std::filesystem::path &path) -> bool {
        return std::ranges::find(path, "validation") == path.end();
    });

    std::ofstream generated(cmake(ctx) / "GeneratedFiles.cmake");
    generated << "set(GENERATED_HEADERS\n";
    for (const auto &generatedFile : ctx.generatedFiles | filterExtension(".hpp")) {
        generated << "\t\"${GENERATED_DIR}/"
                  << std::filesystem::relative(generatedFile, genDir).string() << "\"\n";
    }
    generated << ")\n";
    generated << "set(GENERATED_SRCS\n";
    for (const auto &generatedFile :
         ctx.generatedFiles | filterExtension(".cpp") | hasNoValidation) {
        generated << "\t\"${GENERATED_DIR}/"
                  << std::filesystem::relative(generatedFile, genDir).string() << "\"\n";
    }
    generated << ")\n";
    generated << "set(VALIDATION_SRCS\n";
    for (const auto &generatedFile : ctx.generatedFiles | filterExtension(".cpp") | hasValidation) {
        generated << "\t\"${GENERATED_DIR}/"
                  << std::filesystem::relative(generatedFile, genDir).string() << "\"\n";
    }
    generated << ")\n";
}
