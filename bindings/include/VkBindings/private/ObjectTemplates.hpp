#pragma once

#include "Creator.hpp"
#include "ObjectTemplatesIntreface.hpp"
#include "VkBindings/Defines.hpp"
#include "VkBindings/Reflection/HasDispatcher.hpp"
#include "VkBindings/Reflection/ObjectToHandle.hpp"
#include "VkBindings/Structs.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

#include <cassert>
#include <cstddef>
#include <utility>
#include <vector>

namespace VkBindings::impl_Objects {

template <typename Handle_T>
auto Object<Handle_T>::getInstanceTable() const -> const impl_Loader::InstanceTable & {
    return dispatcher->instanceTable;
}

template <typename Handle_T>
auto Object<Handle_T>::getDeviceTable() const -> const impl_Loader::DeviceTable & {
    return dispatcher->deviceTable;
}

template <typename Handle_T>
auto Object<Handle_T>::getDispatcher() const -> const impl_Loader::Dispatcher & {
    return *dispatcher;
}

template <typename Handle_T>
void Object<Handle_T>::setDispatcher(const impl_Loader::Dispatcher &dispatcher) {
    this->dispatcher = &dispatcher;
}

template <typename Handle_T> auto Object<Handle_T>::getHandle() const -> const handle_type & {
    return handle;
}

template <typename Handle_T>
Object<Handle_T>::Object(const handle_type &handle, const impl_Loader::Dispatcher &dispatcher)
    : handle(handle), dispatcher(&dispatcher) {}

template <typename Handle_T> Object<Handle_T>::Object() = default;

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

template <typename Handle_T> Object<Handle_T>::~Object() noexcept = default;

template <typename Handle_T> Object<Handle_T>::operator handle_type() const noexcept {
    return handle;
}

template <typename Handle_T> Object<Handle_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}

template <typename Handle_T>
auto ObjectWithoutFunctions<Handle_T>::getHandle() const -> const handle_type & {
    return handle;
}

template <typename Handle_T>
ObjectWithoutFunctions<Handle_T>::ObjectWithoutFunctions(const handle_type &handle)
    : handle(handle) {}

template <typename Handle_T> ObjectWithoutFunctions<Handle_T>::ObjectWithoutFunctions() = default;

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
ObjectWithoutFunctions<Handle_T>::~ObjectWithoutFunctions() noexcept = default;

template <typename Handle_T>
ObjectWithoutFunctions<Handle_T>::operator handle_type() const noexcept {
    return handle;
}

template <typename Handle_T> ObjectWithoutFunctions<Handle_T>::operator bool() const noexcept {
    return handle != VK_BINDINGS_NULL_HANDLE;
}

template <typename BaseObject> Unique<BaseObject>::Unique() = default;

template <typename BaseObject>
Unique<BaseObject>::Unique(object_type &&obj, const AllocationCallbacks *allocationCallbacks)

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

template <typename BaseObject> Unique<BaseObject>::operator const object_type &() const noexcept {
    return static_cast<const object_type &>(*this);
}

template <typename BaseObject>
auto Unique<BaseObject>::getObject() const noexcept -> const object_type & {
    return static_cast<const object_type &>(*this);
}

template <typename BaseObject> UniqueWithDispatcher<BaseObject>::UniqueWithDispatcher() = default;

template <typename BaseObject>
UniqueWithDispatcher<BaseObject>::UniqueWithDispatcher(UniqueWithDispatcher &&other) noexcept
    : BaseObject(std::move(static_cast<BaseObject &>(other))),
      allocationCallbacks(std::exchange(other.allocationCallbacks, nullptr)),
      dispatcherObj(other.dispatcherObj) {
    BaseObject::setDispatcher(dispatcherObj);
}

template <typename BaseObject>
auto UniqueWithDispatcher<BaseObject>::operator=(UniqueWithDispatcher &&other) noexcept
    -> UniqueWithDispatcher<BaseObject> & {
    if (this != &other) {
        cleanup();
        BaseObject::operator=(std::move(static_cast<BaseObject &>(other)));
        allocationCallbacks = std::exchange(other.allocationCallbacks, nullptr);
        dispatcherObj = std::exchange(other.dispatcherObj, {});
        BaseObject::setDispatcher(dispatcherObj);
    }
    return *this;
}

template <typename BaseObject> UniqueWithDispatcher<BaseObject>::~UniqueWithDispatcher() noexcept {
    cleanup();
}

template <typename BaseObject>
UniqueWithDispatcher<BaseObject>::operator const object_type &() const noexcept {
    return static_cast<const object_type &>(*this);
}

template <typename BaseObject>
auto UniqueWithDispatcher<BaseObject>::getObject() const noexcept -> const object_type & {
    return static_cast<const object_type &>(*this);
}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::OwnedUnique(
    BaseObject &&obj, const Owner_Handle_T &ownerHandle,
    const impl_Loader::Dispatcher &ownerDispatcher,
    const AllocationCallbacks *allocationCallbacks) noexcept
    : BaseObject(std::move(obj)), allocationCallbacks(allocationCallbacks),
      ownerHandle(ownerHandle), ownerDispatcher(&ownerDispatcher) {}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::OwnedUnique() = default;

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::OwnedUnique(OwnedUnique &&other) noexcept
    : BaseObject(std::move(other)),
      allocationCallbacks(std::exchange(other.allocationCallbacks, nullptr)),
      ownerHandle(std::exchange(other.ownerHandle, VK_BINDINGS_NULL_HANDLE)),
      ownerDispatcher(std::exchange(other.ownerDispatcher, nullptr)) {}

