// #ifndef __HELLO_H__
// #define __HELLO_H__

#include "class.h"

typedef struct _Hello Hello;
void print_hello(Hello *this);

CLASS
(   Hello,

	EXTEND(BASE)

	METHOD(print_hello)

    MEMBERS
    (
        int test;
        const char hello[11];
    )
)

METHODS
(
    void Hello_init(Hello *this, int test, const char *hello);
    void Hello_proc(Hello *this);
    void Hello_destroy(Hello *this);
)

extern Hello *current_Hello;

// #endif //__HELLO_H__
