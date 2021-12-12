/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jim <jim@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:32:31 by jim               #+#    #+#             */
/*   Updated: 2021/12/12 18:22:15 by jim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_SIZE 256
# define TRUE 1
# define FALSE 0

# include <unistd.h>
# include <stdlib.h>

// it must be removed
#include <stdio.h>

/* orign */
char	*get_next_line(int fd);
char	*get_next_line_from_save(char **save, int newline_idx);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
/* util */
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char **s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_strchr(const char *s, int c);

#endif
