/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:31:11 by jim               #+#    #+#             */
/*   Updated: 2021/12/11 21:48:08 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 42
#include <stdio.h>
// <stdio.h> must be removed

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
		printf("newline_idx : %d \n", newline_idx);
		if (newline_idx >= 0)
			return(get_next_line_from_save(&save[fd], newline_idx));
		read_size = read(fd, read_str, BUFFER_SIZE);
		printf("read_size : %d \n", read_size);
		if (read_size <= 0)
			break ;
		read_str[read_size] = '\0';
		save[fd] = ft_strjoin(&save[fd], read_str);
		printf("save[fd] : %s \n", save[fd]);
		if (save[fd] == NULL)
			return (NULL);
	}
	if (ft_strlen(save[fd]) > 0 && read_size == 0)
		return (save[fd]);
	return (NULL);
}

char	*get_next_line_from_save(char **save, int newline_idx)
{
	char	*next_line;
	char	*tmp;

	next_line = (char *)malloc(newline_idx + 1 + 1);
	if (next_line == NULL)
		return (NULL);
	next_line = ft_substr(*save, 0, newline_idx + 1);
	if (next_line == NULL)
		return (NULL);
	tmp = ft_substr(*save, newline_idx + 1, \
						ft_strlen(*save) - (newline_idx + 1));
	if (tmp == NULL)
		return (NULL);
	free(*save);
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
