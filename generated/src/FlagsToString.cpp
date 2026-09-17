#include "VkBindings/Bits.hpp"
#include "VkBindings/Flags.hpp"
#include "VkBindings/FlagsToString.hpp"

#include <cassert>
#include <cstddef>
#include <string>

namespace VkBindings::Reflections {
// NOLINTBEGIN(readability-function-cognitive-complexity, cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
template<> auto flagsToString(AccelerationStructureCreateFlagsKHR flags) -> std::string {
	using enum AccelerationStructureCreateBitsKHR;
	if ((flags & AllBits) != flags) {
		return "AccelerationStructureCreateBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DeviceAddressCaptureReplay) {
		bytes += 29;
	}
	if (flags & MotionBitNV) {
		bytes += 14;
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		bytes += 38;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DeviceAddressCaptureReplay) {
		first = false;
		ret += "DeviceAddressCaptureReplay";
	}
	if (flags & MotionBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MotionBitNV";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "DescriptorBufferCaptureReplayBitEXT";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & IndirectCommandRead) {
		bytes += 22;
	}
	if (flags & IndexRead) {
		bytes += 12;
	}
	if (flags & VertexAttributeRead) {
		bytes += 22;
	}
	if (flags & UniformRead) {
		bytes += 14;
	}
	if (flags & InputAttachmentRead) {
		bytes += 22;
	}
	if (flags & ShaderRead) {
		bytes += 13;
	}
	if (flags & ShaderWrite) {
		bytes += 14;
	}
	if (flags & ColorAttachmentRead) {
		bytes += 22;
	}
	if (flags & ColorAttachmentWrite) {
		bytes += 23;
	}
	if (flags & DepthStencilAttachmentRead) {
		bytes += 29;
	}
	if (flags & DepthStencilAttachmentWrite) {
		bytes += 30;
	}
	if (flags & TransferRead) {
		bytes += 15;
	}
	if (flags & TransferWrite) {
		bytes += 16;
	}
	if (flags & HostRead) {
		bytes += 11;
	}
	if (flags & HostWrite) {
		bytes += 12;
	}
	if (flags & MemoryRead) {
		bytes += 13;
	}
	if (flags & MemoryWrite) {
		bytes += 14;
	}
	if (flags & CommandPreprocessReadBitEXT) {
		bytes += 30;
	}
	if (flags & CommandPreprocessWriteBitEXT) {
		bytes += 31;
	}
	if (flags & ColorAttachmentReadNoncoherentBitEXT) {
		bytes += 39;
	}
	if (flags & ConditionalRenderingReadBitEXT) {
		bytes += 33;
	}
	if (flags & AccelerationStructureReadBitKHR) {
		bytes += 34;
	}
	if (flags & AccelerationStructureWriteBitKHR) {
		bytes += 35;
	}
	if (flags & FragmentShadingRateAttachmentReadBitKHR) {
		bytes += 42;
	}
	if (flags & FragmentDensityMapReadBitEXT) {
		bytes += 31;
	}
	if (flags & TransformFeedbackWriteBitEXT) {
		bytes += 31;
	}
	if (flags & TransformFeedbackCounterReadBitEXT) {
		bytes += 37;
	}
	if (flags & TransformFeedbackCounterWriteBitEXT) {
		bytes += 38;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & IndirectCommandRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectCommandRead";
	}
	if (flags & IndexRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndexRead";
	}
	if (flags & VertexAttributeRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexAttributeRead";
	}
	if (flags & UniformRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformRead";
	}
	if (flags & InputAttachmentRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InputAttachmentRead";
	}
	if (flags & ShaderRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderRead";
	}
	if (flags & ShaderWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderWrite";
	}
	if (flags & ColorAttachmentRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentRead";
	}
	if (flags & ColorAttachmentWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentWrite";
	}
	if (flags & DepthStencilAttachmentRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachmentRead";
	}
	if (flags & DepthStencilAttachmentWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachmentWrite";
	}
	if (flags & TransferRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferRead";
	}
	if (flags & TransferWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferWrite";
	}
	if (flags & HostRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostRead";
	}
	if (flags & HostWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostWrite";
	}
	if (flags & MemoryRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryRead";
	}
	if (flags & MemoryWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryWrite";
	}
	if (flags & CommandPreprocessReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CommandPreprocessReadBitEXT";
	}
	if (flags & CommandPreprocessWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CommandPreprocessWriteBitEXT";
	}
	if (flags & ColorAttachmentReadNoncoherentBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentReadNoncoherentBitEXT";
	}
	if (flags & ConditionalRenderingReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConditionalRenderingReadBitEXT";
	}
	if (flags & AccelerationStructureReadBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureReadBitKHR";
	}
	if (flags & AccelerationStructureWriteBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureWriteBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentReadBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachmentReadBitKHR";
	}
	if (flags & FragmentDensityMapReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapReadBitEXT";
	}
	if (flags & TransformFeedbackWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackWriteBitEXT";
	}
	if (flags & TransformFeedbackCounterReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackCounterReadBitEXT";
	}
	if (flags & TransformFeedbackCounterWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "TransformFeedbackCounterWriteBitEXT";
	}
	return ret;
}
template<> auto flagsToString(AccessFlags2 flags) -> std::string {
	using enum AccessBits2;
	if ((flags & AllBits) != flags) {
		return "AccessBits2 does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & IndirectCommandRead) {
		bytes += 22;
	}
	if (flags & IndexRead) {
		bytes += 12;
	}
	if (flags & VertexAttributeRead) {
		bytes += 22;
	}
	if (flags & UniformRead) {
		bytes += 14;
	}
	if (flags & InputAttachmentRead) {
		bytes += 22;
	}
	if (flags & ShaderRead) {
		bytes += 13;
	}
	if (flags & ShaderWrite) {
		bytes += 14;
	}
	if (flags & ColorAttachmentRead) {
		bytes += 22;
	}
	if (flags & ColorAttachmentWrite) {
		bytes += 23;
	}
	if (flags & DepthStencilAttachmentRead) {
		bytes += 29;
	}
	if (flags & DepthStencilAttachmentWrite) {
		bytes += 30;
	}
	if (flags & TransferRead) {
		bytes += 15;
	}
	if (flags & TransferWrite) {
		bytes += 16;
	}
	if (flags & HostRead) {
		bytes += 11;
	}
	if (flags & HostWrite) {
		bytes += 12;
	}
	if (flags & MemoryRead) {
		bytes += 13;
	}
	if (flags & MemoryWrite) {
		bytes += 14;
	}
	if (flags & CommandPreprocessReadBitEXT) {
		bytes += 30;
	}
	if (flags & CommandPreprocessWriteBitEXT) {
		bytes += 31;
	}
	if (flags & ColorAttachmentReadNoncoherentBitEXT) {
		bytes += 39;
	}
	if (flags & ConditionalRenderingReadBitEXT) {
		bytes += 33;
	}
	if (flags & AccelerationStructureReadBitKHR) {
		bytes += 34;
	}
	if (flags & AccelerationStructureWriteBitKHR) {
		bytes += 35;
	}
	if (flags & FragmentShadingRateAttachmentReadBitKHR) {
		bytes += 42;
	}
	if (flags & FragmentDensityMapReadBitEXT) {
		bytes += 31;
	}
	if (flags & TransformFeedbackWriteBitEXT) {
		bytes += 31;
	}
	if (flags & TransformFeedbackCounterReadBitEXT) {
		bytes += 37;
	}
	if (flags & TransformFeedbackCounterWriteBitEXT) {
		bytes += 38;
	}
	if (flags & ShaderSampledRead) {
		bytes += 20;
	}
	if (flags & ShaderStorageRead) {
		bytes += 20;
	}
	if (flags & ShaderStorageWrite) {
		bytes += 21;
	}
	if (flags & VideoDecodeReadBitKHR) {
		bytes += 24;
	}
	if (flags & VideoDecodeWriteBitKHR) {
		bytes += 25;
	}
	if (flags & VideoEncodeReadBitKHR) {
		bytes += 24;
	}
	if (flags & VideoEncodeWriteBitKHR) {
		bytes += 25;
	}
	if (flags & InvocationMaskReadBitHUAWEI) {
		bytes += 30;
	}
	if (flags & ShaderBindingTableReadBitKHR) {
		bytes += 31;
	}
	if (flags & DescriptorBufferReadBitEXT) {
		bytes += 29;
	}
	if (flags & OpticalFlowReadBitNV) {
		bytes += 23;
	}
	if (flags & OpticalFlowWriteBitNV) {
		bytes += 24;
	}
	if (flags & MicromapReadBitEXT) {
		bytes += 21;
	}
	if (flags & MicromapWriteBitEXT) {
		bytes += 22;
	}
	if (flags & DataGraphReadBitARM) {
		bytes += 22;
	}
	if (flags & DataGraphWriteBitARM) {
		bytes += 23;
	}
	if (flags & ShaderTileAttachmentReadBitQCOM) {
		bytes += 34;
	}
	if (flags & ShaderTileAttachmentWriteBitQCOM) {
		bytes += 35;
	}
	if (flags & MemoryDecompressionReadBitEXT) {
		bytes += 32;
	}
	if (flags & MemoryDecompressionWriteBitEXT) {
		bytes += 33;
	}
	if (flags & SamplerHeapReadBitEXT) {
		bytes += 24;
	}
	if (flags & ResourceHeapReadBitEXT) {
		bytes += 25;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & IndirectCommandRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectCommandRead";
	}
	if (flags & IndexRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndexRead";
	}
	if (flags & VertexAttributeRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexAttributeRead";
	}
	if (flags & UniformRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformRead";
	}
	if (flags & InputAttachmentRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InputAttachmentRead";
	}
	if (flags & ShaderRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderRead";
	}
	if (flags & ShaderWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderWrite";
	}
	if (flags & ColorAttachmentRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentRead";
	}
	if (flags & ColorAttachmentWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentWrite";
	}
	if (flags & DepthStencilAttachmentRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachmentRead";
	}
	if (flags & DepthStencilAttachmentWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachmentWrite";
	}
	if (flags & TransferRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferRead";
	}
	if (flags & TransferWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferWrite";
	}
	if (flags & HostRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostRead";
	}
	if (flags & HostWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostWrite";
	}
	if (flags & MemoryRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryRead";
	}
	if (flags & MemoryWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryWrite";
	}
	if (flags & CommandPreprocessReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CommandPreprocessReadBitEXT";
	}
	if (flags & CommandPreprocessWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CommandPreprocessWriteBitEXT";
	}
	if (flags & ColorAttachmentReadNoncoherentBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentReadNoncoherentBitEXT";
	}
	if (flags & ConditionalRenderingReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConditionalRenderingReadBitEXT";
	}
	if (flags & AccelerationStructureReadBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureReadBitKHR";
	}
	if (flags & AccelerationStructureWriteBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureWriteBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentReadBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachmentReadBitKHR";
	}
	if (flags & FragmentDensityMapReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapReadBitEXT";
	}
	if (flags & TransformFeedbackWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackWriteBitEXT";
	}
	if (flags & TransformFeedbackCounterReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackCounterReadBitEXT";
	}
	if (flags & TransformFeedbackCounterWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackCounterWriteBitEXT";
	}
	if (flags & ShaderSampledRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderSampledRead";
	}
	if (flags & ShaderStorageRead) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderStorageRead";
	}
	if (flags & ShaderStorageWrite) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderStorageWrite";
	}
	if (flags & VideoDecodeReadBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeReadBitKHR";
	}
	if (flags & VideoDecodeWriteBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeWriteBitKHR";
	}
	if (flags & VideoEncodeReadBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeReadBitKHR";
	}
	if (flags & VideoEncodeWriteBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeWriteBitKHR";
	}
	if (flags & InvocationMaskReadBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InvocationMaskReadBitHUAWEI";
	}
	if (flags & ShaderBindingTableReadBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderBindingTableReadBitKHR";
	}
	if (flags & DescriptorBufferReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferReadBitEXT";
	}
	if (flags & OpticalFlowReadBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpticalFlowReadBitNV";
	}
	if (flags & OpticalFlowWriteBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpticalFlowWriteBitNV";
	}
	if (flags & MicromapReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapReadBitEXT";
	}
	if (flags & MicromapWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapWriteBitEXT";
	}
	if (flags & DataGraphReadBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphReadBitARM";
	}
	if (flags & DataGraphWriteBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphWriteBitARM";
	}
	if (flags & ShaderTileAttachmentReadBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderTileAttachmentReadBitQCOM";
	}
	if (flags & ShaderTileAttachmentWriteBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderTileAttachmentWriteBitQCOM";
	}
	if (flags & MemoryDecompressionReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryDecompressionReadBitEXT";
	}
	if (flags & MemoryDecompressionWriteBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryDecompressionWriteBitEXT";
	}
	if (flags & SamplerHeapReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SamplerHeapReadBitEXT";
	}
	if (flags & ResourceHeapReadBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "ResourceHeapReadBitEXT";
	}
	return ret;
}
template<> auto flagsToString(AccessFlags3KHR flags) -> std::string {
	using enum AccessBits3KHR;
	if (flags & None) {
		return "None";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & FullyBound) {
		bytes += 13;
	}
	if (flags & StorageBufferUsage) {
		bytes += 21;
	}
	if (flags & UnknownStorageBufferUsage) {
		bytes += 28;
	}
	if (flags & TransformFeedbackBufferUsage) {
		bytes += 31;
	}
	if (flags & UnknownTransformFeedbackBufferUsage) {
		bytes += 38;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Protected) {
		first = false;
		ret += "Protected";
	}
	if (flags & FullyBound) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FullyBound";
	}
	if (flags & StorageBufferUsage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageBufferUsage";
	}
	if (flags & UnknownStorageBufferUsage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UnknownStorageBufferUsage";
	}
	if (flags & TransformFeedbackBufferUsage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackBufferUsage";
	}
	if (flags & UnknownTransformFeedbackBufferUsage) {
		if (!first) {
			ret += " | ";
		}
		ret += "UnknownTransformFeedbackBufferUsage";
	}
	return ret;
}
template<> auto flagsToString(AddressCopyFlagsKHR flags) -> std::string {
	using enum AddressCopyBitsKHR;
	if ((flags & AllBits) != flags) {
		return "AddressCopyBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DeviceLocal) {
		bytes += 14;
	}
	if (flags & Sparse) {
		bytes += 9;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DeviceLocal) {
		first = false;
		ret += "DeviceLocal";
	}
	if (flags & Sparse) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Sparse";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		ret += "Protected";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & MayAlias) {
		bytes += 11;
	}
	if (flags & ResolveSkipTransferFunctionBitKHR) {
		bytes += 36;
	}
	if (flags & ResolveEnableTransferFunctionBitKHR) {
		bytes += 38;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & MayAlias) {
		first = false;
		ret += "MayAlias";
	}
	if (flags & ResolveSkipTransferFunctionBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ResolveSkipTransferFunctionBitKHR";
	}
	if (flags & ResolveEnableTransferFunctionBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "ResolveEnableTransferFunctionBitKHR";
	}
	return ret;
}
template<> auto flagsToString(BufferCreateFlags flags) -> std::string {
	using enum BufferCreateBits;
	if ((flags & AllBits) != flags) {
		return "BufferCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SparseBinding) {
		bytes += 16;
	}
	if (flags & SparseResidency) {
		bytes += 18;
	}
	if (flags & SparseAliased) {
		bytes += 16;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & DeviceAddressCaptureReplay) {
		bytes += 29;
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		bytes += 38;
	}
	if (flags & VideoProfileIndependentBitKHR) {
		bytes += 32;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SparseBinding) {
		first = false;
		ret += "SparseBinding";
	}
	if (flags & SparseResidency) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SparseResidency";
	}
	if (flags & SparseAliased) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SparseAliased";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Protected";
	}
	if (flags & DeviceAddressCaptureReplay) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeviceAddressCaptureReplay";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferCaptureReplayBitEXT";
	}
	if (flags & VideoProfileIndependentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "VideoProfileIndependentBitKHR";
	}
	return ret;
}
template<> auto flagsToString(BufferUsageFlags flags) -> std::string {
	using enum BufferUsageBits;
	if ((flags & AllBits) != flags) {
		return "BufferUsageBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & TransferSrc) {
		bytes += 14;
	}
	if (flags & TransferDst) {
		bytes += 14;
	}
	if (flags & UniformTexelBuffer) {
		bytes += 21;
	}
	if (flags & StorageTexelBuffer) {
		bytes += 21;
	}
	if (flags & UniformBuffer) {
		bytes += 16;
	}
	if (flags & StorageBuffer) {
		bytes += 16;
	}
	if (flags & IndexBuffer) {
		bytes += 14;
	}
	if (flags & VertexBuffer) {
		bytes += 15;
	}
	if (flags & IndirectBuffer) {
		bytes += 17;
	}
	if (flags & ConditionalRenderingBitEXT) {
		bytes += 29;
	}
	if (flags & ShaderBindingTableBitKHR) {
		bytes += 27;
	}
	if (flags & TransformFeedbackBufferBitEXT) {
		bytes += 32;
	}
	if (flags & TransformFeedbackCounterBufferBitEXT) {
		bytes += 39;
	}
	if (flags & VideoDecodeSrcBitKHR) {
		bytes += 23;
	}
	if (flags & VideoDecodeDstBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeDstBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeSrcBitKHR) {
		bytes += 23;
	}
	if (flags & ShaderDeviceAddress) {
		bytes += 22;
	}
	if (flags & AccelerationStructureBuildInputReadOnlyBitKHR) {
		bytes += 48;
	}
	if (flags & AccelerationStructureStorageBitKHR) {
		bytes += 37;
	}
	if (flags & SamplerDescriptorBufferBitEXT) {
		bytes += 32;
	}
	if (flags & ResourceDescriptorBufferBitEXT) {
		bytes += 33;
	}
	if (flags & MicromapBuildInputReadOnlyBitEXT) {
		bytes += 35;
	}
	if (flags & MicromapStorageBitEXT) {
		bytes += 24;
	}
	if (flags & ExecutionGraphScratchBitAMDX) {
		bytes += 31;
	}
	if (flags & PushDescriptorsDescriptorBufferBitEXT) {
		bytes += 40;
	}
	if (flags & TileMemoryBitQCOM) {
		bytes += 20;
	}
	if (flags & DescriptorHeapBitEXT) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & TransferSrc) {
		first = false;
		ret += "TransferSrc";
	}
	if (flags & TransferDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferDst";
	}
	if (flags & UniformTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageTexelBuffer";
	}
	if (flags & UniformBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformBuffer";
	}
	if (flags & StorageBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageBuffer";
	}
	if (flags & IndexBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndexBuffer";
	}
	if (flags & VertexBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexBuffer";
	}
	if (flags & IndirectBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectBuffer";
	}
	if (flags & ConditionalRenderingBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConditionalRenderingBitEXT";
	}
	if (flags & ShaderBindingTableBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderBindingTableBitKHR";
	}
	if (flags & TransformFeedbackBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackBufferBitEXT";
	}
	if (flags & TransformFeedbackCounterBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackCounterBufferBitEXT";
	}
	if (flags & VideoDecodeSrcBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeSrcBitKHR";
	}
	if (flags & VideoDecodeDstBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDstBitKHR";
	}
	if (flags & VideoEncodeDstBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDstBitKHR";
	}
	if (flags & VideoEncodeSrcBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeSrcBitKHR";
	}
	if (flags & ShaderDeviceAddress) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderDeviceAddress";
	}
	if (flags & AccelerationStructureBuildInputReadOnlyBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureBuildInputReadOnlyBitKHR";
	}
	if (flags & AccelerationStructureStorageBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureStorageBitKHR";
	}
	if (flags & SamplerDescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SamplerDescriptorBufferBitEXT";
	}
	if (flags & ResourceDescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ResourceDescriptorBufferBitEXT";
	}
	if (flags & MicromapBuildInputReadOnlyBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapBuildInputReadOnlyBitEXT";
	}
	if (flags & MicromapStorageBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapStorageBitEXT";
	}
	if (flags & ExecutionGraphScratchBitAMDX) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ExecutionGraphScratchBitAMDX";
	}
	if (flags & PushDescriptorsDescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PushDescriptorsDescriptorBufferBitEXT";
	}
	if (flags & TileMemoryBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TileMemoryBitQCOM";
	}
	if (flags & DescriptorHeapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "DescriptorHeapBitEXT";
	}
	return ret;
}
template<> auto flagsToString(BufferUsageFlags2 flags) -> std::string {
	using enum BufferUsageBits2;
	if ((flags & AllBits) != flags) {
		return "BufferUsageBits2 does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & TransferSrc) {
		bytes += 14;
	}
	if (flags & TransferDst) {
		bytes += 14;
	}
	if (flags & UniformTexelBuffer) {
		bytes += 21;
	}
	if (flags & StorageTexelBuffer) {
		bytes += 21;
	}
	if (flags & UniformBuffer) {
		bytes += 16;
	}
	if (flags & StorageBuffer) {
		bytes += 16;
	}
	if (flags & IndexBuffer) {
		bytes += 14;
	}
	if (flags & VertexBuffer) {
		bytes += 15;
	}
	if (flags & IndirectBuffer) {
		bytes += 17;
	}
	if (flags & ConditionalRenderingBitEXT) {
		bytes += 29;
	}
	if (flags & ShaderBindingTableBitKHR) {
		bytes += 27;
	}
	if (flags & TransformFeedbackBufferBitEXT) {
		bytes += 32;
	}
	if (flags & TransformFeedbackCounterBufferBitEXT) {
		bytes += 39;
	}
	if (flags & VideoDecodeSrcBitKHR) {
		bytes += 23;
	}
	if (flags & VideoDecodeDstBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeDstBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeSrcBitKHR) {
		bytes += 23;
	}
	if (flags & ShaderDeviceAddress) {
		bytes += 22;
	}
	if (flags & AccelerationStructureBuildInputReadOnlyBitKHR) {
		bytes += 48;
	}
	if (flags & AccelerationStructureStorageBitKHR) {
		bytes += 37;
	}
	if (flags & SamplerDescriptorBufferBitEXT) {
		bytes += 32;
	}
	if (flags & ResourceDescriptorBufferBitEXT) {
		bytes += 33;
	}
	if (flags & MicromapBuildInputReadOnlyBitEXT) {
		bytes += 35;
	}
	if (flags & MicromapStorageBitEXT) {
		bytes += 24;
	}
	if (flags & ExecutionGraphScratchBitAMDX) {
		bytes += 31;
	}
	if (flags & PushDescriptorsDescriptorBufferBitEXT) {
		bytes += 40;
	}
	if (flags & TileMemoryBitQCOM) {
		bytes += 20;
	}
	if (flags & DescriptorHeapBitEXT) {
		bytes += 23;
	}
	if (flags & DataGraphForeignDescriptorBitARM) {
		bytes += 35;
	}
	if (flags & PreprocessBufferBitEXT) {
		bytes += 25;
	}
	if (flags & MemoryDecompressionBitEXT) {
		bytes += 28;
	}
	if (flags & CompressedDataDgf1BitAMDX) {
		bytes += 28;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & TransferSrc) {
		first = false;
		ret += "TransferSrc";
	}
	if (flags & TransferDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferDst";
	}
	if (flags & UniformTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageTexelBuffer";
	}
	if (flags & UniformBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformBuffer";
	}
	if (flags & StorageBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageBuffer";
	}
	if (flags & IndexBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndexBuffer";
	}
	if (flags & VertexBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexBuffer";
	}
	if (flags & IndirectBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectBuffer";
	}
	if (flags & ConditionalRenderingBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConditionalRenderingBitEXT";
	}
	if (flags & ShaderBindingTableBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderBindingTableBitKHR";
	}
	if (flags & TransformFeedbackBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackBufferBitEXT";
	}
	if (flags & TransformFeedbackCounterBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackCounterBufferBitEXT";
	}
	if (flags & VideoDecodeSrcBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeSrcBitKHR";
	}
	if (flags & VideoDecodeDstBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDstBitKHR";
	}
	if (flags & VideoEncodeDstBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDstBitKHR";
	}
	if (flags & VideoEncodeSrcBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeSrcBitKHR";
	}
	if (flags & ShaderDeviceAddress) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShaderDeviceAddress";
	}
	if (flags & AccelerationStructureBuildInputReadOnlyBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureBuildInputReadOnlyBitKHR";
	}
	if (flags & AccelerationStructureStorageBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureStorageBitKHR";
	}
	if (flags & SamplerDescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SamplerDescriptorBufferBitEXT";
	}
	if (flags & ResourceDescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ResourceDescriptorBufferBitEXT";
	}
	if (flags & MicromapBuildInputReadOnlyBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapBuildInputReadOnlyBitEXT";
	}
	if (flags & MicromapStorageBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapStorageBitEXT";
	}
	if (flags & ExecutionGraphScratchBitAMDX) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ExecutionGraphScratchBitAMDX";
	}
	if (flags & PushDescriptorsDescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PushDescriptorsDescriptorBufferBitEXT";
	}
	if (flags & TileMemoryBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TileMemoryBitQCOM";
	}
	if (flags & DescriptorHeapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorHeapBitEXT";
	}
	if (flags & DataGraphForeignDescriptorBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphForeignDescriptorBitARM";
	}
	if (flags & PreprocessBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PreprocessBufferBitEXT";
	}
	if (flags & MemoryDecompressionBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryDecompressionBitEXT";
	}
	if (flags & CompressedDataDgf1BitAMDX) {
		if (!first) {
			ret += " | ";
		}
		ret += "CompressedDataDgf1BitAMDX";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & AllowUpdate) {
		bytes += 14;
	}
	if (flags & AllowCompaction) {
		bytes += 18;
	}
	if (flags & PreferFastTrace) {
		bytes += 18;
	}
	if (flags & PreferFastBuild) {
		bytes += 18;
	}
	if (flags & LowMemory) {
		bytes += 12;
	}
	if (flags & MotionBitNV) {
		bytes += 14;
	}
	if (flags & AllowOpacityMicromapUpdate) {
		bytes += 29;
	}
	if (flags & AllowDisableOpacityMicromaps) {
		bytes += 31;
	}
	if (flags & AllowOpacityMicromapDataUpdateBitEXT) {
		bytes += 39;
	}
	if (flags & AllowDisplacementMicromapUpdateBitNV) {
		bytes += 39;
	}
	if (flags & MicromapLossy) {
		bytes += 16;
	}
	if (flags & AllowDataAccess) {
		bytes += 18;
	}
	if (flags & AllowClusterOpacityMicromapsBitNV) {
		bytes += 36;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & AllowUpdate) {
		first = false;
		ret += "AllowUpdate";
	}
	if (flags & AllowCompaction) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowCompaction";
	}
	if (flags & PreferFastTrace) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PreferFastTrace";
	}
	if (flags & PreferFastBuild) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PreferFastBuild";
	}
	if (flags & LowMemory) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LowMemory";
	}
	if (flags & MotionBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MotionBitNV";
	}
	if (flags & AllowOpacityMicromapUpdate) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowOpacityMicromapUpdate";
	}
	if (flags & AllowDisableOpacityMicromaps) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowDisableOpacityMicromaps";
	}
	if (flags & AllowOpacityMicromapDataUpdateBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowOpacityMicromapDataUpdateBitEXT";
	}
	if (flags & AllowDisplacementMicromapUpdateBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowDisplacementMicromapUpdateBitNV";
	}
	if (flags & MicromapLossy) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapLossy";
	}
	if (flags & AllowDataAccess) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowDataAccess";
	}
	if (flags & AllowClusterOpacityMicromapsBitNV) {
		if (!first) {
			ret += " | ";
		}
		ret += "AllowClusterOpacityMicromapsBitNV";
	}
	return ret;
}
template<> auto flagsToString(BuildMicromapFlagsEXT flags) -> std::string {
	using enum BuildMicromapBitsEXT;
	if ((flags & AllBits) != flags) {
		return "BuildMicromapBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & PreferFastTrace) {
		bytes += 18;
	}
	if (flags & PreferFastBuild) {
		bytes += 18;
	}
	if (flags & AllowCompaction) {
		bytes += 18;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & PreferFastTrace) {
		first = false;
		ret += "PreferFastTrace";
	}
	if (flags & PreferFastBuild) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PreferFastBuild";
	}
	if (flags & AllowCompaction) {
		if (!first) {
			ret += " | ";
		}
		ret += "AllowCompaction";
	}
	return ret;
}
template<> auto flagsToString(ClusterAccelerationStructureAddressResolutionFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureAddressResolutionBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureAddressResolutionBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & IndirectedDstImplicitData) {
		bytes += 28;
	}
	if (flags & IndirectedScratchData) {
		bytes += 24;
	}
	if (flags & IndirectedDstAddressArray) {
		bytes += 28;
	}
	if (flags & IndirectedDstSizesArray) {
		bytes += 26;
	}
	if (flags & IndirectedSrcInfosArray) {
		bytes += 26;
	}
	if (flags & IndirectedSrcInfosCount) {
		bytes += 26;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & IndirectedDstImplicitData) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectedDstImplicitData";
	}
	if (flags & IndirectedScratchData) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectedScratchData";
	}
	if (flags & IndirectedDstAddressArray) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectedDstAddressArray";
	}
	if (flags & IndirectedDstSizesArray) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectedDstSizesArray";
	}
	if (flags & IndirectedSrcInfosArray) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectedSrcInfosArray";
	}
	if (flags & IndirectedSrcInfosCount) {
		if (!first) {
			ret += " | ";
		}
		ret += "IndirectedSrcInfosCount";
	}
	return ret;
}
template<> auto flagsToString(ClusterAccelerationStructureClusterFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureClusterBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureClusterBitsNV does contain a bit that is not possible to be set";
	}
	if (flags & AllowDisableOpacityMicromaps) {
		return "AllowDisableOpacityMicromaps";
	}
	return "";
}
template<> auto flagsToString(ClusterAccelerationStructureGeometryFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureGeometryBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureGeometryBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & CullDisable) {
		bytes += 14;
	}
	if (flags & NoDuplicateAnyhitInvocation) {
		bytes += 30;
	}
	if (flags & Opaque) {
		bytes += 9;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & CullDisable) {
		first = false;
		ret += "CullDisable";
	}
	if (flags & NoDuplicateAnyhitInvocation) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "NoDuplicateAnyhitInvocation";
	}
	if (flags & Opaque) {
		if (!first) {
			ret += " | ";
		}
		ret += "Opaque";
	}
	return ret;
}
template<> auto flagsToString(ClusterAccelerationStructureIndexFormatFlagsNV flags) -> std::string {
	using enum ClusterAccelerationStructureIndexFormatBitsNV;
	if ((flags & AllBits) != flags) {
		return "ClusterAccelerationStructureIndexFormatBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & v8) {
		bytes += 5;
	}
	if (flags & v16) {
		bytes += 6;
	}
	if (flags & v32) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & v8) {
		first = false;
		ret += "v8";
	}
	if (flags & v16) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v16";
	}
	if (flags & v32) {
		if (!first) {
			ret += " | ";
		}
		ret += "v32";
	}
	return ret;
}
template<> auto flagsToString(ColorComponentFlags flags) -> std::string {
	using enum ColorComponentBits;
	if ((flags & AllBits) != flags) {
		return "ColorComponentBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & R) {
		bytes += 4;
	}
	if (flags & G) {
		bytes += 4;
	}
	if (flags & B) {
		bytes += 4;
	}
	if (flags & A) {
		bytes += 4;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & R) {
		first = false;
		ret += "R";
	}
	if (flags & G) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "G";
	}
	if (flags & B) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "B";
	}
	if (flags & A) {
		if (!first) {
			ret += " | ";
		}
		ret += "A";
	}
	return ret;
}
template<> auto flagsToString(CommandBufferResetFlags flags) -> std::string {
	using enum CommandBufferResetBits;
	if ((flags & AllBits) != flags) {
		return "CommandBufferResetBits does contain a bit that is not possible to be set";
	}
	if (flags & ReleaseResources) {
		return "ReleaseResources";
	}
	return "";
}
template<> auto flagsToString(CommandBufferUsageFlags flags) -> std::string {
	using enum CommandBufferUsageBits;
	if ((flags & AllBits) != flags) {
		return "CommandBufferUsageBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & OneTimeSubmit) {
		bytes += 16;
	}
	if (flags & RenderPassContinue) {
		bytes += 21;
	}
	if (flags & SimultaneousUse) {
		bytes += 18;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & OneTimeSubmit) {
		first = false;
		ret += "OneTimeSubmit";
	}
	if (flags & RenderPassContinue) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RenderPassContinue";
	}
	if (flags & SimultaneousUse) {
		if (!first) {
			ret += " | ";
		}
		ret += "SimultaneousUse";
	}
	return ret;
}
template<> auto flagsToString(CommandPoolCreateFlags flags) -> std::string {
	using enum CommandPoolCreateBits;
	if ((flags & AllBits) != flags) {
		return "CommandPoolCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Transient) {
		bytes += 12;
	}
	if (flags & ResetCommandBuffer) {
		bytes += 21;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Transient) {
		first = false;
		ret += "Transient";
	}
	if (flags & ResetCommandBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ResetCommandBuffer";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		ret += "Protected";
	}
	return ret;
}
template<> auto flagsToString(CommandPoolResetFlags flags) -> std::string {
	using enum CommandPoolResetBits;
	if ((flags & AllBits) != flags) {
		return "CommandPoolResetBits does contain a bit that is not possible to be set";
	}
	if (flags & ReleaseResources) {
		return "ReleaseResources";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & Opaque) {
		bytes += 9;
	}
	if (flags & PreMultiplied) {
		bytes += 16;
	}
	if (flags & PostMultiplied) {
		bytes += 17;
	}
	if (flags & Inherit) {
		bytes += 10;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Opaque) {
		first = false;
		ret += "Opaque";
	}
	if (flags & PreMultiplied) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PreMultiplied";
	}
	if (flags & PostMultiplied) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PostMultiplied";
	}
	if (flags & Inherit) {
		if (!first) {
			ret += " | ";
		}
		ret += "Inherit";
	}
	return ret;
}
template<> auto flagsToString(ConditionalRenderingFlagsEXT flags) -> std::string {
	using enum ConditionalRenderingBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ConditionalRenderingBitsEXT does contain a bit that is not possible to be set";
	}
	if (flags & Inverted) {
		return "Inverted";
	}
	return "";
}
template<> auto flagsToString(CooperativeMatrixFlagsEXT flags) -> std::string {
	using enum CooperativeMatrixBitsEXT;
	if ((flags & AllBits) != flags) {
		return "CooperativeMatrixBitsEXT does contain a bit that is not possible to be set";
	}
	if (flags & SaturatingAccumulation) {
		return "SaturatingAccumulation";
	}
	return "";
}
template<> auto flagsToString(CullModeFlags flags) -> std::string {
	using enum CullModeBits;
	if ((flags & AllBits) != flags) {
		return "CullModeBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & Front) {
		bytes += 8;
	}
	if (flags & Back) {
		bytes += 7;
	}
	if (flags & FrontAndBack) {
		bytes += 15;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & Front) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Front";
	}
	if (flags & Back) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Back";
	}
	if (flags & FrontAndBack) {
		if (!first) {
			ret += " | ";
		}
		ret += "FrontAndBack";
	}
	return ret;
}
template<> auto flagsToString(DataGraphOpticalFlowCreateFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowCreateBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowCreateBitsARM does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & EnableHint) {
		bytes += 13;
	}
	if (flags & EnableCost) {
		bytes += 13;
	}
	if (flags & Reserved30) {
		bytes += 13;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & EnableHint) {
		first = false;
		ret += "EnableHint";
	}
	if (flags & EnableCost) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableCost";
	}
	if (flags & Reserved30) {
		if (!first) {
			ret += " | ";
		}
		ret += "Reserved30";
	}
	return ret;
}
template<> auto flagsToString(DataGraphOpticalFlowExecuteFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowExecuteBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowExecuteBitsARM does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DisableTemporalHints) {
		bytes += 23;
	}
	if (flags & InputUnchanged) {
		bytes += 17;
	}
	if (flags & ReferenceUnchanged) {
		bytes += 21;
	}
	if (flags & InputIsPreviousReference) {
		bytes += 27;
	}
	if (flags & ReferenceIsPreviousInput) {
		bytes += 27;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DisableTemporalHints) {
		first = false;
		ret += "DisableTemporalHints";
	}
	if (flags & InputUnchanged) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InputUnchanged";
	}
	if (flags & ReferenceUnchanged) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReferenceUnchanged";
	}
	if (flags & InputIsPreviousReference) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InputIsPreviousReference";
	}
	if (flags & ReferenceIsPreviousInput) {
		if (!first) {
			ret += " | ";
		}
		ret += "ReferenceIsPreviousInput";
	}
	return ret;
}
template<> auto flagsToString(DataGraphOpticalFlowGridSizeFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowGridSizeBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowGridSizeBitsARM does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Unknown) {
		bytes += 10;
	}
	if (flags & v1x1) {
		bytes += 7;
	}
	if (flags & v2x2) {
		bytes += 7;
	}
	if (flags & v4x4) {
		bytes += 7;
	}
	if (flags & v8x8) {
		bytes += 7;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Unknown) {
		first = false;
		ret += "Unknown";
	}
	if (flags & v1x1) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v1x1";
	}
	if (flags & v2x2) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2x2";
	}
	if (flags & v4x4) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v4x4";
	}
	if (flags & v8x8) {
		if (!first) {
			ret += " | ";
		}
		ret += "v8x8";
	}
	return ret;
}
template<> auto flagsToString(DataGraphOpticalFlowImageUsageFlagsARM flags) -> std::string {
	using enum DataGraphOpticalFlowImageUsageBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphOpticalFlowImageUsageBitsARM does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Unknown) {
		bytes += 10;
	}
	if (flags & Input) {
		bytes += 8;
	}
	if (flags & Output) {
		bytes += 9;
	}
	if (flags & Hint) {
		bytes += 7;
	}
	if (flags & Cost) {
		bytes += 7;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Unknown) {
		first = false;
		ret += "Unknown";
	}
	if (flags & Input) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Input";
	}
	if (flags & Output) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Output";
	}
	if (flags & Hint) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Hint";
	}
	if (flags & Cost) {
		if (!first) {
			ret += " | ";
		}
		ret += "Cost";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & OpticalFlowCache) {
		bytes += 19;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Protected) {
		first = false;
		ret += "Protected";
	}
	if (flags & OpticalFlowCache) {
		if (!first) {
			ret += " | ";
		}
		ret += "OpticalFlowCache";
	}
	return ret;
}
template<> auto flagsToString(DataGraphTOSAQualityFlagsARM flags) -> std::string {
	using enum DataGraphTOSAQualityBitsARM;
	if ((flags & AllBits) != flags) {
		return "DataGraphTOSAQualityBitsARM does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DataGraphTosaQualityAccelerated) {
		bytes += 34;
	}
	if (flags & DataGraphTosaQualityConformant) {
		bytes += 33;
	}
	if (flags & DataGraphTosaQualityExperimental) {
		bytes += 35;
	}
	if (flags & DataGraphTosaQualityDeprecated) {
		bytes += 33;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DataGraphTosaQualityAccelerated) {
		first = false;
		ret += "DataGraphTosaQualityAccelerated";
	}
	if (flags & DataGraphTosaQualityConformant) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphTosaQualityConformant";
	}
	if (flags & DataGraphTosaQualityExperimental) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphTosaQualityExperimental";
	}
	if (flags & DataGraphTosaQualityDeprecated) {
		if (!first) {
			ret += " | ";
		}
		ret += "DataGraphTosaQualityDeprecated";
	}
	return ret;
}
template<> auto flagsToString(DebugReportFlagsEXT flags) -> std::string {
	using enum DebugReportBitsEXT;
	if ((flags & AllBits) != flags) {
		return "DebugReportBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Information) {
		bytes += 14;
	}
	if (flags & Warning) {
		bytes += 10;
	}
	if (flags & PerformanceWarning) {
		bytes += 21;
	}
	if (flags & Error) {
		bytes += 8;
	}
	if (flags & Debug) {
		bytes += 8;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Information) {
		first = false;
		ret += "Information";
	}
	if (flags & Warning) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Warning";
	}
	if (flags & PerformanceWarning) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerformanceWarning";
	}
	if (flags & Error) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Error";
	}
	if (flags & Debug) {
		if (!first) {
			ret += " | ";
		}
		ret += "Debug";
	}
	return ret;
}
template<> auto flagsToString(DebugUtilsMessageSeverityFlagsEXT flags) -> std::string {
	using enum DebugUtilsMessageSeverityBitsEXT;
	if ((flags & AllBits) != flags) {
		return "DebugUtilsMessageSeverityBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Verbose) {
		bytes += 10;
	}
	if (flags & Info) {
		bytes += 7;
	}
	if (flags & Warning) {
		bytes += 10;
	}
	if (flags & Error) {
		bytes += 8;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Verbose) {
		first = false;
		ret += "Verbose";
	}
	if (flags & Info) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Info";
	}
	if (flags & Warning) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Warning";
	}
	if (flags & Error) {
		if (!first) {
			ret += " | ";
		}
		ret += "Error";
	}
	return ret;
}
template<> auto flagsToString(DebugUtilsMessageTypeFlagsEXT flags) -> std::string {
	using enum DebugUtilsMessageTypeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "DebugUtilsMessageTypeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & General) {
		bytes += 10;
	}
	if (flags & Validation) {
		bytes += 13;
	}
	if (flags & Performance) {
		bytes += 14;
	}
	if (flags & DeviceAddressBinding) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & General) {
		first = false;
		ret += "General";
	}
	if (flags & Validation) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Validation";
	}
	if (flags & Performance) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Performance";
	}
	if (flags & DeviceAddressBinding) {
		if (!first) {
			ret += " | ";
		}
		ret += "DeviceAddressBinding";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & ByRegion) {
		bytes += 11;
	}
	if (flags & ViewLocal) {
		bytes += 12;
	}
	if (flags & DeviceGroup) {
		bytes += 14;
	}
	if (flags & FeedbackLoopBitEXT) {
		bytes += 21;
	}
	if (flags & QueueFamilyOwnershipTransferUseAllStagesBitKHR) {
		bytes += 49;
	}
	if (flags & AsymmetricEventBitKHR) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ByRegion) {
		first = false;
		ret += "ByRegion";
	}
	if (flags & ViewLocal) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ViewLocal";
	}
	if (flags & DeviceGroup) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeviceGroup";
	}
	if (flags & FeedbackLoopBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FeedbackLoopBitEXT";
	}
	if (flags & QueueFamilyOwnershipTransferUseAllStagesBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "QueueFamilyOwnershipTransferUseAllStagesBitKHR";
	}
	if (flags & AsymmetricEventBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "AsymmetricEventBitKHR";
	}
	return ret;
}
template<> auto flagsToString(DescriptorBindingFlags flags) -> std::string {
	using enum DescriptorBindingBits;
	if ((flags & AllBits) != flags) {
		return "DescriptorBindingBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & UpdateAfterBind) {
		bytes += 18;
	}
	if (flags & UpdateUnusedWhilePending) {
		bytes += 27;
	}
	if (flags & PartiallyBound) {
		bytes += 17;
	}
	if (flags & VariableDescriptorCount) {
		bytes += 26;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & UpdateAfterBind) {
		first = false;
		ret += "UpdateAfterBind";
	}
	if (flags & UpdateUnusedWhilePending) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UpdateUnusedWhilePending";
	}
	if (flags & PartiallyBound) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PartiallyBound";
	}
	if (flags & VariableDescriptorCount) {
		if (!first) {
			ret += " | ";
		}
		ret += "VariableDescriptorCount";
	}
	return ret;
}
template<> auto flagsToString(DescriptorPoolCreateFlags flags) -> std::string {
	using enum DescriptorPoolCreateBits;
	if ((flags & AllBits) != flags) {
		return "DescriptorPoolCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & FreeDescriptorSet) {
		bytes += 20;
	}
	if (flags & UpdateAfterBind) {
		bytes += 18;
	}
	if (flags & HostOnlyBitEXT) {
		bytes += 17;
	}
	if (flags & AllowOverallocationSetsBitNV) {
		bytes += 31;
	}
	if (flags & AllowOverallocationPoolsBitNV) {
		bytes += 32;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & FreeDescriptorSet) {
		first = false;
		ret += "FreeDescriptorSet";
	}
	if (flags & UpdateAfterBind) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UpdateAfterBind";
	}
	if (flags & HostOnlyBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostOnlyBitEXT";
	}
	if (flags & AllowOverallocationSetsBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowOverallocationSetsBitNV";
	}
	if (flags & AllowOverallocationPoolsBitNV) {
		if (!first) {
			ret += " | ";
		}
		ret += "AllowOverallocationPoolsBitNV";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & PushDescriptor) {
		bytes += 17;
	}
	if (flags & UpdateAfterBindPool) {
		bytes += 22;
	}
	if (flags & HostOnlyPoolBitEXT) {
		bytes += 21;
	}
	if (flags & DescriptorBufferBitEXT) {
		bytes += 25;
	}
	if (flags & EmbeddedImmutableSamplersBitEXT) {
		bytes += 34;
	}
	if (flags & PerStageBitNV) {
		bytes += 16;
	}
	if (flags & IndirectBindableBitNV) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & PushDescriptor) {
		first = false;
		ret += "PushDescriptor";
	}
	if (flags & UpdateAfterBindPool) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UpdateAfterBindPool";
	}
	if (flags & HostOnlyPoolBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostOnlyPoolBitEXT";
	}
	if (flags & DescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferBitEXT";
	}
	if (flags & EmbeddedImmutableSamplersBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EmbeddedImmutableSamplersBitEXT";
	}
	if (flags & PerStageBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerStageBitNV";
	}
	if (flags & IndirectBindableBitNV) {
		if (!first) {
			ret += " | ";
		}
		ret += "IndirectBindableBitNV";
	}
	return ret;
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
	if (flags & InternalObject) {
		return "InternalObject";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & EnableShaderDebugInfo) {
		bytes += 24;
	}
	if (flags & EnableResourceTracking) {
		bytes += 25;
	}
	if (flags & EnableAutomaticCheckpoints) {
		bytes += 29;
	}
	if (flags & EnableShaderErrorReporting) {
		bytes += 29;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & EnableShaderDebugInfo) {
		first = false;
		ret += "EnableShaderDebugInfo";
	}
	if (flags & EnableResourceTracking) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableResourceTracking";
	}
	if (flags & EnableAutomaticCheckpoints) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableAutomaticCheckpoints";
	}
	if (flags & EnableShaderErrorReporting) {
		if (!first) {
			ret += " | ";
		}
		ret += "EnableShaderErrorReporting";
	}
	return ret;
}
template<> auto flagsToString(DeviceFaultFlagsKHR flags) -> std::string {
	using enum DeviceFaultBitsKHR;
	if ((flags & AllBits) != flags) {
		return "DeviceFaultBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & FlagDeviceLost) {
		bytes += 17;
	}
	if (flags & FlagMemoryAddress) {
		bytes += 20;
	}
	if (flags & FlagInstructionAddress) {
		bytes += 25;
	}
	if (flags & FlagVendor) {
		bytes += 13;
	}
	if (flags & FlagWatchdogTimeout) {
		bytes += 22;
	}
	if (flags & FlagOverflow) {
		bytes += 15;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & FlagDeviceLost) {
		first = false;
		ret += "FlagDeviceLost";
	}
	if (flags & FlagMemoryAddress) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FlagMemoryAddress";
	}
	if (flags & FlagInstructionAddress) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FlagInstructionAddress";
	}
	if (flags & FlagVendor) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FlagVendor";
	}
	if (flags & FlagWatchdogTimeout) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FlagWatchdogTimeout";
	}
	if (flags & FlagOverflow) {
		if (!first) {
			ret += " | ";
		}
		ret += "FlagOverflow";
	}
	return ret;
}
template<> auto flagsToString(DeviceGroupPresentModeFlagsKHR flags) -> std::string {
	using enum DeviceGroupPresentModeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "DeviceGroupPresentModeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Local) {
		bytes += 8;
	}
	if (flags & Remote) {
		bytes += 9;
	}
	if (flags & Sum) {
		bytes += 6;
	}
	if (flags & LocalMultiDevice) {
		bytes += 19;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Local) {
		first = false;
		ret += "Local";
	}
	if (flags & Remote) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Remote";
	}
	if (flags & Sum) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Sum";
	}
	if (flags & LocalMultiDevice) {
		if (!first) {
			ret += " | ";
		}
		ret += "LocalMultiDevice";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & InternallySynchronizedBitKHR) {
		bytes += 31;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Protected) {
		first = false;
		ret += "Protected";
	}
	if (flags & InternallySynchronizedBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "InternallySynchronizedBitKHR";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Opaque) {
		bytes += 9;
	}
	if (flags & Global) {
		bytes += 9;
	}
	if (flags & PerPixel) {
		bytes += 11;
	}
	if (flags & PerPixelPremultiplied) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Opaque) {
		first = false;
		ret += "Opaque";
	}
	if (flags & Global) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Global";
	}
	if (flags & PerPixel) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerPixel";
	}
	if (flags & PerPixelPremultiplied) {
		if (!first) {
			ret += " | ";
		}
		ret += "PerPixelPremultiplied";
	}
	return ret;
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
	if (flags & DeviceOnly) {
		return "DeviceOnly";
	}
	return "";
}
template<> auto flagsToString(ExportMetalObjectTypeFlagsEXT flags) -> std::string {
	using enum ExportMetalObjectTypeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ExportMetalObjectTypeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & MetalDevice) {
		bytes += 14;
	}
	if (flags & MetalCommandQueue) {
		bytes += 20;
	}
	if (flags & MetalBuffer) {
		bytes += 14;
	}
	if (flags & MetalTexture) {
		bytes += 15;
	}
	if (flags & MetalIosurface) {
		bytes += 17;
	}
	if (flags & MetalSharedEvent) {
		bytes += 19;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & MetalDevice) {
		first = false;
		ret += "MetalDevice";
	}
	if (flags & MetalCommandQueue) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MetalCommandQueue";
	}
	if (flags & MetalBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MetalBuffer";
	}
	if (flags & MetalTexture) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MetalTexture";
	}
	if (flags & MetalIosurface) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MetalIosurface";
	}
	if (flags & MetalSharedEvent) {
		if (!first) {
			ret += " | ";
		}
		ret += "MetalSharedEvent";
	}
	return ret;
}
template<> auto flagsToString(ExternalFenceFeatureFlags flags) -> std::string {
	using enum ExternalFenceFeatureBits;
	if ((flags & AllBits) != flags) {
		return "ExternalFenceFeatureBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Exportable) {
		bytes += 13;
	}
	if (flags & Importable) {
		bytes += 13;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Exportable) {
		first = false;
		ret += "Exportable";
	}
	if (flags & Importable) {
		if (!first) {
			ret += " | ";
		}
		ret += "Importable";
	}
	return ret;
}
template<> auto flagsToString(ExternalFenceHandleTypeFlags flags) -> std::string {
	using enum ExternalFenceHandleTypeBits;
	if ((flags & AllBits) != flags) {
		return "ExternalFenceHandleTypeBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & OpaqueFd) {
		bytes += 11;
	}
	if (flags & OpaqueWin32) {
		bytes += 14;
	}
	if (flags & OpaqueWin32Kmt) {
		bytes += 17;
	}
	if (flags & SyncFd) {
		bytes += 9;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & OpaqueFd) {
		first = false;
		ret += "OpaqueFd";
	}
	if (flags & OpaqueWin32) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpaqueWin32Kmt";
	}
	if (flags & SyncFd) {
		if (!first) {
			ret += " | ";
		}
		ret += "SyncFd";
	}
	return ret;
}
template<> auto flagsToString(ExternalMemoryFeatureFlags flags) -> std::string {
	using enum ExternalMemoryFeatureBits;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryFeatureBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DedicatedOnly) {
		bytes += 16;
	}
	if (flags & Exportable) {
		bytes += 13;
	}
	if (flags & Importable) {
		bytes += 13;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DedicatedOnly) {
		first = false;
		ret += "DedicatedOnly";
	}
	if (flags & Exportable) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Exportable";
	}
	if (flags & Importable) {
		if (!first) {
			ret += " | ";
		}
		ret += "Importable";
	}
	return ret;
}
template<> auto flagsToString(ExternalMemoryFeatureFlagsNV flags) -> std::string {
	using enum ExternalMemoryFeatureBitsNV;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryFeatureBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DedicatedOnly) {
		bytes += 16;
	}
	if (flags & Exportable) {
		bytes += 13;
	}
	if (flags & Importable) {
		bytes += 13;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DedicatedOnly) {
		first = false;
		ret += "DedicatedOnly";
	}
	if (flags & Exportable) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Exportable";
	}
	if (flags & Importable) {
		if (!first) {
			ret += " | ";
		}
		ret += "Importable";
	}
	return ret;
}
template<> auto flagsToString(ExternalMemoryHandleTypeFlags flags) -> std::string {
	using enum ExternalMemoryHandleTypeBits;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryHandleTypeBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & OpaqueFd) {
		bytes += 11;
	}
	if (flags & OpaqueWin32) {
		bytes += 14;
	}
	if (flags & OpaqueWin32Kmt) {
		bytes += 17;
	}
	if (flags & D3D11Texture) {
		bytes += 15;
	}
	if (flags & D3D11TextureKmt) {
		bytes += 18;
	}
	if (flags & D3D12Heap) {
		bytes += 12;
	}
	if (flags & D3D12Resource) {
		bytes += 16;
	}
	if (flags & HostAllocationBitEXT) {
		bytes += 23;
	}
	if (flags & HostMappedForeignMemoryBitEXT) {
		bytes += 32;
	}
	if (flags & DmaBufBitEXT) {
		bytes += 15;
	}
	if (flags & ANDROIDHardwareBufferBitANDROID) {
		bytes += 34;
	}
	if (flags & ZirconVmoBitFUCHSIA) {
		bytes += 22;
	}
	if (flags & RdmaAddressBitNV) {
		bytes += 19;
	}
	if (flags & ScreenBufferBitQNX) {
		bytes += 21;
	}
	if (flags & OhNativeBufferBitOHOS) {
		bytes += 24;
	}
	if (flags & MtlbufferBitEXT) {
		bytes += 18;
	}
	if (flags & MtltextureBitEXT) {
		bytes += 19;
	}
	if (flags & MtlheapBitEXT) {
		bytes += 16;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & OpaqueFd) {
		first = false;
		ret += "OpaqueFd";
	}
	if (flags & OpaqueWin32) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpaqueWin32Kmt";
	}
	if (flags & D3D11Texture) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "D3D11Texture";
	}
	if (flags & D3D11TextureKmt) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "D3D11TextureKmt";
	}
	if (flags & D3D12Heap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "D3D12Heap";
	}
	if (flags & D3D12Resource) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "D3D12Resource";
	}
	if (flags & HostAllocationBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostAllocationBitEXT";
	}
	if (flags & HostMappedForeignMemoryBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostMappedForeignMemoryBitEXT";
	}
	if (flags & DmaBufBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DmaBufBitEXT";
	}
	if (flags & ANDROIDHardwareBufferBitANDROID) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ANDROIDHardwareBufferBitANDROID";
	}
	if (flags & ZirconVmoBitFUCHSIA) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ZirconVmoBitFUCHSIA";
	}
	if (flags & RdmaAddressBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RdmaAddressBitNV";
	}
	if (flags & ScreenBufferBitQNX) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ScreenBufferBitQNX";
	}
	if (flags & OhNativeBufferBitOHOS) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OhNativeBufferBitOHOS";
	}
	if (flags & MtlbufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MtlbufferBitEXT";
	}
	if (flags & MtltextureBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MtltextureBitEXT";
	}
	if (flags & MtlheapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "MtlheapBitEXT";
	}
	return ret;
}
template<> auto flagsToString(ExternalMemoryHandleTypeFlagsNV flags) -> std::string {
	using enum ExternalMemoryHandleTypeBitsNV;
	if ((flags & AllBits) != flags) {
		return "ExternalMemoryHandleTypeBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & OpaqueWin32) {
		bytes += 14;
	}
	if (flags & OpaqueWin32Kmt) {
		bytes += 17;
	}
	if (flags & D3D11Image) {
		bytes += 13;
	}
	if (flags & D3D11ImageKmt) {
		bytes += 16;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & OpaqueWin32) {
		first = false;
		ret += "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpaqueWin32Kmt";
	}
	if (flags & D3D11Image) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "D3D11Image";
	}
	if (flags & D3D11ImageKmt) {
		if (!first) {
			ret += " | ";
		}
		ret += "D3D11ImageKmt";
	}
	return ret;
}
template<> auto flagsToString(ExternalSemaphoreFeatureFlags flags) -> std::string {
	using enum ExternalSemaphoreFeatureBits;
	if ((flags & AllBits) != flags) {
		return "ExternalSemaphoreFeatureBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Exportable) {
		bytes += 13;
	}
	if (flags & Importable) {
		bytes += 13;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Exportable) {
		first = false;
		ret += "Exportable";
	}
	if (flags & Importable) {
		if (!first) {
			ret += " | ";
		}
		ret += "Importable";
	}
	return ret;
}
template<> auto flagsToString(ExternalSemaphoreHandleTypeFlags flags) -> std::string {
	using enum ExternalSemaphoreHandleTypeBits;
	if ((flags & AllBits) != flags) {
		return "ExternalSemaphoreHandleTypeBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & OpaqueFd) {
		bytes += 11;
	}
	if (flags & OpaqueWin32) {
		bytes += 14;
	}
	if (flags & OpaqueWin32Kmt) {
		bytes += 17;
	}
	if (flags & D3D12Fence) {
		bytes += 13;
	}
	if (flags & SyncFd) {
		bytes += 9;
	}
	if (flags & ZirconEventBitFUCHSIA) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & OpaqueFd) {
		first = false;
		ret += "OpaqueFd";
	}
	if (flags & OpaqueWin32) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpaqueWin32";
	}
	if (flags & OpaqueWin32Kmt) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpaqueWin32Kmt";
	}
	if (flags & D3D12Fence) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "D3D12Fence";
	}
	if (flags & SyncFd) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SyncFd";
	}
	if (flags & ZirconEventBitFUCHSIA) {
		if (!first) {
			ret += " | ";
		}
		ret += "ZirconEventBitFUCHSIA";
	}
	return ret;
}
template<> auto flagsToString(FenceCreateFlags flags) -> std::string {
	using enum FenceCreateBits;
	if ((flags & AllBits) != flags) {
		return "FenceCreateBits does contain a bit that is not possible to be set";
	}
	if (flags & Signaled) {
		return "Signaled";
	}
	return "";
}
template<> auto flagsToString(FenceImportFlags flags) -> std::string {
	using enum FenceImportBits;
	if ((flags & AllBits) != flags) {
		return "FenceImportBits does contain a bit that is not possible to be set";
	}
	if (flags & Temporary) {
		return "Temporary";
	}
	return "";
}
template<> auto flagsToString(FormatFeatureFlags flags) -> std::string {
	using enum FormatFeatureBits;
	if ((flags & AllBits) != flags) {
		return "FormatFeatureBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SampledImage) {
		bytes += 15;
	}
	if (flags & StorageImage) {
		bytes += 15;
	}
	if (flags & StorageImageAtomic) {
		bytes += 21;
	}
	if (flags & UniformTexelBuffer) {
		bytes += 21;
	}
	if (flags & StorageTexelBuffer) {
		bytes += 21;
	}
	if (flags & StorageTexelBufferAtomic) {
		bytes += 27;
	}
	if (flags & VertexBuffer) {
		bytes += 15;
	}
	if (flags & ColorAttachment) {
		bytes += 18;
	}
	if (flags & ColorAttachmentBlend) {
		bytes += 23;
	}
	if (flags & DepthStencilAttachment) {
		bytes += 25;
	}
	if (flags & BlitSrc) {
		bytes += 10;
	}
	if (flags & BlitDst) {
		bytes += 10;
	}
	if (flags & SampledImageFilterLinear) {
		bytes += 27;
	}
	if (flags & SampledImageFilterCubicBitEXT) {
		bytes += 32;
	}
	if (flags & TransferSrc) {
		bytes += 14;
	}
	if (flags & TransferDst) {
		bytes += 14;
	}
	if (flags & SampledImageFilterMinmax) {
		bytes += 27;
	}
	if (flags & MidpointChromaSamples) {
		bytes += 24;
	}
	if (flags & SampledImageYcbcrConversionLinearFilter) {
		bytes += 42;
	}
	if (flags & SampledImageYcbcrConversionSeparateReconstructionFilter) {
		bytes += 58;
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicit) {
		bytes += 58;
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicitForceable) {
		bytes += 67;
	}
	if (flags & Disjoint) {
		bytes += 11;
	}
	if (flags & CositedChromaSamples) {
		bytes += 23;
	}
	if (flags & FragmentDensityMapBitEXT) {
		bytes += 27;
	}
	if (flags & VideoDecodeOutputBitKHR) {
		bytes += 26;
	}
	if (flags & VideoDecodeDpbBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeInputBitKHR) {
		bytes += 25;
	}
	if (flags & VideoEncodeDpbBitKHR) {
		bytes += 23;
	}
	if (flags & AccelerationStructureVertexBufferBitKHR) {
		bytes += 42;
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		bytes += 38;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SampledImage) {
		first = false;
		ret += "SampledImage";
	}
	if (flags & StorageImage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageImage";
	}
	if (flags & StorageImageAtomic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageImageAtomic";
	}
	if (flags & UniformTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageTexelBuffer";
	}
	if (flags & StorageTexelBufferAtomic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageTexelBufferAtomic";
	}
	if (flags & VertexBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexBuffer";
	}
	if (flags & ColorAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachment";
	}
	if (flags & ColorAttachmentBlend) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentBlend";
	}
	if (flags & DepthStencilAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachment";
	}
	if (flags & BlitSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlitSrc";
	}
	if (flags & BlitDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlitDst";
	}
	if (flags & SampledImageFilterLinear) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageFilterLinear";
	}
	if (flags & SampledImageFilterCubicBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageFilterCubicBitEXT";
	}
	if (flags & TransferSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferSrc";
	}
	if (flags & TransferDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferDst";
	}
	if (flags & SampledImageFilterMinmax) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageFilterMinmax";
	}
	if (flags & MidpointChromaSamples) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MidpointChromaSamples";
	}
	if (flags & SampledImageYcbcrConversionLinearFilter) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionLinearFilter";
	}
	if (flags & SampledImageYcbcrConversionSeparateReconstructionFilter) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionSeparateReconstructionFilter";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicit) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionChromaReconstructionExplicit";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicitForceable) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionChromaReconstructionExplicitForceable";
	}
	if (flags & Disjoint) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Disjoint";
	}
	if (flags & CositedChromaSamples) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CositedChromaSamples";
	}
	if (flags & FragmentDensityMapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeOutputBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeOutputBitKHR";
	}
	if (flags & VideoDecodeDpbBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDpbBitKHR";
	}
	if (flags & VideoEncodeInputBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeInputBitKHR";
	}
	if (flags & VideoEncodeDpbBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDpbBitKHR";
	}
	if (flags & AccelerationStructureVertexBufferBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureVertexBufferBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "FragmentShadingRateAttachmentBitKHR";
	}
	return ret;
}
template<> auto flagsToString(FormatFeatureFlags2 flags) -> std::string {
	using enum FormatFeatureBits2;
	if ((flags & AllBits) != flags) {
		return "FormatFeatureBits2 does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SampledImage) {
		bytes += 15;
	}
	if (flags & StorageImage) {
		bytes += 15;
	}
	if (flags & StorageImageAtomic) {
		bytes += 21;
	}
	if (flags & UniformTexelBuffer) {
		bytes += 21;
	}
	if (flags & StorageTexelBuffer) {
		bytes += 21;
	}
	if (flags & StorageTexelBufferAtomic) {
		bytes += 27;
	}
	if (flags & VertexBuffer) {
		bytes += 15;
	}
	if (flags & ColorAttachment) {
		bytes += 18;
	}
	if (flags & ColorAttachmentBlend) {
		bytes += 23;
	}
	if (flags & DepthStencilAttachment) {
		bytes += 25;
	}
	if (flags & BlitSrc) {
		bytes += 10;
	}
	if (flags & BlitDst) {
		bytes += 10;
	}
	if (flags & SampledImageFilterLinear) {
		bytes += 27;
	}
	if (flags & SampledImageFilterCubic) {
		bytes += 26;
	}
	if (flags & TransferSrc) {
		bytes += 14;
	}
	if (flags & TransferDst) {
		bytes += 14;
	}
	if (flags & SampledImageFilterMinmax) {
		bytes += 27;
	}
	if (flags & MidpointChromaSamples) {
		bytes += 24;
	}
	if (flags & SampledImageYcbcrConversionLinearFilter) {
		bytes += 42;
	}
	if (flags & SampledImageYcbcrConversionSeparateReconstructionFilter) {
		bytes += 58;
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicit) {
		bytes += 58;
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicitForceable) {
		bytes += 67;
	}
	if (flags & Disjoint) {
		bytes += 11;
	}
	if (flags & CositedChromaSamples) {
		bytes += 23;
	}
	if (flags & FragmentDensityMapBitEXT) {
		bytes += 27;
	}
	if (flags & VideoDecodeOutputBitKHR) {
		bytes += 26;
	}
	if (flags & VideoDecodeDpbBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeInputBitKHR) {
		bytes += 25;
	}
	if (flags & VideoEncodeDpbBitKHR) {
		bytes += 23;
	}
	if (flags & AccelerationStructureVertexBufferBitKHR) {
		bytes += 42;
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		bytes += 38;
	}
	if (flags & StorageReadWithoutFormat) {
		bytes += 27;
	}
	if (flags & StorageWriteWithoutFormat) {
		bytes += 28;
	}
	if (flags & SampledImageDepthComparison) {
		bytes += 30;
	}
	if (flags & WeightImageBitQCOM) {
		bytes += 21;
	}
	if (flags & WeightSampledImageBitQCOM) {
		bytes += 28;
	}
	if (flags & BlockMatchingBitQCOM) {
		bytes += 23;
	}
	if (flags & BoxFilterSampledBitQCOM) {
		bytes += 26;
	}
	if (flags & LinearColorAttachmentBitNV) {
		bytes += 29;
	}
	if (flags & TensorShaderBitARM) {
		bytes += 21;
	}
	if (flags & OpticalFlowImageBitNV) {
		bytes += 24;
	}
	if (flags & OpticalFlowVectorBitNV) {
		bytes += 25;
	}
	if (flags & OpticalFlowCostBitNV) {
		bytes += 23;
	}
	if (flags & TensorImageAliasingBitARM) {
		bytes += 28;
	}
	if (flags & BlockMatchingSxdBitQCOM) {
		bytes += 26;
	}
	if (flags & SampledImageFilterLinear2DBitIMG) {
		bytes += 35;
	}
	if (flags & HostImageTransfer) {
		bytes += 20;
	}
	if (flags & TensorDataGraphBitARM) {
		bytes += 24;
	}
	if (flags & VideoEncodeQuantizationDeltaMapBitKHR) {
		bytes += 40;
	}
	if (flags & VideoEncodeEmphasisMapBitKHR) {
		bytes += 31;
	}
	if (flags & AccelerationStructureRadiusBufferBitNV) {
		bytes += 41;
	}
	if (flags & DepthCopyOnComputeQueueBitKHR) {
		bytes += 32;
	}
	if (flags & DepthCopyOnTransferQueueBitKHR) {
		bytes += 33;
	}
	if (flags & StencilCopyOnComputeQueueBitKHR) {
		bytes += 34;
	}
	if (flags & StencilCopyOnTransferQueueBitKHR) {
		bytes += 35;
	}
	if (flags & DataGraphOpticalFlowImageBitARM) {
		bytes += 34;
	}
	if (flags & DataGraphOpticalFlowVectorBitARM) {
		bytes += 35;
	}
	if (flags & DataGraphOpticalFlowCostBitARM) {
		bytes += 33;
	}
	if (flags & CopyImageIndirectDstBitKHR) {
		bytes += 29;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SampledImage) {
		first = false;
		ret += "SampledImage";
	}
	if (flags & StorageImage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageImage";
	}
	if (flags & StorageImageAtomic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageImageAtomic";
	}
	if (flags & UniformTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformTexelBuffer";
	}
	if (flags & StorageTexelBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageTexelBuffer";
	}
	if (flags & StorageTexelBufferAtomic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageTexelBufferAtomic";
	}
	if (flags & VertexBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexBuffer";
	}
	if (flags & ColorAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachment";
	}
	if (flags & ColorAttachmentBlend) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentBlend";
	}
	if (flags & DepthStencilAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachment";
	}
	if (flags & BlitSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlitSrc";
	}
	if (flags & BlitDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlitDst";
	}
	if (flags & SampledImageFilterLinear) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageFilterLinear";
	}
	if (flags & SampledImageFilterCubic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageFilterCubic";
	}
	if (flags & TransferSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferSrc";
	}
	if (flags & TransferDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferDst";
	}
	if (flags & SampledImageFilterMinmax) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageFilterMinmax";
	}
	if (flags & MidpointChromaSamples) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MidpointChromaSamples";
	}
	if (flags & SampledImageYcbcrConversionLinearFilter) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionLinearFilter";
	}
	if (flags & SampledImageYcbcrConversionSeparateReconstructionFilter) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionSeparateReconstructionFilter";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicit) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionChromaReconstructionExplicit";
	}
	if (flags & SampledImageYcbcrConversionChromaReconstructionExplicitForceable) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageYcbcrConversionChromaReconstructionExplicitForceable";
	}
	if (flags & Disjoint) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Disjoint";
	}
	if (flags & CositedChromaSamples) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CositedChromaSamples";
	}
	if (flags & FragmentDensityMapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeOutputBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeOutputBitKHR";
	}
	if (flags & VideoDecodeDpbBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDpbBitKHR";
	}
	if (flags & VideoEncodeInputBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeInputBitKHR";
	}
	if (flags & VideoEncodeDpbBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDpbBitKHR";
	}
	if (flags & AccelerationStructureVertexBufferBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureVertexBufferBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & StorageReadWithoutFormat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageReadWithoutFormat";
	}
	if (flags & StorageWriteWithoutFormat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StorageWriteWithoutFormat";
	}
	if (flags & SampledImageDepthComparison) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageDepthComparison";
	}
	if (flags & WeightImageBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WeightImageBitQCOM";
	}
	if (flags & WeightSampledImageBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WeightSampledImageBitQCOM";
	}
	if (flags & BlockMatchingBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlockMatchingBitQCOM";
	}
	if (flags & BoxFilterSampledBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BoxFilterSampledBitQCOM";
	}
	if (flags & LinearColorAttachmentBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LinearColorAttachmentBitNV";
	}
	if (flags & TensorShaderBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TensorShaderBitARM";
	}
	if (flags & OpticalFlowImageBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpticalFlowImageBitNV";
	}
	if (flags & OpticalFlowVectorBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpticalFlowVectorBitNV";
	}
	if (flags & OpticalFlowCostBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpticalFlowCostBitNV";
	}
	if (flags & TensorImageAliasingBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TensorImageAliasingBitARM";
	}
	if (flags & BlockMatchingSxdBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlockMatchingSxdBitQCOM";
	}
	if (flags & SampledImageFilterLinear2DBitIMG) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImageFilterLinear2DBitIMG";
	}
	if (flags & HostImageTransfer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostImageTransfer";
	}
	if (flags & TensorDataGraphBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TensorDataGraphBitARM";
	}
	if (flags & VideoEncodeQuantizationDeltaMapBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeQuantizationDeltaMapBitKHR";
	}
	if (flags & VideoEncodeEmphasisMapBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeEmphasisMapBitKHR";
	}
	if (flags & AccelerationStructureRadiusBufferBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureRadiusBufferBitNV";
	}
	if (flags & DepthCopyOnComputeQueueBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthCopyOnComputeQueueBitKHR";
	}
	if (flags & DepthCopyOnTransferQueueBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthCopyOnTransferQueueBitKHR";
	}
	if (flags & StencilCopyOnComputeQueueBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StencilCopyOnComputeQueueBitKHR";
	}
	if (flags & StencilCopyOnTransferQueueBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "StencilCopyOnTransferQueueBitKHR";
	}
	if (flags & DataGraphOpticalFlowImageBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphOpticalFlowImageBitARM";
	}
	if (flags & DataGraphOpticalFlowVectorBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphOpticalFlowVectorBitARM";
	}
	if (flags & DataGraphOpticalFlowCostBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphOpticalFlowCostBitARM";
	}
	if (flags & CopyImageIndirectDstBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "CopyImageIndirectDstBitKHR";
	}
	return ret;
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
	if (flags & FrameEnd) {
		return "FrameEnd";
	}
	return "";
}
template<> auto flagsToString(FramebufferCreateFlags flags) -> std::string {
	using enum FramebufferCreateBits;
	if ((flags & AllBits) != flags) {
		return "FramebufferCreateBits does contain a bit that is not possible to be set";
	}
	if (flags & Imageless) {
		return "Imageless";
	}
	return "";
}
template<> auto flagsToString(GeometryFlagsKHR flags) -> std::string {
	using enum GeometryBitsKHR;
	if ((flags & AllBits) != flags) {
		return "GeometryBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Opaque) {
		bytes += 9;
	}
	if (flags & NoDuplicateAnyHitInvocation) {
		bytes += 30;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Opaque) {
		first = false;
		ret += "Opaque";
	}
	if (flags & NoDuplicateAnyHitInvocation) {
		if (!first) {
			ret += " | ";
		}
		ret += "NoDuplicateAnyHitInvocation";
	}
	return ret;
}
template<> auto flagsToString(GeometryInstanceFlagsKHR flags) -> std::string {
	using enum GeometryInstanceBitsKHR;
	if ((flags & AllBits) != flags) {
		return "GeometryInstanceBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & TriangleFacingCullDisable) {
		bytes += 28;
	}
	if (flags & TriangleFlipFacing) {
		bytes += 21;
	}
	if (flags & ForceOpaque) {
		bytes += 14;
	}
	if (flags & ForceNoOpaque) {
		bytes += 16;
	}
	if (flags & ForceOpacityMicromap2State) {
		bytes += 29;
	}
	if (flags & DisableOpacityMicromaps) {
		bytes += 26;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & TriangleFacingCullDisable) {
		first = false;
		ret += "TriangleFacingCullDisable";
	}
	if (flags & TriangleFlipFacing) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TriangleFlipFacing";
	}
	if (flags & ForceOpaque) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ForceOpaque";
	}
	if (flags & ForceNoOpaque) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ForceNoOpaque";
	}
	if (flags & ForceOpacityMicromap2State) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ForceOpacityMicromap2State";
	}
	if (flags & DisableOpacityMicromaps) {
		if (!first) {
			ret += " | ";
		}
		ret += "DisableOpacityMicromaps";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Ps) {
		bytes += 5;
	}
	if (flags & Vs) {
		bytes += 5;
	}
	if (flags & Gs) {
		bytes += 5;
	}
	if (flags & Es) {
		bytes += 5;
	}
	if (flags & Hs) {
		bytes += 5;
	}
	if (flags & Ls) {
		bytes += 5;
	}
	if (flags & Cs) {
		bytes += 5;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Ps) {
		first = false;
		ret += "Ps";
	}
	if (flags & Vs) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Vs";
	}
	if (flags & Gs) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Gs";
	}
	if (flags & Es) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Es";
	}
	if (flags & Hs) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Hs";
	}
	if (flags & Ls) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Ls";
	}
	if (flags & Cs) {
		if (!first) {
			ret += " | ";
		}
		ret += "Cs";
	}
	return ret;
}
template<> auto flagsToString(GraphicsPipelineLibraryFlagsEXT flags) -> std::string {
	using enum GraphicsPipelineLibraryBitsEXT;
	if ((flags & AllBits) != flags) {
		return "GraphicsPipelineLibraryBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & VertexInputInterface) {
		bytes += 23;
	}
	if (flags & PreRasterizationShaders) {
		bytes += 26;
	}
	if (flags & FragmentShader) {
		bytes += 17;
	}
	if (flags & FragmentOutputInterface) {
		bytes += 26;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & VertexInputInterface) {
		first = false;
		ret += "VertexInputInterface";
	}
	if (flags & PreRasterizationShaders) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PreRasterizationShaders";
	}
	if (flags & FragmentShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShader";
	}
	if (flags & FragmentOutputInterface) {
		if (!first) {
			ret += " | ";
		}
		ret += "FragmentOutputInterface";
	}
	return ret;
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
	if (flags & Memcpy) {
		return "Memcpy";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & Color) {
		bytes += 8;
	}
	if (flags & Depth) {
		bytes += 8;
	}
	if (flags & Stencil) {
		bytes += 10;
	}
	if (flags & Metadata) {
		bytes += 11;
	}
	if (flags & Plane0) {
		bytes += 9;
	}
	if (flags & Plane1) {
		bytes += 9;
	}
	if (flags & Plane2) {
		bytes += 9;
	}
	if (flags & MemoryPlane0BitEXT) {
		bytes += 21;
	}
	if (flags & MemoryPlane1BitEXT) {
		bytes += 21;
	}
	if (flags & MemoryPlane2BitEXT) {
		bytes += 21;
	}
	if (flags & MemoryPlane3BitEXT) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & Color) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Color";
	}
	if (flags & Depth) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Depth";
	}
	if (flags & Stencil) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Stencil";
	}
	if (flags & Metadata) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Metadata";
	}
	if (flags & Plane0) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Plane0";
	}
	if (flags & Plane1) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Plane1";
	}
	if (flags & Plane2) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Plane2";
	}
	if (flags & MemoryPlane0BitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryPlane0BitEXT";
	}
	if (flags & MemoryPlane1BitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryPlane1BitEXT";
	}
	if (flags & MemoryPlane2BitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryPlane2BitEXT";
	}
	if (flags & MemoryPlane3BitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "MemoryPlane3BitEXT";
	}
	return ret;
}
template<> auto flagsToString(ImageCompressionFixedRateFlagsEXT flags) -> std::string {
	using enum ImageCompressionFixedRateBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ImageCompressionFixedRateBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & v1Bpc) {
		bytes += 8;
	}
	if (flags & v2Bpc) {
		bytes += 8;
	}
	if (flags & v3Bpc) {
		bytes += 8;
	}
	if (flags & v4Bpc) {
		bytes += 8;
	}
	if (flags & v5Bpc) {
		bytes += 8;
	}
	if (flags & v6Bpc) {
		bytes += 8;
	}
	if (flags & v7Bpc) {
		bytes += 8;
	}
	if (flags & v8Bpc) {
		bytes += 8;
	}
	if (flags & v9Bpc) {
		bytes += 8;
	}
	if (flags & v10Bpc) {
		bytes += 9;
	}
	if (flags & v11Bpc) {
		bytes += 9;
	}
	if (flags & v12Bpc) {
		bytes += 9;
	}
	if (flags & v13Bpc) {
		bytes += 9;
	}
	if (flags & v14Bpc) {
		bytes += 9;
	}
	if (flags & v15Bpc) {
		bytes += 9;
	}
	if (flags & v16Bpc) {
		bytes += 9;
	}
	if (flags & v17Bpc) {
		bytes += 9;
	}
	if (flags & v18Bpc) {
		bytes += 9;
	}
	if (flags & v19Bpc) {
		bytes += 9;
	}
	if (flags & v20Bpc) {
		bytes += 9;
	}
	if (flags & v21Bpc) {
		bytes += 9;
	}
	if (flags & v22Bpc) {
		bytes += 9;
	}
	if (flags & v23Bpc) {
		bytes += 9;
	}
	if (flags & v24Bpc) {
		bytes += 9;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & v1Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v1Bpc";
	}
	if (flags & v2Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2Bpc";
	}
	if (flags & v3Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v3Bpc";
	}
	if (flags & v4Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v4Bpc";
	}
	if (flags & v5Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v5Bpc";
	}
	if (flags & v6Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v6Bpc";
	}
	if (flags & v7Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v7Bpc";
	}
	if (flags & v8Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v8Bpc";
	}
	if (flags & v9Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v9Bpc";
	}
	if (flags & v10Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v10Bpc";
	}
	if (flags & v11Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v11Bpc";
	}
	if (flags & v12Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v12Bpc";
	}
	if (flags & v13Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v13Bpc";
	}
	if (flags & v14Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v14Bpc";
	}
	if (flags & v15Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v15Bpc";
	}
	if (flags & v16Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v16Bpc";
	}
	if (flags & v17Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v17Bpc";
	}
	if (flags & v18Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v18Bpc";
	}
	if (flags & v19Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v19Bpc";
	}
	if (flags & v20Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v20Bpc";
	}
	if (flags & v21Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v21Bpc";
	}
	if (flags & v22Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v22Bpc";
	}
	if (flags & v23Bpc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v23Bpc";
	}
	if (flags & v24Bpc) {
		if (!first) {
			ret += " | ";
		}
		ret += "v24Bpc";
	}
	return ret;
}
template<> auto flagsToString(ImageCompressionFlagsEXT flags) -> std::string {
	using enum ImageCompressionBitsEXT;
	if ((flags & AllBits) != flags) {
		return "ImageCompressionBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Default) {
		bytes += 10;
	}
	if (flags & FixedRateDefault) {
		bytes += 19;
	}
	if (flags & FixedRateExplicit) {
		bytes += 20;
	}
	if (flags & Disabled) {
		bytes += 11;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Default) {
		first = false;
		ret += "Default";
	}
	if (flags & FixedRateDefault) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FixedRateDefault";
	}
	if (flags & FixedRateExplicit) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FixedRateExplicit";
	}
	if (flags & Disabled) {
		if (!first) {
			ret += " | ";
		}
		ret += "Disabled";
	}
	return ret;
}
template<> auto flagsToString(ImageConstraintsInfoFlagsFUCHSIA flags) -> std::string {
	using enum ImageConstraintsInfoBitsFUCHSIA;
	if ((flags & AllBits) != flags) {
		return "ImageConstraintsInfoBitsFUCHSIA does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & CpuReadRarely) {
		bytes += 16;
	}
	if (flags & CpuReadOften) {
		bytes += 15;
	}
	if (flags & CpuWriteRarely) {
		bytes += 17;
	}
	if (flags & CpuWriteOften) {
		bytes += 16;
	}
	if (flags & ProtectedOptional) {
		bytes += 20;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & CpuReadRarely) {
		first = false;
		ret += "CpuReadRarely";
	}
	if (flags & CpuReadOften) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CpuReadOften";
	}
	if (flags & CpuWriteRarely) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CpuWriteRarely";
	}
	if (flags & CpuWriteOften) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CpuWriteOften";
	}
	if (flags & ProtectedOptional) {
		if (!first) {
			ret += " | ";
		}
		ret += "ProtectedOptional";
	}
	return ret;
}
template<> auto flagsToString(ImageCreateFlags flags) -> std::string {
	using enum ImageCreateBits;
	if ((flags & AllBits) != flags) {
		return "ImageCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SparseBinding) {
		bytes += 16;
	}
	if (flags & SparseResidency) {
		bytes += 18;
	}
	if (flags & SparseAliased) {
		bytes += 16;
	}
	if (flags & MutableFormat) {
		bytes += 16;
	}
	if (flags & CubeCompatible) {
		bytes += 17;
	}
	if (flags & v2DArrayCompatible) {
		bytes += 21;
	}
	if (flags & SplitInstanceBindRegions) {
		bytes += 27;
	}
	if (flags & BlockTexelViewCompatible) {
		bytes += 27;
	}
	if (flags & ExtendedUsage) {
		bytes += 16;
	}
	if (flags & Disjoint) {
		bytes += 11;
	}
	if (flags & Alias) {
		bytes += 8;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & SampleLocationsCompatibleDepthBitEXT) {
		bytes += 39;
	}
	if (flags & CornerSampledBitNV) {
		bytes += 21;
	}
	if (flags & SubsampledBitEXT) {
		bytes += 19;
	}
	if (flags & FragmentDensityMapOffsetBitEXT) {
		bytes += 33;
	}
	if (flags & DescriptorHeapCaptureReplayBitEXT) {
		bytes += 36;
	}
	if (flags & v2DViewCompatibleBitEXT) {
		bytes += 26;
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		bytes += 42;
	}
	if (flags & VideoProfileIndependentBitKHR) {
		bytes += 32;
	}
	if (flags & AliasSingleLayerDescriptorBitKHR) {
		bytes += 35;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SparseBinding) {
		first = false;
		ret += "SparseBinding";
	}
	if (flags & SparseResidency) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SparseResidency";
	}
	if (flags & SparseAliased) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SparseAliased";
	}
	if (flags & MutableFormat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MutableFormat";
	}
	if (flags & CubeCompatible) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CubeCompatible";
	}
	if (flags & v2DArrayCompatible) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2DArrayCompatible";
	}
	if (flags & SplitInstanceBindRegions) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SplitInstanceBindRegions";
	}
	if (flags & BlockTexelViewCompatible) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlockTexelViewCompatible";
	}
	if (flags & ExtendedUsage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ExtendedUsage";
	}
	if (flags & Disjoint) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Disjoint";
	}
	if (flags & Alias) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Alias";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Protected";
	}
	if (flags & SampleLocationsCompatibleDepthBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleLocationsCompatibleDepthBitEXT";
	}
	if (flags & CornerSampledBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CornerSampledBitNV";
	}
	if (flags & SubsampledBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SubsampledBitEXT";
	}
	if (flags & FragmentDensityMapOffsetBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapOffsetBitEXT";
	}
	if (flags & DescriptorHeapCaptureReplayBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorHeapCaptureReplayBitEXT";
	}
	if (flags & v2DViewCompatibleBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2DViewCompatibleBitEXT";
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MultisampledRenderToSingleSampledBitEXT";
	}
	if (flags & VideoProfileIndependentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoProfileIndependentBitKHR";
	}
	if (flags & AliasSingleLayerDescriptorBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "AliasSingleLayerDescriptorBitKHR";
	}
	return ret;
}
template<> auto flagsToString(ImageCreateFlags2KHR flags) -> std::string {
	using enum ImageCreateBits2KHR;
	if ((flags & AllBits) != flags) {
		return "ImageCreateBits2KHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SparseBinding) {
		bytes += 16;
	}
	if (flags & SparseResidency) {
		bytes += 18;
	}
	if (flags & SparseAliased) {
		bytes += 16;
	}
	if (flags & MutableFormat) {
		bytes += 16;
	}
	if (flags & CubeCompatible) {
		bytes += 17;
	}
	if (flags & v2DArrayCompatible) {
		bytes += 21;
	}
	if (flags & SplitInstanceBindRegions) {
		bytes += 27;
	}
	if (flags & BlockTexelViewCompatible) {
		bytes += 27;
	}
	if (flags & ExtendedUsage) {
		bytes += 16;
	}
	if (flags & Disjoint) {
		bytes += 11;
	}
	if (flags & Alias) {
		bytes += 8;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & SampleLocationsCompatibleDepthBitEXT) {
		bytes += 39;
	}
	if (flags & CornerSampledBitNV) {
		bytes += 21;
	}
	if (flags & SubsampledBitEXT) {
		bytes += 19;
	}
	if (flags & FragmentDensityMapOffsetBitEXT) {
		bytes += 33;
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		bytes += 38;
	}
	if (flags & v2DViewCompatibleBitEXT) {
		bytes += 26;
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		bytes += 42;
	}
	if (flags & VideoProfileIndependent) {
		bytes += 26;
	}
	if (flags & AliasSingleLayerDescriptor) {
		bytes += 29;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SparseBinding) {
		first = false;
		ret += "SparseBinding";
	}
	if (flags & SparseResidency) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SparseResidency";
	}
	if (flags & SparseAliased) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SparseAliased";
	}
	if (flags & MutableFormat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MutableFormat";
	}
	if (flags & CubeCompatible) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CubeCompatible";
	}
	if (flags & v2DArrayCompatible) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2DArrayCompatible";
	}
	if (flags & SplitInstanceBindRegions) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SplitInstanceBindRegions";
	}
	if (flags & BlockTexelViewCompatible) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlockTexelViewCompatible";
	}
	if (flags & ExtendedUsage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ExtendedUsage";
	}
	if (flags & Disjoint) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Disjoint";
	}
	if (flags & Alias) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Alias";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Protected";
	}
	if (flags & SampleLocationsCompatibleDepthBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleLocationsCompatibleDepthBitEXT";
	}
	if (flags & CornerSampledBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CornerSampledBitNV";
	}
	if (flags & SubsampledBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SubsampledBitEXT";
	}
	if (flags & FragmentDensityMapOffsetBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapOffsetBitEXT";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferCaptureReplayBitEXT";
	}
	if (flags & v2DViewCompatibleBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2DViewCompatibleBitEXT";
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MultisampledRenderToSingleSampledBitEXT";
	}
	if (flags & VideoProfileIndependent) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoProfileIndependent";
	}
	if (flags & AliasSingleLayerDescriptor) {
		if (!first) {
			ret += " | ";
		}
		ret += "AliasSingleLayerDescriptor";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & TransferSrc) {
		bytes += 14;
	}
	if (flags & TransferDst) {
		bytes += 14;
	}
	if (flags & Sampled) {
		bytes += 10;
	}
	if (flags & Storage) {
		bytes += 10;
	}
	if (flags & ColorAttachment) {
		bytes += 18;
	}
	if (flags & DepthStencilAttachment) {
		bytes += 25;
	}
	if (flags & TransientAttachment) {
		bytes += 22;
	}
	if (flags & InputAttachment) {
		bytes += 18;
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		bytes += 38;
	}
	if (flags & FragmentDensityMapBitEXT) {
		bytes += 27;
	}
	if (flags & VideoDecodeDstBitKHR) {
		bytes += 23;
	}
	if (flags & VideoDecodeSrcBitKHR) {
		bytes += 23;
	}
	if (flags & VideoDecodeDpbBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeDstBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeSrcBitKHR) {
		bytes += 23;
	}
	if (flags & VideoEncodeDpbBitKHR) {
		bytes += 23;
	}
	if (flags & InvocationMaskBitHUAWEI) {
		bytes += 26;
	}
	if (flags & AttachmentFeedbackLoopBitEXT) {
		bytes += 31;
	}
	if (flags & SampleWeightBitQCOM) {
		bytes += 22;
	}
	if (flags & SampleBlockMatchBitQCOM) {
		bytes += 26;
	}
	if (flags & HostTransfer) {
		bytes += 15;
	}
	if (flags & TensorAliasingBitARM) {
		bytes += 23;
	}
	if (flags & VideoEncodeQuantizationDeltaMapBitKHR) {
		bytes += 40;
	}
	if (flags & VideoEncodeEmphasisMapBitKHR) {
		bytes += 31;
	}
	if (flags & TileMemoryBitQCOM) {
		bytes += 20;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & TransferSrc) {
		first = false;
		ret += "TransferSrc";
	}
	if (flags & TransferDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferDst";
	}
	if (flags & Sampled) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Sampled";
	}
	if (flags & Storage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Storage";
	}
	if (flags & ColorAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachment";
	}
	if (flags & DepthStencilAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachment";
	}
	if (flags & TransientAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransientAttachment";
	}
	if (flags & InputAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InputAttachment";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & FragmentDensityMapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeDstBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDstBitKHR";
	}
	if (flags & VideoDecodeSrcBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeSrcBitKHR";
	}
	if (flags & VideoDecodeDpbBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDpbBitKHR";
	}
	if (flags & VideoEncodeDstBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDstBitKHR";
	}
	if (flags & VideoEncodeSrcBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeSrcBitKHR";
	}
	if (flags & VideoEncodeDpbBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDpbBitKHR";
	}
	if (flags & InvocationMaskBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InvocationMaskBitHUAWEI";
	}
	if (flags & AttachmentFeedbackLoopBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AttachmentFeedbackLoopBitEXT";
	}
	if (flags & SampleWeightBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleWeightBitQCOM";
	}
	if (flags & SampleBlockMatchBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleBlockMatchBitQCOM";
	}
	if (flags & HostTransfer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostTransfer";
	}
	if (flags & TensorAliasingBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TensorAliasingBitARM";
	}
	if (flags & VideoEncodeQuantizationDeltaMapBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeQuantizationDeltaMapBitKHR";
	}
	if (flags & VideoEncodeEmphasisMapBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeEmphasisMapBitKHR";
	}
	if (flags & TileMemoryBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		ret += "TileMemoryBitQCOM";
	}
	return ret;
}
template<> auto flagsToString(ImageUsageFlags2KHR flags) -> std::string {
	using enum ImageUsageBits2KHR;
	if ((flags & AllBits) != flags) {
		return "ImageUsageBits2KHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & TransferSrc) {
		bytes += 14;
	}
	if (flags & TransferDst) {
		bytes += 14;
	}
	if (flags & Sampled) {
		bytes += 10;
	}
	if (flags & Storage) {
		bytes += 10;
	}
	if (flags & ColorAttachment) {
		bytes += 18;
	}
	if (flags & DepthStencilAttachment) {
		bytes += 25;
	}
	if (flags & TransientAttachment) {
		bytes += 22;
	}
	if (flags & InputAttachment) {
		bytes += 18;
	}
	if (flags & FragmentShadingRateAttachment) {
		bytes += 32;
	}
	if (flags & FragmentDensityMapBitEXT) {
		bytes += 27;
	}
	if (flags & VideoDecodeDst) {
		bytes += 17;
	}
	if (flags & VideoDecodeSrc) {
		bytes += 17;
	}
	if (flags & VideoDecodeDpb) {
		bytes += 17;
	}
	if (flags & VideoEncodeDst) {
		bytes += 17;
	}
	if (flags & VideoEncodeSrc) {
		bytes += 17;
	}
	if (flags & VideoEncodeDpb) {
		bytes += 17;
	}
	if (flags & InvocationMaskBitHUAWEI) {
		bytes += 26;
	}
	if (flags & AttachmentFeedbackLoopBitEXT) {
		bytes += 31;
	}
	if (flags & SampleWeightBitQCOM) {
		bytes += 22;
	}
	if (flags & SampleBlockMatchBitQCOM) {
		bytes += 26;
	}
	if (flags & HostTransfer) {
		bytes += 15;
	}
	if (flags & TensorAliasingBitARM) {
		bytes += 23;
	}
	if (flags & VideoEncodeQuantizationDeltaMap) {
		bytes += 34;
	}
	if (flags & VideoEncodeEmphasisMap) {
		bytes += 25;
	}
	if (flags & TileMemoryBitQCOM) {
		bytes += 20;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & TransferSrc) {
		first = false;
		ret += "TransferSrc";
	}
	if (flags & TransferDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferDst";
	}
	if (flags & Sampled) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Sampled";
	}
	if (flags & Storage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Storage";
	}
	if (flags & ColorAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachment";
	}
	if (flags & DepthStencilAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachment";
	}
	if (flags & TransientAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransientAttachment";
	}
	if (flags & InputAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InputAttachment";
	}
	if (flags & FragmentShadingRateAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachment";
	}
	if (flags & FragmentDensityMapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapBitEXT";
	}
	if (flags & VideoDecodeDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDst";
	}
	if (flags & VideoDecodeSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeSrc";
	}
	if (flags & VideoDecodeDpb) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeDpb";
	}
	if (flags & VideoEncodeDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDst";
	}
	if (flags & VideoEncodeSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeSrc";
	}
	if (flags & VideoEncodeDpb) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeDpb";
	}
	if (flags & InvocationMaskBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InvocationMaskBitHUAWEI";
	}
	if (flags & AttachmentFeedbackLoopBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AttachmentFeedbackLoopBitEXT";
	}
	if (flags & SampleWeightBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleWeightBitQCOM";
	}
	if (flags & SampleBlockMatchBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleBlockMatchBitQCOM";
	}
	if (flags & HostTransfer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostTransfer";
	}
	if (flags & TensorAliasingBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TensorAliasingBitARM";
	}
	if (flags & VideoEncodeQuantizationDeltaMap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeQuantizationDeltaMap";
	}
	if (flags & VideoEncodeEmphasisMap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeEmphasisMap";
	}
	if (flags & TileMemoryBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		ret += "TileMemoryBitQCOM";
	}
	return ret;
}
template<> auto flagsToString(ImageViewCreateFlags flags) -> std::string {
	using enum ImageViewCreateBits;
	if ((flags & AllBits) != flags) {
		return "ImageViewCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & FragmentDensityMapDynamicBitEXT) {
		bytes += 34;
	}
	if (flags & FragmentDensityMapDeferredBitEXT) {
		bytes += 35;
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		bytes += 38;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & FragmentDensityMapDynamicBitEXT) {
		first = false;
		ret += "FragmentDensityMapDynamicBitEXT";
	}
	if (flags & FragmentDensityMapDeferredBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapDeferredBitEXT";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "DescriptorBufferCaptureReplayBitEXT";
	}
	return ret;
}
template<> auto flagsToString(IndirectCommandsInputModeFlagsEXT flags) -> std::string {
	using enum IndirectCommandsInputModeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "IndirectCommandsInputModeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & VulkanIndexBuffer) {
		bytes += 20;
	}
	if (flags & DxgiIndexBuffer) {
		bytes += 18;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & VulkanIndexBuffer) {
		first = false;
		ret += "VulkanIndexBuffer";
	}
	if (flags & DxgiIndexBuffer) {
		if (!first) {
			ret += " | ";
		}
		ret += "DxgiIndexBuffer";
	}
	return ret;
}
template<> auto flagsToString(IndirectCommandsLayoutUsageFlagsEXT flags) -> std::string {
	using enum IndirectCommandsLayoutUsageBitsEXT;
	if ((flags & AllBits) != flags) {
		return "IndirectCommandsLayoutUsageBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & ExplicitPreprocess) {
		bytes += 21;
	}
	if (flags & UnorderedSequences) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ExplicitPreprocess) {
		first = false;
		ret += "ExplicitPreprocess";
	}
	if (flags & UnorderedSequences) {
		if (!first) {
			ret += " | ";
		}
		ret += "UnorderedSequences";
	}
	return ret;
}
template<> auto flagsToString(IndirectCommandsLayoutUsageFlagsNV flags) -> std::string {
	using enum IndirectCommandsLayoutUsageBitsNV;
	if ((flags & AllBits) != flags) {
		return "IndirectCommandsLayoutUsageBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & ExplicitPreprocess) {
		bytes += 21;
	}
	if (flags & IndexedSequences) {
		bytes += 19;
	}
	if (flags & UnorderedSequences) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ExplicitPreprocess) {
		first = false;
		ret += "ExplicitPreprocess";
	}
	if (flags & IndexedSequences) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndexedSequences";
	}
	if (flags & UnorderedSequences) {
		if (!first) {
			ret += " | ";
		}
		ret += "UnorderedSequences";
	}
	return ret;
}
template<> auto flagsToString(IndirectStateFlagsNV flags) -> std::string {
	using enum IndirectStateBitsNV;
	if ((flags & AllBits) != flags) {
		return "IndirectStateBitsNV does contain a bit that is not possible to be set";
	}
	if (flags & FlagFrontface) {
		return "FlagFrontface";
	}
	return "";
}
template<> auto flagsToString(InstanceCreateFlags flags) -> std::string {
	using enum InstanceCreateBits;
	if ((flags & AllBits) != flags) {
		return "InstanceCreateBits does contain a bit that is not possible to be set";
	}
	if (flags & EnumeratePortabilityBitKHR) {
		return "EnumeratePortabilityBitKHR";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & DeviceMask) {
		bytes += 13;
	}
	if (flags & DeviceAddress) {
		bytes += 16;
	}
	if (flags & DeviceAddressCaptureReplay) {
		bytes += 29;
	}
	if (flags & ZeroInitializeBitEXT) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DeviceMask) {
		first = false;
		ret += "DeviceMask";
	}
	if (flags & DeviceAddress) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeviceAddress";
	}
	if (flags & DeviceAddressCaptureReplay) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeviceAddressCaptureReplay";
	}
	if (flags & ZeroInitializeBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "ZeroInitializeBitEXT";
	}
	return ret;
}
template<> auto flagsToString(MemoryDecompressionMethodFlagsEXT flags) -> std::string {
	using enum MemoryDecompressionMethodBitsEXT;
	if ((flags & AllBits) != flags) {
		return "MemoryDecompressionMethodBitsEXT does contain a bit that is not possible to be set";
	}
	if (flags & Gdeflate10) {
		return "Gdeflate10";
	}
	return "";
}
template<> auto flagsToString(MemoryHeapFlags flags) -> std::string {
	using enum MemoryHeapBits;
	if ((flags & AllBits) != flags) {
		return "MemoryHeapBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DeviceLocal) {
		bytes += 14;
	}
	if (flags & MultiInstance) {
		bytes += 16;
	}
	if (flags & TileMemoryBitQCOM) {
		bytes += 20;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DeviceLocal) {
		first = false;
		ret += "DeviceLocal";
	}
	if (flags & MultiInstance) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MultiInstance";
	}
	if (flags & TileMemoryBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		ret += "TileMemoryBitQCOM";
	}
	return ret;
}
template<> auto flagsToString(MemoryMapFlags flags) -> std::string {
	using enum MemoryMapBits;
	if ((flags & AllBits) != flags) {
		return "MemoryMapBits does contain a bit that is not possible to be set";
	}
	if (flags & PlacedBitEXT) {
		return "PlacedBitEXT";
	}
	return "";
}
template<> auto flagsToString(MemoryPropertyFlags flags) -> std::string {
	using enum MemoryPropertyBits;
	if ((flags & AllBits) != flags) {
		return "MemoryPropertyBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DeviceLocal) {
		bytes += 14;
	}
	if (flags & HostVisible) {
		bytes += 14;
	}
	if (flags & HostCoherent) {
		bytes += 15;
	}
	if (flags & HostCached) {
		bytes += 13;
	}
	if (flags & LazilyAllocated) {
		bytes += 18;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & DeviceCoherentBitAMD) {
		bytes += 23;
	}
	if (flags & DeviceUncachedBitAMD) {
		bytes += 23;
	}
	if (flags & RdmaCapableBitNV) {
		bytes += 19;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DeviceLocal) {
		first = false;
		ret += "DeviceLocal";
	}
	if (flags & HostVisible) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostVisible";
	}
	if (flags & HostCoherent) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostCoherent";
	}
	if (flags & HostCached) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HostCached";
	}
	if (flags & LazilyAllocated) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LazilyAllocated";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Protected";
	}
	if (flags & DeviceCoherentBitAMD) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeviceCoherentBitAMD";
	}
	if (flags & DeviceUncachedBitAMD) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeviceUncachedBitAMD";
	}
	if (flags & RdmaCapableBitNV) {
		if (!first) {
			ret += " | ";
		}
		ret += "RdmaCapableBitNV";
	}
	return ret;
}
template<> auto flagsToString(MemoryUnmapFlags flags) -> std::string {
	using enum MemoryUnmapBits;
	if ((flags & AllBits) != flags) {
		return "MemoryUnmapBits does contain a bit that is not possible to be set";
	}
	if (flags & ReserveBitEXT) {
		return "ReserveBitEXT";
	}
	return "";
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
	if (flags & DeviceAddressCaptureReplay) {
		return "DeviceAddressCaptureReplay";
	}
	return "";
}
template<> auto flagsToString(OpticalFlowExecuteFlagsNV flags) -> std::string {
	using enum OpticalFlowExecuteBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowExecuteBitsNV does contain a bit that is not possible to be set";
	}
	if (flags & DisableTemporalHints) {
		return "DisableTemporalHints";
	}
	return "";
}
template<> auto flagsToString(OpticalFlowGridSizeFlagsNV flags) -> std::string {
	using enum OpticalFlowGridSizeBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowGridSizeBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Unknown) {
		bytes += 10;
	}
	if (flags & v1x1) {
		bytes += 7;
	}
	if (flags & v2x2) {
		bytes += 7;
	}
	if (flags & v4x4) {
		bytes += 7;
	}
	if (flags & v8x8) {
		bytes += 7;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Unknown) {
		first = false;
		ret += "Unknown";
	}
	if (flags & v1x1) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v1x1";
	}
	if (flags & v2x2) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2x2";
	}
	if (flags & v4x4) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v4x4";
	}
	if (flags & v8x8) {
		if (!first) {
			ret += " | ";
		}
		ret += "v8x8";
	}
	return ret;
}
template<> auto flagsToString(OpticalFlowSessionCreateFlagsNV flags) -> std::string {
	using enum OpticalFlowSessionCreateBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowSessionCreateBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & EnableHint) {
		bytes += 13;
	}
	if (flags & EnableCost) {
		bytes += 13;
	}
	if (flags & EnableGlobalFlow) {
		bytes += 19;
	}
	if (flags & AllowRegions) {
		bytes += 15;
	}
	if (flags & BothDirections) {
		bytes += 17;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & EnableHint) {
		first = false;
		ret += "EnableHint";
	}
	if (flags & EnableCost) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableCost";
	}
	if (flags & EnableGlobalFlow) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableGlobalFlow";
	}
	if (flags & AllowRegions) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowRegions";
	}
	if (flags & BothDirections) {
		if (!first) {
			ret += " | ";
		}
		ret += "BothDirections";
	}
	return ret;
}
template<> auto flagsToString(OpticalFlowUsageFlagsNV flags) -> std::string {
	using enum OpticalFlowUsageBitsNV;
	if ((flags & AllBits) != flags) {
		return "OpticalFlowUsageBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Unknown) {
		bytes += 10;
	}
	if (flags & Input) {
		bytes += 8;
	}
	if (flags & Output) {
		bytes += 9;
	}
	if (flags & Hint) {
		bytes += 7;
	}
	if (flags & Cost) {
		bytes += 7;
	}
	if (flags & GlobalFlow) {
		bytes += 13;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Unknown) {
		first = false;
		ret += "Unknown";
	}
	if (flags & Input) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Input";
	}
	if (flags & Output) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Output";
	}
	if (flags & Hint) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Hint";
	}
	if (flags & Cost) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Cost";
	}
	if (flags & GlobalFlow) {
		if (!first) {
			ret += " | ";
		}
		ret += "GlobalFlow";
	}
	return ret;
}
template<> auto flagsToString(PartitionedAccelerationStructureInstanceFlagsNV flags) -> std::string {
	using enum PartitionedAccelerationStructureInstanceBitsNV;
	if ((flags & AllBits) != flags) {
		return "PartitionedAccelerationStructureInstanceBitsNV does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & FlagTriangleFacingCullDisable) {
		bytes += 32;
	}
	if (flags & FlagTriangleFlipFacing) {
		bytes += 25;
	}
	if (flags & FlagForceOpaque) {
		bytes += 18;
	}
	if (flags & FlagForceNoOpaque) {
		bytes += 20;
	}
	if (flags & FlagEnableExplicitBoundingBox) {
		bytes += 32;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & FlagTriangleFacingCullDisable) {
		first = false;
		ret += "FlagTriangleFacingCullDisable";
	}
	if (flags & FlagTriangleFlipFacing) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FlagTriangleFlipFacing";
	}
	if (flags & FlagForceOpaque) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FlagForceOpaque";
	}
	if (flags & FlagForceNoOpaque) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FlagForceNoOpaque";
	}
	if (flags & FlagEnableExplicitBoundingBox) {
		if (!first) {
			ret += " | ";
		}
		ret += "FlagEnableExplicitBoundingBox";
	}
	return ret;
}
template<> auto flagsToString(PastPresentationTimingFlagsEXT flags) -> std::string {
	using enum PastPresentationTimingBitsEXT;
	if ((flags & AllBits) != flags) {
		return "PastPresentationTimingBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & AllowPartialResults) {
		bytes += 22;
	}
	if (flags & AllowOutOfOrderResults) {
		bytes += 25;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & AllowPartialResults) {
		first = false;
		ret += "AllowPartialResults";
	}
	if (flags & AllowOutOfOrderResults) {
		if (!first) {
			ret += " | ";
		}
		ret += "AllowOutOfOrderResults";
	}
	return ret;
}
template<> auto flagsToString(PeerMemoryFeatureFlags flags) -> std::string {
	using enum PeerMemoryFeatureBits;
	if ((flags & AllBits) != flags) {
		return "PeerMemoryFeatureBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & CopySrc) {
		bytes += 10;
	}
	if (flags & CopyDst) {
		bytes += 10;
	}
	if (flags & GenericSrc) {
		bytes += 13;
	}
	if (flags & GenericDst) {
		bytes += 13;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & CopySrc) {
		first = false;
		ret += "CopySrc";
	}
	if (flags & CopyDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CopyDst";
	}
	if (flags & GenericSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "GenericSrc";
	}
	if (flags & GenericDst) {
		if (!first) {
			ret += " | ";
		}
		ret += "GenericDst";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & PerformanceImpacting) {
		bytes += 23;
	}
	if (flags & ConcurrentlyImpacted) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & PerformanceImpacting) {
		first = false;
		ret += "PerformanceImpacting";
	}
	if (flags & ConcurrentlyImpacted) {
		if (!first) {
			ret += " | ";
		}
		ret += "ConcurrentlyImpacted";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & ShaderCoreCount) {
		bytes += 18;
	}
	if (flags & DispatchParameters) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ShaderCoreCount) {
		first = false;
		ret += "ShaderCoreCount";
	}
	if (flags & DispatchParameters) {
		if (!first) {
			ret += " | ";
		}
		ret += "DispatchParameters";
	}
	return ret;
}
template<> auto flagsToString(PipelineCacheCreateFlags flags) -> std::string {
	using enum PipelineCacheCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineCacheCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & ExternallySynchronized) {
		bytes += 25;
	}
	if (flags & InternallySynchronizedMergeBitKHR) {
		bytes += 36;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ExternallySynchronized) {
		first = false;
		ret += "ExternallySynchronized";
	}
	if (flags & InternallySynchronizedMergeBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "InternallySynchronizedMergeBitKHR";
	}
	return ret;
}
template<> auto flagsToString(PipelineColorBlendStateCreateFlags flags) -> std::string {
	using enum PipelineColorBlendStateCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineColorBlendStateCreateBits does contain a bit that is not possible to be set";
	}
	if (flags & RasterizationOrderAttachmentAccessBitEXT) {
		return "RasterizationOrderAttachmentAccessBitEXT";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & DisableOptimization) {
		bytes += 22;
	}
	if (flags & AllowDerivatives) {
		bytes += 19;
	}
	if (flags & Derivative) {
		bytes += 13;
	}
	if (flags & ViewIndexFromDeviceIndex) {
		bytes += 27;
	}
	if (flags & DispatchBase) {
		bytes += 15;
	}
	if (flags & DeferCompileBitNV) {
		bytes += 20;
	}
	if (flags & CaptureStatisticsBitKHR) {
		bytes += 26;
	}
	if (flags & CaptureInternalRepresentationsBitKHR) {
		bytes += 39;
	}
	if (flags & FailOnPipelineCompileRequired) {
		bytes += 32;
	}
	if (flags & EarlyReturnOnFailure) {
		bytes += 23;
	}
	if (flags & LinkTimeOptimizationBitEXT) {
		bytes += 29;
	}
	if (flags & LibraryBitKHR) {
		bytes += 16;
	}
	if (flags & RayTracingSkipTrianglesBitKHR) {
		bytes += 32;
	}
	if (flags & RayTracingSkipAabbsBitKHR) {
		bytes += 28;
	}
	if (flags & RayTracingNoNullAnyHitShadersBitKHR) {
		bytes += 38;
	}
	if (flags & RayTracingNoNullClosestHitShadersBitKHR) {
		bytes += 42;
	}
	if (flags & RayTracingNoNullMissShadersBitKHR) {
		bytes += 36;
	}
	if (flags & RayTracingNoNullIntersectionShadersBitKHR) {
		bytes += 44;
	}
	if (flags & IndirectBindableBitNV) {
		bytes += 24;
	}
	if (flags & RayTracingShaderGroupHandleCaptureReplayBitKHR) {
		bytes += 49;
	}
	if (flags & RayTracingAllowMotionBitNV) {
		bytes += 29;
	}
	if (flags & RenderingFragmentShadingRateAttachmentBitKHR) {
		bytes += 47;
	}
	if (flags & RenderingFragmentDensityMapAttachmentBitEXT) {
		bytes += 46;
	}
	if (flags & RetainLinkTimeOptimizationInfoBitEXT) {
		bytes += 39;
	}
	if (flags & RayTracingOpacityMicromapBitKHR) {
		bytes += 34;
	}
	if (flags & ColorAttachmentFeedbackLoopBitEXT) {
		bytes += 36;
	}
	if (flags & DepthStencilAttachmentFeedbackLoopBitEXT) {
		bytes += 43;
	}
	if (flags & NoProtectedAccess) {
		bytes += 20;
	}
	if (flags & RayTracingDisplacementMicromapBitNV) {
		bytes += 38;
	}
	if (flags & DescriptorBufferBitEXT) {
		bytes += 25;
	}
	if (flags & ProtectedAccessOnly) {
		bytes += 22;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DisableOptimization) {
		first = false;
		ret += "DisableOptimization";
	}
	if (flags & AllowDerivatives) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowDerivatives";
	}
	if (flags & Derivative) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Derivative";
	}
	if (flags & ViewIndexFromDeviceIndex) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ViewIndexFromDeviceIndex";
	}
	if (flags & DispatchBase) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DispatchBase";
	}
	if (flags & DeferCompileBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeferCompileBitNV";
	}
	if (flags & CaptureStatisticsBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CaptureStatisticsBitKHR";
	}
	if (flags & CaptureInternalRepresentationsBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CaptureInternalRepresentationsBitKHR";
	}
	if (flags & FailOnPipelineCompileRequired) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FailOnPipelineCompileRequired";
	}
	if (flags & EarlyReturnOnFailure) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EarlyReturnOnFailure";
	}
	if (flags & LinkTimeOptimizationBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LinkTimeOptimizationBitEXT";
	}
	if (flags & LibraryBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LibraryBitKHR";
	}
	if (flags & RayTracingSkipTrianglesBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingSkipTrianglesBitKHR";
	}
	if (flags & RayTracingSkipAabbsBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingSkipAabbsBitKHR";
	}
	if (flags & RayTracingNoNullAnyHitShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullAnyHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullClosestHitShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullClosestHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullMissShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullMissShadersBitKHR";
	}
	if (flags & RayTracingNoNullIntersectionShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullIntersectionShadersBitKHR";
	}
	if (flags & IndirectBindableBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectBindableBitNV";
	}
	if (flags & RayTracingShaderGroupHandleCaptureReplayBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingShaderGroupHandleCaptureReplayBitKHR";
	}
	if (flags & RayTracingAllowMotionBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingAllowMotionBitNV";
	}
	if (flags & RenderingFragmentShadingRateAttachmentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RenderingFragmentShadingRateAttachmentBitKHR";
	}
	if (flags & RenderingFragmentDensityMapAttachmentBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RenderingFragmentDensityMapAttachmentBitEXT";
	}
	if (flags & RetainLinkTimeOptimizationInfoBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RetainLinkTimeOptimizationInfoBitEXT";
	}
	if (flags & RayTracingOpacityMicromapBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingOpacityMicromapBitKHR";
	}
	if (flags & ColorAttachmentFeedbackLoopBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentFeedbackLoopBitEXT";
	}
	if (flags & DepthStencilAttachmentFeedbackLoopBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachmentFeedbackLoopBitEXT";
	}
	if (flags & NoProtectedAccess) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "NoProtectedAccess";
	}
	if (flags & RayTracingDisplacementMicromapBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingDisplacementMicromapBitNV";
	}
	if (flags & DescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferBitEXT";
	}
	if (flags & ProtectedAccessOnly) {
		if (!first) {
			ret += " | ";
		}
		ret += "ProtectedAccessOnly";
	}
	return ret;
}
template<> auto flagsToString(PipelineCreateFlags2 flags) -> std::string {
	using enum PipelineCreateBits2;
	if ((flags & AllBits) != flags) {
		return "PipelineCreateBits2 does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DisableOptimization) {
		bytes += 22;
	}
	if (flags & AllowDerivatives) {
		bytes += 19;
	}
	if (flags & Derivative) {
		bytes += 13;
	}
	if (flags & ViewIndexFromDeviceIndex) {
		bytes += 27;
	}
	if (flags & DispatchBase) {
		bytes += 15;
	}
	if (flags & DeferCompileBitNV) {
		bytes += 20;
	}
	if (flags & CaptureStatisticsBitKHR) {
		bytes += 26;
	}
	if (flags & CaptureInternalRepresentationsBitKHR) {
		bytes += 39;
	}
	if (flags & FailOnPipelineCompileRequired) {
		bytes += 32;
	}
	if (flags & EarlyReturnOnFailure) {
		bytes += 23;
	}
	if (flags & LinkTimeOptimizationBitEXT) {
		bytes += 29;
	}
	if (flags & LibraryBitKHR) {
		bytes += 16;
	}
	if (flags & RayTracingSkipTrianglesBitKHR) {
		bytes += 32;
	}
	if (flags & RayTracingSkipAabbsBitKHR) {
		bytes += 28;
	}
	if (flags & RayTracingNoNullAnyHitShadersBitKHR) {
		bytes += 38;
	}
	if (flags & RayTracingNoNullClosestHitShadersBitKHR) {
		bytes += 42;
	}
	if (flags & RayTracingNoNullMissShadersBitKHR) {
		bytes += 36;
	}
	if (flags & RayTracingNoNullIntersectionShadersBitKHR) {
		bytes += 44;
	}
	if (flags & IndirectBindableBitNV) {
		bytes += 24;
	}
	if (flags & RayTracingShaderGroupHandleCaptureReplayBitKHR) {
		bytes += 49;
	}
	if (flags & RayTracingAllowMotionBitNV) {
		bytes += 29;
	}
	if (flags & RenderingFragmentShadingRateAttachmentBitKHR) {
		bytes += 47;
	}
	if (flags & RenderingFragmentDensityMapAttachmentBitEXT) {
		bytes += 46;
	}
	if (flags & RetainLinkTimeOptimizationInfoBitEXT) {
		bytes += 39;
	}
	if (flags & RayTracingOpacityMicromapBitKHR) {
		bytes += 34;
	}
	if (flags & ColorAttachmentFeedbackLoopBitEXT) {
		bytes += 36;
	}
	if (flags & DepthStencilAttachmentFeedbackLoopBitEXT) {
		bytes += 43;
	}
	if (flags & NoProtectedAccess) {
		bytes += 20;
	}
	if (flags & RayTracingDisplacementMicromapBitNV) {
		bytes += 38;
	}
	if (flags & DescriptorBufferBitEXT) {
		bytes += 25;
	}
	if (flags & ProtectedAccessOnly) {
		bytes += 22;
	}
	if (flags & CaptureDataBitKHR) {
		bytes += 20;
	}
	if (flags & ExecutionGraphBitAMDX) {
		bytes += 24;
	}
	if (flags & RayTracingAllowSpheresAndLinearSweptSpheresBitNV) {
		bytes += 51;
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		bytes += 30;
	}
	if (flags & DescriptorHeapBitEXT) {
		bytes += 23;
	}
	if (flags & DisallowOpacityMicromapBitARM) {
		bytes += 32;
	}
	if (flags & IndirectBindableBitEXT) {
		bytes += 25;
	}
	if (flags & InstrumentShadersBitARM) {
		bytes += 26;
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		bytes += 34;
	}
	if (flags & OpacityMicromapDisallowMixedSpecialIndexBitKHR) {
		bytes += 49;
	}
	if (flags & v64BitIndexingBitEXT) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DisableOptimization) {
		first = false;
		ret += "DisableOptimization";
	}
	if (flags & AllowDerivatives) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowDerivatives";
	}
	if (flags & Derivative) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Derivative";
	}
	if (flags & ViewIndexFromDeviceIndex) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ViewIndexFromDeviceIndex";
	}
	if (flags & DispatchBase) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DispatchBase";
	}
	if (flags & DeferCompileBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeferCompileBitNV";
	}
	if (flags & CaptureStatisticsBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CaptureStatisticsBitKHR";
	}
	if (flags & CaptureInternalRepresentationsBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CaptureInternalRepresentationsBitKHR";
	}
	if (flags & FailOnPipelineCompileRequired) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FailOnPipelineCompileRequired";
	}
	if (flags & EarlyReturnOnFailure) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EarlyReturnOnFailure";
	}
	if (flags & LinkTimeOptimizationBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LinkTimeOptimizationBitEXT";
	}
	if (flags & LibraryBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LibraryBitKHR";
	}
	if (flags & RayTracingSkipTrianglesBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingSkipTrianglesBitKHR";
	}
	if (flags & RayTracingSkipAabbsBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingSkipAabbsBitKHR";
	}
	if (flags & RayTracingNoNullAnyHitShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullAnyHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullClosestHitShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullClosestHitShadersBitKHR";
	}
	if (flags & RayTracingNoNullMissShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullMissShadersBitKHR";
	}
	if (flags & RayTracingNoNullIntersectionShadersBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingNoNullIntersectionShadersBitKHR";
	}
	if (flags & IndirectBindableBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectBindableBitNV";
	}
	if (flags & RayTracingShaderGroupHandleCaptureReplayBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingShaderGroupHandleCaptureReplayBitKHR";
	}
	if (flags & RayTracingAllowMotionBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingAllowMotionBitNV";
	}
	if (flags & RenderingFragmentShadingRateAttachmentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RenderingFragmentShadingRateAttachmentBitKHR";
	}
	if (flags & RenderingFragmentDensityMapAttachmentBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RenderingFragmentDensityMapAttachmentBitEXT";
	}
	if (flags & RetainLinkTimeOptimizationInfoBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RetainLinkTimeOptimizationInfoBitEXT";
	}
	if (flags & RayTracingOpacityMicromapBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingOpacityMicromapBitKHR";
	}
	if (flags & ColorAttachmentFeedbackLoopBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentFeedbackLoopBitEXT";
	}
	if (flags & DepthStencilAttachmentFeedbackLoopBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DepthStencilAttachmentFeedbackLoopBitEXT";
	}
	if (flags & NoProtectedAccess) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "NoProtectedAccess";
	}
	if (flags & RayTracingDisplacementMicromapBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingDisplacementMicromapBitNV";
	}
	if (flags & DescriptorBufferBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferBitEXT";
	}
	if (flags & ProtectedAccessOnly) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ProtectedAccessOnly";
	}
	if (flags & CaptureDataBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CaptureDataBitKHR";
	}
	if (flags & ExecutionGraphBitAMDX) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ExecutionGraphBitAMDX";
	}
	if (flags & RayTracingAllowSpheresAndLinearSweptSpheresBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingAllowSpheresAndLinearSweptSpheresBitNV";
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableLegacyDitheringBitEXT";
	}
	if (flags & DescriptorHeapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorHeapBitEXT";
	}
	if (flags & DisallowOpacityMicromapBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DisallowOpacityMicromapBitARM";
	}
	if (flags & IndirectBindableBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectBindableBitEXT";
	}
	if (flags & InstrumentShadersBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InstrumentShadersBitARM";
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerLayerFragmentDensityBitVALVE";
	}
	if (flags & OpacityMicromapDisallowMixedSpecialIndexBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpacityMicromapDisallowMixedSpecialIndexBitKHR";
	}
	if (flags & v64BitIndexingBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "v64BitIndexingBitEXT";
	}
	return ret;
}
template<> auto flagsToString(PipelineCreationFeedbackFlags flags) -> std::string {
	using enum PipelineCreationFeedbackBits;
	if ((flags & AllBits) != flags) {
		return "PipelineCreationFeedbackBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Valid) {
		bytes += 8;
	}
	if (flags & ApplicationPipelineCacheHit) {
		bytes += 30;
	}
	if (flags & BasePipelineAcceleration) {
		bytes += 27;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Valid) {
		first = false;
		ret += "Valid";
	}
	if (flags & ApplicationPipelineCacheHit) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ApplicationPipelineCacheHit";
	}
	if (flags & BasePipelineAcceleration) {
		if (!first) {
			ret += " | ";
		}
		ret += "BasePipelineAcceleration";
	}
	return ret;
}
template<> auto flagsToString(PipelineDepthStencilStateCreateFlags flags) -> std::string {
	using enum PipelineDepthStencilStateCreateBits;
	if ((flags & AllBits) != flags) {
		return "PipelineDepthStencilStateCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & RasterizationOrderAttachmentDepthAccessBitEXT) {
		bytes += 48;
	}
	if (flags & RasterizationOrderAttachmentStencilAccessBitEXT) {
		bytes += 50;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & RasterizationOrderAttachmentDepthAccessBitEXT) {
		first = false;
		ret += "RasterizationOrderAttachmentDepthAccessBitEXT";
	}
	if (flags & RasterizationOrderAttachmentStencilAccessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "RasterizationOrderAttachmentStencilAccessBitEXT";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & IndependentSetsBitEXT) {
		bytes += 24;
	}
	if (flags & NoTaskShaderBitKHR) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & IndependentSetsBitEXT) {
		first = false;
		ret += "IndependentSetsBitEXT";
	}
	if (flags & NoTaskShaderBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "NoTaskShaderBitKHR";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & AllowVaryingSubgroupSize) {
		bytes += 27;
	}
	if (flags & RequireFullSubgroups) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & AllowVaryingSubgroupSize) {
		first = false;
		ret += "AllowVaryingSubgroupSize";
	}
	if (flags & RequireFullSubgroups) {
		if (!first) {
			ret += " | ";
		}
		ret += "RequireFullSubgroups";
	}
	return ret;
}
template<> auto flagsToString(PipelineStageFlags flags) -> std::string {
	using enum PipelineStageBits;
	if ((flags & AllBits) != flags) {
		return "PipelineStageBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & TopOfPipe) {
		bytes += 12;
	}
	if (flags & DrawIndirect) {
		bytes += 15;
	}
	if (flags & VertexInput) {
		bytes += 14;
	}
	if (flags & VertexShader) {
		bytes += 15;
	}
	if (flags & TessellationControlShader) {
		bytes += 28;
	}
	if (flags & TessellationEvaluationShader) {
		bytes += 31;
	}
	if (flags & GeometryShader) {
		bytes += 17;
	}
	if (flags & FragmentShader) {
		bytes += 17;
	}
	if (flags & EarlyFragmentTests) {
		bytes += 21;
	}
	if (flags & LateFragmentTests) {
		bytes += 20;
	}
	if (flags & ColorAttachmentOutput) {
		bytes += 24;
	}
	if (flags & ComputeShader) {
		bytes += 16;
	}
	if (flags & Transfer) {
		bytes += 11;
	}
	if (flags & BottomOfPipe) {
		bytes += 15;
	}
	if (flags & Host) {
		bytes += 7;
	}
	if (flags & AllGraphics) {
		bytes += 14;
	}
	if (flags & AllCommands) {
		bytes += 14;
	}
	if (flags & CommandPreprocessBitEXT) {
		bytes += 26;
	}
	if (flags & ConditionalRenderingBitEXT) {
		bytes += 29;
	}
	if (flags & TaskShaderBitEXT) {
		bytes += 19;
	}
	if (flags & MeshShaderBitEXT) {
		bytes += 19;
	}
	if (flags & RayTracingShaderBitKHR) {
		bytes += 25;
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		bytes += 38;
	}
	if (flags & FragmentDensityProcessBitEXT) {
		bytes += 31;
	}
	if (flags & TransformFeedbackBitEXT) {
		bytes += 26;
	}
	if (flags & AccelerationStructureBuildBitKHR) {
		bytes += 35;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & TopOfPipe) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TopOfPipe";
	}
	if (flags & DrawIndirect) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DrawIndirect";
	}
	if (flags & VertexInput) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexInput";
	}
	if (flags & VertexShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexShader";
	}
	if (flags & TessellationControlShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationControlShader";
	}
	if (flags & TessellationEvaluationShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationEvaluationShader";
	}
	if (flags & GeometryShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "GeometryShader";
	}
	if (flags & FragmentShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShader";
	}
	if (flags & EarlyFragmentTests) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EarlyFragmentTests";
	}
	if (flags & LateFragmentTests) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LateFragmentTests";
	}
	if (flags & ColorAttachmentOutput) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentOutput";
	}
	if (flags & ComputeShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ComputeShader";
	}
	if (flags & Transfer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Transfer";
	}
	if (flags & BottomOfPipe) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BottomOfPipe";
	}
	if (flags & Host) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Host";
	}
	if (flags & AllGraphics) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllGraphics";
	}
	if (flags & AllCommands) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllCommands";
	}
	if (flags & CommandPreprocessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CommandPreprocessBitEXT";
	}
	if (flags & ConditionalRenderingBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConditionalRenderingBitEXT";
	}
	if (flags & TaskShaderBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TaskShaderBitEXT";
	}
	if (flags & MeshShaderBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MeshShaderBitEXT";
	}
	if (flags & RayTracingShaderBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingShaderBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & FragmentDensityProcessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityProcessBitEXT";
	}
	if (flags & TransformFeedbackBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackBitEXT";
	}
	if (flags & AccelerationStructureBuildBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "AccelerationStructureBuildBitKHR";
	}
	return ret;
}
template<> auto flagsToString(PipelineStageFlags2 flags) -> std::string {
	using enum PipelineStageBits2;
	if ((flags & AllBits) != flags) {
		return "PipelineStageBits2 does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & TopOfPipe) {
		bytes += 12;
	}
	if (flags & DrawIndirect) {
		bytes += 15;
	}
	if (flags & VertexInput) {
		bytes += 14;
	}
	if (flags & VertexShader) {
		bytes += 15;
	}
	if (flags & TessellationControlShader) {
		bytes += 28;
	}
	if (flags & TessellationEvaluationShader) {
		bytes += 31;
	}
	if (flags & GeometryShader) {
		bytes += 17;
	}
	if (flags & FragmentShader) {
		bytes += 17;
	}
	if (flags & EarlyFragmentTests) {
		bytes += 21;
	}
	if (flags & LateFragmentTests) {
		bytes += 20;
	}
	if (flags & ColorAttachmentOutput) {
		bytes += 24;
	}
	if (flags & ComputeShader) {
		bytes += 16;
	}
	if (flags & AllTransfer) {
		bytes += 14;
	}
	if (flags & BottomOfPipe) {
		bytes += 15;
	}
	if (flags & Host) {
		bytes += 7;
	}
	if (flags & AllGraphics) {
		bytes += 14;
	}
	if (flags & AllCommands) {
		bytes += 14;
	}
	if (flags & CommandPreprocessBitEXT) {
		bytes += 26;
	}
	if (flags & ConditionalRenderingBitEXT) {
		bytes += 29;
	}
	if (flags & TaskShaderBitEXT) {
		bytes += 19;
	}
	if (flags & MeshShaderBitEXT) {
		bytes += 19;
	}
	if (flags & RayTracingShaderBitKHR) {
		bytes += 25;
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		bytes += 38;
	}
	if (flags & FragmentDensityProcessBitEXT) {
		bytes += 31;
	}
	if (flags & TransformFeedbackBitEXT) {
		bytes += 26;
	}
	if (flags & AccelerationStructureBuildBitKHR) {
		bytes += 35;
	}
	if (flags & VideoDecodeBitKHR) {
		bytes += 20;
	}
	if (flags & VideoEncodeBitKHR) {
		bytes += 20;
	}
	if (flags & AccelerationStructureCopyBitKHR) {
		bytes += 34;
	}
	if (flags & OpticalFlowBitNV) {
		bytes += 19;
	}
	if (flags & MicromapBuildBitEXT) {
		bytes += 22;
	}
	if (flags & Copy) {
		bytes += 7;
	}
	if (flags & Resolve) {
		bytes += 10;
	}
	if (flags & Blit) {
		bytes += 7;
	}
	if (flags & Clear) {
		bytes += 8;
	}
	if (flags & IndexInput) {
		bytes += 13;
	}
	if (flags & VertexAttributeInput) {
		bytes += 23;
	}
	if (flags & PreRasterizationShaders) {
		bytes += 26;
	}
	if (flags & SubpassShaderBitHUAWEI) {
		bytes += 25;
	}
	if (flags & InvocationMaskBitHUAWEI) {
		bytes += 26;
	}
	if (flags & ClusterCullingShaderBitHUAWEI) {
		bytes += 32;
	}
	if (flags & DataGraphBitARM) {
		bytes += 18;
	}
	if (flags & ConvertCooperativeVectorMatrixBitNV) {
		bytes += 38;
	}
	if (flags & MemoryDecompressionBitEXT) {
		bytes += 28;
	}
	if (flags & CopyIndirectBitKHR) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & TopOfPipe) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TopOfPipe";
	}
	if (flags & DrawIndirect) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DrawIndirect";
	}
	if (flags & VertexInput) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexInput";
	}
	if (flags & VertexShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexShader";
	}
	if (flags & TessellationControlShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationControlShader";
	}
	if (flags & TessellationEvaluationShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationEvaluationShader";
	}
	if (flags & GeometryShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "GeometryShader";
	}
	if (flags & FragmentShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShader";
	}
	if (flags & EarlyFragmentTests) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EarlyFragmentTests";
	}
	if (flags & LateFragmentTests) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "LateFragmentTests";
	}
	if (flags & ColorAttachmentOutput) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ColorAttachmentOutput";
	}
	if (flags & ComputeShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ComputeShader";
	}
	if (flags & AllTransfer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllTransfer";
	}
	if (flags & BottomOfPipe) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BottomOfPipe";
	}
	if (flags & Host) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Host";
	}
	if (flags & AllGraphics) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllGraphics";
	}
	if (flags & AllCommands) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllCommands";
	}
	if (flags & CommandPreprocessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CommandPreprocessBitEXT";
	}
	if (flags & ConditionalRenderingBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConditionalRenderingBitEXT";
	}
	if (flags & TaskShaderBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TaskShaderBitEXT";
	}
	if (flags & MeshShaderBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MeshShaderBitEXT";
	}
	if (flags & RayTracingShaderBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RayTracingShaderBitKHR";
	}
	if (flags & FragmentShadingRateAttachmentBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachmentBitKHR";
	}
	if (flags & FragmentDensityProcessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityProcessBitEXT";
	}
	if (flags & TransformFeedbackBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformFeedbackBitEXT";
	}
	if (flags & AccelerationStructureBuildBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureBuildBitKHR";
	}
	if (flags & VideoDecodeBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeBitKHR";
	}
	if (flags & VideoEncodeBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeBitKHR";
	}
	if (flags & AccelerationStructureCopyBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructureCopyBitKHR";
	}
	if (flags & OpticalFlowBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpticalFlowBitNV";
	}
	if (flags & MicromapBuildBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MicromapBuildBitEXT";
	}
	if (flags & Copy) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Copy";
	}
	if (flags & Resolve) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Resolve";
	}
	if (flags & Blit) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Blit";
	}
	if (flags & Clear) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Clear";
	}
	if (flags & IndexInput) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndexInput";
	}
	if (flags & VertexAttributeInput) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexAttributeInput";
	}
	if (flags & PreRasterizationShaders) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PreRasterizationShaders";
	}
	if (flags & SubpassShaderBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SubpassShaderBitHUAWEI";
	}
	if (flags & InvocationMaskBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InvocationMaskBitHUAWEI";
	}
	if (flags & ClusterCullingShaderBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ClusterCullingShaderBitHUAWEI";
	}
	if (flags & DataGraphBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DataGraphBitARM";
	}
	if (flags & ConvertCooperativeVectorMatrixBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConvertCooperativeVectorMatrixBitNV";
	}
	if (flags & MemoryDecompressionBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MemoryDecompressionBitEXT";
	}
	if (flags & CopyIndirectBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "CopyIndirectBitKHR";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Min) {
		bytes += 6;
	}
	if (flags & Max) {
		bytes += 6;
	}
	if (flags & Centered) {
		bytes += 11;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Min) {
		first = false;
		ret += "Min";
	}
	if (flags & Max) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Max";
	}
	if (flags & Centered) {
		if (!first) {
			ret += " | ";
		}
		ret += "Centered";
	}
	return ret;
}
template<> auto flagsToString(PresentScalingFlagsKHR flags) -> std::string {
	using enum PresentScalingBitsKHR;
	if ((flags & AllBits) != flags) {
		return "PresentScalingBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & OneToOne) {
		bytes += 11;
	}
	if (flags & AspectRatioStretch) {
		bytes += 21;
	}
	if (flags & Stretch) {
		bytes += 10;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & OneToOne) {
		first = false;
		ret += "OneToOne";
	}
	if (flags & AspectRatioStretch) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AspectRatioStretch";
	}
	if (flags & Stretch) {
		if (!first) {
			ret += " | ";
		}
		ret += "Stretch";
	}
	return ret;
}
template<> auto flagsToString(PresentStageFlagsEXT flags) -> std::string {
	using enum PresentStageBitsEXT;
	if ((flags & AllBits) != flags) {
		return "PresentStageBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & QueueOperationsEnd) {
		bytes += 21;
	}
	if (flags & RequestDequeued) {
		bytes += 18;
	}
	if (flags & ImageFirstPixelOut) {
		bytes += 21;
	}
	if (flags & ImageFirstPixelVisible) {
		bytes += 25;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & QueueOperationsEnd) {
		first = false;
		ret += "QueueOperationsEnd";
	}
	if (flags & RequestDequeued) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RequestDequeued";
	}
	if (flags & ImageFirstPixelOut) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ImageFirstPixelOut";
	}
	if (flags & ImageFirstPixelVisible) {
		if (!first) {
			ret += " | ";
		}
		ret += "ImageFirstPixelVisible";
	}
	return ret;
}
template<> auto flagsToString(PresentTimingInfoFlagsEXT flags) -> std::string {
	using enum PresentTimingInfoBitsEXT;
	if ((flags & AllBits) != flags) {
		return "PresentTimingInfoBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & PresentAtRelativeTime) {
		bytes += 24;
	}
	if (flags & PresentAtNearestRefreshCycle) {
		bytes += 31;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & PresentAtRelativeTime) {
		first = false;
		ret += "PresentAtRelativeTime";
	}
	if (flags & PresentAtNearestRefreshCycle) {
		if (!first) {
			ret += " | ";
		}
		ret += "PresentAtNearestRefreshCycle";
	}
	return ret;
}
template<> auto flagsToString(PrivateDataSlotCreateFlags flags) -> std::string {
	using enum PrivateDataSlotCreateBits;
	if ((flags & AllBits) != flags) {
		return "PrivateDataSlotCreateBits does contain a bit that is not possible to be set";
	}
	if (flags & BaseObjectHandleBitNV) {
		return "BaseObjectHandleBitNV";
	}
	return "";
}
template<> auto flagsToString(QueryControlFlags flags) -> std::string {
	using enum QueryControlBits;
	if ((flags & AllBits) != flags) {
		return "QueryControlBits does contain a bit that is not possible to be set";
	}
	if (flags & Precise) {
		return "Precise";
	}
	return "";
}
template<> auto flagsToString(QueryPipelineStatisticFlags flags) -> std::string {
	using enum QueryPipelineStatisticBits;
	if ((flags & AllBits) != flags) {
		return "QueryPipelineStatisticBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & InputAssemblyVertices) {
		bytes += 24;
	}
	if (flags & InputAssemblyPrimitives) {
		bytes += 26;
	}
	if (flags & VertexShaderInvocations) {
		bytes += 26;
	}
	if (flags & GeometryShaderInvocations) {
		bytes += 28;
	}
	if (flags & GeometryShaderPrimitives) {
		bytes += 27;
	}
	if (flags & ClippingInvocations) {
		bytes += 22;
	}
	if (flags & ClippingPrimitives) {
		bytes += 21;
	}
	if (flags & FragmentShaderInvocations) {
		bytes += 28;
	}
	if (flags & TessellationControlShaderPatches) {
		bytes += 35;
	}
	if (flags & TessellationEvaluationShaderInvocations) {
		bytes += 42;
	}
	if (flags & ComputeShaderInvocations) {
		bytes += 27;
	}
	if (flags & TaskShaderInvocationsBitEXT) {
		bytes += 30;
	}
	if (flags & MeshShaderInvocationsBitEXT) {
		bytes += 30;
	}
	if (flags & ClusterCullingShaderInvocationsBitHUAWEI) {
		bytes += 43;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & InputAssemblyVertices) {
		first = false;
		ret += "InputAssemblyVertices";
	}
	if (flags & InputAssemblyPrimitives) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InputAssemblyPrimitives";
	}
	if (flags & VertexShaderInvocations) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VertexShaderInvocations";
	}
	if (flags & GeometryShaderInvocations) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "GeometryShaderInvocations";
	}
	if (flags & GeometryShaderPrimitives) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "GeometryShaderPrimitives";
	}
	if (flags & ClippingInvocations) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ClippingInvocations";
	}
	if (flags & ClippingPrimitives) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ClippingPrimitives";
	}
	if (flags & FragmentShaderInvocations) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShaderInvocations";
	}
	if (flags & TessellationControlShaderPatches) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationControlShaderPatches";
	}
	if (flags & TessellationEvaluationShaderInvocations) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationEvaluationShaderInvocations";
	}
	if (flags & ComputeShaderInvocations) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ComputeShaderInvocations";
	}
	if (flags & TaskShaderInvocationsBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TaskShaderInvocationsBitEXT";
	}
	if (flags & MeshShaderInvocationsBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MeshShaderInvocationsBitEXT";
	}
	if (flags & ClusterCullingShaderInvocationsBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		ret += "ClusterCullingShaderInvocationsBitHUAWEI";
	}
	return ret;
}
template<> auto flagsToString(QueryPoolCreateFlags flags) -> std::string {
	using enum QueryPoolCreateBits;
	if ((flags & AllBits) != flags) {
		return "QueryPoolCreateBits does contain a bit that is not possible to be set";
	}
	if (flags & ResetBitKHR) {
		return "ResetBitKHR";
	}
	return "";
}
template<> auto flagsToString(QueryResultFlags flags) -> std::string {
	using enum QueryResultBits;
	if ((flags & AllBits) != flags) {
		return "QueryResultBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & v64) {
		bytes += 6;
	}
	if (flags & Wait) {
		bytes += 7;
	}
	if (flags & WithAvailability) {
		bytes += 19;
	}
	if (flags & Partial) {
		bytes += 10;
	}
	if (flags & WithStatusBitKHR) {
		bytes += 19;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & v64) {
		first = false;
		ret += "v64";
	}
	if (flags & Wait) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Wait";
	}
	if (flags & WithAvailability) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WithAvailability";
	}
	if (flags & Partial) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Partial";
	}
	if (flags & WithStatusBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "WithStatusBitKHR";
	}
	return ret;
}
template<> auto flagsToString(QueueFlags flags) -> std::string {
	using enum QueueBits;
	if ((flags & AllBits) != flags) {
		return "QueueBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Graphics) {
		bytes += 11;
	}
	if (flags & Compute) {
		bytes += 10;
	}
	if (flags & Transfer) {
		bytes += 11;
	}
	if (flags & SparseBinding) {
		bytes += 16;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & VideoDecodeBitKHR) {
		bytes += 20;
	}
	if (flags & VideoEncodeBitKHR) {
		bytes += 20;
	}
	if (flags & OpticalFlowBitNV) {
		bytes += 19;
	}
	if (flags & DataGraphBitARM) {
		bytes += 18;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Graphics) {
		first = false;
		ret += "Graphics";
	}
	if (flags & Compute) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Compute";
	}
	if (flags & Transfer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Transfer";
	}
	if (flags & SparseBinding) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SparseBinding";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Protected";
	}
	if (flags & VideoDecodeBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoDecodeBitKHR";
	}
	if (flags & VideoEncodeBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "VideoEncodeBitKHR";
	}
	if (flags & OpticalFlowBitNV) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpticalFlowBitNV";
	}
	if (flags & DataGraphBitARM) {
		if (!first) {
			ret += " | ";
		}
		ret += "DataGraphBitARM";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & TransformBitQCOM) {
		bytes += 19;
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		bytes += 34;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & TransformBitQCOM) {
		first = false;
		ret += "TransformBitQCOM";
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		if (!first) {
			ret += " | ";
		}
		ret += "PerLayerFragmentDensityBitVALVE";
	}
	return ret;
}
template<> auto flagsToString(RenderingAttachmentFlagsKHR flags) -> std::string {
	using enum RenderingAttachmentBitsKHR;
	if ((flags & AllBits) != flags) {
		return "RenderingAttachmentBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & InputAttachmentFeedback) {
		bytes += 26;
	}
	if (flags & ResolveSkipTransferFunction) {
		bytes += 30;
	}
	if (flags & ResolveEnableTransferFunction) {
		bytes += 32;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & InputAttachmentFeedback) {
		first = false;
		ret += "InputAttachmentFeedback";
	}
	if (flags & ResolveSkipTransferFunction) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ResolveSkipTransferFunction";
	}
	if (flags & ResolveEnableTransferFunction) {
		if (!first) {
			ret += " | ";
		}
		ret += "ResolveEnableTransferFunction";
	}
	return ret;
}
template<> auto flagsToString(RenderingFlags flags) -> std::string {
	using enum RenderingBits;
	if ((flags & AllBits) != flags) {
		return "RenderingBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & ContentsSecondaryCommandBuffers) {
		bytes += 34;
	}
	if (flags & Suspending) {
		bytes += 13;
	}
	if (flags & Resuming) {
		bytes += 11;
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		bytes += 30;
	}
	if (flags & ContentsInlineBitKHR) {
		bytes += 23;
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		bytes += 34;
	}
	if (flags & FragmentRegionBitEXT) {
		bytes += 23;
	}
	if (flags & CustomResolveBitEXT) {
		bytes += 22;
	}
	if (flags & LocalReadConcurrentAccessControlBitKHR) {
		bytes += 41;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ContentsSecondaryCommandBuffers) {
		first = false;
		ret += "ContentsSecondaryCommandBuffers";
	}
	if (flags & Suspending) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Suspending";
	}
	if (flags & Resuming) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Resuming";
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableLegacyDitheringBitEXT";
	}
	if (flags & ContentsInlineBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ContentsInlineBitKHR";
	}
	if (flags & PerLayerFragmentDensityBitVALVE) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerLayerFragmentDensityBitVALVE";
	}
	if (flags & FragmentRegionBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentRegionBitEXT";
	}
	if (flags & CustomResolveBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CustomResolveBitEXT";
	}
	if (flags & LocalReadConcurrentAccessControlBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "LocalReadConcurrentAccessControlBitKHR";
	}
	return ret;
}
template<> auto flagsToString(ResolveImageFlagsKHR flags) -> std::string {
	using enum ResolveImageBitsKHR;
	if ((flags & AllBits) != flags) {
		return "ResolveImageBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SkipTransferFunction) {
		bytes += 23;
	}
	if (flags & EnableTransferFunction) {
		bytes += 25;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SkipTransferFunction) {
		first = false;
		ret += "SkipTransferFunction";
	}
	if (flags & EnableTransferFunction) {
		if (!first) {
			ret += " | ";
		}
		ret += "EnableTransferFunction";
	}
	return ret;
}
template<> auto flagsToString(ResolveModeFlags flags) -> std::string {
	using enum ResolveModeBits;
	if ((flags & AllBits) != flags) {
		return "ResolveModeBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & SampleZero) {
		bytes += 13;
	}
	if (flags & Average) {
		bytes += 10;
	}
	if (flags & Min) {
		bytes += 6;
	}
	if (flags & Max) {
		bytes += 6;
	}
	if (flags & ExternalFormatDownsampleBitANDROID) {
		bytes += 37;
	}
	if (flags & CustomBitEXT) {
		bytes += 15;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & SampleZero) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleZero";
	}
	if (flags & Average) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Average";
	}
	if (flags & Min) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Min";
	}
	if (flags & Max) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Max";
	}
	if (flags & ExternalFormatDownsampleBitANDROID) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ExternalFormatDownsampleBitANDROID";
	}
	if (flags & CustomBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "CustomBitEXT";
	}
	return ret;
}
template<> auto flagsToString(SampleCountFlags flags) -> std::string {
	using enum SampleCountBits;
	if ((flags & AllBits) != flags) {
		return "SampleCountBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & v1) {
		bytes += 5;
	}
	if (flags & v2) {
		bytes += 5;
	}
	if (flags & v4) {
		bytes += 5;
	}
	if (flags & v8) {
		bytes += 5;
	}
	if (flags & v16) {
		bytes += 6;
	}
	if (flags & v32) {
		bytes += 6;
	}
	if (flags & v64) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & v1) {
		first = false;
		ret += "v1";
	}
	if (flags & v2) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v2";
	}
	if (flags & v4) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v4";
	}
	if (flags & v8) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v8";
	}
	if (flags & v16) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v16";
	}
	if (flags & v32) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v32";
	}
	if (flags & v64) {
		if (!first) {
			ret += " | ";
		}
		ret += "v64";
	}
	return ret;
}
template<> auto flagsToString(SamplerCreateFlags flags) -> std::string {
	using enum SamplerCreateBits;
	if ((flags & AllBits) != flags) {
		return "SamplerCreateBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SubsampledBitEXT) {
		bytes += 19;
	}
	if (flags & SubsampledCoarseReconstructionBitEXT) {
		bytes += 39;
	}
	if (flags & NonSeamlessCubeMapBitEXT) {
		bytes += 27;
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		bytes += 38;
	}
	if (flags & ImageProcessingBitQCOM) {
		bytes += 25;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SubsampledBitEXT) {
		first = false;
		ret += "SubsampledBitEXT";
	}
	if (flags & SubsampledCoarseReconstructionBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SubsampledCoarseReconstructionBitEXT";
	}
	if (flags & NonSeamlessCubeMapBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "NonSeamlessCubeMapBitEXT";
	}
	if (flags & DescriptorBufferCaptureReplayBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferCaptureReplayBitEXT";
	}
	if (flags & ImageProcessingBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		ret += "ImageProcessingBitQCOM";
	}
	return ret;
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
	if (flags & Temporary) {
		return "Temporary";
	}
	return "";
}
template<> auto flagsToString(SemaphoreWaitFlags flags) -> std::string {
	using enum SemaphoreWaitBits;
	if ((flags & AllBits) != flags) {
		return "SemaphoreWaitBits does contain a bit that is not possible to be set";
	}
	if (flags & Any) {
		return "Any";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & LinkStage) {
		bytes += 12;
	}
	if (flags & AllowVaryingSubgroupSize) {
		bytes += 27;
	}
	if (flags & RequireFullSubgroups) {
		bytes += 23;
	}
	if (flags & NoTaskShader) {
		bytes += 15;
	}
	if (flags & DispatchBase) {
		bytes += 15;
	}
	if (flags & FragmentShadingRateAttachment) {
		bytes += 32;
	}
	if (flags & FragmentDensityMapAttachment) {
		bytes += 31;
	}
	if (flags & IndirectBindable) {
		bytes += 19;
	}
	if (flags & DescriptorHeap) {
		bytes += 17;
	}
	if (flags & InstrumentShaderBitARM) {
		bytes += 25;
	}
	if (flags & OpacityMicromapDisallowMixedSpecialIndex) {
		bytes += 43;
	}
	if (flags & v64BitIndexing) {
		bytes += 17;
	}
	if (flags & IndependentSetsBitKHR) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & LinkStage) {
		first = false;
		ret += "LinkStage";
	}
	if (flags & AllowVaryingSubgroupSize) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowVaryingSubgroupSize";
	}
	if (flags & RequireFullSubgroups) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RequireFullSubgroups";
	}
	if (flags & NoTaskShader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "NoTaskShader";
	}
	if (flags & DispatchBase) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DispatchBase";
	}
	if (flags & FragmentShadingRateAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentShadingRateAttachment";
	}
	if (flags & FragmentDensityMapAttachment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentDensityMapAttachment";
	}
	if (flags & IndirectBindable) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IndirectBindable";
	}
	if (flags & DescriptorHeap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorHeap";
	}
	if (flags & InstrumentShaderBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InstrumentShaderBitARM";
	}
	if (flags & OpacityMicromapDisallowMixedSpecialIndex) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "OpacityMicromapDisallowMixedSpecialIndex";
	}
	if (flags & v64BitIndexing) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v64BitIndexing";
	}
	if (flags & IndependentSetsBitKHR) {
		if (!first) {
			ret += " | ";
		}
		ret += "IndependentSetsBitKHR";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Vertex) {
		bytes += 9;
	}
	if (flags & TessellationControl) {
		bytes += 22;
	}
	if (flags & TessellationEvaluation) {
		bytes += 25;
	}
	if (flags & Geometry) {
		bytes += 11;
	}
	if (flags & Fragment) {
		bytes += 11;
	}
	if (flags & AllGraphics) {
		bytes += 14;
	}
	if (flags & Compute) {
		bytes += 10;
	}
	if (flags & TaskBitEXT) {
		bytes += 13;
	}
	if (flags & MeshBitEXT) {
		bytes += 13;
	}
	if (flags & RaygenBitKHR) {
		bytes += 15;
	}
	if (flags & AnyHitBitKHR) {
		bytes += 15;
	}
	if (flags & ClosestHitBitKHR) {
		bytes += 19;
	}
	if (flags & MissBitKHR) {
		bytes += 13;
	}
	if (flags & IntersectionBitKHR) {
		bytes += 21;
	}
	if (flags & CallableBitKHR) {
		bytes += 17;
	}
	if (flags & SubpassShadingBitHUAWEI) {
		bytes += 26;
	}
	if (flags & ClusterCullingBitHUAWEI) {
		bytes += 26;
	}
	if (flags & All) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Vertex) {
		first = false;
		ret += "Vertex";
	}
	if (flags & TessellationControl) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationControl";
	}
	if (flags & TessellationEvaluation) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TessellationEvaluation";
	}
	if (flags & Geometry) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Geometry";
	}
	if (flags & Fragment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Fragment";
	}
	if (flags & AllGraphics) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllGraphics";
	}
	if (flags & Compute) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Compute";
	}
	if (flags & TaskBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TaskBitEXT";
	}
	if (flags & MeshBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MeshBitEXT";
	}
	if (flags & RaygenBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RaygenBitKHR";
	}
	if (flags & AnyHitBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AnyHitBitKHR";
	}
	if (flags & ClosestHitBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ClosestHitBitKHR";
	}
	if (flags & MissBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MissBitKHR";
	}
	if (flags & IntersectionBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IntersectionBitKHR";
	}
	if (flags & CallableBitKHR) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CallableBitKHR";
	}
	if (flags & SubpassShadingBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SubpassShadingBitHUAWEI";
	}
	if (flags & ClusterCullingBitHUAWEI) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ClusterCullingBitHUAWEI";
	}
	if (flags & All) {
		if (!first) {
			ret += " | ";
		}
		ret += "All";
	}
	return ret;
}
template<> auto flagsToString(SparseImageFormatFlags flags) -> std::string {
	using enum SparseImageFormatBits;
	if ((flags & AllBits) != flags) {
		return "SparseImageFormatBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SingleMiptail) {
		bytes += 16;
	}
	if (flags & AlignedMipSize) {
		bytes += 17;
	}
	if (flags & NonstandardBlockSize) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SingleMiptail) {
		first = false;
		ret += "SingleMiptail";
	}
	if (flags & AlignedMipSize) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AlignedMipSize";
	}
	if (flags & NonstandardBlockSize) {
		if (!first) {
			ret += " | ";
		}
		ret += "NonstandardBlockSize";
	}
	return ret;
}
template<> auto flagsToString(SparseMemoryBindFlags flags) -> std::string {
	using enum SparseMemoryBindBits;
	if ((flags & AllBits) != flags) {
		return "SparseMemoryBindBits does contain a bit that is not possible to be set";
	}
	if (flags & Metadata) {
		return "Metadata";
	}
	return "";
}
template<> auto flagsToString(SpirvResourceTypeFlagsEXT flags) -> std::string {
	using enum SpirvResourceTypeBitsEXT;
	if ((flags & AllBits) != flags) {
		return "SpirvResourceTypeBitsEXT does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Sampler) {
		bytes += 10;
	}
	if (flags & SampledImage) {
		bytes += 15;
	}
	if (flags & ReadOnlyImage) {
		bytes += 16;
	}
	if (flags & ReadWriteImage) {
		bytes += 17;
	}
	if (flags & CombinedSampledImage) {
		bytes += 23;
	}
	if (flags & UniformBuffer) {
		bytes += 16;
	}
	if (flags & ReadOnlyStorageBuffer) {
		bytes += 24;
	}
	if (flags & ReadWriteStorageBuffer) {
		bytes += 25;
	}
	if (flags & AccelerationStructure) {
		bytes += 24;
	}
	if (flags & TensorBitARM) {
		bytes += 15;
	}
	if (flags & All) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Sampler) {
		first = false;
		ret += "Sampler";
	}
	if (flags & SampledImage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampledImage";
	}
	if (flags & ReadOnlyImage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReadOnlyImage";
	}
	if (flags & ReadWriteImage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReadWriteImage";
	}
	if (flags & CombinedSampledImage) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CombinedSampledImage";
	}
	if (flags & UniformBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "UniformBuffer";
	}
	if (flags & ReadOnlyStorageBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReadOnlyStorageBuffer";
	}
	if (flags & ReadWriteStorageBuffer) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReadWriteStorageBuffer";
	}
	if (flags & AccelerationStructure) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AccelerationStructure";
	}
	if (flags & TensorBitARM) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TensorBitARM";
	}
	if (flags & All) {
		if (!first) {
			ret += " | ";
		}
		ret += "All";
	}
	return ret;
}
template<> auto flagsToString(StencilFaceFlags flags) -> std::string {
	using enum StencilFaceBits;
	if ((flags & AllBits) != flags) {
		return "StencilFaceBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Front) {
		bytes += 8;
	}
	if (flags & Back) {
		bytes += 7;
	}
	if (flags & FrontAndBack) {
		bytes += 15;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Front) {
		first = false;
		ret += "Front";
	}
	if (flags & Back) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Back";
	}
	if (flags & FrontAndBack) {
		if (!first) {
			ret += " | ";
		}
		ret += "FrontAndBack";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Basic) {
		bytes += 8;
	}
	if (flags & Vote) {
		bytes += 7;
	}
	if (flags & Arithmetic) {
		bytes += 13;
	}
	if (flags & Ballot) {
		bytes += 9;
	}
	if (flags & Shuffle) {
		bytes += 10;
	}
	if (flags & ShuffleRelative) {
		bytes += 18;
	}
	if (flags & Clustered) {
		bytes += 12;
	}
	if (flags & Quad) {
		bytes += 7;
	}
	if (flags & PartitionedBitEXT) {
		bytes += 20;
	}
	if (flags & Rotate) {
		bytes += 9;
	}
	if (flags & RotateClustered) {
		bytes += 18;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Basic) {
		first = false;
		ret += "Basic";
	}
	if (flags & Vote) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Vote";
	}
	if (flags & Arithmetic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Arithmetic";
	}
	if (flags & Ballot) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Ballot";
	}
	if (flags & Shuffle) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Shuffle";
	}
	if (flags & ShuffleRelative) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ShuffleRelative";
	}
	if (flags & Clustered) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Clustered";
	}
	if (flags & Quad) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Quad";
	}
	if (flags & PartitionedBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PartitionedBitEXT";
	}
	if (flags & Rotate) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Rotate";
	}
	if (flags & RotateClustered) {
		if (!first) {
			ret += " | ";
		}
		ret += "RotateClustered";
	}
	return ret;
}
template<> auto flagsToString(SubmitFlags flags) -> std::string {
	using enum SubmitBits;
	if ((flags & AllBits) != flags) {
		return "SubmitBits does contain a bit that is not possible to be set";
	}
	if (flags & Protected) {
		return "Protected";
	}
	return "";
}
template<> auto flagsToString(SubpassDescriptionFlags flags) -> std::string {
	using enum SubpassDescriptionBits;
	if ((flags & AllBits) != flags) {
		return "SubpassDescriptionBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & PerViewAttributesBitNVX) {
		bytes += 26;
	}
	if (flags & PerViewPositionxOnlyBitNVX) {
		bytes += 29;
	}
	if (flags & FragmentRegionBitEXT) {
		bytes += 23;
	}
	if (flags & CustomResolveBitEXT) {
		bytes += 22;
	}
	if (flags & RasterizationOrderAttachmentColorAccessBitEXT) {
		bytes += 48;
	}
	if (flags & RasterizationOrderAttachmentDepthAccessBitEXT) {
		bytes += 48;
	}
	if (flags & RasterizationOrderAttachmentStencilAccessBitEXT) {
		bytes += 50;
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		bytes += 30;
	}
	if (flags & TileShadingApronBitQCOM) {
		bytes += 26;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & PerViewAttributesBitNVX) {
		first = false;
		ret += "PerViewAttributesBitNVX";
	}
	if (flags & PerViewPositionxOnlyBitNVX) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerViewPositionxOnlyBitNVX";
	}
	if (flags & FragmentRegionBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FragmentRegionBitEXT";
	}
	if (flags & CustomResolveBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CustomResolveBitEXT";
	}
	if (flags & RasterizationOrderAttachmentColorAccessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RasterizationOrderAttachmentColorAccessBitEXT";
	}
	if (flags & RasterizationOrderAttachmentDepthAccessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RasterizationOrderAttachmentDepthAccessBitEXT";
	}
	if (flags & RasterizationOrderAttachmentStencilAccessBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RasterizationOrderAttachmentStencilAccessBitEXT";
	}
	if (flags & EnableLegacyDitheringBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EnableLegacyDitheringBitEXT";
	}
	if (flags & TileShadingApronBitQCOM) {
		if (!first) {
			ret += " | ";
		}
		ret += "TileShadingApronBitQCOM";
	}
	return ret;
}
template<> auto flagsToString(SurfaceCounterFlagsEXT flags) -> std::string {
	using enum SurfaceCounterBitsEXT;
	if ((flags & AllBits) != flags) {
		return "SurfaceCounterBitsEXT does contain a bit that is not possible to be set";
	}
	if (flags & Vblank) {
		return "Vblank";
	}
	return "";
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
	size_t bytes = 0;
	if (flags & Identity) {
		bytes += 11;
	}
	if (flags & Rotate90) {
		bytes += 11;
	}
	if (flags & Rotate180) {
		bytes += 12;
	}
	if (flags & Rotate270) {
		bytes += 12;
	}
	if (flags & HorizontalMirror) {
		bytes += 19;
	}
	if (flags & HorizontalMirrorRotate90) {
		bytes += 27;
	}
	if (flags & HorizontalMirrorRotate180) {
		bytes += 28;
	}
	if (flags & HorizontalMirrorRotate270) {
		bytes += 28;
	}
	if (flags & Inherit) {
		bytes += 10;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Identity) {
		first = false;
		ret += "Identity";
	}
	if (flags & Rotate90) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Rotate90";
	}
	if (flags & Rotate180) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Rotate180";
	}
	if (flags & Rotate270) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Rotate270";
	}
	if (flags & HorizontalMirror) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HorizontalMirror";
	}
	if (flags & HorizontalMirrorRotate90) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HorizontalMirrorRotate90";
	}
	if (flags & HorizontalMirrorRotate180) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HorizontalMirrorRotate180";
	}
	if (flags & HorizontalMirrorRotate270) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "HorizontalMirrorRotate270";
	}
	if (flags & Inherit) {
		if (!first) {
			ret += " | ";
		}
		ret += "Inherit";
	}
	return ret;
}
template<> auto flagsToString(SwapchainCreateFlagsKHR flags) -> std::string {
	using enum SwapchainCreateBitsKHR;
	if ((flags & AllBits) != flags) {
		return "SwapchainCreateBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SplitInstanceBindRegions) {
		bytes += 27;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & MutableFormat) {
		bytes += 16;
	}
	if (flags & DeferredMemoryAllocation) {
		bytes += 27;
	}
	if (flags & PresentId2) {
		bytes += 13;
	}
	if (flags & PresentWait2) {
		bytes += 15;
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		bytes += 42;
	}
	if (flags & PresentTimingBitEXT) {
		bytes += 22;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SplitInstanceBindRegions) {
		first = false;
		ret += "SplitInstanceBindRegions";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Protected";
	}
	if (flags & MutableFormat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MutableFormat";
	}
	if (flags & DeferredMemoryAllocation) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeferredMemoryAllocation";
	}
	if (flags & PresentId2) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PresentId2";
	}
	if (flags & PresentWait2) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PresentWait2";
	}
	if (flags & MultisampledRenderToSingleSampledBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MultisampledRenderToSingleSampledBitEXT";
	}
	if (flags & PresentTimingBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "PresentTimingBitEXT";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & MutableFormat) {
		bytes += 16;
	}
	if (flags & Protected) {
		bytes += 12;
	}
	if (flags & DescriptorBufferCaptureReplay) {
		bytes += 32;
	}
	if (flags & DescriptorHeapCaptureReplay) {
		bytes += 30;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & MutableFormat) {
		first = false;
		ret += "MutableFormat";
	}
	if (flags & Protected) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Protected";
	}
	if (flags & DescriptorBufferCaptureReplay) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DescriptorBufferCaptureReplay";
	}
	if (flags & DescriptorHeapCaptureReplay) {
		if (!first) {
			ret += " | ";
		}
		ret += "DescriptorHeapCaptureReplay";
	}
	return ret;
}
template<> auto flagsToString(TensorUsageFlagsARM flags) -> std::string {
	using enum TensorUsageBitsARM;
	if ((flags & AllBits) != flags) {
		return "TensorUsageBitsARM does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Shader) {
		bytes += 9;
	}
	if (flags & TransferSrc) {
		bytes += 14;
	}
	if (flags & TransferDst) {
		bytes += 14;
	}
	if (flags & ImageAliasing) {
		bytes += 16;
	}
	if (flags & DataGraph) {
		bytes += 12;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Shader) {
		first = false;
		ret += "Shader";
	}
	if (flags & TransferSrc) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferSrc";
	}
	if (flags & TransferDst) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransferDst";
	}
	if (flags & ImageAliasing) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ImageAliasing";
	}
	if (flags & DataGraph) {
		if (!first) {
			ret += " | ";
		}
		ret += "DataGraph";
	}
	return ret;
}
template<> auto flagsToString(TensorViewCreateFlagsARM flags) -> std::string {
	using enum TensorViewCreateBitsARM;
	if ((flags & AllBits) != flags) {
		return "TensorViewCreateBitsARM does contain a bit that is not possible to be set";
	}
	if (flags & DescriptorBufferCaptureReplay) {
		return "DescriptorBufferCaptureReplay";
	}
	return "";
}
template<> auto flagsToString(TileShadingRenderPassFlagsQCOM flags) -> std::string {
	using enum TileShadingRenderPassBitsQCOM;
	if ((flags & AllBits) != flags) {
		return "TileShadingRenderPassBitsQCOM does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Enable) {
		bytes += 9;
	}
	if (flags & PerTileExecution) {
		bytes += 19;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Enable) {
		first = false;
		ret += "Enable";
	}
	if (flags & PerTileExecution) {
		if (!first) {
			ret += " | ";
		}
		ret += "PerTileExecution";
	}
	return ret;
}
template<> auto flagsToString(ToolPurposeFlags flags) -> std::string {
	using enum ToolPurposeBits;
	if ((flags & AllBits) != flags) {
		return "ToolPurposeBits does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Validation) {
		bytes += 13;
	}
	if (flags & Profiling) {
		bytes += 12;
	}
	if (flags & Tracing) {
		bytes += 10;
	}
	if (flags & AdditionalFeatures) {
		bytes += 21;
	}
	if (flags & ModifyingFeatures) {
		bytes += 20;
	}
	if (flags & DebugReportingBitEXT) {
		bytes += 23;
	}
	if (flags & DebugMarkersBitEXT) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Validation) {
		first = false;
		ret += "Validation";
	}
	if (flags & Profiling) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Profiling";
	}
	if (flags & Tracing) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Tracing";
	}
	if (flags & AdditionalFeatures) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AdditionalFeatures";
	}
	if (flags & ModifyingFeatures) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ModifyingFeatures";
	}
	if (flags & DebugReportingBitEXT) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DebugReportingBitEXT";
	}
	if (flags & DebugMarkersBitEXT) {
		if (!first) {
			ret += " | ";
		}
		ret += "DebugMarkersBitEXT";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & ProtectedContent) {
		bytes += 19;
	}
	if (flags & SeparateReferenceImages) {
		bytes += 26;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ProtectedContent) {
		first = false;
		ret += "ProtectedContent";
	}
	if (flags & SeparateReferenceImages) {
		if (!first) {
			ret += " | ";
		}
		ret += "SeparateReferenceImages";
	}
	return ret;
}
template<> auto flagsToString(VideoChromaSubsamplingFlagsKHR flags) -> std::string {
	using enum VideoChromaSubsamplingBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoChromaSubsamplingBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Invalid) {
		bytes += 10;
	}
	if (flags & Monochrome) {
		bytes += 13;
	}
	if (flags & v420) {
		bytes += 7;
	}
	if (flags & v422) {
		bytes += 7;
	}
	if (flags & v444) {
		bytes += 7;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Invalid) {
		first = false;
		ret += "Invalid";
	}
	if (flags & Monochrome) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Monochrome";
	}
	if (flags & v420) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v420";
	}
	if (flags & v422) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v422";
	}
	if (flags & v444) {
		if (!first) {
			ret += " | ";
		}
		ret += "v444";
	}
	return ret;
}
template<> auto flagsToString(VideoCodecOperationFlagsKHR flags) -> std::string {
	using enum VideoCodecOperationBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoCodecOperationBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & DecodeH264) {
		bytes += 13;
	}
	if (flags & DecodeH265) {
		bytes += 13;
	}
	if (flags & DecodeAV1) {
		bytes += 12;
	}
	if (flags & DecodeVp9) {
		bytes += 12;
	}
	if (flags & EncodeH264) {
		bytes += 13;
	}
	if (flags & EncodeH265) {
		bytes += 13;
	}
	if (flags & EncodeAV1) {
		bytes += 12;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & DecodeH264) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DecodeH264";
	}
	if (flags & DecodeH265) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DecodeH265";
	}
	if (flags & DecodeAV1) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DecodeAV1";
	}
	if (flags & DecodeVp9) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DecodeVp9";
	}
	if (flags & EncodeH264) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EncodeH264";
	}
	if (flags & EncodeH265) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EncodeH265";
	}
	if (flags & EncodeAV1) {
		if (!first) {
			ret += " | ";
		}
		ret += "EncodeAV1";
	}
	return ret;
}
template<> auto flagsToString(VideoCodingControlFlagsKHR flags) -> std::string {
	using enum VideoCodingControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoCodingControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Reset) {
		bytes += 8;
	}
	if (flags & EncodeRateControl) {
		bytes += 20;
	}
	if (flags & EncodeQualityLevel) {
		bytes += 21;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Reset) {
		first = false;
		ret += "Reset";
	}
	if (flags & EncodeRateControl) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EncodeRateControl";
	}
	if (flags & EncodeQualityLevel) {
		if (!first) {
			ret += " | ";
		}
		ret += "EncodeQualityLevel";
	}
	return ret;
}
template<> auto flagsToString(VideoComponentBitDepthFlagsKHR flags) -> std::string {
	using enum VideoComponentBitDepthBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoComponentBitDepthBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Invalid) {
		bytes += 10;
	}
	if (flags & v8) {
		bytes += 5;
	}
	if (flags & v10) {
		bytes += 6;
	}
	if (flags & v12) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Invalid) {
		first = false;
		ret += "Invalid";
	}
	if (flags & v8) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v8";
	}
	if (flags & v10) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v10";
	}
	if (flags & v12) {
		if (!first) {
			ret += " | ";
		}
		ret += "v12";
	}
	return ret;
}
template<> auto flagsToString(VideoDecodeCapabilityFlagsKHR flags) -> std::string {
	using enum VideoDecodeCapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoDecodeCapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & DpbAndOutputCoincide) {
		bytes += 23;
	}
	if (flags & DpbAndOutputDistinct) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & DpbAndOutputCoincide) {
		first = false;
		ret += "DpbAndOutputCoincide";
	}
	if (flags & DpbAndOutputDistinct) {
		if (!first) {
			ret += " | ";
		}
		ret += "DpbAndOutputDistinct";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Progressive) {
		bytes += 14;
	}
	if (flags & InterlacedInterleavedLines) {
		bytes += 29;
	}
	if (flags & InterlacedSeparatePlanes) {
		bytes += 27;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Progressive) {
		first = false;
		ret += "Progressive";
	}
	if (flags & InterlacedInterleavedLines) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InterlacedInterleavedLines";
	}
	if (flags & InterlacedSeparatePlanes) {
		if (!first) {
			ret += " | ";
		}
		ret += "InterlacedSeparatePlanes";
	}
	return ret;
}
template<> auto flagsToString(VideoDecodeUsageFlagsKHR flags) -> std::string {
	using enum VideoDecodeUsageBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoDecodeUsageBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Default) {
		bytes += 10;
	}
	if (flags & Transcoding) {
		bytes += 14;
	}
	if (flags & Offline) {
		bytes += 10;
	}
	if (flags & Streaming) {
		bytes += 12;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Default) {
		first = false;
		ret += "Default";
	}
	if (flags & Transcoding) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Transcoding";
	}
	if (flags & Offline) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Offline";
	}
	if (flags & Streaming) {
		if (!first) {
			ret += " | ";
		}
		ret += "Streaming";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeAV1CapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1CapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1CapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & PerRateControlGroupMinMaxQIndex) {
		bytes += 34;
	}
	if (flags & GenerateObuExtensionHeader) {
		bytes += 29;
	}
	if (flags & PrimaryReferenceCdfOnly) {
		bytes += 26;
	}
	if (flags & FrameSizeOverride) {
		bytes += 20;
	}
	if (flags & MotionVectorScaling) {
		bytes += 22;
	}
	if (flags & CompoundPredictionIntraRefresh) {
		bytes += 33;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & PerRateControlGroupMinMaxQIndex) {
		first = false;
		ret += "PerRateControlGroupMinMaxQIndex";
	}
	if (flags & GenerateObuExtensionHeader) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "GenerateObuExtensionHeader";
	}
	if (flags & PrimaryReferenceCdfOnly) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PrimaryReferenceCdfOnly";
	}
	if (flags & FrameSizeOverride) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "FrameSizeOverride";
	}
	if (flags & MotionVectorScaling) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MotionVectorScaling";
	}
	if (flags & CompoundPredictionIntraRefresh) {
		if (!first) {
			ret += " | ";
		}
		ret += "CompoundPredictionIntraRefresh";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeAV1RateControlFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1RateControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1RateControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & RegularGop) {
		bytes += 13;
	}
	if (flags & TemporalLayerPatternDyadic) {
		bytes += 29;
	}
	if (flags & ReferencePatternFlat) {
		bytes += 23;
	}
	if (flags & ReferencePatternDyadic) {
		bytes += 25;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & RegularGop) {
		first = false;
		ret += "RegularGop";
	}
	if (flags & TemporalLayerPatternDyadic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TemporalLayerPatternDyadic";
	}
	if (flags & ReferencePatternFlat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReferencePatternFlat";
	}
	if (flags & ReferencePatternDyadic) {
		if (!first) {
			ret += " | ";
		}
		ret += "ReferencePatternDyadic";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeAV1StdFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1StdBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1StdBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & UniformTileSpacingFlagSet) {
		bytes += 28;
	}
	if (flags & SkipModePresentUnset) {
		bytes += 23;
	}
	if (flags & PrimaryRefFrame) {
		bytes += 18;
	}
	if (flags & DeltaQ) {
		bytes += 9;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & UniformTileSpacingFlagSet) {
		first = false;
		ret += "UniformTileSpacingFlagSet";
	}
	if (flags & SkipModePresentUnset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SkipModePresentUnset";
	}
	if (flags & PrimaryRefFrame) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PrimaryRefFrame";
	}
	if (flags & DeltaQ) {
		if (!first) {
			ret += " | ";
		}
		ret += "DeltaQ";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeAV1SuperblockSizeFlagsKHR flags) -> std::string {
	using enum VideoEncodeAV1SuperblockSizeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeAV1SuperblockSizeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & v64) {
		bytes += 6;
	}
	if (flags & v128) {
		bytes += 7;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & v64) {
		first = false;
		ret += "v64";
	}
	if (flags & v128) {
		if (!first) {
			ret += " | ";
		}
		ret += "v128";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeCapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeCapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeCapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & PrecedingExternallyEncodedBytes) {
		bytes += 34;
	}
	if (flags & InsufficientBitstreamBufferRangeDetection) {
		bytes += 44;
	}
	if (flags & QuantizationDeltaMap) {
		bytes += 23;
	}
	if (flags & EmphasisMap) {
		bytes += 14;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & PrecedingExternallyEncodedBytes) {
		first = false;
		ret += "PrecedingExternallyEncodedBytes";
	}
	if (flags & InsufficientBitstreamBufferRangeDetection) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InsufficientBitstreamBufferRangeDetection";
	}
	if (flags & QuantizationDeltaMap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "QuantizationDeltaMap";
	}
	if (flags & EmphasisMap) {
		if (!first) {
			ret += " | ";
		}
		ret += "EmphasisMap";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeContentFlagsKHR flags) -> std::string {
	using enum VideoEncodeContentBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeContentBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Default) {
		bytes += 10;
	}
	if (flags & Camera) {
		bytes += 9;
	}
	if (flags & Desktop) {
		bytes += 10;
	}
	if (flags & Rendered) {
		bytes += 11;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Default) {
		first = false;
		ret += "Default";
	}
	if (flags & Camera) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Camera";
	}
	if (flags & Desktop) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Desktop";
	}
	if (flags & Rendered) {
		if (!first) {
			ret += " | ";
		}
		ret += "Rendered";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeFeedbackFlagsKHR flags) -> std::string {
	using enum VideoEncodeFeedbackBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeFeedbackBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & BitstreamBufferOffset) {
		bytes += 24;
	}
	if (flags & BitstreamBytesWritten) {
		bytes += 24;
	}
	if (flags & BitstreamHasOverrides) {
		bytes += 24;
	}
	if (flags & AverageQuantization) {
		bytes += 22;
	}
	if (flags & MinQuantization) {
		bytes += 18;
	}
	if (flags & MaxQuantization) {
		bytes += 18;
	}
	if (flags & IntraPixels) {
		bytes += 14;
	}
	if (flags & InterPixels) {
		bytes += 14;
	}
	if (flags & SkippedPixels) {
		bytes += 16;
	}
	if (flags & PicturePartitionCount) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & BitstreamBufferOffset) {
		first = false;
		ret += "BitstreamBufferOffset";
	}
	if (flags & BitstreamBytesWritten) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BitstreamBytesWritten";
	}
	if (flags & BitstreamHasOverrides) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BitstreamHasOverrides";
	}
	if (flags & AverageQuantization) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AverageQuantization";
	}
	if (flags & MinQuantization) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MinQuantization";
	}
	if (flags & MaxQuantization) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MaxQuantization";
	}
	if (flags & IntraPixels) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "IntraPixels";
	}
	if (flags & InterPixels) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InterPixels";
	}
	if (flags & SkippedPixels) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SkippedPixels";
	}
	if (flags & PicturePartitionCount) {
		if (!first) {
			ret += " | ";
		}
		ret += "PicturePartitionCount";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeFlagsKHR flags) -> std::string {
	using enum VideoEncodeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & WithQuantizationDeltaMap) {
		bytes += 27;
	}
	if (flags & WithEmphasisMap) {
		bytes += 18;
	}
	if (flags & IntraRefresh) {
		bytes += 15;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & WithQuantizationDeltaMap) {
		first = false;
		ret += "WithQuantizationDeltaMap";
	}
	if (flags & WithEmphasisMap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WithEmphasisMap";
	}
	if (flags & IntraRefresh) {
		if (!first) {
			ret += " | ";
		}
		ret += "IntraRefresh";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH264CapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeH264CapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH264CapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & HrdCompliance) {
		bytes += 16;
	}
	if (flags & PredictionWeightTableGenerated) {
		bytes += 33;
	}
	if (flags & RowUnalignedSlice) {
		bytes += 20;
	}
	if (flags & DifferentSliceType) {
		bytes += 21;
	}
	if (flags & BFrameInL0List) {
		bytes += 17;
	}
	if (flags & BFrameInL1List) {
		bytes += 17;
	}
	if (flags & PerPictureTypeMinMaxQp) {
		bytes += 25;
	}
	if (flags & PerSliceConstantQp) {
		bytes += 21;
	}
	if (flags & GeneratePrefixNalu) {
		bytes += 21;
	}
	if (flags & MbQpDiffWraparound) {
		bytes += 21;
	}
	if (flags & BPictureIntraRefresh) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & HrdCompliance) {
		first = false;
		ret += "HrdCompliance";
	}
	if (flags & PredictionWeightTableGenerated) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PredictionWeightTableGenerated";
	}
	if (flags & RowUnalignedSlice) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RowUnalignedSlice";
	}
	if (flags & DifferentSliceType) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DifferentSliceType";
	}
	if (flags & BFrameInL0List) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BFrameInL0List";
	}
	if (flags & BFrameInL1List) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BFrameInL1List";
	}
	if (flags & PerPictureTypeMinMaxQp) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerPictureTypeMinMaxQp";
	}
	if (flags & PerSliceConstantQp) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerSliceConstantQp";
	}
	if (flags & GeneratePrefixNalu) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "GeneratePrefixNalu";
	}
	if (flags & MbQpDiffWraparound) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MbQpDiffWraparound";
	}
	if (flags & BPictureIntraRefresh) {
		if (!first) {
			ret += " | ";
		}
		ret += "BPictureIntraRefresh";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH264RateControlFlagsKHR flags) -> std::string {
	using enum VideoEncodeH264RateControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH264RateControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & AttemptHrdCompliance) {
		bytes += 23;
	}
	if (flags & RegularGop) {
		bytes += 13;
	}
	if (flags & ReferencePatternFlat) {
		bytes += 23;
	}
	if (flags & ReferencePatternDyadic) {
		bytes += 25;
	}
	if (flags & TemporalLayerPatternDyadic) {
		bytes += 29;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & AttemptHrdCompliance) {
		first = false;
		ret += "AttemptHrdCompliance";
	}
	if (flags & RegularGop) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RegularGop";
	}
	if (flags & ReferencePatternFlat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReferencePatternFlat";
	}
	if (flags & ReferencePatternDyadic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReferencePatternDyadic";
	}
	if (flags & TemporalLayerPatternDyadic) {
		if (!first) {
			ret += " | ";
		}
		ret += "TemporalLayerPatternDyadic";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH264StdFlagsKHR flags) -> std::string {
	using enum VideoEncodeH264StdBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH264StdBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SeparateColorPlaneFlagSet) {
		bytes += 28;
	}
	if (flags & QpprimeYZeroTransformBypassFlagSet) {
		bytes += 37;
	}
	if (flags & ScalingMatrixPresentFlagSet) {
		bytes += 30;
	}
	if (flags & ChromaQpIndexOffset) {
		bytes += 22;
	}
	if (flags & SecondChromaQpIndexOffset) {
		bytes += 28;
	}
	if (flags & PicInitQpMinus26) {
		bytes += 19;
	}
	if (flags & WeightedPredFlagSet) {
		bytes += 22;
	}
	if (flags & WeightedBipredIdcExplicit) {
		bytes += 28;
	}
	if (flags & WeightedBipredIdcImplicit) {
		bytes += 28;
	}
	if (flags & Transform8x8ModeFlagSet) {
		bytes += 26;
	}
	if (flags & DirectSpatialMvPredFlagUnset) {
		bytes += 31;
	}
	if (flags & EntropyCodingModeFlagUnset) {
		bytes += 29;
	}
	if (flags & EntropyCodingModeFlagSet) {
		bytes += 27;
	}
	if (flags & Direct8x8InferenceFlagUnset) {
		bytes += 30;
	}
	if (flags & ConstrainedIntraPredFlagSet) {
		bytes += 30;
	}
	if (flags & DeblockingFilterDisabled) {
		bytes += 27;
	}
	if (flags & DeblockingFilterEnabled) {
		bytes += 26;
	}
	if (flags & DeblockingFilterPartial) {
		bytes += 26;
	}
	if (flags & SliceQpDelta) {
		bytes += 15;
	}
	if (flags & DifferentSliceQpDelta) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SeparateColorPlaneFlagSet) {
		first = false;
		ret += "SeparateColorPlaneFlagSet";
	}
	if (flags & QpprimeYZeroTransformBypassFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "QpprimeYZeroTransformBypassFlagSet";
	}
	if (flags & ScalingMatrixPresentFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ScalingMatrixPresentFlagSet";
	}
	if (flags & ChromaQpIndexOffset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ChromaQpIndexOffset";
	}
	if (flags & SecondChromaQpIndexOffset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SecondChromaQpIndexOffset";
	}
	if (flags & PicInitQpMinus26) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PicInitQpMinus26";
	}
	if (flags & WeightedPredFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WeightedPredFlagSet";
	}
	if (flags & WeightedBipredIdcExplicit) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WeightedBipredIdcExplicit";
	}
	if (flags & WeightedBipredIdcImplicit) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WeightedBipredIdcImplicit";
	}
	if (flags & Transform8x8ModeFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Transform8x8ModeFlagSet";
	}
	if (flags & DirectSpatialMvPredFlagUnset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DirectSpatialMvPredFlagUnset";
	}
	if (flags & EntropyCodingModeFlagUnset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EntropyCodingModeFlagUnset";
	}
	if (flags & EntropyCodingModeFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EntropyCodingModeFlagSet";
	}
	if (flags & Direct8x8InferenceFlagUnset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Direct8x8InferenceFlagUnset";
	}
	if (flags & ConstrainedIntraPredFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConstrainedIntraPredFlagSet";
	}
	if (flags & DeblockingFilterDisabled) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeblockingFilterDisabled";
	}
	if (flags & DeblockingFilterEnabled) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeblockingFilterEnabled";
	}
	if (flags & DeblockingFilterPartial) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeblockingFilterPartial";
	}
	if (flags & SliceQpDelta) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SliceQpDelta";
	}
	if (flags & DifferentSliceQpDelta) {
		if (!first) {
			ret += " | ";
		}
		ret += "DifferentSliceQpDelta";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH265CapabilityFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265CapabilityBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265CapabilityBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & HrdCompliance) {
		bytes += 16;
	}
	if (flags & PredictionWeightTableGenerated) {
		bytes += 33;
	}
	if (flags & RowUnalignedSliceSegment) {
		bytes += 27;
	}
	if (flags & DifferentSliceSegmentType) {
		bytes += 28;
	}
	if (flags & BFrameInL0List) {
		bytes += 17;
	}
	if (flags & BFrameInL1List) {
		bytes += 17;
	}
	if (flags & PerPictureTypeMinMaxQp) {
		bytes += 25;
	}
	if (flags & PerSliceSegmentConstantQp) {
		bytes += 28;
	}
	if (flags & MultipleTilesPerSliceSegment) {
		bytes += 31;
	}
	if (flags & MultipleSliceSegmentsPerTile) {
		bytes += 31;
	}
	if (flags & CuQpDiffWraparound) {
		bytes += 21;
	}
	if (flags & BPictureIntraRefresh) {
		bytes += 23;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & HrdCompliance) {
		first = false;
		ret += "HrdCompliance";
	}
	if (flags & PredictionWeightTableGenerated) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PredictionWeightTableGenerated";
	}
	if (flags & RowUnalignedSliceSegment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RowUnalignedSliceSegment";
	}
	if (flags & DifferentSliceSegmentType) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DifferentSliceSegmentType";
	}
	if (flags & BFrameInL0List) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BFrameInL0List";
	}
	if (flags & BFrameInL1List) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BFrameInL1List";
	}
	if (flags & PerPictureTypeMinMaxQp) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerPictureTypeMinMaxQp";
	}
	if (flags & PerSliceSegmentConstantQp) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerSliceSegmentConstantQp";
	}
	if (flags & MultipleTilesPerSliceSegment) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MultipleTilesPerSliceSegment";
	}
	if (flags & MultipleSliceSegmentsPerTile) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "MultipleSliceSegmentsPerTile";
	}
	if (flags & CuQpDiffWraparound) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "CuQpDiffWraparound";
	}
	if (flags & BPictureIntraRefresh) {
		if (!first) {
			ret += " | ";
		}
		ret += "BPictureIntraRefresh";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH265CtbSizeFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265CtbSizeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265CtbSizeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & v16) {
		bytes += 6;
	}
	if (flags & v32) {
		bytes += 6;
	}
	if (flags & v64) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & v16) {
		first = false;
		ret += "v16";
	}
	if (flags & v32) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v32";
	}
	if (flags & v64) {
		if (!first) {
			ret += " | ";
		}
		ret += "v64";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH265RateControlFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265RateControlBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265RateControlBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & AttemptHrdCompliance) {
		bytes += 23;
	}
	if (flags & RegularGop) {
		bytes += 13;
	}
	if (flags & ReferencePatternFlat) {
		bytes += 23;
	}
	if (flags & ReferencePatternDyadic) {
		bytes += 25;
	}
	if (flags & TemporalSubLayerPatternDyadic) {
		bytes += 32;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & AttemptHrdCompliance) {
		first = false;
		ret += "AttemptHrdCompliance";
	}
	if (flags & RegularGop) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "RegularGop";
	}
	if (flags & ReferencePatternFlat) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReferencePatternFlat";
	}
	if (flags & ReferencePatternDyadic) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ReferencePatternDyadic";
	}
	if (flags & TemporalSubLayerPatternDyadic) {
		if (!first) {
			ret += " | ";
		}
		ret += "TemporalSubLayerPatternDyadic";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH265StdFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265StdBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265StdBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & SeparateColorPlaneFlagSet) {
		bytes += 28;
	}
	if (flags & SampleAdaptiveOffsetEnabledFlagSet) {
		bytes += 37;
	}
	if (flags & ScalingListDataPresentFlagSet) {
		bytes += 32;
	}
	if (flags & PcmEnabledFlagSet) {
		bytes += 20;
	}
	if (flags & SpsTemporalMvpEnabledFlagSet) {
		bytes += 31;
	}
	if (flags & InitQpMinus26) {
		bytes += 16;
	}
	if (flags & WeightedPredFlagSet) {
		bytes += 22;
	}
	if (flags & WeightedBipredFlagSet) {
		bytes += 24;
	}
	if (flags & Log2ParallelMergeLevelMinus2) {
		bytes += 31;
	}
	if (flags & SignDataHidingEnabledFlagSet) {
		bytes += 31;
	}
	if (flags & TransformSkipEnabledFlagSet) {
		bytes += 30;
	}
	if (flags & TransformSkipEnabledFlagUnset) {
		bytes += 32;
	}
	if (flags & PpsSliceChromaQpOffsetsPresentFlagSet) {
		bytes += 40;
	}
	if (flags & TransquantBypassEnabledFlagSet) {
		bytes += 33;
	}
	if (flags & ConstrainedIntraPredFlagSet) {
		bytes += 30;
	}
	if (flags & EntropyCodingSyncEnabledFlagSet) {
		bytes += 34;
	}
	if (flags & DeblockingFilterOverrideEnabledFlagSet) {
		bytes += 41;
	}
	if (flags & DependentSliceSegmentsEnabledFlagSet) {
		bytes += 39;
	}
	if (flags & DependentSliceSegmentFlagSet) {
		bytes += 31;
	}
	if (flags & SliceQpDelta) {
		bytes += 15;
	}
	if (flags & DifferentSliceQpDelta) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & SeparateColorPlaneFlagSet) {
		first = false;
		ret += "SeparateColorPlaneFlagSet";
	}
	if (flags & SampleAdaptiveOffsetEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SampleAdaptiveOffsetEnabledFlagSet";
	}
	if (flags & ScalingListDataPresentFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ScalingListDataPresentFlagSet";
	}
	if (flags & PcmEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PcmEnabledFlagSet";
	}
	if (flags & SpsTemporalMvpEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SpsTemporalMvpEnabledFlagSet";
	}
	if (flags & InitQpMinus26) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InitQpMinus26";
	}
	if (flags & WeightedPredFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WeightedPredFlagSet";
	}
	if (flags & WeightedBipredFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "WeightedBipredFlagSet";
	}
	if (flags & Log2ParallelMergeLevelMinus2) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Log2ParallelMergeLevelMinus2";
	}
	if (flags & SignDataHidingEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SignDataHidingEnabledFlagSet";
	}
	if (flags & TransformSkipEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformSkipEnabledFlagSet";
	}
	if (flags & TransformSkipEnabledFlagUnset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransformSkipEnabledFlagUnset";
	}
	if (flags & PpsSliceChromaQpOffsetsPresentFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PpsSliceChromaQpOffsetsPresentFlagSet";
	}
	if (flags & TransquantBypassEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "TransquantBypassEnabledFlagSet";
	}
	if (flags & ConstrainedIntraPredFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "ConstrainedIntraPredFlagSet";
	}
	if (flags & EntropyCodingSyncEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "EntropyCodingSyncEnabledFlagSet";
	}
	if (flags & DeblockingFilterOverrideEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DeblockingFilterOverrideEnabledFlagSet";
	}
	if (flags & DependentSliceSegmentsEnabledFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DependentSliceSegmentsEnabledFlagSet";
	}
	if (flags & DependentSliceSegmentFlagSet) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "DependentSliceSegmentFlagSet";
	}
	if (flags & SliceQpDelta) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "SliceQpDelta";
	}
	if (flags & DifferentSliceQpDelta) {
		if (!first) {
			ret += " | ";
		}
		ret += "DifferentSliceQpDelta";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeH265TransformBlockSizeFlagsKHR flags) -> std::string {
	using enum VideoEncodeH265TransformBlockSizeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeH265TransformBlockSizeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & v4) {
		bytes += 5;
	}
	if (flags & v8) {
		bytes += 5;
	}
	if (flags & v16) {
		bytes += 6;
	}
	if (flags & v32) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & v4) {
		first = false;
		ret += "v4";
	}
	if (flags & v8) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v8";
	}
	if (flags & v16) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "v16";
	}
	if (flags & v32) {
		if (!first) {
			ret += " | ";
		}
		ret += "v32";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeIntraRefreshModeFlagsKHR flags) -> std::string {
	using enum VideoEncodeIntraRefreshModeBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeIntraRefreshModeBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & None) {
		bytes += 7;
	}
	if (flags & PerPicturePartition) {
		bytes += 22;
	}
	if (flags & BlockBased) {
		bytes += 13;
	}
	if (flags & BlockRowBased) {
		bytes += 16;
	}
	if (flags & BlockColumnBased) {
		bytes += 19;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & None) {
		first = false;
		ret += "None";
	}
	if (flags & PerPicturePartition) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "PerPicturePartition";
	}
	if (flags & BlockBased) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlockBased";
	}
	if (flags & BlockRowBased) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BlockRowBased";
	}
	if (flags & BlockColumnBased) {
		if (!first) {
			ret += " | ";
		}
		ret += "BlockColumnBased";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodePerPartitionFeedbackFlagsKHR flags) -> std::string {
	using enum VideoEncodePerPartitionFeedbackBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodePerPartitionFeedbackBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Status) {
		bytes += 9;
	}
	if (flags & BitstreamBufferOffset) {
		bytes += 24;
	}
	if (flags & BitstreamBytesWritten) {
		bytes += 24;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Status) {
		first = false;
		ret += "Status";
	}
	if (flags & BitstreamBufferOffset) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "BitstreamBufferOffset";
	}
	if (flags & BitstreamBytesWritten) {
		if (!first) {
			ret += " | ";
		}
		ret += "BitstreamBytesWritten";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & Default) {
		bytes += 10;
	}
	if (flags & Disabled) {
		bytes += 11;
	}
	if (flags & Cbr) {
		bytes += 6;
	}
	if (flags & Vbr) {
		bytes += 6;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Default) {
		first = false;
		ret += "Default";
	}
	if (flags & Disabled) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Disabled";
	}
	if (flags & Cbr) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Cbr";
	}
	if (flags & Vbr) {
		if (!first) {
			ret += " | ";
		}
		ret += "Vbr";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeRgbChromaOffsetFlagsVALVE flags) -> std::string {
	using enum VideoEncodeRgbChromaOffsetBitsVALVE;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeRgbChromaOffsetBitsVALVE does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & CositedEven) {
		bytes += 14;
	}
	if (flags & Midpoint) {
		bytes += 11;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & CositedEven) {
		first = false;
		ret += "CositedEven";
	}
	if (flags & Midpoint) {
		if (!first) {
			ret += " | ";
		}
		ret += "Midpoint";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeRgbModelConversionFlagsVALVE flags) -> std::string {
	using enum VideoEncodeRgbModelConversionBitsVALVE;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeRgbModelConversionBitsVALVE does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & RgbIdentity) {
		bytes += 14;
	}
	if (flags & YcbcrIdentity) {
		bytes += 16;
	}
	if (flags & Ycbcr709) {
		bytes += 11;
	}
	if (flags & Ycbcr601) {
		bytes += 11;
	}
	if (flags & Ycbcr2020) {
		bytes += 12;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & RgbIdentity) {
		first = false;
		ret += "RgbIdentity";
	}
	if (flags & YcbcrIdentity) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "YcbcrIdentity";
	}
	if (flags & Ycbcr709) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Ycbcr709";
	}
	if (flags & Ycbcr601) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Ycbcr601";
	}
	if (flags & Ycbcr2020) {
		if (!first) {
			ret += " | ";
		}
		ret += "Ycbcr2020";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeRgbRangeCompressionFlagsVALVE flags) -> std::string {
	using enum VideoEncodeRgbRangeCompressionBitsVALVE;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeRgbRangeCompressionBitsVALVE does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & FullRange) {
		bytes += 12;
	}
	if (flags & NarrowRange) {
		bytes += 14;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & FullRange) {
		first = false;
		ret += "FullRange";
	}
	if (flags & NarrowRange) {
		if (!first) {
			ret += " | ";
		}
		ret += "NarrowRange";
	}
	return ret;
}
template<> auto flagsToString(VideoEncodeUsageFlagsKHR flags) -> std::string {
	using enum VideoEncodeUsageBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoEncodeUsageBitsKHR does contain a bit that is not possible to be set";
	}
	size_t bytes = 0;
	if (flags & Default) {
		bytes += 10;
	}
	if (flags & Transcoding) {
		bytes += 14;
	}
	if (flags & Streaming) {
		bytes += 12;
	}
	if (flags & Recording) {
		bytes += 12;
	}
	if (flags & Conferencing) {
		bytes += 15;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & Default) {
		first = false;
		ret += "Default";
	}
	if (flags & Transcoding) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Transcoding";
	}
	if (flags & Streaming) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Streaming";
	}
	if (flags & Recording) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "Recording";
	}
	if (flags & Conferencing) {
		if (!first) {
			ret += " | ";
		}
		ret += "Conferencing";
	}
	return ret;
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
	size_t bytes = 0;
	if (flags & ProtectedContent) {
		bytes += 19;
	}
	if (flags & AllowEncodeParameterOptimizations) {
		bytes += 36;
	}
	if (flags & InlineQueries) {
		bytes += 16;
	}
	if (flags & AllowEncodeQuantizationDeltaMap) {
		bytes += 34;
	}
	if (flags & AllowEncodeEmphasisMap) {
		bytes += 25;
	}
	if (flags & InlineSessionParameters) {
		bytes += 26;
	}
	std::string ret;
	if (bytes == 0) {
		return "";
	}
	assert(bytes > 3);
	ret.reserve(bytes - 3);
	bool first = true;
	if (flags & ProtectedContent) {
		first = false;
		ret += "ProtectedContent";
	}
	if (flags & AllowEncodeParameterOptimizations) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowEncodeParameterOptimizations";
	}
	if (flags & InlineQueries) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "InlineQueries";
	}
	if (flags & AllowEncodeQuantizationDeltaMap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowEncodeQuantizationDeltaMap";
	}
	if (flags & AllowEncodeEmphasisMap) {
		if (!first) {
			ret += " | ";
		}
		else {
			first = false;
		}
		ret += "AllowEncodeEmphasisMap";
	}
	if (flags & InlineSessionParameters) {
		if (!first) {
			ret += " | ";
		}
		ret += "InlineSessionParameters";
	}
	return ret;
}
template<> auto flagsToString(VideoSessionParametersCreateFlagsKHR flags) -> std::string {
	using enum VideoSessionParametersCreateBitsKHR;
	if ((flags & AllBits) != flags) {
		return "VideoSessionParametersCreateBitsKHR does contain a bit that is not possible to be set";
	}
	if (flags & QuantizationMapCompatible) {
		return "QuantizationMapCompatible";
	}
	return "";
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
