#ifndef _Deck
#define _Deck

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

typedef struct deck
{
  int numberOfCards;
  Card cards[52];
  // Stack* stack;
} DeckOfCards;

bool initDeck(DeckOfCards *deck);

void shuffle(DeckOfCards *deck);

void printDeck(DeckOfCards deck);

DeckOfCards dealCard(DeckOfCards *deck);

#endif
