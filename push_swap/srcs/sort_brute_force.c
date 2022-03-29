/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_brute_force.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:52:35 by jim               #+#    #+#             */
/*   Updated: 2022/03/29 22:08:09 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "sort_struct.h"
#include "doublylist_struct.h"
#include "push_swap.h"

int	sort_brute_force(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	if (a_stack->currentElementCount == 2)
		sort_2things(a_stack, A_STACK);
	else if (a_stack->currentElementCount == 3)
		sort_3things(a_stack, A_STACK);
}

int	sort_2things(t_DoublyList *stack, t_stack_type stack_type)
{
	if (stack_type == A_STACK)
		swap_a(stack, TRUE);
	else if (stack_type == B_STACK)
		swap_b(stack, TRUE);
}

int	find_mid_position(t_DoublyList *stack)
{
	t_DoublyListNode	*top_node;
	int					top;
	int					mid;
	int					bottom;

	if (stack->currentElementCount != 3)
		return (FALSE);
	top_node = stack->headerNode;
	top = top_node->data;
	mid = top_node->pRLink->data;
	bottom = top_node->pRLink->pRLink->data;
	if ((top > mid || top > bottom) && (top < mid || top < bottom))
		return (top);
	else if ((mid > top || mid > bottom) && (mid < top || mid < bottom))
		return (mid);
	else if ((bottom > mid || bottom > top) && (bottom < mid || bottom < top))
		return (bottom);
}

int	sort_3things(t_DoublyList *a_stack, t_DoublyList *b_stack, \
				t_stack_type stack_type)
{
	int	mid_position;

	if (stack_type == A_STACK)
	{
		mid_position = find_mid_position(a_stack);
		swap_a(a_stack, TRUE);
	}
	else if (stack_type == B_STACK)
	{
		mid_position = find_mid_position(b_stack);
		swap_b(b_stack, TRUE);
	}

}

// 4,5개는 한번에 할 수 있는지 고려 필요.
int	sort_4things(t_DoublyList *a_stack, t_DoublyList *b_stack, \
				t_stack_type stack_type)
{
	;
}

int	sort_5things(t_DoublyList *a_stack, t_DoublyList *b_stack, \
				t_stack_type stack_type)
{
	;
}
