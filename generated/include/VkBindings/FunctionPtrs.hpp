#pragma once

#include "VkBindings/BaseTypes.hpp"
#include "VkBindings/Bits.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Flags.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/private/vk_platform.h"

#include <cstddef>
#include <cstdint>

namespace VkBindings {
struct DeviceMemoryReportCallbackDataEXT;
struct DebugUtilsMessengerCallbackDataEXT;
namespace PFN {
using AllocationFunction = auto (VKAPI_PTR *)(void *, size_t, size_t, SystemAllocationScope) -> void;
using DebugReportCallbackEXT = auto (VKAPI_PTR *)(DebugReportFlagsEXT, DebugReportObjectTypeEXT, uint64_t, size_t, int32_t, const char *, const char *, void *) -> Bool32;
using DebugUtilsMessengerCallbackEXT = auto (VKAPI_PTR *)(DebugUtilsMessageSeverityBitsEXT, DebugUtilsMessageTypeFlagsEXT, const DebugUtilsMessengerCallbackDataEXT *, void *) -> Bool32;
using DeviceMemoryReportCallbackEXT = auto (VKAPI_PTR *)(const DeviceMemoryReportCallbackDataEXT *, void *) -> void;
using FreeFunction = auto (VKAPI_PTR *)(void *, void *) -> void;
using InternalAllocationNotification = auto (VKAPI_PTR *)(void *, size_t, InternalAllocationType, SystemAllocationScope) -> void;
using InternalFreeNotification = auto (VKAPI_PTR *)(void *, size_t, InternalAllocationType, SystemAllocationScope) -> void;
using ReallocationFunction = auto (VKAPI_PTR *)(void *, void *, size_t, size_t, SystemAllocationScope) -> void;
using VoidFunction = auto (VKAPI_PTR *)() -> void;
using GetInstanceProcAddrLUNARG = auto (VKAPI_PTR *)(Handle::Instance, const char *) -> VoidFunction;
} // namespace PFN
} // namespace VkBindings
