/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:38:54 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:38:54 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr(t_circular **l, char c)
{
	if (!*l || (*l)->next == *l)
		return ;
	*l = (*l)->prev;
}

void	rotate_reverse(t_circular **l, char c)
{
	if (c == 'a')
	{
		ft_rr(l);
		l->dist_a--;
		ft_printf("rra\n");
	}
	else if (c == 'b')
	{
		ft_rr(l);
		l->dist_a--;
		ft_printf("rrb\n");
	}
	else
	{
		ft_rr(l);
		ft_rr(l);
		l->dist_a--;
		l->dist_b--;
		ft_printf("rrr\n");
	}
}
