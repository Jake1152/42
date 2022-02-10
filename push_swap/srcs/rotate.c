/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:19 by jim               #+#    #+#             */
/*   Updated: 2022/02/10 20:48:37 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_DoublyList *stack, int print_flag)
{
	t_DoublyListNode	*prevOfHeaderNode;

	if (stack == NULL || stack->currentElementCount <= 1)
		return (print_error());
	prevOfHeaderNode = stack->headerNode->pLLink;
	stack->tailerNode = stack->headerNode;
	stack->headerNode = prevOfHeaderNode;
	if (print_flag == TRUE)
		ft_putstr("ra\n");
}

void	rotate_b(t_DoublyList *stack, int print_flag)
{
	t_DoublyListNode	*prevOfHeaderNode;

	if (stack == NULL || stack->currentElementCount <= 1)
		return (print_error());
	prevOfHeaderNode = stack->headerNode->pLLink;
	stack->tailerNode = stack->headerNode;
	stack->headerNode = prevOfHeaderNode;
	if (print_flag == TRUE)
		ft_putstr("rb\n");
}

void	rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if (a_stack == NULL || b_stack == NULL)
		return ;
	rotate(a_stack, FALSE);
	rotate(b_stack, FALSE);
	ft_putstr("rr\n");
}
