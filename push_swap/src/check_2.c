#include "push_swap.h"

int	sorted(t_circular *l, char c)
{
	t_circular	*tmp;

	if (c == 'b' && !l)
		return (1);
	if (c == 'b' && l)
		return (0);
	tmp = l;
    if (tmp->value > tmp->next->value)
            return (0);
	tmp = tmp->next;
    while (tmp != l)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void	free_list(t_circular *l)
{
	t_circular	*tmp;
	t_circular	*current;

	if (!l)
		return ;
	current = l;
	while (current->next != l)
	{
		tmp = current->next;
		current->next = NULL;
		current->prev = NULL;
		free(current);
		current = tmp;
	}
	current->next = NULL;
	current->prev = NULL;
	free(current);
}

void	free_table(t_table *t)
{
	if (!t)
		return ;
	free_list(t->a);
	free_list(t->b);
	free(t);
}
