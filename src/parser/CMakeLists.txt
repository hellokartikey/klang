add_library(parser)

target_sources(parser
PUBLIC
  parser.hpp
)

target_link_libraries(parser
  common
  lexer
  fmt::fmt
  foonathan::lexy
)
