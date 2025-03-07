#ifndef HK_KLANG_LEXER_REGEX_HPP
#define HK_KLANG_LEXER_REGEX_HPP

#include <ctre.hpp>

namespace klang::regex {
constexpr auto whitespace = ctre::starts_with<R"([ \t\n]+)">;

constexpr auto identifier = ctre::starts_with<R"([_a-zA-Z][_a-zA-Z0-9]*)">;

constexpr auto integer = ctre::starts_with<R"([0-9]+)">;
constexpr auto floating_point =
    ctre::starts_with<R"(([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+))">;

constexpr auto binary_op =
    ctre::starts_with<R"((<<)|(>>)|(<=>)|(==)|(!=)|(&&)|(\|\|)|[*/%&^|?:])">;
}  // namespace klang::regex

#endif
