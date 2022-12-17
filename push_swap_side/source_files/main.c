/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:50:20 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:50:20 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_list(t_circular *l)
{
	t_circular	*tmp;

	ft_printf("in list\n");
	if (!l)
	{
		ft_printf("no element\n");
		return ;
	}
	tmp = l->next;
	ft_printf("%d ", l->content);
	while (tmp != l)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

static void	sort_triple(t_table *t)
{
	if (t->a_head->content > t->a_head->next->content \
		&& t->a_head->content > t->a_head->next->next->content)
		rotate(&t->a_head, 'a');
	else if (t->a_head->content < t->a_head->next->content)
		rotate_reverse(&t->a_head, 'a');
	if (t->a_head->content > t->a_head->next->content \
		&& t->a_head->content < t->a_head ->next->next->content)
		swap(t, 'a');
}

static void	place_in_b(t_table *t)
{
	while (list_len(t->a_head) > 3 && !sorted(t->a_head, 'a'))
	{
		if (t->a_head->content > t->a_head->next->content)
			push(&(t->b_head), &(t->a_head), 'b');
		else
			rotate(&(t->a_head), 'a');
		if (list_len(t->a_head) == 3)
			sort_triple(t);
	}
}

static void	push_swap(t_table *t)
{
	place_in_b(t);
	print_list(t->a_head);
	print_list(t->b_head);
	while (!sorted(t->b_head, 'b'))
	{
		path_assign(t);
		place_in_a(t);
	}
}

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (ac <= 2)
		return (0);
	check_input(&av[1]);
	table = t_init(table, ac - 1, &av[1]);
	if (!table)
		write_error(table);
	push_swap(table);
	free_table(table);
	return (0);
}
