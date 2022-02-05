/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/02/05 17:29:02 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // should be removed
#include "doublylist.h"

void displayDoublyList(t_DoublyList *pList)
{
	t_DoublyListNode	*curDoublyListNode;
	int					cnt;
	// DoublyListNode	curDoublyListNode;
	// curDoublyListNode.pLLink = &pLLink;
	printf("== in displayDoublyList\n");
	if (pList == NULL || pList->currentElementCount <= 0)
	{
		printf("pList is NULL\n");
		if (pList != NULL)
			printf("pList->currentElementCount : %d\n", pList->currentElementCount);
		return ;
	}
	curDoublyListNode = pList->headerNode;
	printf("=====================\n");
	printf("displayDoublyList\n");
	printf("=====================\n");
	cnt = 1;
	printf("display right bound\n");
	while (pList->currentElementCount > cnt)
	{
		printf("%d->", curDoublyListNode->data);
		curDoublyListNode = curDoublyListNode->pRLink;
		cnt++;
	}
	printf("%d", curDoublyListNode->data);
	printf("\n");
	curDoublyListNode = pList->headerNode;
	cnt = 1;
	printf("display left bound\n");
	while (pList->currentElementCount > cnt)
	{
		printf("%d->", curDoublyListNode->data);
		curDoublyListNode = curDoublyListNode->pLLink;
		cnt++;
	}
	printf("%d", curDoublyListNode->data);
	printf("\n");
	printf("end of display\n");
}

int	getDoublyListLength(t_DoublyList *pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}

t_DoublyListNode	*getDLElement(t_DoublyList *pList, int position)
{
	t_DoublyListNode	*curDoublyListNode;

	printf("- Start of getDLElement\n\n\n");

	displayDoublyList(pList);
	if (pList == NULL || position < 0 || position > pList->currentElementCount)
	{
		printf("== pList is NULL or position is less than 0\n");
		return (NULL);
	}
	curDoublyListNode = pList->headerNode;
	//  0 1 2 3 4 5
	if (position < pList->currentElementCount / 2)
	{
		while (position > 0)
		{
			curDoublyListNode = curDoublyListNode->pRLink;
			position--;
		}
	}
	else
	{
		while (pList->currentElementCount - position > 0)
		{
			curDoublyListNode = curDoublyListNode->pLLink;
			position++;
		}
	}
	printf("#### in getDLElement\n");
	printf("curDoublyListNode is %d\n", curDoublyListNode->data);
	printf("curDoublyListNode address is %p\n", curDoublyListNode);
	printf("curDoublyListNode->pLLink %p\n", curDoublyListNode->pLLink);
	printf("curDoublyListNode->pRLink %p\n", curDoublyListNode->pRLink);
	printf("- End of getDLElement\n");
	return (curDoublyListNode);
}

int	addDLElement(t_DoublyList* pList, int position, t_DoublyListNode *newNode)
{
	t_DoublyListNode	*prevNode;

	printf("- Start of addDLElement positon is %d\n", position);
	if (pList == NULL || position < 0 || position > pList->currentElementCount)
	{
		printf("== pList is NULL in addDLElement\n");
		return (FALSE);
	}
	if (pList->currentElementCount == 0)
	{
		printf("newNode address is : %p\n", newNode);
		newNode->pLLink = newNode;
		newNode->pRLink = newNode;
		printf("newNode->pLLink address : %p\n", newNode->pLLink);
		printf("newNode->pRLink address : %p\n", newNode->pRLink);
		pList->headerNode = newNode;
		printf("newNode->pLLink->data : %d\n", newNode->pLLink->data);
		printf("newNode->pRLink->data : %d\n", newNode->pRLink->data);
		printf("after pointed Header node to newNode\n");
		printf("newNode->pLLink address : %p\n", newNode->pLLink);
		printf("newNode->pRLink address : %p\n", newNode->pRLink);
		return (pList->currentElementCount++);
	}
	if (position == 0)
	{
		prevNode = getDLElement(pList, 0);
		pList->headerNode = newNode;
	}
	else
		prevNode = getDLElement(pList, position - 1);
	if (prevNode == NULL)
		return (FALSE);
	printf("success getDLElement\n");
	printf("prevNode address is : %p\n", prevNode);
	printf("prevNode->data : %d\n", prevNode->data);
	printf("prevNode->pLLink : %p\n", prevNode->pLLink);
	printf("prevNode->pRLink : %p\n", prevNode->pRLink);
	printf("prevNode->pRLink->data : %d\n", prevNode->pRLink->data);
	newNode->pLLink = prevNode;
	newNode->pRLink = prevNode->pRLink;
	printf("newNode->pRLink->data : %d\n", newNode->pRLink->data);
	if (pList->currentElementCount >= 1)
		prevNode->pRLink->pLLink = newNode;
	prevNode->pRLink = newNode;
	printf("- End of addDLElement\n");
	return (pList->currentElementCount++);
}

int	removeDLElement(t_DoublyList *pList, int position)
{
	t_DoublyListNode	*prevDoublyListNode;
	t_DoublyListNode	*curDoublyListNode;
	t_DoublyListNode	*nextDoublyListNode;

	if (pList == NULL)
		return (FALSE);
	if (position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	curDoublyListNode = getDLElement(pList, position);
	if (curDoublyListNode == NULL)
		return (FALSE);
	prevDoublyListNode = curDoublyListNode->pLLink;
	nextDoublyListNode = curDoublyListNode->pRLink;
	if (position == 0)
		pList->headerNode = nextDoublyListNode;
	if (pList->currentElementCount == 1)
		pList->headerNode = NULL;
	prevDoublyListNode->pRLink = curDoublyListNode->pRLink;
	nextDoublyListNode->pLLink = curDoublyListNode->pLLink;
	free(curDoublyListNode);
	curDoublyListNode = NULL;
	pList->currentElementCount--;
	return (pList->currentElementCount);
}
