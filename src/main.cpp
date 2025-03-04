#include <common/error.hpp>
#include <common/main.hpp>
#include <common/types.hpp>
#include <print>

auto hk::main(arguements /* args */) -> result<i32> {
  std::println("Hello, world!");

  return 0;
}
