#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *rtn;

	rtn = malloc(count * size);
	if (!rtn)
		return (NULL);
	ft_bzero(rtn, size * count);
	return (rtn);
}
