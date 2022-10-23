/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/23 02:54:46 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/23 02:54:46 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	me[] = "My texts Begins here:\n";
	char	he[] = "His texts begings here:\n";
	printf("%s\n", he);
	printf("%%\n");
	printf("%c\n", '%c');
	printf("%s\n", "%s Some String");
	printf("%d, %d\n", 0, 4294967295);
	printf("%i, %i\n", -2147483648, 2147483647);
	printf("%u, %u\n", 0, 4294967295);
	// printf("%p\n", );
	// printf("%x\n", );
	// printf("%X\n", );

	ft_printf("%s\n", me);
	ft_printf("%%\n");
	ft_printf("%c\n", '%c');
	ft_printf("%s\n", "%s Some String");
	ft_printf("%d, %d\n", 0, 4294967295);
	ft_printf("%i, %i\n", -2147483648, 2147483647);
	ft_printf("%u, %u\n", 0, 4294967295);
	// ft_printf("%p\n", );
	// ft_printf("%x\n", );
	// ft_printf("%X\n", );
	return (0);
}