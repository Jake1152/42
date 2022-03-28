/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:32 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 22:36:46 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "sort_struct.h"

void	a_to_b(t_DoublyList *a_stack, t_DoublyList *b_stack, \
				t_pivot_info pivot_info)
{
	t_DoublyListNode	*top_node;

	while (a_stack->currentElementCount)
	{
		top_node = a_stack->headerNode;
		if (top_node->data <= pivot_info.pivot)
		{
			push_b(a_stack, b_stack);
			pivot_info.pivot++;
		}
		else if (top_node->data > pivot_info.pivot && \
				top_node->data <= pivot_info.pivot + pivot_info.chunk)
		{
			push_b(a_stack, b_stack);
			rotate_b(b_stack, TRUE);
			pivot_info.pivot++;
		}
		else if (top_node->data > pivot_info.pivot + pivot_info.chunk)
		{
			rotate_a(a_stack, TRUE);
			pivot_info.pivot++;

		}
	}
}

void	b_to_a(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	t_max_data_info		max_data_info;

	while (b_stack->currentElementCount)
	{
		max_data_info = find_max_data_info(b_stack);
		if (max_data_info.bound == UPPER_BOUND)
			while (max_data_info.data != b_stack->headerNode->data)
				rotate_b(b_stack, TRUE);
		else
			while (max_data_info.data != b_stack->headerNode->data)
				reverse_rotate_b(b_stack, TRUE);
		push_a(a_stack, b_stack);
	}
}
