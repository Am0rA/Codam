/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 14:51:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/23 14:51:10 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
//base_conv.c
int				base_conv(const char *set, int base, unsigned long n);
char			*buffer_size(char *buffer,int base, unsigned long n);
static int		write_zero(unsigned long n);
//based_int.c
int				write_c(va_list argl);
int				write_s(va_list argl);
int				write_int(va_list argl);
int				write_unint(va_list argl);
//hex.c
int				write_hex_p(va_list argl);
int				write_hex_x(va_list argl);
//write.c
int				write_chr(char c);
int				write_str(const char *s);
//printf.c
int				write_percent();
static int		static_in_set(char c);
static size_t	imp_func(const char *format, va_list argl);
int				ft_printf(const char *format, ...);
#endif