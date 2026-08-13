#pragma once

#include "Creator.hpp"
#include "ObjectTemplatesIntreface.hpp"
#include "VkBindings/Structs.hpp"

#include <utility>
#include <vector>

namespace VkBindings::impl_Objects {

template <typename Handle_T>
Object<Handle_T>::Object(handle_type &&handle, impl_Loader::Dispatcher *dispatcher) noexcept
    : handle(handle), dispatcher(dispatcher) {}

template <typename Handle_T> Object<Handle_T>::Object() noexcept = default;

template <typename Handle_T>
Object<Handle_T>::Object(const Object &other) noexcept
    : handle(other.handle), dispatcher(other.dispatcher) {}

template <typename Handle_T>
Object<Handle_T>::Object(Object &&other) noexcept
    : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)),
      dispatcher(std::exchange(other.dispatcher, nullptr)) {}

template <typename Handle_T>
auto Object<Handle_T>::operator=(Object &&other) noexcept -> Object<Handle_T> & {
    handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    dispatcher = std::exchange(other.dispatcher, nullptr);
    return *this;
}

template <typename Handle_T> Object<Handle_T>::operator handle_type() const noexcept {
    return handle;
}

template <typename Handle_T> auto Object<Handle_T>::getHandle() const noexcept -> handle_type {
    return handle;
}

template <typename Handle_T> Object<Handle_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}

template <typename Handle_T>
ObjectWithoutFunctions<Handle_T>::ObjectWithoutFunctions(handle_type &&handle) noexcept
    : handle(handle) {}

template <typename Handle_T>
ObjectWithoutFunctions<Handle_T>::ObjectWithoutFunctions() noexcept = default;

template <typename Handle_T>
ObjectWithoutFunctions<Handle_T>::ObjectWithoutFunctions(
    const ObjectWithoutFunctions &other) noexcept = default;

template <typename Handle_T>
ObjectWithoutFunctions<Handle_T>::ObjectWithoutFunctions(ObjectWithoutFunctions &&other) noexcept
    : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)) {}

template <typename Handle_T>
auto ObjectWithoutFunctions<Handle_T>::operator=(const ObjectWithoutFunctions &other) noexcept
    -> ObjectWithoutFunctions<Handle_T> & = default;

template <typename Handle_T>
auto ObjectWithoutFunctions<Handle_T>::operator=(ObjectWithoutFunctions &&other) noexcept
    -> ObjectWithoutFunctions<Handle_T> & {
    handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    return *this;
}

template <typename Handle_T>
ObjectWithoutFunctions<Handle_T>::operator handle_type() const noexcept {
    return handle;
}

template <typename Handle_T>
auto ObjectWithoutFunctions<Handle_T>::getHandle() const noexcept -> handle_type {
    return handle;
}

template <typename Handle_T> ObjectWithoutFunctions<Handle_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}

template <typename BaseObject>
Unique<BaseObject>::Unique(BaseObject &&obj,
                           const AllocationCallbacks *allocationCallbacks) noexcept
    : BaseObject(std::move(obj)), allocationCallbacks(allocationCallbacks) {}

template <typename BaseObject>
Unique<BaseObject>::Unique(Unique &&other) noexcept
    : BaseObject(std::move(other)),
      allocationCallbacks(std::exchange(other.allocationCallbacks, nullptr)) {}

template <typename BaseObject>
auto Unique<BaseObject>::operator=(Unique &&other) noexcept -> Unique<BaseObject> & {
    if (this != &other) {
        cleanup();
        BaseObject::operator=(std::move(other));
        allocationCallbacks = std::exchange(other.allocationCallbacks, nullptr);
    }
    return *this;
}

template <typename BaseObject> Unique<BaseObject>::~Unique() noexcept { cleanup(); }

template <typename BaseObject> Unique<BaseObject>::operator object_type() const noexcept {
    return static_cast<const object_type &>(*this);
}

template <typename BaseObject>
auto Unique<BaseObject>::getObject() const noexcept -> const object_type {
    return static_cast<const object_type &>(*this);
}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::OwnedUnique(
    BaseObject &&obj, Owner_Handle_T o, const AllocationCallbacks *allocationCallbacks) noexcept
    : BaseObject(std::move(obj)), allocationCallbacks(allocationCallbacks), owner(o) {}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::OwnedUnique() noexcept = default;

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::OwnedUnique(OwnedUnique &&other) noexcept
    : BaseObject(std::move(other)),
      allocationCallbacks(std::exchange(other.allocationCallbacks, nullptr)),
      owner(std::move(other.owner)) {}

template <typename Owner_Handle_T, typename BaseObject>
auto OwnedUnique<Owner_Handle_T, BaseObject>::operator=(OwnedUnique &&other) noexcept
    -> OwnedUnique<Owner_Handle_T, BaseObject> & {
    if (this != &other) {
        cleanup();
        BaseObject::operator=(std::move(other));
        allocationCallbacks = std::exchange(other.allocationCallbacks, nullptr);
        owner = std::move(other.owner);
    }
    return *this;
}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::~OwnedUnique() noexcept {
    cleanup();
}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::operator object_type() const noexcept {
    return static_cast<const BaseObject &>(*this);
}

