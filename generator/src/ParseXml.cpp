#include "ParseXml.hpp"
#include "CppGenerator.hpp"
#include "Depens.hpp"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstddef>
#include <functional>
#include <ranges>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "Registry.hpp"
#include "XmlUtils.hpp"

using namespace tinyxml2;

auto parseHandles(Registry registry) -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> handles;
    if (!handles.empty())
        return handles;

    XMLElement &types = FirstChildElement(registry.getVk(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"handle"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        const std::string name = FirstChildElement(type, "name").GetText();
        if (HasAttribute(type, "parent")) {
            handles[name] = Attribute(type, "parent");
        } else {
            handles[name] = "";
        }
    });
    return handles;
}

auto parseDispatchableHandles(Registry registry) -> const std::unordered_set<std::string> & {
    static std::unordered_set<std::string> dispatchableHandles;
    if (!dispatchableHandles.empty())
        return dispatchableHandles;
    XMLElement &types = FirstChildElement(registry.getVk(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"handle"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        if (FirstChildElement(type, "type").GetText() != std::string_view{"VK_DEFINE_HANDLE"})
            return;
        const std::string name = FirstChildElement(type, "name").GetText();
        dispatchableHandles.insert(name);
    });
    return dispatchableHandles;
}

auto parseObjectType(Registry registry) -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regObjectTypes;
    auto &objectTypes = regObjectTypes[&registry.getActive()];
    if (!objectTypes.empty())
        return objectTypes;
    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"handle"}))
            return;
        if (HasAttribute(type, "alias"))
            return;
        const std::string name = FirstChildElement(type, "name").GetText();
        assert(HasAttribute(type, "objtypeenum"));
        objectTypes[name] = Attribute(type, "objtypeenum");
    });
    return objectTypes;
}

auto parseTypeAndName(XMLElement &param) -> TypeAndName {
    std::string name;
    std::string baseType;
    std::string leading;
    std::string postType;
    std::string trailing;
    std::string commentText;

    int parsingPhase = 0; // 0 = before <type>, 1 = after <type> before <name>, 2 = after <name>
    for (const XMLNode *node = param.FirstChild(); node != nullptr; node = node->NextSibling()) {
        if (const XMLText *textNode = node->ToText()) {
            const char *rawText = textNode->Value();
            const std::string text = (rawText != nullptr) ? rawText : "";

            if (parsingPhase == 0) {
                leading += text;
            } else if (parsingPhase == 1) {
                postType += text;
            } else {
                trailing += text;
            }
        } else if (const XMLElement *element = node->ToElement()) {
            const std::string_view elementTag = element->Name();

            if (elementTag == "type") {
                parsingPhase = 1;
                if (const char *typeText = element->GetText()) {
                    baseType += typeText;
                }
            } else if (elementTag == "name") {
                parsingPhase = 2;
                if (const char *nameText = element->GetText()) {
                    name += nameText;
                }
            } else if (elementTag == "comment") {
                if (const char *commentNodeText = element->GetText()) {
                    commentText += commentNodeText;
                }
            } else {
                if (const char *unknownElementText = element->GetText()) {
                    if (parsingPhase == 0) {
                        leading += unknownElementText;
                    } else if (parsingPhase == 1) {
                        postType += unknownElementText;
                    } else {
                        trailing += unknownElementText;
                    }
                }
            }
        } else if (const XMLComment *commentNode = node->ToComment()) {
            (void)commentNode;
        }
    }

    return TypeAndName(trim_copy(name), trim_copy(baseType), trim_copy(leading),
                       trim_copy(postType), trim_copy(trailing));
}

namespace {
auto parseNotInternalFeatureNames(Registry registry) -> const std::unordered_set<std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_set<std::string>>
        regNotInternelFeatureNames;
    auto &notInternelFeatureNames = regNotInternelFeatureNames[&registry.getActive()];
    if (!notInternelFeatureNames.empty())
        return notInternelFeatureNames;
    ForEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, AttributeName{"apitype"}, AttributeValue{"internal"}))
            return;
        notInternelFeatureNames.insert(Attribute(feature, "name"));
    });
    return notInternelFeatureNames;
}

auto parsePlatformMacros(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<std::string, std::string> platformMakros;
    if (!platformMakros.empty())
        return platformMakros;
    XMLElement &platforms = FirstChildElement(registry.getVk(), "platforms");
    ForEach(platforms, "platform", [&](XMLElement &platform) -> void {
        if (!HasAttribute(platform, "name"))
            return;
        if (!HasAttribute(platform, "protect"))
            return;
        platformMakros[Attribute(platform, "name")] = Attribute(platform, "protect");
    });
    return platformMakros;
}

