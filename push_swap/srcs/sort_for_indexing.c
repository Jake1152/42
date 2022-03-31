/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:13:40 by jim               #+#    #+#             */
/*   Updated: 2022/03/31 11:02:13 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "doublylist_struct.h"
#include "push_swap.h"
#include "utils.h"

static void	data_copy(t_DoublyList *DoublyList, int *arr)
{
	t_DoublyListNode	*cur_node;
	int					k;

	if (DoublyList == NULL || arr == NULL)
		return ;
	cur_node = DoublyList->headerNode;
	k = 0;
	while (k < DoublyList->currentElementCount)
	{
		arr[k] = cur_node->data;
		cur_node = cur_node->pRLink;
		k++;
	}
}

static void	bubble_sort(int *arr_for_indexing, int n)
{
	int					i;
	int					j;
	int					tmp;

	if (arr_for_indexing == NULL)
		return ;
	i = n - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (arr_for_indexing[j] > arr_for_indexing[j + 1])
			{
				tmp = arr_for_indexing[j];
				arr_for_indexing[j] = arr_for_indexing[j + 1];
				arr_for_indexing[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

static int	bin_search_for_idx(int *arr, int target, int elementCount)
{
	size_t	start;
	size_t	end;
	size_t	mid;

	if (arr == NULL)
		return (FALSE);
	start = 0;
	end = elementCount - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (target == arr[mid])
			return (mid);
		else if (target > arr[mid])
			start = mid + 1;
		else if (target < arr[mid])
			end = mid - 1;
	}
	return (FALSE);
}

static void	save_sorted_index(t_DoublyList *stack, int *arr_for_indexing)
{
	t_DoublyListNode	*cur_node;
	int					element_count;

	if (stack == NULL || arr_for_indexing == NULL)
		return ;
	cur_node = stack->headerNode;
	element_count = stack->currentElementCount;
	while (element_count)
	{
		cur_node->sorted_idx = \
						bin_search_for_idx(arr_for_indexing, cur_node->data, \
											stack->currentElementCount);
		if (cur_node->sorted_idx == FALSE)
			ft_putstr("cur_node->sorted_idx == -1\n.");
		cur_node = cur_node->pRLink;
		element_count--;
	}
}

int	indexing(t_DoublyList *stack)
{
	int					*arr_for_indexing;

	if (stack == NULL)
		return (FALSE);
	arr_for_indexing = (int *)malloc(sizeof(int) * stack->currentElementCount);
	if (arr_for_indexing == NULL)
	{
		ft_putstr("malloc error\n");
		return (FALSE);
	}
	data_copy(stack, arr_for_indexing);
	bubble_sort(arr_for_indexing, stack->currentElementCount);
	save_sorted_index(stack, arr_for_indexing);
	free(arr_for_indexing);
	arr_for_indexing = NULL;
	return (TRUE);
}
