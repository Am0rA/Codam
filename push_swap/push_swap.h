/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 18:04:27 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/27 18:04:27 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	long	int		num;
	struct	s_list	*next;
	struct	s_list	*prev;
}				t_list;

typedef	struct	s_table
{
	struct	s_list	*a;
	struct	s_list	*b;
}				t_table;

/*==================================*/
/*				ACTIONS				*/
/*==================================*/

void	ft_s(t_table *t, int i);
void	ft_p(t_table *t, int i);
void	ft_r(t_table *t, int i);
void	ft_rr(t_table *t, int i);

/*==================================*/
/*				ERROR				*/
/*==================================*/

void	free_list(t_list *l);
void	free_table(t_table *t);
void	write_error(t_table *t);

#endif