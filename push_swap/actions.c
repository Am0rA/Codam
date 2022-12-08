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

static void	ft_swap(t_circular *obj1, t_circular *obj2)
{
	int	buf;

	if (!obj1 || !obj2)
		return ;
	buf = obj1->content;
	obj1->content = obj2->content;
	obj2->content = buf;
}

void	ft_s(t_table *t, int i)
{
	if (i % 3 == 1)
	{
		ft_swap(t->a, t->a->next);
		write(1, "sa\n", 3);
	}
	else if (i % 3 == 2)
	{
		ft_swap(t->b, t->b->next);
		write(1, "sb\n", 3);
	}
	else
	{
		ft_swap(t->a, t->a->next);
		ft_swap(t->b, t->b->next);
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
		t->a->prev->head = 1;
		t->a->head = 0;
		write(1, "ra\n", 3);
	}
	else if (i % 3 == 2 && t->b)
	{
		t->b->prev->head = 1;
		t->b->head = 0;
		write(1, "rb\n", 3);
	}
	else if (i % 3 == 0 && t->b && t->a)
	{
		t->a->prev->head = 1;
		t->a->head = 0;
		t->b->prev->head = 1;
		t->b->head = 0;
		write(1, "rr\n", 3);
	}
}

void	ft_rr(t_table *t, int i)
{
	if (i % 3 == 1 && t->a)
	{
		t->a->next->head = 1;
		t->a->head = 0;
		write(1, "rra\n", 3);
	}
	else if (i % 3 == 2 && t->b)
	{
		t->b->next->head = 1;
		t->b->head = 0;
		write(1, "rrb\n", 3);
	}
	else if (i % 3 == 0 && t->b && t->a)
	{
		t->a->next->head = 1;
		t->a->head = 0;
		t->b->next->head = 1;
		t->b->head = 0;
		write(1, "rrr\n", 3);
	}
	t->a = find_beginning(t->a);
	t->b = find_beginning(t->b);
}
