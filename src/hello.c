#include "main.h"

#include "implement.h"
#include "hello.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Hello_init(Hello *this, int test, const char *hello)
{
    SUPER();

    this->test = test;
    memcpy(&this->hello, hello, 11);
}

void Hello_proc(Hello *this)
{
}

void Hello_destroy(Hello *this)
{
}

void print_hello(Hello *this)
{
    printf("%s %d\n", this->hello, this->test);
}
