/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 00:39:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/28 00:39:10 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *l)
{
	t_list	*child;
	t_list	*parent;
	if (!l)
		return ;
	parent = l;
	while (l != NULL)
	{
		child = l;
		l = l->next;
		free(child);
	}
	free(parent);
}

void	free_table(t_table *t)
{
	if (!t)
		return ;
	if(t->a)
		free_list(t->a);
	if(t->b)
		free_list(t->b);
	free(t);
}

void	write_error(t_table *t)
{
	write(2, "Error\n", 6);
	free_table(t);
	exit(-1);
}
