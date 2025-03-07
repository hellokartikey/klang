#ifndef HK_KLANG_LEXER_REGEX_HPP
#define HK_KLANG_LEXER_REGEX_HPP

#include <ctre.hpp>

namespace klang::lexer::regex {
constexpr auto match_whitespace = ctre::starts_with<"[ \t\n]+">;
constexpr auto match_identifier = ctre::starts_with<"[a-zA-Z][a-zA-Z0-9]*">;
}  // namespace klang::lexer::regex

#endif
