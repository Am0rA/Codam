/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 20:43:03 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 20:43:03 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_tail **dst, t_tail **src, char c)
{
	t_tail	*tmp;
	int		len;

	if (!*src)
		return ;
	len  = list_len(*src);
	if (len == 1)
	{
		(*src)->prev = NULL;
		*dst = insert_front(dst, src);
		*src = NULL;
	}
	else
	{
		tmp = (*src)->next;
		(*src)->prev = NULL;
		*dst = insert_front(dst, src);
		tmp->prev = NULL;
		*src = tmp;
	}
	ft_printf("p%c\n", c);
}

static void	ft_r(t_tail **l)
{
	t_tail	*last;
	t_tail	*first;
	t_tail	*tmp;

	last = (*l);
	first = (*l);
	tmp = (*l)->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	tmp->prev = NULL;
	(*l) = tmp;
}

void	rotate(t_table *t, char c)
{
	if (c == 'a')
		ft_r(&(t->a_head));
	else if (c == 'b')
		ft_r(&(t->b_head));
	else
	{
		ft_r(&(t->a_head));
		ft_r(&(t->b_head));
	}
	ft_printf("r%c\n", c);
}

static void	ft_rr(t_tail **l)
{
	t_tail	*last;

	last = (*l);
	while (last->next)
		last = last->next;
	last->next = (*l);
	last->prev->next = NULL;
	last->prev = NULL;
	(*l) = last;
}

void	rotate_reverse(t_table *t, char c)
{
	if (c == 'a')
		ft_rr(&(t->a_head));
	else if (c == 'b')
		ft_rr(&(t->b_head));
	else
	{
		ft_rr(&(t->a_head));
		ft_rr(&(t->b_head));
	}
	ft_printf("rr%c\n", c);
}