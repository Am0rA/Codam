#include "push_swap.h"

void	place_anchor(t_table *t, t_circular **anchor)
{
	while ((*anchor)->dist_a < 0 && (*anchor)->dist_b < 0)
		rotate(t, 'r');
	while ((*anchor)->dist_a < 0 && (*anchor)->dist_b < 0)
		rotate_reverse(t, 'r');
	while ((*anchor)->dist_a < 0)
		rotate(t, 'a');
	while ((*anchor)->dist_a > 0)
		rotate_reverse(t, 'a');
	while ((*anchor)->dist_b < 0)
		rotate(t, 'b');
	while ((*anchor)->dist_b > 0)
		rotate_reverse(t, 'b');
	push(&(t->a), &(t->b), 'a');
}

int	list_len(t_circular *l)
{
	int			count;
	t_circular	*current;

	current = l->next;
	if (current)
	{
		count = 1;
		while (current != l)
		{
			current = current->next;
			count++;
		}
	}
	return count;
}

void	sort_triple(t_table *t)
{
	if (t->a->value > t->a->next->value
		&& t->a->value > t->a->next->next->value)
		rotate(t, 'a');
	else if (t->a->value < t->a->next->value)
		rotate_reverse(t, 'a');
	if (t->a->value > t->a->next->value
		&& t->a->value < t->a ->next->next->value)
		swap(t, 'a');
}

int	distance_to_head(t_circular *l, t_circular *obj)
{
	t_circular	*forward;
	t_circular	*backward;
	int			i;

	i = 0;
	backward = obj;
	forward = obj;
	while (backward != l && forward != l)
	{
		i++;
		backward = backward->prev;
		forward = forward->next;
	}
	ft_printf("dist to head %d\n", i);
	print_list(l);
	if (backward == l)
		return (-i);
	return (i);
}

int	give_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

void	print_list(t_circular *l)
{
	t_circular	*tmp;
	int			i;

	i = 0;
	tmp = l;
	while (tmp != NULL && (tmp != l || i == 0))
	{
		ft_printf("%d", tmp->value);
		tmp = tmp->next;
		i++;
	}
	ft_printf("\n");
}