#pragma once

#include <utility>
namespace VkBindings::impl_Objects {
struct Creator {
    template <typename T, typename... Ts> static auto create(Ts &&...ts) -> T {
        return T{std::forward<Ts>(ts)...};
    }
};
} // namespace VkBindings::impl_Objects
