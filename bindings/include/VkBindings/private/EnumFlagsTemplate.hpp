#pragma once

#include <compare>
#include <type_traits>

namespace VkBindings {
namespace impl_Enum {
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

    constexpr bool operator!() const { return !mask; }

    constexpr Flags operator&(const Flags &other) const { return Flags(mask & other.mask); }
    constexpr Flags operator|(const Flags &other) const { return Flags(mask | other.mask); }
    constexpr Flags operator^(const Flags &other) const { return Flags(mask ^ other.mask); }

    constexpr Flags operator~()
        requires requires { BitType::eAllBits; }
    {
        return Flags(~mask ^ static_cast<MaskType>(BitType::eAllBits));
    }

    constexpr Flags &operator=(const Flags &) = default;
    constexpr Flags &operator|=(const Flags &other) {
        mask |= other.mask;
        return *this;
    }
    constexpr Flags &operator&=(const Flags &other) {
        mask &= other.mask;
        return *this;
    }
    constexpr Flags &operator^=(const Flags &other) {
        mask ^= other.mask;
        return *this;
    }

    explicit constexpr operator bool() const { return !!mask; }
    explicit constexpr operator MaskType() const { return mask; }

    // friend constexpr Flags operator|(BitType a, BitType b) { return Flags(a) | Flags(b); }
    // friend constexpr Flags operator|(Flags lhs, BitType rhs) { return lhs | Flags(rhs); }
    // friend constexpr Flags operator|(BitType lhs, Flags rhs) { return Flags(lhs) | rhs; }

    // friend constexpr Flags operator&(BitType a, BitType b) { return Flags(a) & Flags(b); }
    // friend constexpr Flags operator&(Flags lhs, BitType rhs) { return lhs & Flags(rhs); }
    // friend constexpr Flags operator&(BitType lhs, Flags rhs) { return Flags(lhs) & rhs; }

    // friend constexpr Flags operator^(BitType a, BitType b) { return Flags(a) ^ Flags(b); }
    // friend constexpr Flags operator^(Flags lhs, BitType rhs) { return lhs ^ Flags(rhs); }
    // friend constexpr Flags operator^(BitType lhs, Flags rhs) { return Flags(lhs) ^ rhs; }
};
} // namespace impl_Enum
} // namespace VkBindings
