/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:05 by jim               #+#    #+#             */
/*   Updated: 2022/02/03 19:39:31 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLIST_H
# define DOUBLYLIST_H
# include <stdlib.h>

// file name 구분 definition, manipulation
typedef struct s_DoublyListNodeType
{
	int				data;
	struct s_DoublyListNodeType	*pLLink;
	struct s_DoublyListNodeType	*pRLink;
}				t_DoublyListNode;

typedef struct s_DoublyListType
{
	int				currentElementCount;
	t_DoublyListNode		*headerNode;
}				t_DoublyList;

t_DoublyList		*createDoublyList(void);
t_DoublyListNode	*createDoublyListNode(int data);
void				deleteDoublyList(t_DoublyList **pList);
void 				clearDoublyList(t_DoublyList *pList);

int					addDLElement(t_DoublyList *pList, int position, \
								t_DoublyListNode *newNode);
int					removeDLElement(t_DoublyList* pList, int position);
int					getDoublyListLength(t_DoublyList* pList);
t_DoublyListNode	*getDLElement(t_DoublyList* pList, int position);
void				displayDoublyList(t_DoublyList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif

/*
TODO

1. double linked list implement
2. polynomial implement
3. linked list reverse

*/
