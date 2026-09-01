#include "VkBindings/Defines.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/Creator.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

#include <cstdint>
#include <expected>
#include <vector>

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
void ExternalComputeQueueNV::getExternalComputeQueueDataNV(ExternalComputeQueueDataParamsNV *params, void *pData) const {
	getDeviceTable().getExternalComputeQueueDataNV(getHandle(), params, pData);
}
auto createInstance(const InstanceCreateInfo &createInfo, const AllocationCallbacks *pAllocator) -> std::expected<UniqueInstance, Result> {
	Handle::Instance pInstance = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = impl_Loader::createInstance((&createInfo), pAllocator, &pInstance); res != Result::Success) {
		return std::unexpected(res);
	}
	const impl_Loader::Dispatcher empty;
	return impl_Objects::Creator::create<UniqueInstance>(impl_Objects::Creator::create<Instance>(pInstance, empty), pAllocator);
}
auto enumerateInstanceExtensionProperties(const char *pLayerName) -> std::expected<std::vector<ExtensionProperties>, Result> {
	uint32_t count = 0;
	if (const Result res = impl_Loader::enumerateInstanceExtensionProperties(pLayerName, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<ExtensionProperties> properties(count);
	if (const Result res = impl_Loader::enumerateInstanceExtensionProperties(pLayerName, &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto enumerateInstanceLayerProperties() -> std::expected<std::vector<LayerProperties>, Result> {
	uint32_t count = 0;
	if (const Result res = impl_Loader::enumerateInstanceLayerProperties(&count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<LayerProperties> properties(count);
	if (const Result res = impl_Loader::enumerateInstanceLayerProperties(&count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto enumerateInstanceVersion() -> std::expected<uint32_t, Result> {
	uint32_t pApiVersion = {};
	if (const Result res = impl_Loader::enumerateInstanceVersion(&pApiVersion); res != Result::Success) {
		return std::unexpected(res);
	}
	return pApiVersion;
}
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings
