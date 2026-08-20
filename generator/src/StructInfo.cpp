#include "StructInfo.hpp"
#include "BaseTypeInfo.hpp"
#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"
#include "XmlUtils.hpp"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <functional>
#include <iomanip>
#include <ios>
#include <iterator>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace tinyxml2;

auto StructTemplateInstanceInfo::getDepends() const -> const Depends & { return depends; }

auto StructTemplateInstanceInfo::isInstance(std::string_view prefix) const -> bool {
    return type.starts_with("impl_Struct::" + std::string(prefix));
}

auto StructTemplateInstanceInfo::operator<(const StructTemplateInstanceInfo &other) const -> bool {
    return std::tie(depends, type) < std::tie(other.depends, other.type);
}

void StructTemplateInstanceInfo::writeAssert(CppGenerator &gen) const {
    gen.doWriteLine("static_assert(std::is_standard_layout_v<" + type + ">);");
}

void StructTemplateInstanceInfo::writeImpl(CppGenerator &gen) const {
    gen.doWriteLine("template struct " + type + ";");
}

void StructTemplateInstanceInfo::writeDecl(CppGenerator &gen) const {
    std::string typeWithoutNamespace = type;
    constinit static const std::string_view implStruct = "impl_Struct::";
    for (size_t pos = typeWithoutNamespace.find(implStruct); pos != std::string::npos;
         pos = typeWithoutNamespace.find(implStruct, pos)) {
        typeWithoutNamespace.erase(pos, implStruct.size());
    }
    if (typeWithoutNamespace.starts_with(implStruct)) {
        typeWithoutNamespace.erase(0, implStruct.size());
    }
    gen.doWriteLine("extern template struct " + typeWithoutNamespace + ";");
}

auto StructInfo::getDepends() const -> const Depends & { return depends; }
auto StructInfo::getMembers() const -> const std::vector<StructMember> & { return members; }
auto StructInfo::getName() const -> const std::string & { return name; }

auto StructInfo::hasFunctions() const -> bool { return !functions.empty(); }
auto StructInfo::hasMembers() const -> bool { return !members.empty(); }
auto StructInfo::isPfnStruct(const std::unordered_set<std::string> &pfnStruct)
    -> std::function<bool(StructInfo)> {
    return [&pfnStruct](const StructInfo &structInfo) -> bool {
        return pfnStruct.contains(structInfo.originalName);
    };
}

auto StructInfo::operator<(const StructInfo &other) const -> bool {
    return std::tie(rank, depends, name) < std::tie(other.rank, other.depends, other.name);
}

void StructInfo::writeForward(CppGenerator &gen) const {
    if (isUnion) {
        gen.doWriteLine("union " + name + ";");
    } else {
        gen.doWriteLine("struct " + name + ";");
    }
}

void StructInfo::writeHeader(CppGenerator &gen) const {
    // gen.doCode(std::format("// {} rank: {}", name, rank));
    if (isUnion) {
        gen.doBeginUnion(name);
    } else {
        gen.doBeginStruct(name);
    }
    std::stringstream line;
    size_t typeLen = 0;
    size_t nameLen = 0;
    for (const auto &member : members) {
        typeLen = std::max(typeLen, (member.fullType()).size());
        nameLen = std::max(nameLen, (member.name + member.postArgumentPrint()).size());
    }
    for (const auto &member : members) {
        if (member.removed)
            continue;
        line << std::left << std::setw(static_cast<int>(typeLen)) << member.fullType();
        if (isUnion || member.value.empty()) {
            line << member.name + member.postArgumentPrint() << ";";
        } else {
            line << std::setw(static_cast<int>(nameLen)) << member.name + member.postArgumentPrint()
                 << " = " << member.value + ";";
        }
        if (!member.len.empty() || member.optional) {
            line << "// ";
            if (member.optional) {
                line << "opt ";
            }
            if (!member.len.empty()) {
                line << "len " << member.len;
            }
        }
        gen.doWriteLine(line);
    }
    for (const auto &function : functions) {
        gen.doWriteLine(function.toSignature(true) + ";");
    }
    if (isUnion) {
        gen.doEndUnion();
    } else {
        gen.doEndStruct();
    }
}

