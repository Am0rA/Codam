#include "libft.h"

int	static nbr_len(int nb, char *ret)
{
	int	i;

	i = 0;
	if (nb > 0)
	{
		i = nbr_len(nb / 10);
	}
	ret[i] = (nb % 10) + '0';
	return (i);
}
char *ft_itoa(int n)
{
	char	*ret;
	*ret = malloc(sizeof(char) * (nbr_len(n, *ret) + 1);
	ret[ft_strlen(ret)] = '\0';
	return (ret);
}