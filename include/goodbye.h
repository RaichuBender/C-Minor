// #include "message.h"
#include "class.h"

typedef struct _Goodbye Goodbye;

void Goodbye_init(Goodbye *this, int test, const char *name);
void Goodbye_proc(Goodbye *this);
void Goodbye_destroy(Goodbye *this);

void print_gb(Goodbye *this);

CLASS
(   Goodbye,

	OVERLOAD(Message)

	METHOD(print_gb)
	METHOD(Goodbye_proc)

    MEMBERS
    (
        int test;
        const char name[11];
    )
)
