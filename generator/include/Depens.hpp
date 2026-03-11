#pragma once

#include <set>
#include <string>
#include <tuple>

struct Depends {
    std::string m_namespace;
    std::string platform;
    std::string feature;
    std::set<std::string> extensions;

    bool operator <(const Depends& other) const {
        return std::tie(m_namespace, platform, feature, extensions) < std::tie(other.m_namespace, other.platform, other.feature, other.extensions);
    }
};
