#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/private/Loader.hpp"

#include <vector>

namespace VkBindings::impl_Objects {

struct Creator;

template <typename Handle_T> struct Object {
    using handle_type = Handle_T;

  protected:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatcher = nullptr;

    friend Creator;

    Object(handle_type &&handle, impl_Loader::Dispatcher *dispatcher);

  public:
    Object();
    Object(const Object &other);
    Object(Object &&other);

    auto operator=(const Object &other) noexcept -> Object & = default;
    auto operator=(Object &&other) noexcept -> Object &;

    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename Handle_T> struct ObjectWithoutFunctions {
    using handle_type = Handle_T;

    static const constexpr bool is_object = true;
    static const constexpr bool supports_dispatcher = false;

  protected:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;

    friend Creator;

    ObjectWithoutFunctions(handle_type &&handle);

  public:
    ObjectWithoutFunctions();
    ObjectWithoutFunctions(const ObjectWithoutFunctions &other);
    ObjectWithoutFunctions(ObjectWithoutFunctions &&other);

    auto operator=(const ObjectWithoutFunctions &other) noexcept -> ObjectWithoutFunctions &;
    auto operator=(ObjectWithoutFunctions &&other) noexcept -> ObjectWithoutFunctions &;

    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename DerivedObject> struct Unique {
    using object_type = DerivedObject;
    using handle_type = DerivedObject::handle_type;

    static const constexpr bool is_unique = true;

  protected:
    object_type obj;
    Unique(object_type &&obj);

    friend Creator;

  public:
    Unique();
    Unique(Unique &&other);
    auto operator=(Unique &&other) noexcept -> Unique &;
    void cleanup() noexcept; // implemented per instantiation
    // void cleanup() noexcept {
    //     if (handle != VK_BINDINGS_NULL_HANDLE) {
    //         (*Destroy_Fun)(handle, nullptr);
    //         handle = VK_BINDINGS_NULL_HANDLE;
    //     }
    // }
    ~Unique() noexcept;

    operator object_type() const noexcept;
    auto getObject() const noexcept -> const object_type;
    auto operator->() const noexcept -> const object_type *;
    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename Owner_Handle_T, typename DerivedObject> struct OwnedUnique {
    using object_type = DerivedObject;
    using handle_type = object_type::handle_type;

  protected:
    DerivedObject obj;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    OwnedUnique(DerivedObject &&obj, Owner_Handle_T o);

    friend Creator;

  public:
    OwnedUnique();
    OwnedUnique(OwnedUnique &&other);
    auto operator=(OwnedUnique &&other) noexcept -> OwnedUnique &;
    void cleanup() noexcept; // implemented per instantiation
    // {
    //     if (handle != VK_BINDINGS_NULL_HANDLE) {
    //         if constexpr (requires { (*Destroy_Fun)(owner, handle, nullptr); }) {
    //             (*Destroy_Fun)(owner, handle, nullptr);
    //         } else if constexpr (requires { (*Destroy_Fun)(owner, handle); }) {
    //             (*Destroy_Fun)(owner, handle);
    //         } else {
    //             static_assert(false);
    //         }
    //         handle = VK_BINDINGS_NULL_HANDLE;
    //         owner = VK_BINDINGS_NULL_HANDLE;
    //     }
    // }
    ~OwnedUnique() noexcept;

    operator object_type() const noexcept;
    auto getObject() const noexcept -> const object_type;
    auto operator->() const noexcept -> const object_type *;
    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename Handle_T, typename Owner_Handle_T, typename Pool_Handle_T>
struct PoolAllocatedWithoutFunctions {
    using object_type = Handle_T;
    using handle_type = typename object_type::handle_type;

    using container = std::vector<handle_type>;
    using size_type = container::size_type;
    using iterator = container::iterator;
    using const_iterator = container::const_iterator;
    using reverse_iterator = container::reverse_iterator;
    using const_reverse_iterator = container::const_reverse_iterator;

  private:
    std::vector<handle_type> handles{};
    Pool_Handle_T pool = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    PoolAllocatedWithoutFunctions(std::vector<handle_type> &&handles, Pool_Handle_T pool,
                                  Owner_Handle_T owner);

    friend Creator;

  public:
    PoolAllocatedWithoutFunctions();
    PoolAllocatedWithoutFunctions(PoolAllocatedWithoutFunctions &&other);
    auto operator=(PoolAllocatedWithoutFunctions &&other) noexcept
        -> PoolAllocatedWithoutFunctions &;
    void cleanup();
    ~PoolAllocatedWithoutFunctions() noexcept;
    explicit operator bool() const;
    auto operator[](size_t n) const -> object_type;

    [[nodiscard]] auto size() const -> size_type;
    [[nodiscard]] auto empty() const -> bool;

    [[nodiscard]] auto begin() -> iterator;
    [[nodiscard]] auto begin() const -> const_iterator;
    [[nodiscard]] auto cbegin() const -> const_iterator;

    [[nodiscard]] auto end() -> iterator;
    [[nodiscard]] auto end() const -> const_iterator;
    [[nodiscard]] auto cend() const -> const_iterator;

    [[nodiscard]] auto rbegin() -> reverse_iterator;
    [[nodiscard]] auto rbegin() const -> const_reverse_iterator;
    [[nodiscard]] auto crbegin() const -> const_reverse_iterator;

    [[nodiscard]] auto rend() -> reverse_iterator;
    [[nodiscard]] auto rend() const -> const_reverse_iterator;
    [[nodiscard]] auto crend() const -> const_reverse_iterator;
};

template <typename Handle_T, typename Owner_Handle_T, typename Pool_Handle_T> struct PoolAllocated {
    using object_type = Handle_T;
    using handle_type = typename object_type::handle_type;

    using container = std::vector<handle_type>;
    using size_type = container::size_type;
    using iterator = container::iterator;
    using const_iterator = container::const_iterator;
    using reverse_iterator = container::reverse_iterator;
    using const_reverse_iterator = container::const_reverse_iterator;

  private:
    std::vector<handle_type> handles{};
    Pool_Handle_T pool = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatcher;

    PoolAllocated(std::vector<handle_type> &&handles, Pool_Handle_T pool, Owner_Handle_T owner,
                  impl_Loader::Dispatcher *dispatcher);

    friend Creator;

  public:
    PoolAllocated();
    PoolAllocated(PoolAllocated &&other);
    auto operator=(PoolAllocated &&other) noexcept -> PoolAllocated &;
    void cleanup();
    ~PoolAllocated() noexcept;
    explicit operator bool() const;
    auto operator[](size_t n) const -> object_type;

    [[nodiscard]] auto size() const -> size_type;
    [[nodiscard]] auto empty() const -> bool;

    [[nodiscard]] auto begin() -> iterator;
    [[nodiscard]] auto begin() const -> const_iterator;
    [[nodiscard]] auto cbegin() const -> const_iterator;

    [[nodiscard]] auto end() -> iterator;
    [[nodiscard]] auto end() const -> const_iterator;
    [[nodiscard]] auto cend() const -> const_iterator;

    [[nodiscard]] auto rbegin() -> reverse_iterator;
    [[nodiscard]] auto rbegin() const -> const_reverse_iterator;
    [[nodiscard]] auto crbegin() const -> const_reverse_iterator;

    [[nodiscard]] auto rend() -> reverse_iterator;
    [[nodiscard]] auto rend() const -> const_reverse_iterator;
    [[nodiscard]] auto crend() const -> const_reverse_iterator;
};

} // namespace VkBindings::impl_Objects
