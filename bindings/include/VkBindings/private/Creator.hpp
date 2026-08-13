#pragma once

#include <utility>
namespace VkBindings::impl_Objects {
struct Creator {
    template <typename T, typename... Ts> static auto create(Ts &&...arg) -> T {
        return T{std::forward<Ts>(arg)...};
    }
};
} // namespace VkBindings::impl_Objects
