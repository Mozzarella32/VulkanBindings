#pragma once

#include "VkBindings/ObjectsForward.hpp"

#include <type_traits>

namespace VkBindings::Reflections {
namespace Reflections_impl {
template <typename T> struct IsPool : std::false_type {};
} // namespace Reflections_impl

template <typename T> constexpr bool IsPool = Reflections_impl::IsPool<T>::value;
} // namespace VkBindings::Reflections

namespace VkBindings::Concepts {
template <typename T> concept IsPool = Reflections::IsPool<T>;
} // namespace VkBindings::Concepts

namespace VkBindings::Reflections::Reflections_impl {
template<> struct IsPool<CommandBuffers> : std::true_type{};
template<> struct IsPool<DescriptorSets> : std::true_type{};
} // namespace VkBindings::Reflections::Reflections_impl
