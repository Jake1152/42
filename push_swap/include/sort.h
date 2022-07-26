/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:36:20 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:26:14 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "doublylist_struct.h"
# include "sort_struct.h"

int				check_sort_asc(t_doubly_list *stack);
void			a_to_b(t_doubly_list *a_stack, t_doubly_list *b_stack, \
						t_pivot_info pivot_info);
void			b_to_a(t_doubly_list *a_stack, t_doubly_list *b_stack);
t_max_data_info	find_max_data_info(t_doubly_list *b_stack);
void			init_pivot(t_doubly_list stack, t_pivot_info *pivot_info);

int				find_mid_value_when_3things(t_doubly_list *stack);
int				indexing(t_doubly_list *stack);

void			sort_brute_force(t_doubly_list *a_stack, \
								t_doubly_list *b_stack);
void			sort_3things(t_doubly_list *stack, t_stack_type stack_type);
void			sort_3things_other_part(t_doubly_list *stack, \
										t_stack_type stack_type, \
										int mid_value);
int				sort_4_5_things(t_doubly_list *a_stack, t_doubly_list *b_stack);
#endif
