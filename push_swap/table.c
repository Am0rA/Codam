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

int t_init(t_table *t, int size, char **argv)
{
	int	i;

	i = 0;
	t = (t_table *)malloc(sizeof(t_table));
	if (!t)
		return (0);
	t->a = new_node(ft_atoi(argv[i]));
	if (!(t->a))
		return (0);
	i++;
	t->a->head = 1;
	t->a->next = t->a;
	t->a->prev = t->a;
	while (i <= size)
	{
		if (!insert_back(&(t->a), new_node(ft_atoi(argv[i]))))
			return (0);
		i++;
	}
	return (1);
}
