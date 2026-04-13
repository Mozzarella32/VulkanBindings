#pragma once

#include "FunctionTables.hpp"
#include "Loader.hpp"
#include "VkBindings/Defines.hpp"

#include <utility>
#include <vector>

namespace VkBindings {
namespace impl_Objects {

template <typename Handle_T, typename Creator_T> struct Unique {
    using handle_type = Handle_T;

  protected:
    Handle_T handle = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatch;

    Unique(Handle_T &&h, impl_Loader::Dispatcher *dispatch);

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
    Handle_T *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T> struct OwnedUnique {
    using handle_type = Handle_T;

  protected:
    // Order is very importent for ABI
    Handle_T handle = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatch;

    OwnedUnique(Handle_T &&h, Owner_Handle_T o, impl_Loader::Dispatcher *dispatch);

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
    Handle_T *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T> struct NonOwned {
    using handle_type = Handle_T;

  protected:
    Handle_T handle{VK_BINDINGS_NULL_HANDLE};
    impl_Loader::Dispatcher *dispatch;

    NonOwned(Handle_T &&handle, impl_Loader::Dispatcher* dispatch);

  public:
    NonOwned();

    Handle_T get() const noexcept;
    Handle_T *rawHandlePtr() const noexcept;
    operator Handle_T() const noexcept;
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
struct PoolAllocated {
    using handle_type = typename Handle_T::handle_type;
    bool is_pool_allocated = true;

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
    decltype(handles)::iterator begin();
    decltype(handles)::iterator end();
    decltype(handles)::const_iterator cbegin() const;
    decltype(handles)::const_iterator cend() const;
    decltype(handles)::reverse_iterator rbegin();
    decltype(handles)::reverse_iterator rend();
    decltype(handles)::const_reverse_iterator crbegin() const;
    decltype(handles)::const_reverse_iterator crend() const;
};

} // namespace impl_Objects
} // namespace VkBindings
