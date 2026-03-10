#include "TypeInfo.hpp"

bool TypeInfo::operator<(const TypeInfo &other) const {
    return std::tie(depends.m_namespace, depends.platform, depends.feature, depends.extensions,
                    name) < std::tie(other.depends.m_namespace, other.depends.platform,
                                     other.depends.feature, other.depends.extensions, other.name);
}

void TypeInfo::header(CppGenerator &gen, const TypeInfo &ti) {
    gen.doWriteLine("template <> struct StructureType<" + ti.name + "> { " +
                    "static const constexpr VkStructureType t = " + ti.structureType + ";" + " };");
    gen.doWriteLine("template " + ti.name + " Init<" + ti.name + ">();");
}
