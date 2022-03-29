/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:14:46 by jim               #+#    #+#             */
/*   Updated: 2022/03/29 16:54:35 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist_struct.h"
#include "sort_struct.h"

static long long	calculate_chunk_size(long long element_count)
{
	double		to_be_chunk_size;
	long long	x;

	x = element_count;
	to_be_chunk_size = 0.000000053 * x * x + 0.03 * x + 14.5;
	return ((long long)to_be_chunk_size);
}

void	init_pivot(t_DoublyList stack, t_pivot_info *pivot_info)
{
	pivot_info->chunk = calculate_chunk_size(stack.currentElementCount);
	pivot_info->pivot = 0;
}

t_max_data_info	find_max_data_info(t_DoublyList *stack)
{
	t_max_data_info		max_data_info;
	t_DoublyListNode	*cur_node;
	int					idx;
	int					node_position;

	cur_node = stack->headerNode;
	max_data_info.idx = cur_node->sorted_idx;
	max_data_info.bound = UPPER_BOUND;
	idx = 0;
	while (idx < stack->currentElementCount)
	{
		if (max_data_info.idx < cur_node->sorted_idx)
		{
			max_data_info.idx = cur_node->sorted_idx;
			node_position = idx;
		}
		idx++;
		cur_node = cur_node->pRLink;
	}
	if (node_position > stack->currentElementCount / 2)
		max_data_info.bound = LOWER_BOUND;
	return (max_data_info);
}
