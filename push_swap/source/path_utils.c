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

int path_in_a(t_tail *l, t_tail *obj)
{
    t_tail	*current;
    t_tail	*target;
    int		steps;
	int		len;

	len = list_len(l);
	steps = 0;
	current = l;
	if (next_biggest(l, NULL)->value < obj->value)
		target = next_smallest(l, NULL);
	else
		target = next_biggest(l, obj);
    while (current && current != target)
    {
		current = current->next;
        steps++;
    }
	if (steps * 2 > len)
		return (steps - len);
	return (steps);
}

int	path_in_b(t_tail *l, t_tail *obj)
{
	t_tail	*current;
	int		steps;
	int		len;

	steps = 0;
	current = obj;
	len = list_len(l);
	while (current->next != NULL)
	{
		steps++;
		current = current->next;
	}
	if (steps * 2 > len)
		return (steps - len);
	return (steps);
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
