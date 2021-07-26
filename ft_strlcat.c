/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:34 by jim               #+#    #+#             */
/*   Updated: 2021/07/08 22:08:45 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t merge_size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start_point;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	start_point = i;
	while (src[j] != '\0' && start_point + j + 1 < merge_size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	if (merge_size < start_point)
		return (j + merge_size);
	else
		return (j + start_point);
}
