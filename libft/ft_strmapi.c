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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*to_be;
	size_t	s_len;
	size_t	idx;

	idx = 0;
	s_len = ft_strlen(s);
	to_be = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!to_be)
		return (0);
	while (s[idx])
	{
		to_be[idx] = (*f)(idx, s[idx]);
		idx++;
	}
	to_be[idx] = '\0';
	return (to_be);
}
