/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   base_conv.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 22:34:30 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/16 15:06:26 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_zero(unsigned long n);
char		*buffer_size(int base, unsigned long n);
static int	write_zero(unsigned long n);

int	base_conv(const char *set, int base, unsigned long n)
{
	char	*buffer;
	int		c;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (write_zero(n))
		return (1);
	buffer = buffer_size(base, n);
	if (!buffer)
		return (0);
	while (n != 0)
	{
		c = n % base;
		buffer[i] = set[c];
		n /= base;
		i++;
	}
	while (i-- > 0)
		len += write_chr(buffer[i]);
	free(buffer);
	return (len);
}

static int	write_zero(unsigned long n)
{
	if (n == 0)
	{
		write_chr('0');
		return (1);
	}
	return (0);
}

char	*buffer_size(int base, unsigned long n)
{
	int		len;
	char	*buffer;

	len = 1;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[len] = '\0';
	return (buffer);
}
