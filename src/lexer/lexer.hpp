#ifndef HK_KLANG_LEXER_LEXER_HPP
#define HK_KLANG_LEXER_LEXER_HPP

#include <common/error.hpp>
#include <lexer/token.hpp>

namespace klang {
class Lexer {
 public:
  Lexer(std::string text);

  auto parse() -> result<TokenStream>;

  auto emit_warning(std::string_view message) const -> void;

 private:
  [[nodiscard]]
  auto is_eof() const -> bool;

  // Skips whitespace characters
  auto has_tokens() -> bool;

  auto parse_one() -> result<Token>;

  template <typename Regex>
  auto check(Regex regex) -> result<std::string> {
    if (auto result = regex(m_current, m_end); result) {
      std::advance(m_current, result.size());
      return result.to_string();
    }

    return error("Not a match");
  }

  std::string m_text;
  std::string::const_iterator m_current;
  std::string::const_iterator m_end;
};
}  // namespace klang

#endif
