#include <stdbool.h>

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
