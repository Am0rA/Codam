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

void	push_swap(t_table *t, int argc)
{
	/*
		assign their desired_i;
		t_circular	*prev;
		t_circular	*next;
		int			i;

		i = 0;
		*prev = NULL;
		next = next_smallest(t->a_head, prev);
		next->desired_i = i;
		i++;
		while (next->desired_i < 0)
		{
			next = next_smallest(t->a_head, prev);
			next->desired_i = i;
			i++;
		}
	*/
	/*
		Push item if it is bigger than next one as long as list has at least 3 elements
		t_circular	*last;

		last = t->a_head->prev;
		while (list_len(t->a_head) > 3)
		{
			if (t->a_head->desired_i - 1 == t->a_head->next->desired_i)
			{
				ft_s(t->a_head);
				write(1, "sa\n", 3);
			}
			if (t->a_head->content > t->a_head->next->content)
			{
				ft_p(&(t->a_head), &(t->b_head));
				write(1, "pb\n", 3);
			}
			else (t->a_head->content < t->a_head->next->content)
			{
				ft_rr(&(t->a_head));
				write(1, "rra\n", 4);
			}
			if (last == t->a_head)!?!
				break ;
		}
		if (list_len(t->a_head) == 3)
			sort_triple(t->a_head);
	*/
	/*
		set their indexes depending on in which list they are.
		while (tmp->i < 0)
		{
			tmp->i = i;
			i++;
			tmp = tmp->next;
		}
	*/
	/*
		To put back all of them, find what must come after it in list A. Do it for every element in list B
		t_circular	*next;
		t_circular	*tmp;

		tmp = t->b_head;
		next = next_smallest(t->a_head, tmp);
		tmp->distance = shortest_path(tmp, next);
		tmp = tmp->next;
		while (tmp != t->a_head)
		{
			next = next_smallest(t->a_head, tmp);
			tmp->distance = shortest_path(tmp, next);
			tmp = tmp->next;
		}
	*/
	/*
		SHORTEST PATH
		if (pathA < 0)
			while (pathA < 0)
			{
				ft_r(t->a_head);
				write(1, "ra\n", 3);
				pathA++;
			}
		if (pathA > 0)
			while (pathA > 0)
			{
				ft_rr(t->a_head);
				write(1, "rra\n", 4);
				pathA--;
			}
		if (pathB < 0)
			while (pathB < 0)
			{
				ft_r(t->b_head);
				write(1, "rb\n", 3);
				pathB++;
			}
		if (pathB > 0)
			while (pathB > 0)
			{
				ft_rr(t->b_head);
				write(1, "rrb\n", 4);
				pathB--;
			}
		ft_p(&(t->b_head), &(t->a_head));
		write(1, "pa\n", 3);
	*/
	/*
		SHORTEST PATH b
		index of this + index of target location
		while (tmp != t->b_head)
		{
			i++;
			tmp = tmp->next;
		}
		while (tmp != t->b_head)
		{
			j--;
			tmp = tmp->prev;
		}
		if (i + j > 0)
			give i
		else
			give j
	*/
	/*
		SHORTEST PATH a
		while(tmp != next_smallest(t->a_head, this))
		{
			i++;
			tmp = tmp->next;
		}
		while(tmp != next_smallest(t->a_head, this))
		{
			j--;
			tmp = tmp->prev;
		}
		if (i + j > 0)
			give i
		else
			give j
	*/
}
