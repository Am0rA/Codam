/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 18:03:59 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 21:36:18 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_table	*get_table(int size, char **args)
{
	t_table	*table;

	table = t_init(size, args);
	if (!table)
		return (NULL);
	return (table);
}

void	push_swap(int c, char **v)
{
	t_table	*table;

	table = get_table(c - 1, &v[1]);
	if (!table)
		exit(-1);
	// if (!is_sorted(table))
	// 	sort(table);
	free_table(table);
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		exit(-1);
	check_input(argv);
	if (argc <= 2)
		return (0);
	// else if (argc < 6)
	// 	solve_simple(argc, argv);
	else if (argc >= 6)
		push_swap(argc, argv);
	return (0);
}
