#include <stdio.h> // should be removed
#include "doublylist.h"

int main()
{
	t_DoublyList		*testDoublyList;
	t_DoublyListNode	*addedDoublyListNode;
	t_DoublyListNode	*prevListNode;
	t_DoublyListNode	*curListNode;
	int					position;
	int					start_num;

	testDoublyList = createDoublyList();
	for (int i = 0; i < 5; i++)
	{
		addedDoublyListNode = NULL;
		printf("\n=========== main for loop : %d\n", i);
		displayDoublyList(testDoublyList);
		if (i > 0)
		{
			printf("=== in Main prevListNode\n");
			prevListNode = getDLElement(testDoublyList, i-1);
			printf("=== in Main prevListNode : %p\n", prevListNode);
			printf("=== in Main prevListNode->pLLink : %p\n", prevListNode->pLLink);
			printf("=== in Main prevListNode->pRLink : %p\n", prevListNode->pRLink);
			if (i > 1)
				;
				// while (42);
		}
		printf("== before createDoublyListNode\n");
		addedDoublyListNode = createDoublyListNode(i);
		printf("== after createDoublyListNode\n");

		if (i > 0)
		{
			printf("### in Main prevListNode\n");
			prevListNode = getDLElement(testDoublyList, i-1);
			printf("### in Main prevListNode : %p\n", prevListNode);
			printf("### in Main prevListNode->pLLink : %p\n", prevListNode->pLLink);
			printf("### in Main prevListNode->pRLink : %p\n", prevListNode->pRLink);
			if (i > 1)
				while (42);
		}

		// printf("after create addedDoublyListNode\n");
		printf("addDLElement(testDoublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i, addedDoublyListNode));
		addedDoublyListNode = NULL;
		curListNode =  getDLElement(testDoublyList, i);
		printf("=== getDLElement(pList, i) : %p\n", curListNode);
		printf("=== curListNode->data : %d\n", curListNode->data);
		printf("=== curListNode->pLLink : %p\n", curListNode->pLLink);
		printf("=== curListNode->pRLink : %p\n", curListNode->pRLink);
	}
	printf("\n\ntestDoublyList->headerNode->data %d\n", testDoublyList->headerNode->data);
	displayDoublyList(testDoublyList);

	printf("\n\n===============================\n");
	printf("test remove\n");
	position = 3;
	printf("position : %d\n", position);
	printf("removeDLElement(testDoublyList, position) : %d\n", removeDLElement(testDoublyList, position));
	displayDoublyList(testDoublyList);
	position = 0;
	printf("position : %d\n", position);
	printf("removeDLElement(testDoublyList, position) : %d\n", removeDLElement(testDoublyList, position));
	displayDoublyList(testDoublyList);
	position = 1;
	printf("position : %d\n", position);
	printf("removeDLElement(testDoublyList, position) : %d\n", removeDLElement(testDoublyList, position));
	displayDoublyList(testDoublyList);
	position = 1;
	printf("position : %d\n", position);
	printf("removeDLElement(testDoublyList, position) : %d\n", removeDLElement(testDoublyList, position));
	displayDoublyList(testDoublyList);
	position = 0;
	printf("position : %d\n", position);
	printf("removeDLElement(testDoublyList, position) : %d\n", removeDLElement(testDoublyList, position));
	printf("\n");
	printf("current count is %d\n", testDoublyList->currentElementCount);
	displayDoublyList(testDoublyList);

	printf("\n\n===============================\n");
	printf("test delete\n");
	deleteDoublyList(&testDoublyList);
	if (testDoublyList == NULL)
		printf("after delete, plist be NULL assigned.\n");
	printf("\n");
	printf("test delete\n");
	deleteDoublyList(&testDoublyList);
	if (testDoublyList == NULL)
		printf("after delete, plist be NULL assigned.\n");
	printf("\n");
	displayDoublyList(testDoublyList);

	testDoublyList = createDoublyList();
	if (testDoublyList == NULL)
		printf("\n====testDoublyList is NULL===\n");
	else
		printf("new doublylist current count is : %d\n", testDoublyList->currentElementCount);
	start_num = 5;
	for (int i =start_num; i < 10; i++)
	{
		printf("main for loop : %d\n", i);
		addedDoublyListNode = createDoublyListNode(i);
		printf("addDLElement(testDoublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i - start_num, addedDoublyListNode));
		addedDoublyListNode = NULL;
		displayDoublyList(testDoublyList);
	}
	displayDoublyList(testDoublyList);
	printf("\n");
	printf("test delete\n");
	deleteDoublyList(&testDoublyList);
	printf("\n");
	displayDoublyList(testDoublyList);

	printf("\n\n===============================\n");
	printf("test clear\n");
	clearDoublyList(testDoublyList);
	printf("\n");
	displayDoublyList(testDoublyList);
	testDoublyList = createDoublyList();
	if (testDoublyList == NULL)
		printf("\n====testDoublyList is NULL===\n");
	else
		printf("new doublylist current count is : %d\n", testDoublyList->currentElementCount);
	start_num = 10;
	for (int i = start_num; i < 15; i++)
	{
		printf("main for loop : %d\n", i);
		addedDoublyListNode = createDoublyListNode(i);
		printf("addDLElement(testD oublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i - start_num, addedDoublyListNode));
		addedDoublyListNode = NULL;
		displayDoublyList(testDoublyList);
	}
	displayDoublyList(testDoublyList);
	printf("\n");
	printf("test clear\n");
	clearDoublyList(testDoublyList);
	printf("\n");
	displayDoublyList(testDoublyList);

	printf("\n\n===============================\n");
	printf("finally test clear\n");

	return (0);
}
