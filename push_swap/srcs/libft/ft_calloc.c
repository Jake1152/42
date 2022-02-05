/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:48:17 by jim               #+#    #+#             */
/*   Updated: 2021/07/08 18:31:45 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*un_ori;
	size_t			num;

	num = size * count;
	un_ori = (unsigned char *)malloc(num);
	if (!un_ori)
		return (0);
	ft_bzero(un_ori, num);
	return ((void *)un_ori);
}
