#include "main.h"
#include "base.h"

int main(int argc, char const *argv[])
{
	HELLO   *h = NEW(HELLO, 69, "Barry");
	GOODBYE *g = NEW(GOODBYE, 42, "Lucas");

    MESSAGE *msg[2];
    msg[0] = h;
    msg[1] = g;

    for (int i = 0;  i < 2;  ++i)
    {
        msg[i]->PROC(msg[i]);

        msg[i]->PARENT.PROC(msg[i]);    // Keep in mind msg's type.
                                        // We're actually calling
                                        // the PARENT's PARENT here,
                                        // so BASE::PROC gets called
        msg[i]->print(msg[i]);
        puts("");
    }
    h->DESTROY(h);
    g->DESTROY(g);

	return 0;
}
