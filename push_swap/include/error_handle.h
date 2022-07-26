/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:25:32 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:24:20 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLE_H
# define ERROR_HANDLE_H
# include "doublylist_struct.h"

void	print_error(void);
int		check_duplicate_value(t_doubly_list *pList);
void	delete_and_print_error(t_doubly_list *pList);
void	delete_both_stack(t_doubly_list *a_stack, t_doubly_list *b_stack);

#endif
