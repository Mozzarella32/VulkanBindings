#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/private/Loader.hpp"

#include <utility>
#include <vector>

namespace VkBindings {
namespace impl_Objects {

template <typename D>
concept HasDispatcher = D::supports_dispatcher;

template <typename D>
concept HasHandleConstructor = D::has_handle_constructor;

template <typename Handle_T, typename Creator_T> struct Object {
    using handle_type = Handle_T;

    static const constexpr bool supports_dispatcher = true;

  protected:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;
    impl_Loader::Dispatcher *dispatcher = nullptr;

    friend Creator_T;

    Object(handle_type &&handle, impl_Loader::Dispatcher *dispatcher);

  public:
    Object();
    Object(Object &&other);

    Object &operator=(Object &&other) noexcept;

    handle_type get() const noexcept;
    handle_type *rawHandlePtr() noexcept;
    const handle_type *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator handle_type() const noexcept;
};

template <typename Handle_T, typename Creator_T> struct ObjectWithoutFunctions {
    using handle_type = Handle_T;

    static const constexpr bool supports_dispatcher = false;

  protected:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;

    friend Creator_T;

    ObjectWithoutFunctions(handle_type &&handle);

  public:
    ObjectWithoutFunctions();
    ObjectWithoutFunctions(ObjectWithoutFunctions &&other);

    ObjectWithoutFunctions &operator=(ObjectWithoutFunctions &&other) noexcept;

    handle_type get() const noexcept;
    handle_type *rawHandlePtr() noexcept;
    const handle_type *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator handle_type() const noexcept;
};

template <typename Creator_T, typename DerivedObject> struct Unique {
    using handle_type = DerivedObject::handle_type;

  protected:
    DerivedObject obj;
    Unique(DerivedObject &&obj);

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

    handle_type get() const noexcept;
    handle_type *rawHandlePtr() noexcept;
    const handle_type *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator handle_type() const noexcept;
};

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject> struct OwnedUnique {
    using handle_type = DerivedObject::handle_type;

  protected:
    DerivedObject obj;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    OwnedUnique(DerivedObject &&obj, Owner_Handle_T o);

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

    handle_type get() const noexcept;
    handle_type *rawHandlePtr() noexcept;
    const handle_type *rawHandlePtr() const noexcept;
    explicit operator bool() const noexcept;
    operator handle_type() const noexcept;
};

// template <typename Handle_T, typename> struct NonOwned {
//     using handle_type = Handle_T;

//   protected:

//     Handle_T handle{VK_BINDINGS_NULL_HANDLE};
//     impl_Loader::Dispatcher *dispatcher;

//     NonOwned(Handle_T &&handle, impl_Loader::Dispatcher *dispatcher);

//   public:
//     NonOwned();

//     Handle_T get() const noexcept;
//     Handle_T *rawHandlePtr() noexcept;
//     const Handle_T *rawHandlePtr() const noexcept;
//     operator Handle_T() const noexcept;
// };

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
    std::vector<handle_type> handles{};
    Pool_Handle_T pool = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T owner = VK_BINDINGS_NULL_HANDLE;

    PoolAllocated(std::vector<handle_type> &&handles, Pool_Handle_T pool, Owner_Handle_T owner);

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
