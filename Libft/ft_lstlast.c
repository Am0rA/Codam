/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 18:41:38 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/13 18:41:38 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
	}
	return (lst);
}