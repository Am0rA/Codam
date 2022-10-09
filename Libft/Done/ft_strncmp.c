#include "libft.h"

int ft_strncmp(char const *s1, char const *s2, size_t n)
{
    size_t  i;

    i = 0;
    if (n == 0)
        return (0);
    while ((s1[i] && s2[i]) && i < n - 1)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
