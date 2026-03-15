#include "StructInfo.hpp"

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
