#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

#include <cstddef>
#include <vector>

#include <iterator>

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

    Object(const handle_type &handle, const impl_Loader::Dispatcher &dispatcher);

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

    ObjectWithoutFunctions(const handle_type &handle);

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
    const AllocationCallbacks *allocationCallbacks = nullptr;

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

    operator const object_type &() const noexcept;
    auto getObject() const noexcept -> const object_type &;
};

template <typename BaseObject> struct UniqueWithDispatcher : public BaseObject {
    using object_type = BaseObject;

  private:
    const AllocationCallbacks *allocationCallbacks = nullptr;
    impl_Loader::Dispatcher dispatcherObj;

  protected:
    UniqueWithDispatcher(object_type &&obj, const AllocationCallbacks *allocationCallbacks);

    friend Creator;

  public:
    UniqueWithDispatcher();

    UniqueWithDispatcher(const UniqueWithDispatcher &other) noexcept = delete;
    UniqueWithDispatcher(UniqueWithDispatcher &&other) noexcept;

    auto operator=(const UniqueWithDispatcher &other) noexcept -> UniqueWithDispatcher & = delete;
    auto operator=(UniqueWithDispatcher &&other) noexcept -> UniqueWithDispatcher &;

    ~UniqueWithDispatcher() noexcept;

    void cleanup() noexcept;

    operator const object_type &() const noexcept;
    auto getObject() const noexcept -> const object_type &;
};

template <typename Owner_Handle_T, typename BaseObject> struct OwnedUnique : public BaseObject {
    using object_type = BaseObject;

  private:
    const AllocationCallbacks *allocationCallbacks = nullptr;
    Owner_Handle_T ownerHandle = VK_BINDINGS_NULL_HANDLE;
    const impl_Loader::Dispatcher *ownerDispatcher = nullptr;

  protected:
    OwnedUnique(BaseObject &&obj, const Owner_Handle_T &ownerHandle,
                const impl_Loader::Dispatcher &ownerDispatcher,
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

    operator const object_type &() const noexcept;
    auto getObject() const noexcept -> const object_type &;
};

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T> struct PoolAllocated {
    using object_type = Object_T;
    using handle_type = object_type::handle_type;

    using container = std::vector<handle_type>;
    using size_type = container::size_type;
    using const_handle_iterator = container::const_iterator;

  private:
    std::vector<handle_type> objectHandles{};
    Pool_Handle_T poolHandle = VK_BINDINGS_NULL_HANDLE;
    Owner_Handle_T ownerHandle = VK_BINDINGS_NULL_HANDLE;
    const impl_Loader::Dispatcher *dispatcherOwner = nullptr;

    PoolAllocated(std::vector<handle_type> &&objectHandles, const Pool_Handle_T &poolHandle,
                  const Owner_Handle_T &ownerHandle,
                  const impl_Loader::Dispatcher &dispatcherOwner);

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

    class object_iterator {
      public:
        using iterator_category = std::random_access_iterator_tag;
        using iterator_concept = std::random_access_iterator_tag;
        using value_type = object_type;
        using difference_type = std::ptrdiff_t;

        using reference = object_type;

        object_iterator() = default;

        auto operator*() const -> object_type;
        auto operator[](difference_type offset) const -> object_type;

        auto operator++() -> object_iterator &;
        auto operator++(int) -> object_iterator;
        auto operator--() -> object_iterator &;
        auto operator--(int) -> object_iterator;

        auto operator+=(difference_type offset) -> object_iterator &;
        auto operator-=(difference_type offset) -> object_iterator &;

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wnon-template-friend"
#endif

        friend auto operator+(object_iterator iter, difference_type offset) -> object_iterator;
        friend auto operator+(difference_type offset, object_iterator iter) -> object_iterator;

        friend auto operator-(object_iterator iter, difference_type offset) -> object_iterator;
        friend auto operator-(const object_iterator &lhs, const object_iterator &rhs)
            -> difference_type;

        friend auto operator==(const object_iterator &lhs, const object_iterator &rhs) -> bool;

        friend auto operator!=(const object_iterator &lhs, const object_iterator &rhs) -> bool;
        friend auto operator<(const object_iterator &lhs, const object_iterator &rhs) -> bool;
        friend auto operator<=(const object_iterator &lhs, const object_iterator &rhs) -> bool;
        friend auto operator>(const object_iterator &lhs, const object_iterator &rhs) -> bool;
        friend auto operator>=(const object_iterator &lhs, const object_iterator &rhs) -> bool;
        friend auto operator<=>(const object_iterator &lhs, const object_iterator &rhs) = default;

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

      private:
        friend PoolAllocated;
        object_iterator(const_handle_iterator current, const impl_Loader::Dispatcher *dispatcher)
            : current(current), dispatcher(dispatcher) {}

        const_handle_iterator current{};
        const impl_Loader::Dispatcher *dispatcher = nullptr;
    };

    using const_iterator = object_iterator;
    using const_reverse_iterator = std::reverse_iterator<object_iterator>;

    [[nodiscard]] auto begin() const -> const_iterator;
    [[nodiscard]] auto cbegin() const -> const_iterator;

    [[nodiscard]] auto end() const -> const_iterator;
    [[nodiscard]] auto cend() const -> const_iterator;

    [[nodiscard]] auto rbegin() const -> const_reverse_iterator;
    [[nodiscard]] auto crbegin() const -> const_reverse_iterator;

    [[nodiscard]] auto rend() const -> const_reverse_iterator;
    [[nodiscard]] auto crend() const -> const_reverse_iterator;
};

} // namespace VkBindings::impl_Objects
