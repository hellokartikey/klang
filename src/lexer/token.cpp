#include "token.hpp"

namespace klang {
Token::Token(Type type, std::string text)
    : m_type(type),
      m_text(std::move(text)) {}

auto Token::type() const -> Type { return m_type; }

auto Token::text() const -> const std::string& { return m_text; }

auto Token::operator==(Type other) const -> bool { return type() == other; }
}  // namespace klang
