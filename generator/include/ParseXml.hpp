#pragma once

#include "ConstantInfo.hpp"
#include <set>
#include <tinyxml2.h>

struct ObjectInfo;
struct TypeInfo;
struct ConstantInfo;

extern const std::set<TypeInfo>& parseTypeInfos(tinyxml2::XMLElement &registry);
extern const std::set<ObjectInfo>& parseObjectInfos(tinyxml2::XMLElement &registry);
extern const std::set<ConstantInfo>& parseConstantInfos(tinyxml2::XMLElement &registry);