template <typename Owner_Handle_T, typename BaseObject>
auto OwnedUnique<Owner_Handle_T, BaseObject>::getObject() const noexcept -> const object_type {
    return static_cast<const BaseObject &>(*this);
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::PoolAllocatedWithoutFunctions(
    std::vector<handle_type> &&handles, Pool_Handle_T pool, Owner_T owner)
    : handles(std::move(handles)), pool(pool), owner(owner) {}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::PoolAllocatedWithoutFunctions() =
    default;

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::PoolAllocatedWithoutFunctions(
    PoolAllocatedWithoutFunctions &&other)
    : handles(std::exchange(other.handles, {})),
      pool(std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE)), owner(std::move(other.owner)) {}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::operator=(
    PoolAllocatedWithoutFunctions &&other) noexcept
    -> PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T> & {
    cleanup();
    handles = std::exchange(other.handles, {});
    pool = std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE);
    owner = std::move(other.owner);
    return *this;
}

// template <typename Handle_T, typename Owner_T, typename Owner_T, typename Pool_Handle_T>
// void PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Owner_T, Pool_Handle_T>::cleanup() {
//     if (!handles.empty()) {
//         impl_Loader::Dispatcher* dispatcher = handles[0].dispatcher;
//         (*dispatcher->device->freeCommandBuffers)(owner, pool, handles.size(), handles.data());
//         handles.clear();
//         pool = VK_BINDINGS_NULL_HANDLE;
//         owner = VK_BINDINGS_NULL_HANDLE;
//     }
// }

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocatedWithoutFunctions<Handle_T, Owner_T,
                              Pool_Handle_T>::~PoolAllocatedWithoutFunctions() noexcept {
    cleanup();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::operator bool() const {
    return !handles.empty();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::operator[](size_t n) const
    -> object_type {
    assert(n < handles.size());
    auto handle = handles[n];
    return Creator::create<object_type>(std::move(handle));
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::size() const -> size_type {
    return handles.size();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::empty() const -> bool {
    return handles.empty();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::begin() -> iterator {
    return handles.begin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::begin() const
    -> const_iterator {
    return handles.begin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::cbegin() const
    -> const_iterator {
    return handles.cbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::end() -> iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::end() const
    -> const_iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::cend() const
    -> const_iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::rbegin() -> reverse_iterator {
    return handles.rbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::rbegin() const
    -> const_reverse_iterator {
    return handles.rbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::crbegin() const
    -> const_reverse_iterator {
    return handles.crbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::rend() -> reverse_iterator {
    return handles.rend();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::rend() const
    -> const_reverse_iterator {
    return handles.rend();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocatedWithoutFunctions<Handle_T, Owner_T, Pool_Handle_T>::crend() const
    -> const_reverse_iterator {
    return handles.crend();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::PoolAllocated(std::vector<handle_type> &&handles,
                                                               Pool_Handle_T pool, Owner_T owner,
                                                               impl_Loader::Dispatcher *dispatcher)
    : handles(std::move(handles)), pool(pool), owner(owner), dispatcher(dispatcher) {}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::PoolAllocated() = default;

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::PoolAllocated(PoolAllocated &&other)
    : handles(std::exchange(other.handles, {})),
      pool(std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE)), owner(std::move(other.owner)) {}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::operator=(PoolAllocated &&other) noexcept
    -> PoolAllocated<Handle_T, Owner_T, Pool_Handle_T> & {
    cleanup();
    handles = std::exchange(other.handles, {});
    pool = std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE);
    owner = std::move(other.owner);
    return *this;
}

// template <typename Handle_T, typename Owner_T, typename Owner_T, typename Pool_Handle_T>
// void PoolAllocated<Handle_T, Owner_T, Owner_T, Pool_Handle_T>::cleanup() {
//     if (!handles.empty()) {
//         impl_Loader::Dispatcher* dispatcher = handles[0].dispatcher;
//         (*dispatcher->device->freeCommandBuffers)(owner, pool, handles.size(), handles.data());
//         handles.clear();
//         pool = VK_BINDINGS_NULL_HANDLE;
//         owner = VK_BINDINGS_NULL_HANDLE;
//     }
// }

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::~PoolAllocated() noexcept {
    cleanup();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::operator bool() const {
    return !handles.empty();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::operator[](size_t n) const -> object_type {
    assert(n < handles.size());
    auto handle = handles[n];
    return Creator::create<object_type>(std::move(handle), dispatcher);
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::size() const -> size_type {
    return handles.size();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::empty() const -> bool {
    return handles.empty();
}
template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::begin() -> iterator {
    return handles.begin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::begin() const -> const_iterator {
    return handles.begin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::cbegin() const -> const_iterator {
    return handles.cbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::end() -> iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::end() const -> const_iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::cend() const -> const_iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::rbegin() -> reverse_iterator {
    return handles.rbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::rbegin() const -> const_reverse_iterator {
    return handles.rbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::crbegin() const -> const_reverse_iterator {
    return handles.crbegin();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::rend() -> reverse_iterator {
    return handles.rend();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::rend() const -> const_reverse_iterator {
    return handles.rend();
}

template <typename Handle_T, typename Owner_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Pool_Handle_T>::crend() const -> const_reverse_iterator {
    return handles.crend();
}

} // namespace VkBindings::impl_Objects
