/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:25 by jim               #+#    #+#             */
/*   Updated: 2022/04/01 15:03:26 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "sort.h"
#include "doublylist.h"

void	swap(t_DoublyList *stack, t_stack_type stack_type, int print_flag)
{
	t_DoublyListNode	*midNode;
	t_DoublyListNode	*prevNode;
	t_DoublyListNode	*nextNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return ;
	midNode = getDLElement(stack, 1);
	if (midNode == NULL)
		return ;
	if (stack->currentElementCount == 2)
	{
		stack->headerNode = midNode;
		stack->tailerNode = stack->headerNode;
		return (swap_command_printer(stack_type, print_flag));
	}
	prevNode = midNode->pLLink;
	nextNode = midNode->pRLink;
	prevNode->pRLink = nextNode;
	nextNode->pLLink = prevNode;
	midNode->pRLink = prevNode;
	midNode->pLLink = stack->tailerNode;
	prevNode->pLLink = midNode;
	stack->tailerNode->pRLink = midNode;
	stack->headerNode = midNode;
	swap_command_printer(stack_type, print_flag);
}

void	swap_both(t_DoublyList *a_stack, t_DoublyList *b_stack, int print_flag)
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
