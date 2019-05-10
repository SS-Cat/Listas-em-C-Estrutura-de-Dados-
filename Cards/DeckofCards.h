#ifndef _Deck
#define _Deck

#include <stdbool.h>
#include <stdlib.h>
#include "card.h"

typedef struct deck 
{
  int numberOfCards;
  Card cards[52];
  // Stack* stack;
} DeckOfCards;

bool initDeck(DeckOfCards *deck);

void suffle(DeckOfCards *deck);

DeckOfCards dealCard(DeckOfCards *deck);

#endif
