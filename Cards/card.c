#include <stdio.h>
#include <string.h>
#include "card.h"

void cardToString(Card card)
{
    printf("%s of %s\n", card.faceName, card.suit);
}
