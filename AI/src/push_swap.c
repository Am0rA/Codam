#include "push_swap.h"

void	place_in_a(t_table *t)
{
	t_circular	*anchor;
	t_circular	*current;

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

	if (!(t->b))
		return ;
	c = t->b->next;
	while (c != t->b)
	{
		c->dist_a = distance_to_head(t->a, next_biggest(t->a, c));
		c->dist_b = distance_to_head(t->b, c);
		c->dist = abs(c->dist_a) + abs(c->dist_b);
		ft_printf("%d %d %d\n", c->dist_a, c->dist_b, c->dist);
		c = c->next;
	}
}

void	push_swap(t_table *t)
{
	place_in_b(t);
	set_dist(t);
	while (!sorted(t->a, 'a') || !sorted(t->b, 'b'))
		place_in_a(t);
}
