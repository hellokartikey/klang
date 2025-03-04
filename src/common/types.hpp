#ifndef HK_KLANG_COMMON_TYPES_HPP
#define HK_KLANG_COMMON_TYPES_HPP

#include <cstdint>
#include <stdfloat>

using u8 = std::uint8_t;
static_assert(sizeof(u8) == 1);

using u16 = std::uint16_t;
static_assert(sizeof(u16) == 2);

using u32 = std::uint32_t;
static_assert(sizeof(u32) == 4);

using u64 = std::uint64_t;
static_assert(sizeof(u64) == 8);

using i8 = std::int8_t;
static_assert(sizeof(i8) == 1);

using i16 = std::int16_t;
static_assert(sizeof(i16) == 2);

using i32 = std::int32_t;
static_assert(sizeof(i32) == 4);

using i64 = std::int64_t;
static_assert(sizeof(i64) == 8);

#endif
