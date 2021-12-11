/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:31:38 by jim               #+#    #+#             */
/*   Updated: 2021/12/11 21:45:06 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*dst;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;
	size_t	k;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < s1_size)
		dst[i] = s1[i++];
	free(s1);
	k = 0;
	while (k < s2_size)
		dst[i++] = s2[k++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	int		diff;
	int		i;

	s_len = ft_strlen(s);
	diff = (s + s_len) - (s + start);
	if (diff <= 0)
		return (ft_strdup(""));
	if (diff < len)
		len = (size_t)diff;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = (s + start)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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

int		ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return (idx);
		idx++;
	}
	if (s[idx] == (char)c)
		return (idx);
	return (-1);
}
