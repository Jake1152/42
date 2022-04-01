/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:14 by jim               #+#    #+#             */
/*   Updated: 2022/04/01 15:06:14 by jim              ###   ########seoul.kr  */
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
}

void	reverse_rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack, \
							int print_flag)
{
	if ((a_stack == NULL || a_stack->currentElementCount < 2) && \
		(b_stack == NULL || b_stack->currentElementCount < 2))
		return ;
	reverse_rotate(a_stack, A_STACK, FALSE);
	reverse_rotate(b_stack, B_STACK, FALSE);
	if (print_flag == TRUE)
		ft_putstr("rrr\n");
}
