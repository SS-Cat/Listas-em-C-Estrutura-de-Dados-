#include <stdio.h>
#include <string.h>
#include "card.h"

#define WHT "\x1B[37m"
#define BKBLU "\x1B[44m"
#define RESET "\x1B[0m"

void printCard(Card card)
{
    printf(BKBLU WHT "%s of %s\n" RESET, card.faceName, card.suit);
}
