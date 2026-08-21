#pragma once

#include "VkBindings/ObjectsForward.hpp"

#include <type_traits>

namespace VkBindings::Reflections {
namespace Reflections_impl {
template <typename T> struct HasDispatcher : std::false_type {};
} // namespace Reflections_impl

template <typename T> constexpr bool HasDispatcher = Reflections_impl::HasDispatcher<T>::value;
} // namespace VkBindings::Reflections

namespace VkBindings::Concepts {
template <typename T> concept HasDispatcher = Reflections::HasDispatcher<T>;
} // namespace VkBindings::Concepts

namespace VkBindings::Reflections::Reflections_impl {
template<> struct HasDispatcher<CommandBuffer> : std::true_type{};
template<> struct HasDispatcher<ExternalComputeQueueNV> : std::true_type{};
template<> struct HasDispatcher<Queue> : std::true_type{};
template<> struct HasDispatcher<Device> : std::true_type{};
template<> struct HasDispatcher<PhysicalDevice> : std::true_type{};
template<> struct HasDispatcher<Instance> : std::true_type{};
} // namespace VkBindings::Reflections::Reflections_impl
