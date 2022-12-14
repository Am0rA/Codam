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

t_table	*t_init(t_table *t, int size, char **argv)
{
	t_circular	*n;
	int			i;

	i = 0;
	t = malloc(sizeof(t_table));
	if (!t)
		return (NULL);
	t->a_head = NULL;
	t->b_head = NULL;
	while (i++ < size)
	{
		n = new_node(ft_atoi(argv[i]));
		if (!insert_back(&(t->a_head), &n))
			return (NULL);
	}
	return (t);
}
