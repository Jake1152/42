/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:01:25 by jim               #+#    #+#             */
/*   Updated: 2021/07/09 16:05:02 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*un_d;
	unsigned char	*un_s;

	un_d = (unsigned char *)dst;
	un_s = (unsigned char *)src;
	if (dst == src || n == 0)
		return (dst);
	while (n--)
		*un_d++ = *un_s++;
	return (dst);
}
