#include "VkBindings/BaseTypes.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/Structs.hpp"
#include "VkBindings/private/StructTemplatesInterface.hpp"

#include <cstdint>

namespace VkBindings {
auto AttachmentSampleCountInfoAMD::colorAttachmentSamples() -> impl_Struct::VecView<uint32_t, SampleCountBits> {
	return {&colorAttachmentCount, &pColorAttachmentSamples};
}
auto BindAccelerationStructureMemoryInfoNV::deviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&deviceIndexCount, &pDeviceIndices};
}
auto BindBufferMemoryDeviceGroupInfo::deviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&deviceIndexCount, &pDeviceIndices};
}
auto BindDescriptorSetsInfo::descriptorSets() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSet>> {
	return {&descriptorSetCount, &pDescriptorSets};
}
auto BindDescriptorSetsInfo::dynamicOffsets() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&dynamicOffsetCount, &pDynamicOffsets};
}
auto BufferCreateInfo::queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&queueFamilyIndexCount, &pQueueFamilyIndices};
}
auto CommandBufferInheritanceRenderingInfo::colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format> {
	return {&colorAttachmentCount, &pColorAttachmentFormats};
}
auto CustomResolveCreateInfoEXT::colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format> {
	return {&colorAttachmentCount, &pColorAttachmentFormats};
}
auto DataGraphPipelineIdentifierCreateInfoARM::identifier() -> impl_Struct::VecView<uint32_t, uint8_t> {
	return {&identifierSize, &pIdentifier};
}
auto DescriptorSetAllocateInfo::setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>> {
	return {&descriptorSetCount, &pSetLayouts};
}
auto DescriptorSetLayoutBinding::immutableSamplers() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Sampler>> {
	return {&descriptorCount, &pImmutableSamplers};
}
auto DescriptorSetLayoutBindingFlagsCreateInfo::bindingFlags() -> impl_Struct::VecView<uint32_t, DescriptorBindingFlags> {
	return {&bindingCount, &pBindingFlags};
}
auto DescriptorSetVariableDescriptorCountAllocateInfo::descriptorCounts() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&descriptorSetCount, &pDescriptorCounts};
}
auto DeviceGroupDeviceCreateInfo::physicalDevices() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<PhysicalDevice>> {
	return {&physicalDeviceCount, &pPhysicalDevices};
}
auto DeviceGroupPresentInfoKHR::deviceMasks() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&swapchainCount, &pDeviceMasks};
}
auto DeviceGroupSubmitInfo::waitSemaphoreDeviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&waitSemaphoreCount, &pWaitSemaphoreDeviceIndices};
}
auto DeviceGroupSubmitInfo::commandBufferDeviceMasks() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&commandBufferCount, &pCommandBufferDeviceMasks};
}
auto DeviceGroupSubmitInfo::signalSemaphoreDeviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&signalSemaphoreCount, &pSignalSemaphoreDeviceIndices};
}
auto DeviceQueueCreateInfo::queuePriorities() -> impl_Struct::VecView<uint32_t, float> {
	return {&queueCount, &pQueuePriorities};
}
auto FrameBoundaryEXT::images() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Image>> {
	return {&imageCount, &pImages};
}
auto FrameBoundaryEXT::buffers() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Buffer>> {
	return {&bufferCount, &pBuffers};
}
auto FrameBoundaryTensorsARM::tensors() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<TensorARM>> {
	return {&tensorCount, &pTensors};
}
auto FramebufferAttachmentImageInfo::viewFormats() -> impl_Struct::VecView<uint32_t, Format> {
	return {&viewFormatCount, &pViewFormats};
}
auto FramebufferCreateInfo::attachments() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ImageView>> {
	return {&attachmentCount, &pAttachments};
}
auto GeneratedCommandsShaderInfoEXT::shaders() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ShaderEXT>> {
	return {&shaderCount, &pShaders};
}
auto ImageDrmFormatModifierListCreateInfoEXT::drmFormatModifiers() -> impl_Struct::VecView<uint32_t, uint64_t> {
	return {&drmFormatModifierCount, &pDrmFormatModifiers};
}
auto ImageFormatListCreateInfo::viewFormats() -> impl_Struct::VecView<uint32_t, Format> {
	return {&viewFormatCount, &pViewFormats};
}
auto IndirectCommandsLayoutTokenNV::indexTypes() -> impl_Struct::VecView<uint32_t, IndexType> {
	return {&indexTypeCount, &pIndexTypes};
}
auto IndirectExecutionSetShaderLayoutInfoEXT::setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>> {
	return {&setLayoutCount, &pSetLayouts};
}
auto MutableDescriptorTypeListEXT::descriptorTypes() -> impl_Struct::VecView<uint32_t, DescriptorType> {
	return {&descriptorTypeCount, &pDescriptorTypes};
}
auto PhysicalDeviceImageDrmFormatModifierInfoEXT::queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&queueFamilyIndexCount, &pQueueFamilyIndices};
}
auto PipelineBinaryInfoKHR::pipelineBinaries() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<PipelineBinaryKHR>> {
	return {&binaryCount, &pPipelineBinaries};
}
auto PipelineColorWriteCreateInfoEXT::colorWriteEnables() -> impl_Struct::VecView<uint32_t, Bool32> {
	return {&attachmentCount, &pColorWriteEnables};
}
auto PipelineCoverageModulationStateCreateInfoNV::coverageModulationTable() -> impl_Struct::VecView<uint32_t, float> {
	return {&coverageModulationTableCount, &pCoverageModulationTable};
}
auto PipelineDynamicStateCreateInfo::dynamicStates() -> impl_Struct::VecView<uint32_t, DynamicState> {
	return {&dynamicStateCount, &pDynamicStates};
}
auto PipelineLibraryCreateInfoKHR::libraries() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Pipeline>> {
	return {&libraryCount, &pLibraries};
}
auto PipelineRenderingCreateInfo::colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format> {
	return {&colorAttachmentCount, &pColorAttachmentFormats};
}
auto PipelineShaderStageModuleIdentifierCreateInfoEXT::identifier() -> impl_Struct::VecView<uint32_t, uint8_t> {
	return {&identifierSize, &pIdentifier};
}
auto PresentId2KHR::presentIds() -> impl_Struct::VecView<uint32_t, uint64_t> {
	return {&swapchainCount, &pPresentIds};
}
auto PresentIdKHR::presentIds() -> impl_Struct::VecView<uint32_t, uint64_t> {
	return {&swapchainCount, &pPresentIds};
}
auto PresentInfoKHR::waitSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>> {
	return {&waitSemaphoreCount, &pWaitSemaphores};
}
auto PresentInfoKHR::swapchains() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<SwapchainKHR>> {
	return {&swapchainCount, &pSwapchains};
}
auto QueryPoolPerformanceCreateInfoKHR::counterIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&counterIndexCount, &pCounterIndices};
}
auto ReleaseSwapchainImagesInfoKHR::imageIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&imageIndexCount, &pImageIndices};
}
auto RenderPassAttachmentBeginInfo::attachments() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ImageView>> {
	return {&attachmentCount, &pAttachments};
}
auto RenderPassMultiviewCreateInfo::viewMasks() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&subpassCount, &pViewMasks};
}
auto RenderPassMultiviewCreateInfo::viewOffsets() -> impl_Struct::VecView<uint32_t, int32_t> {
	return {&dependencyCount, &pViewOffsets};
}
auto RenderPassMultiviewCreateInfo::correlationMasks() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&correlationMaskCount, &pCorrelationMasks};
}
auto RenderPassPerformanceCountersByRegionBeginInfoARM::counterAddresses() -> impl_Struct::VecView<uint32_t, DeviceAddress> {
	return {&counterAddressCount, &pCounterAddresses};
}
auto RenderingAreaInfo::colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format> {
	return {&colorAttachmentCount, &pColorAttachmentFormats};
}
auto RenderingAttachmentLocationInfo::colorAttachmentLocations() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&colorAttachmentCount, &pColorAttachmentLocations};
}
auto RenderingInputAttachmentIndexInfo::colorAttachmentInputIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&colorAttachmentCount, &pColorAttachmentInputIndices};
}
auto SemaphoreWaitInfo::semaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>> {
	return {&semaphoreCount, &pSemaphores};
}
auto SetDescriptorBufferOffsetsInfoEXT::bufferIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&setCount, &pBufferIndices};
}
auto ShadingRatePaletteNV::shadingRatePaletteEntries() -> impl_Struct::VecView<uint32_t, ShadingRatePaletteEntryNV> {
	return {&shadingRatePaletteEntryCount, &pShadingRatePaletteEntries};
}
auto SubmitInfo::waitSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>> {
	return {&waitSemaphoreCount, &pWaitSemaphores};
}
auto SubmitInfo::commandBuffers() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<CommandBuffer>> {
	return {&commandBufferCount, &pCommandBuffers};
}
auto SubmitInfo::signalSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>> {
	return {&signalSemaphoreCount, &pSignalSemaphores};
}
auto SwapchainPresentFenceInfoKHR::fences() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Fence>> {
	return {&swapchainCount, &pFences};
}
auto SwapchainPresentModeInfoKHR::presentModes() -> impl_Struct::VecView<uint32_t, PresentModeKHR> {
	return {&swapchainCount, &pPresentModes};
}
auto SwapchainPresentModesCreateInfoKHR::presentModes() -> impl_Struct::VecView<uint32_t, PresentModeKHR> {
	return {&presentModeCount, &pPresentModes};
}
auto TensorCopyARM::srcOffset() -> impl_Struct::VecView<uint32_t, uint64_t> {
	return {&dimensionCount, &pSrcOffset};
}
auto TensorDescriptionARM::dimensions() -> impl_Struct::VecView<uint32_t, int64_t> {
	return {&dimensionCount, &pDimensions};
}
auto TimelineSemaphoreSubmitInfo::waitSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t> {
	return {&waitSemaphoreValueCount, &pWaitSemaphoreValues};
}
auto TimelineSemaphoreSubmitInfo::signalSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t> {
	return {&signalSemaphoreValueCount, &pSignalSemaphoreValues};
}
auto ValidationFeaturesEXT::enabledValidationFeatures() -> impl_Struct::VecView<uint32_t, ValidationFeatureEnableEXT> {
	return {&enabledValidationFeatureCount, &pEnabledValidationFeatures};
}
auto ValidationFeaturesEXT::disabledValidationFeatures() -> impl_Struct::VecView<uint32_t, ValidationFeatureDisableEXT> {
	return {&disabledValidationFeatureCount, &pDisabledValidationFeatures};
}
auto ValidationFlagsEXT::disabledValidationChecks() -> impl_Struct::VecView<uint32_t, ValidationCheckEXT> {
	return {&disabledValidationCheckCount, &pDisabledValidationChecks};
}
auto VideoDecodeAV1PictureInfoKHR::tileOffsets() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&tileCount, &pTileOffsets};
}
auto VideoDecodeH264PictureInfoKHR::sliceOffsets() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&sliceCount, &pSliceOffsets};
}
auto VideoDecodeH264SessionParametersAddInfoKHR::stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264SequenceParameterSet> {
	return {&stdSPSCount, &pStdSPSs};
}
auto VideoDecodeH264SessionParametersAddInfoKHR::stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264PictureParameterSet> {
	return {&stdPPSCount, &pStdPPSs};
}
auto VideoDecodeH265PictureInfoKHR::sliceSegmentOffsets() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&sliceSegmentCount, &pSliceSegmentOffsets};
}
auto VideoDecodeH265SessionParametersAddInfoKHR::stdVPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265VideoParameterSet> {
	return {&stdVPSCount, &pStdVPSs};
}
auto VideoDecodeH265SessionParametersAddInfoKHR::stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265SequenceParameterSet> {
	return {&stdSPSCount, &pStdSPSs};
}
auto VideoDecodeH265SessionParametersAddInfoKHR::stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265PictureParameterSet> {
	return {&stdPPSCount, &pStdPPSs};
}
auto VideoEncodeAV1SessionParametersCreateInfoKHR::stdOperatingPoints() -> impl_Struct::VecView<uint32_t, StdVideoEncodeAV1OperatingPointInfo> {
	return {&stdOperatingPointCount, &pStdOperatingPoints};
}
auto VideoEncodeH264SessionParametersAddInfoKHR::stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264SequenceParameterSet> {
	return {&stdSPSCount, &pStdSPSs};
}
auto VideoEncodeH264SessionParametersAddInfoKHR::stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264PictureParameterSet> {
	return {&stdPPSCount, &pStdPPSs};
}
auto VideoEncodeH265SessionParametersAddInfoKHR::stdVPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265VideoParameterSet> {
	return {&stdVPSCount, &pStdVPSs};
}
auto VideoEncodeH265SessionParametersAddInfoKHR::stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265SequenceParameterSet> {
	return {&stdSPSCount, &pStdSPSs};
}
auto VideoEncodeH265SessionParametersAddInfoKHR::stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265PictureParameterSet> {
	return {&stdPPSCount, &pStdPPSs};
}
auto WriteDescriptorSetAccelerationStructureKHR::accelerationStructures() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<AccelerationStructureKHR>> {
	return {&accelerationStructureCount, &pAccelerationStructures};
}
auto WriteDescriptorSetAccelerationStructureNV::accelerationStructures() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<AccelerationStructureNV>> {
	return {&accelerationStructureCount, &pAccelerationStructures};
}
auto WriteDescriptorSetPartitionedAccelerationStructureNV::accelerationStructures() -> impl_Struct::VecView<uint32_t, DeviceAddress> {
	return {&accelerationStructureCount, &pAccelerationStructures};
}
auto WriteDescriptorSetTensorARM::tensorViews() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<TensorViewARM>> {
	return {&tensorViewCount, &pTensorViews};
}
#ifdef VK_USE_PLATFORM_WIN32_KHR
	auto D3D12FenceSubmitInfoKHR::waitSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t> {
		return {&waitSemaphoreValuesCount, &pWaitSemaphoreValues};
	}
	auto D3D12FenceSubmitInfoKHR::signalSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t> {
		return {&signalSemaphoreValuesCount, &pSignalSemaphoreValues};
	}
	auto Win32KeyedMutexAcquireReleaseInfoKHR::acquireSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>> {
		return {&acquireCount, &pAcquireSyncs};
	}
	auto Win32KeyedMutexAcquireReleaseInfoKHR::releaseSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>> {
		return {&releaseCount, &pReleaseSyncs};
	}
	auto Win32KeyedMutexAcquireReleaseInfoNV::acquireSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>> {
		return {&acquireCount, &pAcquireSyncs};
	}
	auto Win32KeyedMutexAcquireReleaseInfoNV::releaseSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>> {
		return {&releaseCount, &pReleaseSyncs};
	}
