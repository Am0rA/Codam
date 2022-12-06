/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_actions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/05 00:31:48 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/05 00:31:48 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_circular *find_beginning(t_circular *l)
{
	while (l->head != 1)
		l = l->next;
	return (l);
}

int	insert_beginning(t_circular **l, t_circular *new)
{
	t_circular	*tmp;

	if (!new)
		return (0);
	if (!*l)
	{
		new->head = 1;
		new->next = new;
		new->prev = new;
		*l = new;
		return (1);
	}
    tmp = *l;
    while(tmp->next != *l)
        tmp = tmp->next;
    tmp->next = new;
    new->prev=tmp;
	tmp->head = 0;
	new->head = 1;
    (*l)->prev = new;
	new->next = *l;
	return (1);
}

int	insert_back(t_circular **l, t_circular *new)
{
	t_circular	*tmp;

	if (!new)
		return (0);
	if (!*l)
	{
		new->head = 1;
		new->next = new;
		new->prev = new;
		*l = new;
		return (1);
	}
    tmp = *l;
    while(tmp->next != *l)
        tmp = tmp->next;
    tmp->next = new;
    new->prev=tmp;
    (*l)->prev = new;
	new->next = *l;
	return (1);
}

t_circular	*new_node(int value)
{
	t_circular	*new;
	new = (t_circular *)malloc(sizeof(t_circular));
	if(!new)
       return (NULL);
    new->content = value;
	new->head = 0;
	return (new);
}
