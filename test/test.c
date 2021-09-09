#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char const *s1);

/*
int main()
{
	char	*haystack;
	char	*needle;
	char	*ft_be;
	char	*st_be;
	size_t	len;

	haystack = "  \0";
	needle = " \0";
	// haystack = "aaa b3";
	// needle = "b";
	// haystack = " a";
	// needle = "aa 3";
	len = 4;

	st_be = strnstr(haystack, needle, len);
	ft_be = ft_strnstr(haystack, needle, len);
	printf("%s\n%s\n", st_be, ft_be);
	// printf("%s\n", st_be);
	return (0);
}
*/

int main() {
	char *in1;		// 첫 번째 인자로 넘길 문자열
	char *in2;		// 두 번째 인자로 넘길 문자열
	size_t num;		// 세 번째 인자로 넘길 size_t
	char *temp1;
	char *temp2;	// NULL 값 입력시 원래 자리 회복을 위한 변수

	in1 = (char *)malloc(sizeof(char) * 100);
	in2 = (char *)malloc(sizeof(char) * 100);
	temp1 = in1;
	temp2 = in2;
	while (1)
	{
		printf("usage:\t<in1>\t<in2>\t<num>\n");
		scanf("%s %s %ld", in1, in2, &num);
		if (strncmp(in1, "\\0", 5) == 0)
			strlcpy(in1, "", 1);		// "\0" 가 오면 in1을 빈문자열로 치환
		if (strncmp(in2, "\\0", 5) == 0)
			strlcpy(in2, "", 1);		// "\0" 가 오면 in2를 빈문자열로 치환
		if (strncmp(in1, "NULL", 10) == 0)
			in1 = 0;		// "NULL" 이 오면 in1을 NULL로 치환
		if (strncmp(in2, "NULL", 10) == 0)
			in2 = 0;		// "NULL" 이 오면 in2를 NULL로 치환
		printf("-----input----\n");
		printf("in1:\t#%s#\n", in1);	// input 확인
		printf("in2:\t#%s#\n", in2);
		printf("num:\t#%ld#\n", num);
		printf("----result----\n");		// result 비교
		printf("strnstr:\t#%s#\n", strnstr(in1, in2, num));
		printf("ft_strnstr:\t#%s#\n", ft_strnstr(in1, in2, num));
		printf("--------------\n");
		if (!in1 || !in2)
		{
			in1 = temp1;
			in2 = temp2;
		}
	}
}


char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);	
	while (*haystack && len)
	{
		if (needle_len > len)
			return (0);
		else if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (0);
}


size_t	ft_strlen(char const *s1)
{
	size_t	idx;

	while (s1[idx++])
		;
	return (idx);
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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	if (!un_s1 && !un_s2)
		return (0);
	while (n--)
	{
		if ((*(unsigned char *)un_s1 != *(unsigned char *)un_s2))
			return (*un_s1 - *un_s2);
		un_s1++;
		un_s2++;
	}
	return (0);
}