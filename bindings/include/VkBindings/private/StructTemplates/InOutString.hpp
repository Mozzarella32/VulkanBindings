#pragma once

#include <string>
#include <string_view>

namespace VkBindings::impl_Struct {

struct LayoutChecker;

struct InOutString {
  private:
    const char *pStr = nullptr;

    friend LayoutChecker;

  public:
    InOutString() = default;
    InOutString(const std::string &str);
    InOutString(const char *cStr);

    auto operator=(const std::string &str) -> InOutString &;
    auto operator=(const char *cStr) -> InOutString &;

    operator std::string() const;
    operator std::string_view() const;
    operator const char *() const;

    [[nodiscard]] auto to_string() const -> std::string;
    [[nodiscard]] auto to_string_view() const -> std::string_view;
    [[nodiscard]] auto to_c_str() const -> const char *;
};

} // namespace VkBindings::impl_Struct
