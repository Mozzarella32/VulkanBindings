#pragma once

#include "StructTemplatesInterface.hpp"
#include <stdexcept>

namespace VkBindings::impl_Struct {

template <typename T>
    requires requires { typename Reflections::HandleType_t<T>; }
auto AssignableHandle<T>::operator=(T &t) -> AssignableHandle<T> & {
    handle = t.get();
    return *this;
}

template <typename T>
    requires requires { typename Reflections::HandleType_t<T>; }
auto AssignableHandle<T>::operator=(handle_type h) -> AssignableHandle<T> & {
    handle = h;
    return *this;
}

template <std::size_t N>
auto FixedString<N>::operator=(std::string_view sv) noexcept -> FixedString<N> & {
    const std::size_t maxCopy = (N > 0) ? (N - 1) : 0;
    const std::size_t toCopy = (sv.size() <= maxCopy) ? sv.size() : maxCopy;
    std::memset(data, 0, N);
    if (toCopy) {
        std::memcpy(data, sv.data(), toCopy);
    }
    data[toCopy] = '\0';
    return *this;
}

template <std::size_t N>
auto FixedString<N>::operator=(const std::string &s) noexcept -> FixedString<N> & {
    return *this = std::string_view(s);
}

template <std::size_t N>
auto FixedString<N>::operator=(const char *s) noexcept -> FixedString<N> & {
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
auto FixedString<N>::operator=(const char (&lit)[M]) noexcept -> FixedString<N> & {
    const std::size_t literalLen = (M == 0) ? 0 : (M - 1);
    return *this = std::string_view(lit, literalLen);
}

template <typename Size_T, typename Data_T>
VecView<Size_T, Data_T>::VecView(size_type *s, const_pointer *d) noexcept : _size(s), _data(d) {
    assert(_size && _data);
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::operator=(const value_type &data) noexcept
    -> VecView<Size_T, Data_T> & {
    assert(_size && _data);
    *_size = 1;
    *_data = &data;
    return *this;
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::size() const noexcept -> VecView<Size_T, Data_T>::size_type {
    return _size ? *_size : size_type{0};
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::empty() const noexcept -> bool {
    return size() == size_type{0};
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::data() noexcept -> VecView<Size_T, Data_T>::pointer {
    return _data ? *_data : nullptr;
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::data() const noexcept -> VecView<Size_T, Data_T>::const_pointer {
    return _data ? *_data : nullptr;
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::operator[](size_type idx) const noexcept
    -> VecView<Size_T, Data_T>::const_reference {
    return data()[static_cast<std::size_t>(idx)];
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::at(size_type idx) const -> VecView<Size_T, Data_T>::const_reference {
    if (!_size || !_data)
        throw std::out_of_range("VecView::at: null view");
    if (idx >= *_size)
        throw std::out_of_range("VecView::at: index out of range");
    return (*_data)[static_cast<std::size_t>(idx)];
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::front() const -> VecView<Size_T, Data_T>::const_reference {
    return at(size_type{0});
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::back() const -> VecView<Size_T, Data_T>::const_reference {
    return at(size() - size_type{1});
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::begin() const noexcept -> VecView<Size_T, Data_T>::iterator {
    return data();
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::end() const noexcept -> VecView<Size_T, Data_T>::iterator {
    const_pointer p = data();
    return p ? (p + static_cast<std::size_t>(size())) : nullptr;
}

template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::cbegin() const noexcept -> VecView<Size_T, Data_T>::const_iterator {
    return begin();
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::cend() const noexcept -> VecView<Size_T, Data_T>::const_iterator {
    return end();
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::rbegin() const noexcept -> VecView<Size_T, Data_T>::reverse_iterator {
    return reverse_iterator(end());
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::rend() const noexcept -> VecView<Size_T, Data_T>::reverse_iterator {
    return reverse_iterator(begin());
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::crbegin() const noexcept
    -> VecView<Size_T, Data_T>::const_reverse_iterator {
    return const_reverse_iterator(cend());
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::crend() const noexcept
    -> VecView<Size_T, Data_T>::const_reverse_iterator {
    return const_reverse_iterator(cbegin());
}

} // namespace VkBindings::impl_Struct
