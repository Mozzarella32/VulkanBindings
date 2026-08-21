#include "VkBindings/BaseTypes.hpp"
#include "VkBindings/Defines.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/Creator.hpp"

#include <cstdint>
#include <expected>
#include <tuple>
#include <vector>

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
auto PhysicalDevice::acquireDrmDisplayEXT(int32_t drmFd, const DisplayKHR &display) const -> Result {
	return getInstanceTable().acquireDrmDisplayEXT(getHandle(), drmFd, display);
}
auto PhysicalDevice::createDevice(const DeviceCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDevice, Result> {
	Handle::Device pDevice = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getInstanceTable().createDevice(getHandle(), (&createInfo), pAllocator, &pDevice); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDevice>(impl_Objects::Creator::create<Device>(pDevice, getDispatcher()), pAllocator);
}
auto PhysicalDevice::createDisplayModeKHR(const DisplayKHR &display, const DisplayModeCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<DisplayModeKHR, Result> {
	Handle::DisplayModeKHR pMode = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getInstanceTable().createDisplayModeKHR(getHandle(), display, (&createInfo), pAllocator, &pMode); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<DisplayModeKHR>(pMode);
}
auto PhysicalDevice::enumerateDeviceExtensionProperties(const char *pLayerName) const -> std::expected<std::vector<ExtensionProperties>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().enumerateDeviceExtensionProperties(getHandle(), pLayerName, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<ExtensionProperties> properties(count);
	if (const Result res = getInstanceTable().enumerateDeviceExtensionProperties(getHandle(), pLayerName, &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::enumerateDeviceLayerProperties() const -> std::expected<std::vector<LayerProperties>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().enumerateDeviceLayerProperties(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<LayerProperties> properties(count);
	if (const Result res = getInstanceTable().enumerateDeviceLayerProperties(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::enumerateQueueFamilyPerformanceCountersByRegionARM(uint32_t queueFamilyIndex) const -> std::expected<std::tuple<std::vector<PerformanceCounterDescriptionARM>, std::vector<PerformanceCounterARM>>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(getHandle(), queueFamilyIndex, &count, nullptr, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PerformanceCounterDescriptionARM> counterDescriptions(count);
	std::vector<PerformanceCounterARM> counters(count);
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceQueueFamilyPerformanceCountersByRegionARM(getHandle(), queueFamilyIndex, &count, nullptr, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	counterDescriptions.resize(count);
	counters.resize(count);
	return std::make_tuple(counterDescriptions, counters);
}
auto PhysicalDevice::enumerateQueueFamilyPerformanceQueryCountersKHR(uint32_t queueFamilyIndex) const -> std::expected<std::tuple<std::vector<PerformanceCounterDescriptionKHR>, std::vector<PerformanceCounterKHR>>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(getHandle(), queueFamilyIndex, &count, nullptr, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PerformanceCounterDescriptionKHR> counterDescriptions(count);
	std::vector<PerformanceCounterKHR> counters(count);
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceQueueFamilyPerformanceQueryCountersKHR(getHandle(), queueFamilyIndex, &count, nullptr, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	counterDescriptions.resize(count);
	counters.resize(count);
	return std::make_tuple(counterDescriptions, counters);
}
auto PhysicalDevice::enumerateShaderInstrumentationMetricsARM() const -> std::expected<std::vector<ShaderInstrumentationMetricDescriptionARM>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceShaderInstrumentationMetricsARM(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<ShaderInstrumentationMetricDescriptionARM> descriptions(count);
	if (const Result res = getInstanceTable().enumeratePhysicalDeviceShaderInstrumentationMetricsARM(getHandle(), &count, descriptions.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	descriptions.resize(count);
	return descriptions;
}
auto PhysicalDevice::getDisplayModeProperties2KHR(const DisplayKHR &display) const -> std::expected<std::vector<DisplayModeProperties2KHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getDisplayModeProperties2KHR(getHandle(), display, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DisplayModeProperties2KHR> properties(count);
	if (const Result res = getInstanceTable().getDisplayModeProperties2KHR(getHandle(), display, &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getDisplayModePropertiesKHR(const DisplayKHR &display) const -> std::expected<std::vector<DisplayModePropertiesKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getDisplayModePropertiesKHR(getHandle(), display, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DisplayModePropertiesKHR> properties(count);
	if (const Result res = getInstanceTable().getDisplayModePropertiesKHR(getHandle(), display, &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getDisplayPlaneCapabilities2KHR(const DisplayPlaneInfo2KHR &displayPlaneInfo) const -> std::expected<DisplayPlaneCapabilities2KHR, Result> {
	DisplayPlaneCapabilities2KHR pCapabilities = {};
	if (const Result res = getInstanceTable().getDisplayPlaneCapabilities2KHR(getHandle(), (&displayPlaneInfo), &pCapabilities); res != Result::Success) {
		return std::unexpected(res);
	}
	return pCapabilities;
}
auto PhysicalDevice::getDisplayPlaneCapabilitiesKHR(const DisplayModeKHR &mode, uint32_t planeIndex) const -> std::expected<DisplayPlaneCapabilitiesKHR, Result> {
	DisplayPlaneCapabilitiesKHR pCapabilities = {};
	if (const Result res = getInstanceTable().getDisplayPlaneCapabilitiesKHR(getHandle(), mode, planeIndex, &pCapabilities); res != Result::Success) {
		return std::unexpected(res);
	}
	return pCapabilities;
}
auto PhysicalDevice::getDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex) const -> std::expected<std::vector<DisplayKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getDisplayPlaneSupportedDisplaysKHR(getHandle(), planeIndex, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DisplayKHR> displays(count);
	if (const Result res = getInstanceTable().getDisplayPlaneSupportedDisplaysKHR(getHandle(), planeIndex, &count, reinterpret_cast<Handle::DisplayKHR*>(displays.data())); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	displays.resize(count);
	return displays;
}
auto PhysicalDevice::getDrmDisplayEXT(int32_t drmFd, uint32_t connectorId) const -> std::expected<UniqueDisplayKHR, Result> {
	Handle::DisplayKHR display = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getInstanceTable().getDrmDisplayEXT(getHandle(), drmFd, connectorId, &display); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDisplayKHR>(impl_Objects::Creator::create<DisplayKHR>(display), getHandle(), getDispatcher(), nullptr);
}
auto PhysicalDevice::getCalibrateableTimeDomainsKHR() const -> std::expected<std::vector<TimeDomainKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceCalibrateableTimeDomainsKHR(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<TimeDomainKHR> timeDomains(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceCalibrateableTimeDomainsKHR(getHandle(), &count, timeDomains.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	timeDomains.resize(count);
	return timeDomains;
}
auto PhysicalDevice::getCooperativeMatrixFlexibleDimensionsPropertiesNV() const -> std::expected<std::vector<CooperativeMatrixFlexibleDimensionsPropertiesNV>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<CooperativeMatrixFlexibleDimensionsPropertiesNV> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeMatrixFlexibleDimensionsPropertiesNV(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getCooperativeMatrixPropertiesKHR() const -> std::expected<std::vector<CooperativeMatrixPropertiesKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeMatrixPropertiesKHR(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<CooperativeMatrixPropertiesKHR> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeMatrixPropertiesKHR(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getCooperativeMatrixPropertiesNV() const -> std::expected<std::vector<CooperativeMatrixPropertiesNV>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeMatrixPropertiesNV(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<CooperativeMatrixPropertiesNV> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeMatrixPropertiesNV(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getCooperativeVectorPropertiesNV() const -> std::expected<std::vector<CooperativeVectorPropertiesNV>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeVectorPropertiesNV(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<CooperativeVectorPropertiesNV> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceCooperativeVectorPropertiesNV(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getDescriptorSizeEXT(DescriptorType descriptorType) const -> DeviceSize {
	return getInstanceTable().getPhysicalDeviceDescriptorSizeEXT(getHandle(), descriptorType);
}
auto PhysicalDevice::getDisplayPlaneProperties2KHR() const -> std::expected<std::vector<DisplayPlaneProperties2KHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayPlaneProperties2KHR(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DisplayPlaneProperties2KHR> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayPlaneProperties2KHR(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getDisplayPlanePropertiesKHR() const -> std::expected<std::vector<DisplayPlanePropertiesKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayPlanePropertiesKHR(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DisplayPlanePropertiesKHR> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayPlanePropertiesKHR(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getDisplayProperties2KHR() const -> std::expected<std::vector<DisplayProperties2KHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayProperties2KHR(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DisplayProperties2KHR> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayProperties2KHR(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getDisplayPropertiesKHR() const -> std::expected<std::vector<DisplayPropertiesKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayPropertiesKHR(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DisplayPropertiesKHR> properties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceDisplayPropertiesKHR(getHandle(), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getExternalBufferProperties(const PhysicalDeviceExternalBufferInfo &externalBufferInfo) const -> ExternalBufferProperties {
	ExternalBufferProperties pExternalBufferProperties = {};
	getInstanceTable().getPhysicalDeviceExternalBufferProperties(getHandle(), (&externalBufferInfo), &pExternalBufferProperties);
	return pExternalBufferProperties;
}
auto PhysicalDevice::getExternalFenceProperties(const PhysicalDeviceExternalFenceInfo &externalFenceInfo) const -> ExternalFenceProperties {
	ExternalFenceProperties pExternalFenceProperties = {};
	getInstanceTable().getPhysicalDeviceExternalFenceProperties(getHandle(), (&externalFenceInfo), &pExternalFenceProperties);
	return pExternalFenceProperties;
}
auto PhysicalDevice::getExternalImageFormatPropertiesNV(Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags, ExternalMemoryHandleTypeFlagsNV externalHandleType) const -> std::expected<ExternalImageFormatPropertiesNV, Result> {
	ExternalImageFormatPropertiesNV pExternalImageFormatProperties = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceExternalImageFormatPropertiesNV(getHandle(), format, type, tiling, usage, flags, externalHandleType, &pExternalImageFormatProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pExternalImageFormatProperties;
}
auto PhysicalDevice::getExternalSemaphoreProperties(const PhysicalDeviceExternalSemaphoreInfo &externalSemaphoreInfo) const -> ExternalSemaphoreProperties {
	ExternalSemaphoreProperties pExternalSemaphoreProperties = {};
	getInstanceTable().getPhysicalDeviceExternalSemaphoreProperties(getHandle(), (&externalSemaphoreInfo), &pExternalSemaphoreProperties);
	return pExternalSemaphoreProperties;
}
auto PhysicalDevice::getExternalTensorPropertiesARM(const PhysicalDeviceExternalTensorInfoARM &externalTensorInfo) const -> ExternalTensorPropertiesARM {
	ExternalTensorPropertiesARM pExternalTensorProperties = {};
	getInstanceTable().getPhysicalDeviceExternalTensorPropertiesARM(getHandle(), (&externalTensorInfo), &pExternalTensorProperties);
	return pExternalTensorProperties;
}
auto PhysicalDevice::getFeatures() const -> PhysicalDeviceFeatures {
	PhysicalDeviceFeatures pFeatures = {};
	getInstanceTable().getPhysicalDeviceFeatures(getHandle(), &pFeatures);
	return pFeatures;
}
auto PhysicalDevice::getFeatures2() const -> PhysicalDeviceFeatures2 {
	PhysicalDeviceFeatures2 pFeatures = {};
	getInstanceTable().getPhysicalDeviceFeatures2(getHandle(), &pFeatures);
	return pFeatures;
}
auto PhysicalDevice::getFormatProperties(Format format) const -> FormatProperties {
	FormatProperties pFormatProperties = {};
	getInstanceTable().getPhysicalDeviceFormatProperties(getHandle(), format, &pFormatProperties);
	return pFormatProperties;
}
auto PhysicalDevice::getFormatProperties2(Format format) const -> FormatProperties2 {
	FormatProperties2 pFormatProperties = {};
	getInstanceTable().getPhysicalDeviceFormatProperties2(getHandle(), format, &pFormatProperties);
	return pFormatProperties;
}
auto PhysicalDevice::getFragmentShadingRatesKHR() const -> std::expected<std::vector<PhysicalDeviceFragmentShadingRateKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceFragmentShadingRatesKHR(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PhysicalDeviceFragmentShadingRateKHR> fragmentShadingRates(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceFragmentShadingRatesKHR(getHandle(), &count, fragmentShadingRates.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	fragmentShadingRates.resize(count);
	return fragmentShadingRates;
}
auto PhysicalDevice::getImageFormatProperties(Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags) const -> std::expected<ImageFormatProperties, Result> {
	ImageFormatProperties pImageFormatProperties = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceImageFormatProperties(getHandle(), format, type, tiling, usage, flags, &pImageFormatProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pImageFormatProperties;
}
auto PhysicalDevice::getImageFormatProperties2(const PhysicalDeviceImageFormatInfo2 &imageFormatInfo) const -> std::expected<ImageFormatProperties2, Result> {
	ImageFormatProperties2 pImageFormatProperties = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceImageFormatProperties2(getHandle(), (&imageFormatInfo), &pImageFormatProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pImageFormatProperties;
}
auto PhysicalDevice::getMemoryProperties() const -> PhysicalDeviceMemoryProperties {
	PhysicalDeviceMemoryProperties pMemoryProperties = {};
	getInstanceTable().getPhysicalDeviceMemoryProperties(getHandle(), &pMemoryProperties);
	return pMemoryProperties;
}
auto PhysicalDevice::getMemoryProperties2() const -> PhysicalDeviceMemoryProperties2 {
	PhysicalDeviceMemoryProperties2 pMemoryProperties = {};
	getInstanceTable().getPhysicalDeviceMemoryProperties2(getHandle(), &pMemoryProperties);
	return pMemoryProperties;
}
auto PhysicalDevice::getMultisamplePropertiesEXT(SampleCountBits samples) const -> MultisamplePropertiesEXT {
	MultisamplePropertiesEXT pMultisampleProperties = {};
	getInstanceTable().getPhysicalDeviceMultisamplePropertiesEXT(getHandle(), samples, &pMultisampleProperties);
	return pMultisampleProperties;
}
auto PhysicalDevice::getOpticalFlowImageFormatsNV(const OpticalFlowImageFormatInfoNV &opticalFlowImageFormatInfo) const -> std::expected<std::vector<OpticalFlowImageFormatPropertiesNV>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceOpticalFlowImageFormatsNV(getHandle(), (&opticalFlowImageFormatInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<OpticalFlowImageFormatPropertiesNV> imageFormatProperties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceOpticalFlowImageFormatsNV(getHandle(), (&opticalFlowImageFormatInfo), &count, imageFormatProperties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	imageFormatProperties.resize(count);
	return imageFormatProperties;
}
auto PhysicalDevice::getPresentRectanglesKHR(const SurfaceKHR &surface) const -> std::expected<std::vector<Rect2D>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDevicePresentRectanglesKHR(getHandle(), surface, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<Rect2D> rects(count);
	if (const Result res = getInstanceTable().getPhysicalDevicePresentRectanglesKHR(getHandle(), surface, &count, rects.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	rects.resize(count);
	return rects;
}
auto PhysicalDevice::getProperties() const -> PhysicalDeviceProperties {
	PhysicalDeviceProperties pProperties = {};
	getInstanceTable().getPhysicalDeviceProperties(getHandle(), &pProperties);
	return pProperties;
}
auto PhysicalDevice::getProperties2() const -> PhysicalDeviceProperties2 {
	PhysicalDeviceProperties2 pProperties = {};
	getInstanceTable().getPhysicalDeviceProperties2(getHandle(), &pProperties);
	return pProperties;
}
auto PhysicalDevice::getQueueFamilyDataGraphEngineOperationPropertiesARM(uint32_t queueFamilyIndex, const QueueFamilyDataGraphPropertiesARM &queueFamilyDataGraphProperties) const -> std::expected<BaseOutStructure, Result> {
	BaseOutStructure pProperties = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceQueueFamilyDataGraphEngineOperationPropertiesARM(getHandle(), queueFamilyIndex, (&queueFamilyDataGraphProperties), &pProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pProperties;
}
auto PhysicalDevice::getQueueFamilyDataGraphOpticalFlowImageFormatsARM(uint32_t queueFamilyIndex, const QueueFamilyDataGraphPropertiesARM &queueFamilyDataGraphProperties, const DataGraphOpticalFlowImageFormatInfoARM &opticalFlowImageFormatInfo) const -> std::expected<std::vector<DataGraphOpticalFlowImageFormatPropertiesARM>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(getHandle(), queueFamilyIndex, (&queueFamilyDataGraphProperties), (&opticalFlowImageFormatInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DataGraphOpticalFlowImageFormatPropertiesARM> imageFormatProperties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceQueueFamilyDataGraphOpticalFlowImageFormatsARM(getHandle(), queueFamilyIndex, (&queueFamilyDataGraphProperties), (&opticalFlowImageFormatInfo), &count, imageFormatProperties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	imageFormatProperties.resize(count);
	return imageFormatProperties;
}
auto PhysicalDevice::getQueueFamilyDataGraphProcessingEnginePropertiesARM(const PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM &queueFamilyDataGraphProcessingEngineInfo) const -> QueueFamilyDataGraphProcessingEnginePropertiesARM {
	QueueFamilyDataGraphProcessingEnginePropertiesARM pQueueFamilyDataGraphProcessingEngineProperties = {};
	getInstanceTable().getPhysicalDeviceQueueFamilyDataGraphProcessingEnginePropertiesARM(getHandle(), (&queueFamilyDataGraphProcessingEngineInfo), &pQueueFamilyDataGraphProcessingEngineProperties);
	return pQueueFamilyDataGraphProcessingEngineProperties;
}
auto PhysicalDevice::getQueueFamilyDataGraphPropertiesARM(uint32_t queueFamilyIndex) const -> std::expected<std::vector<QueueFamilyDataGraphPropertiesARM>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceQueueFamilyDataGraphPropertiesARM(getHandle(), queueFamilyIndex, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<QueueFamilyDataGraphPropertiesARM> queueFamilyDataGraphProperties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceQueueFamilyDataGraphPropertiesARM(getHandle(), queueFamilyIndex, &count, queueFamilyDataGraphProperties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	queueFamilyDataGraphProperties.resize(count);
	return queueFamilyDataGraphProperties;
}
auto PhysicalDevice::getQueueFamilyPerformanceQueryPassesKHR(const QueryPoolPerformanceCreateInfoKHR &performanceQueryCreateInfo) const -> uint32_t {
	uint32_t pNumPasses = {};
	getInstanceTable().getPhysicalDeviceQueueFamilyPerformanceQueryPassesKHR(getHandle(), (&performanceQueryCreateInfo), &pNumPasses);
	return pNumPasses;
}
auto PhysicalDevice::getQueueFamilyProperties() const -> std::vector<QueueFamilyProperties> {
	uint32_t count = 0;
	getInstanceTable().getPhysicalDeviceQueueFamilyProperties(getHandle(), &count, nullptr);
	std::vector<QueueFamilyProperties> queueFamilyProperties(count);
	getInstanceTable().getPhysicalDeviceQueueFamilyProperties(getHandle(), &count, queueFamilyProperties.data());
	queueFamilyProperties.resize(count);
	return queueFamilyProperties;
}
auto PhysicalDevice::getQueueFamilyProperties2() const -> std::vector<QueueFamilyProperties2> {
	uint32_t count = 0;
	getInstanceTable().getPhysicalDeviceQueueFamilyProperties2(getHandle(), &count, nullptr);
	std::vector<QueueFamilyProperties2> queueFamilyProperties(count);
	getInstanceTable().getPhysicalDeviceQueueFamilyProperties2(getHandle(), &count, queueFamilyProperties.data());
	queueFamilyProperties.resize(count);
	return queueFamilyProperties;
}
auto PhysicalDevice::getSparseImageFormatProperties(Format format, ImageType type, SampleCountBits samples, ImageUsageFlags usage, ImageTiling tiling) const -> std::vector<SparseImageFormatProperties> {
	uint32_t count = 0;
	getInstanceTable().getPhysicalDeviceSparseImageFormatProperties(getHandle(), format, type, samples, usage, tiling, &count, nullptr);
	std::vector<SparseImageFormatProperties> properties(count);
	getInstanceTable().getPhysicalDeviceSparseImageFormatProperties(getHandle(), format, type, samples, usage, tiling, &count, properties.data());
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getSparseImageFormatProperties2(const PhysicalDeviceSparseImageFormatInfo2 &formatInfo) const -> std::vector<SparseImageFormatProperties2> {
	uint32_t count = 0;
	getInstanceTable().getPhysicalDeviceSparseImageFormatProperties2(getHandle(), (&formatInfo), &count, nullptr);
	std::vector<SparseImageFormatProperties2> properties(count);
	getInstanceTable().getPhysicalDeviceSparseImageFormatProperties2(getHandle(), (&formatInfo), &count, properties.data());
	properties.resize(count);
	return properties;
}
auto PhysicalDevice::getSupportedFramebufferMixedSamplesCombinationsNV() const -> std::expected<std::vector<FramebufferMixedSamplesCombinationNV>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<FramebufferMixedSamplesCombinationNV> combinations(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceSupportedFramebufferMixedSamplesCombinationsNV(getHandle(), &count, combinations.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	combinations.resize(count);
	return combinations;
}
auto PhysicalDevice::getSurfaceCapabilities2EXT(const SurfaceKHR &surface) const -> std::expected<SurfaceCapabilities2EXT, Result> {
	SurfaceCapabilities2EXT pSurfaceCapabilities = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceCapabilities2EXT(getHandle(), surface, &pSurfaceCapabilities); res != Result::Success) {
		return std::unexpected(res);
	}
	return pSurfaceCapabilities;
}
auto PhysicalDevice::getSurfaceCapabilities2KHR(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<SurfaceCapabilities2KHR, Result> {
	SurfaceCapabilities2KHR pSurfaceCapabilities = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceCapabilities2KHR(getHandle(), (&surfaceInfo), &pSurfaceCapabilities); res != Result::Success) {
		return std::unexpected(res);
	}
	return pSurfaceCapabilities;
}
auto PhysicalDevice::getSurfaceCapabilitiesKHR(const SurfaceKHR &surface) const -> std::expected<SurfaceCapabilitiesKHR, Result> {
	SurfaceCapabilitiesKHR pSurfaceCapabilities = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceCapabilitiesKHR(getHandle(), surface, &pSurfaceCapabilities); res != Result::Success) {
		return std::unexpected(res);
	}
	return pSurfaceCapabilities;
}
auto PhysicalDevice::getSurfaceFormats2KHR(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<std::vector<SurfaceFormat2KHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceFormats2KHR(getHandle(), (&surfaceInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<SurfaceFormat2KHR> surfaceFormats(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceFormats2KHR(getHandle(), (&surfaceInfo), &count, surfaceFormats.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	surfaceFormats.resize(count);
	return surfaceFormats;
}
auto PhysicalDevice::getSurfaceFormatsKHR(const SurfaceKHR &surface) const -> std::expected<std::vector<SurfaceFormatKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceFormatsKHR(getHandle(), surface, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<SurfaceFormatKHR> surfaceFormats(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceFormatsKHR(getHandle(), surface, &count, surfaceFormats.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	surfaceFormats.resize(count);
	return surfaceFormats;
}
auto PhysicalDevice::getSurfacePresentModesKHR(const SurfaceKHR &surface) const -> std::expected<std::vector<PresentModeKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfacePresentModesKHR(getHandle(), surface, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PresentModeKHR> presentModes(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfacePresentModesKHR(getHandle(), surface, &count, presentModes.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	presentModes.resize(count);
	return presentModes;
}
auto PhysicalDevice::getSurfaceSupportKHR(uint32_t queueFamilyIndex, const SurfaceKHR &surface) const -> std::expected<Bool32, Result> {
	Bool32 pSupported = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceSurfaceSupportKHR(getHandle(), queueFamilyIndex, surface, &pSupported); res != Result::Success) {
		return std::unexpected(res);
	}
	return pSupported;
}
auto PhysicalDevice::getToolProperties() const -> std::expected<std::vector<PhysicalDeviceToolProperties>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceToolProperties(getHandle(), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PhysicalDeviceToolProperties> toolProperties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceToolProperties(getHandle(), &count, toolProperties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	toolProperties.resize(count);
	return toolProperties;
}
auto PhysicalDevice::getVideoCapabilitiesKHR(const VideoProfileInfoKHR &videoProfile) const -> std::expected<VideoCapabilitiesKHR, Result> {
	VideoCapabilitiesKHR pCapabilities = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceVideoCapabilitiesKHR(getHandle(), (&videoProfile), &pCapabilities); res != Result::Success) {
		return std::unexpected(res);
	}
	return pCapabilities;
}
auto PhysicalDevice::getVideoEncodeQualityLevelPropertiesKHR(const PhysicalDeviceVideoEncodeQualityLevelInfoKHR &qualityLevelInfo) const -> std::expected<VideoEncodeQualityLevelPropertiesKHR, Result> {
	VideoEncodeQualityLevelPropertiesKHR pQualityLevelProperties = {};
	if (const Result res = getInstanceTable().getPhysicalDeviceVideoEncodeQualityLevelPropertiesKHR(getHandle(), (&qualityLevelInfo), &pQualityLevelProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pQualityLevelProperties;
}
auto PhysicalDevice::getVideoFormatPropertiesKHR(const PhysicalDeviceVideoFormatInfoKHR &videoFormatInfo) const -> std::expected<std::vector<VideoFormatPropertiesKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getInstanceTable().getPhysicalDeviceVideoFormatPropertiesKHR(getHandle(), (&videoFormatInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<VideoFormatPropertiesKHR> videoFormatProperties(count);
	if (const Result res = getInstanceTable().getPhysicalDeviceVideoFormatPropertiesKHR(getHandle(), (&videoFormatInfo), &count, videoFormatProperties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	videoFormatProperties.resize(count);
	return videoFormatProperties;
}
auto PhysicalDevice::releaseDisplayEXT(const DisplayKHR &display) const -> Result {
	return getInstanceTable().releaseDisplayEXT(getHandle(), display);
}
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
	auto PhysicalDevice::getDirectFBPresentationSupportEXT(uint32_t queueFamilyIndex, IDirectFB *dfb) const -> Bool32 {
		return getInstanceTable().getPhysicalDeviceDirectFBPresentationSupportEXT(getHandle(), queueFamilyIndex, dfb);
	}
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_SCREEN_QNX
	auto PhysicalDevice::getScreenPresentationSupportQNX(uint32_t queueFamilyIndex, struct _screen_window *window) const -> Bool32 {
		return getInstanceTable().getPhysicalDeviceScreenPresentationSupportQNX(getHandle(), queueFamilyIndex, window);
	}
#endif // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_UBM_SEC
	auto PhysicalDevice::getUbmPresentationSupportSEC(uint32_t queueFamilyIndex, struct ubm_device *device) const -> Bool32 {
		return getInstanceTable().getPhysicalDeviceUbmPresentationSupportSEC(getHandle(), queueFamilyIndex, device);
	}
#endif // VK_USE_PLATFORM_UBM_SEC
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
	auto PhysicalDevice::getWaylandPresentationSupportKHR(uint32_t queueFamilyIndex, struct wl_display *display) const -> Bool32 {
		return getInstanceTable().getPhysicalDeviceWaylandPresentationSupportKHR(getHandle(), queueFamilyIndex, display);
	}
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
	auto PhysicalDevice::acquireWinrtDisplayNV(const DisplayKHR &display) const -> Result {
		return getInstanceTable().acquireWinrtDisplayNV(getHandle(), display);
	}
	auto PhysicalDevice::getSurfacePresentModes2EXT(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<std::vector<PresentModeKHR>, Result> {
		uint32_t count = 0;
		if (const Result res = getInstanceTable().getPhysicalDeviceSurfacePresentModes2EXT(getHandle(), (&surfaceInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
			return std::unexpected(res);
		}
		std::vector<PresentModeKHR> presentModes(count);
		if (const Result res = getInstanceTable().getPhysicalDeviceSurfacePresentModes2EXT(getHandle(), (&surfaceInfo), &count, presentModes.data()); res != Result::Success &&res != Result::Incomplete) {
			return std::unexpected(res);
		}
		presentModes.resize(count);
		return presentModes;
	}
	auto PhysicalDevice::getWin32PresentationSupportKHR(uint32_t queueFamilyIndex) const -> Bool32 {
		return getInstanceTable().getPhysicalDeviceWin32PresentationSupportKHR(getHandle(), queueFamilyIndex);
	}
	auto PhysicalDevice::getWinrtDisplayNV(uint32_t deviceRelativeId) const -> std::expected<DisplayKHR, Result> {
		DisplayKHR pDisplay = {};
		if (const Result res = getInstanceTable().getWinrtDisplayNV(getHandle(), deviceRelativeId, &pDisplay); res != Result::Success) {
			return std::unexpected(res);
		}
		return pDisplay;
	}
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
	auto PhysicalDevice::getXcbPresentationSupportKHR(uint32_t queueFamilyIndex, xcb_connection_t *connection, xcb_visualid_t visual_id) const -> Bool32 {
		return getInstanceTable().getPhysicalDeviceXcbPresentationSupportKHR(getHandle(), queueFamilyIndex, connection, visual_id);
	}
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
	auto PhysicalDevice::getXlibPresentationSupportKHR(uint32_t queueFamilyIndex, Display *dpy, VisualID visualID) const -> Bool32 {
		return getInstanceTable().getPhysicalDeviceXlibPresentationSupportKHR(getHandle(), queueFamilyIndex, dpy, visualID);
	}
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
	auto PhysicalDevice::acquireXlibDisplayEXT(Display *dpy, const DisplayKHR &display) const -> Result {
		return getInstanceTable().acquireXlibDisplayEXT(getHandle(), dpy, display);
	}
	auto PhysicalDevice::getRandROutputDisplayEXT(Display *dpy, RROutput rrOutput) const -> std::expected<DisplayKHR, Result> {
		DisplayKHR pDisplay = {};
		if (const Result res = getInstanceTable().getRandROutputDisplayEXT(getHandle(), dpy, rrOutput, &pDisplay); res != Result::Success) {
			return std::unexpected(res);
		}
		return pDisplay;
	}
#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings
