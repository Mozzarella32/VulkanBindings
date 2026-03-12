#include "TypeInfo.hpp"

bool TypeInfo::operator<(const TypeInfo &other) const {
    return std::tie(depends, name) < std::tie(other.depends, other.name);
}

void TypeInfo::writeSpecialisation(CppGenerator &gen, const TypeInfo &ti) {
    gen.doWriteLine("template <> struct StructureType<" + ti.name + "> { " +
                    "static const constexpr VkStructureType t = " + ti.structureType + ";" + " };");
    gen.doWriteLine("template " + ti.name + " Init<" + ti.name + ">();");
}
