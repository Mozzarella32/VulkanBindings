#pragma once

#include "VkBindings/Reflection/BitsToFlag.hpp"
#include "VkBindings/Reflection/IsBits.hpp"
#include "VkBindings/Reflection/IsEnum.hpp"
#include "VkBindings/Reflection/IsFlag.hpp"
#include "VkBindings/Reflection/IsObject.hpp"
#include "VkBindings/Reflection/IsUnique.hpp"
#include "VkBindings/private/StructTemplates/AssignableHandleInterface.hpp"

#include <array>
#include <concepts>

namespace VkBindings {

template <Concepts::IsBits First, Concepts::IsBits... Ts>
    requires(std::same_as<Ts, First> && ...)
constexpr auto stackContainer(const First &first, const Ts &...rest)
    -> std::array<Reflections::BitsToFlag<First>, 1 + sizeof...(Ts)> {
    return {first, rest...};
}

template <Concepts::IsEnum First, Concepts::IsEnum... Ts>
    requires(std::same_as<Ts, First> && ...)
constexpr auto stackContainer(const First &first, const Ts &...rest)
    -> std::array<First, 1 + sizeof...(Ts)> {
    return {first, rest...};
}

template <Concepts::IsFlag First, Concepts::IsFlag... Ts>
    requires(std::same_as<Ts, First> && ...)
constexpr auto stackContainer(const First &first, const Ts &...rest)
    -> std::array<First, 1 + sizeof...(Ts)> {
    return {first, rest...};
}

template <Concepts::IsObject First, Concepts::IsObject... Ts>
    requires(std::same_as<Ts, First> && ...)
constexpr auto stackContainer(const First &first, const Ts &...rest)
    -> std::array<impl_Struct::AssignableHandle<First>, 1 + sizeof...(Ts)> {
    return {first.getHandle(), rest.getHandle()...};
}

template <Concepts::IsUnique First, Concepts::IsUnique... Ts>
    requires(std::same_as<Ts, First> && ...)
constexpr auto stackContainer(const First &first, const Ts &...rest)
    -> std::array<impl_Struct::AssignableHandle<typename First::object_type>, 1 + sizeof...(Ts)> {
    return {first.getHandle(), rest.getHandle()...};
}

} // namespace VkBindings
