/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:05 by jim               #+#    #+#             */
/*   Updated: 2022/03/29 13:45:14 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLYLIST_STRUCT_H
# define DOUBLYLIST_STRUCT_H

typedef enum e_flag
{
	TRUE = 1,
	FALSE = -1,
}				t_e_flag;

typedef struct s_DoublyListNodeType
{
	int							data;
	int							sorted_idx;
	struct s_DoublyListNodeType	*pLLink;
	struct s_DoublyListNodeType	*pRLink;
}				t_DoublyListNode;

typedef struct s_DoublyListType
{
	int					currentElementCount;
	t_DoublyListNode	*headerNode;
	t_DoublyListNode	*tailerNode;
}				t_DoublyList;

#endif
