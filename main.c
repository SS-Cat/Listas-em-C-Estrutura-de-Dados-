#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *next;
} Node;

typedef struct list
{
	Node *start;
	int size;
} List;

bool initList(List *list);

Node *createNode(int key);

bool addListNode(List *list, int key);

Node *removeListNode(List *list, int key);

void endLine();

void printList(List l);




int main(void)
{
	List l;
	initList(&l);
	addListNode(&l, 5);
	addListNode(&l, 7);
	addListNode(&l, 12);
	addListNode(&l, 25);
	addListNode(&l, 90);
	addListNode(&l, 20);
	addListNode(&l, 234);



	// printf("Valor: %d\n", l.start->key);
	// printf("Valor: %d\n", l.start->next->key);
	// printf("Valor: %d\n", l.start->next->next->key);
	printList(l);

	removeListNode(&l, 7);
	printList(l);

	removeListNode(&l, 5);
	printList(l);

	removeListNode(&l, 234);
	printList(l);

	return 0;
}
