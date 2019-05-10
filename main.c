#include <stdio.h>
#include <stdlib.h>
#include "Cards/DeckofCards.h"

extern int NUMBER_OF_CARDS;

int main(void)
{
	DeckOfCards deck;
	initDeck(&deck);
	for (int i = 0; i < NUMBER_OF_CARDS; i++)
	{
		cardToString(deck.cards[i]);
	}
	return 0;
}
