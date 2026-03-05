#pragma once

#include <Vulkan.hpp>

#include <cassert>
#include <expected>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// #define MY_VK_IMPL_PRINT_MEM_OPS

#ifdef MY_VK_IMPL_PRINT_MEM_OPS
#include <typeinfo>
#endif

#include <Structures.hpp>

namespace VkBindings {

namespace impl {

#ifdef MY_VK_IMPL_PRINT_MEM_OPS
std::string demangle(const char *name);

#ifndef NDEBUG
extern std::unordered_map<uint64_t, std::string> objectNameStorage;
#define MY_VK_PRINT_ADDR_SIMPLE(os, ptr)                                                           \
    do {                                                                                           \
        auto it = VkBindings::impl::objectNameStorage.find((uint64_t)ptr);                         \
        if (it != VkBindings::impl::objectNameStorage.end()) {                                     \
            (os) << it->second;                                                                    \
        } else {                                                                                   \
            auto _old_flags = (os).flags();                                                        \
            char _old_fill = (os).fill();                                                          \
            (os) << "0x" << std::hex << std::nouppercase << reinterpret_cast<std::uintptr_t>(ptr); \
            (os).flags(_old_flags);                                                                \
            (os).fill(_old_fill);                                                                  \
        }                                                                                          \
    } while (0)
#else
#define MY_VK_PRINT_ADDR_SIMPLE(os, ptr)                                                           \
    do {                                                                                           \
        auto _old_flags = (os).flags();                                                            \
        char _old_fill = (os).fill();                                                              \
        (os) << "0x" << std::hex << std::nouppercase << reinterpret_cast<std::uintptr_t>(ptr);     \
        (os).flags(_old_flags);                                                                    \
        (os).fill(_old_fill);                                                                      \
    } while (0)
#endif

#define MY_VK_IMPL_PRINT_MEM_FUNCTION(type)                                                        \
    do {                                                                                           \
        MY_VK_PRINT_ADDR_SIMPLE(std::cout, handle);                                                \
        std::cout << " in " << VkBindings::impl::demangle(typeid(Handle_T).name())                 \
                  << "::" << (type) << "\n";                                                       \
    } while (0)

#define MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC(type, container, access)                                 \
    do {                                                                                           \
        std::cout << "{ ";                                                                         \
        for (size_t _i = 0; _i < (container).size(); ++_i) {                                       \
            MY_VK_PRINT_ADDR_SIMPLE(std::cout, (container)[_i] access);                            \
            std::cout << " ";                                                                      \
        }                                                                                          \
        std::cout << "} in " << VkBindings::impl::demangle(typeid(Handle_T).name())                \
                  << "::" << (type) << "\n";                                                       \
    } while (0)

#else
#define MY_VK_IMPL_PRINT_MEM_FUNCTION(type)
#define MY_VK_IMPL_PRINT_MEM_FUNCTION_VEC(type, container, access)
#endif

const char *VkResultToString(VkResult);
const char *VkStructureNameToString(VkStructureType);

extern thread_local VkResult LastResult;

struct Instance;
struct PhyisicalDevice;
struct Device;
struct Queue;

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, typename Create_Info_T,
          VkObjectType VK_Obj_T, auto Create_Fun, auto Destroy_Fun>
    requires requires(Handle_T h, Owner_Handle_T o, Create_Info_T *c) {
        { (*Create_Fun)(o, c, nullptr, &h) } -> std::same_as<VkResult>;
        { (*Destroy_Fun)(o, h, nullptr) } -> std::same_as<void>;
    }
struct OwnedHandle {
    using owner_type = Owner_T;
    using handle_type = Handle_T;
    static constexpr const VkObjectType vk_object_type = VK_Obj_T;

    Owner_Handle_T owner{VK_NULL_HANDLE};
    Handle_T handle{VK_NULL_HANDLE};

  private:
    OwnedHandle(Owner_Handle_T owner, const Create_Info_T *pCreateInfo,
                const VkAllocationCallbacks *pAllocator = nullptr)
        : owner(owner) {
        if (VkResult res = (*Create_Fun)(owner, pCreateInfo, pAllocator, &handle);
            res != VK_SUCCESS) {
            std::cerr << "failed to create: " << VkStructureNameToString(pCreateInfo->sType)
                      << " error: " << VkResultToString(res) << "\n";
            handle = VK_NULL_HANDLE;
            owner = VK_NULL_HANDLE;
            LastResult = res;
        }
    }
    friend Owner_T;

  public:
    OwnedHandle(Handle_T handle) : owner(VK_NULL_HANDLE), handle(handle) {}

    OwnedHandle() {}

    OwnedHandle(OwnedHandle &&o) noexcept
        : owner(std::exchange(o.owner, VK_NULL_HANDLE)),
          handle(std::exchange(o.handle, VK_NULL_HANDLE)) {
        assert(handle != VK_NULL_HANDLE && "Moved from object was empty");
        MY_VK_IMPL_PRINT_MEM_FUNCTION("move constructor");
    }
    OwnedHandle &operator=(OwnedHandle &&o) noexcept {
        if (this != &o) {
            cleanup();
            owner = std::exchange(o.owner, VK_NULL_HANDLE);
            handle = std::exchange(o.handle, VK_NULL_HANDLE);
            assert(handle != VK_NULL_HANDLE && "Moved from object was empty");
            MY_VK_IMPL_PRINT_MEM_FUNCTION("move assignment");
        }
        return *this;
    }

    OwnedHandle(const OwnedHandle &) = delete;
    OwnedHandle &operator=(const OwnedHandle &) = delete;

    ~OwnedHandle() { cleanup(); }

    void cleanup() noexcept {
        if (owner != VK_NULL_HANDLE && handle != VK_NULL_HANDLE) {
            MY_VK_IMPL_PRINT_MEM_FUNCTION("deconstructor");
            (*Destroy_Fun)(owner, handle, nullptr);
            owner = VK_NULL_HANDLE;
            handle = VK_NULL_HANDLE;
        }
    }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template <typename Handle_T, typename Owner_T, typename Owner_Handle_T, VkObjectType VK_Obj_T,
          auto Destroy_Fun>
    requires requires(Handle_T h, Owner_Handle_T o) {
        { (*Destroy_Fun)(o, h, nullptr) } -> std::same_as<void>;
    }
struct OwnedHandleExternCreate {
    using owner_type = Owner_T;
    using handle_type = Handle_T;
    static constexpr const VkObjectType vk_object_type = VK_Obj_T;

    Owner_T::handle_type owner{VK_NULL_HANDLE};
    Handle_T handle{VK_NULL_HANDLE};

    OwnedHandleExternCreate(Owner_Handle_T owner, Handle_T &&handle)
        : owner(owner), handle(std::move(handle)) {}
    OwnedHandleExternCreate() {}

    OwnedHandleExternCreate(OwnedHandleExternCreate &&o) noexcept
        : owner(std::exchange(o.owner, VK_NULL_HANDLE)),
          handle(std::exchange(o.handle, VK_NULL_HANDLE)) {
        assert(handle != VK_NULL_HANDLE && "Moved from object was empty");
        MY_VK_IMPL_PRINT_MEM_FUNCTION("move constructor");
    }

    OwnedHandleExternCreate &operator=(OwnedHandleExternCreate &&o) noexcept {
        if (this != &o) {
            cleanup();
            owner = std::exchange(o.owner, VK_NULL_HANDLE);
            handle = std::exchange(o.handle, VK_NULL_HANDLE);
            assert(handle != VK_NULL_HANDLE && "Moved from object was empty");
            MY_VK_IMPL_PRINT_MEM_FUNCTION("move assignment");
        }
        return *this;
    }

    OwnedHandleExternCreate(const OwnedHandleExternCreate &) = delete;
    OwnedHandleExternCreate &operator=(const OwnedHandleExternCreate &) = delete;

    ~OwnedHandleExternCreate() { cleanup(); }

    void cleanup() noexcept {
        if (handle != VK_NULL_HANDLE) {
            MY_VK_IMPL_PRINT_MEM_FUNCTION("deconstructor");
            (*Destroy_Fun)(owner, handle, nullptr);
            owner = VK_NULL_HANDLE;
            handle = VK_NULL_HANDLE;
        }
    }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

struct DescriptorSets {
    using Handle_T = VkDescriptorSet;
    static constexpr const VkObjectType vk_object_type = VK_OBJECT_TYPE_DESCRIPTOR_SET;

    VkDevice owner{VK_NULL_HANDLE};
    VkDescriptorPool pool{VK_NULL_HANDLE};
    std::vector<VkDescriptorSet> handle{};

  private:
    DescriptorSets(VkDevice owner, const VkDescriptorSetAllocateInfo *pAllocateInfo);
    friend Device;

  public:
    DescriptorSets() {}

    DescriptorSets(DescriptorSets &&o) noexcept;
    DescriptorSets &operator=(DescriptorSets &&o) noexcept;

    DescriptorSets(const DescriptorSets &) = delete;
    DescriptorSets &operator=(const DescriptorSets &) = delete;

    ~DescriptorSets();

    void cleanup() noexcept;

    explicit operator bool() const noexcept;

    VkDescriptorSet operator[](size_t n);
};

template <typename Handle_T> struct NonOwnedHandle {
    Handle_T handle{VK_NULL_HANDLE};

    NonOwnedHandle(Handle_T &&handle) : handle(std::move(handle)) {}
    NonOwnedHandle() {}
    operator Handle_T() const { return handle; }
};

struct Image : public OwnedHandle<VkImage, Device, VkDevice, VkImageCreateInfo,
                                  VK_OBJECT_TYPE_IMAGE, &vkCreateImage, &vkDestroyImage> {
    using OwnedHandle::OwnedHandle;

    VkImageLayout layout = VK_IMAGE_LAYOUT_UNDEFINED;
};

struct CommandBuffer : NonOwnedHandle<VkCommandBuffer> {
    using NonOwnedHandle::NonOwnedHandle;

    [[nodiscard]] std::expected<void, VkResult> begin(VkCommandBufferBeginInfo *pBeginInfo) const;
    [[nodiscard]] std::expected<void, VkResult> end() const;
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, uint32_t regionCount,
                    const VkBufferCopy *pRegions) const;
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, const VkBufferCopy *region) const;
    void copyBufferToImage(VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout,
                           uint32_t regionCount, const VkBufferImageCopy *pRegions) const;
    void copyBufferToImage(VkBuffer srcBuffer, VkImage dstImage, VkImageLayout dstImageLayout,
                           const VkBufferImageCopy *pRegion) const;
    void copyImageToBuffer(VkImage srcImage, VkImageLayout srcImageLayout, VkBuffer dstBuffer,
                           uint32_t regionCount, const VkBufferImageCopy *pRegions) const;
    void pipelineBarrier(VkPipelineStageFlags srcStageMask, VkPipelineStageFlags dstStageMask,
                         VkDependencyFlags dependencyFlags, uint32_t memoryBarrierCount,
                         const VkMemoryBarrier *pMemoryBarriers, uint32_t bufferMemoryBarrierCount,
                         const VkBufferMemoryBarrier *pBufferMemoryBarriers,
                         uint32_t imageMemoryBarrierCount,
                         const VkImageMemoryBarrier *pImageMemoryBarriers) const;
    void bindPipeline(VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline) const;
    void setViewport(VkViewport viewport) const;
    void setScissor(VkRect2D scissor) const;
    void bindDescriptorSets(VkPipelineBindPoint pipelineBindPoint, VkPipelineLayout layout,
                            uint32_t firstSet, uint32_t descriptorSetCount,
                            const VkDescriptorSet *pDescriptorSets, uint32_t dynamicOffsetCount,
                            const uint32_t *pDynamicOffsets) const;
    void dispatch(uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ) const;
    void beginRendering(const VkRenderingInfo *pRenderingInfo) const;
    void endRendering() const;
    void pushConstants(VkPipelineLayout layout, VkShaderStageFlags stageFlags, uint32_t offset,
                       uint32_t size, const void *pValues) const;
    void bindVertexBuffers(uint32_t firstBinding, uint32_t bindingCount, const VkBuffer *pBuffers,
                           const VkDeviceSize *pOffsets) const;
    void bindVertexBuffer(uint32_t firstBinding, VkBuffer buffer, VkDeviceSize offset) const;
    void bindIndexBuffer(VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType) const;
    void draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex,
              uint32_t firstInstance) const;
    void drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                     int32_t vertexOffset, uint32_t firstInstance) const;
    [[nodiscard]] std::expected<void, VkResult> reset(VkCommandBufferResetFlags flags) const;
};

struct OwnedHandleCommandBuffers {
    using Handle_T = VkCommandBuffer;
    static constexpr const VkObjectType vk_object_type = VK_OBJECT_TYPE_COMMAND_BUFFER;

    VkDevice owner{VK_NULL_HANDLE};
    VkCommandPool pool{VK_NULL_HANDLE};
    std::vector<CommandBuffer> handle{};

    OwnedHandleCommandBuffers(VkDevice owner, const VkCommandBufferAllocateInfo *pAllocateInfo);
    OwnedHandleCommandBuffers() {}

    OwnedHandleCommandBuffers(OwnedHandleCommandBuffers &&o) noexcept;

    OwnedHandleCommandBuffers &operator=(OwnedHandleCommandBuffers &&o) noexcept;

    OwnedHandleCommandBuffers(const OwnedHandleCommandBuffers &) = delete;
    OwnedHandleCommandBuffers &operator=(const OwnedHandleCommandBuffers &) = delete;

    size_t size() const { return handle.size(); }

    ~OwnedHandleCommandBuffers();

    void cleanup() noexcept;
    explicit operator bool() const noexcept;

    CommandBuffer &operator[](size_t n);
};

template <typename Handle_T, typename Create_Info_T, VkObjectType VK_Obj_T, auto Create_Fun,
          auto Destroy_Fun>
struct Handle {
    using handle_type = Handle_T;
    static constexpr const VkObjectType vk_object_type = VK_Obj_T;

    Handle_T handle{VK_NULL_HANDLE};

    Handle(const Create_Info_T *pCreateInfo, const VkAllocationCallbacks *pAllocator = nullptr) {
        if (VkResult res = (*Create_Fun)(pCreateInfo, pAllocator, &handle); res != VK_SUCCESS) {
            std::cerr << "failed to create: " << VkStructureNameToString(pCreateInfo->sType)
                      << " error: " << VkResultToString(res) << "\n";
            handle = VK_NULL_HANDLE;
            LastResult = res;
        }
    }

    Handle() {}

    Handle(Handle &&o) noexcept : handle(std::exchange(o.handle, VK_NULL_HANDLE)) {
        assert(handle != VK_NULL_HANDLE && "Moved from object was empty");
        MY_VK_IMPL_PRINT_MEM_FUNCTION("move constructor");
    }
    Handle &operator=(Handle &&o) noexcept {
        if (this != &o) {
            cleanup();
            handle = std::exchange(o.handle, VK_NULL_HANDLE);
            assert(handle != VK_NULL_HANDLE && "Moved from object was empty");
            MY_VK_IMPL_PRINT_MEM_FUNCTION("move assignment");
        }
        return *this;
    }

    Handle(const Handle &) = delete;
    Handle &operator=(const Handle &) = delete;

    ~Handle() { cleanup(); }

    void cleanup() noexcept {
        if (handle != VK_NULL_HANDLE) {
            MY_VK_IMPL_PRINT_MEM_FUNCTION("deconstructor");
            (*Destroy_Fun)(handle, nullptr);
            handle = VK_NULL_HANDLE;
        }
    }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};

template <typename Handle_T, typename Creator_T, typename Create_Info_T, VkObjectType VK_Obj_T,
          auto Create_Fun, auto Destroy_Fun>
struct CreatorHandle {
    using handle_type = Handle_T;
    static constexpr const VkObjectType vk_object_type = VK_Obj_T;

    Handle_T handle{VK_NULL_HANDLE};

    CreatorHandle(Creator_T creator, const Create_Info_T *pCreateInfo,
                  const VkAllocationCallbacks *pAllocator = nullptr) {
        if (VkResult res = (*Create_Fun)(creator, pCreateInfo, pAllocator, &handle);
            res != VK_SUCCESS) {
            std::cerr << "failed to create: " << VkStructureNameToString(pCreateInfo->sType)
                      << " error: " << VkResultToString(res) << "\n";
            handle = VK_NULL_HANDLE;
            LastResult = res;
        }
    }

    CreatorHandle() {}

    CreatorHandle(CreatorHandle &&o) noexcept : handle(o.handle) { o.handle = VK_NULL_HANDLE; }
    CreatorHandle &operator=(CreatorHandle &&o) noexcept {
        if (this != &o) {
            cleanup();
            handle = std::exchange(o.handle, VK_NULL_HANDLE);
            assert(handle != VK_NULL_HANDLE && "Moved from object was empty");
            MY_VK_IMPL_PRINT_MEM_FUNCTION("move assigment");
        }
        return *this;
    }

    CreatorHandle(const CreatorHandle &) = delete;
    CreatorHandle &operator=(const CreatorHandle &) = delete;

    ~CreatorHandle() { cleanup(); }

    void cleanup() noexcept {
        if (handle != VK_NULL_HANDLE) {
            MY_VK_IMPL_PRINT_MEM_FUNCTION("deconstructor");
            (*Destroy_Fun)(handle, nullptr);
            handle = VK_NULL_HANDLE;
        }
    }

    Handle_T get() const noexcept { return handle; }
    explicit operator bool() const noexcept { return handle != VK_NULL_HANDLE; }
    operator Handle_T() const noexcept { return handle; }
};
}; // namespace impl

extern VkResult VkLastResult();

// clang-format off
using UniqueVkInstance =               impl::Instance;
using HandleVkPhysicalDevice =         impl::PhyisicalDevice;
using UniqueVkDevice =                 impl::Device;

using HandleVkQueue =                  impl::Queue;

using UniqueVkSurfaceKHR =             impl::OwnedHandleExternCreate<VkSurfaceKHR, UniqueVkInstance, VkInstance, VK_OBJECT_TYPE_SURFACE_KHR, &vkDestroySurfaceKHR>;
using UniqueVkDebugUtilsMessengerEXT = impl::OwnedHandle<VkDebugUtilsMessengerEXT, UniqueVkInstance, VkInstance, VkDebugUtilsMessengerCreateInfoEXT, VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT, &vkCreateDebugUtilsMessengerEXT, &vkDestroyDebugUtilsMessengerEXT>;
using UniqueVkSwapchainKHR =           impl::OwnedHandle<VkSwapchainKHR, UniqueVkDevice, VkDevice, VkSwapchainCreateInfoKHR, VK_OBJECT_TYPE_SWAPCHAIN_KHR, &vkCreateSwapchainKHR, &vkDestroySwapchainKHR>;


using UniqueVkImage =                  impl::Image;
using UniqueVkImageView =              impl::OwnedHandle<VkImageView, UniqueVkDevice, VkDevice, VkImageViewCreateInfo, VK_OBJECT_TYPE_IMAGE_VIEW, &vkCreateImageView, &vkDestroyImageView>;
using UniqueVkSampler =                impl::OwnedHandle<VkSampler, UniqueVkDevice, VkDevice, VkSamplerCreateInfo, VK_OBJECT_TYPE_SAMPLER, &vkCreateSampler, &vkDestroySampler>;
using UniqueVkDescriptorPool =         impl::OwnedHandle<VkDescriptorPool, UniqueVkDevice, VkDevice, VkDescriptorPoolCreateInfo, VK_OBJECT_TYPE_DESCRIPTOR_POOL, &vkCreateDescriptorPool, &vkDestroyDescriptorPool>;
using UniqueVkDescriptorSets =         impl::DescriptorSets;
using UniqueVkDescriptorSetLayout =    impl::OwnedHandle<VkDescriptorSetLayout, UniqueVkDevice, VkDevice, VkDescriptorSetLayoutCreateInfo, VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT, &vkCreateDescriptorSetLayout, &vkDestroyDescriptorSetLayout>;
using UniqueVkPipelineLayout =         impl::OwnedHandle<VkPipelineLayout, UniqueVkDevice, VkDevice, VkPipelineLayoutCreateInfo, VK_OBJECT_TYPE_PIPELINE_LAYOUT, &vkCreatePipelineLayout, &vkDestroyPipelineLayout>;
using UniqueVkShaderModule =           impl::OwnedHandle<VkShaderModule, UniqueVkDevice, VkDevice, VkShaderModuleCreateInfo, VK_OBJECT_TYPE_SHADER_MODULE, &vkCreateShaderModule, &vkDestroyShaderModule>;

using UniqueVkDeviceMemory =           impl::OwnedHandleExternCreate<VkDeviceMemory, UniqueVkDevice, VkDevice, VK_OBJECT_TYPE_DEVICE_MEMORY, &vkFreeMemory>;
using UniqueVkCommandBuffers =         impl::OwnedHandleCommandBuffers;
using HandleVkCommandBuffer =          impl::CommandBuffer;
using UniqueVkPipeline =               impl::OwnedHandleExternCreate<VkPipeline, UniqueVkDevice, VkDevice, VK_OBJECT_TYPE_PIPELINE, &vkDestroyPipeline>;
using UniqueVkPipelineCache =          impl::OwnedHandle<VkPipelineCache, UniqueVkDevice, VkDevice, VkPipelineCacheCreateInfo, VK_OBJECT_TYPE_PIPELINE_CACHE, &vkCreatePipelineCache, &vkDestroyPipelineCache>;

using UniqueVkBuffer =                 impl::OwnedHandle<VkBuffer, UniqueVkDevice, VkDevice, VkBufferCreateInfo, VK_OBJECT_TYPE_BUFFER, &vkCreateBuffer, &vkDestroyBuffer>;
using UniqueVkCommandPool =            impl::OwnedHandle<VkCommandPool, UniqueVkDevice, VkDevice, VkCommandPoolCreateInfo, VK_OBJECT_TYPE_COMMAND_POOL, &vkCreateCommandPool,&vkDestroyCommandPool>;
using UniqueVkSemaphore =              impl::OwnedHandle<VkSemaphore, UniqueVkDevice, VkDevice, VkSemaphoreCreateInfo, VK_OBJECT_TYPE_SEMAPHORE, &vkCreateSemaphore, &vkDestroySemaphore>;
using UniqueVkFence =                  impl::OwnedHandle<VkFence, UniqueVkDevice, VkDevice, VkFenceCreateInfo, VK_OBJECT_TYPE_FENCE,  &vkCreateFence, &vkDestroyFence>;
// clang-format on

namespace impl {
struct PhyisicalDevice {

    VkPhysicalDevice physicalDevice{VK_NULL_HANDLE};

    PhyisicalDevice() {}
    PhyisicalDevice(VkPhysicalDevice physicalDevice);

    operator VkPhysicalDevice() const;

    [[nodiscard]] VkPhysicalDeviceProperties getProperties() const;
    [[nodiscard]] VkPhysicalDeviceFeatures getFeatures() const;
    [[nodiscard]] VkFormatProperties getFormatProperties(VkFormat format) const;
    [[nodiscard]] std::vector<VkQueueFamilyProperties> getQueueFamilyProperties() const;
    [[nodiscard]] std::expected<VkBool32, VkResult>
    getSurfaceSupportKHR(uint32_t queueFamilyIndex, UniqueVkSurfaceKHR &surface) const;
    [[nodiscard]] std::expected<std::vector<VkSurfaceFormatKHR>, VkResult>
    getSurfaceFormatsKHR(UniqueVkSurfaceKHR &surface) const;
    [[nodiscard]] std::expected<std::vector<VkPresentModeKHR>, VkResult>
    getSurfacePresentModesKHR(UniqueVkSurfaceKHR &surface) const;
    [[nodiscard]] std::expected<VkSurfaceCapabilitiesKHR, VkResult>
    getSurfaceCapabilitiesKHR(UniqueVkSurfaceKHR &surface) const;
    [[nodiscard]] std::expected<std::vector<VkExtensionProperties>, VkResult>
    enumerateExtensionProperties() const;
    [[nodiscard]] VkPhysicalDeviceMemoryProperties getMemoryProperties() const;
};

struct Instance : public Handle<VkInstance, VkInstanceCreateInfo, VK_OBJECT_TYPE_INSTANCE,
                                &vkCreateInstance, &vkDestroyInstance> {
    using Handle::Handle;

    [[nodiscard]] std::expected<std::vector<PhyisicalDevice>, VkResult>
    enumeratePhysicalDevices() const;
    [[nodiscard]] static std::expected<std::vector<VkLayerProperties>, VkResult>
    enumerateInstanceLayerProperties();
    [[nodiscard]] std::expected<UniqueVkDebugUtilsMessengerEXT, VkResult>
    createVkDebugUtilsMessengerEXT(const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
                                   const VkAllocationCallbacks *pAllocator = nullptr) const;
};

struct Queue : public NonOwnedHandle<VkQueue> {
    using NonOwnedHandle::NonOwnedHandle;

    [[nodiscard]] std::expected<void, VkResult> submit(VkSubmitInfo *pSubmitInfo,
                                                       VkFence fence = VK_NULL_HANDLE) const;
    [[nodiscard]] std::expected<void, VkResult>
    cleanupAquireSemaphore(UniqueVkSemaphore &semaphore) const;

