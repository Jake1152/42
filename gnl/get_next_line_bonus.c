/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:31:11 by jim               #+#    #+#             */
/*   Updated: 2021/12/14 01:29:42 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	int			newline_idx;
	char		read_str[BUFFER_SIZE + 1];
	int			read_size;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (TRUE)
	{
		newline_idx = ft_strchr(save[fd], '\n');
		if (newline_idx >= 0)
			return (get_next_line_from_save(&save[fd], newline_idx));
		read_size = read(fd, read_str, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		read_str[read_size] = '\0';
		save[fd] = ft_strjoin(save[fd], read_str);
		if (save[fd] == NULL)
			return (NULL);
	}	
	return (return_remain(&save[fd], read_size));
}

char	*return_remain(char **save, int read_size)
{
	char	*ret;

	if (*save == NULL || save == NULL)
		return (NULL);
	ret = NULL;
	if ((ft_strlen(*save) > 0) && read_size == 0)
	{
		ret = ft_strdup(*save);
		if (ret == NULL)
		{
			free(*save);
			*save = NULL;
			return (NULL);
		}
	}
	free(*save);
	*save = NULL;
	return (ret);
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
	tmp = ft_strdup(*save + newline_idx + 1);
	free(*save);
	if (tmp == NULL)
	{
		free(next_line);
		*save = NULL;
		return (NULL);
	}
	*save = tmp;
	return (next_line);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
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

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
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
