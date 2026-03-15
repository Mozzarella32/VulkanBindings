#include "StructInfo.hpp"
#include "ParseXml.hpp"
#include "XmlUtils.hpp"

#include <algorithm>
#include <ranges>

using namespace tinyxml2;

std::unordered_map<std::string, std::string> StructInfo::enumAlias = {};

bool StructInfo::operator<(const StructInfo &other) const {
    return std::tie(rank, depends, name) < std::tie(other.rank, other.depends, other.name);
}

void StructInfo::writeHeader(CppGenerator &gen, const StructInfo &si) {
    if (si.isUnion) {
        gen.doBeginUnion(si.name);
    } else {
        gen.doBeginStruct(si.name);
    }
    for (auto m : si.members) {
        if (auto it = enumAlias.find(m.baseType); it != enumAlias.end()) {
            m.baseType = it->second;
        }
        if (m.baseType.starts_with("Vk")) {
            m.baseType = m.baseType.substr(2, m.baseType.size() - 2);
            static const std::string FlagBits = "FlagBits";
            static const std::string Flags = "Flags";
            if (auto it = m.baseType.find(FlagBits); it != std::string::npos) {
                m.baseType.erase(it, FlagBits.size());
                m.baseType.insert(it, Flags);
            }
        }
        gen.doWriteLine(m.fullType() + m.name + m.postArgumentPrint() + ";");
    }
    if (si.isUnion) {
        gen.doEndUnion();
    } else {
        gen.doEndStruct();
    }
}

void StructInfo::writeAssert(CppGenerator &gen, const StructInfo &si) {
    gen.doWriteLine("// " + si.name);
}

const std::set<StructInfo> &parseStructInfos(XMLElement &registry) {
    static std::set<StructInfo> structInfos;
    if (!structInfos.empty())
        return structInfos;

    std::unordered_map<std::string, StructInfo> infos;
    std::unordered_map<std::string, std::unordered_set<std::string>> prerequisits;

    const auto &handles = parseHandles(registry);

    StructInfo::enumAlias = parseEnumAlias(registry);

    XMLElement &types = FirstChildElement(registry, "types");
    ForEach(types, "type", [&](XMLElement &type) {
        if (HasAttributeValue(type, "category", "struct") && !HasAttribute(type, "alias")) {
            assert(HasAttribute(type, "name"));
            StructInfo s;
            s.isUnion = false;
            s.originalName = Attribute(type, "name");
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
                members.emplace_back(std::move(m));
            });
            s.members = std::move(members);
            infos[s.originalName] = std::move(s);
        }
    });
    ForEach(types, "type", [&](XMLElement &type) {
        if (HasAttributeValue(type, "category", "union") && !HasAttribute(type, "alias")) {
            assert(HasAttribute(type, "name"));
            StructInfo s;
            s.isUnion = true;
            s.originalName = Attribute(type, "name");
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
        }
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
