#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

namespace VkBindings::impl_Loader {
// NOLINTBEGIN(cppcoreguidelines-avoid-non-const-global-variables)
PFN::CreateInstance createInstance = {};
PFN::EnumerateInstanceExtensionProperties enumerateInstanceExtensionProperties = {};
PFN::EnumerateInstanceLayerProperties enumerateInstanceLayerProperties = {};
PFN::EnumerateInstanceVersion enumerateInstanceVersion = {};
// NOLINTEND(cppcoreguidelines-avoid-non-const-global-variables)
void LoadGlobals() {
	// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
	createInstance = reinterpret_cast<PFN::CreateInstance>(getInstanceProcAddr(nullptr, "vkCreateInstance"));
	enumerateInstanceExtensionProperties = reinterpret_cast<PFN::EnumerateInstanceExtensionProperties>(getInstanceProcAddr(nullptr, "vkEnumerateInstanceExtensionProperties"));
	enumerateInstanceLayerProperties = reinterpret_cast<PFN::EnumerateInstanceLayerProperties>(getInstanceProcAddr(nullptr, "vkEnumerateInstanceLayerProperties"));
	enumerateInstanceVersion = reinterpret_cast<PFN::EnumerateInstanceVersion>(getInstanceProcAddr(nullptr, "vkEnumerateInstanceVersion"));
	// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
}
} // namespace VkBindings::impl_Loader
