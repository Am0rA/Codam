#include "libft.h"

int	ft_atoi(char const *str)
{
	int	i;
	int	minus;
	int out;

	i = 0;
	minus = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' && str[i])
	{
		minus = -1;
		i++;
	}
	while (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		out = (out * 10) + str[i] - '0';
		i++;
	}
	return (out * minus);
}
