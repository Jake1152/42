/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:14:46 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 22:58:59 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist_struct.h"
#include "sort_struct.h"

void	init_pivot(t_DoublyList stack, t_pivot_info *pivot_info)
{
	if (stack.currentElementCount <= 10)
		pivot_info->chunk = 0;
	else if (stack.currentElementCount <= 30)
		pivot_info->chunk = 3;
	else if (stack.currentElementCount <= 50)
		pivot_info->chunk = 5;
	else if (stack.currentElementCount <= 80)
		pivot_info->chunk = 8;
	else if (stack.currentElementCount <= 100)
		pivot_info->chunk = 15;
	else if (stack.currentElementCount <= 500)
		pivot_info->chunk = 30;
	else if (stack.currentElementCount <= 1000)
		pivot_info->chunk = 45;
	else if (stack.currentElementCount <= 2000)
		pivot_info->chunk = 65;
	else if (stack.currentElementCount <= 5000)
		pivot_info->chunk = 150;
	else
		pivot_info->chunk = 250;
	pivot_info->pivot = 0;
}

t_max_data_info	find_max_data_info(t_DoublyList *b_stack)
{
	t_max_data_info		max_data_info;
	t_DoublyListNode	*cur_node;
	int					node_positon;

	cur_node = b_stack->headerNode;
	max_data_info.data = cur_node->data;
	max_data_info.bound = UPPER_BOUND;
	node_positon = 0;
	while (cur_node != b_stack->tailerNode)
	{
		if (TRUE)
			;
		node_positon++;
		cur_node = cur_node->pRLink;
	}
	return (max_data_info);
}
