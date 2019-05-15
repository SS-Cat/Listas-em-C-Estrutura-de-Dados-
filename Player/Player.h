#ifndef _Player
#define _Player

#include "../Cards/card.h"
#include "CardStack.h"

typedef struct player
{
	CardStack cardStack;
	int handCount;
	Card hand[4];
	int id;
	char *nome;
} Player;

void initPlayer(Player *player, int id, char *nome);

void printHand(Player player);

bool addToHand(Player *player, Card card);

bool removeOfHand(Player *player, Card card);

// void handRemoveItem(Player player, Board board, int index);

// void addToStack(Board board, Player player, int index1, int index2);

#endif
