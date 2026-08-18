#pragma once

#include <string>
#include <tuple>

struct Depends {
    std::string _namespace;
    std::string platform;
    std::string guard;

    friend auto operator<(const Depends &depLHS, const Depends &depRHS) -> bool {
        return std::tie(depLHS._namespace, depLHS.platform, depLHS.guard) <
               std::tie(depRHS._namespace, depRHS.platform, depRHS.guard);
    }
};
