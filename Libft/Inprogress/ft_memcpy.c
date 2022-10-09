#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	while (dest++ && n > 0)
	{
		dest = src;
		n--;
	}
}