#include "VkBindings/private/StructTemplates/ArrayProxyInterface.hpp"

#include "VkBindings/Bits.hpp"
#include "VkBindings/Flags.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/Structs.hpp"
#include "VkBindings/private/StructTemplates/AssignableHandleInterface.hpp"

#include <cstdint>

// NOLINTBEGIN(misc-include-cleaner)
// Needed for getting implmenetation
#include "VkBindings/private/StructTemplates/ArrayProxy.hpp"

// NOLINTEND(misc-include-cleaner)
namespace VkBindings {
template struct impl_Struct::ArrayProxy<AccelerationStructureBuildGeometryInfoKHR>;
template struct impl_Struct::ArrayProxy<BindAccelerationStructureMemoryInfoNV>;
template struct impl_Struct::ArrayProxy<BindBufferMemoryInfo>;
template struct impl_Struct::ArrayProxy<BindDataGraphPipelineSessionMemoryInfoARM>;
template struct impl_Struct::ArrayProxy<BindImageMemoryInfo>;
template struct impl_Struct::ArrayProxy<BindSparseInfo>;
template struct impl_Struct::ArrayProxy<BindTensorMemoryInfoARM>;
template struct impl_Struct::ArrayProxy<BindTransformFeedbackBuffer2InfoEXT>;
template struct impl_Struct::ArrayProxy<BindVertexBuffer3InfoKHR>;
template struct impl_Struct::ArrayProxy<BindVideoSessionMemoryInfoKHR>;
template struct impl_Struct::ArrayProxy<BufferCopy>;
template struct impl_Struct::ArrayProxy<BufferImageCopy>;
template struct impl_Struct::ArrayProxy<BufferMemoryBarrier>;
template struct impl_Struct::ArrayProxy<CalibratedTimestampInfoKHR>;
template struct impl_Struct::ArrayProxy<ClearAttachment>;
template struct impl_Struct::ArrayProxy<ClearRect>;
template struct impl_Struct::ArrayProxy<CoarseSampleOrderCustomNV>;
template struct impl_Struct::ArrayProxy<ColorBlendAdvancedEXT>;
template struct impl_Struct::ArrayProxy<ColorBlendEquationEXT>;
template struct impl_Struct::ArrayProxy<ColorComponentFlags>;
template struct impl_Struct::ArrayProxy<ComputePipelineCreateInfo>;
template struct impl_Struct::ArrayProxy<ConvertCooperativeVectorMatrixInfoNV>;
template struct impl_Struct::ArrayProxy<CopyDescriptorSet>;
template struct impl_Struct::ArrayProxy<DataGraphPipelineCreateInfoARM>;
template struct impl_Struct::ArrayProxy<DecompressMemoryRegionNV>;
template struct impl_Struct::ArrayProxy<DependencyInfo>;
template struct impl_Struct::ArrayProxy<DescriptorBufferBindingInfoEXT>;
template struct impl_Struct::ArrayProxy<GraphicsPipelineCreateInfo>;
template struct impl_Struct::ArrayProxy<HdrMetadataEXT>;
template struct impl_Struct::ArrayProxy<HostAddressRangeEXT>;
template struct impl_Struct::ArrayProxy<HostImageLayoutTransitionInfo>;
template struct impl_Struct::ArrayProxy<ImageBlit>;
template struct impl_Struct::ArrayProxy<ImageCopy>;
template struct impl_Struct::ArrayProxy<ImageMemoryBarrier>;
template struct impl_Struct::ArrayProxy<ImageResolve>;
template struct impl_Struct::ArrayProxy<ImageSubresourceLayers>;
template struct impl_Struct::ArrayProxy<ImageSubresourceRange>;
template struct impl_Struct::ArrayProxy<MappedMemoryRange>;
template struct impl_Struct::ArrayProxy<MemoryBarrier>;
template struct impl_Struct::ArrayProxy<MicromapBuildInfoEXT>;
template struct impl_Struct::ArrayProxy<MultiDrawIndexedInfoEXT>;
template struct impl_Struct::ArrayProxy<MultiDrawInfoEXT>;
template struct impl_Struct::ArrayProxy<RayTracingPipelineCreateInfoKHR>;
template struct impl_Struct::ArrayProxy<RayTracingPipelineCreateInfoNV>;
template struct impl_Struct::ArrayProxy<Rect2D>;
template struct impl_Struct::ArrayProxy<ResourceDescriptorInfoEXT>;
template struct impl_Struct::ArrayProxy<SamplerCreateInfo>;
template struct impl_Struct::ArrayProxy<ShaderCreateInfoEXT>;
template struct impl_Struct::ArrayProxy<ShaderStageBits>;
template struct impl_Struct::ArrayProxy<ShadingRatePaletteNV>;
template struct impl_Struct::ArrayProxy<SubmitInfo2>;
template struct impl_Struct::ArrayProxy<SubmitInfo>;
template struct impl_Struct::ArrayProxy<SwapchainCreateInfoKHR>;
template struct impl_Struct::ArrayProxy<VertexInputAttributeDescription2EXT>;
template struct impl_Struct::ArrayProxy<VertexInputBindingDescription2EXT>;
template struct impl_Struct::ArrayProxy<Viewport>;
template struct impl_Struct::ArrayProxy<ViewportSwizzleNV>;
template struct impl_Struct::ArrayProxy<ViewportWScalingNV>;
template struct impl_Struct::ArrayProxy<WriteDescriptorSet>;
template struct impl_Struct::ArrayProxy<WriteIndirectExecutionSetPipelineEXT>;
template struct impl_Struct::ArrayProxy<WriteIndirectExecutionSetShaderEXT>;
template struct impl_Struct::ArrayProxy<float>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureKHR>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureNV>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<CommandBuffer>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<DescriptorSet>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Event>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Fence>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Image>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<MicromapEXT>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<PipelineCache>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<ShaderEXT>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<SwapchainKHR>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<TensorARM>>;
template struct impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<ValidationCacheEXT>>;
template struct impl_Struct::ArrayProxy<uint32_t>;
template struct impl_Struct::ArrayProxy<uint64_t>;
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template struct impl_Struct::ArrayProxy<ExecutionGraphPipelineCreateInfoAMDX>;
#endif // VK_ENABLE_BETA_EXTENSIONS
} // namespace VkBindings
