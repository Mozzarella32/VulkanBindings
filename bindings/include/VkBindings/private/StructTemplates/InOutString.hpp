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
    explicit InOutString(const std::string &str);
    explicit InOutString(const char *cStr);

    auto operator=(const std::string &str) -> InOutString &;
    auto operator=(const char *cStr) -> InOutString &;

    explicit operator std::string() const;
    explicit operator std::string_view() const;
    explicit operator const char *() const;

    [[nodiscard]] auto to_string() const -> std::string;
    [[nodiscard]] auto to_string_view() const -> std::string_view;
    [[nodiscard]] auto to_c_str() const -> const char *;
};

} // namespace VkBindings::impl_Struct
