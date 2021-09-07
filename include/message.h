#include "class.h"

typedef struct _Message Message;

void Message_init(Message *);
void Message_proc(Message *);
void Message_destroy(Message *);

void print(Message *this);

CLASS
(   Message,
	EXTEND(BASE)

	METHOD(print)
	METHOD(Message_proc)
)
