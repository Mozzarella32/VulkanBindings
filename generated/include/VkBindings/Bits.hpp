#pragma once

#include <cstdint>

namespace VkBindings {
// NOLINTBEGIN(performance-enum-size)
enum class AccelerationStructureCreateBitsKHR : std::int32_t {
	DeviceAddressCaptureReplay          = 0x00000001,
	MotionBitNV                         = 0x00000004,
	DescriptorBufferCaptureReplayBitEXT = 0x00000008,
	AllBits                             = 0x0000000d, // generated for ~(not), error checking and for convenience
};
enum class AccelerationStructureMotionInfoBitsNV : std::int32_t {};
enum class AccelerationStructureMotionInstanceBitsNV : std::int32_t {};
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
enum class AccessBits3KHR : std::uint64_t {
	None = 0x0000000000000000,
};
enum class AcquireProfilingLockBitsKHR : std::int32_t {};
enum class AddressCommandBitsKHR : std::int32_t {
	Protected                           = 0x00000001,
	FullyBound                          = 0x00000002,
	StorageBufferUsage                  = 0x00000004,
	UnknownStorageBufferUsage           = 0x00000008,
	TransformFeedbackBufferUsage        = 0x00000010,
	UnknownTransformFeedbackBufferUsage = 0x00000020,
	AllBits                             = 0x0000003f, // generated for ~(not), error checking and for convenience
};
enum class AddressCopyBitsKHR : std::int32_t {
	DeviceLocal = 0x00000001,
	Sparse      = 0x00000002,
	Protected   = 0x00000004,
	AllBits     = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class AndroidSurfaceCreateBitsKHR : std::int32_t {};
enum class AttachmentDescriptionBits : std::int32_t {
	MayAlias                            = 0x00000001, // The attachment may alias physical memory of another attachment in the same render pass
	ResolveSkipTransferFunctionBitKHR   = 0x00000002,
	ResolveEnableTransferFunctionBitKHR = 0x00000004,
	AllBits                             = 0x00000007, // generated for ~(not), error checking and for convenience
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
enum class BufferViewCreateBits : std::int32_t {};
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
enum class BuildMicromapBitsEXT : std::int32_t {
	PreferFastTrace = 0x00000001,
	PreferFastBuild = 0x00000002,
	AllowCompaction = 0x00000004,
	AllBits         = 0x00000007, // generated for ~(not), error checking and for convenience
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
enum class ClusterAccelerationStructureClusterBitsNV : std::int32_t {
	AllowDisableOpacityMicromaps = 0x00000001,
	AllBits                      = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class ClusterAccelerationStructureGeometryBitsNV : std::int32_t {
	CullDisable                 = 0x00000001,
	NoDuplicateAnyhitInvocation = 0x00000002,
	Opaque                      = 0x00000004,
	AllBits                     = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class ClusterAccelerationStructureIndexFormatBitsNV : std::int32_t {
	v8      = 0x00000001,
	v16     = 0x00000002,
	v32     = 0x00000004,
	AllBits = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class ColorComponentBits : std::int32_t {
	R       = 0x00000001,
	G       = 0x00000002,
	B       = 0x00000004,
	A       = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class CommandBufferResetBits : std::int32_t {
	ReleaseResources = 0x00000001, // Release resources owned by the buffer
	AllBits          = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class CommandBufferUsageBits : std::int32_t {
	OneTimeSubmit      = 0x00000001,
	RenderPassContinue = 0x00000002,
	SimultaneousUse    = 0x00000004, // Command buffer may be submitted/executed more than once simultaneously
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class CommandPoolCreateBits : std::int32_t {
	Transient          = 0x00000001, // Command buffers have a short lifetime
	ResetCommandBuffer = 0x00000002, // Command buffers may release their memory individually
	Protected          = 0x00000004, // Command buffers allocated from pool are protected command buffers
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class CommandPoolResetBits : std::int32_t {
	ReleaseResources = 0x00000001, // Release resources owned by the pool
	AllBits          = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class CommandPoolTrimBits : std::int32_t {};
enum class CompositeAlphaBitsKHR : std::int32_t {
	Opaque         = 0x00000001,
	PreMultiplied  = 0x00000002,
	PostMultiplied = 0x00000004,
	Inherit        = 0x00000008,
	AllBits        = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class ConditionalRenderingBitsEXT : std::int32_t {
	Inverted = 0x00000001,
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class CooperativeMatrixBitsEXT : std::int32_t {
	SaturatingAccumulation = 0x00000001,
	AllBits                = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class CullModeBits : std::int32_t {
	None         = 0x00000000,
	Front        = 0x00000001,
	Back         = 0x00000002,
	FrontAndBack = 0x00000003,
	AllBits      = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class DataGraphOpticalFlowCreateBitsARM : std::int32_t {
	EnableHint = 0x00000001,
	EnableCost = 0x00000002,
	Reserved30 = 0x40000000,
	AllBits    = 0x40000003, // generated for ~(not), error checking and for convenience
};
enum class DataGraphOpticalFlowExecuteBitsARM : std::int32_t {
	DisableTemporalHints     = 0x00000001,
	InputUnchanged           = 0x00000002,
	ReferenceUnchanged       = 0x00000004,
	InputIsPreviousReference = 0x00000008,
	ReferenceIsPreviousInput = 0x00000010,
	AllBits                  = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class DataGraphOpticalFlowGridSizeBitsARM : std::int32_t {
	Unknown = 0x00000000,
	v1x1    = 0x00000001,
	v2x2    = 0x00000002,
	v4x4    = 0x00000004,
	v8x8    = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class DataGraphOpticalFlowImageUsageBitsARM : std::int32_t {
	Unknown = 0x00000000,
	Input   = 0x00000001,
	Output  = 0x00000002,
	Hint    = 0x00000004,
	Cost    = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class DataGraphPipelineDispatchBitsARM : std::uint64_t {};
enum class DataGraphPipelineSessionCreateBitsARM : std::uint64_t {
	Protected        = 0x0000000000000001,
	OpticalFlowCache = 0x0000000000000002,
	AllBits          = 0x0000000000000003, // generated for ~(not), error checking and for convenience
};
enum class DataGraphTOSAQualityBitsARM : std::int32_t {
	DataGraphTosaQualityAccelerated  = 0x00000001,
	DataGraphTosaQualityConformant   = 0x00000002,
	DataGraphTosaQualityExperimental = 0x00000004,
	DataGraphTosaQualityDeprecated   = 0x00000008,
	AllBits                          = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class DebugReportBitsEXT : std::int32_t {
	Information        = 0x00000001,
	Warning            = 0x00000002,
	PerformanceWarning = 0x00000004,
	Error              = 0x00000008,
	Debug              = 0x00000010,
	AllBits            = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class DebugUtilsMessageSeverityBitsEXT : std::int32_t {
	Verbose = 0x00000001,
	Info    = 0x00000010,
	Warning = 0x00000100,
	Error   = 0x00001000,
	AllBits = 0x00001111, // generated for ~(not), error checking and for convenience
};
enum class DebugUtilsMessageTypeBitsEXT : std::int32_t {
	General              = 0x00000001,
	Validation           = 0x00000002,
	Performance          = 0x00000004,
	DeviceAddressBinding = 0x00000008,
	AllBits              = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class DebugUtilsMessengerCallbackDataBitsEXT : std::int32_t {};
enum class DebugUtilsMessengerCreateBitsEXT : std::int32_t {};
enum class DependencyBits : std::int32_t {
	ByRegion                                       = 0x00000001, // Dependency is per pixel region 
	ViewLocal                                      = 0x00000002,
	DeviceGroup                                    = 0x00000004, // Dependency is across devices
	FeedbackLoopBitEXT                             = 0x00000008, // Dependency may be a feedback loop
	QueueFamilyOwnershipTransferUseAllStagesBitKHR = 0x00000020,
	AsymmetricEventBitKHR                          = 0x00000040,
	AllBits                                        = 0x0000006f, // generated for ~(not), error checking and for convenience
};
enum class DescriptorBindingBits : std::int32_t {
	UpdateAfterBind          = 0x00000001,
	UpdateUnusedWhilePending = 0x00000002,
	PartiallyBound           = 0x00000004,
	VariableDescriptorCount  = 0x00000008,
	AllBits                  = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class DescriptorPoolCreateBits : std::int32_t {
	FreeDescriptorSet             = 0x00000001, // Descriptor sets may be freed individually
	UpdateAfterBind               = 0x00000002,
	HostOnlyBitEXT                = 0x00000004,
	AllowOverallocationSetsBitNV  = 0x00000008,
	AllowOverallocationPoolsBitNV = 0x00000010,
	AllBits                       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class DescriptorPoolResetBits : std::int32_t {};
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
enum class DescriptorUpdateTemplateCreateBits : std::int32_t {};
enum class DeviceAddressBindingBitsEXT : std::int32_t {
	InternalObject = 0x00000001,
	AllBits        = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class DeviceCreateBits : std::int32_t {};
enum class DeviceDiagnosticsConfigBitsNV : std::int32_t {
	EnableShaderDebugInfo      = 0x00000001,
	EnableResourceTracking     = 0x00000002,
	EnableAutomaticCheckpoints = 0x00000004,
	EnableShaderErrorReporting = 0x00000008,
	AllBits                    = 0x0000000f, // generated for ~(not), error checking and for convenience
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
enum class DeviceGroupPresentModeBitsKHR : std::int32_t {
	Local            = 0x00000001, // Present from local memory
	Remote           = 0x00000002, // Present from remote memory
	Sum              = 0x00000004, // Present sum of local and/or remote memory
	LocalMultiDevice = 0x00000008, // Each physical device presents from local memory
	AllBits          = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class DeviceMemoryReportBitsEXT : std::int32_t {};
enum class DeviceQueueCreateBits : std::int32_t {
	Protected                    = 0x00000001, // Queue is a protected-capable device queue
	InternallySynchronizedBitKHR = 0x00000004,
	AllBits                      = 0x00000005, // generated for ~(not), error checking and for convenience
};
enum class DirectDriverLoadingBitsLUNARG : std::int32_t {};
enum class DirectFBSurfaceCreateBitsEXT : std::int32_t {};
enum class DisplayModeCreateBitsKHR : std::int32_t {};
enum class DisplayPlaneAlphaBitsKHR : std::int32_t {
	Opaque                = 0x00000001,
	Global                = 0x00000002,
	PerPixel              = 0x00000004,
	PerPixelPremultiplied = 0x00000008,
	AllBits               = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class DisplaySurfaceCreateBitsKHR : std::int32_t {};
enum class EventCreateBits : std::int32_t {
	DeviceOnly = 0x00000001,
	AllBits    = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class ExportMetalObjectTypeBitsEXT : std::int32_t {
	MetalDevice       = 0x00000001,
	MetalCommandQueue = 0x00000002,
	MetalBuffer       = 0x00000004,
	MetalTexture      = 0x00000008,
	MetalIosurface    = 0x00000010,
	MetalSharedEvent  = 0x00000020,
	AllBits           = 0x0000003f, // generated for ~(not), error checking and for convenience
};
enum class ExternalFenceFeatureBits : std::int32_t {
	Exportable = 0x00000001,
	Importable = 0x00000002,
	AllBits    = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class ExternalFenceHandleTypeBits : std::int32_t {
	OpaqueFd       = 0x00000001,
	OpaqueWin32    = 0x00000002,
	OpaqueWin32Kmt = 0x00000004,
	SyncFd         = 0x00000008,
	AllBits        = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class ExternalMemoryFeatureBits : std::int32_t {
	DedicatedOnly = 0x00000001,
	Exportable    = 0x00000002,
	Importable    = 0x00000004,
	AllBits       = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class ExternalMemoryFeatureBitsNV : std::int32_t {
	DedicatedOnly = 0x00000001,
	Exportable    = 0x00000002,
	Importable    = 0x00000004,
	AllBits       = 0x00000007, // generated for ~(not), error checking and for convenience
};
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
enum class ExternalMemoryHandleTypeBitsNV : std::int32_t {
	OpaqueWin32    = 0x00000001,
	OpaqueWin32Kmt = 0x00000002,
	D3D11Image     = 0x00000004,
	D3D11ImageKmt  = 0x00000008,
	AllBits        = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class ExternalSemaphoreFeatureBits : std::int32_t {
	Exportable = 0x00000001,
	Importable = 0x00000002,
	AllBits    = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class ExternalSemaphoreHandleTypeBits : std::int32_t {
	OpaqueFd              = 0x00000001,
	OpaqueWin32           = 0x00000002,
	OpaqueWin32Kmt        = 0x00000004,
	D3D12Fence            = 0x00000008,
	SyncFd                = 0x00000010,
	ZirconEventBitFUCHSIA = 0x00000080,
	AllBits               = 0x0000009f, // generated for ~(not), error checking and for convenience
};
enum class FenceCreateBits : std::int32_t {
	Signaled = 0x00000001,
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class FenceImportBits : std::int32_t {
	Temporary = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
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
enum class FormatFeatureBits4KHR : std::uint64_t {};
enum class FrameBoundaryBitsEXT : std::int32_t {
	FrameEnd = 0x00000001,
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class FramebufferCreateBits : std::int32_t {
	Imageless = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class GeometryBitsKHR : std::int32_t {
	Opaque                      = 0x00000001,
	NoDuplicateAnyHitInvocation = 0x00000002,
	AllBits                     = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class GeometryInstanceBitsKHR : std::int32_t {
	TriangleFacingCullDisable  = 0x00000001,
	TriangleFlipFacing         = 0x00000002,
	ForceOpaque                = 0x00000004,
	ForceNoOpaque              = 0x00000008,
	ForceOpacityMicromap2State = 0x00000010,
	DisableOpacityMicromaps    = 0x00000020,
	AllBits                    = 0x0000003f, // generated for ~(not), error checking and for convenience
};
enum class GpaPerfBlockPropertiesBitsAMD : std::int32_t {};
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
enum class GraphicsPipelineLibraryBitsEXT : std::int32_t {
	VertexInputInterface    = 0x00000001,
	PreRasterizationShaders = 0x00000002,
	FragmentShader          = 0x00000004,
	FragmentOutputInterface = 0x00000008,
	AllBits                 = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class HeadlessSurfaceCreateBitsEXT : std::int32_t {};
enum class HostImageCopyBits : std::int32_t {
	Memcpy  = 0x00000001,
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class IOSSurfaceCreateBitsMVK : std::int32_t {};
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
enum class ImageCompressionBitsEXT : std::int32_t {
	Default           = 0x00000000,
	FixedRateDefault  = 0x00000001,
	FixedRateExplicit = 0x00000002,
	Disabled          = 0x00000004,
	AllBits           = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class ImageConstraintsInfoBitsFUCHSIA : std::int32_t {
	CpuReadRarely     = 0x00000001,
	CpuReadOften      = 0x00000002,
	CpuWriteRarely    = 0x00000004,
	CpuWriteOften     = 0x00000008,
	ProtectedOptional = 0x00000010,
	AllBits           = 0x0000001f, // generated for ~(not), error checking and for convenience
};
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
enum class ImageFormatConstraintsBitsFUCHSIA : std::int32_t {};
enum class ImagePipeSurfaceCreateBitsFUCHSIA : std::int32_t {};
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
enum class ImageViewCreateBits : std::int32_t {
	FragmentDensityMapDynamicBitEXT     = 0x00000001,
	FragmentDensityMapDeferredBitEXT    = 0x00000002,
	DescriptorBufferCaptureReplayBitEXT = 0x00000004,
	AllBits                             = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class IndirectCommandsInputModeBitsEXT : std::int32_t {
	VulkanIndexBuffer = 0x00000001,
	DxgiIndexBuffer   = 0x00000002,
	AllBits           = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class IndirectCommandsLayoutUsageBitsEXT : std::int32_t {
	ExplicitPreprocess = 0x00000001,
	UnorderedSequences = 0x00000002,
	AllBits            = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class IndirectCommandsLayoutUsageBitsNV : std::int32_t {
	ExplicitPreprocess = 0x00000001,
	IndexedSequences   = 0x00000002,
	UnorderedSequences = 0x00000004,
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class IndirectStateBitsNV : std::int32_t {
	FlagFrontface = 0x00000001,
	AllBits       = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class InstanceCreateBits : std::int32_t {
	EnumeratePortabilityBitKHR = 0x00000001,
	AllBits                    = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class MacOSSurfaceCreateBitsMVK : std::int32_t {};
enum class MemoryAllocateBits : std::int32_t {
	DeviceMask                 = 0x00000001, // Force allocation on specific devices
	DeviceAddress              = 0x00000002,
	DeviceAddressCaptureReplay = 0x00000004,
	ZeroInitializeBitEXT       = 0x00000008,
	AllBits                    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class MemoryDecompressionMethodBitsEXT : std::uint64_t {
	Gdeflate10 = 0x0000000000000001,
	AllBits    = 0x0000000000000001, // generated for ~(not), error checking and for convenience
};
enum class MemoryHeapBits : std::int32_t {
	DeviceLocal       = 0x00000001, // If set, heap represents device memory
	MultiInstance     = 0x00000002, // If set, heap allocations allocate multiple instances by default
	TileMemoryBitQCOM = 0x00000008,
	AllBits           = 0x0000000b, // generated for ~(not), error checking and for convenience
};
enum class MemoryMapBits : std::int32_t {
	PlacedBitEXT = 0x00000001,
	AllBits      = 0x00000001, // generated for ~(not), error checking and for convenience
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
enum class MemoryUnmapBits : std::int32_t {
	ReserveBitEXT = 0x00000001,
	AllBits       = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class MetalSurfaceCreateBitsEXT : std::int32_t {};
enum class MicromapCreateBitsEXT : std::int32_t {
	DeviceAddressCaptureReplay = 0x00000001,
	AllBits                    = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class OpticalFlowExecuteBitsNV : std::int32_t {
	DisableTemporalHints = 0x00000001,
	AllBits              = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class OpticalFlowGridSizeBitsNV : std::int32_t {
	Unknown = 0x00000000,
	v1x1    = 0x00000001,
	v2x2    = 0x00000002,
	v4x4    = 0x00000004,
	v8x8    = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class OpticalFlowSessionCreateBitsNV : std::int32_t {
	EnableHint       = 0x00000001,
	EnableCost       = 0x00000002,
	EnableGlobalFlow = 0x00000004,
	AllowRegions     = 0x00000008,
	BothDirections   = 0x00000010,
	AllBits          = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class OpticalFlowUsageBitsNV : std::int32_t {
	Unknown    = 0x00000000,
	Input      = 0x00000001,
	Output     = 0x00000002,
	Hint       = 0x00000004,
	Cost       = 0x00000008,
	GlobalFlow = 0x00000010,
	AllBits    = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class PartitionedAccelerationStructureInstanceBitsNV : std::int32_t {
	FlagTriangleFacingCullDisable = 0x00000001,
	FlagTriangleFlipFacing        = 0x00000002,
	FlagForceOpaque               = 0x00000004,
	FlagForceNoOpaque             = 0x00000008,
	FlagEnableExplicitBoundingBox = 0x00000010,
	AllBits                       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class PastPresentationTimingBitsEXT : std::int32_t {
	AllowPartialResults    = 0x00000001,
	AllowOutOfOrderResults = 0x00000002,
	AllBits                = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class PeerMemoryFeatureBits : std::int32_t {
	CopySrc    = 0x00000001, // Can read with vkCmdCopy commands
	CopyDst    = 0x00000002, // Can write with vkCmdCopy commands
	GenericSrc = 0x00000004, // Can read with any access type/command
	GenericDst = 0x00000008, // Can write with and access type/command
	AllBits    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class PerformanceCounterDescriptionBitsARM : std::int32_t {};
enum class PerformanceCounterDescriptionBitsKHR : std::int32_t {
	PerformanceImpacting = 0x00000001,
	ConcurrentlyImpacted = 0x00000002,
	AllBits              = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class PhysicalDeviceGpaPropertiesBitsAMD : std::int32_t {};
enum class PhysicalDeviceSchedulingControlsBitsARM : std::uint64_t {
	ShaderCoreCount    = 0x0000000000000001,
	DispatchParameters = 0x0000000000000002,
	AllBits            = 0x0000000000000003, // generated for ~(not), error checking and for convenience
};
enum class PipelineCacheCreateBits : std::int32_t {
	ExternallySynchronized            = 0x00000001,
	InternallySynchronizedMergeBitKHR = 0x00000008,
	AllBits                           = 0x00000009, // generated for ~(not), error checking and for convenience
};
enum class PipelineColorBlendStateCreateBits : std::int32_t {
	RasterizationOrderAttachmentAccessBitEXT = 0x00000001,
	AllBits                                  = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class PipelineCompilerControlBitsAMD : std::int32_t {};
enum class PipelineCoverageModulationStateCreateBitsNV : std::int32_t {};
enum class PipelineCoverageReductionStateCreateBitsNV : std::int32_t {};
enum class PipelineCoverageToColorStateCreateBitsNV : std::int32_t {};
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
enum class PipelineCreationFeedbackBits : std::int32_t {
	Valid                       = 0x00000001,
	ApplicationPipelineCacheHit = 0x00000002,
	BasePipelineAcceleration    = 0x00000004,
	AllBits                     = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class PipelineDepthStencilStateCreateBits : std::int32_t {
	RasterizationOrderAttachmentDepthAccessBitEXT   = 0x00000001,
	RasterizationOrderAttachmentStencilAccessBitEXT = 0x00000002,
	AllBits                                         = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class PipelineDiscardRectangleStateCreateBitsEXT : std::int32_t {};
enum class PipelineDynamicStateCreateBits : std::int32_t {};
enum class PipelineInputAssemblyStateCreateBits : std::int32_t {};
enum class PipelineLayoutCreateBits : std::int32_t {
	IndependentSetsBitEXT = 0x00000002,
	NoTaskShaderBitKHR    = 0x00000004,
	AllBits               = 0x00000006, // generated for ~(not), error checking and for convenience
};
enum class PipelineMultisampleStateCreateBits : std::int32_t {};
enum class PipelineRasterizationConservativeStateCreateBitsEXT : std::int32_t {};
enum class PipelineRasterizationDepthClipStateCreateBitsEXT : std::int32_t {};
enum class PipelineRasterizationStateCreateBits : std::int32_t {};
enum class PipelineRasterizationStateStreamCreateBitsEXT : std::int32_t {};
enum class PipelineShaderStageCreateBits : std::int32_t {
	AllowVaryingSubgroupSize = 0x00000001,
	RequireFullSubgroups     = 0x00000002,
	AllBits                  = 0x00000003, // generated for ~(not), error checking and for convenience
};
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
enum class PipelineTessellationStateCreateBits : std::int32_t {};
enum class PipelineVertexInputStateCreateBits : std::int32_t {};
enum class PipelineViewportStateCreateBits : std::int32_t {};
enum class PipelineViewportSwizzleStateCreateBitsNV : std::int32_t {};
enum class PresentGravityBitsKHR : std::int32_t {
	Min      = 0x00000001,
	Max      = 0x00000002,
	Centered = 0x00000004,
	AllBits  = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class PresentScalingBitsKHR : std::int32_t {
	OneToOne           = 0x00000001,
	AspectRatioStretch = 0x00000002,
	Stretch            = 0x00000004,
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class PresentStageBitsEXT : std::int32_t {
	QueueOperationsEnd     = 0x00000001,
	RequestDequeued        = 0x00000002,
	ImageFirstPixelOut     = 0x00000004,
	ImageFirstPixelVisible = 0x00000008,
	AllBits                = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class PresentTimingInfoBitsEXT : std::int32_t {
	PresentAtRelativeTime        = 0x00000001,
	PresentAtNearestRefreshCycle = 0x00000002,
	AllBits                      = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class PrivateDataSlotCreateBits : std::int32_t {
	BaseObjectHandleBitNV = 0x00000001,
	AllBits               = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class QueryControlBits : std::int32_t {
	Precise = 0x00000001, // Require precise results to be collected by the query
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
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
enum class QueryPoolCreateBits : std::int32_t {
	ResetBitKHR = 0x00000001,
	AllBits     = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class QueryResultBits : std::int32_t {
	v64              = 0x00000001, // Results of the queries are written to the destination buffer as 64-bit values
	Wait             = 0x00000002, // Results of the queries are waited on before proceeding with the result copy
	WithAvailability = 0x00000004, // Besides the results of the query, the availability of the results is also written
	Partial          = 0x00000008, // Copy the partial results of the query even if the final results are not available
	WithStatusBitKHR = 0x00000010,
	AllBits          = 0x0000001f, // generated for ~(not), error checking and for convenience
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
enum class RefreshObjectBitsKHR : std::int32_t {};
enum class RenderPassCreateBits : std::int32_t {
	TransformBitQCOM                = 0x00000002,
	PerLayerFragmentDensityBitVALVE = 0x00000004,
	AllBits                         = 0x00000006, // generated for ~(not), error checking and for convenience
};
enum class RenderingAttachmentBitsKHR : std::int32_t {
	InputAttachmentFeedback       = 0x00000001,
	ResolveSkipTransferFunction   = 0x00000002,
	ResolveEnableTransferFunction = 0x00000004,
	AllBits                       = 0x00000007, // generated for ~(not), error checking and for convenience
};
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
enum class ResolveImageBitsKHR : std::int32_t {
	SkipTransferFunction   = 0x00000001,
	EnableTransferFunction = 0x00000002,
	AllBits                = 0x00000003, // generated for ~(not), error checking and for convenience
};
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
enum class SamplerCreateBits : std::int32_t {
	SubsampledBitEXT                     = 0x00000001,
	SubsampledCoarseReconstructionBitEXT = 0x00000002,
	NonSeamlessCubeMapBitEXT             = 0x00000004,
	DescriptorBufferCaptureReplayBitEXT  = 0x00000008,
	ImageProcessingBitQCOM               = 0x00000010,
	AllBits                              = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class ScreenSurfaceCreateBitsQNX : std::int32_t {};
enum class SemaphoreCreateBits : std::int32_t {};
enum class SemaphoreImportBits : std::int32_t {
	Temporary = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class SemaphoreWaitBits : std::int32_t {
	Any     = 0x00000001,
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class ShaderCorePropertiesBitsAMD : std::int32_t {};
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
enum class ShaderInstrumentationValuesBitsARM : std::int32_t {};
enum class ShaderModuleCreateBits : std::int32_t {};
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
enum class SparseImageFormatBits : std::int32_t {
	SingleMiptail        = 0x00000001, // Image uses a single mip tail region for all array layers
	AlignedMipSize       = 0x00000002, // Image requires mip level dimensions to be an integer multiple of the sparse image block dimensions for non-tail mip levels.
	NonstandardBlockSize = 0x00000004, // Image uses a non-standard sparse image block dimensions
	AllBits              = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class SparseMemoryBindBits : std::int32_t {
	Metadata = 0x00000001, // Operation binds resource metadata to memory
	AllBits  = 0x00000001, // generated for ~(not), error checking and for convenience
};
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
enum class StencilFaceBits : std::int32_t {
	Front        = 0x00000001, // Front face
	Back         = 0x00000002, // Back face
	FrontAndBack = 0x00000003, // Front and back faces
	AllBits      = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class StreamDescriptorSurfaceCreateBitsGGP : std::int32_t {};
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
enum class SubmitBits : std::int32_t {
	Protected = 0x00000001,
	AllBits   = 0x00000001, // generated for ~(not), error checking and for convenience
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
enum class SurfaceCounterBitsEXT : std::int32_t {
	Vblank  = 0x00000001,
	AllBits = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class SurfaceCreateBitsOHOS : std::int32_t {};
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
enum class SwapchainImageUsageBitsANDROID : std::int32_t {};
enum class SwapchainImageUsageBitsOHOS : std::int32_t {};
enum class TensorCreateBitsARM : std::uint64_t {
	MutableFormat                 = 0x0000000000000001,
	Protected                     = 0x0000000000000002,
	DescriptorBufferCaptureReplay = 0x0000000000000004,
	DescriptorHeapCaptureReplay   = 0x0000000000000008,
	AllBits                       = 0x000000000000000f, // generated for ~(not), error checking and for convenience
};
enum class TensorUsageBitsARM : std::uint64_t {
	Shader        = 0x0000000000000002, // Tensor written/read through shader descriptor
	TransferSrc   = 0x0000000000000004, // Tensor can be src of a transfer operation
	TransferDst   = 0x0000000000000008, // Tensor can be dst of a transfer operation
	ImageAliasing = 0x0000000000000010, // Tensor can be aliased with an image
	DataGraph     = 0x0000000000000020,
	AllBits       = 0x000000000000003e, // generated for ~(not), error checking and for convenience
};
enum class TensorViewCreateBitsARM : std::uint64_t {
	DescriptorBufferCaptureReplay = 0x0000000000000001,
	AllBits                       = 0x0000000000000001, // generated for ~(not), error checking and for convenience
};
enum class TileShadingRenderPassBitsQCOM : std::int32_t {
	Enable           = 0x00000001,
	PerTileExecution = 0x00000002,
	AllBits          = 0x00000003, // generated for ~(not), error checking and for convenience
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
enum class UbmSurfaceCreateBitsSEC : std::int32_t {};
enum class ValidationCacheCreateBitsEXT : std::int32_t {};
enum class ViSurfaceCreateBitsNN : std::int32_t {};
enum class VideoBeginCodingBitsKHR : std::int32_t {};
enum class VideoCapabilityBitsKHR : std::int32_t {
	ProtectedContent        = 0x00000001,
	SeparateReferenceImages = 0x00000002,
	AllBits                 = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class VideoChromaSubsamplingBitsKHR : std::int32_t {
	Invalid    = 0x00000000,
	Monochrome = 0x00000001,
	v420       = 0x00000002,
	v422       = 0x00000004,
	v444       = 0x00000008,
	AllBits    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
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
enum class VideoCodingControlBitsKHR : std::int32_t {
	Reset              = 0x00000001,
	EncodeRateControl  = 0x00000002,
	EncodeQualityLevel = 0x00000004,
	AllBits            = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class VideoComponentBitDepthBitsKHR : std::int32_t {
	Invalid = 0x00000000,
	v8      = 0x00000001,
	v10     = 0x00000004,
	v12     = 0x00000010,
	AllBits = 0x00000015, // generated for ~(not), error checking and for convenience
};
enum class VideoDecodeCapabilityBitsKHR : std::int32_t {
	DpbAndOutputCoincide = 0x00000001,
	DpbAndOutputDistinct = 0x00000002,
	AllBits              = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class VideoDecodeBitsKHR : std::int32_t {};
enum class VideoDecodeH264PictureLayoutBitsKHR : std::int32_t {
	Progressive                = 0x00000000,
	InterlacedInterleavedLines = 0x00000001,
	InterlacedSeparatePlanes   = 0x00000002,
	AllBits                    = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class VideoDecodeUsageBitsKHR : std::int32_t {
	Default     = 0x00000000,
	Transcoding = 0x00000001,
	Offline     = 0x00000002,
	Streaming   = 0x00000004,
	AllBits     = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeAV1CapabilityBitsKHR : std::int32_t {
	PerRateControlGroupMinMaxQIndex = 0x00000001,
	GenerateObuExtensionHeader      = 0x00000002,
	PrimaryReferenceCdfOnly         = 0x00000004,
	FrameSizeOverride               = 0x00000008,
	MotionVectorScaling             = 0x00000010,
	CompoundPredictionIntraRefresh  = 0x00000020,
	AllBits                         = 0x0000003f, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeAV1RateControlBitsKHR : std::int32_t {
	RegularGop                 = 0x00000001,
	TemporalLayerPatternDyadic = 0x00000002,
	ReferencePatternFlat       = 0x00000004,
	ReferencePatternDyadic     = 0x00000008,
	AllBits                    = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeAV1StdBitsKHR : std::int32_t {
	UniformTileSpacingFlagSet = 0x00000001,
	SkipModePresentUnset      = 0x00000002,
	PrimaryRefFrame           = 0x00000004,
	DeltaQ                    = 0x00000008,
	AllBits                   = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeAV1SuperblockSizeBitsKHR : std::int32_t {
	v64     = 0x00000001,
	v128    = 0x00000002,
	AllBits = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeCapabilityBitsKHR : std::int32_t {
	PrecedingExternallyEncodedBytes           = 0x00000001,
	InsufficientBitstreamBufferRangeDetection = 0x00000002,
	QuantizationDeltaMap                      = 0x00000004,
	EmphasisMap                               = 0x00000008,
	AllBits                                   = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeContentBitsKHR : std::int32_t {
	Default  = 0x00000000,
	Camera   = 0x00000001,
	Desktop  = 0x00000002,
	Rendered = 0x00000004,
	AllBits  = 0x00000007, // generated for ~(not), error checking and for convenience
};
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
enum class VideoEncodeBitsKHR : std::int32_t {
	WithQuantizationDeltaMap = 0x00000001,
	WithEmphasisMap          = 0x00000002,
	IntraRefresh             = 0x00000004,
	AllBits                  = 0x00000007, // generated for ~(not), error checking and for convenience
};
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
enum class VideoEncodeH264RateControlBitsKHR : std::int32_t {
	AttemptHrdCompliance       = 0x00000001,
	RegularGop                 = 0x00000002,
	ReferencePatternFlat       = 0x00000004,
	ReferencePatternDyadic     = 0x00000008,
	TemporalLayerPatternDyadic = 0x00000010,
	AllBits                    = 0x0000001f, // generated for ~(not), error checking and for convenience
};
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
enum class VideoEncodeH265CtbSizeBitsKHR : std::int32_t {
	v16     = 0x00000001,
	v32     = 0x00000002,
	v64     = 0x00000004,
	AllBits = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeH265RateControlBitsKHR : std::int32_t {
	AttemptHrdCompliance          = 0x00000001,
	RegularGop                    = 0x00000002,
	ReferencePatternFlat          = 0x00000004,
	ReferencePatternDyadic        = 0x00000008,
	TemporalSubLayerPatternDyadic = 0x00000010,
	AllBits                       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
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
enum class VideoEncodeH265TransformBlockSizeBitsKHR : std::int32_t {
	v4      = 0x00000001,
	v8      = 0x00000002,
	v16     = 0x00000004,
	v32     = 0x00000008,
	AllBits = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeIntraRefreshModeBitsKHR : std::int32_t {
	None                = 0x00000000,
	PerPicturePartition = 0x00000001,
	BlockBased          = 0x00000002,
	BlockRowBased       = 0x00000004,
	BlockColumnBased    = 0x00000008,
	AllBits             = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodePerPartitionFeedbackBitsKHR : std::int32_t {
	Status                = 0x00000001,
	BitstreamBufferOffset = 0x00000002,
	BitstreamBytesWritten = 0x00000004,
	AllBits               = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeRateControlBitsKHR : std::int32_t {};
enum class VideoEncodeRateControlModeBitsKHR : std::int32_t {
	Default  = 0x00000000,
	Disabled = 0x00000001,
	Cbr      = 0x00000002,
	Vbr      = 0x00000004,
	AllBits  = 0x00000007, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeRgbChromaOffsetBitsVALVE : std::int32_t {
	CositedEven = 0x00000001,
	Midpoint    = 0x00000002,
	AllBits     = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeRgbModelConversionBitsVALVE : std::int32_t {
	RgbIdentity   = 0x00000001,
	YcbcrIdentity = 0x00000002,
	Ycbcr709      = 0x00000004,
	Ycbcr601      = 0x00000008,
	Ycbcr2020     = 0x00000010,
	AllBits       = 0x0000001f, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeRgbRangeCompressionBitsVALVE : std::int32_t {
	FullRange   = 0x00000001,
	NarrowRange = 0x00000002,
	AllBits     = 0x00000003, // generated for ~(not), error checking and for convenience
};
enum class VideoEncodeUsageBitsKHR : std::int32_t {
	Default      = 0x00000000,
	Transcoding  = 0x00000001,
	Streaming    = 0x00000002,
	Recording    = 0x00000004,
	Conferencing = 0x00000008,
	AllBits      = 0x0000000f, // generated for ~(not), error checking and for convenience
};
enum class VideoEndCodingBitsKHR : std::int32_t {};
enum class VideoSessionCreateBitsKHR : std::int32_t {
	ProtectedContent                  = 0x00000001,
	AllowEncodeParameterOptimizations = 0x00000002,
	InlineQueries                     = 0x00000004,
	AllowEncodeQuantizationDeltaMap   = 0x00000008,
	AllowEncodeEmphasisMap            = 0x00000010,
	InlineSessionParameters           = 0x00000020,
	AllBits                           = 0x0000003f, // generated for ~(not), error checking and for convenience
};
enum class VideoSessionParametersCreateBitsKHR : std::int32_t {
	QuantizationMapCompatible = 0x00000001,
	AllBits                   = 0x00000001, // generated for ~(not), error checking and for convenience
};
enum class WaylandSurfaceCreateBitsKHR : std::int32_t {};
enum class Win32SurfaceCreateBitsKHR : std::int32_t {};
enum class XcbSurfaceCreateBitsKHR : std::int32_t {};
enum class XlibSurfaceCreateBitsKHR : std::int32_t {};
// NOLINTEND(performance-enum-size)
} // namespace VkBindings
