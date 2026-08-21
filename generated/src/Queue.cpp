#include "VkBindings/Enums.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StructsForward.hpp"
#include "VkBindings/private/StructTemplatesInterface.hpp"

#include <cstdint>
#include <vector>

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
auto Queue::getCheckpointData2NV() const -> std::vector<CheckpointData2NV> {
	uint32_t count = 0;
	getDeviceTable().getQueueCheckpointData2NV(getHandle(), &count, nullptr);
	std::vector<CheckpointData2NV> checkpointData(count);
	getDeviceTable().getQueueCheckpointData2NV(getHandle(), &count, checkpointData.data());
	checkpointData.resize(count);
	return checkpointData;
}
auto Queue::getCheckpointDataNV() const -> std::vector<CheckpointDataNV> {
	uint32_t count = 0;
	getDeviceTable().getQueueCheckpointDataNV(getHandle(), &count, nullptr);
	std::vector<CheckpointDataNV> checkpointData(count);
	getDeviceTable().getQueueCheckpointDataNV(getHandle(), &count, checkpointData.data());
	checkpointData.resize(count);
	return checkpointData;
}
void Queue::beginDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const {
	getDeviceTable().queueBeginDebugUtilsLabelEXT(getHandle(), (&labelInfo));
}
auto Queue::bindSparse(const impl_Struct::ArrayProxy<BindSparseInfo> &bindInfo, const Fence &fence) const -> Result {
	return getDeviceTable().queueBindSparse(getHandle(), static_cast<uint32_t>(bindInfo.size()), bindInfo.data(), fence);
}
void Queue::endDebugUtilsLabelEXT() const {
	getDeviceTable().queueEndDebugUtilsLabelEXT(getHandle());
}
void Queue::insertDebugUtilsLabelEXT(const DebugUtilsLabelEXT &labelInfo) const {
	getDeviceTable().queueInsertDebugUtilsLabelEXT(getHandle(), (&labelInfo));
}
void Queue::notifyOutOfBandLegacyNV(uint32_t queueType) const {
	getDeviceTable().queueNotifyOutOfBandLegacyNV(getHandle(), queueType);
}
void Queue::notifyOutOfBandNV(const OutOfBandQueueTypeInfoNV &queueTypeInfo) const {
	getDeviceTable().queueNotifyOutOfBandNV(getHandle(), (&queueTypeInfo));
}
auto Queue::presentKHR(const PresentInfoKHR &presentInfo) const -> Result {
	return getDeviceTable().queuePresentKHR(getHandle(), (&presentInfo));
}
auto Queue::setPerfHintQCOM(const PerfHintInfoQCOM &perfHintInfo) const -> Result {
	return getDeviceTable().queueSetPerfHintQCOM(getHandle(), (&perfHintInfo));
}
auto Queue::setPerformanceConfigurationINTEL(const PerformanceConfigurationINTEL &configuration) const -> Result {
	return getDeviceTable().queueSetPerformanceConfigurationINTEL(getHandle(), configuration);
}
auto Queue::submit(const impl_Struct::ArrayProxy<SubmitInfo> &submits, const Fence &fence) const -> Result {
	return getDeviceTable().queueSubmit(getHandle(), static_cast<uint32_t>(submits.size()), submits.data(), fence);
}
auto Queue::submit2(const impl_Struct::ArrayProxy<SubmitInfo2> &submits, const Fence &fence) const -> Result {
	return getDeviceTable().queueSubmit2(getHandle(), static_cast<uint32_t>(submits.size()), submits.data(), fence);
}
auto Queue::waitIdle() const -> Result {
	return getDeviceTable().queueWaitIdle(getHandle());
}
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings
