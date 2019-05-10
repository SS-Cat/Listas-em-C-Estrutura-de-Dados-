#ifndef _Card
#define _Card

typedef struct card
{
	char *faceName;
	int faceNumber;
	char *suit;
} Card;

void cardToString(Card card);

#endif
