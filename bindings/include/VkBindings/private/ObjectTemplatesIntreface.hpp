#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

#include <utility>
#include <vector>

namespace VkBindings {
namespace impl_Objects {

template <typename Handle_T, typename Creator_T> struct Unique {
    using handle_type = Handle_T;

  protected:
    Handle_T handle = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatcher;

    Unique(Handle_T &&h, impl_Loader::Dispatcher *dispatcher);

    friend Creator_T;

  public:
    Unique();
    Unique(Unique &&other);
    Unique &operator=(Unique &&other) noexcept;
    void cleanup() noexcept; // implemented per instantiation
    // void cleanup() noexcept {
    //     if (handle != VK_BINDINGS_NULL_HANDLE) {
    //         (*Destroy_Fun)(handle, nullptr);
    //         handle = VK_BINDINGS_NULL_HANDLE;
    //     }
    // }
    ~Unique() noexcept;

    Handle_T get() const noexcept;
    Handle_T *rawHandlePtr() noexcept;
    const Handle_T *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T> struct OwnedUnique {
    using handle_type = Handle_T;

  protected:
    // Order is very importent for ABI
    Handle_T handle = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatcher;

    OwnedUnique(Handle_T &&h, Owner_Handle_T o, impl_Loader::Dispatcher *dispatcher);

    friend Owner_T;

  public:
    OwnedUnique();
    OwnedUnique(OwnedUnique &&other);
    OwnedUnique &operator=(OwnedUnique &&other) noexcept;
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

    Handle_T get() const noexcept;
    Handle_T *rawHandlePtr() noexcept;
    const Handle_T *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
struct OwnedUniqueWithoutFunctions {
    using handle_type = Handle_T;

  protected:
    // Order is very importent for ABI
    Handle_T handle = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    OwnedUniqueWithoutFunctions(Handle_T &&h, Owner_Handle_T o);

    friend Owner_T;

  public:
    OwnedUniqueWithoutFunctions();
    OwnedUniqueWithoutFunctions(OwnedUniqueWithoutFunctions &&other);
    OwnedUniqueWithoutFunctions &operator=(OwnedUniqueWithoutFunctions &&other) noexcept;
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
    ~OwnedUniqueWithoutFunctions() noexcept;

    Handle_T get() const noexcept;
    Handle_T *rawHandlePtr() noexcept;
    const Handle_T *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T> struct NonOwned {
    using handle_type = Handle_T;

  protected:
    Handle_T handle{VK_BINDINGS_NULL_HANDLE};
    impl_Loader::Dispatcher *dispatcher;

    NonOwned(Handle_T &&handle, impl_Loader::Dispatcher *dispatcher);

  public:
    NonOwned();

    Handle_T get() const noexcept;
    Handle_T *rawHandlePtr() noexcept;
    const Handle_T *rawHandlePtr() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T, typename Creator_T> struct NonOwnedWithoutFunctions {
    using handle_type = Handle_T;

  protected:
    Handle_T handle{VK_BINDINGS_NULL_HANDLE};

    NonOwnedWithoutFunctions(Handle_T &&handle);
    friend Creator_T;

  public:
    NonOwnedWithoutFunctions();

    Handle_T get() const noexcept;
    Handle_T *rawHandlePtr() noexcept;
    const Handle_T *rawHandlePtr() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
struct PoolAllocated {
    using handle_type = typename Handle_T::handle_type;
    bool is_pool_allocated = true;

    using container = std::vector<Handle_T>;
    using iterator = container::iterator;
    using const_iterator = container::const_iterator;
    using reverse_iterator = container::reverse_iterator;
    using const_reverse_iterator = container::const_reverse_iterator;

  private:
    std::vector<Handle_T> handles{};
    Pool_Handle_T pool = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    PoolAllocated(std::vector<Handle_T> &&handles, Pool_Handle_T pool, Owner_Handle_T owner);

    friend Owner_T;

  public:
    PoolAllocated();
    PoolAllocated(PoolAllocated &&other);
    PoolAllocated &operator=(PoolAllocated &&other) noexcept;
    void cleanup();
    ~PoolAllocated() noexcept;
    explicit operator bool() const;
    Handle_T &operator[](size_t n);
    const Handle_T &operator[](size_t n) const;
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};

} // namespace impl_Objects
} // namespace VkBindings
