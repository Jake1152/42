/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/02/06 20:42:28 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "./libft/libft.h"
#include "../include/doublylist.h"
#include <stdio.h>

// push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
int	push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	/*
		정렬하는 용도로만 사용한다.
	*/
	// size_t	cmd_cnt;
	return (0);
}

int	parse_str_to_doublylist(t_DoublyList *pList, char **part_of_input_list)
{
	t_DoublyListNode	*addDLElementNode;
	int					result_num;
	int					add_flag;

	// if (pList == NULL)
		// part_of_input_list 리스트 단어들 다 free, split에 있는 free 함수 사용

	add_flag = 1; // should be removed
	printf("### Start of parse_str_to_doublylist\n");
	// printf("*part_of_input_list : %s\n", *part_of_input_list);
	while (*part_of_input_list)
	{
		result_num = ft_atoi(*part_of_input_list);
		printf("result_num : %d\n", result_num);
		if (ft_strncmp(*part_of_input_list, "0", 1) != 0 && result_num == 0)
			printf("### Not a Number\n");
			// delete_and_print_error(pList);
		// addDLElementNode = createDoublyListNode(result_num);
		// if (addDLElementNode == NULL)
		// 	delete_and_print_error(pList);
		// add_flag = addDLElement(pList, pList->currentElementCount, \
		// 						addDLElementNode);
		// if (add_flag == FALSE)
		// 	delete_and_print_error(pList);
		part_of_input_list++;
	}
	// part_of_input_list free
	printf("### End of parse_str_to_doublylist\n");
	return (add_flag);
}

int	main(int argc, char *argv[])
{
	int					idx;
	int					duplicate_flag;
	char				**part_of_input_list;
	t_DoublyList		*a_stack;
	t_DoublyList		*b_stack;

	printf("- Start of main()\n");
	if (argc == 1)
		print_error();
	// a_stack = createDoublyList();
	a_stack = NULL;
	// if (a_stack == NULL)
	// 	print_error();
	idx = 1;
	while (idx < argc)
	{
		part_of_input_list = ft_split(argv[idx], ' ');
		if (part_of_input_list == NULL)
			printf("== part_of_input_list is NULL\n");
			// delete_and_print_error(a_stack);
		parse_str_to_doublylist(a_stack, part_of_input_list);
		idx++;
	}
	duplicate_flag = check_duplicate_value(a_stack);
	// if (duplicate_flag == FALSE)
	// 	printf("### duplicate_flag is FALSE\n");
	// 	delete_and_print_error(a_stack);
	// b_stack = createDoublyList();
	// if (b_stack == NULL)
	// 	delete_and_print_error(a_stack);
	// push_swap(a_stack, b_stack);
	printf("- End of main()\n");
	return (0);
}
