#include "libft.h"

void *ft_memset (void *s, int c, size_t n)
{
	unsigned char	*rtn;
	size_t			i;

	i = 0;
	rtn = (unsigned char *)s;
	//rtn[n] = '\0';
	while (n-- > 0)
		rtn[n] = c;
	return (rtn);
}