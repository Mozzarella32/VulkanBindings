#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>
#include <string_view>

namespace VkBindings::impl_Struct {

struct LayoutChecker;

template <std::size_t N> struct FixedString {
    static_assert(N > 0, "FixedString size must be > 0");

  private:
    std::array<char, N> data;

    friend LayoutChecker;

  public:
    auto operator=(std::string_view stringView) noexcept -> FixedString &;

    auto operator=(const std::string &string) noexcept -> FixedString &;

    auto operator=(const char *stringLiteral) noexcept -> FixedString &;

    operator std::string() const noexcept;

    // NOLINTBEGIN(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
    template <std::size_t M> auto operator=(const char (&lit)[M]) noexcept -> FixedString &;
    // NOLINTEND(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
};
} // namespace VkBindings::impl_Struct
