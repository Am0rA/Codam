/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 00:39:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 16:02:08 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_circular **l)
{
	t_circular	*child;

	if (!*l)
		return ;
	child = (*l)->next;
	(*l)->next = NULL;
	(*l)->prev = NULL;
	free(l);
	free_list(&child);
}

void	free_table(t_table *t)
{
	if (!t)
		return ;
	free_list(&(t->a_head));
	free_list(&(t->b_head));
	free(t);
}

void	write_error(t_table *t)
{
	write(1, "Error\n", 6);
	free_table(t);
	exit(-1);
}
