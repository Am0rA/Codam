#include "libft.h"

void *ft_memset (void *s, int c, size_t n)
{
	unsigned const char	*rtn;

	rtn = (unsigned char *)s;
	while (n-- > 0)
		rtn[n] = c;
	return (rtn);
}