//
// Created by JunhaoWang on 7/16/16.
//

#include "Structure.h"

#define STACK_INIT_SIZE 100

void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base)
        exit(0);
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}

#define STACKINCREMENT 10

void Push(sqStack *s, ElemType e)
{
    if (s->top - s->base >= s->stackSize) {

        s->base = (ElemType *) realloc(s->base, (s->stackSize * STACKINCREMENT) * sizeof(ElemType));
        if (!s->base)
            exit(0);

        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize + STACKINCREMENT;
    }

    *(s->top) = e;
    s->top++;
}

void Pop(sqStack *s, ElemType *e)
{
    if (s->top == s->base)
        return;
    *e = *--(s->top);
}

void ClearStack(sqStack *s)
{
    s->top = s->base;
}

void DestroyStack(sqStack *s)
{
    int i, len;
    len = s->stackSize;

    for (i = 0; i < len; i++) {
        free(s->base);
        s->base++;
    }

    s->base = s->top = NULL;
    s->stackSize = 0;
}

int StackLen(sqStack s)
{
    return (s.top - s.base);
}
