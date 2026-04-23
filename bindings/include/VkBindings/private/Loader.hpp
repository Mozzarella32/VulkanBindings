#pragma once

#include "VkBindings/Enums.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/private/FunctionTables.hpp"

namespace VkBindings {
namespace impl_Loader {
void LoadGlobals();
struct Dispatcher {
    InstanceTable instanceTable = {};
    DeviceTable deviceTable = {};
};
Dispatcher LoadInstanceTable(Handle::Instance instance);
Dispatcher LoadDeviceTable(Handle::Device device, const Dispatcher &instanceDispatcher);
} // namespace impl_Loader
} // namespace VkBindings
