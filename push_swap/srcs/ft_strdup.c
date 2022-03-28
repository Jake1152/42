/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:48:23 by jim               #+#    #+#             */
/*   Updated: 2022/03/28 12:43:48 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	idx;
	size_t	s1_size;

	s1_size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (s1_size + 1));
	if (dest == 0)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}
