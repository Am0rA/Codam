/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:01:34 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:01:34 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (s == NULL && d == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
		if (n == i)
			return (d);
	}
	return (d);
}
