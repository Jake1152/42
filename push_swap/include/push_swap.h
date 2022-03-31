/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:56 by jim               #+#    #+#             */
/*   Updated: 2022/03/31 11:50:36 by jim              ###   ########seoul.kr  */
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
void				swap_both(t_DoublyList *a_stack, t_DoublyList *b_stack);
void				swap_command_printer(t_stack_type stack_type, \
										int print_flag);

void				push(t_DoublyList *from_stack, t_DoublyList *to_stack, \
							t_stack_type to_stack_type);

void				rotate(t_DoublyList *stack, t_stack_type stack_type, \
							int print_flag);
void				rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack);

void				reverse_rotate(t_DoublyList *stack, \
									t_stack_type stack_type, int print_flag);
void				reverse_rotate_both(t_DoublyList *a_stack, \
										t_DoublyList *b_stack);

t_DoublyListNode	*pop(t_DoublyList *stack);
int					check_sort_ASC(t_DoublyList *stack);

void				print_error(void);
int					check_duplicate_value(t_DoublyList *pList);
void				delete_and_print_error(t_DoublyList *pList);

#endif
