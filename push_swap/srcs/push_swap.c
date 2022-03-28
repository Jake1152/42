/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 12:44:47 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "utils.h"
#include "doublylist.h"
//debug
#include <stdio.h>

int	push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	/*
		정렬하는 용도로만 사용한다.
	*/
	// t_DoublyListNode	*tmpNode;
	// size_t	cmd_cnt;
	// displayDoublyList(a_stack);
	if (check_sort_DESC(a_stack) == TRUE)
		printf("'A' stack is DESC sorted.\n");
	if (check_sort_ASC(a_stack) == TRUE)
		printf("'A' stack is ASC sorted.\n");
	if (check_sort_DESC(b_stack) == TRUE)
		printf("'B' stack is DESC sorted.\n");
	if (check_sort_ASC(b_stack) == TRUE)
		printf("'B' stack is ASC sorted.\n");
	return (0);
}

int	parse_str_to_doublylist(t_DoublyList *pList, char **part_of_input_list)
{
	t_DoublyListNode	*addDLElementNode;
	int					result_num;
	int					add_flag;
	int					word_cnt;

	if (pList == NULL || part_of_input_list == NULL)
		return (FALSE);
	word_cnt = 0;
	while (part_of_input_list[word_cnt])
	{
		result_num = ft_atoi(part_of_input_list[word_cnt]);
		if (ft_strncmp(part_of_input_list[word_cnt], "0", 1) != 0 \
			 && result_num == 0)
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

int	main(int argc, char *argv[])
{
	int					idx;
	char				**part_of_input_list;
	t_DoublyList		*a_stack;
	t_DoublyList		*b_stack;

	if (argc == 1)
		return (0);
	a_stack = createDoublyList();
	if (a_stack == NULL)
		print_error();
	idx = 1;
	while (idx < argc)
	{
		part_of_input_list = ft_split(argv[idx], ' ');
		if (part_of_input_list == NULL || \
			parse_str_to_doublylist(a_stack, part_of_input_list) == FALSE)
			delete_and_print_error(a_stack);
		idx++;
	}
	if (check_duplicate_value(a_stack) == FALSE)
		delete_and_print_error(a_stack);
	b_stack = createDoublyList();
	if (b_stack == NULL)
		delete_and_print_error(a_stack);
	return (push_swap(a_stack, b_stack));
}
