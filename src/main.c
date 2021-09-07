#include "main.h"

#ifndef __BASE__
#define __BASE__

BASE cBASE = {NULL,NULL,NULL,NULL};

#endif //__BASE__

int main(int argc, char const *argv[])
{
    Message *msg[2];
	msg[0] = NEW(Hello, 69, "Barry");
	msg[1] = NEW(Goodbye, 42, "Lucas");

    for (int i = 0;  i < 2;  ++i)
        msg[i]->print(msg[i]);

	return 0;
}
