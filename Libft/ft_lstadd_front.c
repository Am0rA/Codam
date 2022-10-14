/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:22:19 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/14 14:59:43 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp_lst;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	if (!new)
		return ;
	tmp_lst = new;
	while (tmp_lst->next)
		tmp_lst = tmp_lst->next;
	tmp_lst->next = *lst;
	*lst = new;
}
