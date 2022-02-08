/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:25:22 by jim               #+#    #+#             */
/*   Updated: 2022/02/06 20:41:49 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	ft_putstr("Error\n");
	exit(EXIT_FAILURE);
}

void	delete_and_print_error(t_DoublyList *pList)
{
	deleteDoublyList(&pList);
	if (pList == NULL)
		ft_putstr("pList is NULL\n");
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
