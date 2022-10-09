<<<<<<< HEAD
#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
=======
#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
