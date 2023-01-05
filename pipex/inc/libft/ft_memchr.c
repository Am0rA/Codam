/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:01:06 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:01:06 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*buffer;
	unsigned char	cr;
	void			*rtn;

	buffer = (unsigned char *)s;
	cr = (unsigned char)c;
	rtn = (void *)s;
	counter = 0;
	while (counter < n)
	{
		if (buffer[counter] == cr)
			return (rtn += counter);
		counter++;
	}
	return (NULL);
}
