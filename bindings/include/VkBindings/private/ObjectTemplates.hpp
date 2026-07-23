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
auto Object<Handle_T, Creator_T>::get() const noexcept -> Object<Handle_T, Creator_T>::handle_type {
    return handle;
}
template <typename Handle_T, typename Creator_T>
auto Object<Handle_T, Creator_T>::rawHandlePtr() noexcept
    -> Object<Handle_T, Creator_T>::handle_type * {
    return &handle;
}
template <typename Handle_T, typename Creator_T>
auto Object<Handle_T, Creator_T>::rawHandlePtr() const noexcept
    -> const Object<Handle_T, Creator_T>::handle_type * {
    return &handle;
}
template <typename Handle_T, typename Creator_T>
Object<Handle_T, Creator_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}
template <typename Handle_T, typename Creator_T>
Object<Handle_T, Creator_T>::operator handle_type() const noexcept {
    return handle;
}

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::ObjectWithoutFunctions(handle_type &&handle)
    : handle(handle) {}

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::ObjectWithoutFunctions() = default;

template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::ObjectWithoutFunctions(ObjectWithoutFunctions &&other)
    : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)) {}

template <typename Handle_T, typename Creator_T>
auto ObjectWithoutFunctions<Handle_T, Creator_T>::operator=(ObjectWithoutFunctions &&other) noexcept
    -> ObjectWithoutFunctions<Handle_T, Creator_T> & {
    handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    return *this;
}

template <typename Handle_T, typename Creator_T>
auto ObjectWithoutFunctions<Handle_T, Creator_T>::get() const noexcept
    -> ObjectWithoutFunctions<Handle_T, Creator_T>::handle_type {
    return handle;
}
template <typename Handle_T, typename Creator_T>
auto ObjectWithoutFunctions<Handle_T, Creator_T>::rawHandlePtr() noexcept
    -> ObjectWithoutFunctions<Handle_T, Creator_T>::handle_type * {
    return &handle;
}
template <typename Handle_T, typename Creator_T>
auto ObjectWithoutFunctions<Handle_T, Creator_T>::rawHandlePtr() const noexcept
    -> const ObjectWithoutFunctions<Handle_T, Creator_T>::handle_type * {
    return &handle;
}
template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}
template <typename Handle_T, typename Creator_T>
ObjectWithoutFunctions<Handle_T, Creator_T>::operator handle_type() const noexcept {
    return handle;
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
auto Unique<Creator_T, DerivedObject>::get() const noexcept
    -> Unique<Creator_T, DerivedObject>::handle_type {
    return obj.get();
}
template <typename Creator_T, typename DerivedObject>
auto Unique<Creator_T, DerivedObject>::rawHandlePtr() const noexcept
    -> const Unique<Creator_T, DerivedObject>::handle_type * {
    return obj.rawHandlePtr();
}
template <typename Creator_T, typename DerivedObject>
auto Unique<Creator_T, DerivedObject>::rawHandlePtr() noexcept
    -> Unique<Creator_T, DerivedObject>::handle_type * {
    return obj.rawHandlePtr();
}
template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::operator bool() const noexcept {
    return bool(obj);
}
template <typename Creator_T, typename DerivedObject>
Unique<Creator_T, DerivedObject>::operator DerivedObject() const noexcept {
    return obj;
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
auto OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::get() const noexcept
    -> OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::handle_type {
    return obj.get();
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
auto OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::rawHandlePtr() const noexcept
    -> const OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::handle_type * {
    return obj.rawHandlePtr();
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
auto OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::rawHandlePtr() noexcept
    -> OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::handle_type * {
    return obj.rawHandlePtr();
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::operator bool() const noexcept {
    return bool(obj);
}

template <typename Owner_T, typename Owner_Handle_T, typename DerivedObject>
OwnedUnique<Owner_T, Owner_Handle_T, DerivedObject>::operator DerivedObject() const noexcept {
    return obj;
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
    -> Handle_T & {
    assert(n < handles.size());
    return handles[n];
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator[](size_t n) const
    -> const Handle_T & {
    assert(n < handles.size());
    return handles[n];
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::begin() ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::iterator {
    return handles.begin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::end() ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::iterator {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::cbegin() const ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::const_iterator {
    return handles.cbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::cend() const ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::const_iterator {
    return handles.cend();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::rbegin() ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::reverse_iterator {
    return handles.rbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::rend() ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::reverse_iterator {
    return handles.rend();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::crbegin() const ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T,
                           Pool_Handle_T>::const_reverse_iterator {
    return handles.crbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::crend() const ->
    typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T,
                           Pool_Handle_T>::const_reverse_iterator {
    return handles.crend();
}

} // namespace VkBindings::impl_Objects
