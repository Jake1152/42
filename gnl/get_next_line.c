/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:35 by jim               #+#    #+#             */
/*   Updated: 2021/12/09 19:30:16 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	static char		*static_save[FD_SIZE];
	char			read_str[BUFFER_SIZE + 1];
	char			*new_line_str;
	int				read_str_len;

	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	static_save[fd] = ft_strdup("");
	if (static_save[fd] == NULL)
		return (NULL);
	while (TRUE)
	{
		new_line_str = ft_ret_newline(&(static_save[fd]));
		if (new_line_str != NULL)
			return (new_line_str);
		read_str_len = read(fd, read_str, BUFFER_SIZE);
		// read는 0 이하인데 static에 data가 남아 있는 경우의 처리 
		if (read_str_len <= 0 && (static_save[fd] == "" || static_save[fd] == NULL))
			break ;
		read_str[read_str_len] = '\0';
		// ft_save() static에 저장하는 역할 만약 실패하면 return NULL하고 종료
	}
	if (static_save[fd] != "" && read_str_len == 0)
		return (static_save[fd]);
	return (NULL);
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
		new_line_str = ft_alloc(new_len + 1);
		ft_strlcpy(new_line_str, *save, new_len + 1);
		tmp = ft_alloc(save_len - new_len + 1);
		if (tmp == NULL)
			return (NULL);
		ft_strlcpy(tmp, (*save + new_len), save_len - new_len + 1);
		// "hello\nworld"
		free(*save);
		*save = tmp;
		free(tmp);
		// printf("save : %s\n", save);
	}
	return (new_line_str);
}

char	*ft_alloc(int size)
{
	char	*ret_str;

	ret_str = (char *)malloc(sizeof(char) * (size));
	if (ret_str == NULL)
		return (NULL);
	return (ret_str);
}

int		*ft_save(char **save, char *read_str)
{
	char	*tmp;

	tmp = ft_strjoin(save, read_str);
	if (tmp == NULL)
		return (NULL);
	*save = tmp;
	free(tmp);
	/*
		s1, s2를 넘겨받아서 새로운 변수에 저장한다.
		s1은 static
	*/
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
