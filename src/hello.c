#include "main.h"

#include "implement.h"
#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Hello_init(Hello *this, int test, const char *name)
{
    this->test = test;
    memcpy(&this->name, name, 11);
}

void Hello_proc(Hello *this)
{
}

void Hello_destroy(Hello *this)
{
}

void print_hl(Hello *this)
{
    printf("Hello, %s! %d\n", this->name, this->test);
}
