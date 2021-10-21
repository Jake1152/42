/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 11:06:26 by jim               #+#    #+#             */
/*   Updated: 2021/10/14 11:27:41 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		l_size;
	t_list	*cur_node;

	l_size = 0;
	cur_node = lst;
	while (cur_node)
	{
		cur_node = cur_node->next;
		l_size++;
	}
	return (l_size);
}
