#include "VkBindings/EnumToString.hpp"
#include "VkBindings/Enums.hpp"

#include <string>

namespace VkBindings::Reflections {
// NOLINTBEGIN(readability-function-size)
template<> auto enumToString(AccelerationStructureBuildTypeKHR enumVal) -> std::string {
	using enum AccelerationStructureBuildTypeKHR;
	switch (enumVal) {
	case Host: {
		return "Host";
	}
	case Device: {
		return "Device";
	}
	case HostOrDevice: {
		return "HostOrDevice";
	}
	}
	return "EnumElement not part of: AccelerationStructureBuildTypeKHR";
}
template<> auto enumToString(AccelerationStructureCompatibilityKHR enumVal) -> std::string {
	using enum AccelerationStructureCompatibilityKHR;
	switch (enumVal) {
	case Compatible: {
		return "Compatible";
	}
	case Incompatible: {
		return "Incompatible";
	}
	}
	return "EnumElement not part of: AccelerationStructureCompatibilityKHR";
}
template<> auto enumToString(AccelerationStructureMemoryRequirementsTypeNV enumVal) -> std::string {
	using enum AccelerationStructureMemoryRequirementsTypeNV;
	switch (enumVal) {
	case Object: {
		return "Object";
	}
	case BuildScratch: {
		return "BuildScratch";
	}
	case UpdateScratch: {
		return "UpdateScratch";
	}
	}
	return "EnumElement not part of: AccelerationStructureMemoryRequirementsTypeNV";
}
template<> auto enumToString(AccelerationStructureMotionInstanceTypeNV enumVal) -> std::string {
	using enum AccelerationStructureMotionInstanceTypeNV;
	switch (enumVal) {
	case Static: {
		return "Static";
	}
	case MatrixMotion: {
		return "MatrixMotion";
	}
	case SrtMotion: {
		return "SrtMotion";
	}
	}
	return "EnumElement not part of: AccelerationStructureMotionInstanceTypeNV";
}
template<> auto enumToString(AccelerationStructureSerializedBlockTypeKHR enumVal) -> std::string {
	using enum AccelerationStructureSerializedBlockTypeKHR;
	switch (enumVal) {
	case OpacityMicromap: {
		return "OpacityMicromap";
	}
	}
	return "EnumElement not part of: AccelerationStructureSerializedBlockTypeKHR";
}
template<> auto enumToString(AccelerationStructureTypeKHR enumVal) -> std::string {
	using enum AccelerationStructureTypeKHR;
	switch (enumVal) {
	case TopLevel: {
		return "TopLevel";
	}
	case BottomLevel: {
		return "BottomLevel";
	}
	case Generic: {
		return "Generic";
	}
	case OpacityMicromap: {
		return "OpacityMicromap";
	}
	}
	return "EnumElement not part of: AccelerationStructureTypeKHR";
}
template<> auto enumToString(AntiLagModeAMD enumVal) -> std::string {
	using enum AntiLagModeAMD;
	switch (enumVal) {
	case DriverControl: {
		return "DriverControl";
	}
	case On: {
		return "On";
	}
	case Off: {
		return "Off";
	}
	}
	return "EnumElement not part of: AntiLagModeAMD";
}
template<> auto enumToString(AntiLagStageAMD enumVal) -> std::string {
	using enum AntiLagStageAMD;
	switch (enumVal) {
	case Input: {
		return "Input";
	}
	case Present: {
		return "Present";
	}
	}
	return "EnumElement not part of: AntiLagStageAMD";
}
template<> auto enumToString(AttachmentLoadOp enumVal) -> std::string {
	using enum AttachmentLoadOp;
	switch (enumVal) {
	case Load: {
		return "Load";
	}
	case Clear: {
		return "Clear";
	}
	case DontCare: {
		return "DontCare";
	}
	case None: {
		return "None";
	}
	}
	return "EnumElement not part of: AttachmentLoadOp";
}
template<> auto enumToString(AttachmentStoreOp enumVal) -> std::string {
	using enum AttachmentStoreOp;
	switch (enumVal) {
	case Store: {
		return "Store";
	}
	case DontCare: {
		return "DontCare";
	}
	case None: {
		return "None";
	}
	}
	return "EnumElement not part of: AttachmentStoreOp";
}
template<> auto enumToString(BlendFactor enumVal) -> std::string {
	using enum BlendFactor;
	switch (enumVal) {
	case Zero: {
		return "Zero";
	}
	case One: {
		return "One";
	}
	case SrcColor: {
		return "SrcColor";
	}
	case OneMinusSrcColor: {
		return "OneMinusSrcColor";
	}
	case DstColor: {
		return "DstColor";
	}
	case OneMinusDstColor: {
		return "OneMinusDstColor";
	}
	case SrcAlpha: {
		return "SrcAlpha";
	}
	case OneMinusSrcAlpha: {
		return "OneMinusSrcAlpha";
	}
	case DstAlpha: {
		return "DstAlpha";
	}
	case OneMinusDstAlpha: {
		return "OneMinusDstAlpha";
	}
	case ConstantColor: {
		return "ConstantColor";
	}
	case OneMinusConstantColor: {
		return "OneMinusConstantColor";
	}
	case ConstantAlpha: {
		return "ConstantAlpha";
	}
	case OneMinusConstantAlpha: {
		return "OneMinusConstantAlpha";
	}
	case SrcAlphaSaturate: {
		return "SrcAlphaSaturate";
	}
	case Src1Color: {
		return "Src1Color";
	}
	case OneMinusSrc1Color: {
		return "OneMinusSrc1Color";
	}
	case Src1Alpha: {
		return "Src1Alpha";
	}
	case OneMinusSrc1Alpha: {
		return "OneMinusSrc1Alpha";
	}
	}
	return "EnumElement not part of: BlendFactor";
}
template<> auto enumToString(BlendOp enumVal) -> std::string {
	using enum BlendOp;
	switch (enumVal) {
	case Add: {
		return "Add";
	}
	case Subtract: {
		return "Subtract";
	}
	case ReverseSubtract: {
		return "ReverseSubtract";
	}
	case Min: {
		return "Min";
	}
	case Max: {
		return "Max";
	}
	case ZeroEXT: {
		return "ZeroEXT";
	}
	case SrcEXT: {
		return "SrcEXT";
	}
	case DstEXT: {
		return "DstEXT";
	}
	case SrcOverEXT: {
		return "SrcOverEXT";
	}
	case DstOverEXT: {
		return "DstOverEXT";
	}
	case SrcInEXT: {
		return "SrcInEXT";
	}
	case DstInEXT: {
		return "DstInEXT";
	}
	case SrcOutEXT: {
		return "SrcOutEXT";
	}
	case DstOutEXT: {
		return "DstOutEXT";
	}
	case SrcAtopEXT: {
		return "SrcAtopEXT";
	}
	case DstAtopEXT: {
		return "DstAtopEXT";
	}
	case XorEXT: {
		return "XorEXT";
	}
	case MultiplyEXT: {
		return "MultiplyEXT";
	}
	case ScreenEXT: {
		return "ScreenEXT";
	}
	case OverlayEXT: {
		return "OverlayEXT";
	}
	case DarkenEXT: {
		return "DarkenEXT";
	}
	case LightenEXT: {
		return "LightenEXT";
	}
	case ColordodgeEXT: {
		return "ColordodgeEXT";
	}
	case ColorburnEXT: {
		return "ColorburnEXT";
	}
	case HardlightEXT: {
		return "HardlightEXT";
	}
	case SoftlightEXT: {
		return "SoftlightEXT";
	}
	case DifferenceEXT: {
		return "DifferenceEXT";
	}
	case ExclusionEXT: {
		return "ExclusionEXT";
	}
	case InvertEXT: {
		return "InvertEXT";
	}
	case InvertRgbEXT: {
		return "InvertRgbEXT";
	}
	case LineardodgeEXT: {
		return "LineardodgeEXT";
	}
	case LinearburnEXT: {
		return "LinearburnEXT";
	}
	case VividlightEXT: {
		return "VividlightEXT";
	}
	case LinearlightEXT: {
		return "LinearlightEXT";
	}
	case PinlightEXT: {
		return "PinlightEXT";
	}
	case HardmixEXT: {
		return "HardmixEXT";
	}
	case HslHueEXT: {
		return "HslHueEXT";
	}
	case HslSaturationEXT: {
		return "HslSaturationEXT";
	}
	case HslColorEXT: {
		return "HslColorEXT";
	}
	case HslLuminosityEXT: {
		return "HslLuminosityEXT";
	}
	case PlusEXT: {
		return "PlusEXT";
	}
	case PlusClampedEXT: {
		return "PlusClampedEXT";
	}
	case PlusClampedAlphaEXT: {
		return "PlusClampedAlphaEXT";
	}
	case PlusDarkerEXT: {
		return "PlusDarkerEXT";
	}
	case MinusEXT: {
		return "MinusEXT";
	}
	case MinusClampedEXT: {
		return "MinusClampedEXT";
	}
	case ContrastEXT: {
		return "ContrastEXT";
	}
	case InvertOvgEXT: {
		return "InvertOvgEXT";
	}
	case RedEXT: {
		return "RedEXT";
	}
	case GreenEXT: {
		return "GreenEXT";
	}
	case BlueEXT: {
		return "BlueEXT";
	}
	}
	return "EnumElement not part of: BlendOp";
}
template<> auto enumToString(BlendOverlapEXT enumVal) -> std::string {
	using enum BlendOverlapEXT;
	switch (enumVal) {
	case Uncorrelated: {
		return "Uncorrelated";
	}
	case Disjoint: {
		return "Disjoint";
	}
	case Conjoint: {
		return "Conjoint";
	}
	}
	return "EnumElement not part of: BlendOverlapEXT";
}
template<> auto enumToString(BlockMatchWindowCompareModeQCOM enumVal) -> std::string {
	using enum BlockMatchWindowCompareModeQCOM;
	switch (enumVal) {
	case Min: {
		return "Min";
	}
	case Max: {
		return "Max";
	}
	}
	return "EnumElement not part of: BlockMatchWindowCompareModeQCOM";
}
template<> auto enumToString(BorderColor enumVal) -> std::string {
	using enum BorderColor;
	switch (enumVal) {
	case FloatTransparentBlack: {
		return "FloatTransparentBlack";
	}
	case IntTransparentBlack: {
		return "IntTransparentBlack";
	}
	case FloatOpaqueBlack: {
		return "FloatOpaqueBlack";
	}
	case IntOpaqueBlack: {
		return "IntOpaqueBlack";
	}
	case FloatOpaqueWhite: {
		return "FloatOpaqueWhite";
	}
	case IntOpaqueWhite: {
		return "IntOpaqueWhite";
	}
	case FloatCustomEXT: {
		return "FloatCustomEXT";
	}
	case IntCustomEXT: {
		return "IntCustomEXT";
	}
	}
	return "EnumElement not part of: BorderColor";
}
template<> auto enumToString(BuildAccelerationStructureModeKHR enumVal) -> std::string {
	using enum BuildAccelerationStructureModeKHR;
	switch (enumVal) {
	case Build: {
		return "Build";
	}
	case Update: {
		return "Update";
	}
	}
	return "EnumElement not part of: BuildAccelerationStructureModeKHR";
}
template<> auto enumToString(BuildMicromapModeEXT enumVal) -> std::string {
	using enum BuildMicromapModeEXT;
	switch (enumVal) {
	case Build: {
		return "Build";
	}
	}
	return "EnumElement not part of: BuildMicromapModeEXT";
}
template<> auto enumToString(ChromaLocation enumVal) -> std::string {
	using enum ChromaLocation;
	switch (enumVal) {
	case CositedEven: {
		return "CositedEven";
	}
	case Midpoint: {
		return "Midpoint";
	}
	}
	return "EnumElement not part of: ChromaLocation";
}
template<> auto enumToString(ClusterAccelerationStructureOpModeNV enumVal) -> std::string {
	using enum ClusterAccelerationStructureOpModeNV;
	switch (enumVal) {
	case ImplicitDestinations: {
		return "ImplicitDestinations";
	}
	case ExplicitDestinations: {
		return "ExplicitDestinations";
	}
	case ComputeSizes: {
		return "ComputeSizes";
	}
	}
	return "EnumElement not part of: ClusterAccelerationStructureOpModeNV";
}
template<> auto enumToString(ClusterAccelerationStructureOpTypeNV enumVal) -> std::string {
	using enum ClusterAccelerationStructureOpTypeNV;
	switch (enumVal) {
	case MoveObjects: {
		return "MoveObjects";
	}
	case BuildClustersBottomLevel: {
		return "BuildClustersBottomLevel";
	}
	case BuildTriangleCluster: {
		return "BuildTriangleCluster";
	}
	case BuildTriangleClusterTemplate: {
		return "BuildTriangleClusterTemplate";
	}
	case InstantiateTriangleCluster: {
		return "InstantiateTriangleCluster";
	}
	case GetClusterTemplateIndices: {
		return "GetClusterTemplateIndices";
	}
	}
	return "EnumElement not part of: ClusterAccelerationStructureOpTypeNV";
}
template<> auto enumToString(ClusterAccelerationStructureTypeNV enumVal) -> std::string {
	using enum ClusterAccelerationStructureTypeNV;
	switch (enumVal) {
	case ClustersBottomLevel: {
		return "ClustersBottomLevel";
	}
	case TriangleCluster: {
		return "TriangleCluster";
	}
	case TriangleClusterTemplate: {
		return "TriangleClusterTemplate";
	}
	}
	return "EnumElement not part of: ClusterAccelerationStructureTypeNV";
}
template<> auto enumToString(CoarseSampleOrderTypeNV enumVal) -> std::string {
	using enum CoarseSampleOrderTypeNV;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case Custom: {
		return "Custom";
	}
	case PixelMajor: {
		return "PixelMajor";
	}
	case SampleMajor: {
		return "SampleMajor";
	}
	}
	return "EnumElement not part of: CoarseSampleOrderTypeNV";
}
template<> auto enumToString(ColorSpaceKHR enumVal) -> std::string {
	using enum ColorSpaceKHR;
	switch (enumVal) {
	case SrgbNonlinear: {
		return "SrgbNonlinear";
	}
	case DisplayP3NonlinearEXT: {
		return "DisplayP3NonlinearEXT";
	}
	case ExtendedSrgbLinearEXT: {
		return "ExtendedSrgbLinearEXT";
	}
	case DisplayP3LinearEXT: {
		return "DisplayP3LinearEXT";
	}
	case DciP3NonlinearEXT: {
		return "DciP3NonlinearEXT";
	}
	case Bt709LinearEXT: {
		return "Bt709LinearEXT";
	}
	case Bt709NonlinearEXT: {
		return "Bt709NonlinearEXT";
	}
	case Bt2020LinearEXT: {
		return "Bt2020LinearEXT";
	}
	case Hdr10St2084EXT: {
		return "Hdr10St2084EXT";
	}
	case DolbyvisionEXT: {
		return "DolbyvisionEXT";
	}
	case Hdr10HlgEXT: {
		return "Hdr10HlgEXT";
	}
	case AdobergbLinearEXT: {
		return "AdobergbLinearEXT";
	}
	case AdobergbNonlinearEXT: {
		return "AdobergbNonlinearEXT";
	}
	case PassThroughEXT: {
		return "PassThroughEXT";
	}
	case ExtendedSrgbNonlinearEXT: {
		return "ExtendedSrgbNonlinearEXT";
	}
	case DisplayNativeAMD: {
		return "DisplayNativeAMD";
	}
	}
	return "EnumElement not part of: ColorSpaceKHR";
}
template<> auto enumToString(CommandBufferLevel enumVal) -> std::string {
	using enum CommandBufferLevel;
	switch (enumVal) {
	case Primary: {
		return "Primary";
	}
	case Secondary: {
		return "Secondary";
	}
	}
	return "EnumElement not part of: CommandBufferLevel";
}
template<> auto enumToString(CompareOp enumVal) -> std::string {
	using enum CompareOp;
	switch (enumVal) {
	case Never: {
		return "Never";
	}
	case Less: {
		return "Less";
	}
	case Equal: {
		return "Equal";
	}
	case LessOrEqual: {
		return "LessOrEqual";
	}
	case Greater: {
		return "Greater";
	}
	case NotEqual: {
		return "NotEqual";
	}
	case GreaterOrEqual: {
		return "GreaterOrEqual";
	}
	case Always: {
		return "Always";
	}
	}
	return "EnumElement not part of: CompareOp";
}
template<> auto enumToString(ComponentSwizzle enumVal) -> std::string {
	using enum ComponentSwizzle;
	switch (enumVal) {
	case Identity: {
		return "Identity";
	}
	case Zero: {
		return "Zero";
	}
	case One: {
		return "One";
	}
	case R: {
		return "R";
	}
	case G: {
		return "G";
	}
	case B: {
		return "B";
	}
	case A: {
		return "A";
	}
	}
	return "EnumElement not part of: ComponentSwizzle";
}
template<> auto enumToString(ComponentTypeKHR enumVal) -> std::string {
	using enum ComponentTypeKHR;
	switch (enumVal) {
	case Float16: {
		return "Float16";
	}
	case Float32: {
		return "Float32";
	}
	case Float64: {
		return "Float64";
	}
	case Sint8: {
		return "Sint8";
	}
	case Sint16: {
		return "Sint16";
	}
	case Sint32: {
		return "Sint32";
	}
	case Sint64: {
		return "Sint64";
	}
	case Uint8: {
		return "Uint8";
	}
	case Uint16: {
		return "Uint16";
	}
	case Uint32: {
		return "Uint32";
	}
	case Uint64: {
		return "Uint64";
	}
	case Bfloat16: {
		return "Bfloat16";
	}
	case Sint8PackedNV: {
		return "Sint8PackedNV";
	}
	case Uint8PackedNV: {
		return "Uint8PackedNV";
	}
	case Float8E4M3EXT: {
		return "Float8E4M3EXT";
	}
	case Float8E5M2EXT: {
		return "Float8E5M2EXT";
	}
	case Float6E2M3EXT: {
		return "Float6E2M3EXT";
	}
	case Float6E3M2EXT: {
		return "Float6E3M2EXT";
	}
	case Float4E2M1EXT: {
		return "Float4E2M1EXT";
	}
	case Float8UnsignedE8M0EXT: {
		return "Float8UnsignedE8M0EXT";
	}
	case Mxint8EXT: {
		return "Mxint8EXT";
	}
	}
	return "EnumElement not part of: ComponentTypeKHR";
}
template<> auto enumToString(CompressedTriangleFormatAMDX enumVal) -> std::string {
	using enum CompressedTriangleFormatAMDX;
	switch (enumVal) {
	case Dgf1: {
		return "Dgf1";
	}
	}
	return "EnumElement not part of: CompressedTriangleFormatAMDX";
}
template<> auto enumToString(ConservativeRasterizationModeEXT enumVal) -> std::string {
	using enum ConservativeRasterizationModeEXT;
	switch (enumVal) {
	case Disabled: {
		return "Disabled";
	}
	case Overestimate: {
		return "Overestimate";
	}
	case Underestimate: {
		return "Underestimate";
	}
	}
	return "EnumElement not part of: ConservativeRasterizationModeEXT";
}
template<> auto enumToString(CooperativeVectorMatrixLayoutNV enumVal) -> std::string {
	using enum CooperativeVectorMatrixLayoutNV;
	switch (enumVal) {
	case RowMajor: {
		return "RowMajor";
	}
	case ColumnMajor: {
		return "ColumnMajor";
	}
	case InferencingOptimal: {
		return "InferencingOptimal";
	}
	case TrainingOptimal: {
		return "TrainingOptimal";
	}
	}
	return "EnumElement not part of: CooperativeVectorMatrixLayoutNV";
}
template<> auto enumToString(CopyAccelerationStructureModeKHR enumVal) -> std::string {
	using enum CopyAccelerationStructureModeKHR;
	switch (enumVal) {
	case Clone: {
		return "Clone";
	}
	case Compact: {
		return "Compact";
	}
	case Serialize: {
		return "Serialize";
	}
	case Deserialize: {
		return "Deserialize";
	}
	}
	return "EnumElement not part of: CopyAccelerationStructureModeKHR";
}
template<> auto enumToString(CopyMicromapModeEXT enumVal) -> std::string {
	using enum CopyMicromapModeEXT;
	switch (enumVal) {
	case Clone: {
		return "Clone";
	}
	case Serialize: {
		return "Serialize";
	}
	case Deserialize: {
		return "Deserialize";
	}
	case Compact: {
		return "Compact";
	}
	}
	return "EnumElement not part of: CopyMicromapModeEXT";
}
template<> auto enumToString(CoverageModulationModeNV enumVal) -> std::string {
	using enum CoverageModulationModeNV;
	switch (enumVal) {
	case None: {
		return "None";
	}
	case Rgb: {
		return "Rgb";
	}
	case Alpha: {
		return "Alpha";
	}
	case Rgba: {
		return "Rgba";
	}
	}
	return "EnumElement not part of: CoverageModulationModeNV";
}
template<> auto enumToString(CoverageReductionModeNV enumVal) -> std::string {
	using enum CoverageReductionModeNV;
	switch (enumVal) {
	case Merge: {
		return "Merge";
	}
	case Truncate: {
		return "Truncate";
	}
	}
	return "EnumElement not part of: CoverageReductionModeNV";
}
template<> auto enumToString(CubicFilterWeightsQCOM enumVal) -> std::string {
	using enum CubicFilterWeightsQCOM;
	switch (enumVal) {
	case CatmullRom: {
		return "CatmullRom";
	}
	case ZeroTangentCardinal: {
		return "ZeroTangentCardinal";
	}
	case BSpline: {
		return "BSpline";
	}
	case MitchellNetravali: {
		return "MitchellNetravali";
	}
	}
	return "EnumElement not part of: CubicFilterWeightsQCOM";
}
template<> auto enumToString(DataGraphModelCacheTypeQCOM enumVal) -> std::string {
	using enum DataGraphModelCacheTypeQCOM;
	switch (enumVal) {
	case GenericBinary: {
		return "GenericBinary";
	}
	}
	return "EnumElement not part of: DataGraphModelCacheTypeQCOM";
}
template<> auto enumToString(DataGraphOpticalFlowPerformanceLevelARM enumVal) -> std::string {
	using enum DataGraphOpticalFlowPerformanceLevelARM;
	switch (enumVal) {
	case Unknown: {
		return "Unknown";
	}
	case Slow: {
		return "Slow";
	}
	case Medium: {
		return "Medium";
	}
	case Fast: {
		return "Fast";
	}
	}
	return "EnumElement not part of: DataGraphOpticalFlowPerformanceLevelARM";
}
template<> auto enumToString(DataGraphPipelineNodeConnectionTypeARM enumVal) -> std::string {
	using enum DataGraphPipelineNodeConnectionTypeARM;
	switch (enumVal) {
	case OpticalFlowInput: {
		return "OpticalFlowInput";
	}
	case OpticalFlowReference: {
		return "OpticalFlowReference";
	}
	case OpticalFlowHint: {
		return "OpticalFlowHint";
	}
	case OpticalFlowFlowVector: {
		return "OpticalFlowFlowVector";
	}
	case OpticalFlowCost: {
		return "OpticalFlowCost";
	}
	}
	return "EnumElement not part of: DataGraphPipelineNodeConnectionTypeARM";
}
template<> auto enumToString(DataGraphPipelineNodeTypeARM enumVal) -> std::string {
	using enum DataGraphPipelineNodeTypeARM;
	switch (enumVal) {
	case OpticalFlow: {
		return "OpticalFlow";
	}
	}
	return "EnumElement not part of: DataGraphPipelineNodeTypeARM";
}
template<> auto enumToString(DataGraphPipelinePropertyARM enumVal) -> std::string {
	using enum DataGraphPipelinePropertyARM;
	switch (enumVal) {
	case CreationLog: {
		return "CreationLog";
	}
	case Identifier: {
		return "Identifier";
	}
	case NeuralAcceleratorDebugDatabase: {
		return "NeuralAcceleratorDebugDatabase";
	}
	case NeuralAcceleratorStatisticsInfo: {
		return "NeuralAcceleratorStatisticsInfo";
	}
	}
	return "EnumElement not part of: DataGraphPipelinePropertyARM";
}
template<> auto enumToString(DataGraphPipelineSessionBindPointARM enumVal) -> std::string {
	using enum DataGraphPipelineSessionBindPointARM;
	switch (enumVal) {
	case Transient: {
		return "Transient";
	}
	case OpticalFlowCache: {
		return "OpticalFlowCache";
	}
	case NeuralAcceleratorStatistics: {
		return "NeuralAcceleratorStatistics";
	}
	}
	return "EnumElement not part of: DataGraphPipelineSessionBindPointARM";
}
template<> auto enumToString(DataGraphPipelineSessionBindPointTypeARM enumVal) -> std::string {
	using enum DataGraphPipelineSessionBindPointTypeARM;
	switch (enumVal) {
	case Memory: {
		return "Memory";
	}
	}
	return "EnumElement not part of: DataGraphPipelineSessionBindPointTypeARM";
}
template<> auto enumToString(DataGraphTOSALevelARM enumVal) -> std::string {
	using enum DataGraphTOSALevelARM;
	switch (enumVal) {
	case DataGraphTosaLevelNone: {
		return "DataGraphTosaLevelNone";
	}
	case DataGraphTosaLevel8K: {
		return "DataGraphTosaLevel8K";
	}
	}
	return "EnumElement not part of: DataGraphTOSALevelARM";
}
template<> auto enumToString(DebugReportObjectTypeEXT enumVal) -> std::string {
	using enum DebugReportObjectTypeEXT;
	switch (enumVal) {
	case Unknown: {
		return "Unknown";
	}
	case Instance: {
		return "Instance";
	}
	case PhysicalDevice: {
		return "PhysicalDevice";
	}
	case Device: {
		return "Device";
	}
	case Queue: {
		return "Queue";
	}
	case Semaphore: {
		return "Semaphore";
	}
	case CommandBuffer: {
		return "CommandBuffer";
	}
	case Fence: {
		return "Fence";
	}
	case DeviceMemory: {
		return "DeviceMemory";
	}
	case Buffer: {
		return "Buffer";
	}
	case Image: {
		return "Image";
	}
	case Event: {
		return "Event";
	}
	case QueryPool: {
		return "QueryPool";
	}
	case BufferView: {
		return "BufferView";
	}
	case ImageView: {
		return "ImageView";
	}
	case ShaderModule: {
		return "ShaderModule";
	}
	case PipelineCache: {
		return "PipelineCache";
	}
	case PipelineLayout: {
		return "PipelineLayout";
	}
	case RenderPass: {
		return "RenderPass";
	}
	case Pipeline: {
		return "Pipeline";
	}
	case DescriptorSetLayout: {
		return "DescriptorSetLayout";
	}
	case Sampler: {
		return "Sampler";
	}
	case DescriptorPool: {
		return "DescriptorPool";
	}
	case DescriptorSet: {
		return "DescriptorSet";
	}
	case Framebuffer: {
		return "Framebuffer";
	}
	case CommandPool: {
		return "CommandPool";
	}
	case SurfaceKHR: {
		return "SurfaceKHR";
	}
	case SwapchainKHR: {
		return "SwapchainKHR";
	}
	case DebugReportCallbackEXT: {
		return "DebugReportCallbackEXT";
	}
	case DisplayKHR: {
		return "DisplayKHR";
	}
	case DisplayModeKHR: {
		return "DisplayModeKHR";
	}
	case ValidationCacheEXT: {
		return "ValidationCacheEXT";
	}
	case CuModuleNVX: {
		return "CuModuleNVX";
	}
	case CuFunctionNVX: {
		return "CuFunctionNVX";
	}
	case DescriptorUpdateTemplate: {
		return "DescriptorUpdateTemplate";
	}
	case AccelerationStructureKHR: {
		return "AccelerationStructureKHR";
	}
	case SamplerYcbcrConversion: {
		return "SamplerYcbcrConversion";
	}
	case AccelerationStructureNV: {
		return "AccelerationStructureNV";
	}
	case CudaModuleNV: {
		return "CudaModuleNV";
	}
	case CudaFunctionNV: {
		return "CudaFunctionNV";
	}
	case BufferCollectionFUCHSIA: {
		return "BufferCollectionFUCHSIA";
	}
	}
	return "EnumElement not part of: DebugReportObjectTypeEXT";
}
template<> auto enumToString(DefaultVertexAttributeValueKHR enumVal) -> std::string {
	using enum DefaultVertexAttributeValueKHR;
	switch (enumVal) {
	case ZeroZeroZeroZero: {
		return "ZeroZeroZeroZero";
	}
	case ZeroZeroZeroOne: {
		return "ZeroZeroZeroOne";
	}
	}
	return "EnumElement not part of: DefaultVertexAttributeValueKHR";
}
template<> auto enumToString(DepthBiasRepresentationEXT enumVal) -> std::string {
	using enum DepthBiasRepresentationEXT;
	switch (enumVal) {
	case LeastRepresentableValueFormat: {
		return "LeastRepresentableValueFormat";
	}
	case LeastRepresentableValueForceUnorm: {
		return "LeastRepresentableValueForceUnorm";
	}
	case Float: {
		return "Float";
	}
	}
	return "EnumElement not part of: DepthBiasRepresentationEXT";
}
template<> auto enumToString(DepthClampModeEXT enumVal) -> std::string {
	using enum DepthClampModeEXT;
	switch (enumVal) {
	case ViewportRange: {
		return "ViewportRange";
	}
	case UserDefinedRange: {
		return "UserDefinedRange";
	}
	}
	return "EnumElement not part of: DepthClampModeEXT";
}
template<> auto enumToString(DescriptorMappingSourceEXT enumVal) -> std::string {
	using enum DescriptorMappingSourceEXT;
	switch (enumVal) {
	case HeapWithConstantOffset: {
		return "HeapWithConstantOffset";
	}
	case HeapWithPushIndex: {
		return "HeapWithPushIndex";
	}
	case HeapWithIndirectIndex: {
		return "HeapWithIndirectIndex";
	}
	case HeapWithIndirectIndexArray: {
		return "HeapWithIndirectIndexArray";
	}
	case ResourceHeapData: {
		return "ResourceHeapData";
	}
	case PushData: {
		return "PushData";
	}
	case PushAddress: {
		return "PushAddress";
	}
	case IndirectAddress: {
		return "IndirectAddress";
	}
	case HeapWithShaderRecordIndex: {
		return "HeapWithShaderRecordIndex";
	}
	case ShaderRecordData: {
		return "ShaderRecordData";
	}
	case ShaderRecordAddress: {
		return "ShaderRecordAddress";
	}
	}
	return "EnumElement not part of: DescriptorMappingSourceEXT";
}
template<> auto enumToString(DescriptorType enumVal) -> std::string {
	using enum DescriptorType;
	switch (enumVal) {
	case Sampler: {
		return "Sampler";
	}
	case CombinedImageSampler: {
		return "CombinedImageSampler";
	}
	case SampledImage: {
		return "SampledImage";
	}
	case StorageImage: {
		return "StorageImage";
	}
	case UniformTexelBuffer: {
		return "UniformTexelBuffer";
	}
	case StorageTexelBuffer: {
		return "StorageTexelBuffer";
	}
	case UniformBuffer: {
		return "UniformBuffer";
	}
	case StorageBuffer: {
		return "StorageBuffer";
	}
	case UniformBufferDynamic: {
		return "UniformBufferDynamic";
	}
	case StorageBufferDynamic: {
		return "StorageBufferDynamic";
	}
	case InputAttachment: {
		return "InputAttachment";
	}
	case InlineUniformBlock: {
		return "InlineUniformBlock";
	}
	case AccelerationStructureKHR: {
		return "AccelerationStructureKHR";
	}
	case AccelerationStructureNV: {
		return "AccelerationStructureNV";
	}
	case MutableEXT: {
		return "MutableEXT";
	}
	case SampleWeightImageQCOM: {
		return "SampleWeightImageQCOM";
	}
	case BlockMatchImageQCOM: {
		return "BlockMatchImageQCOM";
	}
	case TensorARM: {
		return "TensorARM";
	}
	case PartitionedAccelerationStructureNV: {
		return "PartitionedAccelerationStructureNV";
	}
	}
	return "EnumElement not part of: DescriptorType";
}
template<> auto enumToString(DescriptorUpdateTemplateType enumVal) -> std::string {
	using enum DescriptorUpdateTemplateType;
	switch (enumVal) {
	case DescriptorSet: {
		return "DescriptorSet";
	}
	case PushDescriptors: {
		return "PushDescriptors";
	}
	}
	return "EnumElement not part of: DescriptorUpdateTemplateType";
}
template<> auto enumToString(DeviceAddressBindingTypeEXT enumVal) -> std::string {
	using enum DeviceAddressBindingTypeEXT;
	switch (enumVal) {
	case Bind: {
		return "Bind";
	}
	case Unbind: {
		return "Unbind";
	}
	}
	return "EnumElement not part of: DeviceAddressBindingTypeEXT";
}
template<> auto enumToString(DeviceEventTypeEXT enumVal) -> std::string {
	using enum DeviceEventTypeEXT;
	switch (enumVal) {
	case DisplayHotplug: {
		return "DisplayHotplug";
	}
	}
	return "EnumElement not part of: DeviceEventTypeEXT";
}
template<> auto enumToString(DeviceFaultAddressTypeKHR enumVal) -> std::string {
	using enum DeviceFaultAddressTypeKHR;
	switch (enumVal) {
	case None: {
		return "None";
	}
	case ReadInvalid: {
		return "ReadInvalid";
	}
	case WriteInvalid: {
		return "WriteInvalid";
	}
	case ExecuteInvalid: {
		return "ExecuteInvalid";
	}
	case InstructionPointerUnknown: {
		return "InstructionPointerUnknown";
	}
	case InstructionPointerInvalid: {
		return "InstructionPointerInvalid";
	}
	case InstructionPointerFault: {
		return "InstructionPointerFault";
	}
	}
	return "EnumElement not part of: DeviceFaultAddressTypeKHR";
}
template<> auto enumToString(DeviceFaultVendorBinaryHeaderVersionKHR enumVal) -> std::string {
	using enum DeviceFaultVendorBinaryHeaderVersionKHR;
	switch (enumVal) {
	case One: {
		return "One";
	}
	}
	return "EnumElement not part of: DeviceFaultVendorBinaryHeaderVersionKHR";
}
template<> auto enumToString(DeviceMemoryReportEventTypeEXT enumVal) -> std::string {
	using enum DeviceMemoryReportEventTypeEXT;
	switch (enumVal) {
	case Allocate: {
		return "Allocate";
	}
	case Free: {
		return "Free";
	}
	case Import: {
		return "Import";
	}
	case Unimport: {
		return "Unimport";
	}
	case AllocationFailed: {
		return "AllocationFailed";
	}
	}
	return "EnumElement not part of: DeviceMemoryReportEventTypeEXT";
}
template<> auto enumToString(DirectDriverLoadingModeLUNARG enumVal) -> std::string {
	using enum DirectDriverLoadingModeLUNARG;
	switch (enumVal) {
	case Exclusive: {
		return "Exclusive";
	}
	case Inclusive: {
		return "Inclusive";
	}
	}
	return "EnumElement not part of: DirectDriverLoadingModeLUNARG";
}
template<> auto enumToString(DiscardRectangleModeEXT enumVal) -> std::string {
	using enum DiscardRectangleModeEXT;
	switch (enumVal) {
	case Inclusive: {
		return "Inclusive";
	}
	case Exclusive: {
		return "Exclusive";
	}
	}
	return "EnumElement not part of: DiscardRectangleModeEXT";
}
template<> auto enumToString(DisplacementMicromapFormatNV enumVal) -> std::string {
	using enum DisplacementMicromapFormatNV;
	switch (enumVal) {
	case v64Triangles64Bytes: {
		return "v64Triangles64Bytes";
	}
	case v256Triangles128Bytes: {
		return "v256Triangles128Bytes";
	}
	case v1024Triangles128Bytes: {
		return "v1024Triangles128Bytes";
	}
	}
	return "EnumElement not part of: DisplacementMicromapFormatNV";
}
template<> auto enumToString(DisplayEventTypeEXT enumVal) -> std::string {
	using enum DisplayEventTypeEXT;
	switch (enumVal) {
	case FirstPixelOut: {
		return "FirstPixelOut";
	}
	}
	return "EnumElement not part of: DisplayEventTypeEXT";
}
template<> auto enumToString(DisplayPowerStateEXT enumVal) -> std::string {
	using enum DisplayPowerStateEXT;
	switch (enumVal) {
	case Off: {
		return "Off";
	}
	case Suspend: {
		return "Suspend";
	}
	case On: {
		return "On";
	}
	}
	return "EnumElement not part of: DisplayPowerStateEXT";
}
template<> auto enumToString(DisplaySurfaceStereoTypeNV enumVal) -> std::string {
	using enum DisplaySurfaceStereoTypeNV;
	switch (enumVal) {
	case None: {
		return "None";
	}
	case OnboardDin: {
		return "OnboardDin";
	}
	case Hdmi3D: {
		return "Hdmi3D";
	}
	case InbandDisplayport: {
		return "InbandDisplayport";
	}
	}
	return "EnumElement not part of: DisplaySurfaceStereoTypeNV";
}
template<> auto enumToString(DriverId enumVal) -> std::string {
	using enum DriverId;
	switch (enumVal) {
	case AMDProprietary: {
		return "AMDProprietary";
	}
	case AMDOpenSource: {
		return "AMDOpenSource";
	}
	case MESARadv: {
		return "MESARadv";
	}
	case NvidiaProprietary: {
		return "NvidiaProprietary";
	}
	case INTELProprietaryWindows: {
		return "INTELProprietaryWindows";
	}
	case INTELOpenSourceMESA: {
		return "INTELOpenSourceMESA";
	}
	case ImaginationProprietary: {
		return "ImaginationProprietary";
	}
	case QualcommProprietary: {
		return "QualcommProprietary";
	}
	case ARMProprietary: {
		return "ARMProprietary";
	}
	case GOOGLESwiftshader: {
		return "GOOGLESwiftshader";
	}
	case GGPProprietary: {
		return "GGPProprietary";
	}
	case BroadcomProprietary: {
		return "BroadcomProprietary";
	}
	case MESALlvmpipe: {
		return "MESALlvmpipe";
	}
	case Moltenvk: {
		return "Moltenvk";
	}
	case CoreaviProprietary: {
		return "CoreaviProprietary";
	}
	case JUICEProprietary: {
		return "JUICEProprietary";
	}
	case VerisiliconProprietary: {
		return "VerisiliconProprietary";
	}
	case MESATurnip: {
		return "MESATurnip";
	}
	case MESAV3Dv: {
		return "MESAV3Dv";
	}
	case MESAPanvk: {
		return "MESAPanvk";
	}
	case SAMSUNGProprietary: {
		return "SAMSUNGProprietary";
	}
	case MESAVenus: {
		return "MESAVenus";
	}
	case MESADozen: {
		return "MESADozen";
	}
	case MESANvk: {
		return "MESANvk";
	}
	case ImaginationOpenSourceMESA: {
		return "ImaginationOpenSourceMESA";
	}
	case MESAHoneykrisp: {
		return "MESAHoneykrisp";
	}
	case VulkanScEmulationOnVulkan: {
		return "VulkanScEmulationOnVulkan";
	}
	case MESAKosmickrisp: {
		return "MESAKosmickrisp";
	}
	case MESAGfxstream: {
		return "MESAGfxstream";
	}
	case ApeSoft: {
		return "ApeSoft";
	}
	case Reserved31: {
		return "Reserved31";
	}
	}
	return "EnumElement not part of: DriverId";
}
template<> auto enumToString(DynamicState enumVal) -> std::string {
	using enum DynamicState;
	switch (enumVal) {
	case Viewport: {
		return "Viewport";
	}
	case Scissor: {
		return "Scissor";
	}
	case LineWidth: {
		return "LineWidth";
	}
	case DepthBias: {
		return "DepthBias";
	}
	case BlendConstants: {
		return "BlendConstants";
	}
	case DepthBounds: {
		return "DepthBounds";
	}
	case StencilCompareMask: {
		return "StencilCompareMask";
	}
	case StencilWriteMask: {
		return "StencilWriteMask";
	}
	case StencilReference: {
		return "StencilReference";
	}
	case ViewportWScalingNV: {
		return "ViewportWScalingNV";
	}
	case DiscardRectangleEXT: {
		return "DiscardRectangleEXT";
	}
	case DiscardRectangleEnableEXT: {
		return "DiscardRectangleEnableEXT";
	}
	case DiscardRectangleModeEXT: {
		return "DiscardRectangleModeEXT";
	}
	case SampleLocationsEXT: {
		return "SampleLocationsEXT";
	}
	case ViewportShadingRatePaletteNV: {
		return "ViewportShadingRatePaletteNV";
	}
	case ViewportCoarseSampleOrderNV: {
		return "ViewportCoarseSampleOrderNV";
	}
	case ExclusiveScissorEnableNV: {
		return "ExclusiveScissorEnableNV";
	}
	case ExclusiveScissorNV: {
		return "ExclusiveScissorNV";
	}
	case FragmentShadingRateKHR: {
		return "FragmentShadingRateKHR";
	}
	case LineStipple: {
		return "LineStipple";
	}
	case CullMode: {
		return "CullMode";
	}
	case FrontFace: {
		return "FrontFace";
	}
	case PrimitiveTopology: {
		return "PrimitiveTopology";
	}
	case ViewportWithCount: {
		return "ViewportWithCount";
	}
	case ScissorWithCount: {
		return "ScissorWithCount";
	}
	case VertexInputBindingStride: {
		return "VertexInputBindingStride";
	}
	case DepthTestEnable: {
		return "DepthTestEnable";
	}
	case DepthWriteEnable: {
		return "DepthWriteEnable";
	}
	case DepthCompareOp: {
		return "DepthCompareOp";
	}
	case DepthBoundsTestEnable: {
		return "DepthBoundsTestEnable";
	}
	case StencilTestEnable: {
		return "StencilTestEnable";
	}
	case StencilOp: {
		return "StencilOp";
	}
	case RayTracingPipelineStackSizeKHR: {
		return "RayTracingPipelineStackSizeKHR";
	}
	case VertexInputEXT: {
		return "VertexInputEXT";
	}
	case PatchControlPointsEXT: {
		return "PatchControlPointsEXT";
	}
	case RasterizerDiscardEnable: {
		return "RasterizerDiscardEnable";
	}
	case DepthBiasEnable: {
		return "DepthBiasEnable";
	}
	case LogicOpEXT: {
		return "LogicOpEXT";
	}
	case PrimitiveRestartEnable: {
		return "PrimitiveRestartEnable";
	}
	case ColorWriteEnableEXT: {
		return "ColorWriteEnableEXT";
	}
	case TessellationDomainOriginEXT: {
		return "TessellationDomainOriginEXT";
	}
	case DepthClampEnableEXT: {
		return "DepthClampEnableEXT";
	}
	case PolygonModeEXT: {
		return "PolygonModeEXT";
	}
	case RasterizationSamplesEXT: {
		return "RasterizationSamplesEXT";
	}
	case SampleMaskEXT: {
		return "SampleMaskEXT";
	}
	case AlphaToCoverageEnableEXT: {
		return "AlphaToCoverageEnableEXT";
	}
	case AlphaToOneEnableEXT: {
		return "AlphaToOneEnableEXT";
	}
	case LogicOpEnableEXT: {
		return "LogicOpEnableEXT";
	}
	case ColorBlendEnableEXT: {
		return "ColorBlendEnableEXT";
	}
	case ColorBlendEquationEXT: {
		return "ColorBlendEquationEXT";
	}
	case ColorWriteMaskEXT: {
		return "ColorWriteMaskEXT";
	}
	case RasterizationStreamEXT: {
		return "RasterizationStreamEXT";
	}
	case ConservativeRasterizationModeEXT: {
		return "ConservativeRasterizationModeEXT";
	}
	case ExtraPrimitiveOverestimationSizeEXT: {
		return "ExtraPrimitiveOverestimationSizeEXT";
	}
	case DepthClipEnableEXT: {
		return "DepthClipEnableEXT";
	}
	case SampleLocationsEnableEXT: {
		return "SampleLocationsEnableEXT";
	}
	case ColorBlendAdvancedEXT: {
		return "ColorBlendAdvancedEXT";
	}
	case ProvokingVertexModeEXT: {
		return "ProvokingVertexModeEXT";
	}
	case LineRasterizationModeEXT: {
		return "LineRasterizationModeEXT";
	}
	case LineStippleEnableEXT: {
		return "LineStippleEnableEXT";
	}
	case DepthClipNegativeOneToOneEXT: {
		return "DepthClipNegativeOneToOneEXT";
	}
	case ViewportWScalingEnableNV: {
		return "ViewportWScalingEnableNV";
	}
	case ViewportSwizzleNV: {
		return "ViewportSwizzleNV";
	}
	case CoverageToColorEnableNV: {
		return "CoverageToColorEnableNV";
	}
	case CoverageToColorLocationNV: {
		return "CoverageToColorLocationNV";
	}
	case CoverageModulationModeNV: {
		return "CoverageModulationModeNV";
	}
	case CoverageModulationTableEnableNV: {
		return "CoverageModulationTableEnableNV";
	}
	case CoverageModulationTableNV: {
		return "CoverageModulationTableNV";
	}
	case ShadingRateImageEnableNV: {
		return "ShadingRateImageEnableNV";
	}
	case RepresentativeFragmentTestEnableNV: {
		return "RepresentativeFragmentTestEnableNV";
	}
	case CoverageReductionModeNV: {
		return "CoverageReductionModeNV";
	}
	case AttachmentFeedbackLoopEnableEXT: {
		return "AttachmentFeedbackLoopEnableEXT";
	}
	case DepthClampRangeEXT: {
		return "DepthClampRangeEXT";
	}
	}
	return "EnumElement not part of: DynamicState";
}
template<> auto enumToString(Filter enumVal) -> std::string {
	using enum Filter;
	switch (enumVal) {
	case Nearest: {
		return "Nearest";
	}
	case Linear: {
		return "Linear";
	}
	case CubicEXT: {
		return "CubicEXT";
	}
	}
	return "EnumElement not part of: Filter";
}
template<> auto enumToString(Format enumVal) -> std::string {
	using enum Format;
	switch (enumVal) {
	case Undefined: {
		return "Undefined";
	}
	case R4G4UnormPack8: {
		return "R4G4UnormPack8";
	}
	case R4G4B4A4UnormPack16: {
		return "R4G4B4A4UnormPack16";
	}
	case B4G4R4A4UnormPack16: {
		return "B4G4R4A4UnormPack16";
	}
	case R5G6B5UnormPack16: {
		return "R5G6B5UnormPack16";
	}
	case B5G6R5UnormPack16: {
		return "B5G6R5UnormPack16";
	}
	case R5G5B5A1UnormPack16: {
		return "R5G5B5A1UnormPack16";
	}
	case B5G5R5A1UnormPack16: {
		return "B5G5R5A1UnormPack16";
	}
	case A1R5G5B5UnormPack16: {
		return "A1R5G5B5UnormPack16";
	}
	case R8Unorm: {
		return "R8Unorm";
	}
	case R8Snorm: {
		return "R8Snorm";
	}
	case R8Uscaled: {
		return "R8Uscaled";
	}
	case R8Sscaled: {
		return "R8Sscaled";
	}
	case R8Uint: {
		return "R8Uint";
	}
	case R8Sint: {
		return "R8Sint";
	}
	case R8Srgb: {
		return "R8Srgb";
	}
	case R8G8Unorm: {
		return "R8G8Unorm";
	}
	case R8G8Snorm: {
		return "R8G8Snorm";
	}
	case R8G8Uscaled: {
		return "R8G8Uscaled";
	}
	case R8G8Sscaled: {
		return "R8G8Sscaled";
	}
	case R8G8Uint: {
		return "R8G8Uint";
	}
	case R8G8Sint: {
		return "R8G8Sint";
	}
	case R8G8Srgb: {
		return "R8G8Srgb";
	}
	case R8G8B8Unorm: {
		return "R8G8B8Unorm";
	}
	case R8G8B8Snorm: {
		return "R8G8B8Snorm";
	}
	case R8G8B8Uscaled: {
		return "R8G8B8Uscaled";
	}
	case R8G8B8Sscaled: {
		return "R8G8B8Sscaled";
	}
	case R8G8B8Uint: {
		return "R8G8B8Uint";
	}
	case R8G8B8Sint: {
		return "R8G8B8Sint";
	}
	case R8G8B8Srgb: {
		return "R8G8B8Srgb";
	}
	case B8G8R8Unorm: {
		return "B8G8R8Unorm";
	}
	case B8G8R8Snorm: {
		return "B8G8R8Snorm";
	}
	case B8G8R8Uscaled: {
		return "B8G8R8Uscaled";
	}
	case B8G8R8Sscaled: {
		return "B8G8R8Sscaled";
	}
	case B8G8R8Uint: {
		return "B8G8R8Uint";
	}
	case B8G8R8Sint: {
		return "B8G8R8Sint";
	}
	case B8G8R8Srgb: {
		return "B8G8R8Srgb";
	}
	case R8G8B8A8Unorm: {
		return "R8G8B8A8Unorm";
	}
	case R8G8B8A8Snorm: {
		return "R8G8B8A8Snorm";
	}
	case R8G8B8A8Uscaled: {
		return "R8G8B8A8Uscaled";
	}
	case R8G8B8A8Sscaled: {
		return "R8G8B8A8Sscaled";
	}
	case R8G8B8A8Uint: {
		return "R8G8B8A8Uint";
	}
	case R8G8B8A8Sint: {
		return "R8G8B8A8Sint";
	}
	case R8G8B8A8Srgb: {
		return "R8G8B8A8Srgb";
	}
	case B8G8R8A8Unorm: {
		return "B8G8R8A8Unorm";
	}
	case B8G8R8A8Snorm: {
		return "B8G8R8A8Snorm";
	}
	case B8G8R8A8Uscaled: {
		return "B8G8R8A8Uscaled";
	}
	case B8G8R8A8Sscaled: {
		return "B8G8R8A8Sscaled";
	}
	case B8G8R8A8Uint: {
		return "B8G8R8A8Uint";
	}
	case B8G8R8A8Sint: {
		return "B8G8R8A8Sint";
	}
	case B8G8R8A8Srgb: {
		return "B8G8R8A8Srgb";
	}
	case A8B8G8R8UnormPack32: {
		return "A8B8G8R8UnormPack32";
	}
	case A8B8G8R8SnormPack32: {
		return "A8B8G8R8SnormPack32";
	}
	case A8B8G8R8UscaledPack32: {
		return "A8B8G8R8UscaledPack32";
	}
	case A8B8G8R8SscaledPack32: {
		return "A8B8G8R8SscaledPack32";
	}
	case A8B8G8R8UintPack32: {
		return "A8B8G8R8UintPack32";
	}
	case A8B8G8R8SintPack32: {
		return "A8B8G8R8SintPack32";
	}
	case A8B8G8R8SrgbPack32: {
		return "A8B8G8R8SrgbPack32";
	}
	case A2R10G10B10UnormPack32: {
		return "A2R10G10B10UnormPack32";
	}
	case A2R10G10B10SnormPack32: {
		return "A2R10G10B10SnormPack32";
	}
	case A2R10G10B10UscaledPack32: {
		return "A2R10G10B10UscaledPack32";
	}
	case A2R10G10B10SscaledPack32: {
		return "A2R10G10B10SscaledPack32";
	}
	case A2R10G10B10UintPack32: {
		return "A2R10G10B10UintPack32";
	}
	case A2R10G10B10SintPack32: {
		return "A2R10G10B10SintPack32";
	}
	case A2B10G10R10UnormPack32: {
		return "A2B10G10R10UnormPack32";
	}
	case A2B10G10R10SnormPack32: {
		return "A2B10G10R10SnormPack32";
	}
	case A2B10G10R10UscaledPack32: {
		return "A2B10G10R10UscaledPack32";
	}
	case A2B10G10R10SscaledPack32: {
		return "A2B10G10R10SscaledPack32";
	}
	case A2B10G10R10UintPack32: {
		return "A2B10G10R10UintPack32";
	}
	case A2B10G10R10SintPack32: {
		return "A2B10G10R10SintPack32";
	}
	case R16Unorm: {
		return "R16Unorm";
	}
	case R16Snorm: {
		return "R16Snorm";
	}
	case R16Uscaled: {
		return "R16Uscaled";
	}
	case R16Sscaled: {
		return "R16Sscaled";
	}
	case R16Uint: {
		return "R16Uint";
	}
	case R16Sint: {
		return "R16Sint";
	}
	case R16Sfloat: {
		return "R16Sfloat";
	}
	case R16G16Unorm: {
		return "R16G16Unorm";
	}
	case R16G16Snorm: {
		return "R16G16Snorm";
	}
	case R16G16Uscaled: {
		return "R16G16Uscaled";
	}
	case R16G16Sscaled: {
		return "R16G16Sscaled";
	}
	case R16G16Uint: {
		return "R16G16Uint";
	}
	case R16G16Sint: {
		return "R16G16Sint";
	}
	case R16G16Sfloat: {
		return "R16G16Sfloat";
	}
	case R16G16B16Unorm: {
		return "R16G16B16Unorm";
	}
	case R16G16B16Snorm: {
		return "R16G16B16Snorm";
	}
	case R16G16B16Uscaled: {
		return "R16G16B16Uscaled";
	}
	case R16G16B16Sscaled: {
		return "R16G16B16Sscaled";
	}
	case R16G16B16Uint: {
		return "R16G16B16Uint";
	}
	case R16G16B16Sint: {
		return "R16G16B16Sint";
	}
	case R16G16B16Sfloat: {
		return "R16G16B16Sfloat";
	}
	case R16G16B16A16Unorm: {
		return "R16G16B16A16Unorm";
	}
	case R16G16B16A16Snorm: {
		return "R16G16B16A16Snorm";
	}
	case R16G16B16A16Uscaled: {
		return "R16G16B16A16Uscaled";
	}
	case R16G16B16A16Sscaled: {
		return "R16G16B16A16Sscaled";
	}
	case R16G16B16A16Uint: {
		return "R16G16B16A16Uint";
	}
	case R16G16B16A16Sint: {
		return "R16G16B16A16Sint";
	}
	case R16G16B16A16Sfloat: {
		return "R16G16B16A16Sfloat";
	}
	case R32Uint: {
		return "R32Uint";
	}
	case R32Sint: {
		return "R32Sint";
	}
	case R32Sfloat: {
		return "R32Sfloat";
	}
	case R32G32Uint: {
		return "R32G32Uint";
	}
	case R32G32Sint: {
		return "R32G32Sint";
	}
	case R32G32Sfloat: {
		return "R32G32Sfloat";
	}
	case R32G32B32Uint: {
		return "R32G32B32Uint";
	}
	case R32G32B32Sint: {
		return "R32G32B32Sint";
	}
	case R32G32B32Sfloat: {
		return "R32G32B32Sfloat";
	}
	case R32G32B32A32Uint: {
		return "R32G32B32A32Uint";
	}
	case R32G32B32A32Sint: {
		return "R32G32B32A32Sint";
	}
	case R32G32B32A32Sfloat: {
		return "R32G32B32A32Sfloat";
	}
	case R64Uint: {
		return "R64Uint";
	}
	case R64Sint: {
		return "R64Sint";
	}
	case R64Sfloat: {
		return "R64Sfloat";
	}
	case R64G64Uint: {
		return "R64G64Uint";
	}
	case R64G64Sint: {
		return "R64G64Sint";
	}
	case R64G64Sfloat: {
		return "R64G64Sfloat";
	}
	case R64G64B64Uint: {
		return "R64G64B64Uint";
	}
	case R64G64B64Sint: {
		return "R64G64B64Sint";
	}
	case R64G64B64Sfloat: {
		return "R64G64B64Sfloat";
	}
	case R64G64B64A64Uint: {
		return "R64G64B64A64Uint";
	}
	case R64G64B64A64Sint: {
		return "R64G64B64A64Sint";
	}
	case R64G64B64A64Sfloat: {
		return "R64G64B64A64Sfloat";
	}
	case B10G11R11UfloatPack32: {
		return "B10G11R11UfloatPack32";
	}
	case E5B9G9R9UfloatPack32: {
		return "E5B9G9R9UfloatPack32";
	}
	case D16Unorm: {
		return "D16Unorm";
	}
	case x8D24UnormPack32: {
		return "x8D24UnormPack32";
	}
	case D32Sfloat: {
		return "D32Sfloat";
	}
	case S8Uint: {
		return "S8Uint";
	}
	case D16UnormS8Uint: {
		return "D16UnormS8Uint";
	}
	case D24UnormS8Uint: {
		return "D24UnormS8Uint";
	}
	case D32SfloatS8Uint: {
		return "D32SfloatS8Uint";
	}
	case Bc1RgbUnormBlock: {
		return "Bc1RgbUnormBlock";
	}
	case Bc1RgbSrgbBlock: {
		return "Bc1RgbSrgbBlock";
	}
	case Bc1RgbaUnormBlock: {
		return "Bc1RgbaUnormBlock";
	}
	case Bc1RgbaSrgbBlock: {
		return "Bc1RgbaSrgbBlock";
	}
	case Bc2UnormBlock: {
		return "Bc2UnormBlock";
	}
	case Bc2SrgbBlock: {
		return "Bc2SrgbBlock";
	}
	case Bc3UnormBlock: {
		return "Bc3UnormBlock";
	}
	case Bc3SrgbBlock: {
		return "Bc3SrgbBlock";
	}
	case Bc4UnormBlock: {
		return "Bc4UnormBlock";
	}
	case Bc4SnormBlock: {
		return "Bc4SnormBlock";
	}
	case Bc5UnormBlock: {
		return "Bc5UnormBlock";
	}
	case Bc5SnormBlock: {
		return "Bc5SnormBlock";
	}
	case Bc6HUfloatBlock: {
		return "Bc6HUfloatBlock";
	}
	case Bc6HSfloatBlock: {
		return "Bc6HSfloatBlock";
	}
	case Bc7UnormBlock: {
		return "Bc7UnormBlock";
	}
	case Bc7SrgbBlock: {
		return "Bc7SrgbBlock";
	}
	case Etc2R8G8B8UnormBlock: {
		return "Etc2R8G8B8UnormBlock";
	}
	case Etc2R8G8B8SrgbBlock: {
		return "Etc2R8G8B8SrgbBlock";
	}
	case Etc2R8G8B8A1UnormBlock: {
		return "Etc2R8G8B8A1UnormBlock";
	}
	case Etc2R8G8B8A1SrgbBlock: {
		return "Etc2R8G8B8A1SrgbBlock";
	}
	case Etc2R8G8B8A8UnormBlock: {
		return "Etc2R8G8B8A8UnormBlock";
	}
	case Etc2R8G8B8A8SrgbBlock: {
		return "Etc2R8G8B8A8SrgbBlock";
	}
	case EacR11UnormBlock: {
		return "EacR11UnormBlock";
	}
	case EacR11SnormBlock: {
		return "EacR11SnormBlock";
	}
	case EacR11G11UnormBlock: {
		return "EacR11G11UnormBlock";
	}
	case EacR11G11SnormBlock: {
		return "EacR11G11SnormBlock";
	}
	case Astc4x4UnormBlock: {
		return "Astc4x4UnormBlock";
	}
	case Astc4x4SrgbBlock: {
		return "Astc4x4SrgbBlock";
	}
	case Astc5x4UnormBlock: {
		return "Astc5x4UnormBlock";
	}
	case Astc5x4SrgbBlock: {
		return "Astc5x4SrgbBlock";
	}
	case Astc5x5UnormBlock: {
		return "Astc5x5UnormBlock";
	}
	case Astc5x5SrgbBlock: {
		return "Astc5x5SrgbBlock";
	}
	case Astc6x5UnormBlock: {
		return "Astc6x5UnormBlock";
	}
	case Astc6x5SrgbBlock: {
		return "Astc6x5SrgbBlock";
	}
	case Astc6x6UnormBlock: {
		return "Astc6x6UnormBlock";
	}
	case Astc6x6SrgbBlock: {
		return "Astc6x6SrgbBlock";
	}
	case Astc8x5UnormBlock: {
		return "Astc8x5UnormBlock";
	}
	case Astc8x5SrgbBlock: {
		return "Astc8x5SrgbBlock";
	}
	case Astc8x6UnormBlock: {
		return "Astc8x6UnormBlock";
	}
	case Astc8x6SrgbBlock: {
		return "Astc8x6SrgbBlock";
	}
	case Astc8x8UnormBlock: {
		return "Astc8x8UnormBlock";
	}
	case Astc8x8SrgbBlock: {
		return "Astc8x8SrgbBlock";
	}
	case Astc10x5UnormBlock: {
		return "Astc10x5UnormBlock";
	}
	case Astc10x5SrgbBlock: {
		return "Astc10x5SrgbBlock";
	}
	case Astc10x6UnormBlock: {
		return "Astc10x6UnormBlock";
	}
	case Astc10x6SrgbBlock: {
		return "Astc10x6SrgbBlock";
	}
	case Astc10x8UnormBlock: {
		return "Astc10x8UnormBlock";
	}
	case Astc10x8SrgbBlock: {
		return "Astc10x8SrgbBlock";
	}
	case Astc10x10UnormBlock: {
		return "Astc10x10UnormBlock";
	}
	case Astc10x10SrgbBlock: {
		return "Astc10x10SrgbBlock";
	}
	case Astc12x10UnormBlock: {
		return "Astc12x10UnormBlock";
	}
	case Astc12x10SrgbBlock: {
		return "Astc12x10SrgbBlock";
	}
	case Astc12x12UnormBlock: {
		return "Astc12x12UnormBlock";
	}
	case Astc12x12SrgbBlock: {
		return "Astc12x12SrgbBlock";
	}
	case Pvrtc12BppUnormBlockIMG: {
		return "Pvrtc12BppUnormBlockIMG";
	}
	case Pvrtc14BppUnormBlockIMG: {
		return "Pvrtc14BppUnormBlockIMG";
	}
	case Pvrtc22BppUnormBlockIMG: {
		return "Pvrtc22BppUnormBlockIMG";
	}
	case Pvrtc24BppUnormBlockIMG: {
		return "Pvrtc24BppUnormBlockIMG";
	}
	case Pvrtc12BppSrgbBlockIMG: {
		return "Pvrtc12BppSrgbBlockIMG";
	}
	case Pvrtc14BppSrgbBlockIMG: {
		return "Pvrtc14BppSrgbBlockIMG";
	}
	case Pvrtc22BppSrgbBlockIMG: {
		return "Pvrtc22BppSrgbBlockIMG";
	}
	case Pvrtc24BppSrgbBlockIMG: {
		return "Pvrtc24BppSrgbBlockIMG";
	}
	case Astc4x4SfloatBlock: {
		return "Astc4x4SfloatBlock";
	}
	case Astc5x4SfloatBlock: {
		return "Astc5x4SfloatBlock";
	}
	case Astc5x5SfloatBlock: {
		return "Astc5x5SfloatBlock";
	}
	case Astc6x5SfloatBlock: {
		return "Astc6x5SfloatBlock";
	}
	case Astc6x6SfloatBlock: {
		return "Astc6x6SfloatBlock";
	}
	case Astc8x5SfloatBlock: {
		return "Astc8x5SfloatBlock";
	}
	case Astc8x6SfloatBlock: {
		return "Astc8x6SfloatBlock";
	}
	case Astc8x8SfloatBlock: {
		return "Astc8x8SfloatBlock";
	}
	case Astc10x5SfloatBlock: {
		return "Astc10x5SfloatBlock";
	}
	case Astc10x6SfloatBlock: {
		return "Astc10x6SfloatBlock";
	}
	case Astc10x8SfloatBlock: {
		return "Astc10x8SfloatBlock";
	}
	case Astc10x10SfloatBlock: {
		return "Astc10x10SfloatBlock";
	}
	case Astc12x10SfloatBlock: {
		return "Astc12x10SfloatBlock";
	}
	case Astc12x12SfloatBlock: {
		return "Astc12x12SfloatBlock";
	}
	case G8B8G8R8422Unorm: {
		return "G8B8G8R8422Unorm";
	}
	case B8G8R8G8422Unorm: {
		return "B8G8R8G8422Unorm";
	}
	case G8B8R83Plane420Unorm: {
		return "G8B8R83Plane420Unorm";
	}
	case G8B8R82Plane420Unorm: {
		return "G8B8R82Plane420Unorm";
	}
	case G8B8R83Plane422Unorm: {
		return "G8B8R83Plane422Unorm";
	}
	case G8B8R82Plane422Unorm: {
		return "G8B8R82Plane422Unorm";
	}
	case G8B8R83Plane444Unorm: {
		return "G8B8R83Plane444Unorm";
	}
	case R10x6UnormPack16: {
		return "R10x6UnormPack16";
	}
	case R10x6G10x6Unorm2Pack16: {
		return "R10x6G10x6Unorm2Pack16";
	}
	case R10x6G10x6B10x6A10x6Unorm4Pack16: {
		return "R10x6G10x6B10x6A10x6Unorm4Pack16";
	}
	case G10x6B10x6G10x6R10x6422Unorm4Pack16: {
		return "G10x6B10x6G10x6R10x6422Unorm4Pack16";
	}
	case B10x6G10x6R10x6G10x6422Unorm4Pack16: {
		return "B10x6G10x6R10x6G10x6422Unorm4Pack16";
	}
	case G10x6B10x6R10x63Plane420Unorm3Pack16: {
		return "G10x6B10x6R10x63Plane420Unorm3Pack16";
	}
	case G10x6B10x6R10x62Plane420Unorm3Pack16: {
		return "G10x6B10x6R10x62Plane420Unorm3Pack16";
	}
	case G10x6B10x6R10x63Plane422Unorm3Pack16: {
		return "G10x6B10x6R10x63Plane422Unorm3Pack16";
	}
	case G10x6B10x6R10x62Plane422Unorm3Pack16: {
		return "G10x6B10x6R10x62Plane422Unorm3Pack16";
	}
	case G10x6B10x6R10x63Plane444Unorm3Pack16: {
		return "G10x6B10x6R10x63Plane444Unorm3Pack16";
	}
	case R12x4UnormPack16: {
		return "R12x4UnormPack16";
	}
	case R12x4G12x4Unorm2Pack16: {
		return "R12x4G12x4Unorm2Pack16";
	}
	case R12x4G12x4B12x4A12x4Unorm4Pack16: {
		return "R12x4G12x4B12x4A12x4Unorm4Pack16";
	}
	case G12x4B12x4G12x4R12x4422Unorm4Pack16: {
		return "G12x4B12x4G12x4R12x4422Unorm4Pack16";
	}
	case B12x4G12x4R12x4G12x4422Unorm4Pack16: {
		return "B12x4G12x4R12x4G12x4422Unorm4Pack16";
	}
	case G12x4B12x4R12x43Plane420Unorm3Pack16: {
		return "G12x4B12x4R12x43Plane420Unorm3Pack16";
	}
	case G12x4B12x4R12x42Plane420Unorm3Pack16: {
		return "G12x4B12x4R12x42Plane420Unorm3Pack16";
	}
	case G12x4B12x4R12x43Plane422Unorm3Pack16: {
		return "G12x4B12x4R12x43Plane422Unorm3Pack16";
	}
	case G12x4B12x4R12x42Plane422Unorm3Pack16: {
		return "G12x4B12x4R12x42Plane422Unorm3Pack16";
	}
	case G12x4B12x4R12x43Plane444Unorm3Pack16: {
		return "G12x4B12x4R12x43Plane444Unorm3Pack16";
	}
	case G16B16G16R16422Unorm: {
		return "G16B16G16R16422Unorm";
	}
	case B16G16R16G16422Unorm: {
		return "B16G16R16G16422Unorm";
	}
	case G16B16R163Plane420Unorm: {
		return "G16B16R163Plane420Unorm";
	}
	case G16B16R162Plane420Unorm: {
		return "G16B16R162Plane420Unorm";
	}
	case G16B16R163Plane422Unorm: {
		return "G16B16R163Plane422Unorm";
	}
	case G16B16R162Plane422Unorm: {
		return "G16B16R162Plane422Unorm";
	}
	case G16B16R163Plane444Unorm: {
		return "G16B16R163Plane444Unorm";
	}
	case Astc3x3x3UnormBlockEXT: {
		return "Astc3x3x3UnormBlockEXT";
	}
	case Astc3x3x3SrgbBlockEXT: {
		return "Astc3x3x3SrgbBlockEXT";
	}
	case Astc3x3x3SfloatBlockEXT: {
		return "Astc3x3x3SfloatBlockEXT";
	}
	case Astc4x3x3UnormBlockEXT: {
		return "Astc4x3x3UnormBlockEXT";
	}
	case Astc4x3x3SrgbBlockEXT: {
		return "Astc4x3x3SrgbBlockEXT";
	}
	case Astc4x3x3SfloatBlockEXT: {
		return "Astc4x3x3SfloatBlockEXT";
	}
	case Astc4x4x3UnormBlockEXT: {
		return "Astc4x4x3UnormBlockEXT";
	}
	case Astc4x4x3SrgbBlockEXT: {
		return "Astc4x4x3SrgbBlockEXT";
	}
	case Astc4x4x3SfloatBlockEXT: {
		return "Astc4x4x3SfloatBlockEXT";
	}
	case Astc4x4x4UnormBlockEXT: {
		return "Astc4x4x4UnormBlockEXT";
	}
	case Astc4x4x4SrgbBlockEXT: {
		return "Astc4x4x4SrgbBlockEXT";
	}
	case Astc4x4x4SfloatBlockEXT: {
		return "Astc4x4x4SfloatBlockEXT";
	}
	case Astc5x4x4UnormBlockEXT: {
		return "Astc5x4x4UnormBlockEXT";
	}
	case Astc5x4x4SrgbBlockEXT: {
		return "Astc5x4x4SrgbBlockEXT";
	}
	case Astc5x4x4SfloatBlockEXT: {
		return "Astc5x4x4SfloatBlockEXT";
	}
	case Astc5x5x4UnormBlockEXT: {
		return "Astc5x5x4UnormBlockEXT";
	}
	case Astc5x5x4SrgbBlockEXT: {
		return "Astc5x5x4SrgbBlockEXT";
	}
	case Astc5x5x4SfloatBlockEXT: {
		return "Astc5x5x4SfloatBlockEXT";
	}
	case Astc5x5x5UnormBlockEXT: {
		return "Astc5x5x5UnormBlockEXT";
	}
	case Astc5x5x5SrgbBlockEXT: {
		return "Astc5x5x5SrgbBlockEXT";
	}
	case Astc5x5x5SfloatBlockEXT: {
		return "Astc5x5x5SfloatBlockEXT";
	}
	case Astc6x5x5UnormBlockEXT: {
		return "Astc6x5x5UnormBlockEXT";
	}
	case Astc6x5x5SrgbBlockEXT: {
		return "Astc6x5x5SrgbBlockEXT";
	}
	case Astc6x5x5SfloatBlockEXT: {
		return "Astc6x5x5SfloatBlockEXT";
	}
	case Astc6x6x5UnormBlockEXT: {
		return "Astc6x6x5UnormBlockEXT";
	}
	case Astc6x6x5SrgbBlockEXT: {
		return "Astc6x6x5SrgbBlockEXT";
	}
	case Astc6x6x5SfloatBlockEXT: {
		return "Astc6x6x5SfloatBlockEXT";
	}
	case Astc6x6x6UnormBlockEXT: {
		return "Astc6x6x6UnormBlockEXT";
	}
	case Astc6x6x6SrgbBlockEXT: {
		return "Astc6x6x6SrgbBlockEXT";
	}
	case Astc6x6x6SfloatBlockEXT: {
		return "Astc6x6x6SfloatBlockEXT";
	}
	case G8B8R82Plane444Unorm: {
		return "G8B8R82Plane444Unorm";
	}
	case G10x6B10x6R10x62Plane444Unorm3Pack16: {
		return "G10x6B10x6R10x62Plane444Unorm3Pack16";
	}
	case G12x4B12x4R12x42Plane444Unorm3Pack16: {
		return "G12x4B12x4R12x42Plane444Unorm3Pack16";
	}
	case G16B16R162Plane444Unorm: {
		return "G16B16R162Plane444Unorm";
	}
	case A4R4G4B4UnormPack16: {
		return "A4R4G4B4UnormPack16";
	}
	case A4B4G4R4UnormPack16: {
		return "A4B4G4R4UnormPack16";
	}
	case R8BoolARM: {
		return "R8BoolARM";
	}
	case R16SfloatFpencodingBfloat16ARM: {
		return "R16SfloatFpencodingBfloat16ARM";
	}
	case R8SfloatFpencodingFloat8E4M3ARM: {
		return "R8SfloatFpencodingFloat8E4M3ARM";
	}
	case R8SfloatFpencodingFloat8E5M2ARM: {
		return "R8SfloatFpencodingFloat8E5M2ARM";
	}
	case R16G16Sfixed5NV: {
		return "R16G16Sfixed5NV";
	}
	case A1B5G5R5UnormPack16: {
		return "A1B5G5R5UnormPack16";
	}
	case A8Unorm: {
		return "A8Unorm";
	}
	case R10x6UintPack16ARM: {
		return "R10x6UintPack16ARM";
	}
	case R10x6G10x6Uint2Pack16ARM: {
		return "R10x6G10x6Uint2Pack16ARM";
	}
	case R10x6G10x6B10x6A10x6Uint4Pack16ARM: {
		return "R10x6G10x6B10x6A10x6Uint4Pack16ARM";
	}
	case R12x4UintPack16ARM: {
		return "R12x4UintPack16ARM";
	}
	case R12x4G12x4Uint2Pack16ARM: {
		return "R12x4G12x4Uint2Pack16ARM";
	}
	case R12x4G12x4B12x4A12x4Uint4Pack16ARM: {
		return "R12x4G12x4B12x4A12x4Uint4Pack16ARM";
	}
	case R14x2UintPack16ARM: {
		return "R14x2UintPack16ARM";
	}
	case R14x2G14x2Uint2Pack16ARM: {
		return "R14x2G14x2Uint2Pack16ARM";
	}
	case R14x2G14x2B14x2A14x2Uint4Pack16ARM: {
		return "R14x2G14x2B14x2A14x2Uint4Pack16ARM";
	}
	case R14x2UnormPack16ARM: {
		return "R14x2UnormPack16ARM";
	}
	case R14x2G14x2Unorm2Pack16ARM: {
		return "R14x2G14x2Unorm2Pack16ARM";
	}
	case R14x2G14x2B14x2A14x2Unorm4Pack16ARM: {
		return "R14x2G14x2B14x2A14x2Unorm4Pack16ARM";
	}
	case G14x2B14x2R14x22Plane420Unorm3Pack16ARM: {
		return "G14x2B14x2R14x22Plane420Unorm3Pack16ARM";
	}
	case G14x2B14x2R14x22Plane422Unorm3Pack16ARM: {
		return "G14x2B14x2R14x22Plane422Unorm3Pack16ARM";
	}
	}
	return "EnumElement not part of: Format";
}
template<> auto enumToString(FragmentShadingRateNV enumVal) -> std::string {
	using enum FragmentShadingRateNV;
	switch (enumVal) {
	case v1InvocationPerPixel: {
		return "v1InvocationPerPixel";
	}
	case v1InvocationPer1x2Pixels: {
		return "v1InvocationPer1x2Pixels";
	}
	case v1InvocationPer2x1Pixels: {
		return "v1InvocationPer2x1Pixels";
	}
	case v1InvocationPer2x2Pixels: {
		return "v1InvocationPer2x2Pixels";
	}
	case v1InvocationPer2x4Pixels: {
		return "v1InvocationPer2x4Pixels";
	}
	case v1InvocationPer4x2Pixels: {
		return "v1InvocationPer4x2Pixels";
	}
	case v1InvocationPer4x4Pixels: {
		return "v1InvocationPer4x4Pixels";
	}
	case v2InvocationsPerPixel: {
		return "v2InvocationsPerPixel";
	}
	case v4InvocationsPerPixel: {
		return "v4InvocationsPerPixel";
	}
	case v8InvocationsPerPixel: {
		return "v8InvocationsPerPixel";
	}
	case v16InvocationsPerPixel: {
		return "v16InvocationsPerPixel";
	}
	case NoInvocations: {
		return "NoInvocations";
	}
	}
	return "EnumElement not part of: FragmentShadingRateNV";
}
template<> auto enumToString(FragmentShadingRateCombinerOpKHR enumVal) -> std::string {
	using enum FragmentShadingRateCombinerOpKHR;
	switch (enumVal) {
	case Keep: {
		return "Keep";
	}
	case Replace: {
		return "Replace";
	}
	case Min: {
		return "Min";
	}
	case Max: {
		return "Max";
	}
	case Mul: {
		return "Mul";
	}
	}
	return "EnumElement not part of: FragmentShadingRateCombinerOpKHR";
}
template<> auto enumToString(FragmentShadingRateTypeNV enumVal) -> std::string {
	using enum FragmentShadingRateTypeNV;
	switch (enumVal) {
	case FragmentSize: {
		return "FragmentSize";
	}
	case Enums: {
		return "Enums";
	}
	}
	return "EnumElement not part of: FragmentShadingRateTypeNV";
}
template<> auto enumToString(FrontFace enumVal) -> std::string {
	using enum FrontFace;
	switch (enumVal) {
	case CounterClockwise: {
		return "CounterClockwise";
	}
	case Clockwise: {
		return "Clockwise";
	}
	}
	return "EnumElement not part of: FrontFace";
}
template<> auto enumToString(FullScreenExclusiveEXT enumVal) -> std::string {
	using enum FullScreenExclusiveEXT;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case Allowed: {
		return "Allowed";
	}
	case Disallowed: {
		return "Disallowed";
	}
	case ApplicationControlled: {
		return "ApplicationControlled";
	}
	}
	return "EnumElement not part of: FullScreenExclusiveEXT";
}
template<> auto enumToString(GeometryTypeKHR enumVal) -> std::string {
	using enum GeometryTypeKHR;
	switch (enumVal) {
	case Triangles: {
		return "Triangles";
	}
	case Aabbs: {
		return "Aabbs";
	}
	case Instances: {
		return "Instances";
	}
	case SpheresNV: {
		return "SpheresNV";
	}
	case LinearSweptSpheresNV: {
		return "LinearSweptSpheresNV";
	}
	case DenseGeometryFormatTrianglesAMDX: {
		return "DenseGeometryFormatTrianglesAMDX";
	}
	case Micromap: {
		return "Micromap";
	}
	}
	return "EnumElement not part of: GeometryTypeKHR";
}
template<> auto enumToString(GpaDeviceClockModeAMD enumVal) -> std::string {
	using enum GpaDeviceClockModeAMD;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case Query: {
		return "Query";
	}
	case Profiling: {
		return "Profiling";
	}
	case MinMemory: {
		return "MinMemory";
	}
	case MinEngine: {
		return "MinEngine";
	}
	case Peak: {
		return "Peak";
	}
	}
	return "EnumElement not part of: GpaDeviceClockModeAMD";
}
template<> auto enumToString(GpaPerfBlockAMD enumVal) -> std::string {
	using enum GpaPerfBlockAMD;
	switch (enumVal) {
	case Cpf: {
		return "Cpf";
	}
	case Ia: {
		return "Ia";
	}
	case Vgt: {
		return "Vgt";
	}
	case Pa: {
		return "Pa";
	}
	case Sc: {
		return "Sc";
	}
	case Spi: {
		return "Spi";
	}
	case Sq: {
		return "Sq";
	}
	case Sx: {
		return "Sx";
	}
	case Ta: {
		return "Ta";
	}
	case Td: {
		return "Td";
	}
	case Tcp: {
		return "Tcp";
	}
	case Tcc: {
		return "Tcc";
	}
	case Tca: {
		return "Tca";
	}
	case Db: {
		return "Db";
	}
	case Cb: {
		return "Cb";
	}
	case Gds: {
		return "Gds";
	}
	case Srbm: {
		return "Srbm";
	}
	case Grbm: {
		return "Grbm";
	}
	case GrbmSe: {
		return "GrbmSe";
	}
	case Rlc: {
		return "Rlc";
	}
	case Dma: {
		return "Dma";
	}
	case Mc: {
		return "Mc";
	}
	case Cpg: {
		return "Cpg";
	}
	case Cpc: {
		return "Cpc";
	}
	case Wd: {
		return "Wd";
	}
	case Tcs: {
		return "Tcs";
	}
	case Atc: {
		return "Atc";
	}
	case AtcL2: {
		return "AtcL2";
	}
	case McVmL2: {
		return "McVmL2";
	}
	case Ea: {
		return "Ea";
	}
	case Rpb: {
		return "Rpb";
	}
	case Rmi: {
		return "Rmi";
	}
	case Umcch: {
		return "Umcch";
	}
	case Ge: {
		return "Ge";
	}
	case Gl1A: {
		return "Gl1A";
	}
	case Gl1C: {
		return "Gl1C";
	}
	case Gl1Cg: {
		return "Gl1Cg";
	}
	case Gl2A: {
		return "Gl2A";
	}
	case Gl2C: {
		return "Gl2C";
	}
	case Cha: {
		return "Cha";
	}
	case Chc: {
		return "Chc";
	}
	case Chcg: {
		return "Chcg";
	}
	case Gus: {
		return "Gus";
	}
	case Gcr: {
		return "Gcr";
	}
	case Ph: {
		return "Ph";
	}
	case Utcl1: {
		return "Utcl1";
	}
	case GeDist: {
		return "GeDist";
	}
	case GeSe: {
		return "GeSe";
	}
	case DfMall: {
		return "DfMall";
	}
	case SqWgp: {
		return "SqWgp";
	}
	case Pc: {
		return "Pc";
	}
	case Gl1Xa: {
		return "Gl1Xa";
	}
	case Gl1Xc: {
		return "Gl1Xc";
	}
	case Wgs: {
		return "Wgs";
	}
	case Eacpwd: {
		return "Eacpwd";
	}
	case Ease: {
		return "Ease";
	}
	case Rlcuser: {
		return "Rlcuser";
	}
	}
	return "EnumElement not part of: GpaPerfBlockAMD";
}
template<> auto enumToString(GpaSampleTypeAMD enumVal) -> std::string {
	using enum GpaSampleTypeAMD;
	switch (enumVal) {
	case Cumulative: {
		return "Cumulative";
	}
	case Trace: {
		return "Trace";
	}
	case Timing: {
		return "Timing";
	}
	}
	return "EnumElement not part of: GpaSampleTypeAMD";
}
template<> auto enumToString(ImageLayout enumVal) -> std::string {
	using enum ImageLayout;
	switch (enumVal) {
	case Undefined: {
		return "Undefined";
	}
	case General: {
		return "General";
	}
	case ColorAttachmentOptimal: {
		return "ColorAttachmentOptimal";
	}
	case DepthStencilAttachmentOptimal: {
		return "DepthStencilAttachmentOptimal";
	}
	case DepthStencilReadOnlyOptimal: {
		return "DepthStencilReadOnlyOptimal";
	}
	case ShaderReadOnlyOptimal: {
		return "ShaderReadOnlyOptimal";
	}
	case TransferSrcOptimal: {
		return "TransferSrcOptimal";
	}
	case TransferDstOptimal: {
		return "TransferDstOptimal";
	}
	case Preinitialized: {
		return "Preinitialized";
	}
	case PresentSrcKHR: {
		return "PresentSrcKHR";
	}
	case VideoDecodeDstKHR: {
		return "VideoDecodeDstKHR";
	}
	case VideoDecodeSrcKHR: {
		return "VideoDecodeSrcKHR";
	}
	case VideoDecodeDpbKHR: {
		return "VideoDecodeDpbKHR";
	}
	case SharedPresentKHR: {
		return "SharedPresentKHR";
	}
	case DepthReadOnlyStencilAttachmentOptimal: {
		return "DepthReadOnlyStencilAttachmentOptimal";
	}
	case DepthAttachmentStencilReadOnlyOptimal: {
		return "DepthAttachmentStencilReadOnlyOptimal";
	}
	case FragmentShadingRateAttachmentOptimalKHR: {
		return "FragmentShadingRateAttachmentOptimalKHR";
	}
	case FragmentDensityMapOptimalEXT: {
		return "FragmentDensityMapOptimalEXT";
	}
	case RenderingLocalRead: {
		return "RenderingLocalRead";
	}
	case DepthAttachmentOptimal: {
		return "DepthAttachmentOptimal";
	}
	case DepthReadOnlyOptimal: {
		return "DepthReadOnlyOptimal";
	}
	case StencilAttachmentOptimal: {
		return "StencilAttachmentOptimal";
	}
	case StencilReadOnlyOptimal: {
		return "StencilReadOnlyOptimal";
	}
	case VideoEncodeDstKHR: {
		return "VideoEncodeDstKHR";
	}
	case VideoEncodeSrcKHR: {
		return "VideoEncodeSrcKHR";
	}
	case VideoEncodeDpbKHR: {
		return "VideoEncodeDpbKHR";
	}
	case ReadOnlyOptimal: {
		return "ReadOnlyOptimal";
	}
	case AttachmentOptimal: {
		return "AttachmentOptimal";
	}
	case AttachmentFeedbackLoopOptimalEXT: {
		return "AttachmentFeedbackLoopOptimalEXT";
	}
	case TensorAliasingARM: {
		return "TensorAliasingARM";
	}
	case VideoEncodeQuantizationMapKHR: {
		return "VideoEncodeQuantizationMapKHR";
	}
	case ZeroInitializedEXT: {
		return "ZeroInitializedEXT";
	}
	}
	return "EnumElement not part of: ImageLayout";
}
template<> auto enumToString(ImageTiling enumVal) -> std::string {
	using enum ImageTiling;
	switch (enumVal) {
	case Optimal: {
		return "Optimal";
	}
	case Linear: {
		return "Linear";
	}
	case DrmFormatModifierEXT: {
		return "DrmFormatModifierEXT";
	}
	}
	return "EnumElement not part of: ImageTiling";
}
template<> auto enumToString(ImageTilingControlEXT enumVal) -> std::string {
	using enum ImageTilingControlEXT;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case MinSize: {
		return "MinSize";
	}
	case MaxPerformance: {
		return "MaxPerformance";
	}
	}
	return "EnumElement not part of: ImageTilingControlEXT";
}
template<> auto enumToString(ImageType enumVal) -> std::string {
	using enum ImageType;
	switch (enumVal) {
	case v1D: {
		return "v1D";
	}
	case v2D: {
		return "v2D";
	}
	case v3D: {
		return "v3D";
	}
	}
	return "EnumElement not part of: ImageType";
}
template<> auto enumToString(ImageViewType enumVal) -> std::string {
	using enum ImageViewType;
	switch (enumVal) {
	case v1D: {
		return "v1D";
	}
	case v2D: {
		return "v2D";
	}
	case v3D: {
		return "v3D";
	}
	case Cube: {
		return "Cube";
	}
	case v1DArray: {
		return "v1DArray";
	}
	case v2DArray: {
		return "v2DArray";
	}
	case CubeArray: {
		return "CubeArray";
	}
	}
	return "EnumElement not part of: ImageViewType";
}
template<> auto enumToString(IndexType enumVal) -> std::string {
	using enum IndexType;
	switch (enumVal) {
	case Uint16: {
		return "Uint16";
	}
	case Uint32: {
		return "Uint32";
	}
	case NoneKHR: {
		return "NoneKHR";
	}
	case Uint8: {
		return "Uint8";
	}
	}
	return "EnumElement not part of: IndexType";
}
template<> auto enumToString(IndirectCommandsTokenTypeEXT enumVal) -> std::string {
	using enum IndirectCommandsTokenTypeEXT;
	switch (enumVal) {
	case ExecutionSet: {
		return "ExecutionSet";
	}
	case PushConstant: {
		return "PushConstant";
	}
	case SequenceIndex: {
		return "SequenceIndex";
	}
	case IndexBuffer: {
		return "IndexBuffer";
	}
	case VertexBuffer: {
		return "VertexBuffer";
	}
	case DrawIndexed: {
		return "DrawIndexed";
	}
	case Draw: {
		return "Draw";
	}
	case DrawIndexedCount: {
		return "DrawIndexedCount";
	}
	case DrawCount: {
		return "DrawCount";
	}
	case Dispatch: {
		return "Dispatch";
	}
	case PushData: {
		return "PushData";
	}
	case PushDataSequenceIndex: {
		return "PushDataSequenceIndex";
	}
	case DrawMeshTasksNV: {
		return "DrawMeshTasksNV";
	}
	case DrawMeshTasksCountNV: {
		return "DrawMeshTasksCountNV";
	}
	case DrawMeshTasks: {
		return "DrawMeshTasks";
	}
	case DrawMeshTasksCount: {
		return "DrawMeshTasksCount";
	}
	case TraceRays2: {
		return "TraceRays2";
	}
	}
	return "EnumElement not part of: IndirectCommandsTokenTypeEXT";
}
template<> auto enumToString(IndirectCommandsTokenTypeNV enumVal) -> std::string {
	using enum IndirectCommandsTokenTypeNV;
	switch (enumVal) {
	case ShaderGroup: {
		return "ShaderGroup";
	}
	case StateFlags: {
		return "StateFlags";
	}
	case IndexBuffer: {
		return "IndexBuffer";
	}
	case VertexBuffer: {
		return "VertexBuffer";
	}
	case PushConstant: {
		return "PushConstant";
	}
	case DrawIndexed: {
		return "DrawIndexed";
	}
	case Draw: {
		return "Draw";
	}
	case DrawTasks: {
		return "DrawTasks";
	}
	case PushData: {
		return "PushData";
	}
	case DrawMeshTasks: {
		return "DrawMeshTasks";
	}
	case Pipeline: {
		return "Pipeline";
	}
	case Dispatch: {
		return "Dispatch";
	}
	}
	return "EnumElement not part of: IndirectCommandsTokenTypeNV";
}
template<> auto enumToString(IndirectExecutionSetInfoTypeEXT enumVal) -> std::string {
	using enum IndirectExecutionSetInfoTypeEXT;
	switch (enumVal) {
	case Pipelines: {
		return "Pipelines";
	}
	case ShaderObjects: {
		return "ShaderObjects";
	}
	}
	return "EnumElement not part of: IndirectExecutionSetInfoTypeEXT";
}
template<> auto enumToString(InternalAllocationType enumVal) -> std::string {
	using enum InternalAllocationType;
	switch (enumVal) {
	case Executable: {
		return "Executable";
	}
	}
	return "EnumElement not part of: InternalAllocationType";
}
template<> auto enumToString(LatencyMarkerNV enumVal) -> std::string {
	using enum LatencyMarkerNV;
	switch (enumVal) {
	case SimulationStart: {
		return "SimulationStart";
	}
	case SimulationEnd: {
		return "SimulationEnd";
	}
	case RendersubmitStart: {
		return "RendersubmitStart";
	}
	case RendersubmitEnd: {
		return "RendersubmitEnd";
	}
	case PresentStart: {
		return "PresentStart";
	}
	case PresentEnd: {
		return "PresentEnd";
	}
	case InputSample: {
		return "InputSample";
	}
	case TriggerFlash: {
		return "TriggerFlash";
	}
	case OutOfBandRendersubmitStart: {
		return "OutOfBandRendersubmitStart";
	}
	case OutOfBandRendersubmitEnd: {
		return "OutOfBandRendersubmitEnd";
	}
	case OutOfBandPresentStart: {
		return "OutOfBandPresentStart";
	}
	case OutOfBandPresentEnd: {
		return "OutOfBandPresentEnd";
	}
	}
	return "EnumElement not part of: LatencyMarkerNV";
}
template<> auto enumToString(LayerSettingTypeEXT enumVal) -> std::string {
	using enum LayerSettingTypeEXT;
	switch (enumVal) {
	case Bool32: {
		return "Bool32";
	}
	case Int32: {
		return "Int32";
	}
	case Int64: {
		return "Int64";
	}
	case Uint32: {
		return "Uint32";
	}
	case Uint64: {
		return "Uint64";
	}
	case Float32: {
		return "Float32";
	}
	case Float64: {
		return "Float64";
	}
	case String: {
		return "String";
	}
	}
	return "EnumElement not part of: LayerSettingTypeEXT";
}
template<> auto enumToString(LayeredDriverUnderlyingApiMSFT enumVal) -> std::string {
	using enum LayeredDriverUnderlyingApiMSFT;
	switch (enumVal) {
	case None: {
		return "None";
	}
	case D3D12: {
		return "D3D12";
	}
	}
	return "EnumElement not part of: LayeredDriverUnderlyingApiMSFT";
}
template<> auto enumToString(LineRasterizationMode enumVal) -> std::string {
	using enum LineRasterizationMode;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case Rectangular: {
		return "Rectangular";
	}
	case Bresenham: {
		return "Bresenham";
	}
	case RectangularSmooth: {
		return "RectangularSmooth";
	}
	}
	return "EnumElement not part of: LineRasterizationMode";
}
template<> auto enumToString(LogicOp enumVal) -> std::string {
	using enum LogicOp;
	switch (enumVal) {
	case Clear: {
		return "Clear";
	}
	case And: {
		return "And";
	}
	case AndReverse: {
		return "AndReverse";
	}
	case Copy: {
		return "Copy";
	}
	case AndInverted: {
		return "AndInverted";
	}
	case NoOp: {
		return "NoOp";
	}
	case Xor: {
		return "Xor";
	}
	case Or: {
		return "Or";
	}
	case Nor: {
		return "Nor";
	}
	case Equivalent: {
		return "Equivalent";
	}
	case Invert: {
		return "Invert";
	}
	case OrReverse: {
		return "OrReverse";
	}
	case CopyInverted: {
		return "CopyInverted";
	}
	case OrInverted: {
		return "OrInverted";
	}
	case Nand: {
		return "Nand";
	}
	case Set: {
		return "Set";
	}
	}
	return "EnumElement not part of: LogicOp";
}
template<> auto enumToString(MemoryOverallocationBehaviorAMD enumVal) -> std::string {
	using enum MemoryOverallocationBehaviorAMD;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case Allowed: {
		return "Allowed";
	}
	case Disallowed: {
		return "Disallowed";
	}
	}
	return "EnumElement not part of: MemoryOverallocationBehaviorAMD";
}
template<> auto enumToString(MicromapTypeEXT enumVal) -> std::string {
	using enum MicromapTypeEXT;
	switch (enumVal) {
	case OpacityMicromap: {
		return "OpacityMicromap";
	}
	case DisplacementMicromapNV: {
		return "DisplacementMicromapNV";
	}
	}
	return "EnumElement not part of: MicromapTypeEXT";
}
template<> auto enumToString(NeuralAcceleratorStatisticsModeARM enumVal) -> std::string {
	using enum NeuralAcceleratorStatisticsModeARM;
	switch (enumVal) {
	case Disabled: {
		return "Disabled";
	}
	case Statistics0: {
		return "Statistics0";
	}
	case Statistics1: {
		return "Statistics1";
	}
	}
	return "EnumElement not part of: NeuralAcceleratorStatisticsModeARM";
}
template<> auto enumToString(ObjectType enumVal) -> std::string {
	using enum ObjectType;
	switch (enumVal) {
	case Unknown: {
		return "Unknown";
	}
	case Instance: {
		return "Instance";
	}
	case PhysicalDevice: {
		return "PhysicalDevice";
	}
	case Device: {
		return "Device";
	}
	case Queue: {
		return "Queue";
	}
	case Semaphore: {
		return "Semaphore";
	}
	case CommandBuffer: {
		return "CommandBuffer";
	}
	case Fence: {
		return "Fence";
	}
	case DeviceMemory: {
		return "DeviceMemory";
	}
	case Buffer: {
		return "Buffer";
	}
	case Image: {
		return "Image";
	}
	case Event: {
		return "Event";
	}
	case QueryPool: {
		return "QueryPool";
	}
	case BufferView: {
		return "BufferView";
	}
	case ImageView: {
		return "ImageView";
	}
	case ShaderModule: {
		return "ShaderModule";
	}
	case PipelineCache: {
		return "PipelineCache";
	}
	case PipelineLayout: {
		return "PipelineLayout";
	}
	case RenderPass: {
		return "RenderPass";
	}
	case Pipeline: {
		return "Pipeline";
	}
	case DescriptorSetLayout: {
		return "DescriptorSetLayout";
	}
	case Sampler: {
		return "Sampler";
	}
	case DescriptorPool: {
		return "DescriptorPool";
	}
	case DescriptorSet: {
		return "DescriptorSet";
	}
	case Framebuffer: {
		return "Framebuffer";
	}
	case CommandPool: {
		return "CommandPool";
	}
	case SurfaceKHR: {
		return "SurfaceKHR";
	}
	case SwapchainKHR: {
		return "SwapchainKHR";
	}
	case DisplayKHR: {
		return "DisplayKHR";
	}
	case DisplayModeKHR: {
		return "DisplayModeKHR";
	}
	case DebugReportCallbackEXT: {
		return "DebugReportCallbackEXT";
	}
	case VideoSessionKHR: {
		return "VideoSessionKHR";
	}
	case VideoSessionParametersKHR: {
		return "VideoSessionParametersKHR";
	}
	case CuModuleNVX: {
		return "CuModuleNVX";
	}
	case CuFunctionNVX: {
		return "CuFunctionNVX";
	}
	case DescriptorUpdateTemplate: {
		return "DescriptorUpdateTemplate";
	}
	case DebugUtilsMessengerEXT: {
		return "DebugUtilsMessengerEXT";
	}
	case GpaSessionAMD: {
		return "GpaSessionAMD";
	}
	case AccelerationStructureKHR: {
		return "AccelerationStructureKHR";
	}
	case SamplerYcbcrConversion: {
		return "SamplerYcbcrConversion";
	}
	case ValidationCacheEXT: {
		return "ValidationCacheEXT";
	}
	case AccelerationStructureNV: {
		return "AccelerationStructureNV";
	}
	case PerformanceConfigurationINTEL: {
		return "PerformanceConfigurationINTEL";
	}
	case DeferredOperationKHR: {
		return "DeferredOperationKHR";
	}
	case IndirectCommandsLayoutNV: {
		return "IndirectCommandsLayoutNV";
	}
	case PrivateDataSlot: {
		return "PrivateDataSlot";
	}
	case CudaModuleNV: {
		return "CudaModuleNV";
	}
	case CudaFunctionNV: {
		return "CudaFunctionNV";
	}
	case BufferCollectionFUCHSIA: {
		return "BufferCollectionFUCHSIA";
	}
	case MicromapEXT: {
		return "MicromapEXT";
	}
	case TensorARM: {
		return "TensorARM";
	}
	case TensorViewARM: {
		return "TensorViewARM";
	}
	case OpticalFlowSessionNV: {
		return "OpticalFlowSessionNV";
	}
	case ShaderEXT: {
		return "ShaderEXT";
	}
	case PipelineBinaryKHR: {
		return "PipelineBinaryKHR";
	}
	case DataGraphPipelineSessionARM: {
		return "DataGraphPipelineSessionARM";
	}
	case ExternalComputeQueueNV: {
		return "ExternalComputeQueueNV";
	}
	case IndirectCommandsLayoutEXT: {
		return "IndirectCommandsLayoutEXT";
	}
	case IndirectExecutionSetEXT: {
		return "IndirectExecutionSetEXT";
	}
	case ShaderInstrumentationARM: {
		return "ShaderInstrumentationARM";
	}
	}
	return "EnumElement not part of: ObjectType";
}
template<> auto enumToString(OpacityMicromapFormatKHR enumVal) -> std::string {
	using enum OpacityMicromapFormatKHR;
	switch (enumVal) {
	case v2State: {
		return "v2State";
	}
	case v4State: {
		return "v4State";
	}
	}
	return "EnumElement not part of: OpacityMicromapFormatKHR";
}
template<> auto enumToString(OpacityMicromapSpecialIndexKHR enumVal) -> std::string {
	using enum OpacityMicromapSpecialIndexKHR;
	switch (enumVal) {
	case FullyTransparent: {
		return "FullyTransparent";
	}
	case FullyOpaque: {
		return "FullyOpaque";
	}
	case FullyUnknownTransparent: {
		return "FullyUnknownTransparent";
	}
	case FullyUnknownOpaque: {
		return "FullyUnknownOpaque";
	}
	case ClusterGeometryDisableOpacityMicromapNV: {
		return "ClusterGeometryDisableOpacityMicromapNV";
	}
	}
	return "EnumElement not part of: OpacityMicromapSpecialIndexKHR";
}
template<> auto enumToString(OpticalFlowPerformanceLevelNV enumVal) -> std::string {
	using enum OpticalFlowPerformanceLevelNV;
	switch (enumVal) {
	case Unknown: {
		return "Unknown";
	}
	case Slow: {
		return "Slow";
	}
	case Medium: {
		return "Medium";
	}
	case Fast: {
		return "Fast";
	}
	}
	return "EnumElement not part of: OpticalFlowPerformanceLevelNV";
}
template<> auto enumToString(OpticalFlowSessionBindingPointNV enumVal) -> std::string {
	using enum OpticalFlowSessionBindingPointNV;
	switch (enumVal) {
	case Unknown: {
		return "Unknown";
	}
	case Input: {
		return "Input";
	}
	case Reference: {
		return "Reference";
	}
	case Hint: {
		return "Hint";
	}
	case FlowVector: {
		return "FlowVector";
	}
	case BackwardFlowVector: {
		return "BackwardFlowVector";
	}
	case Cost: {
		return "Cost";
	}
	case BackwardCost: {
		return "BackwardCost";
	}
	case GlobalFlow: {
		return "GlobalFlow";
	}
	}
	return "EnumElement not part of: OpticalFlowSessionBindingPointNV";
}
template<> auto enumToString(OutOfBandQueueTypeNV enumVal) -> std::string {
	using enum OutOfBandQueueTypeNV;
	switch (enumVal) {
	case Render: {
		return "Render";
	}
	case Present: {
		return "Present";
	}
	}
	return "EnumElement not part of: OutOfBandQueueTypeNV";
}
template<> auto enumToString(PartitionedAccelerationStructureOpTypeNV enumVal) -> std::string {
	using enum PartitionedAccelerationStructureOpTypeNV;
	switch (enumVal) {
	case WriteInstance: {
		return "WriteInstance";
	}
	case UpdateInstance: {
		return "UpdateInstance";
	}
	case WritePartitionTranslation: {
		return "WritePartitionTranslation";
	}
	}
	return "EnumElement not part of: PartitionedAccelerationStructureOpTypeNV";
}
template<> auto enumToString(PerfHintTypeQCOM enumVal) -> std::string {
	using enum PerfHintTypeQCOM;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case FrequencyMin: {
		return "FrequencyMin";
	}
	case FrequencyMax: {
		return "FrequencyMax";
	}
	case FrequencyScaled: {
		return "FrequencyScaled";
	}
	}
	return "EnumElement not part of: PerfHintTypeQCOM";
}
template<> auto enumToString(PerformanceConfigurationTypeINTEL enumVal) -> std::string {
	using enum PerformanceConfigurationTypeINTEL;
	switch (enumVal) {
	case CommandQueueMetricsDiscoveryActivated: {
		return "CommandQueueMetricsDiscoveryActivated";
	}
	}
	return "EnumElement not part of: PerformanceConfigurationTypeINTEL";
}
template<> auto enumToString(PerformanceCounterScopeKHR enumVal) -> std::string {
	using enum PerformanceCounterScopeKHR;
	switch (enumVal) {
	case CommandBuffer: {
		return "CommandBuffer";
	}
	case RenderPass: {
		return "RenderPass";
	}
	case Command: {
		return "Command";
	}
	}
	return "EnumElement not part of: PerformanceCounterScopeKHR";
}
template<> auto enumToString(PerformanceCounterStorageKHR enumVal) -> std::string {
	using enum PerformanceCounterStorageKHR;
	switch (enumVal) {
	case Int32: {
		return "Int32";
	}
	case Int64: {
		return "Int64";
	}
	case Uint32: {
		return "Uint32";
	}
	case Uint64: {
		return "Uint64";
	}
	case Float32: {
		return "Float32";
	}
	case Float64: {
		return "Float64";
	}
	}
	return "EnumElement not part of: PerformanceCounterStorageKHR";
}
template<> auto enumToString(PerformanceCounterUnitKHR enumVal) -> std::string {
	using enum PerformanceCounterUnitKHR;
	switch (enumVal) {
	case Generic: {
		return "Generic";
	}
	case Percentage: {
		return "Percentage";
	}
	case Nanoseconds: {
		return "Nanoseconds";
	}
	case Bytes: {
		return "Bytes";
	}
	case BytesPerSecond: {
		return "BytesPerSecond";
	}
	case Kelvin: {
		return "Kelvin";
	}
	case Watts: {
		return "Watts";
	}
	case Volts: {
		return "Volts";
	}
	case Amps: {
		return "Amps";
	}
	case Hertz: {
		return "Hertz";
	}
	case Cycles: {
		return "Cycles";
	}
	}
	return "EnumElement not part of: PerformanceCounterUnitKHR";
}
template<> auto enumToString(PerformanceOverrideTypeINTEL enumVal) -> std::string {
	using enum PerformanceOverrideTypeINTEL;
	switch (enumVal) {
	case NullHardware: {
		return "NullHardware";
	}
	case FlushGpuCaches: {
		return "FlushGpuCaches";
	}
	}
	return "EnumElement not part of: PerformanceOverrideTypeINTEL";
}
template<> auto enumToString(PerformanceParameterTypeINTEL enumVal) -> std::string {
	using enum PerformanceParameterTypeINTEL;
	switch (enumVal) {
	case HwCountersSupported: {
		return "HwCountersSupported";
	}
	case StreamMarkerValidBits: {
		return "StreamMarkerValidBits";
	}
	}
	return "EnumElement not part of: PerformanceParameterTypeINTEL";
}
template<> auto enumToString(PerformanceValueTypeINTEL enumVal) -> std::string {
	using enum PerformanceValueTypeINTEL;
	switch (enumVal) {
	case Uint32: {
		return "Uint32";
	}
	case Uint64: {
		return "Uint64";
	}
	case Float: {
		return "Float";
	}
	case Bool: {
		return "Bool";
	}
	case String: {
		return "String";
	}
	}
	return "EnumElement not part of: PerformanceValueTypeINTEL";
}
template<> auto enumToString(PhysicalDeviceDataGraphOperationTypeARM enumVal) -> std::string {
	using enum PhysicalDeviceDataGraphOperationTypeARM;
	switch (enumVal) {
	case SpirvExtendedInstructionSet: {
		return "SpirvExtendedInstructionSet";
	}
	case NeuralModelQCOM: {
		return "NeuralModelQCOM";
	}
	case BuiltinModelQCOM: {
		return "BuiltinModelQCOM";
	}
	case OpticalFlow: {
		return "OpticalFlow";
	}
	}
	return "EnumElement not part of: PhysicalDeviceDataGraphOperationTypeARM";
}
template<> auto enumToString(PhysicalDeviceDataGraphProcessingEngineTypeARM enumVal) -> std::string {
	using enum PhysicalDeviceDataGraphProcessingEngineTypeARM;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case NeuralQCOM: {
		return "NeuralQCOM";
	}
	case ComputeQCOM: {
		return "ComputeQCOM";
	}
	}
	return "EnumElement not part of: PhysicalDeviceDataGraphProcessingEngineTypeARM";
}
template<> auto enumToString(PhysicalDeviceLayeredApiKHR enumVal) -> std::string {
	using enum PhysicalDeviceLayeredApiKHR;
	switch (enumVal) {
	case Vulkan: {
		return "Vulkan";
	}
	case D3D12: {
		return "D3D12";
	}
	case Metal: {
		return "Metal";
	}
	case Opengl: {
		return "Opengl";
	}
	case Opengles: {
		return "Opengles";
	}
	}
	return "EnumElement not part of: PhysicalDeviceLayeredApiKHR";
}
template<> auto enumToString(PhysicalDeviceType enumVal) -> std::string {
	using enum PhysicalDeviceType;
	switch (enumVal) {
	case Other: {
		return "Other";
	}
	case IntegratedGpu: {
		return "IntegratedGpu";
	}
	case DiscreteGpu: {
		return "DiscreteGpu";
	}
	case VirtualGpu: {
		return "VirtualGpu";
	}
	case Cpu: {
		return "Cpu";
	}
	}
	return "EnumElement not part of: PhysicalDeviceType";
}
template<> auto enumToString(PipelineBindPoint enumVal) -> std::string {
	using enum PipelineBindPoint;
	switch (enumVal) {
	case Graphics: {
		return "Graphics";
	}
	case Compute: {
		return "Compute";
	}
	case ExecutionGraphAMDX: {
		return "ExecutionGraphAMDX";
	}
	case RayTracingKHR: {
		return "RayTracingKHR";
	}
	case SubpassShadingHUAWEI: {
		return "SubpassShadingHUAWEI";
	}
	case DataGraphARM: {
		return "DataGraphARM";
	}
	}
	return "EnumElement not part of: PipelineBindPoint";
}
template<> auto enumToString(PipelineCacheHeaderVersion enumVal) -> std::string {
	using enum PipelineCacheHeaderVersion;
	switch (enumVal) {
	case One: {
		return "One";
	}
	case DataGraphQCOM: {
		return "DataGraphQCOM";
	}
	}
	return "EnumElement not part of: PipelineCacheHeaderVersion";
}
template<> auto enumToString(PipelineExecutableStatisticFormatKHR enumVal) -> std::string {
	using enum PipelineExecutableStatisticFormatKHR;
	switch (enumVal) {
	case Bool32: {
		return "Bool32";
	}
	case Int64: {
		return "Int64";
	}
	case Uint64: {
		return "Uint64";
	}
	case Float64: {
		return "Float64";
	}
	}
	return "EnumElement not part of: PipelineExecutableStatisticFormatKHR";
}
template<> auto enumToString(PipelineRobustnessBufferBehavior enumVal) -> std::string {
	using enum PipelineRobustnessBufferBehavior;
	switch (enumVal) {
	case DeviceDefault: {
		return "DeviceDefault";
	}
	case Disabled: {
		return "Disabled";
	}
	case RobustBufferAccess: {
		return "RobustBufferAccess";
	}
	case RobustBufferAccess2: {
		return "RobustBufferAccess2";
	}
	}
	return "EnumElement not part of: PipelineRobustnessBufferBehavior";
}
template<> auto enumToString(PipelineRobustnessImageBehavior enumVal) -> std::string {
	using enum PipelineRobustnessImageBehavior;
	switch (enumVal) {
	case DeviceDefault: {
		return "DeviceDefault";
	}
	case Disabled: {
		return "Disabled";
	}
	case RobustImageAccess: {
		return "RobustImageAccess";
	}
	case RobustImageAccess2: {
		return "RobustImageAccess2";
	}
	}
	return "EnumElement not part of: PipelineRobustnessImageBehavior";
}
template<> auto enumToString(PointClippingBehavior enumVal) -> std::string {
	using enum PointClippingBehavior;
	switch (enumVal) {
	case AllClipPlanes: {
		return "AllClipPlanes";
	}
	case UserClipPlanesOnly: {
		return "UserClipPlanesOnly";
	}
	}
	return "EnumElement not part of: PointClippingBehavior";
}
template<> auto enumToString(PolygonMode enumVal) -> std::string {
	using enum PolygonMode;
	switch (enumVal) {
	case Fill: {
		return "Fill";
	}
	case Line: {
		return "Line";
	}
	case Point: {
		return "Point";
	}
	case FillRectangleNV: {
		return "FillRectangleNV";
	}
	}
	return "EnumElement not part of: PolygonMode";
}
template<> auto enumToString(PresentModeKHR enumVal) -> std::string {
	using enum PresentModeKHR;
	switch (enumVal) {
	case Immediate: {
		return "Immediate";
	}
	case Mailbox: {
		return "Mailbox";
	}
	case Fifo: {
		return "Fifo";
	}
	case FifoRelaxed: {
		return "FifoRelaxed";
	}
	case SharedDemandRefresh: {
		return "SharedDemandRefresh";
	}
	case SharedContinuousRefresh: {
		return "SharedContinuousRefresh";
	}
	case FifoLatestReady: {
		return "FifoLatestReady";
	}
	}
	return "EnumElement not part of: PresentModeKHR";
}
template<> auto enumToString(PrimitiveTopology enumVal) -> std::string {
	using enum PrimitiveTopology;
	switch (enumVal) {
	case PointList: {
		return "PointList";
	}
	case LineList: {
		return "LineList";
	}
	case LineStrip: {
		return "LineStrip";
	}
	case TriangleList: {
		return "TriangleList";
	}
	case TriangleStrip: {
		return "TriangleStrip";
	}
	case TriangleFan: {
		return "TriangleFan";
	}
	case LineListWithAdjacency: {
		return "LineListWithAdjacency";
	}
	case LineStripWithAdjacency: {
		return "LineStripWithAdjacency";
	}
	case TriangleListWithAdjacency: {
		return "TriangleListWithAdjacency";
	}
	case TriangleStripWithAdjacency: {
		return "TriangleStripWithAdjacency";
	}
	case PatchList: {
		return "PatchList";
	}
	}
	return "EnumElement not part of: PrimitiveTopology";
}
template<> auto enumToString(ProvokingVertexModeEXT enumVal) -> std::string {
	using enum ProvokingVertexModeEXT;
	switch (enumVal) {
	case FirstVertex: {
		return "FirstVertex";
	}
	case LastVertex: {
		return "LastVertex";
	}
	}
	return "EnumElement not part of: ProvokingVertexModeEXT";
}
template<> auto enumToString(QueryPoolSamplingModeINTEL enumVal) -> std::string {
	using enum QueryPoolSamplingModeINTEL;
	switch (enumVal) {
	case Manual: {
		return "Manual";
	}
	}
	return "EnumElement not part of: QueryPoolSamplingModeINTEL";
}
template<> auto enumToString(QueryResultStatusKHR enumVal) -> std::string {
	using enum QueryResultStatusKHR;
	switch (enumVal) {
	case NotReady: {
		return "NotReady";
	}
	case Complete: {
		return "Complete";
	}
	case Error: {
		return "Error";
	}
	case InsufficientBitstreamBufferRange: {
		return "InsufficientBitstreamBufferRange";
	}
	}
	return "EnumElement not part of: QueryResultStatusKHR";
}
template<> auto enumToString(QueryType enumVal) -> std::string {
	using enum QueryType;
	switch (enumVal) {
	case Occlusion: {
		return "Occlusion";
	}
	case PipelineStatistics: {
		return "PipelineStatistics";
	}
	case Timestamp: {
		return "Timestamp";
	}
	case ResultStatusOnlyKHR: {
		return "ResultStatusOnlyKHR";
	}
	case TransformFeedbackStreamEXT: {
		return "TransformFeedbackStreamEXT";
	}
	case PerformanceQueryKHR: {
		return "PerformanceQueryKHR";
	}
	case AccelerationStructureCompactedSizeKHR: {
		return "AccelerationStructureCompactedSizeKHR";
	}
	case AccelerationStructureSerializationSizeKHR: {
		return "AccelerationStructureSerializationSizeKHR";
	}
	case AccelerationStructureCompactedSizeNV: {
		return "AccelerationStructureCompactedSizeNV";
	}
	case TimeElapsedQCOM: {
		return "TimeElapsedQCOM";
	}
	case PerformanceQueryINTEL: {
		return "PerformanceQueryINTEL";
	}
	case VideoEncodeFeedbackKHR: {
		return "VideoEncodeFeedbackKHR";
	}
	case MeshPrimitivesGeneratedEXT: {
		return "MeshPrimitivesGeneratedEXT";
	}
	case PrimitivesGeneratedEXT: {
		return "PrimitivesGeneratedEXT";
	}
	case AccelerationStructureSerializationBottomLevelPointersKHR: {
		return "AccelerationStructureSerializationBottomLevelPointersKHR";
	}
	case AccelerationStructureSizeKHR: {
		return "AccelerationStructureSizeKHR";
	}
	case MicromapSerializationSizeEXT: {
		return "MicromapSerializationSizeEXT";
	}
	case MicromapCompactedSizeEXT: {
		return "MicromapCompactedSizeEXT";
	}
	}
	return "EnumElement not part of: QueryType";
}
template<> auto enumToString(QueueGlobalPriority enumVal) -> std::string {
	using enum QueueGlobalPriority;
	switch (enumVal) {
	case Low: {
		return "Low";
	}
	case Medium: {
		return "Medium";
	}
	case High: {
		return "High";
	}
	case Realtime: {
		return "Realtime";
	}
	}
	return "EnumElement not part of: QueueGlobalPriority";
}
template<> auto enumToString(RasterizationOrderAMD enumVal) -> std::string {
	using enum RasterizationOrderAMD;
	switch (enumVal) {
	case Strict: {
		return "Strict";
	}
	case Relaxed: {
		return "Relaxed";
	}
	}
	return "EnumElement not part of: RasterizationOrderAMD";
}
template<> auto enumToString(RayTracingInvocationReorderModeEXT enumVal) -> std::string {
	using enum RayTracingInvocationReorderModeEXT;
	switch (enumVal) {
	case None: {
		return "None";
	}
	case Reorder: {
		return "Reorder";
	}
	}
	return "EnumElement not part of: RayTracingInvocationReorderModeEXT";
}
template<> auto enumToString(RayTracingLssIndexingModeNV enumVal) -> std::string {
	using enum RayTracingLssIndexingModeNV;
	switch (enumVal) {
	case List: {
		return "List";
	}
	case Successive: {
		return "Successive";
	}
	}
	return "EnumElement not part of: RayTracingLssIndexingModeNV";
}
template<> auto enumToString(RayTracingLssPrimitiveEndCapsModeNV enumVal) -> std::string {
	using enum RayTracingLssPrimitiveEndCapsModeNV;
	switch (enumVal) {
	case None: {
		return "None";
	}
	case Chained: {
		return "Chained";
	}
	}
	return "EnumElement not part of: RayTracingLssPrimitiveEndCapsModeNV";
}
template<> auto enumToString(RayTracingShaderGroupTypeKHR enumVal) -> std::string {
	using enum RayTracingShaderGroupTypeKHR;
	switch (enumVal) {
	case General: {
		return "General";
	}
	case TrianglesHitGroup: {
		return "TrianglesHitGroup";
	}
	case ProceduralHitGroup: {
		return "ProceduralHitGroup";
	}
	}
	return "EnumElement not part of: RayTracingShaderGroupTypeKHR";
}
template<> auto enumToString(Result enumVal) -> std::string {
	using enum Result;
	switch (enumVal) {
	case Success: {
		return "Success";
	}
	case NotReady: {
		return "NotReady";
	}
	case Timeout: {
		return "Timeout";
	}
	case EventSet: {
		return "EventSet";
	}
	case EventReset: {
		return "EventReset";
	}
	case Incomplete: {
		return "Incomplete";
	}
	case ErrorOutOfHostMemory: {
		return "ErrorOutOfHostMemory";
	}
	case ErrorOutOfDeviceMemory: {
		return "ErrorOutOfDeviceMemory";
	}
	case ErrorInitializationFailed: {
		return "ErrorInitializationFailed";
	}
	case ErrorDeviceLost: {
		return "ErrorDeviceLost";
	}
	case ErrorMemoryMapFailed: {
		return "ErrorMemoryMapFailed";
	}
	case ErrorLayerNotPresent: {
		return "ErrorLayerNotPresent";
	}
	case ErrorExtensionNotPresent: {
		return "ErrorExtensionNotPresent";
	}
	case ErrorFeatureNotPresent: {
		return "ErrorFeatureNotPresent";
	}
	case ErrorIncompatibleDriver: {
		return "ErrorIncompatibleDriver";
	}
	case ErrorTooManyObjects: {
		return "ErrorTooManyObjects";
	}
	case ErrorFormatNotSupported: {
		return "ErrorFormatNotSupported";
	}
	case ErrorFragmentedPool: {
		return "ErrorFragmentedPool";
	}
	case ErrorUnknown: {
		return "ErrorUnknown";
	}
	case ErrorSurfaceLostKHR: {
		return "ErrorSurfaceLostKHR";
	}
	case ErrorNativeWindowInUseKHR: {
		return "ErrorNativeWindowInUseKHR";
	}
	case ErrorOutOfDateKHR: {
		return "ErrorOutOfDateKHR";
	}
	case ErrorIncompatibleDisplayKHR: {
		return "ErrorIncompatibleDisplayKHR";
	}
	case ErrorValidationFailed: {
		return "ErrorValidationFailed";
	}
	case ErrorInvalidShaderNV: {
		return "ErrorInvalidShaderNV";
	}
	case ErrorImageUsageNotSupportedKHR: {
		return "ErrorImageUsageNotSupportedKHR";
	}
	case ErrorVideoPictureLayoutNotSupportedKHR: {
		return "ErrorVideoPictureLayoutNotSupportedKHR";
	}
	case ErrorVideoProfileOperationNotSupportedKHR: {
		return "ErrorVideoProfileOperationNotSupportedKHR";
	}
	case ErrorVideoProfileFormatNotSupportedKHR: {
		return "ErrorVideoProfileFormatNotSupportedKHR";
	}
	case ErrorVideoProfileCodecNotSupportedKHR: {
		return "ErrorVideoProfileCodecNotSupportedKHR";
	}
	case ErrorVideoStdVersionNotSupportedKHR: {
		return "ErrorVideoStdVersionNotSupportedKHR";
	}
	case ErrorOutOfPoolMemory: {
		return "ErrorOutOfPoolMemory";
	}
	case ErrorInvalidExternalHandle: {
		return "ErrorInvalidExternalHandle";
	}
	case ErrorInvalidDrmFormatModifierPlaneLayoutEXT: {
		return "ErrorInvalidDrmFormatModifierPlaneLayoutEXT";
	}
	case ErrorFragmentation: {
		return "ErrorFragmentation";
	}
	case ErrorNotPermitted: {
		return "ErrorNotPermitted";
	}
	case ErrorPresentTimingQueueFullEXT: {
		return "ErrorPresentTimingQueueFullEXT";
	}
	case ErrorFullScreenExclusiveModeLostEXT: {
		return "ErrorFullScreenExclusiveModeLostEXT";
	}
	case ErrorInvalidOpaqueCaptureAddress: {
		return "ErrorInvalidOpaqueCaptureAddress";
	}
	case ErrorInvalidVideoStdParametersKHR: {
		return "ErrorInvalidVideoStdParametersKHR";
	}
	case ErrorCompressionExhaustedEXT: {
		return "ErrorCompressionExhaustedEXT";
	}
	case ErrorNotEnoughSpaceKHR: {
		return "ErrorNotEnoughSpaceKHR";
	}
	case SuboptimalKHR: {
		return "SuboptimalKHR";
	}
	case ThreadIdleKHR: {
		return "ThreadIdleKHR";
	}
	case ThreadDoneKHR: {
		return "ThreadDoneKHR";
	}
	case OperationDeferredKHR: {
		return "OperationDeferredKHR";
	}
	case OperationNotDeferredKHR: {
		return "OperationNotDeferredKHR";
	}
	case PipelineCompileRequired: {
		return "PipelineCompileRequired";
	}
	case IncompatibleShaderBinaryEXT: {
		return "IncompatibleShaderBinaryEXT";
	}
	case PipelineBinaryMissingKHR: {
		return "PipelineBinaryMissingKHR";
	}
	}
	return "EnumElement not part of: Result";
}
template<> auto enumToString(SamplerAddressMode enumVal) -> std::string {
	using enum SamplerAddressMode;
	switch (enumVal) {
	case Repeat: {
		return "Repeat";
	}
	case MirroredRepeat: {
		return "MirroredRepeat";
	}
	case ClampToEdge: {
		return "ClampToEdge";
	}
	case ClampToBorder: {
		return "ClampToBorder";
	}
	case MirrorClampToEdge: {
		return "MirrorClampToEdge";
	}
	}
	return "EnumElement not part of: SamplerAddressMode";
}
template<> auto enumToString(SamplerMipmapMode enumVal) -> std::string {
	using enum SamplerMipmapMode;
	switch (enumVal) {
	case Nearest: {
		return "Nearest";
	}
	case Linear: {
		return "Linear";
	}
	}
	return "EnumElement not part of: SamplerMipmapMode";
}
template<> auto enumToString(SamplerReductionMode enumVal) -> std::string {
	using enum SamplerReductionMode;
	switch (enumVal) {
	case WeightedAverage: {
		return "WeightedAverage";
	}
	case Min: {
		return "Min";
	}
	case Max: {
		return "Max";
	}
	case WeightedAverageRangeclampQCOM: {
		return "WeightedAverageRangeclampQCOM";
	}
	}
	return "EnumElement not part of: SamplerReductionMode";
}
template<> auto enumToString(SamplerYcbcrModelConversion enumVal) -> std::string {
	using enum SamplerYcbcrModelConversion;
	switch (enumVal) {
	case RgbIdentity: {
		return "RgbIdentity";
	}
	case YcbcrIdentity: {
		return "YcbcrIdentity";
	}
	case Ycbcr709: {
		return "Ycbcr709";
	}
	case Ycbcr601: {
		return "Ycbcr601";
	}
	case Ycbcr2020: {
		return "Ycbcr2020";
	}
	}
	return "EnumElement not part of: SamplerYcbcrModelConversion";
}
template<> auto enumToString(SamplerYcbcrRange enumVal) -> std::string {
	using enum SamplerYcbcrRange;
	switch (enumVal) {
	case ItuFull: {
		return "ItuFull";
	}
	case ItuNarrow: {
		return "ItuNarrow";
	}
	}
	return "EnumElement not part of: SamplerYcbcrRange";
}
template<> auto enumToString(ScopeKHR enumVal) -> std::string {
	using enum ScopeKHR;
	switch (enumVal) {
	case Device: {
		return "Device";
	}
	case Workgroup: {
		return "Workgroup";
	}
	case Subgroup: {
		return "Subgroup";
	}
	case QueueFamily: {
		return "QueueFamily";
	}
	}
	return "EnumElement not part of: ScopeKHR";
}
template<> auto enumToString(SemaphoreType enumVal) -> std::string {
	using enum SemaphoreType;
	switch (enumVal) {
	case Binary: {
		return "Binary";
	}
	case Timeline: {
		return "Timeline";
	}
	}
	return "EnumElement not part of: SemaphoreType";
}
template<> auto enumToString(ShaderCodeTypeEXT enumVal) -> std::string {
	using enum ShaderCodeTypeEXT;
	switch (enumVal) {
	case Binary: {
		return "Binary";
	}
	case Spirv: {
		return "Spirv";
	}
	}
	return "EnumElement not part of: ShaderCodeTypeEXT";
}
template<> auto enumToString(ShaderFloatControlsIndependence enumVal) -> std::string {
	using enum ShaderFloatControlsIndependence;
	switch (enumVal) {
	case v32BitOnly: {
		return "v32BitOnly";
	}
	case All: {
		return "All";
	}
	case None: {
		return "None";
	}
	}
	return "EnumElement not part of: ShaderFloatControlsIndependence";
}
template<> auto enumToString(ShaderGroupShaderKHR enumVal) -> std::string {
	using enum ShaderGroupShaderKHR;
	switch (enumVal) {
	case General: {
		return "General";
	}
	case ClosestHit: {
		return "ClosestHit";
	}
	case AnyHit: {
		return "AnyHit";
	}
	case Intersection: {
		return "Intersection";
	}
	}
	return "EnumElement not part of: ShaderGroupShaderKHR";
}
template<> auto enumToString(ShaderInfoTypeAMD enumVal) -> std::string {
	using enum ShaderInfoTypeAMD;
	switch (enumVal) {
	case Statistics: {
		return "Statistics";
	}
	case Binary: {
		return "Binary";
	}
	case Disassembly: {
		return "Disassembly";
	}
	}
	return "EnumElement not part of: ShaderInfoTypeAMD";
}
template<> auto enumToString(ShadingRatePaletteEntryNV enumVal) -> std::string {
	using enum ShadingRatePaletteEntryNV;
	switch (enumVal) {
	case NoInvocations: {
		return "NoInvocations";
	}
	case v16InvocationsPerPixel: {
		return "v16InvocationsPerPixel";
	}
	case v8InvocationsPerPixel: {
		return "v8InvocationsPerPixel";
	}
	case v4InvocationsPerPixel: {
		return "v4InvocationsPerPixel";
	}
	case v2InvocationsPerPixel: {
		return "v2InvocationsPerPixel";
	}
	case v1InvocationPerPixel: {
		return "v1InvocationPerPixel";
	}
	case v1InvocationPer2x1Pixels: {
		return "v1InvocationPer2x1Pixels";
	}
	case v1InvocationPer1x2Pixels: {
		return "v1InvocationPer1x2Pixels";
	}
	case v1InvocationPer2x2Pixels: {
		return "v1InvocationPer2x2Pixels";
	}
	case v1InvocationPer4x2Pixels: {
		return "v1InvocationPer4x2Pixels";
	}
	case v1InvocationPer2x4Pixels: {
		return "v1InvocationPer2x4Pixels";
	}
	case v1InvocationPer4x4Pixels: {
		return "v1InvocationPer4x4Pixels";
	}
	}
	return "EnumElement not part of: ShadingRatePaletteEntryNV";
}
template<> auto enumToString(SharingMode enumVal) -> std::string {
	using enum SharingMode;
	switch (enumVal) {
	case Exclusive: {
		return "Exclusive";
	}
	case Concurrent: {
		return "Concurrent";
	}
	}
	return "EnumElement not part of: SharingMode";
}
template<> auto enumToString(StencilOp enumVal) -> std::string {
	using enum StencilOp;
	switch (enumVal) {
	case Keep: {
		return "Keep";
	}
	case Zero: {
		return "Zero";
	}
	case Replace: {
		return "Replace";
	}
	case IncrementAndClamp: {
		return "IncrementAndClamp";
	}
	case DecrementAndClamp: {
		return "DecrementAndClamp";
	}
	case Invert: {
		return "Invert";
	}
	case IncrementAndWrap: {
		return "IncrementAndWrap";
	}
	case DecrementAndWrap: {
		return "DecrementAndWrap";
	}
	}
	return "EnumElement not part of: StencilOp";
}
template<> auto enumToString(StructureType enumVal) -> std::string {
	using enum StructureType;
	switch (enumVal) {
	case ApplicationInfo: {
		return "ApplicationInfo";
	}
	case InstanceCreateInfo: {
		return "InstanceCreateInfo";
	}
	case DeviceQueueCreateInfo: {
		return "DeviceQueueCreateInfo";
	}
	case DeviceCreateInfo: {
		return "DeviceCreateInfo";
	}
	case SubmitInfo: {
		return "SubmitInfo";
	}
	case MemoryAllocateInfo: {
		return "MemoryAllocateInfo";
	}
	case MappedMemoryRange: {
		return "MappedMemoryRange";
	}
	case BindSparseInfo: {
		return "BindSparseInfo";
	}
	case FenceCreateInfo: {
		return "FenceCreateInfo";
	}
	case SemaphoreCreateInfo: {
		return "SemaphoreCreateInfo";
	}
	case EventCreateInfo: {
		return "EventCreateInfo";
	}
	case QueryPoolCreateInfo: {
		return "QueryPoolCreateInfo";
	}
	case BufferCreateInfo: {
		return "BufferCreateInfo";
	}
	case BufferViewCreateInfo: {
		return "BufferViewCreateInfo";
	}
	case ImageCreateInfo: {
		return "ImageCreateInfo";
	}
	case ImageViewCreateInfo: {
		return "ImageViewCreateInfo";
	}
	case ShaderModuleCreateInfo: {
		return "ShaderModuleCreateInfo";
	}
	case PipelineCacheCreateInfo: {
		return "PipelineCacheCreateInfo";
	}
	case PipelineShaderStageCreateInfo: {
		return "PipelineShaderStageCreateInfo";
	}
	case PipelineVertexInputStateCreateInfo: {
		return "PipelineVertexInputStateCreateInfo";
	}
	case PipelineInputAssemblyStateCreateInfo: {
		return "PipelineInputAssemblyStateCreateInfo";
	}
	case PipelineTessellationStateCreateInfo: {
		return "PipelineTessellationStateCreateInfo";
	}
	case PipelineViewportStateCreateInfo: {
		return "PipelineViewportStateCreateInfo";
	}
	case PipelineRasterizationStateCreateInfo: {
		return "PipelineRasterizationStateCreateInfo";
	}
	case PipelineMultisampleStateCreateInfo: {
		return "PipelineMultisampleStateCreateInfo";
	}
	case PipelineDepthStencilStateCreateInfo: {
		return "PipelineDepthStencilStateCreateInfo";
	}
	case PipelineColorBlendStateCreateInfo: {
		return "PipelineColorBlendStateCreateInfo";
	}
	case PipelineDynamicStateCreateInfo: {
		return "PipelineDynamicStateCreateInfo";
	}
	case GraphicsPipelineCreateInfo: {
		return "GraphicsPipelineCreateInfo";
	}
	case ComputePipelineCreateInfo: {
		return "ComputePipelineCreateInfo";
	}
	case PipelineLayoutCreateInfo: {
		return "PipelineLayoutCreateInfo";
	}
	case SamplerCreateInfo: {
		return "SamplerCreateInfo";
	}
	case DescriptorSetLayoutCreateInfo: {
		return "DescriptorSetLayoutCreateInfo";
	}
	case DescriptorPoolCreateInfo: {
		return "DescriptorPoolCreateInfo";
	}
	case DescriptorSetAllocateInfo: {
		return "DescriptorSetAllocateInfo";
	}
	case WriteDescriptorSet: {
		return "WriteDescriptorSet";
	}
	case CopyDescriptorSet: {
		return "CopyDescriptorSet";
	}
	case FramebufferCreateInfo: {
		return "FramebufferCreateInfo";
	}
	case RenderPassCreateInfo: {
		return "RenderPassCreateInfo";
	}
	case CommandPoolCreateInfo: {
		return "CommandPoolCreateInfo";
	}
	case CommandBufferAllocateInfo: {
		return "CommandBufferAllocateInfo";
	}
	case CommandBufferInheritanceInfo: {
		return "CommandBufferInheritanceInfo";
	}
	case CommandBufferBeginInfo: {
		return "CommandBufferBeginInfo";
	}
	case RenderPassBeginInfo: {
		return "RenderPassBeginInfo";
	}
	case BufferMemoryBarrier: {
		return "BufferMemoryBarrier";
	}
	case ImageMemoryBarrier: {
		return "ImageMemoryBarrier";
	}
	case MemoryBarrier: {
		return "MemoryBarrier";
	}
	case LoaderInstanceCreateInfo: {
		return "LoaderInstanceCreateInfo";
	}
	case LoaderDeviceCreateInfo: {
		return "LoaderDeviceCreateInfo";
	}
	case PhysicalDeviceVulkan11Features: {
		return "PhysicalDeviceVulkan11Features";
	}
	case PhysicalDeviceVulkan11Properties: {
		return "PhysicalDeviceVulkan11Properties";
	}
	case PhysicalDeviceVulkan12Features: {
		return "PhysicalDeviceVulkan12Features";
	}
	case PhysicalDeviceVulkan12Properties: {
		return "PhysicalDeviceVulkan12Properties";
	}
	case PhysicalDeviceVulkan13Features: {
		return "PhysicalDeviceVulkan13Features";
	}
	case PhysicalDeviceVulkan13Properties: {
		return "PhysicalDeviceVulkan13Properties";
	}
	case PhysicalDeviceVulkan14Features: {
		return "PhysicalDeviceVulkan14Features";
	}
	case PhysicalDeviceVulkan14Properties: {
		return "PhysicalDeviceVulkan14Properties";
	}
	case SwapchainCreateInfoKHR: {
		return "SwapchainCreateInfoKHR";
	}
	case PresentInfoKHR: {
		return "PresentInfoKHR";
	}
	case DisplayModeCreateInfoKHR: {
		return "DisplayModeCreateInfoKHR";
	}
	case DisplaySurfaceCreateInfoKHR: {
		return "DisplaySurfaceCreateInfoKHR";
	}
	case DisplayPresentInfoKHR: {
		return "DisplayPresentInfoKHR";
	}
	case XlibSurfaceCreateInfoKHR: {
		return "XlibSurfaceCreateInfoKHR";
	}
	case XcbSurfaceCreateInfoKHR: {
		return "XcbSurfaceCreateInfoKHR";
	}
	case WaylandSurfaceCreateInfoKHR: {
		return "WaylandSurfaceCreateInfoKHR";
	}
	case ANDROIDSurfaceCreateInfoKHR: {
		return "ANDROIDSurfaceCreateInfoKHR";
	}
	case Win32SurfaceCreateInfoKHR: {
		return "Win32SurfaceCreateInfoKHR";
	}
	case DebugReportCallbackCreateInfoEXT: {
		return "DebugReportCallbackCreateInfoEXT";
	}
	case PipelineRasterizationStateRasterizationOrderAMD: {
		return "PipelineRasterizationStateRasterizationOrderAMD";
	}
	case DebugMarkerObjectNameInfoEXT: {
		return "DebugMarkerObjectNameInfoEXT";
	}
	case DebugMarkerObjectTagInfoEXT: {
		return "DebugMarkerObjectTagInfoEXT";
	}
	case DebugMarkerMarkerInfoEXT: {
		return "DebugMarkerMarkerInfoEXT";
	}
	case VideoProfileInfoKHR: {
		return "VideoProfileInfoKHR";
	}
	case VideoCapabilitiesKHR: {
		return "VideoCapabilitiesKHR";
	}
	case VideoPictureResourceInfoKHR: {
		return "VideoPictureResourceInfoKHR";
	}
	case VideoSessionMemoryRequirementsKHR: {
		return "VideoSessionMemoryRequirementsKHR";
	}
	case BindVideoSessionMemoryInfoKHR: {
		return "BindVideoSessionMemoryInfoKHR";
	}
	case VideoSessionCreateInfoKHR: {
		return "VideoSessionCreateInfoKHR";
	}
	case VideoSessionParametersCreateInfoKHR: {
		return "VideoSessionParametersCreateInfoKHR";
	}
	case VideoSessionParametersUpdateInfoKHR: {
		return "VideoSessionParametersUpdateInfoKHR";
	}
	case VideoBeginCodingInfoKHR: {
		return "VideoBeginCodingInfoKHR";
	}
	case VideoEndCodingInfoKHR: {
		return "VideoEndCodingInfoKHR";
	}
	case VideoCodingControlInfoKHR: {
		return "VideoCodingControlInfoKHR";
	}
	case VideoReferenceSlotInfoKHR: {
		return "VideoReferenceSlotInfoKHR";
	}
	case QueueFamilyVideoPropertiesKHR: {
		return "QueueFamilyVideoPropertiesKHR";
	}
	case VideoProfileListInfoKHR: {
		return "VideoProfileListInfoKHR";
	}
	case PhysicalDeviceVideoFormatInfoKHR: {
		return "PhysicalDeviceVideoFormatInfoKHR";
	}
	case VideoFormatPropertiesKHR: {
		return "VideoFormatPropertiesKHR";
	}
	case QueueFamilyQueryResultStatusPropertiesKHR: {
		return "QueueFamilyQueryResultStatusPropertiesKHR";
	}
	case VideoDecodeInfoKHR: {
		return "VideoDecodeInfoKHR";
	}
	case VideoDecodeCapabilitiesKHR: {
		return "VideoDecodeCapabilitiesKHR";
	}
	case VideoDecodeUsageInfoKHR: {
		return "VideoDecodeUsageInfoKHR";
	}
	case DedicatedAllocationImageCreateInfoNV: {
		return "DedicatedAllocationImageCreateInfoNV";
	}
	case DedicatedAllocationBufferCreateInfoNV: {
		return "DedicatedAllocationBufferCreateInfoNV";
	}
	case DedicatedAllocationMemoryAllocateInfoNV: {
		return "DedicatedAllocationMemoryAllocateInfoNV";
	}
	case PhysicalDeviceTransformFeedbackFeaturesEXT: {
		return "PhysicalDeviceTransformFeedbackFeaturesEXT";
	}
	case PhysicalDeviceTransformFeedbackPropertiesEXT: {
		return "PhysicalDeviceTransformFeedbackPropertiesEXT";
	}
	case PipelineRasterizationStateStreamCreateInfoEXT: {
		return "PipelineRasterizationStateStreamCreateInfoEXT";
	}
	case CuModuleCreateInfoNVX: {
		return "CuModuleCreateInfoNVX";
	}
	case CuFunctionCreateInfoNVX: {
		return "CuFunctionCreateInfoNVX";
	}
	case CuLaunchInfoNVX: {
		return "CuLaunchInfoNVX";
	}
	case CuModuleTexturingModeCreateInfoNVX: {
		return "CuModuleTexturingModeCreateInfoNVX";
	}
	case ImageViewHandleInfoNVX: {
		return "ImageViewHandleInfoNVX";
	}
	case ImageViewAddressPropertiesNVX: {
		return "ImageViewAddressPropertiesNVX";
	}
	case VideoEncodeH264CapabilitiesKHR: {
		return "VideoEncodeH264CapabilitiesKHR";
	}
	case VideoEncodeH264SessionParametersCreateInfoKHR: {
		return "VideoEncodeH264SessionParametersCreateInfoKHR";
	}
	case VideoEncodeH264SessionParametersAddInfoKHR: {
		return "VideoEncodeH264SessionParametersAddInfoKHR";
	}
	case VideoEncodeH264PictureInfoKHR: {
		return "VideoEncodeH264PictureInfoKHR";
	}
	case VideoEncodeH264DpbSlotInfoKHR: {
		return "VideoEncodeH264DpbSlotInfoKHR";
	}
	case VideoEncodeH264NaluSliceInfoKHR: {
		return "VideoEncodeH264NaluSliceInfoKHR";
	}
	case VideoEncodeH264GopRemainingFrameInfoKHR: {
		return "VideoEncodeH264GopRemainingFrameInfoKHR";
	}
	case VideoEncodeH264ProfileInfoKHR: {
		return "VideoEncodeH264ProfileInfoKHR";
	}
	case VideoEncodeH264RateControlInfoKHR: {
		return "VideoEncodeH264RateControlInfoKHR";
	}
	case VideoEncodeH264RateControlLayerInfoKHR: {
		return "VideoEncodeH264RateControlLayerInfoKHR";
	}
	case VideoEncodeH264SessionCreateInfoKHR: {
		return "VideoEncodeH264SessionCreateInfoKHR";
	}
	case VideoEncodeH264QualityLevelPropertiesKHR: {
		return "VideoEncodeH264QualityLevelPropertiesKHR";
	}
	case VideoEncodeH264SessionParametersGetInfoKHR: {
		return "VideoEncodeH264SessionParametersGetInfoKHR";
	}
	case VideoEncodeH264SessionParametersFeedbackInfoKHR: {
		return "VideoEncodeH264SessionParametersFeedbackInfoKHR";
	}
	case VideoEncodeH265CapabilitiesKHR: {
		return "VideoEncodeH265CapabilitiesKHR";
	}
	case VideoEncodeH265SessionParametersCreateInfoKHR: {
		return "VideoEncodeH265SessionParametersCreateInfoKHR";
	}
	case VideoEncodeH265SessionParametersAddInfoKHR: {
		return "VideoEncodeH265SessionParametersAddInfoKHR";
	}
	case VideoEncodeH265PictureInfoKHR: {
		return "VideoEncodeH265PictureInfoKHR";
	}
	case VideoEncodeH265DpbSlotInfoKHR: {
		return "VideoEncodeH265DpbSlotInfoKHR";
	}
	case VideoEncodeH265NaluSliceSegmentInfoKHR: {
		return "VideoEncodeH265NaluSliceSegmentInfoKHR";
	}
	case VideoEncodeH265GopRemainingFrameInfoKHR: {
		return "VideoEncodeH265GopRemainingFrameInfoKHR";
	}
	case VideoEncodeH265ProfileInfoKHR: {
		return "VideoEncodeH265ProfileInfoKHR";
	}
	case VideoEncodeH265RateControlInfoKHR: {
		return "VideoEncodeH265RateControlInfoKHR";
	}
	case VideoEncodeH265RateControlLayerInfoKHR: {
		return "VideoEncodeH265RateControlLayerInfoKHR";
	}
	case VideoEncodeH265SessionCreateInfoKHR: {
		return "VideoEncodeH265SessionCreateInfoKHR";
	}
	case VideoEncodeH265QualityLevelPropertiesKHR: {
		return "VideoEncodeH265QualityLevelPropertiesKHR";
	}
	case VideoEncodeH265SessionParametersGetInfoKHR: {
		return "VideoEncodeH265SessionParametersGetInfoKHR";
	}
	case VideoEncodeH265SessionParametersFeedbackInfoKHR: {
		return "VideoEncodeH265SessionParametersFeedbackInfoKHR";
	}
	case VideoDecodeH264CapabilitiesKHR: {
		return "VideoDecodeH264CapabilitiesKHR";
	}
	case VideoDecodeH264PictureInfoKHR: {
		return "VideoDecodeH264PictureInfoKHR";
	}
	case VideoDecodeH264ProfileInfoKHR: {
		return "VideoDecodeH264ProfileInfoKHR";
	}
	case VideoDecodeH264SessionParametersCreateInfoKHR: {
		return "VideoDecodeH264SessionParametersCreateInfoKHR";
	}
	case VideoDecodeH264SessionParametersAddInfoKHR: {
		return "VideoDecodeH264SessionParametersAddInfoKHR";
	}
	case VideoDecodeH264DpbSlotInfoKHR: {
		return "VideoDecodeH264DpbSlotInfoKHR";
	}
	case TextureLodGatherFormatPropertiesAMD: {
		return "TextureLodGatherFormatPropertiesAMD";
	}
	case RenderingInfo: {
		return "RenderingInfo";
	}
	case RenderingAttachmentInfo: {
		return "RenderingAttachmentInfo";
	}
	case PipelineRenderingCreateInfo: {
		return "PipelineRenderingCreateInfo";
	}
	case PhysicalDeviceDynamicRenderingFeatures: {
		return "PhysicalDeviceDynamicRenderingFeatures";
	}
	case CommandBufferInheritanceRenderingInfo: {
		return "CommandBufferInheritanceRenderingInfo";
	}
	case RenderingFragmentShadingRateAttachmentInfoKHR: {
		return "RenderingFragmentShadingRateAttachmentInfoKHR";
	}
	case RenderingFragmentDensityMapAttachmentInfoEXT: {
		return "RenderingFragmentDensityMapAttachmentInfoEXT";
	}
	case AttachmentSampleCountInfoAMD: {
		return "AttachmentSampleCountInfoAMD";
	}
	case MultiviewPerViewAttributesInfoNVX: {
		return "MultiviewPerViewAttributesInfoNVX";
	}
	case StreamDescriptorSurfaceCreateInfoGGP: {
		return "StreamDescriptorSurfaceCreateInfoGGP";
	}
	case PhysicalDeviceCornerSampledImageFeaturesNV: {
		return "PhysicalDeviceCornerSampledImageFeaturesNV";
	}
	case RenderPassMultiviewCreateInfo: {
		return "RenderPassMultiviewCreateInfo";
	}
	case PhysicalDeviceMultiviewFeatures: {
		return "PhysicalDeviceMultiviewFeatures";
	}
	case PhysicalDeviceMultiviewProperties: {
		return "PhysicalDeviceMultiviewProperties";
	}
	case ExternalMemoryImageCreateInfoNV: {
		return "ExternalMemoryImageCreateInfoNV";
	}
	case ExportMemoryAllocateInfoNV: {
		return "ExportMemoryAllocateInfoNV";
	}
	case ImportMemoryWin32HandleInfoNV: {
		return "ImportMemoryWin32HandleInfoNV";
	}
	case ExportMemoryWin32HandleInfoNV: {
		return "ExportMemoryWin32HandleInfoNV";
	}
	case Win32KeyedMutexAcquireReleaseInfoNV: {
		return "Win32KeyedMutexAcquireReleaseInfoNV";
	}
	case PhysicalDeviceFeatures2: {
		return "PhysicalDeviceFeatures2";
	}
	case PhysicalDeviceProperties2: {
		return "PhysicalDeviceProperties2";
	}
	case FormatProperties2: {
		return "FormatProperties2";
	}
	case ImageFormatProperties2: {
		return "ImageFormatProperties2";
	}
	case PhysicalDeviceImageFormatInfo2: {
		return "PhysicalDeviceImageFormatInfo2";
	}
	case QueueFamilyProperties2: {
		return "QueueFamilyProperties2";
	}
	case PhysicalDeviceMemoryProperties2: {
		return "PhysicalDeviceMemoryProperties2";
	}
	case SparseImageFormatProperties2: {
		return "SparseImageFormatProperties2";
	}
	case PhysicalDeviceSparseImageFormatInfo2: {
		return "PhysicalDeviceSparseImageFormatInfo2";
	}
	case MemoryAllocateFlagsInfo: {
		return "MemoryAllocateFlagsInfo";
	}
	case DeviceGroupRenderPassBeginInfo: {
		return "DeviceGroupRenderPassBeginInfo";
	}
	case DeviceGroupCommandBufferBeginInfo: {
		return "DeviceGroupCommandBufferBeginInfo";
	}
	case DeviceGroupSubmitInfo: {
		return "DeviceGroupSubmitInfo";
	}
	case DeviceGroupBindSparseInfo: {
		return "DeviceGroupBindSparseInfo";
	}
	case DeviceGroupPresentCapabilitiesKHR: {
		return "DeviceGroupPresentCapabilitiesKHR";
	}
	case ImageSwapchainCreateInfoKHR: {
		return "ImageSwapchainCreateInfoKHR";
	}
	case BindImageMemorySwapchainInfoKHR: {
		return "BindImageMemorySwapchainInfoKHR";
	}
	case AcquireNextImageInfoKHR: {
		return "AcquireNextImageInfoKHR";
	}
	case DeviceGroupPresentInfoKHR: {
		return "DeviceGroupPresentInfoKHR";
	}
	case DeviceGroupSwapchainCreateInfoKHR: {
		return "DeviceGroupSwapchainCreateInfoKHR";
	}
	case BindBufferMemoryDeviceGroupInfo: {
		return "BindBufferMemoryDeviceGroupInfo";
	}
	case BindImageMemoryDeviceGroupInfo: {
		return "BindImageMemoryDeviceGroupInfo";
	}
	case ValidationFlagsEXT: {
		return "ValidationFlagsEXT";
	}
	case ViSurfaceCreateInfoNN: {
		return "ViSurfaceCreateInfoNN";
	}
	case PhysicalDeviceShaderDrawParametersFeatures: {
		return "PhysicalDeviceShaderDrawParametersFeatures";
	}
	case PhysicalDeviceTextureCompressionAstcHdrFeatures: {
		return "PhysicalDeviceTextureCompressionAstcHdrFeatures";
	}
	case ImageViewAstcDecodeModeEXT: {
		return "ImageViewAstcDecodeModeEXT";
	}
	case PhysicalDeviceAstcDecodeFeaturesEXT: {
		return "PhysicalDeviceAstcDecodeFeaturesEXT";
	}
	case PipelineRobustnessCreateInfo: {
		return "PipelineRobustnessCreateInfo";
	}
	case PhysicalDevicePipelineRobustnessFeatures: {
		return "PhysicalDevicePipelineRobustnessFeatures";
	}
	case PhysicalDevicePipelineRobustnessProperties: {
		return "PhysicalDevicePipelineRobustnessProperties";
	}
	case PhysicalDeviceGroupProperties: {
		return "PhysicalDeviceGroupProperties";
	}
	case DeviceGroupDeviceCreateInfo: {
		return "DeviceGroupDeviceCreateInfo";
	}
	case PhysicalDeviceExternalImageFormatInfo: {
		return "PhysicalDeviceExternalImageFormatInfo";
	}
	case ExternalImageFormatProperties: {
		return "ExternalImageFormatProperties";
	}
	case PhysicalDeviceExternalBufferInfo: {
		return "PhysicalDeviceExternalBufferInfo";
	}
	case ExternalBufferProperties: {
		return "ExternalBufferProperties";
	}
	case PhysicalDeviceIdProperties: {
		return "PhysicalDeviceIdProperties";
	}
	case ExternalMemoryBufferCreateInfo: {
		return "ExternalMemoryBufferCreateInfo";
	}
	case ExternalMemoryImageCreateInfo: {
		return "ExternalMemoryImageCreateInfo";
	}
	case ExportMemoryAllocateInfo: {
		return "ExportMemoryAllocateInfo";
	}
	case ImportMemoryWin32HandleInfoKHR: {
		return "ImportMemoryWin32HandleInfoKHR";
	}
	case ExportMemoryWin32HandleInfoKHR: {
		return "ExportMemoryWin32HandleInfoKHR";
	}
	case MemoryWin32HandlePropertiesKHR: {
		return "MemoryWin32HandlePropertiesKHR";
	}
	case MemoryGetWin32HandleInfoKHR: {
		return "MemoryGetWin32HandleInfoKHR";
	}
	case ImportMemoryFdInfoKHR: {
		return "ImportMemoryFdInfoKHR";
	}
	case MemoryFdPropertiesKHR: {
		return "MemoryFdPropertiesKHR";
	}
	case MemoryGetFdInfoKHR: {
		return "MemoryGetFdInfoKHR";
	}
	case Win32KeyedMutexAcquireReleaseInfoKHR: {
		return "Win32KeyedMutexAcquireReleaseInfoKHR";
	}
	case PhysicalDeviceExternalSemaphoreInfo: {
		return "PhysicalDeviceExternalSemaphoreInfo";
	}
	case ExternalSemaphoreProperties: {
		return "ExternalSemaphoreProperties";
	}
	case ExportSemaphoreCreateInfo: {
		return "ExportSemaphoreCreateInfo";
	}
	case ImportSemaphoreWin32HandleInfoKHR: {
		return "ImportSemaphoreWin32HandleInfoKHR";
	}
	case ExportSemaphoreWin32HandleInfoKHR: {
		return "ExportSemaphoreWin32HandleInfoKHR";
	}
	case D3D12FenceSubmitInfoKHR: {
		return "D3D12FenceSubmitInfoKHR";
	}
	case SemaphoreGetWin32HandleInfoKHR: {
		return "SemaphoreGetWin32HandleInfoKHR";
	}
	case ImportSemaphoreFdInfoKHR: {
		return "ImportSemaphoreFdInfoKHR";
	}
	case SemaphoreGetFdInfoKHR: {
		return "SemaphoreGetFdInfoKHR";
	}
	case PhysicalDevicePushDescriptorProperties: {
		return "PhysicalDevicePushDescriptorProperties";
	}
	case CommandBufferInheritanceConditionalRenderingInfoEXT: {
		return "CommandBufferInheritanceConditionalRenderingInfoEXT";
	}
	case PhysicalDeviceConditionalRenderingFeaturesEXT: {
		return "PhysicalDeviceConditionalRenderingFeaturesEXT";
	}
	case ConditionalRenderingBeginInfoEXT: {
		return "ConditionalRenderingBeginInfoEXT";
	}
	case PhysicalDeviceShaderFloat16Int8Features: {
		return "PhysicalDeviceShaderFloat16Int8Features";
	}
	case PhysicalDevice16BitStorageFeatures: {
		return "PhysicalDevice16BitStorageFeatures";
	}
	case PresentRegionsKHR: {
		return "PresentRegionsKHR";
	}
	case DescriptorUpdateTemplateCreateInfo: {
		return "DescriptorUpdateTemplateCreateInfo";
	}
	case PipelineViewportWScalingStateCreateInfoNV: {
		return "PipelineViewportWScalingStateCreateInfoNV";
	}
	case SurfaceCapabilities2EXT: {
		return "SurfaceCapabilities2EXT";
	}
	case DisplayPowerInfoEXT: {
		return "DisplayPowerInfoEXT";
	}
	case DeviceEventInfoEXT: {
		return "DeviceEventInfoEXT";
	}
	case DisplayEventInfoEXT: {
		return "DisplayEventInfoEXT";
	}
	case SwapchainCounterCreateInfoEXT: {
		return "SwapchainCounterCreateInfoEXT";
	}
	case PresentTimesInfoGOOGLE: {
		return "PresentTimesInfoGOOGLE";
	}
	case PhysicalDeviceSubgroupProperties: {
		return "PhysicalDeviceSubgroupProperties";
	}
	case PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX: {
		return "PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX";
	}
	case PipelineViewportSwizzleStateCreateInfoNV: {
		return "PipelineViewportSwizzleStateCreateInfoNV";
	}
	case PhysicalDeviceDiscardRectanglePropertiesEXT: {
		return "PhysicalDeviceDiscardRectanglePropertiesEXT";
	}
	case PipelineDiscardRectangleStateCreateInfoEXT: {
		return "PipelineDiscardRectangleStateCreateInfoEXT";
	}
	case PhysicalDeviceConservativeRasterizationPropertiesEXT: {
		return "PhysicalDeviceConservativeRasterizationPropertiesEXT";
	}
	case PipelineRasterizationConservativeStateCreateInfoEXT: {
		return "PipelineRasterizationConservativeStateCreateInfoEXT";
	}
	case PhysicalDeviceDepthClipEnableFeaturesEXT: {
		return "PhysicalDeviceDepthClipEnableFeaturesEXT";
	}
	case PipelineRasterizationDepthClipStateCreateInfoEXT: {
		return "PipelineRasterizationDepthClipStateCreateInfoEXT";
	}
	case HdrMetadataEXT: {
		return "HdrMetadataEXT";
	}
	case PhysicalDeviceImagelessFramebufferFeatures: {
		return "PhysicalDeviceImagelessFramebufferFeatures";
	}
	case FramebufferAttachmentsCreateInfo: {
		return "FramebufferAttachmentsCreateInfo";
	}
	case FramebufferAttachmentImageInfo: {
		return "FramebufferAttachmentImageInfo";
	}
	case RenderPassAttachmentBeginInfo: {
		return "RenderPassAttachmentBeginInfo";
	}
	case AttachmentDescription2: {
		return "AttachmentDescription2";
	}
	case AttachmentReference2: {
		return "AttachmentReference2";
	}
	case SubpassDescription2: {
		return "SubpassDescription2";
	}
	case SubpassDependency2: {
		return "SubpassDependency2";
	}
	case RenderPassCreateInfo2: {
		return "RenderPassCreateInfo2";
	}
	case SubpassBeginInfo: {
		return "SubpassBeginInfo";
	}
	case SubpassEndInfo: {
		return "SubpassEndInfo";
	}
	case PhysicalDeviceRelaxedLineRasterizationFeaturesIMG: {
		return "PhysicalDeviceRelaxedLineRasterizationFeaturesIMG";
	}
	case SharedPresentSurfaceCapabilitiesKHR: {
		return "SharedPresentSurfaceCapabilitiesKHR";
	}
	case PhysicalDeviceExternalFenceInfo: {
		return "PhysicalDeviceExternalFenceInfo";
	}
	case ExternalFenceProperties: {
		return "ExternalFenceProperties";
	}
	case ExportFenceCreateInfo: {
		return "ExportFenceCreateInfo";
	}
	case ImportFenceWin32HandleInfoKHR: {
		return "ImportFenceWin32HandleInfoKHR";
	}
	case ExportFenceWin32HandleInfoKHR: {
		return "ExportFenceWin32HandleInfoKHR";
	}
	case FenceGetWin32HandleInfoKHR: {
		return "FenceGetWin32HandleInfoKHR";
	}
	case ImportFenceFdInfoKHR: {
		return "ImportFenceFdInfoKHR";
	}
	case FenceGetFdInfoKHR: {
		return "FenceGetFdInfoKHR";
	}
	case PhysicalDevicePerformanceQueryFeaturesKHR: {
		return "PhysicalDevicePerformanceQueryFeaturesKHR";
	}
	case PhysicalDevicePerformanceQueryPropertiesKHR: {
		return "PhysicalDevicePerformanceQueryPropertiesKHR";
	}
	case QueryPoolPerformanceCreateInfoKHR: {
		return "QueryPoolPerformanceCreateInfoKHR";
	}
	case PerformanceQuerySubmitInfoKHR: {
		return "PerformanceQuerySubmitInfoKHR";
	}
	case AcquireProfilingLockInfoKHR: {
		return "AcquireProfilingLockInfoKHR";
	}
	case PerformanceCounterKHR: {
		return "PerformanceCounterKHR";
	}
	case PerformanceCounterDescriptionKHR: {
		return "PerformanceCounterDescriptionKHR";
	}
	case PhysicalDevicePointClippingProperties: {
		return "PhysicalDevicePointClippingProperties";
	}
	case RenderPassInputAttachmentAspectCreateInfo: {
		return "RenderPassInputAttachmentAspectCreateInfo";
	}
	case ImageViewUsageCreateInfo: {
		return "ImageViewUsageCreateInfo";
	}
	case PipelineTessellationDomainOriginStateCreateInfo: {
		return "PipelineTessellationDomainOriginStateCreateInfo";
	}
	case PhysicalDeviceSurfaceInfo2KHR: {
		return "PhysicalDeviceSurfaceInfo2KHR";
	}
	case SurfaceCapabilities2KHR: {
		return "SurfaceCapabilities2KHR";
	}
	case SurfaceFormat2KHR: {
		return "SurfaceFormat2KHR";
	}
	case PhysicalDeviceVariablePointersFeatures: {
		return "PhysicalDeviceVariablePointersFeatures";
	}
	case DisplayProperties2KHR: {
		return "DisplayProperties2KHR";
	}
	case DisplayPlaneProperties2KHR: {
		return "DisplayPlaneProperties2KHR";
	}
	case DisplayModeProperties2KHR: {
		return "DisplayModeProperties2KHR";
	}
	case DisplayPlaneInfo2KHR: {
		return "DisplayPlaneInfo2KHR";
	}
	case DisplayPlaneCapabilities2KHR: {
		return "DisplayPlaneCapabilities2KHR";
	}
	case IosSurfaceCreateInfoMVK: {
		return "IosSurfaceCreateInfoMVK";
	}
	case MacosSurfaceCreateInfoMVK: {
		return "MacosSurfaceCreateInfoMVK";
	}
	case MemoryDedicatedRequirements: {
		return "MemoryDedicatedRequirements";
	}
	case MemoryDedicatedAllocateInfo: {
		return "MemoryDedicatedAllocateInfo";
	}
	case DebugUtilsObjectNameInfoEXT: {
		return "DebugUtilsObjectNameInfoEXT";
	}
	case DebugUtilsObjectTagInfoEXT: {
		return "DebugUtilsObjectTagInfoEXT";
	}
	case DebugUtilsLabelEXT: {
		return "DebugUtilsLabelEXT";
	}
	case DebugUtilsMessengerCallbackDataEXT: {
		return "DebugUtilsMessengerCallbackDataEXT";
	}
	case DebugUtilsMessengerCreateInfoEXT: {
		return "DebugUtilsMessengerCreateInfoEXT";
	}
	case ANDROIDHardwareBufferUsageANDROID: {
		return "ANDROIDHardwareBufferUsageANDROID";
	}
	case ANDROIDHardwareBufferPropertiesANDROID: {
		return "ANDROIDHardwareBufferPropertiesANDROID";
	}
	case ANDROIDHardwareBufferFormatPropertiesANDROID: {
		return "ANDROIDHardwareBufferFormatPropertiesANDROID";
	}
	case ImportANDROIDHardwareBufferInfoANDROID: {
		return "ImportANDROIDHardwareBufferInfoANDROID";
	}
	case MemoryGetANDROIDHardwareBufferInfoANDROID: {
		return "MemoryGetANDROIDHardwareBufferInfoANDROID";
	}
	case ExternalFormatANDROID: {
		return "ExternalFormatANDROID";
	}
	case ANDROIDHardwareBufferFormatProperties2ANDROID: {
		return "ANDROIDHardwareBufferFormatProperties2ANDROID";
	}
	case PhysicalDeviceSamplerFilterMinmaxProperties: {
		return "PhysicalDeviceSamplerFilterMinmaxProperties";
	}
	case SamplerReductionModeCreateInfo: {
		return "SamplerReductionModeCreateInfo";
	}
	case PhysicalDeviceGpaFeaturesAMD: {
		return "PhysicalDeviceGpaFeaturesAMD";
	}
	case PhysicalDeviceGpaPropertiesAMD: {
		return "PhysicalDeviceGpaPropertiesAMD";
	}
	case GpaSampleBeginInfoAMD: {
		return "GpaSampleBeginInfoAMD";
	}
	case GpaSessionCreateInfoAMD: {
		return "GpaSessionCreateInfoAMD";
	}
	case GpaDeviceClockModeInfoAMD: {
		return "GpaDeviceClockModeInfoAMD";
	}
	case PhysicalDeviceGpaProperties2AMD: {
		return "PhysicalDeviceGpaProperties2AMD";
	}
	case GpaDeviceGetClockInfoAMD: {
		return "GpaDeviceGetClockInfoAMD";
	}
	case PhysicalDeviceShaderEnqueueFeaturesAMDX: {
		return "PhysicalDeviceShaderEnqueueFeaturesAMDX";
	}
	case PhysicalDeviceShaderEnqueuePropertiesAMDX: {
		return "PhysicalDeviceShaderEnqueuePropertiesAMDX";
	}
	case ExecutionGraphPipelineScratchSizeAMDX: {
		return "ExecutionGraphPipelineScratchSizeAMDX";
	}
	case ExecutionGraphPipelineCreateInfoAMDX: {
		return "ExecutionGraphPipelineCreateInfoAMDX";
	}
	case PipelineShaderStageNodeCreateInfoAMDX: {
		return "PipelineShaderStageNodeCreateInfoAMDX";
	}
	case TexelBufferDescriptorInfoEXT: {
		return "TexelBufferDescriptorInfoEXT";
	}
	case ImageDescriptorInfoEXT: {
		return "ImageDescriptorInfoEXT";
	}
	case ResourceDescriptorInfoEXT: {
		return "ResourceDescriptorInfoEXT";
	}
	case BindHeapInfoEXT: {
		return "BindHeapInfoEXT";
	}
	case PushDataInfoEXT: {
		return "PushDataInfoEXT";
	}
	case DescriptorSetAndBindingMappingEXT: {
		return "DescriptorSetAndBindingMappingEXT";
	}
	case ShaderDescriptorSetAndBindingMappingInfoEXT: {
		return "ShaderDescriptorSetAndBindingMappingInfoEXT";
	}
	case OpaqueCaptureDataCreateInfoEXT: {
		return "OpaqueCaptureDataCreateInfoEXT";
	}
	case PhysicalDeviceDescriptorHeapPropertiesEXT: {
		return "PhysicalDeviceDescriptorHeapPropertiesEXT";
	}
	case PhysicalDeviceDescriptorHeapFeaturesEXT: {
		return "PhysicalDeviceDescriptorHeapFeaturesEXT";
	}
	case CommandBufferInheritanceDescriptorHeapInfoEXT: {
		return "CommandBufferInheritanceDescriptorHeapInfoEXT";
	}
	case SamplerCustomBorderColorIndexCreateInfoEXT: {
		return "SamplerCustomBorderColorIndexCreateInfoEXT";
	}
	case IndirectCommandsLayoutPushDataTokenNV: {
		return "IndirectCommandsLayoutPushDataTokenNV";
	}
	case SubsampledImageFormatPropertiesEXT: {
		return "SubsampledImageFormatPropertiesEXT";
	}
	case PhysicalDeviceDescriptorHeapTensorPropertiesARM: {
		return "PhysicalDeviceDescriptorHeapTensorPropertiesARM";
	}
	case PhysicalDeviceInlineUniformBlockFeatures: {
		return "PhysicalDeviceInlineUniformBlockFeatures";
	}
	case PhysicalDeviceInlineUniformBlockProperties: {
		return "PhysicalDeviceInlineUniformBlockProperties";
	}
	case WriteDescriptorSetInlineUniformBlock: {
		return "WriteDescriptorSetInlineUniformBlock";
	}
	case DescriptorPoolInlineUniformBlockCreateInfo: {
		return "DescriptorPoolInlineUniformBlockCreateInfo";
	}
	case PhysicalDeviceShaderBfloat16FeaturesKHR: {
		return "PhysicalDeviceShaderBfloat16FeaturesKHR";
	}
	case SampleLocationsInfoEXT: {
		return "SampleLocationsInfoEXT";
	}
	case RenderPassSampleLocationsBeginInfoEXT: {
		return "RenderPassSampleLocationsBeginInfoEXT";
	}
	case PipelineSampleLocationsStateCreateInfoEXT: {
		return "PipelineSampleLocationsStateCreateInfoEXT";
	}
	case PhysicalDeviceSampleLocationsPropertiesEXT: {
		return "PhysicalDeviceSampleLocationsPropertiesEXT";
	}
	case MultisamplePropertiesEXT: {
		return "MultisamplePropertiesEXT";
	}
	case ProtectedSubmitInfo: {
		return "ProtectedSubmitInfo";
	}
	case PhysicalDeviceProtectedMemoryFeatures: {
		return "PhysicalDeviceProtectedMemoryFeatures";
	}
	case PhysicalDeviceProtectedMemoryProperties: {
		return "PhysicalDeviceProtectedMemoryProperties";
	}
	case DeviceQueueInfo2: {
		return "DeviceQueueInfo2";
	}
	case BufferMemoryRequirementsInfo2: {
		return "BufferMemoryRequirementsInfo2";
	}
	case ImageMemoryRequirementsInfo2: {
		return "ImageMemoryRequirementsInfo2";
	}
	case ImageSparseMemoryRequirementsInfo2: {
		return "ImageSparseMemoryRequirementsInfo2";
	}
	case MemoryRequirements2: {
		return "MemoryRequirements2";
	}
	case SparseImageMemoryRequirements2: {
		return "SparseImageMemoryRequirements2";
	}
	case ImageFormatListCreateInfo: {
		return "ImageFormatListCreateInfo";
	}
	case PhysicalDeviceBlendOperationAdvancedFeaturesEXT: {
		return "PhysicalDeviceBlendOperationAdvancedFeaturesEXT";
	}
	case PhysicalDeviceBlendOperationAdvancedPropertiesEXT: {
		return "PhysicalDeviceBlendOperationAdvancedPropertiesEXT";
	}
	case PipelineColorBlendAdvancedStateCreateInfoEXT: {
		return "PipelineColorBlendAdvancedStateCreateInfoEXT";
	}
	case PipelineCoverageToColorStateCreateInfoNV: {
		return "PipelineCoverageToColorStateCreateInfoNV";
	}
	case AccelerationStructureBuildGeometryInfoKHR: {
		return "AccelerationStructureBuildGeometryInfoKHR";
	}
	case AccelerationStructureDeviceAddressInfoKHR: {
		return "AccelerationStructureDeviceAddressInfoKHR";
	}
	case AccelerationStructureGeometryAabbsDataKHR: {
		return "AccelerationStructureGeometryAabbsDataKHR";
	}
	case AccelerationStructureGeometryInstancesDataKHR: {
		return "AccelerationStructureGeometryInstancesDataKHR";
	}
	case AccelerationStructureGeometryTrianglesDataKHR: {
		return "AccelerationStructureGeometryTrianglesDataKHR";
	}
	case AccelerationStructureGeometryKHR: {
		return "AccelerationStructureGeometryKHR";
	}
	case WriteDescriptorSetAccelerationStructureKHR: {
		return "WriteDescriptorSetAccelerationStructureKHR";
	}
	case AccelerationStructureVersionInfoKHR: {
		return "AccelerationStructureVersionInfoKHR";
	}
	case CopyAccelerationStructureInfoKHR: {
		return "CopyAccelerationStructureInfoKHR";
	}
	case CopyAccelerationStructureToMemoryInfoKHR: {
		return "CopyAccelerationStructureToMemoryInfoKHR";
	}
	case CopyMemoryToAccelerationStructureInfoKHR: {
		return "CopyMemoryToAccelerationStructureInfoKHR";
	}
	case PhysicalDeviceAccelerationStructureFeaturesKHR: {
		return "PhysicalDeviceAccelerationStructureFeaturesKHR";
	}
	case PhysicalDeviceAccelerationStructurePropertiesKHR: {
		return "PhysicalDeviceAccelerationStructurePropertiesKHR";
	}
	case RayTracingPipelineCreateInfoKHR: {
		return "RayTracingPipelineCreateInfoKHR";
	}
	case RayTracingShaderGroupCreateInfoKHR: {
		return "RayTracingShaderGroupCreateInfoKHR";
	}
	case AccelerationStructureCreateInfoKHR: {
		return "AccelerationStructureCreateInfoKHR";
	}
	case RayTracingPipelineInterfaceCreateInfoKHR: {
		return "RayTracingPipelineInterfaceCreateInfoKHR";
	}
	case AccelerationStructureBuildSizesInfoKHR: {
		return "AccelerationStructureBuildSizesInfoKHR";
	}
	case PipelineCoverageModulationStateCreateInfoNV: {
		return "PipelineCoverageModulationStateCreateInfoNV";
	}
	case PhysicalDeviceShaderSmBuiltinsFeaturesNV: {
		return "PhysicalDeviceShaderSmBuiltinsFeaturesNV";
	}
	case PhysicalDeviceShaderSmBuiltinsPropertiesNV: {
		return "PhysicalDeviceShaderSmBuiltinsPropertiesNV";
	}
	case SamplerYcbcrConversionCreateInfo: {
		return "SamplerYcbcrConversionCreateInfo";
	}
	case SamplerYcbcrConversionInfo: {
		return "SamplerYcbcrConversionInfo";
	}
	case BindImagePlaneMemoryInfo: {
		return "BindImagePlaneMemoryInfo";
	}
	case ImagePlaneMemoryRequirementsInfo: {
		return "ImagePlaneMemoryRequirementsInfo";
	}
	case PhysicalDeviceSamplerYcbcrConversionFeatures: {
		return "PhysicalDeviceSamplerYcbcrConversionFeatures";
	}
	case SamplerYcbcrConversionImageFormatProperties: {
		return "SamplerYcbcrConversionImageFormatProperties";
	}
	case BindBufferMemoryInfo: {
		return "BindBufferMemoryInfo";
	}
	case BindImageMemoryInfo: {
		return "BindImageMemoryInfo";
	}
	case DrmFormatModifierPropertiesListEXT: {
		return "DrmFormatModifierPropertiesListEXT";
	}
	case PhysicalDeviceImageDrmFormatModifierInfoEXT: {
		return "PhysicalDeviceImageDrmFormatModifierInfoEXT";
	}
	case ImageDrmFormatModifierListCreateInfoEXT: {
		return "ImageDrmFormatModifierListCreateInfoEXT";
	}
	case ImageDrmFormatModifierExplicitCreateInfoEXT: {
		return "ImageDrmFormatModifierExplicitCreateInfoEXT";
	}
	case ImageDrmFormatModifierPropertiesEXT: {
		return "ImageDrmFormatModifierPropertiesEXT";
	}
	case DrmFormatModifierPropertiesList2EXT: {
		return "DrmFormatModifierPropertiesList2EXT";
	}
	case ValidationCacheCreateInfoEXT: {
		return "ValidationCacheCreateInfoEXT";
	}
	case ShaderModuleValidationCacheCreateInfoEXT: {
		return "ShaderModuleValidationCacheCreateInfoEXT";
	}
	case DescriptorSetLayoutBindingFlagsCreateInfo: {
		return "DescriptorSetLayoutBindingFlagsCreateInfo";
	}
	case PhysicalDeviceDescriptorIndexingFeatures: {
		return "PhysicalDeviceDescriptorIndexingFeatures";
	}
	case PhysicalDeviceDescriptorIndexingProperties: {
		return "PhysicalDeviceDescriptorIndexingProperties";
	}
	case DescriptorSetVariableDescriptorCountAllocateInfo: {
		return "DescriptorSetVariableDescriptorCountAllocateInfo";
	}
	case DescriptorSetVariableDescriptorCountLayoutSupport: {
		return "DescriptorSetVariableDescriptorCountLayoutSupport";
	}
	case PhysicalDevicePortabilitySubsetFeaturesKHR: {
		return "PhysicalDevicePortabilitySubsetFeaturesKHR";
	}
	case PhysicalDevicePortabilitySubsetPropertiesKHR: {
		return "PhysicalDevicePortabilitySubsetPropertiesKHR";
	}
	case PipelineViewportShadingRateImageStateCreateInfoNV: {
		return "PipelineViewportShadingRateImageStateCreateInfoNV";
	}
	case PhysicalDeviceShadingRateImageFeaturesNV: {
		return "PhysicalDeviceShadingRateImageFeaturesNV";
	}
	case PhysicalDeviceShadingRateImagePropertiesNV: {
		return "PhysicalDeviceShadingRateImagePropertiesNV";
	}
	case PipelineViewportCoarseSampleOrderStateCreateInfoNV: {
		return "PipelineViewportCoarseSampleOrderStateCreateInfoNV";
	}
	case RayTracingPipelineCreateInfoNV: {
		return "RayTracingPipelineCreateInfoNV";
	}
	case AccelerationStructureCreateInfoNV: {
		return "AccelerationStructureCreateInfoNV";
	}
	case GeometryNV: {
		return "GeometryNV";
	}
	case GeometryTrianglesNV: {
		return "GeometryTrianglesNV";
	}
	case GeometryAabbNV: {
		return "GeometryAabbNV";
	}
	case BindAccelerationStructureMemoryInfoNV: {
		return "BindAccelerationStructureMemoryInfoNV";
	}
	case WriteDescriptorSetAccelerationStructureNV: {
		return "WriteDescriptorSetAccelerationStructureNV";
	}
	case AccelerationStructureMemoryRequirementsInfoNV: {
		return "AccelerationStructureMemoryRequirementsInfoNV";
	}
	case PhysicalDeviceRayTracingPropertiesNV: {
		return "PhysicalDeviceRayTracingPropertiesNV";
	}
	case RayTracingShaderGroupCreateInfoNV: {
		return "RayTracingShaderGroupCreateInfoNV";
	}
	case AccelerationStructureInfoNV: {
		return "AccelerationStructureInfoNV";
	}
	case PhysicalDeviceRepresentativeFragmentTestFeaturesNV: {
		return "PhysicalDeviceRepresentativeFragmentTestFeaturesNV";
	}
	case PipelineRepresentativeFragmentTestStateCreateInfoNV: {
		return "PipelineRepresentativeFragmentTestStateCreateInfoNV";
	}
	case PhysicalDeviceMaintenance3Properties: {
		return "PhysicalDeviceMaintenance3Properties";
	}
	case DescriptorSetLayoutSupport: {
		return "DescriptorSetLayoutSupport";
	}
	case PhysicalDeviceImageViewImageFormatInfoEXT: {
		return "PhysicalDeviceImageViewImageFormatInfoEXT";
	}
	case FilterCubicImageViewImageFormatPropertiesEXT: {
		return "FilterCubicImageViewImageFormatPropertiesEXT";
	}
	case PhysicalDeviceCooperativeMatrixConversionFeaturesQCOM: {
		return "PhysicalDeviceCooperativeMatrixConversionFeaturesQCOM";
	}
	case PhysicalDeviceElapsedTimerQueryFeaturesQCOM: {
		return "PhysicalDeviceElapsedTimerQueryFeaturesQCOM";
	}
	case DeviceQueueGlobalPriorityCreateInfo: {
		return "DeviceQueueGlobalPriorityCreateInfo";
	}
	case PhysicalDeviceShaderSubgroupExtendedTypesFeatures: {
		return "PhysicalDeviceShaderSubgroupExtendedTypesFeatures";
	}
	case PhysicalDevice8BitStorageFeatures: {
		return "PhysicalDevice8BitStorageFeatures";
	}
	case ImportMemoryHostPointerInfoEXT: {
		return "ImportMemoryHostPointerInfoEXT";
	}
	case MemoryHostPointerPropertiesEXT: {
		return "MemoryHostPointerPropertiesEXT";
	}
	case PhysicalDeviceExternalMemoryHostPropertiesEXT: {
		return "PhysicalDeviceExternalMemoryHostPropertiesEXT";
	}
	case PhysicalDeviceShaderAtomicInt64Features: {
		return "PhysicalDeviceShaderAtomicInt64Features";
	}
	case PhysicalDeviceShaderClockFeaturesKHR: {
		return "PhysicalDeviceShaderClockFeaturesKHR";
	}
	case PipelineCompilerControlCreateInfoAMD: {
		return "PipelineCompilerControlCreateInfoAMD";
	}
	case CalibratedTimestampInfoKHR: {
		return "CalibratedTimestampInfoKHR";
	}
	case PhysicalDeviceShaderCorePropertiesAMD: {
		return "PhysicalDeviceShaderCorePropertiesAMD";
	}
	case VideoDecodeH265CapabilitiesKHR: {
		return "VideoDecodeH265CapabilitiesKHR";
	}
	case VideoDecodeH265SessionParametersCreateInfoKHR: {
		return "VideoDecodeH265SessionParametersCreateInfoKHR";
	}
	case VideoDecodeH265SessionParametersAddInfoKHR: {
		return "VideoDecodeH265SessionParametersAddInfoKHR";
	}
	case VideoDecodeH265ProfileInfoKHR: {
		return "VideoDecodeH265ProfileInfoKHR";
	}
	case VideoDecodeH265PictureInfoKHR: {
		return "VideoDecodeH265PictureInfoKHR";
	}
	case VideoDecodeH265DpbSlotInfoKHR: {
		return "VideoDecodeH265DpbSlotInfoKHR";
	}
	case DeviceMemoryOverallocationCreateInfoAMD: {
		return "DeviceMemoryOverallocationCreateInfoAMD";
	}
	case PhysicalDeviceVertexAttributeDivisorPropertiesEXT: {
		return "PhysicalDeviceVertexAttributeDivisorPropertiesEXT";
	}
	case PipelineVertexInputDivisorStateCreateInfo: {
		return "PipelineVertexInputDivisorStateCreateInfo";
	}
	case PhysicalDeviceVertexAttributeDivisorFeatures: {
		return "PhysicalDeviceVertexAttributeDivisorFeatures";
	}
	case PresentFrameTokenGGP: {
		return "PresentFrameTokenGGP";
	}
	case PipelineCreationFeedbackCreateInfo: {
		return "PipelineCreationFeedbackCreateInfo";
	}
	case PhysicalDeviceDriverProperties: {
		return "PhysicalDeviceDriverProperties";
	}
	case PhysicalDeviceFloatControlsProperties: {
		return "PhysicalDeviceFloatControlsProperties";
	}
	case PhysicalDeviceDepthStencilResolveProperties: {
		return "PhysicalDeviceDepthStencilResolveProperties";
	}
	case SubpassDescriptionDepthStencilResolve: {
		return "SubpassDescriptionDepthStencilResolve";
	}
	case PhysicalDeviceComputeShaderDerivativesFeaturesKHR: {
		return "PhysicalDeviceComputeShaderDerivativesFeaturesKHR";
	}
	case PhysicalDeviceMeshShaderFeaturesNV: {
		return "PhysicalDeviceMeshShaderFeaturesNV";
	}
	case PhysicalDeviceMeshShaderPropertiesNV: {
		return "PhysicalDeviceMeshShaderPropertiesNV";
	}
	case PhysicalDeviceFragmentShaderBarycentricFeaturesKHR: {
		return "PhysicalDeviceFragmentShaderBarycentricFeaturesKHR";
	}
	case PhysicalDeviceShaderImageFootprintFeaturesNV: {
		return "PhysicalDeviceShaderImageFootprintFeaturesNV";
	}
	case PipelineViewportExclusiveScissorStateCreateInfoNV: {
		return "PipelineViewportExclusiveScissorStateCreateInfoNV";
	}
	case PhysicalDeviceExclusiveScissorFeaturesNV: {
		return "PhysicalDeviceExclusiveScissorFeaturesNV";
	}
	case CheckpointDataNV: {
		return "CheckpointDataNV";
	}
	case QueueFamilyCheckpointPropertiesNV: {
		return "QueueFamilyCheckpointPropertiesNV";
	}
	case PhysicalDeviceTimelineSemaphoreFeatures: {
		return "PhysicalDeviceTimelineSemaphoreFeatures";
	}
	case PhysicalDeviceTimelineSemaphoreProperties: {
		return "PhysicalDeviceTimelineSemaphoreProperties";
	}
	case SemaphoreTypeCreateInfo: {
		return "SemaphoreTypeCreateInfo";
	}
	case TimelineSemaphoreSubmitInfo: {
		return "TimelineSemaphoreSubmitInfo";
	}
	case SemaphoreWaitInfo: {
		return "SemaphoreWaitInfo";
	}
	case SemaphoreSignalInfo: {
		return "SemaphoreSignalInfo";
	}
	case PhysicalDevicePresentTimingFeaturesEXT: {
		return "PhysicalDevicePresentTimingFeaturesEXT";
	}
	case SwapchainTimingPropertiesEXT: {
		return "SwapchainTimingPropertiesEXT";
	}
	case SwapchainTimeDomainPropertiesEXT: {
		return "SwapchainTimeDomainPropertiesEXT";
	}
	case PresentTimingsInfoEXT: {
		return "PresentTimingsInfoEXT";
	}
	case PresentTimingInfoEXT: {
		return "PresentTimingInfoEXT";
	}
	case PastPresentationTimingInfoEXT: {
		return "PastPresentationTimingInfoEXT";
	}
	case PastPresentationTimingPropertiesEXT: {
		return "PastPresentationTimingPropertiesEXT";
	}
	case PastPresentationTimingEXT: {
		return "PastPresentationTimingEXT";
	}
	case PresentTimingSurfaceCapabilitiesEXT: {
		return "PresentTimingSurfaceCapabilitiesEXT";
	}
	case SwapchainCalibratedTimestampInfoEXT: {
		return "SwapchainCalibratedTimestampInfoEXT";
	}
	case PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL: {
		return "PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL";
	}
	case QueryPoolPerformanceQueryCreateInfoINTEL: {
		return "QueryPoolPerformanceQueryCreateInfoINTEL";
	}
	case InitializePerformanceApiInfoINTEL: {
		return "InitializePerformanceApiInfoINTEL";
	}
	case PerformanceMarkerInfoINTEL: {
		return "PerformanceMarkerInfoINTEL";
	}
	case PerformanceStreamMarkerInfoINTEL: {
		return "PerformanceStreamMarkerInfoINTEL";
	}
	case PerformanceOverrideInfoINTEL: {
		return "PerformanceOverrideInfoINTEL";
	}
	case PerformanceConfigurationAcquireInfoINTEL: {
		return "PerformanceConfigurationAcquireInfoINTEL";
	}
	case PhysicalDeviceVulkanMemoryModelFeatures: {
		return "PhysicalDeviceVulkanMemoryModelFeatures";
	}
	case PhysicalDevicePciBusInfoPropertiesEXT: {
		return "PhysicalDevicePciBusInfoPropertiesEXT";
	}
	case DisplayNativeHdrSurfaceCapabilitiesAMD: {
		return "DisplayNativeHdrSurfaceCapabilitiesAMD";
	}
	case SwapchainDisplayNativeHdrCreateInfoAMD: {
		return "SwapchainDisplayNativeHdrCreateInfoAMD";
	}
	case ImagepipeSurfaceCreateInfoFUCHSIA: {
		return "ImagepipeSurfaceCreateInfoFUCHSIA";
	}
	case PhysicalDeviceShaderTerminateInvocationFeatures: {
		return "PhysicalDeviceShaderTerminateInvocationFeatures";
	}
	case MetalSurfaceCreateInfoEXT: {
		return "MetalSurfaceCreateInfoEXT";
	}
	case PhysicalDeviceFragmentDensityMapFeaturesEXT: {
		return "PhysicalDeviceFragmentDensityMapFeaturesEXT";
	}
	case PhysicalDeviceFragmentDensityMapPropertiesEXT: {
		return "PhysicalDeviceFragmentDensityMapPropertiesEXT";
	}
	case RenderPassFragmentDensityMapCreateInfoEXT: {
		return "RenderPassFragmentDensityMapCreateInfoEXT";
	}
	case PhysicalDeviceScalarBlockLayoutFeatures: {
		return "PhysicalDeviceScalarBlockLayoutFeatures";
	}
	case PhysicalDeviceSubgroupSizeControlProperties: {
		return "PhysicalDeviceSubgroupSizeControlProperties";
	}
	case PipelineShaderStageRequiredSubgroupSizeCreateInfo: {
		return "PipelineShaderStageRequiredSubgroupSizeCreateInfo";
	}
	case PhysicalDeviceSubgroupSizeControlFeatures: {
		return "PhysicalDeviceSubgroupSizeControlFeatures";
	}
	case FragmentShadingRateAttachmentInfoKHR: {
		return "FragmentShadingRateAttachmentInfoKHR";
	}
	case PipelineFragmentShadingRateStateCreateInfoKHR: {
		return "PipelineFragmentShadingRateStateCreateInfoKHR";
	}
	case PhysicalDeviceFragmentShadingRatePropertiesKHR: {
		return "PhysicalDeviceFragmentShadingRatePropertiesKHR";
	}
	case PhysicalDeviceFragmentShadingRateFeaturesKHR: {
		return "PhysicalDeviceFragmentShadingRateFeaturesKHR";
	}
	case PhysicalDeviceFragmentShadingRateKHR: {
		return "PhysicalDeviceFragmentShadingRateKHR";
	}
	case PhysicalDeviceShaderCoreProperties2AMD: {
		return "PhysicalDeviceShaderCoreProperties2AMD";
	}
	case PhysicalDeviceCoherentMemoryFeaturesAMD: {
		return "PhysicalDeviceCoherentMemoryFeaturesAMD";
	}
	case PhysicalDeviceShaderConstantDataFeaturesKHR: {
		return "PhysicalDeviceShaderConstantDataFeaturesKHR";
	}
	case PhysicalDeviceDynamicRenderingLocalReadFeatures: {
		return "PhysicalDeviceDynamicRenderingLocalReadFeatures";
	}
	case RenderingAttachmentLocationInfo: {
		return "RenderingAttachmentLocationInfo";
	}
	case RenderingInputAttachmentIndexInfo: {
		return "RenderingInputAttachmentIndexInfo";
	}
	case PhysicalDeviceShaderAbortFeaturesKHR: {
		return "PhysicalDeviceShaderAbortFeaturesKHR";
	}
	case DeviceFaultShaderAbortMessageInfoKHR: {
		return "DeviceFaultShaderAbortMessageInfoKHR";
	}
	case PhysicalDeviceShaderAbortPropertiesKHR: {
		return "PhysicalDeviceShaderAbortPropertiesKHR";
	}
	case PhysicalDeviceShaderImageAtomicInt64FeaturesEXT: {
		return "PhysicalDeviceShaderImageAtomicInt64FeaturesEXT";
	}
	case PhysicalDeviceShaderQuadControlFeaturesKHR: {
		return "PhysicalDeviceShaderQuadControlFeaturesKHR";
	}
	case PhysicalDeviceMemoryBudgetPropertiesEXT: {
		return "PhysicalDeviceMemoryBudgetPropertiesEXT";
	}
	case PhysicalDeviceMemoryPriorityFeaturesEXT: {
		return "PhysicalDeviceMemoryPriorityFeaturesEXT";
	}
	case MemoryPriorityAllocateInfoEXT: {
		return "MemoryPriorityAllocateInfoEXT";
	}
	case SurfaceProtectedCapabilitiesKHR: {
		return "SurfaceProtectedCapabilitiesKHR";
	}
	case PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV: {
		return "PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV";
	}
	case PhysicalDeviceSeparateDepthStencilLayoutsFeatures: {
		return "PhysicalDeviceSeparateDepthStencilLayoutsFeatures";
	}
	case AttachmentReferenceStencilLayout: {
		return "AttachmentReferenceStencilLayout";
	}
	case AttachmentDescriptionStencilLayout: {
		return "AttachmentDescriptionStencilLayout";
	}
	case PhysicalDeviceBufferDeviceAddressFeaturesEXT: {
		return "PhysicalDeviceBufferDeviceAddressFeaturesEXT";
	}
	case BufferDeviceAddressInfo: {
		return "BufferDeviceAddressInfo";
	}
	case BufferDeviceAddressCreateInfoEXT: {
		return "BufferDeviceAddressCreateInfoEXT";
	}
	case PhysicalDeviceToolProperties: {
		return "PhysicalDeviceToolProperties";
	}
	case ImageStencilUsageCreateInfo: {
		return "ImageStencilUsageCreateInfo";
	}
	case ValidationFeaturesEXT: {
		return "ValidationFeaturesEXT";
	}
	case PhysicalDevicePresentWaitFeaturesKHR: {
		return "PhysicalDevicePresentWaitFeaturesKHR";
	}
	case PhysicalDeviceCooperativeMatrixFeaturesNV: {
		return "PhysicalDeviceCooperativeMatrixFeaturesNV";
	}
	case CooperativeMatrixPropertiesNV: {
		return "CooperativeMatrixPropertiesNV";
	}
	case PhysicalDeviceCooperativeMatrixPropertiesNV: {
		return "PhysicalDeviceCooperativeMatrixPropertiesNV";
	}
	case PhysicalDeviceCoverageReductionModeFeaturesNV: {
		return "PhysicalDeviceCoverageReductionModeFeaturesNV";
	}
	case PipelineCoverageReductionStateCreateInfoNV: {
		return "PipelineCoverageReductionStateCreateInfoNV";
	}
	case FramebufferMixedSamplesCombinationNV: {
		return "FramebufferMixedSamplesCombinationNV";
	}
	case PhysicalDeviceFragmentShaderInterlockFeaturesEXT: {
		return "PhysicalDeviceFragmentShaderInterlockFeaturesEXT";
	}
	case PhysicalDeviceYcbcrImageArraysFeaturesEXT: {
		return "PhysicalDeviceYcbcrImageArraysFeaturesEXT";
	}
	case PhysicalDeviceUniformBufferStandardLayoutFeatures: {
		return "PhysicalDeviceUniformBufferStandardLayoutFeatures";
	}
	case PhysicalDeviceProvokingVertexFeaturesEXT: {
		return "PhysicalDeviceProvokingVertexFeaturesEXT";
	}
	case PipelineRasterizationProvokingVertexStateCreateInfoEXT: {
		return "PipelineRasterizationProvokingVertexStateCreateInfoEXT";
	}
	case PhysicalDeviceProvokingVertexPropertiesEXT: {
		return "PhysicalDeviceProvokingVertexPropertiesEXT";
	}
	case SurfaceFullScreenExclusiveInfoEXT: {
		return "SurfaceFullScreenExclusiveInfoEXT";
	}
	case SurfaceFullScreenExclusiveWin32InfoEXT: {
		return "SurfaceFullScreenExclusiveWin32InfoEXT";
	}
	case SurfaceCapabilitiesFullScreenExclusiveEXT: {
		return "SurfaceCapabilitiesFullScreenExclusiveEXT";
	}
	case HeadlessSurfaceCreateInfoEXT: {
		return "HeadlessSurfaceCreateInfoEXT";
	}
	case PhysicalDeviceBufferDeviceAddressFeatures: {
		return "PhysicalDeviceBufferDeviceAddressFeatures";
	}
	case BufferOpaqueCaptureAddressCreateInfo: {
		return "BufferOpaqueCaptureAddressCreateInfo";
	}
	case MemoryOpaqueCaptureAddressAllocateInfo: {
		return "MemoryOpaqueCaptureAddressAllocateInfo";
	}
	case DeviceMemoryOpaqueCaptureAddressInfo: {
		return "DeviceMemoryOpaqueCaptureAddressInfo";
	}
	case PhysicalDeviceLineRasterizationFeatures: {
		return "PhysicalDeviceLineRasterizationFeatures";
	}
	case PipelineRasterizationLineStateCreateInfo: {
		return "PipelineRasterizationLineStateCreateInfo";
	}
	case PhysicalDeviceLineRasterizationProperties: {
		return "PhysicalDeviceLineRasterizationProperties";
	}
	case PhysicalDeviceShaderAtomicFloatFeaturesEXT: {
		return "PhysicalDeviceShaderAtomicFloatFeaturesEXT";
	}
	case PhysicalDeviceHostQueryResetFeatures: {
		return "PhysicalDeviceHostQueryResetFeatures";
	}
	case PhysicalDeviceIndexTypeUint8Features: {
		return "PhysicalDeviceIndexTypeUint8Features";
	}
	case PhysicalDeviceExtendedDynamicStateFeaturesEXT: {
		return "PhysicalDeviceExtendedDynamicStateFeaturesEXT";
	}
	case PhysicalDevicePipelineExecutablePropertiesFeaturesKHR: {
		return "PhysicalDevicePipelineExecutablePropertiesFeaturesKHR";
	}
	case PipelineInfoKHR: {
		return "PipelineInfoKHR";
	}
	case PipelineExecutablePropertiesKHR: {
		return "PipelineExecutablePropertiesKHR";
	}
	case PipelineExecutableInfoKHR: {
		return "PipelineExecutableInfoKHR";
	}
	case PipelineExecutableStatisticKHR: {
		return "PipelineExecutableStatisticKHR";
	}
	case PipelineExecutableInternalRepresentationKHR: {
		return "PipelineExecutableInternalRepresentationKHR";
	}
	case PhysicalDeviceHostImageCopyFeatures: {
		return "PhysicalDeviceHostImageCopyFeatures";
	}
	case PhysicalDeviceHostImageCopyProperties: {
		return "PhysicalDeviceHostImageCopyProperties";
	}
	case MemoryToImageCopy: {
		return "MemoryToImageCopy";
	}
	case ImageToMemoryCopy: {
		return "ImageToMemoryCopy";
	}
	case CopyImageToMemoryInfo: {
		return "CopyImageToMemoryInfo";
	}
	case CopyMemoryToImageInfo: {
		return "CopyMemoryToImageInfo";
	}
	case HostImageLayoutTransitionInfo: {
		return "HostImageLayoutTransitionInfo";
	}
	case CopyImageToImageInfo: {
		return "CopyImageToImageInfo";
	}
	case SubresourceHostMemcpySize: {
		return "SubresourceHostMemcpySize";
	}
	case HostImageCopyDevicePerformanceQuery: {
		return "HostImageCopyDevicePerformanceQuery";
	}
	case MemoryMapInfo: {
		return "MemoryMapInfo";
	}
	case MemoryUnmapInfo: {
		return "MemoryUnmapInfo";
	}
	case PhysicalDeviceMapMemoryPlacedFeaturesEXT: {
		return "PhysicalDeviceMapMemoryPlacedFeaturesEXT";
	}
	case PhysicalDeviceMapMemoryPlacedPropertiesEXT: {
		return "PhysicalDeviceMapMemoryPlacedPropertiesEXT";
	}
	case MemoryMapPlacedInfoEXT: {
		return "MemoryMapPlacedInfoEXT";
	}
	case PhysicalDeviceShaderAtomicFloat2FeaturesEXT: {
		return "PhysicalDeviceShaderAtomicFloat2FeaturesEXT";
	}
	case SurfacePresentModeKHR: {
		return "SurfacePresentModeKHR";
	}
	case SurfacePresentScalingCapabilitiesKHR: {
		return "SurfacePresentScalingCapabilitiesKHR";
	}
	case SurfacePresentModeCompatibilityKHR: {
		return "SurfacePresentModeCompatibilityKHR";
	}
	case PhysicalDeviceSwapchainMaintenance1FeaturesKHR: {
		return "PhysicalDeviceSwapchainMaintenance1FeaturesKHR";
	}
	case SwapchainPresentFenceInfoKHR: {
		return "SwapchainPresentFenceInfoKHR";
	}
	case SwapchainPresentModesCreateInfoKHR: {
		return "SwapchainPresentModesCreateInfoKHR";
	}
	case SwapchainPresentModeInfoKHR: {
		return "SwapchainPresentModeInfoKHR";
	}
	case SwapchainPresentScalingCreateInfoKHR: {
		return "SwapchainPresentScalingCreateInfoKHR";
	}
	case ReleaseSwapchainImagesInfoKHR: {
		return "ReleaseSwapchainImagesInfoKHR";
	}
	case PhysicalDeviceShaderDemoteToHelperInvocationFeatures: {
		return "PhysicalDeviceShaderDemoteToHelperInvocationFeatures";
	}
	case PhysicalDeviceDeviceGeneratedCommandsPropertiesNV: {
		return "PhysicalDeviceDeviceGeneratedCommandsPropertiesNV";
	}
	case GraphicsShaderGroupCreateInfoNV: {
		return "GraphicsShaderGroupCreateInfoNV";
	}
	case GraphicsPipelineShaderGroupsCreateInfoNV: {
		return "GraphicsPipelineShaderGroupsCreateInfoNV";
	}
	case IndirectCommandsLayoutTokenNV: {
		return "IndirectCommandsLayoutTokenNV";
	}
	case IndirectCommandsLayoutCreateInfoNV: {
		return "IndirectCommandsLayoutCreateInfoNV";
	}
	case GeneratedCommandsInfoNV: {
		return "GeneratedCommandsInfoNV";
	}
	case GeneratedCommandsMemoryRequirementsInfoNV: {
		return "GeneratedCommandsMemoryRequirementsInfoNV";
	}
	case PhysicalDeviceDeviceGeneratedCommandsFeaturesNV: {
		return "PhysicalDeviceDeviceGeneratedCommandsFeaturesNV";
	}
	case PhysicalDeviceInheritedViewportScissorFeaturesNV: {
		return "PhysicalDeviceInheritedViewportScissorFeaturesNV";
	}
	case CommandBufferInheritanceViewportScissorInfoNV: {
		return "CommandBufferInheritanceViewportScissorInfoNV";
	}
	case PhysicalDeviceShaderIntegerDotProductFeatures: {
		return "PhysicalDeviceShaderIntegerDotProductFeatures";
	}
	case PhysicalDeviceShaderIntegerDotProductProperties: {
		return "PhysicalDeviceShaderIntegerDotProductProperties";
	}
	case PhysicalDeviceTexelBufferAlignmentFeaturesEXT: {
		return "PhysicalDeviceTexelBufferAlignmentFeaturesEXT";
	}
	case PhysicalDeviceTexelBufferAlignmentProperties: {
		return "PhysicalDeviceTexelBufferAlignmentProperties";
	}
	case CommandBufferInheritanceRenderPassTransformInfoQCOM: {
		return "CommandBufferInheritanceRenderPassTransformInfoQCOM";
	}
	case RenderPassTransformBeginInfoQCOM: {
		return "RenderPassTransformBeginInfoQCOM";
	}
	case PhysicalDeviceDepthBiasControlFeaturesEXT: {
		return "PhysicalDeviceDepthBiasControlFeaturesEXT";
	}
	case DepthBiasInfoEXT: {
		return "DepthBiasInfoEXT";
	}
	case DepthBiasRepresentationInfoEXT: {
		return "DepthBiasRepresentationInfoEXT";
	}
	case PhysicalDeviceDeviceMemoryReportFeaturesEXT: {
		return "PhysicalDeviceDeviceMemoryReportFeaturesEXT";
	}
	case DeviceDeviceMemoryReportCreateInfoEXT: {
		return "DeviceDeviceMemoryReportCreateInfoEXT";
	}
	case DeviceMemoryReportCallbackDataEXT: {
		return "DeviceMemoryReportCallbackDataEXT";
	}
	case PhysicalDeviceRobustness2FeaturesKHR: {
		return "PhysicalDeviceRobustness2FeaturesKHR";
	}
	case PhysicalDeviceRobustness2PropertiesKHR: {
		return "PhysicalDeviceRobustness2PropertiesKHR";
	}
	case SamplerCustomBorderColorCreateInfoEXT: {
		return "SamplerCustomBorderColorCreateInfoEXT";
	}
	case PhysicalDeviceCustomBorderColorPropertiesEXT: {
		return "PhysicalDeviceCustomBorderColorPropertiesEXT";
	}
	case PhysicalDeviceCustomBorderColorFeaturesEXT: {
		return "PhysicalDeviceCustomBorderColorFeaturesEXT";
	}
	case PhysicalDeviceTextureCompressionAstc3DFeaturesEXT: {
		return "PhysicalDeviceTextureCompressionAstc3DFeaturesEXT";
	}
	case PipelineLibraryCreateInfoKHR: {
		return "PipelineLibraryCreateInfoKHR";
	}
	case PhysicalDevicePresentBarrierFeaturesNV: {
		return "PhysicalDevicePresentBarrierFeaturesNV";
	}
	case SurfaceCapabilitiesPresentBarrierNV: {
		return "SurfaceCapabilitiesPresentBarrierNV";
	}
	case SwapchainPresentBarrierCreateInfoNV: {
		return "SwapchainPresentBarrierCreateInfoNV";
	}
	case PresentIdKHR: {
		return "PresentIdKHR";
	}
	case PhysicalDevicePresentIdFeaturesKHR: {
		return "PhysicalDevicePresentIdFeaturesKHR";
	}
	case PhysicalDevicePrivateDataFeatures: {
		return "PhysicalDevicePrivateDataFeatures";
	}
	case DevicePrivateDataCreateInfo: {
		return "DevicePrivateDataCreateInfo";
	}
	case PrivateDataSlotCreateInfo: {
		return "PrivateDataSlotCreateInfo";
	}
	case PhysicalDevicePipelineCreationCacheControlFeatures: {
		return "PhysicalDevicePipelineCreationCacheControlFeatures";
	}
	case VideoEncodeInfoKHR: {
		return "VideoEncodeInfoKHR";
	}
	case VideoEncodeRateControlInfoKHR: {
		return "VideoEncodeRateControlInfoKHR";
	}
	case VideoEncodeRateControlLayerInfoKHR: {
		return "VideoEncodeRateControlLayerInfoKHR";
	}
	case VideoEncodeCapabilitiesKHR: {
		return "VideoEncodeCapabilitiesKHR";
	}
	case VideoEncodeUsageInfoKHR: {
		return "VideoEncodeUsageInfoKHR";
	}
	case QueryPoolVideoEncodeFeedbackCreateInfoKHR: {
		return "QueryPoolVideoEncodeFeedbackCreateInfoKHR";
	}
	case PhysicalDeviceVideoEncodeQualityLevelInfoKHR: {
		return "PhysicalDeviceVideoEncodeQualityLevelInfoKHR";
	}
	case VideoEncodeQualityLevelPropertiesKHR: {
		return "VideoEncodeQualityLevelPropertiesKHR";
	}
	case VideoEncodeQualityLevelInfoKHR: {
		return "VideoEncodeQualityLevelInfoKHR";
	}
	case VideoEncodeSessionParametersGetInfoKHR: {
		return "VideoEncodeSessionParametersGetInfoKHR";
	}
	case VideoEncodeSessionParametersFeedbackInfoKHR: {
		return "VideoEncodeSessionParametersFeedbackInfoKHR";
	}
	case PhysicalDeviceDiagnosticsConfigFeaturesNV: {
		return "PhysicalDeviceDiagnosticsConfigFeaturesNV";
	}
	case DeviceDiagnosticsConfigCreateInfoNV: {
		return "DeviceDiagnosticsConfigCreateInfoNV";
	}
	case PerfHintInfoQCOM: {
		return "PerfHintInfoQCOM";
	}
	case PhysicalDeviceQueuePerfHintFeaturesQCOM: {
		return "PhysicalDeviceQueuePerfHintFeaturesQCOM";
	}
	case PhysicalDeviceQueuePerfHintPropertiesQCOM: {
		return "PhysicalDeviceQueuePerfHintPropertiesQCOM";
	}
	case PhysicalDeviceImageProcessing3FeaturesQCOM: {
		return "PhysicalDeviceImageProcessing3FeaturesQCOM";
	}
	case PhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM: {
		return "PhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM";
	}
	case PhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM: {
		return "PhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM";
	}
	case PhysicalDeviceShaderSplitBarrierFeaturesEXT: {
		return "PhysicalDeviceShaderSplitBarrierFeaturesEXT";
	}
	case PhysicalDeviceShaderSplitBarrierPropertiesEXT: {
		return "PhysicalDeviceShaderSplitBarrierPropertiesEXT";
	}
	case CudaModuleCreateInfoNV: {
		return "CudaModuleCreateInfoNV";
	}
	case CudaFunctionCreateInfoNV: {
		return "CudaFunctionCreateInfoNV";
	}
	case CudaLaunchInfoNV: {
		return "CudaLaunchInfoNV";
	}
	case PhysicalDeviceCudaKernelLaunchFeaturesNV: {
		return "PhysicalDeviceCudaKernelLaunchFeaturesNV";
	}
	case PhysicalDeviceCudaKernelLaunchPropertiesNV: {
		return "PhysicalDeviceCudaKernelLaunchPropertiesNV";
	}
	case PhysicalDeviceTileShadingFeaturesQCOM: {
		return "PhysicalDeviceTileShadingFeaturesQCOM";
	}
	case PhysicalDeviceTileShadingPropertiesQCOM: {
		return "PhysicalDeviceTileShadingPropertiesQCOM";
	}
	case RenderPassTileShadingCreateInfoQCOM: {
		return "RenderPassTileShadingCreateInfoQCOM";
	}
	case PerTileBeginInfoQCOM: {
		return "PerTileBeginInfoQCOM";
	}
	case PerTileEndInfoQCOM: {
		return "PerTileEndInfoQCOM";
	}
	case DispatchTileInfoQCOM: {
		return "DispatchTileInfoQCOM";
	}
	case QueryLowLatencySupportNV: {
		return "QueryLowLatencySupportNV";
	}
	case ExportMetalObjectCreateInfoEXT: {
		return "ExportMetalObjectCreateInfoEXT";
	}
	case ExportMetalObjectsInfoEXT: {
		return "ExportMetalObjectsInfoEXT";
	}
	case ExportMetalDeviceInfoEXT: {
		return "ExportMetalDeviceInfoEXT";
	}
	case ExportMetalCommandQueueInfoEXT: {
		return "ExportMetalCommandQueueInfoEXT";
	}
	case ExportMetalBufferInfoEXT: {
		return "ExportMetalBufferInfoEXT";
	}
	case ImportMetalBufferInfoEXT: {
		return "ImportMetalBufferInfoEXT";
	}
	case ExportMetalTextureInfoEXT: {
		return "ExportMetalTextureInfoEXT";
	}
	case ImportMetalTextureInfoEXT: {
		return "ImportMetalTextureInfoEXT";
	}
	case ExportMetalIoSurfaceInfoEXT: {
		return "ExportMetalIoSurfaceInfoEXT";
	}
	case ImportMetalIoSurfaceInfoEXT: {
		return "ImportMetalIoSurfaceInfoEXT";
	}
	case ExportMetalSharedEventInfoEXT: {
		return "ExportMetalSharedEventInfoEXT";
	}
	case ImportMetalSharedEventInfoEXT: {
		return "ImportMetalSharedEventInfoEXT";
	}
	case MemoryBarrier2: {
		return "MemoryBarrier2";
	}
	case BufferMemoryBarrier2: {
		return "BufferMemoryBarrier2";
	}
	case ImageMemoryBarrier2: {
		return "ImageMemoryBarrier2";
	}
	case DependencyInfo: {
		return "DependencyInfo";
	}
	case SubmitInfo2: {
		return "SubmitInfo2";
	}
	case SemaphoreSubmitInfo: {
		return "SemaphoreSubmitInfo";
	}
	case CommandBufferSubmitInfo: {
		return "CommandBufferSubmitInfo";
	}
	case PhysicalDeviceSynchronization2Features: {
		return "PhysicalDeviceSynchronization2Features";
	}
	case QueueFamilyCheckpointProperties2NV: {
		return "QueueFamilyCheckpointProperties2NV";
	}
	case CheckpointData2NV: {
		return "CheckpointData2NV";
	}
	case PhysicalDeviceDescriptorBufferPropertiesEXT: {
		return "PhysicalDeviceDescriptorBufferPropertiesEXT";
	}
	case PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT: {
		return "PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT";
	}
	case PhysicalDeviceDescriptorBufferFeaturesEXT: {
		return "PhysicalDeviceDescriptorBufferFeaturesEXT";
	}
	case DescriptorAddressInfoEXT: {
		return "DescriptorAddressInfoEXT";
	}
	case DescriptorGetInfoEXT: {
		return "DescriptorGetInfoEXT";
	}
	case BufferCaptureDescriptorDataInfoEXT: {
		return "BufferCaptureDescriptorDataInfoEXT";
	}
	case ImageCaptureDescriptorDataInfoEXT: {
		return "ImageCaptureDescriptorDataInfoEXT";
	}
	case ImageViewCaptureDescriptorDataInfoEXT: {
		return "ImageViewCaptureDescriptorDataInfoEXT";
	}
	case SamplerCaptureDescriptorDataInfoEXT: {
		return "SamplerCaptureDescriptorDataInfoEXT";
	}
	case AccelerationStructureCaptureDescriptorDataInfoEXT: {
		return "AccelerationStructureCaptureDescriptorDataInfoEXT";
	}
	case OpaqueCaptureDescriptorDataCreateInfoEXT: {
		return "OpaqueCaptureDescriptorDataCreateInfoEXT";
	}
	case DescriptorBufferBindingInfoEXT: {
		return "DescriptorBufferBindingInfoEXT";
	}
	case DescriptorBufferBindingPushDescriptorBufferHandleEXT: {
		return "DescriptorBufferBindingPushDescriptorBufferHandleEXT";
	}
	case DeviceMemoryCopyKHR: {
		return "DeviceMemoryCopyKHR";
	}
	case CopyDeviceMemoryInfoKHR: {
		return "CopyDeviceMemoryInfoKHR";
	}
	case DeviceMemoryImageCopyKHR: {
		return "DeviceMemoryImageCopyKHR";
	}
	case CopyDeviceMemoryImageInfoKHR: {
		return "CopyDeviceMemoryImageInfoKHR";
	}
	case MemoryRangeBarriersInfoKHR: {
		return "MemoryRangeBarriersInfoKHR";
	}
	case MemoryRangeBarrierKHR: {
		return "MemoryRangeBarrierKHR";
	}
	case PhysicalDeviceDeviceAddressCommandsFeaturesKHR: {
		return "PhysicalDeviceDeviceAddressCommandsFeaturesKHR";
	}
	case BindIndexBuffer3InfoKHR: {
		return "BindIndexBuffer3InfoKHR";
	}
	case BindVertexBuffer3InfoKHR: {
		return "BindVertexBuffer3InfoKHR";
	}
	case DrawIndirect2InfoKHR: {
		return "DrawIndirect2InfoKHR";
	}
	case DrawIndirectCount2InfoKHR: {
		return "DrawIndirectCount2InfoKHR";
	}
	case DispatchIndirect2InfoKHR: {
		return "DispatchIndirect2InfoKHR";
	}
	case ConditionalRenderingBeginInfo2EXT: {
		return "ConditionalRenderingBeginInfo2EXT";
	}
	case BindTransformFeedbackBuffer2InfoEXT: {
		return "BindTransformFeedbackBuffer2InfoEXT";
	}
	case MemoryMarkerInfoAMD: {
		return "MemoryMarkerInfoAMD";
	}
	case AccelerationStructureCreateInfo2KHR: {
		return "AccelerationStructureCreateInfo2KHR";
	}
	case PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT: {
		return "PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT";
	}
	case PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT: {
		return "PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT";
	}
	case GraphicsPipelineLibraryCreateInfoEXT: {
		return "GraphicsPipelineLibraryCreateInfoEXT";
	}
	case PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD: {
		return "PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD";
	}
	case PhysicalDeviceFragmentShaderBarycentricPropertiesKHR: {
		return "PhysicalDeviceFragmentShaderBarycentricPropertiesKHR";
	}
	case PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR: {
		return "PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR";
	}
	case PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures: {
		return "PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures";
	}
	case PhysicalDeviceFragmentShadingRateEnumsPropertiesNV: {
		return "PhysicalDeviceFragmentShadingRateEnumsPropertiesNV";
	}
	case PhysicalDeviceFragmentShadingRateEnumsFeaturesNV: {
		return "PhysicalDeviceFragmentShadingRateEnumsFeaturesNV";
	}
	case PipelineFragmentShadingRateEnumStateCreateInfoNV: {
		return "PipelineFragmentShadingRateEnumStateCreateInfoNV";
	}
	case AccelerationStructureGeometryMotionTrianglesDataNV: {
		return "AccelerationStructureGeometryMotionTrianglesDataNV";
	}
	case PhysicalDeviceRayTracingMotionBlurFeaturesNV: {
		return "PhysicalDeviceRayTracingMotionBlurFeaturesNV";
	}
	case AccelerationStructureMotionInfoNV: {
		return "AccelerationStructureMotionInfoNV";
	}
	case PhysicalDeviceMeshShaderFeaturesEXT: {
		return "PhysicalDeviceMeshShaderFeaturesEXT";
	}
	case PhysicalDeviceMeshShaderPropertiesEXT: {
		return "PhysicalDeviceMeshShaderPropertiesEXT";
	}
	case PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT: {
		return "PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT";
	}
	case PhysicalDeviceFragmentDensityMap2FeaturesEXT: {
		return "PhysicalDeviceFragmentDensityMap2FeaturesEXT";
	}
	case PhysicalDeviceFragmentDensityMap2PropertiesEXT: {
		return "PhysicalDeviceFragmentDensityMap2PropertiesEXT";
	}
	case CopyCommandTransformInfoQCOM: {
		return "CopyCommandTransformInfoQCOM";
	}
	case PhysicalDeviceImageRobustnessFeatures: {
		return "PhysicalDeviceImageRobustnessFeatures";
	}
	case PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR: {
		return "PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR";
	}
	case CopyBufferInfo2: {
		return "CopyBufferInfo2";
	}
	case CopyImageInfo2: {
		return "CopyImageInfo2";
	}
	case CopyBufferToImageInfo2: {
		return "CopyBufferToImageInfo2";
	}
	case CopyImageToBufferInfo2: {
		return "CopyImageToBufferInfo2";
	}
	case BlitImageInfo2: {
		return "BlitImageInfo2";
	}
	case ResolveImageInfo2: {
		return "ResolveImageInfo2";
	}
	case BufferCopy2: {
		return "BufferCopy2";
	}
	case ImageCopy2: {
		return "ImageCopy2";
	}
	case ImageBlit2: {
		return "ImageBlit2";
	}
	case BufferImageCopy2: {
		return "BufferImageCopy2";
	}
	case ImageResolve2: {
		return "ImageResolve2";
	}
	case PhysicalDeviceImageCompressionControlFeaturesEXT: {
		return "PhysicalDeviceImageCompressionControlFeaturesEXT";
	}
	case ImageCompressionControlEXT: {
		return "ImageCompressionControlEXT";
	}
	case SubresourceLayout2: {
		return "SubresourceLayout2";
	}
	case ImageSubresource2: {
		return "ImageSubresource2";
	}
	case ImageCompressionPropertiesEXT: {
		return "ImageCompressionPropertiesEXT";
	}
	case PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT: {
		return "PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT";
	}
	case PhysicalDevice4444FormatsFeaturesEXT: {
		return "PhysicalDevice4444FormatsFeaturesEXT";
	}
	case PhysicalDeviceFaultFeaturesEXT: {
		return "PhysicalDeviceFaultFeaturesEXT";
	}
	case DeviceFaultCountsEXT: {
		return "DeviceFaultCountsEXT";
	}
	case DeviceFaultInfoEXT: {
		return "DeviceFaultInfoEXT";
	}
	case PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT: {
		return "PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT";
	}
	case PhysicalDeviceRgba10x6FormatsFeaturesEXT: {
		return "PhysicalDeviceRgba10x6FormatsFeaturesEXT";
	}
	case DirectfbSurfaceCreateInfoEXT: {
		return "DirectfbSurfaceCreateInfoEXT";
	}
	case PhysicalDeviceRayTracingPipelineFeaturesKHR: {
		return "PhysicalDeviceRayTracingPipelineFeaturesKHR";
	}
	case PhysicalDeviceRayTracingPipelinePropertiesKHR: {
		return "PhysicalDeviceRayTracingPipelinePropertiesKHR";
	}
	case PhysicalDeviceRayQueryFeaturesKHR: {
		return "PhysicalDeviceRayQueryFeaturesKHR";
	}
	case PhysicalDeviceMutableDescriptorTypeFeaturesEXT: {
		return "PhysicalDeviceMutableDescriptorTypeFeaturesEXT";
	}
	case MutableDescriptorTypeCreateInfoEXT: {
		return "MutableDescriptorTypeCreateInfoEXT";
	}
	case PhysicalDeviceVertexInputDynamicStateFeaturesEXT: {
		return "PhysicalDeviceVertexInputDynamicStateFeaturesEXT";
	}
	case VertexInputBindingDescription2EXT: {
		return "VertexInputBindingDescription2EXT";
	}
	case VertexInputAttributeDescription2EXT: {
		return "VertexInputAttributeDescription2EXT";
	}
	case PhysicalDeviceDrmPropertiesEXT: {
		return "PhysicalDeviceDrmPropertiesEXT";
	}
	case PhysicalDeviceAddressBindingReportFeaturesEXT: {
		return "PhysicalDeviceAddressBindingReportFeaturesEXT";
	}
	case DeviceAddressBindingCallbackDataEXT: {
		return "DeviceAddressBindingCallbackDataEXT";
	}
	case PhysicalDeviceDepthClipControlFeaturesEXT: {
		return "PhysicalDeviceDepthClipControlFeaturesEXT";
	}
	case PipelineViewportDepthClipControlCreateInfoEXT: {
		return "PipelineViewportDepthClipControlCreateInfoEXT";
	}
	case PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT: {
		return "PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT";
	}
	case FormatProperties3: {
		return "FormatProperties3";
	}
	case PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR: {
		return "PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR";
	}
	case ImportMemoryZirconHandleInfoFUCHSIA: {
		return "ImportMemoryZirconHandleInfoFUCHSIA";
	}
	case MemoryZirconHandlePropertiesFUCHSIA: {
		return "MemoryZirconHandlePropertiesFUCHSIA";
	}
	case MemoryGetZirconHandleInfoFUCHSIA: {
		return "MemoryGetZirconHandleInfoFUCHSIA";
	}
	case ImportSemaphoreZirconHandleInfoFUCHSIA: {
		return "ImportSemaphoreZirconHandleInfoFUCHSIA";
	}
	case SemaphoreGetZirconHandleInfoFUCHSIA: {
		return "SemaphoreGetZirconHandleInfoFUCHSIA";
	}
	case BufferCollectionCreateInfoFUCHSIA: {
		return "BufferCollectionCreateInfoFUCHSIA";
	}
	case ImportMemoryBufferCollectionFUCHSIA: {
		return "ImportMemoryBufferCollectionFUCHSIA";
	}
	case BufferCollectionImageCreateInfoFUCHSIA: {
		return "BufferCollectionImageCreateInfoFUCHSIA";
	}
	case BufferCollectionPropertiesFUCHSIA: {
		return "BufferCollectionPropertiesFUCHSIA";
	}
	case BufferConstraintsInfoFUCHSIA: {
		return "BufferConstraintsInfoFUCHSIA";
	}
	case BufferCollectionBufferCreateInfoFUCHSIA: {
		return "BufferCollectionBufferCreateInfoFUCHSIA";
	}
	case ImageConstraintsInfoFUCHSIA: {
		return "ImageConstraintsInfoFUCHSIA";
	}
	case ImageFormatConstraintsInfoFUCHSIA: {
		return "ImageFormatConstraintsInfoFUCHSIA";
	}
	case SysmemColorSpaceFUCHSIA: {
		return "SysmemColorSpaceFUCHSIA";
	}
	case BufferCollectionConstraintsInfoFUCHSIA: {
		return "BufferCollectionConstraintsInfoFUCHSIA";
	}
	case SubpassShadingPipelineCreateInfoHUAWEI: {
		return "SubpassShadingPipelineCreateInfoHUAWEI";
	}
	case PhysicalDeviceSubpassShadingFeaturesHUAWEI: {
		return "PhysicalDeviceSubpassShadingFeaturesHUAWEI";
	}
	case PhysicalDeviceSubpassShadingPropertiesHUAWEI: {
		return "PhysicalDeviceSubpassShadingPropertiesHUAWEI";
	}
	case PhysicalDeviceInvocationMaskFeaturesHUAWEI: {
		return "PhysicalDeviceInvocationMaskFeaturesHUAWEI";
	}
	case MemoryGetRemoteAddressInfoNV: {
		return "MemoryGetRemoteAddressInfoNV";
	}
	case PhysicalDeviceExternalMemoryRdmaFeaturesNV: {
		return "PhysicalDeviceExternalMemoryRdmaFeaturesNV";
	}
	case PipelinePropertiesIdentifierEXT: {
		return "PipelinePropertiesIdentifierEXT";
	}
	case PhysicalDevicePipelinePropertiesFeaturesEXT: {
		return "PhysicalDevicePipelinePropertiesFeaturesEXT";
	}
	case PhysicalDeviceFrameBoundaryFeaturesEXT: {
		return "PhysicalDeviceFrameBoundaryFeaturesEXT";
	}
	case FrameBoundaryEXT: {
		return "FrameBoundaryEXT";
	}
	case PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT: {
		return "PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT";
	}
	case SubpassResolvePerformanceQueryEXT: {
		return "SubpassResolvePerformanceQueryEXT";
	}
	case MultisampledRenderToSingleSampledInfoEXT: {
		return "MultisampledRenderToSingleSampledInfoEXT";
	}
	case PhysicalDeviceExtendedDynamicState2FeaturesEXT: {
		return "PhysicalDeviceExtendedDynamicState2FeaturesEXT";
	}
	case ScreenSurfaceCreateInfoQNX: {
		return "ScreenSurfaceCreateInfoQNX";
	}
	case PhysicalDeviceColorWriteEnableFeaturesEXT: {
		return "PhysicalDeviceColorWriteEnableFeaturesEXT";
	}
	case PipelineColorWriteCreateInfoEXT: {
		return "PipelineColorWriteCreateInfoEXT";
	}
	case PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT: {
		return "PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT";
	}
	case PhysicalDeviceRayTracingMaintenance1FeaturesKHR: {
		return "PhysicalDeviceRayTracingMaintenance1FeaturesKHR";
	}
	case PhysicalDeviceShaderUntypedPointersFeaturesKHR: {
		return "PhysicalDeviceShaderUntypedPointersFeaturesKHR";
	}
	case PhysicalDeviceGlobalPriorityQueryFeatures: {
		return "PhysicalDeviceGlobalPriorityQueryFeatures";
	}
	case QueueFamilyGlobalPriorityProperties: {
		return "QueueFamilyGlobalPriorityProperties";
	}
	case PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE: {
		return "PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE";
	}
	case VideoEncodeRgbConversionCapabilitiesVALVE: {
		return "VideoEncodeRgbConversionCapabilitiesVALVE";
	}
	case VideoEncodeProfileRgbConversionInfoVALVE: {
		return "VideoEncodeProfileRgbConversionInfoVALVE";
	}
	case VideoEncodeSessionRgbConversionCreateInfoVALVE: {
		return "VideoEncodeSessionRgbConversionCreateInfoVALVE";
	}
	case PhysicalDeviceImageViewMinLodFeaturesEXT: {
		return "PhysicalDeviceImageViewMinLodFeaturesEXT";
	}
	case ImageViewMinLodCreateInfoEXT: {
		return "ImageViewMinLodCreateInfoEXT";
	}
	case PhysicalDeviceMultiDrawFeaturesEXT: {
		return "PhysicalDeviceMultiDrawFeaturesEXT";
	}
	case PhysicalDeviceMultiDrawPropertiesEXT: {
		return "PhysicalDeviceMultiDrawPropertiesEXT";
	}
	case PhysicalDeviceImage2DViewOf3DFeaturesEXT: {
		return "PhysicalDeviceImage2DViewOf3DFeaturesEXT";
	}
	case PhysicalDeviceShaderTileImageFeaturesEXT: {
		return "PhysicalDeviceShaderTileImageFeaturesEXT";
	}
	case PhysicalDeviceShaderTileImagePropertiesEXT: {
		return "PhysicalDeviceShaderTileImagePropertiesEXT";
	}
	case MicromapBuildInfoEXT: {
		return "MicromapBuildInfoEXT";
	}
	case MicromapVersionInfoEXT: {
		return "MicromapVersionInfoEXT";
	}
	case CopyMicromapInfoEXT: {
		return "CopyMicromapInfoEXT";
	}
	case CopyMicromapToMemoryInfoEXT: {
		return "CopyMicromapToMemoryInfoEXT";
	}
	case CopyMemoryToMicromapInfoEXT: {
		return "CopyMemoryToMicromapInfoEXT";
	}
	case PhysicalDeviceOpacityMicromapFeaturesEXT: {
		return "PhysicalDeviceOpacityMicromapFeaturesEXT";
	}
	case PhysicalDeviceOpacityMicromapPropertiesEXT: {
		return "PhysicalDeviceOpacityMicromapPropertiesEXT";
	}
	case MicromapCreateInfoEXT: {
		return "MicromapCreateInfoEXT";
	}
	case MicromapBuildSizesInfoEXT: {
		return "MicromapBuildSizesInfoEXT";
	}
	case AccelerationStructureTrianglesOpacityMicromapEXT: {
		return "AccelerationStructureTrianglesOpacityMicromapEXT";
	}
	case PhysicalDeviceDisplacementMicromapFeaturesNV: {
		return "PhysicalDeviceDisplacementMicromapFeaturesNV";
	}
	case PhysicalDeviceDisplacementMicromapPropertiesNV: {
		return "PhysicalDeviceDisplacementMicromapPropertiesNV";
	}
	case AccelerationStructureTrianglesDisplacementMicromapNV: {
		return "AccelerationStructureTrianglesDisplacementMicromapNV";
	}
	case PhysicalDeviceClusterCullingShaderFeaturesHUAWEI: {
		return "PhysicalDeviceClusterCullingShaderFeaturesHUAWEI";
	}
	case PhysicalDeviceClusterCullingShaderPropertiesHUAWEI: {
		return "PhysicalDeviceClusterCullingShaderPropertiesHUAWEI";
	}
	case PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI: {
		return "PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI";
	}
	case PhysicalDeviceBorderColorSwizzleFeaturesEXT: {
		return "PhysicalDeviceBorderColorSwizzleFeaturesEXT";
	}
	case SamplerBorderColorComponentMappingCreateInfoEXT: {
		return "SamplerBorderColorComponentMappingCreateInfoEXT";
	}
	case PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT: {
		return "PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT";
	}
	case PhysicalDeviceMaintenance4Features: {
		return "PhysicalDeviceMaintenance4Features";
	}
	case PhysicalDeviceMaintenance4Properties: {
		return "PhysicalDeviceMaintenance4Properties";
	}
	case DeviceBufferMemoryRequirements: {
		return "DeviceBufferMemoryRequirements";
	}
	case DeviceImageMemoryRequirements: {
		return "DeviceImageMemoryRequirements";
	}
	case PhysicalDeviceShaderCorePropertiesARM: {
		return "PhysicalDeviceShaderCorePropertiesARM";
	}
	case PhysicalDeviceShaderSubgroupRotateFeatures: {
		return "PhysicalDeviceShaderSubgroupRotateFeatures";
	}
	case DeviceQueueShaderCoreControlCreateInfoARM: {
		return "DeviceQueueShaderCoreControlCreateInfoARM";
	}
	case PhysicalDeviceSchedulingControlsFeaturesARM: {
		return "PhysicalDeviceSchedulingControlsFeaturesARM";
	}
	case PhysicalDeviceSchedulingControlsPropertiesARM: {
		return "PhysicalDeviceSchedulingControlsPropertiesARM";
	}
	case DispatchParametersARM: {
		return "DispatchParametersARM";
	}
	case PhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM: {
		return "PhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM";
	}
	case PhysicalDeviceImageSlicedViewOf3DFeaturesEXT: {
		return "PhysicalDeviceImageSlicedViewOf3DFeaturesEXT";
	}
	case ImageViewSlicedCreateInfoEXT: {
		return "ImageViewSlicedCreateInfoEXT";
	}
	case PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE: {
		return "PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE";
	}
	case DescriptorSetBindingReferenceVALVE: {
		return "DescriptorSetBindingReferenceVALVE";
	}
	case DescriptorSetLayoutHostMappingInfoVALVE: {
		return "DescriptorSetLayoutHostMappingInfoVALVE";
	}
	case PhysicalDeviceDepthClampZeroOneFeaturesKHR: {
		return "PhysicalDeviceDepthClampZeroOneFeaturesKHR";
	}
	case PhysicalDeviceNonSeamlessCubeMapFeaturesEXT: {
		return "PhysicalDeviceNonSeamlessCubeMapFeaturesEXT";
	}
	case PhysicalDeviceRenderPassStripedFeaturesARM: {
		return "PhysicalDeviceRenderPassStripedFeaturesARM";
	}
	case PhysicalDeviceRenderPassStripedPropertiesARM: {
		return "PhysicalDeviceRenderPassStripedPropertiesARM";
	}
	case RenderPassStripeBeginInfoARM: {
		return "RenderPassStripeBeginInfoARM";
	}
	case RenderPassStripeInfoARM: {
		return "RenderPassStripeInfoARM";
	}
	case RenderPassStripeSubmitInfoARM: {
		return "RenderPassStripeSubmitInfoARM";
	}
	case PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT: {
		return "PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT";
	}
	case PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT: {
		return "PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT";
	}
	case RenderPassFragmentDensityMapOffsetEndInfoEXT: {
		return "RenderPassFragmentDensityMapOffsetEndInfoEXT";
	}
	case PhysicalDeviceCopyMemoryIndirectFeaturesNV: {
		return "PhysicalDeviceCopyMemoryIndirectFeaturesNV";
	}
	case PhysicalDeviceCopyMemoryIndirectPropertiesKHR: {
		return "PhysicalDeviceCopyMemoryIndirectPropertiesKHR";
	}
	case PhysicalDeviceMemoryDecompressionFeaturesEXT: {
		return "PhysicalDeviceMemoryDecompressionFeaturesEXT";
	}
	case PhysicalDeviceMemoryDecompressionPropertiesEXT: {
		return "PhysicalDeviceMemoryDecompressionPropertiesEXT";
	}
	case PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV: {
		return "PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV";
	}
	case ComputePipelineIndirectBufferInfoNV: {
		return "ComputePipelineIndirectBufferInfoNV";
	}
	case PipelineIndirectDeviceAddressInfoNV: {
		return "PipelineIndirectDeviceAddressInfoNV";
	}
	case PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV: {
		return "PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV";
	}
	case AccelerationStructureGeometryLinearSweptSpheresDataNV: {
		return "AccelerationStructureGeometryLinearSweptSpheresDataNV";
	}
	case AccelerationStructureGeometrySpheresDataNV: {
		return "AccelerationStructureGeometrySpheresDataNV";
	}
	case PhysicalDeviceLinearColorAttachmentFeaturesNV: {
		return "PhysicalDeviceLinearColorAttachmentFeaturesNV";
	}
	case PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR: {
		return "PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR";
	}
	case PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT: {
		return "PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT";
	}
	case PhysicalDeviceImageProcessingFeaturesQCOM: {
		return "PhysicalDeviceImageProcessingFeaturesQCOM";
	}
	case PhysicalDeviceImageProcessingPropertiesQCOM: {
		return "PhysicalDeviceImageProcessingPropertiesQCOM";
	}
	case ImageViewSampleWeightCreateInfoQCOM: {
		return "ImageViewSampleWeightCreateInfoQCOM";
	}
	case PhysicalDeviceNestedCommandBufferFeaturesEXT: {
		return "PhysicalDeviceNestedCommandBufferFeaturesEXT";
	}
	case PhysicalDeviceNestedCommandBufferPropertiesEXT: {
		return "PhysicalDeviceNestedCommandBufferPropertiesEXT";
	}
	case NativeBufferUsageOHOS: {
		return "NativeBufferUsageOHOS";
	}
	case NativeBufferPropertiesOHOS: {
		return "NativeBufferPropertiesOHOS";
	}
	case NativeBufferFormatPropertiesOHOS: {
		return "NativeBufferFormatPropertiesOHOS";
	}
	case ImportNativeBufferInfoOHOS: {
		return "ImportNativeBufferInfoOHOS";
	}
	case MemoryGetNativeBufferInfoOHOS: {
		return "MemoryGetNativeBufferInfoOHOS";
	}
	case ExternalFormatOHOS: {
		return "ExternalFormatOHOS";
	}
	case ExternalMemoryAcquireUnmodifiedEXT: {
		return "ExternalMemoryAcquireUnmodifiedEXT";
	}
	case PhysicalDeviceExtendedDynamicState3FeaturesEXT: {
		return "PhysicalDeviceExtendedDynamicState3FeaturesEXT";
	}
	case PhysicalDeviceExtendedDynamicState3PropertiesEXT: {
		return "PhysicalDeviceExtendedDynamicState3PropertiesEXT";
	}
	case PhysicalDeviceSubpassMergeFeedbackFeaturesEXT: {
		return "PhysicalDeviceSubpassMergeFeedbackFeaturesEXT";
	}
	case RenderPassCreationControlEXT: {
		return "RenderPassCreationControlEXT";
	}
	case RenderPassCreationFeedbackCreateInfoEXT: {
		return "RenderPassCreationFeedbackCreateInfoEXT";
	}
	case RenderPassSubpassFeedbackCreateInfoEXT: {
		return "RenderPassSubpassFeedbackCreateInfoEXT";
	}
	case DirectDriverLoadingInfoLUNARG: {
		return "DirectDriverLoadingInfoLUNARG";
	}
	case DirectDriverLoadingListLUNARG: {
		return "DirectDriverLoadingListLUNARG";
	}
	case TensorCreateInfoARM: {
		return "TensorCreateInfoARM";
	}
	case TensorViewCreateInfoARM: {
		return "TensorViewCreateInfoARM";
	}
	case BindTensorMemoryInfoARM: {
		return "BindTensorMemoryInfoARM";
	}
	case WriteDescriptorSetTensorARM: {
		return "WriteDescriptorSetTensorARM";
	}
	case PhysicalDeviceTensorPropertiesARM: {
		return "PhysicalDeviceTensorPropertiesARM";
	}
	case TensorFormatPropertiesARM: {
		return "TensorFormatPropertiesARM";
	}
	case TensorDescriptionARM: {
		return "TensorDescriptionARM";
	}
	case TensorMemoryRequirementsInfoARM: {
		return "TensorMemoryRequirementsInfoARM";
	}
	case TensorMemoryBarrierARM: {
		return "TensorMemoryBarrierARM";
	}
	case PhysicalDeviceTensorFeaturesARM: {
		return "PhysicalDeviceTensorFeaturesARM";
	}
	case DeviceTensorMemoryRequirementsARM: {
		return "DeviceTensorMemoryRequirementsARM";
	}
	case CopyTensorInfoARM: {
		return "CopyTensorInfoARM";
	}
	case TensorCopyARM: {
		return "TensorCopyARM";
	}
	case TensorDependencyInfoARM: {
		return "TensorDependencyInfoARM";
	}
	case MemoryDedicatedAllocateInfoTensorARM: {
		return "MemoryDedicatedAllocateInfoTensorARM";
	}
	case PhysicalDeviceExternalTensorInfoARM: {
		return "PhysicalDeviceExternalTensorInfoARM";
	}
	case ExternalTensorPropertiesARM: {
		return "ExternalTensorPropertiesARM";
	}
	case ExternalMemoryTensorCreateInfoARM: {
		return "ExternalMemoryTensorCreateInfoARM";
	}
	case PhysicalDeviceDescriptorBufferTensorFeaturesARM: {
		return "PhysicalDeviceDescriptorBufferTensorFeaturesARM";
	}
	case PhysicalDeviceDescriptorBufferTensorPropertiesARM: {
		return "PhysicalDeviceDescriptorBufferTensorPropertiesARM";
	}
	case DescriptorGetTensorInfoARM: {
		return "DescriptorGetTensorInfoARM";
	}
	case TensorCaptureDescriptorDataInfoARM: {
		return "TensorCaptureDescriptorDataInfoARM";
	}
	case TensorViewCaptureDescriptorDataInfoARM: {
		return "TensorViewCaptureDescriptorDataInfoARM";
	}
	case FrameBoundaryTensorsARM: {
		return "FrameBoundaryTensorsARM";
	}
	case PhysicalDeviceShaderModuleIdentifierFeaturesEXT: {
		return "PhysicalDeviceShaderModuleIdentifierFeaturesEXT";
	}
	case PhysicalDeviceShaderModuleIdentifierPropertiesEXT: {
		return "PhysicalDeviceShaderModuleIdentifierPropertiesEXT";
	}
	case PipelineShaderStageModuleIdentifierCreateInfoEXT: {
		return "PipelineShaderStageModuleIdentifierCreateInfoEXT";
	}
	case ShaderModuleIdentifierEXT: {
		return "ShaderModuleIdentifierEXT";
	}
	case PhysicalDeviceOpticalFlowFeaturesNV: {
		return "PhysicalDeviceOpticalFlowFeaturesNV";
	}
	case PhysicalDeviceOpticalFlowPropertiesNV: {
		return "PhysicalDeviceOpticalFlowPropertiesNV";
	}
	case OpticalFlowImageFormatInfoNV: {
		return "OpticalFlowImageFormatInfoNV";
	}
	case OpticalFlowImageFormatPropertiesNV: {
		return "OpticalFlowImageFormatPropertiesNV";
	}
	case OpticalFlowSessionCreateInfoNV: {
		return "OpticalFlowSessionCreateInfoNV";
	}
	case OpticalFlowExecuteInfoNV: {
		return "OpticalFlowExecuteInfoNV";
	}
	case OpticalFlowSessionCreatePrivateDataInfoNV: {
		return "OpticalFlowSessionCreatePrivateDataInfoNV";
	}
	case PhysicalDeviceLegacyDitheringFeaturesEXT: {
		return "PhysicalDeviceLegacyDitheringFeaturesEXT";
	}
	case PhysicalDevicePipelineProtectedAccessFeatures: {
		return "PhysicalDevicePipelineProtectedAccessFeatures";
	}
	case PhysicalDeviceExternalFormatResolveFeaturesANDROID: {
		return "PhysicalDeviceExternalFormatResolveFeaturesANDROID";
	}
	case PhysicalDeviceExternalFormatResolvePropertiesANDROID: {
		return "PhysicalDeviceExternalFormatResolvePropertiesANDROID";
	}
	case ANDROIDHardwareBufferFormatResolvePropertiesANDROID: {
		return "ANDROIDHardwareBufferFormatResolvePropertiesANDROID";
	}
	case PhysicalDeviceMaintenance5Features: {
		return "PhysicalDeviceMaintenance5Features";
	}
	case PhysicalDeviceMaintenance5Properties: {
		return "PhysicalDeviceMaintenance5Properties";
	}
	case RenderingAreaInfo: {
		return "RenderingAreaInfo";
	}
	case DeviceImageSubresourceInfo: {
		return "DeviceImageSubresourceInfo";
	}
	case PipelineCreateFlags2CreateInfo: {
		return "PipelineCreateFlags2CreateInfo";
	}
	case BufferUsageFlags2CreateInfo: {
		return "BufferUsageFlags2CreateInfo";
	}
	case PhysicalDeviceAntiLagFeaturesAMD: {
		return "PhysicalDeviceAntiLagFeaturesAMD";
	}
	case AntiLagDataAMD: {
		return "AntiLagDataAMD";
	}
	case AntiLagPresentationInfoAMD: {
		return "AntiLagPresentationInfoAMD";
	}
	case PhysicalDeviceDenseGeometryFormatFeaturesAMDX: {
		return "PhysicalDeviceDenseGeometryFormatFeaturesAMDX";
	}
	case AccelerationStructureDenseGeometryFormatTrianglesDataAMDX: {
		return "AccelerationStructureDenseGeometryFormatTrianglesDataAMDX";
	}
	case SurfaceCapabilitiesPresentId2KHR: {
		return "SurfaceCapabilitiesPresentId2KHR";
	}
	case PresentId2KHR: {
		return "PresentId2KHR";
	}
	case PhysicalDevicePresentId2FeaturesKHR: {
		return "PhysicalDevicePresentId2FeaturesKHR";
	}
	case SurfaceCapabilitiesPresentWait2KHR: {
		return "SurfaceCapabilitiesPresentWait2KHR";
	}
	case PhysicalDevicePresentWait2FeaturesKHR: {
		return "PhysicalDevicePresentWait2FeaturesKHR";
	}
	case PresentWait2InfoKHR: {
		return "PresentWait2InfoKHR";
	}
	case PhysicalDeviceRayTracingPositionFetchFeaturesKHR: {
		return "PhysicalDeviceRayTracingPositionFetchFeaturesKHR";
	}
	case PhysicalDeviceShaderObjectFeaturesEXT: {
		return "PhysicalDeviceShaderObjectFeaturesEXT";
	}
	case PhysicalDeviceShaderObjectPropertiesEXT: {
		return "PhysicalDeviceShaderObjectPropertiesEXT";
	}
	case ShaderCreateInfoEXT: {
		return "ShaderCreateInfoEXT";
	}
	case PhysicalDevicePipelineBinaryFeaturesKHR: {
		return "PhysicalDevicePipelineBinaryFeaturesKHR";
	}
	case PipelineBinaryCreateInfoKHR: {
		return "PipelineBinaryCreateInfoKHR";
	}
	case PipelineBinaryInfoKHR: {
		return "PipelineBinaryInfoKHR";
	}
	case PipelineBinaryKeyKHR: {
		return "PipelineBinaryKeyKHR";
	}
	case PhysicalDevicePipelineBinaryPropertiesKHR: {
		return "PhysicalDevicePipelineBinaryPropertiesKHR";
	}
	case ReleaseCapturedPipelineDataInfoKHR: {
		return "ReleaseCapturedPipelineDataInfoKHR";
	}
	case PipelineBinaryDataInfoKHR: {
		return "PipelineBinaryDataInfoKHR";
	}
	case PipelineCreateInfoKHR: {
		return "PipelineCreateInfoKHR";
	}
	case DevicePipelineBinaryInternalCacheControlKHR: {
		return "DevicePipelineBinaryInternalCacheControlKHR";
	}
	case PipelineBinaryHandlesInfoKHR: {
		return "PipelineBinaryHandlesInfoKHR";
	}
	case PhysicalDeviceTilePropertiesFeaturesQCOM: {
		return "PhysicalDeviceTilePropertiesFeaturesQCOM";
	}
	case TilePropertiesQCOM: {
		return "TilePropertiesQCOM";
	}
	case PhysicalDeviceAmigoProfilingFeaturesSEC: {
		return "PhysicalDeviceAmigoProfilingFeaturesSEC";
	}
	case AmigoProfilingSubmitInfoSEC: {
		return "AmigoProfilingSubmitInfoSEC";
	}
	case PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM: {
		return "PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM";
	}
	case PhysicalDeviceRayTracingInvocationReorderFeaturesNV: {
		return "PhysicalDeviceRayTracingInvocationReorderFeaturesNV";
	}
	case PhysicalDeviceRayTracingInvocationReorderPropertiesNV: {
		return "PhysicalDeviceRayTracingInvocationReorderPropertiesNV";
	}
	case PhysicalDeviceCooperativeVectorFeaturesNV: {
		return "PhysicalDeviceCooperativeVectorFeaturesNV";
	}
	case PhysicalDeviceCooperativeVectorPropertiesNV: {
		return "PhysicalDeviceCooperativeVectorPropertiesNV";
	}
	case CooperativeVectorPropertiesNV: {
		return "CooperativeVectorPropertiesNV";
	}
	case ConvertCooperativeVectorMatrixInfoNV: {
		return "ConvertCooperativeVectorMatrixInfoNV";
	}
	case PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV: {
		return "PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV";
	}
	case PhysicalDeviceExtendedSparseAddressSpacePropertiesNV: {
		return "PhysicalDeviceExtendedSparseAddressSpacePropertiesNV";
	}
	case PhysicalDeviceLegacyVertexAttributesFeaturesEXT: {
		return "PhysicalDeviceLegacyVertexAttributesFeaturesEXT";
	}
	case PhysicalDeviceLegacyVertexAttributesPropertiesEXT: {
		return "PhysicalDeviceLegacyVertexAttributesPropertiesEXT";
	}
	case LayerSettingsCreateInfoEXT: {
		return "LayerSettingsCreateInfoEXT";
	}
	case PhysicalDeviceShaderCoreBuiltinsFeaturesARM: {
		return "PhysicalDeviceShaderCoreBuiltinsFeaturesARM";
	}
	case PhysicalDeviceShaderCoreBuiltinsPropertiesARM: {
		return "PhysicalDeviceShaderCoreBuiltinsPropertiesARM";
	}
	case PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT: {
		return "PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT";
	}
	case PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT: {
		return "PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT";
	}
	case PhysicalDeviceInternallySynchronizedQueuesFeaturesKHR: {
		return "PhysicalDeviceInternallySynchronizedQueuesFeaturesKHR";
	}
	case LatencySleepModeInfoNV: {
		return "LatencySleepModeInfoNV";
	}
	case LatencySleepInfoNV: {
		return "LatencySleepInfoNV";
	}
	case SetLatencyMarkerInfoNV: {
		return "SetLatencyMarkerInfoNV";
	}
	case GetLatencyMarkerInfoNV: {
		return "GetLatencyMarkerInfoNV";
	}
	case LatencyTimingsFrameReportNV: {
		return "LatencyTimingsFrameReportNV";
	}
	case LatencySubmissionPresentIdNV: {
		return "LatencySubmissionPresentIdNV";
	}
	case OutOfBandQueueTypeInfoNV: {
		return "OutOfBandQueueTypeInfoNV";
	}
	case SwapchainLatencyCreateInfoNV: {
		return "SwapchainLatencyCreateInfoNV";
	}
	case LatencySurfaceCapabilitiesNV: {
		return "LatencySurfaceCapabilitiesNV";
	}
	case PhysicalDeviceCooperativeMatrixFeaturesKHR: {
		return "PhysicalDeviceCooperativeMatrixFeaturesKHR";
	}
	case CooperativeMatrixPropertiesKHR: {
		return "CooperativeMatrixPropertiesKHR";
	}
	case PhysicalDeviceCooperativeMatrixPropertiesKHR: {
		return "PhysicalDeviceCooperativeMatrixPropertiesKHR";
	}
	case DataGraphPipelineCreateInfoARM: {
		return "DataGraphPipelineCreateInfoARM";
	}
	case DataGraphPipelineSessionCreateInfoARM: {
		return "DataGraphPipelineSessionCreateInfoARM";
	}
	case DataGraphPipelineResourceInfoARM: {
		return "DataGraphPipelineResourceInfoARM";
	}
	case DataGraphPipelineConstantARM: {
		return "DataGraphPipelineConstantARM";
	}
	case DataGraphPipelineSessionMemoryRequirementsInfoARM: {
		return "DataGraphPipelineSessionMemoryRequirementsInfoARM";
	}
	case BindDataGraphPipelineSessionMemoryInfoARM: {
		return "BindDataGraphPipelineSessionMemoryInfoARM";
	}
	case PhysicalDeviceDataGraphFeaturesARM: {
		return "PhysicalDeviceDataGraphFeaturesARM";
	}
	case DataGraphPipelineShaderModuleCreateInfoARM: {
		return "DataGraphPipelineShaderModuleCreateInfoARM";
	}
	case DataGraphPipelinePropertyQueryResultARM: {
		return "DataGraphPipelinePropertyQueryResultARM";
	}
	case DataGraphPipelineInfoARM: {
		return "DataGraphPipelineInfoARM";
	}
	case DataGraphPipelineCompilerControlCreateInfoARM: {
		return "DataGraphPipelineCompilerControlCreateInfoARM";
	}
	case DataGraphPipelineSessionBindPointRequirementsInfoARM: {
		return "DataGraphPipelineSessionBindPointRequirementsInfoARM";
	}
	case DataGraphPipelineSessionBindPointRequirementARM: {
		return "DataGraphPipelineSessionBindPointRequirementARM";
	}
	case DataGraphPipelineIdentifierCreateInfoARM: {
		return "DataGraphPipelineIdentifierCreateInfoARM";
	}
	case DataGraphPipelineDispatchInfoARM: {
		return "DataGraphPipelineDispatchInfoARM";
	}
	case DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM: {
		return "DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM";
	}
	case DataGraphProcessingEngineCreateInfoARM: {
		return "DataGraphProcessingEngineCreateInfoARM";
	}
	case QueueFamilyDataGraphProcessingEnginePropertiesARM: {
		return "QueueFamilyDataGraphProcessingEnginePropertiesARM";
	}
	case QueueFamilyDataGraphPropertiesARM: {
		return "QueueFamilyDataGraphPropertiesARM";
	}
	case PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM: {
		return "PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM";
	}
	case QueueFamilyDataGraphTosaPropertiesARM: {
		return "QueueFamilyDataGraphTosaPropertiesARM";
	}
	case PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM: {
		return "PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM";
	}
	case MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM: {
		return "MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM";
	}
	case PhysicalDeviceComputeShaderDerivativesPropertiesKHR: {
		return "PhysicalDeviceComputeShaderDerivativesPropertiesKHR";
	}
	case VideoDecodeAV1CapabilitiesKHR: {
		return "VideoDecodeAV1CapabilitiesKHR";
	}
	case VideoDecodeAV1PictureInfoKHR: {
		return "VideoDecodeAV1PictureInfoKHR";
	}
	case VideoDecodeAV1ProfileInfoKHR: {
		return "VideoDecodeAV1ProfileInfoKHR";
	}
	case VideoDecodeAV1SessionParametersCreateInfoKHR: {
		return "VideoDecodeAV1SessionParametersCreateInfoKHR";
	}
	case VideoDecodeAV1DpbSlotInfoKHR: {
		return "VideoDecodeAV1DpbSlotInfoKHR";
	}
	case VideoEncodeAV1CapabilitiesKHR: {
		return "VideoEncodeAV1CapabilitiesKHR";
	}
	case VideoEncodeAV1SessionParametersCreateInfoKHR: {
		return "VideoEncodeAV1SessionParametersCreateInfoKHR";
	}
	case VideoEncodeAV1PictureInfoKHR: {
		return "VideoEncodeAV1PictureInfoKHR";
	}
	case VideoEncodeAV1DpbSlotInfoKHR: {
		return "VideoEncodeAV1DpbSlotInfoKHR";
	}
	case PhysicalDeviceVideoEncodeAV1FeaturesKHR: {
		return "PhysicalDeviceVideoEncodeAV1FeaturesKHR";
	}
	case VideoEncodeAV1ProfileInfoKHR: {
		return "VideoEncodeAV1ProfileInfoKHR";
	}
	case VideoEncodeAV1RateControlInfoKHR: {
		return "VideoEncodeAV1RateControlInfoKHR";
	}
	case VideoEncodeAV1RateControlLayerInfoKHR: {
		return "VideoEncodeAV1RateControlLayerInfoKHR";
	}
	case VideoEncodeAV1QualityLevelPropertiesKHR: {
		return "VideoEncodeAV1QualityLevelPropertiesKHR";
	}
	case VideoEncodeAV1SessionCreateInfoKHR: {
		return "VideoEncodeAV1SessionCreateInfoKHR";
	}
	case VideoEncodeAV1GopRemainingFrameInfoKHR: {
		return "VideoEncodeAV1GopRemainingFrameInfoKHR";
	}
	case PhysicalDeviceVideoDecodeVp9FeaturesKHR: {
		return "PhysicalDeviceVideoDecodeVp9FeaturesKHR";
	}
	case VideoDecodeVp9CapabilitiesKHR: {
		return "VideoDecodeVp9CapabilitiesKHR";
	}
	case VideoDecodeVp9PictureInfoKHR: {
		return "VideoDecodeVp9PictureInfoKHR";
	}
	case VideoDecodeVp9ProfileInfoKHR: {
		return "VideoDecodeVp9ProfileInfoKHR";
	}
	case PhysicalDeviceVideoMaintenance1FeaturesKHR: {
		return "PhysicalDeviceVideoMaintenance1FeaturesKHR";
	}
	case VideoInlineQueryInfoKHR: {
		return "VideoInlineQueryInfoKHR";
	}
	case PhysicalDevicePerStageDescriptorSetFeaturesNV: {
		return "PhysicalDevicePerStageDescriptorSetFeaturesNV";
	}
	case PhysicalDeviceImageProcessing2FeaturesQCOM: {
		return "PhysicalDeviceImageProcessing2FeaturesQCOM";
	}
	case PhysicalDeviceImageProcessing2PropertiesQCOM: {
		return "PhysicalDeviceImageProcessing2PropertiesQCOM";
	}
	case SamplerBlockMatchWindowCreateInfoQCOM: {
		return "SamplerBlockMatchWindowCreateInfoQCOM";
	}
	case SamplerCubicWeightsCreateInfoQCOM: {
		return "SamplerCubicWeightsCreateInfoQCOM";
	}
	case PhysicalDeviceCubicWeightsFeaturesQCOM: {
		return "PhysicalDeviceCubicWeightsFeaturesQCOM";
	}
	case BlitImageCubicWeightsInfoQCOM: {
		return "BlitImageCubicWeightsInfoQCOM";
	}
	case PhysicalDeviceYcbcrDegammaFeaturesQCOM: {
		return "PhysicalDeviceYcbcrDegammaFeaturesQCOM";
	}
	case SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM: {
		return "SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM";
	}
	case PhysicalDeviceCubicClampFeaturesQCOM: {
		return "PhysicalDeviceCubicClampFeaturesQCOM";
	}
	case PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT: {
		return "PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT";
	}
	case PhysicalDeviceVertexAttributeDivisorProperties: {
		return "PhysicalDeviceVertexAttributeDivisorProperties";
	}
	case PhysicalDeviceUnifiedImageLayoutsFeaturesKHR: {
		return "PhysicalDeviceUnifiedImageLayoutsFeaturesKHR";
	}
	case AttachmentFeedbackLoopInfoEXT: {
		return "AttachmentFeedbackLoopInfoEXT";
	}
	case PhysicalDeviceShaderFloatControls2Features: {
		return "PhysicalDeviceShaderFloatControls2Features";
	}
	case ScreenBufferPropertiesQNX: {
		return "ScreenBufferPropertiesQNX";
	}
	case ScreenBufferFormatPropertiesQNX: {
		return "ScreenBufferFormatPropertiesQNX";
	}
	case ImportScreenBufferInfoQNX: {
		return "ImportScreenBufferInfoQNX";
	}
	case ExternalFormatQNX: {
		return "ExternalFormatQNX";
	}
	case PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX: {
		return "PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX";
	}
	case PhysicalDeviceLayeredDriverPropertiesMSFT: {
		return "PhysicalDeviceLayeredDriverPropertiesMSFT";
	}
	case PhysicalDeviceShaderExpectAssumeFeatures: {
		return "PhysicalDeviceShaderExpectAssumeFeatures";
	}
	case PhysicalDeviceMaintenance6Features: {
		return "PhysicalDeviceMaintenance6Features";
	}
	case PhysicalDeviceMaintenance6Properties: {
		return "PhysicalDeviceMaintenance6Properties";
	}
	case BindMemoryStatus: {
		return "BindMemoryStatus";
	}
	case BindDescriptorSetsInfo: {
		return "BindDescriptorSetsInfo";
	}
	case PushConstantsInfo: {
		return "PushConstantsInfo";
	}
	case PushDescriptorSetInfo: {
		return "PushDescriptorSetInfo";
	}
	case PushDescriptorSetWithTemplateInfo: {
		return "PushDescriptorSetWithTemplateInfo";
	}
	case SetDescriptorBufferOffsetsInfoEXT: {
		return "SetDescriptorBufferOffsetsInfoEXT";
	}
	case BindDescriptorBufferEmbeddedSamplersInfoEXT: {
		return "BindDescriptorBufferEmbeddedSamplersInfoEXT";
	}
	case PhysicalDeviceDescriptorPoolOverallocationFeaturesNV: {
		return "PhysicalDeviceDescriptorPoolOverallocationFeaturesNV";
	}
	case PhysicalDeviceTileMemoryHeapFeaturesQCOM: {
		return "PhysicalDeviceTileMemoryHeapFeaturesQCOM";
	}
	case PhysicalDeviceTileMemoryHeapPropertiesQCOM: {
		return "PhysicalDeviceTileMemoryHeapPropertiesQCOM";
	}
	case TileMemoryRequirementsQCOM: {
		return "TileMemoryRequirementsQCOM";
	}
	case TileMemoryBindInfoQCOM: {
		return "TileMemoryBindInfoQCOM";
	}
	case TileMemorySizeInfoQCOM: {
		return "TileMemorySizeInfoQCOM";
	}
	case PhysicalDeviceCopyMemoryIndirectFeaturesKHR: {
		return "PhysicalDeviceCopyMemoryIndirectFeaturesKHR";
	}
	case CopyMemoryIndirectInfoKHR: {
		return "CopyMemoryIndirectInfoKHR";
	}
	case CopyMemoryToImageIndirectInfoKHR: {
		return "CopyMemoryToImageIndirectInfoKHR";
	}
	case DecompressMemoryInfoEXT: {
		return "DecompressMemoryInfoEXT";
	}
	case DisplaySurfaceStereoCreateInfoNV: {
		return "DisplaySurfaceStereoCreateInfoNV";
	}
	case DisplayModeStereoPropertiesNV: {
		return "DisplayModeStereoPropertiesNV";
	}
	case VideoEncodeIntraRefreshCapabilitiesKHR: {
		return "VideoEncodeIntraRefreshCapabilitiesKHR";
	}
	case VideoEncodeSessionIntraRefreshCreateInfoKHR: {
		return "VideoEncodeSessionIntraRefreshCreateInfoKHR";
	}
	case VideoEncodeIntraRefreshInfoKHR: {
		return "VideoEncodeIntraRefreshInfoKHR";
	}
	case VideoReferenceIntraRefreshInfoKHR: {
		return "VideoReferenceIntraRefreshInfoKHR";
	}
	case PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR: {
		return "PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR";
	}
	case VideoEncodeQuantizationMapCapabilitiesKHR: {
		return "VideoEncodeQuantizationMapCapabilitiesKHR";
	}
	case VideoFormatQuantizationMapPropertiesKHR: {
		return "VideoFormatQuantizationMapPropertiesKHR";
	}
	case VideoEncodeQuantizationMapInfoKHR: {
		return "VideoEncodeQuantizationMapInfoKHR";
	}
	case VideoEncodeH264QuantizationMapCapabilitiesKHR: {
		return "VideoEncodeH264QuantizationMapCapabilitiesKHR";
	}
	case VideoEncodeH265QuantizationMapCapabilitiesKHR: {
		return "VideoEncodeH265QuantizationMapCapabilitiesKHR";
	}
	case VideoEncodeQuantizationMapSessionParametersCreateInfoKHR: {
		return "VideoEncodeQuantizationMapSessionParametersCreateInfoKHR";
	}
	case VideoFormatH265QuantizationMapPropertiesKHR: {
		return "VideoFormatH265QuantizationMapPropertiesKHR";
	}
	case VideoEncodeAV1QuantizationMapCapabilitiesKHR: {
		return "VideoEncodeAV1QuantizationMapCapabilitiesKHR";
	}
	case VideoFormatAV1QuantizationMapPropertiesKHR: {
		return "VideoFormatAV1QuantizationMapPropertiesKHR";
	}
	case PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR: {
		return "PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR";
	}
	case PhysicalDeviceRawAccessChainsFeaturesNV: {
		return "PhysicalDeviceRawAccessChainsFeaturesNV";
	}
	case ExternalComputeQueueDeviceCreateInfoNV: {
		return "ExternalComputeQueueDeviceCreateInfoNV";
	}
	case ExternalComputeQueueCreateInfoNV: {
		return "ExternalComputeQueueCreateInfoNV";
	}
	case ExternalComputeQueueDataParamsNV: {
		return "ExternalComputeQueueDataParamsNV";
	}
	case PhysicalDeviceExternalComputeQueuePropertiesNV: {
		return "PhysicalDeviceExternalComputeQueuePropertiesNV";
	}
	case PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR: {
		return "PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR";
	}
	case PhysicalDeviceCommandBufferInheritanceFeaturesNV: {
		return "PhysicalDeviceCommandBufferInheritanceFeaturesNV";
	}
	case PhysicalDeviceMaintenance7FeaturesKHR: {
		return "PhysicalDeviceMaintenance7FeaturesKHR";
	}
	case PhysicalDeviceMaintenance7PropertiesKHR: {
		return "PhysicalDeviceMaintenance7PropertiesKHR";
	}
	case PhysicalDeviceLayeredApiPropertiesListKHR: {
		return "PhysicalDeviceLayeredApiPropertiesListKHR";
	}
	case PhysicalDeviceLayeredApiPropertiesKHR: {
		return "PhysicalDeviceLayeredApiPropertiesKHR";
	}
	case PhysicalDeviceLayeredApiVulkanPropertiesKHR: {
		return "PhysicalDeviceLayeredApiVulkanPropertiesKHR";
	}
	case PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV: {
		return "PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV";
	}
	case PhysicalDeviceShaderReplicatedCompositesFeaturesEXT: {
		return "PhysicalDeviceShaderReplicatedCompositesFeaturesEXT";
	}
	case TensorExplicitTilingFormatPropertiesARM: {
		return "TensorExplicitTilingFormatPropertiesARM";
	}
	case TensorRollingBackingCreateInfoARM: {
		return "TensorRollingBackingCreateInfoARM";
	}
	case PhysicalDeviceShaderFloat8FeaturesEXT: {
		return "PhysicalDeviceShaderFloat8FeaturesEXT";
	}
	case PhysicalDeviceRayTracingValidationFeaturesNV: {
		return "PhysicalDeviceRayTracingValidationFeaturesNV";
	}
	case PhysicalDeviceClusterAccelerationStructureFeaturesNV: {
		return "PhysicalDeviceClusterAccelerationStructureFeaturesNV";
	}
	case PhysicalDeviceClusterAccelerationStructurePropertiesNV: {
		return "PhysicalDeviceClusterAccelerationStructurePropertiesNV";
	}
	case ClusterAccelerationStructureClustersBottomLevelInputNV: {
		return "ClusterAccelerationStructureClustersBottomLevelInputNV";
	}
	case ClusterAccelerationStructureTriangleClusterInputNV: {
		return "ClusterAccelerationStructureTriangleClusterInputNV";
	}
	case ClusterAccelerationStructureMoveObjectsInputNV: {
		return "ClusterAccelerationStructureMoveObjectsInputNV";
	}
	case ClusterAccelerationStructureInputInfoNV: {
		return "ClusterAccelerationStructureInputInfoNV";
	}
	case ClusterAccelerationStructureCommandsInfoNV: {
		return "ClusterAccelerationStructureCommandsInfoNV";
	}
	case RayTracingPipelineClusterAccelerationStructureCreateInfoNV: {
		return "RayTracingPipelineClusterAccelerationStructureCreateInfoNV";
	}
	case PhysicalDevicePartitionedAccelerationStructureFeaturesNV: {
		return "PhysicalDevicePartitionedAccelerationStructureFeaturesNV";
	}
	case PhysicalDevicePartitionedAccelerationStructurePropertiesNV: {
		return "PhysicalDevicePartitionedAccelerationStructurePropertiesNV";
	}
	case WriteDescriptorSetPartitionedAccelerationStructureNV: {
		return "WriteDescriptorSetPartitionedAccelerationStructureNV";
	}
	case PartitionedAccelerationStructureInstancesInputNV: {
		return "PartitionedAccelerationStructureInstancesInputNV";
	}
	case BuildPartitionedAccelerationStructureInfoNV: {
		return "BuildPartitionedAccelerationStructureInfoNV";
	}
	case PartitionedAccelerationStructureFlagsNV: {
		return "PartitionedAccelerationStructureFlagsNV";
	}
	case PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT: {
		return "PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT";
	}
	case PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT: {
		return "PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT";
	}
	case GeneratedCommandsMemoryRequirementsInfoEXT: {
		return "GeneratedCommandsMemoryRequirementsInfoEXT";
	}
	case IndirectExecutionSetCreateInfoEXT: {
		return "IndirectExecutionSetCreateInfoEXT";
	}
	case GeneratedCommandsInfoEXT: {
		return "GeneratedCommandsInfoEXT";
	}
	case IndirectCommandsLayoutCreateInfoEXT: {
		return "IndirectCommandsLayoutCreateInfoEXT";
	}
	case IndirectCommandsLayoutTokenEXT: {
		return "IndirectCommandsLayoutTokenEXT";
	}
	case WriteIndirectExecutionSetPipelineEXT: {
		return "WriteIndirectExecutionSetPipelineEXT";
	}
	case WriteIndirectExecutionSetShaderEXT: {
		return "WriteIndirectExecutionSetShaderEXT";
	}
	case IndirectExecutionSetPipelineInfoEXT: {
		return "IndirectExecutionSetPipelineInfoEXT";
	}
	case IndirectExecutionSetShaderInfoEXT: {
		return "IndirectExecutionSetShaderInfoEXT";
	}
	case IndirectExecutionSetShaderLayoutInfoEXT: {
		return "IndirectExecutionSetShaderLayoutInfoEXT";
	}
	case GeneratedCommandsPipelineInfoEXT: {
		return "GeneratedCommandsPipelineInfoEXT";
	}
	case GeneratedCommandsShaderInfoEXT: {
		return "GeneratedCommandsShaderInfoEXT";
	}
	case PhysicalDeviceFaultFeaturesKHR: {
		return "PhysicalDeviceFaultFeaturesKHR";
	}
	case PhysicalDeviceFaultPropertiesKHR: {
		return "PhysicalDeviceFaultPropertiesKHR";
	}
	case DeviceFaultInfoKHR: {
		return "DeviceFaultInfoKHR";
	}
	case DeviceFaultDebugInfoKHR: {
		return "DeviceFaultDebugInfoKHR";
	}
	case PhysicalDeviceMaintenance8FeaturesKHR: {
		return "PhysicalDeviceMaintenance8FeaturesKHR";
	}
	case MemoryBarrierAccessFlags3KHR: {
		return "MemoryBarrierAccessFlags3KHR";
	}
	case PhysicalDeviceImageAlignmentControlFeaturesMESA: {
		return "PhysicalDeviceImageAlignmentControlFeaturesMESA";
	}
	case PhysicalDeviceImageAlignmentControlPropertiesMESA: {
		return "PhysicalDeviceImageAlignmentControlPropertiesMESA";
	}
	case ImageAlignmentControlCreateInfoMESA: {
		return "ImageAlignmentControlCreateInfoMESA";
	}
	case PhysicalDeviceShaderFmaFeaturesKHR: {
		return "PhysicalDeviceShaderFmaFeaturesKHR";
	}
	case PushConstantBankInfoNV: {
		return "PushConstantBankInfoNV";
	}
	case PhysicalDevicePushConstantBankFeaturesNV: {
		return "PhysicalDevicePushConstantBankFeaturesNV";
	}
	case PhysicalDevicePushConstantBankPropertiesNV: {
		return "PhysicalDevicePushConstantBankPropertiesNV";
	}
	case PhysicalDeviceRayTracingInvocationReorderFeaturesEXT: {
		return "PhysicalDeviceRayTracingInvocationReorderFeaturesEXT";
	}
	case PhysicalDeviceRayTracingInvocationReorderPropertiesEXT: {
		return "PhysicalDeviceRayTracingInvocationReorderPropertiesEXT";
	}
	case PhysicalDeviceDepthClampControlFeaturesEXT: {
		return "PhysicalDeviceDepthClampControlFeaturesEXT";
	}
	case PipelineViewportDepthClampControlCreateInfoEXT: {
		return "PipelineViewportDepthClampControlCreateInfoEXT";
	}
	case PhysicalDeviceMaintenance9FeaturesKHR: {
		return "PhysicalDeviceMaintenance9FeaturesKHR";
	}
	case PhysicalDeviceMaintenance9PropertiesKHR: {
		return "PhysicalDeviceMaintenance9PropertiesKHR";
	}
	case QueueFamilyOwnershipTransferPropertiesKHR: {
		return "QueueFamilyOwnershipTransferPropertiesKHR";
	}
	case PhysicalDeviceVideoMaintenance2FeaturesKHR: {
		return "PhysicalDeviceVideoMaintenance2FeaturesKHR";
	}
	case VideoDecodeH264InlineSessionParametersInfoKHR: {
		return "VideoDecodeH264InlineSessionParametersInfoKHR";
	}
	case VideoDecodeH265InlineSessionParametersInfoKHR: {
		return "VideoDecodeH265InlineSessionParametersInfoKHR";
	}
	case VideoDecodeAV1InlineSessionParametersInfoKHR: {
		return "VideoDecodeAV1InlineSessionParametersInfoKHR";
	}
	case PhysicalDeviceHdrVividFeaturesHUAWEI: {
		return "PhysicalDeviceHdrVividFeaturesHUAWEI";
	}
	case HdrVividDynamicMetadataHUAWEI: {
		return "HdrVividDynamicMetadataHUAWEI";
	}
	case PhysicalDeviceCooperativeMatrix2FeaturesNV: {
		return "PhysicalDeviceCooperativeMatrix2FeaturesNV";
	}
	case CooperativeMatrixFlexibleDimensionsPropertiesNV: {
		return "CooperativeMatrixFlexibleDimensionsPropertiesNV";
	}
	case PhysicalDeviceCooperativeMatrix2PropertiesNV: {
		return "PhysicalDeviceCooperativeMatrix2PropertiesNV";
	}
	case PhysicalDevicePipelineOpacityMicromapFeaturesARM: {
		return "PhysicalDevicePipelineOpacityMicromapFeaturesARM";
	}
	case PhysicalDeviceVideoEncodeFeedback2FeaturesKHR: {
		return "PhysicalDeviceVideoEncodeFeedback2FeaturesKHR";
	}
	case VideoEncodeFeedback2CapabilitiesKHR: {
		return "VideoEncodeFeedback2CapabilitiesKHR";
	}
	case QueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR: {
		return "QueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR";
	}
	case ImportMemoryMetalHandleInfoEXT: {
		return "ImportMemoryMetalHandleInfoEXT";
	}
	case MemoryMetalHandlePropertiesEXT: {
		return "MemoryMetalHandlePropertiesEXT";
	}
	case MemoryGetMetalHandleInfoEXT: {
		return "MemoryGetMetalHandleInfoEXT";
	}
	case PhysicalDevicePerformanceCountersByRegionFeaturesARM: {
		return "PhysicalDevicePerformanceCountersByRegionFeaturesARM";
	}
	case PhysicalDevicePerformanceCountersByRegionPropertiesARM: {
		return "PhysicalDevicePerformanceCountersByRegionPropertiesARM";
	}
	case PerformanceCounterARM: {
		return "PerformanceCounterARM";
	}
	case PerformanceCounterDescriptionARM: {
		return "PerformanceCounterDescriptionARM";
	}
	case RenderPassPerformanceCountersByRegionBeginInfoARM: {
		return "RenderPassPerformanceCountersByRegionBeginInfoARM";
	}
	case PhysicalDeviceShaderInstrumentationFeaturesARM: {
		return "PhysicalDeviceShaderInstrumentationFeaturesARM";
	}
	case PhysicalDeviceShaderInstrumentationPropertiesARM: {
		return "PhysicalDeviceShaderInstrumentationPropertiesARM";
	}
	case ShaderInstrumentationCreateInfoARM: {
		return "ShaderInstrumentationCreateInfoARM";
	}
	case ShaderInstrumentationMetricDescriptionARM: {
		return "ShaderInstrumentationMetricDescriptionARM";
	}
	case PhysicalDeviceVertexAttributeRobustnessFeaturesEXT: {
		return "PhysicalDeviceVertexAttributeRobustnessFeaturesEXT";
	}
	case PhysicalDeviceFormatPackFeaturesARM: {
		return "PhysicalDeviceFormatPackFeaturesARM";
	}
	case PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE: {
		return "PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE";
	}
	case PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE: {
		return "PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE";
	}
	case PipelineFragmentDensityMapLayeredCreateInfoVALVE: {
		return "PipelineFragmentDensityMapLayeredCreateInfoVALVE";
	}
	case SetPresentConfigNV: {
		return "SetPresentConfigNV";
	}
	case PhysicalDevicePresentMeteringFeaturesNV: {
		return "PhysicalDevicePresentMeteringFeaturesNV";
	}
	case PhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT: {
		return "PhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT";
	}
	case SwapchainFlagsSurfaceCapabilitiesEXT: {
		return "SwapchainFlagsSurfaceCapabilitiesEXT";
	}
	case RenderingEndInfoKHR: {
		return "RenderingEndInfoKHR";
	}
	case PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT: {
		return "PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT";
	}
	case PhysicalDeviceOpacityMicromapFeaturesKHR: {
		return "PhysicalDeviceOpacityMicromapFeaturesKHR";
	}
	case PhysicalDeviceOpacityMicromapPropertiesKHR: {
		return "PhysicalDeviceOpacityMicromapPropertiesKHR";
	}
	case AccelerationStructureGeometryMicromapDataKHR: {
		return "AccelerationStructureGeometryMicromapDataKHR";
	}
	case AccelerationStructureTrianglesOpacityMicromapKHR: {
		return "AccelerationStructureTrianglesOpacityMicromapKHR";
	}
	case PhysicalDeviceShader64BitIndexingFeaturesEXT: {
		return "PhysicalDeviceShader64BitIndexingFeaturesEXT";
	}
	case PhysicalDeviceCustomResolveFeaturesEXT: {
		return "PhysicalDeviceCustomResolveFeaturesEXT";
	}
	case BeginCustomResolveInfoEXT: {
		return "BeginCustomResolveInfoEXT";
	}
	case CustomResolveCreateInfoEXT: {
		return "CustomResolveCreateInfoEXT";
	}
	case PhysicalDeviceDataGraphModelFeaturesQCOM: {
		return "PhysicalDeviceDataGraphModelFeaturesQCOM";
	}
	case DataGraphPipelineBuiltinModelCreateInfoQCOM: {
		return "DataGraphPipelineBuiltinModelCreateInfoQCOM";
	}
	case PhysicalDeviceMaintenance10FeaturesKHR: {
		return "PhysicalDeviceMaintenance10FeaturesKHR";
	}
	case PhysicalDeviceMaintenance10PropertiesKHR: {
		return "PhysicalDeviceMaintenance10PropertiesKHR";
	}
	case RenderingAttachmentFlagsInfoKHR: {
		return "RenderingAttachmentFlagsInfoKHR";
	}
	case ResolveImageModeInfoKHR: {
		return "ResolveImageModeInfoKHR";
	}
	case PhysicalDeviceDataGraphOpticalFlowFeaturesARM: {
		return "PhysicalDeviceDataGraphOpticalFlowFeaturesARM";
	}
	case QueueFamilyDataGraphOpticalFlowPropertiesARM: {
		return "QueueFamilyDataGraphOpticalFlowPropertiesARM";
	}
	case DataGraphPipelineOpticalFlowCreateInfoARM: {
		return "DataGraphPipelineOpticalFlowCreateInfoARM";
	}
	case DataGraphOpticalFlowImageFormatInfoARM: {
		return "DataGraphOpticalFlowImageFormatInfoARM";
	}
	case DataGraphOpticalFlowImageFormatPropertiesARM: {
		return "DataGraphOpticalFlowImageFormatPropertiesARM";
	}
	case DataGraphPipelineOpticalFlowDispatchInfoARM: {
		return "DataGraphPipelineOpticalFlowDispatchInfoARM";
	}
	case DataGraphPipelineResourceInfoImageLayoutARM: {
		return "DataGraphPipelineResourceInfoImageLayoutARM";
	}
	case DataGraphPipelineSingleNodeCreateInfoARM: {
		return "DataGraphPipelineSingleNodeCreateInfoARM";
	}
	case DataGraphPipelineSingleNodeConnectionARM: {
		return "DataGraphPipelineSingleNodeConnectionARM";
	}
	case PhysicalDeviceShaderLongVectorFeaturesEXT: {
		return "PhysicalDeviceShaderLongVectorFeaturesEXT";
	}
	case PhysicalDeviceShaderLongVectorPropertiesEXT: {
		return "PhysicalDeviceShaderLongVectorPropertiesEXT";
	}
	case PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC: {
		return "PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC";
	}
	case PhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT: {
		return "PhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT";
	}
	case ComputeOccupancyPriorityParametersNV: {
		return "ComputeOccupancyPriorityParametersNV";
	}
	case PhysicalDeviceComputeOccupancyPriorityFeaturesNV: {
		return "PhysicalDeviceComputeOccupancyPriorityFeaturesNV";
	}
	case PhysicalDeviceMaintenance11FeaturesKHR: {
		return "PhysicalDeviceMaintenance11FeaturesKHR";
	}
	case QueueFamilyOptimalImageTransferGranularityPropertiesKHR: {
		return "QueueFamilyOptimalImageTransferGranularityPropertiesKHR";
	}
	case PhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT: {
		return "PhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT";
	}
	case PhysicalDeviceCooperativeMatrixInfo2EXT: {
		return "PhysicalDeviceCooperativeMatrixInfo2EXT";
	}
	case CooperativeMatrixProperties2EXT: {
		return "CooperativeMatrixProperties2EXT";
	}
	case PhysicalDeviceShaderSubgroupPartitionedFeaturesEXT: {
		return "PhysicalDeviceShaderSubgroupPartitionedFeaturesEXT";
	}
	case UbmSurfaceCreateInfoSEC: {
		return "UbmSurfaceCreateInfoSEC";
	}
	case FormatProperties4KHR: {
		return "FormatProperties4KHR";
	}
	case ImageCreateFlags2CreateInfoKHR: {
		return "ImageCreateFlags2CreateInfoKHR";
	}
	case ImageUsageFlags2CreateInfoKHR: {
		return "ImageUsageFlags2CreateInfoKHR";
	}
	case ImageViewUsage2CreateInfoKHR: {
		return "ImageViewUsage2CreateInfoKHR";
	}
	case PhysicalDeviceExtendedFlagsFeaturesKHR: {
		return "PhysicalDeviceExtendedFlagsFeaturesKHR";
	}
	case ImageStencilUsage2CreateInfoKHR: {
		return "ImageStencilUsage2CreateInfoKHR";
	}
	case SharedPresentSurfaceCapabilities2KHR: {
		return "SharedPresentSurfaceCapabilities2KHR";
	}
	case PhysicalDeviceShaderOcpMicroscalingTypesFeaturesEXT: {
		return "PhysicalDeviceShaderOcpMicroscalingTypesFeaturesEXT";
	}
	case PhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE: {
		return "PhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE";
	}
	case PhysicalDeviceThrottleHintFeaturesSEC: {
		return "PhysicalDeviceThrottleHintFeaturesSEC";
	}
	case ThrottleHintSubmitInfoSEC: {
		return "ThrottleHintSubmitInfoSEC";
	}
	case DataGraphPipelineNeuralStatisticsCreateInfoARM: {
		return "DataGraphPipelineNeuralStatisticsCreateInfoARM";
	}
	case DataGraphPipelineSessionNeuralStatisticsCreateInfoARM: {
		return "DataGraphPipelineSessionNeuralStatisticsCreateInfoARM";
	}
	case PhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM: {
		return "PhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM";
	}
	case PhysicalDevicePrimitiveRestartIndexFeaturesEXT: {
		return "PhysicalDevicePrimitiveRestartIndexFeaturesEXT";
	}
	case SurfaceCreateInfoOHOS: {
		return "SurfaceCreateInfoOHOS";
	}
	case PhysicalDeviceImageTilingControlFeaturesEXT: {
		return "PhysicalDeviceImageTilingControlFeaturesEXT";
	}
	case ImageTilingControlCreateInfoEXT: {
		return "ImageTilingControlCreateInfoEXT";
	}
	case PhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV: {
		return "PhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV";
	}
	}
	return "EnumElement not part of: StructureType";
}
template<> auto enumToString(SubpassContents enumVal) -> std::string {
	using enum SubpassContents;
	switch (enumVal) {
	case Inline: {
		return "Inline";
	}
	case SecondaryCommandBuffers: {
		return "SecondaryCommandBuffers";
	}
	case InlineAndSecondaryCommandBuffersKHR: {
		return "InlineAndSecondaryCommandBuffersKHR";
	}
	}
	return "EnumElement not part of: SubpassContents";
}
template<> auto enumToString(SubpassMergeStatusEXT enumVal) -> std::string {
	using enum SubpassMergeStatusEXT;
	switch (enumVal) {
	case Merged: {
		return "Merged";
	}
	case Disallowed: {
		return "Disallowed";
	}
	case NotMergedSideEffects: {
		return "NotMergedSideEffects";
	}
	case NotMergedSamplesMismatch: {
		return "NotMergedSamplesMismatch";
	}
	case NotMergedViewsMismatch: {
		return "NotMergedViewsMismatch";
	}
	case NotMergedAliasing: {
		return "NotMergedAliasing";
	}
	case NotMergedDependencies: {
		return "NotMergedDependencies";
	}
	case NotMergedIncompatibleInputAttachment: {
		return "NotMergedIncompatibleInputAttachment";
	}
	case NotMergedTooManyAttachments: {
		return "NotMergedTooManyAttachments";
	}
	case NotMergedInsufficientStorage: {
		return "NotMergedInsufficientStorage";
	}
	case NotMergedDepthStencilCount: {
		return "NotMergedDepthStencilCount";
	}
	case NotMergedResolveAttachmentReuse: {
		return "NotMergedResolveAttachmentReuse";
	}
	case NotMergedSingleSubpass: {
		return "NotMergedSingleSubpass";
	}
	case NotMergedUnspecified: {
		return "NotMergedUnspecified";
	}
	}
	return "EnumElement not part of: SubpassMergeStatusEXT";
}
template<> auto enumToString(SystemAllocationScope enumVal) -> std::string {
	using enum SystemAllocationScope;
	switch (enumVal) {
	case Command: {
		return "Command";
	}
	case Object: {
		return "Object";
	}
	case Cache: {
		return "Cache";
	}
	case Device: {
		return "Device";
	}
	case Instance: {
		return "Instance";
	}
	}
	return "EnumElement not part of: SystemAllocationScope";
}
template<> auto enumToString(TensorTilingARM enumVal) -> std::string {
	using enum TensorTilingARM;
	switch (enumVal) {
	case Optimal: {
		return "Optimal";
	}
	case Linear: {
		return "Linear";
	}
	case Brick16Wide: {
		return "Brick16Wide";
	}
	case Brick8Wide: {
		return "Brick8Wide";
	}
	case Brick4Wide: {
		return "Brick4Wide";
	}
	case BlockUInterleaved: {
		return "BlockUInterleaved";
	}
	case BlockUInterleaved64K: {
		return "BlockUInterleaved64K";
	}
	}
	return "EnumElement not part of: TensorTilingARM";
}
template<> auto enumToString(TessellationDomainOrigin enumVal) -> std::string {
	using enum TessellationDomainOrigin;
	switch (enumVal) {
	case UpperLeft: {
		return "UpperLeft";
	}
	case LowerLeft: {
		return "LowerLeft";
	}
	}
	return "EnumElement not part of: TessellationDomainOrigin";
}
template<> auto enumToString(ThrottleHintTypeSEC enumVal) -> std::string {
	using enum ThrottleHintTypeSEC;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case Low: {
		return "Low";
	}
	case High: {
		return "High";
	}
	}
	return "EnumElement not part of: ThrottleHintTypeSEC";
}
template<> auto enumToString(TimeDomainKHR enumVal) -> std::string {
	using enum TimeDomainKHR;
	switch (enumVal) {
	case Device: {
		return "Device";
	}
	case ClockMonotonic: {
		return "ClockMonotonic";
	}
	case ClockMonotonicRaw: {
		return "ClockMonotonicRaw";
	}
	case QueryPerformanceCounter: {
		return "QueryPerformanceCounter";
	}
	case PresentStageLocalEXT: {
		return "PresentStageLocalEXT";
	}
	case SwapchainLocalEXT: {
		return "SwapchainLocalEXT";
	}
	}
	return "EnumElement not part of: TimeDomainKHR";
}
template<> auto enumToString(ValidationCacheHeaderVersionEXT enumVal) -> std::string {
	using enum ValidationCacheHeaderVersionEXT;
	switch (enumVal) {
	case One: {
		return "One";
	}
	}
	return "EnumElement not part of: ValidationCacheHeaderVersionEXT";
}
template<> auto enumToString(ValidationCheckEXT enumVal) -> std::string {
	using enum ValidationCheckEXT;
	switch (enumVal) {
	case All: {
		return "All";
	}
	case Shaders: {
		return "Shaders";
	}
	}
	return "EnumElement not part of: ValidationCheckEXT";
}
template<> auto enumToString(ValidationFeatureDisableEXT enumVal) -> std::string {
	using enum ValidationFeatureDisableEXT;
	switch (enumVal) {
	case All: {
		return "All";
	}
	case Shaders: {
		return "Shaders";
	}
	case ThreadSafety: {
		return "ThreadSafety";
	}
	case ApiParameters: {
		return "ApiParameters";
	}
	case ObjectLifetimes: {
		return "ObjectLifetimes";
	}
	case CoreChecks: {
		return "CoreChecks";
	}
	case UniqueHandles: {
		return "UniqueHandles";
	}
	case ShaderValidationCache: {
		return "ShaderValidationCache";
	}
	}
	return "EnumElement not part of: ValidationFeatureDisableEXT";
}
template<> auto enumToString(ValidationFeatureEnableEXT enumVal) -> std::string {
	using enum ValidationFeatureEnableEXT;
	switch (enumVal) {
	case GpuAssisted: {
		return "GpuAssisted";
	}
	case GpuAssistedReserveBindingSlot: {
		return "GpuAssistedReserveBindingSlot";
	}
	case BestPractices: {
		return "BestPractices";
	}
	case DebugPrintf: {
		return "DebugPrintf";
	}
	case SynchronizationValidation: {
		return "SynchronizationValidation";
	}
	}
	return "EnumElement not part of: ValidationFeatureEnableEXT";
}
template<> auto enumToString(VendorId enumVal) -> std::string {
	using enum VendorId;
	switch (enumVal) {
	case Khronos: {
		return "Khronos";
	}
	case VIV: {
		return "VIV";
	}
	case VSI: {
		return "VSI";
	}
	case Kazan: {
		return "Kazan";
	}
	case Codeplay: {
		return "Codeplay";
	}
	case MESA: {
		return "MESA";
	}
	case Pocl: {
		return "Pocl";
	}
	case Mobileye: {
		return "Mobileye";
	}
	case Ape: {
		return "Ape";
	}
	}
	return "EnumElement not part of: VendorId";
}
template<> auto enumToString(VertexInputRate enumVal) -> std::string {
	using enum VertexInputRate;
	switch (enumVal) {
	case Vertex: {
		return "Vertex";
	}
	case Instance: {
		return "Instance";
	}
	}
	return "EnumElement not part of: VertexInputRate";
}
template<> auto enumToString(VideoEncodeAV1PredictionModeKHR enumVal) -> std::string {
	using enum VideoEncodeAV1PredictionModeKHR;
	switch (enumVal) {
	case IntraOnly: {
		return "IntraOnly";
	}
	case SingleReference: {
		return "SingleReference";
	}
	case UnidirectionalCompound: {
		return "UnidirectionalCompound";
	}
	case BidirectionalCompound: {
		return "BidirectionalCompound";
	}
	}
	return "EnumElement not part of: VideoEncodeAV1PredictionModeKHR";
}
template<> auto enumToString(VideoEncodeAV1RateControlGroupKHR enumVal) -> std::string {
	using enum VideoEncodeAV1RateControlGroupKHR;
	switch (enumVal) {
	case Intra: {
		return "Intra";
	}
	case Predictive: {
		return "Predictive";
	}
	case Bipredictive: {
		return "Bipredictive";
	}
	}
	return "EnumElement not part of: VideoEncodeAV1RateControlGroupKHR";
}
template<> auto enumToString(VideoEncodeTuningModeKHR enumVal) -> std::string {
	using enum VideoEncodeTuningModeKHR;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case HighQuality: {
		return "HighQuality";
	}
	case LowLatency: {
		return "LowLatency";
	}
	case UltraLowLatency: {
		return "UltraLowLatency";
	}
	case Lossless: {
		return "Lossless";
	}
	}
	return "EnumElement not part of: VideoEncodeTuningModeKHR";
}
template<> auto enumToString(ViewportCoordinateSwizzleNV enumVal) -> std::string {
	using enum ViewportCoordinateSwizzleNV;
	switch (enumVal) {
	case Positivex: {
		return "Positivex";
	}
	case Negativex: {
		return "Negativex";
	}
	case PositiveY: {
		return "PositiveY";
	}
	case NegativeY: {
		return "NegativeY";
	}
	case PositiveZ: {
		return "PositiveZ";
	}
	case NegativeZ: {
		return "NegativeZ";
	}
	case PositiveW: {
		return "PositiveW";
	}
	case NegativeW: {
		return "NegativeW";
	}
	}
	return "EnumElement not part of: ViewportCoordinateSwizzleNV";
}
template<> auto enumToString(StdVideoAV1ChromaSamplePosition enumVal) -> std::string {
	using enum StdVideoAV1ChromaSamplePosition;
	switch (enumVal) {
	case Unknown: {
		return "Unknown";
	}
	case Vertical: {
		return "Vertical";
	}
	case Colocated: {
		return "Colocated";
	}
	case Reserved: {
		return "Reserved";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1ChromaSamplePosition";
}
template<> auto enumToString(StdVideoAV1ColorPrimaries enumVal) -> std::string {
	using enum StdVideoAV1ColorPrimaries;
	switch (enumVal) {
	case Bt709: {
		return "Bt709";
	}
	case Unspecified: {
		return "Unspecified";
	}
	case Bt470M: {
		return "Bt470M";
	}
	case Bt470BG: {
		return "Bt470BG";
	}
	case Bt601: {
		return "Bt601";
	}
	case Smpte240: {
		return "Smpte240";
	}
	case GenericFilm: {
		return "GenericFilm";
	}
	case Bt2020: {
		return "Bt2020";
	}
	case Xyz: {
		return "Xyz";
	}
	case Smpte431: {
		return "Smpte431";
	}
	case Smpte432: {
		return "Smpte432";
	}
	case Ebu3213: {
		return "Ebu3213";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1ColorPrimaries";
}
template<> auto enumToString(StdVideoAV1FrameRestorationType enumVal) -> std::string {
	using enum StdVideoAV1FrameRestorationType;
	switch (enumVal) {
	case None: {
		return "None";
	}
	case Wiener: {
		return "Wiener";
	}
	case Sgrproj: {
		return "Sgrproj";
	}
	case Switchable: {
		return "Switchable";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1FrameRestorationType";
}
template<> auto enumToString(StdVideoAV1FrameType enumVal) -> std::string {
	using enum StdVideoAV1FrameType;
	switch (enumVal) {
	case Key: {
		return "Key";
	}
	case Inter: {
		return "Inter";
	}
	case IntraOnly: {
		return "IntraOnly";
	}
	case Switch: {
		return "Switch";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1FrameType";
}
template<> auto enumToString(StdVideoAV1InterpolationFilter enumVal) -> std::string {
	using enum StdVideoAV1InterpolationFilter;
	switch (enumVal) {
	case Eighttap: {
		return "Eighttap";
	}
	case EighttapSmooth: {
		return "EighttapSmooth";
	}
	case EighttapSharp: {
		return "EighttapSharp";
	}
	case Bilinear: {
		return "Bilinear";
	}
	case Switchable: {
		return "Switchable";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1InterpolationFilter";
}
template<> auto enumToString(StdVideoAV1Level enumVal) -> std::string {
	using enum StdVideoAV1Level;
	switch (enumVal) {
	case v20: {
		return "v20";
	}
	case v21: {
		return "v21";
	}
	case v22: {
		return "v22";
	}
	case v23: {
		return "v23";
	}
	case v30: {
		return "v30";
	}
	case v31: {
		return "v31";
	}
	case v32: {
		return "v32";
	}
	case v33: {
		return "v33";
	}
	case v40: {
		return "v40";
	}
	case v41: {
		return "v41";
	}
	case v42: {
		return "v42";
	}
	case v43: {
		return "v43";
	}
	case v50: {
		return "v50";
	}
	case v51: {
		return "v51";
	}
	case v52: {
		return "v52";
	}
	case v53: {
		return "v53";
	}
	case v60: {
		return "v60";
	}
	case v61: {
		return "v61";
	}
	case v62: {
		return "v62";
	}
	case v63: {
		return "v63";
	}
	case v70: {
		return "v70";
	}
	case v71: {
		return "v71";
	}
	case v72: {
		return "v72";
	}
	case v73: {
		return "v73";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1Level";
}
template<> auto enumToString(StdVideoAV1MatrixCoefficients enumVal) -> std::string {
	using enum StdVideoAV1MatrixCoefficients;
	switch (enumVal) {
	case Identity: {
		return "Identity";
	}
	case Bt709: {
		return "Bt709";
	}
	case Unspecified: {
		return "Unspecified";
	}
	case Reserved3: {
		return "Reserved3";
	}
	case Fcc: {
		return "Fcc";
	}
	case Bt470BG: {
		return "Bt470BG";
	}
	case Bt601: {
		return "Bt601";
	}
	case Smpte240: {
		return "Smpte240";
	}
	case SmpteYcgco: {
		return "SmpteYcgco";
	}
	case Bt2020Ncl: {
		return "Bt2020Ncl";
	}
	case Bt2020Cl: {
		return "Bt2020Cl";
	}
	case Smpte2085: {
		return "Smpte2085";
	}
	case ChromatNcl: {
		return "ChromatNcl";
	}
	case ChromatCl: {
		return "ChromatCl";
	}
	case Ictcp: {
		return "Ictcp";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1MatrixCoefficients";
}
template<> auto enumToString(StdVideoAV1Profile enumVal) -> std::string {
	using enum StdVideoAV1Profile;
	switch (enumVal) {
	case Main: {
		return "Main";
	}
	case High: {
		return "High";
	}
	case Professional: {
		return "Professional";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1Profile";
}
template<> auto enumToString(StdVideoAV1ReferenceName enumVal) -> std::string {
	using enum StdVideoAV1ReferenceName;
	switch (enumVal) {
	case IntraFrame: {
		return "IntraFrame";
	}
	case LastFrame: {
		return "LastFrame";
	}
	case Last2Frame: {
		return "Last2Frame";
	}
	case Last3Frame: {
		return "Last3Frame";
	}
	case GoldenFrame: {
		return "GoldenFrame";
	}
	case BwdrefFrame: {
		return "BwdrefFrame";
	}
	case Altref2Frame: {
		return "Altref2Frame";
	}
	case AltrefFrame: {
		return "AltrefFrame";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1ReferenceName";
}
template<> auto enumToString(StdVideoAV1TransferCharacteristics enumVal) -> std::string {
	using enum StdVideoAV1TransferCharacteristics;
	switch (enumVal) {
	case Reserved0: {
		return "Reserved0";
	}
	case Bt709: {
		return "Bt709";
	}
	case Unspecified: {
		return "Unspecified";
	}
	case Reserved3: {
		return "Reserved3";
	}
	case Bt470M: {
		return "Bt470M";
	}
	case Bt470BG: {
		return "Bt470BG";
	}
	case Bt601: {
		return "Bt601";
	}
	case Smpte240: {
		return "Smpte240";
	}
	case Linear: {
		return "Linear";
	}
	case Log100: {
		return "Log100";
	}
	case Log100Sqrt10: {
		return "Log100Sqrt10";
	}
	case Iec61966: {
		return "Iec61966";
	}
	case Bt1361: {
		return "Bt1361";
	}
	case Srgb: {
		return "Srgb";
	}
	case Bt202010Bit: {
		return "Bt202010Bit";
	}
	case Bt202012Bit: {
		return "Bt202012Bit";
	}
	case Smpte2084: {
		return "Smpte2084";
	}
	case Smpte428: {
		return "Smpte428";
	}
	case Hlg: {
		return "Hlg";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1TransferCharacteristics";
}
template<> auto enumToString(StdVideoAV1TxMode enumVal) -> std::string {
	using enum StdVideoAV1TxMode;
	switch (enumVal) {
	case Only4x4: {
		return "Only4x4";
	}
	case Largest: {
		return "Largest";
	}
	case Select: {
		return "Select";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoAV1TxMode";
}
template<> auto enumToString(StdVideoDecodeH264FieldOrderCount enumVal) -> std::string {
	using enum StdVideoDecodeH264FieldOrderCount;
	switch (enumVal) {
	case Top: {
		return "Top";
	}
	case Bottom: {
		return "Bottom";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoDecodeH264FieldOrderCount";
}
template<> auto enumToString(StdVideoH264AspectRatioIdc enumVal) -> std::string {
	using enum StdVideoH264AspectRatioIdc;
	switch (enumVal) {
	case Unspecified: {
		return "Unspecified";
	}
	case Square: {
		return "Square";
	}
	case v1211: {
		return "v1211";
	}
	case v1011: {
		return "v1011";
	}
	case v1611: {
		return "v1611";
	}
	case v4033: {
		return "v4033";
	}
	case v2411: {
		return "v2411";
	}
	case v2011: {
		return "v2011";
	}
	case v3211: {
		return "v3211";
	}
	case v8033: {
		return "v8033";
	}
	case v1811: {
		return "v1811";
	}
	case v1511: {
		return "v1511";
	}
	case v6433: {
		return "v6433";
	}
	case v16099: {
		return "v16099";
	}
	case v43: {
		return "v43";
	}
	case v32: {
		return "v32";
	}
	case v21: {
		return "v21";
	}
	case ExtendedSar: {
		return "ExtendedSar";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264AspectRatioIdc";
}
template<> auto enumToString(StdVideoH264CabacInitIdc enumVal) -> std::string {
	using enum StdVideoH264CabacInitIdc;
	switch (enumVal) {
	case v0: {
		return "v0";
	}
	case v1: {
		return "v1";
	}
	case v2: {
		return "v2";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264CabacInitIdc";
}
template<> auto enumToString(StdVideoH264ChromaFormatIdc enumVal) -> std::string {
	using enum StdVideoH264ChromaFormatIdc;
	switch (enumVal) {
	case Monochrome: {
		return "Monochrome";
	}
	case v420: {
		return "v420";
	}
	case v422: {
		return "v422";
	}
	case v444: {
		return "v444";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264ChromaFormatIdc";
}
template<> auto enumToString(StdVideoH264DisableDeblockingFilterIdc enumVal) -> std::string {
	using enum StdVideoH264DisableDeblockingFilterIdc;
	switch (enumVal) {
	case Disabled: {
		return "Disabled";
	}
	case Enabled: {
		return "Enabled";
	}
	case Partial: {
		return "Partial";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264DisableDeblockingFilterIdc";
}
template<> auto enumToString(StdVideoH264LevelIdc enumVal) -> std::string {
	using enum StdVideoH264LevelIdc;
	switch (enumVal) {
	case v10: {
		return "v10";
	}
	case v11: {
		return "v11";
	}
	case v12: {
		return "v12";
	}
	case v13: {
		return "v13";
	}
	case v20: {
		return "v20";
	}
	case v21: {
		return "v21";
	}
	case v22: {
		return "v22";
	}
	case v30: {
		return "v30";
	}
	case v31: {
		return "v31";
	}
	case v32: {
		return "v32";
	}
	case v40: {
		return "v40";
	}
	case v41: {
		return "v41";
	}
	case v42: {
		return "v42";
	}
	case v50: {
		return "v50";
	}
	case v51: {
		return "v51";
	}
	case v52: {
		return "v52";
	}
	case v60: {
		return "v60";
	}
	case v61: {
		return "v61";
	}
	case v62: {
		return "v62";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264LevelIdc";
}
template<> auto enumToString(StdVideoH264MemMgmtControlOp enumVal) -> std::string {
	using enum StdVideoH264MemMgmtControlOp;
	switch (enumVal) {
	case End: {
		return "End";
	}
	case UnmarkShortTerm: {
		return "UnmarkShortTerm";
	}
	case UnmarkLongTerm: {
		return "UnmarkLongTerm";
	}
	case MarkLongTerm: {
		return "MarkLongTerm";
	}
	case SetMaxLongTermIndex: {
		return "SetMaxLongTermIndex";
	}
	case UnmarkAll: {
		return "UnmarkAll";
	}
	case MarkCurrentAsLongTerm: {
		return "MarkCurrentAsLongTerm";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264MemMgmtControlOp";
}
template<> auto enumToString(StdVideoH264ModificationOfPicNumsIdc enumVal) -> std::string {
	using enum StdVideoH264ModificationOfPicNumsIdc;
	switch (enumVal) {
	case ShortTermSubtract: {
		return "ShortTermSubtract";
	}
	case ShortTermAdd: {
		return "ShortTermAdd";
	}
	case LongTerm: {
		return "LongTerm";
	}
	case End: {
		return "End";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264ModificationOfPicNumsIdc";
}
template<> auto enumToString(StdVideoH264NonVclNaluType enumVal) -> std::string {
	using enum StdVideoH264NonVclNaluType;
	switch (enumVal) {
	case Sps: {
		return "Sps";
	}
	case Pps: {
		return "Pps";
	}
	case Aud: {
		return "Aud";
	}
	case Prefix: {
		return "Prefix";
	}
	case EndOfSequence: {
		return "EndOfSequence";
	}
	case EndOfStream: {
		return "EndOfStream";
	}
	case Precoded: {
		return "Precoded";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264NonVclNaluType";
}
template<> auto enumToString(StdVideoH264PictureType enumVal) -> std::string {
	using enum StdVideoH264PictureType;
	switch (enumVal) {
	case P: {
		return "P";
	}
	case B: {
		return "B";
	}
	case I: {
		return "I";
	}
	case Idr: {
		return "Idr";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264PictureType";
}
template<> auto enumToString(StdVideoH264PocType enumVal) -> std::string {
	using enum StdVideoH264PocType;
	switch (enumVal) {
	case v0: {
		return "v0";
	}
	case v1: {
		return "v1";
	}
	case v2: {
		return "v2";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264PocType";
}
template<> auto enumToString(StdVideoH264ProfileIdc enumVal) -> std::string {
	using enum StdVideoH264ProfileIdc;
	switch (enumVal) {
	case Baseline: {
		return "Baseline";
	}
	case Main: {
		return "Main";
	}
	case High: {
		return "High";
	}
	case High10: {
		return "High10";
	}
	case High422: {
		return "High422";
	}
	case High444Predictive: {
		return "High444Predictive";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264ProfileIdc";
}
template<> auto enumToString(StdVideoH264SliceType enumVal) -> std::string {
	using enum StdVideoH264SliceType;
	switch (enumVal) {
	case P: {
		return "P";
	}
	case B: {
		return "B";
	}
	case I: {
		return "I";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264SliceType";
}
template<> auto enumToString(StdVideoH264WeightedBipredIdc enumVal) -> std::string {
	using enum StdVideoH264WeightedBipredIdc;
	switch (enumVal) {
	case Default: {
		return "Default";
	}
	case Explicit: {
		return "Explicit";
	}
	case Implicit: {
		return "Implicit";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH264WeightedBipredIdc";
}
template<> auto enumToString(StdVideoH265AspectRatioIdc enumVal) -> std::string {
	using enum StdVideoH265AspectRatioIdc;
	switch (enumVal) {
	case Unspecified: {
		return "Unspecified";
	}
	case Square: {
		return "Square";
	}
	case v1211: {
		return "v1211";
	}
	case v1011: {
		return "v1011";
	}
	case v1611: {
		return "v1611";
	}
	case v4033: {
		return "v4033";
	}
	case v2411: {
		return "v2411";
	}
	case v2011: {
		return "v2011";
	}
	case v3211: {
		return "v3211";
	}
	case v8033: {
		return "v8033";
	}
	case v1811: {
		return "v1811";
	}
	case v1511: {
		return "v1511";
	}
	case v6433: {
		return "v6433";
	}
	case v16099: {
		return "v16099";
	}
	case v43: {
		return "v43";
	}
	case v32: {
		return "v32";
	}
	case v21: {
		return "v21";
	}
	case ExtendedSar: {
		return "ExtendedSar";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH265AspectRatioIdc";
}
template<> auto enumToString(StdVideoH265ChromaFormatIdc enumVal) -> std::string {
	using enum StdVideoH265ChromaFormatIdc;
	switch (enumVal) {
	case Monochrome: {
		return "Monochrome";
	}
	case v420: {
		return "v420";
	}
	case v422: {
		return "v422";
	}
	case v444: {
		return "v444";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH265ChromaFormatIdc";
}
template<> auto enumToString(StdVideoH265LevelIdc enumVal) -> std::string {
	using enum StdVideoH265LevelIdc;
	switch (enumVal) {
	case v10: {
		return "v10";
	}
	case v20: {
		return "v20";
	}
	case v21: {
		return "v21";
	}
	case v30: {
		return "v30";
	}
	case v31: {
		return "v31";
	}
	case v40: {
		return "v40";
	}
	case v41: {
		return "v41";
	}
	case v50: {
		return "v50";
	}
	case v51: {
		return "v51";
	}
	case v52: {
		return "v52";
	}
	case v60: {
		return "v60";
	}
	case v61: {
		return "v61";
	}
	case v62: {
		return "v62";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH265LevelIdc";
}
template<> auto enumToString(StdVideoH265PictureType enumVal) -> std::string {
	using enum StdVideoH265PictureType;
	switch (enumVal) {
	case P: {
		return "P";
	}
	case B: {
		return "B";
	}
	case I: {
		return "I";
	}
	case Idr: {
		return "Idr";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH265PictureType";
}
template<> auto enumToString(StdVideoH265ProfileIdc enumVal) -> std::string {
	using enum StdVideoH265ProfileIdc;
	switch (enumVal) {
	case Main: {
		return "Main";
	}
	case Main10: {
		return "Main10";
	}
	case MainStillPicture: {
		return "MainStillPicture";
	}
	case FormatRangeExtensions: {
		return "FormatRangeExtensions";
	}
	case SccExtensions: {
		return "SccExtensions";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH265ProfileIdc";
}
template<> auto enumToString(StdVideoH265SliceType enumVal) -> std::string {
	using enum StdVideoH265SliceType;
	switch (enumVal) {
	case B: {
		return "B";
	}
	case P: {
		return "P";
	}
	case I: {
		return "I";
	}
	case Invalid: {
		return "Invalid";
	}
	}
	return "EnumElement not part of: StdVideoH265SliceType";
}
template<> auto enumToString(StdVideoVP9ColorSpace enumVal) -> std::string {
	using enum StdVideoVP9ColorSpace;
	switch (enumVal) {
	case StdVideoVp9ColorSpaceUnknown: {
		return "StdVideoVp9ColorSpaceUnknown";
	}
	case StdVideoVp9ColorSpaceBt601: {
		return "StdVideoVp9ColorSpaceBt601";
	}
	case StdVideoVp9ColorSpaceBt709: {
		return "StdVideoVp9ColorSpaceBt709";
	}
	case StdVideoVp9ColorSpaceSmpte170: {
		return "StdVideoVp9ColorSpaceSmpte170";
	}
	case StdVideoVp9ColorSpaceSmpte240: {
		return "StdVideoVp9ColorSpaceSmpte240";
	}
	case StdVideoVp9ColorSpaceBt2020: {
		return "StdVideoVp9ColorSpaceBt2020";
	}
	case StdVideoVp9ColorSpaceReserved: {
		return "StdVideoVp9ColorSpaceReserved";
	}
	case StdVideoVp9ColorSpaceRgb: {
		return "StdVideoVp9ColorSpaceRgb";
	}
	case StdVideoVp9ColorSpaceInvalid: {
		return "StdVideoVp9ColorSpaceInvalid";
	}
	}
	return "EnumElement not part of: StdVideoVP9ColorSpace";
}
template<> auto enumToString(StdVideoVP9FrameType enumVal) -> std::string {
	using enum StdVideoVP9FrameType;
	switch (enumVal) {
	case StdVideoVp9FrameTypeKey: {
		return "StdVideoVp9FrameTypeKey";
	}
	case StdVideoVp9FrameTypeNonKey: {
		return "StdVideoVp9FrameTypeNonKey";
	}
	case StdVideoVp9FrameTypeInvalid: {
		return "StdVideoVp9FrameTypeInvalid";
	}
	}
	return "EnumElement not part of: StdVideoVP9FrameType";
}
template<> auto enumToString(StdVideoVP9InterpolationFilter enumVal) -> std::string {
	using enum StdVideoVP9InterpolationFilter;
	switch (enumVal) {
	case StdVideoVp9InterpolationFilterEighttap: {
		return "StdVideoVp9InterpolationFilterEighttap";
	}
	case StdVideoVp9InterpolationFilterEighttapSmooth: {
		return "StdVideoVp9InterpolationFilterEighttapSmooth";
	}
	case StdVideoVp9InterpolationFilterEighttapSharp: {
		return "StdVideoVp9InterpolationFilterEighttapSharp";
	}
	case StdVideoVp9InterpolationFilterBilinear: {
		return "StdVideoVp9InterpolationFilterBilinear";
	}
	case StdVideoVp9InterpolationFilterSwitchable: {
		return "StdVideoVp9InterpolationFilterSwitchable";
	}
	case StdVideoVp9InterpolationFilterInvalid: {
		return "StdVideoVp9InterpolationFilterInvalid";
	}
	}
	return "EnumElement not part of: StdVideoVP9InterpolationFilter";
}
template<> auto enumToString(StdVideoVP9Level enumVal) -> std::string {
	using enum StdVideoVP9Level;
	switch (enumVal) {
	case StdVideoVp9Level10: {
		return "StdVideoVp9Level10";
	}
	case StdVideoVp9Level11: {
		return "StdVideoVp9Level11";
	}
	case StdVideoVp9Level20: {
		return "StdVideoVp9Level20";
	}
	case StdVideoVp9Level21: {
		return "StdVideoVp9Level21";
	}
	case StdVideoVp9Level30: {
		return "StdVideoVp9Level30";
	}
	case StdVideoVp9Level31: {
		return "StdVideoVp9Level31";
	}
	case StdVideoVp9Level40: {
		return "StdVideoVp9Level40";
	}
	case StdVideoVp9Level41: {
		return "StdVideoVp9Level41";
	}
	case StdVideoVp9Level50: {
		return "StdVideoVp9Level50";
	}
	case StdVideoVp9Level51: {
		return "StdVideoVp9Level51";
	}
	case StdVideoVp9Level52: {
		return "StdVideoVp9Level52";
	}
	case StdVideoVp9Level60: {
		return "StdVideoVp9Level60";
	}
	case StdVideoVp9Level61: {
		return "StdVideoVp9Level61";
	}
	case StdVideoVp9Level62: {
		return "StdVideoVp9Level62";
	}
	case StdVideoVp9LevelInvalid: {
		return "StdVideoVp9LevelInvalid";
	}
	}
	return "EnumElement not part of: StdVideoVP9Level";
}
template<> auto enumToString(StdVideoVP9Profile enumVal) -> std::string {
	using enum StdVideoVP9Profile;
	switch (enumVal) {
	case StdVideoVp9Profile0: {
		return "StdVideoVp9Profile0";
	}
	case StdVideoVp9Profile1: {
		return "StdVideoVp9Profile1";
	}
	case StdVideoVp9Profile2: {
		return "StdVideoVp9Profile2";
	}
	case StdVideoVp9Profile3: {
		return "StdVideoVp9Profile3";
	}
	case StdVideoVp9ProfileInvalid: {
		return "StdVideoVp9ProfileInvalid";
	}
	}
	return "EnumElement not part of: StdVideoVP9Profile";
}
template<> auto enumToString(StdVideoVP9ReferenceName enumVal) -> std::string {
	using enum StdVideoVP9ReferenceName;
	switch (enumVal) {
	case StdVideoVp9ReferenceNameIntraFrame: {
		return "StdVideoVp9ReferenceNameIntraFrame";
	}
	case StdVideoVp9ReferenceNameLastFrame: {
		return "StdVideoVp9ReferenceNameLastFrame";
	}
	case StdVideoVp9ReferenceNameGoldenFrame: {
		return "StdVideoVp9ReferenceNameGoldenFrame";
	}
	case StdVideoVp9ReferenceNameAltrefFrame: {
		return "StdVideoVp9ReferenceNameAltrefFrame";
	}
	case StdVideoVp9ReferenceNameInvalid: {
		return "StdVideoVp9ReferenceNameInvalid";
	}
	}
	return "EnumElement not part of: StdVideoVP9ReferenceName";
}
// NOLINTEND(readability-function-size)
} // namespace VkBindings::Reflections
