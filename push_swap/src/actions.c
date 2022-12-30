#include "push_swap.h"

void	push(t_circular **dst, t_circular **src, char c)
{
	if (!*src)
		return ;
	insert(dst, src);
	ft_printf("p%c\n", c);
}

void	rotate(t_table *t, char c)
{
	if (c == 'a' || c == 'r')
		t->a = t->a->next;
	if (c == 'b' || c == 'r')
		t->b = t->b->next;
	set_dist(t);
	ft_printf("r%c\n", c);
}

void	rotate_reverse(t_table *t, char c)
{
	if (c == 'a' || c == 'r')
		t->a = t->a->prev;
	if (c == 'b' || c == 'r')
		t->b = t->b->prev;
	set_dist(t);
	ft_printf("rr%c\n", c);
}

void	swap(t_table *t, char c)
{
	int	tmp;

	if (c == 'a' || c == 's')
	{
		tmp = t->a->value;
		t->a->value = t->a->next->value;
		t->a->next->value = tmp;
	}
	if (c == 'b' || c == 's')
	{
		tmp = t->b->value;
		t->b->value = t->b->next->value;
		t->b->next->value = tmp;
	}
	set_dist(t);
	ft_printf("s%c\n", c);
}