struct ComposeGuardArgs {
    std::string_view extension;
    std::string_view depends;
};

auto composeGuard(ComposeGuardArgs args, Registry registry) -> std::string {
    const std::unordered_set<std::string> &notInternalFeatureNames =
        parseNotInternalFeatureNames(registry);

    std::unordered_set<std::string> allFeatureNames;
    ForEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
        if (!HasAttribute(feature, "name"))
            return;
        if (!checkApi(feature))
            return;
        allFeatureNames.insert(Attribute(feature, "name"));
    });

    std::unordered_set<std::string> internalFeatureNames;
    for (const auto &featureName : allFeatureNames) {
        if (!notInternalFeatureNames.contains(featureName))
            internalFeatureNames.insert(featureName);
    }

    std::vector<std::string> tokens;

    size_t index = 0;
    auto isAtomCharacter = [](char character) -> bool {
        return std::isalnum(static_cast<unsigned char>(character)) || character == '_' ||
               character == ':';
    };

    while (index < args.depends.size()) {
        const char currentCharacter = args.depends.at(index);

        if (std::isspace(static_cast<unsigned char>(currentCharacter)) != 0) {
            ++index;
            continue;
        }

        if (currentCharacter == '(' || currentCharacter == ')') {
            tokens.emplace_back(1, currentCharacter);
            ++index;
            continue;
        }

        if (currentCharacter == '+' || currentCharacter == '&' || currentCharacter == ',' ||
            currentCharacter == '|') {
            tokens.emplace_back(1, currentCharacter);
            ++index;
            continue;
        }

        // atom
        const size_t atomStart = index;
        while (index < args.depends.size() && isAtomCharacter(args.depends.at(index)))
            ++index;

        tokens.emplace_back(args.depends.substr(atomStart, index - atomStart));
    }

    auto isAndOperatorToken = [](const std::string &token) -> bool {
        return token.size() == 1 && (token.at(0) == '+' || token.at(0) == '&');
    };
    auto isOrOperatorToken = [](const std::string &token) -> bool {
        return token.size() == 1 && (token.at(0) == ',' || token.at(0) == '|');
    };

    std::string output;

    auto appendTokenWithSpace = [&](const std::string &token) -> void {
        if (!output.empty())
            output += ' ';
        output += token;
    };

    auto nextMeaningfulTokenIndex = [&](size_t startIndex) -> size_t {
        for (size_t tokenIndex = startIndex; tokenIndex < tokens.size(); ++tokenIndex) {
            const auto &token = tokens.at(tokenIndex);
            if (token.empty())
                continue;

            if (token == "(" || token == ")")
                return tokenIndex;

            if (isAndOperatorToken(token) || isOrOperatorToken(token))
                continue;

            if (token.contains("::"))
                continue;

            if (internalFeatureNames.contains(token))
                continue;

            return tokenIndex;
        }
        return tokens.size();
    };

    bool previousWasAtom = false;
    for (size_t tokenIndex = 0; tokenIndex < tokens.size(); ++tokenIndex) {
        const std::string &token = tokens.at(tokenIndex);
        if (token.empty())
            continue;

        if (token == "(") {
            const size_t nextTokenIndex = nextMeaningfulTokenIndex(tokenIndex + 1);
            if (nextTokenIndex < tokens.size()) {
                appendTokenWithSpace("(");
                previousWasAtom = false;
            }
            continue;
        }

        if (token == ")") {
            if (previousWasAtom) {
                appendTokenWithSpace(")");
                previousWasAtom = true;
            }
            continue;
        }

        if (isAndOperatorToken(token) || isOrOperatorToken(token)) {
            const std::string mappedOperator = isAndOperatorToken(token) ? "&&" : "||";
            const size_t nextTokenIndex = nextMeaningfulTokenIndex(tokenIndex + 1);
            if (previousWasAtom && nextTokenIndex < tokens.size()) {
                appendTokenWithSpace(mappedOperator);
                previousWasAtom = false;
            }
            continue;
        }

        if (token.contains("::")) {
            continue;
        }

        if (internalFeatureNames.contains(token)) {
            continue;
        }

        const std::string definition = std::string("defined(") + token + ")";
        appendTokenWithSpace(definition);
        previousWasAtom = true;
    }

    auto trimInPlace = [](std::string &str) -> void {
        size_t start = 0;
        while (start < str.size() && std::isspace(static_cast<unsigned char>(str.at(start))))
            ++start;

        size_t end = str.size();
        while (end > start && std::isspace(static_cast<unsigned char>(str.at(end - 1))))
            --end;

        if (start == 0 && end == str.size())
            return;

        str = str.substr(start, end - start);
    };

    trimInPlace(output);

    std::string extensionCondition;
    if (!args.extension.empty()) {
        extensionCondition = "defined(" + std::string(args.extension) + ")";
    }

    if (extensionCondition.empty() && output.empty())
        return {};

    if (!extensionCondition.empty() && output.empty())
        return extensionCondition;

    if (extensionCondition.empty() && !output.empty())
        return output;

    return "(" + extensionCondition + " && (" + output + "))";
}
} // namespace

