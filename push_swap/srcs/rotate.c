/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:19 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:46:27 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort_struct.h"

void	rotate(t_doubly_list *stack, t_stack_type stack_type, int print_flag)
{
	t_doubly_list_node	*prev_of_header_node;

	if (stack == NULL || stack->current_element_count < 2)
		return ;
	prev_of_header_node = stack->header_node->p_r_link;
	stack->tailer_node = stack->header_node;
	stack->header_node = prev_of_header_node;
	if (print_flag == TRUE && stack_type == A_STACK)
		ft_putstr("ra\n");
	else if (print_flag == TRUE && stack_type == B_STACK)
		ft_putstr("rb\n");
}

void	rotate_both(t_doubly_list *a_stack, t_doubly_list *b_stack, \
					int print_flag)
{
	if ((a_stack == NULL || a_stack->current_element_count < 2) && \
		(b_stack == NULL || b_stack->current_element_count < 2))
		return ;
	rotate(a_stack, A_STACK, FALSE);
	rotate(b_stack, B_STACK, FALSE);
	if (print_flag == TRUE)
		ft_putstr("rr\n");
}
