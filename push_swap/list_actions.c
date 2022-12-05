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
	{
		l = l->next;
	}
	return (l);
}

void	insert_beginning(t_circular *l, t_circular *new)
{
	t_circular	*anchor;

	anchor = find_beginning(l);
	new->head = 1;
	new->next = anchor;
	new->prev = anchor->prev;
	anchor->prev->next = new;
	anchor->prev = new;
	anchor->head = 0;
}

int	insert_back(t_circular *l, t_circular *new)
{
	t_circular	*anchor;

	if (!new)
		return (0);
	anchor = find_beginning(l);
	new->next = anchor;
	new->prev = anchor->prev;
	anchor->prev->next = new;
	anchor->prev = new;
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
