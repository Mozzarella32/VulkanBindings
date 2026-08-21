#pragma once

#include "VkBindings/Handles.hpp"
#include "VkBindings/ObjectsForward.hpp"

namespace VkBindings::Reflections {
namespace Reflections_impl {
template <typename T> struct ObjectToHandle;
} // namespace Reflections_impl

template <typename T> using ObjectToHandle = Reflections_impl::ObjectToHandle<T>::t;

namespace Reflections_impl {
template<> struct ObjectToHandle<CommandBuffer> { using t = Handle::CommandBuffer; };
template<> struct ObjectToHandle<DescriptorSet> { using t = Handle::DescriptorSet; };
template<> struct ObjectToHandle<AccelerationStructureKHR> { using t = Handle::AccelerationStructureKHR; };
template<> struct ObjectToHandle<AccelerationStructureNV> { using t = Handle::AccelerationStructureNV; };
template<> struct ObjectToHandle<Buffer> { using t = Handle::Buffer; };
template<> struct ObjectToHandle<BufferView> { using t = Handle::BufferView; };
template<> struct ObjectToHandle<CommandPool> { using t = Handle::CommandPool; };
template<> struct ObjectToHandle<CuFunctionNVX> { using t = Handle::CuFunctionNVX; };
template<> struct ObjectToHandle<CuModuleNVX> { using t = Handle::CuModuleNVX; };
template<> struct ObjectToHandle<DataGraphPipelineSessionARM> { using t = Handle::DataGraphPipelineSessionARM; };
template<> struct ObjectToHandle<DeferredOperationKHR> { using t = Handle::DeferredOperationKHR; };
template<> struct ObjectToHandle<DescriptorPool> { using t = Handle::DescriptorPool; };
template<> struct ObjectToHandle<DescriptorSetLayout> { using t = Handle::DescriptorSetLayout; };
template<> struct ObjectToHandle<DescriptorUpdateTemplate> { using t = Handle::DescriptorUpdateTemplate; };
template<> struct ObjectToHandle<DeviceMemory> { using t = Handle::DeviceMemory; };
template<> struct ObjectToHandle<DisplayModeKHR> { using t = Handle::DisplayModeKHR; };
template<> struct ObjectToHandle<Event> { using t = Handle::Event; };
template<> struct ObjectToHandle<ExternalComputeQueueNV> { using t = Handle::ExternalComputeQueueNV; };
template<> struct ObjectToHandle<Fence> { using t = Handle::Fence; };
template<> struct ObjectToHandle<Framebuffer> { using t = Handle::Framebuffer; };
template<> struct ObjectToHandle<GpaSessionAMD> { using t = Handle::GpaSessionAMD; };
template<> struct ObjectToHandle<Image> { using t = Handle::Image; };
template<> struct ObjectToHandle<ImageView> { using t = Handle::ImageView; };
template<> struct ObjectToHandle<IndirectCommandsLayoutEXT> { using t = Handle::IndirectCommandsLayoutEXT; };
template<> struct ObjectToHandle<IndirectCommandsLayoutNV> { using t = Handle::IndirectCommandsLayoutNV; };
template<> struct ObjectToHandle<IndirectExecutionSetEXT> { using t = Handle::IndirectExecutionSetEXT; };
template<> struct ObjectToHandle<MicromapEXT> { using t = Handle::MicromapEXT; };
template<> struct ObjectToHandle<OpticalFlowSessionNV> { using t = Handle::OpticalFlowSessionNV; };
template<> struct ObjectToHandle<PerformanceConfigurationINTEL> { using t = Handle::PerformanceConfigurationINTEL; };
template<> struct ObjectToHandle<Pipeline> { using t = Handle::Pipeline; };
template<> struct ObjectToHandle<PipelineBinaryKHR> { using t = Handle::PipelineBinaryKHR; };
template<> struct ObjectToHandle<PipelineCache> { using t = Handle::PipelineCache; };
template<> struct ObjectToHandle<PipelineLayout> { using t = Handle::PipelineLayout; };
template<> struct ObjectToHandle<PrivateDataSlot> { using t = Handle::PrivateDataSlot; };
template<> struct ObjectToHandle<QueryPool> { using t = Handle::QueryPool; };
template<> struct ObjectToHandle<Queue> { using t = Handle::Queue; };
template<> struct ObjectToHandle<RenderPass> { using t = Handle::RenderPass; };
template<> struct ObjectToHandle<Sampler> { using t = Handle::Sampler; };
template<> struct ObjectToHandle<SamplerYcbcrConversion> { using t = Handle::SamplerYcbcrConversion; };
template<> struct ObjectToHandle<Semaphore> { using t = Handle::Semaphore; };
template<> struct ObjectToHandle<ShaderEXT> { using t = Handle::ShaderEXT; };
template<> struct ObjectToHandle<ShaderInstrumentationARM> { using t = Handle::ShaderInstrumentationARM; };
template<> struct ObjectToHandle<ShaderModule> { using t = Handle::ShaderModule; };
template<> struct ObjectToHandle<SwapchainKHR> { using t = Handle::SwapchainKHR; };
template<> struct ObjectToHandle<TensorARM> { using t = Handle::TensorARM; };
template<> struct ObjectToHandle<TensorViewARM> { using t = Handle::TensorViewARM; };
template<> struct ObjectToHandle<ValidationCacheEXT> { using t = Handle::ValidationCacheEXT; };
template<> struct ObjectToHandle<VideoSessionKHR> { using t = Handle::VideoSessionKHR; };
template<> struct ObjectToHandle<VideoSessionParametersKHR> { using t = Handle::VideoSessionParametersKHR; };
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> struct ObjectToHandle<CudaFunctionNV> { using t = Handle::CudaFunctionNV; };
	template<> struct ObjectToHandle<CudaModuleNV> { using t = Handle::CudaModuleNV; };
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> struct ObjectToHandle<BufferCollectionFUCHSIA> { using t = Handle::BufferCollectionFUCHSIA; };
#endif // VK_USE_PLATFORM_FUCHSIA
template<> struct ObjectToHandle<Device> { using t = Handle::Device; };
template<> struct ObjectToHandle<DisplayKHR> { using t = Handle::DisplayKHR; };
template<> struct ObjectToHandle<DebugReportCallbackEXT> { using t = Handle::DebugReportCallbackEXT; };
template<> struct ObjectToHandle<DebugUtilsMessengerEXT> { using t = Handle::DebugUtilsMessengerEXT; };
template<> struct ObjectToHandle<PhysicalDevice> { using t = Handle::PhysicalDevice; };
template<> struct ObjectToHandle<SurfaceKHR> { using t = Handle::SurfaceKHR; };
template<> struct ObjectToHandle<Instance> { using t = Handle::Instance; };
} // namespace Reflections_impl
} // namespace VkBindings::Reflections
