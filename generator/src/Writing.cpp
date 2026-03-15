#include "Writing.hpp"
#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "ObjectInfo.hpp"
#include "ParseXml.hpp"
#include "StructInfo.hpp"
#include "TypeInfo.hpp"

#include <chrono>
#include <fstream>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <utility>

template <typename T, typename F>
    requires requires(const T &t, std::ostream &o, CppGenerator &gen, F print) {
        { t.depends } -> std::same_as<const Depends &>;
        print(gen, std::declval<T>());
    }
void writeDepends(CppGenerator &gen, const T &t, F print, bool reversed = false) {
    writeDepends(gen, std::set<T>{t}, print, reversed);
}

void writeTypeInfos(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                    [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<TypeInfo> typeInfos = parseTypeInfos(registry);

    std::filesystem::path structureTypes = genSrc / "Structures.cpp";

    CppGenerator gen;

    gen.doIncludeLocal("VkBindings/Structures.hpp");
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    gen.doCode(R"--(
template <typename T> struct StructureType;

template <typename T>
T Init() {
  T t = {};
  t.sType = StructureType<T>::t;
  return t;
}
)--");

    writeDepends(gen, typeInfos, TypeInfo::writeSpecialisation);

    gen.doEndNamespace();
    gen.doEmptyLine();

    std::ofstream o(structureTypes);
    o << gen.buff.rdbuf();
}

void writeObjects(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                  const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(registry);

    std::filesystem::path objectsForwardHpp = genInclude / "Objects_Forward.hpp";
    std::filesystem::path objectsHpp = genInclude / "Objects.hpp";
    std::filesystem::path objectsCpp = genSrc / "Objects.cpp";
    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doIncludeLocal("ObjectTemplates.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    writeDepends(gen, objectInfos, ObjectInfo::writeForwardDecl, true);
    gen.doEndNamespace();

    std::ofstream o(objectsForwardHpp);
    o << gen.buff.rdbuf();
    o.close();

    gen.startHeader();
    gen.doIncludeGlobal("cassert");
    gen.doIncludeGlobal("cstdint");
    gen.doIncludeGlobal("expected");
    gen.doEmptyLine();
    gen.doIncludeLocal("VkBindings/Objects_Forward.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    std::set<ObjectInfo> objectsWithFuns =
        objectInfos |
        std::views::filter([](const ObjectInfo &info) { return !info.functions.empty(); }) |
        std::ranges::to<std::set<ObjectInfo>>();

    writeDepends(gen, objectsWithFuns, ObjectInfo::writeHeader);

    gen.doEndNamespace();

    o.open(objectsHpp);
    o << gen.buff.rdbuf();
    o.close();

    auto implPre = [&] {
        gen.doIncludeLocal("VkBindings/Objects.hpp");
        gen.doEmptyLine();
        gen.doBeginNamespace("VkBindings");
    };

    auto implPost = [&](const std::filesystem::path &path) {
        gen.doEndNamespace();
        o.open(path);
        o << gen.buff.rdbuf();
        o.close();
    };

    const std::unordered_set<std::string> ownFile = {"Instance", "PhysicalDevice", "Device",
                                                     "CommandBuffer"};

    for (const auto &objectInfo : objectInfos) {
        if (!ownFile.contains(objectInfo.name))
            continue;
        std::filesystem::path path = genSrc / (objectInfo.name + ".cpp");
        implPre();
        writeDepends(gen, objectInfo, ObjectInfo::writeImpl);
        implPost(path);
    }

    std::erase_if(objectsWithFuns,
                  [&](const ObjectInfo &info) { return ownFile.contains(info.name); });

    implPre();
    writeDepends(gen, objectsWithFuns, ObjectInfo::writeImpl);
    implPost(objectsCpp);
}

void writeObjectTypes(tinyxml2::XMLElement &registry,
                      [[maybe_unused]] const std::filesystem::path &genSrc,
                      [[maybe_unused]] const std::filesystem::path &genInclude) {

    std::set<ObjectInfo> objectInfos = parseObjectInfos(registry);

    std::filesystem::path objectTypesCpp = genSrc / "ObjectTypes.cpp";

    CppGenerator gen;
    gen.doIncludeLocal("VkBindings/ObjectTypes.hpp");
    gen.doIncludeLocal("VkBindings/Objects.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Reflection");

    gen.doCode(R"--(
template <typename T>
VkObjectType ObjectType() {
    return T::objectType;
}
)--");

    writeDepends(gen, objectInfos, ObjectInfo::writeObjectTypes);

    gen.doEndNamespace();
    gen.doEndNamespace();

    std::ofstream o(objectTypesCpp);
    o << gen.buff.rdbuf();
}

void writeConstants(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                    const std::filesystem::path &genInclude) {

    std::set<ConstantInfo> constantInfos = parseConstantInfos(registry);

    std::filesystem::path constantsHpp = genInclude / "Constants.hpp";
    std::filesystem::path constantsCpp = genSrc / "Constants.cpp";

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("cstdint");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Constants");

    writeDepends(gen, constantInfos, ConstantInfo::writeHeader);

    gen.doEndNamespace();
    gen.doEndNamespace();

    std::ofstream o(constantsHpp);
    o << gen.buff.rdbuf();
    o.close();

    gen.doIncludeLocal("VkBindings/Constants.hpp");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");
    gen.doBeginNamespace("Constants");

    writeDepends(gen, constantInfos, ConstantInfo::writeImpl);

    gen.doEndNamespace();
    gen.doEndNamespace();

    o.open(constantsCpp);
    o << gen.buff.rdbuf();
}

void writeEnums(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                const std::filesystem::path &genInclude) {

    std::set<EnumInfo> enumInfos = parseEnumInfos(registry);
    std::set<EnumInfo> enumInfosDepends = parseEnumInfosDepends(registry);

    std::filesystem::path enumsHpp = genInclude / "Enums.hpp";
    std::filesystem::path assertCpp = genSrc / "EnumsCorrectAsserts.cpp";

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeGlobal("cstdint");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    writeDepends(gen, enumInfos, EnumInfo::writeHeader);

    gen.doEndNamespace();

    std::ofstream o(enumsHpp);
    o << gen.buff.rdbuf();
    o.close();

    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doEmptyLine();

    std::set<EnumInfo> enumInfosDependsWithElements =
        enumInfosDepends |
        std::views::filter([](const EnumInfo &info) { return !info.elements.empty(); }) |
        std::ranges::to<std::set<EnumInfo>>();

    writeDepends(gen, enumInfosDependsWithElements, EnumInfo::writeAssert);

    o.open(assertCpp);
    o << gen.buff.rdbuf();
}

void writeStructs(tinyxml2::XMLElement &registry, const std::filesystem::path &genSrc,
                  const std::filesystem::path &genInclude) {

    std::set<StructInfo> structInfos = parseStructInfos(registry);

    std::filesystem::path structsHpp = genInclude / "Structs.hpp";
    std::filesystem::path assertCpp = genSrc / "StructsCorrectAsserts.cpp";

    CppGenerator gen;
    gen.startHeader();
    gen.doIncludeLocal("VkBindings/Enums.hpp");
    gen.doIncludeLocal("VkBindings/Objects.hpp");
    gen.doEmptyLine();
    gen.doIncludeGlobal("cstdint");
    gen.doEmptyLine();
    gen.doBeginNamespace("VkBindings");

    gen.doCode(R"--(
template<typename T>
requires requires {typename T::handle_type; }
struct AssignableHandle {
	using handle_type = T::handle_type;

	handle_type handle;

	AssignableHandle& operator =(T& t) {
		handle = t.get();
	}
};
)--");

    gen.doWriteLine("typedef uint32_t SampleMask;");
    gen.doWriteLine("typedef uint32_t Bool32;");
    gen.doWriteLine("typedef uint32_t Flags;");
    gen.doWriteLine("typedef uint64_t Flags64;");
    gen.doWriteLine("typedef uint64_t DeviceSize;");
    gen.doWriteLine("typedef uint64_t DeviceAddress;");

    writeDepends(gen, structInfos, StructInfo::writeHeader);

    gen.doEndNamespace();

    std::ofstream o(structsHpp);
    o << gen.buff.rdbuf();
    o.close();

    gen.doIncludeLocal("VkBindings/Structs.hpp");
    gen.doIncludeLocal("VkBindings/Vulkan.hpp");
    gen.doEmptyLine();

    std::set<StructInfo> structInfosWithMembers =
        structInfos |
        std::views::filter([](const StructInfo &info) { return !info.members.empty(); }) |
        std::ranges::to<std::set<StructInfo>>();

    writeDepends(gen, structInfosWithMembers, StructInfo::writeAssert);

    o.open(assertCpp);
    o << gen.buff.rdbuf();
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
