/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 21:11:45 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:42:24 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "doublylist.h"

t_doubly_list_node	*pop(t_doubly_list *pStack)
{
	t_doubly_list_node	*pop_node;
	t_doubly_list_node	*prev_node;
	t_doubly_list_node	*next_node;

	if (pStack == NULL || pStack->current_element_count == 0)
		return (NULL);
	pop_node = get_dl_element(pStack, 0);
	prev_node = pop_node->p_l_link;
	next_node = pop_node->p_r_link;
	pStack->header_node = next_node;
	if (pStack->current_element_count == 1)
	{
		pStack->header_node = NULL;
		pStack->tailer_node = NULL;
	}
	prev_node->p_r_link = next_node;
	next_node->p_l_link = prev_node;
	pop_node->p_l_link = NULL;
	pop_node->p_r_link = NULL;
	pStack->current_element_count--;
	return (pop_node);
}