#endif // VK_USE_PLATFORM_WIN32_KHR
auto AccelerationStructureGeometryMicromapDataKHR::usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageKHR> {
	return {&usageCountsCount, &pUsageCounts};
}
auto AccelerationStructureTrianglesOpacityMicromapEXT::usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageEXT> {
	return {&usageCountsCount, &pUsageCounts};
}
auto CoarseSampleOrderCustomNV::sampleLocations() -> impl_Struct::VecView<uint32_t, CoarseSampleLocationNV> {
	return {&sampleLocationCount, &pSampleLocations};
}
auto CopyBufferInfo2::regions() -> impl_Struct::VecView<uint32_t, BufferCopy2> {
	return {&regionCount, &pRegions};
}
auto CopyMemoryToImageIndirectInfoKHR::imageSubresources() -> impl_Struct::VecView<uint32_t, ImageSubresourceLayers> {
	return {&copyCount, &pImageSubresources};
}
auto CopyTensorInfoARM::regions() -> impl_Struct::VecView<uint32_t, TensorCopyARM> {
	return {&regionCount, &pRegions};
}
auto DataGraphPipelineCreateInfoARM::resourceInfos() -> impl_Struct::VecView<uint32_t, DataGraphPipelineResourceInfoARM> {
	return {&resourceInfoCount, &pResourceInfos};
}
auto DataGraphPipelineSingleNodeCreateInfoARM::connections() -> impl_Struct::VecView<uint32_t, DataGraphPipelineSingleNodeConnectionARM> {
	return {&connectionCount, &pConnections};
}
auto DebugUtilsMessengerCallbackDataEXT::queueLabels() -> impl_Struct::VecView<uint32_t, DebugUtilsLabelEXT> {
	return {&queueLabelCount, &pQueueLabels};
}
auto DebugUtilsMessengerCallbackDataEXT::cmdBufLabels() -> impl_Struct::VecView<uint32_t, DebugUtilsLabelEXT> {
	return {&cmdBufLabelCount, &pCmdBufLabels};
}
auto DebugUtilsMessengerCallbackDataEXT::objects() -> impl_Struct::VecView<uint32_t, DebugUtilsObjectNameInfoEXT> {
	return {&objectCount, &pObjects};
}
auto DecompressMemoryInfoEXT::regions() -> impl_Struct::VecView<uint32_t, DecompressMemoryRegionEXT> {
	return {&regionCount, &pRegions};
}
auto DescriptorPoolCreateInfo::poolSizes() -> impl_Struct::VecView<uint32_t, DescriptorPoolSize> {
	return {&poolSizeCount, &pPoolSizes};
}
auto DescriptorSetLayoutCreateInfo::bindings() -> impl_Struct::VecView<uint32_t, DescriptorSetLayoutBinding> {
	return {&bindingCount, &pBindings};
}
auto DescriptorUpdateTemplateCreateInfo::descriptorUpdateEntries() -> impl_Struct::VecView<uint32_t, DescriptorUpdateTemplateEntry> {
	return {&descriptorUpdateEntryCount, &pDescriptorUpdateEntries};
}
auto DeviceCreateInfo::queueCreateInfos() -> impl_Struct::VecView<uint32_t, DeviceQueueCreateInfo> {
	return {&queueCreateInfoCount, &pQueueCreateInfos};
}
auto DirectDriverLoadingListLUNARG::drivers() -> impl_Struct::VecView<uint32_t, DirectDriverLoadingInfoLUNARG> {
	return {&driverCount, &pDrivers};
}
auto FramebufferAttachmentsCreateInfo::attachmentImageInfos() -> impl_Struct::VecView<uint32_t, FramebufferAttachmentImageInfo> {
	return {&attachmentImageInfoCount, &pAttachmentImageInfos};
}
auto GeneratedCommandsInfoNV::streams() -> impl_Struct::VecView<uint32_t, IndirectCommandsStreamNV> {
	return {&streamCount, &pStreams};
}
auto GpaSampleBeginInfoAMD::perfCounters() -> impl_Struct::VecView<uint32_t, GpaPerfCounterAMD> {
	return {&perfCounterCount, &pPerfCounters};
}
auto ImageCreateInfo::queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&queueFamilyIndexCount, &pQueueFamilyIndices};
}
auto ImageDrmFormatModifierExplicitCreateInfoEXT::planeLayouts() -> impl_Struct::VecView<uint32_t, SubresourceLayout> {
	return {&drmFormatModifierPlaneCount, &pPlaneLayouts};
}
auto IndirectCommandsLayoutCreateInfoNV::tokens() -> impl_Struct::VecView<uint32_t, IndirectCommandsLayoutTokenNV> {
	return {&tokenCount, &pTokens};
}
auto IndirectCommandsLayoutCreateInfoNV::streamStrides() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&streamCount, &pStreamStrides};
}
auto IndirectExecutionSetShaderInfoEXT::initialShaders() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ShaderEXT>> {
	return {&shaderCount, &pInitialShaders};
}
auto IndirectExecutionSetShaderInfoEXT::pushConstantRanges() -> impl_Struct::VecView<uint32_t, PushConstantRange> {
	return {&pushConstantRangeCount, &pPushConstantRanges};
}
auto LayerSettingsCreateInfoEXT::settings() -> impl_Struct::VecView<uint32_t, LayerSettingEXT> {
	return {&settingCount, &pSettings};
}
auto MicromapBuildInfoEXT::usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageEXT> {
	return {&usageCountsCount, &pUsageCounts};
}
auto MutableDescriptorTypeCreateInfoEXT::mutableDescriptorTypeLists() -> impl_Struct::VecView<uint32_t, MutableDescriptorTypeListEXT> {
	return {&mutableDescriptorTypeListCount, &pMutableDescriptorTypeLists};
}
auto PipelineBinaryKeysAndDataKHR::pipelineBinaryKeys() -> impl_Struct::VecView<uint32_t, PipelineBinaryKeyKHR> {
	return {&binaryCount, &pPipelineBinaryKeys};
}
auto PipelineColorBlendStateCreateInfo::attachments() -> impl_Struct::VecView<uint32_t, PipelineColorBlendAttachmentState> {
	return {&attachmentCount, &pAttachments};
}
auto PipelineLayoutCreateInfo::setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>> {
	return {&setLayoutCount, &pSetLayouts};
}
auto PipelineLayoutCreateInfo::pushConstantRanges() -> impl_Struct::VecView<uint32_t, PushConstantRange> {
	return {&pushConstantRangeCount, &pPushConstantRanges};
}
auto PipelineVertexInputDivisorStateCreateInfo::vertexBindingDivisors() -> impl_Struct::VecView<uint32_t, VertexInputBindingDivisorDescription> {
	return {&vertexBindingDivisorCount, &pVertexBindingDivisors};
}
auto PipelineVertexInputStateCreateInfo::vertexBindingDescriptions() -> impl_Struct::VecView<uint32_t, VertexInputBindingDescription> {
	return {&vertexBindingDescriptionCount, &pVertexBindingDescriptions};
}
auto PipelineVertexInputStateCreateInfo::vertexAttributeDescriptions() -> impl_Struct::VecView<uint32_t, VertexInputAttributeDescription> {
	return {&vertexAttributeDescriptionCount, &pVertexAttributeDescriptions};
}
auto PipelineViewportShadingRateImageStateCreateInfoNV::shadingRatePalettes() -> impl_Struct::VecView<uint32_t, ShadingRatePaletteNV> {
	return {&viewportCount, &pShadingRatePalettes};
}
auto PipelineViewportSwizzleStateCreateInfoNV::viewportSwizzles() -> impl_Struct::VecView<uint32_t, ViewportSwizzleNV> {
	return {&viewportCount, &pViewportSwizzles};
}
auto PipelineViewportWScalingStateCreateInfoNV::viewportWScalings() -> impl_Struct::VecView<uint32_t, ViewportWScalingNV> {
	return {&viewportCount, &pViewportWScalings};
}
auto PresentTimesInfoGOOGLE::times() -> impl_Struct::VecView<uint32_t, PresentTimeGOOGLE> {
	return {&swapchainCount, &pTimes};
}
auto PresentTimingsInfoEXT::timingInfos() -> impl_Struct::VecView<uint32_t, PresentTimingInfoEXT> {
	return {&swapchainCount, &pTimingInfos};
}
auto QueueFamilyDataGraphTOSAPropertiesARM::profiles() -> impl_Struct::VecView<uint32_t, DataGraphTOSANameQualityARM> {
	return {&profileCount, &pProfiles};
}
auto QueueFamilyDataGraphTOSAPropertiesARM::extensions() -> impl_Struct::VecView<uint32_t, DataGraphTOSANameQualityARM> {
	return {&extensionCount, &pExtensions};
}
auto RenderPassFragmentDensityMapOffsetEndInfoEXT::fragmentDensityOffsets() -> impl_Struct::VecView<uint32_t, Offset2D> {
	return {&fragmentDensityOffsetCount, &pFragmentDensityOffsets};
}
auto RenderPassInputAttachmentAspectCreateInfo::aspectReferences() -> impl_Struct::VecView<uint32_t, InputAttachmentAspectReference> {
	return {&aspectReferenceCount, &pAspectReferences};
}
auto RenderPassStripeSubmitInfoARM::stripeSemaphoreInfos() -> impl_Struct::VecView<uint32_t, SemaphoreSubmitInfo> {
	return {&stripeSemaphoreInfoCount, &pStripeSemaphoreInfos};
}
auto SampleLocationsInfoEXT::sampleLocations() -> impl_Struct::VecView<uint32_t, SampleLocationEXT> {
	return {&sampleLocationsCount, &pSampleLocations};
}
auto SparseBufferMemoryBindInfo::binds() -> impl_Struct::VecView<uint32_t, SparseMemoryBind> {
	return {&bindCount, &pBinds};
}
auto SparseImageOpaqueMemoryBindInfo::binds() -> impl_Struct::VecView<uint32_t, SparseMemoryBind> {
	return {&bindCount, &pBinds};
}
auto SpecializationInfo::mapEntries() -> impl_Struct::VecView<uint32_t, SpecializationMapEntry> {
	return {&mapEntryCount, &pMapEntries};
}
auto SubmitInfo2::waitSemaphoreInfos() -> impl_Struct::VecView<uint32_t, SemaphoreSubmitInfo> {
	return {&waitSemaphoreInfoCount, &pWaitSemaphoreInfos};
}
auto SubmitInfo2::commandBufferInfos() -> impl_Struct::VecView<uint32_t, CommandBufferSubmitInfo> {
	return {&commandBufferInfoCount, &pCommandBufferInfos};
}
auto SubmitInfo2::signalSemaphoreInfos() -> impl_Struct::VecView<uint32_t, SemaphoreSubmitInfo> {
	return {&signalSemaphoreInfoCount, &pSignalSemaphoreInfos};
}
auto SubpassDescription::inputAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference> {
	return {&inputAttachmentCount, &pInputAttachments};
}
auto SubpassDescription::colorAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference> {
	return {&colorAttachmentCount, &pColorAttachments};
}
auto SubpassDescription::preserveAttachments() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&preserveAttachmentCount, &pPreserveAttachments};
}
auto SubpassDescription2::inputAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference2> {
	return {&inputAttachmentCount, &pInputAttachments};
}
auto SubpassDescription2::colorAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference2> {
	return {&colorAttachmentCount, &pColorAttachments};
}
auto SubpassDescription2::preserveAttachments() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&preserveAttachmentCount, &pPreserveAttachments};
}
auto SwapchainCreateInfoKHR::queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&queueFamilyIndexCount, &pQueueFamilyIndices};
}
auto TensorCreateInfoARM::queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&queueFamilyIndexCount, &pQueueFamilyIndices};
}
auto TensorDependencyInfoARM::tensorMemoryBarriers() -> impl_Struct::VecView<uint32_t, TensorMemoryBarrierARM> {
	return {&tensorMemoryBarrierCount, &pTensorMemoryBarriers};
}
auto VideoEncodeH264PictureInfoKHR::naluSliceEntries() -> impl_Struct::VecView<uint32_t, VideoEncodeH264NaluSliceInfoKHR> {
	return {&naluSliceEntryCount, &pNaluSliceEntries};
}
auto VideoEncodeH265PictureInfoKHR::naluSliceSegmentEntries() -> impl_Struct::VecView<uint32_t, VideoEncodeH265NaluSliceSegmentInfoKHR> {
	return {&naluSliceSegmentEntryCount, &pNaluSliceSegmentEntries};
}
auto VideoEncodeRateControlInfoKHR::layers() -> impl_Struct::VecView<uint32_t, VideoEncodeRateControlLayerInfoKHR> {
	return {&layerCount, &pLayers};
}
auto VideoProfileListInfoKHR::profiles() -> impl_Struct::VecView<uint32_t, VideoProfileInfoKHR> {
	return {&profileCount, &pProfiles};
}
auto WriteDescriptorSet::imageInfo() -> impl_Struct::VecView<uint32_t, DescriptorImageInfo> {
	return {&descriptorCount, &pImageInfo};
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
	auto AccelerationStructureTrianglesDisplacementMicromapNV::usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageEXT> {
		return {&usageCountsCount, &pUsageCounts};
	}
#endif // VK_ENABLE_BETA_EXTENSIONS
auto BindImageMemoryDeviceGroupInfo::deviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&deviceIndexCount, &pDeviceIndices};
}
auto BindImageMemoryDeviceGroupInfo::splitInstanceBindRegions() -> impl_Struct::VecView<uint32_t, Rect2D> {
	return {&splitInstanceBindRegionCount, &pSplitInstanceBindRegions};
}
auto BlitImageInfo2::regions() -> impl_Struct::VecView<uint32_t, ImageBlit2> {
	return {&regionCount, &pRegions};
}
auto CopyBufferToImageInfo2::regions() -> impl_Struct::VecView<uint32_t, BufferImageCopy2> {
	return {&regionCount, &pRegions};
}
auto CopyDeviceMemoryImageInfoKHR::regions() -> impl_Struct::VecView<uint32_t, DeviceMemoryImageCopyKHR> {
	return {&regionCount, &pRegions};
}
auto CopyDeviceMemoryInfoKHR::regions() -> impl_Struct::VecView<uint32_t, DeviceMemoryCopyKHR> {
	return {&regionCount, &pRegions};
}
auto CopyImageInfo2::regions() -> impl_Struct::VecView<uint32_t, ImageCopy2> {
	return {&regionCount, &pRegions};
}
auto CopyImageToBufferInfo2::regions() -> impl_Struct::VecView<uint32_t, BufferImageCopy2> {
	return {&regionCount, &pRegions};
}
auto CopyImageToImageInfo::regions() -> impl_Struct::VecView<uint32_t, ImageCopy2> {
	return {&regionCount, &pRegions};
}
auto CopyImageToMemoryInfo::regions() -> impl_Struct::VecView<uint32_t, ImageToMemoryCopy> {
	return {&regionCount, &pRegions};
}
auto CopyMemoryToImageInfo::regions() -> impl_Struct::VecView<uint32_t, MemoryToImageCopy> {
	return {&regionCount, &pRegions};
}
auto DataGraphPipelineShaderModuleCreateInfoARM::constants() -> impl_Struct::VecView<uint32_t, DataGraphPipelineConstantARM> {
	return {&constantCount, &pConstants};
}
auto DependencyInfo::memoryBarriers() -> impl_Struct::VecView<uint32_t, MemoryBarrier2> {
	return {&memoryBarrierCount, &pMemoryBarriers};
}
auto DependencyInfo::bufferMemoryBarriers() -> impl_Struct::VecView<uint32_t, BufferMemoryBarrier2> {
	return {&bufferMemoryBarrierCount, &pBufferMemoryBarriers};
}
auto DependencyInfo::imageMemoryBarriers() -> impl_Struct::VecView<uint32_t, ImageMemoryBarrier2> {
	return {&imageMemoryBarrierCount, &pImageMemoryBarriers};
}
auto DeviceGroupRenderPassBeginInfo::deviceRenderAreas() -> impl_Struct::VecView<uint32_t, Rect2D> {
	return {&deviceRenderAreaCount, &pDeviceRenderAreas};
}
auto MemoryRangeBarriersInfoKHR::memoryRangeBarriers() -> impl_Struct::VecView<uint32_t, MemoryRangeBarrierKHR> {
	return {&memoryRangeBarrierCount, &pMemoryRangeBarriers};
}
auto MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM::perViewRenderAreas() -> impl_Struct::VecView<uint32_t, Rect2D> {
	return {&perViewRenderAreaCount, &pPerViewRenderAreas};
}
auto OpticalFlowExecuteInfoNV::regions() -> impl_Struct::VecView<uint32_t, Rect2D> {
	return {&regionCount, &pRegions};
}
auto PipelineDiscardRectangleStateCreateInfoEXT::discardRectangles() -> impl_Struct::VecView<uint32_t, Rect2D> {
	return {&discardRectangleCount, &pDiscardRectangles};
}
auto PipelineViewportCoarseSampleOrderStateCreateInfoNV::customSampleOrders() -> impl_Struct::VecView<uint32_t, CoarseSampleOrderCustomNV> {
	return {&customSampleOrderCount, &pCustomSampleOrders};
}
auto PipelineViewportExclusiveScissorStateCreateInfoNV::exclusiveScissors() -> impl_Struct::VecView<uint32_t, Rect2D> {
	return {&exclusiveScissorCount, &pExclusiveScissors};
}
auto PipelineViewportStateCreateInfo::viewports() -> impl_Struct::VecView<uint32_t, Viewport> {
	return {&viewportCount, &pViewports};
}
auto PipelineViewportStateCreateInfo::scissors() -> impl_Struct::VecView<uint32_t, Rect2D> {
	return {&scissorCount, &pScissors};
}
auto PresentRegionKHR::rectangles() -> impl_Struct::VecView<uint32_t, RectLayerKHR> {
	return {&rectangleCount, &pRectangles};
}
auto PushDescriptorSetInfo::descriptorWrites() -> impl_Struct::VecView<uint32_t, WriteDescriptorSet> {
	return {&descriptorWriteCount, &pDescriptorWrites};
}
auto RenderPassBeginInfo::clearValues() -> impl_Struct::VecView<uint32_t, ClearValue> {
	return {&clearValueCount, &pClearValues};
}
auto RenderPassCreateInfo::attachments() -> impl_Struct::VecView<uint32_t, AttachmentDescription> {
	return {&attachmentCount, &pAttachments};
}
auto RenderPassCreateInfo::subpasses() -> impl_Struct::VecView<uint32_t, SubpassDescription> {
	return {&subpassCount, &pSubpasses};
}
auto RenderPassCreateInfo::dependencies() -> impl_Struct::VecView<uint32_t, SubpassDependency> {
	return {&dependencyCount, &pDependencies};
}
auto RenderPassCreateInfo2::attachments() -> impl_Struct::VecView<uint32_t, AttachmentDescription2> {
	return {&attachmentCount, &pAttachments};
}
auto RenderPassCreateInfo2::subpasses() -> impl_Struct::VecView<uint32_t, SubpassDescription2> {
	return {&subpassCount, &pSubpasses};
}
auto RenderPassCreateInfo2::dependencies() -> impl_Struct::VecView<uint32_t, SubpassDependency2> {
	return {&dependencyCount, &pDependencies};
}
auto RenderPassCreateInfo2::correlatedViewMasks() -> impl_Struct::VecView<uint32_t, uint32_t> {
	return {&correlatedViewMaskCount, &pCorrelatedViewMasks};
}
auto ResolveImageInfo2::regions() -> impl_Struct::VecView<uint32_t, ImageResolve2> {
	return {&regionCount, &pRegions};
}
auto ShaderCreateInfoEXT::setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>> {
	return {&setLayoutCount, &pSetLayouts};
}
auto ShaderCreateInfoEXT::pushConstantRanges() -> impl_Struct::VecView<uint32_t, PushConstantRange> {
	return {&pushConstantRangeCount, &pPushConstantRanges};
}
auto SparseImageMemoryBindInfo::binds() -> impl_Struct::VecView<uint32_t, SparseImageMemoryBind> {
	return {&bindCount, &pBinds};
}
#ifdef VK_USE_PLATFORM_FUCHSIA
	auto ImageFormatConstraintsInfoFUCHSIA::colorSpaces() -> impl_Struct::VecView<uint32_t, SysmemColorSpaceFUCHSIA> {
		return {&colorSpaceCount, &pColorSpaces};
	}
