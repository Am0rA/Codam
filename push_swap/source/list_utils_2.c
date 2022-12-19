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

t_tail	*next_biggest(t_tail *src, t_tail *prev)
{
	t_tail	*next;
	t_tail	*tmp;

	next = src;
	tmp = src;
	while (tmp)
	{
		if (!prev && next->value < tmp->value)
			next = tmp;
		else if (next->value < tmp->value
			&& tmp->value < prev->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

t_tail	*next_smallest(t_tail *src, t_tail *prev)
{
	t_tail	*next;
	t_tail	*tmp;

	next = src;
	tmp = src;
	while (tmp)
	{
		if (!prev && next->value > tmp->value)
			next = tmp;
		else if (next->value > tmp->value
			&& tmp->value > prev->value)
			next = tmp;
		tmp = tmp->next;
	}
	return (next);
}

t_tail	*delete_node(t_tail *l)
{
	t_tail	*tmp;

	if (!l)
		return (NULL);
	tmp = l;
	if (l->next)
		l = l->next;
	free(tmp);
	tmp = NULL;
	if (list_len(l) == 0)
	{
		l->next = NULL;
		l->prev = NULL;
		l = NULL;
	}
	return (l);
}
