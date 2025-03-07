#include <string>

#include <fmt/base.h>
#include <fmt/ranges.h>

#include <common/error.hpp>
#include <common/main.hpp>
#include <common/types.hpp>
#include <lexer/token.hpp>
#include "lexer/lexer.hpp"

auto hk::main(arguements /* args */) -> result<i32> {
  fmt::println("Hello, world!");

  auto lex = klang::lexer::Lexer();

  auto tokens = TRY(lex.parse());
  fmt::println("{}", tokens);

  return 0;
}
