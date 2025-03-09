#ifndef HK_KLANG_LEXER_REGEX_HPP
#define HK_KLANG_LEXER_REGEX_HPP

#include <ctre.hpp>

namespace klang::regex {
template <ctll::fixed_string Regex>
constexpr auto regex = ctre::starts_with<Regex>;

constexpr auto whitespace = regex<R"([ \t\n]+)">;

constexpr auto identifier = regex<R"([_a-zA-Z][_a-zA-Z0-9]*)">;

constexpr auto builtin_type = regex<"(char)|"
                                    "(i8)|(i16)|(i32)|(i64)|"
                                    "(u8)|(u16)|(u32)|(u64)">;

constexpr auto integer = regex<R"([0-9]+)">;
constexpr auto floating_point = regex<R"(([0-9]+\.[0-9]*)|([0-9]*\.[0-9]+))">;

constexpr auto binary_math_op = regex<R"((<<)|(>>)|(&&)|(\|\|)|[*/%&|^])">;
constexpr auto context_math_op = regex<R"([+\-])">;
constexpr auto unary_math_op = regex<R"([~!])">;

constexpr auto pre_post_op = regex<R"((\+\+)|(--))">;

constexpr auto compare_op = regex<R"((==)|(!=)|(<=)|(>=)|(<=>)|[<>])">;

constexpr auto assign_op =
    regex<R"((\+=)|(-=)|(\*=)|(/=)|(%=)|(&=)|(\|=)|(^=)|(<<=)|(>>=)|(=))">;

constexpr auto punctuation = regex<R"(;)">;
}  // namespace klang::regex

#endif
