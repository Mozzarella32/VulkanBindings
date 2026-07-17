#pragma once

#include "VkBindings/Handles.hpp"
#include "VkBindings/private/FunctionTables.hpp"

namespace VkBindings::impl_Loader {
void LoadGlobals();
struct Dispatcher {
    InstanceTable instanceTable = {};
    DeviceTable deviceTable = {};
};
auto LoadInstanceTable(Handle::Instance instance) -> Dispatcher;
auto LoadDeviceTable(Handle::Device device, const Dispatcher &instanceDispatcher) -> Dispatcher;
} // namespace VkBindings::impl_Loader
