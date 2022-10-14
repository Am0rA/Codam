/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:00:51 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:00:51 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	static	len_in(int n)
{
	int	ret;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	ret = 0;
	if (n < 0)
	{
		n *= -1;
		ret++;
	}
	if (n >= 10)
	{
		ret = len_in(n / 10);
		ret++;
	}
	if (n < 10)
	{
		ret++;
	}
	return (ret);
}

char static	*ft_return(int n)
{
	if (n == -2147483648)
		return ("-2147483648");
	else if (n == 0)
		return ("0");
	return (NULL);
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			len;
	int			i;

	len = len_in(n);
	ret = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (ft_return(n) != NULL)
		return (ft_return(n));
	if (n < 0)
	{
		ret[0] = '-';
		n *= -1;
	}
	while (i < len)
	{
		ret[len - 1 - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
