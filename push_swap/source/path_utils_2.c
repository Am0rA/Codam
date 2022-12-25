/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_utils_2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/19 22:18:28 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 22:18:28 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_a(t_table *t, t_tail **anchor)
{
	if ((*anchor)->dist_a > 0)
        rotate(t, 'a');
	else if ((*anchor)->dist_a < 0)
		rotate_reverse(t, 'a');
	path_assign(t);
}

static void	rotate_b(t_table *t, t_tail **anchor)
{
	if ((*anchor)->dist_b > 0)
		rotate(t, 'b');
	else if ((*anchor)->dist_b < 0)
		rotate_reverse(t, 'b');
	path_assign(t);
}

static void	rotate_both(t_table *t, t_tail **anchor)
{
    while ((*anchor)->dist_a != 0 || (*anchor)->dist_b != 0)
    {
        while ((*anchor)->dist_a > 0 && (*anchor)->dist_b > 0)
        {
            rotate(t, 'r');
			path_assign(t);
        }
        while ((*anchor)->dist_a < 0 && (*anchor)->dist_b < 0)
        {
            rotate_reverse(t, 'r');
			path_assign(t);
        }
		rotate_a(t, anchor);
		rotate_b(t, anchor);
	}
}

void	place_anchor(t_table *t, t_tail **anchor)
{
	rotate_both(t, anchor);
	push(&(t->a_head), &(t->b_head), 'a');
}
