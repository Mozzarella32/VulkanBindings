#include "VkBindings/BaseTypes.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Handles.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/StructTemplatesInterface.hpp"

#include <array>
#include <cstdint>

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
auto CommandBuffer::begin(const CommandBufferBeginInfo &beginInfo) const -> Result {
	return getDeviceTable().beginCommandBuffer(getHandle(), (&beginInfo));
}
void CommandBuffer::beginConditionalRendering2EXT(const ConditionalRenderingBeginInfo2EXT &conditionalRenderingBegin) const {
	getDeviceTable().cmdBeginConditionalRendering2EXT(getHandle(), (&conditionalRenderingBegin));
}
void CommandBuffer::beginConditionalRenderingEXT(const ConditionalRenderingBeginInfoEXT &conditionalRenderingBegin) const {
	getDeviceTable().cmdBeginConditionalRenderingEXT(getHandle(), (&conditionalRenderingBegin));
}
void CommandBuffer::beginCustomResolveEXT(const BeginCustomResolveInfoEXT *pBeginCustomResolveInfo) const {
	getDeviceTable().cmdBeginCustomResolveEXT(getHandle(), pBeginCustomResolveInfo);
}
void CommandBuffer::beginDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const {
	getDeviceTable().cmdBeginDebugUtilsLabelEXT(getHandle(), (&labelInfo));
}
auto CommandBuffer::beginGpaSampleAMD(const GpaSessionAMD &gpaSession, const GpaSampleBeginInfoAMD &gpaSampleBeginInfo, uint32_t *pSampleID) const -> Result {
	return getDeviceTable().cmdBeginGpaSampleAMD(getHandle(), gpaSession, (&gpaSampleBeginInfo), pSampleID);
}
auto CommandBuffer::beginGpaSessionAMD(const GpaSessionAMD &gpaSession) const -> Result {
	return getDeviceTable().cmdBeginGpaSessionAMD(getHandle(), gpaSession);
}
void CommandBuffer::beginPerTileExecutionQCOM(const PerTileBeginInfoQCOM &perTileBeginInfo) const {
	getDeviceTable().cmdBeginPerTileExecutionQCOM(getHandle(), (&perTileBeginInfo));
}
void CommandBuffer::beginQuery(const QueryPool &queryPool, uint32_t query, QueryControlFlags flags) const {
	getDeviceTable().cmdBeginQuery(getHandle(), queryPool, query, flags);
}
void CommandBuffer::beginQueryIndexedEXT(const QueryPool &queryPool, uint32_t query, QueryControlFlags flags, uint32_t index) const {
	getDeviceTable().cmdBeginQueryIndexedEXT(getHandle(), queryPool, query, flags, index);
}
void CommandBuffer::beginRenderPass(const RenderPassBeginInfo &renderPassBegin, SubpassContents contents) const {
	getDeviceTable().cmdBeginRenderPass(getHandle(), (&renderPassBegin), contents);
}
void CommandBuffer::beginRenderPass2(const RenderPassBeginInfo &renderPassBegin, const SubpassBeginInfo &subpassBeginInfo) const {
	getDeviceTable().cmdBeginRenderPass2(getHandle(), (&renderPassBegin), (&subpassBeginInfo));
}
void CommandBuffer::beginRendering(const RenderingInfo &renderingInfo) const {
	getDeviceTable().cmdBeginRendering(getHandle(), (&renderingInfo));
}
void CommandBuffer::beginShaderInstrumentationARM(const ShaderInstrumentationARM &instrumentation) const {
	getDeviceTable().cmdBeginShaderInstrumentationARM(getHandle(), instrumentation);
}
void CommandBuffer::beginTransformFeedback2EXT(uint32_t firstCounterRange, const impl_Struct::ArrayProxy<BindTransformFeedbackBuffer2InfoEXT> &counterInfos) const {
	getDeviceTable().cmdBeginTransformFeedback2EXT(getHandle(), firstCounterRange, static_cast<uint32_t>(counterInfos.size()), counterInfos.data());
}
void CommandBuffer::beginTransformFeedbackEXT(uint32_t firstCounterBuffer, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &counterBuffers, const impl_Struct::ArrayProxy<DeviceSize> &counterBufferOffsets) const {
	getDeviceTable().cmdBeginTransformFeedbackEXT(getHandle(), firstCounterBuffer, static_cast<uint32_t>(counterBuffers.size()), reinterpret_cast<const Handle::Buffer*>(counterBuffers.data()), counterBufferOffsets.data());
}
void CommandBuffer::beginVideoCodingKHR(const VideoBeginCodingInfoKHR &beginInfo) const {
	getDeviceTable().cmdBeginVideoCodingKHR(getHandle(), (&beginInfo));
}
void CommandBuffer::bindDescriptorBufferEmbeddedSamplers2EXT(const BindDescriptorBufferEmbeddedSamplersInfoEXT &bindDescriptorBufferEmbeddedSamplersInfo) const {
	getDeviceTable().cmdBindDescriptorBufferEmbeddedSamplers2EXT(getHandle(), (&bindDescriptorBufferEmbeddedSamplersInfo));
}
void CommandBuffer::bindDescriptorBufferEmbeddedSamplersEXT(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t set) const {
	getDeviceTable().cmdBindDescriptorBufferEmbeddedSamplersEXT(getHandle(), pipelineBindPoint, layout, set);
}
void CommandBuffer::bindDescriptorBuffersEXT(const impl_Struct::ArrayProxy<DescriptorBufferBindingInfoEXT> &bindingInfos) const {
	getDeviceTable().cmdBindDescriptorBuffersEXT(getHandle(), static_cast<uint32_t>(bindingInfos.size()), bindingInfos.data());
}
void CommandBuffer::bindDescriptorSets(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t firstSet, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<DescriptorSet>> &descriptorSets, const impl_Struct::ArrayProxy<uint32_t> &dynamicOffsets) const {
	getDeviceTable().cmdBindDescriptorSets(getHandle(), pipelineBindPoint, layout, firstSet, static_cast<uint32_t>(descriptorSets.size()), reinterpret_cast<const Handle::DescriptorSet*>(descriptorSets.data()), static_cast<uint32_t>(dynamicOffsets.size()), dynamicOffsets.data());
}
void CommandBuffer::bindDescriptorSets2(const BindDescriptorSetsInfo &bindDescriptorSetsInfo) const {
	getDeviceTable().cmdBindDescriptorSets2(getHandle(), (&bindDescriptorSetsInfo));
}
void CommandBuffer::bindIndexBuffer(const Buffer &buffer, DeviceSize offset, IndexType indexType) const {
	getDeviceTable().cmdBindIndexBuffer(getHandle(), buffer, offset, indexType);
}
void CommandBuffer::bindIndexBuffer2(const Buffer &buffer, DeviceSize offset, DeviceSize size, IndexType indexType) const {
	getDeviceTable().cmdBindIndexBuffer2(getHandle(), buffer, offset, size, indexType);
}
void CommandBuffer::bindIndexBuffer3KHR(const BindIndexBuffer3InfoKHR &info) const {
	getDeviceTable().cmdBindIndexBuffer3KHR(getHandle(), (&info));
}
void CommandBuffer::bindInvocationMaskHUAWEI(const ImageView &imageView, ImageLayout imageLayout) const {
	getDeviceTable().cmdBindInvocationMaskHUAWEI(getHandle(), imageView, imageLayout);
}
void CommandBuffer::bindPipeline(PipelineBindPoint pipelineBindPoint, const Pipeline &pipeline) const {
	getDeviceTable().cmdBindPipeline(getHandle(), pipelineBindPoint, pipeline);
}
void CommandBuffer::bindPipelineShaderGroupNV(PipelineBindPoint pipelineBindPoint, const Pipeline &pipeline, uint32_t groupIndex) const {
	getDeviceTable().cmdBindPipelineShaderGroupNV(getHandle(), pipelineBindPoint, pipeline, groupIndex);
}
void CommandBuffer::bindResourceHeapEXT(const BindHeapInfoEXT &bindInfo) const {
	getDeviceTable().cmdBindResourceHeapEXT(getHandle(), (&bindInfo));
}
void CommandBuffer::bindSamplerHeapEXT(const BindHeapInfoEXT &bindInfo) const {
	getDeviceTable().cmdBindSamplerHeapEXT(getHandle(), (&bindInfo));
}
void CommandBuffer::bindShadersEXT(const impl_Struct::ArrayProxy<ShaderStageBits> &stages, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<ShaderEXT>> &shaders) const {
	getDeviceTable().cmdBindShadersEXT(getHandle(), static_cast<uint32_t>(stages.size()), stages.data(), reinterpret_cast<const Handle::ShaderEXT*>(shaders.data()));
}
void CommandBuffer::bindShadingRateImageNV(const ImageView &imageView, ImageLayout imageLayout) const {
	getDeviceTable().cmdBindShadingRateImageNV(getHandle(), imageView, imageLayout);
}
void CommandBuffer::bindTileMemoryQCOM(const TileMemoryBindInfoQCOM *pTileMemoryBindInfo) const {
	getDeviceTable().cmdBindTileMemoryQCOM(getHandle(), pTileMemoryBindInfo);
}
void CommandBuffer::bindTransformFeedbackBuffers2EXT(uint32_t firstBinding, const impl_Struct::ArrayProxy<BindTransformFeedbackBuffer2InfoEXT> &bindingInfos) const {
	getDeviceTable().cmdBindTransformFeedbackBuffers2EXT(getHandle(), firstBinding, static_cast<uint32_t>(bindingInfos.size()), bindingInfos.data());
}
void CommandBuffer::bindTransformFeedbackBuffersEXT(uint32_t firstBinding, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &buffers, const impl_Struct::ArrayProxy<DeviceSize> &offsets, const impl_Struct::ArrayProxy<DeviceSize> &sizes) const {
	getDeviceTable().cmdBindTransformFeedbackBuffersEXT(getHandle(), firstBinding, static_cast<uint32_t>(buffers.size()), reinterpret_cast<const Handle::Buffer*>(buffers.data()), offsets.data(), sizes.data());
}
void CommandBuffer::bindVertexBuffers(uint32_t firstBinding, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &buffers, const impl_Struct::ArrayProxy<DeviceSize> &offsets) const {
	getDeviceTable().cmdBindVertexBuffers(getHandle(), firstBinding, static_cast<uint32_t>(buffers.size()), reinterpret_cast<const Handle::Buffer*>(buffers.data()), offsets.data());
}
void CommandBuffer::bindVertexBuffers2(uint32_t firstBinding, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &buffers, const impl_Struct::ArrayProxy<DeviceSize> &offsets, const impl_Struct::ArrayProxy<DeviceSize> &sizes, const impl_Struct::ArrayProxy<DeviceSize> &strides) const {
	getDeviceTable().cmdBindVertexBuffers2(getHandle(), firstBinding, static_cast<uint32_t>(buffers.size()), reinterpret_cast<const Handle::Buffer*>(buffers.data()), offsets.data(), sizes.data(), strides.data());
}
void CommandBuffer::bindVertexBuffers3KHR(uint32_t firstBinding, const impl_Struct::ArrayProxy<BindVertexBuffer3InfoKHR> &bindingInfos) const {
	getDeviceTable().cmdBindVertexBuffers3KHR(getHandle(), firstBinding, static_cast<uint32_t>(bindingInfos.size()), bindingInfos.data());
}
void CommandBuffer::blitImage(const Image &srcImage, ImageLayout srcImageLayout, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageBlit> &regions, Filter filter) const {
	getDeviceTable().cmdBlitImage(getHandle(), srcImage, srcImageLayout, dstImage, dstImageLayout, static_cast<uint32_t>(regions.size()), regions.data(), filter);
}
void CommandBuffer::blitImage2(const BlitImageInfo2 &blitImageInfo) const {
	getDeviceTable().cmdBlitImage2(getHandle(), (&blitImageInfo));
}
void CommandBuffer::buildAccelerationStructureNV(const AccelerationStructureInfoNV &info, const Buffer &instanceData, DeviceSize instanceOffset, Bool32 update, const AccelerationStructureNV &dst, const AccelerationStructureNV &src, const Buffer &scratch, DeviceSize scratchOffset) const {
	getDeviceTable().cmdBuildAccelerationStructureNV(getHandle(), (&info), instanceData, instanceOffset, update, dst, src, scratch, scratchOffset);
}
void CommandBuffer::buildAccelerationStructuresIndirectKHR(const impl_Struct::ArrayProxy<AccelerationStructureBuildGeometryInfoKHR> &infos, const impl_Struct::ArrayProxy<DeviceAddress> &indirectDeviceAddresses, const impl_Struct::ArrayProxy<uint32_t> &indirectStrides, const uint32_t * const*ppMaxPrimitiveCounts) const {
	getDeviceTable().cmdBuildAccelerationStructuresIndirectKHR(getHandle(), static_cast<uint32_t>(infos.size()), infos.data(), indirectDeviceAddresses.data(), indirectStrides.data(), ppMaxPrimitiveCounts);
}
void CommandBuffer::buildAccelerationStructuresKHR(const impl_Struct::ArrayProxy<AccelerationStructureBuildGeometryInfoKHR> &infos, const AccelerationStructureBuildRangeInfoKHR * const*ppBuildRangeInfos) const {
	getDeviceTable().cmdBuildAccelerationStructuresKHR(getHandle(), static_cast<uint32_t>(infos.size()), infos.data(), ppBuildRangeInfos);
}
void CommandBuffer::buildClusterAccelerationStructureIndirectNV(const ClusterAccelerationStructureCommandsInfoNV &commandInfos) const {
	getDeviceTable().cmdBuildClusterAccelerationStructureIndirectNV(getHandle(), (&commandInfos));
}
void CommandBuffer::buildMicromapsEXT(const impl_Struct::ArrayProxy<MicromapBuildInfoEXT> &infos) const {
	getDeviceTable().cmdBuildMicromapsEXT(getHandle(), static_cast<uint32_t>(infos.size()), infos.data());
}
void CommandBuffer::buildPartitionedAccelerationStructuresNV(const BuildPartitionedAccelerationStructureInfoNV &buildInfo) const {
	getDeviceTable().cmdBuildPartitionedAccelerationStructuresNV(getHandle(), (&buildInfo));
}
void CommandBuffer::clearAttachments(const impl_Struct::ArrayProxy<ClearAttachment> &attachments, const impl_Struct::ArrayProxy<ClearRect> &rects) const {
	getDeviceTable().cmdClearAttachments(getHandle(), static_cast<uint32_t>(attachments.size()), attachments.data(), static_cast<uint32_t>(rects.size()), rects.data());
}
void CommandBuffer::clearColorImage(const Image &image, ImageLayout imageLayout, const ClearColorValue &color, const impl_Struct::ArrayProxy<ImageSubresourceRange> &ranges) const {
	getDeviceTable().cmdClearColorImage(getHandle(), image, imageLayout, (&color), static_cast<uint32_t>(ranges.size()), ranges.data());
}
void CommandBuffer::clearDepthStencilImage(const Image &image, ImageLayout imageLayout, const ClearDepthStencilValue &depthStencil, const impl_Struct::ArrayProxy<ImageSubresourceRange> &ranges) const {
	getDeviceTable().cmdClearDepthStencilImage(getHandle(), image, imageLayout, (&depthStencil), static_cast<uint32_t>(ranges.size()), ranges.data());
}
void CommandBuffer::controlVideoCodingKHR(const VideoCodingControlInfoKHR &codingControlInfo) const {
	getDeviceTable().cmdControlVideoCodingKHR(getHandle(), (&codingControlInfo));
}
void CommandBuffer::convertCooperativeVectorMatrixNV(const impl_Struct::ArrayProxy<ConvertCooperativeVectorMatrixInfoNV> &infos) const {
	getDeviceTable().cmdConvertCooperativeVectorMatrixNV(getHandle(), static_cast<uint32_t>(infos.size()), infos.data());
}
void CommandBuffer::copyAccelerationStructureKHR(const CopyAccelerationStructureInfoKHR &info) const {
	getDeviceTable().cmdCopyAccelerationStructureKHR(getHandle(), (&info));
}
void CommandBuffer::copyAccelerationStructureNV(const AccelerationStructureNV &dst, const AccelerationStructureNV &src, CopyAccelerationStructureModeKHR mode) const {
	getDeviceTable().cmdCopyAccelerationStructureNV(getHandle(), dst, src, mode);
}
void CommandBuffer::copyAccelerationStructureToMemoryKHR(const CopyAccelerationStructureToMemoryInfoKHR &info) const {
	getDeviceTable().cmdCopyAccelerationStructureToMemoryKHR(getHandle(), (&info));
}
void CommandBuffer::copyBuffer(const Buffer &srcBuffer, const Buffer &dstBuffer, const impl_Struct::ArrayProxy<BufferCopy> &regions) const {
	getDeviceTable().cmdCopyBuffer(getHandle(), srcBuffer, dstBuffer, static_cast<uint32_t>(regions.size()), regions.data());
}
void CommandBuffer::copyBuffer2(const CopyBufferInfo2 &copyBufferInfo) const {
	getDeviceTable().cmdCopyBuffer2(getHandle(), (&copyBufferInfo));
}
void CommandBuffer::copyBufferToImage(const Buffer &srcBuffer, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<BufferImageCopy> &regions) const {
	getDeviceTable().cmdCopyBufferToImage(getHandle(), srcBuffer, dstImage, dstImageLayout, static_cast<uint32_t>(regions.size()), regions.data());
}
void CommandBuffer::copyBufferToImage2(const CopyBufferToImageInfo2 &copyBufferToImageInfo) const {
	getDeviceTable().cmdCopyBufferToImage2(getHandle(), (&copyBufferToImageInfo));
}
void CommandBuffer::copyGpaSessionResultsAMD(const GpaSessionAMD &gpaSession) const {
	getDeviceTable().cmdCopyGpaSessionResultsAMD(getHandle(), gpaSession);
}
void CommandBuffer::copyImage(const Image &srcImage, ImageLayout srcImageLayout, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageCopy> &regions) const {
	getDeviceTable().cmdCopyImage(getHandle(), srcImage, srcImageLayout, dstImage, dstImageLayout, static_cast<uint32_t>(regions.size()), regions.data());
}
void CommandBuffer::copyImage2(const CopyImageInfo2 &copyImageInfo) const {
	getDeviceTable().cmdCopyImage2(getHandle(), (&copyImageInfo));
}
void CommandBuffer::copyImageToBuffer(const Image &srcImage, ImageLayout srcImageLayout, const Buffer &dstBuffer, const impl_Struct::ArrayProxy<BufferImageCopy> &regions) const {
	getDeviceTable().cmdCopyImageToBuffer(getHandle(), srcImage, srcImageLayout, dstBuffer, static_cast<uint32_t>(regions.size()), regions.data());
}
void CommandBuffer::copyImageToBuffer2(const CopyImageToBufferInfo2 &copyImageToBufferInfo) const {
	getDeviceTable().cmdCopyImageToBuffer2(getHandle(), (&copyImageToBufferInfo));
}
void CommandBuffer::copyImageToMemoryKHR(const CopyDeviceMemoryImageInfoKHR *pCopyMemoryInfo) const {
	getDeviceTable().cmdCopyImageToMemoryKHR(getHandle(), pCopyMemoryInfo);
}
void CommandBuffer::copyMemoryIndirectKHR(const CopyMemoryIndirectInfoKHR &copyMemoryIndirectInfo) const {
	getDeviceTable().cmdCopyMemoryIndirectKHR(getHandle(), (&copyMemoryIndirectInfo));
}
void CommandBuffer::copyMemoryIndirectNV(DeviceAddress copyBufferAddress, uint32_t copyCount, uint32_t stride) const {
	getDeviceTable().cmdCopyMemoryIndirectNV(getHandle(), copyBufferAddress, copyCount, stride);
}
void CommandBuffer::copyMemoryKHR(const CopyDeviceMemoryInfoKHR *pCopyMemoryInfo) const {
	getDeviceTable().cmdCopyMemoryKHR(getHandle(), pCopyMemoryInfo);
}
void CommandBuffer::copyMemoryToAccelerationStructureKHR(const CopyMemoryToAccelerationStructureInfoKHR &info) const {
	getDeviceTable().cmdCopyMemoryToAccelerationStructureKHR(getHandle(), (&info));
}
void CommandBuffer::copyMemoryToImageIndirectKHR(const CopyMemoryToImageIndirectInfoKHR &copyMemoryToImageIndirectInfo) const {
	getDeviceTable().cmdCopyMemoryToImageIndirectKHR(getHandle(), (&copyMemoryToImageIndirectInfo));
}
void CommandBuffer::copyMemoryToImageIndirectNV(DeviceAddress copyBufferAddress, uint32_t stride, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageSubresourceLayers> &imageSubresources) const {
	getDeviceTable().cmdCopyMemoryToImageIndirectNV(getHandle(), copyBufferAddress, static_cast<uint32_t>(imageSubresources.size()), stride, dstImage, dstImageLayout, imageSubresources.data());
}
void CommandBuffer::copyMemoryToImageKHR(const CopyDeviceMemoryImageInfoKHR *pCopyMemoryInfo) const {
	getDeviceTable().cmdCopyMemoryToImageKHR(getHandle(), pCopyMemoryInfo);
}
void CommandBuffer::copyMemoryToMicromapEXT(const CopyMemoryToMicromapInfoEXT &info) const {
	getDeviceTable().cmdCopyMemoryToMicromapEXT(getHandle(), (&info));
}
void CommandBuffer::copyMicromapEXT(const CopyMicromapInfoEXT &info) const {
	getDeviceTable().cmdCopyMicromapEXT(getHandle(), (&info));
}
void CommandBuffer::copyMicromapToMemoryEXT(const CopyMicromapToMemoryInfoEXT &info) const {
	getDeviceTable().cmdCopyMicromapToMemoryEXT(getHandle(), (&info));
}
void CommandBuffer::copyQueryPoolResults(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount, const Buffer &dstBuffer, DeviceSize dstOffset, DeviceSize stride, QueryResultFlags flags) const {
	getDeviceTable().cmdCopyQueryPoolResults(getHandle(), queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}
void CommandBuffer::copyQueryPoolResultsToMemoryKHR(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount, const StridedDeviceAddressRangeKHR &dstRange, AddressCommandFlagsKHR dstFlags, QueryResultFlags queryResultFlags) const {
	getDeviceTable().cmdCopyQueryPoolResultsToMemoryKHR(getHandle(), queryPool, firstQuery, queryCount, (&dstRange), dstFlags, queryResultFlags);
}
void CommandBuffer::copyTensorARM(const CopyTensorInfoARM &copyTensorInfo) const {
	getDeviceTable().cmdCopyTensorARM(getHandle(), (&copyTensorInfo));
}
void CommandBuffer::cuLaunchKernelNVX(const CuLaunchInfoNVX &launchInfo) const {
	getDeviceTable().cmdCuLaunchKernelNVX(getHandle(), (&launchInfo));
}
void CommandBuffer::debugMarkerBeginEXT(const DebugMarkerMarkerInfoEXT &markerInfo) const {
	getDeviceTable().cmdDebugMarkerBeginEXT(getHandle(), (&markerInfo));
}
void CommandBuffer::debugMarkerEndEXT() const {
	getDeviceTable().cmdDebugMarkerEndEXT(getHandle());
}
void CommandBuffer::debugMarkerInsertEXT(const DebugMarkerMarkerInfoEXT &markerInfo) const {
	getDeviceTable().cmdDebugMarkerInsertEXT(getHandle(), (&markerInfo));
}
void CommandBuffer::decodeVideoKHR(const VideoDecodeInfoKHR &decodeInfo) const {
	getDeviceTable().cmdDecodeVideoKHR(getHandle(), (&decodeInfo));
}
void CommandBuffer::decompressMemoryEXT(const DecompressMemoryInfoEXT &decompressMemoryInfoEXT) const {
	getDeviceTable().cmdDecompressMemoryEXT(getHandle(), (&decompressMemoryInfoEXT));
}
void CommandBuffer::decompressMemoryIndirectCountEXT(MemoryDecompressionMethodFlagsEXT decompressionMethod, DeviceAddress indirectCommandsAddress, DeviceAddress indirectCommandsCountAddress, uint32_t maxDecompressionCount, uint32_t stride) const {
	getDeviceTable().cmdDecompressMemoryIndirectCountEXT(getHandle(), decompressionMethod, indirectCommandsAddress, indirectCommandsCountAddress, maxDecompressionCount, stride);
}
void CommandBuffer::decompressMemoryIndirectCountNV(DeviceAddress indirectCommandsAddress, DeviceAddress indirectCommandsCountAddress, uint32_t stride) const {
	getDeviceTable().cmdDecompressMemoryIndirectCountNV(getHandle(), indirectCommandsAddress, indirectCommandsCountAddress, stride);
}
void CommandBuffer::decompressMemoryNV(const impl_Struct::ArrayProxy<DecompressMemoryRegionNV> &decompressMemoryRegions) const {
	getDeviceTable().cmdDecompressMemoryNV(getHandle(), static_cast<uint32_t>(decompressMemoryRegions.size()), decompressMemoryRegions.data());
}
void CommandBuffer::dispatch(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const {
	getDeviceTable().cmdDispatch(getHandle(), groupCountX, groupCountY, groupCountZ);
}
void CommandBuffer::dispatchBase(uint32_t baseGroupX, uint32_t baseGroupY, uint32_t baseGroupZ, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const {
	getDeviceTable().cmdDispatchBase(getHandle(), baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}
void CommandBuffer::dispatchDataGraphARM(const DataGraphPipelineSessionARM &session, const DataGraphPipelineDispatchInfoARM *pInfo) const {
	getDeviceTable().cmdDispatchDataGraphARM(getHandle(), session, pInfo);
}
void CommandBuffer::dispatchIndirect(const Buffer &buffer, DeviceSize offset) const {
	getDeviceTable().cmdDispatchIndirect(getHandle(), buffer, offset);
}
void CommandBuffer::dispatchIndirect2KHR(const DispatchIndirect2InfoKHR &info) const {
	getDeviceTable().cmdDispatchIndirect2KHR(getHandle(), (&info));
}
void CommandBuffer::dispatchTileQCOM(const DispatchTileInfoQCOM &dispatchTileInfo) const {
	getDeviceTable().cmdDispatchTileQCOM(getHandle(), (&dispatchTileInfo));
}
void CommandBuffer::draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
	getDeviceTable().cmdDraw(getHandle(), vertexCount, instanceCount, firstVertex, firstInstance);
}
void CommandBuffer::drawClusterHUAWEI(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const {
	getDeviceTable().cmdDrawClusterHUAWEI(getHandle(), groupCountX, groupCountY, groupCountZ);
}
void CommandBuffer::drawClusterIndirectHUAWEI(const Buffer &buffer, DeviceSize offset) const {
	getDeviceTable().cmdDrawClusterIndirectHUAWEI(getHandle(), buffer, offset);
}
void CommandBuffer::drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) const {
	getDeviceTable().cmdDrawIndexed(getHandle(), indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
void CommandBuffer::drawIndexedIndirect(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawIndexedIndirect(getHandle(), buffer, offset, drawCount, stride);
}
void CommandBuffer::drawIndexedIndirect2KHR(const DrawIndirect2InfoKHR &info) const {
	getDeviceTable().cmdDrawIndexedIndirect2KHR(getHandle(), (&info));
}
void CommandBuffer::drawIndexedIndirectCount(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawIndexedIndirectCount(getHandle(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CommandBuffer::drawIndexedIndirectCount2KHR(const DrawIndirectCount2InfoKHR &info) const {
	getDeviceTable().cmdDrawIndexedIndirectCount2KHR(getHandle(), (&info));
}
void CommandBuffer::drawIndirect(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawIndirect(getHandle(), buffer, offset, drawCount, stride);
}
void CommandBuffer::drawIndirect2KHR(const DrawIndirect2InfoKHR &info) const {
	getDeviceTable().cmdDrawIndirect2KHR(getHandle(), (&info));
}
void CommandBuffer::drawIndirectByteCount2EXT(uint32_t instanceCount, uint32_t firstInstance, const BindTransformFeedbackBuffer2InfoEXT &counterInfo, uint32_t counterOffset, uint32_t vertexStride) const {
	getDeviceTable().cmdDrawIndirectByteCount2EXT(getHandle(), instanceCount, firstInstance, (&counterInfo), counterOffset, vertexStride);
}
void CommandBuffer::drawIndirectByteCountEXT(uint32_t instanceCount, uint32_t firstInstance, const Buffer &counterBuffer, DeviceSize counterBufferOffset, uint32_t counterOffset, uint32_t vertexStride) const {
	getDeviceTable().cmdDrawIndirectByteCountEXT(getHandle(), instanceCount, firstInstance, counterBuffer, counterBufferOffset, counterOffset, vertexStride);
}
void CommandBuffer::drawIndirectCount(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawIndirectCount(getHandle(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CommandBuffer::drawIndirectCount2KHR(const DrawIndirectCount2InfoKHR &info) const {
	getDeviceTable().cmdDrawIndirectCount2KHR(getHandle(), (&info));
}
void CommandBuffer::drawMeshTasksEXT(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const {
	getDeviceTable().cmdDrawMeshTasksEXT(getHandle(), groupCountX, groupCountY, groupCountZ);
}
void CommandBuffer::drawMeshTasksIndirect2EXT(const DrawIndirect2InfoKHR &info) const {
	getDeviceTable().cmdDrawMeshTasksIndirect2EXT(getHandle(), (&info));
}
void CommandBuffer::drawMeshTasksIndirectCount2EXT(const DrawIndirectCount2InfoKHR &info) const {
	getDeviceTable().cmdDrawMeshTasksIndirectCount2EXT(getHandle(), (&info));
}
void CommandBuffer::drawMeshTasksIndirectCountEXT(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawMeshTasksIndirectCountEXT(getHandle(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CommandBuffer::drawMeshTasksIndirectCountNV(const Buffer &buffer, DeviceSize offset, const Buffer &countBuffer, DeviceSize countBufferOffset, uint32_t maxDrawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawMeshTasksIndirectCountNV(getHandle(), buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}
void CommandBuffer::drawMeshTasksIndirectEXT(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawMeshTasksIndirectEXT(getHandle(), buffer, offset, drawCount, stride);
}
void CommandBuffer::drawMeshTasksIndirectNV(const Buffer &buffer, DeviceSize offset, uint32_t drawCount, uint32_t stride) const {
	getDeviceTable().cmdDrawMeshTasksIndirectNV(getHandle(), buffer, offset, drawCount, stride);
}
void CommandBuffer::drawMeshTasksNV(uint32_t taskCount, uint32_t firstTask) const {
	getDeviceTable().cmdDrawMeshTasksNV(getHandle(), taskCount, firstTask);
}
void CommandBuffer::drawMultiEXT(const impl_Struct::ArrayProxy<MultiDrawInfoEXT> &vertexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride) const {
	getDeviceTable().cmdDrawMultiEXT(getHandle(), static_cast<uint32_t>(vertexInfo.size()), vertexInfo.data(), instanceCount, firstInstance, stride);
}
void CommandBuffer::drawMultiIndexedEXT(const impl_Struct::ArrayProxy<MultiDrawIndexedInfoEXT> &indexInfo, uint32_t instanceCount, uint32_t firstInstance, uint32_t stride, const int32_t *pVertexOffset) const {
	getDeviceTable().cmdDrawMultiIndexedEXT(getHandle(), static_cast<uint32_t>(indexInfo.size()), indexInfo.data(), instanceCount, firstInstance, stride, pVertexOffset);
}
void CommandBuffer::encodeVideoKHR(const VideoEncodeInfoKHR &encodeInfo) const {
	getDeviceTable().cmdEncodeVideoKHR(getHandle(), (&encodeInfo));
}
void CommandBuffer::endConditionalRenderingEXT() const {
	getDeviceTable().cmdEndConditionalRenderingEXT(getHandle());
}
void CommandBuffer::endDebugUtilsLabelEXT() const {
	getDeviceTable().cmdEndDebugUtilsLabelEXT(getHandle());
}
void CommandBuffer::endGpaSampleAMD(const GpaSessionAMD &gpaSession, uint32_t sampleID) const {
	getDeviceTable().cmdEndGpaSampleAMD(getHandle(), gpaSession, sampleID);
}
auto CommandBuffer::endGpaSessionAMD(const GpaSessionAMD &gpaSession) const -> Result {
	return getDeviceTable().cmdEndGpaSessionAMD(getHandle(), gpaSession);
}
void CommandBuffer::endPerTileExecutionQCOM(const PerTileEndInfoQCOM &perTileEndInfo) const {
	getDeviceTable().cmdEndPerTileExecutionQCOM(getHandle(), (&perTileEndInfo));
}
void CommandBuffer::endQuery(const QueryPool &queryPool, uint32_t query) const {
	getDeviceTable().cmdEndQuery(getHandle(), queryPool, query);
}
void CommandBuffer::endQueryIndexedEXT(const QueryPool &queryPool, uint32_t query, uint32_t index) const {
	getDeviceTable().cmdEndQueryIndexedEXT(getHandle(), queryPool, query, index);
}
void CommandBuffer::endRenderPass() const {
	getDeviceTable().cmdEndRenderPass(getHandle());
}
void CommandBuffer::endRenderPass2(const SubpassEndInfo &subpassEndInfo) const {
	getDeviceTable().cmdEndRenderPass2(getHandle(), (&subpassEndInfo));
}
void CommandBuffer::endRendering() const {
	getDeviceTable().cmdEndRendering(getHandle());
}
void CommandBuffer::endRendering2KHR(const RenderingEndInfoKHR *pRenderingEndInfo) const {
	getDeviceTable().cmdEndRendering2KHR(getHandle(), pRenderingEndInfo);
}
void CommandBuffer::endShaderInstrumentationARM() const {
	getDeviceTable().cmdEndShaderInstrumentationARM(getHandle());
}
void CommandBuffer::endTransformFeedback2EXT(uint32_t firstCounterRange, const impl_Struct::ArrayProxy<BindTransformFeedbackBuffer2InfoEXT> &counterInfos) const {
	getDeviceTable().cmdEndTransformFeedback2EXT(getHandle(), firstCounterRange, static_cast<uint32_t>(counterInfos.size()), counterInfos.data());
}
void CommandBuffer::endTransformFeedbackEXT(uint32_t firstCounterBuffer, const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Buffer>> &counterBuffers, const impl_Struct::ArrayProxy<DeviceSize> &counterBufferOffsets) const {
	getDeviceTable().cmdEndTransformFeedbackEXT(getHandle(), firstCounterBuffer, static_cast<uint32_t>(counterBuffers.size()), reinterpret_cast<const Handle::Buffer*>(counterBuffers.data()), counterBufferOffsets.data());
}
void CommandBuffer::endVideoCodingKHR(const VideoEndCodingInfoKHR &endCodingInfo) const {
	getDeviceTable().cmdEndVideoCodingKHR(getHandle(), (&endCodingInfo));
}
void CommandBuffer::executeCommands(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<CommandBuffer>> &commandBuffers) const {
	getDeviceTable().cmdExecuteCommands(getHandle(), static_cast<uint32_t>(commandBuffers.size()), reinterpret_cast<const Handle::CommandBuffer*>(commandBuffers.data()));
}
void CommandBuffer::executeGeneratedCommandsEXT(Bool32 isPreprocessed, const GeneratedCommandsInfoEXT &generatedCommandsInfo) const {
	getDeviceTable().cmdExecuteGeneratedCommandsEXT(getHandle(), isPreprocessed, (&generatedCommandsInfo));
}
void CommandBuffer::executeGeneratedCommandsNV(Bool32 isPreprocessed, const GeneratedCommandsInfoNV &generatedCommandsInfo) const {
	getDeviceTable().cmdExecuteGeneratedCommandsNV(getHandle(), isPreprocessed, (&generatedCommandsInfo));
}
void CommandBuffer::fillBuffer(const Buffer &dstBuffer, DeviceSize dstOffset, DeviceSize size, uint32_t data) const {
	getDeviceTable().cmdFillBuffer(getHandle(), dstBuffer, dstOffset, size, data);
}
void CommandBuffer::fillMemoryKHR(const DeviceAddressRangeKHR &dstRange, AddressCommandFlagsKHR dstFlags, uint32_t data) const {
	getDeviceTable().cmdFillMemoryKHR(getHandle(), (&dstRange), dstFlags, data);
}
void CommandBuffer::insertDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const {
	getDeviceTable().cmdInsertDebugUtilsLabelEXT(getHandle(), (&labelInfo));
}
void CommandBuffer::nextSubpass(SubpassContents contents) const {
	getDeviceTable().cmdNextSubpass(getHandle(), contents);
}
void CommandBuffer::nextSubpass2(const SubpassBeginInfo &subpassBeginInfo, const SubpassEndInfo &subpassEndInfo) const {
	getDeviceTable().cmdNextSubpass2(getHandle(), (&subpassBeginInfo), (&subpassEndInfo));
}
void CommandBuffer::opticalFlowExecuteNV(const OpticalFlowSessionNV &session, const OpticalFlowExecuteInfoNV &executeInfo) const {
	getDeviceTable().cmdOpticalFlowExecuteNV(getHandle(), session, (&executeInfo));
}
void CommandBuffer::pipelineBarrier(PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, DependencyFlags dependencyFlags, const impl_Struct::ArrayProxy<MemoryBarrier> &memoryBarriers, const impl_Struct::ArrayProxy<BufferMemoryBarrier> &bufferMemoryBarriers, const impl_Struct::ArrayProxy<ImageMemoryBarrier> &imageMemoryBarriers) const {
	getDeviceTable().cmdPipelineBarrier(getHandle(), srcStageMask, dstStageMask, dependencyFlags, static_cast<uint32_t>(memoryBarriers.size()), memoryBarriers.data(), static_cast<uint32_t>(bufferMemoryBarriers.size()), bufferMemoryBarriers.data(), static_cast<uint32_t>(imageMemoryBarriers.size()), imageMemoryBarriers.data());
}
void CommandBuffer::pipelineBarrier2(const DependencyInfo &dependencyInfo) const {
	getDeviceTable().cmdPipelineBarrier2(getHandle(), (&dependencyInfo));
}
void CommandBuffer::preprocessGeneratedCommandsEXT(const GeneratedCommandsInfoEXT &generatedCommandsInfo, const CommandBuffer &stateCommandBuffer) const {
	getDeviceTable().cmdPreprocessGeneratedCommandsEXT(getHandle(), (&generatedCommandsInfo), stateCommandBuffer);
}
void CommandBuffer::preprocessGeneratedCommandsNV(const GeneratedCommandsInfoNV &generatedCommandsInfo) const {
	getDeviceTable().cmdPreprocessGeneratedCommandsNV(getHandle(), (&generatedCommandsInfo));
}
void CommandBuffer::pushConstants(const PipelineLayout &layout, ShaderStageFlags stageFlags, uint32_t offset, const impl_Struct::POD<uint32_t> &values) const {
	getDeviceTable().cmdPushConstants(getHandle(), layout, stageFlags, offset, static_cast<uint32_t>(values.size()), values.data());
}
void CommandBuffer::pushConstants2(const PushConstantsInfo &pushConstantsInfo) const {
	getDeviceTable().cmdPushConstants2(getHandle(), (&pushConstantsInfo));
}
void CommandBuffer::pushDataEXT(const PushDataInfoEXT &pushDataInfo) const {
	getDeviceTable().cmdPushDataEXT(getHandle(), (&pushDataInfo));
}
void CommandBuffer::pushDescriptorSet(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t set, const impl_Struct::ArrayProxy<WriteDescriptorSet> &descriptorWrites) const {
	getDeviceTable().cmdPushDescriptorSet(getHandle(), pipelineBindPoint, layout, set, static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data());
}
void CommandBuffer::pushDescriptorSet2(const PushDescriptorSetInfo &pushDescriptorSetInfo) const {
	getDeviceTable().cmdPushDescriptorSet2(getHandle(), (&pushDescriptorSetInfo));
}
void CommandBuffer::pushDescriptorSetWithTemplate(const DescriptorUpdateTemplate &descriptorUpdateTemplate, const PipelineLayout &layout, uint32_t set, const void *pData) const {
	getDeviceTable().cmdPushDescriptorSetWithTemplate(getHandle(), descriptorUpdateTemplate, layout, set, pData);
}
void CommandBuffer::pushDescriptorSetWithTemplate2(const PushDescriptorSetWithTemplateInfo &pushDescriptorSetWithTemplateInfo) const {
	getDeviceTable().cmdPushDescriptorSetWithTemplate2(getHandle(), (&pushDescriptorSetWithTemplateInfo));
}
void CommandBuffer::resetEvent(const Event &event, PipelineStageFlags stageMask) const {
	getDeviceTable().cmdResetEvent(getHandle(), event, stageMask);
}
void CommandBuffer::resetEvent2(const Event &event, PipelineStageFlags2 stageMask) const {
	getDeviceTable().cmdResetEvent2(getHandle(), event, stageMask);
}
void CommandBuffer::resetQueryPool(const QueryPool &queryPool, uint32_t firstQuery, uint32_t queryCount) const {
	getDeviceTable().cmdResetQueryPool(getHandle(), queryPool, firstQuery, queryCount);
}
void CommandBuffer::resolveImage(const Image &srcImage, ImageLayout srcImageLayout, const Image &dstImage, ImageLayout dstImageLayout, const impl_Struct::ArrayProxy<ImageResolve> &regions) const {
	getDeviceTable().cmdResolveImage(getHandle(), srcImage, srcImageLayout, dstImage, dstImageLayout, static_cast<uint32_t>(regions.size()), regions.data());
}
void CommandBuffer::resolveImage2(const ResolveImageInfo2 &resolveImageInfo) const {
	getDeviceTable().cmdResolveImage2(getHandle(), (&resolveImageInfo));
}
void CommandBuffer::setAlphaToCoverageEnableEXT(Bool32 alphaToCoverageEnable) const {
	getDeviceTable().cmdSetAlphaToCoverageEnableEXT(getHandle(), alphaToCoverageEnable);
}
void CommandBuffer::setAlphaToOneEnableEXT(Bool32 alphaToOneEnable) const {
	getDeviceTable().cmdSetAlphaToOneEnableEXT(getHandle(), alphaToOneEnable);
}
void CommandBuffer::setAttachmentFeedbackLoopEnableEXT(ImageAspectFlags aspectMask) const {
	getDeviceTable().cmdSetAttachmentFeedbackLoopEnableEXT(getHandle(), aspectMask);
}
void CommandBuffer::setBlendConstants(const std::array<float, 4> &blendConstants) const {
	getDeviceTable().cmdSetBlendConstants(getHandle(), blendConstants.data());
}
void CommandBuffer::setCheckpointNV(const void *pCheckpointMarker) const {
	getDeviceTable().cmdSetCheckpointNV(getHandle(), pCheckpointMarker);
}
void CommandBuffer::setCoarseSampleOrderNV(CoarseSampleOrderTypeNV sampleOrderType, const impl_Struct::ArrayProxy<CoarseSampleOrderCustomNV> &customSampleOrders) const {
	getDeviceTable().cmdSetCoarseSampleOrderNV(getHandle(), sampleOrderType, static_cast<uint32_t>(customSampleOrders.size()), customSampleOrders.data());
}
void CommandBuffer::setColorBlendAdvancedEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<ColorBlendAdvancedEXT> &colorBlendAdvanced) const {
	getDeviceTable().cmdSetColorBlendAdvancedEXT(getHandle(), firstAttachment, static_cast<uint32_t>(colorBlendAdvanced.size()), colorBlendAdvanced.data());
}
void CommandBuffer::setColorBlendEnableEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<Bool32> &colorBlendEnables) const {
	getDeviceTable().cmdSetColorBlendEnableEXT(getHandle(), firstAttachment, static_cast<uint32_t>(colorBlendEnables.size()), colorBlendEnables.data());
}
void CommandBuffer::setColorBlendEquationEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<ColorBlendEquationEXT> &colorBlendEquations) const {
	getDeviceTable().cmdSetColorBlendEquationEXT(getHandle(), firstAttachment, static_cast<uint32_t>(colorBlendEquations.size()), colorBlendEquations.data());
}
void CommandBuffer::setColorWriteEnableEXT(const impl_Struct::ArrayProxy<Bool32> &colorWriteEnables) const {
	getDeviceTable().cmdSetColorWriteEnableEXT(getHandle(), static_cast<uint32_t>(colorWriteEnables.size()), colorWriteEnables.data());
}
void CommandBuffer::setColorWriteMaskEXT(uint32_t firstAttachment, const impl_Struct::ArrayProxy<ColorComponentFlags> &colorWriteMasks) const {
	getDeviceTable().cmdSetColorWriteMaskEXT(getHandle(), firstAttachment, static_cast<uint32_t>(colorWriteMasks.size()), colorWriteMasks.data());
}
void CommandBuffer::setComputeOccupancyPriorityNV(const ComputeOccupancyPriorityParametersNV &parameters) const {
	getDeviceTable().cmdSetComputeOccupancyPriorityNV(getHandle(), (&parameters));
}
void CommandBuffer::setConservativeRasterizationModeEXT(ConservativeRasterizationModeEXT conservativeRasterizationMode) const {
	getDeviceTable().cmdSetConservativeRasterizationModeEXT(getHandle(), conservativeRasterizationMode);
}
void CommandBuffer::setCoverageModulationModeNV(CoverageModulationModeNV coverageModulationMode) const {
	getDeviceTable().cmdSetCoverageModulationModeNV(getHandle(), coverageModulationMode);
}
void CommandBuffer::setCoverageModulationTableEnableNV(Bool32 coverageModulationTableEnable) const {
	getDeviceTable().cmdSetCoverageModulationTableEnableNV(getHandle(), coverageModulationTableEnable);
}
void CommandBuffer::setCoverageModulationTableNV(const impl_Struct::ArrayProxy<float> &coverageModulationTable) const {
	getDeviceTable().cmdSetCoverageModulationTableNV(getHandle(), static_cast<uint32_t>(coverageModulationTable.size()), coverageModulationTable.data());
}
void CommandBuffer::setCoverageReductionModeNV(CoverageReductionModeNV coverageReductionMode) const {
	getDeviceTable().cmdSetCoverageReductionModeNV(getHandle(), coverageReductionMode);
}
void CommandBuffer::setCoverageToColorEnableNV(Bool32 coverageToColorEnable) const {
	getDeviceTable().cmdSetCoverageToColorEnableNV(getHandle(), coverageToColorEnable);
}
void CommandBuffer::setCoverageToColorLocationNV(uint32_t coverageToColorLocation) const {
	getDeviceTable().cmdSetCoverageToColorLocationNV(getHandle(), coverageToColorLocation);
}
void CommandBuffer::setCullMode(CullModeFlags cullMode) const {
	getDeviceTable().cmdSetCullMode(getHandle(), cullMode);
}
void CommandBuffer::setDepthBias(float depthBiasConstantFactor, float depthBiasClamp, float depthBiasSlopeFactor) const {
	getDeviceTable().cmdSetDepthBias(getHandle(), depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}
void CommandBuffer::setDepthBias2EXT(const DepthBiasInfoEXT &depthBiasInfo) const {
	getDeviceTable().cmdSetDepthBias2EXT(getHandle(), (&depthBiasInfo));
}
void CommandBuffer::setDepthBiasEnable(Bool32 depthBiasEnable) const {
	getDeviceTable().cmdSetDepthBiasEnable(getHandle(), depthBiasEnable);
}
void CommandBuffer::setDepthBounds(float minDepthBounds, float maxDepthBounds) const {
	getDeviceTable().cmdSetDepthBounds(getHandle(), minDepthBounds, maxDepthBounds);
}
void CommandBuffer::setDepthBoundsTestEnable(Bool32 depthBoundsTestEnable) const {
	getDeviceTable().cmdSetDepthBoundsTestEnable(getHandle(), depthBoundsTestEnable);
}
void CommandBuffer::setDepthClampEnableEXT(Bool32 depthClampEnable) const {
	getDeviceTable().cmdSetDepthClampEnableEXT(getHandle(), depthClampEnable);
}
void CommandBuffer::setDepthClampRangeEXT(DepthClampModeEXT depthClampMode, const DepthClampRangeEXT *pDepthClampRange) const {
	getDeviceTable().cmdSetDepthClampRangeEXT(getHandle(), depthClampMode, pDepthClampRange);
}
void CommandBuffer::setDepthClipEnableEXT(Bool32 depthClipEnable) const {
	getDeviceTable().cmdSetDepthClipEnableEXT(getHandle(), depthClipEnable);
}
void CommandBuffer::setDepthClipNegativeOneToOneEXT(Bool32 negativeOneToOne) const {
	getDeviceTable().cmdSetDepthClipNegativeOneToOneEXT(getHandle(), negativeOneToOne);
}
void CommandBuffer::setDepthCompareOp(CompareOp depthCompareOp) const {
	getDeviceTable().cmdSetDepthCompareOp(getHandle(), depthCompareOp);
}
void CommandBuffer::setDepthTestEnable(Bool32 depthTestEnable) const {
	getDeviceTable().cmdSetDepthTestEnable(getHandle(), depthTestEnable);
}
void CommandBuffer::setDepthWriteEnable(Bool32 depthWriteEnable) const {
	getDeviceTable().cmdSetDepthWriteEnable(getHandle(), depthWriteEnable);
}
void CommandBuffer::setDescriptorBufferOffsets2EXT(const SetDescriptorBufferOffsetsInfoEXT &setDescriptorBufferOffsetsInfo) const {
	getDeviceTable().cmdSetDescriptorBufferOffsets2EXT(getHandle(), (&setDescriptorBufferOffsetsInfo));
}
void CommandBuffer::setDescriptorBufferOffsetsEXT(PipelineBindPoint pipelineBindPoint, const PipelineLayout &layout, uint32_t firstSet, const impl_Struct::ArrayProxy<uint32_t> &bufferIndices, const impl_Struct::ArrayProxy<DeviceSize> &offsets) const {
	getDeviceTable().cmdSetDescriptorBufferOffsetsEXT(getHandle(), pipelineBindPoint, layout, firstSet, static_cast<uint32_t>(bufferIndices.size()), bufferIndices.data(), offsets.data());
}
void CommandBuffer::setDeviceMask(uint32_t deviceMask) const {
	getDeviceTable().cmdSetDeviceMask(getHandle(), deviceMask);
}
void CommandBuffer::setDiscardRectangleEXT(uint32_t firstDiscardRectangle, const impl_Struct::ArrayProxy<Rect2D> &discardRectangles) const {
	getDeviceTable().cmdSetDiscardRectangleEXT(getHandle(), firstDiscardRectangle, static_cast<uint32_t>(discardRectangles.size()), discardRectangles.data());
}
void CommandBuffer::setDiscardRectangleEnableEXT(Bool32 discardRectangleEnable) const {
	getDeviceTable().cmdSetDiscardRectangleEnableEXT(getHandle(), discardRectangleEnable);
}
void CommandBuffer::setDiscardRectangleModeEXT(DiscardRectangleModeEXT discardRectangleMode) const {
	getDeviceTable().cmdSetDiscardRectangleModeEXT(getHandle(), discardRectangleMode);
}
void CommandBuffer::setDispatchParametersARM(const DispatchParametersARM &dispatchParameters) const {
	getDeviceTable().cmdSetDispatchParametersARM(getHandle(), (&dispatchParameters));
}
void CommandBuffer::setEvent(const Event &event, PipelineStageFlags stageMask) const {
	getDeviceTable().cmdSetEvent(getHandle(), event, stageMask);
}
void CommandBuffer::setEvent2(const Event &event, const DependencyInfo &dependencyInfo) const {
	getDeviceTable().cmdSetEvent2(getHandle(), event, (&dependencyInfo));
}
void CommandBuffer::setExclusiveScissorEnableNV(uint32_t firstExclusiveScissor, const impl_Struct::ArrayProxy<Bool32> &exclusiveScissorEnables) const {
	getDeviceTable().cmdSetExclusiveScissorEnableNV(getHandle(), firstExclusiveScissor, static_cast<uint32_t>(exclusiveScissorEnables.size()), exclusiveScissorEnables.data());
}
void CommandBuffer::setExclusiveScissorNV(uint32_t firstExclusiveScissor, const impl_Struct::ArrayProxy<Rect2D> &exclusiveScissors) const {
	getDeviceTable().cmdSetExclusiveScissorNV(getHandle(), firstExclusiveScissor, static_cast<uint32_t>(exclusiveScissors.size()), exclusiveScissors.data());
}
void CommandBuffer::setExtraPrimitiveOverestimationSizeEXT(float extraPrimitiveOverestimationSize) const {
	getDeviceTable().cmdSetExtraPrimitiveOverestimationSizeEXT(getHandle(), extraPrimitiveOverestimationSize);
}
void CommandBuffer::setFragmentShadingRateEnumNV(FragmentShadingRateNV shadingRate, const std::array<FragmentShadingRateCombinerOpKHR, 2> &combinerOps) const {
	getDeviceTable().cmdSetFragmentShadingRateEnumNV(getHandle(), shadingRate, combinerOps.data());
}
void CommandBuffer::setFragmentShadingRateKHR(const Extent2D &fragmentSize, const std::array<FragmentShadingRateCombinerOpKHR, 2> &combinerOps) const {
	getDeviceTable().cmdSetFragmentShadingRateKHR(getHandle(), (&fragmentSize), combinerOps.data());
}
void CommandBuffer::setFrontFace(FrontFace frontFace) const {
	getDeviceTable().cmdSetFrontFace(getHandle(), frontFace);
}
void CommandBuffer::setLineRasterizationModeEXT(LineRasterizationMode lineRasterizationMode) const {
	getDeviceTable().cmdSetLineRasterizationModeEXT(getHandle(), lineRasterizationMode);
}
void CommandBuffer::setLineStipple(uint32_t lineStippleFactor, uint16_t lineStipplePattern) const {
	getDeviceTable().cmdSetLineStipple(getHandle(), lineStippleFactor, lineStipplePattern);
}
void CommandBuffer::setLineStippleEnableEXT(Bool32 stippledLineEnable) const {
	getDeviceTable().cmdSetLineStippleEnableEXT(getHandle(), stippledLineEnable);
}
void CommandBuffer::setLineWidth(float lineWidth) const {
	getDeviceTable().cmdSetLineWidth(getHandle(), lineWidth);
}
void CommandBuffer::setLogicOpEXT(LogicOp logicOp) const {
	getDeviceTable().cmdSetLogicOpEXT(getHandle(), logicOp);
}
void CommandBuffer::setLogicOpEnableEXT(Bool32 logicOpEnable) const {
	getDeviceTable().cmdSetLogicOpEnableEXT(getHandle(), logicOpEnable);
}
void CommandBuffer::setPatchControlPointsEXT(uint32_t patchControlPoints) const {
	getDeviceTable().cmdSetPatchControlPointsEXT(getHandle(), patchControlPoints);
}
auto CommandBuffer::setPerformanceMarkerINTEL(const PerformanceMarkerInfoINTEL &markerInfo) const -> Result {
	return getDeviceTable().cmdSetPerformanceMarkerINTEL(getHandle(), (&markerInfo));
}
auto CommandBuffer::setPerformanceOverrideINTEL(const PerformanceOverrideInfoINTEL &overrideInfo) const -> Result {
	return getDeviceTable().cmdSetPerformanceOverrideINTEL(getHandle(), (&overrideInfo));
}
auto CommandBuffer::setPerformanceStreamMarkerINTEL(const PerformanceStreamMarkerInfoINTEL &markerInfo) const -> Result {
	return getDeviceTable().cmdSetPerformanceStreamMarkerINTEL(getHandle(), (&markerInfo));
}
void CommandBuffer::setPolygonModeEXT(PolygonMode polygonMode) const {
	getDeviceTable().cmdSetPolygonModeEXT(getHandle(), polygonMode);
}
void CommandBuffer::setPrimitiveRestartEnable(Bool32 primitiveRestartEnable) const {
	getDeviceTable().cmdSetPrimitiveRestartEnable(getHandle(), primitiveRestartEnable);
}
void CommandBuffer::setPrimitiveRestartIndexEXT(uint32_t primitiveRestartIndex) const {
	getDeviceTable().cmdSetPrimitiveRestartIndexEXT(getHandle(), primitiveRestartIndex);
}
void CommandBuffer::setPrimitiveTopology(PrimitiveTopology primitiveTopology) const {
	getDeviceTable().cmdSetPrimitiveTopology(getHandle(), primitiveTopology);
}
void CommandBuffer::setProvokingVertexModeEXT(ProvokingVertexModeEXT provokingVertexMode) const {
	getDeviceTable().cmdSetProvokingVertexModeEXT(getHandle(), provokingVertexMode);
}
void CommandBuffer::setRasterizationSamplesEXT(SampleCountBits rasterizationSamples) const {
	getDeviceTable().cmdSetRasterizationSamplesEXT(getHandle(), rasterizationSamples);
}
void CommandBuffer::setRasterizationStreamEXT(uint32_t rasterizationStream) const {
	getDeviceTable().cmdSetRasterizationStreamEXT(getHandle(), rasterizationStream);
}
void CommandBuffer::setRasterizerDiscardEnable(Bool32 rasterizerDiscardEnable) const {
	getDeviceTable().cmdSetRasterizerDiscardEnable(getHandle(), rasterizerDiscardEnable);
}
void CommandBuffer::setRayTracingPipelineStackSizeKHR(uint32_t pipelineStackSize) const {
	getDeviceTable().cmdSetRayTracingPipelineStackSizeKHR(getHandle(), pipelineStackSize);
}
void CommandBuffer::setRenderingAttachmentLocations(const RenderingAttachmentLocationInfo &locationInfo) const {
	getDeviceTable().cmdSetRenderingAttachmentLocations(getHandle(), (&locationInfo));
}
void CommandBuffer::setRenderingInputAttachmentIndices(const RenderingInputAttachmentIndexInfo &inputAttachmentIndexInfo) const {
	getDeviceTable().cmdSetRenderingInputAttachmentIndices(getHandle(), (&inputAttachmentIndexInfo));
}
void CommandBuffer::setRepresentativeFragmentTestEnableNV(Bool32 representativeFragmentTestEnable) const {
	getDeviceTable().cmdSetRepresentativeFragmentTestEnableNV(getHandle(), representativeFragmentTestEnable);
}
void CommandBuffer::setSampleLocationsEXT(const SampleLocationsInfoEXT &sampleLocationsInfo) const {
	getDeviceTable().cmdSetSampleLocationsEXT(getHandle(), (&sampleLocationsInfo));
}
void CommandBuffer::setSampleLocationsEnableEXT(Bool32 sampleLocationsEnable) const {
	getDeviceTable().cmdSetSampleLocationsEnableEXT(getHandle(), sampleLocationsEnable);
}
void CommandBuffer::setSampleMaskEXT(SampleCountBits samples, const SampleMask *pSampleMask) const {
	getDeviceTable().cmdSetSampleMaskEXT(getHandle(), samples, pSampleMask);
}
void CommandBuffer::setScissor(uint32_t firstScissor, const impl_Struct::ArrayProxy<Rect2D> &scissors) const {
	getDeviceTable().cmdSetScissor(getHandle(), firstScissor, static_cast<uint32_t>(scissors.size()), scissors.data());
}
void CommandBuffer::setScissorWithCount(const impl_Struct::ArrayProxy<Rect2D> &scissors) const {
	getDeviceTable().cmdSetScissorWithCount(getHandle(), static_cast<uint32_t>(scissors.size()), scissors.data());
}
void CommandBuffer::setShadingRateImageEnableNV(Bool32 shadingRateImageEnable) const {
	getDeviceTable().cmdSetShadingRateImageEnableNV(getHandle(), shadingRateImageEnable);
}
void CommandBuffer::setStencilCompareMask(StencilFaceFlags faceMask, uint32_t compareMask) const {
	getDeviceTable().cmdSetStencilCompareMask(getHandle(), faceMask, compareMask);
}
void CommandBuffer::setStencilOp(StencilFaceFlags faceMask, StencilOp failOp, StencilOp passOp, StencilOp depthFailOp, CompareOp compareOp) const {
	getDeviceTable().cmdSetStencilOp(getHandle(), faceMask, failOp, passOp, depthFailOp, compareOp);
}
void CommandBuffer::setStencilReference(StencilFaceFlags faceMask, uint32_t reference) const {
	getDeviceTable().cmdSetStencilReference(getHandle(), faceMask, reference);
}
void CommandBuffer::setStencilTestEnable(Bool32 stencilTestEnable) const {
	getDeviceTable().cmdSetStencilTestEnable(getHandle(), stencilTestEnable);
}
void CommandBuffer::setStencilWriteMask(StencilFaceFlags faceMask, uint32_t writeMask) const {
	getDeviceTable().cmdSetStencilWriteMask(getHandle(), faceMask, writeMask);
}
void CommandBuffer::setTessellationDomainOriginEXT(TessellationDomainOrigin domainOrigin) const {
	getDeviceTable().cmdSetTessellationDomainOriginEXT(getHandle(), domainOrigin);
}
void CommandBuffer::setVertexInputEXT(const impl_Struct::ArrayProxy<VertexInputBindingDescription2EXT> &vertexBindingDescriptions, const impl_Struct::ArrayProxy<VertexInputAttributeDescription2EXT> &vertexAttributeDescriptions) const {
	getDeviceTable().cmdSetVertexInputEXT(getHandle(), static_cast<uint32_t>(vertexBindingDescriptions.size()), vertexBindingDescriptions.data(), static_cast<uint32_t>(vertexAttributeDescriptions.size()), vertexAttributeDescriptions.data());
}
void CommandBuffer::setViewport(uint32_t firstViewport, const impl_Struct::ArrayProxy<Viewport> &viewports) const {
	getDeviceTable().cmdSetViewport(getHandle(), firstViewport, static_cast<uint32_t>(viewports.size()), viewports.data());
}
void CommandBuffer::setViewportShadingRatePaletteNV(uint32_t firstViewport, const impl_Struct::ArrayProxy<ShadingRatePaletteNV> &shadingRatePalettes) const {
	getDeviceTable().cmdSetViewportShadingRatePaletteNV(getHandle(), firstViewport, static_cast<uint32_t>(shadingRatePalettes.size()), shadingRatePalettes.data());
}
void CommandBuffer::setViewportSwizzleNV(uint32_t firstViewport, const impl_Struct::ArrayProxy<ViewportSwizzleNV> &viewportSwizzles) const {
	getDeviceTable().cmdSetViewportSwizzleNV(getHandle(), firstViewport, static_cast<uint32_t>(viewportSwizzles.size()), viewportSwizzles.data());
}
void CommandBuffer::setViewportWScalingEnableNV(Bool32 viewportWScalingEnable) const {
	getDeviceTable().cmdSetViewportWScalingEnableNV(getHandle(), viewportWScalingEnable);
}
void CommandBuffer::setViewportWScalingNV(uint32_t firstViewport, const impl_Struct::ArrayProxy<ViewportWScalingNV> &viewportWScalings) const {
	getDeviceTable().cmdSetViewportWScalingNV(getHandle(), firstViewport, static_cast<uint32_t>(viewportWScalings.size()), viewportWScalings.data());
}
void CommandBuffer::setViewportWithCount(const impl_Struct::ArrayProxy<Viewport> &viewports) const {
	getDeviceTable().cmdSetViewportWithCount(getHandle(), static_cast<uint32_t>(viewports.size()), viewports.data());
}
void CommandBuffer::subpassShadingHUAWEI() const {
	getDeviceTable().cmdSubpassShadingHUAWEI(getHandle());
}
void CommandBuffer::traceRaysIndirect2KHR(DeviceAddress indirectDeviceAddress) const {
	getDeviceTable().cmdTraceRaysIndirect2KHR(getHandle(), indirectDeviceAddress);
}
void CommandBuffer::traceRaysIndirectKHR(const StridedDeviceAddressRegionKHR &raygenShaderBindingTable, const StridedDeviceAddressRegionKHR &missShaderBindingTable, const StridedDeviceAddressRegionKHR &hitShaderBindingTable, const StridedDeviceAddressRegionKHR &callableShaderBindingTable, DeviceAddress indirectDeviceAddress) const {
	getDeviceTable().cmdTraceRaysIndirectKHR(getHandle(), (&raygenShaderBindingTable), (&missShaderBindingTable), (&hitShaderBindingTable), (&callableShaderBindingTable), indirectDeviceAddress);
}
void CommandBuffer::traceRaysKHR(const StridedDeviceAddressRegionKHR &raygenShaderBindingTable, const StridedDeviceAddressRegionKHR &missShaderBindingTable, const StridedDeviceAddressRegionKHR &hitShaderBindingTable, const StridedDeviceAddressRegionKHR &callableShaderBindingTable, uint32_t width, uint32_t height, uint32_t depth) const {
	getDeviceTable().cmdTraceRaysKHR(getHandle(), (&raygenShaderBindingTable), (&missShaderBindingTable), (&hitShaderBindingTable), (&callableShaderBindingTable), width, height, depth);
}
void CommandBuffer::traceRaysNV(const Buffer &raygenShaderBindingTableBuffer, DeviceSize raygenShaderBindingOffset, const Buffer &missShaderBindingTableBuffer, DeviceSize missShaderBindingOffset, DeviceSize missShaderBindingStride, const Buffer &hitShaderBindingTableBuffer, DeviceSize hitShaderBindingOffset, DeviceSize hitShaderBindingStride, const Buffer &callableShaderBindingTableBuffer, DeviceSize callableShaderBindingOffset, DeviceSize callableShaderBindingStride, uint32_t width, uint32_t height, uint32_t depth) const {
	getDeviceTable().cmdTraceRaysNV(getHandle(), raygenShaderBindingTableBuffer, raygenShaderBindingOffset, missShaderBindingTableBuffer, missShaderBindingOffset, missShaderBindingStride, hitShaderBindingTableBuffer, hitShaderBindingOffset, hitShaderBindingStride, callableShaderBindingTableBuffer, callableShaderBindingOffset, callableShaderBindingStride, width, height, depth);
}
void CommandBuffer::updateBuffer(const Buffer &dstBuffer, DeviceSize dstOffset, const impl_Struct::POD<DeviceSize> &data) const {
	getDeviceTable().cmdUpdateBuffer(getHandle(), dstBuffer, dstOffset, static_cast<DeviceSize>(data.size()), data.data());
}
void CommandBuffer::updateMemoryKHR(const DeviceAddressRangeKHR &dstRange, AddressCommandFlagsKHR dstFlags, const impl_Struct::POD<DeviceSize> &data) const {
	getDeviceTable().cmdUpdateMemoryKHR(getHandle(), (&dstRange), dstFlags, static_cast<DeviceSize>(data.size()), data.data());
}
void CommandBuffer::updatePipelineIndirectBufferNV(PipelineBindPoint pipelineBindPoint, const Pipeline &pipeline) const {
	getDeviceTable().cmdUpdatePipelineIndirectBufferNV(getHandle(), pipelineBindPoint, pipeline);
}
void CommandBuffer::waitEvents(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Event>> &events, PipelineStageFlags srcStageMask, PipelineStageFlags dstStageMask, const impl_Struct::ArrayProxy<MemoryBarrier> &memoryBarriers, const impl_Struct::ArrayProxy<BufferMemoryBarrier> &bufferMemoryBarriers, const impl_Struct::ArrayProxy<ImageMemoryBarrier> &imageMemoryBarriers) const {
	getDeviceTable().cmdWaitEvents(getHandle(), static_cast<uint32_t>(events.size()), reinterpret_cast<const Handle::Event*>(events.data()), srcStageMask, dstStageMask, static_cast<uint32_t>(memoryBarriers.size()), memoryBarriers.data(), static_cast<uint32_t>(bufferMemoryBarriers.size()), bufferMemoryBarriers.data(), static_cast<uint32_t>(imageMemoryBarriers.size()), imageMemoryBarriers.data());
}
void CommandBuffer::waitEvents2(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<Event>> &events, const impl_Struct::ArrayProxy<DependencyInfo> &dependencyInfos) const {
	getDeviceTable().cmdWaitEvents2(getHandle(), static_cast<uint32_t>(events.size()), reinterpret_cast<const Handle::Event*>(events.data()), dependencyInfos.data());
}
void CommandBuffer::writeAccelerationStructuresPropertiesKHR(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureKHR>> &accelerationStructures, QueryType queryType, const QueryPool &queryPool, uint32_t firstQuery) const {
	getDeviceTable().cmdWriteAccelerationStructuresPropertiesKHR(getHandle(), static_cast<uint32_t>(accelerationStructures.size()), reinterpret_cast<const Handle::AccelerationStructureKHR*>(accelerationStructures.data()), queryType, queryPool, firstQuery);
}
void CommandBuffer::writeAccelerationStructuresPropertiesNV(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<AccelerationStructureNV>> &accelerationStructures, QueryType queryType, const QueryPool &queryPool, uint32_t firstQuery) const {
	getDeviceTable().cmdWriteAccelerationStructuresPropertiesNV(getHandle(), static_cast<uint32_t>(accelerationStructures.size()), reinterpret_cast<const Handle::AccelerationStructureNV*>(accelerationStructures.data()), queryType, queryPool, firstQuery);
}
void CommandBuffer::writeBufferMarker2AMD(PipelineStageFlags2 stage, const Buffer &dstBuffer, DeviceSize dstOffset, uint32_t marker) const {
	getDeviceTable().cmdWriteBufferMarker2AMD(getHandle(), stage, dstBuffer, dstOffset, marker);
}
void CommandBuffer::writeBufferMarkerAMD(PipelineStageBits pipelineStage, const Buffer &dstBuffer, DeviceSize dstOffset, uint32_t marker) const {
	getDeviceTable().cmdWriteBufferMarkerAMD(getHandle(), pipelineStage, dstBuffer, dstOffset, marker);
}
void CommandBuffer::writeMarkerToMemoryAMD(const MemoryMarkerInfoAMD &info) const {
	getDeviceTable().cmdWriteMarkerToMemoryAMD(getHandle(), (&info));
}
void CommandBuffer::writeMicromapsPropertiesEXT(const impl_Struct::ArrayProxy<impl_Struct::AssignableHandle<MicromapEXT>> &micromaps, QueryType queryType, const QueryPool &queryPool, uint32_t firstQuery) const {
	getDeviceTable().cmdWriteMicromapsPropertiesEXT(getHandle(), static_cast<uint32_t>(micromaps.size()), reinterpret_cast<const Handle::MicromapEXT*>(micromaps.data()), queryType, queryPool, firstQuery);
}
void CommandBuffer::writeTimestamp(PipelineStageBits pipelineStage, const QueryPool &queryPool, uint32_t query) const {
	getDeviceTable().cmdWriteTimestamp(getHandle(), pipelineStage, queryPool, query);
}
void CommandBuffer::writeTimestamp2(PipelineStageFlags2 stage, const QueryPool &queryPool, uint32_t query) const {
	getDeviceTable().cmdWriteTimestamp2(getHandle(), stage, queryPool, query);
}
auto CommandBuffer::end() const -> Result {
	return getDeviceTable().endCommandBuffer(getHandle());
}
auto CommandBuffer::reset(CommandBufferResetFlags flags) const -> Result {
	return getDeviceTable().resetCommandBuffer(getHandle(), flags);
}
#ifdef VK_ENABLE_BETA_EXTENSIONS
	void CommandBuffer::cudaLaunchKernelNV(const CudaLaunchInfoNV &launchInfo) const {
		getDeviceTable().cmdCudaLaunchKernelNV(getHandle(), (&launchInfo));
	}
	void CommandBuffer::dispatchGraphAMDX(DeviceAddress scratch, DeviceSize scratchSize, const DispatchGraphCountInfoAMDX &countInfo) const {
		getDeviceTable().cmdDispatchGraphAMDX(getHandle(), scratch, scratchSize, (&countInfo));
	}
	void CommandBuffer::dispatchGraphIndirectAMDX(DeviceAddress scratch, DeviceSize scratchSize, const DispatchGraphCountInfoAMDX &countInfo) const {
		getDeviceTable().cmdDispatchGraphIndirectAMDX(getHandle(), scratch, scratchSize, (&countInfo));
	}
	void CommandBuffer::dispatchGraphIndirectCountAMDX(DeviceAddress scratch, DeviceSize scratchSize, DeviceAddress countInfo) const {
		getDeviceTable().cmdDispatchGraphIndirectCountAMDX(getHandle(), scratch, scratchSize, countInfo);
	}
	void CommandBuffer::initializeGraphScratchMemoryAMDX(const Pipeline &executionGraph, DeviceAddress scratch, DeviceSize scratchSize) const {
		getDeviceTable().cmdInitializeGraphScratchMemoryAMDX(getHandle(), executionGraph, scratch, scratchSize);
	}
#endif // VK_ENABLE_BETA_EXTENSIONS
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings
