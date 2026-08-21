#include "VkBindings/Concepts.hpp"
#include "VkBindings/Enums.hpp"
#include "VkBindings/Objects.hpp"
#include "VkBindings/ObjectsForward.hpp"
#include "VkBindings/StackContainer.hpp"
#include "VkBindings/Structs.hpp"
#include "VkBindings/private/StructTemplatesInterface.hpp"

#include <array>
#include <concepts>
#include <utility>
#include <vector>

namespace {
// NOLINTBEGIN(clang-analyzer-deadcode.DeadStores)
void fun() {
    const VkBindings::Queue queue;
    const VkBindings::SubmitInfo info;

    std::ignore = queue.submit({info});

    static_assert(VkBindings::Concepts::ABIIsHandle<VkBindings::DescriptorSetLayout>);

    VkBindings::PipelineLayoutCreateInfo pipelineLayoutInfo;
    const VkBindings::DescriptorSetLayout desc;
    pipelineLayoutInfo.setLayouts() = desc;
    std::vector<VkBindings::DescriptorSetLayout> Vdesc;
    pipelineLayoutInfo.setLayouts() = Vdesc;

    VkBindings::GraphicsPipelineCreateInfo pipelineInfo;
    const VkBindings::PipelineLayout playout;
    pipelineInfo.layout = playout;
    const VkBindings::UniquePipelineLayout uplayout;
    pipelineInfo.layout = uplayout;

    const VkBindings::CommandBuffer commandBuffer;
    const VkBindings::Buffer buffer;
    commandBuffer.bindVertexBuffers(0, buffer, {0});

    auto stack = VkBindings::stackContainer(VkBindings::ImageAspectBits::Color,
                                            VkBindings::ImageAspectBits::Depth);
    static_assert(std::same_as<decltype(stack), std::array<VkBindings::ImageAspectFlags, 2>>);
    auto ist = VkBindings::stackContainer(VkBindings::Image{}, VkBindings::Image{});
    static_assert(
        std::same_as<decltype(ist),
                     std::array<VkBindings::impl_Struct::AssignableHandle<VkBindings::Image>, 2>>);
    auto uist = VkBindings::stackContainer(VkBindings::UniqueImage{}, VkBindings::UniqueImage{});
    static_assert(
        std::same_as<decltype(uist),
                     std::array<VkBindings::impl_Struct::AssignableHandle<VkBindings::Image>, 2>>);

    const VkBindings::UniqueSemaphore us1;
    const VkBindings::UniqueSemaphore us2;
    auto waitSem = VkBindings::stackContainer(us1, us2);
    VkBindings::SubmitInfo sinfo;
    sinfo.waitSemaphores() = waitSem;
}
// NOLINTEND(clang-analyzer-deadcode.DeadStores)

} // namespace
auto main() -> int { fun(); }
