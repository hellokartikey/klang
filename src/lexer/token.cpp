#include "token.hpp"

#include <magic_enum/magic_enum.hpp>

namespace klang::lexer {
Token::Token(Type type, std::string text)
    : m_type(type),
      m_text(std::move(text)) {}

auto Token::type() const -> Type { return m_type; }

auto Token::text() const -> const std::string& { return m_text; }
}  // namespace klang::lexer
