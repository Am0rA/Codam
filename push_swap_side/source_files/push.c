/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:39:14 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:39:14 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_circular **dst, t_circular **src, char c)
{
	t_circular	*src_next;
	t_circular	*src_prev;

	if (!src)
		return ;
	src_next = (*src)->next;
	src_prev = (*src)->prev;
	src_prev->next = src_next;
	src_next->prev = src_prev;
	insert_front(dst, src);
	*src = src_next;
	ft_printf("p%c\n", c);
}
