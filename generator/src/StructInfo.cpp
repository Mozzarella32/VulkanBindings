#include "StructInfo.hpp"
#include "BaseTypeInfo.hpp"
#include "ConstantInfo.hpp"
#include "CppGenerator.hpp"
#include "EnumInfo.hpp"
#include "ParseXml.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <ranges>
#include <string_view>
#include <unordered_set>

using namespace tinyxml2;

auto StructTemplateInstanceInfo::operator<(const StructTemplateInstanceInfo &other) const -> bool {
    return std::tie(depends, type) < std::tie(other.depends, other.type);
}

void StructTemplateInstanceInfo::writeAssert(CppGenerator &gen) const {
    gen.doWriteLine("static_assert(std::is_standard_layout_v<" + type + ">);");
}

void StructTemplateInstanceInfo::writeImpl(CppGenerator &gen) const {
    gen.doWriteLine("template struct " + type + ";");
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
    for (const auto &m : members) {
        typeLen = std::max(typeLen, (m.fullType()).size());
        nameLen = std::max(nameLen, (m.name + m.postArgumentPrint()).size());
    }
    for (const auto &m : members) {
        if (m.removed)
            continue;
        line << std::left << std::setw(static_cast<int>(typeLen)) << m.fullType()
             << std::setw(static_cast<int>(nameLen)) << m.name + m.postArgumentPrint();
        if (isUnion) {
            line << ";";
        } else {
            line << " = " << m.value + ";";
        }
        if (m.len != "" || m.optional) {
            line << "// ";
            if (m.optional) {
                line << "opt ";
            }
            if (m.len != "") {
                line << "len " << m.len;
            }
        }
        gen.doWriteLine(line);
    }
    for (const auto &f : functions) {
        gen.doWriteLine(f.toSignature(true) + ";");
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

    for (const auto &m : members) {
        if (!m.trailing.contains(":")) {
            gen.doWriteLine("static_assert(offsetof(" + name + ", " + m.name + ")" + m.offsetOf +
                            " == offsetof(" + originalName + ", " + m.vulkanName + "));");
        }
        gen.doWriteLine("static_assert(alignof(decltype(std::declval<" + name + ">()." + m.name +
                        m.accessor + ")) == alignof(decltype(std::declval<" + originalName +
                        ">()." + m.vulkanName + ")));");
        gen.doWriteLine("static_assert(sizeof(decltype(std::declval<" + name + ">()." + m.name +
                        m.accessor + ")) == sizeof(decltype(std::declval<" + originalName + ">()." +
                        m.vulkanName + ")));");
    }
}

auto parseAllStructs(XMLElement &registry) -> const std::unordered_set<std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>> regAllStructs;
    auto &allStructs = regAllStructs[&registry];

    if (!allStructs.empty())
        return allStructs;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, "category", "struct"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        std::string name = Attribute(type, "name");
        if (objectsDisabled.contains(name))
            return;

        allStructs.insert(name);
    });
    return allStructs;
}

auto parseAllUnions(XMLElement &registry) -> const std::unordered_set<std::string> & {
    static std::unordered_set<std::string> allUnions;
    if (!allUnions.empty())
        return allUnions;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, "category", "union"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        std::string name = Attribute(type, "name");
        if (objectsDisabled.contains(name))
            return;

        allUnions.insert(name);
    });
    return allUnions;
}

