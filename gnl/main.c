#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

// #define BUFFER_SIZE 10
#define FD_SIZE 256

// char	*get_next_line(int fd);
// char	*ft_strdup(const char *s1);
// char	*ft_strjoin(char const *s1, char const *s2);
// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// size_t	ft_strlen(const char *s);

int main()
{
	int		fd;
	// int		ret;
	// char	*str1;
	// char	*str2;
	char	*line;
	// char	*join_Sstr;

	// printf("test\n");
	// str1 = "Hello ";
	// str2 = "World!";
	// join_str = ft_strjoin(str1, str2);
	// printf("result is : \n%s\n", join_str);
	line = NULL;
	fd = open("the_document", O_RDWR, 0777);
	printf("fd : %d\n", fd);
	//ret = read(0, line, 5);
	//printf("ret %d\n", ret);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("Done\n");
			break ;
		}
		printf("line is :%s\n", line);
	}
	close(fd);
	// 이렇게하면 get_next_line(fd)에서 동적할당한 결과를 반환해야한다.
	// 그렇다면 free는 어떻게 하는가?
	// 밖에서 할당한다음에 넘겨주는게 효율적일거 같다.
	// 안에서 동적할당하지 않고 넘겨주어도 받을 수 있는가?
	// 혹시 동적할당해서 넘기기, 로컬변수 넘기기 둘 말고 다른 방식이 있는가?

	// fd가 여러개일 가능성을 생각해야한다.
	// 여러개일때도 꼬이지않고 되어야한다.
	// 그렇다면 미리 배열을 만들거나 다른 자료구조를 써야한다. 
	// 연결리스트, BST
	// ssize_t	read(int fildes, void *buf, size_t nbyte);	
	

	
	return (0);
}


/*

char	*get_next_line(int fd)
{
	static char		*static_str;
	char			*str;
	int				fd_table[FD_SIZE];
	size_t			str_len;
	char			buf[BUFFER_SIZE];

	str_len = 0;
	if (fd == -1)
		return (NULL);
	fd_table[fd] = fd;
	printf("fd_table[fd] %d\n", fd_table[fd]);
	// while (fd_table[fd] != -1)  // 일단 이것을 넣으면 무한루프, read에서 읽은게 남았는지 봐야한다. 
	{
		str_len = read(fd_table[fd], buf, BUFFER_SIZE);
		buf[str_len] = 0;		
		printf("str_len %zu\n", str_len);
		while (str_len > 0)
		{
			printf("%s\n", buf);
			//ft_strdup(str);
			return (buf);
			// printf("%s\n", str);
			// str에 \n이 있는 곳까지 읽는다.

		}
	}
	return (NULL);
}


size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	idx;
	size_t	s1_size;

	s1_size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (s1_size + 1));
	if (dest == 0)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		dest[idx] = s1[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	dstsize;

	dstsize = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(sizeof(char) * (dstsize));
	if (!dst)
		return (0);
	ft_strlcpy(dst, s1, ft_strlen(s1) + 1);
	ft_strlcat(dst, s2, dstsize);
	return (dst);
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


*/
