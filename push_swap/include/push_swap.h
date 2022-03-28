/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:32:56 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 21:53:31 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "doublylist_struct.h"

/* main */
int					push_swap(t_DoublyList *a_stack, t_DoublyList *b_stack);
int					parse_str_to_doublylist(t_DoublyList *pList, \
												char **part_of_input_list);

/* stack of pdf actions */
void				swap_a(t_DoublyList *stack, int print_flag);
void				swap_b(t_DoublyList *stack, int print_flag);
void				swap_both(t_DoublyList *a_stack, t_DoublyList *b_stack);
void				swap_command_printer(char *command, int print_flag);

void				push_a(t_DoublyList *a_stack, t_DoublyList *b_stack);
void				push_b(t_DoublyList *a_stack, t_DoublyList *b_stack);

void				rotate(t_DoublyList *stack);
void				rotate_a(t_DoublyList *stack, int print_flag);
void				rotate_b(t_DoublyList *stack, int print_flag);
void				rotate_both(t_DoublyList *a_stack, t_DoublyList *b_stack);

void				reverse_rotate(t_DoublyList *stack);
void				reverse_rotate_a(t_DoublyList *stack, int print_flag);
void				reverse_rotate_b(t_DoublyList *stack, int print_flag);
void				reverse_rotate_both(t_DoublyList *a_stack, \
										t_DoublyList *b_stack);

/* sort algorithms */

/* other stack action */
t_DoublyListNode	*pop(t_DoublyList *stack);
int					check_sort_DESC(t_DoublyList *stack);
int					check_sort_ASC(t_DoublyList *stack);

/* error handler */
void				print_error(void);
int					check_duplicate_value(t_DoublyList *pList);
void				delete_and_print_error(t_DoublyList *pList);

#endif
