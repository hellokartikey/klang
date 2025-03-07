#ifndef HK_KLANG_LEXER_TOKEN_HPP
#define HK_KLANG_LEXER_TOKEN_HPP

#include <vector>

#include <fmt/format.h>
#include <magic_enum/magic_enum.hpp>

#include <common/types.hpp>

namespace klang::lexer {
class Token {
 public:
  enum class Type : i8 { IDENTIFIER };

  Token(Type type, std::string text);

  [[nodiscard]] auto type() const -> Type;

  [[nodiscard]] auto text() const -> const std::string&;

 private:
  Type m_type;
  std::string m_text;
};

using TokenStream = std::vector<Token>;
}  // namespace klang::lexer

template <>
struct fmt::formatter<klang::lexer::Token> : fmt::formatter<std::string> {
  auto format(const klang::lexer::Token& token,
              fmt::format_context& ctx) const {
    using magic_enum::enum_name;
    auto output = fmt::format("{}({})", enum_name(token.type()), token.text());
    return fmt::formatter<std::string>::format(output, ctx);
  }
};

#endif
