/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:14 by jim               #+#    #+#             */
/*   Updated: 2022/03/29 12:06:31 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"

int	reverse_rotate(t_DoublyList *stack)
{
	t_DoublyListNode	*prevOfTailerNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return (FALSE);
	prevOfTailerNode = stack->tailerNode->pLLink;
	stack->headerNode = stack->tailerNode;
	stack->tailerNode = prevOfTailerNode;
	return (TRUE);
}

void	reverse_rotate_a(t_DoublyList *stack, int print_flag)
{
	int	ret_flat;

	ret_flat = reverse_rotate(stack);
	if (print_flag == TRUE && ret_flat == TRUE)
		ft_putstr("rrb\n");
}

void	reverse_rotate_b(t_DoublyList *stack, int print_flag)
{
	int	ret_flat;

	ret_flat = reverse_rotate(stack);
	if (print_flag == TRUE && ret_flat == TRUE)
		ft_putstr("rrb\n");
}

void	reverse_rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if ((a_stack == NULL || a_stack->currentElementCount < 2) && \
		(b_stack == NULL || b_stack->currentElementCount < 2))
		return ;
	reverse_rotate_a(a_stack, FALSE);
	reverse_rotate_b(b_stack, FALSE);
	ft_putstr("rrr\n");
}
