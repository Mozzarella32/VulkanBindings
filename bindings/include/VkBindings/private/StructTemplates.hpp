#pragma once

#include "StructTemplatesInterface.hpp"

namespace VkBindings {
namespace impl_Struct {

template <typename T>
    requires requires { typename Reflections::HandleType_t<T>; }
AssignableHandle<T> &AssignableHandle<T>::operator=(T &t) {
    handle = t.get();
    return *this;
}

template <typename T>
    requires requires { typename Reflections::HandleType_t<T>; }
AssignableHandle<T> &AssignableHandle<T>::operator=(handle_type h) {
    handle = h;
    return *this;
}

template <std::size_t N> FixedString<N> &FixedString<N>::operator=(std::string_view sv) noexcept {
    const std::size_t maxCopy = (N > 0) ? (N - 1) : 0;
    const std::size_t toCopy = (sv.size() <= maxCopy) ? sv.size() : maxCopy;
    std::memset(data, 0, N);
    if (toCopy) {
        std::memcpy(data, sv.data(), toCopy);
    }
    data[toCopy] = '\0';
    return *this;
}

template <std::size_t N> FixedString<N> &FixedString<N>::operator=(const std::string &s) noexcept {
    return *this = std::string_view(s);
}

template <std::size_t N> FixedString<N> &FixedString<N>::operator=(const char *s) noexcept {
    if (!s) {
        std::memset(data, 0, N);
        if (N)
            data[0] = '\0';
        return *this;
    }
    const std::size_t len = std::char_traits<char>::length(s);
    return *this = std::string_view(s, len);
}

template <std::size_t N>
template <std::size_t M>
FixedString<N> &FixedString<N>::operator=(const char (&lit)[M]) noexcept {
    const std::size_t literalLen = (M == 0) ? 0 : (M - 1);
    return *this = std::string_view(lit, literalLen);
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::VecView(size_type *s, const_pointer *d) noexcept
    : _size(s), _data(d) {
    assert(_size && _data);
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T> &
VecView<Size_T, Data_T>::operator=(const value_type &data) noexcept {
    assert(_size && _data);
    *_size = 1;
    *_data = &data;
    return *this;
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::size_type VecView<Size_T, Data_T>::size() const noexcept {
    return _size ? *_size : size_type{0};
}
template <typename Size_T, typename Data_T>
constexpr bool VecView<Size_T, Data_T>::empty() const noexcept {
    return size() == size_type{0};
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_pointer VecView<Size_T, Data_T>::data() const noexcept {
    return _data ? *_data : nullptr;
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_reference
VecView<Size_T, Data_T>::operator[](size_type idx) const noexcept {
    return data()[static_cast<std::size_t>(idx)];
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_reference
VecView<Size_T, Data_T>::at(size_type idx) const {
    if (!_size || !_data)
        throw std::out_of_range("VecView::at: null view");
    if (idx >= *_size)
        throw std::out_of_range("VecView::at: index out of range");
    return (*_data)[static_cast<std::size_t>(idx)];
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_reference VecView<Size_T, Data_T>::front() const {
    return at(size_type{0});
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_reference VecView<Size_T, Data_T>::back() const {
    return at(size() - size_type{1});
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::iterator VecView<Size_T, Data_T>::begin() const noexcept {
    return data();
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::iterator VecView<Size_T, Data_T>::end() const noexcept {
    const_pointer p = data();
    return p ? (p + static_cast<std::size_t>(size())) : nullptr;
}

template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_iterator VecView<Size_T, Data_T>::cbegin() const noexcept {
    return begin();
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_iterator VecView<Size_T, Data_T>::cend() const noexcept {
    return end();
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::reverse_iterator
VecView<Size_T, Data_T>::rbegin() const noexcept {
    return reverse_iterator(end());
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::reverse_iterator VecView<Size_T, Data_T>::rend() const noexcept {
    return reverse_iterator(begin());
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_reverse_iterator
VecView<Size_T, Data_T>::crbegin() const noexcept {
    return const_reverse_iterator(cend());
}
template <typename Size_T, typename Data_T>
constexpr VecView<Size_T, Data_T>::const_reverse_iterator
VecView<Size_T, Data_T>::crend() const noexcept {
    return const_reverse_iterator(cbegin());
}

} // namespace impl_Struct
} // namespace VkBindings
