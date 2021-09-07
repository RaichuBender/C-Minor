// #include "message.h"
#include "class.h"

typedef struct _GOODBYE GOODBYE;

void GOODBYE_INIT(GOODBYE *this, int test, const char *name);
void GOODBYE_PROC(GOODBYE *this);
void GOODBYE_DESTROY(GOODBYE *this);

void print_gb(GOODBYE *this);

CLASS
(   GOODBYE,

	EXTEND(MESSAGE)

	OVERRIDE(print, print_gb)
	OVERRIDE(PROC, GOODBYE_PROC)
    OVERRIDE(DESTROY, GOODBYE_DESTROY)

    MEMBERS
    (
        int test;
        const char name[11];
    )
)
