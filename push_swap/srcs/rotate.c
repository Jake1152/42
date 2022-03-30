/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:19 by jim               #+#    #+#             */
/*   Updated: 2022/03/30 13:00:10 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort_struct.h"

void	rotate(t_DoublyList *stack, t_stack_type stack_type, int print_flag)
{
	t_DoublyListNode	*prevOfHeaderNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return ;
	prevOfHeaderNode = stack->headerNode->pRLink;
	stack->tailerNode = stack->headerNode;
	stack->headerNode = prevOfHeaderNode;
	if (print_flag == TRUE && stack_type == A_STACK)
		ft_putstr("ra\n");
	else if (print_flag == TRUE && stack_type == B_STACK)
		ft_putstr("rb\n");
}

void	rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if ((a_stack == NULL || a_stack->currentElementCount < 2) && \
		(b_stack == NULL || b_stack->currentElementCount < 2))
		return ;
	rotate(a_stack, A_STACK, FALSE);
	rotate(b_stack, B_STACK, FALSE);
	ft_putstr("rr\n");
}
