#pragma once

#include <functional>
#include <ranges>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <unordered_set>

extern auto checkApi(const tinyxml2::XMLElement &elem) -> bool;

extern auto firstChildElement(tinyxml2::XMLElement &element, const std::string &elementValue)
    -> tinyxml2::XMLElement &;

extern void forEachBreak(tinyxml2::XMLElement &elem, const std::string &elementValue,
                         const std::function<bool(tinyxml2::XMLElement &)> &fun);

extern void forEach(tinyxml2::XMLElement &elem, const std::string &elementValue,
                    const std::function<void(tinyxml2::XMLElement &)> &fun);

extern void print [[maybe_unused]](const tinyxml2::XMLElement &elem);

struct AttributeName {
    const char *value;
};

struct AttributeValue {
    std::string_view value;
};

auto hasAttributeValue(const tinyxml2::XMLElement &elem, AttributeName name, AttributeValue value)
    -> bool;

extern auto hasAttribute(const tinyxml2::XMLElement &elem, const std::string &name) -> bool;

extern auto attribute(const tinyxml2::XMLElement &elem, const std::string &name) -> std::string;

extern auto hasText(const tinyxml2::XMLElement &elem, std::string_view value) -> bool;

extern auto trimCopy(std::string string) -> std::string;

inline constexpr auto splitCSL =
    std::views::split(',') | std::ranges::to<std::unordered_set<std::string>>();
