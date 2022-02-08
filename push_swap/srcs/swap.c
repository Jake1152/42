/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:25 by jim               #+#    #+#             */
/*   Updated: 2022/01/25 13:33:28 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_top(t_DoublyList *pStack)
{
	t_DoublyListNode	*midNode;
	t_DoublyListNode	*prevNode;
	t_DoublyListNode	*nextNode;

	if (pStack == NULL || pStack->currentElementCount < 2)
		return ;
	midNode = getDLElement(pStack, pStack->currentElementCount - 2);
	if (midNode == NULL)
		return ;
	if (pStack->currentElementCount == 2)
	{
		pStack->headerNode = pStack->tailerNode;
		pStack->tailerNode = midNode;
		return ;
	}
	prevNode = midNode->pLLink;
	nextNode = midNode->pRLink;
	/* re-connected */
	prevNode->pRLink = nextNode;
	nextNode->pLLink = prevNode;
	midNode->pLLink = nextNode;
	midNode->pRLink = nextNode->pRLink;
	nextNode->pRLink = midNode;
	if (prevNode == pStack->headerNode)
		prevNode->pLLink = midNode;
}

void	swap_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	// 아무것도 안하면 카운팅하지 말아야한다. 즉 한개라도 동작하지 않으면 명령어 출력하지 않는다.
	// void로 해놓았지만 구현할 정렬알고리즘 방식에 따라서 다르게 가야한다.
	// 아무동작도 안한 경우를 return 받아서 쓸일이 있는지
	swap(a_stack);
	swap(b_stack);
}
