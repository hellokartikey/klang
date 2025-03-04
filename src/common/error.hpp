#ifndef HK_KLANG_COMMON_ERROR_HPP
#define HK_KLANG_COMMON_ERROR_HPP

#include <common/types.hpp>
#include <expected>
#include <string_view>
#include <system_error>

// TODO: Use a my own error type
template <typename T>
using result = std::expected<T, std::error_code>;

#endif
