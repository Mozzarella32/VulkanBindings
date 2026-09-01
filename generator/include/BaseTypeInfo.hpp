#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "Registry.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>
#include <unordered_set>

struct BaseTypeInfo {
  private:
    Depends depends;
    std::string originalName;
    std::string name;
    std::string code;

  public:
    [[nodiscard]] auto getDepends() const -> const Depends &;
    [[nodiscard]] auto getName() const -> const std::string &;

    auto operator<(const BaseTypeInfo &other) const -> bool;

    void write(CppGenerator &gen) const;

    static auto getBaseTypeMapping(Registry registry)
        -> const std::unordered_map<std::string, std::string> &;
    static auto getIntTypedefs(Registry registry) -> const std::unordered_set<std::string> &;

  private:
    static auto makeBaseTypeInfo(tinyxml2::XMLElement &type,
                                 const std::unordered_map<std::string, Depends> &objectDepends)
        -> BaseTypeInfo;

  public:
    static auto parseBaseTypeInfo(Registry registry) -> const std::set<BaseTypeInfo> &;
};
