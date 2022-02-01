/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/02/01 13:08:36 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // should be removed
#include "doublylist.h"

void displayDoublyList(t_DoublyList* pList)
{
	t_DoublyListNode	*curDoublyListNode;
	int					cnt;
	// DoublyListNode	curDoublyListNode;
	// curDoublyListNode.pLLink = &pLLink;
	if (pList == NULL || pList->currentElementCount <= 0)
	{
		printf("pList is NULL or\n");
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

int getDoublyListLength(t_DoublyList* pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}

t_DoublyListNode* getDLElement(t_DoublyList* pList, int position)
{
	t_DoublyListNode	*curDoublyListNode;

	if (pList == NULL)
		return (NULL);
	if (position < 0 || position > pList->currentElementCount)
		return (NULL);
	curDoublyListNode = pList->headerNode;
	if (position < (pList->currentElementCount-1)/2)
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

int addDLElement(t_DoublyList* pList, int position, t_DoublyListNode *newNode)
{
	t_DoublyListNode	*prevNode;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (pList->currentElementCount == 0)
	{
		newNode->pLLink = newNode;
		newNode->pRLink = newNode;
		pList->headerNode = newNode;
		return (pList->currentElementCount++);
	}
	if (position == 0)
	{	
		prevNode = getDLElement(pList, pList->currentElementCount - 1);
		pList->headerNode = newNode;
	}
	else
		prevNode = getDLElement(pList, position - 1);
	if (prevNode == NULL)
		return (FALSE);
	newNode->pLLink = prevNode;
	newNode->pRLink = prevNode->pRLink;
	if (pList->currentElementCount >= 1)
		prevNode->pRLink->pLLink = newNode;
	prevNode->pRLink = newNode;
	return (pList->currentElementCount++);
}

int removeDLElement(t_DoublyList* pList, int position)
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
	curDoublyListNode =  NULL;
	pList->currentElementCount--;
	return (pList->currentElementCount);
}

