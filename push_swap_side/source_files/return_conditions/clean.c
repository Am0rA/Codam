/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:46:56 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:46:56 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_circular *l)
{
	t_circular	*child;
	t_circular	*tmp;

	if (!l)
		return ;
	child = l->next;
	tmp = l->prev;
	tmp->next = NULL;
	l->next = NULL;
	l->prev = NULL;
	free(l);
	free_list(child);
}

void	free_table(t_table *t)
{
	if (!t)
		return ;
	free_list(t->a_head);
	free_list(t->b_head);
	free(t);
}
