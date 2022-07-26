/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:14:46 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:24:20 by jim              ###   ########seoul.kr  */
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

int	find_mid_value_when_3things(t_doubly_list *stack)
{
	t_doubly_list_node	*top_node;
	int					top;
	int					mid;
	int					bottom;

	top_node = stack->header_node;
	top = top_node->data;
	mid = top_node->p_r_link->data;
	bottom = top_node->p_r_link->p_r_link->data;
	if ((top > mid || top > bottom) && (top < mid || top < bottom))
		return (top);
	else if ((mid > top || mid > bottom) && (mid < top || mid < bottom))
		return (mid);
	else if ((bottom > mid || bottom > top) && (bottom < mid || bottom < top))
		return (bottom);
	return (FALSE);
}

void	init_pivot(t_doubly_list stack, t_pivot_info *pivot_info)
{
	pivot_info->chunk = calculate_chunk_size(stack.current_element_count);
	pivot_info->pivot = 0;
}

t_max_data_info	find_max_data_info(t_doubly_list *stack)
{
	t_max_data_info		max_data_info;
	t_doubly_list_node	*cur_node;
	int					idx;
	int					node_position;

	cur_node = stack->header_node;
	max_data_info.idx = cur_node->sorted_idx;
	max_data_info.bound = UPPER_BOUND;
	idx = 0;
	while (idx < stack->current_element_count)
	{
		if (max_data_info.idx < cur_node->sorted_idx)
		{
			max_data_info.idx = cur_node->sorted_idx;
			node_position = idx;
		}
		idx++;
		cur_node = cur_node->p_r_link;
	}
	if (node_position > stack->current_element_count / 2)
		max_data_info.bound = LOWER_BOUND;
	return (max_data_info);
}
