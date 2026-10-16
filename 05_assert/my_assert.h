#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#ifndef NDEBUG

#include <stdio.h>
#include <stdlib.h>

static inline void my_assert_fail(
    const char *expr,
    const char *file,
    int line,
    const char *func)
{
    fprintf(stderr,
        "%s:%d: %s: Assertion `%s' failed.\n",
        file, line, func, expr);

    abort();
}

#define my_assert(expr) \
    ((expr) ? (void)0 : \
    my_assert_fail(#expr, __FILE__, __LINE__, __func__))

#else

#define my_assert(expr) ((void)0)

#endif

#endif