extern auto parseStructInfosAndTemplateInstantiations(tinyxml2::XMLElement &registry)
    -> const std::tuple<std::set<StructInfo>, std::set<StructTemplateInstanceInfo>> & {
    static std::unordered_map<
        XMLElement *, std::tuple<std::set<StructInfo>, std::set<StructTemplateInstanceInfo>>>
        regInfosAndTemplateInstances;
    auto &infosAndTemplateInstances = regInfosAndTemplateInstances[&registry];
    if (!std::get<0>(infosAndTemplateInstances).empty() ||
        !std::get<1>(infosAndTemplateInstances).empty())
        return infosAndTemplateInstances;

    std::unordered_map<std::string, StructInfo> infos;
    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");
    const auto &typeDepends = parseObjectDepents(registry, "type");

    auto removeVk = [](const std::string &s) -> std::string {
        if (s.starts_with("Vk")) {
            return s.substr(2);
        }
        return s;
    };

    const auto &alias = parseAlias(registry);

    auto parseMember = [&](XMLElement &member, const StructInfo &s) -> StructInfo::Member {
        StructInfo::Member m;
        m = parseTypeAndName(member);
        if (alias.contains(m.baseType)) {
            m.baseType = alias.at(m.baseType);
        }
        m.vulkanName = m.name;
        prerequisits[s.originalName].insert(m.baseType);
        if (HasAttribute(member, "len")) {
            m.len = Attribute(member, "len");
            if (m.len.starts_with("latexmath")) {
                assert(HasAttribute(member, "altlen"));
                m.len = Attribute(member, "altlen");
            }
            if (m.len.contains("/") || m.len.contains("*")) {
                m.len = "";
                return m;
            }
        }
        return m;
    };

    auto parseMemberArrayWithLengthOf = [](std::vector<StructInfo::Member> &members) -> void {
        for (auto &m : members) {
            for (const auto &len : splitCSL(m.len)) {
                if (len != "null-terminated" && len != "1" && !len.contains("->") &&
                    !len.starts_with("latexmath")) {
                    auto it =
                        std::ranges::find_if(members, [&](const StructInfo::Member &mem) -> bool {
                            return mem.name == len;
                        });
                    assert(it != members.end());
                    assert(!m.arrayWithLengthOf);
                    m.arrayWithLengthOf = std::distance(members.begin(), it);
                }
            }
        }
    };

    XMLElement &types = FirstChildElement(registry, "types");

    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, "category", "struct"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        StructInfo s;
        s.isUnion = false;
        s.originalName = Attribute(type, "name");
        if (objectsDisabled.contains(s.originalName))
            return;
        if (auto it = typeDepends.find(s.originalName); it != typeDepends.end())
            s.depends = it->second;
        s.name = removeVk(s.originalName);
        std::vector<StructInfo::Member> members;
        ForEach(type, "member", [&](XMLElement &member) -> void {
            if (HasAttribute(member, "api") &&
                !splitCSL(Attribute(member, "api")).contains("vulkan"))
                return;
            members.emplace_back(parseMember(member, s));
        });
        parseMemberArrayWithLengthOf(members);
        s.members = std::move(members);
        infos[s.originalName] = std::move(s);
    });
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, "category", "union"))
            return;
        if (HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        StructInfo s;
        s.isUnion = true;
        s.originalName = Attribute(type, "name");
        if (objectsDisabled.contains(s.originalName))
            return;
        if (auto it = typeDepends.find(s.originalName); it != typeDepends.end())
            s.depends = it->second;
        s.name = removeVk(s.originalName);
        std::vector<StructInfo::Member> members;
        ForEach(type, "member", [&](XMLElement &member) -> void {
            if (HasAttribute(member, "api") &&
                !splitCSL(Attribute(member, "api")).contains("vulkan"))
                return;
            members.emplace_back(parseMember(member, s));
        });
        parseMemberArrayWithLengthOf(members);
        s.members = std::move(members);
        infos[s.originalName] = std::move(s);
    });

    const auto &handles = parseHandles();
    const auto &constantMapping = getConstantMapping();
    const auto &constantValues = getConstantValues();
    const auto &typeStructure = parseTypeStructureName(registry);
    const auto &enumMapping = getEnumElementMapping(registry);
    const auto &allStructs = parseAllStructs(registry);
    const auto &allUnions = parseAllUnions(registry);
    const auto &allEnums = parseAllEnums(registry);
    const auto &allEnumFlags = parseAllEnumFlags(registry);
    const auto &enumZeroElements = parseEnumZeroElement(registry);
    const auto &intTypedefs = getIntTypedefs(registry);

    auto removeP = [](std::string str) -> std::string {
        if (str[0] != 'p')
            return str;
        str = str.substr(1);
        str[0] = static_cast<char>(std::tolower(str[0]));
        return str;
    };

    static std::unordered_set<std::string> BuildInTypes = {"HINSTANCE",
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
        if (auto it = typeDepends.find(type); it != typeDepends.end())
            return it->second;
        return Depends{};
    };

    auto generateZeroValue = [&](const StructInfo &s, const StructInfo::Member &m) -> std::string {
        // value
        if (m.postType == "" && m.trailing == "") {
            if (m.baseType == "float") {
                return "0.0f";
            } else if (m.baseType == "double") {
                return "0.0";
            } else if (m.baseType == "int" || m.baseType == "uint8_t" || m.baseType == "int8_t" ||
                       m.baseType == "uint16_t" || m.baseType == "uint32_t" ||
                       m.baseType == "int32_t" || m.baseType == "int64_t" ||
                       m.baseType == "uint64_t" || m.baseType == "VkDeviceSize" ||
                       m.baseType == "VkDeviceAddress" || m.baseType == "size_t") {
                return "0";
            } else if (m.baseType == "VkBool32") {
                return "Constants::False";
            } else if (m.baseType == "VkStructureType" && s.originalName != "VkBaseOutStructure" &&
                       s.originalName != "VkBaseInStructure") {
                assert(typeStructure.contains(s.originalName));
                assert(enumMapping.contains(typeStructure.at(s.originalName)));
                return "StructureType::" + enumMapping.at(typeStructure.at(s.originalName));

            } else if (m.baseType == "VkStructureType" && (s.originalName == "VkBaseOutStructure" ||
                                                           s.originalName == "VkBaseInStructure")) {
                return "static_cast<StructureType>(0)";
            } else if (allStructs.contains(m.baseType) || allUnions.contains(m.baseType)) {
                return "{}";
            } else if (alias.contains(m.baseType)) {
                const std::string &realEnum = alias.at(m.baseType);
                if (allEnums.contains(removeVk(realEnum))) {
                    return enumZeroElements.at(realEnum);
                } else {
                    assert(allEnumFlags.contains(removeVk(realEnum)));
                    return "{}";
                }
            } else if (allEnums.contains(removeVk(m.baseType))) {
                return enumZeroElements.at(m.baseType);
            } else if (allEnumFlags.contains(removeVk(m.baseType))) {
                return "{}";
            } else if (m.baseType.starts_with("impl_Struct::AssignableHandle") ||
                       m.baseType.starts_with("impl_Struct::InString") ||
                       m.baseType.starts_with("impl_Struct::FixedString") ||
                       m.baseType.starts_with("std::array")) {
                return "{}";
            } else if (BuildInTypes.contains(m.baseType)) {
                return "{}";
            } else if (m.baseType.starts_with("PFN::")) {
                return "nullptr";
            }
            assert(false);
            return "{}";
        } else if (m.trailing.starts_with(":")) {
            return "0";
        } else if (m.trailing.starts_with("[")) {
            if (m.baseType == "char") {
                return "\"\"";
            } else if (alias.contains(m.baseType)) {
                const std::string &realEnum = alias.at(m.baseType);
                if (allEnums.contains(removeVk(realEnum))) {
                    return "{" + enumZeroElements.at(realEnum) + "}";
                } else {
                    assert(allEnumFlags.contains(removeVk(realEnum)));
                    return "{}";
                }
            } else if (allEnums.contains(removeVk(m.baseType))) {
                return "{" + enumZeroElements.at(m.baseType) + "}";
            }
            return "{}";
        } else if (m.postType.contains("*")) {
            return "nullptr";
        }
        assert(false);
        return "{}";
    };

    auto &templateInstances = std::get<1>(infosAndTemplateInstances);

    for (auto &[_, info] : infos) {
        for (auto &m : info.members) {
            if (m.baseType.starts_with("PFN")) {
                static const std::string pfn = "PFN_vk";
                if (auto it = m.baseType.find(pfn); it != std::string::npos) {
                    m.baseType.erase(it, pfn.size());
                }

                m.baseType = "PFN::" + m.baseType;
            }
            if (m.len == "" && handles.contains(m.baseType)) {
                if (m.postType == "*") {
                    assert(m.leading == "const");
                    m.postType = "";
                    m.leading = "";

                    assert(m.name[0] == 'p');
                    m.name = m.name.substr(1);
                    m.name[0] = static_cast<char>(std::tolower(m.name[0]));
                } else {
                    assert(m.leading == "");
                    assert(m.postType == "");
                    assert(m.trailing == "");
                }
                const auto &type =
                    templateInstances
                        .emplace(getTypeDepends(m.baseType),
                                 "impl_Struct::AssignableHandle<" + removeVk(m.baseType) + ">")
                        .first->type;
                m.baseType = type;
                m.offsetOf += " + offsetof(" + type + ", handle)";
            }
            if (m.len != "" && handles.contains(m.baseType)) {
                const auto &type =
                    templateInstances
                        .emplace(getTypeDepends(m.baseType),
                                 "impl_Struct::AssignableHandle<" + removeVk(m.baseType) + ">")
                        .first->type;
                m.baseType = type;
                m.offsetOf += " + offsetof(" + type + ", handle)";
            }
            if (m.trailing.starts_with("[") &&
                constantMapping.contains(m.trailing.substr(1, m.trailing.size() - 2))) {
                const auto &constantName =
                    constantMapping.at(m.trailing.substr(1, m.trailing.size() - 2));
                const auto &constant = "Constants::" + constantName;
                if (m.baseType == "char") {
                    m.trailing = "";
                    templateInstances.emplace(Depends{}, "impl_Struct::FixedString<" +
                                                             constantValues.at(constantName) + ">");
                    auto type = "impl_Struct::FixedString<" + constant + ">";
                    m.baseType = type;
                    m.offsetOf += "+ offsetof(" + type + ", data)";
                } else {
                    m.trailing = "[" + constant + "]";
                }
            }
            if (m.leading == "const" && m.baseType == "char" && m.postType == "*" &&
                m.len == "null-terminated") {
                m.len = "";
                m.leading = "";
                m.postType = "";
                m.baseType = "impl_Struct::InString";
                m.name = removeP(m.name);
                m.offsetOf += " + offsetof(impl_Struct::InString, pStr)";
            }
            if (auto it = alias.find(m.baseType); it != alias.end()) {
                m.baseType = it->second;
            }
            m.value = generateZeroValue(info, m);

            if (m.baseType.starts_with("Vk")) {
                m.baseType = m.baseType.substr(2, m.baseType.size() - 2);
                static const std::string Flags = "Flags";
                if (auto it = m.baseType.find(Flags);
                    m.trailing.contains(":") && it != std::string::npos) {
                    m.baseType = m.baseType + "::MaskType";
                }
            }
            while (!m.trailing.empty() && m.trailing.starts_with("[")) {
                auto close = m.trailing.find(']');
                assert(close != std::string::npos);
                auto constant = m.trailing.substr(1, close - 1);
                if (constantMapping.contains(constant)) {
                    const auto &constantName = constantMapping.at(constant);
                    constant = "Constants::" + constantName;
                }
                m.trailing = m.trailing.substr(close + 1);
                m.baseType = "std::array<" + m.baseType + ", " + constant + ">";
            }
        }

        for (size_t i = 1; i < info.members.size(); i++) {
            const auto &curr = info.members[i];
            if (!curr.arrayWithLengthOf)
                continue;
            const auto &len = info.members[curr.arrayWithLengthOf.value()];
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
        std::erase_if(pair.second, [&](const std::string &s) -> bool { return s == pair.first; });
    });

    std::unordered_set<std::string> toRemove; // Roots of the dependency tree
    std::unordered_map<std::string, int> rank;
    int currentRank = 0;

    std::unordered_set<std::string> roots;

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
            std::erase_if(pair.second,
                          [&](const std::string &s) -> bool { return toRemove.contains(s); });
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
        StructInfo si = info;
        si.rank = rank.at(si.originalName);
        if (auto it = typeDepends.find(info.originalName); it != typeDepends.end()) {
            si.depends = it->second;
        }
        structInfos.emplace(std::move(si));
    }
    return infosAndTemplateInstances;
}
