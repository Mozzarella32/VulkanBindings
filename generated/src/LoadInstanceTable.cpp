#include "VkBindings/Handles.hpp"
#include "VkBindings/private/FunctionTables.hpp"
#include "VkBindings/private/Loader.hpp"

namespace VkBindings::impl_Loader {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
auto LoadInstanceTable(Handle::Instance instance) -> Dispatcher {
	Dispatcher dispatcher = {};
	InstanceTable& table = dispatcher.instanceTable;
	table.acquireDrmDisplayEXT = reinterpret_cast<PFN::AcquireDrmDisplayEXT>(getInstanceProcAddr(instance, "vkAcquireDrmDisplayEXT"));
	table.createDebugReportCallbackEXT = reinterpret_cast<PFN::CreateDebugReportCallbackEXT>(getInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT"));
	table.createDebugUtilsMessengerEXT = reinterpret_cast<PFN::CreateDebugUtilsMessengerEXT>(getInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT"));
	table.createDevice = reinterpret_cast<PFN::CreateDevice>(getInstanceProcAddr(instance, "vkCreateDevice"));
	table.createDisplayModeKHR = reinterpret_cast<PFN::CreateDisplayModeKHR>(getInstanceProcAddr(instance, "vkCreateDisplayModeKHR"));
	table.createDisplayPlaneSurfaceKHR = reinterpret_cast<PFN::CreateDisplayPlaneSurfaceKHR>(getInstanceProcAddr(instance, "vkCreateDisplayPlaneSurfaceKHR"));
	table.createHeadlessSurfaceEXT = reinterpret_cast<PFN::CreateHeadlessSurfaceEXT>(getInstanceProcAddr(instance, "vkCreateHeadlessSurfaceEXT"));
	table.debugReportMessageEXT = reinterpret_cast<PFN::DebugReportMessageEXT>(getInstanceProcAddr(instance, "vkDebugReportMessageEXT"));
	table.destroyDebugReportCallbackEXT = reinterpret_cast<PFN::DestroyDebugReportCallbackEXT>(getInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT"));
	table.destroyDebugUtilsMessengerEXT = reinterpret_cast<PFN::DestroyDebugUtilsMessengerEXT>(getInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT"));
	table.destroyInstance = reinterpret_cast<PFN::DestroyInstance>(getInstanceProcAddr(instance, "vkDestroyInstance"));
	table.destroySurfaceKHR = reinterpret_cast<PFN::DestroySurfaceKHR>(getInstanceProcAddr(instance, "vkDestroySurfaceKHR"));
	table.enumerateDeviceExtensionProperties = reinterpret_cast<PFN::EnumerateDeviceExtensionProperties>(getInstanceProcAddr(instance, "vkEnumerateDeviceExtensionProperties"));
	table.enumerateDeviceLayerProperties = reinterpret_cast<PFN::EnumerateDeviceLayerProperties>(getInstanceProcAddr(instance, "vkEnumerateDeviceLayerProperties"));
	table.enumeratePhysicalDeviceGroups = reinterpret_cast<PFN::EnumeratePhysicalDeviceGroups>(getInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceGroups"));
	table.enumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM = reinterpret_cast<PFN::EnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM>(getInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM"));
	table.enumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR = reinterpret_cast<PFN::EnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR>(getInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR"));
	table.enumeratePhysicalDeviceShaderInstrumentationMetricsARM = reinterpret_cast<PFN::EnumeratePhysicalDeviceShaderInstrumentationMetricsARM>(getInstanceProcAddr(instance, "vkEnumeratePhysicalDeviceShaderInstrumentationMetricsARM"));
	table.enumeratePhysicalDevices = reinterpret_cast<PFN::EnumeratePhysicalDevices>(getInstanceProcAddr(instance, "vkEnumeratePhysicalDevices"));
	table.getDeviceProcAddr = reinterpret_cast<PFN::GetDeviceProcAddr>(getInstanceProcAddr(instance, "vkGetDeviceProcAddr"));
	table.getDisplayModeProperties2KHR = reinterpret_cast<PFN::GetDisplayModeProperties2KHR>(getInstanceProcAddr(instance, "vkGetDisplayModeProperties2KHR"));
	table.getDisplayModePropertiesKHR = reinterpret_cast<PFN::GetDisplayModePropertiesKHR>(getInstanceProcAddr(instance, "vkGetDisplayModePropertiesKHR"));
	table.getDisplayPlaneCapabilities2KHR = reinterpret_cast<PFN::GetDisplayPlaneCapabilities2KHR>(getInstanceProcAddr(instance, "vkGetDisplayPlaneCapabilities2KHR"));
	table.getDisplayPlaneCapabilitiesKHR = reinterpret_cast<PFN::GetDisplayPlaneCapabilitiesKHR>(getInstanceProcAddr(instance, "vkGetDisplayPlaneCapabilitiesKHR"));
	table.getDisplayPlaneSupportedDisplaysKHR = reinterpret_cast<PFN::GetDisplayPlaneSupportedDisplaysKHR>(getInstanceProcAddr(instance, "vkGetDisplayPlaneSupportedDisplaysKHR"));
	table.getDrmDisplayEXT = reinterpret_cast<PFN::GetDrmDisplayEXT>(getInstanceProcAddr(instance, "vkGetDrmDisplayEXT"));
	table.getPhysicalDeviceCalibrateableTimeDomainsKHR = reinterpret_cast<PFN::GetPhysicalDeviceCalibrateableTimeDomainsKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceCalibrateableTimeDomainsKHR"));
	table.getPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV = reinterpret_cast<PFN::GetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV"));
	table.getPhysicalDeviceCooperativeMatrixPropertiesKHR = reinterpret_cast<PFN::GetPhysicalDeviceCooperativeMatrixPropertiesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesKHR"));
	table.getPhysicalDeviceCooperativeMatrixPropertiesNV = reinterpret_cast<PFN::GetPhysicalDeviceCooperativeMatrixPropertiesNV>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceCooperativeMatrixPropertiesNV"));
	table.getPhysicalDeviceCooperativeVectorPropertiesNV = reinterpret_cast<PFN::GetPhysicalDeviceCooperativeVectorPropertiesNV>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceCooperativeVectorPropertiesNV"));
	table.getPhysicalDeviceDescriptorSizeEXT = reinterpret_cast<PFN::GetPhysicalDeviceDescriptorSizeEXT>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceDescriptorSizeEXT"));
	table.getPhysicalDeviceDisplayPlaneProperties2KHR = reinterpret_cast<PFN::GetPhysicalDeviceDisplayPlaneProperties2KHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayPlaneProperties2KHR"));
	table.getPhysicalDeviceDisplayPlanePropertiesKHR = reinterpret_cast<PFN::GetPhysicalDeviceDisplayPlanePropertiesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayPlanePropertiesKHR"));
	table.getPhysicalDeviceDisplayProperties2KHR = reinterpret_cast<PFN::GetPhysicalDeviceDisplayProperties2KHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayProperties2KHR"));
	table.getPhysicalDeviceDisplayPropertiesKHR = reinterpret_cast<PFN::GetPhysicalDeviceDisplayPropertiesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceDisplayPropertiesKHR"));
	table.getPhysicalDeviceExternalBufferProperties = reinterpret_cast<PFN::GetPhysicalDeviceExternalBufferProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalBufferProperties"));
	table.getPhysicalDeviceExternalFenceProperties = reinterpret_cast<PFN::GetPhysicalDeviceExternalFenceProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalFenceProperties"));
	table.getPhysicalDeviceExternalImageFormatPropertiesNV = reinterpret_cast<PFN::GetPhysicalDeviceExternalImageFormatPropertiesNV>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalImageFormatPropertiesNV"));
	table.getPhysicalDeviceExternalSemaphoreProperties = reinterpret_cast<PFN::GetPhysicalDeviceExternalSemaphoreProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalSemaphoreProperties"));
	table.getPhysicalDeviceExternalTensorPropertiesARM = reinterpret_cast<PFN::GetPhysicalDeviceExternalTensorPropertiesARM>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceExternalTensorPropertiesARM"));
	table.getPhysicalDeviceFeatures = reinterpret_cast<PFN::GetPhysicalDeviceFeatures>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures"));
	table.getPhysicalDeviceFeatures2 = reinterpret_cast<PFN::GetPhysicalDeviceFeatures2>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceFeatures2"));
	table.getPhysicalDeviceFormatProperties = reinterpret_cast<PFN::GetPhysicalDeviceFormatProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties"));
	table.getPhysicalDeviceFormatProperties2 = reinterpret_cast<PFN::GetPhysicalDeviceFormatProperties2>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceFormatProperties2"));
	table.getPhysicalDeviceFragmentShadingRatesKHR = reinterpret_cast<PFN::GetPhysicalDeviceFragmentShadingRatesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceFragmentShadingRatesKHR"));
	table.getPhysicalDeviceImageFormatProperties = reinterpret_cast<PFN::GetPhysicalDeviceImageFormatProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties"));
	table.getPhysicalDeviceImageFormatProperties2 = reinterpret_cast<PFN::GetPhysicalDeviceImageFormatProperties2>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceImageFormatProperties2"));
	table.getPhysicalDeviceMemoryProperties = reinterpret_cast<PFN::GetPhysicalDeviceMemoryProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties"));
	table.getPhysicalDeviceMemoryProperties2 = reinterpret_cast<PFN::GetPhysicalDeviceMemoryProperties2>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceMemoryProperties2"));
	table.getPhysicalDeviceMultisamplePropertiesEXT = reinterpret_cast<PFN::GetPhysicalDeviceMultisamplePropertiesEXT>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceMultisamplePropertiesEXT"));
	table.getPhysicalDeviceOpticalFlowImageFormatsNV = reinterpret_cast<PFN::GetPhysicalDeviceOpticalFlowImageFormatsNV>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceOpticalFlowImageFormatsNV"));
	table.getPhysicalDevicePresentRectanglesKHR = reinterpret_cast<PFN::GetPhysicalDevicePresentRectanglesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDevicePresentRectanglesKHR"));
	table.getPhysicalDeviceProperties = reinterpret_cast<PFN::GetPhysicalDeviceProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties"));
	table.getPhysicalDeviceProperties2 = reinterpret_cast<PFN::GetPhysicalDeviceProperties2>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceProperties2"));
	table.getPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM = reinterpret_cast<PFN::GetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM"));
	table.getPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM = reinterpret_cast<PFN::GetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM"));
	table.getPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM = reinterpret_cast<PFN::GetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM"));
	table.getPhysicalDeviceQueueFamilyDataGraphPropertiesARM = reinterpret_cast<PFN::GetPhysicalDeviceQueueFamilyDataGraphPropertiesARM>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyDataGraphPropertiesARM"));
	table.getPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR = reinterpret_cast<PFN::GetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR"));
	table.getPhysicalDeviceQueueFamilyProperties = reinterpret_cast<PFN::GetPhysicalDeviceQueueFamilyProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties"));
	table.getPhysicalDeviceQueueFamilyProperties2 = reinterpret_cast<PFN::GetPhysicalDeviceQueueFamilyProperties2>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceQueueFamilyProperties2"));
	table.getPhysicalDeviceSparseImageFormatProperties = reinterpret_cast<PFN::GetPhysicalDeviceSparseImageFormatProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties"));
	table.getPhysicalDeviceSparseImageFormatProperties2 = reinterpret_cast<PFN::GetPhysicalDeviceSparseImageFormatProperties2>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSparseImageFormatProperties2"));
	table.getPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV = reinterpret_cast<PFN::GetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV"));
	table.getPhysicalDeviceSurfaceCapabilities2EXT = reinterpret_cast<PFN::GetPhysicalDeviceSurfaceCapabilities2EXT>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilities2EXT"));
	table.getPhysicalDeviceSurfaceCapabilities2KHR = reinterpret_cast<PFN::GetPhysicalDeviceSurfaceCapabilities2KHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilities2KHR"));
	table.getPhysicalDeviceSurfaceCapabilitiesKHR = reinterpret_cast<PFN::GetPhysicalDeviceSurfaceCapabilitiesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
	table.getPhysicalDeviceSurfaceFormats2KHR = reinterpret_cast<PFN::GetPhysicalDeviceSurfaceFormats2KHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceFormats2KHR"));
	table.getPhysicalDeviceSurfaceFormatsKHR = reinterpret_cast<PFN::GetPhysicalDeviceSurfaceFormatsKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceFormatsKHR"));
	table.getPhysicalDeviceSurfacePresentModesKHR = reinterpret_cast<PFN::GetPhysicalDeviceSurfacePresentModesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfacePresentModesKHR"));
	table.getPhysicalDeviceSurfaceSupportKHR = reinterpret_cast<PFN::GetPhysicalDeviceSurfaceSupportKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfaceSupportKHR"));
	table.getPhysicalDeviceToolProperties = reinterpret_cast<PFN::GetPhysicalDeviceToolProperties>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceToolProperties"));
	table.getPhysicalDeviceVideoCapabilitiesKHR = reinterpret_cast<PFN::GetPhysicalDeviceVideoCapabilitiesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceVideoCapabilitiesKHR"));
	table.getPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR = reinterpret_cast<PFN::GetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR"));
	table.getPhysicalDeviceVideoFormatPropertiesKHR = reinterpret_cast<PFN::GetPhysicalDeviceVideoFormatPropertiesKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceVideoFormatPropertiesKHR"));
	table.releaseDisplayEXT = reinterpret_cast<PFN::ReleaseDisplayEXT>(getInstanceProcAddr(instance, "vkReleaseDisplayEXT"));
	table.submitDebugUtilsMessageEXT = reinterpret_cast<PFN::SubmitDebugUtilsMessageEXT>(getInstanceProcAddr(instance, "vkSubmitDebugUtilsMessageEXT"));
	#ifdef VK_USE_PLATFORM_ANDROID_KHR
		table.createAndroidSurfaceKHR = reinterpret_cast<PFN::CreateAndroidSurfaceKHR>(getInstanceProcAddr(instance, "vkCreateAndroidSurfaceKHR"));
	#endif // VK_USE_PLATFORM_ANDROID_KHR
	#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
		table.createDirectFBSurfaceEXT = reinterpret_cast<PFN::CreateDirectFBSurfaceEXT>(getInstanceProcAddr(instance, "vkCreateDirectFBSurfaceEXT"));
		table.getPhysicalDeviceDirectFBPresentationSupportEXT = reinterpret_cast<PFN::GetPhysicalDeviceDirectFBPresentationSupportEXT>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceDirectFBPresentationSupportEXT"));
	#endif // VK_USE_PLATFORM_DIRECTFB_EXT
	#ifdef VK_USE_PLATFORM_FUCHSIA
		table.createImagePipeSurfaceFUCHSIA = reinterpret_cast<PFN::CreateImagePipeSurfaceFUCHSIA>(getInstanceProcAddr(instance, "vkCreateImagePipeSurfaceFUCHSIA"));
	#endif // VK_USE_PLATFORM_FUCHSIA
	#ifdef VK_USE_PLATFORM_GGP
		table.createStreamDescriptorSurfaceGGP = reinterpret_cast<PFN::CreateStreamDescriptorSurfaceGGP>(getInstanceProcAddr(instance, "vkCreateStreamDescriptorSurfaceGGP"));
	#endif // VK_USE_PLATFORM_GGP
	#ifdef VK_USE_PLATFORM_IOS_MVK
		table.createIOSSurfaceMVK = reinterpret_cast<PFN::CreateIOSSurfaceMVK>(getInstanceProcAddr(instance, "vkCreateIOSSurfaceMVK"));
	#endif // VK_USE_PLATFORM_IOS_MVK
	#ifdef VK_USE_PLATFORM_MACOS_MVK
		table.createMacOSSurfaceMVK = reinterpret_cast<PFN::CreateMacOSSurfaceMVK>(getInstanceProcAddr(instance, "vkCreateMacOSSurfaceMVK"));
	#endif // VK_USE_PLATFORM_MACOS_MVK
	#ifdef VK_USE_PLATFORM_METAL_EXT
		table.createMetalSurfaceEXT = reinterpret_cast<PFN::CreateMetalSurfaceEXT>(getInstanceProcAddr(instance, "vkCreateMetalSurfaceEXT"));
	#endif // VK_USE_PLATFORM_METAL_EXT
	#ifdef VK_USE_PLATFORM_OHOS
		table.createSurfaceOHOS = reinterpret_cast<PFN::CreateSurfaceOHOS>(getInstanceProcAddr(instance, "vkCreateSurfaceOHOS"));
	#endif // VK_USE_PLATFORM_OHOS
	#ifdef VK_USE_PLATFORM_SCREEN_QNX
		table.createScreenSurfaceQNX = reinterpret_cast<PFN::CreateScreenSurfaceQNX>(getInstanceProcAddr(instance, "vkCreateScreenSurfaceQNX"));
		table.getPhysicalDeviceScreenPresentationSupportQNX = reinterpret_cast<PFN::GetPhysicalDeviceScreenPresentationSupportQNX>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceScreenPresentationSupportQNX"));
	#endif // VK_USE_PLATFORM_SCREEN_QNX
	#ifdef VK_USE_PLATFORM_UBM_SEC
		table.createUbmSurfaceSEC = reinterpret_cast<PFN::CreateUbmSurfaceSEC>(getInstanceProcAddr(instance, "vkCreateUbmSurfaceSEC"));
		table.getPhysicalDeviceUbmPresentationSupportSEC = reinterpret_cast<PFN::GetPhysicalDeviceUbmPresentationSupportSEC>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceUbmPresentationSupportSEC"));
	#endif // VK_USE_PLATFORM_UBM_SEC
	#ifdef VK_USE_PLATFORM_VI_NN
		table.createViSurfaceNN = reinterpret_cast<PFN::CreateViSurfaceNN>(getInstanceProcAddr(instance, "vkCreateViSurfaceNN"));
	#endif // VK_USE_PLATFORM_VI_NN
	#ifdef VK_USE_PLATFORM_WAYLAND_KHR
		table.createWaylandSurfaceKHR = reinterpret_cast<PFN::CreateWaylandSurfaceKHR>(getInstanceProcAddr(instance, "vkCreateWaylandSurfaceKHR"));
		table.getPhysicalDeviceWaylandPresentationSupportKHR = reinterpret_cast<PFN::GetPhysicalDeviceWaylandPresentationSupportKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceWaylandPresentationSupportKHR"));
	#endif // VK_USE_PLATFORM_WAYLAND_KHR
	#ifdef VK_USE_PLATFORM_WIN32_KHR
		table.acquireWinrtDisplayNV = reinterpret_cast<PFN::AcquireWinrtDisplayNV>(getInstanceProcAddr(instance, "vkAcquireWinrtDisplayNV"));
		table.createWin32SurfaceKHR = reinterpret_cast<PFN::CreateWin32SurfaceKHR>(getInstanceProcAddr(instance, "vkCreateWin32SurfaceKHR"));
		table.getPhysicalDeviceSurfacePresentModes2EXT = reinterpret_cast<PFN::GetPhysicalDeviceSurfacePresentModes2EXT>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceSurfacePresentModes2EXT"));
		table.getPhysicalDeviceWin32PresentationSupportKHR = reinterpret_cast<PFN::GetPhysicalDeviceWin32PresentationSupportKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceWin32PresentationSupportKHR"));
		table.getWinrtDisplayNV = reinterpret_cast<PFN::GetWinrtDisplayNV>(getInstanceProcAddr(instance, "vkGetWinrtDisplayNV"));
	#endif // VK_USE_PLATFORM_WIN32_KHR
	#ifdef VK_USE_PLATFORM_XCB_KHR
		table.createXcbSurfaceKHR = reinterpret_cast<PFN::CreateXcbSurfaceKHR>(getInstanceProcAddr(instance, "vkCreateXcbSurfaceKHR"));
		table.getPhysicalDeviceXcbPresentationSupportKHR = reinterpret_cast<PFN::GetPhysicalDeviceXcbPresentationSupportKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceXcbPresentationSupportKHR"));
	#endif // VK_USE_PLATFORM_XCB_KHR
	#ifdef VK_USE_PLATFORM_XLIB_KHR
		table.createXlibSurfaceKHR = reinterpret_cast<PFN::CreateXlibSurfaceKHR>(getInstanceProcAddr(instance, "vkCreateXlibSurfaceKHR"));
		table.getPhysicalDeviceXlibPresentationSupportKHR = reinterpret_cast<PFN::GetPhysicalDeviceXlibPresentationSupportKHR>(getInstanceProcAddr(instance, "vkGetPhysicalDeviceXlibPresentationSupportKHR"));
	#endif // VK_USE_PLATFORM_XLIB_KHR
	#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
		table.acquireXlibDisplayEXT = reinterpret_cast<PFN::AcquireXlibDisplayEXT>(getInstanceProcAddr(instance, "vkAcquireXlibDisplayEXT"));
		table.getRandROutputDisplayEXT = reinterpret_cast<PFN::GetRandROutputDisplayEXT>(getInstanceProcAddr(instance, "vkGetRandROutputDisplayEXT"));
	#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
	return dispatcher;
}
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings::impl_Loader
