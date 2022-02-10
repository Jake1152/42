/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:14 by jim               #+#    #+#             */
/*   Updated: 2022/02/10 20:45:46 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_DoublyList *stack, int print_flag)
{
	t_DoublyListNode	*prevOfTailNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return (print_error());
	prevOfTailNode = stack->tailerNode->pLLink;
	stack->headerNode = stack->tailerNode;
	stack->tailerNode = prevOfTailNode;
	if (print_flag == TRUE)
		ft_putstr("rrb\n");
}

void	reverse_rotate_b(t_DoublyList *stack, int print_flag)
{
	t_DoublyListNode	*prevOfTailNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return (print_error());
	prevOfTailNode = stack->tailerNode->pLLink;
	stack->headerNode = stack->tailerNode;
	stack->tailerNode = prevOfTailNode;
	if (print_flag == TRUE)
		ft_putstr("rrb\n");
}

void	reverse_rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if (a_stack == NULL || b_stack == NULL)
		return ;
	reverse_rotate(a_stack, FALSE);
	reverse_rotate(b_stack, FALSE);
	ft_putstr("rrr\n");
}
