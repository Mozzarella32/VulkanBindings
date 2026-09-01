
#pragma once

#include "ArrayProxyInterface.hpp"

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <initializer_list>

namespace VkBindings::impl_Struct {

template <typename T> constexpr ArrayProxy<T>::ArrayProxy(std::nullptr_t) noexcept {};

template <typename T> ArrayProxy<T>::ArrayProxy(T const &value) noexcept : count(1), ptr(&value) {}

template <typename T>
ArrayProxy<T>::ArrayProxy(std::uint32_t count, T const *ptr) noexcept : count(count), ptr(ptr) {}

// NOLINTBEGIN(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
template <typename T>
template <std::size_t C>
ArrayProxy<T>::ArrayProxy(T const (&ptr)[C]) noexcept : count(C), ptr(ptr) {}
// NOLINTEND(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)

#if __GNUC__ >= 9
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winit-list-lifetime"
#endif
template <typename T>
ArrayProxy<T>::ArrayProxy(std::initializer_list<T> const &list) noexcept
    : count(static_cast<std::uint32_t>(list.size())), ptr(list.begin()) {}
#if __GNUC__ >= 9
#pragma GCC diagnostic pop
#endif

template <typename T> auto ArrayProxy<T>::begin() const noexcept -> T const * { return ptr; }

template <typename T> auto ArrayProxy<T>::end() const noexcept -> T const * { return ptr + count; }

template <typename T> auto ArrayProxy<T>::front() const noexcept -> T const & {
    assert(count && ptr);
    return *ptr;
}

template <typename T> auto ArrayProxy<T>::back() const noexcept -> T const & {
    assert(count && ptr);
    return *(ptr + count - 1);
}

template <typename T> auto ArrayProxy<T>::empty() const noexcept -> bool { return (count == 0); }

template <typename T> auto ArrayProxy<T>::size() const noexcept -> std::uint32_t {
    return static_cast<std::uint32_t>(count);
}

template <typename T> auto ArrayProxy<T>::data() const noexcept -> T const * { return ptr; }

} // namespace VkBindings::impl_Struct
