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

static void	ft_swap(t_circular *l)
{
	int	buf;

	if (l == NULL || l->next == NULL)
		return ;
	buf = l->content;
	l->content = l->next->content;
	l->next->content = buf;
}

void	ft_s(t_table *t, int i)
{
	if (i % 3 == 1)
	{
		ft_swap(t->a);
		write(1, "sa\n", 3);
	}
	else if (i % 3 == 2)
	{
		ft_swap(t->b);
		write(1, "sb\n", 3);
	}
	else
	{
		ft_swap(t->a);
		ft_swap(t->b);
		write(1, "ss\n", 3);
	}
}

void	ft_p(t_table *t, int i)
{
	if (i % 3 == 2 && t->b)
	{
		insert_beginning(&(t->b), t->a);
		//list_del_front(t->a);
		write(1, "pb\n", 3);
	}
	else if (i % 3 == 1 && t->a)
	{
		insert_beginning(&(t->a), t->b);
		//list_del_front(t->b);
		write(1, "pa\n", 3);
	}
}

void	ft_r(t_table *t, int i)
{
	if (i % 3 == 1 && t->a)
	{
		t->a = t->a->next;
		write(1, "ra\n", 3);
	}
	else if (i % 3 == 2 && t->b)
	{
		t->b = t->b->next;
		write(1, "rb\n", 3);
	}
	else if (i % 3 == 0 && t->b && t->a)
	{
		t->a = t->a->next;
		t->b = t->b->next;
		write(1, "rr\n", 3);
	}
}

void	ft_rr(t_table *t, int i)
{
	if (i % 3 == 1 && t->a)
	{
		t->a = t->a->prev;
		write(1, "rra\n", 4);
	}
	else if (i % 3 == 2 && t->b)
	{
		t->b = t->b->prev;
		write(1, "rrb\n", 4);
	}
	else if (i % 3 == 0 && t->b && t->a)
	{
		t->a = t->a->prev;
		t->b = t->b->prev;
		write(1, "rrr\n", 4);
	}
}
