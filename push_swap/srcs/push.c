/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:36 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:42:59 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort.h"
#include "doublylist.h"

void	push(t_doubly_list *from_stack, t_doubly_list *to_stack, \
			t_stack_type to_stack_type, int print_flag)
{
	t_doubly_list_node	*pop_node;

	if (from_stack == NULL || to_stack == NULL)
		return ;
	pop_node = pop(from_stack);
	if (pop_node == NULL)
		return ;
	add_dl_element(to_stack, 0, pop_node);
	if (print_flag == TRUE && to_stack_type == A_STACK)
		ft_putstr("pa\n");
	else if (print_flag == TRUE && to_stack_type == B_STACK)
		ft_putstr("pb\n");
}
