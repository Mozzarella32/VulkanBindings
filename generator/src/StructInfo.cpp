#include "StructInfo.hpp"
#include "ConstantInfo.hpp"
#include "EnumInfo.hpp"
#include "ParseXml.hpp"
#include "XmlUtils.hpp"
#include "tinyxml2.h"

#include <algorithm>
#include <cmath>
#include <print>
#include <ranges>
#include <signal.h>
#include <unordered_set>

using namespace tinyxml2;

std::unordered_map<std::string, std::string> StructInfo::enumAlias = {};

bool StructInfo::operator<(const StructInfo &other) const {
    return std::tie(rank, depends, name) < std::tie(other.rank, other.depends, other.name);
}

std::vector<StructInfo::Member> StructInfo::mapMembers() const {
    std::vector<Member> mappedMembers;
    for (auto m : members) {
        if (auto it = enumAlias.find(m.baseType); it != enumAlias.end()) {
            m.baseType = it->second;
        }
        if (m.baseType.starts_with("Vk")) {
            m.baseType = m.baseType.substr(2, m.baseType.size() - 2);
            static const std::string Flags = "Flags";
            if (auto it = m.baseType.find(Flags);
                m.trailing.contains(":") && it != std::string::npos) {
                m.baseType = m.baseType + "::MaskType";
            }
        }
        mappedMembers.emplace_back(std::move(m));
    }
    return mappedMembers;
};

void StructInfo::writeHeader(CppGenerator &gen, const StructInfo &si) {
    if (si.isUnion) {
        gen.doBeginUnion(si.name);
    } else {
        gen.doBeginStruct(si.name);
    }
    std::stringstream line;
    size_t typeLen = 0;
    size_t nameLen = 0;
    for (auto m : si.mapMembers()) {
        typeLen = std::max(typeLen, (m.fullType()).size());
        nameLen = std::max(nameLen, (m.name + m.postArgumentPrint()).size());
    }
    for (auto m : si.mapMembers()) {
        line << std::left << std::setw(static_cast<int>(typeLen)) << m.fullType()
             << std::setw(static_cast<int>(nameLen)) << m.name + m.postArgumentPrint();
        if (si.isUnion) {
            line << ";";
        } else {
            line << " = " << m.value + ";";
        }
        gen.doWriteLine(line);
    }
    if (si.isUnion) {
        gen.doEndUnion();
    } else {
        gen.doEndStruct();
    }
}

void StructInfo::writeAssert(CppGenerator &gen, const StructInfo &si) {
    gen.doWriteLine("// " + si.name);
    gen.doWriteLine("static_assert(sizeof(VkBindings::" + si.name + ") == sizeof(" +
                    si.originalName + "));");
    gen.doWriteLine("static_assert(alignof(VkBindings::" + si.name + ") == alignof(" +
                    si.originalName + "));");

    const auto mappedMembers = si.mapMembers();
    for (size_t i = 0; i < si.members.size(); i++) {
        if (!mappedMembers[i].trailing.contains(":")) {
            gen.doWriteLine("static_assert(offsetof(VkBindings::" + si.name + ", " +
                            mappedMembers[i].name + ") == offsetof(" + si.originalName + ", " +
                            si.members[i].name + "));");
        }
        gen.doWriteLine("static_assert(alignof(decltype(std::declval<VkBindings::" + si.name +
                        ">()." + mappedMembers[i].name + ")) == alignof(decltype(std::declval<" +
                        si.originalName + ">()." + si.members[i].name + ")));");
        gen.doWriteLine("static_assert(sizeof(decltype(std::declval<VkBindings::" + si.name +
                        ">()." + mappedMembers[i].name + ")) == sizeof(decltype(std::declval<" +
                        si.originalName + ">()." + si.members[i].name + ")));");
    }
}