template <typename Owner_Handle_T, typename BaseObject>
auto OwnedUnique<Owner_Handle_T, BaseObject>::operator=(OwnedUnique &&other) noexcept
    -> OwnedUnique<Owner_Handle_T, BaseObject> & {
    if (this != &other) {
        cleanup();
        BaseObject::operator=(std::move(other));
        allocationCallbacks = std::exchange(other.allocationCallbacks, nullptr);
        ownerHandle = std::exchange(other.ownerHandle, VK_BINDINGS_NULL_HANDLE);
        ownerDispatcher = std::exchange(other.ownerDispatcher, nullptr);
    }
    return *this;
}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::~OwnedUnique() {
    cleanup();
}

template <typename Owner_Handle_T, typename BaseObject>
OwnedUnique<Owner_Handle_T, BaseObject>::operator const object_type &() const noexcept {
    return static_cast<const BaseObject &>(*this);
}

template <typename Owner_Handle_T, typename BaseObject>
auto OwnedUnique<Owner_Handle_T, BaseObject>::getObject() const noexcept -> const object_type & {
    return static_cast<const BaseObject &>(*this);
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated(
    std::vector<handle_type> &&objectHandles, const Pool_Handle_T &pool,
    const Owner_Handle_T &owner, const impl_Loader::Dispatcher &dispatcherOwner)
    : objectHandles(std::move(objectHandles)), poolHandle(pool), ownerHandle(owner),
      dispatcherOwner(&dispatcherOwner) {}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated() = default;

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::PoolAllocated(
    PoolAllocated &&other) noexcept
    : objectHandles(std::exchange(other.objectHandles, {})),
      poolHandle(std::exchange(other.poolHandle, VK_BINDINGS_NULL_HANDLE)),
      ownerHandle(std::exchange(other.ownerHandle, VK_BINDINGS_NULL_HANDLE)),
      dispatcherOwner(std::exchange(other.dispatcherOwner, VK_BINDINGS_NULL_HANDLE)) {}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::operator=(
    PoolAllocated &&other) noexcept -> PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T> & {
    cleanup();
    objectHandles = std::exchange(other.objectHandles, {});
    poolHandle = std::exchange(other.poolHandle, VK_BINDINGS_NULL_HANDLE);
    ownerHandle = std::exchange(other.ownerHandle, VK_BINDINGS_NULL_HANDLE);
    dispatcherOwner = std::exchange(other.dispatcherOwner, nullptr);

    return *this;
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::~PoolAllocated() noexcept {
    cleanup();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::operator bool() const {
    return !objectHandles.empty();
}

template <Concepts::HasDispatcher Object_T>
auto constructObject(Reflections::ObjectToHandle<Object_T> handle,
                     const impl_Loader::Dispatcher &dispatcher) -> Object_T {
    return Creator::create<Object_T>(handle, dispatcher);
}

template <typename Object_T>
    requires(!Concepts::HasDispatcher<Object_T>)
auto constructObject(Reflections::ObjectToHandle<Object_T> handle,
                     [[maybe_unused]] const impl_Loader::Dispatcher &dispatcher) -> Object_T {
    return Creator::create<Object_T>(handle);
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::operator[](size_t n) const
    -> object_type {
    assert(n < objectHandles.size());
    return constructObject<object_type>(objectHandles[n], *dispatcherOwner);
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::at(size_t n) const -> object_type {
    return constructObject<object_type>(objectHandles.at(n), *dispatcherOwner);
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::size() const -> size_type {
    return objectHandles.size();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::empty() const -> bool {
    return objectHandles.empty();
}
template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::begin() -> iterator {
    return objectHandles.begin();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::begin() const -> const_iterator {
    return objectHandles.begin();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::cbegin() const -> const_iterator {
    return objectHandles.cbegin();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::end() -> iterator {
    return objectHandles.end();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::end() const -> const_iterator {
    return objectHandles.end();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::cend() const -> const_iterator {
    return objectHandles.end();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::rbegin() -> reverse_iterator {
    return objectHandles.rbegin();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::rbegin() const
    -> const_reverse_iterator {
    return objectHandles.rbegin();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::crbegin() const
    -> const_reverse_iterator {
    return objectHandles.crbegin();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::rend() -> reverse_iterator {
    return objectHandles.rend();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::rend() const
    -> const_reverse_iterator {
    return objectHandles.rend();
}

template <typename Object_T, typename Owner_Handle_T, typename Pool_Handle_T>
auto PoolAllocated<Object_T, Owner_Handle_T, Pool_Handle_T>::crend() const
    -> const_reverse_iterator {
    return objectHandles.crend();
}

} // namespace VkBindings::impl_Objects
