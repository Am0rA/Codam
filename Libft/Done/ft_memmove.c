#include "libft.h"

void *ft_memmove(void *dst, void const *src, size_t n)
{
	unsigned const char	*s;
	unsigned const char	*d;

	s = (unsigned const char *)src;
	d = (unsigned const char *)dst;
	if (s == NULL || d == NULL)
		return (0);
	d = (void *)ft_strncpy(dst, src, n);
	return (d);
}