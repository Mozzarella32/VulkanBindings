#include "EnumInfo.hpp"

#include "Writing.hpp"
#include <sstream>
#include <utility>

bool EnumElementInfo::operator<(const EnumElementInfo &other) const { return value < other.value; }

void EnumElementInfo::writeAssert(CppGenerator &gen, const EnumElementInfo &eei,
                                  const std::string &enumName, bool size64) {
    std::string type = size64 ? "int64_t" : "int32_t";
    gen.doWriteLine("static_assert(static_cast<" + type + ">(VkBindings::" + enumName +
                    "::" + eei.name + ") == " + eei.originalName + ");");
}

void EnumElementInfo::writeHeader(CppGenerator &gen, const EnumElementInfo &eei, int longestName,
                                  bool size64) {
    std::stringstream s;
    s << std::left << std::setw(longestName) << eei.name << " = ";

    const int hexDigits = size64 ? 16 : 8;

    int64_t abs = std::abs(eei.value);
    if(eei.value < 0) {
        s << "-";
    }
    s << "0x" << std::right << std::hex << std::setw(hexDigits) << std::setfill('0') << abs;

    s << ",";
    if (!eei.comment.empty())
        s << " // " << eei.comment;
    gen.doWriteLine(s);
}

bool EnumInfo::operator<(const EnumInfo &other) const {
    return std::tie(depends, name) < std::tie(other.depends, other.name);
}

void EnumInfo::writeHeader(CppGenerator &gen, const EnumInfo &ei) {
    const std::string bitwidth = ei.bitwidth == Bitwidth::BW32 ? "32" : "64";
    const std::string type = ei.type == Type::Enum ? "Enum" : "Bitmask";
    const std::string baseType = ei.bitwidth == Bitwidth::BW32 ? "int32_t" : "int64_t";
    gen.doLineBeginScope("enum class " + ei.name + ei.extensions + " : " + baseType,
                         bitwidth + " " + type);
    int longestName = 0;
    for (const auto &element : ei.elements) {
        longestName = std::max(longestName, static_cast<int>(element.name.size()));
    }
    writeDepends(
        gen, ei.elements,
        std::bind_back(EnumElementInfo::writeHeader, longestName, ei.bitwidth == Bitwidth::BW64));
    gen.endScope(true);
}

void EnumInfo::writeAssert(CppGenerator &gen, const EnumInfo &ei) {
    writeDepends(gen, ei.elements,
                 std::bind_back(EnumElementInfo::writeAssert, ei.name + ei.extensions,
                                ei.bitwidth == Bitwidth::BW64));
}
