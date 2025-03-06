#ifndef HK_KLANG_LEXER_TOKEN_HPP
#define HK_KLANG_LEXER_TOKEN_HPP

#include <format>

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
struct std::formatter<klang::lexer::Token> : std::formatter<std::string> {
  auto format(const klang::lexer::Token& token,
              std::format_context& ctx) const {
    using magic_enum::enum_name;
    auto output = std::format("{}({})", enum_name(token.type()), token.text());
    return std::formatter<std::string>::format(output, ctx);
  }
};

#endif
