#ifndef HK_KLANG_COMMON_ERROR_HPP
#define HK_KLANG_COMMON_ERROR_HPP

#include <expected>
#include <system_error>

#include <common/types.hpp>

// TODO: Use a my own error type
template <typename T>
using result = std::expected<T, std::error_code>;

#endif
