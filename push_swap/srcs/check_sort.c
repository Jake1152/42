/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:11:24 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:25:20 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "doublylist_struct.h"

int	check_sort_asc(t_doubly_list *stack)
{
	t_doubly_list_node	*current_node;
	int					prev_data;

	if (stack == NULL || stack->current_element_count <= 0)
		return (FALSE);
	current_node = stack->header_node;
	prev_data = current_node->data;
	current_node = current_node->p_r_link;
	while (current_node != stack->header_node)
	{
		if (prev_data > current_node->data)
			return (FALSE);
		prev_data = current_node->data;
		current_node = current_node->p_r_link;
	}
	return (TRUE);
}
