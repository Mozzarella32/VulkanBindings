#pragma once

#include "VecViewInterface.hpp"

#include <cassert>
#include <cstddef>
#include <cstring>
#include <stdexcept>

namespace VkBindings::impl_Struct {
template <typename Size_T, typename Data_T>
VecView<Size_T, Data_T>::VecView(size_type *size, const_pointer *data) noexcept
    : _size(size), _data(data) {
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
    if ((_size == nullptr) || (_data == nullptr)) {
        throw std::out_of_range("VecView::at: null view");
    }
    if (idx >= *_size) {
        throw std::out_of_range("VecView::at: index out of range");
    }

    // NOLINTBEGIN(cppcoreguidelines-pro-bounds-pointer-arithmetic)
    return (*_data)[static_cast<std::size_t>(idx)];
    // NOLINTEND(cppcoreguidelines-pro-bounds-pointer-arithmetic)
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
auto VecView<Size_T, Data_T>::cbegin() const noexcept -> VecView<Size_T, Data_T>::const_iterator {
    return data();
}
template <typename Size_T, typename Data_T>
auto VecView<Size_T, Data_T>::cend() const noexcept -> VecView<Size_T, Data_T>::const_iterator {
    const_pointer ptr = data();
    return ptr ? (ptr + static_cast<std::size_t>(size())) : nullptr;
}
} // namespace VkBindings::impl_Struct
