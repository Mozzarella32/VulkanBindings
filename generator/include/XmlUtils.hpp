#pragma once

#include <functional>
#include <string>
#include <tinyxml2.h>

extern tinyxml2::XMLElement &FirstChildElement(tinyxml2::XMLElement &element,
                                               const std::string &elementValue);

extern void ForEachBreak(tinyxml2::XMLElement &elem, const std::string &elementValue,
                         std::function<bool(tinyxml2::XMLElement &)> fun);

extern void ForEach(tinyxml2::XMLElement &elem, const std::string &elementValue,
                    std::function<void(tinyxml2::XMLElement &)> fun);

extern void Print [[maybe_unused]] (tinyxml2::XMLElement &elem);

extern bool HasAttributeValue(tinyxml2::XMLElement &elem, const std::string &name,
                              const std::string &value);
extern bool HasAttribute(tinyxml2::XMLElement &elem, const std::string &name);

extern std::string Attribute(tinyxml2::XMLElement &elem, const std::string &name);

extern bool HasText(tinyxml2::XMLElement &elem, const std::string &value);

extern std::string trim_copy(std::string s);
