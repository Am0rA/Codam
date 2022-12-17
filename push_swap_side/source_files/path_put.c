/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_put.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 01:23:43 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 01:23:43 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	place_anchor(t_table *t, t_circular **anchor)
{
	while ((*anchor)->dist_a != 0 || (*anchor)->dist_b != 0)
	{
		if ((*anchor)->dist_a < 0)
			rotate(anchor, 'a');
		else if ((*anchor)->dist_a > 0)
			rotate_reverse(anchor, 'a');
		if ((*anchor)->dist_b < 0)
			rotate(anchor, 'b');
		else if ((*anchor)->dist_b > 0)
			rotate_reverse(anchor, 'b');
	}
	push(&(t->a_head), &(t->b_head), 'a');
}

void	place_in_a(t_table *t)
{
	t_circular	*tmp;
	t_circular	*anchor;

	while (t->b_head)
	{
		tmp = t->b_head->next;
		anchor = t->b_head;
		while (tmp != t->b_head)
		{
			if (tmp->dist < anchor->dist)
				anchor = tmp;
			tmp = tmp->next;
		}
		place_anchor(t, &anchor);
	}
}
