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

	ret = 1;
	if (n < 0)
	{
		n *= -1;
		ret++;
	}
	while (n >= 10)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

void static	fill(char	*ret, int sign, int n, int len)
{
	if (sign < 0)
		ret[0] = '-';
	ret[len] = '\0';
	len--;
	while (len >= 0 && ret[len] != '-')
	{
		ret[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		sign;
	int		len;

	if (n == -2147483648)
	{
		ret = ft_strdup("-2147483648");
		return (ret);
	}
	len = len_in(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= sign;
	}
	fill(ret, sign, n, len);
	return (ret);
}
