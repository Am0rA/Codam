/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 22:06:13 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/24 16:30:00 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_hex_p(va_list argl)
{
	unsigned long	n;
	int				len;

	len = 2;
	n = va_arg(argl, unsigned long int);
	if (!n)
		return (write_str("0x0"));
	write(1, "0x", 2);
	len += base_conv("0123456789abcdef", 16, n);
	return (len);
}

int	write_hex_x(va_list argl)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(argl, unsigned int);
	len += base_conv("0123456789abcdef", 16, n);
	return (len);
}

int	write_hex_x_up(va_list argl)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(argl, unsigned int);
	len += base_conv("0123456789ABCDEF", 16, n);
	return (len);
}
