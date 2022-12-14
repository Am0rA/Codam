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

int	list_len(t_circular *l)
{
	t_circular	*tmp;
	int			i;

	i = 0;
	tmp = l;
	if (l->next != tmp)
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp != l)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	remove_node(t_circular **l)
{
	t_circular	*tmp;

	if ((*l)->next == *l)
	{
		free(*l);
		*l = NULL;
	}
	else
	{
		tmp = (*l)->next;
		((*l)->prev)->next = (*l)->next;
		tmp->prev = (*l)->prev;
		free(*l);
		*l = tmp;
	}
}

int	insert_front(t_circular **l, t_circular **n)
{
	t_circular	*tmp;

	if (!n || !*n)
		return (0);
	if (!*l)
	{
		(*n)->next = *n;
		(*n)->prev = *n;
		l = n;
		return (1);
	}
	tmp = (*l)->prev;
	(*n)->next = *l;
	(*n)->prev = tmp;
	tmp->next = (*n);
	(*l)->prev = (*n);
	*l = (*n);
	return (1);
}

int	insert_back(t_circular **l, t_circular **n)
{
	t_circular	*tmp;

	if (!n || !*n || !l)
		return (0);
	if (!*l)
	{
		(*n)->next = *n;
		(*n)->prev = *n;
		*l = *n;
		return (1);
	}
	tmp = (*l)->prev;
	(*n)->next = *l;
	(*n)->prev = tmp;
	tmp->next = (*n);
	(*l)->prev = (*n);
	return (1);
}

t_circular	*new_node(int value)
{
	t_circular	*new;

	new = (t_circular *)malloc(sizeof(t_circular));
	if (!new)
		return (NULL);
	new->content = value;
	new->next = NULL;
	new->prev = NULL;
	new->desired_i = -1;
	return (new);
}
