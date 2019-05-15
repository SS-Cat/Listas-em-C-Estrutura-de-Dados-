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
	while (iterate != NULL &&
		   iterate->card.faceNumber != card.faceNumber &&
		   iterate->card.suitNumber != card.suitNumber)
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

void endLine()
{
	printf("\n");
}

void printList(GameBoard board)
{
	endLine();
	printf("Printing List");
	endLine();
	printf("List size: %d", board.size);
	endLine();
	printf("Node Value | Index");
	endLine();
	int index = 0;
	CardNode *iterate = board.start;

	while (iterate->next != NULL)
	{
		printf("Value:  %d/%d |  %d  ", iterate->card.faceNumber, iterate->card.suitNumber, index);
		endLine();
		index++;
		iterate = iterate->next;
	}

	printf("Value:  %d/%d |  %d  ", iterate->card.faceNumber, iterate->card.suitNumber, index);
	endLine();
	printf("*** *** *** *** *** ***");
}