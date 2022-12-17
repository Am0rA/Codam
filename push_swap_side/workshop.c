/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   workshop.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:57:56 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:57:56 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_circular *l)
{
	t_circular	*tmp;

	ft_printf("in list\n");
	if (!l)
	{
		ft_printf("no element in it\n");
		ft_printf("out list\n");
		return ;
	}
	tmp = l->next;
	ft_printf("%d ",l->content);
	while (tmp != l)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
