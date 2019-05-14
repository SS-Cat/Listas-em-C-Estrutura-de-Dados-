#ifndef _CardStack
#define _CardStack

#include <stdbool.h>
#include <stdlib.h>
#include "../Cards/card.h"

typedef struct cardStack
{
    CardNode *top;
    CardNode *bottom;
    int size;
} CardStack;

void initStack(CardStack *stack);

bool pushCardNode(CardStack *stack, Card card);

Card cardTop(CardStack stack);

void cleanStack(CardStack *stack);

void mergeStacks(CardStack *stack1, CardStack *stack2);

#endif
