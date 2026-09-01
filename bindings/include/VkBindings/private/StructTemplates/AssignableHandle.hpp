#pragma once

#include "AssignableHandleInterface.hpp"
#include "VkBindings/Reflection/IsObject.hpp"

#include <cassert>

namespace VkBindings::impl_Struct {

template <Concepts::IsObject Obj>
AssignableHandle<Obj>::AssignableHandle(handle_type handle) noexcept : handle(handle) {}

template <Concepts::IsObject Obj>
AssignableHandle<Obj>::AssignableHandle(object_type object) noexcept : handle(object) {}

template <Concepts::IsObject Obj>
auto AssignableHandle<Obj>::operator=(handle_type suppliedHandle) noexcept
    -> AssignableHandle<Obj> & {
    handle = suppliedHandle;
    return *this;
}

template <Concepts::IsObject Obj>
auto AssignableHandle<Obj>::operator=(object_type object) noexcept -> AssignableHandle<Obj> & {
    handle = object;
    return *this;
}

template <Concepts::IsObject Obj>
auto AssignableHandle<Obj>::getHandle() const -> const handle_type & {
    return handle;
}

template <Concepts::IsObject Obj> AssignableHandle<Obj>::operator handle_type() const {
    return handle;
}
} // namespace VkBindings::impl_Struct
