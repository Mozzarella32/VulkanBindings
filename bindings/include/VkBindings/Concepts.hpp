#pragma once

namespace VkBindings::Concepts {
template <typename T>
concept HasHandleConstructor = T::has_handle_constructor;

template <typename T>
concept ABIIsHandle =
    sizeof(T) == sizeof(typename T::handle_type) && alignof(T) == alignof(typename T::handle_type);
} // namespace VkBindings::Concepts
