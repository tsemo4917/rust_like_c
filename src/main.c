#include <stdint.h>
#include <stdio.h>

#include "rust_like_c.h"

#define for_each_ptr(_iter, _ptr, _size) \
	for (typeof(&(_ptr)[0]) _iter = &(_ptr)[0], _end = &(_ptr)[_size]; _iter < _end; _iter++)

// #define for_each_array(_iter, _array) for_each_ptr(_iter, _array, ARRAY_SIZE(_array))

DEFINE_RESULT_T(int, int, void *);

static inline RESULT_T(int) mul(int a, int b)
{
	if (a < 100 && b < 100) {
		return RESULT_OK(int, a *b);
	} else {
		return RESULT_ERR(int, NULL);
	}
}

int main()
{
	let val_auto = 10ull;
	u32 val_u64 = 0x89;
	usize val_usize = 0xdeadbeef;
	println("%llu, %x", val_auto, val_u64);
	println("%zu", val_usize);
	eprintln("hello");

	RESULT_T(int) res;

	res = mul(10, 10);
	if (IS_OK(&res)) {
		println("OK: %d", GET_OK(&res));
	} else {
		println("Err: %p", GET_ERR(&res));
	}

	res = mul(100, 1);
	if (IS_ERR(&res)) {
		println("Err: %p", GET_ERR(&res));
	} else {
		println("Ok: %d", GET_OK(&res));
	}
	return 0;
}
