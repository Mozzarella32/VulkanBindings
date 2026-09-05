#include "VkBindings/EnumToString.hpp"
#include "VkBindings/Enums.hpp"

#include <string_view>

namespace VkBindings::Reflections {
using namespace std::string_view_literals;
// NOLINTBEGIN(readability-function-size)
template<> auto enumToString(AccelerationStructureBuildTypeKHR enumVal) -> std::string_view {
	using enum AccelerationStructureBuildTypeKHR;
	switch (enumVal) {
	case Host: {
		return "Host"sv;
	}
	case Device: {
		return "Device"sv;
	}
	case HostOrDevice: {
		return "HostOrDevice"sv;
	}
	}
	return "EnumElement not part of: AccelerationStructureBuildTypeKHR";
}
template<> auto enumToString(AccelerationStructureCompatibilityKHR enumVal) -> std::string_view {
	using enum AccelerationStructureCompatibilityKHR;
	switch (enumVal) {
	case Compatible: {
		return "Compatible"sv;
	}
	case Incompatible: {
		return "Incompatible"sv;
	}
	}
	return "EnumElement not part of: AccelerationStructureCompatibilityKHR";
}
template<> auto enumToString(AccelerationStructureMemoryRequirementsTypeNV enumVal) -> std::string_view {
	using enum AccelerationStructureMemoryRequirementsTypeNV;
	switch (enumVal) {
	case Object: {
		return "Object"sv;
	}
	case BuildScratch: {
		return "BuildScratch"sv;
	}
	case UpdateScratch: {
		return "UpdateScratch"sv;
	}
	}
	return "EnumElement not part of: AccelerationStructureMemoryRequirementsTypeNV";
}
template<> auto enumToString(AccelerationStructureMotionInstanceTypeNV enumVal) -> std::string_view {
	using enum AccelerationStructureMotionInstanceTypeNV;
	switch (enumVal) {
	case Static: {
		return "Static"sv;
	}
	case MatrixMotion: {
		return "MatrixMotion"sv;
	}
	case SrtMotion: {
		return "SrtMotion"sv;
	}
	}
	return "EnumElement not part of: AccelerationStructureMotionInstanceTypeNV";
}
template<> auto enumToString(AccelerationStructureSerializedBlockTypeKHR enumVal) -> std::string_view {
	using enum AccelerationStructureSerializedBlockTypeKHR;
	switch (enumVal) {
	case OpacityMicromap: {
		return "OpacityMicromap"sv;
	}
	}
	return "EnumElement not part of: AccelerationStructureSerializedBlockTypeKHR";
}
template<> auto enumToString(AccelerationStructureTypeKHR enumVal) -> std::string_view {
	using enum AccelerationStructureTypeKHR;
	switch (enumVal) {
	case TopLevel: {
		return "TopLevel"sv;
	}
	case BottomLevel: {
		return "BottomLevel"sv;
	}
	case Generic: {
		return "Generic"sv;
	}
	case OpacityMicromap: {
		return "OpacityMicromap"sv;
	}
	}
	return "EnumElement not part of: AccelerationStructureTypeKHR";
}
template<> auto enumToString(AntiLagModeAMD enumVal) -> std::string_view {
	using enum AntiLagModeAMD;
	switch (enumVal) {
	case DriverControl: {
		return "DriverControl"sv;
	}
	case On: {
		return "On"sv;
	}
	case Off: {
		return "Off"sv;
	}
	}
	return "EnumElement not part of: AntiLagModeAMD";
}
template<> auto enumToString(AntiLagStageAMD enumVal) -> std::string_view {
	using enum AntiLagStageAMD;
	switch (enumVal) {
	case Input: {
		return "Input"sv;
	}
	case Present: {
		return "Present"sv;
	}
	}
	return "EnumElement not part of: AntiLagStageAMD";
}
template<> auto enumToString(AttachmentLoadOp enumVal) -> std::string_view {
	using enum AttachmentLoadOp;
	switch (enumVal) {
	case Load: {
		return "Load"sv;
	}
	case Clear: {
		return "Clear"sv;
	}
	case DontCare: {
		return "DontCare"sv;
	}
	case None: {
		return "None"sv;
	}
	}
	return "EnumElement not part of: AttachmentLoadOp";
}
template<> auto enumToString(AttachmentStoreOp enumVal) -> std::string_view {
	using enum AttachmentStoreOp;
	switch (enumVal) {
	case Store: {
		return "Store"sv;
	}
	case DontCare: {
		return "DontCare"sv;
	}
	case None: {
		return "None"sv;
	}
	}
	return "EnumElement not part of: AttachmentStoreOp";
}
template<> auto enumToString(BlendFactor enumVal) -> std::string_view {
	using enum BlendFactor;
	switch (enumVal) {
	case Zero: {
		return "Zero"sv;
	}
	case One: {
		return "One"sv;
	}
	case SrcColor: {
		return "SrcColor"sv;
	}
	case OneMinusSrcColor: {
		return "OneMinusSrcColor"sv;
	}
	case DstColor: {
		return "DstColor"sv;
	}
	case OneMinusDstColor: {
		return "OneMinusDstColor"sv;
	}
	case SrcAlpha: {
		return "SrcAlpha"sv;
	}
	case OneMinusSrcAlpha: {
		return "OneMinusSrcAlpha"sv;
	}
	case DstAlpha: {
		return "DstAlpha"sv;
	}
	case OneMinusDstAlpha: {
		return "OneMinusDstAlpha"sv;
	}
	case ConstantColor: {
		return "ConstantColor"sv;
	}
	case OneMinusConstantColor: {
		return "OneMinusConstantColor"sv;
	}
	case ConstantAlpha: {
		return "ConstantAlpha"sv;
	}
	case OneMinusConstantAlpha: {
		return "OneMinusConstantAlpha"sv;
	}
	case SrcAlphaSaturate: {
		return "SrcAlphaSaturate"sv;
	}
	case Src1Color: {
		return "Src1Color"sv;
	}
	case OneMinusSrc1Color: {
		return "OneMinusSrc1Color"sv;
	}
	case Src1Alpha: {
		return "Src1Alpha"sv;
	}
	case OneMinusSrc1Alpha: {
		return "OneMinusSrc1Alpha"sv;
	}
	}
	return "EnumElement not part of: BlendFactor";
}
template<> auto enumToString(BlendOp enumVal) -> std::string_view {
	using enum BlendOp;
	switch (enumVal) {
	case Add: {
		return "Add"sv;
	}
	case Subtract: {
		return "Subtract"sv;
	}
	case ReverseSubtract: {
		return "ReverseSubtract"sv;
	}
	case Min: {
		return "Min"sv;
	}
	case Max: {
		return "Max"sv;
	}
	case ZeroEXT: {
		return "ZeroEXT"sv;
	}
	case SrcEXT: {
		return "SrcEXT"sv;
	}
	case DstEXT: {
		return "DstEXT"sv;
	}
	case SrcOverEXT: {
		return "SrcOverEXT"sv;
	}
	case DstOverEXT: {
		return "DstOverEXT"sv;
	}
	case SrcInEXT: {
		return "SrcInEXT"sv;
	}
	case DstInEXT: {
		return "DstInEXT"sv;
	}
	case SrcOutEXT: {
		return "SrcOutEXT"sv;
	}
	case DstOutEXT: {
		return "DstOutEXT"sv;
	}
	case SrcAtopEXT: {
		return "SrcAtopEXT"sv;
	}
	case DstAtopEXT: {
		return "DstAtopEXT"sv;
	}
	case XorEXT: {
		return "XorEXT"sv;
	}
	case MultiplyEXT: {
		return "MultiplyEXT"sv;
	}
	case ScreenEXT: {
		return "ScreenEXT"sv;
	}
	case OverlayEXT: {
		return "OverlayEXT"sv;
	}
	case DarkenEXT: {
		return "DarkenEXT"sv;
	}
	case LightenEXT: {
		return "LightenEXT"sv;
	}
	case ColordodgeEXT: {
		return "ColordodgeEXT"sv;
	}
	case ColorburnEXT: {
		return "ColorburnEXT"sv;
	}
	case HardlightEXT: {
		return "HardlightEXT"sv;
	}
	case SoftlightEXT: {
		return "SoftlightEXT"sv;
	}
	case DifferenceEXT: {
		return "DifferenceEXT"sv;
	}
	case ExclusionEXT: {
		return "ExclusionEXT"sv;
	}
	case InvertEXT: {
		return "InvertEXT"sv;
	}
	case InvertRgbEXT: {
		return "InvertRgbEXT"sv;
	}
	case LineardodgeEXT: {
		return "LineardodgeEXT"sv;
	}
	case LinearburnEXT: {
		return "LinearburnEXT"sv;
	}
	case VividlightEXT: {
		return "VividlightEXT"sv;
	}
	case LinearlightEXT: {
		return "LinearlightEXT"sv;
	}
	case PinlightEXT: {
		return "PinlightEXT"sv;
	}
	case HardmixEXT: {
		return "HardmixEXT"sv;
	}
	case HslHueEXT: {
		return "HslHueEXT"sv;
	}
	case HslSaturationEXT: {
		return "HslSaturationEXT"sv;
	}
	case HslColorEXT: {
		return "HslColorEXT"sv;
	}
	case HslLuminosityEXT: {
		return "HslLuminosityEXT"sv;
	}
	case PlusEXT: {
		return "PlusEXT"sv;
	}
	case PlusClampedEXT: {
		return "PlusClampedEXT"sv;
	}
	case PlusClampedAlphaEXT: {
		return "PlusClampedAlphaEXT"sv;
	}
	case PlusDarkerEXT: {
		return "PlusDarkerEXT"sv;
	}
	case MinusEXT: {
		return "MinusEXT"sv;
	}
	case MinusClampedEXT: {
		return "MinusClampedEXT"sv;
	}
	case ContrastEXT: {
		return "ContrastEXT"sv;
	}
	case InvertOvgEXT: {
		return "InvertOvgEXT"sv;
	}
	case RedEXT: {
		return "RedEXT"sv;
	}
	case GreenEXT: {
		return "GreenEXT"sv;
	}
	case BlueEXT: {
		return "BlueEXT"sv;
	}
	}
	return "EnumElement not part of: BlendOp";
}
template<> auto enumToString(BlendOverlapEXT enumVal) -> std::string_view {
	using enum BlendOverlapEXT;
	switch (enumVal) {
	case Uncorrelated: {
		return "Uncorrelated"sv;
	}
	case Disjoint: {
		return "Disjoint"sv;
	}
	case Conjoint: {
		return "Conjoint"sv;
	}
	}
	return "EnumElement not part of: BlendOverlapEXT";
}
template<> auto enumToString(BlockMatchWindowCompareModeQCOM enumVal) -> std::string_view {
	using enum BlockMatchWindowCompareModeQCOM;
	switch (enumVal) {
	case Min: {
		return "Min"sv;
	}
	case Max: {
		return "Max"sv;
	}
	}
	return "EnumElement not part of: BlockMatchWindowCompareModeQCOM";
}
template<> auto enumToString(BorderColor enumVal) -> std::string_view {
	using enum BorderColor;
	switch (enumVal) {
	case FloatTransparentBlack: {
		return "FloatTransparentBlack"sv;
	}
	case IntTransparentBlack: {
		return "IntTransparentBlack"sv;
	}
	case FloatOpaqueBlack: {
		return "FloatOpaqueBlack"sv;
	}
	case IntOpaqueBlack: {
		return "IntOpaqueBlack"sv;
	}
	case FloatOpaqueWhite: {
		return "FloatOpaqueWhite"sv;
	}
	case IntOpaqueWhite: {
		return "IntOpaqueWhite"sv;
	}
	case FloatCustomEXT: {
		return "FloatCustomEXT"sv;
	}
	case IntCustomEXT: {
		return "IntCustomEXT"sv;
	}
	}
	return "EnumElement not part of: BorderColor";
}
template<> auto enumToString(BuildAccelerationStructureModeKHR enumVal) -> std::string_view {
	using enum BuildAccelerationStructureModeKHR;
	switch (enumVal) {
	case Build: {
		return "Build"sv;
	}
	case Update: {
		return "Update"sv;
	}
	}
	return "EnumElement not part of: BuildAccelerationStructureModeKHR";
}
template<> auto enumToString(BuildMicromapModeEXT enumVal) -> std::string_view {
	using enum BuildMicromapModeEXT;
	switch (enumVal) {
	case Build: {
		return "Build"sv;
	}
	}
	return "EnumElement not part of: BuildMicromapModeEXT";
}
template<> auto enumToString(ChromaLocation enumVal) -> std::string_view {
	using enum ChromaLocation;
	switch (enumVal) {
	case CositedEven: {
		return "CositedEven"sv;
	}
	case Midpoint: {
		return "Midpoint"sv;
	}
	}
	return "EnumElement not part of: ChromaLocation";
}
template<> auto enumToString(ClusterAccelerationStructureOpModeNV enumVal) -> std::string_view {
	using enum ClusterAccelerationStructureOpModeNV;
	switch (enumVal) {
	case ImplicitDestinations: {
		return "ImplicitDestinations"sv;
	}
	case ExplicitDestinations: {
		return "ExplicitDestinations"sv;
	}
	case ComputeSizes: {
		return "ComputeSizes"sv;
	}
	}
	return "EnumElement not part of: ClusterAccelerationStructureOpModeNV";
}
template<> auto enumToString(ClusterAccelerationStructureOpTypeNV enumVal) -> std::string_view {
	using enum ClusterAccelerationStructureOpTypeNV;
	switch (enumVal) {
	case MoveObjects: {
		return "MoveObjects"sv;
	}
	case BuildClustersBottomLevel: {
		return "BuildClustersBottomLevel"sv;
	}
	case BuildTriangleCluster: {
		return "BuildTriangleCluster"sv;
	}
	case BuildTriangleClusterTemplate: {
		return "BuildTriangleClusterTemplate"sv;
	}
	case InstantiateTriangleCluster: {
		return "InstantiateTriangleCluster"sv;
	}
	case GetClusterTemplateIndices: {
		return "GetClusterTemplateIndices"sv;
	}
	}
	return "EnumElement not part of: ClusterAccelerationStructureOpTypeNV";
}
template<> auto enumToString(ClusterAccelerationStructureTypeNV enumVal) -> std::string_view {
	using enum ClusterAccelerationStructureTypeNV;
	switch (enumVal) {
	case ClustersBottomLevel: {
		return "ClustersBottomLevel"sv;
	}
	case TriangleCluster: {
		return "TriangleCluster"sv;
	}
	case TriangleClusterTemplate: {
		return "TriangleClusterTemplate"sv;
	}
	}
	return "EnumElement not part of: ClusterAccelerationStructureTypeNV";
}
template<> auto enumToString(CoarseSampleOrderTypeNV enumVal) -> std::string_view {
	using enum CoarseSampleOrderTypeNV;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case Custom: {
		return "Custom"sv;
	}
	case PixelMajor: {
		return "PixelMajor"sv;
	}
	case SampleMajor: {
		return "SampleMajor"sv;
	}
	}
	return "EnumElement not part of: CoarseSampleOrderTypeNV";
}
template<> auto enumToString(ColorSpaceKHR enumVal) -> std::string_view {
	using enum ColorSpaceKHR;
	switch (enumVal) {
	case SrgbNonlinear: {
		return "SrgbNonlinear"sv;
	}
	case DisplayP3NonlinearEXT: {
		return "DisplayP3NonlinearEXT"sv;
	}
	case ExtendedSrgbLinearEXT: {
		return "ExtendedSrgbLinearEXT"sv;
	}
	case DisplayP3LinearEXT: {
		return "DisplayP3LinearEXT"sv;
	}
	case DciP3NonlinearEXT: {
		return "DciP3NonlinearEXT"sv;
	}
	case Bt709LinearEXT: {
		return "Bt709LinearEXT"sv;
	}
	case Bt709NonlinearEXT: {
		return "Bt709NonlinearEXT"sv;
	}
	case Bt2020LinearEXT: {
		return "Bt2020LinearEXT"sv;
	}
	case Hdr10St2084EXT: {
		return "Hdr10St2084EXT"sv;
	}
	case DolbyvisionEXT: {
		return "DolbyvisionEXT"sv;
	}
	case Hdr10HlgEXT: {
		return "Hdr10HlgEXT"sv;
	}
	case AdobergbLinearEXT: {
		return "AdobergbLinearEXT"sv;
	}
	case AdobergbNonlinearEXT: {
		return "AdobergbNonlinearEXT"sv;
	}
	case PassThroughEXT: {
		return "PassThroughEXT"sv;
	}
	case ExtendedSrgbNonlinearEXT: {
		return "ExtendedSrgbNonlinearEXT"sv;
	}
	case DisplayNativeAMD: {
		return "DisplayNativeAMD"sv;
	}
	}
	return "EnumElement not part of: ColorSpaceKHR";
}
template<> auto enumToString(CommandBufferLevel enumVal) -> std::string_view {
	using enum CommandBufferLevel;
	switch (enumVal) {
	case Primary: {
		return "Primary"sv;
	}
	case Secondary: {
		return "Secondary"sv;
	}
	}
	return "EnumElement not part of: CommandBufferLevel";
}
template<> auto enumToString(CompareOp enumVal) -> std::string_view {
	using enum CompareOp;
	switch (enumVal) {
	case Never: {
		return "Never"sv;
	}
	case Less: {
		return "Less"sv;
	}
	case Equal: {
		return "Equal"sv;
	}
	case LessOrEqual: {
		return "LessOrEqual"sv;
	}
	case Greater: {
		return "Greater"sv;
	}
	case NotEqual: {
		return "NotEqual"sv;
	}
	case GreaterOrEqual: {
		return "GreaterOrEqual"sv;
	}
	case Always: {
		return "Always"sv;
	}
	}
	return "EnumElement not part of: CompareOp";
}
template<> auto enumToString(ComponentSwizzle enumVal) -> std::string_view {
	using enum ComponentSwizzle;
	switch (enumVal) {
	case Identity: {
		return "Identity"sv;
	}
	case Zero: {
		return "Zero"sv;
	}
	case One: {
		return "One"sv;
	}
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
	}
	return "EnumElement not part of: ComponentSwizzle";
}
template<> auto enumToString(ComponentTypeKHR enumVal) -> std::string_view {
	using enum ComponentTypeKHR;
	switch (enumVal) {
	case Float16: {
		return "Float16"sv;
	}
	case Float32: {
		return "Float32"sv;
	}
	case Float64: {
		return "Float64"sv;
	}
	case Sint8: {
		return "Sint8"sv;
	}
	case Sint16: {
		return "Sint16"sv;
	}
	case Sint32: {
		return "Sint32"sv;
	}
	case Sint64: {
		return "Sint64"sv;
	}
	case Uint8: {
		return "Uint8"sv;
	}
	case Uint16: {
		return "Uint16"sv;
	}
	case Uint32: {
		return "Uint32"sv;
	}
	case Uint64: {
		return "Uint64"sv;
	}
	case Bfloat16: {
		return "Bfloat16"sv;
	}
	case Sint8PackedNV: {
		return "Sint8PackedNV"sv;
	}
	case Uint8PackedNV: {
		return "Uint8PackedNV"sv;
	}
	case Float8E4M3EXT: {
		return "Float8E4M3EXT"sv;
	}
	case Float8E5M2EXT: {
		return "Float8E5M2EXT"sv;
	}
	case Float6E2M3EXT: {
		return "Float6E2M3EXT"sv;
	}
	case Float6E3M2EXT: {
		return "Float6E3M2EXT"sv;
	}
	case Float4E2M1EXT: {
		return "Float4E2M1EXT"sv;
	}
	case Float8UnsignedE8M0EXT: {
		return "Float8UnsignedE8M0EXT"sv;
	}
	case Mxint8EXT: {
		return "Mxint8EXT"sv;
	}
	}
	return "EnumElement not part of: ComponentTypeKHR";
}
template<> auto enumToString(CompressedTriangleFormatAMDX enumVal) -> std::string_view {
	using enum CompressedTriangleFormatAMDX;
	switch (enumVal) {
	case Dgf1: {
		return "Dgf1"sv;
	}
	}
	return "EnumElement not part of: CompressedTriangleFormatAMDX";
}
template<> auto enumToString(ConservativeRasterizationModeEXT enumVal) -> std::string_view {
	using enum ConservativeRasterizationModeEXT;
	switch (enumVal) {
	case Disabled: {
		return "Disabled"sv;
	}
	case Overestimate: {
		return "Overestimate"sv;
	}
	case Underestimate: {
		return "Underestimate"sv;
	}
	}
	return "EnumElement not part of: ConservativeRasterizationModeEXT";
}
template<> auto enumToString(CooperativeVectorMatrixLayoutNV enumVal) -> std::string_view {
	using enum CooperativeVectorMatrixLayoutNV;
	switch (enumVal) {
	case RowMajor: {
		return "RowMajor"sv;
	}
	case ColumnMajor: {
		return "ColumnMajor"sv;
	}
	case InferencingOptimal: {
		return "InferencingOptimal"sv;
	}
	case TrainingOptimal: {
		return "TrainingOptimal"sv;
	}
	}
	return "EnumElement not part of: CooperativeVectorMatrixLayoutNV";
}
template<> auto enumToString(CopyAccelerationStructureModeKHR enumVal) -> std::string_view {
	using enum CopyAccelerationStructureModeKHR;
	switch (enumVal) {
	case Clone: {
		return "Clone"sv;
	}
	case Compact: {
		return "Compact"sv;
	}
	case Serialize: {
		return "Serialize"sv;
	}
	case Deserialize: {
		return "Deserialize"sv;
	}
	}
	return "EnumElement not part of: CopyAccelerationStructureModeKHR";
}
template<> auto enumToString(CopyMicromapModeEXT enumVal) -> std::string_view {
	using enum CopyMicromapModeEXT;
	switch (enumVal) {
	case Clone: {
		return "Clone"sv;
	}
	case Serialize: {
		return "Serialize"sv;
	}
	case Deserialize: {
		return "Deserialize"sv;
	}
	case Compact: {
		return "Compact"sv;
	}
	}
	return "EnumElement not part of: CopyMicromapModeEXT";
}
template<> auto enumToString(CoverageModulationModeNV enumVal) -> std::string_view {
	using enum CoverageModulationModeNV;
	switch (enumVal) {
	case None: {
		return "None"sv;
	}
	case Rgb: {
		return "Rgb"sv;
	}
	case Alpha: {
		return "Alpha"sv;
	}
	case Rgba: {
		return "Rgba"sv;
	}
	}
	return "EnumElement not part of: CoverageModulationModeNV";
}
template<> auto enumToString(CoverageReductionModeNV enumVal) -> std::string_view {
	using enum CoverageReductionModeNV;
	switch (enumVal) {
	case Merge: {
		return "Merge"sv;
	}
	case Truncate: {
		return "Truncate"sv;
	}
	}
	return "EnumElement not part of: CoverageReductionModeNV";
}
template<> auto enumToString(CubicFilterWeightsQCOM enumVal) -> std::string_view {
	using enum CubicFilterWeightsQCOM;
	switch (enumVal) {
	case CatmullRom: {
		return "CatmullRom"sv;
	}
	case ZeroTangentCardinal: {
		return "ZeroTangentCardinal"sv;
	}
	case BSpline: {
		return "BSpline"sv;
	}
	case MitchellNetravali: {
		return "MitchellNetravali"sv;
	}
	}
	return "EnumElement not part of: CubicFilterWeightsQCOM";
}
template<> auto enumToString(DataGraphModelCacheTypeQCOM enumVal) -> std::string_view {
	using enum DataGraphModelCacheTypeQCOM;
	switch (enumVal) {
	case GenericBinary: {
		return "GenericBinary"sv;
	}
	}
	return "EnumElement not part of: DataGraphModelCacheTypeQCOM";
}
template<> auto enumToString(DataGraphOpticalFlowPerformanceLevelARM enumVal) -> std::string_view {
	using enum DataGraphOpticalFlowPerformanceLevelARM;
	switch (enumVal) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Slow: {
		return "Slow"sv;
	}
	case Medium: {
		return "Medium"sv;
	}
	case Fast: {
		return "Fast"sv;
	}
	}
	return "EnumElement not part of: DataGraphOpticalFlowPerformanceLevelARM";
}
template<> auto enumToString(DataGraphPipelineNodeConnectionTypeARM enumVal) -> std::string_view {
	using enum DataGraphPipelineNodeConnectionTypeARM;
	switch (enumVal) {
	case OpticalFlowInput: {
		return "OpticalFlowInput"sv;
	}
	case OpticalFlowReference: {
		return "OpticalFlowReference"sv;
	}
	case OpticalFlowHint: {
		return "OpticalFlowHint"sv;
	}
	case OpticalFlowFlowVector: {
		return "OpticalFlowFlowVector"sv;
	}
	case OpticalFlowCost: {
		return "OpticalFlowCost"sv;
	}
	}
	return "EnumElement not part of: DataGraphPipelineNodeConnectionTypeARM";
}
template<> auto enumToString(DataGraphPipelineNodeTypeARM enumVal) -> std::string_view {
	using enum DataGraphPipelineNodeTypeARM;
	switch (enumVal) {
	case OpticalFlow: {
		return "OpticalFlow"sv;
	}
	}
	return "EnumElement not part of: DataGraphPipelineNodeTypeARM";
}
template<> auto enumToString(DataGraphPipelinePropertyARM enumVal) -> std::string_view {
	using enum DataGraphPipelinePropertyARM;
	switch (enumVal) {
	case CreationLog: {
		return "CreationLog"sv;
	}
	case Identifier: {
		return "Identifier"sv;
	}
	case NeuralAcceleratorDebugDatabase: {
		return "NeuralAcceleratorDebugDatabase"sv;
	}
	case NeuralAcceleratorStatisticsInfo: {
		return "NeuralAcceleratorStatisticsInfo"sv;
	}
	}
	return "EnumElement not part of: DataGraphPipelinePropertyARM";
}
template<> auto enumToString(DataGraphPipelineSessionBindPointARM enumVal) -> std::string_view {
	using enum DataGraphPipelineSessionBindPointARM;
	switch (enumVal) {
	case Transient: {
		return "Transient"sv;
	}
	case OpticalFlowCache: {
		return "OpticalFlowCache"sv;
	}
	case NeuralAcceleratorStatistics: {
		return "NeuralAcceleratorStatistics"sv;
	}
	}
	return "EnumElement not part of: DataGraphPipelineSessionBindPointARM";
}
template<> auto enumToString(DataGraphPipelineSessionBindPointTypeARM enumVal) -> std::string_view {
	using enum DataGraphPipelineSessionBindPointTypeARM;
	switch (enumVal) {
	case Memory: {
		return "Memory"sv;
	}
	}
	return "EnumElement not part of: DataGraphPipelineSessionBindPointTypeARM";
}
template<> auto enumToString(DataGraphTOSALevelARM enumVal) -> std::string_view {
	using enum DataGraphTOSALevelARM;
	switch (enumVal) {
	case DataGraphTosaLevelNone: {
		return "DataGraphTosaLevelNone"sv;
	}
	case DataGraphTosaLevel8K: {
		return "DataGraphTosaLevel8K"sv;
	}
	}
	return "EnumElement not part of: DataGraphTOSALevelARM";
}
template<> auto enumToString(DebugReportObjectTypeEXT enumVal) -> std::string_view {
	using enum DebugReportObjectTypeEXT;
	switch (enumVal) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Instance: {
		return "Instance"sv;
	}
	case PhysicalDevice: {
		return "PhysicalDevice"sv;
	}
	case Device: {
		return "Device"sv;
	}
	case Queue: {
		return "Queue"sv;
	}
	case Semaphore: {
		return "Semaphore"sv;
	}
	case CommandBuffer: {
		return "CommandBuffer"sv;
	}
	case Fence: {
		return "Fence"sv;
	}
	case DeviceMemory: {
		return "DeviceMemory"sv;
	}
	case Buffer: {
		return "Buffer"sv;
	}
	case Image: {
		return "Image"sv;
	}
	case Event: {
		return "Event"sv;
	}
	case QueryPool: {
		return "QueryPool"sv;
	}
	case BufferView: {
		return "BufferView"sv;
	}
	case ImageView: {
		return "ImageView"sv;
	}
	case ShaderModule: {
		return "ShaderModule"sv;
	}
	case PipelineCache: {
		return "PipelineCache"sv;
	}
	case PipelineLayout: {
		return "PipelineLayout"sv;
	}
	case RenderPass: {
		return "RenderPass"sv;
	}
	case Pipeline: {
		return "Pipeline"sv;
	}
	case DescriptorSetLayout: {
		return "DescriptorSetLayout"sv;
	}
	case Sampler: {
		return "Sampler"sv;
	}
	case DescriptorPool: {
		return "DescriptorPool"sv;
	}
	case DescriptorSet: {
		return "DescriptorSet"sv;
	}
	case Framebuffer: {
		return "Framebuffer"sv;
	}
	case CommandPool: {
		return "CommandPool"sv;
	}
	case SurfaceKHR: {
		return "SurfaceKHR"sv;
	}
	case SwapchainKHR: {
		return "SwapchainKHR"sv;
	}
	case DebugReportCallbackEXT: {
		return "DebugReportCallbackEXT"sv;
	}
	case DisplayKHR: {
		return "DisplayKHR"sv;
	}
	case DisplayModeKHR: {
		return "DisplayModeKHR"sv;
	}
	case ValidationCacheEXT: {
		return "ValidationCacheEXT"sv;
	}
	case CuModuleNVX: {
		return "CuModuleNVX"sv;
	}
	case CuFunctionNVX: {
		return "CuFunctionNVX"sv;
	}
	case DescriptorUpdateTemplate: {
		return "DescriptorUpdateTemplate"sv;
	}
	case AccelerationStructureKHR: {
		return "AccelerationStructureKHR"sv;
	}
	case SamplerYcbcrConversion: {
		return "SamplerYcbcrConversion"sv;
	}
	case AccelerationStructureNV: {
		return "AccelerationStructureNV"sv;
	}
	case CudaModuleNV: {
		return "CudaModuleNV"sv;
	}
	case CudaFunctionNV: {
		return "CudaFunctionNV"sv;
	}
	case BufferCollectionFUCHSIA: {
		return "BufferCollectionFUCHSIA"sv;
	}
	}
	return "EnumElement not part of: DebugReportObjectTypeEXT";
}
template<> auto enumToString(DefaultVertexAttributeValueKHR enumVal) -> std::string_view {
	using enum DefaultVertexAttributeValueKHR;
	switch (enumVal) {
	case ZeroZeroZeroZero: {
		return "ZeroZeroZeroZero"sv;
	}
	case ZeroZeroZeroOne: {
		return "ZeroZeroZeroOne"sv;
	}
	}
	return "EnumElement not part of: DefaultVertexAttributeValueKHR";
}
template<> auto enumToString(DepthBiasRepresentationEXT enumVal) -> std::string_view {
	using enum DepthBiasRepresentationEXT;
	switch (enumVal) {
	case LeastRepresentableValueFormat: {
		return "LeastRepresentableValueFormat"sv;
	}
	case LeastRepresentableValueForceUnorm: {
		return "LeastRepresentableValueForceUnorm"sv;
	}
	case Float: {
		return "Float"sv;
	}
	}
	return "EnumElement not part of: DepthBiasRepresentationEXT";
}
template<> auto enumToString(DepthClampModeEXT enumVal) -> std::string_view {
	using enum DepthClampModeEXT;
	switch (enumVal) {
	case ViewportRange: {
		return "ViewportRange"sv;
	}
	case UserDefinedRange: {
		return "UserDefinedRange"sv;
	}
	}
	return "EnumElement not part of: DepthClampModeEXT";
}
template<> auto enumToString(DescriptorMappingSourceEXT enumVal) -> std::string_view {
	using enum DescriptorMappingSourceEXT;
	switch (enumVal) {
	case HeapWithConstantOffset: {
		return "HeapWithConstantOffset"sv;
	}
	case HeapWithPushIndex: {
		return "HeapWithPushIndex"sv;
	}
	case HeapWithIndirectIndex: {
		return "HeapWithIndirectIndex"sv;
	}
	case HeapWithIndirectIndexArray: {
		return "HeapWithIndirectIndexArray"sv;
	}
	case ResourceHeapData: {
		return "ResourceHeapData"sv;
	}
	case PushData: {
		return "PushData"sv;
	}
	case PushAddress: {
		return "PushAddress"sv;
	}
	case IndirectAddress: {
		return "IndirectAddress"sv;
	}
	case HeapWithShaderRecordIndex: {
		return "HeapWithShaderRecordIndex"sv;
	}
	case ShaderRecordData: {
		return "ShaderRecordData"sv;
	}
	case ShaderRecordAddress: {
		return "ShaderRecordAddress"sv;
	}
	}
	return "EnumElement not part of: DescriptorMappingSourceEXT";
}
template<> auto enumToString(DescriptorType enumVal) -> std::string_view {
	using enum DescriptorType;
	switch (enumVal) {
	case Sampler: {
		return "Sampler"sv;
	}
	case CombinedImageSampler: {
		return "CombinedImageSampler"sv;
	}
	case SampledImage: {
		return "SampledImage"sv;
	}
	case StorageImage: {
		return "StorageImage"sv;
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
	case UniformBufferDynamic: {
		return "UniformBufferDynamic"sv;
	}
	case StorageBufferDynamic: {
		return "StorageBufferDynamic"sv;
	}
	case InputAttachment: {
		return "InputAttachment"sv;
	}
	case InlineUniformBlock: {
		return "InlineUniformBlock"sv;
	}
	case AccelerationStructureKHR: {
		return "AccelerationStructureKHR"sv;
	}
	case AccelerationStructureNV: {
		return "AccelerationStructureNV"sv;
	}
	case MutableEXT: {
		return "MutableEXT"sv;
	}
	case SampleWeightImageQCOM: {
		return "SampleWeightImageQCOM"sv;
	}
	case BlockMatchImageQCOM: {
		return "BlockMatchImageQCOM"sv;
	}
	case TensorARM: {
		return "TensorARM"sv;
	}
	case PartitionedAccelerationStructureNV: {
		return "PartitionedAccelerationStructureNV"sv;
	}
	}
	return "EnumElement not part of: DescriptorType";
}
template<> auto enumToString(DescriptorUpdateTemplateType enumVal) -> std::string_view {
	using enum DescriptorUpdateTemplateType;
	switch (enumVal) {
	case DescriptorSet: {
		return "DescriptorSet"sv;
	}
	case PushDescriptors: {
		return "PushDescriptors"sv;
	}
	}
	return "EnumElement not part of: DescriptorUpdateTemplateType";
}
template<> auto enumToString(DeviceAddressBindingTypeEXT enumVal) -> std::string_view {
	using enum DeviceAddressBindingTypeEXT;
	switch (enumVal) {
	case Bind: {
		return "Bind"sv;
	}
	case Unbind: {
		return "Unbind"sv;
	}
	}
	return "EnumElement not part of: DeviceAddressBindingTypeEXT";
}
template<> auto enumToString(DeviceEventTypeEXT enumVal) -> std::string_view {
	using enum DeviceEventTypeEXT;
	switch (enumVal) {
	case DisplayHotplug: {
		return "DisplayHotplug"sv;
	}
	}
	return "EnumElement not part of: DeviceEventTypeEXT";
}
template<> auto enumToString(DeviceFaultAddressTypeKHR enumVal) -> std::string_view {
	using enum DeviceFaultAddressTypeKHR;
	switch (enumVal) {
	case None: {
		return "None"sv;
	}
	case ReadInvalid: {
		return "ReadInvalid"sv;
	}
	case WriteInvalid: {
		return "WriteInvalid"sv;
	}
	case ExecuteInvalid: {
		return "ExecuteInvalid"sv;
	}
	case InstructionPointerUnknown: {
		return "InstructionPointerUnknown"sv;
	}
	case InstructionPointerInvalid: {
		return "InstructionPointerInvalid"sv;
	}
	case InstructionPointerFault: {
		return "InstructionPointerFault"sv;
	}
	}
	return "EnumElement not part of: DeviceFaultAddressTypeKHR";
}
template<> auto enumToString(DeviceFaultVendorBinaryHeaderVersionKHR enumVal) -> std::string_view {
	using enum DeviceFaultVendorBinaryHeaderVersionKHR;
	switch (enumVal) {
	case One: {
		return "One"sv;
	}
	}
	return "EnumElement not part of: DeviceFaultVendorBinaryHeaderVersionKHR";
}
template<> auto enumToString(DeviceMemoryReportEventTypeEXT enumVal) -> std::string_view {
	using enum DeviceMemoryReportEventTypeEXT;
	switch (enumVal) {
	case Allocate: {
		return "Allocate"sv;
	}
	case Free: {
		return "Free"sv;
	}
	case Import: {
		return "Import"sv;
	}
	case Unimport: {
		return "Unimport"sv;
	}
	case AllocationFailed: {
		return "AllocationFailed"sv;
	}
	}
	return "EnumElement not part of: DeviceMemoryReportEventTypeEXT";
}
template<> auto enumToString(DirectDriverLoadingModeLUNARG enumVal) -> std::string_view {
	using enum DirectDriverLoadingModeLUNARG;
	switch (enumVal) {
	case Exclusive: {
		return "Exclusive"sv;
	}
	case Inclusive: {
		return "Inclusive"sv;
	}
	}
	return "EnumElement not part of: DirectDriverLoadingModeLUNARG";
}
template<> auto enumToString(DiscardRectangleModeEXT enumVal) -> std::string_view {
	using enum DiscardRectangleModeEXT;
	switch (enumVal) {
	case Inclusive: {
		return "Inclusive"sv;
	}
	case Exclusive: {
		return "Exclusive"sv;
	}
	}
	return "EnumElement not part of: DiscardRectangleModeEXT";
}
template<> auto enumToString(DisplacementMicromapFormatNV enumVal) -> std::string_view {
	using enum DisplacementMicromapFormatNV;
	switch (enumVal) {
	case v64Triangles64Bytes: {
		return "v64Triangles64Bytes"sv;
	}
	case v256Triangles128Bytes: {
		return "v256Triangles128Bytes"sv;
	}
	case v1024Triangles128Bytes: {
		return "v1024Triangles128Bytes"sv;
	}
	}
	return "EnumElement not part of: DisplacementMicromapFormatNV";
}
template<> auto enumToString(DisplayEventTypeEXT enumVal) -> std::string_view {
	using enum DisplayEventTypeEXT;
	switch (enumVal) {
	case FirstPixelOut: {
		return "FirstPixelOut"sv;
	}
	}
	return "EnumElement not part of: DisplayEventTypeEXT";
}
template<> auto enumToString(DisplayPowerStateEXT enumVal) -> std::string_view {
	using enum DisplayPowerStateEXT;
	switch (enumVal) {
	case Off: {
		return "Off"sv;
	}
	case Suspend: {
		return "Suspend"sv;
	}
	case On: {
		return "On"sv;
	}
	}
	return "EnumElement not part of: DisplayPowerStateEXT";
}
template<> auto enumToString(DisplaySurfaceStereoTypeNV enumVal) -> std::string_view {
	using enum DisplaySurfaceStereoTypeNV;
	switch (enumVal) {
	case None: {
		return "None"sv;
	}
	case OnboardDin: {
		return "OnboardDin"sv;
	}
	case Hdmi3D: {
		return "Hdmi3D"sv;
	}
	case InbandDisplayport: {
		return "InbandDisplayport"sv;
	}
	}
	return "EnumElement not part of: DisplaySurfaceStereoTypeNV";
}
template<> auto enumToString(DriverId enumVal) -> std::string_view {
	using enum DriverId;
	switch (enumVal) {
	case AMDProprietary: {
		return "AMDProprietary"sv;
	}
	case AMDOpenSource: {
		return "AMDOpenSource"sv;
	}
	case MESARadv: {
		return "MESARadv"sv;
	}
	case NvidiaProprietary: {
		return "NvidiaProprietary"sv;
	}
	case INTELProprietaryWindows: {
		return "INTELProprietaryWindows"sv;
	}
	case INTELOpenSourceMESA: {
		return "INTELOpenSourceMESA"sv;
	}
	case ImaginationProprietary: {
		return "ImaginationProprietary"sv;
	}
	case QualcommProprietary: {
		return "QualcommProprietary"sv;
	}
	case ARMProprietary: {
		return "ARMProprietary"sv;
	}
	case GOOGLESwiftshader: {
		return "GOOGLESwiftshader"sv;
	}
	case GGPProprietary: {
		return "GGPProprietary"sv;
	}
	case BroadcomProprietary: {
		return "BroadcomProprietary"sv;
	}
	case MESALlvmpipe: {
		return "MESALlvmpipe"sv;
	}
	case Moltenvk: {
		return "Moltenvk"sv;
	}
	case CoreaviProprietary: {
		return "CoreaviProprietary"sv;
	}
	case JUICEProprietary: {
		return "JUICEProprietary"sv;
	}
	case VerisiliconProprietary: {
		return "VerisiliconProprietary"sv;
	}
	case MESATurnip: {
		return "MESATurnip"sv;
	}
	case MESAV3Dv: {
		return "MESAV3Dv"sv;
	}
	case MESAPanvk: {
		return "MESAPanvk"sv;
	}
	case SAMSUNGProprietary: {
		return "SAMSUNGProprietary"sv;
	}
	case MESAVenus: {
		return "MESAVenus"sv;
	}
	case MESADozen: {
		return "MESADozen"sv;
	}
	case MESANvk: {
		return "MESANvk"sv;
	}
	case ImaginationOpenSourceMESA: {
		return "ImaginationOpenSourceMESA"sv;
	}
	case MESAHoneykrisp: {
		return "MESAHoneykrisp"sv;
	}
	case VulkanScEmulationOnVulkan: {
		return "VulkanScEmulationOnVulkan"sv;
	}
	case MESAKosmickrisp: {
		return "MESAKosmickrisp"sv;
	}
	case MESAGfxstream: {
		return "MESAGfxstream"sv;
	}
	case ApeSoft: {
		return "ApeSoft"sv;
	}
	case Reserved31: {
		return "Reserved31"sv;
	}
	}
	return "EnumElement not part of: DriverId";
}
template<> auto enumToString(DynamicState enumVal) -> std::string_view {
	using enum DynamicState;
	switch (enumVal) {
	case Viewport: {
		return "Viewport"sv;
	}
	case Scissor: {
		return "Scissor"sv;
	}
	case LineWidth: {
		return "LineWidth"sv;
	}
	case DepthBias: {
		return "DepthBias"sv;
	}
	case BlendConstants: {
		return "BlendConstants"sv;
	}
	case DepthBounds: {
		return "DepthBounds"sv;
	}
	case StencilCompareMask: {
		return "StencilCompareMask"sv;
	}
	case StencilWriteMask: {
		return "StencilWriteMask"sv;
	}
	case StencilReference: {
		return "StencilReference"sv;
	}
	case ViewportWScalingNV: {
		return "ViewportWScalingNV"sv;
	}
	case DiscardRectangleEXT: {
		return "DiscardRectangleEXT"sv;
	}
	case DiscardRectangleEnableEXT: {
		return "DiscardRectangleEnableEXT"sv;
	}
	case DiscardRectangleModeEXT: {
		return "DiscardRectangleModeEXT"sv;
	}
	case SampleLocationsEXT: {
		return "SampleLocationsEXT"sv;
	}
	case ViewportShadingRatePaletteNV: {
		return "ViewportShadingRatePaletteNV"sv;
	}
	case ViewportCoarseSampleOrderNV: {
		return "ViewportCoarseSampleOrderNV"sv;
	}
	case ExclusiveScissorEnableNV: {
		return "ExclusiveScissorEnableNV"sv;
	}
	case ExclusiveScissorNV: {
		return "ExclusiveScissorNV"sv;
	}
	case FragmentShadingRateKHR: {
		return "FragmentShadingRateKHR"sv;
	}
	case LineStipple: {
		return "LineStipple"sv;
	}
	case CullMode: {
		return "CullMode"sv;
	}
	case FrontFace: {
		return "FrontFace"sv;
	}
	case PrimitiveTopology: {
		return "PrimitiveTopology"sv;
	}
	case ViewportWithCount: {
		return "ViewportWithCount"sv;
	}
	case ScissorWithCount: {
		return "ScissorWithCount"sv;
	}
	case VertexInputBindingStride: {
		return "VertexInputBindingStride"sv;
	}
	case DepthTestEnable: {
		return "DepthTestEnable"sv;
	}
	case DepthWriteEnable: {
		return "DepthWriteEnable"sv;
	}
	case DepthCompareOp: {
		return "DepthCompareOp"sv;
	}
	case DepthBoundsTestEnable: {
		return "DepthBoundsTestEnable"sv;
	}
	case StencilTestEnable: {
		return "StencilTestEnable"sv;
	}
	case StencilOp: {
		return "StencilOp"sv;
	}
	case RayTracingPipelineStackSizeKHR: {
		return "RayTracingPipelineStackSizeKHR"sv;
	}
	case VertexInputEXT: {
		return "VertexInputEXT"sv;
	}
	case PatchControlPointsEXT: {
		return "PatchControlPointsEXT"sv;
	}
	case RasterizerDiscardEnable: {
		return "RasterizerDiscardEnable"sv;
	}
	case DepthBiasEnable: {
		return "DepthBiasEnable"sv;
	}
	case LogicOpEXT: {
		return "LogicOpEXT"sv;
	}
	case PrimitiveRestartEnable: {
		return "PrimitiveRestartEnable"sv;
	}
	case ColorWriteEnableEXT: {
		return "ColorWriteEnableEXT"sv;
	}
	case TessellationDomainOriginEXT: {
		return "TessellationDomainOriginEXT"sv;
	}
	case DepthClampEnableEXT: {
		return "DepthClampEnableEXT"sv;
	}
	case PolygonModeEXT: {
		return "PolygonModeEXT"sv;
	}
	case RasterizationSamplesEXT: {
		return "RasterizationSamplesEXT"sv;
	}
	case SampleMaskEXT: {
		return "SampleMaskEXT"sv;
	}
	case AlphaToCoverageEnableEXT: {
		return "AlphaToCoverageEnableEXT"sv;
	}
	case AlphaToOneEnableEXT: {
		return "AlphaToOneEnableEXT"sv;
	}
	case LogicOpEnableEXT: {
		return "LogicOpEnableEXT"sv;
	}
	case ColorBlendEnableEXT: {
		return "ColorBlendEnableEXT"sv;
	}
	case ColorBlendEquationEXT: {
		return "ColorBlendEquationEXT"sv;
	}
	case ColorWriteMaskEXT: {
		return "ColorWriteMaskEXT"sv;
	}
	case RasterizationStreamEXT: {
		return "RasterizationStreamEXT"sv;
	}
	case ConservativeRasterizationModeEXT: {
		return "ConservativeRasterizationModeEXT"sv;
	}
	case ExtraPrimitiveOverestimationSizeEXT: {
		return "ExtraPrimitiveOverestimationSizeEXT"sv;
	}
	case DepthClipEnableEXT: {
		return "DepthClipEnableEXT"sv;
	}
	case SampleLocationsEnableEXT: {
		return "SampleLocationsEnableEXT"sv;
	}
	case ColorBlendAdvancedEXT: {
		return "ColorBlendAdvancedEXT"sv;
	}
	case ProvokingVertexModeEXT: {
		return "ProvokingVertexModeEXT"sv;
	}
	case LineRasterizationModeEXT: {
		return "LineRasterizationModeEXT"sv;
	}
	case LineStippleEnableEXT: {
		return "LineStippleEnableEXT"sv;
	}
	case DepthClipNegativeOneToOneEXT: {
		return "DepthClipNegativeOneToOneEXT"sv;
	}
	case ViewportWScalingEnableNV: {
		return "ViewportWScalingEnableNV"sv;
	}
	case ViewportSwizzleNV: {
		return "ViewportSwizzleNV"sv;
	}
	case CoverageToColorEnableNV: {
		return "CoverageToColorEnableNV"sv;
	}
	case CoverageToColorLocationNV: {
		return "CoverageToColorLocationNV"sv;
	}
	case CoverageModulationModeNV: {
		return "CoverageModulationModeNV"sv;
	}
	case CoverageModulationTableEnableNV: {
		return "CoverageModulationTableEnableNV"sv;
	}
	case CoverageModulationTableNV: {
		return "CoverageModulationTableNV"sv;
	}
	case ShadingRateImageEnableNV: {
		return "ShadingRateImageEnableNV"sv;
	}
	case RepresentativeFragmentTestEnableNV: {
		return "RepresentativeFragmentTestEnableNV"sv;
	}
	case CoverageReductionModeNV: {
		return "CoverageReductionModeNV"sv;
	}
	case AttachmentFeedbackLoopEnableEXT: {
		return "AttachmentFeedbackLoopEnableEXT"sv;
	}
	case DepthClampRangeEXT: {
		return "DepthClampRangeEXT"sv;
	}
	}
	return "EnumElement not part of: DynamicState";
}
template<> auto enumToString(Filter enumVal) -> std::string_view {
	using enum Filter;
	switch (enumVal) {
	case Nearest: {
		return "Nearest"sv;
	}
	case Linear: {
		return "Linear"sv;
	}
	case CubicEXT: {
		return "CubicEXT"sv;
	}
	}
	return "EnumElement not part of: Filter";
}
template<> auto enumToString(Format enumVal) -> std::string_view {
	using enum Format;
	switch (enumVal) {
	case Undefined: {
		return "Undefined"sv;
	}
	case R4G4UnormPack8: {
		return "R4G4UnormPack8"sv;
	}
	case R4G4B4A4UnormPack16: {
		return "R4G4B4A4UnormPack16"sv;
	}
	case B4G4R4A4UnormPack16: {
		return "B4G4R4A4UnormPack16"sv;
	}
	case R5G6B5UnormPack16: {
		return "R5G6B5UnormPack16"sv;
	}
	case B5G6R5UnormPack16: {
		return "B5G6R5UnormPack16"sv;
	}
	case R5G5B5A1UnormPack16: {
		return "R5G5B5A1UnormPack16"sv;
	}
	case B5G5R5A1UnormPack16: {
		return "B5G5R5A1UnormPack16"sv;
	}
	case A1R5G5B5UnormPack16: {
		return "A1R5G5B5UnormPack16"sv;
	}
	case R8Unorm: {
		return "R8Unorm"sv;
	}
	case R8Snorm: {
		return "R8Snorm"sv;
	}
	case R8Uscaled: {
		return "R8Uscaled"sv;
	}
	case R8Sscaled: {
		return "R8Sscaled"sv;
	}
	case R8Uint: {
		return "R8Uint"sv;
	}
	case R8Sint: {
		return "R8Sint"sv;
	}
	case R8Srgb: {
		return "R8Srgb"sv;
	}
	case R8G8Unorm: {
		return "R8G8Unorm"sv;
	}
	case R8G8Snorm: {
		return "R8G8Snorm"sv;
	}
	case R8G8Uscaled: {
		return "R8G8Uscaled"sv;
	}
	case R8G8Sscaled: {
		return "R8G8Sscaled"sv;
	}
	case R8G8Uint: {
		return "R8G8Uint"sv;
	}
	case R8G8Sint: {
		return "R8G8Sint"sv;
	}
	case R8G8Srgb: {
		return "R8G8Srgb"sv;
	}
	case R8G8B8Unorm: {
		return "R8G8B8Unorm"sv;
	}
	case R8G8B8Snorm: {
		return "R8G8B8Snorm"sv;
	}
	case R8G8B8Uscaled: {
		return "R8G8B8Uscaled"sv;
	}
	case R8G8B8Sscaled: {
		return "R8G8B8Sscaled"sv;
	}
	case R8G8B8Uint: {
		return "R8G8B8Uint"sv;
	}
	case R8G8B8Sint: {
		return "R8G8B8Sint"sv;
	}
	case R8G8B8Srgb: {
		return "R8G8B8Srgb"sv;
	}
	case B8G8R8Unorm: {
		return "B8G8R8Unorm"sv;
	}
	case B8G8R8Snorm: {
		return "B8G8R8Snorm"sv;
	}
	case B8G8R8Uscaled: {
		return "B8G8R8Uscaled"sv;
	}
	case B8G8R8Sscaled: {
		return "B8G8R8Sscaled"sv;
	}
	case B8G8R8Uint: {
		return "B8G8R8Uint"sv;
	}
	case B8G8R8Sint: {
		return "B8G8R8Sint"sv;
	}
	case B8G8R8Srgb: {
		return "B8G8R8Srgb"sv;
	}
	case R8G8B8A8Unorm: {
		return "R8G8B8A8Unorm"sv;
	}
	case R8G8B8A8Snorm: {
		return "R8G8B8A8Snorm"sv;
	}
	case R8G8B8A8Uscaled: {
		return "R8G8B8A8Uscaled"sv;
	}
	case R8G8B8A8Sscaled: {
		return "R8G8B8A8Sscaled"sv;
	}
	case R8G8B8A8Uint: {
		return "R8G8B8A8Uint"sv;
	}
	case R8G8B8A8Sint: {
		return "R8G8B8A8Sint"sv;
	}
	case R8G8B8A8Srgb: {
		return "R8G8B8A8Srgb"sv;
	}
	case B8G8R8A8Unorm: {
		return "B8G8R8A8Unorm"sv;
	}
	case B8G8R8A8Snorm: {
		return "B8G8R8A8Snorm"sv;
	}
	case B8G8R8A8Uscaled: {
		return "B8G8R8A8Uscaled"sv;
	}
	case B8G8R8A8Sscaled: {
		return "B8G8R8A8Sscaled"sv;
	}
	case B8G8R8A8Uint: {
		return "B8G8R8A8Uint"sv;
	}
	case B8G8R8A8Sint: {
		return "B8G8R8A8Sint"sv;
	}
	case B8G8R8A8Srgb: {
		return "B8G8R8A8Srgb"sv;
	}
	case A8B8G8R8UnormPack32: {
		return "A8B8G8R8UnormPack32"sv;
	}
	case A8B8G8R8SnormPack32: {
		return "A8B8G8R8SnormPack32"sv;
	}
	case A8B8G8R8UscaledPack32: {
		return "A8B8G8R8UscaledPack32"sv;
	}
	case A8B8G8R8SscaledPack32: {
		return "A8B8G8R8SscaledPack32"sv;
	}
	case A8B8G8R8UintPack32: {
		return "A8B8G8R8UintPack32"sv;
	}
	case A8B8G8R8SintPack32: {
		return "A8B8G8R8SintPack32"sv;
	}
	case A8B8G8R8SrgbPack32: {
		return "A8B8G8R8SrgbPack32"sv;
	}
	case A2R10G10B10UnormPack32: {
		return "A2R10G10B10UnormPack32"sv;
	}
	case A2R10G10B10SnormPack32: {
		return "A2R10G10B10SnormPack32"sv;
	}
	case A2R10G10B10UscaledPack32: {
		return "A2R10G10B10UscaledPack32"sv;
	}
	case A2R10G10B10SscaledPack32: {
		return "A2R10G10B10SscaledPack32"sv;
	}
	case A2R10G10B10UintPack32: {
		return "A2R10G10B10UintPack32"sv;
	}
	case A2R10G10B10SintPack32: {
		return "A2R10G10B10SintPack32"sv;
	}
	case A2B10G10R10UnormPack32: {
		return "A2B10G10R10UnormPack32"sv;
	}
	case A2B10G10R10SnormPack32: {
		return "A2B10G10R10SnormPack32"sv;
	}
	case A2B10G10R10UscaledPack32: {
		return "A2B10G10R10UscaledPack32"sv;
	}
	case A2B10G10R10SscaledPack32: {
		return "A2B10G10R10SscaledPack32"sv;
	}
	case A2B10G10R10UintPack32: {
		return "A2B10G10R10UintPack32"sv;
	}
	case A2B10G10R10SintPack32: {
		return "A2B10G10R10SintPack32"sv;
	}
	case R16Unorm: {
		return "R16Unorm"sv;
	}
	case R16Snorm: {
		return "R16Snorm"sv;
	}
	case R16Uscaled: {
		return "R16Uscaled"sv;
	}
	case R16Sscaled: {
		return "R16Sscaled"sv;
	}
	case R16Uint: {
		return "R16Uint"sv;
	}
	case R16Sint: {
		return "R16Sint"sv;
	}
	case R16Sfloat: {
		return "R16Sfloat"sv;
	}
	case R16G16Unorm: {
		return "R16G16Unorm"sv;
	}
	case R16G16Snorm: {
		return "R16G16Snorm"sv;
	}
	case R16G16Uscaled: {
		return "R16G16Uscaled"sv;
	}
	case R16G16Sscaled: {
		return "R16G16Sscaled"sv;
	}
	case R16G16Uint: {
		return "R16G16Uint"sv;
	}
	case R16G16Sint: {
		return "R16G16Sint"sv;
	}
	case R16G16Sfloat: {
		return "R16G16Sfloat"sv;
	}
	case R16G16B16Unorm: {
		return "R16G16B16Unorm"sv;
	}
	case R16G16B16Snorm: {
		return "R16G16B16Snorm"sv;
	}
	case R16G16B16Uscaled: {
		return "R16G16B16Uscaled"sv;
	}
	case R16G16B16Sscaled: {
		return "R16G16B16Sscaled"sv;
	}
	case R16G16B16Uint: {
		return "R16G16B16Uint"sv;
	}
	case R16G16B16Sint: {
		return "R16G16B16Sint"sv;
	}
	case R16G16B16Sfloat: {
		return "R16G16B16Sfloat"sv;
	}
	case R16G16B16A16Unorm: {
		return "R16G16B16A16Unorm"sv;
	}
	case R16G16B16A16Snorm: {
		return "R16G16B16A16Snorm"sv;
	}
	case R16G16B16A16Uscaled: {
		return "R16G16B16A16Uscaled"sv;
	}
	case R16G16B16A16Sscaled: {
		return "R16G16B16A16Sscaled"sv;
	}
	case R16G16B16A16Uint: {
		return "R16G16B16A16Uint"sv;
	}
	case R16G16B16A16Sint: {
		return "R16G16B16A16Sint"sv;
	}
	case R16G16B16A16Sfloat: {
		return "R16G16B16A16Sfloat"sv;
	}
	case R32Uint: {
		return "R32Uint"sv;
	}
	case R32Sint: {
		return "R32Sint"sv;
	}
	case R32Sfloat: {
		return "R32Sfloat"sv;
	}
	case R32G32Uint: {
		return "R32G32Uint"sv;
	}
	case R32G32Sint: {
		return "R32G32Sint"sv;
	}
	case R32G32Sfloat: {
		return "R32G32Sfloat"sv;
	}
	case R32G32B32Uint: {
		return "R32G32B32Uint"sv;
	}
	case R32G32B32Sint: {
		return "R32G32B32Sint"sv;
	}
	case R32G32B32Sfloat: {
		return "R32G32B32Sfloat"sv;
	}
	case R32G32B32A32Uint: {
		return "R32G32B32A32Uint"sv;
	}
	case R32G32B32A32Sint: {
		return "R32G32B32A32Sint"sv;
	}
	case R32G32B32A32Sfloat: {
		return "R32G32B32A32Sfloat"sv;
	}
	case R64Uint: {
		return "R64Uint"sv;
	}
	case R64Sint: {
		return "R64Sint"sv;
	}
	case R64Sfloat: {
		return "R64Sfloat"sv;
	}
	case R64G64Uint: {
		return "R64G64Uint"sv;
	}
	case R64G64Sint: {
		return "R64G64Sint"sv;
	}
	case R64G64Sfloat: {
		return "R64G64Sfloat"sv;
	}
	case R64G64B64Uint: {
		return "R64G64B64Uint"sv;
	}
	case R64G64B64Sint: {
		return "R64G64B64Sint"sv;
	}
	case R64G64B64Sfloat: {
		return "R64G64B64Sfloat"sv;
	}
	case R64G64B64A64Uint: {
		return "R64G64B64A64Uint"sv;
	}
	case R64G64B64A64Sint: {
		return "R64G64B64A64Sint"sv;
	}
	case R64G64B64A64Sfloat: {
		return "R64G64B64A64Sfloat"sv;
	}
	case B10G11R11UfloatPack32: {
		return "B10G11R11UfloatPack32"sv;
	}
	case E5B9G9R9UfloatPack32: {
		return "E5B9G9R9UfloatPack32"sv;
	}
	case D16Unorm: {
		return "D16Unorm"sv;
	}
	case x8D24UnormPack32: {
		return "x8D24UnormPack32"sv;
	}
	case D32Sfloat: {
		return "D32Sfloat"sv;
	}
	case S8Uint: {
		return "S8Uint"sv;
	}
	case D16UnormS8Uint: {
		return "D16UnormS8Uint"sv;
	}
	case D24UnormS8Uint: {
		return "D24UnormS8Uint"sv;
	}
	case D32SfloatS8Uint: {
		return "D32SfloatS8Uint"sv;
	}
	case Bc1RgbUnormBlock: {
		return "Bc1RgbUnormBlock"sv;
	}
	case Bc1RgbSrgbBlock: {
		return "Bc1RgbSrgbBlock"sv;
	}
	case Bc1RgbaUnormBlock: {
		return "Bc1RgbaUnormBlock"sv;
	}
	case Bc1RgbaSrgbBlock: {
		return "Bc1RgbaSrgbBlock"sv;
	}
	case Bc2UnormBlock: {
		return "Bc2UnormBlock"sv;
	}
	case Bc2SrgbBlock: {
		return "Bc2SrgbBlock"sv;
	}
	case Bc3UnormBlock: {
		return "Bc3UnormBlock"sv;
	}
	case Bc3SrgbBlock: {
		return "Bc3SrgbBlock"sv;
	}
	case Bc4UnormBlock: {
		return "Bc4UnormBlock"sv;
	}
	case Bc4SnormBlock: {
		return "Bc4SnormBlock"sv;
	}
	case Bc5UnormBlock: {
		return "Bc5UnormBlock"sv;
	}
	case Bc5SnormBlock: {
		return "Bc5SnormBlock"sv;
	}
	case Bc6HUfloatBlock: {
		return "Bc6HUfloatBlock"sv;
	}
	case Bc6HSfloatBlock: {
		return "Bc6HSfloatBlock"sv;
	}
	case Bc7UnormBlock: {
		return "Bc7UnormBlock"sv;
	}
	case Bc7SrgbBlock: {
		return "Bc7SrgbBlock"sv;
	}
	case Etc2R8G8B8UnormBlock: {
		return "Etc2R8G8B8UnormBlock"sv;
	}
	case Etc2R8G8B8SrgbBlock: {
		return "Etc2R8G8B8SrgbBlock"sv;
	}
	case Etc2R8G8B8A1UnormBlock: {
		return "Etc2R8G8B8A1UnormBlock"sv;
	}
	case Etc2R8G8B8A1SrgbBlock: {
		return "Etc2R8G8B8A1SrgbBlock"sv;
	}
	case Etc2R8G8B8A8UnormBlock: {
		return "Etc2R8G8B8A8UnormBlock"sv;
	}
	case Etc2R8G8B8A8SrgbBlock: {
		return "Etc2R8G8B8A8SrgbBlock"sv;
	}
	case EacR11UnormBlock: {
		return "EacR11UnormBlock"sv;
	}
	case EacR11SnormBlock: {
		return "EacR11SnormBlock"sv;
	}
	case EacR11G11UnormBlock: {
		return "EacR11G11UnormBlock"sv;
	}
	case EacR11G11SnormBlock: {
		return "EacR11G11SnormBlock"sv;
	}
	case Astc4x4UnormBlock: {
		return "Astc4x4UnormBlock"sv;
	}
	case Astc4x4SrgbBlock: {
		return "Astc4x4SrgbBlock"sv;
	}
	case Astc5x4UnormBlock: {
		return "Astc5x4UnormBlock"sv;
	}
	case Astc5x4SrgbBlock: {
		return "Astc5x4SrgbBlock"sv;
	}
	case Astc5x5UnormBlock: {
		return "Astc5x5UnormBlock"sv;
	}
	case Astc5x5SrgbBlock: {
		return "Astc5x5SrgbBlock"sv;
	}
	case Astc6x5UnormBlock: {
		return "Astc6x5UnormBlock"sv;
	}
	case Astc6x5SrgbBlock: {
		return "Astc6x5SrgbBlock"sv;
	}
	case Astc6x6UnormBlock: {
		return "Astc6x6UnormBlock"sv;
	}
	case Astc6x6SrgbBlock: {
		return "Astc6x6SrgbBlock"sv;
	}
	case Astc8x5UnormBlock: {
		return "Astc8x5UnormBlock"sv;
	}
	case Astc8x5SrgbBlock: {
		return "Astc8x5SrgbBlock"sv;
	}
	case Astc8x6UnormBlock: {
		return "Astc8x6UnormBlock"sv;
	}
	case Astc8x6SrgbBlock: {
		return "Astc8x6SrgbBlock"sv;
	}
	case Astc8x8UnormBlock: {
		return "Astc8x8UnormBlock"sv;
	}
	case Astc8x8SrgbBlock: {
		return "Astc8x8SrgbBlock"sv;
	}
	case Astc10x5UnormBlock: {
		return "Astc10x5UnormBlock"sv;
	}
	case Astc10x5SrgbBlock: {
		return "Astc10x5SrgbBlock"sv;
	}
	case Astc10x6UnormBlock: {
		return "Astc10x6UnormBlock"sv;
	}
	case Astc10x6SrgbBlock: {
		return "Astc10x6SrgbBlock"sv;
	}
	case Astc10x8UnormBlock: {
		return "Astc10x8UnormBlock"sv;
	}
	case Astc10x8SrgbBlock: {
		return "Astc10x8SrgbBlock"sv;
	}
	case Astc10x10UnormBlock: {
		return "Astc10x10UnormBlock"sv;
	}
	case Astc10x10SrgbBlock: {
		return "Astc10x10SrgbBlock"sv;
	}
	case Astc12x10UnormBlock: {
		return "Astc12x10UnormBlock"sv;
	}
	case Astc12x10SrgbBlock: {
		return "Astc12x10SrgbBlock"sv;
	}
	case Astc12x12UnormBlock: {
		return "Astc12x12UnormBlock"sv;
	}
	case Astc12x12SrgbBlock: {
		return "Astc12x12SrgbBlock"sv;
	}
	case Pvrtc12BppUnormBlockIMG: {
		return "Pvrtc12BppUnormBlockIMG"sv;
	}
	case Pvrtc14BppUnormBlockIMG: {
		return "Pvrtc14BppUnormBlockIMG"sv;
	}
	case Pvrtc22BppUnormBlockIMG: {
		return "Pvrtc22BppUnormBlockIMG"sv;
	}
	case Pvrtc24BppUnormBlockIMG: {
		return "Pvrtc24BppUnormBlockIMG"sv;
	}
	case Pvrtc12BppSrgbBlockIMG: {
		return "Pvrtc12BppSrgbBlockIMG"sv;
	}
	case Pvrtc14BppSrgbBlockIMG: {
		return "Pvrtc14BppSrgbBlockIMG"sv;
	}
	case Pvrtc22BppSrgbBlockIMG: {
		return "Pvrtc22BppSrgbBlockIMG"sv;
	}
	case Pvrtc24BppSrgbBlockIMG: {
		return "Pvrtc24BppSrgbBlockIMG"sv;
	}
	case Astc4x4SfloatBlock: {
		return "Astc4x4SfloatBlock"sv;
	}
	case Astc5x4SfloatBlock: {
		return "Astc5x4SfloatBlock"sv;
	}
	case Astc5x5SfloatBlock: {
		return "Astc5x5SfloatBlock"sv;
	}
	case Astc6x5SfloatBlock: {
		return "Astc6x5SfloatBlock"sv;
	}
	case Astc6x6SfloatBlock: {
		return "Astc6x6SfloatBlock"sv;
	}
	case Astc8x5SfloatBlock: {
		return "Astc8x5SfloatBlock"sv;
	}
	case Astc8x6SfloatBlock: {
		return "Astc8x6SfloatBlock"sv;
	}
	case Astc8x8SfloatBlock: {
		return "Astc8x8SfloatBlock"sv;
	}
	case Astc10x5SfloatBlock: {
		return "Astc10x5SfloatBlock"sv;
	}
	case Astc10x6SfloatBlock: {
		return "Astc10x6SfloatBlock"sv;
	}
	case Astc10x8SfloatBlock: {
		return "Astc10x8SfloatBlock"sv;
	}
	case Astc10x10SfloatBlock: {
		return "Astc10x10SfloatBlock"sv;
	}
	case Astc12x10SfloatBlock: {
		return "Astc12x10SfloatBlock"sv;
	}
	case Astc12x12SfloatBlock: {
		return "Astc12x12SfloatBlock"sv;
	}
	case G8B8G8R8422Unorm: {
		return "G8B8G8R8422Unorm"sv;
	}
	case B8G8R8G8422Unorm: {
		return "B8G8R8G8422Unorm"sv;
	}
	case G8B8R83Plane420Unorm: {
		return "G8B8R83Plane420Unorm"sv;
	}
	case G8B8R82Plane420Unorm: {
		return "G8B8R82Plane420Unorm"sv;
	}
	case G8B8R83Plane422Unorm: {
		return "G8B8R83Plane422Unorm"sv;
	}
	case G8B8R82Plane422Unorm: {
		return "G8B8R82Plane422Unorm"sv;
	}
	case G8B8R83Plane444Unorm: {
		return "G8B8R83Plane444Unorm"sv;
	}
	case R10x6UnormPack16: {
		return "R10x6UnormPack16"sv;
	}
	case R10x6G10x6Unorm2Pack16: {
		return "R10x6G10x6Unorm2Pack16"sv;
	}
	case R10x6G10x6B10x6A10x6Unorm4Pack16: {
		return "R10x6G10x6B10x6A10x6Unorm4Pack16"sv;
	}
	case G10x6B10x6G10x6R10x6422Unorm4Pack16: {
		return "G10x6B10x6G10x6R10x6422Unorm4Pack16"sv;
	}
	case B10x6G10x6R10x6G10x6422Unorm4Pack16: {
		return "B10x6G10x6R10x6G10x6422Unorm4Pack16"sv;
	}
	case G10x6B10x6R10x63Plane420Unorm3Pack16: {
		return "G10x6B10x6R10x63Plane420Unorm3Pack16"sv;
	}
	case G10x6B10x6R10x62Plane420Unorm3Pack16: {
		return "G10x6B10x6R10x62Plane420Unorm3Pack16"sv;
	}
	case G10x6B10x6R10x63Plane422Unorm3Pack16: {
		return "G10x6B10x6R10x63Plane422Unorm3Pack16"sv;
	}
	case G10x6B10x6R10x62Plane422Unorm3Pack16: {
		return "G10x6B10x6R10x62Plane422Unorm3Pack16"sv;
	}
	case G10x6B10x6R10x63Plane444Unorm3Pack16: {
		return "G10x6B10x6R10x63Plane444Unorm3Pack16"sv;
	}
	case R12x4UnormPack16: {
		return "R12x4UnormPack16"sv;
	}
	case R12x4G12x4Unorm2Pack16: {
		return "R12x4G12x4Unorm2Pack16"sv;
	}
	case R12x4G12x4B12x4A12x4Unorm4Pack16: {
		return "R12x4G12x4B12x4A12x4Unorm4Pack16"sv;
	}
	case G12x4B12x4G12x4R12x4422Unorm4Pack16: {
		return "G12x4B12x4G12x4R12x4422Unorm4Pack16"sv;
	}
	case B12x4G12x4R12x4G12x4422Unorm4Pack16: {
		return "B12x4G12x4R12x4G12x4422Unorm4Pack16"sv;
	}
	case G12x4B12x4R12x43Plane420Unorm3Pack16: {
		return "G12x4B12x4R12x43Plane420Unorm3Pack16"sv;
	}
	case G12x4B12x4R12x42Plane420Unorm3Pack16: {
		return "G12x4B12x4R12x42Plane420Unorm3Pack16"sv;
	}
	case G12x4B12x4R12x43Plane422Unorm3Pack16: {
		return "G12x4B12x4R12x43Plane422Unorm3Pack16"sv;
	}
	case G12x4B12x4R12x42Plane422Unorm3Pack16: {
		return "G12x4B12x4R12x42Plane422Unorm3Pack16"sv;
	}
	case G12x4B12x4R12x43Plane444Unorm3Pack16: {
		return "G12x4B12x4R12x43Plane444Unorm3Pack16"sv;
	}
	case G16B16G16R16422Unorm: {
		return "G16B16G16R16422Unorm"sv;
	}
	case B16G16R16G16422Unorm: {
		return "B16G16R16G16422Unorm"sv;
	}
	case G16B16R163Plane420Unorm: {
		return "G16B16R163Plane420Unorm"sv;
	}
	case G16B16R162Plane420Unorm: {
		return "G16B16R162Plane420Unorm"sv;
	}
	case G16B16R163Plane422Unorm: {
		return "G16B16R163Plane422Unorm"sv;
	}
	case G16B16R162Plane422Unorm: {
		return "G16B16R162Plane422Unorm"sv;
	}
	case G16B16R163Plane444Unorm: {
		return "G16B16R163Plane444Unorm"sv;
	}
	case Astc3x3x3UnormBlockEXT: {
		return "Astc3x3x3UnormBlockEXT"sv;
	}
	case Astc3x3x3SrgbBlockEXT: {
		return "Astc3x3x3SrgbBlockEXT"sv;
	}
	case Astc3x3x3SfloatBlockEXT: {
		return "Astc3x3x3SfloatBlockEXT"sv;
	}
	case Astc4x3x3UnormBlockEXT: {
		return "Astc4x3x3UnormBlockEXT"sv;
	}
	case Astc4x3x3SrgbBlockEXT: {
		return "Astc4x3x3SrgbBlockEXT"sv;
	}
	case Astc4x3x3SfloatBlockEXT: {
		return "Astc4x3x3SfloatBlockEXT"sv;
	}
	case Astc4x4x3UnormBlockEXT: {
		return "Astc4x4x3UnormBlockEXT"sv;
	}
	case Astc4x4x3SrgbBlockEXT: {
		return "Astc4x4x3SrgbBlockEXT"sv;
	}
	case Astc4x4x3SfloatBlockEXT: {
		return "Astc4x4x3SfloatBlockEXT"sv;
	}
	case Astc4x4x4UnormBlockEXT: {
		return "Astc4x4x4UnormBlockEXT"sv;
	}
	case Astc4x4x4SrgbBlockEXT: {
		return "Astc4x4x4SrgbBlockEXT"sv;
	}
	case Astc4x4x4SfloatBlockEXT: {
		return "Astc4x4x4SfloatBlockEXT"sv;
	}
	case Astc5x4x4UnormBlockEXT: {
		return "Astc5x4x4UnormBlockEXT"sv;
	}
	case Astc5x4x4SrgbBlockEXT: {
		return "Astc5x4x4SrgbBlockEXT"sv;
	}
	case Astc5x4x4SfloatBlockEXT: {
		return "Astc5x4x4SfloatBlockEXT"sv;
	}
	case Astc5x5x4UnormBlockEXT: {
		return "Astc5x5x4UnormBlockEXT"sv;
	}
	case Astc5x5x4SrgbBlockEXT: {
		return "Astc5x5x4SrgbBlockEXT"sv;
	}
	case Astc5x5x4SfloatBlockEXT: {
		return "Astc5x5x4SfloatBlockEXT"sv;
	}
	case Astc5x5x5UnormBlockEXT: {
		return "Astc5x5x5UnormBlockEXT"sv;
	}
	case Astc5x5x5SrgbBlockEXT: {
		return "Astc5x5x5SrgbBlockEXT"sv;
	}
	case Astc5x5x5SfloatBlockEXT: {
		return "Astc5x5x5SfloatBlockEXT"sv;
	}
	case Astc6x5x5UnormBlockEXT: {
		return "Astc6x5x5UnormBlockEXT"sv;
	}
	case Astc6x5x5SrgbBlockEXT: {
		return "Astc6x5x5SrgbBlockEXT"sv;
	}
	case Astc6x5x5SfloatBlockEXT: {
		return "Astc6x5x5SfloatBlockEXT"sv;
	}
	case Astc6x6x5UnormBlockEXT: {
		return "Astc6x6x5UnormBlockEXT"sv;
	}
	case Astc6x6x5SrgbBlockEXT: {
		return "Astc6x6x5SrgbBlockEXT"sv;
	}
	case Astc6x6x5SfloatBlockEXT: {
		return "Astc6x6x5SfloatBlockEXT"sv;
	}
	case Astc6x6x6UnormBlockEXT: {
		return "Astc6x6x6UnormBlockEXT"sv;
	}
	case Astc6x6x6SrgbBlockEXT: {
		return "Astc6x6x6SrgbBlockEXT"sv;
	}
	case Astc6x6x6SfloatBlockEXT: {
		return "Astc6x6x6SfloatBlockEXT"sv;
	}
	case G8B8R82Plane444Unorm: {
		return "G8B8R82Plane444Unorm"sv;
	}
	case G10x6B10x6R10x62Plane444Unorm3Pack16: {
		return "G10x6B10x6R10x62Plane444Unorm3Pack16"sv;
	}
	case G12x4B12x4R12x42Plane444Unorm3Pack16: {
		return "G12x4B12x4R12x42Plane444Unorm3Pack16"sv;
	}
	case G16B16R162Plane444Unorm: {
		return "G16B16R162Plane444Unorm"sv;
	}
	case A4R4G4B4UnormPack16: {
		return "A4R4G4B4UnormPack16"sv;
	}
	case A4B4G4R4UnormPack16: {
		return "A4B4G4R4UnormPack16"sv;
	}
	case R8BoolARM: {
		return "R8BoolARM"sv;
	}
	case R16SfloatFpencodingBfloat16ARM: {
		return "R16SfloatFpencodingBfloat16ARM"sv;
	}
	case R8SfloatFpencodingFloat8E4M3ARM: {
		return "R8SfloatFpencodingFloat8E4M3ARM"sv;
	}
	case R8SfloatFpencodingFloat8E5M2ARM: {
		return "R8SfloatFpencodingFloat8E5M2ARM"sv;
	}
	case R16G16Sfixed5NV: {
		return "R16G16Sfixed5NV"sv;
	}
	case A1B5G5R5UnormPack16: {
		return "A1B5G5R5UnormPack16"sv;
	}
	case A8Unorm: {
		return "A8Unorm"sv;
	}
	case R10x6UintPack16ARM: {
		return "R10x6UintPack16ARM"sv;
	}
	case R10x6G10x6Uint2Pack16ARM: {
		return "R10x6G10x6Uint2Pack16ARM"sv;
	}
	case R10x6G10x6B10x6A10x6Uint4Pack16ARM: {
		return "R10x6G10x6B10x6A10x6Uint4Pack16ARM"sv;
	}
	case R12x4UintPack16ARM: {
		return "R12x4UintPack16ARM"sv;
	}
	case R12x4G12x4Uint2Pack16ARM: {
		return "R12x4G12x4Uint2Pack16ARM"sv;
	}
	case R12x4G12x4B12x4A12x4Uint4Pack16ARM: {
		return "R12x4G12x4B12x4A12x4Uint4Pack16ARM"sv;
	}
	case R14x2UintPack16ARM: {
		return "R14x2UintPack16ARM"sv;
	}
	case R14x2G14x2Uint2Pack16ARM: {
		return "R14x2G14x2Uint2Pack16ARM"sv;
	}
	case R14x2G14x2B14x2A14x2Uint4Pack16ARM: {
		return "R14x2G14x2B14x2A14x2Uint4Pack16ARM"sv;
	}
	case R14x2UnormPack16ARM: {
		return "R14x2UnormPack16ARM"sv;
	}
	case R14x2G14x2Unorm2Pack16ARM: {
		return "R14x2G14x2Unorm2Pack16ARM"sv;
	}
	case R14x2G14x2B14x2A14x2Unorm4Pack16ARM: {
		return "R14x2G14x2B14x2A14x2Unorm4Pack16ARM"sv;
	}
	case G14x2B14x2R14x22Plane420Unorm3Pack16ARM: {
		return "G14x2B14x2R14x22Plane420Unorm3Pack16ARM"sv;
	}
	case G14x2B14x2R14x22Plane422Unorm3Pack16ARM: {
		return "G14x2B14x2R14x22Plane422Unorm3Pack16ARM"sv;
	}
	}
	return "EnumElement not part of: Format";
}
template<> auto enumToString(FragmentShadingRateNV enumVal) -> std::string_view {
	using enum FragmentShadingRateNV;
	switch (enumVal) {
	case v1InvocationPerPixel: {
		return "v1InvocationPerPixel"sv;
	}
	case v1InvocationPer1x2Pixels: {
		return "v1InvocationPer1x2Pixels"sv;
	}
	case v1InvocationPer2x1Pixels: {
		return "v1InvocationPer2x1Pixels"sv;
	}
	case v1InvocationPer2x2Pixels: {
		return "v1InvocationPer2x2Pixels"sv;
	}
	case v1InvocationPer2x4Pixels: {
		return "v1InvocationPer2x4Pixels"sv;
	}
	case v1InvocationPer4x2Pixels: {
		return "v1InvocationPer4x2Pixels"sv;
	}
	case v1InvocationPer4x4Pixels: {
		return "v1InvocationPer4x4Pixels"sv;
	}
	case v2InvocationsPerPixel: {
		return "v2InvocationsPerPixel"sv;
	}
	case v4InvocationsPerPixel: {
		return "v4InvocationsPerPixel"sv;
	}
	case v8InvocationsPerPixel: {
		return "v8InvocationsPerPixel"sv;
	}
	case v16InvocationsPerPixel: {
		return "v16InvocationsPerPixel"sv;
	}
	case NoInvocations: {
		return "NoInvocations"sv;
	}
	}
	return "EnumElement not part of: FragmentShadingRateNV";
}
template<> auto enumToString(FragmentShadingRateCombinerOpKHR enumVal) -> std::string_view {
	using enum FragmentShadingRateCombinerOpKHR;
	switch (enumVal) {
	case Keep: {
		return "Keep"sv;
	}
	case Replace: {
		return "Replace"sv;
	}
	case Min: {
		return "Min"sv;
	}
	case Max: {
		return "Max"sv;
	}
	case Mul: {
		return "Mul"sv;
	}
	}
	return "EnumElement not part of: FragmentShadingRateCombinerOpKHR";
}
template<> auto enumToString(FragmentShadingRateTypeNV enumVal) -> std::string_view {
	using enum FragmentShadingRateTypeNV;
	switch (enumVal) {
	case FragmentSize: {
		return "FragmentSize"sv;
	}
	case Enums: {
		return "Enums"sv;
	}
	}
	return "EnumElement not part of: FragmentShadingRateTypeNV";
}
template<> auto enumToString(FrontFace enumVal) -> std::string_view {
	using enum FrontFace;
	switch (enumVal) {
	case CounterClockwise: {
		return "CounterClockwise"sv;
	}
	case Clockwise: {
		return "Clockwise"sv;
	}
	}
	return "EnumElement not part of: FrontFace";
}
template<> auto enumToString(FullScreenExclusiveEXT enumVal) -> std::string_view {
	using enum FullScreenExclusiveEXT;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case Allowed: {
		return "Allowed"sv;
	}
	case Disallowed: {
		return "Disallowed"sv;
	}
	case ApplicationControlled: {
		return "ApplicationControlled"sv;
	}
	}
	return "EnumElement not part of: FullScreenExclusiveEXT";
}
template<> auto enumToString(GeometryTypeKHR enumVal) -> std::string_view {
	using enum GeometryTypeKHR;
	switch (enumVal) {
	case Triangles: {
		return "Triangles"sv;
	}
	case Aabbs: {
		return "Aabbs"sv;
	}
	case Instances: {
		return "Instances"sv;
	}
	case SpheresNV: {
		return "SpheresNV"sv;
	}
	case LinearSweptSpheresNV: {
		return "LinearSweptSpheresNV"sv;
	}
	case DenseGeometryFormatTrianglesAMDX: {
		return "DenseGeometryFormatTrianglesAMDX"sv;
	}
	case Micromap: {
		return "Micromap"sv;
	}
	}
	return "EnumElement not part of: GeometryTypeKHR";
}
template<> auto enumToString(GpaDeviceClockModeAMD enumVal) -> std::string_view {
	using enum GpaDeviceClockModeAMD;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case Query: {
		return "Query"sv;
	}
	case Profiling: {
		return "Profiling"sv;
	}
	case MinMemory: {
		return "MinMemory"sv;
	}
	case MinEngine: {
		return "MinEngine"sv;
	}
	case Peak: {
		return "Peak"sv;
	}
	}
	return "EnumElement not part of: GpaDeviceClockModeAMD";
}
template<> auto enumToString(GpaPerfBlockAMD enumVal) -> std::string_view {
	using enum GpaPerfBlockAMD;
	switch (enumVal) {
	case Cpf: {
		return "Cpf"sv;
	}
	case Ia: {
		return "Ia"sv;
	}
	case Vgt: {
		return "Vgt"sv;
	}
	case Pa: {
		return "Pa"sv;
	}
	case Sc: {
		return "Sc"sv;
	}
	case Spi: {
		return "Spi"sv;
	}
	case Sq: {
		return "Sq"sv;
	}
	case Sx: {
		return "Sx"sv;
	}
	case Ta: {
		return "Ta"sv;
	}
	case Td: {
		return "Td"sv;
	}
	case Tcp: {
		return "Tcp"sv;
	}
	case Tcc: {
		return "Tcc"sv;
	}
	case Tca: {
		return "Tca"sv;
	}
	case Db: {
		return "Db"sv;
	}
	case Cb: {
		return "Cb"sv;
	}
	case Gds: {
		return "Gds"sv;
	}
	case Srbm: {
		return "Srbm"sv;
	}
	case Grbm: {
		return "Grbm"sv;
	}
	case GrbmSe: {
		return "GrbmSe"sv;
	}
	case Rlc: {
		return "Rlc"sv;
	}
	case Dma: {
		return "Dma"sv;
	}
	case Mc: {
		return "Mc"sv;
	}
	case Cpg: {
		return "Cpg"sv;
	}
	case Cpc: {
		return "Cpc"sv;
	}
	case Wd: {
		return "Wd"sv;
	}
	case Tcs: {
		return "Tcs"sv;
	}
	case Atc: {
		return "Atc"sv;
	}
	case AtcL2: {
		return "AtcL2"sv;
	}
	case McVmL2: {
		return "McVmL2"sv;
	}
	case Ea: {
		return "Ea"sv;
	}
	case Rpb: {
		return "Rpb"sv;
	}
	case Rmi: {
		return "Rmi"sv;
	}
	case Umcch: {
		return "Umcch"sv;
	}
	case Ge: {
		return "Ge"sv;
	}
	case Gl1A: {
		return "Gl1A"sv;
	}
	case Gl1C: {
		return "Gl1C"sv;
	}
	case Gl1Cg: {
		return "Gl1Cg"sv;
	}
	case Gl2A: {
		return "Gl2A"sv;
	}
	case Gl2C: {
		return "Gl2C"sv;
	}
	case Cha: {
		return "Cha"sv;
	}
	case Chc: {
		return "Chc"sv;
	}
	case Chcg: {
		return "Chcg"sv;
	}
	case Gus: {
		return "Gus"sv;
	}
	case Gcr: {
		return "Gcr"sv;
	}
	case Ph: {
		return "Ph"sv;
	}
	case Utcl1: {
		return "Utcl1"sv;
	}
	case GeDist: {
		return "GeDist"sv;
	}
	case GeSe: {
		return "GeSe"sv;
	}
	case DfMall: {
		return "DfMall"sv;
	}
	case SqWgp: {
		return "SqWgp"sv;
	}
	case Pc: {
		return "Pc"sv;
	}
	case Gl1Xa: {
		return "Gl1Xa"sv;
	}
	case Gl1Xc: {
		return "Gl1Xc"sv;
	}
	case Wgs: {
		return "Wgs"sv;
	}
	case Eacpwd: {
		return "Eacpwd"sv;
	}
	case Ease: {
		return "Ease"sv;
	}
	case Rlcuser: {
		return "Rlcuser"sv;
	}
	}
	return "EnumElement not part of: GpaPerfBlockAMD";
}
template<> auto enumToString(GpaSampleTypeAMD enumVal) -> std::string_view {
	using enum GpaSampleTypeAMD;
	switch (enumVal) {
	case Cumulative: {
		return "Cumulative"sv;
	}
	case Trace: {
		return "Trace"sv;
	}
	case Timing: {
		return "Timing"sv;
	}
	}
	return "EnumElement not part of: GpaSampleTypeAMD";
}
template<> auto enumToString(ImageLayout enumVal) -> std::string_view {
	using enum ImageLayout;
	switch (enumVal) {
	case Undefined: {
		return "Undefined"sv;
	}
	case General: {
		return "General"sv;
	}
	case ColorAttachmentOptimal: {
		return "ColorAttachmentOptimal"sv;
	}
	case DepthStencilAttachmentOptimal: {
		return "DepthStencilAttachmentOptimal"sv;
	}
	case DepthStencilReadOnlyOptimal: {
		return "DepthStencilReadOnlyOptimal"sv;
	}
	case ShaderReadOnlyOptimal: {
		return "ShaderReadOnlyOptimal"sv;
	}
	case TransferSrcOptimal: {
		return "TransferSrcOptimal"sv;
	}
	case TransferDstOptimal: {
		return "TransferDstOptimal"sv;
	}
	case Preinitialized: {
		return "Preinitialized"sv;
	}
	case PresentSrcKHR: {
		return "PresentSrcKHR"sv;
	}
	case VideoDecodeDstKHR: {
		return "VideoDecodeDstKHR"sv;
	}
	case VideoDecodeSrcKHR: {
		return "VideoDecodeSrcKHR"sv;
	}
	case VideoDecodeDpbKHR: {
		return "VideoDecodeDpbKHR"sv;
	}
	case SharedPresentKHR: {
		return "SharedPresentKHR"sv;
	}
	case DepthReadOnlyStencilAttachmentOptimal: {
		return "DepthReadOnlyStencilAttachmentOptimal"sv;
	}
	case DepthAttachmentStencilReadOnlyOptimal: {
		return "DepthAttachmentStencilReadOnlyOptimal"sv;
	}
	case FragmentShadingRateAttachmentOptimalKHR: {
		return "FragmentShadingRateAttachmentOptimalKHR"sv;
	}
	case FragmentDensityMapOptimalEXT: {
		return "FragmentDensityMapOptimalEXT"sv;
	}
	case RenderingLocalRead: {
		return "RenderingLocalRead"sv;
	}
	case DepthAttachmentOptimal: {
		return "DepthAttachmentOptimal"sv;
	}
	case DepthReadOnlyOptimal: {
		return "DepthReadOnlyOptimal"sv;
	}
	case StencilAttachmentOptimal: {
		return "StencilAttachmentOptimal"sv;
	}
	case StencilReadOnlyOptimal: {
		return "StencilReadOnlyOptimal"sv;
	}
	case VideoEncodeDstKHR: {
		return "VideoEncodeDstKHR"sv;
	}
	case VideoEncodeSrcKHR: {
		return "VideoEncodeSrcKHR"sv;
	}
	case VideoEncodeDpbKHR: {
		return "VideoEncodeDpbKHR"sv;
	}
	case ReadOnlyOptimal: {
		return "ReadOnlyOptimal"sv;
	}
	case AttachmentOptimal: {
		return "AttachmentOptimal"sv;
	}
	case AttachmentFeedbackLoopOptimalEXT: {
		return "AttachmentFeedbackLoopOptimalEXT"sv;
	}
	case TensorAliasingARM: {
		return "TensorAliasingARM"sv;
	}
	case VideoEncodeQuantizationMapKHR: {
		return "VideoEncodeQuantizationMapKHR"sv;
	}
	case ZeroInitializedEXT: {
		return "ZeroInitializedEXT"sv;
	}
	}
	return "EnumElement not part of: ImageLayout";
}
template<> auto enumToString(ImageTiling enumVal) -> std::string_view {
	using enum ImageTiling;
	switch (enumVal) {
	case Optimal: {
		return "Optimal"sv;
	}
	case Linear: {
		return "Linear"sv;
	}
	case DrmFormatModifierEXT: {
		return "DrmFormatModifierEXT"sv;
	}
	}
	return "EnumElement not part of: ImageTiling";
}
template<> auto enumToString(ImageTilingControlEXT enumVal) -> std::string_view {
	using enum ImageTilingControlEXT;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case MinSize: {
		return "MinSize"sv;
	}
	case MaxPerformance: {
		return "MaxPerformance"sv;
	}
	}
	return "EnumElement not part of: ImageTilingControlEXT";
}
template<> auto enumToString(ImageType enumVal) -> std::string_view {
	using enum ImageType;
	switch (enumVal) {
	case v1D: {
		return "v1D"sv;
	}
	case v2D: {
		return "v2D"sv;
	}
	case v3D: {
		return "v3D"sv;
	}
	}
	return "EnumElement not part of: ImageType";
}
template<> auto enumToString(ImageViewType enumVal) -> std::string_view {
	using enum ImageViewType;
	switch (enumVal) {
	case v1D: {
		return "v1D"sv;
	}
	case v2D: {
		return "v2D"sv;
	}
	case v3D: {
		return "v3D"sv;
	}
	case Cube: {
		return "Cube"sv;
	}
	case v1DArray: {
		return "v1DArray"sv;
	}
	case v2DArray: {
		return "v2DArray"sv;
	}
	case CubeArray: {
		return "CubeArray"sv;
	}
	}
	return "EnumElement not part of: ImageViewType";
}
template<> auto enumToString(IndexType enumVal) -> std::string_view {
	using enum IndexType;
	switch (enumVal) {
	case Uint16: {
		return "Uint16"sv;
	}
	case Uint32: {
		return "Uint32"sv;
	}
	case NoneKHR: {
		return "NoneKHR"sv;
	}
	case Uint8: {
		return "Uint8"sv;
	}
	}
	return "EnumElement not part of: IndexType";
}
template<> auto enumToString(IndirectCommandsTokenTypeEXT enumVal) -> std::string_view {
	using enum IndirectCommandsTokenTypeEXT;
	switch (enumVal) {
	case ExecutionSet: {
		return "ExecutionSet"sv;
	}
	case PushConstant: {
		return "PushConstant"sv;
	}
	case SequenceIndex: {
		return "SequenceIndex"sv;
	}
	case IndexBuffer: {
		return "IndexBuffer"sv;
	}
	case VertexBuffer: {
		return "VertexBuffer"sv;
	}
	case DrawIndexed: {
		return "DrawIndexed"sv;
	}
	case Draw: {
		return "Draw"sv;
	}
	case DrawIndexedCount: {
		return "DrawIndexedCount"sv;
	}
	case DrawCount: {
		return "DrawCount"sv;
	}
	case Dispatch: {
		return "Dispatch"sv;
	}
	case PushData: {
		return "PushData"sv;
	}
	case PushDataSequenceIndex: {
		return "PushDataSequenceIndex"sv;
	}
	case DrawMeshTasksNV: {
		return "DrawMeshTasksNV"sv;
	}
	case DrawMeshTasksCountNV: {
		return "DrawMeshTasksCountNV"sv;
	}
	case DrawMeshTasks: {
		return "DrawMeshTasks"sv;
	}
	case DrawMeshTasksCount: {
		return "DrawMeshTasksCount"sv;
	}
	case TraceRays2: {
		return "TraceRays2"sv;
	}
	}
	return "EnumElement not part of: IndirectCommandsTokenTypeEXT";
}
template<> auto enumToString(IndirectCommandsTokenTypeNV enumVal) -> std::string_view {
	using enum IndirectCommandsTokenTypeNV;
	switch (enumVal) {
	case ShaderGroup: {
		return "ShaderGroup"sv;
	}
	case StateFlags: {
		return "StateFlags"sv;
	}
	case IndexBuffer: {
		return "IndexBuffer"sv;
	}
	case VertexBuffer: {
		return "VertexBuffer"sv;
	}
	case PushConstant: {
		return "PushConstant"sv;
	}
	case DrawIndexed: {
		return "DrawIndexed"sv;
	}
	case Draw: {
		return "Draw"sv;
	}
	case DrawTasks: {
		return "DrawTasks"sv;
	}
	case PushData: {
		return "PushData"sv;
	}
	case DrawMeshTasks: {
		return "DrawMeshTasks"sv;
	}
	case Pipeline: {
		return "Pipeline"sv;
	}
	case Dispatch: {
		return "Dispatch"sv;
	}
	}
	return "EnumElement not part of: IndirectCommandsTokenTypeNV";
}
template<> auto enumToString(IndirectExecutionSetInfoTypeEXT enumVal) -> std::string_view {
	using enum IndirectExecutionSetInfoTypeEXT;
	switch (enumVal) {
	case Pipelines: {
		return "Pipelines"sv;
	}
	case ShaderObjects: {
		return "ShaderObjects"sv;
	}
	}
	return "EnumElement not part of: IndirectExecutionSetInfoTypeEXT";
}
template<> auto enumToString(InternalAllocationType enumVal) -> std::string_view {
	using enum InternalAllocationType;
	switch (enumVal) {
	case Executable: {
		return "Executable"sv;
	}
	}
	return "EnumElement not part of: InternalAllocationType";
}
template<> auto enumToString(LatencyMarkerNV enumVal) -> std::string_view {
	using enum LatencyMarkerNV;
	switch (enumVal) {
	case SimulationStart: {
		return "SimulationStart"sv;
	}
	case SimulationEnd: {
		return "SimulationEnd"sv;
	}
	case RendersubmitStart: {
		return "RendersubmitStart"sv;
	}
	case RendersubmitEnd: {
		return "RendersubmitEnd"sv;
	}
	case PresentStart: {
		return "PresentStart"sv;
	}
	case PresentEnd: {
		return "PresentEnd"sv;
	}
	case InputSample: {
		return "InputSample"sv;
	}
	case TriggerFlash: {
		return "TriggerFlash"sv;
	}
	case OutOfBandRendersubmitStart: {
		return "OutOfBandRendersubmitStart"sv;
	}
	case OutOfBandRendersubmitEnd: {
		return "OutOfBandRendersubmitEnd"sv;
	}
	case OutOfBandPresentStart: {
		return "OutOfBandPresentStart"sv;
	}
	case OutOfBandPresentEnd: {
		return "OutOfBandPresentEnd"sv;
	}
	}
	return "EnumElement not part of: LatencyMarkerNV";
}
template<> auto enumToString(LayerSettingTypeEXT enumVal) -> std::string_view {
	using enum LayerSettingTypeEXT;
	switch (enumVal) {
	case Bool32: {
		return "Bool32"sv;
	}
	case Int32: {
		return "Int32"sv;
	}
	case Int64: {
		return "Int64"sv;
	}
	case Uint32: {
		return "Uint32"sv;
	}
	case Uint64: {
		return "Uint64"sv;
	}
	case Float32: {
		return "Float32"sv;
	}
	case Float64: {
		return "Float64"sv;
	}
	case String: {
		return "String"sv;
	}
	}
	return "EnumElement not part of: LayerSettingTypeEXT";
}
template<> auto enumToString(LayeredDriverUnderlyingApiMSFT enumVal) -> std::string_view {
	using enum LayeredDriverUnderlyingApiMSFT;
	switch (enumVal) {
	case None: {
		return "None"sv;
	}
	case D3D12: {
		return "D3D12"sv;
	}
	}
	return "EnumElement not part of: LayeredDriverUnderlyingApiMSFT";
}
template<> auto enumToString(LineRasterizationMode enumVal) -> std::string_view {
	using enum LineRasterizationMode;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case Rectangular: {
		return "Rectangular"sv;
	}
	case Bresenham: {
		return "Bresenham"sv;
	}
	case RectangularSmooth: {
		return "RectangularSmooth"sv;
	}
	}
	return "EnumElement not part of: LineRasterizationMode";
}
template<> auto enumToString(LogicOp enumVal) -> std::string_view {
	using enum LogicOp;
	switch (enumVal) {
	case Clear: {
		return "Clear"sv;
	}
	case And: {
		return "And"sv;
	}
	case AndReverse: {
		return "AndReverse"sv;
	}
	case Copy: {
		return "Copy"sv;
	}
	case AndInverted: {
		return "AndInverted"sv;
	}
	case NoOp: {
		return "NoOp"sv;
	}
	case Xor: {
		return "Xor"sv;
	}
	case Or: {
		return "Or"sv;
	}
	case Nor: {
		return "Nor"sv;
	}
	case Equivalent: {
		return "Equivalent"sv;
	}
	case Invert: {
		return "Invert"sv;
	}
	case OrReverse: {
		return "OrReverse"sv;
	}
	case CopyInverted: {
		return "CopyInverted"sv;
	}
	case OrInverted: {
		return "OrInverted"sv;
	}
	case Nand: {
		return "Nand"sv;
	}
	case Set: {
		return "Set"sv;
	}
	}
	return "EnumElement not part of: LogicOp";
}
template<> auto enumToString(MemoryOverallocationBehaviorAMD enumVal) -> std::string_view {
	using enum MemoryOverallocationBehaviorAMD;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case Allowed: {
		return "Allowed"sv;
	}
	case Disallowed: {
		return "Disallowed"sv;
	}
	}
	return "EnumElement not part of: MemoryOverallocationBehaviorAMD";
}
template<> auto enumToString(MicromapTypeEXT enumVal) -> std::string_view {
	using enum MicromapTypeEXT;
	switch (enumVal) {
	case OpacityMicromap: {
		return "OpacityMicromap"sv;
	}
	case DisplacementMicromapNV: {
		return "DisplacementMicromapNV"sv;
	}
	}
	return "EnumElement not part of: MicromapTypeEXT";
}
template<> auto enumToString(NeuralAcceleratorStatisticsModeARM enumVal) -> std::string_view {
	using enum NeuralAcceleratorStatisticsModeARM;
	switch (enumVal) {
	case Disabled: {
		return "Disabled"sv;
	}
	case Statistics0: {
		return "Statistics0"sv;
	}
	case Statistics1: {
		return "Statistics1"sv;
	}
	}
	return "EnumElement not part of: NeuralAcceleratorStatisticsModeARM";
}
template<> auto enumToString(ObjectType enumVal) -> std::string_view {
	using enum ObjectType;
	switch (enumVal) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Instance: {
		return "Instance"sv;
	}
	case PhysicalDevice: {
		return "PhysicalDevice"sv;
	}
	case Device: {
		return "Device"sv;
	}
	case Queue: {
		return "Queue"sv;
	}
	case Semaphore: {
		return "Semaphore"sv;
	}
	case CommandBuffer: {
		return "CommandBuffer"sv;
	}
	case Fence: {
		return "Fence"sv;
	}
	case DeviceMemory: {
		return "DeviceMemory"sv;
	}
	case Buffer: {
		return "Buffer"sv;
	}
	case Image: {
		return "Image"sv;
	}
	case Event: {
		return "Event"sv;
	}
	case QueryPool: {
		return "QueryPool"sv;
	}
	case BufferView: {
		return "BufferView"sv;
	}
	case ImageView: {
		return "ImageView"sv;
	}
	case ShaderModule: {
		return "ShaderModule"sv;
	}
	case PipelineCache: {
		return "PipelineCache"sv;
	}
	case PipelineLayout: {
		return "PipelineLayout"sv;
	}
	case RenderPass: {
		return "RenderPass"sv;
	}
	case Pipeline: {
		return "Pipeline"sv;
	}
	case DescriptorSetLayout: {
		return "DescriptorSetLayout"sv;
	}
	case Sampler: {
		return "Sampler"sv;
	}
	case DescriptorPool: {
		return "DescriptorPool"sv;
	}
	case DescriptorSet: {
		return "DescriptorSet"sv;
	}
	case Framebuffer: {
		return "Framebuffer"sv;
	}
	case CommandPool: {
		return "CommandPool"sv;
	}
	case SurfaceKHR: {
		return "SurfaceKHR"sv;
	}
	case SwapchainKHR: {
		return "SwapchainKHR"sv;
	}
	case DisplayKHR: {
		return "DisplayKHR"sv;
	}
	case DisplayModeKHR: {
		return "DisplayModeKHR"sv;
	}
	case DebugReportCallbackEXT: {
		return "DebugReportCallbackEXT"sv;
	}
	case VideoSessionKHR: {
		return "VideoSessionKHR"sv;
	}
	case VideoSessionParametersKHR: {
		return "VideoSessionParametersKHR"sv;
	}
	case CuModuleNVX: {
		return "CuModuleNVX"sv;
	}
	case CuFunctionNVX: {
		return "CuFunctionNVX"sv;
	}
	case DescriptorUpdateTemplate: {
		return "DescriptorUpdateTemplate"sv;
	}
	case DebugUtilsMessengerEXT: {
		return "DebugUtilsMessengerEXT"sv;
	}
	case GpaSessionAMD: {
		return "GpaSessionAMD"sv;
	}
	case AccelerationStructureKHR: {
		return "AccelerationStructureKHR"sv;
	}
	case SamplerYcbcrConversion: {
		return "SamplerYcbcrConversion"sv;
	}
	case ValidationCacheEXT: {
		return "ValidationCacheEXT"sv;
	}
	case AccelerationStructureNV: {
		return "AccelerationStructureNV"sv;
	}
	case PerformanceConfigurationINTEL: {
		return "PerformanceConfigurationINTEL"sv;
	}
	case DeferredOperationKHR: {
		return "DeferredOperationKHR"sv;
	}
	case IndirectCommandsLayoutNV: {
		return "IndirectCommandsLayoutNV"sv;
	}
	case PrivateDataSlot: {
		return "PrivateDataSlot"sv;
	}
	case CudaModuleNV: {
		return "CudaModuleNV"sv;
	}
	case CudaFunctionNV: {
		return "CudaFunctionNV"sv;
	}
	case BufferCollectionFUCHSIA: {
		return "BufferCollectionFUCHSIA"sv;
	}
	case MicromapEXT: {
		return "MicromapEXT"sv;
	}
	case TensorARM: {
		return "TensorARM"sv;
	}
	case TensorViewARM: {
		return "TensorViewARM"sv;
	}
	case OpticalFlowSessionNV: {
		return "OpticalFlowSessionNV"sv;
	}
	case ShaderEXT: {
		return "ShaderEXT"sv;
	}
	case PipelineBinaryKHR: {
		return "PipelineBinaryKHR"sv;
	}
	case DataGraphPipelineSessionARM: {
		return "DataGraphPipelineSessionARM"sv;
	}
	case ExternalComputeQueueNV: {
		return "ExternalComputeQueueNV"sv;
	}
	case IndirectCommandsLayoutEXT: {
		return "IndirectCommandsLayoutEXT"sv;
	}
	case IndirectExecutionSetEXT: {
		return "IndirectExecutionSetEXT"sv;
	}
	case ShaderInstrumentationARM: {
		return "ShaderInstrumentationARM"sv;
	}
	}
	return "EnumElement not part of: ObjectType";
}
template<> auto enumToString(OpacityMicromapFormatKHR enumVal) -> std::string_view {
	using enum OpacityMicromapFormatKHR;
	switch (enumVal) {
	case v2State: {
		return "v2State"sv;
	}
	case v4State: {
		return "v4State"sv;
	}
	}
	return "EnumElement not part of: OpacityMicromapFormatKHR";
}
template<> auto enumToString(OpacityMicromapSpecialIndexKHR enumVal) -> std::string_view {
	using enum OpacityMicromapSpecialIndexKHR;
	switch (enumVal) {
	case FullyTransparent: {
		return "FullyTransparent"sv;
	}
	case FullyOpaque: {
		return "FullyOpaque"sv;
	}
	case FullyUnknownTransparent: {
		return "FullyUnknownTransparent"sv;
	}
	case FullyUnknownOpaque: {
		return "FullyUnknownOpaque"sv;
	}
	case ClusterGeometryDisableOpacityMicromapNV: {
		return "ClusterGeometryDisableOpacityMicromapNV"sv;
	}
	}
	return "EnumElement not part of: OpacityMicromapSpecialIndexKHR";
}
template<> auto enumToString(OpticalFlowPerformanceLevelNV enumVal) -> std::string_view {
	using enum OpticalFlowPerformanceLevelNV;
	switch (enumVal) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Slow: {
		return "Slow"sv;
	}
	case Medium: {
		return "Medium"sv;
	}
	case Fast: {
		return "Fast"sv;
	}
	}
	return "EnumElement not part of: OpticalFlowPerformanceLevelNV";
}
template<> auto enumToString(OpticalFlowSessionBindingPointNV enumVal) -> std::string_view {
	using enum OpticalFlowSessionBindingPointNV;
	switch (enumVal) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Input: {
		return "Input"sv;
	}
	case Reference: {
		return "Reference"sv;
	}
	case Hint: {
		return "Hint"sv;
	}
	case FlowVector: {
		return "FlowVector"sv;
	}
	case BackwardFlowVector: {
		return "BackwardFlowVector"sv;
	}
	case Cost: {
		return "Cost"sv;
	}
	case BackwardCost: {
		return "BackwardCost"sv;
	}
	case GlobalFlow: {
		return "GlobalFlow"sv;
	}
	}
	return "EnumElement not part of: OpticalFlowSessionBindingPointNV";
}
template<> auto enumToString(OutOfBandQueueTypeNV enumVal) -> std::string_view {
	using enum OutOfBandQueueTypeNV;
	switch (enumVal) {
	case Render: {
		return "Render"sv;
	}
	case Present: {
		return "Present"sv;
	}
	}
	return "EnumElement not part of: OutOfBandQueueTypeNV";
}
template<> auto enumToString(PartitionedAccelerationStructureOpTypeNV enumVal) -> std::string_view {
	using enum PartitionedAccelerationStructureOpTypeNV;
	switch (enumVal) {
	case WriteInstance: {
		return "WriteInstance"sv;
	}
	case UpdateInstance: {
		return "UpdateInstance"sv;
	}
	case WritePartitionTranslation: {
		return "WritePartitionTranslation"sv;
	}
	}
	return "EnumElement not part of: PartitionedAccelerationStructureOpTypeNV";
}
template<> auto enumToString(PerfHintTypeQCOM enumVal) -> std::string_view {
	using enum PerfHintTypeQCOM;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case FrequencyMin: {
		return "FrequencyMin"sv;
	}
	case FrequencyMax: {
		return "FrequencyMax"sv;
	}
	case FrequencyScaled: {
		return "FrequencyScaled"sv;
	}
	}
	return "EnumElement not part of: PerfHintTypeQCOM";
}
template<> auto enumToString(PerformanceConfigurationTypeINTEL enumVal) -> std::string_view {
	using enum PerformanceConfigurationTypeINTEL;
	switch (enumVal) {
	case CommandQueueMetricsDiscoveryActivated: {
		return "CommandQueueMetricsDiscoveryActivated"sv;
	}
	}
	return "EnumElement not part of: PerformanceConfigurationTypeINTEL";
}
template<> auto enumToString(PerformanceCounterScopeKHR enumVal) -> std::string_view {
	using enum PerformanceCounterScopeKHR;
	switch (enumVal) {
	case CommandBuffer: {
		return "CommandBuffer"sv;
	}
	case RenderPass: {
		return "RenderPass"sv;
	}
	case Command: {
		return "Command"sv;
	}
	}
	return "EnumElement not part of: PerformanceCounterScopeKHR";
}
template<> auto enumToString(PerformanceCounterStorageKHR enumVal) -> std::string_view {
	using enum PerformanceCounterStorageKHR;
	switch (enumVal) {
	case Int32: {
		return "Int32"sv;
	}
	case Int64: {
		return "Int64"sv;
	}
	case Uint32: {
		return "Uint32"sv;
	}
	case Uint64: {
		return "Uint64"sv;
	}
	case Float32: {
		return "Float32"sv;
	}
	case Float64: {
		return "Float64"sv;
	}
	}
	return "EnumElement not part of: PerformanceCounterStorageKHR";
}
template<> auto enumToString(PerformanceCounterUnitKHR enumVal) -> std::string_view {
	using enum PerformanceCounterUnitKHR;
	switch (enumVal) {
	case Generic: {
		return "Generic"sv;
	}
	case Percentage: {
		return "Percentage"sv;
	}
	case Nanoseconds: {
		return "Nanoseconds"sv;
	}
	case Bytes: {
		return "Bytes"sv;
	}
	case BytesPerSecond: {
		return "BytesPerSecond"sv;
	}
	case Kelvin: {
		return "Kelvin"sv;
	}
	case Watts: {
		return "Watts"sv;
	}
	case Volts: {
		return "Volts"sv;
	}
	case Amps: {
		return "Amps"sv;
	}
	case Hertz: {
		return "Hertz"sv;
	}
	case Cycles: {
		return "Cycles"sv;
	}
	}
	return "EnumElement not part of: PerformanceCounterUnitKHR";
}
template<> auto enumToString(PerformanceOverrideTypeINTEL enumVal) -> std::string_view {
	using enum PerformanceOverrideTypeINTEL;
	switch (enumVal) {
	case NullHardware: {
		return "NullHardware"sv;
	}
	case FlushGpuCaches: {
		return "FlushGpuCaches"sv;
	}
	}
	return "EnumElement not part of: PerformanceOverrideTypeINTEL";
}
template<> auto enumToString(PerformanceParameterTypeINTEL enumVal) -> std::string_view {
	using enum PerformanceParameterTypeINTEL;
	switch (enumVal) {
	case HwCountersSupported: {
		return "HwCountersSupported"sv;
	}
	case StreamMarkerValidBits: {
		return "StreamMarkerValidBits"sv;
	}
	}
	return "EnumElement not part of: PerformanceParameterTypeINTEL";
}
template<> auto enumToString(PerformanceValueTypeINTEL enumVal) -> std::string_view {
	using enum PerformanceValueTypeINTEL;
	switch (enumVal) {
	case Uint32: {
		return "Uint32"sv;
	}
	case Uint64: {
		return "Uint64"sv;
	}
	case Float: {
		return "Float"sv;
	}
	case Bool: {
		return "Bool"sv;
	}
	case String: {
		return "String"sv;
	}
	}
	return "EnumElement not part of: PerformanceValueTypeINTEL";
}
template<> auto enumToString(PhysicalDeviceDataGraphOperationTypeARM enumVal) -> std::string_view {
	using enum PhysicalDeviceDataGraphOperationTypeARM;
	switch (enumVal) {
	case SpirvExtendedInstructionSet: {
		return "SpirvExtendedInstructionSet"sv;
	}
	case NeuralModelQCOM: {
		return "NeuralModelQCOM"sv;
	}
	case BuiltinModelQCOM: {
		return "BuiltinModelQCOM"sv;
	}
	case OpticalFlow: {
		return "OpticalFlow"sv;
	}
	}
	return "EnumElement not part of: PhysicalDeviceDataGraphOperationTypeARM";
}
template<> auto enumToString(PhysicalDeviceDataGraphProcessingEngineTypeARM enumVal) -> std::string_view {
	using enum PhysicalDeviceDataGraphProcessingEngineTypeARM;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case NeuralQCOM: {
		return "NeuralQCOM"sv;
	}
	case ComputeQCOM: {
		return "ComputeQCOM"sv;
	}
	}
	return "EnumElement not part of: PhysicalDeviceDataGraphProcessingEngineTypeARM";
}
template<> auto enumToString(PhysicalDeviceLayeredApiKHR enumVal) -> std::string_view {
	using enum PhysicalDeviceLayeredApiKHR;
	switch (enumVal) {
	case Vulkan: {
		return "Vulkan"sv;
	}
	case D3D12: {
		return "D3D12"sv;
	}
	case Metal: {
		return "Metal"sv;
	}
	case Opengl: {
		return "Opengl"sv;
	}
	case Opengles: {
		return "Opengles"sv;
	}
	}
	return "EnumElement not part of: PhysicalDeviceLayeredApiKHR";
}
template<> auto enumToString(PhysicalDeviceType enumVal) -> std::string_view {
	using enum PhysicalDeviceType;
	switch (enumVal) {
	case Other: {
		return "Other"sv;
	}
	case IntegratedGpu: {
		return "IntegratedGpu"sv;
	}
	case DiscreteGpu: {
		return "DiscreteGpu"sv;
	}
	case VirtualGpu: {
		return "VirtualGpu"sv;
	}
	case Cpu: {
		return "Cpu"sv;
	}
	}
	return "EnumElement not part of: PhysicalDeviceType";
}
template<> auto enumToString(PipelineBindPoint enumVal) -> std::string_view {
	using enum PipelineBindPoint;
	switch (enumVal) {
	case Graphics: {
		return "Graphics"sv;
	}
	case Compute: {
		return "Compute"sv;
	}
	case ExecutionGraphAMDX: {
		return "ExecutionGraphAMDX"sv;
	}
	case RayTracingKHR: {
		return "RayTracingKHR"sv;
	}
	case SubpassShadingHUAWEI: {
		return "SubpassShadingHUAWEI"sv;
	}
	case DataGraphARM: {
		return "DataGraphARM"sv;
	}
	}
	return "EnumElement not part of: PipelineBindPoint";
}
template<> auto enumToString(PipelineCacheHeaderVersion enumVal) -> std::string_view {
	using enum PipelineCacheHeaderVersion;
	switch (enumVal) {
	case One: {
		return "One"sv;
	}
	case DataGraphQCOM: {
		return "DataGraphQCOM"sv;
	}
	}
	return "EnumElement not part of: PipelineCacheHeaderVersion";
}
template<> auto enumToString(PipelineExecutableStatisticFormatKHR enumVal) -> std::string_view {
	using enum PipelineExecutableStatisticFormatKHR;
	switch (enumVal) {
	case Bool32: {
		return "Bool32"sv;
	}
	case Int64: {
		return "Int64"sv;
	}
	case Uint64: {
		return "Uint64"sv;
	}
	case Float64: {
		return "Float64"sv;
	}
	}
	return "EnumElement not part of: PipelineExecutableStatisticFormatKHR";
}
template<> auto enumToString(PipelineRobustnessBufferBehavior enumVal) -> std::string_view {
	using enum PipelineRobustnessBufferBehavior;
	switch (enumVal) {
	case DeviceDefault: {
		return "DeviceDefault"sv;
	}
	case Disabled: {
		return "Disabled"sv;
	}
	case RobustBufferAccess: {
		return "RobustBufferAccess"sv;
	}
	case RobustBufferAccess2: {
		return "RobustBufferAccess2"sv;
	}
	}
	return "EnumElement not part of: PipelineRobustnessBufferBehavior";
}
template<> auto enumToString(PipelineRobustnessImageBehavior enumVal) -> std::string_view {
	using enum PipelineRobustnessImageBehavior;
	switch (enumVal) {
	case DeviceDefault: {
		return "DeviceDefault"sv;
	}
	case Disabled: {
		return "Disabled"sv;
	}
	case RobustImageAccess: {
		return "RobustImageAccess"sv;
	}
	case RobustImageAccess2: {
		return "RobustImageAccess2"sv;
	}
	}
	return "EnumElement not part of: PipelineRobustnessImageBehavior";
}
template<> auto enumToString(PointClippingBehavior enumVal) -> std::string_view {
	using enum PointClippingBehavior;
	switch (enumVal) {
	case AllClipPlanes: {
		return "AllClipPlanes"sv;
	}
	case UserClipPlanesOnly: {
		return "UserClipPlanesOnly"sv;
	}
	}
	return "EnumElement not part of: PointClippingBehavior";
}
template<> auto enumToString(PolygonMode enumVal) -> std::string_view {
	using enum PolygonMode;
	switch (enumVal) {
	case Fill: {
		return "Fill"sv;
	}
	case Line: {
		return "Line"sv;
	}
	case Point: {
		return "Point"sv;
	}
	case FillRectangleNV: {
		return "FillRectangleNV"sv;
	}
	}
	return "EnumElement not part of: PolygonMode";
}
template<> auto enumToString(PresentModeKHR enumVal) -> std::string_view {
	using enum PresentModeKHR;
	switch (enumVal) {
	case Immediate: {
		return "Immediate"sv;
	}
	case Mailbox: {
		return "Mailbox"sv;
	}
	case Fifo: {
		return "Fifo"sv;
	}
	case FifoRelaxed: {
		return "FifoRelaxed"sv;
	}
	case SharedDemandRefresh: {
		return "SharedDemandRefresh"sv;
	}
	case SharedContinuousRefresh: {
		return "SharedContinuousRefresh"sv;
	}
	case FifoLatestReady: {
		return "FifoLatestReady"sv;
	}
	}
	return "EnumElement not part of: PresentModeKHR";
}
template<> auto enumToString(PrimitiveTopology enumVal) -> std::string_view {
	using enum PrimitiveTopology;
	switch (enumVal) {
	case PointList: {
		return "PointList"sv;
	}
	case LineList: {
		return "LineList"sv;
	}
	case LineStrip: {
		return "LineStrip"sv;
	}
	case TriangleList: {
		return "TriangleList"sv;
	}
	case TriangleStrip: {
		return "TriangleStrip"sv;
	}
	case TriangleFan: {
		return "TriangleFan"sv;
	}
	case LineListWithAdjacency: {
		return "LineListWithAdjacency"sv;
	}
	case LineStripWithAdjacency: {
		return "LineStripWithAdjacency"sv;
	}
	case TriangleListWithAdjacency: {
		return "TriangleListWithAdjacency"sv;
	}
	case TriangleStripWithAdjacency: {
		return "TriangleStripWithAdjacency"sv;
	}
	case PatchList: {
		return "PatchList"sv;
	}
	}
	return "EnumElement not part of: PrimitiveTopology";
}
template<> auto enumToString(ProvokingVertexModeEXT enumVal) -> std::string_view {
	using enum ProvokingVertexModeEXT;
	switch (enumVal) {
	case FirstVertex: {
		return "FirstVertex"sv;
	}
	case LastVertex: {
		return "LastVertex"sv;
	}
	}
	return "EnumElement not part of: ProvokingVertexModeEXT";
}
template<> auto enumToString(QueryPoolSamplingModeINTEL enumVal) -> std::string_view {
	using enum QueryPoolSamplingModeINTEL;
	switch (enumVal) {
	case Manual: {
		return "Manual"sv;
	}
	}
	return "EnumElement not part of: QueryPoolSamplingModeINTEL";
}
template<> auto enumToString(QueryResultStatusKHR enumVal) -> std::string_view {
	using enum QueryResultStatusKHR;
	switch (enumVal) {
	case NotReady: {
		return "NotReady"sv;
	}
	case Complete: {
		return "Complete"sv;
	}
	case Error: {
		return "Error"sv;
	}
	case InsufficientBitstreamBufferRange: {
		return "InsufficientBitstreamBufferRange"sv;
	}
	}
	return "EnumElement not part of: QueryResultStatusKHR";
}
template<> auto enumToString(QueryType enumVal) -> std::string_view {
	using enum QueryType;
	switch (enumVal) {
	case Occlusion: {
		return "Occlusion"sv;
	}
	case PipelineStatistics: {
		return "PipelineStatistics"sv;
	}
	case Timestamp: {
		return "Timestamp"sv;
	}
	case ResultStatusOnlyKHR: {
		return "ResultStatusOnlyKHR"sv;
	}
	case TransformFeedbackStreamEXT: {
		return "TransformFeedbackStreamEXT"sv;
	}
	case PerformanceQueryKHR: {
		return "PerformanceQueryKHR"sv;
	}
	case AccelerationStructureCompactedSizeKHR: {
		return "AccelerationStructureCompactedSizeKHR"sv;
	}
	case AccelerationStructureSerializationSizeKHR: {
		return "AccelerationStructureSerializationSizeKHR"sv;
	}
	case AccelerationStructureCompactedSizeNV: {
		return "AccelerationStructureCompactedSizeNV"sv;
	}
	case TimeElapsedQCOM: {
		return "TimeElapsedQCOM"sv;
	}
	case PerformanceQueryINTEL: {
		return "PerformanceQueryINTEL"sv;
	}
	case VideoEncodeFeedbackKHR: {
		return "VideoEncodeFeedbackKHR"sv;
	}
	case MeshPrimitivesGeneratedEXT: {
		return "MeshPrimitivesGeneratedEXT"sv;
	}
	case PrimitivesGeneratedEXT: {
		return "PrimitivesGeneratedEXT"sv;
	}
	case AccelerationStructureSerializationBottomLevelPointersKHR: {
		return "AccelerationStructureSerializationBottomLevelPointersKHR"sv;
	}
	case AccelerationStructureSizeKHR: {
		return "AccelerationStructureSizeKHR"sv;
	}
	case MicromapSerializationSizeEXT: {
		return "MicromapSerializationSizeEXT"sv;
	}
	case MicromapCompactedSizeEXT: {
		return "MicromapCompactedSizeEXT"sv;
	}
	}
	return "EnumElement not part of: QueryType";
}
template<> auto enumToString(QueueGlobalPriority enumVal) -> std::string_view {
	using enum QueueGlobalPriority;
	switch (enumVal) {
	case Low: {
		return "Low"sv;
	}
	case Medium: {
		return "Medium"sv;
	}
	case High: {
		return "High"sv;
	}
	case Realtime: {
		return "Realtime"sv;
	}
	}
	return "EnumElement not part of: QueueGlobalPriority";
}
template<> auto enumToString(RasterizationOrderAMD enumVal) -> std::string_view {
	using enum RasterizationOrderAMD;
	switch (enumVal) {
	case Strict: {
		return "Strict"sv;
	}
	case Relaxed: {
		return "Relaxed"sv;
	}
	}
	return "EnumElement not part of: RasterizationOrderAMD";
}
template<> auto enumToString(RayTracingInvocationReorderModeEXT enumVal) -> std::string_view {
	using enum RayTracingInvocationReorderModeEXT;
	switch (enumVal) {
	case None: {
		return "None"sv;
	}
	case Reorder: {
		return "Reorder"sv;
	}
	}
	return "EnumElement not part of: RayTracingInvocationReorderModeEXT";
}
template<> auto enumToString(RayTracingLssIndexingModeNV enumVal) -> std::string_view {
	using enum RayTracingLssIndexingModeNV;
	switch (enumVal) {
	case List: {
		return "List"sv;
	}
	case Successive: {
		return "Successive"sv;
	}
	}
	return "EnumElement not part of: RayTracingLssIndexingModeNV";
}
template<> auto enumToString(RayTracingLssPrimitiveEndCapsModeNV enumVal) -> std::string_view {
	using enum RayTracingLssPrimitiveEndCapsModeNV;
	switch (enumVal) {
	case None: {
		return "None"sv;
	}
	case Chained: {
		return "Chained"sv;
	}
	}
	return "EnumElement not part of: RayTracingLssPrimitiveEndCapsModeNV";
}
template<> auto enumToString(RayTracingShaderGroupTypeKHR enumVal) -> std::string_view {
	using enum RayTracingShaderGroupTypeKHR;
	switch (enumVal) {
	case General: {
		return "General"sv;
	}
	case TrianglesHitGroup: {
		return "TrianglesHitGroup"sv;
	}
	case ProceduralHitGroup: {
		return "ProceduralHitGroup"sv;
	}
	}
	return "EnumElement not part of: RayTracingShaderGroupTypeKHR";
}
template<> auto enumToString(Result enumVal) -> std::string_view {
	using enum Result;
	switch (enumVal) {
	case Success: {
		return "Success"sv;
	}
	case NotReady: {
		return "NotReady"sv;
	}
	case Timeout: {
		return "Timeout"sv;
	}
	case EventSet: {
		return "EventSet"sv;
	}
	case EventReset: {
		return "EventReset"sv;
	}
	case Incomplete: {
		return "Incomplete"sv;
	}
	case ErrorOutOfHostMemory: {
		return "ErrorOutOfHostMemory"sv;
	}
	case ErrorOutOfDeviceMemory: {
		return "ErrorOutOfDeviceMemory"sv;
	}
	case ErrorInitializationFailed: {
		return "ErrorInitializationFailed"sv;
	}
	case ErrorDeviceLost: {
		return "ErrorDeviceLost"sv;
	}
	case ErrorMemoryMapFailed: {
		return "ErrorMemoryMapFailed"sv;
	}
	case ErrorLayerNotPresent: {
		return "ErrorLayerNotPresent"sv;
	}
	case ErrorExtensionNotPresent: {
		return "ErrorExtensionNotPresent"sv;
	}
	case ErrorFeatureNotPresent: {
		return "ErrorFeatureNotPresent"sv;
	}
	case ErrorIncompatibleDriver: {
		return "ErrorIncompatibleDriver"sv;
	}
	case ErrorTooManyObjects: {
		return "ErrorTooManyObjects"sv;
	}
	case ErrorFormatNotSupported: {
		return "ErrorFormatNotSupported"sv;
	}
	case ErrorFragmentedPool: {
		return "ErrorFragmentedPool"sv;
	}
	case ErrorUnknown: {
		return "ErrorUnknown"sv;
	}
	case ErrorSurfaceLostKHR: {
		return "ErrorSurfaceLostKHR"sv;
	}
	case ErrorNativeWindowInUseKHR: {
		return "ErrorNativeWindowInUseKHR"sv;
	}
	case ErrorOutOfDateKHR: {
		return "ErrorOutOfDateKHR"sv;
	}
	case ErrorIncompatibleDisplayKHR: {
		return "ErrorIncompatibleDisplayKHR"sv;
	}
	case ErrorValidationFailed: {
		return "ErrorValidationFailed"sv;
	}
	case ErrorInvalidShaderNV: {
		return "ErrorInvalidShaderNV"sv;
	}
	case ErrorImageUsageNotSupportedKHR: {
		return "ErrorImageUsageNotSupportedKHR"sv;
	}
	case ErrorVideoPictureLayoutNotSupportedKHR: {
		return "ErrorVideoPictureLayoutNotSupportedKHR"sv;
	}
	case ErrorVideoProfileOperationNotSupportedKHR: {
		return "ErrorVideoProfileOperationNotSupportedKHR"sv;
	}
	case ErrorVideoProfileFormatNotSupportedKHR: {
		return "ErrorVideoProfileFormatNotSupportedKHR"sv;
	}
	case ErrorVideoProfileCodecNotSupportedKHR: {
		return "ErrorVideoProfileCodecNotSupportedKHR"sv;
	}
	case ErrorVideoStdVersionNotSupportedKHR: {
		return "ErrorVideoStdVersionNotSupportedKHR"sv;
	}
	case ErrorOutOfPoolMemory: {
		return "ErrorOutOfPoolMemory"sv;
	}
	case ErrorInvalidExternalHandle: {
		return "ErrorInvalidExternalHandle"sv;
	}
	case ErrorInvalidDrmFormatModifierPlaneLayoutEXT: {
		return "ErrorInvalidDrmFormatModifierPlaneLayoutEXT"sv;
	}
	case ErrorFragmentation: {
		return "ErrorFragmentation"sv;
	}
	case ErrorNotPermitted: {
		return "ErrorNotPermitted"sv;
	}
	case ErrorPresentTimingQueueFullEXT: {
		return "ErrorPresentTimingQueueFullEXT"sv;
	}
	case ErrorFullScreenExclusiveModeLostEXT: {
		return "ErrorFullScreenExclusiveModeLostEXT"sv;
	}
	case ErrorInvalidOpaqueCaptureAddress: {
		return "ErrorInvalidOpaqueCaptureAddress"sv;
	}
	case ErrorInvalidVideoStdParametersKHR: {
		return "ErrorInvalidVideoStdParametersKHR"sv;
	}
	case ErrorCompressionExhaustedEXT: {
		return "ErrorCompressionExhaustedEXT"sv;
	}
	case ErrorNotEnoughSpaceKHR: {
		return "ErrorNotEnoughSpaceKHR"sv;
	}
	case SuboptimalKHR: {
		return "SuboptimalKHR"sv;
	}
	case ThreadIdleKHR: {
		return "ThreadIdleKHR"sv;
	}
	case ThreadDoneKHR: {
		return "ThreadDoneKHR"sv;
	}
	case OperationDeferredKHR: {
		return "OperationDeferredKHR"sv;
	}
	case OperationNotDeferredKHR: {
		return "OperationNotDeferredKHR"sv;
	}
	case PipelineCompileRequired: {
		return "PipelineCompileRequired"sv;
	}
	case IncompatibleShaderBinaryEXT: {
		return "IncompatibleShaderBinaryEXT"sv;
	}
	case PipelineBinaryMissingKHR: {
		return "PipelineBinaryMissingKHR"sv;
	}
	}
	return "EnumElement not part of: Result";
}
template<> auto enumToString(SamplerAddressMode enumVal) -> std::string_view {
	using enum SamplerAddressMode;
	switch (enumVal) {
	case Repeat: {
		return "Repeat"sv;
	}
	case MirroredRepeat: {
		return "MirroredRepeat"sv;
	}
	case ClampToEdge: {
		return "ClampToEdge"sv;
	}
	case ClampToBorder: {
		return "ClampToBorder"sv;
	}
	case MirrorClampToEdge: {
		return "MirrorClampToEdge"sv;
	}
	}
	return "EnumElement not part of: SamplerAddressMode";
}
template<> auto enumToString(SamplerMipmapMode enumVal) -> std::string_view {
	using enum SamplerMipmapMode;
	switch (enumVal) {
	case Nearest: {
		return "Nearest"sv;
	}
	case Linear: {
		return "Linear"sv;
	}
	}
	return "EnumElement not part of: SamplerMipmapMode";
}
template<> auto enumToString(SamplerReductionMode enumVal) -> std::string_view {
	using enum SamplerReductionMode;
	switch (enumVal) {
	case WeightedAverage: {
		return "WeightedAverage"sv;
	}
	case Min: {
		return "Min"sv;
	}
	case Max: {
		return "Max"sv;
	}
	case WeightedAverageRangeclampQCOM: {
		return "WeightedAverageRangeclampQCOM"sv;
	}
	}
	return "EnumElement not part of: SamplerReductionMode";
}
template<> auto enumToString(SamplerYcbcrModelConversion enumVal) -> std::string_view {
	using enum SamplerYcbcrModelConversion;
	switch (enumVal) {
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
	}
	return "EnumElement not part of: SamplerYcbcrModelConversion";
}
template<> auto enumToString(SamplerYcbcrRange enumVal) -> std::string_view {
	using enum SamplerYcbcrRange;
	switch (enumVal) {
	case ItuFull: {
		return "ItuFull"sv;
	}
	case ItuNarrow: {
		return "ItuNarrow"sv;
	}
	}
	return "EnumElement not part of: SamplerYcbcrRange";
}
template<> auto enumToString(ScopeKHR enumVal) -> std::string_view {
	using enum ScopeKHR;
	switch (enumVal) {
	case Device: {
		return "Device"sv;
	}
	case Workgroup: {
		return "Workgroup"sv;
	}
	case Subgroup: {
		return "Subgroup"sv;
	}
	case QueueFamily: {
		return "QueueFamily"sv;
	}
	}
	return "EnumElement not part of: ScopeKHR";
}
template<> auto enumToString(SemaphoreType enumVal) -> std::string_view {
	using enum SemaphoreType;
	switch (enumVal) {
	case Binary: {
		return "Binary"sv;
	}
	case Timeline: {
		return "Timeline"sv;
	}
	}
	return "EnumElement not part of: SemaphoreType";
}
template<> auto enumToString(ShaderCodeTypeEXT enumVal) -> std::string_view {
	using enum ShaderCodeTypeEXT;
	switch (enumVal) {
	case Binary: {
		return "Binary"sv;
	}
	case Spirv: {
		return "Spirv"sv;
	}
	}
	return "EnumElement not part of: ShaderCodeTypeEXT";
}
template<> auto enumToString(ShaderFloatControlsIndependence enumVal) -> std::string_view {
	using enum ShaderFloatControlsIndependence;
	switch (enumVal) {
	case v32BitOnly: {
		return "v32BitOnly"sv;
	}
	case All: {
		return "All"sv;
	}
	case None: {
		return "None"sv;
	}
	}
	return "EnumElement not part of: ShaderFloatControlsIndependence";
}
template<> auto enumToString(ShaderGroupShaderKHR enumVal) -> std::string_view {
	using enum ShaderGroupShaderKHR;
	switch (enumVal) {
	case General: {
		return "General"sv;
	}
	case ClosestHit: {
		return "ClosestHit"sv;
	}
	case AnyHit: {
		return "AnyHit"sv;
	}
	case Intersection: {
		return "Intersection"sv;
	}
	}
	return "EnumElement not part of: ShaderGroupShaderKHR";
}
template<> auto enumToString(ShaderInfoTypeAMD enumVal) -> std::string_view {
	using enum ShaderInfoTypeAMD;
	switch (enumVal) {
	case Statistics: {
		return "Statistics"sv;
	}
	case Binary: {
		return "Binary"sv;
	}
	case Disassembly: {
		return "Disassembly"sv;
	}
	}
	return "EnumElement not part of: ShaderInfoTypeAMD";
}
template<> auto enumToString(ShadingRatePaletteEntryNV enumVal) -> std::string_view {
	using enum ShadingRatePaletteEntryNV;
	switch (enumVal) {
	case NoInvocations: {
		return "NoInvocations"sv;
	}
	case v16InvocationsPerPixel: {
		return "v16InvocationsPerPixel"sv;
	}
	case v8InvocationsPerPixel: {
		return "v8InvocationsPerPixel"sv;
	}
	case v4InvocationsPerPixel: {
		return "v4InvocationsPerPixel"sv;
	}
	case v2InvocationsPerPixel: {
		return "v2InvocationsPerPixel"sv;
	}
	case v1InvocationPerPixel: {
		return "v1InvocationPerPixel"sv;
	}
	case v1InvocationPer2x1Pixels: {
		return "v1InvocationPer2x1Pixels"sv;
	}
	case v1InvocationPer1x2Pixels: {
		return "v1InvocationPer1x2Pixels"sv;
	}
	case v1InvocationPer2x2Pixels: {
		return "v1InvocationPer2x2Pixels"sv;
	}
	case v1InvocationPer4x2Pixels: {
		return "v1InvocationPer4x2Pixels"sv;
	}
	case v1InvocationPer2x4Pixels: {
		return "v1InvocationPer2x4Pixels"sv;
	}
	case v1InvocationPer4x4Pixels: {
		return "v1InvocationPer4x4Pixels"sv;
	}
	}
	return "EnumElement not part of: ShadingRatePaletteEntryNV";
}
template<> auto enumToString(SharingMode enumVal) -> std::string_view {
	using enum SharingMode;
	switch (enumVal) {
	case Exclusive: {
		return "Exclusive"sv;
	}
	case Concurrent: {
		return "Concurrent"sv;
	}
	}
	return "EnumElement not part of: SharingMode";
}
template<> auto enumToString(StencilOp enumVal) -> std::string_view {
	using enum StencilOp;
	switch (enumVal) {
	case Keep: {
		return "Keep"sv;
	}
	case Zero: {
		return "Zero"sv;
	}
	case Replace: {
		return "Replace"sv;
	}
	case IncrementAndClamp: {
		return "IncrementAndClamp"sv;
	}
	case DecrementAndClamp: {
		return "DecrementAndClamp"sv;
	}
	case Invert: {
		return "Invert"sv;
	}
	case IncrementAndWrap: {
		return "IncrementAndWrap"sv;
	}
	case DecrementAndWrap: {
		return "DecrementAndWrap"sv;
	}
	}
	return "EnumElement not part of: StencilOp";
}
template<> auto enumToString(StructureType enumVal) -> std::string_view {
	using enum StructureType;
	switch (enumVal) {
	case ApplicationInfo: {
		return "ApplicationInfo"sv;
	}
	case InstanceCreateInfo: {
		return "InstanceCreateInfo"sv;
	}
	case DeviceQueueCreateInfo: {
		return "DeviceQueueCreateInfo"sv;
	}
	case DeviceCreateInfo: {
		return "DeviceCreateInfo"sv;
	}
	case SubmitInfo: {
		return "SubmitInfo"sv;
	}
	case MemoryAllocateInfo: {
		return "MemoryAllocateInfo"sv;
	}
	case MappedMemoryRange: {
		return "MappedMemoryRange"sv;
	}
	case BindSparseInfo: {
		return "BindSparseInfo"sv;
	}
	case FenceCreateInfo: {
		return "FenceCreateInfo"sv;
	}
	case SemaphoreCreateInfo: {
		return "SemaphoreCreateInfo"sv;
	}
	case EventCreateInfo: {
		return "EventCreateInfo"sv;
	}
	case QueryPoolCreateInfo: {
		return "QueryPoolCreateInfo"sv;
	}
	case BufferCreateInfo: {
		return "BufferCreateInfo"sv;
	}
	case BufferViewCreateInfo: {
		return "BufferViewCreateInfo"sv;
	}
	case ImageCreateInfo: {
		return "ImageCreateInfo"sv;
	}
	case ImageViewCreateInfo: {
		return "ImageViewCreateInfo"sv;
	}
	case ShaderModuleCreateInfo: {
		return "ShaderModuleCreateInfo"sv;
	}
	case PipelineCacheCreateInfo: {
		return "PipelineCacheCreateInfo"sv;
	}
	case PipelineShaderStageCreateInfo: {
		return "PipelineShaderStageCreateInfo"sv;
	}
	case PipelineVertexInputStateCreateInfo: {
		return "PipelineVertexInputStateCreateInfo"sv;
	}
	case PipelineInputAssemblyStateCreateInfo: {
		return "PipelineInputAssemblyStateCreateInfo"sv;
	}
	case PipelineTessellationStateCreateInfo: {
		return "PipelineTessellationStateCreateInfo"sv;
	}
	case PipelineViewportStateCreateInfo: {
		return "PipelineViewportStateCreateInfo"sv;
	}
	case PipelineRasterizationStateCreateInfo: {
		return "PipelineRasterizationStateCreateInfo"sv;
	}
	case PipelineMultisampleStateCreateInfo: {
		return "PipelineMultisampleStateCreateInfo"sv;
	}
	case PipelineDepthStencilStateCreateInfo: {
		return "PipelineDepthStencilStateCreateInfo"sv;
	}
	case PipelineColorBlendStateCreateInfo: {
		return "PipelineColorBlendStateCreateInfo"sv;
	}
	case PipelineDynamicStateCreateInfo: {
		return "PipelineDynamicStateCreateInfo"sv;
	}
	case GraphicsPipelineCreateInfo: {
		return "GraphicsPipelineCreateInfo"sv;
	}
	case ComputePipelineCreateInfo: {
		return "ComputePipelineCreateInfo"sv;
	}
	case PipelineLayoutCreateInfo: {
		return "PipelineLayoutCreateInfo"sv;
	}
	case SamplerCreateInfo: {
		return "SamplerCreateInfo"sv;
	}
	case DescriptorSetLayoutCreateInfo: {
		return "DescriptorSetLayoutCreateInfo"sv;
	}
	case DescriptorPoolCreateInfo: {
		return "DescriptorPoolCreateInfo"sv;
	}
	case DescriptorSetAllocateInfo: {
		return "DescriptorSetAllocateInfo"sv;
	}
	case WriteDescriptorSet: {
		return "WriteDescriptorSet"sv;
	}
	case CopyDescriptorSet: {
		return "CopyDescriptorSet"sv;
	}
	case FramebufferCreateInfo: {
		return "FramebufferCreateInfo"sv;
	}
	case RenderPassCreateInfo: {
		return "RenderPassCreateInfo"sv;
	}
	case CommandPoolCreateInfo: {
		return "CommandPoolCreateInfo"sv;
	}
	case CommandBufferAllocateInfo: {
		return "CommandBufferAllocateInfo"sv;
	}
	case CommandBufferInheritanceInfo: {
		return "CommandBufferInheritanceInfo"sv;
	}
	case CommandBufferBeginInfo: {
		return "CommandBufferBeginInfo"sv;
	}
	case RenderPassBeginInfo: {
		return "RenderPassBeginInfo"sv;
	}
	case BufferMemoryBarrier: {
		return "BufferMemoryBarrier"sv;
	}
	case ImageMemoryBarrier: {
		return "ImageMemoryBarrier"sv;
	}
	case MemoryBarrier: {
		return "MemoryBarrier"sv;
	}
	case LoaderInstanceCreateInfo: {
		return "LoaderInstanceCreateInfo"sv;
	}
	case LoaderDeviceCreateInfo: {
		return "LoaderDeviceCreateInfo"sv;
	}
	case PhysicalDeviceVulkan11Features: {
		return "PhysicalDeviceVulkan11Features"sv;
	}
	case PhysicalDeviceVulkan11Properties: {
		return "PhysicalDeviceVulkan11Properties"sv;
	}
	case PhysicalDeviceVulkan12Features: {
		return "PhysicalDeviceVulkan12Features"sv;
	}
	case PhysicalDeviceVulkan12Properties: {
		return "PhysicalDeviceVulkan12Properties"sv;
	}
	case PhysicalDeviceVulkan13Features: {
		return "PhysicalDeviceVulkan13Features"sv;
	}
	case PhysicalDeviceVulkan13Properties: {
		return "PhysicalDeviceVulkan13Properties"sv;
	}
	case PhysicalDeviceVulkan14Features: {
		return "PhysicalDeviceVulkan14Features"sv;
	}
	case PhysicalDeviceVulkan14Properties: {
		return "PhysicalDeviceVulkan14Properties"sv;
	}
	case SwapchainCreateInfoKHR: {
		return "SwapchainCreateInfoKHR"sv;
	}
	case PresentInfoKHR: {
		return "PresentInfoKHR"sv;
	}
	case DisplayModeCreateInfoKHR: {
		return "DisplayModeCreateInfoKHR"sv;
	}
	case DisplaySurfaceCreateInfoKHR: {
		return "DisplaySurfaceCreateInfoKHR"sv;
	}
	case DisplayPresentInfoKHR: {
		return "DisplayPresentInfoKHR"sv;
	}
	case XlibSurfaceCreateInfoKHR: {
		return "XlibSurfaceCreateInfoKHR"sv;
	}
	case XcbSurfaceCreateInfoKHR: {
		return "XcbSurfaceCreateInfoKHR"sv;
	}
	case WaylandSurfaceCreateInfoKHR: {
		return "WaylandSurfaceCreateInfoKHR"sv;
	}
	case ANDROIDSurfaceCreateInfoKHR: {
		return "ANDROIDSurfaceCreateInfoKHR"sv;
	}
	case Win32SurfaceCreateInfoKHR: {
		return "Win32SurfaceCreateInfoKHR"sv;
	}
	case DebugReportCallbackCreateInfoEXT: {
		return "DebugReportCallbackCreateInfoEXT"sv;
	}
	case PipelineRasterizationStateRasterizationOrderAMD: {
		return "PipelineRasterizationStateRasterizationOrderAMD"sv;
	}
	case DebugMarkerObjectNameInfoEXT: {
		return "DebugMarkerObjectNameInfoEXT"sv;
	}
	case DebugMarkerObjectTagInfoEXT: {
		return "DebugMarkerObjectTagInfoEXT"sv;
	}
	case DebugMarkerMarkerInfoEXT: {
		return "DebugMarkerMarkerInfoEXT"sv;
	}
	case VideoProfileInfoKHR: {
		return "VideoProfileInfoKHR"sv;
	}
	case VideoCapabilitiesKHR: {
		return "VideoCapabilitiesKHR"sv;
	}
	case VideoPictureResourceInfoKHR: {
		return "VideoPictureResourceInfoKHR"sv;
	}
	case VideoSessionMemoryRequirementsKHR: {
		return "VideoSessionMemoryRequirementsKHR"sv;
	}
	case BindVideoSessionMemoryInfoKHR: {
		return "BindVideoSessionMemoryInfoKHR"sv;
	}
	case VideoSessionCreateInfoKHR: {
		return "VideoSessionCreateInfoKHR"sv;
	}
	case VideoSessionParametersCreateInfoKHR: {
		return "VideoSessionParametersCreateInfoKHR"sv;
	}
	case VideoSessionParametersUpdateInfoKHR: {
		return "VideoSessionParametersUpdateInfoKHR"sv;
	}
	case VideoBeginCodingInfoKHR: {
		return "VideoBeginCodingInfoKHR"sv;
	}
	case VideoEndCodingInfoKHR: {
		return "VideoEndCodingInfoKHR"sv;
	}
	case VideoCodingControlInfoKHR: {
		return "VideoCodingControlInfoKHR"sv;
	}
	case VideoReferenceSlotInfoKHR: {
		return "VideoReferenceSlotInfoKHR"sv;
	}
	case QueueFamilyVideoPropertiesKHR: {
		return "QueueFamilyVideoPropertiesKHR"sv;
	}
	case VideoProfileListInfoKHR: {
		return "VideoProfileListInfoKHR"sv;
	}
	case PhysicalDeviceVideoFormatInfoKHR: {
		return "PhysicalDeviceVideoFormatInfoKHR"sv;
	}
	case VideoFormatPropertiesKHR: {
		return "VideoFormatPropertiesKHR"sv;
	}
	case QueueFamilyQueryResultStatusPropertiesKHR: {
		return "QueueFamilyQueryResultStatusPropertiesKHR"sv;
	}
	case VideoDecodeInfoKHR: {
		return "VideoDecodeInfoKHR"sv;
	}
	case VideoDecodeCapabilitiesKHR: {
		return "VideoDecodeCapabilitiesKHR"sv;
	}
	case VideoDecodeUsageInfoKHR: {
		return "VideoDecodeUsageInfoKHR"sv;
	}
	case DedicatedAllocationImageCreateInfoNV: {
		return "DedicatedAllocationImageCreateInfoNV"sv;
	}
	case DedicatedAllocationBufferCreateInfoNV: {
		return "DedicatedAllocationBufferCreateInfoNV"sv;
	}
	case DedicatedAllocationMemoryAllocateInfoNV: {
		return "DedicatedAllocationMemoryAllocateInfoNV"sv;
	}
	case PhysicalDeviceTransformFeedbackFeaturesEXT: {
		return "PhysicalDeviceTransformFeedbackFeaturesEXT"sv;
	}
	case PhysicalDeviceTransformFeedbackPropertiesEXT: {
		return "PhysicalDeviceTransformFeedbackPropertiesEXT"sv;
	}
	case PipelineRasterizationStateStreamCreateInfoEXT: {
		return "PipelineRasterizationStateStreamCreateInfoEXT"sv;
	}
	case CuModuleCreateInfoNVX: {
		return "CuModuleCreateInfoNVX"sv;
	}
	case CuFunctionCreateInfoNVX: {
		return "CuFunctionCreateInfoNVX"sv;
	}
	case CuLaunchInfoNVX: {
		return "CuLaunchInfoNVX"sv;
	}
	case CuModuleTexturingModeCreateInfoNVX: {
		return "CuModuleTexturingModeCreateInfoNVX"sv;
	}
	case ImageViewHandleInfoNVX: {
		return "ImageViewHandleInfoNVX"sv;
	}
	case ImageViewAddressPropertiesNVX: {
		return "ImageViewAddressPropertiesNVX"sv;
	}
	case VideoEncodeH264CapabilitiesKHR: {
		return "VideoEncodeH264CapabilitiesKHR"sv;
	}
	case VideoEncodeH264SessionParametersCreateInfoKHR: {
		return "VideoEncodeH264SessionParametersCreateInfoKHR"sv;
	}
	case VideoEncodeH264SessionParametersAddInfoKHR: {
		return "VideoEncodeH264SessionParametersAddInfoKHR"sv;
	}
	case VideoEncodeH264PictureInfoKHR: {
		return "VideoEncodeH264PictureInfoKHR"sv;
	}
	case VideoEncodeH264DpbSlotInfoKHR: {
		return "VideoEncodeH264DpbSlotInfoKHR"sv;
	}
	case VideoEncodeH264NaluSliceInfoKHR: {
		return "VideoEncodeH264NaluSliceInfoKHR"sv;
	}
	case VideoEncodeH264GopRemainingFrameInfoKHR: {
		return "VideoEncodeH264GopRemainingFrameInfoKHR"sv;
	}
	case VideoEncodeH264ProfileInfoKHR: {
		return "VideoEncodeH264ProfileInfoKHR"sv;
	}
	case VideoEncodeH264RateControlInfoKHR: {
		return "VideoEncodeH264RateControlInfoKHR"sv;
	}
	case VideoEncodeH264RateControlLayerInfoKHR: {
		return "VideoEncodeH264RateControlLayerInfoKHR"sv;
	}
	case VideoEncodeH264SessionCreateInfoKHR: {
		return "VideoEncodeH264SessionCreateInfoKHR"sv;
	}
	case VideoEncodeH264QualityLevelPropertiesKHR: {
		return "VideoEncodeH264QualityLevelPropertiesKHR"sv;
	}
	case VideoEncodeH264SessionParametersGetInfoKHR: {
		return "VideoEncodeH264SessionParametersGetInfoKHR"sv;
	}
	case VideoEncodeH264SessionParametersFeedbackInfoKHR: {
		return "VideoEncodeH264SessionParametersFeedbackInfoKHR"sv;
	}
	case VideoEncodeH265CapabilitiesKHR: {
		return "VideoEncodeH265CapabilitiesKHR"sv;
	}
	case VideoEncodeH265SessionParametersCreateInfoKHR: {
		return "VideoEncodeH265SessionParametersCreateInfoKHR"sv;
	}
	case VideoEncodeH265SessionParametersAddInfoKHR: {
		return "VideoEncodeH265SessionParametersAddInfoKHR"sv;
	}
	case VideoEncodeH265PictureInfoKHR: {
		return "VideoEncodeH265PictureInfoKHR"sv;
	}
	case VideoEncodeH265DpbSlotInfoKHR: {
		return "VideoEncodeH265DpbSlotInfoKHR"sv;
	}
	case VideoEncodeH265NaluSliceSegmentInfoKHR: {
		return "VideoEncodeH265NaluSliceSegmentInfoKHR"sv;
	}
	case VideoEncodeH265GopRemainingFrameInfoKHR: {
		return "VideoEncodeH265GopRemainingFrameInfoKHR"sv;
	}
	case VideoEncodeH265ProfileInfoKHR: {
		return "VideoEncodeH265ProfileInfoKHR"sv;
	}
	case VideoEncodeH265RateControlInfoKHR: {
		return "VideoEncodeH265RateControlInfoKHR"sv;
	}
	case VideoEncodeH265RateControlLayerInfoKHR: {
		return "VideoEncodeH265RateControlLayerInfoKHR"sv;
	}
	case VideoEncodeH265SessionCreateInfoKHR: {
		return "VideoEncodeH265SessionCreateInfoKHR"sv;
	}
	case VideoEncodeH265QualityLevelPropertiesKHR: {
		return "VideoEncodeH265QualityLevelPropertiesKHR"sv;
	}
	case VideoEncodeH265SessionParametersGetInfoKHR: {
		return "VideoEncodeH265SessionParametersGetInfoKHR"sv;
	}
	case VideoEncodeH265SessionParametersFeedbackInfoKHR: {
		return "VideoEncodeH265SessionParametersFeedbackInfoKHR"sv;
	}
	case VideoDecodeH264CapabilitiesKHR: {
		return "VideoDecodeH264CapabilitiesKHR"sv;
	}
	case VideoDecodeH264PictureInfoKHR: {
		return "VideoDecodeH264PictureInfoKHR"sv;
	}
	case VideoDecodeH264ProfileInfoKHR: {
		return "VideoDecodeH264ProfileInfoKHR"sv;
	}
	case VideoDecodeH264SessionParametersCreateInfoKHR: {
		return "VideoDecodeH264SessionParametersCreateInfoKHR"sv;
	}
	case VideoDecodeH264SessionParametersAddInfoKHR: {
		return "VideoDecodeH264SessionParametersAddInfoKHR"sv;
	}
	case VideoDecodeH264DpbSlotInfoKHR: {
		return "VideoDecodeH264DpbSlotInfoKHR"sv;
	}
	case TextureLodGatherFormatPropertiesAMD: {
		return "TextureLodGatherFormatPropertiesAMD"sv;
	}
	case RenderingInfo: {
		return "RenderingInfo"sv;
	}
	case RenderingAttachmentInfo: {
		return "RenderingAttachmentInfo"sv;
	}
	case PipelineRenderingCreateInfo: {
		return "PipelineRenderingCreateInfo"sv;
	}
	case PhysicalDeviceDynamicRenderingFeatures: {
		return "PhysicalDeviceDynamicRenderingFeatures"sv;
	}
	case CommandBufferInheritanceRenderingInfo: {
		return "CommandBufferInheritanceRenderingInfo"sv;
	}
	case RenderingFragmentShadingRateAttachmentInfoKHR: {
		return "RenderingFragmentShadingRateAttachmentInfoKHR"sv;
	}
	case RenderingFragmentDensityMapAttachmentInfoEXT: {
		return "RenderingFragmentDensityMapAttachmentInfoEXT"sv;
	}
	case AttachmentSampleCountInfoAMD: {
		return "AttachmentSampleCountInfoAMD"sv;
	}
	case MultiviewPerViewAttributesInfoNVX: {
		return "MultiviewPerViewAttributesInfoNVX"sv;
	}
	case StreamDescriptorSurfaceCreateInfoGGP: {
		return "StreamDescriptorSurfaceCreateInfoGGP"sv;
	}
	case PhysicalDeviceCornerSampledImageFeaturesNV: {
		return "PhysicalDeviceCornerSampledImageFeaturesNV"sv;
	}
	case RenderPassMultiviewCreateInfo: {
		return "RenderPassMultiviewCreateInfo"sv;
	}
	case PhysicalDeviceMultiviewFeatures: {
		return "PhysicalDeviceMultiviewFeatures"sv;
	}
	case PhysicalDeviceMultiviewProperties: {
		return "PhysicalDeviceMultiviewProperties"sv;
	}
	case ExternalMemoryImageCreateInfoNV: {
		return "ExternalMemoryImageCreateInfoNV"sv;
	}
	case ExportMemoryAllocateInfoNV: {
		return "ExportMemoryAllocateInfoNV"sv;
	}
	case ImportMemoryWin32HandleInfoNV: {
		return "ImportMemoryWin32HandleInfoNV"sv;
	}
	case ExportMemoryWin32HandleInfoNV: {
		return "ExportMemoryWin32HandleInfoNV"sv;
	}
	case Win32KeyedMutexAcquireReleaseInfoNV: {
		return "Win32KeyedMutexAcquireReleaseInfoNV"sv;
	}
	case PhysicalDeviceFeatures2: {
		return "PhysicalDeviceFeatures2"sv;
	}
	case PhysicalDeviceProperties2: {
		return "PhysicalDeviceProperties2"sv;
	}
	case FormatProperties2: {
		return "FormatProperties2"sv;
	}
	case ImageFormatProperties2: {
		return "ImageFormatProperties2"sv;
	}
	case PhysicalDeviceImageFormatInfo2: {
		return "PhysicalDeviceImageFormatInfo2"sv;
	}
	case QueueFamilyProperties2: {
		return "QueueFamilyProperties2"sv;
	}
	case PhysicalDeviceMemoryProperties2: {
		return "PhysicalDeviceMemoryProperties2"sv;
	}
	case SparseImageFormatProperties2: {
		return "SparseImageFormatProperties2"sv;
	}
	case PhysicalDeviceSparseImageFormatInfo2: {
		return "PhysicalDeviceSparseImageFormatInfo2"sv;
	}
	case MemoryAllocateFlagsInfo: {
		return "MemoryAllocateFlagsInfo"sv;
	}
	case DeviceGroupRenderPassBeginInfo: {
		return "DeviceGroupRenderPassBeginInfo"sv;
	}
	case DeviceGroupCommandBufferBeginInfo: {
		return "DeviceGroupCommandBufferBeginInfo"sv;
	}
	case DeviceGroupSubmitInfo: {
		return "DeviceGroupSubmitInfo"sv;
	}
	case DeviceGroupBindSparseInfo: {
		return "DeviceGroupBindSparseInfo"sv;
	}
	case DeviceGroupPresentCapabilitiesKHR: {
		return "DeviceGroupPresentCapabilitiesKHR"sv;
	}
	case ImageSwapchainCreateInfoKHR: {
		return "ImageSwapchainCreateInfoKHR"sv;
	}
	case BindImageMemorySwapchainInfoKHR: {
		return "BindImageMemorySwapchainInfoKHR"sv;
	}
	case AcquireNextImageInfoKHR: {
		return "AcquireNextImageInfoKHR"sv;
	}
	case DeviceGroupPresentInfoKHR: {
		return "DeviceGroupPresentInfoKHR"sv;
	}
	case DeviceGroupSwapchainCreateInfoKHR: {
		return "DeviceGroupSwapchainCreateInfoKHR"sv;
	}
	case BindBufferMemoryDeviceGroupInfo: {
		return "BindBufferMemoryDeviceGroupInfo"sv;
	}
	case BindImageMemoryDeviceGroupInfo: {
		return "BindImageMemoryDeviceGroupInfo"sv;
	}
	case ValidationFlagsEXT: {
		return "ValidationFlagsEXT"sv;
	}
	case ViSurfaceCreateInfoNN: {
		return "ViSurfaceCreateInfoNN"sv;
	}
	case PhysicalDeviceShaderDrawParametersFeatures: {
		return "PhysicalDeviceShaderDrawParametersFeatures"sv;
	}
	case PhysicalDeviceTextureCompressionAstcHdrFeatures: {
		return "PhysicalDeviceTextureCompressionAstcHdrFeatures"sv;
	}
	case ImageViewAstcDecodeModeEXT: {
		return "ImageViewAstcDecodeModeEXT"sv;
	}
	case PhysicalDeviceAstcDecodeFeaturesEXT: {
		return "PhysicalDeviceAstcDecodeFeaturesEXT"sv;
	}
	case PipelineRobustnessCreateInfo: {
		return "PipelineRobustnessCreateInfo"sv;
	}
	case PhysicalDevicePipelineRobustnessFeatures: {
		return "PhysicalDevicePipelineRobustnessFeatures"sv;
	}
	case PhysicalDevicePipelineRobustnessProperties: {
		return "PhysicalDevicePipelineRobustnessProperties"sv;
	}
	case PhysicalDeviceGroupProperties: {
		return "PhysicalDeviceGroupProperties"sv;
	}
	case DeviceGroupDeviceCreateInfo: {
		return "DeviceGroupDeviceCreateInfo"sv;
	}
	case PhysicalDeviceExternalImageFormatInfo: {
		return "PhysicalDeviceExternalImageFormatInfo"sv;
	}
	case ExternalImageFormatProperties: {
		return "ExternalImageFormatProperties"sv;
	}
	case PhysicalDeviceExternalBufferInfo: {
		return "PhysicalDeviceExternalBufferInfo"sv;
	}
	case ExternalBufferProperties: {
		return "ExternalBufferProperties"sv;
	}
	case PhysicalDeviceIdProperties: {
		return "PhysicalDeviceIdProperties"sv;
	}
	case ExternalMemoryBufferCreateInfo: {
		return "ExternalMemoryBufferCreateInfo"sv;
	}
	case ExternalMemoryImageCreateInfo: {
		return "ExternalMemoryImageCreateInfo"sv;
	}
	case ExportMemoryAllocateInfo: {
		return "ExportMemoryAllocateInfo"sv;
	}
	case ImportMemoryWin32HandleInfoKHR: {
		return "ImportMemoryWin32HandleInfoKHR"sv;
	}
	case ExportMemoryWin32HandleInfoKHR: {
		return "ExportMemoryWin32HandleInfoKHR"sv;
	}
	case MemoryWin32HandlePropertiesKHR: {
		return "MemoryWin32HandlePropertiesKHR"sv;
	}
	case MemoryGetWin32HandleInfoKHR: {
		return "MemoryGetWin32HandleInfoKHR"sv;
	}
	case ImportMemoryFdInfoKHR: {
		return "ImportMemoryFdInfoKHR"sv;
	}
	case MemoryFdPropertiesKHR: {
		return "MemoryFdPropertiesKHR"sv;
	}
	case MemoryGetFdInfoKHR: {
		return "MemoryGetFdInfoKHR"sv;
	}
	case Win32KeyedMutexAcquireReleaseInfoKHR: {
		return "Win32KeyedMutexAcquireReleaseInfoKHR"sv;
	}
	case PhysicalDeviceExternalSemaphoreInfo: {
		return "PhysicalDeviceExternalSemaphoreInfo"sv;
	}
	case ExternalSemaphoreProperties: {
		return "ExternalSemaphoreProperties"sv;
	}
	case ExportSemaphoreCreateInfo: {
		return "ExportSemaphoreCreateInfo"sv;
	}
	case ImportSemaphoreWin32HandleInfoKHR: {
		return "ImportSemaphoreWin32HandleInfoKHR"sv;
	}
	case ExportSemaphoreWin32HandleInfoKHR: {
		return "ExportSemaphoreWin32HandleInfoKHR"sv;
	}
	case D3D12FenceSubmitInfoKHR: {
		return "D3D12FenceSubmitInfoKHR"sv;
	}
	case SemaphoreGetWin32HandleInfoKHR: {
		return "SemaphoreGetWin32HandleInfoKHR"sv;
	}
	case ImportSemaphoreFdInfoKHR: {
		return "ImportSemaphoreFdInfoKHR"sv;
	}
	case SemaphoreGetFdInfoKHR: {
		return "SemaphoreGetFdInfoKHR"sv;
	}
	case PhysicalDevicePushDescriptorProperties: {
		return "PhysicalDevicePushDescriptorProperties"sv;
	}
	case CommandBufferInheritanceConditionalRenderingInfoEXT: {
		return "CommandBufferInheritanceConditionalRenderingInfoEXT"sv;
	}
	case PhysicalDeviceConditionalRenderingFeaturesEXT: {
		return "PhysicalDeviceConditionalRenderingFeaturesEXT"sv;
	}
	case ConditionalRenderingBeginInfoEXT: {
		return "ConditionalRenderingBeginInfoEXT"sv;
	}
	case PhysicalDeviceShaderFloat16Int8Features: {
		return "PhysicalDeviceShaderFloat16Int8Features"sv;
	}
	case PhysicalDevice16BitStorageFeatures: {
		return "PhysicalDevice16BitStorageFeatures"sv;
	}
	case PresentRegionsKHR: {
		return "PresentRegionsKHR"sv;
	}
	case DescriptorUpdateTemplateCreateInfo: {
		return "DescriptorUpdateTemplateCreateInfo"sv;
	}
	case PipelineViewportWScalingStateCreateInfoNV: {
		return "PipelineViewportWScalingStateCreateInfoNV"sv;
	}
	case SurfaceCapabilities2EXT: {
		return "SurfaceCapabilities2EXT"sv;
	}
	case DisplayPowerInfoEXT: {
		return "DisplayPowerInfoEXT"sv;
	}
	case DeviceEventInfoEXT: {
		return "DeviceEventInfoEXT"sv;
	}
	case DisplayEventInfoEXT: {
		return "DisplayEventInfoEXT"sv;
	}
	case SwapchainCounterCreateInfoEXT: {
		return "SwapchainCounterCreateInfoEXT"sv;
	}
	case PresentTimesInfoGOOGLE: {
		return "PresentTimesInfoGOOGLE"sv;
	}
	case PhysicalDeviceSubgroupProperties: {
		return "PhysicalDeviceSubgroupProperties"sv;
	}
	case PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX: {
		return "PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX"sv;
	}
	case PipelineViewportSwizzleStateCreateInfoNV: {
		return "PipelineViewportSwizzleStateCreateInfoNV"sv;
	}
	case PhysicalDeviceDiscardRectanglePropertiesEXT: {
		return "PhysicalDeviceDiscardRectanglePropertiesEXT"sv;
	}
	case PipelineDiscardRectangleStateCreateInfoEXT: {
		return "PipelineDiscardRectangleStateCreateInfoEXT"sv;
	}
	case PhysicalDeviceConservativeRasterizationPropertiesEXT: {
		return "PhysicalDeviceConservativeRasterizationPropertiesEXT"sv;
	}
	case PipelineRasterizationConservativeStateCreateInfoEXT: {
		return "PipelineRasterizationConservativeStateCreateInfoEXT"sv;
	}
	case PhysicalDeviceDepthClipEnableFeaturesEXT: {
		return "PhysicalDeviceDepthClipEnableFeaturesEXT"sv;
	}
	case PipelineRasterizationDepthClipStateCreateInfoEXT: {
		return "PipelineRasterizationDepthClipStateCreateInfoEXT"sv;
	}
	case HdrMetadataEXT: {
		return "HdrMetadataEXT"sv;
	}
	case PhysicalDeviceImagelessFramebufferFeatures: {
		return "PhysicalDeviceImagelessFramebufferFeatures"sv;
	}
	case FramebufferAttachmentsCreateInfo: {
		return "FramebufferAttachmentsCreateInfo"sv;
	}
	case FramebufferAttachmentImageInfo: {
		return "FramebufferAttachmentImageInfo"sv;
	}
	case RenderPassAttachmentBeginInfo: {
		return "RenderPassAttachmentBeginInfo"sv;
	}
	case AttachmentDescription2: {
		return "AttachmentDescription2"sv;
	}
	case AttachmentReference2: {
		return "AttachmentReference2"sv;
	}
	case SubpassDescription2: {
		return "SubpassDescription2"sv;
	}
	case SubpassDependency2: {
		return "SubpassDependency2"sv;
	}
	case RenderPassCreateInfo2: {
		return "RenderPassCreateInfo2"sv;
	}
	case SubpassBeginInfo: {
		return "SubpassBeginInfo"sv;
	}
	case SubpassEndInfo: {
		return "SubpassEndInfo"sv;
	}
	case PhysicalDeviceRelaxedLineRasterizationFeaturesIMG: {
		return "PhysicalDeviceRelaxedLineRasterizationFeaturesIMG"sv;
	}
	case SharedPresentSurfaceCapabilitiesKHR: {
		return "SharedPresentSurfaceCapabilitiesKHR"sv;
	}
	case PhysicalDeviceExternalFenceInfo: {
		return "PhysicalDeviceExternalFenceInfo"sv;
	}
	case ExternalFenceProperties: {
		return "ExternalFenceProperties"sv;
	}
	case ExportFenceCreateInfo: {
		return "ExportFenceCreateInfo"sv;
	}
	case ImportFenceWin32HandleInfoKHR: {
		return "ImportFenceWin32HandleInfoKHR"sv;
	}
	case ExportFenceWin32HandleInfoKHR: {
		return "ExportFenceWin32HandleInfoKHR"sv;
	}
	case FenceGetWin32HandleInfoKHR: {
		return "FenceGetWin32HandleInfoKHR"sv;
	}
	case ImportFenceFdInfoKHR: {
		return "ImportFenceFdInfoKHR"sv;
	}
	case FenceGetFdInfoKHR: {
		return "FenceGetFdInfoKHR"sv;
	}
	case PhysicalDevicePerformanceQueryFeaturesKHR: {
		return "PhysicalDevicePerformanceQueryFeaturesKHR"sv;
	}
	case PhysicalDevicePerformanceQueryPropertiesKHR: {
		return "PhysicalDevicePerformanceQueryPropertiesKHR"sv;
	}
	case QueryPoolPerformanceCreateInfoKHR: {
		return "QueryPoolPerformanceCreateInfoKHR"sv;
	}
	case PerformanceQuerySubmitInfoKHR: {
		return "PerformanceQuerySubmitInfoKHR"sv;
	}
	case AcquireProfilingLockInfoKHR: {
		return "AcquireProfilingLockInfoKHR"sv;
	}
	case PerformanceCounterKHR: {
		return "PerformanceCounterKHR"sv;
	}
	case PerformanceCounterDescriptionKHR: {
		return "PerformanceCounterDescriptionKHR"sv;
	}
	case PhysicalDevicePointClippingProperties: {
		return "PhysicalDevicePointClippingProperties"sv;
	}
	case RenderPassInputAttachmentAspectCreateInfo: {
		return "RenderPassInputAttachmentAspectCreateInfo"sv;
	}
	case ImageViewUsageCreateInfo: {
		return "ImageViewUsageCreateInfo"sv;
	}
	case PipelineTessellationDomainOriginStateCreateInfo: {
		return "PipelineTessellationDomainOriginStateCreateInfo"sv;
	}
	case PhysicalDeviceSurfaceInfo2KHR: {
		return "PhysicalDeviceSurfaceInfo2KHR"sv;
	}
	case SurfaceCapabilities2KHR: {
		return "SurfaceCapabilities2KHR"sv;
	}
	case SurfaceFormat2KHR: {
		return "SurfaceFormat2KHR"sv;
	}
	case PhysicalDeviceVariablePointersFeatures: {
		return "PhysicalDeviceVariablePointersFeatures"sv;
	}
	case DisplayProperties2KHR: {
		return "DisplayProperties2KHR"sv;
	}
	case DisplayPlaneProperties2KHR: {
		return "DisplayPlaneProperties2KHR"sv;
	}
	case DisplayModeProperties2KHR: {
		return "DisplayModeProperties2KHR"sv;
	}
	case DisplayPlaneInfo2KHR: {
		return "DisplayPlaneInfo2KHR"sv;
	}
	case DisplayPlaneCapabilities2KHR: {
		return "DisplayPlaneCapabilities2KHR"sv;
	}
	case IosSurfaceCreateInfoMVK: {
		return "IosSurfaceCreateInfoMVK"sv;
	}
	case MacosSurfaceCreateInfoMVK: {
		return "MacosSurfaceCreateInfoMVK"sv;
	}
	case MemoryDedicatedRequirements: {
		return "MemoryDedicatedRequirements"sv;
	}
	case MemoryDedicatedAllocateInfo: {
		return "MemoryDedicatedAllocateInfo"sv;
	}
	case DebugUtilsObjectNameInfoEXT: {
		return "DebugUtilsObjectNameInfoEXT"sv;
	}
	case DebugUtilsObjectTagInfoEXT: {
		return "DebugUtilsObjectTagInfoEXT"sv;
	}
	case DebugUtilsLabelEXT: {
		return "DebugUtilsLabelEXT"sv;
	}
	case DebugUtilsMessengerCallbackDataEXT: {
		return "DebugUtilsMessengerCallbackDataEXT"sv;
	}
	case DebugUtilsMessengerCreateInfoEXT: {
		return "DebugUtilsMessengerCreateInfoEXT"sv;
	}
	case ANDROIDHardwareBufferUsageANDROID: {
		return "ANDROIDHardwareBufferUsageANDROID"sv;
	}
	case ANDROIDHardwareBufferPropertiesANDROID: {
		return "ANDROIDHardwareBufferPropertiesANDROID"sv;
	}
	case ANDROIDHardwareBufferFormatPropertiesANDROID: {
		return "ANDROIDHardwareBufferFormatPropertiesANDROID"sv;
	}
	case ImportANDROIDHardwareBufferInfoANDROID: {
		return "ImportANDROIDHardwareBufferInfoANDROID"sv;
	}
	case MemoryGetANDROIDHardwareBufferInfoANDROID: {
		return "MemoryGetANDROIDHardwareBufferInfoANDROID"sv;
	}
	case ExternalFormatANDROID: {
		return "ExternalFormatANDROID"sv;
	}
	case ANDROIDHardwareBufferFormatProperties2ANDROID: {
		return "ANDROIDHardwareBufferFormatProperties2ANDROID"sv;
	}
	case PhysicalDeviceSamplerFilterMinmaxProperties: {
		return "PhysicalDeviceSamplerFilterMinmaxProperties"sv;
	}
	case SamplerReductionModeCreateInfo: {
		return "SamplerReductionModeCreateInfo"sv;
	}
	case PhysicalDeviceGpaFeaturesAMD: {
		return "PhysicalDeviceGpaFeaturesAMD"sv;
	}
	case PhysicalDeviceGpaPropertiesAMD: {
		return "PhysicalDeviceGpaPropertiesAMD"sv;
	}
	case GpaSampleBeginInfoAMD: {
		return "GpaSampleBeginInfoAMD"sv;
	}
	case GpaSessionCreateInfoAMD: {
		return "GpaSessionCreateInfoAMD"sv;
	}
	case GpaDeviceClockModeInfoAMD: {
		return "GpaDeviceClockModeInfoAMD"sv;
	}
	case PhysicalDeviceGpaProperties2AMD: {
		return "PhysicalDeviceGpaProperties2AMD"sv;
	}
	case GpaDeviceGetClockInfoAMD: {
		return "GpaDeviceGetClockInfoAMD"sv;
	}
	case PhysicalDeviceShaderEnqueueFeaturesAMDX: {
		return "PhysicalDeviceShaderEnqueueFeaturesAMDX"sv;
	}
	case PhysicalDeviceShaderEnqueuePropertiesAMDX: {
		return "PhysicalDeviceShaderEnqueuePropertiesAMDX"sv;
	}
	case ExecutionGraphPipelineScratchSizeAMDX: {
		return "ExecutionGraphPipelineScratchSizeAMDX"sv;
	}
	case ExecutionGraphPipelineCreateInfoAMDX: {
		return "ExecutionGraphPipelineCreateInfoAMDX"sv;
	}
	case PipelineShaderStageNodeCreateInfoAMDX: {
		return "PipelineShaderStageNodeCreateInfoAMDX"sv;
	}
	case TexelBufferDescriptorInfoEXT: {
		return "TexelBufferDescriptorInfoEXT"sv;
	}
	case ImageDescriptorInfoEXT: {
		return "ImageDescriptorInfoEXT"sv;
	}
	case ResourceDescriptorInfoEXT: {
		return "ResourceDescriptorInfoEXT"sv;
	}
	case BindHeapInfoEXT: {
		return "BindHeapInfoEXT"sv;
	}
	case PushDataInfoEXT: {
		return "PushDataInfoEXT"sv;
	}
	case DescriptorSetAndBindingMappingEXT: {
		return "DescriptorSetAndBindingMappingEXT"sv;
	}
	case ShaderDescriptorSetAndBindingMappingInfoEXT: {
		return "ShaderDescriptorSetAndBindingMappingInfoEXT"sv;
	}
	case OpaqueCaptureDataCreateInfoEXT: {
		return "OpaqueCaptureDataCreateInfoEXT"sv;
	}
	case PhysicalDeviceDescriptorHeapPropertiesEXT: {
		return "PhysicalDeviceDescriptorHeapPropertiesEXT"sv;
	}
	case PhysicalDeviceDescriptorHeapFeaturesEXT: {
		return "PhysicalDeviceDescriptorHeapFeaturesEXT"sv;
	}
	case CommandBufferInheritanceDescriptorHeapInfoEXT: {
		return "CommandBufferInheritanceDescriptorHeapInfoEXT"sv;
	}
	case SamplerCustomBorderColorIndexCreateInfoEXT: {
		return "SamplerCustomBorderColorIndexCreateInfoEXT"sv;
	}
	case IndirectCommandsLayoutPushDataTokenNV: {
		return "IndirectCommandsLayoutPushDataTokenNV"sv;
	}
	case SubsampledImageFormatPropertiesEXT: {
		return "SubsampledImageFormatPropertiesEXT"sv;
	}
	case PhysicalDeviceDescriptorHeapTensorPropertiesARM: {
		return "PhysicalDeviceDescriptorHeapTensorPropertiesARM"sv;
	}
	case PhysicalDeviceInlineUniformBlockFeatures: {
		return "PhysicalDeviceInlineUniformBlockFeatures"sv;
	}
	case PhysicalDeviceInlineUniformBlockProperties: {
		return "PhysicalDeviceInlineUniformBlockProperties"sv;
	}
	case WriteDescriptorSetInlineUniformBlock: {
		return "WriteDescriptorSetInlineUniformBlock"sv;
	}
	case DescriptorPoolInlineUniformBlockCreateInfo: {
		return "DescriptorPoolInlineUniformBlockCreateInfo"sv;
	}
	case PhysicalDeviceShaderBfloat16FeaturesKHR: {
		return "PhysicalDeviceShaderBfloat16FeaturesKHR"sv;
	}
	case SampleLocationsInfoEXT: {
		return "SampleLocationsInfoEXT"sv;
	}
	case RenderPassSampleLocationsBeginInfoEXT: {
		return "RenderPassSampleLocationsBeginInfoEXT"sv;
	}
	case PipelineSampleLocationsStateCreateInfoEXT: {
		return "PipelineSampleLocationsStateCreateInfoEXT"sv;
	}
	case PhysicalDeviceSampleLocationsPropertiesEXT: {
		return "PhysicalDeviceSampleLocationsPropertiesEXT"sv;
	}
	case MultisamplePropertiesEXT: {
		return "MultisamplePropertiesEXT"sv;
	}
	case ProtectedSubmitInfo: {
		return "ProtectedSubmitInfo"sv;
	}
	case PhysicalDeviceProtectedMemoryFeatures: {
		return "PhysicalDeviceProtectedMemoryFeatures"sv;
	}
	case PhysicalDeviceProtectedMemoryProperties: {
		return "PhysicalDeviceProtectedMemoryProperties"sv;
	}
	case DeviceQueueInfo2: {
		return "DeviceQueueInfo2"sv;
	}
	case BufferMemoryRequirementsInfo2: {
		return "BufferMemoryRequirementsInfo2"sv;
	}
	case ImageMemoryRequirementsInfo2: {
		return "ImageMemoryRequirementsInfo2"sv;
	}
	case ImageSparseMemoryRequirementsInfo2: {
		return "ImageSparseMemoryRequirementsInfo2"sv;
	}
	case MemoryRequirements2: {
		return "MemoryRequirements2"sv;
	}
	case SparseImageMemoryRequirements2: {
		return "SparseImageMemoryRequirements2"sv;
	}
	case ImageFormatListCreateInfo: {
		return "ImageFormatListCreateInfo"sv;
	}
	case PhysicalDeviceBlendOperationAdvancedFeaturesEXT: {
		return "PhysicalDeviceBlendOperationAdvancedFeaturesEXT"sv;
	}
	case PhysicalDeviceBlendOperationAdvancedPropertiesEXT: {
		return "PhysicalDeviceBlendOperationAdvancedPropertiesEXT"sv;
	}
	case PipelineColorBlendAdvancedStateCreateInfoEXT: {
		return "PipelineColorBlendAdvancedStateCreateInfoEXT"sv;
	}
	case PipelineCoverageToColorStateCreateInfoNV: {
		return "PipelineCoverageToColorStateCreateInfoNV"sv;
	}
	case AccelerationStructureBuildGeometryInfoKHR: {
		return "AccelerationStructureBuildGeometryInfoKHR"sv;
	}
	case AccelerationStructureDeviceAddressInfoKHR: {
		return "AccelerationStructureDeviceAddressInfoKHR"sv;
	}
	case AccelerationStructureGeometryAabbsDataKHR: {
		return "AccelerationStructureGeometryAabbsDataKHR"sv;
	}
	case AccelerationStructureGeometryInstancesDataKHR: {
		return "AccelerationStructureGeometryInstancesDataKHR"sv;
	}
	case AccelerationStructureGeometryTrianglesDataKHR: {
		return "AccelerationStructureGeometryTrianglesDataKHR"sv;
	}
	case AccelerationStructureGeometryKHR: {
		return "AccelerationStructureGeometryKHR"sv;
	}
	case WriteDescriptorSetAccelerationStructureKHR: {
		return "WriteDescriptorSetAccelerationStructureKHR"sv;
	}
	case AccelerationStructureVersionInfoKHR: {
		return "AccelerationStructureVersionInfoKHR"sv;
	}
	case CopyAccelerationStructureInfoKHR: {
		return "CopyAccelerationStructureInfoKHR"sv;
	}
	case CopyAccelerationStructureToMemoryInfoKHR: {
		return "CopyAccelerationStructureToMemoryInfoKHR"sv;
	}
	case CopyMemoryToAccelerationStructureInfoKHR: {
		return "CopyMemoryToAccelerationStructureInfoKHR"sv;
	}
	case PhysicalDeviceAccelerationStructureFeaturesKHR: {
		return "PhysicalDeviceAccelerationStructureFeaturesKHR"sv;
	}
	case PhysicalDeviceAccelerationStructurePropertiesKHR: {
		return "PhysicalDeviceAccelerationStructurePropertiesKHR"sv;
	}
	case RayTracingPipelineCreateInfoKHR: {
		return "RayTracingPipelineCreateInfoKHR"sv;
	}
	case RayTracingShaderGroupCreateInfoKHR: {
		return "RayTracingShaderGroupCreateInfoKHR"sv;
	}
	case AccelerationStructureCreateInfoKHR: {
		return "AccelerationStructureCreateInfoKHR"sv;
	}
	case RayTracingPipelineInterfaceCreateInfoKHR: {
		return "RayTracingPipelineInterfaceCreateInfoKHR"sv;
	}
	case AccelerationStructureBuildSizesInfoKHR: {
		return "AccelerationStructureBuildSizesInfoKHR"sv;
	}
	case PipelineCoverageModulationStateCreateInfoNV: {
		return "PipelineCoverageModulationStateCreateInfoNV"sv;
	}
	case PhysicalDeviceShaderSmBuiltinsFeaturesNV: {
		return "PhysicalDeviceShaderSmBuiltinsFeaturesNV"sv;
	}
	case PhysicalDeviceShaderSmBuiltinsPropertiesNV: {
		return "PhysicalDeviceShaderSmBuiltinsPropertiesNV"sv;
	}
	case SamplerYcbcrConversionCreateInfo: {
		return "SamplerYcbcrConversionCreateInfo"sv;
	}
	case SamplerYcbcrConversionInfo: {
		return "SamplerYcbcrConversionInfo"sv;
	}
	case BindImagePlaneMemoryInfo: {
		return "BindImagePlaneMemoryInfo"sv;
	}
	case ImagePlaneMemoryRequirementsInfo: {
		return "ImagePlaneMemoryRequirementsInfo"sv;
	}
	case PhysicalDeviceSamplerYcbcrConversionFeatures: {
		return "PhysicalDeviceSamplerYcbcrConversionFeatures"sv;
	}
	case SamplerYcbcrConversionImageFormatProperties: {
		return "SamplerYcbcrConversionImageFormatProperties"sv;
	}
	case BindBufferMemoryInfo: {
		return "BindBufferMemoryInfo"sv;
	}
	case BindImageMemoryInfo: {
		return "BindImageMemoryInfo"sv;
	}
	case DrmFormatModifierPropertiesListEXT: {
		return "DrmFormatModifierPropertiesListEXT"sv;
	}
	case PhysicalDeviceImageDrmFormatModifierInfoEXT: {
		return "PhysicalDeviceImageDrmFormatModifierInfoEXT"sv;
	}
	case ImageDrmFormatModifierListCreateInfoEXT: {
		return "ImageDrmFormatModifierListCreateInfoEXT"sv;
	}
	case ImageDrmFormatModifierExplicitCreateInfoEXT: {
		return "ImageDrmFormatModifierExplicitCreateInfoEXT"sv;
	}
	case ImageDrmFormatModifierPropertiesEXT: {
		return "ImageDrmFormatModifierPropertiesEXT"sv;
	}
	case DrmFormatModifierPropertiesList2EXT: {
		return "DrmFormatModifierPropertiesList2EXT"sv;
	}
	case ValidationCacheCreateInfoEXT: {
		return "ValidationCacheCreateInfoEXT"sv;
	}
	case ShaderModuleValidationCacheCreateInfoEXT: {
		return "ShaderModuleValidationCacheCreateInfoEXT"sv;
	}
	case DescriptorSetLayoutBindingFlagsCreateInfo: {
		return "DescriptorSetLayoutBindingFlagsCreateInfo"sv;
	}
	case PhysicalDeviceDescriptorIndexingFeatures: {
		return "PhysicalDeviceDescriptorIndexingFeatures"sv;
	}
	case PhysicalDeviceDescriptorIndexingProperties: {
		return "PhysicalDeviceDescriptorIndexingProperties"sv;
	}
	case DescriptorSetVariableDescriptorCountAllocateInfo: {
		return "DescriptorSetVariableDescriptorCountAllocateInfo"sv;
	}
	case DescriptorSetVariableDescriptorCountLayoutSupport: {
		return "DescriptorSetVariableDescriptorCountLayoutSupport"sv;
	}
	case PhysicalDevicePortabilitySubsetFeaturesKHR: {
		return "PhysicalDevicePortabilitySubsetFeaturesKHR"sv;
	}
	case PhysicalDevicePortabilitySubsetPropertiesKHR: {
		return "PhysicalDevicePortabilitySubsetPropertiesKHR"sv;
	}
	case PipelineViewportShadingRateImageStateCreateInfoNV: {
		return "PipelineViewportShadingRateImageStateCreateInfoNV"sv;
	}
	case PhysicalDeviceShadingRateImageFeaturesNV: {
		return "PhysicalDeviceShadingRateImageFeaturesNV"sv;
	}
	case PhysicalDeviceShadingRateImagePropertiesNV: {
		return "PhysicalDeviceShadingRateImagePropertiesNV"sv;
	}
	case PipelineViewportCoarseSampleOrderStateCreateInfoNV: {
		return "PipelineViewportCoarseSampleOrderStateCreateInfoNV"sv;
	}
	case RayTracingPipelineCreateInfoNV: {
		return "RayTracingPipelineCreateInfoNV"sv;
	}
	case AccelerationStructureCreateInfoNV: {
		return "AccelerationStructureCreateInfoNV"sv;
	}
	case GeometryNV: {
		return "GeometryNV"sv;
	}
	case GeometryTrianglesNV: {
		return "GeometryTrianglesNV"sv;
	}
	case GeometryAabbNV: {
		return "GeometryAabbNV"sv;
	}
	case BindAccelerationStructureMemoryInfoNV: {
		return "BindAccelerationStructureMemoryInfoNV"sv;
	}
	case WriteDescriptorSetAccelerationStructureNV: {
		return "WriteDescriptorSetAccelerationStructureNV"sv;
	}
	case AccelerationStructureMemoryRequirementsInfoNV: {
		return "AccelerationStructureMemoryRequirementsInfoNV"sv;
	}
	case PhysicalDeviceRayTracingPropertiesNV: {
		return "PhysicalDeviceRayTracingPropertiesNV"sv;
	}
	case RayTracingShaderGroupCreateInfoNV: {
		return "RayTracingShaderGroupCreateInfoNV"sv;
	}
	case AccelerationStructureInfoNV: {
		return "AccelerationStructureInfoNV"sv;
	}
	case PhysicalDeviceRepresentativeFragmentTestFeaturesNV: {
		return "PhysicalDeviceRepresentativeFragmentTestFeaturesNV"sv;
	}
	case PipelineRepresentativeFragmentTestStateCreateInfoNV: {
		return "PipelineRepresentativeFragmentTestStateCreateInfoNV"sv;
	}
	case PhysicalDeviceMaintenance3Properties: {
		return "PhysicalDeviceMaintenance3Properties"sv;
	}
	case DescriptorSetLayoutSupport: {
		return "DescriptorSetLayoutSupport"sv;
	}
	case PhysicalDeviceImageViewImageFormatInfoEXT: {
		return "PhysicalDeviceImageViewImageFormatInfoEXT"sv;
	}
	case FilterCubicImageViewImageFormatPropertiesEXT: {
		return "FilterCubicImageViewImageFormatPropertiesEXT"sv;
	}
	case PhysicalDeviceCooperativeMatrixConversionFeaturesQCOM: {
		return "PhysicalDeviceCooperativeMatrixConversionFeaturesQCOM"sv;
	}
	case PhysicalDeviceElapsedTimerQueryFeaturesQCOM: {
		return "PhysicalDeviceElapsedTimerQueryFeaturesQCOM"sv;
	}
	case DeviceQueueGlobalPriorityCreateInfo: {
		return "DeviceQueueGlobalPriorityCreateInfo"sv;
	}
	case PhysicalDeviceShaderSubgroupExtendedTypesFeatures: {
		return "PhysicalDeviceShaderSubgroupExtendedTypesFeatures"sv;
	}
	case PhysicalDevice8BitStorageFeatures: {
		return "PhysicalDevice8BitStorageFeatures"sv;
	}
	case ImportMemoryHostPointerInfoEXT: {
		return "ImportMemoryHostPointerInfoEXT"sv;
	}
	case MemoryHostPointerPropertiesEXT: {
		return "MemoryHostPointerPropertiesEXT"sv;
	}
	case PhysicalDeviceExternalMemoryHostPropertiesEXT: {
		return "PhysicalDeviceExternalMemoryHostPropertiesEXT"sv;
	}
	case PhysicalDeviceShaderAtomicInt64Features: {
		return "PhysicalDeviceShaderAtomicInt64Features"sv;
	}
	case PhysicalDeviceShaderClockFeaturesKHR: {
		return "PhysicalDeviceShaderClockFeaturesKHR"sv;
	}
	case PipelineCompilerControlCreateInfoAMD: {
		return "PipelineCompilerControlCreateInfoAMD"sv;
	}
	case CalibratedTimestampInfoKHR: {
		return "CalibratedTimestampInfoKHR"sv;
	}
	case PhysicalDeviceShaderCorePropertiesAMD: {
		return "PhysicalDeviceShaderCorePropertiesAMD"sv;
	}
	case VideoDecodeH265CapabilitiesKHR: {
		return "VideoDecodeH265CapabilitiesKHR"sv;
	}
	case VideoDecodeH265SessionParametersCreateInfoKHR: {
		return "VideoDecodeH265SessionParametersCreateInfoKHR"sv;
	}
	case VideoDecodeH265SessionParametersAddInfoKHR: {
		return "VideoDecodeH265SessionParametersAddInfoKHR"sv;
	}
	case VideoDecodeH265ProfileInfoKHR: {
		return "VideoDecodeH265ProfileInfoKHR"sv;
	}
	case VideoDecodeH265PictureInfoKHR: {
		return "VideoDecodeH265PictureInfoKHR"sv;
	}
	case VideoDecodeH265DpbSlotInfoKHR: {
		return "VideoDecodeH265DpbSlotInfoKHR"sv;
	}
	case DeviceMemoryOverallocationCreateInfoAMD: {
		return "DeviceMemoryOverallocationCreateInfoAMD"sv;
	}
	case PhysicalDeviceVertexAttributeDivisorPropertiesEXT: {
		return "PhysicalDeviceVertexAttributeDivisorPropertiesEXT"sv;
	}
	case PipelineVertexInputDivisorStateCreateInfo: {
		return "PipelineVertexInputDivisorStateCreateInfo"sv;
	}
	case PhysicalDeviceVertexAttributeDivisorFeatures: {
		return "PhysicalDeviceVertexAttributeDivisorFeatures"sv;
	}
	case PresentFrameTokenGGP: {
		return "PresentFrameTokenGGP"sv;
	}
	case PipelineCreationFeedbackCreateInfo: {
		return "PipelineCreationFeedbackCreateInfo"sv;
	}
	case PhysicalDeviceDriverProperties: {
		return "PhysicalDeviceDriverProperties"sv;
	}
	case PhysicalDeviceFloatControlsProperties: {
		return "PhysicalDeviceFloatControlsProperties"sv;
	}
	case PhysicalDeviceDepthStencilResolveProperties: {
		return "PhysicalDeviceDepthStencilResolveProperties"sv;
	}
	case SubpassDescriptionDepthStencilResolve: {
		return "SubpassDescriptionDepthStencilResolve"sv;
	}
	case PhysicalDeviceComputeShaderDerivativesFeaturesKHR: {
		return "PhysicalDeviceComputeShaderDerivativesFeaturesKHR"sv;
	}
	case PhysicalDeviceMeshShaderFeaturesNV: {
		return "PhysicalDeviceMeshShaderFeaturesNV"sv;
	}
	case PhysicalDeviceMeshShaderPropertiesNV: {
		return "PhysicalDeviceMeshShaderPropertiesNV"sv;
	}
	case PhysicalDeviceFragmentShaderBarycentricFeaturesKHR: {
		return "PhysicalDeviceFragmentShaderBarycentricFeaturesKHR"sv;
	}
	case PhysicalDeviceShaderImageFootprintFeaturesNV: {
		return "PhysicalDeviceShaderImageFootprintFeaturesNV"sv;
	}
	case PipelineViewportExclusiveScissorStateCreateInfoNV: {
		return "PipelineViewportExclusiveScissorStateCreateInfoNV"sv;
	}
	case PhysicalDeviceExclusiveScissorFeaturesNV: {
		return "PhysicalDeviceExclusiveScissorFeaturesNV"sv;
	}
	case CheckpointDataNV: {
		return "CheckpointDataNV"sv;
	}
	case QueueFamilyCheckpointPropertiesNV: {
		return "QueueFamilyCheckpointPropertiesNV"sv;
	}
	case PhysicalDeviceTimelineSemaphoreFeatures: {
		return "PhysicalDeviceTimelineSemaphoreFeatures"sv;
	}
	case PhysicalDeviceTimelineSemaphoreProperties: {
		return "PhysicalDeviceTimelineSemaphoreProperties"sv;
	}
	case SemaphoreTypeCreateInfo: {
		return "SemaphoreTypeCreateInfo"sv;
	}
	case TimelineSemaphoreSubmitInfo: {
		return "TimelineSemaphoreSubmitInfo"sv;
	}
	case SemaphoreWaitInfo: {
		return "SemaphoreWaitInfo"sv;
	}
	case SemaphoreSignalInfo: {
		return "SemaphoreSignalInfo"sv;
	}
	case PhysicalDevicePresentTimingFeaturesEXT: {
		return "PhysicalDevicePresentTimingFeaturesEXT"sv;
	}
	case SwapchainTimingPropertiesEXT: {
		return "SwapchainTimingPropertiesEXT"sv;
	}
	case SwapchainTimeDomainPropertiesEXT: {
		return "SwapchainTimeDomainPropertiesEXT"sv;
	}
	case PresentTimingsInfoEXT: {
		return "PresentTimingsInfoEXT"sv;
	}
	case PresentTimingInfoEXT: {
		return "PresentTimingInfoEXT"sv;
	}
	case PastPresentationTimingInfoEXT: {
		return "PastPresentationTimingInfoEXT"sv;
	}
	case PastPresentationTimingPropertiesEXT: {
		return "PastPresentationTimingPropertiesEXT"sv;
	}
	case PastPresentationTimingEXT: {
		return "PastPresentationTimingEXT"sv;
	}
	case PresentTimingSurfaceCapabilitiesEXT: {
		return "PresentTimingSurfaceCapabilitiesEXT"sv;
	}
	case SwapchainCalibratedTimestampInfoEXT: {
		return "SwapchainCalibratedTimestampInfoEXT"sv;
	}
	case PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL: {
		return "PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL"sv;
	}
	case QueryPoolPerformanceQueryCreateInfoINTEL: {
		return "QueryPoolPerformanceQueryCreateInfoINTEL"sv;
	}
	case InitializePerformanceApiInfoINTEL: {
		return "InitializePerformanceApiInfoINTEL"sv;
	}
	case PerformanceMarkerInfoINTEL: {
		return "PerformanceMarkerInfoINTEL"sv;
	}
	case PerformanceStreamMarkerInfoINTEL: {
		return "PerformanceStreamMarkerInfoINTEL"sv;
	}
	case PerformanceOverrideInfoINTEL: {
		return "PerformanceOverrideInfoINTEL"sv;
	}
	case PerformanceConfigurationAcquireInfoINTEL: {
		return "PerformanceConfigurationAcquireInfoINTEL"sv;
	}
	case PhysicalDeviceVulkanMemoryModelFeatures: {
		return "PhysicalDeviceVulkanMemoryModelFeatures"sv;
	}
	case PhysicalDevicePciBusInfoPropertiesEXT: {
		return "PhysicalDevicePciBusInfoPropertiesEXT"sv;
	}
	case DisplayNativeHdrSurfaceCapabilitiesAMD: {
		return "DisplayNativeHdrSurfaceCapabilitiesAMD"sv;
	}
	case SwapchainDisplayNativeHdrCreateInfoAMD: {
		return "SwapchainDisplayNativeHdrCreateInfoAMD"sv;
	}
	case ImagepipeSurfaceCreateInfoFUCHSIA: {
		return "ImagepipeSurfaceCreateInfoFUCHSIA"sv;
	}
	case PhysicalDeviceShaderTerminateInvocationFeatures: {
		return "PhysicalDeviceShaderTerminateInvocationFeatures"sv;
	}
	case MetalSurfaceCreateInfoEXT: {
		return "MetalSurfaceCreateInfoEXT"sv;
	}
	case PhysicalDeviceFragmentDensityMapFeaturesEXT: {
		return "PhysicalDeviceFragmentDensityMapFeaturesEXT"sv;
	}
	case PhysicalDeviceFragmentDensityMapPropertiesEXT: {
		return "PhysicalDeviceFragmentDensityMapPropertiesEXT"sv;
	}
	case RenderPassFragmentDensityMapCreateInfoEXT: {
		return "RenderPassFragmentDensityMapCreateInfoEXT"sv;
	}
	case PhysicalDeviceScalarBlockLayoutFeatures: {
		return "PhysicalDeviceScalarBlockLayoutFeatures"sv;
	}
	case PhysicalDeviceSubgroupSizeControlProperties: {
		return "PhysicalDeviceSubgroupSizeControlProperties"sv;
	}
	case PipelineShaderStageRequiredSubgroupSizeCreateInfo: {
		return "PipelineShaderStageRequiredSubgroupSizeCreateInfo"sv;
	}
	case PhysicalDeviceSubgroupSizeControlFeatures: {
		return "PhysicalDeviceSubgroupSizeControlFeatures"sv;
	}
	case FragmentShadingRateAttachmentInfoKHR: {
		return "FragmentShadingRateAttachmentInfoKHR"sv;
	}
	case PipelineFragmentShadingRateStateCreateInfoKHR: {
		return "PipelineFragmentShadingRateStateCreateInfoKHR"sv;
	}
	case PhysicalDeviceFragmentShadingRatePropertiesKHR: {
		return "PhysicalDeviceFragmentShadingRatePropertiesKHR"sv;
	}
	case PhysicalDeviceFragmentShadingRateFeaturesKHR: {
		return "PhysicalDeviceFragmentShadingRateFeaturesKHR"sv;
	}
	case PhysicalDeviceFragmentShadingRateKHR: {
		return "PhysicalDeviceFragmentShadingRateKHR"sv;
	}
	case PhysicalDeviceShaderCoreProperties2AMD: {
		return "PhysicalDeviceShaderCoreProperties2AMD"sv;
	}
	case PhysicalDeviceCoherentMemoryFeaturesAMD: {
		return "PhysicalDeviceCoherentMemoryFeaturesAMD"sv;
	}
	case PhysicalDeviceShaderConstantDataFeaturesKHR: {
		return "PhysicalDeviceShaderConstantDataFeaturesKHR"sv;
	}
	case PhysicalDeviceDynamicRenderingLocalReadFeatures: {
		return "PhysicalDeviceDynamicRenderingLocalReadFeatures"sv;
	}
	case RenderingAttachmentLocationInfo: {
		return "RenderingAttachmentLocationInfo"sv;
	}
	case RenderingInputAttachmentIndexInfo: {
		return "RenderingInputAttachmentIndexInfo"sv;
	}
	case PhysicalDeviceShaderAbortFeaturesKHR: {
		return "PhysicalDeviceShaderAbortFeaturesKHR"sv;
	}
	case DeviceFaultShaderAbortMessageInfoKHR: {
		return "DeviceFaultShaderAbortMessageInfoKHR"sv;
	}
	case PhysicalDeviceShaderAbortPropertiesKHR: {
		return "PhysicalDeviceShaderAbortPropertiesKHR"sv;
	}
	case PhysicalDeviceShaderImageAtomicInt64FeaturesEXT: {
		return "PhysicalDeviceShaderImageAtomicInt64FeaturesEXT"sv;
	}
	case PhysicalDeviceShaderQuadControlFeaturesKHR: {
		return "PhysicalDeviceShaderQuadControlFeaturesKHR"sv;
	}
	case PhysicalDeviceMemoryBudgetPropertiesEXT: {
		return "PhysicalDeviceMemoryBudgetPropertiesEXT"sv;
	}
	case PhysicalDeviceMemoryPriorityFeaturesEXT: {
		return "PhysicalDeviceMemoryPriorityFeaturesEXT"sv;
	}
	case MemoryPriorityAllocateInfoEXT: {
		return "MemoryPriorityAllocateInfoEXT"sv;
	}
	case SurfaceProtectedCapabilitiesKHR: {
		return "SurfaceProtectedCapabilitiesKHR"sv;
	}
	case PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV: {
		return "PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV"sv;
	}
	case PhysicalDeviceSeparateDepthStencilLayoutsFeatures: {
		return "PhysicalDeviceSeparateDepthStencilLayoutsFeatures"sv;
	}
	case AttachmentReferenceStencilLayout: {
		return "AttachmentReferenceStencilLayout"sv;
	}
	case AttachmentDescriptionStencilLayout: {
		return "AttachmentDescriptionStencilLayout"sv;
	}
	case PhysicalDeviceBufferDeviceAddressFeaturesEXT: {
		return "PhysicalDeviceBufferDeviceAddressFeaturesEXT"sv;
	}
	case BufferDeviceAddressInfo: {
		return "BufferDeviceAddressInfo"sv;
	}
	case BufferDeviceAddressCreateInfoEXT: {
		return "BufferDeviceAddressCreateInfoEXT"sv;
	}
	case PhysicalDeviceToolProperties: {
		return "PhysicalDeviceToolProperties"sv;
	}
	case ImageStencilUsageCreateInfo: {
		return "ImageStencilUsageCreateInfo"sv;
	}
	case ValidationFeaturesEXT: {
		return "ValidationFeaturesEXT"sv;
	}
	case PhysicalDevicePresentWaitFeaturesKHR: {
		return "PhysicalDevicePresentWaitFeaturesKHR"sv;
	}
	case PhysicalDeviceCooperativeMatrixFeaturesNV: {
		return "PhysicalDeviceCooperativeMatrixFeaturesNV"sv;
	}
	case CooperativeMatrixPropertiesNV: {
		return "CooperativeMatrixPropertiesNV"sv;
	}
	case PhysicalDeviceCooperativeMatrixPropertiesNV: {
		return "PhysicalDeviceCooperativeMatrixPropertiesNV"sv;
	}
	case PhysicalDeviceCoverageReductionModeFeaturesNV: {
		return "PhysicalDeviceCoverageReductionModeFeaturesNV"sv;
	}
	case PipelineCoverageReductionStateCreateInfoNV: {
		return "PipelineCoverageReductionStateCreateInfoNV"sv;
	}
	case FramebufferMixedSamplesCombinationNV: {
		return "FramebufferMixedSamplesCombinationNV"sv;
	}
	case PhysicalDeviceFragmentShaderInterlockFeaturesEXT: {
		return "PhysicalDeviceFragmentShaderInterlockFeaturesEXT"sv;
	}
	case PhysicalDeviceYcbcrImageArraysFeaturesEXT: {
		return "PhysicalDeviceYcbcrImageArraysFeaturesEXT"sv;
	}
	case PhysicalDeviceUniformBufferStandardLayoutFeatures: {
		return "PhysicalDeviceUniformBufferStandardLayoutFeatures"sv;
	}
	case PhysicalDeviceProvokingVertexFeaturesEXT: {
		return "PhysicalDeviceProvokingVertexFeaturesEXT"sv;
	}
	case PipelineRasterizationProvokingVertexStateCreateInfoEXT: {
		return "PipelineRasterizationProvokingVertexStateCreateInfoEXT"sv;
	}
	case PhysicalDeviceProvokingVertexPropertiesEXT: {
		return "PhysicalDeviceProvokingVertexPropertiesEXT"sv;
	}
	case SurfaceFullScreenExclusiveInfoEXT: {
		return "SurfaceFullScreenExclusiveInfoEXT"sv;
	}
	case SurfaceFullScreenExclusiveWin32InfoEXT: {
		return "SurfaceFullScreenExclusiveWin32InfoEXT"sv;
	}
	case SurfaceCapabilitiesFullScreenExclusiveEXT: {
		return "SurfaceCapabilitiesFullScreenExclusiveEXT"sv;
	}
	case HeadlessSurfaceCreateInfoEXT: {
		return "HeadlessSurfaceCreateInfoEXT"sv;
	}
	case PhysicalDeviceBufferDeviceAddressFeatures: {
		return "PhysicalDeviceBufferDeviceAddressFeatures"sv;
	}
	case BufferOpaqueCaptureAddressCreateInfo: {
		return "BufferOpaqueCaptureAddressCreateInfo"sv;
	}
	case MemoryOpaqueCaptureAddressAllocateInfo: {
		return "MemoryOpaqueCaptureAddressAllocateInfo"sv;
	}
	case DeviceMemoryOpaqueCaptureAddressInfo: {
		return "DeviceMemoryOpaqueCaptureAddressInfo"sv;
	}
	case PhysicalDeviceLineRasterizationFeatures: {
		return "PhysicalDeviceLineRasterizationFeatures"sv;
	}
	case PipelineRasterizationLineStateCreateInfo: {
		return "PipelineRasterizationLineStateCreateInfo"sv;
	}
	case PhysicalDeviceLineRasterizationProperties: {
		return "PhysicalDeviceLineRasterizationProperties"sv;
	}
	case PhysicalDeviceShaderAtomicFloatFeaturesEXT: {
		return "PhysicalDeviceShaderAtomicFloatFeaturesEXT"sv;
	}
	case PhysicalDeviceHostQueryResetFeatures: {
		return "PhysicalDeviceHostQueryResetFeatures"sv;
	}
	case PhysicalDeviceIndexTypeUint8Features: {
		return "PhysicalDeviceIndexTypeUint8Features"sv;
	}
	case PhysicalDeviceExtendedDynamicStateFeaturesEXT: {
		return "PhysicalDeviceExtendedDynamicStateFeaturesEXT"sv;
	}
	case PhysicalDevicePipelineExecutablePropertiesFeaturesKHR: {
		return "PhysicalDevicePipelineExecutablePropertiesFeaturesKHR"sv;
	}
	case PipelineInfoKHR: {
		return "PipelineInfoKHR"sv;
	}
	case PipelineExecutablePropertiesKHR: {
		return "PipelineExecutablePropertiesKHR"sv;
	}
	case PipelineExecutableInfoKHR: {
		return "PipelineExecutableInfoKHR"sv;
	}
	case PipelineExecutableStatisticKHR: {
		return "PipelineExecutableStatisticKHR"sv;
	}
	case PipelineExecutableInternalRepresentationKHR: {
		return "PipelineExecutableInternalRepresentationKHR"sv;
	}
	case PhysicalDeviceHostImageCopyFeatures: {
		return "PhysicalDeviceHostImageCopyFeatures"sv;
	}
	case PhysicalDeviceHostImageCopyProperties: {
		return "PhysicalDeviceHostImageCopyProperties"sv;
	}
	case MemoryToImageCopy: {
		return "MemoryToImageCopy"sv;
	}
	case ImageToMemoryCopy: {
		return "ImageToMemoryCopy"sv;
	}
	case CopyImageToMemoryInfo: {
		return "CopyImageToMemoryInfo"sv;
	}
	case CopyMemoryToImageInfo: {
		return "CopyMemoryToImageInfo"sv;
	}
	case HostImageLayoutTransitionInfo: {
		return "HostImageLayoutTransitionInfo"sv;
	}
	case CopyImageToImageInfo: {
		return "CopyImageToImageInfo"sv;
	}
	case SubresourceHostMemcpySize: {
		return "SubresourceHostMemcpySize"sv;
	}
	case HostImageCopyDevicePerformanceQuery: {
		return "HostImageCopyDevicePerformanceQuery"sv;
	}
	case MemoryMapInfo: {
		return "MemoryMapInfo"sv;
	}
	case MemoryUnmapInfo: {
		return "MemoryUnmapInfo"sv;
	}
	case PhysicalDeviceMapMemoryPlacedFeaturesEXT: {
		return "PhysicalDeviceMapMemoryPlacedFeaturesEXT"sv;
	}
	case PhysicalDeviceMapMemoryPlacedPropertiesEXT: {
		return "PhysicalDeviceMapMemoryPlacedPropertiesEXT"sv;
	}
	case MemoryMapPlacedInfoEXT: {
		return "MemoryMapPlacedInfoEXT"sv;
	}
	case PhysicalDeviceShaderAtomicFloat2FeaturesEXT: {
		return "PhysicalDeviceShaderAtomicFloat2FeaturesEXT"sv;
	}
	case SurfacePresentModeKHR: {
		return "SurfacePresentModeKHR"sv;
	}
	case SurfacePresentScalingCapabilitiesKHR: {
		return "SurfacePresentScalingCapabilitiesKHR"sv;
	}
	case SurfacePresentModeCompatibilityKHR: {
		return "SurfacePresentModeCompatibilityKHR"sv;
	}
	case PhysicalDeviceSwapchainMaintenance1FeaturesKHR: {
		return "PhysicalDeviceSwapchainMaintenance1FeaturesKHR"sv;
	}
	case SwapchainPresentFenceInfoKHR: {
		return "SwapchainPresentFenceInfoKHR"sv;
	}
	case SwapchainPresentModesCreateInfoKHR: {
		return "SwapchainPresentModesCreateInfoKHR"sv;
	}
	case SwapchainPresentModeInfoKHR: {
		return "SwapchainPresentModeInfoKHR"sv;
	}
	case SwapchainPresentScalingCreateInfoKHR: {
		return "SwapchainPresentScalingCreateInfoKHR"sv;
	}
	case ReleaseSwapchainImagesInfoKHR: {
		return "ReleaseSwapchainImagesInfoKHR"sv;
	}
	case PhysicalDeviceShaderDemoteToHelperInvocationFeatures: {
		return "PhysicalDeviceShaderDemoteToHelperInvocationFeatures"sv;
	}
	case PhysicalDeviceDeviceGeneratedCommandsPropertiesNV: {
		return "PhysicalDeviceDeviceGeneratedCommandsPropertiesNV"sv;
	}
	case GraphicsShaderGroupCreateInfoNV: {
		return "GraphicsShaderGroupCreateInfoNV"sv;
	}
	case GraphicsPipelineShaderGroupsCreateInfoNV: {
		return "GraphicsPipelineShaderGroupsCreateInfoNV"sv;
	}
	case IndirectCommandsLayoutTokenNV: {
		return "IndirectCommandsLayoutTokenNV"sv;
	}
	case IndirectCommandsLayoutCreateInfoNV: {
		return "IndirectCommandsLayoutCreateInfoNV"sv;
	}
	case GeneratedCommandsInfoNV: {
		return "GeneratedCommandsInfoNV"sv;
	}
	case GeneratedCommandsMemoryRequirementsInfoNV: {
		return "GeneratedCommandsMemoryRequirementsInfoNV"sv;
	}
	case PhysicalDeviceDeviceGeneratedCommandsFeaturesNV: {
		return "PhysicalDeviceDeviceGeneratedCommandsFeaturesNV"sv;
	}
	case PhysicalDeviceInheritedViewportScissorFeaturesNV: {
		return "PhysicalDeviceInheritedViewportScissorFeaturesNV"sv;
	}
	case CommandBufferInheritanceViewportScissorInfoNV: {
		return "CommandBufferInheritanceViewportScissorInfoNV"sv;
	}
	case PhysicalDeviceShaderIntegerDotProductFeatures: {
		return "PhysicalDeviceShaderIntegerDotProductFeatures"sv;
	}
	case PhysicalDeviceShaderIntegerDotProductProperties: {
		return "PhysicalDeviceShaderIntegerDotProductProperties"sv;
	}
	case PhysicalDeviceTexelBufferAlignmentFeaturesEXT: {
		return "PhysicalDeviceTexelBufferAlignmentFeaturesEXT"sv;
	}
	case PhysicalDeviceTexelBufferAlignmentProperties: {
		return "PhysicalDeviceTexelBufferAlignmentProperties"sv;
	}
	case CommandBufferInheritanceRenderPassTransformInfoQCOM: {
		return "CommandBufferInheritanceRenderPassTransformInfoQCOM"sv;
	}
	case RenderPassTransformBeginInfoQCOM: {
		return "RenderPassTransformBeginInfoQCOM"sv;
	}
	case PhysicalDeviceDepthBiasControlFeaturesEXT: {
		return "PhysicalDeviceDepthBiasControlFeaturesEXT"sv;
	}
	case DepthBiasInfoEXT: {
		return "DepthBiasInfoEXT"sv;
	}
	case DepthBiasRepresentationInfoEXT: {
		return "DepthBiasRepresentationInfoEXT"sv;
	}
	case PhysicalDeviceDeviceMemoryReportFeaturesEXT: {
		return "PhysicalDeviceDeviceMemoryReportFeaturesEXT"sv;
	}
	case DeviceDeviceMemoryReportCreateInfoEXT: {
		return "DeviceDeviceMemoryReportCreateInfoEXT"sv;
	}
	case DeviceMemoryReportCallbackDataEXT: {
		return "DeviceMemoryReportCallbackDataEXT"sv;
	}
	case PhysicalDeviceRobustness2FeaturesKHR: {
		return "PhysicalDeviceRobustness2FeaturesKHR"sv;
	}
	case PhysicalDeviceRobustness2PropertiesKHR: {
		return "PhysicalDeviceRobustness2PropertiesKHR"sv;
	}
	case SamplerCustomBorderColorCreateInfoEXT: {
		return "SamplerCustomBorderColorCreateInfoEXT"sv;
	}
	case PhysicalDeviceCustomBorderColorPropertiesEXT: {
		return "PhysicalDeviceCustomBorderColorPropertiesEXT"sv;
	}
	case PhysicalDeviceCustomBorderColorFeaturesEXT: {
		return "PhysicalDeviceCustomBorderColorFeaturesEXT"sv;
	}
	case PhysicalDeviceTextureCompressionAstc3DFeaturesEXT: {
		return "PhysicalDeviceTextureCompressionAstc3DFeaturesEXT"sv;
	}
	case PipelineLibraryCreateInfoKHR: {
		return "PipelineLibraryCreateInfoKHR"sv;
	}
	case PhysicalDevicePresentBarrierFeaturesNV: {
		return "PhysicalDevicePresentBarrierFeaturesNV"sv;
	}
	case SurfaceCapabilitiesPresentBarrierNV: {
		return "SurfaceCapabilitiesPresentBarrierNV"sv;
	}
	case SwapchainPresentBarrierCreateInfoNV: {
		return "SwapchainPresentBarrierCreateInfoNV"sv;
	}
	case PresentIdKHR: {
		return "PresentIdKHR"sv;
	}
	case PhysicalDevicePresentIdFeaturesKHR: {
		return "PhysicalDevicePresentIdFeaturesKHR"sv;
	}
	case PhysicalDevicePrivateDataFeatures: {
		return "PhysicalDevicePrivateDataFeatures"sv;
	}
	case DevicePrivateDataCreateInfo: {
		return "DevicePrivateDataCreateInfo"sv;
	}
	case PrivateDataSlotCreateInfo: {
		return "PrivateDataSlotCreateInfo"sv;
	}
	case PhysicalDevicePipelineCreationCacheControlFeatures: {
		return "PhysicalDevicePipelineCreationCacheControlFeatures"sv;
	}
	case VideoEncodeInfoKHR: {
		return "VideoEncodeInfoKHR"sv;
	}
	case VideoEncodeRateControlInfoKHR: {
		return "VideoEncodeRateControlInfoKHR"sv;
	}
	case VideoEncodeRateControlLayerInfoKHR: {
		return "VideoEncodeRateControlLayerInfoKHR"sv;
	}
	case VideoEncodeCapabilitiesKHR: {
		return "VideoEncodeCapabilitiesKHR"sv;
	}
	case VideoEncodeUsageInfoKHR: {
		return "VideoEncodeUsageInfoKHR"sv;
	}
	case QueryPoolVideoEncodeFeedbackCreateInfoKHR: {
		return "QueryPoolVideoEncodeFeedbackCreateInfoKHR"sv;
	}
	case PhysicalDeviceVideoEncodeQualityLevelInfoKHR: {
		return "PhysicalDeviceVideoEncodeQualityLevelInfoKHR"sv;
	}
	case VideoEncodeQualityLevelPropertiesKHR: {
		return "VideoEncodeQualityLevelPropertiesKHR"sv;
	}
	case VideoEncodeQualityLevelInfoKHR: {
		return "VideoEncodeQualityLevelInfoKHR"sv;
	}
	case VideoEncodeSessionParametersGetInfoKHR: {
		return "VideoEncodeSessionParametersGetInfoKHR"sv;
	}
	case VideoEncodeSessionParametersFeedbackInfoKHR: {
		return "VideoEncodeSessionParametersFeedbackInfoKHR"sv;
	}
	case PhysicalDeviceDiagnosticsConfigFeaturesNV: {
		return "PhysicalDeviceDiagnosticsConfigFeaturesNV"sv;
	}
	case DeviceDiagnosticsConfigCreateInfoNV: {
		return "DeviceDiagnosticsConfigCreateInfoNV"sv;
	}
	case PerfHintInfoQCOM: {
		return "PerfHintInfoQCOM"sv;
	}
	case PhysicalDeviceQueuePerfHintFeaturesQCOM: {
		return "PhysicalDeviceQueuePerfHintFeaturesQCOM"sv;
	}
	case PhysicalDeviceQueuePerfHintPropertiesQCOM: {
		return "PhysicalDeviceQueuePerfHintPropertiesQCOM"sv;
	}
	case PhysicalDeviceImageProcessing3FeaturesQCOM: {
		return "PhysicalDeviceImageProcessing3FeaturesQCOM"sv;
	}
	case PhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM: {
		return "PhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM"sv;
	}
	case PhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM: {
		return "PhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM"sv;
	}
	case PhysicalDeviceShaderSplitBarrierFeaturesEXT: {
		return "PhysicalDeviceShaderSplitBarrierFeaturesEXT"sv;
	}
	case PhysicalDeviceShaderSplitBarrierPropertiesEXT: {
		return "PhysicalDeviceShaderSplitBarrierPropertiesEXT"sv;
	}
	case CudaModuleCreateInfoNV: {
		return "CudaModuleCreateInfoNV"sv;
	}
	case CudaFunctionCreateInfoNV: {
		return "CudaFunctionCreateInfoNV"sv;
	}
	case CudaLaunchInfoNV: {
		return "CudaLaunchInfoNV"sv;
	}
	case PhysicalDeviceCudaKernelLaunchFeaturesNV: {
		return "PhysicalDeviceCudaKernelLaunchFeaturesNV"sv;
	}
	case PhysicalDeviceCudaKernelLaunchPropertiesNV: {
		return "PhysicalDeviceCudaKernelLaunchPropertiesNV"sv;
	}
	case PhysicalDeviceTileShadingFeaturesQCOM: {
		return "PhysicalDeviceTileShadingFeaturesQCOM"sv;
	}
	case PhysicalDeviceTileShadingPropertiesQCOM: {
		return "PhysicalDeviceTileShadingPropertiesQCOM"sv;
	}
	case RenderPassTileShadingCreateInfoQCOM: {
		return "RenderPassTileShadingCreateInfoQCOM"sv;
	}
	case PerTileBeginInfoQCOM: {
		return "PerTileBeginInfoQCOM"sv;
	}
	case PerTileEndInfoQCOM: {
		return "PerTileEndInfoQCOM"sv;
	}
	case DispatchTileInfoQCOM: {
		return "DispatchTileInfoQCOM"sv;
	}
	case QueryLowLatencySupportNV: {
		return "QueryLowLatencySupportNV"sv;
	}
	case ExportMetalObjectCreateInfoEXT: {
		return "ExportMetalObjectCreateInfoEXT"sv;
	}
	case ExportMetalObjectsInfoEXT: {
		return "ExportMetalObjectsInfoEXT"sv;
	}
	case ExportMetalDeviceInfoEXT: {
		return "ExportMetalDeviceInfoEXT"sv;
	}
	case ExportMetalCommandQueueInfoEXT: {
		return "ExportMetalCommandQueueInfoEXT"sv;
	}
	case ExportMetalBufferInfoEXT: {
		return "ExportMetalBufferInfoEXT"sv;
	}
	case ImportMetalBufferInfoEXT: {
		return "ImportMetalBufferInfoEXT"sv;
	}
	case ExportMetalTextureInfoEXT: {
		return "ExportMetalTextureInfoEXT"sv;
	}
	case ImportMetalTextureInfoEXT: {
		return "ImportMetalTextureInfoEXT"sv;
	}
	case ExportMetalIoSurfaceInfoEXT: {
		return "ExportMetalIoSurfaceInfoEXT"sv;
	}
	case ImportMetalIoSurfaceInfoEXT: {
		return "ImportMetalIoSurfaceInfoEXT"sv;
	}
	case ExportMetalSharedEventInfoEXT: {
		return "ExportMetalSharedEventInfoEXT"sv;
	}
	case ImportMetalSharedEventInfoEXT: {
		return "ImportMetalSharedEventInfoEXT"sv;
	}
	case MemoryBarrier2: {
		return "MemoryBarrier2"sv;
	}
	case BufferMemoryBarrier2: {
		return "BufferMemoryBarrier2"sv;
	}
	case ImageMemoryBarrier2: {
		return "ImageMemoryBarrier2"sv;
	}
	case DependencyInfo: {
		return "DependencyInfo"sv;
	}
	case SubmitInfo2: {
		return "SubmitInfo2"sv;
	}
	case SemaphoreSubmitInfo: {
		return "SemaphoreSubmitInfo"sv;
	}
	case CommandBufferSubmitInfo: {
		return "CommandBufferSubmitInfo"sv;
	}
	case PhysicalDeviceSynchronization2Features: {
		return "PhysicalDeviceSynchronization2Features"sv;
	}
	case QueueFamilyCheckpointProperties2NV: {
		return "QueueFamilyCheckpointProperties2NV"sv;
	}
	case CheckpointData2NV: {
		return "CheckpointData2NV"sv;
	}
	case PhysicalDeviceDescriptorBufferPropertiesEXT: {
		return "PhysicalDeviceDescriptorBufferPropertiesEXT"sv;
	}
	case PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT: {
		return "PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT"sv;
	}
	case PhysicalDeviceDescriptorBufferFeaturesEXT: {
		return "PhysicalDeviceDescriptorBufferFeaturesEXT"sv;
	}
	case DescriptorAddressInfoEXT: {
		return "DescriptorAddressInfoEXT"sv;
	}
	case DescriptorGetInfoEXT: {
		return "DescriptorGetInfoEXT"sv;
	}
	case BufferCaptureDescriptorDataInfoEXT: {
		return "BufferCaptureDescriptorDataInfoEXT"sv;
	}
	case ImageCaptureDescriptorDataInfoEXT: {
		return "ImageCaptureDescriptorDataInfoEXT"sv;
	}
	case ImageViewCaptureDescriptorDataInfoEXT: {
		return "ImageViewCaptureDescriptorDataInfoEXT"sv;
	}
	case SamplerCaptureDescriptorDataInfoEXT: {
		return "SamplerCaptureDescriptorDataInfoEXT"sv;
	}
	case AccelerationStructureCaptureDescriptorDataInfoEXT: {
		return "AccelerationStructureCaptureDescriptorDataInfoEXT"sv;
	}
	case OpaqueCaptureDescriptorDataCreateInfoEXT: {
		return "OpaqueCaptureDescriptorDataCreateInfoEXT"sv;
	}
	case DescriptorBufferBindingInfoEXT: {
		return "DescriptorBufferBindingInfoEXT"sv;
	}
	case DescriptorBufferBindingPushDescriptorBufferHandleEXT: {
		return "DescriptorBufferBindingPushDescriptorBufferHandleEXT"sv;
	}
	case DeviceMemoryCopyKHR: {
		return "DeviceMemoryCopyKHR"sv;
	}
	case CopyDeviceMemoryInfoKHR: {
		return "CopyDeviceMemoryInfoKHR"sv;
	}
	case DeviceMemoryImageCopyKHR: {
		return "DeviceMemoryImageCopyKHR"sv;
	}
	case CopyDeviceMemoryImageInfoKHR: {
		return "CopyDeviceMemoryImageInfoKHR"sv;
	}
	case MemoryRangeBarriersInfoKHR: {
		return "MemoryRangeBarriersInfoKHR"sv;
	}
	case MemoryRangeBarrierKHR: {
		return "MemoryRangeBarrierKHR"sv;
	}
	case PhysicalDeviceDeviceAddressCommandsFeaturesKHR: {
		return "PhysicalDeviceDeviceAddressCommandsFeaturesKHR"sv;
	}
	case BindIndexBuffer3InfoKHR: {
		return "BindIndexBuffer3InfoKHR"sv;
	}
	case BindVertexBuffer3InfoKHR: {
		return "BindVertexBuffer3InfoKHR"sv;
	}
	case DrawIndirect2InfoKHR: {
		return "DrawIndirect2InfoKHR"sv;
	}
	case DrawIndirectCount2InfoKHR: {
		return "DrawIndirectCount2InfoKHR"sv;
	}
	case DispatchIndirect2InfoKHR: {
		return "DispatchIndirect2InfoKHR"sv;
	}
	case ConditionalRenderingBeginInfo2EXT: {
		return "ConditionalRenderingBeginInfo2EXT"sv;
	}
	case BindTransformFeedbackBuffer2InfoEXT: {
		return "BindTransformFeedbackBuffer2InfoEXT"sv;
	}
	case MemoryMarkerInfoAMD: {
		return "MemoryMarkerInfoAMD"sv;
	}
	case AccelerationStructureCreateInfo2KHR: {
		return "AccelerationStructureCreateInfo2KHR"sv;
	}
	case PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT: {
		return "PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT"sv;
	}
	case PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT: {
		return "PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT"sv;
	}
	case GraphicsPipelineLibraryCreateInfoEXT: {
		return "GraphicsPipelineLibraryCreateInfoEXT"sv;
	}
	case PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD: {
		return "PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD"sv;
	}
	case PhysicalDeviceFragmentShaderBarycentricPropertiesKHR: {
		return "PhysicalDeviceFragmentShaderBarycentricPropertiesKHR"sv;
	}
	case PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR: {
		return "PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR"sv;
	}
	case PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures: {
		return "PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures"sv;
	}
	case PhysicalDeviceFragmentShadingRateEnumsPropertiesNV: {
		return "PhysicalDeviceFragmentShadingRateEnumsPropertiesNV"sv;
	}
	case PhysicalDeviceFragmentShadingRateEnumsFeaturesNV: {
		return "PhysicalDeviceFragmentShadingRateEnumsFeaturesNV"sv;
	}
	case PipelineFragmentShadingRateEnumStateCreateInfoNV: {
		return "PipelineFragmentShadingRateEnumStateCreateInfoNV"sv;
	}
	case AccelerationStructureGeometryMotionTrianglesDataNV: {
		return "AccelerationStructureGeometryMotionTrianglesDataNV"sv;
	}
	case PhysicalDeviceRayTracingMotionBlurFeaturesNV: {
		return "PhysicalDeviceRayTracingMotionBlurFeaturesNV"sv;
	}
	case AccelerationStructureMotionInfoNV: {
		return "AccelerationStructureMotionInfoNV"sv;
	}
	case PhysicalDeviceMeshShaderFeaturesEXT: {
		return "PhysicalDeviceMeshShaderFeaturesEXT"sv;
	}
	case PhysicalDeviceMeshShaderPropertiesEXT: {
		return "PhysicalDeviceMeshShaderPropertiesEXT"sv;
	}
	case PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT: {
		return "PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT"sv;
	}
	case PhysicalDeviceFragmentDensityMap2FeaturesEXT: {
		return "PhysicalDeviceFragmentDensityMap2FeaturesEXT"sv;
	}
	case PhysicalDeviceFragmentDensityMap2PropertiesEXT: {
		return "PhysicalDeviceFragmentDensityMap2PropertiesEXT"sv;
	}
	case CopyCommandTransformInfoQCOM: {
		return "CopyCommandTransformInfoQCOM"sv;
	}
	case PhysicalDeviceImageRobustnessFeatures: {
		return "PhysicalDeviceImageRobustnessFeatures"sv;
	}
	case PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR: {
		return "PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR"sv;
	}
	case CopyBufferInfo2: {
		return "CopyBufferInfo2"sv;
	}
	case CopyImageInfo2: {
		return "CopyImageInfo2"sv;
	}
	case CopyBufferToImageInfo2: {
		return "CopyBufferToImageInfo2"sv;
	}
	case CopyImageToBufferInfo2: {
		return "CopyImageToBufferInfo2"sv;
	}
	case BlitImageInfo2: {
		return "BlitImageInfo2"sv;
	}
	case ResolveImageInfo2: {
		return "ResolveImageInfo2"sv;
	}
	case BufferCopy2: {
		return "BufferCopy2"sv;
	}
	case ImageCopy2: {
		return "ImageCopy2"sv;
	}
	case ImageBlit2: {
		return "ImageBlit2"sv;
	}
	case BufferImageCopy2: {
		return "BufferImageCopy2"sv;
	}
	case ImageResolve2: {
		return "ImageResolve2"sv;
	}
	case PhysicalDeviceImageCompressionControlFeaturesEXT: {
		return "PhysicalDeviceImageCompressionControlFeaturesEXT"sv;
	}
	case ImageCompressionControlEXT: {
		return "ImageCompressionControlEXT"sv;
	}
	case SubresourceLayout2: {
		return "SubresourceLayout2"sv;
	}
	case ImageSubresource2: {
		return "ImageSubresource2"sv;
	}
	case ImageCompressionPropertiesEXT: {
		return "ImageCompressionPropertiesEXT"sv;
	}
	case PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT: {
		return "PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT"sv;
	}
	case PhysicalDevice4444FormatsFeaturesEXT: {
		return "PhysicalDevice4444FormatsFeaturesEXT"sv;
	}
	case PhysicalDeviceFaultFeaturesEXT: {
		return "PhysicalDeviceFaultFeaturesEXT"sv;
	}
	case DeviceFaultCountsEXT: {
		return "DeviceFaultCountsEXT"sv;
	}
	case DeviceFaultInfoEXT: {
		return "DeviceFaultInfoEXT"sv;
	}
	case PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT: {
		return "PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT"sv;
	}
	case PhysicalDeviceRgba10x6FormatsFeaturesEXT: {
		return "PhysicalDeviceRgba10x6FormatsFeaturesEXT"sv;
	}
	case DirectfbSurfaceCreateInfoEXT: {
		return "DirectfbSurfaceCreateInfoEXT"sv;
	}
	case PhysicalDeviceRayTracingPipelineFeaturesKHR: {
		return "PhysicalDeviceRayTracingPipelineFeaturesKHR"sv;
	}
	case PhysicalDeviceRayTracingPipelinePropertiesKHR: {
		return "PhysicalDeviceRayTracingPipelinePropertiesKHR"sv;
	}
	case PhysicalDeviceRayQueryFeaturesKHR: {
		return "PhysicalDeviceRayQueryFeaturesKHR"sv;
	}
	case PhysicalDeviceMutableDescriptorTypeFeaturesEXT: {
		return "PhysicalDeviceMutableDescriptorTypeFeaturesEXT"sv;
	}
	case MutableDescriptorTypeCreateInfoEXT: {
		return "MutableDescriptorTypeCreateInfoEXT"sv;
	}
	case PhysicalDeviceVertexInputDynamicStateFeaturesEXT: {
		return "PhysicalDeviceVertexInputDynamicStateFeaturesEXT"sv;
	}
	case VertexInputBindingDescription2EXT: {
		return "VertexInputBindingDescription2EXT"sv;
	}
	case VertexInputAttributeDescription2EXT: {
		return "VertexInputAttributeDescription2EXT"sv;
	}
	case PhysicalDeviceDrmPropertiesEXT: {
		return "PhysicalDeviceDrmPropertiesEXT"sv;
	}
	case PhysicalDeviceAddressBindingReportFeaturesEXT: {
		return "PhysicalDeviceAddressBindingReportFeaturesEXT"sv;
	}
	case DeviceAddressBindingCallbackDataEXT: {
		return "DeviceAddressBindingCallbackDataEXT"sv;
	}
	case PhysicalDeviceDepthClipControlFeaturesEXT: {
		return "PhysicalDeviceDepthClipControlFeaturesEXT"sv;
	}
	case PipelineViewportDepthClipControlCreateInfoEXT: {
		return "PipelineViewportDepthClipControlCreateInfoEXT"sv;
	}
	case PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT: {
		return "PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT"sv;
	}
	case FormatProperties3: {
		return "FormatProperties3"sv;
	}
	case PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR: {
		return "PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR"sv;
	}
	case ImportMemoryZirconHandleInfoFUCHSIA: {
		return "ImportMemoryZirconHandleInfoFUCHSIA"sv;
	}
	case MemoryZirconHandlePropertiesFUCHSIA: {
		return "MemoryZirconHandlePropertiesFUCHSIA"sv;
	}
	case MemoryGetZirconHandleInfoFUCHSIA: {
		return "MemoryGetZirconHandleInfoFUCHSIA"sv;
	}
	case ImportSemaphoreZirconHandleInfoFUCHSIA: {
		return "ImportSemaphoreZirconHandleInfoFUCHSIA"sv;
	}
	case SemaphoreGetZirconHandleInfoFUCHSIA: {
		return "SemaphoreGetZirconHandleInfoFUCHSIA"sv;
	}
	case BufferCollectionCreateInfoFUCHSIA: {
		return "BufferCollectionCreateInfoFUCHSIA"sv;
	}
	case ImportMemoryBufferCollectionFUCHSIA: {
		return "ImportMemoryBufferCollectionFUCHSIA"sv;
	}
	case BufferCollectionImageCreateInfoFUCHSIA: {
		return "BufferCollectionImageCreateInfoFUCHSIA"sv;
	}
	case BufferCollectionPropertiesFUCHSIA: {
		return "BufferCollectionPropertiesFUCHSIA"sv;
	}
	case BufferConstraintsInfoFUCHSIA: {
		return "BufferConstraintsInfoFUCHSIA"sv;
	}
	case BufferCollectionBufferCreateInfoFUCHSIA: {
		return "BufferCollectionBufferCreateInfoFUCHSIA"sv;
	}
	case ImageConstraintsInfoFUCHSIA: {
		return "ImageConstraintsInfoFUCHSIA"sv;
	}
	case ImageFormatConstraintsInfoFUCHSIA: {
		return "ImageFormatConstraintsInfoFUCHSIA"sv;
	}
	case SysmemColorSpaceFUCHSIA: {
		return "SysmemColorSpaceFUCHSIA"sv;
	}
	case BufferCollectionConstraintsInfoFUCHSIA: {
		return "BufferCollectionConstraintsInfoFUCHSIA"sv;
	}
	case SubpassShadingPipelineCreateInfoHUAWEI: {
		return "SubpassShadingPipelineCreateInfoHUAWEI"sv;
	}
	case PhysicalDeviceSubpassShadingFeaturesHUAWEI: {
		return "PhysicalDeviceSubpassShadingFeaturesHUAWEI"sv;
	}
	case PhysicalDeviceSubpassShadingPropertiesHUAWEI: {
		return "PhysicalDeviceSubpassShadingPropertiesHUAWEI"sv;
	}
	case PhysicalDeviceInvocationMaskFeaturesHUAWEI: {
		return "PhysicalDeviceInvocationMaskFeaturesHUAWEI"sv;
	}
	case MemoryGetRemoteAddressInfoNV: {
		return "MemoryGetRemoteAddressInfoNV"sv;
	}
	case PhysicalDeviceExternalMemoryRdmaFeaturesNV: {
		return "PhysicalDeviceExternalMemoryRdmaFeaturesNV"sv;
	}
	case PipelinePropertiesIdentifierEXT: {
		return "PipelinePropertiesIdentifierEXT"sv;
	}
	case PhysicalDevicePipelinePropertiesFeaturesEXT: {
		return "PhysicalDevicePipelinePropertiesFeaturesEXT"sv;
	}
	case PhysicalDeviceFrameBoundaryFeaturesEXT: {
		return "PhysicalDeviceFrameBoundaryFeaturesEXT"sv;
	}
	case FrameBoundaryEXT: {
		return "FrameBoundaryEXT"sv;
	}
	case PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT: {
		return "PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT"sv;
	}
	case SubpassResolvePerformanceQueryEXT: {
		return "SubpassResolvePerformanceQueryEXT"sv;
	}
	case MultisampledRenderToSingleSampledInfoEXT: {
		return "MultisampledRenderToSingleSampledInfoEXT"sv;
	}
	case PhysicalDeviceExtendedDynamicState2FeaturesEXT: {
		return "PhysicalDeviceExtendedDynamicState2FeaturesEXT"sv;
	}
	case ScreenSurfaceCreateInfoQNX: {
		return "ScreenSurfaceCreateInfoQNX"sv;
	}
	case PhysicalDeviceColorWriteEnableFeaturesEXT: {
		return "PhysicalDeviceColorWriteEnableFeaturesEXT"sv;
	}
	case PipelineColorWriteCreateInfoEXT: {
		return "PipelineColorWriteCreateInfoEXT"sv;
	}
	case PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT: {
		return "PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT"sv;
	}
	case PhysicalDeviceRayTracingMaintenance1FeaturesKHR: {
		return "PhysicalDeviceRayTracingMaintenance1FeaturesKHR"sv;
	}
	case PhysicalDeviceShaderUntypedPointersFeaturesKHR: {
		return "PhysicalDeviceShaderUntypedPointersFeaturesKHR"sv;
	}
	case PhysicalDeviceGlobalPriorityQueryFeatures: {
		return "PhysicalDeviceGlobalPriorityQueryFeatures"sv;
	}
	case QueueFamilyGlobalPriorityProperties: {
		return "QueueFamilyGlobalPriorityProperties"sv;
	}
	case PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE: {
		return "PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE"sv;
	}
	case VideoEncodeRgbConversionCapabilitiesVALVE: {
		return "VideoEncodeRgbConversionCapabilitiesVALVE"sv;
	}
	case VideoEncodeProfileRgbConversionInfoVALVE: {
		return "VideoEncodeProfileRgbConversionInfoVALVE"sv;
	}
	case VideoEncodeSessionRgbConversionCreateInfoVALVE: {
		return "VideoEncodeSessionRgbConversionCreateInfoVALVE"sv;
	}
	case PhysicalDeviceImageViewMinLodFeaturesEXT: {
		return "PhysicalDeviceImageViewMinLodFeaturesEXT"sv;
	}
	case ImageViewMinLodCreateInfoEXT: {
		return "ImageViewMinLodCreateInfoEXT"sv;
	}
	case PhysicalDeviceMultiDrawFeaturesEXT: {
		return "PhysicalDeviceMultiDrawFeaturesEXT"sv;
	}
	case PhysicalDeviceMultiDrawPropertiesEXT: {
		return "PhysicalDeviceMultiDrawPropertiesEXT"sv;
	}
	case PhysicalDeviceImage2DViewOf3DFeaturesEXT: {
		return "PhysicalDeviceImage2DViewOf3DFeaturesEXT"sv;
	}
	case PhysicalDeviceShaderTileImageFeaturesEXT: {
		return "PhysicalDeviceShaderTileImageFeaturesEXT"sv;
	}
	case PhysicalDeviceShaderTileImagePropertiesEXT: {
		return "PhysicalDeviceShaderTileImagePropertiesEXT"sv;
	}
	case MicromapBuildInfoEXT: {
		return "MicromapBuildInfoEXT"sv;
	}
	case MicromapVersionInfoEXT: {
		return "MicromapVersionInfoEXT"sv;
	}
	case CopyMicromapInfoEXT: {
		return "CopyMicromapInfoEXT"sv;
	}
	case CopyMicromapToMemoryInfoEXT: {
		return "CopyMicromapToMemoryInfoEXT"sv;
	}
	case CopyMemoryToMicromapInfoEXT: {
		return "CopyMemoryToMicromapInfoEXT"sv;
	}
	case PhysicalDeviceOpacityMicromapFeaturesEXT: {
		return "PhysicalDeviceOpacityMicromapFeaturesEXT"sv;
	}
	case PhysicalDeviceOpacityMicromapPropertiesEXT: {
		return "PhysicalDeviceOpacityMicromapPropertiesEXT"sv;
	}
	case MicromapCreateInfoEXT: {
		return "MicromapCreateInfoEXT"sv;
	}
	case MicromapBuildSizesInfoEXT: {
		return "MicromapBuildSizesInfoEXT"sv;
	}
	case AccelerationStructureTrianglesOpacityMicromapEXT: {
		return "AccelerationStructureTrianglesOpacityMicromapEXT"sv;
	}
	case PhysicalDeviceDisplacementMicromapFeaturesNV: {
		return "PhysicalDeviceDisplacementMicromapFeaturesNV"sv;
	}
	case PhysicalDeviceDisplacementMicromapPropertiesNV: {
		return "PhysicalDeviceDisplacementMicromapPropertiesNV"sv;
	}
	case AccelerationStructureTrianglesDisplacementMicromapNV: {
		return "AccelerationStructureTrianglesDisplacementMicromapNV"sv;
	}
	case PhysicalDeviceClusterCullingShaderFeaturesHUAWEI: {
		return "PhysicalDeviceClusterCullingShaderFeaturesHUAWEI"sv;
	}
	case PhysicalDeviceClusterCullingShaderPropertiesHUAWEI: {
		return "PhysicalDeviceClusterCullingShaderPropertiesHUAWEI"sv;
	}
	case PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI: {
		return "PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI"sv;
	}
	case PhysicalDeviceBorderColorSwizzleFeaturesEXT: {
		return "PhysicalDeviceBorderColorSwizzleFeaturesEXT"sv;
	}
	case SamplerBorderColorComponentMappingCreateInfoEXT: {
		return "SamplerBorderColorComponentMappingCreateInfoEXT"sv;
	}
	case PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT: {
		return "PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT"sv;
	}
	case PhysicalDeviceMaintenance4Features: {
		return "PhysicalDeviceMaintenance4Features"sv;
	}
	case PhysicalDeviceMaintenance4Properties: {
		return "PhysicalDeviceMaintenance4Properties"sv;
	}
	case DeviceBufferMemoryRequirements: {
		return "DeviceBufferMemoryRequirements"sv;
	}
	case DeviceImageMemoryRequirements: {
		return "DeviceImageMemoryRequirements"sv;
	}
	case PhysicalDeviceShaderCorePropertiesARM: {
		return "PhysicalDeviceShaderCorePropertiesARM"sv;
	}
	case PhysicalDeviceShaderSubgroupRotateFeatures: {
		return "PhysicalDeviceShaderSubgroupRotateFeatures"sv;
	}
	case DeviceQueueShaderCoreControlCreateInfoARM: {
		return "DeviceQueueShaderCoreControlCreateInfoARM"sv;
	}
	case PhysicalDeviceSchedulingControlsFeaturesARM: {
		return "PhysicalDeviceSchedulingControlsFeaturesARM"sv;
	}
	case PhysicalDeviceSchedulingControlsPropertiesARM: {
		return "PhysicalDeviceSchedulingControlsPropertiesARM"sv;
	}
	case DispatchParametersARM: {
		return "DispatchParametersARM"sv;
	}
	case PhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM: {
		return "PhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM"sv;
	}
	case PhysicalDeviceImageSlicedViewOf3DFeaturesEXT: {
		return "PhysicalDeviceImageSlicedViewOf3DFeaturesEXT"sv;
	}
	case ImageViewSlicedCreateInfoEXT: {
		return "ImageViewSlicedCreateInfoEXT"sv;
	}
	case PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE: {
		return "PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE"sv;
	}
	case DescriptorSetBindingReferenceVALVE: {
		return "DescriptorSetBindingReferenceVALVE"sv;
	}
	case DescriptorSetLayoutHostMappingInfoVALVE: {
		return "DescriptorSetLayoutHostMappingInfoVALVE"sv;
	}
	case PhysicalDeviceDepthClampZeroOneFeaturesKHR: {
		return "PhysicalDeviceDepthClampZeroOneFeaturesKHR"sv;
	}
	case PhysicalDeviceNonSeamlessCubeMapFeaturesEXT: {
		return "PhysicalDeviceNonSeamlessCubeMapFeaturesEXT"sv;
	}
	case PhysicalDeviceRenderPassStripedFeaturesARM: {
		return "PhysicalDeviceRenderPassStripedFeaturesARM"sv;
	}
	case PhysicalDeviceRenderPassStripedPropertiesARM: {
		return "PhysicalDeviceRenderPassStripedPropertiesARM"sv;
	}
	case RenderPassStripeBeginInfoARM: {
		return "RenderPassStripeBeginInfoARM"sv;
	}
	case RenderPassStripeInfoARM: {
		return "RenderPassStripeInfoARM"sv;
	}
	case RenderPassStripeSubmitInfoARM: {
		return "RenderPassStripeSubmitInfoARM"sv;
	}
	case PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT: {
		return "PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT"sv;
	}
	case PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT: {
		return "PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT"sv;
	}
	case RenderPassFragmentDensityMapOffsetEndInfoEXT: {
		return "RenderPassFragmentDensityMapOffsetEndInfoEXT"sv;
	}
	case PhysicalDeviceCopyMemoryIndirectFeaturesNV: {
		return "PhysicalDeviceCopyMemoryIndirectFeaturesNV"sv;
	}
	case PhysicalDeviceCopyMemoryIndirectPropertiesKHR: {
		return "PhysicalDeviceCopyMemoryIndirectPropertiesKHR"sv;
	}
	case PhysicalDeviceMemoryDecompressionFeaturesEXT: {
		return "PhysicalDeviceMemoryDecompressionFeaturesEXT"sv;
	}
	case PhysicalDeviceMemoryDecompressionPropertiesEXT: {
		return "PhysicalDeviceMemoryDecompressionPropertiesEXT"sv;
	}
	case PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV: {
		return "PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV"sv;
	}
	case ComputePipelineIndirectBufferInfoNV: {
		return "ComputePipelineIndirectBufferInfoNV"sv;
	}
	case PipelineIndirectDeviceAddressInfoNV: {
		return "PipelineIndirectDeviceAddressInfoNV"sv;
	}
	case PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV: {
		return "PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV"sv;
	}
	case AccelerationStructureGeometryLinearSweptSpheresDataNV: {
		return "AccelerationStructureGeometryLinearSweptSpheresDataNV"sv;
	}
	case AccelerationStructureGeometrySpheresDataNV: {
		return "AccelerationStructureGeometrySpheresDataNV"sv;
	}
	case PhysicalDeviceLinearColorAttachmentFeaturesNV: {
		return "PhysicalDeviceLinearColorAttachmentFeaturesNV"sv;
	}
	case PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR: {
		return "PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR"sv;
	}
	case PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT: {
		return "PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT"sv;
	}
	case PhysicalDeviceImageProcessingFeaturesQCOM: {
		return "PhysicalDeviceImageProcessingFeaturesQCOM"sv;
	}
	case PhysicalDeviceImageProcessingPropertiesQCOM: {
		return "PhysicalDeviceImageProcessingPropertiesQCOM"sv;
	}
	case ImageViewSampleWeightCreateInfoQCOM: {
		return "ImageViewSampleWeightCreateInfoQCOM"sv;
	}
	case PhysicalDeviceNestedCommandBufferFeaturesEXT: {
		return "PhysicalDeviceNestedCommandBufferFeaturesEXT"sv;
	}
	case PhysicalDeviceNestedCommandBufferPropertiesEXT: {
		return "PhysicalDeviceNestedCommandBufferPropertiesEXT"sv;
	}
	case NativeBufferUsageOHOS: {
		return "NativeBufferUsageOHOS"sv;
	}
	case NativeBufferPropertiesOHOS: {
		return "NativeBufferPropertiesOHOS"sv;
	}
	case NativeBufferFormatPropertiesOHOS: {
		return "NativeBufferFormatPropertiesOHOS"sv;
	}
	case ImportNativeBufferInfoOHOS: {
		return "ImportNativeBufferInfoOHOS"sv;
	}
	case MemoryGetNativeBufferInfoOHOS: {
		return "MemoryGetNativeBufferInfoOHOS"sv;
	}
	case ExternalFormatOHOS: {
		return "ExternalFormatOHOS"sv;
	}
	case ExternalMemoryAcquireUnmodifiedEXT: {
		return "ExternalMemoryAcquireUnmodifiedEXT"sv;
	}
	case PhysicalDeviceExtendedDynamicState3FeaturesEXT: {
		return "PhysicalDeviceExtendedDynamicState3FeaturesEXT"sv;
	}
	case PhysicalDeviceExtendedDynamicState3PropertiesEXT: {
		return "PhysicalDeviceExtendedDynamicState3PropertiesEXT"sv;
	}
	case PhysicalDeviceSubpassMergeFeedbackFeaturesEXT: {
		return "PhysicalDeviceSubpassMergeFeedbackFeaturesEXT"sv;
	}
	case RenderPassCreationControlEXT: {
		return "RenderPassCreationControlEXT"sv;
	}
	case RenderPassCreationFeedbackCreateInfoEXT: {
		return "RenderPassCreationFeedbackCreateInfoEXT"sv;
	}
	case RenderPassSubpassFeedbackCreateInfoEXT: {
		return "RenderPassSubpassFeedbackCreateInfoEXT"sv;
	}
	case DirectDriverLoadingInfoLUNARG: {
		return "DirectDriverLoadingInfoLUNARG"sv;
	}
	case DirectDriverLoadingListLUNARG: {
		return "DirectDriverLoadingListLUNARG"sv;
	}
	case TensorCreateInfoARM: {
		return "TensorCreateInfoARM"sv;
	}
	case TensorViewCreateInfoARM: {
		return "TensorViewCreateInfoARM"sv;
	}
	case BindTensorMemoryInfoARM: {
		return "BindTensorMemoryInfoARM"sv;
	}
	case WriteDescriptorSetTensorARM: {
		return "WriteDescriptorSetTensorARM"sv;
	}
	case PhysicalDeviceTensorPropertiesARM: {
		return "PhysicalDeviceTensorPropertiesARM"sv;
	}
	case TensorFormatPropertiesARM: {
		return "TensorFormatPropertiesARM"sv;
	}
	case TensorDescriptionARM: {
		return "TensorDescriptionARM"sv;
	}
	case TensorMemoryRequirementsInfoARM: {
		return "TensorMemoryRequirementsInfoARM"sv;
	}
	case TensorMemoryBarrierARM: {
		return "TensorMemoryBarrierARM"sv;
	}
	case PhysicalDeviceTensorFeaturesARM: {
		return "PhysicalDeviceTensorFeaturesARM"sv;
	}
	case DeviceTensorMemoryRequirementsARM: {
		return "DeviceTensorMemoryRequirementsARM"sv;
	}
	case CopyTensorInfoARM: {
		return "CopyTensorInfoARM"sv;
	}
	case TensorCopyARM: {
		return "TensorCopyARM"sv;
	}
	case TensorDependencyInfoARM: {
		return "TensorDependencyInfoARM"sv;
	}
	case MemoryDedicatedAllocateInfoTensorARM: {
		return "MemoryDedicatedAllocateInfoTensorARM"sv;
	}
	case PhysicalDeviceExternalTensorInfoARM: {
		return "PhysicalDeviceExternalTensorInfoARM"sv;
	}
	case ExternalTensorPropertiesARM: {
		return "ExternalTensorPropertiesARM"sv;
	}
	case ExternalMemoryTensorCreateInfoARM: {
		return "ExternalMemoryTensorCreateInfoARM"sv;
	}
	case PhysicalDeviceDescriptorBufferTensorFeaturesARM: {
		return "PhysicalDeviceDescriptorBufferTensorFeaturesARM"sv;
	}
	case PhysicalDeviceDescriptorBufferTensorPropertiesARM: {
		return "PhysicalDeviceDescriptorBufferTensorPropertiesARM"sv;
	}
	case DescriptorGetTensorInfoARM: {
		return "DescriptorGetTensorInfoARM"sv;
	}
	case TensorCaptureDescriptorDataInfoARM: {
		return "TensorCaptureDescriptorDataInfoARM"sv;
	}
	case TensorViewCaptureDescriptorDataInfoARM: {
		return "TensorViewCaptureDescriptorDataInfoARM"sv;
	}
	case FrameBoundaryTensorsARM: {
		return "FrameBoundaryTensorsARM"sv;
	}
	case PhysicalDeviceShaderModuleIdentifierFeaturesEXT: {
		return "PhysicalDeviceShaderModuleIdentifierFeaturesEXT"sv;
	}
	case PhysicalDeviceShaderModuleIdentifierPropertiesEXT: {
		return "PhysicalDeviceShaderModuleIdentifierPropertiesEXT"sv;
	}
	case PipelineShaderStageModuleIdentifierCreateInfoEXT: {
		return "PipelineShaderStageModuleIdentifierCreateInfoEXT"sv;
	}
	case ShaderModuleIdentifierEXT: {
		return "ShaderModuleIdentifierEXT"sv;
	}
	case PhysicalDeviceOpticalFlowFeaturesNV: {
		return "PhysicalDeviceOpticalFlowFeaturesNV"sv;
	}
	case PhysicalDeviceOpticalFlowPropertiesNV: {
		return "PhysicalDeviceOpticalFlowPropertiesNV"sv;
	}
	case OpticalFlowImageFormatInfoNV: {
		return "OpticalFlowImageFormatInfoNV"sv;
	}
	case OpticalFlowImageFormatPropertiesNV: {
		return "OpticalFlowImageFormatPropertiesNV"sv;
	}
	case OpticalFlowSessionCreateInfoNV: {
		return "OpticalFlowSessionCreateInfoNV"sv;
	}
	case OpticalFlowExecuteInfoNV: {
		return "OpticalFlowExecuteInfoNV"sv;
	}
	case OpticalFlowSessionCreatePrivateDataInfoNV: {
		return "OpticalFlowSessionCreatePrivateDataInfoNV"sv;
	}
	case PhysicalDeviceLegacyDitheringFeaturesEXT: {
		return "PhysicalDeviceLegacyDitheringFeaturesEXT"sv;
	}
	case PhysicalDevicePipelineProtectedAccessFeatures: {
		return "PhysicalDevicePipelineProtectedAccessFeatures"sv;
	}
	case PhysicalDeviceExternalFormatResolveFeaturesANDROID: {
		return "PhysicalDeviceExternalFormatResolveFeaturesANDROID"sv;
	}
	case PhysicalDeviceExternalFormatResolvePropertiesANDROID: {
		return "PhysicalDeviceExternalFormatResolvePropertiesANDROID"sv;
	}
	case ANDROIDHardwareBufferFormatResolvePropertiesANDROID: {
		return "ANDROIDHardwareBufferFormatResolvePropertiesANDROID"sv;
	}
	case PhysicalDeviceMaintenance5Features: {
		return "PhysicalDeviceMaintenance5Features"sv;
	}
	case PhysicalDeviceMaintenance5Properties: {
		return "PhysicalDeviceMaintenance5Properties"sv;
	}
	case RenderingAreaInfo: {
		return "RenderingAreaInfo"sv;
	}
	case DeviceImageSubresourceInfo: {
		return "DeviceImageSubresourceInfo"sv;
	}
	case PipelineCreateFlags2CreateInfo: {
		return "PipelineCreateFlags2CreateInfo"sv;
	}
	case BufferUsageFlags2CreateInfo: {
		return "BufferUsageFlags2CreateInfo"sv;
	}
	case PhysicalDeviceAntiLagFeaturesAMD: {
		return "PhysicalDeviceAntiLagFeaturesAMD"sv;
	}
	case AntiLagDataAMD: {
		return "AntiLagDataAMD"sv;
	}
	case AntiLagPresentationInfoAMD: {
		return "AntiLagPresentationInfoAMD"sv;
	}
	case PhysicalDeviceDenseGeometryFormatFeaturesAMDX: {
		return "PhysicalDeviceDenseGeometryFormatFeaturesAMDX"sv;
	}
	case AccelerationStructureDenseGeometryFormatTrianglesDataAMDX: {
		return "AccelerationStructureDenseGeometryFormatTrianglesDataAMDX"sv;
	}
	case SurfaceCapabilitiesPresentId2KHR: {
		return "SurfaceCapabilitiesPresentId2KHR"sv;
	}
	case PresentId2KHR: {
		return "PresentId2KHR"sv;
	}
	case PhysicalDevicePresentId2FeaturesKHR: {
		return "PhysicalDevicePresentId2FeaturesKHR"sv;
	}
	case SurfaceCapabilitiesPresentWait2KHR: {
		return "SurfaceCapabilitiesPresentWait2KHR"sv;
	}
	case PhysicalDevicePresentWait2FeaturesKHR: {
		return "PhysicalDevicePresentWait2FeaturesKHR"sv;
	}
	case PresentWait2InfoKHR: {
		return "PresentWait2InfoKHR"sv;
	}
	case PhysicalDeviceRayTracingPositionFetchFeaturesKHR: {
		return "PhysicalDeviceRayTracingPositionFetchFeaturesKHR"sv;
	}
	case PhysicalDeviceShaderObjectFeaturesEXT: {
		return "PhysicalDeviceShaderObjectFeaturesEXT"sv;
	}
	case PhysicalDeviceShaderObjectPropertiesEXT: {
		return "PhysicalDeviceShaderObjectPropertiesEXT"sv;
	}
	case ShaderCreateInfoEXT: {
		return "ShaderCreateInfoEXT"sv;
	}
	case PhysicalDevicePipelineBinaryFeaturesKHR: {
		return "PhysicalDevicePipelineBinaryFeaturesKHR"sv;
	}
	case PipelineBinaryCreateInfoKHR: {
		return "PipelineBinaryCreateInfoKHR"sv;
	}
	case PipelineBinaryInfoKHR: {
		return "PipelineBinaryInfoKHR"sv;
	}
	case PipelineBinaryKeyKHR: {
		return "PipelineBinaryKeyKHR"sv;
	}
	case PhysicalDevicePipelineBinaryPropertiesKHR: {
		return "PhysicalDevicePipelineBinaryPropertiesKHR"sv;
	}
	case ReleaseCapturedPipelineDataInfoKHR: {
		return "ReleaseCapturedPipelineDataInfoKHR"sv;
	}
	case PipelineBinaryDataInfoKHR: {
		return "PipelineBinaryDataInfoKHR"sv;
	}
	case PipelineCreateInfoKHR: {
		return "PipelineCreateInfoKHR"sv;
	}
	case DevicePipelineBinaryInternalCacheControlKHR: {
		return "DevicePipelineBinaryInternalCacheControlKHR"sv;
	}
	case PipelineBinaryHandlesInfoKHR: {
		return "PipelineBinaryHandlesInfoKHR"sv;
	}
	case PhysicalDeviceTilePropertiesFeaturesQCOM: {
		return "PhysicalDeviceTilePropertiesFeaturesQCOM"sv;
	}
	case TilePropertiesQCOM: {
		return "TilePropertiesQCOM"sv;
	}
	case PhysicalDeviceAmigoProfilingFeaturesSEC: {
		return "PhysicalDeviceAmigoProfilingFeaturesSEC"sv;
	}
	case AmigoProfilingSubmitInfoSEC: {
		return "AmigoProfilingSubmitInfoSEC"sv;
	}
	case PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM: {
		return "PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM"sv;
	}
	case PhysicalDeviceRayTracingInvocationReorderFeaturesNV: {
		return "PhysicalDeviceRayTracingInvocationReorderFeaturesNV"sv;
	}
	case PhysicalDeviceRayTracingInvocationReorderPropertiesNV: {
		return "PhysicalDeviceRayTracingInvocationReorderPropertiesNV"sv;
	}
	case PhysicalDeviceCooperativeVectorFeaturesNV: {
		return "PhysicalDeviceCooperativeVectorFeaturesNV"sv;
	}
	case PhysicalDeviceCooperativeVectorPropertiesNV: {
		return "PhysicalDeviceCooperativeVectorPropertiesNV"sv;
	}
	case CooperativeVectorPropertiesNV: {
		return "CooperativeVectorPropertiesNV"sv;
	}
	case ConvertCooperativeVectorMatrixInfoNV: {
		return "ConvertCooperativeVectorMatrixInfoNV"sv;
	}
	case PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV: {
		return "PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV"sv;
	}
	case PhysicalDeviceExtendedSparseAddressSpacePropertiesNV: {
		return "PhysicalDeviceExtendedSparseAddressSpacePropertiesNV"sv;
	}
	case PhysicalDeviceLegacyVertexAttributesFeaturesEXT: {
		return "PhysicalDeviceLegacyVertexAttributesFeaturesEXT"sv;
	}
	case PhysicalDeviceLegacyVertexAttributesPropertiesEXT: {
		return "PhysicalDeviceLegacyVertexAttributesPropertiesEXT"sv;
	}
	case LayerSettingsCreateInfoEXT: {
		return "LayerSettingsCreateInfoEXT"sv;
	}
	case PhysicalDeviceShaderCoreBuiltinsFeaturesARM: {
		return "PhysicalDeviceShaderCoreBuiltinsFeaturesARM"sv;
	}
	case PhysicalDeviceShaderCoreBuiltinsPropertiesARM: {
		return "PhysicalDeviceShaderCoreBuiltinsPropertiesARM"sv;
	}
	case PhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR: {
		return "PhysicalDevicePipelineLibraryGroupHandlesFeaturesKHR"sv;
	}
	case PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT: {
		return "PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT"sv;
	}
	case PhysicalDeviceInternallySynchronizedQueuesFeaturesKHR: {
		return "PhysicalDeviceInternallySynchronizedQueuesFeaturesKHR"sv;
	}
	case LatencySleepModeInfoNV: {
		return "LatencySleepModeInfoNV"sv;
	}
	case LatencySleepInfoNV: {
		return "LatencySleepInfoNV"sv;
	}
	case SetLatencyMarkerInfoNV: {
		return "SetLatencyMarkerInfoNV"sv;
	}
	case GetLatencyMarkerInfoNV: {
		return "GetLatencyMarkerInfoNV"sv;
	}
	case LatencyTimingsFrameReportNV: {
		return "LatencyTimingsFrameReportNV"sv;
	}
	case LatencySubmissionPresentIdNV: {
		return "LatencySubmissionPresentIdNV"sv;
	}
	case OutOfBandQueueTypeInfoNV: {
		return "OutOfBandQueueTypeInfoNV"sv;
	}
	case SwapchainLatencyCreateInfoNV: {
		return "SwapchainLatencyCreateInfoNV"sv;
	}
	case LatencySurfaceCapabilitiesNV: {
		return "LatencySurfaceCapabilitiesNV"sv;
	}
	case PhysicalDeviceCooperativeMatrixFeaturesKHR: {
		return "PhysicalDeviceCooperativeMatrixFeaturesKHR"sv;
	}
	case CooperativeMatrixPropertiesKHR: {
		return "CooperativeMatrixPropertiesKHR"sv;
	}
	case PhysicalDeviceCooperativeMatrixPropertiesKHR: {
		return "PhysicalDeviceCooperativeMatrixPropertiesKHR"sv;
	}
	case DataGraphPipelineCreateInfoARM: {
		return "DataGraphPipelineCreateInfoARM"sv;
	}
	case DataGraphPipelineSessionCreateInfoARM: {
		return "DataGraphPipelineSessionCreateInfoARM"sv;
	}
	case DataGraphPipelineResourceInfoARM: {
		return "DataGraphPipelineResourceInfoARM"sv;
	}
	case DataGraphPipelineConstantARM: {
		return "DataGraphPipelineConstantARM"sv;
	}
	case DataGraphPipelineSessionMemoryRequirementsInfoARM: {
		return "DataGraphPipelineSessionMemoryRequirementsInfoARM"sv;
	}
	case BindDataGraphPipelineSessionMemoryInfoARM: {
		return "BindDataGraphPipelineSessionMemoryInfoARM"sv;
	}
	case PhysicalDeviceDataGraphFeaturesARM: {
		return "PhysicalDeviceDataGraphFeaturesARM"sv;
	}
	case DataGraphPipelineShaderModuleCreateInfoARM: {
		return "DataGraphPipelineShaderModuleCreateInfoARM"sv;
	}
	case DataGraphPipelinePropertyQueryResultARM: {
		return "DataGraphPipelinePropertyQueryResultARM"sv;
	}
	case DataGraphPipelineInfoARM: {
		return "DataGraphPipelineInfoARM"sv;
	}
	case DataGraphPipelineCompilerControlCreateInfoARM: {
		return "DataGraphPipelineCompilerControlCreateInfoARM"sv;
	}
	case DataGraphPipelineSessionBindPointRequirementsInfoARM: {
		return "DataGraphPipelineSessionBindPointRequirementsInfoARM"sv;
	}
	case DataGraphPipelineSessionBindPointRequirementARM: {
		return "DataGraphPipelineSessionBindPointRequirementARM"sv;
	}
	case DataGraphPipelineIdentifierCreateInfoARM: {
		return "DataGraphPipelineIdentifierCreateInfoARM"sv;
	}
	case DataGraphPipelineDispatchInfoARM: {
		return "DataGraphPipelineDispatchInfoARM"sv;
	}
	case DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM: {
		return "DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM"sv;
	}
	case DataGraphProcessingEngineCreateInfoARM: {
		return "DataGraphProcessingEngineCreateInfoARM"sv;
	}
	case QueueFamilyDataGraphProcessingEnginePropertiesARM: {
		return "QueueFamilyDataGraphProcessingEnginePropertiesARM"sv;
	}
	case QueueFamilyDataGraphPropertiesARM: {
		return "QueueFamilyDataGraphPropertiesARM"sv;
	}
	case PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM: {
		return "PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM"sv;
	}
	case QueueFamilyDataGraphTosaPropertiesARM: {
		return "QueueFamilyDataGraphTosaPropertiesARM"sv;
	}
	case PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM: {
		return "PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM"sv;
	}
	case MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM: {
		return "MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM"sv;
	}
	case PhysicalDeviceComputeShaderDerivativesPropertiesKHR: {
		return "PhysicalDeviceComputeShaderDerivativesPropertiesKHR"sv;
	}
	case VideoDecodeAV1CapabilitiesKHR: {
		return "VideoDecodeAV1CapabilitiesKHR"sv;
	}
	case VideoDecodeAV1PictureInfoKHR: {
		return "VideoDecodeAV1PictureInfoKHR"sv;
	}
	case VideoDecodeAV1ProfileInfoKHR: {
		return "VideoDecodeAV1ProfileInfoKHR"sv;
	}
	case VideoDecodeAV1SessionParametersCreateInfoKHR: {
		return "VideoDecodeAV1SessionParametersCreateInfoKHR"sv;
	}
	case VideoDecodeAV1DpbSlotInfoKHR: {
		return "VideoDecodeAV1DpbSlotInfoKHR"sv;
	}
	case VideoEncodeAV1CapabilitiesKHR: {
		return "VideoEncodeAV1CapabilitiesKHR"sv;
	}
	case VideoEncodeAV1SessionParametersCreateInfoKHR: {
		return "VideoEncodeAV1SessionParametersCreateInfoKHR"sv;
	}
	case VideoEncodeAV1PictureInfoKHR: {
		return "VideoEncodeAV1PictureInfoKHR"sv;
	}
	case VideoEncodeAV1DpbSlotInfoKHR: {
		return "VideoEncodeAV1DpbSlotInfoKHR"sv;
	}
	case PhysicalDeviceVideoEncodeAV1FeaturesKHR: {
		return "PhysicalDeviceVideoEncodeAV1FeaturesKHR"sv;
	}
	case VideoEncodeAV1ProfileInfoKHR: {
		return "VideoEncodeAV1ProfileInfoKHR"sv;
	}
	case VideoEncodeAV1RateControlInfoKHR: {
		return "VideoEncodeAV1RateControlInfoKHR"sv;
	}
	case VideoEncodeAV1RateControlLayerInfoKHR: {
		return "VideoEncodeAV1RateControlLayerInfoKHR"sv;
	}
	case VideoEncodeAV1QualityLevelPropertiesKHR: {
		return "VideoEncodeAV1QualityLevelPropertiesKHR"sv;
	}
	case VideoEncodeAV1SessionCreateInfoKHR: {
		return "VideoEncodeAV1SessionCreateInfoKHR"sv;
	}
	case VideoEncodeAV1GopRemainingFrameInfoKHR: {
		return "VideoEncodeAV1GopRemainingFrameInfoKHR"sv;
	}
	case PhysicalDeviceVideoDecodeVp9FeaturesKHR: {
		return "PhysicalDeviceVideoDecodeVp9FeaturesKHR"sv;
	}
	case VideoDecodeVp9CapabilitiesKHR: {
		return "VideoDecodeVp9CapabilitiesKHR"sv;
	}
	case VideoDecodeVp9PictureInfoKHR: {
		return "VideoDecodeVp9PictureInfoKHR"sv;
	}
	case VideoDecodeVp9ProfileInfoKHR: {
		return "VideoDecodeVp9ProfileInfoKHR"sv;
	}
	case PhysicalDeviceVideoMaintenance1FeaturesKHR: {
		return "PhysicalDeviceVideoMaintenance1FeaturesKHR"sv;
	}
	case VideoInlineQueryInfoKHR: {
		return "VideoInlineQueryInfoKHR"sv;
	}
	case PhysicalDevicePerStageDescriptorSetFeaturesNV: {
		return "PhysicalDevicePerStageDescriptorSetFeaturesNV"sv;
	}
	case PhysicalDeviceImageProcessing2FeaturesQCOM: {
		return "PhysicalDeviceImageProcessing2FeaturesQCOM"sv;
	}
	case PhysicalDeviceImageProcessing2PropertiesQCOM: {
		return "PhysicalDeviceImageProcessing2PropertiesQCOM"sv;
	}
	case SamplerBlockMatchWindowCreateInfoQCOM: {
		return "SamplerBlockMatchWindowCreateInfoQCOM"sv;
	}
	case SamplerCubicWeightsCreateInfoQCOM: {
		return "SamplerCubicWeightsCreateInfoQCOM"sv;
	}
	case PhysicalDeviceCubicWeightsFeaturesQCOM: {
		return "PhysicalDeviceCubicWeightsFeaturesQCOM"sv;
	}
	case BlitImageCubicWeightsInfoQCOM: {
		return "BlitImageCubicWeightsInfoQCOM"sv;
	}
	case PhysicalDeviceYcbcrDegammaFeaturesQCOM: {
		return "PhysicalDeviceYcbcrDegammaFeaturesQCOM"sv;
	}
	case SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM: {
		return "SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM"sv;
	}
	case PhysicalDeviceCubicClampFeaturesQCOM: {
		return "PhysicalDeviceCubicClampFeaturesQCOM"sv;
	}
	case PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT: {
		return "PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT"sv;
	}
	case PhysicalDeviceVertexAttributeDivisorProperties: {
		return "PhysicalDeviceVertexAttributeDivisorProperties"sv;
	}
	case PhysicalDeviceUnifiedImageLayoutsFeaturesKHR: {
		return "PhysicalDeviceUnifiedImageLayoutsFeaturesKHR"sv;
	}
	case AttachmentFeedbackLoopInfoEXT: {
		return "AttachmentFeedbackLoopInfoEXT"sv;
	}
	case PhysicalDeviceShaderFloatControls2Features: {
		return "PhysicalDeviceShaderFloatControls2Features"sv;
	}
	case ScreenBufferPropertiesQNX: {
		return "ScreenBufferPropertiesQNX"sv;
	}
	case ScreenBufferFormatPropertiesQNX: {
		return "ScreenBufferFormatPropertiesQNX"sv;
	}
	case ImportScreenBufferInfoQNX: {
		return "ImportScreenBufferInfoQNX"sv;
	}
	case ExternalFormatQNX: {
		return "ExternalFormatQNX"sv;
	}
	case PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX: {
		return "PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX"sv;
	}
	case PhysicalDeviceLayeredDriverPropertiesMSFT: {
		return "PhysicalDeviceLayeredDriverPropertiesMSFT"sv;
	}
	case PhysicalDeviceShaderExpectAssumeFeatures: {
		return "PhysicalDeviceShaderExpectAssumeFeatures"sv;
	}
	case PhysicalDeviceMaintenance6Features: {
		return "PhysicalDeviceMaintenance6Features"sv;
	}
	case PhysicalDeviceMaintenance6Properties: {
		return "PhysicalDeviceMaintenance6Properties"sv;
	}
	case BindMemoryStatus: {
		return "BindMemoryStatus"sv;
	}
	case BindDescriptorSetsInfo: {
		return "BindDescriptorSetsInfo"sv;
	}
	case PushConstantsInfo: {
		return "PushConstantsInfo"sv;
	}
	case PushDescriptorSetInfo: {
		return "PushDescriptorSetInfo"sv;
	}
	case PushDescriptorSetWithTemplateInfo: {
		return "PushDescriptorSetWithTemplateInfo"sv;
	}
	case SetDescriptorBufferOffsetsInfoEXT: {
		return "SetDescriptorBufferOffsetsInfoEXT"sv;
	}
	case BindDescriptorBufferEmbeddedSamplersInfoEXT: {
		return "BindDescriptorBufferEmbeddedSamplersInfoEXT"sv;
	}
	case PhysicalDeviceDescriptorPoolOverallocationFeaturesNV: {
		return "PhysicalDeviceDescriptorPoolOverallocationFeaturesNV"sv;
	}
	case PhysicalDeviceTileMemoryHeapFeaturesQCOM: {
		return "PhysicalDeviceTileMemoryHeapFeaturesQCOM"sv;
	}
	case PhysicalDeviceTileMemoryHeapPropertiesQCOM: {
		return "PhysicalDeviceTileMemoryHeapPropertiesQCOM"sv;
	}
	case TileMemoryRequirementsQCOM: {
		return "TileMemoryRequirementsQCOM"sv;
	}
	case TileMemoryBindInfoQCOM: {
		return "TileMemoryBindInfoQCOM"sv;
	}
	case TileMemorySizeInfoQCOM: {
		return "TileMemorySizeInfoQCOM"sv;
	}
	case PhysicalDeviceCopyMemoryIndirectFeaturesKHR: {
		return "PhysicalDeviceCopyMemoryIndirectFeaturesKHR"sv;
	}
	case CopyMemoryIndirectInfoKHR: {
		return "CopyMemoryIndirectInfoKHR"sv;
	}
	case CopyMemoryToImageIndirectInfoKHR: {
		return "CopyMemoryToImageIndirectInfoKHR"sv;
	}
	case DecompressMemoryInfoEXT: {
		return "DecompressMemoryInfoEXT"sv;
	}
	case DisplaySurfaceStereoCreateInfoNV: {
		return "DisplaySurfaceStereoCreateInfoNV"sv;
	}
	case DisplayModeStereoPropertiesNV: {
		return "DisplayModeStereoPropertiesNV"sv;
	}
	case VideoEncodeIntraRefreshCapabilitiesKHR: {
		return "VideoEncodeIntraRefreshCapabilitiesKHR"sv;
	}
	case VideoEncodeSessionIntraRefreshCreateInfoKHR: {
		return "VideoEncodeSessionIntraRefreshCreateInfoKHR"sv;
	}
	case VideoEncodeIntraRefreshInfoKHR: {
		return "VideoEncodeIntraRefreshInfoKHR"sv;
	}
	case VideoReferenceIntraRefreshInfoKHR: {
		return "VideoReferenceIntraRefreshInfoKHR"sv;
	}
	case PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR: {
		return "PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR"sv;
	}
	case VideoEncodeQuantizationMapCapabilitiesKHR: {
		return "VideoEncodeQuantizationMapCapabilitiesKHR"sv;
	}
	case VideoFormatQuantizationMapPropertiesKHR: {
		return "VideoFormatQuantizationMapPropertiesKHR"sv;
	}
	case VideoEncodeQuantizationMapInfoKHR: {
		return "VideoEncodeQuantizationMapInfoKHR"sv;
	}
	case VideoEncodeH264QuantizationMapCapabilitiesKHR: {
		return "VideoEncodeH264QuantizationMapCapabilitiesKHR"sv;
	}
	case VideoEncodeH265QuantizationMapCapabilitiesKHR: {
		return "VideoEncodeH265QuantizationMapCapabilitiesKHR"sv;
	}
	case VideoEncodeQuantizationMapSessionParametersCreateInfoKHR: {
		return "VideoEncodeQuantizationMapSessionParametersCreateInfoKHR"sv;
	}
	case VideoFormatH265QuantizationMapPropertiesKHR: {
		return "VideoFormatH265QuantizationMapPropertiesKHR"sv;
	}
	case VideoEncodeAV1QuantizationMapCapabilitiesKHR: {
		return "VideoEncodeAV1QuantizationMapCapabilitiesKHR"sv;
	}
	case VideoFormatAV1QuantizationMapPropertiesKHR: {
		return "VideoFormatAV1QuantizationMapPropertiesKHR"sv;
	}
	case PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR: {
		return "PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR"sv;
	}
	case PhysicalDeviceRawAccessChainsFeaturesNV: {
		return "PhysicalDeviceRawAccessChainsFeaturesNV"sv;
	}
	case ExternalComputeQueueDeviceCreateInfoNV: {
		return "ExternalComputeQueueDeviceCreateInfoNV"sv;
	}
	case ExternalComputeQueueCreateInfoNV: {
		return "ExternalComputeQueueCreateInfoNV"sv;
	}
	case ExternalComputeQueueDataParamsNV: {
		return "ExternalComputeQueueDataParamsNV"sv;
	}
	case PhysicalDeviceExternalComputeQueuePropertiesNV: {
		return "PhysicalDeviceExternalComputeQueuePropertiesNV"sv;
	}
	case PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR: {
		return "PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR"sv;
	}
	case PhysicalDeviceCommandBufferInheritanceFeaturesNV: {
		return "PhysicalDeviceCommandBufferInheritanceFeaturesNV"sv;
	}
	case PhysicalDeviceMaintenance7FeaturesKHR: {
		return "PhysicalDeviceMaintenance7FeaturesKHR"sv;
	}
	case PhysicalDeviceMaintenance7PropertiesKHR: {
		return "PhysicalDeviceMaintenance7PropertiesKHR"sv;
	}
	case PhysicalDeviceLayeredApiPropertiesListKHR: {
		return "PhysicalDeviceLayeredApiPropertiesListKHR"sv;
	}
	case PhysicalDeviceLayeredApiPropertiesKHR: {
		return "PhysicalDeviceLayeredApiPropertiesKHR"sv;
	}
	case PhysicalDeviceLayeredApiVulkanPropertiesKHR: {
		return "PhysicalDeviceLayeredApiVulkanPropertiesKHR"sv;
	}
	case PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV: {
		return "PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV"sv;
	}
	case PhysicalDeviceShaderReplicatedCompositesFeaturesEXT: {
		return "PhysicalDeviceShaderReplicatedCompositesFeaturesEXT"sv;
	}
	case TensorExplicitTilingFormatPropertiesARM: {
		return "TensorExplicitTilingFormatPropertiesARM"sv;
	}
	case TensorRollingBackingCreateInfoARM: {
		return "TensorRollingBackingCreateInfoARM"sv;
	}
	case PhysicalDeviceShaderFloat8FeaturesEXT: {
		return "PhysicalDeviceShaderFloat8FeaturesEXT"sv;
	}
	case PhysicalDeviceRayTracingValidationFeaturesNV: {
		return "PhysicalDeviceRayTracingValidationFeaturesNV"sv;
	}
	case PhysicalDeviceClusterAccelerationStructureFeaturesNV: {
		return "PhysicalDeviceClusterAccelerationStructureFeaturesNV"sv;
	}
	case PhysicalDeviceClusterAccelerationStructurePropertiesNV: {
		return "PhysicalDeviceClusterAccelerationStructurePropertiesNV"sv;
	}
	case ClusterAccelerationStructureClustersBottomLevelInputNV: {
		return "ClusterAccelerationStructureClustersBottomLevelInputNV"sv;
	}
	case ClusterAccelerationStructureTriangleClusterInputNV: {
		return "ClusterAccelerationStructureTriangleClusterInputNV"sv;
	}
	case ClusterAccelerationStructureMoveObjectsInputNV: {
		return "ClusterAccelerationStructureMoveObjectsInputNV"sv;
	}
	case ClusterAccelerationStructureInputInfoNV: {
		return "ClusterAccelerationStructureInputInfoNV"sv;
	}
	case ClusterAccelerationStructureCommandsInfoNV: {
		return "ClusterAccelerationStructureCommandsInfoNV"sv;
	}
	case RayTracingPipelineClusterAccelerationStructureCreateInfoNV: {
		return "RayTracingPipelineClusterAccelerationStructureCreateInfoNV"sv;
	}
	case PhysicalDevicePartitionedAccelerationStructureFeaturesNV: {
		return "PhysicalDevicePartitionedAccelerationStructureFeaturesNV"sv;
	}
	case PhysicalDevicePartitionedAccelerationStructurePropertiesNV: {
		return "PhysicalDevicePartitionedAccelerationStructurePropertiesNV"sv;
	}
	case WriteDescriptorSetPartitionedAccelerationStructureNV: {
		return "WriteDescriptorSetPartitionedAccelerationStructureNV"sv;
	}
	case PartitionedAccelerationStructureInstancesInputNV: {
		return "PartitionedAccelerationStructureInstancesInputNV"sv;
	}
	case BuildPartitionedAccelerationStructureInfoNV: {
		return "BuildPartitionedAccelerationStructureInfoNV"sv;
	}
	case PartitionedAccelerationStructureFlagsNV: {
		return "PartitionedAccelerationStructureFlagsNV"sv;
	}
	case PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT: {
		return "PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT"sv;
	}
	case PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT: {
		return "PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT"sv;
	}
	case GeneratedCommandsMemoryRequirementsInfoEXT: {
		return "GeneratedCommandsMemoryRequirementsInfoEXT"sv;
	}
	case IndirectExecutionSetCreateInfoEXT: {
		return "IndirectExecutionSetCreateInfoEXT"sv;
	}
	case GeneratedCommandsInfoEXT: {
		return "GeneratedCommandsInfoEXT"sv;
	}
	case IndirectCommandsLayoutCreateInfoEXT: {
		return "IndirectCommandsLayoutCreateInfoEXT"sv;
	}
	case IndirectCommandsLayoutTokenEXT: {
		return "IndirectCommandsLayoutTokenEXT"sv;
	}
	case WriteIndirectExecutionSetPipelineEXT: {
		return "WriteIndirectExecutionSetPipelineEXT"sv;
	}
	case WriteIndirectExecutionSetShaderEXT: {
		return "WriteIndirectExecutionSetShaderEXT"sv;
	}
	case IndirectExecutionSetPipelineInfoEXT: {
		return "IndirectExecutionSetPipelineInfoEXT"sv;
	}
	case IndirectExecutionSetShaderInfoEXT: {
		return "IndirectExecutionSetShaderInfoEXT"sv;
	}
	case IndirectExecutionSetShaderLayoutInfoEXT: {
		return "IndirectExecutionSetShaderLayoutInfoEXT"sv;
	}
	case GeneratedCommandsPipelineInfoEXT: {
		return "GeneratedCommandsPipelineInfoEXT"sv;
	}
	case GeneratedCommandsShaderInfoEXT: {
		return "GeneratedCommandsShaderInfoEXT"sv;
	}
	case PhysicalDeviceFaultFeaturesKHR: {
		return "PhysicalDeviceFaultFeaturesKHR"sv;
	}
	case PhysicalDeviceFaultPropertiesKHR: {
		return "PhysicalDeviceFaultPropertiesKHR"sv;
	}
	case DeviceFaultInfoKHR: {
		return "DeviceFaultInfoKHR"sv;
	}
	case DeviceFaultDebugInfoKHR: {
		return "DeviceFaultDebugInfoKHR"sv;
	}
	case PhysicalDeviceMaintenance8FeaturesKHR: {
		return "PhysicalDeviceMaintenance8FeaturesKHR"sv;
	}
	case MemoryBarrierAccessFlags3KHR: {
		return "MemoryBarrierAccessFlags3KHR"sv;
	}
	case PhysicalDeviceImageAlignmentControlFeaturesMESA: {
		return "PhysicalDeviceImageAlignmentControlFeaturesMESA"sv;
	}
	case PhysicalDeviceImageAlignmentControlPropertiesMESA: {
		return "PhysicalDeviceImageAlignmentControlPropertiesMESA"sv;
	}
	case ImageAlignmentControlCreateInfoMESA: {
		return "ImageAlignmentControlCreateInfoMESA"sv;
	}
	case PhysicalDeviceShaderFmaFeaturesKHR: {
		return "PhysicalDeviceShaderFmaFeaturesKHR"sv;
	}
	case PushConstantBankInfoNV: {
		return "PushConstantBankInfoNV"sv;
	}
	case PhysicalDevicePushConstantBankFeaturesNV: {
		return "PhysicalDevicePushConstantBankFeaturesNV"sv;
	}
	case PhysicalDevicePushConstantBankPropertiesNV: {
		return "PhysicalDevicePushConstantBankPropertiesNV"sv;
	}
	case PhysicalDeviceRayTracingInvocationReorderFeaturesEXT: {
		return "PhysicalDeviceRayTracingInvocationReorderFeaturesEXT"sv;
	}
	case PhysicalDeviceRayTracingInvocationReorderPropertiesEXT: {
		return "PhysicalDeviceRayTracingInvocationReorderPropertiesEXT"sv;
	}
	case PhysicalDeviceDepthClampControlFeaturesEXT: {
		return "PhysicalDeviceDepthClampControlFeaturesEXT"sv;
	}
	case PipelineViewportDepthClampControlCreateInfoEXT: {
		return "PipelineViewportDepthClampControlCreateInfoEXT"sv;
	}
	case PhysicalDeviceMaintenance9FeaturesKHR: {
		return "PhysicalDeviceMaintenance9FeaturesKHR"sv;
	}
	case PhysicalDeviceMaintenance9PropertiesKHR: {
		return "PhysicalDeviceMaintenance9PropertiesKHR"sv;
	}
	case QueueFamilyOwnershipTransferPropertiesKHR: {
		return "QueueFamilyOwnershipTransferPropertiesKHR"sv;
	}
	case PhysicalDeviceVideoMaintenance2FeaturesKHR: {
		return "PhysicalDeviceVideoMaintenance2FeaturesKHR"sv;
	}
	case VideoDecodeH264InlineSessionParametersInfoKHR: {
		return "VideoDecodeH264InlineSessionParametersInfoKHR"sv;
	}
	case VideoDecodeH265InlineSessionParametersInfoKHR: {
		return "VideoDecodeH265InlineSessionParametersInfoKHR"sv;
	}
	case VideoDecodeAV1InlineSessionParametersInfoKHR: {
		return "VideoDecodeAV1InlineSessionParametersInfoKHR"sv;
	}
	case PhysicalDeviceHdrVividFeaturesHUAWEI: {
		return "PhysicalDeviceHdrVividFeaturesHUAWEI"sv;
	}
	case HdrVividDynamicMetadataHUAWEI: {
		return "HdrVividDynamicMetadataHUAWEI"sv;
	}
	case PhysicalDeviceCooperativeMatrix2FeaturesNV: {
		return "PhysicalDeviceCooperativeMatrix2FeaturesNV"sv;
	}
	case CooperativeMatrixFlexibleDimensionsPropertiesNV: {
		return "CooperativeMatrixFlexibleDimensionsPropertiesNV"sv;
	}
	case PhysicalDeviceCooperativeMatrix2PropertiesNV: {
		return "PhysicalDeviceCooperativeMatrix2PropertiesNV"sv;
	}
	case PhysicalDevicePipelineOpacityMicromapFeaturesARM: {
		return "PhysicalDevicePipelineOpacityMicromapFeaturesARM"sv;
	}
	case PhysicalDeviceVideoEncodeFeedback2FeaturesKHR: {
		return "PhysicalDeviceVideoEncodeFeedback2FeaturesKHR"sv;
	}
	case VideoEncodeFeedback2CapabilitiesKHR: {
		return "VideoEncodeFeedback2CapabilitiesKHR"sv;
	}
	case QueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR: {
		return "QueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR"sv;
	}
	case ImportMemoryMetalHandleInfoEXT: {
		return "ImportMemoryMetalHandleInfoEXT"sv;
	}
	case MemoryMetalHandlePropertiesEXT: {
		return "MemoryMetalHandlePropertiesEXT"sv;
	}
	case MemoryGetMetalHandleInfoEXT: {
		return "MemoryGetMetalHandleInfoEXT"sv;
	}
	case PhysicalDevicePerformanceCountersByRegionFeaturesARM: {
		return "PhysicalDevicePerformanceCountersByRegionFeaturesARM"sv;
	}
	case PhysicalDevicePerformanceCountersByRegionPropertiesARM: {
		return "PhysicalDevicePerformanceCountersByRegionPropertiesARM"sv;
	}
	case PerformanceCounterARM: {
		return "PerformanceCounterARM"sv;
	}
	case PerformanceCounterDescriptionARM: {
		return "PerformanceCounterDescriptionARM"sv;
	}
	case RenderPassPerformanceCountersByRegionBeginInfoARM: {
		return "RenderPassPerformanceCountersByRegionBeginInfoARM"sv;
	}
	case PhysicalDeviceShaderInstrumentationFeaturesARM: {
		return "PhysicalDeviceShaderInstrumentationFeaturesARM"sv;
	}
	case PhysicalDeviceShaderInstrumentationPropertiesARM: {
		return "PhysicalDeviceShaderInstrumentationPropertiesARM"sv;
	}
	case ShaderInstrumentationCreateInfoARM: {
		return "ShaderInstrumentationCreateInfoARM"sv;
	}
	case ShaderInstrumentationMetricDescriptionARM: {
		return "ShaderInstrumentationMetricDescriptionARM"sv;
	}
	case PhysicalDeviceVertexAttributeRobustnessFeaturesEXT: {
		return "PhysicalDeviceVertexAttributeRobustnessFeaturesEXT"sv;
	}
	case PhysicalDeviceFormatPackFeaturesARM: {
		return "PhysicalDeviceFormatPackFeaturesARM"sv;
	}
	case PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE: {
		return "PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE"sv;
	}
	case PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE: {
		return "PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE"sv;
	}
	case PipelineFragmentDensityMapLayeredCreateInfoVALVE: {
		return "PipelineFragmentDensityMapLayeredCreateInfoVALVE"sv;
	}
	case SetPresentConfigNV: {
		return "SetPresentConfigNV"sv;
	}
	case PhysicalDevicePresentMeteringFeaturesNV: {
		return "PhysicalDevicePresentMeteringFeaturesNV"sv;
	}
	case PhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT: {
		return "PhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT"sv;
	}
	case SwapchainFlagsSurfaceCapabilitiesEXT: {
		return "SwapchainFlagsSurfaceCapabilitiesEXT"sv;
	}
	case RenderingEndInfoKHR: {
		return "RenderingEndInfoKHR"sv;
	}
	case PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT: {
		return "PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT"sv;
	}
	case PhysicalDeviceOpacityMicromapFeaturesKHR: {
		return "PhysicalDeviceOpacityMicromapFeaturesKHR"sv;
	}
	case PhysicalDeviceOpacityMicromapPropertiesKHR: {
		return "PhysicalDeviceOpacityMicromapPropertiesKHR"sv;
	}
	case AccelerationStructureGeometryMicromapDataKHR: {
		return "AccelerationStructureGeometryMicromapDataKHR"sv;
	}
	case AccelerationStructureTrianglesOpacityMicromapKHR: {
		return "AccelerationStructureTrianglesOpacityMicromapKHR"sv;
	}
	case PhysicalDeviceShader64BitIndexingFeaturesEXT: {
		return "PhysicalDeviceShader64BitIndexingFeaturesEXT"sv;
	}
	case PhysicalDeviceCustomResolveFeaturesEXT: {
		return "PhysicalDeviceCustomResolveFeaturesEXT"sv;
	}
	case BeginCustomResolveInfoEXT: {
		return "BeginCustomResolveInfoEXT"sv;
	}
	case CustomResolveCreateInfoEXT: {
		return "CustomResolveCreateInfoEXT"sv;
	}
	case PhysicalDeviceDataGraphModelFeaturesQCOM: {
		return "PhysicalDeviceDataGraphModelFeaturesQCOM"sv;
	}
	case DataGraphPipelineBuiltinModelCreateInfoQCOM: {
		return "DataGraphPipelineBuiltinModelCreateInfoQCOM"sv;
	}
	case PhysicalDeviceMaintenance10FeaturesKHR: {
		return "PhysicalDeviceMaintenance10FeaturesKHR"sv;
	}
	case PhysicalDeviceMaintenance10PropertiesKHR: {
		return "PhysicalDeviceMaintenance10PropertiesKHR"sv;
	}
	case RenderingAttachmentFlagsInfoKHR: {
		return "RenderingAttachmentFlagsInfoKHR"sv;
	}
	case ResolveImageModeInfoKHR: {
		return "ResolveImageModeInfoKHR"sv;
	}
	case PhysicalDeviceDataGraphOpticalFlowFeaturesARM: {
		return "PhysicalDeviceDataGraphOpticalFlowFeaturesARM"sv;
	}
	case QueueFamilyDataGraphOpticalFlowPropertiesARM: {
		return "QueueFamilyDataGraphOpticalFlowPropertiesARM"sv;
	}
	case DataGraphPipelineOpticalFlowCreateInfoARM: {
		return "DataGraphPipelineOpticalFlowCreateInfoARM"sv;
	}
	case DataGraphOpticalFlowImageFormatInfoARM: {
		return "DataGraphOpticalFlowImageFormatInfoARM"sv;
	}
	case DataGraphOpticalFlowImageFormatPropertiesARM: {
		return "DataGraphOpticalFlowImageFormatPropertiesARM"sv;
	}
	case DataGraphPipelineOpticalFlowDispatchInfoARM: {
		return "DataGraphPipelineOpticalFlowDispatchInfoARM"sv;
	}
	case DataGraphPipelineResourceInfoImageLayoutARM: {
		return "DataGraphPipelineResourceInfoImageLayoutARM"sv;
	}
	case DataGraphPipelineSingleNodeCreateInfoARM: {
		return "DataGraphPipelineSingleNodeCreateInfoARM"sv;
	}
	case DataGraphPipelineSingleNodeConnectionARM: {
		return "DataGraphPipelineSingleNodeConnectionARM"sv;
	}
	case PhysicalDeviceShaderLongVectorFeaturesEXT: {
		return "PhysicalDeviceShaderLongVectorFeaturesEXT"sv;
	}
	case PhysicalDeviceShaderLongVectorPropertiesEXT: {
		return "PhysicalDeviceShaderLongVectorPropertiesEXT"sv;
	}
	case PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC: {
		return "PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC"sv;
	}
	case PhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT: {
		return "PhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT"sv;
	}
	case ComputeOccupancyPriorityParametersNV: {
		return "ComputeOccupancyPriorityParametersNV"sv;
	}
	case PhysicalDeviceComputeOccupancyPriorityFeaturesNV: {
		return "PhysicalDeviceComputeOccupancyPriorityFeaturesNV"sv;
	}
	case PhysicalDeviceMaintenance11FeaturesKHR: {
		return "PhysicalDeviceMaintenance11FeaturesKHR"sv;
	}
	case QueueFamilyOptimalImageTransferGranularityPropertiesKHR: {
		return "QueueFamilyOptimalImageTransferGranularityPropertiesKHR"sv;
	}
	case PhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT: {
		return "PhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT"sv;
	}
	case PhysicalDeviceCooperativeMatrixInfo2EXT: {
		return "PhysicalDeviceCooperativeMatrixInfo2EXT"sv;
	}
	case CooperativeMatrixProperties2EXT: {
		return "CooperativeMatrixProperties2EXT"sv;
	}
	case PhysicalDeviceShaderSubgroupPartitionedFeaturesEXT: {
		return "PhysicalDeviceShaderSubgroupPartitionedFeaturesEXT"sv;
	}
	case UbmSurfaceCreateInfoSEC: {
		return "UbmSurfaceCreateInfoSEC"sv;
	}
	case FormatProperties4KHR: {
		return "FormatProperties4KHR"sv;
	}
	case ImageCreateFlags2CreateInfoKHR: {
		return "ImageCreateFlags2CreateInfoKHR"sv;
	}
	case ImageUsageFlags2CreateInfoKHR: {
		return "ImageUsageFlags2CreateInfoKHR"sv;
	}
	case ImageViewUsage2CreateInfoKHR: {
		return "ImageViewUsage2CreateInfoKHR"sv;
	}
	case PhysicalDeviceExtendedFlagsFeaturesKHR: {
		return "PhysicalDeviceExtendedFlagsFeaturesKHR"sv;
	}
	case ImageStencilUsage2CreateInfoKHR: {
		return "ImageStencilUsage2CreateInfoKHR"sv;
	}
	case SharedPresentSurfaceCapabilities2KHR: {
		return "SharedPresentSurfaceCapabilities2KHR"sv;
	}
	case PhysicalDeviceShaderOcpMicroscalingTypesFeaturesEXT: {
		return "PhysicalDeviceShaderOcpMicroscalingTypesFeaturesEXT"sv;
	}
	case PhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE: {
		return "PhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE"sv;
	}
	case PhysicalDeviceThrottleHintFeaturesSEC: {
		return "PhysicalDeviceThrottleHintFeaturesSEC"sv;
	}
	case ThrottleHintSubmitInfoSEC: {
		return "ThrottleHintSubmitInfoSEC"sv;
	}
	case DataGraphPipelineNeuralStatisticsCreateInfoARM: {
		return "DataGraphPipelineNeuralStatisticsCreateInfoARM"sv;
	}
	case DataGraphPipelineSessionNeuralStatisticsCreateInfoARM: {
		return "DataGraphPipelineSessionNeuralStatisticsCreateInfoARM"sv;
	}
	case PhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM: {
		return "PhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM"sv;
	}
	case PhysicalDevicePrimitiveRestartIndexFeaturesEXT: {
		return "PhysicalDevicePrimitiveRestartIndexFeaturesEXT"sv;
	}
	case SurfaceCreateInfoOHOS: {
		return "SurfaceCreateInfoOHOS"sv;
	}
	case PhysicalDeviceImageTilingControlFeaturesEXT: {
		return "PhysicalDeviceImageTilingControlFeaturesEXT"sv;
	}
	case ImageTilingControlCreateInfoEXT: {
		return "ImageTilingControlCreateInfoEXT"sv;
	}
	case PhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV: {
		return "PhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV"sv;
	}
	case PhysicalDevicePrivateDataBaseHandleFeaturesNV: {
		return "PhysicalDevicePrivateDataBaseHandleFeaturesNV"sv;
	}
	case PhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE: {
		return "PhysicalDeviceBufferDeviceAddressAllocationAlignmentFeaturesVALVE"sv;
	}
	case PhysicalDeviceBufferDeviceAddressAllocationAlignmentPropertiesVALVE: {
		return "PhysicalDeviceBufferDeviceAddressAllocationAlignmentPropertiesVALVE"sv;
	}
	case BufferDeviceAddressAlignmentAllocateInfoVALVE: {
		return "BufferDeviceAddressAlignmentAllocateInfoVALVE"sv;
	}
	}
	return "EnumElement not part of: StructureType";
}
template<> auto enumToString(SubpassContents enumVal) -> std::string_view {
	using enum SubpassContents;
	switch (enumVal) {
	case Inline: {
		return "Inline"sv;
	}
	case SecondaryCommandBuffers: {
		return "SecondaryCommandBuffers"sv;
	}
	case InlineAndSecondaryCommandBuffersKHR: {
		return "InlineAndSecondaryCommandBuffersKHR"sv;
	}
	}
	return "EnumElement not part of: SubpassContents";
}
template<> auto enumToString(SubpassMergeStatusEXT enumVal) -> std::string_view {
	using enum SubpassMergeStatusEXT;
	switch (enumVal) {
	case Merged: {
		return "Merged"sv;
	}
	case Disallowed: {
		return "Disallowed"sv;
	}
	case NotMergedSideEffects: {
		return "NotMergedSideEffects"sv;
	}
	case NotMergedSamplesMismatch: {
		return "NotMergedSamplesMismatch"sv;
	}
	case NotMergedViewsMismatch: {
		return "NotMergedViewsMismatch"sv;
	}
	case NotMergedAliasing: {
		return "NotMergedAliasing"sv;
	}
	case NotMergedDependencies: {
		return "NotMergedDependencies"sv;
	}
	case NotMergedIncompatibleInputAttachment: {
		return "NotMergedIncompatibleInputAttachment"sv;
	}
	case NotMergedTooManyAttachments: {
		return "NotMergedTooManyAttachments"sv;
	}
	case NotMergedInsufficientStorage: {
		return "NotMergedInsufficientStorage"sv;
	}
	case NotMergedDepthStencilCount: {
		return "NotMergedDepthStencilCount"sv;
	}
	case NotMergedResolveAttachmentReuse: {
		return "NotMergedResolveAttachmentReuse"sv;
	}
	case NotMergedSingleSubpass: {
		return "NotMergedSingleSubpass"sv;
	}
	case NotMergedUnspecified: {
		return "NotMergedUnspecified"sv;
	}
	}
	return "EnumElement not part of: SubpassMergeStatusEXT";
}
template<> auto enumToString(SystemAllocationScope enumVal) -> std::string_view {
	using enum SystemAllocationScope;
	switch (enumVal) {
	case Command: {
		return "Command"sv;
	}
	case Object: {
		return "Object"sv;
	}
	case Cache: {
		return "Cache"sv;
	}
	case Device: {
		return "Device"sv;
	}
	case Instance: {
		return "Instance"sv;
	}
	}
	return "EnumElement not part of: SystemAllocationScope";
}
template<> auto enumToString(TensorTilingARM enumVal) -> std::string_view {
	using enum TensorTilingARM;
	switch (enumVal) {
	case Optimal: {
		return "Optimal"sv;
	}
	case Linear: {
		return "Linear"sv;
	}
	case Brick16Wide: {
		return "Brick16Wide"sv;
	}
	case Brick8Wide: {
		return "Brick8Wide"sv;
	}
	case Brick4Wide: {
		return "Brick4Wide"sv;
	}
	case BlockUInterleaved: {
		return "BlockUInterleaved"sv;
	}
	case BlockUInterleaved64K: {
		return "BlockUInterleaved64K"sv;
	}
	}
	return "EnumElement not part of: TensorTilingARM";
}
template<> auto enumToString(TessellationDomainOrigin enumVal) -> std::string_view {
	using enum TessellationDomainOrigin;
	switch (enumVal) {
	case UpperLeft: {
		return "UpperLeft"sv;
	}
	case LowerLeft: {
		return "LowerLeft"sv;
	}
	}
	return "EnumElement not part of: TessellationDomainOrigin";
}
template<> auto enumToString(ThrottleHintTypeSEC enumVal) -> std::string_view {
	using enum ThrottleHintTypeSEC;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case Low: {
		return "Low"sv;
	}
	case High: {
		return "High"sv;
	}
	}
	return "EnumElement not part of: ThrottleHintTypeSEC";
}
template<> auto enumToString(TimeDomainKHR enumVal) -> std::string_view {
	using enum TimeDomainKHR;
	switch (enumVal) {
	case Device: {
		return "Device"sv;
	}
	case ClockMonotonic: {
		return "ClockMonotonic"sv;
	}
	case ClockMonotonicRaw: {
		return "ClockMonotonicRaw"sv;
	}
	case QueryPerformanceCounter: {
		return "QueryPerformanceCounter"sv;
	}
	case PresentStageLocalEXT: {
		return "PresentStageLocalEXT"sv;
	}
	case SwapchainLocalEXT: {
		return "SwapchainLocalEXT"sv;
	}
	}
	return "EnumElement not part of: TimeDomainKHR";
}
template<> auto enumToString(ValidationCacheHeaderVersionEXT enumVal) -> std::string_view {
	using enum ValidationCacheHeaderVersionEXT;
	switch (enumVal) {
	case One: {
		return "One"sv;
	}
	}
	return "EnumElement not part of: ValidationCacheHeaderVersionEXT";
}
template<> auto enumToString(ValidationCheckEXT enumVal) -> std::string_view {
	using enum ValidationCheckEXT;
	switch (enumVal) {
	case All: {
		return "All"sv;
	}
	case Shaders: {
		return "Shaders"sv;
	}
	}
	return "EnumElement not part of: ValidationCheckEXT";
}
template<> auto enumToString(ValidationFeatureDisableEXT enumVal) -> std::string_view {
	using enum ValidationFeatureDisableEXT;
	switch (enumVal) {
	case All: {
		return "All"sv;
	}
	case Shaders: {
		return "Shaders"sv;
	}
	case ThreadSafety: {
		return "ThreadSafety"sv;
	}
	case ApiParameters: {
		return "ApiParameters"sv;
	}
	case ObjectLifetimes: {
		return "ObjectLifetimes"sv;
	}
	case CoreChecks: {
		return "CoreChecks"sv;
	}
	case UniqueHandles: {
		return "UniqueHandles"sv;
	}
	case ShaderValidationCache: {
		return "ShaderValidationCache"sv;
	}
	}
	return "EnumElement not part of: ValidationFeatureDisableEXT";
}
template<> auto enumToString(ValidationFeatureEnableEXT enumVal) -> std::string_view {
	using enum ValidationFeatureEnableEXT;
	switch (enumVal) {
	case GpuAssisted: {
		return "GpuAssisted"sv;
	}
	case GpuAssistedReserveBindingSlot: {
		return "GpuAssistedReserveBindingSlot"sv;
	}
	case BestPractices: {
		return "BestPractices"sv;
	}
	case DebugPrintf: {
		return "DebugPrintf"sv;
	}
	case SynchronizationValidation: {
		return "SynchronizationValidation"sv;
	}
	}
	return "EnumElement not part of: ValidationFeatureEnableEXT";
}
template<> auto enumToString(VendorId enumVal) -> std::string_view {
	using enum VendorId;
	switch (enumVal) {
	case Khronos: {
		return "Khronos"sv;
	}
	case VIV: {
		return "VIV"sv;
	}
	case VSI: {
		return "VSI"sv;
	}
	case Kazan: {
		return "Kazan"sv;
	}
	case Codeplay: {
		return "Codeplay"sv;
	}
	case MESA: {
		return "MESA"sv;
	}
	case Pocl: {
		return "Pocl"sv;
	}
	case Mobileye: {
		return "Mobileye"sv;
	}
	case Ape: {
		return "Ape"sv;
	}
	}
	return "EnumElement not part of: VendorId";
}
template<> auto enumToString(VertexInputRate enumVal) -> std::string_view {
	using enum VertexInputRate;
	switch (enumVal) {
	case Vertex: {
		return "Vertex"sv;
	}
	case Instance: {
		return "Instance"sv;
	}
	}
	return "EnumElement not part of: VertexInputRate";
}
template<> auto enumToString(VideoEncodeAV1PredictionModeKHR enumVal) -> std::string_view {
	using enum VideoEncodeAV1PredictionModeKHR;
	switch (enumVal) {
	case IntraOnly: {
		return "IntraOnly"sv;
	}
	case SingleReference: {
		return "SingleReference"sv;
	}
	case UnidirectionalCompound: {
		return "UnidirectionalCompound"sv;
	}
	case BidirectionalCompound: {
		return "BidirectionalCompound"sv;
	}
	}
	return "EnumElement not part of: VideoEncodeAV1PredictionModeKHR";
}
template<> auto enumToString(VideoEncodeAV1RateControlGroupKHR enumVal) -> std::string_view {
	using enum VideoEncodeAV1RateControlGroupKHR;
	switch (enumVal) {
	case Intra: {
		return "Intra"sv;
	}
	case Predictive: {
		return "Predictive"sv;
	}
	case Bipredictive: {
		return "Bipredictive"sv;
	}
	}
	return "EnumElement not part of: VideoEncodeAV1RateControlGroupKHR";
}
template<> auto enumToString(VideoEncodeTuningModeKHR enumVal) -> std::string_view {
	using enum VideoEncodeTuningModeKHR;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case HighQuality: {
		return "HighQuality"sv;
	}
	case LowLatency: {
		return "LowLatency"sv;
	}
	case UltraLowLatency: {
		return "UltraLowLatency"sv;
	}
	case Lossless: {
		return "Lossless"sv;
	}
	}
	return "EnumElement not part of: VideoEncodeTuningModeKHR";
}
template<> auto enumToString(ViewportCoordinateSwizzleNV enumVal) -> std::string_view {
	using enum ViewportCoordinateSwizzleNV;
	switch (enumVal) {
	case Positivex: {
		return "Positivex"sv;
	}
	case Negativex: {
		return "Negativex"sv;
	}
	case PositiveY: {
		return "PositiveY"sv;
	}
	case NegativeY: {
		return "NegativeY"sv;
	}
	case PositiveZ: {
		return "PositiveZ"sv;
	}
	case NegativeZ: {
		return "NegativeZ"sv;
	}
	case PositiveW: {
		return "PositiveW"sv;
	}
	case NegativeW: {
		return "NegativeW"sv;
	}
	}
	return "EnumElement not part of: ViewportCoordinateSwizzleNV";
}
template<> auto enumToString(StdVideoAV1ChromaSamplePosition enumVal) -> std::string_view {
	using enum StdVideoAV1ChromaSamplePosition;
	switch (enumVal) {
	case Unknown: {
		return "Unknown"sv;
	}
	case Vertical: {
		return "Vertical"sv;
	}
	case Colocated: {
		return "Colocated"sv;
	}
	case Reserved: {
		return "Reserved"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1ChromaSamplePosition";
}
template<> auto enumToString(StdVideoAV1ColorPrimaries enumVal) -> std::string_view {
	using enum StdVideoAV1ColorPrimaries;
	switch (enumVal) {
	case Bt709: {
		return "Bt709"sv;
	}
	case Unspecified: {
		return "Unspecified"sv;
	}
	case Bt470M: {
		return "Bt470M"sv;
	}
	case Bt470BG: {
		return "Bt470BG"sv;
	}
	case Bt601: {
		return "Bt601"sv;
	}
	case Smpte240: {
		return "Smpte240"sv;
	}
	case GenericFilm: {
		return "GenericFilm"sv;
	}
	case Bt2020: {
		return "Bt2020"sv;
	}
	case Xyz: {
		return "Xyz"sv;
	}
	case Smpte431: {
		return "Smpte431"sv;
	}
	case Smpte432: {
		return "Smpte432"sv;
	}
	case Ebu3213: {
		return "Ebu3213"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1ColorPrimaries";
}
template<> auto enumToString(StdVideoAV1FrameRestorationType enumVal) -> std::string_view {
	using enum StdVideoAV1FrameRestorationType;
	switch (enumVal) {
	case None: {
		return "None"sv;
	}
	case Wiener: {
		return "Wiener"sv;
	}
	case Sgrproj: {
		return "Sgrproj"sv;
	}
	case Switchable: {
		return "Switchable"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1FrameRestorationType";
}
template<> auto enumToString(StdVideoAV1FrameType enumVal) -> std::string_view {
	using enum StdVideoAV1FrameType;
	switch (enumVal) {
	case Key: {
		return "Key"sv;
	}
	case Inter: {
		return "Inter"sv;
	}
	case IntraOnly: {
		return "IntraOnly"sv;
	}
	case Switch: {
		return "Switch"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1FrameType";
}
template<> auto enumToString(StdVideoAV1InterpolationFilter enumVal) -> std::string_view {
	using enum StdVideoAV1InterpolationFilter;
	switch (enumVal) {
	case Eighttap: {
		return "Eighttap"sv;
	}
	case EighttapSmooth: {
		return "EighttapSmooth"sv;
	}
	case EighttapSharp: {
		return "EighttapSharp"sv;
	}
	case Bilinear: {
		return "Bilinear"sv;
	}
	case Switchable: {
		return "Switchable"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1InterpolationFilter";
}
template<> auto enumToString(StdVideoAV1Level enumVal) -> std::string_view {
	using enum StdVideoAV1Level;
	switch (enumVal) {
	case v20: {
		return "v20"sv;
	}
	case v21: {
		return "v21"sv;
	}
	case v22: {
		return "v22"sv;
	}
	case v23: {
		return "v23"sv;
	}
	case v30: {
		return "v30"sv;
	}
	case v31: {
		return "v31"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case v33: {
		return "v33"sv;
	}
	case v40: {
		return "v40"sv;
	}
	case v41: {
		return "v41"sv;
	}
	case v42: {
		return "v42"sv;
	}
	case v43: {
		return "v43"sv;
	}
	case v50: {
		return "v50"sv;
	}
	case v51: {
		return "v51"sv;
	}
	case v52: {
		return "v52"sv;
	}
	case v53: {
		return "v53"sv;
	}
	case v60: {
		return "v60"sv;
	}
	case v61: {
		return "v61"sv;
	}
	case v62: {
		return "v62"sv;
	}
	case v63: {
		return "v63"sv;
	}
	case v70: {
		return "v70"sv;
	}
	case v71: {
		return "v71"sv;
	}
	case v72: {
		return "v72"sv;
	}
	case v73: {
		return "v73"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1Level";
}
template<> auto enumToString(StdVideoAV1MatrixCoefficients enumVal) -> std::string_view {
	using enum StdVideoAV1MatrixCoefficients;
	switch (enumVal) {
	case Identity: {
		return "Identity"sv;
	}
	case Bt709: {
		return "Bt709"sv;
	}
	case Unspecified: {
		return "Unspecified"sv;
	}
	case Reserved3: {
		return "Reserved3"sv;
	}
	case Fcc: {
		return "Fcc"sv;
	}
	case Bt470BG: {
		return "Bt470BG"sv;
	}
	case Bt601: {
		return "Bt601"sv;
	}
	case Smpte240: {
		return "Smpte240"sv;
	}
	case SmpteYcgco: {
		return "SmpteYcgco"sv;
	}
	case Bt2020Ncl: {
		return "Bt2020Ncl"sv;
	}
	case Bt2020Cl: {
		return "Bt2020Cl"sv;
	}
	case Smpte2085: {
		return "Smpte2085"sv;
	}
	case ChromatNcl: {
		return "ChromatNcl"sv;
	}
	case ChromatCl: {
		return "ChromatCl"sv;
	}
	case Ictcp: {
		return "Ictcp"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1MatrixCoefficients";
}
template<> auto enumToString(StdVideoAV1Profile enumVal) -> std::string_view {
	using enum StdVideoAV1Profile;
	switch (enumVal) {
	case Main: {
		return "Main"sv;
	}
	case High: {
		return "High"sv;
	}
	case Professional: {
		return "Professional"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1Profile";
}
template<> auto enumToString(StdVideoAV1ReferenceName enumVal) -> std::string_view {
	using enum StdVideoAV1ReferenceName;
	switch (enumVal) {
	case IntraFrame: {
		return "IntraFrame"sv;
	}
	case LastFrame: {
		return "LastFrame"sv;
	}
	case Last2Frame: {
		return "Last2Frame"sv;
	}
	case Last3Frame: {
		return "Last3Frame"sv;
	}
	case GoldenFrame: {
		return "GoldenFrame"sv;
	}
	case BwdrefFrame: {
		return "BwdrefFrame"sv;
	}
	case Altref2Frame: {
		return "Altref2Frame"sv;
	}
	case AltrefFrame: {
		return "AltrefFrame"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1ReferenceName";
}
template<> auto enumToString(StdVideoAV1TransferCharacteristics enumVal) -> std::string_view {
	using enum StdVideoAV1TransferCharacteristics;
	switch (enumVal) {
	case Reserved0: {
		return "Reserved0"sv;
	}
	case Bt709: {
		return "Bt709"sv;
	}
	case Unspecified: {
		return "Unspecified"sv;
	}
	case Reserved3: {
		return "Reserved3"sv;
	}
	case Bt470M: {
		return "Bt470M"sv;
	}
	case Bt470BG: {
		return "Bt470BG"sv;
	}
	case Bt601: {
		return "Bt601"sv;
	}
	case Smpte240: {
		return "Smpte240"sv;
	}
	case Linear: {
		return "Linear"sv;
	}
	case Log100: {
		return "Log100"sv;
	}
	case Log100Sqrt10: {
		return "Log100Sqrt10"sv;
	}
	case Iec61966: {
		return "Iec61966"sv;
	}
	case Bt1361: {
		return "Bt1361"sv;
	}
	case Srgb: {
		return "Srgb"sv;
	}
	case Bt202010Bit: {
		return "Bt202010Bit"sv;
	}
	case Bt202012Bit: {
		return "Bt202012Bit"sv;
	}
	case Smpte2084: {
		return "Smpte2084"sv;
	}
	case Smpte428: {
		return "Smpte428"sv;
	}
	case Hlg: {
		return "Hlg"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1TransferCharacteristics";
}
template<> auto enumToString(StdVideoAV1TxMode enumVal) -> std::string_view {
	using enum StdVideoAV1TxMode;
	switch (enumVal) {
	case Only4x4: {
		return "Only4x4"sv;
	}
	case Largest: {
		return "Largest"sv;
	}
	case Select: {
		return "Select"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoAV1TxMode";
}
template<> auto enumToString(StdVideoDecodeH264FieldOrderCount enumVal) -> std::string_view {
	using enum StdVideoDecodeH264FieldOrderCount;
	switch (enumVal) {
	case Top: {
		return "Top"sv;
	}
	case Bottom: {
		return "Bottom"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoDecodeH264FieldOrderCount";
}
template<> auto enumToString(StdVideoH264AspectRatioIdc enumVal) -> std::string_view {
	using enum StdVideoH264AspectRatioIdc;
	switch (enumVal) {
	case Unspecified: {
		return "Unspecified"sv;
	}
	case Square: {
		return "Square"sv;
	}
	case v1211: {
		return "v1211"sv;
	}
	case v1011: {
		return "v1011"sv;
	}
	case v1611: {
		return "v1611"sv;
	}
	case v4033: {
		return "v4033"sv;
	}
	case v2411: {
		return "v2411"sv;
	}
	case v2011: {
		return "v2011"sv;
	}
	case v3211: {
		return "v3211"sv;
	}
	case v8033: {
		return "v8033"sv;
	}
	case v1811: {
		return "v1811"sv;
	}
	case v1511: {
		return "v1511"sv;
	}
	case v6433: {
		return "v6433"sv;
	}
	case v16099: {
		return "v16099"sv;
	}
	case v43: {
		return "v43"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case v21: {
		return "v21"sv;
	}
	case ExtendedSar: {
		return "ExtendedSar"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264AspectRatioIdc";
}
template<> auto enumToString(StdVideoH264CabacInitIdc enumVal) -> std::string_view {
	using enum StdVideoH264CabacInitIdc;
	switch (enumVal) {
	case v0: {
		return "v0"sv;
	}
	case v1: {
		return "v1"sv;
	}
	case v2: {
		return "v2"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264CabacInitIdc";
}
template<> auto enumToString(StdVideoH264ChromaFormatIdc enumVal) -> std::string_view {
	using enum StdVideoH264ChromaFormatIdc;
	switch (enumVal) {
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
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264ChromaFormatIdc";
}
template<> auto enumToString(StdVideoH264DisableDeblockingFilterIdc enumVal) -> std::string_view {
	using enum StdVideoH264DisableDeblockingFilterIdc;
	switch (enumVal) {
	case Disabled: {
		return "Disabled"sv;
	}
	case Enabled: {
		return "Enabled"sv;
	}
	case Partial: {
		return "Partial"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264DisableDeblockingFilterIdc";
}
template<> auto enumToString(StdVideoH264LevelIdc enumVal) -> std::string_view {
	using enum StdVideoH264LevelIdc;
	switch (enumVal) {
	case v10: {
		return "v10"sv;
	}
	case v11: {
		return "v11"sv;
	}
	case v12: {
		return "v12"sv;
	}
	case v13: {
		return "v13"sv;
	}
	case v20: {
		return "v20"sv;
	}
	case v21: {
		return "v21"sv;
	}
	case v22: {
		return "v22"sv;
	}
	case v30: {
		return "v30"sv;
	}
	case v31: {
		return "v31"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case v40: {
		return "v40"sv;
	}
	case v41: {
		return "v41"sv;
	}
	case v42: {
		return "v42"sv;
	}
	case v50: {
		return "v50"sv;
	}
	case v51: {
		return "v51"sv;
	}
	case v52: {
		return "v52"sv;
	}
	case v60: {
		return "v60"sv;
	}
	case v61: {
		return "v61"sv;
	}
	case v62: {
		return "v62"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264LevelIdc";
}
template<> auto enumToString(StdVideoH264MemMgmtControlOp enumVal) -> std::string_view {
	using enum StdVideoH264MemMgmtControlOp;
	switch (enumVal) {
	case End: {
		return "End"sv;
	}
	case UnmarkShortTerm: {
		return "UnmarkShortTerm"sv;
	}
	case UnmarkLongTerm: {
		return "UnmarkLongTerm"sv;
	}
	case MarkLongTerm: {
		return "MarkLongTerm"sv;
	}
	case SetMaxLongTermIndex: {
		return "SetMaxLongTermIndex"sv;
	}
	case UnmarkAll: {
		return "UnmarkAll"sv;
	}
	case MarkCurrentAsLongTerm: {
		return "MarkCurrentAsLongTerm"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264MemMgmtControlOp";
}
template<> auto enumToString(StdVideoH264ModificationOfPicNumsIdc enumVal) -> std::string_view {
	using enum StdVideoH264ModificationOfPicNumsIdc;
	switch (enumVal) {
	case ShortTermSubtract: {
		return "ShortTermSubtract"sv;
	}
	case ShortTermAdd: {
		return "ShortTermAdd"sv;
	}
	case LongTerm: {
		return "LongTerm"sv;
	}
	case End: {
		return "End"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264ModificationOfPicNumsIdc";
}
template<> auto enumToString(StdVideoH264NonVclNaluType enumVal) -> std::string_view {
	using enum StdVideoH264NonVclNaluType;
	switch (enumVal) {
	case Sps: {
		return "Sps"sv;
	}
	case Pps: {
		return "Pps"sv;
	}
	case Aud: {
		return "Aud"sv;
	}
	case Prefix: {
		return "Prefix"sv;
	}
	case EndOfSequence: {
		return "EndOfSequence"sv;
	}
	case EndOfStream: {
		return "EndOfStream"sv;
	}
	case Precoded: {
		return "Precoded"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264NonVclNaluType";
}
template<> auto enumToString(StdVideoH264PictureType enumVal) -> std::string_view {
	using enum StdVideoH264PictureType;
	switch (enumVal) {
	case P: {
		return "P"sv;
	}
	case B: {
		return "B"sv;
	}
	case I: {
		return "I"sv;
	}
	case Idr: {
		return "Idr"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264PictureType";
}
template<> auto enumToString(StdVideoH264PocType enumVal) -> std::string_view {
	using enum StdVideoH264PocType;
	switch (enumVal) {
	case v0: {
		return "v0"sv;
	}
	case v1: {
		return "v1"sv;
	}
	case v2: {
		return "v2"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264PocType";
}
template<> auto enumToString(StdVideoH264ProfileIdc enumVal) -> std::string_view {
	using enum StdVideoH264ProfileIdc;
	switch (enumVal) {
	case Baseline: {
		return "Baseline"sv;
	}
	case Main: {
		return "Main"sv;
	}
	case High: {
		return "High"sv;
	}
	case High10: {
		return "High10"sv;
	}
	case High422: {
		return "High422"sv;
	}
	case High444Predictive: {
		return "High444Predictive"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264ProfileIdc";
}
template<> auto enumToString(StdVideoH264SliceType enumVal) -> std::string_view {
	using enum StdVideoH264SliceType;
	switch (enumVal) {
	case P: {
		return "P"sv;
	}
	case B: {
		return "B"sv;
	}
	case I: {
		return "I"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264SliceType";
}
template<> auto enumToString(StdVideoH264WeightedBipredIdc enumVal) -> std::string_view {
	using enum StdVideoH264WeightedBipredIdc;
	switch (enumVal) {
	case Default: {
		return "Default"sv;
	}
	case Explicit: {
		return "Explicit"sv;
	}
	case Implicit: {
		return "Implicit"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH264WeightedBipredIdc";
}
template<> auto enumToString(StdVideoH265AspectRatioIdc enumVal) -> std::string_view {
	using enum StdVideoH265AspectRatioIdc;
	switch (enumVal) {
	case Unspecified: {
		return "Unspecified"sv;
	}
	case Square: {
		return "Square"sv;
	}
	case v1211: {
		return "v1211"sv;
	}
	case v1011: {
		return "v1011"sv;
	}
	case v1611: {
		return "v1611"sv;
	}
	case v4033: {
		return "v4033"sv;
	}
	case v2411: {
		return "v2411"sv;
	}
	case v2011: {
		return "v2011"sv;
	}
	case v3211: {
		return "v3211"sv;
	}
	case v8033: {
		return "v8033"sv;
	}
	case v1811: {
		return "v1811"sv;
	}
	case v1511: {
		return "v1511"sv;
	}
	case v6433: {
		return "v6433"sv;
	}
	case v16099: {
		return "v16099"sv;
	}
	case v43: {
		return "v43"sv;
	}
	case v32: {
		return "v32"sv;
	}
	case v21: {
		return "v21"sv;
	}
	case ExtendedSar: {
		return "ExtendedSar"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH265AspectRatioIdc";
}
template<> auto enumToString(StdVideoH265ChromaFormatIdc enumVal) -> std::string_view {
	using enum StdVideoH265ChromaFormatIdc;
	switch (enumVal) {
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
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH265ChromaFormatIdc";
}
template<> auto enumToString(StdVideoH265LevelIdc enumVal) -> std::string_view {
	using enum StdVideoH265LevelIdc;
	switch (enumVal) {
	case v10: {
		return "v10"sv;
	}
	case v20: {
		return "v20"sv;
	}
	case v21: {
		return "v21"sv;
	}
	case v30: {
		return "v30"sv;
	}
	case v31: {
		return "v31"sv;
	}
	case v40: {
		return "v40"sv;
	}
	case v41: {
		return "v41"sv;
	}
	case v50: {
		return "v50"sv;
	}
	case v51: {
		return "v51"sv;
	}
	case v52: {
		return "v52"sv;
	}
	case v60: {
		return "v60"sv;
	}
	case v61: {
		return "v61"sv;
	}
	case v62: {
		return "v62"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH265LevelIdc";
}
template<> auto enumToString(StdVideoH265PictureType enumVal) -> std::string_view {
	using enum StdVideoH265PictureType;
	switch (enumVal) {
	case P: {
		return "P"sv;
	}
	case B: {
		return "B"sv;
	}
	case I: {
		return "I"sv;
	}
	case Idr: {
		return "Idr"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH265PictureType";
}
template<> auto enumToString(StdVideoH265ProfileIdc enumVal) -> std::string_view {
	using enum StdVideoH265ProfileIdc;
	switch (enumVal) {
	case Main: {
		return "Main"sv;
	}
	case Main10: {
		return "Main10"sv;
	}
	case MainStillPicture: {
		return "MainStillPicture"sv;
	}
	case FormatRangeExtensions: {
		return "FormatRangeExtensions"sv;
	}
	case SccExtensions: {
		return "SccExtensions"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH265ProfileIdc";
}
template<> auto enumToString(StdVideoH265SliceType enumVal) -> std::string_view {
	using enum StdVideoH265SliceType;
	switch (enumVal) {
	case B: {
		return "B"sv;
	}
	case P: {
		return "P"sv;
	}
	case I: {
		return "I"sv;
	}
	case Invalid: {
		return "Invalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoH265SliceType";
}
template<> auto enumToString(StdVideoVP9ColorSpace enumVal) -> std::string_view {
	using enum StdVideoVP9ColorSpace;
	switch (enumVal) {
	case StdVideoVp9ColorSpaceUnknown: {
		return "StdVideoVp9ColorSpaceUnknown"sv;
	}
	case StdVideoVp9ColorSpaceBt601: {
		return "StdVideoVp9ColorSpaceBt601"sv;
	}
	case StdVideoVp9ColorSpaceBt709: {
		return "StdVideoVp9ColorSpaceBt709"sv;
	}
	case StdVideoVp9ColorSpaceSmpte170: {
		return "StdVideoVp9ColorSpaceSmpte170"sv;
	}
	case StdVideoVp9ColorSpaceSmpte240: {
		return "StdVideoVp9ColorSpaceSmpte240"sv;
	}
	case StdVideoVp9ColorSpaceBt2020: {
		return "StdVideoVp9ColorSpaceBt2020"sv;
	}
	case StdVideoVp9ColorSpaceReserved: {
		return "StdVideoVp9ColorSpaceReserved"sv;
	}
	case StdVideoVp9ColorSpaceRgb: {
		return "StdVideoVp9ColorSpaceRgb"sv;
	}
	case StdVideoVp9ColorSpaceInvalid: {
		return "StdVideoVp9ColorSpaceInvalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoVP9ColorSpace";
}
template<> auto enumToString(StdVideoVP9FrameType enumVal) -> std::string_view {
	using enum StdVideoVP9FrameType;
	switch (enumVal) {
	case StdVideoVp9FrameTypeKey: {
		return "StdVideoVp9FrameTypeKey"sv;
	}
	case StdVideoVp9FrameTypeNonKey: {
		return "StdVideoVp9FrameTypeNonKey"sv;
	}
	case StdVideoVp9FrameTypeInvalid: {
		return "StdVideoVp9FrameTypeInvalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoVP9FrameType";
}
template<> auto enumToString(StdVideoVP9InterpolationFilter enumVal) -> std::string_view {
	using enum StdVideoVP9InterpolationFilter;
	switch (enumVal) {
	case StdVideoVp9InterpolationFilterEighttap: {
		return "StdVideoVp9InterpolationFilterEighttap"sv;
	}
	case StdVideoVp9InterpolationFilterEighttapSmooth: {
		return "StdVideoVp9InterpolationFilterEighttapSmooth"sv;
	}
	case StdVideoVp9InterpolationFilterEighttapSharp: {
		return "StdVideoVp9InterpolationFilterEighttapSharp"sv;
	}
	case StdVideoVp9InterpolationFilterBilinear: {
		return "StdVideoVp9InterpolationFilterBilinear"sv;
	}
	case StdVideoVp9InterpolationFilterSwitchable: {
		return "StdVideoVp9InterpolationFilterSwitchable"sv;
	}
	case StdVideoVp9InterpolationFilterInvalid: {
		return "StdVideoVp9InterpolationFilterInvalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoVP9InterpolationFilter";
}
template<> auto enumToString(StdVideoVP9Level enumVal) -> std::string_view {
	using enum StdVideoVP9Level;
	switch (enumVal) {
	case StdVideoVp9Level10: {
		return "StdVideoVp9Level10"sv;
	}
	case StdVideoVp9Level11: {
		return "StdVideoVp9Level11"sv;
	}
	case StdVideoVp9Level20: {
		return "StdVideoVp9Level20"sv;
	}
	case StdVideoVp9Level21: {
		return "StdVideoVp9Level21"sv;
	}
	case StdVideoVp9Level30: {
		return "StdVideoVp9Level30"sv;
	}
	case StdVideoVp9Level31: {
		return "StdVideoVp9Level31"sv;
	}
	case StdVideoVp9Level40: {
		return "StdVideoVp9Level40"sv;
	}
	case StdVideoVp9Level41: {
		return "StdVideoVp9Level41"sv;
	}
	case StdVideoVp9Level50: {
		return "StdVideoVp9Level50"sv;
	}
	case StdVideoVp9Level51: {
		return "StdVideoVp9Level51"sv;
	}
	case StdVideoVp9Level52: {
		return "StdVideoVp9Level52"sv;
	}
	case StdVideoVp9Level60: {
		return "StdVideoVp9Level60"sv;
	}
	case StdVideoVp9Level61: {
		return "StdVideoVp9Level61"sv;
	}
	case StdVideoVp9Level62: {
		return "StdVideoVp9Level62"sv;
	}
	case StdVideoVp9LevelInvalid: {
		return "StdVideoVp9LevelInvalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoVP9Level";
}
template<> auto enumToString(StdVideoVP9Profile enumVal) -> std::string_view {
	using enum StdVideoVP9Profile;
	switch (enumVal) {
	case StdVideoVp9Profile0: {
		return "StdVideoVp9Profile0"sv;
	}
	case StdVideoVp9Profile1: {
		return "StdVideoVp9Profile1"sv;
	}
	case StdVideoVp9Profile2: {
		return "StdVideoVp9Profile2"sv;
	}
	case StdVideoVp9Profile3: {
		return "StdVideoVp9Profile3"sv;
	}
	case StdVideoVp9ProfileInvalid: {
		return "StdVideoVp9ProfileInvalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoVP9Profile";
}
template<> auto enumToString(StdVideoVP9ReferenceName enumVal) -> std::string_view {
	using enum StdVideoVP9ReferenceName;
	switch (enumVal) {
	case StdVideoVp9ReferenceNameIntraFrame: {
		return "StdVideoVp9ReferenceNameIntraFrame"sv;
	}
	case StdVideoVp9ReferenceNameLastFrame: {
		return "StdVideoVp9ReferenceNameLastFrame"sv;
	}
	case StdVideoVp9ReferenceNameGoldenFrame: {
		return "StdVideoVp9ReferenceNameGoldenFrame"sv;
	}
	case StdVideoVp9ReferenceNameAltrefFrame: {
		return "StdVideoVp9ReferenceNameAltrefFrame"sv;
	}
	case StdVideoVp9ReferenceNameInvalid: {
		return "StdVideoVp9ReferenceNameInvalid"sv;
	}
	}
	return "EnumElement not part of: StdVideoVP9ReferenceName";
}
// NOLINTEND(readability-function-size)
} // namespace VkBindings::Reflections
