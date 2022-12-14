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

void	ft_s(t_circular **l)
{
	t_circular	*tmp;

	if (!*l || !(*l)->next)
		return ;
	tmp = (*l)->next;
	(*l)->next = tmp->next;
	tmp->prev = (*l)->prev;
	tmp->next = (*l);
	(*l)->prev = tmp;
	*l = tmp;
}

void	ft_r(t_circular **l)
{
	if (!l || !*l)
		return ;
	*l = (*l)->prev;
}

void	ft_rr(t_circular **l)
{
	if (!l || !*l)
		return ;
	*l = (*l)->next;
}

void	ft_p(t_circular **dst, t_circular **src)
{
	t_circular	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	if (tmp->next != tmp)
	{
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
	}
	insert_front(dst, src);
}

void	apply_double(t_circular **a, t_circular **b, int type)
{
	if (!*a || !*b)
		return ;
	if (type == 1)
	{
		ft_s(a);
		ft_s(b);
		write(1, "ss\n", 3);
	}
	else if (type == 2)
	{
		ft_r(a);
		ft_r(b);
		write(1, "rr\n", 3);
	}
	else if (type == 3)
	{
		ft_rr(a);
		ft_rr(b);
		write(1, "rrr\n", 4);
	}
}
