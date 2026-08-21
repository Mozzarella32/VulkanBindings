#include "VkBindings/private/StructTemplatesInterface.hpp"

// NOLINTBEGIN(misc-include-cleaner)
// Needed for getting implmenetations
#include "VkBindings/private/StructTemplates.hpp"

// NOLINTEND(misc-include-cleaner)
namespace VkBindings {
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
template struct impl_Struct::FixedString<128>;
template struct impl_Struct::FixedString<256>;
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
} // namespace VkBindings
