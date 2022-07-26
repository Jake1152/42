/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:53 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:41:59 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "sort.h"
#include "utils.h"
#include "doublylist.h"
#include "error_handle.h"

int	main(int argc, char *argv[])
{
	int					idx;
	char				**part_of_input_list;
	t_doubly_list		*a_stack;
	t_doubly_list		*b_stack;

	if (argc == 1)
		return (0);
	a_stack = create_doubly_list();
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
	b_stack = create_doubly_list();
	if (b_stack == NULL)
		delete_and_print_error(a_stack);
	return (push_swap(a_stack, b_stack));
}
