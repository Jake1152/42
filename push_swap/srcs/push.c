/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:36 by jim               #+#    #+#             */
/*   Updated: 2022/02/08 21:06:44 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	t_DoublyListNode	*pop_node;

	if (a_stack == NULL || b_stack == NULL)
		return ;
	pop_node = pop(b_stack);
	if (pop_node == NULL)
		return ;
	addDLElement(a_stack, a_stack->currentElementCount, pop_node);
}

void	push_b(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	t_DoublyListNode	*pop_node;

	if (a_stack == NULL || b_stack == NULL)
		return ;
	pop_node = pop(a_stack);
	if (pop_node == NULL)
		return ;
	addDLElement(b_stack, b_stack->currentElementCount, pop_node);
}
