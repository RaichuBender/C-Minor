#ifndef __CLASS_H__
#define __CLASS_H__

#include <stdarg.h>

#define NULL (0)

typedef struct BASE BASE;
typedef void (*BASE_CALL)(BASE *);
typedef void BASE_PARENT;

#define CONSTR(name)                     \
    {                                    \
        NULL,                            \
            (BASE_CALL)(&name##_INIT),   \
            (BASE_CALL)(&name##_PROC),   \
            (BASE_CALL)(&name##_DESTROY) \
    }

#define NEW(lbl, ...)                                                 \
    (                                                                 \
        {                                                             \
            lbl *new = malloc(sizeof(lbl));                           \
            memcpy(new, &lbl##_PROTO, sizeof(lbl)); \
            lbl##_CONSTR(new);                                        \
            lbl##_INIT(new, __VA_ARGS__);                             \
            new;                                                      \
        })

void ABSTRACT(void *);

#ifndef IMPLEMENT

struct BASE
{
    BASE_CALL *VTABLE;
    BASE_CALL INIT;
    BASE_CALL PROC;
    BASE_CALL DESTROY;
};

extern BASE BASE_PROTO;

#define EXTEND(bs) \
    bs PARENT;

#define METHOD(name, src) \
    typeof(src) *name;
#define OVERRIDE(name, src) \
    typeof(src) *name;
#define USE(name)   \
    typeof(name) *name;

#define MEMBERS(...) \
    __VA_ARGS__
#define METHODS(...) \
    __VA_ARGS__

#define CLASS(lbl, ...)                     \
    typedef struct _##lbl                   \
    {                                       \
        __VA_ARGS__                         \
    } lbl;                                  \
                                            \
    static const lbl lbl##_PROTO = \
        {CONSTR(lbl), NULL};                \
    void lbl##_CONSTR(lbl *p);

#else //IMPLEMENT

#define EXTEND(bs)                             \
    if (((BASE *)(&bs##_PROTO))->INIT != NULL) \
        memcpy(&p->PARENT, &bs##_PROTO, sizeof(bs));

#define METHOD(name, src) \
    p->name = &src;
#define OVERRIDE(name, src) \
    p->PARENT.name = &src;  \
    p->name = &src;
#define USE(name)   \
    p->name = p->PARENT.name;

#define MEMBERS(...)
#define METHODS(...)

#define CLASS(lbl, ...)       \
    void lbl##_CONSTR(lbl *p) \
    {                         \
        __VA_ARGS__           \
    }

#define SUPER(lbl,this)              \
    if (((BASE *)this)->lbl != NULL) \
        ((BASE *)this)->lbl(this);

#endif //IMPLEMENT

#endif //__CLASS_H__
