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
template<> struct ObjectToObjectType<CommandBuffer> { ObjectType value = ObjectType::CommandBuffer; };
template<> struct ObjectToObjectType<DescriptorSet> { ObjectType value = ObjectType::DescriptorSet; };
template<> struct ObjectToObjectType<AccelerationStructureKHR> { ObjectType value = ObjectType::AccelerationStructureKHR; };
template<> struct ObjectToObjectType<AccelerationStructureNV> { ObjectType value = ObjectType::AccelerationStructureNV; };
template<> struct ObjectToObjectType<Buffer> { ObjectType value = ObjectType::Buffer; };
template<> struct ObjectToObjectType<BufferView> { ObjectType value = ObjectType::BufferView; };
template<> struct ObjectToObjectType<CommandPool> { ObjectType value = ObjectType::CommandPool; };
template<> struct ObjectToObjectType<CuFunctionNVX> { ObjectType value = ObjectType::CuFunctionNVX; };
template<> struct ObjectToObjectType<CuModuleNVX> { ObjectType value = ObjectType::CuModuleNVX; };
template<> struct ObjectToObjectType<DataGraphPipelineSessionARM> { ObjectType value = ObjectType::DataGraphPipelineSessionARM; };
template<> struct ObjectToObjectType<DeferredOperationKHR> { ObjectType value = ObjectType::DeferredOperationKHR; };
template<> struct ObjectToObjectType<DescriptorPool> { ObjectType value = ObjectType::DescriptorPool; };
template<> struct ObjectToObjectType<DescriptorSetLayout> { ObjectType value = ObjectType::DescriptorSetLayout; };
template<> struct ObjectToObjectType<DescriptorUpdateTemplate> { ObjectType value = ObjectType::DescriptorUpdateTemplate; };
template<> struct ObjectToObjectType<DeviceMemory> { ObjectType value = ObjectType::DeviceMemory; };
template<> struct ObjectToObjectType<DisplayModeKHR> { ObjectType value = ObjectType::DisplayModeKHR; };
template<> struct ObjectToObjectType<Event> { ObjectType value = ObjectType::Event; };
template<> struct ObjectToObjectType<ExternalComputeQueueNV> { ObjectType value = ObjectType::ExternalComputeQueueNV; };
template<> struct ObjectToObjectType<Fence> { ObjectType value = ObjectType::Fence; };
template<> struct ObjectToObjectType<Framebuffer> { ObjectType value = ObjectType::Framebuffer; };
template<> struct ObjectToObjectType<GpaSessionAMD> { ObjectType value = ObjectType::GpaSessionAMD; };
template<> struct ObjectToObjectType<Image> { ObjectType value = ObjectType::Image; };
template<> struct ObjectToObjectType<ImageView> { ObjectType value = ObjectType::ImageView; };
template<> struct ObjectToObjectType<IndirectCommandsLayoutEXT> { ObjectType value = ObjectType::IndirectCommandsLayoutEXT; };
template<> struct ObjectToObjectType<IndirectCommandsLayoutNV> { ObjectType value = ObjectType::IndirectCommandsLayoutNV; };
template<> struct ObjectToObjectType<IndirectExecutionSetEXT> { ObjectType value = ObjectType::IndirectExecutionSetEXT; };
template<> struct ObjectToObjectType<MicromapEXT> { ObjectType value = ObjectType::MicromapEXT; };
template<> struct ObjectToObjectType<OpticalFlowSessionNV> { ObjectType value = ObjectType::OpticalFlowSessionNV; };
template<> struct ObjectToObjectType<PerformanceConfigurationINTEL> { ObjectType value = ObjectType::PerformanceConfigurationINTEL; };
template<> struct ObjectToObjectType<Pipeline> { ObjectType value = ObjectType::Pipeline; };
template<> struct ObjectToObjectType<PipelineBinaryKHR> { ObjectType value = ObjectType::PipelineBinaryKHR; };
template<> struct ObjectToObjectType<PipelineCache> { ObjectType value = ObjectType::PipelineCache; };
template<> struct ObjectToObjectType<PipelineLayout> { ObjectType value = ObjectType::PipelineLayout; };
template<> struct ObjectToObjectType<PrivateDataSlot> { ObjectType value = ObjectType::PrivateDataSlot; };
template<> struct ObjectToObjectType<QueryPool> { ObjectType value = ObjectType::QueryPool; };
template<> struct ObjectToObjectType<Queue> { ObjectType value = ObjectType::Queue; };
template<> struct ObjectToObjectType<RenderPass> { ObjectType value = ObjectType::RenderPass; };
template<> struct ObjectToObjectType<Sampler> { ObjectType value = ObjectType::Sampler; };
template<> struct ObjectToObjectType<SamplerYcbcrConversion> { ObjectType value = ObjectType::SamplerYcbcrConversion; };
template<> struct ObjectToObjectType<Semaphore> { ObjectType value = ObjectType::Semaphore; };
template<> struct ObjectToObjectType<ShaderEXT> { ObjectType value = ObjectType::ShaderEXT; };
template<> struct ObjectToObjectType<ShaderInstrumentationARM> { ObjectType value = ObjectType::ShaderInstrumentationARM; };
template<> struct ObjectToObjectType<ShaderModule> { ObjectType value = ObjectType::ShaderModule; };
template<> struct ObjectToObjectType<SwapchainKHR> { ObjectType value = ObjectType::SwapchainKHR; };
template<> struct ObjectToObjectType<TensorARM> { ObjectType value = ObjectType::TensorARM; };
template<> struct ObjectToObjectType<TensorViewARM> { ObjectType value = ObjectType::TensorViewARM; };
template<> struct ObjectToObjectType<ValidationCacheEXT> { ObjectType value = ObjectType::ValidationCacheEXT; };
template<> struct ObjectToObjectType<VideoSessionKHR> { ObjectType value = ObjectType::VideoSessionKHR; };
template<> struct ObjectToObjectType<VideoSessionParametersKHR> { ObjectType value = ObjectType::VideoSessionParametersKHR; };
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> struct ObjectToObjectType<CudaFunctionNV> { ObjectType value = ObjectType::CudaFunctionNV; };
	template<> struct ObjectToObjectType<CudaModuleNV> { ObjectType value = ObjectType::CudaModuleNV; };
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> struct ObjectToObjectType<BufferCollectionFUCHSIA> { ObjectType value = ObjectType::BufferCollectionFUCHSIA; };
#endif // VK_USE_PLATFORM_FUCHSIA
template<> struct ObjectToObjectType<Device> { ObjectType value = ObjectType::Device; };
template<> struct ObjectToObjectType<DisplayKHR> { ObjectType value = ObjectType::DisplayKHR; };
template<> struct ObjectToObjectType<DebugReportCallbackEXT> { ObjectType value = ObjectType::DebugReportCallbackEXT; };
template<> struct ObjectToObjectType<DebugUtilsMessengerEXT> { ObjectType value = ObjectType::DebugUtilsMessengerEXT; };
template<> struct ObjectToObjectType<PhysicalDevice> { ObjectType value = ObjectType::PhysicalDevice; };
template<> struct ObjectToObjectType<SurfaceKHR> { ObjectType value = ObjectType::SurfaceKHR; };
template<> struct ObjectToObjectType<Instance> { ObjectType value = ObjectType::Instance; };
} // namespace VkBindings::Reflections::Reflections_impl
