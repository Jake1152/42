
#include <stdlib.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	str = (char *)malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (0);
	while (len--)
	{
		if (*s == start)
			ft_strlcpy(str, s, len+1);
			return (str);
		s++;
	}
	return (0);
}