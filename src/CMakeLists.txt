include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(common)
add_subdirectory(lexer)
add_subdirectory(parser)

add_executable(klang main.cpp)

target_link_libraries(klang
  common
  lexer
  parser
  fmt::fmt
)
