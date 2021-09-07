#include "main.h"

#include "implement.h"
#include "goodbye.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Goodbye_init(Goodbye *this, int test, const char *name)
{
    this->test = test;
    memcpy(&this->name, name, 11);
}

void Goodbye_proc(Goodbye *this)
{
}

void Goodbye_destroy(Goodbye *this)
{
}

void print_gb(Goodbye *this)
{
    printf("Goodbye, %s! %d\n", this->name, this->test);
}
