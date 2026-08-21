#pragma once

#include "VkBindings/private/EnumFlagsTemplate.hpp"

#include <cstdint>

namespace VkBindings {
// NOLINTBEGIN(performance-enum-size)
enum class AccelerationStructureBuildTypeKHR : std::int32_t {
	Host         =          0,
	Device       =          1,
	HostOrDevice =          2,
};
enum class AccelerationStructureCompatibilityKHR : std::int32_t {
	Compatible   =          0,
	Incompatible =          1,
};
enum class AccelerationStructureCreateBitsKHR : std::int32_t {
	DeviceAddressCaptureReplay          = 0x00000001,
	MotionBitNV                         = 0x00000004,
	DescriptorBufferCaptureReplayBitEXT = 0x00000008,
	AllBits                             = 0x0000000d, // generated for ~(not), error checking and for convenience
};
using AccelerationStructureCreateFlagsKHR = impl_Enum::Flags<AccelerationStructureCreateBitsKHR>;
enum class AccelerationStructureMemoryRequirementsTypeNV : std::int32_t {
	Object        =          0,
	BuildScratch  =          1,
	UpdateScratch =          2,
};
enum class AccelerationStructureMotionInfoBitsNV : std::int32_t {};
using AccelerationStructureMotionInfoFlagsNV = impl_Enum::Flags<AccelerationStructureMotionInfoBitsNV>;
enum class AccelerationStructureMotionInstanceBitsNV : std::int32_t {};
using AccelerationStructureMotionInstanceFlagsNV = impl_Enum::Flags<AccelerationStructureMotionInstanceBitsNV>;
enum class AccelerationStructureMotionInstanceTypeNV : std::int32_t {
	Static       =          0,
	MatrixMotion =          1,
	SrtMotion    =          2,
};
enum class AccelerationStructureSerializedBlockTypeKHR : std::int32_t {
	OpacityMicromap =          0,
};
enum class AccelerationStructureTypeKHR : std::int32_t {
	TopLevel        =          0,
	BottomLevel     =          1,
	Generic         =          2,
	OpacityMicromap = 1000623000,
};
enum class AccessBits : std::int32_t {
	None                                    = 0x00000000,
	IndirectCommandRead                     = 0x00000001, // Controls coherency of indirect command reads
	IndexRead                               = 0x00000002, // Controls coherency of index reads
	VertexAttributeRead                     = 0x00000004, // Controls coherency of vertex attribute reads
	UniformRead                             = 0x00000008, // Controls coherency of uniform buffer reads
	InputAttachmentRead                     = 0x00000010, // Controls coherency of input attachment reads
	ShaderRead                              = 0x00000020, // Controls coherency of shader reads
	ShaderWrite                             = 0x00000040, // Controls coherency of shader writes
	ColorAttachmentRead                     = 0x00000080, // Controls coherency of color attachment reads
	ColorAttachmentWrite                    = 0x00000100, // Controls coherency of color attachment writes
	DepthStencilAttachmentRead              = 0x00000200, // Controls coherency of depth/stencil attachment reads
	DepthStencilAttachmentWrite             = 0x00000400, // Controls coherency of depth/stencil attachment writes
	TransferRead                            = 0x00000800, // Controls coherency of transfer reads
	TransferWrite                           = 0x00001000, // Controls coherency of transfer writes
	HostRead                                = 0x00002000, // Controls coherency of host reads
	HostWrite                               = 0x00004000, // Controls coherency of host writes
	MemoryRead                              = 0x00008000, // Controls coherency of memory reads
	MemoryWrite                             = 0x00010000, // Controls coherency of memory writes
	CommandPreprocessReadBitEXT             = 0x00020000,
	CommandPreprocessWriteBitEXT            = 0x00040000,
	ColorAttachmentReadNoncoherentBitEXT    = 0x00080000,
	ConditionalRenderingReadBitEXT          = 0x00100000, // read access flag for reading conditional rendering predicate
	AccelerationStructureReadBitKHR         = 0x00200000,
	AccelerationStructureWriteBitKHR        = 0x00400000,
	FragmentShadingRateAttachmentReadBitKHR = 0x00800000,
	FragmentDensityMapReadBitEXT            = 0x01000000,
	TransformFeedbackWriteBitEXT            = 0x02000000,
	TransformFeedbackCounterReadBitEXT      = 0x04000000,
	TransformFeedbackCounterWriteBitEXT     = 0x08000000,
	AllBits                                 = 0x0fffffff, // generated for ~(not), error checking and for convenience
};
using AccessFlags = impl_Enum::Flags<AccessBits>;
enum class AccessBits2 : std::uint64_t {
	None                                    = 0x0000000000000000,
	IndirectCommandRead                     = 0x0000000000000001,
	IndexRead                               = 0x0000000000000002,
	VertexAttributeRead                     = 0x0000000000000004,
	UniformRead                             = 0x0000000000000008,
	InputAttachmentRead                     = 0x0000000000000010,
	ShaderRead                              = 0x0000000000000020,
	ShaderWrite                             = 0x0000000000000040,
	ColorAttachmentRead                     = 0x0000000000000080,
	ColorAttachmentWrite                    = 0x0000000000000100,
	DepthStencilAttachmentRead              = 0x0000000000000200,
	DepthStencilAttachmentWrite             = 0x0000000000000400,
	TransferRead                            = 0x0000000000000800,
	TransferWrite                           = 0x0000000000001000,
	HostRead                                = 0x0000000000002000,
	HostWrite                               = 0x0000000000004000,
	MemoryRead                              = 0x0000000000008000,
	MemoryWrite                             = 0x0000000000010000,
	CommandPreprocessReadBitEXT             = 0x0000000000020000,
	CommandPreprocessWriteBitEXT            = 0x0000000000040000,
	ColorAttachmentReadNoncoherentBitEXT    = 0x0000000000080000,
	ConditionalRenderingReadBitEXT          = 0x0000000000100000, // read access flag for reading conditional rendering predicate
	AccelerationStructureReadBitKHR         = 0x0000000000200000,
	AccelerationStructureWriteBitKHR        = 0x0000000000400000,
	FragmentShadingRateAttachmentReadBitKHR = 0x0000000000800000,
	FragmentDensityMapReadBitEXT            = 0x0000000001000000,
	TransformFeedbackWriteBitEXT            = 0x0000000002000000,
	TransformFeedbackCounterReadBitEXT      = 0x0000000004000000,
	TransformFeedbackCounterWriteBitEXT     = 0x0000000008000000,
	ShaderSampledRead                       = 0x0000000100000000,
	ShaderStorageRead                       = 0x0000000200000000,
	ShaderStorageWrite                      = 0x0000000400000000,
	VideoDecodeReadBitKHR                   = 0x0000000800000000,
	VideoDecodeWriteBitKHR                  = 0x0000001000000000,
	VideoEncodeReadBitKHR                   = 0x0000002000000000,
	VideoEncodeWriteBitKHR                  = 0x0000004000000000,
	InvocationMaskReadBitHUAWEI             = 0x0000008000000000,
	ShaderBindingTableReadBitKHR            = 0x0000010000000000,
	DescriptorBufferReadBitEXT              = 0x0000020000000000,
	OpticalFlowReadBitNV                    = 0x0000040000000000,
	OpticalFlowWriteBitNV                   = 0x0000080000000000,
	MicromapReadBitEXT                      = 0x0000100000000000,
	MicromapWriteBitEXT                     = 0x0000200000000000,
	DataGraphReadBitARM                     = 0x0000800000000000,
	DataGraphWriteBitARM                    = 0x0001000000000000,
	ShaderTileAttachmentReadBitQCOM         = 0x0008000000000000,
	ShaderTileAttachmentWriteBitQCOM        = 0x0010000000000000,
	MemoryDecompressionReadBitEXT           = 0x0080000000000000,
	MemoryDecompressionWriteBitEXT          = 0x0100000000000000,
	SamplerHeapReadBitEXT                   = 0x0200000000000000,
	ResourceHeapReadBitEXT                  = 0x0400000000000000,
	AllBits                                 = 0x0799bfff0fffffff, // generated for ~(not), error checking and for convenience
};
using AccessFlags2 = impl_Enum::Flags<AccessBits2>;
enum class AccessBits3KHR : std::uint64_t {
	None = 0x0000000000000000,
};
using AccessFlags3KHR = impl_Enum::Flags<AccessBits3KHR>;
enum class AcquireProfilingLockBitsKHR : std::int32_t {};
using AcquireProfilingLockFlagsKHR = impl_Enum::Flags<AcquireProfilingLockBitsKHR>;
enum class AddressCommandBitsKHR : std::int32_t {
	Protected                           = 0x00000001,
	FullyBound                          = 0x00000002,
	StorageBufferUsage                  = 0x00000004,
	UnknownStorageBufferUsage           = 0x00000008,
	TransformFeedbackBufferUsage        = 0x00000010,
	UnknownTransformFeedbackBufferUsage = 0x00000020,
	AllBits                             = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using AddressCommandFlagsKHR = impl_Enum::Flags<AddressCommandBitsKHR>;
enum class AddressCopyBitsKHR : std::int32_t {
	DeviceLocal = 0x00000001,
	Sparse      = 0x00000002,
	Protected   = 0x00000004,
	AllBits     = 0x00000007, // generated for ~(not), error checking and for convenience
};
using AddressCopyFlagsKHR = impl_Enum::Flags<AddressCopyBitsKHR>;
enum class AndroidSurfaceCreateBitsKHR : std::int32_t {};
using AndroidSurfaceCreateFlagsKHR = impl_Enum::Flags<AndroidSurfaceCreateBitsKHR>;
enum class AntiLagModeAMD : std::int32_t {
	DriverControl =          0,
	On            =          1,
	Off           =          2,
};
enum class AntiLagStageAMD : std::int32_t {
	Input   =          0,
	Present =          1,
};
enum class AttachmentDescriptionBits : std::int32_t {
	MayAlias                            = 0x00000001, // The attachment may alias physical memory of another attachment in the same render pass
	ResolveSkipTransferFunctionBitKHR   = 0x00000002,
	ResolveEnableTransferFunctionBitKHR = 0x00000004,
	AllBits                             = 0x00000007, // generated for ~(not), error checking and for convenience
};
using AttachmentDescriptionFlags = impl_Enum::Flags<AttachmentDescriptionBits>;
enum class AttachmentLoadOp : std::int32_t {
	Load     =          0,
	Clear    =          1,
	DontCare =          2,
	None     = 1000400000,
};
enum class AttachmentStoreOp : std::int32_t {
	Store    =          0,
	DontCare =          1,
	None     = 1000301000,
};
enum class BlendFactor : std::int32_t {
	Zero                  =          0,
	One                   =          1,
	SrcColor              =          2,
	OneMinusSrcColor      =          3,
	DstColor              =          4,
	OneMinusDstColor      =          5,
	SrcAlpha              =          6,
	OneMinusSrcAlpha      =          7,
	DstAlpha              =          8,
	OneMinusDstAlpha      =          9,
	ConstantColor         =         10,
	OneMinusConstantColor =         11,
	ConstantAlpha         =         12,
	OneMinusConstantAlpha =         13,
	SrcAlphaSaturate      =         14,
	Src1Color             =         15,
	OneMinusSrc1Color     =         16,
	Src1Alpha             =         17,
	OneMinusSrc1Alpha     =         18,
};
enum class BlendOp : std::int32_t {
	Add                 =          0,
	Subtract            =          1,
	ReverseSubtract     =          2,
	Min                 =          3,
	Max                 =          4,
	ZeroEXT             = 1000148000,
	SrcEXT              = 1000148001,
	DstEXT              = 1000148002,
	SrcOverEXT          = 1000148003,
	DstOverEXT          = 1000148004,
	SrcInEXT            = 1000148005,
	DstInEXT            = 1000148006,
	SrcOutEXT           = 1000148007,
	DstOutEXT           = 1000148008,
	SrcAtopEXT          = 1000148009,
	DstAtopEXT          = 1000148010,
	XorEXT              = 1000148011,
	MultiplyEXT         = 1000148012,
	ScreenEXT           = 1000148013,
	OverlayEXT          = 1000148014,
	DarkenEXT           = 1000148015,
	LightenEXT          = 1000148016,
	ColordodgeEXT       = 1000148017,
	ColorburnEXT        = 1000148018,
	HardlightEXT        = 1000148019,
	SoftlightEXT        = 1000148020,
	DifferenceEXT       = 1000148021,
	ExclusionEXT        = 1000148022,
	InvertEXT           = 1000148023,
	InvertRgbEXT        = 1000148024,
	LineardodgeEXT      = 1000148025,
	LinearburnEXT       = 1000148026,
	VividlightEXT       = 1000148027,
	LinearlightEXT      = 1000148028,
	PinlightEXT         = 1000148029,
	HardmixEXT          = 1000148030,
	HslHueEXT           = 1000148031,
	HslSaturationEXT    = 1000148032,
	HslColorEXT         = 1000148033,
	HslLuminosityEXT    = 1000148034,
	PlusEXT             = 1000148035,
	PlusClampedEXT      = 1000148036,
	PlusClampedAlphaEXT = 1000148037,
	PlusDarkerEXT       = 1000148038,
	MinusEXT            = 1000148039,
	MinusClampedEXT     = 1000148040,
	ContrastEXT         = 1000148041,
	InvertOvgEXT        = 1000148042,
	RedEXT              = 1000148043,
	GreenEXT            = 1000148044,
	BlueEXT             = 1000148045,
};
enum class BlendOverlapEXT : std::int32_t {
	Uncorrelated =          0,
	Disjoint     =          1,
	Conjoint     =          2,
};
enum class BlockMatchWindowCompareModeQCOM : std::int32_t {
	Min =          0,
	Max =          1,
};
enum class BorderColor : std::int32_t {
	FloatTransparentBlack =          0,
	IntTransparentBlack   =          1,
	FloatOpaqueBlack      =          2,
	IntOpaqueBlack        =          3,
	FloatOpaqueWhite      =          4,
	IntOpaqueWhite        =          5,
	FloatCustomEXT        = 1000287003,
	IntCustomEXT          = 1000287004,
};
enum class BufferCreateBits : std::int32_t {
	SparseBinding                       = 0x00000001, // Buffer should support sparse backing
	SparseResidency                     = 0x00000002, // Buffer should support sparse backing with partial residency
	SparseAliased                       = 0x00000004, // Buffer should support constant data access to physical memory ranges mapped into multiple locations of sparse buffers
	Protected                           = 0x00000008, // Buffer requires protected memory
	DeviceAddressCaptureReplay          = 0x00000010,
	DescriptorBufferCaptureReplayBitEXT = 0x00000020,
	VideoProfileIndependentBitKHR       = 0x00000040,
	AllBits                             = 0x0000007f, // generated for ~(not), error checking and for convenience
};
using BufferCreateFlags = impl_Enum::Flags<BufferCreateBits>;
enum class BufferUsageBits : std::int32_t {
	TransferSrc                                   = 0x00000001, // Can be used as a source of transfer operations
	TransferDst                                   = 0x00000002, // Can be used as a destination of transfer operations
	UniformTexelBuffer                            = 0x00000004, // Can be used as TBO
	StorageTexelBuffer                            = 0x00000008, // Can be used as IBO
	UniformBuffer                                 = 0x00000010, // Can be used as UBO
	StorageBuffer                                 = 0x00000020, // Can be used as SSBO
	IndexBuffer                                   = 0x00000040, // Can be used as source of fixed-function index fetch (index buffer)
	VertexBuffer                                  = 0x00000080, // Can be used as source of fixed-function vertex fetch (VBO)
	IndirectBuffer                                = 0x00000100, // Can be the source of indirect parameters (e.g. indirect buffer, parameter buffer)
	ConditionalRenderingBitEXT                    = 0x00000200, // Specifies the buffer can be used as predicate in conditional rendering
	ShaderBindingTableBitKHR                      = 0x00000400,
	TransformFeedbackBufferBitEXT                 = 0x00000800,
	TransformFeedbackCounterBufferBitEXT          = 0x00001000,
	VideoDecodeSrcBitKHR                          = 0x00002000,
	VideoDecodeDstBitKHR                          = 0x00004000,
	VideoEncodeDstBitKHR                          = 0x00008000,
	VideoEncodeSrcBitKHR                          = 0x00010000,
	ShaderDeviceAddress                           = 0x00020000,
	AccelerationStructureBuildInputReadOnlyBitKHR = 0x00080000,
	AccelerationStructureStorageBitKHR            = 0x00100000,
	SamplerDescriptorBufferBitEXT                 = 0x00200000,
	ResourceDescriptorBufferBitEXT                = 0x00400000,
	MicromapBuildInputReadOnlyBitEXT              = 0x00800000,
	MicromapStorageBitEXT                         = 0x01000000,
	ExecutionGraphScratchBitAMDX                  = 0x02000000,
	PushDescriptorsDescriptorBufferBitEXT         = 0x04000000,
	TileMemoryBitQCOM                             = 0x08000000,
	DescriptorHeapBitEXT                          = 0x10000000,
	AllBits                                       = 0x1ffbffff, // generated for ~(not), error checking and for convenience
};
using BufferUsageFlags = impl_Enum::Flags<BufferUsageBits>;
enum class BufferUsageBits2 : std::uint64_t {
	TransferSrc                                   = 0x0000000000000001,
	TransferDst                                   = 0x0000000000000002,
	UniformTexelBuffer                            = 0x0000000000000004,
	StorageTexelBuffer                            = 0x0000000000000008,
	UniformBuffer                                 = 0x0000000000000010,
	StorageBuffer                                 = 0x0000000000000020,
	IndexBuffer                                   = 0x0000000000000040,
	VertexBuffer                                  = 0x0000000000000080,
	IndirectBuffer                                = 0x0000000000000100,
	ConditionalRenderingBitEXT                    = 0x0000000000000200,
	ShaderBindingTableBitKHR                      = 0x0000000000000400,
	TransformFeedbackBufferBitEXT                 = 0x0000000000000800,
	TransformFeedbackCounterBufferBitEXT          = 0x0000000000001000,
	VideoDecodeSrcBitKHR                          = 0x0000000000002000,
	VideoDecodeDstBitKHR                          = 0x0000000000004000,
	VideoEncodeDstBitKHR                          = 0x0000000000008000,
	VideoEncodeSrcBitKHR                          = 0x0000000000010000,
	ShaderDeviceAddress                           = 0x0000000000020000,
	AccelerationStructureBuildInputReadOnlyBitKHR = 0x0000000000080000,
	AccelerationStructureStorageBitKHR            = 0x0000000000100000,
	SamplerDescriptorBufferBitEXT                 = 0x0000000000200000,
	ResourceDescriptorBufferBitEXT                = 0x0000000000400000,
	MicromapBuildInputReadOnlyBitEXT              = 0x0000000000800000,
	MicromapStorageBitEXT                         = 0x0000000001000000,
	ExecutionGraphScratchBitAMDX                  = 0x0000000002000000,
	PushDescriptorsDescriptorBufferBitEXT         = 0x0000000004000000,
	TileMemoryBitQCOM                             = 0x0000000008000000,
	DescriptorHeapBitEXT                          = 0x0000000010000000,
	DataGraphForeignDescriptorBitARM              = 0x0000000020000000,
	PreprocessBufferBitEXT                        = 0x0000000080000000,
	MemoryDecompressionBitEXT                     = 0x0000000100000000,
	CompressedDataDgf1BitAMDX                     = 0x0000000200000000,
	AllBits                                       = 0x00000003bffbffff, // generated for ~(not), error checking and for convenience
};
using BufferUsageFlags2 = impl_Enum::Flags<BufferUsageBits2>;
enum class BufferViewCreateBits : std::int32_t {};
using BufferViewCreateFlags = impl_Enum::Flags<BufferViewCreateBits>;
enum class BuildAccelerationStructureBitsKHR : std::int32_t {
	AllowUpdate                          = 0x00000001,
	AllowCompaction                      = 0x00000002,
	PreferFastTrace                      = 0x00000004,
	PreferFastBuild                      = 0x00000008,
	LowMemory                            = 0x00000010,
	MotionBitNV                          = 0x00000020,
	AllowOpacityMicromapUpdate           = 0x00000040,
	AllowDisableOpacityMicromaps         = 0x00000080,
	AllowOpacityMicromapDataUpdateBitEXT = 0x00000100,
	AllowDisplacementMicromapUpdateBitNV = 0x00000200,
	MicromapLossy                        = 0x00000400,
	AllowDataAccess                      = 0x00000800,
	AllowClusterOpacityMicromapsBitNV    = 0x00001000,
	AllBits                              = 0x00001fff, // generated for ~(not), error checking and for convenience
};
using BuildAccelerationStructureFlagsKHR = impl_Enum::Flags<BuildAccelerationStructureBitsKHR>;
enum class BuildAccelerationStructureModeKHR : std::int32_t {
	Build  =          0,
	Update =          1,
};
enum class BuildMicromapBitsEXT : std::int32_t {
	PreferFastTrace = 0x00000001,
	PreferFastBuild = 0x00000002,
	AllowCompaction = 0x00000004,
	AllBits         = 0x00000007, // generated for ~(not), error checking and for convenience
};
using BuildMicromapFlagsEXT = impl_Enum::Flags<BuildMicromapBitsEXT>;
enum class BuildMicromapModeEXT : std::int32_t {
	Build =          0,
};
enum class ChromaLocation : std::int32_t {
	CositedEven =          0,
	Midpoint    =          1,
};
enum class ClusterAccelerationStructureAddressResolutionBitsNV : std::int32_t {
	None                      = 0x00000000,
	IndirectedDstImplicitData = 0x00000001,
	IndirectedScratchData     = 0x00000002,
	IndirectedDstAddressArray = 0x00000004,
	IndirectedDstSizesArray   = 0x00000008,
	IndirectedSrcInfosArray   = 0x00000010,
	IndirectedSrcInfosCount   = 0x00000020,
	AllBits                   = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using ClusterAccelerationStructureAddressResolutionFlagsNV = impl_Enum::Flags<ClusterAccelerationStructureAddressResolutionBitsNV>;
enum class ClusterAccelerationStructureClusterBitsNV : std::int32_t {
	AllowDisableOpacityMicromaps = 0x00000001,
	AllBits                      = 0x00000001, // generated for ~(not), error checking and for convenience
};
using ClusterAccelerationStructureClusterFlagsNV = impl_Enum::Flags<ClusterAccelerationStructureClusterBitsNV>;
enum class ClusterAccelerationStructureGeometryBitsNV : std::int32_t {
	CullDisable                 = 0x00000001,
	NoDuplicateAnyhitInvocation = 0x00000002,
	Opaque                      = 0x00000004,
	AllBits                     = 0x00000007, // generated for ~(not), error checking and for convenience
};
using ClusterAccelerationStructureGeometryFlagsNV = impl_Enum::Flags<ClusterAccelerationStructureGeometryBitsNV>;
enum class ClusterAccelerationStructureIndexFormatBitsNV : std::int32_t {
	v8      = 0x00000001,
	v16     = 0x00000002,
	v32     = 0x00000004,
	AllBits = 0x00000007, // generated for ~(not), error checking and for convenience
};
using ClusterAccelerationStructureIndexFormatFlagsNV = impl_Enum::Flags<ClusterAccelerationStructureIndexFormatBitsNV>;
enum class ClusterAccelerationStructureOpModeNV : std::int32_t {
	ImplicitDestinations =          0,
	ExplicitDestinations =          1,
	ComputeSizes         =          2,
};
enum class ClusterAccelerationStructureOpTypeNV : std::int32_t {
	MoveObjects                  =          0,
	BuildClustersBottomLevel     =          1,
	BuildTriangleCluster         =          2,
	BuildTriangleClusterTemplate =          3,
	InstantiateTriangleCluster   =          4,
	GetClusterTemplateIndices    =          5,
};
enum class ClusterAccelerationStructureTypeNV : std::int32_t {
	ClustersBottomLevel     =          0,
	TriangleCluster         =          1,
	TriangleClusterTemplate =          2,
};
enum class CoarseSampleOrderTypeNV : std::int32_t {
	Default     =          0,
	Custom      =          1,
	PixelMajor  =          2,
	SampleMajor =          3,
};
enum class ColorComponentBits : std::int32_t {
	R       = 0x00000001,
	G       = 0x00000002,
	B       = 0x00000004,
	A       = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using ColorComponentFlags = impl_Enum::Flags<ColorComponentBits>;
enum class ColorSpaceKHR : std::int32_t {
	SrgbNonlinear            =          0,
	DisplayP3NonlinearEXT    = 1000104001,
	ExtendedSrgbLinearEXT    = 1000104002,
	DisplayP3LinearEXT       = 1000104003,
	DciP3NonlinearEXT        = 1000104004,
	Bt709LinearEXT           = 1000104005,
	Bt709NonlinearEXT        = 1000104006,
	Bt2020LinearEXT          = 1000104007,
	Hdr10St2084EXT           = 1000104008,
	DolbyvisionEXT           = 1000104009,
	Hdr10HlgEXT              = 1000104010,
	AdobergbLinearEXT        = 1000104011,
	AdobergbNonlinearEXT     = 1000104012,
	PassThroughEXT           = 1000104013,
	ExtendedSrgbNonlinearEXT = 1000104014,
	DisplayNativeAMD         = 1000213000,
};
enum class CommandBufferLevel : std::int32_t {
	Primary   =          0,
	Secondary =          1,
};
enum class CommandBufferResetBits : std::int32_t {
	ReleaseResources = 0x00000001, // Release resources owned by the buffer
	AllBits          = 0x00000001, // generated for ~(not), error checking and for convenience
};
using CommandBufferResetFlags = impl_Enum::Flags<CommandBufferResetBits>;
enum class CommandBufferUsageBits : std::int32_t {
	OneTimeSubmit      = 0x00000001,
	RenderPassContinue = 0x00000002,
	SimultaneousUse    = 0x00000004, // Command buffer may be submitted/executed more than once simultaneously
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
using CommandBufferUsageFlags = impl_Enum::Flags<CommandBufferUsageBits>;
enum class CommandPoolCreateBits : std::int32_t {
	Transient          = 0x00000001, // Command buffers have a short lifetime
	ResetCommandBuffer = 0x00000002, // Command buffers may release their memory individually
	Protected          = 0x00000004, // Command buffers allocated from pool are protected command buffers
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
using CommandPoolCreateFlags = impl_Enum::Flags<CommandPoolCreateBits>;
enum class CommandPoolResetBits : std::int32_t {
	ReleaseResources = 0x00000001, // Release resources owned by the pool
	AllBits          = 0x00000001, // generated for ~(not), error checking and for convenience
};
using CommandPoolResetFlags = impl_Enum::Flags<CommandPoolResetBits>;
enum class CommandPoolTrimBits : std::int32_t {};
using CommandPoolTrimFlags = impl_Enum::Flags<CommandPoolTrimBits>;
enum class CompareOp : std::int32_t {
	Never          =          0,
	Less           =          1,
	Equal          =          2,
	LessOrEqual    =          3,
	Greater        =          4,
	NotEqual       =          5,
	GreaterOrEqual =          6,
	Always         =          7,
};
enum class ComponentSwizzle : std::int32_t {
	Identity =          0,
	Zero     =          1,
	One      =          2,
	R        =          3,
	G        =          4,
	B        =          5,
	A        =          6,
};
enum class ComponentTypeKHR : std::int32_t {
	Float16               =          0,
	Float32               =          1,
	Float64               =          2,
	Sint8                 =          3,
	Sint16                =          4,
	Sint32                =          5,
	Sint64                =          6,
	Uint8                 =          7,
	Uint16                =          8,
	Uint32                =          9,
	Uint64                =         10,
	Bfloat16              = 1000141000,
	Sint8PackedNV         = 1000491000,
	Uint8PackedNV         = 1000491001,
	Float8E4M3EXT         = 1000491002,
	Float8E5M2EXT         = 1000491003,
	Float6E2M3EXT         = 1000672000,
	Float6E3M2EXT         = 1000672001,
	Float4E2M1EXT         = 1000672002,
	Float8UnsignedE8M0EXT = 1000672003,
	Mxint8EXT             = 1000672004,
};
enum class CompositeAlphaBitsKHR : std::int32_t {
	Opaque         = 0x00000001,
	PreMultiplied  = 0x00000002,
	PostMultiplied = 0x00000004,
	Inherit        = 0x00000008,
	AllBits        = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using CompositeAlphaFlagsKHR = impl_Enum::Flags<CompositeAlphaBitsKHR>;
enum class CompressedTriangleFormatAMDX : std::int32_t {
	Dgf1 =          0,
};
enum class ConditionalRenderingBitsEXT : std::int32_t {
	Inverted = 0x00000001,
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
using ConditionalRenderingFlagsEXT = impl_Enum::Flags<ConditionalRenderingBitsEXT>;
enum class ConservativeRasterizationModeEXT : std::int32_t {
	Disabled      =          0,
	Overestimate  =          1,
	Underestimate =          2,
};
enum class CooperativeVectorMatrixLayoutNV : std::int32_t {
	RowMajor           =          0,
	ColumnMajor        =          1,
	InferencingOptimal =          2,
	TrainingOptimal    =          3,
};
enum class CopyAccelerationStructureModeKHR : std::int32_t {
	Clone       =          0,
	Compact     =          1,
	Serialize   =          2,
	Deserialize =          3,
};
enum class CopyMicromapModeEXT : std::int32_t {
	Clone       =          0,
	Serialize   =          1,
	Deserialize =          2,
	Compact     =          3,
};
enum class CoverageModulationModeNV : std::int32_t {
	None  =          0,
	Rgb   =          1,
	Alpha =          2,
	Rgba  =          3,
};
enum class CoverageReductionModeNV : std::int32_t {
	Merge    =          0,
	Truncate =          1,
};
enum class CubicFilterWeightsQCOM : std::int32_t {
	CatmullRom          =          0,
	ZeroTangentCardinal =          1,
	BSpline             =          2,
	MitchellNetravali   =          3,
};
enum class CullModeBits : std::int32_t {
	None         = 0x00000000,
	Front        = 0x00000001,
	Back         = 0x00000002,
	FrontAndBack = 0x00000003,
	AllBits      = 0x00000003, // generated for ~(not), error checking and for convenience
};
using CullModeFlags = impl_Enum::Flags<CullModeBits>;
enum class DataGraphModelCacheTypeQCOM : std::int32_t {
	GenericBinary =          0,
};
enum class DataGraphOpticalFlowCreateBitsARM : std::int32_t {
	EnableHint = 0x00000001,
	EnableCost = 0x00000002,
	Reserved30 = 0x40000000,
	AllBits    = 0x40000003, // generated for ~(not), error checking and for convenience
};
using DataGraphOpticalFlowCreateFlagsARM = impl_Enum::Flags<DataGraphOpticalFlowCreateBitsARM>;
enum class DataGraphOpticalFlowExecuteBitsARM : std::int32_t {
	DisableTemporalHints     = 0x00000001,
	InputUnchanged           = 0x00000002,
	ReferenceUnchanged       = 0x00000004,
	InputIsPreviousReference = 0x00000008,
	ReferenceIsPreviousInput = 0x00000010,
	AllBits                  = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using DataGraphOpticalFlowExecuteFlagsARM = impl_Enum::Flags<DataGraphOpticalFlowExecuteBitsARM>;
enum class DataGraphOpticalFlowGridSizeBitsARM : std::int32_t {
	Unknown = 0x00000000,
	v1x1    = 0x00000001,
	v2x2    = 0x00000002,
	v4x4    = 0x00000004,
	v8x8    = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DataGraphOpticalFlowGridSizeFlagsARM = impl_Enum::Flags<DataGraphOpticalFlowGridSizeBitsARM>;
enum class DataGraphOpticalFlowImageUsageBitsARM : std::int32_t {
	Unknown = 0x00000000,
	Input   = 0x00000001,
	Output  = 0x00000002,
	Hint    = 0x00000004,
	Cost    = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DataGraphOpticalFlowImageUsageFlagsARM = impl_Enum::Flags<DataGraphOpticalFlowImageUsageBitsARM>;
enum class DataGraphOpticalFlowPerformanceLevelARM : std::int32_t {
	Unknown =          0,
	Slow    =          1,
	Medium  =          2,
	Fast    =          3,
};
enum class DataGraphPipelineDispatchBitsARM : std::uint64_t {};
using DataGraphPipelineDispatchFlagsARM = impl_Enum::Flags<DataGraphPipelineDispatchBitsARM>;
enum class DataGraphPipelineNodeConnectionTypeARM : std::int32_t {
	OpticalFlowInput      = 1000631000,
	OpticalFlowReference  = 1000631001,
	OpticalFlowHint       = 1000631002,
	OpticalFlowFlowVector = 1000631003,
	OpticalFlowCost       = 1000631004,
};
enum class DataGraphPipelineNodeTypeARM : std::int32_t {
	OpticalFlow = 1000631000,
};
enum class DataGraphPipelinePropertyARM : std::int32_t {
	CreationLog                     =          0,
	Identifier                      =          1,
	NeuralAcceleratorDebugDatabase  = 1000676000,
	NeuralAcceleratorStatisticsInfo = 1000676001,
};
enum class DataGraphPipelineSessionBindPointARM : std::int32_t {
	Transient                   =          0,
	OpticalFlowCache            = 1000631001,
	NeuralAcceleratorStatistics = 1000676000,
};
enum class DataGraphPipelineSessionBindPointTypeARM : std::int32_t {
	Memory =          0,
};
enum class DataGraphPipelineSessionCreateBitsARM : std::uint64_t {
	Protected        = 0x0000000000000001,
	OpticalFlowCache = 0x0000000000000002,
	AllBits          = 0x0000000000000003, // generated for ~(not), error checking and for convenience
};
using DataGraphPipelineSessionCreateFlagsARM = impl_Enum::Flags<DataGraphPipelineSessionCreateBitsARM>;
enum class DataGraphTOSALevelARM : std::int32_t {
	DataGraphTosaLevelNone =          0,
	DataGraphTosaLevel8K   =          1,
};
enum class DataGraphTOSAQualityBitsARM : std::int32_t {
	DataGraphTosaQualityAccelerated  = 0x00000001,
	DataGraphTosaQualityConformant   = 0x00000002,
	DataGraphTosaQualityExperimental = 0x00000004,
	DataGraphTosaQualityDeprecated   = 0x00000008,
	AllBits                          = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DataGraphTOSAQualityFlagsARM = impl_Enum::Flags<DataGraphTOSAQualityBitsARM>;
enum class DebugReportBitsEXT : std::int32_t {
	Information        = 0x00000001,
	Warning            = 0x00000002,
	PerformanceWarning = 0x00000004,
	Error              = 0x00000008,
	Debug              = 0x00000010,
	AllBits            = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using DebugReportFlagsEXT = impl_Enum::Flags<DebugReportBitsEXT>;
enum class DebugReportObjectTypeEXT : std::int32_t {
	Unknown                  =          0,
	Instance                 =          1,
	PhysicalDevice           =          2,
	Device                   =          3,
	Queue                    =          4,
	Semaphore                =          5,
	CommandBuffer            =          6,
	Fence                    =          7,
	DeviceMemory             =          8,
	Buffer                   =          9,
	Image                    =         10,
	Event                    =         11,
	QueryPool                =         12,
	BufferView               =         13,
	ImageView                =         14,
	ShaderModule             =         15,
	PipelineCache            =         16,
	PipelineLayout           =         17,
	RenderPass               =         18,
	Pipeline                 =         19,
	DescriptorSetLayout      =         20,
	Sampler                  =         21,
	DescriptorPool           =         22,
	DescriptorSet            =         23,
	Framebuffer              =         24,
	CommandPool              =         25,
	SurfaceKHR               =         26,
	SwapchainKHR             =         27,
	DebugReportCallbackEXT   =         28,
	DisplayKHR               =         29,
	DisplayModeKHR           =         30,
	ValidationCacheEXT       =         33,
	CuModuleNVX              = 1000029000,
	CuFunctionNVX            = 1000029001,
	DescriptorUpdateTemplate = 1000085000,
	AccelerationStructureKHR = 1000150000,
	SamplerYcbcrConversion   = 1000156000,
	AccelerationStructureNV  = 1000165000,
	CudaModuleNV             = 1000307000,
	CudaFunctionNV           = 1000307001,
	BufferCollectionFUCHSIA  = 1000366000,
};
enum class DebugUtilsMessageSeverityBitsEXT : std::int32_t {
	Verbose = 0x00000001,
	Info    = 0x00000010,
	Warning = 0x00000100,
	Error   = 0x00001000,
	AllBits = 0x00001111, // generated for ~(not), error checking and for convenience
};
using DebugUtilsMessageSeverityFlagsEXT = impl_Enum::Flags<DebugUtilsMessageSeverityBitsEXT>;
enum class DebugUtilsMessageTypeBitsEXT : std::int32_t {
	General              = 0x00000001,
	Validation           = 0x00000002,
	Performance          = 0x00000004,
	DeviceAddressBinding = 0x00000008,
	AllBits              = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DebugUtilsMessageTypeFlagsEXT = impl_Enum::Flags<DebugUtilsMessageTypeBitsEXT>;
enum class DebugUtilsMessengerCallbackDataBitsEXT : std::int32_t {};
using DebugUtilsMessengerCallbackDataFlagsEXT = impl_Enum::Flags<DebugUtilsMessengerCallbackDataBitsEXT>;
enum class DebugUtilsMessengerCreateBitsEXT : std::int32_t {};
using DebugUtilsMessengerCreateFlagsEXT = impl_Enum::Flags<DebugUtilsMessengerCreateBitsEXT>;
enum class DefaultVertexAttributeValueKHR : std::int32_t {
	ZeroZeroZeroZero =          0,
	ZeroZeroZeroOne  =          1,
};
enum class DependencyBits : std::int32_t {
	ByRegion                                       = 0x00000001, // Dependency is per pixel region 
	ViewLocal                                      = 0x00000002,
	DeviceGroup                                    = 0x00000004, // Dependency is across devices
	FeedbackLoopBitEXT                             = 0x00000008, // Dependency may be a feedback loop
	QueueFamilyOwnershipTransferUseAllStagesBitKHR = 0x00000020,
	AsymmetricEventBitKHR                          = 0x00000040,
	AllBits                                        = 0x0000006f, // generated for ~(not), error checking and for convenience
};
using DependencyFlags = impl_Enum::Flags<DependencyBits>;
enum class DepthBiasRepresentationEXT : std::int32_t {
	LeastRepresentableValueFormat     =          0,
	LeastRepresentableValueForceUnorm =          1,
	Float                             =          2,
};
enum class DepthClampModeEXT : std::int32_t {
	ViewportRange    =          0,
	UserDefinedRange =          1,
};
enum class DescriptorBindingBits : std::int32_t {
	UpdateAfterBind          = 0x00000001,
	UpdateUnusedWhilePending = 0x00000002,
	PartiallyBound           = 0x00000004,
	VariableDescriptorCount  = 0x00000008,
	AllBits                  = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DescriptorBindingFlags = impl_Enum::Flags<DescriptorBindingBits>;
enum class DescriptorMappingSourceEXT : std::int32_t {
	HeapWithConstantOffset     =          0,
	HeapWithPushIndex          =          1,
	HeapWithIndirectIndex      =          2,
	HeapWithIndirectIndexArray =          3,
	ResourceHeapData           =          4,
	PushData                   =          5,
	PushAddress                =          6,
	IndirectAddress            =          7,
	HeapWithShaderRecordIndex  =          8,
	ShaderRecordData           =          9,
	ShaderRecordAddress        =         10,
};
enum class DescriptorPoolCreateBits : std::int32_t {
	FreeDescriptorSet             = 0x00000001, // Descriptor sets may be freed individually
	UpdateAfterBind               = 0x00000002,
	HostOnlyBitEXT                = 0x00000004,
	AllowOverallocationSetsBitNV  = 0x00000008,
	AllowOverallocationPoolsBitNV = 0x00000010,
	AllBits                       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using DescriptorPoolCreateFlags = impl_Enum::Flags<DescriptorPoolCreateBits>;
enum class DescriptorPoolResetBits : std::int32_t {};
using DescriptorPoolResetFlags = impl_Enum::Flags<DescriptorPoolResetBits>;
enum class DescriptorSetLayoutCreateBits : std::int32_t {
	PushDescriptor                  = 0x00000001,
	UpdateAfterBindPool             = 0x00000002,
	HostOnlyPoolBitEXT              = 0x00000004,
	DescriptorBufferBitEXT          = 0x00000010,
	EmbeddedImmutableSamplersBitEXT = 0x00000020,
	PerStageBitNV                   = 0x00000040,
	IndirectBindableBitNV           = 0x00000080,
	AllBits                         = 0x000000f7, // generated for ~(not), error checking and for convenience
};
using DescriptorSetLayoutCreateFlags = impl_Enum::Flags<DescriptorSetLayoutCreateBits>;
enum class DescriptorType : std::int32_t {
	Sampler                            =          0,
	CombinedImageSampler               =          1,
	SampledImage                       =          2,
	StorageImage                       =          3,
	UniformTexelBuffer                 =          4,
	StorageTexelBuffer                 =          5,
	UniformBuffer                      =          6,
	StorageBuffer                      =          7,
	UniformBufferDynamic               =          8,
	StorageBufferDynamic               =          9,
	InputAttachment                    =         10,
	InlineUniformBlock                 = 1000138000,
	AccelerationStructureKHR           = 1000150000,
	AccelerationStructureNV            = 1000165000,
	MutableEXT                         = 1000351000,
	SampleWeightImageQCOM              = 1000440000,
	BlockMatchImageQCOM                = 1000440001,
	TensorARM                          = 1000460000,
	PartitionedAccelerationStructureNV = 1000570000,
};
enum class DescriptorUpdateTemplateCreateBits : std::int32_t {};
using DescriptorUpdateTemplateCreateFlags = impl_Enum::Flags<DescriptorUpdateTemplateCreateBits>;
enum class DescriptorUpdateTemplateType : std::int32_t {
	DescriptorSet   =          0, // Create descriptor update template for descriptor set updates
	PushDescriptors =          1,
};
enum class DeviceAddressBindingBitsEXT : std::int32_t {
	InternalObject = 0x00000001,
	AllBits        = 0x00000001, // generated for ~(not), error checking and for convenience
};
using DeviceAddressBindingFlagsEXT = impl_Enum::Flags<DeviceAddressBindingBitsEXT>;
enum class DeviceAddressBindingTypeEXT : std::int32_t {
	Bind   =          0,
	Unbind =          1,
};
enum class DeviceCreateBits : std::int32_t {};
using DeviceCreateFlags = impl_Enum::Flags<DeviceCreateBits>;
enum class DeviceDiagnosticsConfigBitsNV : std::int32_t {
	EnableShaderDebugInfo      = 0x00000001,
	EnableResourceTracking     = 0x00000002,
	EnableAutomaticCheckpoints = 0x00000004,
	EnableShaderErrorReporting = 0x00000008,
	AllBits                    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DeviceDiagnosticsConfigFlagsNV = impl_Enum::Flags<DeviceDiagnosticsConfigBitsNV>;
enum class DeviceEventTypeEXT : std::int32_t {
	DisplayHotplug =          0,
};
enum class DeviceFaultAddressTypeKHR : std::int32_t {
	None                      =          0, // Currently unused
	ReadInvalid               =          1,
	WriteInvalid              =          2,
	ExecuteInvalid            =          3,
	InstructionPointerUnknown =          4,
	InstructionPointerInvalid =          5,
	InstructionPointerFault   =          6,
};
enum class DeviceFaultBitsKHR : std::int32_t {
	FlagDeviceLost         = 0x00000001,
	FlagMemoryAddress      = 0x00000002,
	FlagInstructionAddress = 0x00000004,
	FlagVendor             = 0x00000008,
	FlagWatchdogTimeout    = 0x00000010,
	FlagOverflow           = 0x00000020,
	AllBits                = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using DeviceFaultFlagsKHR = impl_Enum::Flags<DeviceFaultBitsKHR>;
enum class DeviceFaultVendorBinaryHeaderVersionKHR : std::int32_t {
	One =          1,
};
enum class DeviceGroupPresentModeBitsKHR : std::int32_t {
	Local            = 0x00000001, // Present from local memory
	Remote           = 0x00000002, // Present from remote memory
	Sum              = 0x00000004, // Present sum of local and/or remote memory
	LocalMultiDevice = 0x00000008, // Each physical device presents from local memory
	AllBits          = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DeviceGroupPresentModeFlagsKHR = impl_Enum::Flags<DeviceGroupPresentModeBitsKHR>;
enum class DeviceMemoryReportEventTypeEXT : std::int32_t {
	Allocate         =          0,
	Free             =          1,
	Import           =          2,
	Unimport         =          3,
	AllocationFailed =          4,
};
enum class DeviceMemoryReportBitsEXT : std::int32_t {};
using DeviceMemoryReportFlagsEXT = impl_Enum::Flags<DeviceMemoryReportBitsEXT>;
enum class DeviceQueueCreateBits : std::int32_t {
	Protected                    = 0x00000001, // Queue is a protected-capable device queue
	InternallySynchronizedBitKHR = 0x00000004,
	AllBits                      = 0x00000005, // generated for ~(not), error checking and for convenience
};
using DeviceQueueCreateFlags = impl_Enum::Flags<DeviceQueueCreateBits>;
enum class DirectDriverLoadingBitsLUNARG : std::int32_t {};
using DirectDriverLoadingFlagsLUNARG = impl_Enum::Flags<DirectDriverLoadingBitsLUNARG>;
enum class DirectDriverLoadingModeLUNARG : std::int32_t {
	Exclusive =          0,
	Inclusive =          1,
};
enum class DirectFBSurfaceCreateBitsEXT : std::int32_t {};
using DirectFBSurfaceCreateFlagsEXT = impl_Enum::Flags<DirectFBSurfaceCreateBitsEXT>;
enum class DiscardRectangleModeEXT : std::int32_t {
	Inclusive =          0,
	Exclusive =          1,
};
enum class DisplacementMicromapFormatNV : std::int32_t {
	v64Triangles64Bytes    =          1,
	v256Triangles128Bytes  =          2,
	v1024Triangles128Bytes =          3,
};
enum class DisplayEventTypeEXT : std::int32_t {
	FirstPixelOut =          0,
};
enum class DisplayModeCreateBitsKHR : std::int32_t {};
using DisplayModeCreateFlagsKHR = impl_Enum::Flags<DisplayModeCreateBitsKHR>;
enum class DisplayPlaneAlphaBitsKHR : std::int32_t {
	Opaque                = 0x00000001,
	Global                = 0x00000002,
	PerPixel              = 0x00000004,
	PerPixelPremultiplied = 0x00000008,
	AllBits               = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using DisplayPlaneAlphaFlagsKHR = impl_Enum::Flags<DisplayPlaneAlphaBitsKHR>;
enum class DisplayPowerStateEXT : std::int32_t {
	Off     =          0,
	Suspend =          1,
	On      =          2,
};
enum class DisplaySurfaceCreateBitsKHR : std::int32_t {};
using DisplaySurfaceCreateFlagsKHR = impl_Enum::Flags<DisplaySurfaceCreateBitsKHR>;
enum class DisplaySurfaceStereoTypeNV : std::int32_t {
	None              =          0,
	OnboardDin        =          1,
	Hdmi3D            =          2,
	InbandDisplayport =          3,
};
enum class DriverId : std::int32_t {
	AMDProprietary            =          1, // Advanced Micro Devices, Inc.
	AMDOpenSource             =          2, // Advanced Micro Devices, Inc.
	MESARadv                  =          3, // Mesa open source project
	NvidiaProprietary         =          4, // NVIDIA Corporation
	INTELProprietaryWindows   =          5, // Intel Corporation
	INTELOpenSourceMESA       =          6, // Intel Corporation
	ImaginationProprietary    =          7, // Imagination Technologies
	QualcommProprietary       =          8, // Qualcomm Technologies, Inc.
	ARMProprietary            =          9, // Arm Limited
	GOOGLESwiftshader         =         10, // Google LLC
	GGPProprietary            =         11, // Google LLC
	BroadcomProprietary       =         12, // Broadcom Inc.
	MESALlvmpipe              =         13, // Mesa
	Moltenvk                  =         14, // MoltenVK
	CoreaviProprietary        =         15, // Core Avionics & Industrial Inc.
	JUICEProprietary          =         16, // Juice Technologies, Inc.
	VerisiliconProprietary    =         17, // Verisilicon, Inc.
	MESATurnip                =         18, // Mesa open source project
	MESAV3Dv                  =         19, // Mesa open source project
	MESAPanvk                 =         20, // Mesa open source project
	SAMSUNGProprietary        =         21, // Samsung Electronics Co., Ltd.
	MESAVenus                 =         22, // Mesa open source project
	MESADozen                 =         23, // Mesa open source project
	MESANvk                   =         24, // Mesa open source project
	ImaginationOpenSourceMESA =         25, // Imagination Technologies
	MESAHoneykrisp            =         26, // Mesa open source project
	VulkanScEmulationOnVulkan =         27, // Vulkan SC Emulation on Vulkan
	MESAKosmickrisp           =         28, // Mesa open source project
	MESAGfxstream             =         29, // Mesa open source project
	ApeSoft                   =         30, // Ape open source project
};
enum class DynamicState : std::int32_t {
	Viewport                            =          0,
	Scissor                             =          1,
	LineWidth                           =          2,
	DepthBias                           =          3,
	BlendConstants                      =          4,
	DepthBounds                         =          5,
	StencilCompareMask                  =          6,
	StencilWriteMask                    =          7,
	StencilReference                    =          8,
	ViewportWScalingNV                  = 1000087000,
	DiscardRectangleEXT                 = 1000099000,
	DiscardRectangleEnableEXT           = 1000099001,
	DiscardRectangleModeEXT             = 1000099002,
	SampleLocationsEXT                  = 1000143000,
	ViewportShadingRatePaletteNV        = 1000164004,
	ViewportCoarseSampleOrderNV         = 1000164006,
	ExclusiveScissorEnableNV            = 1000205000,
	ExclusiveScissorNV                  = 1000205001,
	FragmentShadingRateKHR              = 1000226000,
	LineStipple                         = 1000259000,
	CullMode                            = 1000267000,
	FrontFace                           = 1000267001,
	PrimitiveTopology                   = 1000267002,
	ViewportWithCount                   = 1000267003,
	ScissorWithCount                    = 1000267004,
	VertexInputBindingStride            = 1000267005,
	DepthTestEnable                     = 1000267006,
	DepthWriteEnable                    = 1000267007,
	DepthCompareOp                      = 1000267008,
	DepthBoundsTestEnable               = 1000267009,
	StencilTestEnable                   = 1000267010,
	StencilOp                           = 1000267011,
	RayTracingPipelineStackSizeKHR      = 1000347000,
	VertexInputEXT                      = 1000352000,
	PatchControlPointsEXT               = 1000377000, // Not promoted to 1.3
	RasterizerDiscardEnable             = 1000377001,
	DepthBiasEnable                     = 1000377002,
	LogicOpEXT                          = 1000377003, // Not promoted to 1.3
	PrimitiveRestartEnable              = 1000377004,
	ColorWriteEnableEXT                 = 1000381000,
	TessellationDomainOriginEXT         = 1000455002,
	DepthClampEnableEXT                 = 1000455003,
	PolygonModeEXT                      = 1000455004,
	RasterizationSamplesEXT             = 1000455005,
	SampleMaskEXT                       = 1000455006,
	AlphaToCoverageEnableEXT            = 1000455007,
	AlphaToOneEnableEXT                 = 1000455008,
	LogicOpEnableEXT                    = 1000455009,
	ColorBlendEnableEXT                 = 1000455010,
	ColorBlendEquationEXT               = 1000455011,
	ColorWriteMaskEXT                   = 1000455012,
	RasterizationStreamEXT              = 1000455013,
	ConservativeRasterizationModeEXT    = 1000455014,
	ExtraPrimitiveOverestimationSizeEXT = 1000455015,
	DepthClipEnableEXT                  = 1000455016,
	SampleLocationsEnableEXT            = 1000455017,
	ColorBlendAdvancedEXT               = 1000455018,
	ProvokingVertexModeEXT              = 1000455019,
	LineRasterizationModeEXT            = 1000455020,
	LineStippleEnableEXT                = 1000455021,
	DepthClipNegativeOneToOneEXT        = 1000455022,
	ViewportWScalingEnableNV            = 1000455023,
	ViewportSwizzleNV                   = 1000455024,
	CoverageToColorEnableNV             = 1000455025,
	CoverageToColorLocationNV           = 1000455026,
	CoverageModulationModeNV            = 1000455027,
	CoverageModulationTableEnableNV     = 1000455028,
	CoverageModulationTableNV           = 1000455029,
	ShadingRateImageEnableNV            = 1000455030,
	RepresentativeFragmentTestEnableNV  = 1000455031,
	CoverageReductionModeNV             = 1000455032,
	AttachmentFeedbackLoopEnableEXT     = 1000524000,
	DepthClampRangeEXT                  = 1000582000,
};
enum class EventCreateBits : std::int32_t {
	DeviceOnly = 0x00000001,
	AllBits    = 0x00000001, // generated for ~(not), error checking and for convenience
};
using EventCreateFlags = impl_Enum::Flags<EventCreateBits>;
enum class ExportMetalObjectTypeBitsEXT : std::int32_t {
	MetalDevice       = 0x00000001,
	MetalCommandQueue = 0x00000002,
	MetalBuffer       = 0x00000004,
	MetalTexture      = 0x00000008,
	MetalIosurface    = 0x00000010,
	MetalSharedEvent  = 0x00000020,
	AllBits           = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using ExportMetalObjectTypeFlagsEXT = impl_Enum::Flags<ExportMetalObjectTypeBitsEXT>;
enum class ExternalFenceFeatureBits : std::int32_t {
	Exportable = 0x00000001,
	Importable = 0x00000002,
	AllBits    = 0x00000003, // generated for ~(not), error checking and for convenience
};
using ExternalFenceFeatureFlags = impl_Enum::Flags<ExternalFenceFeatureBits>;
enum class ExternalFenceHandleTypeBits : std::int32_t {
	OpaqueFd       = 0x00000001,
	OpaqueWin32    = 0x00000002,
	OpaqueWin32Kmt = 0x00000004,
	SyncFd         = 0x00000008,
	AllBits        = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using ExternalFenceHandleTypeFlags = impl_Enum::Flags<ExternalFenceHandleTypeBits>;
enum class ExternalMemoryFeatureBits : std::int32_t {
	DedicatedOnly = 0x00000001,
	Exportable    = 0x00000002,
	Importable    = 0x00000004,
	AllBits       = 0x00000007, // generated for ~(not), error checking and for convenience
};
using ExternalMemoryFeatureFlags = impl_Enum::Flags<ExternalMemoryFeatureBits>;
enum class ExternalMemoryFeatureBitsNV : std::int32_t {
	DedicatedOnly = 0x00000001,
	Exportable    = 0x00000002,
	Importable    = 0x00000004,
	AllBits       = 0x00000007, // generated for ~(not), error checking and for convenience
};
using ExternalMemoryFeatureFlagsNV = impl_Enum::Flags<ExternalMemoryFeatureBitsNV>;
enum class ExternalMemoryHandleTypeBits : std::int32_t {
	OpaqueFd                        = 0x00000001,
	OpaqueWin32                     = 0x00000002,
	OpaqueWin32Kmt                  = 0x00000004,
	D3D11Texture                    = 0x00000008,
	D3D11TextureKmt                 = 0x00000010,
	D3D12Heap                       = 0x00000020,
	D3D12Resource                   = 0x00000040,
	HostAllocationBitEXT            = 0x00000080,
	HostMappedForeignMemoryBitEXT   = 0x00000100,
	DmaBufBitEXT                    = 0x00000200,
	ANDROIDHardwareBufferBitANDROID = 0x00000400,
	ZirconVmoBitFUCHSIA             = 0x00000800,
	RdmaAddressBitNV                = 0x00001000,
	ScreenBufferBitQNX              = 0x00004000,
	OhNativeBufferBitOHOS           = 0x00008000,
	MtlbufferBitEXT                 = 0x00010000,
	MtltextureBitEXT                = 0x00020000,
	MtlheapBitEXT                   = 0x00040000,
	AllBits                         = 0x0007dfff, // generated for ~(not), error checking and for convenience
};
using ExternalMemoryHandleTypeFlags = impl_Enum::Flags<ExternalMemoryHandleTypeBits>;
enum class ExternalMemoryHandleTypeBitsNV : std::int32_t {
	OpaqueWin32    = 0x00000001,
	OpaqueWin32Kmt = 0x00000002,
	D3D11Image     = 0x00000004,
	D3D11ImageKmt  = 0x00000008,
	AllBits        = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using ExternalMemoryHandleTypeFlagsNV = impl_Enum::Flags<ExternalMemoryHandleTypeBitsNV>;
enum class ExternalSemaphoreFeatureBits : std::int32_t {
	Exportable = 0x00000001,
	Importable = 0x00000002,
	AllBits    = 0x00000003, // generated for ~(not), error checking and for convenience
};
using ExternalSemaphoreFeatureFlags = impl_Enum::Flags<ExternalSemaphoreFeatureBits>;
enum class ExternalSemaphoreHandleTypeBits : std::int32_t {
	OpaqueFd              = 0x00000001,
	OpaqueWin32           = 0x00000002,
	OpaqueWin32Kmt        = 0x00000004,
	D3D12Fence            = 0x00000008,
	SyncFd                = 0x00000010,
	ZirconEventBitFUCHSIA = 0x00000080,
	AllBits               = 0x0000009f, // generated for ~(not), error checking and for convenience
};
using ExternalSemaphoreHandleTypeFlags = impl_Enum::Flags<ExternalSemaphoreHandleTypeBits>;
enum class FenceCreateBits : std::int32_t {
	Signaled = 0x00000001,
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
using FenceCreateFlags = impl_Enum::Flags<FenceCreateBits>;
enum class FenceImportBits : std::int32_t {
	Temporary = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
};
using FenceImportFlags = impl_Enum::Flags<FenceImportBits>;
enum class Filter : std::int32_t {
	Nearest  =          0,
	Linear   =          1,
	CubicEXT = 1000015000,
};
enum class Format : std::int32_t {
	Undefined                               =          0,
	R4G4UnormPack8                          =          1,
	R4G4B4A4UnormPack16                     =          2,
	B4G4R4A4UnormPack16                     =          3,
	R5G6B5UnormPack16                       =          4,
	B5G6R5UnormPack16                       =          5,
	R5G5B5A1UnormPack16                     =          6,
	B5G5R5A1UnormPack16                     =          7,
	A1R5G5B5UnormPack16                     =          8,
	R8Unorm                                 =          9,
	R8Snorm                                 =         10,
	R8Uscaled                               =         11,
	R8Sscaled                               =         12,
	R8Uint                                  =         13,
	R8Sint                                  =         14,
	R8Srgb                                  =         15,
	R8G8Unorm                               =         16,
	R8G8Snorm                               =         17,
	R8G8Uscaled                             =         18,
	R8G8Sscaled                             =         19,
	R8G8Uint                                =         20,
	R8G8Sint                                =         21,
	R8G8Srgb                                =         22,
	R8G8B8Unorm                             =         23,
	R8G8B8Snorm                             =         24,
	R8G8B8Uscaled                           =         25,
	R8G8B8Sscaled                           =         26,
	R8G8B8Uint                              =         27,
	R8G8B8Sint                              =         28,
	R8G8B8Srgb                              =         29,
	B8G8R8Unorm                             =         30,
	B8G8R8Snorm                             =         31,
	B8G8R8Uscaled                           =         32,
	B8G8R8Sscaled                           =         33,
	B8G8R8Uint                              =         34,
	B8G8R8Sint                              =         35,
	B8G8R8Srgb                              =         36,
	R8G8B8A8Unorm                           =         37,
	R8G8B8A8Snorm                           =         38,
	R8G8B8A8Uscaled                         =         39,
	R8G8B8A8Sscaled                         =         40,
	R8G8B8A8Uint                            =         41,
	R8G8B8A8Sint                            =         42,
	R8G8B8A8Srgb                            =         43,
	B8G8R8A8Unorm                           =         44,
	B8G8R8A8Snorm                           =         45,
	B8G8R8A8Uscaled                         =         46,
	B8G8R8A8Sscaled                         =         47,
	B8G8R8A8Uint                            =         48,
	B8G8R8A8Sint                            =         49,
	B8G8R8A8Srgb                            =         50,
	A8B8G8R8UnormPack32                     =         51,
	A8B8G8R8SnormPack32                     =         52,
	A8B8G8R8UscaledPack32                   =         53,
	A8B8G8R8SscaledPack32                   =         54,
	A8B8G8R8UintPack32                      =         55,
	A8B8G8R8SintPack32                      =         56,
	A8B8G8R8SrgbPack32                      =         57,
	A2R10G10B10UnormPack32                  =         58,
	A2R10G10B10SnormPack32                  =         59,
	A2R10G10B10UscaledPack32                =         60,
	A2R10G10B10SscaledPack32                =         61,
	A2R10G10B10UintPack32                   =         62,
	A2R10G10B10SintPack32                   =         63,
	A2B10G10R10UnormPack32                  =         64,
	A2B10G10R10SnormPack32                  =         65,
	A2B10G10R10UscaledPack32                =         66,
	A2B10G10R10SscaledPack32                =         67,
	A2B10G10R10UintPack32                   =         68,
	A2B10G10R10SintPack32                   =         69,
	R16Unorm                                =         70,
	R16Snorm                                =         71,
	R16Uscaled                              =         72,
	R16Sscaled                              =         73,
	R16Uint                                 =         74,
	R16Sint                                 =         75,
	R16Sfloat                               =         76,
	R16G16Unorm                             =         77,
	R16G16Snorm                             =         78,
	R16G16Uscaled                           =         79,
	R16G16Sscaled                           =         80,
	R16G16Uint                              =         81,
	R16G16Sint                              =         82,
	R16G16Sfloat                            =         83,
	R16G16B16Unorm                          =         84,
	R16G16B16Snorm                          =         85,
	R16G16B16Uscaled                        =         86,
	R16G16B16Sscaled                        =         87,
	R16G16B16Uint                           =         88,
	R16G16B16Sint                           =         89,
	R16G16B16Sfloat                         =         90,
	R16G16B16A16Unorm                       =         91,
	R16G16B16A16Snorm                       =         92,
	R16G16B16A16Uscaled                     =         93,
	R16G16B16A16Sscaled                     =         94,
	R16G16B16A16Uint                        =         95,
	R16G16B16A16Sint                        =         96,
	R16G16B16A16Sfloat                      =         97,
	R32Uint                                 =         98,
	R32Sint                                 =         99,
	R32Sfloat                               =        100,
	R32G32Uint                              =        101,
	R32G32Sint                              =        102,
	R32G32Sfloat                            =        103,
	R32G32B32Uint                           =        104,
	R32G32B32Sint                           =        105,
	R32G32B32Sfloat                         =        106,
	R32G32B32A32Uint                        =        107,
	R32G32B32A32Sint                        =        108,
	R32G32B32A32Sfloat                      =        109,
	R64Uint                                 =        110,
	R64Sint                                 =        111,
	R64Sfloat                               =        112,
	R64G64Uint                              =        113,
	R64G64Sint                              =        114,
	R64G64Sfloat                            =        115,
	R64G64B64Uint                           =        116,
	R64G64B64Sint                           =        117,
	R64G64B64Sfloat                         =        118,
	R64G64B64A64Uint                        =        119,
	R64G64B64A64Sint                        =        120,
	R64G64B64A64Sfloat                      =        121,
	B10G11R11UfloatPack32                   =        122,
	E5B9G9R9UfloatPack32                    =        123,
	D16Unorm                                =        124,
	x8D24UnormPack32                        =        125,
	D32Sfloat                               =        126,
	S8Uint                                  =        127,
	D16UnormS8Uint                          =        128,
	D24UnormS8Uint                          =        129,
	D32SfloatS8Uint                         =        130,
	Bc1RgbUnormBlock                        =        131,
	Bc1RgbSrgbBlock                         =        132,
	Bc1RgbaUnormBlock                       =        133,
	Bc1RgbaSrgbBlock                        =        134,
	Bc2UnormBlock                           =        135,
	Bc2SrgbBlock                            =        136,
	Bc3UnormBlock                           =        137,
	Bc3SrgbBlock                            =        138,
	Bc4UnormBlock                           =        139,
	Bc4SnormBlock                           =        140,
	Bc5UnormBlock                           =        141,
	Bc5SnormBlock                           =        142,
	Bc6HUfloatBlock                         =        143,
	Bc6HSfloatBlock                         =        144,
	Bc7UnormBlock                           =        145,
	Bc7SrgbBlock                            =        146,
	Etc2R8G8B8UnormBlock                    =        147,
	Etc2R8G8B8SrgbBlock                     =        148,
	Etc2R8G8B8A1UnormBlock                  =        149,
	Etc2R8G8B8A1SrgbBlock                   =        150,
	Etc2R8G8B8A8UnormBlock                  =        151,
	Etc2R8G8B8A8SrgbBlock                   =        152,
	EacR11UnormBlock                        =        153,
	EacR11SnormBlock                        =        154,
	EacR11G11UnormBlock                     =        155,
	EacR11G11SnormBlock                     =        156,
	Astc4x4UnormBlock                       =        157,
	Astc4x4SrgbBlock                        =        158,
	Astc5x4UnormBlock                       =        159,
	Astc5x4SrgbBlock                        =        160,
	Astc5x5UnormBlock                       =        161,
	Astc5x5SrgbBlock                        =        162,
	Astc6x5UnormBlock                       =        163,
	Astc6x5SrgbBlock                        =        164,
	Astc6x6UnormBlock                       =        165,
	Astc6x6SrgbBlock                        =        166,
	Astc8x5UnormBlock                       =        167,
	Astc8x5SrgbBlock                        =        168,
	Astc8x6UnormBlock                       =        169,
	Astc8x6SrgbBlock                        =        170,
	Astc8x8UnormBlock                       =        171,
	Astc8x8SrgbBlock                        =        172,
	Astc10x5UnormBlock                      =        173,
	Astc10x5SrgbBlock                       =        174,
	Astc10x6UnormBlock                      =        175,
	Astc10x6SrgbBlock                       =        176,
	Astc10x8UnormBlock                      =        177,
	Astc10x8SrgbBlock                       =        178,
	Astc10x10UnormBlock                     =        179,
	Astc10x10SrgbBlock                      =        180,
	Astc12x10UnormBlock                     =        181,
	Astc12x10SrgbBlock                      =        182,
	Astc12x12UnormBlock                     =        183,
	Astc12x12SrgbBlock                      =        184,
	Pvrtc12BppUnormBlockIMG                 = 1000054000,
	Pvrtc14BppUnormBlockIMG                 = 1000054001,
	Pvrtc22BppUnormBlockIMG                 = 1000054002,
	Pvrtc24BppUnormBlockIMG                 = 1000054003,
	Pvrtc12BppSrgbBlockIMG                  = 1000054004,
	Pvrtc14BppSrgbBlockIMG                  = 1000054005,
	Pvrtc22BppSrgbBlockIMG                  = 1000054006,
	Pvrtc24BppSrgbBlockIMG                  = 1000054007,
	Astc4x4SfloatBlock                      = 1000066000,
	Astc5x4SfloatBlock                      = 1000066001,
	Astc5x5SfloatBlock                      = 1000066002,
	Astc6x5SfloatBlock                      = 1000066003,
	Astc6x6SfloatBlock                      = 1000066004,
	Astc8x5SfloatBlock                      = 1000066005,
	Astc8x6SfloatBlock                      = 1000066006,
	Astc8x8SfloatBlock                      = 1000066007,
	Astc10x5SfloatBlock                     = 1000066008,
	Astc10x6SfloatBlock                     = 1000066009,
	Astc10x8SfloatBlock                     = 1000066010,
	Astc10x10SfloatBlock                    = 1000066011,
	Astc12x10SfloatBlock                    = 1000066012,
	Astc12x12SfloatBlock                    = 1000066013,
	G8B8G8R8422Unorm                        = 1000156000,
	B8G8R8G8422Unorm                        = 1000156001,
	G8B8R83Plane420Unorm                    = 1000156002,
	G8B8R82Plane420Unorm                    = 1000156003,
	G8B8R83Plane422Unorm                    = 1000156004,
	G8B8R82Plane422Unorm                    = 1000156005,
	G8B8R83Plane444Unorm                    = 1000156006,
	R10x6UnormPack16                        = 1000156007,
	R10x6G10x6Unorm2Pack16                  = 1000156008,
	R10x6G10x6B10x6A10x6Unorm4Pack16        = 1000156009,
	G10x6B10x6G10x6R10x6422Unorm4Pack16     = 1000156010,
	B10x6G10x6R10x6G10x6422Unorm4Pack16     = 1000156011,
	G10x6B10x6R10x63Plane420Unorm3Pack16    = 1000156012,
	G10x6B10x6R10x62Plane420Unorm3Pack16    = 1000156013,
	G10x6B10x6R10x63Plane422Unorm3Pack16    = 1000156014,
	G10x6B10x6R10x62Plane422Unorm3Pack16    = 1000156015,
	G10x6B10x6R10x63Plane444Unorm3Pack16    = 1000156016,
	R12x4UnormPack16                        = 1000156017,
	R12x4G12x4Unorm2Pack16                  = 1000156018,
	R12x4G12x4B12x4A12x4Unorm4Pack16        = 1000156019,
	G12x4B12x4G12x4R12x4422Unorm4Pack16     = 1000156020,
	B12x4G12x4R12x4G12x4422Unorm4Pack16     = 1000156021,
	G12x4B12x4R12x43Plane420Unorm3Pack16    = 1000156022,
	G12x4B12x4R12x42Plane420Unorm3Pack16    = 1000156023,
	G12x4B12x4R12x43Plane422Unorm3Pack16    = 1000156024,
	G12x4B12x4R12x42Plane422Unorm3Pack16    = 1000156025,
	G12x4B12x4R12x43Plane444Unorm3Pack16    = 1000156026,
	G16B16G16R16422Unorm                    = 1000156027,
	B16G16R16G16422Unorm                    = 1000156028,
	G16B16R163Plane420Unorm                 = 1000156029,
	G16B16R162Plane420Unorm                 = 1000156030,
	G16B16R163Plane422Unorm                 = 1000156031,
	G16B16R162Plane422Unorm                 = 1000156032,
	G16B16R163Plane444Unorm                 = 1000156033,
	Astc3x3x3UnormBlockEXT                  = 1000288000,
	Astc3x3x3SrgbBlockEXT                   = 1000288001,
	Astc3x3x3SfloatBlockEXT                 = 1000288002,
	Astc4x3x3UnormBlockEXT                  = 1000288003,
	Astc4x3x3SrgbBlockEXT                   = 1000288004,
	Astc4x3x3SfloatBlockEXT                 = 1000288005,
	Astc4x4x3UnormBlockEXT                  = 1000288006,
	Astc4x4x3SrgbBlockEXT                   = 1000288007,
	Astc4x4x3SfloatBlockEXT                 = 1000288008,
	Astc4x4x4UnormBlockEXT                  = 1000288009,
	Astc4x4x4SrgbBlockEXT                   = 1000288010,
	Astc4x4x4SfloatBlockEXT                 = 1000288011,
	Astc5x4x4UnormBlockEXT                  = 1000288012,
	Astc5x4x4SrgbBlockEXT                   = 1000288013,
	Astc5x4x4SfloatBlockEXT                 = 1000288014,
	Astc5x5x4UnormBlockEXT                  = 1000288015,
	Astc5x5x4SrgbBlockEXT                   = 1000288016,
	Astc5x5x4SfloatBlockEXT                 = 1000288017,
	Astc5x5x5UnormBlockEXT                  = 1000288018,
	Astc5x5x5SrgbBlockEXT                   = 1000288019,
	Astc5x5x5SfloatBlockEXT                 = 1000288020,
	Astc6x5x5UnormBlockEXT                  = 1000288021,
	Astc6x5x5SrgbBlockEXT                   = 1000288022,
	Astc6x5x5SfloatBlockEXT                 = 1000288023,
	Astc6x6x5UnormBlockEXT                  = 1000288024,
	Astc6x6x5SrgbBlockEXT                   = 1000288025,
	Astc6x6x5SfloatBlockEXT                 = 1000288026,
	Astc6x6x6UnormBlockEXT                  = 1000288027,
	Astc6x6x6SrgbBlockEXT                   = 1000288028,
	Astc6x6x6SfloatBlockEXT                 = 1000288029,
	G8B8R82Plane444Unorm                    = 1000330000,
	G10x6B10x6R10x62Plane444Unorm3Pack16    = 1000330001,
	G12x4B12x4R12x42Plane444Unorm3Pack16    = 1000330002,
	G16B16R162Plane444Unorm                 = 1000330003,
	A4R4G4B4UnormPack16                     = 1000340000,
	A4B4G4R4UnormPack16                     = 1000340001,
	R8BoolARM                               = 1000460000,
	R16SfloatFpencodingBfloat16ARM          = 1000460001,
	R8SfloatFpencodingFloat8E4M3ARM         = 1000460002,
	R8SfloatFpencodingFloat8E5M2ARM         = 1000460003,
	R16G16Sfixed5NV                         = 1000464000,
	A1B5G5R5UnormPack16                     = 1000470000,
	A8Unorm                                 = 1000470001,
	R10x6UintPack16ARM                      = 1000609000,
	R10x6G10x6Uint2Pack16ARM                = 1000609001,
	R10x6G10x6B10x6A10x6Uint4Pack16ARM      = 1000609002,
	R12x4UintPack16ARM                      = 1000609003,
	R12x4G12x4Uint2Pack16ARM                = 1000609004,
	R12x4G12x4B12x4A12x4Uint4Pack16ARM      = 1000609005,
	R14x2UintPack16ARM                      = 1000609006,
	R14x2G14x2Uint2Pack16ARM                = 1000609007,
	R14x2G14x2B14x2A14x2Uint4Pack16ARM      = 1000609008,
	R14x2UnormPack16ARM                     = 1000609009,
	R14x2G14x2Unorm2Pack16ARM               = 1000609010,
	R14x2G14x2B14x2A14x2Unorm4Pack16ARM     = 1000609011,
	G14x2B14x2R14x22Plane420Unorm3Pack16ARM = 1000609012,
	G14x2B14x2R14x22Plane422Unorm3Pack16ARM = 1000609013,
};
enum class FormatFeatureBits : std::int32_t {
	SampledImage                                                     = 0x00000001, // Format can be used for sampled images (SAMPLED_IMAGE and COMBINED_IMAGE_SAMPLER descriptor types)
	StorageImage                                                     = 0x00000002, // Format can be used for storage images (STORAGE_IMAGE descriptor type)
	StorageImageAtomic                                               = 0x00000004, // Format supports atomic operations in case it is used for storage images
	UniformTexelBuffer                                               = 0x00000008, // Format can be used for uniform texel buffers (TBOs)
	StorageTexelBuffer                                               = 0x00000010, // Format can be used for storage texel buffers (IBOs)
	StorageTexelBufferAtomic                                         = 0x00000020, // Format supports atomic operations in case it is used for storage texel buffers
	VertexBuffer                                                     = 0x00000040, // Format can be used for vertex buffers (VBOs)
	ColorAttachment                                                  = 0x00000080, // Format can be used for color attachment images
	ColorAttachmentBlend                                             = 0x00000100, // Format supports blending in case it is used for color attachment images
	DepthStencilAttachment                                           = 0x00000200, // Format can be used for depth/stencil attachment images
	BlitSrc                                                          = 0x00000400, // Format can be used as the source image of blits with vkCmdBlitImage
	BlitDst                                                          = 0x00000800, // Format can be used as the destination image of blits with vkCmdBlitImage
	SampledImageFilterLinear                                         = 0x00001000, // Format can be filtered with VK_FILTER_LINEAR when being sampled
	SampledImageFilterCubicBitEXT                                    = 0x00002000,
	TransferSrc                                                      = 0x00004000, // Format can be used as the source image of image transfer commands
	TransferDst                                                      = 0x00008000, // Format can be used as the destination image of image transfer commands
	SampledImageFilterMinmax                                         = 0x00010000, // Format can be used with min/max reduction filtering
	MidpointChromaSamples                                            = 0x00020000, // Format can have midpoint rather than cosited chroma samples
	SampledImageYcbcrConversionLinearFilter                          = 0x00040000, // Format can be used with linear filtering whilst color conversion is enabled
	SampledImageYcbcrConversionSeparateReconstructionFilter          = 0x00080000, // Format can have different chroma, min and mag filters
	SampledImageYcbcrConversionChromaReconstructionExplicit          = 0x00100000,
	SampledImageYcbcrConversionChromaReconstructionExplicitForceable = 0x00200000,
	Disjoint                                                         = 0x00400000, // Format supports disjoint planes
	CositedChromaSamples                                             = 0x00800000, // Format can have cosited rather than midpoint chroma samples
	FragmentDensityMapBitEXT                                         = 0x01000000,
	VideoDecodeOutputBitKHR                                          = 0x02000000,
	VideoDecodeDpbBitKHR                                             = 0x04000000,
	VideoEncodeInputBitKHR                                           = 0x08000000,
	VideoEncodeDpbBitKHR                                             = 0x10000000,
	AccelerationStructureVertexBufferBitKHR                          = 0x20000000,
	FragmentShadingRateAttachmentBitKHR                              = 0x40000000,
	AllBits                                                          = 0x7fffffff, // generated for ~(not), error checking and for convenience
};
using FormatFeatureFlags = impl_Enum::Flags<FormatFeatureBits>;
enum class FormatFeatureBits2 : std::uint64_t {
	SampledImage                                                     = 0x0000000000000001,
	StorageImage                                                     = 0x0000000000000002,
	StorageImageAtomic                                               = 0x0000000000000004,
	UniformTexelBuffer                                               = 0x0000000000000008,
	StorageTexelBuffer                                               = 0x0000000000000010,
	StorageTexelBufferAtomic                                         = 0x0000000000000020,
	VertexBuffer                                                     = 0x0000000000000040,
	ColorAttachment                                                  = 0x0000000000000080,
	ColorAttachmentBlend                                             = 0x0000000000000100,
	DepthStencilAttachment                                           = 0x0000000000000200,
	BlitSrc                                                          = 0x0000000000000400,
	BlitDst                                                          = 0x0000000000000800,
	SampledImageFilterLinear                                         = 0x0000000000001000,
	SampledImageFilterCubic                                          = 0x0000000000002000, // This is an interaction with EXT_filter_cubic, though not tagged that way
	TransferSrc                                                      = 0x0000000000004000,
	TransferDst                                                      = 0x0000000000008000,
	SampledImageFilterMinmax                                         = 0x0000000000010000,
	MidpointChromaSamples                                            = 0x0000000000020000,
	SampledImageYcbcrConversionLinearFilter                          = 0x0000000000040000,
	SampledImageYcbcrConversionSeparateReconstructionFilter          = 0x0000000000080000,
	SampledImageYcbcrConversionChromaReconstructionExplicit          = 0x0000000000100000,
	SampledImageYcbcrConversionChromaReconstructionExplicitForceable = 0x0000000000200000,
	Disjoint                                                         = 0x0000000000400000,
	CositedChromaSamples                                             = 0x0000000000800000,
	FragmentDensityMapBitEXT                                         = 0x0000000001000000,
	VideoDecodeOutputBitKHR                                          = 0x0000000002000000,
	VideoDecodeDpbBitKHR                                             = 0x0000000004000000,
	VideoEncodeInputBitKHR                                           = 0x0000000008000000,
	VideoEncodeDpbBitKHR                                             = 0x0000000010000000,
	AccelerationStructureVertexBufferBitKHR                          = 0x0000000020000000,
	FragmentShadingRateAttachmentBitKHR                              = 0x0000000040000000,
	StorageReadWithoutFormat                                         = 0x0000000080000000,
	StorageWriteWithoutFormat                                        = 0x0000000100000000,
	SampledImageDepthComparison                                      = 0x0000000200000000,
	WeightImageBitQCOM                                               = 0x0000000400000000,
	WeightSampledImageBitQCOM                                        = 0x0000000800000000,
	BlockMatchingBitQCOM                                             = 0x0000001000000000,
	BoxFilterSampledBitQCOM                                          = 0x0000002000000000,
	LinearColorAttachmentBitNV                                       = 0x0000004000000000, // Format support linear image as render target, it cannot be mixed with non linear attachment
	TensorShaderBitARM                                               = 0x0000008000000000,
	OpticalFlowImageBitNV                                            = 0x0000010000000000,
	OpticalFlowVectorBitNV                                           = 0x0000020000000000,
	OpticalFlowCostBitNV                                             = 0x0000040000000000,
	TensorImageAliasingBitARM                                        = 0x0000080000000000,
	BlockMatchingSxdBitQCOM                                          = 0x0000100000000000,
	SampledImageFilterLinear2DBitIMG                                 = 0x0000200000000000,
	HostImageTransfer                                                = 0x0000400000000000,
	TensorDataGraphBitARM                                            = 0x0001000000000000,
	VideoEncodeQuantizationDeltaMapBitKHR                            = 0x0002000000000000,
	VideoEncodeEmphasisMapBitKHR                                     = 0x0004000000000000,
	AccelerationStructureRadiusBufferBitNV                           = 0x0008000000000000,
	DepthCopyOnComputeQueueBitKHR                                    = 0x0010000000000000,
	DepthCopyOnTransferQueueBitKHR                                   = 0x0020000000000000,
	StencilCopyOnComputeQueueBitKHR                                  = 0x0040000000000000,
	StencilCopyOnTransferQueueBitKHR                                 = 0x0080000000000000,
	DataGraphOpticalFlowImageBitARM                                  = 0x0100000000000000,
	DataGraphOpticalFlowVectorBitARM                                 = 0x0200000000000000,
	DataGraphOpticalFlowCostBitARM                                   = 0x0400000000000000,
	CopyImageIndirectDstBitKHR                                       = 0x0800000000000000,
	AllBits                                                          = 0x0fff7fffffffffff, // generated for ~(not), error checking and for convenience
};
using FormatFeatureFlags2 = impl_Enum::Flags<FormatFeatureBits2>;
enum class FormatFeatureBits4KHR : std::uint64_t {};
using FormatFeatureFlags4KHR = impl_Enum::Flags<FormatFeatureBits4KHR>;
enum class FragmentShadingRateNV : std::int32_t {
	v1InvocationPerPixel     =          0,
	v1InvocationPer1x2Pixels =          1,
	v1InvocationPer2x1Pixels =          4,
	v1InvocationPer2x2Pixels =          5,
	v1InvocationPer2x4Pixels =          6,
	v1InvocationPer4x2Pixels =          9,
	v1InvocationPer4x4Pixels =         10,
	v2InvocationsPerPixel    =         11,
	v4InvocationsPerPixel    =         12,
	v8InvocationsPerPixel    =         13,
	v16InvocationsPerPixel   =         14,
	NoInvocations            =         15,
};
enum class FragmentShadingRateCombinerOpKHR : std::int32_t {
	Keep    =          0,
	Replace =          1,
	Min     =          2,
	Max     =          3,
	Mul     =          4,
};
enum class FragmentShadingRateTypeNV : std::int32_t {
	FragmentSize =          0,
	Enums        =          1,
};
enum class FrameBoundaryBitsEXT : std::int32_t {
	FrameEnd = 0x00000001,
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
using FrameBoundaryFlagsEXT = impl_Enum::Flags<FrameBoundaryBitsEXT>;
enum class FramebufferCreateBits : std::int32_t {
	Imageless = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
};
using FramebufferCreateFlags = impl_Enum::Flags<FramebufferCreateBits>;
enum class FrontFace : std::int32_t {
	CounterClockwise =          0,
	Clockwise        =          1,
};
enum class FullScreenExclusiveEXT : std::int32_t {
	Default               =          0,
	Allowed               =          1,
	Disallowed            =          2,
	ApplicationControlled =          3,
};
enum class GeometryBitsKHR : std::int32_t {
	Opaque                      = 0x00000001,
	NoDuplicateAnyHitInvocation = 0x00000002,
	AllBits                     = 0x00000003, // generated for ~(not), error checking and for convenience
};
using GeometryFlagsKHR = impl_Enum::Flags<GeometryBitsKHR>;
enum class GeometryInstanceBitsKHR : std::int32_t {
	TriangleFacingCullDisable  = 0x00000001,
	TriangleFlipFacing         = 0x00000002,
	ForceOpaque                = 0x00000004,
	ForceNoOpaque              = 0x00000008,
	ForceOpacityMicromap2State = 0x00000010,
	DisableOpacityMicromaps    = 0x00000020,
	AllBits                    = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using GeometryInstanceFlagsKHR = impl_Enum::Flags<GeometryInstanceBitsKHR>;
enum class GeometryTypeKHR : std::int32_t {
	Triangles                        =          0,
	Aabbs                            =          1,
	Instances                        =          2,
	SpheresNV                        = 1000429004,
	LinearSweptSpheresNV             = 1000429005,
	DenseGeometryFormatTrianglesAMDX = 1000478000,
	Micromap                         = 1000623000,
};
enum class GpaDeviceClockModeAMD : std::int32_t {
	Default   =          0,
	Query     =          1,
	Profiling =          2,
	MinMemory =          3,
	MinEngine =          4,
	Peak      =          5,
};
enum class GpaPerfBlockAMD : std::int32_t {
	Cpf     =          0,
	Ia      =          1,
	Vgt     =          2,
	Pa      =          3,
	Sc      =          4,
	Spi     =          5,
	Sq      =          6,
	Sx      =          7,
	Ta      =          8,
	Td      =          9,
	Tcp     =         10,
	Tcc     =         11,
	Tca     =         12,
	Db      =         13,
	Cb      =         14,
	Gds     =         15,
	Srbm    =         16,
	Grbm    =         17,
	GrbmSe  =         18,
	Rlc     =         19,
	Dma     =         20,
	Mc      =         21,
	Cpg     =         22,
	Cpc     =         23,
	Wd      =         24,
	Tcs     =         25,
	Atc     =         26,
	AtcL2   =         27,
	McVmL2  =         28,
	Ea      =         29,
	Rpb     =         30,
	Rmi     =         31,
	Umcch   =         32,
	Ge      =         33,
	Gl1A    =         34,
	Gl1C    =         35,
	Gl1Cg   =         36,
	Gl2A    =         37,
	Gl2C    =         38,
	Cha     =         39,
	Chc     =         40,
	Chcg    =         41,
	Gus     =         42,
	Gcr     =         43,
	Ph      =         44,
	Utcl1   =         45,
	GeDist  =         46,
	GeSe    =         47,
	DfMall  =         48,
	SqWgp   =         49,
	Pc      =         50,
	Gl1Xa   =         51,
	Gl1Xc   =         52,
	Wgs     =         53,
	Eacpwd  =         54,
	Ease    =         55,
	Rlcuser =         56,
};
enum class GpaPerfBlockPropertiesBitsAMD : std::int32_t {};
using GpaPerfBlockPropertiesFlagsAMD = impl_Enum::Flags<GpaPerfBlockPropertiesBitsAMD>;
enum class GpaSampleTypeAMD : std::int32_t {
	Cumulative =          0,
	Trace      =          1,
	Timing     =          2,
};
enum class GpaSqShaderStageBitsAMD : std::int32_t {
	Ps      = 0x00000001,
	Vs      = 0x00000002,
	Gs      = 0x00000004,
	Es      = 0x00000008,
	Hs      = 0x00000010,
	Ls      = 0x00000020,
	Cs      = 0x00000040,
	AllBits = 0x0000007f, // generated for ~(not), error checking and for convenience
};
using GpaSqShaderStageFlagsAMD = impl_Enum::Flags<GpaSqShaderStageBitsAMD>;
enum class GraphicsPipelineLibraryBitsEXT : std::int32_t {
	VertexInputInterface    = 0x00000001,
	PreRasterizationShaders = 0x00000002,
	FragmentShader          = 0x00000004,
	FragmentOutputInterface = 0x00000008,
	AllBits                 = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using GraphicsPipelineLibraryFlagsEXT = impl_Enum::Flags<GraphicsPipelineLibraryBitsEXT>;
enum class HeadlessSurfaceCreateBitsEXT : std::int32_t {};
using HeadlessSurfaceCreateFlagsEXT = impl_Enum::Flags<HeadlessSurfaceCreateBitsEXT>;
enum class HostImageCopyBits : std::int32_t {
	Memcpy  = 0x00000001,
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
using HostImageCopyFlags = impl_Enum::Flags<HostImageCopyBits>;
enum class IOSSurfaceCreateBitsMVK : std::int32_t {};
using IOSSurfaceCreateFlagsMVK = impl_Enum::Flags<IOSSurfaceCreateBitsMVK>;
enum class ImageAspectBits : std::int32_t {
	None               = 0x00000000,
	Color              = 0x00000001,
	Depth              = 0x00000002,
	Stencil            = 0x00000004,
	Metadata           = 0x00000008,
	Plane0             = 0x00000010,
	Plane1             = 0x00000020,
	Plane2             = 0x00000040,
	MemoryPlane0BitEXT = 0x00000080,
	MemoryPlane1BitEXT = 0x00000100,
	MemoryPlane2BitEXT = 0x00000200,
	MemoryPlane3BitEXT = 0x00000400,
	AllBits            = 0x000007ff, // generated for ~(not), error checking and for convenience
};
using ImageAspectFlags = impl_Enum::Flags<ImageAspectBits>;
enum class ImageCompressionFixedRateBitsEXT : std::int32_t {
	None    = 0x00000000,
	v1Bpc   = 0x00000001,
	v2Bpc   = 0x00000002,
	v3Bpc   = 0x00000004,
	v4Bpc   = 0x00000008,
	v5Bpc   = 0x00000010,
	v6Bpc   = 0x00000020,
	v7Bpc   = 0x00000040,
	v8Bpc   = 0x00000080,
	v9Bpc   = 0x00000100,
	v10Bpc  = 0x00000200,
	v11Bpc  = 0x00000400,
	v12Bpc  = 0x00000800,
	v13Bpc  = 0x00001000,
	v14Bpc  = 0x00002000,
	v15Bpc  = 0x00004000,
	v16Bpc  = 0x00008000,
	v17Bpc  = 0x00010000,
	v18Bpc  = 0x00020000,
	v19Bpc  = 0x00040000,
	v20Bpc  = 0x00080000,
	v21Bpc  = 0x00100000,
	v22Bpc  = 0x00200000,
	v23Bpc  = 0x00400000,
	v24Bpc  = 0x00800000,
	AllBits = 0x00ffffff, // generated for ~(not), error checking and for convenience
};
using ImageCompressionFixedRateFlagsEXT = impl_Enum::Flags<ImageCompressionFixedRateBitsEXT>;
enum class ImageCompressionBitsEXT : std::int32_t {
	Default           = 0x00000000,
	FixedRateDefault  = 0x00000001,
	FixedRateExplicit = 0x00000002,
	Disabled          = 0x00000004,
	AllBits           = 0x00000007, // generated for ~(not), error checking and for convenience
};
using ImageCompressionFlagsEXT = impl_Enum::Flags<ImageCompressionBitsEXT>;
enum class ImageConstraintsInfoBitsFUCHSIA : std::int32_t {
	CpuReadRarely     = 0x00000001,
	CpuReadOften      = 0x00000002,
	CpuWriteRarely    = 0x00000004,
	CpuWriteOften     = 0x00000008,
	ProtectedOptional = 0x00000010,
	AllBits           = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using ImageConstraintsInfoFlagsFUCHSIA = impl_Enum::Flags<ImageConstraintsInfoBitsFUCHSIA>;
enum class ImageCreateBits : std::int32_t {
	SparseBinding                           = 0x00000001, // Image should support sparse backing
	SparseResidency                         = 0x00000002, // Image should support sparse backing with partial residency
	SparseAliased                           = 0x00000004, // Image should support constant data access to physical memory ranges mapped into multiple locations of sparse images
	MutableFormat                           = 0x00000008, // Allows image views to have different format than the base image
	CubeCompatible                          = 0x00000010, // Allows creating image views with cube type from the created image
	v2DArrayCompatible                      = 0x00000020, // The 3D image can be viewed as a 2D or 2D array image
	SplitInstanceBindRegions                = 0x00000040, // Allows using VkBindImageMemoryDeviceGroupInfo::pSplitInstanceBindRegions when binding memory to the image
	BlockTexelViewCompatible                = 0x00000080,
	ExtendedUsage                           = 0x00000100,
	Disjoint                                = 0x00000200,
	Alias                                   = 0x00000400,
	Protected                               = 0x00000800, // Image requires protected memory
	SampleLocationsCompatibleDepthBitEXT    = 0x00001000,
	CornerSampledBitNV                      = 0x00002000,
	SubsampledBitEXT                        = 0x00004000,
	FragmentDensityMapOffsetBitEXT          = 0x00008000,
	DescriptorHeapCaptureReplayBitEXT       = 0x00010000,
	v2DViewCompatibleBitEXT                 = 0x00020000, // Image is created with a layout where individual slices are capable of being used as 2D images
	MultisampledRenderToSingleSampledBitEXT = 0x00040000,
	VideoProfileIndependentBitKHR           = 0x00100000,
	AliasSingleLayerDescriptorBitKHR        = 0x00400000,
	AllBits                                 = 0x0057ffff, // generated for ~(not), error checking and for convenience
};
using ImageCreateFlags = impl_Enum::Flags<ImageCreateBits>;
enum class ImageCreateBits2KHR : std::uint64_t {
	SparseBinding                           = 0x0000000000000001,
	SparseResidency                         = 0x0000000000000002,
	SparseAliased                           = 0x0000000000000004,
	MutableFormat                           = 0x0000000000000008,
	CubeCompatible                          = 0x0000000000000010,
	v2DArrayCompatible                      = 0x0000000000000020,
	SplitInstanceBindRegions                = 0x0000000000000040,
	BlockTexelViewCompatible                = 0x0000000000000080,
	ExtendedUsage                           = 0x0000000000000100,
	Disjoint                                = 0x0000000000000200,
	Alias                                   = 0x0000000000000400,
	Protected                               = 0x0000000000000800,
	SampleLocationsCompatibleDepthBitEXT    = 0x0000000000001000,
	CornerSampledBitNV                      = 0x0000000000002000,
	SubsampledBitEXT                        = 0x0000000000004000,
	FragmentDensityMapOffsetBitEXT          = 0x0000000000008000,
	DescriptorBufferCaptureReplayBitEXT     = 0x0000000000010000,
	v2DViewCompatibleBitEXT                 = 0x0000000000020000,
	MultisampledRenderToSingleSampledBitEXT = 0x0000000000040000,
	VideoProfileIndependent                 = 0x0000000000100000,
	AliasSingleLayerDescriptor              = 0x0000000000400000,
	AllBits                                 = 0x000000000057ffff, // generated for ~(not), error checking and for convenience
};
using ImageCreateFlags2KHR = impl_Enum::Flags<ImageCreateBits2KHR>;
enum class ImageFormatConstraintsBitsFUCHSIA : std::int32_t {};
using ImageFormatConstraintsFlagsFUCHSIA = impl_Enum::Flags<ImageFormatConstraintsBitsFUCHSIA>;
enum class ImageLayout : std::int32_t {
	Undefined                               =          0, // Implicit layout an image is when its contents are undefined due to various reasons (e.g. right after creation)
	General                                 =          1, // General layout when image can be used for any kind of access
	ColorAttachmentOptimal                  =          2, // Optimal layout when image is only used for color attachment read/write
	DepthStencilAttachmentOptimal           =          3, // Optimal layout when image is only used for depth/stencil attachment read/write
	DepthStencilReadOnlyOptimal             =          4, // Optimal layout when image is used for read only depth/stencil attachment and shader access
	ShaderReadOnlyOptimal                   =          5, // Optimal layout when image is used for read only shader access
	TransferSrcOptimal                      =          6, // Optimal layout when image is used only as source of transfer operations
	TransferDstOptimal                      =          7, // Optimal layout when image is used only as destination of transfer operations
	Preinitialized                          =          8, // Initial layout used when the data is populated by the CPU
	PresentSrcKHR                           = 1000001002,
	VideoDecodeDstKHR                       = 1000024000,
	VideoDecodeSrcKHR                       = 1000024001,
	VideoDecodeDpbKHR                       = 1000024002,
	SharedPresentKHR                        = 1000111000,
	DepthReadOnlyStencilAttachmentOptimal   = 1000117000,
	DepthAttachmentStencilReadOnlyOptimal   = 1000117001,
	FragmentShadingRateAttachmentOptimalKHR = 1000164003,
	FragmentDensityMapOptimalEXT            = 1000218000,
	RenderingLocalRead                      = 1000232000,
	DepthAttachmentOptimal                  = 1000241000,
	DepthReadOnlyOptimal                    = 1000241001,
	StencilAttachmentOptimal                = 1000241002,
	StencilReadOnlyOptimal                  = 1000241003,
	VideoEncodeDstKHR                       = 1000299000,
	VideoEncodeSrcKHR                       = 1000299001,
	VideoEncodeDpbKHR                       = 1000299002,
	ReadOnlyOptimal                         = 1000314000,
	AttachmentOptimal                       = 1000314001,
	AttachmentFeedbackLoopOptimalEXT        = 1000339000,
	TensorAliasingARM                       = 1000460000,
	VideoEncodeQuantizationMapKHR           = 1000553000,
	ZeroInitializedEXT                      = 1000620000,
};
enum class ImagePipeSurfaceCreateBitsFUCHSIA : std::int32_t {};
using ImagePipeSurfaceCreateFlagsFUCHSIA = impl_Enum::Flags<ImagePipeSurfaceCreateBitsFUCHSIA>;
enum class ImageTiling : std::int32_t {
	Optimal              =          0,
	Linear               =          1,
	DrmFormatModifierEXT = 1000158000,
};
enum class ImageType : std::int32_t {
	v1D =          0,
	v2D =          1,
	v3D =          2,
};
enum class ImageUsageBits : std::int32_t {
	TransferSrc                           = 0x00000001, // Can be used as a source of transfer operations
	TransferDst                           = 0x00000002, // Can be used as a destination of transfer operations
	Sampled                               = 0x00000004, // Can be sampled from (SAMPLED_IMAGE and COMBINED_IMAGE_SAMPLER descriptor types)
	Storage                               = 0x00000008, // Can be used as storage image (STORAGE_IMAGE descriptor type)
	ColorAttachment                       = 0x00000010, // Can be used as framebuffer color attachment
	DepthStencilAttachment                = 0x00000020, // Can be used as framebuffer depth/stencil attachment
	TransientAttachment                   = 0x00000040, // Image data not needed outside of rendering
	InputAttachment                       = 0x00000080, // Can be used as framebuffer input attachment
	FragmentShadingRateAttachmentBitKHR   = 0x00000100,
	FragmentDensityMapBitEXT              = 0x00000200,
	VideoDecodeDstBitKHR                  = 0x00000400,
	VideoDecodeSrcBitKHR                  = 0x00000800,
	VideoDecodeDpbBitKHR                  = 0x00001000,
	VideoEncodeDstBitKHR                  = 0x00002000,
	VideoEncodeSrcBitKHR                  = 0x00004000,
	VideoEncodeDpbBitKHR                  = 0x00008000,
	InvocationMaskBitHUAWEI               = 0x00040000,
	AttachmentFeedbackLoopBitEXT          = 0x00080000,
	SampleWeightBitQCOM                   = 0x00100000,
	SampleBlockMatchBitQCOM               = 0x00200000,
	HostTransfer                          = 0x00400000,
	TensorAliasingBitARM                  = 0x00800000,
	VideoEncodeQuantizationDeltaMapBitKHR = 0x02000000,
	VideoEncodeEmphasisMapBitKHR          = 0x04000000,
	TileMemoryBitQCOM                     = 0x08000000,
	AllBits                               = 0x0efcffff, // generated for ~(not), error checking and for convenience
};
using ImageUsageFlags = impl_Enum::Flags<ImageUsageBits>;
enum class ImageUsageBits2KHR : std::uint64_t {
	TransferSrc                     = 0x0000000000000001,
	TransferDst                     = 0x0000000000000002,
	Sampled                         = 0x0000000000000004,
	Storage                         = 0x0000000000000008,
	ColorAttachment                 = 0x0000000000000010,
	DepthStencilAttachment          = 0x0000000000000020,
	TransientAttachment             = 0x0000000000000040,
	InputAttachment                 = 0x0000000000000080,
	FragmentShadingRateAttachment   = 0x0000000000000100,
	FragmentDensityMapBitEXT        = 0x0000000000000200,
	VideoDecodeDst                  = 0x0000000000000400,
	VideoDecodeSrc                  = 0x0000000000000800,
	VideoDecodeDpb                  = 0x0000000000001000,
	VideoEncodeDst                  = 0x0000000000002000,
	VideoEncodeSrc                  = 0x0000000000004000,
	VideoEncodeDpb                  = 0x0000000000008000,
	InvocationMaskBitHUAWEI         = 0x0000000000040000,
	AttachmentFeedbackLoopBitEXT    = 0x0000000000080000,
	SampleWeightBitQCOM             = 0x0000000000100000,
	SampleBlockMatchBitQCOM         = 0x0000000000200000,
	HostTransfer                    = 0x0000000000400000,
	TensorAliasingBitARM            = 0x0000000000800000,
	VideoEncodeQuantizationDeltaMap = 0x0000000002000000,
	VideoEncodeEmphasisMap          = 0x0000000004000000,
	TileMemoryBitQCOM               = 0x0000000008000000,
	AllBits                         = 0x000000000efcffff, // generated for ~(not), error checking and for convenience
};
using ImageUsageFlags2KHR = impl_Enum::Flags<ImageUsageBits2KHR>;
enum class ImageViewCreateBits : std::int32_t {
	FragmentDensityMapDynamicBitEXT     = 0x00000001,
	FragmentDensityMapDeferredBitEXT    = 0x00000002,
	DescriptorBufferCaptureReplayBitEXT = 0x00000004,
	AllBits                             = 0x00000007, // generated for ~(not), error checking and for convenience
};
using ImageViewCreateFlags = impl_Enum::Flags<ImageViewCreateBits>;
enum class ImageViewType : std::int32_t {
	v1D       =          0,
	v2D       =          1,
	v3D       =          2,
	Cube      =          3,
	v1DArray  =          4,
	v2DArray  =          5,
	CubeArray =          6,
};
enum class IndexType : std::int32_t {
	Uint16  =          0,
	Uint32  =          1,
	NoneKHR = 1000165000,
	Uint8   = 1000265000,
};
enum class IndirectCommandsInputModeBitsEXT : std::int32_t {
	VulkanIndexBuffer = 0x00000001,
	DxgiIndexBuffer   = 0x00000002,
	AllBits           = 0x00000003, // generated for ~(not), error checking and for convenience
};
using IndirectCommandsInputModeFlagsEXT = impl_Enum::Flags<IndirectCommandsInputModeBitsEXT>;
enum class IndirectCommandsLayoutUsageBitsEXT : std::int32_t {
	ExplicitPreprocess = 0x00000001,
	UnorderedSequences = 0x00000002,
	AllBits            = 0x00000003, // generated for ~(not), error checking and for convenience
};
using IndirectCommandsLayoutUsageFlagsEXT = impl_Enum::Flags<IndirectCommandsLayoutUsageBitsEXT>;
enum class IndirectCommandsLayoutUsageBitsNV : std::int32_t {
	ExplicitPreprocess = 0x00000001,
	IndexedSequences   = 0x00000002,
	UnorderedSequences = 0x00000004,
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
using IndirectCommandsLayoutUsageFlagsNV = impl_Enum::Flags<IndirectCommandsLayoutUsageBitsNV>;
enum class IndirectCommandsTokenTypeEXT : std::int32_t {
	ExecutionSet          =          0,
	PushConstant          =          1,
	SequenceIndex         =          2,
	IndexBuffer           =          3,
	VertexBuffer          =          4,
	DrawIndexed           =          5,
	Draw                  =          6,
	DrawIndexedCount      =          7,
	DrawCount             =          8,
	Dispatch              =          9,
	PushData              = 1000135000,
	PushDataSequenceIndex = 1000135001,
	DrawMeshTasksNV       = 1000202002,
	DrawMeshTasksCountNV  = 1000202003,
	DrawMeshTasks         = 1000328000,
	DrawMeshTasksCount    = 1000328001,
	TraceRays2            = 1000386004,
};
enum class IndirectCommandsTokenTypeNV : std::int32_t {
	ShaderGroup   =          0,
	StateFlags    =          1,
	IndexBuffer   =          2,
	VertexBuffer  =          3,
	PushConstant  =          4,
	DrawIndexed   =          5,
	Draw          =          6,
	DrawTasks     =          7,
	PushData      = 1000135000,
	DrawMeshTasks = 1000328000,
	Pipeline      = 1000428003,
	Dispatch      = 1000428004,
};
enum class IndirectExecutionSetInfoTypeEXT : std::int32_t {
	Pipelines     =          0,
	ShaderObjects =          1,
};
enum class IndirectStateBitsNV : std::int32_t {
	FlagFrontface = 0x00000001,
	AllBits       = 0x00000001, // generated for ~(not), error checking and for convenience
};
using IndirectStateFlagsNV = impl_Enum::Flags<IndirectStateBitsNV>;
enum class InstanceCreateBits : std::int32_t {
	EnumeratePortabilityBitKHR = 0x00000001,
	AllBits                    = 0x00000001, // generated for ~(not), error checking and for convenience
};
using InstanceCreateFlags = impl_Enum::Flags<InstanceCreateBits>;
enum class InternalAllocationType : std::int32_t {
	Executable =          0,
};
enum class LatencyMarkerNV : std::int32_t {
	SimulationStart            =          0,
	SimulationEnd              =          1,
	RendersubmitStart          =          2,
	RendersubmitEnd            =          3,
	PresentStart               =          4,
	PresentEnd                 =          5,
	InputSample                =          6,
	TriggerFlash               =          7,
	OutOfBandRendersubmitStart =          8,
	OutOfBandRendersubmitEnd   =          9,
	OutOfBandPresentStart      =         10,
	OutOfBandPresentEnd        =         11,
};
enum class LayerSettingTypeEXT : std::int32_t {
	Bool32  =          0,
	Int32   =          1,
	Int64   =          2,
	Uint32  =          3,
	Uint64  =          4,
	Float32 =          5,
	Float64 =          6,
	String  =          7,
};
enum class LayeredDriverUnderlyingApiMSFT : std::int32_t {
	None  =          0,
	D3D12 =          1,
};
enum class LineRasterizationMode : std::int32_t {
	Default           =          0,
	Rectangular       =          1,
	Bresenham         =          2,
	RectangularSmooth =          3,
};
enum class LogicOp : std::int32_t {
	Clear        =          0,
	And          =          1,
	AndReverse   =          2,
	Copy         =          3,
	AndInverted  =          4,
	NoOp         =          5,
	Xor          =          6,
	Or           =          7,
	Nor          =          8,
	Equivalent   =          9,
	Invert       =         10,
	OrReverse    =         11,
	CopyInverted =         12,
	OrInverted   =         13,
	Nand         =         14,
	Set          =         15,
};
enum class MacOSSurfaceCreateBitsMVK : std::int32_t {};
using MacOSSurfaceCreateFlagsMVK = impl_Enum::Flags<MacOSSurfaceCreateBitsMVK>;
enum class MemoryAllocateBits : std::int32_t {
	DeviceMask                 = 0x00000001, // Force allocation on specific devices
	DeviceAddress              = 0x00000002,
	DeviceAddressCaptureReplay = 0x00000004,
	ZeroInitializeBitEXT       = 0x00000008,
	AllBits                    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using MemoryAllocateFlags = impl_Enum::Flags<MemoryAllocateBits>;
enum class MemoryDecompressionMethodBitsEXT : std::uint64_t {
	Gdeflate10 = 0x0000000000000001,
	AllBits    = 0x0000000000000001, // generated for ~(not), error checking and for convenience
};
using MemoryDecompressionMethodFlagsEXT = impl_Enum::Flags<MemoryDecompressionMethodBitsEXT>;
enum class MemoryHeapBits : std::int32_t {
	DeviceLocal       = 0x00000001, // If set, heap represents device memory
	MultiInstance     = 0x00000002, // If set, heap allocations allocate multiple instances by default
	TileMemoryBitQCOM = 0x00000008,
	AllBits           = 0x0000000b, // generated for ~(not), error checking and for convenience
};
using MemoryHeapFlags = impl_Enum::Flags<MemoryHeapBits>;
enum class MemoryMapBits : std::int32_t {
	PlacedBitEXT = 0x00000001,
	AllBits      = 0x00000001, // generated for ~(not), error checking and for convenience
};
using MemoryMapFlags = impl_Enum::Flags<MemoryMapBits>;
enum class MemoryOverallocationBehaviorAMD : std::int32_t {
	Default    =          0,
	Allowed    =          1,
	Disallowed =          2,
};
enum class MemoryPropertyBits : std::int32_t {
	DeviceLocal          = 0x00000001, // If otherwise stated, then allocate memory on device
	HostVisible          = 0x00000002, // Memory is mappable by host
	HostCoherent         = 0x00000004, // Memory will have i/o coherency. If not set, application may need to use vkFlushMappedMemoryRanges and vkInvalidateMappedMemoryRanges to flush/invalidate host cache
	HostCached           = 0x00000008, // Memory will be cached by the host
	LazilyAllocated      = 0x00000010, // Memory may be allocated by the driver when it is required
	Protected            = 0x00000020, // Memory is protected
	DeviceCoherentBitAMD = 0x00000040,
	DeviceUncachedBitAMD = 0x00000080,
	RdmaCapableBitNV     = 0x00000100,
	AllBits              = 0x000001ff, // generated for ~(not), error checking and for convenience
};
using MemoryPropertyFlags = impl_Enum::Flags<MemoryPropertyBits>;
enum class MemoryUnmapBits : std::int32_t {
	ReserveBitEXT = 0x00000001,
	AllBits       = 0x00000001, // generated for ~(not), error checking and for convenience
};
using MemoryUnmapFlags = impl_Enum::Flags<MemoryUnmapBits>;
enum class MetalSurfaceCreateBitsEXT : std::int32_t {};
using MetalSurfaceCreateFlagsEXT = impl_Enum::Flags<MetalSurfaceCreateBitsEXT>;
enum class MicromapCreateBitsEXT : std::int32_t {
	DeviceAddressCaptureReplay = 0x00000001,
	AllBits                    = 0x00000001, // generated for ~(not), error checking and for convenience
};
using MicromapCreateFlagsEXT = impl_Enum::Flags<MicromapCreateBitsEXT>;
enum class MicromapTypeEXT : std::int32_t {
	OpacityMicromap        =          0,
	DisplacementMicromapNV = 1000397000,
};
enum class NeuralAcceleratorStatisticsModeARM : std::int32_t {
	Disabled    =          0,
	Statistics0 =          1,
	Statistics1 =          2,
};
enum class ObjectType : std::int32_t {
	Unknown                       =          0,
	Instance                      =          1,
	PhysicalDevice                =          2,
	Device                        =          3,
	Queue                         =          4,
	Semaphore                     =          5,
	CommandBuffer                 =          6,
	Fence                         =          7,
	DeviceMemory                  =          8,
	Buffer                        =          9,
	Image                         =         10,
	Event                         =         11,
	QueryPool                     =         12,
	BufferView                    =         13,
	ImageView                     =         14,
	ShaderModule                  =         15,
	PipelineCache                 =         16,
	PipelineLayout                =         17,
	RenderPass                    =         18,
	Pipeline                      =         19,
	DescriptorSetLayout           =         20,
	Sampler                       =         21,
	DescriptorPool                =         22,
	DescriptorSet                 =         23,
	Framebuffer                   =         24,
	CommandPool                   =         25,
	SurfaceKHR                    = 1000000000,
	SwapchainKHR                  = 1000001000,
	DisplayKHR                    = 1000002000,
	DisplayModeKHR                = 1000002001,
	DebugReportCallbackEXT        = 1000011000,
	VideoSessionKHR               = 1000023000, // VkVideoSessionKHR
	VideoSessionParametersKHR     = 1000023001, // VkVideoSessionParametersKHR
	CuModuleNVX                   = 1000029000,
	CuFunctionNVX                 = 1000029001,
	DescriptorUpdateTemplate      = 1000085000,
	DebugUtilsMessengerEXT        = 1000128000,
	GpaSessionAMD                 = 1000133000,
	AccelerationStructureKHR      = 1000150000,
	SamplerYcbcrConversion        = 1000156000,
	ValidationCacheEXT            = 1000160000,
	AccelerationStructureNV       = 1000165000,
	PerformanceConfigurationINTEL = 1000210000,
	DeferredOperationKHR          = 1000268000,
	IndirectCommandsLayoutNV      = 1000277000,
	PrivateDataSlot               = 1000295000,
	CudaModuleNV                  = 1000307000,
	CudaFunctionNV                = 1000307001,
	BufferCollectionFUCHSIA       = 1000366000, // VkBufferCollectionFUCHSIA
	MicromapEXT                   = 1000396000,
	TensorARM                     = 1000460000,
	TensorViewARM                 = 1000460001,
	OpticalFlowSessionNV          = 1000464000,
	ShaderEXT                     = 1000482000,
	PipelineBinaryKHR             = 1000483000,
	DataGraphPipelineSessionARM   = 1000507000,
	ExternalComputeQueueNV        = 1000556000,
	IndirectCommandsLayoutEXT     = 1000572000,
	IndirectExecutionSetEXT       = 1000572001,
	ShaderInstrumentationARM      = 1000607000,
};
enum class OpacityMicromapFormatKHR : std::int32_t {
	v2State =          1,
	v4State =          2,
};
enum class OpacityMicromapSpecialIndexKHR : std::int32_t {
	FullyTransparent                        = -         1,
	FullyOpaque                             = -         2,
	FullyUnknownTransparent                 = -         3,
	FullyUnknownOpaque                      = -         4,
	ClusterGeometryDisableOpacityMicromapNV = -         5,
};
enum class OpticalFlowExecuteBitsNV : std::int32_t {
	DisableTemporalHints = 0x00000001,
	AllBits              = 0x00000001, // generated for ~(not), error checking and for convenience
};
using OpticalFlowExecuteFlagsNV = impl_Enum::Flags<OpticalFlowExecuteBitsNV>;
enum class OpticalFlowGridSizeBitsNV : std::int32_t {
	Unknown = 0x00000000,
	v1x1    = 0x00000001,
	v2x2    = 0x00000002,
	v4x4    = 0x00000004,
	v8x8    = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using OpticalFlowGridSizeFlagsNV = impl_Enum::Flags<OpticalFlowGridSizeBitsNV>;
enum class OpticalFlowPerformanceLevelNV : std::int32_t {
	Unknown =          0,
	Slow    =          1,
	Medium  =          2,
	Fast    =          3,
};
enum class OpticalFlowSessionBindingPointNV : std::int32_t {
	Unknown            =          0,
	Input              =          1,
	Reference          =          2,
	Hint               =          3,
	FlowVector         =          4,
	BackwardFlowVector =          5,
	Cost               =          6,
	BackwardCost       =          7,
	GlobalFlow         =          8,
};
enum class OpticalFlowSessionCreateBitsNV : std::int32_t {
	EnableHint       = 0x00000001,
	EnableCost       = 0x00000002,
	EnableGlobalFlow = 0x00000004,
	AllowRegions     = 0x00000008,
	BothDirections   = 0x00000010,
	AllBits          = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using OpticalFlowSessionCreateFlagsNV = impl_Enum::Flags<OpticalFlowSessionCreateBitsNV>;
enum class OpticalFlowUsageBitsNV : std::int32_t {
	Unknown    = 0x00000000,
	Input      = 0x00000001,
	Output     = 0x00000002,
	Hint       = 0x00000004,
	Cost       = 0x00000008,
	GlobalFlow = 0x00000010,
	AllBits    = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using OpticalFlowUsageFlagsNV = impl_Enum::Flags<OpticalFlowUsageBitsNV>;
enum class OutOfBandQueueTypeNV : std::int32_t {
	Render  =          0,
	Present =          1,
};
enum class PartitionedAccelerationStructureInstanceBitsNV : std::int32_t {
	FlagTriangleFacingCullDisable = 0x00000001,
	FlagTriangleFlipFacing        = 0x00000002,
	FlagForceOpaque               = 0x00000004,
	FlagForceNoOpaque             = 0x00000008,
	FlagEnableExplicitBoundingBox = 0x00000010,
	AllBits                       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using PartitionedAccelerationStructureInstanceFlagsNV = impl_Enum::Flags<PartitionedAccelerationStructureInstanceBitsNV>;
enum class PartitionedAccelerationStructureOpTypeNV : std::int32_t {
	WriteInstance             =          0,
	UpdateInstance            =          1,
	WritePartitionTranslation =          2,
};
enum class PastPresentationTimingBitsEXT : std::int32_t {
	AllowPartialResults    = 0x00000001,
	AllowOutOfOrderResults = 0x00000002,
	AllBits                = 0x00000003, // generated for ~(not), error checking and for convenience
};
using PastPresentationTimingFlagsEXT = impl_Enum::Flags<PastPresentationTimingBitsEXT>;
enum class PeerMemoryFeatureBits : std::int32_t {
	CopySrc    = 0x00000001, // Can read with vkCmdCopy commands
	CopyDst    = 0x00000002, // Can write with vkCmdCopy commands
	GenericSrc = 0x00000004, // Can read with any access type/command
	GenericDst = 0x00000008, // Can write with and access type/command
	AllBits    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using PeerMemoryFeatureFlags = impl_Enum::Flags<PeerMemoryFeatureBits>;
enum class PerfHintTypeQCOM : std::int32_t {
	Default         =          0,
	FrequencyMin    =          1,
	FrequencyMax    =          2,
	FrequencyScaled =          3,
};
enum class PerformanceConfigurationTypeINTEL : std::int32_t {
	CommandQueueMetricsDiscoveryActivated =          0,
};
enum class PerformanceCounterDescriptionBitsARM : std::int32_t {};
using PerformanceCounterDescriptionFlagsARM = impl_Enum::Flags<PerformanceCounterDescriptionBitsARM>;
enum class PerformanceCounterDescriptionBitsKHR : std::int32_t {
	PerformanceImpacting = 0x00000001,
	ConcurrentlyImpacted = 0x00000002,
	AllBits              = 0x00000003, // generated for ~(not), error checking and for convenience
};
using PerformanceCounterDescriptionFlagsKHR = impl_Enum::Flags<PerformanceCounterDescriptionBitsKHR>;
enum class PerformanceCounterScopeKHR : std::int32_t {
	CommandBuffer =          0,
	RenderPass    =          1,
	Command       =          2,
};
enum class PerformanceCounterStorageKHR : std::int32_t {
	Int32   =          0,
	Int64   =          1,
	Uint32  =          2,
	Uint64  =          3,
	Float32 =          4,
	Float64 =          5,
};
enum class PerformanceCounterUnitKHR : std::int32_t {
	Generic        =          0,
	Percentage     =          1,
	Nanoseconds    =          2,
	Bytes          =          3,
	BytesPerSecond =          4,
	Kelvin         =          5,
	Watts          =          6,
	Volts          =          7,
	Amps           =          8,
	Hertz          =          9,
	Cycles         =         10,
};
enum class PerformanceOverrideTypeINTEL : std::int32_t {
	NullHardware   =          0,
	FlushGpuCaches =          1,
};
enum class PerformanceParameterTypeINTEL : std::int32_t {
	HwCountersSupported   =          0,
	StreamMarkerValidBits =          1,
};
enum class PerformanceValueTypeINTEL : std::int32_t {
	Uint32 =          0,
	Uint64 =          1,
	Float  =          2,
	Bool   =          3,
	String =          4,
};
enum class PhysicalDeviceDataGraphOperationTypeARM : std::int32_t {
	SpirvExtendedInstructionSet =          0,
	NeuralModelQCOM             = 1000629000,
	BuiltinModelQCOM            = 1000629001,
	OpticalFlow                 = 1000631000,
};
enum class PhysicalDeviceDataGraphProcessingEngineTypeARM : std::int32_t {
	Default     =          0,
	NeuralQCOM  = 1000629000,
	ComputeQCOM = 1000629001,
};
enum class PhysicalDeviceGpaPropertiesBitsAMD : std::int32_t {};
using PhysicalDeviceGpaPropertiesFlagsAMD = impl_Enum::Flags<PhysicalDeviceGpaPropertiesBitsAMD>;
enum class PhysicalDeviceLayeredApiKHR : std::int32_t {
	Vulkan   =          0,
	D3D12    =          1,
	Metal    =          2,
	Opengl   =          3,
	Opengles =          4,
};
enum class PhysicalDeviceSchedulingControlsBitsARM : std::uint64_t {
	ShaderCoreCount    = 0x0000000000000001,
	DispatchParameters = 0x0000000000000002,
	AllBits            = 0x0000000000000003, // generated for ~(not), error checking and for convenience
};
using PhysicalDeviceSchedulingControlsFlagsARM = impl_Enum::Flags<PhysicalDeviceSchedulingControlsBitsARM>;
enum class PhysicalDeviceType : std::int32_t {
	Other         =          0,
	IntegratedGpu =          1,
	DiscreteGpu   =          2,
	VirtualGpu    =          3,
	Cpu           =          4,
};
enum class PipelineBindPoint : std::int32_t {
	Graphics             =          0,
	Compute              =          1,
	ExecutionGraphAMDX   = 1000134000,
	RayTracingKHR        = 1000165000,
	SubpassShadingHUAWEI = 1000369003,
	DataGraphARM         = 1000507000,
};
enum class PipelineCacheCreateBits : std::int32_t {
	ExternallySynchronized            = 0x00000001,
	InternallySynchronizedMergeBitKHR = 0x00000008,
	AllBits                           = 0x00000009, // generated for ~(not), error checking and for convenience
};
using PipelineCacheCreateFlags = impl_Enum::Flags<PipelineCacheCreateBits>;
enum class PipelineCacheHeaderVersion : std::int32_t {
	One           =          1,
	DataGraphQCOM = 1000629000,
};
enum class PipelineColorBlendStateCreateBits : std::int32_t {
	RasterizationOrderAttachmentAccessBitEXT = 0x00000001,
	AllBits                                  = 0x00000001, // generated for ~(not), error checking and for convenience
};
using PipelineColorBlendStateCreateFlags = impl_Enum::Flags<PipelineColorBlendStateCreateBits>;
enum class PipelineCompilerControlBitsAMD : std::int32_t {};
using PipelineCompilerControlFlagsAMD = impl_Enum::Flags<PipelineCompilerControlBitsAMD>;
enum class PipelineCoverageModulationStateCreateBitsNV : std::int32_t {};
using PipelineCoverageModulationStateCreateFlagsNV = impl_Enum::Flags<PipelineCoverageModulationStateCreateBitsNV>;
enum class PipelineCoverageReductionStateCreateBitsNV : std::int32_t {};
using PipelineCoverageReductionStateCreateFlagsNV = impl_Enum::Flags<PipelineCoverageReductionStateCreateBitsNV>;
enum class PipelineCoverageToColorStateCreateBitsNV : std::int32_t {};
using PipelineCoverageToColorStateCreateFlagsNV = impl_Enum::Flags<PipelineCoverageToColorStateCreateBitsNV>;
enum class PipelineCreateBits : std::int32_t {
	DisableOptimization                            = 0x00000001,
	AllowDerivatives                               = 0x00000002,
	Derivative                                     = 0x00000004,
	ViewIndexFromDeviceIndex                       = 0x00000008,
	DispatchBase                                   = 0x00000010,
	DeferCompileBitNV                              = 0x00000020,
	CaptureStatisticsBitKHR                        = 0x00000040,
	CaptureInternalRepresentationsBitKHR           = 0x00000080,
	FailOnPipelineCompileRequired                  = 0x00000100,
	EarlyReturnOnFailure                           = 0x00000200,
	LinkTimeOptimizationBitEXT                     = 0x00000400,
	LibraryBitKHR                                  = 0x00000800,
	RayTracingSkipTrianglesBitKHR                  = 0x00001000,
	RayTracingSkipAabbsBitKHR                      = 0x00002000,
	RayTracingNoNullAnyHitShadersBitKHR            = 0x00004000,
	RayTracingNoNullClosestHitShadersBitKHR        = 0x00008000,
	RayTracingNoNullMissShadersBitKHR              = 0x00010000,
	RayTracingNoNullIntersectionShadersBitKHR      = 0x00020000,
	IndirectBindableBitNV                          = 0x00040000,
	RayTracingShaderGroupHandleCaptureReplayBitKHR = 0x00080000,
	RayTracingAllowMotionBitNV                     = 0x00100000,
	RenderingFragmentShadingRateAttachmentBitKHR   = 0x00200000,
	RenderingFragmentDensityMapAttachmentBitEXT    = 0x00400000,
	RetainLinkTimeOptimizationInfoBitEXT           = 0x00800000,
	RayTracingOpacityMicromapBitKHR                = 0x01000000,
	ColorAttachmentFeedbackLoopBitEXT              = 0x02000000,
	DepthStencilAttachmentFeedbackLoopBitEXT       = 0x04000000,
	NoProtectedAccess                              = 0x08000000,
	RayTracingDisplacementMicromapBitNV            = 0x10000000,
	DescriptorBufferBitEXT                         = 0x20000000,
	ProtectedAccessOnly                            = 0x40000000,
	AllBits                                        = 0x7fffffff, // generated for ~(not), error checking and for convenience
};
using PipelineCreateFlags = impl_Enum::Flags<PipelineCreateBits>;
enum class PipelineCreateBits2 : std::uint64_t {
	DisableOptimization                              = 0x0000000000000001,
	AllowDerivatives                                 = 0x0000000000000002,
	Derivative                                       = 0x0000000000000004,
	ViewIndexFromDeviceIndex                         = 0x0000000000000008,
	DispatchBase                                     = 0x0000000000000010,
	DeferCompileBitNV                                = 0x0000000000000020,
	CaptureStatisticsBitKHR                          = 0x0000000000000040,
	CaptureInternalRepresentationsBitKHR             = 0x0000000000000080,
	FailOnPipelineCompileRequired                    = 0x0000000000000100,
	EarlyReturnOnFailure                             = 0x0000000000000200,
	LinkTimeOptimizationBitEXT                       = 0x0000000000000400,
	LibraryBitKHR                                    = 0x0000000000000800,
	RayTracingSkipTrianglesBitKHR                    = 0x0000000000001000,
	RayTracingSkipAabbsBitKHR                        = 0x0000000000002000,
	RayTracingNoNullAnyHitShadersBitKHR              = 0x0000000000004000,
	RayTracingNoNullClosestHitShadersBitKHR          = 0x0000000000008000,
	RayTracingNoNullMissShadersBitKHR                = 0x0000000000010000,
	RayTracingNoNullIntersectionShadersBitKHR        = 0x0000000000020000,
	IndirectBindableBitNV                            = 0x0000000000040000,
	RayTracingShaderGroupHandleCaptureReplayBitKHR   = 0x0000000000080000,
	RayTracingAllowMotionBitNV                       = 0x0000000000100000,
	RenderingFragmentShadingRateAttachmentBitKHR     = 0x0000000000200000,
	RenderingFragmentDensityMapAttachmentBitEXT      = 0x0000000000400000,
	RetainLinkTimeOptimizationInfoBitEXT             = 0x0000000000800000,
	RayTracingOpacityMicromapBitKHR                  = 0x0000000001000000,
	ColorAttachmentFeedbackLoopBitEXT                = 0x0000000002000000,
	DepthStencilAttachmentFeedbackLoopBitEXT         = 0x0000000004000000,
	NoProtectedAccess                                = 0x0000000008000000,
	RayTracingDisplacementMicromapBitNV              = 0x0000000010000000,
	DescriptorBufferBitEXT                           = 0x0000000020000000,
	ProtectedAccessOnly                              = 0x0000000040000000,
	CaptureDataBitKHR                                = 0x0000000080000000,
	ExecutionGraphBitAMDX                            = 0x0000000100000000,
	RayTracingAllowSpheresAndLinearSweptSpheresBitNV = 0x0000000200000000,
	EnableLegacyDitheringBitEXT                      = 0x0000000400000000,
	DescriptorHeapBitEXT                             = 0x0000001000000000,
	DisallowOpacityMicromapBitARM                    = 0x0000002000000000,
	IndirectBindableBitEXT                           = 0x0000004000000000,
	InstrumentShadersBitARM                          = 0x0000008000000000,
	PerLayerFragmentDensityBitVALVE                  = 0x0000010000000000,
	OpacityMicromapDisallowMixedSpecialIndexBitKHR   = 0x0000020000000000,
	v64BitIndexingBitEXT                             = 0x0000080000000000,
	AllBits                                          = 0x00000bf7ffffffff, // generated for ~(not), error checking and for convenience
};
using PipelineCreateFlags2 = impl_Enum::Flags<PipelineCreateBits2>;
enum class PipelineCreationFeedbackBits : std::int32_t {
	Valid                       = 0x00000001,
	ApplicationPipelineCacheHit = 0x00000002,
	BasePipelineAcceleration    = 0x00000004,
	AllBits                     = 0x00000007, // generated for ~(not), error checking and for convenience
};
using PipelineCreationFeedbackFlags = impl_Enum::Flags<PipelineCreationFeedbackBits>;
enum class PipelineDepthStencilStateCreateBits : std::int32_t {
	RasterizationOrderAttachmentDepthAccessBitEXT   = 0x00000001,
	RasterizationOrderAttachmentStencilAccessBitEXT = 0x00000002,
	AllBits                                         = 0x00000003, // generated for ~(not), error checking and for convenience
};
using PipelineDepthStencilStateCreateFlags = impl_Enum::Flags<PipelineDepthStencilStateCreateBits>;
enum class PipelineDiscardRectangleStateCreateBitsEXT : std::int32_t {};
using PipelineDiscardRectangleStateCreateFlagsEXT = impl_Enum::Flags<PipelineDiscardRectangleStateCreateBitsEXT>;
enum class PipelineDynamicStateCreateBits : std::int32_t {};
using PipelineDynamicStateCreateFlags = impl_Enum::Flags<PipelineDynamicStateCreateBits>;
enum class PipelineExecutableStatisticFormatKHR : std::int32_t {
	Bool32  =          0,
	Int64   =          1,
	Uint64  =          2,
	Float64 =          3,
};
enum class PipelineInputAssemblyStateCreateBits : std::int32_t {};
using PipelineInputAssemblyStateCreateFlags = impl_Enum::Flags<PipelineInputAssemblyStateCreateBits>;
enum class PipelineLayoutCreateBits : std::int32_t {
	IndependentSetsBitEXT = 0x00000002,
	NoTaskShaderBitKHR    = 0x00000004,
	AllBits               = 0x00000006, // generated for ~(not), error checking and for convenience
};
using PipelineLayoutCreateFlags = impl_Enum::Flags<PipelineLayoutCreateBits>;
enum class PipelineMultisampleStateCreateBits : std::int32_t {};
using PipelineMultisampleStateCreateFlags = impl_Enum::Flags<PipelineMultisampleStateCreateBits>;
enum class PipelineRasterizationConservativeStateCreateBitsEXT : std::int32_t {};
using PipelineRasterizationConservativeStateCreateFlagsEXT = impl_Enum::Flags<PipelineRasterizationConservativeStateCreateBitsEXT>;
enum class PipelineRasterizationDepthClipStateCreateBitsEXT : std::int32_t {};
using PipelineRasterizationDepthClipStateCreateFlagsEXT = impl_Enum::Flags<PipelineRasterizationDepthClipStateCreateBitsEXT>;
enum class PipelineRasterizationStateCreateBits : std::int32_t {};
using PipelineRasterizationStateCreateFlags = impl_Enum::Flags<PipelineRasterizationStateCreateBits>;
enum class PipelineRasterizationStateStreamCreateBitsEXT : std::int32_t {};
using PipelineRasterizationStateStreamCreateFlagsEXT = impl_Enum::Flags<PipelineRasterizationStateStreamCreateBitsEXT>;
enum class PipelineRobustnessBufferBehavior : std::int32_t {
	DeviceDefault       =          0,
	Disabled            =          1,
	RobustBufferAccess  =          2,
	RobustBufferAccess2 =          3,
};
enum class PipelineRobustnessImageBehavior : std::int32_t {
	DeviceDefault      =          0,
	Disabled           =          1,
	RobustImageAccess  =          2,
	RobustImageAccess2 =          3,
};
enum class PipelineShaderStageCreateBits : std::int32_t {
	AllowVaryingSubgroupSize = 0x00000001,
	RequireFullSubgroups     = 0x00000002,
	AllBits                  = 0x00000003, // generated for ~(not), error checking and for convenience
};
using PipelineShaderStageCreateFlags = impl_Enum::Flags<PipelineShaderStageCreateBits>;
enum class PipelineStageBits : std::int32_t {
	None                                = 0x00000000,
	TopOfPipe                           = 0x00000001, // Before subsequent commands are processed
	DrawIndirect                        = 0x00000002, // Draw/DispatchIndirect command fetch
	VertexInput                         = 0x00000004, // Vertex/index fetch
	VertexShader                        = 0x00000008, // Vertex shading
	TessellationControlShader           = 0x00000010, // Tessellation control shading
	TessellationEvaluationShader        = 0x00000020, // Tessellation evaluation shading
	GeometryShader                      = 0x00000040, // Geometry shading
	FragmentShader                      = 0x00000080, // Fragment shading
	EarlyFragmentTests                  = 0x00000100, // Early fragment (depth and stencil) tests
	LateFragmentTests                   = 0x00000200, // Late fragment (depth and stencil) tests
	ColorAttachmentOutput               = 0x00000400, // Color attachment writes
	ComputeShader                       = 0x00000800, // Compute shading
	Transfer                            = 0x00001000, // Transfer/copy operations
	BottomOfPipe                        = 0x00002000, // After previous commands have completed
	Host                                = 0x00004000, // Indicates host (CPU) is a source/sink of the dependency
	AllGraphics                         = 0x00008000, // All stages of the graphics pipeline
	AllCommands                         = 0x00010000, // All stages supported on the queue
	CommandPreprocessBitEXT             = 0x00020000,
	ConditionalRenderingBitEXT          = 0x00040000, // A pipeline stage for conditional rendering predicate fetch
	TaskShaderBitEXT                    = 0x00080000,
	MeshShaderBitEXT                    = 0x00100000,
	RayTracingShaderBitKHR              = 0x00200000,
	FragmentShadingRateAttachmentBitKHR = 0x00400000,
	FragmentDensityProcessBitEXT        = 0x00800000,
	TransformFeedbackBitEXT             = 0x01000000,
	AccelerationStructureBuildBitKHR    = 0x02000000,
	AllBits                             = 0x03ffffff, // generated for ~(not), error checking and for convenience
};
using PipelineStageFlags = impl_Enum::Flags<PipelineStageBits>;
enum class PipelineStageBits2 : std::uint64_t {
	None                                = 0x0000000000000000,
	TopOfPipe                           = 0x0000000000000001,
	DrawIndirect                        = 0x0000000000000002,
	VertexInput                         = 0x0000000000000004,
	VertexShader                        = 0x0000000000000008,
	TessellationControlShader           = 0x0000000000000010,
	TessellationEvaluationShader        = 0x0000000000000020,
	GeometryShader                      = 0x0000000000000040,
	FragmentShader                      = 0x0000000000000080,
	EarlyFragmentTests                  = 0x0000000000000100,
	LateFragmentTests                   = 0x0000000000000200,
	ColorAttachmentOutput               = 0x0000000000000400,
	ComputeShader                       = 0x0000000000000800,
	AllTransfer                         = 0x0000000000001000,
	BottomOfPipe                        = 0x0000000000002000,
	Host                                = 0x0000000000004000,
	AllGraphics                         = 0x0000000000008000,
	AllCommands                         = 0x0000000000010000,
	CommandPreprocessBitEXT             = 0x0000000000020000,
	ConditionalRenderingBitEXT          = 0x0000000000040000, // A pipeline stage for conditional rendering predicate fetch
	TaskShaderBitEXT                    = 0x0000000000080000,
	MeshShaderBitEXT                    = 0x0000000000100000,
	RayTracingShaderBitKHR              = 0x0000000000200000,
	FragmentShadingRateAttachmentBitKHR = 0x0000000000400000,
	FragmentDensityProcessBitEXT        = 0x0000000000800000,
	TransformFeedbackBitEXT             = 0x0000000001000000,
	AccelerationStructureBuildBitKHR    = 0x0000000002000000,
	VideoDecodeBitKHR                   = 0x0000000004000000,
	VideoEncodeBitKHR                   = 0x0000000008000000,
	AccelerationStructureCopyBitKHR     = 0x0000000010000000,
	OpticalFlowBitNV                    = 0x0000000020000000,
	MicromapBuildBitEXT                 = 0x0000000040000000,
	Copy                                = 0x0000000100000000,
	Resolve                             = 0x0000000200000000,
	Blit                                = 0x0000000400000000,
	Clear                               = 0x0000000800000000,
	IndexInput                          = 0x0000001000000000,
	VertexAttributeInput                = 0x0000002000000000,
	PreRasterizationShaders             = 0x0000004000000000,
	SubpassShaderBitHUAWEI              = 0x0000008000000000,
	InvocationMaskBitHUAWEI             = 0x0000010000000000,
	ClusterCullingShaderBitHUAWEI       = 0x0000020000000000,
	DataGraphBitARM                     = 0x0000040000000000,
	ConvertCooperativeVectorMatrixBitNV = 0x0000100000000000,
	MemoryDecompressionBitEXT           = 0x0000200000000000,
	CopyIndirectBitKHR                  = 0x0000400000000000,
	AllBits                             = 0x000077ff7fffffff, // generated for ~(not), error checking and for convenience
};
using PipelineStageFlags2 = impl_Enum::Flags<PipelineStageBits2>;
enum class PipelineTessellationStateCreateBits : std::int32_t {};
using PipelineTessellationStateCreateFlags = impl_Enum::Flags<PipelineTessellationStateCreateBits>;
enum class PipelineVertexInputStateCreateBits : std::int32_t {};
using PipelineVertexInputStateCreateFlags = impl_Enum::Flags<PipelineVertexInputStateCreateBits>;
enum class PipelineViewportStateCreateBits : std::int32_t {};
using PipelineViewportStateCreateFlags = impl_Enum::Flags<PipelineViewportStateCreateBits>;
enum class PipelineViewportSwizzleStateCreateBitsNV : std::int32_t {};
using PipelineViewportSwizzleStateCreateFlagsNV = impl_Enum::Flags<PipelineViewportSwizzleStateCreateBitsNV>;
enum class PointClippingBehavior : std::int32_t {
	AllClipPlanes      =          0,
	UserClipPlanesOnly =          1,
};
enum class PolygonMode : std::int32_t {
	Fill            =          0,
	Line            =          1,
	Point           =          2,
	FillRectangleNV = 1000153000,
};
enum class PresentGravityBitsKHR : std::int32_t {
	Min      = 0x00000001,
	Max      = 0x00000002,
	Centered = 0x00000004,
	AllBits  = 0x00000007, // generated for ~(not), error checking and for convenience
};
using PresentGravityFlagsKHR = impl_Enum::Flags<PresentGravityBitsKHR>;
enum class PresentModeKHR : std::int32_t {
	Immediate               =          0,
	Mailbox                 =          1,
	Fifo                    =          2,
	FifoRelaxed             =          3,
	SharedDemandRefresh     = 1000111000,
	SharedContinuousRefresh = 1000111001,
	FifoLatestReady         = 1000361000,
};
enum class PresentScalingBitsKHR : std::int32_t {
	OneToOne           = 0x00000001,
	AspectRatioStretch = 0x00000002,
	Stretch            = 0x00000004,
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
using PresentScalingFlagsKHR = impl_Enum::Flags<PresentScalingBitsKHR>;
enum class PresentStageBitsEXT : std::int32_t {
	QueueOperationsEnd     = 0x00000001,
	RequestDequeued        = 0x00000002,
	ImageFirstPixelOut     = 0x00000004,
	ImageFirstPixelVisible = 0x00000008,
	AllBits                = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using PresentStageFlagsEXT = impl_Enum::Flags<PresentStageBitsEXT>;
enum class PresentTimingInfoBitsEXT : std::int32_t {
	PresentAtRelativeTime        = 0x00000001,
	PresentAtNearestRefreshCycle = 0x00000002,
	AllBits                      = 0x00000003, // generated for ~(not), error checking and for convenience
};
using PresentTimingInfoFlagsEXT = impl_Enum::Flags<PresentTimingInfoBitsEXT>;
enum class PrimitiveTopology : std::int32_t {
	PointList                  =          0,
	LineList                   =          1,
	LineStrip                  =          2,
	TriangleList               =          3,
	TriangleStrip              =          4,
	TriangleFan                =          5,
	LineListWithAdjacency      =          6,
	LineStripWithAdjacency     =          7,
	TriangleListWithAdjacency  =          8,
	TriangleStripWithAdjacency =          9,
	PatchList                  =         10,
};
enum class PrivateDataSlotCreateBits : std::int32_t {};
using PrivateDataSlotCreateFlags = impl_Enum::Flags<PrivateDataSlotCreateBits>;
enum class ProvokingVertexModeEXT : std::int32_t {
	FirstVertex =          0,
	LastVertex  =          1,
};
enum class QueryControlBits : std::int32_t {
	Precise = 0x00000001, // Require precise results to be collected by the query
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
using QueryControlFlags = impl_Enum::Flags<QueryControlBits>;
enum class QueryPipelineStatisticBits : std::int32_t {
	InputAssemblyVertices                    = 0x00000001, // Optional
	InputAssemblyPrimitives                  = 0x00000002, // Optional
	VertexShaderInvocations                  = 0x00000004, // Optional
	GeometryShaderInvocations                = 0x00000008, // Optional
	GeometryShaderPrimitives                 = 0x00000010, // Optional
	ClippingInvocations                      = 0x00000020, // Optional
	ClippingPrimitives                       = 0x00000040, // Optional
	FragmentShaderInvocations                = 0x00000080, // Optional
	TessellationControlShaderPatches         = 0x00000100, // Optional
	TessellationEvaluationShaderInvocations  = 0x00000200, // Optional
	ComputeShaderInvocations                 = 0x00000400, // Optional
	TaskShaderInvocationsBitEXT              = 0x00000800,
	MeshShaderInvocationsBitEXT              = 0x00001000,
	ClusterCullingShaderInvocationsBitHUAWEI = 0x00002000,
	AllBits                                  = 0x00003fff, // generated for ~(not), error checking and for convenience
};
using QueryPipelineStatisticFlags = impl_Enum::Flags<QueryPipelineStatisticBits>;
enum class QueryPoolCreateBits : std::int32_t {
	ResetBitKHR = 0x00000001,
	AllBits     = 0x00000001, // generated for ~(not), error checking and for convenience
};
using QueryPoolCreateFlags = impl_Enum::Flags<QueryPoolCreateBits>;
enum class QueryPoolSamplingModeINTEL : std::int32_t {
	Manual =          0,
};
enum class QueryResultBits : std::int32_t {
	v64              = 0x00000001, // Results of the queries are written to the destination buffer as 64-bit values
	Wait             = 0x00000002, // Results of the queries are waited on before proceeding with the result copy
	WithAvailability = 0x00000004, // Besides the results of the query, the availability of the results is also written
	Partial          = 0x00000008, // Copy the partial results of the query even if the final results are not available
	WithStatusBitKHR = 0x00000010,
	AllBits          = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using QueryResultFlags = impl_Enum::Flags<QueryResultBits>;
enum class QueryResultStatusKHR : std::int32_t {
	NotReady                         =          0,
	Complete                         =          1,
	Error                            = -         1,
	InsufficientBitstreamBufferRange = -1000299000,
};
enum class QueryType : std::int32_t {
	Occlusion                                                =          0,
	PipelineStatistics                                       =          1, // Optional
	Timestamp                                                =          2,
	ResultStatusOnlyKHR                                      = 1000023000,
	TransformFeedbackStreamEXT                               = 1000028004,
	PerformanceQueryKHR                                      = 1000116000,
	AccelerationStructureCompactedSizeKHR                    = 1000150000,
	AccelerationStructureSerializationSizeKHR                = 1000150001,
	AccelerationStructureCompactedSizeNV                     = 1000165000,
	TimeElapsedQCOM                                          = 1000173000,
	PerformanceQueryINTEL                                    = 1000210000,
	VideoEncodeFeedbackKHR                                   = 1000299000,
	MeshPrimitivesGeneratedEXT                               = 1000328000,
	PrimitivesGeneratedEXT                                   = 1000382000,
	AccelerationStructureSerializationBottomLevelPointersKHR = 1000386000,
	AccelerationStructureSizeKHR                             = 1000386001,
	MicromapSerializationSizeEXT                             = 1000396000,
	MicromapCompactedSizeEXT                                 = 1000396001,
};
enum class QueueBits : std::int32_t {
	Graphics          = 0x00000001, // Queue supports graphics operations
	Compute           = 0x00000002, // Queue supports compute operations
	Transfer          = 0x00000004, // Queue supports transfer operations
	SparseBinding     = 0x00000008, // Queue supports sparse resource memory management operations
	Protected         = 0x00000010, // Queues may support protected operations
	VideoDecodeBitKHR = 0x00000020,
	VideoEncodeBitKHR = 0x00000040,
	OpticalFlowBitNV  = 0x00000100,
	DataGraphBitARM   = 0x00000400,
	AllBits           = 0x0000057f, // generated for ~(not), error checking and for convenience
};
using QueueFlags = impl_Enum::Flags<QueueBits>;
enum class QueueGlobalPriority : std::int32_t {
	Low      =        128,
	Medium   =        256,
	High     =        512,
	Realtime =       1024,
};
enum class RasterizationOrderAMD : std::int32_t {
	Strict  =          0,
	Relaxed =          1,
};
enum class RayTracingInvocationReorderModeEXT : std::int32_t {
	None    =          0,
	Reorder =          1,
};
enum class RayTracingLssIndexingModeNV : std::int32_t {
	List       =          0,
	Successive =          1,
};
enum class RayTracingLssPrimitiveEndCapsModeNV : std::int32_t {
	None    =          0,
	Chained =          1,
};
enum class RayTracingShaderGroupTypeKHR : std::int32_t {
	General            =          0,
	TrianglesHitGroup  =          1,
	ProceduralHitGroup =          2,
};
enum class RefreshObjectBitsKHR : std::int32_t {};
using RefreshObjectFlagsKHR = impl_Enum::Flags<RefreshObjectBitsKHR>;
enum class RenderPassCreateBits : std::int32_t {
	TransformBitQCOM                = 0x00000002,
	PerLayerFragmentDensityBitVALVE = 0x00000004,
	AllBits                         = 0x00000006, // generated for ~(not), error checking and for convenience
};
using RenderPassCreateFlags = impl_Enum::Flags<RenderPassCreateBits>;
enum class RenderingAttachmentBitsKHR : std::int32_t {
	InputAttachmentFeedback       = 0x00000001,
	ResolveSkipTransferFunction   = 0x00000002,
	ResolveEnableTransferFunction = 0x00000004,
	AllBits                       = 0x00000007, // generated for ~(not), error checking and for convenience
};
using RenderingAttachmentFlagsKHR = impl_Enum::Flags<RenderingAttachmentBitsKHR>;
enum class RenderingBits : std::int32_t {
	ContentsSecondaryCommandBuffers        = 0x00000001,
	Suspending                             = 0x00000002,
	Resuming                               = 0x00000004,
	EnableLegacyDitheringBitEXT            = 0x00000008,
	ContentsInlineBitKHR                   = 0x00000010, // Promoted from extension 452
	PerLayerFragmentDensityBitVALVE        = 0x00000020,
	FragmentRegionBitEXT                   = 0x00000040,
	CustomResolveBitEXT                    = 0x00000080,
	LocalReadConcurrentAccessControlBitKHR = 0x00000100,
	AllBits                                = 0x000001ff, // generated for ~(not), error checking and for convenience
};
using RenderingFlags = impl_Enum::Flags<RenderingBits>;
enum class ResolveImageBitsKHR : std::int32_t {
	SkipTransferFunction   = 0x00000001,
	EnableTransferFunction = 0x00000002,
	AllBits                = 0x00000003, // generated for ~(not), error checking and for convenience
};
using ResolveImageFlagsKHR = impl_Enum::Flags<ResolveImageBitsKHR>;
enum class ResolveModeBits : std::int32_t {
	None                               = 0x00000000,
	SampleZero                         = 0x00000001,
	Average                            = 0x00000002,
	Min                                = 0x00000004,
	Max                                = 0x00000008,
	ExternalFormatDownsampleBitANDROID = 0x00000010,
	CustomBitEXT                       = 0x00000020,
	AllBits                            = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using ResolveModeFlags = impl_Enum::Flags<ResolveModeBits>;
enum class Result : std::int32_t {
	Success                                     =          0, // Command completed successfully
	NotReady                                    =          1, // A fence or query has not yet completed
	Timeout                                     =          2, // A wait operation has not completed in the specified time
	EventSet                                    =          3, // An event is signaled
	EventReset                                  =          4, // An event is unsignaled
	Incomplete                                  =          5, // A return array was too small for the result
	ErrorOutOfHostMemory                        = -         1, // A host memory allocation has failed
	ErrorOutOfDeviceMemory                      = -         2, // A device memory allocation has failed
	ErrorInitializationFailed                   = -         3, // Initialization of an object has failed
	ErrorDeviceLost                             = -         4, // The logical device has been lost. See <<devsandqueues-lost-device>>
	ErrorMemoryMapFailed                        = -         5, // Mapping of a memory object has failed
	ErrorLayerNotPresent                        = -         6, // Layer specified does not exist
	ErrorExtensionNotPresent                    = -         7, // Extension specified does not exist
	ErrorFeatureNotPresent                      = -         8, // Requested feature is not available on this device
	ErrorIncompatibleDriver                     = -         9, // Unable to find a Vulkan driver
	ErrorTooManyObjects                         = -        10, // Too many objects of the type have already been created
	ErrorFormatNotSupported                     = -        11, // Requested format is not supported on this device
	ErrorFragmentedPool                         = -        12, // A requested pool allocation has failed due to fragmentation of the pool's memory
	ErrorUnknown                                = -        13, // An unknown error has occurred, due to an implementation or application bug
	ErrorSurfaceLostKHR                         = -1000000000,
	ErrorNativeWindowInUseKHR                   = -1000000001,
	ErrorOutOfDateKHR                           = -1000001004,
	ErrorIncompatibleDisplayKHR                 = -1000003001,
	ErrorValidationFailed                       = -1000011001,
	ErrorInvalidShaderNV                        = -1000012000,
	ErrorImageUsageNotSupportedKHR              = -1000023000,
	ErrorVideoPictureLayoutNotSupportedKHR      = -1000023001,
	ErrorVideoProfileOperationNotSupportedKHR   = -1000023002,
	ErrorVideoProfileFormatNotSupportedKHR      = -1000023003,
	ErrorVideoProfileCodecNotSupportedKHR       = -1000023004,
	ErrorVideoStdVersionNotSupportedKHR         = -1000023005,
	ErrorOutOfPoolMemory                        = -1000069000,
	ErrorInvalidExternalHandle                  = -1000072003,
	ErrorInvalidDrmFormatModifierPlaneLayoutEXT = -1000158000,
	ErrorFragmentation                          = -1000161000,
	ErrorNotPermitted                           = -1000174001,
	ErrorPresentTimingQueueFullEXT              = -1000208000,
	ErrorFullScreenExclusiveModeLostEXT         = -1000255000,
	ErrorInvalidOpaqueCaptureAddress            = -1000257000,
	ErrorInvalidVideoStdParametersKHR           = -1000299000,
	ErrorCompressionExhaustedEXT                = -1000338000,
	ErrorNotEnoughSpaceKHR                      = -1000483000,
	SuboptimalKHR                               = 1000001003,
	ThreadIdleKHR                               = 1000268000,
	ThreadDoneKHR                               = 1000268001,
	OperationDeferredKHR                        = 1000268002,
	OperationNotDeferredKHR                     = 1000268003,
	PipelineCompileRequired                     = 1000297000,
	IncompatibleShaderBinaryEXT                 = 1000482000,
	PipelineBinaryMissingKHR                    = 1000483000,
};
enum class SampleCountBits : std::int32_t {
	v1      = 0x00000001, // Sample count 1 supported
	v2      = 0x00000002, // Sample count 2 supported
	v4      = 0x00000004, // Sample count 4 supported
	v8      = 0x00000008, // Sample count 8 supported
	v16     = 0x00000010, // Sample count 16 supported
	v32     = 0x00000020, // Sample count 32 supported
	v64     = 0x00000040, // Sample count 64 supported
	AllBits = 0x0000007f, // generated for ~(not), error checking and for convenience
};
using SampleCountFlags = impl_Enum::Flags<SampleCountBits>;
enum class SamplerAddressMode : std::int32_t {
	Repeat            =          0,
	MirroredRepeat    =          1,
	ClampToEdge       =          2,
	ClampToBorder     =          3,
	MirrorClampToEdge =          4, // No need to add an extnumber attribute, since this uses a core enum value
};
enum class SamplerCreateBits : std::int32_t {
	SubsampledBitEXT                     = 0x00000001,
	SubsampledCoarseReconstructionBitEXT = 0x00000002,
	NonSeamlessCubeMapBitEXT             = 0x00000004,
	DescriptorBufferCaptureReplayBitEXT  = 0x00000008,
	ImageProcessingBitQCOM               = 0x00000010,
	AllBits                              = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using SamplerCreateFlags = impl_Enum::Flags<SamplerCreateBits>;
enum class SamplerMipmapMode : std::int32_t {
	Nearest =          0, // Choose nearest mip level
	Linear  =          1, // Linear filter between mip levels
};
enum class SamplerReductionMode : std::int32_t {
	WeightedAverage               =          0,
	Min                           =          1,
	Max                           =          2,
	WeightedAverageRangeclampQCOM = 1000521000,
};
enum class SamplerYcbcrModelConversion : std::int32_t {
	RgbIdentity   =          0,
	YcbcrIdentity =          1, // just range expansion
	Ycbcr709      =          2, // aka HD YUV
	Ycbcr601      =          3, // aka SD YUV
	Ycbcr2020     =          4, // aka UHD YUV
};
enum class SamplerYcbcrRange : std::int32_t {
	ItuFull   =          0, // Luma 0..1 maps to 0..255, chroma -0.5..0.5 to 1..255 (clamped)
	ItuNarrow =          1, // Luma 0..1 maps to 16..235, chroma -0.5..0.5 to 16..240
};
enum class ScopeKHR : std::int32_t {
	Device      =          1,
	Workgroup   =          2,
	Subgroup    =          3,
	QueueFamily =          5,
};
enum class ScreenSurfaceCreateBitsQNX : std::int32_t {};
using ScreenSurfaceCreateFlagsQNX = impl_Enum::Flags<ScreenSurfaceCreateBitsQNX>;
enum class SemaphoreCreateBits : std::int32_t {};
using SemaphoreCreateFlags = impl_Enum::Flags<SemaphoreCreateBits>;
enum class SemaphoreImportBits : std::int32_t {
	Temporary = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
};
using SemaphoreImportFlags = impl_Enum::Flags<SemaphoreImportBits>;
enum class SemaphoreType : std::int32_t {
	Binary   =          0,
	Timeline =          1,
};
enum class SemaphoreWaitBits : std::int32_t {
	Any     = 0x00000001,
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
using SemaphoreWaitFlags = impl_Enum::Flags<SemaphoreWaitBits>;
enum class ShaderCodeTypeEXT : std::int32_t {
	Binary =          0,
	Spirv  =          1,
};
enum class ShaderCorePropertiesBitsAMD : std::int32_t {};
using ShaderCorePropertiesFlagsAMD = impl_Enum::Flags<ShaderCorePropertiesBitsAMD>;
enum class ShaderCreateBitsEXT : std::int32_t {
	LinkStage                                = 0x00000001,
	AllowVaryingSubgroupSize                 = 0x00000002,
	RequireFullSubgroups                     = 0x00000004,
	NoTaskShader                             = 0x00000008,
	DispatchBase                             = 0x00000010,
	FragmentShadingRateAttachment            = 0x00000020,
	FragmentDensityMapAttachment             = 0x00000040,
	IndirectBindable                         = 0x00000080,
	DescriptorHeap                           = 0x00000400,
	InstrumentShaderBitARM                   = 0x00000800,
	OpacityMicromapDisallowMixedSpecialIndex = 0x00001000,
	v64BitIndexing                           = 0x00008000,
	IndependentSetsBitKHR                    = 0x00040000,
	AllBits                                  = 0x00049cff, // generated for ~(not), error checking and for convenience
};
using ShaderCreateFlagsEXT = impl_Enum::Flags<ShaderCreateBitsEXT>;
enum class ShaderFloatControlsIndependence : std::int32_t {
	v32BitOnly =          0,
	All        =          1,
	None       =          2,
};
enum class ShaderGroupShaderKHR : std::int32_t {
	General      =          0,
	ClosestHit   =          1,
	AnyHit       =          2,
	Intersection =          3,
};
enum class ShaderInfoTypeAMD : std::int32_t {
	Statistics  =          0,
	Binary      =          1,
	Disassembly =          2,
};
enum class ShaderInstrumentationValuesBitsARM : std::int32_t {};
using ShaderInstrumentationValuesFlagsARM = impl_Enum::Flags<ShaderInstrumentationValuesBitsARM>;
enum class ShaderModuleCreateBits : std::int32_t {};
using ShaderModuleCreateFlags = impl_Enum::Flags<ShaderModuleCreateBits>;
enum class ShaderStageBits : std::int32_t {
	Vertex                  = 0x00000001,
	TessellationControl     = 0x00000002,
	TessellationEvaluation  = 0x00000004,
	Geometry                = 0x00000008,
	Fragment                = 0x00000010,
	AllGraphics             = 0x0000001f,
	Compute                 = 0x00000020,
	TaskBitEXT              = 0x00000040,
	MeshBitEXT              = 0x00000080,
	RaygenBitKHR            = 0x00000100,
	AnyHitBitKHR            = 0x00000200,
	ClosestHitBitKHR        = 0x00000400,
	MissBitKHR              = 0x00000800,
	IntersectionBitKHR      = 0x00001000,
	CallableBitKHR          = 0x00002000,
	SubpassShadingBitHUAWEI = 0x00004000,
	ClusterCullingBitHUAWEI = 0x00080000,
	All                     = 0x7fffffff,
	AllBits                 = 0x7fffffff, // generated for ~(not), error checking and for convenience
};
using ShaderStageFlags = impl_Enum::Flags<ShaderStageBits>;
enum class ShadingRatePaletteEntryNV : std::int32_t {
	NoInvocations            =          0,
	v16InvocationsPerPixel   =          1,
	v8InvocationsPerPixel    =          2,
	v4InvocationsPerPixel    =          3,
	v2InvocationsPerPixel    =          4,
	v1InvocationPerPixel     =          5,
	v1InvocationPer2x1Pixels =          6,
	v1InvocationPer1x2Pixels =          7,
	v1InvocationPer2x2Pixels =          8,
	v1InvocationPer4x2Pixels =          9,
	v1InvocationPer2x4Pixels =         10,
	v1InvocationPer4x4Pixels =         11,
};
enum class SharingMode : std::int32_t {
	Exclusive  =          0,
	Concurrent =          1,
};
enum class SparseImageFormatBits : std::int32_t {
	SingleMiptail        = 0x00000001, // Image uses a single mip tail region for all array layers
	AlignedMipSize       = 0x00000002, // Image requires mip level dimensions to be an integer multiple of the sparse image block dimensions for non-tail mip levels.
	NonstandardBlockSize = 0x00000004, // Image uses a non-standard sparse image block dimensions
	AllBits              = 0x00000007, // generated for ~(not), error checking and for convenience
};
using SparseImageFormatFlags = impl_Enum::Flags<SparseImageFormatBits>;
enum class SparseMemoryBindBits : std::int32_t {
	Metadata = 0x00000001, // Operation binds resource metadata to memory
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
using SparseMemoryBindFlags = impl_Enum::Flags<SparseMemoryBindBits>;
enum class SpirvResourceTypeBitsEXT : std::int32_t {
	Sampler                = 0x00000001,
	SampledImage           = 0x00000002,
	ReadOnlyImage          = 0x00000004,
	ReadWriteImage         = 0x00000008,
	CombinedSampledImage   = 0x00000010,
	UniformBuffer          = 0x00000020,
	ReadOnlyStorageBuffer  = 0x00000040,
	ReadWriteStorageBuffer = 0x00000080,
	AccelerationStructure  = 0x00000100,
	TensorBitARM           = 0x00000200,
	All                    = 0x7fffffff,
	AllBits                = 0x7fffffff, // generated for ~(not), error checking and for convenience
};
using SpirvResourceTypeFlagsEXT = impl_Enum::Flags<SpirvResourceTypeBitsEXT>;
enum class StencilFaceBits : std::int32_t {
	Front        = 0x00000001, // Front face
	Back         = 0x00000002, // Back face
	FrontAndBack = 0x00000003, // Front and back faces
	AllBits      = 0x00000003, // generated for ~(not), error checking and for convenience
};
using StencilFaceFlags = impl_Enum::Flags<StencilFaceBits>;
enum class StencilOp : std::int32_t {
	Keep              =          0,
	Zero              =          1,
	Replace           =          2,
	IncrementAndClamp =          3,
	DecrementAndClamp =          4,
	Invert            =          5,
	IncrementAndWrap  =          6,
	DecrementAndWrap  =          7,
};
enum class StreamDescriptorSurfaceCreateBitsGGP : std::int32_t {};
using StreamDescriptorSurfaceCreateFlagsGGP = impl_Enum::Flags<StreamDescriptorSurfaceCreateBitsGGP>;
enum class StructureType : std::int32_t {
	ApplicationInfo                                                 =          0,
	InstanceCreateInfo                                              =          1,
	DeviceQueueCreateInfo                                           =          2,
	DeviceCreateInfo                                                =          3,
	SubmitInfo                                                      =          4,
	MemoryAllocateInfo                                              =          5,
	MappedMemoryRange                                               =          6,
	BindSparseInfo                                                  =          7,
	FenceCreateInfo                                                 =          8,
	SemaphoreCreateInfo                                             =          9,
	EventCreateInfo                                                 =         10,
	QueryPoolCreateInfo                                             =         11,
	BufferCreateInfo                                                =         12,
	BufferViewCreateInfo                                            =         13,
	ImageCreateInfo                                                 =         14,
	ImageViewCreateInfo                                             =         15,
	ShaderModuleCreateInfo                                          =         16,
	PipelineCacheCreateInfo                                         =         17,
	PipelineShaderStageCreateInfo                                   =         18,
	PipelineVertexInputStateCreateInfo                              =         19,
	PipelineInputAssemblyStateCreateInfo                            =         20,
	PipelineTessellationStateCreateInfo                             =         21,
	PipelineViewportStateCreateInfo                                 =         22,
	PipelineRasterizationStateCreateInfo                            =         23,
	PipelineMultisampleStateCreateInfo                              =         24,
	PipelineDepthStencilStateCreateInfo                             =         25,
	PipelineColorBlendStateCreateInfo                               =         26,
	PipelineDynamicStateCreateInfo                                  =         27,
	GraphicsPipelineCreateInfo                                      =         28,
	ComputePipelineCreateInfo                                       =         29,
	PipelineLayoutCreateInfo                                        =         30,
	SamplerCreateInfo                                               =         31,
	DescriptorSetLayoutCreateInfo                                   =         32,
	DescriptorPoolCreateInfo                                        =         33,
	DescriptorSetAllocateInfo                                       =         34,
	WriteDescriptorSet                                              =         35,
	CopyDescriptorSet                                               =         36,
	FramebufferCreateInfo                                           =         37,
	RenderPassCreateInfo                                            =         38,
	CommandPoolCreateInfo                                           =         39,
	CommandBufferAllocateInfo                                       =         40,
	CommandBufferInheritanceInfo                                    =         41,
	CommandBufferBeginInfo                                          =         42,
	RenderPassBeginInfo                                             =         43,
	BufferMemoryBarrier                                             =         44,
	ImageMemoryBarrier                                              =         45,
	MemoryBarrier                                                   =         46,
	LoaderInstanceCreateInfo                                        =         47, // Reserved for internal use by the loader, layers, and ICDs
	LoaderDeviceCreateInfo                                          =         48, // Reserved for internal use by the loader, layers, and ICDs
	PhysicalDeviceVulkan11Features                                  =         49,
	PhysicalDeviceVulkan11Properties                                =         50,
	PhysicalDeviceVulkan12Features                                  =         51,
	PhysicalDeviceVulkan12Properties                                =         52,
	PhysicalDeviceVulkan13Features                                  =         53,
	PhysicalDeviceVulkan13Properties                                =         54,
	PhysicalDeviceVulkan14Features                                  =         55,
	PhysicalDeviceVulkan14Properties                                =         56,
	SwapchainCreateInfoKHR                                          = 1000001000,
	PresentInfoKHR                                                  = 1000001001,
	DisplayModeCreateInfoKHR                                        = 1000002000,
	DisplaySurfaceCreateInfoKHR                                     = 1000002001,
	DisplayPresentInfoKHR                                           = 1000003000,
	XlibSurfaceCreateInfoKHR                                        = 1000004000,
	XcbSurfaceCreateInfoKHR                                         = 1000005000,
	WaylandSurfaceCreateInfoKHR                                     = 1000006000,
	ANDROIDSurfaceCreateInfoKHR                                     = 1000008000,
	Win32SurfaceCreateInfoKHR                                       = 1000009000,
	DebugReportCallbackCreateInfoEXT                                = 1000011000,
	PipelineRasterizationStateRasterizationOrderAMD                 = 1000018000,
	DebugMarkerObjectNameInfoEXT                                    = 1000022000,
	DebugMarkerObjectTagInfoEXT                                     = 1000022001,
	DebugMarkerMarkerInfoEXT                                        = 1000022002,
	VideoProfileInfoKHR                                             = 1000023000,
	VideoCapabilitiesKHR                                            = 1000023001,
	VideoPictureResourceInfoKHR                                     = 1000023002,
	VideoSessionMemoryRequirementsKHR                               = 1000023003,
	BindVideoSessionMemoryInfoKHR                                   = 1000023004,
	VideoSessionCreateInfoKHR                                       = 1000023005,
	VideoSessionParametersCreateInfoKHR                             = 1000023006,
	VideoSessionParametersUpdateInfoKHR                             = 1000023007,
	VideoBeginCodingInfoKHR                                         = 1000023008,
	VideoEndCodingInfoKHR                                           = 1000023009,
	VideoCodingControlInfoKHR                                       = 1000023010,
	VideoReferenceSlotInfoKHR                                       = 1000023011,
	QueueFamilyVideoPropertiesKHR                                   = 1000023012,
	VideoProfileListInfoKHR                                         = 1000023013,
	PhysicalDeviceVideoFormatInfoKHR                                = 1000023014,
	VideoFormatPropertiesKHR                                        = 1000023015,
	QueueFamilyQueryResultStatusPropertiesKHR                       = 1000023016,
	VideoDecodeInfoKHR                                              = 1000024000,
	VideoDecodeCapabilitiesKHR                                      = 1000024001,
	VideoDecodeUsageInfoKHR                                         = 1000024002,
	DedicatedAllocationImageCreateInfoNV                            = 1000026000,
	DedicatedAllocationBufferCreateInfoNV                           = 1000026001,
	DedicatedAllocationMemoryAllocateInfoNV                         = 1000026002,
	PhysicalDeviceTransformFeedbackFeaturesEXT                      = 1000028000,
	PhysicalDeviceTransformFeedbackPropertiesEXT                    = 1000028001,
	PipelineRasterizationStateStreamCreateInfoEXT                   = 1000028002,
	CuModuleCreateInfoNVX                                           = 1000029000,
	CuFunctionCreateInfoNVX                                         = 1000029001,
	CuLaunchInfoNVX                                                 = 1000029002,
	CuModuleTexturingModeCreateInfoNVX                              = 1000029004,
	ImageViewHandleInfoNVX                                          = 1000030000,
	ImageViewAddressPropertiesNVX                                   = 1000030001,
	VideoEncodeH264CapabilitiesKHR                                  = 1000038000,
	VideoEncodeH264SessionParametersCreateInfoKHR                   = 1000038001,
	VideoEncodeH264SessionParametersAddInfoKHR                      = 1000038002,
	VideoEncodeH264PictureInfoKHR                                   = 1000038003,
	VideoEncodeH264DpbSlotInfoKHR                                   = 1000038004,
	VideoEncodeH264NaluSliceInfoKHR                                 = 1000038005,
	VideoEncodeH264GopRemainingFrameInfoKHR                         = 1000038006,
	VideoEncodeH264ProfileInfoKHR                                   = 1000038007,
	VideoEncodeH264RateControlInfoKHR                               = 1000038008,
	VideoEncodeH264RateControlLayerInfoKHR                          = 1000038009,
	VideoEncodeH264SessionCreateInfoKHR                             = 1000038010,
	VideoEncodeH264QualityLevelPropertiesKHR                        = 1000038011,
	VideoEncodeH264SessionParametersGetInfoKHR                      = 1000038012,
	VideoEncodeH264SessionParametersFeedbackInfoKHR                 = 1000038013,
	VideoEncodeH265CapabilitiesKHR                                  = 1000039000,
	VideoEncodeH265SessionParametersCreateInfoKHR                   = 1000039001,
	VideoEncodeH265SessionParametersAddInfoKHR                      = 1000039002,
	VideoEncodeH265PictureInfoKHR                                   = 1000039003,
	VideoEncodeH265DpbSlotInfoKHR                                   = 1000039004,
	VideoEncodeH265NaluSliceSegmentInfoKHR                          = 1000039005,
	VideoEncodeH265GopRemainingFrameInfoKHR                         = 1000039006,
	VideoEncodeH265ProfileInfoKHR                                   = 1000039007,
	VideoEncodeH265RateControlInfoKHR                               = 1000039009,
	VideoEncodeH265RateControlLayerInfoKHR                          = 1000039010,
	VideoEncodeH265SessionCreateInfoKHR                             = 1000039011,
	VideoEncodeH265QualityLevelPropertiesKHR                        = 1000039012,
	VideoEncodeH265SessionParametersGetInfoKHR                      = 1000039013,
	VideoEncodeH265SessionParametersFeedbackInfoKHR                 = 1000039014,
	VideoDecodeH264CapabilitiesKHR                                  = 1000040000,
	VideoDecodeH264PictureInfoKHR                                   = 1000040001,
	VideoDecodeH264ProfileInfoKHR                                   = 1000040003,
	VideoDecodeH264SessionParametersCreateInfoKHR                   = 1000040004,
	VideoDecodeH264SessionParametersAddInfoKHR                      = 1000040005,
	VideoDecodeH264DpbSlotInfoKHR                                   = 1000040006,
	TextureLodGatherFormatPropertiesAMD                             = 1000041000,
	RenderingInfo                                                   = 1000044000,
	RenderingAttachmentInfo                                         = 1000044001,
	PipelineRenderingCreateInfo                                     = 1000044002,
	PhysicalDeviceDynamicRenderingFeatures                          = 1000044003,
	CommandBufferInheritanceRenderingInfo                           = 1000044004,
	RenderingFragmentShadingRateAttachmentInfoKHR                   = 1000044006,
	RenderingFragmentDensityMapAttachmentInfoEXT                    = 1000044007,
	AttachmentSampleCountInfoAMD                                    = 1000044008,
	MultiviewPerViewAttributesInfoNVX                               = 1000044009,
	StreamDescriptorSurfaceCreateInfoGGP                            = 1000049000,
	PhysicalDeviceCornerSampledImageFeaturesNV                      = 1000050000,
	RenderPassMultiviewCreateInfo                                   = 1000053000,
	PhysicalDeviceMultiviewFeatures                                 = 1000053001,
	PhysicalDeviceMultiviewProperties                               = 1000053002,
	ExternalMemoryImageCreateInfoNV                                 = 1000056000,
	ExportMemoryAllocateInfoNV                                      = 1000056001,
	ImportMemoryWin32HandleInfoNV                                   = 1000057000,
	ExportMemoryWin32HandleInfoNV                                   = 1000057001,
	Win32KeyedMutexAcquireReleaseInfoNV                             = 1000058000,
	PhysicalDeviceFeatures2                                         = 1000059000,
	PhysicalDeviceProperties2                                       = 1000059001,
	FormatProperties2                                               = 1000059002,
	ImageFormatProperties2                                          = 1000059003,
	PhysicalDeviceImageFormatInfo2                                  = 1000059004,
	QueueFamilyProperties2                                          = 1000059005,
	PhysicalDeviceMemoryProperties2                                 = 1000059006,
	SparseImageFormatProperties2                                    = 1000059007,
	PhysicalDeviceSparseImageFormatInfo2                            = 1000059008,
	MemoryAllocateFlagsInfo                                         = 1000060000,
	DeviceGroupRenderPassBeginInfo                                  = 1000060003,
	DeviceGroupCommandBufferBeginInfo                               = 1000060004,
	DeviceGroupSubmitInfo                                           = 1000060005,
	DeviceGroupBindSparseInfo                                       = 1000060006,
	DeviceGroupPresentCapabilitiesKHR                               = 1000060007,
	ImageSwapchainCreateInfoKHR                                     = 1000060008,
	BindImageMemorySwapchainInfoKHR                                 = 1000060009,
	AcquireNextImageInfoKHR                                         = 1000060010,
	DeviceGroupPresentInfoKHR                                       = 1000060011,
	DeviceGroupSwapchainCreateInfoKHR                               = 1000060012,
	BindBufferMemoryDeviceGroupInfo                                 = 1000060013,
	BindImageMemoryDeviceGroupInfo                                  = 1000060014,
	ValidationFlagsEXT                                              = 1000061000,
	ViSurfaceCreateInfoNN                                           = 1000062000,
	PhysicalDeviceShaderDrawParametersFeatures                      = 1000063000,
	PhysicalDeviceTextureCompressionAstcHdrFeatures                 = 1000066000,
	ImageViewAstcDecodeModeEXT                                      = 1000067000,
	PhysicalDeviceAstcDecodeFeaturesEXT                             = 1000067001,
	PipelineRobustnessCreateInfo                                    = 1000068000,
	PhysicalDevicePipelineRobustnessFeatures                        = 1000068001,
	PhysicalDevicePipelineRobustnessProperties                      = 1000068002,
	PhysicalDeviceGroupProperties                                   = 1000070000,
	DeviceGroupDeviceCreateInfo                                     = 1000070001,
	PhysicalDeviceExternalImageFormatInfo                           = 1000071000,
	ExternalImageFormatProperties                                   = 1000071001,
	PhysicalDeviceExternalBufferInfo                                = 1000071002,
	ExternalBufferProperties                                        = 1000071003,
	PhysicalDeviceIdProperties                                      = 1000071004,
	ExternalMemoryBufferCreateInfo                                  = 1000072000,
	ExternalMemoryImageCreateInfo                                   = 1000072001,
	ExportMemoryAllocateInfo                                        = 1000072002,
	ImportMemoryWin32HandleInfoKHR                                  = 1000073000,
	ExportMemoryWin32HandleInfoKHR                                  = 1000073001,
	MemoryWin32HandlePropertiesKHR                                  = 1000073002,
	MemoryGetWin32HandleInfoKHR                                     = 1000073003,
	ImportMemoryFdInfoKHR                                           = 1000074000,
	MemoryFdPropertiesKHR                                           = 1000074001,
	MemoryGetFdInfoKHR                                              = 1000074002,
	Win32KeyedMutexAcquireReleaseInfoKHR                            = 1000075000,
	PhysicalDeviceExternalSemaphoreInfo                             = 1000076000,
	ExternalSemaphoreProperties                                     = 1000076001,
	ExportSemaphoreCreateInfo                                       = 1000077000,
	ImportSemaphoreWin32HandleInfoKHR                               = 1000078000,
	ExportSemaphoreWin32HandleInfoKHR                               = 1000078001,
	D3D12FenceSubmitInfoKHR                                         = 1000078002,
	SemaphoreGetWin32HandleInfoKHR                                  = 1000078003,
	ImportSemaphoreFdInfoKHR                                        = 1000079000,
	SemaphoreGetFdInfoKHR                                           = 1000079001,
	PhysicalDevicePushDescriptorProperties                          = 1000080000,
	CommandBufferInheritanceConditionalRenderingInfoEXT             = 1000081000,
	PhysicalDeviceConditionalRenderingFeaturesEXT                   = 1000081001,
	ConditionalRenderingBeginInfoEXT                                = 1000081002,
	PhysicalDeviceShaderFloat16Int8Features                         = 1000082000,
	PhysicalDevice16BitStorageFeatures                              = 1000083000,
	PresentRegionsKHR                                               = 1000084000,
	DescriptorUpdateTemplateCreateInfo                              = 1000085000,
	PipelineViewportWScalingStateCreateInfoNV                       = 1000087000,
	SurfaceCapabilities2EXT                                         = 1000090000,
	DisplayPowerInfoEXT                                             = 1000091000,
	DeviceEventInfoEXT                                              = 1000091001,
	DisplayEventInfoEXT                                             = 1000091002,
	SwapchainCounterCreateInfoEXT                                   = 1000091003,
	PresentTimesInfoGOOGLE                                          = 1000092000,
	PhysicalDeviceSubgroupProperties                                = 1000094000,
	PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX           = 1000097000,
	PipelineViewportSwizzleStateCreateInfoNV                        = 1000098000,
	PhysicalDeviceDiscardRectanglePropertiesEXT                     = 1000099000,
	PipelineDiscardRectangleStateCreateInfoEXT                      = 1000099001,
	PhysicalDeviceConservativeRasterizationPropertiesEXT            = 1000101000,
	PipelineRasterizationConservativeStateCreateInfoEXT             = 1000101001,
	PhysicalDeviceDepthClipEnableFeaturesEXT                        = 1000102000,
	PipelineRasterizationDepthClipStateCreateInfoEXT                = 1000102001,
	HdrMetadataEXT                                                  = 1000105000,
	PhysicalDeviceImagelessFramebufferFeatures                      = 1000108000,
	FramebufferAttachmentsCreateInfo                                = 1000108001,
	FramebufferAttachmentImageInfo                                  = 1000108002,
	RenderPassAttachmentBeginInfo                                   = 1000108003,
	AttachmentDescription2                                          = 1000109000,
	AttachmentReference2                                            = 1000109001,
	SubpassDescription2                                             = 1000109002,
	SubpassDependency2                                              = 1000109003,
	RenderPassCreateInfo2                                           = 1000109004,
	SubpassBeginInfo                                                = 1000109005,
	SubpassEndInfo                                                  = 1000109006,
	PhysicalDeviceRelaxedLineRasterizationFeaturesIMG               = 1000110000,
	SharedPresentSurfaceCapabilitiesKHR                             = 1000111000,
	PhysicalDeviceExternalFenceInfo                                 = 1000112000,
	ExternalFenceProperties                                         = 1000112001,
	ExportFenceCreateInfo                                           = 1000113000,
	ImportFenceWin32HandleInfoKHR                                   = 1000114000,
	ExportFenceWin32HandleInfoKHR                                   = 1000114001,
	FenceGetWin32HandleInfoKHR                                      = 1000114002,
	ImportFenceFdInfoKHR                                            = 1000115000,
	FenceGetFdInfoKHR                                               = 1000115001,
	PhysicalDevicePerformanceQueryFeaturesKHR                       = 1000116000,
	PhysicalDevicePerformanceQueryPropertiesKHR                     = 1000116001,
	QueryPoolPerformanceCreateInfoKHR                               = 1000116002,
	PerformanceQuerySubmitInfoKHR                                   = 1000116003,
	AcquireProfilingLockInfoKHR                                     = 1000116004,
	PerformanceCounterKHR                                           = 1000116005,
	PerformanceCounterDescriptionKHR                                = 1000116006,
	PhysicalDevicePointClippingProperties                           = 1000117000,
	RenderPassInputAttachmentAspectCreateInfo                       = 1000117001,
	ImageViewUsageCreateInfo                                        = 1000117002,
	PipelineTessellationDomainOriginStateCreateInfo                 = 1000117003,
	PhysicalDeviceSurfaceInfo2KHR                                   = 1000119000,
	SurfaceCapabilities2KHR                                         = 1000119001,
	SurfaceFormat2KHR                                               = 1000119002,
	PhysicalDeviceVariablePointersFeatures                          = 1000120000,
	DisplayProperties2KHR                                           = 1000121000,
	DisplayPlaneProperties2KHR                                      = 1000121001,
	DisplayModeProperties2KHR                                       = 1000121002,
	DisplayPlaneInfo2KHR                                            = 1000121003,
	DisplayPlaneCapabilities2KHR                                    = 1000121004,
	IosSurfaceCreateInfoMVK                                         = 1000122000,
	MacosSurfaceCreateInfoMVK                                       = 1000123000,
	MemoryDedicatedRequirements                                     = 1000127000,
	MemoryDedicatedAllocateInfo                                     = 1000127001,
	DebugUtilsObjectNameInfoEXT                                     = 1000128000,
	DebugUtilsObjectTagInfoEXT                                      = 1000128001,
	DebugUtilsLabelEXT                                              = 1000128002,
	DebugUtilsMessengerCallbackDataEXT                              = 1000128003,
	DebugUtilsMessengerCreateInfoEXT                                = 1000128004,
	ANDROIDHardwareBufferUsageANDROID                               = 1000129000,
	ANDROIDHardwareBufferPropertiesANDROID                          = 1000129001,
	ANDROIDHardwareBufferFormatPropertiesANDROID                    = 1000129002,
	ImportANDROIDHardwareBufferInfoANDROID                          = 1000129003,
	MemoryGetANDROIDHardwareBufferInfoANDROID                       = 1000129004,
	ExternalFormatANDROID                                           = 1000129005,
	ANDROIDHardwareBufferFormatProperties2ANDROID                   = 1000129006,
	PhysicalDeviceSamplerFilterMinmaxProperties                     = 1000130000,
	SamplerReductionModeCreateInfo                                  = 1000130001,
	PhysicalDeviceGpaFeaturesAMD                                    = 1000133000,
	PhysicalDeviceGpaPropertiesAMD                                  = 1000133001,
	GpaSampleBeginInfoAMD                                           = 1000133002,
	GpaSessionCreateInfoAMD                                         = 1000133003,
	GpaDeviceClockModeInfoAMD                                       = 1000133004,
	PhysicalDeviceGpaProperties2AMD                                 = 1000133005,
	GpaDeviceGetClockInfoAMD                                        = 1000133006,
	PhysicalDeviceShaderEnqueueFeaturesAMDX                         = 1000134000,
	PhysicalDeviceShaderEnqueuePropertiesAMDX                       = 1000134001,
	ExecutionGraphPipelineScratchSizeAMDX                           = 1000134002,
	ExecutionGraphPipelineCreateInfoAMDX                            = 1000134003,
	PipelineShaderStageNodeCreateInfoAMDX                           = 1000134004,
	TexelBufferDescriptorInfoEXT                                    = 1000135000,
	ImageDescriptorInfoEXT                                          = 1000135001,
	ResourceDescriptorInfoEXT                                       = 1000135002,
	BindHeapInfoEXT                                                 = 1000135003,
	PushDataInfoEXT                                                 = 1000135004,
	DescriptorSetAndBindingMappingEXT                               = 1000135005,
	ShaderDescriptorSetAndBindingMappingInfoEXT                     = 1000135006,
	OpaqueCaptureDataCreateInfoEXT                                  = 1000135007,
	PhysicalDeviceDescriptorHeapPropertiesEXT                       = 1000135008,
	PhysicalDeviceDescriptorHeapFeaturesEXT                         = 1000135009,
	CommandBufferInheritanceDescriptorHeapInfoEXT                   = 1000135010,
	SamplerCustomBorderColorIndexCreateInfoEXT                      = 1000135011,
	IndirectCommandsLayoutPushDataTokenNV                           = 1000135012,
	SubsampledImageFormatPropertiesEXT                              = 1000135013,
	PhysicalDeviceDescriptorHeapTensorPropertiesARM                 = 1000135014,
	PhysicalDeviceInlineUniformBlockFeatures                        = 1000138000,
	PhysicalDeviceInlineUniformBlockProperties                      = 1000138001,
	WriteDescriptorSetInlineUniformBlock                            = 1000138002,
	DescriptorPoolInlineUniformBlockCreateInfo                      = 1000138003,
	PhysicalDeviceShaderBfloat16FeaturesKHR                         = 1000141000,
	SampleLocationsInfoEXT                                          = 1000143000,
	RenderPassSampleLocationsBeginInfoEXT                           = 1000143001,
	PipelineSampleLocationsStateCreateInfoEXT                       = 1000143002,
	PhysicalDeviceSampleLocationsPropertiesEXT                      = 1000143003,
	MultisamplePropertiesEXT                                        = 1000143004,
	ProtectedSubmitInfo                                             = 1000145000,
	PhysicalDeviceProtectedMemoryFeatures                           = 1000145001,
	PhysicalDeviceProtectedMemoryProperties                         = 1000145002,
	DeviceQueueInfo2                                                = 1000145003,
	BufferMemoryRequirementsInfo2                                   = 1000146000,
	ImageMemoryRequirementsInfo2                                    = 1000146001,
	ImageSparseMemoryRequirementsInfo2                              = 1000146002,
	MemoryRequirements2                                             = 1000146003,
	SparseImageMemoryRequirements2                                  = 1000146004,
	ImageFormatListCreateInfo                                       = 1000147000,
	PhysicalDeviceBlendOperationAdvancedFeaturesEXT                 = 1000148000,
	PhysicalDeviceBlendOperationAdvancedPropertiesEXT               = 1000148001,
	PipelineColorBlendAdvancedStateCreateInfoEXT                    = 1000148002,
	PipelineCoverageToColorStateCreateInfoNV                        = 1000149000,
	AccelerationStructureBuildGeometryInfoKHR                       = 1000150000,
	AccelerationStructureDeviceAddressInfoKHR                       = 1000150002,
	AccelerationStructureGeometryAabbsDataKHR                       = 1000150003,
	AccelerationStructureGeometryInstancesDataKHR                   = 1000150004,
	AccelerationStructureGeometryTrianglesDataKHR                   = 1000150005,
	AccelerationStructureGeometryKHR                                = 1000150006,
	WriteDescriptorSetAccelerationStructureKHR                      = 1000150007,
	AccelerationStructureVersionInfoKHR                             = 1000150009,
	CopyAccelerationStructureInfoKHR                                = 1000150010,
	CopyAccelerationStructureToMemoryInfoKHR                        = 1000150011,
	CopyMemoryToAccelerationStructureInfoKHR                        = 1000150012,
	PhysicalDeviceAccelerationStructureFeaturesKHR                  = 1000150013,
	PhysicalDeviceAccelerationStructurePropertiesKHR                = 1000150014,
	RayTracingPipelineCreateInfoKHR                                 = 1000150015,
	RayTracingShaderGroupCreateInfoKHR                              = 1000150016,
	AccelerationStructureCreateInfoKHR                              = 1000150017,
	RayTracingPipelineInterfaceCreateInfoKHR                        = 1000150018,
	AccelerationStructureBuildSizesInfoKHR                          = 1000150020,
	PipelineCoverageModulationStateCreateInfoNV                     = 1000152000,
	PhysicalDeviceShaderSmBuiltinsFeaturesNV                        = 1000154000,
	PhysicalDeviceShaderSmBuiltinsPropertiesNV                      = 1000154001,
	SamplerYcbcrConversionCreateInfo                                = 1000156000,
	SamplerYcbcrConversionInfo                                      = 1000156001,
	BindImagePlaneMemoryInfo                                        = 1000156002,
	ImagePlaneMemoryRequirementsInfo                                = 1000156003,
	PhysicalDeviceSamplerYcbcrConversionFeatures                    = 1000156004,
	SamplerYcbcrConversionImageFormatProperties                     = 1000156005,
	BindBufferMemoryInfo                                            = 1000157000,
	BindImageMemoryInfo                                             = 1000157001,
	DrmFormatModifierPropertiesListEXT                              = 1000158000,
	PhysicalDeviceImageDrmFormatModifierInfoEXT                     = 1000158002,
	ImageDrmFormatModifierListCreateInfoEXT                         = 1000158003,
	ImageDrmFormatModifierExplicitCreateInfoEXT                     = 1000158004,
	ImageDrmFormatModifierPropertiesEXT                             = 1000158005,
	DrmFormatModifierPropertiesList2EXT                             = 1000158006,
	ValidationCacheCreateInfoEXT                                    = 1000160000,
	ShaderModuleValidationCacheCreateInfoEXT                        = 1000160001,
	DescriptorSetLayoutBindingFlagsCreateInfo                       = 1000161000,
	PhysicalDeviceDescriptorIndexingFeatures                        = 1000161001,
	PhysicalDeviceDescriptorIndexingProperties                      = 1000161002,
	DescriptorSetVariableDescriptorCountAllocateInfo                = 1000161003,
	DescriptorSetVariableDescriptorCountLayoutSupport               = 1000161004,
	PhysicalDevicePortabilitySubsetFeaturesKHR                      = 1000163000,
	PhysicalDevicePortabilitySubsetPropertiesKHR                    = 1000163001,
	PipelineViewportShadingRateImageStateCreateInfoNV               = 1000164000,
	PhysicalDeviceShadingRateImageFeaturesNV                        = 1000164001,
	PhysicalDeviceShadingRateImagePropertiesNV                      = 1000164002,
	PipelineViewportCoarseSampleOrderStateCreateInfoNV              = 1000164005,
	RayTracingPipelineCreateInfoNV                                  = 1000165000,
	AccelerationStructureCreateInfoNV                               = 1000165001,
	GeometryNV                                                      = 1000165003,
	GeometryTrianglesNV                                             = 1000165004,
	GeometryAabbNV                                                  = 1000165005,
	BindAccelerationStructureMemoryInfoNV                           = 1000165006,
	WriteDescriptorSetAccelerationStructureNV                       = 1000165007,
	AccelerationStructureMemoryRequirementsInfoNV                   = 1000165008,
	PhysicalDeviceRayTracingPropertiesNV                            = 1000165009,
	RayTracingShaderGroupCreateInfoNV                               = 1000165011,
	AccelerationStructureInfoNV                                     = 1000165012,
	PhysicalDeviceRepresentativeFragmentTestFeaturesNV              = 1000166000,
	PipelineRepresentativeFragmentTestStateCreateInfoNV             = 1000166001,
	PhysicalDeviceMaintenance3Properties                            = 1000168000,
	DescriptorSetLayoutSupport                                      = 1000168001,
	PhysicalDeviceImageViewImageFormatInfoEXT                       = 1000170000,
	FilterCubicImageViewImageFormatPropertiesEXT                    = 1000170001,
	PhysicalDeviceCooperativeMatrixConversionFeaturesQCOM           = 1000172000,
	PhysicalDeviceElapsedTimerQueryFeaturesQCOM                     = 1000173000,
	DeviceQueueGlobalPriorityCreateInfo                             = 1000174000,
	PhysicalDeviceShaderSubgroupExtendedTypesFeatures               = 1000175000,
	PhysicalDevice8BitStorageFeatures                               = 1000177000,
	ImportMemoryHostPointerInfoEXT                                  = 1000178000,
	MemoryHostPointerPropertiesEXT                                  = 1000178001,
	PhysicalDeviceExternalMemoryHostPropertiesEXT                   = 1000178002,
	PhysicalDeviceShaderAtomicInt64Features                         = 1000180000,
	PhysicalDeviceShaderClockFeaturesKHR                            = 1000181000,
	PipelineCompilerControlCreateInfoAMD                            = 1000183000,
	CalibratedTimestampInfoKHR                                      = 1000184000,
	PhysicalDeviceShaderCorePropertiesAMD                           = 1000185000,
	VideoDecodeH265CapabilitiesKHR                                  = 1000187000,
	VideoDecodeH265SessionParametersCreateInfoKHR                   = 1000187001,
	VideoDecodeH265SessionParametersAddInfoKHR                      = 1000187002,
	VideoDecodeH265ProfileInfoKHR                                   = 1000187003,
	VideoDecodeH265PictureInfoKHR                                   = 1000187004,
	VideoDecodeH265DpbSlotInfoKHR                                   = 1000187005,
	DeviceMemoryOverallocationCreateInfoAMD                         = 1000189000,
	PhysicalDeviceVertexAttributeDivisorPropertiesEXT               = 1000190000,
	PipelineVertexInputDivisorStateCreateInfo                       = 1000190001,
	PhysicalDeviceVertexAttributeDivisorFeatures                    = 1000190002,
	PresentFrameTokenGGP                                            = 1000191000,
	PipelineCreationFeedbackCreateInfo                              = 1000192000,
	PhysicalDeviceDriverProperties                                  = 1000196000,
	PhysicalDeviceFloatControlsProperties                           = 1000197000,
	PhysicalDeviceDepthStencilResolveProperties                     = 1000199000,
	SubpassDescriptionDepthStencilResolve                           = 1000199001,
	PhysicalDeviceComputeShaderDerivativesFeaturesKHR               = 1000201000,
	PhysicalDeviceMeshShaderFeaturesNV                              = 1000202000,
	PhysicalDeviceMeshShaderPropertiesNV                            = 1000202001,
	PhysicalDeviceFragmentShaderBarycentricFeaturesKHR              = 1000203000,
	PhysicalDeviceShaderImageFootprintFeaturesNV                    = 1000204000,
	PipelineViewportExclusiveScissorStateCreateInfoNV               = 1000205000,
	PhysicalDeviceExclusiveScissorFeaturesNV                        = 1000205002,
	CheckpointDataNV                                                = 1000206000,
	QueueFamilyCheckpointPropertiesNV                               = 1000206001,
	PhysicalDeviceTimelineSemaphoreFeatures                         = 1000207000,
	PhysicalDeviceTimelineSemaphoreProperties                       = 1000207001,
	SemaphoreTypeCreateInfo                                         = 1000207002,
	TimelineSemaphoreSubmitInfo                                     = 1000207003,
	SemaphoreWaitInfo                                               = 1000207004,
	SemaphoreSignalInfo                                             = 1000207005,
	PhysicalDevicePresentTimingFeaturesEXT                          = 1000208000,
	SwapchainTimingPropertiesEXT                                    = 1000208001,
	SwapchainTimeDomainPropertiesEXT                                = 1000208002,
	PresentTimingsInfoEXT                                           = 1000208003,
	PresentTimingInfoEXT                                            = 1000208004,
	PastPresentationTimingInfoEXT                                   = 1000208005,
	PastPresentationTimingPropertiesEXT                             = 1000208006,
	PastPresentationTimingEXT                                       = 1000208007,
	PresentTimingSurfaceCapabilitiesEXT                             = 1000208008,
	SwapchainCalibratedTimestampInfoEXT                             = 1000208009,
	PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL              = 1000209000,
	QueryPoolPerformanceQueryCreateInfoINTEL                        = 1000210000,
	InitializePerformanceApiInfoINTEL                               = 1000210001,
	PerformanceMarkerInfoINTEL                                      = 1000210002,
	PerformanceStreamMarkerInfoINTEL                                = 1000210003,
	PerformanceOverrideInfoINTEL                                    = 1000210004,
	PerformanceConfigurationAcquireInfoINTEL                        = 1000210005,
	PhysicalDeviceVulkanMemoryModelFeatures                         = 1000211000,
	PhysicalDevicePciBusInfoPropertiesEXT                           = 1000212000,
	DisplayNativeHdrSurfaceCapabilitiesAMD                          = 1000213000,
	SwapchainDisplayNativeHdrCreateInfoAMD                          = 1000213001,
	ImagepipeSurfaceCreateInfoFUCHSIA                               = 1000214000,
	PhysicalDeviceShaderTerminateInvocationFeatures                 = 1000215000,
	MetalSurfaceCreateInfoEXT                                       = 1000217000,
	PhysicalDeviceFragmentDensityMapFeaturesEXT                     = 1000218000,
	PhysicalDeviceFragmentDensityMapPropertiesEXT                   = 1000218001,
	RenderPassFragmentDensityMapCreateInfoEXT                       = 1000218002,
	PhysicalDeviceScalarBlockLayoutFeatures                         = 1000221000,
	PhysicalDeviceSubgroupSizeControlProperties                     = 1000225000,
	PipelineShaderStageRequiredSubgroupSizeCreateInfo               = 1000225001,
	PhysicalDeviceSubgroupSizeControlFeatures                       = 1000225002,
	FragmentShadingRateAttachmentInfoKHR                            = 1000226000,
	PipelineFragmentShadingRateStateCreateInfoKHR                   = 1000226001,
	PhysicalDeviceFragmentShadingRatePropertiesKHR                  = 1000226002,
	PhysicalDeviceFragmentShadingRateFeaturesKHR                    = 1000226003,
	PhysicalDeviceFragmentShadingRateKHR                            = 1000226004,
	PhysicalDeviceShaderCoreProperties2AMD                          = 1000227000,
	PhysicalDeviceCoherentMemoryFeaturesAMD                         = 1000229000,
	PhysicalDeviceShaderConstantDataFeaturesKHR                     = 1000231000,
	PhysicalDeviceDynamicRenderingLocalReadFeatures                 = 1000232000,
	RenderingAttachmentLocationInfo                                 = 1000232001,
	RenderingInputAttachmentIndexInfo                               = 1000232002,
	PhysicalDeviceShaderAbortFeaturesKHR                            = 1000233000,
	DeviceFaultShaderAbortMessageInfoKHR                            = 1000233001,
	PhysicalDeviceShaderAbortPropertiesKHR                          = 1000233002,
	PhysicalDeviceShaderImageAtomicInt64FeaturesEXT                 = 1000234000,
	PhysicalDeviceShaderQuadControlFeaturesKHR                      = 1000235000,
	PhysicalDeviceMemoryBudgetPropertiesEXT                         = 1000237000,
	PhysicalDeviceMemoryPriorityFeaturesEXT                         = 1000238000,
	MemoryPriorityAllocateInfoEXT                                   = 1000238001,
	SurfaceProtectedCapabilitiesKHR                                 = 1000239000,
	PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV        = 1000240000,
	PhysicalDeviceSeparateDepthStencilLayoutsFeatures               = 1000241000,
	AttachmentReferenceStencilLayout                                = 1000241001,
	AttachmentDescriptionStencilLayout                              = 1000241002,
	PhysicalDeviceBufferDeviceAddressFeaturesEXT                    = 1000244000,
	BufferDeviceAddressInfo                                         = 1000244001,
	BufferDeviceAddressCreateInfoEXT                                = 1000244002,
	PhysicalDeviceToolProperties                                    = 1000245000,
	ImageStencilUsageCreateInfo                                     = 1000246000,
	ValidationFeaturesEXT                                           = 1000247000,
	PhysicalDevicePresentWaitFeaturesKHR                            = 1000248000,
	PhysicalDeviceCooperativeMatrixFeaturesNV                       = 1000249000,
	CooperativeMatrixPropertiesNV                                   = 1000249001,
	PhysicalDeviceCooperativeMatrixPropertiesNV                     = 1000249002,
	PhysicalDeviceCoverageReductionModeFeaturesNV                   = 1000250000,
	PipelineCoverageReductionStateCreateInfoNV                      = 1000250001,
	FramebufferMixedSamplesCombinationNV                            = 1000250002,
	PhysicalDeviceFragmentShaderInterlockFeaturesEXT                = 1000251000,
	PhysicalDeviceYcbcrImageArraysFeaturesEXT                       = 1000252000,
	PhysicalDeviceUniformBufferStandardLayoutFeatures               = 1000253000,
	PhysicalDeviceProvokingVertexFeaturesEXT                        = 1000254000,
	PipelineRasterizationProvokingVertexStateCreateInfoEXT          = 1000254001,
	PhysicalDeviceProvokingVertexPropertiesEXT                      = 1000254002,
	SurfaceFullScreenExclusiveInfoEXT                               = 1000255000,
	SurfaceFullScreenExclusiveWin32InfoEXT                          = 1000255001,
	SurfaceCapabilitiesFullScreenExclusiveEXT                       = 1000255002,
	HeadlessSurfaceCreateInfoEXT                                    = 1000256000,
	PhysicalDeviceBufferDeviceAddressFeatures                       = 1000257000,
	BufferOpaqueCaptureAddressCreateInfo                            = 1000257002,
	MemoryOpaqueCaptureAddressAllocateInfo                          = 1000257003,
	DeviceMemoryOpaqueCaptureAddressInfo                            = 1000257004,
	PhysicalDeviceLineRasterizationFeatures                         = 1000259000,
	PipelineRasterizationLineStateCreateInfo                        = 1000259001,
	PhysicalDeviceLineRasterizationProperties                       = 1000259002,
	PhysicalDeviceShaderAtomicFloatFeaturesEXT                      = 1000260000,
	PhysicalDeviceHostQueryResetFeatures                            = 1000261000,
	PhysicalDeviceIndexTypeUint8Features                            = 1000265000,
	PhysicalDeviceExtendedDynamicStateFeaturesEXT                   = 1000267000, // Not promoted to 1.3
	PhysicalDevicePipelineExecutablePropertiesFeaturesKHR           = 1000269000,
	PipelineInfoKHR                                                 = 1000269001,
	PipelineExecutablePropertiesKHR                                 = 1000269002,
	PipelineExecutableInfoKHR                                       = 1000269003,
	PipelineExecutableStatisticKHR                                  = 1000269004,
	PipelineExecutableInternalRepresentationKHR                     = 1000269005,
	PhysicalDeviceHostImageCopyFeatures                             = 1000270000,
	PhysicalDeviceHostImageCopyProperties                           = 1000270001,
	MemoryToImageCopy                                               = 1000270002,
	ImageToMemoryCopy                                               = 1000270003,
	CopyImageToMemoryInfo                                           = 1000270004,
	CopyMemoryToImageInfo                                           = 1000270005,
	HostImageLayoutTransitionInfo                                   = 1000270006,
	CopyImageToImageInfo                                            = 1000270007,
	SubresourceHostMemcpySize                                       = 1000270008,
	HostImageCopyDevicePerformanceQuery                             = 1000270009,
	MemoryMapInfo                                                   = 1000271000,
	MemoryUnmapInfo                                                 = 1000271001,
	PhysicalDeviceMapMemoryPlacedFeaturesEXT                        = 1000272000,
	PhysicalDeviceMapMemoryPlacedPropertiesEXT                      = 1000272001,
	MemoryMapPlacedInfoEXT                                          = 1000272002,
	PhysicalDeviceShaderAtomicFloat2FeaturesEXT                     = 1000273000,
	SurfacePresentModeKHR                                           = 1000274000,
	SurfacePresentScalingCapabilitiesKHR                            = 1000274001,
	SurfacePresentModeCompatibilityKHR                              = 1000274002,
	PhysicalDeviceSwapchainMaintenance1FeaturesKHR                  = 1000275000,
	SwapchainPresentFenceInfoKHR                                    = 1000275001,
	SwapchainPresentModesCreateInfoKHR                              = 1000275002,
	SwapchainPresentModeInfoKHR                                     = 1000275003,
	SwapchainPresentScalingCreateInfoKHR                            = 1000275004,
	ReleaseSwapchainImagesInfoKHR                                   = 1000275005,
	PhysicalDeviceShaderDemoteToHelperInvocationFeatures            = 1000276000,
	PhysicalDeviceDeviceGeneratedCommandsPropertiesNV               = 1000277000,
	GraphicsShaderGroupCreateInfoNV                                 = 1000277001,
	GraphicsPipelineShaderGroupsCreateInfoNV                        = 1000277002,
	IndirectCommandsLayoutTokenNV                                   = 1000277003,
	IndirectCommandsLayoutCreateInfoNV                              = 1000277004,
	GeneratedCommandsInfoNV                                         = 1000277005,
	GeneratedCommandsMemoryRequirementsInfoNV                       = 1000277006,
	PhysicalDeviceDeviceGeneratedCommandsFeaturesNV                 = 1000277007,
	PhysicalDeviceInheritedViewportScissorFeaturesNV                = 1000278000,
	CommandBufferInheritanceViewportScissorInfoNV                   = 1000278001,
	PhysicalDeviceShaderIntegerDotProductFeatures                   = 1000280000,
	PhysicalDeviceShaderIntegerDotProductProperties                 = 1000280001,
	PhysicalDeviceTexelBufferAlignmentFeaturesEXT                   = 1000281000, // Not promoted to 1.3
	PhysicalDeviceTexelBufferAlignmentProperties                    = 1000281001,
	CommandBufferInheritanceRenderPassTransformInfoQCOM             = 1000282000,
	RenderPassTransformBeginInfoQCOM                                = 1000282001,
	PhysicalDeviceDepthBiasControlFeaturesEXT                       = 1000283000,
	DepthBiasInfoEXT                                                = 1000283001,
	DepthBiasRepresentationInfoEXT                                  = 1000283002,
	PhysicalDeviceDeviceMemoryReportFeaturesEXT                     = 1000284000,
	DeviceDeviceMemoryReportCreateInfoEXT                           = 1000284001,
	DeviceMemoryReportCallbackDataEXT                               = 1000284002,
	PhysicalDeviceRobustness2FeaturesKHR                            = 1000286000,
	PhysicalDeviceRobustness2PropertiesKHR                          = 1000286001,
	SamplerCustomBorderColorCreateInfoEXT                           = 1000287000,
	PhysicalDeviceCustomBorderColorPropertiesEXT                    = 1000287001,
	PhysicalDeviceCustomBorderColorFeaturesEXT                      = 1000287002,
	PhysicalDeviceTextureCompressionAstc3DFeaturesEXT               = 1000288000,
	PipelineLibraryCreateInfoKHR                                    = 1000290000,
	PhysicalDevicePresentBarrierFeaturesNV                          = 1000292000,
	SurfaceCapabilitiesPresentBarrierNV                             = 1000292001,
	SwapchainPresentBarrierCreateInfoNV                             = 1000292002,
	PresentIdKHR                                                    = 1000294000,
	PhysicalDevicePresentIdFeaturesKHR                              = 1000294001,
	PhysicalDevicePrivateDataFeatures                               = 1000295000,
	DevicePrivateDataCreateInfo                                     = 1000295001,
	PrivateDataSlotCreateInfo                                       = 1000295002,
	PhysicalDevicePipelineCreationCacheControlFeatures              = 1000297000,
	VideoEncodeInfoKHR                                              = 1000299000,
	VideoEncodeRateControlInfoKHR                                   = 1000299001,
	VideoEncodeRateControlLayerInfoKHR                              = 1000299002,
	VideoEncodeCapabilitiesKHR                                      = 1000299003,
	VideoEncodeUsageInfoKHR                                         = 1000299004,
	QueryPoolVideoEncodeFeedbackCreateInfoKHR                       = 1000299005,
	PhysicalDeviceVideoEncodeQualityLevelInfoKHR                    = 1000299006,
	VideoEncodeQualityLevelPropertiesKHR                            = 1000299007,
	VideoEncodeQualityLevelInfoKHR                                  = 1000299008,
	VideoEncodeSessionParametersGetInfoKHR                          = 1000299009,
	VideoEncodeSessionParametersFeedbackInfoKHR                     = 1000299010,
	PhysicalDeviceDiagnosticsConfigFeaturesNV                       = 1000300000,
	DeviceDiagnosticsConfigCreateInfoNV                             = 1000300001,
	PerfHintInfoQCOM                                                = 1000302000,
	PhysicalDeviceQueuePerfHintFeaturesQCOM                         = 1000302001,
	PhysicalDeviceQueuePerfHintPropertiesQCOM                       = 1000302002,
	PhysicalDeviceImageProcessing3FeaturesQCOM                      = 1000303000,
	PhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM              = 1000304000,
	PhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM            = 1000304001,
	PhysicalDeviceShaderSplitBarrierFeaturesEXT                     = 1000305000,
	PhysicalDeviceShaderSplitBarrierPropertiesEXT                   = 1000305001,
	CudaModuleCreateInfoNV                                          = 1000307000,
	CudaFunctionCreateInfoNV                                        = 1000307001,
	CudaLaunchInfoNV                                                = 1000307002,
	PhysicalDeviceCudaKernelLaunchFeaturesNV                        = 1000307003,
	PhysicalDeviceCudaKernelLaunchPropertiesNV                      = 1000307004,
	PhysicalDeviceTileShadingFeaturesQCOM                           = 1000309000,
	PhysicalDeviceTileShadingPropertiesQCOM                         = 1000309001,
	RenderPassTileShadingCreateInfoQCOM                             = 1000309002,
	PerTileBeginInfoQCOM                                            = 1000309003,
	PerTileEndInfoQCOM                                              = 1000309004,
	DispatchTileInfoQCOM                                            = 1000309005,
	QueryLowLatencySupportNV                                        = 1000310000,
	ExportMetalObjectCreateInfoEXT                                  = 1000311000,
	ExportMetalObjectsInfoEXT                                       = 1000311001,
	ExportMetalDeviceInfoEXT                                        = 1000311002,
	ExportMetalCommandQueueInfoEXT                                  = 1000311003,
	ExportMetalBufferInfoEXT                                        = 1000311004,
	ImportMetalBufferInfoEXT                                        = 1000311005,
	ExportMetalTextureInfoEXT                                       = 1000311006,
	ImportMetalTextureInfoEXT                                       = 1000311007,
	ExportMetalIoSurfaceInfoEXT                                     = 1000311008,
	ImportMetalIoSurfaceInfoEXT                                     = 1000311009,
	ExportMetalSharedEventInfoEXT                                   = 1000311010,
	ImportMetalSharedEventInfoEXT                                   = 1000311011,
	MemoryBarrier2                                                  = 1000314000,
	BufferMemoryBarrier2                                            = 1000314001,
	ImageMemoryBarrier2                                             = 1000314002,
	DependencyInfo                                                  = 1000314003,
	SubmitInfo2                                                     = 1000314004,
	SemaphoreSubmitInfo                                             = 1000314005,
	CommandBufferSubmitInfo                                         = 1000314006,
	PhysicalDeviceSynchronization2Features                          = 1000314007,
	QueueFamilyCheckpointProperties2NV                              = 1000314008,
	CheckpointData2NV                                               = 1000314009,
	PhysicalDeviceDescriptorBufferPropertiesEXT                     = 1000316000,
	PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT           = 1000316001,
	PhysicalDeviceDescriptorBufferFeaturesEXT                       = 1000316002,
	DescriptorAddressInfoEXT                                        = 1000316003,
	DescriptorGetInfoEXT                                            = 1000316004,
	BufferCaptureDescriptorDataInfoEXT                              = 1000316005,
	ImageCaptureDescriptorDataInfoEXT                               = 1000316006,
	ImageViewCaptureDescriptorDataInfoEXT                           = 1000316007,
	SamplerCaptureDescriptorDataInfoEXT                             = 1000316008,
	AccelerationStructureCaptureDescriptorDataInfoEXT               = 1000316009,
	OpaqueCaptureDescriptorDataCreateInfoEXT                        = 1000316010,
	DescriptorBufferBindingInfoEXT                                  = 1000316011,
	DescriptorBufferBindingPushDescriptorBufferHandleEXT            = 1000316012,
	DeviceMemoryCopyKHR                                             = 1000318000,
	CopyDeviceMemoryInfoKHR                                         = 1000318001,
	DeviceMemoryImageCopyKHR                                        = 1000318002,
	CopyDeviceMemoryImageInfoKHR                                    = 1000318003,
	MemoryRangeBarriersInfoKHR                                      = 1000318004,
	MemoryRangeBarrierKHR                                           = 1000318005,
	PhysicalDeviceDeviceAddressCommandsFeaturesKHR                  = 1000318006,
	BindIndexBuffer3InfoKHR                                         = 1000318007,
	BindVertexBuffer3InfoKHR                                        = 1000318008,
	DrawIndirect2InfoKHR                                            = 1000318009,
	DrawIndirectCount2InfoKHR                                       = 1000318010,
	DispatchIndirect2InfoKHR                                        = 1000318011,
	ConditionalRenderingBeginInfo2EXT                               = 1000318012,
	BindTransformFeedbackBuffer2InfoEXT                             = 1000318013,
	MemoryMarkerInfoAMD                                             = 1000318014,
	AccelerationStructureCreateInfo2KHR                             = 1000318015,
	PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT                = 1000320000,
	PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT              = 1000320001,
	GraphicsPipelineLibraryCreateInfoEXT                            = 1000320002,
	PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD        = 1000321000,
	PhysicalDeviceFragmentShaderBarycentricPropertiesKHR            = 1000322000,
	PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR       = 1000323000,
	PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures             = 1000325000,
	PhysicalDeviceFragmentShadingRateEnumsPropertiesNV              = 1000326000,
	PhysicalDeviceFragmentShadingRateEnumsFeaturesNV                = 1000326001,
	PipelineFragmentShadingRateEnumStateCreateInfoNV                = 1000326002,
	AccelerationStructureGeometryMotionTrianglesDataNV              = 1000327000,
	PhysicalDeviceRayTracingMotionBlurFeaturesNV                    = 1000327001,
	AccelerationStructureMotionInfoNV                               = 1000327002,
	PhysicalDeviceMeshShaderFeaturesEXT                             = 1000328000,
	PhysicalDeviceMeshShaderPropertiesEXT                           = 1000328001,
	PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT                  = 1000330000,
	PhysicalDeviceFragmentDensityMap2FeaturesEXT                    = 1000332000,
	PhysicalDeviceFragmentDensityMap2PropertiesEXT                  = 1000332001,
	CopyCommandTransformInfoQCOM                                    = 1000333000,
	PhysicalDeviceImageRobustnessFeatures                           = 1000335000,
	PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR          = 1000336000,
	CopyBufferInfo2                                                 = 1000337000,
	CopyImageInfo2                                                  = 1000337001,
	CopyBufferToImageInfo2                                          = 1000337002,
	CopyImageToBufferInfo2                                          = 1000337003,
	BlitImageInfo2                                                  = 1000337004,
	ResolveImageInfo2                                               = 1000337005,
	BufferCopy2                                                     = 1000337006,
	ImageCopy2                                                      = 1000337007,
	ImageBlit2                                                      = 1000337008,
	BufferImageCopy2                                                = 1000337009,
	ImageResolve2                                                   = 1000337010,
	PhysicalDeviceImageCompressionControlFeaturesEXT                = 1000338000,
	ImageCompressionControlEXT                                      = 1000338001,
	SubresourceLayout2                                              = 1000338002,
	ImageSubresource2                                               = 1000338003,
	ImageCompressionPropertiesEXT                                   = 1000338004,
	PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT           = 1000339000,
	PhysicalDevice4444FormatsFeaturesEXT                            = 1000340000,
	PhysicalDeviceFaultFeaturesEXT                                  = 1000341000,
	DeviceFaultCountsEXT                                            = 1000341001,
	DeviceFaultInfoEXT                                              = 1000341002,
	PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT     = 1000342000,
	PhysicalDeviceRgba10x6FormatsFeaturesEXT                        = 1000344000,
	DirectfbSurfaceCreateInfoEXT                                    = 1000346000,
	PhysicalDeviceRayTracingPipelineFeaturesKHR                     = 1000347000,
	PhysicalDeviceRayTracingPipelinePropertiesKHR                   = 1000347001,
	PhysicalDeviceRayQueryFeaturesKHR                               = 1000348013,
	PhysicalDeviceMutableDescriptorTypeFeaturesEXT                  = 1000351000,
	MutableDescriptorTypeCreateInfoEXT                              = 1000351002,
	PhysicalDeviceVertexInputDynamicStateFeaturesEXT                = 1000352000,
	VertexInputBindingDescription2EXT                               = 1000352001,
	VertexInputAttributeDescription2EXT                             = 1000352002,
	PhysicalDeviceDrmPropertiesEXT                                  = 1000353000,
	PhysicalDeviceAddressBindingReportFeaturesEXT                   = 1000354000,
	DeviceAddressBindingCallbackDataEXT                             = 1000354001,
	PhysicalDeviceDepthClipControlFeaturesEXT                       = 1000355000,
	PipelineViewportDepthClipControlCreateInfoEXT                   = 1000355001,
	PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT           = 1000356000,
	FormatProperties3                                               = 1000360000,
	PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR             = 1000361000,
	ImportMemoryZirconHandleInfoFUCHSIA                             = 1000364000,
	MemoryZirconHandlePropertiesFUCHSIA                             = 1000364001,
	MemoryGetZirconHandleInfoFUCHSIA                                = 1000364002,
	ImportSemaphoreZirconHandleInfoFUCHSIA                          = 1000365000,
	SemaphoreGetZirconHandleInfoFUCHSIA                             = 1000365001,
	BufferCollectionCreateInfoFUCHSIA                               = 1000366000,
	ImportMemoryBufferCollectionFUCHSIA                             = 1000366001,
	BufferCollectionImageCreateInfoFUCHSIA                          = 1000366002,
	BufferCollectionPropertiesFUCHSIA                               = 1000366003,
	BufferConstraintsInfoFUCHSIA                                    = 1000366004,
	BufferCollectionBufferCreateInfoFUCHSIA                         = 1000366005,
	ImageConstraintsInfoFUCHSIA                                     = 1000366006,
	ImageFormatConstraintsInfoFUCHSIA                               = 1000366007,
	SysmemColorSpaceFUCHSIA                                         = 1000366008,
	BufferCollectionConstraintsInfoFUCHSIA                          = 1000366009,
	SubpassShadingPipelineCreateInfoHUAWEI                          = 1000369000,
	PhysicalDeviceSubpassShadingFeaturesHUAWEI                      = 1000369001,
	PhysicalDeviceSubpassShadingPropertiesHUAWEI                    = 1000369002,
	PhysicalDeviceInvocationMaskFeaturesHUAWEI                      = 1000370000,
	MemoryGetRemoteAddressInfoNV                                    = 1000371000,
	PhysicalDeviceExternalMemoryRdmaFeaturesNV                      = 1000371001,
	PipelinePropertiesIdentifierEXT                                 = 1000372000,
	PhysicalDevicePipelinePropertiesFeaturesEXT                     = 1000372001,
	PhysicalDeviceFrameBoundaryFeaturesEXT                          = 1000375000,
	FrameBoundaryEXT                                                = 1000375001,
	PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT      = 1000376000,
	SubpassResolvePerformanceQueryEXT                               = 1000376001,
	MultisampledRenderToSingleSampledInfoEXT                        = 1000376002,
	PhysicalDeviceExtendedDynamicState2FeaturesEXT                  = 1000377000, // Not promoted to 1.3
	ScreenSurfaceCreateInfoQNX                                      = 1000378000,
	PhysicalDeviceColorWriteEnableFeaturesEXT                       = 1000381000,
	PipelineColorWriteCreateInfoEXT                                 = 1000381001,
	PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT               = 1000382000,
	PhysicalDeviceRayTracingMaintenance1FeaturesKHR                 = 1000386000,
	PhysicalDeviceShaderUntypedPointersFeaturesKHR                  = 1000387000,
	PhysicalDeviceGlobalPriorityQueryFeatures                       = 1000388000,
	QueueFamilyGlobalPriorityProperties                             = 1000388001,
	PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE             = 1000390000,
	VideoEncodeRgbConversionCapabilitiesVALVE                       = 1000390001,
	VideoEncodeProfileRgbConversionInfoVALVE                        = 1000390002,
	VideoEncodeSessionRgbConversionCreateInfoVALVE                  = 1000390003,
	PhysicalDeviceImageViewMinLodFeaturesEXT                        = 1000391000,
	ImageViewMinLodCreateInfoEXT                                    = 1000391001,
	PhysicalDeviceMultiDrawFeaturesEXT                              = 1000392000,
	PhysicalDeviceMultiDrawPropertiesEXT                            = 1000392001,
	PhysicalDeviceImage2DViewOf3DFeaturesEXT                        = 1000393000,
	PhysicalDeviceShaderTileImageFeaturesEXT                        = 1000395000,
	PhysicalDeviceShaderTileImagePropertiesEXT                      = 1000395001,
	MicromapBuildInfoEXT                                            = 1000396000,
	MicromapVersionInfoEXT                                          = 1000396001,
	CopyMicromapInfoEXT                                             = 1000396002,
	CopyMicromapToMemoryInfoEXT                                     = 1000396003,
	CopyMemoryToMicromapInfoEXT                                     = 1000396004,
	PhysicalDeviceOpacityMicromapFeaturesEXT                        = 1000396005,
	PhysicalDeviceOpacityMicromapPropertiesEXT                      = 1000396006,
	MicromapCreateInfoEXT                                           = 1000396007,
	MicromapBuildSizesInfoEXT                                       = 1000396008,
	AccelerationStructureTrianglesOpacityMicromapEXT                = 1000396009,
	PhysicalDeviceDisplacementMicromapFeaturesNV                    = 1000397000,
	PhysicalDeviceDisplacementMicromapPropertiesNV                  = 1000397001,
	AccelerationStructureTrianglesDisplacementMicromapNV            = 1000397002,
	PhysicalDeviceClusterCullingShaderFeaturesHUAWEI                = 1000404000,
	PhysicalDeviceClusterCullingShaderPropertiesHUAWEI              = 1000404001,
	PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI             = 1000404002,
	PhysicalDeviceBorderColorSwizzleFeaturesEXT                     = 1000411000,
	SamplerBorderColorComponentMappingCreateInfoEXT                 = 1000411001,
	PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT              = 1000412000,
	PhysicalDeviceMaintenance4Features                              = 1000413000,
	PhysicalDeviceMaintenance4Properties                            = 1000413001,
	DeviceBufferMemoryRequirements                                  = 1000413002,
	DeviceImageMemoryRequirements                                   = 1000413003,
	PhysicalDeviceShaderCorePropertiesARM                           = 1000415000,
	PhysicalDeviceShaderSubgroupRotateFeatures                      = 1000416000,
	DeviceQueueShaderCoreControlCreateInfoARM                       = 1000417000,
	PhysicalDeviceSchedulingControlsFeaturesARM                     = 1000417001,
	PhysicalDeviceSchedulingControlsPropertiesARM                   = 1000417002,
	DispatchParametersARM                                           = 1000417003,
	PhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM = 1000417004,
	PhysicalDeviceImageSlicedViewOf3DFeaturesEXT                    = 1000418000,
	ImageViewSlicedCreateInfoEXT                                    = 1000418001,
	PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE             = 1000420000,
	DescriptorSetBindingReferenceVALVE                              = 1000420001,
	DescriptorSetLayoutHostMappingInfoVALVE                         = 1000420002,
	PhysicalDeviceDepthClampZeroOneFeaturesKHR                      = 1000421000,
	PhysicalDeviceNonSeamlessCubeMapFeaturesEXT                     = 1000422000,
	PhysicalDeviceRenderPassStripedFeaturesARM                      = 1000424000,
	PhysicalDeviceRenderPassStripedPropertiesARM                    = 1000424001,
	RenderPassStripeBeginInfoARM                                    = 1000424002,
	RenderPassStripeInfoARM                                         = 1000424003,
	RenderPassStripeSubmitInfoARM                                   = 1000424004,
	PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT               = 1000425000,
	PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT             = 1000425001,
	RenderPassFragmentDensityMapOffsetEndInfoEXT                    = 1000425002,
	PhysicalDeviceCopyMemoryIndirectFeaturesNV                      = 1000426000,
	PhysicalDeviceCopyMemoryIndirectPropertiesKHR                   = 1000426001,
	PhysicalDeviceMemoryDecompressionFeaturesEXT                    = 1000427000,
	PhysicalDeviceMemoryDecompressionPropertiesEXT                  = 1000427001,
	PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV          = 1000428000,
	ComputePipelineIndirectBufferInfoNV                             = 1000428001,
	PipelineIndirectDeviceAddressInfoNV                             = 1000428002,
	PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV            = 1000429008,
	AccelerationStructureGeometryLinearSweptSpheresDataNV           = 1000429009,
	AccelerationStructureGeometrySpheresDataNV                      = 1000429010,
	PhysicalDeviceLinearColorAttachmentFeaturesNV                   = 1000430000,
	PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR             = 1000434000,
	PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT       = 1000437000,
	PhysicalDeviceImageProcessingFeaturesQCOM                       = 1000440000,
	PhysicalDeviceImageProcessingPropertiesQCOM                     = 1000440001,
	ImageViewSampleWeightCreateInfoQCOM                             = 1000440002,
	PhysicalDeviceNestedCommandBufferFeaturesEXT                    = 1000451000,
	PhysicalDeviceNestedCommandBufferPropertiesEXT                  = 1000451001,
	NativeBufferUsageOHOS                                           = 1000452000,
	NativeBufferPropertiesOHOS                                      = 1000452001,
	NativeBufferFormatPropertiesOHOS                                = 1000452002,
	ImportNativeBufferInfoOHOS                                      = 1000452003,
	MemoryGetNativeBufferInfoOHOS                                   = 1000452004,
	ExternalFormatOHOS                                              = 1000452005,
	ExternalMemoryAcquireUnmodifiedEXT                              = 1000453000,
	PhysicalDeviceExtendedDynamicState3FeaturesEXT                  = 1000455000,
	PhysicalDeviceExtendedDynamicState3PropertiesEXT                = 1000455001,
	PhysicalDeviceSubpassMergeFeedbackFeaturesEXT                   = 1000458000,
	RenderPassCreationControlEXT                                    = 1000458001,
	RenderPassCreationFeedbackCreateInfoEXT                         = 1000458002,
	RenderPassSubpassFeedbackCreateInfoEXT                          = 1000458003,
	DirectDriverLoadingInfoLUNARG                                   = 1000459000,
	DirectDriverLoadingListLUNARG                                   = 1000459001,
	TensorCreateInfoARM                                             = 1000460000,
	TensorViewCreateInfoARM                                         = 1000460001,
	BindTensorMemoryInfoARM                                         = 1000460002,
	WriteDescriptorSetTensorARM                                     = 1000460003,
	PhysicalDeviceTensorPropertiesARM                               = 1000460004,
	TensorFormatPropertiesARM                                       = 1000460005,
	TensorDescriptionARM                                            = 1000460006,
	TensorMemoryRequirementsInfoARM                                 = 1000460007,
	TensorMemoryBarrierARM                                          = 1000460008,
	PhysicalDeviceTensorFeaturesARM                                 = 1000460009,
	DeviceTensorMemoryRequirementsARM                               = 1000460010,
	CopyTensorInfoARM                                               = 1000460011,
	TensorCopyARM                                                   = 1000460012,
	TensorDependencyInfoARM                                         = 1000460013,
	MemoryDedicatedAllocateInfoTensorARM                            = 1000460014,
	PhysicalDeviceExternalTensorInfoARM                             = 1000460015,
	ExternalTensorPropertiesARM                                     = 1000460016,
	ExternalMemoryTensorCreateInfoARM                               = 1000460017,
	PhysicalDeviceDescriptorBufferTensorFeaturesARM                 = 1000460018,
	PhysicalDeviceDescriptorBufferTensorPropertiesARM               = 1000460019,
	DescriptorGetTensorInfoARM                                      = 1000460020,
	TensorCaptureDescriptorDataInfoARM                              = 1000460021,
	TensorViewCaptureDescriptorDataInfoARM                          = 1000460022,
	FrameBoundaryTensorsARM                                         = 1000460023,
	PhysicalDeviceShaderModuleIdentifierFeaturesEXT                 = 1000462000,
	PhysicalDeviceShaderModuleIdentifierPropertiesEXT               = 1000462001,
	PipelineShaderStageModuleIdentifierCreateInfoEXT                = 1000462002,
	ShaderModuleIdentifierEXT                                       = 1000462003,
	PhysicalDeviceOpticalFlowFeaturesNV                             = 1000464000,
	PhysicalDeviceOpticalFlowPropertiesNV                           = 1000464001,
	OpticalFlowImageFormatInfoNV                                    = 1000464002,
	OpticalFlowImageFormatPropertiesNV                              = 1000464003,
	OpticalFlowSessionCreateInfoNV                                  = 1000464004,
	OpticalFlowExecuteInfoNV                                        = 1000464005,
	OpticalFlowSessionCreatePrivateDataInfoNV                       = 1000464010,
	PhysicalDeviceLegacyDitheringFeaturesEXT                        = 1000465000,
	PhysicalDevicePipelineProtectedAccessFeatures                   = 1000466000,
	PhysicalDeviceExternalFormatResolveFeaturesANDROID              = 1000468000,
	PhysicalDeviceExternalFormatResolvePropertiesANDROID            = 1000468001,
	ANDROIDHardwareBufferFormatResolvePropertiesANDROID             = 1000468002,
	PhysicalDeviceMaintenance5Features                              = 1000470000,
	PhysicalDeviceMaintenance5Properties                            = 1000470001,
	RenderingAreaInfo                                               = 1000470003,
	DeviceImageSubresourceInfo                                      = 1000470004,
	PipelineCreateFlags2CreateInfo                                  = 1000470005,
	BufferUsageFlags2CreateInfo                                     = 1000470006,
	PhysicalDeviceAntiLagFeaturesAMD                                = 1000476000,
	AntiLagDataAMD                                                  = 1000476001,
	AntiLagPresentationInfoAMD                                      = 1000476002,
	PhysicalDeviceDenseGeometryFormatFeaturesAMDX                   = 1000478000,
	AccelerationStructureDenseGeometryFormatTrianglesDataAMDX       = 1000478001,
	SurfaceCapabilitiesPresentId2KHR                                = 1000479000,
	PresentId2KHR                                                   = 1000479001,
	PhysicalDevicePresentId2FeaturesKHR                             = 1000479002,
	SurfaceCapabilitiesPresentWait2KHR                              = 1000480000,
	PhysicalDevicePresentWait2FeaturesKHR                           = 1000480001,
	PresentWait2InfoKHR                                             = 1000480002,
	PhysicalDeviceRayTracingPositionFetchFeaturesKHR                = 1000481000,
	PhysicalDeviceShaderObjectFeaturesEXT                           = 1000482000,
	PhysicalDeviceShaderObjectPropertiesEXT                         = 1000482001,
	ShaderCreateInfoEXT                                             = 1000482002,
	PhysicalDevicePipelineBinaryFeaturesKHR                         = 1000483000,
	PipelineBinaryCreateInfoKHR                                     = 1000483001,
	PipelineBinaryInfoKHR                                           = 1000483002,
	PipelineBinaryKeyKHR                                            = 1000483003,
	PhysicalDevicePipelineBinaryPropertiesKHR                       = 1000483004,
	ReleaseCapturedPipelineDataInfoKHR                              = 1000483005,
	PipelineBinaryDataInfoKHR                                       = 1000483006,
	PipelineCreateInfoKHR                                           = 1000483007,
	DevicePipelineBinaryInternalCacheControlKHR                     = 1000483008,
	PipelineBinaryHandlesInfoKHR                                    = 1000483009,
	PhysicalDeviceTilePropertiesFeaturesQCOM                        = 1000484000,
	TilePropertiesQCOM                                              = 1000484001,
	PhysicalDeviceAmigoProfilingFeaturesSEC                         = 1000485000,
	AmigoProfilingSubmitInfoSEC                                     = 1000485001,
	PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM             = 1000488000,
	PhysicalDeviceRayTracingInvocationReorderFeaturesNV             = 1000490000,
	PhysicalDeviceRayTracingInvocationReorderPropertiesNV           = 1000490001,
	PhysicalDeviceCooperativeVectorFeaturesNV                       = 1000491000,
	PhysicalDeviceCooperativeVectorPropertiesNV                     = 1000491001,
	CooperativeVectorPropertiesNV                                   = 1000491002,
	ConvertCooperativeVectorMatrixInfoNV                            = 1000491004,
	PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV              = 1000492000,
	PhysicalDeviceExtendedSparseAddressSpacePropertiesNV            = 1000492001,
	PhysicalDeviceLegacyVertexAttributesFeaturesEXT                 = 1000495000,
	PhysicalDeviceLegacyVertexAttributesPropertiesEXT               = 1000495001,
	LayerSettingsCreateInfoEXT                                      = 1000496000,
	PhysicalDeviceShaderCoreBuiltinsFeaturesARM                     = 1000497000,
	PhysicalDeviceShaderCoreBuiltinsPropertiesARM                   = 1000497001,
	PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT            = 1000498000,
	PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT      = 1000499000,
	PhysicalDeviceInternallySynchronizedQueuesFeaturesKHR           = 1000504000,
	LatencySleepModeInfoNV                                          = 1000505000,
	LatencySleepInfoNV                                              = 1000505001,
	SetLatencyMarkerInfoNV                                          = 1000505002,
	GetLatencyMarkerInfoNV                                          = 1000505003,
	LatencyTimingsFrameReportNV                                     = 1000505004,
	LatencySubmissionPresentIdNV                                    = 1000505005,
	OutOfBandQueueTypeInfoNV                                        = 1000505006,
	SwapchainLatencyCreateInfoNV                                    = 1000505007,
	LatencySurfaceCapabilitiesNV                                    = 1000505008,
	PhysicalDeviceCooperativeMatrixFeaturesKHR                      = 1000506000,
	CooperativeMatrixPropertiesKHR                                  = 1000506001,
	PhysicalDeviceCooperativeMatrixPropertiesKHR                    = 1000506002,
	DataGraphPipelineCreateInfoARM                                  = 1000507000,
	DataGraphPipelineSessionCreateInfoARM                           = 1000507001,
	DataGraphPipelineResourceInfoARM                                = 1000507002,
	DataGraphPipelineConstantARM                                    = 1000507003,
	DataGraphPipelineSessionMemoryRequirementsInfoARM               = 1000507004,
	BindDataGraphPipelineSessionMemoryInfoARM                       = 1000507005,
	PhysicalDeviceDataGraphFeaturesARM                              = 1000507006,
	DataGraphPipelineShaderModuleCreateInfoARM                      = 1000507007,
	DataGraphPipelinePropertyQueryResultARM                         = 1000507008,
	DataGraphPipelineInfoARM                                        = 1000507009,
	DataGraphPipelineCompilerControlCreateInfoARM                   = 1000507010,
	DataGraphPipelineSessionBindPointRequirementsInfoARM            = 1000507011,
	DataGraphPipelineSessionBindPointRequirementARM                 = 1000507012,
	DataGraphPipelineIdentifierCreateInfoARM                        = 1000507013,
	DataGraphPipelineDispatchInfoARM                                = 1000507014,
	DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM    = 1000507015,
	DataGraphProcessingEngineCreateInfoARM                          = 1000507016,
	QueueFamilyDataGraphProcessingEnginePropertiesARM               = 1000507017,
	QueueFamilyDataGraphPropertiesARM                               = 1000507018,
	PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM       = 1000507019,
	QueueFamilyDataGraphTosaPropertiesARM                           = 1000508000,
	PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM           = 1000510000,
	MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM              = 1000510001,
	PhysicalDeviceComputeShaderDerivativesPropertiesKHR             = 1000511000,
	VideoDecodeAV1CapabilitiesKHR                                   = 1000512000,
	VideoDecodeAV1PictureInfoKHR                                    = 1000512001,
	VideoDecodeAV1ProfileInfoKHR                                    = 1000512003,
	VideoDecodeAV1SessionParametersCreateInfoKHR                    = 1000512004,
	VideoDecodeAV1DpbSlotInfoKHR                                    = 1000512005,
	VideoEncodeAV1CapabilitiesKHR                                   = 1000513000,
	VideoEncodeAV1SessionParametersCreateInfoKHR                    = 1000513001,
	VideoEncodeAV1PictureInfoKHR                                    = 1000513002,
	VideoEncodeAV1DpbSlotInfoKHR                                    = 1000513003,
	PhysicalDeviceVideoEncodeAV1FeaturesKHR                         = 1000513004,
	VideoEncodeAV1ProfileInfoKHR                                    = 1000513005,
	VideoEncodeAV1RateControlInfoKHR                                = 1000513006,
	VideoEncodeAV1RateControlLayerInfoKHR                           = 1000513007,
	VideoEncodeAV1QualityLevelPropertiesKHR                         = 1000513008,
	VideoEncodeAV1SessionCreateInfoKHR                              = 1000513009,
	VideoEncodeAV1GopRemainingFrameInfoKHR                          = 1000513010,
	PhysicalDeviceVideoDecodeVp9FeaturesKHR                         = 1000514000,
	VideoDecodeVp9CapabilitiesKHR                                   = 1000514001,
	VideoDecodeVp9PictureInfoKHR                                    = 1000514002,
	VideoDecodeVp9ProfileInfoKHR                                    = 1000514003,
	PhysicalDeviceVideoMaintenance1FeaturesKHR                      = 1000515000,
	VideoInlineQueryInfoKHR                                         = 1000515001,
	PhysicalDevicePerStageDescriptorSetFeaturesNV                   = 1000516000,
	PhysicalDeviceImageProcessing2FeaturesQCOM                      = 1000518000,
	PhysicalDeviceImageProcessing2PropertiesQCOM                    = 1000518001,
	SamplerBlockMatchWindowCreateInfoQCOM                           = 1000518002,
	SamplerCubicWeightsCreateInfoQCOM                               = 1000519000,
	PhysicalDeviceCubicWeightsFeaturesQCOM                          = 1000519001,
	BlitImageCubicWeightsInfoQCOM                                   = 1000519002,
	PhysicalDeviceYcbcrDegammaFeaturesQCOM                          = 1000520000,
	SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM                = 1000520001,
	PhysicalDeviceCubicClampFeaturesQCOM                            = 1000521000,
	PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT     = 1000524000,
	PhysicalDeviceVertexAttributeDivisorProperties                  = 1000525000,
	PhysicalDeviceUnifiedImageLayoutsFeaturesKHR                    = 1000527000,
	AttachmentFeedbackLoopInfoEXT                                   = 1000527001,
	PhysicalDeviceShaderFloatControls2Features                      = 1000528000,
	ScreenBufferPropertiesQNX                                       = 1000529000,
	ScreenBufferFormatPropertiesQNX                                 = 1000529001,
	ImportScreenBufferInfoQNX                                       = 1000529002,
	ExternalFormatQNX                                               = 1000529003,
	PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX             = 1000529004,
	PhysicalDeviceLayeredDriverPropertiesMSFT                       = 1000530000,
	PhysicalDeviceShaderExpectAssumeFeatures                        = 1000544000,
	PhysicalDeviceMaintenance6Features                              = 1000545000,
	PhysicalDeviceMaintenance6Properties                            = 1000545001,
	BindMemoryStatus                                                = 1000545002,
	BindDescriptorSetsInfo                                          = 1000545003,
	PushConstantsInfo                                               = 1000545004,
	PushDescriptorSetInfo                                           = 1000545005,
	PushDescriptorSetWithTemplateInfo                               = 1000545006,
	SetDescriptorBufferOffsetsInfoEXT                               = 1000545007,
	BindDescriptorBufferEmbeddedSamplersInfoEXT                     = 1000545008,
	PhysicalDeviceDescriptorPoolOverallocationFeaturesNV            = 1000546000,
	PhysicalDeviceTileMemoryHeapFeaturesQCOM                        = 1000547000,
	PhysicalDeviceTileMemoryHeapPropertiesQCOM                      = 1000547001,
	TileMemoryRequirementsQCOM                                      = 1000547002,
	TileMemoryBindInfoQCOM                                          = 1000547003,
	TileMemorySizeInfoQCOM                                          = 1000547004,
	PhysicalDeviceCopyMemoryIndirectFeaturesKHR                     = 1000549000,
	CopyMemoryIndirectInfoKHR                                       = 1000549002,
	CopyMemoryToImageIndirectInfoKHR                                = 1000549003,
	DecompressMemoryInfoEXT                                         = 1000550002,
	DisplaySurfaceStereoCreateInfoNV                                = 1000551000,
	DisplayModeStereoPropertiesNV                                   = 1000551001,
	VideoEncodeIntraRefreshCapabilitiesKHR                          = 1000552000,
	VideoEncodeSessionIntraRefreshCreateInfoKHR                     = 1000552001,
	VideoEncodeIntraRefreshInfoKHR                                  = 1000552002,
	VideoReferenceIntraRefreshInfoKHR                               = 1000552003,
	PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR                = 1000552004,
	VideoEncodeQuantizationMapCapabilitiesKHR                       = 1000553000,
	VideoFormatQuantizationMapPropertiesKHR                         = 1000553001,
	VideoEncodeQuantizationMapInfoKHR                               = 1000553002,
	VideoEncodeH264QuantizationMapCapabilitiesKHR                   = 1000553003,
	VideoEncodeH265QuantizationMapCapabilitiesKHR                   = 1000553004,
	VideoEncodeQuantizationMapSessionParametersCreateInfoKHR        = 1000553005,
	VideoFormatH265QuantizationMapPropertiesKHR                     = 1000553006,
	VideoEncodeAV1QuantizationMapCapabilitiesKHR                    = 1000553007,
	VideoFormatAV1QuantizationMapPropertiesKHR                      = 1000553008,
	PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR             = 1000553009,
	PhysicalDeviceRawAccessChainsFeaturesNV                         = 1000555000,
	ExternalComputeQueueDeviceCreateInfoNV                          = 1000556000,
	ExternalComputeQueueCreateInfoNV                                = 1000556001,
	ExternalComputeQueueDataParamsNV                                = 1000556002,
	PhysicalDeviceExternalComputeQueuePropertiesNV                  = 1000556003,
	PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR       = 1000558000,
	PhysicalDeviceCommandBufferInheritanceFeaturesNV                = 1000559000,
	PhysicalDeviceMaintenance7FeaturesKHR                           = 1000562000,
	PhysicalDeviceMaintenance7PropertiesKHR                         = 1000562001,
	PhysicalDeviceLayeredApiPropertiesListKHR                       = 1000562002,
	PhysicalDeviceLayeredApiPropertiesKHR                           = 1000562003,
	PhysicalDeviceLayeredApiVulkanPropertiesKHR                     = 1000562004,
	PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV               = 1000563000,
	PhysicalDeviceShaderReplicatedCompositesFeaturesEXT             = 1000564000,
	TensorExplicitTilingFormatPropertiesARM                         = 1000565000,
	TensorRollingBackingCreateInfoARM                               = 1000565001,
	PhysicalDeviceShaderFloat8FeaturesEXT                           = 1000567000,
	PhysicalDeviceRayTracingValidationFeaturesNV                    = 1000568000,
	PhysicalDeviceClusterAccelerationStructureFeaturesNV            = 1000569000,
	PhysicalDeviceClusterAccelerationStructurePropertiesNV          = 1000569001,
	ClusterAccelerationStructureClustersBottomLevelInputNV          = 1000569002,
	ClusterAccelerationStructureTriangleClusterInputNV              = 1000569003,
	ClusterAccelerationStructureMoveObjectsInputNV                  = 1000569004,
	ClusterAccelerationStructureInputInfoNV                         = 1000569005,
	ClusterAccelerationStructureCommandsInfoNV                      = 1000569006,
	RayTracingPipelineClusterAccelerationStructureCreateInfoNV      = 1000569007,
	PhysicalDevicePartitionedAccelerationStructureFeaturesNV        = 1000570000,
	PhysicalDevicePartitionedAccelerationStructurePropertiesNV      = 1000570001,
	WriteDescriptorSetPartitionedAccelerationStructureNV            = 1000570002,
	PartitionedAccelerationStructureInstancesInputNV                = 1000570003,
	BuildPartitionedAccelerationStructureInfoNV                     = 1000570004,
	PartitionedAccelerationStructureFlagsNV                         = 1000570005,
	PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT                = 1000572000,
	PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT              = 1000572001,
	GeneratedCommandsMemoryRequirementsInfoEXT                      = 1000572002,
	IndirectExecutionSetCreateInfoEXT                               = 1000572003,
	GeneratedCommandsInfoEXT                                        = 1000572004,
	IndirectCommandsLayoutCreateInfoEXT                             = 1000572006,
	IndirectCommandsLayoutTokenEXT                                  = 1000572007,
	WriteIndirectExecutionSetPipelineEXT                            = 1000572008,
	WriteIndirectExecutionSetShaderEXT                              = 1000572009,
	IndirectExecutionSetPipelineInfoEXT                             = 1000572010,
	IndirectExecutionSetShaderInfoEXT                               = 1000572011,
	IndirectExecutionSetShaderLayoutInfoEXT                         = 1000572012,
	GeneratedCommandsPipelineInfoEXT                                = 1000572013,
	GeneratedCommandsShaderInfoEXT                                  = 1000572014,
	PhysicalDeviceFaultFeaturesKHR                                  = 1000573000,
	PhysicalDeviceFaultPropertiesKHR                                = 1000573001,
	DeviceFaultInfoKHR                                              = 1000573002,
	DeviceFaultDebugInfoKHR                                         = 1000573003,
	PhysicalDeviceMaintenance8FeaturesKHR                           = 1000574000,
	MemoryBarrierAccessFlags3KHR                                    = 1000574002,
	PhysicalDeviceImageAlignmentControlFeaturesMESA                 = 1000575000,
	PhysicalDeviceImageAlignmentControlPropertiesMESA               = 1000575001,
	ImageAlignmentControlCreateInfoMESA                             = 1000575002,
	PhysicalDeviceShaderFmaFeaturesKHR                              = 1000579000,
	PushConstantBankInfoNV                                          = 1000580000,
	PhysicalDevicePushConstantBankFeaturesNV                        = 1000580001,
	PhysicalDevicePushConstantBankPropertiesNV                      = 1000580002,
	PhysicalDeviceRayTracingInvocationReorderFeaturesEXT            = 1000581000,
	PhysicalDeviceRayTracingInvocationReorderPropertiesEXT          = 1000581001,
	PhysicalDeviceDepthClampControlFeaturesEXT                      = 1000582000,
	PipelineViewportDepthClampControlCreateInfoEXT                  = 1000582001,
	PhysicalDeviceMaintenance9FeaturesKHR                           = 1000584000,
	PhysicalDeviceMaintenance9PropertiesKHR                         = 1000584001,
	QueueFamilyOwnershipTransferPropertiesKHR                       = 1000584002,
	PhysicalDeviceVideoMaintenance2FeaturesKHR                      = 1000586000,
	VideoDecodeH264InlineSessionParametersInfoKHR                   = 1000586001,
	VideoDecodeH265InlineSessionParametersInfoKHR                   = 1000586002,
	VideoDecodeAV1InlineSessionParametersInfoKHR                    = 1000586003,
	PhysicalDeviceHdrVividFeaturesHUAWEI                            = 1000590000,
	HdrVividDynamicMetadataHUAWEI                                   = 1000590001,
	PhysicalDeviceCooperativeMatrix2FeaturesNV                      = 1000593000,
	CooperativeMatrixFlexibleDimensionsPropertiesNV                 = 1000593001,
	PhysicalDeviceCooperativeMatrix2PropertiesNV                    = 1000593002,
	PhysicalDevicePipelineOpacityMicromapFeaturesARM                = 1000596000,
	PhysicalDeviceVideoEncodeFeedback2FeaturesKHR                   = 1000598000,
	VideoEncodeFeedback2CapabilitiesKHR                             = 1000598001,
	QueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR           = 1000598002,
	ImportMemoryMetalHandleInfoEXT                                  = 1000602000,
	MemoryMetalHandlePropertiesEXT                                  = 1000602001,
	MemoryGetMetalHandleInfoEXT                                     = 1000602002,
	PhysicalDevicePerformanceCountersByRegionFeaturesARM            = 1000605000,
	PhysicalDevicePerformanceCountersByRegionPropertiesARM          = 1000605001,
	PerformanceCounterARM                                           = 1000605002,
	PerformanceCounterDescriptionARM                                = 1000605003,
	RenderPassPerformanceCountersByRegionBeginInfoARM               = 1000605004,
	PhysicalDeviceShaderInstrumentationFeaturesARM                  = 1000607000,
	PhysicalDeviceShaderInstrumentationPropertiesARM                = 1000607001,
	ShaderInstrumentationCreateInfoARM                              = 1000607002,
	ShaderInstrumentationMetricDescriptionARM                       = 1000607003,
	PhysicalDeviceVertexAttributeRobustnessFeaturesEXT              = 1000608000,
	PhysicalDeviceFormatPackFeaturesARM                             = 1000609000,
	PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE            = 1000611000,
	PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE          = 1000611001,
	PipelineFragmentDensityMapLayeredCreateInfoVALVE                = 1000611002,
	SetPresentConfigNV                                              = 1000613000,
	PhysicalDevicePresentMeteringFeaturesNV                         = 1000613001,
	PhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT          = 1000616000,
	SwapchainFlagsSurfaceCapabilitiesEXT                            = 1000616001,
	RenderingEndInfoKHR                                             = 1000619003,
	PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT             = 1000620000,
	PhysicalDeviceOpacityMicromapFeaturesKHR                        = 1000623000,
	PhysicalDeviceOpacityMicromapPropertiesKHR                      = 1000623001,
	AccelerationStructureGeometryMicromapDataKHR                    = 1000623002,
	AccelerationStructureTrianglesOpacityMicromapKHR                = 1000623003,
	PhysicalDeviceShader64BitIndexingFeaturesEXT                    = 1000627000,
	PhysicalDeviceCustomResolveFeaturesEXT                          = 1000628000,
	BeginCustomResolveInfoEXT                                       = 1000628001,
	CustomResolveCreateInfoEXT                                      = 1000628002,
	PhysicalDeviceDataGraphModelFeaturesQCOM                        = 1000629000,
	DataGraphPipelineBuiltinModelCreateInfoQCOM                     = 1000629001,
	PhysicalDeviceMaintenance10FeaturesKHR                          = 1000630000,
	PhysicalDeviceMaintenance10PropertiesKHR                        = 1000630001,
	RenderingAttachmentFlagsInfoKHR                                 = 1000630002,
	ResolveImageModeInfoKHR                                         = 1000630004,
	PhysicalDeviceDataGraphOpticalFlowFeaturesARM                   = 1000631000,
	QueueFamilyDataGraphOpticalFlowPropertiesARM                    = 1000631001,
	DataGraphPipelineOpticalFlowCreateInfoARM                       = 1000631002,
	DataGraphOpticalFlowImageFormatInfoARM                          = 1000631003,
	DataGraphOpticalFlowImageFormatPropertiesARM                    = 1000631004,
	DataGraphPipelineOpticalFlowDispatchInfoARM                     = 1000631005,
	DataGraphPipelineResourceInfoImageLayoutARM                     = 1000631006,
	DataGraphPipelineSingleNodeCreateInfoARM                        = 1000631007,
	DataGraphPipelineSingleNodeConnectionARM                        = 1000631008,
	PhysicalDeviceShaderLongVectorFeaturesEXT                       = 1000635000,
	PhysicalDeviceShaderLongVectorPropertiesEXT                     = 1000635001,
	PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC           = 1000637000,
	PhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT        = 1000642000,
	ComputeOccupancyPriorityParametersNV                            = 1000645000,
	PhysicalDeviceComputeOccupancyPriorityFeaturesNV                = 1000645001,
	PhysicalDeviceMaintenance11FeaturesKHR                          = 1000657000,
	QueueFamilyOptimalImageTransferGranularityPropertiesKHR         = 1000657001,
	PhysicalDeviceShaderSubgroupPartitionedFeaturesEXT              = 1000662000,
	UbmSurfaceCreateInfoSEC                                         = 1000664000,
	FormatProperties4KHR                                            = 1000668000,
	ImageCreateFlags2CreateInfoKHR                                  = 1000668001,
	ImageUsageFlags2CreateInfoKHR                                   = 1000668002,
	ImageViewUsage2CreateInfoKHR                                    = 1000668003,
	PhysicalDeviceExtendedFlagsFeaturesKHR                          = 1000668004,
	ImageStencilUsage2CreateInfoKHR                                 = 1000668005,
	SharedPresentSurfaceCapabilities2KHR                            = 1000668006,
	PhysicalDeviceShaderOcpMicroscalingTypesFeaturesEXT             = 1000672000,
	PhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE           = 1000673000,
	PhysicalDeviceThrottleHintFeaturesSEC                           = 1000674000,
	ThrottleHintSubmitInfoSEC                                       = 1000674001,
	DataGraphPipelineNeuralStatisticsCreateInfoARM                  = 1000676000,
	DataGraphPipelineSessionNeuralStatisticsCreateInfoARM           = 1000676001,
	PhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM   = 1000676002,
	PhysicalDevicePrimitiveRestartIndexFeaturesEXT                  = 1000678000,
	SurfaceCreateInfoOHOS                                           = 1000685000,
	PhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV           = 1000689000,
};
enum class SubgroupFeatureBits : std::int32_t {
	Basic             = 0x00000001, // Basic subgroup operations
	Vote              = 0x00000002, // Vote subgroup operations
	Arithmetic        = 0x00000004, // Arithmetic subgroup operations
	Ballot            = 0x00000008, // Ballot subgroup operations
	Shuffle           = 0x00000010, // Shuffle subgroup operations
	ShuffleRelative   = 0x00000020, // Shuffle relative subgroup operations
	Clustered         = 0x00000040, // Clustered subgroup operations
	Quad              = 0x00000080, // Quad subgroup operations
	PartitionedBitEXT = 0x00000100,
	Rotate            = 0x00000200,
	RotateClustered   = 0x00000400,
	AllBits           = 0x000007ff, // generated for ~(not), error checking and for convenience
};
using SubgroupFeatureFlags = impl_Enum::Flags<SubgroupFeatureBits>;
enum class SubmitBits : std::int32_t {
	Protected = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
};
using SubmitFlags = impl_Enum::Flags<SubmitBits>;
enum class SubpassContents : std::int32_t {
	Inline                              =          0,
	SecondaryCommandBuffers             =          1,
	InlineAndSecondaryCommandBuffersKHR = 1000451000,
};
enum class SubpassDescriptionBits : std::int32_t {
	PerViewAttributesBitNVX                         = 0x00000001,
	PerViewPositionxOnlyBitNVX                      = 0x00000002,
	FragmentRegionBitEXT                            = 0x00000004,
	CustomResolveBitEXT                             = 0x00000008,
	RasterizationOrderAttachmentColorAccessBitEXT   = 0x00000010,
	RasterizationOrderAttachmentDepthAccessBitEXT   = 0x00000020,
	RasterizationOrderAttachmentStencilAccessBitEXT = 0x00000040,
	EnableLegacyDitheringBitEXT                     = 0x00000080,
	TileShadingApronBitQCOM                         = 0x00000100,
	AllBits                                         = 0x000001ff, // generated for ~(not), error checking and for convenience
};
using SubpassDescriptionFlags = impl_Enum::Flags<SubpassDescriptionBits>;
enum class SubpassMergeStatusEXT : std::int32_t {
	Merged                               =          0,
	Disallowed                           =          1,
	NotMergedSideEffects                 =          2,
	NotMergedSamplesMismatch             =          3,
	NotMergedViewsMismatch               =          4,
	NotMergedAliasing                    =          5,
	NotMergedDependencies                =          6,
	NotMergedIncompatibleInputAttachment =          7,
	NotMergedTooManyAttachments          =          8,
	NotMergedInsufficientStorage         =          9,
	NotMergedDepthStencilCount           =         10,
	NotMergedResolveAttachmentReuse      =         11,
	NotMergedSingleSubpass               =         12,
	NotMergedUnspecified                 =         13,
};
enum class SurfaceCounterBitsEXT : std::int32_t {
	Vblank  = 0x00000001,
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
using SurfaceCounterFlagsEXT = impl_Enum::Flags<SurfaceCounterBitsEXT>;
enum class SurfaceCreateBitsOHOS : std::int32_t {};
using SurfaceCreateFlagsOHOS = impl_Enum::Flags<SurfaceCreateBitsOHOS>;
enum class SurfaceTransformBitsKHR : std::int32_t {
	Identity                  = 0x00000001,
	Rotate90                  = 0x00000002,
	Rotate180                 = 0x00000004,
	Rotate270                 = 0x00000008,
	HorizontalMirror          = 0x00000010,
	HorizontalMirrorRotate90  = 0x00000020,
	HorizontalMirrorRotate180 = 0x00000040,
	HorizontalMirrorRotate270 = 0x00000080,
	Inherit                   = 0x00000100,
	AllBits                   = 0x000001ff, // generated for ~(not), error checking and for convenience
};
using SurfaceTransformFlagsKHR = impl_Enum::Flags<SurfaceTransformBitsKHR>;
enum class SwapchainCreateBitsKHR : std::int32_t {
	SplitInstanceBindRegions                = 0x00000001, // Allow images with VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT
	Protected                               = 0x00000002, // Swapchain is protected
	MutableFormat                           = 0x00000004,
	DeferredMemoryAllocation                = 0x00000008,
	PresentId2                              = 0x00000040, // Allow use of VK_KHR_present_id2 with this swapchain
	PresentWait2                            = 0x00000080, // Allow use of VK_KHR_present_wait2 with this swapchain
	MultisampledRenderToSingleSampledBitEXT = 0x00000100,
	PresentTimingBitEXT                     = 0x00000200,
	AllBits                                 = 0x000003cf, // generated for ~(not), error checking and for convenience
};
using SwapchainCreateFlagsKHR = impl_Enum::Flags<SwapchainCreateBitsKHR>;
enum class SwapchainImageUsageBitsANDROID : std::int32_t {};
using SwapchainImageUsageFlagsANDROID = impl_Enum::Flags<SwapchainImageUsageBitsANDROID>;
enum class SwapchainImageUsageBitsOHOS : std::int32_t {};
using SwapchainImageUsageFlagsOHOS = impl_Enum::Flags<SwapchainImageUsageBitsOHOS>;
enum class SystemAllocationScope : std::int32_t {
	Command  =          0,
	Object   =          1,
	Cache    =          2,
	Device   =          3,
	Instance =          4,
};
enum class TensorCreateBitsARM : std::uint64_t {
	MutableFormat                 = 0x0000000000000001,
	Protected                     = 0x0000000000000002,
	DescriptorBufferCaptureReplay = 0x0000000000000004,
	DescriptorHeapCaptureReplay   = 0x0000000000000008,
	AllBits                       = 0x000000000000000f, // generated for ~(not), error checking and for convenience
};
using TensorCreateFlagsARM = impl_Enum::Flags<TensorCreateBitsARM>;
enum class TensorTilingARM : std::int32_t {
	Optimal              =          0,
	Linear               =          1,
	Brick16Wide          = 1000565000,
	Brick8Wide           = 1000565001,
	Brick4Wide           = 1000565002,
	BlockUInterleaved    = 1000565003,
	BlockUInterleaved64K = 1000565004,
};
enum class TensorUsageBitsARM : std::uint64_t {
	Shader        = 0x0000000000000002, // Tensor written/read through shader descriptor
	TransferSrc   = 0x0000000000000004, // Tensor can be src of a transfer operation
	TransferDst   = 0x0000000000000008, // Tensor can be dst of a transfer operation
	ImageAliasing = 0x0000000000000010, // Tensor can be aliased with an image
	DataGraph     = 0x0000000000000020,
	AllBits       = 0x000000000000003e, // generated for ~(not), error checking and for convenience
};
using TensorUsageFlagsARM = impl_Enum::Flags<TensorUsageBitsARM>;
enum class TensorViewCreateBitsARM : std::uint64_t {
	DescriptorBufferCaptureReplay = 0x0000000000000001,
	AllBits                       = 0x0000000000000001, // generated for ~(not), error checking and for convenience
};
using TensorViewCreateFlagsARM = impl_Enum::Flags<TensorViewCreateBitsARM>;
enum class TessellationDomainOrigin : std::int32_t {
	UpperLeft =          0,
	LowerLeft =          1,
};
enum class ThrottleHintTypeSEC : std::int32_t {
	Default =          0,
	Low     =          1,
	High    =          2,
};
enum class TileShadingRenderPassBitsQCOM : std::int32_t {
	Enable           = 0x00000001,
	PerTileExecution = 0x00000002,
	AllBits          = 0x00000003, // generated for ~(not), error checking and for convenience
};
using TileShadingRenderPassFlagsQCOM = impl_Enum::Flags<TileShadingRenderPassBitsQCOM>;
enum class TimeDomainKHR : std::int32_t {
	Device                  =          0,
	ClockMonotonic          =          1,
	ClockMonotonicRaw       =          2,
	QueryPerformanceCounter =          3,
	PresentStageLocalEXT    = 1000208000,
	SwapchainLocalEXT       = 1000208001,
};
enum class ToolPurposeBits : std::int32_t {
	Validation           = 0x00000001,
	Profiling            = 0x00000002,
	Tracing              = 0x00000004,
	AdditionalFeatures   = 0x00000008,
	ModifyingFeatures    = 0x00000010,
	DebugReportingBitEXT = 0x00000020,
	DebugMarkersBitEXT   = 0x00000040,
	AllBits              = 0x0000007f, // generated for ~(not), error checking and for convenience
};
using ToolPurposeFlags = impl_Enum::Flags<ToolPurposeBits>;
enum class UbmSurfaceCreateBitsSEC : std::int32_t {};
using UbmSurfaceCreateFlagsSEC = impl_Enum::Flags<UbmSurfaceCreateBitsSEC>;
enum class ValidationCacheCreateBitsEXT : std::int32_t {};
using ValidationCacheCreateFlagsEXT = impl_Enum::Flags<ValidationCacheCreateBitsEXT>;
enum class ValidationCacheHeaderVersionEXT : std::int32_t {
	One =          1,
};
enum class ValidationCheckEXT : std::int32_t {
	All     =          0,
	Shaders =          1,
};
enum class ValidationFeatureDisableEXT : std::int32_t {
	All                   =          0,
	Shaders               =          1,
	ThreadSafety          =          2,
	ApiParameters         =          3,
	ObjectLifetimes       =          4,
	CoreChecks            =          5,
	UniqueHandles         =          6,
	ShaderValidationCache =          7,
};
enum class ValidationFeatureEnableEXT : std::int32_t {
	GpuAssisted                   =          0,
	GpuAssistedReserveBindingSlot =          1,
	BestPractices                 =          2,
	DebugPrintf                   =          3,
	SynchronizationValidation     =          4,
};
enum class VendorId : std::int32_t {
	Khronos  =      65536, // Khronos vendor ID
	VIV      =      65537, // Vivante vendor ID
	VSI      =      65538, // VeriSilicon vendor ID
	Kazan    =      65539, // Kazan Software Renderer
	Codeplay =      65540, // Codeplay Software Ltd. vendor ID
	MESA     =      65541, // Mesa vendor ID
	Pocl     =      65542, // PoCL vendor ID
	Mobileye =      65543, // Mobileye vendor ID
	Ape      =      65544, // Ape vendor ID
};
enum class VertexInputRate : std::int32_t {
	Vertex   =          0,
	Instance =          1,
};
enum class ViSurfaceCreateBitsNN : std::int32_t {};
using ViSurfaceCreateFlagsNN = impl_Enum::Flags<ViSurfaceCreateBitsNN>;
enum class VideoBeginCodingBitsKHR : std::int32_t {};
using VideoBeginCodingFlagsKHR = impl_Enum::Flags<VideoBeginCodingBitsKHR>;
enum class VideoCapabilityBitsKHR : std::int32_t {
	ProtectedContent        = 0x00000001,
	SeparateReferenceImages = 0x00000002,
	AllBits                 = 0x00000003, // generated for ~(not), error checking and for convenience
};
using VideoCapabilityFlagsKHR = impl_Enum::Flags<VideoCapabilityBitsKHR>;
enum class VideoChromaSubsamplingBitsKHR : std::int32_t {
	Invalid    = 0x00000000,
	Monochrome = 0x00000001,
	v420       = 0x00000002,
	v422       = 0x00000004,
	v444       = 0x00000008,
	AllBits    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using VideoChromaSubsamplingFlagsKHR = impl_Enum::Flags<VideoChromaSubsamplingBitsKHR>;
enum class VideoCodecOperationBitsKHR : std::int32_t {
	None       = 0x00000000,
	DecodeH264 = 0x00000001,
	DecodeH265 = 0x00000002,
	DecodeAV1  = 0x00000004,
	DecodeVp9  = 0x00000008,
	EncodeH264 = 0x00010000,
	EncodeH265 = 0x00020000,
	EncodeAV1  = 0x00040000,
	AllBits    = 0x0007000f, // generated for ~(not), error checking and for convenience
};
using VideoCodecOperationFlagsKHR = impl_Enum::Flags<VideoCodecOperationBitsKHR>;
enum class VideoCodingControlBitsKHR : std::int32_t {
	Reset              = 0x00000001,
	EncodeRateControl  = 0x00000002,
	EncodeQualityLevel = 0x00000004,
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
using VideoCodingControlFlagsKHR = impl_Enum::Flags<VideoCodingControlBitsKHR>;
enum class VideoComponentBitDepthBitsKHR : std::int32_t {
	Invalid = 0x00000000,
	v8      = 0x00000001,
	v10     = 0x00000004,
	v12     = 0x00000010,
	AllBits = 0x00000015, // generated for ~(not), error checking and for convenience
};
using VideoComponentBitDepthFlagsKHR = impl_Enum::Flags<VideoComponentBitDepthBitsKHR>;
enum class VideoDecodeCapabilityBitsKHR : std::int32_t {
	DpbAndOutputCoincide = 0x00000001,
	DpbAndOutputDistinct = 0x00000002,
	AllBits              = 0x00000003, // generated for ~(not), error checking and for convenience
};
using VideoDecodeCapabilityFlagsKHR = impl_Enum::Flags<VideoDecodeCapabilityBitsKHR>;
enum class VideoDecodeBitsKHR : std::int32_t {};
using VideoDecodeFlagsKHR = impl_Enum::Flags<VideoDecodeBitsKHR>;
enum class VideoDecodeH264PictureLayoutBitsKHR : std::int32_t {
	Progressive                = 0x00000000,
	InterlacedInterleavedLines = 0x00000001,
	InterlacedSeparatePlanes   = 0x00000002,
	AllBits                    = 0x00000003, // generated for ~(not), error checking and for convenience
};
using VideoDecodeH264PictureLayoutFlagsKHR = impl_Enum::Flags<VideoDecodeH264PictureLayoutBitsKHR>;
enum class VideoDecodeUsageBitsKHR : std::int32_t {
	Default     = 0x00000000,
	Transcoding = 0x00000001,
	Offline     = 0x00000002,
	Streaming   = 0x00000004,
	AllBits     = 0x00000007, // generated for ~(not), error checking and for convenience
};
using VideoDecodeUsageFlagsKHR = impl_Enum::Flags<VideoDecodeUsageBitsKHR>;
enum class VideoEncodeAV1CapabilityBitsKHR : std::int32_t {
	PerRateControlGroupMinMaxQIndex = 0x00000001,
	GenerateObuExtensionHeader      = 0x00000002,
	PrimaryReferenceCdfOnly         = 0x00000004,
	FrameSizeOverride               = 0x00000008,
	MotionVectorScaling             = 0x00000010,
	CompoundPredictionIntraRefresh  = 0x00000020,
	AllBits                         = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeAV1CapabilityFlagsKHR = impl_Enum::Flags<VideoEncodeAV1CapabilityBitsKHR>;
enum class VideoEncodeAV1PredictionModeKHR : std::int32_t {
	IntraOnly              =          0,
	SingleReference        =          1,
	UnidirectionalCompound =          2,
	BidirectionalCompound  =          3,
};
enum class VideoEncodeAV1RateControlBitsKHR : std::int32_t {
	RegularGop                 = 0x00000001,
	TemporalLayerPatternDyadic = 0x00000002,
	ReferencePatternFlat       = 0x00000004,
	ReferencePatternDyadic     = 0x00000008,
	AllBits                    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeAV1RateControlFlagsKHR = impl_Enum::Flags<VideoEncodeAV1RateControlBitsKHR>;
enum class VideoEncodeAV1RateControlGroupKHR : std::int32_t {
	Intra        =          0,
	Predictive   =          1,
	Bipredictive =          2,
};
enum class VideoEncodeAV1StdBitsKHR : std::int32_t {
	UniformTileSpacingFlagSet = 0x00000001,
	SkipModePresentUnset      = 0x00000002,
	PrimaryRefFrame           = 0x00000004,
	DeltaQ                    = 0x00000008,
	AllBits                   = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeAV1StdFlagsKHR = impl_Enum::Flags<VideoEncodeAV1StdBitsKHR>;
enum class VideoEncodeAV1SuperblockSizeBitsKHR : std::int32_t {
	v64     = 0x00000001,
	v128    = 0x00000002,
	AllBits = 0x00000003, // generated for ~(not), error checking and for convenience
};
using VideoEncodeAV1SuperblockSizeFlagsKHR = impl_Enum::Flags<VideoEncodeAV1SuperblockSizeBitsKHR>;
enum class VideoEncodeCapabilityBitsKHR : std::int32_t {
	PrecedingExternallyEncodedBytes           = 0x00000001,
	InsufficientBitstreamBufferRangeDetection = 0x00000002,
	QuantizationDeltaMap                      = 0x00000004,
	EmphasisMap                               = 0x00000008,
	AllBits                                   = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeCapabilityFlagsKHR = impl_Enum::Flags<VideoEncodeCapabilityBitsKHR>;
enum class VideoEncodeContentBitsKHR : std::int32_t {
	Default  = 0x00000000,
	Camera   = 0x00000001,
	Desktop  = 0x00000002,
	Rendered = 0x00000004,
	AllBits  = 0x00000007, // generated for ~(not), error checking and for convenience
};
using VideoEncodeContentFlagsKHR = impl_Enum::Flags<VideoEncodeContentBitsKHR>;
enum class VideoEncodeFeedbackBitsKHR : std::int32_t {
	BitstreamBufferOffset = 0x00000001,
	BitstreamBytesWritten = 0x00000002,
	BitstreamHasOverrides = 0x00000004,
	AverageQuantization   = 0x00000008,
	MinQuantization       = 0x00000010,
	MaxQuantization       = 0x00000020,
	IntraPixels           = 0x00000040,
	InterPixels           = 0x00000080,
	SkippedPixels         = 0x00000100,
	PicturePartitionCount = 0x00000200,
	AllBits               = 0x000003ff, // generated for ~(not), error checking and for convenience
};
using VideoEncodeFeedbackFlagsKHR = impl_Enum::Flags<VideoEncodeFeedbackBitsKHR>;
enum class VideoEncodeBitsKHR : std::int32_t {
	WithQuantizationDeltaMap = 0x00000001,
	WithEmphasisMap          = 0x00000002,
	IntraRefresh             = 0x00000004,
	AllBits                  = 0x00000007, // generated for ~(not), error checking and for convenience
};
using VideoEncodeFlagsKHR = impl_Enum::Flags<VideoEncodeBitsKHR>;
enum class VideoEncodeH264CapabilityBitsKHR : std::int32_t {
	HrdCompliance                  = 0x00000001,
	PredictionWeightTableGenerated = 0x00000002,
	RowUnalignedSlice              = 0x00000004,
	DifferentSliceType             = 0x00000008,
	BFrameInL0List                 = 0x00000010,
	BFrameInL1List                 = 0x00000020,
	PerPictureTypeMinMaxQp         = 0x00000040,
	PerSliceConstantQp             = 0x00000080,
	GeneratePrefixNalu             = 0x00000100,
	MbQpDiffWraparound             = 0x00000200,
	BPictureIntraRefresh           = 0x00000400,
	AllBits                        = 0x000007ff, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH264CapabilityFlagsKHR = impl_Enum::Flags<VideoEncodeH264CapabilityBitsKHR>;
enum class VideoEncodeH264RateControlBitsKHR : std::int32_t {
	AttemptHrdCompliance       = 0x00000001,
	RegularGop                 = 0x00000002,
	ReferencePatternFlat       = 0x00000004,
	ReferencePatternDyadic     = 0x00000008,
	TemporalLayerPatternDyadic = 0x00000010,
	AllBits                    = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH264RateControlFlagsKHR = impl_Enum::Flags<VideoEncodeH264RateControlBitsKHR>;
enum class VideoEncodeH264StdBitsKHR : std::int32_t {
	SeparateColorPlaneFlagSet          = 0x00000001,
	QpprimeYZeroTransformBypassFlagSet = 0x00000002,
	ScalingMatrixPresentFlagSet        = 0x00000004,
	ChromaQpIndexOffset                = 0x00000008,
	SecondChromaQpIndexOffset          = 0x00000010,
	PicInitQpMinus26                   = 0x00000020,
	WeightedPredFlagSet                = 0x00000040,
	WeightedBipredIdcExplicit          = 0x00000080,
	WeightedBipredIdcImplicit          = 0x00000100,
	Transform8x8ModeFlagSet            = 0x00000200,
	DirectSpatialMvPredFlagUnset       = 0x00000400,
	EntropyCodingModeFlagUnset         = 0x00000800,
	EntropyCodingModeFlagSet           = 0x00001000,
	Direct8x8InferenceFlagUnset        = 0x00002000,
	ConstrainedIntraPredFlagSet        = 0x00004000,
	DeblockingFilterDisabled           = 0x00008000,
	DeblockingFilterEnabled            = 0x00010000,
	DeblockingFilterPartial            = 0x00020000,
	SliceQpDelta                       = 0x00080000,
	DifferentSliceQpDelta              = 0x00100000,
	AllBits                            = 0x001bffff, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH264StdFlagsKHR = impl_Enum::Flags<VideoEncodeH264StdBitsKHR>;
enum class VideoEncodeH265CapabilityBitsKHR : std::int32_t {
	HrdCompliance                  = 0x00000001,
	PredictionWeightTableGenerated = 0x00000002,
	RowUnalignedSliceSegment       = 0x00000004,
	DifferentSliceSegmentType      = 0x00000008,
	BFrameInL0List                 = 0x00000010,
	BFrameInL1List                 = 0x00000020,
	PerPictureTypeMinMaxQp         = 0x00000040,
	PerSliceSegmentConstantQp      = 0x00000080,
	MultipleTilesPerSliceSegment   = 0x00000100,
	MultipleSliceSegmentsPerTile   = 0x00000200,
	CuQpDiffWraparound             = 0x00000400,
	BPictureIntraRefresh           = 0x00000800,
	AllBits                        = 0x00000fff, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH265CapabilityFlagsKHR = impl_Enum::Flags<VideoEncodeH265CapabilityBitsKHR>;
enum class VideoEncodeH265CtbSizeBitsKHR : std::int32_t {
	v16     = 0x00000001,
	v32     = 0x00000002,
	v64     = 0x00000004,
	AllBits = 0x00000007, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH265CtbSizeFlagsKHR = impl_Enum::Flags<VideoEncodeH265CtbSizeBitsKHR>;
enum class VideoEncodeH265RateControlBitsKHR : std::int32_t {
	AttemptHrdCompliance          = 0x00000001,
	RegularGop                    = 0x00000002,
	ReferencePatternFlat          = 0x00000004,
	ReferencePatternDyadic        = 0x00000008,
	TemporalSubLayerPatternDyadic = 0x00000010,
	AllBits                       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH265RateControlFlagsKHR = impl_Enum::Flags<VideoEncodeH265RateControlBitsKHR>;
enum class VideoEncodeH265StdBitsKHR : std::int32_t {
	SeparateColorPlaneFlagSet              = 0x00000001,
	SampleAdaptiveOffsetEnabledFlagSet     = 0x00000002,
	ScalingListDataPresentFlagSet          = 0x00000004,
	PcmEnabledFlagSet                      = 0x00000008,
	SpsTemporalMvpEnabledFlagSet           = 0x00000010,
	InitQpMinus26                          = 0x00000020,
	WeightedPredFlagSet                    = 0x00000040,
	WeightedBipredFlagSet                  = 0x00000080,
	Log2ParallelMergeLevelMinus2           = 0x00000100,
	SignDataHidingEnabledFlagSet           = 0x00000200,
	TransformSkipEnabledFlagSet            = 0x00000400,
	TransformSkipEnabledFlagUnset          = 0x00000800,
	PpsSliceChromaQpOffsetsPresentFlagSet  = 0x00001000,
	TransquantBypassEnabledFlagSet         = 0x00002000,
	ConstrainedIntraPredFlagSet            = 0x00004000,
	EntropyCodingSyncEnabledFlagSet        = 0x00008000,
	DeblockingFilterOverrideEnabledFlagSet = 0x00010000,
	DependentSliceSegmentsEnabledFlagSet   = 0x00020000,
	DependentSliceSegmentFlagSet           = 0x00040000,
	SliceQpDelta                           = 0x00080000,
	DifferentSliceQpDelta                  = 0x00100000,
	AllBits                                = 0x001fffff, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH265StdFlagsKHR = impl_Enum::Flags<VideoEncodeH265StdBitsKHR>;
enum class VideoEncodeH265TransformBlockSizeBitsKHR : std::int32_t {
	v4      = 0x00000001,
	v8      = 0x00000002,
	v16     = 0x00000004,
	v32     = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeH265TransformBlockSizeFlagsKHR = impl_Enum::Flags<VideoEncodeH265TransformBlockSizeBitsKHR>;
enum class VideoEncodeIntraRefreshModeBitsKHR : std::int32_t {
	None                = 0x00000000,
	PerPicturePartition = 0x00000001,
	BlockBased          = 0x00000002,
	BlockRowBased       = 0x00000004,
	BlockColumnBased    = 0x00000008,
	AllBits             = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeIntraRefreshModeFlagsKHR = impl_Enum::Flags<VideoEncodeIntraRefreshModeBitsKHR>;
enum class VideoEncodePerPartitionFeedbackBitsKHR : std::int32_t {
	Status                = 0x00000001,
	BitstreamBufferOffset = 0x00000002,
	BitstreamBytesWritten = 0x00000004,
	AllBits               = 0x00000007, // generated for ~(not), error checking and for convenience
};
using VideoEncodePerPartitionFeedbackFlagsKHR = impl_Enum::Flags<VideoEncodePerPartitionFeedbackBitsKHR>;
enum class VideoEncodeRateControlBitsKHR : std::int32_t {};
using VideoEncodeRateControlFlagsKHR = impl_Enum::Flags<VideoEncodeRateControlBitsKHR>;
enum class VideoEncodeRateControlModeBitsKHR : std::int32_t {
	Default  = 0x00000000,
	Disabled = 0x00000001,
	Cbr      = 0x00000002,
	Vbr      = 0x00000004,
	AllBits  = 0x00000007, // generated for ~(not), error checking and for convenience
};
using VideoEncodeRateControlModeFlagsKHR = impl_Enum::Flags<VideoEncodeRateControlModeBitsKHR>;
enum class VideoEncodeRgbChromaOffsetBitsVALVE : std::int32_t {
	CositedEven = 0x00000001,
	Midpoint    = 0x00000002,
	AllBits     = 0x00000003, // generated for ~(not), error checking and for convenience
};
using VideoEncodeRgbChromaOffsetFlagsVALVE = impl_Enum::Flags<VideoEncodeRgbChromaOffsetBitsVALVE>;
enum class VideoEncodeRgbModelConversionBitsVALVE : std::int32_t {
	RgbIdentity   = 0x00000001,
	YcbcrIdentity = 0x00000002,
	Ycbcr709      = 0x00000004,
	Ycbcr601      = 0x00000008,
	Ycbcr2020     = 0x00000010,
	AllBits       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeRgbModelConversionFlagsVALVE = impl_Enum::Flags<VideoEncodeRgbModelConversionBitsVALVE>;
enum class VideoEncodeRgbRangeCompressionBitsVALVE : std::int32_t {
	FullRange   = 0x00000001,
	NarrowRange = 0x00000002,
	AllBits     = 0x00000003, // generated for ~(not), error checking and for convenience
};
using VideoEncodeRgbRangeCompressionFlagsVALVE = impl_Enum::Flags<VideoEncodeRgbRangeCompressionBitsVALVE>;
enum class VideoEncodeTuningModeKHR : std::int32_t {
	Default         =          0,
	HighQuality     =          1,
	LowLatency      =          2,
	UltraLowLatency =          3,
	Lossless        =          4,
};
enum class VideoEncodeUsageBitsKHR : std::int32_t {
	Default      = 0x00000000,
	Transcoding  = 0x00000001,
	Streaming    = 0x00000002,
	Recording    = 0x00000004,
	Conferencing = 0x00000008,
	AllBits      = 0x0000000f, // generated for ~(not), error checking and for convenience
};
using VideoEncodeUsageFlagsKHR = impl_Enum::Flags<VideoEncodeUsageBitsKHR>;
enum class VideoEndCodingBitsKHR : std::int32_t {};
using VideoEndCodingFlagsKHR = impl_Enum::Flags<VideoEndCodingBitsKHR>;
enum class VideoSessionCreateBitsKHR : std::int32_t {
	ProtectedContent                  = 0x00000001,
	AllowEncodeParameterOptimizations = 0x00000002,
	InlineQueries                     = 0x00000004,
	AllowEncodeQuantizationDeltaMap   = 0x00000008,
	AllowEncodeEmphasisMap            = 0x00000010,
	InlineSessionParameters           = 0x00000020,
	AllBits                           = 0x0000003f, // generated for ~(not), error checking and for convenience
};
using VideoSessionCreateFlagsKHR = impl_Enum::Flags<VideoSessionCreateBitsKHR>;
enum class VideoSessionParametersCreateBitsKHR : std::int32_t {
	QuantizationMapCompatible = 0x00000001,
	AllBits                   = 0x00000001, // generated for ~(not), error checking and for convenience
};
using VideoSessionParametersCreateFlagsKHR = impl_Enum::Flags<VideoSessionParametersCreateBitsKHR>;
enum class ViewportCoordinateSwizzleNV : std::int32_t {
	Positivex =          0,
	Negativex =          1,
	PositiveY =          2,
	NegativeY =          3,
	PositiveZ =          4,
	NegativeZ =          5,
	PositiveW =          6,
	NegativeW =          7,
};
enum class WaylandSurfaceCreateBitsKHR : std::int32_t {};
using WaylandSurfaceCreateFlagsKHR = impl_Enum::Flags<WaylandSurfaceCreateBitsKHR>;
enum class Win32SurfaceCreateBitsKHR : std::int32_t {};
using Win32SurfaceCreateFlagsKHR = impl_Enum::Flags<Win32SurfaceCreateBitsKHR>;
enum class XcbSurfaceCreateBitsKHR : std::int32_t {};
using XcbSurfaceCreateFlagsKHR = impl_Enum::Flags<XcbSurfaceCreateBitsKHR>;
enum class XlibSurfaceCreateBitsKHR : std::int32_t {};
using XlibSurfaceCreateFlagsKHR = impl_Enum::Flags<XlibSurfaceCreateBitsKHR>;
enum class StdVideoAV1ChromaSamplePosition : std::int32_t {
	Unknown   =          0,
	Vertical  =          1,
	Colocated =          2,
	Reserved  =          3,
	Invalid   = 2147483647,
};
enum class StdVideoAV1ColorPrimaries : std::int32_t {
	Bt709       =          1,
	Unspecified =          2,
	Bt470M      =          4,
	Bt470BG     =          5,
	Bt601       =          6,
	Smpte240    =          7,
	GenericFilm =          8,
	Bt2020      =          9,
	Xyz         =         10,
	Smpte431    =         11,
	Smpte432    =         12,
	Ebu3213     =         22,
	Invalid     = 2147483647,
};
enum class StdVideoAV1FrameRestorationType : std::int32_t {
	None       =          0,
	Wiener     =          1,
	Sgrproj    =          2,
	Switchable =          3,
	Invalid    = 2147483647,
};
enum class StdVideoAV1FrameType : std::int32_t {
	Key       =          0,
	Inter     =          1,
	IntraOnly =          2,
	Switch    =          3,
	Invalid   = 2147483647,
};
enum class StdVideoAV1InterpolationFilter : std::int32_t {
	Eighttap       =          0,
	EighttapSmooth =          1,
	EighttapSharp  =          2,
	Bilinear       =          3,
	Switchable     =          4,
	Invalid        = 2147483647,
};
enum class StdVideoAV1Level : std::int32_t {
	v20     =          0,
	v21     =          1,
	v22     =          2,
	v23     =          3,
	v30     =          4,
	v31     =          5,
	v32     =          6,
	v33     =          7,
	v40     =          8,
	v41     =          9,
	v42     =         10,
	v43     =         11,
	v50     =         12,
	v51     =         13,
	v52     =         14,
	v53     =         15,
	v60     =         16,
	v61     =         17,
	v62     =         18,
	v63     =         19,
	v70     =         20,
	v71     =         21,
	v72     =         22,
	v73     =         23,
	Invalid = 2147483647,
};
enum class StdVideoAV1MatrixCoefficients : std::int32_t {
	Identity    =          0,
	Bt709       =          1,
	Unspecified =          2,
	Reserved3   =          3,
	Fcc         =          4,
	Bt470BG     =          5,
	Bt601       =          6,
	Smpte240    =          7,
	SmpteYcgco  =          8,
	Bt2020Ncl   =          9,
	Bt2020Cl    =         10,
	Smpte2085   =         11,
	ChromatNcl  =         12,
	ChromatCl   =         13,
	Ictcp       =         14,
	Invalid     = 2147483647,
};
enum class StdVideoAV1Profile : std::int32_t {
	Main         =          0,
	High         =          1,
	Professional =          2,
	Invalid      = 2147483647,
};
enum class StdVideoAV1ReferenceName : std::int32_t {
	IntraFrame   =          0,
	LastFrame    =          1,
	Last2Frame   =          2,
	Last3Frame   =          3,
	GoldenFrame  =          4,
	BwdrefFrame  =          5,
	Altref2Frame =          6,
	AltrefFrame  =          7,
	Invalid      = 2147483647,
};
enum class StdVideoAV1TransferCharacteristics : std::int32_t {
	Reserved0    =          0,
	Bt709        =          1,
	Unspecified  =          2,
	Reserved3    =          3,
	Bt470M       =          4,
	Bt470BG      =          5,
	Bt601        =          6,
	Smpte240     =          7,
	Linear       =          8,
	Log100       =          9,
	Log100Sqrt10 =         10,
	Iec61966     =         11,
	Bt1361       =         12,
	Srgb         =         13,
	Bt202010Bit  =         14,
	Bt202012Bit  =         15,
	Smpte2084    =         16,
	Smpte428     =         17,
	Hlg          =         18,
	Invalid      = 2147483647,
};
enum class StdVideoAV1TxMode : std::int32_t {
	Only4x4 =          0,
	Largest =          1,
	Select  =          2,
	Invalid = 2147483647,
};
enum class StdVideoDecodeH264FieldOrderCount : std::int32_t {
	Top     =          0,
	Bottom  =          1,
	Invalid = 2147483647,
};
enum class StdVideoH264AspectRatioIdc : std::int32_t {
	Unspecified =          0,
	Square      =          1,
	v1211       =          2,
	v1011       =          3,
	v1611       =          4,
	v4033       =          5,
	v2411       =          6,
	v2011       =          7,
	v3211       =          8,
	v8033       =          9,
	v1811       =         10,
	v1511       =         11,
	v6433       =         12,
	v16099      =         13,
	v43         =         14,
	v32         =         15,
	v21         =         16,
	ExtendedSar =        255,
	Invalid     = 2147483647,
};
enum class StdVideoH264CabacInitIdc : std::int32_t {
	v0      =          0,
	v1      =          1,
	v2      =          2,
	Invalid = 2147483647,
};
enum class StdVideoH264ChromaFormatIdc : std::int32_t {
	Monochrome =          0,
	v420       =          1,
	v422       =          2,
	v444       =          3,
	Invalid    = 2147483647,
};
enum class StdVideoH264DisableDeblockingFilterIdc : std::int32_t {
	Disabled =          0,
	Enabled  =          1,
	Partial  =          2,
	Invalid  = 2147483647,
};
enum class StdVideoH264LevelIdc : std::int32_t {
	v10     =          0,
	v11     =          1,
	v12     =          2,
	v13     =          3,
	v20     =          4,
	v21     =          5,
	v22     =          6,
	v30     =          7,
	v31     =          8,
	v32     =          9,
	v40     =         10,
	v41     =         11,
	v42     =         12,
	v50     =         13,
	v51     =         14,
	v52     =         15,
	v60     =         16,
	v61     =         17,
	v62     =         18,
	Invalid = 2147483647,
};
enum class StdVideoH264MemMgmtControlOp : std::int32_t {
	End                   =          0,
	UnmarkShortTerm       =          1,
	UnmarkLongTerm        =          2,
	MarkLongTerm          =          3,
	SetMaxLongTermIndex   =          4,
	UnmarkAll             =          5,
	MarkCurrentAsLongTerm =          6,
	Invalid               = 2147483647,
};
enum class StdVideoH264ModificationOfPicNumsIdc : std::int32_t {
	ShortTermSubtract =          0,
	ShortTermAdd      =          1,
	LongTerm          =          2,
	End               =          3,
	Invalid           = 2147483647,
};
enum class StdVideoH264NonVclNaluType : std::int32_t {
	Sps           =          0,
	Pps           =          1,
	Aud           =          2,
	Prefix        =          3,
	EndOfSequence =          4,
	EndOfStream   =          5,
	Precoded      =          6,
	Invalid       = 2147483647,
};
enum class StdVideoH264PictureType : std::int32_t {
	P       =          0,
	B       =          1,
	I       =          2,
	Idr     =          5,
	Invalid = 2147483647,
};
enum class StdVideoH264PocType : std::int32_t {
	v0      =          0,
	v1      =          1,
	v2      =          2,
	Invalid = 2147483647,
};
enum class StdVideoH264ProfileIdc : std::int32_t {
	Baseline          =         66, // Only constrained baseline is supported
	Main              =         77,
	High              =        100,
	High10            =        110, // Annex A.2.5 High 10 profile (profile_idc 100 or 110)
	High422           =        122, // Annex A.2.6 High 4:2:2 profile (profile_idc 100, 110, or 122)
	High444Predictive =        244,
	Invalid           = 2147483647,
};
enum class StdVideoH264SliceType : std::int32_t {
	P       =          0,
	B       =          1,
	I       =          2,
	Invalid = 2147483647,
};
enum class StdVideoH264WeightedBipredIdc : std::int32_t {
	Default  =          0,
	Explicit =          1,
	Implicit =          2,
	Invalid  = 2147483647,
};
enum class StdVideoH265AspectRatioIdc : std::int32_t {
	Unspecified =          0,
	Square      =          1,
	v1211       =          2,
	v1011       =          3,
	v1611       =          4,
	v4033       =          5,
	v2411       =          6,
	v2011       =          7,
	v3211       =          8,
	v8033       =          9,
	v1811       =         10,
	v1511       =         11,
	v6433       =         12,
	v16099      =         13,
	v43         =         14,
	v32         =         15,
	v21         =         16,
	ExtendedSar =        255,
	Invalid     = 2147483647,
};
enum class StdVideoH265ChromaFormatIdc : std::int32_t {
	Monochrome =          0,
	v420       =          1,
	v422       =          2,
	v444       =          3,
	Invalid    = 2147483647,
};
enum class StdVideoH265LevelIdc : std::int32_t {
	v10     =          0,
	v20     =          1,
	v21     =          2,
	v30     =          3,
	v31     =          4,
	v40     =          5,
	v41     =          6,
	v50     =          7,
	v51     =          8,
	v52     =          9,
	v60     =         10,
	v61     =         11,
	v62     =         12,
	Invalid = 2147483647,
};
enum class StdVideoH265PictureType : std::int32_t {
	P       =          0,
	B       =          1,
	I       =          2,
	Idr     =          3,
	Invalid = 2147483647,
};
enum class StdVideoH265ProfileIdc : std::int32_t {
	Main                  =          1,
	Main10                =          2,
	MainStillPicture      =          3,
	FormatRangeExtensions =          4,
	SccExtensions         =          9,
	Invalid               = 2147483647,
};
enum class StdVideoH265SliceType : std::int32_t {
	B       =          0,
	P       =          1,
	I       =          2,
	Invalid = 2147483647,
};
enum class StdVideoVP9ColorSpace : std::int32_t {
	StdVideoVp9ColorSpaceUnknown  =          0,
	StdVideoVp9ColorSpaceBt601    =          1,
	StdVideoVp9ColorSpaceBt709    =          2,
	StdVideoVp9ColorSpaceSmpte170 =          3,
	StdVideoVp9ColorSpaceSmpte240 =          4,
	StdVideoVp9ColorSpaceBt2020   =          5,
	StdVideoVp9ColorSpaceReserved =          6,
	StdVideoVp9ColorSpaceRgb      =          7,
	StdVideoVp9ColorSpaceInvalid  = 2147483647,
};
enum class StdVideoVP9FrameType : std::int32_t {
	StdVideoVp9FrameTypeKey     =          0,
	StdVideoVp9FrameTypeNonKey  =          1,
	StdVideoVp9FrameTypeInvalid = 2147483647,
};
enum class StdVideoVP9InterpolationFilter : std::int32_t {
	StdVideoVp9InterpolationFilterEighttap       =          0,
	StdVideoVp9InterpolationFilterEighttapSmooth =          1,
	StdVideoVp9InterpolationFilterEighttapSharp  =          2,
	StdVideoVp9InterpolationFilterBilinear       =          3,
	StdVideoVp9InterpolationFilterSwitchable     =          4,
	StdVideoVp9InterpolationFilterInvalid        = 2147483647,
};
enum class StdVideoVP9Level : std::int32_t {
	StdVideoVp9Level10      =          0,
	StdVideoVp9Level11      =          1,
	StdVideoVp9Level20      =          2,
	StdVideoVp9Level21      =          3,
	StdVideoVp9Level30      =          4,
	StdVideoVp9Level31      =          5,
	StdVideoVp9Level40      =          6,
	StdVideoVp9Level41      =          7,
	StdVideoVp9Level50      =          8,
	StdVideoVp9Level51      =          9,
	StdVideoVp9Level52      =         10,
	StdVideoVp9Level60      =         11,
	StdVideoVp9Level61      =         12,
	StdVideoVp9Level62      =         13,
	StdVideoVp9LevelInvalid = 2147483647,
};
enum class StdVideoVP9Profile : std::int32_t {
	StdVideoVp9Profile0       =          0,
	StdVideoVp9Profile1       =          1,
	StdVideoVp9Profile2       =          2,
	StdVideoVp9Profile3       =          3,
	StdVideoVp9ProfileInvalid = 2147483647,
};
enum class StdVideoVP9ReferenceName : std::int32_t {
	StdVideoVp9ReferenceNameIntraFrame  =          0,
	StdVideoVp9ReferenceNameLastFrame   =          1,
	StdVideoVp9ReferenceNameGoldenFrame =          2,
	StdVideoVp9ReferenceNameAltrefFrame =          3,
	StdVideoVp9ReferenceNameInvalid     = 2147483647,
};
// NOLINTEND(performance-enum-size)
} // namespace VkBindings
