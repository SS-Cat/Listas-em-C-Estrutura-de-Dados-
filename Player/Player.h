#ifndef _Player
#define _Player

#include "../Cards/card.h"
#include "CardStack.h"
#include <stdio.h>

typedef struct player
{
	CardStack cardStack;
	int handCount;
	Card hand[4];
	int id;
	char *nome;
} Player;

void initPlayer(Player *player, int id);

void printHand(Player player);

bool addToHand(Player *player, Card card);

bool removeOfHand(Player *player, Card *card);

int searchCard(Player player, Card card);

Card cardTop(Player player);

#endif
