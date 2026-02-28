#include "VulkanBindings.hpp"

#include <cassert>
#include <expected>
#include <utility>

using namespace std::string_literals;

#ifdef MY_VK_IMPL_PRINT_MEM_OPS
#include <cxxabi.h>
#endif

VkResult VkLastResult() { return VulkanBindings::impl::LastResult; }

namespace VulkanBindings {
namespace impl {

thread_local VkResult LastResult = VK_SUCCESS;

#ifdef MY_VK_IMPL_PRINT_MEM_OPS
std::string demangle(const char *name) {
    int status = 0;
    char *dem = abi::__cxa_demangle(name, nullptr, nullptr, &status);
    if (dem != nullptr && status == 0) {
        std::string s(dem);
        std::free(dem);
        return s;
    }
    return std::string(name);
}

#ifndef NDEBUG
std::unordered_map<uint64_t, std::string> objectNameStorage;
#endif

#endif

DescriptorSets::DescriptorSets(VkDevice owner, const VkDescriptorSetAllocateInfo *pAllocateInfo)
    : owner(owner), pool(pAllocateInfo->descriptorPool) {

    handle.resize(pAllocateInfo->descriptorSetCount);

    if (VkResult res = vkAllocateDescriptorSets(owner, pAllocateInfo, handle.data());
        res != VK_SUCCESS) {
        std::cerr << "failed to create: " << VkStructureNameToString(pAllocateInfo->sType)
                  << " error: " << VkResultToString(res) << "\n";
        handle.clear();
        LastResult = res;
    }
}

DescriptorSets::DescriptorSets(DescriptorSets &&o) noexcept
    : owner(std::exchange(o.owner, VK_NULL_HANDLE)), pool(std::exchange(o.pool, VK_NULL_HANDLE)),
      handle(std::exchange(o.handle, std::vector<VkDescriptorSet>{})) {
    assert(!handle.empty() && "Moved from object was empty");
    MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC("move constructor", handle, );
}

DescriptorSets &DescriptorSets::operator=(DescriptorSets &&o) noexcept {
    if (this != &o) {
        cleanup();
        owner = std::exchange(o.owner, VK_NULL_HANDLE);
        pool = std::exchange(o.pool, VK_NULL_HANDLE);
        handle = std::exchange(o.handle, std::vector<VkDescriptorSet>{});
        assert(!handle.empty() && "Moved from object was empty");
        MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC("move assignment", handle, );
    }
    return *this;
}

DescriptorSets::~DescriptorSets() { cleanup(); }

void DescriptorSets::cleanup() noexcept {
    if (!handle.empty()) {
        MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC("deconstructor", handle, );
        if (VkResult res = vkFreeDescriptorSets(owner, pool, static_cast<uint32_t>(handle.size()),
                                                handle.data());
            res != VK_SUCCESS) {
            std::cerr << "failed to FreeDescriptorSets"
                      << " error: " << VkResultToString(res) << "\n";
            owner = VK_NULL_HANDLE;
            pool = VK_NULL_HANDLE;
            handle = std::vector<VkDescriptorSet>{};
            LastResult = res;
        }
        handle.clear();
    }
}

DescriptorSets::operator bool() const noexcept { return !handle.empty(); }

VkDescriptorSet DescriptorSets::operator[](size_t n) {
    assert(n < handle.size());
    return handle[n];
}

// Can be casted into and outof
static_assert(sizeof(CommandBuffer) == sizeof(CommandBuffer));
static_assert(alignof(CommandBuffer) == alignof(CommandBuffer));

std::expected<void, VkResult> CommandBuffer::begin(VkCommandBufferBeginInfo *pBeginInfo) const {
    if (VkResult res = vkBeginCommandBuffer(handle, pBeginInfo); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> CommandBuffer::end() const {
    if (VkResult res = vkEndCommandBuffer(handle); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
void CommandBuffer::copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                               const VkBufferCopy *pRegions) const {
    vkCmdCopyBuffer(handle, srcBuffer, dstBuffer, regionCount, pRegions);
}
void CommandBuffer::copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer,
                               const VkBufferCopy *region) const {
    copyBuffer(srcBuffer, dstBuffer, 1, region);
}
void CommandBuffer::copyBufferToImage(VkBuffer srcBuffer, VkImage dstImage,
                                      VkImageLayout dstImageLayout, uint32_t regionCount,
                                      const VkBufferImageCopy *pRegions) const {
    vkCmdCopyBufferToImage(handle, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}
void CommandBuffer::copyBufferToImage(VkBuffer srcBuffer, VkImage dstImage,
                                      VkImageLayout dstImageLayout,
                                      const VkBufferImageCopy *pRegion) const {
    vkCmdCopyBufferToImage(handle, srcBuffer, dstImage, dstImageLayout, 1, pRegion);
}
void CommandBuffer::copyImageToBuffer(VkImage srcImage, VkImageLayout srcImageLayout,
                                      VkBuffer dstBuffer, uint32_t regionCount,
                                      const VkBufferImageCopy *pRegions) const {
    vkCmdCopyImageToBuffer(handle, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}
void CommandBuffer::pipelineBarrier(VkPipelineStageFlags srcStageMask,
                                    VkPipelineStageFlags dstStageMask,
                                    VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount,
                                    const VkMemoryBarrier *pMemoryBarriers,
                                    uint32_t bufferMemoryBarrierCount,
                                    const VkBufferMemoryBarrier *pBufferMemoryBarriers,
                                    uint32_t imageMemoryBarrierCount,
                                    const VkImageMemoryBarrier *pImageMemoryBarriers) const {
    vkCmdPipelineBarrier(handle, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount,
                         pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers,
                         imageMemoryBarrierCount, pImageMemoryBarriers);
}
void CommandBuffer::bindPipeline(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) const {
    vkCmdBindPipeline(handle, pipelineBindPoint, pipeline);
}
void CommandBuffer::setViewport(VkViewport viewport) const {
    vkCmdSetViewport(handle, 0, 1, &viewport);
}
void CommandBuffer::setScissor(VkRect2D scissor) const { vkCmdSetScissor(handle, 0, 1, &scissor); }
void CommandBuffer::bindDescriptorSets(VkPipelineBindPoint pipelineBindPoint,
                                       VkPipelineLayout layout, uint32_t firstSet,
                                       uint32_t descriptorSetCount,
                                       const VkDescriptorSet *pDescriptorSets,
                                       uint32_t dynamicOffsetCount,
                                       const uint32_t *pDynamicOffsets) const {
    vkCmdBindDescriptorSets(handle, pipelineBindPoint, layout, firstSet, descriptorSetCount,
                            pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}
void CommandBuffer::dispatch(uint32_t groupCountX, uint32_t groupCountY,
                             uint32_t groupCountZ) const {
    vkCmdDispatch(handle, groupCountX, groupCountY, groupCountZ);
}
void CommandBuffer::beginRendering(const VkRenderingInfo *pRenderingInfo) const {
    vkCmdBeginRendering(handle, pRenderingInfo);
}
void CommandBuffer::endRendering() const { vkCmdEndRendering(handle); }
void CommandBuffer::pushConstants(VkPipelineLayout layout, VkShaderStageFlags stageFlags,
                                  uint32_t offset, uint32_t size, const void *pValues) const {
    vkCmdPushConstants(handle, layout, stageFlags, offset, size, pValues);
}
void CommandBuffer::bindVertexBuffers(uint32_t firstBinding, uint32_t bindingCount,
                                      const VkBuffer *pBuffers,
                                      const VkDeviceSize *pOffsets) const {
    vkCmdBindVertexBuffers(handle, firstBinding, bindingCount, pBuffers, pOffsets);
}
void CommandBuffer::bindVertexBuffer(uint32_t firstBinding, VkBuffer buffer,
                                     VkDeviceSize offset) const {
    vkCmdBindVertexBuffers(handle, firstBinding, 1, &buffer, &offset);
}
void CommandBuffer::bindIndexBuffer(VkBuffer buffer, VkDeviceSize offset,
                                    VkIndexType indexType) const {
    vkCmdBindIndexBuffer(handle, buffer, offset, indexType);
}
void CommandBuffer::draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
                         uint32_t firstInstance) const {
    vkCmdDraw(handle, vertexCount, instanceCount, firstVertex, firstInstance);
}
void CommandBuffer::drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                                int32_t vertexOffset, uint32_t firstInstance) const {
    vkCmdDrawIndexed(handle, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}
std::expected<void, VkResult> CommandBuffer::reset(VkCommandBufferResetFlags flags) const {
    if (VkResult res = vkResetCommandBuffer(handle, flags); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}

OwnedHandleCommandBuffers::OwnedHandleCommandBuffers(
    VkDevice owner, const VkCommandBufferAllocateInfo *pAllocateInfo)
    : owner(owner), pool(pAllocateInfo->commandPool) {

    handle.resize(pAllocateInfo->commandBufferCount);

    if (VkResult res =
            vkAllocateCommandBuffers(owner, pAllocateInfo, (VkCommandBuffer *)handle.data());
        res != VK_SUCCESS) {
        std::cerr << "failed to create: " << VkStructureNameToString(pAllocateInfo->sType)
                  << " error: " << VkResultToString(res) << "\n";
        owner = VK_NULL_HANDLE;
        pool = VK_NULL_HANDLE;
        LastResult = res;
    }
}

OwnedHandleCommandBuffers::OwnedHandleCommandBuffers(OwnedHandleCommandBuffers &&o) noexcept
    : owner(std::exchange(o.owner, VK_NULL_HANDLE)), pool(std::exchange(o.pool, VK_NULL_HANDLE)),
      handle(std::exchange(o.handle, std::vector<CommandBuffer>{})) {
    assert(!handle.empty() && "Moved from object was empty");
    MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC("move constructor", handle, .handle);
    o.owner = VK_NULL_HANDLE;
    o.handle.clear();
}

OwnedHandleCommandBuffers &
OwnedHandleCommandBuffers::operator=(OwnedHandleCommandBuffers &&o) noexcept {
    if (this != &o) {
        cleanup();
        owner = std::exchange(o.owner, VK_NULL_HANDLE);
        pool = std::exchange(o.pool, VK_NULL_HANDLE);
        handle = std::exchange(o.handle, std::vector<CommandBuffer>{});
        assert(!handle.empty() && "Moved from object was empty");
        MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC("move assignment", handle, .handle);
    }
    return *this;
}

OwnedHandleCommandBuffers::~OwnedHandleCommandBuffers() { cleanup(); }

void OwnedHandleCommandBuffers::cleanup() noexcept {
    if (!handle.empty()) {
        MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC("deconstructor", handle, .handle);
        vkFreeCommandBuffers(owner, pool, static_cast<uint32_t>(handle.size()),
                             (VkCommandBuffer *)handle.data());
        owner = VK_NULL_HANDLE;
        handle.clear();
    }
}

OwnedHandleCommandBuffers::operator bool() const noexcept { return !handle.empty(); }

CommandBuffer &OwnedHandleCommandBuffers::operator[](size_t n) {
    assert(n < handle.size());
    return handle[n];
}

PhyisicalDevice::PhyisicalDevice(VkPhysicalDevice physicalDevice)
    : physicalDevice(physicalDevice) {};

PhyisicalDevice::operator VkPhysicalDevice() const { return physicalDevice; }

VkPhysicalDeviceProperties PhyisicalDevice::getProperties() const {
    VkPhysicalDeviceProperties properties{};
    vkGetPhysicalDeviceProperties(physicalDevice, &properties);
    return properties;
}
VkPhysicalDeviceFeatures PhyisicalDevice::getFeatures() const {
    VkPhysicalDeviceFeatures features{};
    vkGetPhysicalDeviceFeatures(physicalDevice, &features);
    return features;
}
VkFormatProperties PhyisicalDevice::getFormatProperties(VkFormat format) const {
    VkFormatProperties properties{};
    vkGetPhysicalDeviceFormatProperties(physicalDevice, format, &properties);
    return properties;
}
std::vector<VkQueueFamilyProperties> PhyisicalDevice::getQueueFamilyProperties() const {
    uint32_t count = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, nullptr);
    std::vector<VkQueueFamilyProperties> vec(count);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, vec.data());
    return vec;
}
std::expected<VkBool32, VkResult>
PhyisicalDevice::getSurfaceSupportKHR(uint32_t queueFamilyIndex,
                                      UniqueVkSurfaceKHR &surface) const {
    VkBool32 supported = false;
    if (VkResult res = vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex,
                                                            surface.get(), &supported);
        res != VK_SUCCESS) {
        return res;
    }
    return supported;
}
std::expected<std::vector<VkSurfaceFormatKHR>, VkResult>
PhyisicalDevice::getSurfaceFormatsKHR(UniqueVkSurfaceKHR &surface) const {
    uint32_t count = 0;
    if (VkResult res =
            vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface.get(), &count, nullptr);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<VkSurfaceFormatKHR> vec(count);
    if (VkResult res =
            vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface.get(), &count, vec.data());
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return vec;
}
std::expected<std::vector<VkPresentModeKHR>, VkResult>
PhyisicalDevice::getSurfacePresentModesKHR(UniqueVkSurfaceKHR &surface) const {
    uint32_t count = 0;
    if (VkResult res = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface.get(),
                                                                 &count, nullptr);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<VkPresentModeKHR> vec(count);
    if (VkResult res = vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface.get(),
                                                                 &count, vec.data());
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return vec;
}
std::expected<VkSurfaceCapabilitiesKHR, VkResult>
PhyisicalDevice::getSurfaceCapabilitiesKHR(UniqueVkSurfaceKHR &surface) const {
    VkSurfaceCapabilitiesKHR capabilities;
    if (VkResult res =
            vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface.get(), &capabilities);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return capabilities;
}
std::expected<std::vector<VkExtensionProperties>, VkResult>
PhyisicalDevice::enumerateExtensionProperties() const {
    uint32_t count = 0;
    if (VkResult res =
            vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &count, nullptr);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<VkExtensionProperties> vec(count);
    if (VkResult res =
            vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &count, vec.data());
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return vec;
}
VkPhysicalDeviceMemoryProperties PhyisicalDevice::getMemoryProperties() const {
    VkPhysicalDeviceMemoryProperties properites;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &properites);
    return properites;
}

std::expected<std::vector<PhyisicalDevice>, VkResult> Instance::enumeratePhysicalDevices() const {
    uint32_t count = 0;
    if (VkResult res = vkEnumeratePhysicalDevices(handle, &count, nullptr); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<VkPhysicalDevice> pds(count);
    if (VkResult res = vkEnumeratePhysicalDevices(handle, &count, pds.data()); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<PhyisicalDevice> mypds(count);
    for (size_t i = 0; i < count; i++) {
        mypds[i] = pds[i];
    }
    return mypds;
}
std::expected<std::vector<VkLayerProperties>, VkResult>
Instance::enumerateInstanceLayerProperties() {
    uint32_t count = 0;
    if (VkResult res = vkEnumerateInstanceLayerProperties(&count, nullptr); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<VkLayerProperties> vec(count);
    if (VkResult res = vkEnumerateInstanceLayerProperties(&count, vec.data()); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return vec;
}
[[nodiscard]] std::expected<UniqueVkDebugUtilsMessengerEXT, VkResult>
Instance::createVkDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                         const VkAllocationCallbacks *pAllocator) const {
    if (auto messenger = UniqueVkDebugUtilsMessengerEXT(handle, pCreateInfo, pAllocator);
        !messenger) {
        return std::unexpected(LastResult);
    } else {
        return messenger;
    }
}

std::expected<void, VkResult> Queue::submit(VkSubmitInfo *pSubmitInfo, VkFence fence) const {
    if (VkResult res = vkQueueSubmit(handle, 1, pSubmitInfo, fence); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Queue::cleanupAquireSemaphore(UniqueVkSemaphore &semaphore) const {
    auto submitInfo = VulkanBindings::Init<VkSubmitInfo>();
    VkPipelineStageFlags waitStageMaske = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    VkSemaphore sem = semaphore;
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = &sem;
    submitInfo.pWaitDstStageMask = &waitStageMaske;
    return submit(&submitInfo);
}

std::expected<void, VkResult> Queue::waitIdle() const {
    if (VkResult res = vkQueueWaitIdle(handle); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Queue::presentKHR(const VkPresentInfoKHR *pPresentInfo) const {
    if (VkResult res = vkQueuePresentKHR(handle, pPresentInfo); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}

HandleVkQueue Device::getQueue(uint32_t queueFamilyIndex, uint32_t queueIndex) const {
    HandleVkQueue queue;
    vkGetDeviceQueue(handle, queueFamilyIndex, queueIndex, &queue.handle);
    return queue;
}
std::expected<std::vector<UniqueVkImage>, VkResult>
Device::getSwapchainImagesKHR(UniqueVkSwapchainKHR &swapChain) const {
    uint32_t count = 0;
    if (VkResult res = vkGetSwapchainImagesKHR(handle, swapChain.get(), &count, nullptr);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<VkImage> vec(count);
    if (VkResult res = vkGetSwapchainImagesKHR(handle, swapChain.get(), &count, vec.data());
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<UniqueVkImage> images;
    images.reserve(count);
    for (const auto &i : vec) {
        images.emplace_back(i);
    }
    return images;
}
VkMemoryRequirements Device::getImageMemoryRequirements(VkImage image) const {
    VkMemoryRequirements requirements{};
    vkGetImageMemoryRequirements(handle, image, &requirements);
    return requirements;
}
std::expected<UniqueVkPipelineCache, VkResult>
Device::createPipelineCache(const VkPipelineCacheCreateInfo *pCreateInfo,
                            const VkAllocationCallbacks *pAllocator) const {
    if (UniqueVkPipelineCache cache = UniqueVkPipelineCache(handle, pCreateInfo, pAllocator);
        !cache) {
        return std::unexpected(LastResult);
    } else
        return cache;
}
std::expected<std::vector<uint8_t>, VkResult>
Device::getPiplineCacheData(UniqueVkPipelineCache &pipelineCache) const {
    size_t size = 0;
    if (VkResult res = vkGetPipelineCacheData(handle, pipelineCache, &size, nullptr);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    std::vector<uint8_t> vec(size);
    if (VkResult res = vkGetPipelineCacheData(handle, pipelineCache, &size, vec.data());
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return vec;
}
std::expected<UniqueVkPipeline, VkResult>
Device::createGraphicsPipeline(const VkGraphicsPipelineCreateInfo *pCreateInfo,
                               VkPipelineCache pipelineCache,
                               const VkAllocationCallbacks *pAllocator) const {
    VkPipeline pipeline = VK_NULL_HANDLE;
    if (VkResult res =
            vkCreateGraphicsPipelines(handle, pipelineCache, 1, pCreateInfo, pAllocator, &pipeline);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return UniqueVkPipeline(handle, std::move(pipeline));
}
std::expected<UniqueVkPipeline, VkResult>
Device::createComputePipeline(const VkComputePipelineCreateInfo *pCreateInfo,
                              VkPipelineCache pipelineCache,
                              const VkAllocationCallbacks *pAllocator) const {
    VkPipeline pipeline = VK_NULL_HANDLE;
    if (VkResult res =
            vkCreateComputePipelines(handle, pipelineCache, 1, pCreateInfo, pAllocator, &pipeline);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return UniqueVkPipeline(handle, std::move(pipeline));
}
std::expected<void *, VkResult> Device::mapMemory(VkDeviceMemory memory, VkDeviceSize offset,
                                                  VkDeviceSize size, VkMemoryMapFlags flags) const {
    void *pData = nullptr;
    if (VkResult res = vkMapMemory(handle, memory, offset, size, flags, &pData);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return pData;
}
void Device::unmapMemory(VkDeviceMemory memory) const { vkUnmapMemory(handle, memory); }
std::expected<UniqueVkDeviceMemory, VkResult>
Device::allocateMemory(const VkMemoryAllocateInfo *pAllocInfo,
                       const VkAllocationCallbacks *pAllocator) const {
    VkDeviceMemory memory = VK_NULL_HANDLE;
    if (VkResult res = vkAllocateMemory(handle, pAllocInfo, pAllocator, &memory);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    static_assert(std::same_as<UniqueVkDeviceMemory::owner_type, Device>);
    return UniqueVkDeviceMemory(handle, std::move(memory));
}
std::expected<UniqueVkCommandBuffers, VkResult>
Device::allocateCommandBuffers(const VkCommandBufferAllocateInfo *pAllocateInfo) const {
    if (auto buffs = UniqueVkCommandBuffers(handle, pAllocateInfo); !buffs) {
        return std::unexpected(LastResult);
    } else {
        return buffs;
    }
}
std::expected<void, VkResult> Device::bindImageMemory(VkImage image, VkDeviceMemory memory,
                                                      VkDeviceSize offset) const {
    if (auto res = vkBindImageMemory(handle, image, memory, offset); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Device::bindBufferMemory(VkBuffer buffer, VkDeviceMemory memory,
                                                       VkDeviceSize offset) const {
    if (auto res = vkBindBufferMemory(handle, buffer, memory, offset); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<UniqueVkBuffer, VkResult>
Device::createBuffer(const VkBufferCreateInfo *pCreateInfo,
                     const VkAllocationCallbacks *pAllocator) const {
    if (auto buff = UniqueVkBuffer(handle, pCreateInfo, pAllocator); !buff) {
        return std::unexpected(LastResult);
    } else {
        return buff;
    }
}
VkMemoryRequirements Device::getBufferMemoryRequirements(VkBuffer buffer) const {
    VkMemoryRequirements memoryRequirements{};
    vkGetBufferMemoryRequirements(handle, buffer, &memoryRequirements);
    return memoryRequirements;
}
std::expected<UniqueVkDescriptorPool, VkResult>
Device::createDescriptorPool(const VkDescriptorPoolCreateInfo *pCreateInfo) const {
    if (auto pool = UniqueVkDescriptorPool(handle, pCreateInfo); !pool) {
        return std::unexpected(LastResult);
    } else {
        return pool;
    }
}
std::expected<DescriptorSets, VkResult>
Device::allocateDescriptorSets(const VkDescriptorSetAllocateInfo *pAllocateInfo) const {
    if (auto sets = DescriptorSets(handle, pAllocateInfo); !sets) {
        return std::unexpected(LastResult);
    } else {
        return sets;
    }
}
void Device::updateDescriptorSets(uint32_t descriptorWriteCount,
                                  const VkWriteDescriptorSet *pDescriptorWrites,
                                  uint32_t descriptorCopyCount,
                                  const VkCopyDescriptorSet *pDescriptorCopies) const {
    vkUpdateDescriptorSets(handle, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount,
                           pDescriptorCopies);
}
std::expected<UniqueVkFence, VkResult>
Device::createFence(const VkFenceCreateInfo *pCreateInfo,
                    const VkAllocationCallbacks *pAllocator) const {
    if (auto fence = UniqueVkFence(handle, pCreateInfo, pAllocator); !fence) {
        return std::unexpected(LastResult);
    } else {
        return fence;
    }
}
std::expected<UniqueVkSemaphore, VkResult>
Device::createSemaphore(const VkSemaphoreCreateInfo *pCreateInfo,
                        const VkAllocationCallbacks *pAllocator) const {
    if (auto sem = UniqueVkSemaphore(handle, pCreateInfo, pAllocator); !sem) {
        return std::unexpected(LastResult);
    } else {
        return sem;
    }
}
std::expected<UniqueVkShaderModule, VkResult>
Device::createShaderModule(const VkShaderModuleCreateInfo *pCreateInfo,
                           const VkAllocationCallbacks *pAllocator) const {
    if (auto shader = UniqueVkShaderModule(handle, pCreateInfo, pAllocator); !shader) {
        return std::unexpected(LastResult);
    } else {
        return shader;
    }
}
std::expected<UniqueVkImageView, VkResult>
Device::createImageView(const VkImageViewCreateInfo *pCreateInfo,
                        const VkAllocationCallbacks *pAllocator) const {
    if (auto view = UniqueVkImageView(handle, pCreateInfo, pAllocator); !view) {
        return std::unexpected(LastResult);
    } else {
        return view;
    }
}
std::expected<UniqueVkImage, VkResult>
Device::createImage(const VkImageCreateInfo *pCreateInfo,
                    const VkAllocationCallbacks *pAllocator) const {
    if (auto image = UniqueVkImage(handle, pCreateInfo, pAllocator); !image) {
        return std::unexpected(LastResult);
    } else {
        return image;
    }
}
std::expected<UniqueVkDescriptorSetLayout, VkResult>
Device::createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo *pCreateInfo,
                                  const VkAllocationCallbacks *pAllocator) const {
    if (auto layout = UniqueVkDescriptorSetLayout(handle, pCreateInfo, pAllocator); !layout) {
        return std::unexpected(LastResult);
    } else {
        return layout;
    }
}
std::expected<UniqueVkPipelineLayout, VkResult>
Device::createPipelineLayout(const VkPipelineLayoutCreateInfo *pCreateInfo,
                             const VkAllocationCallbacks *pAllocator) const {
    if (auto layout = UniqueVkPipelineLayout(handle, pCreateInfo, pAllocator); !layout) {
        return std::unexpected(LastResult);
    } else {
        return layout;
    }
}
std::expected<UniqueVkSwapchainKHR, VkResult>
Device::createSwapchainKHR(const VkSwapchainCreateInfoKHR *pCreateInfo,
                           const VkAllocationCallbacks *pAllocator) const {
    if (auto Swapchain = UniqueVkSwapchainKHR(handle, pCreateInfo, pAllocator); !Swapchain) {
        return std::unexpected(LastResult);
    } else {
        return Swapchain;
    }
}
std::expected<UniqueVkCommandPool, VkResult>
Device::createCommandPool(const VkCommandPoolCreateInfo *pCreateInfo,
                          const VkAllocationCallbacks *pAllocator) const {
    if (auto pool = UniqueVkCommandPool(handle, pCreateInfo, pAllocator); !pool) {
        return std::unexpected(LastResult);
    } else {
        return pool;
    }
}
std::expected<UniqueVkSampler, VkResult>
Device::createSampler(const VkSamplerCreateInfo *pCreateInfo,
                      const VkAllocationCallbacks *pAllocator) const {
    if (auto sampler = UniqueVkSampler(handle, pCreateInfo, pAllocator); !sampler) {
        return std::unexpected(LastResult);
    } else {
        return sampler;
    }
}

std::expected<void, VkResult> Device::waitIdle() const {
    if (VkResult res = vkDeviceWaitIdle(handle); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Device::waitForFences(uint32_t fenceCount, const VkFence *pFences,
                                                    VkBool32 waitAll, uint64_t timeout) const {
    if (VkResult res = vkWaitForFences(handle, fenceCount, pFences, waitAll, timeout);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Device::waitForFence(VkFence fence, VkBool32 waitAll,
                                                   uint64_t timeout) const {
    if (VkResult res = vkWaitForFences(handle, 1, &fence, waitAll, timeout); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Device::resetFences(uint32_t fenceCount,
                                                  const VkFence *pFences) const {
    if (VkResult res = vkResetFences(handle, fenceCount, pFences); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Device::resetFence(VkFence fence) const {
    if (VkResult res = vkResetFences(handle, 1, &fence); res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}
std::expected<void, VkResult> Device::aquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout,
                                                         VkSemaphore semaphore, VkFence fence,
                                                         uint32_t *pImageIndex) const {
    if (VkResult res =
            vkAcquireNextImageKHR(handle, swapchain, timeout, semaphore, fence, pImageIndex);
        res != VK_SUCCESS) {
        return std::unexpected(res);
    }
    return {};
}

const char *VkResultToString(VkResult input_value) {
    switch (input_value) {
    case VK_SUCCESS:
        return "VK_SUCCESS";
    case VK_NOT_READY:
        return "VK_NOT_READY";
    case VK_TIMEOUT:
        return "VK_TIMEOUT";
    case VK_EVENT_SET:
        return "VK_EVENT_SET";
    case VK_EVENT_RESET:
        return "VK_EVENT_RESET";
    case VK_INCOMPLETE:
        return "VK_INCOMPLETE";
    case VK_ERROR_OUT_OF_HOST_MEMORY:
        return "VK_ERROR_OUT_OF_HOST_MEMORY";
    case VK_ERROR_OUT_OF_DEVICE_MEMORY:
        return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
    case VK_ERROR_INITIALIZATION_FAILED:
        return "VK_ERROR_INITIALIZATION_FAILED";
    case VK_ERROR_DEVICE_LOST:
        return "VK_ERROR_DEVICE_LOST";
    case VK_ERROR_MEMORY_MAP_FAILED:
        return "VK_ERROR_MEMORY_MAP_FAILED";
    case VK_ERROR_LAYER_NOT_PRESENT:
        return "VK_ERROR_LAYER_NOT_PRESENT";
    case VK_ERROR_EXTENSION_NOT_PRESENT:
        return "VK_ERROR_EXTENSION_NOT_PRESENT";
    case VK_ERROR_FEATURE_NOT_PRESENT:
        return "VK_ERROR_FEATURE_NOT_PRESENT";
    case VK_ERROR_INCOMPATIBLE_DRIVER:
        return "VK_ERROR_INCOMPATIBLE_DRIVER";
    case VK_ERROR_TOO_MANY_OBJECTS:
        return "VK_ERROR_TOO_MANY_OBJECTS";
    case VK_ERROR_FORMAT_NOT_SUPPORTED:
        return "VK_ERROR_FORMAT_NOT_SUPPORTED";
    case VK_ERROR_FRAGMENTED_POOL:
        return "VK_ERROR_FRAGMENTED_POOL";
    case VK_ERROR_UNKNOWN:
        return "VK_ERROR_UNKNOWN";
    case VK_ERROR_VALIDATION_FAILED:
        return "VK_ERROR_VALIDATION_FAILED";
    case VK_ERROR_OUT_OF_POOL_MEMORY:
        return "VK_ERROR_OUT_OF_POOL_MEMORY";
    case VK_ERROR_INVALID_EXTERNAL_HANDLE:
        return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
    case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
        return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
    case VK_ERROR_FRAGMENTATION:
        return "VK_ERROR_FRAGMENTATION";
    case VK_PIPELINE_COMPILE_REQUIRED:
        return "VK_PIPELINE_COMPILE_REQUIRED";
    case VK_ERROR_NOT_PERMITTED:
        return "VK_ERROR_NOT_PERMITTED";
    case VK_ERROR_SURFACE_LOST_KHR:
        return "VK_ERROR_SURFACE_LOST_KHR";
    case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
        return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
    case VK_SUBOPTIMAL_KHR:
        return "VK_SUBOPTIMAL_KHR";
    case VK_ERROR_OUT_OF_DATE_KHR:
        return "VK_ERROR_OUT_OF_DATE_KHR";
    case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
        return "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
    case VK_ERROR_INVALID_SHADER_NV:
        return "VK_ERROR_INVALID_SHADER_NV";
    case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR:
        return "VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR";
    case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR:
        return "VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR";
    case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
        return "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
    case VK_ERROR_PRESENT_TIMING_QUEUE_FULL_EXT:
        return "VK_ERROR_PRESENT_TIMING_QUEUE_FULL_EXT";
    case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
        return "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
    case VK_THREAD_IDLE_KHR:
        return "VK_THREAD_IDLE_KHR";
    case VK_THREAD_DONE_KHR:
        return "VK_THREAD_DONE_KHR";
    case VK_OPERATION_DEFERRED_KHR:
        return "VK_OPERATION_DEFERRED_KHR";
    case VK_OPERATION_NOT_DEFERRED_KHR:
        return "VK_OPERATION_NOT_DEFERRED_KHR";
    case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR:
        return "VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR";
    case VK_ERROR_COMPRESSION_EXHAUSTED_EXT:
        return "VK_ERROR_COMPRESSION_EXHAUSTED_EXT";
    case VK_INCOMPATIBLE_SHADER_BINARY_EXT:
        return "VK_INCOMPATIBLE_SHADER_BINARY_EXT";
    case VK_PIPELINE_BINARY_MISSING_KHR:
        return "VK_PIPELINE_BINARY_MISSING_KHR";
    case VK_ERROR_NOT_ENOUGH_SPACE_KHR:
        return "VK_ERROR_NOT_ENOUGH_SPACE_KHR";
    default:
        return "Unhandled VkResult";
    }
}

const char *VkStructureNameToString(VkStructureType input_value) {
    switch (input_value) {
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
        return "VkBufferMemoryBarrier";
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
        return "VkImageMemoryBarrier";
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
        return "VkMemoryBarrier";
    case VK_STRUCTURE_TYPE_APPLICATION_INFO:
        return "VkApplicationInfo";
    case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
        return "VkInstanceCreateInfo";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
        return "VkDeviceQueueCreateInfo";
    case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
        return "VkDeviceCreateInfo";
    case VK_STRUCTURE_TYPE_SUBMIT_INFO:
        return "VkSubmitInfo";
    case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
        return "VkMappedMemoryRange";
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
        return "VkMemoryAllocateInfo";
    case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
        return "VkBindSparseInfo";
    case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
        return "VkFenceCreateInfo";
    case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
        return "VkSemaphoreCreateInfo";
    case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
        return "VkQueryPoolCreateInfo";
    case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
        return "VkBufferCreateInfo";
    case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
        return "VkImageCreateInfo";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
        return "VkImageViewCreateInfo";
    case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
        return "VkCommandPoolCreateInfo";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
        return "VkCommandBufferAllocateInfo";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
        return "VkCommandBufferInheritanceInfo";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
        return "VkCommandBufferBeginInfo";
    case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
        return "VkEventCreateInfo";
    case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
        return "VkBufferViewCreateInfo";
    case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
        return "VkShaderModuleCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
        return "VkPipelineCacheCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
        return "VkPipelineShaderStageCreateInfo";
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
        return "VkComputePipelineCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
        return "VkPipelineLayoutCreateInfo";
    case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
        return "VkSamplerCreateInfo";
    case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
        return "VkCopyDescriptorSet";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
        return "VkDescriptorPoolCreateInfo";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
        return "VkDescriptorSetAllocateInfo";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
        return "VkDescriptorSetLayoutCreateInfo";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
        return "VkWriteDescriptorSet";
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
        return "VkPipelineVertexInputStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
        return "VkPipelineInputAssemblyStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
        return "VkPipelineTessellationStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
        return "VkPipelineViewportStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
        return "VkPipelineRasterizationStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
        return "VkPipelineMultisampleStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
        return "VkPipelineDepthStencilStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
        return "VkPipelineColorBlendStateCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
        return "VkPipelineDynamicStateCreateInfo";
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
        return "VkGraphicsPipelineCreateInfo";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
        return "VkFramebufferCreateInfo";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
        return "VkRenderPassCreateInfo";
    case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
        return "VkRenderPassBeginInfo";
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
        return "VkBindBufferMemoryInfo";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
        return "VkBindImageMemoryInfo";
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
        return "VkMemoryDedicatedRequirements";
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
        return "VkMemoryDedicatedAllocateInfo";
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
        return "VkMemoryAllocateFlagsInfo";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
        return "VkDeviceGroupCommandBufferBeginInfo";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
        return "VkDeviceGroupSubmitInfo";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
        return "VkDeviceGroupBindSparseInfo";
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
        return "VkBindBufferMemoryDeviceGroupInfo";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
        return "VkBindImageMemoryDeviceGroupInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
        return "VkPhysicalDeviceGroupProperties";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
        return "VkDeviceGroupDeviceCreateInfo";
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
        return "VkBufferMemoryRequirementsInfo2";
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
        return "VkImageMemoryRequirementsInfo2";
    case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
        return "VkImageSparseMemoryRequirementsInfo2";
    case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
        return "VkMemoryRequirements2";
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
        return "VkSparseImageMemoryRequirements2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
        return "VkPhysicalDeviceFeatures2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
        return "VkPhysicalDeviceProperties2";
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
        return "VkFormatProperties2";
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
        return "VkImageFormatProperties2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
        return "VkPhysicalDeviceImageFormatInfo2";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
        return "VkQueueFamilyProperties2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
        return "VkPhysicalDeviceMemoryProperties2";
    case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
        return "VkSparseImageFormatProperties2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
        return "VkPhysicalDeviceSparseImageFormatInfo2";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
        return "VkImageViewUsageCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        return "VkPhysicalDeviceProtectedMemoryFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
        return "VkPhysicalDeviceProtectedMemoryProperties";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
        return "VkDeviceQueueInfo2";
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
        return "VkProtectedSubmitInfo";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
        return "VkBindImagePlaneMemoryInfo";
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
        return "VkImagePlaneMemoryRequirementsInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
        return "VkPhysicalDeviceExternalImageFormatInfo";
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
        return "VkExternalImageFormatProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
        return "VkPhysicalDeviceExternalBufferInfo";
    case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
        return "VkExternalBufferProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
        return "VkPhysicalDeviceIDProperties";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
        return "VkExternalMemoryImageCreateInfo";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
        return "VkExternalMemoryBufferCreateInfo";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
        return "VkExportMemoryAllocateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
        return "VkPhysicalDeviceExternalFenceInfo";
    case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
        return "VkExternalFenceProperties";
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
        return "VkExportFenceCreateInfo";
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
        return "VkExportSemaphoreCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
        return "VkPhysicalDeviceExternalSemaphoreInfo";
    case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
        return "VkExternalSemaphoreProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
        return "VkPhysicalDeviceSubgroupProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        return "VkPhysicalDevice16BitStorageFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        return "VkPhysicalDeviceVariablePointersFeatures";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
        return "VkDescriptorUpdateTemplateCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
        return "VkPhysicalDeviceMaintenance3Properties";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
        return "VkDescriptorSetLayoutSupport";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
        return "VkSamplerYcbcrConversionCreateInfo";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        return "VkSamplerYcbcrConversionInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        return "VkPhysicalDeviceSamplerYcbcrConversionFeatures";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
        return "VkSamplerYcbcrConversionImageFormatProperties";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
        return "VkDeviceGroupRenderPassBeginInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
        return "VkPhysicalDevicePointClippingProperties";
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
        return "VkRenderPassInputAttachmentAspectCreateInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
        return "VkPipelineTessellationDomainOriginStateCreateInfo";
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
        return "VkRenderPassMultiviewCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        return "VkPhysicalDeviceMultiviewFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
        return "VkPhysicalDeviceMultiviewProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        return "VkPhysicalDeviceShaderDrawParametersFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        return "VkPhysicalDeviceVulkan11Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
        return "VkPhysicalDeviceVulkan11Properties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        return "VkPhysicalDeviceVulkan12Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
        return "VkPhysicalDeviceVulkan12Properties";
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        return "VkImageFormatListCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
        return "VkPhysicalDeviceDriverProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        return "VkPhysicalDeviceVulkanMemoryModelFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        return "VkPhysicalDeviceHostQueryResetFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        return "VkPhysicalDeviceTimelineSemaphoreFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
        return "VkPhysicalDeviceTimelineSemaphoreProperties";
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        return "VkSemaphoreTypeCreateInfo";
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        return "VkTimelineSemaphoreSubmitInfo";
    case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
        return "VkSemaphoreWaitInfo";
    case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
        return "VkSemaphoreSignalInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        return "VkPhysicalDeviceBufferDeviceAddressFeatures";
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
        return "VkBufferDeviceAddressInfo";
    case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
        return "VkBufferOpaqueCaptureAddressCreateInfo";
    case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
        return "VkMemoryOpaqueCaptureAddressAllocateInfo";
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
        return "VkDeviceMemoryOpaqueCaptureAddressInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        return "VkPhysicalDevice8BitStorageFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        return "VkPhysicalDeviceShaderAtomicInt64Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        return "VkPhysicalDeviceShaderFloat16Int8Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
        return "VkPhysicalDeviceFloatControlsProperties";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
        return "VkDescriptorSetLayoutBindingFlagsCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        return "VkPhysicalDeviceDescriptorIndexingFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
        return "VkPhysicalDeviceDescriptorIndexingProperties";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
        return "VkDescriptorSetVariableDescriptorCountAllocateInfo";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
        return "VkDescriptorSetVariableDescriptorCountLayoutSupport";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        return "VkPhysicalDeviceScalarBlockLayoutFeatures";
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
        return "VkSamplerReductionModeCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
        return "VkPhysicalDeviceSamplerFilterMinmaxProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        return "VkPhysicalDeviceUniformBufferStandardLayoutFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        return "VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures";
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
        return "VkAttachmentDescription2";
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
        return "VkAttachmentReference2";
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
        return "VkSubpassDescription2";
    case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
        return "VkSubpassDependency2";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
        return "VkRenderPassCreateInfo2";
    case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
        return "VkSubpassBeginInfo";
    case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
        return "VkSubpassEndInfo";
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
        return "VkSubpassDescriptionDepthStencilResolve";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
        return "VkPhysicalDeviceDepthStencilResolveProperties";
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        return "VkImageStencilUsageCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        return "VkPhysicalDeviceImagelessFramebufferFeatures";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
        return "VkFramebufferAttachmentImageInfo";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
        return "VkFramebufferAttachmentsCreateInfo";
    case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
        return "VkRenderPassAttachmentBeginInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        return "VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures";
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
        return "VkAttachmentReferenceStencilLayout";
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
        return "VkAttachmentDescriptionStencilLayout";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
        return "VkPhysicalDeviceVulkan13Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
        return "VkPhysicalDeviceVulkan13Properties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
        return "VkPhysicalDeviceToolProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
        return "VkPhysicalDevicePrivateDataFeatures";
    case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
        return "VkDevicePrivateDataCreateInfo";
    case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
        return "VkPrivateDataSlotCreateInfo";
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
        return "VkMemoryBarrier2";
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
        return "VkBufferMemoryBarrier2";
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
        return "VkImageMemoryBarrier2";
    case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
        return "VkDependencyInfo";
    case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
        return "VkSemaphoreSubmitInfo";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
        return "VkCommandBufferSubmitInfo";
    case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
        return "VkSubmitInfo2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
        return "VkPhysicalDeviceSynchronization2Features";
    case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
        return "VkBufferCopy2";
    case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
        return "VkCopyBufferInfo2";
    case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
        return "VkImageCopy2";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
        return "VkCopyImageInfo2";
    case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
        return "VkBufferImageCopy2";
    case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
        return "VkCopyBufferToImageInfo2";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
        return "VkCopyImageToBufferInfo2";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
        return "VkPhysicalDeviceTextureCompressionASTCHDRFeatures";
    case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
        return "VkFormatProperties3";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
        return "VkPhysicalDeviceMaintenance4Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
        return "VkPhysicalDeviceMaintenance4Properties";
    case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
        return "VkDeviceBufferMemoryRequirements";
    case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
        return "VkDeviceImageMemoryRequirements";
    case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
        return "VkPipelineCreationFeedbackCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
        return "VkPhysicalDeviceShaderTerminateInvocationFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
        return "VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
        return "VkPhysicalDevicePipelineCreationCacheControlFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
        return "VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
        return "VkPhysicalDeviceImageRobustnessFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
        return "VkPhysicalDeviceSubgroupSizeControlFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
        return "VkPhysicalDeviceSubgroupSizeControlProperties";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
        return "VkPipelineShaderStageRequiredSubgroupSizeCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
        return "VkPhysicalDeviceInlineUniformBlockFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
        return "VkPhysicalDeviceInlineUniformBlockProperties";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
        return "VkWriteDescriptorSetInlineUniformBlock";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
        return "VkDescriptorPoolInlineUniformBlockCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
        return "VkPhysicalDeviceShaderIntegerDotProductFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
        return "VkPhysicalDeviceShaderIntegerDotProductProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
        return "VkPhysicalDeviceTexelBufferAlignmentProperties";
    case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
        return "VkImageBlit2";
    case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
        return "VkBlitImageInfo2";
    case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
        return "VkImageResolve2";
    case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
        return "VkResolveImageInfo2";
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
        return "VkRenderingAttachmentInfo";
    case VK_STRUCTURE_TYPE_RENDERING_INFO:
        return "VkRenderingInfo";
    case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
        return "VkPipelineRenderingCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
        return "VkPhysicalDeviceDynamicRenderingFeatures";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
        return "VkCommandBufferInheritanceRenderingInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
        return "VkPhysicalDeviceVulkan14Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
        return "VkPhysicalDeviceVulkan14Properties";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
        return "VkDeviceQueueGlobalPriorityCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES:
        return "VkPhysicalDeviceGlobalPriorityQueryFeatures";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
        return "VkQueueFamilyGlobalPriorityProperties";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES:
        return "VkPhysicalDeviceIndexTypeUint8Features";
    case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO:
        return "VkMemoryMapInfo";
    case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO:
        return "VkMemoryUnmapInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
        return "VkPhysicalDeviceMaintenance5Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
        return "VkPhysicalDeviceMaintenance5Properties";
    case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2:
        return "VkImageSubresource2";
    case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO:
        return "VkDeviceImageSubresourceInfo";
    case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2:
        return "VkSubresourceLayout2";
    case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
        return "VkBufferUsageFlags2CreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
        return "VkPhysicalDeviceMaintenance6Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
        return "VkPhysicalDeviceMaintenance6Properties";
    case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS:
        return "VkBindMemoryStatus";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
        return "VkPhysicalDeviceHostImageCopyFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
        return "VkPhysicalDeviceHostImageCopyProperties";
    case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY:
        return "VkMemoryToImageCopy";
    case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY:
        return "VkImageToMemoryCopy";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO:
        return "VkCopyMemoryToImageInfo";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO:
        return "VkCopyImageToMemoryInfo";
    case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO:
        return "VkCopyImageToImageInfo";
    case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO:
        return "VkHostImageLayoutTransitionInfo";
    case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
        return "VkSubresourceHostMemcpySize";
    case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
        return "VkHostImageCopyDevicePerformanceQuery";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
        return "VkPhysicalDeviceShaderSubgroupRotateFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
        return "VkPhysicalDeviceShaderFloatControls2Features";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
        return "VkPhysicalDeviceShaderExpectAssumeFeatures";
    case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO:
        return "VkPipelineCreateFlags2CreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
        return "VkPhysicalDevicePushDescriptorProperties";
    case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO:
        return "VkBindDescriptorSetsInfo";
    case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO:
        return "VkPushConstantsInfo";
    case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO:
        return "VkPushDescriptorSetInfo";
    case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO:
        return "VkPushDescriptorSetWithTemplateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
        return "VkPhysicalDevicePipelineProtectedAccessFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
        return "VkPhysicalDevicePipelineRobustnessFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
        return "VkPhysicalDevicePipelineRobustnessProperties";
    case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO:
        return "VkPipelineRobustnessCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES:
        return "VkPhysicalDeviceLineRasterizationFeatures";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES:
        return "VkPhysicalDeviceLineRasterizationProperties";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO:
        return "VkPipelineRasterizationLineStateCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES:
        return "VkPhysicalDeviceVertexAttributeDivisorProperties";
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
        return "VkPipelineVertexInputDivisorStateCreateInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES:
        return "VkPhysicalDeviceVertexAttributeDivisorFeatures";
    case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO:
        return "VkRenderingAreaInfo";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
        return "VkPhysicalDeviceDynamicRenderingLocalReadFeatures";
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
        return "VkRenderingAttachmentLocationInfo";
    case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
        return "VkRenderingInputAttachmentIndexInfo";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
        return "VkSwapchainCreateInfoKHR";
    case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
        return "VkPresentInfoKHR";
    case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
        return "VkImageSwapchainCreateInfoKHR";
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
        return "VkBindImageMemorySwapchainInfoKHR";
    case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
        return "VkAcquireNextImageInfoKHR";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
        return "VkDeviceGroupPresentCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
        return "VkDeviceGroupPresentInfoKHR";
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
        return "VkDeviceGroupSwapchainCreateInfoKHR";
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
        return "VkDisplayModeCreateInfoKHR";
    case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
        return "VkDisplaySurfaceCreateInfoKHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
        return "VkDisplayPresentInfoKHR";
#ifdef VK_USE_PLATFORM_XLIB_KHR
    case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
        return "VkXlibSurfaceCreateInfoKHR";
#endif // VK_USE_PLATFORM_XLIB_KHR
#ifdef VK_USE_PLATFORM_XCB_KHR
    case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
        return "VkXcbSurfaceCreateInfoKHR";
#endif // VK_USE_PLATFORM_XCB_KHR
#ifdef VK_USE_PLATFORM_WAYLAND_KHR
    case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
        return "VkWaylandSurfaceCreateInfoKHR";
#endif // VK_USE_PLATFORM_WAYLAND_KHR
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
        return "VkAndroidSurfaceCreateInfoKHR";
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
        return "VkWin32SurfaceCreateInfoKHR";
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
        return "VkQueueFamilyQueryResultStatusPropertiesKHR";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
        return "VkQueueFamilyVideoPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
        return "VkVideoProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
        return "VkVideoProfileListInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
        return "VkVideoCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
        return "VkPhysicalDeviceVideoFormatInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
        return "VkVideoFormatPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
        return "VkVideoPictureResourceInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
        return "VkVideoReferenceSlotInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
        return "VkVideoSessionMemoryRequirementsKHR";
    case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
        return "VkBindVideoSessionMemoryInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
        return "VkVideoSessionCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoSessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
        return "VkVideoSessionParametersUpdateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
        return "VkVideoBeginCodingInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
        return "VkVideoEndCodingInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
        return "VkVideoCodingControlInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
        return "VkVideoDecodeCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
        return "VkVideoDecodeUsageInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
        return "VkVideoDecodeInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
        return "VkVideoEncodeH264CapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
        return "VkVideoEncodeH264QualityLevelPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
        return "VkVideoEncodeH264SessionCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
        return "VkVideoEncodeH264SessionParametersAddInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoEncodeH264SessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
        return "VkVideoEncodeH264SessionParametersGetInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
        return "VkVideoEncodeH264SessionParametersFeedbackInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
        return "VkVideoEncodeH264NaluSliceInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
        return "VkVideoEncodeH264PictureInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
        return "VkVideoEncodeH264DpbSlotInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
        return "VkVideoEncodeH264ProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
        return "VkVideoEncodeH264RateControlInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
        return "VkVideoEncodeH264RateControlLayerInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
        return "VkVideoEncodeH264GopRemainingFrameInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
        return "VkVideoEncodeH265CapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
        return "VkVideoEncodeH265SessionCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
        return "VkVideoEncodeH265QualityLevelPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
        return "VkVideoEncodeH265SessionParametersAddInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoEncodeH265SessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
        return "VkVideoEncodeH265SessionParametersGetInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
        return "VkVideoEncodeH265SessionParametersFeedbackInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR:
        return "VkVideoEncodeH265NaluSliceSegmentInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
        return "VkVideoEncodeH265PictureInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
        return "VkVideoEncodeH265DpbSlotInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
        return "VkVideoEncodeH265ProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
        return "VkVideoEncodeH265RateControlInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
        return "VkVideoEncodeH265RateControlLayerInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
        return "VkVideoEncodeH265GopRemainingFrameInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
        return "VkVideoDecodeH264ProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
        return "VkVideoDecodeH264CapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
        return "VkVideoDecodeH264SessionParametersAddInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoDecodeH264SessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
        return "VkVideoDecodeH264PictureInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
        return "VkVideoDecodeH264DpbSlotInfoKHR";
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        return "VkImportMemoryWin32HandleInfoKHR";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
        return "VkExportMemoryWin32HandleInfoKHR";
    case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
        return "VkMemoryWin32HandlePropertiesKHR";
    case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
        return "VkMemoryGetWin32HandleInfoKHR";
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
        return "VkImportMemoryFdInfoKHR";
    case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
        return "VkMemoryFdPropertiesKHR";
    case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
        return "VkMemoryGetFdInfoKHR";
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
        return "VkWin32KeyedMutexAcquireReleaseInfoKHR";
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
        return "VkImportSemaphoreWin32HandleInfoKHR";
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
        return "VkExportSemaphoreWin32HandleInfoKHR";
    case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
        return "VkD3D12FenceSubmitInfoKHR";
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
        return "VkSemaphoreGetWin32HandleInfoKHR";
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
        return "VkImportSemaphoreFdInfoKHR";
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
        return "VkSemaphoreGetFdInfoKHR";
    case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
        return "VkPresentRegionsKHR";
    case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
        return "VkSharedPresentSurfaceCapabilitiesKHR";
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
        return "VkImportFenceWin32HandleInfoKHR";
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
        return "VkExportFenceWin32HandleInfoKHR";
    case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
        return "VkFenceGetWin32HandleInfoKHR";
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
        return "VkImportFenceFdInfoKHR";
    case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
        return "VkFenceGetFdInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
        return "VkPhysicalDevicePerformanceQueryFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
        return "VkPhysicalDevicePerformanceQueryPropertiesKHR";
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
        return "VkPerformanceCounterKHR";
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
        return "VkPerformanceCounterDescriptionKHR";
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
        return "VkQueryPoolPerformanceCreateInfoKHR";
    case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
        return "VkAcquireProfilingLockInfoKHR";
    case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
        return "VkPerformanceQuerySubmitInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
        return "VkPhysicalDeviceSurfaceInfo2KHR";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
        return "VkSurfaceCapabilities2KHR";
    case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
        return "VkSurfaceFormat2KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
        return "VkDisplayProperties2KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
        return "VkDisplayPlaneProperties2KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
        return "VkDisplayModeProperties2KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
        return "VkDisplayPlaneInfo2KHR";
    case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
        return "VkDisplayPlaneCapabilities2KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
        return "VkPhysicalDeviceShaderBfloat16FeaturesKHR";
#ifdef VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
        return "VkPhysicalDevicePortabilitySubsetFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
        return "VkPhysicalDevicePortabilitySubsetPropertiesKHR";
#endif // VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
        return "VkPhysicalDeviceShaderClockFeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
        return "VkVideoDecodeH265ProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
        return "VkVideoDecodeH265CapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
        return "VkVideoDecodeH265SessionParametersAddInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoDecodeH265SessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
        return "VkVideoDecodeH265PictureInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
        return "VkVideoDecodeH265DpbSlotInfoKHR";
    case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        return "VkFragmentShadingRateAttachmentInfoKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
        return "VkPipelineFragmentShadingRateStateCreateInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
        return "VkPhysicalDeviceFragmentShadingRateFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
        return "VkPhysicalDeviceFragmentShadingRatePropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
        return "VkPhysicalDeviceFragmentShadingRateKHR";
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
        return "VkRenderingFragmentShadingRateAttachmentInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
        return "VkPhysicalDeviceShaderQuadControlFeaturesKHR";
    case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
        return "VkSurfaceProtectedCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
        return "VkPhysicalDevicePresentWaitFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
        return "VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
        return "VkPipelineInfoKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
        return "VkPipelineExecutablePropertiesKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
        return "VkPipelineExecutableInfoKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
        return "VkPipelineExecutableStatisticKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
        return "VkPipelineExecutableInternalRepresentationKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
        return "VkPipelineLibraryCreateInfoKHR";
    case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
        return "VkPresentIdKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
        return "VkPhysicalDevicePresentIdFeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
        return "VkVideoEncodeInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
        return "VkVideoEncodeCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
        return "VkQueryPoolVideoEncodeFeedbackCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
        return "VkVideoEncodeUsageInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
        return "VkVideoEncodeRateControlLayerInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
        return "VkVideoEncodeRateControlInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
        return "VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
        return "VkVideoEncodeQualityLevelPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
        return "VkVideoEncodeQualityLevelInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
        return "VkVideoEncodeSessionParametersGetInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
        return "VkVideoEncodeSessionParametersFeedbackInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
        return "VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
        return "VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
        return "VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
        return "VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
        return "VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
        return "VkPhysicalDeviceShaderUntypedPointersFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
        return "VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
        return "VkSurfaceCapabilitiesPresentId2KHR";
    case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
        return "VkPresentId2KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
        return "VkPhysicalDevicePresentId2FeaturesKHR";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
        return "VkSurfaceCapabilitiesPresentWait2KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
        return "VkPhysicalDevicePresentWait2FeaturesKHR";
    case VK_STRUCTURE_TYPE_PRESENT_WAIT_2_INFO_KHR:
        return "VkPresentWait2InfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
        return "VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
        return "VkPhysicalDevicePipelineBinaryFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
        return "VkPhysicalDevicePipelineBinaryPropertiesKHR";
    case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
        return "VkDevicePipelineBinaryInternalCacheControlKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR:
        return "VkPipelineBinaryKeyKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_CREATE_INFO_KHR:
        return "VkPipelineCreateInfoKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR:
        return "VkPipelineBinaryCreateInfoKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
        return "VkPipelineBinaryInfoKHR";
    case VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR:
        return "VkReleaseCapturedPipelineDataInfoKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR:
        return "VkPipelineBinaryDataInfoKHR";
    case VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR:
        return "VkPipelineBinaryHandlesInfoKHR";
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR:
        return "VkSurfacePresentModeKHR";
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR:
        return "VkSurfacePresentScalingCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR:
        return "VkSurfacePresentModeCompatibilityKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR:
        return "VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
        return "VkSwapchainPresentFenceInfoKHR";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR:
        return "VkSwapchainPresentModesCreateInfoKHR";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR:
        return "VkSwapchainPresentModeInfoKHR";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR:
        return "VkSwapchainPresentScalingCreateInfoKHR";
    case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_KHR:
        return "VkReleaseSwapchainImagesInfoKHR";
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
        return "VkCooperativeMatrixPropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
        return "VkPhysicalDeviceCooperativeMatrixFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
        return "VkPhysicalDeviceCooperativeMatrixPropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
        return "VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
        return "VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
        return "VkVideoDecodeAV1ProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
        return "VkVideoDecodeAV1CapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoDecodeAV1SessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
        return "VkVideoDecodeAV1PictureInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
        return "VkVideoDecodeAV1DpbSlotInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
        return "VkPhysicalDeviceVideoEncodeAV1FeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
        return "VkVideoEncodeAV1CapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
        return "VkVideoEncodeAV1QualityLevelPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
        return "VkVideoEncodeAV1SessionCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoEncodeAV1SessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
        return "VkVideoEncodeAV1PictureInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
        return "VkVideoEncodeAV1DpbSlotInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
        return "VkVideoEncodeAV1ProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
        return "VkVideoEncodeAV1GopRemainingFrameInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
        return "VkVideoEncodeAV1RateControlInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
        return "VkVideoEncodeAV1RateControlLayerInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
        return "VkPhysicalDeviceVideoDecodeVP9FeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
        return "VkVideoDecodeVP9ProfileInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
        return "VkVideoDecodeVP9CapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
        return "VkVideoDecodeVP9PictureInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
        return "VkPhysicalDeviceVideoMaintenance1FeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
        return "VkVideoInlineQueryInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
        return "VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR";
    case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
        return "VkAttachmentFeedbackLoopInfoEXT";
    case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
        return "VkCalibratedTimestampInfoKHR";
    case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
        return "VkSetDescriptorBufferOffsetsInfoEXT";
    case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
        return "VkBindDescriptorBufferEmbeddedSamplersInfoEXT";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_INDIRECT_INFO_KHR:
        return "VkCopyMemoryIndirectInfoKHR";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INDIRECT_INFO_KHR:
        return "VkCopyMemoryToImageIndirectInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
        return "VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR:
        return "VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
        return "VkVideoEncodeIntraRefreshCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
        return "VkVideoEncodeSessionIntraRefreshCreateInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
        return "VkVideoEncodeIntraRefreshInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
        return "VkVideoReferenceIntraRefreshInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
        return "VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
        return "VkVideoEncodeQuantizationMapCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
        return "VkVideoFormatQuantizationMapPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
        return "VkVideoEncodeQuantizationMapInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
        return "VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
        return "VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
        return "VkVideoEncodeH264QuantizationMapCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
        return "VkVideoEncodeH265QuantizationMapCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
        return "VkVideoFormatH265QuantizationMapPropertiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
        return "VkVideoEncodeAV1QuantizationMapCapabilitiesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
        return "VkVideoFormatAV1QuantizationMapPropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
        return "VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
        return "VkPhysicalDeviceMaintenance7FeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
        return "VkPhysicalDeviceMaintenance7PropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_KHR:
        return "VkPhysicalDeviceLayeredApiPropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
        return "VkPhysicalDeviceLayeredApiPropertiesListKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
        return "VkPhysicalDeviceLayeredApiVulkanPropertiesKHR";
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
        return "VkMemoryBarrierAccessFlags3KHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
        return "VkPhysicalDeviceMaintenance8FeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
        return "VkPhysicalDeviceShaderFmaFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
        return "VkPhysicalDeviceMaintenance9FeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
        return "VkPhysicalDeviceMaintenance9PropertiesKHR";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
        return "VkQueueFamilyOwnershipTransferPropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_2_FEATURES_KHR:
        return "VkPhysicalDeviceVideoMaintenance2FeaturesKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_INLINE_SESSION_PARAMETERS_INFO_KHR:
        return "VkVideoDecodeH264InlineSessionParametersInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_INLINE_SESSION_PARAMETERS_INFO_KHR:
        return "VkVideoDecodeH265InlineSessionParametersInfoKHR";
    case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_INLINE_SESSION_PARAMETERS_INFO_KHR:
        return "VkVideoDecodeAV1InlineSessionParametersInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
        return "VkPhysicalDeviceDepthClampZeroOneFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR:
        return "VkPhysicalDeviceRobustness2FeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR:
        return "VkPhysicalDeviceRobustness2PropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR:
        return "VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
        return "VkPhysicalDeviceMaintenance10FeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
        return "VkPhysicalDeviceMaintenance10PropertiesKHR";
    case VK_STRUCTURE_TYPE_RENDERING_END_INFO_KHR:
        return "VkRenderingEndInfoKHR";
    case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
        return "VkRenderingAttachmentFlagsInfoKHR";
    case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
        return "VkResolveImageModeInfoKHR";
    case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
        return "VkDebugReportCallbackCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
        return "VkPipelineRasterizationStateRasterizationOrderAMD";
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
        return "VkDebugMarkerObjectNameInfoEXT";
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
        return "VkDebugMarkerObjectTagInfoEXT";
    case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
        return "VkDebugMarkerMarkerInfoEXT";
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
        return "VkDedicatedAllocationImageCreateInfoNV";
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
        return "VkDedicatedAllocationBufferCreateInfoNV";
    case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
        return "VkDedicatedAllocationMemoryAllocateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        return "VkPhysicalDeviceTransformFeedbackFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
        return "VkPhysicalDeviceTransformFeedbackPropertiesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
        return "VkPipelineRasterizationStateStreamCreateInfoEXT";
    case VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX:
        return "VkCuModuleCreateInfoNVX";
    case VK_STRUCTURE_TYPE_CU_MODULE_TEXTURING_MODE_CREATE_INFO_NVX:
        return "VkCuModuleTexturingModeCreateInfoNVX";
    case VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX:
        return "VkCuFunctionCreateInfoNVX";
    case VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX:
        return "VkCuLaunchInfoNVX";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
        return "VkImageViewHandleInfoNVX";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
        return "VkImageViewAddressPropertiesNVX";
    case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
        return "VkTextureLODGatherFormatPropertiesAMD";
#ifdef VK_USE_PLATFORM_GGP
    case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
        return "VkStreamDescriptorSurfaceCreateInfoGGP";
#endif // VK_USE_PLATFORM_GGP
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
        return "VkPhysicalDeviceCornerSampledImageFeaturesNV";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
        return "VkExternalMemoryImageCreateInfoNV";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
        return "VkExportMemoryAllocateInfoNV";
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        return "VkImportMemoryWin32HandleInfoNV";
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
        return "VkExportMemoryWin32HandleInfoNV";
    case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
        return "VkWin32KeyedMutexAcquireReleaseInfoNV";
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
        return "VkValidationFlagsEXT";
#ifdef VK_USE_PLATFORM_VI_NN
    case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
        return "VkViSurfaceCreateInfoNN";
#endif // VK_USE_PLATFORM_VI_NN
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
        return "VkImageViewASTCDecodeModeEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
        return "VkPhysicalDeviceASTCDecodeFeaturesEXT";
    case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
        return "VkConditionalRenderingBeginInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
        return "VkPhysicalDeviceConditionalRenderingFeaturesEXT";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
        return "VkCommandBufferInheritanceConditionalRenderingInfoEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
        return "VkPipelineViewportWScalingStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
        return "VkSurfaceCapabilities2EXT";
    case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
        return "VkDisplayPowerInfoEXT";
    case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
        return "VkDeviceEventInfoEXT";
    case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
        return "VkDisplayEventInfoEXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
        return "VkSwapchainCounterCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
        return "VkPresentTimesInfoGOOGLE";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
        return "VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX";
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
        return "VkMultiviewPerViewAttributesInfoNVX";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
        return "VkPipelineViewportSwizzleStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
        return "VkPhysicalDeviceDiscardRectanglePropertiesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
        return "VkPipelineDiscardRectangleStateCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
        return "VkPhysicalDeviceConservativeRasterizationPropertiesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
        return "VkPipelineRasterizationConservativeStateCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
        return "VkPhysicalDeviceDepthClipEnableFeaturesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
        return "VkPipelineRasterizationDepthClipStateCreateInfoEXT";
    case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
        return "VkHdrMetadataEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
        return "VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG";
#ifdef VK_USE_PLATFORM_IOS_MVK
    case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
        return "VkIOSSurfaceCreateInfoMVK";
#endif // VK_USE_PLATFORM_IOS_MVK
#ifdef VK_USE_PLATFORM_MACOS_MVK
    case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
        return "VkMacOSSurfaceCreateInfoMVK";
#endif // VK_USE_PLATFORM_MACOS_MVK
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
        return "VkDebugUtilsLabelEXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
        return "VkDebugUtilsObjectNameInfoEXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
        return "VkDebugUtilsMessengerCallbackDataEXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
        return "VkDebugUtilsMessengerCreateInfoEXT";
    case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
        return "VkDebugUtilsObjectTagInfoEXT";
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
        return "VkAndroidHardwareBufferUsageANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
        return "VkAndroidHardwareBufferPropertiesANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
        return "VkAndroidHardwareBufferFormatPropertiesANDROID";
    case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
        return "VkImportAndroidHardwareBufferInfoANDROID";
    case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
        return "VkMemoryGetAndroidHardwareBufferInfoANDROID";
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
        return "VkExternalFormatANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
        return "VkAndroidHardwareBufferFormatProperties2ANDROID";
#endif // VK_USE_PLATFORM_ANDROID_KHR
#ifdef VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX:
        return "VkPhysicalDeviceShaderEnqueueFeaturesAMDX";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX:
        return "VkPhysicalDeviceShaderEnqueuePropertiesAMDX";
    case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX:
        return "VkExecutionGraphPipelineScratchSizeAMDX";
    case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX:
        return "VkExecutionGraphPipelineCreateInfoAMDX";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX:
        return "VkPipelineShaderStageNodeCreateInfoAMDX";
#endif // VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
        return "VkAttachmentSampleCountInfoAMD";
    case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
        return "VkSampleLocationsInfoEXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
        return "VkRenderPassSampleLocationsBeginInfoEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
        return "VkPipelineSampleLocationsStateCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
        return "VkPhysicalDeviceSampleLocationsPropertiesEXT";
    case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
        return "VkMultisamplePropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
        return "VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
        return "VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
        return "VkPipelineColorBlendAdvancedStateCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
        return "VkPipelineCoverageToColorStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
        return "VkPipelineCoverageModulationStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
        return "VkPhysicalDeviceShaderSMBuiltinsPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
        return "VkPhysicalDeviceShaderSMBuiltinsFeaturesNV";
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
        return "VkDrmFormatModifierPropertiesListEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
        return "VkPhysicalDeviceImageDrmFormatModifierInfoEXT";
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
        return "VkImageDrmFormatModifierListCreateInfoEXT";
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
        return "VkImageDrmFormatModifierExplicitCreateInfoEXT";
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
        return "VkImageDrmFormatModifierPropertiesEXT";
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
        return "VkDrmFormatModifierPropertiesList2EXT";
    case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
        return "VkValidationCacheCreateInfoEXT";
    case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
        return "VkShaderModuleValidationCacheCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
        return "VkPipelineViewportShadingRateImageStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
        return "VkPhysicalDeviceShadingRateImageFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
        return "VkPhysicalDeviceShadingRateImagePropertiesNV";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
        return "VkPipelineViewportCoarseSampleOrderStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
        return "VkRayTracingShaderGroupCreateInfoNV";
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
        return "VkRayTracingPipelineCreateInfoNV";
    case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
        return "VkGeometryTrianglesNV";
    case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
        return "VkGeometryAABBNV";
    case VK_STRUCTURE_TYPE_GEOMETRY_NV:
        return "VkGeometryNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
        return "VkAccelerationStructureInfoNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
        return "VkAccelerationStructureCreateInfoNV";
    case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
        return "VkBindAccelerationStructureMemoryInfoNV";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
        return "VkWriteDescriptorSetAccelerationStructureNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
        return "VkAccelerationStructureMemoryRequirementsInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
        return "VkPhysicalDeviceRayTracingPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
        return "VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV";
    case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
        return "VkPipelineRepresentativeFragmentTestStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
        return "VkPhysicalDeviceImageViewImageFormatInfoEXT";
    case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
        return "VkFilterCubicImageViewImageFormatPropertiesEXT";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
        return "VkImportMemoryHostPointerInfoEXT";
    case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
        return "VkMemoryHostPointerPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
        return "VkPhysicalDeviceExternalMemoryHostPropertiesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
        return "VkPipelineCompilerControlCreateInfoAMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
        return "VkPhysicalDeviceShaderCorePropertiesAMD";
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
        return "VkDeviceMemoryOverallocationCreateInfoAMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
        return "VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT";
#ifdef VK_USE_PLATFORM_GGP
    case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
        return "VkPresentFrameTokenGGP";
#endif // VK_USE_PLATFORM_GGP
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
        return "VkPhysicalDeviceMeshShaderFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
        return "VkPhysicalDeviceMeshShaderPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
        return "VkPhysicalDeviceShaderImageFootprintFeaturesNV";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
        return "VkPipelineViewportExclusiveScissorStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
        return "VkPhysicalDeviceExclusiveScissorFeaturesNV";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
        return "VkQueueFamilyCheckpointPropertiesNV";
    case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
        return "VkCheckpointDataNV";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
        return "VkQueueFamilyCheckpointProperties2NV";
    case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
        return "VkCheckpointData2NV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_TIMING_FEATURES_EXT:
        return "VkPhysicalDevicePresentTimingFeaturesEXT";
    case VK_STRUCTURE_TYPE_PRESENT_TIMING_SURFACE_CAPABILITIES_EXT:
        return "VkPresentTimingSurfaceCapabilitiesEXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_CALIBRATED_TIMESTAMP_INFO_EXT:
        return "VkSwapchainCalibratedTimestampInfoEXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_TIMING_PROPERTIES_EXT:
        return "VkSwapchainTimingPropertiesEXT";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_TIME_DOMAIN_PROPERTIES_EXT:
        return "VkSwapchainTimeDomainPropertiesEXT";
    case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_INFO_EXT:
        return "VkPastPresentationTimingInfoEXT";
    case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_EXT:
        return "VkPastPresentationTimingEXT";
    case VK_STRUCTURE_TYPE_PAST_PRESENTATION_TIMING_PROPERTIES_EXT:
        return "VkPastPresentationTimingPropertiesEXT";
    case VK_STRUCTURE_TYPE_PRESENT_TIMING_INFO_EXT:
        return "VkPresentTimingInfoEXT";
    case VK_STRUCTURE_TYPE_PRESENT_TIMINGS_INFO_EXT:
        return "VkPresentTimingsInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
        return "VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL";
    case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
        return "VkInitializePerformanceApiInfoINTEL";
    case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
        return "VkQueryPoolPerformanceQueryCreateInfoINTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
        return "VkPerformanceMarkerInfoINTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
        return "VkPerformanceStreamMarkerInfoINTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
        return "VkPerformanceOverrideInfoINTEL";
    case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
        return "VkPerformanceConfigurationAcquireInfoINTEL";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
        return "VkPhysicalDevicePCIBusInfoPropertiesEXT";
    case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
        return "VkDisplayNativeHdrSurfaceCapabilitiesAMD";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
        return "VkSwapchainDisplayNativeHdrCreateInfoAMD";
#ifdef VK_USE_PLATFORM_FUCHSIA
    case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
        return "VkImagePipeSurfaceCreateInfoFUCHSIA";
#endif // VK_USE_PLATFORM_FUCHSIA
#ifdef VK_USE_PLATFORM_METAL_EXT
    case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
        return "VkMetalSurfaceCreateInfoEXT";
#endif // VK_USE_PLATFORM_METAL_EXT
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
        return "VkPhysicalDeviceFragmentDensityMapFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
        return "VkPhysicalDeviceFragmentDensityMapPropertiesEXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
        return "VkRenderPassFragmentDensityMapCreateInfoEXT";
    case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
        return "VkRenderingFragmentDensityMapAttachmentInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
        return "VkPhysicalDeviceShaderCoreProperties2AMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
        return "VkPhysicalDeviceCoherentMemoryFeaturesAMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
        return "VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
        return "VkPhysicalDeviceMemoryBudgetPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
        return "VkPhysicalDeviceMemoryPriorityFeaturesEXT";
    case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
        return "VkMemoryPriorityAllocateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
        return "VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
        return "VkPhysicalDeviceBufferDeviceAddressFeaturesEXT";
    case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
        return "VkBufferDeviceAddressCreateInfoEXT";
    case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
        return "VkValidationFeaturesEXT";
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
        return "VkCooperativeMatrixPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
        return "VkPhysicalDeviceCooperativeMatrixFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
        return "VkPhysicalDeviceCooperativeMatrixPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
        return "VkPhysicalDeviceCoverageReductionModeFeaturesNV";
    case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
        return "VkPipelineCoverageReductionStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
        return "VkFramebufferMixedSamplesCombinationNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
        return "VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
        return "VkPhysicalDeviceYcbcrImageArraysFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
        return "VkPhysicalDeviceProvokingVertexFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
        return "VkPhysicalDeviceProvokingVertexPropertiesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
        return "VkPipelineRasterizationProvokingVertexStateCreateInfoEXT";
#ifdef VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
        return "VkSurfaceFullScreenExclusiveInfoEXT";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
        return "VkSurfaceCapabilitiesFullScreenExclusiveEXT";
    case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
        return "VkSurfaceFullScreenExclusiveWin32InfoEXT";
#endif // VK_USE_PLATFORM_WIN32_KHR
    case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
        return "VkHeadlessSurfaceCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
        return "VkPhysicalDeviceShaderAtomicFloatFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
        return "VkPhysicalDeviceExtendedDynamicStateFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
        return "VkPhysicalDeviceMapMemoryPlacedFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
        return "VkPhysicalDeviceMapMemoryPlacedPropertiesEXT";
    case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
        return "VkMemoryMapPlacedInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
        return "VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
        return "VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
        return "VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV";
    case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
        return "VkGraphicsShaderGroupCreateInfoNV";
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
        return "VkGraphicsPipelineShaderGroupsCreateInfoNV";
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
        return "VkIndirectCommandsLayoutTokenNV";
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
        return "VkIndirectCommandsLayoutCreateInfoNV";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
        return "VkGeneratedCommandsInfoNV";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
        return "VkGeneratedCommandsMemoryRequirementsInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
        return "VkPhysicalDeviceInheritedViewportScissorFeaturesNV";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
        return "VkCommandBufferInheritanceViewportScissorInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
        return "VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
        return "VkRenderPassTransformBeginInfoQCOM";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
        return "VkCommandBufferInheritanceRenderPassTransformInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
        return "VkPhysicalDeviceDepthBiasControlFeaturesEXT";
    case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
        return "VkDepthBiasInfoEXT";
    case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
        return "VkDepthBiasRepresentationInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
        return "VkPhysicalDeviceDeviceMemoryReportFeaturesEXT";
    case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
        return "VkDeviceMemoryReportCallbackDataEXT";
    case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
        return "VkDeviceDeviceMemoryReportCreateInfoEXT";
    case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
        return "VkSamplerCustomBorderColorCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
        return "VkPhysicalDeviceCustomBorderColorPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
        return "VkPhysicalDeviceCustomBorderColorFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
        return "VkPhysicalDevicePresentBarrierFeaturesNV";
    case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
        return "VkSurfaceCapabilitiesPresentBarrierNV";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
        return "VkSwapchainPresentBarrierCreateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
        return "VkPhysicalDeviceDiagnosticsConfigFeaturesNV";
    case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
        return "VkDeviceDiagnosticsConfigCreateInfoNV";
#ifdef VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV:
        return "VkCudaModuleCreateInfoNV";
    case VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV:
        return "VkCudaFunctionCreateInfoNV";
    case VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV:
        return "VkCudaLaunchInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV:
        return "VkPhysicalDeviceCudaKernelLaunchFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV:
        return "VkPhysicalDeviceCudaKernelLaunchPropertiesNV";
#endif // VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
        return "VkPhysicalDeviceTileShadingFeaturesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
        return "VkPhysicalDeviceTileShadingPropertiesQCOM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
        return "VkRenderPassTileShadingCreateInfoQCOM";
    case VK_STRUCTURE_TYPE_PER_TILE_BEGIN_INFO_QCOM:
        return "VkPerTileBeginInfoQCOM";
    case VK_STRUCTURE_TYPE_PER_TILE_END_INFO_QCOM:
        return "VkPerTileEndInfoQCOM";
    case VK_STRUCTURE_TYPE_DISPATCH_TILE_INFO_QCOM:
        return "VkDispatchTileInfoQCOM";
    case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
        return "VkQueryLowLatencySupportNV";
#ifdef VK_USE_PLATFORM_METAL_EXT
    case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT:
        return "VkExportMetalObjectCreateInfoEXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT:
        return "VkExportMetalObjectsInfoEXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT:
        return "VkExportMetalDeviceInfoEXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT:
        return "VkExportMetalCommandQueueInfoEXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT:
        return "VkExportMetalBufferInfoEXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT:
        return "VkImportMetalBufferInfoEXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT:
        return "VkExportMetalTextureInfoEXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT:
        return "VkImportMetalTextureInfoEXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT:
        return "VkExportMetalIOSurfaceInfoEXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT:
        return "VkImportMetalIOSurfaceInfoEXT";
    case VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT:
        return "VkExportMetalSharedEventInfoEXT";
    case VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT:
        return "VkImportMetalSharedEventInfoEXT";
#endif // VK_USE_PLATFORM_METAL_EXT
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT:
        return "VkPhysicalDeviceDescriptorBufferPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT:
        return "VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT:
        return "VkPhysicalDeviceDescriptorBufferFeaturesEXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT:
        return "VkDescriptorAddressInfoEXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
        return "VkDescriptorBufferBindingInfoEXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
        return "VkDescriptorBufferBindingPushDescriptorBufferHandleEXT";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT:
        return "VkDescriptorGetInfoEXT";
    case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        return "VkBufferCaptureDescriptorDataInfoEXT";
    case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        return "VkImageCaptureDescriptorDataInfoEXT";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        return "VkImageViewCaptureDescriptorDataInfoEXT";
    case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        return "VkSamplerCaptureDescriptorDataInfoEXT";
    case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT:
        return "VkOpaqueCaptureDescriptorDataCreateInfoEXT";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
        return "VkAccelerationStructureCaptureDescriptorDataInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
        return "VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
        return "VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT";
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
        return "VkGraphicsPipelineLibraryCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
        return "VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
        return "VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
        return "VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV";
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
        return "VkPipelineFragmentShadingRateEnumStateCreateInfoNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
        return "VkAccelerationStructureGeometryMotionTrianglesDataNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
        return "VkAccelerationStructureMotionInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
        return "VkPhysicalDeviceRayTracingMotionBlurFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
        return "VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
        return "VkPhysicalDeviceFragmentDensityMap2FeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
        return "VkPhysicalDeviceFragmentDensityMap2PropertiesEXT";
    case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
        return "VkCopyCommandTransformInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
        return "VkPhysicalDeviceImageCompressionControlFeaturesEXT";
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
        return "VkImageCompressionControlEXT";
    case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
        return "VkImageCompressionPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
        return "VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
        return "VkPhysicalDevice4444FormatsFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
        return "VkPhysicalDeviceFaultFeaturesEXT";
    case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
        return "VkDeviceFaultCountsEXT";
    case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
        return "VkDeviceFaultInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
        return "VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
        return "VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT";
#ifdef VK_USE_PLATFORM_DIRECTFB_EXT
    case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
        return "VkDirectFBSurfaceCreateInfoEXT";
#endif // VK_USE_PLATFORM_DIRECTFB_EXT
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
        return "VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT";
    case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
        return "VkMutableDescriptorTypeCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
        return "VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT";
    case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
        return "VkVertexInputBindingDescription2EXT";
    case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
        return "VkVertexInputAttributeDescription2EXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
        return "VkPhysicalDeviceDrmPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
        return "VkPhysicalDeviceAddressBindingReportFeaturesEXT";
    case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
        return "VkDeviceAddressBindingCallbackDataEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
        return "VkPhysicalDeviceDepthClipControlFeaturesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
        return "VkPipelineViewportDepthClipControlCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
        return "VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT";
#ifdef VK_USE_PLATFORM_FUCHSIA
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
        return "VkImportMemoryZirconHandleInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
        return "VkMemoryZirconHandlePropertiesFUCHSIA";
    case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
        return "VkMemoryGetZirconHandleInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
        return "VkImportSemaphoreZirconHandleInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
        return "VkSemaphoreGetZirconHandleInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA:
        return "VkBufferCollectionCreateInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA:
        return "VkImportMemoryBufferCollectionFUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA:
        return "VkBufferCollectionImageCreateInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA:
        return "VkBufferCollectionConstraintsInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA:
        return "VkBufferConstraintsInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA:
        return "VkBufferCollectionBufferCreateInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA:
        return "VkSysmemColorSpaceFUCHSIA";
    case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA:
        return "VkBufferCollectionPropertiesFUCHSIA";
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA:
        return "VkImageFormatConstraintsInfoFUCHSIA";
    case VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA:
        return "VkImageConstraintsInfoFUCHSIA";
#endif // VK_USE_PLATFORM_FUCHSIA
    case VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI:
        return "VkSubpassShadingPipelineCreateInfoHUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI:
        return "VkPhysicalDeviceSubpassShadingFeaturesHUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI:
        return "VkPhysicalDeviceSubpassShadingPropertiesHUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
        return "VkPhysicalDeviceInvocationMaskFeaturesHUAWEI";
    case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
        return "VkMemoryGetRemoteAddressInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
        return "VkPhysicalDeviceExternalMemoryRDMAFeaturesNV";
    case VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT:
        return "VkPipelinePropertiesIdentifierEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT:
        return "VkPhysicalDevicePipelinePropertiesFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
        return "VkPhysicalDeviceFrameBoundaryFeaturesEXT";
    case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
        return "VkFrameBoundaryEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
        return "VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT";
    case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
        return "VkSubpassResolvePerformanceQueryEXT";
    case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
        return "VkMultisampledRenderToSingleSampledInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
        return "VkPhysicalDeviceExtendedDynamicState2FeaturesEXT";
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
        return "VkScreenSurfaceCreateInfoQNX";
#endif // VK_USE_PLATFORM_SCREEN_QNX
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
        return "VkPhysicalDeviceColorWriteEnableFeaturesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
        return "VkPipelineColorWriteCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
        return "VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
        return "VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
        return "VkVideoEncodeRgbConversionCapabilitiesVALVE";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
        return "VkVideoEncodeProfileRgbConversionInfoVALVE";
    case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
        return "VkVideoEncodeSessionRgbConversionCreateInfoVALVE";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
        return "VkPhysicalDeviceImageViewMinLodFeaturesEXT";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
        return "VkImageViewMinLodCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
        return "VkPhysicalDeviceMultiDrawFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
        return "VkPhysicalDeviceMultiDrawPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
        return "VkPhysicalDeviceImage2DViewOf3DFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
        return "VkPhysicalDeviceShaderTileImageFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
        return "VkPhysicalDeviceShaderTileImagePropertiesEXT";
    case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
        return "VkMicromapBuildInfoEXT";
    case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
        return "VkMicromapCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
        return "VkPhysicalDeviceOpacityMicromapFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
        return "VkPhysicalDeviceOpacityMicromapPropertiesEXT";
    case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
        return "VkMicromapVersionInfoEXT";
    case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
        return "VkCopyMicromapToMemoryInfoEXT";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
        return "VkCopyMemoryToMicromapInfoEXT";
    case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
        return "VkCopyMicromapInfoEXT";
    case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
        return "VkMicromapBuildSizesInfoEXT";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
        return "VkAccelerationStructureTrianglesOpacityMicromapEXT";
#ifdef VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
        return "VkPhysicalDeviceDisplacementMicromapFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
        return "VkPhysicalDeviceDisplacementMicromapPropertiesNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
        return "VkAccelerationStructureTrianglesDisplacementMicromapNV";
#endif // VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
        return "VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
        return "VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
        return "VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
        return "VkPhysicalDeviceBorderColorSwizzleFeaturesEXT";
    case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
        return "VkSamplerBorderColorComponentMappingCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
        return "VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
        return "VkPhysicalDeviceShaderCorePropertiesARM";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
        return "VkDeviceQueueShaderCoreControlCreateInfoARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
        return "VkPhysicalDeviceSchedulingControlsFeaturesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
        return "VkPhysicalDeviceSchedulingControlsPropertiesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
        return "VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
        return "VkImageViewSlicedCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
        return "VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
        return "VkDescriptorSetBindingReferenceVALVE";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
        return "VkDescriptorSetLayoutHostMappingInfoVALVE";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
        return "VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
        return "VkPhysicalDeviceRenderPassStripedFeaturesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
        return "VkPhysicalDeviceRenderPassStripedPropertiesARM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
        return "VkRenderPassStripeInfoARM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
        return "VkRenderPassStripeBeginInfoARM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
        return "VkRenderPassStripeSubmitInfoARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
        return "VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
        return "VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
        return "VkRenderPassFragmentDensityMapOffsetEndInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV:
        return "VkPhysicalDeviceCopyMemoryIndirectFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT:
        return "VkPhysicalDeviceMemoryDecompressionFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT:
        return "VkPhysicalDeviceMemoryDecompressionPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
        return "VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV";
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
        return "VkComputePipelineIndirectBufferInfoNV";
    case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
        return "VkPipelineIndirectDeviceAddressInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
        return "VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
        return "VkAccelerationStructureGeometryLinearSweptSpheresDataNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
        return "VkAccelerationStructureGeometrySpheresDataNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
        return "VkPhysicalDeviceLinearColorAttachmentFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
        return "VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
        return "VkImageViewSampleWeightCreateInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
        return "VkPhysicalDeviceImageProcessingFeaturesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
        return "VkPhysicalDeviceImageProcessingPropertiesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
        return "VkPhysicalDeviceNestedCommandBufferFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
        return "VkPhysicalDeviceNestedCommandBufferPropertiesEXT";
#ifdef VK_USE_PLATFORM_OHOS
    case VK_STRUCTURE_TYPE_NATIVE_BUFFER_USAGE_OHOS:
        return "VkNativeBufferUsageOHOS";
    case VK_STRUCTURE_TYPE_NATIVE_BUFFER_PROPERTIES_OHOS:
        return "VkNativeBufferPropertiesOHOS";
    case VK_STRUCTURE_TYPE_NATIVE_BUFFER_FORMAT_PROPERTIES_OHOS:
        return "VkNativeBufferFormatPropertiesOHOS";
    case VK_STRUCTURE_TYPE_IMPORT_NATIVE_BUFFER_INFO_OHOS:
        return "VkImportNativeBufferInfoOHOS";
    case VK_STRUCTURE_TYPE_MEMORY_GET_NATIVE_BUFFER_INFO_OHOS:
        return "VkMemoryGetNativeBufferInfoOHOS";
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_OHOS:
        return "VkExternalFormatOHOS";
#endif // VK_USE_PLATFORM_OHOS
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
        return "VkExternalMemoryAcquireUnmodifiedEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
        return "VkPhysicalDeviceExtendedDynamicState3FeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
        return "VkPhysicalDeviceExtendedDynamicState3PropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
        return "VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
        return "VkRenderPassCreationControlEXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
        return "VkRenderPassCreationFeedbackCreateInfoEXT";
    case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
        return "VkRenderPassSubpassFeedbackCreateInfoEXT";
    case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
        return "VkDirectDriverLoadingInfoLUNARG";
    case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
        return "VkDirectDriverLoadingListLUNARG";
    case VK_STRUCTURE_TYPE_TENSOR_DESCRIPTION_ARM:
        return "VkTensorDescriptionARM";
    case VK_STRUCTURE_TYPE_TENSOR_CREATE_INFO_ARM:
        return "VkTensorCreateInfoARM";
    case VK_STRUCTURE_TYPE_TENSOR_VIEW_CREATE_INFO_ARM:
        return "VkTensorViewCreateInfoARM";
    case VK_STRUCTURE_TYPE_TENSOR_MEMORY_REQUIREMENTS_INFO_ARM:
        return "VkTensorMemoryRequirementsInfoARM";
    case VK_STRUCTURE_TYPE_BIND_TENSOR_MEMORY_INFO_ARM:
        return "VkBindTensorMemoryInfoARM";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_TENSOR_ARM:
        return "VkWriteDescriptorSetTensorARM";
    case VK_STRUCTURE_TYPE_TENSOR_FORMAT_PROPERTIES_ARM:
        return "VkTensorFormatPropertiesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_PROPERTIES_ARM:
        return "VkPhysicalDeviceTensorPropertiesARM";
    case VK_STRUCTURE_TYPE_TENSOR_MEMORY_BARRIER_ARM:
        return "VkTensorMemoryBarrierARM";
    case VK_STRUCTURE_TYPE_TENSOR_DEPENDENCY_INFO_ARM:
        return "VkTensorDependencyInfoARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TENSOR_FEATURES_ARM:
        return "VkPhysicalDeviceTensorFeaturesARM";
    case VK_STRUCTURE_TYPE_DEVICE_TENSOR_MEMORY_REQUIREMENTS_ARM:
        return "VkDeviceTensorMemoryRequirementsARM";
    case VK_STRUCTURE_TYPE_TENSOR_COPY_ARM:
        return "VkTensorCopyARM";
    case VK_STRUCTURE_TYPE_COPY_TENSOR_INFO_ARM:
        return "VkCopyTensorInfoARM";
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_TENSOR_ARM:
        return "VkMemoryDedicatedAllocateInfoTensorARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_TENSOR_INFO_ARM:
        return "VkPhysicalDeviceExternalTensorInfoARM";
    case VK_STRUCTURE_TYPE_EXTERNAL_TENSOR_PROPERTIES_ARM:
        return "VkExternalTensorPropertiesARM";
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_TENSOR_CREATE_INFO_ARM:
        return "VkExternalMemoryTensorCreateInfoARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_FEATURES_ARM:
        return "VkPhysicalDeviceDescriptorBufferTensorFeaturesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_TENSOR_PROPERTIES_ARM:
        return "VkPhysicalDeviceDescriptorBufferTensorPropertiesARM";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_TENSOR_INFO_ARM:
        return "VkDescriptorGetTensorInfoARM";
    case VK_STRUCTURE_TYPE_TENSOR_CAPTURE_DESCRIPTOR_DATA_INFO_ARM:
        return "VkTensorCaptureDescriptorDataInfoARM";
    case VK_STRUCTURE_TYPE_TENSOR_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_ARM:
        return "VkTensorViewCaptureDescriptorDataInfoARM";
    case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_TENSORS_ARM:
        return "VkFrameBoundaryTensorsARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
        return "VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
        return "VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
        return "VkPipelineShaderStageModuleIdentifierCreateInfoEXT";
    case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
        return "VkShaderModuleIdentifierEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
        return "VkPhysicalDeviceOpticalFlowFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
        return "VkPhysicalDeviceOpticalFlowPropertiesNV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
        return "VkOpticalFlowImageFormatInfoNV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
        return "VkOpticalFlowImageFormatPropertiesNV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
        return "VkOpticalFlowSessionCreateInfoNV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
        return "VkOpticalFlowSessionCreatePrivateDataInfoNV";
    case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
        return "VkOpticalFlowExecuteInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
        return "VkPhysicalDeviceLegacyDitheringFeaturesEXT";
#ifdef VK_USE_PLATFORM_ANDROID_KHR
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
        return "VkPhysicalDeviceExternalFormatResolveFeaturesANDROID";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
        return "VkPhysicalDeviceExternalFormatResolvePropertiesANDROID";
    case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
        return "VkAndroidHardwareBufferFormatResolvePropertiesANDROID";
#endif // VK_USE_PLATFORM_ANDROID_KHR
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
        return "VkPhysicalDeviceAntiLagFeaturesAMD";
    case VK_STRUCTURE_TYPE_ANTI_LAG_PRESENTATION_INFO_AMD:
        return "VkAntiLagPresentationInfoAMD";
    case VK_STRUCTURE_TYPE_ANTI_LAG_DATA_AMD:
        return "VkAntiLagDataAMD";
#ifdef VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DENSE_GEOMETRY_FORMAT_FEATURES_AMDX:
        return "VkPhysicalDeviceDenseGeometryFormatFeaturesAMDX";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DENSE_GEOMETRY_FORMAT_TRIANGLES_DATA_AMDX:
        return "VkAccelerationStructureDenseGeometryFormatTrianglesDataAMDX";
#endif // VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
        return "VkPhysicalDeviceShaderObjectFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
        return "VkPhysicalDeviceShaderObjectPropertiesEXT";
    case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
        return "VkShaderCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
        return "VkPhysicalDeviceTilePropertiesFeaturesQCOM";
    case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
        return "VkTilePropertiesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
        return "VkPhysicalDeviceAmigoProfilingFeaturesSEC";
    case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
        return "VkAmigoProfilingSubmitInfoSEC";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
        return "VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
        return "VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
        return "VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
        return "VkPhysicalDeviceCooperativeVectorPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
        return "VkPhysicalDeviceCooperativeVectorFeaturesNV";
    case VK_STRUCTURE_TYPE_COOPERATIVE_VECTOR_PROPERTIES_NV:
        return "VkCooperativeVectorPropertiesNV";
    case VK_STRUCTURE_TYPE_CONVERT_COOPERATIVE_VECTOR_MATRIX_INFO_NV:
        return "VkConvertCooperativeVectorMatrixInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
        return "VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
        return "VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
        return "VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
        return "VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT";
    case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
        return "VkLayerSettingsCreateInfoEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
        return "VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
        return "VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
        return "VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
        return "VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT";
    case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
        return "VkLatencySleepModeInfoNV";
    case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
        return "VkLatencySleepInfoNV";
    case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
        return "VkSetLatencyMarkerInfoNV";
    case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
        return "VkLatencyTimingsFrameReportNV";
    case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
        return "VkGetLatencyMarkerInfoNV";
    case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
        return "VkLatencySubmissionPresentIdNV";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
        return "VkSwapchainLatencyCreateInfoNV";
    case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
        return "VkOutOfBandQueueTypeInfoNV";
    case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
        return "VkLatencySurfaceCapabilitiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_FEATURES_ARM:
        return "VkPhysicalDeviceDataGraphFeaturesARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_ARM:
        return "VkDataGraphPipelineConstantARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_RESOURCE_INFO_ARM:
        return "VkDataGraphPipelineResourceInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_COMPILER_CONTROL_CREATE_INFO_ARM:
        return "VkDataGraphPipelineCompilerControlCreateInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CREATE_INFO_ARM:
        return "VkDataGraphPipelineCreateInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SHADER_MODULE_CREATE_INFO_ARM:
        return "VkDataGraphPipelineShaderModuleCreateInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_CREATE_INFO_ARM:
        return "VkDataGraphPipelineSessionCreateInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENTS_INFO_ARM:
        return "VkDataGraphPipelineSessionBindPointRequirementsInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_BIND_POINT_REQUIREMENT_ARM:
        return "VkDataGraphPipelineSessionBindPointRequirementARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_SESSION_MEMORY_REQUIREMENTS_INFO_ARM:
        return "VkDataGraphPipelineSessionMemoryRequirementsInfoARM";
    case VK_STRUCTURE_TYPE_BIND_DATA_GRAPH_PIPELINE_SESSION_MEMORY_INFO_ARM:
        return "VkBindDataGraphPipelineSessionMemoryInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_INFO_ARM:
        return "VkDataGraphPipelineInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_PROPERTY_QUERY_RESULT_ARM:
        return "VkDataGraphPipelinePropertyQueryResultARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_IDENTIFIER_CREATE_INFO_ARM:
        return "VkDataGraphPipelineIdentifierCreateInfoARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_DISPATCH_INFO_ARM:
        return "VkDataGraphPipelineDispatchInfoARM";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROPERTIES_ARM:
        return "VkQueueFamilyDataGraphPropertiesARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PROCESSING_ENGINE_CREATE_INFO_ARM:
        return "VkDataGraphProcessingEngineCreateInfoARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_INFO_ARM:
        return "VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM";
    case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
        return "VkQueueFamilyDataGraphProcessingEnginePropertiesARM";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_CONSTANT_TENSOR_SEMI_STRUCTURED_SPARSITY_INFO_ARM:
        return "VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
        return "VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM";
    case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
        return "VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
        return "VkPhysicalDevicePerStageDescriptorSetFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
        return "VkPhysicalDeviceImageProcessing2FeaturesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
        return "VkPhysicalDeviceImageProcessing2PropertiesQCOM";
    case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
        return "VkSamplerBlockMatchWindowCreateInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
        return "VkPhysicalDeviceCubicWeightsFeaturesQCOM";
    case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
        return "VkSamplerCubicWeightsCreateInfoQCOM";
    case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
        return "VkBlitImageCubicWeightsInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
        return "VkPhysicalDeviceYcbcrDegammaFeaturesQCOM";
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
        return "VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
        return "VkPhysicalDeviceCubicClampFeaturesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
        return "VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT";
#ifdef VK_USE_PLATFORM_SCREEN_QNX
    case VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX:
        return "VkScreenBufferPropertiesQNX";
    case VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX:
        return "VkScreenBufferFormatPropertiesQNX";
    case VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX:
        return "VkImportScreenBufferInfoQNX";
    case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX:
        return "VkExternalFormatQNX";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX:
        return "VkPhysicalDeviceExternalMemoryScreenBufferFeaturesQNX";
#endif // VK_USE_PLATFORM_SCREEN_QNX
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
        return "VkPhysicalDeviceLayeredDriverPropertiesMSFT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
        return "VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
        return "VkPhysicalDeviceTileMemoryHeapFeaturesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
        return "VkPhysicalDeviceTileMemoryHeapPropertiesQCOM";
    case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
        return "VkTileMemoryRequirementsQCOM";
    case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
        return "VkTileMemoryBindInfoQCOM";
    case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
        return "VkTileMemorySizeInfoQCOM";
    case VK_STRUCTURE_TYPE_DECOMPRESS_MEMORY_INFO_EXT:
        return "VkDecompressMemoryInfoEXT";
    case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
        return "VkDisplaySurfaceStereoCreateInfoNV";
    case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
        return "VkDisplayModeStereoPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
        return "VkPhysicalDeviceRawAccessChainsFeaturesNV";
    case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DEVICE_CREATE_INFO_NV:
        return "VkExternalComputeQueueDeviceCreateInfoNV";
    case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_CREATE_INFO_NV:
        return "VkExternalComputeQueueCreateInfoNV";
    case VK_STRUCTURE_TYPE_EXTERNAL_COMPUTE_QUEUE_DATA_PARAMS_NV:
        return "VkExternalComputeQueueDataParamsNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_COMPUTE_QUEUE_PROPERTIES_NV:
        return "VkPhysicalDeviceExternalComputeQueuePropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
        return "VkPhysicalDeviceCommandBufferInheritanceFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
        return "VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
        return "VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
        return "VkPhysicalDeviceShaderFloat8FeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
        return "VkPhysicalDeviceRayTracingValidationFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_FEATURES_NV:
        return "VkPhysicalDeviceClusterAccelerationStructureFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_ACCELERATION_STRUCTURE_PROPERTIES_NV:
        return "VkPhysicalDeviceClusterAccelerationStructurePropertiesNV";
    case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_CLUSTERS_BOTTOM_LEVEL_INPUT_NV:
        return "VkClusterAccelerationStructureClustersBottomLevelInputNV";
    case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_TRIANGLE_CLUSTER_INPUT_NV:
        return "VkClusterAccelerationStructureTriangleClusterInputNV";
    case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_MOVE_OBJECTS_INPUT_NV:
        return "VkClusterAccelerationStructureMoveObjectsInputNV";
    case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_INPUT_INFO_NV:
        return "VkClusterAccelerationStructureInputInfoNV";
    case VK_STRUCTURE_TYPE_CLUSTER_ACCELERATION_STRUCTURE_COMMANDS_INFO_NV:
        return "VkClusterAccelerationStructureCommandsInfoNV";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
        return "VkAccelerationStructureBuildSizesInfoKHR";
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CLUSTER_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
        return "VkRayTracingPipelineClusterAccelerationStructureCreateInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
        return "VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
        return "VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV";
    case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
        return "VkPartitionedAccelerationStructureFlagsNV";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
        return "VkWriteDescriptorSetPartitionedAccelerationStructureNV";
    case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_INSTANCES_INPUT_NV:
        return "VkPartitionedAccelerationStructureInstancesInputNV";
    case VK_STRUCTURE_TYPE_BUILD_PARTITIONED_ACCELERATION_STRUCTURE_INFO_NV:
        return "VkBuildPartitionedAccelerationStructureInfoNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
        return "VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
        return "VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_EXT:
        return "VkGeneratedCommandsMemoryRequirementsInfoEXT";
    case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_PIPELINE_INFO_EXT:
        return "VkIndirectExecutionSetPipelineInfoEXT";
    case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_LAYOUT_INFO_EXT:
        return "VkIndirectExecutionSetShaderLayoutInfoEXT";
    case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_SHADER_INFO_EXT:
        return "VkIndirectExecutionSetShaderInfoEXT";
    case VK_STRUCTURE_TYPE_INDIRECT_EXECUTION_SET_CREATE_INFO_EXT:
        return "VkIndirectExecutionSetCreateInfoEXT";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_EXT:
        return "VkGeneratedCommandsInfoEXT";
    case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_PIPELINE_EXT:
        return "VkWriteIndirectExecutionSetPipelineEXT";
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_EXT:
        return "VkIndirectCommandsLayoutTokenEXT";
    case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_EXT:
        return "VkIndirectCommandsLayoutCreateInfoEXT";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
        return "VkGeneratedCommandsPipelineInfoEXT";
    case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
        return "VkGeneratedCommandsShaderInfoEXT";
    case VK_STRUCTURE_TYPE_WRITE_INDIRECT_EXECUTION_SET_SHADER_EXT:
        return "VkWriteIndirectExecutionSetShaderEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
        return "VkPhysicalDeviceImageAlignmentControlFeaturesMESA";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
        return "VkPhysicalDeviceImageAlignmentControlPropertiesMESA";
    case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
        return "VkImageAlignmentControlCreateInfoMESA";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
        return "VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
        return "VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
        return "VkPhysicalDeviceDepthClampControlFeaturesEXT";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
        return "VkPipelineViewportDepthClampControlCreateInfoEXT";
#ifdef VK_USE_PLATFORM_OHOS
    case VK_STRUCTURE_TYPE_SURFACE_CREATE_INFO_OHOS:
        return "VkSurfaceCreateInfoOHOS";
    case VK_STRUCTURE_TYPE_NATIVE_BUFFER_OHOS:
        return "VkNativeBufferOHOS";
    case VK_STRUCTURE_TYPE_SWAPCHAIN_IMAGE_CREATE_INFO_OHOS:
        return "VkSwapchainImageCreateInfoOHOS";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENTATION_PROPERTIES_OHOS:
        return "VkPhysicalDevicePresentationPropertiesOHOS";
#endif // VK_USE_PLATFORM_OHOS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
        return "VkPhysicalDeviceHdrVividFeaturesHUAWEI";
    case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
        return "VkHdrVividDynamicMetadataHUAWEI";
    case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_FLEXIBLE_DIMENSIONS_PROPERTIES_NV:
        return "VkCooperativeMatrixFlexibleDimensionsPropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
        return "VkPhysicalDeviceCooperativeMatrix2FeaturesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
        return "VkPhysicalDeviceCooperativeMatrix2PropertiesNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
        return "VkPhysicalDevicePipelineOpacityMicromapFeaturesARM";
#ifdef VK_USE_PLATFORM_METAL_EXT
    case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
        return "VkImportMemoryMetalHandleInfoEXT";
    case VK_STRUCTURE_TYPE_MEMORY_METAL_HANDLE_PROPERTIES_EXT:
        return "VkMemoryMetalHandlePropertiesEXT";
    case VK_STRUCTURE_TYPE_MEMORY_GET_METAL_HANDLE_INFO_EXT:
        return "VkMemoryGetMetalHandleInfoEXT";
#endif // VK_USE_PLATFORM_METAL_EXT
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
        return "VkPhysicalDevicePerformanceCountersByRegionFeaturesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
        return "VkPhysicalDevicePerformanceCountersByRegionPropertiesARM";
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_ARM:
        return "VkPerformanceCounterARM";
    case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_ARM:
        return "VkPerformanceCounterDescriptionARM";
    case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
        return "VkRenderPassPerformanceCountersByRegionBeginInfoARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
        return "VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
        return "VkPhysicalDeviceFormatPackFeaturesARM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
        return "VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
        return "VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE";
    case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
        return "VkPipelineFragmentDensityMapLayeredCreateInfoVALVE";
#ifdef VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
        return "VkSetPresentConfigNV";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
        return "VkPhysicalDevicePresentMeteringFeaturesNV";
#endif // VK_ENABLE_BETA_EXTENSIONS
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
        return "VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
        return "VkPhysicalDeviceShader64BitIndexingFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
        return "VkPhysicalDeviceCustomResolveFeaturesEXT";
    case VK_STRUCTURE_TYPE_BEGIN_CUSTOM_RESOLVE_INFO_EXT:
        return "VkBeginCustomResolveInfoEXT";
    case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
        return "VkCustomResolveCreateInfoEXT";
    case VK_STRUCTURE_TYPE_DATA_GRAPH_PIPELINE_BUILTIN_MODEL_CREATE_INFO_QCOM:
        return "VkDataGraphPipelineBuiltinModelCreateInfoQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
        return "VkPhysicalDeviceDataGraphModelFeaturesQCOM";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
        return "VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
        return "VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
        return "VkAccelerationStructureGeometryTrianglesDataKHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
        return "VkAccelerationStructureGeometryAabbsDataKHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
        return "VkAccelerationStructureGeometryInstancesDataKHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
        return "VkAccelerationStructureGeometryKHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
        return "VkAccelerationStructureBuildGeometryInfoKHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
        return "VkAccelerationStructureCreateInfoKHR";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
        return "VkWriteDescriptorSetAccelerationStructureKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
        return "VkPhysicalDeviceAccelerationStructureFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
        return "VkPhysicalDeviceAccelerationStructurePropertiesKHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
        return "VkAccelerationStructureDeviceAddressInfoKHR";
    case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
        return "VkAccelerationStructureVersionInfoKHR";
    case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
        return "VkCopyAccelerationStructureToMemoryInfoKHR";
    case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
        return "VkCopyMemoryToAccelerationStructureInfoKHR";
    case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
        return "VkCopyAccelerationStructureInfoKHR";
    case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
        return "VkRayTracingShaderGroupCreateInfoKHR";
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
        return "VkRayTracingPipelineInterfaceCreateInfoKHR";
    case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
        return "VkRayTracingPipelineCreateInfoKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
        return "VkPhysicalDeviceRayTracingPipelineFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
        return "VkPhysicalDeviceRayTracingPipelinePropertiesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
        return "VkPhysicalDeviceRayQueryFeaturesKHR";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
        return "VkPhysicalDeviceMeshShaderFeaturesEXT";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
        return "VkPhysicalDeviceMeshShaderPropertiesEXT";
    default:
        return "Unhandled VkStructureType";
    }
}
} // namespace impl
} // namespace VulkanBindings
