#pragma once

#include <string>
#include <set>

struct Depends {
    std::string m_namespace;
    std::string platform;
    std::string feature;
    std::set<std::string> extensions;
};

