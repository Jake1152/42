/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_definition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/02/05 20:08:26 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // should be removed
#include "doublylist.h"

t_DoublyListNode	*createDoublyListNode(int data)
{
	t_DoublyListNode	*newDoublyListNode;

	printf("- Start of createDoublyListNode\n");
	newDoublyListNode = (t_DoublyListNode *)malloc(sizeof(newDoublyListNode));
	if (newDoublyListNode == NULL)
	{
		printf("*********** FAIL to allocation t_DoublyListNode\n");
		return (NULL);
	}
	printf("after alloc in createDoublyListNode\n");
	newDoublyListNode->pRLink = (t_DoublyListNode *) NULL;
	newDoublyListNode->pLLink = (t_DoublyListNode *) NULL;
	newDoublyListNode->data = data;
	printf("- End of createDoublyListNode\n");
	return (newDoublyListNode);
}

t_DoublyList	*createDoublyList(void)
{
	t_DoublyList		*newDoublyList;

	newDoublyList = (t_DoublyList *)malloc(sizeof(newDoublyList));
	if (newDoublyList == NULL)
	{
		printf("*********** FAIL to allocation t_DoublyList\n");
		return (NULL);
	}
	newDoublyList->headerNode = (t_DoublyListNode *) NULL;
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