// string_view to prevent dangling refrence, when passing a string literal
auto parseObjectDepents(Registry registry, std::string_view objectSV)
    -> const std::unordered_map<std::string, Depends> & {

    static std::unordered_map<
        XMLElement *, std::unordered_map<std::string, std::unordered_map<std::string, Depends>>>
        regAllObjectDepends;
    auto &allObjectDepends = regAllObjectDepends[&registry.getActive()];
    std::string object{objectSV};
    std::unordered_map<std::string, Depends> &objectDepends = allObjectDepends[object];
    if (!objectDepends.empty())
        return objectDepends;

    ForEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttributeValue(feature, AttributeName{"apitype"}, AttributeValue{"internal"}))
            return;
        if (!checkApi(feature))
            return;
        std::string featureName = Attribute(feature, "name");
        ForEach(feature, "require", [&](XMLElement &require) -> void {
            if (!checkApi(require))
                return;
            ForEach(require, object, [&](XMLElement &type) -> void {
                if (!HasAttribute(type, "name"))
                    return;
                const std::string typeName = Attribute(type, "name");
                auto &objDepends = objectDepends[typeName];
                const std::string featureGuard =
                    composeGuard({.extension = std::string(), .depends = featureName}, registry);
                if (featureGuard.empty())
                    return;
                if (!objDepends.guard.empty()) {
                    objDepends.guard = objDepends.guard + " || " + featureGuard;
                } else {
                    objDepends.guard = featureGuard;
                }
            });
        });
    });

    const std::unordered_map<std::string, std::string> &platformMakros =
        parsePlatformMacros(registry);

    XMLElement &extensions = FirstChildElement(registry.getActive(), "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        ForEach(extension, "require", [&](XMLElement &require) -> void {
            if (!checkApi(require))
                return;
            std::string depends;
            if (HasAttribute(require, "depends")) {
                depends = Attribute(require, "depends");
            }
            ForEach(require, object, [&](XMLElement &type) -> void {
                if (!HasAttribute(type, "name"))
                    return;
                auto &objDepends = objectDepends[Attribute(type, "name")];
                std::string platformMacro;

                if (HasAttribute(type, "protect")) {
                    platformMacro = Attribute(type, "protect");
                } else if (HasAttribute(extension, "platform")) {
                    const std::string platform = Attribute(extension, "platform");
                    platformMacro = platformMakros.at(platform);
                }

                if (!platformMacro.empty()) {
                    assert(objDepends.platform.empty() || objDepends.platform == platformMacro);
                    objDepends.platform = platformMacro;
                }
            });
        });
    });

    return objectDepends;
}

