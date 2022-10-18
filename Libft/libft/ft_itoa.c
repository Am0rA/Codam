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

int	static	len_in(int long n)
{
	int	ret;

	ret = 1;
	while (n > 9)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

void static	fill(char	*ret, int sign, int long n, int len)
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
	char		*ret;
	int			len;
	int			sign;
	int long	l;

	l = n;
	sign = 1;
	if (l < 0)
	{
		sign = -1;
		l *= sign;
	}
	len = len_in(l);
	if (n < 0)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	fill(ret, sign, l, len);
	return (ret);
}
