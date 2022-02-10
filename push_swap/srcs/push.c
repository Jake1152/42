/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:36 by jim               #+#    #+#             */
/*   Updated: 2022/02/10 20:20:04 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	push_a(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	t_DoublyListNode	*pop_node;

	if (a_stack == NULL || b_stack == NULL)
		return ;
	pop_node = pop(b_stack);
	if (pop_node == NULL)
		return ;
	printf("a_stack->currentElementCount : %d\n", a_stack->currentElementCount);
	displayDoublyList(a_stack);
	addDLElement(a_stack, a_stack->currentElementCount, pop_node);
	ft_putstr("pa\n");
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
	ft_putstr("pb\n");
}
