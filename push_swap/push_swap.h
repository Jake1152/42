/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:56 by jim               #+#    #+#             */
/*   Updated: 2022/01/25 13:54:58 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

int		push_swap(char *num_str);
int	    *parse_str_to_int_list();

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

#endif