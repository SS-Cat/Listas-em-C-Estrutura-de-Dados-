#include "CardStack.h"

void initStack(CardStack *stack)
{
    stack->size = 0;
    stack->top = NULL;
    stack->bottom = NULL;
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

void cleanStack(CardStack *stack)
{
    CardNode *corrente = stack->bottom;
    while (corrente->next != NULL)
    {
        CardNode *clean = corrente;
        corrente = corrente->next;
        free(clean);
    }
    initStack(stack);
}

void mergeStacks(CardStack *stack1, CardStack *stack2)
{
    CardStack stack = *stack2;

    stack1->bottom->next = stack.top;
    stack1->bottom = stack.bottom;
    stack1->size += stack.size;

    initStack(stack2);
}