#include "push_swap.h"

void	place_in_a(t_table *t)
{
	t_circular	*anchor;
	t_circular	*current;

	if (!(t->b))
		return ;
	current = t->b->next;
	anchor = t->b;
	while (current != t->b)
	{
		if (current->dist < anchor->dist)
			anchor = current;
		current = current->next;
	}
	place_anchor(t, &anchor);
}

void	place_in_b(t_table *t)
{
	int	len;

	len = list_len(t->a);
	while (len > 3 && !sorted(t->a, 'a'))
	{
		if (t->a->value > t->a->next->value && len > 3)
		{
			push(&(t->b), &(t->a), 'b');
			len--;
		}
		else
			rotate(t, 'a');
	}
	if (len == 3)
		sort_triple(t);
}

void	set_dist(t_table *t)
{
	t_circular	*c;
	int			i;

	if (!(t->b))
		return ;
	i = 0;
	c = t->b;
	while (c != t->b || i == 0)
	{
		c->dist_a = distance_to_head(t->a, next_smallest(t->a, c));
		c->dist_b = distance_to_head(t->b, c);
		c->dist = give_abs(c->dist_a) + give_abs(c->dist_b);
		c = c->next;
		i++;
	}
}

void	push_swap(t_table *t)
{
	t_circular	*check;
	place_in_b(t);
	set_dist(t);
	while (!sorted(t->b, 'b'))
		place_in_a(t);
	check = next_smallest(t->a, NULL);
	while (check != t->a)
	{
		if (distance_to_head(t->a, check) > 0)
			rotate(t, 'a');
		else if (distance_to_head(t->a, check) < 0)
			rotate_reverse(t, 'a');
	}
}
