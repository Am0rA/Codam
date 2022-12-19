/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 21:44:29 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 21:44:29 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_tail *l, char c)
{
	t_tail	*tmp;

	if (c == 'b' && !l)
		return (1);
	if (c == 'b' && l)
		return (0);
	tmp = l;
	while (tmp)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_list(t_tail *l)
{
	t_tail	*tmp;

	while (l)
	{
		tmp = l->next;
		l->next = NULL;
		l->prev = NULL;
		free (l);
		l = tmp;
	}
}

void	free_table(t_table *t)
{
	if (!t)
		return ;
	free_list(t->a_head);
	free_list(t->b_head);
	free(t);
}
