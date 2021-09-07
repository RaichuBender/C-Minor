// #ifndef __HELLO_H__
// #define __HELLO_H__

// #include "message.h"
#include "class.h"

typedef struct _Hello Hello;


void Hello_init(Hello *this, int test, const char *name);
void Hello_proc(Hello *this);
void Hello_destroy(Hello *this);

void print_hl(Hello *this);

CLASS
(   Hello,

	OVERLOAD(Message)

	METHOD(print_hl)
	METHOD(Hello_proc)

    MEMBERS
    (
        int test;
        const char name[11];
    )
)

// #endif //__HELLO_H__
