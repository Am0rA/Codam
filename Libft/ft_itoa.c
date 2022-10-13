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

int	len_in(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = len_in(n);
	ret = malloc(sizeof(char) * (len + 1));
	if (n < 0)
	    n *= -1;
	while (i < len)
	{
		ret[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	if (len == 0)
	{
		ret[i] = '0';
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
