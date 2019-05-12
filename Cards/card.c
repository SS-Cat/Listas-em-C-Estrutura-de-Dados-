#include <stdio.h>
#include <string.h>
#include "card.h"

void printCard(Card card)
{
    printf("%s of %s\n", card.faceName, card.suit);
}
