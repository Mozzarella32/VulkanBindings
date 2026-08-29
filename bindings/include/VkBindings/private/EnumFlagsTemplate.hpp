#pragma once

#include <type_traits>
#ifdef _MSC_VER
#include <compare>
#endif

namespace VkBindings::impl_Enum {
template <typename BitType> struct Flags {
  public:
    using BitsType = BitType;
    using MaskType = std::underlying_type_t<BitType>;

  private:
    MaskType mask;

    constexpr Flags(MaskType mask) : mask(mask) {};

  public:
    constexpr Flags(BitType bit) : mask(static_cast<MaskType>(bit)) {};
    constexpr Flags() = default;

    auto operator<=>(Flags<BitType> const &) const = default;

    constexpr auto operator!() const -> bool { return !mask; }

    constexpr auto operator&(const Flags &other) const -> Flags { return Flags(mask & other.mask); }
    constexpr auto operator|(const Flags &other) const -> Flags { return Flags(mask | other.mask); }
    constexpr auto operator^(const Flags &other) const -> Flags { return Flags(mask ^ other.mask); }

    constexpr auto operator~() -> Flags
        requires requires { BitType::AllBits; }
    {
        return Flags(~mask ^ static_cast<MaskType>(BitType::AllBits));
    }

    constexpr auto operator|=(const Flags &other) -> Flags & {
        mask |= other.mask;
        return *this;
    }
    constexpr auto operator&=(const Flags &other) -> Flags & {
        mask &= other.mask;
        return *this;
    }
    constexpr auto operator^=(const Flags &other) -> Flags & {
        mask ^= other.mask;
        return *this;
    }

    explicit constexpr operator bool() const { return !!mask; }
    explicit constexpr operator MaskType() const { return mask; }
};
} // namespace VkBindings::impl_Enum

namespace VkBindings {
template <class E>
concept HasVkFlags = requires { typename impl_Enum::Flags<E>; };

template <HasVkFlags E> constexpr auto operator|(E bitA, E bitB) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bitA) | impl_Enum::Flags<E>(bitB);
}

template <HasVkFlags E> constexpr auto operator&(E bitA, E bitB) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bitA) & impl_Enum::Flags<E>(bitB);
}

template <HasVkFlags E> constexpr auto operator^(E bitA, E bitB) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bitA) ^ impl_Enum::Flags<E>(bitB);
}
template <HasVkFlags E>
constexpr auto operator|(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bit) | flag;
}

template <HasVkFlags E>
constexpr auto operator&(E bit, impl_Enum::Flags<E> blag) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bit) & blag;
}

template <HasVkFlags E>
constexpr auto operator^(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bit) ^ flag;
}

template <HasVkFlags E>
constexpr auto operator|(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E> {
    return flag | impl_Enum::Flags<E>(bit);
}

template <HasVkFlags E>
constexpr auto operator&(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E> {
    return flag & impl_Enum::Flags<E>(bit);
}

template <HasVkFlags E>
constexpr auto operator^(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E> {
    return flag ^ impl_Enum::Flags<E>(bit);
}
} // namespace VkBindings
