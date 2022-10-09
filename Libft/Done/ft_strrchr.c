#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int	index;

	index = ft_strlen(s);
	while (s[index])
	{
		if (s[index] == c)
			return (&s[index]);
		index--;
	}
	return (NULL);
}