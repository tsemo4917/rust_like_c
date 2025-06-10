#ifndef _RESULT_H_
#define _RESULT_H_

#include <stdbool.h>

typedef struct _result_void {
	int _[0];
} _result_void_t;

#define RESULT_VOID_T _result_void_t
#define RESULT_VOID_NULL {}

#define RESULT_T(name) result_##name##_t

#define DEFINE_RESULT_T(name, T, E) \
	typedef struct _result_##name { \
		bool succ;                  \
		union {                     \
			T ok;                   \
			E err;                  \
		};                          \
	} RESULT_T(name)

#define RESULT_OK(name, value)     \
	(RESULT_T(name))               \
	{                              \
		.succ = true, .ok = value, \
	}

#define RESULT_ERR(name, error)      \
	(RESULT_T(name))                 \
	{                                \
		.succ = false, .err = error, \
	}

#define IS_OK(res) ((res)->succ)
#define IS_ERR(res) (!IS_OK(res))

#define GET_OK(res) ((res)->ok)
#define GET_ERR(res) ((res)->err)

#endif // _RESULT_H_