// string_view to prevent dangling refrence, when passing a string literal
auto parseObjectsDisabled(Registry registry, std::string_view objectSV)
    -> const std::unordered_set<std::string> & {

    static std::unordered_map<XMLElement *,
                              std::unordered_map<std::string, std::unordered_set<std::string>>>
        regAllObjectsDisabled;
    auto &allObjectsDisabled = regAllObjectsDisabled[&registry.getActive()];
    std::string object{objectSV};
    std::unordered_set<std::string> &objectsDisabled = allObjectsDisabled[object];
    if (!objectsDisabled.empty())
        return objectsDisabled;

    XMLElement &extensions = FirstChildElement(registry.getActive(), "extensions");
    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        const bool extensionUnsupported =
            HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan");
        ForEach(extension, "require", [&](XMLElement &require) -> void {
            const bool apiUnsupported = HasAttribute(require, "api") &&
                                        !splitCSL(Attribute(require, "api")).contains("vulkan");
            if (!extensionUnsupported && !apiUnsupported)
                return;
            ForEach(require, object, [&](XMLElement &type) -> void {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.insert(Attribute(type, "name"));
            });
        });
    });

    ForEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
        if (!HasAttribute(feature, "name"))
            return;
        bool featureUnsupported =
            HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan");

        ForEach(feature, "require", [&](XMLElement &require) -> void {
            const bool apiUnsupported = HasAttribute(require, "api") &&
                                        !splitCSL(Attribute(require, "api")).contains("vulkan");
            if (!featureUnsupported && !apiUnsupported)
                return;
            ForEach(require, object, [&](XMLElement &type) -> void {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.insert(Attribute(type, "name"));
            });
        });
    });

    ForEach(extensions, "extension", [&](XMLElement &extension) -> void {
        assert(HasAttribute(extension, "name"));
        if (HasAttribute(extension, "supported") &&
            !splitCSL(Attribute(extension, "supported")).contains("vulkan"))
            return;
        ForEach(extension, "require", [&](XMLElement &require) -> void {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, object, [&](XMLElement &type) -> void {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.erase(Attribute(type, "name"));
            });
        });
    });

    ForEach(registry.getActive(), "feature", [&](XMLElement &feature) -> void {
        if (!HasAttribute(feature, "name"))
            return;
        if (HasAttribute(feature, "api") && !splitCSL(Attribute(feature, "api")).contains("vulkan"))
            return;

        ForEach(feature, "require", [&](XMLElement &require) -> void {
            if (HasAttribute(require, "api") &&
                !splitCSL(Attribute(require, "api")).contains("vulkan"))
                return;
            ForEach(require, object, [&](XMLElement &type) -> void {
                if (!HasAttribute(type, "name"))
                    return;
                objectsDisabled.erase(Attribute(type, "name"));
            });
        });
    });

    return objectsDisabled;
}

auto parseTypeStructureName(Registry registry)
    -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regTypeStructureName;
    auto &typeStructureName = regTypeStructureName[&registry.getActive()];
    if (!typeStructureName.empty())
        return typeStructureName;

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"struct"}))
            return;
        if (!HasAttribute(type, "name"))
            return;
        const std::string name = Attribute(type, "name");
        std::string structureType;
        ForEachBreak(type, "member", [&](XMLElement &member) -> bool {
            bool hasStructureType = false;
            ForEachBreak(member, "type", [&](XMLElement &memberType) -> bool {
                if (HasText(memberType, "VkStructureType")) {
                    hasStructureType = true;
                    if (!HasAttribute(member, "values"))
                        return false;
                    structureType = Attribute(member, "values");
                }
                return false;
            });
            return hasStructureType;
        });
        if (!structureType.empty()) {
            typeStructureName[name] = std::move(structureType);
        }
    });
    return typeStructureName;
}

auto parseVendorTags(Registry registry) -> std::unordered_set<std::string> {
    static std::unordered_set<std::string> vendorTags;

    XMLElement &tags = FirstChildElement(registry.getVk(), "tags");
    ForEach(tags, "tag", [&](XMLElement &tag) -> void {
        assert(HasAttribute(tag, "name"));
        vendorTags.insert(Attribute(tag, "name"));
    });
    return vendorTags;
}

auto screamingSnakeCaseToPascalCase(const std::string &name,
                                    const std::unordered_set<std::string> &vendorTags)
    -> std::string {
    std::string out;
    out.reserve(name.size());

    static const std::unordered_set<std::string> ignorList = {"AV1"};

    for (auto token_range : name | std::views::split('_')) {
        std::string token(token_range.begin(), token_range.end());
        if (token.empty())
            continue;

        // Preserve vendor tags and ignored tokens exactly as they appear in the XML.
        if (vendorTags.contains(token)) {
            out += token;
            continue;
        }
        if (ignorList.contains(token)) {
            out += token;
            continue;
        }

        // Split the token into contiguous alpha or digit segments.
        std::vector<std::string> segments;
        segments.reserve(4);
        size_t i = 0;
        while (i < token.size()) {
            size_t j = i;
            if (std::isdigit(token.at(j)) != 0) {
                while (j < token.size() &&
                       (std::isdigit(static_cast<unsigned char>(token.at(j))) != 0))
                    ++j;
            } else if (std::isalpha(static_cast<unsigned char>(token.at(j))) != 0) {
                while (j < token.size() &&
                       (std::isalpha(static_cast<unsigned char>(token.at(j))) != 0))
                    ++j;
            } else {
                // treat any other single char as its own segment
                ++j;
            }
            segments.emplace_back(token.substr(i, j - i));
            i = j;
        }

        for (const auto &seg : segments) {
            const bool segHasDigit = std::ranges::any_of(
                seg, [](unsigned char character) -> int { return std::isdigit(character); });
            const bool segAllAlpha = std::ranges::all_of(
                seg, [](unsigned char character) -> int { return std::isalpha(character); });

            if (segHasDigit) {
                // Numeric groups (e.g., "4", "10") are appended as-is.
                out += seg;
                continue;
            }

            if (segAllAlpha) {
                if (seg.size() == 1) {
                    // Single-letter tokens: channel letters (R/G/B/A) -> uppercase.
                    const char character = seg.at(0);
                    if (character == 'x' || character == 'X') {
                        out.push_back('x'); // keep lowercase x for "4x4"
                    } else {
                        out.push_back(
                            static_cast<char>(std::toupper(static_cast<unsigned char>(character))));
                    }
                    continue;
                }

                // Multi-letter alpha groups: convert to PascalCase (e.g. ACCELERATION ->
                // Acceleration, UNORM -> Unorm, SRGB -> Srgb). This avoids concatenated all-caps
                // results.
                std::string lower = seg;
                std::ranges::transform(lower, lower.begin(), [](unsigned char character) -> char {
                    return static_cast<char>(std::tolower(character));
                });
                lower.at(0) =
                    static_cast<char>(std::toupper(static_cast<unsigned char>(lower.at(0))));
                out += lower;
                continue;
            }

            // Fallback: append as-is.
            out += seg;
        }
    }

    return out;
}

