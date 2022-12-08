/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solve_small.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 16:47:24 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/08 16:47:24 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_table *t)
{
	if (t->a->content > t->a->next->content
		&& t->a->content < t->a->next->next->content)
		ft_s(t, 'a');

}