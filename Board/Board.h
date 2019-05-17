#ifndef _Board
#define _Board

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Cards/card.h"

typedef struct gameBoard
{
	CardNode *start;
	CardNode *end;
	int size;
} GameBoard;

bool initBoard(GameBoard *board);

bool addListNode(GameBoard *board, Card card);

Card *removeListNode(GameBoard *board, Card card);

CardNode *pickIndex(GameBoard board, int index);

bool searchCardBoard(GameBoard board, Card card);

void printList(GameBoard board);

void endLine();

#endif
