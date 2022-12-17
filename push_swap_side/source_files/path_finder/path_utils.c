/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:43:19 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:43:19 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	path_in_a(t_circular *l, t_circular *prev)
{
	t_circular	*tmp;
	t_circular	*tmp2;
	t_circular	*next;
	int			i;

	tmp = l;
	tmp2 = l;
	next = next_smallest(l, prev);
	while (tmp != next && tmp2 != next)
	{
		i++;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	if (tmp2 == next)
		i *= -1;
	return (i);
}

int	path_in_b(t_circular *l, t_circular *obj)
{
	t_circular	*tmp;
	t_circular	*tmp2;
	int			i;

	tmp = obj;
	tmp2 = obj;
	while (tmp != l && tmp2 != l)
	{
		i++;
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	if (tmp2 == l)
		i *= -1;
	return (i);
}