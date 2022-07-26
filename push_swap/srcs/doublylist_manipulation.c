/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_manipulation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:44:11 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "doublylist.h"

t_doubly_list_node	*get_dl_element(t_doubly_list *pList, int position)
{
	t_doubly_list_node	*cur_doubly_list_node;

	if (pList == NULL || position > pList->current_element_count)
		return (NULL);
	if (position < 0)
		position = pList->current_element_count \
		+ (position % pList->current_element_count);
	cur_doubly_list_node = pList->header_node;
	if (position < pList->current_element_count / 2)
	{
		while (position > 0)
		{
			cur_doubly_list_node = cur_doubly_list_node->p_r_link;
			position--;
		}
	}
	else
	{
		while (pList->current_element_count - position > 0)
		{
			cur_doubly_list_node = cur_doubly_list_node->p_l_link;
			position++;
		}
	}
	return (cur_doubly_list_node);
}

int	add_dl_element(t_doubly_list *pList, int position, \
					t_doubly_list_node *new_node)
{
	t_doubly_list_node	*prev_node;

	if (pList == NULL || position < 0
		|| position > pList->current_element_count || new_node == NULL)
		return (FALSE);
	if (pList->current_element_count == 0)
	{
		new_node->p_l_link = new_node;
		new_node->p_r_link = new_node;
		pList->header_node = new_node;
		pList->tailer_node = new_node;
		return (pList->current_element_count++);
	}
	prev_node = get_dl_element(pList, position - 1);
	if (prev_node == NULL)
		return (FALSE);
	if (position == 0)
		pList->header_node = new_node;
	if (position == pList->current_element_count)
		pList->tailer_node = new_node;
	new_node->p_l_link = prev_node;
	new_node->p_r_link = prev_node->p_r_link;
	prev_node->p_r_link->p_l_link = new_node;
	prev_node->p_r_link = new_node;
	return (pList->current_element_count++);
}

int	remove_dl_element(t_doubly_list *pList, int position)
{
	t_doubly_list_node	*prev_doubly_list_node;
	t_doubly_list_node	*cur_doubly_list_node;

	if (pList == NULL)
		return (FALSE);
	if (position < 0 || pList->current_element_count <= position)
		return (FALSE);
	cur_doubly_list_node = get_dl_element(pList, position);
	if (cur_doubly_list_node == NULL)
		return (FALSE);
	prev_doubly_list_node = cur_doubly_list_node->p_l_link;
	if (position == 0)
		pList->header_node = cur_doubly_list_node->p_r_link;
	if (pList->current_element_count - 1 == position)
		pList->tailer_node = prev_doubly_list_node;
	if (pList->current_element_count == 1)
	{
		pList->header_node = NULL;
		pList->tailer_node = NULL;
	}
	prev_doubly_list_node->p_r_link = cur_doubly_list_node->p_r_link;
	cur_doubly_list_node->p_r_link->p_l_link = cur_doubly_list_node->p_l_link;
	free(cur_doubly_list_node);
	cur_doubly_list_node = NULL;
	return (pList->current_element_count--);
}
