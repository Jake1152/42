/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:01:58 by jim               #+#    #+#             */
/*   Updated: 2021/07/06 20:39:58 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	if (!un_s1 && !un_s2)
		return (0);
	while (*un_s1 && n--)
	{
		if ((*(unsigned char *)un_s1 != *(unsigned char *)un_s2))
			return (*un_s1 - *un_s2);
		un_s1++;
		un_s2++;
	}
	return (0);
}
