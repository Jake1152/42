#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char const *s1);

/* */
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



char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || s + ft_strlen(s) <= s + start)
		return (0);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
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