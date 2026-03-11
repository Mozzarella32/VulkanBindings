#pragma once

#include <set>
#include <tinyxml2.h>

struct ObjectInfo;
struct TypeInfo;

extern const std::set<TypeInfo>& parseTypeInfos(tinyxml2::XMLElement &registry);
extern const std::set<ObjectInfo>& parseObjectInfos(tinyxml2::XMLElement &registry);
