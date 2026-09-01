#include "VkBindings/Bits.hpp"
#include "VkBindings/BitsToString.hpp"

#include <string_view>

namespace VkBindings::Reflections {
using namespace std::string_view_literals;
// NOLINTBEGIN(readability-function-size)
template<> auto bitToString(AccelerationStructureCreateBitsKHR bit) -> std::string_view {
	using enum AccelerationStructureCreateBitsKHR;
	switch (bit) {
	case DeviceAddressCaptureReplay: {
		return "DeviceAddressCaptureReplay"sv;
	}
	case MotionBitNV: {
		return "MotionBitNV"sv;
	}
	case DescriptorBufferCaptureReplayBitEXT: {
		return "DescriptorBufferCaptureReplayBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: AccelerationStructureCreateBitsKHR";
}
template<> auto bitToString(AccelerationStructureMotionInfoBitsNV bit) -> std::string_view {
	using enum AccelerationStructureMotionInfoBitsNV;
	switch (bit) {
	}
	return "bit not part of: AccelerationStructureMotionInfoBitsNV";
}
template<> auto bitToString(AccelerationStructureMotionInstanceBitsNV bit) -> std::string_view {
	using enum AccelerationStructureMotionInstanceBitsNV;
	switch (bit) {
	}
	return "bit not part of: AccelerationStructureMotionInstanceBitsNV";
}
template<> auto bitToString(AccessBits bit) -> std::string_view {
	using enum AccessBits;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case IndirectCommandRead: {
		return "IndirectCommandRead"sv;
	}
	case IndexRead: {
		return "IndexRead"sv;
	}
	case VertexAttributeRead: {
		return "VertexAttributeRead"sv;
	}
	case UniformRead: {
		return "UniformRead"sv;
	}
	case InputAttachmentRead: {
		return "InputAttachmentRead"sv;
	}
	case ShaderRead: {
		return "ShaderRead"sv;
	}
	case ShaderWrite: {
		return "ShaderWrite"sv;
	}
	case ColorAttachmentRead: {
		return "ColorAttachmentRead"sv;
	}
	case ColorAttachmentWrite: {
		return "ColorAttachmentWrite"sv;
	}
	case DepthStencilAttachmentRead: {
		return "DepthStencilAttachmentRead"sv;
	}
	case DepthStencilAttachmentWrite: {
		return "DepthStencilAttachmentWrite"sv;
	}
	case TransferRead: {
		return "TransferRead"sv;
	}
	case TransferWrite: {
		return "TransferWrite"sv;
	}
	case HostRead: {
		return "HostRead"sv;
	}
	case HostWrite: {
		return "HostWrite"sv;
	}
	case MemoryRead: {
		return "MemoryRead"sv;
	}
	case MemoryWrite: {
		return "MemoryWrite"sv;
	}
	case CommandPreprocessReadBitEXT: {
		return "CommandPreprocessReadBitEXT"sv;
	}
	case CommandPreprocessWriteBitEXT: {
		return "CommandPreprocessWriteBitEXT"sv;
	}
	case ColorAttachmentReadNoncoherentBitEXT: {
		return "ColorAttachmentReadNoncoherentBitEXT"sv;
	}
	case ConditionalRenderingReadBitEXT: {
		return "ConditionalRenderingReadBitEXT"sv;
	}
	case AccelerationStructureReadBitKHR: {
		return "AccelerationStructureReadBitKHR"sv;
	}
	case AccelerationStructureWriteBitKHR: {
		return "AccelerationStructureWriteBitKHR"sv;
	}
	case FragmentShadingRateAttachmentReadBitKHR: {
		return "FragmentShadingRateAttachmentReadBitKHR"sv;
	}
	case FragmentDensityMapReadBitEXT: {
		return "FragmentDensityMapReadBitEXT"sv;
	}
	case TransformFeedbackWriteBitEXT: {
		return "TransformFeedbackWriteBitEXT"sv;
	}
	case TransformFeedbackCounterReadBitEXT: {
		return "TransformFeedbackCounterReadBitEXT"sv;
	}
	case TransformFeedbackCounterWriteBitEXT: {
		return "TransformFeedbackCounterWriteBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: AccessBits";
}
template<> auto bitToString(AccessBits2 bit) -> std::string_view {
	using enum AccessBits2;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case IndirectCommandRead: {
		return "IndirectCommandRead"sv;
	}
	case IndexRead: {
		return "IndexRead"sv;
	}
	case VertexAttributeRead: {
		return "VertexAttributeRead"sv;
	}
	case UniformRead: {
		return "UniformRead"sv;
	}
	case InputAttachmentRead: {
		return "InputAttachmentRead"sv;
	}
	case ShaderRead: {
		return "ShaderRead"sv;
	}
	case ShaderWrite: {
		return "ShaderWrite"sv;
	}
	case ColorAttachmentRead: {
		return "ColorAttachmentRead"sv;
	}
	case ColorAttachmentWrite: {
		return "ColorAttachmentWrite"sv;
	}
	case DepthStencilAttachmentRead: {
		return "DepthStencilAttachmentRead"sv;
	}
	case DepthStencilAttachmentWrite: {
		return "DepthStencilAttachmentWrite"sv;
	}
	case TransferRead: {
		return "TransferRead"sv;
	}
	case TransferWrite: {
		return "TransferWrite"sv;
	}
	case HostRead: {
		return "HostRead"sv;
	}
	case HostWrite: {
		return "HostWrite"sv;
	}
	case MemoryRead: {
		return "MemoryRead"sv;
	}
	case MemoryWrite: {
		return "MemoryWrite"sv;
	}
	case CommandPreprocessReadBitEXT: {
		return "CommandPreprocessReadBitEXT"sv;
	}
	case CommandPreprocessWriteBitEXT: {
		return "CommandPreprocessWriteBitEXT"sv;
	}
	case ColorAttachmentReadNoncoherentBitEXT: {
		return "ColorAttachmentReadNoncoherentBitEXT"sv;
	}
	case ConditionalRenderingReadBitEXT: {
		return "ConditionalRenderingReadBitEXT"sv;
	}
	case AccelerationStructureReadBitKHR: {
		return "AccelerationStructureReadBitKHR"sv;
	}
	case AccelerationStructureWriteBitKHR: {
		return "AccelerationStructureWriteBitKHR"sv;
	}
	case FragmentShadingRateAttachmentReadBitKHR: {
		return "FragmentShadingRateAttachmentReadBitKHR"sv;
	}
	case FragmentDensityMapReadBitEXT: {
		return "FragmentDensityMapReadBitEXT"sv;
	}
	case TransformFeedbackWriteBitEXT: {
		return "TransformFeedbackWriteBitEXT"sv;
	}
	case TransformFeedbackCounterReadBitEXT: {
		return "TransformFeedbackCounterReadBitEXT"sv;
	}
	case TransformFeedbackCounterWriteBitEXT: {
		return "TransformFeedbackCounterWriteBitEXT"sv;
	}
	case ShaderSampledRead: {
		return "ShaderSampledRead"sv;
	}
	case ShaderStorageRead: {
		return "ShaderStorageRead"sv;
	}
	case ShaderStorageWrite: {
		return "ShaderStorageWrite"sv;
	}
	case VideoDecodeReadBitKHR: {
		return "VideoDecodeReadBitKHR"sv;
	}
	case VideoDecodeWriteBitKHR: {
		return "VideoDecodeWriteBitKHR"sv;
	}
	case VideoEncodeReadBitKHR: {
		return "VideoEncodeReadBitKHR"sv;
	}
	case VideoEncodeWriteBitKHR: {
		return "VideoEncodeWriteBitKHR"sv;
	}
	case InvocationMaskReadBitHUAWEI: {
		return "InvocationMaskReadBitHUAWEI"sv;
	}
	case ShaderBindingTableReadBitKHR: {
		return "ShaderBindingTableReadBitKHR"sv;
	}
	case DescriptorBufferReadBitEXT: {
		return "DescriptorBufferReadBitEXT"sv;
	}
	case OpticalFlowReadBitNV: {
		return "OpticalFlowReadBitNV"sv;
	}
	case OpticalFlowWriteBitNV: {
		return "OpticalFlowWriteBitNV"sv;
	}
	case MicromapReadBitEXT: {
		return "MicromapReadBitEXT"sv;
	}
	case MicromapWriteBitEXT: {
		return "MicromapWriteBitEXT"sv;
	}
	case DataGraphReadBitARM: {
		return "DataGraphReadBitARM"sv;
	}
	case DataGraphWriteBitARM: {
		return "DataGraphWriteBitARM"sv;
	}
	case ShaderTileAttachmentReadBitQCOM: {
		return "ShaderTileAttachmentReadBitQCOM"sv;
	}
	case ShaderTileAttachmentWriteBitQCOM: {
		return "ShaderTileAttachmentWriteBitQCOM"sv;
	}
	case MemoryDecompressionReadBitEXT: {
		return "MemoryDecompressionReadBitEXT"sv;
	}
	case MemoryDecompressionWriteBitEXT: {
		return "MemoryDecompressionWriteBitEXT"sv;
	}
	case SamplerHeapReadBitEXT: {
		return "SamplerHeapReadBitEXT"sv;
	}
	case ResourceHeapReadBitEXT: {
		return "ResourceHeapReadBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: AccessBits2";
}
template<> auto bitToString(AccessBits3KHR bit) -> std::string_view {
	using enum AccessBits3KHR;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	}
	return "bit not part of: AccessBits3KHR";
}
template<> auto bitToString(AcquireProfilingLockBitsKHR bit) -> std::string_view {
	using enum AcquireProfilingLockBitsKHR;
	switch (bit) {
	}
	return "bit not part of: AcquireProfilingLockBitsKHR";
}
template<> auto bitToString(AddressCommandBitsKHR bit) -> std::string_view {
	using enum AddressCommandBitsKHR;
	switch (bit) {
	case Protected: {
		return "Protected"sv;
	}
	case FullyBound: {
		return "FullyBound"sv;
	}
	case StorageBufferUsage: {
		return "StorageBufferUsage"sv;
	}
	case UnknownStorageBufferUsage: {
		return "UnknownStorageBufferUsage"sv;
	}
	case TransformFeedbackBufferUsage: {
		return "TransformFeedbackBufferUsage"sv;
	}
	case UnknownTransformFeedbackBufferUsage: {
		return "UnknownTransformFeedbackBufferUsage"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: AddressCommandBitsKHR";
}
template<> auto bitToString(AddressCopyBitsKHR bit) -> std::string_view {
	using enum AddressCopyBitsKHR;
	switch (bit) {
	case DeviceLocal: {
		return "DeviceLocal"sv;
	}
	case Sparse: {
		return "Sparse"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: AddressCopyBitsKHR";
}
template<> auto bitToString(AndroidSurfaceCreateBitsKHR bit) -> std::string_view {
	using enum AndroidSurfaceCreateBitsKHR;
	switch (bit) {
	}
	return "bit not part of: AndroidSurfaceCreateBitsKHR";
}
template<> auto bitToString(AttachmentDescriptionBits bit) -> std::string_view {
	using enum AttachmentDescriptionBits;
	switch (bit) {
	case MayAlias: {
		return "MayAlias"sv;
	}
	case ResolveSkipTransferFunctionBitKHR: {
		return "ResolveSkipTransferFunctionBitKHR"sv;
	}
	case ResolveEnableTransferFunctionBitKHR: {
		return "ResolveEnableTransferFunctionBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: AttachmentDescriptionBits";
}
template<> auto bitToString(BufferCreateBits bit) -> std::string_view {
	using enum BufferCreateBits;
	switch (bit) {
	case SparseBinding: {
		return "SparseBinding"sv;
	}
	case SparseResidency: {
		return "SparseResidency"sv;
	}
	case SparseAliased: {
		return "SparseAliased"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case DeviceAddressCaptureReplay: {
		return "DeviceAddressCaptureReplay"sv;
	}
	case DescriptorBufferCaptureReplayBitEXT: {
		return "DescriptorBufferCaptureReplayBitEXT"sv;
	}
	case VideoProfileIndependentBitKHR: {
		return "VideoProfileIndependentBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: BufferCreateBits";
}
template<> auto bitToString(BufferUsageBits bit) -> std::string_view {
	using enum BufferUsageBits;
	switch (bit) {
	case TransferSrc: {
		return "TransferSrc"sv;
	}
	case TransferDst: {
		return "TransferDst"sv;
	}
	case UniformTexelBuffer: {
		return "UniformTexelBuffer"sv;
	}
	case StorageTexelBuffer: {
		return "StorageTexelBuffer"sv;
	}
	case UniformBuffer: {
		return "UniformBuffer"sv;
	}
	case StorageBuffer: {
		return "StorageBuffer"sv;
	}
	case IndexBuffer: {
		return "IndexBuffer"sv;
	}
	case VertexBuffer: {
		return "VertexBuffer"sv;
	}
	case IndirectBuffer: {
		return "IndirectBuffer"sv;
	}
	case ConditionalRenderingBitEXT: {
		return "ConditionalRenderingBitEXT"sv;
	}
	case ShaderBindingTableBitKHR: {
		return "ShaderBindingTableBitKHR"sv;
	}
	case TransformFeedbackBufferBitEXT: {
		return "TransformFeedbackBufferBitEXT"sv;
	}
	case TransformFeedbackCounterBufferBitEXT: {
		return "TransformFeedbackCounterBufferBitEXT"sv;
	}
	case VideoDecodeSrcBitKHR: {
		return "VideoDecodeSrcBitKHR"sv;
	}
	case VideoDecodeDstBitKHR: {
		return "VideoDecodeDstBitKHR"sv;
	}
	case VideoEncodeDstBitKHR: {
		return "VideoEncodeDstBitKHR"sv;
	}
	case VideoEncodeSrcBitKHR: {
		return "VideoEncodeSrcBitKHR"sv;
	}
	case ShaderDeviceAddress: {
		return "ShaderDeviceAddress"sv;
	}
	case AccelerationStructureBuildInputReadOnlyBitKHR: {
		return "AccelerationStructureBuildInputReadOnlyBitKHR"sv;
	}
	case AccelerationStructureStorageBitKHR: {
		return "AccelerationStructureStorageBitKHR"sv;
	}
	case SamplerDescriptorBufferBitEXT: {
		return "SamplerDescriptorBufferBitEXT"sv;
	}
	case ResourceDescriptorBufferBitEXT: {
		return "ResourceDescriptorBufferBitEXT"sv;
	}
	case MicromapBuildInputReadOnlyBitEXT: {
		return "MicromapBuildInputReadOnlyBitEXT"sv;
	}
	case MicromapStorageBitEXT: {
		return "MicromapStorageBitEXT"sv;
	}
	case ExecutionGraphScratchBitAMDX: {
		return "ExecutionGraphScratchBitAMDX"sv;
	}
	case PushDescriptorsDescriptorBufferBitEXT: {
		return "PushDescriptorsDescriptorBufferBitEXT"sv;
	}
	case TileMemoryBitQCOM: {
		return "TileMemoryBitQCOM"sv;
	}
	case DescriptorHeapBitEXT: {
		return "DescriptorHeapBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: BufferUsageBits";
}
template<> auto bitToString(BufferUsageBits2 bit) -> std::string_view {
	using enum BufferUsageBits2;
	switch (bit) {
	case TransferSrc: {
		return "TransferSrc"sv;
	}
	case TransferDst: {
		return "TransferDst"sv;
	}
	case UniformTexelBuffer: {
		return "UniformTexelBuffer"sv;
	}
	case StorageTexelBuffer: {
		return "StorageTexelBuffer"sv;
	}
	case UniformBuffer: {
		return "UniformBuffer"sv;
	}
	case StorageBuffer: {
		return "StorageBuffer"sv;
	}
	case IndexBuffer: {
		return "IndexBuffer"sv;
	}
	case VertexBuffer: {
		return "VertexBuffer"sv;
	}
	case IndirectBuffer: {
		return "IndirectBuffer"sv;
	}
	case ConditionalRenderingBitEXT: {
		return "ConditionalRenderingBitEXT"sv;
	}
	case ShaderBindingTableBitKHR: {
		return "ShaderBindingTableBitKHR"sv;
	}
	case TransformFeedbackBufferBitEXT: {
		return "TransformFeedbackBufferBitEXT"sv;
	}
	case TransformFeedbackCounterBufferBitEXT: {
		return "TransformFeedbackCounterBufferBitEXT"sv;
	}
	case VideoDecodeSrcBitKHR: {
		return "VideoDecodeSrcBitKHR"sv;
	}
	case VideoDecodeDstBitKHR: {
		return "VideoDecodeDstBitKHR"sv;
	}
	case VideoEncodeDstBitKHR: {
		return "VideoEncodeDstBitKHR"sv;
	}
	case VideoEncodeSrcBitKHR: {
		return "VideoEncodeSrcBitKHR"sv;
	}
	case ShaderDeviceAddress: {
		return "ShaderDeviceAddress"sv;
	}
	case AccelerationStructureBuildInputReadOnlyBitKHR: {
		return "AccelerationStructureBuildInputReadOnlyBitKHR"sv;
	}
	case AccelerationStructureStorageBitKHR: {
		return "AccelerationStructureStorageBitKHR"sv;
	}
	case SamplerDescriptorBufferBitEXT: {
		return "SamplerDescriptorBufferBitEXT"sv;
	}
	case ResourceDescriptorBufferBitEXT: {
		return "ResourceDescriptorBufferBitEXT"sv;
	}
	case MicromapBuildInputReadOnlyBitEXT: {
		return "MicromapBuildInputReadOnlyBitEXT"sv;
	}
	case MicromapStorageBitEXT: {
		return "MicromapStorageBitEXT"sv;
	}
	case ExecutionGraphScratchBitAMDX: {
		return "ExecutionGraphScratchBitAMDX"sv;
	}
	case PushDescriptorsDescriptorBufferBitEXT: {
		return "PushDescriptorsDescriptorBufferBitEXT"sv;
	}
	case TileMemoryBitQCOM: {
		return "TileMemoryBitQCOM"sv;
	}
	case DescriptorHeapBitEXT: {
		return "DescriptorHeapBitEXT"sv;
	}
	case DataGraphForeignDescriptorBitARM: {
		return "DataGraphForeignDescriptorBitARM"sv;
	}
	case PreprocessBufferBitEXT: {
		return "PreprocessBufferBitEXT"sv;
	}
	case MemoryDecompressionBitEXT: {
		return "MemoryDecompressionBitEXT"sv;
	}
	case CompressedDataDgf1BitAMDX: {
		return "CompressedDataDgf1BitAMDX"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: BufferUsageBits2";
}
template<> auto bitToString(BufferViewCreateBits bit) -> std::string_view {
	using enum BufferViewCreateBits;
	switch (bit) {
	}
	return "bit not part of: BufferViewCreateBits";
}
template<> auto bitToString(BuildAccelerationStructureBitsKHR bit) -> std::string_view {
	using enum BuildAccelerationStructureBitsKHR;
	switch (bit) {
	case AllowUpdate: {
		return "AllowUpdate"sv;
	}
	case AllowCompaction: {
		return "AllowCompaction"sv;
	}
	case PreferFastTrace: {
		return "PreferFastTrace"sv;
	}
	case PreferFastBuild: {
		return "PreferFastBuild"sv;
	}
	case LowMemory: {
		return "LowMemory"sv;
	}
	case MotionBitNV: {
		return "MotionBitNV"sv;
	}
	case AllowOpacityMicromapUpdate: {
		return "AllowOpacityMicromapUpdate"sv;
	}
	case AllowDisableOpacityMicromaps: {
		return "AllowDisableOpacityMicromaps"sv;
	}
	case AllowOpacityMicromapDataUpdateBitEXT: {
		return "AllowOpacityMicromapDataUpdateBitEXT"sv;
	}
	case AllowDisplacementMicromapUpdateBitNV: {
		return "AllowDisplacementMicromapUpdateBitNV"sv;
	}
	case MicromapLossy: {
		return "MicromapLossy"sv;
	}
	case AllowDataAccess: {
		return "AllowDataAccess"sv;
	}
	case AllowClusterOpacityMicromapsBitNV: {
		return "AllowClusterOpacityMicromapsBitNV"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: BuildAccelerationStructureBitsKHR";
}
template<> auto bitToString(BuildMicromapBitsEXT bit) -> std::string_view {
	using enum BuildMicromapBitsEXT;
	switch (bit) {
	case PreferFastTrace: {
		return "PreferFastTrace"sv;
	}
	case PreferFastBuild: {
		return "PreferFastBuild"sv;
	}
	case AllowCompaction: {
		return "AllowCompaction"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: BuildMicromapBitsEXT";
}
template<> auto bitToString(ClusterAccelerationStructureAddressResolutionBitsNV bit) -> std::string_view {
	using enum ClusterAccelerationStructureAddressResolutionBitsNV;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case IndirectedDstImplicitData: {
		return "IndirectedDstImplicitData"sv;
	}
	case IndirectedScratchData: {
		return "IndirectedScratchData"sv;
	}
	case IndirectedDstAddressArray: {
		return "IndirectedDstAddressArray"sv;
	}
	case IndirectedDstSizesArray: {
		return "IndirectedDstSizesArray"sv;
	}
	case IndirectedSrcInfosArray: {
		return "IndirectedSrcInfosArray"sv;
	}
	case IndirectedSrcInfosCount: {
		return "IndirectedSrcInfosCount"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ClusterAccelerationStructureAddressResolutionBitsNV";
}
template<> auto bitToString(ClusterAccelerationStructureClusterBitsNV bit) -> std::string_view {
	using enum ClusterAccelerationStructureClusterBitsNV;
	switch (bit) {
	case AllowDisableOpacityMicromaps: {
		return "AllowDisableOpacityMicromaps"sv;
	}
	}
	return "bit not part of: ClusterAccelerationStructureClusterBitsNV";
}
template<> auto bitToString(ClusterAccelerationStructureGeometryBitsNV bit) -> std::string_view {
	using enum ClusterAccelerationStructureGeometryBitsNV;
	switch (bit) {
	case CullDisable: {
		return "CullDisable"sv;
	}
	case NoDuplicateAnyhitInvocation: {
		return "NoDuplicateAnyhitInvocation"sv;
	}
	case Opaque: {
		return "Opaque"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ClusterAccelerationStructureGeometryBitsNV";
}
template<> auto bitToString(ClusterAccelerationStructureIndexFormatBitsNV bit) -> std::string_view {
	using enum ClusterAccelerationStructureIndexFormatBitsNV;
	switch (bit) {
	case v8: {
		return "v8"sv;
	}
	case v16: {
		return "v16"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ClusterAccelerationStructureIndexFormatBitsNV";
}
template<> auto bitToString(ColorComponentBits bit) -> std::string_view {
	using enum ColorComponentBits;
	switch (bit) {
	case R: {
		return "R"sv;
	}
	case G: {
		return "G"sv;
	}
	case B: {
		return "B"sv;
	}
	case A: {
		return "A"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ColorComponentBits";
}
template<> auto bitToString(CommandBufferResetBits bit) -> std::string_view {
	using enum CommandBufferResetBits;
	switch (bit) {
	case ReleaseResources: {
		return "ReleaseResources"sv;
	}
	}
	return "bit not part of: CommandBufferResetBits";
}
template<> auto bitToString(CommandBufferUsageBits bit) -> std::string_view {
	using enum CommandBufferUsageBits;
	switch (bit) {
	case OneTimeSubmit: {
		return "OneTimeSubmit"sv;
	}
	case RenderPassContinue: {
		return "RenderPassContinue"sv;
	}
	case SimultaneousUse: {
		return "SimultaneousUse"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: CommandBufferUsageBits";
}
template<> auto bitToString(CommandPoolCreateBits bit) -> std::string_view {
	using enum CommandPoolCreateBits;
	switch (bit) {
	case Transient: {
		return "Transient"sv;
	}
	case ResetCommandBuffer: {
		return "ResetCommandBuffer"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: CommandPoolCreateBits";
}
template<> auto bitToString(CommandPoolResetBits bit) -> std::string_view {
	using enum CommandPoolResetBits;
	switch (bit) {
	case ReleaseResources: {
		return "ReleaseResources"sv;
	}
	}
	return "bit not part of: CommandPoolResetBits";
}
template<> auto bitToString(CommandPoolTrimBits bit) -> std::string_view {
	using enum CommandPoolTrimBits;
	switch (bit) {
	}
	return "bit not part of: CommandPoolTrimBits";
}
template<> auto bitToString(CompositeAlphaBitsKHR bit) -> std::string_view {
	using enum CompositeAlphaBitsKHR;
	switch (bit) {
	case Opaque: {
		return "Opaque"sv;
	}
	case PreMultiplied: {
		return "PreMultiplied"sv;
	}
	case PostMultiplied: {
		return "PostMultiplied"sv;
	}
	case Inherit: {
		return "Inherit"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: CompositeAlphaBitsKHR";
}
template<> auto bitToString(ConditionalRenderingBitsEXT bit) -> std::string_view {
	using enum ConditionalRenderingBitsEXT;
	switch (bit) {
	case Inverted: {
		return "Inverted"sv;
	}
	}
	return "bit not part of: ConditionalRenderingBitsEXT";
}
template<> auto bitToString(CooperativeMatrixBitsEXT bit) -> std::string_view {
	using enum CooperativeMatrixBitsEXT;
	switch (bit) {
	case SaturatingAccumulation: {
		return "SaturatingAccumulation"sv;
	}
	}
	return "bit not part of: CooperativeMatrixBitsEXT";
}
template<> auto bitToString(CullModeBits bit) -> std::string_view {
	using enum CullModeBits;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case Front: {
		return "Front"sv;
	}
	case Back: {
		return "Back"sv;
	}
	case FrontAndBack: {
		return "FrontAndBack"sv;
	}
	}
	return "bit not part of: CullModeBits";
}
template<> auto bitToString(DataGraphOpticalFlowCreateBitsARM bit) -> std::string_view {
	using enum DataGraphOpticalFlowCreateBitsARM;
	switch (bit) {
	case EnableHint: {
		return "EnableHint"sv;
	}
	case EnableCost: {
		return "EnableCost"sv;
	}
	case Reserved30: {
		return "Reserved30"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DataGraphOpticalFlowCreateBitsARM";
}
template<> auto bitToString(DataGraphOpticalFlowExecuteBitsARM bit) -> std::string_view {
	using enum DataGraphOpticalFlowExecuteBitsARM;
	switch (bit) {
	case DisableTemporalHints: {
		return "DisableTemporalHints"sv;
	}
	case InputUnchanged: {
		return "InputUnchanged"sv;
	}
	case ReferenceUnchanged: {
		return "ReferenceUnchanged"sv;
	}
	case InputIsPreviousReference: {
		return "InputIsPreviousReference"sv;
	}
	case ReferenceIsPreviousInput: {
		return "ReferenceIsPreviousInput"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DataGraphOpticalFlowExecuteBitsARM";
}
template<> auto bitToString(DataGraphOpticalFlowGridSizeBitsARM bit) -> std::string_view {
	using enum DataGraphOpticalFlowGridSizeBitsARM;
	switch (bit) {
	case Unknown: {
		return "Unknown"sv;
	}
	case v1x1: {
		return "v1x1"sv;
	}
	case v2x2: {
		return "v2x2"sv;
	}
	case v4x4: {
		return "v4x4"sv;
	}
	case v8x8: {
		return "v8x8"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DataGraphOpticalFlowGridSizeBitsARM";
}
template<> auto bitToString(DataGraphOpticalFlowImageUsageBitsARM bit) -> std::string_view {
	using enum DataGraphOpticalFlowImageUsageBitsARM;
	switch (bit) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Input: {
		return "Input"sv;
	}
	case Output: {
		return "Output"sv;
	}
	case Hint: {
		return "Hint"sv;
	}
	case Cost: {
		return "Cost"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DataGraphOpticalFlowImageUsageBitsARM";
}
template<> auto bitToString(DataGraphPipelineDispatchBitsARM bit) -> std::string_view {
	using enum DataGraphPipelineDispatchBitsARM;
	switch (bit) {
	}
	return "bit not part of: DataGraphPipelineDispatchBitsARM";
}
template<> auto bitToString(DataGraphPipelineSessionCreateBitsARM bit) -> std::string_view {
	using enum DataGraphPipelineSessionCreateBitsARM;
	switch (bit) {
	case Protected: {
		return "Protected"sv;
	}
	case OpticalFlowCache: {
		return "OpticalFlowCache"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DataGraphPipelineSessionCreateBitsARM";
}
template<> auto bitToString(DataGraphTOSAQualityBitsARM bit) -> std::string_view {
	using enum DataGraphTOSAQualityBitsARM;
	switch (bit) {
	case DataGraphTosaQualityAccelerated: {
		return "DataGraphTosaQualityAccelerated"sv;
	}
	case DataGraphTosaQualityConformant: {
		return "DataGraphTosaQualityConformant"sv;
	}
	case DataGraphTosaQualityExperimental: {
		return "DataGraphTosaQualityExperimental"sv;
	}
	case DataGraphTosaQualityDeprecated: {
		return "DataGraphTosaQualityDeprecated"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DataGraphTOSAQualityBitsARM";
}
template<> auto bitToString(DebugReportBitsEXT bit) -> std::string_view {
	using enum DebugReportBitsEXT;
	switch (bit) {
	case Information: {
		return "Information"sv;
	}
	case Warning: {
		return "Warning"sv;
	}
	case PerformanceWarning: {
		return "PerformanceWarning"sv;
	}
	case Error: {
		return "Error"sv;
	}
	case Debug: {
		return "Debug"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DebugReportBitsEXT";
}
template<> auto bitToString(DebugUtilsMessageSeverityBitsEXT bit) -> std::string_view {
	using enum DebugUtilsMessageSeverityBitsEXT;
	switch (bit) {
	case Verbose: {
		return "Verbose"sv;
	}
	case Info: {
		return "Info"sv;
	}
	case Warning: {
		return "Warning"sv;
	}
	case Error: {
		return "Error"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DebugUtilsMessageSeverityBitsEXT";
}
template<> auto bitToString(DebugUtilsMessageTypeBitsEXT bit) -> std::string_view {
	using enum DebugUtilsMessageTypeBitsEXT;
	switch (bit) {
	case General: {
		return "General"sv;
	}
	case Validation: {
		return "Validation"sv;
	}
	case Performance: {
		return "Performance"sv;
	}
	case DeviceAddressBinding: {
		return "DeviceAddressBinding"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DebugUtilsMessageTypeBitsEXT";
}
template<> auto bitToString(DebugUtilsMessengerCallbackDataBitsEXT bit) -> std::string_view {
	using enum DebugUtilsMessengerCallbackDataBitsEXT;
	switch (bit) {
	}
	return "bit not part of: DebugUtilsMessengerCallbackDataBitsEXT";
}
template<> auto bitToString(DebugUtilsMessengerCreateBitsEXT bit) -> std::string_view {
	using enum DebugUtilsMessengerCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: DebugUtilsMessengerCreateBitsEXT";
}
template<> auto bitToString(DependencyBits bit) -> std::string_view {
	using enum DependencyBits;
	switch (bit) {
	case ByRegion: {
		return "ByRegion"sv;
	}
	case ViewLocal: {
		return "ViewLocal"sv;
	}
	case DeviceGroup: {
		return "DeviceGroup"sv;
	}
	case FeedbackLoopBitEXT: {
		return "FeedbackLoopBitEXT"sv;
	}
	case QueueFamilyOwnershipTransferUseAllStagesBitKHR: {
		return "QueueFamilyOwnershipTransferUseAllStagesBitKHR"sv;
	}
	case AsymmetricEventBitKHR: {
		return "AsymmetricEventBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DependencyBits";
}
template<> auto bitToString(DescriptorBindingBits bit) -> std::string_view {
	using enum DescriptorBindingBits;
	switch (bit) {
	case UpdateAfterBind: {
		return "UpdateAfterBind"sv;
	}
	case UpdateUnusedWhilePending: {
		return "UpdateUnusedWhilePending"sv;
	}
	case PartiallyBound: {
		return "PartiallyBound"sv;
	}
	case VariableDescriptorCount: {
		return "VariableDescriptorCount"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DescriptorBindingBits";
}
template<> auto bitToString(DescriptorPoolCreateBits bit) -> std::string_view {
	using enum DescriptorPoolCreateBits;
	switch (bit) {
	case FreeDescriptorSet: {
		return "FreeDescriptorSet"sv;
	}
	case UpdateAfterBind: {
		return "UpdateAfterBind"sv;
	}
	case HostOnlyBitEXT: {
		return "HostOnlyBitEXT"sv;
	}
	case AllowOverallocationSetsBitNV: {
		return "AllowOverallocationSetsBitNV"sv;
	}
	case AllowOverallocationPoolsBitNV: {
		return "AllowOverallocationPoolsBitNV"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DescriptorPoolCreateBits";
}
template<> auto bitToString(DescriptorPoolResetBits bit) -> std::string_view {
	using enum DescriptorPoolResetBits;
	switch (bit) {
	}
	return "bit not part of: DescriptorPoolResetBits";
}
template<> auto bitToString(DescriptorSetLayoutCreateBits bit) -> std::string_view {
	using enum DescriptorSetLayoutCreateBits;
	switch (bit) {
	case PushDescriptor: {
		return "PushDescriptor"sv;
	}
	case UpdateAfterBindPool: {
		return "UpdateAfterBindPool"sv;
	}
	case HostOnlyPoolBitEXT: {
		return "HostOnlyPoolBitEXT"sv;
	}
	case DescriptorBufferBitEXT: {
		return "DescriptorBufferBitEXT"sv;
	}
	case EmbeddedImmutableSamplersBitEXT: {
		return "EmbeddedImmutableSamplersBitEXT"sv;
	}
	case PerStageBitNV: {
		return "PerStageBitNV"sv;
	}
	case IndirectBindableBitNV: {
		return "IndirectBindableBitNV"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DescriptorSetLayoutCreateBits";
}
template<> auto bitToString(DescriptorUpdateTemplateCreateBits bit) -> std::string_view {
	using enum DescriptorUpdateTemplateCreateBits;
	switch (bit) {
	}
	return "bit not part of: DescriptorUpdateTemplateCreateBits";
}
template<> auto bitToString(DeviceAddressBindingBitsEXT bit) -> std::string_view {
	using enum DeviceAddressBindingBitsEXT;
	switch (bit) {
	case InternalObject: {
		return "InternalObject"sv;
	}
	}
	return "bit not part of: DeviceAddressBindingBitsEXT";
}
template<> auto bitToString(DeviceCreateBits bit) -> std::string_view {
	using enum DeviceCreateBits;
	switch (bit) {
	}
	return "bit not part of: DeviceCreateBits";
}
template<> auto bitToString(DeviceDiagnosticsConfigBitsNV bit) -> std::string_view {
	using enum DeviceDiagnosticsConfigBitsNV;
	switch (bit) {
	case EnableShaderDebugInfo: {
		return "EnableShaderDebugInfo"sv;
	}
	case EnableResourceTracking: {
		return "EnableResourceTracking"sv;
	}
	case EnableAutomaticCheckpoints: {
		return "EnableAutomaticCheckpoints"sv;
	}
	case EnableShaderErrorReporting: {
		return "EnableShaderErrorReporting"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DeviceDiagnosticsConfigBitsNV";
}
template<> auto bitToString(DeviceFaultBitsKHR bit) -> std::string_view {
	using enum DeviceFaultBitsKHR;
	switch (bit) {
	case FlagDeviceLost: {
		return "FlagDeviceLost"sv;
	}
	case FlagMemoryAddress: {
		return "FlagMemoryAddress"sv;
	}
	case FlagInstructionAddress: {
		return "FlagInstructionAddress"sv;
	}
	case FlagVendor: {
		return "FlagVendor"sv;
	}
	case FlagWatchdogTimeout: {
		return "FlagWatchdogTimeout"sv;
	}
	case FlagOverflow: {
		return "FlagOverflow"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DeviceFaultBitsKHR";
}
template<> auto bitToString(DeviceGroupPresentModeBitsKHR bit) -> std::string_view {
	using enum DeviceGroupPresentModeBitsKHR;
	switch (bit) {
	case Local: {
		return "Local"sv;
	}
	case Remote: {
		return "Remote"sv;
	}
	case Sum: {
		return "Sum"sv;
	}
	case LocalMultiDevice: {
		return "LocalMultiDevice"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DeviceGroupPresentModeBitsKHR";
}
template<> auto bitToString(DeviceMemoryReportBitsEXT bit) -> std::string_view {
	using enum DeviceMemoryReportBitsEXT;
	switch (bit) {
	}
	return "bit not part of: DeviceMemoryReportBitsEXT";
}
template<> auto bitToString(DeviceQueueCreateBits bit) -> std::string_view {
	using enum DeviceQueueCreateBits;
	switch (bit) {
	case Protected: {
		return "Protected"sv;
	}
	case InternallySynchronizedBitKHR: {
		return "InternallySynchronizedBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DeviceQueueCreateBits";
}
template<> auto bitToString(DirectDriverLoadingBitsLUNARG bit) -> std::string_view {
	using enum DirectDriverLoadingBitsLUNARG;
	switch (bit) {
	}
	return "bit not part of: DirectDriverLoadingBitsLUNARG";
}
template<> auto bitToString(DirectFBSurfaceCreateBitsEXT bit) -> std::string_view {
	using enum DirectFBSurfaceCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: DirectFBSurfaceCreateBitsEXT";
}
template<> auto bitToString(DisplayModeCreateBitsKHR bit) -> std::string_view {
	using enum DisplayModeCreateBitsKHR;
	switch (bit) {
	}
	return "bit not part of: DisplayModeCreateBitsKHR";
}
template<> auto bitToString(DisplayPlaneAlphaBitsKHR bit) -> std::string_view {
	using enum DisplayPlaneAlphaBitsKHR;
	switch (bit) {
	case Opaque: {
		return "Opaque"sv;
	}
	case Global: {
		return "Global"sv;
	}
	case PerPixel: {
		return "PerPixel"sv;
	}
	case PerPixelPremultiplied: {
		return "PerPixelPremultiplied"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: DisplayPlaneAlphaBitsKHR";
}
template<> auto bitToString(DisplaySurfaceCreateBitsKHR bit) -> std::string_view {
	using enum DisplaySurfaceCreateBitsKHR;
	switch (bit) {
	}
	return "bit not part of: DisplaySurfaceCreateBitsKHR";
}
template<> auto bitToString(EventCreateBits bit) -> std::string_view {
	using enum EventCreateBits;
	switch (bit) {
	case DeviceOnly: {
		return "DeviceOnly"sv;
	}
	}
	return "bit not part of: EventCreateBits";
}
template<> auto bitToString(ExportMetalObjectTypeBitsEXT bit) -> std::string_view {
	using enum ExportMetalObjectTypeBitsEXT;
	switch (bit) {
	case MetalDevice: {
		return "MetalDevice"sv;
	}
	case MetalCommandQueue: {
		return "MetalCommandQueue"sv;
	}
	case MetalBuffer: {
		return "MetalBuffer"sv;
	}
	case MetalTexture: {
		return "MetalTexture"sv;
	}
	case MetalIosurface: {
		return "MetalIosurface"sv;
	}
	case MetalSharedEvent: {
		return "MetalSharedEvent"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExportMetalObjectTypeBitsEXT";
}
template<> auto bitToString(ExternalFenceFeatureBits bit) -> std::string_view {
	using enum ExternalFenceFeatureBits;
	switch (bit) {
	case Exportable: {
		return "Exportable"sv;
	}
	case Importable: {
		return "Importable"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalFenceFeatureBits";
}
template<> auto bitToString(ExternalFenceHandleTypeBits bit) -> std::string_view {
	using enum ExternalFenceHandleTypeBits;
	switch (bit) {
	case OpaqueFd: {
		return "OpaqueFd"sv;
	}
	case OpaqueWin32: {
		return "OpaqueWin32"sv;
	}
	case OpaqueWin32Kmt: {
		return "OpaqueWin32Kmt"sv;
	}
	case SyncFd: {
		return "SyncFd"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalFenceHandleTypeBits";
}
template<> auto bitToString(ExternalMemoryFeatureBits bit) -> std::string_view {
	using enum ExternalMemoryFeatureBits;
	switch (bit) {
	case DedicatedOnly: {
		return "DedicatedOnly"sv;
	}
	case Exportable: {
		return "Exportable"sv;
	}
	case Importable: {
		return "Importable"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalMemoryFeatureBits";
}
template<> auto bitToString(ExternalMemoryFeatureBitsNV bit) -> std::string_view {
	using enum ExternalMemoryFeatureBitsNV;
	switch (bit) {
	case DedicatedOnly: {
		return "DedicatedOnly"sv;
	}
	case Exportable: {
		return "Exportable"sv;
	}
	case Importable: {
		return "Importable"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalMemoryFeatureBitsNV";
}
template<> auto bitToString(ExternalMemoryHandleTypeBits bit) -> std::string_view {
	using enum ExternalMemoryHandleTypeBits;
	switch (bit) {
	case OpaqueFd: {
		return "OpaqueFd"sv;
	}
	case OpaqueWin32: {
		return "OpaqueWin32"sv;
	}
	case OpaqueWin32Kmt: {
		return "OpaqueWin32Kmt"sv;
	}
	case D3D11Texture: {
		return "D3D11Texture"sv;
	}
	case D3D11TextureKmt: {
		return "D3D11TextureKmt"sv;
	}
	case D3D12Heap: {
		return "D3D12Heap"sv;
	}
	case D3D12Resource: {
		return "D3D12Resource"sv;
	}
	case HostAllocationBitEXT: {
		return "HostAllocationBitEXT"sv;
	}
	case HostMappedForeignMemoryBitEXT: {
		return "HostMappedForeignMemoryBitEXT"sv;
	}
	case DmaBufBitEXT: {
		return "DmaBufBitEXT"sv;
	}
	case ANDROIDHardwareBufferBitANDROID: {
		return "ANDROIDHardwareBufferBitANDROID"sv;
	}
	case ZirconVmoBitFUCHSIA: {
		return "ZirconVmoBitFUCHSIA"sv;
	}
	case RdmaAddressBitNV: {
		return "RdmaAddressBitNV"sv;
	}
	case ScreenBufferBitQNX: {
		return "ScreenBufferBitQNX"sv;
	}
	case OhNativeBufferBitOHOS: {
		return "OhNativeBufferBitOHOS"sv;
	}
	case MtlbufferBitEXT: {
		return "MtlbufferBitEXT"sv;
	}
	case MtltextureBitEXT: {
		return "MtltextureBitEXT"sv;
	}
	case MtlheapBitEXT: {
		return "MtlheapBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalMemoryHandleTypeBits";
}
template<> auto bitToString(ExternalMemoryHandleTypeBitsNV bit) -> std::string_view {
	using enum ExternalMemoryHandleTypeBitsNV;
	switch (bit) {
	case OpaqueWin32: {
		return "OpaqueWin32"sv;
	}
	case OpaqueWin32Kmt: {
		return "OpaqueWin32Kmt"sv;
	}
	case D3D11Image: {
		return "D3D11Image"sv;
	}
	case D3D11ImageKmt: {
		return "D3D11ImageKmt"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalMemoryHandleTypeBitsNV";
}
template<> auto bitToString(ExternalSemaphoreFeatureBits bit) -> std::string_view {
	using enum ExternalSemaphoreFeatureBits;
	switch (bit) {
	case Exportable: {
		return "Exportable"sv;
	}
	case Importable: {
		return "Importable"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalSemaphoreFeatureBits";
}
template<> auto bitToString(ExternalSemaphoreHandleTypeBits bit) -> std::string_view {
	using enum ExternalSemaphoreHandleTypeBits;
	switch (bit) {
	case OpaqueFd: {
		return "OpaqueFd"sv;
	}
	case OpaqueWin32: {
		return "OpaqueWin32"sv;
	}
	case OpaqueWin32Kmt: {
		return "OpaqueWin32Kmt"sv;
	}
	case D3D12Fence: {
		return "D3D12Fence"sv;
	}
	case SyncFd: {
		return "SyncFd"sv;
	}
	case ZirconEventBitFUCHSIA: {
		return "ZirconEventBitFUCHSIA"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ExternalSemaphoreHandleTypeBits";
}
template<> auto bitToString(FenceCreateBits bit) -> std::string_view {
	using enum FenceCreateBits;
	switch (bit) {
	case Signaled: {
		return "Signaled"sv;
	}
	}
	return "bit not part of: FenceCreateBits";
}
template<> auto bitToString(FenceImportBits bit) -> std::string_view {
	using enum FenceImportBits;
	switch (bit) {
	case Temporary: {
		return "Temporary"sv;
	}
	}
	return "bit not part of: FenceImportBits";
}
template<> auto bitToString(FormatFeatureBits bit) -> std::string_view {
	using enum FormatFeatureBits;
	switch (bit) {
	case SampledImage: {
		return "SampledImage"sv;
	}
	case StorageImage: {
		return "StorageImage"sv;
	}
	case StorageImageAtomic: {
		return "StorageImageAtomic"sv;
	}
	case UniformTexelBuffer: {
		return "UniformTexelBuffer"sv;
	}
	case StorageTexelBuffer: {
		return "StorageTexelBuffer"sv;
	}
	case StorageTexelBufferAtomic: {
		return "StorageTexelBufferAtomic"sv;
	}
	case VertexBuffer: {
		return "VertexBuffer"sv;
	}
	case ColorAttachment: {
		return "ColorAttachment"sv;
	}
	case ColorAttachmentBlend: {
		return "ColorAttachmentBlend"sv;
	}
	case DepthStencilAttachment: {
		return "DepthStencilAttachment"sv;
	}
	case BlitSrc: {
		return "BlitSrc"sv;
	}
	case BlitDst: {
		return "BlitDst"sv;
	}
	case SampledImageFilterLinear: {
		return "SampledImageFilterLinear"sv;
	}
	case SampledImageFilterCubicBitEXT: {
		return "SampledImageFilterCubicBitEXT"sv;
	}
	case TransferSrc: {
		return "TransferSrc"sv;
	}
	case TransferDst: {
		return "TransferDst"sv;
	}
	case SampledImageFilterMinmax: {
		return "SampledImageFilterMinmax"sv;
	}
	case MidpointChromaSamples: {
		return "MidpointChromaSamples"sv;
	}
	case SampledImageYcbcrConversionLinearFilter: {
		return "SampledImageYcbcrConversionLinearFilter"sv;
	}
	case SampledImageYcbcrConversionSeparateReconstructionFilter: {
		return "SampledImageYcbcrConversionSeparateReconstructionFilter"sv;
	}
	case SampledImageYcbcrConversionChromaReconstructionExplicit: {
		return "SampledImageYcbcrConversionChromaReconstructionExplicit"sv;
	}
	case SampledImageYcbcrConversionChromaReconstructionExplicitForceable: {
		return "SampledImageYcbcrConversionChromaReconstructionExplicitForceable"sv;
	}
	case Disjoint: {
		return "Disjoint"sv;
	}
	case CositedChromaSamples: {
		return "CositedChromaSamples"sv;
	}
	case FragmentDensityMapBitEXT: {
		return "FragmentDensityMapBitEXT"sv;
	}
	case VideoDecodeOutputBitKHR: {
		return "VideoDecodeOutputBitKHR"sv;
	}
	case VideoDecodeDpbBitKHR: {
		return "VideoDecodeDpbBitKHR"sv;
	}
	case VideoEncodeInputBitKHR: {
		return "VideoEncodeInputBitKHR"sv;
	}
	case VideoEncodeDpbBitKHR: {
		return "VideoEncodeDpbBitKHR"sv;
	}
	case AccelerationStructureVertexBufferBitKHR: {
		return "AccelerationStructureVertexBufferBitKHR"sv;
	}
	case FragmentShadingRateAttachmentBitKHR: {
		return "FragmentShadingRateAttachmentBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: FormatFeatureBits";
}
template<> auto bitToString(FormatFeatureBits2 bit) -> std::string_view {
	using enum FormatFeatureBits2;
	switch (bit) {
	case SampledImage: {
		return "SampledImage"sv;
	}
	case StorageImage: {
		return "StorageImage"sv;
	}
	case StorageImageAtomic: {
		return "StorageImageAtomic"sv;
	}
	case UniformTexelBuffer: {
		return "UniformTexelBuffer"sv;
	}
	case StorageTexelBuffer: {
		return "StorageTexelBuffer"sv;
	}
	case StorageTexelBufferAtomic: {
		return "StorageTexelBufferAtomic"sv;
	}
	case VertexBuffer: {
		return "VertexBuffer"sv;
	}
	case ColorAttachment: {
		return "ColorAttachment"sv;
	}
	case ColorAttachmentBlend: {
		return "ColorAttachmentBlend"sv;
	}
	case DepthStencilAttachment: {
		return "DepthStencilAttachment"sv;
	}
	case BlitSrc: {
		return "BlitSrc"sv;
	}
	case BlitDst: {
		return "BlitDst"sv;
	}
	case SampledImageFilterLinear: {
		return "SampledImageFilterLinear"sv;
	}
	case SampledImageFilterCubic: {
		return "SampledImageFilterCubic"sv;
	}
	case TransferSrc: {
		return "TransferSrc"sv;
	}
	case TransferDst: {
		return "TransferDst"sv;
	}
	case SampledImageFilterMinmax: {
		return "SampledImageFilterMinmax"sv;
	}
	case MidpointChromaSamples: {
		return "MidpointChromaSamples"sv;
	}
	case SampledImageYcbcrConversionLinearFilter: {
		return "SampledImageYcbcrConversionLinearFilter"sv;
	}
	case SampledImageYcbcrConversionSeparateReconstructionFilter: {
		return "SampledImageYcbcrConversionSeparateReconstructionFilter"sv;
	}
	case SampledImageYcbcrConversionChromaReconstructionExplicit: {
		return "SampledImageYcbcrConversionChromaReconstructionExplicit"sv;
	}
	case SampledImageYcbcrConversionChromaReconstructionExplicitForceable: {
		return "SampledImageYcbcrConversionChromaReconstructionExplicitForceable"sv;
	}
	case Disjoint: {
		return "Disjoint"sv;
	}
	case CositedChromaSamples: {
		return "CositedChromaSamples"sv;
	}
	case FragmentDensityMapBitEXT: {
		return "FragmentDensityMapBitEXT"sv;
	}
	case VideoDecodeOutputBitKHR: {
		return "VideoDecodeOutputBitKHR"sv;
	}
	case VideoDecodeDpbBitKHR: {
		return "VideoDecodeDpbBitKHR"sv;
	}
	case VideoEncodeInputBitKHR: {
		return "VideoEncodeInputBitKHR"sv;
	}
	case VideoEncodeDpbBitKHR: {
		return "VideoEncodeDpbBitKHR"sv;
	}
	case AccelerationStructureVertexBufferBitKHR: {
		return "AccelerationStructureVertexBufferBitKHR"sv;
	}
	case FragmentShadingRateAttachmentBitKHR: {
		return "FragmentShadingRateAttachmentBitKHR"sv;
	}
	case StorageReadWithoutFormat: {
		return "StorageReadWithoutFormat"sv;
	}
	case StorageWriteWithoutFormat: {
		return "StorageWriteWithoutFormat"sv;
	}
	case SampledImageDepthComparison: {
		return "SampledImageDepthComparison"sv;
	}
	case WeightImageBitQCOM: {
		return "WeightImageBitQCOM"sv;
	}
	case WeightSampledImageBitQCOM: {
		return "WeightSampledImageBitQCOM"sv;
	}
	case BlockMatchingBitQCOM: {
		return "BlockMatchingBitQCOM"sv;
	}
	case BoxFilterSampledBitQCOM: {
		return "BoxFilterSampledBitQCOM"sv;
	}
	case LinearColorAttachmentBitNV: {
		return "LinearColorAttachmentBitNV"sv;
	}
	case TensorShaderBitARM: {
		return "TensorShaderBitARM"sv;
	}
	case OpticalFlowImageBitNV: {
		return "OpticalFlowImageBitNV"sv;
	}
	case OpticalFlowVectorBitNV: {
		return "OpticalFlowVectorBitNV"sv;
	}
	case OpticalFlowCostBitNV: {
		return "OpticalFlowCostBitNV"sv;
	}
	case TensorImageAliasingBitARM: {
		return "TensorImageAliasingBitARM"sv;
	}
	case BlockMatchingSxdBitQCOM: {
		return "BlockMatchingSxdBitQCOM"sv;
	}
	case SampledImageFilterLinear2DBitIMG: {
		return "SampledImageFilterLinear2DBitIMG"sv;
	}
	case HostImageTransfer: {
		return "HostImageTransfer"sv;
	}
	case TensorDataGraphBitARM: {
		return "TensorDataGraphBitARM"sv;
	}
	case VideoEncodeQuantizationDeltaMapBitKHR: {
		return "VideoEncodeQuantizationDeltaMapBitKHR"sv;
	}
	case VideoEncodeEmphasisMapBitKHR: {
		return "VideoEncodeEmphasisMapBitKHR"sv;
	}
	case AccelerationStructureRadiusBufferBitNV: {
		return "AccelerationStructureRadiusBufferBitNV"sv;
	}
	case DepthCopyOnComputeQueueBitKHR: {
		return "DepthCopyOnComputeQueueBitKHR"sv;
	}
	case DepthCopyOnTransferQueueBitKHR: {
		return "DepthCopyOnTransferQueueBitKHR"sv;
	}
	case StencilCopyOnComputeQueueBitKHR: {
		return "StencilCopyOnComputeQueueBitKHR"sv;
	}
	case StencilCopyOnTransferQueueBitKHR: {
		return "StencilCopyOnTransferQueueBitKHR"sv;
	}
	case DataGraphOpticalFlowImageBitARM: {
		return "DataGraphOpticalFlowImageBitARM"sv;
	}
	case DataGraphOpticalFlowVectorBitARM: {
		return "DataGraphOpticalFlowVectorBitARM"sv;
	}
	case DataGraphOpticalFlowCostBitARM: {
		return "DataGraphOpticalFlowCostBitARM"sv;
	}
	case CopyImageIndirectDstBitKHR: {
		return "CopyImageIndirectDstBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: FormatFeatureBits2";
}
template<> auto bitToString(FormatFeatureBits4KHR bit) -> std::string_view {
	using enum FormatFeatureBits4KHR;
	switch (bit) {
	}
	return "bit not part of: FormatFeatureBits4KHR";
}
template<> auto bitToString(FrameBoundaryBitsEXT bit) -> std::string_view {
	using enum FrameBoundaryBitsEXT;
	switch (bit) {
	case FrameEnd: {
		return "FrameEnd"sv;
	}
	}
	return "bit not part of: FrameBoundaryBitsEXT";
}
template<> auto bitToString(FramebufferCreateBits bit) -> std::string_view {
	using enum FramebufferCreateBits;
	switch (bit) {
	case Imageless: {
		return "Imageless"sv;
	}
	}
	return "bit not part of: FramebufferCreateBits";
}
template<> auto bitToString(GeometryBitsKHR bit) -> std::string_view {
	using enum GeometryBitsKHR;
	switch (bit) {
	case Opaque: {
		return "Opaque"sv;
	}
	case NoDuplicateAnyHitInvocation: {
		return "NoDuplicateAnyHitInvocation"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: GeometryBitsKHR";
}
template<> auto bitToString(GeometryInstanceBitsKHR bit) -> std::string_view {
	using enum GeometryInstanceBitsKHR;
	switch (bit) {
	case TriangleFacingCullDisable: {
		return "TriangleFacingCullDisable"sv;
	}
	case TriangleFlipFacing: {
		return "TriangleFlipFacing"sv;
	}
	case ForceOpaque: {
		return "ForceOpaque"sv;
	}
	case ForceNoOpaque: {
		return "ForceNoOpaque"sv;
	}
	case ForceOpacityMicromap2State: {
		return "ForceOpacityMicromap2State"sv;
	}
	case DisableOpacityMicromaps: {
		return "DisableOpacityMicromaps"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: GeometryInstanceBitsKHR";
}
template<> auto bitToString(GpaPerfBlockPropertiesBitsAMD bit) -> std::string_view {
	using enum GpaPerfBlockPropertiesBitsAMD;
	switch (bit) {
	}
	return "bit not part of: GpaPerfBlockPropertiesBitsAMD";
}
template<> auto bitToString(GpaSqShaderStageBitsAMD bit) -> std::string_view {
	using enum GpaSqShaderStageBitsAMD;
	switch (bit) {
	case Ps: {
		return "Ps"sv;
	}
	case Vs: {
		return "Vs"sv;
	}
	case Gs: {
		return "Gs"sv;
	}
	case Es: {
		return "Es"sv;
	}
	case Hs: {
		return "Hs"sv;
	}
	case Ls: {
		return "Ls"sv;
	}
	case Cs: {
		return "Cs"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: GpaSqShaderStageBitsAMD";
}
template<> auto bitToString(GraphicsPipelineLibraryBitsEXT bit) -> std::string_view {
	using enum GraphicsPipelineLibraryBitsEXT;
	switch (bit) {
	case VertexInputInterface: {
		return "VertexInputInterface"sv;
	}
	case PreRasterizationShaders: {
		return "PreRasterizationShaders"sv;
	}
	case FragmentShader: {
		return "FragmentShader"sv;
	}
	case FragmentOutputInterface: {
		return "FragmentOutputInterface"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: GraphicsPipelineLibraryBitsEXT";
}
template<> auto bitToString(HeadlessSurfaceCreateBitsEXT bit) -> std::string_view {
	using enum HeadlessSurfaceCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: HeadlessSurfaceCreateBitsEXT";
}
template<> auto bitToString(HostImageCopyBits bit) -> std::string_view {
	using enum HostImageCopyBits;
	switch (bit) {
	case Memcpy: {
		return "Memcpy"sv;
	}
	}
	return "bit not part of: HostImageCopyBits";
}
template<> auto bitToString(IOSSurfaceCreateBitsMVK bit) -> std::string_view {
	using enum IOSSurfaceCreateBitsMVK;
	switch (bit) {
	}
	return "bit not part of: IOSSurfaceCreateBitsMVK";
}
template<> auto bitToString(ImageAspectBits bit) -> std::string_view {
	using enum ImageAspectBits;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case Color: {
		return "Color"sv;
	}
	case Depth: {
		return "Depth"sv;
	}
	case Stencil: {
		return "Stencil"sv;
	}
	case Metadata: {
		return "Metadata"sv;
	}
	case Plane0: {
		return "Plane0"sv;
	}
	case Plane1: {
		return "Plane1"sv;
	}
	case Plane2: {
		return "Plane2"sv;
	}
	case MemoryPlane0BitEXT: {
		return "MemoryPlane0BitEXT"sv;
	}
	case MemoryPlane1BitEXT: {
		return "MemoryPlane1BitEXT"sv;
	}
	case MemoryPlane2BitEXT: {
		return "MemoryPlane2BitEXT"sv;
	}
	case MemoryPlane3BitEXT: {
		return "MemoryPlane3BitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageAspectBits";
}
template<> auto bitToString(ImageCompressionFixedRateBitsEXT bit) -> std::string_view {
	using enum ImageCompressionFixedRateBitsEXT;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case v1Bpc: {
		return "v1Bpc"sv;
	}
	case v2Bpc: {
		return "v2Bpc"sv;
	}
	case v3Bpc: {
		return "v3Bpc"sv;
	}
	case v4Bpc: {
		return "v4Bpc"sv;
	}
	case v5Bpc: {
		return "v5Bpc"sv;
	}
	case v6Bpc: {
		return "v6Bpc"sv;
	}
	case v7Bpc: {
		return "v7Bpc"sv;
	}
	case v8Bpc: {
		return "v8Bpc"sv;
	}
	case v9Bpc: {
		return "v9Bpc"sv;
	}
	case v10Bpc: {
		return "v10Bpc"sv;
	}
	case v11Bpc: {
		return "v11Bpc"sv;
	}
	case v12Bpc: {
		return "v12Bpc"sv;
	}
	case v13Bpc: {
		return "v13Bpc"sv;
	}
	case v14Bpc: {
		return "v14Bpc"sv;
	}
	case v15Bpc: {
		return "v15Bpc"sv;
	}
	case v16Bpc: {
		return "v16Bpc"sv;
	}
	case v17Bpc: {
		return "v17Bpc"sv;
	}
	case v18Bpc: {
		return "v18Bpc"sv;
	}
	case v19Bpc: {
		return "v19Bpc"sv;
	}
	case v20Bpc: {
		return "v20Bpc"sv;
	}
	case v21Bpc: {
		return "v21Bpc"sv;
	}
	case v22Bpc: {
		return "v22Bpc"sv;
	}
	case v23Bpc: {
		return "v23Bpc"sv;
	}
	case v24Bpc: {
		return "v24Bpc"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageCompressionFixedRateBitsEXT";
}
template<> auto bitToString(ImageCompressionBitsEXT bit) -> std::string_view {
	using enum ImageCompressionBitsEXT;
	switch (bit) {
	case Default: {
		return "Default"sv;
	}
	case FixedRateDefault: {
		return "FixedRateDefault"sv;
	}
	case FixedRateExplicit: {
		return "FixedRateExplicit"sv;
	}
	case Disabled: {
		return "Disabled"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageCompressionBitsEXT";
}
template<> auto bitToString(ImageConstraintsInfoBitsFUCHSIA bit) -> std::string_view {
	using enum ImageConstraintsInfoBitsFUCHSIA;
	switch (bit) {
	case CpuReadRarely: {
		return "CpuReadRarely"sv;
	}
	case CpuReadOften: {
		return "CpuReadOften"sv;
	}
	case CpuWriteRarely: {
		return "CpuWriteRarely"sv;
	}
	case CpuWriteOften: {
		return "CpuWriteOften"sv;
	}
	case ProtectedOptional: {
		return "ProtectedOptional"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageConstraintsInfoBitsFUCHSIA";
}
template<> auto bitToString(ImageCreateBits bit) -> std::string_view {
	using enum ImageCreateBits;
	switch (bit) {
	case SparseBinding: {
		return "SparseBinding"sv;
	}
	case SparseResidency: {
		return "SparseResidency"sv;
	}
	case SparseAliased: {
		return "SparseAliased"sv;
	}
	case MutableFormat: {
		return "MutableFormat"sv;
	}
	case CubeCompatible: {
		return "CubeCompatible"sv;
	}
	case v2DArrayCompatible: {
		return "v2DArrayCompatible"sv;
	}
	case SplitInstanceBindRegions: {
		return "SplitInstanceBindRegions"sv;
	}
	case BlockTexelViewCompatible: {
		return "BlockTexelViewCompatible"sv;
	}
	case ExtendedUsage: {
		return "ExtendedUsage"sv;
	}
	case Disjoint: {
		return "Disjoint"sv;
	}
	case Alias: {
		return "Alias"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case SampleLocationsCompatibleDepthBitEXT: {
		return "SampleLocationsCompatibleDepthBitEXT"sv;
	}
	case CornerSampledBitNV: {
		return "CornerSampledBitNV"sv;
	}
	case SubsampledBitEXT: {
		return "SubsampledBitEXT"sv;
	}
	case FragmentDensityMapOffsetBitEXT: {
		return "FragmentDensityMapOffsetBitEXT"sv;
	}
	case DescriptorHeapCaptureReplayBitEXT: {
		return "DescriptorHeapCaptureReplayBitEXT"sv;
	}
	case v2DViewCompatibleBitEXT: {
		return "v2DViewCompatibleBitEXT"sv;
	}
	case MultisampledRenderToSingleSampledBitEXT: {
		return "MultisampledRenderToSingleSampledBitEXT"sv;
	}
	case VideoProfileIndependentBitKHR: {
		return "VideoProfileIndependentBitKHR"sv;
	}
	case AliasSingleLayerDescriptorBitKHR: {
		return "AliasSingleLayerDescriptorBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageCreateBits";
}
template<> auto bitToString(ImageCreateBits2KHR bit) -> std::string_view {
	using enum ImageCreateBits2KHR;
	switch (bit) {
	case SparseBinding: {
		return "SparseBinding"sv;
	}
	case SparseResidency: {
		return "SparseResidency"sv;
	}
	case SparseAliased: {
		return "SparseAliased"sv;
	}
	case MutableFormat: {
		return "MutableFormat"sv;
	}
	case CubeCompatible: {
		return "CubeCompatible"sv;
	}
	case v2DArrayCompatible: {
		return "v2DArrayCompatible"sv;
	}
	case SplitInstanceBindRegions: {
		return "SplitInstanceBindRegions"sv;
	}
	case BlockTexelViewCompatible: {
		return "BlockTexelViewCompatible"sv;
	}
	case ExtendedUsage: {
		return "ExtendedUsage"sv;
	}
	case Disjoint: {
		return "Disjoint"sv;
	}
	case Alias: {
		return "Alias"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case SampleLocationsCompatibleDepthBitEXT: {
		return "SampleLocationsCompatibleDepthBitEXT"sv;
	}
	case CornerSampledBitNV: {
		return "CornerSampledBitNV"sv;
	}
	case SubsampledBitEXT: {
		return "SubsampledBitEXT"sv;
	}
	case FragmentDensityMapOffsetBitEXT: {
		return "FragmentDensityMapOffsetBitEXT"sv;
	}
	case DescriptorBufferCaptureReplayBitEXT: {
		return "DescriptorBufferCaptureReplayBitEXT"sv;
	}
	case v2DViewCompatibleBitEXT: {
		return "v2DViewCompatibleBitEXT"sv;
	}
	case MultisampledRenderToSingleSampledBitEXT: {
		return "MultisampledRenderToSingleSampledBitEXT"sv;
	}
	case VideoProfileIndependent: {
		return "VideoProfileIndependent"sv;
	}
	case AliasSingleLayerDescriptor: {
		return "AliasSingleLayerDescriptor"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageCreateBits2KHR";
}
template<> auto bitToString(ImageFormatConstraintsBitsFUCHSIA bit) -> std::string_view {
	using enum ImageFormatConstraintsBitsFUCHSIA;
	switch (bit) {
	}
	return "bit not part of: ImageFormatConstraintsBitsFUCHSIA";
}
template<> auto bitToString(ImagePipeSurfaceCreateBitsFUCHSIA bit) -> std::string_view {
	using enum ImagePipeSurfaceCreateBitsFUCHSIA;
	switch (bit) {
	}
	return "bit not part of: ImagePipeSurfaceCreateBitsFUCHSIA";
}
template<> auto bitToString(ImageUsageBits bit) -> std::string_view {
	using enum ImageUsageBits;
	switch (bit) {
	case TransferSrc: {
		return "TransferSrc"sv;
	}
	case TransferDst: {
		return "TransferDst"sv;
	}
	case Sampled: {
		return "Sampled"sv;
	}
	case Storage: {
		return "Storage"sv;
	}
	case ColorAttachment: {
		return "ColorAttachment"sv;
	}
	case DepthStencilAttachment: {
		return "DepthStencilAttachment"sv;
	}
	case TransientAttachment: {
		return "TransientAttachment"sv;
	}
	case InputAttachment: {
		return "InputAttachment"sv;
	}
	case FragmentShadingRateAttachmentBitKHR: {
		return "FragmentShadingRateAttachmentBitKHR"sv;
	}
	case FragmentDensityMapBitEXT: {
		return "FragmentDensityMapBitEXT"sv;
	}
	case VideoDecodeDstBitKHR: {
		return "VideoDecodeDstBitKHR"sv;
	}
	case VideoDecodeSrcBitKHR: {
		return "VideoDecodeSrcBitKHR"sv;
	}
	case VideoDecodeDpbBitKHR: {
		return "VideoDecodeDpbBitKHR"sv;
	}
	case VideoEncodeDstBitKHR: {
		return "VideoEncodeDstBitKHR"sv;
	}
	case VideoEncodeSrcBitKHR: {
		return "VideoEncodeSrcBitKHR"sv;
	}
	case VideoEncodeDpbBitKHR: {
		return "VideoEncodeDpbBitKHR"sv;
	}
	case InvocationMaskBitHUAWEI: {
		return "InvocationMaskBitHUAWEI"sv;
	}
	case AttachmentFeedbackLoopBitEXT: {
		return "AttachmentFeedbackLoopBitEXT"sv;
	}
	case SampleWeightBitQCOM: {
		return "SampleWeightBitQCOM"sv;
	}
	case SampleBlockMatchBitQCOM: {
		return "SampleBlockMatchBitQCOM"sv;
	}
	case HostTransfer: {
		return "HostTransfer"sv;
	}
	case TensorAliasingBitARM: {
		return "TensorAliasingBitARM"sv;
	}
	case VideoEncodeQuantizationDeltaMapBitKHR: {
		return "VideoEncodeQuantizationDeltaMapBitKHR"sv;
	}
	case VideoEncodeEmphasisMapBitKHR: {
		return "VideoEncodeEmphasisMapBitKHR"sv;
	}
	case TileMemoryBitQCOM: {
		return "TileMemoryBitQCOM"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageUsageBits";
}
template<> auto bitToString(ImageUsageBits2KHR bit) -> std::string_view {
	using enum ImageUsageBits2KHR;
	switch (bit) {
	case TransferSrc: {
		return "TransferSrc"sv;
	}
	case TransferDst: {
		return "TransferDst"sv;
	}
	case Sampled: {
		return "Sampled"sv;
	}
	case Storage: {
		return "Storage"sv;
	}
	case ColorAttachment: {
		return "ColorAttachment"sv;
	}
	case DepthStencilAttachment: {
		return "DepthStencilAttachment"sv;
	}
	case TransientAttachment: {
		return "TransientAttachment"sv;
	}
	case InputAttachment: {
		return "InputAttachment"sv;
	}
	case FragmentShadingRateAttachment: {
		return "FragmentShadingRateAttachment"sv;
	}
	case FragmentDensityMapBitEXT: {
		return "FragmentDensityMapBitEXT"sv;
	}
	case VideoDecodeDst: {
		return "VideoDecodeDst"sv;
	}
	case VideoDecodeSrc: {
		return "VideoDecodeSrc"sv;
	}
	case VideoDecodeDpb: {
		return "VideoDecodeDpb"sv;
	}
	case VideoEncodeDst: {
		return "VideoEncodeDst"sv;
	}
	case VideoEncodeSrc: {
		return "VideoEncodeSrc"sv;
	}
	case VideoEncodeDpb: {
		return "VideoEncodeDpb"sv;
	}
	case InvocationMaskBitHUAWEI: {
		return "InvocationMaskBitHUAWEI"sv;
	}
	case AttachmentFeedbackLoopBitEXT: {
		return "AttachmentFeedbackLoopBitEXT"sv;
	}
	case SampleWeightBitQCOM: {
		return "SampleWeightBitQCOM"sv;
	}
	case SampleBlockMatchBitQCOM: {
		return "SampleBlockMatchBitQCOM"sv;
	}
	case HostTransfer: {
		return "HostTransfer"sv;
	}
	case TensorAliasingBitARM: {
		return "TensorAliasingBitARM"sv;
	}
	case VideoEncodeQuantizationDeltaMap: {
		return "VideoEncodeQuantizationDeltaMap"sv;
	}
	case VideoEncodeEmphasisMap: {
		return "VideoEncodeEmphasisMap"sv;
	}
	case TileMemoryBitQCOM: {
		return "TileMemoryBitQCOM"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageUsageBits2KHR";
}
template<> auto bitToString(ImageViewCreateBits bit) -> std::string_view {
	using enum ImageViewCreateBits;
	switch (bit) {
	case FragmentDensityMapDynamicBitEXT: {
		return "FragmentDensityMapDynamicBitEXT"sv;
	}
	case FragmentDensityMapDeferredBitEXT: {
		return "FragmentDensityMapDeferredBitEXT"sv;
	}
	case DescriptorBufferCaptureReplayBitEXT: {
		return "DescriptorBufferCaptureReplayBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ImageViewCreateBits";
}
template<> auto bitToString(IndirectCommandsInputModeBitsEXT bit) -> std::string_view {
	using enum IndirectCommandsInputModeBitsEXT;
	switch (bit) {
	case VulkanIndexBuffer: {
		return "VulkanIndexBuffer"sv;
	}
	case DxgiIndexBuffer: {
		return "DxgiIndexBuffer"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: IndirectCommandsInputModeBitsEXT";
}
template<> auto bitToString(IndirectCommandsLayoutUsageBitsEXT bit) -> std::string_view {
	using enum IndirectCommandsLayoutUsageBitsEXT;
	switch (bit) {
	case ExplicitPreprocess: {
		return "ExplicitPreprocess"sv;
	}
	case UnorderedSequences: {
		return "UnorderedSequences"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: IndirectCommandsLayoutUsageBitsEXT";
}
template<> auto bitToString(IndirectCommandsLayoutUsageBitsNV bit) -> std::string_view {
	using enum IndirectCommandsLayoutUsageBitsNV;
	switch (bit) {
	case ExplicitPreprocess: {
		return "ExplicitPreprocess"sv;
	}
	case IndexedSequences: {
		return "IndexedSequences"sv;
	}
	case UnorderedSequences: {
		return "UnorderedSequences"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: IndirectCommandsLayoutUsageBitsNV";
}
template<> auto bitToString(IndirectStateBitsNV bit) -> std::string_view {
	using enum IndirectStateBitsNV;
	switch (bit) {
	case FlagFrontface: {
		return "FlagFrontface"sv;
	}
	}
	return "bit not part of: IndirectStateBitsNV";
}
template<> auto bitToString(InstanceCreateBits bit) -> std::string_view {
	using enum InstanceCreateBits;
	switch (bit) {
	case EnumeratePortabilityBitKHR: {
		return "EnumeratePortabilityBitKHR"sv;
	}
	}
	return "bit not part of: InstanceCreateBits";
}
template<> auto bitToString(MacOSSurfaceCreateBitsMVK bit) -> std::string_view {
	using enum MacOSSurfaceCreateBitsMVK;
	switch (bit) {
	}
	return "bit not part of: MacOSSurfaceCreateBitsMVK";
}
template<> auto bitToString(MemoryAllocateBits bit) -> std::string_view {
	using enum MemoryAllocateBits;
	switch (bit) {
	case DeviceMask: {
		return "DeviceMask"sv;
	}
	case DeviceAddress: {
		return "DeviceAddress"sv;
	}
	case DeviceAddressCaptureReplay: {
		return "DeviceAddressCaptureReplay"sv;
	}
	case ZeroInitializeBitEXT: {
		return "ZeroInitializeBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: MemoryAllocateBits";
}
template<> auto bitToString(MemoryDecompressionMethodBitsEXT bit) -> std::string_view {
	using enum MemoryDecompressionMethodBitsEXT;
	switch (bit) {
	case Gdeflate10: {
		return "Gdeflate10"sv;
	}
	}
	return "bit not part of: MemoryDecompressionMethodBitsEXT";
}
template<> auto bitToString(MemoryHeapBits bit) -> std::string_view {
	using enum MemoryHeapBits;
	switch (bit) {
	case DeviceLocal: {
		return "DeviceLocal"sv;
	}
	case MultiInstance: {
		return "MultiInstance"sv;
	}
	case TileMemoryBitQCOM: {
		return "TileMemoryBitQCOM"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: MemoryHeapBits";
}
template<> auto bitToString(MemoryMapBits bit) -> std::string_view {
	using enum MemoryMapBits;
	switch (bit) {
	case PlacedBitEXT: {
		return "PlacedBitEXT"sv;
	}
	}
	return "bit not part of: MemoryMapBits";
}
template<> auto bitToString(MemoryPropertyBits bit) -> std::string_view {
	using enum MemoryPropertyBits;
	switch (bit) {
	case DeviceLocal: {
		return "DeviceLocal"sv;
	}
	case HostVisible: {
		return "HostVisible"sv;
	}
	case HostCoherent: {
		return "HostCoherent"sv;
	}
	case HostCached: {
		return "HostCached"sv;
	}
	case LazilyAllocated: {
		return "LazilyAllocated"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case DeviceCoherentBitAMD: {
		return "DeviceCoherentBitAMD"sv;
	}
	case DeviceUncachedBitAMD: {
		return "DeviceUncachedBitAMD"sv;
	}
	case RdmaCapableBitNV: {
		return "RdmaCapableBitNV"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: MemoryPropertyBits";
}
template<> auto bitToString(MemoryUnmapBits bit) -> std::string_view {
	using enum MemoryUnmapBits;
	switch (bit) {
	case ReserveBitEXT: {
		return "ReserveBitEXT"sv;
	}
	}
	return "bit not part of: MemoryUnmapBits";
}
template<> auto bitToString(MetalSurfaceCreateBitsEXT bit) -> std::string_view {
	using enum MetalSurfaceCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: MetalSurfaceCreateBitsEXT";
}
template<> auto bitToString(MicromapCreateBitsEXT bit) -> std::string_view {
	using enum MicromapCreateBitsEXT;
	switch (bit) {
	case DeviceAddressCaptureReplay: {
		return "DeviceAddressCaptureReplay"sv;
	}
	}
	return "bit not part of: MicromapCreateBitsEXT";
}
template<> auto bitToString(OpticalFlowExecuteBitsNV bit) -> std::string_view {
	using enum OpticalFlowExecuteBitsNV;
	switch (bit) {
	case DisableTemporalHints: {
		return "DisableTemporalHints"sv;
	}
	}
	return "bit not part of: OpticalFlowExecuteBitsNV";
}
template<> auto bitToString(OpticalFlowGridSizeBitsNV bit) -> std::string_view {
	using enum OpticalFlowGridSizeBitsNV;
	switch (bit) {
	case Unknown: {
		return "Unknown"sv;
	}
	case v1x1: {
		return "v1x1"sv;
	}
	case v2x2: {
		return "v2x2"sv;
	}
	case v4x4: {
		return "v4x4"sv;
	}
	case v8x8: {
		return "v8x8"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: OpticalFlowGridSizeBitsNV";
}
template<> auto bitToString(OpticalFlowSessionCreateBitsNV bit) -> std::string_view {
	using enum OpticalFlowSessionCreateBitsNV;
	switch (bit) {
	case EnableHint: {
		return "EnableHint"sv;
	}
	case EnableCost: {
		return "EnableCost"sv;
	}
	case EnableGlobalFlow: {
		return "EnableGlobalFlow"sv;
	}
	case AllowRegions: {
		return "AllowRegions"sv;
	}
	case BothDirections: {
		return "BothDirections"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: OpticalFlowSessionCreateBitsNV";
}
template<> auto bitToString(OpticalFlowUsageBitsNV bit) -> std::string_view {
	using enum OpticalFlowUsageBitsNV;
	switch (bit) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Input: {
		return "Input"sv;
	}
	case Output: {
		return "Output"sv;
	}
	case Hint: {
		return "Hint"sv;
	}
	case Cost: {
		return "Cost"sv;
	}
	case GlobalFlow: {
		return "GlobalFlow"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: OpticalFlowUsageBitsNV";
}
template<> auto bitToString(PartitionedAccelerationStructureInstanceBitsNV bit) -> std::string_view {
	using enum PartitionedAccelerationStructureInstanceBitsNV;
	switch (bit) {
	case FlagTriangleFacingCullDisable: {
		return "FlagTriangleFacingCullDisable"sv;
	}
	case FlagTriangleFlipFacing: {
		return "FlagTriangleFlipFacing"sv;
	}
	case FlagForceOpaque: {
		return "FlagForceOpaque"sv;
	}
	case FlagForceNoOpaque: {
		return "FlagForceNoOpaque"sv;
	}
	case FlagEnableExplicitBoundingBox: {
		return "FlagEnableExplicitBoundingBox"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PartitionedAccelerationStructureInstanceBitsNV";
}
template<> auto bitToString(PastPresentationTimingBitsEXT bit) -> std::string_view {
	using enum PastPresentationTimingBitsEXT;
	switch (bit) {
	case AllowPartialResults: {
		return "AllowPartialResults"sv;
	}
	case AllowOutOfOrderResults: {
		return "AllowOutOfOrderResults"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PastPresentationTimingBitsEXT";
}
template<> auto bitToString(PeerMemoryFeatureBits bit) -> std::string_view {
	using enum PeerMemoryFeatureBits;
	switch (bit) {
	case CopySrc: {
		return "CopySrc"sv;
	}
	case CopyDst: {
		return "CopyDst"sv;
	}
	case GenericSrc: {
		return "GenericSrc"sv;
	}
	case GenericDst: {
		return "GenericDst"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PeerMemoryFeatureBits";
}
template<> auto bitToString(PerformanceCounterDescriptionBitsARM bit) -> std::string_view {
	using enum PerformanceCounterDescriptionBitsARM;
	switch (bit) {
	}
	return "bit not part of: PerformanceCounterDescriptionBitsARM";
}
template<> auto bitToString(PerformanceCounterDescriptionBitsKHR bit) -> std::string_view {
	using enum PerformanceCounterDescriptionBitsKHR;
	switch (bit) {
	case PerformanceImpacting: {
		return "PerformanceImpacting"sv;
	}
	case ConcurrentlyImpacted: {
		return "ConcurrentlyImpacted"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PerformanceCounterDescriptionBitsKHR";
}
template<> auto bitToString(PhysicalDeviceGpaPropertiesBitsAMD bit) -> std::string_view {
	using enum PhysicalDeviceGpaPropertiesBitsAMD;
	switch (bit) {
	}
	return "bit not part of: PhysicalDeviceGpaPropertiesBitsAMD";
}
template<> auto bitToString(PhysicalDeviceSchedulingControlsBitsARM bit) -> std::string_view {
	using enum PhysicalDeviceSchedulingControlsBitsARM;
	switch (bit) {
	case ShaderCoreCount: {
		return "ShaderCoreCount"sv;
	}
	case DispatchParameters: {
		return "DispatchParameters"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PhysicalDeviceSchedulingControlsBitsARM";
}
template<> auto bitToString(PipelineCacheCreateBits bit) -> std::string_view {
	using enum PipelineCacheCreateBits;
	switch (bit) {
	case ExternallySynchronized: {
		return "ExternallySynchronized"sv;
	}
	case InternallySynchronizedMergeBitKHR: {
		return "InternallySynchronizedMergeBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineCacheCreateBits";
}
template<> auto bitToString(PipelineColorBlendStateCreateBits bit) -> std::string_view {
	using enum PipelineColorBlendStateCreateBits;
	switch (bit) {
	case RasterizationOrderAttachmentAccessBitEXT: {
		return "RasterizationOrderAttachmentAccessBitEXT"sv;
	}
	}
	return "bit not part of: PipelineColorBlendStateCreateBits";
}
template<> auto bitToString(PipelineCompilerControlBitsAMD bit) -> std::string_view {
	using enum PipelineCompilerControlBitsAMD;
	switch (bit) {
	}
	return "bit not part of: PipelineCompilerControlBitsAMD";
}
template<> auto bitToString(PipelineCoverageModulationStateCreateBitsNV bit) -> std::string_view {
	using enum PipelineCoverageModulationStateCreateBitsNV;
	switch (bit) {
	}
	return "bit not part of: PipelineCoverageModulationStateCreateBitsNV";
}
template<> auto bitToString(PipelineCoverageReductionStateCreateBitsNV bit) -> std::string_view {
	using enum PipelineCoverageReductionStateCreateBitsNV;
	switch (bit) {
	}
	return "bit not part of: PipelineCoverageReductionStateCreateBitsNV";
}
template<> auto bitToString(PipelineCoverageToColorStateCreateBitsNV bit) -> std::string_view {
	using enum PipelineCoverageToColorStateCreateBitsNV;
	switch (bit) {
	}
	return "bit not part of: PipelineCoverageToColorStateCreateBitsNV";
}
template<> auto bitToString(PipelineCreateBits bit) -> std::string_view {
	using enum PipelineCreateBits;
	switch (bit) {
	case DisableOptimization: {
		return "DisableOptimization"sv;
	}
	case AllowDerivatives: {
		return "AllowDerivatives"sv;
	}
	case Derivative: {
		return "Derivative"sv;
	}
	case ViewIndexFromDeviceIndex: {
		return "ViewIndexFromDeviceIndex"sv;
	}
	case DispatchBase: {
		return "DispatchBase"sv;
	}
	case DeferCompileBitNV: {
		return "DeferCompileBitNV"sv;
	}
	case CaptureStatisticsBitKHR: {
		return "CaptureStatisticsBitKHR"sv;
	}
	case CaptureInternalRepresentationsBitKHR: {
		return "CaptureInternalRepresentationsBitKHR"sv;
	}
	case FailOnPipelineCompileRequired: {
		return "FailOnPipelineCompileRequired"sv;
	}
	case EarlyReturnOnFailure: {
		return "EarlyReturnOnFailure"sv;
	}
	case LinkTimeOptimizationBitEXT: {
		return "LinkTimeOptimizationBitEXT"sv;
	}
	case LibraryBitKHR: {
		return "LibraryBitKHR"sv;
	}
	case RayTracingSkipTrianglesBitKHR: {
		return "RayTracingSkipTrianglesBitKHR"sv;
	}
	case RayTracingSkipAabbsBitKHR: {
		return "RayTracingSkipAabbsBitKHR"sv;
	}
	case RayTracingNoNullAnyHitShadersBitKHR: {
		return "RayTracingNoNullAnyHitShadersBitKHR"sv;
	}
	case RayTracingNoNullClosestHitShadersBitKHR: {
		return "RayTracingNoNullClosestHitShadersBitKHR"sv;
	}
	case RayTracingNoNullMissShadersBitKHR: {
		return "RayTracingNoNullMissShadersBitKHR"sv;
	}
	case RayTracingNoNullIntersectionShadersBitKHR: {
		return "RayTracingNoNullIntersectionShadersBitKHR"sv;
	}
	case IndirectBindableBitNV: {
		return "IndirectBindableBitNV"sv;
	}
	case RayTracingShaderGroupHandleCaptureReplayBitKHR: {
		return "RayTracingShaderGroupHandleCaptureReplayBitKHR"sv;
	}
	case RayTracingAllowMotionBitNV: {
		return "RayTracingAllowMotionBitNV"sv;
	}
	case RenderingFragmentShadingRateAttachmentBitKHR: {
		return "RenderingFragmentShadingRateAttachmentBitKHR"sv;
	}
	case RenderingFragmentDensityMapAttachmentBitEXT: {
		return "RenderingFragmentDensityMapAttachmentBitEXT"sv;
	}
	case RetainLinkTimeOptimizationInfoBitEXT: {
		return "RetainLinkTimeOptimizationInfoBitEXT"sv;
	}
	case RayTracingOpacityMicromapBitKHR: {
		return "RayTracingOpacityMicromapBitKHR"sv;
	}
	case ColorAttachmentFeedbackLoopBitEXT: {
		return "ColorAttachmentFeedbackLoopBitEXT"sv;
	}
	case DepthStencilAttachmentFeedbackLoopBitEXT: {
		return "DepthStencilAttachmentFeedbackLoopBitEXT"sv;
	}
	case NoProtectedAccess: {
		return "NoProtectedAccess"sv;
	}
	case RayTracingDisplacementMicromapBitNV: {
		return "RayTracingDisplacementMicromapBitNV"sv;
	}
	case DescriptorBufferBitEXT: {
		return "DescriptorBufferBitEXT"sv;
	}
	case ProtectedAccessOnly: {
		return "ProtectedAccessOnly"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineCreateBits";
}
template<> auto bitToString(PipelineCreateBits2 bit) -> std::string_view {
	using enum PipelineCreateBits2;
	switch (bit) {
	case DisableOptimization: {
		return "DisableOptimization"sv;
	}
	case AllowDerivatives: {
		return "AllowDerivatives"sv;
	}
	case Derivative: {
		return "Derivative"sv;
	}
	case ViewIndexFromDeviceIndex: {
		return "ViewIndexFromDeviceIndex"sv;
	}
	case DispatchBase: {
		return "DispatchBase"sv;
	}
	case DeferCompileBitNV: {
		return "DeferCompileBitNV"sv;
	}
	case CaptureStatisticsBitKHR: {
		return "CaptureStatisticsBitKHR"sv;
	}
	case CaptureInternalRepresentationsBitKHR: {
		return "CaptureInternalRepresentationsBitKHR"sv;
	}
	case FailOnPipelineCompileRequired: {
		return "FailOnPipelineCompileRequired"sv;
	}
	case EarlyReturnOnFailure: {
		return "EarlyReturnOnFailure"sv;
	}
	case LinkTimeOptimizationBitEXT: {
		return "LinkTimeOptimizationBitEXT"sv;
	}
	case LibraryBitKHR: {
		return "LibraryBitKHR"sv;
	}
	case RayTracingSkipTrianglesBitKHR: {
		return "RayTracingSkipTrianglesBitKHR"sv;
	}
	case RayTracingSkipAabbsBitKHR: {
		return "RayTracingSkipAabbsBitKHR"sv;
	}
	case RayTracingNoNullAnyHitShadersBitKHR: {
		return "RayTracingNoNullAnyHitShadersBitKHR"sv;
	}
	case RayTracingNoNullClosestHitShadersBitKHR: {
		return "RayTracingNoNullClosestHitShadersBitKHR"sv;
	}
	case RayTracingNoNullMissShadersBitKHR: {
		return "RayTracingNoNullMissShadersBitKHR"sv;
	}
	case RayTracingNoNullIntersectionShadersBitKHR: {
		return "RayTracingNoNullIntersectionShadersBitKHR"sv;
	}
	case IndirectBindableBitNV: {
		return "IndirectBindableBitNV"sv;
	}
	case RayTracingShaderGroupHandleCaptureReplayBitKHR: {
		return "RayTracingShaderGroupHandleCaptureReplayBitKHR"sv;
	}
	case RayTracingAllowMotionBitNV: {
		return "RayTracingAllowMotionBitNV"sv;
	}
	case RenderingFragmentShadingRateAttachmentBitKHR: {
		return "RenderingFragmentShadingRateAttachmentBitKHR"sv;
	}
	case RenderingFragmentDensityMapAttachmentBitEXT: {
		return "RenderingFragmentDensityMapAttachmentBitEXT"sv;
	}
	case RetainLinkTimeOptimizationInfoBitEXT: {
		return "RetainLinkTimeOptimizationInfoBitEXT"sv;
	}
	case RayTracingOpacityMicromapBitKHR: {
		return "RayTracingOpacityMicromapBitKHR"sv;
	}
	case ColorAttachmentFeedbackLoopBitEXT: {
		return "ColorAttachmentFeedbackLoopBitEXT"sv;
	}
	case DepthStencilAttachmentFeedbackLoopBitEXT: {
		return "DepthStencilAttachmentFeedbackLoopBitEXT"sv;
	}
	case NoProtectedAccess: {
		return "NoProtectedAccess"sv;
	}
	case RayTracingDisplacementMicromapBitNV: {
		return "RayTracingDisplacementMicromapBitNV"sv;
	}
	case DescriptorBufferBitEXT: {
		return "DescriptorBufferBitEXT"sv;
	}
	case ProtectedAccessOnly: {
		return "ProtectedAccessOnly"sv;
	}
	case CaptureDataBitKHR: {
		return "CaptureDataBitKHR"sv;
	}
	case ExecutionGraphBitAMDX: {
		return "ExecutionGraphBitAMDX"sv;
	}
	case RayTracingAllowSpheresAndLinearSweptSpheresBitNV: {
		return "RayTracingAllowSpheresAndLinearSweptSpheresBitNV"sv;
	}
	case EnableLegacyDitheringBitEXT: {
		return "EnableLegacyDitheringBitEXT"sv;
	}
	case DescriptorHeapBitEXT: {
		return "DescriptorHeapBitEXT"sv;
	}
	case DisallowOpacityMicromapBitARM: {
		return "DisallowOpacityMicromapBitARM"sv;
	}
	case IndirectBindableBitEXT: {
		return "IndirectBindableBitEXT"sv;
	}
	case InstrumentShadersBitARM: {
		return "InstrumentShadersBitARM"sv;
	}
	case PerLayerFragmentDensityBitVALVE: {
		return "PerLayerFragmentDensityBitVALVE"sv;
	}
	case OpacityMicromapDisallowMixedSpecialIndexBitKHR: {
		return "OpacityMicromapDisallowMixedSpecialIndexBitKHR"sv;
	}
	case v64BitIndexingBitEXT: {
		return "v64BitIndexingBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineCreateBits2";
}
template<> auto bitToString(PipelineCreationFeedbackBits bit) -> std::string_view {
	using enum PipelineCreationFeedbackBits;
	switch (bit) {
	case Valid: {
		return "Valid"sv;
	}
	case ApplicationPipelineCacheHit: {
		return "ApplicationPipelineCacheHit"sv;
	}
	case BasePipelineAcceleration: {
		return "BasePipelineAcceleration"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineCreationFeedbackBits";
}
template<> auto bitToString(PipelineDepthStencilStateCreateBits bit) -> std::string_view {
	using enum PipelineDepthStencilStateCreateBits;
	switch (bit) {
	case RasterizationOrderAttachmentDepthAccessBitEXT: {
		return "RasterizationOrderAttachmentDepthAccessBitEXT"sv;
	}
	case RasterizationOrderAttachmentStencilAccessBitEXT: {
		return "RasterizationOrderAttachmentStencilAccessBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineDepthStencilStateCreateBits";
}
template<> auto bitToString(PipelineDiscardRectangleStateCreateBitsEXT bit) -> std::string_view {
	using enum PipelineDiscardRectangleStateCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: PipelineDiscardRectangleStateCreateBitsEXT";
}
template<> auto bitToString(PipelineDynamicStateCreateBits bit) -> std::string_view {
	using enum PipelineDynamicStateCreateBits;
	switch (bit) {
	}
	return "bit not part of: PipelineDynamicStateCreateBits";
}
template<> auto bitToString(PipelineInputAssemblyStateCreateBits bit) -> std::string_view {
	using enum PipelineInputAssemblyStateCreateBits;
	switch (bit) {
	}
	return "bit not part of: PipelineInputAssemblyStateCreateBits";
}
template<> auto bitToString(PipelineLayoutCreateBits bit) -> std::string_view {
	using enum PipelineLayoutCreateBits;
	switch (bit) {
	case IndependentSetsBitEXT: {
		return "IndependentSetsBitEXT"sv;
	}
	case NoTaskShaderBitKHR: {
		return "NoTaskShaderBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineLayoutCreateBits";
}
template<> auto bitToString(PipelineMultisampleStateCreateBits bit) -> std::string_view {
	using enum PipelineMultisampleStateCreateBits;
	switch (bit) {
	}
	return "bit not part of: PipelineMultisampleStateCreateBits";
}
template<> auto bitToString(PipelineRasterizationConservativeStateCreateBitsEXT bit) -> std::string_view {
	using enum PipelineRasterizationConservativeStateCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: PipelineRasterizationConservativeStateCreateBitsEXT";
}
template<> auto bitToString(PipelineRasterizationDepthClipStateCreateBitsEXT bit) -> std::string_view {
	using enum PipelineRasterizationDepthClipStateCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: PipelineRasterizationDepthClipStateCreateBitsEXT";
}
template<> auto bitToString(PipelineRasterizationStateCreateBits bit) -> std::string_view {
	using enum PipelineRasterizationStateCreateBits;
	switch (bit) {
	}
	return "bit not part of: PipelineRasterizationStateCreateBits";
}
template<> auto bitToString(PipelineRasterizationStateStreamCreateBitsEXT bit) -> std::string_view {
	using enum PipelineRasterizationStateStreamCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: PipelineRasterizationStateStreamCreateBitsEXT";
}
template<> auto bitToString(PipelineShaderStageCreateBits bit) -> std::string_view {
	using enum PipelineShaderStageCreateBits;
	switch (bit) {
	case AllowVaryingSubgroupSize: {
		return "AllowVaryingSubgroupSize"sv;
	}
	case RequireFullSubgroups: {
		return "RequireFullSubgroups"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineShaderStageCreateBits";
}
template<> auto bitToString(PipelineStageBits bit) -> std::string_view {
	using enum PipelineStageBits;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case TopOfPipe: {
		return "TopOfPipe"sv;
	}
	case DrawIndirect: {
		return "DrawIndirect"sv;
	}
	case VertexInput: {
		return "VertexInput"sv;
	}
	case VertexShader: {
		return "VertexShader"sv;
	}
	case TessellationControlShader: {
		return "TessellationControlShader"sv;
	}
	case TessellationEvaluationShader: {
		return "TessellationEvaluationShader"sv;
	}
	case GeometryShader: {
		return "GeometryShader"sv;
	}
	case FragmentShader: {
		return "FragmentShader"sv;
	}
	case EarlyFragmentTests: {
		return "EarlyFragmentTests"sv;
	}
	case LateFragmentTests: {
		return "LateFragmentTests"sv;
	}
	case ColorAttachmentOutput: {
		return "ColorAttachmentOutput"sv;
	}
	case ComputeShader: {
		return "ComputeShader"sv;
	}
	case Transfer: {
		return "Transfer"sv;
	}
	case BottomOfPipe: {
		return "BottomOfPipe"sv;
	}
	case Host: {
		return "Host"sv;
	}
	case AllGraphics: {
		return "AllGraphics"sv;
	}
	case AllCommands: {
		return "AllCommands"sv;
	}
	case CommandPreprocessBitEXT: {
		return "CommandPreprocessBitEXT"sv;
	}
	case ConditionalRenderingBitEXT: {
		return "ConditionalRenderingBitEXT"sv;
	}
	case TaskShaderBitEXT: {
		return "TaskShaderBitEXT"sv;
	}
	case MeshShaderBitEXT: {
		return "MeshShaderBitEXT"sv;
	}
	case RayTracingShaderBitKHR: {
		return "RayTracingShaderBitKHR"sv;
	}
	case FragmentShadingRateAttachmentBitKHR: {
		return "FragmentShadingRateAttachmentBitKHR"sv;
	}
	case FragmentDensityProcessBitEXT: {
		return "FragmentDensityProcessBitEXT"sv;
	}
	case TransformFeedbackBitEXT: {
		return "TransformFeedbackBitEXT"sv;
	}
	case AccelerationStructureBuildBitKHR: {
		return "AccelerationStructureBuildBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineStageBits";
}
template<> auto bitToString(PipelineStageBits2 bit) -> std::string_view {
	using enum PipelineStageBits2;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case TopOfPipe: {
		return "TopOfPipe"sv;
	}
	case DrawIndirect: {
		return "DrawIndirect"sv;
	}
	case VertexInput: {
		return "VertexInput"sv;
	}
	case VertexShader: {
		return "VertexShader"sv;
	}
	case TessellationControlShader: {
		return "TessellationControlShader"sv;
	}
	case TessellationEvaluationShader: {
		return "TessellationEvaluationShader"sv;
	}
	case GeometryShader: {
		return "GeometryShader"sv;
	}
	case FragmentShader: {
		return "FragmentShader"sv;
	}
	case EarlyFragmentTests: {
		return "EarlyFragmentTests"sv;
	}
	case LateFragmentTests: {
		return "LateFragmentTests"sv;
	}
	case ColorAttachmentOutput: {
		return "ColorAttachmentOutput"sv;
	}
	case ComputeShader: {
		return "ComputeShader"sv;
	}
	case AllTransfer: {
		return "AllTransfer"sv;
	}
	case BottomOfPipe: {
		return "BottomOfPipe"sv;
	}
	case Host: {
		return "Host"sv;
	}
	case AllGraphics: {
		return "AllGraphics"sv;
	}
	case AllCommands: {
		return "AllCommands"sv;
	}
	case CommandPreprocessBitEXT: {
		return "CommandPreprocessBitEXT"sv;
	}
	case ConditionalRenderingBitEXT: {
		return "ConditionalRenderingBitEXT"sv;
	}
	case TaskShaderBitEXT: {
		return "TaskShaderBitEXT"sv;
	}
	case MeshShaderBitEXT: {
		return "MeshShaderBitEXT"sv;
	}
	case RayTracingShaderBitKHR: {
		return "RayTracingShaderBitKHR"sv;
	}
	case FragmentShadingRateAttachmentBitKHR: {
		return "FragmentShadingRateAttachmentBitKHR"sv;
	}
	case FragmentDensityProcessBitEXT: {
		return "FragmentDensityProcessBitEXT"sv;
	}
	case TransformFeedbackBitEXT: {
		return "TransformFeedbackBitEXT"sv;
	}
	case AccelerationStructureBuildBitKHR: {
		return "AccelerationStructureBuildBitKHR"sv;
	}
	case VideoDecodeBitKHR: {
		return "VideoDecodeBitKHR"sv;
	}
	case VideoEncodeBitKHR: {
		return "VideoEncodeBitKHR"sv;
	}
	case AccelerationStructureCopyBitKHR: {
		return "AccelerationStructureCopyBitKHR"sv;
	}
	case OpticalFlowBitNV: {
		return "OpticalFlowBitNV"sv;
	}
	case MicromapBuildBitEXT: {
		return "MicromapBuildBitEXT"sv;
	}
	case Copy: {
		return "Copy"sv;
	}
	case Resolve: {
		return "Resolve"sv;
	}
	case Blit: {
		return "Blit"sv;
	}
	case Clear: {
		return "Clear"sv;
	}
	case IndexInput: {
		return "IndexInput"sv;
	}
	case VertexAttributeInput: {
		return "VertexAttributeInput"sv;
	}
	case PreRasterizationShaders: {
		return "PreRasterizationShaders"sv;
	}
	case SubpassShaderBitHUAWEI: {
		return "SubpassShaderBitHUAWEI"sv;
	}
	case InvocationMaskBitHUAWEI: {
		return "InvocationMaskBitHUAWEI"sv;
	}
	case ClusterCullingShaderBitHUAWEI: {
		return "ClusterCullingShaderBitHUAWEI"sv;
	}
	case DataGraphBitARM: {
		return "DataGraphBitARM"sv;
	}
	case ConvertCooperativeVectorMatrixBitNV: {
		return "ConvertCooperativeVectorMatrixBitNV"sv;
	}
	case MemoryDecompressionBitEXT: {
		return "MemoryDecompressionBitEXT"sv;
	}
	case CopyIndirectBitKHR: {
		return "CopyIndirectBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PipelineStageBits2";
}
template<> auto bitToString(PipelineTessellationStateCreateBits bit) -> std::string_view {
	using enum PipelineTessellationStateCreateBits;
	switch (bit) {
	}
	return "bit not part of: PipelineTessellationStateCreateBits";
}
template<> auto bitToString(PipelineVertexInputStateCreateBits bit) -> std::string_view {
	using enum PipelineVertexInputStateCreateBits;
	switch (bit) {
	}
	return "bit not part of: PipelineVertexInputStateCreateBits";
}
template<> auto bitToString(PipelineViewportStateCreateBits bit) -> std::string_view {
	using enum PipelineViewportStateCreateBits;
	switch (bit) {
	}
	return "bit not part of: PipelineViewportStateCreateBits";
}
template<> auto bitToString(PipelineViewportSwizzleStateCreateBitsNV bit) -> std::string_view {
	using enum PipelineViewportSwizzleStateCreateBitsNV;
	switch (bit) {
	}
	return "bit not part of: PipelineViewportSwizzleStateCreateBitsNV";
}
template<> auto bitToString(PresentGravityBitsKHR bit) -> std::string_view {
	using enum PresentGravityBitsKHR;
	switch (bit) {
	case Min: {
		return "Min"sv;
	}
	case Max: {
		return "Max"sv;
	}
	case Centered: {
		return "Centered"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PresentGravityBitsKHR";
}
template<> auto bitToString(PresentScalingBitsKHR bit) -> std::string_view {
	using enum PresentScalingBitsKHR;
	switch (bit) {
	case OneToOne: {
		return "OneToOne"sv;
	}
	case AspectRatioStretch: {
		return "AspectRatioStretch"sv;
	}
	case Stretch: {
		return "Stretch"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PresentScalingBitsKHR";
}
template<> auto bitToString(PresentStageBitsEXT bit) -> std::string_view {
	using enum PresentStageBitsEXT;
	switch (bit) {
	case QueueOperationsEnd: {
		return "QueueOperationsEnd"sv;
	}
	case RequestDequeued: {
		return "RequestDequeued"sv;
	}
	case ImageFirstPixelOut: {
		return "ImageFirstPixelOut"sv;
	}
	case ImageFirstPixelVisible: {
		return "ImageFirstPixelVisible"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PresentStageBitsEXT";
}
template<> auto bitToString(PresentTimingInfoBitsEXT bit) -> std::string_view {
	using enum PresentTimingInfoBitsEXT;
	switch (bit) {
	case PresentAtRelativeTime: {
		return "PresentAtRelativeTime"sv;
	}
	case PresentAtNearestRefreshCycle: {
		return "PresentAtNearestRefreshCycle"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: PresentTimingInfoBitsEXT";
}
template<> auto bitToString(PrivateDataSlotCreateBits bit) -> std::string_view {
	using enum PrivateDataSlotCreateBits;
	switch (bit) {
	case BaseObjectHandleBitNV: {
		return "BaseObjectHandleBitNV"sv;
	}
	}
	return "bit not part of: PrivateDataSlotCreateBits";
}
template<> auto bitToString(QueryControlBits bit) -> std::string_view {
	using enum QueryControlBits;
	switch (bit) {
	case Precise: {
		return "Precise"sv;
	}
	}
	return "bit not part of: QueryControlBits";
}
template<> auto bitToString(QueryPipelineStatisticBits bit) -> std::string_view {
	using enum QueryPipelineStatisticBits;
	switch (bit) {
	case InputAssemblyVertices: {
		return "InputAssemblyVertices"sv;
	}
	case InputAssemblyPrimitives: {
		return "InputAssemblyPrimitives"sv;
	}
	case VertexShaderInvocations: {
		return "VertexShaderInvocations"sv;
	}
	case GeometryShaderInvocations: {
		return "GeometryShaderInvocations"sv;
	}
	case GeometryShaderPrimitives: {
		return "GeometryShaderPrimitives"sv;
	}
	case ClippingInvocations: {
		return "ClippingInvocations"sv;
	}
	case ClippingPrimitives: {
		return "ClippingPrimitives"sv;
	}
	case FragmentShaderInvocations: {
		return "FragmentShaderInvocations"sv;
	}
	case TessellationControlShaderPatches: {
		return "TessellationControlShaderPatches"sv;
	}
	case TessellationEvaluationShaderInvocations: {
		return "TessellationEvaluationShaderInvocations"sv;
	}
	case ComputeShaderInvocations: {
		return "ComputeShaderInvocations"sv;
	}
	case TaskShaderInvocationsBitEXT: {
		return "TaskShaderInvocationsBitEXT"sv;
	}
	case MeshShaderInvocationsBitEXT: {
		return "MeshShaderInvocationsBitEXT"sv;
	}
	case ClusterCullingShaderInvocationsBitHUAWEI: {
		return "ClusterCullingShaderInvocationsBitHUAWEI"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: QueryPipelineStatisticBits";
}
template<> auto bitToString(QueryPoolCreateBits bit) -> std::string_view {
	using enum QueryPoolCreateBits;
	switch (bit) {
	case ResetBitKHR: {
		return "ResetBitKHR"sv;
	}
	}
	return "bit not part of: QueryPoolCreateBits";
}
template<> auto bitToString(QueryResultBits bit) -> std::string_view {
	using enum QueryResultBits;
	switch (bit) {
	case v64: {
		return "v64"sv;
	}
	case Wait: {
		return "Wait"sv;
	}
	case WithAvailability: {
		return "WithAvailability"sv;
	}
	case Partial: {
		return "Partial"sv;
	}
	case WithStatusBitKHR: {
		return "WithStatusBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: QueryResultBits";
}
template<> auto bitToString(QueueBits bit) -> std::string_view {
	using enum QueueBits;
	switch (bit) {
	case Graphics: {
		return "Graphics"sv;
	}
	case Compute: {
		return "Compute"sv;
	}
	case Transfer: {
		return "Transfer"sv;
	}
	case SparseBinding: {
		return "SparseBinding"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case VideoDecodeBitKHR: {
		return "VideoDecodeBitKHR"sv;
	}
	case VideoEncodeBitKHR: {
		return "VideoEncodeBitKHR"sv;
	}
	case OpticalFlowBitNV: {
		return "OpticalFlowBitNV"sv;
	}
	case DataGraphBitARM: {
		return "DataGraphBitARM"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: QueueBits";
}
template<> auto bitToString(RefreshObjectBitsKHR bit) -> std::string_view {
	using enum RefreshObjectBitsKHR;
	switch (bit) {
	}
	return "bit not part of: RefreshObjectBitsKHR";
}
template<> auto bitToString(RenderPassCreateBits bit) -> std::string_view {
	using enum RenderPassCreateBits;
	switch (bit) {
	case TransformBitQCOM: {
		return "TransformBitQCOM"sv;
	}
	case PerLayerFragmentDensityBitVALVE: {
		return "PerLayerFragmentDensityBitVALVE"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: RenderPassCreateBits";
}
template<> auto bitToString(RenderingAttachmentBitsKHR bit) -> std::string_view {
	using enum RenderingAttachmentBitsKHR;
	switch (bit) {
	case InputAttachmentFeedback: {
		return "InputAttachmentFeedback"sv;
	}
	case ResolveSkipTransferFunction: {
		return "ResolveSkipTransferFunction"sv;
	}
	case ResolveEnableTransferFunction: {
		return "ResolveEnableTransferFunction"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: RenderingAttachmentBitsKHR";
}
template<> auto bitToString(RenderingBits bit) -> std::string_view {
	using enum RenderingBits;
	switch (bit) {
	case ContentsSecondaryCommandBuffers: {
		return "ContentsSecondaryCommandBuffers"sv;
	}
	case Suspending: {
		return "Suspending"sv;
	}
	case Resuming: {
		return "Resuming"sv;
	}
	case EnableLegacyDitheringBitEXT: {
		return "EnableLegacyDitheringBitEXT"sv;
	}
	case ContentsInlineBitKHR: {
		return "ContentsInlineBitKHR"sv;
	}
	case PerLayerFragmentDensityBitVALVE: {
		return "PerLayerFragmentDensityBitVALVE"sv;
	}
	case FragmentRegionBitEXT: {
		return "FragmentRegionBitEXT"sv;
	}
	case CustomResolveBitEXT: {
		return "CustomResolveBitEXT"sv;
	}
	case LocalReadConcurrentAccessControlBitKHR: {
		return "LocalReadConcurrentAccessControlBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: RenderingBits";
}
template<> auto bitToString(ResolveImageBitsKHR bit) -> std::string_view {
	using enum ResolveImageBitsKHR;
	switch (bit) {
	case SkipTransferFunction: {
		return "SkipTransferFunction"sv;
	}
	case EnableTransferFunction: {
		return "EnableTransferFunction"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ResolveImageBitsKHR";
}
template<> auto bitToString(ResolveModeBits bit) -> std::string_view {
	using enum ResolveModeBits;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case SampleZero: {
		return "SampleZero"sv;
	}
	case Average: {
		return "Average"sv;
	}
	case Min: {
		return "Min"sv;
	}
	case Max: {
		return "Max"sv;
	}
	case ExternalFormatDownsampleBitANDROID: {
		return "ExternalFormatDownsampleBitANDROID"sv;
	}
	case CustomBitEXT: {
		return "CustomBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ResolveModeBits";
}
template<> auto bitToString(SampleCountBits bit) -> std::string_view {
	using enum SampleCountBits;
	switch (bit) {
	case v1: {
		return "v1"sv;
	}
	case v2: {
		return "v2"sv;
	}
	case v4: {
		return "v4"sv;
	}
	case v8: {
		return "v8"sv;
	}
	case v16: {
		return "v16"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case v64: {
		return "v64"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: SampleCountBits";
}
template<> auto bitToString(SamplerCreateBits bit) -> std::string_view {
	using enum SamplerCreateBits;
	switch (bit) {
	case SubsampledBitEXT: {
		return "SubsampledBitEXT"sv;
	}
	case SubsampledCoarseReconstructionBitEXT: {
		return "SubsampledCoarseReconstructionBitEXT"sv;
	}
	case NonSeamlessCubeMapBitEXT: {
		return "NonSeamlessCubeMapBitEXT"sv;
	}
	case DescriptorBufferCaptureReplayBitEXT: {
		return "DescriptorBufferCaptureReplayBitEXT"sv;
	}
	case ImageProcessingBitQCOM: {
		return "ImageProcessingBitQCOM"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: SamplerCreateBits";
}
template<> auto bitToString(ScreenSurfaceCreateBitsQNX bit) -> std::string_view {
	using enum ScreenSurfaceCreateBitsQNX;
	switch (bit) {
	}
	return "bit not part of: ScreenSurfaceCreateBitsQNX";
}
template<> auto bitToString(SemaphoreCreateBits bit) -> std::string_view {
	using enum SemaphoreCreateBits;
	switch (bit) {
	}
	return "bit not part of: SemaphoreCreateBits";
}
template<> auto bitToString(SemaphoreImportBits bit) -> std::string_view {
	using enum SemaphoreImportBits;
	switch (bit) {
	case Temporary: {
		return "Temporary"sv;
	}
	}
	return "bit not part of: SemaphoreImportBits";
}
template<> auto bitToString(SemaphoreWaitBits bit) -> std::string_view {
	using enum SemaphoreWaitBits;
	switch (bit) {
	case Any: {
		return "Any"sv;
	}
	}
	return "bit not part of: SemaphoreWaitBits";
}
template<> auto bitToString(ShaderCorePropertiesBitsAMD bit) -> std::string_view {
	using enum ShaderCorePropertiesBitsAMD;
	switch (bit) {
	}
	return "bit not part of: ShaderCorePropertiesBitsAMD";
}
template<> auto bitToString(ShaderCreateBitsEXT bit) -> std::string_view {
	using enum ShaderCreateBitsEXT;
	switch (bit) {
	case LinkStage: {
		return "LinkStage"sv;
	}
	case AllowVaryingSubgroupSize: {
		return "AllowVaryingSubgroupSize"sv;
	}
	case RequireFullSubgroups: {
		return "RequireFullSubgroups"sv;
	}
	case NoTaskShader: {
		return "NoTaskShader"sv;
	}
	case DispatchBase: {
		return "DispatchBase"sv;
	}
	case FragmentShadingRateAttachment: {
		return "FragmentShadingRateAttachment"sv;
	}
	case FragmentDensityMapAttachment: {
		return "FragmentDensityMapAttachment"sv;
	}
	case IndirectBindable: {
		return "IndirectBindable"sv;
	}
	case DescriptorHeap: {
		return "DescriptorHeap"sv;
	}
	case InstrumentShaderBitARM: {
		return "InstrumentShaderBitARM"sv;
	}
	case OpacityMicromapDisallowMixedSpecialIndex: {
		return "OpacityMicromapDisallowMixedSpecialIndex"sv;
	}
	case v64BitIndexing: {
		return "v64BitIndexing"sv;
	}
	case IndependentSetsBitKHR: {
		return "IndependentSetsBitKHR"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ShaderCreateBitsEXT";
}
template<> auto bitToString(ShaderInstrumentationValuesBitsARM bit) -> std::string_view {
	using enum ShaderInstrumentationValuesBitsARM;
	switch (bit) {
	}
	return "bit not part of: ShaderInstrumentationValuesBitsARM";
}
template<> auto bitToString(ShaderModuleCreateBits bit) -> std::string_view {
	using enum ShaderModuleCreateBits;
	switch (bit) {
	}
	return "bit not part of: ShaderModuleCreateBits";
}
template<> auto bitToString(ShaderStageBits bit) -> std::string_view {
	using enum ShaderStageBits;
	switch (bit) {
	case Vertex: {
		return "Vertex"sv;
	}
	case TessellationControl: {
		return "TessellationControl"sv;
	}
	case TessellationEvaluation: {
		return "TessellationEvaluation"sv;
	}
	case Geometry: {
		return "Geometry"sv;
	}
	case Fragment: {
		return "Fragment"sv;
	}
	case AllGraphics: {
		return "AllGraphics"sv;
	}
	case Compute: {
		return "Compute"sv;
	}
	case TaskBitEXT: {
		return "TaskBitEXT"sv;
	}
	case MeshBitEXT: {
		return "MeshBitEXT"sv;
	}
	case RaygenBitKHR: {
		return "RaygenBitKHR"sv;
	}
	case AnyHitBitKHR: {
		return "AnyHitBitKHR"sv;
	}
	case ClosestHitBitKHR: {
		return "ClosestHitBitKHR"sv;
	}
	case MissBitKHR: {
		return "MissBitKHR"sv;
	}
	case IntersectionBitKHR: {
		return "IntersectionBitKHR"sv;
	}
	case CallableBitKHR: {
		return "CallableBitKHR"sv;
	}
	case SubpassShadingBitHUAWEI: {
		return "SubpassShadingBitHUAWEI"sv;
	}
	case ClusterCullingBitHUAWEI: {
		return "ClusterCullingBitHUAWEI"sv;
	}
	case All: {
		return "All"sv;
	}
	}
	return "bit not part of: ShaderStageBits";
}
template<> auto bitToString(SparseImageFormatBits bit) -> std::string_view {
	using enum SparseImageFormatBits;
	switch (bit) {
	case SingleMiptail: {
		return "SingleMiptail"sv;
	}
	case AlignedMipSize: {
		return "AlignedMipSize"sv;
	}
	case NonstandardBlockSize: {
		return "NonstandardBlockSize"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: SparseImageFormatBits";
}
template<> auto bitToString(SparseMemoryBindBits bit) -> std::string_view {
	using enum SparseMemoryBindBits;
	switch (bit) {
	case Metadata: {
		return "Metadata"sv;
	}
	}
	return "bit not part of: SparseMemoryBindBits";
}
template<> auto bitToString(SpirvResourceTypeBitsEXT bit) -> std::string_view {
	using enum SpirvResourceTypeBitsEXT;
	switch (bit) {
	case Sampler: {
		return "Sampler"sv;
	}
	case SampledImage: {
		return "SampledImage"sv;
	}
	case ReadOnlyImage: {
		return "ReadOnlyImage"sv;
	}
	case ReadWriteImage: {
		return "ReadWriteImage"sv;
	}
	case CombinedSampledImage: {
		return "CombinedSampledImage"sv;
	}
	case UniformBuffer: {
		return "UniformBuffer"sv;
	}
	case ReadOnlyStorageBuffer: {
		return "ReadOnlyStorageBuffer"sv;
	}
	case ReadWriteStorageBuffer: {
		return "ReadWriteStorageBuffer"sv;
	}
	case AccelerationStructure: {
		return "AccelerationStructure"sv;
	}
	case TensorBitARM: {
		return "TensorBitARM"sv;
	}
	case All: {
		return "All"sv;
	}
	}
	return "bit not part of: SpirvResourceTypeBitsEXT";
}
template<> auto bitToString(StencilFaceBits bit) -> std::string_view {
	using enum StencilFaceBits;
	switch (bit) {
	case Front: {
		return "Front"sv;
	}
	case Back: {
		return "Back"sv;
	}
	case FrontAndBack: {
		return "FrontAndBack"sv;
	}
	}
	return "bit not part of: StencilFaceBits";
}
template<> auto bitToString(StreamDescriptorSurfaceCreateBitsGGP bit) -> std::string_view {
	using enum StreamDescriptorSurfaceCreateBitsGGP;
	switch (bit) {
	}
	return "bit not part of: StreamDescriptorSurfaceCreateBitsGGP";
}
template<> auto bitToString(SubgroupFeatureBits bit) -> std::string_view {
	using enum SubgroupFeatureBits;
	switch (bit) {
	case Basic: {
		return "Basic"sv;
	}
	case Vote: {
		return "Vote"sv;
	}
	case Arithmetic: {
		return "Arithmetic"sv;
	}
	case Ballot: {
		return "Ballot"sv;
	}
	case Shuffle: {
		return "Shuffle"sv;
	}
	case ShuffleRelative: {
		return "ShuffleRelative"sv;
	}
	case Clustered: {
		return "Clustered"sv;
	}
	case Quad: {
		return "Quad"sv;
	}
	case PartitionedBitEXT: {
		return "PartitionedBitEXT"sv;
	}
	case Rotate: {
		return "Rotate"sv;
	}
	case RotateClustered: {
		return "RotateClustered"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: SubgroupFeatureBits";
}
template<> auto bitToString(SubmitBits bit) -> std::string_view {
	using enum SubmitBits;
	switch (bit) {
	case Protected: {
		return "Protected"sv;
	}
	}
	return "bit not part of: SubmitBits";
}
template<> auto bitToString(SubpassDescriptionBits bit) -> std::string_view {
	using enum SubpassDescriptionBits;
	switch (bit) {
	case PerViewAttributesBitNVX: {
		return "PerViewAttributesBitNVX"sv;
	}
	case PerViewPositionxOnlyBitNVX: {
		return "PerViewPositionxOnlyBitNVX"sv;
	}
	case FragmentRegionBitEXT: {
		return "FragmentRegionBitEXT"sv;
	}
	case CustomResolveBitEXT: {
		return "CustomResolveBitEXT"sv;
	}
	case RasterizationOrderAttachmentColorAccessBitEXT: {
		return "RasterizationOrderAttachmentColorAccessBitEXT"sv;
	}
	case RasterizationOrderAttachmentDepthAccessBitEXT: {
		return "RasterizationOrderAttachmentDepthAccessBitEXT"sv;
	}
	case RasterizationOrderAttachmentStencilAccessBitEXT: {
		return "RasterizationOrderAttachmentStencilAccessBitEXT"sv;
	}
	case EnableLegacyDitheringBitEXT: {
		return "EnableLegacyDitheringBitEXT"sv;
	}
	case TileShadingApronBitQCOM: {
		return "TileShadingApronBitQCOM"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: SubpassDescriptionBits";
}
template<> auto bitToString(SurfaceCounterBitsEXT bit) -> std::string_view {
	using enum SurfaceCounterBitsEXT;
	switch (bit) {
	case Vblank: {
		return "Vblank"sv;
	}
	}
	return "bit not part of: SurfaceCounterBitsEXT";
}
template<> auto bitToString(SurfaceCreateBitsOHOS bit) -> std::string_view {
	using enum SurfaceCreateBitsOHOS;
	switch (bit) {
	}
	return "bit not part of: SurfaceCreateBitsOHOS";
}
template<> auto bitToString(SurfaceTransformBitsKHR bit) -> std::string_view {
	using enum SurfaceTransformBitsKHR;
	switch (bit) {
	case Identity: {
		return "Identity"sv;
	}
	case Rotate90: {
		return "Rotate90"sv;
	}
	case Rotate180: {
		return "Rotate180"sv;
	}
	case Rotate270: {
		return "Rotate270"sv;
	}
	case HorizontalMirror: {
		return "HorizontalMirror"sv;
	}
	case HorizontalMirrorRotate90: {
		return "HorizontalMirrorRotate90"sv;
	}
	case HorizontalMirrorRotate180: {
		return "HorizontalMirrorRotate180"sv;
	}
	case HorizontalMirrorRotate270: {
		return "HorizontalMirrorRotate270"sv;
	}
	case Inherit: {
		return "Inherit"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: SurfaceTransformBitsKHR";
}
template<> auto bitToString(SwapchainCreateBitsKHR bit) -> std::string_view {
	using enum SwapchainCreateBitsKHR;
	switch (bit) {
	case SplitInstanceBindRegions: {
		return "SplitInstanceBindRegions"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case MutableFormat: {
		return "MutableFormat"sv;
	}
	case DeferredMemoryAllocation: {
		return "DeferredMemoryAllocation"sv;
	}
	case PresentId2: {
		return "PresentId2"sv;
	}
	case PresentWait2: {
		return "PresentWait2"sv;
	}
	case MultisampledRenderToSingleSampledBitEXT: {
		return "MultisampledRenderToSingleSampledBitEXT"sv;
	}
	case PresentTimingBitEXT: {
		return "PresentTimingBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: SwapchainCreateBitsKHR";
}
template<> auto bitToString(SwapchainImageUsageBitsANDROID bit) -> std::string_view {
	using enum SwapchainImageUsageBitsANDROID;
	switch (bit) {
	}
	return "bit not part of: SwapchainImageUsageBitsANDROID";
}
template<> auto bitToString(SwapchainImageUsageBitsOHOS bit) -> std::string_view {
	using enum SwapchainImageUsageBitsOHOS;
	switch (bit) {
	}
	return "bit not part of: SwapchainImageUsageBitsOHOS";
}
template<> auto bitToString(TensorCreateBitsARM bit) -> std::string_view {
	using enum TensorCreateBitsARM;
	switch (bit) {
	case MutableFormat: {
		return "MutableFormat"sv;
	}
	case Protected: {
		return "Protected"sv;
	}
	case DescriptorBufferCaptureReplay: {
		return "DescriptorBufferCaptureReplay"sv;
	}
	case DescriptorHeapCaptureReplay: {
		return "DescriptorHeapCaptureReplay"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: TensorCreateBitsARM";
}
template<> auto bitToString(TensorUsageBitsARM bit) -> std::string_view {
	using enum TensorUsageBitsARM;
	switch (bit) {
	case Shader: {
		return "Shader"sv;
	}
	case TransferSrc: {
		return "TransferSrc"sv;
	}
	case TransferDst: {
		return "TransferDst"sv;
	}
	case ImageAliasing: {
		return "ImageAliasing"sv;
	}
	case DataGraph: {
		return "DataGraph"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: TensorUsageBitsARM";
}
template<> auto bitToString(TensorViewCreateBitsARM bit) -> std::string_view {
	using enum TensorViewCreateBitsARM;
	switch (bit) {
	case DescriptorBufferCaptureReplay: {
		return "DescriptorBufferCaptureReplay"sv;
	}
	}
	return "bit not part of: TensorViewCreateBitsARM";
}
template<> auto bitToString(TileShadingRenderPassBitsQCOM bit) -> std::string_view {
	using enum TileShadingRenderPassBitsQCOM;
	switch (bit) {
	case Enable: {
		return "Enable"sv;
	}
	case PerTileExecution: {
		return "PerTileExecution"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: TileShadingRenderPassBitsQCOM";
}
template<> auto bitToString(ToolPurposeBits bit) -> std::string_view {
	using enum ToolPurposeBits;
	switch (bit) {
	case Validation: {
		return "Validation"sv;
	}
	case Profiling: {
		return "Profiling"sv;
	}
	case Tracing: {
		return "Tracing"sv;
	}
	case AdditionalFeatures: {
		return "AdditionalFeatures"sv;
	}
	case ModifyingFeatures: {
		return "ModifyingFeatures"sv;
	}
	case DebugReportingBitEXT: {
		return "DebugReportingBitEXT"sv;
	}
	case DebugMarkersBitEXT: {
		return "DebugMarkersBitEXT"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: ToolPurposeBits";
}
template<> auto bitToString(UbmSurfaceCreateBitsSEC bit) -> std::string_view {
	using enum UbmSurfaceCreateBitsSEC;
	switch (bit) {
	}
	return "bit not part of: UbmSurfaceCreateBitsSEC";
}
template<> auto bitToString(ValidationCacheCreateBitsEXT bit) -> std::string_view {
	using enum ValidationCacheCreateBitsEXT;
	switch (bit) {
	}
	return "bit not part of: ValidationCacheCreateBitsEXT";
}
template<> auto bitToString(ViSurfaceCreateBitsNN bit) -> std::string_view {
	using enum ViSurfaceCreateBitsNN;
	switch (bit) {
	}
	return "bit not part of: ViSurfaceCreateBitsNN";
}
template<> auto bitToString(VideoBeginCodingBitsKHR bit) -> std::string_view {
	using enum VideoBeginCodingBitsKHR;
	switch (bit) {
	}
	return "bit not part of: VideoBeginCodingBitsKHR";
}
template<> auto bitToString(VideoCapabilityBitsKHR bit) -> std::string_view {
	using enum VideoCapabilityBitsKHR;
	switch (bit) {
	case ProtectedContent: {
		return "ProtectedContent"sv;
	}
	case SeparateReferenceImages: {
		return "SeparateReferenceImages"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoCapabilityBitsKHR";
}
template<> auto bitToString(VideoChromaSubsamplingBitsKHR bit) -> std::string_view {
	using enum VideoChromaSubsamplingBitsKHR;
	switch (bit) {
	case Invalid: {
		return "Invalid"sv;
	}
	case Monochrome: {
		return "Monochrome"sv;
	}
	case v420: {
		return "v420"sv;
	}
	case v422: {
		return "v422"sv;
	}
	case v444: {
		return "v444"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoChromaSubsamplingBitsKHR";
}
template<> auto bitToString(VideoCodecOperationBitsKHR bit) -> std::string_view {
	using enum VideoCodecOperationBitsKHR;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case DecodeH264: {
		return "DecodeH264"sv;
	}
	case DecodeH265: {
		return "DecodeH265"sv;
	}
	case DecodeAV1: {
		return "DecodeAV1"sv;
	}
	case DecodeVp9: {
		return "DecodeVp9"sv;
	}
	case EncodeH264: {
		return "EncodeH264"sv;
	}
	case EncodeH265: {
		return "EncodeH265"sv;
	}
	case EncodeAV1: {
		return "EncodeAV1"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoCodecOperationBitsKHR";
}
template<> auto bitToString(VideoCodingControlBitsKHR bit) -> std::string_view {
	using enum VideoCodingControlBitsKHR;
	switch (bit) {
	case Reset: {
		return "Reset"sv;
	}
	case EncodeRateControl: {
		return "EncodeRateControl"sv;
	}
	case EncodeQualityLevel: {
		return "EncodeQualityLevel"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoCodingControlBitsKHR";
}
template<> auto bitToString(VideoComponentBitDepthBitsKHR bit) -> std::string_view {
	using enum VideoComponentBitDepthBitsKHR;
	switch (bit) {
	case Invalid: {
		return "Invalid"sv;
	}
	case v8: {
		return "v8"sv;
	}
	case v10: {
		return "v10"sv;
	}
	case v12: {
		return "v12"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoComponentBitDepthBitsKHR";
}
template<> auto bitToString(VideoDecodeCapabilityBitsKHR bit) -> std::string_view {
	using enum VideoDecodeCapabilityBitsKHR;
	switch (bit) {
	case DpbAndOutputCoincide: {
		return "DpbAndOutputCoincide"sv;
	}
	case DpbAndOutputDistinct: {
		return "DpbAndOutputDistinct"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoDecodeCapabilityBitsKHR";
}
template<> auto bitToString(VideoDecodeBitsKHR bit) -> std::string_view {
	using enum VideoDecodeBitsKHR;
	switch (bit) {
	}
	return "bit not part of: VideoDecodeBitsKHR";
}
template<> auto bitToString(VideoDecodeH264PictureLayoutBitsKHR bit) -> std::string_view {
	using enum VideoDecodeH264PictureLayoutBitsKHR;
	switch (bit) {
	case Progressive: {
		return "Progressive"sv;
	}
	case InterlacedInterleavedLines: {
		return "InterlacedInterleavedLines"sv;
	}
	case InterlacedSeparatePlanes: {
		return "InterlacedSeparatePlanes"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoDecodeH264PictureLayoutBitsKHR";
}
template<> auto bitToString(VideoDecodeUsageBitsKHR bit) -> std::string_view {
	using enum VideoDecodeUsageBitsKHR;
	switch (bit) {
	case Default: {
		return "Default"sv;
	}
	case Transcoding: {
		return "Transcoding"sv;
	}
	case Offline: {
		return "Offline"sv;
	}
	case Streaming: {
		return "Streaming"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoDecodeUsageBitsKHR";
}
template<> auto bitToString(VideoEncodeAV1CapabilityBitsKHR bit) -> std::string_view {
	using enum VideoEncodeAV1CapabilityBitsKHR;
	switch (bit) {
	case PerRateControlGroupMinMaxQIndex: {
		return "PerRateControlGroupMinMaxQIndex"sv;
	}
	case GenerateObuExtensionHeader: {
		return "GenerateObuExtensionHeader"sv;
	}
	case PrimaryReferenceCdfOnly: {
		return "PrimaryReferenceCdfOnly"sv;
	}
	case FrameSizeOverride: {
		return "FrameSizeOverride"sv;
	}
	case MotionVectorScaling: {
		return "MotionVectorScaling"sv;
	}
	case CompoundPredictionIntraRefresh: {
		return "CompoundPredictionIntraRefresh"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeAV1CapabilityBitsKHR";
}
template<> auto bitToString(VideoEncodeAV1RateControlBitsKHR bit) -> std::string_view {
	using enum VideoEncodeAV1RateControlBitsKHR;
	switch (bit) {
	case RegularGop: {
		return "RegularGop"sv;
	}
	case TemporalLayerPatternDyadic: {
		return "TemporalLayerPatternDyadic"sv;
	}
	case ReferencePatternFlat: {
		return "ReferencePatternFlat"sv;
	}
	case ReferencePatternDyadic: {
		return "ReferencePatternDyadic"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeAV1RateControlBitsKHR";
}
template<> auto bitToString(VideoEncodeAV1StdBitsKHR bit) -> std::string_view {
	using enum VideoEncodeAV1StdBitsKHR;
	switch (bit) {
	case UniformTileSpacingFlagSet: {
		return "UniformTileSpacingFlagSet"sv;
	}
	case SkipModePresentUnset: {
		return "SkipModePresentUnset"sv;
	}
	case PrimaryRefFrame: {
		return "PrimaryRefFrame"sv;
	}
	case DeltaQ: {
		return "DeltaQ"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeAV1StdBitsKHR";
}
template<> auto bitToString(VideoEncodeAV1SuperblockSizeBitsKHR bit) -> std::string_view {
	using enum VideoEncodeAV1SuperblockSizeBitsKHR;
	switch (bit) {
	case v64: {
		return "v64"sv;
	}
	case v128: {
		return "v128"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeAV1SuperblockSizeBitsKHR";
}
template<> auto bitToString(VideoEncodeCapabilityBitsKHR bit) -> std::string_view {
	using enum VideoEncodeCapabilityBitsKHR;
	switch (bit) {
	case PrecedingExternallyEncodedBytes: {
		return "PrecedingExternallyEncodedBytes"sv;
	}
	case InsufficientBitstreamBufferRangeDetection: {
		return "InsufficientBitstreamBufferRangeDetection"sv;
	}
	case QuantizationDeltaMap: {
		return "QuantizationDeltaMap"sv;
	}
	case EmphasisMap: {
		return "EmphasisMap"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeCapabilityBitsKHR";
}
template<> auto bitToString(VideoEncodeContentBitsKHR bit) -> std::string_view {
	using enum VideoEncodeContentBitsKHR;
	switch (bit) {
	case Default: {
		return "Default"sv;
	}
	case Camera: {
		return "Camera"sv;
	}
	case Desktop: {
		return "Desktop"sv;
	}
	case Rendered: {
		return "Rendered"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeContentBitsKHR";
}
template<> auto bitToString(VideoEncodeFeedbackBitsKHR bit) -> std::string_view {
	using enum VideoEncodeFeedbackBitsKHR;
	switch (bit) {
	case BitstreamBufferOffset: {
		return "BitstreamBufferOffset"sv;
	}
	case BitstreamBytesWritten: {
		return "BitstreamBytesWritten"sv;
	}
	case BitstreamHasOverrides: {
		return "BitstreamHasOverrides"sv;
	}
	case AverageQuantization: {
		return "AverageQuantization"sv;
	}
	case MinQuantization: {
		return "MinQuantization"sv;
	}
	case MaxQuantization: {
		return "MaxQuantization"sv;
	}
	case IntraPixels: {
		return "IntraPixels"sv;
	}
	case InterPixels: {
		return "InterPixels"sv;
	}
	case SkippedPixels: {
		return "SkippedPixels"sv;
	}
	case PicturePartitionCount: {
		return "PicturePartitionCount"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeFeedbackBitsKHR";
}
template<> auto bitToString(VideoEncodeBitsKHR bit) -> std::string_view {
	using enum VideoEncodeBitsKHR;
	switch (bit) {
	case WithQuantizationDeltaMap: {
		return "WithQuantizationDeltaMap"sv;
	}
	case WithEmphasisMap: {
		return "WithEmphasisMap"sv;
	}
	case IntraRefresh: {
		return "IntraRefresh"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeBitsKHR";
}
template<> auto bitToString(VideoEncodeH264CapabilityBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH264CapabilityBitsKHR;
	switch (bit) {
	case HrdCompliance: {
		return "HrdCompliance"sv;
	}
	case PredictionWeightTableGenerated: {
		return "PredictionWeightTableGenerated"sv;
	}
	case RowUnalignedSlice: {
		return "RowUnalignedSlice"sv;
	}
	case DifferentSliceType: {
		return "DifferentSliceType"sv;
	}
	case BFrameInL0List: {
		return "BFrameInL0List"sv;
	}
	case BFrameInL1List: {
		return "BFrameInL1List"sv;
	}
	case PerPictureTypeMinMaxQp: {
		return "PerPictureTypeMinMaxQp"sv;
	}
	case PerSliceConstantQp: {
		return "PerSliceConstantQp"sv;
	}
	case GeneratePrefixNalu: {
		return "GeneratePrefixNalu"sv;
	}
	case MbQpDiffWraparound: {
		return "MbQpDiffWraparound"sv;
	}
	case BPictureIntraRefresh: {
		return "BPictureIntraRefresh"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH264CapabilityBitsKHR";
}
template<> auto bitToString(VideoEncodeH264RateControlBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH264RateControlBitsKHR;
	switch (bit) {
	case AttemptHrdCompliance: {
		return "AttemptHrdCompliance"sv;
	}
	case RegularGop: {
		return "RegularGop"sv;
	}
	case ReferencePatternFlat: {
		return "ReferencePatternFlat"sv;
	}
	case ReferencePatternDyadic: {
		return "ReferencePatternDyadic"sv;
	}
	case TemporalLayerPatternDyadic: {
		return "TemporalLayerPatternDyadic"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH264RateControlBitsKHR";
}
template<> auto bitToString(VideoEncodeH264StdBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH264StdBitsKHR;
	switch (bit) {
	case SeparateColorPlaneFlagSet: {
		return "SeparateColorPlaneFlagSet"sv;
	}
	case QpprimeYZeroTransformBypassFlagSet: {
		return "QpprimeYZeroTransformBypassFlagSet"sv;
	}
	case ScalingMatrixPresentFlagSet: {
		return "ScalingMatrixPresentFlagSet"sv;
	}
	case ChromaQpIndexOffset: {
		return "ChromaQpIndexOffset"sv;
	}
	case SecondChromaQpIndexOffset: {
		return "SecondChromaQpIndexOffset"sv;
	}
	case PicInitQpMinus26: {
		return "PicInitQpMinus26"sv;
	}
	case WeightedPredFlagSet: {
		return "WeightedPredFlagSet"sv;
	}
	case WeightedBipredIdcExplicit: {
		return "WeightedBipredIdcExplicit"sv;
	}
	case WeightedBipredIdcImplicit: {
		return "WeightedBipredIdcImplicit"sv;
	}
	case Transform8x8ModeFlagSet: {
		return "Transform8x8ModeFlagSet"sv;
	}
	case DirectSpatialMvPredFlagUnset: {
		return "DirectSpatialMvPredFlagUnset"sv;
	}
	case EntropyCodingModeFlagUnset: {
		return "EntropyCodingModeFlagUnset"sv;
	}
	case EntropyCodingModeFlagSet: {
		return "EntropyCodingModeFlagSet"sv;
	}
	case Direct8x8InferenceFlagUnset: {
		return "Direct8x8InferenceFlagUnset"sv;
	}
	case ConstrainedIntraPredFlagSet: {
		return "ConstrainedIntraPredFlagSet"sv;
	}
	case DeblockingFilterDisabled: {
		return "DeblockingFilterDisabled"sv;
	}
	case DeblockingFilterEnabled: {
		return "DeblockingFilterEnabled"sv;
	}
	case DeblockingFilterPartial: {
		return "DeblockingFilterPartial"sv;
	}
	case SliceQpDelta: {
		return "SliceQpDelta"sv;
	}
	case DifferentSliceQpDelta: {
		return "DifferentSliceQpDelta"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH264StdBitsKHR";
}
template<> auto bitToString(VideoEncodeH265CapabilityBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH265CapabilityBitsKHR;
	switch (bit) {
	case HrdCompliance: {
		return "HrdCompliance"sv;
	}
	case PredictionWeightTableGenerated: {
		return "PredictionWeightTableGenerated"sv;
	}
	case RowUnalignedSliceSegment: {
		return "RowUnalignedSliceSegment"sv;
	}
	case DifferentSliceSegmentType: {
		return "DifferentSliceSegmentType"sv;
	}
	case BFrameInL0List: {
		return "BFrameInL0List"sv;
	}
	case BFrameInL1List: {
		return "BFrameInL1List"sv;
	}
	case PerPictureTypeMinMaxQp: {
		return "PerPictureTypeMinMaxQp"sv;
	}
	case PerSliceSegmentConstantQp: {
		return "PerSliceSegmentConstantQp"sv;
	}
	case MultipleTilesPerSliceSegment: {
		return "MultipleTilesPerSliceSegment"sv;
	}
	case MultipleSliceSegmentsPerTile: {
		return "MultipleSliceSegmentsPerTile"sv;
	}
	case CuQpDiffWraparound: {
		return "CuQpDiffWraparound"sv;
	}
	case BPictureIntraRefresh: {
		return "BPictureIntraRefresh"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH265CapabilityBitsKHR";
}
template<> auto bitToString(VideoEncodeH265CtbSizeBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH265CtbSizeBitsKHR;
	switch (bit) {
	case v16: {
		return "v16"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case v64: {
		return "v64"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH265CtbSizeBitsKHR";
}
template<> auto bitToString(VideoEncodeH265RateControlBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH265RateControlBitsKHR;
	switch (bit) {
	case AttemptHrdCompliance: {
		return "AttemptHrdCompliance"sv;
	}
	case RegularGop: {
		return "RegularGop"sv;
	}
	case ReferencePatternFlat: {
		return "ReferencePatternFlat"sv;
	}
	case ReferencePatternDyadic: {
		return "ReferencePatternDyadic"sv;
	}
	case TemporalSubLayerPatternDyadic: {
		return "TemporalSubLayerPatternDyadic"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH265RateControlBitsKHR";
}
template<> auto bitToString(VideoEncodeH265StdBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH265StdBitsKHR;
	switch (bit) {
	case SeparateColorPlaneFlagSet: {
		return "SeparateColorPlaneFlagSet"sv;
	}
	case SampleAdaptiveOffsetEnabledFlagSet: {
		return "SampleAdaptiveOffsetEnabledFlagSet"sv;
	}
	case ScalingListDataPresentFlagSet: {
		return "ScalingListDataPresentFlagSet"sv;
	}
	case PcmEnabledFlagSet: {
		return "PcmEnabledFlagSet"sv;
	}
	case SpsTemporalMvpEnabledFlagSet: {
		return "SpsTemporalMvpEnabledFlagSet"sv;
	}
	case InitQpMinus26: {
		return "InitQpMinus26"sv;
	}
	case WeightedPredFlagSet: {
		return "WeightedPredFlagSet"sv;
	}
	case WeightedBipredFlagSet: {
		return "WeightedBipredFlagSet"sv;
	}
	case Log2ParallelMergeLevelMinus2: {
		return "Log2ParallelMergeLevelMinus2"sv;
	}
	case SignDataHidingEnabledFlagSet: {
		return "SignDataHidingEnabledFlagSet"sv;
	}
	case TransformSkipEnabledFlagSet: {
		return "TransformSkipEnabledFlagSet"sv;
	}
	case TransformSkipEnabledFlagUnset: {
		return "TransformSkipEnabledFlagUnset"sv;
	}
	case PpsSliceChromaQpOffsetsPresentFlagSet: {
		return "PpsSliceChromaQpOffsetsPresentFlagSet"sv;
	}
	case TransquantBypassEnabledFlagSet: {
		return "TransquantBypassEnabledFlagSet"sv;
	}
	case ConstrainedIntraPredFlagSet: {
		return "ConstrainedIntraPredFlagSet"sv;
	}
	case EntropyCodingSyncEnabledFlagSet: {
		return "EntropyCodingSyncEnabledFlagSet"sv;
	}
	case DeblockingFilterOverrideEnabledFlagSet: {
		return "DeblockingFilterOverrideEnabledFlagSet"sv;
	}
	case DependentSliceSegmentsEnabledFlagSet: {
		return "DependentSliceSegmentsEnabledFlagSet"sv;
	}
	case DependentSliceSegmentFlagSet: {
		return "DependentSliceSegmentFlagSet"sv;
	}
	case SliceQpDelta: {
		return "SliceQpDelta"sv;
	}
	case DifferentSliceQpDelta: {
		return "DifferentSliceQpDelta"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH265StdBitsKHR";
}
template<> auto bitToString(VideoEncodeH265TransformBlockSizeBitsKHR bit) -> std::string_view {
	using enum VideoEncodeH265TransformBlockSizeBitsKHR;
	switch (bit) {
	case v4: {
		return "v4"sv;
	}
	case v8: {
		return "v8"sv;
	}
	case v16: {
		return "v16"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeH265TransformBlockSizeBitsKHR";
}
template<> auto bitToString(VideoEncodeIntraRefreshModeBitsKHR bit) -> std::string_view {
	using enum VideoEncodeIntraRefreshModeBitsKHR;
	switch (bit) {
	case None: {
		return "None"sv;
	}
	case PerPicturePartition: {
		return "PerPicturePartition"sv;
	}
	case BlockBased: {
		return "BlockBased"sv;
	}
	case BlockRowBased: {
		return "BlockRowBased"sv;
	}
	case BlockColumnBased: {
		return "BlockColumnBased"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeIntraRefreshModeBitsKHR";
}
template<> auto bitToString(VideoEncodePerPartitionFeedbackBitsKHR bit) -> std::string_view {
	using enum VideoEncodePerPartitionFeedbackBitsKHR;
	switch (bit) {
	case Status: {
		return "Status"sv;
	}
	case BitstreamBufferOffset: {
		return "BitstreamBufferOffset"sv;
	}
	case BitstreamBytesWritten: {
		return "BitstreamBytesWritten"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodePerPartitionFeedbackBitsKHR";
}
template<> auto bitToString(VideoEncodeRateControlBitsKHR bit) -> std::string_view {
	using enum VideoEncodeRateControlBitsKHR;
	switch (bit) {
	}
	return "bit not part of: VideoEncodeRateControlBitsKHR";
}
template<> auto bitToString(VideoEncodeRateControlModeBitsKHR bit) -> std::string_view {
	using enum VideoEncodeRateControlModeBitsKHR;
	switch (bit) {
	case Default: {
		return "Default"sv;
	}
	case Disabled: {
		return "Disabled"sv;
	}
	case Cbr: {
		return "Cbr"sv;
	}
	case Vbr: {
		return "Vbr"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeRateControlModeBitsKHR";
}
template<> auto bitToString(VideoEncodeRgbChromaOffsetBitsVALVE bit) -> std::string_view {
	using enum VideoEncodeRgbChromaOffsetBitsVALVE;
	switch (bit) {
	case CositedEven: {
		return "CositedEven"sv;
	}
	case Midpoint: {
		return "Midpoint"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeRgbChromaOffsetBitsVALVE";
}
template<> auto bitToString(VideoEncodeRgbModelConversionBitsVALVE bit) -> std::string_view {
	using enum VideoEncodeRgbModelConversionBitsVALVE;
	switch (bit) {
	case RgbIdentity: {
		return "RgbIdentity"sv;
	}
	case YcbcrIdentity: {
		return "YcbcrIdentity"sv;
	}
	case Ycbcr709: {
		return "Ycbcr709"sv;
	}
	case Ycbcr601: {
		return "Ycbcr601"sv;
	}
	case Ycbcr2020: {
		return "Ycbcr2020"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeRgbModelConversionBitsVALVE";
}
template<> auto bitToString(VideoEncodeRgbRangeCompressionBitsVALVE bit) -> std::string_view {
	using enum VideoEncodeRgbRangeCompressionBitsVALVE;
	switch (bit) {
	case FullRange: {
		return "FullRange"sv;
	}
	case NarrowRange: {
		return "NarrowRange"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeRgbRangeCompressionBitsVALVE";
}
template<> auto bitToString(VideoEncodeUsageBitsKHR bit) -> std::string_view {
	using enum VideoEncodeUsageBitsKHR;
	switch (bit) {
	case Default: {
		return "Default"sv;
	}
	case Transcoding: {
		return "Transcoding"sv;
	}
	case Streaming: {
		return "Streaming"sv;
	}
	case Recording: {
		return "Recording"sv;
	}
	case Conferencing: {
		return "Conferencing"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoEncodeUsageBitsKHR";
}
template<> auto bitToString(VideoEndCodingBitsKHR bit) -> std::string_view {
	using enum VideoEndCodingBitsKHR;
	switch (bit) {
	}
	return "bit not part of: VideoEndCodingBitsKHR";
}
template<> auto bitToString(VideoSessionCreateBitsKHR bit) -> std::string_view {
	using enum VideoSessionCreateBitsKHR;
	switch (bit) {
	case ProtectedContent: {
		return "ProtectedContent"sv;
	}
	case AllowEncodeParameterOptimizations: {
		return "AllowEncodeParameterOptimizations"sv;
	}
	case InlineQueries: {
		return "InlineQueries"sv;
	}
	case AllowEncodeQuantizationDeltaMap: {
		return "AllowEncodeQuantizationDeltaMap"sv;
	}
	case AllowEncodeEmphasisMap: {
		return "AllowEncodeEmphasisMap"sv;
	}
	case InlineSessionParameters: {
		return "InlineSessionParameters"sv;
	}
	case AllBits: {
		return "AllBits is no single bit value to pass arount"sv;
	}
	}
	return "bit not part of: VideoSessionCreateBitsKHR";
}
template<> auto bitToString(VideoSessionParametersCreateBitsKHR bit) -> std::string_view {
	using enum VideoSessionParametersCreateBitsKHR;
	switch (bit) {
	case QuantizationMapCompatible: {
		return "QuantizationMapCompatible"sv;
	}
	}
	return "bit not part of: VideoSessionParametersCreateBitsKHR";
}
template<> auto bitToString(WaylandSurfaceCreateBitsKHR bit) -> std::string_view {
	using enum WaylandSurfaceCreateBitsKHR;
	switch (bit) {
	}
	return "bit not part of: WaylandSurfaceCreateBitsKHR";
}
template<> auto bitToString(Win32SurfaceCreateBitsKHR bit) -> std::string_view {
	using enum Win32SurfaceCreateBitsKHR;
	switch (bit) {
	}
	return "bit not part of: Win32SurfaceCreateBitsKHR";
}
template<> auto bitToString(XcbSurfaceCreateBitsKHR bit) -> std::string_view {
	using enum XcbSurfaceCreateBitsKHR;
	switch (bit) {
	}
	return "bit not part of: XcbSurfaceCreateBitsKHR";
}
template<> auto bitToString(XlibSurfaceCreateBitsKHR bit) -> std::string_view {
	using enum XlibSurfaceCreateBitsKHR;
	switch (bit) {
	}
	return "bit not part of: XlibSurfaceCreateBitsKHR";
}
// NOLINTEND(readability-function-size)
} // namespace VkBindings::Reflections
