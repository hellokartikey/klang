#ifndef HK_KLANG_COMMON_MAIN_HPP
#define HK_KLANG_COMMON_MAIN_HPP

#include <span>
#include <string_view>

#include <common/error.hpp>
#include <common/types.hpp>

class arguements {
 public:
  using span_view = std::span<std::string_view>;

  arguements(i32 argc, char **argv, span_view span)
      : m_argc(argc),
        m_argv(argv),
        m_span(span) {}

  [[nodiscard]] auto argc() const -> i32 { return m_argc; }
  auto argv() -> char ** { return m_argv; };
  auto span() -> span_view { return m_span; }

 private:
  i32 m_argc;
  char **m_argv;
  span_view m_span;
};

namespace hk {
auto main(arguements args) -> result<i32>;
}

#endif
