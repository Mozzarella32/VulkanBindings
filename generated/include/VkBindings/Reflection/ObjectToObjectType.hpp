#pragma once

#include "VkBindings/ObjectsForward.hpp"

namespace VkBindings {
enum class ObjectType;
namespace Reflections {

template <typename T>
constexpr auto ObjectToObjectType() -> ObjectType;

template<> auto ObjectToObjectType<CommandBuffer>() -> ObjectType;
template<> auto ObjectToObjectType<DescriptorSet>() -> ObjectType;
template<> auto ObjectToObjectType<AccelerationStructureKHR>() -> ObjectType;
template<> auto ObjectToObjectType<AccelerationStructureNV>() -> ObjectType;
template<> auto ObjectToObjectType<Buffer>() -> ObjectType;
template<> auto ObjectToObjectType<BufferView>() -> ObjectType;
template<> auto ObjectToObjectType<CommandPool>() -> ObjectType;
template<> auto ObjectToObjectType<CuFunctionNVX>() -> ObjectType;
template<> auto ObjectToObjectType<CuModuleNVX>() -> ObjectType;
template<> auto ObjectToObjectType<DataGraphPipelineSessionARM>() -> ObjectType;
template<> auto ObjectToObjectType<DeferredOperationKHR>() -> ObjectType;
template<> auto ObjectToObjectType<DescriptorPool>() -> ObjectType;
template<> auto ObjectToObjectType<DescriptorSetLayout>() -> ObjectType;
template<> auto ObjectToObjectType<DescriptorUpdateTemplate>() -> ObjectType;
template<> auto ObjectToObjectType<DeviceMemory>() -> ObjectType;
template<> auto ObjectToObjectType<DisplayModeKHR>() -> ObjectType;
template<> auto ObjectToObjectType<Event>() -> ObjectType;
template<> auto ObjectToObjectType<ExternalComputeQueueNV>() -> ObjectType;
template<> auto ObjectToObjectType<Fence>() -> ObjectType;
template<> auto ObjectToObjectType<Framebuffer>() -> ObjectType;
template<> auto ObjectToObjectType<GpaSessionAMD>() -> ObjectType;
template<> auto ObjectToObjectType<Image>() -> ObjectType;
template<> auto ObjectToObjectType<ImageView>() -> ObjectType;
template<> auto ObjectToObjectType<IndirectCommandsLayoutEXT>() -> ObjectType;
template<> auto ObjectToObjectType<IndirectCommandsLayoutNV>() -> ObjectType;
template<> auto ObjectToObjectType<IndirectExecutionSetEXT>() -> ObjectType;
template<> auto ObjectToObjectType<MicromapEXT>() -> ObjectType;
template<> auto ObjectToObjectType<OpticalFlowSessionNV>() -> ObjectType;
template<> auto ObjectToObjectType<PerformanceConfigurationINTEL>() -> ObjectType;
template<> auto ObjectToObjectType<Pipeline>() -> ObjectType;
template<> auto ObjectToObjectType<PipelineBinaryKHR>() -> ObjectType;
template<> auto ObjectToObjectType<PipelineCache>() -> ObjectType;
template<> auto ObjectToObjectType<PipelineLayout>() -> ObjectType;
template<> auto ObjectToObjectType<PrivateDataSlot>() -> ObjectType;
template<> auto ObjectToObjectType<QueryPool>() -> ObjectType;
template<> auto ObjectToObjectType<Queue>() -> ObjectType;
template<> auto ObjectToObjectType<RenderPass>() -> ObjectType;
template<> auto ObjectToObjectType<Sampler>() -> ObjectType;
template<> auto ObjectToObjectType<SamplerYcbcrConversion>() -> ObjectType;
template<> auto ObjectToObjectType<Semaphore>() -> ObjectType;
template<> auto ObjectToObjectType<ShaderEXT>() -> ObjectType;
template<> auto ObjectToObjectType<ShaderInstrumentationARM>() -> ObjectType;
template<> auto ObjectToObjectType<ShaderModule>() -> ObjectType;
template<> auto ObjectToObjectType<SwapchainKHR>() -> ObjectType;
template<> auto ObjectToObjectType<TensorARM>() -> ObjectType;
template<> auto ObjectToObjectType<TensorViewARM>() -> ObjectType;
template<> auto ObjectToObjectType<ValidationCacheEXT>() -> ObjectType;
template<> auto ObjectToObjectType<VideoSessionKHR>() -> ObjectType;
template<> auto ObjectToObjectType<VideoSessionParametersKHR>() -> ObjectType;
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> auto ObjectToObjectType<CudaFunctionNV>() -> ObjectType;
	template<> auto ObjectToObjectType<CudaModuleNV>() -> ObjectType;
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> auto ObjectToObjectType<BufferCollectionFUCHSIA>() -> ObjectType;
#endif // VK_USE_PLATFORM_FUCHSIA
template<> auto ObjectToObjectType<Device>() -> ObjectType;
template<> auto ObjectToObjectType<DisplayKHR>() -> ObjectType;
template<> auto ObjectToObjectType<DebugReportCallbackEXT>() -> ObjectType;
template<> auto ObjectToObjectType<DebugUtilsMessengerEXT>() -> ObjectType;
template<> auto ObjectToObjectType<PhysicalDevice>() -> ObjectType;
template<> auto ObjectToObjectType<SurfaceKHR>() -> ObjectType;
template<> auto ObjectToObjectType<Instance>() -> ObjectType;
} // namespace Reflections
} // namespace VkBindings
