/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   next_smallest.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:49:02 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:49:02 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_circular	*next_smallest(t_circular *src, t_circular *prev)
{
	t_circular	*tmp;
	t_circular	*next_small;

	next_small = src;
	tmp = src->next;
	while (tmp != src)
	{
		if (!prev && next_small->content > tmp->content)
			next_small = tmp;
		else if (next_small->content > tmp->content
			&& prev->content < tmp->content)
			next_small = tmp;
		tmp = tmp->next;
	}
	return (next_small);
}