void StructInfo::writeImpl(CppGenerator &gen) const {
    for (const auto &function : functions) {
        gen.doLineBeginScope(function.toSignature());
        gen.doCode(function.body);
        gen.endScope();
    }
}

void StructInfo::writeAssert(CppGenerator &gen) const {
    gen.doWriteLine("// " + name);
    gen.doWriteLine("static_assert(std::is_standard_layout_v<" + name + ">);");
    gen.doWriteLine("static_assert(sizeof(" + name + ") == sizeof(" + originalName + "));");
    gen.doWriteLine("static_assert(alignof(" + name + ") == alignof(" + originalName + "));");

    for (const auto &member : members) {
        if (!member.trailing.contains(":")) {
            gen.doWriteLine("static_assert(offsetof(" + name + ", " + member.name + ")" +
                            member.offsetOf + " == offsetof(" + originalName + ", " +
                            member.vulkanName + "));");
        }
        gen.doWriteLine("static_assert(alignof(decltype(std::declval<" + name + ">()." +
                        member.name + member.accessor + ")) == alignof(decltype(std::declval<" +
                        originalName + ">()." + member.vulkanName + ")));");
        gen.doWriteLine("static_assert(sizeof(decltype(std::declval<" + name + ">()." +
                        member.name + member.accessor + ")) == sizeof(decltype(std::declval<" +
                        originalName + ">()." + member.vulkanName + ")));");
    }
}

auto StructInfo::parseAllStructs(Registry registry) -> const std::unordered_set<std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>> regAllStructs;
    auto &allStructs = regAllStructs[&registry.getActive()];

    if (!allStructs.empty())
        return allStructs;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"struct"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        const std::string name = Attribute(type, "name");
        if (objectsDisabled.contains(name))
            return;

        allStructs.insert(name);
    });
    return allStructs;
}

auto StructInfo::parseAllUnions(Registry registry) -> const std::unordered_set<std::string> & {
    static std::unordered_set<std::string> allUnions;
    if (!allUnions.empty())
        return allUnions;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"union"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        const std::string name = Attribute(type, "name");
        if (objectsDisabled.contains(name))
            return;

        allUnions.insert(name);
    });
    return allUnions;
}

