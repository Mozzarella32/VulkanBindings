#pragma once

namespace VkBindings::impl_Struct {

struct LayoutChecker {
    LayoutChecker() = delete;

  private:
    static void checkStructsCorrectAsserts();
};

}; // namespace VkBindings::impl_Struct
