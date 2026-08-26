#pragma once

#include "VkBindings/Enums.hpp"
#include "VkBindings/private/FunctionTables.hpp"

namespace VkBindings::Loader {
// Init call before instance creation
auto Init() -> Result;
auto GetGetInstanceProcAddr() -> VkBindings::PFN::GetInstanceProcAddr;
} // namespace VkBindings::Loader
