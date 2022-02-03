/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_definition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/02/03 19:48:46 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
		displayDoublyList(testDoublyList);
		printf("main for loop : %d\n", i);
		printf("== before addedDoublyListNode\n");
		addedDoublyListNode = createDoublyListNode(i);
		printf("== after addedDoublyListNode\n");
		if (i > 0)
		{
			printf("=== in Main prevListNode\n");
			prevListNode = getDLElement(testDoublyList, i-1);
			printf("=== in Main prevListNode : %p\n", prevListNode);
			printf("=== in Main prevListNode->pLLink : %p\n", prevListNode->pLLink);
			printf("=== in Main prevListNode->pRLink : %p\n", prevListNode->pRLink);
		}
			
		// printf("after create addedDoublyListNode\n");
		printf("addDLElement(testDoublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i, addedDoublyListNode));
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

t_DoublyListNode	*createDoublyListNode(int data)
{
	t_DoublyListNode	*newDoublyListNode;

	printf("- start of createDoublyListNode\n");
	newDoublyListNode = (t_DoublyListNode *)malloc(sizeof(newDoublyListNode));
	if (newDoublyListNode == NULL)
	{
		printf("Failed allocation\n");
		return (NULL);
	}
	printf("after alloc in createDoublyListNode\n");
	newDoublyListNode->pRLink = (t_DoublyListNode *)NULL;
	newDoublyListNode->pLLink = (t_DoublyListNode *)NULL;
	newDoublyListNode->data = data;
	printf("- end of createDoublyListNode\n");
	return (newDoublyListNode);
}

t_DoublyList	*createDoublyList(void)
{
	t_DoublyList		*newDoublyList;

	newDoublyList = (t_DoublyList *)malloc(sizeof(newDoublyList));
	if (newDoublyList == NULL)
		return (NULL);
	newDoublyList->headerNode = (t_DoublyListNode *)NULL;
	newDoublyList->currentElementCount = 0;
	return (newDoublyList);
}

void	deleteDoublyList(t_DoublyList **pList)
{
	if (pList == NULL)
		return ;
	clearDoublyList(*pList);
	free(*pList);
	*pList = NULL;
}

void	clearDoublyList(t_DoublyList *pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount > 0)
		removeDLElement(pList, 0);
}
