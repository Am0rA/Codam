/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 21:14:28 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 21:21:20 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_del_front(t_int_l *l)
{
	l->prev->next = l->next;
	l->next->prev = l->prev;
	free(l);
}

int	list_add_front(t_int_l *l, long int var)
{
	t_int_l	*new;

	new = malloc(sizeof(t_init));
	if (!new)
		return (0);
	l->prev->next = new;
	l->next->prev = new;
	new->num = var;
	return (1);
}
