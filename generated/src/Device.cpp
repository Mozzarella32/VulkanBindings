#include "VkBindings/BaseTypes.hpp"
#include "VkBindings/Defines.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/Creator.hpp"
#include "VkBindings/private/ObjectTemplatesIntreface.hpp"
#include "VkBindings/private/StructTemplatesInterface.hpp"

#include <cstddef>
#include <cstdint>
#include <expected>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
// NOLINTBEGIN(bugprone-easily-swappable-parameters)
auto Device::acquireNextImage2KHR(const AcquireNextImageInfoKHR &acquireInfo, uint32_t *pImageIndex) const -> Result {
	return getDeviceTable().acquireNextImage2KHR(getHandle(), (&acquireInfo), pImageIndex);
}
auto Device::acquireNextImageKHR(const SwapchainKHR &swapchain, uint64_t timeout, const Semaphore &semaphore, const Fence &fence, uint32_t *pImageIndex) const -> Result {
	return getDeviceTable().acquireNextImageKHR(getHandle(), swapchain, timeout, semaphore, fence, pImageIndex);
}
auto Device::acquirePerformanceConfigurationINTEL(const PerformanceConfigurationAcquireInfoINTEL &acquireInfo) const -> std::expected<UniquePerformanceConfigurationINTEL, Result> {
	Handle::PerformanceConfigurationINTEL pConfiguration = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().acquirePerformanceConfigurationINTEL(getHandle(), (&acquireInfo), &pConfiguration); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniquePerformanceConfigurationINTEL>(impl_Objects::Creator::create<PerformanceConfigurationINTEL>(pConfiguration), getHandle(), getDispatcher(), nullptr);
}
auto Device::acquireProfilingLockKHR(const AcquireProfilingLockInfoKHR &info) const -> Result {
	return getDeviceTable().acquireProfilingLockKHR(getHandle(), (&info));
}
auto Device::allocateCommandBuffers(const CommandBufferAllocateInfo &allocateInfo) const -> std::expected<CommandBuffers, Result> {
	std::vector<Handle::CommandBuffer> handles((&allocateInfo)->commandBufferCount);
	if (const Result res = getDeviceTable().allocateCommandBuffers(getHandle(), (&allocateInfo), handles.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<CommandBuffers>(std::move(handles), (&allocateInfo)->commandPool, getHandle(), getDispatcher());
}
auto Device::allocateDescriptorSets(const DescriptorSetAllocateInfo &allocateInfo) const -> std::expected<DescriptorSets, Result> {
	std::vector<Handle::DescriptorSet> handles((&allocateInfo)->descriptorSetCount);
	if (const Result res = getDeviceTable().allocateDescriptorSets(getHandle(), (&allocateInfo), handles.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<DescriptorSets>(std::move(handles), (&allocateInfo)->descriptorPool, getHandle(), getDispatcher());
}
auto Device::allocateMemory(const MemoryAllocateInfo &allocateInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDeviceMemory, Result> {
	Handle::DeviceMemory pMemory = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().allocateMemory(getHandle(), (&allocateInfo), pAllocator, &pMemory); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDeviceMemory>(impl_Objects::Creator::create<DeviceMemory>(pMemory), getHandle(), getDispatcher(), pAllocator);
}
void Device::antiLagUpdateAMD(const AntiLagDataAMD &data) const {
	getDeviceTable().antiLagUpdateAMD(getHandle(), (&data));
}
auto Device::bindAccelerationStructureMemoryNV(const impl_Struct::ArrayProxy<BindAccelerationStructureMemoryInfoNV> &bindInfos) const -> Result {
	return getDeviceTable().bindAccelerationStructureMemoryNV(getHandle(), static_cast<uint32_t>(bindInfos.size()), bindInfos.data());
}
auto Device::bindBufferMemory(const Buffer &buffer, const DeviceMemory &memory, DeviceSize memoryOffset) const -> Result {
	return getDeviceTable().bindBufferMemory(getHandle(), buffer, memory, memoryOffset);
}
auto Device::bindBufferMemory2(const impl_Struct::ArrayProxy<BindBufferMemoryInfo> &bindInfos) const -> Result {
	return getDeviceTable().bindBufferMemory2(getHandle(), static_cast<uint32_t>(bindInfos.size()), bindInfos.data());
}
auto Device::bindDataGraphPipelineSessionMemoryARM(const impl_Struct::ArrayProxy<BindDataGraphPipelineSessionMemoryInfoARM> &bindInfos) const -> Result {
	return getDeviceTable().bindDataGraphPipelineSessionMemoryARM(getHandle(), static_cast<uint32_t>(bindInfos.size()), bindInfos.data());
}
auto Device::bindImageMemory(const Image &image, const DeviceMemory &memory, DeviceSize memoryOffset) const -> Result {
	return getDeviceTable().bindImageMemory(getHandle(), image, memory, memoryOffset);
}
auto Device::bindImageMemory2(const impl_Struct::ArrayProxy<BindImageMemoryInfo> &bindInfos) const -> Result {
	return getDeviceTable().bindImageMemory2(getHandle(), static_cast<uint32_t>(bindInfos.size()), bindInfos.data());
}
auto Device::bindOpticalFlowSessionImageNV(const OpticalFlowSessionNV &session, OpticalFlowSessionBindingPointNV bindingPoint, const ImageView &view, ImageLayout layout) const -> Result {
	return getDeviceTable().bindOpticalFlowSessionImageNV(getHandle(), session, bindingPoint, view, layout);
}
auto Device::bindTensorMemoryARM(const impl_Struct::ArrayProxy<BindTensorMemoryInfoARM> &bindInfos) const -> Result {
	return getDeviceTable().bindTensorMemoryARM(getHandle(), static_cast<uint32_t>(bindInfos.size()), bindInfos.data());
}
auto Device::bindVideoSessionMemoryKHR(const VideoSessionKHR &videoSession, const impl_Struct::ArrayProxy<BindVideoSessionMemoryInfoKHR> &bindSessionMemoryInfos) const -> Result {
	return getDeviceTable().bindVideoSessionMemoryKHR(getHandle(), videoSession, static_cast<uint32_t>(bindSessionMemoryInfos.size()), bindSessionMemoryInfos.data());
}
auto Device::buildAccelerationStructuresKHR(const DeferredOperationKHR &deferredOperation, const impl_Struct::ArrayProxy<AccelerationStructureBuildGeometryInfoKHR> &infos, const AccelerationStructureBuildRangeInfoKHR * const*ppBuildRangeInfos) const -> Result {
	return getDeviceTable().buildAccelerationStructuresKHR(getHandle(), deferredOperation, static_cast<uint32_t>(infos.size()), infos.data(), ppBuildRangeInfos);
}
auto Device::buildMicromapsEXT(const DeferredOperationKHR &deferredOperation, const impl_Struct::ArrayProxy<MicromapBuildInfoEXT> &infos) const -> Result {
	return getDeviceTable().buildMicromapsEXT(getHandle(), deferredOperation, static_cast<uint32_t>(infos.size()), infos.data());
}
void Device::clearShaderInstrumentationMetricsARM(const ShaderInstrumentationARM &instrumentation) const {
	getDeviceTable().clearShaderInstrumentationMetricsARM(getHandle(), instrumentation);
}
auto Device::compileDeferredNV(const Pipeline &pipeline, uint32_t shader) const -> Result {
	return getDeviceTable().compileDeferredNV(getHandle(), pipeline, shader);
}
auto Device::convertCooperativeVectorMatrixNV(const ConvertCooperativeVectorMatrixInfoNV &info) const -> Result {
	return getDeviceTable().convertCooperativeVectorMatrixNV(getHandle(), (&info));
}
auto Device::copyAccelerationStructureKHR(const DeferredOperationKHR &deferredOperation, const CopyAccelerationStructureInfoKHR &info) const -> Result {
	return getDeviceTable().copyAccelerationStructureKHR(getHandle(), deferredOperation, (&info));
}
auto Device::copyAccelerationStructureToMemoryKHR(const DeferredOperationKHR &deferredOperation, const CopyAccelerationStructureToMemoryInfoKHR &info) const -> Result {
	return getDeviceTable().copyAccelerationStructureToMemoryKHR(getHandle(), deferredOperation, (&info));
}
auto Device::copyImageToImage(const CopyImageToImageInfo &copyImageToImageInfo) const -> Result {
	return getDeviceTable().copyImageToImage(getHandle(), (&copyImageToImageInfo));
}
auto Device::copyImageToMemory(const CopyImageToMemoryInfo &copyImageToMemoryInfo) const -> Result {
	return getDeviceTable().copyImageToMemory(getHandle(), (&copyImageToMemoryInfo));
}
auto Device::copyMemoryToAccelerationStructureKHR(const DeferredOperationKHR &deferredOperation, const CopyMemoryToAccelerationStructureInfoKHR &info) const -> Result {
	return getDeviceTable().copyMemoryToAccelerationStructureKHR(getHandle(), deferredOperation, (&info));
}
auto Device::copyMemoryToImage(const CopyMemoryToImageInfo &copyMemoryToImageInfo) const -> Result {
	return getDeviceTable().copyMemoryToImage(getHandle(), (&copyMemoryToImageInfo));
}
auto Device::copyMemoryToMicromapEXT(const DeferredOperationKHR &deferredOperation, const CopyMemoryToMicromapInfoEXT &info) const -> Result {
	return getDeviceTable().copyMemoryToMicromapEXT(getHandle(), deferredOperation, (&info));
}
auto Device::copyMicromapEXT(const DeferredOperationKHR &deferredOperation, const CopyMicromapInfoEXT &info) const -> Result {
	return getDeviceTable().copyMicromapEXT(getHandle(), deferredOperation, (&info));
}
auto Device::copyMicromapToMemoryEXT(const DeferredOperationKHR &deferredOperation, const CopyMicromapToMemoryInfoEXT &info) const -> Result {
	return getDeviceTable().copyMicromapToMemoryEXT(getHandle(), deferredOperation, (&info));
}
auto Device::createAccelerationStructure2KHR(const AccelerationStructureCreateInfo2KHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueAccelerationStructureKHR, Result> {
	Handle::AccelerationStructureKHR pAccelerationStructure = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createAccelerationStructure2KHR(getHandle(), (&createInfo), pAllocator, &pAccelerationStructure); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueAccelerationStructureKHR>(impl_Objects::Creator::create<AccelerationStructureKHR>(pAccelerationStructure), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createAccelerationStructureKHR(const AccelerationStructureCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueAccelerationStructureKHR, Result> {
	Handle::AccelerationStructureKHR pAccelerationStructure = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createAccelerationStructureKHR(getHandle(), (&createInfo), pAllocator, &pAccelerationStructure); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueAccelerationStructureKHR>(impl_Objects::Creator::create<AccelerationStructureKHR>(pAccelerationStructure), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createAccelerationStructureNV(const AccelerationStructureCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueAccelerationStructureNV, Result> {
	Handle::AccelerationStructureNV pAccelerationStructure = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createAccelerationStructureNV(getHandle(), (&createInfo), pAllocator, &pAccelerationStructure); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueAccelerationStructureNV>(impl_Objects::Creator::create<AccelerationStructureNV>(pAccelerationStructure), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createBuffer(const BufferCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueBuffer, Result> {
	Handle::Buffer pBuffer = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createBuffer(getHandle(), (&createInfo), pAllocator, &pBuffer); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueBuffer>(impl_Objects::Creator::create<Buffer>(pBuffer), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createBufferView(const BufferViewCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueBufferView, Result> {
	Handle::BufferView pView = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createBufferView(getHandle(), (&createInfo), pAllocator, &pView); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueBufferView>(impl_Objects::Creator::create<BufferView>(pView), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createCommandPool(const CommandPoolCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueCommandPool, Result> {
	Handle::CommandPool pCommandPool = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createCommandPool(getHandle(), (&createInfo), pAllocator, &pCommandPool); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueCommandPool>(impl_Objects::Creator::create<CommandPool>(pCommandPool), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createComputePipelines(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<ComputePipelineCreateInfo> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniquePipeline>, Result> {
	std::vector<Handle::Pipeline> pipelinesRaw{static_cast<uint32_t>(createInfos.size())};
	if (const Result res = getDeviceTable().createComputePipelines(getHandle(), pipelineCache, static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, pipelinesRaw.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return pipelinesRaw |
	       std::views::transform([this, &pAllocator](Handle::Pipeline handleTransform) -> UniquePipeline {
	           return impl_Objects::Creator::create<UniquePipeline>(
	               impl_Objects::Creator::create<Pipeline>(handleTransform), getHandle(), getDispatcher(), pAllocator);
	       }) |
	       std::ranges::to<std::vector>();
}
auto Device::createCuFunctionNVX(const CuFunctionCreateInfoNVX &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueCuFunctionNVX, Result> {
	Handle::CuFunctionNVX pFunction = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createCuFunctionNVX(getHandle(), (&createInfo), pAllocator, &pFunction); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueCuFunctionNVX>(impl_Objects::Creator::create<CuFunctionNVX>(pFunction), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createCuModuleNVX(const CuModuleCreateInfoNVX &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueCuModuleNVX, Result> {
	Handle::CuModuleNVX pModule = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createCuModuleNVX(getHandle(), (&createInfo), pAllocator, &pModule); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueCuModuleNVX>(impl_Objects::Creator::create<CuModuleNVX>(pModule), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createDataGraphPipelineSessionARM(const DataGraphPipelineSessionCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDataGraphPipelineSessionARM, Result> {
	Handle::DataGraphPipelineSessionARM pSession = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createDataGraphPipelineSessionARM(getHandle(), (&createInfo), pAllocator, &pSession); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDataGraphPipelineSessionARM>(impl_Objects::Creator::create<DataGraphPipelineSessionARM>(pSession), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createDataGraphPipelinesARM(const DeferredOperationKHR &deferredOperation, const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<DataGraphPipelineCreateInfoARM> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniquePipeline>, Result> {
	std::vector<Handle::Pipeline> pipelinesRaw{static_cast<uint32_t>(createInfos.size())};
	if (const Result res = getDeviceTable().createDataGraphPipelinesARM(getHandle(), deferredOperation, pipelineCache, static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, pipelinesRaw.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return pipelinesRaw |
	       std::views::transform([this, &pAllocator](Handle::Pipeline handleTransform) -> UniquePipeline {
	           return impl_Objects::Creator::create<UniquePipeline>(
	               impl_Objects::Creator::create<Pipeline>(handleTransform), getHandle(), getDispatcher(), pAllocator);
	       }) |
	       std::ranges::to<std::vector>();
}
auto Device::createDeferredOperationKHR(const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDeferredOperationKHR, Result> {
	Handle::DeferredOperationKHR pDeferredOperation = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createDeferredOperationKHR(getHandle(), pAllocator, &pDeferredOperation); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDeferredOperationKHR>(impl_Objects::Creator::create<DeferredOperationKHR>(pDeferredOperation), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createDescriptorPool(const DescriptorPoolCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDescriptorPool, Result> {
	Handle::DescriptorPool pDescriptorPool = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createDescriptorPool(getHandle(), (&createInfo), pAllocator, &pDescriptorPool); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDescriptorPool>(impl_Objects::Creator::create<DescriptorPool>(pDescriptorPool), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createDescriptorSetLayout(const DescriptorSetLayoutCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDescriptorSetLayout, Result> {
	Handle::DescriptorSetLayout pSetLayout = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createDescriptorSetLayout(getHandle(), (&createInfo), pAllocator, &pSetLayout); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDescriptorSetLayout>(impl_Objects::Creator::create<DescriptorSetLayout>(pSetLayout), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createDescriptorUpdateTemplate(const DescriptorUpdateTemplateCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueDescriptorUpdateTemplate, Result> {
	Handle::DescriptorUpdateTemplate pDescriptorUpdateTemplate = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createDescriptorUpdateTemplate(getHandle(), (&createInfo), pAllocator, &pDescriptorUpdateTemplate); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueDescriptorUpdateTemplate>(impl_Objects::Creator::create<DescriptorUpdateTemplate>(pDescriptorUpdateTemplate), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createEvent(const EventCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueEvent, Result> {
	Handle::Event pEvent = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createEvent(getHandle(), (&createInfo), pAllocator, &pEvent); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueEvent>(impl_Objects::Creator::create<Event>(pEvent), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createExternalComputeQueueNV(const ExternalComputeQueueCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueExternalComputeQueueNV, Result> {
	Handle::ExternalComputeQueueNV pExternalQueue = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createExternalComputeQueueNV(getHandle(), (&createInfo), pAllocator, &pExternalQueue); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueExternalComputeQueueNV>(impl_Objects::Creator::create<ExternalComputeQueueNV>(pExternalQueue, getDispatcher()), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createFence(const FenceCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueFence, Result> {
	Handle::Fence pFence = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createFence(getHandle(), (&createInfo), pAllocator, &pFence); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueFence>(impl_Objects::Creator::create<Fence>(pFence), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createFramebuffer(const FramebufferCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueFramebuffer, Result> {
	Handle::Framebuffer pFramebuffer = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createFramebuffer(getHandle(), (&createInfo), pAllocator, &pFramebuffer); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueFramebuffer>(impl_Objects::Creator::create<Framebuffer>(pFramebuffer), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createGpaSessionAMD(const GpaSessionCreateInfoAMD &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueGpaSessionAMD, Result> {
	Handle::GpaSessionAMD pGpaSession = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createGpaSessionAMD(getHandle(), (&createInfo), pAllocator, &pGpaSession); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueGpaSessionAMD>(impl_Objects::Creator::create<GpaSessionAMD>(pGpaSession), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createGraphicsPipelines(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<GraphicsPipelineCreateInfo> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniquePipeline>, Result> {
	std::vector<Handle::Pipeline> pipelinesRaw{static_cast<uint32_t>(createInfos.size())};
	if (const Result res = getDeviceTable().createGraphicsPipelines(getHandle(), pipelineCache, static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, pipelinesRaw.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return pipelinesRaw |
	       std::views::transform([this, &pAllocator](Handle::Pipeline handleTransform) -> UniquePipeline {
	           return impl_Objects::Creator::create<UniquePipeline>(
	               impl_Objects::Creator::create<Pipeline>(handleTransform), getHandle(), getDispatcher(), pAllocator);
	       }) |
	       std::ranges::to<std::vector>();
}
auto Device::createImage(const ImageCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueImage, Result> {
	Handle::Image pImage = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createImage(getHandle(), (&createInfo), pAllocator, &pImage); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueImage>(impl_Objects::Creator::create<Image>(pImage), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createImageView(const ImageViewCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueImageView, Result> {
	Handle::ImageView pView = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createImageView(getHandle(), (&createInfo), pAllocator, &pView); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueImageView>(impl_Objects::Creator::create<ImageView>(pView), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createIndirectCommandsLayoutEXT(const IndirectCommandsLayoutCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueIndirectCommandsLayoutEXT, Result> {
	Handle::IndirectCommandsLayoutEXT pIndirectCommandsLayout = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createIndirectCommandsLayoutEXT(getHandle(), (&createInfo), pAllocator, &pIndirectCommandsLayout); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueIndirectCommandsLayoutEXT>(impl_Objects::Creator::create<IndirectCommandsLayoutEXT>(pIndirectCommandsLayout), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createIndirectCommandsLayoutNV(const IndirectCommandsLayoutCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueIndirectCommandsLayoutNV, Result> {
	Handle::IndirectCommandsLayoutNV pIndirectCommandsLayout = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createIndirectCommandsLayoutNV(getHandle(), (&createInfo), pAllocator, &pIndirectCommandsLayout); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueIndirectCommandsLayoutNV>(impl_Objects::Creator::create<IndirectCommandsLayoutNV>(pIndirectCommandsLayout), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createIndirectExecutionSetEXT(const IndirectExecutionSetCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueIndirectExecutionSetEXT, Result> {
	Handle::IndirectExecutionSetEXT pIndirectExecutionSet = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createIndirectExecutionSetEXT(getHandle(), (&createInfo), pAllocator, &pIndirectExecutionSet); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueIndirectExecutionSetEXT>(impl_Objects::Creator::create<IndirectExecutionSetEXT>(pIndirectExecutionSet), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createMicromapEXT(const MicromapCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueMicromapEXT, Result> {
	Handle::MicromapEXT pMicromap = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createMicromapEXT(getHandle(), (&createInfo), pAllocator, &pMicromap); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueMicromapEXT>(impl_Objects::Creator::create<MicromapEXT>(pMicromap), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createOpticalFlowSessionNV(const OpticalFlowSessionCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueOpticalFlowSessionNV, Result> {
	Handle::OpticalFlowSessionNV pSession = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createOpticalFlowSessionNV(getHandle(), (&createInfo), pAllocator, &pSession); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueOpticalFlowSessionNV>(impl_Objects::Creator::create<OpticalFlowSessionNV>(pSession), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createPipelineBinariesKHR(const PipelineBinaryCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator, PipelineBinaryHandlesInfoKHR *pBinaries) const -> Result {
	return getDeviceTable().createPipelineBinariesKHR(getHandle(), (&createInfo), pAllocator, pBinaries);
}
auto Device::createPipelineCache(const PipelineCacheCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniquePipelineCache, Result> {
	Handle::PipelineCache pPipelineCache = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createPipelineCache(getHandle(), (&createInfo), pAllocator, &pPipelineCache); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniquePipelineCache>(impl_Objects::Creator::create<PipelineCache>(pPipelineCache), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createPipelineLayout(const PipelineLayoutCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniquePipelineLayout, Result> {
	Handle::PipelineLayout pPipelineLayout = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createPipelineLayout(getHandle(), (&createInfo), pAllocator, &pPipelineLayout); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniquePipelineLayout>(impl_Objects::Creator::create<PipelineLayout>(pPipelineLayout), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createPrivateDataSlot(const PrivateDataSlotCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniquePrivateDataSlot, Result> {
	Handle::PrivateDataSlot pPrivateDataSlot = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createPrivateDataSlot(getHandle(), (&createInfo), pAllocator, &pPrivateDataSlot); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniquePrivateDataSlot>(impl_Objects::Creator::create<PrivateDataSlot>(pPrivateDataSlot), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createQueryPool(const QueryPoolCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueQueryPool, Result> {
	Handle::QueryPool pQueryPool = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createQueryPool(getHandle(), (&createInfo), pAllocator, &pQueryPool); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueQueryPool>(impl_Objects::Creator::create<QueryPool>(pQueryPool), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createRayTracingPipelinesKHR(const DeferredOperationKHR &deferredOperation, const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<RayTracingPipelineCreateInfoKHR> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniquePipeline>, Result> {
	std::vector<Handle::Pipeline> pipelinesRaw{static_cast<uint32_t>(createInfos.size())};
	if (const Result res = getDeviceTable().createRayTracingPipelinesKHR(getHandle(), deferredOperation, pipelineCache, static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, pipelinesRaw.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return pipelinesRaw |
	       std::views::transform([this, &pAllocator](Handle::Pipeline handleTransform) -> UniquePipeline {
	           return impl_Objects::Creator::create<UniquePipeline>(
	               impl_Objects::Creator::create<Pipeline>(handleTransform), getHandle(), getDispatcher(), pAllocator);
	       }) |
	       std::ranges::to<std::vector>();
}
auto Device::createRayTracingPipelinesNV(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<RayTracingPipelineCreateInfoNV> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniquePipeline>, Result> {
	std::vector<Handle::Pipeline> pipelinesRaw{static_cast<uint32_t>(createInfos.size())};
	if (const Result res = getDeviceTable().createRayTracingPipelinesNV(getHandle(), pipelineCache, static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, pipelinesRaw.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return pipelinesRaw |
	       std::views::transform([this, &pAllocator](Handle::Pipeline handleTransform) -> UniquePipeline {
	           return impl_Objects::Creator::create<UniquePipeline>(
	               impl_Objects::Creator::create<Pipeline>(handleTransform), getHandle(), getDispatcher(), pAllocator);
	       }) |
	       std::ranges::to<std::vector>();
}
auto Device::createRenderPass(const RenderPassCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueRenderPass, Result> {
	Handle::RenderPass pRenderPass = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createRenderPass(getHandle(), (&createInfo), pAllocator, &pRenderPass); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueRenderPass>(impl_Objects::Creator::create<RenderPass>(pRenderPass), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createRenderPass2(const RenderPassCreateInfo2 &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueRenderPass, Result> {
	Handle::RenderPass pRenderPass = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createRenderPass2(getHandle(), (&createInfo), pAllocator, &pRenderPass); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueRenderPass>(impl_Objects::Creator::create<RenderPass>(pRenderPass), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createSampler(const SamplerCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSampler, Result> {
	Handle::Sampler pSampler = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createSampler(getHandle(), (&createInfo), pAllocator, &pSampler); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueSampler>(impl_Objects::Creator::create<Sampler>(pSampler), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createSamplerYcbcrConversion(const SamplerYcbcrConversionCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSamplerYcbcrConversion, Result> {
	Handle::SamplerYcbcrConversion pYcbcrConversion = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createSamplerYcbcrConversion(getHandle(), (&createInfo), pAllocator, &pYcbcrConversion); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueSamplerYcbcrConversion>(impl_Objects::Creator::create<SamplerYcbcrConversion>(pYcbcrConversion), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createSemaphore(const SemaphoreCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSemaphore, Result> {
	Handle::Semaphore pSemaphore = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createSemaphore(getHandle(), (&createInfo), pAllocator, &pSemaphore); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueSemaphore>(impl_Objects::Creator::create<Semaphore>(pSemaphore), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createShaderInstrumentationARM(const ShaderInstrumentationCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueShaderInstrumentationARM, Result> {
	Handle::ShaderInstrumentationARM pInstrumentation = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createShaderInstrumentationARM(getHandle(), (&createInfo), pAllocator, &pInstrumentation); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueShaderInstrumentationARM>(impl_Objects::Creator::create<ShaderInstrumentationARM>(pInstrumentation), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createShaderModule(const ShaderModuleCreateInfo &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueShaderModule, Result> {
	Handle::ShaderModule pShaderModule = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createShaderModule(getHandle(), (&createInfo), pAllocator, &pShaderModule); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueShaderModule>(impl_Objects::Creator::create<ShaderModule>(pShaderModule), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createShadersEXT(const impl_Struct::ArrayProxy<ShaderCreateInfoEXT> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniqueShaderEXT>, Result> {
	std::vector<Handle::ShaderEXT> shadersRaw{static_cast<uint32_t>(createInfos.size())};
	if (const Result res = getDeviceTable().createShadersEXT(getHandle(), static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, shadersRaw.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return shadersRaw |
	       std::views::transform([this, &pAllocator](Handle::ShaderEXT handleTransform) -> UniqueShaderEXT {
	           return impl_Objects::Creator::create<UniqueShaderEXT>(
	               impl_Objects::Creator::create<ShaderEXT>(handleTransform), getHandle(), getDispatcher(), pAllocator);
	       }) |
	       std::ranges::to<std::vector>();
}
auto Device::createSharedSwapchainsKHR(const impl_Struct::ArrayProxy<SwapchainCreateInfoKHR> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniqueSwapchainKHR>, Result> {
	std::vector<Handle::SwapchainKHR> swapchainsRaw{static_cast<uint32_t>(createInfos.size())};
	if (const Result res = getDeviceTable().createSharedSwapchainsKHR(getHandle(), static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, swapchainsRaw.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return swapchainsRaw |
	       std::views::transform([this, &pAllocator](Handle::SwapchainKHR handleTransform) -> UniqueSwapchainKHR {
	           return impl_Objects::Creator::create<UniqueSwapchainKHR>(
	               impl_Objects::Creator::create<SwapchainKHR>(handleTransform), getHandle(), getDispatcher(), pAllocator);
	       }) |
	       std::ranges::to<std::vector>();
}
auto Device::createSwapchainKHR(const SwapchainCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueSwapchainKHR, Result> {
	Handle::SwapchainKHR pSwapchain = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createSwapchainKHR(getHandle(), (&createInfo), pAllocator, &pSwapchain); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueSwapchainKHR>(impl_Objects::Creator::create<SwapchainKHR>(pSwapchain), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createTensorARM(const TensorCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueTensorARM, Result> {
	Handle::TensorARM pTensor = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createTensorARM(getHandle(), (&createInfo), pAllocator, &pTensor); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueTensorARM>(impl_Objects::Creator::create<TensorARM>(pTensor), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createTensorViewARM(const TensorViewCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueTensorViewARM, Result> {
	Handle::TensorViewARM pView = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createTensorViewARM(getHandle(), (&createInfo), pAllocator, &pView); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueTensorViewARM>(impl_Objects::Creator::create<TensorViewARM>(pView), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createValidationCacheEXT(const ValidationCacheCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueValidationCacheEXT, Result> {
	Handle::ValidationCacheEXT pValidationCache = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createValidationCacheEXT(getHandle(), (&createInfo), pAllocator, &pValidationCache); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueValidationCacheEXT>(impl_Objects::Creator::create<ValidationCacheEXT>(pValidationCache), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createVideoSessionKHR(const VideoSessionCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueVideoSessionKHR, Result> {
	Handle::VideoSessionKHR pVideoSession = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createVideoSessionKHR(getHandle(), (&createInfo), pAllocator, &pVideoSession); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueVideoSessionKHR>(impl_Objects::Creator::create<VideoSessionKHR>(pVideoSession), getHandle(), getDispatcher(), pAllocator);
}
auto Device::createVideoSessionParametersKHR(const VideoSessionParametersCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueVideoSessionParametersKHR, Result> {
	Handle::VideoSessionParametersKHR pVideoSessionParameters = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().createVideoSessionParametersKHR(getHandle(), (&createInfo), pAllocator, &pVideoSessionParameters); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueVideoSessionParametersKHR>(impl_Objects::Creator::create<VideoSessionParametersKHR>(pVideoSessionParameters), getHandle(), getDispatcher(), pAllocator);
}
auto Device::debugMarkerSetObjectNameEXT(const DebugMarkerObjectNameInfoEXT &nameInfo) const -> Result {
	return getDeviceTable().debugMarkerSetObjectNameEXT(getHandle(), (&nameInfo));
}
auto Device::debugMarkerSetObjectTagEXT(const DebugMarkerObjectTagInfoEXT &tagInfo) const -> Result {
	return getDeviceTable().debugMarkerSetObjectTagEXT(getHandle(), (&tagInfo));
}
auto Device::deferredOperationJoinKHR(const DeferredOperationKHR &operation) const -> Result {
	return getDeviceTable().deferredOperationJoinKHR(getHandle(), operation);
}
void Device::destroyAccelerationStructureKHR(const AccelerationStructureKHR &accelerationStructure, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyAccelerationStructureKHR(getHandle(), accelerationStructure, pAllocator);
}
void Device::destroyAccelerationStructureNV(const AccelerationStructureNV &accelerationStructure, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyAccelerationStructureNV(getHandle(), accelerationStructure, pAllocator);
}
void Device::destroyBuffer(const Buffer &buffer, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyBuffer(getHandle(), buffer, pAllocator);
}
void Device::destroyBufferView(const BufferView &bufferView, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyBufferView(getHandle(), bufferView, pAllocator);
}
void Device::destroyCommandPool(const CommandPool &commandPool, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyCommandPool(getHandle(), commandPool, pAllocator);
}
void Device::destroyCuFunctionNVX(const CuFunctionNVX &function, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyCuFunctionNVX(getHandle(), function, pAllocator);
}
void Device::destroyCuModuleNVX(const CuModuleNVX &module, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyCuModuleNVX(getHandle(), module, pAllocator);
}
void Device::destroyDataGraphPipelineSessionARM(const DataGraphPipelineSessionARM &session, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyDataGraphPipelineSessionARM(getHandle(), session, pAllocator);
}
void Device::destroyDeferredOperationKHR(const DeferredOperationKHR &operation, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyDeferredOperationKHR(getHandle(), operation, pAllocator);
}
void Device::destroyDescriptorPool(const DescriptorPool &descriptorPool, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyDescriptorPool(getHandle(), descriptorPool, pAllocator);
}
void Device::destroyDescriptorSetLayout(const DescriptorSetLayout &descriptorSetLayout, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyDescriptorSetLayout(getHandle(), descriptorSetLayout, pAllocator);
}
void Device::destroyDescriptorUpdateTemplate(const DescriptorUpdateTemplate &descriptorUpdateTemplate, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyDescriptorUpdateTemplate(getHandle(), descriptorUpdateTemplate, pAllocator);
}
void Device::destroyDevice(const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyDevice(getHandle(), pAllocator);
}
void Device::destroyEvent(const Event &event, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyEvent(getHandle(), event, pAllocator);
}
void Device::destroyExternalComputeQueueNV(const ExternalComputeQueueNV &externalQueue, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyExternalComputeQueueNV(getHandle(), externalQueue, pAllocator);
}
void Device::destroyFence(const Fence &fence, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyFence(getHandle(), fence, pAllocator);
}
void Device::destroyFramebuffer(const Framebuffer &framebuffer, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyFramebuffer(getHandle(), framebuffer, pAllocator);
}
void Device::destroyGpaSessionAMD(const GpaSessionAMD &gpaSession, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyGpaSessionAMD(getHandle(), gpaSession, pAllocator);
}
void Device::destroyImage(const Image &image, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyImage(getHandle(), image, pAllocator);
}
void Device::destroyImageView(const ImageView &imageView, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyImageView(getHandle(), imageView, pAllocator);
}
void Device::destroyIndirectCommandsLayoutEXT(const IndirectCommandsLayoutEXT &indirectCommandsLayout, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyIndirectCommandsLayoutEXT(getHandle(), indirectCommandsLayout, pAllocator);
}
void Device::destroyIndirectCommandsLayoutNV(const IndirectCommandsLayoutNV &indirectCommandsLayout, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyIndirectCommandsLayoutNV(getHandle(), indirectCommandsLayout, pAllocator);
}
void Device::destroyIndirectExecutionSetEXT(const IndirectExecutionSetEXT &indirectExecutionSet, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyIndirectExecutionSetEXT(getHandle(), indirectExecutionSet, pAllocator);
}
void Device::destroyMicromapEXT(const MicromapEXT &micromap, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyMicromapEXT(getHandle(), micromap, pAllocator);
}
void Device::destroyOpticalFlowSessionNV(const OpticalFlowSessionNV &session, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyOpticalFlowSessionNV(getHandle(), session, pAllocator);
}
void Device::destroyPipeline(const Pipeline &pipeline, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyPipeline(getHandle(), pipeline, pAllocator);
}
void Device::destroyPipelineBinaryKHR(const PipelineBinaryKHR &pipelineBinary, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyPipelineBinaryKHR(getHandle(), pipelineBinary, pAllocator);
}
void Device::destroyPipelineCache(const PipelineCache &pipelineCache, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyPipelineCache(getHandle(), pipelineCache, pAllocator);
}
void Device::destroyPipelineLayout(const PipelineLayout &pipelineLayout, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyPipelineLayout(getHandle(), pipelineLayout, pAllocator);
}
void Device::destroyPrivateDataSlot(const PrivateDataSlot &privateDataSlot, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyPrivateDataSlot(getHandle(), privateDataSlot, pAllocator);
}
void Device::destroyQueryPool(const QueryPool &queryPool, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyQueryPool(getHandle(), queryPool, pAllocator);
}
void Device::destroyRenderPass(const RenderPass &renderPass, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyRenderPass(getHandle(), renderPass, pAllocator);
}
void Device::destroySampler(const Sampler &sampler, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroySampler(getHandle(), sampler, pAllocator);
}
void Device::destroySamplerYcbcrConversion(const SamplerYcbcrConversion &ycbcrConversion, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroySamplerYcbcrConversion(getHandle(), ycbcrConversion, pAllocator);
}
void Device::destroySemaphore(const Semaphore &semaphore, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroySemaphore(getHandle(), semaphore, pAllocator);
}
void Device::destroyShaderEXT(const ShaderEXT &shader, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyShaderEXT(getHandle(), shader, pAllocator);
}
void Device::destroyShaderInstrumentationARM(const ShaderInstrumentationARM &instrumentation, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyShaderInstrumentationARM(getHandle(), instrumentation, pAllocator);
}
void Device::destroyShaderModule(const ShaderModule &shaderModule, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyShaderModule(getHandle(), shaderModule, pAllocator);
}
void Device::destroySwapchainKHR(const SwapchainKHR &swapchain, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroySwapchainKHR(getHandle(), swapchain, pAllocator);
}
void Device::destroyTensorARM(const TensorARM &tensor, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyTensorARM(getHandle(), tensor, pAllocator);
}
void Device::destroyTensorViewARM(const TensorViewARM &tensorView, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyTensorViewARM(getHandle(), tensorView, pAllocator);
}
void Device::destroyValidationCacheEXT(const ValidationCacheEXT &validationCache, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyValidationCacheEXT(getHandle(), validationCache, pAllocator);
}
void Device::destroyVideoSessionKHR(const VideoSessionKHR &videoSession, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyVideoSessionKHR(getHandle(), videoSession, pAllocator);
}
void Device::destroyVideoSessionParametersKHR(const VideoSessionParametersKHR &videoSessionParameters, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().destroyVideoSessionParametersKHR(getHandle(), videoSessionParameters, pAllocator);
}
auto Device::waitIdle() const -> Result {
	return getDeviceTable().deviceWaitIdle(getHandle());
}
auto Device::displayPowerControlEXT(const DisplayKHR &display, const DisplayPowerInfoEXT &displayPowerInfo) const -> Result {
	return getDeviceTable().displayPowerControlEXT(getHandle(), display, (&displayPowerInfo));
}
auto Device::flushMappedMemoryRanges(const impl_Struct::ArrayProxy<MappedMemoryRange> &memoryRanges) const -> Result {
	return getDeviceTable().flushMappedMemoryRanges(getHandle(), static_cast<uint32_t>(memoryRanges.size()), memoryRanges.data());
}
void Device::freeCommandBuffers(const CommandPool &commandPool, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<CommandBuffer>> &commandBuffers) const {
	getDeviceTable().freeCommandBuffers(getHandle(), commandPool, static_cast<uint32_t>(commandBuffers.size()), reinterpret_cast<const Handle::CommandBuffer*>(commandBuffers.data()));
}
auto Device::freeDescriptorSets(const DescriptorPool &descriptorPool, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<DescriptorSet>> &descriptorSets) const -> Result {
	return getDeviceTable().freeDescriptorSets(getHandle(), descriptorPool, static_cast<uint32_t>(descriptorSets.size()), reinterpret_cast<const Handle::DescriptorSet*>(descriptorSets.data()));
}
void Device::freeMemory(const DeviceMemory &memory, const AllocationCallbacks *pAllocator) const {
	getDeviceTable().freeMemory(getHandle(), memory, pAllocator);
}
auto Device::getAccelerationStructureBuildSizesKHR(AccelerationStructureBuildTypeKHR buildType, const AccelerationStructureBuildGeometryInfoKHR &buildInfo, const uint32_t *pMaxPrimitiveCounts) const -> AccelerationStructureBuildSizesInfoKHR {
	AccelerationStructureBuildSizesInfoKHR pSizeInfo = {};
	getDeviceTable().getAccelerationStructureBuildSizesKHR(getHandle(), buildType, (&buildInfo), pMaxPrimitiveCounts, &pSizeInfo);
	return pSizeInfo;
}
auto Device::getAccelerationStructureAddressKHR(const AccelerationStructureDeviceAddressInfoKHR &info) const -> DeviceAddress {
	return getDeviceTable().getAccelerationStructureDeviceAddressKHR(getHandle(), (&info));
}
auto Device::getAccelerationStructureHandleNV(const AccelerationStructureNV &accelerationStructure, size_t size) const -> std::vector<std::byte> {
	std::vector<std::byte> data(size);
	getDeviceTable().getAccelerationStructureHandleNV(getHandle(), accelerationStructure, data.size(), data.data());
	return data;
}
auto Device::getAccelerationStructureMemoryRequirementsNV(const AccelerationStructureMemoryRequirementsInfoNV &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getAccelerationStructureMemoryRequirementsNV(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getAccelerationStructureOpaqueCaptureDescriptorDataEXT(const AccelerationStructureCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result {
	return getDeviceTable().getAccelerationStructureOpaqueCaptureDescriptorDataEXT(getHandle(), (&info), pData);
}
auto Device::getBufferAddress(const BufferDeviceAddressInfo &info) const -> DeviceAddress {
	return getDeviceTable().getBufferDeviceAddress(getHandle(), (&info));
}
auto Device::getBufferMemoryRequirements(const Buffer &buffer) const -> MemoryRequirements {
	MemoryRequirements pMemoryRequirements = {};
	getDeviceTable().getBufferMemoryRequirements(getHandle(), buffer, &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getBufferMemoryRequirements2(const BufferMemoryRequirementsInfo2 &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getBufferMemoryRequirements2(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getBufferOpaqueCaptureAddress(const BufferDeviceAddressInfo &info) const -> uint64_t {
	return getDeviceTable().getBufferOpaqueCaptureAddress(getHandle(), (&info));
}
auto Device::getBufferOpaqueCaptureDescriptorDataEXT(const BufferCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result {
	return getDeviceTable().getBufferOpaqueCaptureDescriptorDataEXT(getHandle(), (&info), pData);
}
auto Device::getCalibratedTimestampsKHR(const impl_Struct::ArrayProxy<CalibratedTimestampInfoKHR> &timestampInfos) const -> std::expected<std::tuple<std::vector<uint64_t>, uint64_t>, Result> {
	uint64_t maxDeviation = 0;
	std::vector<uint64_t> timestamps(timestampInfos.size());
	getDeviceTable().getCalibratedTimestampsKHR(getHandle(), static_cast<uint32_t>(timestampInfos.size()), timestampInfos.data(), timestamps.data(), &maxDeviation);
	return {{timestamps, maxDeviation}};
}
auto Device::getClusterAccelerationStructureBuildSizesNV(const ClusterAccelerationStructureInputInfoNV &info) const -> AccelerationStructureBuildSizesInfoKHR {
	AccelerationStructureBuildSizesInfoKHR pSizeInfo = {};
	getDeviceTable().getClusterAccelerationStructureBuildSizesNV(getHandle(), (&info), &pSizeInfo);
	return pSizeInfo;
}
auto Device::getDataGraphPipelineAvailablePropertiesARM(const DataGraphPipelineInfoARM &pipelineInfo) const -> std::expected<std::vector<DataGraphPipelinePropertyARM>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getDataGraphPipelineAvailablePropertiesARM(getHandle(), (&pipelineInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DataGraphPipelinePropertyARM> properties(count);
	if (const Result res = getDeviceTable().getDataGraphPipelineAvailablePropertiesARM(getHandle(), (&pipelineInfo), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto Device::getDataGraphPipelinePropertiesARM(const DataGraphPipelineInfoARM &pipelineInfo, size_t size) const -> std::vector<DataGraphPipelinePropertyQueryResultARM> {
	std::vector<DataGraphPipelinePropertyQueryResultARM> properties(size);
	getDeviceTable().getDataGraphPipelinePropertiesARM(getHandle(), (&pipelineInfo), static_cast<uint32_t>(properties.size()), properties.data());
	return properties;
}
auto Device::getDataGraphPipelineSessionBindPointRequirementsARM(const DataGraphPipelineSessionBindPointRequirementsInfoARM &info) const -> std::expected<std::vector<DataGraphPipelineSessionBindPointRequirementARM>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getDataGraphPipelineSessionBindPointRequirementsARM(getHandle(), (&info), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<DataGraphPipelineSessionBindPointRequirementARM> bindPointRequirements(count);
	if (const Result res = getDeviceTable().getDataGraphPipelineSessionBindPointRequirementsARM(getHandle(), (&info), &count, bindPointRequirements.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	bindPointRequirements.resize(count);
	return bindPointRequirements;
}
auto Device::getDataGraphPipelineSessionMemoryRequirementsARM(const DataGraphPipelineSessionMemoryRequirementsInfoARM &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getDataGraphPipelineSessionMemoryRequirementsARM(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getDeferredOperationMaxConcurrencyKHR(const DeferredOperationKHR &operation) const -> uint32_t {
	return getDeviceTable().getDeferredOperationMaxConcurrencyKHR(getHandle(), operation);
}
auto Device::getDeferredOperationResultKHR() const -> std::expected<DeferredOperationKHR, Result> {
	DeferredOperationKHR operation = {};
	if (const Result res = getDeviceTable().getDeferredOperationResultKHR(getHandle(), operation); res != Result::Success &&res != Result::NotReady) {
		return std::unexpected(res);
	}
	return operation;
}
auto Device::getDescriptorEXT(const DescriptorGetInfoEXT &descriptorInfo, size_t size) const -> std::vector<std::byte> {
	std::vector<std::byte> descriptor(size);
	getDeviceTable().getDescriptorEXT(getHandle(), (&descriptorInfo), descriptor.size(), descriptor.data());
	return descriptor;
}
void Device::getDescriptorSetHostMappingVALVE(const DescriptorSet &descriptorSet, void **ppData) const {
	getDeviceTable().getDescriptorSetHostMappingVALVE(getHandle(), descriptorSet, ppData);
}
auto Device::getDescriptorSetLayoutBindingOffsetEXT(const DescriptorSetLayout &layout, uint32_t binding) const -> DeviceSize {
	DeviceSize pOffset = {};
	getDeviceTable().getDescriptorSetLayoutBindingOffsetEXT(getHandle(), layout, binding, &pOffset);
	return pOffset;
}
auto Device::getDescriptorSetLayoutHostMappingInfoVALVE(const DescriptorSetBindingReferenceVALVE &bindingReference) const -> DescriptorSetLayoutHostMappingInfoVALVE {
	DescriptorSetLayoutHostMappingInfoVALVE pHostMapping = {};
	getDeviceTable().getDescriptorSetLayoutHostMappingInfoVALVE(getHandle(), (&bindingReference), &pHostMapping);
	return pHostMapping;
}
auto Device::getDescriptorSetLayoutSizeEXT(const DescriptorSetLayout &layout) const -> DeviceSize {
	DeviceSize pLayoutSizeInBytes = {};
	getDeviceTable().getDescriptorSetLayoutSizeEXT(getHandle(), layout, &pLayoutSizeInBytes);
	return pLayoutSizeInBytes;
}
auto Device::getDescriptorSetLayoutSupport(const DescriptorSetLayoutCreateInfo &createInfo) const -> DescriptorSetLayoutSupport {
	DescriptorSetLayoutSupport pSupport = {};
	getDeviceTable().getDescriptorSetLayoutSupport(getHandle(), (&createInfo), &pSupport);
	return pSupport;
}
auto Device::getAccelerationStructureCompatibilityKHR(const AccelerationStructureVersionInfoKHR &versionInfo) const -> AccelerationStructureCompatibilityKHR {
	AccelerationStructureCompatibilityKHR pCompatibility = {};
	getDeviceTable().getDeviceAccelerationStructureCompatibilityKHR(getHandle(), (&versionInfo), &pCompatibility);
	return pCompatibility;
}
auto Device::getBufferMemoryRequirements(const DeviceBufferMemoryRequirements &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getDeviceBufferMemoryRequirements(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getCombinedImageSamplerIndexNVX(uint64_t imageViewIndex, uint64_t samplerIndex) const -> uint64_t {
	return getDeviceTable().getDeviceCombinedImageSamplerIndexNVX(getHandle(), imageViewIndex, samplerIndex);
}
auto Device::getFaultDebugInfoKHR() const -> std::expected<DeviceFaultDebugInfoKHR, Result> {
	DeviceFaultDebugInfoKHR pDebugInfo = {};
	if (const Result res = getDeviceTable().getDeviceFaultDebugInfoKHR(getHandle(), &pDebugInfo); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	return pDebugInfo;
}
auto Device::getFaultInfoEXT(DeviceFaultCountsEXT *pFaultCounts) const -> std::expected<DeviceFaultInfoEXT, Result> {
	DeviceFaultInfoEXT pFaultInfo = {};
	if (const Result res = getDeviceTable().getDeviceFaultInfoEXT(getHandle(), pFaultCounts, &pFaultInfo); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	return pFaultInfo;
}
auto Device::getFaultReportsKHR(uint64_t timeout) const -> std::expected<std::vector<DeviceFaultInfoKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getDeviceFaultReportsKHR(getHandle(), timeout, &count, nullptr); res != Result::Success &&res != Result::Incomplete &&res != Result::Timeout) {
		return std::unexpected(res);
	}
	std::vector<DeviceFaultInfoKHR> faultInfo(count);
	if (const Result res = getDeviceTable().getDeviceFaultReportsKHR(getHandle(), timeout, &count, faultInfo.data()); res != Result::Success &&res != Result::Incomplete &&res != Result::Timeout) {
		return std::unexpected(res);
	}
	faultInfo.resize(count);
	return faultInfo;
}
auto Device::getGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex) const -> PeerMemoryFeatureFlags {
	PeerMemoryFeatureFlags pPeerMemoryFeatures = {};
	getDeviceTable().getDeviceGroupPeerMemoryFeatures(getHandle(), heapIndex, localDeviceIndex, remoteDeviceIndex, &pPeerMemoryFeatures);
	return pPeerMemoryFeatures;
}
auto Device::getGroupPresentCapabilitiesKHR() const -> std::expected<DeviceGroupPresentCapabilitiesKHR, Result> {
	DeviceGroupPresentCapabilitiesKHR pDeviceGroupPresentCapabilities = {};
	if (const Result res = getDeviceTable().getDeviceGroupPresentCapabilitiesKHR(getHandle(), &pDeviceGroupPresentCapabilities); res != Result::Success) {
		return std::unexpected(res);
	}
	return pDeviceGroupPresentCapabilities;
}
auto Device::getGroupSurfacePresentModesKHR(const SurfaceKHR &surface) const -> std::expected<DeviceGroupPresentModeFlagsKHR, Result> {
	DeviceGroupPresentModeFlagsKHR pModes = {};
	if (const Result res = getDeviceTable().getDeviceGroupSurfacePresentModesKHR(getHandle(), surface, &pModes); res != Result::Success) {
		return std::unexpected(res);
	}
	return pModes;
}
auto Device::getImageMemoryRequirements(const DeviceImageMemoryRequirements &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getDeviceImageMemoryRequirements(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getImageSparseMemoryRequirements(const DeviceImageMemoryRequirements &info) const -> std::vector<SparseImageMemoryRequirements2> {
	uint32_t count = 0;
	getDeviceTable().getDeviceImageSparseMemoryRequirements(getHandle(), (&info), &count, nullptr);
	std::vector<SparseImageMemoryRequirements2> sparseMemoryRequirements(count);
	getDeviceTable().getDeviceImageSparseMemoryRequirements(getHandle(), (&info), &count, sparseMemoryRequirements.data());
	sparseMemoryRequirements.resize(count);
	return sparseMemoryRequirements;
}
auto Device::getImageSubresourceLayout(const DeviceImageSubresourceInfo &info) const -> SubresourceLayout2 {
	SubresourceLayout2 pLayout = {};
	getDeviceTable().getDeviceImageSubresourceLayout(getHandle(), (&info), &pLayout);
	return pLayout;
}
auto Device::getMemoryCommitment(const DeviceMemory &memory) const -> DeviceSize {
	DeviceSize pCommittedMemoryInBytes = {};
	getDeviceTable().getDeviceMemoryCommitment(getHandle(), memory, &pCommittedMemoryInBytes);
	return pCommittedMemoryInBytes;
}
auto Device::getMemoryOpaqueCaptureAddress(const DeviceMemoryOpaqueCaptureAddressInfo &info) const -> uint64_t {
	return getDeviceTable().getDeviceMemoryOpaqueCaptureAddress(getHandle(), (&info));
}
auto Device::getMicromapCompatibilityEXT(const MicromapVersionInfoEXT &versionInfo) const -> AccelerationStructureCompatibilityKHR {
	AccelerationStructureCompatibilityKHR pCompatibility = {};
	getDeviceTable().getDeviceMicromapCompatibilityEXT(getHandle(), (&versionInfo), &pCompatibility);
	return pCompatibility;
}
auto Device::getQueue(uint32_t queueFamilyIndex, uint32_t queueIndex) const -> Queue {
	Handle::Queue queue = VK_BINDINGS_NULL_HANDLE;
	getDeviceTable().getDeviceQueue(getHandle(), queueFamilyIndex, queueIndex, &queue);
	return impl_Objects::Creator::create<Queue>(queue, getDispatcher());
}
auto Device::getQueue2(const DeviceQueueInfo2 &queueInfo) const -> Queue {
	Handle::Queue queue = VK_BINDINGS_NULL_HANDLE;
	getDeviceTable().getDeviceQueue2(getHandle(), (&queueInfo), &queue);
	return impl_Objects::Creator::create<Queue>(queue, getDispatcher());
}
auto Device::getSubpassShadingMaxWorkgroupSizeHUAWEI(const RenderPass &renderpass) const -> std::expected<Extent2D, Result> {
	Extent2D pMaxWorkgroupSize = {};
	if (const Result res = getDeviceTable().getDeviceSubpassShadingMaxWorkgroupSizeHUAWEI(getHandle(), renderpass, &pMaxWorkgroupSize); res != Result::Success) {
		return std::unexpected(res);
	}
	return pMaxWorkgroupSize;
}
auto Device::getTensorMemoryRequirementsARM(const DeviceTensorMemoryRequirementsARM &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getDeviceTensorMemoryRequirementsARM(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getDynamicRenderingTilePropertiesQCOM(const RenderingInfo &renderingInfo) const -> std::expected<TilePropertiesQCOM, Result> {
	TilePropertiesQCOM pProperties = {};
	if (const Result res = getDeviceTable().getDynamicRenderingTilePropertiesQCOM(getHandle(), (&renderingInfo), &pProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pProperties;
}
auto Device::getEncodedVideoSessionParametersKHR(const VideoEncodeSessionParametersGetInfoKHR &videoSessionParametersInfo, VideoEncodeSessionParametersFeedbackInfoKHR *pFeedbackInfo) const -> std::expected<std::vector<std::byte>, Result> {
	size_t count = 0;
	if (const Result res = getDeviceTable().getEncodedVideoSessionParametersKHR(getHandle(), (&videoSessionParametersInfo), pFeedbackInfo, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<std::byte> data(count);
	if (const Result res = getDeviceTable().getEncodedVideoSessionParametersKHR(getHandle(), (&videoSessionParametersInfo), pFeedbackInfo, &count, data.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	data.resize(count);
	return data;
}
auto Device::getEventStatus(const Event &event) const -> Result {
	return getDeviceTable().getEventStatus(getHandle(), event);
}
auto Device::getFenceFdKHR(const FenceGetFdInfoKHR &getFdInfo) const -> std::expected<int, Result> {
	int pFd = {};
	if (const Result res = getDeviceTable().getFenceFdKHR(getHandle(), (&getFdInfo), &pFd); res != Result::Success) {
		return std::unexpected(res);
	}
	return pFd;
}
auto Device::getFenceStatus(const Fence &fence) const -> Result {
	return getDeviceTable().getFenceStatus(getHandle(), fence);
}
auto Device::getFramebufferTilePropertiesQCOM(const Framebuffer &framebuffer) const -> std::expected<std::vector<TilePropertiesQCOM>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getFramebufferTilePropertiesQCOM(getHandle(), framebuffer, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<TilePropertiesQCOM> properties(count);
	if (const Result res = getDeviceTable().getFramebufferTilePropertiesQCOM(getHandle(), framebuffer, &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto Device::getGeneratedCommandsMemoryRequirementsEXT(const GeneratedCommandsMemoryRequirementsInfoEXT &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getGeneratedCommandsMemoryRequirementsEXT(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getGeneratedCommandsMemoryRequirementsNV(const GeneratedCommandsMemoryRequirementsInfoNV &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getGeneratedCommandsMemoryRequirementsNV(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getGpaClockInfoAMD() const -> std::expected<GpaDeviceGetClockInfoAMD, Result> {
	GpaDeviceGetClockInfoAMD pInfo = {};
	if (const Result res = getDeviceTable().getGpaDeviceClockInfoAMD(getHandle(), &pInfo); res != Result::Success) {
		return std::unexpected(res);
	}
	return pInfo;
}
auto Device::getGpaSessionResultsAMD(const GpaSessionAMD &gpaSession, uint32_t sampleID) const -> std::expected<std::vector<std::byte>, Result> {
	size_t count = 0;
	if (const Result res = getDeviceTable().getGpaSessionResultsAMD(getHandle(), gpaSession, sampleID, &count, nullptr); res != Result::Success) {
		return std::unexpected(res);
	}
	std::vector<std::byte> data(count);
	if (const Result res = getDeviceTable().getGpaSessionResultsAMD(getHandle(), gpaSession, sampleID, &count, data.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	data.resize(count);
	return data;
}
auto Device::getGpaSessionStatusAMD(const GpaSessionAMD &gpaSession) const -> Result {
	return getDeviceTable().getGpaSessionStatusAMD(getHandle(), gpaSession);
}
auto Device::getImageDrmFormatModifierPropertiesEXT(const Image &image) const -> std::expected<ImageDrmFormatModifierPropertiesEXT, Result> {
	ImageDrmFormatModifierPropertiesEXT pProperties = {};
	if (const Result res = getDeviceTable().getImageDrmFormatModifierPropertiesEXT(getHandle(), image, &pProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pProperties;
}
auto Device::getImageMemoryRequirements(const Image &image) const -> MemoryRequirements {
	MemoryRequirements pMemoryRequirements = {};
	getDeviceTable().getImageMemoryRequirements(getHandle(), image, &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getImageMemoryRequirements2(const ImageMemoryRequirementsInfo2 &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getImageMemoryRequirements2(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getImageOpaqueCaptureDataEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Image>> &images) const -> std::expected<std::vector<HostAddressRangeEXT>, Result> {
	std::vector<HostAddressRangeEXT> datas(images.size());
	if (const Result res = getDeviceTable().getImageOpaqueCaptureDataEXT(getHandle(), static_cast<uint32_t>(images.size()), reinterpret_cast<const Handle::Image*>(images.data()), datas.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return datas;
}
auto Device::getImageOpaqueCaptureDescriptorDataEXT(const ImageCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result {
	return getDeviceTable().getImageOpaqueCaptureDescriptorDataEXT(getHandle(), (&info), pData);
}
auto Device::getImageSparseMemoryRequirements(const Image &image) const -> std::vector<SparseImageMemoryRequirements> {
	uint32_t count = 0;
	getDeviceTable().getImageSparseMemoryRequirements(getHandle(), image, &count, nullptr);
	std::vector<SparseImageMemoryRequirements> sparseMemoryRequirements(count);
	getDeviceTable().getImageSparseMemoryRequirements(getHandle(), image, &count, sparseMemoryRequirements.data());
	sparseMemoryRequirements.resize(count);
	return sparseMemoryRequirements;
}
auto Device::getImageSparseMemoryRequirements2(const ImageSparseMemoryRequirementsInfo2 &info) const -> std::vector<SparseImageMemoryRequirements2> {
	uint32_t count = 0;
	getDeviceTable().getImageSparseMemoryRequirements2(getHandle(), (&info), &count, nullptr);
	std::vector<SparseImageMemoryRequirements2> sparseMemoryRequirements(count);
	getDeviceTable().getImageSparseMemoryRequirements2(getHandle(), (&info), &count, sparseMemoryRequirements.data());
	sparseMemoryRequirements.resize(count);
	return sparseMemoryRequirements;
}
auto Device::getImageSubresourceLayout(const Image &image, const ImageSubresource &subresource) const -> SubresourceLayout {
	SubresourceLayout pLayout = {};
	getDeviceTable().getImageSubresourceLayout(getHandle(), image, (&subresource), &pLayout);
	return pLayout;
}
auto Device::getImageSubresourceLayout2(const Image &image, const ImageSubresource2 &subresource) const -> SubresourceLayout2 {
	SubresourceLayout2 pLayout = {};
	getDeviceTable().getImageSubresourceLayout2(getHandle(), image, (&subresource), &pLayout);
	return pLayout;
}
auto Device::getImageViewAddressNVX(const ImageView &imageView) const -> std::expected<ImageViewAddressPropertiesNVX, Result> {
	ImageViewAddressPropertiesNVX pProperties = {};
	if (const Result res = getDeviceTable().getImageViewAddressNVX(getHandle(), imageView, &pProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pProperties;
}
auto Device::getImageViewHandle64NVX(const ImageViewHandleInfoNVX &info) const -> uint64_t {
	return getDeviceTable().getImageViewHandle64NVX(getHandle(), (&info));
}
auto Device::getImageViewHandleNVX(const ImageViewHandleInfoNVX &info) const -> uint32_t {
	return getDeviceTable().getImageViewHandleNVX(getHandle(), (&info));
}
auto Device::getImageViewOpaqueCaptureDescriptorDataEXT(const ImageViewCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result {
	return getDeviceTable().getImageViewOpaqueCaptureDescriptorDataEXT(getHandle(), (&info), pData);
}
void Device::getLatencyTimingsLegacyNV(void *pTimings) const {
	getDeviceTable().getLatencyTimingsLegacyNV(getHandle(), pTimings);
}
auto Device::getLatencyTimingsNV(const SwapchainKHR &swapchain) const -> GetLatencyMarkerInfoNV {
	GetLatencyMarkerInfoNV pLatencyMarkerInfo = {};
	getDeviceTable().getLatencyTimingsNV(getHandle(), swapchain, &pLatencyMarkerInfo);
	return pLatencyMarkerInfo;
}
auto Device::getMemoryFdKHR(const MemoryGetFdInfoKHR &getFdInfo) const -> std::expected<int, Result> {
	int pFd = {};
	if (const Result res = getDeviceTable().getMemoryFdKHR(getHandle(), (&getFdInfo), &pFd); res != Result::Success) {
		return std::unexpected(res);
	}
	return pFd;
}
auto Device::getMemoryFdPropertiesKHR(ExternalMemoryHandleTypeBits handleType, int fileDescriptor) const -> std::expected<MemoryFdPropertiesKHR, Result> {
	MemoryFdPropertiesKHR pMemoryFdProperties = {};
	if (const Result res = getDeviceTable().getMemoryFdPropertiesKHR(getHandle(), handleType, fileDescriptor, &pMemoryFdProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pMemoryFdProperties;
}
auto Device::getMemoryHostPointerPropertiesEXT(ExternalMemoryHandleTypeBits handleType, const void *pHostPointer) const -> std::expected<MemoryHostPointerPropertiesEXT, Result> {
	MemoryHostPointerPropertiesEXT pMemoryHostPointerProperties = {};
	if (const Result res = getDeviceTable().getMemoryHostPointerPropertiesEXT(getHandle(), handleType, pHostPointer, &pMemoryHostPointerProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pMemoryHostPointerProperties;
}
auto Device::getMemoryRemoteAddressNV(const MemoryGetRemoteAddressInfoNV &memoryGetRemoteAddressInfo) const -> std::expected<RemoteAddressNV, Result> {
	RemoteAddressNV pAddress = {};
	if (const Result res = getDeviceTable().getMemoryRemoteAddressNV(getHandle(), (&memoryGetRemoteAddressInfo), &pAddress); res != Result::Success) {
		return std::unexpected(res);
	}
	return pAddress;
}
auto Device::getMicromapBuildSizesEXT(AccelerationStructureBuildTypeKHR buildType, const MicromapBuildInfoEXT &buildInfo) const -> MicromapBuildSizesInfoEXT {
	MicromapBuildSizesInfoEXT pSizeInfo = {};
	getDeviceTable().getMicromapBuildSizesEXT(getHandle(), buildType, (&buildInfo), &pSizeInfo);
	return pSizeInfo;
}
auto Device::getPartitionedAccelerationStructuresBuildSizesNV(const PartitionedAccelerationStructureInstancesInputNV &info) const -> AccelerationStructureBuildSizesInfoKHR {
	AccelerationStructureBuildSizesInfoKHR pSizeInfo = {};
	getDeviceTable().getPartitionedAccelerationStructuresBuildSizesNV(getHandle(), (&info), &pSizeInfo);
	return pSizeInfo;
}
auto Device::getPastPresentationTimingEXT(const PastPresentationTimingInfoEXT &pastPresentationTimingInfo) const -> std::expected<PastPresentationTimingPropertiesEXT, Result> {
	PastPresentationTimingPropertiesEXT pPastPresentationTimingProperties = {};
	if (const Result res = getDeviceTable().getPastPresentationTimingEXT(getHandle(), (&pastPresentationTimingInfo), &pPastPresentationTimingProperties); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	return pPastPresentationTimingProperties;
}
auto Device::getPastPresentationTimingGOOGLE(const SwapchainKHR &swapchain) const -> std::expected<std::vector<PastPresentationTimingGOOGLE>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getPastPresentationTimingGOOGLE(getHandle(), swapchain, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PastPresentationTimingGOOGLE> presentationTimings(count);
	if (const Result res = getDeviceTable().getPastPresentationTimingGOOGLE(getHandle(), swapchain, &count, presentationTimings.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	presentationTimings.resize(count);
	return presentationTimings;
}
auto Device::getPerformanceParameterINTEL(PerformanceParameterTypeINTEL parameter) const -> std::expected<PerformanceValueINTEL, Result> {
	PerformanceValueINTEL pValue = {};
	if (const Result res = getDeviceTable().getPerformanceParameterINTEL(getHandle(), parameter, &pValue); res != Result::Success) {
		return std::unexpected(res);
	}
	return pValue;
}
auto Device::getPipelineBinaryDataKHR(const PipelineBinaryDataInfoKHR &info, PipelineBinaryKeyKHR *pPipelineBinaryKey) const -> std::expected<std::vector<std::byte>, Result> {
	size_t count = 0;
	if (const Result res = getDeviceTable().getPipelineBinaryDataKHR(getHandle(), (&info), pPipelineBinaryKey, &count, nullptr); res != Result::Success) {
		return std::unexpected(res);
	}
	std::vector<std::byte> pipelineBinaryData(count);
	if (const Result res = getDeviceTable().getPipelineBinaryDataKHR(getHandle(), (&info), pPipelineBinaryKey, &count, pipelineBinaryData.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	pipelineBinaryData.resize(count);
	return pipelineBinaryData;
}
auto Device::getPipelineCacheData(const PipelineCache &pipelineCache) const -> std::expected<std::vector<std::byte>, Result> {
	size_t count = 0;
	if (const Result res = getDeviceTable().getPipelineCacheData(getHandle(), pipelineCache, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<std::byte> data(count);
	if (const Result res = getDeviceTable().getPipelineCacheData(getHandle(), pipelineCache, &count, data.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	data.resize(count);
	return data;
}
auto Device::getPipelineExecutableInternalRepresentationsKHR(const PipelineExecutableInfoKHR &executableInfo) const -> std::expected<std::vector<PipelineExecutableInternalRepresentationKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getPipelineExecutableInternalRepresentationsKHR(getHandle(), (&executableInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PipelineExecutableInternalRepresentationKHR> internalRepresentations(count);
	if (const Result res = getDeviceTable().getPipelineExecutableInternalRepresentationsKHR(getHandle(), (&executableInfo), &count, internalRepresentations.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	internalRepresentations.resize(count);
	return internalRepresentations;
}
auto Device::getPipelineExecutablePropertiesKHR(const PipelineInfoKHR &pipelineInfo) const -> std::expected<std::vector<PipelineExecutablePropertiesKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getPipelineExecutablePropertiesKHR(getHandle(), (&pipelineInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PipelineExecutablePropertiesKHR> properties(count);
	if (const Result res = getDeviceTable().getPipelineExecutablePropertiesKHR(getHandle(), (&pipelineInfo), &count, properties.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	properties.resize(count);
	return properties;
}
auto Device::getPipelineExecutableStatisticsKHR(const PipelineExecutableInfoKHR &executableInfo) const -> std::expected<std::vector<PipelineExecutableStatisticKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getPipelineExecutableStatisticsKHR(getHandle(), (&executableInfo), &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<PipelineExecutableStatisticKHR> statistics(count);
	if (const Result res = getDeviceTable().getPipelineExecutableStatisticsKHR(getHandle(), (&executableInfo), &count, statistics.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	statistics.resize(count);
	return statistics;
}
auto Device::getPipelineIndirectAddressNV(const PipelineIndirectDeviceAddressInfoNV &info) const -> DeviceAddress {
	return getDeviceTable().getPipelineIndirectDeviceAddressNV(getHandle(), (&info));
}
auto Device::getPipelineIndirectMemoryRequirementsNV(const ComputePipelineCreateInfo &createInfo) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getPipelineIndirectMemoryRequirementsNV(getHandle(), (&createInfo), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getPipelineKeyKHR(const PipelineCreateInfoKHR *pPipelineCreateInfo) const -> std::expected<PipelineBinaryKeyKHR, Result> {
	PipelineBinaryKeyKHR pPipelineKey = {};
	if (const Result res = getDeviceTable().getPipelineKeyKHR(getHandle(), pPipelineCreateInfo, &pPipelineKey); res != Result::Success) {
		return std::unexpected(res);
	}
	return pPipelineKey;
}
auto Device::getPipelinePropertiesEXT(const PipelineInfoKHR &pipelineInfo) const -> std::expected<BaseOutStructure, Result> {
	BaseOutStructure pPipelineProperties = {};
	if (const Result res = getDeviceTable().getPipelinePropertiesEXT(getHandle(), (&pipelineInfo), &pPipelineProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pPipelineProperties;
}
auto Device::getPrivateData(ObjectType objectType, uint64_t objectHandle, const PrivateDataSlot &privateDataSlot) const -> uint64_t {
	uint64_t pData = {};
	getDeviceTable().getPrivateData(getHandle(), objectType, objectHandle, privateDataSlot, &pData);
	return pData;
}
auto Device::getQueryPoolResults(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount, std::vector<std::byte> &data, DeviceSize stride, QueryResultFlags flags) const -> Result {
	return getDeviceTable().getQueryPoolResults(getHandle(), queryPool, firstQuery, queryCount, data.size(), data.data(), stride, flags);
}
auto Device::getRayTracingCaptureReplayShaderGroupHandlesKHR(const Pipeline &pipeline, uint32_t firstGroup, uint32_t groupCount, size_t size) const -> std::vector<std::byte> {
	std::vector<std::byte> data(size);
	getDeviceTable().getRayTracingCaptureReplayShaderGroupHandlesKHR(getHandle(), pipeline, firstGroup, groupCount, data.size(), data.data());
	return data;
}
auto Device::getRayTracingShaderGroupHandlesKHR(const Pipeline &pipeline, uint32_t firstGroup, uint32_t groupCount, size_t size) const -> std::vector<std::byte> {
	std::vector<std::byte> data(size);
	getDeviceTable().getRayTracingShaderGroupHandlesKHR(getHandle(), pipeline, firstGroup, groupCount, data.size(), data.data());
	return data;
}
auto Device::getRayTracingShaderGroupStackSizeKHR(const Pipeline &pipeline, uint32_t group, ShaderGroupShaderKHR groupShader) const -> DeviceSize {
	return getDeviceTable().getRayTracingShaderGroupStackSizeKHR(getHandle(), pipeline, group, groupShader);
}
auto Device::getRefreshCycleDurationGOOGLE(const SwapchainKHR &swapchain) const -> std::expected<RefreshCycleDurationGOOGLE, Result> {
	RefreshCycleDurationGOOGLE pDisplayTimingProperties = {};
	if (const Result res = getDeviceTable().getRefreshCycleDurationGOOGLE(getHandle(), swapchain, &pDisplayTimingProperties); res != Result::Success) {
		return std::unexpected(res);
	}
	return pDisplayTimingProperties;
}
auto Device::getRenderAreaGranularity(const RenderPass &renderPass) const -> Extent2D {
	Extent2D pGranularity = {};
	getDeviceTable().getRenderAreaGranularity(getHandle(), renderPass, &pGranularity);
	return pGranularity;
}
auto Device::getRenderingAreaGranularity(const RenderingAreaInfo &renderingAreaInfo) const -> Extent2D {
	Extent2D pGranularity = {};
	getDeviceTable().getRenderingAreaGranularity(getHandle(), (&renderingAreaInfo), &pGranularity);
	return pGranularity;
}
auto Device::getSamplerOpaqueCaptureDescriptorDataEXT(const SamplerCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result {
	return getDeviceTable().getSamplerOpaqueCaptureDescriptorDataEXT(getHandle(), (&info), pData);
}
auto Device::getSemaphoreCounterValue(const Semaphore &semaphore) const -> std::expected<uint64_t, Result> {
	uint64_t pValue = {};
	if (const Result res = getDeviceTable().getSemaphoreCounterValue(getHandle(), semaphore, &pValue); res != Result::Success) {
		return std::unexpected(res);
	}
	return pValue;
}
auto Device::getSemaphoreFdKHR(const SemaphoreGetFdInfoKHR &getFdInfo) const -> std::expected<int, Result> {
	int pFd = {};
	if (const Result res = getDeviceTable().getSemaphoreFdKHR(getHandle(), (&getFdInfo), &pFd); res != Result::Success) {
		return std::unexpected(res);
	}
	return pFd;
}
auto Device::getShaderBinaryDataEXT(const ShaderEXT &shader) const -> std::expected<std::vector<std::byte>, Result> {
	size_t count = 0;
	if (const Result res = getDeviceTable().getShaderBinaryDataEXT(getHandle(), shader, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<std::byte> data(count);
	if (const Result res = getDeviceTable().getShaderBinaryDataEXT(getHandle(), shader, &count, data.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	data.resize(count);
	return data;
}
auto Device::getShaderInfoAMD(const Pipeline &pipeline, ShaderStageBits shaderStage, ShaderInfoTypeAMD infoType) const -> std::expected<std::vector<std::byte>, Result> {
	size_t count = 0;
	if (const Result res = getDeviceTable().getShaderInfoAMD(getHandle(), pipeline, shaderStage, infoType, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<std::byte> info(count);
	if (const Result res = getDeviceTable().getShaderInfoAMD(getHandle(), pipeline, shaderStage, infoType, &count, info.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	info.resize(count);
	return info;
}
auto Device::getShaderInstrumentationValuesARM(const ShaderInstrumentationARM &instrumentation, uint32_t *pMetricBlockCount, void *pMetricValues) const -> std::expected<ShaderInstrumentationValuesFlagsARM, Result> {
	ShaderInstrumentationValuesFlagsARM flags = {};
	if (const Result res = getDeviceTable().getShaderInstrumentationValuesARM(getHandle(), instrumentation, pMetricBlockCount, pMetricValues, flags); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	return flags;
}
auto Device::getShaderModuleCreateInfoIdentifierEXT(const ShaderModuleCreateInfo &createInfo) const -> ShaderModuleIdentifierEXT {
	ShaderModuleIdentifierEXT pIdentifier = {};
	getDeviceTable().getShaderModuleCreateInfoIdentifierEXT(getHandle(), (&createInfo), &pIdentifier);
	return pIdentifier;
}
auto Device::getShaderModuleIdentifierEXT(const ShaderModule &shaderModule) const -> ShaderModuleIdentifierEXT {
	ShaderModuleIdentifierEXT pIdentifier = {};
	getDeviceTable().getShaderModuleIdentifierEXT(getHandle(), shaderModule, &pIdentifier);
	return pIdentifier;
}
auto Device::getSleepStatusLegacyNV() const -> Bool32 {
	Bool32 pLowLatencyMode = {};
	getDeviceTable().getSleepStatusLegacyNV(getHandle(), &pLowLatencyMode);
	return pLowLatencyMode;
}
auto Device::getSwapchainCounterEXT(const SwapchainKHR &swapchain, SurfaceCounterBitsEXT counter) const -> std::expected<uint64_t, Result> {
	uint64_t pCounterValue = {};
	if (const Result res = getDeviceTable().getSwapchainCounterEXT(getHandle(), swapchain, counter, &pCounterValue); res != Result::Success) {
		return std::unexpected(res);
	}
	return pCounterValue;
}
auto Device::getSwapchainImagesKHR(const SwapchainKHR &swapchain) const -> std::expected<std::vector<Image>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getSwapchainImagesKHR(getHandle(), swapchain, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<Image> swapchainImages(count);
	if (const Result res = getDeviceTable().getSwapchainImagesKHR(getHandle(), swapchain, &count, reinterpret_cast<Handle::Image*>(swapchainImages.data())); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	swapchainImages.resize(count);
	return swapchainImages;
}
auto Device::getSwapchainStatusKHR(const SwapchainKHR &swapchain) const -> Result {
	return getDeviceTable().getSwapchainStatusKHR(getHandle(), swapchain);
}
auto Device::getSwapchainTimeDomainPropertiesEXT(const SwapchainKHR &swapchain, SwapchainTimeDomainPropertiesEXT *pSwapchainTimeDomainProperties) const -> std::expected<uint64_t, Result> {
	uint64_t pTimeDomainsCounter = {};
	if (const Result res = getDeviceTable().getSwapchainTimeDomainPropertiesEXT(getHandle(), swapchain, pSwapchainTimeDomainProperties, &pTimeDomainsCounter); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	return pTimeDomainsCounter;
}
auto Device::getSwapchainTimingPropertiesEXT(const SwapchainKHR &swapchain, SwapchainTimingPropertiesEXT *pSwapchainTimingProperties) const -> std::expected<uint64_t, Result> {
	uint64_t pSwapchainTimingPropertiesCounter = {};
	if (const Result res = getDeviceTable().getSwapchainTimingPropertiesEXT(getHandle(), swapchain, pSwapchainTimingProperties, &pSwapchainTimingPropertiesCounter); res != Result::Success &&res != Result::NotReady) {
		return std::unexpected(res);
	}
	return pSwapchainTimingPropertiesCounter;
}
auto Device::getTensorMemoryRequirementsARM(const TensorMemoryRequirementsInfoARM &info) const -> MemoryRequirements2 {
	MemoryRequirements2 pMemoryRequirements = {};
	getDeviceTable().getTensorMemoryRequirementsARM(getHandle(), (&info), &pMemoryRequirements);
	return pMemoryRequirements;
}
auto Device::getTensorOpaqueCaptureDataARM(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<TensorARM>> &tensors) const -> std::expected<std::vector<HostAddressRangeEXT>, Result> {
	std::vector<HostAddressRangeEXT> datas(tensors.size());
	if (const Result res = getDeviceTable().getTensorOpaqueCaptureDataARM(getHandle(), static_cast<uint32_t>(tensors.size()), reinterpret_cast<const Handle::TensorARM*>(tensors.data()), datas.data()); res != Result::Success) {
		return std::unexpected(res);
	}
	return datas;
}
auto Device::getTensorOpaqueCaptureDescriptorDataARM(const TensorCaptureDescriptorDataInfoARM &info, void *pData) const -> Result {
	return getDeviceTable().getTensorOpaqueCaptureDescriptorDataARM(getHandle(), (&info), pData);
}
auto Device::getTensorViewOpaqueCaptureDescriptorDataARM(const TensorViewCaptureDescriptorDataInfoARM &info, void *pData) const -> Result {
	return getDeviceTable().getTensorViewOpaqueCaptureDescriptorDataARM(getHandle(), (&info), pData);
}
auto Device::getValidationCacheDataEXT(const ValidationCacheEXT &validationCache) const -> std::expected<std::vector<std::byte>, Result> {
	size_t count = 0;
	if (const Result res = getDeviceTable().getValidationCacheDataEXT(getHandle(), validationCache, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<std::byte> data(count);
	if (const Result res = getDeviceTable().getValidationCacheDataEXT(getHandle(), validationCache, &count, data.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	data.resize(count);
	return data;
}
auto Device::getVideoSessionMemoryRequirementsKHR(const VideoSessionKHR &videoSession) const -> std::expected<std::vector<VideoSessionMemoryRequirementsKHR>, Result> {
	uint32_t count = 0;
	if (const Result res = getDeviceTable().getVideoSessionMemoryRequirementsKHR(getHandle(), videoSession, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	std::vector<VideoSessionMemoryRequirementsKHR> memoryRequirements(count);
	if (const Result res = getDeviceTable().getVideoSessionMemoryRequirementsKHR(getHandle(), videoSession, &count, memoryRequirements.data()); res != Result::Success &&res != Result::Incomplete) {
		return std::unexpected(res);
	}
	memoryRequirements.resize(count);
	return memoryRequirements;
}
auto Device::importFenceFdKHR(const ImportFenceFdInfoKHR &importFenceFdInfo) const -> Result {
	return getDeviceTable().importFenceFdKHR(getHandle(), (&importFenceFdInfo));
}
auto Device::importSemaphoreFdKHR(const ImportSemaphoreFdInfoKHR &importSemaphoreFdInfo) const -> Result {
	return getDeviceTable().importSemaphoreFdKHR(getHandle(), (&importSemaphoreFdInfo));
}
auto Device::initializePerformanceApiINTEL(const InitializePerformanceApiInfoINTEL &initializeInfo) const -> Result {
	return getDeviceTable().initializePerformanceApiINTEL(getHandle(), (&initializeInfo));
}
auto Device::invalidateMappedMemoryRanges(const impl_Struct::ArrayProxy<MappedMemoryRange> &memoryRanges) const -> Result {
	return getDeviceTable().invalidateMappedMemoryRanges(getHandle(), static_cast<uint32_t>(memoryRanges.size()), memoryRanges.data());
}
void Device::latencySleepLegacyNV(const Semaphore &signalSemaphore, uint64_t value) const {
	getDeviceTable().latencySleepLegacyNV(getHandle(), signalSemaphore, value);
}
auto Device::latencySleepNV(const SwapchainKHR &swapchain, const LatencySleepInfoNV &sleepInfo) const -> Result {
	return getDeviceTable().latencySleepNV(getHandle(), swapchain, (&sleepInfo));
}
auto Device::mapMemory(const DeviceMemory &memory, DeviceSize offset, DeviceSize size, MemoryMapFlags flags) const -> std::expected<void *, Result> {
	void *ppData = nullptr;
	if (const Result res = getDeviceTable().mapMemory(getHandle(), memory, offset, size, flags, &ppData); res != Result::Success) {
		return std::unexpected(res);
	}
	return ppData;
}
auto Device::mapMemory2(const MemoryMapInfo &memoryMapInfo) const -> std::expected<void *, Result> {
	void *ppData = nullptr;
	if (const Result res = getDeviceTable().mapMemory2(getHandle(), (&memoryMapInfo), &ppData); res != Result::Success) {
		return std::unexpected(res);
	}
	return ppData;
}
auto Device::mergePipelineCaches(const PipelineCache &dstCache, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<PipelineCache>> &srcCaches) const -> Result {
	return getDeviceTable().mergePipelineCaches(getHandle(), dstCache, static_cast<uint32_t>(srcCaches.size()), reinterpret_cast<const Handle::PipelineCache*>(srcCaches.data()));
}
auto Device::mergeValidationCachesEXT(const ValidationCacheEXT &dstCache, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<ValidationCacheEXT>> &srcCaches) const -> Result {
	return getDeviceTable().mergeValidationCachesEXT(getHandle(), dstCache, static_cast<uint32_t>(srcCaches.size()), reinterpret_cast<const Handle::ValidationCacheEXT*>(srcCaches.data()));
}
auto Device::registerCustomBorderColorEXT(const SamplerCustomBorderColorCreateInfoEXT &borderColor, Bool32 requestIndex, uint32_t *pIndex) const -> Result {
	return getDeviceTable().registerCustomBorderColorEXT(getHandle(), (&borderColor), requestIndex, pIndex);
}
auto Device::registerEventEXT(const DeviceEventInfoEXT &deviceEventInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueFence, Result> {
	Handle::Fence pFence = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().registerDeviceEventEXT(getHandle(), (&deviceEventInfo), pAllocator, &pFence); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueFence>(impl_Objects::Creator::create<Fence>(pFence), getHandle(), getDispatcher(), pAllocator);
}
auto Device::registerDisplayEventEXT(const DisplayKHR &display, const DisplayEventInfoEXT &displayEventInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueFence, Result> {
	Handle::Fence pFence = VK_BINDINGS_NULL_HANDLE;
	if (const Result res = getDeviceTable().registerDisplayEventEXT(getHandle(), display, (&displayEventInfo), pAllocator, &pFence); res != Result::Success) {
		return std::unexpected(res);
	}
	return impl_Objects::Creator::create<UniqueFence>(impl_Objects::Creator::create<Fence>(pFence), getHandle(), getDispatcher(), pAllocator);
}
auto Device::releaseCapturedPipelineDataKHR(const ReleaseCapturedPipelineDataInfoKHR &info, const AllocationCallbacks *pAllocator) const -> Result {
	return getDeviceTable().releaseCapturedPipelineDataKHR(getHandle(), (&info), pAllocator);
}
auto Device::releasePerformanceConfigurationINTEL(const PerformanceConfigurationINTEL &configuration) const -> Result {
	return getDeviceTable().releasePerformanceConfigurationINTEL(getHandle(), configuration);
}
void Device::releaseProfilingLockKHR() const {
	getDeviceTable().releaseProfilingLockKHR(getHandle());
}
auto Device::releaseSwapchainImagesKHR(const ReleaseSwapchainImagesInfoKHR &releaseInfo) const -> Result {
	return getDeviceTable().releaseSwapchainImagesKHR(getHandle(), (&releaseInfo));
}
auto Device::resetCommandPool(const CommandPool &commandPool, CommandPoolResetFlags flags) const -> Result {
	return getDeviceTable().resetCommandPool(getHandle(), commandPool, flags);
}
auto Device::resetDescriptorPool(const DescriptorPool &descriptorPool, DescriptorPoolResetFlags flags) const -> Result {
	return getDeviceTable().resetDescriptorPool(getHandle(), descriptorPool, flags);
}
auto Device::resetEvent(const Event &event) const -> Result {
	return getDeviceTable().resetEvent(getHandle(), event);
}
auto Device::resetFences(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Fence>> &fences) const -> Result {
	return getDeviceTable().resetFences(getHandle(), static_cast<uint32_t>(fences.size()), reinterpret_cast<const Handle::Fence*>(fences.data()));
}
auto Device::resetGpaSessionAMD(const GpaSessionAMD &gpaSession) const -> Result {
	return getDeviceTable().resetGpaSessionAMD(getHandle(), gpaSession);
}
void Device::resetQueryPool(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount) const {
	getDeviceTable().resetQueryPool(getHandle(), queryPool, firstQuery, queryCount);
}
auto Device::setDebugUtilsObjectNameEXT(const DebugUtilsObjectNameInfoEXT &nameInfo) const -> Result {
	return getDeviceTable().setDebugUtilsObjectNameEXT(getHandle(), (&nameInfo));
}
auto Device::setDebugUtilsObjectTagEXT(const DebugUtilsObjectTagInfoEXT &tagInfo) const -> Result {
	return getDeviceTable().setDebugUtilsObjectTagEXT(getHandle(), (&tagInfo));
}
void Device::setMemoryPriorityEXT(const DeviceMemory &memory, float priority) const {
	getDeviceTable().setDeviceMemoryPriorityEXT(getHandle(), memory, priority);
}
auto Device::setEvent(const Event &event) const -> Result {
	return getDeviceTable().setEvent(getHandle(), event);
}
auto Device::setGpaClockModeAMD(GpaDeviceClockModeInfoAMD *pInfo) const -> Result {
	return getDeviceTable().setGpaDeviceClockModeAMD(getHandle(), pInfo);
}
void Device::setHdrMetadataEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<SwapchainKHR>> &swapchains, const impl_Struct::ArrayProxy<HdrMetadataEXT> &metadata) const {
	getDeviceTable().setHdrMetadataEXT(getHandle(), static_cast<uint32_t>(swapchains.size()), reinterpret_cast<const Handle::SwapchainKHR*>(swapchains.data()), metadata.data());
}
void Device::setLatencyMarkerLegacyNV(uint64_t frameID, uint32_t marker) const {
	getDeviceTable().setLatencyMarkerLegacyNV(getHandle(), frameID, marker);
}
void Device::setLatencyMarkerNV(const SwapchainKHR &swapchain, const SetLatencyMarkerInfoNV &latencyMarkerInfo) const {
	getDeviceTable().setLatencyMarkerNV(getHandle(), swapchain, (&latencyMarkerInfo));
}
void Device::setLatencySleepModeLegacyNV(Bool32 lowLatencyMode, Bool32 lowLatencyBoost, uint32_t minimumIntervalUs) const {
	getDeviceTable().setLatencySleepModeLegacyNV(getHandle(), lowLatencyMode, lowLatencyBoost, minimumIntervalUs);
}
auto Device::setLatencySleepModeNV(const SwapchainKHR &swapchain, const LatencySleepModeInfoNV &sleepModeInfo) const -> Result {
	return getDeviceTable().setLatencySleepModeNV(getHandle(), swapchain, (&sleepModeInfo));
}
void Device::setLocalDimmingAMD(const SwapchainKHR &swapChain, Bool32 localDimmingEnable) const {
	getDeviceTable().setLocalDimmingAMD(getHandle(), swapChain, localDimmingEnable);
}
auto Device::setPrivateData(ObjectType objectType, uint64_t objectHandle, const PrivateDataSlot &privateDataSlot, uint64_t data) const -> Result {
	return getDeviceTable().setPrivateData(getHandle(), objectType, objectHandle, privateDataSlot, data);
}
auto Device::setSwapchainPresentTimingQueueSizeEXT(const SwapchainKHR &swapchain, uint32_t size) const -> Result {
	return getDeviceTable().setSwapchainPresentTimingQueueSizeEXT(getHandle(), swapchain, size);
}
void Device::shutdownLatencyLegacyNV() const {
	getDeviceTable().shutdownLatencyDeviceLegacyNV(getHandle());
}
auto Device::signalSemaphore(const SemaphoreSignalInfo &signalInfo) const -> Result {
	return getDeviceTable().signalSemaphore(getHandle(), (&signalInfo));
}
auto Device::transitionImageLayout(const impl_Struct::ArrayProxy<HostImageLayoutTransitionInfo> &transitions) const -> Result {
	return getDeviceTable().transitionImageLayout(getHandle(), static_cast<uint32_t>(transitions.size()), transitions.data());
}
void Device::trimCommandPool(const CommandPool &commandPool, CommandPoolTrimFlags flags) const {
	getDeviceTable().trimCommandPool(getHandle(), commandPool, flags);
}
void Device::uninitializePerformanceApiINTEL() const {
	getDeviceTable().uninitializePerformanceApiINTEL(getHandle());
}
void Device::unmapMemory(const DeviceMemory &memory) const {
	getDeviceTable().unmapMemory(getHandle(), memory);
}
auto Device::unmapMemory2(const MemoryUnmapInfo &memoryUnmapInfo) const -> Result {
	return getDeviceTable().unmapMemory2(getHandle(), (&memoryUnmapInfo));
}
void Device::unregisterCustomBorderColorEXT(uint32_t index) const {
	getDeviceTable().unregisterCustomBorderColorEXT(getHandle(), index);
}
void Device::updateDescriptorSetWithTemplate(const DescriptorSet &descriptorSet, const DescriptorUpdateTemplate &descriptorUpdateTemplate, const void *pData) const {
	getDeviceTable().updateDescriptorSetWithTemplate(getHandle(), descriptorSet, descriptorUpdateTemplate, pData);
}
void Device::updateDescriptorSets(const impl_Struct::ArrayProxy<WriteDescriptorSet> &descriptorWrites, const impl_Struct::ArrayProxy<CopyDescriptorSet> &descriptorCopies) const {
	getDeviceTable().updateDescriptorSets(getHandle(), static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), static_cast<uint32_t>(descriptorCopies.size()), descriptorCopies.data());
}
void Device::updateIndirectExecutionSetPipelineEXT(const IndirectExecutionSetEXT &indirectExecutionSet, const impl_Struct::ArrayProxy<WriteIndirectExecutionSetPipelineEXT> &executionSetWrites) const {
	getDeviceTable().updateIndirectExecutionSetPipelineEXT(getHandle(), indirectExecutionSet, static_cast<uint32_t>(executionSetWrites.size()), executionSetWrites.data());
}
void Device::updateIndirectExecutionSetShaderEXT(const IndirectExecutionSetEXT &indirectExecutionSet, const impl_Struct::ArrayProxy<WriteIndirectExecutionSetShaderEXT> &executionSetWrites) const {
	getDeviceTable().updateIndirectExecutionSetShaderEXT(getHandle(), indirectExecutionSet, static_cast<uint32_t>(executionSetWrites.size()), executionSetWrites.data());
}
auto Device::updateVideoSessionParametersKHR(const VideoSessionParametersKHR &videoSessionParameters, const VideoSessionParametersUpdateInfoKHR &updateInfo) const -> Result {
	return getDeviceTable().updateVideoSessionParametersKHR(getHandle(), videoSessionParameters, (&updateInfo));
}
auto Device::waitForFences(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Fence>> &fences, Bool32 waitAll, uint64_t timeout) const -> Result {
	return getDeviceTable().waitForFences(getHandle(), static_cast<uint32_t>(fences.size()), reinterpret_cast<const Handle::Fence*>(fences.data()), waitAll, timeout);
}
auto Device::waitForPresent2KHR(const SwapchainKHR &swapchain, const PresentWait2InfoKHR &presentWait2Info) const -> Result {
	return getDeviceTable().waitForPresent2KHR(getHandle(), swapchain, (&presentWait2Info));
}
auto Device::waitForPresentKHR(const SwapchainKHR &swapchain, uint64_t presentId, uint64_t timeout) const -> Result {
	return getDeviceTable().waitForPresentKHR(getHandle(), swapchain, presentId, timeout);
}
auto Device::waitSemaphores(const SemaphoreWaitInfo &waitInfo, uint64_t timeout) const -> Result {
	return getDeviceTable().waitSemaphores(getHandle(), (&waitInfo), timeout);
}
auto Device::writeAccelerationStructuresPropertiesKHR(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureKHR>> &accelerationStructures, QueryType queryType, std::vector<std::byte> &data, size_t stride) const -> Result {
	return getDeviceTable().writeAccelerationStructuresPropertiesKHR(getHandle(), static_cast<uint32_t>(accelerationStructures.size()), reinterpret_cast<const Handle::AccelerationStructureKHR*>(accelerationStructures.data()), queryType, data.size(), data.data(), stride);
}
auto Device::writeMicromapsPropertiesEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<MicromapEXT>> &micromaps, QueryType queryType, std::vector<std::byte> &data, size_t stride) const -> Result {
	return getDeviceTable().writeMicromapsPropertiesEXT(getHandle(), static_cast<uint32_t>(micromaps.size()), reinterpret_cast<const Handle::MicromapEXT*>(micromaps.data()), queryType, data.size(), data.data(), stride);
}
auto Device::writeResourceDescriptorsEXT(const impl_Struct::ArrayProxy<ResourceDescriptorInfoEXT> &resources, const impl_Struct::ArrayProxy<HostAddressRangeEXT> &descriptors) const -> Result {
	return getDeviceTable().writeResourceDescriptorsEXT(getHandle(), static_cast<uint32_t>(resources.size()), resources.data(), descriptors.data());
}
auto Device::writeSamplerDescriptorsEXT(const impl_Struct::ArrayProxy<SamplerCreateInfo> &samplers, const impl_Struct::ArrayProxy<HostAddressRangeEXT> &descriptors) const -> Result {
	return getDeviceTable().writeSamplerDescriptorsEXT(getHandle(), static_cast<uint32_t>(samplers.size()), samplers.data(), descriptors.data());
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
	auto Device::createCudaFunctionNV(const CudaFunctionCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueCudaFunctionNV, Result> {
		Handle::CudaFunctionNV pFunction = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getDeviceTable().createCudaFunctionNV(getHandle(), (&createInfo), pAllocator, &pFunction); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueCudaFunctionNV>(impl_Objects::Creator::create<CudaFunctionNV>(pFunction), getHandle(), getDispatcher(), pAllocator);
	}
	auto Device::createCudaModuleNV(const CudaModuleCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueCudaModuleNV, Result> {
		Handle::CudaModuleNV pModule = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getDeviceTable().createCudaModuleNV(getHandle(), (&createInfo), pAllocator, &pModule); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueCudaModuleNV>(impl_Objects::Creator::create<CudaModuleNV>(pModule), getHandle(), getDispatcher(), pAllocator);
	}
	auto Device::createExecutionGraphPipelinesAMDX(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<ExecutionGraphPipelineCreateInfoAMDX> &createInfos, const AllocationCallbacks *pAllocator) const -> std::expected<std::vector<UniquePipeline>, Result> {
		std::vector<Handle::Pipeline> pipelinesRaw{static_cast<uint32_t>(createInfos.size())};
		if (const Result res = getDeviceTable().createExecutionGraphPipelinesAMDX(getHandle(), pipelineCache, static_cast<uint32_t>(createInfos.size()), createInfos.data(), pAllocator, pipelinesRaw.data()); res != Result::Success) {
			return std::unexpected(res);
		}
		return pipelinesRaw |
		       std::views::transform([this, &pAllocator](Handle::Pipeline handleTransform) -> UniquePipeline {
		           return impl_Objects::Creator::create<UniquePipeline>(
		               impl_Objects::Creator::create<Pipeline>(handleTransform), getHandle(), getDispatcher(), pAllocator);
		       }) |
		       std::ranges::to<std::vector>();
	}
	void Device::destroyCudaFunctionNV(const CudaFunctionNV &function, const AllocationCallbacks *pAllocator) const {
		getDeviceTable().destroyCudaFunctionNV(getHandle(), function, pAllocator);
	}
	void Device::destroyCudaModuleNV(const CudaModuleNV &module, const AllocationCallbacks *pAllocator) const {
		getDeviceTable().destroyCudaModuleNV(getHandle(), module, pAllocator);
	}
	auto Device::getCudaModuleCacheNV(const CudaModuleNV &module) const -> std::expected<std::vector<std::byte>, Result> {
		size_t count = 0;
		if (const Result res = getDeviceTable().getCudaModuleCacheNV(getHandle(), module, &count, nullptr); res != Result::Success &&res != Result::Incomplete) {
			return std::unexpected(res);
		}
		std::vector<std::byte> cacheData(count);
		if (const Result res = getDeviceTable().getCudaModuleCacheNV(getHandle(), module, &count, cacheData.data()); res != Result::Success &&res != Result::Incomplete) {
			return std::unexpected(res);
		}
		cacheData.resize(count);
		return cacheData;
	}
	auto Device::getExecutionGraphPipelineNodeIndexAMDX(const Pipeline &executionGraph, const PipelineShaderStageNodeCreateInfoAMDX &nodeInfo) const -> std::expected<uint32_t, Result> {
		uint32_t pNodeIndex = {};
		if (const Result res = getDeviceTable().getExecutionGraphPipelineNodeIndexAMDX(getHandle(), executionGraph, (&nodeInfo), &pNodeIndex); res != Result::Success) {
			return std::unexpected(res);
		}
		return pNodeIndex;
	}
	auto Device::getExecutionGraphPipelineScratchSizeAMDX(const Pipeline &executionGraph) const -> std::expected<ExecutionGraphPipelineScratchSizeAMDX, Result> {
		ExecutionGraphPipelineScratchSizeAMDX pSizeInfo = {};
		if (const Result res = getDeviceTable().getExecutionGraphPipelineScratchSizeAMDX(getHandle(), executionGraph, &pSizeInfo); res != Result::Success) {
			return std::unexpected(res);
		}
		return pSizeInfo;
	}
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_ANDROID_KHR
	auto Device::getAndroidHardwareBufferPropertiesANDROID(const struct AHardwareBuffer *buffer) const -> std::expected<AndroidHardwareBufferPropertiesANDROID, Result> {
		AndroidHardwareBufferPropertiesANDROID pProperties = {};
		if (const Result res = getDeviceTable().getAndroidHardwareBufferPropertiesANDROID(getHandle(), buffer, &pProperties); res != Result::Success) {
			return std::unexpected(res);
		}
		return pProperties;
	}
	auto Device::getMemoryAndroidHardwareBufferANDROID(const MemoryGetAndroidHardwareBufferInfoANDROID &info) const -> std::expected<AHardwareBuffer, Result> {
		AHardwareBuffer pBuffer = {};
		if (const Result res = getDeviceTable().getMemoryAndroidHardwareBufferANDROID(getHandle(), (&info), pBuffer); res != Result::Success) {
			return std::unexpected(res);
		}
		return pBuffer;
	}
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_FUCHSIA
	auto Device::createBufferCollectionFUCHSIA(const BufferCollectionCreateInfoFUCHSIA &createInfo, const AllocationCallbacks *pAllocator) const -> std::expected<UniqueBufferCollectionFUCHSIA, Result> {
		Handle::BufferCollectionFUCHSIA pCollection = VK_BINDINGS_NULL_HANDLE;
		if (const Result res = getDeviceTable().createBufferCollectionFUCHSIA(getHandle(), (&createInfo), pAllocator, &pCollection); res != Result::Success) {
			return std::unexpected(res);
		}
		return impl_Objects::Creator::create<UniqueBufferCollectionFUCHSIA>(impl_Objects::Creator::create<BufferCollectionFUCHSIA>(pCollection), getHandle(), getDispatcher(), pAllocator);
	}
	void Device::destroyBufferCollectionFUCHSIA(const BufferCollectionFUCHSIA &collection, const AllocationCallbacks *pAllocator) const {
		getDeviceTable().destroyBufferCollectionFUCHSIA(getHandle(), collection, pAllocator);
	}
	auto Device::getBufferCollectionPropertiesFUCHSIA(const BufferCollectionFUCHSIA &collection) const -> std::expected<BufferCollectionPropertiesFUCHSIA, Result> {
		BufferCollectionPropertiesFUCHSIA pProperties = {};
		if (const Result res = getDeviceTable().getBufferCollectionPropertiesFUCHSIA(getHandle(), collection, &pProperties); res != Result::Success) {
			return std::unexpected(res);
		}
		return pProperties;
	}
	auto Device::getMemoryZirconHandleFUCHSIA(const MemoryGetZirconHandleInfoFUCHSIA &getZirconHandleInfo) const -> std::expected<zx_handle_t, Result> {
		zx_handle_t pZirconHandle = {};
		if (const Result res = getDeviceTable().getMemoryZirconHandleFUCHSIA(getHandle(), (&getZirconHandleInfo), &pZirconHandle); res != Result::Success) {
			return std::unexpected(res);
		}
		return pZirconHandle;
	}
	auto Device::getMemoryZirconHandlePropertiesFUCHSIA(ExternalMemoryHandleTypeBits handleType, zx_handle_t zirconHandle) const -> std::expected<MemoryZirconHandlePropertiesFUCHSIA, Result> {
		MemoryZirconHandlePropertiesFUCHSIA pMemoryZirconHandleProperties = {};
		if (const Result res = getDeviceTable().getMemoryZirconHandlePropertiesFUCHSIA(getHandle(), handleType, zirconHandle, &pMemoryZirconHandleProperties); res != Result::Success) {
			return std::unexpected(res);
		}
		return pMemoryZirconHandleProperties;
	}
	auto Device::getSemaphoreZirconHandleFUCHSIA(const SemaphoreGetZirconHandleInfoFUCHSIA &getZirconHandleInfo) const -> std::expected<zx_handle_t, Result> {
		zx_handle_t pZirconHandle = {};
		if (const Result res = getDeviceTable().getSemaphoreZirconHandleFUCHSIA(getHandle(), (&getZirconHandleInfo), &pZirconHandle); res != Result::Success) {
			return std::unexpected(res);
		}
		return pZirconHandle;
	}
	auto Device::importSemaphoreZirconHandleFUCHSIA(const ImportSemaphoreZirconHandleInfoFUCHSIA &importSemaphoreZirconHandleInfo) const -> Result {
		return getDeviceTable().importSemaphoreZirconHandleFUCHSIA(getHandle(), (&importSemaphoreZirconHandleInfo));
	}
	auto Device::setBufferCollectionBufferConstraintsFUCHSIA(const BufferCollectionFUCHSIA &collection, const BufferConstraintsInfoFUCHSIA &bufferConstraintsInfo) const -> Result {
		return getDeviceTable().setBufferCollectionBufferConstraintsFUCHSIA(getHandle(), collection, (&bufferConstraintsInfo));
	}
	auto Device::setBufferCollectionImageConstraintsFUCHSIA(const BufferCollectionFUCHSIA &collection, const ImageConstraintsInfoFUCHSIA &imageConstraintsInfo) const -> Result {
		return getDeviceTable().setBufferCollectionImageConstraintsFUCHSIA(getHandle(), collection, (&imageConstraintsInfo));
	}
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
	void Device::exportMetalObjectsEXT(ExportMetalObjectsInfoEXT *pMetalObjectsInfo) const {
		getDeviceTable().exportMetalObjectsEXT(getHandle(), pMetalObjectsInfo);
	}
	auto Device::getMemoryMetalHandleEXT(const MemoryGetMetalHandleInfoEXT &getMetalHandleInfo, void **pHandle) const -> Result {
		return getDeviceTable().getMemoryMetalHandleEXT(getHandle(), (&getMetalHandleInfo), pHandle);
	}
	auto Device::getMemoryMetalHandlePropertiesEXT(ExternalMemoryHandleTypeBits handleType, const void *pHandle) const -> std::expected<MemoryMetalHandlePropertiesEXT, Result> {
		MemoryMetalHandlePropertiesEXT pMemoryMetalHandleProperties = {};
		if (const Result res = getDeviceTable().getMemoryMetalHandlePropertiesEXT(getHandle(), handleType, pHandle, &pMemoryMetalHandleProperties); res != Result::Success) {
			return std::unexpected(res);
		}
		return pMemoryMetalHandleProperties;
	}
#endif // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_OHOS
	auto Device::getMemoryNativeBufferOHOS(const MemoryGetNativeBufferInfoOHOS &info) const -> std::expected<OH_NativeBuffer, Result> {
		OH_NativeBuffer pBuffer = {};
		if (const Result res = getDeviceTable().getMemoryNativeBufferOHOS(getHandle(), (&info), pBuffer); res != Result::Success) {
			return std::unexpected(res);
		}
		return pBuffer;
	}
	auto Device::getNativeBufferPropertiesOHOS(const struct OH_NativeBuffer *buffer) const -> std::expected<NativeBufferPropertiesOHOS, Result> {
		NativeBufferPropertiesOHOS pProperties = {};
		if (const Result res = getDeviceTable().getNativeBufferPropertiesOHOS(getHandle(), buffer, &pProperties); res != Result::Success) {
			return std::unexpected(res);
		}
		return pProperties;
	}
#endif // VK_USE_PLATFORM_OHOS
#ifdef VK_USE_PLATFORM_SCREEN_QNX
	auto Device::getScreenBufferPropertiesQNX(const struct _screen_buffer *buffer) const -> std::expected<ScreenBufferPropertiesQNX, Result> {
		ScreenBufferPropertiesQNX pProperties = {};
		if (const Result res = getDeviceTable().getScreenBufferPropertiesQNX(getHandle(), buffer, &pProperties); res != Result::Success) {
			return std::unexpected(res);
		}
		return pProperties;
	}
#endif // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_WIN32_KHR
	auto Device::acquireFullScreenExclusiveModeEXT(const SwapchainKHR &swapchain) const -> Result {
		return getDeviceTable().acquireFullScreenExclusiveModeEXT(getHandle(), swapchain);
	}
	auto Device::getGroupSurfacePresentModes2EXT(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<DeviceGroupPresentModeFlagsKHR, Result> {
		DeviceGroupPresentModeFlagsKHR pModes = {};
		if (const Result res = getDeviceTable().getDeviceGroupSurfacePresentModes2EXT(getHandle(), (&surfaceInfo), &pModes); res != Result::Success) {
			return std::unexpected(res);
		}
		return pModes;
	}
	auto Device::getFenceWin32HandleKHR(const FenceGetWin32HandleInfoKHR &getWin32HandleInfo) const -> std::expected<HANDLE, Result> {
		HANDLE pHandle = {};
		if (const Result res = getDeviceTable().getFenceWin32HandleKHR(getHandle(), (&getWin32HandleInfo), &pHandle); res != Result::Success) {
			return std::unexpected(res);
		}
		return pHandle;
	}
	auto Device::getMemoryWin32HandleKHR(const MemoryGetWin32HandleInfoKHR &getWin32HandleInfo) const -> std::expected<HANDLE, Result> {
		HANDLE pHandle = {};
		if (const Result res = getDeviceTable().getMemoryWin32HandleKHR(getHandle(), (&getWin32HandleInfo), &pHandle); res != Result::Success) {
			return std::unexpected(res);
		}
		return pHandle;
	}
	auto Device::getMemoryWin32HandleNV(const DeviceMemory &memory, ExternalMemoryHandleTypeFlagsNV handleType) const -> std::expected<HANDLE, Result> {
		HANDLE pHandle = {};
		if (const Result res = getDeviceTable().getMemoryWin32HandleNV(getHandle(), memory, handleType, &pHandle); res != Result::Success) {
			return std::unexpected(res);
		}
		return pHandle;
	}
	auto Device::getMemoryWin32HandlePropertiesKHR(ExternalMemoryHandleTypeBits handleType, HANDLE handle) const -> std::expected<MemoryWin32HandlePropertiesKHR, Result> {
		MemoryWin32HandlePropertiesKHR pMemoryWin32HandleProperties = {};
		if (const Result res = getDeviceTable().getMemoryWin32HandlePropertiesKHR(getHandle(), handleType, handle, &pMemoryWin32HandleProperties); res != Result::Success) {
			return std::unexpected(res);
		}
		return pMemoryWin32HandleProperties;
	}
	auto Device::getSemaphoreWin32HandleKHR(const SemaphoreGetWin32HandleInfoKHR &getWin32HandleInfo) const -> std::expected<HANDLE, Result> {
		HANDLE pHandle = {};
		if (const Result res = getDeviceTable().getSemaphoreWin32HandleKHR(getHandle(), (&getWin32HandleInfo), &pHandle); res != Result::Success) {
			return std::unexpected(res);
		}
		return pHandle;
	}
	auto Device::importFenceWin32HandleKHR(const ImportFenceWin32HandleInfoKHR &importFenceWin32HandleInfo) const -> Result {
		return getDeviceTable().importFenceWin32HandleKHR(getHandle(), (&importFenceWin32HandleInfo));
	}
	auto Device::importSemaphoreWin32HandleKHR(const ImportSemaphoreWin32HandleInfoKHR &importSemaphoreWin32HandleInfo) const -> Result {
		return getDeviceTable().importSemaphoreWin32HandleKHR(getHandle(), (&importSemaphoreWin32HandleInfo));
	}
	auto Device::releaseFullScreenExclusiveModeEXT(const SwapchainKHR &swapchain) const -> Result {
		return getDeviceTable().releaseFullScreenExclusiveModeEXT(getHandle(), swapchain);
	}
#endif // VK_USE_PLATFORM_WIN32_KHR
// NOLINTEND(bugprone-easily-swappable-parameters)
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings
