#pragma once

#include <set>
#include <string>

struct Depends {
    std::string m_namespace;
    std::string platform;
    std::string feature;
    std::set<std::string> extensions;
};
