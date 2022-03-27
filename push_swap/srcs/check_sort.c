/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:11:24 by jim               #+#    #+#             */
/*   Updated: 2022/03/27 16:17:42 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/doublylist.h"

int	check_sort_DESC(t_DoublyList *stack)
{
	/*
		top에서 bottom을 보았을때 기준으로 생각한다.
		밑으로 갈수록 숫자가 작아져야한다.
	*/
	t_DoublyListNode	*currentNode;
	int					prevData;

	if (stack == NULL || stack->currentElementCount <= 0)
		return (FALSE);
	currentNode = stack->headerNode;
	prevData = currentNode->data;
	currentNode = currentNode->pRLink;
	while (currentNode != stack->headerNode)
	{
		if (prevData < currentNode->data)
			return (FALSE);
		prevData = currentNode->data;
		currentNode = currentNode->pRLink;
	}
	return (TRUE);
}

int	check_sort_ASC(t_DoublyList *stack)
{
	/*
		top에서 bottom을 보았을때 기준으로 생각한다.
		밑으로 갈수록 숫자가 커져야한다.
	*/
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
