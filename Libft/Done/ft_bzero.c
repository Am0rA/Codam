<<<<<<< HEAD
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n-- > 0)
		str[n] = '\0';
=======
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n-- > 0)
		str[n] = '\0';
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}