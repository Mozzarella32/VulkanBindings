#include "VkBindings/Defines.hpp"
#include "VkBindings/EnumToString.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/Loader.hpp"
#include "VkBindings/private/ObjectTemplatesIntreface.hpp"

// NOLINTBEGIN(misc-include-cleaner)
// Needed for getting implmenetations
#include "VkBindings/private/ObjectTemplates.hpp"

// NOLINTEND(misc-include-cleaner)
#include <cassert>
#include <cstdint>
#include <iostream>
#include <utility>

namespace VkBindings::impl_Objects {

template <>
UniqueWithDispatcher<Instance>::UniqueWithDispatcher(
    object_type &&obj, const AllocationCallbacks *allocationCallbacks)
    : object_type(std::move(obj)), allocationCallbacks(allocationCallbacks),
      dispatcherObj(impl_Loader::LoadInstanceTable(getHandle())) {
    setDispatcher(dispatcherObj);
}


template <>
UniqueWithDispatcher<Device>::UniqueWithDispatcher(
    object_type &&obj, const AllocationCallbacks *allocationCallbacks)
    : object_type(std::move(obj)), allocationCallbacks(allocationCallbacks),
      dispatcherObj(impl_Loader::LoadDeviceTable(getHandle(), getDispatcher())) {
    setDispatcher(dispatcherObj);
}

template<>
void PoolAllocated<CommandBuffer, Handle::Device, Handle::CommandPool>::cleanup() noexcept {
	if (poolHandle == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	dispatcherOwner->deviceTable.freeCommandBuffers(ownerHandle, poolHandle, static_cast<uint32_t>(objectHandles.size()), objectHandles.data());
	objectHandles.clear();
	poolHandle = VK_BINDINGS_NULL_HANDLE;
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	dispatcherOwner = nullptr;
}
template<>
void PoolAllocated<DescriptorSet, Handle::Device, Handle::DescriptorPool>::cleanup() noexcept {
	if (poolHandle == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	dispatcherOwner->deviceTable.freeDescriptorSets(ownerHandle, poolHandle, static_cast<uint32_t>(objectHandles.size()), objectHandles.data());
	objectHandles.clear();
	poolHandle = VK_BINDINGS_NULL_HANDLE;
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	dispatcherOwner = nullptr;
}
template<>
void OwnedUnique<Handle::Device, AccelerationStructureKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyAccelerationStructureKHR(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, AccelerationStructureNV>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyAccelerationStructureNV(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Buffer>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyBuffer(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, BufferView>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyBufferView(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, CommandPool>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyCommandPool(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, CuFunctionNVX>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyCuFunctionNVX(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, CuModuleNVX>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyCuModuleNVX(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, DataGraphPipelineSessionARM>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyDataGraphPipelineSessionARM(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, DeferredOperationKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyDeferredOperationKHR(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, DescriptorPool>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyDescriptorPool(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, DescriptorSetLayout>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyDescriptorSetLayout(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, DescriptorUpdateTemplate>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyDescriptorUpdateTemplate(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, DeviceMemory>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.freeMemory(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Event>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyEvent(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, ExternalComputeQueueNV>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyExternalComputeQueueNV(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Fence>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyFence(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Framebuffer>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyFramebuffer(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, GpaSessionAMD>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyGpaSessionAMD(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Image>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyImage(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, ImageView>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyImageView(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, IndirectCommandsLayoutEXT>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyIndirectCommandsLayoutEXT(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, IndirectCommandsLayoutNV>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyIndirectCommandsLayoutNV(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, IndirectExecutionSetEXT>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyIndirectExecutionSetEXT(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, MicromapEXT>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyMicromapEXT(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, OpticalFlowSessionNV>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyOpticalFlowSessionNV(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, PerformanceConfigurationINTEL>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	if (auto res = ownerDispatcher->deviceTable.releasePerformanceConfigurationINTEL(ownerHandle, getHandle()); res != Result::Success) {
		std::cerr << "VkBindings: releasePerformanceConfigurationINTEL: " << Reflections::enumToString(res) << "\n";
		assert(false && "releasePerformanceConfigurationINTEL");
	}
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Pipeline>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyPipeline(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, PipelineBinaryKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyPipelineBinaryKHR(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, PipelineCache>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyPipelineCache(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, PipelineLayout>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyPipelineLayout(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, PrivateDataSlot>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyPrivateDataSlot(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, QueryPool>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyQueryPool(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, RenderPass>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyRenderPass(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Sampler>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroySampler(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, SamplerYcbcrConversion>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroySamplerYcbcrConversion(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, Semaphore>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroySemaphore(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, ShaderEXT>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyShaderEXT(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, ShaderInstrumentationARM>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyShaderInstrumentationARM(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, ShaderModule>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyShaderModule(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, SwapchainKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroySwapchainKHR(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, TensorARM>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyTensorARM(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, TensorViewARM>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyTensorViewARM(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, ValidationCacheEXT>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyValidationCacheEXT(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, VideoSessionKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyVideoSessionKHR(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Device, VideoSessionParametersKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->deviceTable.destroyVideoSessionParametersKHR(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template<>
	void OwnedUnique<Handle::Device, CudaFunctionNV>::cleanup() noexcept {
		if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
			return;
		}
		ownerDispatcher->deviceTable.destroyCudaFunctionNV(ownerHandle, getHandle(), allocationCallbacks);
		this->allocationCallbacks = nullptr;
		*static_cast<object_type *>(this) = {};
		ownerHandle = VK_BINDINGS_NULL_HANDLE;
		ownerDispatcher = nullptr;
	}
	template<>
	void OwnedUnique<Handle::Device, CudaModuleNV>::cleanup() noexcept {
		if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
			return;
		}
		ownerDispatcher->deviceTable.destroyCudaModuleNV(ownerHandle, getHandle(), allocationCallbacks);
		this->allocationCallbacks = nullptr;
		*static_cast<object_type *>(this) = {};
		ownerHandle = VK_BINDINGS_NULL_HANDLE;
		ownerDispatcher = nullptr;
	}
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template<>
	void OwnedUnique<Handle::Device, BufferCollectionFUCHSIA>::cleanup() noexcept {
		if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
			return;
		}
		ownerDispatcher->deviceTable.destroyBufferCollectionFUCHSIA(ownerHandle, getHandle(), allocationCallbacks);
		this->allocationCallbacks = nullptr;
		*static_cast<object_type *>(this) = {};
		ownerHandle = VK_BINDINGS_NULL_HANDLE;
		ownerDispatcher = nullptr;
	}
#endif // VK_USE_PLATFORM_FUCHSIA
template<>
void UniqueWithDispatcher<Device>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	getDeviceTable().destroyDevice(getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	dispatcherObj = {};
}
template<>
void OwnedUnique<Handle::PhysicalDevice, DisplayKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	if (auto res = ownerDispatcher->instanceTable.releaseDisplayEXT(ownerHandle, getHandle()); res != Result::Success) {
		std::cerr << "VkBindings: releaseDisplayEXT: " << Reflections::enumToString(res) << "\n";
		assert(false && "releaseDisplayEXT");
	}
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Instance, DebugReportCallbackEXT>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->instanceTable.destroyDebugReportCallbackEXT(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Instance, DebugUtilsMessengerEXT>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->instanceTable.destroyDebugUtilsMessengerEXT(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void OwnedUnique<Handle::Instance, SurfaceKHR>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	ownerDispatcher->instanceTable.destroySurfaceKHR(ownerHandle, getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	ownerHandle = VK_BINDINGS_NULL_HANDLE;
	ownerDispatcher = nullptr;
}
template<>
void UniqueWithDispatcher<Instance>::cleanup() noexcept {
	if (getHandle() == VK_BINDINGS_NULL_HANDLE) {
		return;
	}
	getInstanceTable().destroyInstance(getHandle(), allocationCallbacks);
	this->allocationCallbacks = nullptr;
	*static_cast<object_type *>(this) = {};
	dispatcherObj = {};
}
template struct PoolAllocated<CommandBuffer, Handle::Device, Handle::CommandPool>;
template struct PoolAllocated<DescriptorSet, Handle::Device, Handle::DescriptorPool>;
template struct Object<Handle::CommandBuffer>;
template struct ObjectWithoutFunctions<Handle::DescriptorSet>;
template struct ObjectWithoutFunctions<Handle::AccelerationStructureKHR>;
template struct OwnedUnique<Handle::Device, AccelerationStructureKHR>;
template struct ObjectWithoutFunctions<Handle::AccelerationStructureNV>;
template struct OwnedUnique<Handle::Device, AccelerationStructureNV>;
template struct ObjectWithoutFunctions<Handle::Buffer>;
template struct OwnedUnique<Handle::Device, Buffer>;
template struct ObjectWithoutFunctions<Handle::BufferView>;
template struct OwnedUnique<Handle::Device, BufferView>;
template struct ObjectWithoutFunctions<Handle::CommandPool>;
template struct OwnedUnique<Handle::Device, CommandPool>;
template struct ObjectWithoutFunctions<Handle::CuFunctionNVX>;
template struct OwnedUnique<Handle::Device, CuFunctionNVX>;
template struct ObjectWithoutFunctions<Handle::CuModuleNVX>;
template struct OwnedUnique<Handle::Device, CuModuleNVX>;
template struct ObjectWithoutFunctions<Handle::DataGraphPipelineSessionARM>;
template struct OwnedUnique<Handle::Device, DataGraphPipelineSessionARM>;
template struct ObjectWithoutFunctions<Handle::DeferredOperationKHR>;
template struct OwnedUnique<Handle::Device, DeferredOperationKHR>;
template struct ObjectWithoutFunctions<Handle::DescriptorPool>;
template struct OwnedUnique<Handle::Device, DescriptorPool>;
template struct ObjectWithoutFunctions<Handle::DescriptorSetLayout>;
template struct OwnedUnique<Handle::Device, DescriptorSetLayout>;
template struct ObjectWithoutFunctions<Handle::DescriptorUpdateTemplate>;
template struct OwnedUnique<Handle::Device, DescriptorUpdateTemplate>;
template struct ObjectWithoutFunctions<Handle::DeviceMemory>;
template struct OwnedUnique<Handle::Device, DeviceMemory>;
template struct ObjectWithoutFunctions<Handle::DisplayModeKHR>;
template struct ObjectWithoutFunctions<Handle::Event>;
template struct OwnedUnique<Handle::Device, Event>;
template struct Object<Handle::ExternalComputeQueueNV>;
template struct OwnedUnique<Handle::Device, ExternalComputeQueueNV>;
template struct ObjectWithoutFunctions<Handle::Fence>;
template struct OwnedUnique<Handle::Device, Fence>;
template struct ObjectWithoutFunctions<Handle::Framebuffer>;
template struct OwnedUnique<Handle::Device, Framebuffer>;
template struct ObjectWithoutFunctions<Handle::GpaSessionAMD>;
template struct OwnedUnique<Handle::Device, GpaSessionAMD>;
template struct ObjectWithoutFunctions<Handle::Image>;
template struct OwnedUnique<Handle::Device, Image>;
template struct ObjectWithoutFunctions<Handle::ImageView>;
template struct OwnedUnique<Handle::Device, ImageView>;
template struct ObjectWithoutFunctions<Handle::IndirectCommandsLayoutEXT>;
template struct OwnedUnique<Handle::Device, IndirectCommandsLayoutEXT>;
template struct ObjectWithoutFunctions<Handle::IndirectCommandsLayoutNV>;
template struct OwnedUnique<Handle::Device, IndirectCommandsLayoutNV>;
template struct ObjectWithoutFunctions<Handle::IndirectExecutionSetEXT>;
template struct OwnedUnique<Handle::Device, IndirectExecutionSetEXT>;
template struct ObjectWithoutFunctions<Handle::MicromapEXT>;
template struct OwnedUnique<Handle::Device, MicromapEXT>;
template struct ObjectWithoutFunctions<Handle::OpticalFlowSessionNV>;
template struct OwnedUnique<Handle::Device, OpticalFlowSessionNV>;
template struct ObjectWithoutFunctions<Handle::PerformanceConfigurationINTEL>;
template struct OwnedUnique<Handle::Device, PerformanceConfigurationINTEL>;
template struct ObjectWithoutFunctions<Handle::Pipeline>;
template struct OwnedUnique<Handle::Device, Pipeline>;
template struct ObjectWithoutFunctions<Handle::PipelineBinaryKHR>;
template struct OwnedUnique<Handle::Device, PipelineBinaryKHR>;
template struct ObjectWithoutFunctions<Handle::PipelineCache>;
template struct OwnedUnique<Handle::Device, PipelineCache>;
template struct ObjectWithoutFunctions<Handle::PipelineLayout>;
template struct OwnedUnique<Handle::Device, PipelineLayout>;
template struct ObjectWithoutFunctions<Handle::PrivateDataSlot>;
template struct OwnedUnique<Handle::Device, PrivateDataSlot>;
template struct ObjectWithoutFunctions<Handle::QueryPool>;
template struct OwnedUnique<Handle::Device, QueryPool>;
template struct Object<Handle::Queue>;
template struct ObjectWithoutFunctions<Handle::RenderPass>;
template struct OwnedUnique<Handle::Device, RenderPass>;
template struct ObjectWithoutFunctions<Handle::Sampler>;
template struct OwnedUnique<Handle::Device, Sampler>;
template struct ObjectWithoutFunctions<Handle::SamplerYcbcrConversion>;
template struct OwnedUnique<Handle::Device, SamplerYcbcrConversion>;
template struct ObjectWithoutFunctions<Handle::Semaphore>;
template struct OwnedUnique<Handle::Device, Semaphore>;
template struct ObjectWithoutFunctions<Handle::ShaderEXT>;
template struct OwnedUnique<Handle::Device, ShaderEXT>;
template struct ObjectWithoutFunctions<Handle::ShaderInstrumentationARM>;
template struct OwnedUnique<Handle::Device, ShaderInstrumentationARM>;
template struct ObjectWithoutFunctions<Handle::ShaderModule>;
template struct OwnedUnique<Handle::Device, ShaderModule>;
template struct ObjectWithoutFunctions<Handle::SwapchainKHR>;
template struct OwnedUnique<Handle::Device, SwapchainKHR>;
template struct ObjectWithoutFunctions<Handle::TensorARM>;
template struct OwnedUnique<Handle::Device, TensorARM>;
template struct ObjectWithoutFunctions<Handle::TensorViewARM>;
template struct OwnedUnique<Handle::Device, TensorViewARM>;
template struct ObjectWithoutFunctions<Handle::ValidationCacheEXT>;
template struct OwnedUnique<Handle::Device, ValidationCacheEXT>;
template struct ObjectWithoutFunctions<Handle::VideoSessionKHR>;
template struct OwnedUnique<Handle::Device, VideoSessionKHR>;
template struct ObjectWithoutFunctions<Handle::VideoSessionParametersKHR>;
template struct OwnedUnique<Handle::Device, VideoSessionParametersKHR>;
#ifdef VK_ENABLE_BETA_EXTENSIONS
	template struct ObjectWithoutFunctions<Handle::CudaFunctionNV>;
	template struct OwnedUnique<Handle::Device, CudaFunctionNV>;
	template struct ObjectWithoutFunctions<Handle::CudaModuleNV>;
	template struct OwnedUnique<Handle::Device, CudaModuleNV>;
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	template struct ObjectWithoutFunctions<Handle::BufferCollectionFUCHSIA>;
	template struct OwnedUnique<Handle::Device, BufferCollectionFUCHSIA>;
#endif // VK_USE_PLATFORM_FUCHSIA
template struct Object<Handle::Device>;
template struct UniqueWithDispatcher<Device>;
template struct ObjectWithoutFunctions<Handle::DisplayKHR>;
template struct OwnedUnique<Handle::PhysicalDevice, DisplayKHR>;
template struct ObjectWithoutFunctions<Handle::DebugReportCallbackEXT>;
template struct OwnedUnique<Handle::Instance, DebugReportCallbackEXT>;
template struct ObjectWithoutFunctions<Handle::DebugUtilsMessengerEXT>;
template struct OwnedUnique<Handle::Instance, DebugUtilsMessengerEXT>;
template struct Object<Handle::PhysicalDevice>;
template struct ObjectWithoutFunctions<Handle::SurfaceKHR>;
template struct OwnedUnique<Handle::Instance, SurfaceKHR>;
template struct Object<Handle::Instance>;
template struct UniqueWithDispatcher<Instance>;
} // namespace VkBindings::impl_Objects
