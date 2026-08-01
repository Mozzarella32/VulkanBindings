#pragma once

#include "VkBindings/ObjectReflections.hpp"

#include <cassert>
#include <cstring>
#include <string>

namespace VkBindings::impl_Struct {

// Don't use Concepts here ase we only have Obj fwd at this point
template <typename T>
    requires requires { typename Reflections::ObjectToHandle_t<T>; }
struct AssignableHandle {
    using handle_type = Reflections::ObjectToHandle_t<T>;

    handle_type handle;

    auto operator=(const T &t) -> AssignableHandle &;
    auto operator=(handle_type h) -> AssignableHandle &;
};

struct InString {
    const char *pStr = nullptr;

    auto operator=(const std::string &str) -> InString & {
        pStr = str.data();
        return *this;
    }
    auto operator=(const char *cStr) -> InString & {
        pStr = cStr;
        return *this;
    }
};

template <std::size_t N> struct FixedString {
    static_assert(N > 0, "FixedString size must be > 0");
    std::array<char, N> data;

    auto operator=(std::string_view sv) noexcept -> FixedString &;

    auto operator=(const std::string &s) noexcept -> FixedString &;

    auto operator=(const char *s) noexcept -> FixedString &;

    operator std::string() const noexcept;

    template <std::size_t M> auto operator=(const char (&lit)[M]) noexcept -> FixedString &;
};

template <typename Size_T, typename Data_T> struct VecView {
    static_assert(std::integral<Size_T>, "Size_T should be an integral type");

    using value_type = Data_T;
    using size_type = Size_T;
    using pointer = Data_T *;
    using const_pointer = const Data_T *;
    using reference = Data_T &;
    using const_reference = const Data_T &;
    using iterator = const_pointer;
    using const_iterator = const_pointer;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  private:
    size_type *_size = nullptr;
    const_pointer *_data = nullptr;

  public:
    VecView() noexcept = default;

    VecView(size_type *s, const_pointer *d) noexcept;

    template <typename Container>
        requires requires(const Container &c) {
            { c.size() } -> std::convertible_to<size_type>;
            { c.data() } -> std::convertible_to<const_pointer>;
        }
    auto operator=(const Container &container) noexcept -> VecView & {
        assert(_size && _data);
        *_size = static_cast<size_type>(container.size());
        *_data = static_cast<const_pointer>(container.data());
        return *this;
    }
    auto operator=(const value_type &data) noexcept -> VecView &;
    template <typename T>
        requires std::same_as<value_type, AssignableHandle<T>>
    auto operator=(const value_type &data) noexcept -> VecView &;

    [[nodiscard]] auto size() const noexcept -> size_type;
    [[nodiscard]] auto empty() const noexcept -> bool;
    [[nodiscard]] auto data() const noexcept -> const_pointer;

    auto operator[](size_type idx) const noexcept -> const_reference;

    auto at(size_type idx) const -> const_reference;

    auto front() const -> const_reference;
    auto back() const -> const_reference;

    auto cbegin() const noexcept -> const_iterator;
    auto cend() const noexcept -> const_iterator;
    auto crbegin() const noexcept -> const_reverse_iterator;
    auto crend() const noexcept -> const_reverse_iterator;
};

template <typename T> class ArrayProxy {
  public:
    constexpr ArrayProxy() = default;

    constexpr ArrayProxy(std::nullptr_t) noexcept;
    ArrayProxy(T const &value) noexcept;

    ArrayProxy(uint32_t count, T const *ptr) noexcept;

    template <std::size_t C> ArrayProxy(T const (&ptr)[C]) noexcept;

#if __GNUC__ >= 9
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winit-list-lifetime"
#endif

    ArrayProxy(std::initializer_list<T> const &list) noexcept;

    template <typename B = T>
    ArrayProxy(std::initializer_list<std::remove_const_t<T>> const &list) noexcept
        requires std::is_const_v<B>
        : count(static_cast<uint32_t>(list.size())), ptr(list.begin()) {}

#if __GNUC__ >= 9
#pragma GCC diagnostic pop
#endif

    template <typename V>
    ArrayProxy(V const &v) noexcept
        requires requires(V v) {
            { v.data() } -> std::convertible_to<T *>;
            { v.size() } -> std::convertible_to<std::size_t>;
        }
        : count(static_cast<uint32_t>(v.size())), ptr(v.data()) {}

    auto begin() const noexcept -> T const *;

    auto end() const noexcept -> T const *;

    auto front() const noexcept -> T const &;

    auto back() const noexcept -> T const &;

    [[nodiscard]] auto empty() const noexcept -> bool;

    [[nodiscard]] auto size() const noexcept -> uint32_t;

    auto data() const noexcept -> T const *;

  private:
    uint32_t count = 0;
    T const *ptr = nullptr;
};
} // namespace VkBindings::impl_Struct
