#include "BaseTypeInfo.hpp"
#include "CppGenerator.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"
#include "XmlUtils.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <format>
#include <set>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace tinyxml2;

[[nodiscard]] auto BaseTypeInfo::getDepends() const -> const Depends & { return depends; }

[[nodiscard]] auto BaseTypeInfo::getName() const -> const std::string & { return name; }

auto BaseTypeInfo::operator<(const BaseTypeInfo &other) const -> bool {
    return std::tie(depends, name) < std::tie(other.depends, other.name);
}

void BaseTypeInfo::write(CppGenerator &gen) const {
    static constinit const std::string_view prefix = "typedef ";
    static constinit const std::string_view suffix = ";";
    if (code.starts_with(prefix) && code.ends_with(suffix)) {
        std::string_view codeView = code;
        codeView.remove_prefix(prefix.size());
        codeView.remove_suffix(suffix.size());

        const size_t lastSpace = codeView.find_last_of(' ');
        assert(lastSpace != std::string::npos);
        std::string_view typePart = codeView.substr(0, lastSpace);
        std::string_view aliasPart = codeView.substr(lastSpace + 1);

        gen.doCode(std::format("using {} = {};", aliasPart, typePart));
        return;
    }
    gen.doCode(code);
}

auto BaseTypeInfo::getBaseTypeMapping(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> mapping;
    if (!mapping.empty()) {
        return mapping;
    }

    const auto &baseTypeInfos = parseBaseTypeInfo(registry);
    for (const auto &baseTypeInfo : baseTypeInfos) {
        mapping[baseTypeInfo.originalName] = baseTypeInfo.name;
    }

    return mapping;
}

auto BaseTypeInfo::getIntTypedefs(Registry registry) -> const std::unordered_set<std::string> & {
    static std::unordered_set<std::string> types;
    const auto &baseTypeInfos = parseBaseTypeInfo(registry);
    std::array intTypes = {"uint32_t", "uint64_t"};
    for (const auto &info : baseTypeInfos) {
        if (std::ranges::any_of(intTypes, [&](const std::string &intType) -> bool {
                return info.code.contains(intType);
            })) {
            types.insert(info.name);
        }
    }
    return types;
}

namespace {

auto stripVkPrefix(std::string name) -> std::string {
    if (name.starts_with("Vk")) {
        return name.substr(2);
    }
    return name;
}

auto appendTokenWithSpacing(std::string &out, const char *text) -> void {
    if (((*text) == 0) || (text == nullptr)) {
        return;
    }
    if (!out.empty() && (std::isspace(static_cast<unsigned char>(out.back())) == 0)) {
        out.push_back(' ');
    }
    out += text;
}

auto buildBaseTypeCode(XMLElement &type, const std::string &strippedName) -> std::string {
    const XMLElement &nameElement = *type.FirstChildElement("name");
    std::string code;
    for (XMLNode *node = type.FirstChild(); node != nullptr; node = node->NextSibling()) {
        if (const XMLText *txt = node->ToText()) {
            const char *val = txt->Value();
            if (val != nullptr && *val != '\0') {
                code += val; // preserve raw text spacing
            }
            continue;
        }

        if (const XMLElement *element = node->ToElement()) {
            const char *text =
                (element == &nameElement) ? strippedName.c_str() : element->GetText();
            appendTokenWithSpacing(code, text);
        }
    }
    return code;
}

auto shouldSkipBaseType(XMLElement &type, const std::unordered_set<std::string> &objectsDisabled)
    -> bool {
    if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"basetype"})) {
        return true;
    }
    if (!checkApi(type)) {
        return true;
    }

    const XMLElement *name = type.FirstChildElement("name");
    if (name == nullptr || name->GetText() == nullptr) {
        return true;
    }

    return objectsDisabled.contains(name->GetText());
}

} // namespace

auto BaseTypeInfo::makeBaseTypeInfo(XMLElement &type,
                                    const std::unordered_map<std::string, Depends> &objectDepends)
    -> BaseTypeInfo {
    BaseTypeInfo info;
    info.originalName = FirstChildElement(type, "name").GetText();
    assert(!info.originalName.empty());
    info.name = stripVkPrefix(info.originalName);
    info.code = buildBaseTypeCode(type, info.name);

    if (auto iter = objectDepends.find(info.originalName); iter != objectDepends.end()) {
        info.depends = iter->second;
    }

    return info;
}

auto BaseTypeInfo::parseBaseTypeInfo(Registry registry) -> const std::set<BaseTypeInfo> & {
    static std::set<BaseTypeInfo> infos;
    if (!infos.empty()) {
        return infos;
    }

    const auto objectsDisabled = parseObjectsDisabled(registry, "type");
    const auto &objectDepends = parseObjectDepents(registry, "type");

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (shouldSkipBaseType(type, objectsDisabled)) {
            return;
        }
        infos.insert(makeBaseTypeInfo(type, objectDepends));
    });
    return infos;
}
