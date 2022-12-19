/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 19:44:24 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 19:44:24 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_len(t_tail *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

t_tail	*insert_back(t_tail *l, t_tail *new)
{
	t_tail	*last;

	if (!new)
		return (NULL);
	if (!l)
		l = new;
	else
	{
		last = l;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
	return (l);
}

t_tail	*insert_front(t_tail *l, t_tail *new)
{
	if (!new)
		return (NULL);
	if (!l)
		l = new;
	else
	{
		new->next = l;
		l->prev = new;
		l = new;
	}
	return (l);
}

t_tail	*new_node(int i)
{
	t_tail	*new;

	new = (t_tail *)malloc(sizeof(t_tail));
	if (!new)
		return (NULL);
	new->value = i;
	new->next = NULL;
	new->prev = NULL;
	new->dist = 0;
	new->dist_a = 0;
	new->dist_b = 0;
	return (new);
}

void	printlist(t_tail *head)
{
	t_tail	*tmp;

	tmp = head;
	if (!head)
		return ;
	while (tmp != NULL)
	{
		ft_printf("%d", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
	free(tmp);
}