#pragma once

#include "VkBindings/Handles.hpp"
#include "VkBindings/ObjectsForward.hpp"

namespace VkBindings::Reflections {
namespace Reflections_impl {
template <typename T> struct HandleToObject;
} // namespace Reflections_impl

template <typename T> using HandleToObject = Reflections_impl::HandleToObject<T>::t;

namespace Reflections_impl {
template<> struct HandleToObject<Handle::CommandBuffer> { using t = CommandBuffer; };
template<> struct HandleToObject<Handle::DescriptorSet> { using t = DescriptorSet; };
template<> struct HandleToObject<Handle::AccelerationStructureKHR> { using t = AccelerationStructureKHR; };
template<> struct HandleToObject<Handle::AccelerationStructureNV> { using t = AccelerationStructureNV; };
template<> struct HandleToObject<Handle::Buffer> { using t = Buffer; };
template<> struct HandleToObject<Handle::BufferView> { using t = BufferView; };
template<> struct HandleToObject<Handle::CommandPool> { using t = CommandPool; };
template<> struct HandleToObject<Handle::CuFunctionNVX> { using t = CuFunctionNVX; };
template<> struct HandleToObject<Handle::CuModuleNVX> { using t = CuModuleNVX; };
template<> struct HandleToObject<Handle::DataGraphPipelineSessionARM> { using t = DataGraphPipelineSessionARM; };
template<> struct HandleToObject<Handle::DeferredOperationKHR> { using t = DeferredOperationKHR; };
template<> struct HandleToObject<Handle::DescriptorPool> { using t = DescriptorPool; };
template<> struct HandleToObject<Handle::DescriptorSetLayout> { using t = DescriptorSetLayout; };
template<> struct HandleToObject<Handle::DescriptorUpdateTemplate> { using t = DescriptorUpdateTemplate; };
template<> struct HandleToObject<Handle::DeviceMemory> { using t = DeviceMemory; };
template<> struct HandleToObject<Handle::DisplayModeKHR> { using t = DisplayModeKHR; };
template<> struct HandleToObject<Handle::Event> { using t = Event; };
template<> struct HandleToObject<Handle::ExternalComputeQueueNV> { using t = ExternalComputeQueueNV; };
template<> struct HandleToObject<Handle::Fence> { using t = Fence; };
template<> struct HandleToObject<Handle::Framebuffer> { using t = Framebuffer; };
template<> struct HandleToObject<Handle::GpaSessionAMD> { using t = GpaSessionAMD; };
template<> struct HandleToObject<Handle::Image> { using t = Image; };
template<> struct HandleToObject<Handle::ImageView> { using t = ImageView; };
template<> struct HandleToObject<Handle::IndirectCommandsLayoutEXT> { using t = IndirectCommandsLayoutEXT; };
template<> struct HandleToObject<Handle::IndirectCommandsLayoutNV> { using t = IndirectCommandsLayoutNV; };
template<> struct HandleToObject<Handle::IndirectExecutionSetEXT> { using t = IndirectExecutionSetEXT; };
template<> struct HandleToObject<Handle::MicromapEXT> { using t = MicromapEXT; };
template<> struct HandleToObject<Handle::OpticalFlowSessionNV> { using t = OpticalFlowSessionNV; };
template<> struct HandleToObject<Handle::PerformanceConfigurationINTEL> { using t = PerformanceConfigurationINTEL; };
template<> struct HandleToObject<Handle::Pipeline> { using t = Pipeline; };
template<> struct HandleToObject<Handle::PipelineBinaryKHR> { using t = PipelineBinaryKHR; };
template<> struct HandleToObject<Handle::PipelineCache> { using t = PipelineCache; };
template<> struct HandleToObject<Handle::PipelineLayout> { using t = PipelineLayout; };
template<> struct HandleToObject<Handle::PrivateDataSlot> { using t = PrivateDataSlot; };
template<> struct HandleToObject<Handle::QueryPool> { using t = QueryPool; };
template<> struct HandleToObject<Handle::Queue> { using t = Queue; };
template<> struct HandleToObject<Handle::RenderPass> { using t = RenderPass; };
template<> struct HandleToObject<Handle::Sampler> { using t = Sampler; };
template<> struct HandleToObject<Handle::SamplerYcbcrConversion> { using t = SamplerYcbcrConversion; };
template<> struct HandleToObject<Handle::Semaphore> { using t = Semaphore; };
template<> struct HandleToObject<Handle::ShaderEXT> { using t = ShaderEXT; };
template<> struct HandleToObject<Handle::ShaderInstrumentationARM> { using t = ShaderInstrumentationARM; };
template<> struct HandleToObject<Handle::ShaderModule> { using t = ShaderModule; };
template<> struct HandleToObject<Handle::SwapchainKHR> { using t = SwapchainKHR; };
template<> struct HandleToObject<Handle::TensorARM> { using t = TensorARM; };
template<> struct HandleToObject<Handle::TensorViewARM> { using t = TensorViewARM; };
template<> struct HandleToObject<Handle::ValidationCacheEXT> { using t = ValidationCacheEXT; };
template<> struct HandleToObject<Handle::VideoSessionKHR> { using t = VideoSessionKHR; };
template<> struct HandleToObject<Handle::VideoSessionParametersKHR> { using t = VideoSessionParametersKHR; };
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> struct HandleToObject<Handle::CudaFunctionNV> { using t = CudaFunctionNV; };
	template<> struct HandleToObject<Handle::CudaModuleNV> { using t = CudaModuleNV; };
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> struct HandleToObject<Handle::BufferCollectionFUCHSIA> { using t = BufferCollectionFUCHSIA; };
#endif // VK_USE_PLATFORM_FUCHSIA
template<> struct HandleToObject<Handle::Device> { using t = Device; };
template<> struct HandleToObject<Handle::DisplayKHR> { using t = DisplayKHR; };
template<> struct HandleToObject<Handle::DebugReportCallbackEXT> { using t = DebugReportCallbackEXT; };
template<> struct HandleToObject<Handle::DebugUtilsMessengerEXT> { using t = DebugUtilsMessengerEXT; };
template<> struct HandleToObject<Handle::PhysicalDevice> { using t = PhysicalDevice; };
template<> struct HandleToObject<Handle::SurfaceKHR> { using t = SurfaceKHR; };
template<> struct HandleToObject<Handle::Instance> { using t = Instance; };
} // namespace Reflections_impl
} // namespace VkBindings::Reflections
