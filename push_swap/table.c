/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 16:14:44 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 21:26:53 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	t_int_l_init(t_int_l *l, char **args, int size)
{
	t_int_l	*first;
	int		i;

	i = 0;
	first = l;
	while (i < size - 1)
	{
		if (args)
			l->num = ft_atoi(args[i]);
		if (i != size - 2)
			l->next = malloc(sizeof(t_int_l));
		if (l->next == NULL)
			return (0);
		l->prev = l;
		i++;
	}
	l->next = first;
	return (1);
}

void	fill_list(t_table *t, char **args, int size)
{
	int	check;

	check = t_int_l_init(t->a, args, size);
	if (!check)
		write_error(t);
	check = t_int_l_init(t->b, NULL, size);
	if (!check)
		write_error(t);
}

t_table	*t_init(void)
{
	t_table	*table;

	table = malloc(sizeof(*table));
	if (!table)
		return (NULL);
	table->a = malloc(sizeof(*(table->a)));
	if (!(table->a))
		return (free_table(table), NULL);
	table->b = malloc(sizeof(*(table->b)));
	if (!(table->b))
		return (free_table(table), NULL);
	return (table);
}
