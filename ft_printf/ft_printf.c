/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 01:02:26 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/24 16:30:54 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_percent(void)
{
	write_chr('%');
	return (1);
}

static size_t	imp_func(char format, va_list argl)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += write_c(argl);
	else if (format == 's')
		len += write_s(argl);
	else if (format == 'p')
		len += write_hex_p(argl);
	else if (format == 'i' || format == 'd')
		len += write_int(argl);
	else if (format == 'u')
		len += write_unint(argl);
	else if (format == 'x')
		len += write_hex_x(argl);
	else if (format == 'X')
		len += write_hex_x_up(argl);
	else if (format == '%')
		len += write_percent();
	else
		len += write(1, &format, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	ret_val;
	va_list	argl;
	int		i;

	i = 0;
	ret_val = 0;
	va_start(argl, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ret_val += imp_func((char)format[i + 1], argl);
			i++;
		}
		else
			ret_val += write(1, &format[i], 1);
		i++;
	}
	va_end(argl);
	return (ret_val);
}
