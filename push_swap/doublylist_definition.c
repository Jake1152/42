/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/01/29 19:49:44 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // should be removed
#include "doublylist.h"

int main()
{
	t_DoublyList		*testDoublyList;
	t_DoublyListNode	*addedDoublyListNode;

	for (int i =0; i < 5; i++)
	{
		addedDoublyListNode = createDoublyListNode(i);
		printf("addDLElement(testDoublyList, i, addedDoublyListNode) : %d\n", addDLElement(testDoublyList, i, *addedDoublyListNode));
		displayDoublyList(testDoublyList);
	}
	
	printf("\n\ntestDoublyList->headerNode.data %d\n", testDoublyList->headerNode->data);
	displayDoublyList(testDoublyList);

	return (0);
}

static t_DoublyListNode	*createDoublyListNode(int data)
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
		return (NULL);
	while (pList->currentElementCount != 0)
		removeDLElement(pList, 0);
}

