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

char	*get_next_line(int fd)
{
	static char	*save[FD_SIZE];
	char		*newline_idx;
	char		read_str[BUFFER_SIZE + 1];
	int			read_size;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_SIZE)
		return (NULL);
	save[fd] = "";
	while (TRUE)
	{
		newline_idx = ft_strchr(save[fd], '\n');
		if (newline_idx >= 0)
			return(get_next_line_from_save(&save[fd], newline_idx));
		read_size = read(fd, read_str, BUFFER_SIZE);
		if (read_size <= 0)
			break ;
		read_str[read_size] = '\0';
		save[fd] = ft_strjoin(&save[fd], read_str);
		if (save[fd] == NULL)
			return (NULL);
	}
	if (save[fd] && )
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
	// hello\nworld
	// 11 - 6 = 5
	if (tmp == NULL)
		return (NULL);
	free(*save);
	*save = tmp;
	free(*tmp);
	return (next_line);
}

char	*ft_read_and_save(void)
{
	char	*ret;

	return (ret);
}
