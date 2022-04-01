/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/04/01 15:31:46 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "utils.h"
#include "doublylist.h"
#include "error_handle.h"

int	push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	t_pivot_info	pivot_info;

	if (a_stack == NULL || b_stack == NULL)
		delete_both_stack(a_stack, b_stack);
	if (check_sort_ASC(a_stack) == TRUE)
		return (0);
	if (a_stack->currentElementCount <= 5)
		sort_brute_force(a_stack, b_stack);
	else
	{
		init_pivot(*a_stack, &pivot_info);
		if (indexing(a_stack) == FALSE)
			delete_both_stack(a_stack, b_stack);
		a_to_b(a_stack, b_stack, pivot_info);
		b_to_a(a_stack, b_stack);
	}
	return (0);
}

int	parse_str_to_doublylist(t_DoublyList *pList, char **part_of_input_list)
{
	t_DoublyListNode	*addDLElementNode;
	int					result_num;
	int					add_flag;
	int					word_cnt;
	int					atoi_flag;

	if (pList == NULL || part_of_input_list == NULL)
		return (FALSE);
	word_cnt = 0;
	while (part_of_input_list[word_cnt])
	{
		result_num = ft_atoi(part_of_input_list[word_cnt], &atoi_flag);
		if (atoi_flag == FALSE)
			delete_and_print_error(pList);
		addDLElementNode = createDoublyListNode(result_num);
		if (addDLElementNode == NULL)
			delete_and_print_error(pList);
		add_flag = addDLElement(pList, pList->currentElementCount, \
								addDLElementNode);
		if (add_flag == FALSE)
			delete_and_print_error(pList);
		word_cnt++;
	}
	free_list(&part_of_input_list, word_cnt);
	return (add_flag);
}
