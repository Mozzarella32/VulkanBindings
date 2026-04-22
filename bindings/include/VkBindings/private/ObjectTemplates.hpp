#pragma once

#include "ObjectTemplatesIntreface.hpp"
#include <vector>

namespace VkBindings {
namespace impl_Objects {
template <typename Handle_T, typename Creator_T> Unique<Handle_T, Creator_T>::Unique() {}

template <typename Handle_T, typename Creator_T>
Unique<Handle_T, Creator_T>::Unique(Handle_T &&h, impl_Loader::Dispatcher *dispatcher)
    : handle(h), dispatcher(dispatcher) {}

template <typename Handle_T, typename Creator_T>
Unique<Handle_T, Creator_T>::Unique(Unique &&other)
    : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)),
      dispatcher(std::exchange(other.dispatcher, nullptr)) {}

template <typename Handle_T, typename Creator_T>
Unique<Handle_T, Creator_T> &Unique<Handle_T, Creator_T>::operator=(Unique &&other) noexcept {
    cleanup();
    handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    dispatcher = std::exchange(other.dispatcher, nullptr);
    return *this;
}

template <typename Handle_T, typename Creator_T> Unique<Handle_T, Creator_T>::~Unique() noexcept {
    cleanup();
}

template <typename Handle_T, typename Creator_T>
Handle_T Unique<Handle_T, Creator_T>::get() const noexcept {
    return handle;
}
template <typename Handle_T, typename Creator_T>
const Handle_T *Unique<Handle_T, Creator_T>::rawHandlePtr() const noexcept {
    return &handle;
}
template <typename Handle_T, typename Creator_T>
Handle_T *Unique<Handle_T, Creator_T>::rawHandlePtr() noexcept {
    return &handle;
}
template <typename Handle_T, typename Creator_T>
Unique<Handle_T, Creator_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}
template <typename Handle_T, typename Creator_T>
Unique<Handle_T, Creator_T>::operator Handle_T() const noexcept {
    return handle;
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::OwnedUnique(Handle_T &&h, Owner_Handle_T o,
                                                            impl_Loader::Dispatcher *dispatcher)
    : handle(h), owner(o), dispatcher(dispatcher) {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::OwnedUnique() {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::OwnedUnique(OwnedUnique &&other)
    : handle(std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE)),
      owner(std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE)),
      dispatcher(std::exchange(other.dispatcher, nullptr)) {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T> &
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::operator=(OwnedUnique &&other) noexcept {
    cleanup();
    handle = std::exchange(other.handle, VK_BINDINGS_NULL_HANDLE);
    owner = std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE);
    dispatcher = std::exchange(other.dispatcher, nullptr);
    return *this;
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::~OwnedUnique() noexcept {
    cleanup();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
Handle_T OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::get() const noexcept {
    return handle;
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
const Handle_T *OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::rawHandlePtr() const noexcept {
    return &handle;
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
Handle_T *OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::rawHandlePtr() noexcept {
    return &handle;
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T>
OwnedUnique<Handle_T, Owner_T, Owner_Handle_T>::operator Handle_T() const noexcept {
    return handle;
}

template <typename Handle_T>
NonOwned<Handle_T>::NonOwned(Handle_T &&handle, impl_Loader::Dispatcher *dispatcher)
    : handle(std::move(handle)), dispatcher(dispatcher) {}

template <typename Handle_T> NonOwned<Handle_T>::NonOwned() {}

template <typename Handle_T> Handle_T NonOwned<Handle_T>::get() const noexcept { return handle; }

template <typename Handle_T> const Handle_T *NonOwned<Handle_T>::rawHandlePtr() const noexcept {
    return &handle;
}

template <typename Handle_T> Handle_T *NonOwned<Handle_T>::rawHandlePtr() noexcept {
    return &handle;
}

template <typename Handle_T> NonOwned<Handle_T>::operator Handle_T() const noexcept {
    return handle;
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated(
    std::vector<Handle_T> &&handles, Pool_Handle_T pool, Owner_Handle_T owner)
    : handles(std::move(handles)), pool(pool), owner(owner) {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated() {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated(
    PoolAllocated &&other)
    : handles(std::exchange(other.handles, {})),
      pool(std::exchange(other.pool, VK_BINDINGS_NULL_HANDLE)),
      owner(std::exchange(other.owner, VK_BINDINGS_NULL_HANDLE)) {}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T> &
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator=(
    PoolAllocated &&other) noexcept {
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
Handle_T &PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator[](size_t n) {
    assert(n < handles.size());
    return handles[n];
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
const Handle_T &
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::operator[](size_t n) const {
    assert(n < handles.size());
    return handles[n];
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::begin() {
    return handles.begin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::end() {
    return handles.end();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::const_iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::cbegin() const {
    return handles.cbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::const_iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::cend() const {
    return handles.cend();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::reverse_iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::rbegin() {
    return handles.rbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::reverse_iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::rend() {
    return handles.rend();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::const_reverse_iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::crbegin() const {
    return handles.crbegin();
}

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Pool_Handle_T>
typename PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::const_reverse_iterator
PoolAllocated<Handle_T, Owner_T, Owner_Handle_T, Pool_Handle_T>::crend() const {
    return handles.crend();
}

} // namespace impl_Objects
} // namespace VkBindings
