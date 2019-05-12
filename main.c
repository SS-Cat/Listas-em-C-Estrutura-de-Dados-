#include <stdio.h>
#include <stdlib.h>
#include "Cards/DeckofCards.h"

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define BGYEL "\x1B[43m"
#define BGGRN "\x1B[42m"
#define RESET "\x1B[0m"

int main(void)
{
	DeckOfCards deck;
	initDeck(&deck);
	shuffle(&deck);
	for (int i = 0; i < deck.numberOfCards; i++)
	{
		if (i % 2 == 0)
			printf(GRN BGYEL "%s of %s\n" RESET, deck.cards[i].faceName, deck.cards[i].suit);
		else
			printf(YEL BGGRN "%s of %s\n" RESET, deck.cards[i].faceName, deck.cards[i].suit);
	}
	return 0;
}
