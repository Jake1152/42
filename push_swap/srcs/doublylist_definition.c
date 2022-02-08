/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_definition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/02/08 19:55:27 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/doublylist.h"

t_DoublyList	*createDoublyList(void)
{
	t_DoublyList		*newDoublyList;

	newDoublyList = (t_DoublyList *)malloc(sizeof(t_DoublyList));
	if (newDoublyList == NULL)
		return (NULL);
	newDoublyList->headerNode = (t_DoublyListNode *) NULL;
	newDoublyList->tailerNode = (t_DoublyListNode *) NULL;
	newDoublyList->currentElementCount = 0;
	return (newDoublyList);
}

t_DoublyListNode	*createDoublyListNode(int data)
{
	t_DoublyListNode	*newDoublyListNode;

	newDoublyListNode = (t_DoublyListNode *)malloc(sizeof(t_DoublyListNode));
	if (newDoublyListNode == NULL)
		return (NULL);
	newDoublyListNode->pRLink = (t_DoublyListNode *) NULL;
	newDoublyListNode->pLLink = (t_DoublyListNode *) NULL;
	newDoublyListNode->data = data;
	return (newDoublyListNode);
}

void	clearDoublyList(t_DoublyList *pList)
{
	if (pList == NULL)
		return ;
	while (pList->currentElementCount > 0)
		removeDLElement(pList, 0);
}

void	deleteDoublyList(t_DoublyList **pList)
{
	if (pList == NULL)
		return ;
	clearDoublyList(*pList);
	free(*pList);
	*pList = NULL;
}