auto StructInfo::parseStructInfosAndTemplateInstantiations(Registry registry)
    -> const std::tuple<std::set<StructInfo>, std::set<StructTemplateInstanceInfo>> & {
    static std::unordered_map<
        XMLElement *, std::tuple<std::set<StructInfo>, std::set<StructTemplateInstanceInfo>>>
        regInfosAndTemplateInstances;
    auto &infosAndTemplateInstances = regInfosAndTemplateInstances[&registry.getActive()];
    if (!std::get<0>(infosAndTemplateInstances).empty() ||
        !std::get<1>(infosAndTemplateInstances).empty())
        return infosAndTemplateInstances;

    std::unordered_map<std::string, StructInfo> infos;
    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");
    const auto &typeDepends = parseObjectDepents(registry, "type");

    auto removeVk = [](const std::string &str) -> std::string {
        if (str.starts_with("Vk")) {
            return str.substr(2);
        }
        return str;
    };

    const auto &alias = parseAlias(registry);

    auto parseMember = [&](XMLElement &memberXML, const StructInfo &structInfo) -> StructMember {
        StructMember memeber;
        memeber = parseTypeAndName(memberXML);
        if (alias.contains(memeber.baseType)) {
            memeber.baseType = alias.at(memeber.baseType);
        }
        memeber.vulkanName = memeber.name;
        prerequisits[structInfo.originalName].insert(memeber.baseType);
        if (HasAttribute(memberXML, "len")) {
            memeber.len = Attribute(memberXML, "len");
            if (memeber.len.starts_with("latexmath")) {
                assert(HasAttribute(memberXML, "altlen"));
                memeber.len = Attribute(memberXML, "altlen");
            }
            if (memeber.len.contains("/") || memeber.len.contains("*")) {
                memeber.len = "";
                return memeber;
            }
        }
        return memeber;
    };

    auto parseMemberArrayWithLengthOf = [](std::vector<StructMember> &members) -> void {
        for (auto &member : members) {
            for (const auto &len : splitCSL(member.len)) {
                if (len != "null-terminated" && len != "1" && !len.contains("->") &&
                    !len.starts_with("latexmath")) {
                    auto iter = std::ranges::find_if(
                        members, [&](const StructMember &mem) -> bool { return mem.name == len; });
                    assert(iter != members.end());
                    assert(!member.arrayWithLengthOf);
                    member.arrayWithLengthOf = std::distance(members.begin(), iter);
                }
            }
        }
    };

    XMLElement &types = FirstChildElement(registry.getActive(), "types");

    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"struct"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        StructInfo structInfo;
        structInfo.isUnion = false;
        structInfo.originalName = Attribute(type, "name");
        if (objectsDisabled.contains(structInfo.originalName))
            return;
        if (auto iter = typeDepends.find(structInfo.originalName); iter != typeDepends.end())
            structInfo.depends = iter->second;
        structInfo.name = removeVk(structInfo.originalName);
        std::vector<StructMember> members;
        ForEach(type, "member", [&](XMLElement &member) -> void {
            if (HasAttribute(member, "api") &&
                !splitCSL(Attribute(member, "api")).contains("vulkan"))
                return;
            members.emplace_back(parseMember(member, structInfo));
        });
        parseMemberArrayWithLengthOf(members);
        structInfo.members = std::move(members);
        infos[structInfo.originalName] = std::move(structInfo);
    });
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"union"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        StructInfo structInfo;
        structInfo.isUnion = true;
        structInfo.originalName = Attribute(type, "name");
        if (objectsDisabled.contains(structInfo.originalName))
            return;
        if (auto iter = typeDepends.find(structInfo.originalName); iter != typeDepends.end())
            structInfo.depends = iter->second;
        structInfo.name = removeVk(structInfo.originalName);
        std::vector<StructMember> members;
        ForEach(type, "member", [&](XMLElement &member) -> void {
            if (HasAttribute(member, "api") &&
                !splitCSL(Attribute(member, "api")).contains("vulkan"))
                return;
            members.emplace_back(parseMember(member, structInfo));
        });
        parseMemberArrayWithLengthOf(members);
        structInfo.members = std::move(members);
        infos[structInfo.originalName] = std::move(structInfo);
    });

    const auto &handles = parseHandles(registry);
    const auto &constantMapping = ConstantInfo::getConstantMapping(registry);
    const auto &constantValues = ConstantInfo::getConstantValues(registry);
    const auto &typeStructure = parseTypeStructureName(registry);
    const auto &enumMapping = EnumInfo::getEnumElementMapping(registry);
    const auto &allStructs = parseAllStructs(registry);
    const auto &allUnions = parseAllUnions(registry);
    const auto &allEnums = EnumInfo::parseAllEnums(registry);
    const auto &allEnumFlags = EnumInfo::parseAllEnumFlags(registry);
    const auto &enumZeroElements = EnumInfo::parseEnumZeroElement(registry);
    const auto &intTypedefs = BaseTypeInfo::getIntTypedefs(registry);

    auto removeP = [](std::string str) -> std::string {
        if (str.at(0) != 'p')
            return str;
        str = str.substr(1);
        str.at(0) = static_cast<char>(std::tolower(str.at(0)));
        return str;
    };

    static const std::unordered_set<std::string_view> BuildInTypes = {"HINSTANCE",
                                                                      "HWND",
                                                                      "HMONITOR",
                                                                      "HANDLE",
                                                                      "DWORD",
                                                                      "LPCWSTR",
                                                                      "Window",
                                                                      "xcb_window_t",
                                                                      "zx_handle_t",
                                                                      "GgpStreamDescriptor",
                                                                      "GgpFrameToken",
                                                                      "StdVideoH264ProfileIdc",
                                                                      "StdVideoH264LevelIdc",
                                                                      "StdVideoH265ProfileIdc",
                                                                      "StdVideoH265LevelIdc",
                                                                      "StdVideoVP9Profile",
                                                                      "StdVideoVP9Level",
                                                                      "StdVideoAV1Profile",
                                                                      "StdVideoAV1Level",
                                                                      "StdVideoAV1SequenceHeader",
                                                                      "MTLDevice_id",
                                                                      "MTLCommandQueue_id",
                                                                      "MTLBuffer_id",
                                                                      "MTLTexture_id",
                                                                      "IOSurfaceRef",
                                                                      "MTLSharedEvent_id"};

    auto getTypeDepends = [&](const std::string &type) -> Depends {
        if (auto iter = typeDepends.find(type); iter != typeDepends.end())
            return iter->second;
        return Depends{};
    };

    auto generateZeroValue = [&](const StructInfo &structInfo,
                                 const StructMember &member) -> std::string {
        // value
        if (member.postType.empty() && member.trailing.empty()) {
            if (member.baseType == "float") {
                return "0.0F";
            }
            if (member.baseType == "double") {
                return "0.0";
            }
            if (member.baseType == "int" || member.baseType == "uint8_t" ||
                member.baseType == "int8_t" || member.baseType == "uint16_t" ||
                member.baseType == "uint32_t" || member.baseType == "int32_t" ||
                member.baseType == "int64_t" || member.baseType == "uint64_t" ||
                member.baseType == "VkDeviceSize" || member.baseType == "VkDeviceAddress" ||
                member.baseType == "size_t") {
                return "0";
            }
            if (member.baseType == "VkBool32") {
                return "Constants::False";
            }
            if (member.baseType == "VkStructureType" &&
                structInfo.originalName != "VkBaseOutStructure" &&
                structInfo.originalName != "VkBaseInStructure") {
                assert(typeStructure.contains(structInfo.originalName));
                assert(enumMapping.contains(typeStructure.at(structInfo.originalName)));
                return "StructureType::" +
                       enumMapping.at(typeStructure.at(structInfo.originalName));
            }
            if (member.baseType == "VkStructureType" &&
                (structInfo.originalName == "VkBaseOutStructure" ||
                 structInfo.originalName == "VkBaseInStructure")) {
                return "static_cast<StructureType>(0)";
            }
            if (allStructs.contains(member.baseType) || allUnions.contains(member.baseType)) {
                return "{}";
            }
            if (alias.contains(member.baseType)) {
                const std::string &realEnum = alias.at(member.baseType);
                if (allEnums.contains(removeVk(realEnum))) {
                    return enumZeroElements.at(realEnum);
                }
                assert(allEnumFlags.contains(removeVk(realEnum)));
                return "{}";
            }
            if (allEnums.contains(removeVk(member.baseType))) {
                return enumZeroElements.at(member.baseType);
            }
            if (allEnumFlags.contains(removeVk(member.baseType))) {
                return "{}";
            }
            if (member.baseType.starts_with("impl_Struct::AssignableHandle")) {
                return "";
            }
            if (member.baseType.starts_with("impl_Struct::InOutString") ||
                member.baseType.starts_with("impl_Struct::FixedString") ||
                member.baseType.starts_with("impl_Struct::std::array")) {
                return "{}";
            }
            if (BuildInTypes.contains(member.baseType)) {
                return "{}";
            }
            if (member.baseType.starts_with("PFN::")) {
                return "nullptr";
            }
            assert(false);
            return "{}";
        }
        if (member.trailing.starts_with(":")) {
            return "0";
        }
        if (member.trailing.starts_with("[")) {
            if (member.baseType == "char") {
                return "\"\"";
            }
            if (alias.contains(member.baseType)) {
                const std::string &realEnum = alias.at(member.baseType);
                if (allEnums.contains(removeVk(realEnum))) {
                    return "{" + enumZeroElements.at(realEnum) + "}";
                }
                assert(allEnumFlags.contains(removeVk(realEnum)));
                return "{}";
            }
            if (allEnums.contains(removeVk(member.baseType))) {
                return "{}";
            }
            return "{}";
        }
        if (member.postType.contains("*")) {
            return "nullptr";
        }
        assert(false);
        return "{}";
    };

    auto &templateInstances = std::get<1>(infosAndTemplateInstances);

    for (auto &[_, info] : infos) {
        for (auto &member : info.members) {
            if (member.baseType.starts_with("PFN")) {
                static const std::string pfn = "PFN_vk";
                if (auto iter = member.baseType.find(pfn); iter != std::string::npos) {
                    member.baseType.erase(iter, pfn.size());
                }

                member.baseType = "PFN::" + member.baseType;
            }
            if (member.len.empty() && handles.contains(member.baseType)) {
                if (member.postType == "*") {
                    assert(member.leading == "const");
                    member.postType = "";
                    member.leading = "";

                    assert(member.name.at(0) == 'p');
                    member.name = member.name.substr(1);
                    member.name.at(0) = static_cast<char>(std::tolower(member.name.at(0)));
                } else {
                    assert(member.leading.empty());
                    assert(member.postType.empty());
                    assert(member.trailing.empty());
                }
                const auto &type =
                    templateInstances
                        .emplace(getTypeDepends(member.baseType),
                                 "impl_Struct::AssignableHandle<" + removeVk(member.baseType) + ">")
                        .first->type;
                member.baseType = type;
                member.offsetOf += " + offsetof(" + type + ", handle)";
            }
            if (!member.len.empty() && handles.contains(member.baseType)) {
                const auto &type =
                    templateInstances
                        .emplace(getTypeDepends(member.baseType),
                                 "impl_Struct::AssignableHandle<" + removeVk(member.baseType) + ">")
                        .first->type;
                member.baseType = type;
                member.offsetOf += " + offsetof(" + type + ", handle)";
            }
            if (member.trailing.starts_with("[") &&
                constantMapping.contains(member.trailing.substr(1, member.trailing.size() - 2))) {
                const auto &constantName =
                    constantMapping.at(member.trailing.substr(1, member.trailing.size() - 2));
                const auto &constant = "Constants::" + constantName;
                if (member.baseType == "char") {
                    member.trailing = "";
                    templateInstances.emplace(Depends{}, "impl_Struct::FixedString<" +
                                                             constantValues.at(constantName) + ">");
                    auto type = "impl_Struct::FixedString<" + constant + ">";
                    member.baseType = type;
                    member.offsetOf += "+ offsetof(" + type + ", data)";
                } else {
                    member.trailing = "[" + constant + "]";
                }
            }
            if (member.leading == "const" && member.baseType == "char" && member.postType == "*" &&
                member.len == "null-terminated") {
                member.len = "";
                member.leading = "";
                member.postType = "";
                member.baseType = "impl_Struct::InOutString";
                member.name = removeP(member.name);
                member.offsetOf += " + offsetof(impl_Struct::InOutString, pStr)";
            }
            if (auto iter = alias.find(member.baseType); iter != alias.end()) {
                member.baseType = iter->second;
            }
            member.value = generateZeroValue(info, member);

            if (member.baseType.starts_with("Vk")) {
                member.baseType = member.baseType.substr(2, member.baseType.size() - 2);
                constinit static const std::string_view flags = "Flags";
                if (auto iter = member.baseType.find(flags);
                    member.trailing.contains(":") && iter != std::string::npos) {
                    member.baseType = member.baseType + "::MaskType";
                } else if (allEnums.contains(member.baseType)) {
                    member.baseType = EnumInfo::getEnumName(member.baseType);
                }
            }
            while (!member.trailing.empty() && member.trailing.starts_with("[")) {
                auto close = member.trailing.find(']');
                assert(close != std::string::npos);
                auto constant = member.trailing.substr(1, close - 1);
                if (constantMapping.contains(constant)) {
                    const auto &constantName = constantMapping.at(constant);
                    constant = "Constants::" + constantName;
                }
                member.trailing = member.trailing.substr(close + 1);
                member.baseType = "std::array<" + member.baseType + ", " + constant + ">";
            }
        }

        std::unordered_set<size_t> usedLengths;
        for (const auto &curr : info.members) {
            if (!curr.arrayWithLengthOf)
                continue;
            const auto &lenIdx = curr.arrayWithLengthOf.value();
            if (usedLengths.contains(lenIdx)) {
                continue;
            }
            usedLengths.insert(lenIdx);
            const auto &len = info.members.at(lenIdx);
            if (curr.leading == "const" && curr.postType == "*" && curr.baseType != "void") {
                info.functions.emplace_back();
                auto &function = info.functions.back();
                function.className = info.name;
                if (intTypedefs.contains(curr.baseType)) {
                    function.returnType =
                        "impl_Struct::VecView<" + len.baseType + ", " + curr.baseType + ">";
                } else {
                    const auto &type = templateInstances
                                           .emplace(getTypeDepends("Vk" + curr.baseType),
                                                    "impl_Struct::VecView<" + len.baseType + ", " +
                                                        curr.baseType + ">")
                                           .first->type;
                    function.returnType = type;
                }
                function.name = removeP(curr.name);
                function.body = "return {&" + len.name + ", &" + curr.name + "};";
            }
        }
    }

    std::ranges::for_each(prerequisits, [&](auto &pair) -> auto { // remove reflecifity
        std::erase_if(pair.second, [&](const std::string &requirement) -> bool {
            return requirement == pair.first;
        });
    });

    std::unordered_set<std::string> toRemove; // Roots of the dependency tree
    std::unordered_map<std::string, int> rank;
    int currentRank = 0;

    const std::unordered_set<std::string> roots;

    // Add all pre
    for (const auto &[_, pre] : prerequisits) {
        toRemove.insert_range(pre);
    }
    // Tack back all names
    for (const auto &[name, _] : prerequisits) {
        toRemove.erase(name);
    }

    while (!toRemove.empty()) {

        for (const auto &key : toRemove) {
            rank[key] = currentRank;
        }
        currentRank += 1;

        std::ranges::for_each(prerequisits, [&](auto &pair) -> auto {
            std::erase_if(pair.second, [&](const std::string &requirement) -> bool {
                return toRemove.contains(requirement);
            });
        });
        toRemove.clear();

        for (const auto &[name, pre] : prerequisits) {
            if (pre.empty())
                toRemove.insert(name);
        }
        std::erase_if(prerequisits, [&](const auto &pair) -> auto { return pair.second.empty(); });
    }
    assert(prerequisits.empty());

    auto &structInfos = std::get<0>(infosAndTemplateInstances);

    for (const auto &[_, info] : infos) {
        assert(rank.contains(info.originalName));
        StructInfo structInfo = info;
        structInfo.rank = rank.at(structInfo.originalName);
        if (auto iter = typeDepends.find(info.originalName); iter != typeDepends.end()) {
            structInfo.depends = iter->second;
        }
        structInfos.emplace(std::move(structInfo));
    }
    return infosAndTemplateInstances;
}

StructMember::StructMember(TypeAndName &&typeAndName) : TypeAndName(std::move(typeAndName)) {}
