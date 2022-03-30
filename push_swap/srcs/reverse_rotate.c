/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:14 by jim               #+#    #+#             */
/*   Updated: 2022/03/30 13:00:41 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort_struct.h"

void	reverse_rotate(t_DoublyList *stack, t_stack_type stack_type, \
						int print_flag)
{
	t_DoublyListNode	*prevOfTailerNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return ;
	prevOfTailerNode = stack->tailerNode->pLLink;
	stack->headerNode = stack->tailerNode;
	stack->tailerNode = prevOfTailerNode;
	if (print_flag == TRUE && stack_type == A_STACK)
		ft_putstr("rra\n");
	else if (print_flag == TRUE && stack_type == B_STACK)
		ft_putstr("rrb\n");
	else
		ft_putstr("unexpected case in reverse rotate.\n");
}

void	reverse_rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if ((a_stack == NULL || a_stack->currentElementCount < 2) && \
		(b_stack == NULL || b_stack->currentElementCount < 2))
		return ;
	reverse_rotate(a_stack, A_STACK, FALSE);
	reverse_rotate(b_stack, B_STACK, FALSE);
	ft_putstr("rrr\n");
}
