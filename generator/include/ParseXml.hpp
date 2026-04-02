#pragma once

#include "CppGenerator.hpp"

struct FunctionInfo;

#include <set>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>

struct Depends;

extern tinyxml2::XMLElement *vkXml;
extern tinyxml2::XMLElement *videoXml;

extern const std::unordered_map<std::string, std::string> &parseHandles();

extern const std::unordered_set<std::string> &parseDispatchableHandles();

extern const std::unordered_map<std::string, std::string> &
parseEnumAlias(tinyxml2::XMLElement &registry);

extern TypeAndName parseTypeAndName(tinyxml2::XMLElement &param);

extern const std::unordered_map<std::string, Depends> &
parseObjectDepents(tinyxml2::XMLElement &registry, std::string_view objectSV);

extern const std::unordered_set<std::string> &parseObjectsDisabled(tinyxml2::XMLElement &registry,
                                                                   std::string_view objectSV);

extern const std::unordered_set<std::string> parseVendorTags();

extern std::string
screamingSnakeCaseToPascalCase(const std::string &name,
                               const std::unordered_set<std::string> &vendorTags);

extern const std::set<FunctionInfo> &parseDestroyFunctions();

extern std::tuple<std::unordered_map<std::string, Function>,
                  std::unordered_map<std::string, std::set<FunctionInfo>>>
parseGroupedFunctions(tinyxml2::XMLElement &registry);

extern const std::unordered_map<std::string, std::string> &
parseObjectType(tinyxml2::XMLElement &registry);

extern const std::unordered_map<std::string, std::string> &
parseTypeStructureName(tinyxml2::XMLElement &registry);

extern const std::unordered_map<std::string, std::string> &
parseEnumAlias(tinyxml2::XMLElement &registry);

extern const std::string &parseDefines(tinyxml2::XMLElement &registry);
