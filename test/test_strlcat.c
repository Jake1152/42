#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char const *s1);

/* */
int main()
{
	char *dest_st;
	char *dest_ft;
	if (!(dest_st = (char *)malloc(sizeof(*dest_st) * 15)))
		return (0);
	if (!(dest_ft = (char *)malloc(sizeof(*dest_ft) * 15)))
		return (0);
	memset(dest_st, 0, 15);
	memset(dest_st, 'r', 6);
	memset(dest_ft, 0, 15);
	memset(dest_ft, 'r', 6);

	strlcat(dest_st, "lorem ipsum dolor sit amet", 5);
	// ft_strlcat(dest_ft, "lorem ipsum dolor sit amet", 5);
	printf("%s \n", dest_st);
	// printf("%s \n", dest_ft);
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