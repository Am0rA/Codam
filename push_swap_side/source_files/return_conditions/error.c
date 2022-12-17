/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 00:46:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 00:46:10 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(t_table *t)
{
	write(1, "Error\n", 6);
	free_table(t);
	exit(-1);
}
