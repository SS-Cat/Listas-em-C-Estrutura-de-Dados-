#include "DeckofCards.h"
#include "card.h"

#define BGRED "\x1B[41m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

const int NUMBER_OF_CARDS = 52;

void initDeck(DeckOfCards *deck)
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
	deck->top = deck->numberOfCards - 1;
	for (int iterate = 0; iterate < deck->numberOfCards; iterate++)
	{
		Card carta;
		int face = iterate % 13;
		int suit = iterate / 13;

		carta.faceName = faces[face];
		carta.faceNumber = face + 1;
		carta.suit = suits[suit];
		carta.suitNumber = suit + 1;

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

bool dealCard(DeckOfCards *deck, Card *card)
{
	if (deck->top < 0)
	{
		printf(BGRED WHT "Acabou as cartas\n" RESET);
		card = NULL;
		return false;
	}
	else
	{
		Card temp = deck->cards[deck->top--];
		card->faceName = temp.faceName;
		card->faceNumber = temp.faceNumber;
		card->suit = temp.suit;
		return true;
	}
}

void printDeck(DeckOfCards deck)
{
	for (int i = 0; i < deck.numberOfCards; i++)
	{
		printCard(deck.cards[i]);
	}
}
