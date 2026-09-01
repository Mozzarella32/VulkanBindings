
#pragma once

#include "AssignableHandleInterface.hpp"
#include "VkBindings/Concepts.hpp"
#include "VkBindings/Reflection/HandleToObject.hpp"

#include <cassert>
#include <concepts>
#include <type_traits>

namespace VkBindings::impl_Struct {

struct LayoutChecker;
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

    // NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
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
        *_data = reinterpret_cast<const_pointer>(std::forward<Container>(container).data());
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
        *_data = reinterpret_cast<const AssignableHandle<
            Reflections::HandleToObject<typename value_type::handle_type>> *>(
            &std::forward<T>(data));
        return *this;
    }
    // NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)

    [[nodiscard]] auto size() const noexcept -> size_type;
    [[nodiscard]] auto empty() const noexcept -> bool;
    [[nodiscard]] auto data() const noexcept -> const_pointer;

    auto operator[](size_type idx) const noexcept -> const_reference;

    auto at(size_type idx) const -> const_reference;

    auto front() const -> const_reference;
    auto back() const -> const_reference;

    auto cbegin() const noexcept -> const_iterator;
    auto cend() const noexcept -> const_iterator;
};

} // namespace VkBindings::impl_Struct
