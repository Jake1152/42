/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/02/10 20:15:38 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "./libft/libft.h"
#include "../include/doublylist.h"
#include <stdio.h>

int	push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	/*
		정렬하는 용도로만 사용한다.
	*/
	t_DoublyListNode	*tmpNode;

	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);

	printf("\n\n== pop test\n");
	tmpNode = pop(a_stack);
	printf("tmpNode->data : %d\n", tmpNode->data);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);

	for (int i=1; i<=5; i++)
	{
		printf("\n\n== rotate_a %dth test\n", i);
		rotate_a(a_stack, TRUE);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	for (int i=1; i<=5; i++)
	{
		printf("\n\n== reverse_rotate_a %dth test\n", i);
		reverse_rotate_a(a_stack, TRUE);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	printf("\n\n====== push_a test\n");
	push_a(a_stack, b_stack);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);

	printf("\n\n====== push_b test\n");
	push_b(a_stack, b_stack);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);

	displayDoublyList(a_stack);
	for (int i=1; i<=1; i++)
	{
		printf("\n\n== swap_a %dth test\n", i);
		swap_a(a_stack, TRUE);
		printf("== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
	}

	printf("\n\n====== swap_b test\n");
	swap_b(b_stack, TRUE);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);


	printf("\n=====================================================\n");
	printf("\n\n====== push_a test\n");
	push_a(a_stack, b_stack);
	printf("== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);
	printf("\n=====================================================\n");

	printf("\n=====================================================\n");
	printf("\n\n====== push_b test\n");
	for (int i=1; i<=3; i++)
	{
		printf("\n\n====== push_b %dth test\n", i);
		push_b(a_stack, b_stack);
		printf("\n== displayDoublyList(a_stack)\n");
		displayDoublyList(a_stack);
		printf("\n== displayDoublyList(b_stack)\n");
		displayDoublyList(b_stack);
	}
	
	printf("\n=====================================================\n");

	printf("\n\n== displayDoublyList(a_stack)\n");
	displayDoublyList(a_stack);
	printf("\n\n== displayDoublyList(b_stack)\n");
	displayDoublyList(b_stack);

	printf("\n\n### Finally done\n");

	// size_t	cmd_cnt;
	return (0);
}

// part_of_input_list doublyList로 변환이후에 free 및 dangling방지할 것
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
		print_error();
	a_stack = createDoublyList();
	if (a_stack == NULL)
		print_error();
	idx = 1;
	while (idx < argc)
	{
		part_of_input_list = ft_split(argv[idx], ' ');
		if (part_of_input_list == NULL)
			delete_and_print_error(a_stack);
		parse_str_to_doublylist(a_stack, part_of_input_list);
		idx++;
	}
	if (check_duplicate_value(a_stack) == FALSE)
		delete_and_print_error(a_stack);
	b_stack = createDoublyList();
	if (b_stack == NULL)
		delete_and_print_error(a_stack);
	return (push_swap(a_stack, b_stack));
}
