#include "VkBindings/Objects.hpp"
#include "VkBindings/StructsForward.hpp"

namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-pro-type-reinterpret-cast)
void ExternalComputeQueueNV::getExternalComputeQueueDataNV(ExternalComputeQueueDataParamsNV *params, void *pData) const {
	getDeviceTable().getExternalComputeQueueDataNV(getHandle(), params, pData);
}
// NOLINTEND(cppcoreguidelines-pro-type-reinterpret-cast)
} // namespace VkBindings
