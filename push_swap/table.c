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

t_circular	*l_init(char **args, int size)
{
	t_circular	*new;
	t_circular	*l;
	int			i;

	i = 0;
	if (args[i])
		l = list_new(ft_atoi(args[i]));
	l->head = 1;
	printf("index: %i %d\n", i, l->content);
	i++;
	while (i < size && l)
	{
		if (args[size])
			new = list_new(ft_atoi(args[size]));
		if (!new)
			return (NULL);
		printf("index: %i %d\n", i, l->content);
		list_add_front(&l, new);
		i++;
	}
	l->prev = list_last(l);
	l = list_last(l)->next;
	return (l);
}

t_table	*t_init(int size, char **args)
{
	t_table	*t;

	t = malloc(sizeof(t_table));
	if (!t)
		write_error(t);
	t->a = l_init(args, size);
	if (!(t->a))
		write_error(t);
	return (t);
}
