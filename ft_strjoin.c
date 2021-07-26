#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str;

    str = (char *)malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (0);
    return (str);
}
