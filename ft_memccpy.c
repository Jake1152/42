/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:01:25 by jim               #+#    #+#             */
/*   Updated: 2021/07/05 18:52:47 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*un_d;
	unsigned char	*un_s;

	un_d = (unsigned char *)dst;
	un_s = (unsigned char *)src;
	while (n--)
	{
		*un_d = *un_s;
		if ((unsigned char)c == *un_s)
			return (++un_d);
		un_d++;
		un_s++;
	}
	return (0);
}
