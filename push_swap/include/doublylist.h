/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:05 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 12:15:03 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLIST_H
# define DOUBLYLIST_H
# include "doublylist_struct.h"

t_DoublyList		*createDoublyList(void);
t_DoublyListNode	*createDoublyListNode(int data);
void				deleteDoublyList(t_DoublyList **pList);
void				clearDoublyList(t_DoublyList *pList);

int					addDLElement(t_DoublyList *pList, int position, \
								t_DoublyListNode *newNode);
int					removeDLElement(t_DoublyList *pList, int position);
t_DoublyListNode	*getDLElement(t_DoublyList *pList, int position);
void				displayDoublyList(t_DoublyList *pList);

#endif
