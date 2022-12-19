/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 22:04:36 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 22:04:36 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	path_in_a(t_tail *l, t_tail *prev)
{
	t_tail	*tmp;
	t_tail	*next;
	int		i;
	int		len;

	i = 0;
	len = list_len(l);
	tmp = l;
	next = next_smallest(l, prev);
	while (tmp != next)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < len/2)
		return (i);
	return (-1*(len - i));
}

int	path_in_b(t_tail *l, t_tail *obj)
{
	t_tail	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = obj;
	len = list_len(l);
	while (tmp != l)
	{
		i++;
		tmp = tmp->prev;
	}
	if (i < len/2)
		return (-i);
	return (len - i);
}
static void	set_dist(t_tail *l)
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
	t_tail	*tmp;

	tmp = t->b_head;
	while (tmp)
	{
		tmp->dist_a = path_in_a(t->a_head, tmp);
		tmp->dist_b = path_in_b(t->b_head, tmp);
		set_dist(tmp);
		tmp = tmp->next;
	}
}
