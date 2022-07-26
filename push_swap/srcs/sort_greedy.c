/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_greedy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:03:32 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:24:20 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "sort_struct.h"

void	a_to_b(t_doubly_list *a_stack, t_doubly_list *b_stack, \
				t_pivot_info pivot_info)
{
	t_doubly_list_node	*top_node;

	while (a_stack->current_element_count)
	{
		top_node = a_stack->header_node;
		if (top_node->sorted_idx <= pivot_info.pivot)
		{
			push(a_stack, b_stack, B_STACK, TRUE);
			pivot_info.pivot++;
		}
		else if (top_node->sorted_idx > pivot_info.pivot && \
				top_node->sorted_idx <= pivot_info.pivot + pivot_info.chunk)
		{
			push(a_stack, b_stack, B_STACK, TRUE);
			rotate(b_stack, B_STACK, TRUE);
			pivot_info.pivot++;
		}
		else if (top_node->sorted_idx > pivot_info.pivot + pivot_info.chunk)
			rotate(a_stack, A_STACK, TRUE);
	}
}

void	b_to_a(t_doubly_list *a_stack, t_doubly_list *b_stack)
{
	t_max_data_info		max_data_info;

	while (b_stack->current_element_count)
	{
		max_data_info = find_max_data_info(b_stack);
		if (max_data_info.bound == UPPER_BOUND)
			while (max_data_info.idx != b_stack->header_node->sorted_idx)
				rotate(b_stack, B_STACK, TRUE);
		else
			while (max_data_info.idx != b_stack->header_node->sorted_idx)
				reverse_rotate(b_stack, B_STACK, TRUE);
		push(b_stack, a_stack, A_STACK, TRUE);
	}
}
