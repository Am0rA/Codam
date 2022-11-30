/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 16:14:44 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/30 16:14:44 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_list(t_table *t, char **args, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		t->a->num = ft_atoi(args[i]);
		t->a = t->a->next;
		i++;
	}
}

t_table	*t_init(unsigned int size)
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
