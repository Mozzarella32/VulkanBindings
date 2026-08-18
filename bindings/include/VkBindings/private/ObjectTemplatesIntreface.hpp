#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

#include <cstddef>
#include <vector>

namespace VkBindings::impl_Objects {

struct Creator;

template <typename Handle_T> struct Object {
    using handle_type = Handle_T;

  private:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;
    const impl_Loader::Dispatcher *dispatcher = nullptr;

  protected:
    [[nodiscard]] auto getInstanceTable() const -> const impl_Loader::InstanceTable &;
    [[nodiscard]] auto getDeviceTable() const -> const impl_Loader::DeviceTable &;
    [[nodiscard]] auto getDispatcher() const -> const impl_Loader::Dispatcher &;
    void setDispatcher(const impl_Loader::Dispatcher &dispatcher);

  public:
    [[nodiscard]] auto getHandle() const -> const handle_type &;

  protected:
    friend Creator;

    Object(handle_type &&handle, const impl_Loader::Dispatcher &dispatcher);

  public:
    Object();

    Object(const Object &other) noexcept;
    Object(Object &&other) noexcept;

    auto operator=(const Object &other) noexcept -> Object & = default;
    auto operator=(Object &&other) noexcept -> Object &;

    ~Object() noexcept;

    operator handle_type() const noexcept;
    explicit operator bool() const noexcept;
};

template <typename Handle_T> struct ObjectWithoutFunctions {
    using handle_type = Handle_T;

  private:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;

  public:
    [[nodiscard]] auto getHandle() const -> const handle_type &;

  protected:
    friend Creator;

    ObjectWithoutFunctions(handle_type &&handle);

  public:
    ObjectWithoutFunctions();

    ObjectWithoutFunctions(const ObjectWithoutFunctions &other) noexcept;
    ObjectWithoutFunctions(ObjectWithoutFunctions &&other) noexcept;

    auto operator=(const ObjectWithoutFunctions &other) noexcept -> ObjectWithoutFunctions &;
    auto operator=(ObjectWithoutFunctions &&other) noexcept -> ObjectWithoutFunctions &;

    ~ObjectWithoutFunctions() noexcept;

    operator handle_type() const noexcept;
    explicit operator bool() const noexcept;
};

template <typename BaseObject> struct Unique : public BaseObject {
    using object_type = BaseObject;

  private:
    const AllocationCallbacks *allocationCallbacks;

  protected:
    Unique(object_type &&obj, const AllocationCallbacks *allocationCallbacks);

    friend Creator;

  public:
    Unique();

    Unique(const Unique &other) noexcept = delete;
    Unique(Unique &&other) noexcept;

    auto operator=(const Unique &other) noexcept -> Unique & = delete;
    auto operator=(Unique &&other) noexcept -> Unique &;

    ~Unique() noexcept;

    void cleanup() noexcept;
    // implemented per instantiation
    // void cleanup() noexcept {
    //     if (handle != VK_BINDINGS_NULL_HANDLE) {
    //         (*Destroy_Fun)(handle, nullptr);
    //         handle = VK_BINDINGS_NULL_HANDLE;
    //     }
    // }

    operator object_type() const noexcept;
    auto getObject() const noexcept -> object_type;
};

template <typename Owner_T, typename BaseObject> struct OwnedUnique : public BaseObject {
    using object_type = BaseObject;

  private:
    const AllocationCallbacks *allocationCallbacks = nullptr;
    Owner_T owner;

  protected:
    OwnedUnique(BaseObject &&obj, Owner_T owner,
                const AllocationCallbacks *allocationCallbacks) noexcept;

    friend Creator;

  public:
    OwnedUnique();

    OwnedUnique(const OwnedUnique &other) noexcept = delete;
    OwnedUnique(OwnedUnique &&other) noexcept;

    auto operator=(const OwnedUnique &other) noexcept -> OwnedUnique & = delete;
    auto operator=(OwnedUnique &&other) noexcept -> OwnedUnique &;

    ~OwnedUnique();

    void cleanup() noexcept;
    // implemented per instantiation
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

    operator object_type() const noexcept;
    auto getObject() const noexcept -> object_type;
};

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
struct PoolAllocatedWithoutFunctions {
    using object_type = Handle_T;
    using handle_type = object_type::handle_type;

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

    PoolAllocatedWithoutFunctions(const PoolAllocatedWithoutFunctions &other) noexcept = delete;
    PoolAllocatedWithoutFunctions(PoolAllocatedWithoutFunctions &&other) noexcept;

    auto operator=(const PoolAllocatedWithoutFunctions &other) noexcept
        -> PoolAllocatedWithoutFunctions & = delete;
    auto operator=(PoolAllocatedWithoutFunctions &&other) noexcept
        -> PoolAllocatedWithoutFunctions &;

    ~PoolAllocatedWithoutFunctions() noexcept;

    void cleanup() noexcept;

    explicit operator bool() const;
    auto operator[](size_t n) const -> object_type;
    auto at(size_t n) const -> object_type;

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
    using handle_type = object_type::handle_type;

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
    const impl_Loader::Dispatcher *dispatcher = nullptr;

    PoolAllocated(std::vector<handle_type> &&handles, Pool_Handle_T pool, Owner_T owner,
                  const impl_Loader::Dispatcher &dispatcher);

    friend Creator;

  public:
    PoolAllocated();

    PoolAllocated(const PoolAllocated &other) noexcept = delete;
    PoolAllocated(PoolAllocated &&other) noexcept;

    auto operator=(const PoolAllocated &other) noexcept -> PoolAllocated & = delete;
    auto operator=(PoolAllocated &&other) noexcept -> PoolAllocated &;

    ~PoolAllocated() noexcept;

    void cleanup() noexcept;

    explicit operator bool() const;
    auto operator[](size_t n) const -> object_type;
    auto at(size_t n) const -> object_type;

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
