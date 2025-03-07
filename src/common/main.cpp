#include "main.hpp"

#include <span>
#include <string_view>
#include <vector>

#include <common/types.hpp>

auto main(i32 argc, char **argv) -> i32 {
  auto args = std::vector<std::string_view>(argc);

  for (auto *arg : std::span(argv, argc)) {
    args.emplace_back(arg);
  }

  auto result = hk::main(arguements(argc, argv, args));

  if (not result) {
    fmt::println(stderr, "Runtime error: {}", result.error().message());
    return 1;
  }

  return *result;
}
