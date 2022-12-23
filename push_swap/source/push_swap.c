/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 21:57:58 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 21:57:58 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_triple(t_table *t)
{
	if (t->a_head->value > t->a_head->next->value \
		&& t->a_head->value > t->a_head->next->next->value)
		rotate(t, 'a');
	else if (t->a_head->value < t->a_head->next->value)
		rotate_reverse(t, 'a');
	if (t->a_head->value > t->a_head->next->value \
		&& t->a_head->value < t->a_head ->next->next->value)
		swap(t, 'a');
}

static void	place_in_b(t_table *t)
{
	int	i;

	i = list_len(t->a_head);
	while (i > 3 && !sorted(t->a_head, 'a') && t->a_head->next)
	{
		if (t->a_head->value > t->a_head->next->value)
		{
			push(&(t->b_head), &(t->a_head), 'b');
			i--;
		}
		else
			rotate(t, 'a');
	}
	if (list_len(t->a_head) == 3)
		sort_triple(t);
}

static void	place_in_a(t_table *t)
{
	t_tail	*current;
	t_tail	*anchor;

	while (t->b_head)
	{
		current = t->b_head;
		anchor = t->b_head;
		while (current)
		{
			if (current->dist < anchor->dist)
				anchor = current;
			current = current->next;
		}
		path_assign(t);
		place_anchor(t, &anchor);
	}
}

void	push_swap(t_table *t)
{
	place_in_b(t);
	while (!sorted(t->b_head, 'b'))
	{
		path_assign(t);
		place_in_a(t);
	}
}