/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:37:51 by jim               #+#    #+#             */
/*   Updated: 2021/07/08 21:40:23 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = (char *)malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (0);
	while (len--)
	{
		if (*s == start)
			ft_strlcpy(str, s, len+1);
			return (str);
		s++;
	}
	return (0);
}