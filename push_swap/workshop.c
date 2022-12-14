/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   workshop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/13 22:05:55 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/14 16:43:14 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_circular	*next_smallest(t_circular *src, t_circular *prev)
{
	t_circular	*tmp;
	t_circular	*next_small;

	next_small = src;
	tmp = src->next;

	if (!prev)
	{
		while (tmp != src)
		{
			if (next_small->content > tmp->content)
				next_small = tmp;
			tmp = tmp->next;
		}
		return (next_small);
	}
	while (tmp != src)
	{
		if (next_small->content > tmp->content && prev->content < tmp->content)
			next_small = tmp;
		tmp = tmp->next;
	}
	return (next_small);
}

t_circular	*next_biggest(t_circular *src, t_circular *prev)
{
	t_circular	*tmp;
	t_circular	*next_big;

	next_big = src;
	tmp = src->next;

	if (!prev)
	{
		while (tmp != src)
		{
			if (next_big->content < tmp->content)
				next_big = tmp;
			tmp = tmp->next;
		}
		return (next_big);
	}
	while (tmp != src)
	{
		if (next_big->content < tmp->content && prev->content > tmp->content)
			next_big = tmp;
		tmp = tmp->next;
	}
	return (next_big);
}
