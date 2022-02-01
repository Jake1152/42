/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:36 by jim               #+#    #+#             */
/*   Updated: 2022/01/25 13:32:41 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	/*
		stack b가 비었는지 확인
		비었으면 Error\n 출력
	*/
   t_DoublyListNode *pop_node;

	if (a_stack == NULL || b_stack == NULL)
		return (print_error());
	pop_node = pop(b_stack);
	if (pop_node == NULL)
		return (print_error());
	addDLElement(a_stack, a_stack->currentElementCount, pop_node);
}

void	push_b(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	t_DoublyListNode *pop_node;

	
	if (a_stack == NULL || b_stack == NULL)
		return (print_error());
	pop_node = pop(a_stack);
	if (pop_node == NULL)
		return (print_error());
	addDLElement(b_stack, b_stack->currentElementCount, pop_node);
}

