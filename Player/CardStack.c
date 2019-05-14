#include "CardStack.h"

void initStack(CardStack *stack)
{
    stack->size = 0;
    stack->top = NULL;
    stack->bottom = NULL;
}

CardNode *createCardNode(Card card)
{
    CardNode *newNode = (CardNode *)malloc(sizeof(CardNode));
    newNode->card = card;
    newNode->next = NULL;
    return newNode;
}

bool pushCardNode(CardStack *stack, Card card)
{
    CardNode *newNode = createCardNode(card);
    if (newNode == NULL)
        return false;

    if (stack->size == 0)
    {
        stack->top = newNode;
        stack->bottom = newNode;
    }
    else
    {
        CardNode *temp = stack->top;
        newNode->next = temp;
        stack->top = newNode;
    }
    stack->size++;
    return true;
}

Card cardTop(CardStack stack)
{
    return stack.top->card;
}

void cleanStack(CardStack *stack)
{
    CardNode *corrente = stack->top;
    initStack(stack);
    while (corrente->next != NULL)
    {
        CardNode *clean = corrente;
        corrente = corrente->next;
        free(clean);
    }
}

void mergeStacks(CardStack *stack1, CardStack *stack2)
{
    CardStack stack = *stack2;

    stack1->bottom->next = stack.top;
    stack1->bottom = stack.bottom;
    stack1->size += stack.size;

    initStack(stack2);
}