auto parseAlias(Registry registry) -> const std::unordered_map<std::string, std::string> & {
    static std::unordered_map<XMLElement *, std::unordered_map<std::string, std::string>>
        regEnumAlias;
    auto &alias = regEnumAlias[&registry.getActive()];
    if (!alias.empty())
        return alias;

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttribute(type, "alias"))
            return;
        assert(HasAttribute(type, "name"));
        alias[Attribute(type, "name")] = Attribute(type, "alias");
    });
    return alias;
}

auto parseDefines(Registry registry) -> const std::string & {
    static std::unordered_map<XMLElement *, std::string> regRet;
    auto &ret = regRet[&registry.getActive()];
    if (!ret.empty())
        return ret;
    std::stringstream buffer;

    XMLElement &types = FirstChildElement(registry.getActive(), "types");
    ForEach(types, "type", [&](XMLElement &type) -> void {
        if (!HasAttributeValue(type, AttributeName{"category"}, AttributeValue{"define"}))
            return;
        if (!checkApi(type))
            return;
        if (type.FirstChildElement("name") == nullptr) {
            buffer << type.GetText() << "\n";
            return;
        }
        XMLElement &name = FirstChildElement(type, "name");
        buffer << "#define " << name.GetText();
        XMLNode *node = name.NextSibling();
        bool first = true;
        while (node) {
            if (const XMLText *txt = node->ToText()) {
                const char *val = txt->Value();
                if (val && *val) {
                    if (first && std::string_view{val}.at(0) != '(') {
                        first = false;
                        buffer << " ";
                    }
                    buffer << val;
                }
            } else if (const XMLElement *element = node->ToElement()) {
                if (const char *text = element->GetText()) {
                    if (first && std::string_view{text}.at(0) != '(') {
                        first = false;
                        buffer << " ";
                    }
                    buffer << text;
                }
            }
            node = node->NextSibling();
        }
        buffer << "\n";
    });
    ret = buffer.str();
    std::string replace = "VK_";
    for (auto pos = ret.find(replace); pos != std::string::npos; pos = ret.find(replace, pos)) {
        pos += replace.size();
        ret.insert(pos, "BINDINGS_");
    }
    replace = "VKSC_";
    for (auto pos = ret.find(replace); pos != std::string::npos; pos = ret.find(replace, pos)) {
        pos += replace.size();
        ret.insert(pos, "BINDINGS_");
    }
    replace = "#define VK_BINDINGS_NULL_HANDLE";
    return ret;
}

auto parseCodecEnumIncludes(Registry registry) -> std::set<std::string> {
    std::set<std::string> includes;
    XMLElement &types = FirstChildElement(registry.getVideo(), "types");
    ForEach(types, "type", [&](XMLElement &element) -> void {
        if (!HasAttributeValue(element, AttributeName{"category"}, AttributeValue{"include"}))
            return;
        if (!HasAttribute(element, "name"))
            return;
        const std::string name = Attribute(element, "name");
        if (name.contains("common"))
            return;
        if (!name.starts_with("vk_video/vulkan_video_codec"))
            return;
        includes.insert(name);
    });
    return includes;
}
