/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/02/05 22:00:11 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"
#include "doublylist.h"

// push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
int	push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	/*
		정렬하는 용도로만 사용한다.
	*/
	size_t	cmd_cnt;

	cmd_cnt = 0;
	// int * array return 
	if (a_stack == NULL)
	{
		print_error();
		return (0);
	}
	b_stack = create_int_list();
	return (cmd_cnt);
}

int	parse_str_to_doublylist(t_DoublyList *pList, char **part_of_input_list)
{
	t_DoublyListNode	*addDLElementNode;
	int					result_num;
	int					add_flag;

	while (part_of_input_list)
	{
		result_num = ft_atoi(*part_of_input_list);
		if (ft_strncmp(*part_of_input_list, "0", 1) != 0 && result_num == 0)
			delete_and_print_error(pList);
		addDLElementNode = createDoublyListNode(result_num);
		if (addDLElementNode == NULL)
			delete_and_print_error(pList);
		add_flag = addDLElement(pList, pList->currentElementCount, \
								addDLElementNode);
		if (add_flag == FALSE)
			delete_and_print_error(pList);
		part_of_input_list++;
	}
	return (add_flag);
}

int	main(int argc, char *argv[])
{
	int					idx;
	int					duplicate_flag;
	char				**part_of_input_list;
	t_DoublyList		*a_stack;
	t_DoublyList		*b_stack;

	if (argc == 0)
		print_error();
	a_stack = createDoublyList();
	if (a_stack == NULL)
		print_error();
	idx = 1;
	while (idx < argc)
	{
		part_of_input_list = ft_split(argv[idx], ' ');
		parse_str_to_doublylist(a_stack, part_of_input_list);
		idx++;
		// idx++를 잘보이게 하면서 어떻게 26줄로 줄일 것인가?
	}
	duplicate_flag = check_duplicate_value(a_stack);
	if (duplicate_flag == FALSE)
		delete_and_print_error(a_stack);
	b_stack = createDoublyList();
	if (b_stack == NULL)
		delete_and_print_error(a_stack);
	push_swap(a_stack, b_stack);
	return (0);
}
