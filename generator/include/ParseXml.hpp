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

extern auto parseHandles() -> const std::unordered_map<std::string, std::string> &;

extern auto parseDispatchableHandles() -> const std::unordered_set<std::string> &;

extern auto parseAlias(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> &;

extern auto parseTypeAndName(tinyxml2::XMLElement &param) -> TypeAndName;

extern auto parseObjectDepents(tinyxml2::XMLElement &registry, std::string_view objectSV)
    -> const std::unordered_map<std::string, Depends> &;

extern auto parseObjectsDisabled(tinyxml2::XMLElement &registry, std::string_view objectSV)
    -> const std::unordered_set<std::string> &;

extern auto parseVendorTags() -> const std::unordered_set<std::string>;

extern auto screamingSnakeCaseToPascalCase(const std::string &name,
                                           const std::unordered_set<std::string> &vendorTags)
    -> std::string;

extern auto parseDestroyFunctions(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, FunctionInfo> &;

extern auto parseGroupedFunctions(tinyxml2::XMLElement &registry)
    -> std::unordered_map<std::string, std::set<FunctionInfo>>;

extern auto parseObjectType(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> &;

extern auto parseTypeStructureName(tinyxml2::XMLElement &registry)
    -> const std::unordered_map<std::string, std::string> &;

extern auto parseDefines(tinyxml2::XMLElement &registry) -> const std::string &;
