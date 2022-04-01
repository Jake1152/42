/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:25:22 by jim               #+#    #+#             */
/*   Updated: 2022/04/01 11:31:56 by jim              ###   ########seoul.kr  */
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

void	delete_both_stack(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	deleteDoublyList(&a_stack);
	deleteDoublyList(&b_stack);
	print_error();
}

void	delete_and_print_error(t_DoublyList *pList)
{
	deleteDoublyList(&pList);
	print_error();
}

int	check_duplicate_value(t_DoublyList *pList)
{
	int					i;
	int					j;
	t_DoublyListNode	*i_node;
	t_DoublyListNode	*j_node;

	if (pList == NULL)
		print_error();
	i = 1;
	i_node = pList->headerNode;
	while (i < pList->currentElementCount)
	{
		j_node = i_node->pRLink;
		j = i;
		while (j < pList->currentElementCount)
		{
			if (i_node->data == j_node->data)
				return (FALSE);
			j_node = j_node->pRLink;
			j++;
		}
		i_node = i_node->pRLink;
		i++;
	}
	return (TRUE);
}
