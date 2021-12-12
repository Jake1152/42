/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:31:11 by jim               #+#    #+#             */
/*   Updated: 2021/12/12 20:28:21 by jake             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save[FD_SIZE];
	int			newline_idx;
	char		read_str[BUFFER_SIZE + 1];
	int			read_size;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_SIZE)
		return (NULL);
	save[fd] = NULL;
	while (TRUE)
	{
		newline_idx = ft_strchr(save[fd], '\n');
		if (newline_idx >= 0)
			return (get_next_line_from_save(save[fd], newline_idx));
		read_size = read(fd, read_str, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		read_str[read_size] = '\0';
		save[fd] = ft_strjoin(save[fd], read_str);
		if (save[fd] == NULL)
			return (NULL);
	}
	if (ft_strncmp(save[fd], "", 1) > 0 && read_size == 0)
		return (save[fd]);
	return (NULL);
}

char	*get_next_line_from_save(char **save, int newline_idx)
{
	char	*next_line;
	char	*tmp;

	next_line = ft_substr(*save, 0, newline_idx + 1);
	if (next_line == NULL)
	{
		free(*save);
		*save = NULL;
		return (NULL);
	}		
	tmp = ft_substr(*save, newline_idx + 1, \
						ft_strlen(*save) - (newline_idx + 1));
	free(*save);
	if (tmp == NULL)
		return (NULL);
	*save = tmp;
	return (next_line);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	while ((k < dstsize - 1) && src[k])
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	i = 0;
	while (i++ < n)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
		{
			if (c1 < c2)
				return (-1);
			else
				return (1);
		}
		if (!c1)
			break ;
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	org_dstsize;

	i = ft_strlen(dst);
	j = 0;
	org_dstsize = i;
	while (src[j] != '\0' && (org_dstsize + j + 1 < dstsize))
		dst[i++] = src[j++];
	if (org_dstsize < dstsize)
		dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	if (dstsize < org_dstsize)
		return (j + dstsize);
	else
		return (j + org_dstsize);
}
