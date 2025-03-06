#include <common/error.hpp>
#include <common/main.hpp>
#include <common/types.hpp>
#include <lexer/token.hpp>
#include <print>
#include <string>

auto hk::main(arguements /* args */) -> result<i32> {
  std::println("Hello, world!");

  using namespace std::literals;
  using enum klang::lexer::Token::Type;

  auto token = klang::lexer::Token{IDENTIFIER, "variable"s};
  std::println("{}", token);

  return 0;
}
