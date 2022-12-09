/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 22:26:55 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 21:19:12 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_s(t_circular **l)
{
	int	tmp;

	if (!*l || !(*l)->next)
		return (0);
	tmp = (*l)->content;
	(*l)->content = ((*l)->next)->content;
	((*l)->next)->content = tmp;
	return (1);
}

int	ft_r(t_circular **l)
{
	t_circular *tmp;

	if (!*l)
		return (0);
	tmp = (*l)->prev;
	(*l)->head = 0;
	tmp->head = 1;
	*l = tmp;
	return (1);
}

int	ft_rr(t_circular **l)
{
	t_circular *tmp;

	if (!*l)
		return (0);
	tmp = (*l)->next;
	(*l)->head = 0;
	tmp->head = 1;
	*l = tmp;
	return (1);
}

int	ft_p(t_circular **dst, t_circular **src)
{
	t_circular *tmp;

	if (!*src)
		return (0);
	tmp = *src;
	insert_beginning(dst, *src);
	(*src)->next->head = 1;
	remove_node(src);
	free(tmp);
	return (1);
}

int apply_double(t_circular **a, t_circular **b, int type)
{
	if (!*a || !*b)
		return (0);
	if (type == 1)
	{
		ft_s(a);
		ft_s(b);
	}
	else if (type == 2)
	{
		ft_r(a);
		ft_r(b);
	}
	else if (type == 3)
	{
		ft_rr(a);
		ft_rr(b);
	}
	return (1);
}
