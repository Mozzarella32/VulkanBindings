#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/private/Loader.hpp"

#include <vector>

namespace VkBindings::impl_Objects {

template <typename Handle_T, typename Creator_T> struct Object {
    using handle_type = Handle_T;

  protected:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatcher = nullptr;

    friend Creator_T;

    Object(handle_type &&handle, impl_Loader::Dispatcher *dispatcher);

  public:
    Object();
    Object(const Object &other);
    Object(Object &&other);

    auto operator=(const Object &other) noexcept -> Object &;
    auto operator=(Object &&other) noexcept -> Object &;

    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename Handle_T, typename Creator_T> struct ObjectWithoutFunctions {
    using handle_type = Handle_T;

    static const constexpr bool is_object = true;
    static const constexpr bool supports_dispatcher = false;

  protected:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;

    friend Creator_T;

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

template <typename Creator_T, typename DerivedObject> struct Unique {
    using object_type = DerivedObject;
    using handle_type = DerivedObject::handle_type;

    static const constexpr bool is_unique = true;

  protected:
    DerivedObject obj;
    Unique(DerivedObject &&obj);

    friend Creator_T;

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
    auto getObject() const noexcept -> object_type;
    auto operator->() const noexcept -> object_type;
    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject> struct OwnedUnique {
    using object_type = DerivedObject;
    using handle_type = DerivedObject::handle_type;

  protected:
    DerivedObject obj;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    OwnedUnique(DerivedObject &&obj, Owner_Handle_T o);

    friend Owner_T;

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
    auto getObject() const noexcept -> object_type;
    auto operator->() const noexcept -> object_type;
    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
struct PoolAllocated {
    using object_type = Handle_T;
    using handle_type = typename Handle_T::handle_type;

    using container = std::vector<Handle_T>;
    using iterator = container::iterator;
    using const_iterator = container::const_iterator;
    using reverse_iterator = container::reverse_iterator;
    using const_reverse_iterator = container::const_reverse_iterator;

  private:
    std::vector<handle_type> handles{};
    Pool_Handle_T pool = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    PoolAllocated(std::vector<handle_type> &&handles, Pool_Handle_T pool, Owner_Handle_T owner);

    friend Owner_T;

  public:
    PoolAllocated();
    PoolAllocated(PoolAllocated &&other);
    auto operator=(PoolAllocated &&other) noexcept -> PoolAllocated &;
    void cleanup();
    ~PoolAllocated() noexcept;
    explicit operator bool() const;
    auto operator[](size_t n) -> object_type &;
    auto operator[](size_t n) const -> const object_type &;
    auto begin() -> iterator;
    auto end() -> iterator;
    auto cbegin() const -> const_iterator;
    auto cend() const -> const_iterator;
    auto rbegin() -> reverse_iterator;
    auto rend() -> reverse_iterator;
    auto crbegin() const -> const_reverse_iterator;
    auto crend() const -> const_reverse_iterator;
};

} // namespace VkBindings::impl_Objects
