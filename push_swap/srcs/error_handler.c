/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:25:22 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:44:13 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "doublylist.h"
#include "error_handle.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	delete_both_stack(t_doubly_list *a_stack, t_doubly_list *b_stack)
{
	delete_doubly_list(&a_stack);
	delete_doubly_list(&b_stack);
	print_error();
}

void	delete_and_print_error(t_doubly_list *pList)
{
	delete_doubly_list(&pList);
	print_error();
}

int	check_duplicate_value(t_doubly_list *pList)
{
	int					i;
	int					j;
	t_doubly_list_node	*i_node;
	t_doubly_list_node	*j_node;

	if (pList == NULL)
		print_error();
	i = 1;
	i_node = pList->header_node;
	while (i < pList->current_element_count)
	{
		j_node = i_node->p_r_link;
		j = i;
		while (j < pList->current_element_count)
		{
			if (i_node->data == j_node->data)
				return (FALSE);
			j_node = j_node->p_r_link;
			j++;
		}
		i_node = i_node->p_r_link;
		i++;
	}
	return (TRUE);
}
