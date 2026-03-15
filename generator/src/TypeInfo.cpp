#include "TypeInfo.hpp"

#include "ParseXml.hpp"

using namespace tinyxml2;

bool TypeInfo::operator<(const TypeInfo &other) const {
    return std::tie(depends, name) < std::tie(other.depends, other.name);
}

void TypeInfo::writeSpecialisation(CppGenerator &gen, const TypeInfo &ti) {
    gen.doWriteLine("template <> struct StructureType<" + ti.name + "> { " +
                    "static const constexpr VkStructureType t = " + ti.structureType + ";" + " };");
    gen.doWriteLine("template " + ti.name + " Init<" + ti.name + ">();");
}

const std::set<TypeInfo> &parseTypeInfos(XMLElement &registry) {
    static std::set<TypeInfo> typeInfos;
    if (!typeInfos.empty())
        return typeInfos;

    const std::unordered_map<std::string, std::string> &typeStructureName =
        parseTypeStructureName(registry);

    const std::unordered_map<std::string, Depends> &typeDepends =
        parseObjectDepents(registry, "type");

    const std::unordered_set<std::string> &objectsDisabled = parseObjectsDisabled(registry, "type");

    auto CreateTypeInfo = [&](std::string name) {
        TypeInfo info;
        info.name = name;
        info.structureType = typeStructureName.at(name);
        if (auto it = typeDepends.find(name); it != typeDepends.end()) {
            info.depends = it->second;
        }
        return info;
    };
    for (const auto &[name, _] : typeStructureName) {
        if (objectsDisabled.contains(name))
            continue;
        typeInfos.emplace(CreateTypeInfo(name));
    }
    return typeInfos;
}
