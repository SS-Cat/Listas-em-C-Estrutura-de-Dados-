#ifndef _Deck
#define _Deck

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "card.h"

typedef struct deck
{
  int numberOfCards;
  Card cards[52];
  int top;
} DeckOfCards;

void initDeck(DeckOfCards *deck);

void shuffle(DeckOfCards *deck);

bool dealCard(DeckOfCards *deck, Card *card);

void printDeck(DeckOfCards deck);

#endif
