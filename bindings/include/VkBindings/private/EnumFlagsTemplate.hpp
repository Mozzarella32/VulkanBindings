#pragma once

#include <compare>
#include <type_traits>

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
    constexpr Flags(const Flags &) = default;
    constexpr Flags() = default;

    auto operator<=>(Flags<BitType> const &) const = default;

    constexpr auto operator!() const -> bool { return !mask; }

    constexpr auto operator&(const Flags &other) const -> Flags { return Flags(mask & other.mask); }
    constexpr auto operator|(const Flags &other) const -> Flags { return Flags(mask | other.mask); }
    constexpr auto operator^(const Flags &other) const -> Flags { return Flags(mask ^ other.mask); }

    constexpr auto operator~() -> Flags
        requires requires { BitType::eAllBits; }
    {
        return Flags(~mask ^ static_cast<MaskType>(BitType::eAllBits));
    }

    constexpr auto operator=(const Flags &) -> Flags & = default;
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
concept HasVkFlags = requires(E e) { typename impl_Enum::Flags<E>; };

template <HasVkFlags E> constexpr auto operator|(E a, E b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return Flags(a) | Flags(b);
}

template <HasVkFlags E> constexpr auto operator&(E a, E b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return Flags(a) & Flags(b);
}

template <HasVkFlags E> constexpr auto operator^(E a, E b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return Flags(a) ^ Flags(b);
}
template <HasVkFlags E>
constexpr auto operator|(E a, impl_Enum::Flags<E> b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return Flags(a) | b;
}

template <HasVkFlags E>
constexpr auto operator&(E a, impl_Enum::Flags<E> b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return Flags(a) & b;
}

template <HasVkFlags E>
constexpr auto operator^(E a, impl_Enum::Flags<E> b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return Flags(a) ^ b;
}

template <HasVkFlags E>
constexpr auto operator|(impl_Enum::Flags<E> a, E b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return a | Flags(b);
}

template <HasVkFlags E>
constexpr auto operator&(impl_Enum::Flags<E> a, E b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return a & Flags(b);
}

template <HasVkFlags E>
constexpr auto operator^(impl_Enum::Flags<E> a, E b) -> impl_Enum::Flags<E> {
    using Flags = impl_Enum::Flags<E>;
    return a ^ Flags(b);
}
} // namespace VkBindings
