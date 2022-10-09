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
//CHECK AGAIN