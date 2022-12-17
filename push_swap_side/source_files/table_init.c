/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:49:40 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:49:40 by itopchu       ########   odam.nl         */
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
	while (i < size)
	{
		n = new_node(ft_atoi(argv[i]));
		if (!insert_back(&(t->a_head), &n))
			return (NULL);
		i++;
	}
	return (t);
}
