/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jake <jake@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:31:11 by jim               #+#    #+#             */
/*   Updated: 2021/12/12 18:44:47 by jake             ###   ########.fr       */
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
	while (TRUE)
	{
		newline_idx = ft_strchr(save[fd], '\n');
		if (newline_idx >= 0)
			return (get_next_line_from_save(&save[fd], newline_idx));
		read_size = read(fd, read_str, BUFFER_SIZE);
		// printf("read_size : %d \n", read_size);
		if (read_size <= 0)
			break ;
		read_str[read_size] = '\0';
		save[fd] = ft_strjoin(&save[fd], read_str);
		if (save[fd] == NULL)
			return (NULL);
	}
	if (ft_strlen(save[fd]) > 0 && read_size == 0)
		return (save[fd]);
	// printf("It will be returned NULL\n");
	return (NULL);
}

char	*get_next_line_from_save(char **save, int newline_idx)
{
	char	*next_line;
	char	*tmp;

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
