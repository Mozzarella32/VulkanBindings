#pragma once

#include <string>
#include <tuple>

struct Depends {
    std::string m_namespace;
    std::string platform;
    std::string guard;

    auto operator<(const Depends &other) const -> bool {
        return std::tie(m_namespace, platform, guard) <
               std::tie(other.m_namespace, other.platform, other.guard);
    }
};
