#include "push_swap.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (ac <= 2)
		return (0);
	check(&av[1]);
	table = table_init(ac, av);
	if (sorted(table->a, 'a'))
		return (0);
	push_swap(table);
	free_table(table);
	return (0);
}