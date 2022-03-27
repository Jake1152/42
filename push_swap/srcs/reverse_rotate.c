/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:14 by jim               #+#    #+#             */
/*   Updated: 2022/03/27 20:36:04 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/doublylist.h"

void	reverse_rotate(t_DoublyList *stack, int print_flag)
{
	t_DoublyListNode	*prevOfTailerNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return ;
	prevOfTailerNode = stack->tailerNode->pLLink;
	stack->headerNode = stack->tailerNode;
	stack->tailerNode = prevOfTailerNode;
}

void	reverse_rotate_a(t_DoublyList *stack, int print_flag)
{
	reverse_rotate(stack, print_flag);
	if (print_flag == TRUE)
		ft_putstr("rrb\n");
}

void	reverse_rotate_b(t_DoublyList *stack, int print_flag)
{
	reverse_rotate(stack, print_flag);
	if (print_flag == TRUE)
		ft_putstr("rrb\n");
}

void	reverse_rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	reverse_rotate_a(a_stack, FALSE);
	reverse_rotate_b(b_stack, FALSE);
	ft_putstr("rrr\n");
}
