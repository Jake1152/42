/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:56 by jim               #+#    #+#             */
/*   Updated: 2022/04/01 15:07:54 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "doublylist_struct.h"
# include "sort_struct.h"

int					push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack);
int					parse_str_to_doublylist(t_DoublyList *pList, \
												char **part_of_input_list);

void				swap(t_DoublyList *stack, t_stack_type stack_type, \
							int print_flag);
void				swap_both(t_DoublyList *a_stack, t_DoublyList *b_stack, \
								int print_flag);
void				swap_command_printer(t_stack_type stack_type, \
											int print_flag);

void				push(t_DoublyList *from_stack, t_DoublyList *to_stack, \
							t_stack_type to_stack_type, int print_flag);

void				rotate(t_DoublyList *stack, t_stack_type stack_type, \
							int print_flag);
void				rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack, \
								int print_flag);

void				reverse_rotate(t_DoublyList *stack, \
									t_stack_type stack_type, int print_flag);
void				reverse_rotate_both(t_DoublyList *a_stack, \
										t_DoublyList *b_stack, \
										int print_flag);

t_DoublyListNode	*pop(t_DoublyList *stack);

#endif
