/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:23:33 by jim               #+#    #+#             */
/*   Updated: 2021/10/14 13:13:31 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur_node;
	t_list	*del_node;

	cur_node = (*lst);
	while (cur_node != NULL)
	{
		del_node = cur_node;
		ft_lstdelone(del_node, del);
		cur_node = cur_node->next;
	}
	*lst = NULL;
}
