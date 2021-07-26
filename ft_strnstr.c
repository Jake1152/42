/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:48 by jim               #+#    #+#             */
/*   Updated: 2021/07/08 21:43:03 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			n_idx;
	unsigned char	*starting_point;

	n_idx = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack && len)
	{
		starting_point = (unsigned char *)haystack;
		while (len && needle[n_idx] && *haystack && *haystack == needle[n_idx])
		{
			n_idx++;
			haystack++;
			len--;
		}		
		if (needle[n_idx] == 0)
			return ((char *)starting_point);
		n_idx = 0;
		len--;
		haystack++;
	}
	return (0);
}
