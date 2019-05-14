#include "../Cards/card.h"
#include "CardStack.h"

typedef struct player
{
	CardStack *cardStack;
	int handCount;
	Card hand[4];
} Player;

void printHand(Player player);

bool addToHand(Player *player, Card card);

bool removeOfHand(Player *player, Card card);

// void handRemoveItem(Player player, Board board, int index);

// void addToStack(Board board, Player player, int index1, int index2);

void fillHand(Player player);
