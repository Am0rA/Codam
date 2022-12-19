/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions_2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 21:37:01 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 21:37:01 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_s(t_tail **l)
{
	t_tail	*next;

	next = (*l)->next;
	next->next->prev = (*l);
	(*l)->next = next->next;
	(*l)->prev = next;
	next->next = (*l);
	next->prev = NULL;
	(*l) = next;
}

void	swap(t_table *t, char c)
{
	if (c == 'a')
		ft_s(&(t->a_head));
	else if (c == 'b')
		ft_s(&(t->b_head));
	else
	{
		ft_s(&(t->a_head));
		ft_s(&(t->b_head));
	}
	ft_printf("s%c\n", c);
}

void	table_init(t_table *t, int size, char **argv)
{
	int	i;

	t = malloc(sizeof(t_table));
	if (!t)
		write_error(t);
	i = 0;
	t->a_head = NULL;
	t->b_head = NULL;
	while (i < size)
	{
		if (!insert_back(t->a_head, new_node(ft_atoi(argv[i]))))
			write_error(t);
		i++;
	}
}
