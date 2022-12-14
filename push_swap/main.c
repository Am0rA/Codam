/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 21:48:38 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/13 22:01:52 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;

	if (ac <= 2)
		return (0);
	check_input(&av[1]);

	table = t_init(table, ac - 1, &av[1]);
	if (!table)
		write_error(table);

	push_swap(table, ac - 1);

	free_table(table);
	return (0);
}
