/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:05 by jim               #+#    #+#             */
/*   Updated: 2022/03/31 11:49:21 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLIST_H
# define DOUBLYLIST_H
# include "doublylist_struct.h"

t_DoublyList		*createDoublyList(void);
t_DoublyListNode	*createDoublyListNode(int data);
void				deleteDoublyList(t_DoublyList **pList);
int					clearDoublyList(t_DoublyList *pList);

int					addDLElement(t_DoublyList *pList, int position, \
								t_DoublyListNode *newNode);
int					removeDLElement(t_DoublyList *pList, int position);
t_DoublyListNode	*getDLElement(t_DoublyList *pList, int position);

#endif
