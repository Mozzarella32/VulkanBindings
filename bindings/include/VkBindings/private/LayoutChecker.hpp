#pragma once

#include "VkBindings/private/StructTemplatesInterface.hpp"

namespace VkBindings::impl_Struct {

struct LayoutChecker {
    LayoutChecker() = delete;

  private:
    void checkStructsCorrectAsserts();
};

}; // namespace VkBindings::impl_Struct
