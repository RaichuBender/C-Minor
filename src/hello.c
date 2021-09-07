#include "main.h"

#include "implement.h"
#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HELLO_INIT(HELLO *this, int test, const char *name)
{
    SUPER(INIT,this);

    this->test = test;
    memcpy(&this->name, name, 11);
}

void HELLO_PROC(HELLO *this)
{
    puts("HELLO_PROC invoked!");

    SUPER(PROC,this)
}

void HELLO_DESTROY(HELLO *this)
{
    puts("HELLO_DESTROY invoked!");
    free(this);
}

void print_hl(HELLO *this)
{
    printf("Hello, %s! Your ticked ID is: %d!\n", this->name, this->test);
}
