#include "main.h"

int main(int argc, char const *argv[])
{
	Hello *prhello = NEW(Hello, 8, "Hello");

	prhello->print_hello(prhello);
	return 0;
}
