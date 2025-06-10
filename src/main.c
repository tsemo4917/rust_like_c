#include <stdint.h>
#include <stdio.h>
// #include <zlog.h>

#include "rust_like_c.h"

#define for_each_ptr(_iter, _ptr, _size) \
	for (typeof(&(_ptr)[0]) _iter = &(_ptr)[0], _end = &(_ptr)[_size]; _iter < _end; _iter++)

// #define for_each_array(_iter, _array) for_each_ptr(_iter, _array, ARRAY_SIZE(_array))

DEFINE_RESULT_T(int, int, RESULT_VOID_T);

static inline RESULT_T(int) mul(int a, int b)
{
	if (a < 100 && b < 100) {
		return RESULT_OK(int, a *b);
	} else {
		return RESULT_ERR(int, RESULT_VOID_NULL);
	}
}

DEFINE_RESULT_T(only_err, RESULT_VOID_T, int);

static inline RESULT_T(only_err) div(int a, int b)
{
	if (a < b) {
		return RESULT_OK(only_err, RESULT_VOID_NULL);
	} else {
		return RESULT_ERR(only_err, a / b);
	}
}

static int log_init()
{
	// int rc;
	// zlog_category_t *c;

	// rc = zlog_init("test_hello.conf");

	// if (rc) {
	// 	printf("init failed\n");
	// 	return -1;
	// }

	// c = zlog_get_category("my_cat");

	// if (!c) {
	// 	printf("get cat fail\n");

	// 	zlog_fini();
	// 	return -2;
	// }

	// zlog_info(c, "hello, zlog");

	// zlog_fini();

	return 0;
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
		println("Err when mul");
	}

	RESULT_T(only_err) err;

	err = div(100, 9);
	if (IS_ERR(&err)) {
		println("div %d", GET_ERR(&err));
	} else {
		println("Ok");
	}

	log_init();
	return 0;
}
