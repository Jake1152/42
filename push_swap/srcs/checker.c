/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:09:31 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:46:02 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sort.h"
#include "utils.h"
#include "doublylist.h"
#include "push_swap.h"
#include "get_next_line.h"
#include "error_handle.h"

static void	handle_result(t_doubly_list *a_stack, t_doubly_list *b_stack)
{
	if (b_stack->current_element_count == 0 && check_sort_asc(a_stack) == TRUE)
		ft_putstr("OK\n");
	else if (b_stack->current_element_count != 0 \
			|| check_sort_asc(a_stack) == FALSE)
		ft_putstr("KO\n");
}

static void	handle_command(t_doubly_list *a_stack, t_doubly_list *b_stack,
							char *command)
{
	if (ft_strncmp("pa\n", command, 3) == 0)
		push(b_stack, a_stack, A_STACK, FALSE);
	else if (ft_strncmp("ra\n", command, 3) == 0)
		rotate(a_stack, A_STACK, FALSE);
	else if (ft_strncmp("rra\n", command, 4) == 0)
		reverse_rotate(a_stack, A_STACK, FALSE);
	else if (ft_strncmp("sa\n", command, 3) == 0)
		swap(a_stack, A_STACK, FALSE);
	else if (ft_strncmp("pb\n", command, 3) == 0)
		push(a_stack, b_stack, B_STACK, FALSE);
	else if (ft_strncmp("rb\n", command, 3) == 0)
		rotate(b_stack, B_STACK, FALSE);
	else if (ft_strncmp("rrb\n", command, 4) == 0)
		reverse_rotate(b_stack, B_STACK, FALSE);
	else if (ft_strncmp("sb\n", command, 3) == 0)
		swap(b_stack, B_STACK, FALSE);
	else if (ft_strncmp("rr\n", command, 3) == 0)
		rotate_both(a_stack, b_stack, FALSE);
	else if (ft_strncmp("rrr\n", command, 4) == 0)
		reverse_rotate_both(a_stack, b_stack, FALSE);
	else if (ft_strncmp("ss\n", command, 3) == 0)
		swap_both(a_stack, b_stack, FALSE);
	else
		delete_both_stack(a_stack, b_stack);
}

static int	push_swap_checker(t_doubly_list *a_stack, t_doubly_list *b_stack)
{
	char	*gnl_str;

	if (a_stack == NULL || b_stack == NULL)
		delete_both_stack(a_stack, b_stack);
	while (TRUE)
	{
		gnl_str = get_next_line(0);
		if (gnl_str == NULL)
			break ;
		if (ft_strlen(gnl_str) > 4)
			delete_both_stack(a_stack, b_stack);
		handle_command(a_stack, b_stack, gnl_str);
		free(gnl_str);
		gnl_str = NULL;
	}
	handle_result(a_stack, b_stack);
	return (0);
}

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
	return (push_swap_checker(a_stack, b_stack));
}
