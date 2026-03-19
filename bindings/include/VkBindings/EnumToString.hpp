#pragma once

#include <string>

namespace VkBindings {
namespace Reflections {
template <typename T> constexpr std::string EnumToString(T enumVal);
// intended for the Flag type alias
template <typename T> constexpr std::string BitmaskToString(T bitmask);
} // namespace Reflections
} // namespace VkBindings
