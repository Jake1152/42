/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_definition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/02/01 11:46:31 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // should be removed
#include "doublylist.h"

int main()
{
	t_DoublyList		*testDoublyList;
	t_DoublyListNode	*addedDoublyListNode;
	int					position;

	testDoublyList = createDoublyList();
	for (int i =0; i < 5; i++)
	{
		printf("main for loop : %d\n", i);
		addedDoublyListNode = createDoublyListNode(i);
		printf("addDLElement(testDoublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i, addedDoublyListNode));
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
	displayDoublyList(testDoublyList);

	printf("\n\n===============================\n");
	printf("test delete\n");
	deleteDoublyList(testDoublyList);
	printf("\n");
	displayDoublyList(testDoublyList);

	testDoublyList = createDoublyList();
	for (int i =5; i < 10; i++)
	{
		printf("main for loop : %d\n", i);
		addedDoublyListNode = createDoublyListNode(i);
		printf("addDLElement(testD oublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i, addedDoublyListNode));
	}
	printf("test delete\n");
	deleteDoublyList(testDoublyList);
	printf("\n");
	displayDoublyList(testDoublyList);

	printf("\n\n===============================\n");
	printf("test clear\n");
	clearDoublyList(testDoublyList);
	printf("\n");
	displayDoublyList(testDoublyList);
	testDoublyList = createDoublyList();
	for (int i =10; i < 15; i++)
	{
		printf("main for loop : %d\n", i);
		addedDoublyListNode = createDoublyListNode(i);
		printf("addDLElement(testD oublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i, addedDoublyListNode));
	}
	displayDoublyList(testDoublyList);
	printf("\n");
	clearDoublyList(testDoublyList);
	printf("\n");
	displayDoublyList(testDoublyList);

	printf("\n\n===============================\n");
	printf("test clear\n");

	return (0);
}

t_DoublyListNode	*createDoublyListNode(int data)
{
	t_DoublyListNode *newDoublyListNode;

	newDoublyListNode = (t_DoublyListNode *)malloc(sizeof(newDoublyListNode));
	if (newDoublyListNode == NULL)
		return (NULL);
	newDoublyListNode->pRLink = NULL;
	newDoublyListNode->pLLink = NULL;
	newDoublyListNode->data = data;
	return (newDoublyListNode);
}

t_DoublyList*	createDoublyList(void)
{
	t_DoublyList		*newDoublyList;

	newDoublyList = (t_DoublyList *)malloc(sizeof(newDoublyList));;
	if (newDoublyList == NULL)
		return (NULL);
	newDoublyList->headerNode = NULL;
	newDoublyList->currentElementCount = 0;

	return (newDoublyList);
}

void deleteDoublyList(t_DoublyList* pList)
{
	/*
		- 노드하나씩 free
		- 마지막으로 pList free
	*/
	if (pList == NULL)
		exit(EXIT_FAILURE);
	clearDoublyList(pList);	
	free(pList);
	pList = NULL;
}

void clearDoublyList(t_DoublyList* pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount > 0)
		removeDLElement(pList, 0);
}

