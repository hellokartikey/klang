#ifndef HK_KLANG_COMMON_ERROR_HPP
#define HK_KLANG_COMMON_ERROR_HPP

#include <concepts>
#include <expected>
#include <string_view>

#include <fmt/format.h>

#include <common/types.hpp>

#define TRY(expr)                                                       \
  ({                                                                    \
    auto result = (expr);                                               \
    static_assert(is_result<decltype(result)>,                          \
                  "expression: " #expr " does not return result type"); \
    if (not result) {                                                   \
      return result.error();                                            \
    }                                                                   \
    *result;                                                            \
  })

class error {
 public:
  template <typename T>
  using result = std::expected<T, error>;

  error(std::string_view message)
      : m_message(message) {}

  [[nodiscard]]
  auto message() const -> std::string_view {
    return m_message;
  }

  template <typename T>
  operator result<T>() const {
    return std::unexpected{*this};
  }

 private:
  std::string_view m_message;
};

template <>
struct fmt::formatter<error> : fmt::formatter<std::string> {
  auto format(const error& value, fmt::format_context& ctx) const {
    auto output = fmt::format("error({})", value.message());
    return fmt::formatter<std::string>::format(output, ctx);
  }
};

template <typename T>
using result = error::result<T>;

template <typename T>
concept is_result = requires(T item) {
  { static_cast<bool>(item) };
  { *item };
};

#endif
