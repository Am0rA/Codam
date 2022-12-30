#include "push_swap.h"

void	place_anchor(t_table *t, t_circular **anchor)
{
	while ((*anchor)->dist_a < 0 && (*anchor)->dist_b < 0)
		rotate_reverse(t, 'r');
	while ((*anchor)->dist_a > 0 && (*anchor)->dist_b > 0)
		rotate(t, 'r');
	while ((*anchor)->dist_b > 0)
		rotate(t, 'b');
	while ((*anchor)->dist_b < 0)
		rotate_reverse(t, 'b');
	while ((*anchor)->dist_a > 0)
		rotate(t, 'a');
	while ((*anchor)->dist_a < 0)
		rotate_reverse(t, 'a');
	push(&(t->a), &(t->b), 'a');
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

int distance_to_head(t_circular *list, t_circular *node)
{
	t_circular	*tmp;
	int			distance;

	if (!list || !node)
		return (0);
	distance = 0;
	tmp = list;
	while (tmp != node)
	{
		distance++;
		tmp = tmp->next;
		if (tmp == list)
			return (0);
	}
	if (distance * 2 > list_len(list))
		return (-distance);
	return (distance);
}

int	give_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

int	list_len(t_circular *l)
{
	int			count;
	t_circular	*current;

	count = 0;
	if (!l)
		return (count);
	current = l->next;
	count++;
	while (current != l)
	{
		current = current->next;
		count++;
	}
	return count;
}

void	print_list(t_circular *l)
{
	t_circular	*tmp;
	int			i;

	i = 0;
	tmp = l;
	while (tmp != NULL && (tmp != l || i == 0))
	{
		ft_printf("%d,", tmp->value);
		tmp = tmp->next;
		i++;
	}
	ft_printf("\n");
}