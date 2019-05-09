#ifndef deck
#define deck

#include <stdbool.h>
#include "card.h"

typedef struct Deck {
  Card card[];
  int numberOfCards;
} DeckOfCards;

bool initDeck(DeckOfCards deck);

void suffle(DeckOfCards deck);

DeckOfCards dealCard(DeckOfCards deck);

#endif
