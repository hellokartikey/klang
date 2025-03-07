#include "lexer.hpp"

#include <expected>
#include <utility>

#include <fmt/base.h>

#include <lexer/regex.hpp>
#include "lexer/token.hpp"

#define MATCH_TOKEN(regex, token_type)    \
  if (auto match = check(regex); match) { \
    return Token(token_type, *match);     \
  }

namespace klang {
Lexer::Lexer(std::string text)
    : m_text(std::move(text)),
      m_current(m_text.begin()),
      m_end(m_text.end()) {}

auto Lexer::parse() -> result<TokenStream> {
  auto tokens = TokenStream{};

  while (has_tokens()) {
    tokens.push_back(TRY(parse_one()));
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

  using enum Token::Type;

  MATCH_TOKEN(regex::binary_op, BINARY_OP);

  MATCH_TOKEN(regex::floating_point, FLOAT);
  MATCH_TOKEN(regex::integer, INTEGER);

  MATCH_TOKEN(regex::identifier, IDENTIFIER);

  return error("Unable to parse the string");
}

auto Lexer::is_eof() const -> bool { return m_current == m_end; }

auto Lexer::has_tokens() -> bool {
  std::ignore = check(regex::whitespace);
  return not is_eof();
}
}  // namespace klang
