add_library(lexer)

target_sources(lexer
PUBLIC
  lexer.hpp
  token.hpp
PRIVATE
  lexer.cpp
  token.cpp
)

target_link_libraries(lexer
  common
  ctre::ctre
  magic_enum::magic_enum
)
