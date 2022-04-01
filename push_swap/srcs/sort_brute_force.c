/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_brute_force.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:52:35 by jim               #+#    #+#             */
/*   Updated: 2022/04/01 15:08:53 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sort_struct.h"
#include "sort.h"
#include "doublylist_struct.h"
#include "push_swap.h"
#include "utils.h"
#include "error_handle.h"

static void	find_min_max_value(t_DoublyList *stack, \
								t_min_max_info *min_max_info)
{
	t_DoublyListNode	*cur_node;
	int					cnt;

	cur_node = stack->headerNode;
	min_max_info->max = cur_node->data;
	min_max_info->min = cur_node->data;
	cur_node = cur_node->pRLink;
	cnt = 1;
	while (cnt < stack->currentElementCount)
	{
		if (min_max_info->max < cur_node->data)
			min_max_info->max = cur_node->data;
		if (min_max_info->min > cur_node->data)
			min_max_info->min = cur_node->data;
		cur_node = cur_node->pRLink;
		cnt++;
	}
}

void	sort_brute_force(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if (a_stack == NULL || b_stack == NULL)
		delete_both_stack(a_stack, b_stack);
	if (a_stack->currentElementCount == 2)
		swap(a_stack, A_STACK, TRUE);
	else if (a_stack->currentElementCount == 3)
		sort_3things(a_stack, A_STACK);
	else if (a_stack->currentElementCount == 4 || \
			a_stack->currentElementCount == 5)
		sort_4_5_things(a_stack, b_stack);
}

void	sort_3things_other_part(t_DoublyList *stack, t_stack_type stack_type, \
							int mid_value)
{
	t_DoublyListNode	*top_node;
	int					top_position_data;
	int					mid_position_data;
	int					bottom_position_data;

	top_node = stack->headerNode;
	top_position_data = stack->headerNode->data;
	mid_position_data = stack->headerNode->pRLink->data;
	bottom_position_data = stack->headerNode->pRLink->pRLink->data;
	if ((mid_value == mid_position_data) && \
			(mid_value > bottom_position_data))
	{
		swap(stack, stack_type, TRUE);
		reverse_rotate(stack, stack_type, TRUE);
	}
	else if ((mid_value == bottom_position_data) && \
			(mid_value > mid_position_data))
		rotate(stack, stack_type, TRUE);
}

void	sort_3things(t_DoublyList *stack, t_stack_type stack_type)
{
	t_DoublyListNode	*top_node;
	int					top_position_data;
	int					mid_position_data;
	int					bottom_position_data;
	int					mid_value;

	top_node = stack->headerNode;
	top_position_data = stack->headerNode->data;
	mid_position_data = stack->headerNode->pRLink->data;
	bottom_position_data = stack->headerNode->pRLink->pRLink->data;
	mid_value = find_mid_value_when_3things(stack);
	if ((mid_value == bottom_position_data) && (mid_value > top_position_data))
	{
		reverse_rotate(stack, stack_type, TRUE);
		swap(stack, stack_type, TRUE);
	}
	else if ((mid_value == top_position_data) && \
			 (mid_value > bottom_position_data))
		reverse_rotate(stack, stack_type, TRUE);
	else if ((mid_value == top_position_data) && \
			(mid_value > mid_position_data))
		swap(stack, stack_type, TRUE);
	else
		sort_3things_other_part(stack, stack_type, mid_value);
}

int	sort_4_5_things(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	t_min_max_info		min_max_info;

	find_min_max_value(a_stack, &min_max_info);
	while (a_stack->currentElementCount > 3)
	{
		if (a_stack->headerNode->data == min_max_info.max || \
			a_stack->headerNode->data == min_max_info.min)
			push(a_stack, b_stack, B_STACK, TRUE);
		else
			rotate(a_stack, A_STACK, TRUE);
	}
	sort_3things(a_stack, A_STACK);
	while (b_stack->currentElementCount > 0)
	{
		push(b_stack, a_stack, A_STACK, TRUE);
		if (a_stack->headerNode->data == min_max_info.max)
			rotate(a_stack, A_STACK, TRUE);
	}
	return (TRUE);
}
