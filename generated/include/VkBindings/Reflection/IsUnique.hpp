#pragma once

#include "VkBindings/ObjectsForward.hpp"

#include <type_traits>

namespace VkBindings::Reflections {
namespace Reflections_impl {
template <typename T> struct IsUnique : std::false_type {};
} // namespace Reflections_impl

template <typename T> constexpr bool IsUnique = Reflections_impl::IsUnique<T>::value;
} // namespace VkBindings::Reflections

namespace VkBindings::Concepts {
template <typename T> concept IsUnique = Reflections::IsUnique<T>;
} // namespace VkBindings::Concepts

namespace VkBindings::Reflections::Reflections_impl {
template<> struct IsUnique<UniqueAccelerationStructureKHR> : std::true_type{};
template<> struct IsUnique<UniqueAccelerationStructureNV> : std::true_type{};
template<> struct IsUnique<UniqueBuffer> : std::true_type{};
template<> struct IsUnique<UniqueBufferView> : std::true_type{};
template<> struct IsUnique<UniqueCommandPool> : std::true_type{};
template<> struct IsUnique<UniqueCuFunctionNVX> : std::true_type{};
template<> struct IsUnique<UniqueCuModuleNVX> : std::true_type{};
template<> struct IsUnique<UniqueDataGraphPipelineSessionARM> : std::true_type{};
template<> struct IsUnique<UniqueDeferredOperationKHR> : std::true_type{};
template<> struct IsUnique<UniqueDescriptorPool> : std::true_type{};
template<> struct IsUnique<UniqueDescriptorSetLayout> : std::true_type{};
template<> struct IsUnique<UniqueDescriptorUpdateTemplate> : std::true_type{};
template<> struct IsUnique<UniqueDeviceMemory> : std::true_type{};
template<> struct IsUnique<UniqueEvent> : std::true_type{};
template<> struct IsUnique<UniqueExternalComputeQueueNV> : std::true_type{};
template<> struct IsUnique<UniqueFence> : std::true_type{};
template<> struct IsUnique<UniqueFramebuffer> : std::true_type{};
template<> struct IsUnique<UniqueGpaSessionAMD> : std::true_type{};
template<> struct IsUnique<UniqueImage> : std::true_type{};
template<> struct IsUnique<UniqueImageView> : std::true_type{};
template<> struct IsUnique<UniqueIndirectCommandsLayoutEXT> : std::true_type{};
template<> struct IsUnique<UniqueIndirectCommandsLayoutNV> : std::true_type{};
template<> struct IsUnique<UniqueIndirectExecutionSetEXT> : std::true_type{};
template<> struct IsUnique<UniqueMicromapEXT> : std::true_type{};
template<> struct IsUnique<UniqueOpticalFlowSessionNV> : std::true_type{};
template<> struct IsUnique<UniquePerformanceConfigurationINTEL> : std::true_type{};
template<> struct IsUnique<UniquePipeline> : std::true_type{};
template<> struct IsUnique<UniquePipelineBinaryKHR> : std::true_type{};
template<> struct IsUnique<UniquePipelineCache> : std::true_type{};
template<> struct IsUnique<UniquePipelineLayout> : std::true_type{};
template<> struct IsUnique<UniquePrivateDataSlot> : std::true_type{};
template<> struct IsUnique<UniqueQueryPool> : std::true_type{};
template<> struct IsUnique<UniqueRenderPass> : std::true_type{};
template<> struct IsUnique<UniqueSampler> : std::true_type{};
template<> struct IsUnique<UniqueSamplerYcbcrConversion> : std::true_type{};
template<> struct IsUnique<UniqueSemaphore> : std::true_type{};
template<> struct IsUnique<UniqueShaderEXT> : std::true_type{};
template<> struct IsUnique<UniqueShaderInstrumentationARM> : std::true_type{};
template<> struct IsUnique<UniqueShaderModule> : std::true_type{};
template<> struct IsUnique<UniqueSwapchainKHR> : std::true_type{};
template<> struct IsUnique<UniqueTensorARM> : std::true_type{};
template<> struct IsUnique<UniqueTensorViewARM> : std::true_type{};
template<> struct IsUnique<UniqueValidationCacheEXT> : std::true_type{};
template<> struct IsUnique<UniqueVideoSessionKHR> : std::true_type{};
template<> struct IsUnique<UniqueVideoSessionParametersKHR> : std::true_type{};
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<> struct IsUnique<UniqueCudaFunctionNV> : std::true_type{};
	template<> struct IsUnique<UniqueCudaModuleNV> : std::true_type{};
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<> struct IsUnique<UniqueBufferCollectionFUCHSIA> : std::true_type{};
#endif // VK_USE_PLATFORM_FUCHSIA
template<> struct IsUnique<UniqueDevice> : std::true_type{};
template<> struct IsUnique<UniqueDisplayKHR> : std::true_type{};
template<> struct IsUnique<UniqueDebugReportCallbackEXT> : std::true_type{};
template<> struct IsUnique<UniqueDebugUtilsMessengerEXT> : std::true_type{};
template<> struct IsUnique<UniqueSurfaceKHR> : std::true_type{};
template<> struct IsUnique<UniqueInstance> : std::true_type{};
} // namespace VkBindings::Reflections::Reflections_impl
