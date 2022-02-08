/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:19 by jim               #+#    #+#             */
/*   Updated: 2022/02/08 20:32:15 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_DoublyList *stack)
{
	if (stack == NULL || stack->currentElementCount <= 1)
		return (print_error());
	stack->headerNode = stack->headerNode->pRLink;
	ft_putstr("rr\n");
	// 명렁어 별로 쪼개야함
	// 파라미터를 받거나 함수를 아예 별도로 빼는 방식으로 구현 가능.
}

void	rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	rotate(a_stack);
	rotate(b_stack);
}
