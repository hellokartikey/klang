#include "main.hpp"

#include <common/types.hpp>
#include <print>
#include <span>
#include <string_view>
#include <vector>

auto main(i32 argc, char **argv) -> i32 {
  auto args = std::vector<std::string_view>(argc);

  for (auto *arg : std::span(argv, argc)) {
    args.emplace_back(arg);
  }

  auto result = hk::main(arguements(argc, argv, args));

  if (not result) {
    // FIXME: Print proper error message
    std::println(stderr, "Runtime error occured...");
    return 1;
  }

  return *result;
}
