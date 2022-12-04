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

void	list_add_front(t_circular **l, t_circular *new)
{

	new->next = *l;
	new->prev = (*l)->prev;
	(*l)->prev->next = new;
	(*l)->prev = new;
	new->head = 1;
	(*l)->head = 0;
}

int	list_del_front(t_circular *l)
{
	l = list_last(l)->next;
	l->next->head = 1;
	l->prev->next = l->next->prev;
	l->next->prev = l->prev->next;
	free(l);
	return (1);
}

t_circular	*list_new(int content)
{
	t_circular	*new;

	new = malloc(sizeof(t_circular));
	if (!new)
		return (NULL);
	new->content = content;
	new->head = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_circular	*list_last(t_circular *l)
{
	while (l->next->head == 0)
	{
		l = l->next;
	}
	return (l);
}