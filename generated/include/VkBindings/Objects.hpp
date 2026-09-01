#pragma once

#include "VkBindings/BaseTypes.hpp"
#include "VkBindings/Bits.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Flags.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/Structs.hpp"
#include "VkBindings/private/ObjectTemplatesIntreface.hpp"
#include "VkBindings/private/StructTemplates/ArrayProxyInterface.hpp"
#include "VkBindings/private/StructTemplates/AssignableHandleInterface.hpp"
#include "VkBindings/private/StructTemplates/Pod.hpp"

#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <expected>
#include <tuple>
#include <vector>

namespace VkBindings {
struct CommandBuffer : public impl_Objects::Object<Handle::CommandBuffer> {
	using Object::Object;
	CommandBuffer() = default;
	[[nodiscard]] auto begin(const CommandBufferBeginInfo &beginInfo) const -> Result;
	void beginConditionalRendering2EXT(const ConditionalRenderingBeginInfo2EXT &conditionalRenderingBegin) const;
	
	[[deprecated("supersededby: beginConditionalRendering2EXT")]]
	void beginConditionalRenderingEXT(const ConditionalRenderingBeginInfoEXT &conditionalRenderingBegin) const;
	void beginCustomResolveEXT(const BeginCustomResolveInfoEXT *pBeginCustomResolveInfo = nullptr) const;
	void beginDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const;
	[[nodiscard]] auto beginGpaSampleAMD(const GpaSessionAMD &gpaSession, const GpaSampleBeginInfoAMD &gpaSampleBeginInfo, uint32_t *pSampleID) const -> Result;
	[[nodiscard]] auto beginGpaSessionAMD(const GpaSessionAMD &gpaSession) const -> Result;
	void beginPerTileExecutionQCOM(const PerTileBeginInfoQCOM &perTileBeginInfo) const;
	void beginQuery(const QueryPool &queryPool, uint32_t query, QueryControlFlags flags = {}) const;
	void beginQueryIndexedEXT(const QueryPool &queryPool, uint32_t query, QueryControlFlags flags, uint32_t index) const;
	
	[[deprecated("supersededby: beginRenderPass2")]]
	void beginRenderPass(const RenderPassBeginInfo &renderPassBegin, SubpassContents contents) const;
	void beginRenderPass2(const RenderPassBeginInfo &renderPassBegin, const SubpassBeginInfo &subpassBeginInfo) const;
	void beginRendering(const RenderingInfo &renderingInfo) const;
	void beginShaderInstrumentationARM(const ShaderInstrumentationARM &instrumentation) const;
	void beginTransformFeedback2EXT(uint32_t firstCounterRange, const impl_Struct::ArrayProxy<BindTransformFeedbackBuffer2InfoEXT> &counterInfos = nullptr) const;
	
	[[deprecated("supersededby: beginTransformFeedback2EXT")]]
	void beginTransformFeedbackEXT(uint32_t firstCounterBuffer, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &counterBuffers, const impl_Struct::ArrayProxy<DeviceSize> &counterBufferOffsets = nullptr) const;
	void beginVideoCodingKHR(const VideoBeginCodingInfoKHR &beginInfo) const;
	void bindDescriptorBufferEmbeddedSamplers2EXT(const BindDescriptorBufferEmbeddedSamplersInfoEXT &bindDescriptorBufferEmbeddedSamplersInfo) const;
	void bindDescriptorBufferEmbeddedSamplersEXT(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t set) const;
	void bindDescriptorBuffersEXT(const impl_Struct::ArrayProxy<DescriptorBufferBindingInfoEXT> &bindingInfos) const;
	void bindDescriptorSets(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t firstSet, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<DescriptorSet>> &descriptorSets, const impl_Struct::ArrayProxy<uint32_t> &dynamicOffsets) const;
	void bindDescriptorSets2(const BindDescriptorSetsInfo &bindDescriptorSetsInfo) const;
	void bindIndexBuffer(const Buffer &buffer, DeviceSize offset, IndexType indexType) const;
	
	[[deprecated("supersededby: bindIndexBuffer3KHR")]]
	void bindIndexBuffer2(const Buffer &buffer, DeviceSize offset, DeviceSize size, IndexType indexType) const;
	void bindIndexBuffer3KHR(const BindIndexBuffer3InfoKHR &info) const;
	void bindInvocationMaskHUAWEI(const ImageView &imageView, ImageLayout imageLayout) const;
	void bindPipeline(PipelineBindPoint pipelineBindPoint, const Pipeline &pipeline) const;
	void bindPipelineShaderGroupNV(PipelineBindPoint pipelineBindPoint, const Pipeline &pipeline, uint32_t groupIndex) const;
	void bindResourceHeapEXT(const BindHeapInfoEXT &bindInfo) const;
	void bindSamplerHeapEXT(const BindHeapInfoEXT &bindInfo) const;
	void bindShadersEXT(const impl_Struct::ArrayProxy<ShaderStageBits> &stages, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<ShaderEXT>> &shaders = nullptr) const;
	void bindShadingRateImageNV(const ImageView &imageView, ImageLayout imageLayout) const;
	void bindTileMemoryQCOM(const TileMemoryBindInfoQCOM *pTileMemoryBindInfo = nullptr) const;
	void bindTransformFeedbackBuffers2EXT(uint32_t firstBinding, const impl_Struct::ArrayProxy<BindTransformFeedbackBuffer2InfoEXT> &bindingInfos = nullptr) const;
	
	[[deprecated("supersededby: bindTransformFeedbackBuffers2EXT")]]
	void bindTransformFeedbackBuffersEXT(uint32_t firstBinding, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &buffers, const impl_Struct::ArrayProxy<DeviceSize> &offsets, const impl_Struct::ArrayProxy<DeviceSize> &sizes = nullptr) const;
	void bindVertexBuffers(uint32_t firstBinding, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &buffers, const impl_Struct::ArrayProxy<DeviceSize> &offsets) const;
	void bindVertexBuffers2(uint32_t firstBinding, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &buffers, const impl_Struct::ArrayProxy<DeviceSize> &offsets, const impl_Struct::ArrayProxy<DeviceSize> &sizes = nullptr, const impl_Struct::ArrayProxy<DeviceSize> &strides = nullptr) const;
	void bindVertexBuffers3KHR(uint32_t firstBinding, const impl_Struct::ArrayProxy<BindVertexBuffer3InfoKHR> &bindingInfos) const;
	void blitImage(const Image &srcImage, ImageLayout srcImageLayout, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageBlit> &regions, Filter filter) const;
	void blitImage2(const BlitImageInfo2 &blitImageInfo) const;
	void buildAccelerationStructureNV(const AccelerationStructureInfoNV &info, const Buffer &instanceData, DeviceSize instanceOffset, Bool32 update, const AccelerationStructureNV &dst, const AccelerationStructureNV &src, const Buffer &scratch, DeviceSize scratchOffset) const;
	void buildAccelerationStructuresIndirectKHR(const impl_Struct::ArrayProxy<AccelerationStructureBuildGeometryInfoKHR> &infos, const impl_Struct::ArrayProxy<DeviceAddress> &indirectDeviceAddresses, const impl_Struct::ArrayProxy<uint32_t> &indirectStrides, const uint32_t * const*ppMaxPrimitiveCounts) const;
	void buildAccelerationStructuresKHR(const impl_Struct::ArrayProxy<AccelerationStructureBuildGeometryInfoKHR> &infos, const AccelerationStructureBuildRangeInfoKHR * const*ppBuildRangeInfos) const;
	void buildClusterAccelerationStructureIndirectNV(const ClusterAccelerationStructureCommandsInfoNV &commandInfos) const;
	void buildMicromapsEXT(const impl_Struct::ArrayProxy<MicromapBuildInfoEXT> &infos) const;
	void buildPartitionedAccelerationStructuresNV(const BuildPartitionedAccelerationStructureInfoNV &buildInfo) const;
	void clearAttachments(const impl_Struct::ArrayProxy<ClearAttachment> &attachments, const impl_Struct::ArrayProxy<ClearRect> &rects) const;
	void clearColorImage(const Image &image, ImageLayout imageLayout, const ClearColorValue &color, const impl_Struct::ArrayProxy<ImageSubresourceRange> &ranges) const;
	void clearDepthStencilImage(const Image &image, ImageLayout imageLayout, const ClearDepthStencilValue &depthStencil, const impl_Struct::ArrayProxy<ImageSubresourceRange> &ranges) const;
	void controlVideoCodingKHR(const VideoCodingControlInfoKHR &codingControlInfo) const;
	void convertCooperativeVectorMatrixNV(const impl_Struct::ArrayProxy<ConvertCooperativeVectorMatrixInfoNV> &infos) const;
	void copyAccelerationStructureKHR(const CopyAccelerationStructureInfoKHR &info) const;
	void copyAccelerationStructureNV(const AccelerationStructureNV &dst, const AccelerationStructureNV &src, CopyAccelerationStructureModeKHR mode) const;
	void copyAccelerationStructureToMemoryKHR(const CopyAccelerationStructureToMemoryInfoKHR &info) const;
	void copyBuffer(const Buffer &srcBuffer, const Buffer &dstBuffer, const impl_Struct::ArrayProxy<BufferCopy> &regions) const;
	
	[[deprecated("supersededby: copyMemoryKHR")]]
	void copyBuffer2(const CopyBufferInfo2 &copyBufferInfo) const;
	void copyBufferToImage(const Buffer &srcBuffer, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<BufferImageCopy> &regions) const;
	
	[[deprecated("supersededby: copyMemoryToImageKHR")]]
	void copyBufferToImage2(const CopyBufferToImageInfo2 &copyBufferToImageInfo) const;
	void copyGpaSessionResultsAMD(const GpaSessionAMD &gpaSession) const;
	void copyImage(const Image &srcImage, ImageLayout srcImageLayout, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageCopy> &regions) const;
	void copyImage2(const CopyImageInfo2 &copyImageInfo) const;
	void copyImageToBuffer(const Image &srcImage, ImageLayout srcImageLayout, const Buffer &dstBuffer, const impl_Struct::ArrayProxy<BufferImageCopy> &regions) const;
	
	[[deprecated("supersededby: copyImageToMemoryKHR")]]
	void copyImageToBuffer2(const CopyImageToBufferInfo2 &copyImageToBufferInfo) const;
	void copyImageToMemoryKHR(const CopyDeviceMemoryImageInfoKHR *pCopyMemoryInfo = nullptr) const;
	void copyMemoryIndirectKHR(const CopyMemoryIndirectInfoKHR &copyMemoryIndirectInfo) const;
	void copyMemoryIndirectNV(DeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) const;
	void copyMemoryKHR(const CopyDeviceMemoryInfoKHR *pCopyMemoryInfo = nullptr) const;
	void copyMemoryToAccelerationStructureKHR(const CopyMemoryToAccelerationStructureInfoKHR &info) const;
	void copyMemoryToImageIndirectKHR(const CopyMemoryToImageIndirectInfoKHR &copyMemoryToImageIndirectInfo) const;
	void copyMemoryToImageIndirectNV(DeviceAddress copyBufferAddress, uint32_t stride, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageSubresourceLayers> &imageSubresources) const;
	void copyMemoryToImageKHR(const CopyDeviceMemoryImageInfoKHR *pCopyMemoryInfo = nullptr) const;
	void copyMemoryToMicromapEXT(const CopyMemoryToMicromapInfoEXT &info) const;
	void copyMicromapEXT(const CopyMicromapInfoEXT &info) const;
	void copyMicromapToMemoryEXT(const CopyMicromapToMemoryInfoEXT &info) const;
	
