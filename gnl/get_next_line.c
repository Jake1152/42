/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:47:35 by jim               #+#    #+#             */
/*   Updated: 2021/12/08 19:08:58 by jim              ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUFFER_SIZE 42
#define FD_SIZE 256

char	*get_next_line(int fd)
{
	static char		*static_save[FD_SIZE];
	char			read_str[BUFFER_SIZE + 1];
	char			*new_line_str;
	char			*tmp;
	int				read_str_len;

	read_str_len = 0;
	static_save[fd] = ft_strdup("");
	if (static_save[fd] == NULL)
		return (NULL);
	while (TRUE)
	{
		// 개행확인
		new_line_str = ft_ret_newline();
		if (new_line_str != NULL)
			return (new_line_str);
		// read
		read_str_len = read(fd, read_str, BUFFER_SIZE);
		if (read_str_len <= 0 && static_save[fd] == "")
			break ;
		read_str[read_str_len] = '\0';
		tmp = ft_strjoin(static_save[fd], read_str);
		static_save[fd] = tmp;
		free(tmp);
	}
	// 
	if ((ft_strncmp(static_save[fd], "", 1) > 0) && read_str_len == 0)
		return (static_save[fd]);
	return (NULL);
}

char	*ft_ret_newline(void)
{
	char	*new_line_str;
	char	*tmp;
	size_t	new_len;
	size_t	save_len;
	char	*new_line_posi;
	extern	static_save[fd];

	new_line_posi = ft_strchr(static_save[fd], '\n');
	save_len = ft_strlen(static_save[fd]);
	if (new_line_posi != NULL)
	{
		new_len = new_line_posi - static_save[fd] + 1;
		new_line_str = ft_alloc(new_len + 1);
		ft_strlcpy(new_line_str, static_save[fd], new_len);
		tmp = ft_alloc(save_len - new_len + 1);
		ft_strlcpy(tmp, static_save[fd] + new_len, save_len - new_len + 1);
		free(static_save[fd]);
		static_save[fd] = tmp;
		free(tmp);
		free(static_save[fd]);
		static_save[fd] = ft_strdup("");
		printf("static_save[fd] : %s\n", static_save[fd] );
		return (new_line_str);
	}
}

char	*ft_alloc(int size)
{
	char	*ret_str;

	ret_str = (char *)malloc(sizeof(char) * (size));
	if (ret_str == NULL)
		return (NULL);
	return (ret_str);
}

char	*ft_save(char *s1, char *s2)
{
	/*
		s1, s2를 넘겨받아서 새로운 변수에 저장한다.
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
