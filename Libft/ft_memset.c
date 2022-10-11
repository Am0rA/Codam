/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:02:14 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/10 18:17:55 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*rtn;

	rtn = (unsigned char *)s;
	while (n-- > 0)
		rtn[n] = c;
	return (rtn);
}
