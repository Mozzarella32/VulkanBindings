#pragma once

#include "FunctionTables.hpp"
#include "VkBindings/Defines.hpp"

#include <utility>
#include <vector>

namespace VkBindings {
namespace impl_Objects {
template <typename Table_T, bool HasTable, bool IsOwner> struct TableBase;

template <typename Table_T, bool IsOwner> struct TableBase<Table_T, false, IsOwner> {
    static_assert(IsOwner == false);
};

template <typename Table_T> struct TableBase<Table_T, true, true> {
    Table_T table;
};

template <typename Table_T> struct TableBase<Table_T, true, false> {
    Table_T *table;
};

template <typename Handle_T, auto Destroy_Fun, typename Creator_T> struct Unique {
    using handle_type = Handle_T;

  protected:
    Handle_T handle = VK_BINDINGS_NULL_HANDLE;
    Unique(Handle_T &&h) : handle(h) {}

    friend Creator_T;

  public:
    Unique() {}
    Unique(Unique &&other) : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)) {}
    Unique &operator=(Unique &&other) noexcept {
        cleanup();
        handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    }
    void cleanup() noexcept {
        if (handle != VK_BINDINGS_NULL_HANDLE) {
            (*Destroy_Fun)(handle, nullptr);
            handle = VK_BINDINGS_NULL_HANDLE;
        }
    }
    ~Unique() noexcept { cleanup(); }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_BINDINGS_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, auto Destroy_Fun>
struct OwnedUnique {
    using handle_type = Handle_T;

  protected:
    // Order is very importent for ABI
    Handle_T handle = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;
    OwnedUnique(Handle_T &&h, Owner_Handle_T o) : handle(h), owner(o) {}

    friend Owner_T;

  public:
    OwnedUnique() {}
    OwnedUnique(OwnedUnique &&other)
        : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)),
          owner(std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE)) {}
    OwnedUnique &operator=(OwnedUnique &&other) noexcept {
        cleanup();
        handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
        owner = std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE);
    }
    void cleanup() noexcept {
        if (handle != VK_BINDINGS_NULL_HANDLE) {
            if constexpr (requires { (*Destroy_Fun)(owner, handle, nullptr); }) {
                (*Destroy_Fun)(owner, handle, nullptr);
            } else if constexpr (requires { (*Destroy_Fun)(owner, handle); }) {
                (*Destroy_Fun)(owner, handle);
            } else {
                static_assert(false);
            }
            handle = VK_BINDINGS_NULL_HANDLE;
            owner = VK_BINDINGS_NULL_HANDLE;
        }
    }
    ~OwnedUnique() noexcept { cleanup(); }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_BINDINGS_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template <typename Handle_T> struct NonOwned {
    using handle_type = Handle_T;

  protected:
    Handle_T handle{VK_BINDINGS_NULL_HANDLE};
    NonOwned(Handle_T &&handle) : handle(std::move(handle)) {}

  public:
    NonOwned() {}

    Handle_T get() const noexcept { return handle; }
    operator Handle_T() const { return handle; }
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T,
          auto Free_fun>
struct PoolAllocated {
    using handle_type = typename Handle_T::handle_type;
    bool is_pool_allocated = true;

  private:
    std::vector<Handle_T> handles{};
    Pool_Handle_T pool = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    PoolAllocated(std::vector<Handle_T> &&handles, Pool_Handle_T pool, Owner_Handle_T owner)
        : handles(std::move(handles)), pool(pool), owner(owner) {}

    friend Owner_T;

  public:
    PoolAllocated() {}
    PoolAllocated(PoolAllocated &&other)
        : handles(std::exchange(other.handles, {})),
          pool(std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE)),
          owner(std::exchange(other.owner), VK_BINDINGS_NULL_HANDLE) {}
    PoolAllocated &operator=(PoolAllocated &&other) noexcept {
        cleanup();
        handles = std::exchange(other.handles, {});
        pool = std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE);
        owner = std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE);
    }
    void cleanup() {
        if (!handles.empty()) {
            (*Free_fun)(owner, pool, handles.size(), handles.data());
            handles.clear();
            pool = VK_BINDINGS_NULL_HANDLE;
            owner = VK_BINDINGS_NULL_HANDLE;
        }
    }
    ~PoolAllocated() noexcept { cleanup(); }
    explicit operator bool() const { return !handles.empty(); }
    Handle_T &operator[](size_t n) {
        assert(n < handles.size());
        return handles[n];
    }
    const Handle_T &operator[](size_t n) const {
        assert(n < handles.size());
        return handles[n];
    }
    decltype(handles)::iterator begin() { return handles.begin(); }
    decltype(handles)::iterator end() { return handles.end(); }
    decltype(handles)::const_iterator cbegin() const { return handles.cbegin(); }
    decltype(handles)::const_iterator cend() const { return handles.cend(); }
    decltype(handles)::reverse_iterator rbegin() { return handles.rbegin(); }
    decltype(handles)::reverse_iterator rend() { return handles.rend(); }
    decltype(handles)::const_reverse_iterator crbegin() const { return handles.crbegin(); }
    decltype(handles)::const_reverse_iterator crend() const { return handles.crend(); }
};

} // namespace impl_Objects
} // namespace VkBindings
