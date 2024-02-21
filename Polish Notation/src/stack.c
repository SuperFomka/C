#include "stack.h"

#include <stdlib.h>

struct Stack *InString(struct Stack *t, char s) {
    struct Stack *t1 = (struct Stack *)malloc(sizeof(struct Stack));
    t1->c = s;
    t1->Next = t;
    return t1;
}
struct Stack *OutString(struct Stack *t, char *s) {
    if (t) {
        struct Stack *t1 = t;
        *s = t->c;
        t = t->Next;
        free(t1);
    }
    return t;
}
