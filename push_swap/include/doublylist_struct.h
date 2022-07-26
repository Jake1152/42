/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:33:05 by jim               #+#    #+#             */
/*   Updated: 2022/07/03 12:24:36 by jim              ###   ########seoul.kr  */
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
	struct s_DoublyListNodeType	*p_l_link;
	struct s_DoublyListNodeType	*p_r_link;
}				t_doubly_list_node;

typedef struct s_doubly_list_type
{
	int					current_element_count;
	t_doubly_list_node	*header_node;
	t_doubly_list_node	*tailer_node;
}				t_doubly_list;

#endif
