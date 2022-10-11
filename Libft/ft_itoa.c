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

int	static	nbr_len(int nb, char *ret)
{
	int	i;

	i = 0;
	if (nb > 0)
	{
		i = nbr_len(nb / 10, ret);
	}
	ret[i] = (nb % 10) + '0';
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;

	ret = NULL;
	len = nbr_len(n, ret);
	ret = malloc(sizeof(char) * (len + 1));
	ret[ft_strlen(ret)] = '\0';
	return (ret);
}
