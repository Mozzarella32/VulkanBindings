#pragma once

#include "VkBindings/Concepts.hpp"
#include "VkBindings/Defines.hpp"
#include "VkBindings/Reflection/HandleToObject.hpp"
#include "VkBindings/Reflection/IsObject.hpp"
#include "VkBindings/Reflection/ObjectToHandle.hpp"

#include <array>
#include <cassert>
#include <cstring>
#include <string>

namespace VkBindings::impl_Struct {

template <Concepts::IsObject Obj> struct AssignableHandle {
    using handle_type = Reflections::ObjectToHandle<Obj>;

    handle_type handle = VK_BINDINGS_NULL_HANDLE;

    AssignableHandle() = default;

    AssignableHandle(handle_type h) noexcept;

    auto operator=(handle_type h) noexcept -> AssignableHandle &;
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

    // NOLINTBEGIN(modernize-avoid-c-arrays)
    template <std::size_t M> auto operator=(const char (&lit)[M]) noexcept -> FixedString &;
    // NOLINTEND(modernize-avoid-c-arrays)
};

template <typename Size_T> struct POD {
    using size_type = Size_T;

    size_type _size;
    const void *_data;

    template <typename T>
        requires std::is_standard_layout_v<T>
    POD(const T &t) : _size(sizeof(T)), _data(std::addressof(t)) {}

    [[nodiscard]] auto data() const -> const void * { return _data; }
    [[nodiscard]] auto size() const -> size_type { return _size; }
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
            requires std::is_lvalue_reference_v<Container &&>;
        }
    auto operator=(Container &&container) noexcept -> VecView & {
        assert(_size && _data);
        *_size = static_cast<size_type>(container.size());
        *_data = static_cast<const_pointer>(container.data());
        return *this;
    }

    template <typename Container>
        requires requires(const Container &c) {
            // Is a AssignableHandle
            requires std::same_as<
                AssignableHandle<Reflections::HandleToObject<typename value_type::handle_type>>,
                value_type>;
            // has size
            { c.size() } -> std::convertible_to<size_type>;
            // to reduce ambiguous overload set
            requires(!std::convertible_to<decltype(c.data()), const_pointer>);
            // has value_type
            typename std::remove_reference_t<Container>::value_type;
            // is value_type is ABI compatable with Handle
            requires Concepts::ABIIsHandle<typename std::remove_reference_t<Container>::value_type>;
            // Disallow rvalues
            requires std::is_lvalue_reference_v<Container &&>;
        }
    auto operator=(Container &&container) noexcept -> VecView & {
        assert(_size && _data);
        *_size = static_cast<size_type>(container.size());
        *_data = std::bit_cast<const_pointer>(container.data());
        return *this;
    }

    auto operator=(const value_type &data) noexcept -> VecView &;

    template <typename T>
    auto operator=(T &&data) noexcept -> VecView &
        requires
        // is Assignable Handle
        std::same_as<
            AssignableHandle<Reflections::HandleToObject<typename value_type::handle_type>>,
            value_type> &&
        // Extract object from Arg
        std::same_as<Reflections::HandleToObject<typename value_type::handle_type>,
                     std::remove_cvref_t<T>> &&
        // Is ABI compatable to Handle
        Concepts::ABIIsHandle<Reflections::HandleToObject<typename value_type::handle_type>> &&
        // Disallow rvalues
        std::is_lvalue_reference_v<T &&>

    {
        assert(_size && _data);
        *_size = 1;
        *_data = std::bit_cast<
            AssignableHandle<Reflections::HandleToObject<typename value_type::handle_type>> *>(
            &data);
        return *this;
    }

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

    template <typename V>
    ArrayProxy(V &v) noexcept
        requires(requires { typename T::handle_type; } &&
                 std::same_as<
                     T, AssignableHandle<Reflections::HandleToObject<typename T::handle_type>>> &&
                 std::same_as<std::remove_cvref_t<V>,
                              Reflections::HandleToObject<typename T::handle_type>> &&
                 Concepts::ABIIsHandle<std::remove_cvref_t<V>>)
        : count(1), ptr(std::bit_cast<T const *>(std::addressof(v))) {}

    // NOLINTBEGIN(modernize-avoid-c-arrays)
    template <std::size_t C> ArrayProxy(T const (&ptr)[C]) noexcept;
    // NOLINTEND(modernize-avoid-c-arrays)

#if __GNUC__ >= 9
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winit-list-lifetime"
#endif

    ArrayProxy(std::initializer_list<T> const &list) noexcept;

    template <typename B = T>
    ArrayProxy(std::initializer_list<std::remove_const_t<T>> const &list) noexcept
        requires std::is_const_v<B>
        : count(static_cast<std::size_t>(list.size())), ptr(list.begin()) {}

    template <typename U>
        requires
        // T must be AssignableHandle<Obj>
        requires { typename T::handle_type; } &&
            std::same_as<T,
                         AssignableHandle<Reflections::HandleToObject<typename T::handle_type>>> &&
            // U must be that Obj type
            std::same_as<std::remove_cvref_t<U>,
                         Reflections::HandleToObject<typename T::handle_type>> &&
            // Obj must be ABI-compatible with handle
            Concepts::ABIIsHandle<Reflections::HandleToObject<typename T::handle_type>>
            ArrayProxy(std::initializer_list<U> const &list) noexcept
        : count(static_cast<uint32_t>(list.size())),
        ptr(std::bit_cast<T const *>(list.begin())) {}

#if __GNUC__ >= 9
#pragma GCC diagnostic pop
#endif

    template <typename V>
    ArrayProxy(V const &v) noexcept
        requires requires(V v) {
            { v.data() } -> std::convertible_to<T *>;
            { v.size() } -> std::convertible_to<std::size_t>;
        }
        : count(static_cast<std::size_t>(v.size())), ptr(v.data()) {}

    auto begin() const noexcept -> T const *;

    auto end() const noexcept -> T const *;

    auto front() const noexcept -> T const &;

    auto back() const noexcept -> T const &;

    [[nodiscard]] auto empty() const noexcept -> bool;

    [[nodiscard]] auto size() const noexcept -> uint32_t;

    auto data() const noexcept -> T const *;

  private:
    std::size_t count = 0;
    T const *ptr = nullptr;
};
} // namespace VkBindings::impl_Struct
