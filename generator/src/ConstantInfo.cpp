#include "ConstantInfo.hpp"

bool ConstantInfo::operator<(const ConstantInfo &other) const {
    return std::tie(depends, name, type, value) <
           std::tie(other.depends, other.name, other.type, other.value);
}
void ConstantInfo::writeHeader(CppGenerator &gen, const ConstantInfo &info) {
    gen.doWriteLine("extern const constinit " + info.type + " " + info.name + ";");
}

void ConstantInfo::writeImpl(CppGenerator &gen, const ConstantInfo &info) {
    gen.doWriteLine("const constinit " + info.type + " " + info.name + " = " + info.value + ";");
}
