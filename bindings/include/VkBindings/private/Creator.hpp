#pragma once

#include "VkBindings/private/Loader.hpp"

#include <utility>

namespace VkBindings::impl_Objects {
struct Creator {
    template <typename T, typename... Ts> static auto create(Ts &&...arg) -> T {
        return T{std::forward<Ts>(arg)...};
    }
    template <typename T>
    static auto getDispatcher(const T &obj) -> const impl_Loader::Dispatcher & {
        return obj.getDispatcher();
    }
};
} // namespace VkBindings::impl_Objects
