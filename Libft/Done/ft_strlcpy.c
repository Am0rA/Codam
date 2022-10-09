<<<<<<< HEAD
#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || !src)
		return (0);
	while (*src && size - 1 > 0)
	{
		*dst = *src;
		*src++;
		*dst++;
		size--;
	}
	*dst = '\0';
	return (srclen);
=======
#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dst || !src)
		return (0);
	while (*src && size - 1 > 0)
	{
		*dst = *src;
		*src++;
		*dst++;
		size--;
	}
	*dst = '\0';
	return (srclen);
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}