/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:11:45 by jim               #+#    #+#             */
/*   Updated: 2022/02/05 21:12:16 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_DoublyListNode	*pop(t_DoublyList *stack)
{
	t_DoublyListNode	*tmp_node;
	t_DoublyListNode	*pop_node;
	int					remove_return_value;

	if (stack == NULL || stack->currentElementCount == 0)
		return (NULL);
	tmp_node = getDLElement(stack, stack->currentElementCount);
	if (tmp_node == NULL)
		return (NULL);
	pop_node = createDoublyListNode(tmp_node->data);
	if (tmp_node == NULL)
		return (NULL);
	remove_return_value = removeDLElement(stack, \
											stack->currentElementCount - 1);
	if (remove_return_value == FALSE)
	{
		free(pop_node);
		pop_node = NULL;
		return (NULL);
	}
	return (pop_node);
}
