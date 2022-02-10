/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:25 by jim               #+#    #+#             */
/*   Updated: 2022/02/10 21:05:34 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_DoublyList *stack, int print_flag)
{
	t_DoublyListNode	*midNode;
	t_DoublyListNode	*prevNode;
	t_DoublyListNode	*nextNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return ;
	midNode = getDLElement(stack, stack->currentElementCount - 2);
	if (midNode == NULL)
		return ;
	if (stack->currentElementCount == 2)
	{
		stack->headerNode = stack->tailerNode;
		stack->tailerNode = midNode;
		return ;
	}
	prevNode = midNode->pLLink;
	nextNode = midNode->pRLink;
	prevNode->pRLink = nextNode;
	nextNode->pLLink = prevNode;
	midNode->pLLink = nextNode;
	midNode->pRLink = nextNode->pRLink;
	nextNode->pRLink = midNode;
	stack->tailerNode = midNode;
	stack->headerNode->pLLink = midNode;
	swap_command_printer("sa", print_flag);
}

void	swap_b(t_DoublyList *stack, int print_flag)
{
	t_DoublyListNode	*midNode;
	t_DoublyListNode	*prevNode;
	t_DoublyListNode	*nextNode;

	if (stack == NULL || stack->currentElementCount < 2)
		return ;
	midNode = getDLElement(stack, stack->currentElementCount - 2);
	if (midNode == NULL)
		return ;
	if (stack->currentElementCount == 2)
	{
		stack->headerNode = stack->tailerNode;
		stack->tailerNode = midNode;
		return ;
	}
	prevNode = midNode->pLLink;
	nextNode = midNode->pRLink;
	prevNode->pRLink = nextNode;
	nextNode->pLLink = prevNode;
	midNode->pLLink = nextNode;
	midNode->pRLink = nextNode->pRLink;
	nextNode->pRLink = midNode;
	stack->tailerNode = midNode;
	stack->headerNode->pLLink = midNode;
	swap_command_printer("sb", print_flag);
}

void	swap_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	swap_a(a_stack, FALSE);
	swap_b(b_stack, FALSE);
	swap_command_printer("ss", TRUE);
}

void	swap_command_printer(char *command, int print_flag)
{
	if (print_flag == TRUE)
	{
		if (ft_strncmp("sa", command, 2) == 0)
			ft_putstr("sa\n");
		else if (ft_strncmp("sb", command, 2) == 0)
			ft_putstr("sb\n");
		else if (ft_strncmp("ss", command, 2) == 0)
			ft_putstr("ss\n");
	}
}
