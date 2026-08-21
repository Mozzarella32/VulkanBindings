#include "/home/Valentin/source/VulkanBindings/generated/include/VkBindings/Reflection/ObjectToObjectType.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/ObjectsForward.hpp"

namespace VkBindings::Reflections {
template<> auto ObjectToObjectType<CommandBuffer>() -> ObjectType { return ObjectType::CommandBuffer; }
template<> auto ObjectToObjectType<DescriptorSet>() -> ObjectType { return ObjectType::DescriptorSet; }
template<> auto ObjectToObjectType<AccelerationStructureKHR>() -> ObjectType { return ObjectType::AccelerationStructureKHR; }
template<> auto ObjectToObjectType<AccelerationStructureNV>() -> ObjectType { return ObjectType::AccelerationStructureNV; }
template<> auto ObjectToObjectType<Buffer>() -> ObjectType { return ObjectType::Buffer; }
template<> auto ObjectToObjectType<BufferView>() -> ObjectType { return ObjectType::BufferView; }
template<> auto ObjectToObjectType<CommandPool>() -> ObjectType { return ObjectType::CommandPool; }
template<> auto ObjectToObjectType<CuFunctionNVX>() -> ObjectType { return ObjectType::CuFunctionNVX; }
template<> auto ObjectToObjectType<CuModuleNVX>() -> ObjectType { return ObjectType::CuModuleNVX; }
template<> auto ObjectToObjectType<DataGraphPipelineSessionARM>() -> ObjectType { return ObjectType::DataGraphPipelineSessionARM; }
template<> auto ObjectToObjectType<DeferredOperationKHR>() -> ObjectType { return ObjectType::DeferredOperationKHR; }
template<> auto ObjectToObjectType<DescriptorPool>() -> ObjectType { return ObjectType::DescriptorPool; }
template<> auto ObjectToObjectType<DescriptorSetLayout>() -> ObjectType { return ObjectType::DescriptorSetLayout; }
template<> auto ObjectToObjectType<DescriptorUpdateTemplate>() -> ObjectType { return ObjectType::DescriptorUpdateTemplate; }
template<> auto ObjectToObjectType<DeviceMemory>() -> ObjectType { return ObjectType::DeviceMemory; }
template<> auto ObjectToObjectType<DisplayModeKHR>() -> ObjectType { return ObjectType::DisplayModeKHR; }
template<> auto ObjectToObjectType<Event>() -> ObjectType { return ObjectType::Event; }
template<> auto ObjectToObjectType<ExternalComputeQueueNV>() -> ObjectType { return ObjectType::ExternalComputeQueueNV; }
template<> auto ObjectToObjectType<Fence>() -> ObjectType { return ObjectType::Fence; }
template<> auto ObjectToObjectType<Framebuffer>() -> ObjectType { return ObjectType::Framebuffer; }
template<> auto ObjectToObjectType<GpaSessionAMD>() -> ObjectType { return ObjectType::GpaSessionAMD; }
template<> auto ObjectToObjectType<Image>() -> ObjectType { return ObjectType::Image; }
template<> auto ObjectToObjectType<ImageView>() -> ObjectType { return ObjectType::ImageView; }
template<> auto ObjectToObjectType<IndirectCommandsLayoutEXT>() -> ObjectType { return ObjectType::IndirectCommandsLayoutEXT; }
template<> auto ObjectToObjectType<IndirectCommandsLayoutNV>() -> ObjectType { return ObjectType::IndirectCommandsLayoutNV; }
template<> auto ObjectToObjectType<IndirectExecutionSetEXT>() -> ObjectType { return ObjectType::IndirectExecutionSetEXT; }
template<> auto ObjectToObjectType<MicromapEXT>() -> ObjectType { return ObjectType::MicromapEXT; }
template<> auto ObjectToObjectType<OpticalFlowSessionNV>() -> ObjectType { return ObjectType::OpticalFlowSessionNV; }
template<> auto ObjectToObjectType<PerformanceConfigurationINTEL>() -> ObjectType { return ObjectType::PerformanceConfigurationINTEL; }
template<> auto ObjectToObjectType<Pipeline>() -> ObjectType { return ObjectType::Pipeline; }
template<> auto ObjectToObjectType<PipelineBinaryKHR>() -> ObjectType { return ObjectType::PipelineBinaryKHR; }
template<> auto ObjectToObjectType<PipelineCache>() -> ObjectType { return ObjectType::PipelineCache; }
template<> auto ObjectToObjectType<PipelineLayout>() -> ObjectType { return ObjectType::PipelineLayout; }
template<> auto ObjectToObjectType<PrivateDataSlot>() -> ObjectType { return ObjectType::PrivateDataSlot; }
template<> auto ObjectToObjectType<QueryPool>() -> ObjectType { return ObjectType::QueryPool; }
template<> auto ObjectToObjectType<Queue>() -> ObjectType { return ObjectType::Queue; }
template<> auto ObjectToObjectType<RenderPass>() -> ObjectType { return ObjectType::RenderPass; }
template<> auto ObjectToObjectType<Sampler>() -> ObjectType { return ObjectType::Sampler; }
template<> auto ObjectToObjectType<SamplerYcbcrConversion>() -> ObjectType { return ObjectType::SamplerYcbcrConversion; }
template<> auto ObjectToObjectType<Semaphore>() -> ObjectType { return ObjectType::Semaphore; }
template<> auto ObjectToObjectType<ShaderEXT>() -> ObjectType { return ObjectType::ShaderEXT; }
template<> auto ObjectToObjectType<ShaderInstrumentationARM>() -> ObjectType { return ObjectType::ShaderInstrumentationARM; }
template<> auto ObjectToObjectType<ShaderModule>() -> ObjectType { return ObjectType::ShaderModule; }
template<> auto ObjectToObjectType<SwapchainKHR>() -> ObjectType { return ObjectType::SwapchainKHR; }
template<> auto ObjectToObjectType<TensorARM>() -> ObjectType { return ObjectType::TensorARM; }
template<> auto ObjectToObjectType<TensorViewARM>() -> ObjectType { return ObjectType::TensorViewARM; }
template<> auto ObjectToObjectType<ValidationCacheEXT>() -> ObjectType { return ObjectType::ValidationCacheEXT; }
template<> auto ObjectToObjectType<VideoSessionKHR>() -> ObjectType { return ObjectType::VideoSessionKHR; }
template<> auto ObjectToObjectType<VideoSessionParametersKHR>() -> ObjectType { return ObjectType::VideoSessionParametersKHR; }
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> auto ObjectToObjectType<CudaFunctionNV>() -> ObjectType { return ObjectType::CudaFunctionNV; }
	template<> auto ObjectToObjectType<CudaModuleNV>() -> ObjectType { return ObjectType::CudaModuleNV; }
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> auto ObjectToObjectType<BufferCollectionFUCHSIA>() -> ObjectType { return ObjectType::BufferCollectionFUCHSIA; }
#endif // VK_USE_PLATFORM_FUCHSIA
template<> auto ObjectToObjectType<Device>() -> ObjectType { return ObjectType::Device; }
template<> auto ObjectToObjectType<DisplayKHR>() -> ObjectType { return ObjectType::DisplayKHR; }
template<> auto ObjectToObjectType<DebugReportCallbackEXT>() -> ObjectType { return ObjectType::DebugReportCallbackEXT; }
template<> auto ObjectToObjectType<DebugUtilsMessengerEXT>() -> ObjectType { return ObjectType::DebugUtilsMessengerEXT; }
template<> auto ObjectToObjectType<PhysicalDevice>() -> ObjectType { return ObjectType::PhysicalDevice; }
template<> auto ObjectToObjectType<SurfaceKHR>() -> ObjectType { return ObjectType::SurfaceKHR; }
template<> auto ObjectToObjectType<Instance>() -> ObjectType { return ObjectType::Instance; }
} // namespace VkBindings::Reflections
