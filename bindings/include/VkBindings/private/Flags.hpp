#pragma once

#include "FlagsInterface.hpp"
#include "VkBindings/Reflection/IsBits.hpp"

namespace VkBindings::impl_Enum {
template <typename BitType> Flags<BitType>::Flags(MaskType mask) : mask(mask) {};

template <typename BitType>
Flags<BitType>::Flags(BitType bit) : mask(static_cast<MaskType>(bit)) {};

template <typename BitType> auto Flags<BitType>::operator!() const -> bool { return !mask; }

template <typename BitType> auto Flags<BitType>::operator&(const Flags &other) const -> Flags {
    return Flags(mask & other.mask);
}
template <typename BitType> auto Flags<BitType>::operator|(const Flags &other) const -> Flags {
    return Flags(mask | other.mask);
}
template <typename BitType> auto Flags<BitType>::operator^(const Flags &other) const -> Flags {
    return Flags(mask ^ other.mask);
}

template <typename BitType>
auto Flags<BitType>::operator~() -> Flags
    requires requires { BitType::AllBits; }
{
    return Flags(~mask ^ static_cast<MaskType>(BitType::AllBits));
}

template <typename BitType> auto Flags<BitType>::operator|=(const Flags &other) -> Flags & {
    mask |= other.mask;
    return *this;
}
template <typename BitType> auto Flags<BitType>::operator&=(const Flags &other) -> Flags & {
    mask &= other.mask;
    return *this;
}
template <typename BitType> auto Flags<BitType>::operator^=(const Flags &other) -> Flags & {
    mask ^= other.mask;
    return *this;
}

template <typename BitType> Flags<BitType>::operator bool() const { return !!mask; }
template <typename BitType> Flags<BitType>::operator MaskType() const { return mask; }
} // namespace VkBindings::impl_Enum

namespace VkBindings {

template <Concepts::IsBits E> auto operator|(E bitA, E bitB) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bitA) | impl_Enum::Flags<E>(bitB);
}

template <Concepts::IsBits E> auto operator&(E bitA, E bitB) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bitA) & impl_Enum::Flags<E>(bitB);
}

template <Concepts::IsBits E> auto operator^(E bitA, E bitB) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bitA) ^ impl_Enum::Flags<E>(bitB);
}

template <Concepts::IsBits E>
auto operator|(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bit) | flag;
}

template <Concepts::IsBits E>
auto operator&(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bit) & flag;
}

template <Concepts::IsBits E>
auto operator^(E bit, impl_Enum::Flags<E> flag) -> impl_Enum::Flags<E> {
    return impl_Enum::Flags<E>(bit) ^ flag;
}

template <Concepts::IsBits E>
auto operator|(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E> {
    return flag | impl_Enum::Flags<E>(bit);
}

template <Concepts::IsBits E>
auto operator&(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E> {
    return flag & impl_Enum::Flags<E>(bit);
}

template <Concepts::IsBits E>
auto operator^(impl_Enum::Flags<E> flag, E bit) -> impl_Enum::Flags<E> {
    return flag ^ impl_Enum::Flags<E>(bit);
}
} // namespace VkBindings
