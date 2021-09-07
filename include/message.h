#include "class.h"

typedef struct _MESSAGE MESSAGE;

// These are mandatory, even if not used
void MESSAGE_INIT(MESSAGE *);
void MESSAGE_PROC(MESSAGE *);
void MESSAGE_DESTROY(MESSAGE *);
	// Don't forget to define,
	// else the linker will complain

// Classes are defined using this syntax:
CLASS
(	MESSAGE,		// Object type name
	EXTEND(BASE)	// Parent class (or BASE if N/A)
						// This means it's the a base/root class.
						// Also applicable to abstract classes and/or interfaces

				//	ABSTRACT function: will be overriden by child class(es)
	METHOD(print,   ABSTRACT)
	METHOD(PROC,    ABSTRACT)
	METHOD(DESTROY, ABSTRACT)
)
