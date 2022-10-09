<<<<<<< HEAD
#include "libft.h"

void *ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned const char	*d;
	unsigned const char	*s;

	d = (unsigned const char *)dst;
	s = (unsigned const char *)src;
	if (s == NULL || d == NULL)
		return (0);
	while (n)
	{
		d[i] = s[i];
		n--;
	}
	return (dst);
=======
#include "libft.h"

void *ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned const char	*d;
	unsigned const char	*s;

	d = (unsigned const char *)dst;
	s = (unsigned const char *)src;
	if (s == NULL || d == NULL)
		return (0);
	while (n)
	{
		d[i] = s[i];
		n--;
	}
	return (dst);
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}