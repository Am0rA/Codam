<<<<<<< HEAD
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
=======
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
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