    [[nodiscard]] std::expected<void, VkResult> waitIdle() const;
    [[nodiscard]] std::expected<void, VkResult>
    presentKHR(const VkPresentInfoKHR *pPresentInfo) const;
};

struct Device : public CreatorHandle<VkDevice, VkPhysicalDevice, VkDeviceCreateInfo,
                                     VK_OBJECT_TYPE_DEVICE, &vkCreateDevice, &vkDestroyDevice> {
    using CreatorHandle::CreatorHandle;

    template <typename T> void nameObject(T &t, const std::string &name);

    [[nodiscard]] HandleVkQueue getQueue(uint32_t queueFamilyIndex, uint32_t queueIndex) const;
    [[nodiscard]] std::expected<std::vector<UniqueVkImage>, VkResult>
    getSwapchainImagesKHR(UniqueVkSwapchainKHR &swapChain) const;
    [[nodiscard]] VkMemoryRequirements getImageMemoryRequirements(VkImage image) const;
    [[nodiscard]] std::expected<UniqueVkPipelineCache, VkResult>
    createPipelineCache(const VkPipelineCacheCreateInfo *pCreateInfo,
                        const VkAllocationCallbacks *pAllocator = nullptr) const;
    [[nodiscard]] std::expected<std::vector<uint8_t>, VkResult>
    getPiplineCacheData(UniqueVkPipelineCache &pipelineCache) const;
    [[nodiscard]] std::expected<UniqueVkPipeline, VkResult>
    createGraphicsPipeline(const VkGraphicsPipelineCreateInfo *pCreateInfo,
                           VkPipelineCache pipelineCache,
                           const VkAllocationCallbacks *pAllocator = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkPipeline, VkResult>
    createComputePipeline(const VkComputePipelineCreateInfo *pCreateInfo,
                          VkPipelineCache pipelineCache = VK_NULL_HANDLE,
                          const VkAllocationCallbacks *pAllocator = nullptr) const;
    [[nodiscard]] std::expected<void *, VkResult> mapMemory(VkDeviceMemory memory,
                                                            VkDeviceSize offset, VkDeviceSize size,
                                                            VkMemoryMapFlags flags = 0) const;
    void unmapMemory(VkDeviceMemory memory) const;
    [[nodiscard]] std::expected<UniqueVkDeviceMemory, VkResult>
    allocateMemory(const VkMemoryAllocateInfo *pAllocInfo,
                   const VkAllocationCallbacks *pAllocator = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkCommandBuffers, VkResult>
    allocateCommandBuffers(const VkCommandBufferAllocateInfo *pAllocateInfo) const;
    [[nodiscard]] std::expected<void, VkResult>
    bindImageMemory(VkImage image, VkDeviceMemory memory, VkDeviceSize offset) const;
    [[nodiscard]] std::expected<void, VkResult>
    bindBufferMemory(VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize offset) const;
    [[nodiscard]] std::expected<UniqueVkBuffer, VkResult>
    createBuffer(const VkBufferCreateInfo *pCreateInfo,
                 const VkAllocationCallbacks *pAllocator = nullptr) const;
    [[nodiscard]] VkMemoryRequirements getBufferMemoryRequirements(VkBuffer buffer) const;
    [[nodiscard]] std::expected<UniqueVkDescriptorPool, VkResult>
    createDescriptorPool(const VkDescriptorPoolCreateInfo *pCreateInfo) const;
    [[nodiscard]] std::expected<DescriptorSets, VkResult>
    allocateDescriptorSets(const VkDescriptorSetAllocateInfo *pAllocateInfo) const;
    void updateDescriptorSets(uint32_t descriptorWriteCount,
                              const VkWriteDescriptorSet *pDescriptorWrites,
                              uint32_t descriptorCopyCount,
                              const VkCopyDescriptorSet *pDescriptorCopies) const;
    [[nodiscard]] std::expected<UniqueVkFence, VkResult>
    createFence(const VkFenceCreateInfo *pCreateInfo,
                const VkAllocationCallbacks *pAllocator = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkSemaphore, VkResult>
    createSemaphore(const VkSemaphoreCreateInfo *pCreateInfo,
                    const VkAllocationCallbacks *pAllocator = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkShaderModule, VkResult>
    createShaderModule(const VkShaderModuleCreateInfo *createInfo,
                       const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkImageView, VkResult>
    createImageView(const VkImageViewCreateInfo *createInfo,
                    const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkImage, VkResult>
    createImage(const VkImageCreateInfo *createInfo,
                const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkDescriptorSetLayout, VkResult>
    createDescriptorSetLayout(const VkDescriptorSetLayoutCreateInfo *createInfo,
                              const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkPipelineLayout, VkResult>
    createPipelineLayout(const VkPipelineLayoutCreateInfo *createInfo,
                         const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkSwapchainKHR, VkResult>
    createSwapchainKHR(const VkSwapchainCreateInfoKHR *createInfo,
                       const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkCommandPool, VkResult>
    createCommandPool(const VkCommandPoolCreateInfo *createInfo,
                      const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<UniqueVkSampler, VkResult>
    createSampler(const VkSamplerCreateInfo *createInfo,
                  const VkAllocationCallbacks *pAlloc = nullptr) const;
    [[nodiscard]] std::expected<void, VkResult> waitIdle() const;
    [[nodiscard]] std::expected<void, VkResult> waitForFences(uint32_t fenceCount,
                                                              const VkFence *pFences,
                                                              VkBool32 waitAll,
                                                              uint64_t timeout) const;
    [[nodiscard]] std::expected<void, VkResult> waitForFence(VkFence fence, VkBool32 waitAll,
                                                             uint64_t timeout) const;
    [[nodiscard]] std::expected<void, VkResult> resetFences(uint32_t fenceCount,
                                                            const VkFence *pFences) const;
    [[nodiscard]] std::expected<void, VkResult> resetFence(VkFence fence) const;
    [[nodiscard]] std::expected<void, VkResult>
    aquireNextImageKHR(VkSwapchainKHR swapchain, uint64_t timeout, VkSemaphore semaphore,
                       VkFence fence, uint32_t *pImageIndex) const;
};

#ifndef NDEBUG
template <typename T> void Device::nameObject(T &t, const std::string &name) {
    auto nameInfo = VkBindings::Init<VkDebugUtilsObjectNameInfoEXT>();
    nameInfo.objectType = T::vk_object_type;
    nameInfo.objectHandle = (uint64_t)t.get();
    nameInfo.pObjectName = name.data();
    VkResult res = vkSetDebugUtilsObjectNameEXT(handle, &nameInfo);
    assert(res == VK_SUCCESS && "How??");
#ifdef MY_VK_IMPL_PRINT_MEM_OPS
    objectNameStorage[(uint64_t)t.get()] = name;
#endif
}
template <> inline void Device::nameObject(UniqueVkCommandBuffers &t, const std::string &name) {
    auto nameInfo = VkBindings::Init<VkDebugUtilsObjectNameInfoEXT>();
    nameInfo.objectType = UniqueVkCommandBuffers::vk_object_type;
    for (size_t i = 0; i < t.handle.size(); i++) {
        std::string s = name + "[" + std::to_string(i) + "]";
        nameInfo.pObjectName = s.data();
        nameInfo.objectHandle = (uint64_t)t.handle[i].handle;
        VkResult res = vkSetDebugUtilsObjectNameEXT(handle, &nameInfo);
        assert(res == VK_SUCCESS && "How??");
#ifdef MY_VK_IMPL_PRINT_MEM_OPS
        objectNameStorage[(uint64_t)t.handle[i].handle] = name;
#endif
    }
}
template <> inline void Device::nameObject(UniqueVkDescriptorSets &t, const std::string &name) {
    auto nameInfo = VkBindings::Init<VkDebugUtilsObjectNameInfoEXT>();
    nameInfo.objectType = UniqueVkCommandBuffers::vk_object_type;
    for (size_t i = 0; i < t.handle.size(); i++) {
        std::string s = name + "[" + std::to_string(i) + "]";
        nameInfo.pObjectName = s.data();
        nameInfo.objectHandle = (uint64_t)t.handle[i];
        VkResult res = vkSetDebugUtilsObjectNameEXT(handle, &nameInfo);
        assert(res == VK_SUCCESS && "How??");
#ifdef MY_VK_IMPL_PRINT_MEM_OPS
        objectNameStorage[(uint64_t)t.handle[i]] = name;
#endif
    }
}
#else
template <typename T> inline void Device::nameObject(T &, const std::string &) {}
#endif
} // namespace impl
} // namespace VkBindings
