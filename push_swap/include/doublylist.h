/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:05 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 13:43:49 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLIST_H
# define DOUBLYLIST_H
# include "doublylist_struct.h"

t_doubly_list		*create_doubly_list(void);
t_doubly_list_node	*create_doubly_list_node(int data);
void				delete_doubly_list(t_doubly_list **pList);
int					clear_doubly_list(t_doubly_list *pList);

int					add_dl_element(t_doubly_list *pList, int position, \
								t_doubly_list_node *new_node);
int					remove_dl_element(t_doubly_list *pList, int position);
t_doubly_list_node	*get_dl_element(t_doubly_list *pList, int position);

#endif
