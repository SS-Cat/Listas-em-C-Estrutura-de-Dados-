#include <stdio.h>
#include "DeckofCards.h"
#include "card.h"

const int NUMBER_OF_CARDS = 52;

bool initDeck(DeckOfCards *deck)
{
	char *suits[4] = {"Hearts",
					  "Diamonds",
					  "Clubs",
					  "Spades"};

	char *faces[13] = {"Ace",
					   "Deuce",
					   "Three",
					   "Four",
					   "Five",
					   "Six",
					   "Seven",
					   "Eight",
					   "Nine",
					   "Ten",
					   "Jack",
					   "Queen",
					   "King"};

	deck->numberOfCards = NUMBER_OF_CARDS;
	for (int iterate = 0; iterate < NUMBER_OF_CARDS; iterate++)
	{
		Card carta;
		int face = iterate % 13;

		carta.faceName = faces[face];
		carta.faceNumber = face;
		carta.suit = suits[iterate / 13];

		deck->cards[iterate] = carta;
	}
}

// int main(int argc, char const *argv[])
// {
// 	DeckOfCards deck;
// 	initDeck(&deck);
// 	for (int i = 0; i < NUMBER_OF_CARDS; i++)
// 	{
// 		cardToString(deck.cards[i]);
// 	}

// 	return 0;
// }