#endif // VK_USE_PLATFORM_FUCHSIA
auto AccelerationStructureInfoNV::geometries() -> impl_Struct::VecView<uint32_t, GeometryNV> {
	return {&geometryCount, &pGeometries};
}
auto BindSparseInfo::waitSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>> {
	return {&waitSemaphoreCount, &pWaitSemaphores};
}
auto BindSparseInfo::bufferBinds() -> impl_Struct::VecView<uint32_t, SparseBufferMemoryBindInfo> {
	return {&bufferBindCount, &pBufferBinds};
}
auto BindSparseInfo::imageOpaqueBinds() -> impl_Struct::VecView<uint32_t, SparseImageOpaqueMemoryBindInfo> {
	return {&imageOpaqueBindCount, &pImageOpaqueBinds};
}
auto BindSparseInfo::imageBinds() -> impl_Struct::VecView<uint32_t, SparseImageMemoryBindInfo> {
	return {&imageBindCount, &pImageBinds};
}
auto BindSparseInfo::signalSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>> {
	return {&signalSemaphoreCount, &pSignalSemaphores};
}
auto GraphicsPipelineCreateInfo::stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo> {
	return {&stageCount, &pStages};
}
auto GraphicsShaderGroupCreateInfoNV::stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo> {
	return {&stageCount, &pStages};
}
auto PresentRegionsKHR::regions() -> impl_Struct::VecView<uint32_t, PresentRegionKHR> {
	return {&swapchainCount, &pRegions};
}
auto RayTracingPipelineCreateInfoKHR::stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo> {
	return {&stageCount, &pStages};
}
auto RayTracingPipelineCreateInfoKHR::groups() -> impl_Struct::VecView<uint32_t, RayTracingShaderGroupCreateInfoKHR> {
	return {&groupCount, &pGroups};
}
auto RayTracingPipelineCreateInfoNV::stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo> {
	return {&stageCount, &pStages};
}
auto RayTracingPipelineCreateInfoNV::groups() -> impl_Struct::VecView<uint32_t, RayTracingShaderGroupCreateInfoNV> {
	return {&groupCount, &pGroups};
}
auto RenderPassSampleLocationsBeginInfoEXT::attachmentInitialSampleLocations() -> impl_Struct::VecView<uint32_t, AttachmentSampleLocationsEXT> {
	return {&attachmentInitialSampleLocationsCount, &pAttachmentInitialSampleLocations};
}
auto RenderPassSampleLocationsBeginInfoEXT::postSubpassSampleLocations() -> impl_Struct::VecView<uint32_t, SubpassSampleLocationsEXT> {
	return {&postSubpassSampleLocationsCount, &pPostSubpassSampleLocations};
}
auto RenderPassStripeBeginInfoARM::stripeInfos() -> impl_Struct::VecView<uint32_t, RenderPassStripeInfoARM> {
	return {&stripeInfoCount, &pStripeInfos};
}
auto RenderingInfo::colorAttachments() -> impl_Struct::VecView<uint32_t, RenderingAttachmentInfo> {
	return {&colorAttachmentCount, &pColorAttachments};
}
auto VideoBeginCodingInfoKHR::referenceSlots() -> impl_Struct::VecView<uint32_t, VideoReferenceSlotInfoKHR> {
	return {&referenceSlotCount, &pReferenceSlots};
}
auto VideoDecodeInfoKHR::referenceSlots() -> impl_Struct::VecView<uint32_t, VideoReferenceSlotInfoKHR> {
	return {&referenceSlotCount, &pReferenceSlots};
}
auto VideoEncodeInfoKHR::referenceSlots() -> impl_Struct::VecView<uint32_t, VideoReferenceSlotInfoKHR> {
	return {&referenceSlotCount, &pReferenceSlots};
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
	auto ExecutionGraphPipelineCreateInfoAMDX::stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo> {
		return {&stageCount, &pStages};
	}
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	auto ImageConstraintsInfoFUCHSIA::formatConstraints() -> impl_Struct::VecView<uint32_t, ImageFormatConstraintsInfoFUCHSIA> {
		return {&formatConstraintsCount, &pFormatConstraints};
	}
#endif // VK_USE_PLATFORM_FUCHSIA
auto AccelerationStructureBuildGeometryInfoKHR::geometries() -> impl_Struct::VecView<uint32_t, AccelerationStructureGeometryKHR> {
	return {&geometryCount, &pGeometries};
}
auto GraphicsPipelineShaderGroupsCreateInfoNV::groups() -> impl_Struct::VecView<uint32_t, GraphicsShaderGroupCreateInfoNV> {
	return {&groupCount, &pGroups};
}
auto GraphicsPipelineShaderGroupsCreateInfoNV::pipelines() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Pipeline>> {
	return {&pipelineCount, &pPipelines};
}
auto IndirectCommandsLayoutCreateInfoEXT::tokens() -> impl_Struct::VecView<uint32_t, IndirectCommandsLayoutTokenEXT> {
	return {&tokenCount, &pTokens};
}
auto ShaderDescriptorSetAndBindingMappingInfoEXT::mappings() -> impl_Struct::VecView<uint32_t, DescriptorSetAndBindingMappingEXT> {
	return {&mappingCount, &pMappings};
}
} // namespace VkBindings
