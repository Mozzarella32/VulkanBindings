#pragma once

#include "VkBindings/BaseTypes.hpp"
#include "VkBindings/Bits.hpp"
#include "VkBindings/Constants.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Flags.hpp"
#include "VkBindings/FunctionPtrs.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/private/StructTemplates/AssignableHandleInterface.hpp"
#include "VkBindings/private/StructTemplates/FixedStringInterface.hpp"
#include "VkBindings/private/StructTemplates/InOutString.hpp"
#include "VkBindings/private/StructTemplates/VecViewInterface.hpp"

#include <array>
#include <cstddef>
#include <cstdint>

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-non-private-member-variables-in-classes, misc-non-private-member-variables-in-classes, cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-type-member-init, bugprone-invalid-enum-default-initialization)
struct StdVideoAV1CDEF {
	uint8_t                                                           cdef_damping_minus_3 = 0;
	uint8_t                                                           cdef_bits            = 0;
	std::array<uint8_t, Constants::StdVideoAV1MaxCdefFilterStrengths> cdef_y_pri_strength  = {};
	std::array<uint8_t, Constants::StdVideoAV1MaxCdefFilterStrengths> cdef_y_sec_strength  = {};
	std::array<uint8_t, Constants::StdVideoAV1MaxCdefFilterStrengths> cdef_uv_pri_strength = {};
	std::array<uint8_t, Constants::StdVideoAV1MaxCdefFilterStrengths> cdef_uv_sec_strength = {};
};
struct StdVideoAV1ColorConfigFlags {
	uint32_t mono_chrome: 1                    = 0;
	uint32_t color_range: 1                    = 0;
	uint32_t separate_uv_delta_q: 1            = 0;
	uint32_t color_description_present_flag: 1 = 0;
	uint32_t reserved: 28                      = 0;
};
struct StdVideoAV1FilmGrainFlags {
	uint32_t chroma_scaling_from_luma: 1 = 0;
	uint32_t overlap_flag: 1             = 0;
	uint32_t clip_to_restricted_range: 1 = 0;
	uint32_t update_grain: 1             = 0;
	uint32_t reserved: 28                = 0;
};
struct StdVideoAV1GlobalMotion {
	std::array<uint8_t, Constants::StdVideoAV1NumRefFrames>                                                       GmType    = {};
	std::array<std::array<int32_t, Constants::StdVideoAV1NumRefFrames>, Constants::StdVideoAV1GlobalMotionParams> gm_params = {};
};
struct StdVideoAV1LoopFilterFlags {
	uint32_t loop_filter_delta_enabled: 1 = 0;
	uint32_t loop_filter_delta_update: 1  = 0;
	uint32_t reserved: 30                 = 0;
};
struct StdVideoAV1LoopRestoration {
	std::array<StdVideoAV1FrameRestorationType, Constants::StdVideoAV1MaxNumPlanes> FrameRestorationType = {};
	std::array<uint16_t, Constants::StdVideoAV1MaxNumPlanes>                        LoopRestorationSize  = {};
};
struct StdVideoAV1QuantizationFlags {
	uint32_t using_qmatrix: 1 = 0;
	uint32_t diff_uv_delta: 1 = 0;
	uint32_t reserved: 30     = 0;
};
struct StdVideoAV1Segmentation {
	std::array<uint8_t, Constants::StdVideoAV1MaxSegments>                                              FeatureEnabled = {};
	std::array<std::array<int16_t, Constants::StdVideoAV1MaxSegments>, Constants::StdVideoAV1SegLvlMax> FeatureData    = {};
};
struct StdVideoAV1SequenceHeaderFlags {
	uint32_t still_picture: 1                      = 0;
	uint32_t reduced_still_picture_header: 1       = 0;
	uint32_t use_128x128_superblock: 1             = 0;
	uint32_t enable_filter_intra: 1                = 0;
	uint32_t enable_intra_edge_filter: 1           = 0;
	uint32_t enable_interintra_compound: 1         = 0;
	uint32_t enable_masked_compound: 1             = 0;
	uint32_t enable_warped_motion: 1               = 0;
	uint32_t enable_dual_filter: 1                 = 0;
	uint32_t enable_order_hint: 1                  = 0;
	uint32_t enable_jnt_comp: 1                    = 0;
	uint32_t enable_ref_frame_mvs: 1               = 0;
	uint32_t frame_id_numbers_present_flag: 1      = 0;
	uint32_t enable_superres: 1                    = 0;
	uint32_t enable_cdef: 1                        = 0;
	uint32_t enable_restoration: 1                 = 0;
	uint32_t film_grain_params_present: 1          = 0;
	uint32_t timing_info_present_flag: 1           = 0;
	uint32_t initial_display_delay_present_flag: 1 = 0;
	uint32_t reserved: 13                          = 0;
};
struct StdVideoAV1TileInfoFlags {
	uint32_t uniform_tile_spacing_flag: 1 = 0;
	uint32_t reserved: 31                 = 0;
};
struct StdVideoAV1TimingInfoFlags {
	uint32_t equal_picture_interval: 1 = 0;
	uint32_t reserved: 31              = 0;
};
struct StdVideoDecodeAV1PictureInfoFlags {
	uint32_t error_resilient_mode: 1             = 0;
	uint32_t disable_cdf_update: 1               = 0;
	uint32_t use_superres: 1                     = 0;
	uint32_t render_and_frame_size_different: 1  = 0;
	uint32_t allow_screen_content_tools: 1       = 0;
	uint32_t is_filter_switchable: 1             = 0;
	uint32_t force_integer_mv: 1                 = 0;
	uint32_t frame_size_override_flag: 1         = 0;
	uint32_t buffer_removal_time_present_flag: 1 = 0;
	uint32_t allow_intrabc: 1                    = 0;
	uint32_t frame_refs_short_signaling: 1       = 0;
	uint32_t allow_high_precision_mv: 1          = 0;
	uint32_t is_motion_mode_switchable: 1        = 0;
	uint32_t use_ref_frame_mvs: 1                = 0;
	uint32_t disable_frame_end_update_cdf: 1     = 0;
	uint32_t allow_warped_motion: 1              = 0;
	uint32_t reduced_tx_set: 1                   = 0;
	uint32_t reference_select: 1                 = 0;
	uint32_t skip_mode_present: 1                = 0;
	uint32_t delta_q_present: 1                  = 0;
	uint32_t delta_lf_present: 1                 = 0;
	uint32_t delta_lf_multi: 1                   = 0;
	uint32_t segmentation_enabled: 1             = 0;
	uint32_t segmentation_update_map: 1          = 0;
	uint32_t segmentation_temporal_update: 1     = 0;
	uint32_t segmentation_update_data: 1         = 0;
	uint32_t UsesLr: 1                           = 0;
	uint32_t usesChromaLr: 1                     = 0;
	uint32_t apply_grain: 1                      = 0;
	uint32_t reserved: 3                         = 0;
};
struct StdVideoDecodeAV1ReferenceInfoFlags {
	uint32_t disable_frame_end_update_cdf: 1 = 0;
	uint32_t segmentation_enabled: 1         = 0;
	uint32_t reserved: 30                    = 0;
};
struct StdVideoDecodeH264PictureInfoFlags {
	uint32_t field_pic_flag: 1           = 0;
	uint32_t is_intra: 1                 = 0;
	uint32_t IdrPicFlag: 1               = 0;
	uint32_t bottom_field_flag: 1        = 0;
	uint32_t is_reference: 1             = 0;
	uint32_t complementary_field_pair: 1 = 0;
};
struct StdVideoDecodeH264ReferenceInfoFlags {
	uint32_t top_field_flag: 1               = 0;
	uint32_t bottom_field_flag: 1            = 0;
	uint32_t used_for_long_term_reference: 1 = 0;
	uint32_t is_non_existing: 1              = 0;
};
struct StdVideoDecodeH265PictureInfoFlags {
	uint32_t IrapPicFlag: 1                     = 0;
	uint32_t IdrPicFlag: 1                      = 0;
	uint32_t IsReference: 1                     = 0;
	uint32_t short_term_ref_pic_set_sps_flag: 1 = 0;
};
struct StdVideoDecodeH265ReferenceInfoFlags {
	uint32_t used_for_long_term_reference: 1 = 0;
	uint32_t unused_for_reference: 1         = 0;
};
struct StdVideoDecodeVP9PictureInfoFlags {
	uint32_t error_resilient_mode: 1         = 0;
	uint32_t intra_only: 1                   = 0;
	uint32_t allow_high_precision_mv: 1      = 0;
	uint32_t refresh_frame_context: 1        = 0;
	uint32_t frame_parallel_decoding_mode: 1 = 0;
	uint32_t segmentation_enabled: 1         = 0;
	uint32_t show_frame: 1                   = 0;
	uint32_t UsePrevFrameMvs: 1              = 0;
	uint32_t reserved: 24                    = 0;
};
struct StdVideoEncodeAV1DecoderModelInfo {
	uint8_t  buffer_delay_length_minus_1            = 0;
	uint8_t  buffer_removal_time_length_minus_1     = 0;
	uint8_t  frame_presentation_time_length_minus_1 = 0;
	uint8_t  reserved1                              = 0;
	uint32_t num_units_in_decoding_tick             = 0;
};
struct StdVideoEncodeAV1ExtensionHeader {
	uint8_t temporal_id = 0;
	uint8_t spatial_id  = 0;
};
struct StdVideoEncodeAV1OperatingPointInfoFlags {
	uint32_t decoder_model_present_for_this_op: 1         = 0;
	uint32_t low_delay_mode_flag: 1                       = 0;
	uint32_t initial_display_delay_present_for_this_op: 1 = 0;
	uint32_t reserved: 29                                 = 0;
};
struct StdVideoEncodeAV1PictureInfoFlags {
	uint32_t error_resilient_mode: 1             = 0;
	uint32_t disable_cdf_update: 1               = 0;
	uint32_t use_superres: 1                     = 0;
	uint32_t render_and_frame_size_different: 1  = 0;
	uint32_t allow_screen_content_tools: 1       = 0;
	uint32_t is_filter_switchable: 1             = 0;
	uint32_t force_integer_mv: 1                 = 0;
	uint32_t frame_size_override_flag: 1         = 0;
	uint32_t buffer_removal_time_present_flag: 1 = 0;
	uint32_t allow_intrabc: 1                    = 0;
	uint32_t frame_refs_short_signaling: 1       = 0;
	uint32_t allow_high_precision_mv: 1          = 0;
	uint32_t is_motion_mode_switchable: 1        = 0;
	uint32_t use_ref_frame_mvs: 1                = 0;
	uint32_t disable_frame_end_update_cdf: 1     = 0;
	uint32_t allow_warped_motion: 1              = 0;
	uint32_t reduced_tx_set: 1                   = 0;
	uint32_t skip_mode_present: 1                = 0;
	uint32_t delta_q_present: 1                  = 0;
	uint32_t delta_lf_present: 1                 = 0;
	uint32_t delta_lf_multi: 1                   = 0;
	uint32_t segmentation_enabled: 1             = 0;
	uint32_t segmentation_update_map: 1          = 0;
	uint32_t segmentation_temporal_update: 1     = 0;
	uint32_t segmentation_update_data: 1         = 0;
	uint32_t UsesLr: 1                           = 0;
	uint32_t usesChromaLr: 1                     = 0;
	uint32_t show_frame: 1                       = 0;
	uint32_t showable_frame: 1                   = 0;
	uint32_t reserved: 3                         = 0;
};
struct StdVideoEncodeAV1ReferenceInfoFlags {
	uint32_t disable_frame_end_update_cdf: 1 = 0;
	uint32_t segmentation_enabled: 1         = 0;
	uint32_t reserved: 30                    = 0;
};
struct StdVideoEncodeH264PictureInfoFlags {
	uint32_t IdrPicFlag: 1                         = 0;
	uint32_t is_reference: 1                       = 0;
	uint32_t no_output_of_prior_pics_flag: 1       = 0;
	uint32_t long_term_reference_flag: 1           = 0;
	uint32_t adaptive_ref_pic_marking_mode_flag: 1 = 0;
	uint32_t reserved: 27                          = 0;
};
struct StdVideoEncodeH264RefListModEntry {
	StdVideoH264ModificationOfPicNumsIdc modification_of_pic_nums_idc = StdVideoH264ModificationOfPicNumsIdc::ShortTermSubtract;
	uint16_t                             abs_diff_pic_num_minus1      = 0;
	uint16_t                             long_term_pic_num            = 0;
};
struct StdVideoEncodeH264RefPicMarkingEntry {
	StdVideoH264MemMgmtControlOp memory_management_control_operation = StdVideoH264MemMgmtControlOp::End;
	uint16_t                     difference_of_pic_nums_minus1       = 0;
	uint16_t                     long_term_pic_num                   = 0;
	uint16_t                     long_term_frame_idx                 = 0;
	uint16_t                     max_long_term_frame_idx_plus1       = 0;
};
struct StdVideoEncodeH264ReferenceInfoFlags {
	uint32_t used_for_long_term_reference: 1 = 0;
	uint32_t reserved: 31                    = 0;
};
struct StdVideoEncodeH264ReferenceListsInfoFlags {
	uint32_t ref_pic_list_modification_flag_l0: 1 = 0;
	uint32_t ref_pic_list_modification_flag_l1: 1 = 0;
	uint32_t reserved: 30                         = 0;
};
struct StdVideoEncodeH264SliceHeaderFlags {
	uint32_t direct_spatial_mv_pred_flag: 1      = 0;
	uint32_t num_ref_idx_active_override_flag: 1 = 0;
	uint32_t reserved: 30                        = 0;
};
struct StdVideoEncodeH264WeightTableFlags {
	uint32_t luma_weight_l0_flag   = 0;
	uint32_t chroma_weight_l0_flag = 0;
	uint32_t luma_weight_l1_flag   = 0;
	uint32_t chroma_weight_l1_flag = 0;
};
struct StdVideoEncodeH265LongTermRefPics {
	uint8_t                                                           num_long_term_sps          = 0;
	uint8_t                                                           num_long_term_pics         = 0;
	std::array<uint8_t, Constants::StdVideoH265MaxLongTermRefPicsSps> lt_idx_sps                 = {};
	std::array<uint8_t, Constants::StdVideoH265MaxLongTermPics>       poc_lsb_lt                 = {};
	uint16_t                                                          used_by_curr_pic_lt_flag   = 0;
	std::array<uint8_t, Constants::StdVideoH265MaxDeltaPoc>           delta_poc_msb_present_flag = {};
	std::array<uint8_t, Constants::StdVideoH265MaxDeltaPoc>           delta_poc_msb_cycle_lt     = {};
};
struct StdVideoEncodeH265PictureInfoFlags {
	uint32_t is_reference: 1                    = 0;
	uint32_t IrapPicFlag: 1                     = 0;
	uint32_t used_for_long_term_reference: 1    = 0;
	uint32_t discardable_flag: 1                = 0;
	uint32_t cross_layer_bla_flag: 1            = 0;
	uint32_t pic_output_flag: 1                 = 0;
	uint32_t no_output_of_prior_pics_flag: 1    = 0;
	uint32_t short_term_ref_pic_set_sps_flag: 1 = 0;
	uint32_t slice_temporal_mvp_enabled_flag: 1 = 0;
	uint32_t reserved: 23                       = 0;
};
struct StdVideoEncodeH265ReferenceInfoFlags {
	uint32_t used_for_long_term_reference: 1 = 0;
	uint32_t unused_for_reference: 1         = 0;
	uint32_t reserved: 30                    = 0;
};
struct StdVideoEncodeH265ReferenceListsInfoFlags {
	uint32_t ref_pic_list_modification_flag_l0: 1 = 0;
	uint32_t ref_pic_list_modification_flag_l1: 1 = 0;
	uint32_t reserved: 30                         = 0;
};
struct StdVideoEncodeH265SliceSegmentHeaderFlags {
	uint32_t first_slice_segment_in_pic_flag: 1              = 0;
	uint32_t dependent_slice_segment_flag: 1                 = 0;
	uint32_t slice_sao_luma_flag: 1                          = 0;
	uint32_t slice_sao_chroma_flag: 1                        = 0;
	uint32_t num_ref_idx_active_override_flag: 1             = 0;
	uint32_t mvd_l1_zero_flag: 1                             = 0;
	uint32_t cabac_init_flag: 1                              = 0;
	uint32_t cu_chroma_qp_offset_enabled_flag: 1             = 0;
	uint32_t deblocking_filter_override_flag: 1              = 0;
	uint32_t slice_deblocking_filter_disabled_flag: 1        = 0;
	uint32_t collocated_from_l0_flag: 1                      = 0;
	uint32_t slice_loop_filter_across_slices_enabled_flag: 1 = 0;
	uint32_t reserved: 20                                    = 0;
};
struct StdVideoEncodeH265WeightTableFlags {
	uint16_t luma_weight_l0_flag   = 0;
	uint16_t chroma_weight_l0_flag = 0;
	uint16_t luma_weight_l1_flag   = 0;
	uint16_t chroma_weight_l1_flag = 0;
};
struct StdVideoH264HrdParameters {
	uint8_t                                                     cpb_cnt_minus1                          = 0;
	uint8_t                                                     bit_rate_scale                          = 0;
	uint8_t                                                     cpb_size_scale                          = 0;
	uint8_t                                                     reserved1                               = 0;
	std::array<uint32_t, Constants::StdVideoH264CpbCntListSize> bit_rate_value_minus1                   = {};
	std::array<uint32_t, Constants::StdVideoH264CpbCntListSize> cpb_size_value_minus1                   = {};
	std::array<uint8_t, Constants::StdVideoH264CpbCntListSize>  cbr_flag                                = {};
	uint32_t                                                    initial_cpb_removal_delay_length_minus1 = 0;
	uint32_t                                                    cpb_removal_delay_length_minus1         = 0;
	uint32_t                                                    dpb_output_delay_length_minus1          = 0;
	uint32_t                                                    time_offset_length                      = 0;
};
struct StdVideoH264PpsFlags {
	uint32_t transform_8x8_mode_flag: 1                      = 0;
	uint32_t redundant_pic_cnt_present_flag: 1               = 0;
	uint32_t constrained_intra_pred_flag: 1                  = 0;
	uint32_t deblocking_filter_control_present_flag: 1       = 0;
	uint32_t weighted_pred_flag: 1                           = 0;
	uint32_t bottom_field_pic_order_in_frame_present_flag: 1 = 0;
	uint32_t entropy_coding_mode_flag: 1                     = 0;
	uint32_t pic_scaling_matrix_present_flag: 1              = 0;
};
struct StdVideoH264ScalingLists {
	uint16_t                                                                                                                         scaling_list_present_mask       = 0;
	uint16_t                                                                                                                         use_default_scaling_matrix_mask = 0;
	std::array<std::array<uint8_t, Constants::StdVideoH264ScalingList4x4NumLists>, Constants::StdVideoH264ScalingList4x4NumElements> ScalingList4x4                  = {};
	std::array<std::array<uint8_t, Constants::StdVideoH264ScalingList8x8NumLists>, Constants::StdVideoH264ScalingList8x8NumElements> ScalingList8x8                  = {};
};
struct StdVideoH264SpsFlags {
	uint32_t constraint_set0_flag: 1                 = 0;
	uint32_t constraint_set1_flag: 1                 = 0;
	uint32_t constraint_set2_flag: 1                 = 0;
	uint32_t constraint_set3_flag: 1                 = 0;
	uint32_t constraint_set4_flag: 1                 = 0;
	uint32_t constraint_set5_flag: 1                 = 0;
	uint32_t direct_8x8_inference_flag: 1            = 0;
	uint32_t mb_adaptive_frame_field_flag: 1         = 0;
	uint32_t frame_mbs_only_flag: 1                  = 0;
	uint32_t delta_pic_order_always_zero_flag: 1     = 0;
	uint32_t separate_colour_plane_flag: 1           = 0;
	uint32_t gaps_in_frame_num_value_allowed_flag: 1 = 0;
	uint32_t qpprime_y_zero_transform_bypass_flag: 1 = 0;
	uint32_t frame_cropping_flag: 1                  = 0;
	uint32_t seq_scaling_matrix_present_flag: 1      = 0;
	uint32_t vui_parameters_present_flag: 1          = 0;
};
struct StdVideoH264SpsVuiFlags {
	uint32_t aspect_ratio_info_present_flag: 1  = 0;
	uint32_t overscan_info_present_flag: 1      = 0;
	uint32_t overscan_appropriate_flag: 1       = 0;
	uint32_t video_signal_type_present_flag: 1  = 0;
	uint32_t video_full_range_flag: 1           = 0;
	uint32_t color_description_present_flag: 1  = 0;
	uint32_t chroma_loc_info_present_flag: 1    = 0;
	uint32_t timing_info_present_flag: 1        = 0;
	uint32_t fixed_frame_rate_flag: 1           = 0;
	uint32_t bitstream_restriction_flag: 1      = 0;
	uint32_t nal_hrd_parameters_present_flag: 1 = 0;
	uint32_t vcl_hrd_parameters_present_flag: 1 = 0;
};
struct StdVideoH265DecPicBufMgr {
	std::array<uint32_t, Constants::StdVideoH265SublayersListSize> max_latency_increase_plus1   = {};
	std::array<uint8_t, Constants::StdVideoH265SublayersListSize>  max_dec_pic_buffering_minus1 = {};
	std::array<uint8_t, Constants::StdVideoH265SublayersListSize>  max_num_reorder_pics         = {};
};
struct StdVideoH265HrdFlags {
	uint32_t nal_hrd_parameters_present_flag: 1           = 0;
	uint32_t vcl_hrd_parameters_present_flag: 1           = 0;
	uint32_t sub_pic_hrd_params_present_flag: 1           = 0;
	uint32_t sub_pic_cpb_params_in_pic_timing_sei_flag: 1 = 0;
	uint32_t fixed_pic_rate_general_flag: 8               = 0;
	uint32_t fixed_pic_rate_within_cvs_flag: 8            = 0;
	uint32_t low_delay_hrd_flag: 8                        = 0;
};
struct StdVideoH265LongTermRefPicsSps {
	uint32_t                                                           used_by_curr_pic_lt_sps_flag = 0;
	std::array<uint32_t, Constants::StdVideoH265MaxLongTermRefPicsSps> lt_ref_pic_poc_lsb_sps       = {};
};
struct StdVideoH265PpsFlags {
	uint32_t dependent_slice_segments_enabled_flag: 1           = 0;
	uint32_t output_flag_present_flag: 1                        = 0;
	uint32_t sign_data_hiding_enabled_flag: 1                   = 0;
	uint32_t cabac_init_present_flag: 1                         = 0;
	uint32_t constrained_intra_pred_flag: 1                     = 0;
	uint32_t transform_skip_enabled_flag: 1                     = 0;
	uint32_t cu_qp_delta_enabled_flag: 1                        = 0;
	uint32_t pps_slice_chroma_qp_offsets_present_flag: 1        = 0;
	uint32_t weighted_pred_flag: 1                              = 0;
	uint32_t weighted_bipred_flag: 1                            = 0;
	uint32_t transquant_bypass_enabled_flag: 1                  = 0;
	uint32_t tiles_enabled_flag: 1                              = 0;
	uint32_t entropy_coding_sync_enabled_flag: 1                = 0;
	uint32_t uniform_spacing_flag: 1                            = 0;
	uint32_t loop_filter_across_tiles_enabled_flag: 1           = 0;
	uint32_t pps_loop_filter_across_slices_enabled_flag: 1      = 0;
	uint32_t deblocking_filter_control_present_flag: 1          = 0;
	uint32_t deblocking_filter_override_enabled_flag: 1         = 0;
	uint32_t pps_deblocking_filter_disabled_flag: 1             = 0;
	uint32_t pps_scaling_list_data_present_flag: 1              = 0;
	uint32_t lists_modification_present_flag: 1                 = 0;
	uint32_t slice_segment_header_extension_present_flag: 1     = 0;
	uint32_t pps_extension_present_flag: 1                      = 0;
	uint32_t cross_component_prediction_enabled_flag: 1         = 0;
	uint32_t chroma_qp_offset_list_enabled_flag: 1              = 0;
	uint32_t pps_curr_pic_ref_enabled_flag: 1                   = 0;
	uint32_t residual_adaptive_colour_transform_enabled_flag: 1 = 0;
	uint32_t pps_slice_act_qp_offsets_present_flag: 1           = 0;
	uint32_t pps_palette_predictor_initializers_present_flag: 1 = 0;
	uint32_t monochrome_palette_flag: 1                         = 0;
	uint32_t pps_range_extension_flag: 1                        = 0;
};
struct StdVideoH265PredictorPaletteEntries {
	std::array<std::array<uint16_t, Constants::StdVideoH265PredictorPaletteComponentsListSize>, Constants::StdVideoH265PredictorPaletteCompEntriesListSize> PredictorPaletteEntries = {};
};
struct StdVideoH265ProfileTierLevelFlags {
	uint32_t general_tier_flag: 1                  = 0;
	uint32_t general_progressive_source_flag: 1    = 0;
	uint32_t general_interlaced_source_flag: 1     = 0;
	uint32_t general_non_packed_constraint_flag: 1 = 0;
	uint32_t general_frame_only_constraint_flag: 1 = 0;
};
struct StdVideoH265ScalingLists {
	std::array<std::array<uint8_t, Constants::StdVideoH265ScalingList4x4NumLists>, Constants::StdVideoH265ScalingList4x4NumElements>     ScalingList4x4         = {};
	std::array<std::array<uint8_t, Constants::StdVideoH265ScalingList8x8NumLists>, Constants::StdVideoH265ScalingList8x8NumElements>     ScalingList8x8         = {};
	std::array<std::array<uint8_t, Constants::StdVideoH265ScalingList16x16NumLists>, Constants::StdVideoH265ScalingList16x16NumElements> ScalingList16x16       = {};
	std::array<std::array<uint8_t, Constants::StdVideoH265ScalingList32x32NumLists>, Constants::StdVideoH265ScalingList32x32NumElements> ScalingList32x32       = {};
	std::array<uint8_t, Constants::StdVideoH265ScalingList16x16NumLists>                                                                 ScalingListDCCoef16x16 = {};
	std::array<uint8_t, Constants::StdVideoH265ScalingList32x32NumLists>                                                                 ScalingListDCCoef32x32 = {};
};
struct StdVideoH265ShortTermRefPicSetFlags {
	uint32_t inter_ref_pic_set_prediction_flag: 1 = 0;
	uint32_t delta_rps_sign: 1                    = 0;
};
struct StdVideoH265SpsFlags {
	uint32_t sps_temporal_id_nesting_flag: 1                    = 0;
	uint32_t separate_colour_plane_flag: 1                      = 0;
	uint32_t conformance_window_flag: 1                         = 0;
	uint32_t sps_sub_layer_ordering_info_present_flag: 1        = 0;
	uint32_t scaling_list_enabled_flag: 1                       = 0;
	uint32_t sps_scaling_list_data_present_flag: 1              = 0;
	uint32_t amp_enabled_flag: 1                                = 0;
	uint32_t sample_adaptive_offset_enabled_flag: 1             = 0;
	uint32_t pcm_enabled_flag: 1                                = 0;
	uint32_t pcm_loop_filter_disabled_flag: 1                   = 0;
	uint32_t long_term_ref_pics_present_flag: 1                 = 0;
	uint32_t sps_temporal_mvp_enabled_flag: 1                   = 0;
	uint32_t strong_intra_smoothing_enabled_flag: 1             = 0;
	uint32_t vui_parameters_present_flag: 1                     = 0;
	uint32_t sps_extension_present_flag: 1                      = 0;
	uint32_t sps_range_extension_flag: 1                        = 0;
	uint32_t transform_skip_rotation_enabled_flag: 1            = 0;
	uint32_t transform_skip_context_enabled_flag: 1             = 0;
	uint32_t implicit_rdpcm_enabled_flag: 1                     = 0;
	uint32_t explicit_rdpcm_enabled_flag: 1                     = 0;
	uint32_t extended_precision_processing_flag: 1              = 0;
	uint32_t intra_smoothing_disabled_flag: 1                   = 0;
	uint32_t high_precision_offsets_enabled_flag: 1             = 0;
	uint32_t persistent_rice_adaptation_enabled_flag: 1         = 0;
	uint32_t cabac_bypass_alignment_enabled_flag: 1             = 0;
	uint32_t sps_scc_extension_flag: 1                          = 0;
	uint32_t sps_curr_pic_ref_enabled_flag: 1                   = 0;
	uint32_t palette_mode_enabled_flag: 1                       = 0;
	uint32_t sps_palette_predictor_initializers_present_flag: 1 = 0;
	uint32_t intra_boundary_filtering_disabled_flag: 1          = 0;
};
struct StdVideoH265SpsVuiFlags {
	uint32_t aspect_ratio_info_present_flag: 1          = 0;
	uint32_t overscan_info_present_flag: 1              = 0;
	uint32_t overscan_appropriate_flag: 1               = 0;
	uint32_t video_signal_type_present_flag: 1          = 0;
	uint32_t video_full_range_flag: 1                   = 0;
	uint32_t colour_description_present_flag: 1         = 0;
	uint32_t chroma_loc_info_present_flag: 1            = 0;
	uint32_t neutral_chroma_indication_flag: 1          = 0;
	uint32_t field_seq_flag: 1                          = 0;
	uint32_t frame_field_info_present_flag: 1           = 0;
	uint32_t default_display_window_flag: 1             = 0;
	uint32_t vui_timing_info_present_flag: 1            = 0;
	uint32_t vui_poc_proportional_to_timing_flag: 1     = 0;
	uint32_t vui_hrd_parameters_present_flag: 1         = 0;
	uint32_t bitstream_restriction_flag: 1              = 0;
	uint32_t tiles_fixed_structure_flag: 1              = 0;
	uint32_t motion_vectors_over_pic_boundaries_flag: 1 = 0;
	uint32_t restricted_ref_pic_lists_flag: 1           = 0;
};
struct StdVideoH265SubLayerHrdParameters {
	std::array<uint32_t, Constants::StdVideoH265CpbCntListSize> bit_rate_value_minus1    = {};
	std::array<uint32_t, Constants::StdVideoH265CpbCntListSize> cpb_size_value_minus1    = {};
	std::array<uint32_t, Constants::StdVideoH265CpbCntListSize> cpb_size_du_value_minus1 = {};
	std::array<uint32_t, Constants::StdVideoH265CpbCntListSize> bit_rate_du_value_minus1 = {};
	uint32_t                                                    cbr_flag                 = 0;
};
struct StdVideoH265VpsFlags {
	uint32_t vps_temporal_id_nesting_flag: 1             = 0;
	uint32_t vps_sub_layer_ordering_info_present_flag: 1 = 0;
	uint32_t vps_timing_info_present_flag: 1             = 0;
	uint32_t vps_poc_proportional_to_timing_flag: 1      = 0;
};
struct StdVideoVP9ColorConfigFlags {
	uint32_t color_range: 1 = 0;
	uint32_t reserved: 31   = 0;
};
struct StdVideoVP9LoopFilterFlags {
	uint32_t loop_filter_delta_enabled: 1 = 0;
	uint32_t loop_filter_delta_update: 1  = 0;
	uint32_t reserved: 30                 = 0;
};
struct StdVideoVP9SegmentationFlags {
	uint32_t segmentation_update_map: 1          = 0;
	uint32_t segmentation_temporal_update: 1     = 0;
	uint32_t segmentation_update_data: 1         = 0;
	uint32_t segmentation_abs_or_delta_update: 1 = 0;
	uint32_t reserved: 28                        = 0;
};
struct StdVideoAV1ColorConfig {
	StdVideoAV1ColorConfigFlags        flags                    = {};
	uint8_t                            BitDepth                 = 0;
	uint8_t                            subsampling_x            = 0;
	uint8_t                            subsampling_y            = 0;
	uint8_t                            reserved1                = 0;
	StdVideoAV1ColorPrimaries          color_primaries          = StdVideoAV1ColorPrimaries::Invalid;
	StdVideoAV1TransferCharacteristics transfer_characteristics = StdVideoAV1TransferCharacteristics::Reserved0;
	StdVideoAV1MatrixCoefficients      matrix_coefficients      = StdVideoAV1MatrixCoefficients::Identity;
	StdVideoAV1ChromaSamplePosition    chroma_sample_position   = StdVideoAV1ChromaSamplePosition::Unknown;
};
struct StdVideoAV1FilmGrain {
	StdVideoAV1FilmGrainFlags                                 flags                     = {};
	uint8_t                                                   grain_scaling_minus_8     = 0;
	uint8_t                                                   ar_coeff_lag              = 0;
	uint8_t                                                   ar_coeff_shift_minus_6    = 0;
	uint8_t                                                   grain_scale_shift         = 0;
	uint16_t                                                  grain_seed                = 0;
	uint8_t                                                   film_grain_params_ref_idx = 0;
	uint8_t                                                   num_y_points              = 0;
	std::array<uint8_t, Constants::StdVideoAV1MaxNumYPoints>  point_y_value             = {};
	std::array<uint8_t, Constants::StdVideoAV1MaxNumYPoints>  point_y_scaling           = {};
	uint8_t                                                   num_cb_points             = 0;
	std::array<uint8_t, Constants::StdVideoAV1MaxNumCbPoints> point_cb_value            = {};
	std::array<uint8_t, Constants::StdVideoAV1MaxNumCbPoints> point_cb_scaling          = {};
	uint8_t                                                   num_cr_points             = 0;
	std::array<uint8_t, Constants::StdVideoAV1MaxNumCrPoints> point_cr_value            = {};
	std::array<uint8_t, Constants::StdVideoAV1MaxNumCrPoints> point_cr_scaling          = {};
	std::array<int8_t, Constants::StdVideoAV1MaxNumPosLuma>   ar_coeffs_y_plus_128      = {};
	std::array<int8_t, Constants::StdVideoAV1MaxNumPosChroma> ar_coeffs_cb_plus_128     = {};
	std::array<int8_t, Constants::StdVideoAV1MaxNumPosChroma> ar_coeffs_cr_plus_128     = {};
	uint8_t                                                   cb_mult                   = 0;
	uint8_t                                                   cb_luma_mult              = 0;
	uint16_t                                                  cb_offset                 = 0;
	uint8_t                                                   cr_mult                   = 0;
	uint8_t                                                   cr_luma_mult              = 0;
	uint16_t                                                  cr_offset                 = 0;
};
struct StdVideoAV1LoopFilter {
	StdVideoAV1LoopFilterFlags                                        flags                   = {};
	std::array<uint8_t, Constants::StdVideoAV1MaxLoopFilterStrengths> loop_filter_level       = {};
	uint8_t                                                           loop_filter_sharpness   = 0;
	uint8_t                                                           update_ref_delta        = 0;
	std::array<int8_t, Constants::StdVideoAV1TotalRefsPerFrame>       loop_filter_ref_deltas  = {};
	uint8_t                                                           update_mode_delta       = 0;
	std::array<int8_t, Constants::StdVideoAV1LoopFilterAdjustments>   loop_filter_mode_deltas = {};
};
struct StdVideoAV1Quantization {
	StdVideoAV1QuantizationFlags flags      = {};
	uint8_t                      base_q_idx = 0;
	int8_t                       DeltaQYDc  = 0;
	int8_t                       DeltaQUDc  = 0;
	int8_t                       DeltaQUAc  = 0;
	int8_t                       DeltaQVDc  = 0;
	int8_t                       DeltaQVAc  = 0;
	uint8_t                      qm_y       = 0;
	uint8_t                      qm_u       = 0;
	uint8_t                      qm_v       = 0;
};
struct StdVideoAV1TileInfo {
	StdVideoAV1TileInfoFlags flags                   = {};
	uint8_t                  TileCols                = 0;
	uint8_t                  TileRows                = 0;
	uint16_t                 context_update_tile_id  = 0;
	uint8_t                  tile_size_bytes_minus_1 = 0;
	std::array<uint8_t, 7>   reserved1               = {};
	const uint16_t *         pMiColStarts            = nullptr;// len TileCols
	const uint16_t *         pMiRowStarts            = nullptr;// len TileRows
	const uint16_t *         pWidthInSbsMinus1       = nullptr;// len TileCols
	const uint16_t *         pHeightInSbsMinus1      = nullptr;// len TileRows
	auto miColStarts() -> impl_Struct::VecView<uint8_t, uint16_t>;
	auto miRowStarts() -> impl_Struct::VecView<uint8_t, uint16_t>;
};
struct StdVideoAV1TimingInfo {
	StdVideoAV1TimingInfoFlags flags                         = {};
	uint32_t                   num_units_in_display_tick     = 0;
	uint32_t                   time_scale                    = 0;
	uint32_t                   num_ticks_per_picture_minus_1 = 0;
};
struct StdVideoDecodeAV1ReferenceInfo {
	StdVideoDecodeAV1ReferenceInfoFlags                     flags            = {};
	uint8_t                                                 frame_type       = 0;
	uint8_t                                                 RefFrameSignBias = 0;
	uint8_t                                                 OrderHint        = 0;
	std::array<uint8_t, Constants::StdVideoAV1NumRefFrames> SavedOrderHints  = {};
};
struct StdVideoDecodeH264PictureInfo {
	StdVideoDecodeH264PictureInfoFlags                                        flags                = {};
	uint8_t                                                                   seq_parameter_set_id = 0;
	uint8_t                                                                   pic_parameter_set_id = 0;
	uint8_t                                                                   reserved1            = 0;
	uint8_t                                                                   reserved2            = 0;
	uint16_t                                                                  frame_num            = 0;
	uint16_t                                                                  idr_pic_id           = 0;
	std::array<int32_t, Constants::StdVideoDecodeH264FieldOrderCountListSize> PicOrderCnt          = {};
};
struct StdVideoDecodeH264ReferenceInfo {
	StdVideoDecodeH264ReferenceInfoFlags                                      flags       = {};
	uint16_t                                                                  FrameNum    = 0;
	uint16_t                                                                  reserved    = 0;
	std::array<int32_t, Constants::StdVideoDecodeH264FieldOrderCountListSize> PicOrderCnt = {};
};
struct StdVideoDecodeH265PictureInfo {
	StdVideoDecodeH265PictureInfoFlags                                  flags                        = {};
	uint8_t                                                             sps_video_parameter_set_id   = 0;
	uint8_t                                                             pps_seq_parameter_set_id     = 0;
	uint8_t                                                             pps_pic_parameter_set_id     = 0;
	uint8_t                                                             NumDeltaPocsOfRefRpsIdx      = 0;
	int32_t                                                             PicOrderCntVal               = 0;
	uint16_t                                                            NumBitsForSTRefPicSetInSlice = 0;
	uint16_t                                                            reserved                     = 0;
	std::array<uint8_t, Constants::StdVideoDecodeH265RefPicSetListSize> RefPicSetStCurrBefore        = {};
	std::array<uint8_t, Constants::StdVideoDecodeH265RefPicSetListSize> RefPicSetStCurrAfter         = {};
	std::array<uint8_t, Constants::StdVideoDecodeH265RefPicSetListSize> RefPicSetLtCurr              = {};
};
struct StdVideoDecodeH265ReferenceInfo {
	StdVideoDecodeH265ReferenceInfoFlags flags          = {};
	int32_t                              PicOrderCntVal = 0;
};
struct StdVideoEncodeAV1OperatingPointInfo {
	StdVideoEncodeAV1OperatingPointInfoFlags flags                         = {};
	uint16_t                                 operating_point_idc           = 0;
	uint8_t                                  seq_level_idx                 = 0;
	uint8_t                                  seq_tier                      = 0;
	uint32_t                                 decoder_buffer_delay          = 0;
	uint32_t                                 encoder_buffer_delay          = 0;
	uint8_t                                  initial_display_delay_minus_1 = 0;
};
struct StdVideoEncodeAV1ReferenceInfo {
	StdVideoEncodeAV1ReferenceInfoFlags     flags            = {};
	uint32_t                                RefFrameId       = 0;
	StdVideoAV1FrameType                    frame_type       = StdVideoAV1FrameType::Key;
	uint8_t                                 OrderHint        = 0;
	std::array<uint8_t, 3>                  reserved1        = {};
	const StdVideoEncodeAV1ExtensionHeader *pExtensionHeader = nullptr;
};
struct StdVideoEncodeH264ReferenceInfo {
	StdVideoEncodeH264ReferenceInfoFlags flags               = {};
	StdVideoH264PictureType              primary_pic_type    = StdVideoH264PictureType::P;
	uint32_t                             FrameNum            = 0;
	int32_t                              PicOrderCnt         = 0;
	uint16_t                             long_term_pic_num   = 0;
	uint16_t                             long_term_frame_idx = 0;
	uint8_t                              temporal_id         = 0;
};
struct StdVideoEncodeH264ReferenceListsInfo {
	StdVideoEncodeH264ReferenceListsInfoFlags                 flags                        = {};
	uint8_t                                                   num_ref_idx_l0_active_minus1 = 0;
	uint8_t                                                   num_ref_idx_l1_active_minus1 = 0;
	std::array<uint8_t, Constants::StdVideoH264MaxNumListRef> RefPicList0                  = {};
	std::array<uint8_t, Constants::StdVideoH264MaxNumListRef> RefPicList1                  = {};
	uint8_t                                                   refList0ModOpCount           = 0;
	uint8_t                                                   refList1ModOpCount           = 0;
	uint8_t                                                   refPicMarkingOpCount         = 0;
	std::array<uint8_t, 7>                                    reserved1                    = {};
	const StdVideoEncodeH264RefListModEntry *                 pRefList0ModOperations       = nullptr;// len refList0ModOpCount
	const StdVideoEncodeH264RefListModEntry *                 pRefList1ModOperations       = nullptr;// len refList1ModOpCount
	const StdVideoEncodeH264RefPicMarkingEntry *              pRefPicMarkingOperations     = nullptr;// len refPicMarkingOpCount
	auto refList0ModOperations() -> impl_Struct::VecView<uint8_t, StdVideoEncodeH264RefListModEntry>;
	auto refList1ModOperations() -> impl_Struct::VecView<uint8_t, StdVideoEncodeH264RefListModEntry>;
	auto refPicMarkingOperations() -> impl_Struct::VecView<uint8_t, StdVideoEncodeH264RefPicMarkingEntry>;
};
struct StdVideoEncodeH264WeightTable {
	StdVideoEncodeH264WeightTableFlags                                                                           flags                    = {};
	uint8_t                                                                                                      luma_log2_weight_denom   = 0;
	uint8_t                                                                                                      chroma_log2_weight_denom = 0;
	std::array<int8_t, Constants::StdVideoH264MaxNumListRef>                                                     luma_weight_l0           = {};
	std::array<int8_t, Constants::StdVideoH264MaxNumListRef>                                                     luma_offset_l0           = {};
	std::array<std::array<int8_t, Constants::StdVideoH264MaxNumListRef>, Constants::StdVideoH264MaxChromaPlanes> chroma_weight_l0         = {};
	std::array<std::array<int8_t, Constants::StdVideoH264MaxNumListRef>, Constants::StdVideoH264MaxChromaPlanes> chroma_offset_l0         = {};
	std::array<int8_t, Constants::StdVideoH264MaxNumListRef>                                                     luma_weight_l1           = {};
	std::array<int8_t, Constants::StdVideoH264MaxNumListRef>                                                     luma_offset_l1           = {};
	std::array<std::array<int8_t, Constants::StdVideoH264MaxNumListRef>, Constants::StdVideoH264MaxChromaPlanes> chroma_weight_l1         = {};
	std::array<std::array<int8_t, Constants::StdVideoH264MaxNumListRef>, Constants::StdVideoH264MaxChromaPlanes> chroma_offset_l1         = {};
};
struct StdVideoEncodeH265ReferenceInfo {
	StdVideoEncodeH265ReferenceInfoFlags flags          = {};
	StdVideoH265PictureType              pic_type       = StdVideoH265PictureType::P;
	int32_t                              PicOrderCntVal = 0;
	uint8_t                              TemporalId     = 0;
};
struct StdVideoEncodeH265ReferenceListsInfo {
	StdVideoEncodeH265ReferenceListsInfoFlags                 flags                        = {};
	uint8_t                                                   num_ref_idx_l0_active_minus1 = 0;
	uint8_t                                                   num_ref_idx_l1_active_minus1 = 0;
	std::array<uint8_t, Constants::StdVideoH265MaxNumListRef> RefPicList0                  = {};
	std::array<uint8_t, Constants::StdVideoH265MaxNumListRef> RefPicList1                  = {};
	std::array<uint8_t, Constants::StdVideoH265MaxNumListRef> list_entry_l0                = {};
	std::array<uint8_t, Constants::StdVideoH265MaxNumListRef> list_entry_l1                = {};
};
struct StdVideoEncodeH265WeightTable {
	StdVideoEncodeH265WeightTableFlags                                                                           flags                          = {};
	uint8_t                                                                                                      luma_log2_weight_denom         = 0;
	int8_t                                                                                                       delta_chroma_log2_weight_denom = 0;
	std::array<int8_t, Constants::StdVideoH265MaxNumListRef>                                                     delta_luma_weight_l0           = {};
	std::array<int8_t, Constants::StdVideoH265MaxNumListRef>                                                     luma_offset_l0                 = {};
	std::array<std::array<int8_t, Constants::StdVideoH265MaxNumListRef>, Constants::StdVideoH265MaxChromaPlanes> delta_chroma_weight_l0         = {};
	std::array<std::array<int8_t, Constants::StdVideoH265MaxNumListRef>, Constants::StdVideoH265MaxChromaPlanes> delta_chroma_offset_l0         = {};
	std::array<int8_t, Constants::StdVideoH265MaxNumListRef>                                                     delta_luma_weight_l1           = {};
	std::array<int8_t, Constants::StdVideoH265MaxNumListRef>                                                     luma_offset_l1                 = {};
	std::array<std::array<int8_t, Constants::StdVideoH265MaxNumListRef>, Constants::StdVideoH265MaxChromaPlanes> delta_chroma_weight_l1         = {};
	std::array<std::array<int8_t, Constants::StdVideoH265MaxNumListRef>, Constants::StdVideoH265MaxChromaPlanes> delta_chroma_offset_l1         = {};
};
struct StdVideoH264PictureParameterSet {
	StdVideoH264PpsFlags            flags                                = {};
	uint8_t                         seq_parameter_set_id                 = 0;
	uint8_t                         pic_parameter_set_id                 = 0;
	uint8_t                         num_ref_idx_l0_default_active_minus1 = 0;
	uint8_t                         num_ref_idx_l1_default_active_minus1 = 0;
	StdVideoH264WeightedBipredIdc   weighted_bipred_idc                  = StdVideoH264WeightedBipredIdc::Default;
	int8_t                          pic_init_qp_minus26                  = 0;
	int8_t                          pic_init_qs_minus26                  = 0;
	int8_t                          chroma_qp_index_offset               = 0;
	int8_t                          second_chroma_qp_index_offset        = 0;
	const StdVideoH264ScalingLists *pScalingLists                        = nullptr;
};
struct StdVideoH264SequenceParameterSetVui {
	StdVideoH264SpsVuiFlags          flags                               = {};
	StdVideoH264AspectRatioIdc       aspect_ratio_idc                    = StdVideoH264AspectRatioIdc::Unspecified;
	uint16_t                         sar_width                           = 0;
	uint16_t                         sar_height                          = 0;
	uint8_t                          video_format                        = 0;
	uint8_t                          colour_primaries                    = 0;
	uint8_t                          transfer_characteristics            = 0;
	uint8_t                          matrix_coefficients                 = 0;
	uint32_t                         num_units_in_tick                   = 0;
	uint32_t                         time_scale                          = 0;
	uint8_t                          max_num_reorder_frames              = 0;
	uint8_t                          max_dec_frame_buffering             = 0;
	uint8_t                          chroma_sample_loc_type_top_field    = 0;
	uint8_t                          chroma_sample_loc_type_bottom_field = 0;
	uint32_t                         reserved1                           = 0;
	const StdVideoH264HrdParameters *pHrdParameters                      = nullptr;
};
struct StdVideoH265HrdParameters {
	StdVideoH265HrdFlags                                           flags                                        = {};
	uint8_t                                                        tick_divisor_minus2                          = 0;
	uint8_t                                                        du_cpb_removal_delay_increment_length_minus1 = 0;
	uint8_t                                                        dpb_output_delay_du_length_minus1            = 0;
	uint8_t                                                        bit_rate_scale                               = 0;
	uint8_t                                                        cpb_size_scale                               = 0;
	uint8_t                                                        cpb_size_du_scale                            = 0;
	uint8_t                                                        initial_cpb_removal_delay_length_minus1      = 0;
	uint8_t                                                        au_cpb_removal_delay_length_minus1           = 0;
	uint8_t                                                        dpb_output_delay_length_minus1               = 0;
	std::array<uint8_t, Constants::StdVideoH265SublayersListSize>  cpb_cnt_minus1                               = {};
	std::array<uint16_t, Constants::StdVideoH265SublayersListSize> elemental_duration_in_tc_minus1              = {};
	std::array<uint16_t, 3>                                        reserved                                     = {};
	const StdVideoH265SubLayerHrdParameters *                      pSubLayerHrdParametersNal                    = nullptr;
	const StdVideoH265SubLayerHrdParameters *                      pSubLayerHrdParametersVcl                    = nullptr;
};
struct StdVideoH265PictureParameterSet {
	StdVideoH265PpsFlags                                                        flags                                     = {};
	uint8_t                                                                     pps_pic_parameter_set_id                  = 0;
	uint8_t                                                                     pps_seq_parameter_set_id                  = 0;
	uint8_t                                                                     sps_video_parameter_set_id                = 0;
	uint8_t                                                                     num_extra_slice_header_bits               = 0;
	uint8_t                                                                     num_ref_idx_l0_default_active_minus1      = 0;
	uint8_t                                                                     num_ref_idx_l1_default_active_minus1      = 0;
	int8_t                                                                      init_qp_minus26                           = 0;
	uint8_t                                                                     diff_cu_qp_delta_depth                    = 0;
	int8_t                                                                      pps_cb_qp_offset                          = 0;
	int8_t                                                                      pps_cr_qp_offset                          = 0;
	int8_t                                                                      pps_beta_offset_div2                      = 0;
	int8_t                                                                      pps_tc_offset_div2                        = 0;
	uint8_t                                                                     log2_parallel_merge_level_minus2          = 0;
	uint8_t                                                                     log2_max_transform_skip_block_size_minus2 = 0;
	uint8_t                                                                     diff_cu_chroma_qp_offset_depth            = 0;
	uint8_t                                                                     chroma_qp_offset_list_len_minus1          = 0;
	std::array<int8_t, Constants::StdVideoH265ChromaQpOffsetListSize>           cb_qp_offset_list                         = {};
	std::array<int8_t, Constants::StdVideoH265ChromaQpOffsetListSize>           cr_qp_offset_list                         = {};
	uint8_t                                                                     log2_sao_offset_scale_luma                = 0;
	uint8_t                                                                     log2_sao_offset_scale_chroma              = 0;
	int8_t                                                                      pps_act_y_qp_offset_plus5                 = 0;
	int8_t                                                                      pps_act_cb_qp_offset_plus5                = 0;
	int8_t                                                                      pps_act_cr_qp_offset_plus3                = 0;
	uint8_t                                                                     pps_num_palette_predictor_initializers    = 0;
	uint8_t                                                                     luma_bit_depth_entry_minus8               = 0;
	uint8_t                                                                     chroma_bit_depth_entry_minus8             = 0;
	uint8_t                                                                     num_tile_columns_minus1                   = 0;
	uint8_t                                                                     num_tile_rows_minus1                      = 0;
	uint8_t                                                                     reserved1                                 = 0;
	uint8_t                                                                     reserved2                                 = 0;
	std::array<uint16_t, Constants::StdVideoH265ChromaQpOffsetTileColsListSize> column_width_minus1                       = {};
	std::array<uint16_t, Constants::StdVideoH265ChromaQpOffsetTileRowsListSize> row_height_minus1                         = {};
	uint32_t                                                                    reserved3                                 = 0;
	const StdVideoH265ScalingLists *                                            pScalingLists                             = nullptr;
	const StdVideoH265PredictorPaletteEntries *                                 pPredictorPaletteEntries                  = nullptr;
};
struct StdVideoH265ProfileTierLevel {
	StdVideoH265ProfileTierLevelFlags flags               = {};
	StdVideoH265ProfileIdc            general_profile_idc = StdVideoH265ProfileIdc::Invalid;
	StdVideoH265LevelIdc              general_level_idc   = StdVideoH265LevelIdc::v10;
};
struct StdVideoH265ShortTermRefPicSet {
	StdVideoH265ShortTermRefPicSetFlags                     flags                    = {};
	uint32_t                                                delta_idx_minus1         = 0;
	uint16_t                                                use_delta_flag           = 0;
	uint16_t                                                abs_delta_rps_minus1     = 0;
	uint16_t                                                used_by_curr_pic_flag    = 0;
	uint16_t                                                used_by_curr_pic_s0_flag = 0;
	uint16_t                                                used_by_curr_pic_s1_flag = 0;
	uint16_t                                                reserved1                = 0;
	uint8_t                                                 reserved2                = 0;
	uint8_t                                                 reserved3                = 0;
	uint8_t                                                 num_negative_pics        = 0;
	uint8_t                                                 num_positive_pics        = 0;
	std::array<uint16_t, Constants::StdVideoH265MaxDpbSize> delta_poc_s0_minus1      = {};
	std::array<uint16_t, Constants::StdVideoH265MaxDpbSize> delta_poc_s1_minus1      = {};
};
struct StdVideoVP9ColorConfig {
	StdVideoVP9ColorConfigFlags flags         = {};
	uint8_t                     BitDepth      = 0;
	uint8_t                     subsampling_x = 0;
	uint8_t                     subsampling_y = 0;
	uint8_t                     reserved1     = 0;
	StdVideoVP9ColorSpace       color_space   = StdVideoVP9ColorSpace::StdVideoVp9ColorSpaceUnknown;
};
struct StdVideoVP9LoopFilter {
	StdVideoVP9LoopFilterFlags                                      flags                   = {};
	uint8_t                                                         loop_filter_level       = 0;
	uint8_t                                                         loop_filter_sharpness   = 0;
	uint8_t                                                         update_ref_delta        = 0;
	std::array<int8_t, Constants::StdVideoVp9MaxRefFrames>          loop_filter_ref_deltas  = {};
	uint8_t                                                         update_mode_delta       = 0;
	std::array<int8_t, Constants::StdVideoVp9LoopFilterAdjustments> loop_filter_mode_deltas = {};
};
struct StdVideoVP9Segmentation {
	StdVideoVP9SegmentationFlags                                                                        flags                   = {};
	std::array<uint8_t, Constants::StdVideoVp9MaxSegmentationTreeProbs>                                 segmentation_tree_probs = {};
	std::array<uint8_t, Constants::StdVideoVp9MaxSegmentationPredProb>                                  segmentation_pred_prob  = {};
	std::array<uint8_t, Constants::StdVideoVp9MaxSegments>                                              FeatureEnabled          = {};
	std::array<std::array<int16_t, Constants::StdVideoVp9MaxSegments>, Constants::StdVideoVp9SegLvlMax> FeatureData             = {};
};
struct StdVideoAV1SequenceHeader {
	StdVideoAV1SequenceHeaderFlags flags                              = {};
	StdVideoAV1Profile             seq_profile                        = StdVideoAV1Profile::Main;
	uint8_t                        frame_width_bits_minus_1           = 0;
	uint8_t                        frame_height_bits_minus_1          = 0;
	uint16_t                       max_frame_width_minus_1            = 0;
	uint16_t                       max_frame_height_minus_1           = 0;
	uint8_t                        delta_frame_id_length_minus_2      = 0;
	uint8_t                        additional_frame_id_length_minus_1 = 0;
	uint8_t                        order_hint_bits_minus_1            = 0;
	uint8_t                        seq_force_integer_mv               = 0;
	uint8_t                        seq_force_screen_content_tools     = 0;
	std::array<uint8_t, 5>         reserved1                          = {};
	const StdVideoAV1ColorConfig * pColorConfig                       = nullptr;
	const StdVideoAV1TimingInfo *  pTimingInfo                        = nullptr;
};
struct StdVideoDecodeAV1PictureInfo {
	StdVideoDecodeAV1PictureInfoFlags                         flags                = {};
	StdVideoAV1FrameType                                      frame_type           = StdVideoAV1FrameType::Key;
	uint32_t                                                  current_frame_id     = 0;
	uint8_t                                                   OrderHint            = 0;
	uint8_t                                                   primary_ref_frame    = 0;
	uint8_t                                                   refresh_frame_flags  = 0;
	uint8_t                                                   reserved1            = 0;
	StdVideoAV1InterpolationFilter                            interpolation_filter = StdVideoAV1InterpolationFilter::Eighttap;
	StdVideoAV1TxMode                                         TxMode               = StdVideoAV1TxMode::Only4x4;
	uint8_t                                                   delta_q_res          = 0;
	uint8_t                                                   delta_lf_res         = 0;
	std::array<uint8_t, Constants::StdVideoAV1SkipModeFrames> SkipModeFrame        = {};
	uint8_t                                                   coded_denom          = 0;
	std::array<uint8_t, 3>                                    reserved2            = {};
	std::array<uint8_t, Constants::StdVideoAV1NumRefFrames>   OrderHints           = {};
	std::array<uint32_t, Constants::StdVideoAV1NumRefFrames>  expectedFrameId      = {};
	const StdVideoAV1TileInfo *                               pTileInfo            = nullptr;
	const StdVideoAV1Quantization *                           pQuantization        = nullptr;
	const StdVideoAV1Segmentation *                           pSegmentation        = nullptr;
	const StdVideoAV1LoopFilter *                             pLoopFilter          = nullptr;
	const StdVideoAV1CDEF *                                   pCDEF                = nullptr;
	const StdVideoAV1LoopRestoration *                        pLoopRestoration     = nullptr;
	const StdVideoAV1GlobalMotion *                           pGlobalMotion        = nullptr;
	const StdVideoAV1FilmGrain *                              pFilmGrain           = nullptr;
};
struct StdVideoDecodeVP9PictureInfo {
	StdVideoDecodeVP9PictureInfoFlags flags                    = {};
	StdVideoVP9Profile                profile                  = StdVideoVP9Profile::StdVideoVp9Profile0;
	StdVideoVP9FrameType              frame_type               = StdVideoVP9FrameType::StdVideoVp9FrameTypeKey;
	uint8_t                           frame_context_idx        = 0;
	uint8_t                           reset_frame_context      = 0;
	uint8_t                           refresh_frame_flags      = 0;
	uint8_t                           ref_frame_sign_bias_mask = 0;
	StdVideoVP9InterpolationFilter    interpolation_filter     = StdVideoVP9InterpolationFilter::StdVideoVp9InterpolationFilterEighttap;
	uint8_t                           base_q_idx               = 0;
	int8_t                            delta_q_y_dc             = 0;
	int8_t                            delta_q_uv_dc            = 0;
	int8_t                            delta_q_uv_ac            = 0;
	uint8_t                           tile_cols_log2           = 0;
	uint8_t                           tile_rows_log2           = 0;
	std::array<uint16_t, 3>           reserved1                = {};
	const StdVideoVP9ColorConfig *    pColorConfig             = nullptr;
	const StdVideoVP9LoopFilter *     pLoopFilter              = nullptr;
	const StdVideoVP9Segmentation *   pSegmentation            = nullptr;
};
struct StdVideoEncodeAV1PictureInfo {
	StdVideoEncodeAV1PictureInfoFlags                        flags                   = {};
	StdVideoAV1FrameType                                     frame_type              = StdVideoAV1FrameType::Key;
	uint32_t                                                 frame_presentation_time = 0;
	uint32_t                                                 current_frame_id        = 0;
	uint8_t                                                  order_hint              = 0;
	uint8_t                                                  primary_ref_frame       = 0;
	uint8_t                                                  refresh_frame_flags     = 0;
	uint8_t                                                  coded_denom             = 0;
	uint16_t                                                 render_width_minus_1    = 0;
	uint16_t                                                 render_height_minus_1   = 0;
	StdVideoAV1InterpolationFilter                           interpolation_filter    = StdVideoAV1InterpolationFilter::Eighttap;
	StdVideoAV1TxMode                                        TxMode                  = StdVideoAV1TxMode::Only4x4;
	uint8_t                                                  delta_q_res             = 0;
	uint8_t                                                  delta_lf_res            = 0;
	std::array<uint8_t, Constants::StdVideoAV1NumRefFrames>  ref_order_hint          = {};
	std::array<int8_t, Constants::StdVideoAV1RefsPerFrame>   ref_frame_idx           = {};
	std::array<uint8_t, 3>                                   reserved1               = {};
	std::array<uint32_t, Constants::StdVideoAV1RefsPerFrame> delta_frame_id_minus_1  = {};
	const StdVideoAV1TileInfo *                              pTileInfo               = nullptr;
	const StdVideoAV1Quantization *                          pQuantization           = nullptr;
	const StdVideoAV1Segmentation *                          pSegmentation           = nullptr;
	const StdVideoAV1LoopFilter *                            pLoopFilter             = nullptr;
	const StdVideoAV1CDEF *                                  pCDEF                   = nullptr;
	const StdVideoAV1LoopRestoration *                       pLoopRestoration        = nullptr;
	const StdVideoAV1GlobalMotion *                          pGlobalMotion           = nullptr;
	const StdVideoEncodeAV1ExtensionHeader *                 pExtensionHeader        = nullptr;
	const uint32_t *                                         pBufferRemovalTimes     = nullptr;
};
struct StdVideoEncodeH264PictureInfo {
	StdVideoEncodeH264PictureInfoFlags          flags                = {};
	uint8_t                                     seq_parameter_set_id = 0;
	uint8_t                                     pic_parameter_set_id = 0;
	uint16_t                                    idr_pic_id           = 0;
	StdVideoH264PictureType                     primary_pic_type     = StdVideoH264PictureType::P;
	uint32_t                                    frame_num            = 0;
	int32_t                                     PicOrderCnt          = 0;
	uint8_t                                     temporal_id          = 0;
	std::array<uint8_t, 3>                      reserved1            = {};
	const StdVideoEncodeH264ReferenceListsInfo *pRefLists            = nullptr;
};
struct StdVideoEncodeH264SliceHeader {
	StdVideoEncodeH264SliceHeaderFlags     flags                         = {};
	uint32_t                               first_mb_in_slice             = 0;
	StdVideoH264SliceType                  slice_type                    = StdVideoH264SliceType::P;
	int8_t                                 slice_alpha_c0_offset_div2    = 0;
	int8_t                                 slice_beta_offset_div2        = 0;
	int8_t                                 slice_qp_delta                = 0;
	uint8_t                                reserved1                     = 0;
	StdVideoH264CabacInitIdc               cabac_init_idc                = StdVideoH264CabacInitIdc::v0;
	StdVideoH264DisableDeblockingFilterIdc disable_deblocking_filter_idc = StdVideoH264DisableDeblockingFilterIdc::Disabled;
	const StdVideoEncodeH264WeightTable *  pWeightTable                  = nullptr;
};
struct StdVideoEncodeH265PictureInfo {
	StdVideoEncodeH265PictureInfoFlags          flags                      = {};
	StdVideoH265PictureType                     pic_type                   = StdVideoH265PictureType::P;
	uint8_t                                     sps_video_parameter_set_id = 0;
	uint8_t                                     pps_seq_parameter_set_id   = 0;
	uint8_t                                     pps_pic_parameter_set_id   = 0;
	uint8_t                                     short_term_ref_pic_set_idx = 0;
	int32_t                                     PicOrderCntVal             = 0;
	uint8_t                                     TemporalId                 = 0;
	std::array<uint8_t, 7>                      reserved1                  = {};
	const StdVideoEncodeH265ReferenceListsInfo *pRefLists                  = nullptr;
	const StdVideoH265ShortTermRefPicSet *      pShortTermRefPicSet        = nullptr;
	const StdVideoEncodeH265LongTermRefPics *   pLongTermRefPics           = nullptr;
};
struct StdVideoEncodeH265SliceSegmentHeader {
	StdVideoEncodeH265SliceSegmentHeaderFlags flags                  = {};
	StdVideoH265SliceType                     slice_type             = StdVideoH265SliceType::B;
	uint32_t                                  slice_segment_address  = 0;
	uint8_t                                   collocated_ref_idx     = 0;
	uint8_t                                   MaxNumMergeCand        = 0;
	int8_t                                    slice_cb_qp_offset     = 0;
	int8_t                                    slice_cr_qp_offset     = 0;
	int8_t                                    slice_beta_offset_div2 = 0;
	int8_t                                    slice_tc_offset_div2   = 0;
	int8_t                                    slice_act_y_qp_offset  = 0;
	int8_t                                    slice_act_cb_qp_offset = 0;
	int8_t                                    slice_act_cr_qp_offset = 0;
	int8_t                                    slice_qp_delta         = 0;
	uint16_t                                  reserved1              = 0;
	const StdVideoEncodeH265WeightTable *     pWeightTable           = nullptr;
};
struct StdVideoH264SequenceParameterSet {
	StdVideoH264SpsFlags                       flags                                 = {};
	StdVideoH264ProfileIdc                     profile_idc                           = StdVideoH264ProfileIdc::Invalid;
	StdVideoH264LevelIdc                       level_idc                             = StdVideoH264LevelIdc::v10;
	StdVideoH264ChromaFormatIdc                chroma_format_idc                     = StdVideoH264ChromaFormatIdc::Monochrome;
	uint8_t                                    seq_parameter_set_id                  = 0;
	uint8_t                                    bit_depth_luma_minus8                 = 0;
	uint8_t                                    bit_depth_chroma_minus8               = 0;
	uint8_t                                    log2_max_frame_num_minus4             = 0;
	StdVideoH264PocType                        pic_order_cnt_type                    = StdVideoH264PocType::v0;
	int32_t                                    offset_for_non_ref_pic                = 0;
	int32_t                                    offset_for_top_to_bottom_field        = 0;
	uint8_t                                    log2_max_pic_order_cnt_lsb_minus4     = 0;
	uint8_t                                    num_ref_frames_in_pic_order_cnt_cycle = 0;
	uint8_t                                    max_num_ref_frames                    = 0;
	uint8_t                                    reserved1                             = 0;
	uint32_t                                   pic_width_in_mbs_minus1               = 0;
	uint32_t                                   pic_height_in_map_units_minus1        = 0;
	uint32_t                                   frame_crop_left_offset                = 0;
	uint32_t                                   frame_crop_right_offset               = 0;
	uint32_t                                   frame_crop_top_offset                 = 0;
	uint32_t                                   frame_crop_bottom_offset              = 0;
	uint32_t                                   reserved2                             = 0;
	const int32_t *                            pOffsetForRefFrame                    = nullptr;// len num_ref_frames_in_pic_order_cnt_cycle
	const StdVideoH264ScalingLists *           pScalingLists                         = nullptr;
	const StdVideoH264SequenceParameterSetVui *pSequenceParameterSetVui              = nullptr;
	auto offsetForRefFrame() -> impl_Struct::VecView<uint8_t, int32_t>;
};
struct StdVideoH265SequenceParameterSetVui {
	StdVideoH265SpsVuiFlags          flags                               = {};
	StdVideoH265AspectRatioIdc       aspect_ratio_idc                    = StdVideoH265AspectRatioIdc::Unspecified;
	uint16_t                         sar_width                           = 0;
	uint16_t                         sar_height                          = 0;
	uint8_t                          video_format                        = 0;
	uint8_t                          colour_primaries                    = 0;
	uint8_t                          transfer_characteristics            = 0;
	uint8_t                          matrix_coeffs                       = 0;
	uint8_t                          chroma_sample_loc_type_top_field    = 0;
	uint8_t                          chroma_sample_loc_type_bottom_field = 0;
	uint8_t                          reserved1                           = 0;
	uint8_t                          reserved2                           = 0;
	uint16_t                         def_disp_win_left_offset            = 0;
	uint16_t                         def_disp_win_right_offset           = 0;
	uint16_t                         def_disp_win_top_offset             = 0;
	uint16_t                         def_disp_win_bottom_offset          = 0;
	uint32_t                         vui_num_units_in_tick               = 0;
	uint32_t                         vui_time_scale                      = 0;
	uint32_t                         vui_num_ticks_poc_diff_one_minus1   = 0;
	uint16_t                         min_spatial_segmentation_idc        = 0;
	uint16_t                         reserved3                           = 0;
	uint8_t                          max_bytes_per_pic_denom             = 0;
	uint8_t                          max_bits_per_min_cu_denom           = 0;
	uint8_t                          log2_max_mv_length_horizontal       = 0;
	uint8_t                          log2_max_mv_length_vertical         = 0;
	const StdVideoH265HrdParameters *pHrdParameters                      = nullptr;
};
struct StdVideoH265VideoParameterSet {
	StdVideoH265VpsFlags                flags                             = {};
	uint8_t                             vps_video_parameter_set_id        = 0;
	uint8_t                             vps_max_sub_layers_minus1         = 0;
	uint8_t                             reserved1                         = 0;
	uint8_t                             reserved2                         = 0;
	uint32_t                            vps_num_units_in_tick             = 0;
	uint32_t                            vps_time_scale                    = 0;
	uint32_t                            vps_num_ticks_poc_diff_one_minus1 = 0;
	uint32_t                            reserved3                         = 0;
	const StdVideoH265DecPicBufMgr *    pDecPicBufMgr                     = nullptr;
	const StdVideoH265HrdParameters *   pHrdParameters                    = nullptr;
	const StdVideoH265ProfileTierLevel *pProfileTierLevel                 = nullptr;
};
struct StdVideoH265SequenceParameterSet {
	StdVideoH265SpsFlags                       flags                                         = {};
	StdVideoH265ChromaFormatIdc                chroma_format_idc                             = StdVideoH265ChromaFormatIdc::Monochrome;
	uint32_t                                   pic_width_in_luma_samples                     = 0;
	uint32_t                                   pic_height_in_luma_samples                    = 0;
	uint8_t                                    sps_video_parameter_set_id                    = 0;
	uint8_t                                    sps_max_sub_layers_minus1                     = 0;
	uint8_t                                    sps_seq_parameter_set_id                      = 0;
	uint8_t                                    bit_depth_luma_minus8                         = 0;
	uint8_t                                    bit_depth_chroma_minus8                       = 0;
	uint8_t                                    log2_max_pic_order_cnt_lsb_minus4             = 0;
	uint8_t                                    log2_min_luma_coding_block_size_minus3        = 0;
	uint8_t                                    log2_diff_max_min_luma_coding_block_size      = 0;
	uint8_t                                    log2_min_luma_transform_block_size_minus2     = 0;
	uint8_t                                    log2_diff_max_min_luma_transform_block_size   = 0;
	uint8_t                                    max_transform_hierarchy_depth_inter           = 0;
	uint8_t                                    max_transform_hierarchy_depth_intra           = 0;
	uint8_t                                    num_short_term_ref_pic_sets                   = 0;
	uint8_t                                    num_long_term_ref_pics_sps                    = 0;
	uint8_t                                    pcm_sample_bit_depth_luma_minus1              = 0;
	uint8_t                                    pcm_sample_bit_depth_chroma_minus1            = 0;
	uint8_t                                    log2_min_pcm_luma_coding_block_size_minus3    = 0;
	uint8_t                                    log2_diff_max_min_pcm_luma_coding_block_size  = 0;
	uint8_t                                    reserved1                                     = 0;
	uint8_t                                    reserved2                                     = 0;
	uint8_t                                    palette_max_size                              = 0;
	uint8_t                                    delta_palette_max_predictor_size              = 0;
	uint8_t                                    motion_vector_resolution_control_idc          = 0;
	uint8_t                                    sps_num_palette_predictor_initializers_minus1 = 0;
	uint32_t                                   conf_win_left_offset                          = 0;
	uint32_t                                   conf_win_right_offset                         = 0;
	uint32_t                                   conf_win_top_offset                           = 0;
	uint32_t                                   conf_win_bottom_offset                        = 0;
	const StdVideoH265ProfileTierLevel *       pProfileTierLevel                             = nullptr;
	const StdVideoH265DecPicBufMgr *           pDecPicBufMgr                                 = nullptr;
	const StdVideoH265ScalingLists *           pScalingLists                                 = nullptr;
	const StdVideoH265ShortTermRefPicSet *     pShortTermRefPicSet                           = nullptr;// len num_short_term_ref_pic_sets
	const StdVideoH265LongTermRefPicsSps *     pLongTermRefPicsSps                           = nullptr;
	const StdVideoH265SequenceParameterSetVui *pSequenceParameterSetVui                      = nullptr;
	const StdVideoH265PredictorPaletteEntries *pPredictorPaletteEntries                      = nullptr;
	auto shortTermRefPicSet() -> impl_Struct::VecView<uint8_t, StdVideoH265ShortTermRefPicSet>;
};
struct AabbPositionsKHR {
	float minX = 0.0F;
	float minY = 0.0F;
	float minZ = 0.0F;
	float maxX = 0.0F;
	float maxY = 0.0F;
	float maxZ = 0.0F;
};
struct AccelerationStructureBuildRangeInfoKHR {
	uint32_t primitiveCount  = 0;
	uint32_t primitiveOffset = 0;
	uint32_t firstVertex     = 0;
	uint32_t transformOffset = 0;
};
struct AccelerationStructureBuildSizesInfoKHR {
	StructureType sType                     = StructureType::AccelerationStructureBuildSizesInfoKHR;
	void *        pNext                     = nullptr;
	DeviceSize    accelerationStructureSize = 0;
	DeviceSize    updateScratchSize         = 0;
	DeviceSize    buildScratchSize          = 0;
};
struct AccelerationStructureCaptureDescriptorDataInfoEXT {
	StructureType                                           sType                   = StructureType::AccelerationStructureCaptureDescriptorDataInfoEXT;
	const void *                                            pNext                   = nullptr;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> accelerationStructure;
	impl_Struct::AssignableHandle<AccelerationStructureNV>  accelerationStructureNV;
};
struct AccelerationStructureCreateInfoKHR {
	StructureType                         sType         = StructureType::AccelerationStructureCreateInfoKHR;
	const void *                          pNext         = nullptr;
	AccelerationStructureCreateFlagsKHR   createFlags   = {};
	impl_Struct::AssignableHandle<Buffer> buffer;
	DeviceSize                            offset        = 0;
	DeviceSize                            size          = 0;
	AccelerationStructureTypeKHR          type          = AccelerationStructureTypeKHR::TopLevel;
	DeviceAddress                         deviceAddress = 0;
};
struct AccelerationStructureDeviceAddressInfoKHR {
	StructureType                                           sType                 = StructureType::AccelerationStructureDeviceAddressInfoKHR;
	const void *                                            pNext                 = nullptr;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> accelerationStructure;
};
struct AccelerationStructureMemoryRequirementsInfoNV {
	StructureType                                          sType                 = StructureType::AccelerationStructureMemoryRequirementsInfoNV;
	const void *                                           pNext                 = nullptr;
	AccelerationStructureMemoryRequirementsTypeNV          type                  = AccelerationStructureMemoryRequirementsTypeNV::Object;
	impl_Struct::AssignableHandle<AccelerationStructureNV> accelerationStructure;
};
struct AccelerationStructureMotionInfoNV {
	StructureType                          sType        = StructureType::AccelerationStructureMotionInfoNV;
	const void *                           pNext        = nullptr;
	uint32_t                               maxInstances = 0;
	AccelerationStructureMotionInfoFlagsNV flags        = {};
};
struct AccelerationStructureTrianglesOpacityMicromapKHR {
	StructureType                                           sType        = StructureType::AccelerationStructureTrianglesOpacityMicromapKHR;
	void *                                                  pNext        = nullptr;
	IndexType                                               indexType    = IndexType::Uint16;
	DeviceAddress                                           indexBuffer  = 0;
	DeviceSize                                              indexStride  = 0;
	uint32_t                                                baseTriangle = 0;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> micromap;
};
struct AccelerationStructureVersionInfoKHR {
	StructureType  sType        = StructureType::AccelerationStructureVersionInfoKHR;
	const void *   pNext        = nullptr;
	const uint8_t *pVersionData = nullptr;
};
struct AcquireNextImageInfoKHR {
	StructureType                               sType      = StructureType::AcquireNextImageInfoKHR;
	const void *                                pNext      = nullptr;
	impl_Struct::AssignableHandle<SwapchainKHR> swapchain;
	uint64_t                                    timeout    = 0;
	impl_Struct::AssignableHandle<Semaphore>    semaphore;
	impl_Struct::AssignableHandle<Fence>        fence;
	uint32_t                                    deviceMask = 0;
};
struct AcquireProfilingLockInfoKHR {
	StructureType                sType   = StructureType::AcquireProfilingLockInfoKHR;
	const void *                 pNext   = nullptr;
	AcquireProfilingLockFlagsKHR flags   = {};
	uint64_t                     timeout = 0;
};
struct AllocationCallbacks {
	void *                              pUserData             = nullptr;
	PFN::AllocationFunction             pfnAllocation         = nullptr;
	PFN::ReallocationFunction           pfnReallocation       = nullptr;
	PFN::FreeFunction                   pfnFree               = nullptr;
	PFN::InternalAllocationNotification pfnInternalAllocation = nullptr;
	PFN::InternalFreeNotification       pfnInternalFree       = nullptr;
};
struct AmigoProfilingSubmitInfoSEC {
	StructureType sType               = StructureType::AmigoProfilingSubmitInfoSEC;
	const void *  pNext               = nullptr;
	uint64_t      firstDrawTimestamp  = 0;
	uint64_t      swapBufferTimestamp = 0;
};
struct AntiLagPresentationInfoAMD {
	StructureType   sType      = StructureType::AntiLagPresentationInfoAMD;
	void *          pNext      = nullptr;
	AntiLagStageAMD stage      = AntiLagStageAMD::Input;
	uint64_t        frameIndex = 0;
};
struct ApplicationInfo {
	StructureType            sType              = StructureType::ApplicationInfo;
	const void *             pNext              = nullptr;
	impl_Struct::InOutString applicationName;
	uint32_t                 applicationVersion = 0;
	impl_Struct::InOutString engineName;
	uint32_t                 engineVersion      = 0;
	uint32_t                 apiVersion         = 0;
};
struct AttachmentDescription {
	AttachmentDescriptionFlags flags          = {};
	Format                     format         = Format::Undefined;
	SampleCountBits            samples        = SampleCountBits::v1;
	AttachmentLoadOp           loadOp         = AttachmentLoadOp::Load;
	AttachmentStoreOp          storeOp        = AttachmentStoreOp::Store;
	AttachmentLoadOp           stencilLoadOp  = AttachmentLoadOp::Load;
	AttachmentStoreOp          stencilStoreOp = AttachmentStoreOp::Store;
	ImageLayout                initialLayout  = ImageLayout::Undefined;
	ImageLayout                finalLayout    = ImageLayout::Undefined;
};
struct AttachmentDescription2 {
	StructureType              sType          = StructureType::AttachmentDescription2;
	const void *               pNext          = nullptr;
	AttachmentDescriptionFlags flags          = {};
	Format                     format         = Format::Undefined;
	SampleCountBits            samples        = SampleCountBits::v1;
	AttachmentLoadOp           loadOp         = AttachmentLoadOp::Load;
	AttachmentStoreOp          storeOp        = AttachmentStoreOp::Store;
	AttachmentLoadOp           stencilLoadOp  = AttachmentLoadOp::Load;
	AttachmentStoreOp          stencilStoreOp = AttachmentStoreOp::Store;
	ImageLayout                initialLayout  = ImageLayout::Undefined;
	ImageLayout                finalLayout    = ImageLayout::Undefined;
};
struct AttachmentDescriptionStencilLayout {
	StructureType sType                = StructureType::AttachmentDescriptionStencilLayout;
	void *        pNext                = nullptr;
	ImageLayout   stencilInitialLayout = ImageLayout::Undefined;
	ImageLayout   stencilFinalLayout   = ImageLayout::Undefined;
};
struct AttachmentFeedbackLoopInfoEXT {
	StructureType sType              = StructureType::AttachmentFeedbackLoopInfoEXT;
	const void *  pNext              = nullptr;
	Bool32        feedbackLoopEnable = Constants::False;
};
struct AttachmentReference {
	uint32_t    attachment = 0;
	ImageLayout layout     = ImageLayout::Undefined;
};
struct AttachmentReference2 {
	StructureType    sType      = StructureType::AttachmentReference2;
	const void *     pNext      = nullptr;
	uint32_t         attachment = 0;
	ImageLayout      layout     = ImageLayout::Undefined;
	ImageAspectFlags aspectMask = {};
};
struct AttachmentReferenceStencilLayout {
	StructureType sType         = StructureType::AttachmentReferenceStencilLayout;
	void *        pNext         = nullptr;
	ImageLayout   stencilLayout = ImageLayout::Undefined;
};
struct AttachmentSampleCountInfoAMD {
	StructureType          sType                         = StructureType::AttachmentSampleCountInfoAMD;
	const void *           pNext                         = nullptr;
	uint32_t               colorAttachmentCount          = 0;
	const SampleCountBits *pColorAttachmentSamples       = nullptr;// len colorAttachmentCount
	SampleCountBits        depthStencilAttachmentSamples = SampleCountBits::v1;
	auto colorAttachmentSamples() -> impl_Struct::VecView<uint32_t, SampleCountBits>;
};
struct BaseInStructure {
	StructureType                 sType = static_cast<StructureType>(0);
	const struct BaseInStructure *pNext = nullptr;
};
struct BaseOutStructure {
	StructureType            sType = static_cast<StructureType>(0);
	struct BaseOutStructure *pNext = nullptr;
};
struct BeginCustomResolveInfoEXT {
	StructureType sType = StructureType::BeginCustomResolveInfoEXT;
	void *        pNext = nullptr;
};
struct BindAccelerationStructureMemoryInfoNV {
	StructureType                                          sType                 = StructureType::BindAccelerationStructureMemoryInfoNV;
	const void *                                           pNext                 = nullptr;
	impl_Struct::AssignableHandle<AccelerationStructureNV> accelerationStructure;
	impl_Struct::AssignableHandle<DeviceMemory>            memory;
	DeviceSize                                             memoryOffset          = 0;
	uint32_t                                               deviceIndexCount      = 0;
	const uint32_t *                                       pDeviceIndices        = nullptr;// len deviceIndexCount
	auto deviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct BindBufferMemoryDeviceGroupInfo {
	StructureType   sType            = StructureType::BindBufferMemoryDeviceGroupInfo;
	const void *    pNext            = nullptr;
	uint32_t        deviceIndexCount = 0;
	const uint32_t *pDeviceIndices   = nullptr;// len deviceIndexCount
	auto deviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct BindBufferMemoryInfo {
	StructureType                               sType        = StructureType::BindBufferMemoryInfo;
	const void *                                pNext        = nullptr;
	impl_Struct::AssignableHandle<Buffer>       buffer;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  memoryOffset = 0;
};
struct BindDataGraphPipelineSessionMemoryInfoARM {
	StructureType                                              sType        = StructureType::BindDataGraphPipelineSessionMemoryInfoARM;
	const void *                                               pNext        = nullptr;
	impl_Struct::AssignableHandle<DataGraphPipelineSessionARM> session;
	DataGraphPipelineSessionBindPointARM                       bindPoint    = DataGraphPipelineSessionBindPointARM::Transient;
	uint32_t                                                   objectIndex  = 0;
	impl_Struct::AssignableHandle<DeviceMemory>                memory;
	DeviceSize                                                 memoryOffset = 0;
};
struct BindDescriptorBufferEmbeddedSamplersInfoEXT {
	StructureType                                 sType      = StructureType::BindDescriptorBufferEmbeddedSamplersInfoEXT;
	const void *                                  pNext      = nullptr;
	ShaderStageFlags                              stageFlags = {};
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	uint32_t                                      set        = 0;
};
struct BindDescriptorSetsInfo {
	StructureType                                       sType              = StructureType::BindDescriptorSetsInfo;
	const void *                                        pNext              = nullptr;
	ShaderStageFlags                                    stageFlags         = {};
	impl_Struct::AssignableHandle<PipelineLayout>       layout;
	uint32_t                                            firstSet           = 0;
	uint32_t                                            descriptorSetCount = 0;
	const impl_Struct::AssignableHandle<DescriptorSet> *pDescriptorSets    = nullptr;// len descriptorSetCount
	uint32_t                                            dynamicOffsetCount = 0;
	const uint32_t *                                    pDynamicOffsets    = nullptr;// len dynamicOffsetCount
	auto descriptorSets() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSet>>;
	auto dynamicOffsets() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct BindImageMemoryInfo {
	StructureType                               sType        = StructureType::BindImageMemoryInfo;
	const void *                                pNext        = nullptr;
	impl_Struct::AssignableHandle<Image>        image;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  memoryOffset = 0;
};
struct BindImageMemorySwapchainInfoKHR {
	StructureType                               sType      = StructureType::BindImageMemorySwapchainInfoKHR;
	const void *                                pNext      = nullptr;
	impl_Struct::AssignableHandle<SwapchainKHR> swapchain;
	uint32_t                                    imageIndex = 0;
};
struct BindImagePlaneMemoryInfo {
	StructureType   sType       = StructureType::BindImagePlaneMemoryInfo;
	const void *    pNext       = nullptr;
	ImageAspectBits planeAspect = ImageAspectBits::None;
};
struct BindIndexBufferIndirectCommandEXT {
	DeviceAddress bufferAddress = 0;
	uint32_t      size          = 0;
	IndexType     indexType     = IndexType::Uint16;
};
struct BindIndexBufferIndirectCommandNV {
	DeviceAddress bufferAddress = 0;
	uint32_t      size          = 0;
	IndexType     indexType     = IndexType::Uint16;
};
struct BindMemoryStatus {
	StructureType sType   = StructureType::BindMemoryStatus;
	const void *  pNext   = nullptr;
	Result *      pResult = nullptr;
};
struct BindPipelineIndirectCommandNV {
	DeviceAddress pipelineAddress = 0;
};
struct BindShaderGroupIndirectCommandNV {
	uint32_t groupIndex = 0;
};
struct BindTensorMemoryInfoARM {
	StructureType                               sType        = StructureType::BindTensorMemoryInfoARM;
	const void *                                pNext        = nullptr;
	impl_Struct::AssignableHandle<TensorARM>    tensor;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  memoryOffset = 0;
};
struct BindVertexBufferIndirectCommandEXT {
	DeviceAddress bufferAddress = 0;
	uint32_t      size          = 0;
	uint32_t      stride        = 0;
};
struct BindVertexBufferIndirectCommandNV {
	DeviceAddress bufferAddress = 0;
	uint32_t      size          = 0;
	uint32_t      stride        = 0;
};
struct BindVideoSessionMemoryInfoKHR {
	StructureType                               sType           = StructureType::BindVideoSessionMemoryInfoKHR;
	const void *                                pNext           = nullptr;
	uint32_t                                    memoryBindIndex = 0;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  memoryOffset    = 0;
	DeviceSize                                  memorySize      = 0;
};
struct BlitImageCubicWeightsInfoQCOM {
	StructureType          sType        = StructureType::BlitImageCubicWeightsInfoQCOM;
	const void *           pNext        = nullptr;
	CubicFilterWeightsQCOM cubicWeights = CubicFilterWeightsQCOM::CatmullRom;
};
struct BufferCaptureDescriptorDataInfoEXT {
	StructureType                         sType  = StructureType::BufferCaptureDescriptorDataInfoEXT;
	const void *                          pNext  = nullptr;
	impl_Struct::AssignableHandle<Buffer> buffer;
};
struct BufferCopy {
	DeviceSize srcOffset = 0;
	DeviceSize dstOffset = 0;
	DeviceSize size      = 0;
};
struct BufferCopy2 {
	StructureType sType     = StructureType::BufferCopy2;
	const void *  pNext     = nullptr;
	DeviceSize    srcOffset = 0;
	DeviceSize    dstOffset = 0;
	DeviceSize    size      = 0;
};
struct BufferCreateInfo {
	StructureType     sType                 = StructureType::BufferCreateInfo;
	const void *      pNext                 = nullptr;
	BufferCreateFlags flags                 = {};
	DeviceSize        size                  = 0;
	BufferUsageFlags  usage                 = {};
	SharingMode       sharingMode           = SharingMode::Exclusive;
	uint32_t          queueFamilyIndexCount = 0;
	const uint32_t *  pQueueFamilyIndices   = nullptr;// len queueFamilyIndexCount
	auto queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct BufferDeviceAddressCreateInfoEXT {
	StructureType sType         = StructureType::BufferDeviceAddressCreateInfoEXT;
	const void *  pNext         = nullptr;
	DeviceAddress deviceAddress = 0;
};
struct BufferDeviceAddressInfo {
	StructureType                         sType  = StructureType::BufferDeviceAddressInfo;
	const void *                          pNext  = nullptr;
	impl_Struct::AssignableHandle<Buffer> buffer;
};
struct BufferMemoryBarrier {
	StructureType                         sType               = StructureType::BufferMemoryBarrier;
	const void *                          pNext               = nullptr;
	AccessFlags                           srcAccessMask       = {};
	AccessFlags                           dstAccessMask       = {};
	uint32_t                              srcQueueFamilyIndex = 0;
	uint32_t                              dstQueueFamilyIndex = 0;
	impl_Struct::AssignableHandle<Buffer> buffer;
	DeviceSize                            offset              = 0;
	DeviceSize                            size                = 0;
};
struct BufferMemoryBarrier2 {
	StructureType                         sType               = StructureType::BufferMemoryBarrier2;
	const void *                          pNext               = nullptr;
	PipelineStageFlags2                   srcStageMask        = {};
	AccessFlags2                          srcAccessMask       = {};
	PipelineStageFlags2                   dstStageMask        = {};
	AccessFlags2                          dstAccessMask       = {};
	uint32_t                              srcQueueFamilyIndex = 0;
	uint32_t                              dstQueueFamilyIndex = 0;
	impl_Struct::AssignableHandle<Buffer> buffer;
	DeviceSize                            offset              = 0;
	DeviceSize                            size                = 0;
};
struct BufferMemoryRequirementsInfo2 {
	StructureType                         sType  = StructureType::BufferMemoryRequirementsInfo2;
	const void *                          pNext  = nullptr;
	impl_Struct::AssignableHandle<Buffer> buffer;
};
struct BufferOpaqueCaptureAddressCreateInfo {
	StructureType sType                = StructureType::BufferOpaqueCaptureAddressCreateInfo;
	const void *  pNext                = nullptr;
	uint64_t      opaqueCaptureAddress = 0;
};
struct BufferUsageFlags2CreateInfo {
	StructureType     sType = StructureType::BufferUsageFlags2CreateInfo;
	const void *      pNext = nullptr;
	BufferUsageFlags2 usage = {};
};
struct BufferViewCreateInfo {
	StructureType                         sType  = StructureType::BufferViewCreateInfo;
	const void *                          pNext  = nullptr;
	BufferViewCreateFlags                 flags  = {};
	impl_Struct::AssignableHandle<Buffer> buffer;
	Format                                format = Format::Undefined;
	DeviceSize                            offset = 0;
	DeviceSize                            range  = 0;
};
struct CalibratedTimestampInfoKHR {
	StructureType sType      = StructureType::CalibratedTimestampInfoKHR;
	const void *  pNext      = nullptr;
	TimeDomainKHR timeDomain = TimeDomainKHR::Device;
};
struct CheckpointData2NV {
	StructureType       sType             = StructureType::CheckpointData2NV;
	void *              pNext             = nullptr;
	PipelineStageFlags2 stage             = {};
	void *              pCheckpointMarker = nullptr;
};
struct CheckpointDataNV {
	StructureType     sType             = StructureType::CheckpointDataNV;
	void *            pNext             = nullptr;
	PipelineStageBits stage             = PipelineStageBits::None;
	void *            pCheckpointMarker = nullptr;
};
union ClearColorValue {
	std::array<float, 4>    float32;
	std::array<int32_t, 4>  int32;
	std::array<uint32_t, 4> uint32;
};
struct ClearDepthStencilValue {
	float    depth   = 0.0F;
	uint32_t stencil = 0;
};
struct ClusterAccelerationStructureBuildClustersBottomLevelInfoNV {
	uint32_t      clusterReferencesCount  = 0;
	uint32_t      clusterReferencesStride = 0;
	DeviceAddress clusterReferences       = 0;
};
struct ClusterAccelerationStructureClustersBottomLevelInputNV {
	StructureType sType                                   = StructureType::ClusterAccelerationStructureClustersBottomLevelInputNV;
	void *        pNext                                   = nullptr;
	uint32_t      maxTotalClusterCount                    = 0;
	uint32_t      maxClusterCountPerAccelerationStructure = 0;
};
struct ClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV {
	uint32_t geometryIndex:24 = 0;
	uint32_t reserved:5       = 0;
	uint32_t geometryFlags:3  = 0;
};
struct ClusterAccelerationStructureGetTemplateIndicesInfoNV {
	DeviceAddress clusterTemplateAddress = 0;
};
struct ClusterAccelerationStructureMoveObjectsInfoNV {
	DeviceAddress srcAccelerationStructure = 0;
};
struct ClusterAccelerationStructureMoveObjectsInputNV {
	StructureType                      sType         = StructureType::ClusterAccelerationStructureMoveObjectsInputNV;
	void *                             pNext         = nullptr;
	ClusterAccelerationStructureTypeNV type          = ClusterAccelerationStructureTypeNV::ClustersBottomLevel;
	Bool32                             noMoveOverlap = Constants::False;
	DeviceSize                         maxMovedBytes = 0;
};
struct ClusterAccelerationStructureTriangleClusterInputNV {
	StructureType sType                         = StructureType::ClusterAccelerationStructureTriangleClusterInputNV;
	void *        pNext                         = nullptr;
	Format        vertexFormat                  = Format::Undefined;
	uint32_t      maxGeometryIndexValue         = 0;
	uint32_t      maxClusterUniqueGeometryCount = 0;
	uint32_t      maxClusterTriangleCount       = 0;
	uint32_t      maxClusterVertexCount         = 0;
	uint32_t      maxTotalTriangleCount         = 0;
	uint32_t      maxTotalVertexCount           = 0;
	uint32_t      minPositionTruncateBitCount   = 0;
};
struct CoarseSampleLocationNV {
	uint32_t pixelX = 0;
	uint32_t pixelY = 0;
	uint32_t sample = 0;
};
struct ColorBlendAdvancedEXT {
	BlendOp         advancedBlendOp  = BlendOp::Add;
	Bool32          srcPremultiplied = Constants::False;
	Bool32          dstPremultiplied = Constants::False;
	BlendOverlapEXT blendOverlap     = BlendOverlapEXT::Uncorrelated;
	Bool32          clampResults     = Constants::False;
};
struct ColorBlendEquationEXT {
	BlendFactor srcColorBlendFactor = BlendFactor::Zero;
	BlendFactor dstColorBlendFactor = BlendFactor::Zero;
	BlendOp     colorBlendOp        = BlendOp::Add;
	BlendFactor srcAlphaBlendFactor = BlendFactor::Zero;
	BlendFactor dstAlphaBlendFactor = BlendFactor::Zero;
	BlendOp     alphaBlendOp        = BlendOp::Add;
};
struct CommandBufferAllocateInfo {
	StructureType                              sType              = StructureType::CommandBufferAllocateInfo;
	const void *                               pNext              = nullptr;
	impl_Struct::AssignableHandle<CommandPool> commandPool;
	CommandBufferLevel                         level              = CommandBufferLevel::Primary;
	uint32_t                                   commandBufferCount = 0;
};
struct CommandBufferInheritanceConditionalRenderingInfoEXT {
	StructureType sType                      = StructureType::CommandBufferInheritanceConditionalRenderingInfoEXT;
	const void *  pNext                      = nullptr;
	Bool32        conditionalRenderingEnable = Constants::False;
};
struct CommandBufferInheritanceInfo {
	StructureType                              sType                = StructureType::CommandBufferInheritanceInfo;
	const void *                               pNext                = nullptr;
	impl_Struct::AssignableHandle<RenderPass>  renderPass;
	uint32_t                                   subpass              = 0;
	impl_Struct::AssignableHandle<Framebuffer> framebuffer;
	Bool32                                     occlusionQueryEnable = Constants::False;
	QueryControlFlags                          queryFlags           = {};
	QueryPipelineStatisticFlags                pipelineStatistics   = {};
};
struct CommandBufferInheritanceRenderingInfo {
	StructureType   sType                   = StructureType::CommandBufferInheritanceRenderingInfo;
	const void *    pNext                   = nullptr;
	RenderingFlags  flags                   = {};
	uint32_t        viewMask                = 0;
	uint32_t        colorAttachmentCount    = 0;
	const Format *  pColorAttachmentFormats = nullptr;// len colorAttachmentCount
	Format          depthAttachmentFormat   = Format::Undefined;
	Format          stencilAttachmentFormat = Format::Undefined;
	SampleCountBits rasterizationSamples    = SampleCountBits::v1;
	auto colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format>;
};
struct CommandBufferSubmitInfo {
	StructureType                                sType         = StructureType::CommandBufferSubmitInfo;
	const void *                                 pNext         = nullptr;
	impl_Struct::AssignableHandle<CommandBuffer> commandBuffer;
	uint32_t                                     deviceMask    = 0;
};
struct CommandPoolCreateInfo {
	StructureType          sType            = StructureType::CommandPoolCreateInfo;
	const void *           pNext            = nullptr;
	CommandPoolCreateFlags flags            = {};
	uint32_t               queueFamilyIndex = 0;
};
struct ComponentMapping {
	ComponentSwizzle r = ComponentSwizzle::Identity;
	ComponentSwizzle g = ComponentSwizzle::Identity;
	ComponentSwizzle b = ComponentSwizzle::Identity;
	ComponentSwizzle a = ComponentSwizzle::Identity;
};
struct ComputeOccupancyPriorityParametersNV {
	StructureType sType               = StructureType::ComputeOccupancyPriorityParametersNV;
	const void *  pNext               = nullptr;
	float         occupancyPriority   = 0.0F;
	float         occupancyThrottling = 0.0F;
};
struct ComputePipelineIndirectBufferInfoNV {
	StructureType sType                              = StructureType::ComputePipelineIndirectBufferInfoNV;
	const void *  pNext                              = nullptr;
	DeviceAddress deviceAddress                      = 0;
	DeviceSize    size                               = 0;
	DeviceAddress pipelineDeviceAddressCaptureReplay = 0;
};
struct ConditionalRenderingBeginInfoEXT {
	StructureType                         sType  = StructureType::ConditionalRenderingBeginInfoEXT;
	const void *                          pNext  = nullptr;
	impl_Struct::AssignableHandle<Buffer> buffer;
	DeviceSize                            offset = 0;
	ConditionalRenderingFlagsEXT          flags  = {};
};
struct ConformanceVersion {
	uint8_t major    = 0;
	uint8_t minor    = 0;
	uint8_t subminor = 0;
	uint8_t patch    = 0;
};
struct CooperativeMatrixFlexibleDimensionsPropertiesNV {
	StructureType    sType                  = StructureType::CooperativeMatrixFlexibleDimensionsPropertiesNV;
	void *           pNext                  = nullptr;
	uint32_t         MGranularity           = 0;
	uint32_t         NGranularity           = 0;
	uint32_t         KGranularity           = 0;
	ComponentTypeKHR AType                  = ComponentTypeKHR::Float16;
	ComponentTypeKHR BType                  = ComponentTypeKHR::Float16;
	ComponentTypeKHR CType                  = ComponentTypeKHR::Float16;
	ComponentTypeKHR ResultType             = ComponentTypeKHR::Float16;
	Bool32           saturatingAccumulation = Constants::False;
	ScopeKHR         scope                  = ScopeKHR::Device;
	uint32_t         workgroupInvocations   = 0;
};
struct CooperativeMatrixProperties2EXT {
	StructureType    sType        = StructureType::CooperativeMatrixProperties2EXT;
	void *           pNext        = nullptr;
	uint32_t         MGranularity = 0;
	uint32_t         NGranularity = 0;
	uint32_t         KGranularity = 0;
	ComponentTypeKHR AType        = ComponentTypeKHR::Float16;
	ComponentTypeKHR BType        = ComponentTypeKHR::Float16;
	ComponentTypeKHR CType        = ComponentTypeKHR::Float16;
	ComponentTypeKHR ResultType   = ComponentTypeKHR::Float16;
};
struct CooperativeMatrixPropertiesKHR {
	StructureType    sType                  = StructureType::CooperativeMatrixPropertiesKHR;
	void *           pNext                  = nullptr;
	uint32_t         MSize                  = 0;
	uint32_t         NSize                  = 0;
	uint32_t         KSize                  = 0;
	ComponentTypeKHR AType                  = ComponentTypeKHR::Float16;
	ComponentTypeKHR BType                  = ComponentTypeKHR::Float16;
	ComponentTypeKHR CType                  = ComponentTypeKHR::Float16;
	ComponentTypeKHR ResultType             = ComponentTypeKHR::Float16;
	Bool32           saturatingAccumulation = Constants::False;
	ScopeKHR         scope                  = ScopeKHR::Device;
};
struct CooperativeMatrixPropertiesNV {
	StructureType    sType = StructureType::CooperativeMatrixPropertiesNV;
	void *           pNext = nullptr;
	uint32_t         MSize = 0;
	uint32_t         NSize = 0;
	uint32_t         KSize = 0;
	ComponentTypeKHR AType = ComponentTypeKHR::Float16;
	ComponentTypeKHR BType = ComponentTypeKHR::Float16;
	ComponentTypeKHR CType = ComponentTypeKHR::Float16;
	ComponentTypeKHR DType = ComponentTypeKHR::Float16;
	ScopeKHR         scope = ScopeKHR::Device;
};
struct CooperativeVectorPropertiesNV {
	StructureType    sType                = StructureType::CooperativeVectorPropertiesNV;
	void *           pNext                = nullptr;
	ComponentTypeKHR inputType            = ComponentTypeKHR::Float16;
	ComponentTypeKHR inputInterpretation  = ComponentTypeKHR::Float16;
	ComponentTypeKHR matrixInterpretation = ComponentTypeKHR::Float16;
	ComponentTypeKHR biasInterpretation   = ComponentTypeKHR::Float16;
	ComponentTypeKHR resultType           = ComponentTypeKHR::Float16;
	Bool32           transpose            = Constants::False;
};
struct CopyAccelerationStructureInfoKHR {
	StructureType                                           sType = StructureType::CopyAccelerationStructureInfoKHR;
	const void *                                            pNext = nullptr;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> src;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> dst;
	CopyAccelerationStructureModeKHR                        mode  = CopyAccelerationStructureModeKHR::Clone;
};
struct CopyCommandTransformInfoQCOM {
	StructureType           sType     = StructureType::CopyCommandTransformInfoQCOM;
	const void *            pNext     = nullptr;
	SurfaceTransformBitsKHR transform = SurfaceTransformBitsKHR::Identity;
};
struct CopyDescriptorSet {
	StructureType                                sType           = StructureType::CopyDescriptorSet;
	const void *                                 pNext           = nullptr;
	impl_Struct::AssignableHandle<DescriptorSet> srcSet;
	uint32_t                                     srcBinding      = 0;
	uint32_t                                     srcArrayElement = 0;
	impl_Struct::AssignableHandle<DescriptorSet> dstSet;
	uint32_t                                     dstBinding      = 0;
	uint32_t                                     dstArrayElement = 0;
	uint32_t                                     descriptorCount = 0;
};
struct CopyMemoryIndirectCommandKHR {
	DeviceAddress srcAddress = 0;
	DeviceAddress dstAddress = 0;
	DeviceSize    size       = 0;
};
struct CopyMicromapInfoEXT {
	StructureType                              sType = StructureType::CopyMicromapInfoEXT;
	const void *                               pNext = nullptr;
	impl_Struct::AssignableHandle<MicromapEXT> src;
	impl_Struct::AssignableHandle<MicromapEXT> dst;
	CopyMicromapModeEXT                        mode  = CopyMicromapModeEXT::Clone;
};
struct CuFunctionCreateInfoNVX {
	StructureType                              sType  = StructureType::CuFunctionCreateInfoNVX;
	const void *                               pNext  = nullptr;
	impl_Struct::AssignableHandle<CuModuleNVX> module;
	impl_Struct::InOutString                   name;
};
struct CuLaunchInfoNVX {
	StructureType                                sType          = StructureType::CuLaunchInfoNVX;
	const void *                                 pNext          = nullptr;
	impl_Struct::AssignableHandle<CuFunctionNVX> function;
	uint32_t                                     gridDimX       = 0;
	uint32_t                                     gridDimY       = 0;
	uint32_t                                     gridDimZ       = 0;
	uint32_t                                     blockDimX      = 0;
	uint32_t                                     blockDimY      = 0;
	uint32_t                                     blockDimZ      = 0;
	uint32_t                                     sharedMemBytes = 0;
	size_t                                       paramCount     = 0;
	const void * const *                         pParams        = nullptr;// len paramCount
	size_t                                       extraCount     = 0;
	const void * const *                         pExtras        = nullptr;// len extraCount
};
struct CuModuleCreateInfoNVX {
	StructureType sType    = StructureType::CuModuleCreateInfoNVX;
	const void *  pNext    = nullptr;
	size_t        dataSize = 0;
	const void *  pData    = nullptr;// len dataSize
};
struct CuModuleTexturingModeCreateInfoNVX {
	StructureType sType             = StructureType::CuModuleTexturingModeCreateInfoNVX;
	const void *  pNext             = nullptr;
	Bool32        use64bitTexturing = Constants::False;
};
struct CustomResolveCreateInfoEXT {
	StructureType sType                   = StructureType::CustomResolveCreateInfoEXT;
	const void *  pNext                   = nullptr;
	Bool32        customResolve           = Constants::False;
	uint32_t      colorAttachmentCount    = 0;
	const Format *pColorAttachmentFormats = nullptr;// len colorAttachmentCount
	Format        depthAttachmentFormat   = Format::Undefined;
	Format        stencilAttachmentFormat = Format::Undefined;
	auto colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format>;
};
struct DataGraphOpticalFlowImageFormatInfoARM {
	StructureType                          sType = StructureType::DataGraphOpticalFlowImageFormatInfoARM;
	const void *                           pNext = nullptr;
	DataGraphOpticalFlowImageUsageFlagsARM usage = {};
};
struct DataGraphOpticalFlowImageFormatPropertiesARM {
	StructureType sType  = StructureType::DataGraphOpticalFlowImageFormatPropertiesARM;
	void *        pNext  = nullptr;
	Format        format = Format::Undefined;
};
struct DataGraphPipelineCompilerControlCreateInfoARM {
	StructureType            sType         = StructureType::DataGraphPipelineCompilerControlCreateInfoARM;
	const void *             pNext         = nullptr;
	impl_Struct::InOutString vendorOptions;
};
struct DataGraphPipelineConstantARM {
	StructureType sType         = StructureType::DataGraphPipelineConstantARM;
	const void *  pNext         = nullptr;
	uint32_t      id            = 0;
	const void *  pConstantData = nullptr;
};
struct DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM {
	StructureType sType     = StructureType::DataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM;
	const void *  pNext     = nullptr;
	uint32_t      dimension = 0;
	uint32_t      zeroCount = 0;
	uint32_t      groupSize = 0;
};
struct DataGraphPipelineDispatchInfoARM {
	StructureType                     sType = StructureType::DataGraphPipelineDispatchInfoARM;
	void *                            pNext = nullptr;
	DataGraphPipelineDispatchFlagsARM flags = {};
};
struct DataGraphPipelineIdentifierCreateInfoARM {
	StructureType  sType          = StructureType::DataGraphPipelineIdentifierCreateInfoARM;
	const void *   pNext          = nullptr;
	uint32_t       identifierSize = 0;
	const uint8_t *pIdentifier    = nullptr;// len identifierSize
	auto identifier() -> impl_Struct::VecView<uint32_t, uint8_t>;
};
struct DataGraphPipelineInfoARM {
	StructureType                           sType             = StructureType::DataGraphPipelineInfoARM;
	const void *                            pNext             = nullptr;
	impl_Struct::AssignableHandle<Pipeline> dataGraphPipeline;
};
struct DataGraphPipelineNeuralStatisticsCreateInfoARM {
	StructureType sType                 = StructureType::DataGraphPipelineNeuralStatisticsCreateInfoARM;
	const void *  pNext                 = nullptr;
	Bool32        allowNeuralStatistics = Constants::False;
};
struct DataGraphPipelineOpticalFlowCreateInfoARM {
	StructureType                           sType            = StructureType::DataGraphPipelineOpticalFlowCreateInfoARM;
	void *                                  pNext            = nullptr;
	uint32_t                                width            = 0;
	uint32_t                                height           = 0;
	Format                                  imageFormat      = Format::Undefined;
	Format                                  flowVectorFormat = Format::Undefined;
	Format                                  costFormat       = Format::Undefined;
	DataGraphOpticalFlowGridSizeFlagsARM    outputGridSize   = {};
	DataGraphOpticalFlowGridSizeFlagsARM    hintGridSize     = {};
	DataGraphOpticalFlowPerformanceLevelARM performanceLevel = DataGraphOpticalFlowPerformanceLevelARM::Unknown;
	DataGraphOpticalFlowCreateFlagsARM      flags            = {};
};
struct DataGraphPipelineOpticalFlowDispatchInfoARM {
	StructureType                       sType              = StructureType::DataGraphPipelineOpticalFlowDispatchInfoARM;
	void *                              pNext              = nullptr;
	DataGraphOpticalFlowExecuteFlagsARM flags              = {};
	uint32_t                            meanFlowL1NormHint = 0;
};
struct DataGraphPipelinePropertyQueryResultARM {
	StructureType                sType    = StructureType::DataGraphPipelinePropertyQueryResultARM;
	void *                       pNext    = nullptr;
	DataGraphPipelinePropertyARM property = DataGraphPipelinePropertyARM::CreationLog;
	Bool32                       isText   = Constants::False;
	size_t                       dataSize = 0;
	void *                       pData    = nullptr;// len dataSize
};
struct DataGraphPipelineResourceInfoARM {
	StructureType sType         = StructureType::DataGraphPipelineResourceInfoARM;
	const void *  pNext         = nullptr;
	uint32_t      descriptorSet = 0;
	uint32_t      binding       = 0;
	uint32_t      arrayElement  = 0;
};
struct DataGraphPipelineResourceInfoImageLayoutARM {
	StructureType sType  = StructureType::DataGraphPipelineResourceInfoImageLayoutARM;
	const void *  pNext  = nullptr;
	ImageLayout   layout = ImageLayout::Undefined;
};
struct DataGraphPipelineSessionBindPointRequirementARM {
	StructureType                            sType         = StructureType::DataGraphPipelineSessionBindPointRequirementARM;
	void *                                   pNext         = nullptr;
	DataGraphPipelineSessionBindPointARM     bindPoint     = DataGraphPipelineSessionBindPointARM::Transient;
	DataGraphPipelineSessionBindPointTypeARM bindPointType = DataGraphPipelineSessionBindPointTypeARM::Memory;
	uint32_t                                 numObjects    = 0;
};
struct DataGraphPipelineSessionBindPointRequirementsInfoARM {
	StructureType                                              sType   = StructureType::DataGraphPipelineSessionBindPointRequirementsInfoARM;
	const void *                                               pNext   = nullptr;
	impl_Struct::AssignableHandle<DataGraphPipelineSessionARM> session;
};
struct DataGraphPipelineSessionCreateInfoARM {
	StructureType                           sType             = StructureType::DataGraphPipelineSessionCreateInfoARM;
	const void *                            pNext             = nullptr;
	DataGraphPipelineSessionCreateFlagsARM  flags             = {};
	impl_Struct::AssignableHandle<Pipeline> dataGraphPipeline;
};
struct DataGraphPipelineSessionMemoryRequirementsInfoARM {
	StructureType                                              sType       = StructureType::DataGraphPipelineSessionMemoryRequirementsInfoARM;
	const void *                                               pNext       = nullptr;
	impl_Struct::AssignableHandle<DataGraphPipelineSessionARM> session;
	DataGraphPipelineSessionBindPointARM                       bindPoint   = DataGraphPipelineSessionBindPointARM::Transient;
	uint32_t                                                   objectIndex = 0;
};
struct DataGraphPipelineSessionNeuralStatisticsCreateInfoARM {
	StructureType                      sType = StructureType::DataGraphPipelineSessionNeuralStatisticsCreateInfoARM;
	const void *                       pNext = nullptr;
	NeuralAcceleratorStatisticsModeARM mode  = NeuralAcceleratorStatisticsModeARM::Disabled;
};
struct DataGraphPipelineSingleNodeConnectionARM {
	StructureType                          sType      = StructureType::DataGraphPipelineSingleNodeConnectionARM;
	void *                                 pNext      = nullptr;
	uint32_t                               set        = 0;
	uint32_t                               binding    = 0;
	DataGraphPipelineNodeConnectionTypeARM connection = DataGraphPipelineNodeConnectionTypeARM::OpticalFlowInput;
};
struct DataGraphTOSANameQualityARM {
	impl_Struct::FixedString<Constants::MaxDataGraphTosaNameSizeARM> name         = {};// len null-terminated
	DataGraphTOSAQualityFlagsARM                                     qualityFlags = {};
};
struct DebugMarkerMarkerInfoEXT {
	StructureType            sType      = StructureType::DebugMarkerMarkerInfoEXT;
	const void *             pNext      = nullptr;
	impl_Struct::InOutString markerName;
	std::array<float, 4>     color      = {};
};
struct DebugMarkerObjectNameInfoEXT {
	StructureType            sType      = StructureType::DebugMarkerObjectNameInfoEXT;
	const void *             pNext      = nullptr;
	DebugReportObjectTypeEXT objectType = DebugReportObjectTypeEXT::Unknown;
	uint64_t                 object     = 0;
	impl_Struct::InOutString objectName;
};
struct DebugMarkerObjectTagInfoEXT {
	StructureType            sType      = StructureType::DebugMarkerObjectTagInfoEXT;
	const void *             pNext      = nullptr;
	DebugReportObjectTypeEXT objectType = DebugReportObjectTypeEXT::Unknown;
	uint64_t                 object     = 0;
	uint64_t                 tagName    = 0;
	size_t                   tagSize    = 0;
	const void *             pTag       = nullptr;// len tagSize
};
struct DebugReportCallbackCreateInfoEXT {
	StructureType               sType       = StructureType::DebugReportCallbackCreateInfoEXT;
	const void *                pNext       = nullptr;
	DebugReportFlagsEXT         flags       = {};
	PFN::DebugReportCallbackEXT pfnCallback = nullptr;
	void *                      pUserData   = nullptr;
};
struct DebugUtilsLabelEXT {
	StructureType            sType     = StructureType::DebugUtilsLabelEXT;
	const void *             pNext     = nullptr;
	impl_Struct::InOutString labelName;
	std::array<float, 4>     color     = {};
};
struct DebugUtilsMessengerCreateInfoEXT {
	StructureType                       sType           = StructureType::DebugUtilsMessengerCreateInfoEXT;
	const void *                        pNext           = nullptr;
	DebugUtilsMessengerCreateFlagsEXT   flags           = {};
	DebugUtilsMessageSeverityFlagsEXT   messageSeverity = {};
	DebugUtilsMessageTypeFlagsEXT       messageType     = {};
	PFN::DebugUtilsMessengerCallbackEXT pfnUserCallback = nullptr;
	void *                              pUserData       = nullptr;
};
struct DebugUtilsObjectNameInfoEXT {
	StructureType            sType        = StructureType::DebugUtilsObjectNameInfoEXT;
	const void *             pNext        = nullptr;
	ObjectType               objectType   = ObjectType::Unknown;
	uint64_t                 objectHandle = 0;
	impl_Struct::InOutString objectName;
};
struct DebugUtilsObjectTagInfoEXT {
	StructureType sType        = StructureType::DebugUtilsObjectTagInfoEXT;
	const void *  pNext        = nullptr;
	ObjectType    objectType   = ObjectType::Unknown;
	uint64_t      objectHandle = 0;
	uint64_t      tagName      = 0;
	size_t        tagSize      = 0;
	const void *  pTag         = nullptr;// len tagSize
};
struct DecompressMemoryRegionEXT {
	DeviceAddress srcAddress       = 0;
	DeviceAddress dstAddress       = 0;
	DeviceSize    compressedSize   = 0;
	DeviceSize    decompressedSize = 0;
};
struct DecompressMemoryRegionNV {
	DeviceAddress                     srcAddress          = 0;
	DeviceAddress                     dstAddress          = 0;
	DeviceSize                        compressedSize      = 0;
	DeviceSize                        decompressedSize    = 0;
	MemoryDecompressionMethodFlagsEXT decompressionMethod = {};
};
struct DedicatedAllocationBufferCreateInfoNV {
	StructureType sType               = StructureType::DedicatedAllocationBufferCreateInfoNV;
	const void *  pNext               = nullptr;
	Bool32        dedicatedAllocation = Constants::False;
};
struct DedicatedAllocationImageCreateInfoNV {
	StructureType sType               = StructureType::DedicatedAllocationImageCreateInfoNV;
	const void *  pNext               = nullptr;
	Bool32        dedicatedAllocation = Constants::False;
};
struct DedicatedAllocationMemoryAllocateInfoNV {
	StructureType                         sType  = StructureType::DedicatedAllocationMemoryAllocateInfoNV;
	const void *                          pNext  = nullptr;
	impl_Struct::AssignableHandle<Image>  image;
	impl_Struct::AssignableHandle<Buffer> buffer;
};
struct DepthBiasInfoEXT {
	StructureType sType                   = StructureType::DepthBiasInfoEXT;
	const void *  pNext                   = nullptr;
	float         depthBiasConstantFactor = 0.0F;
	float         depthBiasClamp          = 0.0F;
	float         depthBiasSlopeFactor    = 0.0F;
};
struct DepthBiasRepresentationInfoEXT {
	StructureType              sType                   = StructureType::DepthBiasRepresentationInfoEXT;
	const void *               pNext                   = nullptr;
	DepthBiasRepresentationEXT depthBiasRepresentation = DepthBiasRepresentationEXT::LeastRepresentableValueFormat;
	Bool32                     depthBiasExact          = Constants::False;
};
struct DepthClampRangeEXT {
	float minDepthClamp = 0.0F;
	float maxDepthClamp = 0.0F;
};
struct DescriptorAddressInfoEXT {
	StructureType sType   = StructureType::DescriptorAddressInfoEXT;
	void *        pNext   = nullptr;
	DeviceAddress address = 0;
	DeviceSize    range   = 0;
	Format        format  = Format::Undefined;
};
struct DescriptorBufferBindingInfoEXT {
	StructureType    sType   = StructureType::DescriptorBufferBindingInfoEXT;
	const void *     pNext   = nullptr;
	DeviceAddress    address = 0;
	BufferUsageFlags usage   = {};
};
struct DescriptorBufferBindingPushDescriptorBufferHandleEXT {
	StructureType                         sType  = StructureType::DescriptorBufferBindingPushDescriptorBufferHandleEXT;
	const void *                          pNext  = nullptr;
	impl_Struct::AssignableHandle<Buffer> buffer;
};
struct DescriptorBufferInfo {
	impl_Struct::AssignableHandle<Buffer> buffer;
	DeviceSize                            offset = 0;
	DeviceSize                            range  = 0;
};
struct DescriptorGetTensorInfoARM {
	StructureType                                sType      = StructureType::DescriptorGetTensorInfoARM;
	const void *                                 pNext      = nullptr;
	impl_Struct::AssignableHandle<TensorViewARM> tensorView;
};
struct DescriptorImageInfo {
	impl_Struct::AssignableHandle<Sampler>   sampler;
	impl_Struct::AssignableHandle<ImageView> imageView;
	ImageLayout                              imageLayout = ImageLayout::Undefined;
};
struct DescriptorMappingSourceHeapDataEXT {
	uint32_t heapOffset = 0;
	uint32_t pushOffset = 0;
};
struct DescriptorMappingSourceIndirectAddressEXT {
	uint32_t pushOffset    = 0;
	uint32_t addressOffset = 0;
};
struct DescriptorPoolInlineUniformBlockCreateInfo {
	StructureType sType                         = StructureType::DescriptorPoolInlineUniformBlockCreateInfo;
	const void *  pNext                         = nullptr;
	uint32_t      maxInlineUniformBlockBindings = 0;
};
struct DescriptorPoolSize {
	DescriptorType type            = DescriptorType::Sampler;
	uint32_t       descriptorCount = 0;
};
struct DescriptorSetAllocateInfo {
	StructureType                                             sType              = StructureType::DescriptorSetAllocateInfo;
	const void *                                              pNext              = nullptr;
	impl_Struct::AssignableHandle<DescriptorPool>             descriptorPool;
	uint32_t                                                  descriptorSetCount = 0;
	const impl_Struct::AssignableHandle<DescriptorSetLayout> *pSetLayouts        = nullptr;// len descriptorSetCount
	auto setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>>;
};
struct DescriptorSetBindingReferenceVALVE {
	StructureType                                      sType               = StructureType::DescriptorSetBindingReferenceVALVE;
	const void *                                       pNext               = nullptr;
	impl_Struct::AssignableHandle<DescriptorSetLayout> descriptorSetLayout;
	uint32_t                                           binding             = 0;
};
struct DescriptorSetLayoutBinding {
	uint32_t                                      binding            = 0;
	DescriptorType                                descriptorType     = DescriptorType::Sampler;
	uint32_t                                      descriptorCount    = 0;
	ShaderStageFlags                              stageFlags         = {};
	const impl_Struct::AssignableHandle<Sampler> *pImmutableSamplers = nullptr;// len descriptorCount
	auto immutableSamplers() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Sampler>>;
};
struct DescriptorSetLayoutBindingFlagsCreateInfo {
	StructureType                 sType         = StructureType::DescriptorSetLayoutBindingFlagsCreateInfo;
	const void *                  pNext         = nullptr;
	uint32_t                      bindingCount  = 0;
	const DescriptorBindingFlags *pBindingFlags = nullptr;// len bindingCount
	auto bindingFlags() -> impl_Struct::VecView<uint32_t, DescriptorBindingFlags>;
};
struct DescriptorSetLayoutHostMappingInfoVALVE {
	StructureType sType            = StructureType::DescriptorSetLayoutHostMappingInfoVALVE;
	void *        pNext            = nullptr;
	size_t        descriptorOffset = 0;
	uint32_t      descriptorSize   = 0;
};
struct DescriptorSetLayoutSupport {
	StructureType sType     = StructureType::DescriptorSetLayoutSupport;
	void *        pNext     = nullptr;
	Bool32        supported = Constants::False;
};
struct DescriptorSetVariableDescriptorCountAllocateInfo {
	StructureType   sType              = StructureType::DescriptorSetVariableDescriptorCountAllocateInfo;
	const void *    pNext              = nullptr;
	uint32_t        descriptorSetCount = 0;
	const uint32_t *pDescriptorCounts  = nullptr;// len descriptorSetCount
	auto descriptorCounts() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct DescriptorSetVariableDescriptorCountLayoutSupport {
	StructureType sType                      = StructureType::DescriptorSetVariableDescriptorCountLayoutSupport;
	void *        pNext                      = nullptr;
	uint32_t      maxVariableDescriptorCount = 0;
};
struct DescriptorUpdateTemplateEntry {
	uint32_t       dstBinding      = 0;
	uint32_t       dstArrayElement = 0;
	uint32_t       descriptorCount = 0;
	DescriptorType descriptorType  = DescriptorType::Sampler;
	size_t         offset          = 0;
	size_t         stride          = 0;
};
struct DeviceAddressBindingCallbackDataEXT {
	StructureType                sType       = StructureType::DeviceAddressBindingCallbackDataEXT;
	void *                       pNext       = nullptr;
	DeviceAddressBindingFlagsEXT flags       = {};
	DeviceAddress                baseAddress = 0;
	DeviceSize                   size        = 0;
	DeviceAddressBindingTypeEXT  bindingType = DeviceAddressBindingTypeEXT::Bind;
};
struct DeviceAddressRangeKHR {
	DeviceAddress address = 0;
	DeviceSize    size    = 0;
};
struct DeviceDeviceMemoryReportCreateInfoEXT {
	StructureType                      sType           = StructureType::DeviceDeviceMemoryReportCreateInfoEXT;
	const void *                       pNext           = nullptr;
	DeviceMemoryReportFlagsEXT         flags           = {};
	PFN::DeviceMemoryReportCallbackEXT pfnUserCallback = nullptr;
	void *                             pUserData       = nullptr;
};
struct DeviceDiagnosticsConfigCreateInfoNV {
	StructureType                  sType = StructureType::DeviceDiagnosticsConfigCreateInfoNV;
	const void *                   pNext = nullptr;
	DeviceDiagnosticsConfigFlagsNV flags = {};
};
struct DeviceEventInfoEXT {
	StructureType      sType       = StructureType::DeviceEventInfoEXT;
	const void *       pNext       = nullptr;
	DeviceEventTypeEXT deviceEvent = DeviceEventTypeEXT::DisplayHotplug;
};
struct DeviceFaultAddressInfoKHR {
	DeviceFaultAddressTypeKHR addressType      = DeviceFaultAddressTypeKHR::None;
	DeviceAddress             reportedAddress  = 0;
	DeviceSize                addressPrecision = 0;
};
struct DeviceFaultCountsEXT {
	StructureType sType            = StructureType::DeviceFaultCountsEXT;
	void *        pNext            = nullptr;
	uint32_t      addressInfoCount = 0;
	uint32_t      vendorInfoCount  = 0;
	DeviceSize    vendorBinarySize = 0;
};
struct DeviceFaultDebugInfoKHR {
	StructureType sType             = StructureType::DeviceFaultDebugInfoKHR;
	void *        pNext             = nullptr;
	uint32_t      vendorBinarySize  = 0;
	void *        pVendorBinaryData = nullptr;// len vendorBinarySize
};
struct DeviceFaultShaderAbortMessageInfoKHR {
	StructureType sType           = StructureType::DeviceFaultShaderAbortMessageInfoKHR;
	void *        pNext           = nullptr;
	uint64_t      messageDataSize = 0;
	void *        pMessageData    = nullptr;// len messageDataSize
};
struct DeviceFaultVendorBinaryHeaderVersionOneKHR {
	uint32_t                                 headerSize            = 0;
	DeviceFaultVendorBinaryHeaderVersionKHR  headerVersion         = DeviceFaultVendorBinaryHeaderVersionKHR::One;
	uint32_t                                 vendorID              = 0;
	uint32_t                                 deviceID              = 0;
	uint32_t                                 driverVersion         = 0;
	std::array<uint8_t, Constants::UuidSize> pipelineCacheUUID     = {};
	uint32_t                                 applicationNameOffset = 0;
	uint32_t                                 applicationVersion    = 0;
	uint32_t                                 engineNameOffset      = 0;
	uint32_t                                 engineVersion         = 0;
	uint32_t                                 apiVersion            = 0;
};
struct DeviceFaultVendorInfoKHR {
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description     = {};// len null-terminated
	uint64_t                                                vendorFaultCode = 0;
	uint64_t                                                vendorFaultData = 0;
};
struct DeviceGroupBindSparseInfo {
	StructureType sType               = StructureType::DeviceGroupBindSparseInfo;
	const void *  pNext               = nullptr;
	uint32_t      resourceDeviceIndex = 0;
	uint32_t      memoryDeviceIndex   = 0;
};
struct DeviceGroupCommandBufferBeginInfo {
	StructureType sType      = StructureType::DeviceGroupCommandBufferBeginInfo;
	const void *  pNext      = nullptr;
	uint32_t      deviceMask = 0;
};
struct DeviceGroupDeviceCreateInfo {
	StructureType                                        sType               = StructureType::DeviceGroupDeviceCreateInfo;
	const void *                                         pNext               = nullptr;
	uint32_t                                             physicalDeviceCount = 0;
	const impl_Struct::AssignableHandle<PhysicalDevice> *pPhysicalDevices    = nullptr;// len physicalDeviceCount
	auto physicalDevices() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<PhysicalDevice>>;
};
struct DeviceGroupPresentCapabilitiesKHR {
	StructureType                                       sType       = StructureType::DeviceGroupPresentCapabilitiesKHR;
	void *                                              pNext       = nullptr;
	std::array<uint32_t, Constants::MaxDeviceGroupSize> presentMask = {};
	DeviceGroupPresentModeFlagsKHR                      modes       = {};
};
struct DeviceGroupPresentInfoKHR {
	StructureType                 sType          = StructureType::DeviceGroupPresentInfoKHR;
	const void *                  pNext          = nullptr;
	uint32_t                      swapchainCount = 0;
	const uint32_t *              pDeviceMasks   = nullptr;// len swapchainCount
	DeviceGroupPresentModeBitsKHR mode           = DeviceGroupPresentModeBitsKHR::Local;
	auto deviceMasks() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct DeviceGroupSubmitInfo {
	StructureType   sType                         = StructureType::DeviceGroupSubmitInfo;
	const void *    pNext                         = nullptr;
	uint32_t        waitSemaphoreCount            = 0;
	const uint32_t *pWaitSemaphoreDeviceIndices   = nullptr;// len waitSemaphoreCount
	uint32_t        commandBufferCount            = 0;
	const uint32_t *pCommandBufferDeviceMasks     = nullptr;// len commandBufferCount
	uint32_t        signalSemaphoreCount          = 0;
	const uint32_t *pSignalSemaphoreDeviceIndices = nullptr;// len signalSemaphoreCount
	auto waitSemaphoreDeviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
	auto commandBufferDeviceMasks() -> impl_Struct::VecView<uint32_t, uint32_t>;
	auto signalSemaphoreDeviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct DeviceGroupSwapchainCreateInfoKHR {
	StructureType                  sType = StructureType::DeviceGroupSwapchainCreateInfoKHR;
	const void *                   pNext = nullptr;
	DeviceGroupPresentModeFlagsKHR modes = {};
};
struct DeviceMemoryOpaqueCaptureAddressInfo {
	StructureType                               sType  = StructureType::DeviceMemoryOpaqueCaptureAddressInfo;
	const void *                                pNext  = nullptr;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
};
struct DeviceMemoryOverallocationCreateInfoAMD {
	StructureType                   sType                  = StructureType::DeviceMemoryOverallocationCreateInfoAMD;
	const void *                    pNext                  = nullptr;
	MemoryOverallocationBehaviorAMD overallocationBehavior = MemoryOverallocationBehaviorAMD::Default;
};
struct DeviceMemoryReportCallbackDataEXT {
	StructureType                  sType          = StructureType::DeviceMemoryReportCallbackDataEXT;
	void *                         pNext          = nullptr;
	DeviceMemoryReportFlagsEXT     flags          = {};
	DeviceMemoryReportEventTypeEXT type           = DeviceMemoryReportEventTypeEXT::Allocate;
	uint64_t                       memoryObjectId = 0;
	DeviceSize                     size           = 0;
	ObjectType                     objectType     = ObjectType::Unknown;
	uint64_t                       objectHandle   = 0;
	uint32_t                       heapIndex      = 0;
};
union DeviceOrHostAddressConstKHR {
	DeviceAddress deviceAddress;
	const void *  hostAddress;
};
union DeviceOrHostAddressKHR {
	DeviceAddress deviceAddress;
	void *        hostAddress;
};
struct DevicePipelineBinaryInternalCacheControlKHR {
	StructureType sType                = StructureType::DevicePipelineBinaryInternalCacheControlKHR;
	const void *  pNext                = nullptr;
	Bool32        disableInternalCache = Constants::False;
};
struct DevicePrivateDataCreateInfo {
	StructureType sType                       = StructureType::DevicePrivateDataCreateInfo;
	const void *  pNext                       = nullptr;
	uint32_t      privateDataSlotRequestCount = 0;
};
struct DeviceQueueCreateInfo {
	StructureType          sType            = StructureType::DeviceQueueCreateInfo;
	const void *           pNext            = nullptr;
	DeviceQueueCreateFlags flags            = {};
	uint32_t               queueFamilyIndex = 0;
	uint32_t               queueCount       = 0;
	const float *          pQueuePriorities = nullptr;// len queueCount
	auto queuePriorities() -> impl_Struct::VecView<uint32_t, float>;
};
struct DeviceQueueGlobalPriorityCreateInfo {
	StructureType       sType          = StructureType::DeviceQueueGlobalPriorityCreateInfo;
	const void *        pNext          = nullptr;
	QueueGlobalPriority globalPriority = QueueGlobalPriority::Low;
};
struct DeviceQueueInfo2 {
	StructureType          sType            = StructureType::DeviceQueueInfo2;
	const void *           pNext            = nullptr;
	DeviceQueueCreateFlags flags            = {};
	uint32_t               queueFamilyIndex = 0;
	uint32_t               queueIndex       = 0;
};
struct DeviceQueueShaderCoreControlCreateInfoARM {
	StructureType sType           = StructureType::DeviceQueueShaderCoreControlCreateInfoARM;
	void *        pNext           = nullptr;
	uint32_t      shaderCoreCount = 0;
};
struct DirectDriverLoadingInfoLUNARG {
	StructureType                  sType                  = StructureType::DirectDriverLoadingInfoLUNARG;
	void *                         pNext                  = nullptr;
	DirectDriverLoadingFlagsLUNARG flags                  = {};
	PFN::GetInstanceProcAddrLUNARG pfnGetInstanceProcAddr = nullptr;
};
struct DispatchIndirectCommand {
	uint32_t x = 0;
	uint32_t y = 0;
	uint32_t z = 0;
};
struct DispatchParametersARM {
	StructureType sType                     = StructureType::DispatchParametersARM;
	void *        pNext                     = nullptr;
	uint32_t      workGroupBatchSize        = 0;
	uint32_t      maxQueuedWorkGroupBatches = 0;
	uint32_t      maxWarpsPerShaderCore     = 0;
};
struct DispatchTileInfoQCOM {
	StructureType sType = StructureType::DispatchTileInfoQCOM;
	const void *  pNext = nullptr;
};
struct DisplayEventInfoEXT {
	StructureType       sType        = StructureType::DisplayEventInfoEXT;
	const void *        pNext        = nullptr;
	DisplayEventTypeEXT displayEvent = DisplayEventTypeEXT::FirstPixelOut;
};
struct DisplayModeStereoPropertiesNV {
	StructureType sType           = StructureType::DisplayModeStereoPropertiesNV;
	void *        pNext           = nullptr;
	Bool32        hdmi3DSupported = Constants::False;
};
struct DisplayNativeHdrSurfaceCapabilitiesAMD {
	StructureType sType               = StructureType::DisplayNativeHdrSurfaceCapabilitiesAMD;
	void *        pNext               = nullptr;
	Bool32        localDimmingSupport = Constants::False;
};
struct DisplayPlaneInfo2KHR {
	StructureType                                 sType      = StructureType::DisplayPlaneInfo2KHR;
	const void *                                  pNext      = nullptr;
	impl_Struct::AssignableHandle<DisplayModeKHR> mode;
	uint32_t                                      planeIndex = 0;
};
struct DisplayPlanePropertiesKHR {
	impl_Struct::AssignableHandle<DisplayKHR> currentDisplay;
	uint32_t                                  currentStackIndex = 0;
};
struct DisplayPowerInfoEXT {
	StructureType        sType      = StructureType::DisplayPowerInfoEXT;
	const void *         pNext      = nullptr;
	DisplayPowerStateEXT powerState = DisplayPowerStateEXT::Off;
};
struct DisplaySurfaceStereoCreateInfoNV {
	StructureType              sType      = StructureType::DisplaySurfaceStereoCreateInfoNV;
	const void *               pNext      = nullptr;
	DisplaySurfaceStereoTypeNV stereoType = DisplaySurfaceStereoTypeNV::None;
};
struct DrawIndexedIndirectCommand {
	uint32_t indexCount    = 0;
	uint32_t instanceCount = 0;
	uint32_t firstIndex    = 0;
	int32_t  vertexOffset  = 0;
	uint32_t firstInstance = 0;
};
struct DrawIndirectCommand {
	uint32_t vertexCount   = 0;
	uint32_t instanceCount = 0;
	uint32_t firstVertex   = 0;
	uint32_t firstInstance = 0;
};
struct DrawIndirectCountIndirectCommandEXT {
	DeviceAddress bufferAddress = 0;
	uint32_t      stride        = 0;
	uint32_t      commandCount  = 0;
};
struct DrawMeshTasksIndirectCommandEXT {
	uint32_t groupCountX = 0;
	uint32_t groupCountY = 0;
	uint32_t groupCountZ = 0;
};
struct DrawMeshTasksIndirectCommandNV {
	uint32_t taskCount = 0;
	uint32_t firstTask = 0;
};
struct DrmFormatModifierProperties2EXT {
	uint64_t            drmFormatModifier               = 0;
	uint32_t            drmFormatModifierPlaneCount     = 0;
	FormatFeatureFlags2 drmFormatModifierTilingFeatures = {};
};
struct DrmFormatModifierPropertiesEXT {
	uint64_t           drmFormatModifier               = 0;
	uint32_t           drmFormatModifierPlaneCount     = 0;
	FormatFeatureFlags drmFormatModifierTilingFeatures = {};
};
struct EventCreateInfo {
	StructureType    sType = StructureType::EventCreateInfo;
	const void *     pNext = nullptr;
	EventCreateFlags flags = {};
};
struct ExportFenceCreateInfo {
	StructureType                sType       = StructureType::ExportFenceCreateInfo;
	const void *                 pNext       = nullptr;
	ExternalFenceHandleTypeFlags handleTypes = {};
};
struct ExportMemoryAllocateInfo {
	StructureType                 sType       = StructureType::ExportMemoryAllocateInfo;
	const void *                  pNext       = nullptr;
	ExternalMemoryHandleTypeFlags handleTypes = {};
};
struct ExportMemoryAllocateInfoNV {
	StructureType                   sType       = StructureType::ExportMemoryAllocateInfoNV;
	const void *                    pNext       = nullptr;
	ExternalMemoryHandleTypeFlagsNV handleTypes = {};
};
struct ExportSemaphoreCreateInfo {
	StructureType                    sType       = StructureType::ExportSemaphoreCreateInfo;
	const void *                     pNext       = nullptr;
	ExternalSemaphoreHandleTypeFlags handleTypes = {};
};
struct ExtensionProperties {
	impl_Struct::FixedString<Constants::MaxExtensionNameSize> extensionName = {};// len null-terminated
	uint32_t                                                  specVersion   = 0;
};
struct Extent2D {
	uint32_t width  = 0;
	uint32_t height = 0;
};
struct Extent3D {
	uint32_t width  = 0;
	uint32_t height = 0;
	uint32_t depth  = 0;
};
struct ExternalComputeQueueCreateInfoNV {
	StructureType                        sType          = StructureType::ExternalComputeQueueCreateInfoNV;
	const void *                         pNext          = nullptr;
	impl_Struct::AssignableHandle<Queue> preferredQueue;
};
struct ExternalComputeQueueDataParamsNV {
	StructureType sType       = StructureType::ExternalComputeQueueDataParamsNV;
	const void *  pNext       = nullptr;
	uint32_t      deviceIndex = 0;
};
struct ExternalComputeQueueDeviceCreateInfoNV {
	StructureType sType                  = StructureType::ExternalComputeQueueDeviceCreateInfoNV;
	const void *  pNext                  = nullptr;
	uint32_t      reservedExternalQueues = 0;
};
struct ExternalFenceProperties {
	StructureType                sType                         = StructureType::ExternalFenceProperties;
	void *                       pNext                         = nullptr;
	ExternalFenceHandleTypeFlags exportFromImportedHandleTypes = {};
	ExternalFenceHandleTypeFlags compatibleHandleTypes         = {};
	ExternalFenceFeatureFlags    externalFenceFeatures         = {};
};
struct ExternalMemoryAcquireUnmodifiedEXT {
	StructureType sType                   = StructureType::ExternalMemoryAcquireUnmodifiedEXT;
	const void *  pNext                   = nullptr;
	Bool32        acquireUnmodifiedMemory = Constants::False;
};
struct ExternalMemoryBufferCreateInfo {
	StructureType                 sType       = StructureType::ExternalMemoryBufferCreateInfo;
	const void *                  pNext       = nullptr;
	ExternalMemoryHandleTypeFlags handleTypes = {};
};
struct ExternalMemoryImageCreateInfo {
	StructureType                 sType       = StructureType::ExternalMemoryImageCreateInfo;
	const void *                  pNext       = nullptr;
	ExternalMemoryHandleTypeFlags handleTypes = {};
};
struct ExternalMemoryImageCreateInfoNV {
	StructureType                   sType       = StructureType::ExternalMemoryImageCreateInfoNV;
	const void *                    pNext       = nullptr;
	ExternalMemoryHandleTypeFlagsNV handleTypes = {};
};
struct ExternalMemoryProperties {
	ExternalMemoryFeatureFlags    externalMemoryFeatures        = {};
	ExternalMemoryHandleTypeFlags exportFromImportedHandleTypes = {};
	ExternalMemoryHandleTypeFlags compatibleHandleTypes         = {};
};
struct ExternalMemoryTensorCreateInfoARM {
	StructureType                 sType       = StructureType::ExternalMemoryTensorCreateInfoARM;
	const void *                  pNext       = nullptr;
	ExternalMemoryHandleTypeFlags handleTypes = {};
};
struct ExternalSemaphoreProperties {
	StructureType                    sType                         = StructureType::ExternalSemaphoreProperties;
	void *                           pNext                         = nullptr;
	ExternalSemaphoreHandleTypeFlags exportFromImportedHandleTypes = {};
	ExternalSemaphoreHandleTypeFlags compatibleHandleTypes         = {};
	ExternalSemaphoreFeatureFlags    externalSemaphoreFeatures     = {};
};
struct FenceCreateInfo {
	StructureType    sType = StructureType::FenceCreateInfo;
	const void *     pNext = nullptr;
	FenceCreateFlags flags = {};
};
struct FenceGetFdInfoKHR {
	StructureType                        sType      = StructureType::FenceGetFdInfoKHR;
	const void *                         pNext      = nullptr;
	impl_Struct::AssignableHandle<Fence> fence;
	ExternalFenceHandleTypeBits          handleType = ExternalFenceHandleTypeBits::OpaqueFd;
};
struct FilterCubicImageViewImageFormatPropertiesEXT {
	StructureType sType             = StructureType::FilterCubicImageViewImageFormatPropertiesEXT;
	void *        pNext             = nullptr;
	Bool32        filterCubic       = Constants::False;
	Bool32        filterCubicMinmax = Constants::False;
};
struct FormatProperties {
	FormatFeatureFlags linearTilingFeatures  = {};
	FormatFeatureFlags optimalTilingFeatures = {};
	FormatFeatureFlags bufferFeatures        = {};
};
struct FormatProperties3 {
	StructureType       sType                 = StructureType::FormatProperties3;
	void *              pNext                 = nullptr;
	FormatFeatureFlags2 linearTilingFeatures  = {};
	FormatFeatureFlags2 optimalTilingFeatures = {};
	FormatFeatureFlags2 bufferFeatures        = {};
};
struct FormatProperties4KHR {
	StructureType          sType                 = StructureType::FormatProperties4KHR;
	void *                 pNext                 = nullptr;
	FormatFeatureFlags4KHR linearTilingFeatures  = {};
	FormatFeatureFlags4KHR optimalTilingFeatures = {};
	FormatFeatureFlags4KHR bufferFeatures        = {};
};
struct FrameBoundaryEXT {
	StructureType                                sType       = StructureType::FrameBoundaryEXT;
	const void *                                 pNext       = nullptr;
	FrameBoundaryFlagsEXT                        flags       = {};
	uint64_t                                     frameID     = 0;
	uint32_t                                     imageCount  = 0;
	const impl_Struct::AssignableHandle<Image> * pImages     = nullptr;// len imageCount
	uint32_t                                     bufferCount = 0;
	const impl_Struct::AssignableHandle<Buffer> *pBuffers    = nullptr;// len bufferCount
	uint64_t                                     tagName     = 0;
	size_t                                       tagSize     = 0;
	const void *                                 pTag        = nullptr;// len tagSize
	auto images() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Image>>;
	auto buffers() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Buffer>>;
};
struct FrameBoundaryTensorsARM {
	StructureType                                   sType       = StructureType::FrameBoundaryTensorsARM;
	const void *                                    pNext       = nullptr;
	uint32_t                                        tensorCount = 0;
	const impl_Struct::AssignableHandle<TensorARM> *pTensors    = nullptr;// len tensorCount
	auto tensors() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<TensorARM>>;
};
struct FramebufferAttachmentImageInfo {
	StructureType    sType           = StructureType::FramebufferAttachmentImageInfo;
	const void *     pNext           = nullptr;
	ImageCreateFlags flags           = {};
	ImageUsageFlags  usage           = {};
	uint32_t         width           = 0;
	uint32_t         height          = 0;
	uint32_t         layerCount      = 0;
	uint32_t         viewFormatCount = 0;
	const Format *   pViewFormats    = nullptr;// len viewFormatCount
	auto viewFormats() -> impl_Struct::VecView<uint32_t, Format>;
};
struct FramebufferCreateInfo {
	StructureType                                   sType           = StructureType::FramebufferCreateInfo;
	const void *                                    pNext           = nullptr;
	FramebufferCreateFlags                          flags           = {};
	impl_Struct::AssignableHandle<RenderPass>       renderPass;
	uint32_t                                        attachmentCount = 0;
	const impl_Struct::AssignableHandle<ImageView> *pAttachments    = nullptr;// len attachmentCount
	uint32_t                                        width           = 0;
	uint32_t                                        height          = 0;
	uint32_t                                        layers          = 0;
	auto attachments() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ImageView>>;
};
struct FramebufferMixedSamplesCombinationNV {
	StructureType           sType                 = StructureType::FramebufferMixedSamplesCombinationNV;
	void *                  pNext                 = nullptr;
	CoverageReductionModeNV coverageReductionMode = CoverageReductionModeNV::Merge;
	SampleCountBits         rasterizationSamples  = SampleCountBits::v1;
	SampleCountFlags        depthStencilSamples   = {};
	SampleCountFlags        colorSamples          = {};
};
struct GeneratedCommandsInfoEXT {
	StructureType                                            sType                  = StructureType::GeneratedCommandsInfoEXT;
	const void *                                             pNext                  = nullptr;
	ShaderStageFlags                                         shaderStages           = {};
	impl_Struct::AssignableHandle<IndirectExecutionSetEXT>   indirectExecutionSet;
	impl_Struct::AssignableHandle<IndirectCommandsLayoutEXT> indirectCommandsLayout;
	DeviceAddress                                            indirectAddress        = 0;
	DeviceSize                                               indirectAddressSize    = 0;
	DeviceAddress                                            preprocessAddress      = 0;
	DeviceSize                                               preprocessSize         = 0;
	uint32_t                                                 maxSequenceCount       = 0;
	DeviceAddress                                            sequenceCountAddress   = 0;
	uint32_t                                                 maxDrawCount           = 0;
};
struct GeneratedCommandsMemoryRequirementsInfoEXT {
	StructureType                                            sType                  = StructureType::GeneratedCommandsMemoryRequirementsInfoEXT;
	const void *                                             pNext                  = nullptr;
	impl_Struct::AssignableHandle<IndirectExecutionSetEXT>   indirectExecutionSet;
	impl_Struct::AssignableHandle<IndirectCommandsLayoutEXT> indirectCommandsLayout;
	uint32_t                                                 maxSequenceCount       = 0;
	uint32_t                                                 maxDrawCount           = 0;
};
struct GeneratedCommandsMemoryRequirementsInfoNV {
	StructureType                                           sType                  = StructureType::GeneratedCommandsMemoryRequirementsInfoNV;
	const void *                                            pNext                  = nullptr;
	PipelineBindPoint                                       pipelineBindPoint      = PipelineBindPoint::Graphics;
	impl_Struct::AssignableHandle<Pipeline>                 pipeline;
	impl_Struct::AssignableHandle<IndirectCommandsLayoutNV> indirectCommandsLayout;
	uint32_t                                                maxSequencesCount      = 0;
};
struct GeneratedCommandsPipelineInfoEXT {
	StructureType                           sType    = StructureType::GeneratedCommandsPipelineInfoEXT;
	void *                                  pNext    = nullptr;
	impl_Struct::AssignableHandle<Pipeline> pipeline;
};
struct GeneratedCommandsShaderInfoEXT {
	StructureType                                   sType       = StructureType::GeneratedCommandsShaderInfoEXT;
	void *                                          pNext       = nullptr;
	uint32_t                                        shaderCount = 0;
	const impl_Struct::AssignableHandle<ShaderEXT> *pShaders    = nullptr;// len shaderCount
	auto shaders() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ShaderEXT>>;
};
struct GeometryAABBNV {
	StructureType                         sType    = StructureType::GeometryAabbNV;
	const void *                          pNext    = nullptr;
	impl_Struct::AssignableHandle<Buffer> aabbData;
	uint32_t                              numAABBs = 0;
	uint32_t                              stride   = 0;
	DeviceSize                            offset   = 0;
};
struct GeometryTrianglesNV {
	StructureType                         sType           = StructureType::GeometryTrianglesNV;
	const void *                          pNext           = nullptr;
	impl_Struct::AssignableHandle<Buffer> vertexData;
	DeviceSize                            vertexOffset    = 0;
	uint32_t                              vertexCount     = 0;
	DeviceSize                            vertexStride    = 0;
	Format                                vertexFormat    = Format::Undefined;
	impl_Struct::AssignableHandle<Buffer> indexData;
	DeviceSize                            indexOffset     = 0;
	uint32_t                              indexCount      = 0;
	IndexType                             indexType       = IndexType::Uint16;
	impl_Struct::AssignableHandle<Buffer> transformData;
	DeviceSize                            transformOffset = 0;
};
struct GpaDeviceClockModeInfoAMD {
	StructureType         sType                  = StructureType::GpaDeviceClockModeInfoAMD;
	const void *          pNext                  = nullptr;
	GpaDeviceClockModeAMD clockMode              = GpaDeviceClockModeAMD::Default;
	float                 memoryClockRatioToPeak = 0.0F;
	float                 engineClockRatioToPeak = 0.0F;
};
struct GpaDeviceGetClockInfoAMD {
	StructureType sType                  = StructureType::GpaDeviceGetClockInfoAMD;
	void *        pNext                  = nullptr;
	float         memoryClockRatioToPeak = 0.0F;
	float         engineClockRatioToPeak = 0.0F;
	uint32_t      memoryClockFrequency   = 0;
	uint32_t      engineClockFrequency   = 0;
};
struct GpaPerfBlockPropertiesAMD {
	GpaPerfBlockAMD                blockType               = GpaPerfBlockAMD::Cpf;
	GpaPerfBlockPropertiesFlagsAMD flags                   = {};
	uint32_t                       instanceCount           = 0;
	uint32_t                       maxEventID              = 0;
	uint32_t                       maxGlobalOnlyCounters   = 0;
	uint32_t                       maxGlobalSharedCounters = 0;
	uint32_t                       maxStreamingCounters    = 0;
};
struct GpaPerfCounterAMD {
	GpaPerfBlockAMD blockType     = GpaPerfBlockAMD::Cpf;
	uint32_t        blockInstance = 0;
	uint32_t        eventID       = 0;
};
struct GpaSessionCreateInfoAMD {
	StructureType                                sType               = StructureType::GpaSessionCreateInfoAMD;
	const void *                                 pNext               = nullptr;
	impl_Struct::AssignableHandle<GpaSessionAMD> secondaryCopySource;
};
struct GraphicsPipelineLibraryCreateInfoEXT {
	StructureType                   sType = StructureType::GraphicsPipelineLibraryCreateInfoEXT;
	const void *                    pNext = nullptr;
	GraphicsPipelineLibraryFlagsEXT flags = {};
};
struct HdrVividDynamicMetadataHUAWEI {
	StructureType sType               = StructureType::HdrVividDynamicMetadataHUAWEI;
	const void *  pNext               = nullptr;
	size_t        dynamicMetadataSize = 0;
	const void *  pDynamicMetadata    = nullptr;// len dynamicMetadataSize
};
struct HeadlessSurfaceCreateInfoEXT {
	StructureType                 sType = StructureType::HeadlessSurfaceCreateInfoEXT;
	const void *                  pNext = nullptr;
	HeadlessSurfaceCreateFlagsEXT flags = {};
};
struct HostAddressRangeConstEXT {
	const void *address = nullptr;// len size
	size_t      size    = 0;
};
struct HostAddressRangeEXT {
	void * address = nullptr;// len size
	size_t size    = 0;
};
struct HostImageCopyDevicePerformanceQuery {
	StructureType sType                 = StructureType::HostImageCopyDevicePerformanceQuery;
	void *        pNext                 = nullptr;
	Bool32        optimalDeviceAccess   = Constants::False;
	Bool32        identicalMemoryLayout = Constants::False;
};
struct ImageAlignmentControlCreateInfoMESA {
	StructureType sType                     = StructureType::ImageAlignmentControlCreateInfoMESA;
	const void *  pNext                     = nullptr;
	uint32_t      maximumRequestedAlignment = 0;
};
struct ImageCaptureDescriptorDataInfoEXT {
	StructureType                        sType = StructureType::ImageCaptureDescriptorDataInfoEXT;
	const void *                         pNext = nullptr;
	impl_Struct::AssignableHandle<Image> image;
};
struct ImageCompressionControlEXT {
	StructureType                      sType                        = StructureType::ImageCompressionControlEXT;
	const void *                       pNext                        = nullptr;
	ImageCompressionFlagsEXT           flags                        = {};
	uint32_t                           compressionControlPlaneCount = 0;
	ImageCompressionFixedRateFlagsEXT *pFixedRateFlags              = nullptr;// len compressionControlPlaneCount
};
struct ImageCompressionPropertiesEXT {
	StructureType                     sType                          = StructureType::ImageCompressionPropertiesEXT;
	void *                            pNext                          = nullptr;
	ImageCompressionFlagsEXT          imageCompressionFlags          = {};
	ImageCompressionFixedRateFlagsEXT imageCompressionFixedRateFlags = {};
};
struct ImageCreateFlags2CreateInfoKHR {
	StructureType        sType = StructureType::ImageCreateFlags2CreateInfoKHR;
	void *               pNext = nullptr;
	ImageCreateFlags2KHR flags = {};
};
struct ImageDrmFormatModifierListCreateInfoEXT {
	StructureType   sType                  = StructureType::ImageDrmFormatModifierListCreateInfoEXT;
	const void *    pNext                  = nullptr;
	uint32_t        drmFormatModifierCount = 0;
	const uint64_t *pDrmFormatModifiers    = nullptr;// len drmFormatModifierCount
	auto drmFormatModifiers() -> impl_Struct::VecView<uint32_t, uint64_t>;
};
struct ImageDrmFormatModifierPropertiesEXT {
	StructureType sType             = StructureType::ImageDrmFormatModifierPropertiesEXT;
	void *        pNext             = nullptr;
	uint64_t      drmFormatModifier = 0;
};
struct ImageFormatListCreateInfo {
	StructureType sType           = StructureType::ImageFormatListCreateInfo;
	const void *  pNext           = nullptr;
	uint32_t      viewFormatCount = 0;
	const Format *pViewFormats    = nullptr;// len viewFormatCount
	auto viewFormats() -> impl_Struct::VecView<uint32_t, Format>;
};
struct ImageMemoryRequirementsInfo2 {
	StructureType                        sType = StructureType::ImageMemoryRequirementsInfo2;
	const void *                         pNext = nullptr;
	impl_Struct::AssignableHandle<Image> image;
};
struct ImagePlaneMemoryRequirementsInfo {
	StructureType   sType       = StructureType::ImagePlaneMemoryRequirementsInfo;
	const void *    pNext       = nullptr;
	ImageAspectBits planeAspect = ImageAspectBits::None;
};
struct ImageSparseMemoryRequirementsInfo2 {
	StructureType                        sType = StructureType::ImageSparseMemoryRequirementsInfo2;
	const void *                         pNext = nullptr;
	impl_Struct::AssignableHandle<Image> image;
};
struct ImageStencilUsage2CreateInfoKHR {
	StructureType       sType        = StructureType::ImageStencilUsage2CreateInfoKHR;
	void *              pNext        = nullptr;
	ImageUsageFlags2KHR stencilUsage = {};
};
struct ImageStencilUsageCreateInfo {
	StructureType   sType        = StructureType::ImageStencilUsageCreateInfo;
	const void *    pNext        = nullptr;
	ImageUsageFlags stencilUsage = {};
};
struct ImageSubresource {
	ImageAspectFlags aspectMask = {};
	uint32_t         mipLevel   = 0;
	uint32_t         arrayLayer = 0;
};
struct ImageSubresourceLayers {
	ImageAspectFlags aspectMask     = {};
	uint32_t         mipLevel       = 0;
	uint32_t         baseArrayLayer = 0;
	uint32_t         layerCount     = 0;
};
struct ImageSubresourceRange {
	ImageAspectFlags aspectMask     = {};
	uint32_t         baseMipLevel   = 0;
	uint32_t         levelCount     = 0;
	uint32_t         baseArrayLayer = 0;
	uint32_t         layerCount     = 0;
};
struct ImageSwapchainCreateInfoKHR {
	StructureType                               sType     = StructureType::ImageSwapchainCreateInfoKHR;
	const void *                                pNext     = nullptr;
	impl_Struct::AssignableHandle<SwapchainKHR> swapchain;
};
struct ImageTilingControlCreateInfoEXT {
	StructureType         sType         = StructureType::ImageTilingControlCreateInfoEXT;
	const void *          pNext         = nullptr;
	ImageTilingControlEXT tilingControl = ImageTilingControlEXT::Default;
};
struct ImageUsageFlags2CreateInfoKHR {
	StructureType       sType = StructureType::ImageUsageFlags2CreateInfoKHR;
	void *              pNext = nullptr;
	ImageUsageFlags2KHR usage = {};
};
struct ImageViewASTCDecodeModeEXT {
	StructureType sType      = StructureType::ImageViewAstcDecodeModeEXT;
	const void *  pNext      = nullptr;
	Format        decodeMode = Format::Undefined;
};
struct ImageViewAddressPropertiesNVX {
	StructureType sType         = StructureType::ImageViewAddressPropertiesNVX;
	void *        pNext         = nullptr;
	DeviceAddress deviceAddress = 0;
	DeviceSize    size          = 0;
};
struct ImageViewCaptureDescriptorDataInfoEXT {
	StructureType                            sType     = StructureType::ImageViewCaptureDescriptorDataInfoEXT;
	const void *                             pNext     = nullptr;
	impl_Struct::AssignableHandle<ImageView> imageView;
};
struct ImageViewHandleInfoNVX {
	StructureType                            sType          = StructureType::ImageViewHandleInfoNVX;
	const void *                             pNext          = nullptr;
	impl_Struct::AssignableHandle<ImageView> imageView;
	DescriptorType                           descriptorType = DescriptorType::Sampler;
	impl_Struct::AssignableHandle<Sampler>   sampler;
};
struct ImageViewMinLodCreateInfoEXT {
	StructureType sType  = StructureType::ImageViewMinLodCreateInfoEXT;
	const void *  pNext  = nullptr;
	float         minLod = 0.0F;
};
struct ImageViewSlicedCreateInfoEXT {
	StructureType sType       = StructureType::ImageViewSlicedCreateInfoEXT;
	const void *  pNext       = nullptr;
	uint32_t      sliceOffset = 0;
	uint32_t      sliceCount  = 0;
};
struct ImageViewUsage2CreateInfoKHR {
	StructureType       sType = StructureType::ImageViewUsage2CreateInfoKHR;
	void *              pNext = nullptr;
	ImageUsageFlags2KHR usage = {};
};
struct ImageViewUsageCreateInfo {
	StructureType   sType = StructureType::ImageViewUsageCreateInfo;
	const void *    pNext = nullptr;
	ImageUsageFlags usage = {};
};
struct ImportFenceFdInfoKHR {
	StructureType                        sType      = StructureType::ImportFenceFdInfoKHR;
	const void *                         pNext      = nullptr;
	impl_Struct::AssignableHandle<Fence> fence;
	FenceImportFlags                     flags      = {};
	ExternalFenceHandleTypeBits          handleType = ExternalFenceHandleTypeBits::OpaqueFd;
	int                                  fd         = 0;
};
struct ImportMemoryFdInfoKHR {
	StructureType                sType      = StructureType::ImportMemoryFdInfoKHR;
	const void *                 pNext      = nullptr;
	ExternalMemoryHandleTypeBits handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
	int                          fd         = 0;
};
struct ImportMemoryHostPointerInfoEXT {
	StructureType                sType        = StructureType::ImportMemoryHostPointerInfoEXT;
	const void *                 pNext        = nullptr;
	ExternalMemoryHandleTypeBits handleType   = ExternalMemoryHandleTypeBits::OpaqueFd;
	void *                       pHostPointer = nullptr;
};
struct ImportSemaphoreFdInfoKHR {
	StructureType                            sType      = StructureType::ImportSemaphoreFdInfoKHR;
	const void *                             pNext      = nullptr;
	impl_Struct::AssignableHandle<Semaphore> semaphore;
	SemaphoreImportFlags                     flags      = {};
	ExternalSemaphoreHandleTypeBits          handleType = ExternalSemaphoreHandleTypeBits::OpaqueFd;
	int                                      fd         = 0;
};
struct IndirectCommandsExecutionSetTokenEXT {
	IndirectExecutionSetInfoTypeEXT type         = IndirectExecutionSetInfoTypeEXT::Pipelines;
	ShaderStageFlags                shaderStages = {};
};
struct IndirectCommandsIndexBufferTokenEXT {
	IndirectCommandsInputModeBitsEXT mode = IndirectCommandsInputModeBitsEXT::VulkanIndexBuffer;
};
struct IndirectCommandsLayoutPushDataTokenNV {
	StructureType sType          = StructureType::IndirectCommandsLayoutPushDataTokenNV;
	const void *  pNext          = nullptr;
	uint32_t      pushDataOffset = 0;
	uint32_t      pushDataSize   = 0;
};
struct IndirectCommandsLayoutTokenNV {
	StructureType                                 sType                        = StructureType::IndirectCommandsLayoutTokenNV;
	const void *                                  pNext                        = nullptr;
	IndirectCommandsTokenTypeNV                   tokenType                    = IndirectCommandsTokenTypeNV::ShaderGroup;
	uint32_t                                      stream                       = 0;
	uint32_t                                      offset                       = 0;
	uint32_t                                      vertexBindingUnit            = 0;
	Bool32                                        vertexDynamicStride          = Constants::False;
	impl_Struct::AssignableHandle<PipelineLayout> pushconstantPipelineLayout;
	ShaderStageFlags                              pushconstantShaderStageFlags = {};
	uint32_t                                      pushconstantOffset           = 0;
	uint32_t                                      pushconstantSize             = 0;
	IndirectStateFlagsNV                          indirectStateFlags           = {};
	uint32_t                                      indexTypeCount               = 0;
	const IndexType *                             pIndexTypes                  = nullptr;// len indexTypeCount
	const uint32_t *                              pIndexTypeValues             = nullptr;// len indexTypeCount
	auto indexTypes() -> impl_Struct::VecView<uint32_t, IndexType>;
};
struct IndirectCommandsStreamNV {
	impl_Struct::AssignableHandle<Buffer> buffer;
	DeviceSize                            offset = 0;
};
struct IndirectCommandsVertexBufferTokenEXT {
	uint32_t vertexBindingUnit = 0;
};
struct IndirectExecutionSetPipelineInfoEXT {
	StructureType                           sType            = StructureType::IndirectExecutionSetPipelineInfoEXT;
	const void *                            pNext            = nullptr;
	impl_Struct::AssignableHandle<Pipeline> initialPipeline;
	uint32_t                                maxPipelineCount = 0;
};
struct IndirectExecutionSetShaderLayoutInfoEXT {
	StructureType                                             sType          = StructureType::IndirectExecutionSetShaderLayoutInfoEXT;
	const void *                                              pNext          = nullptr;
	uint32_t                                                  setLayoutCount = 0;
	const impl_Struct::AssignableHandle<DescriptorSetLayout> *pSetLayouts    = nullptr;// len setLayoutCount
	auto setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>>;
};
struct InitializePerformanceApiInfoINTEL {
	StructureType sType     = StructureType::InitializePerformanceApiInfoINTEL;
	const void *  pNext     = nullptr;
	void *        pUserData = nullptr;
};
struct InputAttachmentAspectReference {
	uint32_t         subpass              = 0;
	uint32_t         inputAttachmentIndex = 0;
	ImageAspectFlags aspectMask           = {};
};
struct LatencySleepInfoNV {
	StructureType                            sType           = StructureType::LatencySleepInfoNV;
	const void *                             pNext           = nullptr;
	impl_Struct::AssignableHandle<Semaphore> signalSemaphore;
	uint64_t                                 value           = 0;
};
struct LatencySleepModeInfoNV {
	StructureType sType             = StructureType::LatencySleepModeInfoNV;
	const void *  pNext             = nullptr;
	Bool32        lowLatencyMode    = Constants::False;
	Bool32        lowLatencyBoost   = Constants::False;
	uint32_t      minimumIntervalUs = 0;
};
struct LatencySubmissionPresentIdNV {
	StructureType sType     = StructureType::LatencySubmissionPresentIdNV;
	const void *  pNext     = nullptr;
	uint64_t      presentID = 0;
};
struct LatencySurfaceCapabilitiesNV {
	StructureType   sType            = StructureType::LatencySurfaceCapabilitiesNV;
	const void *    pNext            = nullptr;
	uint32_t        presentModeCount = 0;
	PresentModeKHR *pPresentModes    = nullptr;// len presentModeCount
};
struct LatencyTimingsFrameReportNV {
	StructureType sType                    = StructureType::LatencyTimingsFrameReportNV;
	void *        pNext                    = nullptr;
	uint64_t      presentID                = 0;
	uint64_t      inputSampleTimeUs        = 0;
	uint64_t      simStartTimeUs           = 0;
	uint64_t      simEndTimeUs             = 0;
	uint64_t      renderSubmitStartTimeUs  = 0;
	uint64_t      renderSubmitEndTimeUs    = 0;
	uint64_t      presentStartTimeUs       = 0;
	uint64_t      presentEndTimeUs         = 0;
	uint64_t      driverStartTimeUs        = 0;
	uint64_t      driverEndTimeUs          = 0;
	uint64_t      osRenderQueueStartTimeUs = 0;
	uint64_t      osRenderQueueEndTimeUs   = 0;
	uint64_t      gpuRenderStartTimeUs     = 0;
	uint64_t      gpuRenderEndTimeUs       = 0;
};
struct LayerProperties {
	impl_Struct::FixedString<Constants::MaxExtensionNameSize> layerName             = {};// len null-terminated
	uint32_t                                                  specVersion           = 0;
	uint32_t                                                  implementationVersion = 0;
	impl_Struct::FixedString<Constants::MaxDescriptionSize>   description           = {};// len null-terminated
};
struct LayerSettingEXT {
	impl_Struct::InOutString layerName;
	impl_Struct::InOutString settingName;
	LayerSettingTypeEXT      type        = LayerSettingTypeEXT::Bool32;
	uint32_t                 valueCount  = 0;
	const void *             pValues     = nullptr;// len valueCount
};
struct MappedMemoryRange {
	StructureType                               sType  = StructureType::MappedMemoryRange;
	const void *                                pNext  = nullptr;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  offset = 0;
	DeviceSize                                  size   = 0;
};
struct MemoryAllocateFlagsInfo {
	StructureType       sType      = StructureType::MemoryAllocateFlagsInfo;
	const void *        pNext      = nullptr;
	MemoryAllocateFlags flags      = {};
	uint32_t            deviceMask = 0;
};
struct MemoryAllocateInfo {
	StructureType sType           = StructureType::MemoryAllocateInfo;
	const void *  pNext           = nullptr;
	DeviceSize    allocationSize  = 0;
	uint32_t      memoryTypeIndex = 0;
};
struct MemoryBarrier {
	StructureType sType         = StructureType::MemoryBarrier;
	const void *  pNext         = nullptr;
	AccessFlags   srcAccessMask = {};
	AccessFlags   dstAccessMask = {};
};
struct MemoryBarrier2 {
	StructureType       sType         = StructureType::MemoryBarrier2;
	const void *        pNext         = nullptr;
	PipelineStageFlags2 srcStageMask  = {};
	AccessFlags2        srcAccessMask = {};
	PipelineStageFlags2 dstStageMask  = {};
	AccessFlags2        dstAccessMask = {};
};
struct MemoryBarrierAccessFlags3KHR {
	StructureType   sType          = StructureType::MemoryBarrierAccessFlags3KHR;
	const void *    pNext          = nullptr;
	AccessFlags3KHR srcAccessMask3 = {};
	AccessFlags3KHR dstAccessMask3 = {};
};
struct MemoryDedicatedAllocateInfo {
	StructureType                         sType  = StructureType::MemoryDedicatedAllocateInfo;
	const void *                          pNext  = nullptr;
	impl_Struct::AssignableHandle<Image>  image;
	impl_Struct::AssignableHandle<Buffer> buffer;
};
struct MemoryDedicatedAllocateInfoTensorARM {
	StructureType                            sType  = StructureType::MemoryDedicatedAllocateInfoTensorARM;
	const void *                             pNext  = nullptr;
	impl_Struct::AssignableHandle<TensorARM> tensor;
};
struct MemoryDedicatedRequirements {
	StructureType sType                       = StructureType::MemoryDedicatedRequirements;
	void *        pNext                       = nullptr;
	Bool32        prefersDedicatedAllocation  = Constants::False;
	Bool32        requiresDedicatedAllocation = Constants::False;
};
struct MemoryFdPropertiesKHR {
	StructureType sType          = StructureType::MemoryFdPropertiesKHR;
	void *        pNext          = nullptr;
	uint32_t      memoryTypeBits = 0;
};
struct MemoryGetFdInfoKHR {
	StructureType                               sType      = StructureType::MemoryGetFdInfoKHR;
	const void *                                pNext      = nullptr;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	ExternalMemoryHandleTypeBits                handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
};
struct MemoryGetRemoteAddressInfoNV {
	StructureType                               sType      = StructureType::MemoryGetRemoteAddressInfoNV;
	const void *                                pNext      = nullptr;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	ExternalMemoryHandleTypeBits                handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
};
struct MemoryHeap {
	DeviceSize      size  = 0;
	MemoryHeapFlags flags = {};
};
struct MemoryHostPointerPropertiesEXT {
	StructureType sType          = StructureType::MemoryHostPointerPropertiesEXT;
	void *        pNext          = nullptr;
	uint32_t      memoryTypeBits = 0;
};
struct MemoryMapInfo {
	StructureType                               sType  = StructureType::MemoryMapInfo;
	const void *                                pNext  = nullptr;
	MemoryMapFlags                              flags  = {};
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  offset = 0;
	DeviceSize                                  size   = 0;
};
struct MemoryMapPlacedInfoEXT {
	StructureType sType          = StructureType::MemoryMapPlacedInfoEXT;
	const void *  pNext          = nullptr;
	void *        pPlacedAddress = nullptr;
};
struct MemoryOpaqueCaptureAddressAllocateInfo {
	StructureType sType                = StructureType::MemoryOpaqueCaptureAddressAllocateInfo;
	const void *  pNext                = nullptr;
	uint64_t      opaqueCaptureAddress = 0;
};
struct MemoryPriorityAllocateInfoEXT {
	StructureType sType    = StructureType::MemoryPriorityAllocateInfoEXT;
	const void *  pNext    = nullptr;
	float         priority = 0.0F;
};
struct MemoryRequirements {
	DeviceSize size           = 0;
	DeviceSize alignment      = 0;
	uint32_t   memoryTypeBits = 0;
};
struct MemoryType {
	MemoryPropertyFlags propertyFlags = {};
	uint32_t            heapIndex     = 0;
};
struct MemoryUnmapInfo {
	StructureType                               sType  = StructureType::MemoryUnmapInfo;
	const void *                                pNext  = nullptr;
	MemoryUnmapFlags                            flags  = {};
	impl_Struct::AssignableHandle<DeviceMemory> memory;
};
struct MicromapBuildSizesInfoEXT {
	StructureType sType            = StructureType::MicromapBuildSizesInfoEXT;
	const void *  pNext            = nullptr;
	DeviceSize    micromapSize     = 0;
	DeviceSize    buildScratchSize = 0;
	Bool32        discardable      = Constants::False;
};
struct MicromapCreateInfoEXT {
	StructureType                         sType         = StructureType::MicromapCreateInfoEXT;
	const void *                          pNext         = nullptr;
	MicromapCreateFlagsEXT                createFlags   = {};
	impl_Struct::AssignableHandle<Buffer> buffer;
	DeviceSize                            offset        = 0;
	DeviceSize                            size          = 0;
	MicromapTypeEXT                       type          = MicromapTypeEXT::OpacityMicromap;
	DeviceAddress                         deviceAddress = 0;
};
struct MicromapTriangleKHR {
	uint32_t dataOffset       = 0;
	uint16_t subdivisionLevel = 0;
	uint16_t format           = 0;
};
struct MicromapUsageEXT {
	uint32_t count            = 0;
	uint32_t subdivisionLevel = 0;
	uint32_t format           = 0;
};
struct MicromapUsageKHR {
	uint32_t                 count            = 0;
	uint32_t                 subdivisionLevel = 0;
	OpacityMicromapFormatKHR format           = OpacityMicromapFormatKHR::v2State;
};
struct MicromapVersionInfoEXT {
	StructureType  sType        = StructureType::MicromapVersionInfoEXT;
	const void *   pNext        = nullptr;
	const uint8_t *pVersionData = nullptr;
};
struct MultiDrawIndexedInfoEXT {
	uint32_t firstIndex   = 0;
	uint32_t indexCount   = 0;
	int32_t  vertexOffset = 0;
};
struct MultiDrawInfoEXT {
	uint32_t firstVertex = 0;
	uint32_t vertexCount = 0;
};
struct MultisampledRenderToSingleSampledInfoEXT {
	StructureType   sType                                   = StructureType::MultisampledRenderToSingleSampledInfoEXT;
	const void *    pNext                                   = nullptr;
	Bool32          multisampledRenderToSingleSampledEnable = Constants::False;
	SampleCountBits rasterizationSamples                    = SampleCountBits::v1;
};
struct MultiviewPerViewAttributesInfoNVX {
	StructureType sType                          = StructureType::MultiviewPerViewAttributesInfoNVX;
	const void *  pNext                          = nullptr;
	Bool32        perViewAttributes              = Constants::False;
	Bool32        perViewAttributesPositionXOnly = Constants::False;
};
struct MutableDescriptorTypeListEXT {
	uint32_t              descriptorTypeCount = 0;
	const DescriptorType *pDescriptorTypes    = nullptr;// len descriptorTypeCount
	auto descriptorTypes() -> impl_Struct::VecView<uint32_t, DescriptorType>;
};
struct Offset2D {
	int32_t x = 0;
	int32_t y = 0;
};
struct Offset3D {
	int32_t x = 0;
	int32_t y = 0;
	int32_t z = 0;
};
struct OpaqueCaptureDescriptorDataCreateInfoEXT {
	StructureType sType                       = StructureType::OpaqueCaptureDescriptorDataCreateInfoEXT;
	const void *  pNext                       = nullptr;
	const void *  opaqueCaptureDescriptorData = nullptr;
};
struct OpticalFlowImageFormatInfoNV {
	StructureType           sType = StructureType::OpticalFlowImageFormatInfoNV;
	const void *            pNext = nullptr;
	OpticalFlowUsageFlagsNV usage = {};
};
struct OpticalFlowImageFormatPropertiesNV {
	StructureType sType  = StructureType::OpticalFlowImageFormatPropertiesNV;
	void *        pNext  = nullptr;
	Format        format = Format::Undefined;
};
struct OpticalFlowSessionCreateInfoNV {
	StructureType                   sType            = StructureType::OpticalFlowSessionCreateInfoNV;
	void *                          pNext            = nullptr;
	uint32_t                        width            = 0;
	uint32_t                        height           = 0;
	Format                          imageFormat      = Format::Undefined;
	Format                          flowVectorFormat = Format::Undefined;
	Format                          costFormat       = Format::Undefined;
	OpticalFlowGridSizeFlagsNV      outputGridSize   = {};
	OpticalFlowGridSizeFlagsNV      hintGridSize     = {};
	OpticalFlowPerformanceLevelNV   performanceLevel = OpticalFlowPerformanceLevelNV::Unknown;
	OpticalFlowSessionCreateFlagsNV flags            = {};
};
struct OpticalFlowSessionCreatePrivateDataInfoNV {
	StructureType sType        = StructureType::OpticalFlowSessionCreatePrivateDataInfoNV;
	void *        pNext        = nullptr;
	uint32_t      id           = 0;
	uint32_t      size         = 0;
	const void *  pPrivateData = nullptr;
};
struct OutOfBandQueueTypeInfoNV {
	StructureType        sType     = StructureType::OutOfBandQueueTypeInfoNV;
	const void *         pNext     = nullptr;
	OutOfBandQueueTypeNV queueType = OutOfBandQueueTypeNV::Render;
};
struct PartitionedAccelerationStructureFlagsNV {
	StructureType sType                      = StructureType::PartitionedAccelerationStructureFlagsNV;
	void *        pNext                      = nullptr;
	Bool32        enablePartitionTranslation = Constants::False;
};
struct PartitionedAccelerationStructureInstancesInputNV {
	StructureType                      sType                             = StructureType::PartitionedAccelerationStructureInstancesInputNV;
	void *                             pNext                             = nullptr;
	BuildAccelerationStructureFlagsKHR flags                             = {};
	uint32_t                           instanceCount                     = 0;
	uint32_t                           maxInstancePerPartitionCount      = 0;
	uint32_t                           partitionCount                    = 0;
	uint32_t                           maxInstanceInGlobalPartitionCount = 0;
};
struct PartitionedAccelerationStructureUpdateInstanceDataNV {
	uint32_t      instanceIndex                       = 0;
	uint32_t      instanceContributionToHitGroupIndex = 0;
	DeviceAddress accelerationStructure               = 0;
};
struct PartitionedAccelerationStructureWritePartitionTranslationDataNV {
	uint32_t             partitionIndex       = 0;
	std::array<float, 3> partitionTranslation = {};
};
struct PastPresentationTimingGOOGLE {
	uint32_t presentID           = 0;
	uint64_t desiredPresentTime  = 0;
	uint64_t actualPresentTime   = 0;
	uint64_t earliestPresentTime = 0;
	uint64_t presentMargin       = 0;
};
struct PastPresentationTimingInfoEXT {
	StructureType                               sType     = StructureType::PastPresentationTimingInfoEXT;
	const void *                                pNext     = nullptr;
	PastPresentationTimingFlagsEXT              flags     = {};
	impl_Struct::AssignableHandle<SwapchainKHR> swapchain;
};
struct PerTileBeginInfoQCOM {
	StructureType sType = StructureType::PerTileBeginInfoQCOM;
	const void *  pNext = nullptr;
};
struct PerTileEndInfoQCOM {
	StructureType sType = StructureType::PerTileEndInfoQCOM;
	const void *  pNext = nullptr;
};
struct PerfHintInfoQCOM {
	StructureType    sType = StructureType::PerfHintInfoQCOM;
	void *           pNext = nullptr;
	PerfHintTypeQCOM type  = PerfHintTypeQCOM::Default;
	uint32_t         scale = 0;
};
struct PerformanceConfigurationAcquireInfoINTEL {
	StructureType                     sType = StructureType::PerformanceConfigurationAcquireInfoINTEL;
	const void *                      pNext = nullptr;
	PerformanceConfigurationTypeINTEL type  = PerformanceConfigurationTypeINTEL::CommandQueueMetricsDiscoveryActivated;
};
struct PerformanceCounterARM {
	StructureType sType     = StructureType::PerformanceCounterARM;
	void *        pNext     = nullptr;
	uint32_t      counterID = 0;
};
struct PerformanceCounterDescriptionARM {
	StructureType                                           sType = StructureType::PerformanceCounterDescriptionARM;
	void *                                                  pNext = nullptr;
	PerformanceCounterDescriptionFlagsARM                   flags = {};
	impl_Struct::FixedString<Constants::MaxDescriptionSize> name  = {};// len null-terminated
};
struct PerformanceCounterDescriptionKHR {
	StructureType                                           sType       = StructureType::PerformanceCounterDescriptionKHR;
	void *                                                  pNext       = nullptr;
	PerformanceCounterDescriptionFlagsKHR                   flags       = {};
	impl_Struct::FixedString<Constants::MaxDescriptionSize> name        = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDescriptionSize> category    = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description = {};// len null-terminated
};
struct PerformanceCounterKHR {
	StructureType                            sType   = StructureType::PerformanceCounterKHR;
	void *                                   pNext   = nullptr;
	PerformanceCounterUnitKHR                unit    = PerformanceCounterUnitKHR::Generic;
	PerformanceCounterScopeKHR               scope   = PerformanceCounterScopeKHR::CommandBuffer;
	PerformanceCounterStorageKHR             storage = PerformanceCounterStorageKHR::Int32;
	std::array<uint8_t, Constants::UuidSize> uuid    = {};
};
union PerformanceCounterResultKHR {
	int32_t  int32;
	int64_t  int64;
	uint32_t uint32;
	uint64_t uint64;
	float    float32;
	double   float64;
};
struct PerformanceMarkerInfoINTEL {
	StructureType sType  = StructureType::PerformanceMarkerInfoINTEL;
	const void *  pNext  = nullptr;
	uint64_t      marker = 0;
};
struct PerformanceOverrideInfoINTEL {
	StructureType                sType     = StructureType::PerformanceOverrideInfoINTEL;
	const void *                 pNext     = nullptr;
	PerformanceOverrideTypeINTEL type      = PerformanceOverrideTypeINTEL::NullHardware;
	Bool32                       enable    = Constants::False;
	uint64_t                     parameter = 0;
};
struct PerformanceQuerySubmitInfoKHR {
	StructureType sType            = StructureType::PerformanceQuerySubmitInfoKHR;
	const void *  pNext            = nullptr;
	uint32_t      counterPassIndex = 0;
};
struct PerformanceStreamMarkerInfoINTEL {
	StructureType sType  = StructureType::PerformanceStreamMarkerInfoINTEL;
	const void *  pNext  = nullptr;
	uint32_t      marker = 0;
};
union PerformanceValueDataINTEL {
	uint32_t                 value32;
	uint64_t                 value64;
	float                    valueFloat;
	Bool32                   valueBool;
	impl_Struct::InOutString valueString;
};
struct PhysicalDevice16BitStorageFeatures {
	StructureType sType                              = StructureType::PhysicalDevice16BitStorageFeatures;
	void *        pNext                              = nullptr;
	Bool32        storageBuffer16BitAccess           = Constants::False;
	Bool32        uniformAndStorageBuffer16BitAccess = Constants::False;
	Bool32        storagePushConstant16              = Constants::False;
	Bool32        storageInputOutput16               = Constants::False;
};
struct PhysicalDevice4444FormatsFeaturesEXT {
	StructureType sType          = StructureType::PhysicalDevice4444FormatsFeaturesEXT;
	void *        pNext          = nullptr;
	Bool32        formatA4R4G4B4 = Constants::False;
	Bool32        formatA4B4G4R4 = Constants::False;
};
struct PhysicalDevice8BitStorageFeatures {
	StructureType sType                             = StructureType::PhysicalDevice8BitStorageFeatures;
	void *        pNext                             = nullptr;
	Bool32        storageBuffer8BitAccess           = Constants::False;
	Bool32        uniformAndStorageBuffer8BitAccess = Constants::False;
	Bool32        storagePushConstant8              = Constants::False;
};
struct PhysicalDeviceASTCDecodeFeaturesEXT {
	StructureType sType                    = StructureType::PhysicalDeviceAstcDecodeFeaturesEXT;
	void *        pNext                    = nullptr;
	Bool32        decodeModeSharedExponent = Constants::False;
};
struct PhysicalDeviceAccelerationStructureFeaturesKHR {
	StructureType sType                                                 = StructureType::PhysicalDeviceAccelerationStructureFeaturesKHR;
	void *        pNext                                                 = nullptr;
	Bool32        accelerationStructure                                 = Constants::False;
	Bool32        accelerationStructureCaptureReplay                    = Constants::False;
	Bool32        accelerationStructureIndirectBuild                    = Constants::False;
	Bool32        accelerationStructureHostCommands                     = Constants::False;
	Bool32        descriptorBindingAccelerationStructureUpdateAfterBind = Constants::False;
};
struct PhysicalDeviceAccelerationStructurePropertiesKHR {
	StructureType sType                                                      = StructureType::PhysicalDeviceAccelerationStructurePropertiesKHR;
	void *        pNext                                                      = nullptr;
	uint64_t      maxGeometryCount                                           = 0;
	uint64_t      maxInstanceCount                                           = 0;
	uint64_t      maxPrimitiveCount                                          = 0;
	uint32_t      maxPerStageDescriptorAccelerationStructures                = 0;
	uint32_t      maxPerStageDescriptorUpdateAfterBindAccelerationStructures = 0;
	uint32_t      maxDescriptorSetAccelerationStructures                     = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindAccelerationStructures      = 0;
	uint32_t      minAccelerationStructureScratchOffsetAlignment             = 0;
};
struct PhysicalDeviceAddressBindingReportFeaturesEXT {
	StructureType sType                = StructureType::PhysicalDeviceAddressBindingReportFeaturesEXT;
	void *        pNext                = nullptr;
	Bool32        reportAddressBinding = Constants::False;
};
struct PhysicalDeviceAmigoProfilingFeaturesSEC {
	StructureType sType          = StructureType::PhysicalDeviceAmigoProfilingFeaturesSEC;
	void *        pNext          = nullptr;
	Bool32        amigoProfiling = Constants::False;
};
struct PhysicalDeviceAntiLagFeaturesAMD {
	StructureType sType   = StructureType::PhysicalDeviceAntiLagFeaturesAMD;
	void *        pNext   = nullptr;
	Bool32        antiLag = Constants::False;
};
struct PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT {
	StructureType sType                              = StructureType::PhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;
	void *        pNext                              = nullptr;
	Bool32        attachmentFeedbackLoopDynamicState = Constants::False;
};
struct PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT {
	StructureType sType                        = StructureType::PhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;
	void *        pNext                        = nullptr;
	Bool32        attachmentFeedbackLoopLayout = Constants::False;
};
struct PhysicalDeviceBlendOperationAdvancedFeaturesEXT {
	StructureType sType                           = StructureType::PhysicalDeviceBlendOperationAdvancedFeaturesEXT;
	void *        pNext                           = nullptr;
	Bool32        advancedBlendCoherentOperations = Constants::False;
};
struct PhysicalDeviceBlendOperationAdvancedPropertiesEXT {
	StructureType sType                                 = StructureType::PhysicalDeviceBlendOperationAdvancedPropertiesEXT;
	void *        pNext                                 = nullptr;
	uint32_t      advancedBlendMaxColorAttachments      = 0;
	Bool32        advancedBlendIndependentBlend         = Constants::False;
	Bool32        advancedBlendNonPremultipliedSrcColor = Constants::False;
	Bool32        advancedBlendNonPremultipliedDstColor = Constants::False;
	Bool32        advancedBlendCorrelatedOverlap        = Constants::False;
	Bool32        advancedBlendAllOperations            = Constants::False;
};
struct PhysicalDeviceBorderColorSwizzleFeaturesEXT {
	StructureType sType                       = StructureType::PhysicalDeviceBorderColorSwizzleFeaturesEXT;
	void *        pNext                       = nullptr;
	Bool32        borderColorSwizzle          = Constants::False;
	Bool32        borderColorSwizzleFromImage = Constants::False;
};
struct PhysicalDeviceBufferDeviceAddressFeatures {
	StructureType sType                            = StructureType::PhysicalDeviceBufferDeviceAddressFeatures;
	void *        pNext                            = nullptr;
	Bool32        bufferDeviceAddress              = Constants::False;
	Bool32        bufferDeviceAddressCaptureReplay = Constants::False;
	Bool32        bufferDeviceAddressMultiDevice   = Constants::False;
};
struct PhysicalDeviceBufferDeviceAddressFeaturesEXT {
	StructureType sType                            = StructureType::PhysicalDeviceBufferDeviceAddressFeaturesEXT;
	void *        pNext                            = nullptr;
	Bool32        bufferDeviceAddress              = Constants::False;
	Bool32        bufferDeviceAddressCaptureReplay = Constants::False;
	Bool32        bufferDeviceAddressMultiDevice   = Constants::False;
};
struct PhysicalDeviceClusterAccelerationStructureFeaturesNV {
	StructureType sType                        = StructureType::PhysicalDeviceClusterAccelerationStructureFeaturesNV;
	void *        pNext                        = nullptr;
	Bool32        clusterAccelerationStructure = Constants::False;
};
struct PhysicalDeviceClusterAccelerationStructurePropertiesNV {
	StructureType sType                              = StructureType::PhysicalDeviceClusterAccelerationStructurePropertiesNV;
	void *        pNext                              = nullptr;
	uint32_t      maxVerticesPerCluster              = 0;
	uint32_t      maxTrianglesPerCluster             = 0;
	uint32_t      clusterScratchByteAlignment        = 0;
	uint32_t      clusterByteAlignment               = 0;
	uint32_t      clusterTemplateByteAlignment       = 0;
	uint32_t      clusterBottomLevelByteAlignment    = 0;
	uint32_t      clusterTemplateBoundsByteAlignment = 0;
	uint32_t      maxClusterGeometryIndex            = 0;
};
struct PhysicalDeviceClusterCullingShaderFeaturesHUAWEI {
	StructureType sType                         = StructureType::PhysicalDeviceClusterCullingShaderFeaturesHUAWEI;
	void *        pNext                         = nullptr;
	Bool32        clustercullingShader          = Constants::False;
	Bool32        multiviewClusterCullingShader = Constants::False;
};
struct PhysicalDeviceClusterCullingShaderPropertiesHUAWEI {
	StructureType           sType                         = StructureType::PhysicalDeviceClusterCullingShaderPropertiesHUAWEI;
	void *                  pNext                         = nullptr;
	std::array<uint32_t, 3> maxWorkGroupCount             = {};
	std::array<uint32_t, 3> maxWorkGroupSize              = {};
	uint32_t                maxOutputClusterCount         = 0;
	DeviceSize              indirectBufferOffsetAlignment = 0;
};
struct PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI {
	StructureType sType              = StructureType::PhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI;
	void *        pNext              = nullptr;
	Bool32        clusterShadingRate = Constants::False;
};
struct PhysicalDeviceCoherentMemoryFeaturesAMD {
	StructureType sType                = StructureType::PhysicalDeviceCoherentMemoryFeaturesAMD;
	void *        pNext                = nullptr;
	Bool32        deviceCoherentMemory = Constants::False;
};
struct PhysicalDeviceColorWriteEnableFeaturesEXT {
	StructureType sType            = StructureType::PhysicalDeviceColorWriteEnableFeaturesEXT;
	void *        pNext            = nullptr;
	Bool32        colorWriteEnable = Constants::False;
};
struct PhysicalDeviceCommandBufferInheritanceFeaturesNV {
	StructureType sType                    = StructureType::PhysicalDeviceCommandBufferInheritanceFeaturesNV;
	void *        pNext                    = nullptr;
	Bool32        commandBufferInheritance = Constants::False;
};
struct PhysicalDeviceComputeOccupancyPriorityFeaturesNV {
	StructureType sType                    = StructureType::PhysicalDeviceComputeOccupancyPriorityFeaturesNV;
	void *        pNext                    = nullptr;
	Bool32        computeOccupancyPriority = Constants::False;
};
struct PhysicalDeviceComputeShaderDerivativesFeaturesKHR {
	StructureType sType                        = StructureType::PhysicalDeviceComputeShaderDerivativesFeaturesKHR;
	void *        pNext                        = nullptr;
	Bool32        computeDerivativeGroupQuads  = Constants::False;
	Bool32        computeDerivativeGroupLinear = Constants::False;
};
struct PhysicalDeviceComputeShaderDerivativesPropertiesKHR {
	StructureType sType                        = StructureType::PhysicalDeviceComputeShaderDerivativesPropertiesKHR;
	void *        pNext                        = nullptr;
	Bool32        meshAndTaskShaderDerivatives = Constants::False;
};
struct PhysicalDeviceConditionalRenderingFeaturesEXT {
	StructureType sType                         = StructureType::PhysicalDeviceConditionalRenderingFeaturesEXT;
	void *        pNext                         = nullptr;
	Bool32        conditionalRendering          = Constants::False;
	Bool32        inheritedConditionalRendering = Constants::False;
};
struct PhysicalDeviceConservativeRasterizationPropertiesEXT {
	StructureType sType                                       = StructureType::PhysicalDeviceConservativeRasterizationPropertiesEXT;
	void *        pNext                                       = nullptr;
	float         primitiveOverestimationSize                 = 0.0F;
	float         maxExtraPrimitiveOverestimationSize         = 0.0F;
	float         extraPrimitiveOverestimationSizeGranularity = 0.0F;
	Bool32        primitiveUnderestimation                    = Constants::False;
	Bool32        conservativePointAndLineRasterization       = Constants::False;
	Bool32        degenerateTrianglesRasterized               = Constants::False;
	Bool32        degenerateLinesRasterized                   = Constants::False;
	Bool32        fullyCoveredFragmentShaderInputVariable     = Constants::False;
	Bool32        conservativeRasterizationPostDepthCoverage  = Constants::False;
};
struct PhysicalDeviceCooperativeMatrix2FeaturesNV {
	StructureType sType                                 = StructureType::PhysicalDeviceCooperativeMatrix2FeaturesNV;
	void *        pNext                                 = nullptr;
	Bool32        cooperativeMatrixWorkgroupScope       = Constants::False;
	Bool32        cooperativeMatrixFlexibleDimensions   = Constants::False;
	Bool32        cooperativeMatrixReductions           = Constants::False;
	Bool32        cooperativeMatrixConversions          = Constants::False;
	Bool32        cooperativeMatrixPerElementOperations = Constants::False;
	Bool32        cooperativeMatrixTensorAddressing     = Constants::False;
	Bool32        cooperativeMatrixBlockLoads           = Constants::False;
};
struct PhysicalDeviceCooperativeMatrix2PropertiesNV {
	StructureType sType                                               = StructureType::PhysicalDeviceCooperativeMatrix2PropertiesNV;
	void *        pNext                                               = nullptr;
	uint32_t      cooperativeMatrixWorkgroupScopeMaxWorkgroupSize     = 0;
	uint32_t      cooperativeMatrixFlexibleDimensionsMaxDimension     = 0;
	uint32_t      cooperativeMatrixWorkgroupScopeReservedSharedMemory = 0;
};
struct PhysicalDeviceCooperativeMatrixConversionFeaturesQCOM {
	StructureType sType                       = StructureType::PhysicalDeviceCooperativeMatrixConversionFeaturesQCOM;
	void *        pNext                       = nullptr;
	Bool32        cooperativeMatrixConversion = Constants::False;
};
struct PhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV {
	StructureType sType                         = StructureType::PhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV;
	void *        pNext                         = nullptr;
	Bool32        cooperativeMatrixDecodeVector = Constants::False;
};
struct PhysicalDeviceCooperativeMatrixFeaturesKHR {
	StructureType sType                               = StructureType::PhysicalDeviceCooperativeMatrixFeaturesKHR;
	void *        pNext                               = nullptr;
	Bool32        cooperativeMatrix                   = Constants::False;
	Bool32        cooperativeMatrixRobustBufferAccess = Constants::False;
};
struct PhysicalDeviceCooperativeMatrixFeaturesNV {
	StructureType sType                               = StructureType::PhysicalDeviceCooperativeMatrixFeaturesNV;
	void *        pNext                               = nullptr;
	Bool32        cooperativeMatrix                   = Constants::False;
	Bool32        cooperativeMatrixRobustBufferAccess = Constants::False;
};
struct PhysicalDeviceCooperativeMatrixInfo2EXT {
	StructureType             sType        = StructureType::PhysicalDeviceCooperativeMatrixInfo2EXT;
	const void *              pNext        = nullptr;
	ScopeKHR                  scope        = ScopeKHR::Device;
	uint32_t                  invocations  = 0;
	uint32_t                  subgroupSize = 0;
	CooperativeMatrixFlagsEXT flags        = {};
};
struct PhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT {
	StructureType sType                                 = StructureType::PhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT;
	void *        pNext                                 = nullptr;
	Bool32        cooperativeMatrixProperties2          = Constants::False;
	Bool32        cooperativeMatrixReductions           = Constants::False;
	Bool32        cooperativeMatrixConversions          = Constants::False;
	Bool32        cooperativeMatrixPerElementOperations = Constants::False;
	Bool32        cooperativeMatrixGetCoordinate        = Constants::False;
};
struct PhysicalDeviceCooperativeMatrixPropertiesKHR {
	StructureType    sType                            = StructureType::PhysicalDeviceCooperativeMatrixPropertiesKHR;
	void *           pNext                            = nullptr;
	ShaderStageFlags cooperativeMatrixSupportedStages = {};
};
struct PhysicalDeviceCooperativeMatrixPropertiesNV {
	StructureType    sType                            = StructureType::PhysicalDeviceCooperativeMatrixPropertiesNV;
	void *           pNext                            = nullptr;
	ShaderStageFlags cooperativeMatrixSupportedStages = {};
};
struct PhysicalDeviceCooperativeVectorFeaturesNV {
	StructureType sType                     = StructureType::PhysicalDeviceCooperativeVectorFeaturesNV;
	void *        pNext                     = nullptr;
	Bool32        cooperativeVector         = Constants::False;
	Bool32        cooperativeVectorTraining = Constants::False;
};
struct PhysicalDeviceCooperativeVectorPropertiesNV {
	StructureType    sType                                        = StructureType::PhysicalDeviceCooperativeVectorPropertiesNV;
	void *           pNext                                        = nullptr;
	ShaderStageFlags cooperativeVectorSupportedStages             = {};
	Bool32           cooperativeVectorTrainingFloat16Accumulation = Constants::False;
	Bool32           cooperativeVectorTrainingFloat32Accumulation = Constants::False;
	uint32_t         maxCooperativeVectorComponents               = 0;
};
struct PhysicalDeviceCopyMemoryIndirectFeaturesKHR {
	StructureType sType                     = StructureType::PhysicalDeviceCopyMemoryIndirectFeaturesKHR;
	void *        pNext                     = nullptr;
	Bool32        indirectMemoryCopy        = Constants::False;
	Bool32        indirectMemoryToImageCopy = Constants::False;
};
struct PhysicalDeviceCopyMemoryIndirectFeaturesNV {
	StructureType sType        = StructureType::PhysicalDeviceCopyMemoryIndirectFeaturesNV;
	void *        pNext        = nullptr;
	Bool32        indirectCopy = Constants::False;
};
struct PhysicalDeviceCopyMemoryIndirectPropertiesKHR {
	StructureType sType           = StructureType::PhysicalDeviceCopyMemoryIndirectPropertiesKHR;
	void *        pNext           = nullptr;
	QueueFlags    supportedQueues = {};
};
struct PhysicalDeviceCornerSampledImageFeaturesNV {
	StructureType sType              = StructureType::PhysicalDeviceCornerSampledImageFeaturesNV;
	void *        pNext              = nullptr;
	Bool32        cornerSampledImage = Constants::False;
};
struct PhysicalDeviceCoverageReductionModeFeaturesNV {
	StructureType sType                 = StructureType::PhysicalDeviceCoverageReductionModeFeaturesNV;
	void *        pNext                 = nullptr;
	Bool32        coverageReductionMode = Constants::False;
};
struct PhysicalDeviceCubicClampFeaturesQCOM {
	StructureType sType           = StructureType::PhysicalDeviceCubicClampFeaturesQCOM;
	void *        pNext           = nullptr;
	Bool32        cubicRangeClamp = Constants::False;
};
struct PhysicalDeviceCubicWeightsFeaturesQCOM {
	StructureType sType                  = StructureType::PhysicalDeviceCubicWeightsFeaturesQCOM;
	void *        pNext                  = nullptr;
	Bool32        selectableCubicWeights = Constants::False;
};
struct PhysicalDeviceCustomBorderColorFeaturesEXT {
	StructureType sType                          = StructureType::PhysicalDeviceCustomBorderColorFeaturesEXT;
	void *        pNext                          = nullptr;
	Bool32        customBorderColors             = Constants::False;
	Bool32        customBorderColorWithoutFormat = Constants::False;
};
struct PhysicalDeviceCustomBorderColorPropertiesEXT {
	StructureType sType                        = StructureType::PhysicalDeviceCustomBorderColorPropertiesEXT;
	void *        pNext                        = nullptr;
	uint32_t      maxCustomBorderColorSamplers = 0;
};
struct PhysicalDeviceCustomResolveFeaturesEXT {
	StructureType sType         = StructureType::PhysicalDeviceCustomResolveFeaturesEXT;
	void *        pNext         = nullptr;
	Bool32        customResolve = Constants::False;
};
struct PhysicalDeviceDataGraphFeaturesARM {
	StructureType sType                            = StructureType::PhysicalDeviceDataGraphFeaturesARM;
	void *        pNext                            = nullptr;
	Bool32        dataGraph                        = Constants::False;
	Bool32        dataGraphUpdateAfterBind         = Constants::False;
	Bool32        dataGraphSpecializationConstants = Constants::False;
	Bool32        dataGraphDescriptorBuffer        = Constants::False;
	Bool32        dataGraphShaderModule            = Constants::False;
};
struct PhysicalDeviceDataGraphModelFeaturesQCOM {
	StructureType sType          = StructureType::PhysicalDeviceDataGraphModelFeaturesQCOM;
	void *        pNext          = nullptr;
	Bool32        dataGraphModel = Constants::False;
};
struct PhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM {
	StructureType sType                                = StructureType::PhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM;
	void *        pNext                                = nullptr;
	Bool32        dataGraphNeuralAcceleratorStatistics = Constants::False;
};
struct PhysicalDeviceDataGraphOperationSupportARM {
	PhysicalDeviceDataGraphOperationTypeARM                                                operationType = PhysicalDeviceDataGraphOperationTypeARM::SpirvExtendedInstructionSet;
	impl_Struct::FixedString<Constants::MaxPhysicalDeviceDataGraphOperationSetNameSizeARM> name          = {};// len null-terminated
	uint32_t                                                                               version       = 0;
};
struct PhysicalDeviceDataGraphOpticalFlowFeaturesARM {
	StructureType sType                = StructureType::PhysicalDeviceDataGraphOpticalFlowFeaturesARM;
	void *        pNext                = nullptr;
	Bool32        dataGraphOpticalFlow = Constants::False;
};
struct PhysicalDeviceDataGraphProcessingEngineARM {
	PhysicalDeviceDataGraphProcessingEngineTypeARM type      = PhysicalDeviceDataGraphProcessingEngineTypeARM::Default;
	Bool32                                         isForeign = Constants::False;
};
struct PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV {
	StructureType sType                            = StructureType::PhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
	void *        pNext                            = nullptr;
	Bool32        dedicatedAllocationImageAliasing = Constants::False;
};
struct PhysicalDeviceDepthBiasControlFeaturesEXT {
	StructureType sType                                           = StructureType::PhysicalDeviceDepthBiasControlFeaturesEXT;
	void *        pNext                                           = nullptr;
	Bool32        depthBiasControl                                = Constants::False;
	Bool32        leastRepresentableValueForceUnormRepresentation = Constants::False;
	Bool32        floatRepresentation                             = Constants::False;
	Bool32        depthBiasExact                                  = Constants::False;
};
struct PhysicalDeviceDepthClampControlFeaturesEXT {
	StructureType sType             = StructureType::PhysicalDeviceDepthClampControlFeaturesEXT;
	void *        pNext             = nullptr;
	Bool32        depthClampControl = Constants::False;
};
struct PhysicalDeviceDepthClampZeroOneFeaturesKHR {
	StructureType sType             = StructureType::PhysicalDeviceDepthClampZeroOneFeaturesKHR;
	void *        pNext             = nullptr;
	Bool32        depthClampZeroOne = Constants::False;
};
struct PhysicalDeviceDepthClipControlFeaturesEXT {
	StructureType sType            = StructureType::PhysicalDeviceDepthClipControlFeaturesEXT;
	void *        pNext            = nullptr;
	Bool32        depthClipControl = Constants::False;
};
struct PhysicalDeviceDepthClipEnableFeaturesEXT {
	StructureType sType           = StructureType::PhysicalDeviceDepthClipEnableFeaturesEXT;
	void *        pNext           = nullptr;
	Bool32        depthClipEnable = Constants::False;
};
struct PhysicalDeviceDepthStencilResolveProperties {
	StructureType    sType                        = StructureType::PhysicalDeviceDepthStencilResolveProperties;
	void *           pNext                        = nullptr;
	ResolveModeFlags supportedDepthResolveModes   = {};
	ResolveModeFlags supportedStencilResolveModes = {};
	Bool32           independentResolveNone       = Constants::False;
	Bool32           independentResolve           = Constants::False;
};
struct PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT {
	StructureType sType                                        = StructureType::PhysicalDeviceDescriptorBufferDensityMapPropertiesEXT;
	void *        pNext                                        = nullptr;
	size_t        combinedImageSamplerDensityMapDescriptorSize = 0;
};
struct PhysicalDeviceDescriptorBufferFeaturesEXT {
	StructureType sType                              = StructureType::PhysicalDeviceDescriptorBufferFeaturesEXT;
	void *        pNext                              = nullptr;
	Bool32        descriptorBuffer                   = Constants::False;
	Bool32        descriptorBufferCaptureReplay      = Constants::False;
	Bool32        descriptorBufferImageLayoutIgnored = Constants::False;
	Bool32        descriptorBufferPushDescriptors    = Constants::False;
};
struct PhysicalDeviceDescriptorBufferPropertiesEXT {
	StructureType sType                                                = StructureType::PhysicalDeviceDescriptorBufferPropertiesEXT;
	void *        pNext                                                = nullptr;
	Bool32        combinedImageSamplerDescriptorSingleArray            = Constants::False;
	Bool32        bufferlessPushDescriptors                            = Constants::False;
	Bool32        allowSamplerImageViewPostSubmitCreation              = Constants::False;
	DeviceSize    descriptorBufferOffsetAlignment                      = 0;
	uint32_t      maxDescriptorBufferBindings                          = 0;
	uint32_t      maxResourceDescriptorBufferBindings                  = 0;
	uint32_t      maxSamplerDescriptorBufferBindings                   = 0;
	uint32_t      maxEmbeddedImmutableSamplerBindings                  = 0;
	uint32_t      maxEmbeddedImmutableSamplers                         = 0;
	size_t        bufferCaptureReplayDescriptorDataSize                = 0;
	size_t        imageCaptureReplayDescriptorDataSize                 = 0;
	size_t        imageViewCaptureReplayDescriptorDataSize             = 0;
	size_t        samplerCaptureReplayDescriptorDataSize               = 0;
	size_t        accelerationStructureCaptureReplayDescriptorDataSize = 0;
	size_t        samplerDescriptorSize                                = 0;
	size_t        combinedImageSamplerDescriptorSize                   = 0;
	size_t        sampledImageDescriptorSize                           = 0;
	size_t        storageImageDescriptorSize                           = 0;
	size_t        uniformTexelBufferDescriptorSize                     = 0;
	size_t        robustUniformTexelBufferDescriptorSize               = 0;
	size_t        storageTexelBufferDescriptorSize                     = 0;
	size_t        robustStorageTexelBufferDescriptorSize               = 0;
	size_t        uniformBufferDescriptorSize                          = 0;
	size_t        robustUniformBufferDescriptorSize                    = 0;
	size_t        storageBufferDescriptorSize                          = 0;
	size_t        robustStorageBufferDescriptorSize                    = 0;
	size_t        inputAttachmentDescriptorSize                        = 0;
	size_t        accelerationStructureDescriptorSize                  = 0;
	DeviceSize    maxSamplerDescriptorBufferRange                      = 0;
	DeviceSize    maxResourceDescriptorBufferRange                     = 0;
	DeviceSize    samplerDescriptorBufferAddressSpaceSize              = 0;
	DeviceSize    resourceDescriptorBufferAddressSpaceSize             = 0;
	DeviceSize    descriptorBufferAddressSpaceSize                     = 0;
};
struct PhysicalDeviceDescriptorBufferTensorFeaturesARM {
	StructureType sType                             = StructureType::PhysicalDeviceDescriptorBufferTensorFeaturesARM;
	void *        pNext                             = nullptr;
	Bool32        descriptorBufferTensorDescriptors = Constants::False;
};
struct PhysicalDeviceDescriptorBufferTensorPropertiesARM {
	StructureType sType                                     = StructureType::PhysicalDeviceDescriptorBufferTensorPropertiesARM;
	void *        pNext                                     = nullptr;
	size_t        tensorCaptureReplayDescriptorDataSize     = 0;
	size_t        tensorViewCaptureReplayDescriptorDataSize = 0;
	size_t        tensorDescriptorSize                      = 0;
};
struct PhysicalDeviceDescriptorHeapFeaturesEXT {
	StructureType sType                       = StructureType::PhysicalDeviceDescriptorHeapFeaturesEXT;
	void *        pNext                       = nullptr;
	Bool32        descriptorHeap              = Constants::False;
	Bool32        descriptorHeapCaptureReplay = Constants::False;
};
struct PhysicalDeviceDescriptorHeapPropertiesEXT {
	StructureType sType                                   = StructureType::PhysicalDeviceDescriptorHeapPropertiesEXT;
	void *        pNext                                   = nullptr;
	DeviceSize    samplerHeapAlignment                    = 0;
	DeviceSize    resourceHeapAlignment                   = 0;
	DeviceSize    maxSamplerHeapSize                      = 0;
	DeviceSize    maxResourceHeapSize                     = 0;
	DeviceSize    minSamplerHeapReservedRange             = 0;
	DeviceSize    minSamplerHeapReservedRangeWithEmbedded = 0;
	DeviceSize    minResourceHeapReservedRange            = 0;
	DeviceSize    samplerDescriptorSize                   = 0;
	DeviceSize    imageDescriptorSize                     = 0;
	DeviceSize    bufferDescriptorSize                    = 0;
	DeviceSize    samplerDescriptorAlignment              = 0;
	DeviceSize    imageDescriptorAlignment                = 0;
	DeviceSize    bufferDescriptorAlignment               = 0;
	DeviceSize    maxPushDataSize                         = 0;
	size_t        imageCaptureReplayOpaqueDataSize        = 0;
	uint32_t      maxDescriptorHeapEmbeddedSamplers       = 0;
	uint32_t      samplerYcbcrConversionCount             = 0;
	Bool32        sparseDescriptorHeaps                   = Constants::False;
	Bool32        protectedDescriptorHeaps                = Constants::False;
};
struct PhysicalDeviceDescriptorHeapTensorPropertiesARM {
	StructureType sType                             = StructureType::PhysicalDeviceDescriptorHeapTensorPropertiesARM;
	void *        pNext                             = nullptr;
	DeviceSize    tensorDescriptorSize              = 0;
	DeviceSize    tensorDescriptorAlignment         = 0;
	size_t        tensorCaptureReplayOpaqueDataSize = 0;
};
struct PhysicalDeviceDescriptorIndexingFeatures {
	StructureType sType                                              = StructureType::PhysicalDeviceDescriptorIndexingFeatures;
	void *        pNext                                              = nullptr;
	Bool32        shaderInputAttachmentArrayDynamicIndexing          = Constants::False;
	Bool32        shaderUniformTexelBufferArrayDynamicIndexing       = Constants::False;
	Bool32        shaderStorageTexelBufferArrayDynamicIndexing       = Constants::False;
	Bool32        shaderUniformBufferArrayNonUniformIndexing         = Constants::False;
	Bool32        shaderSampledImageArrayNonUniformIndexing          = Constants::False;
	Bool32        shaderStorageBufferArrayNonUniformIndexing         = Constants::False;
	Bool32        shaderStorageImageArrayNonUniformIndexing          = Constants::False;
	Bool32        shaderInputAttachmentArrayNonUniformIndexing       = Constants::False;
	Bool32        shaderUniformTexelBufferArrayNonUniformIndexing    = Constants::False;
	Bool32        shaderStorageTexelBufferArrayNonUniformIndexing    = Constants::False;
	Bool32        descriptorBindingUniformBufferUpdateAfterBind      = Constants::False;
	Bool32        descriptorBindingSampledImageUpdateAfterBind       = Constants::False;
	Bool32        descriptorBindingStorageImageUpdateAfterBind       = Constants::False;
	Bool32        descriptorBindingStorageBufferUpdateAfterBind      = Constants::False;
	Bool32        descriptorBindingUniformTexelBufferUpdateAfterBind = Constants::False;
	Bool32        descriptorBindingStorageTexelBufferUpdateAfterBind = Constants::False;
	Bool32        descriptorBindingUpdateUnusedWhilePending          = Constants::False;
	Bool32        descriptorBindingPartiallyBound                    = Constants::False;
	Bool32        descriptorBindingVariableDescriptorCount           = Constants::False;
	Bool32        runtimeDescriptorArray                             = Constants::False;
};
struct PhysicalDeviceDescriptorIndexingProperties {
	StructureType sType                                                = StructureType::PhysicalDeviceDescriptorIndexingProperties;
	void *        pNext                                                = nullptr;
	uint32_t      maxUpdateAfterBindDescriptorsInAllPools              = 0;
	Bool32        shaderUniformBufferArrayNonUniformIndexingNative     = Constants::False;
	Bool32        shaderSampledImageArrayNonUniformIndexingNative      = Constants::False;
	Bool32        shaderStorageBufferArrayNonUniformIndexingNative     = Constants::False;
	Bool32        shaderStorageImageArrayNonUniformIndexingNative      = Constants::False;
	Bool32        shaderInputAttachmentArrayNonUniformIndexingNative   = Constants::False;
	Bool32        robustBufferAccessUpdateAfterBind                    = Constants::False;
	Bool32        quadDivergentImplicitLod                             = Constants::False;
	uint32_t      maxPerStageDescriptorUpdateAfterBindSamplers         = 0;
	uint32_t      maxPerStageDescriptorUpdateAfterBindUniformBuffers   = 0;
	uint32_t      maxPerStageDescriptorUpdateAfterBindStorageBuffers   = 0;
	uint32_t      maxPerStageDescriptorUpdateAfterBindSampledImages    = 0;
	uint32_t      maxPerStageDescriptorUpdateAfterBindStorageImages    = 0;
	uint32_t      maxPerStageDescriptorUpdateAfterBindInputAttachments = 0;
	uint32_t      maxPerStageUpdateAfterBindResources                  = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindSamplers              = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindUniformBuffers        = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindStorageBuffers        = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindSampledImages         = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindStorageImages         = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindInputAttachments      = 0;
};
struct PhysicalDeviceDescriptorPoolOverallocationFeaturesNV {
	StructureType sType                        = StructureType::PhysicalDeviceDescriptorPoolOverallocationFeaturesNV;
	void *        pNext                        = nullptr;
	Bool32        descriptorPoolOverallocation = Constants::False;
};
struct PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE {
	StructureType sType                    = StructureType::PhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;
	void *        pNext                    = nullptr;
	Bool32        descriptorSetHostMapping = Constants::False;
};
struct PhysicalDeviceDeviceAddressCommandsFeaturesKHR {
	StructureType sType                 = StructureType::PhysicalDeviceDeviceAddressCommandsFeaturesKHR;
	void *        pNext                 = nullptr;
	Bool32        deviceAddressCommands = Constants::False;
};
struct PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV {
	StructureType sType                               = StructureType::PhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;
	void *        pNext                               = nullptr;
	Bool32        deviceGeneratedCompute              = Constants::False;
	Bool32        deviceGeneratedComputePipelines     = Constants::False;
	Bool32        deviceGeneratedComputeCaptureReplay = Constants::False;
};
struct PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT {
	StructureType sType                          = StructureType::PhysicalDeviceDeviceGeneratedCommandsFeaturesEXT;
	void *        pNext                          = nullptr;
	Bool32        deviceGeneratedCommands        = Constants::False;
	Bool32        dynamicGeneratedPipelineLayout = Constants::False;
};
struct PhysicalDeviceDeviceGeneratedCommandsFeaturesNV {
	StructureType sType                   = StructureType::PhysicalDeviceDeviceGeneratedCommandsFeaturesNV;
	void *        pNext                   = nullptr;
	Bool32        deviceGeneratedCommands = Constants::False;
};
struct PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT {
	StructureType                     sType                                                = StructureType::PhysicalDeviceDeviceGeneratedCommandsPropertiesEXT;
	void *                            pNext                                                = nullptr;
	uint32_t                          maxIndirectPipelineCount                             = 0;
	uint32_t                          maxIndirectShaderObjectCount                         = 0;
	uint32_t                          maxIndirectSequenceCount                             = 0;
	uint32_t                          maxIndirectCommandsTokenCount                        = 0;
	uint32_t                          maxIndirectCommandsTokenOffset                       = 0;
	uint32_t                          maxIndirectCommandsIndirectStride                    = 0;
	IndirectCommandsInputModeFlagsEXT supportedIndirectCommandsInputModes                  = {};
	ShaderStageFlags                  supportedIndirectCommandsShaderStages                = {};
	ShaderStageFlags                  supportedIndirectCommandsShaderStagesPipelineBinding = {};
	ShaderStageFlags                  supportedIndirectCommandsShaderStagesShaderBinding   = {};
	Bool32                            deviceGeneratedCommandsTransformFeedback             = Constants::False;
	Bool32                            deviceGeneratedCommandsMultiDrawIndirectCount        = Constants::False;
};
struct PhysicalDeviceDeviceGeneratedCommandsPropertiesNV {
	StructureType sType                                    = StructureType::PhysicalDeviceDeviceGeneratedCommandsPropertiesNV;
	void *        pNext                                    = nullptr;
	uint32_t      maxGraphicsShaderGroupCount              = 0;
	uint32_t      maxIndirectSequenceCount                 = 0;
	uint32_t      maxIndirectCommandsTokenCount            = 0;
	uint32_t      maxIndirectCommandsStreamCount           = 0;
	uint32_t      maxIndirectCommandsTokenOffset           = 0;
	uint32_t      maxIndirectCommandsStreamStride          = 0;
	uint32_t      minSequencesCountBufferOffsetAlignment   = 0;
	uint32_t      minSequencesIndexBufferOffsetAlignment   = 0;
	uint32_t      minIndirectCommandsBufferOffsetAlignment = 0;
};
struct PhysicalDeviceDeviceMemoryReportFeaturesEXT {
	StructureType sType              = StructureType::PhysicalDeviceDeviceMemoryReportFeaturesEXT;
	void *        pNext              = nullptr;
	Bool32        deviceMemoryReport = Constants::False;
};
struct PhysicalDeviceDiagnosticsConfigFeaturesNV {
	StructureType sType             = StructureType::PhysicalDeviceDiagnosticsConfigFeaturesNV;
	void *        pNext             = nullptr;
	Bool32        diagnosticsConfig = Constants::False;
};
struct PhysicalDeviceDiscardRectanglePropertiesEXT {
	StructureType sType                = StructureType::PhysicalDeviceDiscardRectanglePropertiesEXT;
	void *        pNext                = nullptr;
	uint32_t      maxDiscardRectangles = 0;
};
struct PhysicalDeviceDrmPropertiesEXT {
	StructureType sType        = StructureType::PhysicalDeviceDrmPropertiesEXT;
	void *        pNext        = nullptr;
	Bool32        hasPrimary   = Constants::False;
	Bool32        hasRender    = Constants::False;
	int64_t       primaryMajor = 0;
	int64_t       primaryMinor = 0;
	int64_t       renderMajor  = 0;
	int64_t       renderMinor  = 0;
};
struct PhysicalDeviceDynamicRenderingFeatures {
	StructureType sType            = StructureType::PhysicalDeviceDynamicRenderingFeatures;
	void *        pNext            = nullptr;
	Bool32        dynamicRendering = Constants::False;
};
struct PhysicalDeviceDynamicRenderingLocalReadFeatures {
	StructureType sType                     = StructureType::PhysicalDeviceDynamicRenderingLocalReadFeatures;
	void *        pNext                     = nullptr;
	Bool32        dynamicRenderingLocalRead = Constants::False;
};
struct PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT {
	StructureType sType                             = StructureType::PhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;
	void *        pNext                             = nullptr;
	Bool32        dynamicRenderingUnusedAttachments = Constants::False;
};
struct PhysicalDeviceElapsedTimerQueryFeaturesQCOM {
	StructureType sType             = StructureType::PhysicalDeviceElapsedTimerQueryFeaturesQCOM;
	void *        pNext             = nullptr;
	Bool32        elapsedTimerQuery = Constants::False;
};
struct PhysicalDeviceExclusiveScissorFeaturesNV {
	StructureType sType            = StructureType::PhysicalDeviceExclusiveScissorFeaturesNV;
	void *        pNext            = nullptr;
	Bool32        exclusiveScissor = Constants::False;
};
struct PhysicalDeviceExtendedDynamicState2FeaturesEXT {
	StructureType sType                                   = StructureType::PhysicalDeviceExtendedDynamicState2FeaturesEXT;
	void *        pNext                                   = nullptr;
	Bool32        extendedDynamicState2                   = Constants::False;
	Bool32        extendedDynamicState2LogicOp            = Constants::False;
	Bool32        extendedDynamicState2PatchControlPoints = Constants::False;
};
struct PhysicalDeviceExtendedDynamicState3FeaturesEXT {
	StructureType sType                                                 = StructureType::PhysicalDeviceExtendedDynamicState3FeaturesEXT;
	void *        pNext                                                 = nullptr;
	Bool32        extendedDynamicState3TessellationDomainOrigin         = Constants::False;
	Bool32        extendedDynamicState3DepthClampEnable                 = Constants::False;
	Bool32        extendedDynamicState3PolygonMode                      = Constants::False;
	Bool32        extendedDynamicState3RasterizationSamples             = Constants::False;
	Bool32        extendedDynamicState3SampleMask                       = Constants::False;
	Bool32        extendedDynamicState3AlphaToCoverageEnable            = Constants::False;
	Bool32        extendedDynamicState3AlphaToOneEnable                 = Constants::False;
	Bool32        extendedDynamicState3LogicOpEnable                    = Constants::False;
	Bool32        extendedDynamicState3ColorBlendEnable                 = Constants::False;
	Bool32        extendedDynamicState3ColorBlendEquation               = Constants::False;
	Bool32        extendedDynamicState3ColorWriteMask                   = Constants::False;
	Bool32        extendedDynamicState3RasterizationStream              = Constants::False;
	Bool32        extendedDynamicState3ConservativeRasterizationMode    = Constants::False;
	Bool32        extendedDynamicState3ExtraPrimitiveOverestimationSize = Constants::False;
	Bool32        extendedDynamicState3DepthClipEnable                  = Constants::False;
	Bool32        extendedDynamicState3SampleLocationsEnable            = Constants::False;
	Bool32        extendedDynamicState3ColorBlendAdvanced               = Constants::False;
	Bool32        extendedDynamicState3ProvokingVertexMode              = Constants::False;
	Bool32        extendedDynamicState3LineRasterizationMode            = Constants::False;
	Bool32        extendedDynamicState3LineStippleEnable                = Constants::False;
	Bool32        extendedDynamicState3DepthClipNegativeOneToOne        = Constants::False;
	Bool32        extendedDynamicState3ViewportWScalingEnable           = Constants::False;
	Bool32        extendedDynamicState3ViewportSwizzle                  = Constants::False;
	Bool32        extendedDynamicState3CoverageToColorEnable            = Constants::False;
	Bool32        extendedDynamicState3CoverageToColorLocation          = Constants::False;
	Bool32        extendedDynamicState3CoverageModulationMode           = Constants::False;
	Bool32        extendedDynamicState3CoverageModulationTableEnable    = Constants::False;
	Bool32        extendedDynamicState3CoverageModulationTable          = Constants::False;
	Bool32        extendedDynamicState3CoverageReductionMode            = Constants::False;
	Bool32        extendedDynamicState3RepresentativeFragmentTestEnable = Constants::False;
	Bool32        extendedDynamicState3ShadingRateImageEnable           = Constants::False;
};
struct PhysicalDeviceExtendedDynamicState3PropertiesEXT {
	StructureType sType                                = StructureType::PhysicalDeviceExtendedDynamicState3PropertiesEXT;
	void *        pNext                                = nullptr;
	Bool32        dynamicPrimitiveTopologyUnrestricted = Constants::False;
};
struct PhysicalDeviceExtendedDynamicStateFeaturesEXT {
	StructureType sType                = StructureType::PhysicalDeviceExtendedDynamicStateFeaturesEXT;
	void *        pNext                = nullptr;
	Bool32        extendedDynamicState = Constants::False;
};
struct PhysicalDeviceExtendedFlagsFeaturesKHR {
	StructureType sType         = StructureType::PhysicalDeviceExtendedFlagsFeaturesKHR;
	void *        pNext         = nullptr;
	Bool32        extendedFlags = Constants::False;
};
struct PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV {
	StructureType sType                      = StructureType::PhysicalDeviceExtendedSparseAddressSpaceFeaturesNV;
	void *        pNext                      = nullptr;
	Bool32        extendedSparseAddressSpace = Constants::False;
};
struct PhysicalDeviceExtendedSparseAddressSpacePropertiesNV {
	StructureType    sType                          = StructureType::PhysicalDeviceExtendedSparseAddressSpacePropertiesNV;
	void *           pNext                          = nullptr;
	DeviceSize       extendedSparseAddressSpaceSize = 0;
	ImageUsageFlags  extendedSparseImageUsageFlags  = {};
	BufferUsageFlags extendedSparseBufferUsageFlags = {};
};
struct PhysicalDeviceExternalBufferInfo {
	StructureType                sType      = StructureType::PhysicalDeviceExternalBufferInfo;
	const void *                 pNext      = nullptr;
	BufferCreateFlags            flags      = {};
	BufferUsageFlags             usage      = {};
	ExternalMemoryHandleTypeBits handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
};
struct PhysicalDeviceExternalComputeQueuePropertiesNV {
	StructureType sType             = StructureType::PhysicalDeviceExternalComputeQueuePropertiesNV;
	void *        pNext             = nullptr;
	uint32_t      externalDataSize  = 0;
	uint32_t      maxExternalQueues = 0;
};
struct PhysicalDeviceExternalFenceInfo {
	StructureType               sType      = StructureType::PhysicalDeviceExternalFenceInfo;
	const void *                pNext      = nullptr;
	ExternalFenceHandleTypeBits handleType = ExternalFenceHandleTypeBits::OpaqueFd;
};
struct PhysicalDeviceExternalImageFormatInfo {
	StructureType                sType      = StructureType::PhysicalDeviceExternalImageFormatInfo;
	const void *                 pNext      = nullptr;
	ExternalMemoryHandleTypeBits handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
};
struct PhysicalDeviceExternalMemoryHostPropertiesEXT {
	StructureType sType                           = StructureType::PhysicalDeviceExternalMemoryHostPropertiesEXT;
	void *        pNext                           = nullptr;
	DeviceSize    minImportedHostPointerAlignment = 0;
};
struct PhysicalDeviceExternalMemoryRDMAFeaturesNV {
	StructureType sType              = StructureType::PhysicalDeviceExternalMemoryRdmaFeaturesNV;
	void *        pNext              = nullptr;
	Bool32        externalMemoryRDMA = Constants::False;
};
struct PhysicalDeviceExternalSemaphoreInfo {
	StructureType                   sType      = StructureType::PhysicalDeviceExternalSemaphoreInfo;
	const void *                    pNext      = nullptr;
	ExternalSemaphoreHandleTypeBits handleType = ExternalSemaphoreHandleTypeBits::OpaqueFd;
};
struct PhysicalDeviceFaultFeaturesEXT {
	StructureType sType                   = StructureType::PhysicalDeviceFaultFeaturesEXT;
	void *        pNext                   = nullptr;
	Bool32        deviceFault             = Constants::False;
	Bool32        deviceFaultVendorBinary = Constants::False;
};
struct PhysicalDeviceFaultFeaturesKHR {
	StructureType sType                         = StructureType::PhysicalDeviceFaultFeaturesKHR;
	void *        pNext                         = nullptr;
	Bool32        deviceFault                   = Constants::False;
	Bool32        deviceFaultVendorBinary       = Constants::False;
	Bool32        deviceFaultReportMasked       = Constants::False;
	Bool32        deviceFaultDeviceLostOnMasked = Constants::False;
};
struct PhysicalDeviceFaultPropertiesKHR {
	StructureType sType               = StructureType::PhysicalDeviceFaultPropertiesKHR;
	void *        pNext               = nullptr;
	uint32_t      maxDeviceFaultCount = 0;
};
struct PhysicalDeviceFeatures {
	Bool32 robustBufferAccess                      = Constants::False;
	Bool32 fullDrawIndexUint32                     = Constants::False;
	Bool32 imageCubeArray                          = Constants::False;
	Bool32 independentBlend                        = Constants::False;
	Bool32 geometryShader                          = Constants::False;
	Bool32 tessellationShader                      = Constants::False;
	Bool32 sampleRateShading                       = Constants::False;
	Bool32 dualSrcBlend                            = Constants::False;
	Bool32 logicOp                                 = Constants::False;
	Bool32 multiDrawIndirect                       = Constants::False;
	Bool32 drawIndirectFirstInstance               = Constants::False;
	Bool32 depthClamp                              = Constants::False;
	Bool32 depthBiasClamp                          = Constants::False;
	Bool32 fillModeNonSolid                        = Constants::False;
	Bool32 depthBounds                             = Constants::False;
	Bool32 wideLines                               = Constants::False;
	Bool32 largePoints                             = Constants::False;
	Bool32 alphaToOne                              = Constants::False;
	Bool32 multiViewport                           = Constants::False;
	Bool32 samplerAnisotropy                       = Constants::False;
	Bool32 textureCompressionETC2                  = Constants::False;
	Bool32 textureCompressionASTC_LDR              = Constants::False;
	Bool32 textureCompressionBC                    = Constants::False;
	Bool32 occlusionQueryPrecise                   = Constants::False;
	Bool32 pipelineStatisticsQuery                 = Constants::False;
	Bool32 vertexPipelineStoresAndAtomics          = Constants::False;
	Bool32 fragmentStoresAndAtomics                = Constants::False;
	Bool32 shaderTessellationAndGeometryPointSize  = Constants::False;
	Bool32 shaderImageGatherExtended               = Constants::False;
	Bool32 shaderStorageImageExtendedFormats       = Constants::False;
	Bool32 shaderStorageImageMultisample           = Constants::False;
	Bool32 shaderStorageImageReadWithoutFormat     = Constants::False;
	Bool32 shaderStorageImageWriteWithoutFormat    = Constants::False;
	Bool32 shaderUniformBufferArrayDynamicIndexing = Constants::False;
	Bool32 shaderSampledImageArrayDynamicIndexing  = Constants::False;
	Bool32 shaderStorageBufferArrayDynamicIndexing = Constants::False;
	Bool32 shaderStorageImageArrayDynamicIndexing  = Constants::False;
	Bool32 shaderClipDistance                      = Constants::False;
	Bool32 shaderCullDistance                      = Constants::False;
	Bool32 shaderFloat64                           = Constants::False;
	Bool32 shaderInt64                             = Constants::False;
	Bool32 shaderInt16                             = Constants::False;
	Bool32 shaderResourceResidency                 = Constants::False;
	Bool32 shaderResourceMinLod                    = Constants::False;
	Bool32 sparseBinding                           = Constants::False;
	Bool32 sparseResidencyBuffer                   = Constants::False;
	Bool32 sparseResidencyImage2D                  = Constants::False;
	Bool32 sparseResidencyImage3D                  = Constants::False;
	Bool32 sparseResidency2Samples                 = Constants::False;
	Bool32 sparseResidency4Samples                 = Constants::False;
	Bool32 sparseResidency8Samples                 = Constants::False;
	Bool32 sparseResidency16Samples                = Constants::False;
	Bool32 sparseResidencyAliased                  = Constants::False;
	Bool32 variableMultisampleRate                 = Constants::False;
	Bool32 inheritedQueries                        = Constants::False;
};
struct PhysicalDeviceFloatControlsProperties {
	StructureType                   sType                                 = StructureType::PhysicalDeviceFloatControlsProperties;
	void *                          pNext                                 = nullptr;
	ShaderFloatControlsIndependence denormBehaviorIndependence            = ShaderFloatControlsIndependence::v32BitOnly;
	ShaderFloatControlsIndependence roundingModeIndependence              = ShaderFloatControlsIndependence::v32BitOnly;
	Bool32                          shaderSignedZeroInfNanPreserveFloat16 = Constants::False;
	Bool32                          shaderSignedZeroInfNanPreserveFloat32 = Constants::False;
	Bool32                          shaderSignedZeroInfNanPreserveFloat64 = Constants::False;
	Bool32                          shaderDenormPreserveFloat16           = Constants::False;
	Bool32                          shaderDenormPreserveFloat32           = Constants::False;
	Bool32                          shaderDenormPreserveFloat64           = Constants::False;
	Bool32                          shaderDenormFlushToZeroFloat16        = Constants::False;
	Bool32                          shaderDenormFlushToZeroFloat32        = Constants::False;
	Bool32                          shaderDenormFlushToZeroFloat64        = Constants::False;
	Bool32                          shaderRoundingModeRTEFloat16          = Constants::False;
	Bool32                          shaderRoundingModeRTEFloat32          = Constants::False;
	Bool32                          shaderRoundingModeRTEFloat64          = Constants::False;
	Bool32                          shaderRoundingModeRTZFloat16          = Constants::False;
	Bool32                          shaderRoundingModeRTZFloat32          = Constants::False;
	Bool32                          shaderRoundingModeRTZFloat64          = Constants::False;
};
struct PhysicalDeviceFormatPackFeaturesARM {
	StructureType sType      = StructureType::PhysicalDeviceFormatPackFeaturesARM;
	void *        pNext      = nullptr;
	Bool32        formatPack = Constants::False;
};
struct PhysicalDeviceFragmentDensityMap2FeaturesEXT {
	StructureType sType                      = StructureType::PhysicalDeviceFragmentDensityMap2FeaturesEXT;
	void *        pNext                      = nullptr;
	Bool32        fragmentDensityMapDeferred = Constants::False;
};
struct PhysicalDeviceFragmentDensityMap2PropertiesEXT {
	StructureType sType                                     = StructureType::PhysicalDeviceFragmentDensityMap2PropertiesEXT;
	void *        pNext                                     = nullptr;
	Bool32        subsampledLoads                           = Constants::False;
	Bool32        subsampledCoarseReconstructionEarlyAccess = Constants::False;
	uint32_t      maxSubsampledArrayLayers                  = 0;
	uint32_t      maxDescriptorSetSubsampledSamplers        = 0;
};
struct PhysicalDeviceFragmentDensityMapFeaturesEXT {
	StructureType sType                                 = StructureType::PhysicalDeviceFragmentDensityMapFeaturesEXT;
	void *        pNext                                 = nullptr;
	Bool32        fragmentDensityMap                    = Constants::False;
	Bool32        fragmentDensityMapDynamic             = Constants::False;
	Bool32        fragmentDensityMapNonSubsampledImages = Constants::False;
};
struct PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE {
	StructureType sType                     = StructureType::PhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE;
	void *        pNext                     = nullptr;
	Bool32        fragmentDensityMapLayered = Constants::False;
};
struct PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE {
	StructureType sType                       = StructureType::PhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE;
	void *        pNext                       = nullptr;
	uint32_t      maxFragmentDensityMapLayers = 0;
};
struct PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT {
	StructureType sType                    = StructureType::PhysicalDeviceFragmentDensityMapOffsetFeaturesEXT;
	void *        pNext                    = nullptr;
	Bool32        fragmentDensityMapOffset = Constants::False;
};
struct PhysicalDeviceFragmentShaderBarycentricFeaturesKHR {
	StructureType sType                     = StructureType::PhysicalDeviceFragmentShaderBarycentricFeaturesKHR;
	void *        pNext                     = nullptr;
	Bool32        fragmentShaderBarycentric = Constants::False;
};
struct PhysicalDeviceFragmentShaderBarycentricPropertiesKHR {
	StructureType sType                                           = StructureType::PhysicalDeviceFragmentShaderBarycentricPropertiesKHR;
	void *        pNext                                           = nullptr;
	Bool32        triStripVertexOrderIndependentOfProvokingVertex = Constants::False;
};
struct PhysicalDeviceFragmentShaderInterlockFeaturesEXT {
	StructureType sType                              = StructureType::PhysicalDeviceFragmentShaderInterlockFeaturesEXT;
	void *        pNext                              = nullptr;
	Bool32        fragmentShaderSampleInterlock      = Constants::False;
	Bool32        fragmentShaderPixelInterlock       = Constants::False;
	Bool32        fragmentShaderShadingRateInterlock = Constants::False;
};
struct PhysicalDeviceFragmentShadingRateEnumsFeaturesNV {
	StructureType sType                            = StructureType::PhysicalDeviceFragmentShadingRateEnumsFeaturesNV;
	void *        pNext                            = nullptr;
	Bool32        fragmentShadingRateEnums         = Constants::False;
	Bool32        supersampleFragmentShadingRates  = Constants::False;
	Bool32        noInvocationFragmentShadingRates = Constants::False;
};
struct PhysicalDeviceFragmentShadingRateEnumsPropertiesNV {
	StructureType   sType                                 = StructureType::PhysicalDeviceFragmentShadingRateEnumsPropertiesNV;
	void *          pNext                                 = nullptr;
	SampleCountBits maxFragmentShadingRateInvocationCount = SampleCountBits::v1;
};
struct PhysicalDeviceFragmentShadingRateFeaturesKHR {
	StructureType sType                         = StructureType::PhysicalDeviceFragmentShadingRateFeaturesKHR;
	void *        pNext                         = nullptr;
	Bool32        pipelineFragmentShadingRate   = Constants::False;
	Bool32        primitiveFragmentShadingRate  = Constants::False;
	Bool32        attachmentFragmentShadingRate = Constants::False;
};
struct PhysicalDeviceFrameBoundaryFeaturesEXT {
	StructureType sType         = StructureType::PhysicalDeviceFrameBoundaryFeaturesEXT;
	void *        pNext         = nullptr;
	Bool32        frameBoundary = Constants::False;
};
struct PhysicalDeviceGlobalPriorityQueryFeatures {
	StructureType sType               = StructureType::PhysicalDeviceGlobalPriorityQueryFeatures;
	void *        pNext               = nullptr;
	Bool32        globalPriorityQuery = Constants::False;
};
struct PhysicalDeviceGpaFeaturesAMD {
	StructureType sType                 = StructureType::PhysicalDeviceGpaFeaturesAMD;
	void *        pNext                 = nullptr;
	Bool32        perfCounters          = Constants::False;
	Bool32        streamingPerfCounters = Constants::False;
	Bool32        sqThreadTracing       = Constants::False;
	Bool32        clockModes            = Constants::False;
};
struct PhysicalDeviceGpaProperties2AMD {
	StructureType sType      = StructureType::PhysicalDeviceGpaProperties2AMD;
	void *        pNext      = nullptr;
	uint32_t      revisionId = 0;
};
struct PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT {
	StructureType sType                   = StructureType::PhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;
	void *        pNext                   = nullptr;
	Bool32        graphicsPipelineLibrary = Constants::False;
};
struct PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT {
	StructureType sType                                                     = StructureType::PhysicalDeviceGraphicsPipelineLibraryPropertiesEXT;
	void *        pNext                                                     = nullptr;
	Bool32        graphicsPipelineLibraryFastLinking                        = Constants::False;
	Bool32        graphicsPipelineLibraryIndependentInterpolationDecoration = Constants::False;
};
struct PhysicalDeviceGroupProperties {
	StructureType                                                                            sType               = StructureType::PhysicalDeviceGroupProperties;
	void *                                                                                   pNext               = nullptr;
	uint32_t                                                                                 physicalDeviceCount = 0;
	std::array<impl_Struct::AssignableHandle<PhysicalDevice>, Constants::MaxDeviceGroupSize> physicalDevices     = {};// len physicalDeviceCount
	Bool32                                                                                   subsetAllocation    = Constants::False;
};
struct PhysicalDeviceHdrVividFeaturesHUAWEI {
	StructureType sType    = StructureType::PhysicalDeviceHdrVividFeaturesHUAWEI;
	void *        pNext    = nullptr;
	Bool32        hdrVivid = Constants::False;
};
struct PhysicalDeviceHostImageCopyFeatures {
	StructureType sType         = StructureType::PhysicalDeviceHostImageCopyFeatures;
	void *        pNext         = nullptr;
	Bool32        hostImageCopy = Constants::False;
};
struct PhysicalDeviceHostImageCopyProperties {
	StructureType                            sType                           = StructureType::PhysicalDeviceHostImageCopyProperties;
	void *                                   pNext                           = nullptr;
	uint32_t                                 copySrcLayoutCount              = 0;
	ImageLayout *                            pCopySrcLayouts                 = nullptr;// len copySrcLayoutCount
	uint32_t                                 copyDstLayoutCount              = 0;
	ImageLayout *                            pCopyDstLayouts                 = nullptr;// len copyDstLayoutCount
	std::array<uint8_t, Constants::UuidSize> optimalTilingLayoutUUID         = {};
	Bool32                                   identicalMemoryTypeRequirements = Constants::False;
};
struct PhysicalDeviceHostQueryResetFeatures {
	StructureType sType          = StructureType::PhysicalDeviceHostQueryResetFeatures;
	void *        pNext          = nullptr;
	Bool32        hostQueryReset = Constants::False;
};
struct PhysicalDeviceIDProperties {
	StructureType                            sType           = StructureType::PhysicalDeviceIdProperties;
	void *                                   pNext           = nullptr;
	std::array<uint8_t, Constants::UuidSize> deviceUUID      = {};
	std::array<uint8_t, Constants::UuidSize> driverUUID      = {};
	std::array<uint8_t, Constants::LuidSize> deviceLUID      = {};
	uint32_t                                 deviceNodeMask  = 0;
	Bool32                                   deviceLUIDValid = Constants::False;
};
struct PhysicalDeviceImage2DViewOf3DFeaturesEXT {
	StructureType sType             = StructureType::PhysicalDeviceImage2DViewOf3DFeaturesEXT;
	void *        pNext             = nullptr;
	Bool32        image2DViewOf3D   = Constants::False;
	Bool32        sampler2DViewOf3D = Constants::False;
};
struct PhysicalDeviceImageAlignmentControlFeaturesMESA {
	StructureType sType                 = StructureType::PhysicalDeviceImageAlignmentControlFeaturesMESA;
	void *        pNext                 = nullptr;
	Bool32        imageAlignmentControl = Constants::False;
};
struct PhysicalDeviceImageAlignmentControlPropertiesMESA {
	StructureType sType                       = StructureType::PhysicalDeviceImageAlignmentControlPropertiesMESA;
	void *        pNext                       = nullptr;
	uint32_t      supportedImageAlignmentMask = 0;
};
struct PhysicalDeviceImageCompressionControlFeaturesEXT {
	StructureType sType                   = StructureType::PhysicalDeviceImageCompressionControlFeaturesEXT;
	void *        pNext                   = nullptr;
	Bool32        imageCompressionControl = Constants::False;
};
struct PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT {
	StructureType sType                            = StructureType::PhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;
	void *        pNext                            = nullptr;
	Bool32        imageCompressionControlSwapchain = Constants::False;
};
struct PhysicalDeviceImageDrmFormatModifierInfoEXT {
	StructureType   sType                 = StructureType::PhysicalDeviceImageDrmFormatModifierInfoEXT;
	const void *    pNext                 = nullptr;
	uint64_t        drmFormatModifier     = 0;
	SharingMode     sharingMode           = SharingMode::Exclusive;
	uint32_t        queueFamilyIndexCount = 0;
	const uint32_t *pQueueFamilyIndices   = nullptr;// len queueFamilyIndexCount
	auto queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct PhysicalDeviceImageFormatInfo2 {
	StructureType    sType  = StructureType::PhysicalDeviceImageFormatInfo2;
	const void *     pNext  = nullptr;
	Format           format = Format::Undefined;
	ImageType        type   = ImageType::v1D;
	ImageTiling      tiling = ImageTiling::Optimal;
	ImageUsageFlags  usage  = {};
	ImageCreateFlags flags  = {};
};
struct PhysicalDeviceImageProcessing2FeaturesQCOM {
	StructureType sType              = StructureType::PhysicalDeviceImageProcessing2FeaturesQCOM;
	void *        pNext              = nullptr;
	Bool32        textureBlockMatch2 = Constants::False;
};
struct PhysicalDeviceImageProcessing3FeaturesQCOM {
	StructureType sType                         = StructureType::PhysicalDeviceImageProcessing3FeaturesQCOM;
	void *        pNext                         = nullptr;
	Bool32        imageGatherLinear             = Constants::False;
	Bool32        imageGatherExtendedModes      = Constants::False;
	Bool32        blockMatchExtendedClampToEdge = Constants::False;
};
struct PhysicalDeviceImageProcessingFeaturesQCOM {
	StructureType sType                 = StructureType::PhysicalDeviceImageProcessingFeaturesQCOM;
	void *        pNext                 = nullptr;
	Bool32        textureSampleWeighted = Constants::False;
	Bool32        textureBoxFilter      = Constants::False;
	Bool32        textureBlockMatch     = Constants::False;
};
struct PhysicalDeviceImageRobustnessFeatures {
	StructureType sType             = StructureType::PhysicalDeviceImageRobustnessFeatures;
	void *        pNext             = nullptr;
	Bool32        robustImageAccess = Constants::False;
};
struct PhysicalDeviceImageSlicedViewOf3DFeaturesEXT {
	StructureType sType               = StructureType::PhysicalDeviceImageSlicedViewOf3DFeaturesEXT;
	void *        pNext               = nullptr;
	Bool32        imageSlicedViewOf3D = Constants::False;
};
struct PhysicalDeviceImageTilingControlFeaturesEXT {
	StructureType sType              = StructureType::PhysicalDeviceImageTilingControlFeaturesEXT;
	void *        pNext              = nullptr;
	Bool32        imageTilingControl = Constants::False;
};
struct PhysicalDeviceImageViewImageFormatInfoEXT {
	StructureType sType         = StructureType::PhysicalDeviceImageViewImageFormatInfoEXT;
	void *        pNext         = nullptr;
	ImageViewType imageViewType = ImageViewType::v1D;
};
struct PhysicalDeviceImageViewMinLodFeaturesEXT {
	StructureType sType  = StructureType::PhysicalDeviceImageViewMinLodFeaturesEXT;
	void *        pNext  = nullptr;
	Bool32        minLod = Constants::False;
};
struct PhysicalDeviceImagelessFramebufferFeatures {
	StructureType sType                = StructureType::PhysicalDeviceImagelessFramebufferFeatures;
	void *        pNext                = nullptr;
	Bool32        imagelessFramebuffer = Constants::False;
};
struct PhysicalDeviceIndexTypeUint8Features {
	StructureType sType          = StructureType::PhysicalDeviceIndexTypeUint8Features;
	void *        pNext          = nullptr;
	Bool32        indexTypeUint8 = Constants::False;
};
struct PhysicalDeviceInheritedViewportScissorFeaturesNV {
	StructureType sType                      = StructureType::PhysicalDeviceInheritedViewportScissorFeaturesNV;
	void *        pNext                      = nullptr;
	Bool32        inheritedViewportScissor2D = Constants::False;
};
struct PhysicalDeviceInlineUniformBlockFeatures {
	StructureType sType                                              = StructureType::PhysicalDeviceInlineUniformBlockFeatures;
	void *        pNext                                              = nullptr;
	Bool32        inlineUniformBlock                                 = Constants::False;
	Bool32        descriptorBindingInlineUniformBlockUpdateAfterBind = Constants::False;
};
struct PhysicalDeviceInlineUniformBlockProperties {
	StructureType sType                                                   = StructureType::PhysicalDeviceInlineUniformBlockProperties;
	void *        pNext                                                   = nullptr;
	uint32_t      maxInlineUniformBlockSize                               = 0;
	uint32_t      maxPerStageDescriptorInlineUniformBlocks                = 0;
	uint32_t      maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks = 0;
	uint32_t      maxDescriptorSetInlineUniformBlocks                     = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindInlineUniformBlocks      = 0;
};
struct PhysicalDeviceInternallySynchronizedQueuesFeaturesKHR {
	StructureType sType                        = StructureType::PhysicalDeviceInternallySynchronizedQueuesFeaturesKHR;
	void *        pNext                        = nullptr;
	Bool32        internallySynchronizedQueues = Constants::False;
};
struct PhysicalDeviceInvocationMaskFeaturesHUAWEI {
	StructureType sType          = StructureType::PhysicalDeviceInvocationMaskFeaturesHUAWEI;
	void *        pNext          = nullptr;
	Bool32        invocationMask = Constants::False;
};
struct PhysicalDeviceLayeredApiPropertiesKHR {
	StructureType                                                  sType      = StructureType::PhysicalDeviceLayeredApiPropertiesKHR;
	void *                                                         pNext      = nullptr;
	uint32_t                                                       vendorID   = 0;
	uint32_t                                                       deviceID   = 0;
	PhysicalDeviceLayeredApiKHR                                    layeredAPI = PhysicalDeviceLayeredApiKHR::Vulkan;
	impl_Struct::FixedString<Constants::MaxPhysicalDeviceNameSize> deviceName = {};
};
struct PhysicalDeviceLayeredDriverPropertiesMSFT {
	StructureType                  sType         = StructureType::PhysicalDeviceLayeredDriverPropertiesMSFT;
	void *                         pNext         = nullptr;
	LayeredDriverUnderlyingApiMSFT underlyingAPI = LayeredDriverUnderlyingApiMSFT::None;
};
struct PhysicalDeviceLegacyDitheringFeaturesEXT {
	StructureType sType           = StructureType::PhysicalDeviceLegacyDitheringFeaturesEXT;
	void *        pNext           = nullptr;
	Bool32        legacyDithering = Constants::False;
};
struct PhysicalDeviceLegacyVertexAttributesFeaturesEXT {
	StructureType sType                  = StructureType::PhysicalDeviceLegacyVertexAttributesFeaturesEXT;
	void *        pNext                  = nullptr;
	Bool32        legacyVertexAttributes = Constants::False;
};
struct PhysicalDeviceLegacyVertexAttributesPropertiesEXT {
	StructureType sType                      = StructureType::PhysicalDeviceLegacyVertexAttributesPropertiesEXT;
	void *        pNext                      = nullptr;
	Bool32        nativeUnalignedPerformance = Constants::False;
};
struct PhysicalDeviceLimits {
	uint32_t                maxImageDimension1D                             = 0;
	uint32_t                maxImageDimension2D                             = 0;
	uint32_t                maxImageDimension3D                             = 0;
	uint32_t                maxImageDimensionCube                           = 0;
	uint32_t                maxImageArrayLayers                             = 0;
	uint32_t                maxTexelBufferElements                          = 0;
	uint32_t                maxUniformBufferRange                           = 0;
	uint32_t                maxStorageBufferRange                           = 0;
	uint32_t                maxPushConstantsSize                            = 0;
	uint32_t                maxMemoryAllocationCount                        = 0;
	uint32_t                maxSamplerAllocationCount                       = 0;
	DeviceSize              bufferImageGranularity                          = 0;
	DeviceSize              sparseAddressSpaceSize                          = 0;
	uint32_t                maxBoundDescriptorSets                          = 0;
	uint32_t                maxPerStageDescriptorSamplers                   = 0;
	uint32_t                maxPerStageDescriptorUniformBuffers             = 0;
	uint32_t                maxPerStageDescriptorStorageBuffers             = 0;
	uint32_t                maxPerStageDescriptorSampledImages              = 0;
	uint32_t                maxPerStageDescriptorStorageImages              = 0;
	uint32_t                maxPerStageDescriptorInputAttachments           = 0;
	uint32_t                maxPerStageResources                            = 0;
	uint32_t                maxDescriptorSetSamplers                        = 0;
	uint32_t                maxDescriptorSetUniformBuffers                  = 0;
	uint32_t                maxDescriptorSetUniformBuffersDynamic           = 0;
	uint32_t                maxDescriptorSetStorageBuffers                  = 0;
	uint32_t                maxDescriptorSetStorageBuffersDynamic           = 0;
	uint32_t                maxDescriptorSetSampledImages                   = 0;
	uint32_t                maxDescriptorSetStorageImages                   = 0;
	uint32_t                maxDescriptorSetInputAttachments                = 0;
	uint32_t                maxVertexInputAttributes                        = 0;
	uint32_t                maxVertexInputBindings                          = 0;
	uint32_t                maxVertexInputAttributeOffset                   = 0;
	uint32_t                maxVertexInputBindingStride                     = 0;
	uint32_t                maxVertexOutputComponents                       = 0;
	uint32_t                maxTessellationGenerationLevel                  = 0;
	uint32_t                maxTessellationPatchSize                        = 0;
	uint32_t                maxTessellationControlPerVertexInputComponents  = 0;
	uint32_t                maxTessellationControlPerVertexOutputComponents = 0;
	uint32_t                maxTessellationControlPerPatchOutputComponents  = 0;
	uint32_t                maxTessellationControlTotalOutputComponents     = 0;
	uint32_t                maxTessellationEvaluationInputComponents        = 0;
	uint32_t                maxTessellationEvaluationOutputComponents       = 0;
	uint32_t                maxGeometryShaderInvocations                    = 0;
	uint32_t                maxGeometryInputComponents                      = 0;
	uint32_t                maxGeometryOutputComponents                     = 0;
	uint32_t                maxGeometryOutputVertices                       = 0;
	uint32_t                maxGeometryTotalOutputComponents                = 0;
	uint32_t                maxFragmentInputComponents                      = 0;
	uint32_t                maxFragmentOutputAttachments                    = 0;
	uint32_t                maxFragmentDualSrcAttachments                   = 0;
	uint32_t                maxFragmentCombinedOutputResources              = 0;
	uint32_t                maxComputeSharedMemorySize                      = 0;
	std::array<uint32_t, 3> maxComputeWorkGroupCount                        = {};
	uint32_t                maxComputeWorkGroupInvocations                  = 0;
	std::array<uint32_t, 3> maxComputeWorkGroupSize                         = {};
	uint32_t                subPixelPrecisionBits                           = 0;
	uint32_t                subTexelPrecisionBits                           = 0;
	uint32_t                mipmapPrecisionBits                             = 0;
	uint32_t                maxDrawIndexedIndexValue                        = 0;
	uint32_t                maxDrawIndirectCount                            = 0;
	float                   maxSamplerLodBias                               = 0.0F;
	float                   maxSamplerAnisotropy                            = 0.0F;
	uint32_t                maxViewports                                    = 0;
	std::array<uint32_t, 2> maxViewportDimensions                           = {};
	std::array<float, 2>    viewportBoundsRange                             = {};
	uint32_t                viewportSubPixelBits                            = 0;
	size_t                  minMemoryMapAlignment                           = 0;
	DeviceSize              minTexelBufferOffsetAlignment                   = 0;
	DeviceSize              minUniformBufferOffsetAlignment                 = 0;
	DeviceSize              minStorageBufferOffsetAlignment                 = 0;
	int32_t                 minTexelOffset                                  = 0;
	uint32_t                maxTexelOffset                                  = 0;
	int32_t                 minTexelGatherOffset                            = 0;
	uint32_t                maxTexelGatherOffset                            = 0;
	float                   minInterpolationOffset                          = 0.0F;
	float                   maxInterpolationOffset                          = 0.0F;
	uint32_t                subPixelInterpolationOffsetBits                 = 0;
	uint32_t                maxFramebufferWidth                             = 0;
	uint32_t                maxFramebufferHeight                            = 0;
	uint32_t                maxFramebufferLayers                            = 0;
	SampleCountFlags        framebufferColorSampleCounts                    = {};
	SampleCountFlags        framebufferDepthSampleCounts                    = {};
	SampleCountFlags        framebufferStencilSampleCounts                  = {};
	SampleCountFlags        framebufferNoAttachmentsSampleCounts            = {};
	uint32_t                maxColorAttachments                             = 0;
	SampleCountFlags        sampledImageColorSampleCounts                   = {};
	SampleCountFlags        sampledImageIntegerSampleCounts                 = {};
	SampleCountFlags        sampledImageDepthSampleCounts                   = {};
	SampleCountFlags        sampledImageStencilSampleCounts                 = {};
	SampleCountFlags        storageImageSampleCounts                        = {};
	uint32_t                maxSampleMaskWords                              = 0;
	Bool32                  timestampComputeAndGraphics                     = Constants::False;
	float                   timestampPeriod                                 = 0.0F;
	uint32_t                maxClipDistances                                = 0;
	uint32_t                maxCullDistances                                = 0;
	uint32_t                maxCombinedClipAndCullDistances                 = 0;
	uint32_t                discreteQueuePriorities                         = 0;
	std::array<float, 2>    pointSizeRange                                  = {};
	std::array<float, 2>    lineWidthRange                                  = {};
	float                   pointSizeGranularity                            = 0.0F;
	float                   lineWidthGranularity                            = 0.0F;
	Bool32                  strictLines                                     = Constants::False;
	Bool32                  standardSampleLocations                         = Constants::False;
	DeviceSize              optimalBufferCopyOffsetAlignment                = 0;
	DeviceSize              optimalBufferCopyRowPitchAlignment              = 0;
	DeviceSize              nonCoherentAtomSize                             = 0;
};
struct PhysicalDeviceLineRasterizationFeatures {
	StructureType sType                    = StructureType::PhysicalDeviceLineRasterizationFeatures;
	void *        pNext                    = nullptr;
	Bool32        rectangularLines         = Constants::False;
	Bool32        bresenhamLines           = Constants::False;
	Bool32        smoothLines              = Constants::False;
	Bool32        stippledRectangularLines = Constants::False;
	Bool32        stippledBresenhamLines   = Constants::False;
	Bool32        stippledSmoothLines      = Constants::False;
};
struct PhysicalDeviceLineRasterizationProperties {
	StructureType sType                     = StructureType::PhysicalDeviceLineRasterizationProperties;
	void *        pNext                     = nullptr;
	uint32_t      lineSubPixelPrecisionBits = 0;
};
struct PhysicalDeviceLinearColorAttachmentFeaturesNV {
	StructureType sType                 = StructureType::PhysicalDeviceLinearColorAttachmentFeaturesNV;
	void *        pNext                 = nullptr;
	Bool32        linearColorAttachment = Constants::False;
};
struct PhysicalDeviceMaintenance10FeaturesKHR {
	StructureType sType         = StructureType::PhysicalDeviceMaintenance10FeaturesKHR;
	void *        pNext         = nullptr;
	Bool32        maintenance10 = Constants::False;
};
struct PhysicalDeviceMaintenance10PropertiesKHR {
	StructureType sType                                            = StructureType::PhysicalDeviceMaintenance10PropertiesKHR;
	void *        pNext                                            = nullptr;
	Bool32        rgba4OpaqueBlackSwizzled                         = Constants::False;
	Bool32        resolveSrgbFormatAppliesTransferFunction         = Constants::False;
	Bool32        resolveSrgbFormatSupportsTransferFunctionControl = Constants::False;
};
struct PhysicalDeviceMaintenance11FeaturesKHR {
	StructureType sType         = StructureType::PhysicalDeviceMaintenance11FeaturesKHR;
	void *        pNext         = nullptr;
	Bool32        maintenance11 = Constants::False;
};
struct PhysicalDeviceMaintenance3Properties {
	StructureType sType                   = StructureType::PhysicalDeviceMaintenance3Properties;
	void *        pNext                   = nullptr;
	uint32_t      maxPerSetDescriptors    = 0;
	DeviceSize    maxMemoryAllocationSize = 0;
};
struct PhysicalDeviceMaintenance4Features {
	StructureType sType        = StructureType::PhysicalDeviceMaintenance4Features;
	void *        pNext        = nullptr;
	Bool32        maintenance4 = Constants::False;
};
struct PhysicalDeviceMaintenance4Properties {
	StructureType sType         = StructureType::PhysicalDeviceMaintenance4Properties;
	void *        pNext         = nullptr;
	DeviceSize    maxBufferSize = 0;
};
struct PhysicalDeviceMaintenance5Features {
	StructureType sType        = StructureType::PhysicalDeviceMaintenance5Features;
	void *        pNext        = nullptr;
	Bool32        maintenance5 = Constants::False;
};
struct PhysicalDeviceMaintenance5Properties {
	StructureType sType                                               = StructureType::PhysicalDeviceMaintenance5Properties;
	void *        pNext                                               = nullptr;
	Bool32        earlyFragmentMultisampleCoverageAfterSampleCounting = Constants::False;
	Bool32        earlyFragmentSampleMaskTestBeforeSampleCounting     = Constants::False;
	Bool32        depthStencilSwizzleOneSupport                       = Constants::False;
	Bool32        polygonModePointSize                                = Constants::False;
	Bool32        nonStrictSinglePixelWideLinesUseParallelogram       = Constants::False;
	Bool32        nonStrictWideLinesUseParallelogram                  = Constants::False;
};
struct PhysicalDeviceMaintenance6Features {
	StructureType sType        = StructureType::PhysicalDeviceMaintenance6Features;
	void *        pNext        = nullptr;
	Bool32        maintenance6 = Constants::False;
};
struct PhysicalDeviceMaintenance6Properties {
	StructureType sType                                  = StructureType::PhysicalDeviceMaintenance6Properties;
	void *        pNext                                  = nullptr;
	Bool32        blockTexelViewCompatibleMultipleLayers = Constants::False;
	uint32_t      maxCombinedImageSamplerDescriptorCount = 0;
	Bool32        fragmentShadingRateClampCombinerInputs = Constants::False;
};
struct PhysicalDeviceMaintenance7FeaturesKHR {
	StructureType sType        = StructureType::PhysicalDeviceMaintenance7FeaturesKHR;
	void *        pNext        = nullptr;
	Bool32        maintenance7 = Constants::False;
};
struct PhysicalDeviceMaintenance7PropertiesKHR {
	StructureType sType                                                     = StructureType::PhysicalDeviceMaintenance7PropertiesKHR;
	void *        pNext                                                     = nullptr;
	Bool32        robustFragmentShadingRateAttachmentAccess                 = Constants::False;
	Bool32        separateDepthStencilAttachmentAccess                      = Constants::False;
	uint32_t      maxDescriptorSetTotalUniformBuffersDynamic                = 0;
	uint32_t      maxDescriptorSetTotalStorageBuffersDynamic                = 0;
	uint32_t      maxDescriptorSetTotalBuffersDynamic                       = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic = 0;
	uint32_t      maxDescriptorSetUpdateAfterBindTotalBuffersDynamic        = 0;
};
struct PhysicalDeviceMaintenance8FeaturesKHR {
	StructureType sType        = StructureType::PhysicalDeviceMaintenance8FeaturesKHR;
	void *        pNext        = nullptr;
	Bool32        maintenance8 = Constants::False;
};
struct PhysicalDeviceMaintenance9FeaturesKHR {
	StructureType sType        = StructureType::PhysicalDeviceMaintenance9FeaturesKHR;
	void *        pNext        = nullptr;
	Bool32        maintenance9 = Constants::False;
};
struct PhysicalDeviceMaintenance9PropertiesKHR {
	StructureType                  sType                       = StructureType::PhysicalDeviceMaintenance9PropertiesKHR;
	void *                         pNext                       = nullptr;
	Bool32                         image2DViewOf3DSparse       = Constants::False;
	DefaultVertexAttributeValueKHR defaultVertexAttributeValue = DefaultVertexAttributeValueKHR::ZeroZeroZeroZero;
};
struct PhysicalDeviceMapMemoryPlacedFeaturesEXT {
	StructureType sType                = StructureType::PhysicalDeviceMapMemoryPlacedFeaturesEXT;
	void *        pNext                = nullptr;
	Bool32        memoryMapPlaced      = Constants::False;
	Bool32        memoryMapRangePlaced = Constants::False;
	Bool32        memoryUnmapReserve   = Constants::False;
};
struct PhysicalDeviceMapMemoryPlacedPropertiesEXT {
	StructureType sType                       = StructureType::PhysicalDeviceMapMemoryPlacedPropertiesEXT;
	void *        pNext                       = nullptr;
	DeviceSize    minPlacedMemoryMapAlignment = 0;
};
struct PhysicalDeviceMemoryBudgetPropertiesEXT {
	StructureType                                     sType      = StructureType::PhysicalDeviceMemoryBudgetPropertiesEXT;
	void *                                            pNext      = nullptr;
	std::array<DeviceSize, Constants::MaxMemoryHeaps> heapBudget = {};
	std::array<DeviceSize, Constants::MaxMemoryHeaps> heapUsage  = {};
};
struct PhysicalDeviceMemoryDecompressionFeaturesEXT {
	StructureType sType               = StructureType::PhysicalDeviceMemoryDecompressionFeaturesEXT;
	void *        pNext               = nullptr;
	Bool32        memoryDecompression = Constants::False;
};
struct PhysicalDeviceMemoryDecompressionPropertiesEXT {
	StructureType                     sType                         = StructureType::PhysicalDeviceMemoryDecompressionPropertiesEXT;
	void *                            pNext                         = nullptr;
	MemoryDecompressionMethodFlagsEXT decompressionMethods          = {};
	uint64_t                          maxDecompressionIndirectCount = 0;
};
struct PhysicalDeviceMemoryPriorityFeaturesEXT {
	StructureType sType          = StructureType::PhysicalDeviceMemoryPriorityFeaturesEXT;
	void *        pNext          = nullptr;
	Bool32        memoryPriority = Constants::False;
};
struct PhysicalDeviceMeshShaderFeaturesEXT {
	StructureType sType                                  = StructureType::PhysicalDeviceMeshShaderFeaturesEXT;
	void *        pNext                                  = nullptr;
	Bool32        taskShader                             = Constants::False;
	Bool32        meshShader                             = Constants::False;
	Bool32        multiviewMeshShader                    = Constants::False;
	Bool32        primitiveFragmentShadingRateMeshShader = Constants::False;
	Bool32        meshShaderQueries                      = Constants::False;
};
struct PhysicalDeviceMeshShaderFeaturesNV {
	StructureType sType      = StructureType::PhysicalDeviceMeshShaderFeaturesNV;
	void *        pNext      = nullptr;
	Bool32        taskShader = Constants::False;
	Bool32        meshShader = Constants::False;
};
struct PhysicalDeviceMeshShaderPropertiesEXT {
	StructureType           sType                                 = StructureType::PhysicalDeviceMeshShaderPropertiesEXT;
	void *                  pNext                                 = nullptr;
	uint32_t                maxTaskWorkGroupTotalCount            = 0;
	std::array<uint32_t, 3> maxTaskWorkGroupCount                 = {};
	uint32_t                maxTaskWorkGroupInvocations           = 0;
	std::array<uint32_t, 3> maxTaskWorkGroupSize                  = {};
	uint32_t                maxTaskPayloadSize                    = 0;
	uint32_t                maxTaskSharedMemorySize               = 0;
	uint32_t                maxTaskPayloadAndSharedMemorySize     = 0;
	uint32_t                maxMeshWorkGroupTotalCount            = 0;
	std::array<uint32_t, 3> maxMeshWorkGroupCount                 = {};
	uint32_t                maxMeshWorkGroupInvocations           = 0;
	std::array<uint32_t, 3> maxMeshWorkGroupSize                  = {};
	uint32_t                maxMeshSharedMemorySize               = 0;
	uint32_t                maxMeshPayloadAndSharedMemorySize     = 0;
	uint32_t                maxMeshOutputMemorySize               = 0;
	uint32_t                maxMeshPayloadAndOutputMemorySize     = 0;
	uint32_t                maxMeshOutputComponents               = 0;
	uint32_t                maxMeshOutputVertices                 = 0;
	uint32_t                maxMeshOutputPrimitives               = 0;
	uint32_t                maxMeshOutputLayers                   = 0;
	uint32_t                maxMeshMultiviewViewCount             = 0;
	uint32_t                meshOutputPerVertexGranularity        = 0;
	uint32_t                meshOutputPerPrimitiveGranularity     = 0;
	uint32_t                maxPreferredTaskWorkGroupInvocations  = 0;
	uint32_t                maxPreferredMeshWorkGroupInvocations  = 0;
	Bool32                  prefersLocalInvocationVertexOutput    = Constants::False;
	Bool32                  prefersLocalInvocationPrimitiveOutput = Constants::False;
	Bool32                  prefersCompactVertexOutput            = Constants::False;
	Bool32                  prefersCompactPrimitiveOutput         = Constants::False;
};
struct PhysicalDeviceMeshShaderPropertiesNV {
	StructureType           sType                             = StructureType::PhysicalDeviceMeshShaderPropertiesNV;
	void *                  pNext                             = nullptr;
	uint32_t                maxDrawMeshTasksCount             = 0;
	uint32_t                maxTaskWorkGroupInvocations       = 0;
	std::array<uint32_t, 3> maxTaskWorkGroupSize              = {};
	uint32_t                maxTaskTotalMemorySize            = 0;
	uint32_t                maxTaskOutputCount                = 0;
	uint32_t                maxMeshWorkGroupInvocations       = 0;
	std::array<uint32_t, 3> maxMeshWorkGroupSize              = {};
	uint32_t                maxMeshTotalMemorySize            = 0;
	uint32_t                maxMeshOutputVertices             = 0;
	uint32_t                maxMeshOutputPrimitives           = 0;
	uint32_t                maxMeshMultiviewViewCount         = 0;
	uint32_t                meshOutputPerVertexGranularity    = 0;
	uint32_t                meshOutputPerPrimitiveGranularity = 0;
};
struct PhysicalDeviceMultiDrawFeaturesEXT {
	StructureType sType     = StructureType::PhysicalDeviceMultiDrawFeaturesEXT;
	void *        pNext     = nullptr;
	Bool32        multiDraw = Constants::False;
};
struct PhysicalDeviceMultiDrawPropertiesEXT {
	StructureType sType             = StructureType::PhysicalDeviceMultiDrawPropertiesEXT;
	void *        pNext             = nullptr;
	uint32_t      maxMultiDrawCount = 0;
};
struct PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT {
	StructureType sType                             = StructureType::PhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;
	void *        pNext                             = nullptr;
	Bool32        multisampledRenderToSingleSampled = Constants::False;
};
struct PhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT {
	StructureType sType                         = StructureType::PhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT;
	void *        pNext                         = nullptr;
	Bool32        multisampledRenderToSwapchain = Constants::False;
};
struct PhysicalDeviceMultiviewFeatures {
	StructureType sType                       = StructureType::PhysicalDeviceMultiviewFeatures;
	void *        pNext                       = nullptr;
	Bool32        multiview                   = Constants::False;
	Bool32        multiviewGeometryShader     = Constants::False;
	Bool32        multiviewTessellationShader = Constants::False;
};
struct PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX {
	StructureType sType                        = StructureType::PhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;
	void *        pNext                        = nullptr;
	Bool32        perViewPositionAllComponents = Constants::False;
};
struct PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM {
	StructureType sType                       = StructureType::PhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;
	void *        pNext                       = nullptr;
	Bool32        multiviewPerViewRenderAreas = Constants::False;
};
struct PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM {
	StructureType sType                     = StructureType::PhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM;
	void *        pNext                     = nullptr;
	Bool32        multiviewPerViewViewports = Constants::False;
};
struct PhysicalDeviceMultiviewProperties {
	StructureType sType                     = StructureType::PhysicalDeviceMultiviewProperties;
	void *        pNext                     = nullptr;
	uint32_t      maxMultiviewViewCount     = 0;
	uint32_t      maxMultiviewInstanceIndex = 0;
};
struct PhysicalDeviceMutableDescriptorTypeFeaturesEXT {
	StructureType sType                 = StructureType::PhysicalDeviceMutableDescriptorTypeFeaturesEXT;
	void *        pNext                 = nullptr;
	Bool32        mutableDescriptorType = Constants::False;
};
struct PhysicalDeviceNestedCommandBufferFeaturesEXT {
	StructureType sType                              = StructureType::PhysicalDeviceNestedCommandBufferFeaturesEXT;
	void *        pNext                              = nullptr;
	Bool32        nestedCommandBuffer                = Constants::False;
	Bool32        nestedCommandBufferRendering       = Constants::False;
	Bool32        nestedCommandBufferSimultaneousUse = Constants::False;
};
struct PhysicalDeviceNestedCommandBufferPropertiesEXT {
	StructureType sType                        = StructureType::PhysicalDeviceNestedCommandBufferPropertiesEXT;
	void *        pNext                        = nullptr;
	uint32_t      maxCommandBufferNestingLevel = 0;
};
struct PhysicalDeviceNonSeamlessCubeMapFeaturesEXT {
	StructureType sType              = StructureType::PhysicalDeviceNonSeamlessCubeMapFeaturesEXT;
	void *        pNext              = nullptr;
	Bool32        nonSeamlessCubeMap = Constants::False;
};
struct PhysicalDeviceOpacityMicromapFeaturesEXT {
	StructureType sType                 = StructureType::PhysicalDeviceOpacityMicromapFeaturesEXT;
	void *        pNext                 = nullptr;
	Bool32        micromap              = Constants::False;
	Bool32        micromapCaptureReplay = Constants::False;
	Bool32        micromapHostCommands  = Constants::False;
};
struct PhysicalDeviceOpacityMicromapFeaturesKHR {
	StructureType sType    = StructureType::PhysicalDeviceOpacityMicromapFeaturesKHR;
	void *        pNext    = nullptr;
	Bool32        micromap = Constants::False;
};
struct PhysicalDeviceOpacityMicromapPropertiesEXT {
	StructureType sType                            = StructureType::PhysicalDeviceOpacityMicromapPropertiesEXT;
	void *        pNext                            = nullptr;
	uint32_t      maxOpacity2StateSubdivisionLevel = 0;
	uint32_t      maxOpacity4StateSubdivisionLevel = 0;
};
struct PhysicalDeviceOpacityMicromapPropertiesKHR {
	StructureType sType                                 = StructureType::PhysicalDeviceOpacityMicromapPropertiesKHR;
	void *        pNext                                 = nullptr;
	uint32_t      maxOpacity2StateSubdivisionLevel      = 0;
	uint32_t      maxOpacity4StateSubdivisionLevel      = 0;
	uint32_t      maxOpacityLossy4StateSubdivisionLevel = 0;
	uint64_t      maxMicromapTriangles                  = 0;
};
struct PhysicalDeviceOpticalFlowFeaturesNV {
	StructureType sType       = StructureType::PhysicalDeviceOpticalFlowFeaturesNV;
	void *        pNext       = nullptr;
	Bool32        opticalFlow = Constants::False;
};
struct PhysicalDeviceOpticalFlowPropertiesNV {
	StructureType              sType                      = StructureType::PhysicalDeviceOpticalFlowPropertiesNV;
	void *                     pNext                      = nullptr;
	OpticalFlowGridSizeFlagsNV supportedOutputGridSizes   = {};
	OpticalFlowGridSizeFlagsNV supportedHintGridSizes     = {};
	Bool32                     hintSupported              = Constants::False;
	Bool32                     costSupported              = Constants::False;
	Bool32                     bidirectionalFlowSupported = Constants::False;
	Bool32                     globalFlowSupported        = Constants::False;
	uint32_t                   minWidth                   = 0;
	uint32_t                   minHeight                  = 0;
	uint32_t                   maxWidth                   = 0;
	uint32_t                   maxHeight                  = 0;
	uint32_t                   maxNumRegionsOfInterest    = 0;
};
struct PhysicalDevicePCIBusInfoPropertiesEXT {
	StructureType sType       = StructureType::PhysicalDevicePciBusInfoPropertiesEXT;
	void *        pNext       = nullptr;
	uint32_t      pciDomain   = 0;
	uint32_t      pciBus      = 0;
	uint32_t      pciDevice   = 0;
	uint32_t      pciFunction = 0;
};
struct PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT {
	StructureType sType                     = StructureType::PhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;
	void *        pNext                     = nullptr;
	Bool32        pageableDeviceLocalMemory = Constants::False;
};
struct PhysicalDevicePartitionedAccelerationStructureFeaturesNV {
	StructureType sType                            = StructureType::PhysicalDevicePartitionedAccelerationStructureFeaturesNV;
	void *        pNext                            = nullptr;
	Bool32        partitionedAccelerationStructure = Constants::False;
};
struct PhysicalDevicePartitionedAccelerationStructurePropertiesNV {
	StructureType sType             = StructureType::PhysicalDevicePartitionedAccelerationStructurePropertiesNV;
	void *        pNext             = nullptr;
	uint32_t      maxPartitionCount = 0;
};
struct PhysicalDevicePerStageDescriptorSetFeaturesNV {
	StructureType sType                 = StructureType::PhysicalDevicePerStageDescriptorSetFeaturesNV;
	void *        pNext                 = nullptr;
	Bool32        perStageDescriptorSet = Constants::False;
	Bool32        dynamicPipelineLayout = Constants::False;
};
struct PhysicalDevicePerformanceCountersByRegionFeaturesARM {
	StructureType sType                       = StructureType::PhysicalDevicePerformanceCountersByRegionFeaturesARM;
	void *        pNext                       = nullptr;
	Bool32        performanceCountersByRegion = Constants::False;
};
struct PhysicalDevicePerformanceQueryFeaturesKHR {
	StructureType sType                                = StructureType::PhysicalDevicePerformanceQueryFeaturesKHR;
	void *        pNext                                = nullptr;
	Bool32        performanceCounterQueryPools         = Constants::False;
	Bool32        performanceCounterMultipleQueryPools = Constants::False;
};
struct PhysicalDevicePerformanceQueryPropertiesKHR {
	StructureType sType                         = StructureType::PhysicalDevicePerformanceQueryPropertiesKHR;
	void *        pNext                         = nullptr;
	Bool32        allowCommandBufferQueryCopies = Constants::False;
};
struct PhysicalDevicePipelineBinaryFeaturesKHR {
	StructureType sType            = StructureType::PhysicalDevicePipelineBinaryFeaturesKHR;
	void *        pNext            = nullptr;
	Bool32        pipelineBinaries = Constants::False;
};
struct PhysicalDevicePipelineBinaryPropertiesKHR {
	StructureType sType                                  = StructureType::PhysicalDevicePipelineBinaryPropertiesKHR;
	void *        pNext                                  = nullptr;
	Bool32        pipelineBinaryInternalCache            = Constants::False;
	Bool32        pipelineBinaryInternalCacheControl     = Constants::False;
	Bool32        pipelineBinaryPrefersInternalCache     = Constants::False;
	Bool32        pipelineBinaryPrecompiledInternalCache = Constants::False;
	Bool32        pipelineBinaryCompressedData           = Constants::False;
};
struct PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC {
	StructureType sType                        = StructureType::PhysicalDevicePipelineCacheIncrementalModeFeaturesSEC;
	void *        pNext                        = nullptr;
	Bool32        pipelineCacheIncrementalMode = Constants::False;
};
struct PhysicalDevicePipelineCreationCacheControlFeatures {
	StructureType sType                        = StructureType::PhysicalDevicePipelineCreationCacheControlFeatures;
	void *        pNext                        = nullptr;
	Bool32        pipelineCreationCacheControl = Constants::False;
};
struct PhysicalDevicePipelineExecutablePropertiesFeaturesKHR {
	StructureType sType                  = StructureType::PhysicalDevicePipelineExecutablePropertiesFeaturesKHR;
	void *        pNext                  = nullptr;
	Bool32        pipelineExecutableInfo = Constants::False;
};
struct PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT {
	StructureType sType                       = StructureType::PhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT;
	void *        pNext                       = nullptr;
	Bool32        pipelineLibraryGroupHandles = Constants::False;
};
struct PhysicalDevicePipelineOpacityMicromapFeaturesARM {
	StructureType sType                   = StructureType::PhysicalDevicePipelineOpacityMicromapFeaturesARM;
	void *        pNext                   = nullptr;
	Bool32        pipelineOpacityMicromap = Constants::False;
};
struct PhysicalDevicePipelinePropertiesFeaturesEXT {
	StructureType sType                        = StructureType::PhysicalDevicePipelinePropertiesFeaturesEXT;
	void *        pNext                        = nullptr;
	Bool32        pipelinePropertiesIdentifier = Constants::False;
};
struct PhysicalDevicePipelineProtectedAccessFeatures {
	StructureType sType                   = StructureType::PhysicalDevicePipelineProtectedAccessFeatures;
	void *        pNext                   = nullptr;
	Bool32        pipelineProtectedAccess = Constants::False;
};
struct PhysicalDevicePipelineRobustnessFeatures {
	StructureType sType              = StructureType::PhysicalDevicePipelineRobustnessFeatures;
	void *        pNext              = nullptr;
	Bool32        pipelineRobustness = Constants::False;
};
struct PhysicalDevicePipelineRobustnessProperties {
	StructureType                    sType                           = StructureType::PhysicalDevicePipelineRobustnessProperties;
	void *                           pNext                           = nullptr;
	PipelineRobustnessBufferBehavior defaultRobustnessStorageBuffers = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessBufferBehavior defaultRobustnessUniformBuffers = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessBufferBehavior defaultRobustnessVertexInputs   = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessImageBehavior  defaultRobustnessImages         = PipelineRobustnessImageBehavior::DeviceDefault;
};
struct PhysicalDevicePointClippingProperties {
	StructureType         sType                 = StructureType::PhysicalDevicePointClippingProperties;
	void *                pNext                 = nullptr;
	PointClippingBehavior pointClippingBehavior = PointClippingBehavior::AllClipPlanes;
};
struct PhysicalDevicePresentBarrierFeaturesNV {
	StructureType sType          = StructureType::PhysicalDevicePresentBarrierFeaturesNV;
	void *        pNext          = nullptr;
	Bool32        presentBarrier = Constants::False;
};
struct PhysicalDevicePresentId2FeaturesKHR {
	StructureType sType      = StructureType::PhysicalDevicePresentId2FeaturesKHR;
	void *        pNext      = nullptr;
	Bool32        presentId2 = Constants::False;
};
struct PhysicalDevicePresentIdFeaturesKHR {
	StructureType sType     = StructureType::PhysicalDevicePresentIdFeaturesKHR;
	void *        pNext     = nullptr;
	Bool32        presentId = Constants::False;
};
struct PhysicalDevicePresentMeteringFeaturesNV {
	StructureType sType           = StructureType::PhysicalDevicePresentMeteringFeaturesNV;
	void *        pNext           = nullptr;
	Bool32        presentMetering = Constants::False;
};
struct PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR {
	StructureType sType                      = StructureType::PhysicalDevicePresentModeFifoLatestReadyFeaturesKHR;
	void *        pNext                      = nullptr;
	Bool32        presentModeFifoLatestReady = Constants::False;
};
struct PhysicalDevicePresentTimingFeaturesEXT {
	StructureType sType                 = StructureType::PhysicalDevicePresentTimingFeaturesEXT;
	void *        pNext                 = nullptr;
	Bool32        presentTiming         = Constants::False;
	Bool32        presentAtAbsoluteTime = Constants::False;
	Bool32        presentAtRelativeTime = Constants::False;
};
struct PhysicalDevicePresentWait2FeaturesKHR {
	StructureType sType        = StructureType::PhysicalDevicePresentWait2FeaturesKHR;
	void *        pNext        = nullptr;
	Bool32        presentWait2 = Constants::False;
};
struct PhysicalDevicePresentWaitFeaturesKHR {
	StructureType sType       = StructureType::PhysicalDevicePresentWaitFeaturesKHR;
	void *        pNext       = nullptr;
	Bool32        presentWait = Constants::False;
};
struct PhysicalDevicePrimitiveRestartIndexFeaturesEXT {
	StructureType sType                 = StructureType::PhysicalDevicePrimitiveRestartIndexFeaturesEXT;
	void *        pNext                 = nullptr;
	Bool32        primitiveRestartIndex = Constants::False;
};
struct PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT {
	StructureType sType                             = StructureType::PhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;
	void *        pNext                             = nullptr;
	Bool32        primitiveTopologyListRestart      = Constants::False;
	Bool32        primitiveTopologyPatchListRestart = Constants::False;
};
struct PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT {
	StructureType sType                                         = StructureType::PhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;
	void *        pNext                                         = nullptr;
	Bool32        primitivesGeneratedQuery                      = Constants::False;
	Bool32        primitivesGeneratedQueryWithRasterizerDiscard = Constants::False;
	Bool32        primitivesGeneratedQueryWithNonZeroStreams    = Constants::False;
};
struct PhysicalDevicePrivateDataBaseHandleFeaturesNV {
	StructureType sType                 = StructureType::PhysicalDevicePrivateDataBaseHandleFeaturesNV;
	void *        pNext                 = nullptr;
	Bool32        privateDataBaseHandle = Constants::False;
};
struct PhysicalDevicePrivateDataFeatures {
	StructureType sType       = StructureType::PhysicalDevicePrivateDataFeatures;
	void *        pNext       = nullptr;
	Bool32        privateData = Constants::False;
};
struct PhysicalDeviceProtectedMemoryFeatures {
	StructureType sType           = StructureType::PhysicalDeviceProtectedMemoryFeatures;
	void *        pNext           = nullptr;
	Bool32        protectedMemory = Constants::False;
};
struct PhysicalDeviceProtectedMemoryProperties {
	StructureType sType            = StructureType::PhysicalDeviceProtectedMemoryProperties;
	void *        pNext            = nullptr;
	Bool32        protectedNoFault = Constants::False;
};
struct PhysicalDeviceProvokingVertexFeaturesEXT {
	StructureType sType                                     = StructureType::PhysicalDeviceProvokingVertexFeaturesEXT;
	void *        pNext                                     = nullptr;
	Bool32        provokingVertexLast                       = Constants::False;
	Bool32        transformFeedbackPreservesProvokingVertex = Constants::False;
};
struct PhysicalDeviceProvokingVertexPropertiesEXT {
	StructureType sType                                                = StructureType::PhysicalDeviceProvokingVertexPropertiesEXT;
	void *        pNext                                                = nullptr;
	Bool32        provokingVertexModePerPipeline                       = Constants::False;
	Bool32        transformFeedbackPreservesTriangleFanProvokingVertex = Constants::False;
};
struct PhysicalDevicePushConstantBankFeaturesNV {
	StructureType sType            = StructureType::PhysicalDevicePushConstantBankFeaturesNV;
	void *        pNext            = nullptr;
	Bool32        pushConstantBank = Constants::False;
};
struct PhysicalDevicePushConstantBankPropertiesNV {
	StructureType sType                        = StructureType::PhysicalDevicePushConstantBankPropertiesNV;
	void *        pNext                        = nullptr;
	uint32_t      maxGraphicsPushConstantBanks = 0;
	uint32_t      maxComputePushConstantBanks  = 0;
	uint32_t      maxGraphicsPushDataBanks     = 0;
	uint32_t      maxComputePushDataBanks      = 0;
};
struct PhysicalDevicePushDescriptorProperties {
	StructureType sType              = StructureType::PhysicalDevicePushDescriptorProperties;
	void *        pNext              = nullptr;
	uint32_t      maxPushDescriptors = 0;
};
struct PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM {
	StructureType                                  sType            = StructureType::PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM;
	const void *                                   pNext            = nullptr;
	uint32_t                                       queueFamilyIndex = 0;
	PhysicalDeviceDataGraphProcessingEngineTypeARM engineType       = PhysicalDeviceDataGraphProcessingEngineTypeARM::Default;
};
struct PhysicalDeviceQueuePerfHintFeaturesQCOM {
	StructureType sType         = StructureType::PhysicalDeviceQueuePerfHintFeaturesQCOM;
	void *        pNext         = nullptr;
	Bool32        queuePerfHint = Constants::False;
};
struct PhysicalDeviceQueuePerfHintPropertiesQCOM {
	StructureType sType           = StructureType::PhysicalDeviceQueuePerfHintPropertiesQCOM;
	void *        pNext           = nullptr;
	QueueFlags    supportedQueues = {};
};
struct PhysicalDeviceRGBA10X6FormatsFeaturesEXT {
	StructureType sType                             = StructureType::PhysicalDeviceRgba10x6FormatsFeaturesEXT;
	void *        pNext                             = nullptr;
	Bool32        formatRgba10x6WithoutYCbCrSampler = Constants::False;
};
struct PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT {
	StructureType sType                                     = StructureType::PhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;
	void *        pNext                                     = nullptr;
	Bool32        rasterizationOrderColorAttachmentAccess   = Constants::False;
	Bool32        rasterizationOrderDepthAttachmentAccess   = Constants::False;
	Bool32        rasterizationOrderStencilAttachmentAccess = Constants::False;
};
struct PhysicalDeviceRawAccessChainsFeaturesNV {
	StructureType sType                 = StructureType::PhysicalDeviceRawAccessChainsFeaturesNV;
	void *        pNext                 = nullptr;
	Bool32        shaderRawAccessChains = Constants::False;
};
struct PhysicalDeviceRayQueryFeaturesKHR {
	StructureType sType    = StructureType::PhysicalDeviceRayQueryFeaturesKHR;
	void *        pNext    = nullptr;
	Bool32        rayQuery = Constants::False;
};
struct PhysicalDeviceRayTracingInvocationReorderFeaturesEXT {
	StructureType sType                       = StructureType::PhysicalDeviceRayTracingInvocationReorderFeaturesEXT;
	void *        pNext                       = nullptr;
	Bool32        rayTracingInvocationReorder = Constants::False;
};
struct PhysicalDeviceRayTracingInvocationReorderFeaturesNV {
	StructureType sType                       = StructureType::PhysicalDeviceRayTracingInvocationReorderFeaturesNV;
	void *        pNext                       = nullptr;
	Bool32        rayTracingInvocationReorder = Constants::False;
};
struct PhysicalDeviceRayTracingInvocationReorderPropertiesEXT {
	StructureType                      sType                                     = StructureType::PhysicalDeviceRayTracingInvocationReorderPropertiesEXT;
	void *                             pNext                                     = nullptr;
	RayTracingInvocationReorderModeEXT rayTracingInvocationReorderReorderingHint = RayTracingInvocationReorderModeEXT::None;
	uint32_t                           maxShaderBindingTableRecordIndex          = 0;
};
struct PhysicalDeviceRayTracingInvocationReorderPropertiesNV {
	StructureType                      sType                                     = StructureType::PhysicalDeviceRayTracingInvocationReorderPropertiesNV;
	void *                             pNext                                     = nullptr;
	RayTracingInvocationReorderModeEXT rayTracingInvocationReorderReorderingHint = RayTracingInvocationReorderModeEXT::None;
};
struct PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV {
	StructureType sType              = StructureType::PhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV;
	void *        pNext              = nullptr;
	Bool32        spheres            = Constants::False;
	Bool32        linearSweptSpheres = Constants::False;
};
struct PhysicalDeviceRayTracingMaintenance1FeaturesKHR {
	StructureType sType                                = StructureType::PhysicalDeviceRayTracingMaintenance1FeaturesKHR;
	void *        pNext                                = nullptr;
	Bool32        rayTracingMaintenance1               = Constants::False;
	Bool32        rayTracingPipelineTraceRaysIndirect2 = Constants::False;
};
struct PhysicalDeviceRayTracingMotionBlurFeaturesNV {
	StructureType sType                                         = StructureType::PhysicalDeviceRayTracingMotionBlurFeaturesNV;
	void *        pNext                                         = nullptr;
	Bool32        rayTracingMotionBlur                          = Constants::False;
	Bool32        rayTracingMotionBlurPipelineTraceRaysIndirect = Constants::False;
};
struct PhysicalDeviceRayTracingPipelineFeaturesKHR {
	StructureType sType                                                 = StructureType::PhysicalDeviceRayTracingPipelineFeaturesKHR;
	void *        pNext                                                 = nullptr;
	Bool32        rayTracingPipeline                                    = Constants::False;
	Bool32        rayTracingPipelineShaderGroupHandleCaptureReplay      = Constants::False;
	Bool32        rayTracingPipelineShaderGroupHandleCaptureReplayMixed = Constants::False;
	Bool32        rayTracingPipelineTraceRaysIndirect                   = Constants::False;
	Bool32        rayTraversalPrimitiveCulling                          = Constants::False;
};
struct PhysicalDeviceRayTracingPipelinePropertiesKHR {
	StructureType sType                              = StructureType::PhysicalDeviceRayTracingPipelinePropertiesKHR;
	void *        pNext                              = nullptr;
	uint32_t      shaderGroupHandleSize              = 0;
	uint32_t      maxRayRecursionDepth               = 0;
	uint32_t      maxShaderGroupStride               = 0;
	uint32_t      shaderGroupBaseAlignment           = 0;
	uint32_t      shaderGroupHandleCaptureReplaySize = 0;
	uint32_t      maxRayDispatchInvocationCount      = 0;
	uint32_t      shaderGroupHandleAlignment         = 0;
	uint32_t      maxRayHitAttributeSize             = 0;
};
struct PhysicalDeviceRayTracingPositionFetchFeaturesKHR {
	StructureType sType                   = StructureType::PhysicalDeviceRayTracingPositionFetchFeaturesKHR;
	void *        pNext                   = nullptr;
	Bool32        rayTracingPositionFetch = Constants::False;
};
struct PhysicalDeviceRayTracingPropertiesNV {
	StructureType sType                                  = StructureType::PhysicalDeviceRayTracingPropertiesNV;
	void *        pNext                                  = nullptr;
	uint32_t      shaderGroupHandleSize                  = 0;
	uint32_t      maxRecursionDepth                      = 0;
	uint32_t      maxShaderGroupStride                   = 0;
	uint32_t      shaderGroupBaseAlignment               = 0;
	uint64_t      maxGeometryCount                       = 0;
	uint64_t      maxInstanceCount                       = 0;
	uint64_t      maxTriangleCount                       = 0;
	uint32_t      maxDescriptorSetAccelerationStructures = 0;
};
struct PhysicalDeviceRayTracingValidationFeaturesNV {
	StructureType sType                = StructureType::PhysicalDeviceRayTracingValidationFeaturesNV;
	void *        pNext                = nullptr;
	Bool32        rayTracingValidation = Constants::False;
};
struct PhysicalDeviceRelaxedLineRasterizationFeaturesIMG {
	StructureType sType                    = StructureType::PhysicalDeviceRelaxedLineRasterizationFeaturesIMG;
	void *        pNext                    = nullptr;
	Bool32        relaxedLineRasterization = Constants::False;
};
struct PhysicalDeviceRenderPassStripedFeaturesARM {
	StructureType sType             = StructureType::PhysicalDeviceRenderPassStripedFeaturesARM;
	void *        pNext             = nullptr;
	Bool32        renderPassStriped = Constants::False;
};
struct PhysicalDeviceRepresentativeFragmentTestFeaturesNV {
	StructureType sType                      = StructureType::PhysicalDeviceRepresentativeFragmentTestFeaturesNV;
	void *        pNext                      = nullptr;
	Bool32        representativeFragmentTest = Constants::False;
};
struct PhysicalDeviceRobustness2FeaturesKHR {
	StructureType sType               = StructureType::PhysicalDeviceRobustness2FeaturesKHR;
	void *        pNext               = nullptr;
	Bool32        robustBufferAccess2 = Constants::False;
	Bool32        robustImageAccess2  = Constants::False;
	Bool32        nullDescriptor      = Constants::False;
};
struct PhysicalDeviceRobustness2PropertiesKHR {
	StructureType sType                                  = StructureType::PhysicalDeviceRobustness2PropertiesKHR;
	void *        pNext                                  = nullptr;
	DeviceSize    robustStorageBufferAccessSizeAlignment = 0;
	DeviceSize    robustUniformBufferAccessSizeAlignment = 0;
};
struct PhysicalDeviceSamplerFilterMinmaxProperties {
	StructureType sType                              = StructureType::PhysicalDeviceSamplerFilterMinmaxProperties;
	void *        pNext                              = nullptr;
	Bool32        filterMinmaxSingleComponentFormats = Constants::False;
	Bool32        filterMinmaxImageComponentMapping  = Constants::False;
};
struct PhysicalDeviceSamplerYcbcrConversionFeatures {
	StructureType sType                  = StructureType::PhysicalDeviceSamplerYcbcrConversionFeatures;
	void *        pNext                  = nullptr;
	Bool32        samplerYcbcrConversion = Constants::False;
};
struct PhysicalDeviceScalarBlockLayoutFeatures {
	StructureType sType             = StructureType::PhysicalDeviceScalarBlockLayoutFeatures;
	void *        pNext             = nullptr;
	Bool32        scalarBlockLayout = Constants::False;
};
struct PhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM {
	StructureType sType                                   = StructureType::PhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM;
	void *        pNext                                   = nullptr;
	uint32_t      schedulingControlsMaxWarpsCount         = 0;
	uint32_t      schedulingControlsMaxQueuedBatchesCount = 0;
	uint32_t      schedulingControlsMaxWorkGroupBatchSize = 0;
};
struct PhysicalDeviceSchedulingControlsFeaturesARM {
	StructureType sType              = StructureType::PhysicalDeviceSchedulingControlsFeaturesARM;
	void *        pNext              = nullptr;
	Bool32        schedulingControls = Constants::False;
};
struct PhysicalDeviceSchedulingControlsPropertiesARM {
	StructureType                            sType                   = StructureType::PhysicalDeviceSchedulingControlsPropertiesARM;
	void *                                   pNext                   = nullptr;
	PhysicalDeviceSchedulingControlsFlagsARM schedulingControlsFlags = {};
};
struct PhysicalDeviceSeparateDepthStencilLayoutsFeatures {
	StructureType sType                       = StructureType::PhysicalDeviceSeparateDepthStencilLayoutsFeatures;
	void *        pNext                       = nullptr;
	Bool32        separateDepthStencilLayouts = Constants::False;
};
struct PhysicalDeviceShader64BitIndexingFeaturesEXT {
	StructureType sType               = StructureType::PhysicalDeviceShader64BitIndexingFeaturesEXT;
	void *        pNext               = nullptr;
	Bool32        shader64BitIndexing = Constants::False;
};
struct PhysicalDeviceShaderAbortFeaturesKHR {
	StructureType sType       = StructureType::PhysicalDeviceShaderAbortFeaturesKHR;
	void *        pNext       = nullptr;
	Bool32        shaderAbort = Constants::False;
};
struct PhysicalDeviceShaderAbortPropertiesKHR {
	StructureType sType                     = StructureType::PhysicalDeviceShaderAbortPropertiesKHR;
	void *        pNext                     = nullptr;
	uint64_t      maxShaderAbortMessageSize = 0;
};
struct PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV {
	StructureType sType                      = StructureType::PhysicalDeviceShaderAtomicFloat16VectorFeaturesNV;
	void *        pNext                      = nullptr;
	Bool32        shaderFloat16VectorAtomics = Constants::False;
};
struct PhysicalDeviceShaderAtomicFloat2FeaturesEXT {
	StructureType sType                           = StructureType::PhysicalDeviceShaderAtomicFloat2FeaturesEXT;
	void *        pNext                           = nullptr;
	Bool32        shaderBufferFloat16Atomics      = Constants::False;
	Bool32        shaderBufferFloat16AtomicAdd    = Constants::False;
	Bool32        shaderBufferFloat16AtomicMinMax = Constants::False;
	Bool32        shaderBufferFloat32AtomicMinMax = Constants::False;
	Bool32        shaderBufferFloat64AtomicMinMax = Constants::False;
	Bool32        shaderSharedFloat16Atomics      = Constants::False;
	Bool32        shaderSharedFloat16AtomicAdd    = Constants::False;
	Bool32        shaderSharedFloat16AtomicMinMax = Constants::False;
	Bool32        shaderSharedFloat32AtomicMinMax = Constants::False;
	Bool32        shaderSharedFloat64AtomicMinMax = Constants::False;
	Bool32        shaderImageFloat32AtomicMinMax  = Constants::False;
	Bool32        sparseImageFloat32AtomicMinMax  = Constants::False;
};
struct PhysicalDeviceShaderAtomicFloatFeaturesEXT {
	StructureType sType                        = StructureType::PhysicalDeviceShaderAtomicFloatFeaturesEXT;
	void *        pNext                        = nullptr;
	Bool32        shaderBufferFloat32Atomics   = Constants::False;
	Bool32        shaderBufferFloat32AtomicAdd = Constants::False;
	Bool32        shaderBufferFloat64Atomics   = Constants::False;
	Bool32        shaderBufferFloat64AtomicAdd = Constants::False;
	Bool32        shaderSharedFloat32Atomics   = Constants::False;
	Bool32        shaderSharedFloat32AtomicAdd = Constants::False;
	Bool32        shaderSharedFloat64Atomics   = Constants::False;
	Bool32        shaderSharedFloat64AtomicAdd = Constants::False;
	Bool32        shaderImageFloat32Atomics    = Constants::False;
	Bool32        shaderImageFloat32AtomicAdd  = Constants::False;
	Bool32        sparseImageFloat32Atomics    = Constants::False;
	Bool32        sparseImageFloat32AtomicAdd  = Constants::False;
};
struct PhysicalDeviceShaderAtomicInt64Features {
	StructureType sType                    = StructureType::PhysicalDeviceShaderAtomicInt64Features;
	void *        pNext                    = nullptr;
	Bool32        shaderBufferInt64Atomics = Constants::False;
	Bool32        shaderSharedInt64Atomics = Constants::False;
};
struct PhysicalDeviceShaderBfloat16FeaturesKHR {
	StructureType sType                           = StructureType::PhysicalDeviceShaderBfloat16FeaturesKHR;
	void *        pNext                           = nullptr;
	Bool32        shaderBFloat16Type              = Constants::False;
	Bool32        shaderBFloat16DotProduct        = Constants::False;
	Bool32        shaderBFloat16CooperativeMatrix = Constants::False;
};
struct PhysicalDeviceShaderClockFeaturesKHR {
	StructureType sType               = StructureType::PhysicalDeviceShaderClockFeaturesKHR;
	void *        pNext               = nullptr;
	Bool32        shaderSubgroupClock = Constants::False;
	Bool32        shaderDeviceClock   = Constants::False;
};
struct PhysicalDeviceShaderConstantDataFeaturesKHR {
	StructureType sType              = StructureType::PhysicalDeviceShaderConstantDataFeaturesKHR;
	void *        pNext              = nullptr;
	Bool32        shaderConstantData = Constants::False;
};
struct PhysicalDeviceShaderCoreBuiltinsFeaturesARM {
	StructureType sType              = StructureType::PhysicalDeviceShaderCoreBuiltinsFeaturesARM;
	void *        pNext              = nullptr;
	Bool32        shaderCoreBuiltins = Constants::False;
};
struct PhysicalDeviceShaderCoreBuiltinsPropertiesARM {
	StructureType sType              = StructureType::PhysicalDeviceShaderCoreBuiltinsPropertiesARM;
	void *        pNext              = nullptr;
	uint64_t      shaderCoreMask     = 0;
	uint32_t      shaderCoreCount    = 0;
	uint32_t      shaderWarpsPerCore = 0;
};
struct PhysicalDeviceShaderCoreProperties2AMD {
	StructureType                sType                  = StructureType::PhysicalDeviceShaderCoreProperties2AMD;
	void *                       pNext                  = nullptr;
	ShaderCorePropertiesFlagsAMD shaderCoreFeatures     = {};
	uint32_t                     activeComputeUnitCount = 0;
};
struct PhysicalDeviceShaderCorePropertiesAMD {
	StructureType sType                      = StructureType::PhysicalDeviceShaderCorePropertiesAMD;
	void *        pNext                      = nullptr;
	uint32_t      shaderEngineCount          = 0;
	uint32_t      shaderArraysPerEngineCount = 0;
	uint32_t      computeUnitsPerShaderArray = 0;
	uint32_t      simdPerComputeUnit         = 0;
	uint32_t      wavefrontsPerSimd          = 0;
	uint32_t      wavefrontSize              = 0;
	uint32_t      sgprsPerSimd               = 0;
	uint32_t      minSgprAllocation          = 0;
	uint32_t      maxSgprAllocation          = 0;
	uint32_t      sgprAllocationGranularity  = 0;
	uint32_t      vgprsPerSimd               = 0;
	uint32_t      minVgprAllocation          = 0;
	uint32_t      maxVgprAllocation          = 0;
	uint32_t      vgprAllocationGranularity  = 0;
};
struct PhysicalDeviceShaderCorePropertiesARM {
	StructureType sType     = StructureType::PhysicalDeviceShaderCorePropertiesARM;
	void *        pNext     = nullptr;
	uint32_t      pixelRate = 0;
	uint32_t      texelRate = 0;
	uint32_t      fmaRate   = 0;
};
struct PhysicalDeviceShaderDemoteToHelperInvocationFeatures {
	StructureType sType                          = StructureType::PhysicalDeviceShaderDemoteToHelperInvocationFeatures;
	void *        pNext                          = nullptr;
	Bool32        shaderDemoteToHelperInvocation = Constants::False;
};
struct PhysicalDeviceShaderDrawParametersFeatures {
	StructureType sType                = StructureType::PhysicalDeviceShaderDrawParametersFeatures;
	void *        pNext                = nullptr;
	Bool32        shaderDrawParameters = Constants::False;
};
struct PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD {
	StructureType sType                           = StructureType::PhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;
	void *        pNext                           = nullptr;
	Bool32        shaderEarlyAndLateFragmentTests = Constants::False;
};
struct PhysicalDeviceShaderExpectAssumeFeatures {
	StructureType sType              = StructureType::PhysicalDeviceShaderExpectAssumeFeatures;
	void *        pNext              = nullptr;
	Bool32        shaderExpectAssume = Constants::False;
};
struct PhysicalDeviceShaderFloat16Int8Features {
	StructureType sType         = StructureType::PhysicalDeviceShaderFloat16Int8Features;
	void *        pNext         = nullptr;
	Bool32        shaderFloat16 = Constants::False;
	Bool32        shaderInt8    = Constants::False;
};
struct PhysicalDeviceShaderFloat8FeaturesEXT {
	StructureType sType                         = StructureType::PhysicalDeviceShaderFloat8FeaturesEXT;
	void *        pNext                         = nullptr;
	Bool32        shaderFloat8                  = Constants::False;
	Bool32        shaderFloat8CooperativeMatrix = Constants::False;
};
struct PhysicalDeviceShaderFloatControls2Features {
	StructureType sType                = StructureType::PhysicalDeviceShaderFloatControls2Features;
	void *        pNext                = nullptr;
	Bool32        shaderFloatControls2 = Constants::False;
};
struct PhysicalDeviceShaderFmaFeaturesKHR {
	StructureType sType            = StructureType::PhysicalDeviceShaderFmaFeaturesKHR;
	void *        pNext            = nullptr;
	Bool32        shaderFmaFloat16 = Constants::False;
	Bool32        shaderFmaFloat32 = Constants::False;
	Bool32        shaderFmaFloat64 = Constants::False;
};
struct PhysicalDeviceShaderImageAtomicInt64FeaturesEXT {
	StructureType sType                   = StructureType::PhysicalDeviceShaderImageAtomicInt64FeaturesEXT;
	void *        pNext                   = nullptr;
	Bool32        shaderImageInt64Atomics = Constants::False;
	Bool32        sparseImageInt64Atomics = Constants::False;
};
struct PhysicalDeviceShaderImageFootprintFeaturesNV {
	StructureType sType          = StructureType::PhysicalDeviceShaderImageFootprintFeaturesNV;
	void *        pNext          = nullptr;
	Bool32        imageFootprint = Constants::False;
};
struct PhysicalDeviceShaderInstrumentationFeaturesARM {
	StructureType sType                 = StructureType::PhysicalDeviceShaderInstrumentationFeaturesARM;
	void *        pNext                 = nullptr;
	Bool32        shaderInstrumentation = Constants::False;
};
struct PhysicalDeviceShaderInstrumentationPropertiesARM {
	StructureType sType                    = StructureType::PhysicalDeviceShaderInstrumentationPropertiesARM;
	void *        pNext                    = nullptr;
	uint32_t      numMetrics               = 0;
	Bool32        perBasicBlockGranularity = Constants::False;
};
struct PhysicalDeviceShaderIntegerDotProductFeatures {
	StructureType sType                   = StructureType::PhysicalDeviceShaderIntegerDotProductFeatures;
	void *        pNext                   = nullptr;
	Bool32        shaderIntegerDotProduct = Constants::False;
};
struct PhysicalDeviceShaderIntegerDotProductProperties {
	StructureType sType                                                                         = StructureType::PhysicalDeviceShaderIntegerDotProductProperties;
	void *        pNext                                                                         = nullptr;
	Bool32        integerDotProduct8BitUnsignedAccelerated                                      = Constants::False;
	Bool32        integerDotProduct8BitSignedAccelerated                                        = Constants::False;
	Bool32        integerDotProduct8BitMixedSignednessAccelerated                               = Constants::False;
	Bool32        integerDotProduct4x8BitPackedUnsignedAccelerated                              = Constants::False;
	Bool32        integerDotProduct4x8BitPackedSignedAccelerated                                = Constants::False;
	Bool32        integerDotProduct4x8BitPackedMixedSignednessAccelerated                       = Constants::False;
	Bool32        integerDotProduct16BitUnsignedAccelerated                                     = Constants::False;
	Bool32        integerDotProduct16BitSignedAccelerated                                       = Constants::False;
	Bool32        integerDotProduct16BitMixedSignednessAccelerated                              = Constants::False;
	Bool32        integerDotProduct32BitUnsignedAccelerated                                     = Constants::False;
	Bool32        integerDotProduct32BitSignedAccelerated                                       = Constants::False;
	Bool32        integerDotProduct32BitMixedSignednessAccelerated                              = Constants::False;
	Bool32        integerDotProduct64BitUnsignedAccelerated                                     = Constants::False;
	Bool32        integerDotProduct64BitSignedAccelerated                                       = Constants::False;
	Bool32        integerDotProduct64BitMixedSignednessAccelerated                              = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating8BitUnsignedAccelerated                = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating8BitSignedAccelerated                  = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated         = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated        = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated          = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating16BitUnsignedAccelerated               = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating16BitSignedAccelerated                 = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated        = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating32BitUnsignedAccelerated               = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating32BitSignedAccelerated                 = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated        = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating64BitUnsignedAccelerated               = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating64BitSignedAccelerated                 = Constants::False;
	Bool32        integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated        = Constants::False;
};
struct PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL {
	StructureType sType                   = StructureType::PhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;
	void *        pNext                   = nullptr;
	Bool32        shaderIntegerFunctions2 = Constants::False;
};
struct PhysicalDeviceShaderLongVectorFeaturesEXT {
	StructureType sType      = StructureType::PhysicalDeviceShaderLongVectorFeaturesEXT;
	void *        pNext      = nullptr;
	Bool32        longVector = Constants::False;
};
struct PhysicalDeviceShaderLongVectorPropertiesEXT {
	StructureType sType               = StructureType::PhysicalDeviceShaderLongVectorPropertiesEXT;
	void *        pNext               = nullptr;
	uint32_t      maxVectorComponents = 0;
};
struct PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR {
	StructureType sType                      = StructureType::PhysicalDeviceShaderMaximalReconvergenceFeaturesKHR;
	void *        pNext                      = nullptr;
	Bool32        shaderMaximalReconvergence = Constants::False;
};
struct PhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE {
	StructureType sType                                       = StructureType::PhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE;
	void *        pNext                                       = nullptr;
	Bool32        shaderMixedFloatDotProductFloat16AccFloat32 = Constants::False;
	Bool32        shaderMixedFloatDotProductFloat16AccFloat16 = Constants::False;
	Bool32        shaderMixedFloatDotProductBFloat16Acc       = Constants::False;
	Bool32        shaderMixedFloatDotProductFloat8AccFloat32  = Constants::False;
};
struct PhysicalDeviceShaderModuleIdentifierFeaturesEXT {
	StructureType sType                  = StructureType::PhysicalDeviceShaderModuleIdentifierFeaturesEXT;
	void *        pNext                  = nullptr;
	Bool32        shaderModuleIdentifier = Constants::False;
};
struct PhysicalDeviceShaderModuleIdentifierPropertiesEXT {
	StructureType                            sType                               = StructureType::PhysicalDeviceShaderModuleIdentifierPropertiesEXT;
	void *                                   pNext                               = nullptr;
	std::array<uint8_t, Constants::UuidSize> shaderModuleIdentifierAlgorithmUUID = {};
};
struct PhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM {
	StructureType sType                    = StructureType::PhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM;
	void *        pNext                    = nullptr;
	Bool32        shaderMultipleWaitQueues = Constants::False;
};
struct PhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM {
	StructureType sType               = StructureType::PhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM;
	void *        pNext               = nullptr;
	uint32_t      maxShaderWaitQueues = 0;
};
struct PhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT {
	StructureType sType                    = StructureType::PhysicalDeviceShaderOcpMicroscalingTypesFeaturesEXT;
	void *        pNext                    = nullptr;
	Bool32        shaderFloat4             = Constants::False;
	Bool32        shaderFloat6             = Constants::False;
	Bool32        shaderFloat8UnsignedE8M0 = Constants::False;
	Bool32        shaderMXInt8             = Constants::False;
};
struct PhysicalDeviceShaderObjectFeaturesEXT {
	StructureType sType        = StructureType::PhysicalDeviceShaderObjectFeaturesEXT;
	void *        pNext        = nullptr;
	Bool32        shaderObject = Constants::False;
};
struct PhysicalDeviceShaderObjectPropertiesEXT {
	StructureType                            sType               = StructureType::PhysicalDeviceShaderObjectPropertiesEXT;
	void *                                   pNext               = nullptr;
	std::array<uint8_t, Constants::UuidSize> shaderBinaryUUID    = {};
	uint32_t                                 shaderBinaryVersion = 0;
};
struct PhysicalDeviceShaderQuadControlFeaturesKHR {
	StructureType sType             = StructureType::PhysicalDeviceShaderQuadControlFeaturesKHR;
	void *        pNext             = nullptr;
	Bool32        shaderQuadControl = Constants::False;
};
struct PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR {
	StructureType sType                            = StructureType::PhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR;
	void *        pNext                            = nullptr;
	Bool32        shaderRelaxedExtendedInstruction = Constants::False;
};
struct PhysicalDeviceShaderReplicatedCompositesFeaturesEXT {
	StructureType sType                      = StructureType::PhysicalDeviceShaderReplicatedCompositesFeaturesEXT;
	void *        pNext                      = nullptr;
	Bool32        shaderReplicatedComposites = Constants::False;
};
struct PhysicalDeviceShaderSMBuiltinsFeaturesNV {
	StructureType sType            = StructureType::PhysicalDeviceShaderSmBuiltinsFeaturesNV;
	void *        pNext            = nullptr;
	Bool32        shaderSMBuiltins = Constants::False;
};
struct PhysicalDeviceShaderSMBuiltinsPropertiesNV {
	StructureType sType            = StructureType::PhysicalDeviceShaderSmBuiltinsPropertiesNV;
	void *        pNext            = nullptr;
	uint32_t      shaderSMCount    = 0;
	uint32_t      shaderWarpsPerSM = 0;
};
struct PhysicalDeviceShaderSplitBarrierFeaturesEXT {
	StructureType sType              = StructureType::PhysicalDeviceShaderSplitBarrierFeaturesEXT;
	void *        pNext              = nullptr;
	Bool32        shaderSplitBarrier = Constants::False;
};
struct PhysicalDeviceShaderSplitBarrierPropertiesEXT {
	StructureType sType                            = StructureType::PhysicalDeviceShaderSplitBarrierPropertiesEXT;
	void *        pNext                            = nullptr;
	uint32_t      splitBarrierReservedSharedMemory = 0;
};
struct PhysicalDeviceShaderSubgroupExtendedTypesFeatures {
	StructureType sType                       = StructureType::PhysicalDeviceShaderSubgroupExtendedTypesFeatures;
	void *        pNext                       = nullptr;
	Bool32        shaderSubgroupExtendedTypes = Constants::False;
};
struct PhysicalDeviceShaderSubgroupPartitionedFeaturesEXT {
	StructureType sType                     = StructureType::PhysicalDeviceShaderSubgroupPartitionedFeaturesEXT;
	void *        pNext                     = nullptr;
	Bool32        shaderSubgroupPartitioned = Constants::False;
};
struct PhysicalDeviceShaderSubgroupRotateFeatures {
	StructureType sType                         = StructureType::PhysicalDeviceShaderSubgroupRotateFeatures;
	void *        pNext                         = nullptr;
	Bool32        shaderSubgroupRotate          = Constants::False;
	Bool32        shaderSubgroupRotateClustered = Constants::False;
};
struct PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR {
	StructureType sType                            = StructureType::PhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;
	void *        pNext                            = nullptr;
	Bool32        shaderSubgroupUniformControlFlow = Constants::False;
};
struct PhysicalDeviceShaderTerminateInvocationFeatures {
	StructureType sType                     = StructureType::PhysicalDeviceShaderTerminateInvocationFeatures;
	void *        pNext                     = nullptr;
	Bool32        shaderTerminateInvocation = Constants::False;
};
struct PhysicalDeviceShaderTileImageFeaturesEXT {
	StructureType sType                            = StructureType::PhysicalDeviceShaderTileImageFeaturesEXT;
	void *        pNext                            = nullptr;
	Bool32        shaderTileImageColorReadAccess   = Constants::False;
	Bool32        shaderTileImageDepthReadAccess   = Constants::False;
	Bool32        shaderTileImageStencilReadAccess = Constants::False;
};
struct PhysicalDeviceShaderTileImagePropertiesEXT {
	StructureType sType                                            = StructureType::PhysicalDeviceShaderTileImagePropertiesEXT;
	void *        pNext                                            = nullptr;
	Bool32        shaderTileImageCoherentReadAccelerated           = Constants::False;
	Bool32        shaderTileImageReadSampleFromPixelRateInvocation = Constants::False;
	Bool32        shaderTileImageReadFromHelperInvocation          = Constants::False;
};
struct PhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT {
	StructureType sType                           = StructureType::PhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT;
	void *        pNext                           = nullptr;
	Bool32        shaderUniformBufferUnsizedArray = Constants::False;
};
struct PhysicalDeviceShaderUntypedPointersFeaturesKHR {
	StructureType sType                 = StructureType::PhysicalDeviceShaderUntypedPointersFeaturesKHR;
	void *        pNext                 = nullptr;
	Bool32        shaderUntypedPointers = Constants::False;
};
struct PhysicalDeviceShadingRateImageFeaturesNV {
	StructureType sType                        = StructureType::PhysicalDeviceShadingRateImageFeaturesNV;
	void *        pNext                        = nullptr;
	Bool32        shadingRateImage             = Constants::False;
	Bool32        shadingRateCoarseSampleOrder = Constants::False;
};
struct PhysicalDeviceSparseImageFormatInfo2 {
	StructureType   sType   = StructureType::PhysicalDeviceSparseImageFormatInfo2;
	const void *    pNext   = nullptr;
	Format          format  = Format::Undefined;
	ImageType       type    = ImageType::v1D;
	SampleCountBits samples = SampleCountBits::v1;
	ImageUsageFlags usage   = {};
	ImageTiling     tiling  = ImageTiling::Optimal;
};
struct PhysicalDeviceSparseProperties {
	Bool32 residencyStandard2DBlockShape            = Constants::False;
	Bool32 residencyStandard2DMultisampleBlockShape = Constants::False;
	Bool32 residencyStandard3DBlockShape            = Constants::False;
	Bool32 residencyAlignedMipSize                  = Constants::False;
	Bool32 residencyNonResidentStrict               = Constants::False;
};
struct PhysicalDeviceSubgroupProperties {
	StructureType        sType                     = StructureType::PhysicalDeviceSubgroupProperties;
	void *               pNext                     = nullptr;
	uint32_t             subgroupSize              = 0;
	ShaderStageFlags     supportedStages           = {};
	SubgroupFeatureFlags supportedOperations       = {};
	Bool32               quadOperationsInAllStages = Constants::False;
};
struct PhysicalDeviceSubgroupSizeControlFeatures {
	StructureType sType                = StructureType::PhysicalDeviceSubgroupSizeControlFeatures;
	void *        pNext                = nullptr;
	Bool32        subgroupSizeControl  = Constants::False;
	Bool32        computeFullSubgroups = Constants::False;
};
struct PhysicalDeviceSubgroupSizeControlProperties {
	StructureType    sType                        = StructureType::PhysicalDeviceSubgroupSizeControlProperties;
	void *           pNext                        = nullptr;
	uint32_t         minSubgroupSize              = 0;
	uint32_t         maxSubgroupSize              = 0;
	uint32_t         maxComputeWorkgroupSubgroups = 0;
	ShaderStageFlags requiredSubgroupSizeStages   = {};
};
struct PhysicalDeviceSubpassMergeFeedbackFeaturesEXT {
	StructureType sType                = StructureType::PhysicalDeviceSubpassMergeFeedbackFeaturesEXT;
	void *        pNext                = nullptr;
	Bool32        subpassMergeFeedback = Constants::False;
};
struct PhysicalDeviceSubpassShadingFeaturesHUAWEI {
	StructureType sType          = StructureType::PhysicalDeviceSubpassShadingFeaturesHUAWEI;
	void *        pNext          = nullptr;
	Bool32        subpassShading = Constants::False;
};
struct PhysicalDeviceSubpassShadingPropertiesHUAWEI {
	StructureType sType                                     = StructureType::PhysicalDeviceSubpassShadingPropertiesHUAWEI;
	void *        pNext                                     = nullptr;
	uint32_t      maxSubpassShadingWorkgroupSizeAspectRatio = 0;
};
struct PhysicalDeviceSurfaceInfo2KHR {
	StructureType                             sType   = StructureType::PhysicalDeviceSurfaceInfo2KHR;
	const void *                              pNext   = nullptr;
	impl_Struct::AssignableHandle<SurfaceKHR> surface;
};
struct PhysicalDeviceSwapchainMaintenance1FeaturesKHR {
	StructureType sType                 = StructureType::PhysicalDeviceSwapchainMaintenance1FeaturesKHR;
	void *        pNext                 = nullptr;
	Bool32        swapchainMaintenance1 = Constants::False;
};
struct PhysicalDeviceSynchronization2Features {
	StructureType sType            = StructureType::PhysicalDeviceSynchronization2Features;
	void *        pNext            = nullptr;
	Bool32        synchronization2 = Constants::False;
};
struct PhysicalDeviceTensorFeaturesARM {
	StructureType sType                                         = StructureType::PhysicalDeviceTensorFeaturesARM;
	void *        pNext                                         = nullptr;
	Bool32        tensorNonPacked                               = Constants::False;
	Bool32        shaderTensorAccess                            = Constants::False;
	Bool32        shaderStorageTensorArrayDynamicIndexing       = Constants::False;
	Bool32        shaderStorageTensorArrayNonUniformIndexing    = Constants::False;
	Bool32        descriptorBindingStorageTensorUpdateAfterBind = Constants::False;
	Bool32        tensors                                       = Constants::False;
};
struct PhysicalDeviceTensorPropertiesARM {
	StructureType    sType                                              = StructureType::PhysicalDeviceTensorPropertiesARM;
	void *           pNext                                              = nullptr;
	uint32_t         maxTensorDimensionCount                            = 0;
	uint64_t         maxTensorElements                                  = 0;
	uint64_t         maxPerDimensionTensorElements                      = 0;
	int64_t          maxTensorStride                                    = 0;
	uint64_t         maxTensorSize                                      = 0;
	uint32_t         maxTensorShaderAccessArrayLength                   = 0;
	uint32_t         maxTensorShaderAccessSize                          = 0;
	uint32_t         maxDescriptorSetStorageTensors                     = 0;
	uint32_t         maxPerStageDescriptorSetStorageTensors             = 0;
	uint32_t         maxDescriptorSetUpdateAfterBindStorageTensors      = 0;
	uint32_t         maxPerStageDescriptorUpdateAfterBindStorageTensors = 0;
	Bool32           shaderStorageTensorArrayNonUniformIndexingNative   = Constants::False;
	ShaderStageFlags shaderTensorSupportedStages                        = {};
};
struct PhysicalDeviceTexelBufferAlignmentFeaturesEXT {
	StructureType sType                = StructureType::PhysicalDeviceTexelBufferAlignmentFeaturesEXT;
	void *        pNext                = nullptr;
	Bool32        texelBufferAlignment = Constants::False;
};
struct PhysicalDeviceTexelBufferAlignmentProperties {
	StructureType sType                                        = StructureType::PhysicalDeviceTexelBufferAlignmentProperties;
	void *        pNext                                        = nullptr;
	DeviceSize    storageTexelBufferOffsetAlignmentBytes       = 0;
	Bool32        storageTexelBufferOffsetSingleTexelAlignment = Constants::False;
	DeviceSize    uniformTexelBufferOffsetAlignmentBytes       = 0;
	Bool32        uniformTexelBufferOffsetSingleTexelAlignment = Constants::False;
};
struct PhysicalDeviceTextureCompressionASTC3DFeaturesEXT {
	StructureType sType                     = StructureType::PhysicalDeviceTextureCompressionAstc3DFeaturesEXT;
	void *        pNext                     = nullptr;
	Bool32        textureCompressionASTC_3D = Constants::False;
};
struct PhysicalDeviceTextureCompressionASTCHDRFeatures {
	StructureType sType                      = StructureType::PhysicalDeviceTextureCompressionAstcHdrFeatures;
	void *        pNext                      = nullptr;
	Bool32        textureCompressionASTC_HDR = Constants::False;
};
struct PhysicalDeviceThrottleHintFeaturesSEC {
	StructureType sType        = StructureType::PhysicalDeviceThrottleHintFeaturesSEC;
	void *        pNext        = nullptr;
	Bool32        throttleHint = Constants::False;
};
struct PhysicalDeviceTileMemoryHeapFeaturesQCOM {
	StructureType sType          = StructureType::PhysicalDeviceTileMemoryHeapFeaturesQCOM;
	void *        pNext          = nullptr;
	Bool32        tileMemoryHeap = Constants::False;
};
struct PhysicalDeviceTileMemoryHeapPropertiesQCOM {
	StructureType sType               = StructureType::PhysicalDeviceTileMemoryHeapPropertiesQCOM;
	void *        pNext               = nullptr;
	Bool32        queueSubmitBoundary = Constants::False;
	Bool32        tileBufferTransfers = Constants::False;
};
struct PhysicalDeviceTilePropertiesFeaturesQCOM {
	StructureType sType          = StructureType::PhysicalDeviceTilePropertiesFeaturesQCOM;
	void *        pNext          = nullptr;
	Bool32        tileProperties = Constants::False;
};
struct PhysicalDeviceTileShadingFeaturesQCOM {
	StructureType sType                         = StructureType::PhysicalDeviceTileShadingFeaturesQCOM;
	void *        pNext                         = nullptr;
	Bool32        tileShading                   = Constants::False;
	Bool32        tileShadingFragmentStage      = Constants::False;
	Bool32        tileShadingColorAttachments   = Constants::False;
	Bool32        tileShadingDepthAttachments   = Constants::False;
	Bool32        tileShadingStencilAttachments = Constants::False;
	Bool32        tileShadingInputAttachments   = Constants::False;
	Bool32        tileShadingSampledAttachments = Constants::False;
	Bool32        tileShadingPerTileDraw        = Constants::False;
	Bool32        tileShadingPerTileDispatch    = Constants::False;
	Bool32        tileShadingDispatchTile       = Constants::False;
	Bool32        tileShadingApron              = Constants::False;
	Bool32        tileShadingAnisotropicApron   = Constants::False;
	Bool32        tileShadingAtomicOps          = Constants::False;
	Bool32        tileShadingImageProcessing    = Constants::False;
};
struct PhysicalDeviceTimelineSemaphoreFeatures {
	StructureType sType             = StructureType::PhysicalDeviceTimelineSemaphoreFeatures;
	void *        pNext             = nullptr;
	Bool32        timelineSemaphore = Constants::False;
};
struct PhysicalDeviceTimelineSemaphoreProperties {
	StructureType sType                               = StructureType::PhysicalDeviceTimelineSemaphoreProperties;
	void *        pNext                               = nullptr;
	uint64_t      maxTimelineSemaphoreValueDifference = 0;
};
struct PhysicalDeviceToolProperties {
	StructureType                                             sType       = StructureType::PhysicalDeviceToolProperties;
	void *                                                    pNext       = nullptr;
	impl_Struct::FixedString<Constants::MaxExtensionNameSize> name        = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxExtensionNameSize> version     = {};// len null-terminated
	ToolPurposeFlags                                          purposes    = {};
	impl_Struct::FixedString<Constants::MaxDescriptionSize>   description = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxExtensionNameSize> layer       = {};// len null-terminated
};
struct PhysicalDeviceTransformFeedbackFeaturesEXT {
	StructureType sType             = StructureType::PhysicalDeviceTransformFeedbackFeaturesEXT;
	void *        pNext             = nullptr;
	Bool32        transformFeedback = Constants::False;
	Bool32        geometryStreams   = Constants::False;
};
struct PhysicalDeviceTransformFeedbackPropertiesEXT {
	StructureType sType                                      = StructureType::PhysicalDeviceTransformFeedbackPropertiesEXT;
	void *        pNext                                      = nullptr;
	uint32_t      maxTransformFeedbackStreams                = 0;
	uint32_t      maxTransformFeedbackBuffers                = 0;
	DeviceSize    maxTransformFeedbackBufferSize             = 0;
	uint32_t      maxTransformFeedbackStreamDataSize         = 0;
	uint32_t      maxTransformFeedbackBufferDataSize         = 0;
	uint32_t      maxTransformFeedbackBufferDataStride       = 0;
	Bool32        transformFeedbackQueries                   = Constants::False;
	Bool32        transformFeedbackStreamsLinesTriangles     = Constants::False;
	Bool32        transformFeedbackRasterizationStreamSelect = Constants::False;
	Bool32        transformFeedbackDraw                      = Constants::False;
};
struct PhysicalDeviceUnifiedImageLayoutsFeaturesKHR {
	StructureType sType                    = StructureType::PhysicalDeviceUnifiedImageLayoutsFeaturesKHR;
	void *        pNext                    = nullptr;
	Bool32        unifiedImageLayouts      = Constants::False;
	Bool32        unifiedImageLayoutsVideo = Constants::False;
};
struct PhysicalDeviceUniformBufferStandardLayoutFeatures {
	StructureType sType                       = StructureType::PhysicalDeviceUniformBufferStandardLayoutFeatures;
	void *        pNext                       = nullptr;
	Bool32        uniformBufferStandardLayout = Constants::False;
};
struct PhysicalDeviceVariablePointersFeatures {
	StructureType sType                         = StructureType::PhysicalDeviceVariablePointersFeatures;
	void *        pNext                         = nullptr;
	Bool32        variablePointersStorageBuffer = Constants::False;
	Bool32        variablePointers              = Constants::False;
};
struct PhysicalDeviceVertexAttributeDivisorFeatures {
	StructureType sType                                  = StructureType::PhysicalDeviceVertexAttributeDivisorFeatures;
	void *        pNext                                  = nullptr;
	Bool32        vertexAttributeInstanceRateDivisor     = Constants::False;
	Bool32        vertexAttributeInstanceRateZeroDivisor = Constants::False;
};
struct PhysicalDeviceVertexAttributeDivisorProperties {
	StructureType sType                        = StructureType::PhysicalDeviceVertexAttributeDivisorProperties;
	void *        pNext                        = nullptr;
	uint32_t      maxVertexAttribDivisor       = 0;
	Bool32        supportsNonZeroFirstInstance = Constants::False;
};
struct PhysicalDeviceVertexAttributeDivisorPropertiesEXT {
	StructureType sType                  = StructureType::PhysicalDeviceVertexAttributeDivisorPropertiesEXT;
	void *        pNext                  = nullptr;
	uint32_t      maxVertexAttribDivisor = 0;
};
struct PhysicalDeviceVertexAttributeRobustnessFeaturesEXT {
	StructureType sType                     = StructureType::PhysicalDeviceVertexAttributeRobustnessFeaturesEXT;
	void *        pNext                     = nullptr;
	Bool32        vertexAttributeRobustness = Constants::False;
};
struct PhysicalDeviceVertexInputDynamicStateFeaturesEXT {
	StructureType sType                   = StructureType::PhysicalDeviceVertexInputDynamicStateFeaturesEXT;
	void *        pNext                   = nullptr;
	Bool32        vertexInputDynamicState = Constants::False;
};
struct PhysicalDeviceVideoDecodeVP9FeaturesKHR {
	StructureType sType          = StructureType::PhysicalDeviceVideoDecodeVp9FeaturesKHR;
	void *        pNext          = nullptr;
	Bool32        videoDecodeVP9 = Constants::False;
};
struct PhysicalDeviceVideoEncodeAV1FeaturesKHR {
	StructureType sType          = StructureType::PhysicalDeviceVideoEncodeAV1FeaturesKHR;
	void *        pNext          = nullptr;
	Bool32        videoEncodeAV1 = Constants::False;
};
struct PhysicalDeviceVideoEncodeFeedback2FeaturesKHR {
	StructureType sType                = StructureType::PhysicalDeviceVideoEncodeFeedback2FeaturesKHR;
	void *        pNext                = nullptr;
	Bool32        videoEncodeFeedback2 = Constants::False;
};
struct PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR {
	StructureType sType                   = StructureType::PhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR;
	void *        pNext                   = nullptr;
	Bool32        videoEncodeIntraRefresh = Constants::False;
};
struct PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR {
	StructureType sType                      = StructureType::PhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR;
	void *        pNext                      = nullptr;
	Bool32        videoEncodeQuantizationMap = Constants::False;
};
struct PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE {
	StructureType sType                    = StructureType::PhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE;
	void *        pNext                    = nullptr;
	Bool32        videoEncodeRgbConversion = Constants::False;
};
struct PhysicalDeviceVideoFormatInfoKHR {
	StructureType   sType      = StructureType::PhysicalDeviceVideoFormatInfoKHR;
	const void *    pNext      = nullptr;
	ImageUsageFlags imageUsage = {};
};
struct PhysicalDeviceVideoMaintenance1FeaturesKHR {
	StructureType sType             = StructureType::PhysicalDeviceVideoMaintenance1FeaturesKHR;
	void *        pNext             = nullptr;
	Bool32        videoMaintenance1 = Constants::False;
};
struct PhysicalDeviceVideoMaintenance2FeaturesKHR {
	StructureType sType             = StructureType::PhysicalDeviceVideoMaintenance2FeaturesKHR;
	void *        pNext             = nullptr;
	Bool32        videoMaintenance2 = Constants::False;
};
struct PhysicalDeviceVulkan11Features {
	StructureType sType                              = StructureType::PhysicalDeviceVulkan11Features;
	void *        pNext                              = nullptr;
	Bool32        storageBuffer16BitAccess           = Constants::False;
	Bool32        uniformAndStorageBuffer16BitAccess = Constants::False;
	Bool32        storagePushConstant16              = Constants::False;
	Bool32        storageInputOutput16               = Constants::False;
	Bool32        multiview                          = Constants::False;
	Bool32        multiviewGeometryShader            = Constants::False;
	Bool32        multiviewTessellationShader        = Constants::False;
	Bool32        variablePointersStorageBuffer      = Constants::False;
	Bool32        variablePointers                   = Constants::False;
	Bool32        protectedMemory                    = Constants::False;
	Bool32        samplerYcbcrConversion             = Constants::False;
	Bool32        shaderDrawParameters               = Constants::False;
};
struct PhysicalDeviceVulkan11Properties {
	StructureType                            sType                             = StructureType::PhysicalDeviceVulkan11Properties;
	void *                                   pNext                             = nullptr;
	std::array<uint8_t, Constants::UuidSize> deviceUUID                        = {};
	std::array<uint8_t, Constants::UuidSize> driverUUID                        = {};
	std::array<uint8_t, Constants::LuidSize> deviceLUID                        = {};
	uint32_t                                 deviceNodeMask                    = 0;
	Bool32                                   deviceLUIDValid                   = Constants::False;
	uint32_t                                 subgroupSize                      = 0;
	ShaderStageFlags                         subgroupSupportedStages           = {};
	SubgroupFeatureFlags                     subgroupSupportedOperations       = {};
	Bool32                                   subgroupQuadOperationsInAllStages = Constants::False;
	PointClippingBehavior                    pointClippingBehavior             = PointClippingBehavior::AllClipPlanes;
	uint32_t                                 maxMultiviewViewCount             = 0;
	uint32_t                                 maxMultiviewInstanceIndex         = 0;
	Bool32                                   protectedNoFault                  = Constants::False;
	uint32_t                                 maxPerSetDescriptors              = 0;
	DeviceSize                               maxMemoryAllocationSize           = 0;
};
struct PhysicalDeviceVulkan12Features {
	StructureType sType                                              = StructureType::PhysicalDeviceVulkan12Features;
	void *        pNext                                              = nullptr;
	Bool32        samplerMirrorClampToEdge                           = Constants::False;
	Bool32        drawIndirectCount                                  = Constants::False;
	Bool32        storageBuffer8BitAccess                            = Constants::False;
	Bool32        uniformAndStorageBuffer8BitAccess                  = Constants::False;
	Bool32        storagePushConstant8                               = Constants::False;
	Bool32        shaderBufferInt64Atomics                           = Constants::False;
	Bool32        shaderSharedInt64Atomics                           = Constants::False;
	Bool32        shaderFloat16                                      = Constants::False;
	Bool32        shaderInt8                                         = Constants::False;
	Bool32        descriptorIndexing                                 = Constants::False;
	Bool32        shaderInputAttachmentArrayDynamicIndexing          = Constants::False;
	Bool32        shaderUniformTexelBufferArrayDynamicIndexing       = Constants::False;
	Bool32        shaderStorageTexelBufferArrayDynamicIndexing       = Constants::False;
	Bool32        shaderUniformBufferArrayNonUniformIndexing         = Constants::False;
	Bool32        shaderSampledImageArrayNonUniformIndexing          = Constants::False;
	Bool32        shaderStorageBufferArrayNonUniformIndexing         = Constants::False;
	Bool32        shaderStorageImageArrayNonUniformIndexing          = Constants::False;
	Bool32        shaderInputAttachmentArrayNonUniformIndexing       = Constants::False;
	Bool32        shaderUniformTexelBufferArrayNonUniformIndexing    = Constants::False;
	Bool32        shaderStorageTexelBufferArrayNonUniformIndexing    = Constants::False;
	Bool32        descriptorBindingUniformBufferUpdateAfterBind      = Constants::False;
	Bool32        descriptorBindingSampledImageUpdateAfterBind       = Constants::False;
	Bool32        descriptorBindingStorageImageUpdateAfterBind       = Constants::False;
	Bool32        descriptorBindingStorageBufferUpdateAfterBind      = Constants::False;
	Bool32        descriptorBindingUniformTexelBufferUpdateAfterBind = Constants::False;
	Bool32        descriptorBindingStorageTexelBufferUpdateAfterBind = Constants::False;
	Bool32        descriptorBindingUpdateUnusedWhilePending          = Constants::False;
	Bool32        descriptorBindingPartiallyBound                    = Constants::False;
	Bool32        descriptorBindingVariableDescriptorCount           = Constants::False;
	Bool32        runtimeDescriptorArray                             = Constants::False;
	Bool32        samplerFilterMinmax                                = Constants::False;
	Bool32        scalarBlockLayout                                  = Constants::False;
	Bool32        imagelessFramebuffer                               = Constants::False;
	Bool32        uniformBufferStandardLayout                        = Constants::False;
	Bool32        shaderSubgroupExtendedTypes                        = Constants::False;
	Bool32        separateDepthStencilLayouts                        = Constants::False;
	Bool32        hostQueryReset                                     = Constants::False;
	Bool32        timelineSemaphore                                  = Constants::False;
	Bool32        bufferDeviceAddress                                = Constants::False;
	Bool32        bufferDeviceAddressCaptureReplay                   = Constants::False;
	Bool32        bufferDeviceAddressMultiDevice                     = Constants::False;
	Bool32        vulkanMemoryModel                                  = Constants::False;
	Bool32        vulkanMemoryModelDeviceScope                       = Constants::False;
	Bool32        vulkanMemoryModelAvailabilityVisibilityChains      = Constants::False;
	Bool32        shaderOutputViewportIndex                          = Constants::False;
	Bool32        shaderOutputLayer                                  = Constants::False;
	Bool32        subgroupBroadcastDynamicId                         = Constants::False;
};
struct PhysicalDeviceVulkan13Features {
	StructureType sType                                              = StructureType::PhysicalDeviceVulkan13Features;
	void *        pNext                                              = nullptr;
	Bool32        robustImageAccess                                  = Constants::False;
	Bool32        inlineUniformBlock                                 = Constants::False;
	Bool32        descriptorBindingInlineUniformBlockUpdateAfterBind = Constants::False;
	Bool32        pipelineCreationCacheControl                       = Constants::False;
	Bool32        privateData                                        = Constants::False;
	Bool32        shaderDemoteToHelperInvocation                     = Constants::False;
	Bool32        shaderTerminateInvocation                          = Constants::False;
	Bool32        subgroupSizeControl                                = Constants::False;
	Bool32        computeFullSubgroups                               = Constants::False;
	Bool32        synchronization2                                   = Constants::False;
	Bool32        textureCompressionASTC_HDR                         = Constants::False;
	Bool32        shaderZeroInitializeWorkgroupMemory                = Constants::False;
	Bool32        dynamicRendering                                   = Constants::False;
	Bool32        shaderIntegerDotProduct                            = Constants::False;
	Bool32        maintenance4                                       = Constants::False;
};
struct PhysicalDeviceVulkan13Properties {
	StructureType    sType                                                                         = StructureType::PhysicalDeviceVulkan13Properties;
	void *           pNext                                                                         = nullptr;
	uint32_t         minSubgroupSize                                                               = 0;
	uint32_t         maxSubgroupSize                                                               = 0;
	uint32_t         maxComputeWorkgroupSubgroups                                                  = 0;
	ShaderStageFlags requiredSubgroupSizeStages                                                    = {};
	uint32_t         maxInlineUniformBlockSize                                                     = 0;
	uint32_t         maxPerStageDescriptorInlineUniformBlocks                                      = 0;
	uint32_t         maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks                       = 0;
	uint32_t         maxDescriptorSetInlineUniformBlocks                                           = 0;
	uint32_t         maxDescriptorSetUpdateAfterBindInlineUniformBlocks                            = 0;
	uint32_t         maxInlineUniformTotalSize                                                     = 0;
	Bool32           integerDotProduct8BitUnsignedAccelerated                                      = Constants::False;
	Bool32           integerDotProduct8BitSignedAccelerated                                        = Constants::False;
	Bool32           integerDotProduct8BitMixedSignednessAccelerated                               = Constants::False;
	Bool32           integerDotProduct4x8BitPackedUnsignedAccelerated                              = Constants::False;
	Bool32           integerDotProduct4x8BitPackedSignedAccelerated                                = Constants::False;
	Bool32           integerDotProduct4x8BitPackedMixedSignednessAccelerated                       = Constants::False;
	Bool32           integerDotProduct16BitUnsignedAccelerated                                     = Constants::False;
	Bool32           integerDotProduct16BitSignedAccelerated                                       = Constants::False;
	Bool32           integerDotProduct16BitMixedSignednessAccelerated                              = Constants::False;
	Bool32           integerDotProduct32BitUnsignedAccelerated                                     = Constants::False;
	Bool32           integerDotProduct32BitSignedAccelerated                                       = Constants::False;
	Bool32           integerDotProduct32BitMixedSignednessAccelerated                              = Constants::False;
	Bool32           integerDotProduct64BitUnsignedAccelerated                                     = Constants::False;
	Bool32           integerDotProduct64BitSignedAccelerated                                       = Constants::False;
	Bool32           integerDotProduct64BitMixedSignednessAccelerated                              = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating8BitUnsignedAccelerated                = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating8BitSignedAccelerated                  = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated         = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated        = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated          = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating16BitUnsignedAccelerated               = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating16BitSignedAccelerated                 = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated        = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating32BitUnsignedAccelerated               = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating32BitSignedAccelerated                 = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated        = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating64BitUnsignedAccelerated               = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating64BitSignedAccelerated                 = Constants::False;
	Bool32           integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated        = Constants::False;
	DeviceSize       storageTexelBufferOffsetAlignmentBytes                                        = 0;
	Bool32           storageTexelBufferOffsetSingleTexelAlignment                                  = Constants::False;
	DeviceSize       uniformTexelBufferOffsetAlignmentBytes                                        = 0;
	Bool32           uniformTexelBufferOffsetSingleTexelAlignment                                  = Constants::False;
	DeviceSize       maxBufferSize                                                                 = 0;
};
struct PhysicalDeviceVulkan14Features {
	StructureType sType                                  = StructureType::PhysicalDeviceVulkan14Features;
	void *        pNext                                  = nullptr;
	Bool32        globalPriorityQuery                    = Constants::False;
	Bool32        shaderSubgroupRotate                   = Constants::False;
	Bool32        shaderSubgroupRotateClustered          = Constants::False;
	Bool32        shaderFloatControls2                   = Constants::False;
	Bool32        shaderExpectAssume                     = Constants::False;
	Bool32        rectangularLines                       = Constants::False;
	Bool32        bresenhamLines                         = Constants::False;
	Bool32        smoothLines                            = Constants::False;
	Bool32        stippledRectangularLines               = Constants::False;
	Bool32        stippledBresenhamLines                 = Constants::False;
	Bool32        stippledSmoothLines                    = Constants::False;
	Bool32        vertexAttributeInstanceRateDivisor     = Constants::False;
	Bool32        vertexAttributeInstanceRateZeroDivisor = Constants::False;
	Bool32        indexTypeUint8                         = Constants::False;
	Bool32        dynamicRenderingLocalRead              = Constants::False;
	Bool32        maintenance5                           = Constants::False;
	Bool32        maintenance6                           = Constants::False;
	Bool32        pipelineProtectedAccess                = Constants::False;
	Bool32        pipelineRobustness                     = Constants::False;
	Bool32        hostImageCopy                          = Constants::False;
	Bool32        pushDescriptor                         = Constants::False;
};
struct PhysicalDeviceVulkan14Properties {
	StructureType                            sType                                               = StructureType::PhysicalDeviceVulkan14Properties;
	void *                                   pNext                                               = nullptr;
	uint32_t                                 lineSubPixelPrecisionBits                           = 0;
	uint32_t                                 maxVertexAttribDivisor                              = 0;
	Bool32                                   supportsNonZeroFirstInstance                        = Constants::False;
	uint32_t                                 maxPushDescriptors                                  = 0;
	Bool32                                   dynamicRenderingLocalReadDepthStencilAttachments    = Constants::False;
	Bool32                                   dynamicRenderingLocalReadMultisampledAttachments    = Constants::False;
	Bool32                                   earlyFragmentMultisampleCoverageAfterSampleCounting = Constants::False;
	Bool32                                   earlyFragmentSampleMaskTestBeforeSampleCounting     = Constants::False;
	Bool32                                   depthStencilSwizzleOneSupport                       = Constants::False;
	Bool32                                   polygonModePointSize                                = Constants::False;
	Bool32                                   nonStrictSinglePixelWideLinesUseParallelogram       = Constants::False;
	Bool32                                   nonStrictWideLinesUseParallelogram                  = Constants::False;
	Bool32                                   blockTexelViewCompatibleMultipleLayers              = Constants::False;
	uint32_t                                 maxCombinedImageSamplerDescriptorCount              = 0;
	Bool32                                   fragmentShadingRateClampCombinerInputs              = Constants::False;
	PipelineRobustnessBufferBehavior         defaultRobustnessStorageBuffers                     = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessBufferBehavior         defaultRobustnessUniformBuffers                     = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessBufferBehavior         defaultRobustnessVertexInputs                       = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessImageBehavior          defaultRobustnessImages                             = PipelineRobustnessImageBehavior::DeviceDefault;
	uint32_t                                 copySrcLayoutCount                                  = 0;
	ImageLayout *                            pCopySrcLayouts                                     = nullptr;// len copySrcLayoutCount
	uint32_t                                 copyDstLayoutCount                                  = 0;
	ImageLayout *                            pCopyDstLayouts                                     = nullptr;// len copyDstLayoutCount
	std::array<uint8_t, Constants::UuidSize> optimalTilingLayoutUUID                             = {};
	Bool32                                   identicalMemoryTypeRequirements                     = Constants::False;
};
struct PhysicalDeviceVulkanMemoryModelFeatures {
	StructureType sType                                         = StructureType::PhysicalDeviceVulkanMemoryModelFeatures;
	void *        pNext                                         = nullptr;
	Bool32        vulkanMemoryModel                             = Constants::False;
	Bool32        vulkanMemoryModelDeviceScope                  = Constants::False;
	Bool32        vulkanMemoryModelAvailabilityVisibilityChains = Constants::False;
};
struct PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR {
	StructureType sType                                          = StructureType::PhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;
	void *        pNext                                          = nullptr;
	Bool32        workgroupMemoryExplicitLayout                  = Constants::False;
	Bool32        workgroupMemoryExplicitLayoutScalarBlockLayout = Constants::False;
	Bool32        workgroupMemoryExplicitLayout8BitAccess        = Constants::False;
	Bool32        workgroupMemoryExplicitLayout16BitAccess       = Constants::False;
};
struct PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT {
	StructureType sType                 = StructureType::PhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;
	void *        pNext                 = nullptr;
	Bool32        ycbcr2plane444Formats = Constants::False;
};
struct PhysicalDeviceYcbcrDegammaFeaturesQCOM {
	StructureType sType        = StructureType::PhysicalDeviceYcbcrDegammaFeaturesQCOM;
	void *        pNext        = nullptr;
	Bool32        ycbcrDegamma = Constants::False;
};
struct PhysicalDeviceYcbcrImageArraysFeaturesEXT {
	StructureType sType            = StructureType::PhysicalDeviceYcbcrImageArraysFeaturesEXT;
	void *        pNext            = nullptr;
	Bool32        ycbcrImageArrays = Constants::False;
};
struct PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT {
	StructureType sType                      = StructureType::PhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT;
	void *        pNext                      = nullptr;
	Bool32        zeroInitializeDeviceMemory = Constants::False;
};
struct PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures {
	StructureType sType                               = StructureType::PhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;
	void *        pNext                               = nullptr;
	Bool32        shaderZeroInitializeWorkgroupMemory = Constants::False;
};
struct PipelineBinaryDataInfoKHR {
	StructureType                                    sType          = StructureType::PipelineBinaryDataInfoKHR;
	void *                                           pNext          = nullptr;
	impl_Struct::AssignableHandle<PipelineBinaryKHR> pipelineBinary;
};
struct PipelineBinaryDataKHR {
	size_t dataSize = 0;
	void * pData    = nullptr;// len dataSize
};
struct PipelineBinaryHandlesInfoKHR {
	StructureType                                     sType               = StructureType::PipelineBinaryHandlesInfoKHR;
	const void *                                      pNext               = nullptr;
	uint32_t                                          pipelineBinaryCount = 0;
	impl_Struct::AssignableHandle<PipelineBinaryKHR> *pPipelineBinaries   = nullptr;// len pipelineBinaryCount
};
struct PipelineBinaryInfoKHR {
	StructureType                                           sType             = StructureType::PipelineBinaryInfoKHR;
	const void *                                            pNext             = nullptr;
	uint32_t                                                binaryCount       = 0;
	const impl_Struct::AssignableHandle<PipelineBinaryKHR> *pPipelineBinaries = nullptr;// len binaryCount
	auto pipelineBinaries() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<PipelineBinaryKHR>>;
};
struct PipelineBinaryKeyKHR {
	StructureType                                               sType   = StructureType::PipelineBinaryKeyKHR;
	void *                                                      pNext   = nullptr;
	uint32_t                                                    keySize = 0;
	std::array<uint8_t, Constants::MaxPipelineBinaryKeySizeKHR> key     = {};
};
struct PipelineCacheCreateInfo {
	StructureType            sType           = StructureType::PipelineCacheCreateInfo;
	const void *             pNext           = nullptr;
	PipelineCacheCreateFlags flags           = {};
	size_t                   initialDataSize = 0;
	const void *             pInitialData    = nullptr;// len initialDataSize
};
struct PipelineCacheHeaderVersionDataGraphQCOM {
	uint32_t                                                                  headerSize       = 0;
	PipelineCacheHeaderVersion                                                headerVersion    = PipelineCacheHeaderVersion::One;
	DataGraphModelCacheTypeQCOM                                               cacheType        = DataGraphModelCacheTypeQCOM::GenericBinary;
	uint32_t                                                                  cacheVersion     = 0;
	std::array<uint32_t, Constants::DataGraphModelToolchainVersionLengthQCOM> toolchainVersion = {};
};
struct PipelineCacheHeaderVersionOne {
	uint32_t                                 headerSize        = 0;
	PipelineCacheHeaderVersion               headerVersion     = PipelineCacheHeaderVersion::One;
	uint32_t                                 vendorID          = 0;
	uint32_t                                 deviceID          = 0;
	std::array<uint8_t, Constants::UuidSize> pipelineCacheUUID = {};
};
struct PipelineColorBlendAdvancedStateCreateInfoEXT {
	StructureType   sType            = StructureType::PipelineColorBlendAdvancedStateCreateInfoEXT;
	const void *    pNext            = nullptr;
	Bool32          srcPremultiplied = Constants::False;
	Bool32          dstPremultiplied = Constants::False;
	BlendOverlapEXT blendOverlap     = BlendOverlapEXT::Uncorrelated;
};
struct PipelineColorBlendAttachmentState {
	Bool32              blendEnable         = Constants::False;
	BlendFactor         srcColorBlendFactor = BlendFactor::Zero;
	BlendFactor         dstColorBlendFactor = BlendFactor::Zero;
	BlendOp             colorBlendOp        = BlendOp::Add;
	BlendFactor         srcAlphaBlendFactor = BlendFactor::Zero;
	BlendFactor         dstAlphaBlendFactor = BlendFactor::Zero;
	BlendOp             alphaBlendOp        = BlendOp::Add;
	ColorComponentFlags colorWriteMask      = {};
};
struct PipelineColorWriteCreateInfoEXT {
	StructureType sType              = StructureType::PipelineColorWriteCreateInfoEXT;
	const void *  pNext              = nullptr;
	uint32_t      attachmentCount    = 0;
	const Bool32 *pColorWriteEnables = nullptr;// len attachmentCount
	auto colorWriteEnables() -> impl_Struct::VecView<uint32_t, Bool32>;
};
struct PipelineCompilerControlCreateInfoAMD {
	StructureType                   sType                = StructureType::PipelineCompilerControlCreateInfoAMD;
	const void *                    pNext                = nullptr;
	PipelineCompilerControlFlagsAMD compilerControlFlags = {};
};
struct PipelineCoverageModulationStateCreateInfoNV {
	StructureType                                sType                         = StructureType::PipelineCoverageModulationStateCreateInfoNV;
	const void *                                 pNext                         = nullptr;
	PipelineCoverageModulationStateCreateFlagsNV flags                         = {};
	CoverageModulationModeNV                     coverageModulationMode        = CoverageModulationModeNV::None;
	Bool32                                       coverageModulationTableEnable = Constants::False;
	uint32_t                                     coverageModulationTableCount  = 0;
	const float *                                pCoverageModulationTable      = nullptr;// len coverageModulationTableCount
	auto coverageModulationTable() -> impl_Struct::VecView<uint32_t, float>;
};
struct PipelineCoverageReductionStateCreateInfoNV {
	StructureType                               sType                 = StructureType::PipelineCoverageReductionStateCreateInfoNV;
	const void *                                pNext                 = nullptr;
	PipelineCoverageReductionStateCreateFlagsNV flags                 = {};
	CoverageReductionModeNV                     coverageReductionMode = CoverageReductionModeNV::Merge;
};
struct PipelineCoverageToColorStateCreateInfoNV {
	StructureType                             sType                   = StructureType::PipelineCoverageToColorStateCreateInfoNV;
	const void *                              pNext                   = nullptr;
	PipelineCoverageToColorStateCreateFlagsNV flags                   = {};
	Bool32                                    coverageToColorEnable   = Constants::False;
	uint32_t                                  coverageToColorLocation = 0;
};
struct PipelineCreateFlags2CreateInfo {
	StructureType        sType = StructureType::PipelineCreateFlags2CreateInfo;
	const void *         pNext = nullptr;
	PipelineCreateFlags2 flags = {};
};
struct PipelineCreateInfoKHR {
	StructureType sType = StructureType::PipelineCreateInfoKHR;
	void *        pNext = nullptr;
};
struct PipelineCreationFeedback {
	PipelineCreationFeedbackFlags flags    = {};
	uint64_t                      duration = 0;
};
struct PipelineDynamicStateCreateInfo {
	StructureType                   sType             = StructureType::PipelineDynamicStateCreateInfo;
	const void *                    pNext             = nullptr;
	PipelineDynamicStateCreateFlags flags             = {};
	uint32_t                        dynamicStateCount = 0;
	const DynamicState *            pDynamicStates    = nullptr;// len dynamicStateCount
	auto dynamicStates() -> impl_Struct::VecView<uint32_t, DynamicState>;
};
struct PipelineExecutableInfoKHR {
	StructureType                           sType           = StructureType::PipelineExecutableInfoKHR;
	const void *                            pNext           = nullptr;
	impl_Struct::AssignableHandle<Pipeline> pipeline;
	uint32_t                                executableIndex = 0;
};
struct PipelineExecutableInternalRepresentationKHR {
	StructureType                                           sType       = StructureType::PipelineExecutableInternalRepresentationKHR;
	void *                                                  pNext       = nullptr;
	impl_Struct::FixedString<Constants::MaxDescriptionSize> name        = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description = {};// len null-terminated
	Bool32                                                  isText      = Constants::False;
	size_t                                                  dataSize    = 0;
	void *                                                  pData       = nullptr;// len dataSize
};
struct PipelineExecutablePropertiesKHR {
	StructureType                                           sType        = StructureType::PipelineExecutablePropertiesKHR;
	void *                                                  pNext        = nullptr;
	ShaderStageFlags                                        stages       = {};
	impl_Struct::FixedString<Constants::MaxDescriptionSize> name         = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description  = {};// len null-terminated
	uint32_t                                                subgroupSize = 0;
};
union PipelineExecutableStatisticValueKHR {
	Bool32   b32;
	int64_t  i64;
	uint64_t u64;
	double   f64;
};
struct PipelineFragmentDensityMapLayeredCreateInfoVALVE {
	StructureType sType                       = StructureType::PipelineFragmentDensityMapLayeredCreateInfoVALVE;
	const void *  pNext                       = nullptr;
	uint32_t      maxFragmentDensityMapLayers = 0;
};
struct PipelineFragmentShadingRateEnumStateCreateInfoNV {
	StructureType                                   sType           = StructureType::PipelineFragmentShadingRateEnumStateCreateInfoNV;
	const void *                                    pNext           = nullptr;
	FragmentShadingRateTypeNV                       shadingRateType = FragmentShadingRateTypeNV::FragmentSize;
	FragmentShadingRateNV                           shadingRate     = FragmentShadingRateNV::v1InvocationPerPixel;
	std::array<FragmentShadingRateCombinerOpKHR, 2> combinerOps     = {};
};
struct PipelineIndirectDeviceAddressInfoNV {
	StructureType                           sType             = StructureType::PipelineIndirectDeviceAddressInfoNV;
	const void *                            pNext             = nullptr;
	PipelineBindPoint                       pipelineBindPoint = PipelineBindPoint::Graphics;
	impl_Struct::AssignableHandle<Pipeline> pipeline;
};
struct PipelineInfoKHR {
	StructureType                           sType    = StructureType::PipelineInfoKHR;
	const void *                            pNext    = nullptr;
	impl_Struct::AssignableHandle<Pipeline> pipeline;
};
struct PipelineInputAssemblyStateCreateInfo {
	StructureType                         sType                  = StructureType::PipelineInputAssemblyStateCreateInfo;
	const void *                          pNext                  = nullptr;
	PipelineInputAssemblyStateCreateFlags flags                  = {};
	PrimitiveTopology                     topology               = PrimitiveTopology::PointList;
	Bool32                                primitiveRestartEnable = Constants::False;
};
struct PipelineLibraryCreateInfoKHR {
	StructureType                                  sType        = StructureType::PipelineLibraryCreateInfoKHR;
	const void *                                   pNext        = nullptr;
	uint32_t                                       libraryCount = 0;
	const impl_Struct::AssignableHandle<Pipeline> *pLibraries   = nullptr;// len libraryCount
	auto libraries() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Pipeline>>;
};
struct PipelineMultisampleStateCreateInfo {
	StructureType                       sType                 = StructureType::PipelineMultisampleStateCreateInfo;
	const void *                        pNext                 = nullptr;
	PipelineMultisampleStateCreateFlags flags                 = {};
	SampleCountBits                     rasterizationSamples  = SampleCountBits::v1;
	Bool32                              sampleShadingEnable   = Constants::False;
	float                               minSampleShading      = 0.0F;
	const SampleMask *                  pSampleMask           = nullptr;
	Bool32                              alphaToCoverageEnable = Constants::False;
	Bool32                              alphaToOneEnable      = Constants::False;
};
struct PipelinePropertiesIdentifierEXT {
	StructureType                            sType              = StructureType::PipelinePropertiesIdentifierEXT;
	void *                                   pNext              = nullptr;
	std::array<uint8_t, Constants::UuidSize> pipelineIdentifier = {};
};
struct PipelineRasterizationConservativeStateCreateInfoEXT {
	StructureType                                        sType                            = StructureType::PipelineRasterizationConservativeStateCreateInfoEXT;
	const void *                                         pNext                            = nullptr;
	PipelineRasterizationConservativeStateCreateFlagsEXT flags                            = {};
	ConservativeRasterizationModeEXT                     conservativeRasterizationMode    = ConservativeRasterizationModeEXT::Disabled;
	float                                                extraPrimitiveOverestimationSize = 0.0F;
};
struct PipelineRasterizationDepthClipStateCreateInfoEXT {
	StructureType                                     sType           = StructureType::PipelineRasterizationDepthClipStateCreateInfoEXT;
	const void *                                      pNext           = nullptr;
	PipelineRasterizationDepthClipStateCreateFlagsEXT flags           = {};
	Bool32                                            depthClipEnable = Constants::False;
};
struct PipelineRasterizationLineStateCreateInfo {
	StructureType         sType                 = StructureType::PipelineRasterizationLineStateCreateInfo;
	const void *          pNext                 = nullptr;
	LineRasterizationMode lineRasterizationMode = LineRasterizationMode::Default;
	Bool32                stippledLineEnable    = Constants::False;
	uint32_t              lineStippleFactor     = 0;
	uint16_t              lineStipplePattern    = 0;
};
struct PipelineRasterizationProvokingVertexStateCreateInfoEXT {
	StructureType          sType               = StructureType::PipelineRasterizationProvokingVertexStateCreateInfoEXT;
	const void *           pNext               = nullptr;
	ProvokingVertexModeEXT provokingVertexMode = ProvokingVertexModeEXT::FirstVertex;
};
struct PipelineRasterizationStateCreateInfo {
	StructureType                         sType                   = StructureType::PipelineRasterizationStateCreateInfo;
	const void *                          pNext                   = nullptr;
	PipelineRasterizationStateCreateFlags flags                   = {};
	Bool32                                depthClampEnable        = Constants::False;
	Bool32                                rasterizerDiscardEnable = Constants::False;
	PolygonMode                           polygonMode             = PolygonMode::Fill;
	CullModeFlags                         cullMode                = {};
	FrontFace                             frontFace               = FrontFace::CounterClockwise;
	Bool32                                depthBiasEnable         = Constants::False;
	float                                 depthBiasConstantFactor = 0.0F;
	float                                 depthBiasClamp          = 0.0F;
	float                                 depthBiasSlopeFactor    = 0.0F;
	float                                 lineWidth               = 0.0F;
};
struct PipelineRasterizationStateRasterizationOrderAMD {
	StructureType         sType              = StructureType::PipelineRasterizationStateRasterizationOrderAMD;
	const void *          pNext              = nullptr;
	RasterizationOrderAMD rasterizationOrder = RasterizationOrderAMD::Strict;
};
struct PipelineRasterizationStateStreamCreateInfoEXT {
	StructureType                                  sType               = StructureType::PipelineRasterizationStateStreamCreateInfoEXT;
	const void *                                   pNext               = nullptr;
	PipelineRasterizationStateStreamCreateFlagsEXT flags               = {};
	uint32_t                                       rasterizationStream = 0;
};
struct PipelineRenderingCreateInfo {
	StructureType sType                   = StructureType::PipelineRenderingCreateInfo;
	const void *  pNext                   = nullptr;
	uint32_t      viewMask                = 0;
	uint32_t      colorAttachmentCount    = 0;
	const Format *pColorAttachmentFormats = nullptr;// len colorAttachmentCount
	Format        depthAttachmentFormat   = Format::Undefined;
	Format        stencilAttachmentFormat = Format::Undefined;
	auto colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format>;
};
struct PipelineRepresentativeFragmentTestStateCreateInfoNV {
	StructureType sType                            = StructureType::PipelineRepresentativeFragmentTestStateCreateInfoNV;
	const void *  pNext                            = nullptr;
	Bool32        representativeFragmentTestEnable = Constants::False;
};
struct PipelineRobustnessCreateInfo {
	StructureType                    sType          = StructureType::PipelineRobustnessCreateInfo;
	const void *                     pNext          = nullptr;
	PipelineRobustnessBufferBehavior storageBuffers = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessBufferBehavior uniformBuffers = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessBufferBehavior vertexInputs   = PipelineRobustnessBufferBehavior::DeviceDefault;
	PipelineRobustnessImageBehavior  images         = PipelineRobustnessImageBehavior::DeviceDefault;
};
struct PipelineShaderStageModuleIdentifierCreateInfoEXT {
	StructureType  sType          = StructureType::PipelineShaderStageModuleIdentifierCreateInfoEXT;
	const void *   pNext          = nullptr;
	uint32_t       identifierSize = 0;
	const uint8_t *pIdentifier    = nullptr;// len identifierSize
	auto identifier() -> impl_Struct::VecView<uint32_t, uint8_t>;
};
struct PipelineShaderStageRequiredSubgroupSizeCreateInfo {
	StructureType sType                = StructureType::PipelineShaderStageRequiredSubgroupSizeCreateInfo;
	const void *  pNext                = nullptr;
	uint32_t      requiredSubgroupSize = 0;
};
struct PipelineTessellationDomainOriginStateCreateInfo {
	StructureType            sType        = StructureType::PipelineTessellationDomainOriginStateCreateInfo;
	const void *             pNext        = nullptr;
	TessellationDomainOrigin domainOrigin = TessellationDomainOrigin::UpperLeft;
};
struct PipelineTessellationStateCreateInfo {
	StructureType                        sType              = StructureType::PipelineTessellationStateCreateInfo;
	const void *                         pNext              = nullptr;
	PipelineTessellationStateCreateFlags flags              = {};
	uint32_t                             patchControlPoints = 0;
};
struct PipelineViewportDepthClipControlCreateInfoEXT {
	StructureType sType            = StructureType::PipelineViewportDepthClipControlCreateInfoEXT;
	const void *  pNext            = nullptr;
	Bool32        negativeOneToOne = Constants::False;
};
struct PresentId2KHR {
	StructureType   sType          = StructureType::PresentId2KHR;
	const void *    pNext          = nullptr;
	uint32_t        swapchainCount = 0;
	const uint64_t *pPresentIds    = nullptr;// len swapchainCount
	auto presentIds() -> impl_Struct::VecView<uint32_t, uint64_t>;
};
struct PresentIdKHR {
	StructureType   sType          = StructureType::PresentIdKHR;
	const void *    pNext          = nullptr;
	uint32_t        swapchainCount = 0;
	const uint64_t *pPresentIds    = nullptr;// len swapchainCount
	auto presentIds() -> impl_Struct::VecView<uint32_t, uint64_t>;
};
struct PresentInfoKHR {
	StructureType                                      sType              = StructureType::PresentInfoKHR;
	const void *                                       pNext              = nullptr;
	uint32_t                                           waitSemaphoreCount = 0;
	const impl_Struct::AssignableHandle<Semaphore> *   pWaitSemaphores    = nullptr;// len waitSemaphoreCount
	uint32_t                                           swapchainCount     = 0;
	const impl_Struct::AssignableHandle<SwapchainKHR> *pSwapchains        = nullptr;// len swapchainCount
	const uint32_t *                                   pImageIndices      = nullptr;// len swapchainCount
	Result *                                           pResults           = nullptr;// len swapchainCount
	auto waitSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>>;
	auto swapchains() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<SwapchainKHR>>;
};
struct PresentStageTimeEXT {
	PresentStageFlagsEXT stage = {};
	uint64_t             time  = 0;
};
struct PresentTimeGOOGLE {
	uint32_t presentID          = 0;
	uint64_t desiredPresentTime = 0;
};
struct PresentTimingInfoEXT {
	StructureType             sType                        = StructureType::PresentTimingInfoEXT;
	const void *              pNext                        = nullptr;
	PresentTimingInfoFlagsEXT flags                        = {};
	uint64_t                  targetTime                   = 0;
	uint64_t                  timeDomainId                 = 0;
	PresentStageFlagsEXT      presentStageQueries          = {};
	PresentStageFlagsEXT      targetTimeDomainPresentStage = {};
};
struct PresentTimingSurfaceCapabilitiesEXT {
	StructureType        sType                          = StructureType::PresentTimingSurfaceCapabilitiesEXT;
	void *               pNext                          = nullptr;
	Bool32               presentTimingSupported         = Constants::False;
	Bool32               presentAtAbsoluteTimeSupported = Constants::False;
	Bool32               presentAtRelativeTimeSupported = Constants::False;
	PresentStageFlagsEXT presentStageQueries            = {};
};
struct PresentWait2InfoKHR {
	StructureType sType     = StructureType::PresentWait2InfoKHR;
	const void *  pNext     = nullptr;
	uint64_t      presentId = 0;
	uint64_t      timeout   = 0;
};
struct PrivateDataSlotCreateInfo {
	StructureType              sType = StructureType::PrivateDataSlotCreateInfo;
	const void *               pNext = nullptr;
	PrivateDataSlotCreateFlags flags = {};
};
struct ProtectedSubmitInfo {
	StructureType sType           = StructureType::ProtectedSubmitInfo;
	const void *  pNext           = nullptr;
	Bool32        protectedSubmit = Constants::False;
};
struct PushConstantBankInfoNV {
	StructureType sType = StructureType::PushConstantBankInfoNV;
	const void *  pNext = nullptr;
	uint32_t      bank  = 0;
};
struct PushConstantRange {
	ShaderStageFlags stageFlags = {};
	uint32_t         offset     = 0;
	uint32_t         size       = 0;
};
struct PushConstantsInfo {
	StructureType                                 sType      = StructureType::PushConstantsInfo;
	const void *                                  pNext      = nullptr;
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	ShaderStageFlags                              stageFlags = {};
	uint32_t                                      offset     = 0;
	uint32_t                                      size       = 0;
	const void *                                  pValues    = nullptr;// len size
};
struct PushDescriptorSetWithTemplateInfo {
	StructureType                                           sType                    = StructureType::PushDescriptorSetWithTemplateInfo;
	const void *                                            pNext                    = nullptr;
	impl_Struct::AssignableHandle<DescriptorUpdateTemplate> descriptorUpdateTemplate;
	impl_Struct::AssignableHandle<PipelineLayout>           layout;
	uint32_t                                                set                      = 0;
	const void *                                            pData                    = nullptr;
};
struct QueryLowLatencySupportNV {
	StructureType sType                  = StructureType::QueryLowLatencySupportNV;
	const void *  pNext                  = nullptr;
	void *        pQueriedLowLatencyData = nullptr;
};
struct QueryPoolCreateInfo {
	StructureType               sType              = StructureType::QueryPoolCreateInfo;
	const void *                pNext              = nullptr;
	QueryPoolCreateFlags        flags              = {};
	QueryType                   queryType          = QueryType::Occlusion;
	uint32_t                    queryCount         = 0;
	QueryPipelineStatisticFlags pipelineStatistics = {};
};
struct QueryPoolPerformanceCreateInfoKHR {
	StructureType   sType             = StructureType::QueryPoolPerformanceCreateInfoKHR;
	const void *    pNext             = nullptr;
	uint32_t        queueFamilyIndex  = 0;
	uint32_t        counterIndexCount = 0;
	const uint32_t *pCounterIndices   = nullptr;// len counterIndexCount
	auto counterIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct QueryPoolPerformanceQueryCreateInfoINTEL {
	StructureType              sType                       = StructureType::QueryPoolPerformanceQueryCreateInfoINTEL;
	const void *               pNext                       = nullptr;
	QueryPoolSamplingModeINTEL performanceCountersSampling = QueryPoolSamplingModeINTEL::Manual;
};
struct QueryPoolVideoEncodeFeedbackCreateInfoKHR {
	StructureType               sType               = StructureType::QueryPoolVideoEncodeFeedbackCreateInfoKHR;
	const void *                pNext               = nullptr;
	VideoEncodeFeedbackFlagsKHR encodeFeedbackFlags = {};
};
struct QueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR {
	StructureType                           sType                           = StructureType::QueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR;
	const void *                            pNext                           = nullptr;
	uint32_t                                maxPerPartitionFeedbackEntries  = 0;
	VideoEncodePerPartitionFeedbackFlagsKHR perPartitionEncodeFeedbackFlags = {};
};
struct QueueFamilyCheckpointProperties2NV {
	StructureType       sType                        = StructureType::QueueFamilyCheckpointProperties2NV;
	void *              pNext                        = nullptr;
	PipelineStageFlags2 checkpointExecutionStageMask = {};
};
struct QueueFamilyCheckpointPropertiesNV {
	StructureType      sType                        = StructureType::QueueFamilyCheckpointPropertiesNV;
	void *             pNext                        = nullptr;
	PipelineStageFlags checkpointExecutionStageMask = {};
};
struct QueueFamilyDataGraphOpticalFlowPropertiesARM {
	StructureType                        sType                    = StructureType::QueueFamilyDataGraphOpticalFlowPropertiesARM;
	void *                               pNext                    = nullptr;
	DataGraphOpticalFlowGridSizeFlagsARM supportedOutputGridSizes = {};
	DataGraphOpticalFlowGridSizeFlagsARM supportedHintGridSizes   = {};
	Bool32                               hintSupported            = Constants::False;
	Bool32                               costSupported            = Constants::False;
	uint32_t                             minWidth                 = 0;
	uint32_t                             minHeight                = 0;
	uint32_t                             maxWidth                 = 0;
	uint32_t                             maxHeight                = 0;
};
struct QueueFamilyDataGraphProcessingEnginePropertiesARM {
	StructureType                    sType                       = StructureType::QueueFamilyDataGraphProcessingEnginePropertiesARM;
	void *                           pNext                       = nullptr;
	ExternalSemaphoreHandleTypeFlags foreignSemaphoreHandleTypes = {};
	ExternalMemoryHandleTypeFlags    foreignMemoryHandleTypes    = {};
};
struct QueueFamilyGlobalPriorityProperties {
	StructureType                                                     sType         = StructureType::QueueFamilyGlobalPriorityProperties;
	void *                                                            pNext         = nullptr;
	uint32_t                                                          priorityCount = 0;
	std::array<QueueGlobalPriority, Constants::MaxGlobalPrioritySize> priorities    = {};// len priorityCount
};
struct QueueFamilyOwnershipTransferPropertiesKHR {
	StructureType sType                               = StructureType::QueueFamilyOwnershipTransferPropertiesKHR;
	void *        pNext                               = nullptr;
	uint32_t      optimalImageTransferToQueueFamilies = 0;
};
struct QueueFamilyQueryResultStatusPropertiesKHR {
	StructureType sType                    = StructureType::QueueFamilyQueryResultStatusPropertiesKHR;
	void *        pNext                    = nullptr;
	Bool32        queryResultStatusSupport = Constants::False;
};
struct QueueFamilyVideoPropertiesKHR {
	StructureType               sType                = StructureType::QueueFamilyVideoPropertiesKHR;
	void *                      pNext                = nullptr;
	VideoCodecOperationFlagsKHR videoCodecOperations = {};
};
struct RayTracingPipelineClusterAccelerationStructureCreateInfoNV {
	StructureType sType                             = StructureType::RayTracingPipelineClusterAccelerationStructureCreateInfoNV;
	void *        pNext                             = nullptr;
	Bool32        allowClusterAccelerationStructure = Constants::False;
};
struct RayTracingPipelineInterfaceCreateInfoKHR {
	StructureType sType                          = StructureType::RayTracingPipelineInterfaceCreateInfoKHR;
	const void *  pNext                          = nullptr;
	uint32_t      maxPipelineRayPayloadSize      = 0;
	uint32_t      maxPipelineRayHitAttributeSize = 0;
};
struct RayTracingShaderGroupCreateInfoKHR {
	StructureType                sType                           = StructureType::RayTracingShaderGroupCreateInfoKHR;
	const void *                 pNext                           = nullptr;
	RayTracingShaderGroupTypeKHR type                            = RayTracingShaderGroupTypeKHR::General;
	uint32_t                     generalShader                   = 0;
	uint32_t                     closestHitShader                = 0;
	uint32_t                     anyHitShader                    = 0;
	uint32_t                     intersectionShader              = 0;
	const void *                 pShaderGroupCaptureReplayHandle = nullptr;
};
struct RayTracingShaderGroupCreateInfoNV {
	StructureType                sType              = StructureType::RayTracingShaderGroupCreateInfoNV;
	const void *                 pNext              = nullptr;
	RayTracingShaderGroupTypeKHR type               = RayTracingShaderGroupTypeKHR::General;
	uint32_t                     generalShader      = 0;
	uint32_t                     closestHitShader   = 0;
	uint32_t                     anyHitShader       = 0;
	uint32_t                     intersectionShader = 0;
};
struct RefreshCycleDurationGOOGLE {
	uint64_t refreshDuration = 0;
};
struct ReleaseCapturedPipelineDataInfoKHR {
	StructureType                           sType    = StructureType::ReleaseCapturedPipelineDataInfoKHR;
	void *                                  pNext    = nullptr;
	impl_Struct::AssignableHandle<Pipeline> pipeline;
};
struct ReleaseSwapchainImagesInfoKHR {
	StructureType                               sType           = StructureType::ReleaseSwapchainImagesInfoKHR;
	const void *                                pNext           = nullptr;
	impl_Struct::AssignableHandle<SwapchainKHR> swapchain;
	uint32_t                                    imageIndexCount = 0;
	const uint32_t *                            pImageIndices   = nullptr;// len imageIndexCount
	auto imageIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct RenderPassAttachmentBeginInfo {
	StructureType                                   sType           = StructureType::RenderPassAttachmentBeginInfo;
	const void *                                    pNext           = nullptr;
	uint32_t                                        attachmentCount = 0;
	const impl_Struct::AssignableHandle<ImageView> *pAttachments    = nullptr;// len attachmentCount
	auto attachments() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ImageView>>;
};
struct RenderPassCreationControlEXT {
	StructureType sType           = StructureType::RenderPassCreationControlEXT;
	const void *  pNext           = nullptr;
	Bool32        disallowMerging = Constants::False;
};
struct RenderPassCreationFeedbackInfoEXT {
	uint32_t postMergeSubpassCount = 0;
};
struct RenderPassMultiviewCreateInfo {
	StructureType   sType                = StructureType::RenderPassMultiviewCreateInfo;
	const void *    pNext                = nullptr;
	uint32_t        subpassCount         = 0;
	const uint32_t *pViewMasks           = nullptr;// len subpassCount
	uint32_t        dependencyCount      = 0;
	const int32_t * pViewOffsets         = nullptr;// len dependencyCount
	uint32_t        correlationMaskCount = 0;
	const uint32_t *pCorrelationMasks    = nullptr;// len correlationMaskCount
	auto viewMasks() -> impl_Struct::VecView<uint32_t, uint32_t>;
	auto viewOffsets() -> impl_Struct::VecView<uint32_t, int32_t>;
	auto correlationMasks() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct RenderPassPerformanceCountersByRegionBeginInfoARM {
	StructureType        sType               = StructureType::RenderPassPerformanceCountersByRegionBeginInfoARM;
	void *               pNext               = nullptr;
	uint32_t             counterAddressCount = 0;
	const DeviceAddress *pCounterAddresses   = nullptr;// len counterAddressCount
	Bool32               serializeRegions    = Constants::False;
	uint32_t             counterIndexCount   = 0;
	uint32_t *           pCounterIndices     = nullptr;// len counterIndexCount
	auto counterAddresses() -> impl_Struct::VecView<uint32_t, DeviceAddress>;
};
struct RenderPassSubpassFeedbackInfoEXT {
	SubpassMergeStatusEXT                                   subpassMergeStatus = SubpassMergeStatusEXT::Merged;
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description        = {};// len null-terminated
	uint32_t                                                postMergeIndex     = 0;
};
struct RenderPassTransformBeginInfoQCOM {
	StructureType           sType     = StructureType::RenderPassTransformBeginInfoQCOM;
	const void *            pNext     = nullptr;
	SurfaceTransformBitsKHR transform = SurfaceTransformBitsKHR::Identity;
};
struct RenderingAreaInfo {
	StructureType sType                   = StructureType::RenderingAreaInfo;
	const void *  pNext                   = nullptr;
	uint32_t      viewMask                = 0;
	uint32_t      colorAttachmentCount    = 0;
	const Format *pColorAttachmentFormats = nullptr;// len colorAttachmentCount
	Format        depthAttachmentFormat   = Format::Undefined;
	Format        stencilAttachmentFormat = Format::Undefined;
	auto colorAttachmentFormats() -> impl_Struct::VecView<uint32_t, Format>;
};
struct RenderingAttachmentFlagsInfoKHR {
	StructureType               sType = StructureType::RenderingAttachmentFlagsInfoKHR;
	const void *                pNext = nullptr;
	RenderingAttachmentFlagsKHR flags = {};
};
struct RenderingAttachmentLocationInfo {
	StructureType   sType                     = StructureType::RenderingAttachmentLocationInfo;
	const void *    pNext                     = nullptr;
	uint32_t        colorAttachmentCount      = 0;
	const uint32_t *pColorAttachmentLocations = nullptr;// len colorAttachmentCount
	auto colorAttachmentLocations() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct RenderingEndInfoKHR {
	StructureType sType = StructureType::RenderingEndInfoKHR;
	const void *  pNext = nullptr;
};
struct RenderingFragmentDensityMapAttachmentInfoEXT {
	StructureType                            sType       = StructureType::RenderingFragmentDensityMapAttachmentInfoEXT;
	const void *                             pNext       = nullptr;
	impl_Struct::AssignableHandle<ImageView> imageView;
	ImageLayout                              imageLayout = ImageLayout::Undefined;
};
struct RenderingInputAttachmentIndexInfo {
	StructureType   sType                        = StructureType::RenderingInputAttachmentIndexInfo;
	const void *    pNext                        = nullptr;
	uint32_t        colorAttachmentCount         = 0;
	const uint32_t *pColorAttachmentInputIndices = nullptr;// len colorAttachmentCount
	const uint32_t *pDepthInputAttachmentIndex   = nullptr;
	const uint32_t *pStencilInputAttachmentIndex = nullptr;
	auto colorAttachmentInputIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct ResolveImageModeInfoKHR {
	StructureType        sType              = StructureType::ResolveImageModeInfoKHR;
	const void *         pNext              = nullptr;
	ResolveImageFlagsKHR flags              = {};
	ResolveModeBits      resolveMode        = ResolveModeBits::None;
	ResolveModeBits      stencilResolveMode = ResolveModeBits::None;
};
struct SRTDataNV {
	float sx  = 0.0F;
	float a   = 0.0F;
	float b   = 0.0F;
	float pvx = 0.0F;
	float sy  = 0.0F;
	float c   = 0.0F;
	float pvy = 0.0F;
	float sz  = 0.0F;
	float pvz = 0.0F;
	float qx  = 0.0F;
	float qy  = 0.0F;
	float qz  = 0.0F;
	float qw  = 0.0F;
	float tx  = 0.0F;
	float ty  = 0.0F;
	float tz  = 0.0F;
};
struct SampleLocationEXT {
	float x = 0.0F;
	float y = 0.0F;
};
struct SamplerCaptureDescriptorDataInfoEXT {
	StructureType                          sType   = StructureType::SamplerCaptureDescriptorDataInfoEXT;
	const void *                           pNext   = nullptr;
	impl_Struct::AssignableHandle<Sampler> sampler;
};
struct SamplerCreateInfo {
	StructureType      sType                   = StructureType::SamplerCreateInfo;
	const void *       pNext                   = nullptr;
	SamplerCreateFlags flags                   = {};
	Filter             magFilter               = Filter::Nearest;
	Filter             minFilter               = Filter::Nearest;
	SamplerMipmapMode  mipmapMode              = SamplerMipmapMode::Nearest;
	SamplerAddressMode addressModeU            = SamplerAddressMode::Repeat;
	SamplerAddressMode addressModeV            = SamplerAddressMode::Repeat;
	SamplerAddressMode addressModeW            = SamplerAddressMode::Repeat;
	float              mipLodBias              = 0.0F;
	Bool32             anisotropyEnable        = Constants::False;
	float              maxAnisotropy           = 0.0F;
	Bool32             compareEnable           = Constants::False;
	CompareOp          compareOp               = CompareOp::Never;
	float              minLod                  = 0.0F;
	float              maxLod                  = 0.0F;
	BorderColor        borderColor             = BorderColor::FloatTransparentBlack;
	Bool32             unnormalizedCoordinates = Constants::False;
};
struct SamplerCubicWeightsCreateInfoQCOM {
	StructureType          sType        = StructureType::SamplerCubicWeightsCreateInfoQCOM;
	const void *           pNext        = nullptr;
	CubicFilterWeightsQCOM cubicWeights = CubicFilterWeightsQCOM::CatmullRom;
};
struct SamplerCustomBorderColorIndexCreateInfoEXT {
	StructureType sType = StructureType::SamplerCustomBorderColorIndexCreateInfoEXT;
	const void *  pNext = nullptr;
	uint32_t      index = 0;
};
struct SamplerReductionModeCreateInfo {
	StructureType        sType         = StructureType::SamplerReductionModeCreateInfo;
	const void *         pNext         = nullptr;
	SamplerReductionMode reductionMode = SamplerReductionMode::WeightedAverage;
};
struct SamplerYcbcrConversionImageFormatProperties {
	StructureType sType                               = StructureType::SamplerYcbcrConversionImageFormatProperties;
	void *        pNext                               = nullptr;
	uint32_t      combinedImageSamplerDescriptorCount = 0;
};
struct SamplerYcbcrConversionInfo {
	StructureType                                         sType      = StructureType::SamplerYcbcrConversionInfo;
	const void *                                          pNext      = nullptr;
	impl_Struct::AssignableHandle<SamplerYcbcrConversion> conversion;
};
struct SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM {
	StructureType sType             = StructureType::SamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM;
	void *        pNext             = nullptr;
	Bool32        enableYDegamma    = Constants::False;
	Bool32        enableCbCrDegamma = Constants::False;
};
struct SemaphoreCreateInfo {
	StructureType        sType = StructureType::SemaphoreCreateInfo;
	const void *         pNext = nullptr;
	SemaphoreCreateFlags flags = {};
};
struct SemaphoreGetFdInfoKHR {
	StructureType                            sType      = StructureType::SemaphoreGetFdInfoKHR;
	const void *                             pNext      = nullptr;
	impl_Struct::AssignableHandle<Semaphore> semaphore;
	ExternalSemaphoreHandleTypeBits          handleType = ExternalSemaphoreHandleTypeBits::OpaqueFd;
};
struct SemaphoreSignalInfo {
	StructureType                            sType     = StructureType::SemaphoreSignalInfo;
	const void *                             pNext     = nullptr;
	impl_Struct::AssignableHandle<Semaphore> semaphore;
	uint64_t                                 value     = 0;
};
struct SemaphoreSubmitInfo {
	StructureType                            sType       = StructureType::SemaphoreSubmitInfo;
	const void *                             pNext       = nullptr;
	impl_Struct::AssignableHandle<Semaphore> semaphore;
	uint64_t                                 value       = 0;
	PipelineStageFlags2                      stageMask   = {};
	uint32_t                                 deviceIndex = 0;
};
struct SemaphoreTypeCreateInfo {
	StructureType sType         = StructureType::SemaphoreTypeCreateInfo;
	const void *  pNext         = nullptr;
	SemaphoreType semaphoreType = SemaphoreType::Binary;
	uint64_t      initialValue  = 0;
};
struct SemaphoreWaitInfo {
	StructureType                                   sType          = StructureType::SemaphoreWaitInfo;
	const void *                                    pNext          = nullptr;
	SemaphoreWaitFlags                              flags          = {};
	uint32_t                                        semaphoreCount = 0;
	const impl_Struct::AssignableHandle<Semaphore> *pSemaphores    = nullptr;// len semaphoreCount
	const uint64_t *                                pValues        = nullptr;// len semaphoreCount
	auto semaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>>;
};
struct SetDescriptorBufferOffsetsInfoEXT {
	StructureType                                 sType          = StructureType::SetDescriptorBufferOffsetsInfoEXT;
	const void *                                  pNext          = nullptr;
	ShaderStageFlags                              stageFlags     = {};
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	uint32_t                                      firstSet       = 0;
	uint32_t                                      setCount       = 0;
	const uint32_t *                              pBufferIndices = nullptr;// len setCount
	const DeviceSize *                            pOffsets       = nullptr;// len setCount
	auto bufferIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct SetLatencyMarkerInfoNV {
	StructureType   sType     = StructureType::SetLatencyMarkerInfoNV;
	const void *    pNext     = nullptr;
	uint64_t        presentID = 0;
	LatencyMarkerNV marker    = LatencyMarkerNV::SimulationStart;
};
struct SetPresentConfigNV {
	StructureType sType                 = StructureType::SetPresentConfigNV;
	const void *  pNext                 = nullptr;
	uint32_t      numFramesPerBatch     = 0;
	uint32_t      presentConfigFeedback = 0;
};
struct SetStateFlagsIndirectCommandNV {
	uint32_t data = 0;
};
struct ShaderInstrumentationCreateInfoARM {
	StructureType sType = StructureType::ShaderInstrumentationCreateInfoARM;
	void *        pNext = nullptr;
};
struct ShaderInstrumentationMetricDataHeaderARM {
	uint32_t         resultIndex     = 0;
	uint32_t         resultSubIndex  = 0;
	ShaderStageFlags stages          = {};
	uint32_t         basicBlockIndex = 0;
};
struct ShaderInstrumentationMetricDescriptionARM {
	StructureType                                           sType       = StructureType::ShaderInstrumentationMetricDescriptionARM;
	void *                                                  pNext       = nullptr;
	impl_Struct::FixedString<Constants::MaxDescriptionSize> name        = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description = {};// len null-terminated
};
struct ShaderModuleCreateInfo {
	StructureType           sType    = StructureType::ShaderModuleCreateInfo;
	const void *            pNext    = nullptr;
	ShaderModuleCreateFlags flags    = {};
	size_t                  codeSize = 0;
	const uint32_t *        pCode    = nullptr;
};
struct ShaderModuleIdentifierEXT {
	StructureType                                                    sType          = StructureType::ShaderModuleIdentifierEXT;
	void *                                                           pNext          = nullptr;
	uint32_t                                                         identifierSize = 0;
	std::array<uint8_t, Constants::MaxShaderModuleIdentifierSizeEXT> identifier     = {};// len identifierSize
};
struct ShaderModuleValidationCacheCreateInfoEXT {
	StructureType                                     sType           = StructureType::ShaderModuleValidationCacheCreateInfoEXT;
	const void *                                      pNext           = nullptr;
	impl_Struct::AssignableHandle<ValidationCacheEXT> validationCache;
};
struct ShaderResourceUsageAMD {
	uint32_t numUsedVgprs             = 0;
	uint32_t numUsedSgprs             = 0;
	uint32_t ldsSizePerLocalWorkGroup = 0;
	size_t   ldsUsageSizeInBytes      = 0;
	size_t   scratchMemUsageInBytes   = 0;
};
struct ShadingRatePaletteNV {
	uint32_t                         shadingRatePaletteEntryCount = 0;
	const ShadingRatePaletteEntryNV *pShadingRatePaletteEntries   = nullptr;// len shadingRatePaletteEntryCount
	auto shadingRatePaletteEntries() -> impl_Struct::VecView<uint32_t, ShadingRatePaletteEntryNV>;
};
struct SharedPresentSurfaceCapabilities2KHR {
	StructureType       sType                            = StructureType::SharedPresentSurfaceCapabilities2KHR;
	void *              pNext                            = nullptr;
	ImageUsageFlags2KHR sharedPresentSupportedUsageFlags = {};
};
struct SharedPresentSurfaceCapabilitiesKHR {
	StructureType   sType                            = StructureType::SharedPresentSurfaceCapabilitiesKHR;
	void *          pNext                            = nullptr;
	ImageUsageFlags sharedPresentSupportedUsageFlags = {};
};
struct SparseMemoryBind {
	DeviceSize                                  resourceOffset = 0;
	DeviceSize                                  size           = 0;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  memoryOffset   = 0;
	SparseMemoryBindFlags                       flags          = {};
};
struct SpecializationMapEntry {
	uint32_t constantID = 0;
	uint32_t offset     = 0;
	size_t   size       = 0;
};
struct StencilOpState {
	StencilOp failOp      = StencilOp::Keep;
	StencilOp passOp      = StencilOp::Keep;
	StencilOp depthFailOp = StencilOp::Keep;
	CompareOp compareOp   = CompareOp::Never;
	uint32_t  compareMask = 0;
	uint32_t  writeMask   = 0;
	uint32_t  reference   = 0;
};
struct StridedDeviceAddressNV {
	DeviceAddress startAddress  = 0;
	DeviceSize    strideInBytes = 0;
};
struct StridedDeviceAddressRangeKHR {
	DeviceAddress address = 0;
	DeviceSize    size    = 0;
	DeviceSize    stride  = 0;
};
struct StridedDeviceAddressRegionKHR {
	DeviceAddress deviceAddress = 0;
	DeviceSize    stride        = 0;
	DeviceSize    size          = 0;
};
struct SubmitInfo {
	StructureType                                       sType                = StructureType::SubmitInfo;
	const void *                                        pNext                = nullptr;
	uint32_t                                            waitSemaphoreCount   = 0;
	const impl_Struct::AssignableHandle<Semaphore> *    pWaitSemaphores      = nullptr;// len waitSemaphoreCount
	const PipelineStageFlags *                          pWaitDstStageMask    = nullptr;// len waitSemaphoreCount
	uint32_t                                            commandBufferCount   = 0;
	const impl_Struct::AssignableHandle<CommandBuffer> *pCommandBuffers      = nullptr;// len commandBufferCount
	uint32_t                                            signalSemaphoreCount = 0;
	const impl_Struct::AssignableHandle<Semaphore> *    pSignalSemaphores    = nullptr;// len signalSemaphoreCount
	auto waitSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>>;
	auto commandBuffers() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<CommandBuffer>>;
	auto signalSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>>;
};
struct SubpassBeginInfo {
	StructureType   sType    = StructureType::SubpassBeginInfo;
	const void *    pNext    = nullptr;
	SubpassContents contents = SubpassContents::Inline;
};
struct SubpassDependency {
	uint32_t           srcSubpass      = 0;
	uint32_t           dstSubpass      = 0;
	PipelineStageFlags srcStageMask    = {};
	PipelineStageFlags dstStageMask    = {};
	AccessFlags        srcAccessMask   = {};
	AccessFlags        dstAccessMask   = {};
	DependencyFlags    dependencyFlags = {};
};
struct SubpassDependency2 {
	StructureType      sType           = StructureType::SubpassDependency2;
	const void *       pNext           = nullptr;
	uint32_t           srcSubpass      = 0;
	uint32_t           dstSubpass      = 0;
	PipelineStageFlags srcStageMask    = {};
	PipelineStageFlags dstStageMask    = {};
	AccessFlags        srcAccessMask   = {};
	AccessFlags        dstAccessMask   = {};
	DependencyFlags    dependencyFlags = {};
	int32_t            viewOffset      = 0;
};
struct SubpassEndInfo {
	StructureType sType = StructureType::SubpassEndInfo;
	const void *  pNext = nullptr;
};
struct SubpassResolvePerformanceQueryEXT {
	StructureType sType   = StructureType::SubpassResolvePerformanceQueryEXT;
	void *        pNext   = nullptr;
	Bool32        optimal = Constants::False;
};
struct SubpassShadingPipelineCreateInfoHUAWEI {
	StructureType                             sType      = StructureType::SubpassShadingPipelineCreateInfoHUAWEI;
	void *                                    pNext      = nullptr;
	impl_Struct::AssignableHandle<RenderPass> renderPass;
	uint32_t                                  subpass    = 0;
};
struct SubresourceHostMemcpySize {
	StructureType sType = StructureType::SubresourceHostMemcpySize;
	void *        pNext = nullptr;
	DeviceSize    size  = 0;
};
struct SubresourceLayout {
	DeviceSize offset     = 0;
	DeviceSize size       = 0;
	DeviceSize rowPitch   = 0;
	DeviceSize arrayPitch = 0;
	DeviceSize depthPitch = 0;
};
struct SubsampledImageFormatPropertiesEXT {
	StructureType sType                          = StructureType::SubsampledImageFormatPropertiesEXT;
	const void *  pNext                          = nullptr;
	uint32_t      subsampledImageDescriptorCount = 0;
};
struct SurfaceCapabilitiesPresentBarrierNV {
	StructureType sType                   = StructureType::SurfaceCapabilitiesPresentBarrierNV;
	void *        pNext                   = nullptr;
	Bool32        presentBarrierSupported = Constants::False;
};
struct SurfaceCapabilitiesPresentId2KHR {
	StructureType sType               = StructureType::SurfaceCapabilitiesPresentId2KHR;
	void *        pNext               = nullptr;
	Bool32        presentId2Supported = Constants::False;
};
struct SurfaceCapabilitiesPresentWait2KHR {
	StructureType sType                 = StructureType::SurfaceCapabilitiesPresentWait2KHR;
	void *        pNext                 = nullptr;
	Bool32        presentWait2Supported = Constants::False;
};
struct SurfaceFormatKHR {
	Format        format     = Format::Undefined;
	ColorSpaceKHR colorSpace = ColorSpaceKHR::SrgbNonlinear;
};
struct SurfacePresentModeCompatibilityKHR {
	StructureType   sType            = StructureType::SurfacePresentModeCompatibilityKHR;
	void *          pNext            = nullptr;
	uint32_t        presentModeCount = 0;
	PresentModeKHR *pPresentModes    = nullptr;// len presentModeCount
};
struct SurfacePresentModeKHR {
	StructureType  sType       = StructureType::SurfacePresentModeKHR;
	void *         pNext       = nullptr;
	PresentModeKHR presentMode = PresentModeKHR::Immediate;
};
struct SurfaceProtectedCapabilitiesKHR {
	StructureType sType             = StructureType::SurfaceProtectedCapabilitiesKHR;
	void *        pNext             = nullptr;
	Bool32        supportsProtected = Constants::False;
};
struct SwapchainCalibratedTimestampInfoEXT {
	StructureType                               sType        = StructureType::SwapchainCalibratedTimestampInfoEXT;
	const void *                                pNext        = nullptr;
	impl_Struct::AssignableHandle<SwapchainKHR> swapchain;
	PresentStageFlagsEXT                        presentStage = {};
	uint64_t                                    timeDomainId = 0;
};
struct SwapchainCounterCreateInfoEXT {
	StructureType          sType           = StructureType::SwapchainCounterCreateInfoEXT;
	const void *           pNext           = nullptr;
	SurfaceCounterFlagsEXT surfaceCounters = {};
};
struct SwapchainDisplayNativeHdrCreateInfoAMD {
	StructureType sType              = StructureType::SwapchainDisplayNativeHdrCreateInfoAMD;
	const void *  pNext              = nullptr;
	Bool32        localDimmingEnable = Constants::False;
};
struct SwapchainFlagsSurfaceCapabilitiesEXT {
	StructureType           sType                   = StructureType::SwapchainFlagsSurfaceCapabilitiesEXT;
	void *                  pNext                   = nullptr;
	SwapchainCreateFlagsKHR swapchainSupportedFlags = {};
};
struct SwapchainLatencyCreateInfoNV {
	StructureType sType             = StructureType::SwapchainLatencyCreateInfoNV;
	const void *  pNext             = nullptr;
	Bool32        latencyModeEnable = Constants::False;
};
struct SwapchainPresentBarrierCreateInfoNV {
	StructureType sType                = StructureType::SwapchainPresentBarrierCreateInfoNV;
	void *        pNext                = nullptr;
	Bool32        presentBarrierEnable = Constants::False;
};
struct SwapchainPresentFenceInfoKHR {
	StructureType                               sType          = StructureType::SwapchainPresentFenceInfoKHR;
	const void *                                pNext          = nullptr;
	uint32_t                                    swapchainCount = 0;
	const impl_Struct::AssignableHandle<Fence> *pFences        = nullptr;// len swapchainCount
	auto fences() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Fence>>;
};
struct SwapchainPresentModeInfoKHR {
	StructureType         sType          = StructureType::SwapchainPresentModeInfoKHR;
	const void *          pNext          = nullptr;
	uint32_t              swapchainCount = 0;
	const PresentModeKHR *pPresentModes  = nullptr;// len swapchainCount
	auto presentModes() -> impl_Struct::VecView<uint32_t, PresentModeKHR>;
};
struct SwapchainPresentModesCreateInfoKHR {
	StructureType         sType            = StructureType::SwapchainPresentModesCreateInfoKHR;
	const void *          pNext            = nullptr;
	uint32_t              presentModeCount = 0;
	const PresentModeKHR *pPresentModes    = nullptr;// len presentModeCount
	auto presentModes() -> impl_Struct::VecView<uint32_t, PresentModeKHR>;
};
struct SwapchainPresentScalingCreateInfoKHR {
	StructureType          sType           = StructureType::SwapchainPresentScalingCreateInfoKHR;
	const void *           pNext           = nullptr;
	PresentScalingFlagsKHR scalingBehavior = {};
	PresentGravityFlagsKHR presentGravityX = {};
	PresentGravityFlagsKHR presentGravityY = {};
};
struct SwapchainTimeDomainPropertiesEXT {
	StructureType  sType           = StructureType::SwapchainTimeDomainPropertiesEXT;
	void *         pNext           = nullptr;
	uint32_t       timeDomainCount = 0;
	TimeDomainKHR *pTimeDomains    = nullptr;// len timeDomainCount
	uint64_t *     pTimeDomainIds  = nullptr;// len timeDomainCount
};
struct SwapchainTimingPropertiesEXT {
	StructureType sType           = StructureType::SwapchainTimingPropertiesEXT;
	void *        pNext           = nullptr;
	uint64_t      refreshDuration = 0;
	uint64_t      refreshInterval = 0;
};
struct TensorCaptureDescriptorDataInfoARM {
	StructureType                            sType  = StructureType::TensorCaptureDescriptorDataInfoARM;
	const void *                             pNext  = nullptr;
	impl_Struct::AssignableHandle<TensorARM> tensor;
};
struct TensorCopyARM {
	StructureType   sType          = StructureType::TensorCopyARM;
	const void *    pNext          = nullptr;
	uint32_t        dimensionCount = 0;
	const uint64_t *pSrcOffset     = nullptr;// len dimensionCount
	const uint64_t *pDstOffset     = nullptr;// len dimensionCount
	const uint64_t *pExtent        = nullptr;// len dimensionCount
	auto srcOffset() -> impl_Struct::VecView<uint32_t, uint64_t>;
};
struct TensorDescriptionARM {
	StructureType       sType          = StructureType::TensorDescriptionARM;
	const void *        pNext          = nullptr;
	TensorTilingARM     tiling         = TensorTilingARM::Optimal;
	Format              format         = Format::Undefined;
	uint32_t            dimensionCount = 0;
	const int64_t *     pDimensions    = nullptr;// len dimensionCount
	const int64_t *     pStrides       = nullptr;// len dimensionCount
	TensorUsageFlagsARM usage          = {};
	auto dimensions() -> impl_Struct::VecView<uint32_t, int64_t>;
};
struct TensorExplicitTilingFormatPropertiesARM {
	StructureType       sType                         = StructureType::TensorExplicitTilingFormatPropertiesARM;
	void *              pNext                         = nullptr;
	FormatFeatureFlags2 brick16TilingTensorFeatures   = {};
	FormatFeatureFlags2 brick8TilingTensorFeatures    = {};
	FormatFeatureFlags2 brick4TilingTensorFeatures    = {};
	FormatFeatureFlags2 blockUTilingTensorFeatures    = {};
	FormatFeatureFlags2 blockU64kTilingTensorFeatures = {};
};
struct TensorFormatPropertiesARM {
	StructureType       sType                       = StructureType::TensorFormatPropertiesARM;
	void *              pNext                       = nullptr;
	FormatFeatureFlags2 optimalTilingTensorFeatures = {};
	FormatFeatureFlags2 linearTilingTensorFeatures  = {};
};
struct TensorMemoryBarrierARM {
	StructureType                            sType               = StructureType::TensorMemoryBarrierARM;
	const void *                             pNext               = nullptr;
	PipelineStageFlags2                      srcStageMask        = {};
	AccessFlags2                             srcAccessMask       = {};
	PipelineStageFlags2                      dstStageMask        = {};
	AccessFlags2                             dstAccessMask       = {};
	uint32_t                                 srcQueueFamilyIndex = 0;
	uint32_t                                 dstQueueFamilyIndex = 0;
	impl_Struct::AssignableHandle<TensorARM> tensor;
};
struct TensorMemoryRequirementsInfoARM {
	StructureType                            sType  = StructureType::TensorMemoryRequirementsInfoARM;
	const void *                             pNext  = nullptr;
	impl_Struct::AssignableHandle<TensorARM> tensor;
};
struct TensorRollingBackingCreateInfoARM {
	StructureType                                                                  sType = StructureType::TensorRollingBackingCreateInfoARM;
	const void *                                                                   pNext = nullptr;
	std::array<uint32_t, Constants::MaxTensorCreateInfoRollingBackingWrapCountARM> wraps = {};
};
struct TensorViewCaptureDescriptorDataInfoARM {
	StructureType                                sType      = StructureType::TensorViewCaptureDescriptorDataInfoARM;
	const void *                                 pNext      = nullptr;
	impl_Struct::AssignableHandle<TensorViewARM> tensorView;
};
struct TensorViewCreateInfoARM {
	StructureType                            sType  = StructureType::TensorViewCreateInfoARM;
	const void *                             pNext  = nullptr;
	TensorViewCreateFlagsARM                 flags  = {};
	impl_Struct::AssignableHandle<TensorARM> tensor;
	Format                                   format = Format::Undefined;
};
struct TextureLODGatherFormatPropertiesAMD {
	StructureType sType                           = StructureType::TextureLodGatherFormatPropertiesAMD;
	void *        pNext                           = nullptr;
	Bool32        supportsTextureGatherLODBiasAMD = Constants::False;
};
struct ThrottleHintSubmitInfoSEC {
	StructureType       sType        = StructureType::ThrottleHintSubmitInfoSEC;
	const void *        pNext        = nullptr;
	ThrottleHintTypeSEC throttleHint = ThrottleHintTypeSEC::Default;
};
struct TileMemoryBindInfoQCOM {
	StructureType                               sType  = StructureType::TileMemoryBindInfoQCOM;
	const void *                                pNext  = nullptr;
	impl_Struct::AssignableHandle<DeviceMemory> memory;
};
struct TileMemoryRequirementsQCOM {
	StructureType sType     = StructureType::TileMemoryRequirementsQCOM;
	void *        pNext     = nullptr;
	DeviceSize    size      = 0;
	DeviceSize    alignment = 0;
};
struct TileMemorySizeInfoQCOM {
	StructureType sType = StructureType::TileMemorySizeInfoQCOM;
	const void *  pNext = nullptr;
	DeviceSize    size  = 0;
};
struct TimelineSemaphoreSubmitInfo {
	StructureType   sType                     = StructureType::TimelineSemaphoreSubmitInfo;
	const void *    pNext                     = nullptr;
	uint32_t        waitSemaphoreValueCount   = 0;
	const uint64_t *pWaitSemaphoreValues      = nullptr;// len waitSemaphoreValueCount
	uint32_t        signalSemaphoreValueCount = 0;
	const uint64_t *pSignalSemaphoreValues    = nullptr;// len signalSemaphoreValueCount
	auto waitSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t>;
	auto signalSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t>;
};
struct TraceRaysIndirectCommand2KHR {
	DeviceAddress raygenShaderRecordAddress         = 0;
	DeviceSize    raygenShaderRecordSize            = 0;
	DeviceAddress missShaderBindingTableAddress     = 0;
	DeviceSize    missShaderBindingTableSize        = 0;
	DeviceSize    missShaderBindingTableStride      = 0;
	DeviceAddress hitShaderBindingTableAddress      = 0;
	DeviceSize    hitShaderBindingTableSize         = 0;
	DeviceSize    hitShaderBindingTableStride       = 0;
	DeviceAddress callableShaderBindingTableAddress = 0;
	DeviceSize    callableShaderBindingTableSize    = 0;
	DeviceSize    callableShaderBindingTableStride  = 0;
	uint32_t      width                             = 0;
	uint32_t      height                            = 0;
	uint32_t      depth                             = 0;
};
struct TraceRaysIndirectCommandKHR {
	uint32_t width  = 0;
	uint32_t height = 0;
	uint32_t depth  = 0;
};
struct TransformMatrixKHR {
	std::array<std::array<float, 3>, 4> matrix = {};
};
struct ValidationCacheCreateInfoEXT {
	StructureType                 sType           = StructureType::ValidationCacheCreateInfoEXT;
	const void *                  pNext           = nullptr;
	ValidationCacheCreateFlagsEXT flags           = {};
	size_t                        initialDataSize = 0;
	const void *                  pInitialData    = nullptr;// len initialDataSize
};
struct ValidationFeaturesEXT {
	StructureType                      sType                          = StructureType::ValidationFeaturesEXT;
	const void *                       pNext                          = nullptr;
	uint32_t                           enabledValidationFeatureCount  = 0;
	const ValidationFeatureEnableEXT * pEnabledValidationFeatures     = nullptr;// len enabledValidationFeatureCount
	uint32_t                           disabledValidationFeatureCount = 0;
	const ValidationFeatureDisableEXT *pDisabledValidationFeatures    = nullptr;// len disabledValidationFeatureCount
	auto enabledValidationFeatures() -> impl_Struct::VecView<uint32_t, ValidationFeatureEnableEXT>;
	auto disabledValidationFeatures() -> impl_Struct::VecView<uint32_t, ValidationFeatureDisableEXT>;
};
struct ValidationFlagsEXT {
	StructureType             sType                        = StructureType::ValidationFlagsEXT;
	const void *              pNext                        = nullptr;
	uint32_t                  disabledValidationCheckCount = 0;
	const ValidationCheckEXT *pDisabledValidationChecks    = nullptr;// len disabledValidationCheckCount
	auto disabledValidationChecks() -> impl_Struct::VecView<uint32_t, ValidationCheckEXT>;
};
struct VertexInputAttributeDescription {
	uint32_t location = 0;
	uint32_t binding  = 0;
	Format   format   = Format::Undefined;
	uint32_t offset   = 0;
};
struct VertexInputAttributeDescription2EXT {
	StructureType sType    = StructureType::VertexInputAttributeDescription2EXT;
	void *        pNext    = nullptr;
	uint32_t      location = 0;
	uint32_t      binding  = 0;
	Format        format   = Format::Undefined;
	uint32_t      offset   = 0;
};
struct VertexInputBindingDescription {
	uint32_t        binding   = 0;
	uint32_t        stride    = 0;
	VertexInputRate inputRate = VertexInputRate::Vertex;
};
struct VertexInputBindingDescription2EXT {
	StructureType   sType     = StructureType::VertexInputBindingDescription2EXT;
	void *          pNext     = nullptr;
	uint32_t        binding   = 0;
	uint32_t        stride    = 0;
	VertexInputRate inputRate = VertexInputRate::Vertex;
	uint32_t        divisor   = 0;
};
struct VertexInputBindingDivisorDescription {
	uint32_t binding = 0;
	uint32_t divisor = 0;
};
struct VideoCodingControlInfoKHR {
	StructureType              sType = StructureType::VideoCodingControlInfoKHR;
	const void *               pNext = nullptr;
	VideoCodingControlFlagsKHR flags = {};
};
struct VideoDecodeAV1CapabilitiesKHR {
	StructureType    sType    = StructureType::VideoDecodeAV1CapabilitiesKHR;
	void *           pNext    = nullptr;
	StdVideoAV1Level maxLevel = {};
};
struct VideoDecodeAV1DpbSlotInfoKHR {
	StructureType                         sType             = StructureType::VideoDecodeAV1DpbSlotInfoKHR;
	const void *                          pNext             = nullptr;
	const StdVideoDecodeAV1ReferenceInfo *pStdReferenceInfo = nullptr;
};
struct VideoDecodeAV1InlineSessionParametersInfoKHR {
	StructureType                    sType              = StructureType::VideoDecodeAV1InlineSessionParametersInfoKHR;
	const void *                     pNext              = nullptr;
	const StdVideoAV1SequenceHeader *pStdSequenceHeader = nullptr;
};
struct VideoDecodeAV1PictureInfoKHR {
	StructureType                                                    sType                    = StructureType::VideoDecodeAV1PictureInfoKHR;
	const void *                                                     pNext                    = nullptr;
	const StdVideoDecodeAV1PictureInfo *                             pStdPictureInfo          = nullptr;
	std::array<int32_t, Constants::MaxVideoAV1ReferencesPerFrameKHR> referenceNameSlotIndices = {};
	uint32_t                                                         frameHeaderOffset        = 0;
	uint32_t                                                         tileCount                = 0;
	const uint32_t *                                                 pTileOffsets             = nullptr;// len tileCount
	const uint32_t *                                                 pTileSizes               = nullptr;// len tileCount
	auto tileOffsets() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct VideoDecodeAV1ProfileInfoKHR {
	StructureType      sType            = StructureType::VideoDecodeAV1ProfileInfoKHR;
	const void *       pNext            = nullptr;
	StdVideoAV1Profile stdProfile       = {};
	Bool32             filmGrainSupport = Constants::False;
};
struct VideoDecodeAV1SessionParametersCreateInfoKHR {
	StructureType                    sType              = StructureType::VideoDecodeAV1SessionParametersCreateInfoKHR;
	const void *                     pNext              = nullptr;
	const StdVideoAV1SequenceHeader *pStdSequenceHeader = nullptr;
};
struct VideoDecodeCapabilitiesKHR {
	StructureType                 sType = StructureType::VideoDecodeCapabilitiesKHR;
	void *                        pNext = nullptr;
	VideoDecodeCapabilityFlagsKHR flags = {};
};
struct VideoDecodeH264DpbSlotInfoKHR {
	StructureType                          sType             = StructureType::VideoDecodeH264DpbSlotInfoKHR;
	const void *                           pNext             = nullptr;
	const StdVideoDecodeH264ReferenceInfo *pStdReferenceInfo = nullptr;
};
struct VideoDecodeH264InlineSessionParametersInfoKHR {
	StructureType                           sType   = StructureType::VideoDecodeH264InlineSessionParametersInfoKHR;
	const void *                            pNext   = nullptr;
	const StdVideoH264SequenceParameterSet *pStdSPS = nullptr;
	const StdVideoH264PictureParameterSet * pStdPPS = nullptr;
};
struct VideoDecodeH264PictureInfoKHR {
	StructureType                        sType           = StructureType::VideoDecodeH264PictureInfoKHR;
	const void *                         pNext           = nullptr;
	const StdVideoDecodeH264PictureInfo *pStdPictureInfo = nullptr;
	uint32_t                             sliceCount      = 0;
	const uint32_t *                     pSliceOffsets   = nullptr;// len sliceCount
	auto sliceOffsets() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct VideoDecodeH264ProfileInfoKHR {
	StructureType                       sType         = StructureType::VideoDecodeH264ProfileInfoKHR;
	const void *                        pNext         = nullptr;
	StdVideoH264ProfileIdc              stdProfileIdc = {};
	VideoDecodeH264PictureLayoutBitsKHR pictureLayout = VideoDecodeH264PictureLayoutBitsKHR::Progressive;
};
struct VideoDecodeH264SessionParametersAddInfoKHR {
	StructureType                           sType       = StructureType::VideoDecodeH264SessionParametersAddInfoKHR;
	const void *                            pNext       = nullptr;
	uint32_t                                stdSPSCount = 0;
	const StdVideoH264SequenceParameterSet *pStdSPSs    = nullptr;// len stdSPSCount
	uint32_t                                stdPPSCount = 0;
	const StdVideoH264PictureParameterSet * pStdPPSs    = nullptr;// len stdPPSCount
	auto stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264SequenceParameterSet>;
	auto stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264PictureParameterSet>;
};
struct VideoDecodeH265CapabilitiesKHR {
	StructureType        sType       = StructureType::VideoDecodeH265CapabilitiesKHR;
	void *               pNext       = nullptr;
	StdVideoH265LevelIdc maxLevelIdc = {};
};
struct VideoDecodeH265DpbSlotInfoKHR {
	StructureType                          sType             = StructureType::VideoDecodeH265DpbSlotInfoKHR;
	const void *                           pNext             = nullptr;
	const StdVideoDecodeH265ReferenceInfo *pStdReferenceInfo = nullptr;
};
struct VideoDecodeH265InlineSessionParametersInfoKHR {
	StructureType                           sType   = StructureType::VideoDecodeH265InlineSessionParametersInfoKHR;
	const void *                            pNext   = nullptr;
	const StdVideoH265VideoParameterSet *   pStdVPS = nullptr;
	const StdVideoH265SequenceParameterSet *pStdSPS = nullptr;
	const StdVideoH265PictureParameterSet * pStdPPS = nullptr;
};
struct VideoDecodeH265PictureInfoKHR {
	StructureType                        sType                = StructureType::VideoDecodeH265PictureInfoKHR;
	const void *                         pNext                = nullptr;
	const StdVideoDecodeH265PictureInfo *pStdPictureInfo      = nullptr;
	uint32_t                             sliceSegmentCount    = 0;
	const uint32_t *                     pSliceSegmentOffsets = nullptr;// len sliceSegmentCount
	auto sliceSegmentOffsets() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct VideoDecodeH265ProfileInfoKHR {
	StructureType          sType         = StructureType::VideoDecodeH265ProfileInfoKHR;
	const void *           pNext         = nullptr;
	StdVideoH265ProfileIdc stdProfileIdc = {};
};
struct VideoDecodeH265SessionParametersAddInfoKHR {
	StructureType                           sType       = StructureType::VideoDecodeH265SessionParametersAddInfoKHR;
	const void *                            pNext       = nullptr;
	uint32_t                                stdVPSCount = 0;
	const StdVideoH265VideoParameterSet *   pStdVPSs    = nullptr;// len stdVPSCount
	uint32_t                                stdSPSCount = 0;
	const StdVideoH265SequenceParameterSet *pStdSPSs    = nullptr;// len stdSPSCount
	uint32_t                                stdPPSCount = 0;
	const StdVideoH265PictureParameterSet * pStdPPSs    = nullptr;// len stdPPSCount
	auto stdVPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265VideoParameterSet>;
	auto stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265SequenceParameterSet>;
	auto stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265PictureParameterSet>;
};
struct VideoDecodeUsageInfoKHR {
	StructureType            sType           = StructureType::VideoDecodeUsageInfoKHR;
	const void *             pNext           = nullptr;
	VideoDecodeUsageFlagsKHR videoUsageHints = {};
};
struct VideoDecodeVP9CapabilitiesKHR {
	StructureType    sType    = StructureType::VideoDecodeVp9CapabilitiesKHR;
	void *           pNext    = nullptr;
	StdVideoVP9Level maxLevel = {};
};
struct VideoDecodeVP9PictureInfoKHR {
	StructureType                                                    sType                    = StructureType::VideoDecodeVp9PictureInfoKHR;
	const void *                                                     pNext                    = nullptr;
	const StdVideoDecodeVP9PictureInfo *                             pStdPictureInfo          = nullptr;
	std::array<int32_t, Constants::MaxVideoVp9ReferencesPerFrameKHR> referenceNameSlotIndices = {};
	uint32_t                                                         uncompressedHeaderOffset = 0;
	uint32_t                                                         compressedHeaderOffset   = 0;
	uint32_t                                                         tilesOffset              = 0;
};
struct VideoDecodeVP9ProfileInfoKHR {
	StructureType      sType      = StructureType::VideoDecodeVp9ProfileInfoKHR;
	const void *       pNext      = nullptr;
	StdVideoVP9Profile stdProfile = {};
};
struct VideoEncodeAV1DpbSlotInfoKHR {
	StructureType                         sType             = StructureType::VideoEncodeAV1DpbSlotInfoKHR;
	const void *                          pNext             = nullptr;
	const StdVideoEncodeAV1ReferenceInfo *pStdReferenceInfo = nullptr;
};
struct VideoEncodeAV1FrameSizeKHR {
	uint32_t intraFrameSize        = 0;
	uint32_t predictiveFrameSize   = 0;
	uint32_t bipredictiveFrameSize = 0;
};
struct VideoEncodeAV1GopRemainingFrameInfoKHR {
	StructureType sType                    = StructureType::VideoEncodeAV1GopRemainingFrameInfoKHR;
	const void *  pNext                    = nullptr;
	Bool32        useGopRemainingFrames    = Constants::False;
	uint32_t      gopRemainingIntra        = 0;
	uint32_t      gopRemainingPredictive   = 0;
	uint32_t      gopRemainingBipredictive = 0;
};
struct VideoEncodeAV1PictureInfoKHR {
	StructureType                                                    sType                      = StructureType::VideoEncodeAV1PictureInfoKHR;
	const void *                                                     pNext                      = nullptr;
	VideoEncodeAV1PredictionModeKHR                                  predictionMode             = VideoEncodeAV1PredictionModeKHR::IntraOnly;
	VideoEncodeAV1RateControlGroupKHR                                rateControlGroup           = VideoEncodeAV1RateControlGroupKHR::Intra;
	uint32_t                                                         constantQIndex             = 0;
	const StdVideoEncodeAV1PictureInfo *                             pStdPictureInfo            = nullptr;
	std::array<int32_t, Constants::MaxVideoAV1ReferencesPerFrameKHR> referenceNameSlotIndices   = {};
	Bool32                                                           primaryReferenceCdfOnly    = Constants::False;
	Bool32                                                           generateObuExtensionHeader = Constants::False;
};
struct VideoEncodeAV1ProfileInfoKHR {
	StructureType      sType      = StructureType::VideoEncodeAV1ProfileInfoKHR;
	const void *       pNext      = nullptr;
	StdVideoAV1Profile stdProfile = {};
};
struct VideoEncodeAV1QIndexKHR {
	uint32_t intraQIndex        = 0;
	uint32_t predictiveQIndex   = 0;
	uint32_t bipredictiveQIndex = 0;
};
struct VideoEncodeAV1QuantizationMapCapabilitiesKHR {
	StructureType sType          = StructureType::VideoEncodeAV1QuantizationMapCapabilitiesKHR;
	void *        pNext          = nullptr;
	int32_t       minQIndexDelta = 0;
	int32_t       maxQIndexDelta = 0;
};
struct VideoEncodeAV1RateControlInfoKHR {
	StructureType                     sType                             = StructureType::VideoEncodeAV1RateControlInfoKHR;
	const void *                      pNext                             = nullptr;
	VideoEncodeAV1RateControlFlagsKHR flags                             = {};
	uint32_t                          gopFrameCount                     = 0;
	uint32_t                          keyFramePeriod                    = 0;
	uint32_t                          consecutiveBipredictiveFrameCount = 0;
	uint32_t                          temporalLayerCount                = 0;
};
struct VideoEncodeAV1SessionCreateInfoKHR {
	StructureType    sType       = StructureType::VideoEncodeAV1SessionCreateInfoKHR;
	const void *     pNext       = nullptr;
	Bool32           useMaxLevel = Constants::False;
	StdVideoAV1Level maxLevel    = {};
};
struct VideoEncodeAV1SessionParametersCreateInfoKHR {
	StructureType                              sType                  = StructureType::VideoEncodeAV1SessionParametersCreateInfoKHR;
	const void *                               pNext                  = nullptr;
	const StdVideoAV1SequenceHeader *          pStdSequenceHeader     = nullptr;
	const StdVideoEncodeAV1DecoderModelInfo *  pStdDecoderModelInfo   = nullptr;
	uint32_t                                   stdOperatingPointCount = 0;
	const StdVideoEncodeAV1OperatingPointInfo *pStdOperatingPoints    = nullptr;// len stdOperatingPointCount
	auto stdOperatingPoints() -> impl_Struct::VecView<uint32_t, StdVideoEncodeAV1OperatingPointInfo>;
};
struct VideoEncodeFeedback2CapabilitiesKHR {
	StructureType                           sType                                    = StructureType::VideoEncodeFeedback2CapabilitiesKHR;
	void *                                  pNext                                    = nullptr;
	uint32_t                                maxPerPartitionFeedbackEntries           = 0;
	VideoEncodePerPartitionFeedbackFlagsKHR supportedPerPartitionEncodeFeedbackFlags = {};
};
struct VideoEncodeH264CapabilitiesKHR {
	StructureType                     sType                            = StructureType::VideoEncodeH264CapabilitiesKHR;
	void *                            pNext                            = nullptr;
	VideoEncodeH264CapabilityFlagsKHR flags                            = {};
	StdVideoH264LevelIdc              maxLevelIdc                      = {};
	uint32_t                          maxSliceCount                    = 0;
	uint32_t                          maxPPictureL0ReferenceCount      = 0;
	uint32_t                          maxBPictureL0ReferenceCount      = 0;
	uint32_t                          maxL1ReferenceCount              = 0;
	uint32_t                          maxTemporalLayerCount            = 0;
	Bool32                            expectDyadicTemporalLayerPattern = Constants::False;
	int32_t                           minQp                            = 0;
	int32_t                           maxQp                            = 0;
	Bool32                            prefersGopRemainingFrames        = Constants::False;
	Bool32                            requiresGopRemainingFrames       = Constants::False;
	VideoEncodeH264StdFlagsKHR        stdSyntaxFlags                   = {};
};
struct VideoEncodeH264DpbSlotInfoKHR {
	StructureType                          sType             = StructureType::VideoEncodeH264DpbSlotInfoKHR;
	const void *                           pNext             = nullptr;
	const StdVideoEncodeH264ReferenceInfo *pStdReferenceInfo = nullptr;
};
struct VideoEncodeH264FrameSizeKHR {
	uint32_t frameISize = 0;
	uint32_t framePSize = 0;
	uint32_t frameBSize = 0;
};
struct VideoEncodeH264GopRemainingFrameInfoKHR {
	StructureType sType                 = StructureType::VideoEncodeH264GopRemainingFrameInfoKHR;
	const void *  pNext                 = nullptr;
	Bool32        useGopRemainingFrames = Constants::False;
	uint32_t      gopRemainingI         = 0;
	uint32_t      gopRemainingP         = 0;
	uint32_t      gopRemainingB         = 0;
};
struct VideoEncodeH264NaluSliceInfoKHR {
	StructureType                        sType           = StructureType::VideoEncodeH264NaluSliceInfoKHR;
	const void *                         pNext           = nullptr;
	int32_t                              constantQp      = 0;
	const StdVideoEncodeH264SliceHeader *pStdSliceHeader = nullptr;
};
struct VideoEncodeH264ProfileInfoKHR {
	StructureType          sType         = StructureType::VideoEncodeH264ProfileInfoKHR;
	const void *           pNext         = nullptr;
	StdVideoH264ProfileIdc stdProfileIdc = {};
};
struct VideoEncodeH264QpKHR {
	int32_t qpI = 0;
	int32_t qpP = 0;
	int32_t qpB = 0;
};
struct VideoEncodeH264QuantizationMapCapabilitiesKHR {
	StructureType sType      = StructureType::VideoEncodeH264QuantizationMapCapabilitiesKHR;
	void *        pNext      = nullptr;
	int32_t       minQpDelta = 0;
	int32_t       maxQpDelta = 0;
};
struct VideoEncodeH264RateControlInfoKHR {
	StructureType                      sType                  = StructureType::VideoEncodeH264RateControlInfoKHR;
	const void *                       pNext                  = nullptr;
	VideoEncodeH264RateControlFlagsKHR flags                  = {};
	uint32_t                           gopFrameCount          = 0;
	uint32_t                           idrPeriod              = 0;
	uint32_t                           consecutiveBFrameCount = 0;
	uint32_t                           temporalLayerCount     = 0;
};
struct VideoEncodeH264SessionCreateInfoKHR {
	StructureType        sType          = StructureType::VideoEncodeH264SessionCreateInfoKHR;
	const void *         pNext          = nullptr;
	Bool32               useMaxLevelIdc = Constants::False;
	StdVideoH264LevelIdc maxLevelIdc    = {};
};
struct VideoEncodeH264SessionParametersAddInfoKHR {
	StructureType                           sType       = StructureType::VideoEncodeH264SessionParametersAddInfoKHR;
	const void *                            pNext       = nullptr;
	uint32_t                                stdSPSCount = 0;
	const StdVideoH264SequenceParameterSet *pStdSPSs    = nullptr;// len stdSPSCount
	uint32_t                                stdPPSCount = 0;
	const StdVideoH264PictureParameterSet * pStdPPSs    = nullptr;// len stdPPSCount
	auto stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264SequenceParameterSet>;
	auto stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH264PictureParameterSet>;
};
struct VideoEncodeH264SessionParametersFeedbackInfoKHR {
	StructureType sType              = StructureType::VideoEncodeH264SessionParametersFeedbackInfoKHR;
	void *        pNext              = nullptr;
	Bool32        hasStdSPSOverrides = Constants::False;
	Bool32        hasStdPPSOverrides = Constants::False;
};
struct VideoEncodeH264SessionParametersGetInfoKHR {
	StructureType sType       = StructureType::VideoEncodeH264SessionParametersGetInfoKHR;
	const void *  pNext       = nullptr;
	Bool32        writeStdSPS = Constants::False;
	Bool32        writeStdPPS = Constants::False;
	uint32_t      stdSPSId    = 0;
	uint32_t      stdPPSId    = 0;
};
struct VideoEncodeH265DpbSlotInfoKHR {
	StructureType                          sType             = StructureType::VideoEncodeH265DpbSlotInfoKHR;
	const void *                           pNext             = nullptr;
	const StdVideoEncodeH265ReferenceInfo *pStdReferenceInfo = nullptr;
};
struct VideoEncodeH265FrameSizeKHR {
	uint32_t frameISize = 0;
	uint32_t framePSize = 0;
	uint32_t frameBSize = 0;
};
struct VideoEncodeH265GopRemainingFrameInfoKHR {
	StructureType sType                 = StructureType::VideoEncodeH265GopRemainingFrameInfoKHR;
	const void *  pNext                 = nullptr;
	Bool32        useGopRemainingFrames = Constants::False;
	uint32_t      gopRemainingI         = 0;
	uint32_t      gopRemainingP         = 0;
	uint32_t      gopRemainingB         = 0;
};
struct VideoEncodeH265NaluSliceSegmentInfoKHR {
	StructureType                               sType                  = StructureType::VideoEncodeH265NaluSliceSegmentInfoKHR;
	const void *                                pNext                  = nullptr;
	int32_t                                     constantQp             = 0;
	const StdVideoEncodeH265SliceSegmentHeader *pStdSliceSegmentHeader = nullptr;
};
struct VideoEncodeH265ProfileInfoKHR {
	StructureType          sType         = StructureType::VideoEncodeH265ProfileInfoKHR;
	const void *           pNext         = nullptr;
	StdVideoH265ProfileIdc stdProfileIdc = {};
};
struct VideoEncodeH265QpKHR {
	int32_t qpI = 0;
	int32_t qpP = 0;
	int32_t qpB = 0;
};
struct VideoEncodeH265QuantizationMapCapabilitiesKHR {
	StructureType sType      = StructureType::VideoEncodeH265QuantizationMapCapabilitiesKHR;
	void *        pNext      = nullptr;
	int32_t       minQpDelta = 0;
	int32_t       maxQpDelta = 0;
};
struct VideoEncodeH265RateControlInfoKHR {
	StructureType                      sType                  = StructureType::VideoEncodeH265RateControlInfoKHR;
	const void *                       pNext                  = nullptr;
	VideoEncodeH265RateControlFlagsKHR flags                  = {};
	uint32_t                           gopFrameCount          = 0;
	uint32_t                           idrPeriod              = 0;
	uint32_t                           consecutiveBFrameCount = 0;
	uint32_t                           subLayerCount          = 0;
};
struct VideoEncodeH265SessionCreateInfoKHR {
	StructureType        sType          = StructureType::VideoEncodeH265SessionCreateInfoKHR;
	const void *         pNext          = nullptr;
	Bool32               useMaxLevelIdc = Constants::False;
	StdVideoH265LevelIdc maxLevelIdc    = {};
};
struct VideoEncodeH265SessionParametersAddInfoKHR {
	StructureType                           sType       = StructureType::VideoEncodeH265SessionParametersAddInfoKHR;
	const void *                            pNext       = nullptr;
	uint32_t                                stdVPSCount = 0;
	const StdVideoH265VideoParameterSet *   pStdVPSs    = nullptr;// len stdVPSCount
	uint32_t                                stdSPSCount = 0;
	const StdVideoH265SequenceParameterSet *pStdSPSs    = nullptr;// len stdSPSCount
	uint32_t                                stdPPSCount = 0;
	const StdVideoH265PictureParameterSet * pStdPPSs    = nullptr;// len stdPPSCount
	auto stdVPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265VideoParameterSet>;
	auto stdSPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265SequenceParameterSet>;
	auto stdPPSs() -> impl_Struct::VecView<uint32_t, StdVideoH265PictureParameterSet>;
};
struct VideoEncodeH265SessionParametersFeedbackInfoKHR {
	StructureType sType              = StructureType::VideoEncodeH265SessionParametersFeedbackInfoKHR;
	void *        pNext              = nullptr;
	Bool32        hasStdVPSOverrides = Constants::False;
	Bool32        hasStdSPSOverrides = Constants::False;
	Bool32        hasStdPPSOverrides = Constants::False;
};
struct VideoEncodeH265SessionParametersGetInfoKHR {
	StructureType sType       = StructureType::VideoEncodeH265SessionParametersGetInfoKHR;
	const void *  pNext       = nullptr;
	Bool32        writeStdVPS = Constants::False;
	Bool32        writeStdSPS = Constants::False;
	Bool32        writeStdPPS = Constants::False;
	uint32_t      stdVPSId    = 0;
	uint32_t      stdSPSId    = 0;
	uint32_t      stdPPSId    = 0;
};
struct VideoEncodeIntraRefreshCapabilitiesKHR {
	StructureType                       sType                                   = StructureType::VideoEncodeIntraRefreshCapabilitiesKHR;
	void *                              pNext                                   = nullptr;
	VideoEncodeIntraRefreshModeFlagsKHR intraRefreshModes                       = {};
	uint32_t                            maxIntraRefreshCycleDuration            = 0;
	uint32_t                            maxIntraRefreshActiveReferencePictures  = 0;
	Bool32                              partitionIndependentIntraRefreshRegions = Constants::False;
	Bool32                              nonRectangularIntraRefreshRegions       = Constants::False;
};
struct VideoEncodeIntraRefreshInfoKHR {
	StructureType sType                     = StructureType::VideoEncodeIntraRefreshInfoKHR;
	const void *  pNext                     = nullptr;
	uint32_t      intraRefreshCycleDuration = 0;
	uint32_t      intraRefreshIndex         = 0;
};
struct VideoEncodeProfileRgbConversionInfoVALVE {
	StructureType sType                      = StructureType::VideoEncodeProfileRgbConversionInfoVALVE;
	const void *  pNext                      = nullptr;
	Bool32        performEncodeRgbConversion = Constants::False;
};
struct VideoEncodeQualityLevelInfoKHR {
	StructureType sType        = StructureType::VideoEncodeQualityLevelInfoKHR;
	const void *  pNext        = nullptr;
	uint32_t      qualityLevel = 0;
};
struct VideoEncodeQualityLevelPropertiesKHR {
	StructureType                     sType                          = StructureType::VideoEncodeQualityLevelPropertiesKHR;
	void *                            pNext                          = nullptr;
	VideoEncodeRateControlModeBitsKHR preferredRateControlMode       = VideoEncodeRateControlModeBitsKHR::Default;
	uint32_t                          preferredRateControlLayerCount = 0;
};
struct VideoEncodeRateControlLayerInfoKHR {
	StructureType sType                = StructureType::VideoEncodeRateControlLayerInfoKHR;
	const void *  pNext                = nullptr;
	uint64_t      averageBitrate       = 0;
	uint64_t      maxBitrate           = 0;
	uint32_t      frameRateNumerator   = 0;
	uint32_t      frameRateDenominator = 0;
};
struct VideoEncodeRgbConversionCapabilitiesVALVE {
	StructureType                            sType          = StructureType::VideoEncodeRgbConversionCapabilitiesVALVE;
	void *                                   pNext          = nullptr;
	VideoEncodeRgbModelConversionFlagsVALVE  rgbModels      = {};
	VideoEncodeRgbRangeCompressionFlagsVALVE rgbRanges      = {};
	VideoEncodeRgbChromaOffsetFlagsVALVE     xChromaOffsets = {};
	VideoEncodeRgbChromaOffsetFlagsVALVE     yChromaOffsets = {};
};
struct VideoEncodeSessionIntraRefreshCreateInfoKHR {
	StructureType                      sType            = StructureType::VideoEncodeSessionIntraRefreshCreateInfoKHR;
	const void *                       pNext            = nullptr;
	VideoEncodeIntraRefreshModeBitsKHR intraRefreshMode = VideoEncodeIntraRefreshModeBitsKHR::None;
};
struct VideoEncodeSessionParametersFeedbackInfoKHR {
	StructureType sType        = StructureType::VideoEncodeSessionParametersFeedbackInfoKHR;
	void *        pNext        = nullptr;
	Bool32        hasOverrides = Constants::False;
};
struct VideoEncodeSessionParametersGetInfoKHR {
	StructureType                                            sType                  = StructureType::VideoEncodeSessionParametersGetInfoKHR;
	const void *                                             pNext                  = nullptr;
	impl_Struct::AssignableHandle<VideoSessionParametersKHR> videoSessionParameters;
};
struct VideoEncodeSessionRgbConversionCreateInfoVALVE {
	StructureType                           sType         = StructureType::VideoEncodeSessionRgbConversionCreateInfoVALVE;
	const void *                            pNext         = nullptr;
	VideoEncodeRgbModelConversionBitsVALVE  rgbModel      = VideoEncodeRgbModelConversionBitsVALVE::RgbIdentity;
	VideoEncodeRgbRangeCompressionBitsVALVE rgbRange      = VideoEncodeRgbRangeCompressionBitsVALVE::FullRange;
	VideoEncodeRgbChromaOffsetBitsVALVE     xChromaOffset = VideoEncodeRgbChromaOffsetBitsVALVE::CositedEven;
	VideoEncodeRgbChromaOffsetBitsVALVE     yChromaOffset = VideoEncodeRgbChromaOffsetBitsVALVE::CositedEven;
};
struct VideoEncodeUsageInfoKHR {
	StructureType              sType             = StructureType::VideoEncodeUsageInfoKHR;
	const void *               pNext             = nullptr;
	VideoEncodeUsageFlagsKHR   videoUsageHints   = {};
	VideoEncodeContentFlagsKHR videoContentHints = {};
	VideoEncodeTuningModeKHR   tuningMode        = VideoEncodeTuningModeKHR::Default;
};
struct VideoEndCodingInfoKHR {
	StructureType          sType = StructureType::VideoEndCodingInfoKHR;
	const void *           pNext = nullptr;
	VideoEndCodingFlagsKHR flags = {};
};
struct VideoFormatAV1QuantizationMapPropertiesKHR {
	StructureType                        sType                     = StructureType::VideoFormatAV1QuantizationMapPropertiesKHR;
	void *                               pNext                     = nullptr;
	VideoEncodeAV1SuperblockSizeFlagsKHR compatibleSuperblockSizes = {};
};
struct VideoFormatH265QuantizationMapPropertiesKHR {
	StructureType                  sType              = StructureType::VideoFormatH265QuantizationMapPropertiesKHR;
	void *                         pNext              = nullptr;
	VideoEncodeH265CtbSizeFlagsKHR compatibleCtbSizes = {};
};
struct VideoInlineQueryInfoKHR {
	StructureType                            sType      = StructureType::VideoInlineQueryInfoKHR;
	const void *                             pNext      = nullptr;
	impl_Struct::AssignableHandle<QueryPool> queryPool;
	uint32_t                                 firstQuery = 0;
	uint32_t                                 queryCount = 0;
};
struct VideoProfileInfoKHR {
	StructureType                  sType               = StructureType::VideoProfileInfoKHR;
	const void *                   pNext               = nullptr;
	VideoCodecOperationBitsKHR     videoCodecOperation = VideoCodecOperationBitsKHR::None;
	VideoChromaSubsamplingFlagsKHR chromaSubsampling   = {};
	VideoComponentBitDepthFlagsKHR lumaBitDepth        = {};
	VideoComponentBitDepthFlagsKHR chromaBitDepth      = {};
};
struct VideoReferenceIntraRefreshInfoKHR {
	StructureType sType                    = StructureType::VideoReferenceIntraRefreshInfoKHR;
	const void *  pNext                    = nullptr;
	uint32_t      dirtyIntraRefreshRegions = 0;
};
struct VideoSessionParametersCreateInfoKHR {
	StructureType                                            sType                          = StructureType::VideoSessionParametersCreateInfoKHR;
	const void *                                             pNext                          = nullptr;
	VideoSessionParametersCreateFlagsKHR                     flags                          = {};
	impl_Struct::AssignableHandle<VideoSessionParametersKHR> videoSessionParametersTemplate;
	impl_Struct::AssignableHandle<VideoSessionKHR>           videoSession;
};
struct VideoSessionParametersUpdateInfoKHR {
	StructureType sType               = StructureType::VideoSessionParametersUpdateInfoKHR;
	const void *  pNext               = nullptr;
	uint32_t      updateSequenceCount = 0;
};
struct Viewport {
	float x        = 0.0F;
	float y        = 0.0F;
	float width    = 0.0F;
	float height   = 0.0F;
	float minDepth = 0.0F;
	float maxDepth = 0.0F;
};
struct ViewportSwizzleNV {
	ViewportCoordinateSwizzleNV x = ViewportCoordinateSwizzleNV::Positivex;
	ViewportCoordinateSwizzleNV y = ViewportCoordinateSwizzleNV::Positivex;
	ViewportCoordinateSwizzleNV z = ViewportCoordinateSwizzleNV::Positivex;
	ViewportCoordinateSwizzleNV w = ViewportCoordinateSwizzleNV::Positivex;
};
struct ViewportWScalingNV {
	float xcoeff = 0.0F;
	float ycoeff = 0.0F;
};
struct WriteDescriptorSetAccelerationStructureKHR {
	StructureType                                                  sType                      = StructureType::WriteDescriptorSetAccelerationStructureKHR;
	const void *                                                   pNext                      = nullptr;
	uint32_t                                                       accelerationStructureCount = 0;
	const impl_Struct::AssignableHandle<AccelerationStructureKHR> *pAccelerationStructures    = nullptr;// len accelerationStructureCount
	auto accelerationStructures() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<AccelerationStructureKHR>>;
};
struct WriteDescriptorSetAccelerationStructureNV {
	StructureType                                                 sType                      = StructureType::WriteDescriptorSetAccelerationStructureNV;
	const void *                                                  pNext                      = nullptr;
	uint32_t                                                      accelerationStructureCount = 0;
	const impl_Struct::AssignableHandle<AccelerationStructureNV> *pAccelerationStructures    = nullptr;// len accelerationStructureCount
	auto accelerationStructures() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<AccelerationStructureNV>>;
};
struct WriteDescriptorSetInlineUniformBlock {
	StructureType sType    = StructureType::WriteDescriptorSetInlineUniformBlock;
	const void *  pNext    = nullptr;
	uint32_t      dataSize = 0;
	const void *  pData    = nullptr;// len dataSize
};
struct WriteDescriptorSetPartitionedAccelerationStructureNV {
	StructureType        sType                      = StructureType::WriteDescriptorSetPartitionedAccelerationStructureNV;
	void *               pNext                      = nullptr;
	uint32_t             accelerationStructureCount = 0;
	const DeviceAddress *pAccelerationStructures    = nullptr;// len accelerationStructureCount
	auto accelerationStructures() -> impl_Struct::VecView<uint32_t, DeviceAddress>;
};
struct WriteDescriptorSetTensorARM {
	StructureType                                       sType           = StructureType::WriteDescriptorSetTensorARM;
	const void *                                        pNext           = nullptr;
	uint32_t                                            tensorViewCount = 0;
	const impl_Struct::AssignableHandle<TensorViewARM> *pTensorViews    = nullptr;// len tensorViewCount
	auto tensorViews() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<TensorViewARM>>;
};
struct WriteIndirectExecutionSetPipelineEXT {
	StructureType                           sType    = StructureType::WriteIndirectExecutionSetPipelineEXT;
	const void *                            pNext    = nullptr;
	uint32_t                                index    = 0;
	impl_Struct::AssignableHandle<Pipeline> pipeline;
};
struct WriteIndirectExecutionSetShaderEXT {
	StructureType                            sType  = StructureType::WriteIndirectExecutionSetShaderEXT;
	const void *                             pNext  = nullptr;
	uint32_t                                 index  = 0;
	impl_Struct::AssignableHandle<ShaderEXT> shader;
};
struct XYColorEXT {
	float x = 0.0F;
	float y = 0.0F;
};
#ifdef VK_ENABLE_BETA_EXTENSIONS
	struct CudaFunctionCreateInfoNV {
		StructureType                               sType  = StructureType::CudaFunctionCreateInfoNV;
		const void *                                pNext  = nullptr;
		impl_Struct::AssignableHandle<CudaModuleNV> module;
		impl_Struct::InOutString                    name;
	};
	struct CudaLaunchInfoNV {
		StructureType                                 sType          = StructureType::CudaLaunchInfoNV;
		const void *                                  pNext          = nullptr;
		impl_Struct::AssignableHandle<CudaFunctionNV> function;
		uint32_t                                      gridDimX       = 0;
		uint32_t                                      gridDimY       = 0;
		uint32_t                                      gridDimZ       = 0;
		uint32_t                                      blockDimX      = 0;
		uint32_t                                      blockDimY      = 0;
		uint32_t                                      blockDimZ      = 0;
		uint32_t                                      sharedMemBytes = 0;
		size_t                                        paramCount     = 0;
		const void * const *                          pParams        = nullptr;// len paramCount
		size_t                                        extraCount     = 0;
		const void * const *                          pExtras        = nullptr;// len extraCount
	};
	struct CudaModuleCreateInfoNV {
		StructureType sType    = StructureType::CudaModuleCreateInfoNV;
		const void *  pNext    = nullptr;
		size_t        dataSize = 0;
		const void *  pData    = nullptr;// len dataSize
	};
	union DeviceOrHostAddressConstAMDX {
		DeviceAddress deviceAddress;
		const void *  hostAddress;
	};
	struct ExecutionGraphPipelineScratchSizeAMDX {
		StructureType sType           = StructureType::ExecutionGraphPipelineScratchSizeAMDX;
		void *        pNext           = nullptr;
		DeviceSize    minSize         = 0;
		DeviceSize    maxSize         = 0;
		DeviceSize    sizeGranularity = 0;
	};
	struct PhysicalDeviceCudaKernelLaunchFeaturesNV {
		StructureType sType                    = StructureType::PhysicalDeviceCudaKernelLaunchFeaturesNV;
		void *        pNext                    = nullptr;
		Bool32        cudaKernelLaunchFeatures = Constants::False;
	};
	struct PhysicalDeviceCudaKernelLaunchPropertiesNV {
		StructureType sType                  = StructureType::PhysicalDeviceCudaKernelLaunchPropertiesNV;
		void *        pNext                  = nullptr;
		uint32_t      computeCapabilityMinor = 0;
		uint32_t      computeCapabilityMajor = 0;
	};
	struct PhysicalDeviceDenseGeometryFormatFeaturesAMDX {
		StructureType sType               = StructureType::PhysicalDeviceDenseGeometryFormatFeaturesAMDX;
		void *        pNext               = nullptr;
		Bool32        denseGeometryFormat = Constants::False;
	};
	struct PhysicalDeviceDisplacementMicromapFeaturesNV {
		StructureType sType                = StructureType::PhysicalDeviceDisplacementMicromapFeaturesNV;
		void *        pNext                = nullptr;
		Bool32        displacementMicromap = Constants::False;
	};
	struct PhysicalDeviceDisplacementMicromapPropertiesNV {
		StructureType sType                                   = StructureType::PhysicalDeviceDisplacementMicromapPropertiesNV;
		void *        pNext                                   = nullptr;
		uint32_t      maxDisplacementMicromapSubdivisionLevel = 0;
	};
	struct PhysicalDevicePortabilitySubsetFeaturesKHR {
		StructureType sType                                  = StructureType::PhysicalDevicePortabilitySubsetFeaturesKHR;
		void *        pNext                                  = nullptr;
		Bool32        constantAlphaColorBlendFactors         = Constants::False;
		Bool32        events                                 = Constants::False;
		Bool32        imageViewFormatReinterpretation        = Constants::False;
		Bool32        imageViewFormatSwizzle                 = Constants::False;
		Bool32        imageView2DOn3DImage                   = Constants::False;
		Bool32        multisampleArrayImage                  = Constants::False;
		Bool32        mutableComparisonSamplers              = Constants::False;
		Bool32        pointPolygons                          = Constants::False;
		Bool32        samplerMipLodBias                      = Constants::False;
		Bool32        separateStencilMaskRef                 = Constants::False;
		Bool32        shaderSampleRateInterpolationFunctions = Constants::False;
		Bool32        tessellationIsolines                   = Constants::False;
		Bool32        tessellationPointMode                  = Constants::False;
		Bool32        triangleFans                           = Constants::False;
		Bool32        vertexAttributeAccessBeyondStride      = Constants::False;
	};
	struct PhysicalDevicePortabilitySubsetPropertiesKHR {
		StructureType sType                                = StructureType::PhysicalDevicePortabilitySubsetPropertiesKHR;
		void *        pNext                                = nullptr;
		uint32_t      minVertexInputBindingStrideAlignment = 0;
	};
	struct PhysicalDeviceShaderEnqueueFeaturesAMDX {
		StructureType sType             = StructureType::PhysicalDeviceShaderEnqueueFeaturesAMDX;
		void *        pNext             = nullptr;
		Bool32        shaderEnqueue     = Constants::False;
		Bool32        shaderMeshEnqueue = Constants::False;
	};
	struct PhysicalDeviceShaderEnqueuePropertiesAMDX {
		StructureType           sType                                  = StructureType::PhysicalDeviceShaderEnqueuePropertiesAMDX;
		void *                  pNext                                  = nullptr;
		uint32_t                maxExecutionGraphDepth                 = 0;
		uint32_t                maxExecutionGraphShaderOutputNodes     = 0;
		uint32_t                maxExecutionGraphShaderPayloadSize     = 0;
		uint32_t                maxExecutionGraphShaderPayloadCount    = 0;
		uint32_t                executionGraphDispatchAddressAlignment = 0;
		std::array<uint32_t, 3> maxExecutionGraphWorkgroupCount        = {};
		uint32_t                maxExecutionGraphWorkgroups            = 0;
	};
	struct PipelineShaderStageNodeCreateInfoAMDX {
		StructureType            sType = StructureType::PipelineShaderStageNodeCreateInfoAMDX;
		const void *             pNext = nullptr;
		impl_Struct::InOutString name;
		uint32_t                 index = 0;
	};
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_ANDROID_KHR
	struct AndroidHardwareBufferFormatResolvePropertiesANDROID {
		StructureType sType                 = StructureType::ANDROIDHardwareBufferFormatResolvePropertiesANDROID;
		void *        pNext                 = nullptr;
		Format        colorAttachmentFormat = Format::Undefined;
	};
	struct AndroidHardwareBufferPropertiesANDROID {
		StructureType sType          = StructureType::ANDROIDHardwareBufferPropertiesANDROID;
		void *        pNext          = nullptr;
		DeviceSize    allocationSize = 0;
		uint32_t      memoryTypeBits = 0;
	};
	struct AndroidHardwareBufferUsageANDROID {
		StructureType sType                      = StructureType::ANDROIDHardwareBufferUsageANDROID;
		void *        pNext                      = nullptr;
		uint64_t      androidHardwareBufferUsage = 0;
	};
	struct AndroidSurfaceCreateInfoKHR {
		StructureType                sType  = StructureType::ANDROIDSurfaceCreateInfoKHR;
		const void *                 pNext  = nullptr;
		AndroidSurfaceCreateFlagsKHR flags  = {};
		struct ANativeWindow *       window = nullptr;
	};
	struct ExternalFormatANDROID {
		StructureType sType          = StructureType::ExternalFormatANDROID;
		void *        pNext          = nullptr;
		uint64_t      externalFormat = 0;
	};
	struct ImportAndroidHardwareBufferInfoANDROID {
		StructureType           sType  = StructureType::ImportANDROIDHardwareBufferInfoANDROID;
		const void *            pNext  = nullptr;
		struct AHardwareBuffer *buffer = nullptr;
	};
	struct MemoryGetAndroidHardwareBufferInfoANDROID {
		StructureType                               sType  = StructureType::MemoryGetANDROIDHardwareBufferInfoANDROID;
		const void *                                pNext  = nullptr;
		impl_Struct::AssignableHandle<DeviceMemory> memory;
	};
	struct PhysicalDeviceExternalFormatResolveFeaturesANDROID {
		StructureType sType                 = StructureType::PhysicalDeviceExternalFormatResolveFeaturesANDROID;
		void *        pNext                 = nullptr;
		Bool32        externalFormatResolve = Constants::False;
	};
	struct PhysicalDeviceExternalFormatResolvePropertiesANDROID {
		StructureType  sType                                        = StructureType::PhysicalDeviceExternalFormatResolvePropertiesANDROID;
		void *         pNext                                        = nullptr;
		Bool32         nullColorAttachmentWithExternalFormatResolve = Constants::False;
		ChromaLocation externalFormatResolveChromaOffsetX           = ChromaLocation::CositedEven;
		ChromaLocation externalFormatResolveChromaOffsetY           = ChromaLocation::CositedEven;
	};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
	struct DirectFBSurfaceCreateInfoEXT {
		StructureType                 sType   = StructureType::DirectfbSurfaceCreateInfoEXT;
		const void *                  pNext   = nullptr;
		DirectFBSurfaceCreateFlagsEXT flags   = {};
		IDirectFB *                   dfb     = nullptr;
		IDirectFBSurface *            surface = nullptr;
	};
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
#ifdef VK_USE_PLATFORM_FUCHSIA
	struct BufferCollectionBufferCreateInfoFUCHSIA {
		StructureType                                          sType      = StructureType::BufferCollectionBufferCreateInfoFUCHSIA;
		const void *                                           pNext      = nullptr;
		impl_Struct::AssignableHandle<BufferCollectionFUCHSIA> collection;
		uint32_t                                               index      = 0;
	};
	struct BufferCollectionConstraintsInfoFUCHSIA {
		StructureType sType                           = StructureType::BufferCollectionConstraintsInfoFUCHSIA;
		const void *  pNext                           = nullptr;
		uint32_t      minBufferCount                  = 0;
		uint32_t      maxBufferCount                  = 0;
		uint32_t      minBufferCountForCamping        = 0;
		uint32_t      minBufferCountForDedicatedSlack = 0;
		uint32_t      minBufferCountForSharedSlack    = 0;
	};
	struct BufferCollectionCreateInfoFUCHSIA {
		StructureType sType           = StructureType::BufferCollectionCreateInfoFUCHSIA;
		const void *  pNext           = nullptr;
		zx_handle_t   collectionToken = {};
	};
	struct BufferCollectionImageCreateInfoFUCHSIA {
		StructureType                                          sType      = StructureType::BufferCollectionImageCreateInfoFUCHSIA;
		const void *                                           pNext      = nullptr;
		impl_Struct::AssignableHandle<BufferCollectionFUCHSIA> collection;
		uint32_t                                               index      = 0;
	};
	struct ImagePipeSurfaceCreateInfoFUCHSIA {
		StructureType                      sType           = StructureType::ImagepipeSurfaceCreateInfoFUCHSIA;
		const void *                       pNext           = nullptr;
		ImagePipeSurfaceCreateFlagsFUCHSIA flags           = {};
		zx_handle_t                        imagePipeHandle = {};
	};
	struct ImportMemoryBufferCollectionFUCHSIA {
		StructureType                                          sType      = StructureType::ImportMemoryBufferCollectionFUCHSIA;
		const void *                                           pNext      = nullptr;
		impl_Struct::AssignableHandle<BufferCollectionFUCHSIA> collection;
		uint32_t                                               index      = 0;
	};
	struct ImportMemoryZirconHandleInfoFUCHSIA {
		StructureType                sType      = StructureType::ImportMemoryZirconHandleInfoFUCHSIA;
		const void *                 pNext      = nullptr;
		ExternalMemoryHandleTypeBits handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
		zx_handle_t                  handle     = {};
	};
	struct ImportSemaphoreZirconHandleInfoFUCHSIA {
		StructureType                            sType        = StructureType::ImportSemaphoreZirconHandleInfoFUCHSIA;
		const void *                             pNext        = nullptr;
		impl_Struct::AssignableHandle<Semaphore> semaphore;
		SemaphoreImportFlags                     flags        = {};
		ExternalSemaphoreHandleTypeBits          handleType   = ExternalSemaphoreHandleTypeBits::OpaqueFd;
		zx_handle_t                              zirconHandle = {};
	};
	struct MemoryGetZirconHandleInfoFUCHSIA {
		StructureType                               sType      = StructureType::MemoryGetZirconHandleInfoFUCHSIA;
		const void *                                pNext      = nullptr;
		impl_Struct::AssignableHandle<DeviceMemory> memory;
		ExternalMemoryHandleTypeBits                handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
	};
	struct MemoryZirconHandlePropertiesFUCHSIA {
		StructureType sType          = StructureType::MemoryZirconHandlePropertiesFUCHSIA;
		void *        pNext          = nullptr;
		uint32_t      memoryTypeBits = 0;
	};
	struct SemaphoreGetZirconHandleInfoFUCHSIA {
		StructureType                            sType      = StructureType::SemaphoreGetZirconHandleInfoFUCHSIA;
		const void *                             pNext      = nullptr;
		impl_Struct::AssignableHandle<Semaphore> semaphore;
		ExternalSemaphoreHandleTypeBits          handleType = ExternalSemaphoreHandleTypeBits::OpaqueFd;
	};
	struct SysmemColorSpaceFUCHSIA {
		StructureType sType      = StructureType::SysmemColorSpaceFUCHSIA;
		const void *  pNext      = nullptr;
		uint32_t      colorSpace = 0;
	};
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_GGP
	struct PresentFrameTokenGGP {
		StructureType sType      = StructureType::PresentFrameTokenGGP;
		const void *  pNext      = nullptr;
		GgpFrameToken frameToken = {};
	};
	struct StreamDescriptorSurfaceCreateInfoGGP {
		StructureType                         sType            = StructureType::StreamDescriptorSurfaceCreateInfoGGP;
		const void *                          pNext            = nullptr;
		StreamDescriptorSurfaceCreateFlagsGGP flags            = {};
		GgpStreamDescriptor                   streamDescriptor = {};
	};
#endif // VK_USE_PLATFORM_GGP
#ifdef VK_USE_PLATFORM_IOS_MVK
	struct IOSSurfaceCreateInfoMVK {
		StructureType            sType = StructureType::IosSurfaceCreateInfoMVK;
		const void *             pNext = nullptr;
		IOSSurfaceCreateFlagsMVK flags = {};
		const void *             pView = nullptr;
	};
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
	struct MacOSSurfaceCreateInfoMVK {
		StructureType              sType = StructureType::MacosSurfaceCreateInfoMVK;
		const void *               pNext = nullptr;
		MacOSSurfaceCreateFlagsMVK flags = {};
		const void *               pView = nullptr;
	};
#endif // VK_USE_PLATFORM_MACOS_MVK
#ifdef VK_USE_PLATFORM_METAL_EXT
	struct ExportMetalBufferInfoEXT {
		StructureType                               sType     = StructureType::ExportMetalBufferInfoEXT;
		const void *                                pNext     = nullptr;
		impl_Struct::AssignableHandle<DeviceMemory> memory;
		MTLBuffer_id                                mtlBuffer = {};
	};
	struct ExportMetalCommandQueueInfoEXT {
		StructureType                        sType           = StructureType::ExportMetalCommandQueueInfoEXT;
		const void *                         pNext           = nullptr;
		impl_Struct::AssignableHandle<Queue> queue;
		MTLCommandQueue_id                   mtlCommandQueue = {};
	};
	struct ExportMetalDeviceInfoEXT {
		StructureType sType     = StructureType::ExportMetalDeviceInfoEXT;
		const void *  pNext     = nullptr;
		MTLDevice_id  mtlDevice = {};
	};
	struct ExportMetalIOSurfaceInfoEXT {
		StructureType                        sType     = StructureType::ExportMetalIoSurfaceInfoEXT;
		const void *                         pNext     = nullptr;
		impl_Struct::AssignableHandle<Image> image;
		IOSurfaceRef                         ioSurface = {};
	};
	struct ExportMetalObjectCreateInfoEXT {
		StructureType                sType            = StructureType::ExportMetalObjectCreateInfoEXT;
		const void *                 pNext            = nullptr;
		ExportMetalObjectTypeBitsEXT exportObjectType = ExportMetalObjectTypeBitsEXT::MetalDevice;
	};
	struct ExportMetalObjectsInfoEXT {
		StructureType sType = StructureType::ExportMetalObjectsInfoEXT;
		const void *  pNext = nullptr;
	};
	struct ExportMetalSharedEventInfoEXT {
		StructureType                            sType          = StructureType::ExportMetalSharedEventInfoEXT;
		const void *                             pNext          = nullptr;
		impl_Struct::AssignableHandle<Semaphore> semaphore;
		impl_Struct::AssignableHandle<Event>     event;
		MTLSharedEvent_id                        mtlSharedEvent = {};
	};
	struct ExportMetalTextureInfoEXT {
		StructureType                             sType      = StructureType::ExportMetalTextureInfoEXT;
		const void *                              pNext      = nullptr;
		impl_Struct::AssignableHandle<Image>      image;
		impl_Struct::AssignableHandle<ImageView>  imageView;
		impl_Struct::AssignableHandle<BufferView> bufferView;
		ImageAspectBits                           plane      = ImageAspectBits::None;
		MTLTexture_id                             mtlTexture = {};
	};
	struct ImportMemoryMetalHandleInfoEXT {
		StructureType                sType      = StructureType::ImportMemoryMetalHandleInfoEXT;
		const void *                 pNext      = nullptr;
		ExternalMemoryHandleTypeBits handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
		void *                       handle     = nullptr;
	};
	struct ImportMetalBufferInfoEXT {
		StructureType sType     = StructureType::ImportMetalBufferInfoEXT;
		const void *  pNext     = nullptr;
		MTLBuffer_id  mtlBuffer = {};
	};
	struct ImportMetalIOSurfaceInfoEXT {
		StructureType sType     = StructureType::ImportMetalIoSurfaceInfoEXT;
		const void *  pNext     = nullptr;
		IOSurfaceRef  ioSurface = {};
	};
	struct ImportMetalSharedEventInfoEXT {
		StructureType     sType          = StructureType::ImportMetalSharedEventInfoEXT;
		const void *      pNext          = nullptr;
		MTLSharedEvent_id mtlSharedEvent = {};
	};
	struct ImportMetalTextureInfoEXT {
		StructureType   sType      = StructureType::ImportMetalTextureInfoEXT;
		const void *    pNext      = nullptr;
		ImageAspectBits plane      = ImageAspectBits::None;
		MTLTexture_id   mtlTexture = {};
	};
	struct MemoryGetMetalHandleInfoEXT {
		StructureType                               sType      = StructureType::MemoryGetMetalHandleInfoEXT;
		const void *                                pNext      = nullptr;
		impl_Struct::AssignableHandle<DeviceMemory> memory;
		ExternalMemoryHandleTypeBits                handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
	};
	struct MemoryMetalHandlePropertiesEXT {
		StructureType sType          = StructureType::MemoryMetalHandlePropertiesEXT;
		void *        pNext          = nullptr;
		uint32_t      memoryTypeBits = 0;
	};
	struct MetalSurfaceCreateInfoEXT {
		StructureType              sType  = StructureType::MetalSurfaceCreateInfoEXT;
		const void *               pNext  = nullptr;
		MetalSurfaceCreateFlagsEXT flags  = {};
		const CAMetalLayer *       pLayer = nullptr;
	};
#endif // VK_USE_PLATFORM_METAL_EXT
#ifdef VK_USE_PLATFORM_OHOS
	struct ExternalFormatOHOS {
		StructureType sType          = StructureType::ExternalFormatOHOS;
		void *        pNext          = nullptr;
		uint64_t      externalFormat = 0;
	};
	struct ImportNativeBufferInfoOHOS {
		StructureType           sType  = StructureType::ImportNativeBufferInfoOHOS;
		const void *            pNext  = nullptr;
		struct OH_NativeBuffer *buffer = nullptr;
	};
	struct MemoryGetNativeBufferInfoOHOS {
		StructureType                               sType  = StructureType::MemoryGetNativeBufferInfoOHOS;
		const void *                                pNext  = nullptr;
		impl_Struct::AssignableHandle<DeviceMemory> memory;
	};
	struct NativeBufferPropertiesOHOS {
		StructureType sType          = StructureType::NativeBufferPropertiesOHOS;
		void *        pNext          = nullptr;
		DeviceSize    allocationSize = 0;
		uint32_t      memoryTypeBits = 0;
	};
	struct NativeBufferUsageOHOS {
		StructureType sType                 = StructureType::NativeBufferUsageOHOS;
		void *        pNext                 = nullptr;
		uint64_t      OHOSNativeBufferUsage = 0;
	};
	struct SurfaceCreateInfoOHOS {
		StructureType          sType  = StructureType::SurfaceCreateInfoOHOS;
		const void *           pNext  = nullptr;
		SurfaceCreateFlagsOHOS flags  = {};
		OHNativeWindow *       window = nullptr;
	};
#endif // VK_USE_PLATFORM_OHOS
#ifdef VK_USE_PLATFORM_SCREEN_QNX
	struct ExternalFormatQNX {
		StructureType sType          = StructureType::ExternalFormatQNX;
		void *        pNext          = nullptr;
		uint64_t      externalFormat = 0;
	};
	struct ImportScreenBufferInfoQNX {
		StructureType          sType  = StructureType::ImportScreenBufferInfoQNX;
		const void *           pNext  = nullptr;
		struct _screen_buffer *buffer = nullptr;
	};
	struct PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX {
		StructureType sType              = StructureType::PhysicalDeviceExternalMemoryScreenBufferFeaturesQNX;
		void *        pNext              = nullptr;
		Bool32        screenBufferImport = Constants::False;
	};
	struct ScreenBufferPropertiesQNX {
		StructureType sType          = StructureType::ScreenBufferPropertiesQNX;
		void *        pNext          = nullptr;
		DeviceSize    allocationSize = 0;
		uint32_t      memoryTypeBits = 0;
	};
	struct ScreenSurfaceCreateInfoQNX {
		StructureType               sType   = StructureType::ScreenSurfaceCreateInfoQNX;
		const void *                pNext   = nullptr;
		ScreenSurfaceCreateFlagsQNX flags   = {};
		struct _screen_context *    context = nullptr;
		struct _screen_window *     window  = nullptr;
	};
#endif // VK_USE_PLATFORM_SCREEN_QNX
#ifdef VK_USE_PLATFORM_UBM_SEC
	struct UbmSurfaceCreateInfoSEC {
		StructureType            sType   = StructureType::UbmSurfaceCreateInfoSEC;
		const void *             pNext   = nullptr;
		UbmSurfaceCreateFlagsSEC flags   = {};
		struct ubm_device *      device  = nullptr;
		struct ubm_surface *     surface = nullptr;
	};
#endif // VK_USE_PLATFORM_UBM_SEC
#ifdef VK_USE_PLATFORM_VI_NN
	struct ViSurfaceCreateInfoNN {
		StructureType          sType  = StructureType::ViSurfaceCreateInfoNN;
		const void *           pNext  = nullptr;
		ViSurfaceCreateFlagsNN flags  = {};
		void *                 window = nullptr;
	};
#endif // VK_USE_PLATFORM_VI_NN
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
	struct WaylandSurfaceCreateInfoKHR {
		StructureType                sType   = StructureType::WaylandSurfaceCreateInfoKHR;
		const void *                 pNext   = nullptr;
		WaylandSurfaceCreateFlagsKHR flags   = {};
		struct wl_display *          display = nullptr;
		struct wl_surface *          surface = nullptr;
	};
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
	struct D3D12FenceSubmitInfoKHR {
		StructureType   sType                      = StructureType::D3D12FenceSubmitInfoKHR;
		const void *    pNext                      = nullptr;
		uint32_t        waitSemaphoreValuesCount   = 0;
		const uint64_t *pWaitSemaphoreValues       = nullptr;// len waitSemaphoreValuesCount
		uint32_t        signalSemaphoreValuesCount = 0;
		const uint64_t *pSignalSemaphoreValues     = nullptr;// len signalSemaphoreValuesCount
		auto waitSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t>;
		auto signalSemaphoreValues() -> impl_Struct::VecView<uint32_t, uint64_t>;
	};
	struct ExportFenceWin32HandleInfoKHR {
		StructureType              sType       = StructureType::ExportFenceWin32HandleInfoKHR;
		const void *               pNext       = nullptr;
		const SECURITY_ATTRIBUTES *pAttributes = nullptr;
		DWORD                      dwAccess    = {};
		LPCWSTR                    name        = {};
	};
	struct ExportMemoryWin32HandleInfoKHR {
		StructureType              sType       = StructureType::ExportMemoryWin32HandleInfoKHR;
		const void *               pNext       = nullptr;
		const SECURITY_ATTRIBUTES *pAttributes = nullptr;
		DWORD                      dwAccess    = {};
		LPCWSTR                    name        = {};
	};
	struct ExportMemoryWin32HandleInfoNV {
		StructureType              sType       = StructureType::ExportMemoryWin32HandleInfoNV;
		const void *               pNext       = nullptr;
		const SECURITY_ATTRIBUTES *pAttributes = nullptr;
		DWORD                      dwAccess    = {};
	};
	struct ExportSemaphoreWin32HandleInfoKHR {
		StructureType              sType       = StructureType::ExportSemaphoreWin32HandleInfoKHR;
		const void *               pNext       = nullptr;
		const SECURITY_ATTRIBUTES *pAttributes = nullptr;
		DWORD                      dwAccess    = {};
		LPCWSTR                    name        = {};
	};
	struct FenceGetWin32HandleInfoKHR {
		StructureType                        sType      = StructureType::FenceGetWin32HandleInfoKHR;
		const void *                         pNext      = nullptr;
		impl_Struct::AssignableHandle<Fence> fence;
		ExternalFenceHandleTypeBits          handleType = ExternalFenceHandleTypeBits::OpaqueFd;
	};
	struct ImportFenceWin32HandleInfoKHR {
		StructureType                        sType      = StructureType::ImportFenceWin32HandleInfoKHR;
		const void *                         pNext      = nullptr;
		impl_Struct::AssignableHandle<Fence> fence;
		FenceImportFlags                     flags      = {};
		ExternalFenceHandleTypeBits          handleType = ExternalFenceHandleTypeBits::OpaqueFd;
		HANDLE                               handle     = {};
		LPCWSTR                              name       = {};
	};
	struct ImportMemoryWin32HandleInfoKHR {
		StructureType                sType      = StructureType::ImportMemoryWin32HandleInfoKHR;
		const void *                 pNext      = nullptr;
		ExternalMemoryHandleTypeBits handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
		HANDLE                       handle     = {};
		LPCWSTR                      name       = {};
	};
	struct ImportMemoryWin32HandleInfoNV {
		StructureType                   sType      = StructureType::ImportMemoryWin32HandleInfoNV;
		const void *                    pNext      = nullptr;
		ExternalMemoryHandleTypeFlagsNV handleType = {};
		HANDLE                          handle     = {};
	};
	struct ImportSemaphoreWin32HandleInfoKHR {
		StructureType                            sType      = StructureType::ImportSemaphoreWin32HandleInfoKHR;
		const void *                             pNext      = nullptr;
		impl_Struct::AssignableHandle<Semaphore> semaphore;
		SemaphoreImportFlags                     flags      = {};
		ExternalSemaphoreHandleTypeBits          handleType = ExternalSemaphoreHandleTypeBits::OpaqueFd;
		HANDLE                                   handle     = {};
		LPCWSTR                                  name       = {};
	};
	struct MemoryGetWin32HandleInfoKHR {
		StructureType                               sType      = StructureType::MemoryGetWin32HandleInfoKHR;
		const void *                                pNext      = nullptr;
		impl_Struct::AssignableHandle<DeviceMemory> memory;
		ExternalMemoryHandleTypeBits                handleType = ExternalMemoryHandleTypeBits::OpaqueFd;
	};
	struct MemoryWin32HandlePropertiesKHR {
		StructureType sType          = StructureType::MemoryWin32HandlePropertiesKHR;
		void *        pNext          = nullptr;
		uint32_t      memoryTypeBits = 0;
	};
	struct SemaphoreGetWin32HandleInfoKHR {
		StructureType                            sType      = StructureType::SemaphoreGetWin32HandleInfoKHR;
		const void *                             pNext      = nullptr;
		impl_Struct::AssignableHandle<Semaphore> semaphore;
		ExternalSemaphoreHandleTypeBits          handleType = ExternalSemaphoreHandleTypeBits::OpaqueFd;
	};
	struct SurfaceCapabilitiesFullScreenExclusiveEXT {
		StructureType sType                        = StructureType::SurfaceCapabilitiesFullScreenExclusiveEXT;
		void *        pNext                        = nullptr;
		Bool32        fullScreenExclusiveSupported = Constants::False;
	};
	struct SurfaceFullScreenExclusiveInfoEXT {
		StructureType          sType               = StructureType::SurfaceFullScreenExclusiveInfoEXT;
		void *                 pNext               = nullptr;
		FullScreenExclusiveEXT fullScreenExclusive = FullScreenExclusiveEXT::Default;
	};
	struct SurfaceFullScreenExclusiveWin32InfoEXT {
		StructureType sType    = StructureType::SurfaceFullScreenExclusiveWin32InfoEXT;
		const void *  pNext    = nullptr;
		HMONITOR      hmonitor = {};
	};
	struct Win32KeyedMutexAcquireReleaseInfoKHR {
		StructureType                                      sType            = StructureType::Win32KeyedMutexAcquireReleaseInfoKHR;
		const void *                                       pNext            = nullptr;
		uint32_t                                           acquireCount     = 0;
		const impl_Struct::AssignableHandle<DeviceMemory> *pAcquireSyncs    = nullptr;// len acquireCount
		const uint64_t *                                   pAcquireKeys     = nullptr;// len acquireCount
		const uint32_t *                                   pAcquireTimeouts = nullptr;// len acquireCount
		uint32_t                                           releaseCount     = 0;
		const impl_Struct::AssignableHandle<DeviceMemory> *pReleaseSyncs    = nullptr;// len releaseCount
		const uint64_t *                                   pReleaseKeys     = nullptr;// len releaseCount
		auto acquireSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>>;
		auto releaseSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>>;
	};
	struct Win32KeyedMutexAcquireReleaseInfoNV {
		StructureType                                      sType                       = StructureType::Win32KeyedMutexAcquireReleaseInfoNV;
		const void *                                       pNext                       = nullptr;
		uint32_t                                           acquireCount                = 0;
		const impl_Struct::AssignableHandle<DeviceMemory> *pAcquireSyncs               = nullptr;// len acquireCount
		const uint64_t *                                   pAcquireKeys                = nullptr;// len acquireCount
		const uint32_t *                                   pAcquireTimeoutMilliseconds = nullptr;// len acquireCount
		uint32_t                                           releaseCount                = 0;
		const impl_Struct::AssignableHandle<DeviceMemory> *pReleaseSyncs               = nullptr;// len releaseCount
		const uint64_t *                                   pReleaseKeys                = nullptr;// len releaseCount
		auto acquireSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>>;
		auto releaseSyncs() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DeviceMemory>>;
	};
	struct Win32SurfaceCreateInfoKHR {
		StructureType              sType     = StructureType::Win32SurfaceCreateInfoKHR;
		const void *               pNext     = nullptr;
		Win32SurfaceCreateFlagsKHR flags     = {};
		HINSTANCE                  hinstance = {};
		HWND                       hwnd      = {};
	};
#endif // VK_USE_PLATFORM_WIN32_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
	struct XcbSurfaceCreateInfoKHR {
		StructureType            sType      = StructureType::XcbSurfaceCreateInfoKHR;
		const void *             pNext      = nullptr;
		XcbSurfaceCreateFlagsKHR flags      = {};
		xcb_connection_t *       connection = nullptr;
		xcb_window_t             window     = {};
	};
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_XLIB_KHR
	struct XlibSurfaceCreateInfoKHR {
		StructureType             sType  = StructureType::XlibSurfaceCreateInfoKHR;
		const void *              pNext  = nullptr;
		XlibSurfaceCreateFlagsKHR flags  = {};
		Display *                 dpy    = nullptr;
		Window                    window = {};
	};
#endif // VK_USE_PLATFORM_XLIB_KHR
struct AccelerationStructureCreateInfo2KHR {
	StructureType                       sType        = StructureType::AccelerationStructureCreateInfo2KHR;
	const void *                        pNext        = nullptr;
	AccelerationStructureCreateFlagsKHR createFlags  = {};
	DeviceAddressRangeKHR               addressRange = {};
	AddressCommandFlagsKHR              addressFlags = {};
	AccelerationStructureTypeKHR        type         = AccelerationStructureTypeKHR::TopLevel;
};
struct AccelerationStructureGeometryAabbsDataKHR {
	StructureType               sType  = StructureType::AccelerationStructureGeometryAabbsDataKHR;
	const void *                pNext  = nullptr;
	DeviceOrHostAddressConstKHR data   = {};
	DeviceSize                  stride = 0;
};
struct AccelerationStructureGeometryInstancesDataKHR {
	StructureType               sType           = StructureType::AccelerationStructureGeometryInstancesDataKHR;
	const void *                pNext           = nullptr;
	Bool32                      arrayOfPointers = Constants::False;
	DeviceOrHostAddressConstKHR data            = {};
};
struct AccelerationStructureGeometryLinearSweptSpheresDataNV {
	StructureType                       sType        = StructureType::AccelerationStructureGeometryLinearSweptSpheresDataNV;
	const void *                        pNext        = nullptr;
	Format                              vertexFormat = Format::Undefined;
	DeviceOrHostAddressConstKHR         vertexData   = {};
	DeviceSize                          vertexStride = 0;
	Format                              radiusFormat = Format::Undefined;
	DeviceOrHostAddressConstKHR         radiusData   = {};
	DeviceSize                          radiusStride = 0;
	IndexType                           indexType    = IndexType::Uint16;
	DeviceOrHostAddressConstKHR         indexData    = {};
	DeviceSize                          indexStride  = 0;
	RayTracingLssIndexingModeNV         indexingMode = RayTracingLssIndexingModeNV::List;
	RayTracingLssPrimitiveEndCapsModeNV endCapsMode  = RayTracingLssPrimitiveEndCapsModeNV::None;
};
struct AccelerationStructureGeometryMicromapDataKHR {
	StructureType                  sType               = StructureType::AccelerationStructureGeometryMicromapDataKHR;
	const void *                   pNext               = nullptr;
	uint32_t                       usageCountsCount    = 0;
	const MicromapUsageKHR *       pUsageCounts        = nullptr;// len usageCountsCount
	const MicromapUsageKHR * const*ppUsageCounts       = nullptr;// len usageCountsCount,1
	DeviceAddress                  data                = 0;
	DeviceAddress                  triangleArray       = 0;
	DeviceSize                     triangleArrayStride = 0;
	auto usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageKHR>;
};
struct AccelerationStructureGeometryMotionTrianglesDataNV {
	StructureType               sType      = StructureType::AccelerationStructureGeometryMotionTrianglesDataNV;
	const void *                pNext      = nullptr;
	DeviceOrHostAddressConstKHR vertexData = {};
};
struct AccelerationStructureGeometrySpheresDataNV {
	StructureType               sType        = StructureType::AccelerationStructureGeometrySpheresDataNV;
	const void *                pNext        = nullptr;
	Format                      vertexFormat = Format::Undefined;
	DeviceOrHostAddressConstKHR vertexData   = {};
	DeviceSize                  vertexStride = 0;
	Format                      radiusFormat = Format::Undefined;
	DeviceOrHostAddressConstKHR radiusData   = {};
	DeviceSize                  radiusStride = 0;
	IndexType                   indexType    = IndexType::Uint16;
	DeviceOrHostAddressConstKHR indexData    = {};
	DeviceSize                  indexStride  = 0;
};
struct AccelerationStructureGeometryTrianglesDataKHR {
	StructureType               sType         = StructureType::AccelerationStructureGeometryTrianglesDataKHR;
	const void *                pNext         = nullptr;
	Format                      vertexFormat  = Format::Undefined;
	DeviceOrHostAddressConstKHR vertexData    = {};
	DeviceSize                  vertexStride  = 0;
	uint32_t                    maxVertex     = 0;
	IndexType                   indexType     = IndexType::Uint16;
	DeviceOrHostAddressConstKHR indexData     = {};
	DeviceOrHostAddressConstKHR transformData = {};
};
struct AccelerationStructureInstanceKHR {
	TransformMatrixKHR                 transform                                 = {};
	uint32_t                           instanceCustomIndex:24                    = 0;
	uint32_t                           mask:8                                    = 0;
	uint32_t                           instanceShaderBindingTableRecordOffset:24 = 0;
	GeometryInstanceFlagsKHR::MaskType flags:8                                   = 0;
	uint64_t                           accelerationStructureReference            = 0;
};
struct AccelerationStructureMatrixMotionInstanceNV {
	TransformMatrixKHR                 transformT0                               = {};
	TransformMatrixKHR                 transformT1                               = {};
	uint32_t                           instanceCustomIndex:24                    = 0;
	uint32_t                           mask:8                                    = 0;
	uint32_t                           instanceShaderBindingTableRecordOffset:24 = 0;
	GeometryInstanceFlagsKHR::MaskType flags:8                                   = 0;
	uint64_t                           accelerationStructureReference            = 0;
};
struct AccelerationStructureSRTMotionInstanceNV {
	SRTDataNV                          transformT0                               = {};
	SRTDataNV                          transformT1                               = {};
	uint32_t                           instanceCustomIndex:24                    = 0;
	uint32_t                           mask:8                                    = 0;
	uint32_t                           instanceShaderBindingTableRecordOffset:24 = 0;
	GeometryInstanceFlagsKHR::MaskType flags:8                                   = 0;
	uint64_t                           accelerationStructureReference            = 0;
};
struct AccelerationStructureTrianglesOpacityMicromapEXT {
	StructureType                              sType            = StructureType::AccelerationStructureTrianglesOpacityMicromapEXT;
	void *                                     pNext            = nullptr;
	IndexType                                  indexType        = IndexType::Uint16;
	DeviceOrHostAddressConstKHR                indexBuffer      = {};
	DeviceSize                                 indexStride      = 0;
	uint32_t                                   baseTriangle     = 0;
	uint32_t                                   usageCountsCount = 0;
	const MicromapUsageEXT *                   pUsageCounts     = nullptr;// len usageCountsCount
	const MicromapUsageEXT * const*            ppUsageCounts    = nullptr;// len usageCountsCount,1
	impl_Struct::AssignableHandle<MicromapEXT> micromap;
	auto usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageEXT>;
};
struct AntiLagDataAMD {
	StructureType                     sType             = StructureType::AntiLagDataAMD;
	const void *                      pNext             = nullptr;
	AntiLagModeAMD                    mode              = AntiLagModeAMD::DriverControl;
	uint32_t                          maxFPS            = 0;
	const AntiLagPresentationInfoAMD *pPresentationInfo = nullptr;
};
struct BindHeapInfoEXT {
	StructureType         sType               = StructureType::BindHeapInfoEXT;
	const void *          pNext               = nullptr;
	DeviceAddressRangeKHR heapRange           = {};
	DeviceSize            reservedRangeOffset = 0;
	DeviceSize            reservedRangeSize   = 0;
};
struct BindIndexBuffer3InfoKHR {
	StructureType          sType        = StructureType::BindIndexBuffer3InfoKHR;
	const void *           pNext        = nullptr;
	DeviceAddressRangeKHR  addressRange = {};
	AddressCommandFlagsKHR addressFlags = {};
	IndexType              indexType    = IndexType::Uint16;
};
struct BindTransformFeedbackBuffer2InfoEXT {
	StructureType          sType        = StructureType::BindTransformFeedbackBuffer2InfoEXT;
	const void *           pNext        = nullptr;
	DeviceAddressRangeKHR  addressRange = {};
	AddressCommandFlagsKHR addressFlags = {};
};
struct BindVertexBuffer3InfoKHR {
	StructureType                sType        = StructureType::BindVertexBuffer3InfoKHR;
	const void *                 pNext        = nullptr;
	Bool32                       setStride    = Constants::False;
	StridedDeviceAddressRangeKHR addressRange = {};
	AddressCommandFlagsKHR       addressFlags = {};
};
struct BufferImageCopy {
	DeviceSize             bufferOffset      = 0;
	uint32_t               bufferRowLength   = 0;
	uint32_t               bufferImageHeight = 0;
	ImageSubresourceLayers imageSubresource  = {};
	Offset3D               imageOffset       = {};
	Extent3D               imageExtent       = {};
};
struct BufferImageCopy2 {
	StructureType          sType             = StructureType::BufferImageCopy2;
	const void *           pNext             = nullptr;
	DeviceSize             bufferOffset      = 0;
	uint32_t               bufferRowLength   = 0;
	uint32_t               bufferImageHeight = 0;
	ImageSubresourceLayers imageSubresource  = {};
	Offset3D               imageOffset       = {};
	Extent3D               imageExtent       = {};
};
struct BuildPartitionedAccelerationStructureIndirectCommandNV {
	PartitionedAccelerationStructureOpTypeNV opType   = PartitionedAccelerationStructureOpTypeNV::WriteInstance;
	uint32_t                                 argCount = 0;
	StridedDeviceAddressNV                   argData  = {};
};
struct BuildPartitionedAccelerationStructureInfoNV {
	StructureType                                    sType                        = StructureType::BuildPartitionedAccelerationStructureInfoNV;
	void *                                           pNext                        = nullptr;
	PartitionedAccelerationStructureInstancesInputNV input                        = {};
	DeviceAddress                                    srcAccelerationStructureData = 0;
	DeviceAddress                                    dstAccelerationStructureData = 0;
	DeviceAddress                                    scratchData                  = 0;
	DeviceAddress                                    srcInfos                     = 0;
	DeviceAddress                                    srcInfosCount                = 0;
};
union ClearValue {
	ClearColorValue        color;
	ClearDepthStencilValue depthStencil;
};
struct ClusterAccelerationStructureBuildTriangleClusterInfoNV {
	uint32_t                                                    clusterID                         = 0;
	ClusterAccelerationStructureClusterFlagsNV                  clusterFlags                      = {};
	uint32_t                                                    triangleCount:9                   = 0;
	uint32_t                                                    vertexCount:9                     = 0;
	uint32_t                                                    positionTruncateBitCount:6        = 0;
	uint32_t                                                    indexType:4                       = 0;
	uint32_t                                                    opacityMicromapIndexType:4        = 0;
	ClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV baseGeometryIndexAndGeometryFlags = {};
	uint16_t                                                    indexBufferStride                 = 0;
	uint16_t                                                    vertexBufferStride                = 0;
	uint16_t                                                    geometryIndexAndFlagsBufferStride = 0;
	uint16_t                                                    opacityMicromapIndexBufferStride  = 0;
	DeviceAddress                                               indexBuffer                       = 0;
	DeviceAddress                                               vertexBuffer                      = 0;
	DeviceAddress                                               geometryIndexAndFlagsBuffer       = 0;
	DeviceAddress                                               opacityMicromapArray              = 0;
	DeviceAddress                                               opacityMicromapIndexBuffer        = 0;
};
struct ClusterAccelerationStructureBuildTriangleClusterTemplateInfoNV {
	uint32_t                                                    clusterID                         = 0;
	ClusterAccelerationStructureClusterFlagsNV                  clusterFlags                      = {};
	uint32_t                                                    triangleCount:9                   = 0;
	uint32_t                                                    vertexCount:9                     = 0;
	uint32_t                                                    positionTruncateBitCount:6        = 0;
	uint32_t                                                    indexType:4                       = 0;
	uint32_t                                                    opacityMicromapIndexType:4        = 0;
	ClusterAccelerationStructureGeometryIndexAndGeometryFlagsNV baseGeometryIndexAndGeometryFlags = {};
	uint16_t                                                    indexBufferStride                 = 0;
	uint16_t                                                    vertexBufferStride                = 0;
	uint16_t                                                    geometryIndexAndFlagsBufferStride = 0;
	uint16_t                                                    opacityMicromapIndexBufferStride  = 0;
	DeviceAddress                                               indexBuffer                       = 0;
	DeviceAddress                                               vertexBuffer                      = 0;
	DeviceAddress                                               geometryIndexAndFlagsBuffer       = 0;
	DeviceAddress                                               opacityMicromapArray              = 0;
	DeviceAddress                                               opacityMicromapIndexBuffer        = 0;
	DeviceAddress                                               instantiationBoundingBoxLimit     = 0;
};
struct ClusterAccelerationStructureInstantiateClusterInfoNV {
	uint32_t               clusterIdOffset        = 0;
	uint32_t               geometryIndexOffset:24 = 0;
	uint32_t               reserved:8             = 0;
	DeviceAddress          clusterTemplateAddress = 0;
	StridedDeviceAddressNV vertexBuffer           = {};
};
union ClusterAccelerationStructureOpInputNV {
	ClusterAccelerationStructureClustersBottomLevelInputNV *pClustersBottomLevel;
	ClusterAccelerationStructureTriangleClusterInputNV *    pTriangleClusters;
	ClusterAccelerationStructureMoveObjectsInputNV *        pMoveObjects;
};
struct CoarseSampleOrderCustomNV {
	ShadingRatePaletteEntryNV     shadingRate         = ShadingRatePaletteEntryNV::NoInvocations;
	uint32_t                      sampleCount         = 0;
	uint32_t                      sampleLocationCount = 0;
	const CoarseSampleLocationNV *pSampleLocations    = nullptr;// len sampleLocationCount
	auto sampleLocations() -> impl_Struct::VecView<uint32_t, CoarseSampleLocationNV>;
};
struct CommandBufferBeginInfo {
	StructureType                       sType            = StructureType::CommandBufferBeginInfo;
	const void *                        pNext            = nullptr;
	CommandBufferUsageFlags             flags            = {};
	const CommandBufferInheritanceInfo *pInheritanceInfo = nullptr;
};
struct CommandBufferInheritanceViewportScissorInfoNV {
	StructureType   sType              = StructureType::CommandBufferInheritanceViewportScissorInfoNV;
	const void *    pNext              = nullptr;
	Bool32          viewportScissor2D  = Constants::False;
	uint32_t        viewportDepthCount = 0;
	const Viewport *pViewportDepths    = nullptr;
};
struct ConditionalRenderingBeginInfo2EXT {
	StructureType                sType        = StructureType::ConditionalRenderingBeginInfo2EXT;
	const void *                 pNext        = nullptr;
	DeviceAddressRangeKHR        addressRange = {};
	AddressCommandFlagsKHR       addressFlags = {};
	ConditionalRenderingFlagsEXT flags        = {};
};
struct ConvertCooperativeVectorMatrixInfoNV {
	StructureType                   sType            = StructureType::ConvertCooperativeVectorMatrixInfoNV;
	const void *                    pNext            = nullptr;
	size_t                          srcSize          = 0;
	DeviceOrHostAddressConstKHR     srcData          = {};
	size_t *                        pDstSize         = nullptr;
	DeviceOrHostAddressKHR          dstData          = {};
	ComponentTypeKHR                srcComponentType = ComponentTypeKHR::Float16;
	ComponentTypeKHR                dstComponentType = ComponentTypeKHR::Float16;
	uint32_t                        numRows          = 0;
	uint32_t                        numColumns       = 0;
	CooperativeVectorMatrixLayoutNV srcLayout        = CooperativeVectorMatrixLayoutNV::RowMajor;
	size_t                          srcStride        = 0;
	CooperativeVectorMatrixLayoutNV dstLayout        = CooperativeVectorMatrixLayoutNV::RowMajor;
	size_t                          dstStride        = 0;
};
struct CopyAccelerationStructureToMemoryInfoKHR {
	StructureType                                           sType = StructureType::CopyAccelerationStructureToMemoryInfoKHR;
	const void *                                            pNext = nullptr;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> src;
	DeviceOrHostAddressKHR                                  dst   = {};
	CopyAccelerationStructureModeKHR                        mode  = CopyAccelerationStructureModeKHR::Clone;
};
struct CopyBufferInfo2 {
	StructureType                         sType       = StructureType::CopyBufferInfo2;
	const void *                          pNext       = nullptr;
	impl_Struct::AssignableHandle<Buffer> srcBuffer;
	impl_Struct::AssignableHandle<Buffer> dstBuffer;
	uint32_t                              regionCount = 0;
	const BufferCopy2 *                   pRegions    = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, BufferCopy2>;
};
struct CopyMemoryIndirectInfoKHR {
	StructureType                sType            = StructureType::CopyMemoryIndirectInfoKHR;
	const void *                 pNext            = nullptr;
	AddressCopyFlagsKHR          srcCopyFlags     = {};
	AddressCopyFlagsKHR          dstCopyFlags     = {};
	uint32_t                     copyCount        = 0;
	StridedDeviceAddressRangeKHR copyAddressRange = {};
};
struct CopyMemoryToAccelerationStructureInfoKHR {
	StructureType                                           sType = StructureType::CopyMemoryToAccelerationStructureInfoKHR;
	const void *                                            pNext = nullptr;
	DeviceOrHostAddressConstKHR                             src   = {};
	impl_Struct::AssignableHandle<AccelerationStructureKHR> dst;
	CopyAccelerationStructureModeKHR                        mode  = CopyAccelerationStructureModeKHR::Clone;
};
struct CopyMemoryToImageIndirectCommandKHR {
	DeviceAddress          srcAddress        = 0;
	uint32_t               bufferRowLength   = 0;
	uint32_t               bufferImageHeight = 0;
	ImageSubresourceLayers imageSubresource  = {};
	Offset3D               imageOffset       = {};
	Extent3D               imageExtent       = {};
};
struct CopyMemoryToImageIndirectInfoKHR {
	StructureType                        sType              = StructureType::CopyMemoryToImageIndirectInfoKHR;
	const void *                         pNext              = nullptr;
	AddressCopyFlagsKHR                  srcCopyFlags       = {};
	uint32_t                             copyCount          = 0;
	StridedDeviceAddressRangeKHR         copyAddressRange   = {};
	impl_Struct::AssignableHandle<Image> dstImage;
	ImageLayout                          dstImageLayout     = ImageLayout::Undefined;
	const ImageSubresourceLayers *       pImageSubresources = nullptr;// len copyCount
	auto imageSubresources() -> impl_Struct::VecView<uint32_t, ImageSubresourceLayers>;
};
struct CopyMemoryToMicromapInfoEXT {
	StructureType                              sType = StructureType::CopyMemoryToMicromapInfoEXT;
	const void *                               pNext = nullptr;
	DeviceOrHostAddressConstKHR                src   = {};
	impl_Struct::AssignableHandle<MicromapEXT> dst;
	CopyMicromapModeEXT                        mode  = CopyMicromapModeEXT::Clone;
};
struct CopyMicromapToMemoryInfoEXT {
	StructureType                              sType = StructureType::CopyMicromapToMemoryInfoEXT;
	const void *                               pNext = nullptr;
	impl_Struct::AssignableHandle<MicromapEXT> src;
	DeviceOrHostAddressKHR                     dst   = {};
	CopyMicromapModeEXT                        mode  = CopyMicromapModeEXT::Clone;
};
struct CopyTensorInfoARM {
	StructureType                            sType       = StructureType::CopyTensorInfoARM;
	const void *                             pNext       = nullptr;
	impl_Struct::AssignableHandle<TensorARM> srcTensor;
	impl_Struct::AssignableHandle<TensorARM> dstTensor;
	uint32_t                                 regionCount = 0;
	const TensorCopyARM *                    pRegions    = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, TensorCopyARM>;
};
struct DataGraphPipelineBuiltinModelCreateInfoQCOM {
	StructureType                                     sType      = StructureType::DataGraphPipelineBuiltinModelCreateInfoQCOM;
	const void *                                      pNext      = nullptr;
	const PhysicalDeviceDataGraphOperationSupportARM *pOperation = nullptr;
};
struct DataGraphPipelineCreateInfoARM {
	StructureType                                 sType             = StructureType::DataGraphPipelineCreateInfoARM;
	const void *                                  pNext             = nullptr;
	PipelineCreateFlags2                          flags             = {};
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	uint32_t                                      resourceInfoCount = 0;
	const DataGraphPipelineResourceInfoARM *      pResourceInfos    = nullptr;// len resourceInfoCount
	auto resourceInfos() -> impl_Struct::VecView<uint32_t, DataGraphPipelineResourceInfoARM>;
};
struct DataGraphPipelineSingleNodeCreateInfoARM {
	StructureType                                   sType           = StructureType::DataGraphPipelineSingleNodeCreateInfoARM;
	void *                                          pNext           = nullptr;
	DataGraphPipelineNodeTypeARM                    nodeType        = DataGraphPipelineNodeTypeARM::OpticalFlow;
	uint32_t                                        connectionCount = 0;
	const DataGraphPipelineSingleNodeConnectionARM *pConnections    = nullptr;// len connectionCount
	auto connections() -> impl_Struct::VecView<uint32_t, DataGraphPipelineSingleNodeConnectionARM>;
};
struct DataGraphProcessingEngineCreateInfoARM {
	StructureType                               sType                 = StructureType::DataGraphProcessingEngineCreateInfoARM;
	const void *                                pNext                 = nullptr;
	uint32_t                                    processingEngineCount = 0;
	PhysicalDeviceDataGraphProcessingEngineARM *pProcessingEngines    = nullptr;// len processingEngineCount
};
struct DebugUtilsMessengerCallbackDataEXT {
	StructureType                           sType            = StructureType::DebugUtilsMessengerCallbackDataEXT;
	const void *                            pNext            = nullptr;
	DebugUtilsMessengerCallbackDataFlagsEXT flags            = {};
	impl_Struct::InOutString                messageIdName;
	int32_t                                 messageIdNumber  = 0;
	impl_Struct::InOutString                message;
	uint32_t                                queueLabelCount  = 0;
	const DebugUtilsLabelEXT *              pQueueLabels     = nullptr;// len queueLabelCount
	uint32_t                                cmdBufLabelCount = 0;
	const DebugUtilsLabelEXT *              pCmdBufLabels    = nullptr;// len cmdBufLabelCount
	uint32_t                                objectCount      = 0;
	const DebugUtilsObjectNameInfoEXT *     pObjects         = nullptr;// len objectCount
	auto queueLabels() -> impl_Struct::VecView<uint32_t, DebugUtilsLabelEXT>;
	auto cmdBufLabels() -> impl_Struct::VecView<uint32_t, DebugUtilsLabelEXT>;
	auto objects() -> impl_Struct::VecView<uint32_t, DebugUtilsObjectNameInfoEXT>;
};
struct DecompressMemoryInfoEXT {
	StructureType                     sType               = StructureType::DecompressMemoryInfoEXT;
	const void *                      pNext               = nullptr;
	MemoryDecompressionMethodFlagsEXT decompressionMethod = {};
	uint32_t                          regionCount         = 0;
	const DecompressMemoryRegionEXT * pRegions            = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, DecompressMemoryRegionEXT>;
};
union DescriptorDataEXT {
	impl_Struct::AssignableHandle<Sampler> sampler;
	const DescriptorImageInfo *            pCombinedImageSampler;
	const DescriptorImageInfo *            pInputAttachmentImage;
	const DescriptorImageInfo *            pSampledImage;
	const DescriptorImageInfo *            pStorageImage;
	const DescriptorAddressInfoEXT *       pUniformTexelBuffer;
	const DescriptorAddressInfoEXT *       pStorageTexelBuffer;
	const DescriptorAddressInfoEXT *       pUniformBuffer;
	const DescriptorAddressInfoEXT *       pStorageBuffer;
	DeviceAddress                          accelerationStructure;
};
struct DescriptorMappingSourceConstantOffsetEXT {
	uint32_t                 heapOffset             = 0;
	uint32_t                 heapArrayStride        = 0;
	const SamplerCreateInfo *pEmbeddedSampler       = nullptr;
	uint32_t                 samplerHeapOffset      = 0;
	uint32_t                 samplerHeapArrayStride = 0;
};
struct DescriptorMappingSourceIndirectIndexArrayEXT {
	uint32_t                 heapOffset                   = 0;
	uint32_t                 pushOffset                   = 0;
	uint32_t                 addressOffset                = 0;
	uint32_t                 heapIndexStride              = 0;
	const SamplerCreateInfo *pEmbeddedSampler             = nullptr;
	Bool32                   useCombinedImageSamplerIndex = Constants::False;
	uint32_t                 samplerHeapOffset            = 0;
	uint32_t                 samplerPushOffset            = 0;
	uint32_t                 samplerAddressOffset         = 0;
	uint32_t                 samplerHeapIndexStride       = 0;
};
struct DescriptorMappingSourceIndirectIndexEXT {
	uint32_t                 heapOffset                   = 0;
	uint32_t                 pushOffset                   = 0;
	uint32_t                 addressOffset                = 0;
	uint32_t                 heapIndexStride              = 0;
	uint32_t                 heapArrayStride              = 0;
	const SamplerCreateInfo *pEmbeddedSampler             = nullptr;
	Bool32                   useCombinedImageSamplerIndex = Constants::False;
	uint32_t                 samplerHeapOffset            = 0;
	uint32_t                 samplerPushOffset            = 0;
	uint32_t                 samplerAddressOffset         = 0;
	uint32_t                 samplerHeapIndexStride       = 0;
	uint32_t                 samplerHeapArrayStride       = 0;
};
struct DescriptorMappingSourcePushIndexEXT {
	uint32_t                 heapOffset                   = 0;
	uint32_t                 pushOffset                   = 0;
	uint32_t                 heapIndexStride              = 0;
	uint32_t                 heapArrayStride              = 0;
	const SamplerCreateInfo *pEmbeddedSampler             = nullptr;
	Bool32                   useCombinedImageSamplerIndex = Constants::False;
	uint32_t                 samplerHeapOffset            = 0;
	uint32_t                 samplerPushOffset            = 0;
	uint32_t                 samplerHeapIndexStride       = 0;
	uint32_t                 samplerHeapArrayStride       = 0;
};
struct DescriptorMappingSourceShaderRecordIndexEXT {
	uint32_t                 heapOffset                   = 0;
	uint32_t                 shaderRecordOffset           = 0;
	uint32_t                 heapIndexStride              = 0;
	uint32_t                 heapArrayStride              = 0;
	const SamplerCreateInfo *pEmbeddedSampler             = nullptr;
	Bool32                   useCombinedImageSamplerIndex = Constants::False;
	uint32_t                 samplerHeapOffset            = 0;
	uint32_t                 samplerShaderRecordOffset    = 0;
	uint32_t                 samplerHeapIndexStride       = 0;
	uint32_t                 samplerHeapArrayStride       = 0;
};
struct DescriptorPoolCreateInfo {
	StructureType             sType         = StructureType::DescriptorPoolCreateInfo;
	const void *              pNext         = nullptr;
	DescriptorPoolCreateFlags flags         = {};
	uint32_t                  maxSets       = 0;
	uint32_t                  poolSizeCount = 0;
	const DescriptorPoolSize *pPoolSizes    = nullptr;// len poolSizeCount
	auto poolSizes() -> impl_Struct::VecView<uint32_t, DescriptorPoolSize>;
};
struct DescriptorSetLayoutCreateInfo {
	StructureType                     sType        = StructureType::DescriptorSetLayoutCreateInfo;
	const void *                      pNext        = nullptr;
	DescriptorSetLayoutCreateFlags    flags        = {};
	uint32_t                          bindingCount = 0;
	const DescriptorSetLayoutBinding *pBindings    = nullptr;// len bindingCount
	auto bindings() -> impl_Struct::VecView<uint32_t, DescriptorSetLayoutBinding>;
};
struct DescriptorUpdateTemplateCreateInfo {
	StructureType                                      sType                      = StructureType::DescriptorUpdateTemplateCreateInfo;
	const void *                                       pNext                      = nullptr;
	DescriptorUpdateTemplateCreateFlags                flags                      = {};
	uint32_t                                           descriptorUpdateEntryCount = 0;
	const DescriptorUpdateTemplateEntry *              pDescriptorUpdateEntries   = nullptr;// len descriptorUpdateEntryCount
	DescriptorUpdateTemplateType                       templateType               = DescriptorUpdateTemplateType::DescriptorSet;
	impl_Struct::AssignableHandle<DescriptorSetLayout> descriptorSetLayout;
	PipelineBindPoint                                  pipelineBindPoint          = PipelineBindPoint::Graphics;
	impl_Struct::AssignableHandle<PipelineLayout>      pipelineLayout;
	uint32_t                                           set                        = 0;
	auto descriptorUpdateEntries() -> impl_Struct::VecView<uint32_t, DescriptorUpdateTemplateEntry>;
};
struct DeviceBufferMemoryRequirements {
	StructureType           sType       = StructureType::DeviceBufferMemoryRequirements;
	const void *            pNext       = nullptr;
	const BufferCreateInfo *pCreateInfo = nullptr;
};
struct DeviceCreateInfo {
	StructureType                 sType                          = StructureType::DeviceCreateInfo;
	const void *                  pNext                          = nullptr;
	DeviceCreateFlags             flags                          = {};
	uint32_t                      queueCreateInfoCount           = 0;
	const DeviceQueueCreateInfo * pQueueCreateInfos              = nullptr;// len queueCreateInfoCount
	// deprecated: this member is not used by the implementation and must be 0
	uint32_t                      deprecated_enabledLayerCount   = 0;
	// deprecated: this member is not used by the implementation and must be 0
	const char * const*           deprecated_ppEnabledLayerNames = nullptr;// len enabledLayerCount,null-terminated
	uint32_t                      enabledExtensionCount          = 0;
	const char * const*           ppEnabledExtensionNames        = nullptr;// len enabledExtensionCount,null-terminated
	const PhysicalDeviceFeatures *pEnabledFeatures               = nullptr;
	auto queueCreateInfos() -> impl_Struct::VecView<uint32_t, DeviceQueueCreateInfo>;
};
struct DeviceFaultInfoEXT {
	StructureType                                           sType             = StructureType::DeviceFaultInfoEXT;
	void *                                                  pNext             = nullptr;
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description       = {};// len null-terminated
	DeviceFaultAddressInfoKHR *                             pAddressInfos     = nullptr;
	DeviceFaultVendorInfoKHR *                              pVendorInfos      = nullptr;
	void *                                                  pVendorBinaryData = nullptr;
};
struct DeviceFaultInfoKHR {
	StructureType                                           sType                  = StructureType::DeviceFaultInfoKHR;
	void *                                                  pNext                  = nullptr;
	DeviceFaultFlagsKHR                                     flags                  = {};
	uint64_t                                                groupId                = 0;
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description            = {};// len null-terminated
	DeviceFaultAddressInfoKHR                               faultAddressInfo       = {};
	DeviceFaultAddressInfoKHR                               instructionAddressInfo = {};
	DeviceFaultVendorInfoKHR                                vendorInfo             = {};
};
struct DeviceMemoryCopyKHR {
	StructureType          sType    = StructureType::DeviceMemoryCopyKHR;
	const void *           pNext    = nullptr;
	DeviceAddressRangeKHR  srcRange = {};
	AddressCommandFlagsKHR srcFlags = {};
	DeviceAddressRangeKHR  dstRange = {};
	AddressCommandFlagsKHR dstFlags = {};
};
struct DeviceMemoryImageCopyKHR {
	StructureType          sType              = StructureType::DeviceMemoryImageCopyKHR;
	const void *           pNext              = nullptr;
	DeviceAddressRangeKHR  addressRange       = {};
	AddressCommandFlagsKHR addressFlags       = {};
	uint32_t               addressRowLength   = 0;
	uint32_t               addressImageHeight = 0;
	ImageSubresourceLayers imageSubresource   = {};
	ImageLayout            imageLayout        = ImageLayout::Undefined;
	Offset3D               imageOffset        = {};
	Extent3D               imageExtent        = {};
};
struct DirectDriverLoadingListLUNARG {
	StructureType                        sType       = StructureType::DirectDriverLoadingListLUNARG;
	const void *                         pNext       = nullptr;
	DirectDriverLoadingModeLUNARG        mode        = DirectDriverLoadingModeLUNARG::Exclusive;
	uint32_t                             driverCount = 0;
	const DirectDriverLoadingInfoLUNARG *pDrivers    = nullptr;// len driverCount
	auto drivers() -> impl_Struct::VecView<uint32_t, DirectDriverLoadingInfoLUNARG>;
};
struct DispatchIndirect2InfoKHR {
	StructureType          sType        = StructureType::DispatchIndirect2InfoKHR;
	const void *           pNext        = nullptr;
	DeviceAddressRangeKHR  addressRange = {};
	AddressCommandFlagsKHR addressFlags = {};
};
struct DisplayModeParametersKHR {
	Extent2D visibleRegion = {};
	uint32_t refreshRate   = 0;
};
struct DisplayPlaneCapabilitiesKHR {
	DisplayPlaneAlphaFlagsKHR supportedAlpha = {};
	Offset2D                  minSrcPosition = {};
	Offset2D                  maxSrcPosition = {};
	Extent2D                  minSrcExtent   = {};
	Extent2D                  maxSrcExtent   = {};
	Offset2D                  minDstPosition = {};
	Offset2D                  maxDstPosition = {};
	Extent2D                  minDstExtent   = {};
	Extent2D                  maxDstExtent   = {};
};
struct DisplayPlaneProperties2KHR {
	StructureType             sType                  = StructureType::DisplayPlaneProperties2KHR;
	void *                    pNext                  = nullptr;
	DisplayPlanePropertiesKHR displayPlaneProperties = {};
};
struct DisplayPropertiesKHR {
	impl_Struct::AssignableHandle<DisplayKHR> display;
	impl_Struct::InOutString                  displayName;
	Extent2D                                  physicalDimensions   = {};
	Extent2D                                  physicalResolution   = {};
	SurfaceTransformFlagsKHR                  supportedTransforms  = {};
	Bool32                                    planeReorderPossible = Constants::False;
	Bool32                                    persistentContent    = Constants::False;
};
struct DisplaySurfaceCreateInfoKHR {
	StructureType                                 sType           = StructureType::DisplaySurfaceCreateInfoKHR;
	const void *                                  pNext           = nullptr;
	DisplaySurfaceCreateFlagsKHR                  flags           = {};
	impl_Struct::AssignableHandle<DisplayModeKHR> displayMode;
	uint32_t                                      planeIndex      = 0;
	uint32_t                                      planeStackIndex = 0;
	SurfaceTransformBitsKHR                       transform       = SurfaceTransformBitsKHR::Identity;
	float                                         globalAlpha     = 0.0F;
	DisplayPlaneAlphaBitsKHR                      alphaMode       = DisplayPlaneAlphaBitsKHR::Opaque;
	Extent2D                                      imageExtent     = {};
};
struct DrawIndirect2InfoKHR {
	StructureType                sType        = StructureType::DrawIndirect2InfoKHR;
	const void *                 pNext        = nullptr;
	StridedDeviceAddressRangeKHR addressRange = {};
	AddressCommandFlagsKHR       addressFlags = {};
	uint32_t                     drawCount    = 0;
};
struct DrawIndirectCount2InfoKHR {
	StructureType                sType             = StructureType::DrawIndirectCount2InfoKHR;
	const void *                 pNext             = nullptr;
	StridedDeviceAddressRangeKHR addressRange      = {};
	AddressCommandFlagsKHR       addressFlags      = {};
	DeviceAddressRangeKHR        countAddressRange = {};
	AddressCommandFlagsKHR       countAddressFlags = {};
	uint32_t                     maxDrawCount      = 0;
};
struct DrmFormatModifierPropertiesList2EXT {
	StructureType                    sType                        = StructureType::DrmFormatModifierPropertiesList2EXT;
	void *                           pNext                        = nullptr;
	uint32_t                         drmFormatModifierCount       = 0;
	DrmFormatModifierProperties2EXT *pDrmFormatModifierProperties = nullptr;// len drmFormatModifierCount
};
struct DrmFormatModifierPropertiesListEXT {
	StructureType                   sType                        = StructureType::DrmFormatModifierPropertiesListEXT;
	void *                          pNext                        = nullptr;
	uint32_t                        drmFormatModifierCount       = 0;
	DrmFormatModifierPropertiesEXT *pDrmFormatModifierProperties = nullptr;// len drmFormatModifierCount
};
struct ExternalBufferProperties {
	StructureType            sType                    = StructureType::ExternalBufferProperties;
	void *                   pNext                    = nullptr;
	ExternalMemoryProperties externalMemoryProperties = {};
};
struct ExternalImageFormatProperties {
	StructureType            sType                    = StructureType::ExternalImageFormatProperties;
	void *                   pNext                    = nullptr;
	ExternalMemoryProperties externalMemoryProperties = {};
};
struct ExternalTensorPropertiesARM {
	StructureType            sType                    = StructureType::ExternalTensorPropertiesARM;
	const void *             pNext                    = nullptr;
	ExternalMemoryProperties externalMemoryProperties = {};
};
struct FormatProperties2 {
	StructureType    sType            = StructureType::FormatProperties2;
	void *           pNext            = nullptr;
	FormatProperties formatProperties = {};
};
struct FragmentShadingRateAttachmentInfoKHR {
	StructureType               sType                          = StructureType::FragmentShadingRateAttachmentInfoKHR;
	const void *                pNext                          = nullptr;
	const AttachmentReference2 *pFragmentShadingRateAttachment = nullptr;
	Extent2D                    shadingRateAttachmentTexelSize = {};
};
struct FramebufferAttachmentsCreateInfo {
	StructureType                         sType                    = StructureType::FramebufferAttachmentsCreateInfo;
	const void *                          pNext                    = nullptr;
	uint32_t                              attachmentImageInfoCount = 0;
	const FramebufferAttachmentImageInfo *pAttachmentImageInfos    = nullptr;// len attachmentImageInfoCount
	auto attachmentImageInfos() -> impl_Struct::VecView<uint32_t, FramebufferAttachmentImageInfo>;
};
struct GeneratedCommandsInfoNV {
	StructureType                                           sType                  = StructureType::GeneratedCommandsInfoNV;
	const void *                                            pNext                  = nullptr;
	PipelineBindPoint                                       pipelineBindPoint      = PipelineBindPoint::Graphics;
	impl_Struct::AssignableHandle<Pipeline>                 pipeline;
	impl_Struct::AssignableHandle<IndirectCommandsLayoutNV> indirectCommandsLayout;
	uint32_t                                                streamCount            = 0;
	const IndirectCommandsStreamNV *                        pStreams               = nullptr;// len streamCount
	uint32_t                                                sequencesCount         = 0;
	impl_Struct::AssignableHandle<Buffer>                   preprocessBuffer;
	DeviceSize                                              preprocessOffset       = 0;
	DeviceSize                                              preprocessSize         = 0;
	impl_Struct::AssignableHandle<Buffer>                   sequencesCountBuffer;
	DeviceSize                                              sequencesCountOffset   = 0;
	impl_Struct::AssignableHandle<Buffer>                   sequencesIndexBuffer;
	DeviceSize                                              sequencesIndexOffset   = 0;
	auto streams() -> impl_Struct::VecView<uint32_t, IndirectCommandsStreamNV>;
};
struct GeometryDataNV {
	GeometryTrianglesNV triangles = {};
	GeometryAABBNV      aabbs     = {};
};
struct GetLatencyMarkerInfoNV {
	StructureType                sType       = StructureType::GetLatencyMarkerInfoNV;
	const void *                 pNext       = nullptr;
	uint32_t                     timingCount = 0;
	LatencyTimingsFrameReportNV *pTimings    = nullptr;// len timingCount
};
struct GpaSampleBeginInfoAMD {
	StructureType            sType                                  = StructureType::GpaSampleBeginInfoAMD;
	const void *             pNext                                  = nullptr;
	GpaSampleTypeAMD         sampleType                             = GpaSampleTypeAMD::Cumulative;
	Bool32                   sampleInternalOperations               = Constants::False;
	Bool32                   cacheFlushOnCounterCollection          = Constants::False;
	Bool32                   sqShaderMaskEnable                     = Constants::False;
	GpaSqShaderStageFlagsAMD sqShaderMask                           = {};
	uint32_t                 perfCounterCount                       = 0;
	const GpaPerfCounterAMD *pPerfCounters                          = nullptr;// len perfCounterCount
	uint32_t                 streamingPerfTraceSampleInterval       = 0;
	DeviceSize               perfCounterDeviceMemoryLimit           = 0;
	Bool32                   sqThreadTraceEnable                    = Constants::False;
	Bool32                   sqThreadTraceSuppressInstructionTokens = Constants::False;
	DeviceSize               sqThreadTraceDeviceMemoryLimit         = 0;
	PipelineStageFlags       timingPreSample                        = {};
	PipelineStageFlags       timingPostSample                       = {};
	auto perfCounters() -> impl_Struct::VecView<uint32_t, GpaPerfCounterAMD>;
};
struct HdrMetadataEXT {
	StructureType sType                     = StructureType::HdrMetadataEXT;
	const void *  pNext                     = nullptr;
	XYColorEXT    displayPrimaryRed         = {};
	XYColorEXT    displayPrimaryGreen       = {};
	XYColorEXT    displayPrimaryBlue        = {};
	XYColorEXT    whitePoint                = {};
	float         maxLuminance              = 0.0F;
	float         minLuminance              = 0.0F;
	float         maxContentLightLevel      = 0.0F;
	float         maxFrameAverageLightLevel = 0.0F;
};
struct HostImageLayoutTransitionInfo {
	StructureType                        sType            = StructureType::HostImageLayoutTransitionInfo;
	const void *                         pNext            = nullptr;
	impl_Struct::AssignableHandle<Image> image;
	ImageLayout                          oldLayout        = ImageLayout::Undefined;
	ImageLayout                          newLayout        = ImageLayout::Undefined;
	ImageSubresourceRange                subresourceRange = {};
};
struct ImageBlit {
	ImageSubresourceLayers  srcSubresource = {};
	std::array<Offset3D, 2> srcOffsets     = {};
	ImageSubresourceLayers  dstSubresource = {};
	std::array<Offset3D, 2> dstOffsets     = {};
};
struct ImageBlit2 {
	StructureType           sType          = StructureType::ImageBlit2;
	const void *            pNext          = nullptr;
	ImageSubresourceLayers  srcSubresource = {};
	std::array<Offset3D, 2> srcOffsets     = {};
	ImageSubresourceLayers  dstSubresource = {};
	std::array<Offset3D, 2> dstOffsets     = {};
};
struct ImageCopy {
	ImageSubresourceLayers srcSubresource = {};
	Offset3D               srcOffset      = {};
	ImageSubresourceLayers dstSubresource = {};
	Offset3D               dstOffset      = {};
	Extent3D               extent         = {};
};
struct ImageCopy2 {
	StructureType          sType          = StructureType::ImageCopy2;
	const void *           pNext          = nullptr;
	ImageSubresourceLayers srcSubresource = {};
	Offset3D               srcOffset      = {};
	ImageSubresourceLayers dstSubresource = {};
	Offset3D               dstOffset      = {};
	Extent3D               extent         = {};
};
struct ImageCreateInfo {
	StructureType    sType                 = StructureType::ImageCreateInfo;
	const void *     pNext                 = nullptr;
	ImageCreateFlags flags                 = {};
	ImageType        imageType             = ImageType::v1D;
	Format           format                = Format::Undefined;
	Extent3D         extent                = {};
	uint32_t         mipLevels             = 0;
	uint32_t         arrayLayers           = 0;
	SampleCountBits  samples               = SampleCountBits::v1;
	ImageTiling      tiling                = ImageTiling::Optimal;
	ImageUsageFlags  usage                 = {};
	SharingMode      sharingMode           = SharingMode::Exclusive;
	uint32_t         queueFamilyIndexCount = 0;
	const uint32_t * pQueueFamilyIndices   = nullptr;// len queueFamilyIndexCount
	ImageLayout      initialLayout         = ImageLayout::Undefined;
	auto queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct ImageDrmFormatModifierExplicitCreateInfoEXT {
	StructureType            sType                       = StructureType::ImageDrmFormatModifierExplicitCreateInfoEXT;
	const void *             pNext                       = nullptr;
	uint64_t                 drmFormatModifier           = 0;
	uint32_t                 drmFormatModifierPlaneCount = 0;
	const SubresourceLayout *pPlaneLayouts               = nullptr;// len drmFormatModifierPlaneCount
	auto planeLayouts() -> impl_Struct::VecView<uint32_t, SubresourceLayout>;
};
struct ImageFormatProperties {
	Extent3D         maxExtent       = {};
	uint32_t         maxMipLevels    = 0;
	uint32_t         maxArrayLayers  = 0;
	SampleCountFlags sampleCounts    = {};
	DeviceSize       maxResourceSize = 0;
};
struct ImageMemoryBarrier {
	StructureType                        sType               = StructureType::ImageMemoryBarrier;
	const void *                         pNext               = nullptr;
	AccessFlags                          srcAccessMask       = {};
	AccessFlags                          dstAccessMask       = {};
	ImageLayout                          oldLayout           = ImageLayout::Undefined;
	ImageLayout                          newLayout           = ImageLayout::Undefined;
	uint32_t                             srcQueueFamilyIndex = 0;
	uint32_t                             dstQueueFamilyIndex = 0;
	impl_Struct::AssignableHandle<Image> image;
	ImageSubresourceRange                subresourceRange    = {};
};
struct ImageMemoryBarrier2 {
	StructureType                        sType               = StructureType::ImageMemoryBarrier2;
	const void *                         pNext               = nullptr;
	PipelineStageFlags2                  srcStageMask        = {};
	AccessFlags2                         srcAccessMask       = {};
	PipelineStageFlags2                  dstStageMask        = {};
	AccessFlags2                         dstAccessMask       = {};
	ImageLayout                          oldLayout           = ImageLayout::Undefined;
	ImageLayout                          newLayout           = ImageLayout::Undefined;
	uint32_t                             srcQueueFamilyIndex = 0;
	uint32_t                             dstQueueFamilyIndex = 0;
	impl_Struct::AssignableHandle<Image> image;
	ImageSubresourceRange                subresourceRange    = {};
};
struct ImageResolve {
	ImageSubresourceLayers srcSubresource = {};
	Offset3D               srcOffset      = {};
	ImageSubresourceLayers dstSubresource = {};
	Offset3D               dstOffset      = {};
	Extent3D               extent         = {};
};
struct ImageResolve2 {
	StructureType          sType          = StructureType::ImageResolve2;
	const void *           pNext          = nullptr;
	ImageSubresourceLayers srcSubresource = {};
	Offset3D               srcOffset      = {};
	ImageSubresourceLayers dstSubresource = {};
	Offset3D               dstOffset      = {};
	Extent3D               extent         = {};
};
struct ImageSubresource2 {
	StructureType    sType            = StructureType::ImageSubresource2;
	void *           pNext            = nullptr;
	ImageSubresource imageSubresource = {};
};
struct ImageToMemoryCopy {
	StructureType          sType             = StructureType::ImageToMemoryCopy;
	const void *           pNext             = nullptr;
	void *                 pHostPointer      = nullptr;
	uint32_t               memoryRowLength   = 0;
	uint32_t               memoryImageHeight = 0;
	ImageSubresourceLayers imageSubresource  = {};
	Offset3D               imageOffset       = {};
	Extent3D               imageExtent       = {};
};
struct ImageViewCreateInfo {
	StructureType                        sType            = StructureType::ImageViewCreateInfo;
	const void *                         pNext            = nullptr;
	ImageViewCreateFlags                 flags            = {};
	impl_Struct::AssignableHandle<Image> image;
	ImageViewType                        viewType         = ImageViewType::v1D;
	Format                               format           = Format::Undefined;
	ComponentMapping                     components       = {};
	ImageSubresourceRange                subresourceRange = {};
};
struct ImageViewSampleWeightCreateInfoQCOM {
	StructureType sType        = StructureType::ImageViewSampleWeightCreateInfoQCOM;
	const void *  pNext        = nullptr;
	Offset2D      filterCenter = {};
	Extent2D      filterSize   = {};
	uint32_t      numPhases    = 0;
};
struct IndirectCommandsLayoutCreateInfoNV {
	StructureType                        sType             = StructureType::IndirectCommandsLayoutCreateInfoNV;
	const void *                         pNext             = nullptr;
	IndirectCommandsLayoutUsageFlagsNV   flags             = {};
	PipelineBindPoint                    pipelineBindPoint = PipelineBindPoint::Graphics;
	uint32_t                             tokenCount        = 0;
	const IndirectCommandsLayoutTokenNV *pTokens           = nullptr;// len tokenCount
	uint32_t                             streamCount       = 0;
	const uint32_t *                     pStreamStrides    = nullptr;// len streamCount
	auto tokens() -> impl_Struct::VecView<uint32_t, IndirectCommandsLayoutTokenNV>;
	auto streamStrides() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct IndirectCommandsPushConstantTokenEXT {
	PushConstantRange updateRange = {};
};
struct IndirectExecutionSetShaderInfoEXT {
	StructureType                                   sType                  = StructureType::IndirectExecutionSetShaderInfoEXT;
	const void *                                    pNext                  = nullptr;
	uint32_t                                        shaderCount            = 0;
	const impl_Struct::AssignableHandle<ShaderEXT> *pInitialShaders        = nullptr;// len shaderCount
	const IndirectExecutionSetShaderLayoutInfoEXT * pSetLayoutInfos        = nullptr;// len shaderCount
	uint32_t                                        maxShaderCount         = 0;
	uint32_t                                        pushConstantRangeCount = 0;
	const PushConstantRange *                       pPushConstantRanges    = nullptr;// len pushConstantRangeCount
	auto initialShaders() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<ShaderEXT>>;
	auto pushConstantRanges() -> impl_Struct::VecView<uint32_t, PushConstantRange>;
};
struct InstanceCreateInfo {
	StructureType          sType                   = StructureType::InstanceCreateInfo;
	const void *           pNext                   = nullptr;
	InstanceCreateFlags    flags                   = {};
	const ApplicationInfo *pApplicationInfo        = nullptr;
	uint32_t               enabledLayerCount       = 0;
	const char * const*    ppEnabledLayerNames     = nullptr;// len enabledLayerCount,null-terminated
	uint32_t               enabledExtensionCount   = 0;
	const char * const*    ppEnabledExtensionNames = nullptr;// len enabledExtensionCount,null-terminated
};
struct LayerSettingsCreateInfoEXT {
	StructureType          sType        = StructureType::LayerSettingsCreateInfoEXT;
	const void *           pNext        = nullptr;
	uint32_t               settingCount = 0;
	const LayerSettingEXT *pSettings    = nullptr;// len settingCount
	auto settings() -> impl_Struct::VecView<uint32_t, LayerSettingEXT>;
};
struct MemoryMarkerInfoAMD {
	StructureType          sType    = StructureType::MemoryMarkerInfoAMD;
	const void *           pNext    = nullptr;
	PipelineStageFlags2    stage    = {};
	DeviceAddressRangeKHR  dstRange = {};
	AddressCommandFlagsKHR dstFlags = {};
	uint32_t               marker   = 0;
};
struct MemoryRangeBarrierKHR {
	StructureType          sType               = StructureType::MemoryRangeBarrierKHR;
	const void *           pNext               = nullptr;
	PipelineStageFlags2    srcStageMask        = {};
	AccessFlags2           srcAccessMask       = {};
	PipelineStageFlags2    dstStageMask        = {};
	AccessFlags2           dstAccessMask       = {};
	uint32_t               srcQueueFamilyIndex = 0;
	uint32_t               dstQueueFamilyIndex = 0;
	DeviceAddressRangeKHR  addressRange        = {};
	AddressCommandFlagsKHR addressFlags        = {};
};
struct MemoryRequirements2 {
	StructureType      sType              = StructureType::MemoryRequirements2;
	void *             pNext              = nullptr;
	MemoryRequirements memoryRequirements = {};
};
struct MemoryToImageCopy {
	StructureType          sType             = StructureType::MemoryToImageCopy;
	const void *           pNext             = nullptr;
	const void *           pHostPointer      = nullptr;
	uint32_t               memoryRowLength   = 0;
	uint32_t               memoryImageHeight = 0;
	ImageSubresourceLayers imageSubresource  = {};
	Offset3D               imageOffset       = {};
	Extent3D               imageExtent       = {};
};
struct MicromapBuildInfoEXT {
	StructureType                              sType               = StructureType::MicromapBuildInfoEXT;
	const void *                               pNext               = nullptr;
	MicromapTypeEXT                            type                = MicromapTypeEXT::OpacityMicromap;
	BuildMicromapFlagsEXT                      flags               = {};
	BuildMicromapModeEXT                       mode                = BuildMicromapModeEXT::Build;
	impl_Struct::AssignableHandle<MicromapEXT> dstMicromap;
	uint32_t                                   usageCountsCount    = 0;
	const MicromapUsageEXT *                   pUsageCounts        = nullptr;// len usageCountsCount
	const MicromapUsageEXT * const*            ppUsageCounts       = nullptr;// len usageCountsCount,1
	DeviceOrHostAddressConstKHR                data                = {};
	DeviceOrHostAddressKHR                     scratchData         = {};
	DeviceOrHostAddressConstKHR                triangleArray       = {};
	DeviceSize                                 triangleArrayStride = 0;
	auto usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageEXT>;
};
struct MultisamplePropertiesEXT {
	StructureType sType                     = StructureType::MultisamplePropertiesEXT;
	void *        pNext                     = nullptr;
	Extent2D      maxSampleLocationGridSize = {};
};
struct MutableDescriptorTypeCreateInfoEXT {
	StructureType                       sType                          = StructureType::MutableDescriptorTypeCreateInfoEXT;
	const void *                        pNext                          = nullptr;
	uint32_t                            mutableDescriptorTypeListCount = 0;
	const MutableDescriptorTypeListEXT *pMutableDescriptorTypeLists    = nullptr;// len mutableDescriptorTypeListCount
	auto mutableDescriptorTypeLists() -> impl_Struct::VecView<uint32_t, MutableDescriptorTypeListEXT>;
};
struct OpaqueCaptureDataCreateInfoEXT {
	StructureType                   sType = StructureType::OpaqueCaptureDataCreateInfoEXT;
	const void *                    pNext = nullptr;
	const HostAddressRangeConstEXT *pData = nullptr;
};
struct PartitionedAccelerationStructureWriteInstanceDataNV {
	TransformMatrixKHR                              transform                           = {};
	std::array<float, 6>                            explicitAABB                        = {};
	uint32_t                                        instanceID                          = 0;
	uint32_t                                        instanceMask                        = 0;
	uint32_t                                        instanceContributionToHitGroupIndex = 0;
	PartitionedAccelerationStructureInstanceFlagsNV instanceFlags                       = {};
	uint32_t                                        instanceIndex                       = 0;
	uint32_t                                        partitionIndex                      = 0;
	DeviceAddress                                   accelerationStructure               = 0;
};
struct PastPresentationTimingEXT {
	StructureType        sType             = StructureType::PastPresentationTimingEXT;
	void *               pNext             = nullptr;
	uint64_t             presentId         = 0;
	uint64_t             targetTime        = 0;
	uint32_t             presentStageCount = 0;
	PresentStageTimeEXT *pPresentStages    = nullptr;// len presentStageCount
	TimeDomainKHR        timeDomain        = TimeDomainKHR::Device;
	uint64_t             timeDomainId      = 0;
	Bool32               reportComplete    = Constants::False;
};
struct PerformanceValueINTEL {
	PerformanceValueTypeINTEL type = PerformanceValueTypeINTEL::Uint32;
	PerformanceValueDataINTEL data = {};
};
struct PhysicalDeviceDriverProperties {
	StructureType                                          sType              = StructureType::PhysicalDeviceDriverProperties;
	void *                                                 pNext              = nullptr;
	DriverId                                               driverID           = DriverId::AMDProprietary;
	impl_Struct::FixedString<Constants::MaxDriverNameSize> driverName         = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDriverInfoSize> driverInfo         = {};// len null-terminated
	ConformanceVersion                                     conformanceVersion = {};
};
struct PhysicalDeviceExternalTensorInfoARM {
	StructureType                sType        = StructureType::PhysicalDeviceExternalTensorInfoARM;
	const void *                 pNext        = nullptr;
	TensorCreateFlagsARM         flags        = {};
	const TensorDescriptionARM * pDescription = nullptr;
	ExternalMemoryHandleTypeBits handleType   = ExternalMemoryHandleTypeBits::OpaqueFd;
};
struct PhysicalDeviceFeatures2 {
	StructureType          sType    = StructureType::PhysicalDeviceFeatures2;
	void *                 pNext    = nullptr;
	PhysicalDeviceFeatures features = {};
};
struct PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT {
	StructureType sType                            = StructureType::PhysicalDeviceFragmentDensityMapOffsetPropertiesEXT;
	void *        pNext                            = nullptr;
	Extent2D      fragmentDensityOffsetGranularity = {};
};
struct PhysicalDeviceFragmentDensityMapPropertiesEXT {
	StructureType sType                       = StructureType::PhysicalDeviceFragmentDensityMapPropertiesEXT;
	void *        pNext                       = nullptr;
	Extent2D      minFragmentDensityTexelSize = {};
	Extent2D      maxFragmentDensityTexelSize = {};
	Bool32        fragmentDensityInvocations  = Constants::False;
};
struct PhysicalDeviceFragmentShadingRateKHR {
	StructureType    sType        = StructureType::PhysicalDeviceFragmentShadingRateKHR;
	void *           pNext        = nullptr;
	SampleCountFlags sampleCounts = {};
	Extent2D         fragmentSize = {};
};
struct PhysicalDeviceFragmentShadingRatePropertiesKHR {
	StructureType   sType                                                = StructureType::PhysicalDeviceFragmentShadingRatePropertiesKHR;
	void *          pNext                                                = nullptr;
	Extent2D        minFragmentShadingRateAttachmentTexelSize            = {};
	Extent2D        maxFragmentShadingRateAttachmentTexelSize            = {};
	uint32_t        maxFragmentShadingRateAttachmentTexelSizeAspectRatio = 0;
	Bool32          primitiveFragmentShadingRateWithMultipleViewports    = Constants::False;
	Bool32          layeredShadingRateAttachments                        = Constants::False;
	Bool32          fragmentShadingRateNonTrivialCombinerOps             = Constants::False;
	Extent2D        maxFragmentSize                                      = {};
	uint32_t        maxFragmentSizeAspectRatio                           = 0;
	uint32_t        maxFragmentShadingRateCoverageSamples                = 0;
	SampleCountBits maxFragmentShadingRateRasterizationSamples           = SampleCountBits::v1;
	Bool32          fragmentShadingRateWithShaderDepthStencilWrites      = Constants::False;
	Bool32          fragmentShadingRateWithSampleMask                    = Constants::False;
	Bool32          fragmentShadingRateWithShaderSampleMask              = Constants::False;
	Bool32          fragmentShadingRateWithConservativeRasterization     = Constants::False;
	Bool32          fragmentShadingRateWithFragmentShaderInterlock       = Constants::False;
	Bool32          fragmentShadingRateWithCustomSampleLocations         = Constants::False;
	Bool32          fragmentShadingRateStrictMultiplyCombiner            = Constants::False;
};
struct PhysicalDeviceGpaPropertiesAMD {
	StructureType                       sType               = StructureType::PhysicalDeviceGpaPropertiesAMD;
	void *                              pNext               = nullptr;
	PhysicalDeviceGpaPropertiesFlagsAMD flags               = {};
	DeviceSize                          maxSqttSeBufferSize = 0;
	uint32_t                            shaderEngineCount   = 0;
	uint32_t                            perfBlockCount      = 0;
	GpaPerfBlockPropertiesAMD *         pPerfBlocks         = nullptr;// len perfBlockCount
};
struct PhysicalDeviceImageProcessing2PropertiesQCOM {
	StructureType sType               = StructureType::PhysicalDeviceImageProcessing2PropertiesQCOM;
	void *        pNext               = nullptr;
	Extent2D      maxBlockMatchWindow = {};
};
struct PhysicalDeviceImageProcessingPropertiesQCOM {
	StructureType sType                    = StructureType::PhysicalDeviceImageProcessingPropertiesQCOM;
	void *        pNext                    = nullptr;
	uint32_t      maxWeightFilterPhases    = 0;
	Extent2D      maxWeightFilterDimension = {};
	Extent2D      maxBlockMatchRegion      = {};
	Extent2D      maxBoxFilterBlockSize    = {};
};
struct PhysicalDeviceLayeredApiPropertiesListKHR {
	StructureType                          sType           = StructureType::PhysicalDeviceLayeredApiPropertiesListKHR;
	void *                                 pNext           = nullptr;
	uint32_t                               layeredApiCount = 0;
	PhysicalDeviceLayeredApiPropertiesKHR *pLayeredApis    = nullptr;// len layeredApiCount
};
struct PhysicalDeviceMemoryProperties {
	uint32_t                                          memoryTypeCount = 0;
	std::array<MemoryType, Constants::MaxMemoryTypes> memoryTypes     = {};// len memoryTypeCount
	uint32_t                                          memoryHeapCount = 0;
	std::array<MemoryHeap, Constants::MaxMemoryHeaps> memoryHeaps     = {};// len memoryHeapCount
};
struct PhysicalDevicePerformanceCountersByRegionPropertiesARM {
	StructureType sType                           = StructureType::PhysicalDevicePerformanceCountersByRegionPropertiesARM;
	void *        pNext                           = nullptr;
	uint32_t      maxPerRegionPerformanceCounters = 0;
	Extent2D      performanceCounterRegionSize    = {};
	uint32_t      rowStrideAlignment              = 0;
	uint32_t      regionAlignment                 = 0;
	Bool32        identityTransformOrder          = Constants::False;
};
struct PhysicalDeviceProperties {
	uint32_t                                                       apiVersion        = 0;
	uint32_t                                                       driverVersion     = 0;
	uint32_t                                                       vendorID          = 0;
	uint32_t                                                       deviceID          = 0;
	PhysicalDeviceType                                             deviceType        = PhysicalDeviceType::Other;
	impl_Struct::FixedString<Constants::MaxPhysicalDeviceNameSize> deviceName        = {};// len null-terminated
	std::array<uint8_t, Constants::UuidSize>                       pipelineCacheUUID = {};
	PhysicalDeviceLimits                                           limits            = {};
	PhysicalDeviceSparseProperties                                 sparseProperties  = {};
};
struct PhysicalDeviceRenderPassStripedPropertiesARM {
	StructureType sType                       = StructureType::PhysicalDeviceRenderPassStripedPropertiesARM;
	void *        pNext                       = nullptr;
	Extent2D      renderPassStripeGranularity = {};
	uint32_t      maxRenderPassStripes        = 0;
};
struct PhysicalDeviceSampleLocationsPropertiesEXT {
	StructureType        sType                         = StructureType::PhysicalDeviceSampleLocationsPropertiesEXT;
	void *               pNext                         = nullptr;
	SampleCountFlags     sampleLocationSampleCounts    = {};
	Extent2D             maxSampleLocationGridSize     = {};
	std::array<float, 2> sampleLocationCoordinateRange = {};
	uint32_t             sampleLocationSubPixelBits    = 0;
	Bool32               variableSampleLocations       = Constants::False;
};
struct PhysicalDeviceShadingRateImagePropertiesNV {
	StructureType sType                       = StructureType::PhysicalDeviceShadingRateImagePropertiesNV;
	void *        pNext                       = nullptr;
	Extent2D      shadingRateTexelSize        = {};
	uint32_t      shadingRatePaletteSize      = 0;
	uint32_t      shadingRateMaxCoarseSamples = 0;
};
struct PhysicalDeviceTileShadingPropertiesQCOM {
	StructureType sType              = StructureType::PhysicalDeviceTileShadingPropertiesQCOM;
	void *        pNext              = nullptr;
	uint32_t      maxApronSize       = 0;
	Bool32        preferNonCoherent  = Constants::False;
	Extent2D      tileGranularity    = {};
	Extent2D      maxTileShadingRate = {};
};
struct PhysicalDeviceVideoEncodeQualityLevelInfoKHR {
	StructureType              sType         = StructureType::PhysicalDeviceVideoEncodeQualityLevelInfoKHR;
	const void *               pNext         = nullptr;
	const VideoProfileInfoKHR *pVideoProfile = nullptr;
	uint32_t                   qualityLevel  = 0;
};
struct PhysicalDeviceVulkan12Properties {
	StructureType                                          sType                                                = StructureType::PhysicalDeviceVulkan12Properties;
	void *                                                 pNext                                                = nullptr;
	DriverId                                               driverID                                             = DriverId::AMDProprietary;
	impl_Struct::FixedString<Constants::MaxDriverNameSize> driverName                                           = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDriverInfoSize> driverInfo                                           = {};// len null-terminated
	ConformanceVersion                                     conformanceVersion                                   = {};
	ShaderFloatControlsIndependence                        denormBehaviorIndependence                           = ShaderFloatControlsIndependence::v32BitOnly;
	ShaderFloatControlsIndependence                        roundingModeIndependence                             = ShaderFloatControlsIndependence::v32BitOnly;
	Bool32                                                 shaderSignedZeroInfNanPreserveFloat16                = Constants::False;
	Bool32                                                 shaderSignedZeroInfNanPreserveFloat32                = Constants::False;
	Bool32                                                 shaderSignedZeroInfNanPreserveFloat64                = Constants::False;
	Bool32                                                 shaderDenormPreserveFloat16                          = Constants::False;
	Bool32                                                 shaderDenormPreserveFloat32                          = Constants::False;
	Bool32                                                 shaderDenormPreserveFloat64                          = Constants::False;
	Bool32                                                 shaderDenormFlushToZeroFloat16                       = Constants::False;
	Bool32                                                 shaderDenormFlushToZeroFloat32                       = Constants::False;
	Bool32                                                 shaderDenormFlushToZeroFloat64                       = Constants::False;
	Bool32                                                 shaderRoundingModeRTEFloat16                         = Constants::False;
	Bool32                                                 shaderRoundingModeRTEFloat32                         = Constants::False;
	Bool32                                                 shaderRoundingModeRTEFloat64                         = Constants::False;
	Bool32                                                 shaderRoundingModeRTZFloat16                         = Constants::False;
	Bool32                                                 shaderRoundingModeRTZFloat32                         = Constants::False;
	Bool32                                                 shaderRoundingModeRTZFloat64                         = Constants::False;
	uint32_t                                               maxUpdateAfterBindDescriptorsInAllPools              = 0;
	Bool32                                                 shaderUniformBufferArrayNonUniformIndexingNative     = Constants::False;
	Bool32                                                 shaderSampledImageArrayNonUniformIndexingNative      = Constants::False;
	Bool32                                                 shaderStorageBufferArrayNonUniformIndexingNative     = Constants::False;
	Bool32                                                 shaderStorageImageArrayNonUniformIndexingNative      = Constants::False;
	Bool32                                                 shaderInputAttachmentArrayNonUniformIndexingNative   = Constants::False;
	Bool32                                                 robustBufferAccessUpdateAfterBind                    = Constants::False;
	Bool32                                                 quadDivergentImplicitLod                             = Constants::False;
	uint32_t                                               maxPerStageDescriptorUpdateAfterBindSamplers         = 0;
	uint32_t                                               maxPerStageDescriptorUpdateAfterBindUniformBuffers   = 0;
	uint32_t                                               maxPerStageDescriptorUpdateAfterBindStorageBuffers   = 0;
	uint32_t                                               maxPerStageDescriptorUpdateAfterBindSampledImages    = 0;
	uint32_t                                               maxPerStageDescriptorUpdateAfterBindStorageImages    = 0;
	uint32_t                                               maxPerStageDescriptorUpdateAfterBindInputAttachments = 0;
	uint32_t                                               maxPerStageUpdateAfterBindResources                  = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindSamplers              = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindUniformBuffers        = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindUniformBuffersDynamic = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindStorageBuffers        = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindStorageBuffersDynamic = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindSampledImages         = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindStorageImages         = 0;
	uint32_t                                               maxDescriptorSetUpdateAfterBindInputAttachments      = 0;
	ResolveModeFlags                                       supportedDepthResolveModes                           = {};
	ResolveModeFlags                                       supportedStencilResolveModes                         = {};
	Bool32                                                 independentResolveNone                               = Constants::False;
	Bool32                                                 independentResolve                                   = Constants::False;
	Bool32                                                 filterMinmaxSingleComponentFormats                   = Constants::False;
	Bool32                                                 filterMinmaxImageComponentMapping                    = Constants::False;
	uint64_t                                               maxTimelineSemaphoreValueDifference                  = 0;
	SampleCountFlags                                       framebufferIntegerColorSampleCounts                  = {};
};
struct PipelineBinaryKeysAndDataKHR {
	uint32_t                     binaryCount         = 0;
	const PipelineBinaryKeyKHR * pPipelineBinaryKeys = nullptr;// len binaryCount
	const PipelineBinaryDataKHR *pPipelineBinaryData = nullptr;// len binaryCount
	auto pipelineBinaryKeys() -> impl_Struct::VecView<uint32_t, PipelineBinaryKeyKHR>;
};
struct PipelineColorBlendStateCreateInfo {
	StructureType                            sType           = StructureType::PipelineColorBlendStateCreateInfo;
	const void *                             pNext           = nullptr;
	PipelineColorBlendStateCreateFlags       flags           = {};
	Bool32                                   logicOpEnable   = Constants::False;
	LogicOp                                  logicOp         = LogicOp::Clear;
	uint32_t                                 attachmentCount = 0;
	const PipelineColorBlendAttachmentState *pAttachments    = nullptr;// len attachmentCount
	std::array<float, 4>                     blendConstants  = {};
	auto attachments() -> impl_Struct::VecView<uint32_t, PipelineColorBlendAttachmentState>;
};
struct PipelineCreationFeedbackCreateInfo {
	StructureType             sType                              = StructureType::PipelineCreationFeedbackCreateInfo;
	const void *              pNext                              = nullptr;
	PipelineCreationFeedback *pPipelineCreationFeedback          = nullptr;
	uint32_t                  pipelineStageCreationFeedbackCount = 0;
	PipelineCreationFeedback *pPipelineStageCreationFeedbacks    = nullptr;// len pipelineStageCreationFeedbackCount
};
struct PipelineDepthStencilStateCreateInfo {
	StructureType                        sType                 = StructureType::PipelineDepthStencilStateCreateInfo;
	const void *                         pNext                 = nullptr;
	PipelineDepthStencilStateCreateFlags flags                 = {};
	Bool32                               depthTestEnable       = Constants::False;
	Bool32                               depthWriteEnable      = Constants::False;
	CompareOp                            depthCompareOp        = CompareOp::Never;
	Bool32                               depthBoundsTestEnable = Constants::False;
	Bool32                               stencilTestEnable     = Constants::False;
	StencilOpState                       front                 = {};
	StencilOpState                       back                  = {};
	float                                minDepthBounds        = 0.0F;
	float                                maxDepthBounds        = 0.0F;
};
struct PipelineExecutableStatisticKHR {
	StructureType                                           sType       = StructureType::PipelineExecutableStatisticKHR;
	void *                                                  pNext       = nullptr;
	impl_Struct::FixedString<Constants::MaxDescriptionSize> name        = {};// len null-terminated
	impl_Struct::FixedString<Constants::MaxDescriptionSize> description = {};// len null-terminated
	PipelineExecutableStatisticFormatKHR                    format      = PipelineExecutableStatisticFormatKHR::Bool32;
	PipelineExecutableStatisticValueKHR                     value       = {};
};
struct PipelineFragmentShadingRateStateCreateInfoKHR {
	StructureType                                   sType        = StructureType::PipelineFragmentShadingRateStateCreateInfoKHR;
	const void *                                    pNext        = nullptr;
	Extent2D                                        fragmentSize = {};
	std::array<FragmentShadingRateCombinerOpKHR, 2> combinerOps  = {};
};
struct PipelineLayoutCreateInfo {
	StructureType                                             sType                  = StructureType::PipelineLayoutCreateInfo;
	const void *                                              pNext                  = nullptr;
	PipelineLayoutCreateFlags                                 flags                  = {};
	uint32_t                                                  setLayoutCount         = 0;
	const impl_Struct::AssignableHandle<DescriptorSetLayout> *pSetLayouts            = nullptr;// len setLayoutCount
	uint32_t                                                  pushConstantRangeCount = 0;
	const PushConstantRange *                                 pPushConstantRanges    = nullptr;// len pushConstantRangeCount
	auto setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>>;
	auto pushConstantRanges() -> impl_Struct::VecView<uint32_t, PushConstantRange>;
};
struct PipelineVertexInputDivisorStateCreateInfo {
	StructureType                               sType                     = StructureType::PipelineVertexInputDivisorStateCreateInfo;
	const void *                                pNext                     = nullptr;
	uint32_t                                    vertexBindingDivisorCount = 0;
	const VertexInputBindingDivisorDescription *pVertexBindingDivisors    = nullptr;// len vertexBindingDivisorCount
	auto vertexBindingDivisors() -> impl_Struct::VecView<uint32_t, VertexInputBindingDivisorDescription>;
};
struct PipelineVertexInputStateCreateInfo {
	StructureType                          sType                           = StructureType::PipelineVertexInputStateCreateInfo;
	const void *                           pNext                           = nullptr;
	PipelineVertexInputStateCreateFlags    flags                           = {};
	uint32_t                               vertexBindingDescriptionCount   = 0;
	const VertexInputBindingDescription *  pVertexBindingDescriptions      = nullptr;// len vertexBindingDescriptionCount
	uint32_t                               vertexAttributeDescriptionCount = 0;
	const VertexInputAttributeDescription *pVertexAttributeDescriptions    = nullptr;// len vertexAttributeDescriptionCount
	auto vertexBindingDescriptions() -> impl_Struct::VecView<uint32_t, VertexInputBindingDescription>;
	auto vertexAttributeDescriptions() -> impl_Struct::VecView<uint32_t, VertexInputAttributeDescription>;
};
struct PipelineViewportDepthClampControlCreateInfoEXT {
	StructureType             sType            = StructureType::PipelineViewportDepthClampControlCreateInfoEXT;
	const void *              pNext            = nullptr;
	DepthClampModeEXT         depthClampMode   = DepthClampModeEXT::ViewportRange;
	const DepthClampRangeEXT *pDepthClampRange = nullptr;
};
struct PipelineViewportShadingRateImageStateCreateInfoNV {
	StructureType               sType                  = StructureType::PipelineViewportShadingRateImageStateCreateInfoNV;
	const void *                pNext                  = nullptr;
	Bool32                      shadingRateImageEnable = Constants::False;
	uint32_t                    viewportCount          = 0;
	const ShadingRatePaletteNV *pShadingRatePalettes   = nullptr;// len viewportCount
	auto shadingRatePalettes() -> impl_Struct::VecView<uint32_t, ShadingRatePaletteNV>;
};
struct PipelineViewportSwizzleStateCreateInfoNV {
	StructureType                             sType             = StructureType::PipelineViewportSwizzleStateCreateInfoNV;
	const void *                              pNext             = nullptr;
	PipelineViewportSwizzleStateCreateFlagsNV flags             = {};
	uint32_t                                  viewportCount     = 0;
	const ViewportSwizzleNV *                 pViewportSwizzles = nullptr;// len viewportCount
	auto viewportSwizzles() -> impl_Struct::VecView<uint32_t, ViewportSwizzleNV>;
};
struct PipelineViewportWScalingStateCreateInfoNV {
	StructureType             sType                  = StructureType::PipelineViewportWScalingStateCreateInfoNV;
	const void *              pNext                  = nullptr;
	Bool32                    viewportWScalingEnable = Constants::False;
	uint32_t                  viewportCount          = 0;
	const ViewportWScalingNV *pViewportWScalings     = nullptr;// len viewportCount
	auto viewportWScalings() -> impl_Struct::VecView<uint32_t, ViewportWScalingNV>;
};
struct PresentTimesInfoGOOGLE {
	StructureType            sType          = StructureType::PresentTimesInfoGOOGLE;
	const void *             pNext          = nullptr;
	uint32_t                 swapchainCount = 0;
	const PresentTimeGOOGLE *pTimes         = nullptr;// len swapchainCount
	auto times() -> impl_Struct::VecView<uint32_t, PresentTimeGOOGLE>;
};
struct PresentTimingsInfoEXT {
	StructureType               sType          = StructureType::PresentTimingsInfoEXT;
	const void *                pNext          = nullptr;
	uint32_t                    swapchainCount = 0;
	const PresentTimingInfoEXT *pTimingInfos   = nullptr;// len swapchainCount
	auto timingInfos() -> impl_Struct::VecView<uint32_t, PresentTimingInfoEXT>;
};
struct PushDataInfoEXT {
	StructureType            sType  = StructureType::PushDataInfoEXT;
	const void *             pNext  = nullptr;
	uint32_t                 offset = 0;
	HostAddressRangeConstEXT data   = {};
};
struct QueueFamilyDataGraphPropertiesARM {
	StructureType                              sType     = StructureType::QueueFamilyDataGraphPropertiesARM;
	void *                                     pNext     = nullptr;
	PhysicalDeviceDataGraphProcessingEngineARM engine    = {};
	PhysicalDeviceDataGraphOperationSupportARM operation = {};
};
struct QueueFamilyDataGraphTOSAPropertiesARM {
	StructureType                      sType          = StructureType::QueueFamilyDataGraphTosaPropertiesARM;
	void *                             pNext          = nullptr;
	uint32_t                           profileCount   = 0;
	const DataGraphTOSANameQualityARM *pProfiles      = nullptr;// len profileCount
	uint32_t                           extensionCount = 0;
	const DataGraphTOSANameQualityARM *pExtensions    = nullptr;// len extensionCount
	DataGraphTOSALevelARM              level          = DataGraphTOSALevelARM::DataGraphTosaLevelNone;
	auto profiles() -> impl_Struct::VecView<uint32_t, DataGraphTOSANameQualityARM>;
	auto extensions() -> impl_Struct::VecView<uint32_t, DataGraphTOSANameQualityARM>;
};
struct QueueFamilyOptimalImageTransferGranularityPropertiesKHR {
	StructureType sType                           = StructureType::QueueFamilyOptimalImageTransferGranularityPropertiesKHR;
	void *        pNext                           = nullptr;
	Extent3D      optimalImageTransferGranularity = {};
};
struct QueueFamilyProperties {
	QueueFlags queueFlags                  = {};
	uint32_t   queueCount                  = 0;
	uint32_t   timestampValidBits          = 0;
	Extent3D   minImageTransferGranularity = {};
};
struct Rect2D {
	Offset2D offset = {};
	Extent2D extent = {};
};
struct RectLayerKHR {
	Offset2D offset = {};
	Extent2D extent = {};
	uint32_t layer  = 0;
};
struct RenderPassCreationFeedbackCreateInfoEXT {
	StructureType                      sType               = StructureType::RenderPassCreationFeedbackCreateInfoEXT;
	const void *                       pNext               = nullptr;
	RenderPassCreationFeedbackInfoEXT *pRenderPassFeedback = nullptr;
};
struct RenderPassFragmentDensityMapCreateInfoEXT {
	StructureType       sType                        = StructureType::RenderPassFragmentDensityMapCreateInfoEXT;
	const void *        pNext                        = nullptr;
	AttachmentReference fragmentDensityMapAttachment = {};
};
struct RenderPassFragmentDensityMapOffsetEndInfoEXT {
	StructureType   sType                      = StructureType::RenderPassFragmentDensityMapOffsetEndInfoEXT;
	const void *    pNext                      = nullptr;
	uint32_t        fragmentDensityOffsetCount = 0;
	const Offset2D *pFragmentDensityOffsets    = nullptr;// len fragmentDensityOffsetCount
	auto fragmentDensityOffsets() -> impl_Struct::VecView<uint32_t, Offset2D>;
};
struct RenderPassInputAttachmentAspectCreateInfo {
	StructureType                         sType                = StructureType::RenderPassInputAttachmentAspectCreateInfo;
	const void *                          pNext                = nullptr;
	uint32_t                              aspectReferenceCount = 0;
	const InputAttachmentAspectReference *pAspectReferences    = nullptr;// len aspectReferenceCount
	auto aspectReferences() -> impl_Struct::VecView<uint32_t, InputAttachmentAspectReference>;
};
struct RenderPassStripeSubmitInfoARM {
	StructureType              sType                    = StructureType::RenderPassStripeSubmitInfoARM;
	const void *               pNext                    = nullptr;
	uint32_t                   stripeSemaphoreInfoCount = 0;
	const SemaphoreSubmitInfo *pStripeSemaphoreInfos    = nullptr;// len stripeSemaphoreInfoCount
	auto stripeSemaphoreInfos() -> impl_Struct::VecView<uint32_t, SemaphoreSubmitInfo>;
};
struct RenderPassSubpassFeedbackCreateInfoEXT {
	StructureType                     sType            = StructureType::RenderPassSubpassFeedbackCreateInfoEXT;
	const void *                      pNext            = nullptr;
	RenderPassSubpassFeedbackInfoEXT *pSubpassFeedback = nullptr;
};
struct RenderPassTileShadingCreateInfoQCOM {
	StructureType                  sType         = StructureType::RenderPassTileShadingCreateInfoQCOM;
	const void *                   pNext         = nullptr;
	TileShadingRenderPassFlagsQCOM flags         = {};
	Extent2D                       tileApronSize = {};
};
struct RenderingFragmentShadingRateAttachmentInfoKHR {
	StructureType                            sType                          = StructureType::RenderingFragmentShadingRateAttachmentInfoKHR;
	const void *                             pNext                          = nullptr;
	impl_Struct::AssignableHandle<ImageView> imageView;
	ImageLayout                              imageLayout                    = ImageLayout::Undefined;
	Extent2D                                 shadingRateAttachmentTexelSize = {};
};
struct SampleLocationsInfoEXT {
	StructureType            sType                   = StructureType::SampleLocationsInfoEXT;
	const void *             pNext                   = nullptr;
	SampleCountBits          sampleLocationsPerPixel = SampleCountBits::v1;
	Extent2D                 sampleLocationGridSize  = {};
	uint32_t                 sampleLocationsCount    = 0;
	const SampleLocationEXT *pSampleLocations        = nullptr;// len sampleLocationsCount
	auto sampleLocations() -> impl_Struct::VecView<uint32_t, SampleLocationEXT>;
};
struct SamplerBlockMatchWindowCreateInfoQCOM {
	StructureType                   sType             = StructureType::SamplerBlockMatchWindowCreateInfoQCOM;
	const void *                    pNext             = nullptr;
	Extent2D                        windowExtent      = {};
	BlockMatchWindowCompareModeQCOM windowCompareMode = BlockMatchWindowCompareModeQCOM::Min;
};
struct SamplerBorderColorComponentMappingCreateInfoEXT {
	StructureType    sType      = StructureType::SamplerBorderColorComponentMappingCreateInfoEXT;
	const void *     pNext      = nullptr;
	ComponentMapping components = {};
	Bool32           srgb       = Constants::False;
};
struct SamplerCustomBorderColorCreateInfoEXT {
	StructureType   sType             = StructureType::SamplerCustomBorderColorCreateInfoEXT;
	const void *    pNext             = nullptr;
	ClearColorValue customBorderColor = {};
	Format          format            = Format::Undefined;
};
struct SamplerYcbcrConversionCreateInfo {
	StructureType               sType                       = StructureType::SamplerYcbcrConversionCreateInfo;
	const void *                pNext                       = nullptr;
	Format                      format                      = Format::Undefined;
	SamplerYcbcrModelConversion ycbcrModel                  = SamplerYcbcrModelConversion::RgbIdentity;
	SamplerYcbcrRange           ycbcrRange                  = SamplerYcbcrRange::ItuFull;
	ComponentMapping            components                  = {};
	ChromaLocation              xChromaOffset               = ChromaLocation::CositedEven;
	ChromaLocation              yChromaOffset               = ChromaLocation::CositedEven;
	Filter                      chromaFilter                = Filter::Nearest;
	Bool32                      forceExplicitReconstruction = Constants::False;
};
struct ShaderStatisticsInfoAMD {
	ShaderStageFlags        shaderStageMask      = {};
	ShaderResourceUsageAMD  resourceUsage        = {};
	uint32_t                numPhysicalVgprs     = 0;
	uint32_t                numPhysicalSgprs     = 0;
	uint32_t                numAvailableVgprs    = 0;
	uint32_t                numAvailableSgprs    = 0;
	std::array<uint32_t, 3> computeWorkGroupSize = {};
};
struct SparseBufferMemoryBindInfo {
	impl_Struct::AssignableHandle<Buffer> buffer;
	uint32_t                              bindCount = 0;
	const SparseMemoryBind *              pBinds    = nullptr;// len bindCount
	auto binds() -> impl_Struct::VecView<uint32_t, SparseMemoryBind>;
};
struct SparseImageFormatProperties {
	ImageAspectFlags       aspectMask       = {};
	Extent3D               imageGranularity = {};
	SparseImageFormatFlags flags            = {};
};
struct SparseImageMemoryBind {
	ImageSubresource                            subresource  = {};
	Offset3D                                    offset       = {};
	Extent3D                                    extent       = {};
	impl_Struct::AssignableHandle<DeviceMemory> memory;
	DeviceSize                                  memoryOffset = 0;
	SparseMemoryBindFlags                       flags        = {};
};
struct SparseImageOpaqueMemoryBindInfo {
	impl_Struct::AssignableHandle<Image> image;
	uint32_t                             bindCount = 0;
	const SparseMemoryBind *             pBinds    = nullptr;// len bindCount
	auto binds() -> impl_Struct::VecView<uint32_t, SparseMemoryBind>;
};
struct SpecializationInfo {
	uint32_t                      mapEntryCount = 0;
	const SpecializationMapEntry *pMapEntries   = nullptr;// len mapEntryCount
	size_t                        dataSize      = 0;
	const void *                  pData         = nullptr;// len dataSize
	auto mapEntries() -> impl_Struct::VecView<uint32_t, SpecializationMapEntry>;
};
struct SubmitInfo2 {
	StructureType                  sType                    = StructureType::SubmitInfo2;
	const void *                   pNext                    = nullptr;
	SubmitFlags                    flags                    = {};
	uint32_t                       waitSemaphoreInfoCount   = 0;
	const SemaphoreSubmitInfo *    pWaitSemaphoreInfos      = nullptr;// len waitSemaphoreInfoCount
	uint32_t                       commandBufferInfoCount   = 0;
	const CommandBufferSubmitInfo *pCommandBufferInfos      = nullptr;// len commandBufferInfoCount
	uint32_t                       signalSemaphoreInfoCount = 0;
	const SemaphoreSubmitInfo *    pSignalSemaphoreInfos    = nullptr;// len signalSemaphoreInfoCount
	auto waitSemaphoreInfos() -> impl_Struct::VecView<uint32_t, SemaphoreSubmitInfo>;
	auto commandBufferInfos() -> impl_Struct::VecView<uint32_t, CommandBufferSubmitInfo>;
	auto signalSemaphoreInfos() -> impl_Struct::VecView<uint32_t, SemaphoreSubmitInfo>;
};
struct SubpassDescription {
	SubpassDescriptionFlags    flags                   = {};
	PipelineBindPoint          pipelineBindPoint       = PipelineBindPoint::Graphics;
	uint32_t                   inputAttachmentCount    = 0;
	const AttachmentReference *pInputAttachments       = nullptr;// len inputAttachmentCount
	uint32_t                   colorAttachmentCount    = 0;
	const AttachmentReference *pColorAttachments       = nullptr;// len colorAttachmentCount
	const AttachmentReference *pResolveAttachments     = nullptr;// len colorAttachmentCount
	const AttachmentReference *pDepthStencilAttachment = nullptr;
	uint32_t                   preserveAttachmentCount = 0;
	const uint32_t *           pPreserveAttachments    = nullptr;// len preserveAttachmentCount
	auto inputAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference>;
	auto colorAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference>;
	auto preserveAttachments() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct SubpassDescription2 {
	StructureType               sType                   = StructureType::SubpassDescription2;
	const void *                pNext                   = nullptr;
	SubpassDescriptionFlags     flags                   = {};
	PipelineBindPoint           pipelineBindPoint       = PipelineBindPoint::Graphics;
	uint32_t                    viewMask                = 0;
	uint32_t                    inputAttachmentCount    = 0;
	const AttachmentReference2 *pInputAttachments       = nullptr;// len inputAttachmentCount
	uint32_t                    colorAttachmentCount    = 0;
	const AttachmentReference2 *pColorAttachments       = nullptr;// len colorAttachmentCount
	const AttachmentReference2 *pResolveAttachments     = nullptr;// len colorAttachmentCount
	const AttachmentReference2 *pDepthStencilAttachment = nullptr;
	uint32_t                    preserveAttachmentCount = 0;
	const uint32_t *            pPreserveAttachments    = nullptr;// len preserveAttachmentCount
	auto inputAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference2>;
	auto colorAttachments() -> impl_Struct::VecView<uint32_t, AttachmentReference2>;
	auto preserveAttachments() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct SubpassDescriptionDepthStencilResolve {
	StructureType               sType                          = StructureType::SubpassDescriptionDepthStencilResolve;
	const void *                pNext                          = nullptr;
	ResolveModeBits             depthResolveMode               = ResolveModeBits::None;
	ResolveModeBits             stencilResolveMode             = ResolveModeBits::None;
	const AttachmentReference2 *pDepthStencilResolveAttachment = nullptr;
};
struct SubresourceLayout2 {
	StructureType     sType             = StructureType::SubresourceLayout2;
	void *            pNext             = nullptr;
	SubresourceLayout subresourceLayout = {};
};
struct SurfaceCapabilities2EXT {
	StructureType            sType                    = StructureType::SurfaceCapabilities2EXT;
	void *                   pNext                    = nullptr;
	uint32_t                 minImageCount            = 0;
	uint32_t                 maxImageCount            = 0;
	Extent2D                 currentExtent            = {};
	Extent2D                 minImageExtent           = {};
	Extent2D                 maxImageExtent           = {};
	uint32_t                 maxImageArrayLayers      = 0;
	SurfaceTransformFlagsKHR supportedTransforms      = {};
	SurfaceTransformBitsKHR  currentTransform         = SurfaceTransformBitsKHR::Identity;
	CompositeAlphaFlagsKHR   supportedCompositeAlpha  = {};
	ImageUsageFlags          supportedUsageFlags      = {};
	SurfaceCounterFlagsEXT   supportedSurfaceCounters = {};
};
struct SurfaceCapabilitiesKHR {
	uint32_t                 minImageCount           = 0;
	uint32_t                 maxImageCount           = 0;
	Extent2D                 currentExtent           = {};
	Extent2D                 minImageExtent          = {};
	Extent2D                 maxImageExtent          = {};
	uint32_t                 maxImageArrayLayers     = 0;
	SurfaceTransformFlagsKHR supportedTransforms     = {};
	SurfaceTransformBitsKHR  currentTransform        = SurfaceTransformBitsKHR::Identity;
	CompositeAlphaFlagsKHR   supportedCompositeAlpha = {};
	ImageUsageFlags          supportedUsageFlags     = {};
};
struct SurfaceFormat2KHR {
	StructureType    sType         = StructureType::SurfaceFormat2KHR;
	void *           pNext         = nullptr;
	SurfaceFormatKHR surfaceFormat = {};
};
struct SurfacePresentScalingCapabilitiesKHR {
	StructureType          sType                    = StructureType::SurfacePresentScalingCapabilitiesKHR;
	void *                 pNext                    = nullptr;
	PresentScalingFlagsKHR supportedPresentScaling  = {};
	PresentGravityFlagsKHR supportedPresentGravityX = {};
	PresentGravityFlagsKHR supportedPresentGravityY = {};
	Extent2D               minScaledImageExtent     = {};
	Extent2D               maxScaledImageExtent     = {};
};
struct SwapchainCreateInfoKHR {
	StructureType                               sType                 = StructureType::SwapchainCreateInfoKHR;
	const void *                                pNext                 = nullptr;
	SwapchainCreateFlagsKHR                     flags                 = {};
	impl_Struct::AssignableHandle<SurfaceKHR>   surface;
	uint32_t                                    minImageCount         = 0;
	Format                                      imageFormat           = Format::Undefined;
	ColorSpaceKHR                               imageColorSpace       = ColorSpaceKHR::SrgbNonlinear;
	Extent2D                                    imageExtent           = {};
	uint32_t                                    imageArrayLayers      = 0;
	ImageUsageFlags                             imageUsage            = {};
	SharingMode                                 imageSharingMode      = SharingMode::Exclusive;
	uint32_t                                    queueFamilyIndexCount = 0;
	const uint32_t *                            pQueueFamilyIndices   = nullptr;// len queueFamilyIndexCount
	SurfaceTransformBitsKHR                     preTransform          = SurfaceTransformBitsKHR::Identity;
	CompositeAlphaBitsKHR                       compositeAlpha        = CompositeAlphaBitsKHR::Opaque;
	PresentModeKHR                              presentMode           = PresentModeKHR::Immediate;
	Bool32                                      clipped               = Constants::False;
	impl_Struct::AssignableHandle<SwapchainKHR> oldSwapchain;
	auto queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct TensorCreateInfoARM {
	StructureType               sType                 = StructureType::TensorCreateInfoARM;
	const void *                pNext                 = nullptr;
	TensorCreateFlagsARM        flags                 = {};
	const TensorDescriptionARM *pDescription          = nullptr;
	SharingMode                 sharingMode           = SharingMode::Exclusive;
	uint32_t                    queueFamilyIndexCount = 0;
	const uint32_t *            pQueueFamilyIndices   = nullptr;// len queueFamilyIndexCount
	auto queueFamilyIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct TensorDependencyInfoARM {
	StructureType                 sType                    = StructureType::TensorDependencyInfoARM;
	const void *                  pNext                    = nullptr;
	uint32_t                      tensorMemoryBarrierCount = 0;
	const TensorMemoryBarrierARM *pTensorMemoryBarriers    = nullptr;// len tensorMemoryBarrierCount
	auto tensorMemoryBarriers() -> impl_Struct::VecView<uint32_t, TensorMemoryBarrierARM>;
};
struct TexelBufferDescriptorInfoEXT {
	StructureType         sType        = StructureType::TexelBufferDescriptorInfoEXT;
	const void *          pNext        = nullptr;
	Format                format       = Format::Undefined;
	DeviceAddressRangeKHR addressRange = {};
};
struct TilePropertiesQCOM {
	StructureType sType     = StructureType::TilePropertiesQCOM;
	void *        pNext     = nullptr;
	Extent3D      tileSize  = {};
	Extent2D      apronSize = {};
	Offset2D      origin    = {};
};
struct VideoCapabilitiesKHR {
	StructureType           sType                             = StructureType::VideoCapabilitiesKHR;
	void *                  pNext                             = nullptr;
	VideoCapabilityFlagsKHR flags                             = {};
	DeviceSize              minBitstreamBufferOffsetAlignment = 0;
	DeviceSize              minBitstreamBufferSizeAlignment   = 0;
	Extent2D                pictureAccessGranularity          = {};
	Extent2D                minCodedExtent                    = {};
	Extent2D                maxCodedExtent                    = {};
	uint32_t                maxDpbSlots                       = 0;
	uint32_t                maxActiveReferencePictures        = 0;
	ExtensionProperties     stdHeaderVersion                  = {};
};
struct VideoDecodeH264CapabilitiesKHR {
	StructureType        sType                  = StructureType::VideoDecodeH264CapabilitiesKHR;
	void *               pNext                  = nullptr;
	StdVideoH264LevelIdc maxLevelIdc            = {};
	Offset2D             fieldOffsetGranularity = {};
};
struct VideoDecodeH264SessionParametersCreateInfoKHR {
	StructureType                                     sType              = StructureType::VideoDecodeH264SessionParametersCreateInfoKHR;
	const void *                                      pNext              = nullptr;
	uint32_t                                          maxStdSPSCount     = 0;
	uint32_t                                          maxStdPPSCount     = 0;
	const VideoDecodeH264SessionParametersAddInfoKHR *pParametersAddInfo = nullptr;
};
struct VideoDecodeH265SessionParametersCreateInfoKHR {
	StructureType                                     sType              = StructureType::VideoDecodeH265SessionParametersCreateInfoKHR;
	const void *                                      pNext              = nullptr;
	uint32_t                                          maxStdVPSCount     = 0;
	uint32_t                                          maxStdSPSCount     = 0;
	uint32_t                                          maxStdPPSCount     = 0;
	const VideoDecodeH265SessionParametersAddInfoKHR *pParametersAddInfo = nullptr;
};
struct VideoEncodeAV1CapabilitiesKHR {
	StructureType                        sType                                         = StructureType::VideoEncodeAV1CapabilitiesKHR;
	void *                               pNext                                         = nullptr;
	VideoEncodeAV1CapabilityFlagsKHR     flags                                         = {};
	StdVideoAV1Level                     maxLevel                                      = {};
	Extent2D                             codedPictureAlignment                         = {};
	Extent2D                             maxTiles                                      = {};
	Extent2D                             minTileSize                                   = {};
	Extent2D                             maxTileSize                                   = {};
	VideoEncodeAV1SuperblockSizeFlagsKHR superblockSizes                               = {};
	uint32_t                             maxSingleReferenceCount                       = 0;
	uint32_t                             singleReferenceNameMask                       = 0;
	uint32_t                             maxUnidirectionalCompoundReferenceCount       = 0;
	uint32_t                             maxUnidirectionalCompoundGroup1ReferenceCount = 0;
	uint32_t                             unidirectionalCompoundReferenceNameMask       = 0;
	uint32_t                             maxBidirectionalCompoundReferenceCount        = 0;
	uint32_t                             maxBidirectionalCompoundGroup1ReferenceCount  = 0;
	uint32_t                             maxBidirectionalCompoundGroup2ReferenceCount  = 0;
	uint32_t                             bidirectionalCompoundReferenceNameMask        = 0;
	uint32_t                             maxTemporalLayerCount                         = 0;
	uint32_t                             maxSpatialLayerCount                          = 0;
	uint32_t                             maxOperatingPoints                            = 0;
	uint32_t                             minQIndex                                     = 0;
	uint32_t                             maxQIndex                                     = 0;
	Bool32                               prefersGopRemainingFrames                     = Constants::False;
	Bool32                               requiresGopRemainingFrames                    = Constants::False;
	VideoEncodeAV1StdFlagsKHR            stdSyntaxFlags                                = {};
};
struct VideoEncodeAV1QualityLevelPropertiesKHR {
	StructureType                     sType                                                  = StructureType::VideoEncodeAV1QualityLevelPropertiesKHR;
	void *                            pNext                                                  = nullptr;
	VideoEncodeAV1RateControlFlagsKHR preferredRateControlFlags                              = {};
	uint32_t                          preferredGopFrameCount                                 = 0;
	uint32_t                          preferredKeyFramePeriod                                = 0;
	uint32_t                          preferredConsecutiveBipredictiveFrameCount             = 0;
	uint32_t                          preferredTemporalLayerCount                            = 0;
	VideoEncodeAV1QIndexKHR           preferredConstantQIndex                                = {};
	uint32_t                          preferredMaxSingleReferenceCount                       = 0;
	uint32_t                          preferredSingleReferenceNameMask                       = 0;
	uint32_t                          preferredMaxUnidirectionalCompoundReferenceCount       = 0;
	uint32_t                          preferredMaxUnidirectionalCompoundGroup1ReferenceCount = 0;
	uint32_t                          preferredUnidirectionalCompoundReferenceNameMask       = 0;
	uint32_t                          preferredMaxBidirectionalCompoundReferenceCount        = 0;
	uint32_t                          preferredMaxBidirectionalCompoundGroup1ReferenceCount  = 0;
	uint32_t                          preferredMaxBidirectionalCompoundGroup2ReferenceCount  = 0;
	uint32_t                          preferredBidirectionalCompoundReferenceNameMask        = 0;
};
struct VideoEncodeAV1RateControlLayerInfoKHR {
	StructureType              sType           = StructureType::VideoEncodeAV1RateControlLayerInfoKHR;
	const void *               pNext           = nullptr;
	Bool32                     useMinQIndex    = Constants::False;
	VideoEncodeAV1QIndexKHR    minQIndex       = {};
	Bool32                     useMaxQIndex    = Constants::False;
	VideoEncodeAV1QIndexKHR    maxQIndex       = {};
	Bool32                     useMaxFrameSize = Constants::False;
	VideoEncodeAV1FrameSizeKHR maxFrameSize    = {};
};
struct VideoEncodeCapabilitiesKHR {
	StructureType                      sType                         = StructureType::VideoEncodeCapabilitiesKHR;
	void *                             pNext                         = nullptr;
	VideoEncodeCapabilityFlagsKHR      flags                         = {};
	VideoEncodeRateControlModeFlagsKHR rateControlModes              = {};
	uint32_t                           maxRateControlLayers          = 0;
	uint64_t                           maxBitrate                    = 0;
	uint32_t                           maxQualityLevels              = 0;
	Extent2D                           encodeInputPictureGranularity = {};
	VideoEncodeFeedbackFlagsKHR        supportedEncodeFeedbackFlags  = {};
};
struct VideoEncodeH264PictureInfoKHR {
	StructureType                          sType               = StructureType::VideoEncodeH264PictureInfoKHR;
	const void *                           pNext               = nullptr;
	uint32_t                               naluSliceEntryCount = 0;
	const VideoEncodeH264NaluSliceInfoKHR *pNaluSliceEntries   = nullptr;// len naluSliceEntryCount
	const StdVideoEncodeH264PictureInfo *  pStdPictureInfo     = nullptr;
	Bool32                                 generatePrefixNalu  = Constants::False;
	auto naluSliceEntries() -> impl_Struct::VecView<uint32_t, VideoEncodeH264NaluSliceInfoKHR>;
};
struct VideoEncodeH264QualityLevelPropertiesKHR {
	StructureType                      sType                             = StructureType::VideoEncodeH264QualityLevelPropertiesKHR;
	void *                             pNext                             = nullptr;
	VideoEncodeH264RateControlFlagsKHR preferredRateControlFlags         = {};
	uint32_t                           preferredGopFrameCount            = 0;
	uint32_t                           preferredIdrPeriod                = 0;
	uint32_t                           preferredConsecutiveBFrameCount   = 0;
	uint32_t                           preferredTemporalLayerCount       = 0;
	VideoEncodeH264QpKHR               preferredConstantQp               = {};
	uint32_t                           preferredMaxL0ReferenceCount      = 0;
	uint32_t                           preferredMaxL1ReferenceCount      = 0;
	Bool32                             preferredStdEntropyCodingModeFlag = Constants::False;
};
struct VideoEncodeH264RateControlLayerInfoKHR {
	StructureType               sType           = StructureType::VideoEncodeH264RateControlLayerInfoKHR;
	const void *                pNext           = nullptr;
	Bool32                      useMinQp        = Constants::False;
	VideoEncodeH264QpKHR        minQp           = {};
	Bool32                      useMaxQp        = Constants::False;
	VideoEncodeH264QpKHR        maxQp           = {};
	Bool32                      useMaxFrameSize = Constants::False;
	VideoEncodeH264FrameSizeKHR maxFrameSize    = {};
};
struct VideoEncodeH264SessionParametersCreateInfoKHR {
	StructureType                                     sType              = StructureType::VideoEncodeH264SessionParametersCreateInfoKHR;
	const void *                                      pNext              = nullptr;
	uint32_t                                          maxStdSPSCount     = 0;
	uint32_t                                          maxStdPPSCount     = 0;
	const VideoEncodeH264SessionParametersAddInfoKHR *pParametersAddInfo = nullptr;
};
struct VideoEncodeH265CapabilitiesKHR {
	StructureType                             sType                               = StructureType::VideoEncodeH265CapabilitiesKHR;
	void *                                    pNext                               = nullptr;
	VideoEncodeH265CapabilityFlagsKHR         flags                               = {};
	StdVideoH265LevelIdc                      maxLevelIdc                         = {};
	uint32_t                                  maxSliceSegmentCount                = 0;
	Extent2D                                  maxTiles                            = {};
	VideoEncodeH265CtbSizeFlagsKHR            ctbSizes                            = {};
	VideoEncodeH265TransformBlockSizeFlagsKHR transformBlockSizes                 = {};
	uint32_t                                  maxPPictureL0ReferenceCount         = 0;
	uint32_t                                  maxBPictureL0ReferenceCount         = 0;
	uint32_t                                  maxL1ReferenceCount                 = 0;
	uint32_t                                  maxSubLayerCount                    = 0;
	Bool32                                    expectDyadicTemporalSubLayerPattern = Constants::False;
	int32_t                                   minQp                               = 0;
	int32_t                                   maxQp                               = 0;
	Bool32                                    prefersGopRemainingFrames           = Constants::False;
	Bool32                                    requiresGopRemainingFrames          = Constants::False;
	VideoEncodeH265StdFlagsKHR                stdSyntaxFlags                      = {};
};
struct VideoEncodeH265PictureInfoKHR {
	StructureType                                 sType                      = StructureType::VideoEncodeH265PictureInfoKHR;
	const void *                                  pNext                      = nullptr;
	uint32_t                                      naluSliceSegmentEntryCount = 0;
	const VideoEncodeH265NaluSliceSegmentInfoKHR *pNaluSliceSegmentEntries   = nullptr;// len naluSliceSegmentEntryCount
	const StdVideoEncodeH265PictureInfo *         pStdPictureInfo            = nullptr;
	auto naluSliceSegmentEntries() -> impl_Struct::VecView<uint32_t, VideoEncodeH265NaluSliceSegmentInfoKHR>;
};
struct VideoEncodeH265QualityLevelPropertiesKHR {
	StructureType                      sType                           = StructureType::VideoEncodeH265QualityLevelPropertiesKHR;
	void *                             pNext                           = nullptr;
	VideoEncodeH265RateControlFlagsKHR preferredRateControlFlags       = {};
	uint32_t                           preferredGopFrameCount          = 0;
	uint32_t                           preferredIdrPeriod              = 0;
	uint32_t                           preferredConsecutiveBFrameCount = 0;
	uint32_t                           preferredSubLayerCount          = 0;
	VideoEncodeH265QpKHR               preferredConstantQp             = {};
	uint32_t                           preferredMaxL0ReferenceCount    = 0;
	uint32_t                           preferredMaxL1ReferenceCount    = 0;
};
struct VideoEncodeH265RateControlLayerInfoKHR {
	StructureType               sType           = StructureType::VideoEncodeH265RateControlLayerInfoKHR;
	const void *                pNext           = nullptr;
	Bool32                      useMinQp        = Constants::False;
	VideoEncodeH265QpKHR        minQp           = {};
	Bool32                      useMaxQp        = Constants::False;
	VideoEncodeH265QpKHR        maxQp           = {};
	Bool32                      useMaxFrameSize = Constants::False;
	VideoEncodeH265FrameSizeKHR maxFrameSize    = {};
};
struct VideoEncodeH265SessionParametersCreateInfoKHR {
	StructureType                                     sType              = StructureType::VideoEncodeH265SessionParametersCreateInfoKHR;
	const void *                                      pNext              = nullptr;
	uint32_t                                          maxStdVPSCount     = 0;
	uint32_t                                          maxStdSPSCount     = 0;
	uint32_t                                          maxStdPPSCount     = 0;
	const VideoEncodeH265SessionParametersAddInfoKHR *pParametersAddInfo = nullptr;
};
struct VideoEncodeQuantizationMapCapabilitiesKHR {
	StructureType sType                    = StructureType::VideoEncodeQuantizationMapCapabilitiesKHR;
	void *        pNext                    = nullptr;
	Extent2D      maxQuantizationMapExtent = {};
};
struct VideoEncodeQuantizationMapInfoKHR {
	StructureType                            sType                 = StructureType::VideoEncodeQuantizationMapInfoKHR;
	const void *                             pNext                 = nullptr;
	impl_Struct::AssignableHandle<ImageView> quantizationMap;
	Extent2D                                 quantizationMapExtent = {};
};
struct VideoEncodeQuantizationMapSessionParametersCreateInfoKHR {
	StructureType sType                    = StructureType::VideoEncodeQuantizationMapSessionParametersCreateInfoKHR;
	const void *  pNext                    = nullptr;
	Extent2D      quantizationMapTexelSize = {};
};
struct VideoEncodeRateControlInfoKHR {
	StructureType                             sType                        = StructureType::VideoEncodeRateControlInfoKHR;
	const void *                              pNext                        = nullptr;
	VideoEncodeRateControlFlagsKHR            flags                        = {};
	VideoEncodeRateControlModeBitsKHR         rateControlMode              = VideoEncodeRateControlModeBitsKHR::Default;
	uint32_t                                  layerCount                   = 0;
	const VideoEncodeRateControlLayerInfoKHR *pLayers                      = nullptr;// len layerCount
	uint32_t                                  virtualBufferSizeInMs        = 0;
	uint32_t                                  initialVirtualBufferSizeInMs = 0;
	auto layers() -> impl_Struct::VecView<uint32_t, VideoEncodeRateControlLayerInfoKHR>;
};
struct VideoFormatPropertiesKHR {
	StructureType    sType            = StructureType::VideoFormatPropertiesKHR;
	void *           pNext            = nullptr;
	Format           format           = Format::Undefined;
	ComponentMapping componentMapping = {};
	ImageCreateFlags imageCreateFlags = {};
	ImageType        imageType        = ImageType::v1D;
	ImageTiling      imageTiling      = ImageTiling::Optimal;
	ImageUsageFlags  imageUsageFlags  = {};
};
struct VideoFormatQuantizationMapPropertiesKHR {
	StructureType sType                    = StructureType::VideoFormatQuantizationMapPropertiesKHR;
	void *        pNext                    = nullptr;
	Extent2D      quantizationMapTexelSize = {};
};
struct VideoPictureResourceInfoKHR {
	StructureType                            sType            = StructureType::VideoPictureResourceInfoKHR;
	const void *                             pNext            = nullptr;
	Offset2D                                 codedOffset      = {};
	Extent2D                                 codedExtent      = {};
	uint32_t                                 baseArrayLayer   = 0;
	impl_Struct::AssignableHandle<ImageView> imageViewBinding;
};
struct VideoProfileListInfoKHR {
	StructureType              sType        = StructureType::VideoProfileListInfoKHR;
	const void *               pNext        = nullptr;
	uint32_t                   profileCount = 0;
	const VideoProfileInfoKHR *pProfiles    = nullptr;// len profileCount
	auto profiles() -> impl_Struct::VecView<uint32_t, VideoProfileInfoKHR>;
};
struct VideoSessionCreateInfoKHR {
	StructureType              sType                      = StructureType::VideoSessionCreateInfoKHR;
	const void *               pNext                      = nullptr;
	uint32_t                   queueFamilyIndex           = 0;
	VideoSessionCreateFlagsKHR flags                      = {};
	const VideoProfileInfoKHR *pVideoProfile              = nullptr;
	Format                     pictureFormat              = Format::Undefined;
	Extent2D                   maxCodedExtent             = {};
	Format                     referencePictureFormat     = Format::Undefined;
	uint32_t                   maxDpbSlots                = 0;
	uint32_t                   maxActiveReferencePictures = 0;
	const ExtensionProperties *pStdHeaderVersion          = nullptr;
};
struct VideoSessionMemoryRequirementsKHR {
	StructureType      sType              = StructureType::VideoSessionMemoryRequirementsKHR;
	void *             pNext              = nullptr;
	uint32_t           memoryBindIndex    = 0;
	MemoryRequirements memoryRequirements = {};
};
struct WriteDescriptorSet {
	StructureType                                    sType            = StructureType::WriteDescriptorSet;
	const void *                                     pNext            = nullptr;
	impl_Struct::AssignableHandle<DescriptorSet>     dstSet;
	uint32_t                                         dstBinding       = 0;
	uint32_t                                         dstArrayElement  = 0;
	uint32_t                                         descriptorCount  = 0;
	DescriptorType                                   descriptorType   = DescriptorType::Sampler;
	const DescriptorImageInfo *                      pImageInfo       = nullptr;// len descriptorCount
	const DescriptorBufferInfo *                     pBufferInfo      = nullptr;// len descriptorCount
	const impl_Struct::AssignableHandle<BufferView> *pTexelBufferView = nullptr;// len descriptorCount
	auto imageInfo() -> impl_Struct::VecView<uint32_t, DescriptorImageInfo>;
};
#ifdef VK_ENABLE_BETA_EXTENSIONS
	struct AccelerationStructureDenseGeometryFormatTrianglesDataAMDX {
		StructureType                sType             = StructureType::AccelerationStructureDenseGeometryFormatTrianglesDataAMDX;
		const void *                 pNext             = nullptr;
		DeviceOrHostAddressConstKHR  compressedData    = {};
		DeviceSize                   dataSize          = 0;
		uint32_t                     numTriangles      = 0;
		uint32_t                     numVertices       = 0;
		uint32_t                     maxPrimitiveIndex = 0;
		uint32_t                     maxGeometryIndex  = 0;
		CompressedTriangleFormatAMDX format            = CompressedTriangleFormatAMDX::Dgf1;
	};
	struct AccelerationStructureTrianglesDisplacementMicromapNV {
		StructureType                              sType                                 = StructureType::AccelerationStructureTrianglesDisplacementMicromapNV;
		void *                                     pNext                                 = nullptr;
		Format                                     displacementBiasAndScaleFormat        = Format::Undefined;
		Format                                     displacementVectorFormat              = Format::Undefined;
		DeviceOrHostAddressConstKHR                displacementBiasAndScaleBuffer        = {};
		DeviceSize                                 displacementBiasAndScaleStride        = 0;
		DeviceOrHostAddressConstKHR                displacementVectorBuffer              = {};
		DeviceSize                                 displacementVectorStride              = 0;
		DeviceOrHostAddressConstKHR                displacedMicromapPrimitiveFlags       = {};
		DeviceSize                                 displacedMicromapPrimitiveFlagsStride = 0;
		IndexType                                  indexType                             = IndexType::Uint16;
		DeviceOrHostAddressConstKHR                indexBuffer                           = {};
		DeviceSize                                 indexStride                           = 0;
		uint32_t                                   baseTriangle                          = 0;
		uint32_t                                   usageCountsCount                      = 0;
		const MicromapUsageEXT *                   pUsageCounts                          = nullptr;// len usageCountsCount
		const MicromapUsageEXT * const*            ppUsageCounts                         = nullptr;// len usageCountsCount,1
		impl_Struct::AssignableHandle<MicromapEXT> micromap;
		auto usageCounts() -> impl_Struct::VecView<uint32_t, MicromapUsageEXT>;
	};
	struct DispatchGraphCountInfoAMDX {
		uint32_t                     count  = 0;
		DeviceOrHostAddressConstAMDX infos  = {};
		uint64_t                     stride = 0;
	};
	struct DispatchGraphInfoAMDX {
		uint32_t                     nodeIndex     = 0;
		uint32_t                     payloadCount  = 0;
		DeviceOrHostAddressConstAMDX payloads      = {};
		uint64_t                     payloadStride = 0;
	};
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_ANDROID_KHR
	struct AndroidHardwareBufferFormatProperties2ANDROID {
		StructureType               sType                            = StructureType::ANDROIDHardwareBufferFormatProperties2ANDROID;
		void *                      pNext                            = nullptr;
		Format                      format                           = Format::Undefined;
		uint64_t                    externalFormat                   = 0;
		FormatFeatureFlags2         formatFeatures                   = {};
		ComponentMapping            samplerYcbcrConversionComponents = {};
		SamplerYcbcrModelConversion suggestedYcbcrModel              = SamplerYcbcrModelConversion::RgbIdentity;
		SamplerYcbcrRange           suggestedYcbcrRange              = SamplerYcbcrRange::ItuFull;
		ChromaLocation              suggestedXChromaOffset           = ChromaLocation::CositedEven;
		ChromaLocation              suggestedYChromaOffset           = ChromaLocation::CositedEven;
	};
	struct AndroidHardwareBufferFormatPropertiesANDROID {
		StructureType               sType                            = StructureType::ANDROIDHardwareBufferFormatPropertiesANDROID;
		void *                      pNext                            = nullptr;
		Format                      format                           = Format::Undefined;
		uint64_t                    externalFormat                   = 0;
		FormatFeatureFlags          formatFeatures                   = {};
		ComponentMapping            samplerYcbcrConversionComponents = {};
		SamplerYcbcrModelConversion suggestedYcbcrModel              = SamplerYcbcrModelConversion::RgbIdentity;
		SamplerYcbcrRange           suggestedYcbcrRange              = SamplerYcbcrRange::ItuFull;
		ChromaLocation              suggestedXChromaOffset           = ChromaLocation::CositedEven;
		ChromaLocation              suggestedYChromaOffset           = ChromaLocation::CositedEven;
	};
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_FUCHSIA
	struct BufferCollectionPropertiesFUCHSIA {
		StructureType               sType                            = StructureType::BufferCollectionPropertiesFUCHSIA;
		void *                      pNext                            = nullptr;
		uint32_t                    memoryTypeBits                   = 0;
		uint32_t                    bufferCount                      = 0;
		uint32_t                    createInfoIndex                  = 0;
		uint64_t                    sysmemPixelFormat                = 0;
		FormatFeatureFlags          formatFeatures                   = {};
		SysmemColorSpaceFUCHSIA     sysmemColorSpaceIndex            = {};
		ComponentMapping            samplerYcbcrConversionComponents = {};
		SamplerYcbcrModelConversion suggestedYcbcrModel              = SamplerYcbcrModelConversion::RgbIdentity;
		SamplerYcbcrRange           suggestedYcbcrRange              = SamplerYcbcrRange::ItuFull;
		ChromaLocation              suggestedXChromaOffset           = ChromaLocation::CositedEven;
		ChromaLocation              suggestedYChromaOffset           = ChromaLocation::CositedEven;
	};
	struct BufferConstraintsInfoFUCHSIA {
		StructureType                          sType                       = StructureType::BufferConstraintsInfoFUCHSIA;
		const void *                           pNext                       = nullptr;
		BufferCreateInfo                       createInfo                  = {};
		FormatFeatureFlags                     requiredFormatFeatures      = {};
		BufferCollectionConstraintsInfoFUCHSIA bufferCollectionConstraints = {};
	};
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_OHOS
	struct NativeBufferFormatPropertiesOHOS {
		StructureType               sType                            = StructureType::NativeBufferFormatPropertiesOHOS;
		void *                      pNext                            = nullptr;
		Format                      format                           = Format::Undefined;
		uint64_t                    externalFormat                   = 0;
		FormatFeatureFlags          formatFeatures                   = {};
		ComponentMapping            samplerYcbcrConversionComponents = {};
		SamplerYcbcrModelConversion suggestedYcbcrModel              = SamplerYcbcrModelConversion::RgbIdentity;
		SamplerYcbcrRange           suggestedYcbcrRange              = SamplerYcbcrRange::ItuFull;
		ChromaLocation              suggestedXChromaOffset           = ChromaLocation::CositedEven;
		ChromaLocation              suggestedYChromaOffset           = ChromaLocation::CositedEven;
	};
#endif // VK_USE_PLATFORM_OHOS
#ifdef VK_USE_PLATFORM_SCREEN_QNX
	struct ScreenBufferFormatPropertiesQNX {
		StructureType               sType                            = StructureType::ScreenBufferFormatPropertiesQNX;
		void *                      pNext                            = nullptr;
		Format                      format                           = Format::Undefined;
		uint64_t                    externalFormat                   = 0;
		uint64_t                    screenUsage                      = 0;
		FormatFeatureFlags          formatFeatures                   = {};
		ComponentMapping            samplerYcbcrConversionComponents = {};
		SamplerYcbcrModelConversion suggestedYcbcrModel              = SamplerYcbcrModelConversion::RgbIdentity;
		SamplerYcbcrRange           suggestedYcbcrRange              = SamplerYcbcrRange::ItuFull;
		ChromaLocation              suggestedXChromaOffset           = ChromaLocation::CositedEven;
		ChromaLocation              suggestedYChromaOffset           = ChromaLocation::CositedEven;
	};
#endif // VK_USE_PLATFORM_SCREEN_QNX
union AccelerationStructureGeometryDataKHR {
	AccelerationStructureGeometryTrianglesDataKHR triangles;
	AccelerationStructureGeometryAabbsDataKHR     aabbs;
	AccelerationStructureGeometryInstancesDataKHR instances;
};
union AccelerationStructureMotionInstanceDataNV {
	AccelerationStructureInstanceKHR            staticInstance;
	AccelerationStructureMatrixMotionInstanceNV matrixMotionInstance;
	AccelerationStructureSRTMotionInstanceNV    srtMotionInstance;
};
struct AttachmentSampleLocationsEXT {
	uint32_t               attachmentIndex     = 0;
	SampleLocationsInfoEXT sampleLocationsInfo = {};
};
struct BindImageMemoryDeviceGroupInfo {
	StructureType   sType                        = StructureType::BindImageMemoryDeviceGroupInfo;
	const void *    pNext                        = nullptr;
	uint32_t        deviceIndexCount             = 0;
	const uint32_t *pDeviceIndices               = nullptr;// len deviceIndexCount
	uint32_t        splitInstanceBindRegionCount = 0;
	const Rect2D *  pSplitInstanceBindRegions    = nullptr;// len splitInstanceBindRegionCount
	auto deviceIndices() -> impl_Struct::VecView<uint32_t, uint32_t>;
	auto splitInstanceBindRegions() -> impl_Struct::VecView<uint32_t, Rect2D>;
};
struct BlitImageInfo2 {
	StructureType                        sType          = StructureType::BlitImageInfo2;
	const void *                         pNext          = nullptr;
	impl_Struct::AssignableHandle<Image> srcImage;
	ImageLayout                          srcImageLayout = ImageLayout::Undefined;
	impl_Struct::AssignableHandle<Image> dstImage;
	ImageLayout                          dstImageLayout = ImageLayout::Undefined;
	uint32_t                             regionCount    = 0;
	const ImageBlit2 *                   pRegions       = nullptr;// len regionCount
	Filter                               filter         = Filter::Nearest;
	auto regions() -> impl_Struct::VecView<uint32_t, ImageBlit2>;
};
struct ClearAttachment {
	ImageAspectFlags aspectMask      = {};
	uint32_t         colorAttachment = 0;
	ClearValue       clearValue      = {};
};
struct ClearRect {
	Rect2D   rect           = {};
	uint32_t baseArrayLayer = 0;
	uint32_t layerCount     = 0;
};
struct ClusterAccelerationStructureInputInfoNV {
	StructureType                         sType                         = StructureType::ClusterAccelerationStructureInputInfoNV;
	void *                                pNext                         = nullptr;
	uint32_t                              maxAccelerationStructureCount = 0;
	BuildAccelerationStructureFlagsKHR    flags                         = {};
	ClusterAccelerationStructureOpTypeNV  opType                        = ClusterAccelerationStructureOpTypeNV::MoveObjects;
	ClusterAccelerationStructureOpModeNV  opMode                        = ClusterAccelerationStructureOpModeNV::ImplicitDestinations;
	ClusterAccelerationStructureOpInputNV opInput                       = {};
};
struct CommandBufferInheritanceDescriptorHeapInfoEXT {
	StructureType          sType                 = StructureType::CommandBufferInheritanceDescriptorHeapInfoEXT;
	const void *           pNext                 = nullptr;
	const BindHeapInfoEXT *pSamplerHeapBindInfo  = nullptr;
	const BindHeapInfoEXT *pResourceHeapBindInfo = nullptr;
};
struct CommandBufferInheritanceRenderPassTransformInfoQCOM {
	StructureType           sType      = StructureType::CommandBufferInheritanceRenderPassTransformInfoQCOM;
	const void *            pNext      = nullptr;
	SurfaceTransformBitsKHR transform  = SurfaceTransformBitsKHR::Identity;
	Rect2D                  renderArea = {};
};
struct CopyBufferToImageInfo2 {
	StructureType                         sType          = StructureType::CopyBufferToImageInfo2;
	const void *                          pNext          = nullptr;
	impl_Struct::AssignableHandle<Buffer> srcBuffer;
	impl_Struct::AssignableHandle<Image>  dstImage;
	ImageLayout                           dstImageLayout = ImageLayout::Undefined;
	uint32_t                              regionCount    = 0;
	const BufferImageCopy2 *              pRegions       = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, BufferImageCopy2>;
};
struct CopyDeviceMemoryImageInfoKHR {
	StructureType                        sType       = StructureType::CopyDeviceMemoryImageInfoKHR;
	const void *                         pNext       = nullptr;
	impl_Struct::AssignableHandle<Image> image;
	uint32_t                             regionCount = 0;
	const DeviceMemoryImageCopyKHR *     pRegions    = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, DeviceMemoryImageCopyKHR>;
};
struct CopyDeviceMemoryInfoKHR {
	StructureType              sType       = StructureType::CopyDeviceMemoryInfoKHR;
	const void *               pNext       = nullptr;
	uint32_t                   regionCount = 0;
	const DeviceMemoryCopyKHR *pRegions    = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, DeviceMemoryCopyKHR>;
};
struct CopyImageInfo2 {
	StructureType                        sType          = StructureType::CopyImageInfo2;
	const void *                         pNext          = nullptr;
	impl_Struct::AssignableHandle<Image> srcImage;
	ImageLayout                          srcImageLayout = ImageLayout::Undefined;
	impl_Struct::AssignableHandle<Image> dstImage;
	ImageLayout                          dstImageLayout = ImageLayout::Undefined;
	uint32_t                             regionCount    = 0;
	const ImageCopy2 *                   pRegions       = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, ImageCopy2>;
};
struct CopyImageToBufferInfo2 {
	StructureType                         sType          = StructureType::CopyImageToBufferInfo2;
	const void *                          pNext          = nullptr;
	impl_Struct::AssignableHandle<Image>  srcImage;
	ImageLayout                           srcImageLayout = ImageLayout::Undefined;
	impl_Struct::AssignableHandle<Buffer> dstBuffer;
	uint32_t                              regionCount    = 0;
	const BufferImageCopy2 *              pRegions       = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, BufferImageCopy2>;
};
struct CopyImageToImageInfo {
	StructureType                        sType          = StructureType::CopyImageToImageInfo;
	const void *                         pNext          = nullptr;
	HostImageCopyFlags                   flags          = {};
	impl_Struct::AssignableHandle<Image> srcImage;
	ImageLayout                          srcImageLayout = ImageLayout::Undefined;
	impl_Struct::AssignableHandle<Image> dstImage;
	ImageLayout                          dstImageLayout = ImageLayout::Undefined;
	uint32_t                             regionCount    = 0;
	const ImageCopy2 *                   pRegions       = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, ImageCopy2>;
};
struct CopyImageToMemoryInfo {
	StructureType                        sType          = StructureType::CopyImageToMemoryInfo;
	const void *                         pNext          = nullptr;
	HostImageCopyFlags                   flags          = {};
	impl_Struct::AssignableHandle<Image> srcImage;
	ImageLayout                          srcImageLayout = ImageLayout::Undefined;
	uint32_t                             regionCount    = 0;
	const ImageToMemoryCopy *            pRegions       = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, ImageToMemoryCopy>;
};
struct CopyMemoryToImageInfo {
	StructureType                        sType          = StructureType::CopyMemoryToImageInfo;
	const void *                         pNext          = nullptr;
	HostImageCopyFlags                   flags          = {};
	impl_Struct::AssignableHandle<Image> dstImage;
	ImageLayout                          dstImageLayout = ImageLayout::Undefined;
	uint32_t                             regionCount    = 0;
	const MemoryToImageCopy *            pRegions       = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, MemoryToImageCopy>;
};
struct DataGraphPipelineShaderModuleCreateInfoARM {
	StructureType                               sType               = StructureType::DataGraphPipelineShaderModuleCreateInfoARM;
	const void *                                pNext               = nullptr;
	impl_Struct::AssignableHandle<ShaderModule> module;
	impl_Struct::InOutString                    name;
	const SpecializationInfo *                  pSpecializationInfo = nullptr;
	uint32_t                                    constantCount       = 0;
	const DataGraphPipelineConstantARM *        pConstants          = nullptr;// len constantCount
	auto constants() -> impl_Struct::VecView<uint32_t, DataGraphPipelineConstantARM>;
};
struct DependencyInfo {
	StructureType               sType                    = StructureType::DependencyInfo;
	const void *                pNext                    = nullptr;
	DependencyFlags             dependencyFlags          = {};
	uint32_t                    memoryBarrierCount       = 0;
	const MemoryBarrier2 *      pMemoryBarriers          = nullptr;// len memoryBarrierCount
	uint32_t                    bufferMemoryBarrierCount = 0;
	const BufferMemoryBarrier2 *pBufferMemoryBarriers    = nullptr;// len bufferMemoryBarrierCount
	uint32_t                    imageMemoryBarrierCount  = 0;
	const ImageMemoryBarrier2 * pImageMemoryBarriers     = nullptr;// len imageMemoryBarrierCount
	auto memoryBarriers() -> impl_Struct::VecView<uint32_t, MemoryBarrier2>;
	auto bufferMemoryBarriers() -> impl_Struct::VecView<uint32_t, BufferMemoryBarrier2>;
	auto imageMemoryBarriers() -> impl_Struct::VecView<uint32_t, ImageMemoryBarrier2>;
};
struct DescriptorGetInfoEXT {
	StructureType     sType = StructureType::DescriptorGetInfoEXT;
	const void *      pNext = nullptr;
	DescriptorType    type  = DescriptorType::Sampler;
	DescriptorDataEXT data  = {};
};
union DescriptorMappingSourceDataEXT {
	DescriptorMappingSourceConstantOffsetEXT     constantOffset;
	DescriptorMappingSourcePushIndexEXT          pushIndex;
	DescriptorMappingSourceIndirectIndexEXT      indirectIndex;
	DescriptorMappingSourceIndirectIndexArrayEXT indirectIndexArray;
	DescriptorMappingSourceHeapDataEXT           heapData;
	uint32_t                                     pushDataOffset;
	uint32_t                                     pushAddressOffset;
	DescriptorMappingSourceIndirectAddressEXT    indirectAddress;
	DescriptorMappingSourceShaderRecordIndexEXT  shaderRecordIndex;
	uint32_t                                     shaderRecordDataOffset;
	uint32_t                                     shaderRecordAddressOffset;
};
struct DeviceGroupRenderPassBeginInfo {
	StructureType sType                 = StructureType::DeviceGroupRenderPassBeginInfo;
	const void *  pNext                 = nullptr;
	uint32_t      deviceMask            = 0;
	uint32_t      deviceRenderAreaCount = 0;
	const Rect2D *pDeviceRenderAreas    = nullptr;// len deviceRenderAreaCount
	auto deviceRenderAreas() -> impl_Struct::VecView<uint32_t, Rect2D>;
};
struct DeviceImageMemoryRequirements {
	StructureType          sType       = StructureType::DeviceImageMemoryRequirements;
	const void *           pNext       = nullptr;
	const ImageCreateInfo *pCreateInfo = nullptr;
	ImageAspectBits        planeAspect = ImageAspectBits::None;
};
struct DeviceImageSubresourceInfo {
	StructureType            sType        = StructureType::DeviceImageSubresourceInfo;
	const void *             pNext        = nullptr;
	const ImageCreateInfo *  pCreateInfo  = nullptr;
	const ImageSubresource2 *pSubresource = nullptr;
};
struct DeviceTensorMemoryRequirementsARM {
	StructureType              sType       = StructureType::DeviceTensorMemoryRequirementsARM;
	const void *               pNext       = nullptr;
	const TensorCreateInfoARM *pCreateInfo = nullptr;
};
struct DisplayModeCreateInfoKHR {
	StructureType             sType      = StructureType::DisplayModeCreateInfoKHR;
	const void *              pNext      = nullptr;
	DisplayModeCreateFlagsKHR flags      = {};
	DisplayModeParametersKHR  parameters = {};
};
struct DisplayModePropertiesKHR {
	impl_Struct::AssignableHandle<DisplayModeKHR> displayMode;
	DisplayModeParametersKHR                      parameters  = {};
};
struct DisplayPlaneCapabilities2KHR {
	StructureType               sType        = StructureType::DisplayPlaneCapabilities2KHR;
	void *                      pNext        = nullptr;
	DisplayPlaneCapabilitiesKHR capabilities = {};
};
struct DisplayPresentInfoKHR {
	StructureType sType      = StructureType::DisplayPresentInfoKHR;
	const void *  pNext      = nullptr;
	Rect2D        srcRect    = {};
	Rect2D        dstRect    = {};
	Bool32        persistent = Constants::False;
};
struct DisplayProperties2KHR {
	StructureType        sType             = StructureType::DisplayProperties2KHR;
	void *               pNext             = nullptr;
	DisplayPropertiesKHR displayProperties = {};
};
struct ExternalImageFormatPropertiesNV {
	ImageFormatProperties           imageFormatProperties         = {};
	ExternalMemoryFeatureFlagsNV    externalMemoryFeatures        = {};
	ExternalMemoryHandleTypeFlagsNV exportFromImportedHandleTypes = {};
	ExternalMemoryHandleTypeFlagsNV compatibleHandleTypes         = {};
};
struct GeometryNV {
	StructureType    sType        = StructureType::GeometryNV;
	const void *     pNext        = nullptr;
	GeometryTypeKHR  geometryType = GeometryTypeKHR::Triangles;
	GeometryDataNV   geometry     = {};
	GeometryFlagsKHR flags        = {};
};
struct ImageDescriptorInfoEXT {
	StructureType              sType  = StructureType::ImageDescriptorInfoEXT;
	const void *               pNext  = nullptr;
	const ImageViewCreateInfo *pView  = nullptr;
	ImageLayout                layout = ImageLayout::Undefined;
};
struct ImageFormatProperties2 {
	StructureType         sType                 = StructureType::ImageFormatProperties2;
	void *                pNext                 = nullptr;
	ImageFormatProperties imageFormatProperties = {};
};
union IndirectCommandsTokenDataEXT {
	const IndirectCommandsPushConstantTokenEXT *pPushConstant;
	const IndirectCommandsVertexBufferTokenEXT *pVertexBuffer;
	const IndirectCommandsIndexBufferTokenEXT * pIndexBuffer;
	const IndirectCommandsExecutionSetTokenEXT *pExecutionSet;
};
union IndirectExecutionSetInfoEXT {
	const IndirectExecutionSetPipelineInfoEXT *pPipelineInfo;
	const IndirectExecutionSetShaderInfoEXT *  pShaderInfo;
};
struct MemoryRangeBarriersInfoKHR {
	StructureType                sType                   = StructureType::MemoryRangeBarriersInfoKHR;
	const void *                 pNext                   = nullptr;
	uint32_t                     memoryRangeBarrierCount = 0;
	const MemoryRangeBarrierKHR *pMemoryRangeBarriers    = nullptr;// len memoryRangeBarrierCount
	auto memoryRangeBarriers() -> impl_Struct::VecView<uint32_t, MemoryRangeBarrierKHR>;
};
struct MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM {
	StructureType sType                  = StructureType::MultiviewPerViewRenderAreasRenderPassBeginInfoQCOM;
	const void *  pNext                  = nullptr;
	uint32_t      perViewRenderAreaCount = 0;
	const Rect2D *pPerViewRenderAreas    = nullptr;// len perViewRenderAreaCount
	auto perViewRenderAreas() -> impl_Struct::VecView<uint32_t, Rect2D>;
};
struct OpticalFlowExecuteInfoNV {
	StructureType             sType       = StructureType::OpticalFlowExecuteInfoNV;
	void *                    pNext       = nullptr;
	OpticalFlowExecuteFlagsNV flags       = {};
	uint32_t                  regionCount = 0;
	const Rect2D *            pRegions    = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, Rect2D>;
};
struct PastPresentationTimingPropertiesEXT {
	StructureType              sType                   = StructureType::PastPresentationTimingPropertiesEXT;
	void *                     pNext                   = nullptr;
	uint64_t                   timingPropertiesCounter = 0;
	uint64_t                   timeDomainsCounter      = 0;
	uint32_t                   presentationTimingCount = 0;
	PastPresentationTimingEXT *pPresentationTimings    = nullptr;// len presentationTimingCount
};
struct PhysicalDeviceMemoryProperties2 {
	StructureType                  sType            = StructureType::PhysicalDeviceMemoryProperties2;
	void *                         pNext            = nullptr;
	PhysicalDeviceMemoryProperties memoryProperties = {};
};
struct PhysicalDeviceProperties2 {
	StructureType            sType      = StructureType::PhysicalDeviceProperties2;
	void *                   pNext      = nullptr;
	PhysicalDeviceProperties properties = {};
};
struct PipelineBinaryCreateInfoKHR {
	StructureType                           sType               = StructureType::PipelineBinaryCreateInfoKHR;
	const void *                            pNext               = nullptr;
	const PipelineBinaryKeysAndDataKHR *    pKeysAndDataInfo    = nullptr;
	impl_Struct::AssignableHandle<Pipeline> pipeline;
	const PipelineCreateInfoKHR *           pPipelineCreateInfo = nullptr;
};
struct PipelineDiscardRectangleStateCreateInfoEXT {
	StructureType                               sType                 = StructureType::PipelineDiscardRectangleStateCreateInfoEXT;
	const void *                                pNext                 = nullptr;
	PipelineDiscardRectangleStateCreateFlagsEXT flags                 = {};
	DiscardRectangleModeEXT                     discardRectangleMode  = DiscardRectangleModeEXT::Inclusive;
	uint32_t                                    discardRectangleCount = 0;
	const Rect2D *                              pDiscardRectangles    = nullptr;// len discardRectangleCount
	auto discardRectangles() -> impl_Struct::VecView<uint32_t, Rect2D>;
};
struct PipelineSampleLocationsStateCreateInfoEXT {
	StructureType          sType                 = StructureType::PipelineSampleLocationsStateCreateInfoEXT;
	const void *           pNext                 = nullptr;
	Bool32                 sampleLocationsEnable = Constants::False;
	SampleLocationsInfoEXT sampleLocationsInfo   = {};
};
struct PipelineShaderStageCreateInfo {
	StructureType                               sType               = StructureType::PipelineShaderStageCreateInfo;
	const void *                                pNext               = nullptr;
	PipelineShaderStageCreateFlags              flags               = {};
	ShaderStageBits                             stage               = ShaderStageBits::Vertex;
	impl_Struct::AssignableHandle<ShaderModule> module;
	impl_Struct::InOutString                    name;
	const SpecializationInfo *                  pSpecializationInfo = nullptr;
};
struct PipelineViewportCoarseSampleOrderStateCreateInfoNV {
	StructureType                    sType                  = StructureType::PipelineViewportCoarseSampleOrderStateCreateInfoNV;
	const void *                     pNext                  = nullptr;
	CoarseSampleOrderTypeNV          sampleOrderType        = CoarseSampleOrderTypeNV::Default;
	uint32_t                         customSampleOrderCount = 0;
	const CoarseSampleOrderCustomNV *pCustomSampleOrders    = nullptr;// len customSampleOrderCount
	auto customSampleOrders() -> impl_Struct::VecView<uint32_t, CoarseSampleOrderCustomNV>;
};
struct PipelineViewportExclusiveScissorStateCreateInfoNV {
	StructureType sType                 = StructureType::PipelineViewportExclusiveScissorStateCreateInfoNV;
	const void *  pNext                 = nullptr;
	uint32_t      exclusiveScissorCount = 0;
	const Rect2D *pExclusiveScissors    = nullptr;// len exclusiveScissorCount
	auto exclusiveScissors() -> impl_Struct::VecView<uint32_t, Rect2D>;
};
struct PipelineViewportStateCreateInfo {
	StructureType                    sType         = StructureType::PipelineViewportStateCreateInfo;
	const void *                     pNext         = nullptr;
	PipelineViewportStateCreateFlags flags         = {};
	uint32_t                         viewportCount = 0;
	const Viewport *                 pViewports    = nullptr;// len viewportCount
	uint32_t                         scissorCount  = 0;
	const Rect2D *                   pScissors     = nullptr;// len scissorCount
	auto viewports() -> impl_Struct::VecView<uint32_t, Viewport>;
	auto scissors() -> impl_Struct::VecView<uint32_t, Rect2D>;
};
struct PresentRegionKHR {
	uint32_t            rectangleCount = 0;
	const RectLayerKHR *pRectangles    = nullptr;// len rectangleCount
	auto rectangles() -> impl_Struct::VecView<uint32_t, RectLayerKHR>;
};
struct PushDescriptorSetInfo {
	StructureType                                 sType                = StructureType::PushDescriptorSetInfo;
	const void *                                  pNext                = nullptr;
	ShaderStageFlags                              stageFlags           = {};
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	uint32_t                                      set                  = 0;
	uint32_t                                      descriptorWriteCount = 0;
	const WriteDescriptorSet *                    pDescriptorWrites    = nullptr;// len descriptorWriteCount
	auto descriptorWrites() -> impl_Struct::VecView<uint32_t, WriteDescriptorSet>;
};
struct QueueFamilyProperties2 {
	StructureType         sType                 = StructureType::QueueFamilyProperties2;
	void *                pNext                 = nullptr;
	QueueFamilyProperties queueFamilyProperties = {};
};
struct RenderPassBeginInfo {
	StructureType                              sType           = StructureType::RenderPassBeginInfo;
	const void *                               pNext           = nullptr;
	impl_Struct::AssignableHandle<RenderPass>  renderPass;
	impl_Struct::AssignableHandle<Framebuffer> framebuffer;
	Rect2D                                     renderArea      = {};
	uint32_t                                   clearValueCount = 0;
	const ClearValue *                         pClearValues    = nullptr;// len clearValueCount
	auto clearValues() -> impl_Struct::VecView<uint32_t, ClearValue>;
};
struct RenderPassCreateInfo {
	StructureType                sType           = StructureType::RenderPassCreateInfo;
	const void *                 pNext           = nullptr;
	RenderPassCreateFlags        flags           = {};
	uint32_t                     attachmentCount = 0;
	const AttachmentDescription *pAttachments    = nullptr;// len attachmentCount
	uint32_t                     subpassCount    = 0;
	const SubpassDescription *   pSubpasses      = nullptr;// len subpassCount
	uint32_t                     dependencyCount = 0;
	const SubpassDependency *    pDependencies   = nullptr;// len dependencyCount
	auto attachments() -> impl_Struct::VecView<uint32_t, AttachmentDescription>;
	auto subpasses() -> impl_Struct::VecView<uint32_t, SubpassDescription>;
	auto dependencies() -> impl_Struct::VecView<uint32_t, SubpassDependency>;
};
struct RenderPassCreateInfo2 {
	StructureType                 sType                   = StructureType::RenderPassCreateInfo2;
	const void *                  pNext                   = nullptr;
	RenderPassCreateFlags         flags                   = {};
	uint32_t                      attachmentCount         = 0;
	const AttachmentDescription2 *pAttachments            = nullptr;// len attachmentCount
	uint32_t                      subpassCount            = 0;
	const SubpassDescription2 *   pSubpasses              = nullptr;// len subpassCount
	uint32_t                      dependencyCount         = 0;
	const SubpassDependency2 *    pDependencies           = nullptr;// len dependencyCount
	uint32_t                      correlatedViewMaskCount = 0;
	const uint32_t *              pCorrelatedViewMasks    = nullptr;// len correlatedViewMaskCount
	auto attachments() -> impl_Struct::VecView<uint32_t, AttachmentDescription2>;
	auto subpasses() -> impl_Struct::VecView<uint32_t, SubpassDescription2>;
	auto dependencies() -> impl_Struct::VecView<uint32_t, SubpassDependency2>;
	auto correlatedViewMasks() -> impl_Struct::VecView<uint32_t, uint32_t>;
};
struct RenderPassStripeInfoARM {
	StructureType sType      = StructureType::RenderPassStripeInfoARM;
	const void *  pNext      = nullptr;
	Rect2D        stripeArea = {};
};
struct RenderingAttachmentInfo {
	StructureType                            sType              = StructureType::RenderingAttachmentInfo;
	const void *                             pNext              = nullptr;
	impl_Struct::AssignableHandle<ImageView> imageView;
	ImageLayout                              imageLayout        = ImageLayout::Undefined;
	ResolveModeBits                          resolveMode        = ResolveModeBits::None;
	impl_Struct::AssignableHandle<ImageView> resolveImageView;
	ImageLayout                              resolveImageLayout = ImageLayout::Undefined;
	AttachmentLoadOp                         loadOp             = AttachmentLoadOp::Load;
	AttachmentStoreOp                        storeOp            = AttachmentStoreOp::Store;
	ClearValue                               clearValue         = {};
};
struct ResolveImageInfo2 {
	StructureType                        sType          = StructureType::ResolveImageInfo2;
	const void *                         pNext          = nullptr;
	impl_Struct::AssignableHandle<Image> srcImage;
	ImageLayout                          srcImageLayout = ImageLayout::Undefined;
	impl_Struct::AssignableHandle<Image> dstImage;
	ImageLayout                          dstImageLayout = ImageLayout::Undefined;
	uint32_t                             regionCount    = 0;
	const ImageResolve2 *                pRegions       = nullptr;// len regionCount
	auto regions() -> impl_Struct::VecView<uint32_t, ImageResolve2>;
};
struct ShaderCreateInfoEXT {
	StructureType                                             sType                  = StructureType::ShaderCreateInfoEXT;
	const void *                                              pNext                  = nullptr;
	ShaderCreateFlagsEXT                                      flags                  = {};
	ShaderStageBits                                           stage                  = ShaderStageBits::Vertex;
	ShaderStageFlags                                          nextStage              = {};
	ShaderCodeTypeEXT                                         codeType               = ShaderCodeTypeEXT::Binary;
	size_t                                                    codeSize               = 0;
	const void *                                              pCode                  = nullptr;// len codeSize
	impl_Struct::InOutString                                  name;
	uint32_t                                                  setLayoutCount         = 0;
	const impl_Struct::AssignableHandle<DescriptorSetLayout> *pSetLayouts            = nullptr;// len setLayoutCount
	uint32_t                                                  pushConstantRangeCount = 0;
	const PushConstantRange *                                 pPushConstantRanges    = nullptr;// len pushConstantRangeCount
	const SpecializationInfo *                                pSpecializationInfo    = nullptr;
	auto setLayouts() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<DescriptorSetLayout>>;
	auto pushConstantRanges() -> impl_Struct::VecView<uint32_t, PushConstantRange>;
};
struct SparseImageFormatProperties2 {
	StructureType               sType      = StructureType::SparseImageFormatProperties2;
	void *                      pNext      = nullptr;
	SparseImageFormatProperties properties = {};
};
struct SparseImageMemoryBindInfo {
	impl_Struct::AssignableHandle<Image> image;
	uint32_t                             bindCount = 0;
	const SparseImageMemoryBind *        pBinds    = nullptr;// len bindCount
	auto binds() -> impl_Struct::VecView<uint32_t, SparseImageMemoryBind>;
};
struct SparseImageMemoryRequirements {
	SparseImageFormatProperties formatProperties     = {};
	uint32_t                    imageMipTailFirstLod = 0;
	DeviceSize                  imageMipTailSize     = 0;
	DeviceSize                  imageMipTailOffset   = 0;
	DeviceSize                  imageMipTailStride   = 0;
};
struct SubpassSampleLocationsEXT {
	uint32_t               subpassIndex        = 0;
	SampleLocationsInfoEXT sampleLocationsInfo = {};
};
struct SurfaceCapabilities2KHR {
	StructureType          sType               = StructureType::SurfaceCapabilities2KHR;
	void *                 pNext               = nullptr;
	SurfaceCapabilitiesKHR surfaceCapabilities = {};
};
struct VideoReferenceSlotInfoKHR {
	StructureType                      sType            = StructureType::VideoReferenceSlotInfoKHR;
	const void *                       pNext            = nullptr;
	int32_t                            slotIndex        = 0;
	const VideoPictureResourceInfoKHR *pPictureResource = nullptr;
};
#ifdef VK_USE_PLATFORM_FUCHSIA
	struct ImageFormatConstraintsInfoFUCHSIA {
		StructureType                      sType                  = StructureType::ImageFormatConstraintsInfoFUCHSIA;
		const void *                       pNext                  = nullptr;
		ImageCreateInfo                    imageCreateInfo        = {};
		FormatFeatureFlags                 requiredFormatFeatures = {};
		ImageFormatConstraintsFlagsFUCHSIA flags                  = {};
		uint64_t                           sysmemPixelFormat      = 0;
		uint32_t                           colorSpaceCount        = 0;
		const SysmemColorSpaceFUCHSIA *    pColorSpaces           = nullptr;// len colorSpaceCount
		auto colorSpaces() -> impl_Struct::VecView<uint32_t, SysmemColorSpaceFUCHSIA>;
	};
#endif // VK_USE_PLATFORM_FUCHSIA
struct AccelerationStructureGeometryKHR {
	StructureType                        sType        = StructureType::AccelerationStructureGeometryKHR;
	const void *                         pNext        = nullptr;
	GeometryTypeKHR                      geometryType = GeometryTypeKHR::Triangles;
	AccelerationStructureGeometryDataKHR geometry     = {};
	GeometryFlagsKHR                     flags        = {};
};
struct AccelerationStructureInfoNV {
	StructureType                      sType         = StructureType::AccelerationStructureInfoNV;
	const void *                       pNext         = nullptr;
	AccelerationStructureTypeKHR       type          = AccelerationStructureTypeKHR::TopLevel;
	BuildAccelerationStructureFlagsKHR flags         = {};
	uint32_t                           instanceCount = 0;
	uint32_t                           geometryCount = 0;
	const GeometryNV *                 pGeometries   = nullptr;// len geometryCount
	auto geometries() -> impl_Struct::VecView<uint32_t, GeometryNV>;
};
struct AccelerationStructureMotionInstanceNV {
	AccelerationStructureMotionInstanceTypeNV  type  = AccelerationStructureMotionInstanceTypeNV::Static;
	AccelerationStructureMotionInstanceFlagsNV flags = {};
	AccelerationStructureMotionInstanceDataNV  data  = {};
};
struct BindSparseInfo {
	StructureType                                   sType                = StructureType::BindSparseInfo;
	const void *                                    pNext                = nullptr;
	uint32_t                                        waitSemaphoreCount   = 0;
	const impl_Struct::AssignableHandle<Semaphore> *pWaitSemaphores      = nullptr;// len waitSemaphoreCount
	uint32_t                                        bufferBindCount      = 0;
	const SparseBufferMemoryBindInfo *              pBufferBinds         = nullptr;// len bufferBindCount
	uint32_t                                        imageOpaqueBindCount = 0;
	const SparseImageOpaqueMemoryBindInfo *         pImageOpaqueBinds    = nullptr;// len imageOpaqueBindCount
	uint32_t                                        imageBindCount       = 0;
	const SparseImageMemoryBindInfo *               pImageBinds          = nullptr;// len imageBindCount
	uint32_t                                        signalSemaphoreCount = 0;
	const impl_Struct::AssignableHandle<Semaphore> *pSignalSemaphores    = nullptr;// len signalSemaphoreCount
	auto waitSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>>;
	auto bufferBinds() -> impl_Struct::VecView<uint32_t, SparseBufferMemoryBindInfo>;
	auto imageOpaqueBinds() -> impl_Struct::VecView<uint32_t, SparseImageOpaqueMemoryBindInfo>;
	auto imageBinds() -> impl_Struct::VecView<uint32_t, SparseImageMemoryBindInfo>;
	auto signalSemaphores() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Semaphore>>;
};
struct ClusterAccelerationStructureCommandsInfoNV {
	StructureType                                        sType                  = StructureType::ClusterAccelerationStructureCommandsInfoNV;
	void *                                               pNext                  = nullptr;
	ClusterAccelerationStructureInputInfoNV              input                  = {};
	DeviceAddress                                        dstImplicitData        = 0;
	DeviceAddress                                        scratchData            = 0;
	StridedDeviceAddressRegionKHR                        dstAddressesArray      = {};
	StridedDeviceAddressRegionKHR                        dstSizesArray          = {};
	StridedDeviceAddressRegionKHR                        srcInfosArray          = {};
	DeviceAddress                                        srcInfosCount          = 0;
	ClusterAccelerationStructureAddressResolutionFlagsNV addressResolutionFlags = {};
};
struct ComputePipelineCreateInfo {
	StructureType                                 sType              = StructureType::ComputePipelineCreateInfo;
	const void *                                  pNext              = nullptr;
	PipelineCreateFlags                           flags              = {};
	PipelineShaderStageCreateInfo                 stage              = {};
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	impl_Struct::AssignableHandle<Pipeline>       basePipelineHandle;
	int32_t                                       basePipelineIndex  = 0;
};
struct DescriptorSetAndBindingMappingEXT {
	StructureType                  sType         = StructureType::DescriptorSetAndBindingMappingEXT;
	const void *                   pNext         = nullptr;
	uint32_t                       descriptorSet = 0;
	uint32_t                       firstBinding  = 0;
	uint32_t                       bindingCount  = 0;
	SpirvResourceTypeFlagsEXT      resourceMask  = {};
	DescriptorMappingSourceEXT     source        = DescriptorMappingSourceEXT::HeapWithConstantOffset;
	DescriptorMappingSourceDataEXT sourceData    = {};
};
struct DisplayModeProperties2KHR {
	StructureType            sType                 = StructureType::DisplayModeProperties2KHR;
	void *                   pNext                 = nullptr;
	DisplayModePropertiesKHR displayModeProperties = {};
};
struct GraphicsPipelineCreateInfo {
	StructureType                                 sType               = StructureType::GraphicsPipelineCreateInfo;
	const void *                                  pNext               = nullptr;
	PipelineCreateFlags                           flags               = {};
	uint32_t                                      stageCount          = 0;
	const PipelineShaderStageCreateInfo *         pStages             = nullptr;// len stageCount
	const PipelineVertexInputStateCreateInfo *    pVertexInputState   = nullptr;
	const PipelineInputAssemblyStateCreateInfo *  pInputAssemblyState = nullptr;
	const PipelineTessellationStateCreateInfo *   pTessellationState  = nullptr;
	const PipelineViewportStateCreateInfo *       pViewportState      = nullptr;
	const PipelineRasterizationStateCreateInfo *  pRasterizationState = nullptr;
	const PipelineMultisampleStateCreateInfo *    pMultisampleState   = nullptr;
	const PipelineDepthStencilStateCreateInfo *   pDepthStencilState  = nullptr;
	const PipelineColorBlendStateCreateInfo *     pColorBlendState    = nullptr;
	const PipelineDynamicStateCreateInfo *        pDynamicState       = nullptr;
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	impl_Struct::AssignableHandle<RenderPass>     renderPass;
	uint32_t                                      subpass             = 0;
	impl_Struct::AssignableHandle<Pipeline>       basePipelineHandle;
	int32_t                                       basePipelineIndex   = 0;
	auto stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo>;
};
struct GraphicsShaderGroupCreateInfoNV {
	StructureType                              sType              = StructureType::GraphicsShaderGroupCreateInfoNV;
	const void *                               pNext              = nullptr;
	uint32_t                                   stageCount         = 0;
	const PipelineShaderStageCreateInfo *      pStages            = nullptr;// len stageCount
	const PipelineVertexInputStateCreateInfo * pVertexInputState  = nullptr;
	const PipelineTessellationStateCreateInfo *pTessellationState = nullptr;
	auto stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo>;
};
struct IndirectCommandsLayoutTokenEXT {
	StructureType                sType  = StructureType::IndirectCommandsLayoutTokenEXT;
	const void *                 pNext  = nullptr;
	IndirectCommandsTokenTypeEXT type   = IndirectCommandsTokenTypeEXT::ExecutionSet;
	IndirectCommandsTokenDataEXT data   = {};
	uint32_t                     offset = 0;
};
struct IndirectExecutionSetCreateInfoEXT {
	StructureType                   sType = StructureType::IndirectExecutionSetCreateInfoEXT;
	const void *                    pNext = nullptr;
	IndirectExecutionSetInfoTypeEXT type  = IndirectExecutionSetInfoTypeEXT::Pipelines;
	IndirectExecutionSetInfoEXT     info  = {};
};
struct PhysicalDeviceLayeredApiVulkanPropertiesKHR {
	StructureType             sType      = StructureType::PhysicalDeviceLayeredApiVulkanPropertiesKHR;
	void *                    pNext      = nullptr;
	PhysicalDeviceProperties2 properties = {};
};
struct PresentRegionsKHR {
	StructureType           sType          = StructureType::PresentRegionsKHR;
	const void *            pNext          = nullptr;
	uint32_t                swapchainCount = 0;
	const PresentRegionKHR *pRegions       = nullptr;// len swapchainCount
	auto regions() -> impl_Struct::VecView<uint32_t, PresentRegionKHR>;
};
struct RayTracingPipelineCreateInfoKHR {
	StructureType                                   sType                        = StructureType::RayTracingPipelineCreateInfoKHR;
	const void *                                    pNext                        = nullptr;
	PipelineCreateFlags                             flags                        = {};
	uint32_t                                        stageCount                   = 0;
	const PipelineShaderStageCreateInfo *           pStages                      = nullptr;// len stageCount
	uint32_t                                        groupCount                   = 0;
	const RayTracingShaderGroupCreateInfoKHR *      pGroups                      = nullptr;// len groupCount
	uint32_t                                        maxPipelineRayRecursionDepth = 0;
	const PipelineLibraryCreateInfoKHR *            pLibraryInfo                 = nullptr;
	const RayTracingPipelineInterfaceCreateInfoKHR *pLibraryInterface            = nullptr;
	const PipelineDynamicStateCreateInfo *          pDynamicState                = nullptr;
	impl_Struct::AssignableHandle<PipelineLayout>   layout;
	impl_Struct::AssignableHandle<Pipeline>         basePipelineHandle;
	int32_t                                         basePipelineIndex            = 0;
	auto stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo>;
	auto groups() -> impl_Struct::VecView<uint32_t, RayTracingShaderGroupCreateInfoKHR>;
};
struct RayTracingPipelineCreateInfoNV {
	StructureType                                 sType              = StructureType::RayTracingPipelineCreateInfoNV;
	const void *                                  pNext              = nullptr;
	PipelineCreateFlags                           flags              = {};
	uint32_t                                      stageCount         = 0;
	const PipelineShaderStageCreateInfo *         pStages            = nullptr;// len stageCount
	uint32_t                                      groupCount         = 0;
	const RayTracingShaderGroupCreateInfoNV *     pGroups            = nullptr;// len groupCount
	uint32_t                                      maxRecursionDepth  = 0;
	impl_Struct::AssignableHandle<PipelineLayout> layout;
	impl_Struct::AssignableHandle<Pipeline>       basePipelineHandle;
	int32_t                                       basePipelineIndex  = 0;
	auto stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo>;
	auto groups() -> impl_Struct::VecView<uint32_t, RayTracingShaderGroupCreateInfoNV>;
};
struct RenderPassSampleLocationsBeginInfoEXT {
	StructureType                       sType                                 = StructureType::RenderPassSampleLocationsBeginInfoEXT;
	const void *                        pNext                                 = nullptr;
	uint32_t                            attachmentInitialSampleLocationsCount = 0;
	const AttachmentSampleLocationsEXT *pAttachmentInitialSampleLocations     = nullptr;// len attachmentInitialSampleLocationsCount
	uint32_t                            postSubpassSampleLocationsCount       = 0;
	const SubpassSampleLocationsEXT *   pPostSubpassSampleLocations           = nullptr;// len postSubpassSampleLocationsCount
	auto attachmentInitialSampleLocations() -> impl_Struct::VecView<uint32_t, AttachmentSampleLocationsEXT>;
	auto postSubpassSampleLocations() -> impl_Struct::VecView<uint32_t, SubpassSampleLocationsEXT>;
};
struct RenderPassStripeBeginInfoARM {
	StructureType                  sType           = StructureType::RenderPassStripeBeginInfoARM;
	const void *                   pNext           = nullptr;
	uint32_t                       stripeInfoCount = 0;
	const RenderPassStripeInfoARM *pStripeInfos    = nullptr;// len stripeInfoCount
	auto stripeInfos() -> impl_Struct::VecView<uint32_t, RenderPassStripeInfoARM>;
};
struct RenderingInfo {
	StructureType                  sType                = StructureType::RenderingInfo;
	const void *                   pNext                = nullptr;
	RenderingFlags                 flags                = {};
	Rect2D                         renderArea           = {};
	uint32_t                       layerCount           = 0;
	uint32_t                       viewMask             = 0;
	uint32_t                       colorAttachmentCount = 0;
	const RenderingAttachmentInfo *pColorAttachments    = nullptr;// len colorAttachmentCount
	const RenderingAttachmentInfo *pDepthAttachment     = nullptr;
	const RenderingAttachmentInfo *pStencilAttachment   = nullptr;
	auto colorAttachments() -> impl_Struct::VecView<uint32_t, RenderingAttachmentInfo>;
};
union ResourceDescriptorDataEXT {
	const ImageDescriptorInfoEXT *      pImage;
	const TexelBufferDescriptorInfoEXT *pTexelBuffer;
	const DeviceAddressRangeKHR *       pAddressRange;
	const TensorViewCreateInfoARM *     pTensorARM;
};
struct SparseImageMemoryRequirements2 {
	StructureType                 sType              = StructureType::SparseImageMemoryRequirements2;
	void *                        pNext              = nullptr;
	SparseImageMemoryRequirements memoryRequirements = {};
};
struct VideoBeginCodingInfoKHR {
	StructureType                                            sType                  = StructureType::VideoBeginCodingInfoKHR;
	const void *                                             pNext                  = nullptr;
	VideoBeginCodingFlagsKHR                                 flags                  = {};
	impl_Struct::AssignableHandle<VideoSessionKHR>           videoSession;
	impl_Struct::AssignableHandle<VideoSessionParametersKHR> videoSessionParameters;
	uint32_t                                                 referenceSlotCount     = 0;
	const VideoReferenceSlotInfoKHR *                        pReferenceSlots        = nullptr;// len referenceSlotCount
	auto referenceSlots() -> impl_Struct::VecView<uint32_t, VideoReferenceSlotInfoKHR>;
};
struct VideoDecodeInfoKHR {
	StructureType                         sType               = StructureType::VideoDecodeInfoKHR;
	const void *                          pNext               = nullptr;
	VideoDecodeFlagsKHR                   flags               = {};
	impl_Struct::AssignableHandle<Buffer> srcBuffer;
	DeviceSize                            srcBufferOffset     = 0;
	DeviceSize                            srcBufferRange      = 0;
	VideoPictureResourceInfoKHR           dstPictureResource  = {};
	const VideoReferenceSlotInfoKHR *     pSetupReferenceSlot = nullptr;
	uint32_t                              referenceSlotCount  = 0;
	const VideoReferenceSlotInfoKHR *     pReferenceSlots     = nullptr;// len referenceSlotCount
	auto referenceSlots() -> impl_Struct::VecView<uint32_t, VideoReferenceSlotInfoKHR>;
};
struct VideoEncodeInfoKHR {
	StructureType                         sType                           = StructureType::VideoEncodeInfoKHR;
	const void *                          pNext                           = nullptr;
	VideoEncodeFlagsKHR                   flags                           = {};
	impl_Struct::AssignableHandle<Buffer> dstBuffer;
	DeviceSize                            dstBufferOffset                 = 0;
	DeviceSize                            dstBufferRange                  = 0;
	VideoPictureResourceInfoKHR           srcPictureResource              = {};
	const VideoReferenceSlotInfoKHR *     pSetupReferenceSlot             = nullptr;
	uint32_t                              referenceSlotCount              = 0;
	const VideoReferenceSlotInfoKHR *     pReferenceSlots                 = nullptr;// len referenceSlotCount
	uint32_t                              precedingExternallyEncodedBytes = 0;
	auto referenceSlots() -> impl_Struct::VecView<uint32_t, VideoReferenceSlotInfoKHR>;
};
#ifdef VK_ENABLE_BETA_EXTENSIONS
	struct ExecutionGraphPipelineCreateInfoAMDX {
		StructureType                                 sType              = StructureType::ExecutionGraphPipelineCreateInfoAMDX;
		const void *                                  pNext              = nullptr;
		PipelineCreateFlags                           flags              = {};
		uint32_t                                      stageCount         = 0;
		const PipelineShaderStageCreateInfo *         pStages            = nullptr;// len stageCount
		const PipelineLibraryCreateInfoKHR *          pLibraryInfo       = nullptr;
		impl_Struct::AssignableHandle<PipelineLayout> layout;
		impl_Struct::AssignableHandle<Pipeline>       basePipelineHandle;
		int32_t                                       basePipelineIndex  = 0;
		auto stages() -> impl_Struct::VecView<uint32_t, PipelineShaderStageCreateInfo>;
	};
#endif // VK_ENABLE_BETA_EXTENSIONS
#ifdef VK_USE_PLATFORM_FUCHSIA
	struct ImageConstraintsInfoFUCHSIA {
		StructureType                            sType                       = StructureType::ImageConstraintsInfoFUCHSIA;
		const void *                             pNext                       = nullptr;
		uint32_t                                 formatConstraintsCount      = 0;
		const ImageFormatConstraintsInfoFUCHSIA *pFormatConstraints          = nullptr;// len formatConstraintsCount
		BufferCollectionConstraintsInfoFUCHSIA   bufferCollectionConstraints = {};
		ImageConstraintsInfoFlagsFUCHSIA         flags                       = {};
		auto formatConstraints() -> impl_Struct::VecView<uint32_t, ImageFormatConstraintsInfoFUCHSIA>;
	};
#endif // VK_USE_PLATFORM_FUCHSIA
struct AccelerationStructureBuildGeometryInfoKHR {
	StructureType                                           sType                    = StructureType::AccelerationStructureBuildGeometryInfoKHR;
	const void *                                            pNext                    = nullptr;
	AccelerationStructureTypeKHR                            type                     = AccelerationStructureTypeKHR::TopLevel;
	BuildAccelerationStructureFlagsKHR                      flags                    = {};
	BuildAccelerationStructureModeKHR                       mode                     = BuildAccelerationStructureModeKHR::Build;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> srcAccelerationStructure;
	impl_Struct::AssignableHandle<AccelerationStructureKHR> dstAccelerationStructure;
	uint32_t                                                geometryCount            = 0;
	const AccelerationStructureGeometryKHR *                pGeometries              = nullptr;// len geometryCount
	const AccelerationStructureGeometryKHR * const*         ppGeometries             = nullptr;// len geometryCount,1
	DeviceOrHostAddressKHR                                  scratchData              = {};
	auto geometries() -> impl_Struct::VecView<uint32_t, AccelerationStructureGeometryKHR>;
};
struct AccelerationStructureCreateInfoNV {
	StructureType               sType         = StructureType::AccelerationStructureCreateInfoNV;
	const void *                pNext         = nullptr;
	DeviceSize                  compactedSize = 0;
	AccelerationStructureInfoNV info          = {};
};
struct GraphicsPipelineShaderGroupsCreateInfoNV {
	StructureType                                  sType         = StructureType::GraphicsPipelineShaderGroupsCreateInfoNV;
	const void *                                   pNext         = nullptr;
	uint32_t                                       groupCount    = 0;
	const GraphicsShaderGroupCreateInfoNV *        pGroups       = nullptr;// len groupCount
	uint32_t                                       pipelineCount = 0;
	const impl_Struct::AssignableHandle<Pipeline> *pPipelines    = nullptr;// len pipelineCount
	auto groups() -> impl_Struct::VecView<uint32_t, GraphicsShaderGroupCreateInfoNV>;
	auto pipelines() -> impl_Struct::VecView<uint32_t, impl_Struct::AssignableHandle<Pipeline>>;
};
struct IndirectCommandsLayoutCreateInfoEXT {
	StructureType                                 sType          = StructureType::IndirectCommandsLayoutCreateInfoEXT;
	const void *                                  pNext          = nullptr;
	IndirectCommandsLayoutUsageFlagsEXT           flags          = {};
	ShaderStageFlags                              shaderStages   = {};
	uint32_t                                      indirectStride = 0;
	impl_Struct::AssignableHandle<PipelineLayout> pipelineLayout;
	uint32_t                                      tokenCount     = 0;
	const IndirectCommandsLayoutTokenEXT *        pTokens        = nullptr;// len tokenCount
	auto tokens() -> impl_Struct::VecView<uint32_t, IndirectCommandsLayoutTokenEXT>;
};
struct ResourceDescriptorInfoEXT {
	StructureType             sType = StructureType::ResourceDescriptorInfoEXT;
	const void *              pNext = nullptr;
	DescriptorType            type  = DescriptorType::Sampler;
	ResourceDescriptorDataEXT data  = {};
};
struct ShaderDescriptorSetAndBindingMappingInfoEXT {
	StructureType                            sType        = StructureType::ShaderDescriptorSetAndBindingMappingInfoEXT;
	const void *                             pNext        = nullptr;
	uint32_t                                 mappingCount = 0;
	const DescriptorSetAndBindingMappingEXT *pMappings    = nullptr;// len mappingCount
	auto mappings() -> impl_Struct::VecView<uint32_t, DescriptorSetAndBindingMappingEXT>;
};
// NOLINTEND(cppcoreguidelines-non-private-member-variables-in-classes, misc-non-private-member-variables-in-classes, cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers, cppcoreguidelines-pro-type-member-init, bugprone-invalid-enum-default-initialization)
} // namespace VkBindings
