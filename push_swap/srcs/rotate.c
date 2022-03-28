/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:19 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 12:44:34 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

int	rotate(t_DoublyList *stack)
{
	t_DoublyListNode	*prevOfHeaderNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return (FALSE);
	prevOfHeaderNode = stack->headerNode->pRLink;
	stack->tailerNode = stack->headerNode;
	stack->headerNode = prevOfHeaderNode;
	return (TRUE);
}

void	rotate_a(t_DoublyList *stack, int print_flag)
{
	int	ret_flat;

	ret_flat = rotate(stack);
	if (print_flag == TRUE && ret_flat == TRUE)
		ft_putstr("ra\n");
}

void	rotate_b(t_DoublyList *stack, int print_flag)
{
	int	ret_flat;

	ret_flat = rotate(stack);
	if (print_flag == TRUE && ret_flat == TRUE)
		ft_putstr("rb\n");
}

void	rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if ((a_stack == NULL || a_stack->currentElementCount < 2) && \
		(b_stack == NULL || b_stack->currentElementCount < 2))
		return ;
	rotate_a(a_stack, FALSE);
	rotate_b(b_stack, FALSE);
	ft_putstr("rr\n");
}
