#include "push_swap.h"

int	sorted(t_circular *l, char c)
{
	t_circular	*tmp;
	int		count;

	if (c == 'b' && !l)
		return (1);
	if (c == 'b' && l)
		return (0);
	count = 0;
	tmp = l;
	while (tmp->next != l || count == 0)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		count++;
	}
	return (1);
}

void	free_list(t_circular *l)
{
	t_circular	*tmp;

	while (l)
	{
		tmp = l->next;
		l->next = NULL;
		l->prev = NULL;
		free (l);
		l = tmp;
	}
}

void	free_table(t_table *t)
{
	if (!t)
		return ;
	free_list(t->a);
	free_list(t->b);
	free(t);
}
