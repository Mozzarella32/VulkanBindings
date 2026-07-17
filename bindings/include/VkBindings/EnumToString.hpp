#pragma once

#include <string>

namespace VkBindings::Reflections {
template <typename T> constexpr auto EnumToString(T enumVal) -> std::string;
// intended for the Flag type alias
template <typename T> constexpr auto BitmaskToString(T bitmask) -> std::string;
} // namespace VkBindings::Reflections
