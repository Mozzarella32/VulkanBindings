#pragma once

#include <functional>
#include <string>
#include <tinyxml2.h>
#include <unordered_set>

extern auto checkApi(tinyxml2::XMLElement &elem) -> bool;

extern auto FirstChildElement(tinyxml2::XMLElement &element, const std::string &elementValue)
    -> tinyxml2::XMLElement &;

extern void ForEachBreak(tinyxml2::XMLElement &elem, const std::string &elementValue,
                         std::function<bool(tinyxml2::XMLElement &)> fun);

extern void ForEach(tinyxml2::XMLElement &elem, const std::string &elementValue,
                    std::function<void(tinyxml2::XMLElement &)> fun);

extern void Print [[maybe_unused]] (tinyxml2::XMLElement &elem);

extern auto HasAttributeValue(tinyxml2::XMLElement &elem, const std::string &name,
                              const std::string &value) -> bool;
extern auto HasAttribute(tinyxml2::XMLElement &elem, const std::string &name) -> bool;

extern auto Attribute(tinyxml2::XMLElement &elem, const std::string &name) -> std::string;

extern auto HasText(tinyxml2::XMLElement &elem, const std::string &value) -> bool;

extern auto trim_copy(std::string s) -> std::string;

extern auto splitCSL(const std::string &s) -> std::unordered_set<std::string>;
