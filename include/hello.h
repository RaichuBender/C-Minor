// #ifndef __HELLO_H__
// #define __HELLO_H__

// #include "message.h"
#include "class.h"

typedef struct _HELLO HELLO;


void HELLO_INIT(HELLO *this, int test, const char *name);
void HELLO_PROC(HELLO *this);
void HELLO_DESTROY(HELLO *this);

void print_hl(HELLO *this);

CLASS
(   HELLO,

	EXTEND(MESSAGE)

	OVERRIDE(print, print_hl)
	OVERRIDE(PROC, HELLO_PROC)
    OVERRIDE(DESTROY, HELLO_DESTROY)

    MEMBERS
    (
        int test;
        const char name[11];
    )
)

// #endif //__HELLO_H__
