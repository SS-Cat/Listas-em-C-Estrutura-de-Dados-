#ifndef _Card
#define _Card

typedef struct card
{
	char *faceName;
	int faceNumber;
	char *suit;
} Card;

void printCard(Card card);

char *normalizeCardNumber(int CardNumber);

#endif
