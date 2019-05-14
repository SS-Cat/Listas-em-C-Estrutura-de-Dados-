#ifndef _CardStack
#define _CardStack

#include <stdbool.h>
#include <stdlib.h>
#include "../Cards/card.h"

typedef struct node
{
    Card card;
    struct node *next;
} CardNode;

typedef struct cardStack
{
    CardNode *top;
    CardNode *bottom;
    int size;
} CardStack;

void initStack(CardStack *stack);

CardNode *createCardNode(Card card);

bool pushCardNode(CardStack *stack, Card card);

Card cardTop(CardStack stack);

void cleanStack(CardStack *stack);

void mergeStacks(CardStack *stack1, CardStack *stack2);

#endif
