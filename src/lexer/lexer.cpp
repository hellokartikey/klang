#include "lexer.hpp"

#include <expected>
#include <utility>

#include <fmt/base.h>

#include <lexer/regex.hpp>

namespace klang {
Lexer::Lexer(std::string text)
    : m_text(std::move(text)),
      m_current(m_text.begin()),
      m_end(m_text.end()) {}

auto Lexer::parse() -> result<TokenStream> {
  auto tokens = TokenStream{};

  while (auto token = parse_one()) {
    tokens.push_back(*token);
  }

  if (tokens.empty()) {
    return error("No tokens could be parsed");
  }

  return tokens;
}

auto Lexer::parse_one() -> result<Token> {
  if (is_eof()) {
    return error("EOF reached");
  }

  // Move past any whitespace characters
  std::ignore = check(regex::whitespace);

  using enum Token::Type;

  if (auto match = check(regex::floating_point); match) {
    return Token(FLOAT, *match);
  }

  if (auto match = check(regex::integer); match) {
    return Token(INTEGER, *match);
  }

  if (auto match = check(regex::identifier); match) {
    return Token(IDENTIFIER, *match);
  }

  return error("Unable to parse the string");
}

auto Lexer::is_eof() const -> bool { return m_current == m_end; }
}  // namespace klang
