#pragma once

#include "CppGenerator.hpp"
#include "Depens.hpp"
#include "ParseXml.hpp"
#include "Registry.hpp"

#include <set>
#include <string>
#include <tinyxml2.h>
#include <unordered_map>

class ConstantInfo {
    std::string type;
    std::string originalName;
    std::string name;
    std::string value;
    Depends depends;

  public:
    auto operator<(const ConstantInfo &other) const -> bool;

    [[nodiscard]] auto getDepends() const -> const Depends &;

    void writeHeader(CppGenerator &gen) const;

    static auto getConstantMapping(Registry registry)
        -> const std::unordered_map<std::string, std::string> &;
    static auto getConstantValues(Registry registry)
        -> const std::unordered_map<std::string, std::string> &;

  private:
    static auto parseConstantInfo(Registry registry, tinyxml2::XMLElement &element) -> ConstantInfo;
    static auto parseConstantInfosActive(Registry registry) -> const std::set<ConstantInfo> &;

  public:
    static auto parseConstantInfos(Registry registry) -> const std::set<ConstantInfo> &;
};
