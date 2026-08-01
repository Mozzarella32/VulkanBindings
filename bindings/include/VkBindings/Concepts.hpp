#pragma once

namespace VkBindings::Concepts {
template <typename T>
concept HasDispatcher = T::supports_dispatcher;

template <typename T>
concept HasHandleConstructor = T::has_handle_constructor;

template <typename T>
concept IsPoolAllocated = T::is_pool_allocated;

template <typename T>
concept IsUnique = T::is_unique;

template <typename T>
concept IsObject = T::is_object;
} // namespace VkBindings::Concepts
