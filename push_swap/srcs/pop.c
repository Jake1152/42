/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:11:45 by jim               #+#    #+#             */
/*   Updated: 2022/03/27 12:38:23 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/doublylist.h"

t_DoublyListNode	*pop(t_DoublyList *pStack)
{
	t_DoublyListNode	*pop_node;
	t_DoublyListNode	*prev_node;
	t_DoublyListNode	*next_node;

	/*
		pop할떄 재할당 필요 없음, 연결만 해제시킨다.
	*/
	if (pStack == NULL || pStack->currentElementCount == 0)
		return (NULL);
	pop_node = getDLElement(pStack, 0);
	prev_node = pop_node->pLLink;
	next_node = pop_node->pRLink;
	pStack->headerNode = next_node;
	if (pStack->currentElementCount == 1)
	{
		pStack->headerNode = NULL;
		pStack->tailerNode = NULL;
	}
	prev_node->pRLink = next_node;
	next_node->pLLink = prev_node;
	pop_node->pLLink = NULL;
	pop_node->pRLink = NULL;
	pStack->currentElementCount--;
	return (pop_node);
}
