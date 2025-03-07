add_library(common)

target_sources(
  common
PUBLIC
  error.hpp
  types.hpp
  main.hpp
PRIVATE
  main.cpp
)

target_link_libraries(common fmt::fmt)
