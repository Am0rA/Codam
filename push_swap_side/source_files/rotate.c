/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:38:35 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:38:35 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r(t_circular **l)
{
	if (!*l || (*l)->next == *l)
		return ;
	*l = (*l)->next;
}

void	rotate(t_circular **l, char c)
{
	if (c == 'a')
	{
		ft_r(l);
		(*l)->dist_a++;
	}
	else if (c == 'b')
	{
		ft_r(l);
		(*l)->dist_b++;
	}
	else
	{
		ft_r(l);
		ft_r(l);
		(*l)->dist_a++;
		(*l)->dist_b++;
	}
	ft_printf("r%c\n", c);
}
