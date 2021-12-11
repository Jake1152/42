/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:35 by jim               #+#    #+#             */
/*   Updated: 2021/12/11 16:05:04 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char		*static_save[FD_SIZE];
	char			read_str[BUFFER_SIZE + 1];
	char			*newline_str;
	int				read_str_len;

	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	static_save[fd] = ft_strdup("");
	if (static_save[fd] == NULL)
		return (NULL);
	while (TRUE)
	{
		printf("static_save[fd] in start of gnl: %s\n", static_save[fd]);
		newline_str = ft_ret_newline(&(static_save[fd]));
		printf("newline_str : %s\n", newline_str);
		printf("static_save[fd] after found newline : %s\n", static_save[fd]);
		if (static_save[fd] == NULL)
			return (NULL);
		if (newline_str != NULL)
			return (newline_str);
		read_str_len = read(fd, read_str, BUFFER_SIZE);
		printf("read_str_len : %d\n", read_str_len);
		if (read_str_len <= 0)
			break ;
		read_str[read_str_len] = '\0';
		static_save[fd] = ft_save(&static_save[fd], read_str);
		printf("static_save[fd] in middle of gnl : %s\n", static_save[fd]);
		if (static_save[fd] == NULL)
			return (NULL);
	}
	if (ft_strlen(static_save[fd]) == 0 && read_str_len == 0)
		return (static_save[fd]);
	return (NULL);
}

char	*ft_save(char **save, char *read_str)
{
	char	*str_join;
	size_t	read_len;
	size_t	save_len;

	save_len = ft_strlen(*save);
	read_len = ft_strlen(read_str);
	str_join = (char *)malloc(save_len + read_len + 1);
	printf("save_len, read_len : %zu %zu \n", save_len, read_len);
	if (str_join == NULL)
		return (NULL);
	printf("*save : %s \n", *save);
	ft_strlcpy(str_join, *save, save_len + 1);
	free(*save);
	ft_strlcat(str_join, read_str, save_len + read_len + 1);
	printf("str_join : %s\n", str_join);
	return (str_join);
}

char	*ft_ret_newline(char **save)
{
	char	*new_line_str;
	char	*tmp;
	size_t	new_len;
	size_t	save_len;
	char	*new_line_posi;

	new_line_posi = ft_strchr(*save, '\n');
	save_len = ft_strlen(*save);
	new_line_str = NULL;
	if (new_line_posi != NULL)
	{
		new_len = new_line_posi - *save + 1;
		new_line_str = (char *)malloc(new_len + 1);
		if (new_line_str == NULL)
			return (NULL);
		ft_strlcpy(new_line_str, *save, new_len + 1);
		tmp = (char *)malloc(save_len - new_len + 1);
		if (tmp == NULL)
			return (NULL);
		ft_strlcpy(tmp, (*save + new_len), save_len - new_len + 1);
		free(*save);
		*save = tmp;
		free(tmp);
	}
	return (new_line_str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	if (s[idx] == (char)c)
		return ((char *)&s[idx]);
	return (NULL);
}
