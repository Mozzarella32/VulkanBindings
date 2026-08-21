#include "VkBindings/Enums.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/Structs.hpp"
#include "VkBindings/private/StructTemplatesInterface.hpp"

#include <cstdint>

// NOLINTBEGIN(misc-include-cleaner)
// Needed for getting implmenetations
#include "VkBindings/private/StructTemplates.hpp"

// NOLINTEND(misc-include-cleaner)
namespace VkBindings {
template struct impl_Struct::VecView<uint32_t, AccelerationStructureGeometryKHR>;
template struct impl_Struct::VecView<uint32_t, AttachmentDescription2>;
template struct impl_Struct::VecView<uint32_t, AttachmentDescription>;
template struct impl_Struct::VecView<uint32_t, AttachmentReference2>;
template struct impl_Struct::VecView<uint32_t, AttachmentReference>;
template struct impl_Struct::VecView<uint32_t, AttachmentSampleLocationsEXT>;
template struct impl_Struct::VecView<uint32_t, BufferCopy2>;
template struct impl_Struct::VecView<uint32_t, BufferImageCopy2>;
template struct impl_Struct::VecView<uint32_t, BufferMemoryBarrier2>;
template struct impl_Struct::VecView<uint32_t, ClearValue>;
template struct impl_Struct::VecView<uint32_t, CoarseSampleLocationNV>;
template struct impl_Struct::VecView<uint32_t, CoarseSampleOrderCustomNV>;
template struct impl_Struct::VecView<uint32_t, CommandBufferSubmitInfo>;
template struct impl_Struct::VecView<uint32_t, DataGraphPipelineConstantARM>;
template struct impl_Struct::VecView<uint32_t, DataGraphPipelineResourceInfoARM>;
template struct impl_Struct::VecView<uint32_t, DataGraphPipelineSingleNodeConnectionARM>;
template struct impl_Struct::VecView<uint32_t, DataGraphTOSANameQualityARM>;
template struct impl_Struct::VecView<uint32_t, DebugUtilsLabelEXT>;
template struct impl_Struct::VecView<uint32_t, DebugUtilsObjectNameInfoEXT>;
template struct impl_Struct::VecView<uint32_t, DecompressMemoryRegionEXT>;
template struct impl_Struct::VecView<uint32_t, DescriptorBindingFlags>;
template struct impl_Struct::VecView<uint32_t, DescriptorImageInfo>;
template struct impl_Struct::VecView<uint32_t, DescriptorPoolSize>;
template struct impl_Struct::VecView<uint32_t, DescriptorSetAndBindingMappingEXT>;
template struct impl_Struct::VecView<uint32_t, DescriptorSetLayoutBinding>;
template struct impl_Struct::VecView<uint32_t, DescriptorType>;
template struct impl_Struct::VecView<uint32_t, DescriptorUpdateTemplateEntry>;
template struct impl_Struct::VecView<uint32_t, DeviceMemoryCopyKHR>;
template struct impl_Struct::VecView<uint32_t, DeviceMemoryImageCopyKHR>;
template struct impl_Struct::VecView<uint32_t, DeviceQueueCreateInfo>;
template struct impl_Struct::VecView<uint32_t, DirectDriverLoadingInfoLUNARG>;
template struct impl_Struct::VecView<uint32_t, DynamicState>;
template struct impl_Struct::VecView<uint32_t, Format>;
template struct impl_Struct::VecView<uint32_t, FramebufferAttachmentImageInfo>;
template struct impl_Struct::VecView<uint32_t, GeometryNV>;
template struct impl_Struct::VecView<uint32_t, GpaPerfCounterAMD>;
template struct impl_Struct::VecView<uint32_t, GraphicsShaderGroupCreateInfoNV>;
template struct impl_Struct::VecView<uint32_t, ImageBlit2>;
template struct impl_Struct::VecView<uint32_t, ImageCopy2>;
template struct impl_Struct::VecView<uint32_t, ImageMemoryBarrier2>;
template struct impl_Struct::VecView<uint32_t, ImageResolve2>;
template struct impl_Struct::VecView<uint32_t, ImageSubresourceLayers>;
template struct impl_Struct::VecView<uint32_t, ImageToMemoryCopy>;
template struct impl_Struct::VecView<uint32_t, IndexType>;
template struct impl_Struct::VecView<uint32_t, IndirectCommandsLayoutTokenEXT>;
template struct impl_Struct::VecView<uint32_t, IndirectCommandsLayoutTokenNV>;
template struct impl_Struct::VecView<uint32_t, IndirectCommandsStreamNV>;
template struct impl_Struct::VecView<uint32_t, InputAttachmentAspectReference>;
template struct impl_Struct::VecView<uint32_t, LayerSettingEXT>;
template struct impl_Struct::VecView<uint32_t, MemoryBarrier2>;
template struct impl_Struct::VecView<uint32_t, MemoryRangeBarrierKHR>;
template struct impl_Struct::VecView<uint32_t, MemoryToImageCopy>;
template struct impl_Struct::VecView<uint32_t, MicromapUsageEXT>;
template struct impl_Struct::VecView<uint32_t, MicromapUsageKHR>;
template struct impl_Struct::VecView<uint32_t, MutableDescriptorTypeListEXT>;
template struct impl_Struct::VecView<uint32_t, Offset2D>;
template struct impl_Struct::VecView<uint32_t, PipelineBinaryKeyKHR>;
template struct impl_Struct::VecView<uint32_t, PipelineColorBlendAttachmentState>;
template struct impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo>;
template struct impl_Struct::VecView<uint32_t, PresentModeKHR>;
template struct impl_Struct::VecView<uint32_t, PresentRegionKHR>;
template struct impl_Struct::VecView<uint32_t, PresentTimeGOOGLE>;
template struct impl_Struct::VecView<uint32_t, PresentTimingInfoEXT>;
template struct impl_Struct::VecView<uint32_t, PushConstantRange>;
template struct impl_Struct::VecView<uint32_t, RayTracingShaderGroupCreateInfoKHR>;
template struct impl_Struct::VecView<uint32_t, RayTracingShaderGroupCreateInfoNV>;
template struct impl_Struct::VecView<uint32_t, Rect2D>;
template struct impl_Struct::VecView<uint32_t, RectLayerKHR>;
template struct impl_Struct::VecView<uint32_t, RenderPassStripeInfoARM>;
template struct impl_Struct::VecView<uint32_t, RenderingAttachmentInfo>;
template struct impl_Struct::VecView<uint32_t, SampleCountBits>;
template struct impl_Struct::VecView<uint32_t, SampleLocationEXT>;
template struct impl_Struct::VecView<uint32_t, SemaphoreSubmitInfo>;
template struct impl_Struct::VecView<uint32_t, ShadingRatePaletteEntryNV>;
template struct impl_Struct::VecView<uint32_t, ShadingRatePaletteNV>;
template struct impl_Struct::VecView<uint32_t, SparseBufferMemoryBindInfo>;
template struct impl_Struct::VecView<uint32_t, SparseImageMemoryBind>;
template struct impl_Struct::VecView<uint32_t, SparseImageMemoryBindInfo>;
template struct impl_Struct::VecView<uint32_t, SparseImageOpaqueMemoryBindInfo>;
template struct impl_Struct::VecView<uint32_t, SparseMemoryBind>;
template struct impl_Struct::VecView<uint32_t, SpecializationMapEntry>;
template struct impl_Struct::VecView<uint32_t, StdVideoEncodeAV1OperatingPointInfo>;
template struct impl_Struct::VecView<uint32_t, StdVideoH264PictureParameterSet>;
template struct impl_Struct::VecView<uint32_t, StdVideoH264SequenceParameterSet>;
template struct impl_Struct::VecView<uint32_t, StdVideoH265PictureParameterSet>;
template struct impl_Struct::VecView<uint32_t, StdVideoH265SequenceParameterSet>;
template struct impl_Struct::VecView<uint32_t, StdVideoH265VideoParameterSet>;
template struct impl_Struct::VecView<uint32_t, SubpassDependency2>;
template struct impl_Struct::VecView<uint32_t, SubpassDependency>;
template struct impl_Struct::VecView<uint32_t, SubpassDescription2>;
template struct impl_Struct::VecView<uint32_t, SubpassDescription>;
template struct impl_Struct::VecView<uint32_t, SubpassSampleLocationsEXT>;
template struct impl_Struct::VecView<uint32_t, SubresourceLayout>;
template struct impl_Struct::VecView<uint32_t, TensorCopyARM>;
template struct impl_Struct::VecView<uint32_t, TensorMemoryBarrierARM>;
template struct impl_Struct::VecView<uint32_t, ValidationCheckEXT>;
template struct impl_Struct::VecView<uint32_t, ValidationFeatureDisableEXT>;
template struct impl_Struct::VecView<uint32_t, ValidationFeatureEnableEXT>;
template struct impl_Struct::VecView<uint32_t, VertexInputAttributeDescription>;
template struct impl_Struct::VecView<uint32_t, VertexInputBindingDescription>;
template struct impl_Struct::VecView<uint32_t, VertexInputBindingDivisorDescription>;
template struct impl_Struct::VecView<uint32_t, VideoEncodeH264NaluSliceInfoKHR>;
template struct impl_Struct::VecView<uint32_t, VideoEncodeH265NaluSliceSegmentInfoKHR>;
template struct impl_Struct::VecView<uint32_t, VideoEncodeRateControlLayerInfoKHR>;
template struct impl_Struct::VecView<uint32_t, VideoProfileInfoKHR>;
template struct impl_Struct::VecView<uint32_t, VideoReferenceSlotInfoKHR>;
template struct impl_Struct::VecView<uint32_t, Viewport>;
template struct impl_Struct::VecView<uint32_t, ViewportSwizzleNV>;
template struct impl_Struct::VecView<uint32_t, ViewportWScalingNV>;
template struct impl_Struct::VecView<uint32_t, WriteDescriptorSet>;
template struct impl_Struct::VecView<uint32_t, float>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<AccelerationStructureKHR>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<AccelerationStructureNV>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Buffer>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<CommandBuffer>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSet>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Fence>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Image>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ImageView>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<PhysicalDevice>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Pipeline>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<PipelineBinaryKHR>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Sampler>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ShaderEXT>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<SwapchainKHR>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<TensorARM>>;
template struct impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<TensorViewARM>>;
template struct impl_Struct::VecView<uint32_t, int32_t>;
template struct impl_Struct::VecView<uint32_t, int64_t>;
template struct impl_Struct::VecView<uint32_t, uint32_t>;
template struct impl_Struct::VecView<uint32_t, uint64_t>;
template struct impl_Struct::VecView<uint32_t, uint8_t>;
template struct impl_Struct::VecView<uint8_t, StdVideoEncodeH264RefListModEntry>;
template struct impl_Struct::VecView<uint8_t, StdVideoEncodeH264RefPicMarkingEntry>;
template struct impl_Struct::VecView<uint8_t, StdVideoH265ShortTermRefPicSet>;
template struct impl_Struct::VecView<uint8_t, int32_t>;
template struct impl_Struct::VecView<uint8_t, uint16_t>;
#ifdef VK_USE_PLATFORM_FUCHSIA
	template struct impl_Struct::VecView<uint32_t, ImageFormatConstraintsInfoFUCHSIA>;
	template struct impl_Struct::VecView<uint32_t, SysmemColorSpaceFUCHSIA>;
#endif // VK_USE_PLATFORM_FUCHSIA
} // namespace VkBindings
