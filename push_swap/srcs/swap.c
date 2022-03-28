/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:25 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 13:00:35 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "push_swap.h"
#include "doublylist.h"

void	swap(t_DoublyList *stack, int print_flag, char *swap_flag)
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
		return (swap_command_printer(swap_flag, print_flag));
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
	swap_command_printer(swap_flag, print_flag);
}

void	swap_a(t_DoublyList *stack, int print_flag)
{
	swap(stack, print_flag, "sa");
}

void	swap_b(t_DoublyList *stack, int print_flag)
{
	swap(stack, print_flag, "sb");
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
