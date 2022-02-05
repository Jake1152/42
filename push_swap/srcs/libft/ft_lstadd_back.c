/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:17:33 by jim               #+#    #+#             */
/*   Updated: 2021/10/14 10:24:28 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur_node;

	cur_node = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (cur_node->next)
		cur_node = cur_node->next;
	cur_node->next = new;
}
