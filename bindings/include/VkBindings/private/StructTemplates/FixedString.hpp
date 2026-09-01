#pragma once

#include "FixedStringInterface.hpp"

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <string_view>

namespace VkBindings::impl_Struct {
template <std::size_t N>
auto FixedString<N>::operator=(std::string_view stringView) noexcept -> FixedString<N> & {
    constexpr std::size_t maxCopy = (N > 0) ? (N - 1) : 0;
    const std::size_t toCopy = (stringView.size() <= maxCopy) ? stringView.size() : maxCopy;

    data.fill(0);
    if (toCopy != 0) {
        std::ranges::copy_n(stringView.begin(), toCopy, data.data());
    }
    if constexpr (N > 0) {
        data[toCopy] = '\0';
    }
    return *this;
}

template <std::size_t N>
auto FixedString<N>::operator=(const std::string &string) noexcept -> FixedString<N> & {
    return *this = std::string_view(string);
}

template <std::size_t N>
auto FixedString<N>::operator=(const char *stringLiteral) noexcept -> FixedString<N> & {
    if (stringLiteral == nullptr) {
        data.fill(0);
        if constexpr (N != 0U) {
            data[0] = '\0';
        }
        return *this;
    }
    const std::size_t len = std::char_traits<char>::length(stringLiteral);
    return *this = std::string_view(stringLiteral, len);
}

template <std::size_t N> FixedString<N>::operator std::string() const noexcept {
    return std::string(this->data.data());
}

// NOLINTBEGIN(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
template <std::size_t N>
template <std::size_t M>
auto FixedString<N>::operator=(const char (&lit)[M]) noexcept -> FixedString<N> & {
    const std::size_t literalLen = (M == 0) ? 0 : (M - 1);
    return *this = std::string_view(lit, literalLen);
}
// NOLINTEND(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
} // namespace VkBindings::impl_Struct
