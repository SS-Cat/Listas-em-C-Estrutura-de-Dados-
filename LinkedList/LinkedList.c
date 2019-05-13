#include "LinkedList.h"

bool initList(List *list)
{
	list->start = NULL;
	list->size = 0;
	return true;
}

Node *createNode(int key)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->key = key;
	newNode->next = NULL;
	return newNode;
}

bool addListNode(List *list, int key)
{
	Node *new_node = createNode(key);
	if (new_node == NULL)
		return false;

	if (list->size == 0)
		list->start = new_node;
	else
	{
		Node *corrente = list->start;

		while (corrente->next != NULL)
			corrente = corrente->next;

		corrente->next = new_node;
	}

	if (list->start == NULL)
		return false;

	list->size++;
	return true;
}

Node *removeListNode(List *list, int key)
{
	if (list->size == 0)
		return NULL;

	Node *iterate = list->start, *slibling = NULL;
	while (iterate != NULL && iterate->key != key)
	{
		slibling = iterate;
		iterate = iterate->next;
	}

	if (slibling == NULL)
		list->start = iterate->next;
	else
	{
		slibling->next = iterate->next;
	}

	if (iterate == NULL)
		return false;

	Node *node_remove = iterate;
	free(iterate);
	list->size--;

	return node_remove;
}

void endLine()
{
	printf("\n");
}

void printList(List l)
{
	endLine();
	printf("Printing List");
	endLine();
	printf("List size: %d", l.size);
	endLine();
	printf("Node Value | Index");
	endLine();
	int index = 0;
	Node *iterate = l.start;

	while (iterate->next != NULL)
	{
		printf("Value:  %d |  %d  ", iterate->key, index);
		endLine();
		index++;
		iterate = iterate->next;
	}

	printf("Value:  %d |  %d  ", iterate->key, index);
	endLine();
	printf("*** *** *** *** *** ***");
}