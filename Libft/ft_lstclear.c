/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 19:00:48 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/14 17:43:49 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_del;

	tmp = *lst;
	while (tmp)
	{
		tmp_del = tmp;
		tmp = tmp->next;
		ft_lstdelone(tmp_del, del);
	}
	*lst = NULL;
}
