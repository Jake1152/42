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

#include "push_swap.h"

void	swap_top(t_DoublyList *stack)
{
	t_DoublyListNode	*mid_node;
	t_DoublyListNode	*prev_node;
	t_DoublyListNode	*next_node;

	if (stack == NULL || stack->currentElementCount <= 1)
		return (print_error());
	mid_node = getDLElement(stack, stack->currentElementCount-2);
	prev_node = mid_node->pLLink;
	next_node = mid_node->pRLink;
	/* re-connected */
	prev_node->pRLink = next_node;
	next_node->pLLink = prev_node;
	mid_node->pLLink = next_node;
	mid_node->pRLink = next_node->pRLink;
	next_node->pRLink = mid_node;
}

void	swap_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{	
	swap(a_stack);
	swap(b_stack);
}
