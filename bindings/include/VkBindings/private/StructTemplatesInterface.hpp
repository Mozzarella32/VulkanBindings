#pragma once

#include "VkBindings/ObjectReflections.hpp"

#include <cassert>
#include <cstring>
#include <stdexcept>
#include <string>

namespace VkBindings {
namespace impl_Struct {

template <typename T>
    requires requires { typename Reflections::HandleType_t<T>; }
struct AssignableHandle {
    using handle_type = Reflections::HandleType_t<T>;

    handle_type handle;

    AssignableHandle &operator=(T &t);
};

struct InString {
    const char *pStr = nullptr;

    InString &operator=(const std::string &str) {
        pStr = str.data();
        return *this;
    }
    InString &operator=(const char *cStr) {
        pStr = cStr;
        return *this;
    }
};

template <std::size_t N> struct FixedString {
    static_assert(N > 0, "FixedString size must be > 0");
    char data[N];

    FixedString &operator=(std::string_view sv) noexcept;

    FixedString &operator=(const std::string &s) noexcept;

    FixedString &operator=(const char *s) noexcept;

    template <std::size_t M> FixedString &operator=(const char (&lit)[M]) noexcept;
};

template <typename Size_T, typename Data_T> struct VecView {
    static_assert(std::integral<Size_T>, "Size_T should be an integral type");

    using value_type = Data_T;
    using size_type = Size_T;
    using pointer = const Data_T *;
    using const_pointer = const Data_T *;
    using reference = const Data_T &;
    using const_reference = const Data_T &;
    using iterator = const_pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  private:
    size_type *_size = nullptr;
    const_pointer *_data = nullptr;

  public:
    constexpr VecView() noexcept = default;

    constexpr VecView(size_type *s, const_pointer *d) noexcept;

    template <typename Container>
        requires requires(const Container &c) {
            { c.size() } -> std::convertible_to<size_type>;
            { c.data() } -> std::convertible_to<const_pointer>;
        }
    constexpr VecView &operator=(const Container &container) noexcept {
        assert(_size && _data);
        *_size = static_cast<size_type>(container.size());
        *_data = container.data();
        return *this;
    }
    constexpr VecView &operator=(const Data_T &data) noexcept;

    constexpr size_type size() const noexcept;
    constexpr bool empty() const noexcept;
    constexpr const_pointer data() const noexcept;

    constexpr const_reference operator[](size_type idx) const noexcept;

    constexpr const_reference at(size_type idx) const;

    constexpr const_reference front() const;
    constexpr const_reference back() const;

    constexpr iterator begin() const noexcept;
    constexpr iterator end() const noexcept;

    constexpr const_iterator cbegin() const noexcept;
    constexpr const_iterator cend() const noexcept;
    constexpr reverse_iterator rbegin() const noexcept;
    constexpr reverse_iterator rend() const noexcept;
    constexpr const_reverse_iterator crbegin() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;
};
} // namespace impl_Struct
} // namespace VkBindings
