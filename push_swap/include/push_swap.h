/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:56 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:24:20 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "doublylist_struct.h"
# include "sort_struct.h"

int					push_swap(t_doubly_list *a_stack, t_doubly_list *b_stack);
int					parse_str_to_doublylist(t_doubly_list *pList, \
												char **part_of_input_list);

void				swap(t_doubly_list *stack, t_stack_type stack_type, \
							int print_flag);
void				swap_both(t_doubly_list *a_stack, t_doubly_list *b_stack, \
								int print_flag);
void				swap_command_printer(t_stack_type stack_type, \
											int print_flag);

void				push(t_doubly_list *from_stack, t_doubly_list *to_stack, \
							t_stack_type to_stack_type, int print_flag);

void				rotate(t_doubly_list *stack, t_stack_type stack_type, \
							int print_flag);
void				rotate_both(t_doubly_list *a_stack, t_doubly_list *b_stack, \
								int print_flag);

void				reverse_rotate(t_doubly_list *stack, \
									t_stack_type stack_type, int print_flag);
void				reverse_rotate_both(t_doubly_list *a_stack, \
										t_doubly_list *b_stack, \
										int print_flag);

t_doubly_list_node	*pop(t_doubly_list *stack);

#endif
