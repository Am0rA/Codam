/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 21:42:09 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 21:42:09 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_table *table;

	table = NULL;
	if (ac <= 2)
		return (0);
	check_input(&av[1]);
	table_init(&table, ac - 1, &av[1]);
	push_swap(table);
	printlist(table->a_head);
	free_table(table);
	return (0);
}