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

void	push_swap(t_table *t, int argc)
{
	if (is_sorted(t))
		return ;
	if (argc <= 5)
		return ;
	// 	sort_small(t);
	// else
	// 	sort(t);
}

int	main(int argc, char **argv)
{
	t_table *table;

	table = NULL;
	if (argc <= 2)
		return (0);
	check_input(&argv[1]);
	table = t_init(table, argc - 1, argv);
	if(!table)
		write_error(table);
	push_swap(table, argc - 1);
	//ADD
	free_table(table);
	return (0);
}
