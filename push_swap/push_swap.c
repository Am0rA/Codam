/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 18:03:59 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 21:36:18 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_triple(t_table *t)
{
	if (t->a_head->content > t->a_head->next->content \
		&& t->a_head->content > t->a_head->next->next->content)
	{
		ft_r(&t->a_head);
		write(1, "ra\n", 3);
	}
	else if (t->a_head->content < t->a_head->next->content)
	{
		ft_rr(&t->a_head);
		write(1, "rra\n", 4);
	}
	if (t->a_head->content > t->a_head->next->content \
		&& t->a_head->content < t->a_head ->next->next->content)
	{
		ft_s(&t->a_head);
		write(1, "sa\n", 3);
	}
}

static void	desired_assign(t_table *t)
{
	t_circular	*prev;
	t_circular	*next;
	int			i;

	i = 0;
	prev = NULL;
	next = next_smallest(t->a_head, prev);
	next->desired_i = i;
	i++;
	while (next->desired_i < 0)
	{
		next = next_smallest(t->a_head, prev);
		next->desired_i = i;
		prev = next;
		i++;
	}
}

static void	push(t_table *t)
{
	t_circular	*last;

	last = t->a_head->prev;
	while (list_len(t->a_head) > 3 && last != t->a_head)
	{
		if (t->a_head->desired_i - 1 == t->a_head->next->desired_i)
		{
			ft_s(&t->a_head);
			write(1, "sa\n", 3);
		}
		if (t->a_head->content > t->a_head->next->content)
		{
			ft_p(&(t->a_head), &(t->b_head));
			write(1, "pb\n", 3);
		}
		else
		{
			ft_rr(&(t->a_head));
			write(1, "rra\n", 4);
		}
	}
	if (list_len(t->a_head) == 3)
		sort_triple(t);
}

void	push_swap(t_table *t)
{
	int	i;

	i = 0;
	desired_assign(t);
	push(t);
	while (!sorted(t))
	{
		path_assign(t);
		path_put(t);
		i++;
		if (i >= 5000)
			break ;
	}
}
