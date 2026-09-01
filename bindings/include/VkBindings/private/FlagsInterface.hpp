#pragma once

#include <type_traits>
#ifdef _MSC_VER
#include <compare>
#endif

#include "VkBindings/Reflection/IsBits.hpp"

namespace VkBindings::impl_Enum {
template <typename BitType> struct Flags {
  public:
    using BitsType = BitType;
    using MaskType = std::underlying_type_t<BitType>;

  private:
    MaskType mask;

    Flags(MaskType mask);

  public:
    Flags(BitType bit);
    Flags() = default;

    auto operator<=>(Flags<BitType> const &) const = default;

    auto operator!() const -> bool;

    auto operator&(const Flags &other) const -> Flags;
    auto operator|(const Flags &other) const -> Flags;
    auto operator^(const Flags &other) const -> Flags;

    auto operator~() -> Flags
        requires requires { BitType::AllBits; };

    auto operator|=(const Flags &other) -> Flags &;
    auto operator&=(const Flags &other) -> Flags &;
    auto operator^=(const Flags &other) -> Flags &;

    explicit operator bool() const;
    explicit operator MaskType() const;
};
} // namespace VkBindings::impl_Enum

namespace VkBindings {

template <Concepts::IsBits E> auto operator|(E bitA, E bitB) -> impl_Enum::Flags<E>;
template <Concepts::IsBits E> auto operator&(E bitA, E bitB) -> impl_Enum::Flags<E>;
template <Concepts::IsBits E> auto operator^(E bitA, E bitB) -> impl_Enum::Flags<E>;

template <Concepts::IsBits E>
auto operator|(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E>;
template <Concepts::IsBits E>
auto operator&(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E>;
template <Concepts::IsBits E>
auto operator^(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E>;

template <Concepts::IsBits E>
auto operator|(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E>;
template <Concepts::IsBits E>
auto operator&(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E>;
template <Concepts::IsBits E>
auto operator^(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E>;
} // namespace VkBindings
