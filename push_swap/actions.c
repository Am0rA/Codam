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

void	ft_s(t_circular **l, char c)
{
	t_circular	*tmp;

	if (!*l || (*l)->next == *l)
		return ;
	tmp = (*l)->next;
	((*l)->prev)->next =(*l)->next;
	(tmp->next)->prev = *l;

	(*l)->next = tmp->next;
	tmp->next = *l;
	tmp->prev = (*l)->prev;
	(*l)->prev = tmp;
	*l = tmp;
    ft_printf("s%c\n", c);
}

void	ft_r(t_circular **l, char c)
{
	if (!*l || (*l)->next == *l)
		return ;
	*l = (*l)->next;
    ft_printf("r%c\n", c);
}

void	ft_rr(t_circular **l, char c)
{
	if (!*l || (*l)->next == *l)
		return ;
	*l = (*l)->prev;
    ft_printf("rr%c\n", c);
}

void	ft_p(t_circular **dst, t_circular **src)
{
	t_circular	*tmp;
	t_circular	*tmp2;

	if (!src)
		return ;
	tmp = (*src)->next;
	tmp2 = (*src)->prev;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	insert_front(dst, src);
	*src = tmp;
}

void	apply_double(t_circular **a, t_circular **b, int type)
{
	if (!*a || !*b)
		return ;
	if (type == 1)
	{
		ft_s(a, 0);
		ft_s(b, 0);
		write(1, "s\n", 2);
	}
	else if (type == 2)
	{
		ft_r(a, 0);
		ft_r(b, 0);
		write(1, "r\n", 2);
	}
	else if (type == 3)
	{
		ft_rr(a, 0);
		ft_rr(b, 0);
		write(1, "rr\n", 3);
	}
}
