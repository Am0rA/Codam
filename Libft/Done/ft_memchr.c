<<<<<<< HEAD
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		counter;
	char const	*buffer;

	buffer = (char const *)s;
	counter = 0;
	while (counter < n)
	{
		if (buffer[counter] == c)
			return ((void *)(s + counter));
		counter++;
	}
	return (NULL);
}
=======
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		counter;
	char const	*buffer;

	buffer = (char const *)s;
	counter = 0;
	while (counter < n)
	{
		if (buffer[counter] == c)
			return ((void *)(s + counter));
		counter++;
	}
	return (NULL);
}
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
//CHECK AGAIN