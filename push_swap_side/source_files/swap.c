/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:38:15 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:38:15 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_s(t_circular **l)
{
	t_circular	*tmp;

	if (!*l || (*l)->next == *l)
		return ;
	tmp = (*l)->next;
	((*l)->prev)->next = (*l)->next;
	(tmp->next)->prev = *l;
	(*l)->next = tmp->next;
	tmp->next = *l;
	tmp->prev = (*l)->prev;
	(*l)->prev = tmp;
	*l = tmp;
}

void	swap(t_table *t, char c)
{
	if (c == 'a')
	{
		ft_s(&(t->a_head));
		ft_printf("sa\n");
	}
	else if (c == 'b')
	{
		ft_s(&(t->b_head));
		ft_printf("sb\n");
	}
	else
	{
		ft_s(&(t->a_head));
		ft_s(&(t->b_head));
		ft_printf("ss\n");
	}
}
