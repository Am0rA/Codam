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
	int		check;
	t_table	*table;

	if (size < 1)
		exit(0);
	check = 1;
	table = t_init();
	if (!table)
		return (NULL);
	fill_list(table, args, size);
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
	while (c)
	{
		printf("%ld", table->a->num);
		table->a = table->a->next;
		c--;
	}
	free_table(table);
}

int	main(int argc, char **argv)
{
	int	check;

	check = check_input(NULL, argv);
	if (argc <= 2)
		return (0);
	// else if (argc < 6 && check == 1)
	// 	solve_simple(argc, argv);
	else if (argc >= 6 && check == 1)
		push_swap(argc, argv);
	return (0);
}
