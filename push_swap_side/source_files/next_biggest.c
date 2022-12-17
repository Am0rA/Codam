/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   next_biggest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:48:13 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:48:13 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_circular	*next_biggest(t_circular *src, t_circular *prev)
{
	t_circular	*tmp;
	t_circular	*next_big;

	next_big = src;
	tmp = src->next;
	while (tmp != src)
	{
		if (next_big->content < tmp->content && !prev)
			next_big = tmp;
		else if (next_big->content < tmp->content
			&& prev->content > tmp->content)
			next_big = tmp;
		tmp = tmp->next;
	}
	return (next_big);
}
