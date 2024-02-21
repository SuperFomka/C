#ifndef STACK_H_
#define STACK_H_

struct Stack {
    char c;
    struct Stack *Next;
};

struct Stack *InString(struct Stack *, char);
struct Stack *OutString(struct Stack *, char *);

#endif