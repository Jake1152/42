/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:31:38 by jim               #+#    #+#             */
/*   Updated: 2021/12/13 10:53:31 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	if (s == NULL)
		return (0);
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

	s1_size = ft_strlen(*s1);
	s2_size = ft_strlen(s2);
	if (s2 == NULL)
		return (NULL);
	if (*s1 == NULL)
	{
		*s1 = ft_strdup("");
		if (*s1 == NULL)
			return (NULL);
	}	
	dst = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (dst == NULL)
	{
		free(*s1);
		*s1 = NULL;
		return (NULL);
	}	
	ft_strlcpy(dst, *s1, s1_size + 1);
	free(*s1);
	ft_strlcat(dst, s2, s1_size + s2_size + 1);
	printf("dst : %s \n", dst);
	printf("dst len : %zu \n", ft_strlen(dst));
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	int		diff;

	s_len = ft_strlen(s);
	diff = s_len - start;
	if (diff <= 0)
		return (ft_strdup(""));
	else if (diff > 0 && (size_t)diff < len)
		len = (size_t)diff;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	idx;
	size_t	s1_size;

	if (s1 == NULL)
		return (NULL);
	s1_size = ft_strlen(s1);
	printf("s1 string in dup : %s\n", s1);
	printf("s1 size : %zu\n", s1_size);
	dest = (char *)malloc(sizeof(char) * (s1_size + 1));
	if (dest == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}

int	ft_strchr(const char *s, int c)
{
	size_t	idx;

	if (s == NULL)
		return (-1);
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
