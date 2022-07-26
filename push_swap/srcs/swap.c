/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:25 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:45:13 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort.h"
#include "doublylist.h"

void	swap(t_doubly_list *stack, t_stack_type stack_type, int print_flag)
{
	t_doubly_list_node	*mid_node;
	t_doubly_list_node	*prev_node;
	t_doubly_list_node	*next_node;

	if (stack == NULL || stack->current_element_count < 2)
		return ;
	mid_node = get_dl_element(stack, 1);
	if (mid_node == NULL)
		return ;
	if (stack->current_element_count == 2)
	{
		stack->header_node = mid_node;
		stack->tailer_node = stack->header_node;
		return (swap_command_printer(stack_type, print_flag));
	}
	prev_node = mid_node->p_l_link;
	next_node = mid_node->p_r_link;
	prev_node->p_r_link = next_node;
	next_node->p_l_link = prev_node;
	mid_node->p_r_link = prev_node;
	mid_node->p_l_link = stack->tailer_node;
	prev_node->p_l_link = mid_node;
	stack->tailer_node->p_r_link = mid_node;
	stack->header_node = mid_node;
	swap_command_printer(stack_type, print_flag);
}

void	swap_both(t_doubly_list *a_stack, \
					t_doubly_list *b_stack, int print_flag)
{
	swap(a_stack, FALSE, A_STACK);
	swap(b_stack, FALSE, B_STACK);
	swap_command_printer(BOTH_STACK, print_flag);
}

void	swap_command_printer(t_stack_type stack_type, int print_flag)
{
	if (print_flag == TRUE)
	{
		if (stack_type == A_STACK)
			ft_putstr("sa\n");
		else if (stack_type == B_STACK)
			ft_putstr("sb\n");
		else if (stack_type == BOTH_STACK)
			ft_putstr("ss\n");
	}
}
