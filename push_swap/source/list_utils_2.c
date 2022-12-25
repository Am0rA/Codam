/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 20:11:20 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 20:11:20 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tail	*biggest(t_tail *src)
{
	t_tail	*tmp;
	t_tail	*next;

	tmp = src;
	next = src;
	while (tmp)
	{
		if (tmp->value > next->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

t_tail	*smallest(t_tail *src)
{
	t_tail	*tmp;
	t_tail	*next;

	tmp = src;
	next = src;
	while (tmp)
	{
		if (tmp->value < next->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

t_tail	*next_biggest(t_tail *src, t_tail *prev)
{
    t_tail *next;
	t_tail *tmp;

	if (!prev)
 		return (biggest(src));
	if (biggest(src)->value < prev->value)
		return (smallest(src));
	next = smallest(src);
	tmp = src;
	while (tmp)
	{
		if (tmp->value > next->value
			&& prev->value > tmp->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

t_tail *next_smallest(t_tail *src, t_tail *prev)
{
    t_tail *next;
    t_tail *tmp;

	if (!prev)
		return (smallest(src));
	if (smallest(src)->value > prev->value)
		return (smallest(src));
	next = biggest(src);
	tmp = src;
	while (tmp)
	{
		if (next->value > prev->value
			&& tmp->value < next->value)
            next = tmp;
		tmp = tmp->next;
	}
    return (next);
}
