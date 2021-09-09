/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:02:05 by jim               #+#    #+#             */
/*   Updated: 2021/07/09 16:02:30 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*un_dst;
	unsigned char	*un_src;

	un_dst = (unsigned char *)dst;
	un_src = (unsigned char *)src;
	if (dst == src || len == 0)
		return (dst);
	if (src > dst)
		while (len--)
			*un_dst++ = *un_src++;
	else
		while (len--)
			*(un_dst + len) = *(un_src + len);
	return (dst);
}
