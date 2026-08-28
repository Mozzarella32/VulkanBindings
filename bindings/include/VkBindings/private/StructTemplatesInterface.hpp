#pragma once

#include "VkBindings/Concepts.hpp"
#include "VkBindings/Defines.hpp"
#include "VkBindings/Reflection/HandleToObject.hpp"
#include "VkBindings/Reflection/IsObject.hpp"
#include "VkBindings/Reflection/ObjectToHandle.hpp"

#include <array>
#include <cassert>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <initializer_list>
#include <iterator>
#include <string>
#include <string_view>
#include <type_traits>

namespace VkBindings::impl_Struct {

struct LayoutChecker;

template <Concepts::IsObject Obj> struct AssignableHandle {
    using handle_type = Reflections::ObjectToHandle<Obj>;
    using object_type = Obj;

  private:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;

    friend LayoutChecker;

  public:
    AssignableHandle() = default;

    AssignableHandle(handle_type handle) noexcept;
    AssignableHandle(object_type object) noexcept;

    auto operator=(handle_type handle) noexcept -> AssignableHandle &;
    auto operator=(object_type object) noexcept -> AssignableHandle &;

    [[nodiscard]] auto getHandle() const -> const handle_type &;

    operator handle_type() const;
};

struct InOutString {
  private:
    const char *pStr = nullptr;

    friend LayoutChecker;

  public:
    InOutString() = default;
    InOutString(const std::string &str) : pStr(str.data()) {}
    InOutString(const char *cStr) : pStr(cStr) {}

    auto operator=(const std::string &str) -> InOutString & {
        pStr = str.data();
        return *this;
    }
    auto operator=(const char *cStr) -> InOutString & {
        pStr = cStr;
        return *this;
    }

    operator std::string() const { return {pStr}; }
    operator std::string_view() const { return {pStr}; }
    operator const char *() const { return pStr; }

    [[nodiscard]] auto to_string() const -> std::string { return *this; }
    [[nodiscard]] auto to_string_view() const -> std::string_view { return *this; }
    [[nodiscard]] auto to_c_str() const -> const char * { return *this; }
};

template <std::size_t N> struct FixedString {
    static_assert(N > 0, "FixedString size must be > 0");

  private:
    std::array<char, N> data;

    friend LayoutChecker;

  public:
    auto operator=(std::string_view stringView) noexcept -> FixedString &;

    auto operator=(const std::string &string) noexcept -> FixedString &;

    auto operator=(const char *stringLiteral) noexcept -> FixedString &;

    operator std::string() const noexcept;

    // NOLINTBEGIN(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
    template <std::size_t M> auto operator=(const char (&lit)[M]) noexcept -> FixedString &;
    // NOLINTEND(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
};

template <typename Size_T> struct POD {
    using size_type = Size_T;

  private:
    size_type _size;
    const void *_data;

  public:
    template <typename T>
        requires std::is_standard_layout_v<T>
    POD(const T &obj) : _size(sizeof(T)), _data(std::addressof(obj)) {}

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

    VecView(size_type *size, const_pointer *data) noexcept;

    template <typename Container>
        requires requires(const Container &container) {
            { container.size() } -> std::convertible_to<size_type>;
            { container.data() } -> std::convertible_to<const_pointer>;
            requires std::is_lvalue_reference_v<Container &&>;
        }
    auto operator=(Container &&container) noexcept -> VecView & {
        assert(_size && _data);
        *_size = static_cast<size_type>(std::forward<Container>(container).size());
        *_data = static_cast<const_pointer>(std::forward<Container>(container).data());
        return *this;
    }

    template <typename Container>
        requires requires(const Container &container) {
            // Is a AssignableHandle
            requires std::same_as<
                AssignableHandle<Reflections::HandleToObject<typename value_type::handle_type>>,
                value_type>;
            // has size
            { container.size() } -> std::convertible_to<size_type>;
            // to reduce ambiguous overload set
            requires(!std::convertible_to<decltype(container.data()), const_pointer>);
            // has value_type
            typename std::remove_reference_t<Container>::value_type;
            // is value_type is ABI compatable with Handle
            requires Concepts::ABIIsHandle<typename std::remove_reference_t<Container>::value_type>;
            // Disallow rvalues
            requires std::is_lvalue_reference_v<Container &&>;
        }
    auto operator=(Container &&container) noexcept -> VecView & {
        assert(_size && _data);
        *_size = static_cast<size_type>(std::forward<Container>(container).size());
        *_data = std::bit_cast<const_pointer>(std::forward<Container>(container).data());
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
            &std::forward<T>(data));
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

template <typename T> struct ArrayProxy {
  public:
    constexpr ArrayProxy() = default;

    constexpr ArrayProxy(std::nullptr_t) noexcept;
    ArrayProxy(T const &value) noexcept;

    ArrayProxy(std::uint32_t count, T const *ptr) noexcept;

    template <typename V>
    ArrayProxy(V &val) noexcept
        requires(requires { typename T::handle_type; } &&
                 std::same_as<
                     T, AssignableHandle<Reflections::HandleToObject<typename T::handle_type>>> &&
                 std::same_as<std::remove_cvref_t<V>,
                              Reflections::HandleToObject<typename T::handle_type>> &&
                 Concepts::ABIIsHandle<std::remove_cvref_t<V>>)
        : count(1), ptr(std::bit_cast<T const *>(std::addressof(val))) {}

    // NOLINTBEGIN(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)
    template <std::size_t C> ArrayProxy(T const (&ptr)[C]) noexcept;
    // NOLINTEND(modernize-avoid-c-arrays, cppcoreguidelines-avoid-c-arrays)

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
        : count(static_cast<std::uint32_t>(list.size())),
        ptr(std::bit_cast<T const *>(list.begin())) {}

#if __GNUC__ >= 9
#pragma GCC diagnostic pop
#endif

    template <typename V>
    ArrayProxy(V const &val) noexcept
        requires requires(V val) {
            { val.data() } -> std::convertible_to<T *>;
            { val.size() } -> std::convertible_to<std::size_t>;
        }
        : count(static_cast<std::size_t>(val.size())), ptr(val.data()) {}

    auto begin() const noexcept -> T const *;

    auto end() const noexcept -> T const *;

    auto front() const noexcept -> T const &;

    auto back() const noexcept -> T const &;

    [[nodiscard]] auto empty() const noexcept -> bool;

    [[nodiscard]] auto size() const noexcept -> std::uint32_t;

    auto data() const noexcept -> T const *;

  private:
    std::size_t count = 0;
    T const *ptr = nullptr;
};
} // namespace VkBindings::impl_Struct
