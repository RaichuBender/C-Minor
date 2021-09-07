#include "main.h"

#include "implement.h"
#include "goodbye.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GOODBYE_INIT(GOODBYE *this, int test, const char *name)
{
    SUPER(INIT,this);

    this->test = test;
    memcpy(&this->name, name, 11);
}

void GOODBYE_PROC(GOODBYE *this)
{
    puts("GOODBYE_PROC invoked!");
}

void GOODBYE_DESTROY(GOODBYE *this)
{
    puts("GOODBYE_DESTROY invoked!");
    free(this);
}

void print_gb(GOODBYE *this)
{
    printf("Goodbye, %s! Your ticked ID is: %d!\n", this->name, this->test);
}
