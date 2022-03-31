/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:09:31 by jim               #+#    #+#             */
/*   Updated: 2022/03/31 22:10:09 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "sort.h"
#include "utils.h"
#include "doublylist.h"
#include "get_next_line.h"
#include "error_handle.h"

static void	handle_result(t_DoublyList *stack)
{
	if (check_sort_ASC(stack) == TRUE)
		ft_putstr("OK\n");
	else if (check_sort_ASC(stack) == FALSE)
		ft_putstr("KO\n");
}

static void	handle_command(t_DoublyList *a_stack, t_DoublyList *b_stack,
							char *command)
{
	if (ft_strncmp("ra",command ,2) == 0)
		;
}

static int	push_swap_checker(t_DoublyList *a_stack, t_DoublyList *b_stack)
{
	char	*gnl_str;

	if (a_stack == NULL || b_stack == NULL)
	{
		deleteDoublyList(a_stack);
		delete_and_print_error(a_stack);
	}
	while (TRUE)
	{
		gnl_str = get_next_line(0);
		if (gnl_str == NULL)
			break ;
		handle_command(a_stack, b_stack, gnl_str);
	}
	handle_result(a_stack);
	return (0);
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
	return (push_swap_checker(a_stack, b_stack));
}
