#include "Board.h"

bool initBoard(GameBoard *board)
{
	board->start = NULL;
	board->end = NULL;
	board->size = 0;
	return true;
}

bool addListNode(GameBoard *board, Card card)
{
	CardNode *new_card = createCardNode(card);
	if (new_card == NULL)
		return false;

	if (board->size == 0)
	{
		board->start = new_card;
		board->end = new_card;
	}
	else
	{
		CardNode *temp = board->start;
		new_card->next = temp;
		board->start = new_card;
	}

	board->size++;
	return true;
}

Card *removeListNode(GameBoard *board, Card card)
{
	if (board->size == 0)
		return NULL;

	CardNode *iterate = board->start, *slibling = NULL;
	while (iterate != NULL && iterate->card.faceNumber != card.faceNumber || iterate->card.suitNumber != card.suitNumber)
	{
		slibling = iterate;
		iterate = iterate->next;
	}

	if (slibling == NULL)
		board->start = iterate->next;
	else
	{
		slibling->next = iterate->next;
	}

	if (iterate == NULL)
		return false;

	CardNode *node_remove = iterate;
	free(iterate);
	board->size--;

	return &node_remove->card;
}

CardNode *pickIndex(GameBoard board, int index)
{
	CardNode *pick = board.start;
	for (int i = 0; i < index - 1; i++)
	{
		pick = pick->next;
	}
	return pick;
}

bool searchCardBoard(GameBoard board, Card card)
{
	CardNode *search = board.start;
	for (int i = 0; i < board.size; i++)
	{
		if (search->card.faceNumber == card.faceNumber && 
		search->card.suitNumber == card.suitNumber)
		{
			return true;
		}
		search = search->next;
	}
	return false;
}

void endLine()
{
	printf("\n");
}

void printList(GameBoard board)
{
	printf("Mesa:\n");
	printf("*** *** *** *** *** ***\n");
	CardNode *iterate = board.start;
	for (int i = 0; i < board.size; i++)
	{
		printf("Selecione %d |", i + 1);
		printCard(iterate->card);
		iterate = iterate->next;
	}

	printf("*** *** *** *** *** ***\n");
}