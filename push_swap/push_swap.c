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

void	push_swap(int c, char **v)
{
	t_table	*table;

	int i = 0;
	table = NULL;
	if (!t_init(table, c, v))
		write_error(table);
	while (i < 5 && table->a)
	{
		printf("HELLO");
		printf("%d\n", table->a->content);
		table->a = table->a->next;
		i++;
	}
	// if (!is_sorted(table->a))
	// 	sort(table);
	free_table(table);
}

int	main(int argc, char **argv)
{
	argc--;
	if (argc <= 1)
		return (0);
	check_input(argv);
	//if (argc < 7)
	// 	solve_simple(argc, argv);
	//else if (argc >= 5)
		push_swap(argc, &argv[1]);
	return (0);
}
