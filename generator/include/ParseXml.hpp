#pragma once

#include "CppGenerator.hpp"
#include "Registry.hpp"

struct FunctionInfo;

#include <set>
#include <string>
#include <string_view>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>

struct Depends;

extern auto parseHandles(Registry registry) -> const std::unordered_map<std::string, std::string> &;

extern auto parseDispatchableHandles(Registry registry) -> const std::unordered_set<std::string> &;

extern auto parseAlias(Registry registry) -> const std::unordered_map<std::string, std::string> &;

extern auto parseTypeAndName(tinyxml2::XMLElement &param) -> TypeAndName;

extern auto parseObjectDepents(Registry registry, std::string_view objectSV)
    -> const std::unordered_map<std::string, Depends> &;

extern auto parseObjectsDisabled(Registry registry, std::string_view objectSV)
    -> const std::unordered_set<std::string> &;

extern auto parseVendorTags(Registry registry) -> std::unordered_set<std::string>;

extern auto screamingSnakeCaseToPascalCase(const std::string &name,
                                           const std::unordered_set<std::string> &vendorTags)
    -> std::string;

extern auto parseObjectType(Registry registry)
    -> const std::unordered_map<std::string, std::string> &;

extern auto parseTypeStructureName(Registry registry)
    -> const std::unordered_map<std::string, std::string> &;

extern auto parseDefines(Registry registry) -> const std::string &;

extern auto parseCodecEnumIncludes(Registry registry) -> std::set<std::string>;

extern auto parseDeprecation(Registry registry) -> std::unordered_map<std::string, std::string>&;
