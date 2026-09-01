#pragma once

#include "AssignableHandleInterface.hpp"
#include "VkBindings/Concepts.hpp"
#include "VkBindings/Reflection/HandleToObject.hpp"

#include <cassert>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <type_traits>

namespace VkBindings::impl_Struct {

struct LayoutChecker;
template <typename T> struct ArrayProxy {
  public:
    constexpr ArrayProxy() = default;

    constexpr ArrayProxy(std::nullptr_t) noexcept;
    ArrayProxy(T const &value) noexcept;

    ArrayProxy(std::uint32_t count, T const *ptr) noexcept;

    // NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
    template <typename V>
    ArrayProxy(V &val) noexcept
        requires(requires { typename T::handle_type; } &&
                 std::same_as<
                     T, AssignableHandle<Reflections::HandleToObject<typename T::handle_type>>> &&
                 std::same_as<std::remove_cvref_t<V>,
                              Reflections::HandleToObject<typename T::handle_type>> &&
                 Concepts::ABIIsHandle<std::remove_cvref_t<V>>)
        : count(1), ptr(reinterpret_cast<T const *>(std::addressof(val))) {}

    // NOLINTBEGIN(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
    template <std::size_t C> ArrayProxy(T const (&ptr)[C]) noexcept;
    // NOLINTEND(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)

#if __GNUC__ >= 9
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winit-list-lifetime"
#endif

    ArrayProxy(std::initializer_list<T> const &list) noexcept;

    template <typename B = T>
    ArrayProxy(std::initializer_list<std::remove_const_t<T>> const &list) noexcept
        requires std::is_const_v<B>
        : count(static_cast<std::size_t>(list.size())), ptr(list.begin()) {}

    template <typename U>
        requires
        // T must be AssignableHandle<Obj>
        requires { typename T::handle_type; } &&
            std::same_as<T,
                         AssignableHandle<Reflections::HandleToObject<typename T::handle_type>>> &&
            // U must be that Obj type
            std::same_as<std::remove_cvref_t<U>,
                         Reflections::HandleToObject<typename T::handle_type>> &&
            // Obj must be ABI-compatible with handle
            Concepts::ABIIsHandle<Reflections::HandleToObject<typename T::handle_type>>
            ArrayProxy(std::initializer_list<U> const &list) noexcept
        : count(static_cast<std::uint32_t>(list.size())),
        ptr(reinterpret_cast<T const *>(list.begin())) {}

#if __GNUC__ >= 9
#pragma GCC diagnostic pop
#endif
    // NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

    template <typename V>
    ArrayProxy(V const &val) noexcept
        requires requires(V val) {
            { val.data() } -> std::convertible_to<T *>;
            { val.size() } -> std::convertible_to<std::size_t>;
        }
        : count(static_cast<std::size_t>(val.size())), ptr(val.data()) {}

    auto begin() const noexcept -> T const *;

    auto end() const noexcept -> T const *;

    auto front() const noexcept -> T const &;

    auto back() const noexcept -> T const &;

    [[nodiscard]] auto empty() const noexcept -> bool;

    [[nodiscard]] auto size() const noexcept -> std::uint32_t;

    auto data() const noexcept -> T const *;

  private:
    std::size_t count = 0;
    T const *ptr = nullptr;
};
} // namespace VkBindings::impl_Struct
