#include "VkBindings/Enums.hpp"
#include "VkBindings/FlagsToString.hpp"

#include <array>
#include <cstddef>
#include <ranges>
#include <span>
#include <string>
#include <string_view>

namespace VkBindings::Reflections {
// NOLINTBEGIN(readability-function-cognitive-complexity, cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
template<> auto flagsToString(AccelerationStructureCreateFlagsKHR flags) -> std::string {
	using enum AccelerationStructureCreateBitsKHR;
	if ((flags & AllBits) != flags) {
		return "AccelerationStructureCreateBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & DeviceAddressCaptureReplay) {
		value_data.at(value_size++) = "DeviceAddressCaptureReplay";
	}
	if (flags & MotionBitNV) {
		value_data.at(value_size++) = "MotionBitNV";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferCaptureReplayBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(AccelerationStructureMotionInfoFlagsNV flags) -> std::string {
	if (flags) {
		return "AccelerationStructureMotionInfoFlagsNV has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(AccelerationStructureMotionInstanceFlagsNV flags) -> std::string {
	if (flags) {
		return "AccelerationStructureMotionInstanceFlagsNV has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(AccessFlags flags) -> std::string {
	using enum AccessBits;
	if ((flags & AllBits) != flags) {
		return "AccessBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 30> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & IndirectCommandRead) {
		value_data.at(value_size++) = "IndirectCommandRead";
	}
	if (flags & IndexRead) {
		value_data.at(value_size++) = "IndexRead";
	}
	if (flags & VertexAttributeRead) {
		value_data.at(value_size++) = "VertexAttributeRead";
	}
	if (flags & UniformRead) {
		value_data.at(value_size++) = "UniformRead";
	}
	if (flags & InputAttachmentRead) {
		value_data.at(value_size++) = "InputAttachmentRead";
	}
	if (flags & ShaderRead) {
		value_data.at(value_size++) = "ShaderRead";
	}
	if (flags & ShaderWrite) {
		value_data.at(value_size++) = "ShaderWrite";
	}
	if (flags & ColorAttachmentRead) {
		value_data.at(value_size++) = "ColorAttachmentRead";
	}
	if (flags & ColorAttachmentWrite) {
		value_data.at(value_size++) = "ColorAttachmentWrite";
	}
	if (flags & DepthStencilAttachmentRead) {
		value_data.at(value_size++) = "DepthStencilAttachmentRead";
	}
	if (flags & DepthStencilAttachmentWrite) {
		value_data.at(value_size++) = "DepthStencilAttachmentWrite";
	}
	if (flags & TransferRead) {
		value_data.at(value_size++) = "TransferRead";
	}
	if (flags & TransferWrite) {
		value_data.at(value_size++) = "TransferWrite";
	}
	if (flags & HostRead) {
		value_data.at(value_size++) = "HostRead";
	}
	if (flags & HostWrite) {
		value_data.at(value_size++) = "HostWrite";
	}
	if (flags & MemoryRead) {
		value_data.at(value_size++) = "MemoryRead";
	}
	if (flags & MemoryWrite) {
		value_data.at(value_size++) = "MemoryWrite";
	}
	if (flags & CommandPreprocessReadBitEXT) {
		value_data.at(value_size++) = "CommandPreprocessReadBitEXT";
	}
	if (flags & CommandPreprocessWriteBitEXT) {
		value_data.at(value_size++) = "CommandPreprocessWriteBitEXT";
	}
	if (flags & ColorAttachmentReadNoncoherentBitEXT) {
		value_data.at(value_size++) = "ColorAttachmentReadNoncoherentBitEXT";
	}
	if (flags & ConditionalRenderingReadBitEXT) {
		value_data.at(value_size++) = "ConditionalRenderingReadBitEXT";
	}
	if (flags & AccelerationStructureReadBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureReadBitKHR";
	}
	if (flags & AccelerationStructureWriteBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureWriteBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentReadBitKHR) {
		value_data.at(value_size++) = "FragmentShadingRateAttachmentReadBitKHR";
	}
	if (flags & FragmentDensityMapReadBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapReadBitEXT";
	}
	if (flags & TransformFeedbackWriteBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackWriteBitEXT";
	}
	if (flags & TransformFeedbackCounterReadBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackCounterReadBitEXT";
	}
	if (flags & TransformFeedbackCounterWriteBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackCounterWriteBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(AccessFlags2 flags) -> std::string {
	using enum AccessBits2;
	if ((flags & AllBits) != flags) {
		return "AccessBits2 does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 52> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & IndirectCommandRead) {
		value_data.at(value_size++) = "IndirectCommandRead";
	}
	if (flags & IndexRead) {
		value_data.at(value_size++) = "IndexRead";
	}
	if (flags & VertexAttributeRead) {
		value_data.at(value_size++) = "VertexAttributeRead";
	}
	if (flags & UniformRead) {
		value_data.at(value_size++) = "UniformRead";
	}
	if (flags & InputAttachmentRead) {
		value_data.at(value_size++) = "InputAttachmentRead";
	}
	if (flags & ShaderRead) {
		value_data.at(value_size++) = "ShaderRead";
	}
	if (flags & ShaderWrite) {
		value_data.at(value_size++) = "ShaderWrite";
	}
	if (flags & ColorAttachmentRead) {
		value_data.at(value_size++) = "ColorAttachmentRead";
	}
	if (flags & ColorAttachmentWrite) {
		value_data.at(value_size++) = "ColorAttachmentWrite";
	}
	if (flags & DepthStencilAttachmentRead) {
		value_data.at(value_size++) = "DepthStencilAttachmentRead";
	}
	if (flags & DepthStencilAttachmentWrite) {
		value_data.at(value_size++) = "DepthStencilAttachmentWrite";
	}
	if (flags & TransferRead) {
		value_data.at(value_size++) = "TransferRead";
	}
	if (flags & TransferWrite) {
		value_data.at(value_size++) = "TransferWrite";
	}
	if (flags & HostRead) {
		value_data.at(value_size++) = "HostRead";
	}
	if (flags & HostWrite) {
		value_data.at(value_size++) = "HostWrite";
	}
	if (flags & MemoryRead) {
		value_data.at(value_size++) = "MemoryRead";
	}
	if (flags & MemoryWrite) {
		value_data.at(value_size++) = "MemoryWrite";
	}
	if (flags & CommandPreprocessReadBitEXT) {
		value_data.at(value_size++) = "CommandPreprocessReadBitEXT";
	}
	if (flags & CommandPreprocessWriteBitEXT) {
		value_data.at(value_size++) = "CommandPreprocessWriteBitEXT";
	}
	if (flags & ColorAttachmentReadNoncoherentBitEXT) {
		value_data.at(value_size++) = "ColorAttachmentReadNoncoherentBitEXT";
	}
	if (flags & ConditionalRenderingReadBitEXT) {
		value_data.at(value_size++) = "ConditionalRenderingReadBitEXT";
	}
	if (flags & AccelerationStructureReadBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureReadBitKHR";
	}
	if (flags & AccelerationStructureWriteBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureWriteBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentReadBitKHR) {
		value_data.at(value_size++) = "FragmentShadingRateAttachmentReadBitKHR";
	}
	if (flags & FragmentDensityMapReadBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapReadBitEXT";
	}
	if (flags & TransformFeedbackWriteBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackWriteBitEXT";
	}
	if (flags & TransformFeedbackCounterReadBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackCounterReadBitEXT";
	}
	if (flags & TransformFeedbackCounterWriteBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackCounterWriteBitEXT";
	}
	if (flags & ShaderSampledRead) {
		value_data.at(value_size++) = "ShaderSampledRead";
	}
	if (flags & ShaderStorageRead) {
		value_data.at(value_size++) = "ShaderStorageRead";
	}
	if (flags & ShaderStorageWrite) {
		value_data.at(value_size++) = "ShaderStorageWrite";
	}
	if (flags & VideoDecodeReadBitKHR) {
		value_data.at(value_size++) = "VideoDecodeReadBitKHR";
	}
	if (flags & VideoDecodeWriteBitKHR) {
		value_data.at(value_size++) = "VideoDecodeWriteBitKHR";
	}
	if (flags & VideoEncodeReadBitKHR) {
		value_data.at(value_size++) = "VideoEncodeReadBitKHR";
	}
	if (flags & VideoEncodeWriteBitKHR) {
		value_data.at(value_size++) = "VideoEncodeWriteBitKHR";
	}
	if (flags & InvocationMaskReadBitHUAWEI) {
		value_data.at(value_size++) = "InvocationMaskReadBitHUAWEI";
	}
	if (flags & ShaderBindingTableReadBitKHR) {
		value_data.at(value_size++) = "ShaderBindingTableReadBitKHR";
	}
	if (flags & DescriptorBufferReadBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferReadBitEXT";
	}
	if (flags & OpticalFlowReadBitNV) {
		value_data.at(value_size++) = "OpticalFlowReadBitNV";
	}
	if (flags & OpticalFlowWriteBitNV) {
		value_data.at(value_size++) = "OpticalFlowWriteBitNV";
	}
	if (flags & MicromapReadBitEXT) {
		value_data.at(value_size++) = "MicromapReadBitEXT";
	}
	if (flags & MicromapWriteBitEXT) {
		value_data.at(value_size++) = "MicromapWriteBitEXT";
	}
	if (flags & DataGraphReadBitARM) {
		value_data.at(value_size++) = "DataGraphReadBitARM";
	}
	if (flags & DataGraphWriteBitARM) {
		value_data.at(value_size++) = "DataGraphWriteBitARM";
	}
	if (flags & ShaderTileAttachmentReadBitQCOM) {
		value_data.at(value_size++) = "ShaderTileAttachmentReadBitQCOM";
	}
	if (flags & ShaderTileAttachmentWriteBitQCOM) {
		value_data.at(value_size++) = "ShaderTileAttachmentWriteBitQCOM";
	}
	if (flags & MemoryDecompressionReadBitEXT) {
		value_data.at(value_size++) = "MemoryDecompressionReadBitEXT";
	}
	if (flags & MemoryDecompressionWriteBitEXT) {
		value_data.at(value_size++) = "MemoryDecompressionWriteBitEXT";
	}
	if (flags & SamplerHeapReadBitEXT) {
		value_data.at(value_size++) = "SamplerHeapReadBitEXT";
	}
	if (flags & ResourceHeapReadBitEXT) {
		value_data.at(value_size++) = "ResourceHeapReadBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(AccessFlags3KHR flags) -> std::string {
	using enum AccessBits3KHR;
	size_t value_size = 0;
	std::array<std::string_view, 1> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(AcquireProfilingLockFlagsKHR flags) -> std::string {
	if (flags) {
		return "AcquireProfilingLockFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(AddressCommandFlagsKHR flags) -> std::string {
	using enum AddressCommandBitsKHR;
	if ((flags & AllBits) != flags) {
		return "AddressCommandBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & FullyBound) {
		value_data.at(value_size++) = "FullyBound";
	}
	if (flags & StorageBufferUsage) {
		value_data.at(value_size++) = "StorageBufferUsage";
	}
	if (flags & UnknownStorageBufferUsage) {
		value_data.at(value_size++) = "UnknownStorageBufferUsage";
	}
	if (flags & TransformFeedbackBufferUsage) {
		value_data.at(value_size++) = "TransformFeedbackBufferUsage";
	}
	if (flags & UnknownTransformFeedbackBufferUsage) {
		value_data.at(value_size++) = "UnknownTransformFeedbackBufferUsage";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(AddressCopyFlagsKHR flags) -> std::string {
	using enum AddressCopyBitsKHR;
	if ((flags & AllBits) != flags) {
		return "AddressCopyBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & DeviceLocal) {
		value_data.at(value_size++) = "DeviceLocal";
	}
	if (flags & Sparse) {
		value_data.at(value_size++) = "Sparse";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(AndroidSurfaceCreateFlagsKHR flags) -> std::string {
	if (flags) {
		return "AndroidSurfaceCreateFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(AttachmentDescriptionFlags flags) -> std::string {
	using enum AttachmentDescriptionBits;
	if ((flags & AllBits) != flags) {
		return "AttachmentDescriptionBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & MayAlias) {
		value_data.at(value_size++) = "MayAlias";
	}
	if (flags & ResolveSkipTransferFunctionBitKHR) {
		value_data.at(value_size++) = "ResolveSkipTransferFunctionBitKHR";
	}
	if (flags & ResolveEnableTransferFunctionBitKHR) {
		value_data.at(value_size++) = "ResolveEnableTransferFunctionBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(BufferCreateFlags flags) -> std::string {
	using enum BufferCreateBits;
	if ((flags & AllBits) != flags) {
		return "BufferCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 8> value_data;
	if (flags & SparseBinding) {
		value_data.at(value_size++) = "SparseBinding";
	}
	if (flags & SparseResidency) {
		value_data.at(value_size++) = "SparseResidency";
	}
	if (flags & SparseAliased) {
		value_data.at(value_size++) = "SparseAliased";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & DeviceAddressCaptureReplay) {
		value_data.at(value_size++) = "DeviceAddressCaptureReplay";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferCaptureReplayBitEXT";
	}
	if (flags & VideoProfileIndependentBitKHR) {
		value_data.at(value_size++) = "VideoProfileIndependentBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(BufferUsageFlags flags) -> std::string {
	using enum BufferUsageBits;
	if ((flags & AllBits) != flags) {
		return "BufferUsageBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 29> value_data;
	if (flags & TransferSrc) {
		value_data.at(value_size++) = "TransferSrc";
	}
	if (flags & TransferDst) {
		value_data.at(value_size++) = "TransferDst";
	}
	if (flags & UniformTexelBuffer) {
		value_data.at(value_size++) = "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		value_data.at(value_size++) = "StorageTexelBuffer";
	}
	if (flags & UniformBuffer) {
		value_data.at(value_size++) = "UniformBuffer";
	}
	if (flags & StorageBuffer) {
		value_data.at(value_size++) = "StorageBuffer";
	}
	if (flags & IndexBuffer) {
		value_data.at(value_size++) = "IndexBuffer";
	}
	if (flags & VertexBuffer) {
		value_data.at(value_size++) = "VertexBuffer";
	}
	if (flags & IndirectBuffer) {
		value_data.at(value_size++) = "IndirectBuffer";
	}
	if (flags & ConditionalRenderingBitEXT) {
		value_data.at(value_size++) = "ConditionalRenderingBitEXT";
	}
	if (flags & ShaderBindingTableBitKHR) {
		value_data.at(value_size++) = "ShaderBindingTableBitKHR";
	}
	if (flags & TransformFeedbackBufferBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackBufferBitEXT";
	}
	if (flags & TransformFeedbackCounterBufferBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackCounterBufferBitEXT";
	}
	if (flags & VideoDecodeSrcBitKHR) {
		value_data.at(value_size++) = "VideoDecodeSrcBitKHR";
	}
	if (flags & VideoDecodeDstBitKHR) {
		value_data.at(value_size++) = "VideoDecodeDstBitKHR";
	}
	if (flags & VideoEncodeDstBitKHR) {
		value_data.at(value_size++) = "VideoEncodeDstBitKHR";
	}
	if (flags & VideoEncodeSrcBitKHR) {
		value_data.at(value_size++) = "VideoEncodeSrcBitKHR";
	}
	if (flags & ShaderDeviceAddress) {
		value_data.at(value_size++) = "ShaderDeviceAddress";
	}
	if (flags & AccelerationStructureBuildInputReadOnlyBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureBuildInputReadOnlyBitKHR";
	}
	if (flags & AccelerationStructureStorageBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureStorageBitKHR";
	}
	if (flags & SamplerDescriptorBufferBitEXT) {
		value_data.at(value_size++) = "SamplerDescriptorBufferBitEXT";
	}
	if (flags & ResourceDescriptorBufferBitEXT) {
		value_data.at(value_size++) = "ResourceDescriptorBufferBitEXT";
	}
	if (flags & MicromapBuildInputReadOnlyBitEXT) {
		value_data.at(value_size++) = "MicromapBuildInputReadOnlyBitEXT";
	}
	if (flags & MicromapStorageBitEXT) {
		value_data.at(value_size++) = "MicromapStorageBitEXT";
	}
	if (flags & ExecutionGraphScratchBitAMDX) {
		value_data.at(value_size++) = "ExecutionGraphScratchBitAMDX";
	}
	if (flags & PushDescriptorsDescriptorBufferBitEXT) {
		value_data.at(value_size++) = "PushDescriptorsDescriptorBufferBitEXT";
	}
	if (flags & TileMemoryBitQCOM) {
		value_data.at(value_size++) = "TileMemoryBitQCOM";
	}
	if (flags & DescriptorHeapBitEXT) {
		value_data.at(value_size++) = "DescriptorHeapBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(BufferUsageFlags2 flags) -> std::string {
	using enum BufferUsageBits2;
	if ((flags & AllBits) != flags) {
		return "BufferUsageBits2 does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 33> value_data;
	if (flags & TransferSrc) {
		value_data.at(value_size++) = "TransferSrc";
	}
	if (flags & TransferDst) {
		value_data.at(value_size++) = "TransferDst";
	}
	if (flags & UniformTexelBuffer) {
		value_data.at(value_size++) = "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		value_data.at(value_size++) = "StorageTexelBuffer";
	}
	if (flags & UniformBuffer) {
		value_data.at(value_size++) = "UniformBuffer";
	}
	if (flags & StorageBuffer) {
		value_data.at(value_size++) = "StorageBuffer";
	}
	if (flags & IndexBuffer) {
		value_data.at(value_size++) = "IndexBuffer";
	}
	if (flags & VertexBuffer) {
		value_data.at(value_size++) = "VertexBuffer";
	}
	if (flags & IndirectBuffer) {
		value_data.at(value_size++) = "IndirectBuffer";
	}
	if (flags & ConditionalRenderingBitEXT) {
		value_data.at(value_size++) = "ConditionalRenderingBitEXT";
	}
	if (flags & ShaderBindingTableBitKHR) {
		value_data.at(value_size++) = "ShaderBindingTableBitKHR";
	}
	if (flags & TransformFeedbackBufferBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackBufferBitEXT";
	}
	if (flags & TransformFeedbackCounterBufferBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackCounterBufferBitEXT";
	}
	if (flags & VideoDecodeSrcBitKHR) {
		value_data.at(value_size++) = "VideoDecodeSrcBitKHR";
	}
	if (flags & VideoDecodeDstBitKHR) {
		value_data.at(value_size++) = "VideoDecodeDstBitKHR";
	}
	if (flags & VideoEncodeDstBitKHR) {
		value_data.at(value_size++) = "VideoEncodeDstBitKHR";
	}
	if (flags & VideoEncodeSrcBitKHR) {
		value_data.at(value_size++) = "VideoEncodeSrcBitKHR";
	}
	if (flags & ShaderDeviceAddress) {
		value_data.at(value_size++) = "ShaderDeviceAddress";
	}
	if (flags & AccelerationStructureBuildInputReadOnlyBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureBuildInputReadOnlyBitKHR";
	}
	if (flags & AccelerationStructureStorageBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureStorageBitKHR";
	}
	if (flags & SamplerDescriptorBufferBitEXT) {
		value_data.at(value_size++) = "SamplerDescriptorBufferBitEXT";
	}
	if (flags & ResourceDescriptorBufferBitEXT) {
		value_data.at(value_size++) = "ResourceDescriptorBufferBitEXT";
	}
	if (flags & MicromapBuildInputReadOnlyBitEXT) {
		value_data.at(value_size++) = "MicromapBuildInputReadOnlyBitEXT";
	}
	if (flags & MicromapStorageBitEXT) {
		value_data.at(value_size++) = "MicromapStorageBitEXT";
	}
	if (flags & ExecutionGraphScratchBitAMDX) {
		value_data.at(value_size++) = "ExecutionGraphScratchBitAMDX";
	}
	if (flags & PushDescriptorsDescriptorBufferBitEXT) {
		value_data.at(value_size++) = "PushDescriptorsDescriptorBufferBitEXT";
	}
	if (flags & TileMemoryBitQCOM) {
		value_data.at(value_size++) = "TileMemoryBitQCOM";
	}
	if (flags & DescriptorHeapBitEXT) {
		value_data.at(value_size++) = "DescriptorHeapBitEXT";
	}
	if (flags & DataGraphForeignDescriptorBitARM) {
		value_data.at(value_size++) = "DataGraphForeignDescriptorBitARM";
	}
	if (flags & PreprocessBufferBitEXT) {
		value_data.at(value_size++) = "PreprocessBufferBitEXT";
	}
	if (flags & MemoryDecompressionBitEXT) {
		value_data.at(value_size++) = "MemoryDecompressionBitEXT";
	}
	if (flags & CompressedDataDgf1BitAMDX) {
		value_data.at(value_size++) = "CompressedDataDgf1BitAMDX";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(BufferViewCreateFlags flags) -> std::string {
	if (flags) {
		return "BufferViewCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(BuildAccelerationStructureFlagsKHR flags) -> std::string {
	using enum BuildAccelerationStructureBitsKHR;
	if ((flags & AllBits) != flags) {
		return "BuildAccelerationStructureBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 14> value_data;
	if (flags & AllowUpdate) {
		value_data.at(value_size++) = "AllowUpdate";
	}
	if (flags & AllowCompaction) {
		value_data.at(value_size++) = "AllowCompaction";
	}
	if (flags & PreferFastTrace) {
		value_data.at(value_size++) = "PreferFastTrace";
	}
	if (flags & PreferFastBuild) {
		value_data.at(value_size++) = "PreferFastBuild";
	}
	if (flags & LowMemory) {
		value_data.at(value_size++) = "LowMemory";
	}
	if (flags & MotionBitNV) {
		value_data.at(value_size++) = "MotionBitNV";
	}
	if (flags & AllowOpacityMicromapUpdate) {
		value_data.at(value_size++) = "AllowOpacityMicromapUpdate";
	}
	if (flags & AllowDisableOpacityMicromaps) {
		value_data.at(value_size++) = "AllowDisableOpacityMicromaps";
	}
	if (flags & AllowOpacityMicromapDataUpdateBitEXT) {
		value_data.at(value_size++) = "AllowOpacityMicromapDataUpdateBitEXT";
	}
	if (flags & AllowDisplacementMicromapUpdateBitNV) {
		value_data.at(value_size++) = "AllowDisplacementMicromapUpdateBitNV";
	}
	if (flags & MicromapLossy) {
		value_data.at(value_size++) = "MicromapLossy";
	}
	if (flags & AllowDataAccess) {
		value_data.at(value_size++) = "AllowDataAccess";
	}
	if (flags & AllowClusterOpacityMicromapsBitNV) {
		value_data.at(value_size++) = "AllowClusterOpacityMicromapsBitNV";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(BuildMicromapFlagsEXT flags) -> std::string {
	using enum BuildMicromapBitsEXT;
	if ((flags & AllBits) != flags) {
		return "BuildMicromapBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & PreferFastTrace) {
		value_data.at(value_size++) = "PreferFastTrace";
	}
	if (flags & PreferFastBuild) {
		value_data.at(value_size++) = "PreferFastBuild";
	}
	if (flags & AllowCompaction) {
		value_data.at(value_size++) = "AllowCompaction";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ClusterAccelerationStructureAddressResolutionFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureAddressResolutionBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureAddressResolutionBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 8> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & IndirectedDstImplicitData) {
		value_data.at(value_size++) = "IndirectedDstImplicitData";
	}
	if (flags & IndirectedScratchData) {
		value_data.at(value_size++) = "IndirectedScratchData";
	}
	if (flags & IndirectedDstAddressArray) {
		value_data.at(value_size++) = "IndirectedDstAddressArray";
	}
	if (flags & IndirectedDstSizesArray) {
		value_data.at(value_size++) = "IndirectedDstSizesArray";
	}
	if (flags & IndirectedSrcInfosArray) {
		value_data.at(value_size++) = "IndirectedSrcInfosArray";
	}
	if (flags & IndirectedSrcInfosCount) {
		value_data.at(value_size++) = "IndirectedSrcInfosCount";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ClusterAccelerationStructureClusterFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureClusterBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureClusterBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & AllowDisableOpacityMicromaps) {
		value_data.at(value_size++) = "AllowDisableOpacityMicromaps";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ClusterAccelerationStructureGeometryFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureGeometryBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureGeometryBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & CullDisable) {
		value_data.at(value_size++) = "CullDisable";
	}
	if (flags & NoDuplicateAnyhitInvocation) {
		value_data.at(value_size++) = "NoDuplicateAnyhitInvocation";
	}
	if (flags & Opaque) {
		value_data.at(value_size++) = "Opaque";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ClusterAccelerationStructureIndexFormatFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureIndexFormatBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureIndexFormatBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & v8) {
		value_data.at(value_size++) = "v8";
	}
	if (flags & v16) {
		value_data.at(value_size++) = "v16";
	}
	if (flags & v32) {
		value_data.at(value_size++) = "v32";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ColorComponentFlags flags) -> std::string {
	using enum ColorComponentBits;
	if ((flags & AllBits) != flags) {
		return "ColorComponentBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & R) {
		value_data.at(value_size++) = "R";
	}
	if (flags & G) {
		value_data.at(value_size++) = "G";
	}
	if (flags & B) {
		value_data.at(value_size++) = "B";
	}
	if (flags & A) {
		value_data.at(value_size++) = "A";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(CommandBufferResetFlags flags) -> std::string {
	using enum CommandBufferResetBits;
	if ((flags & AllBits) != flags) {
		return "CommandBufferResetBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & ReleaseResources) {
		value_data.at(value_size++) = "ReleaseResources";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(CommandBufferUsageFlags flags) -> std::string {
	using enum CommandBufferUsageBits;
	if ((flags & AllBits) != flags) {
		return "CommandBufferUsageBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & OneTimeSubmit) {
		value_data.at(value_size++) = "OneTimeSubmit";
	}
	if (flags & RenderPassContinue) {
		value_data.at(value_size++) = "RenderPassContinue";
	}
	if (flags & SimultaneousUse) {
		value_data.at(value_size++) = "SimultaneousUse";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(CommandPoolCreateFlags flags) -> std::string {
	using enum CommandPoolCreateBits;
	if ((flags & AllBits) != flags) {
		return "CommandPoolCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & Transient) {
		value_data.at(value_size++) = "Transient";
	}
	if (flags & ResetCommandBuffer) {
		value_data.at(value_size++) = "ResetCommandBuffer";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(CommandPoolResetFlags flags) -> std::string {
	using enum CommandPoolResetBits;
	if ((flags & AllBits) != flags) {
		return "CommandPoolResetBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & ReleaseResources) {
		value_data.at(value_size++) = "ReleaseResources";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(CommandPoolTrimFlags flags) -> std::string {
	if (flags) {
		return "CommandPoolTrimFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(CompositeAlphaFlagsKHR flags) -> std::string {
	using enum CompositeAlphaBitsKHR;
	if ((flags & AllBits) != flags) {
		return "CompositeAlphaBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Opaque) {
		value_data.at(value_size++) = "Opaque";
	}
	if (flags & PreMultiplied) {
		value_data.at(value_size++) = "PreMultiplied";
	}
	if (flags & PostMultiplied) {
		value_data.at(value_size++) = "PostMultiplied";
	}
	if (flags & Inherit) {
		value_data.at(value_size++) = "Inherit";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ConditionalRenderingFlagsEXT flags) -> std::string {
	using enum ConditionalRenderingBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ConditionalRenderingBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Inverted) {
		value_data.at(value_size++) = "Inverted";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(CooperativeMatrixFlagsEXT flags) -> std::string {
	using enum CooperativeMatrixBitsEXT;
	if ((flags & AllBits) != flags) {
		return "CooperativeMatrixBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & SaturatingAccumulation) {
		value_data.at(value_size++) = "SaturatingAccumulation";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(CullModeFlags flags) -> std::string {
	using enum CullModeBits;
	if ((flags & AllBits) != flags) {
		return "CullModeBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & Front) {
		value_data.at(value_size++) = "Front";
	}
	if (flags & Back) {
		value_data.at(value_size++) = "Back";
	}
	if (flags & FrontAndBack) {
		value_data.at(value_size++) = "FrontAndBack";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DataGraphOpticalFlowCreateFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowCreateBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowCreateBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & EnableHint) {
		value_data.at(value_size++) = "EnableHint";
	}
	if (flags & EnableCost) {
		value_data.at(value_size++) = "EnableCost";
	}
	if (flags & Reserved30) {
		value_data.at(value_size++) = "Reserved30";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DataGraphOpticalFlowExecuteFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowExecuteBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowExecuteBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & DisableTemporalHints) {
		value_data.at(value_size++) = "DisableTemporalHints";
	}
	if (flags & InputUnchanged) {
		value_data.at(value_size++) = "InputUnchanged";
	}
	if (flags & ReferenceUnchanged) {
		value_data.at(value_size++) = "ReferenceUnchanged";
	}
	if (flags & InputIsPreviousReference) {
		value_data.at(value_size++) = "InputIsPreviousReference";
	}
	if (flags & ReferenceIsPreviousInput) {
		value_data.at(value_size++) = "ReferenceIsPreviousInput";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DataGraphOpticalFlowGridSizeFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowGridSizeBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowGridSizeBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & Unknown) {
		value_data.at(value_size++) = "Unknown";
	}
	if (flags & v1x1) {
		value_data.at(value_size++) = "v1x1";
	}
	if (flags & v2x2) {
		value_data.at(value_size++) = "v2x2";
	}
	if (flags & v4x4) {
		value_data.at(value_size++) = "v4x4";
	}
	if (flags & v8x8) {
		value_data.at(value_size++) = "v8x8";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DataGraphOpticalFlowImageUsageFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowImageUsageBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowImageUsageBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & Unknown) {
		value_data.at(value_size++) = "Unknown";
	}
	if (flags & Input) {
		value_data.at(value_size++) = "Input";
	}
	if (flags & Output) {
		value_data.at(value_size++) = "Output";
	}
	if (flags & Hint) {
		value_data.at(value_size++) = "Hint";
	}
	if (flags & Cost) {
		value_data.at(value_size++) = "Cost";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DataGraphPipelineDispatchFlagsARM flags) -> std::string {
	if (flags) {
		return "DataGraphPipelineDispatchFlagsARM has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DataGraphPipelineSessionCreateFlagsARM flags) -> std::string {
	using enum DataGraphPipelineSessionCreateBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphPipelineSessionCreateBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & OpticalFlowCache) {
		value_data.at(value_size++) = "OpticalFlowCache";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DataGraphTOSAQualityFlagsARM flags) -> std::string {
	using enum DataGraphTOSAQualityBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphTOSAQualityBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & DataGraphTosaQualityAccelerated) {
		value_data.at(value_size++) = "DataGraphTosaQualityAccelerated";
	}
	if (flags & DataGraphTosaQualityConformant) {
		value_data.at(value_size++) = "DataGraphTosaQualityConformant";
	}
	if (flags & DataGraphTosaQualityExperimental) {
		value_data.at(value_size++) = "DataGraphTosaQualityExperimental";
	}
	if (flags & DataGraphTosaQualityDeprecated) {
		value_data.at(value_size++) = "DataGraphTosaQualityDeprecated";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DebugReportFlagsEXT flags) -> std::string {
	using enum DebugReportBitsEXT;
	if ((flags & AllBits) != flags) {
		return "DebugReportBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & Information) {
		value_data.at(value_size++) = "Information";
	}
	if (flags & Warning) {
		value_data.at(value_size++) = "Warning";
	}
	if (flags & PerformanceWarning) {
		value_data.at(value_size++) = "PerformanceWarning";
	}
	if (flags & Error) {
		value_data.at(value_size++) = "Error";
	}
	if (flags & Debug) {
		value_data.at(value_size++) = "Debug";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DebugUtilsMessageSeverityFlagsEXT flags) -> std::string {
	using enum DebugUtilsMessageSeverityBitsEXT;
	if ((flags & AllBits) != flags) {
		return "DebugUtilsMessageSeverityBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Verbose) {
		value_data.at(value_size++) = "Verbose";
	}
	if (flags & Info) {
		value_data.at(value_size++) = "Info";
	}
	if (flags & Warning) {
		value_data.at(value_size++) = "Warning";
	}
	if (flags & Error) {
		value_data.at(value_size++) = "Error";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DebugUtilsMessageTypeFlagsEXT flags) -> std::string {
	using enum DebugUtilsMessageTypeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "DebugUtilsMessageTypeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & General) {
		value_data.at(value_size++) = "General";
	}
	if (flags & Validation) {
		value_data.at(value_size++) = "Validation";
	}
	if (flags & Performance) {
		value_data.at(value_size++) = "Performance";
	}
	if (flags & DeviceAddressBinding) {
		value_data.at(value_size++) = "DeviceAddressBinding";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DebugUtilsMessengerCallbackDataFlagsEXT flags) -> std::string {
	if (flags) {
		return "DebugUtilsMessengerCallbackDataFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DebugUtilsMessengerCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "DebugUtilsMessengerCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DependencyFlags flags) -> std::string {
	using enum DependencyBits;
	if ((flags & AllBits) != flags) {
		return "DependencyBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & ByRegion) {
		value_data.at(value_size++) = "ByRegion";
	}
	if (flags & ViewLocal) {
		value_data.at(value_size++) = "ViewLocal";
	}
	if (flags & DeviceGroup) {
		value_data.at(value_size++) = "DeviceGroup";
	}
	if (flags & FeedbackLoopBitEXT) {
		value_data.at(value_size++) = "FeedbackLoopBitEXT";
	}
	if (flags & QueueFamilyOwnershipTransferUseAllStagesBitKHR) {
		value_data.at(value_size++) = "QueueFamilyOwnershipTransferUseAllStagesBitKHR";
	}
	if (flags & AsymmetricEventBitKHR) {
		value_data.at(value_size++) = "AsymmetricEventBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DescriptorBindingFlags flags) -> std::string {
	using enum DescriptorBindingBits;
	if ((flags & AllBits) != flags) {
		return "DescriptorBindingBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & UpdateAfterBind) {
		value_data.at(value_size++) = "UpdateAfterBind";
	}
	if (flags & UpdateUnusedWhilePending) {
		value_data.at(value_size++) = "UpdateUnusedWhilePending";
	}
	if (flags & PartiallyBound) {
		value_data.at(value_size++) = "PartiallyBound";
	}
	if (flags & VariableDescriptorCount) {
		value_data.at(value_size++) = "VariableDescriptorCount";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DescriptorPoolCreateFlags flags) -> std::string {
	using enum DescriptorPoolCreateBits;
	if ((flags & AllBits) != flags) {
		return "DescriptorPoolCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & FreeDescriptorSet) {
		value_data.at(value_size++) = "FreeDescriptorSet";
	}
	if (flags & UpdateAfterBind) {
		value_data.at(value_size++) = "UpdateAfterBind";
	}
	if (flags & HostOnlyBitEXT) {
		value_data.at(value_size++) = "HostOnlyBitEXT";
	}
	if (flags & AllowOverallocationSetsBitNV) {
		value_data.at(value_size++) = "AllowOverallocationSetsBitNV";
	}
	if (flags & AllowOverallocationPoolsBitNV) {
		value_data.at(value_size++) = "AllowOverallocationPoolsBitNV";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DescriptorPoolResetFlags flags) -> std::string {
	if (flags) {
		return "DescriptorPoolResetFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DescriptorSetLayoutCreateFlags flags) -> std::string {
	using enum DescriptorSetLayoutCreateBits;
	if ((flags & AllBits) != flags) {
		return "DescriptorSetLayoutCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 8> value_data;
	if (flags & PushDescriptor) {
		value_data.at(value_size++) = "PushDescriptor";
	}
	if (flags & UpdateAfterBindPool) {
		value_data.at(value_size++) = "UpdateAfterBindPool";
	}
	if (flags & HostOnlyPoolBitEXT) {
		value_data.at(value_size++) = "HostOnlyPoolBitEXT";
	}
	if (flags & DescriptorBufferBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferBitEXT";
	}
	if (flags & EmbeddedImmutableSamplersBitEXT) {
		value_data.at(value_size++) = "EmbeddedImmutableSamplersBitEXT";
	}
	if (flags & PerStageBitNV) {
		value_data.at(value_size++) = "PerStageBitNV";
	}
	if (flags & IndirectBindableBitNV) {
		value_data.at(value_size++) = "IndirectBindableBitNV";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DescriptorUpdateTemplateCreateFlags flags) -> std::string {
	if (flags) {
		return "DescriptorUpdateTemplateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DeviceAddressBindingFlagsEXT flags) -> std::string {
	using enum DeviceAddressBindingBitsEXT;
	if ((flags & AllBits) != flags) {
		return "DeviceAddressBindingBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & InternalObject) {
		value_data.at(value_size++) = "InternalObject";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DeviceCreateFlags flags) -> std::string {
	if (flags) {
		return "DeviceCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DeviceDiagnosticsConfigFlagsNV flags) -> std::string {
	using enum DeviceDiagnosticsConfigBitsNV;
	if ((flags & AllBits) != flags) {
		return "DeviceDiagnosticsConfigBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & EnableShaderDebugInfo) {
		value_data.at(value_size++) = "EnableShaderDebugInfo";
	}
	if (flags & EnableResourceTracking) {
		value_data.at(value_size++) = "EnableResourceTracking";
	}
	if (flags & EnableAutomaticCheckpoints) {
		value_data.at(value_size++) = "EnableAutomaticCheckpoints";
	}
	if (flags & EnableShaderErrorReporting) {
		value_data.at(value_size++) = "EnableShaderErrorReporting";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DeviceFaultFlagsKHR flags) -> std::string {
	using enum DeviceFaultBitsKHR;
	if ((flags & AllBits) != flags) {
		return "DeviceFaultBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & FlagDeviceLost) {
		value_data.at(value_size++) = "FlagDeviceLost";
	}
	if (flags & FlagMemoryAddress) {
		value_data.at(value_size++) = "FlagMemoryAddress";
	}
	if (flags & FlagInstructionAddress) {
		value_data.at(value_size++) = "FlagInstructionAddress";
	}
	if (flags & FlagVendor) {
		value_data.at(value_size++) = "FlagVendor";
	}
	if (flags & FlagWatchdogTimeout) {
		value_data.at(value_size++) = "FlagWatchdogTimeout";
	}
	if (flags & FlagOverflow) {
		value_data.at(value_size++) = "FlagOverflow";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DeviceGroupPresentModeFlagsKHR flags) -> std::string {
	using enum DeviceGroupPresentModeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "DeviceGroupPresentModeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Local) {
		value_data.at(value_size++) = "Local";
	}
	if (flags & Remote) {
		value_data.at(value_size++) = "Remote";
	}
	if (flags & Sum) {
		value_data.at(value_size++) = "Sum";
	}
	if (flags & LocalMultiDevice) {
		value_data.at(value_size++) = "LocalMultiDevice";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DeviceMemoryReportFlagsEXT flags) -> std::string {
	if (flags) {
		return "DeviceMemoryReportFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DeviceQueueCreateFlags flags) -> std::string {
	using enum DeviceQueueCreateBits;
	if ((flags & AllBits) != flags) {
		return "DeviceQueueCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & InternallySynchronizedBitKHR) {
		value_data.at(value_size++) = "InternallySynchronizedBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DirectDriverLoadingFlagsLUNARG flags) -> std::string {
	if (flags) {
		return "DirectDriverLoadingFlagsLUNARG has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DirectFBSurfaceCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "DirectFBSurfaceCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DisplayModeCreateFlagsKHR flags) -> std::string {
	if (flags) {
		return "DisplayModeCreateFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(DisplayPlaneAlphaFlagsKHR flags) -> std::string {
	using enum DisplayPlaneAlphaBitsKHR;
	if ((flags & AllBits) != flags) {
		return "DisplayPlaneAlphaBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Opaque) {
		value_data.at(value_size++) = "Opaque";
	}
	if (flags & Global) {
		value_data.at(value_size++) = "Global";
	}
	if (flags & PerPixel) {
		value_data.at(value_size++) = "PerPixel";
	}
	if (flags & PerPixelPremultiplied) {
		value_data.at(value_size++) = "PerPixelPremultiplied";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(DisplaySurfaceCreateFlagsKHR flags) -> std::string {
	if (flags) {
		return "DisplaySurfaceCreateFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(EventCreateFlags flags) -> std::string {
	using enum EventCreateBits;
	if ((flags & AllBits) != flags) {
		return "EventCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & DeviceOnly) {
		value_data.at(value_size++) = "DeviceOnly";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExportMetalObjectTypeFlagsEXT flags) -> std::string {
	using enum ExportMetalObjectTypeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ExportMetalObjectTypeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & MetalDevice) {
		value_data.at(value_size++) = "MetalDevice";
	}
	if (flags & MetalCommandQueue) {
		value_data.at(value_size++) = "MetalCommandQueue";
	}
	if (flags & MetalBuffer) {
		value_data.at(value_size++) = "MetalBuffer";
	}
	if (flags & MetalTexture) {
		value_data.at(value_size++) = "MetalTexture";
	}
	if (flags & MetalIosurface) {
		value_data.at(value_size++) = "MetalIosurface";
	}
	if (flags & MetalSharedEvent) {
		value_data.at(value_size++) = "MetalSharedEvent";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalFenceFeatureFlags flags) -> std::string {
	using enum ExternalFenceFeatureBits;
	if ((flags & AllBits) != flags) {
		return "ExternalFenceFeatureBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & Exportable) {
		value_data.at(value_size++) = "Exportable";
	}
	if (flags & Importable) {
		value_data.at(value_size++) = "Importable";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalFenceHandleTypeFlags flags) -> std::string {
	using enum ExternalFenceHandleTypeBits;
	if ((flags & AllBits) != flags) {
		return "ExternalFenceHandleTypeBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & OpaqueFd) {
		value_data.at(value_size++) = "OpaqueFd";
	}
	if (flags & OpaqueWin32) {
		value_data.at(value_size++) = "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		value_data.at(value_size++) = "OpaqueWin32Kmt";
	}
	if (flags & SyncFd) {
		value_data.at(value_size++) = "SyncFd";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalMemoryFeatureFlags flags) -> std::string {
	using enum ExternalMemoryFeatureBits;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryFeatureBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & DedicatedOnly) {
		value_data.at(value_size++) = "DedicatedOnly";
	}
	if (flags & Exportable) {
		value_data.at(value_size++) = "Exportable";
	}
	if (flags & Importable) {
		value_data.at(value_size++) = "Importable";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalMemoryFeatureFlagsNV flags) -> std::string {
	using enum ExternalMemoryFeatureBitsNV;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryFeatureBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & DedicatedOnly) {
		value_data.at(value_size++) = "DedicatedOnly";
	}
	if (flags & Exportable) {
		value_data.at(value_size++) = "Exportable";
	}
	if (flags & Importable) {
		value_data.at(value_size++) = "Importable";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalMemoryHandleTypeFlags flags) -> std::string {
	using enum ExternalMemoryHandleTypeBits;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryHandleTypeBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 19> value_data;
	if (flags & OpaqueFd) {
		value_data.at(value_size++) = "OpaqueFd";
	}
	if (flags & OpaqueWin32) {
		value_data.at(value_size++) = "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		value_data.at(value_size++) = "OpaqueWin32Kmt";
	}
	if (flags & D3D11Texture) {
		value_data.at(value_size++) = "D3D11Texture";
	}
	if (flags & D3D11TextureKmt) {
		value_data.at(value_size++) = "D3D11TextureKmt";
	}
	if (flags & D3D12Heap) {
		value_data.at(value_size++) = "D3D12Heap";
	}
	if (flags & D3D12Resource) {
		value_data.at(value_size++) = "D3D12Resource";
	}
	if (flags & HostAllocationBitEXT) {
		value_data.at(value_size++) = "HostAllocationBitEXT";
	}
	if (flags & HostMappedForeignMemoryBitEXT) {
		value_data.at(value_size++) = "HostMappedForeignMemoryBitEXT";
	}
	if (flags & DmaBufBitEXT) {
		value_data.at(value_size++) = "DmaBufBitEXT";
	}
	if (flags & ANDROIDHardwareBufferBitANDROID) {
		value_data.at(value_size++) = "ANDROIDHardwareBufferBitANDROID";
	}
	if (flags & ZirconVmoBitFUCHSIA) {
		value_data.at(value_size++) = "ZirconVmoBitFUCHSIA";
	}
	if (flags & RdmaAddressBitNV) {
		value_data.at(value_size++) = "RdmaAddressBitNV";
	}
	if (flags & ScreenBufferBitQNX) {
		value_data.at(value_size++) = "ScreenBufferBitQNX";
	}
	if (flags & OhNativeBufferBitOHOS) {
		value_data.at(value_size++) = "OhNativeBufferBitOHOS";
	}
	if (flags & MtlbufferBitEXT) {
		value_data.at(value_size++) = "MtlbufferBitEXT";
	}
	if (flags & MtltextureBitEXT) {
		value_data.at(value_size++) = "MtltextureBitEXT";
	}
	if (flags & MtlheapBitEXT) {
		value_data.at(value_size++) = "MtlheapBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalMemoryHandleTypeFlagsNV flags) -> std::string {
	using enum ExternalMemoryHandleTypeBitsNV;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryHandleTypeBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & OpaqueWin32) {
		value_data.at(value_size++) = "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		value_data.at(value_size++) = "OpaqueWin32Kmt";
	}
	if (flags & D3D11Image) {
		value_data.at(value_size++) = "D3D11Image";
	}
	if (flags & D3D11ImageKmt) {
		value_data.at(value_size++) = "D3D11ImageKmt";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalSemaphoreFeatureFlags flags) -> std::string {
	using enum ExternalSemaphoreFeatureBits;
	if ((flags & AllBits) != flags) {
		return "ExternalSemaphoreFeatureBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & Exportable) {
		value_data.at(value_size++) = "Exportable";
	}
	if (flags & Importable) {
		value_data.at(value_size++) = "Importable";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ExternalSemaphoreHandleTypeFlags flags) -> std::string {
	using enum ExternalSemaphoreHandleTypeBits;
	if ((flags & AllBits) != flags) {
		return "ExternalSemaphoreHandleTypeBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & OpaqueFd) {
		value_data.at(value_size++) = "OpaqueFd";
	}
	if (flags & OpaqueWin32) {
		value_data.at(value_size++) = "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		value_data.at(value_size++) = "OpaqueWin32Kmt";
	}
	if (flags & D3D12Fence) {
		value_data.at(value_size++) = "D3D12Fence";
	}
	if (flags & SyncFd) {
		value_data.at(value_size++) = "SyncFd";
	}
	if (flags & ZirconEventBitFUCHSIA) {
		value_data.at(value_size++) = "ZirconEventBitFUCHSIA";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(FenceCreateFlags flags) -> std::string {
	using enum FenceCreateBits;
	if ((flags & AllBits) != flags) {
		return "FenceCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Signaled) {
		value_data.at(value_size++) = "Signaled";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(FenceImportFlags flags) -> std::string {
	using enum FenceImportBits;
	if ((flags & AllBits) != flags) {
		return "FenceImportBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Temporary) {
		value_data.at(value_size++) = "Temporary";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(FormatFeatureFlags flags) -> std::string {
	using enum FormatFeatureBits;
	if ((flags & AllBits) != flags) {
		return "FormatFeatureBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 32> value_data;
	if (flags & SampledImage) {
		value_data.at(value_size++) = "SampledImage";
	}
	if (flags & StorageImage) {
		value_data.at(value_size++) = "StorageImage";
	}
	if (flags & StorageImageAtomic) {
		value_data.at(value_size++) = "StorageImageAtomic";
	}
	if (flags & UniformTexelBuffer) {
		value_data.at(value_size++) = "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		value_data.at(value_size++) = "StorageTexelBuffer";
	}
	if (flags & StorageTexelBufferAtomic) {
		value_data.at(value_size++) = "StorageTexelBufferAtomic";
	}
	if (flags & VertexBuffer) {
		value_data.at(value_size++) = "VertexBuffer";
	}
	if (flags & ColorAttachment) {
		value_data.at(value_size++) = "ColorAttachment";
	}
	if (flags & ColorAttachmentBlend) {
		value_data.at(value_size++) = "ColorAttachmentBlend";
	}
	if (flags & DepthStencilAttachment) {
		value_data.at(value_size++) = "DepthStencilAttachment";
	}
	if (flags & BlitSrc) {
		value_data.at(value_size++) = "BlitSrc";
	}
	if (flags & BlitDst) {
		value_data.at(value_size++) = "BlitDst";
	}
	if (flags & SampledImageFilterLinear) {
		value_data.at(value_size++) = "SampledImageFilterLinear";
	}
	if (flags & SampledImageFilterCubicBitEXT) {
		value_data.at(value_size++) = "SampledImageFilterCubicBitEXT";
	}
	if (flags & TransferSrc) {
		value_data.at(value_size++) = "TransferSrc";
	}
	if (flags & TransferDst) {
		value_data.at(value_size++) = "TransferDst";
	}
	if (flags & SampledImageFilterMinmax) {
		value_data.at(value_size++) = "SampledImageFilterMinmax";
	}
	if (flags & MidpointChromaSamples) {
		value_data.at(value_size++) = "MidpointChromaSamples";
	}
	if (flags & SampledImageYcbcrConversionLinearFilter) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionLinearFilter";
	}
	if (flags & SampledImageYcbcrConversionSeparateReconstructionFilter) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionSeparateReconstructionFilter";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicit) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionChromaReconstructionExplicit";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicitForceable) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionChromaReconstructionExplicitForceable";
	}
	if (flags & Disjoint) {
		value_data.at(value_size++) = "Disjoint";
	}
	if (flags & CositedChromaSamples) {
		value_data.at(value_size++) = "CositedChromaSamples";
	}
	if (flags & FragmentDensityMapBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeOutputBitKHR) {
		value_data.at(value_size++) = "VideoDecodeOutputBitKHR";
	}
	if (flags & VideoDecodeDpbBitKHR) {
		value_data.at(value_size++) = "VideoDecodeDpbBitKHR";
	}
	if (flags & VideoEncodeInputBitKHR) {
		value_data.at(value_size++) = "VideoEncodeInputBitKHR";
	}
	if (flags & VideoEncodeDpbBitKHR) {
		value_data.at(value_size++) = "VideoEncodeDpbBitKHR";
	}
	if (flags & AccelerationStructureVertexBufferBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureVertexBufferBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		value_data.at(value_size++) = "FragmentShadingRateAttachmentBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(FormatFeatureFlags2 flags) -> std::string {
	using enum FormatFeatureBits2;
	if ((flags & AllBits) != flags) {
		return "FormatFeatureBits2 does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 60> value_data;
	if (flags & SampledImage) {
		value_data.at(value_size++) = "SampledImage";
	}
	if (flags & StorageImage) {
		value_data.at(value_size++) = "StorageImage";
	}
	if (flags & StorageImageAtomic) {
		value_data.at(value_size++) = "StorageImageAtomic";
	}
	if (flags & UniformTexelBuffer) {
		value_data.at(value_size++) = "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		value_data.at(value_size++) = "StorageTexelBuffer";
	}
	if (flags & StorageTexelBufferAtomic) {
		value_data.at(value_size++) = "StorageTexelBufferAtomic";
	}
	if (flags & VertexBuffer) {
		value_data.at(value_size++) = "VertexBuffer";
	}
	if (flags & ColorAttachment) {
		value_data.at(value_size++) = "ColorAttachment";
	}
	if (flags & ColorAttachmentBlend) {
		value_data.at(value_size++) = "ColorAttachmentBlend";
	}
	if (flags & DepthStencilAttachment) {
		value_data.at(value_size++) = "DepthStencilAttachment";
	}
	if (flags & BlitSrc) {
		value_data.at(value_size++) = "BlitSrc";
	}
	if (flags & BlitDst) {
		value_data.at(value_size++) = "BlitDst";
	}
	if (flags & SampledImageFilterLinear) {
		value_data.at(value_size++) = "SampledImageFilterLinear";
	}
	if (flags & SampledImageFilterCubic) {
		value_data.at(value_size++) = "SampledImageFilterCubic";
	}
	if (flags & TransferSrc) {
		value_data.at(value_size++) = "TransferSrc";
	}
	if (flags & TransferDst) {
		value_data.at(value_size++) = "TransferDst";
	}
	if (flags & SampledImageFilterMinmax) {
		value_data.at(value_size++) = "SampledImageFilterMinmax";
	}
	if (flags & MidpointChromaSamples) {
		value_data.at(value_size++) = "MidpointChromaSamples";
	}
	if (flags & SampledImageYcbcrConversionLinearFilter) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionLinearFilter";
	}
	if (flags & SampledImageYcbcrConversionSeparateReconstructionFilter) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionSeparateReconstructionFilter";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicit) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionChromaReconstructionExplicit";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicitForceable) {
		value_data.at(value_size++) = "SampledImageYcbcrConversionChromaReconstructionExplicitForceable";
	}
	if (flags & Disjoint) {
		value_data.at(value_size++) = "Disjoint";
	}
	if (flags & CositedChromaSamples) {
		value_data.at(value_size++) = "CositedChromaSamples";
	}
	if (flags & FragmentDensityMapBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeOutputBitKHR) {
		value_data.at(value_size++) = "VideoDecodeOutputBitKHR";
	}
	if (flags & VideoDecodeDpbBitKHR) {
		value_data.at(value_size++) = "VideoDecodeDpbBitKHR";
	}
	if (flags & VideoEncodeInputBitKHR) {
		value_data.at(value_size++) = "VideoEncodeInputBitKHR";
	}
	if (flags & VideoEncodeDpbBitKHR) {
		value_data.at(value_size++) = "VideoEncodeDpbBitKHR";
	}
	if (flags & AccelerationStructureVertexBufferBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureVertexBufferBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		value_data.at(value_size++) = "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & StorageReadWithoutFormat) {
		value_data.at(value_size++) = "StorageReadWithoutFormat";
	}
	if (flags & StorageWriteWithoutFormat) {
		value_data.at(value_size++) = "StorageWriteWithoutFormat";
	}
	if (flags & SampledImageDepthComparison) {
		value_data.at(value_size++) = "SampledImageDepthComparison";
	}
	if (flags & WeightImageBitQCOM) {
		value_data.at(value_size++) = "WeightImageBitQCOM";
	}
	if (flags & WeightSampledImageBitQCOM) {
		value_data.at(value_size++) = "WeightSampledImageBitQCOM";
	}
	if (flags & BlockMatchingBitQCOM) {
		value_data.at(value_size++) = "BlockMatchingBitQCOM";
	}
	if (flags & BoxFilterSampledBitQCOM) {
		value_data.at(value_size++) = "BoxFilterSampledBitQCOM";
	}
	if (flags & LinearColorAttachmentBitNV) {
		value_data.at(value_size++) = "LinearColorAttachmentBitNV";
	}
	if (flags & TensorShaderBitARM) {
		value_data.at(value_size++) = "TensorShaderBitARM";
	}
	if (flags & OpticalFlowImageBitNV) {
		value_data.at(value_size++) = "OpticalFlowImageBitNV";
	}
	if (flags & OpticalFlowVectorBitNV) {
		value_data.at(value_size++) = "OpticalFlowVectorBitNV";
	}
	if (flags & OpticalFlowCostBitNV) {
		value_data.at(value_size++) = "OpticalFlowCostBitNV";
	}
	if (flags & TensorImageAliasingBitARM) {
		value_data.at(value_size++) = "TensorImageAliasingBitARM";
	}
	if (flags & BlockMatchingSxdBitQCOM) {
		value_data.at(value_size++) = "BlockMatchingSxdBitQCOM";
	}
	if (flags & SampledImageFilterLinear2DBitIMG) {
		value_data.at(value_size++) = "SampledImageFilterLinear2DBitIMG";
	}
	if (flags & HostImageTransfer) {
		value_data.at(value_size++) = "HostImageTransfer";
	}
	if (flags & TensorDataGraphBitARM) {
		value_data.at(value_size++) = "TensorDataGraphBitARM";
	}
	if (flags & VideoEncodeQuantizationDeltaMapBitKHR) {
		value_data.at(value_size++) = "VideoEncodeQuantizationDeltaMapBitKHR";
	}
	if (flags & VideoEncodeEmphasisMapBitKHR) {
		value_data.at(value_size++) = "VideoEncodeEmphasisMapBitKHR";
	}
	if (flags & AccelerationStructureRadiusBufferBitNV) {
		value_data.at(value_size++) = "AccelerationStructureRadiusBufferBitNV";
	}
	if (flags & DepthCopyOnComputeQueueBitKHR) {
		value_data.at(value_size++) = "DepthCopyOnComputeQueueBitKHR";
	}
	if (flags & DepthCopyOnTransferQueueBitKHR) {
		value_data.at(value_size++) = "DepthCopyOnTransferQueueBitKHR";
	}
	if (flags & StencilCopyOnComputeQueueBitKHR) {
		value_data.at(value_size++) = "StencilCopyOnComputeQueueBitKHR";
	}
	if (flags & StencilCopyOnTransferQueueBitKHR) {
		value_data.at(value_size++) = "StencilCopyOnTransferQueueBitKHR";
	}
	if (flags & DataGraphOpticalFlowImageBitARM) {
		value_data.at(value_size++) = "DataGraphOpticalFlowImageBitARM";
	}
	if (flags & DataGraphOpticalFlowVectorBitARM) {
		value_data.at(value_size++) = "DataGraphOpticalFlowVectorBitARM";
	}
	if (flags & DataGraphOpticalFlowCostBitARM) {
		value_data.at(value_size++) = "DataGraphOpticalFlowCostBitARM";
	}
	if (flags & CopyImageIndirectDstBitKHR) {
		value_data.at(value_size++) = "CopyImageIndirectDstBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(FormatFeatureFlags4KHR flags) -> std::string {
	if (flags) {
		return "FormatFeatureFlags4KHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(FrameBoundaryFlagsEXT flags) -> std::string {
	using enum FrameBoundaryBitsEXT;
	if ((flags & AllBits) != flags) {
		return "FrameBoundaryBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & FrameEnd) {
		value_data.at(value_size++) = "FrameEnd";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(FramebufferCreateFlags flags) -> std::string {
	using enum FramebufferCreateBits;
	if ((flags & AllBits) != flags) {
		return "FramebufferCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Imageless) {
		value_data.at(value_size++) = "Imageless";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(GeometryFlagsKHR flags) -> std::string {
	using enum GeometryBitsKHR;
	if ((flags & AllBits) != flags) {
		return "GeometryBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & Opaque) {
		value_data.at(value_size++) = "Opaque";
	}
	if (flags & NoDuplicateAnyHitInvocation) {
		value_data.at(value_size++) = "NoDuplicateAnyHitInvocation";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(GeometryInstanceFlagsKHR flags) -> std::string {
	using enum GeometryInstanceBitsKHR;
	if ((flags & AllBits) != flags) {
		return "GeometryInstanceBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & TriangleFacingCullDisable) {
		value_data.at(value_size++) = "TriangleFacingCullDisable";
	}
	if (flags & TriangleFlipFacing) {
		value_data.at(value_size++) = "TriangleFlipFacing";
	}
	if (flags & ForceOpaque) {
		value_data.at(value_size++) = "ForceOpaque";
	}
	if (flags & ForceNoOpaque) {
		value_data.at(value_size++) = "ForceNoOpaque";
	}
	if (flags & ForceOpacityMicromap2State) {
		value_data.at(value_size++) = "ForceOpacityMicromap2State";
	}
	if (flags & DisableOpacityMicromaps) {
		value_data.at(value_size++) = "DisableOpacityMicromaps";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(GpaPerfBlockPropertiesFlagsAMD flags) -> std::string {
	if (flags) {
		return "GpaPerfBlockPropertiesFlagsAMD has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(GpaSqShaderStageFlagsAMD flags) -> std::string {
	using enum GpaSqShaderStageBitsAMD;
	if ((flags & AllBits) != flags) {
		return "GpaSqShaderStageBitsAMD does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 8> value_data;
	if (flags & Ps) {
		value_data.at(value_size++) = "Ps";
	}
	if (flags & Vs) {
		value_data.at(value_size++) = "Vs";
	}
	if (flags & Gs) {
		value_data.at(value_size++) = "Gs";
	}
	if (flags & Es) {
		value_data.at(value_size++) = "Es";
	}
	if (flags & Hs) {
		value_data.at(value_size++) = "Hs";
	}
	if (flags & Ls) {
		value_data.at(value_size++) = "Ls";
	}
	if (flags & Cs) {
		value_data.at(value_size++) = "Cs";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(GraphicsPipelineLibraryFlagsEXT flags) -> std::string {
	using enum GraphicsPipelineLibraryBitsEXT;
	if ((flags & AllBits) != flags) {
		return "GraphicsPipelineLibraryBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & VertexInputInterface) {
		value_data.at(value_size++) = "VertexInputInterface";
	}
	if (flags & PreRasterizationShaders) {
		value_data.at(value_size++) = "PreRasterizationShaders";
	}
	if (flags & FragmentShader) {
		value_data.at(value_size++) = "FragmentShader";
	}
	if (flags & FragmentOutputInterface) {
		value_data.at(value_size++) = "FragmentOutputInterface";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(HeadlessSurfaceCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "HeadlessSurfaceCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(HostImageCopyFlags flags) -> std::string {
	using enum HostImageCopyBits;
	if ((flags & AllBits) != flags) {
		return "HostImageCopyBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Memcpy) {
		value_data.at(value_size++) = "Memcpy";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(IOSSurfaceCreateFlagsMVK flags) -> std::string {
	if (flags) {
		return "IOSSurfaceCreateFlagsMVK has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ImageAspectFlags flags) -> std::string {
	using enum ImageAspectBits;
	if ((flags & AllBits) != flags) {
		return "ImageAspectBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 13> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & Color) {
		value_data.at(value_size++) = "Color";
	}
	if (flags & Depth) {
		value_data.at(value_size++) = "Depth";
	}
	if (flags & Stencil) {
		value_data.at(value_size++) = "Stencil";
	}
	if (flags & Metadata) {
		value_data.at(value_size++) = "Metadata";
	}
	if (flags & Plane0) {
		value_data.at(value_size++) = "Plane0";
	}
	if (flags & Plane1) {
		value_data.at(value_size++) = "Plane1";
	}
	if (flags & Plane2) {
		value_data.at(value_size++) = "Plane2";
	}
	if (flags & MemoryPlane0BitEXT) {
		value_data.at(value_size++) = "MemoryPlane0BitEXT";
	}
	if (flags & MemoryPlane1BitEXT) {
		value_data.at(value_size++) = "MemoryPlane1BitEXT";
	}
	if (flags & MemoryPlane2BitEXT) {
		value_data.at(value_size++) = "MemoryPlane2BitEXT";
	}
	if (flags & MemoryPlane3BitEXT) {
		value_data.at(value_size++) = "MemoryPlane3BitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageCompressionFixedRateFlagsEXT flags) -> std::string {
	using enum ImageCompressionFixedRateBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ImageCompressionFixedRateBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 26> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & v1Bpc) {
		value_data.at(value_size++) = "v1Bpc";
	}
	if (flags & v2Bpc) {
		value_data.at(value_size++) = "v2Bpc";
	}
	if (flags & v3Bpc) {
		value_data.at(value_size++) = "v3Bpc";
	}
	if (flags & v4Bpc) {
		value_data.at(value_size++) = "v4Bpc";
	}
	if (flags & v5Bpc) {
		value_data.at(value_size++) = "v5Bpc";
	}
	if (flags & v6Bpc) {
		value_data.at(value_size++) = "v6Bpc";
	}
	if (flags & v7Bpc) {
		value_data.at(value_size++) = "v7Bpc";
	}
	if (flags & v8Bpc) {
		value_data.at(value_size++) = "v8Bpc";
	}
	if (flags & v9Bpc) {
		value_data.at(value_size++) = "v9Bpc";
	}
	if (flags & v10Bpc) {
		value_data.at(value_size++) = "v10Bpc";
	}
	if (flags & v11Bpc) {
		value_data.at(value_size++) = "v11Bpc";
	}
	if (flags & v12Bpc) {
		value_data.at(value_size++) = "v12Bpc";
	}
	if (flags & v13Bpc) {
		value_data.at(value_size++) = "v13Bpc";
	}
	if (flags & v14Bpc) {
		value_data.at(value_size++) = "v14Bpc";
	}
	if (flags & v15Bpc) {
		value_data.at(value_size++) = "v15Bpc";
	}
	if (flags & v16Bpc) {
		value_data.at(value_size++) = "v16Bpc";
	}
	if (flags & v17Bpc) {
		value_data.at(value_size++) = "v17Bpc";
	}
	if (flags & v18Bpc) {
		value_data.at(value_size++) = "v18Bpc";
	}
	if (flags & v19Bpc) {
		value_data.at(value_size++) = "v19Bpc";
	}
	if (flags & v20Bpc) {
		value_data.at(value_size++) = "v20Bpc";
	}
	if (flags & v21Bpc) {
		value_data.at(value_size++) = "v21Bpc";
	}
	if (flags & v22Bpc) {
		value_data.at(value_size++) = "v22Bpc";
	}
	if (flags & v23Bpc) {
		value_data.at(value_size++) = "v23Bpc";
	}
	if (flags & v24Bpc) {
		value_data.at(value_size++) = "v24Bpc";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageCompressionFlagsEXT flags) -> std::string {
	using enum ImageCompressionBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ImageCompressionBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Default) {
		value_data.at(value_size++) = "Default";
	}
	if (flags & FixedRateDefault) {
		value_data.at(value_size++) = "FixedRateDefault";
	}
	if (flags & FixedRateExplicit) {
		value_data.at(value_size++) = "FixedRateExplicit";
	}
	if (flags & Disabled) {
		value_data.at(value_size++) = "Disabled";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageConstraintsInfoFlagsFUCHSIA flags) -> std::string {
	using enum ImageConstraintsInfoBitsFUCHSIA;
	if ((flags & AllBits) != flags) {
		return "ImageConstraintsInfoBitsFUCHSIA does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & CpuReadRarely) {
		value_data.at(value_size++) = "CpuReadRarely";
	}
	if (flags & CpuReadOften) {
		value_data.at(value_size++) = "CpuReadOften";
	}
	if (flags & CpuWriteRarely) {
		value_data.at(value_size++) = "CpuWriteRarely";
	}
	if (flags & CpuWriteOften) {
		value_data.at(value_size++) = "CpuWriteOften";
	}
	if (flags & ProtectedOptional) {
		value_data.at(value_size++) = "ProtectedOptional";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageCreateFlags flags) -> std::string {
	using enum ImageCreateBits;
	if ((flags & AllBits) != flags) {
		return "ImageCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 22> value_data;
	if (flags & SparseBinding) {
		value_data.at(value_size++) = "SparseBinding";
	}
	if (flags & SparseResidency) {
		value_data.at(value_size++) = "SparseResidency";
	}
	if (flags & SparseAliased) {
		value_data.at(value_size++) = "SparseAliased";
	}
	if (flags & MutableFormat) {
		value_data.at(value_size++) = "MutableFormat";
	}
	if (flags & CubeCompatible) {
		value_data.at(value_size++) = "CubeCompatible";
	}
	if (flags & v2DArrayCompatible) {
		value_data.at(value_size++) = "v2DArrayCompatible";
	}
	if (flags & SplitInstanceBindRegions) {
		value_data.at(value_size++) = "SplitInstanceBindRegions";
	}
	if (flags & BlockTexelViewCompatible) {
		value_data.at(value_size++) = "BlockTexelViewCompatible";
	}
	if (flags & ExtendedUsage) {
		value_data.at(value_size++) = "ExtendedUsage";
	}
	if (flags & Disjoint) {
		value_data.at(value_size++) = "Disjoint";
	}
	if (flags & Alias) {
		value_data.at(value_size++) = "Alias";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & SampleLocationsCompatibleDepthBitEXT) {
		value_data.at(value_size++) = "SampleLocationsCompatibleDepthBitEXT";
	}
	if (flags & CornerSampledBitNV) {
		value_data.at(value_size++) = "CornerSampledBitNV";
	}
	if (flags & SubsampledBitEXT) {
		value_data.at(value_size++) = "SubsampledBitEXT";
	}
	if (flags & FragmentDensityMapOffsetBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapOffsetBitEXT";
	}
	if (flags & DescriptorHeapCaptureReplayBitEXT) {
		value_data.at(value_size++) = "DescriptorHeapCaptureReplayBitEXT";
	}
	if (flags & v2DViewCompatibleBitEXT) {
		value_data.at(value_size++) = "v2DViewCompatibleBitEXT";
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		value_data.at(value_size++) = "MultisampledRenderToSingleSampledBitEXT";
	}
	if (flags & VideoProfileIndependentBitKHR) {
		value_data.at(value_size++) = "VideoProfileIndependentBitKHR";
	}
	if (flags & AliasSingleLayerDescriptorBitKHR) {
		value_data.at(value_size++) = "AliasSingleLayerDescriptorBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageCreateFlags2KHR flags) -> std::string {
	using enum ImageCreateBits2KHR;
	if ((flags & AllBits) != flags) {
		return "ImageCreateBits2KHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 22> value_data;
	if (flags & SparseBinding) {
		value_data.at(value_size++) = "SparseBinding";
	}
	if (flags & SparseResidency) {
		value_data.at(value_size++) = "SparseResidency";
	}
	if (flags & SparseAliased) {
		value_data.at(value_size++) = "SparseAliased";
	}
	if (flags & MutableFormat) {
		value_data.at(value_size++) = "MutableFormat";
	}
	if (flags & CubeCompatible) {
		value_data.at(value_size++) = "CubeCompatible";
	}
	if (flags & v2DArrayCompatible) {
		value_data.at(value_size++) = "v2DArrayCompatible";
	}
	if (flags & SplitInstanceBindRegions) {
		value_data.at(value_size++) = "SplitInstanceBindRegions";
	}
	if (flags & BlockTexelViewCompatible) {
		value_data.at(value_size++) = "BlockTexelViewCompatible";
	}
	if (flags & ExtendedUsage) {
		value_data.at(value_size++) = "ExtendedUsage";
	}
	if (flags & Disjoint) {
		value_data.at(value_size++) = "Disjoint";
	}
	if (flags & Alias) {
		value_data.at(value_size++) = "Alias";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & SampleLocationsCompatibleDepthBitEXT) {
		value_data.at(value_size++) = "SampleLocationsCompatibleDepthBitEXT";
	}
	if (flags & CornerSampledBitNV) {
		value_data.at(value_size++) = "CornerSampledBitNV";
	}
	if (flags & SubsampledBitEXT) {
		value_data.at(value_size++) = "SubsampledBitEXT";
	}
	if (flags & FragmentDensityMapOffsetBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapOffsetBitEXT";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferCaptureReplayBitEXT";
	}
	if (flags & v2DViewCompatibleBitEXT) {
		value_data.at(value_size++) = "v2DViewCompatibleBitEXT";
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		value_data.at(value_size++) = "MultisampledRenderToSingleSampledBitEXT";
	}
	if (flags & VideoProfileIndependent) {
		value_data.at(value_size++) = "VideoProfileIndependent";
	}
	if (flags & AliasSingleLayerDescriptor) {
		value_data.at(value_size++) = "AliasSingleLayerDescriptor";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageFormatConstraintsFlagsFUCHSIA flags) -> std::string {
	if (flags) {
		return "ImageFormatConstraintsFlagsFUCHSIA has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ImagePipeSurfaceCreateFlagsFUCHSIA flags) -> std::string {
	if (flags) {
		return "ImagePipeSurfaceCreateFlagsFUCHSIA has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ImageUsageFlags flags) -> std::string {
	using enum ImageUsageBits;
	if ((flags & AllBits) != flags) {
		return "ImageUsageBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 26> value_data;
	if (flags & TransferSrc) {
		value_data.at(value_size++) = "TransferSrc";
	}
	if (flags & TransferDst) {
		value_data.at(value_size++) = "TransferDst";
	}
	if (flags & Sampled) {
		value_data.at(value_size++) = "Sampled";
	}
	if (flags & Storage) {
		value_data.at(value_size++) = "Storage";
	}
	if (flags & ColorAttachment) {
		value_data.at(value_size++) = "ColorAttachment";
	}
	if (flags & DepthStencilAttachment) {
		value_data.at(value_size++) = "DepthStencilAttachment";
	}
	if (flags & TransientAttachment) {
		value_data.at(value_size++) = "TransientAttachment";
	}
	if (flags & InputAttachment) {
		value_data.at(value_size++) = "InputAttachment";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		value_data.at(value_size++) = "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & FragmentDensityMapBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeDstBitKHR) {
		value_data.at(value_size++) = "VideoDecodeDstBitKHR";
	}
	if (flags & VideoDecodeSrcBitKHR) {
		value_data.at(value_size++) = "VideoDecodeSrcBitKHR";
	}
	if (flags & VideoDecodeDpbBitKHR) {
		value_data.at(value_size++) = "VideoDecodeDpbBitKHR";
	}
	if (flags & VideoEncodeDstBitKHR) {
		value_data.at(value_size++) = "VideoEncodeDstBitKHR";
	}
	if (flags & VideoEncodeSrcBitKHR) {
		value_data.at(value_size++) = "VideoEncodeSrcBitKHR";
	}
	if (flags & VideoEncodeDpbBitKHR) {
		value_data.at(value_size++) = "VideoEncodeDpbBitKHR";
	}
	if (flags & InvocationMaskBitHUAWEI) {
		value_data.at(value_size++) = "InvocationMaskBitHUAWEI";
	}
	if (flags & AttachmentFeedbackLoopBitEXT) {
		value_data.at(value_size++) = "AttachmentFeedbackLoopBitEXT";
	}
	if (flags & SampleWeightBitQCOM) {
		value_data.at(value_size++) = "SampleWeightBitQCOM";
	}
	if (flags & SampleBlockMatchBitQCOM) {
		value_data.at(value_size++) = "SampleBlockMatchBitQCOM";
	}
	if (flags & HostTransfer) {
		value_data.at(value_size++) = "HostTransfer";
	}
	if (flags & TensorAliasingBitARM) {
		value_data.at(value_size++) = "TensorAliasingBitARM";
	}
	if (flags & VideoEncodeQuantizationDeltaMapBitKHR) {
		value_data.at(value_size++) = "VideoEncodeQuantizationDeltaMapBitKHR";
	}
	if (flags & VideoEncodeEmphasisMapBitKHR) {
		value_data.at(value_size++) = "VideoEncodeEmphasisMapBitKHR";
	}
	if (flags & TileMemoryBitQCOM) {
		value_data.at(value_size++) = "TileMemoryBitQCOM";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageUsageFlags2KHR flags) -> std::string {
	using enum ImageUsageBits2KHR;
	if ((flags & AllBits) != flags) {
		return "ImageUsageBits2KHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 26> value_data;
	if (flags & TransferSrc) {
		value_data.at(value_size++) = "TransferSrc";
	}
	if (flags & TransferDst) {
		value_data.at(value_size++) = "TransferDst";
	}
	if (flags & Sampled) {
		value_data.at(value_size++) = "Sampled";
	}
	if (flags & Storage) {
		value_data.at(value_size++) = "Storage";
	}
	if (flags & ColorAttachment) {
		value_data.at(value_size++) = "ColorAttachment";
	}
	if (flags & DepthStencilAttachment) {
		value_data.at(value_size++) = "DepthStencilAttachment";
	}
	if (flags & TransientAttachment) {
		value_data.at(value_size++) = "TransientAttachment";
	}
	if (flags & InputAttachment) {
		value_data.at(value_size++) = "InputAttachment";
	}
	if (flags & FragmentShadingRateAttachment) {
		value_data.at(value_size++) = "FragmentShadingRateAttachment";
	}
	if (flags & FragmentDensityMapBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeDst) {
		value_data.at(value_size++) = "VideoDecodeDst";
	}
	if (flags & VideoDecodeSrc) {
		value_data.at(value_size++) = "VideoDecodeSrc";
	}
	if (flags & VideoDecodeDpb) {
		value_data.at(value_size++) = "VideoDecodeDpb";
	}
	if (flags & VideoEncodeDst) {
		value_data.at(value_size++) = "VideoEncodeDst";
	}
	if (flags & VideoEncodeSrc) {
		value_data.at(value_size++) = "VideoEncodeSrc";
	}
	if (flags & VideoEncodeDpb) {
		value_data.at(value_size++) = "VideoEncodeDpb";
	}
	if (flags & InvocationMaskBitHUAWEI) {
		value_data.at(value_size++) = "InvocationMaskBitHUAWEI";
	}
	if (flags & AttachmentFeedbackLoopBitEXT) {
		value_data.at(value_size++) = "AttachmentFeedbackLoopBitEXT";
	}
	if (flags & SampleWeightBitQCOM) {
		value_data.at(value_size++) = "SampleWeightBitQCOM";
	}
	if (flags & SampleBlockMatchBitQCOM) {
		value_data.at(value_size++) = "SampleBlockMatchBitQCOM";
	}
	if (flags & HostTransfer) {
		value_data.at(value_size++) = "HostTransfer";
	}
	if (flags & TensorAliasingBitARM) {
		value_data.at(value_size++) = "TensorAliasingBitARM";
	}
	if (flags & VideoEncodeQuantizationDeltaMap) {
		value_data.at(value_size++) = "VideoEncodeQuantizationDeltaMap";
	}
	if (flags & VideoEncodeEmphasisMap) {
		value_data.at(value_size++) = "VideoEncodeEmphasisMap";
	}
	if (flags & TileMemoryBitQCOM) {
		value_data.at(value_size++) = "TileMemoryBitQCOM";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ImageViewCreateFlags flags) -> std::string {
	using enum ImageViewCreateBits;
	if ((flags & AllBits) != flags) {
		return "ImageViewCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & FragmentDensityMapDynamicBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapDynamicBitEXT";
	}
	if (flags & FragmentDensityMapDeferredBitEXT) {
		value_data.at(value_size++) = "FragmentDensityMapDeferredBitEXT";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferCaptureReplayBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(IndirectCommandsInputModeFlagsEXT flags) -> std::string {
	using enum IndirectCommandsInputModeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "IndirectCommandsInputModeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & VulkanIndexBuffer) {
		value_data.at(value_size++) = "VulkanIndexBuffer";
	}
	if (flags & DxgiIndexBuffer) {
		value_data.at(value_size++) = "DxgiIndexBuffer";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(IndirectCommandsLayoutUsageFlagsEXT flags) -> std::string {
	using enum IndirectCommandsLayoutUsageBitsEXT;
	if ((flags & AllBits) != flags) {
		return "IndirectCommandsLayoutUsageBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & ExplicitPreprocess) {
		value_data.at(value_size++) = "ExplicitPreprocess";
	}
	if (flags & UnorderedSequences) {
		value_data.at(value_size++) = "UnorderedSequences";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(IndirectCommandsLayoutUsageFlagsNV flags) -> std::string {
	using enum IndirectCommandsLayoutUsageBitsNV;
	if ((flags & AllBits) != flags) {
		return "IndirectCommandsLayoutUsageBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & ExplicitPreprocess) {
		value_data.at(value_size++) = "ExplicitPreprocess";
	}
	if (flags & IndexedSequences) {
		value_data.at(value_size++) = "IndexedSequences";
	}
	if (flags & UnorderedSequences) {
		value_data.at(value_size++) = "UnorderedSequences";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(IndirectStateFlagsNV flags) -> std::string {
	using enum IndirectStateBitsNV;
	if ((flags & AllBits) != flags) {
		return "IndirectStateBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & FlagFrontface) {
		value_data.at(value_size++) = "FlagFrontface";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(InstanceCreateFlags flags) -> std::string {
	using enum InstanceCreateBits;
	if ((flags & AllBits) != flags) {
		return "InstanceCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & EnumeratePortabilityBitKHR) {
		value_data.at(value_size++) = "EnumeratePortabilityBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(MacOSSurfaceCreateFlagsMVK flags) -> std::string {
	if (flags) {
		return "MacOSSurfaceCreateFlagsMVK has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(MemoryAllocateFlags flags) -> std::string {
	using enum MemoryAllocateBits;
	if ((flags & AllBits) != flags) {
		return "MemoryAllocateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & DeviceMask) {
		value_data.at(value_size++) = "DeviceMask";
	}
	if (flags & DeviceAddress) {
		value_data.at(value_size++) = "DeviceAddress";
	}
	if (flags & DeviceAddressCaptureReplay) {
		value_data.at(value_size++) = "DeviceAddressCaptureReplay";
	}
	if (flags & ZeroInitializeBitEXT) {
		value_data.at(value_size++) = "ZeroInitializeBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(MemoryDecompressionMethodFlagsEXT flags) -> std::string {
	using enum MemoryDecompressionMethodBitsEXT;
	if ((flags & AllBits) != flags) {
		return "MemoryDecompressionMethodBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Gdeflate10) {
		value_data.at(value_size++) = "Gdeflate10";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(MemoryHeapFlags flags) -> std::string {
	using enum MemoryHeapBits;
	if ((flags & AllBits) != flags) {
		return "MemoryHeapBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & DeviceLocal) {
		value_data.at(value_size++) = "DeviceLocal";
	}
	if (flags & MultiInstance) {
		value_data.at(value_size++) = "MultiInstance";
	}
	if (flags & TileMemoryBitQCOM) {
		value_data.at(value_size++) = "TileMemoryBitQCOM";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(MemoryMapFlags flags) -> std::string {
	using enum MemoryMapBits;
	if ((flags & AllBits) != flags) {
		return "MemoryMapBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & PlacedBitEXT) {
		value_data.at(value_size++) = "PlacedBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(MemoryPropertyFlags flags) -> std::string {
	using enum MemoryPropertyBits;
	if ((flags & AllBits) != flags) {
		return "MemoryPropertyBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 10> value_data;
	if (flags & DeviceLocal) {
		value_data.at(value_size++) = "DeviceLocal";
	}
	if (flags & HostVisible) {
		value_data.at(value_size++) = "HostVisible";
	}
	if (flags & HostCoherent) {
		value_data.at(value_size++) = "HostCoherent";
	}
	if (flags & HostCached) {
		value_data.at(value_size++) = "HostCached";
	}
	if (flags & LazilyAllocated) {
		value_data.at(value_size++) = "LazilyAllocated";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & DeviceCoherentBitAMD) {
		value_data.at(value_size++) = "DeviceCoherentBitAMD";
	}
	if (flags & DeviceUncachedBitAMD) {
		value_data.at(value_size++) = "DeviceUncachedBitAMD";
	}
	if (flags & RdmaCapableBitNV) {
		value_data.at(value_size++) = "RdmaCapableBitNV";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(MemoryUnmapFlags flags) -> std::string {
	using enum MemoryUnmapBits;
	if ((flags & AllBits) != flags) {
		return "MemoryUnmapBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & ReserveBitEXT) {
		value_data.at(value_size++) = "ReserveBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(MetalSurfaceCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "MetalSurfaceCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(MicromapCreateFlagsEXT flags) -> std::string {
	using enum MicromapCreateBitsEXT;
	if ((flags & AllBits) != flags) {
		return "MicromapCreateBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & DeviceAddressCaptureReplay) {
		value_data.at(value_size++) = "DeviceAddressCaptureReplay";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(OpticalFlowExecuteFlagsNV flags) -> std::string {
	using enum OpticalFlowExecuteBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowExecuteBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & DisableTemporalHints) {
		value_data.at(value_size++) = "DisableTemporalHints";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(OpticalFlowGridSizeFlagsNV flags) -> std::string {
	using enum OpticalFlowGridSizeBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowGridSizeBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & Unknown) {
		value_data.at(value_size++) = "Unknown";
	}
	if (flags & v1x1) {
		value_data.at(value_size++) = "v1x1";
	}
	if (flags & v2x2) {
		value_data.at(value_size++) = "v2x2";
	}
	if (flags & v4x4) {
		value_data.at(value_size++) = "v4x4";
	}
	if (flags & v8x8) {
		value_data.at(value_size++) = "v8x8";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(OpticalFlowSessionCreateFlagsNV flags) -> std::string {
	using enum OpticalFlowSessionCreateBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowSessionCreateBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & EnableHint) {
		value_data.at(value_size++) = "EnableHint";
	}
	if (flags & EnableCost) {
		value_data.at(value_size++) = "EnableCost";
	}
	if (flags & EnableGlobalFlow) {
		value_data.at(value_size++) = "EnableGlobalFlow";
	}
	if (flags & AllowRegions) {
		value_data.at(value_size++) = "AllowRegions";
	}
	if (flags & BothDirections) {
		value_data.at(value_size++) = "BothDirections";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(OpticalFlowUsageFlagsNV flags) -> std::string {
	using enum OpticalFlowUsageBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowUsageBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & Unknown) {
		value_data.at(value_size++) = "Unknown";
	}
	if (flags & Input) {
		value_data.at(value_size++) = "Input";
	}
	if (flags & Output) {
		value_data.at(value_size++) = "Output";
	}
	if (flags & Hint) {
		value_data.at(value_size++) = "Hint";
	}
	if (flags & Cost) {
		value_data.at(value_size++) = "Cost";
	}
	if (flags & GlobalFlow) {
		value_data.at(value_size++) = "GlobalFlow";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PartitionedAccelerationStructureInstanceFlagsNV flags) -> std::string {
	using enum PartitionedAccelerationStructureInstanceBitsNV;
	if ((flags & AllBits) != flags) {
		return "PartitionedAccelerationStructureInstanceBitsNV does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & FlagTriangleFacingCullDisable) {
		value_data.at(value_size++) = "FlagTriangleFacingCullDisable";
	}
	if (flags & FlagTriangleFlipFacing) {
		value_data.at(value_size++) = "FlagTriangleFlipFacing";
	}
	if (flags & FlagForceOpaque) {
		value_data.at(value_size++) = "FlagForceOpaque";
	}
	if (flags & FlagForceNoOpaque) {
		value_data.at(value_size++) = "FlagForceNoOpaque";
	}
	if (flags & FlagEnableExplicitBoundingBox) {
		value_data.at(value_size++) = "FlagEnableExplicitBoundingBox";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PastPresentationTimingFlagsEXT flags) -> std::string {
	using enum PastPresentationTimingBitsEXT;
	if ((flags & AllBits) != flags) {
		return "PastPresentationTimingBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & AllowPartialResults) {
		value_data.at(value_size++) = "AllowPartialResults";
	}
	if (flags & AllowOutOfOrderResults) {
		value_data.at(value_size++) = "AllowOutOfOrderResults";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PeerMemoryFeatureFlags flags) -> std::string {
	using enum PeerMemoryFeatureBits;
	if ((flags & AllBits) != flags) {
		return "PeerMemoryFeatureBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & CopySrc) {
		value_data.at(value_size++) = "CopySrc";
	}
	if (flags & CopyDst) {
		value_data.at(value_size++) = "CopyDst";
	}
	if (flags & GenericSrc) {
		value_data.at(value_size++) = "GenericSrc";
	}
	if (flags & GenericDst) {
		value_data.at(value_size++) = "GenericDst";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PerformanceCounterDescriptionFlagsARM flags) -> std::string {
	if (flags) {
		return "PerformanceCounterDescriptionFlagsARM has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PerformanceCounterDescriptionFlagsKHR flags) -> std::string {
	using enum PerformanceCounterDescriptionBitsKHR;
	if ((flags & AllBits) != flags) {
		return "PerformanceCounterDescriptionBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & PerformanceImpacting) {
		value_data.at(value_size++) = "PerformanceImpacting";
	}
	if (flags & ConcurrentlyImpacted) {
		value_data.at(value_size++) = "ConcurrentlyImpacted";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PhysicalDeviceGpaPropertiesFlagsAMD flags) -> std::string {
	if (flags) {
		return "PhysicalDeviceGpaPropertiesFlagsAMD has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PhysicalDeviceSchedulingControlsFlagsARM flags) -> std::string {
	using enum PhysicalDeviceSchedulingControlsBitsARM;
	if ((flags & AllBits) != flags) {
		return "PhysicalDeviceSchedulingControlsBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & ShaderCoreCount) {
		value_data.at(value_size++) = "ShaderCoreCount";
	}
	if (flags & DispatchParameters) {
		value_data.at(value_size++) = "DispatchParameters";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineCacheCreateFlags flags) -> std::string {
	using enum PipelineCacheCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineCacheCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & ExternallySynchronized) {
		value_data.at(value_size++) = "ExternallySynchronized";
	}
	if (flags & InternallySynchronizedMergeBitKHR) {
		value_data.at(value_size++) = "InternallySynchronizedMergeBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineColorBlendStateCreateFlags flags) -> std::string {
	using enum PipelineColorBlendStateCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineColorBlendStateCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & RasterizationOrderAttachmentAccessBitEXT) {
		value_data.at(value_size++) = "RasterizationOrderAttachmentAccessBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineCompilerControlFlagsAMD flags) -> std::string {
	if (flags) {
		return "PipelineCompilerControlFlagsAMD has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineCoverageModulationStateCreateFlagsNV flags) -> std::string {
	if (flags) {
		return "PipelineCoverageModulationStateCreateFlagsNV has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineCoverageReductionStateCreateFlagsNV flags) -> std::string {
	if (flags) {
		return "PipelineCoverageReductionStateCreateFlagsNV has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineCoverageToColorStateCreateFlagsNV flags) -> std::string {
	if (flags) {
		return "PipelineCoverageToColorStateCreateFlagsNV has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineCreateFlags flags) -> std::string {
	using enum PipelineCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 32> value_data;
	if (flags & DisableOptimization) {
		value_data.at(value_size++) = "DisableOptimization";
	}
	if (flags & AllowDerivatives) {
		value_data.at(value_size++) = "AllowDerivatives";
	}
	if (flags & Derivative) {
		value_data.at(value_size++) = "Derivative";
	}
	if (flags & ViewIndexFromDeviceIndex) {
		value_data.at(value_size++) = "ViewIndexFromDeviceIndex";
	}
	if (flags & DispatchBase) {
		value_data.at(value_size++) = "DispatchBase";
	}
	if (flags & DeferCompileBitNV) {
		value_data.at(value_size++) = "DeferCompileBitNV";
	}
	if (flags & CaptureStatisticsBitKHR) {
		value_data.at(value_size++) = "CaptureStatisticsBitKHR";
	}
	if (flags & CaptureInternalRepresentationsBitKHR) {
		value_data.at(value_size++) = "CaptureInternalRepresentationsBitKHR";
	}
	if (flags & FailOnPipelineCompileRequired) {
		value_data.at(value_size++) = "FailOnPipelineCompileRequired";
	}
	if (flags & EarlyReturnOnFailure) {
		value_data.at(value_size++) = "EarlyReturnOnFailure";
	}
	if (flags & LinkTimeOptimizationBitEXT) {
		value_data.at(value_size++) = "LinkTimeOptimizationBitEXT";
	}
	if (flags & LibraryBitKHR) {
		value_data.at(value_size++) = "LibraryBitKHR";
	}
	if (flags & RayTracingSkipTrianglesBitKHR) {
		value_data.at(value_size++) = "RayTracingSkipTrianglesBitKHR";
	}
	if (flags & RayTracingSkipAabbsBitKHR) {
		value_data.at(value_size++) = "RayTracingSkipAabbsBitKHR";
	}
	if (flags & RayTracingNoNullAnyHitShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullAnyHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullClosestHitShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullClosestHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullMissShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullMissShadersBitKHR";
	}
	if (flags & RayTracingNoNullIntersectionShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullIntersectionShadersBitKHR";
	}
	if (flags & IndirectBindableBitNV) {
		value_data.at(value_size++) = "IndirectBindableBitNV";
	}
	if (flags & RayTracingShaderGroupHandleCaptureReplayBitKHR) {
		value_data.at(value_size++) = "RayTracingShaderGroupHandleCaptureReplayBitKHR";
	}
	if (flags & RayTracingAllowMotionBitNV) {
		value_data.at(value_size++) = "RayTracingAllowMotionBitNV";
	}
	if (flags & RenderingFragmentShadingRateAttachmentBitKHR) {
		value_data.at(value_size++) = "RenderingFragmentShadingRateAttachmentBitKHR";
	}
	if (flags & RenderingFragmentDensityMapAttachmentBitEXT) {
		value_data.at(value_size++) = "RenderingFragmentDensityMapAttachmentBitEXT";
	}
	if (flags & RetainLinkTimeOptimizationInfoBitEXT) {
		value_data.at(value_size++) = "RetainLinkTimeOptimizationInfoBitEXT";
	}
	if (flags & RayTracingOpacityMicromapBitKHR) {
		value_data.at(value_size++) = "RayTracingOpacityMicromapBitKHR";
	}
	if (flags & ColorAttachmentFeedbackLoopBitEXT) {
		value_data.at(value_size++) = "ColorAttachmentFeedbackLoopBitEXT";
	}
	if (flags & DepthStencilAttachmentFeedbackLoopBitEXT) {
		value_data.at(value_size++) = "DepthStencilAttachmentFeedbackLoopBitEXT";
	}
	if (flags & NoProtectedAccess) {
		value_data.at(value_size++) = "NoProtectedAccess";
	}
	if (flags & RayTracingDisplacementMicromapBitNV) {
		value_data.at(value_size++) = "RayTracingDisplacementMicromapBitNV";
	}
	if (flags & DescriptorBufferBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferBitEXT";
	}
	if (flags & ProtectedAccessOnly) {
		value_data.at(value_size++) = "ProtectedAccessOnly";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineCreateFlags2 flags) -> std::string {
	using enum PipelineCreateBits2;
	if ((flags & AllBits) != flags) {
		return "PipelineCreateBits2 does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 43> value_data;
	if (flags & DisableOptimization) {
		value_data.at(value_size++) = "DisableOptimization";
	}
	if (flags & AllowDerivatives) {
		value_data.at(value_size++) = "AllowDerivatives";
	}
	if (flags & Derivative) {
		value_data.at(value_size++) = "Derivative";
	}
	if (flags & ViewIndexFromDeviceIndex) {
		value_data.at(value_size++) = "ViewIndexFromDeviceIndex";
	}
	if (flags & DispatchBase) {
		value_data.at(value_size++) = "DispatchBase";
	}
	if (flags & DeferCompileBitNV) {
		value_data.at(value_size++) = "DeferCompileBitNV";
	}
	if (flags & CaptureStatisticsBitKHR) {
		value_data.at(value_size++) = "CaptureStatisticsBitKHR";
	}
	if (flags & CaptureInternalRepresentationsBitKHR) {
		value_data.at(value_size++) = "CaptureInternalRepresentationsBitKHR";
	}
	if (flags & FailOnPipelineCompileRequired) {
		value_data.at(value_size++) = "FailOnPipelineCompileRequired";
	}
	if (flags & EarlyReturnOnFailure) {
		value_data.at(value_size++) = "EarlyReturnOnFailure";
	}
	if (flags & LinkTimeOptimizationBitEXT) {
		value_data.at(value_size++) = "LinkTimeOptimizationBitEXT";
	}
	if (flags & LibraryBitKHR) {
		value_data.at(value_size++) = "LibraryBitKHR";
	}
	if (flags & RayTracingSkipTrianglesBitKHR) {
		value_data.at(value_size++) = "RayTracingSkipTrianglesBitKHR";
	}
	if (flags & RayTracingSkipAabbsBitKHR) {
		value_data.at(value_size++) = "RayTracingSkipAabbsBitKHR";
	}
	if (flags & RayTracingNoNullAnyHitShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullAnyHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullClosestHitShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullClosestHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullMissShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullMissShadersBitKHR";
	}
	if (flags & RayTracingNoNullIntersectionShadersBitKHR) {
		value_data.at(value_size++) = "RayTracingNoNullIntersectionShadersBitKHR";
	}
	if (flags & IndirectBindableBitNV) {
		value_data.at(value_size++) = "IndirectBindableBitNV";
	}
	if (flags & RayTracingShaderGroupHandleCaptureReplayBitKHR) {
		value_data.at(value_size++) = "RayTracingShaderGroupHandleCaptureReplayBitKHR";
	}
	if (flags & RayTracingAllowMotionBitNV) {
		value_data.at(value_size++) = "RayTracingAllowMotionBitNV";
	}
	if (flags & RenderingFragmentShadingRateAttachmentBitKHR) {
		value_data.at(value_size++) = "RenderingFragmentShadingRateAttachmentBitKHR";
	}
	if (flags & RenderingFragmentDensityMapAttachmentBitEXT) {
		value_data.at(value_size++) = "RenderingFragmentDensityMapAttachmentBitEXT";
	}
	if (flags & RetainLinkTimeOptimizationInfoBitEXT) {
		value_data.at(value_size++) = "RetainLinkTimeOptimizationInfoBitEXT";
	}
	if (flags & RayTracingOpacityMicromapBitKHR) {
		value_data.at(value_size++) = "RayTracingOpacityMicromapBitKHR";
	}
	if (flags & ColorAttachmentFeedbackLoopBitEXT) {
		value_data.at(value_size++) = "ColorAttachmentFeedbackLoopBitEXT";
	}
	if (flags & DepthStencilAttachmentFeedbackLoopBitEXT) {
		value_data.at(value_size++) = "DepthStencilAttachmentFeedbackLoopBitEXT";
	}
	if (flags & NoProtectedAccess) {
		value_data.at(value_size++) = "NoProtectedAccess";
	}
	if (flags & RayTracingDisplacementMicromapBitNV) {
		value_data.at(value_size++) = "RayTracingDisplacementMicromapBitNV";
	}
	if (flags & DescriptorBufferBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferBitEXT";
	}
	if (flags & ProtectedAccessOnly) {
		value_data.at(value_size++) = "ProtectedAccessOnly";
	}
	if (flags & CaptureDataBitKHR) {
		value_data.at(value_size++) = "CaptureDataBitKHR";
	}
	if (flags & ExecutionGraphBitAMDX) {
		value_data.at(value_size++) = "ExecutionGraphBitAMDX";
	}
	if (flags & RayTracingAllowSpheresAndLinearSweptSpheresBitNV) {
		value_data.at(value_size++) = "RayTracingAllowSpheresAndLinearSweptSpheresBitNV";
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		value_data.at(value_size++) = "EnableLegacyDitheringBitEXT";
	}
	if (flags & DescriptorHeapBitEXT) {
		value_data.at(value_size++) = "DescriptorHeapBitEXT";
	}
	if (flags & DisallowOpacityMicromapBitARM) {
		value_data.at(value_size++) = "DisallowOpacityMicromapBitARM";
	}
	if (flags & IndirectBindableBitEXT) {
		value_data.at(value_size++) = "IndirectBindableBitEXT";
	}
	if (flags & InstrumentShadersBitARM) {
		value_data.at(value_size++) = "InstrumentShadersBitARM";
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		value_data.at(value_size++) = "PerLayerFragmentDensityBitVALVE";
	}
	if (flags & OpacityMicromapDisallowMixedSpecialIndexBitKHR) {
		value_data.at(value_size++) = "OpacityMicromapDisallowMixedSpecialIndexBitKHR";
	}
	if (flags & v64BitIndexingBitEXT) {
		value_data.at(value_size++) = "v64BitIndexingBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineCreationFeedbackFlags flags) -> std::string {
	using enum PipelineCreationFeedbackBits;
	if ((flags & AllBits) != flags) {
		return "PipelineCreationFeedbackBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & Valid) {
		value_data.at(value_size++) = "Valid";
	}
	if (flags & ApplicationPipelineCacheHit) {
		value_data.at(value_size++) = "ApplicationPipelineCacheHit";
	}
	if (flags & BasePipelineAcceleration) {
		value_data.at(value_size++) = "BasePipelineAcceleration";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineDepthStencilStateCreateFlags flags) -> std::string {
	using enum PipelineDepthStencilStateCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineDepthStencilStateCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & RasterizationOrderAttachmentDepthAccessBitEXT) {
		value_data.at(value_size++) = "RasterizationOrderAttachmentDepthAccessBitEXT";
	}
	if (flags & RasterizationOrderAttachmentStencilAccessBitEXT) {
		value_data.at(value_size++) = "RasterizationOrderAttachmentStencilAccessBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineDiscardRectangleStateCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "PipelineDiscardRectangleStateCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineDynamicStateCreateFlags flags) -> std::string {
	if (flags) {
		return "PipelineDynamicStateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineInputAssemblyStateCreateFlags flags) -> std::string {
	if (flags) {
		return "PipelineInputAssemblyStateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineLayoutCreateFlags flags) -> std::string {
	using enum PipelineLayoutCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineLayoutCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & IndependentSetsBitEXT) {
		value_data.at(value_size++) = "IndependentSetsBitEXT";
	}
	if (flags & NoTaskShaderBitKHR) {
		value_data.at(value_size++) = "NoTaskShaderBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineMultisampleStateCreateFlags flags) -> std::string {
	if (flags) {
		return "PipelineMultisampleStateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineRasterizationConservativeStateCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "PipelineRasterizationConservativeStateCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineRasterizationDepthClipStateCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "PipelineRasterizationDepthClipStateCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineRasterizationStateCreateFlags flags) -> std::string {
	if (flags) {
		return "PipelineRasterizationStateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineRasterizationStateStreamCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "PipelineRasterizationStateStreamCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineShaderStageCreateFlags flags) -> std::string {
	using enum PipelineShaderStageCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineShaderStageCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & AllowVaryingSubgroupSize) {
		value_data.at(value_size++) = "AllowVaryingSubgroupSize";
	}
	if (flags & RequireFullSubgroups) {
		value_data.at(value_size++) = "RequireFullSubgroups";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineStageFlags flags) -> std::string {
	using enum PipelineStageBits;
	if ((flags & AllBits) != flags) {
		return "PipelineStageBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 28> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & TopOfPipe) {
		value_data.at(value_size++) = "TopOfPipe";
	}
	if (flags & DrawIndirect) {
		value_data.at(value_size++) = "DrawIndirect";
	}
	if (flags & VertexInput) {
		value_data.at(value_size++) = "VertexInput";
	}
	if (flags & VertexShader) {
		value_data.at(value_size++) = "VertexShader";
	}
	if (flags & TessellationControlShader) {
		value_data.at(value_size++) = "TessellationControlShader";
	}
	if (flags & TessellationEvaluationShader) {
		value_data.at(value_size++) = "TessellationEvaluationShader";
	}
	if (flags & GeometryShader) {
		value_data.at(value_size++) = "GeometryShader";
	}
	if (flags & FragmentShader) {
		value_data.at(value_size++) = "FragmentShader";
	}
	if (flags & EarlyFragmentTests) {
		value_data.at(value_size++) = "EarlyFragmentTests";
	}
	if (flags & LateFragmentTests) {
		value_data.at(value_size++) = "LateFragmentTests";
	}
	if (flags & ColorAttachmentOutput) {
		value_data.at(value_size++) = "ColorAttachmentOutput";
	}
	if (flags & ComputeShader) {
		value_data.at(value_size++) = "ComputeShader";
	}
	if (flags & Transfer) {
		value_data.at(value_size++) = "Transfer";
	}
	if (flags & BottomOfPipe) {
		value_data.at(value_size++) = "BottomOfPipe";
	}
	if (flags & Host) {
		value_data.at(value_size++) = "Host";
	}
	if (flags & AllGraphics) {
		value_data.at(value_size++) = "AllGraphics";
	}
	if (flags & AllCommands) {
		value_data.at(value_size++) = "AllCommands";
	}
	if (flags & CommandPreprocessBitEXT) {
		value_data.at(value_size++) = "CommandPreprocessBitEXT";
	}
	if (flags & ConditionalRenderingBitEXT) {
		value_data.at(value_size++) = "ConditionalRenderingBitEXT";
	}
	if (flags & TaskShaderBitEXT) {
		value_data.at(value_size++) = "TaskShaderBitEXT";
	}
	if (flags & MeshShaderBitEXT) {
		value_data.at(value_size++) = "MeshShaderBitEXT";
	}
	if (flags & RayTracingShaderBitKHR) {
		value_data.at(value_size++) = "RayTracingShaderBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		value_data.at(value_size++) = "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & FragmentDensityProcessBitEXT) {
		value_data.at(value_size++) = "FragmentDensityProcessBitEXT";
	}
	if (flags & TransformFeedbackBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackBitEXT";
	}
	if (flags & AccelerationStructureBuildBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureBuildBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineStageFlags2 flags) -> std::string {
	using enum PipelineStageBits2;
	if ((flags & AllBits) != flags) {
		return "PipelineStageBits2 does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 47> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & TopOfPipe) {
		value_data.at(value_size++) = "TopOfPipe";
	}
	if (flags & DrawIndirect) {
		value_data.at(value_size++) = "DrawIndirect";
	}
	if (flags & VertexInput) {
		value_data.at(value_size++) = "VertexInput";
	}
	if (flags & VertexShader) {
		value_data.at(value_size++) = "VertexShader";
	}
	if (flags & TessellationControlShader) {
		value_data.at(value_size++) = "TessellationControlShader";
	}
	if (flags & TessellationEvaluationShader) {
		value_data.at(value_size++) = "TessellationEvaluationShader";
	}
	if (flags & GeometryShader) {
		value_data.at(value_size++) = "GeometryShader";
	}
	if (flags & FragmentShader) {
		value_data.at(value_size++) = "FragmentShader";
	}
	if (flags & EarlyFragmentTests) {
		value_data.at(value_size++) = "EarlyFragmentTests";
	}
	if (flags & LateFragmentTests) {
		value_data.at(value_size++) = "LateFragmentTests";
	}
	if (flags & ColorAttachmentOutput) {
		value_data.at(value_size++) = "ColorAttachmentOutput";
	}
	if (flags & ComputeShader) {
		value_data.at(value_size++) = "ComputeShader";
	}
	if (flags & AllTransfer) {
		value_data.at(value_size++) = "AllTransfer";
	}
	if (flags & BottomOfPipe) {
		value_data.at(value_size++) = "BottomOfPipe";
	}
	if (flags & Host) {
		value_data.at(value_size++) = "Host";
	}
	if (flags & AllGraphics) {
		value_data.at(value_size++) = "AllGraphics";
	}
	if (flags & AllCommands) {
		value_data.at(value_size++) = "AllCommands";
	}
	if (flags & CommandPreprocessBitEXT) {
		value_data.at(value_size++) = "CommandPreprocessBitEXT";
	}
	if (flags & ConditionalRenderingBitEXT) {
		value_data.at(value_size++) = "ConditionalRenderingBitEXT";
	}
	if (flags & TaskShaderBitEXT) {
		value_data.at(value_size++) = "TaskShaderBitEXT";
	}
	if (flags & MeshShaderBitEXT) {
		value_data.at(value_size++) = "MeshShaderBitEXT";
	}
	if (flags & RayTracingShaderBitKHR) {
		value_data.at(value_size++) = "RayTracingShaderBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		value_data.at(value_size++) = "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & FragmentDensityProcessBitEXT) {
		value_data.at(value_size++) = "FragmentDensityProcessBitEXT";
	}
	if (flags & TransformFeedbackBitEXT) {
		value_data.at(value_size++) = "TransformFeedbackBitEXT";
	}
	if (flags & AccelerationStructureBuildBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureBuildBitKHR";
	}
	if (flags & VideoDecodeBitKHR) {
		value_data.at(value_size++) = "VideoDecodeBitKHR";
	}
	if (flags & VideoEncodeBitKHR) {
		value_data.at(value_size++) = "VideoEncodeBitKHR";
	}
	if (flags & AccelerationStructureCopyBitKHR) {
		value_data.at(value_size++) = "AccelerationStructureCopyBitKHR";
	}
	if (flags & OpticalFlowBitNV) {
		value_data.at(value_size++) = "OpticalFlowBitNV";
	}
	if (flags & MicromapBuildBitEXT) {
		value_data.at(value_size++) = "MicromapBuildBitEXT";
	}
	if (flags & Copy) {
		value_data.at(value_size++) = "Copy";
	}
	if (flags & Resolve) {
		value_data.at(value_size++) = "Resolve";
	}
	if (flags & Blit) {
		value_data.at(value_size++) = "Blit";
	}
	if (flags & Clear) {
		value_data.at(value_size++) = "Clear";
	}
	if (flags & IndexInput) {
		value_data.at(value_size++) = "IndexInput";
	}
	if (flags & VertexAttributeInput) {
		value_data.at(value_size++) = "VertexAttributeInput";
	}
	if (flags & PreRasterizationShaders) {
		value_data.at(value_size++) = "PreRasterizationShaders";
	}
	if (flags & SubpassShaderBitHUAWEI) {
		value_data.at(value_size++) = "SubpassShaderBitHUAWEI";
	}
	if (flags & InvocationMaskBitHUAWEI) {
		value_data.at(value_size++) = "InvocationMaskBitHUAWEI";
	}
	if (flags & ClusterCullingShaderBitHUAWEI) {
		value_data.at(value_size++) = "ClusterCullingShaderBitHUAWEI";
	}
	if (flags & DataGraphBitARM) {
		value_data.at(value_size++) = "DataGraphBitARM";
	}
	if (flags & ConvertCooperativeVectorMatrixBitNV) {
		value_data.at(value_size++) = "ConvertCooperativeVectorMatrixBitNV";
	}
	if (flags & MemoryDecompressionBitEXT) {
		value_data.at(value_size++) = "MemoryDecompressionBitEXT";
	}
	if (flags & CopyIndirectBitKHR) {
		value_data.at(value_size++) = "CopyIndirectBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PipelineTessellationStateCreateFlags flags) -> std::string {
	if (flags) {
		return "PipelineTessellationStateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineVertexInputStateCreateFlags flags) -> std::string {
	if (flags) {
		return "PipelineVertexInputStateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineViewportStateCreateFlags flags) -> std::string {
	if (flags) {
		return "PipelineViewportStateCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PipelineViewportSwizzleStateCreateFlagsNV flags) -> std::string {
	if (flags) {
		return "PipelineViewportSwizzleStateCreateFlagsNV has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(PresentGravityFlagsKHR flags) -> std::string {
	using enum PresentGravityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "PresentGravityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & Min) {
		value_data.at(value_size++) = "Min";
	}
	if (flags & Max) {
		value_data.at(value_size++) = "Max";
	}
	if (flags & Centered) {
		value_data.at(value_size++) = "Centered";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PresentScalingFlagsKHR flags) -> std::string {
	using enum PresentScalingBitsKHR;
	if ((flags & AllBits) != flags) {
		return "PresentScalingBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & OneToOne) {
		value_data.at(value_size++) = "OneToOne";
	}
	if (flags & AspectRatioStretch) {
		value_data.at(value_size++) = "AspectRatioStretch";
	}
	if (flags & Stretch) {
		value_data.at(value_size++) = "Stretch";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PresentStageFlagsEXT flags) -> std::string {
	using enum PresentStageBitsEXT;
	if ((flags & AllBits) != flags) {
		return "PresentStageBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & QueueOperationsEnd) {
		value_data.at(value_size++) = "QueueOperationsEnd";
	}
	if (flags & RequestDequeued) {
		value_data.at(value_size++) = "RequestDequeued";
	}
	if (flags & ImageFirstPixelOut) {
		value_data.at(value_size++) = "ImageFirstPixelOut";
	}
	if (flags & ImageFirstPixelVisible) {
		value_data.at(value_size++) = "ImageFirstPixelVisible";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PresentTimingInfoFlagsEXT flags) -> std::string {
	using enum PresentTimingInfoBitsEXT;
	if ((flags & AllBits) != flags) {
		return "PresentTimingInfoBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & PresentAtRelativeTime) {
		value_data.at(value_size++) = "PresentAtRelativeTime";
	}
	if (flags & PresentAtNearestRefreshCycle) {
		value_data.at(value_size++) = "PresentAtNearestRefreshCycle";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(PrivateDataSlotCreateFlags flags) -> std::string {
	if (flags) {
		return "PrivateDataSlotCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(QueryControlFlags flags) -> std::string {
	using enum QueryControlBits;
	if ((flags & AllBits) != flags) {
		return "QueryControlBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Precise) {
		value_data.at(value_size++) = "Precise";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(QueryPipelineStatisticFlags flags) -> std::string {
	using enum QueryPipelineStatisticBits;
	if ((flags & AllBits) != flags) {
		return "QueryPipelineStatisticBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 15> value_data;
	if (flags & InputAssemblyVertices) {
		value_data.at(value_size++) = "InputAssemblyVertices";
	}
	if (flags & InputAssemblyPrimitives) {
		value_data.at(value_size++) = "InputAssemblyPrimitives";
	}
	if (flags & VertexShaderInvocations) {
		value_data.at(value_size++) = "VertexShaderInvocations";
	}
	if (flags & GeometryShaderInvocations) {
		value_data.at(value_size++) = "GeometryShaderInvocations";
	}
	if (flags & GeometryShaderPrimitives) {
		value_data.at(value_size++) = "GeometryShaderPrimitives";
	}
	if (flags & ClippingInvocations) {
		value_data.at(value_size++) = "ClippingInvocations";
	}
	if (flags & ClippingPrimitives) {
		value_data.at(value_size++) = "ClippingPrimitives";
	}
	if (flags & FragmentShaderInvocations) {
		value_data.at(value_size++) = "FragmentShaderInvocations";
	}
	if (flags & TessellationControlShaderPatches) {
		value_data.at(value_size++) = "TessellationControlShaderPatches";
	}
	if (flags & TessellationEvaluationShaderInvocations) {
		value_data.at(value_size++) = "TessellationEvaluationShaderInvocations";
	}
	if (flags & ComputeShaderInvocations) {
		value_data.at(value_size++) = "ComputeShaderInvocations";
	}
	if (flags & TaskShaderInvocationsBitEXT) {
		value_data.at(value_size++) = "TaskShaderInvocationsBitEXT";
	}
	if (flags & MeshShaderInvocationsBitEXT) {
		value_data.at(value_size++) = "MeshShaderInvocationsBitEXT";
	}
	if (flags & ClusterCullingShaderInvocationsBitHUAWEI) {
		value_data.at(value_size++) = "ClusterCullingShaderInvocationsBitHUAWEI";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(QueryPoolCreateFlags flags) -> std::string {
	using enum QueryPoolCreateBits;
	if ((flags & AllBits) != flags) {
		return "QueryPoolCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & ResetBitKHR) {
		value_data.at(value_size++) = "ResetBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(QueryResultFlags flags) -> std::string {
	using enum QueryResultBits;
	if ((flags & AllBits) != flags) {
		return "QueryResultBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & v64) {
		value_data.at(value_size++) = "v64";
	}
	if (flags & Wait) {
		value_data.at(value_size++) = "Wait";
	}
	if (flags & WithAvailability) {
		value_data.at(value_size++) = "WithAvailability";
	}
	if (flags & Partial) {
		value_data.at(value_size++) = "Partial";
	}
	if (flags & WithStatusBitKHR) {
		value_data.at(value_size++) = "WithStatusBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(QueueFlags flags) -> std::string {
	using enum QueueBits;
	if ((flags & AllBits) != flags) {
		return "QueueBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 10> value_data;
	if (flags & Graphics) {
		value_data.at(value_size++) = "Graphics";
	}
	if (flags & Compute) {
		value_data.at(value_size++) = "Compute";
	}
	if (flags & Transfer) {
		value_data.at(value_size++) = "Transfer";
	}
	if (flags & SparseBinding) {
		value_data.at(value_size++) = "SparseBinding";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & VideoDecodeBitKHR) {
		value_data.at(value_size++) = "VideoDecodeBitKHR";
	}
	if (flags & VideoEncodeBitKHR) {
		value_data.at(value_size++) = "VideoEncodeBitKHR";
	}
	if (flags & OpticalFlowBitNV) {
		value_data.at(value_size++) = "OpticalFlowBitNV";
	}
	if (flags & DataGraphBitARM) {
		value_data.at(value_size++) = "DataGraphBitARM";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(RefreshObjectFlagsKHR flags) -> std::string {
	if (flags) {
		return "RefreshObjectFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(RenderPassCreateFlags flags) -> std::string {
	using enum RenderPassCreateBits;
	if ((flags & AllBits) != flags) {
		return "RenderPassCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & TransformBitQCOM) {
		value_data.at(value_size++) = "TransformBitQCOM";
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		value_data.at(value_size++) = "PerLayerFragmentDensityBitVALVE";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(RenderingAttachmentFlagsKHR flags) -> std::string {
	using enum RenderingAttachmentBitsKHR;
	if ((flags & AllBits) != flags) {
		return "RenderingAttachmentBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & InputAttachmentFeedback) {
		value_data.at(value_size++) = "InputAttachmentFeedback";
	}
	if (flags & ResolveSkipTransferFunction) {
		value_data.at(value_size++) = "ResolveSkipTransferFunction";
	}
	if (flags & ResolveEnableTransferFunction) {
		value_data.at(value_size++) = "ResolveEnableTransferFunction";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(RenderingFlags flags) -> std::string {
	using enum RenderingBits;
	if ((flags & AllBits) != flags) {
		return "RenderingBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 10> value_data;
	if (flags & ContentsSecondaryCommandBuffers) {
		value_data.at(value_size++) = "ContentsSecondaryCommandBuffers";
	}
	if (flags & Suspending) {
		value_data.at(value_size++) = "Suspending";
	}
	if (flags & Resuming) {
		value_data.at(value_size++) = "Resuming";
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		value_data.at(value_size++) = "EnableLegacyDitheringBitEXT";
	}
	if (flags & ContentsInlineBitKHR) {
		value_data.at(value_size++) = "ContentsInlineBitKHR";
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		value_data.at(value_size++) = "PerLayerFragmentDensityBitVALVE";
	}
	if (flags & FragmentRegionBitEXT) {
		value_data.at(value_size++) = "FragmentRegionBitEXT";
	}
	if (flags & CustomResolveBitEXT) {
		value_data.at(value_size++) = "CustomResolveBitEXT";
	}
	if (flags & LocalReadConcurrentAccessControlBitKHR) {
		value_data.at(value_size++) = "LocalReadConcurrentAccessControlBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ResolveImageFlagsKHR flags) -> std::string {
	using enum ResolveImageBitsKHR;
	if ((flags & AllBits) != flags) {
		return "ResolveImageBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & SkipTransferFunction) {
		value_data.at(value_size++) = "SkipTransferFunction";
	}
	if (flags & EnableTransferFunction) {
		value_data.at(value_size++) = "EnableTransferFunction";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ResolveModeFlags flags) -> std::string {
	using enum ResolveModeBits;
	if ((flags & AllBits) != flags) {
		return "ResolveModeBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 8> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & SampleZero) {
		value_data.at(value_size++) = "SampleZero";
	}
	if (flags & Average) {
		value_data.at(value_size++) = "Average";
	}
	if (flags & Min) {
		value_data.at(value_size++) = "Min";
	}
	if (flags & Max) {
		value_data.at(value_size++) = "Max";
	}
	if (flags & ExternalFormatDownsampleBitANDROID) {
		value_data.at(value_size++) = "ExternalFormatDownsampleBitANDROID";
	}
	if (flags & CustomBitEXT) {
		value_data.at(value_size++) = "CustomBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SampleCountFlags flags) -> std::string {
	using enum SampleCountBits;
	if ((flags & AllBits) != flags) {
		return "SampleCountBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 8> value_data;
	if (flags & v1) {
		value_data.at(value_size++) = "v1";
	}
	if (flags & v2) {
		value_data.at(value_size++) = "v2";
	}
	if (flags & v4) {
		value_data.at(value_size++) = "v4";
	}
	if (flags & v8) {
		value_data.at(value_size++) = "v8";
	}
	if (flags & v16) {
		value_data.at(value_size++) = "v16";
	}
	if (flags & v32) {
		value_data.at(value_size++) = "v32";
	}
	if (flags & v64) {
		value_data.at(value_size++) = "v64";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SamplerCreateFlags flags) -> std::string {
	using enum SamplerCreateBits;
	if ((flags & AllBits) != flags) {
		return "SamplerCreateBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & SubsampledBitEXT) {
		value_data.at(value_size++) = "SubsampledBitEXT";
	}
	if (flags & SubsampledCoarseReconstructionBitEXT) {
		value_data.at(value_size++) = "SubsampledCoarseReconstructionBitEXT";
	}
	if (flags & NonSeamlessCubeMapBitEXT) {
		value_data.at(value_size++) = "NonSeamlessCubeMapBitEXT";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		value_data.at(value_size++) = "DescriptorBufferCaptureReplayBitEXT";
	}
	if (flags & ImageProcessingBitQCOM) {
		value_data.at(value_size++) = "ImageProcessingBitQCOM";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ScreenSurfaceCreateFlagsQNX flags) -> std::string {
	if (flags) {
		return "ScreenSurfaceCreateFlagsQNX has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(SemaphoreCreateFlags flags) -> std::string {
	if (flags) {
		return "SemaphoreCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(SemaphoreImportFlags flags) -> std::string {
	using enum SemaphoreImportBits;
	if ((flags & AllBits) != flags) {
		return "SemaphoreImportBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Temporary) {
		value_data.at(value_size++) = "Temporary";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SemaphoreWaitFlags flags) -> std::string {
	using enum SemaphoreWaitBits;
	if ((flags & AllBits) != flags) {
		return "SemaphoreWaitBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Any) {
		value_data.at(value_size++) = "Any";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ShaderCorePropertiesFlagsAMD flags) -> std::string {
	if (flags) {
		return "ShaderCorePropertiesFlagsAMD has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ShaderCreateFlagsEXT flags) -> std::string {
	using enum ShaderCreateBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ShaderCreateBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 14> value_data;
	if (flags & LinkStage) {
		value_data.at(value_size++) = "LinkStage";
	}
	if (flags & AllowVaryingSubgroupSize) {
		value_data.at(value_size++) = "AllowVaryingSubgroupSize";
	}
	if (flags & RequireFullSubgroups) {
		value_data.at(value_size++) = "RequireFullSubgroups";
	}
	if (flags & NoTaskShader) {
		value_data.at(value_size++) = "NoTaskShader";
	}
	if (flags & DispatchBase) {
		value_data.at(value_size++) = "DispatchBase";
	}
	if (flags & FragmentShadingRateAttachment) {
		value_data.at(value_size++) = "FragmentShadingRateAttachment";
	}
	if (flags & FragmentDensityMapAttachment) {
		value_data.at(value_size++) = "FragmentDensityMapAttachment";
	}
	if (flags & IndirectBindable) {
		value_data.at(value_size++) = "IndirectBindable";
	}
	if (flags & DescriptorHeap) {
		value_data.at(value_size++) = "DescriptorHeap";
	}
	if (flags & InstrumentShaderBitARM) {
		value_data.at(value_size++) = "InstrumentShaderBitARM";
	}
	if (flags & OpacityMicromapDisallowMixedSpecialIndex) {
		value_data.at(value_size++) = "OpacityMicromapDisallowMixedSpecialIndex";
	}
	if (flags & v64BitIndexing) {
		value_data.at(value_size++) = "v64BitIndexing";
	}
	if (flags & IndependentSetsBitKHR) {
		value_data.at(value_size++) = "IndependentSetsBitKHR";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ShaderInstrumentationValuesFlagsARM flags) -> std::string {
	if (flags) {
		return "ShaderInstrumentationValuesFlagsARM has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ShaderModuleCreateFlags flags) -> std::string {
	if (flags) {
		return "ShaderModuleCreateFlags has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ShaderStageFlags flags) -> std::string {
	using enum ShaderStageBits;
	if ((flags & AllBits) != flags) {
		return "ShaderStageBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 19> value_data;
	if (flags & Vertex) {
		value_data.at(value_size++) = "Vertex";
	}
	if (flags & TessellationControl) {
		value_data.at(value_size++) = "TessellationControl";
	}
	if (flags & TessellationEvaluation) {
		value_data.at(value_size++) = "TessellationEvaluation";
	}
	if (flags & Geometry) {
		value_data.at(value_size++) = "Geometry";
	}
	if (flags & Fragment) {
		value_data.at(value_size++) = "Fragment";
	}
	if (flags & AllGraphics) {
		value_data.at(value_size++) = "AllGraphics";
	}
	if (flags & Compute) {
		value_data.at(value_size++) = "Compute";
	}
	if (flags & TaskBitEXT) {
		value_data.at(value_size++) = "TaskBitEXT";
	}
	if (flags & MeshBitEXT) {
		value_data.at(value_size++) = "MeshBitEXT";
	}
	if (flags & RaygenBitKHR) {
		value_data.at(value_size++) = "RaygenBitKHR";
	}
	if (flags & AnyHitBitKHR) {
		value_data.at(value_size++) = "AnyHitBitKHR";
	}
	if (flags & ClosestHitBitKHR) {
		value_data.at(value_size++) = "ClosestHitBitKHR";
	}
	if (flags & MissBitKHR) {
		value_data.at(value_size++) = "MissBitKHR";
	}
	if (flags & IntersectionBitKHR) {
		value_data.at(value_size++) = "IntersectionBitKHR";
	}
	if (flags & CallableBitKHR) {
		value_data.at(value_size++) = "CallableBitKHR";
	}
	if (flags & SubpassShadingBitHUAWEI) {
		value_data.at(value_size++) = "SubpassShadingBitHUAWEI";
	}
	if (flags & ClusterCullingBitHUAWEI) {
		value_data.at(value_size++) = "ClusterCullingBitHUAWEI";
	}
	if (flags & All) {
		value_data.at(value_size++) = "All";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SparseImageFormatFlags flags) -> std::string {
	using enum SparseImageFormatBits;
	if ((flags & AllBits) != flags) {
		return "SparseImageFormatBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & SingleMiptail) {
		value_data.at(value_size++) = "SingleMiptail";
	}
	if (flags & AlignedMipSize) {
		value_data.at(value_size++) = "AlignedMipSize";
	}
	if (flags & NonstandardBlockSize) {
		value_data.at(value_size++) = "NonstandardBlockSize";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SparseMemoryBindFlags flags) -> std::string {
	using enum SparseMemoryBindBits;
	if ((flags & AllBits) != flags) {
		return "SparseMemoryBindBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Metadata) {
		value_data.at(value_size++) = "Metadata";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SpirvResourceTypeFlagsEXT flags) -> std::string {
	using enum SpirvResourceTypeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "SpirvResourceTypeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 12> value_data;
	if (flags & Sampler) {
		value_data.at(value_size++) = "Sampler";
	}
	if (flags & SampledImage) {
		value_data.at(value_size++) = "SampledImage";
	}
	if (flags & ReadOnlyImage) {
		value_data.at(value_size++) = "ReadOnlyImage";
	}
	if (flags & ReadWriteImage) {
		value_data.at(value_size++) = "ReadWriteImage";
	}
	if (flags & CombinedSampledImage) {
		value_data.at(value_size++) = "CombinedSampledImage";
	}
	if (flags & UniformBuffer) {
		value_data.at(value_size++) = "UniformBuffer";
	}
	if (flags & ReadOnlyStorageBuffer) {
		value_data.at(value_size++) = "ReadOnlyStorageBuffer";
	}
	if (flags & ReadWriteStorageBuffer) {
		value_data.at(value_size++) = "ReadWriteStorageBuffer";
	}
	if (flags & AccelerationStructure) {
		value_data.at(value_size++) = "AccelerationStructure";
	}
	if (flags & TensorBitARM) {
		value_data.at(value_size++) = "TensorBitARM";
	}
	if (flags & All) {
		value_data.at(value_size++) = "All";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(StencilFaceFlags flags) -> std::string {
	using enum StencilFaceBits;
	if ((flags & AllBits) != flags) {
		return "StencilFaceBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & Front) {
		value_data.at(value_size++) = "Front";
	}
	if (flags & Back) {
		value_data.at(value_size++) = "Back";
	}
	if (flags & FrontAndBack) {
		value_data.at(value_size++) = "FrontAndBack";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(StreamDescriptorSurfaceCreateFlagsGGP flags) -> std::string {
	if (flags) {
		return "StreamDescriptorSurfaceCreateFlagsGGP has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(SubgroupFeatureFlags flags) -> std::string {
	using enum SubgroupFeatureBits;
	if ((flags & AllBits) != flags) {
		return "SubgroupFeatureBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 12> value_data;
	if (flags & Basic) {
		value_data.at(value_size++) = "Basic";
	}
	if (flags & Vote) {
		value_data.at(value_size++) = "Vote";
	}
	if (flags & Arithmetic) {
		value_data.at(value_size++) = "Arithmetic";
	}
	if (flags & Ballot) {
		value_data.at(value_size++) = "Ballot";
	}
	if (flags & Shuffle) {
		value_data.at(value_size++) = "Shuffle";
	}
	if (flags & ShuffleRelative) {
		value_data.at(value_size++) = "ShuffleRelative";
	}
	if (flags & Clustered) {
		value_data.at(value_size++) = "Clustered";
	}
	if (flags & Quad) {
		value_data.at(value_size++) = "Quad";
	}
	if (flags & PartitionedBitEXT) {
		value_data.at(value_size++) = "PartitionedBitEXT";
	}
	if (flags & Rotate) {
		value_data.at(value_size++) = "Rotate";
	}
	if (flags & RotateClustered) {
		value_data.at(value_size++) = "RotateClustered";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SubmitFlags flags) -> std::string {
	using enum SubmitBits;
	if ((flags & AllBits) != flags) {
		return "SubmitBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SubpassDescriptionFlags flags) -> std::string {
	using enum SubpassDescriptionBits;
	if ((flags & AllBits) != flags) {
		return "SubpassDescriptionBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 10> value_data;
	if (flags & PerViewAttributesBitNVX) {
		value_data.at(value_size++) = "PerViewAttributesBitNVX";
	}
	if (flags & PerViewPositionxOnlyBitNVX) {
		value_data.at(value_size++) = "PerViewPositionxOnlyBitNVX";
	}
	if (flags & FragmentRegionBitEXT) {
		value_data.at(value_size++) = "FragmentRegionBitEXT";
	}
	if (flags & CustomResolveBitEXT) {
		value_data.at(value_size++) = "CustomResolveBitEXT";
	}
	if (flags & RasterizationOrderAttachmentColorAccessBitEXT) {
		value_data.at(value_size++) = "RasterizationOrderAttachmentColorAccessBitEXT";
	}
	if (flags & RasterizationOrderAttachmentDepthAccessBitEXT) {
		value_data.at(value_size++) = "RasterizationOrderAttachmentDepthAccessBitEXT";
	}
	if (flags & RasterizationOrderAttachmentStencilAccessBitEXT) {
		value_data.at(value_size++) = "RasterizationOrderAttachmentStencilAccessBitEXT";
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		value_data.at(value_size++) = "EnableLegacyDitheringBitEXT";
	}
	if (flags & TileShadingApronBitQCOM) {
		value_data.at(value_size++) = "TileShadingApronBitQCOM";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SurfaceCounterFlagsEXT flags) -> std::string {
	using enum SurfaceCounterBitsEXT;
	if ((flags & AllBits) != flags) {
		return "SurfaceCounterBitsEXT does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & Vblank) {
		value_data.at(value_size++) = "Vblank";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SurfaceCreateFlagsOHOS flags) -> std::string {
	if (flags) {
		return "SurfaceCreateFlagsOHOS has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(SurfaceTransformFlagsKHR flags) -> std::string {
	using enum SurfaceTransformBitsKHR;
	if ((flags & AllBits) != flags) {
		return "SurfaceTransformBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 10> value_data;
	if (flags & Identity) {
		value_data.at(value_size++) = "Identity";
	}
	if (flags & Rotate90) {
		value_data.at(value_size++) = "Rotate90";
	}
	if (flags & Rotate180) {
		value_data.at(value_size++) = "Rotate180";
	}
	if (flags & Rotate270) {
		value_data.at(value_size++) = "Rotate270";
	}
	if (flags & HorizontalMirror) {
		value_data.at(value_size++) = "HorizontalMirror";
	}
	if (flags & HorizontalMirrorRotate90) {
		value_data.at(value_size++) = "HorizontalMirrorRotate90";
	}
	if (flags & HorizontalMirrorRotate180) {
		value_data.at(value_size++) = "HorizontalMirrorRotate180";
	}
	if (flags & HorizontalMirrorRotate270) {
		value_data.at(value_size++) = "HorizontalMirrorRotate270";
	}
	if (flags & Inherit) {
		value_data.at(value_size++) = "Inherit";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SwapchainCreateFlagsKHR flags) -> std::string {
	using enum SwapchainCreateBitsKHR;
	if ((flags & AllBits) != flags) {
		return "SwapchainCreateBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 9> value_data;
	if (flags & SplitInstanceBindRegions) {
		value_data.at(value_size++) = "SplitInstanceBindRegions";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & MutableFormat) {
		value_data.at(value_size++) = "MutableFormat";
	}
	if (flags & DeferredMemoryAllocation) {
		value_data.at(value_size++) = "DeferredMemoryAllocation";
	}
	if (flags & PresentId2) {
		value_data.at(value_size++) = "PresentId2";
	}
	if (flags & PresentWait2) {
		value_data.at(value_size++) = "PresentWait2";
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		value_data.at(value_size++) = "MultisampledRenderToSingleSampledBitEXT";
	}
	if (flags & PresentTimingBitEXT) {
		value_data.at(value_size++) = "PresentTimingBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(SwapchainImageUsageFlagsANDROID flags) -> std::string {
	if (flags) {
		return "SwapchainImageUsageFlagsANDROID has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(SwapchainImageUsageFlagsOHOS flags) -> std::string {
	if (flags) {
		return "SwapchainImageUsageFlagsOHOS has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(TensorCreateFlagsARM flags) -> std::string {
	using enum TensorCreateBitsARM;
	if ((flags & AllBits) != flags) {
		return "TensorCreateBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & MutableFormat) {
		value_data.at(value_size++) = "MutableFormat";
	}
	if (flags & Protected) {
		value_data.at(value_size++) = "Protected";
	}
	if (flags & DescriptorBufferCaptureReplay) {
		value_data.at(value_size++) = "DescriptorBufferCaptureReplay";
	}
	if (flags & DescriptorHeapCaptureReplay) {
		value_data.at(value_size++) = "DescriptorHeapCaptureReplay";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(TensorUsageFlagsARM flags) -> std::string {
	using enum TensorUsageBitsARM;
	if ((flags & AllBits) != flags) {
		return "TensorUsageBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & Shader) {
		value_data.at(value_size++) = "Shader";
	}
	if (flags & TransferSrc) {
		value_data.at(value_size++) = "TransferSrc";
	}
	if (flags & TransferDst) {
		value_data.at(value_size++) = "TransferDst";
	}
	if (flags & ImageAliasing) {
		value_data.at(value_size++) = "ImageAliasing";
	}
	if (flags & DataGraph) {
		value_data.at(value_size++) = "DataGraph";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(TensorViewCreateFlagsARM flags) -> std::string {
	using enum TensorViewCreateBitsARM;
	if ((flags & AllBits) != flags) {
		return "TensorViewCreateBitsARM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & DescriptorBufferCaptureReplay) {
		value_data.at(value_size++) = "DescriptorBufferCaptureReplay";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(TileShadingRenderPassFlagsQCOM flags) -> std::string {
	using enum TileShadingRenderPassBitsQCOM;
	if ((flags & AllBits) != flags) {
		return "TileShadingRenderPassBitsQCOM does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & Enable) {
		value_data.at(value_size++) = "Enable";
	}
	if (flags & PerTileExecution) {
		value_data.at(value_size++) = "PerTileExecution";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(ToolPurposeFlags flags) -> std::string {
	using enum ToolPurposeBits;
	if ((flags & AllBits) != flags) {
		return "ToolPurposeBits does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 8> value_data;
	if (flags & Validation) {
		value_data.at(value_size++) = "Validation";
	}
	if (flags & Profiling) {
		value_data.at(value_size++) = "Profiling";
	}
	if (flags & Tracing) {
		value_data.at(value_size++) = "Tracing";
	}
	if (flags & AdditionalFeatures) {
		value_data.at(value_size++) = "AdditionalFeatures";
	}
	if (flags & ModifyingFeatures) {
		value_data.at(value_size++) = "ModifyingFeatures";
	}
	if (flags & DebugReportingBitEXT) {
		value_data.at(value_size++) = "DebugReportingBitEXT";
	}
	if (flags & DebugMarkersBitEXT) {
		value_data.at(value_size++) = "DebugMarkersBitEXT";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(UbmSurfaceCreateFlagsSEC flags) -> std::string {
	if (flags) {
		return "UbmSurfaceCreateFlagsSEC has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ValidationCacheCreateFlagsEXT flags) -> std::string {
	if (flags) {
		return "ValidationCacheCreateFlagsEXT has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(ViSurfaceCreateFlagsNN flags) -> std::string {
	if (flags) {
		return "ViSurfaceCreateFlagsNN has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(VideoBeginCodingFlagsKHR flags) -> std::string {
	if (flags) {
		return "VideoBeginCodingFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(VideoCapabilityFlagsKHR flags) -> std::string {
	using enum VideoCapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoCapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & ProtectedContent) {
		value_data.at(value_size++) = "ProtectedContent";
	}
	if (flags & SeparateReferenceImages) {
		value_data.at(value_size++) = "SeparateReferenceImages";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoChromaSubsamplingFlagsKHR flags) -> std::string {
	using enum VideoChromaSubsamplingBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoChromaSubsamplingBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & Invalid) {
		value_data.at(value_size++) = "Invalid";
	}
	if (flags & Monochrome) {
		value_data.at(value_size++) = "Monochrome";
	}
	if (flags & v420) {
		value_data.at(value_size++) = "v420";
	}
	if (flags & v422) {
		value_data.at(value_size++) = "v422";
	}
	if (flags & v444) {
		value_data.at(value_size++) = "v444";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoCodecOperationFlagsKHR flags) -> std::string {
	using enum VideoCodecOperationBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoCodecOperationBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 9> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & DecodeH264) {
		value_data.at(value_size++) = "DecodeH264";
	}
	if (flags & DecodeH265) {
		value_data.at(value_size++) = "DecodeH265";
	}
	if (flags & DecodeAV1) {
		value_data.at(value_size++) = "DecodeAV1";
	}
	if (flags & DecodeVp9) {
		value_data.at(value_size++) = "DecodeVp9";
	}
	if (flags & EncodeH264) {
		value_data.at(value_size++) = "EncodeH264";
	}
	if (flags & EncodeH265) {
		value_data.at(value_size++) = "EncodeH265";
	}
	if (flags & EncodeAV1) {
		value_data.at(value_size++) = "EncodeAV1";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoCodingControlFlagsKHR flags) -> std::string {
	using enum VideoCodingControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoCodingControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & Reset) {
		value_data.at(value_size++) = "Reset";
	}
	if (flags & EncodeRateControl) {
		value_data.at(value_size++) = "EncodeRateControl";
	}
	if (flags & EncodeQualityLevel) {
		value_data.at(value_size++) = "EncodeQualityLevel";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoComponentBitDepthFlagsKHR flags) -> std::string {
	using enum VideoComponentBitDepthBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoComponentBitDepthBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Invalid) {
		value_data.at(value_size++) = "Invalid";
	}
	if (flags & v8) {
		value_data.at(value_size++) = "v8";
	}
	if (flags & v10) {
		value_data.at(value_size++) = "v10";
	}
	if (flags & v12) {
		value_data.at(value_size++) = "v12";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoDecodeCapabilityFlagsKHR flags) -> std::string {
	using enum VideoDecodeCapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoDecodeCapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & DpbAndOutputCoincide) {
		value_data.at(value_size++) = "DpbAndOutputCoincide";
	}
	if (flags & DpbAndOutputDistinct) {
		value_data.at(value_size++) = "DpbAndOutputDistinct";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoDecodeFlagsKHR flags) -> std::string {
	if (flags) {
		return "VideoDecodeFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(VideoDecodeH264PictureLayoutFlagsKHR flags) -> std::string {
	using enum VideoDecodeH264PictureLayoutBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoDecodeH264PictureLayoutBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & Progressive) {
		value_data.at(value_size++) = "Progressive";
	}
	if (flags & InterlacedInterleavedLines) {
		value_data.at(value_size++) = "InterlacedInterleavedLines";
	}
	if (flags & InterlacedSeparatePlanes) {
		value_data.at(value_size++) = "InterlacedSeparatePlanes";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoDecodeUsageFlagsKHR flags) -> std::string {
	using enum VideoDecodeUsageBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoDecodeUsageBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Default) {
		value_data.at(value_size++) = "Default";
	}
	if (flags & Transcoding) {
		value_data.at(value_size++) = "Transcoding";
	}
	if (flags & Offline) {
		value_data.at(value_size++) = "Offline";
	}
	if (flags & Streaming) {
		value_data.at(value_size++) = "Streaming";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeAV1CapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1CapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1CapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & PerRateControlGroupMinMaxQIndex) {
		value_data.at(value_size++) = "PerRateControlGroupMinMaxQIndex";
	}
	if (flags & GenerateObuExtensionHeader) {
		value_data.at(value_size++) = "GenerateObuExtensionHeader";
	}
	if (flags & PrimaryReferenceCdfOnly) {
		value_data.at(value_size++) = "PrimaryReferenceCdfOnly";
	}
	if (flags & FrameSizeOverride) {
		value_data.at(value_size++) = "FrameSizeOverride";
	}
	if (flags & MotionVectorScaling) {
		value_data.at(value_size++) = "MotionVectorScaling";
	}
	if (flags & CompoundPredictionIntraRefresh) {
		value_data.at(value_size++) = "CompoundPredictionIntraRefresh";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeAV1RateControlFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1RateControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1RateControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & RegularGop) {
		value_data.at(value_size++) = "RegularGop";
	}
	if (flags & TemporalLayerPatternDyadic) {
		value_data.at(value_size++) = "TemporalLayerPatternDyadic";
	}
	if (flags & ReferencePatternFlat) {
		value_data.at(value_size++) = "ReferencePatternFlat";
	}
	if (flags & ReferencePatternDyadic) {
		value_data.at(value_size++) = "ReferencePatternDyadic";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeAV1StdFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1StdBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1StdBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & UniformTileSpacingFlagSet) {
		value_data.at(value_size++) = "UniformTileSpacingFlagSet";
	}
	if (flags & SkipModePresentUnset) {
		value_data.at(value_size++) = "SkipModePresentUnset";
	}
	if (flags & PrimaryRefFrame) {
		value_data.at(value_size++) = "PrimaryRefFrame";
	}
	if (flags & DeltaQ) {
		value_data.at(value_size++) = "DeltaQ";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeAV1SuperblockSizeFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1SuperblockSizeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1SuperblockSizeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & v64) {
		value_data.at(value_size++) = "v64";
	}
	if (flags & v128) {
		value_data.at(value_size++) = "v128";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeCapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeCapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeCapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & PrecedingExternallyEncodedBytes) {
		value_data.at(value_size++) = "PrecedingExternallyEncodedBytes";
	}
	if (flags & InsufficientBitstreamBufferRangeDetection) {
		value_data.at(value_size++) = "InsufficientBitstreamBufferRangeDetection";
	}
	if (flags & QuantizationDeltaMap) {
		value_data.at(value_size++) = "QuantizationDeltaMap";
	}
	if (flags & EmphasisMap) {
		value_data.at(value_size++) = "EmphasisMap";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeContentFlagsKHR flags) -> std::string {
	using enum VideoEncodeContentBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeContentBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Default) {
		value_data.at(value_size++) = "Default";
	}
	if (flags & Camera) {
		value_data.at(value_size++) = "Camera";
	}
	if (flags & Desktop) {
		value_data.at(value_size++) = "Desktop";
	}
	if (flags & Rendered) {
		value_data.at(value_size++) = "Rendered";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeFeedbackFlagsKHR flags) -> std::string {
	using enum VideoEncodeFeedbackBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeFeedbackBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 11> value_data;
	if (flags & BitstreamBufferOffset) {
		value_data.at(value_size++) = "BitstreamBufferOffset";
	}
	if (flags & BitstreamBytesWritten) {
		value_data.at(value_size++) = "BitstreamBytesWritten";
	}
	if (flags & BitstreamHasOverrides) {
		value_data.at(value_size++) = "BitstreamHasOverrides";
	}
	if (flags & AverageQuantization) {
		value_data.at(value_size++) = "AverageQuantization";
	}
	if (flags & MinQuantization) {
		value_data.at(value_size++) = "MinQuantization";
	}
	if (flags & MaxQuantization) {
		value_data.at(value_size++) = "MaxQuantization";
	}
	if (flags & IntraPixels) {
		value_data.at(value_size++) = "IntraPixels";
	}
	if (flags & InterPixels) {
		value_data.at(value_size++) = "InterPixels";
	}
	if (flags & SkippedPixels) {
		value_data.at(value_size++) = "SkippedPixels";
	}
	if (flags & PicturePartitionCount) {
		value_data.at(value_size++) = "PicturePartitionCount";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeFlagsKHR flags) -> std::string {
	using enum VideoEncodeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & WithQuantizationDeltaMap) {
		value_data.at(value_size++) = "WithQuantizationDeltaMap";
	}
	if (flags & WithEmphasisMap) {
		value_data.at(value_size++) = "WithEmphasisMap";
	}
	if (flags & IntraRefresh) {
		value_data.at(value_size++) = "IntraRefresh";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH264CapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeH264CapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH264CapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 12> value_data;
	if (flags & HrdCompliance) {
		value_data.at(value_size++) = "HrdCompliance";
	}
	if (flags & PredictionWeightTableGenerated) {
		value_data.at(value_size++) = "PredictionWeightTableGenerated";
	}
	if (flags & RowUnalignedSlice) {
		value_data.at(value_size++) = "RowUnalignedSlice";
	}
	if (flags & DifferentSliceType) {
		value_data.at(value_size++) = "DifferentSliceType";
	}
	if (flags & BFrameInL0List) {
		value_data.at(value_size++) = "BFrameInL0List";
	}
	if (flags & BFrameInL1List) {
		value_data.at(value_size++) = "BFrameInL1List";
	}
	if (flags & PerPictureTypeMinMaxQp) {
		value_data.at(value_size++) = "PerPictureTypeMinMaxQp";
	}
	if (flags & PerSliceConstantQp) {
		value_data.at(value_size++) = "PerSliceConstantQp";
	}
	if (flags & GeneratePrefixNalu) {
		value_data.at(value_size++) = "GeneratePrefixNalu";
	}
	if (flags & MbQpDiffWraparound) {
		value_data.at(value_size++) = "MbQpDiffWraparound";
	}
	if (flags & BPictureIntraRefresh) {
		value_data.at(value_size++) = "BPictureIntraRefresh";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH264RateControlFlagsKHR flags) -> std::string {
	using enum VideoEncodeH264RateControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH264RateControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & AttemptHrdCompliance) {
		value_data.at(value_size++) = "AttemptHrdCompliance";
	}
	if (flags & RegularGop) {
		value_data.at(value_size++) = "RegularGop";
	}
	if (flags & ReferencePatternFlat) {
		value_data.at(value_size++) = "ReferencePatternFlat";
	}
	if (flags & ReferencePatternDyadic) {
		value_data.at(value_size++) = "ReferencePatternDyadic";
	}
	if (flags & TemporalLayerPatternDyadic) {
		value_data.at(value_size++) = "TemporalLayerPatternDyadic";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH264StdFlagsKHR flags) -> std::string {
	using enum VideoEncodeH264StdBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH264StdBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 21> value_data;
	if (flags & SeparateColorPlaneFlagSet) {
		value_data.at(value_size++) = "SeparateColorPlaneFlagSet";
	}
	if (flags & QpprimeYZeroTransformBypassFlagSet) {
		value_data.at(value_size++) = "QpprimeYZeroTransformBypassFlagSet";
	}
	if (flags & ScalingMatrixPresentFlagSet) {
		value_data.at(value_size++) = "ScalingMatrixPresentFlagSet";
	}
	if (flags & ChromaQpIndexOffset) {
		value_data.at(value_size++) = "ChromaQpIndexOffset";
	}
	if (flags & SecondChromaQpIndexOffset) {
		value_data.at(value_size++) = "SecondChromaQpIndexOffset";
	}
	if (flags & PicInitQpMinus26) {
		value_data.at(value_size++) = "PicInitQpMinus26";
	}
	if (flags & WeightedPredFlagSet) {
		value_data.at(value_size++) = "WeightedPredFlagSet";
	}
	if (flags & WeightedBipredIdcExplicit) {
		value_data.at(value_size++) = "WeightedBipredIdcExplicit";
	}
	if (flags & WeightedBipredIdcImplicit) {
		value_data.at(value_size++) = "WeightedBipredIdcImplicit";
	}
	if (flags & Transform8x8ModeFlagSet) {
		value_data.at(value_size++) = "Transform8x8ModeFlagSet";
	}
	if (flags & DirectSpatialMvPredFlagUnset) {
		value_data.at(value_size++) = "DirectSpatialMvPredFlagUnset";
	}
	if (flags & EntropyCodingModeFlagUnset) {
		value_data.at(value_size++) = "EntropyCodingModeFlagUnset";
	}
	if (flags & EntropyCodingModeFlagSet) {
		value_data.at(value_size++) = "EntropyCodingModeFlagSet";
	}
	if (flags & Direct8x8InferenceFlagUnset) {
		value_data.at(value_size++) = "Direct8x8InferenceFlagUnset";
	}
	if (flags & ConstrainedIntraPredFlagSet) {
		value_data.at(value_size++) = "ConstrainedIntraPredFlagSet";
	}
	if (flags & DeblockingFilterDisabled) {
		value_data.at(value_size++) = "DeblockingFilterDisabled";
	}
	if (flags & DeblockingFilterEnabled) {
		value_data.at(value_size++) = "DeblockingFilterEnabled";
	}
	if (flags & DeblockingFilterPartial) {
		value_data.at(value_size++) = "DeblockingFilterPartial";
	}
	if (flags & SliceQpDelta) {
		value_data.at(value_size++) = "SliceQpDelta";
	}
	if (flags & DifferentSliceQpDelta) {
		value_data.at(value_size++) = "DifferentSliceQpDelta";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH265CapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265CapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265CapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 13> value_data;
	if (flags & HrdCompliance) {
		value_data.at(value_size++) = "HrdCompliance";
	}
	if (flags & PredictionWeightTableGenerated) {
		value_data.at(value_size++) = "PredictionWeightTableGenerated";
	}
	if (flags & RowUnalignedSliceSegment) {
		value_data.at(value_size++) = "RowUnalignedSliceSegment";
	}
	if (flags & DifferentSliceSegmentType) {
		value_data.at(value_size++) = "DifferentSliceSegmentType";
	}
	if (flags & BFrameInL0List) {
		value_data.at(value_size++) = "BFrameInL0List";
	}
	if (flags & BFrameInL1List) {
		value_data.at(value_size++) = "BFrameInL1List";
	}
	if (flags & PerPictureTypeMinMaxQp) {
		value_data.at(value_size++) = "PerPictureTypeMinMaxQp";
	}
	if (flags & PerSliceSegmentConstantQp) {
		value_data.at(value_size++) = "PerSliceSegmentConstantQp";
	}
	if (flags & MultipleTilesPerSliceSegment) {
		value_data.at(value_size++) = "MultipleTilesPerSliceSegment";
	}
	if (flags & MultipleSliceSegmentsPerTile) {
		value_data.at(value_size++) = "MultipleSliceSegmentsPerTile";
	}
	if (flags & CuQpDiffWraparound) {
		value_data.at(value_size++) = "CuQpDiffWraparound";
	}
	if (flags & BPictureIntraRefresh) {
		value_data.at(value_size++) = "BPictureIntraRefresh";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH265CtbSizeFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265CtbSizeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265CtbSizeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & v16) {
		value_data.at(value_size++) = "v16";
	}
	if (flags & v32) {
		value_data.at(value_size++) = "v32";
	}
	if (flags & v64) {
		value_data.at(value_size++) = "v64";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH265RateControlFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265RateControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265RateControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & AttemptHrdCompliance) {
		value_data.at(value_size++) = "AttemptHrdCompliance";
	}
	if (flags & RegularGop) {
		value_data.at(value_size++) = "RegularGop";
	}
	if (flags & ReferencePatternFlat) {
		value_data.at(value_size++) = "ReferencePatternFlat";
	}
	if (flags & ReferencePatternDyadic) {
		value_data.at(value_size++) = "ReferencePatternDyadic";
	}
	if (flags & TemporalSubLayerPatternDyadic) {
		value_data.at(value_size++) = "TemporalSubLayerPatternDyadic";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH265StdFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265StdBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265StdBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 22> value_data;
	if (flags & SeparateColorPlaneFlagSet) {
		value_data.at(value_size++) = "SeparateColorPlaneFlagSet";
	}
	if (flags & SampleAdaptiveOffsetEnabledFlagSet) {
		value_data.at(value_size++) = "SampleAdaptiveOffsetEnabledFlagSet";
	}
	if (flags & ScalingListDataPresentFlagSet) {
		value_data.at(value_size++) = "ScalingListDataPresentFlagSet";
	}
	if (flags & PcmEnabledFlagSet) {
		value_data.at(value_size++) = "PcmEnabledFlagSet";
	}
	if (flags & SpsTemporalMvpEnabledFlagSet) {
		value_data.at(value_size++) = "SpsTemporalMvpEnabledFlagSet";
	}
	if (flags & InitQpMinus26) {
		value_data.at(value_size++) = "InitQpMinus26";
	}
	if (flags & WeightedPredFlagSet) {
		value_data.at(value_size++) = "WeightedPredFlagSet";
	}
	if (flags & WeightedBipredFlagSet) {
		value_data.at(value_size++) = "WeightedBipredFlagSet";
	}
	if (flags & Log2ParallelMergeLevelMinus2) {
		value_data.at(value_size++) = "Log2ParallelMergeLevelMinus2";
	}
	if (flags & SignDataHidingEnabledFlagSet) {
		value_data.at(value_size++) = "SignDataHidingEnabledFlagSet";
	}
	if (flags & TransformSkipEnabledFlagSet) {
		value_data.at(value_size++) = "TransformSkipEnabledFlagSet";
	}
	if (flags & TransformSkipEnabledFlagUnset) {
		value_data.at(value_size++) = "TransformSkipEnabledFlagUnset";
	}
	if (flags & PpsSliceChromaQpOffsetsPresentFlagSet) {
		value_data.at(value_size++) = "PpsSliceChromaQpOffsetsPresentFlagSet";
	}
	if (flags & TransquantBypassEnabledFlagSet) {
		value_data.at(value_size++) = "TransquantBypassEnabledFlagSet";
	}
	if (flags & ConstrainedIntraPredFlagSet) {
		value_data.at(value_size++) = "ConstrainedIntraPredFlagSet";
	}
	if (flags & EntropyCodingSyncEnabledFlagSet) {
		value_data.at(value_size++) = "EntropyCodingSyncEnabledFlagSet";
	}
	if (flags & DeblockingFilterOverrideEnabledFlagSet) {
		value_data.at(value_size++) = "DeblockingFilterOverrideEnabledFlagSet";
	}
	if (flags & DependentSliceSegmentsEnabledFlagSet) {
		value_data.at(value_size++) = "DependentSliceSegmentsEnabledFlagSet";
	}
	if (flags & DependentSliceSegmentFlagSet) {
		value_data.at(value_size++) = "DependentSliceSegmentFlagSet";
	}
	if (flags & SliceQpDelta) {
		value_data.at(value_size++) = "SliceQpDelta";
	}
	if (flags & DifferentSliceQpDelta) {
		value_data.at(value_size++) = "DifferentSliceQpDelta";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeH265TransformBlockSizeFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265TransformBlockSizeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265TransformBlockSizeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & v4) {
		value_data.at(value_size++) = "v4";
	}
	if (flags & v8) {
		value_data.at(value_size++) = "v8";
	}
	if (flags & v16) {
		value_data.at(value_size++) = "v16";
	}
	if (flags & v32) {
		value_data.at(value_size++) = "v32";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeIntraRefreshModeFlagsKHR flags) -> std::string {
	using enum VideoEncodeIntraRefreshModeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeIntraRefreshModeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & None) {
		value_data.at(value_size++) = "None";
	}
	if (flags & PerPicturePartition) {
		value_data.at(value_size++) = "PerPicturePartition";
	}
	if (flags & BlockBased) {
		value_data.at(value_size++) = "BlockBased";
	}
	if (flags & BlockRowBased) {
		value_data.at(value_size++) = "BlockRowBased";
	}
	if (flags & BlockColumnBased) {
		value_data.at(value_size++) = "BlockColumnBased";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodePerPartitionFeedbackFlagsKHR flags) -> std::string {
	using enum VideoEncodePerPartitionFeedbackBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodePerPartitionFeedbackBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 4> value_data;
	if (flags & Status) {
		value_data.at(value_size++) = "Status";
	}
	if (flags & BitstreamBufferOffset) {
		value_data.at(value_size++) = "BitstreamBufferOffset";
	}
	if (flags & BitstreamBytesWritten) {
		value_data.at(value_size++) = "BitstreamBytesWritten";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeRateControlFlagsKHR flags) -> std::string {
	if (flags) {
		return "VideoEncodeRateControlFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(VideoEncodeRateControlModeFlagsKHR flags) -> std::string {
	using enum VideoEncodeRateControlModeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeRateControlModeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 5> value_data;
	if (flags & Default) {
		value_data.at(value_size++) = "Default";
	}
	if (flags & Disabled) {
		value_data.at(value_size++) = "Disabled";
	}
	if (flags & Cbr) {
		value_data.at(value_size++) = "Cbr";
	}
	if (flags & Vbr) {
		value_data.at(value_size++) = "Vbr";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeRgbChromaOffsetFlagsVALVE flags) -> std::string {
	using enum VideoEncodeRgbChromaOffsetBitsVALVE;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeRgbChromaOffsetBitsVALVE does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & CositedEven) {
		value_data.at(value_size++) = "CositedEven";
	}
	if (flags & Midpoint) {
		value_data.at(value_size++) = "Midpoint";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeRgbModelConversionFlagsVALVE flags) -> std::string {
	using enum VideoEncodeRgbModelConversionBitsVALVE;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeRgbModelConversionBitsVALVE does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & RgbIdentity) {
		value_data.at(value_size++) = "RgbIdentity";
	}
	if (flags & YcbcrIdentity) {
		value_data.at(value_size++) = "YcbcrIdentity";
	}
	if (flags & Ycbcr709) {
		value_data.at(value_size++) = "Ycbcr709";
	}
	if (flags & Ycbcr601) {
		value_data.at(value_size++) = "Ycbcr601";
	}
	if (flags & Ycbcr2020) {
		value_data.at(value_size++) = "Ycbcr2020";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeRgbRangeCompressionFlagsVALVE flags) -> std::string {
	using enum VideoEncodeRgbRangeCompressionBitsVALVE;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeRgbRangeCompressionBitsVALVE does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 3> value_data;
	if (flags & FullRange) {
		value_data.at(value_size++) = "FullRange";
	}
	if (flags & NarrowRange) {
		value_data.at(value_size++) = "NarrowRange";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEncodeUsageFlagsKHR flags) -> std::string {
	using enum VideoEncodeUsageBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeUsageBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 6> value_data;
	if (flags & Default) {
		value_data.at(value_size++) = "Default";
	}
	if (flags & Transcoding) {
		value_data.at(value_size++) = "Transcoding";
	}
	if (flags & Streaming) {
		value_data.at(value_size++) = "Streaming";
	}
	if (flags & Recording) {
		value_data.at(value_size++) = "Recording";
	}
	if (flags & Conferencing) {
		value_data.at(value_size++) = "Conferencing";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoEndCodingFlagsKHR flags) -> std::string {
	if (flags) {
		return "VideoEndCodingFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(VideoSessionCreateFlagsKHR flags) -> std::string {
	using enum VideoSessionCreateBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoSessionCreateBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 7> value_data;
	if (flags & ProtectedContent) {
		value_data.at(value_size++) = "ProtectedContent";
	}
	if (flags & AllowEncodeParameterOptimizations) {
		value_data.at(value_size++) = "AllowEncodeParameterOptimizations";
	}
	if (flags & InlineQueries) {
		value_data.at(value_size++) = "InlineQueries";
	}
	if (flags & AllowEncodeQuantizationDeltaMap) {
		value_data.at(value_size++) = "AllowEncodeQuantizationDeltaMap";
	}
	if (flags & AllowEncodeEmphasisMap) {
		value_data.at(value_size++) = "AllowEncodeEmphasisMap";
	}
	if (flags & InlineSessionParameters) {
		value_data.at(value_size++) = "InlineSessionParameters";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(VideoSessionParametersCreateFlagsKHR flags) -> std::string {
	using enum VideoSessionParametersCreateBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoSessionParametersCreateBitsKHR does contain a bit that is not possible to be set";
	}
	size_t value_size = 0;
	std::array<std::string_view, 2> value_data;
	if (flags & QuantizationMapCompatible) {
		value_data.at(value_size++) = "QuantizationMapCompatible";
	}
	return std::span<std::string_view>{value_data}.first(value_size) | std::views::join_with(std::string(" | ")) | std::ranges::to<std::string>();
}
template<> auto flagsToString(WaylandSurfaceCreateFlagsKHR flags) -> std::string {
	if (flags) {
		return "WaylandSurfaceCreateFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(Win32SurfaceCreateFlagsKHR flags) -> std::string {
	if (flags) {
		return "Win32SurfaceCreateFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(XcbSurfaceCreateFlagsKHR flags) -> std::string {
	if (flags) {
		return "XcbSurfaceCreateFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
template<> auto flagsToString(XlibSurfaceCreateFlagsKHR flags) -> std::string {
	if (flags) {
		return "XlibSurfaceCreateFlagsKHR has no bits, it sould be empty";
	}
	return "";
}
// NOLINTEND(readability-function-cognitive-complexity, cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
} // namespace VkBindings::Reflections
