#pragma once

#include "VkBindings/Defines.hpp"
#include "VkBindings/Reflection/IsObject.hpp"
#include "VkBindings/Reflection/ObjectToHandle.hpp"

namespace VkBindings::impl_Struct {

struct LayoutChecker;

template <Concepts::IsObject Obj> struct AssignableHandle {
    using handle_type = Reflections::ObjectToHandle<Obj>;
    using object_type = Obj;

  private:
    handle_type handle = VK_BINDINGS_NULL_HANDLE;

    friend LayoutChecker;

  public:
    AssignableHandle() = default;

    AssignableHandle(handle_type handle) noexcept;
    AssignableHandle(object_type object) noexcept;

    auto operator=(handle_type handle) noexcept -> AssignableHandle &;
    auto operator=(object_type object) noexcept -> AssignableHandle &;

    [[nodiscard]] auto getHandle() const -> const handle_type &;

    operator handle_type() const;
};
} // namespace VkBindings::impl_Struct
