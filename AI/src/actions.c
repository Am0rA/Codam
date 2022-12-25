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
	if (c == 'a')
		t->a = t->a->prev;
	else if (c == 'b')
		t->b = t->b->prev;
	else
	{
		t->a = t->a->prev;
		t->b = t->b->prev;
	}
	set_dist(t);
	ft_printf("r%c\n", c);
}

void	rotate_reverse(t_table *t, char c)
{
	if (c == 'a')
		t->a = t->a->next;
	else if (c == 'b')
		t->b = t->b->next;
	else
	{
		t->a = t->a->next;
		t->b = t->b->next;
	}
	set_dist(t);
	ft_printf("rr%c\n", c);
}

void	swap(t_table *t, char c)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = t->a->value;
		t->a->value = t->a->next->value;
		t->a->next->value = tmp;
	}
	else if (c == 'b')
	{
		tmp = t->b->value;
		t->b->value = t->b->next->value;
		t->b->next->value = tmp;
	}
	else
	{
		tmp = t->a->value;
		t->a->value = t->a->next->value;
		t->a->next->value = tmp;
		tmp = t->b->value;
		t->b->value = t->b->next->value;
		t->b->next->value = tmp;
	}
	ft_printf("s%c\n", c);
}
