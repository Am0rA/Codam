/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_assign.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:41:00 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:41:00 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_dist(t_circular *l)
{
	int	a;
	int	b;

	a = l->dist_a;
	b = l->dist_b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	l->dist = a + b;
}

void	path_assign(t_table	*t)
{
	t_circular	*tmp;

	tmp = t->b_head;
	tmp->dist_a = path_in_a(t->a_head, tmp);
	tmp->dist_b = path_in_b(t->b_head, tmp);
	tmp = tmp->next;
	while (tmp != t->b_head)
	{
		tmp->dist_a = path_in_a(t->a_head, tmp);
		tmp->dist_b = path_in_b(t->b_head, tmp);
		tmp = tmp->next;
		set_dist(tmp);
	}
}
