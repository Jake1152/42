/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/02/08 21:48:05 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // should be removed
#include "../include/doublylist.h"

void displayDoublyList(t_DoublyList *pList)
{
	t_DoublyListNode	*rightBoundDoublyListNode;
	t_DoublyListNode	*leftBoundDoublyListNode;
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
	rightBoundDoublyListNode = pList->headerNode;
	printf("##### headerNode is %d\n", rightBoundDoublyListNode->data);
	printf("=====================\n");
	printf("displayDoublyList\n");
	printf("=====================\n");
	cnt = 1;
	printf("display right bound\n");
	while (pList->currentElementCount > cnt)
	{
		printf("%d->", rightBoundDoublyListNode->data);
		rightBoundDoublyListNode = rightBoundDoublyListNode->pRLink;
		cnt++;
	}
	printf("%d", rightBoundDoublyListNode->data);
	printf("\n");
	leftBoundDoublyListNode = pList->tailerNode;
	printf("##### tailerNode is %d\n", leftBoundDoublyListNode->data);
	cnt = 1;
	printf("display left bound\n");
	while (pList->currentElementCount > cnt)
	{
		printf("%d->", leftBoundDoublyListNode->data);
		leftBoundDoublyListNode = leftBoundDoublyListNode->pLLink;
		cnt++;
	}
	printf("%d", leftBoundDoublyListNode->data);
	printf("\n");
	printf("end of display\n");
}

t_DoublyListNode	*getDLElement(t_DoublyList *pList, int position)
{
	t_DoublyListNode	*curDoublyListNode;

	if (pList == NULL || position > pList->currentElementCount)
		return (NULL);
	if (position < 0)
		position = pList->currentElementCount \
		+ (position % pList->currentElementCount);
	curDoublyListNode = pList->headerNode;
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
	return (curDoublyListNode);
}

int	addDLElement_at_first_time(t_DoublyList *pList, t_DoublyListNode *newNode)
{
	if (pList == NULL || newNode == NULL)
		return (FALSE);
	newNode->pLLink = newNode;
	newNode->pRLink = newNode;
	pList->headerNode = newNode;
	pList->tailerNode = newNode;
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

int	addDLElement(t_DoublyList *pList, int position, t_DoublyListNode *newNode)
{
	t_DoublyListNode	*prevNode;

	if (pList == NULL || position < 0 || position > pList->currentElementCount \
		|| newNode == NULL)
		return (FALSE);
	if (pList->currentElementCount == 0)
		return (addDLElement_at_first_time(pList, newNode));
	prevNode = getDLElement(pList, position - 1);
	if (prevNode == NULL)
		return (FALSE);
	if (position == 0)
		pList->headerNode = newNode;
	if (position == pList->currentElementCount)
		pList->tailerNode = newNode;
	newNode->pLLink = prevNode;
	newNode->pRLink = prevNode->pRLink;
	prevNode->pRLink->pLLink = newNode;
	prevNode->pRLink = newNode;
	return (pList->currentElementCount++);
}

int	removeDLElement(t_DoublyList *pList, int position)
{
	t_DoublyListNode	*prevDoublyListNode;
	t_DoublyListNode	*curDoublyListNode;

	if (pList == NULL)
		return (FALSE);
	if (position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	curDoublyListNode = getDLElement(pList, position);
	if (curDoublyListNode == NULL)
		return (FALSE);
	prevDoublyListNode = curDoublyListNode->pLLink;
	if (position == 0)
		pList->headerNode = curDoublyListNode->pRLink;
	if (pList->currentElementCount - 1 == position)
		pList->tailerNode = prevDoublyListNode;
	if (pList->currentElementCount == 1)
	{
		pList->headerNode = NULL;
		pList->tailerNode = NULL;
	}
	prevDoublyListNode->pRLink = curDoublyListNode->pRLink;
	curDoublyListNode->pRLink->pLLink = curDoublyListNode->pLLink;
	free(curDoublyListNode);
	curDoublyListNode = NULL;
	return (pList->currentElementCount--);
}
