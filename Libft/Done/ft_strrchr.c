<<<<<<< HEAD
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
=======
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
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}