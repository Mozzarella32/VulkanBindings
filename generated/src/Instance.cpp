#include "VkBindings/Defines.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/Creator.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"
#include "VkBindings/private/ObjectTemplatesIntreface.hpp"

#include <cstddef>
#include <cstdint>
#include <expected>
#include <ranges>
#include <utility>
#include <vector>

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)

auto Instance::adoptForignSurfaceKHR(SurfaceKHR &&surface) const -> UniqueSurfaceKHR {
    return impl_Objects::Creator::create<UniqueSurfaceKHR>(std::move(surface), getHandle(), getDispatcher(), nullptr);
}

auto Instance::createInstance(const InstanceCreateInfo &createInfo, const AllocationCallbacks *pAllocator) -> std::expected<UniqueInstance, Result> {
	Handle::Instance pInstance = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = impl_Loader::createInstance((&createInfo), pAllocator, &pInstance); res != Result::Success) {
		return std::unexpected(res);
	}
	const impl_Loader::Dispatcher empty;
	return impl_Objects::Creator::create<UniqueInstance>(impl_Objects::Creator::create<Instance>(pInstance, empty), pAllocator);
}
auto Instance::enumerateInstanceExtensionProperties(const char *pLayerName) -> std::expected<std::vector<ExtensionProperties>, Result> {
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
auto Instance::enumerateInstanceLayerProperties() -> std::expected<std::vector<LayerProperties>, Result> {
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
auto Instance::enumerateInstanceVersion() -> std::expected<uint32_t, Result> {
	uint32_t pApiVersion = {};
	if (const Result res = impl_Loader::enumerateInstanceVersion(&pApiVersion); res != Result::Success) {
		return std::unexpected(res);
	}
	return pApiVersion;
}
auto Instance::createDebugReportCallbackEXT(const DebugReportCallbackCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDebugReportCallbackEXT, Result> {
	Handle::DebugReportCallbackEXT pCallback = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getInstanceTable().createDebugReportCallbackEXT(getHandle(), (&createInfo), pAllocator, &pCallback); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDebugReportCallbackEXT>(impl_Objects::Creator::create<DebugReportCallbackEXT>(pCallback), getHandle(), getDispatcher(), pAllocator);
}
auto Instance::createDebugUtilsMessengerEXT(const DebugUtilsMessengerCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDebugUtilsMessengerEXT, Result> {
	Handle::DebugUtilsMessengerEXT pMessenger = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getInstanceTable().createDebugUtilsMessengerEXT(getHandle(), (&createInfo), pAllocator, &pMessenger); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDebugUtilsMessengerEXT>(impl_Objects::Creator::create<DebugUtilsMessengerEXT>(pMessenger), getHandle(), getDispatcher(), pAllocator);
}
auto Instance::createDisplayPlaneSurfaceKHR(const DisplaySurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
	Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getInstanceTable().createDisplayPlaneSurfaceKHR(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
}
auto Instance::createHeadlessSurfaceEXT(const HeadlessSurfaceCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
	Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getInstanceTable().createHeadlessSurfaceEXT(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
}
void Instance::debugReportMessageEXT(DebugReportFlagsEXT flags, DebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char *pLayerPrefix, const char *pMessage) const {
	getInstanceTable().debugReportMessageEXT(getHandle(), flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}
void Instance::destroyDebugReportCallbackEXT(const DebugReportCallbackEXT &callback, const AllocationCallbacks *pAllocator) const {
	getInstanceTable().destroyDebugReportCallbackEXT(getHandle(), callback, pAllocator);
}
void Instance::destroyDebugUtilsMessengerEXT(const DebugUtilsMessengerEXT &messenger, const AllocationCallbacks *pAllocator) const {
	getInstanceTable().destroyDebugUtilsMessengerEXT(getHandle(), messenger, pAllocator);
}
void Instance::destroyInstance(const AllocationCallbacks *pAllocator) const {
	getInstanceTable().destroyInstance(getHandle(), pAllocator);
}
void Instance::destroySurfaceKHR(const SurfaceKHR &surface, const AllocationCallbacks *pAllocator) const {
	getInstanceTable().destroySurfaceKHR(getHandle(), surface, pAllocator);
}
auto Instance::enumeratePhysicalDeviceGroups() const -> std::expected<std::vector<PhysicalDeviceGroupProperties>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceGroups(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PhysicalDeviceGroupProperties> physicalDeviceGroupProperties(count);
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceGroups(getHandle(), &count, physicalDeviceGroupProperties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	physicalDeviceGroupProperties.resize(count);
	return physicalDeviceGroupProperties;
}
auto Instance::enumeratePhysicalDevices() const -> std::expected<std::vector<PhysicalDevice>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().enumeratePhysicalDevices(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<Handle::PhysicalDevice> physicalDevices(count);
	if (const Result res = getInstanceTable().enumeratePhysicalDevices(getHandle(), &count, physicalDevices.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	return physicalDevices |
	       std::views::transform(
	           [this](Handle::PhysicalDevice handle) -> PhysicalDevice {
	               return impl_Objects::Creator::create<PhysicalDevice>(handle, getDispatcher());
	           }) |
	       std::ranges::to<std::vector>();
	
}
void Instance::submitDebugUtilsMessageEXT(DebugUtilsMessageSeverityBitsEXT messageSeverity, DebugUtilsMessageTypeFlagsEXT messageTypes, const DebugUtilsMessengerCallbackDataEXT &callbackData) const {
	getInstanceTable().submitDebugUtilsMessageEXT(getHandle(), messageSeverity, messageTypes, (&callbackData));
}
#ifdef VK_USE_PLATFORM_ANDROID_KHR
	auto Instance::createAndroidSurfaceKHR(const AndroidSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createAndroidSurfaceKHR(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
	auto Instance::createDirectFBSurfaceEXT(const DirectFBSurfaceCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createDirectFBSurfaceEXT(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_FUCHSIA
	auto Instance::createImagePipeSurfaceFUCHSIA(const ImagePipeSurfaceCreateInfoFUCHSIA &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createImagePipeSurfaceFUCHSIA(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_GGP
	auto Instance::createStreamDescriptorSurfaceGGP(const StreamDescriptorSurfaceCreateInfoGGP &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createStreamDescriptorSurfaceGGP(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_GGP
#ifdef VK_USE_PLATFORM_IOS_MVK
	auto Instance::createIOSSurfaceMVK(const IOSSurfaceCreateInfoMVK &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createIOSSurfaceMVK(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
	auto Instance::createMacOSSurfaceMVK(const MacOSSurfaceCreateInfoMVK &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createMacOSSurfaceMVK(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_MACOS_MVK
#ifdef VK_USE_PLATFORM_METAL_EXT
	auto Instance::createMetalSurfaceEXT(const MetalSurfaceCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createMetalSurfaceEXT(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_OHOS
	auto Instance::createSurfaceOHOS(const SurfaceCreateInfoOHOS &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createSurfaceOHOS(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_OHOS
#ifdef VK_USE_PLATFORM_SCREEN_QNX
	auto Instance::createScreenSurfaceQNX(const ScreenSurfaceCreateInfoQNX &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createScreenSurfaceQNX(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_UBM_SEC
	auto Instance::createUbmSurfaceSEC(const UbmSurfaceCreateInfoSEC &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createUbmSurfaceSEC(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_UBM_SEC
#ifdef VK_USE_PLATFORM_VI_NN
	auto Instance::createViSurfaceNN(const ViSurfaceCreateInfoNN &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createViSurfaceNN(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_VI_NN
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
	auto Instance::createWaylandSurfaceKHR(const WaylandSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createWaylandSurfaceKHR(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
	auto Instance::createWin32SurfaceKHR(const Win32SurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createWin32SurfaceKHR(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
	auto Instance::createXcbSurfaceKHR(const XcbSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createXcbSurfaceKHR(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
	auto Instance::createXlibSurfaceKHR(const XlibSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSurfaceKHR, Result> {
		Handle::SurfaceKHR pSurface = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getInstanceTable().createXlibSurfaceKHR(getHandle(), (&createInfo), pAllocator, &pSurface); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueSurfaceKHR>(impl_Objects::Creator::create<SurfaceKHR>(pSurface), getHandle(), getDispatcher(), pAllocator);
	}
#endif // VK_USE_PLATFORM_XLIB_KHR
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings
