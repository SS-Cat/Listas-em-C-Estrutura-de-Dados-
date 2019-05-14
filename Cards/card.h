#ifndef _Card
#define _Card

#include <stdlib.h>

typedef struct card
{
	char *faceName;
	int faceNumber;
	char *suit;
	int suitNumber;
} Card;

typedef struct node
{
	Card card;
	struct node *next;
} CardNode;

CardNode *createCardNode(Card card);

void printCard(Card card);

char *normalizeCardNumber(int CardNumber);

#endif
