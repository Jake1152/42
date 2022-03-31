/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:11:24 by jim               #+#    #+#             */
/*   Updated: 2022/03/31 11:50:30 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "doublylist_struct.h"

int	check_sort_ASC(t_DoublyList *stack)
{
	t_DoublyListNode	*currentNode;
	int					prevData;

	if (stack == NULL || stack->currentElementCount <= 0)
		return (FALSE);
	currentNode = stack->headerNode;
	prevData = currentNode->data;
	currentNode = currentNode->pRLink;
	while (currentNode != stack->headerNode)
	{
		if (prevData > currentNode->data)
			return (FALSE);
		prevData = currentNode->data;
		currentNode = currentNode->pRLink;
	}
	return (TRUE);
}
