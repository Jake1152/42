/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_brute_force.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:52:35 by jim               #+#    #+#             */
/*   Updated: 2022/03/30 17:26:38 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sort_struct.h"
#include "sort.h"
#include "doublylist_struct.h"
#include "push_swap.h"
#include "utils.h"

void	sort_brute_force(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if (a_stack->currentElementCount == 2)
		sort_2things(a_stack, A_STACK);
	else if (a_stack->currentElementCount == 3)
		sort_3things(a_stack, A_STACK);
	else if (a_stack->currentElementCount == 4 || \
			a_stack->currentElementCount == 5)
		sort_
}

void	sort_2things(t_DoublyList *stack, t_stack_type stack_type)
{
	swap(stack, stack_type, TRUE);
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
	else
	{
		ft_putstr("There are unexpected case in sort 3things.\n");
		print_error();
	}
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
