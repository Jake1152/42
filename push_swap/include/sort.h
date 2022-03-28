/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:36:20 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 22:50:22 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include "doublylist_struct.h"
# include "sort_struct.h"

void			a_to_b(t_DoublyList *a_stack, t_DoublyList *b_stack, \
						t_pivot_info pivot_info);
void			b_to_a(t_DoublyList *a_stack, t_DoublyList *b_stack);
t_max_data_info	find_max_data_info(t_DoublyList *b_stack);

void			init_pivot(t_DoublyList stack, t_pivot_info *pivot_info);

#endif
