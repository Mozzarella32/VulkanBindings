#pragma once

#include <functional>
#include <ranges>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <unordered_set>

extern auto checkApi(tinyxml2::XMLElement &elem) -> bool;

extern auto FirstChildElement(tinyxml2::XMLElement &element, const std::string &elementValue)
    -> tinyxml2::XMLElement &;

extern void ForEachBreak(tinyxml2::XMLElement &elem, const std::string &elementValue,
                         const std::function<bool(tinyxml2::XMLElement &)> &fun);

extern void ForEach(tinyxml2::XMLElement &elem, const std::string &elementValue,
                    const std::function<void(tinyxml2::XMLElement &)> &fun);

extern void Print [[maybe_unused]] (tinyxml2::XMLElement &elem);

struct AttributeName {
    const char *value;
};

struct AttributeValue {
    std::string_view value;
};

auto HasAttributeValue(tinyxml2::XMLElement &elem, AttributeName name, AttributeValue value)
    -> bool;

extern auto HasAttribute(tinyxml2::XMLElement &elem, const std::string &name) -> bool;

extern auto Attribute(tinyxml2::XMLElement &elem, const std::string &name) -> std::string;

extern auto HasText(tinyxml2::XMLElement &elem, std::string_view value) -> bool;

extern auto trim_copy(std::string string) -> std::string;

inline constexpr auto splitCSL =
    std::views::split(',') | std::ranges::to<std::unordered_set<std::string>>();
