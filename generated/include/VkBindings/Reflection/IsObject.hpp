#pragma once

#include "VkBindings/ObjectsForward.hpp"

#include <type_traits>

namespace VkBindings::Reflections {
namespace Reflections_impl {
template <typename T> struct IsObject : std::false_type {};
} // namespace Reflections_impl

template <typename T> constexpr bool IsObject = Reflections_impl::IsObject<T>::value;
} // namespace VkBindings::Reflections

namespace VkBindings::Concepts {
template <typename T> concept IsObject = Reflections::IsObject<T>;
} // namespace VkBindings::Concepts

namespace VkBindings::Reflections::Reflections_impl {
template<> struct IsObject<CommandBuffer> : std::true_type{};
template<> struct IsObject<DescriptorSet> : std::true_type{};
template<> struct IsObject<AccelerationStructureKHR> : std::true_type{};
template<> struct IsObject<AccelerationStructureNV> : std::true_type{};
template<> struct IsObject<Buffer> : std::true_type{};
template<> struct IsObject<BufferView> : std::true_type{};
template<> struct IsObject<CommandPool> : std::true_type{};
template<> struct IsObject<CuFunctionNVX> : std::true_type{};
template<> struct IsObject<CuModuleNVX> : std::true_type{};
template<> struct IsObject<DataGraphPipelineSessionARM> : std::true_type{};
template<> struct IsObject<DeferredOperationKHR> : std::true_type{};
template<> struct IsObject<DescriptorPool> : std::true_type{};
template<> struct IsObject<DescriptorSetLayout> : std::true_type{};
template<> struct IsObject<DescriptorUpdateTemplate> : std::true_type{};
template<> struct IsObject<DeviceMemory> : std::true_type{};
template<> struct IsObject<DisplayModeKHR> : std::true_type{};
template<> struct IsObject<Event> : std::true_type{};
template<> struct IsObject<ExternalComputeQueueNV> : std::true_type{};
template<> struct IsObject<Fence> : std::true_type{};
template<> struct IsObject<Framebuffer> : std::true_type{};
template<> struct IsObject<GpaSessionAMD> : std::true_type{};
template<> struct IsObject<Image> : std::true_type{};
template<> struct IsObject<ImageView> : std::true_type{};
template<> struct IsObject<IndirectCommandsLayoutEXT> : std::true_type{};
template<> struct IsObject<IndirectCommandsLayoutNV> : std::true_type{};
template<> struct IsObject<IndirectExecutionSetEXT> : std::true_type{};
template<> struct IsObject<MicromapEXT> : std::true_type{};
template<> struct IsObject<OpticalFlowSessionNV> : std::true_type{};
template<> struct IsObject<PerformanceConfigurationINTEL> : std::true_type{};
template<> struct IsObject<Pipeline> : std::true_type{};
template<> struct IsObject<PipelineBinaryKHR> : std::true_type{};
template<> struct IsObject<PipelineCache> : std::true_type{};
template<> struct IsObject<PipelineLayout> : std::true_type{};
template<> struct IsObject<PrivateDataSlot> : std::true_type{};
template<> struct IsObject<QueryPool> : std::true_type{};
template<> struct IsObject<Queue> : std::true_type{};
template<> struct IsObject<RenderPass> : std::true_type{};
template<> struct IsObject<Sampler> : std::true_type{};
template<> struct IsObject<SamplerYcbcrConversion> : std::true_type{};
template<> struct IsObject<Semaphore> : std::true_type{};
template<> struct IsObject<ShaderEXT> : std::true_type{};
template<> struct IsObject<ShaderInstrumentationARM> : std::true_type{};
template<> struct IsObject<ShaderModule> : std::true_type{};
template<> struct IsObject<SwapchainKHR> : std::true_type{};
template<> struct IsObject<TensorARM> : std::true_type{};
template<> struct IsObject<TensorViewARM> : std::true_type{};
template<> struct IsObject<ValidationCacheEXT> : std::true_type{};
template<> struct IsObject<VideoSessionKHR> : std::true_type{};
template<> struct IsObject<VideoSessionParametersKHR> : std::true_type{};
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> struct IsObject<CudaFunctionNV> : std::true_type{};
	template<> struct IsObject<CudaModuleNV> : std::true_type{};
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> struct IsObject<BufferCollectionFUCHSIA> : std::true_type{};
#endif // VK_USE_PLATFORM_FUCHSIA
template<> struct IsObject<Device> : std::true_type{};
template<> struct IsObject<DisplayKHR> : std::true_type{};
template<> struct IsObject<DebugReportCallbackEXT> : std::true_type{};
template<> struct IsObject<DebugUtilsMessengerEXT> : std::true_type{};
template<> struct IsObject<PhysicalDevice> : std::true_type{};
template<> struct IsObject<SurfaceKHR> : std::true_type{};
template<> struct IsObject<Instance> : std::true_type{};
} // namespace VkBindings::Reflections::Reflections_impl