	[[deprecated("supersededby: copyQueryPoolResultsToMemoryKHR")]]
	void copyQueryPoolResults(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount, const Buffer &dstBuffer, DeviceSize dstOffset, DeviceSize stride, QueryResultFlags flags = {}) const;
	void copyQueryPoolResultsToMemoryKHR(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount, const StridedDeviceAddressRangeKHR &dstRange, AddressCommandFlagsKHR dstFlags = {}, QueryResultFlags queryResultFlags = {}) const;
	void copyTensorARM(const CopyTensorInfoARM &copyTensorInfo) const;
	void cuLaunchKernelNVX(const CuLaunchInfoNVX &launchInfo) const;
	void debugMarkerBeginEXT(const DebugMarkerMarkerInfoEXT &markerInfo) const;
	void debugMarkerEndEXT() const;
	void debugMarkerInsertEXT(const DebugMarkerMarkerInfoEXT &markerInfo) const;
	void decodeVideoKHR(const VideoDecodeInfoKHR &decodeInfo) const;
	void decompressMemoryEXT(const DecompressMemoryInfoEXT &decompressMemoryInfoEXT) const;
	void decompressMemoryIndirectCountEXT(MemoryDecompressionMethodFlagsEXT decompressionMethod, DeviceAddress indirectCommandsAddress, DeviceAddress indirectCommandsCountAddress, uint32_t maxDecompressionCount, uint32_t stride) const;
	void decompressMemoryIndirectCountNV(DeviceAddress indirectCommandsAddress, DeviceAddress indirectCommandsCountAddress, uint32_t stride) const;
	void decompressMemoryNV(const impl_Struct::ArrayProxy<DecompressMemoryRegionNV> &decompressMemoryRegions) const;
	void dispatch(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const;
	void dispatchBase(uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const;
	void dispatchDataGraphARM(const DataGraphPipelineSessionARM &session, const DataGraphPipelineDispatchInfoARM *pInfo = nullptr) const;
	
	[[deprecated("supersededby: dispatchIndirect2KHR")]]
	void dispatchIndirect(const Buffer &buffer, DeviceSize offset) const;
	void dispatchIndirect2KHR(const DispatchIndirect2InfoKHR &info) const;
	void dispatchTileQCOM(const DispatchTileInfoQCOM &dispatchTileInfo) const;
	void draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const;
	void drawClusterHUAWEI(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const;
	void drawClusterIndirectHUAWEI(const Buffer &buffer, DeviceSize offset) const;
	void drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) const;
	
	[[deprecated("supersededby: drawIndexedIndirect2KHR")]]
	void drawIndexedIndirect(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const;
	void drawIndexedIndirect2KHR(const DrawIndirect2InfoKHR &info) const;
	
	[[deprecated("supersededby: drawIndexedIndirectCount2KHR")]]
	void drawIndexedIndirectCount(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const;
	void drawIndexedIndirectCount2KHR(const DrawIndirectCount2InfoKHR &info) const;
	
	[[deprecated("supersededby: drawIndirect2KHR")]]
	void drawIndirect(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const;
	void drawIndirect2KHR(const DrawIndirect2InfoKHR &info) const;
	void drawIndirectByteCount2EXT(uint32_t instanceCount, uint32_t firstInstance, const BindTransformFeedbackBuffer2InfoEXT &counterInfo, uint32_t counterOffset, uint32_t vertexStride) const;
	
	[[deprecated("supersededby: drawIndirectByteCount2EXT")]]
	void drawIndirectByteCountEXT(uint32_t instanceCount, uint32_t firstInstance, const Buffer &counterBuffer, DeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) const;
	
	[[deprecated("supersededby: drawIndirectCount2KHR")]]
	void drawIndirectCount(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const;
	void drawIndirectCount2KHR(const DrawIndirectCount2InfoKHR &info) const;
	void drawMeshTasksEXT(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const;
	void drawMeshTasksIndirect2EXT(const DrawIndirect2InfoKHR &info) const;
	void drawMeshTasksIndirectCount2EXT(const DrawIndirectCount2InfoKHR &info) const;
	
	[[deprecated("supersededby: drawMeshTasksIndirectCount2EXT")]]
	void drawMeshTasksIndirectCountEXT(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const;
	void drawMeshTasksIndirectCountNV(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const;
	
	[[deprecated("supersededby: drawMeshTasksIndirect2EXT")]]
	void drawMeshTasksIndirectEXT(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const;
	void drawMeshTasksIndirectNV(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const;
	void drawMeshTasksNV(uint32_t taskCount, uint32_t firstTask) const;
	void drawMultiEXT(const impl_Struct::ArrayProxy<MultiDrawInfoEXT> &vertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) const;
	void drawMultiIndexedEXT(const impl_Struct::ArrayProxy<MultiDrawIndexedInfoEXT> &indexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t *pVertexOffset = nullptr) const;
	void encodeVideoKHR(const VideoEncodeInfoKHR &encodeInfo) const;
	void endConditionalRenderingEXT() const;
	void endDebugUtilsLabelEXT() const;
	void endGpaSampleAMD(const GpaSessionAMD &gpaSession, uint32_t sampleID) const;
	[[nodiscard]] auto endGpaSessionAMD(const GpaSessionAMD &gpaSession) const -> Result;
	void endPerTileExecutionQCOM(const PerTileEndInfoQCOM &perTileEndInfo) const;
	void endQuery(const QueryPool &queryPool, uint32_t query) const;
	void endQueryIndexedEXT(const QueryPool &queryPool, uint32_t query, uint32_t index) const;
	
	[[deprecated("supersededby: endRenderPass2")]]
	void endRenderPass() const;
	void endRenderPass2(const SubpassEndInfo &subpassEndInfo) const;
	void endRendering() const;
	void endRendering2KHR(const RenderingEndInfoKHR *pRenderingEndInfo = nullptr) const;
	void endShaderInstrumentationARM() const;
	void endTransformFeedback2EXT(uint32_t firstCounterRange, const impl_Struct::ArrayProxy<BindTransformFeedbackBuffer2InfoEXT> &counterInfos = nullptr) const;
	
	[[deprecated("supersededby: endTransformFeedback2EXT")]]
	void endTransformFeedbackEXT(uint32_t firstCounterBuffer, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &counterBuffers, const impl_Struct::ArrayProxy<DeviceSize> &counterBufferOffsets = nullptr) const;
	void endVideoCodingKHR(const VideoEndCodingInfoKHR &endCodingInfo) const;
	void executeCommands(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<CommandBuffer>> &commandBuffers) const;
	void executeGeneratedCommandsEXT(Bool32 isPreprocessed, const GeneratedCommandsInfoEXT &generatedCommandsInfo) const;
	void executeGeneratedCommandsNV(Bool32 isPreprocessed, const GeneratedCommandsInfoNV &generatedCommandsInfo) const;
	
	[[deprecated("supersededby: fillMemoryKHR")]]
	void fillBuffer(const Buffer &dstBuffer, DeviceSize dstOffset, DeviceSize size, uint32_t data) const;
	void fillMemoryKHR(const DeviceAddressRangeKHR &dstRange, AddressCommandFlagsKHR dstFlags, uint32_t data) const;
	void insertDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const;
	
	[[deprecated("supersededby: nextSubpass2")]]
	void nextSubpass(SubpassContents contents) const;
	void nextSubpass2(const SubpassBeginInfo &subpassBeginInfo, const SubpassEndInfo &subpassEndInfo) const;
	void opticalFlowExecuteNV(const OpticalFlowSessionNV &session, const OpticalFlowExecuteInfoNV &executeInfo) const;
	
	[[deprecated("supersededby: pipelineBarrier2")]]
	void pipelineBarrier(PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, DependencyFlags dependencyFlags, const impl_Struct::ArrayProxy<MemoryBarrier> &memoryBarriers, const impl_Struct::ArrayProxy<BufferMemoryBarrier> &bufferMemoryBarriers, const impl_Struct::ArrayProxy<ImageMemoryBarrier> &imageMemoryBarriers) const;
	void pipelineBarrier2(const DependencyInfo &dependencyInfo) const;
	void preprocessGeneratedCommandsEXT(const GeneratedCommandsInfoEXT &generatedCommandsInfo, const CommandBuffer &stateCommandBuffer) const;
	void preprocessGeneratedCommandsNV(const GeneratedCommandsInfoNV &generatedCommandsInfo) const;
	void pushConstants(const PipelineLayout &layout, ShaderStageFlags stageFlags, uint32_t offset, const impl_Struct::POD<uint32_t> &values) const;
	void pushConstants2(const PushConstantsInfo &pushConstantsInfo) const;
	void pushDataEXT(const PushDataInfoEXT &pushDataInfo) const;
	void pushDescriptorSet(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t set, const impl_Struct::ArrayProxy<WriteDescriptorSet> &descriptorWrites) const;
	void pushDescriptorSet2(const PushDescriptorSetInfo &pushDescriptorSetInfo) const;
	void pushDescriptorSetWithTemplate(const DescriptorUpdateTemplate &descriptorUpdateTemplate, const PipelineLayout &layout, uint32_t set, const void *pData) const;
	void pushDescriptorSetWithTemplate2(const PushDescriptorSetWithTemplateInfo &pushDescriptorSetWithTemplateInfo) const;
	
	[[deprecated("supersededby: resetEvent2")]]
	void resetEvent(const Event &event, PipelineStageFlags stageMask = {}) const;
	void resetEvent2(const Event &event, PipelineStageFlags2 stageMask = {}) const;
	void resetQueryPool(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount) const;
	void resolveImage(const Image &srcImage, ImageLayout srcImageLayout, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageResolve> &regions) const;
	void resolveImage2(const ResolveImageInfo2 &resolveImageInfo) const;
	void setAlphaToCoverageEnableEXT(Bool32 alphaToCoverageEnable) const;
	void setAlphaToOneEnableEXT(Bool32 alphaToOneEnable) const;
	void setAttachmentFeedbackLoopEnableEXT(ImageAspectFlags aspectMask = {}) const;
	void setBlendConstants(const std::array<float, 4> &blendConstants) const;
	void setCheckpointNV(const void *pCheckpointMarker) const;
	void setCoarseSampleOrderNV(CoarseSampleOrderTypeNV sampleOrderType, const impl_Struct::ArrayProxy<CoarseSampleOrderCustomNV> &customSampleOrders) const;
	void setColorBlendAdvancedEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<ColorBlendAdvancedEXT> &colorBlendAdvanced) const;
	void setColorBlendEnableEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<Bool32> &colorBlendEnables) const;
	void setColorBlendEquationEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<ColorBlendEquationEXT> &colorBlendEquations) const;
	void setColorWriteEnableEXT(const impl_Struct::ArrayProxy<Bool32> &colorWriteEnables) const;
	void setColorWriteMaskEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<ColorComponentFlags> &colorWriteMasks = nullptr) const;
	void setComputeOccupancyPriorityNV(const ComputeOccupancyPriorityParametersNV &parameters) const;
	void setConservativeRasterizationModeEXT(ConservativeRasterizationModeEXT conservativeRasterizationMode) const;
	void setCoverageModulationModeNV(CoverageModulationModeNV coverageModulationMode) const;
	void setCoverageModulationTableEnableNV(Bool32 coverageModulationTableEnable) const;
	void setCoverageModulationTableNV(const impl_Struct::ArrayProxy<float> &coverageModulationTable) const;
	void setCoverageReductionModeNV(CoverageReductionModeNV coverageReductionMode) const;
	void setCoverageToColorEnableNV(Bool32 coverageToColorEnable) const;
	void setCoverageToColorLocationNV(uint32_t coverageToColorLocation) const;
	void setCullMode(CullModeFlags cullMode = {}) const;
	void setDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) const;
	void setDepthBias2EXT(const DepthBiasInfoEXT &depthBiasInfo) const;
	void setDepthBiasEnable(Bool32 depthBiasEnable) const;
	void setDepthBounds(float minDepthBounds, float maxDepthBounds) const;
	void setDepthBoundsTestEnable(Bool32 depthBoundsTestEnable) const;
	void setDepthClampEnableEXT(Bool32 depthClampEnable) const;
	void setDepthClampRangeEXT(DepthClampModeEXT depthClampMode, const DepthClampRangeEXT *pDepthClampRange = nullptr) const;
	void setDepthClipEnableEXT(Bool32 depthClipEnable) const;
	void setDepthClipNegativeOneToOneEXT(Bool32 negativeOneToOne) const;
	void setDepthCompareOp(CompareOp depthCompareOp) const;
	void setDepthTestEnable(Bool32 depthTestEnable) const;
	void setDepthWriteEnable(Bool32 depthWriteEnable) const;
	void setDescriptorBufferOffsets2EXT(const SetDescriptorBufferOffsetsInfoEXT &setDescriptorBufferOffsetsInfo) const;
	void setDescriptorBufferOffsetsEXT(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t firstSet, const impl_Struct::ArrayProxy<uint32_t> &bufferIndices, const impl_Struct::ArrayProxy<DeviceSize> &offsets) const;
	void setDeviceMask(uint32_t deviceMask) const;
	void setDiscardRectangleEXT(uint32_t firstDiscardRectangle, const impl_Struct::ArrayProxy<Rect2D> &discardRectangles) const;
	void setDiscardRectangleEnableEXT(Bool32 discardRectangleEnable) const;
	void setDiscardRectangleModeEXT(DiscardRectangleModeEXT discardRectangleMode) const;
	void setDispatchParametersARM(const DispatchParametersARM &dispatchParameters) const;
	
	[[deprecated("supersededby: setEvent2")]]
	void setEvent(const Event &event, PipelineStageFlags stageMask = {}) const;
	void setEvent2(const Event &event, const DependencyInfo &dependencyInfo) const;
	void setExclusiveScissorEnableNV(uint32_t firstExclusiveScissor, const impl_Struct::ArrayProxy<Bool32> &exclusiveScissorEnables) const;
	void setExclusiveScissorNV(uint32_t firstExclusiveScissor, const impl_Struct::ArrayProxy<Rect2D> &exclusiveScissors) const;
	void setExtraPrimitiveOverestimationSizeEXT(float extraPrimitiveOverestimationSize) const;
	void setFragmentShadingRateEnumNV(FragmentShadingRateNV shadingRate, const std::array<FragmentShadingRateCombinerOpKHR, 2> &combinerOps) const;
	void setFragmentShadingRateKHR(const Extent2D &fragmentSize, const std::array<FragmentShadingRateCombinerOpKHR, 2> &combinerOps) const;
	void setFrontFace(FrontFace frontFace) const;
	void setLineRasterizationModeEXT(LineRasterizationMode lineRasterizationMode) const;
	void setLineStipple(uint32_t lineStippleFactor, uint16_t lineStipplePattern) const;
	void setLineStippleEnableEXT(Bool32 stippledLineEnable) const;
	void setLineWidth(float lineWidth) const;
	void setLogicOpEXT(LogicOp logicOp) const;
	void setLogicOpEnableEXT(Bool32 logicOpEnable) const;
	void setPatchControlPointsEXT(uint32_t patchControlPoints) const;
	[[nodiscard]] auto setPerformanceMarkerINTEL(const PerformanceMarkerInfoINTEL &markerInfo) const -> Result;
	[[nodiscard]] auto setPerformanceOverrideINTEL(const PerformanceOverrideInfoINTEL &overrideInfo) const -> Result;
	[[nodiscard]] auto setPerformanceStreamMarkerINTEL(const PerformanceStreamMarkerInfoINTEL &markerInfo) const -> Result;
	void setPolygonModeEXT(PolygonMode polygonMode) const;
	void setPrimitiveRestartEnable(Bool32 primitiveRestartEnable) const;
	void setPrimitiveRestartIndexEXT(uint32_t primitiveRestartIndex = 0) const;
	void setPrimitiveTopology(PrimitiveTopology primitiveTopology) const;
	void setProvokingVertexModeEXT(ProvokingVertexModeEXT provokingVertexMode) const;
	void setRasterizationSamplesEXT(SampleCountBits rasterizationSamples) const;
	void setRasterizationStreamEXT(uint32_t rasterizationStream) const;
	void setRasterizerDiscardEnable(Bool32 rasterizerDiscardEnable) const;
	void setRayTracingPipelineStackSizeKHR(uint32_t pipelineStackSize) const;
	void setRenderingAttachmentLocations(const RenderingAttachmentLocationInfo &locationInfo) const;
	void setRenderingInputAttachmentIndices(const RenderingInputAttachmentIndexInfo &inputAttachmentIndexInfo) const;
	void setRepresentativeFragmentTestEnableNV(Bool32 representativeFragmentTestEnable) const;
	void setSampleLocationsEXT(const SampleLocationsInfoEXT &sampleLocationsInfo) const;
	void setSampleLocationsEnableEXT(Bool32 sampleLocationsEnable) const;
	void setSampleMaskEXT(SampleCountBits samples, const SampleMask *pSampleMask = nullptr) const;
	void setScissor(uint32_t firstScissor, const impl_Struct::ArrayProxy<Rect2D> &scissors) const;
	void setScissorWithCount(const impl_Struct::ArrayProxy<Rect2D> &scissors) const;
	void setShadingRateImageEnableNV(Bool32 shadingRateImageEnable) const;
	void setStencilCompareMask(StencilFaceFlags faceMask, uint32_t compareMask) const;
	void setStencilOp(StencilFaceFlags faceMask, StencilOp failOp, StencilOp passOp, StencilOp depthFailOp, CompareOp compareOp) const;
	void setStencilReference(StencilFaceFlags faceMask, uint32_t reference) const;
	void setStencilTestEnable(Bool32 stencilTestEnable) const;
	void setStencilWriteMask(StencilFaceFlags faceMask, uint32_t writeMask) const;
	void setTessellationDomainOriginEXT(TessellationDomainOrigin domainOrigin) const;
	void setVertexInputEXT(const impl_Struct::ArrayProxy<VertexInputBindingDescription2EXT> &vertexBindingDescriptions, const impl_Struct::ArrayProxy<VertexInputAttributeDescription2EXT> &vertexAttributeDescriptions) const;
	void setViewport(uint32_t firstViewport, const impl_Struct::ArrayProxy<Viewport> &viewports) const;
	void setViewportShadingRatePaletteNV(uint32_t firstViewport, const impl_Struct::ArrayProxy<ShadingRatePaletteNV> &shadingRatePalettes) const;
	void setViewportSwizzleNV(uint32_t firstViewport, const impl_Struct::ArrayProxy<ViewportSwizzleNV> &viewportSwizzles) const;
	void setViewportWScalingEnableNV(Bool32 viewportWScalingEnable) const;
	void setViewportWScalingNV(uint32_t firstViewport, const impl_Struct::ArrayProxy<ViewportWScalingNV> &viewportWScalings) const;
	void setViewportWithCount(const impl_Struct::ArrayProxy<Viewport> &viewports) const;
	void subpassShadingHUAWEI() const;
	void traceRaysIndirect2KHR(DeviceAddress indirectDeviceAddress) const;
	void traceRaysIndirectKHR(const StridedDeviceAddressRegionKHR &raygenShaderBindingTable, const StridedDeviceAddressRegionKHR &missShaderBindingTable, const StridedDeviceAddressRegionKHR &hitShaderBindingTable, const StridedDeviceAddressRegionKHR &callableShaderBindingTable, DeviceAddress indirectDeviceAddress) const;
	void traceRaysKHR(const StridedDeviceAddressRegionKHR &raygenShaderBindingTable, const StridedDeviceAddressRegionKHR &missShaderBindingTable, const StridedDeviceAddressRegionKHR &hitShaderBindingTable, const StridedDeviceAddressRegionKHR &callableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) const;
	void traceRaysNV(const Buffer &raygenShaderBindingTableBuffer, DeviceSize raygenShaderBindingOffset, const Buffer &missShaderBindingTableBuffer, DeviceSize missShaderBindingOffset, DeviceSize missShaderBindingStride, const Buffer &hitShaderBindingTableBuffer, DeviceSize hitShaderBindingOffset, DeviceSize hitShaderBindingStride, const Buffer &callableShaderBindingTableBuffer, DeviceSize callableShaderBindingOffset, DeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) const;
	
	[[deprecated("supersededby: updateMemoryKHR")]]
	void updateBuffer(const Buffer &dstBuffer, DeviceSize dstOffset, const impl_Struct::POD<DeviceSize> &data) const;
	void updateMemoryKHR(const DeviceAddressRangeKHR &dstRange, AddressCommandFlagsKHR dstFlags, const impl_Struct::POD<DeviceSize> &data) const;
	void updatePipelineIndirectBufferNV(PipelineBindPoint pipelineBindPoint, const Pipeline &pipeline) const;
	
	[[deprecated("supersededby: waitEvents2")]]
	void waitEvents(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Event>> &events, PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, const impl_Struct::ArrayProxy<MemoryBarrier> &memoryBarriers, const impl_Struct::ArrayProxy<BufferMemoryBarrier> &bufferMemoryBarriers, const impl_Struct::ArrayProxy<ImageMemoryBarrier> &imageMemoryBarriers) const;
	void waitEvents2(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Event>> &events, const impl_Struct::ArrayProxy<DependencyInfo> &dependencyInfos) const;
	void writeAccelerationStructuresPropertiesKHR(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureKHR>> &accelerationStructures, QueryType queryType, const QueryPool &queryPool, uint32_t firstQuery) const;
	void writeAccelerationStructuresPropertiesNV(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureNV>> &accelerationStructures, QueryType queryType, const QueryPool &queryPool, uint32_t firstQuery) const;
	
	[[deprecated("supersededby: writeMarkerToMemoryAMD")]]
	void writeBufferMarker2AMD(PipelineStageFlags2 stage, const Buffer &dstBuffer, DeviceSize dstOffset, uint32_t marker) const;
	void writeBufferMarkerAMD(PipelineStageBits pipelineStage, const Buffer &dstBuffer, DeviceSize dstOffset, uint32_t marker) const;
	void writeMarkerToMemoryAMD(const MemoryMarkerInfoAMD &info) const;
	void writeMicromapsPropertiesEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<MicromapEXT>> &micromaps, QueryType queryType, const QueryPool &queryPool, uint32_t firstQuery) const;
	
	[[deprecated("supersededby: writeTimestamp2")]]
	void writeTimestamp(PipelineStageBits pipelineStage, const QueryPool &queryPool, uint32_t query) const;
	void writeTimestamp2(PipelineStageFlags2 stage, const QueryPool &queryPool, uint32_t query) const;
	[[nodiscard]] auto end() const -> Result;
	[[nodiscard]] auto reset(CommandBufferResetFlags flags = {}) const -> Result;
	#ifdef VK_ENABLE_BETA_EXTENSIONS
		void cudaLaunchKernelNV(const CudaLaunchInfoNV &launchInfo) const;
		void dispatchGraphAMDX(DeviceAddress scratch, DeviceSize scratchSize, const DispatchGraphCountInfoAMDX &countInfo) const;
		void dispatchGraphIndirectAMDX(DeviceAddress scratch, DeviceSize scratchSize, const DispatchGraphCountInfoAMDX &countInfo) const;
		void dispatchGraphIndirectCountAMDX(DeviceAddress scratch, DeviceSize scratchSize, DeviceAddress countInfo) const;
		void initializeGraphScratchMemoryAMDX(const Pipeline &executionGraph, DeviceAddress scratch, DeviceSize scratchSize) const;
	#endif // VK_ENABLE_BETA_EXTENSIONS
};
struct ExternalComputeQueueNV : public impl_Objects::Object<Handle::ExternalComputeQueueNV> {
	using Object::Object;
	ExternalComputeQueueNV() = default;
	void getExternalComputeQueueDataNV(ExternalComputeQueueDataParamsNV *params, void *pData) const;
};
struct Queue : public impl_Objects::Object<Handle::Queue> {
	using Object::Object;
	Queue() = default;
	[[nodiscard]] auto getCheckpointData2NV() const -> std::vector<CheckpointData2NV>;
	[[nodiscard]] auto getCheckpointDataNV() const -> std::vector<CheckpointDataNV>;
	void beginDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const;
	[[nodiscard]] auto bindSparse(const impl_Struct::ArrayProxy<BindSparseInfo> &bindInfo, const Fence &fence = {}) const -> Result;
	void endDebugUtilsLabelEXT() const;
	void insertDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const;
	void notifyOutOfBandLegacyNV(uint32_t queueType) const;
	void notifyOutOfBandNV(const OutOfBandQueueTypeInfoNV &queueTypeInfo) const;
	[[nodiscard]] auto presentKHR(const PresentInfoKHR &presentInfo) const -> Result;
	[[nodiscard]] auto setPerfHintQCOM(const PerfHintInfoQCOM &perfHintInfo) const -> Result;
	[[nodiscard]] auto setPerformanceConfigurationINTEL(const PerformanceConfigurationINTEL &configuration) const -> Result;
	
	[[deprecated("supersededby: submit2")]]
	[[nodiscard]] auto submit(const impl_Struct::ArrayProxy<SubmitInfo> &submits, const Fence &fence = {}) const -> Result;
	[[nodiscard]] auto submit2(const impl_Struct::ArrayProxy<SubmitInfo2> &submits, const Fence &fence = {}) const -> Result;
	[[nodiscard]] auto waitIdle() const -> Result;
};
struct Device : public impl_Objects::Object<Handle::Device> {
	using Object::Object;
	Device() = default;
	[[nodiscard]] auto acquireNextImage2KHR(const AcquireNextImageInfoKHR &acquireInfo, uint32_t *pImageIndex) const -> Result;
	[[nodiscard]] auto acquireNextImageKHR(const SwapchainKHR &swapchain, uint64_t timeout, const Semaphore &semaphore, const Fence &fence, uint32_t *pImageIndex) const -> Result;
	[[nodiscard]] auto acquirePerformanceConfigurationINTEL(const PerformanceConfigurationAcquireInfoINTEL &acquireInfo) const -> std::expected<UniquePerformanceConfigurationINTEL, Result>;
	[[nodiscard]] auto acquireProfilingLockKHR(const AcquireProfilingLockInfoKHR &info) const -> Result;
	[[nodiscard]] auto allocateCommandBuffers(const CommandBufferAllocateInfo &allocateInfo) const -> std::expected<CommandBuffers, Result>;
	[[nodiscard]] auto allocateDescriptorSets(const DescriptorSetAllocateInfo &allocateInfo) const -> std::expected<DescriptorSets, Result>;
	[[nodiscard]] auto allocateMemory(const MemoryAllocateInfo &allocateInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDeviceMemory, Result>;
	void antiLagUpdateAMD(const AntiLagDataAMD &data) const;
	[[nodiscard]] auto bindAccelerationStructureMemoryNV(const impl_Struct::ArrayProxy<BindAccelerationStructureMemoryInfoNV> &bindInfos) const -> Result;
	[[nodiscard]] auto bindBufferMemory(const Buffer &buffer, const DeviceMemory &memory, DeviceSize memoryOffset) const -> Result;
	[[nodiscard]] auto bindBufferMemory2(const impl_Struct::ArrayProxy<BindBufferMemoryInfo> &bindInfos) const -> Result;
	[[nodiscard]] auto bindDataGraphPipelineSessionMemoryARM(const impl_Struct::ArrayProxy<BindDataGraphPipelineSessionMemoryInfoARM> &bindInfos) const -> Result;
	[[nodiscard]] auto bindImageMemory(const Image &image, const DeviceMemory &memory, DeviceSize memoryOffset) const -> Result;
	[[nodiscard]] auto bindImageMemory2(const impl_Struct::ArrayProxy<BindImageMemoryInfo> &bindInfos) const -> Result;
	[[nodiscard]] auto bindOpticalFlowSessionImageNV(const OpticalFlowSessionNV &session, OpticalFlowSessionBindingPointNV bindingPoint, const ImageView &view, ImageLayout layout) const -> Result;
	[[nodiscard]] auto bindTensorMemoryARM(const impl_Struct::ArrayProxy<BindTensorMemoryInfoARM> &bindInfos) const -> Result;
	[[nodiscard]] auto bindVideoSessionMemoryKHR(const VideoSessionKHR &videoSession, const impl_Struct::ArrayProxy<BindVideoSessionMemoryInfoKHR> &bindSessionMemoryInfos) const -> Result;
	
	[[deprecated("supersededby: buildAccelerationStructuresKHR")]]
	[[nodiscard]] auto buildAccelerationStructuresKHR(const DeferredOperationKHR &deferredOperation, const impl_Struct::ArrayProxy<AccelerationStructureBuildGeometryInfoKHR> &infos, const AccelerationStructureBuildRangeInfoKHR * const*ppBuildRangeInfos) const -> Result;
	
	[[deprecated("supersededby: buildMicromapsEXT")]]
	[[nodiscard]] auto buildMicromapsEXT(const DeferredOperationKHR &deferredOperation, const impl_Struct::ArrayProxy<MicromapBuildInfoEXT> &infos) const -> Result;
	void clearShaderInstrumentationMetricsARM(const ShaderInstrumentationARM &instrumentation) const;
	[[nodiscard]] auto compileDeferredNV(const Pipeline &pipeline, uint32_t shader) const -> Result;
	[[nodiscard]] auto convertCooperativeVectorMatrixNV(const ConvertCooperativeVectorMatrixInfoNV &info) const -> Result;
	
	[[deprecated("supersededby: copyAccelerationStructureKHR")]]
	[[nodiscard]] auto copyAccelerationStructureKHR(const DeferredOperationKHR &deferredOperation, const CopyAccelerationStructureInfoKHR &info) const -> Result;
	
	[[deprecated("supersededby: copyAccelerationStructureToMemoryKHR")]]
	[[nodiscard]] auto copyAccelerationStructureToMemoryKHR(const DeferredOperationKHR &deferredOperation, const CopyAccelerationStructureToMemoryInfoKHR &info) const -> Result;
	[[nodiscard]] auto copyImageToImage(const CopyImageToImageInfo &copyImageToImageInfo) const -> Result;
	[[nodiscard]] auto copyImageToMemory(const CopyImageToMemoryInfo &copyImageToMemoryInfo) const -> Result;
	
	[[deprecated("supersededby: copyMemoryToAccelerationStructureKHR")]]
	[[nodiscard]] auto copyMemoryToAccelerationStructureKHR(const DeferredOperationKHR &deferredOperation, const CopyMemoryToAccelerationStructureInfoKHR &info) const -> Result;
	[[nodiscard]] auto copyMemoryToImage(const CopyMemoryToImageInfo &copyMemoryToImageInfo) const -> Result;
	
	[[deprecated("supersededby: copyMemoryToMicromapEXT")]]
	[[nodiscard]] auto copyMemoryToMicromapEXT(const DeferredOperationKHR &deferredOperation, const CopyMemoryToMicromapInfoEXT &info) const -> Result;
	
	[[deprecated("supersededby: copyMicromapEXT")]]
	[[nodiscard]] auto copyMicromapEXT(const DeferredOperationKHR &deferredOperation, const CopyMicromapInfoEXT &info) const -> Result;
	
	[[deprecated("supersededby: copyMicromapToMemoryEXT")]]
	[[nodiscard]] auto copyMicromapToMemoryEXT(const DeferredOperationKHR &deferredOperation, const CopyMicromapToMemoryInfoEXT &info) const -> Result;
	[[nodiscard]] auto createAccelerationStructure2KHR(const AccelerationStructureCreateInfo2KHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueAccelerationStructureKHR, Result>;
	
	[[deprecated("supersededby: createAccelerationStructure2KHR")]]
	[[nodiscard]] auto createAccelerationStructureKHR(const AccelerationStructureCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueAccelerationStructureKHR, Result>;
	[[nodiscard]] auto createAccelerationStructureNV(const AccelerationStructureCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueAccelerationStructureNV, Result>;
	[[nodiscard]] auto createBuffer(const BufferCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueBuffer, Result>;
	[[nodiscard]] auto createBufferView(const BufferViewCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueBufferView, Result>;
	[[nodiscard]] auto createCommandPool(const CommandPoolCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueCommandPool, Result>;
	[[nodiscard]] auto createComputePipelines(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<ComputePipelineCreateInfo> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniquePipeline>, Result>;
	[[nodiscard]] auto createCuFunctionNVX(const CuFunctionCreateInfoNVX &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueCuFunctionNVX, Result>;
	[[nodiscard]] auto createCuModuleNVX(const CuModuleCreateInfoNVX &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueCuModuleNVX, Result>;
	[[nodiscard]] auto createDataGraphPipelineSessionARM(const DataGraphPipelineSessionCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDataGraphPipelineSessionARM, Result>;
	[[nodiscard]] auto createDataGraphPipelinesARM(const DeferredOperationKHR &deferredOperation, const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<DataGraphPipelineCreateInfoARM> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniquePipeline>, Result>;
	[[nodiscard]] auto createDeferredOperationKHR(const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDeferredOperationKHR, Result>;
	[[nodiscard]] auto createDescriptorPool(const DescriptorPoolCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDescriptorPool, Result>;
	[[nodiscard]] auto createDescriptorSetLayout(const DescriptorSetLayoutCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDescriptorSetLayout, Result>;
	[[nodiscard]] auto createDescriptorUpdateTemplate(const DescriptorUpdateTemplateCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDescriptorUpdateTemplate, Result>;
	[[nodiscard]] auto createEvent(const EventCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueEvent, Result>;
	[[nodiscard]] auto createExternalComputeQueueNV(const ExternalComputeQueueCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueExternalComputeQueueNV, Result>;
	[[nodiscard]] auto createFence(const FenceCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueFence, Result>;
	[[nodiscard]] auto createFramebuffer(const FramebufferCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueFramebuffer, Result>;
	[[nodiscard]] auto createGpaSessionAMD(const GpaSessionCreateInfoAMD &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueGpaSessionAMD, Result>;
	[[nodiscard]] auto createGraphicsPipelines(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<GraphicsPipelineCreateInfo> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniquePipeline>, Result>;
	[[nodiscard]] auto createImage(const ImageCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueImage, Result>;
	[[nodiscard]] auto createImageView(const ImageViewCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueImageView, Result>;
	[[nodiscard]] auto createIndirectCommandsLayoutEXT(const IndirectCommandsLayoutCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueIndirectCommandsLayoutEXT, Result>;
	[[nodiscard]] auto createIndirectCommandsLayoutNV(const IndirectCommandsLayoutCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueIndirectCommandsLayoutNV, Result>;
	[[nodiscard]] auto createIndirectExecutionSetEXT(const IndirectExecutionSetCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueIndirectExecutionSetEXT, Result>;
	[[nodiscard]] auto createMicromapEXT(const MicromapCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueMicromapEXT, Result>;
	[[nodiscard]] auto createOpticalFlowSessionNV(const OpticalFlowSessionCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueOpticalFlowSessionNV, Result>;
	[[nodiscard]] auto createPipelineBinariesKHR(const PipelineBinaryCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator, PipelineBinaryHandlesInfoKHR *pBinaries) const -> Result;
	[[nodiscard]] auto createPipelineCache(const PipelineCacheCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniquePipelineCache, Result>;
	[[nodiscard]] auto createPipelineLayout(const PipelineLayoutCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniquePipelineLayout, Result>;
	[[nodiscard]] auto createPrivateDataSlot(const PrivateDataSlotCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniquePrivateDataSlot, Result>;
	[[nodiscard]] auto createQueryPool(const QueryPoolCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueQueryPool, Result>;
	[[nodiscard]] auto createRayTracingPipelinesKHR(const DeferredOperationKHR &deferredOperation, const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<RayTracingPipelineCreateInfoKHR> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniquePipeline>, Result>;
	[[nodiscard]] auto createRayTracingPipelinesNV(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<RayTracingPipelineCreateInfoNV> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniquePipeline>, Result>;
	
	[[deprecated("supersededby: createRenderPass2")]]
	[[nodiscard]] auto createRenderPass(const RenderPassCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueRenderPass, Result>;
	[[nodiscard]] auto createRenderPass2(const RenderPassCreateInfo2 &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueRenderPass, Result>;
	[[nodiscard]] auto createSampler(const SamplerCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSampler, Result>;
	[[nodiscard]] auto createSamplerYcbcrConversion(const SamplerYcbcrConversionCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSamplerYcbcrConversion, Result>;
	[[nodiscard]] auto createSemaphore(const SemaphoreCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSemaphore, Result>;
	[[nodiscard]] auto createShaderInstrumentationARM(const ShaderInstrumentationCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueShaderInstrumentationARM, Result>;
	[[nodiscard]] auto createShaderModule(const ShaderModuleCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueShaderModule, Result>;
	[[nodiscard]] auto createShadersEXT(const impl_Struct::ArrayProxy<ShaderCreateInfoEXT> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniqueShaderEXT>, Result>;
	[[nodiscard]] auto createSharedSwapchainsKHR(const impl_Struct::ArrayProxy<SwapchainCreateInfoKHR> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniqueSwapchainKHR>, Result>;
	[[nodiscard]] auto createSwapchainKHR(const SwapchainCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSwapchainKHR, Result>;
	[[nodiscard]] auto createTensorARM(const TensorCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueTensorARM, Result>;
	[[nodiscard]] auto createTensorViewARM(const TensorViewCreateInfoARM &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueTensorViewARM, Result>;
	[[nodiscard]] auto createValidationCacheEXT(const ValidationCacheCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueValidationCacheEXT, Result>;
	[[nodiscard]] auto createVideoSessionKHR(const VideoSessionCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueVideoSessionKHR, Result>;
	[[nodiscard]] auto createVideoSessionParametersKHR(const VideoSessionParametersCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueVideoSessionParametersKHR, Result>;
	[[nodiscard]] auto debugMarkerSetObjectNameEXT(const DebugMarkerObjectNameInfoEXT &nameInfo) const -> Result;
	[[nodiscard]] auto debugMarkerSetObjectTagEXT(const DebugMarkerObjectTagInfoEXT &tagInfo) const -> Result;
	[[nodiscard]] auto deferredOperationJoinKHR(const DeferredOperationKHR &operation) const -> Result;
	[[nodiscard]] auto waitIdle() const -> Result;
	[[nodiscard]] auto displayPowerControlEXT(const DisplayKHR &display, const DisplayPowerInfoEXT &displayPowerInfo) const -> Result;
	[[nodiscard]] auto flushMappedMemoryRanges(const impl_Struct::ArrayProxy<MappedMemoryRange> &memoryRanges) const -> Result;
	[[nodiscard]] auto getAccelerationStructureBuildSizesKHR(AccelerationStructureBuildTypeKHR buildType, const AccelerationStructureBuildGeometryInfoKHR &buildInfo, const uint32_t *pMaxPrimitiveCounts = nullptr) const -> AccelerationStructureBuildSizesInfoKHR;
	[[nodiscard]] auto getAccelerationStructureAddressKHR(const AccelerationStructureDeviceAddressInfoKHR &info) const -> DeviceAddress;
	[[nodiscard]] auto getAccelerationStructureHandleNV(const AccelerationStructureNV &accelerationStructure, size_t size) const -> std::vector<std::byte>;
	[[nodiscard]] auto getAccelerationStructureMemoryRequirementsNV(const AccelerationStructureMemoryRequirementsInfoNV &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getAccelerationStructureOpaqueCaptureDescriptorDataEXT(const AccelerationStructureCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result;
	[[nodiscard]] auto getBufferAddress(const BufferDeviceAddressInfo &info) const -> DeviceAddress;
	[[nodiscard]] auto getBufferMemoryRequirements(const Buffer &buffer) const -> MemoryRequirements;
	[[nodiscard]] auto getBufferMemoryRequirements2(const BufferMemoryRequirementsInfo2 &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getBufferOpaqueCaptureAddress(const BufferDeviceAddressInfo &info) const -> uint64_t;
	[[nodiscard]] auto getBufferOpaqueCaptureDescriptorDataEXT(const BufferCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result;
	[[nodiscard]] auto getCalibratedTimestampsKHR(const impl_Struct::ArrayProxy<CalibratedTimestampInfoKHR> &timestampInfos) const -> std::expected<std::tuple<std::vector<uint64_t>, uint64_t>, Result>;
	[[nodiscard]] auto getClusterAccelerationStructureBuildSizesNV(const ClusterAccelerationStructureInputInfoNV &info) const -> AccelerationStructureBuildSizesInfoKHR;
	[[nodiscard]] auto getDataGraphPipelineAvailablePropertiesARM(const DataGraphPipelineInfoARM &pipelineInfo) const -> std::expected<std::vector<DataGraphPipelinePropertyARM>, Result>;
	[[nodiscard]] auto getDataGraphPipelinePropertiesARM(const DataGraphPipelineInfoARM &pipelineInfo, size_t size) const -> std::vector<DataGraphPipelinePropertyQueryResultARM>;
	[[nodiscard]] auto getDataGraphPipelineSessionBindPointRequirementsARM(const DataGraphPipelineSessionBindPointRequirementsInfoARM &info) const -> std::expected<std::vector<DataGraphPipelineSessionBindPointRequirementARM>, Result>;
	[[nodiscard]] auto getDataGraphPipelineSessionMemoryRequirementsARM(const DataGraphPipelineSessionMemoryRequirementsInfoARM &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getDeferredOperationMaxConcurrencyKHR(const DeferredOperationKHR &operation) const -> uint32_t;
	[[nodiscard]] auto getDeferredOperationResultKHR() const -> std::expected<DeferredOperationKHR, Result>;
	[[nodiscard]] auto getDescriptorEXT(const DescriptorGetInfoEXT &descriptorInfo, size_t size) const -> std::vector<std::byte>;
	void getDescriptorSetHostMappingVALVE(const DescriptorSet &descriptorSet, void **ppData) const;
	[[nodiscard]] auto getDescriptorSetLayoutBindingOffsetEXT(const DescriptorSetLayout &layout, uint32_t binding) const -> DeviceSize;
	[[nodiscard]] auto getDescriptorSetLayoutHostMappingInfoVALVE(const DescriptorSetBindingReferenceVALVE &bindingReference) const -> DescriptorSetLayoutHostMappingInfoVALVE;
	[[nodiscard]] auto getDescriptorSetLayoutSizeEXT(const DescriptorSetLayout &layout) const -> DeviceSize;
	[[nodiscard]] auto getDescriptorSetLayoutSupport(const DescriptorSetLayoutCreateInfo &createInfo) const -> DescriptorSetLayoutSupport;
	[[nodiscard]] auto getAccelerationStructureCompatibilityKHR(const AccelerationStructureVersionInfoKHR &versionInfo) const -> AccelerationStructureCompatibilityKHR;
	[[nodiscard]] auto getBufferMemoryRequirements(const DeviceBufferMemoryRequirements &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getCombinedImageSamplerIndexNVX(uint64_t imageViewIndex, uint64_t samplerIndex) const -> uint64_t;
	[[nodiscard]] auto getFaultDebugInfoKHR() const -> std::expected<DeviceFaultDebugInfoKHR, Result>;
	[[nodiscard]] auto getFaultInfoEXT(DeviceFaultCountsEXT *pFaultCounts) const -> std::expected<DeviceFaultInfoEXT, Result>;
	[[nodiscard]] auto getFaultReportsKHR(uint64_t timeout) const -> std::expected<std::vector<DeviceFaultInfoKHR>, Result>;
	[[nodiscard]] auto getGroupPeerMemoryFeatures(uint32_t heapIndex, uint32_t localDeviceIndex, uint32_t remoteDeviceIndex) const -> PeerMemoryFeatureFlags;
	[[nodiscard]] auto getGroupPresentCapabilitiesKHR() const -> std::expected<DeviceGroupPresentCapabilitiesKHR, Result>;
	[[nodiscard]] auto getGroupSurfacePresentModesKHR(const SurfaceKHR &surface) const -> std::expected<DeviceGroupPresentModeFlagsKHR, Result>;
	[[nodiscard]] auto getImageMemoryRequirements(const DeviceImageMemoryRequirements &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getImageSparseMemoryRequirements(const DeviceImageMemoryRequirements &info) const -> std::vector<SparseImageMemoryRequirements2>;
	[[nodiscard]] auto getImageSubresourceLayout(const DeviceImageSubresourceInfo &info) const -> SubresourceLayout2;
	[[nodiscard]] auto getMemoryCommitment(const DeviceMemory &memory) const -> DeviceSize;
	[[nodiscard]] auto getMemoryOpaqueCaptureAddress(const DeviceMemoryOpaqueCaptureAddressInfo &info) const -> uint64_t;
	[[nodiscard]] auto getMicromapCompatibilityEXT(const MicromapVersionInfoEXT &versionInfo) const -> AccelerationStructureCompatibilityKHR;
	[[nodiscard]] auto getQueue(uint32_t queueFamilyIndex, uint32_t queueIndex) const -> Queue;
	[[nodiscard]] auto getQueue2(const DeviceQueueInfo2 &queueInfo) const -> Queue;
	[[nodiscard]] auto getSubpassShadingMaxWorkgroupSizeHUAWEI(const RenderPass &renderpass) const -> std::expected<Extent2D, Result>;
	[[nodiscard]] auto getTensorMemoryRequirementsARM(const DeviceTensorMemoryRequirementsARM &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getDynamicRenderingTilePropertiesQCOM(const RenderingInfo &renderingInfo) const -> std::expected<TilePropertiesQCOM, Result>;
	[[nodiscard]] auto getEncodedVideoSessionParametersKHR(const VideoEncodeSessionParametersGetInfoKHR &videoSessionParametersInfo, VideoEncodeSessionParametersFeedbackInfoKHR *pFeedbackInfo = nullptr) const -> std::expected<std::vector<std::byte>, Result>;
	[[nodiscard]] auto getEventStatus(const Event &event) const -> Result;
	[[nodiscard]] auto getFenceFdKHR(const FenceGetFdInfoKHR &getFdInfo) const -> std::expected<int, Result>;
	[[nodiscard]] auto getFenceStatus(const Fence &fence) const -> Result;
	[[nodiscard]] auto getFramebufferTilePropertiesQCOM(const Framebuffer &framebuffer) const -> std::expected<std::vector<TilePropertiesQCOM>, Result>;
	[[nodiscard]] auto getGeneratedCommandsMemoryRequirementsEXT(const GeneratedCommandsMemoryRequirementsInfoEXT &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getGeneratedCommandsMemoryRequirementsNV(const GeneratedCommandsMemoryRequirementsInfoNV &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getGpaClockInfoAMD() const -> std::expected<GpaDeviceGetClockInfoAMD, Result>;
	[[nodiscard]] auto getGpaSessionResultsAMD(const GpaSessionAMD &gpaSession, uint32_t sampleID) const -> std::expected<std::vector<std::byte>, Result>;
	[[nodiscard]] auto getGpaSessionStatusAMD(const GpaSessionAMD &gpaSession) const -> Result;
	[[nodiscard]] auto getImageDrmFormatModifierPropertiesEXT(const Image &image) const -> std::expected<ImageDrmFormatModifierPropertiesEXT, Result>;
	[[nodiscard]] auto getImageMemoryRequirements(const Image &image) const -> MemoryRequirements;
	[[nodiscard]] auto getImageMemoryRequirements2(const ImageMemoryRequirementsInfo2 &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getImageOpaqueCaptureDataEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Image>> &images) const -> std::expected<std::vector<HostAddressRangeEXT>, Result>;
	[[nodiscard]] auto getImageOpaqueCaptureDescriptorDataEXT(const ImageCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result;
	[[nodiscard]] auto getImageSparseMemoryRequirements(const Image &image) const -> std::vector<SparseImageMemoryRequirements>;
	[[nodiscard]] auto getImageSparseMemoryRequirements2(const ImageSparseMemoryRequirementsInfo2 &info) const -> std::vector<SparseImageMemoryRequirements2>;
	[[nodiscard]] auto getImageSubresourceLayout(const Image &image, const ImageSubresource &subresource) const -> SubresourceLayout;
	[[nodiscard]] auto getImageSubresourceLayout2(const Image &image, const ImageSubresource2 &subresource) const -> SubresourceLayout2;
	[[nodiscard]] auto getImageViewAddressNVX(const ImageView &imageView) const -> std::expected<ImageViewAddressPropertiesNVX, Result>;
	[[nodiscard]] auto getImageViewHandle64NVX(const ImageViewHandleInfoNVX &info) const -> uint64_t;
	[[nodiscard]] auto getImageViewHandleNVX(const ImageViewHandleInfoNVX &info) const -> uint32_t;
	[[nodiscard]] auto getImageViewOpaqueCaptureDescriptorDataEXT(const ImageViewCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result;
	void getLatencyTimingsLegacyNV(void *pTimings) const;
	[[nodiscard]] auto getLatencyTimingsNV(const SwapchainKHR &swapchain) const -> GetLatencyMarkerInfoNV;
	[[nodiscard]] auto getMemoryFdKHR(const MemoryGetFdInfoKHR &getFdInfo) const -> std::expected<int, Result>;
	[[nodiscard]] auto getMemoryFdPropertiesKHR(ExternalMemoryHandleTypeBits handleType, int fileDescriptor) const -> std::expected<MemoryFdPropertiesKHR, Result>;
	[[nodiscard]] auto getMemoryHostPointerPropertiesEXT(ExternalMemoryHandleTypeBits handleType, const void *pHostPointer) const -> std::expected<MemoryHostPointerPropertiesEXT, Result>;
	[[nodiscard]] auto getMemoryRemoteAddressNV(const MemoryGetRemoteAddressInfoNV &memoryGetRemoteAddressInfo) const -> std::expected<RemoteAddressNV, Result>;
	[[nodiscard]] auto getMicromapBuildSizesEXT(AccelerationStructureBuildTypeKHR buildType, const MicromapBuildInfoEXT &buildInfo) const -> MicromapBuildSizesInfoEXT;
	[[nodiscard]] auto getPartitionedAccelerationStructuresBuildSizesNV(const PartitionedAccelerationStructureInstancesInputNV &info) const -> AccelerationStructureBuildSizesInfoKHR;
	[[nodiscard]] auto getPastPresentationTimingEXT(const PastPresentationTimingInfoEXT &pastPresentationTimingInfo) const -> std::expected<PastPresentationTimingPropertiesEXT, Result>;
	[[nodiscard]] auto getPastPresentationTimingGOOGLE(const SwapchainKHR &swapchain) const -> std::expected<std::vector<PastPresentationTimingGOOGLE>, Result>;
	[[nodiscard]] auto getPerformanceParameterINTEL(PerformanceParameterTypeINTEL parameter) const -> std::expected<PerformanceValueINTEL, Result>;
	[[nodiscard]] auto getPipelineBinaryDataKHR(const PipelineBinaryDataInfoKHR &info, PipelineBinaryKeyKHR *pPipelineBinaryKey) const -> std::expected<std::vector<std::byte>, Result>;
	[[nodiscard]] auto getPipelineCacheData(const PipelineCache &pipelineCache) const -> std::expected<std::vector<std::byte>, Result>;
	[[nodiscard]] auto getPipelineExecutableInternalRepresentationsKHR(const PipelineExecutableInfoKHR &executableInfo) const -> std::expected<std::vector<PipelineExecutableInternalRepresentationKHR>, Result>;
	[[nodiscard]] auto getPipelineExecutablePropertiesKHR(const PipelineInfoKHR &pipelineInfo) const -> std::expected<std::vector<PipelineExecutablePropertiesKHR>, Result>;
	[[nodiscard]] auto getPipelineExecutableStatisticsKHR(const PipelineExecutableInfoKHR &executableInfo) const -> std::expected<std::vector<PipelineExecutableStatisticKHR>, Result>;
	[[nodiscard]] auto getPipelineIndirectAddressNV(const PipelineIndirectDeviceAddressInfoNV &info) const -> DeviceAddress;
	[[nodiscard]] auto getPipelineIndirectMemoryRequirementsNV(const ComputePipelineCreateInfo &createInfo) const -> MemoryRequirements2;
	[[nodiscard]] auto getPipelineKeyKHR(const PipelineCreateInfoKHR *pPipelineCreateInfo = nullptr) const -> std::expected<PipelineBinaryKeyKHR, Result>;
	[[nodiscard]] auto getPipelinePropertiesEXT(const PipelineInfoKHR &pipelineInfo) const -> std::expected<BaseOutStructure, Result>;
	[[nodiscard]] auto getPrivateData(ObjectType objectType, uint64_t objectHandle, const PrivateDataSlot &privateDataSlot) const -> uint64_t;
	[[nodiscard]] auto getQueryPoolResults(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount, std::vector<std::byte> &data, DeviceSize stride, QueryResultFlags flags = {}) const -> Result;
	[[nodiscard]] auto getRayTracingCaptureReplayShaderGroupHandlesKHR(const Pipeline &pipeline, uint32_t firstGroup, uint32_t groupCount, size_t size) const -> std::vector<std::byte>;
	[[nodiscard]] auto getRayTracingShaderGroupHandlesKHR(const Pipeline &pipeline, uint32_t firstGroup, uint32_t groupCount, size_t size) const -> std::vector<std::byte>;
	[[nodiscard]] auto getRayTracingShaderGroupStackSizeKHR(const Pipeline &pipeline, uint32_t group, ShaderGroupShaderKHR groupShader) const -> DeviceSize;
	[[nodiscard]] auto getRefreshCycleDurationGOOGLE(const SwapchainKHR &swapchain) const -> std::expected<RefreshCycleDurationGOOGLE, Result>;
	[[nodiscard]] auto getRenderAreaGranularity(const RenderPass &renderPass) const -> Extent2D;
	[[nodiscard]] auto getRenderingAreaGranularity(const RenderingAreaInfo &renderingAreaInfo) const -> Extent2D;
	[[nodiscard]] auto getSamplerOpaqueCaptureDescriptorDataEXT(const SamplerCaptureDescriptorDataInfoEXT &info, void *pData) const -> Result;
	[[nodiscard]] auto getSemaphoreCounterValue(const Semaphore &semaphore) const -> std::expected<uint64_t, Result>;
	[[nodiscard]] auto getSemaphoreFdKHR(const SemaphoreGetFdInfoKHR &getFdInfo) const -> std::expected<int, Result>;
	[[nodiscard]] auto getShaderBinaryDataEXT(const ShaderEXT &shader) const -> std::expected<std::vector<std::byte>, Result>;
	[[nodiscard]] auto getShaderInfoAMD(const Pipeline &pipeline, ShaderStageBits shaderStage, ShaderInfoTypeAMD infoType) const -> std::expected<std::vector<std::byte>, Result>;
	[[nodiscard]] auto getShaderInstrumentationValuesARM(const ShaderInstrumentationARM &instrumentation, uint32_t *pMetricBlockCount, void *pMetricValues = nullptr) const -> std::expected<ShaderInstrumentationValuesFlagsARM, Result>;
	[[nodiscard]] auto getShaderModuleCreateInfoIdentifierEXT(const ShaderModuleCreateInfo &createInfo) const -> ShaderModuleIdentifierEXT;
	[[nodiscard]] auto getShaderModuleIdentifierEXT(const ShaderModule &shaderModule) const -> ShaderModuleIdentifierEXT;
	[[nodiscard]] auto getSleepStatusLegacyNV() const -> Bool32;
	[[nodiscard]] auto getSwapchainCounterEXT(const SwapchainKHR &swapchain, SurfaceCounterBitsEXT counter) const -> std::expected<uint64_t, Result>;
	[[nodiscard]] auto getSwapchainImagesKHR(const SwapchainKHR &swapchain) const -> std::expected<std::vector<Image>, Result>;
	[[nodiscard]] auto getSwapchainStatusKHR(const SwapchainKHR &swapchain) const -> Result;
	[[nodiscard]] auto getSwapchainTimeDomainPropertiesEXT(const SwapchainKHR &swapchain, SwapchainTimeDomainPropertiesEXT *pSwapchainTimeDomainProperties) const -> std::expected<uint64_t, Result>;
	[[nodiscard]] auto getSwapchainTimingPropertiesEXT(const SwapchainKHR &swapchain, SwapchainTimingPropertiesEXT *pSwapchainTimingProperties) const -> std::expected<uint64_t, Result>;
	[[nodiscard]] auto getTensorMemoryRequirementsARM(const TensorMemoryRequirementsInfoARM &info) const -> MemoryRequirements2;
	[[nodiscard]] auto getTensorOpaqueCaptureDataARM(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<TensorARM>> &tensors) const -> std::expected<std::vector<HostAddressRangeEXT>, Result>;
	[[nodiscard]] auto getTensorOpaqueCaptureDescriptorDataARM(const TensorCaptureDescriptorDataInfoARM &info, void *pData) const -> Result;
	[[nodiscard]] auto getTensorViewOpaqueCaptureDescriptorDataARM(const TensorViewCaptureDescriptorDataInfoARM &info, void *pData) const -> Result;
	[[nodiscard]] auto getValidationCacheDataEXT(const ValidationCacheEXT &validationCache) const -> std::expected<std::vector<std::byte>, Result>;
	[[nodiscard]] auto getVideoSessionMemoryRequirementsKHR(const VideoSessionKHR &videoSession) const -> std::expected<std::vector<VideoSessionMemoryRequirementsKHR>, Result>;
	[[nodiscard]] auto importFenceFdKHR(const ImportFenceFdInfoKHR &importFenceFdInfo) const -> Result;
	[[nodiscard]] auto importSemaphoreFdKHR(const ImportSemaphoreFdInfoKHR &importSemaphoreFdInfo) const -> Result;
	[[nodiscard]] auto initializePerformanceApiINTEL(const InitializePerformanceApiInfoINTEL &initializeInfo) const -> Result;
	[[nodiscard]] auto invalidateMappedMemoryRanges(const impl_Struct::ArrayProxy<MappedMemoryRange> &memoryRanges) const -> Result;
	void latencySleepLegacyNV(const Semaphore &signalSemaphore, uint64_t value) const;
	[[nodiscard]] auto latencySleepNV(const SwapchainKHR &swapchain, const LatencySleepInfoNV &sleepInfo) const -> Result;
	[[nodiscard]] auto mapMemory(const DeviceMemory &memory, DeviceSize offset, DeviceSize size, MemoryMapFlags flags = {}) const -> std::expected<void *, Result>;
	[[nodiscard]] auto mapMemory2(const MemoryMapInfo &memoryMapInfo) const -> std::expected<void *, Result>;
	[[nodiscard]] auto mergePipelineCaches(const PipelineCache &dstCache, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<PipelineCache>> &srcCaches) const -> Result;
	[[nodiscard]] auto mergeValidationCachesEXT(const ValidationCacheEXT &dstCache, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<ValidationCacheEXT>> &srcCaches) const -> Result;
	[[nodiscard]] auto registerCustomBorderColorEXT(const SamplerCustomBorderColorCreateInfoEXT &borderColor, Bool32 requestIndex, uint32_t *pIndex) const -> Result;
	[[nodiscard]] auto registerEventEXT(const DeviceEventInfoEXT &deviceEventInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueFence, Result>;
	[[nodiscard]] auto registerDisplayEventEXT(const DisplayKHR &display, const DisplayEventInfoEXT &displayEventInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueFence, Result>;
	[[nodiscard]] auto releaseCapturedPipelineDataKHR(const ReleaseCapturedPipelineDataInfoKHR &info, const AllocationCallbacks *pAllocator = nullptr) const -> Result;
	void releaseProfilingLockKHR() const;
	[[nodiscard]] auto releaseSwapchainImagesKHR(const ReleaseSwapchainImagesInfoKHR &releaseInfo) const -> Result;
	[[nodiscard]] auto resetCommandPool(const CommandPool &commandPool, CommandPoolResetFlags flags = {}) const -> Result;
	[[nodiscard]] auto resetDescriptorPool(const DescriptorPool &descriptorPool, DescriptorPoolResetFlags flags = {}) const -> Result;
	[[nodiscard]] auto resetEvent(const Event &event) const -> Result;
	[[nodiscard]] auto resetFences(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Fence>> &fences) const -> Result;
	[[nodiscard]] auto resetGpaSessionAMD(const GpaSessionAMD &gpaSession) const -> Result;
	void resetQueryPool(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount) const;
	[[nodiscard]] auto setDebugUtilsObjectNameEXT(const DebugUtilsObjectNameInfoEXT &nameInfo) const -> Result;
	[[nodiscard]] auto setDebugUtilsObjectTagEXT(const DebugUtilsObjectTagInfoEXT &tagInfo) const -> Result;
	void setMemoryPriorityEXT(const DeviceMemory &memory, float priority) const;
	[[nodiscard]] auto setEvent(const Event &event) const -> Result;
	[[nodiscard]] auto setGpaClockModeAMD(GpaDeviceClockModeInfoAMD *pInfo) const -> Result;
	void setHdrMetadataEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<SwapchainKHR>> &swapchains, const impl_Struct::ArrayProxy<HdrMetadataEXT> &metadata) const;
	void setLatencyMarkerLegacyNV(uint64_t frameID, uint32_t marker) const;
	void setLatencyMarkerNV(const SwapchainKHR &swapchain, const SetLatencyMarkerInfoNV &latencyMarkerInfo) const;
	void setLatencySleepModeLegacyNV(Bool32 lowLatencyMode, Bool32 lowLatencyBoost, uint32_t minimumIntervalUs) const;
	[[nodiscard]] auto setLatencySleepModeNV(const SwapchainKHR &swapchain, const LatencySleepModeInfoNV &sleepModeInfo) const -> Result;
	void setLocalDimmingAMD(const SwapchainKHR &swapChain, Bool32 localDimmingEnable) const;
	[[nodiscard]] auto setPrivateData(ObjectType objectType, uint64_t objectHandle, const PrivateDataSlot &privateDataSlot, uint64_t data) const -> Result;
	[[nodiscard]] auto setSwapchainPresentTimingQueueSizeEXT(const SwapchainKHR &swapchain, uint32_t size) const -> Result;
	void shutdownLatencyLegacyNV() const;
	[[nodiscard]] auto signalSemaphore(const SemaphoreSignalInfo &signalInfo) const -> Result;
	[[nodiscard]] auto transitionImageLayout(const impl_Struct::ArrayProxy<HostImageLayoutTransitionInfo> &transitions) const -> Result;
	void trimCommandPool(const CommandPool &commandPool, CommandPoolTrimFlags flags = {}) const;
	void uninitializePerformanceApiINTEL() const;
	void unmapMemory(const DeviceMemory &memory) const;
	[[nodiscard]] auto unmapMemory2(const MemoryUnmapInfo &memoryUnmapInfo) const -> Result;
	void unregisterCustomBorderColorEXT(uint32_t index) const;
	void updateDescriptorSetWithTemplate(const DescriptorSet &descriptorSet, const DescriptorUpdateTemplate &descriptorUpdateTemplate, const void *pData) const;
	void updateDescriptorSets(const impl_Struct::ArrayProxy<WriteDescriptorSet> &descriptorWrites, const impl_Struct::ArrayProxy<CopyDescriptorSet> &descriptorCopies) const;
	void updateIndirectExecutionSetPipelineEXT(const IndirectExecutionSetEXT &indirectExecutionSet, const impl_Struct::ArrayProxy<WriteIndirectExecutionSetPipelineEXT> &executionSetWrites) const;
	void updateIndirectExecutionSetShaderEXT(const IndirectExecutionSetEXT &indirectExecutionSet, const impl_Struct::ArrayProxy<WriteIndirectExecutionSetShaderEXT> &executionSetWrites) const;
	[[nodiscard]] auto updateVideoSessionParametersKHR(const VideoSessionParametersKHR &videoSessionParameters, const VideoSessionParametersUpdateInfoKHR &updateInfo) const -> Result;
	[[nodiscard]] auto waitForFences(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Fence>> &fences, Bool32 waitAll, uint64_t timeout) const -> Result;
	[[nodiscard]] auto waitForPresent2KHR(const SwapchainKHR &swapchain, const PresentWait2InfoKHR &presentWait2Info) const -> Result;
	[[nodiscard]] auto waitForPresentKHR(const SwapchainKHR &swapchain, uint64_t presentId, uint64_t timeout) const -> Result;
	[[nodiscard]] auto waitSemaphores(const SemaphoreWaitInfo &waitInfo, uint64_t timeout) const -> Result;
	
	[[deprecated("supersededby: writeAccelerationStructuresPropertiesKHR")]]
	[[nodiscard]] auto writeAccelerationStructuresPropertiesKHR(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureKHR>> &accelerationStructures, QueryType queryType, std::vector<std::byte> &data, size_t stride) const -> Result;
	
	[[deprecated("supersededby: writeMicromapsPropertiesEXT")]]
	[[nodiscard]] auto writeMicromapsPropertiesEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<MicromapEXT>> &micromaps, QueryType queryType, std::vector<std::byte> &data, size_t stride) const -> Result;
	[[nodiscard]] auto writeResourceDescriptorsEXT(const impl_Struct::ArrayProxy<ResourceDescriptorInfoEXT> &resources, const impl_Struct::ArrayProxy<HostAddressRangeEXT> &descriptors) const -> Result;
	[[nodiscard]] auto writeSamplerDescriptorsEXT(const impl_Struct::ArrayProxy<SamplerCreateInfo> &samplers, const impl_Struct::ArrayProxy<HostAddressRangeEXT> &descriptors) const -> Result;
	#ifdef VK_ENABLE_BETA_EXTENSIONS
		[[nodiscard]] auto createCudaFunctionNV(const CudaFunctionCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueCudaFunctionNV, Result>;
		[[nodiscard]] auto createCudaModuleNV(const CudaModuleCreateInfoNV &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueCudaModuleNV, Result>;
		[[nodiscard]] auto createExecutionGraphPipelinesAMDX(const PipelineCache &pipelineCache, const impl_Struct::ArrayProxy<ExecutionGraphPipelineCreateInfoAMDX> &createInfos, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<std::vector<UniquePipeline>, Result>;
		[[nodiscard]] auto getCudaModuleCacheNV(const CudaModuleNV &module) const -> std::expected<std::vector<std::byte>, Result>;
		[[nodiscard]] auto getExecutionGraphPipelineNodeIndexAMDX(const Pipeline &executionGraph, const PipelineShaderStageNodeCreateInfoAMDX &nodeInfo) const -> std::expected<uint32_t, Result>;
		[[nodiscard]] auto getExecutionGraphPipelineScratchSizeAMDX(const Pipeline &executionGraph) const -> std::expected<ExecutionGraphPipelineScratchSizeAMDX, Result>;
	#endif // VK_ENABLE_BETA_EXTENSIONS
	#ifdef VK_USE_PLATFORM_ANDROID_KHR
		[[nodiscard]] auto getAndroidHardwareBufferPropertiesANDROID(const struct AHardwareBuffer *buffer) const -> std::expected<AndroidHardwareBufferPropertiesANDROID, Result>;
		[[nodiscard]] auto getMemoryAndroidHardwareBufferANDROID(const MemoryGetAndroidHardwareBufferInfoANDROID &info) const -> std::expected<AHardwareBuffer, Result>;
	#endif // VK_USE_PLATFORM_ANDROID_KHR
	#ifdef VK_USE_PLATFORM_FUCHSIA
		[[nodiscard]] auto createBufferCollectionFUCHSIA(const BufferCollectionCreateInfoFUCHSIA &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueBufferCollectionFUCHSIA, Result>;
		[[nodiscard]] auto getBufferCollectionPropertiesFUCHSIA(const BufferCollectionFUCHSIA &collection) const -> std::expected<BufferCollectionPropertiesFUCHSIA, Result>;
		[[nodiscard]] auto getMemoryZirconHandleFUCHSIA(const MemoryGetZirconHandleInfoFUCHSIA &getZirconHandleInfo) const -> std::expected<zx_handle_t, Result>;
		[[nodiscard]] auto getMemoryZirconHandlePropertiesFUCHSIA(ExternalMemoryHandleTypeBits handleType, zx_handle_t zirconHandle) const -> std::expected<MemoryZirconHandlePropertiesFUCHSIA, Result>;
		[[nodiscard]] auto getSemaphoreZirconHandleFUCHSIA(const SemaphoreGetZirconHandleInfoFUCHSIA &getZirconHandleInfo) const -> std::expected<zx_handle_t, Result>;
		[[nodiscard]] auto importSemaphoreZirconHandleFUCHSIA(const ImportSemaphoreZirconHandleInfoFUCHSIA &importSemaphoreZirconHandleInfo) const -> Result;
		[[nodiscard]] auto setBufferCollectionBufferConstraintsFUCHSIA(const BufferCollectionFUCHSIA &collection, const BufferConstraintsInfoFUCHSIA &bufferConstraintsInfo) const -> Result;
		[[nodiscard]] auto setBufferCollectionImageConstraintsFUCHSIA(const BufferCollectionFUCHSIA &collection, const ImageConstraintsInfoFUCHSIA &imageConstraintsInfo) const -> Result;
	#endif // VK_USE_PLATFORM_FUCHSIA
	#ifdef VK_USE_PLATFORM_METAL_EXT
		void exportMetalObjectsEXT(ExportMetalObjectsInfoEXT *pMetalObjectsInfo) const;
		[[nodiscard]] auto getMemoryMetalHandleEXT(const MemoryGetMetalHandleInfoEXT &getMetalHandleInfo, void **pHandle) const -> Result;
		[[nodiscard]] auto getMemoryMetalHandlePropertiesEXT(ExternalMemoryHandleTypeBits handleType, const void *pHandle) const -> std::expected<MemoryMetalHandlePropertiesEXT, Result>;
	#endif // VK_USE_PLATFORM_METAL_EXT
	#ifdef VK_USE_PLATFORM_OHOS
		[[nodiscard]] auto getMemoryNativeBufferOHOS(const MemoryGetNativeBufferInfoOHOS &info) const -> std::expected<OH_NativeBuffer, Result>;
		[[nodiscard]] auto getNativeBufferPropertiesOHOS(const struct OH_NativeBuffer *buffer) const -> std::expected<NativeBufferPropertiesOHOS, Result>;
	#endif // VK_USE_PLATFORM_OHOS
	#ifdef VK_USE_PLATFORM_SCREEN_QNX
		[[nodiscard]] auto getScreenBufferPropertiesQNX(const struct _screen_buffer *buffer) const -> std::expected<ScreenBufferPropertiesQNX, Result>;
	#endif // VK_USE_PLATFORM_SCREEN_QNX
	#ifdef VK_USE_PLATFORM_WIN32_KHR
		[[nodiscard]] auto acquireFullScreenExclusiveModeEXT(const SwapchainKHR &swapchain) const -> Result;
		[[nodiscard]] auto getGroupSurfacePresentModes2EXT(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<DeviceGroupPresentModeFlagsKHR, Result>;
		[[nodiscard]] auto getFenceWin32HandleKHR(const FenceGetWin32HandleInfoKHR &getWin32HandleInfo) const -> std::expected<HANDLE, Result>;
		[[nodiscard]] auto getMemoryWin32HandleKHR(const MemoryGetWin32HandleInfoKHR &getWin32HandleInfo) const -> std::expected<HANDLE, Result>;
		[[nodiscard]] auto getMemoryWin32HandleNV(const DeviceMemory &memory, ExternalMemoryHandleTypeFlagsNV handleType) const -> std::expected<HANDLE, Result>;
		[[nodiscard]] auto getMemoryWin32HandlePropertiesKHR(ExternalMemoryHandleTypeBits handleType, HANDLE handle) const -> std::expected<MemoryWin32HandlePropertiesKHR, Result>;
		[[nodiscard]] auto getSemaphoreWin32HandleKHR(const SemaphoreGetWin32HandleInfoKHR &getWin32HandleInfo) const -> std::expected<HANDLE, Result>;
		[[nodiscard]] auto importFenceWin32HandleKHR(const ImportFenceWin32HandleInfoKHR &importFenceWin32HandleInfo) const -> Result;
		[[nodiscard]] auto importSemaphoreWin32HandleKHR(const ImportSemaphoreWin32HandleInfoKHR &importSemaphoreWin32HandleInfo) const -> Result;
		[[nodiscard]] auto releaseFullScreenExclusiveModeEXT(const SwapchainKHR &swapchain) const -> Result;
	#endif // VK_USE_PLATFORM_WIN32_KHR
};
struct PhysicalDevice : public impl_Objects::Object<Handle::PhysicalDevice> {
	using Object::Object;
	PhysicalDevice() = default;
	[[nodiscard]] auto acquireDrmDisplayEXT(int32_t drmFd, const DisplayKHR &display) const -> Result;
	[[nodiscard]] auto createDevice(const DeviceCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDevice, Result>;
	[[nodiscard]] auto createDisplayModeKHR(const DisplayKHR &display, const DisplayModeCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<DisplayModeKHR, Result>;
	[[nodiscard]] auto enumerateDeviceExtensionProperties(const char *pLayerName = nullptr) const -> std::expected<std::vector<ExtensionProperties>, Result>;
	[[nodiscard]] auto enumerateDeviceLayerProperties() const -> std::expected<std::vector<LayerProperties>, Result>;
	[[nodiscard]] auto enumerateQueueFamilyPerformanceCountersByRegionARM(uint32_t queueFamilyIndex) const -> std::expected<std::tuple<std::vector<PerformanceCounterDescriptionARM>, std::vector<PerformanceCounterARM>>, Result>;
	[[nodiscard]] auto enumerateQueueFamilyPerformanceQueryCountersKHR(uint32_t queueFamilyIndex) const -> std::expected<std::tuple<std::vector<PerformanceCounterDescriptionKHR>, std::vector<PerformanceCounterKHR>>, Result>;
	[[nodiscard]] auto enumerateShaderInstrumentationMetricsARM() const -> std::expected<std::vector<ShaderInstrumentationMetricDescriptionARM>, Result>;
	[[nodiscard]] auto getDisplayModeProperties2KHR(const DisplayKHR &display) const -> std::expected<std::vector<DisplayModeProperties2KHR>, Result>;
	[[nodiscard]] auto getDisplayModePropertiesKHR(const DisplayKHR &display) const -> std::expected<std::vector<DisplayModePropertiesKHR>, Result>;
	[[nodiscard]] auto getDisplayPlaneCapabilities2KHR(const DisplayPlaneInfo2KHR &displayPlaneInfo) const -> std::expected<DisplayPlaneCapabilities2KHR, Result>;
	[[nodiscard]] auto getDisplayPlaneCapabilitiesKHR(const DisplayModeKHR &mode, uint32_t planeIndex) const -> std::expected<DisplayPlaneCapabilitiesKHR, Result>;
	[[nodiscard]] auto getDisplayPlaneSupportedDisplaysKHR(uint32_t planeIndex) const -> std::expected<std::vector<DisplayKHR>, Result>;
	[[nodiscard]] auto getDrmDisplayEXT(int32_t drmFd, uint32_t connectorId) const -> std::expected<UniqueDisplayKHR, Result>;
	[[nodiscard]] auto getCalibrateableTimeDomainsKHR() const -> std::expected<std::vector<TimeDomainKHR>, Result>;
	[[nodiscard]] auto getCooperativeMatrixFlexibleDimensionsPropertiesNV() const -> std::expected<std::vector<CooperativeMatrixFlexibleDimensionsPropertiesNV>, Result>;
	[[nodiscard]] auto getCooperativeMatrixProperties2EXT(const PhysicalDeviceCooperativeMatrixInfo2EXT &cooperativeMatrixInfo) const -> std::expected<std::vector<CooperativeMatrixProperties2EXT>, Result>;
	[[nodiscard]] auto getCooperativeMatrixPropertiesKHR() const -> std::expected<std::vector<CooperativeMatrixPropertiesKHR>, Result>;
	[[nodiscard]] auto getCooperativeMatrixPropertiesNV() const -> std::expected<std::vector<CooperativeMatrixPropertiesNV>, Result>;
	[[nodiscard]] auto getCooperativeVectorPropertiesNV() const -> std::expected<std::vector<CooperativeVectorPropertiesNV>, Result>;
	[[nodiscard]] auto getDescriptorSizeEXT(DescriptorType descriptorType) const -> DeviceSize;
	[[nodiscard]] auto getDisplayPlaneProperties2KHR() const -> std::expected<std::vector<DisplayPlaneProperties2KHR>, Result>;
	[[nodiscard]] auto getDisplayPlanePropertiesKHR() const -> std::expected<std::vector<DisplayPlanePropertiesKHR>, Result>;
	[[nodiscard]] auto getDisplayProperties2KHR() const -> std::expected<std::vector<DisplayProperties2KHR>, Result>;
	[[nodiscard]] auto getDisplayPropertiesKHR() const -> std::expected<std::vector<DisplayPropertiesKHR>, Result>;
	[[nodiscard]] auto getExternalBufferProperties(const PhysicalDeviceExternalBufferInfo &externalBufferInfo) const -> ExternalBufferProperties;
	[[nodiscard]] auto getExternalFenceProperties(const PhysicalDeviceExternalFenceInfo &externalFenceInfo) const -> ExternalFenceProperties;
	[[nodiscard]] auto getExternalImageFormatPropertiesNV(Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags = {}, ExternalMemoryHandleTypeFlagsNV externalHandleType = {}) const -> std::expected<ExternalImageFormatPropertiesNV, Result>;
	[[nodiscard]] auto getExternalSemaphoreProperties(const PhysicalDeviceExternalSemaphoreInfo &externalSemaphoreInfo) const -> ExternalSemaphoreProperties;
	[[nodiscard]] auto getExternalTensorPropertiesARM(const PhysicalDeviceExternalTensorInfoARM &externalTensorInfo) const -> ExternalTensorPropertiesARM;
	
	[[deprecated("supersededby: getFeatures2")]]
	[[nodiscard]] auto getFeatures() const -> PhysicalDeviceFeatures;
	[[nodiscard]] auto getFeatures2() const -> PhysicalDeviceFeatures2;
	
	[[deprecated("supersededby: getFormatProperties2")]]
	[[nodiscard]] auto getFormatProperties(Format format) const -> FormatProperties;
	[[nodiscard]] auto getFormatProperties2(Format format) const -> FormatProperties2;
	[[nodiscard]] auto getFragmentShadingRatesKHR() const -> std::expected<std::vector<PhysicalDeviceFragmentShadingRateKHR>, Result>;
	
	[[deprecated("supersededby: getImageFormatProperties2")]]
	[[nodiscard]] auto getImageFormatProperties(Format format, ImageType type, ImageTiling tiling, ImageUsageFlags usage, ImageCreateFlags flags = {}) const -> std::expected<ImageFormatProperties, Result>;
	[[nodiscard]] auto getImageFormatProperties2(const PhysicalDeviceImageFormatInfo2 &imageFormatInfo) const -> std::expected<ImageFormatProperties2, Result>;
	
	[[deprecated("supersededby: getMemoryProperties2")]]
	[[nodiscard]] auto getMemoryProperties() const -> PhysicalDeviceMemoryProperties;
	[[nodiscard]] auto getMemoryProperties2() const -> PhysicalDeviceMemoryProperties2;
	[[nodiscard]] auto getMultisamplePropertiesEXT(SampleCountBits samples) const -> MultisamplePropertiesEXT;
	[[nodiscard]] auto getOpticalFlowImageFormatsNV(const OpticalFlowImageFormatInfoNV &opticalFlowImageFormatInfo) const -> std::expected<std::vector<OpticalFlowImageFormatPropertiesNV>, Result>;
	[[nodiscard]] auto getPresentRectanglesKHR(const SurfaceKHR &surface) const -> std::expected<std::vector<Rect2D>, Result>;
	
	[[deprecated("supersededby: getProperties2")]]
	[[nodiscard]] auto getProperties() const -> PhysicalDeviceProperties;
	[[nodiscard]] auto getProperties2() const -> PhysicalDeviceProperties2;
	[[nodiscard]] auto getQueueFamilyDataGraphEngineOperationPropertiesARM(uint32_t queueFamilyIndex, const QueueFamilyDataGraphPropertiesARM &queueFamilyDataGraphProperties) const -> std::expected<BaseOutStructure, Result>;
	[[nodiscard]] auto getQueueFamilyDataGraphOpticalFlowImageFormatsARM(uint32_t queueFamilyIndex, const QueueFamilyDataGraphPropertiesARM &queueFamilyDataGraphProperties, const DataGraphOpticalFlowImageFormatInfoARM &opticalFlowImageFormatInfo) const -> std::expected<std::vector<DataGraphOpticalFlowImageFormatPropertiesARM>, Result>;
	[[nodiscard]] auto getQueueFamilyDataGraphProcessingEnginePropertiesARM(const PhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM &queueFamilyDataGraphProcessingEngineInfo) const -> QueueFamilyDataGraphProcessingEnginePropertiesARM;
	[[nodiscard]] auto getQueueFamilyDataGraphPropertiesARM(uint32_t queueFamilyIndex) const -> std::expected<std::vector<QueueFamilyDataGraphPropertiesARM>, Result>;
	[[nodiscard]] auto getQueueFamilyPerformanceQueryPassesKHR(const QueryPoolPerformanceCreateInfoKHR &performanceQueryCreateInfo) const -> uint32_t;
	
	[[deprecated("supersededby: getQueueFamilyProperties2")]]
	[[nodiscard]] auto getQueueFamilyProperties() const -> std::vector<QueueFamilyProperties>;
	[[nodiscard]] auto getQueueFamilyProperties2() const -> std::vector<QueueFamilyProperties2>;
	
	[[deprecated("supersededby: getSparseImageFormatProperties2")]]
	[[nodiscard]] auto getSparseImageFormatProperties(Format format, ImageType type, SampleCountBits samples, ImageUsageFlags usage, ImageTiling tiling) const -> std::vector<SparseImageFormatProperties>;
	[[nodiscard]] auto getSparseImageFormatProperties2(const PhysicalDeviceSparseImageFormatInfo2 &formatInfo) const -> std::vector<SparseImageFormatProperties2>;
	[[nodiscard]] auto getSupportedFramebufferMixedSamplesCombinationsNV() const -> std::expected<std::vector<FramebufferMixedSamplesCombinationNV>, Result>;
	[[nodiscard]] auto getSurfaceCapabilities2EXT(const SurfaceKHR &surface) const -> std::expected<SurfaceCapabilities2EXT, Result>;
	[[nodiscard]] auto getSurfaceCapabilities2KHR(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<SurfaceCapabilities2KHR, Result>;
	
	[[deprecated("supersededby: getSurfaceCapabilities2KHR")]]
	[[nodiscard]] auto getSurfaceCapabilitiesKHR(const SurfaceKHR &surface) const -> std::expected<SurfaceCapabilitiesKHR, Result>;
	[[nodiscard]] auto getSurfaceFormats2KHR(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<std::vector<SurfaceFormat2KHR>, Result>;
	
	[[deprecated("supersededby: getSurfaceFormats2KHR")]]
	[[nodiscard]] auto getSurfaceFormatsKHR(const SurfaceKHR &surface = {}) const -> std::expected<std::vector<SurfaceFormatKHR>, Result>;
	[[nodiscard]] auto getSurfacePresentModesKHR(const SurfaceKHR &surface = {}) const -> std::expected<std::vector<PresentModeKHR>, Result>;
	[[nodiscard]] auto getSurfaceSupportKHR(uint32_t queueFamilyIndex, const SurfaceKHR &surface) const -> std::expected<Bool32, Result>;
	[[nodiscard]] auto getToolProperties() const -> std::expected<std::vector<PhysicalDeviceToolProperties>, Result>;
	[[nodiscard]] auto getVideoCapabilitiesKHR(const VideoProfileInfoKHR &videoProfile) const -> std::expected<VideoCapabilitiesKHR, Result>;
	[[nodiscard]] auto getVideoEncodeQualityLevelPropertiesKHR(const PhysicalDeviceVideoEncodeQualityLevelInfoKHR &qualityLevelInfo) const -> std::expected<VideoEncodeQualityLevelPropertiesKHR, Result>;
	[[nodiscard]] auto getVideoFormatPropertiesKHR(const PhysicalDeviceVideoFormatInfoKHR &videoFormatInfo) const -> std::expected<std::vector<VideoFormatPropertiesKHR>, Result>;
	#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
		[[nodiscard]] auto getDirectFBPresentationSupportEXT(uint32_t queueFamilyIndex, IDirectFB *dfb) const -> Bool32;
	#endif // VK_USE_PLATFORM_DIRECTFB_EXT
	#ifdef VK_USE_PLATFORM_SCREEN_QNX
		[[nodiscard]] auto getScreenPresentationSupportQNX(uint32_t queueFamilyIndex, struct _screen_window *window) const -> Bool32;
	#endif // VK_USE_PLATFORM_SCREEN_QNX
	#ifdef VK_USE_PLATFORM_UBM_SEC
		[[nodiscard]] auto getUbmPresentationSupportSEC(uint32_t queueFamilyIndex, struct ubm_device *device) const -> Bool32;
	#endif // VK_USE_PLATFORM_UBM_SEC
	#ifdef VK_USE_PLATFORM_WAYLAND_KHR
		[[nodiscard]] auto getWaylandPresentationSupportKHR(uint32_t queueFamilyIndex, struct wl_display *display) const -> Bool32;
	#endif // VK_USE_PLATFORM_WAYLAND_KHR
	#ifdef VK_USE_PLATFORM_WIN32_KHR
		[[nodiscard]] auto acquireWinrtDisplayNV(const DisplayKHR &display) const -> Result;
		[[nodiscard]] auto getSurfacePresentModes2EXT(const PhysicalDeviceSurfaceInfo2KHR &surfaceInfo) const -> std::expected<std::vector<PresentModeKHR>, Result>;
		[[nodiscard]] auto getWin32PresentationSupportKHR(uint32_t queueFamilyIndex) const -> Bool32;
		[[nodiscard]] auto getWinrtDisplayNV(uint32_t deviceRelativeId) const -> std::expected<DisplayKHR, Result>;
	#endif // VK_USE_PLATFORM_WIN32_KHR
	#ifdef VK_USE_PLATFORM_XCB_KHR
		[[nodiscard]] auto getXcbPresentationSupportKHR(uint32_t queueFamilyIndex, xcb_connection_t *connection, xcb_visualid_t visual_id) const -> Bool32;
	#endif // VK_USE_PLATFORM_XCB_KHR
	#ifdef VK_USE_PLATFORM_XLIB_KHR
		[[nodiscard]] auto getXlibPresentationSupportKHR(uint32_t queueFamilyIndex, Display *dpy, VisualID visualID) const -> Bool32;
	#endif // VK_USE_PLATFORM_XLIB_KHR
	#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
		[[nodiscard]] auto acquireXlibDisplayEXT(Display *dpy, const DisplayKHR &display) const -> Result;
		[[nodiscard]] auto getRandROutputDisplayEXT(Display *dpy, RROutput rrOutput) const -> std::expected<DisplayKHR, Result>;
	#endif // VK_USE_PLATFORM_XLIB_XRANDR_EXT
};
struct Instance : public impl_Objects::Object<Handle::Instance> {
	using Object::Object;
	[[nodiscard]] auto adoptForignSurfaceKHR(SurfaceKHR&& surface) const -> UniqueSurfaceKHR;
	Instance() = default;
	[[nodiscard]] auto createDebugReportCallbackEXT(const DebugReportCallbackCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDebugReportCallbackEXT, Result>;
	[[nodiscard]] auto createDebugUtilsMessengerEXT(const DebugUtilsMessengerCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueDebugUtilsMessengerEXT, Result>;
	[[nodiscard]] auto createDisplayPlaneSurfaceKHR(const DisplaySurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	[[nodiscard]] auto createHeadlessSurfaceEXT(const HeadlessSurfaceCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	void debugReportMessageEXT(DebugReportFlagsEXT flags, DebugReportObjectTypeEXT objectType, uint64_t object, size_t location, int32_t messageCode, const char *pLayerPrefix, const char *pMessage) const;
	[[nodiscard]] auto enumeratePhysicalDeviceGroups() const -> std::expected<std::vector<PhysicalDeviceGroupProperties>, Result>;
	[[nodiscard]] auto enumeratePhysicalDevices() const -> std::expected<std::vector<PhysicalDevice>, Result>;
	void submitDebugUtilsMessageEXT(DebugUtilsMessageSeverityBitsEXT messageSeverity, DebugUtilsMessageTypeFlagsEXT messageTypes, const DebugUtilsMessengerCallbackDataEXT &callbackData) const;
	#ifdef VK_USE_PLATFORM_ANDROID_KHR
		[[nodiscard]] auto createAndroidSurfaceKHR(const AndroidSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_ANDROID_KHR
	#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
		[[nodiscard]] auto createDirectFBSurfaceEXT(const DirectFBSurfaceCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_DIRECTFB_EXT
	#ifdef VK_USE_PLATFORM_FUCHSIA
		[[nodiscard]] auto createImagePipeSurfaceFUCHSIA(const ImagePipeSurfaceCreateInfoFUCHSIA &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_FUCHSIA
	#ifdef VK_USE_PLATFORM_GGP
		[[nodiscard]] auto createStreamDescriptorSurfaceGGP(const StreamDescriptorSurfaceCreateInfoGGP &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_GGP
	#ifdef VK_USE_PLATFORM_IOS_MVK
		[[nodiscard]] auto createIOSSurfaceMVK(const IOSSurfaceCreateInfoMVK &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_IOS_MVK
	#ifdef VK_USE_PLATFORM_MACOS_MVK
		[[nodiscard]] auto createMacOSSurfaceMVK(const MacOSSurfaceCreateInfoMVK &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_MACOS_MVK
	#ifdef VK_USE_PLATFORM_METAL_EXT
		[[nodiscard]] auto createMetalSurfaceEXT(const MetalSurfaceCreateInfoEXT &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_METAL_EXT
	#ifdef VK_USE_PLATFORM_OHOS
		[[nodiscard]] auto createSurfaceOHOS(const SurfaceCreateInfoOHOS &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_OHOS
	#ifdef VK_USE_PLATFORM_SCREEN_QNX
		[[nodiscard]] auto createScreenSurfaceQNX(const ScreenSurfaceCreateInfoQNX &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_SCREEN_QNX
	#ifdef VK_USE_PLATFORM_UBM_SEC
		[[nodiscard]] auto createUbmSurfaceSEC(const UbmSurfaceCreateInfoSEC &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_UBM_SEC
	#ifdef VK_USE_PLATFORM_VI_NN
		[[nodiscard]] auto createViSurfaceNN(const ViSurfaceCreateInfoNN &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_VI_NN
	#ifdef VK_USE_PLATFORM_WAYLAND_KHR
		[[nodiscard]] auto createWaylandSurfaceKHR(const WaylandSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_WAYLAND_KHR
	#ifdef VK_USE_PLATFORM_WIN32_KHR
		[[nodiscard]] auto createWin32SurfaceKHR(const Win32SurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_WIN32_KHR
	#ifdef VK_USE_PLATFORM_XCB_KHR
		[[nodiscard]] auto createXcbSurfaceKHR(const XcbSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_XCB_KHR
	#ifdef VK_USE_PLATFORM_XLIB_KHR
		[[nodiscard]] auto createXlibSurfaceKHR(const XlibSurfaceCreateInfoKHR &createInfo, const AllocationCallbacks *pAllocator = nullptr) const -> std::expected<UniqueSurfaceKHR, Result>;
	#endif // VK_USE_PLATFORM_XLIB_KHR
};
auto createInstance(const InstanceCreateInfo &createInfo, const AllocationCallbacks *pAllocator = nullptr) -> std::expected<UniqueInstance, Result>;
auto enumerateInstanceExtensionProperties(const char *pLayerName = nullptr) -> std::expected<std::vector<ExtensionProperties>, Result>;
auto enumerateInstanceLayerProperties() -> std::expected<std::vector<LayerProperties>, Result>;
auto enumerateInstanceVersion() -> std::expected<uint32_t, Result>;
} // namespace VkBindings
