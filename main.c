#include "LinkedList.h"

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

	printList(l);

	removeListNode(&l, 7);
	printList(l);

	removeListNode(&l, 5);
	printList(l);

	removeListNode(&l, 234);
	printList(l);
	
	return 0;
}
