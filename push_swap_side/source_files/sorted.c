/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 16:45:56 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 16:54:12 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_circular *l, char c)
{
	t_circular	*tmp;
	int			value;

	if (c == 'b' && !l)
		return (1);
	if (c == 'b' && l)
		return (0);
	tmp = l->next;
	value = l->content;
	while (tmp != l)
	{
		if (value > tmp->content)
			return (0);
		value = tmp->content;
		tmp = tmp->next;
	}
	return (1);
}
