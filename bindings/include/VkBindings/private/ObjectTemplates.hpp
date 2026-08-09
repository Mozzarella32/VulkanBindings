#pragma once

#include "ObjectTemplatesIntreface.hpp"

#include <utility>
#include <vector>

namespace VkBindings::impl_Objects {

template <typename Handle_T, typename Creator_T>
Object<Handle_T, Creator_T>::Object(handle_type &&handle, impl_Loader::Dispatcher *dispatcher)
    : handle(handle), dispatcher(dispatcher) {}

template <typename Handle_T, typename Creator_T> Object<Handle_T, Creator_T>::Object() = default;

template <typename Handle_T, typename Creator_T>
Object<Handle_T, Creator_T>::Object(const Object &other)
    : handle(other.handle), dispatcher(other.dispatcher) {}

template <typename Handle_T, typename Creator_T>
Object<Handle_T, Creator_T>::Object(Object &&other)
    : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)),
      dispatcher(std::exchange(other.dispatcher, nullptr)) {}

template <typename Handle_T, typename Creator_T>
auto Object<Handle_T, Creator_T>::operator=(Object &&other) noexcept
    -> Object<Handle_T, Creator_T> & {
    handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    dispatcher = std::exchange(other.dispatcher, nullptr);
    return *this;
}

template <typename Handle_T, typename Creator_T>
Object<Handle_T, Creator_T>::operator handle_type() const noexcept {
    return handle;
}

template <typename Handle_T, typename Creator_T>
auto Object<Handle_T, Creator_T>::getHandle() const noexcept -> handle_type {
    return handle;
}

template <typename Handle_T, typename Creator_T>
Object<Handle_T, Creator_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::ObjectWithoutFunctions(handle_type &&handle)
    : handle(handle) {}

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::ObjectWithoutFunctions() = default;

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::ObjectWithoutFunctions(
    const ObjectWithoutFunctions &other) = default;

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::ObjectWithoutFunctions(ObjectWithoutFunctions &&other)
    : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)) {}

template <typename Handle_T, typename Creator_T>
auto ObjectWithoutFunctions<Handle_T, Creator_T>::operator=(
    const ObjectWithoutFunctions &other) noexcept
    -> ObjectWithoutFunctions<Handle_T, Creator_T> & = default;

template <typename Handle_T, typename Creator_T>
auto ObjectWithoutFunctions<Handle_T, Creator_T>::operator=(ObjectWithoutFunctions &&other) noexcept
    -> ObjectWithoutFunctions<Handle_T, Creator_T> & {
    handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    return *this;
}

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::operator handle_type() const noexcept {
    return handle;
}

template <typename Handle_T, typename Creator_T>
auto ObjectWithoutFunctions<Handle_T, Creator_T>::getHandle() const noexcept -> handle_type {
    return handle;
}

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}

template <typename Creator_T, typename DerivedObjectWithoutFunctions>
Unique<Creator_T, DerivedObjectWithoutFunctions>::Unique() = default;

template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::Unique(DerivedObject &&obj) : obj(std::move(obj)) {}

template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::Unique(Unique &&other) : obj(std::move(other.obj)) {}

template <typename Creator_T, typename DerivedObject>
auto Unique<Creator_T, DerivedObject>::operator=(Unique &&other) noexcept
    -> Unique<Creator_T, DerivedObject> & {
    cleanup();
    obj = std::move(other.obj);
    return *this;
}

template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::~Unique() noexcept {
    cleanup();
}

template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::operator object_type() const noexcept {
    return obj;
}

template <typename Creator_T, typename DerivedObject>
auto Unique<Creator_T, DerivedObject>::getObject() const noexcept -> object_type {
    return obj;
}

template <typename Creator_T, typename DerivedObject>
auto Unique<Creator_T, DerivedObject>::operator->() const noexcept -> object_type * {
    return &obj;
}

template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::operator handle_type() const noexcept {
    return obj.getHandle();
}

template <typename Creator_T, typename DerivedObject>
auto Unique<Creator_T, DerivedObject>::getHandle() const noexcept -> handle_type {
    return obj.getiHandle();
}

template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::operator bool() const noexcept {
    return bool(obj);
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::OwnedUnique(DerivedObject &&obj,
                                                                 Owner_Handle_T o)
    : obj(std::move(obj)), owner(o) {}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::OwnedUnique() = default;

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::OwnedUnique(OwnedUnique &&other)
    : obj(std::move(other.obj)), owner(std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE)) {}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
auto OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::operator=(OwnedUnique &&other) noexcept
    -> OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject> & {
    cleanup();
    obj = std::move(other.obj);
    owner = std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE);
    return *this;
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::~OwnedUnique() noexcept {
    cleanup();
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::operator object_type() const noexcept {
    return obj;
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
auto OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::getObject() const noexcept
    -> object_type {
    return obj;
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
auto OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::operator->() const noexcept
    -> object_type * {
    return &obj;
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::operator handle_type() const noexcept {
    return obj.getHandle();
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
auto OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::getHandle() const noexcept
    -> handle_type {
    return obj.getiHandle();
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::operator bool() const noexcept {
    return bool(obj);
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated(
    std::vector<handle_type> &&handles, Pool_Handle_T pool, Owner_Handle_T owner)
    : handles(std::move(handles)), pool(pool), owner(owner) {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated() = default;

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated(
    PoolAllocated &&other)
    : handles(std::exchange(other.handles, {})),
      pool(std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE)),
      owner(std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE)) {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator=(
    PoolAllocated &&other) noexcept
    -> PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T> & {
    cleanup();
    handles = std::exchange(other.handles, {});
    pool = std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE);
    owner = std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE);
    return *this;
}

// template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
// void PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::cleanup() {
//     if (!handles.empty()) {
//         impl_Loader::Dispatcher* dispatcher = handles[0].dispatcher;
//         (*dispatcher->device->freeCommandBuffers)(owner, pool, handles.size(), handles.data());
//         handles.clear();
//         pool = VK_BINDINGS_NULL_HANDLE;
//         owner = VK_BINDINGS_NULL_HANDLE;
//     }
// }

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::~PoolAllocated() noexcept {
    cleanup();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator bool() const {
    return !handles.empty();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator[](size_t n)
    -> object_type & {
    assert(n < handles.size());
    return handles[n];
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator[](size_t n) const
    -> const object_type & {
    assert(n < handles.size());
    return handles[n];
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::size() const -> size_type {
    return handles.size();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::empty() const -> bool {
    return handles.empty();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::begin() const -> iterator {
    return handles.begin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::end() const -> iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::cbegin() const
    -> const_iterator {
    return handles.cbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::cend() const
    -> const_iterator {
    return handles.cend();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::rbegin() const
    -> reverse_iterator {
    return handles.rbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::rend() const
    -> reverse_iterator {
    return handles.rend();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::crbegin() const
    -> const_reverse_iterator {
    return handles.crbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::crend() const
    -> const_reverse_iterator {
    return handles.crend();
}

} // namespace VkBindings::impl_Objects
