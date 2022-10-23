/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 01:02:26 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/23 01:02:26 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_percent()
{
	write(1, '%', 1);
	return (1);
}

static int	static_in_set(char c)
{
	char	*set;

	set = "cspdiuxX%";
	while (*set++)
		if (*set == c)
			return (1);
	return (0);
}

static size_t	imp_func(const char *format, va_list argl)
{
	size_t	len;

	len = 0;
	if (*format == 'c')
		len += write_c(argl);
	else if (*format == 's')
		len += write_s(argl);
	else if (*format == 'p')
		len += write_hex_p(argl);
	else if (*format == 'i' || *format == 'd')
		len += write_int(argl);
	else if (*format == 'u')
		len += write_unint(argl);
	else if (*format == 'x' || *format == 'X')
		len += write_hex_x(argl);
	else if (*format == '%')
		len += write_percent(argl);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	ret_val;
	va_list	argl;

	ret_val = 0;
	va_start(argl, format);
	while (*format++)
		if (*(++format) == '%')
			if (static_in_set(format))
				ret_val += imp_func(format, argl);
		else
			ret_val += char_put(format);
	va_end(argl);
	return (ret_val);
}
