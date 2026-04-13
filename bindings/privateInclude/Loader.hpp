#pragma once

#include "FunctionTables.hpp"
#include "Handles.hpp"
#include "VkBindings/Enums.hpp"

namespace VkBindings {
namespace impl_Loader {
void LoadGlobals();
InstanceTable LoadInstanceTable(impl_Objects::HandleInstance instance);
DeviceTable LoadDeviceTable(impl_Objects::HandleDevice device);
struct Dispatcher {
    InstanceTable *instanceTable;
    DeviceTable *deviceTable;
};
} // namespace impl_Loader
} // namespace VkBindings
