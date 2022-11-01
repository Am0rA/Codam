/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:01:22 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:01:22 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*b1;
	unsigned char		*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	if (b1 == NULL && b2 == NULL)
		return (0);
	while (n)
	{
		if (*b1 != *b2)
			return (*b1 - *b2);
		b1++;
		b2++;
		n--;
	}
	return (0);
}
