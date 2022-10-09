#include "libft.h"

size_t  ft_strlcat(char *dst, char const *src, size_t size)
{
    size_t i;
    size_t j;

    i = 0;
    j = ft_strlen(dst);
    if (size <= j)
        return (size + ft_strlen(src));
    while (src[i] && j + 1 < size)
    {
        dst[j + i] = src[i];
        i++;
    }
    dst[j + i] = '\0';
    return (j + ft_strlen(&src[i]));
}
