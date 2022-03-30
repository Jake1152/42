/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:13:40 by jim               #+#    #+#             */
/*   Updated: 2022/03/30 17:23:18 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "doublylist_struct.h"
// debug
#include <stdio.h>

// void	ASC_indexing(t_DoublyList *DoublyList, int *arr)
// {
// 	t_DoublyListNode	*cur_node;
// }
/*
static void	print_arr(int *arr, int n)
{
	if (arr == NULL)
		return ;
	for (int k=0; k<n; k++)
		printf("arr[%d] : %d\n", k, arr[k]);
}
*/
void	print_doubly_list(t_DoublyList *doubly_list)
{
	t_DoublyListNode	*cur_node;
	int					cnt;

	if (doubly_list == NULL)
		return ;
	cur_node = doubly_list->headerNode;
	cnt = 0;
	while (cnt < doubly_list->currentElementCount)
	{
		printf("cur_node->data : %d\n", cur_node->data);
		printf("cur_node->sorted_idx : %d\n", cur_node->sorted_idx);
		printf("cnt : %d\n", cnt);
		cur_node = cur_node->pRLink;
		cnt++;
	}
}

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
		{
			printf("cur_node->data : %d\n", cur_node->data);
			printf("cur_node index in doubly list : %d\n", \
									stack->currentElementCount - element_count);
			printf("cur_node->sorted_idx == -1\n.");
		}
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
		printf("malloc error\n");
		return (FALSE); // exit() or delete_error
	}
	data_copy(stack, arr_for_indexing);
	bubble_sort(arr_for_indexing, stack->currentElementCount);
	// linked list돌면서 현재 node가 정렬되었을때 어떤 인덱스에 있는지 확인 필요
	save_sorted_index(stack, arr_for_indexing);
	// print_arr(arr_for_indexing, stack->currentElementCount);
	// print_doubly_list(stack);
	free(arr_for_indexing);
	arr_for_indexing = NULL;
	return (TRUE);
}
