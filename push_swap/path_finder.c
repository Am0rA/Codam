/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_finder.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/14 20:52:26 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/14 21:18:01 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	path_len(t_circular	*l, t_circular *obj)
{
	t_circular	*tmp;
	t_circular	*next;
	int			i;
	int			j;

	i = 0;
	j = 0;
	tmp = l;
	next = next_smallest(l, obj);
	while (tmp != next)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp != next)
	{
		j--;
		tmp = tmp->prev;
	}
	if (i + j < 0)
		return (j);
	else
		return (i);
}

void	path_assign(t_table	*t)
{
	t_circular	*tmp;
	int			a;
	int			b;

	tmp = t->b_head;
	a = path_len(t->a_head, tmp);
	b = path_len(t->b_head, tmp);
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	tmp->distance = a + b;
	tmp = tmp->next;
	while (tmp != t->b_head)
	{
		a = path_len(t->a_head, tmp);
		b = path_len(t->b_head, tmp);
		if (a < 0)
			a *= -1;
		if (b < 0)
			b *= -1;
		tmp->distance = a + b;
		tmp = tmp->next;
	}
}

void	path_put(t_table *t)
{
	t_circular	*obj;
	t_circular	*closest;

	obj = t->b_head->next;
	closest = t->b_head;
	while (obj != t->b_head)
	{
		if (closest->distance > obj->distance)
			closest = obj;
		obj = obj->next;
	}
	put(t, closest, 'a');
	put(t, closest, 'b');
	ft_p(&(t->b_head), &(t->a_head));
	write(1, "pa\n", 3);
}

void	put(t_table *t, t_circular *closest, int c)
{
	int	len;

	len = 0;
	if ((char)c == 'a')
		len = path_len(t->a_head, closest);
	else if ((char)c == 'b')
		len = path_len(t->b_head, closest);
	while (len != 0)
	{
		if (len > 0)
		{
			ft_rr(&t->a_head);
			ft_printf("rr%c\n", (char)c);
			len--;
		}
		else if (len < 0)
		{
			ft_r(&t->a_head);
			ft_printf("r%c\n", (char)c);
			len++;
		}
	}
}
