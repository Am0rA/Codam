/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 22:06:13 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/23 22:06:13 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_hex_p(va_list argl)
{
	unsigned long	n;
	int				len;

	len = 2;
	n = va_arg(argl, unsigned int);
	if (!n)
		return (write_str("NULL"));
	write(1, "0x", 2);
	len += base_conv("01234567890ABCDEF", 16, n);
	return (len);
}

int	write_hex_x(va_list argl)
{
	unsigned int	n;
	int				len;

	len = 0;
	n = va_arg(argl, unsigned int);
	len += base_conv("01234567890ABCDEF", 16, n);
	return (len);
}
