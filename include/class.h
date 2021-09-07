#ifndef __CLASS_H__
#define __CLASS_H__

#include <stdarg.h>

#define NULL (0)

typedef struct BASE BASE;
typedef void (*BASE_CALL)(BASE *);

#define CONSTR(name)           \
    {                          \
        NULL, NULL, NULL, NULL \
    }

#define NEW(lbl, ...)                          \
    (                                          \
        {                                      \
            lbl *new = malloc(sizeof(lbl));    \
            memcpy(new, &c##lbl, sizeof(lbl)); \
            lbl##_CONSTR(new);                 \
            lbl##_init(new, __VA_ARGS__);      \
            new;                               \
        })

#ifndef IMPLEMENT

struct BASE
{
    BASE_CALL *VTABLE;
    BASE_CALL INIT;
    BASE_CALL PROC;
    BASE_CALL DESTROY;
};

#define EXTEND(bs) \
    bs PARENT;

#define METHOD(name) \
    typeof(name) *name;

#define MEMBERS(...) \
    __VA_ARGS__
#define METHODS(...) \
    __VA_ARGS__

#define CLASS(lbl, ...)       \
    typedef struct _##lbl     \
    {                         \
        __VA_ARGS__           \
    } lbl;                    \
                              \
    static const lbl c##lbl = \
        {CONSTR(lbl), NULL};  \
    void lbl##_CONSTR(lbl *p);

#else //IMPLEMENT

#define EXTEND(bs)

#define METHOD(name) \
    p->name = &name;

#define MEMBERS(...)
#define METHODS(...)

#define CLASS(lbl, ...)       \
    void lbl##_CONSTR(lbl *p) \
    {                         \
        __VA_ARGS__           \
    }

#define SUPER()                    \
    if (this->PARENT.INIT != NULL) \
        this->PARENT.INIT(this);

#endif //IMPLEMENT

#endif //__CLASS_H__