static const std::unordered_set<std::string> &parseAllStructs(XMLElement &registry) {
    static std::unordered_set<std::string> allStructs;
    if (!allStructs.empty())
        return allStructs;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
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

static const std::unordered_set<std::string> &parseAllUnions(XMLElement &registry) {
    static std::unordered_set<std::string> allUnions;
    if (!allUnions.empty())
        return allUnions;

    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
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

const std::set<StructInfo> &parseStructInfos(XMLElement &registry) {
    static std::set<StructInfo> structInfos;
    if (!structInfos.empty())
        return structInfos;

    std::unordered_map<std::string, StructInfo> infos;
    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    const auto &handles = parseHandles(registry);

    StructInfo::enumAlias = parseEnumAlias(registry);

    const auto &constantMapping = getConstantMapping(registry);
    const auto &typeStructure = parseTypeStructureName(registry);
    const auto &enumMapping = getEnumElementMapping(registry);
    const auto &objectsDisabled = parseObjectsDisabled(registry, "type");
    const auto &allStructs = parseAllStructs(registry);
    const auto &allUnions = parseAllUnions(registry);
    const auto &allEnums = parseAllEnums(registry);
    const auto &enumZeroElements = parseEnumZeroElement(registry);
    const auto &allEnumFlags = parseAllEnumFlags(registry);
    const auto &enumAlias = parseEnumAlias(registry);

    auto generateZeroValue = [&](const StructInfo &s, const StructInfo::Member &m) -> std::string {
        // value
        if (m.postType == "" && m.trailing == "") {
            if (m.baseType == "float") {
                return "0.0f";
            } else if (m.baseType == "int" || m.baseType == "uint8_t" || m.baseType == "uint16_t" ||
                       m.baseType == "uint32_t" || m.baseType == "int32_t" ||
                       m.baseType == "int64_t" || m.baseType == "uint64_t" ||
                       m.baseType == "VkDeviceSize" || m.baseType == "VkDeviceAddress" ||
                       m.baseType == "size_t") {
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
            } else if (enumAlias.contains(m.baseType)) {
                const std::string &realEnum = enumAlias.at(m.baseType);
                if (allEnums.contains(realEnum.substr(2))) {
                    return enumZeroElements.at(realEnum);
                } else {
                    assert(allEnumFlags.contains(realEnum.substr(2)));
                    return "{}";
                }
            }
            if (allEnums.contains(m.baseType.substr(2))) {
                return enumZeroElements.at(m.baseType);
            } else if (allEnumFlags.contains(m.baseType.substr(2))) {
                return "{}";
            } else if (m.baseType.starts_with("PFN")) {
                return "nullptr";
            } else if (m.baseType.starts_with("AssignableHandle")) {
                return "{}";
            } else if (std::unordered_set<std::string>{"HINSTANCE",
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
                                                       "MTLSharedEvent_id"}
                           .contains(m.baseType)) {
                return "{}";
            }
            assert(false);
            return "{}";
        } else if (m.trailing.starts_with(":")) {
            return "0";
        } else if (m.trailing.starts_with("[")) {
            if (m.baseType == "char") {
                return "\"\"";

                // } else if (m.baseType == "uint8_t" || m.baseType == "uint32_t" ||
                //            m.baseType == "int32_t" || m.baseType == "float" ||
                //            m.baseType == "VkDeviceSize") {
                //     return "{}";
                // } else if (allStructs.contains(m.baseType)) {
                //     return "{}";
            } else if (enumAlias.contains(m.baseType)) {
                const std::string &realEnum = enumAlias.at(m.baseType);
                if (allEnums.contains(realEnum.substr(2))) {
                    return "{" + enumZeroElements.at(realEnum) + "}";
                } else {
                    assert(allEnumFlags.contains(realEnum.substr(2)));
                    return "{}";
                }
            } else if (allEnums.contains(m.baseType.substr(2))) {
                return "{" + enumZeroElements.at(m.baseType) + "}";
            }
            return "{}";
            // } else if (allEnumFlags.contains(m.baseType.substr(2))) {
            //     return "{}";
            // } else if (m.baseType.starts_with("AssignableHandle")) {
            //     return "{}";
            // }
            // std::cout << s.originalName << ": " << m.fullType() << m.name <<
            // m.postArgumentPrint()
            //           << "\n"
            //           << std::flush;
            // assert(false);
            // return "";
        } else if (m.postType.contains("*")) {
            return "nullptr";
        }
        assert(false);
        return "{}";
    };

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
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
        s.name = s.originalName.substr(2);
        std::vector<StructInfo::Member> members;
        ForEach(type, "member", [&](XMLElement &member) {
            if (HasAttribute(member, "api") &&
                !splitCSL(Attribute(member, "api")).contains("vulkan"))
                return;
            StructInfo::Member m;
            m = parseTypeAndName(member);
            prerequisits[s.originalName].insert(m.baseType);
            if (!HasAttribute(member, "len") && handles.contains(m.baseType)) {
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
                m.baseType = "AssignableHandle<" + m.baseType.substr(2) + ">";
            }
            if (HasAttribute(member, "len") && handles.contains(m.baseType) &&
                m.trailing.starts_with("[")) {
                m.baseType = "AssignableHandle<" + m.baseType.substr(2) + ">";
            }
            if (m.trailing.starts_with("[") &&
                constantMapping.contains(m.trailing.substr(1, m.trailing.size() - 2))) {
                m.trailing = "[Constants::" +
                             constantMapping.at(m.trailing.substr(1, m.trailing.size() - 2)) + "]";
            }
            m.value = generateZeroValue(s, m);
            members.emplace_back(std::move(m));
        });
        s.members = std::move(members);
        infos[s.originalName] = std::move(s);
    });
    ForEach(types, "type", [&](XMLElement &type) {
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
        s.name = s.originalName.substr(2);
        std::vector<StructInfo::Member> members;
        ForEach(type, "member", [&](XMLElement &member) {
            if (HasAttribute(member, "api") &&
                !splitCSL(Attribute(member, "api")).contains("vulkan"))
                return;
            StructInfo::Member m;
            m = parseTypeAndName(member);
            prerequisits[s.originalName].insert(m.baseType);
            members.emplace_back(std::move(m));
        });
        s.members = std::move(members);
        infos[s.originalName] = std::move(s);
    });

    std::ranges::for_each(prerequisits, [&](auto &pair) { // remove reflecifity
        std::erase_if(pair.second, [&](const std::string &s) { return s == pair.first; });
    });

    std::unordered_set<std::string> toRemove; // Roots of the dependency tree
    std::unordered_map<std::string, int> rank;
    int currentRank = 0;

    std::unordered_set<std::string> roots;
    for (const auto &[_, pre] : prerequisits) {
        toRemove.insert_range(pre);
    }
    for (const auto &[name, _] : prerequisits) {
        toRemove.erase(name);
    }

    while (!toRemove.empty()) {

        for (const auto &key : toRemove) {
            rank[key] = currentRank;
        }
        currentRank += 1;

        std::ranges::for_each(prerequisits, [&](auto &pair) {
            std::erase_if(pair.second, [&](const std::string &s) { return toRemove.contains(s); });
        });
        toRemove.clear();

        for (const auto &[name, pre] : prerequisits) {
            if (pre.empty())
                toRemove.insert(name);
        }
        std::erase_if(prerequisits, [&](const auto &pair) { return pair.second.empty(); });
    }
    assert(prerequisits.empty());

    const auto &typeDepends = parseObjectDepents(registry, "type");
    const auto &typeDisabled = parseObjectsDisabled(registry, "type");

    for (const auto &[_, info] : infos) {
        assert(rank.contains(info.originalName));
        if (typeDisabled.contains(info.originalName))
            continue;
        StructInfo si = info;
        si.rank = rank.at(info.originalName);
        if (auto it = typeDepends.find(info.originalName); it != typeDepends.end()) {
            si.depends = it->second;
        }
        structInfos.emplace(std::move(si));
    }

    return structInfos;
}
