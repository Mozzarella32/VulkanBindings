#pragma once

#include "VkBindings/Vulkan.hpp"
#include "VkBindings/Enums.hpp"

namespace VkBindings {
namespace Reflections {
template <typename T> struct ObjectType;
template <typename T> constexpr auto ObjectType_v = ObjectType<T>::value; template <typename T> struct HandleType;
template <typename T> struct HandleType;
template <typename T> using HandleType_t = HandleType<T>::t;
} // namespace Reflections
} // namespace VkBindings
