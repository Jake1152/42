/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:36 by jim               #+#    #+#             */
/*   Updated: 2022/04/01 15:07:49 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort.h"
#include "doublylist.h"

void	push(t_DoublyList *from_stack, t_DoublyList *to_stack, \
			t_stack_type to_stack_type, int print_flag)
{
	t_DoublyListNode	*pop_node;

	if (from_stack == NULL || to_stack == NULL)
		return ;
	pop_node = pop(from_stack);
	if (pop_node == NULL)
		return ;
	addDLElement(to_stack, 0, pop_node);
	if (print_flag == TRUE && to_stack_type == A_STACK)
		ft_putstr("pa\n");
	else if (print_flag == TRUE && to_stack_type == B_STACK)
		ft_putstr("pb\n");
}
