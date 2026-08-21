#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/private/StructTemplatesInterface.hpp"

// NOLINTBEGIN(misc-include-cleaner)
// Needed for getting implmenetations
#include "VkBindings/private/StructTemplates.hpp"

// NOLINTEND(misc-include-cleaner)
namespace VkBindings {
template struct impl_Struct::AssignableHandle<AccelerationStructureKHR>;
template struct impl_Struct::AssignableHandle<AccelerationStructureNV>;
template struct impl_Struct::AssignableHandle<Buffer>;
template struct impl_Struct::AssignableHandle<BufferView>;
template struct impl_Struct::AssignableHandle<CommandBuffer>;
template struct impl_Struct::AssignableHandle<CommandPool>;
template struct impl_Struct::AssignableHandle<CuFunctionNVX>;
template struct impl_Struct::AssignableHandle<CuModuleNVX>;
template struct impl_Struct::AssignableHandle<DataGraphPipelineSessionARM>;
template struct impl_Struct::AssignableHandle<DescriptorPool>;
template struct impl_Struct::AssignableHandle<DescriptorSet>;
template struct impl_Struct::AssignableHandle<DescriptorSetLayout>;
template struct impl_Struct::AssignableHandle<DescriptorUpdateTemplate>;
template struct impl_Struct::AssignableHandle<DeviceMemory>;
template struct impl_Struct::AssignableHandle<DisplayKHR>;
template struct impl_Struct::AssignableHandle<DisplayModeKHR>;
template struct impl_Struct::AssignableHandle<Event>;
template struct impl_Struct::AssignableHandle<Fence>;
template struct impl_Struct::AssignableHandle<Framebuffer>;
template struct impl_Struct::AssignableHandle<GpaSessionAMD>;
template struct impl_Struct::AssignableHandle<Image>;
template struct impl_Struct::AssignableHandle<ImageView>;
template struct impl_Struct::AssignableHandle<IndirectCommandsLayoutEXT>;
template struct impl_Struct::AssignableHandle<IndirectCommandsLayoutNV>;
template struct impl_Struct::AssignableHandle<IndirectExecutionSetEXT>;
template struct impl_Struct::AssignableHandle<MicromapEXT>;
template struct impl_Struct::AssignableHandle<PhysicalDevice>;
template struct impl_Struct::AssignableHandle<Pipeline>;
template struct impl_Struct::AssignableHandle<PipelineBinaryKHR>;
template struct impl_Struct::AssignableHandle<PipelineLayout>;
template struct impl_Struct::AssignableHandle<QueryPool>;
template struct impl_Struct::AssignableHandle<Queue>;
template struct impl_Struct::AssignableHandle<RenderPass>;
template struct impl_Struct::AssignableHandle<Sampler>;
template struct impl_Struct::AssignableHandle<SamplerYcbcrConversion>;
template struct impl_Struct::AssignableHandle<Semaphore>;
template struct impl_Struct::AssignableHandle<ShaderEXT>;
template struct impl_Struct::AssignableHandle<ShaderModule>;
template struct impl_Struct::AssignableHandle<SurfaceKHR>;
template struct impl_Struct::AssignableHandle<SwapchainKHR>;
template struct impl_Struct::AssignableHandle<TensorARM>;
template struct impl_Struct::AssignableHandle<TensorViewARM>;
template struct impl_Struct::AssignableHandle<ValidationCacheEXT>;
template struct impl_Struct::AssignableHandle<VideoSessionKHR>;
template struct impl_Struct::AssignableHandle<VideoSessionParametersKHR>;
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template struct impl_Struct::AssignableHandle<CudaFunctionNV>;
	template struct impl_Struct::AssignableHandle<CudaModuleNV>;
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template struct impl_Struct::AssignableHandle<BufferCollectionFUCHSIA>;
#endif // VK_USE_PLATFORM_FUCHSIA
} // namespace VkBindings
