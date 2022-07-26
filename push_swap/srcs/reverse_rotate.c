/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:14 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:45:51 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort_struct.h"

void	reverse_rotate(t_doubly_list *stack, t_stack_type stack_type, \
						int print_flag)
{
	t_doubly_list_node	*prev_of_tailer_node;

	if (stack == NULL || stack->current_element_count < 2)
		return ;
	prev_of_tailer_node = stack->tailer_node->p_l_link;
	stack->header_node = stack->tailer_node;
	stack->tailer_node = prev_of_tailer_node;
	if (print_flag == TRUE && stack_type == A_STACK)
		ft_putstr("rra\n");
	else if (print_flag == TRUE && stack_type == B_STACK)
		ft_putstr("rrb\n");
}

void	reverse_rotate_both(t_doubly_list *a_stack, t_doubly_list *b_stack, \
							int print_flag)
{
	if ((a_stack == NULL || a_stack->current_element_count < 2) && \
		(b_stack == NULL || b_stack->current_element_count < 2))
		return ;
	reverse_rotate(a_stack, A_STACK, FALSE);
	reverse_rotate(b_stack, B_STACK, FALSE);
	if (print_flag == TRUE)
		ft_putstr("rrr\n");
}
