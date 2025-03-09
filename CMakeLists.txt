cmake_minimum_required(VERSION 3.30)

project(klang
  VERSION 0.1.0
  DESCRIPTION "A C++ like embedded language"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(ctre REQUIRED)
find_package(lexy REQUIRED)
find_package(fmt REQUIRED)
find_package(magic_enum REQUIRED)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

  include(clang_format)
endif()

add_subdirectory(src)
