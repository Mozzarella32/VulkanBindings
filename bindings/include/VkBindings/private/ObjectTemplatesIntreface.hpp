#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/StructsForward.hpp"
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

    Object(handle_type &&handle, impl_Loader::Dispatcher *dispatcher) noexcept;

  public:
    Object() noexcept;
    Object(const Object &other) noexcept;
    Object(Object &&other) noexcept;

    auto operator=(const Object &other) noexcept -> Object & = default;
    auto operator=(Object &&other) noexcept -> Object &;

    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename Handle_T> struct ObjectWithoutFunctions {
    using handle_type = Handle_T;

  protected:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;

    friend Creator;

    ObjectWithoutFunctions(handle_type &&handle) noexcept;

  public:
    ObjectWithoutFunctions() noexcept;
    ObjectWithoutFunctions(const ObjectWithoutFunctions &other) noexcept;
    ObjectWithoutFunctions(ObjectWithoutFunctions &&other) noexcept;

    auto operator=(const ObjectWithoutFunctions &other) noexcept -> ObjectWithoutFunctions &;
    auto operator=(ObjectWithoutFunctions &&other) noexcept -> ObjectWithoutFunctions &;

    operator handle_type() const noexcept;
    auto getHandle() const noexcept -> handle_type;
    explicit operator bool() const noexcept;
};

template <typename BaseObject> struct Unique : public BaseObject {
    using object_type = BaseObject;

  protected:
    const AllocationCallbacks *allocationCallbacks = nullptr;
    Unique(object_type &&obj, const AllocationCallbacks *allocationCallbacks) noexcept;

    friend Creator;

  public:
    Unique() noexcept;
    Unique(Unique &&other) noexcept;
    auto operator=(Unique &&other) noexcept -> Unique &;
    void cleanup() noexcept;
    ~Unique() noexcept;

    operator object_type() const noexcept;
    auto getObject() const noexcept -> const object_type;
};

template <typename Owner_T, typename BaseObject> struct OwnedUnique : public BaseObject {
    using object_type = BaseObject;

  protected:
    const AllocationCallbacks *allocationCallbacks = nullptr;
    Owner_T owner;

    OwnedUnique(BaseObject &&obj, Owner_T o,
                const AllocationCallbacks *allocationCallbacks) noexcept;

    friend Creator;

  public:
    OwnedUnique() noexcept;
    OwnedUnique(OwnedUnique &&other) noexcept;
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
};

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
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
    Owner_T owner;

    PoolAllocatedWithoutFunctions(std::vector<handle_type> &&handles, Pool_Handle_T pool,
                                  Owner_T owner);

    friend Creator;

  public:
    PoolAllocatedWithoutFunctions();
    PoolAllocatedWithoutFunctions(PoolAllocatedWithoutFunctions &&other);
    auto operator=(PoolAllocatedWithoutFunctions &&other) noexcept
        -> PoolAllocatedWithoutFunctions &;
    void cleanup() noexcept;
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

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T> struct PoolAllocated {
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
    Owner_T owner;
    impl_Loader::Dispatcher *dispatcher;

    PoolAllocated(std::vector<handle_type> &&handles, Pool_Handle_T pool, Owner_T owner,
                  impl_Loader::Dispatcher *dispatcher);

    friend Creator;

  public:
    PoolAllocated();
    PoolAllocated(PoolAllocated &&other);
    auto operator=(PoolAllocated &&other) noexcept -> PoolAllocated &;
    void cleanup() noexcept;
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
