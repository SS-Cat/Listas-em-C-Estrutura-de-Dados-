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
	for (int iterate = 0; iterate < deck->numberOfCards; iterate++)
	{
		Card carta;
		int face = iterate % 13;

		carta.faceName = faces[face];
		carta.faceNumber = face;
		carta.suit = suits[iterate / 13];

		deck->cards[iterate] = carta;
	}
}

void shuffle(DeckOfCards *deck)
{
	srand(time(NULL));
	for (int iterate = 0; iterate < deck->numberOfCards; iterate++)
	{
		int randomIndex = rand() % deck->numberOfCards;
		Card temp = deck->cards[iterate];
		deck->cards[iterate] = deck->cards[randomIndex];
		deck->cards[randomIndex] = temp;
	}
}

void printDeck(DeckOfCards deck)
{
	for (int i = 0; i < deck.numberOfCards; i++)
	{
		printCard(deck.cards[i]);
	}
}
