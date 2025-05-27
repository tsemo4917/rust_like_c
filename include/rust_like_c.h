#ifndef _RUST_LIKE_C_H_
#define _RUST_LIKE_C_H_
#include <inttypes.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include "result.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef __uint128_t u128;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef __int128_t i128;

typedef float f32;
typedef double f64;

typedef size_t usize;
typedef ssize_t isize;

#define let __auto_type

#define print(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define println(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define eprintln(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

#endif // _RUST_LIKE_C_H_
