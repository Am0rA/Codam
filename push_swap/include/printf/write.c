/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 21:57:34 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/24 14:32:46 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_chr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_str(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i += write_chr(s[i]);
	return (i);
}
