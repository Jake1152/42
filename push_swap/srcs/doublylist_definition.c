/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_definition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:00 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:42:00 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "doublylist.h"

t_doubly_list	*create_doubly_list(void)
{
	t_doubly_list	*new_doubly_list;

	new_doubly_list = (t_doubly_list *)malloc(sizeof(t_doubly_list));
	if (new_doubly_list == NULL)
		return (NULL);
	new_doubly_list->header_node = (t_doubly_list_node *) NULL;
	new_doubly_list->tailer_node = (t_doubly_list_node *) NULL;
	new_doubly_list->current_element_count = 0;
	return (new_doubly_list);
}

t_doubly_list_node	*create_doubly_list_node(int data)
{
	t_doubly_list_node	*new_doubly_list_node;

	new_doubly_list_node = \
					(t_doubly_list_node *)malloc(sizeof(t_doubly_list_node));
	if (new_doubly_list_node == NULL)
		return (NULL);
	new_doubly_list_node->p_r_link = (t_doubly_list_node *) NULL;
	new_doubly_list_node->p_l_link = (t_doubly_list_node *) NULL;
	new_doubly_list_node->data = data;
	return (new_doubly_list_node);
}

int	clear_doubly_list(t_doubly_list *pList)
{
	if (pList == NULL)
		return (FALSE);
	while (pList->current_element_count > 0)
		remove_dl_element(pList, 0);
	return (TRUE);
}

void	delete_doubly_list(t_doubly_list **pList)
{
	if (pList == NULL)
		return ;
	if (clear_doubly_list(*pList) == FALSE)
		return ;
	free(*pList);
	*pList = NULL;
}
