/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   based_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 22:17:15 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/16 15:06:38 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(va_list argl)
{
	char	c;
	int		i;

	c = va_arg(argl, int);
	i = write_chr(c);
	return (i);
}

int	write_s(va_list argl)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(argl, char *);
	if (!s)
		return (write_str("(null)"));
	i = write_str(s);
	return (i);
}

int	write_int(va_list argl)
{
	long	n;
	int		i;

	i = 0;
	n = va_arg(argl, signed int);
	if (n < 0)
	{
		n *= -1;
		i += write_chr('-');
	}
	i += base_conv("01234567890", 10, n);
	return (i);
}

int	write_unint(va_list argl)
{
	unsigned int	n;

	n = va_arg(argl, unsigned int);
	n = base_conv("01234567890", 10, n);
	return (n);
}
