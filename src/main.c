#include "main.h"
#include "base.h"

int main(int argc, const char *argv[])
{
	HELLO   *h = NEW(HELLO,   69, "Barry");
	GOODBYE *g = NEW(GOODBYE, 42, "Lucas");

	// Even though both classes extend MESSAGE,
	// different struct types are handled separately.
	MESSAGE *msg[2];
	msg[0] = h;
	msg[1] = g;

	// Polymorphism demonstration
	for (int i = 0;  i < 2;  ++i)
	{
		msg[i]->PROC(msg[i]);
		msg[i]->PARENT.PROC(msg[i]);	// Keep in mind msg's type.
										// We're actually calling
										// the PARENT's PARENT here,
										// so BASE::PROC gets called (which contain the init, proc and destroy of the base class)
		msg[i]->print(msg[i]);
		puts("");
	}

	h->DESTROY(h);
	g->DESTROY(g);

	return 0;
}
