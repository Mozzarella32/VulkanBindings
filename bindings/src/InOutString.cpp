#include "VkBindings/private/StructTemplates/InOutString.hpp"

#include <string>
#include <string_view>

namespace VkBindings::impl_Struct {
InOutString::InOutString(const std::string &str) : pStr(str.data()) {}
InOutString::InOutString(const char *cStr) : pStr(cStr) {}

auto InOutString::operator=(const std::string &str) -> InOutString & {
    pStr = str.data();
    return *this;
}
auto InOutString::operator=(const char *cStr) -> InOutString & {
    pStr = cStr;
    return *this;
}

InOutString::operator std::string() const { return {pStr}; }
InOutString::operator std::string_view() const { return {pStr}; }
InOutString::operator const char *() const { return pStr; }

[[nodiscard]] auto InOutString::to_string() const -> std::string { return *this; }
[[nodiscard]] auto InOutString::to_string_view() const -> std::string_view { return *this; }
[[nodiscard]] auto InOutString::to_c_str() const -> const char * { return *this; }

} // namespace VkBindings::impl_Struct
