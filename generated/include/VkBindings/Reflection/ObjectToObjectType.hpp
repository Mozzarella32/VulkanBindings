#pragma once

#include "VkBindings/Enums.hpp"
#include "VkBindings/ObjectsForward.hpp"

namespace VkBindings::Reflections {
namespace Reflections_impl {
template <typename T> struct ObjectToObjectType { static const ObjectType value = ObjectType::Unknown; };
} // namespace Reflections_impl

template <typename T> constexpr ObjectType ObjectToObjectType = Reflections_impl::ObjectToObjectType<T>::value;
} // namespace VkBindings::Reflections


namespace VkBindings::Reflections::Reflections_impl {
template<> struct ObjectToObjectType<CommandBuffer> { static const ObjectType value = ObjectType::CommandBuffer; };
template<> struct ObjectToObjectType<DescriptorSet> { static const ObjectType value = ObjectType::DescriptorSet; };
template<> struct ObjectToObjectType<AccelerationStructureKHR> { static const ObjectType value = ObjectType::AccelerationStructureKHR; };
template<> struct ObjectToObjectType<AccelerationStructureNV> { static const ObjectType value = ObjectType::AccelerationStructureNV; };
template<> struct ObjectToObjectType<Buffer> { static const ObjectType value = ObjectType::Buffer; };
template<> struct ObjectToObjectType<BufferView> { static const ObjectType value = ObjectType::BufferView; };
template<> struct ObjectToObjectType<CommandPool> { static const ObjectType value = ObjectType::CommandPool; };
template<> struct ObjectToObjectType<CuFunctionNVX> { static const ObjectType value = ObjectType::CuFunctionNVX; };
template<> struct ObjectToObjectType<CuModuleNVX> { static const ObjectType value = ObjectType::CuModuleNVX; };
template<> struct ObjectToObjectType<DataGraphPipelineSessionARM> { static const ObjectType value = ObjectType::DataGraphPipelineSessionARM; };
template<> struct ObjectToObjectType<DeferredOperationKHR> { static const ObjectType value = ObjectType::DeferredOperationKHR; };
template<> struct ObjectToObjectType<DescriptorPool> { static const ObjectType value = ObjectType::DescriptorPool; };
template<> struct ObjectToObjectType<DescriptorSetLayout> { static const ObjectType value = ObjectType::DescriptorSetLayout; };
template<> struct ObjectToObjectType<DescriptorUpdateTemplate> { static const ObjectType value = ObjectType::DescriptorUpdateTemplate; };
template<> struct ObjectToObjectType<DeviceMemory> { static const ObjectType value = ObjectType::DeviceMemory; };
template<> struct ObjectToObjectType<DisplayModeKHR> { static const ObjectType value = ObjectType::DisplayModeKHR; };
template<> struct ObjectToObjectType<Event> { static const ObjectType value = ObjectType::Event; };
template<> struct ObjectToObjectType<ExternalComputeQueueNV> { static const ObjectType value = ObjectType::ExternalComputeQueueNV; };
template<> struct ObjectToObjectType<Fence> { static const ObjectType value = ObjectType::Fence; };
template<> struct ObjectToObjectType<Framebuffer> { static const ObjectType value = ObjectType::Framebuffer; };
template<> struct ObjectToObjectType<GpaSessionAMD> { static const ObjectType value = ObjectType::GpaSessionAMD; };
template<> struct ObjectToObjectType<Image> { static const ObjectType value = ObjectType::Image; };
template<> struct ObjectToObjectType<ImageView> { static const ObjectType value = ObjectType::ImageView; };
template<> struct ObjectToObjectType<IndirectCommandsLayoutEXT> { static const ObjectType value = ObjectType::IndirectCommandsLayoutEXT; };
template<> struct ObjectToObjectType<IndirectCommandsLayoutNV> { static const ObjectType value = ObjectType::IndirectCommandsLayoutNV; };
template<> struct ObjectToObjectType<IndirectExecutionSetEXT> { static const ObjectType value = ObjectType::IndirectExecutionSetEXT; };
template<> struct ObjectToObjectType<MicromapEXT> { static const ObjectType value = ObjectType::MicromapEXT; };
template<> struct ObjectToObjectType<OpticalFlowSessionNV> { static const ObjectType value = ObjectType::OpticalFlowSessionNV; };
template<> struct ObjectToObjectType<PerformanceConfigurationINTEL> { static const ObjectType value = ObjectType::PerformanceConfigurationINTEL; };
template<> struct ObjectToObjectType<Pipeline> { static const ObjectType value = ObjectType::Pipeline; };
template<> struct ObjectToObjectType<PipelineBinaryKHR> { static const ObjectType value = ObjectType::PipelineBinaryKHR; };
template<> struct ObjectToObjectType<PipelineCache> { static const ObjectType value = ObjectType::PipelineCache; };
template<> struct ObjectToObjectType<PipelineLayout> { static const ObjectType value = ObjectType::PipelineLayout; };
template<> struct ObjectToObjectType<PrivateDataSlot> { static const ObjectType value = ObjectType::PrivateDataSlot; };
template<> struct ObjectToObjectType<QueryPool> { static const ObjectType value = ObjectType::QueryPool; };
template<> struct ObjectToObjectType<Queue> { static const ObjectType value = ObjectType::Queue; };
template<> struct ObjectToObjectType<RenderPass> { static const ObjectType value = ObjectType::RenderPass; };
template<> struct ObjectToObjectType<Sampler> { static const ObjectType value = ObjectType::Sampler; };
template<> struct ObjectToObjectType<SamplerYcbcrConversion> { static const ObjectType value = ObjectType::SamplerYcbcrConversion; };
template<> struct ObjectToObjectType<Semaphore> { static const ObjectType value = ObjectType::Semaphore; };
template<> struct ObjectToObjectType<ShaderEXT> { static const ObjectType value = ObjectType::ShaderEXT; };
template<> struct ObjectToObjectType<ShaderInstrumentationARM> { static const ObjectType value = ObjectType::ShaderInstrumentationARM; };
template<> struct ObjectToObjectType<ShaderModule> { static const ObjectType value = ObjectType::ShaderModule; };
template<> struct ObjectToObjectType<SwapchainKHR> { static const ObjectType value = ObjectType::SwapchainKHR; };
template<> struct ObjectToObjectType<TensorARM> { static const ObjectType value = ObjectType::TensorARM; };
template<> struct ObjectToObjectType<TensorViewARM> { static const ObjectType value = ObjectType::TensorViewARM; };
template<> struct ObjectToObjectType<ValidationCacheEXT> { static const ObjectType value = ObjectType::ValidationCacheEXT; };
template<> struct ObjectToObjectType<VideoSessionKHR> { static const ObjectType value = ObjectType::VideoSessionKHR; };
template<> struct ObjectToObjectType<VideoSessionParametersKHR> { static const ObjectType value = ObjectType::VideoSessionParametersKHR; };
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> struct ObjectToObjectType<CudaFunctionNV> { static const ObjectType value = ObjectType::CudaFunctionNV; };
	template<> struct ObjectToObjectType<CudaModuleNV> { static const ObjectType value = ObjectType::CudaModuleNV; };
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> struct ObjectToObjectType<BufferCollectionFUCHSIA> { static const ObjectType value = ObjectType::BufferCollectionFUCHSIA; };
#endif // VK_USE_PLATFORM_FUCHSIA
template<> struct ObjectToObjectType<Device> { static const ObjectType value = ObjectType::Device; };
template<> struct ObjectToObjectType<DisplayKHR> { static const ObjectType value = ObjectType::DisplayKHR; };
template<> struct ObjectToObjectType<DebugReportCallbackEXT> { static const ObjectType value = ObjectType::DebugReportCallbackEXT; };
template<> struct ObjectToObjectType<DebugUtilsMessengerEXT> { static const ObjectType value = ObjectType::DebugUtilsMessengerEXT; };
template<> struct ObjectToObjectType<PhysicalDevice> { static const ObjectType value = ObjectType::PhysicalDevice; };
template<> struct ObjectToObjectType<SurfaceKHR> { static const ObjectType value = ObjectType::SurfaceKHR; };
template<> struct ObjectToObjectType<Instance> { static const ObjectType value = ObjectType::Instance; };
} // namespace VkBindings::Reflections::Reflections_impl
