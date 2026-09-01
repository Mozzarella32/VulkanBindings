#pragma once

#include <cassert>
#include <memory>
#include <type_traits>

namespace VkBindings::impl_Struct {

struct LayoutChecker;

template <typename Size_T> struct POD {
    using size_type = Size_T;

  private:
    size_type _size;
    const void *_data;

  public:
    template <typename T>
        requires std::is_standard_layout_v<T>
    POD(const T &obj) : _size(sizeof(T)), _data(std::addressof(obj)) {}

    [[nodiscard]] auto data() const -> const void * { return _data; }
    [[nodiscard]] auto size() const -> size_type { return _size; }
};

} // namespace VkBindings::impl_Struct
