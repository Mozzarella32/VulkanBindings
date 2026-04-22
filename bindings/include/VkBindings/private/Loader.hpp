#pragma once

#include "VkBindings/Enums.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Handles.hpp"

namespace VkBindings {
namespace impl_Loader {
void LoadGlobals();
struct Dispatcher {
    InstanceTable instanceTable = {};
    DeviceTable deviceTable = {};
};
Dispatcher LoadInstanceTable(impl_Objects::HandleInstance instance);
Dispatcher LoadDeviceTable(impl_Objects::HandleDevice device, const Dispatcher &instanceDispatcher);
} // namespace impl_Loader
} // namespace VkBindings
