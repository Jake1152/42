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

	testDoublyList = createDoublyList();
	for (int i =0; i < 5; i++)
	{
		printf("main for loop : %d\n", i);
		addedDoublyListNode = createDoublyListNode(i);
		printf("addDLElement(testDoublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i, addedDoublyListNode));
	}
	printf("\n\ntestDoublyList->headerNode->data %d\n", testDoublyList->headerNode->data);
	displayDoublyList(testDoublyList);

	printf("test remove\n");


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
}

void clearDoublyList(t_DoublyList* pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount != 0)
		removeDLElement(pList, 0);
}

