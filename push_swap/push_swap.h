/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:56 by jim               #+#    #+#             */
/*   Updated: 2022/01/28 14:40:32 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "linkedstack.h"

/* main */
int		push_swap(char *num_str);
int		*parse_str_to_int_list(char *num_str);

/* 11 actions */
void	swap_a(int *a_stack, int *b_stack);
void	swap_b(int *a_stack, int *b_stack);
void	swap_both(int *a_stack, int *b_stack);

void	push_a(int *a_stack, int *b_stack);
void	push_b(int *a_stack, int *b_stack);

void	rotate_a(int *a_stack, int *b_stack);
void	rotate_b(int *a_stack, int *b_stack);
void	rotate_both(int *a_stack, int *b_stack);

void	reverse_rotate_a(int *a_stack, int *b_stack);
void	reverse_rotate_b(int *a_stack, int *b_stack);
void	reverse_rotate_both(int *a_stack, int *b_stack);

/* util */
void	ft_putchar(char ch);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);

/* error handler */
void	print_error(void);
int		check_duplicate_value(int	*num_list);

#endif