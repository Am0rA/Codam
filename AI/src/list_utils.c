#include "push_swap.h"

t_circular	*biggest(t_circular *src)
{
	t_circular	*tmp;
	t_circular	*next;

	tmp = src->next;
	next = src;
	while (tmp != src)
	{
		if (tmp->value > next->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

t_circular	*smallest(t_circular *src)
{
	t_circular	*tmp;
	t_circular	*next;

	tmp = src->next;
	next = src;
	while (tmp != src)
	{
		if (tmp->value < next->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

t_circular	*next_biggest(t_circular *src, t_circular *prev)
{
    t_circular	*next;
	t_circular	*tmp;
	int			count;

	if (!prev)
 		return (biggest(src));
	if (smallest(src)->value > prev->value)
		return (smallest(src));
	next = smallest(src);
	tmp = src;
	count = 0;
	while (tmp != src || count == 0)
	{
		if (tmp->value > next->value
			&& prev->value > tmp->value)
			next = tmp;
		tmp = tmp->next;
		count++;
	}
	return (next);
}

t_circular *next_smallest(t_circular *src, t_circular *prev)
{
    t_circular	*next;
    t_circular	*tmp;
	int			count;

	if (!prev)
		return (smallest(src));
	if (biggest(src)->value < prev->value)
		return (smallest(src));
	next = biggest(src);
	tmp = src;
	count = 0;
	while (tmp != src || count == 0)
	{
		if (next->value > prev->value
			&& tmp->value < next->value)
            next = tmp;
		tmp = tmp->next;
		count++;
	}
    return (next);
}
