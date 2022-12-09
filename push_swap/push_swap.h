/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/27 18:04:27 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 21:27:23 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_circular
{
	int					head;
	int					content;
	struct s_circular	*prev;
	struct s_circular	*next;
}				t_circular;

typedef struct s_table
{
	struct s_circular	*a;
	struct s_circular	*b;
}				t_table;

/*==================================*/
/*				ACTIONS				*/
/*==================================*/

int			ft_s(t_circular **l);
int			ft_r(t_circular **l);
int			ft_rr(t_circular **l);
int			ft_p(t_circular **dst, t_circular **src);
int 		apply_double(t_circular **a, t_circular **b, int type);

/*==================================*/
/*				CHECK				*/
/*==================================*/

int			is_sorted(t_table *t);
void		check_input(char **v);

/*==================================*/
/*				ERROR				*/
/*==================================*/

void		free_list(t_circular **l);
void		free_table(t_table *t);
void		write_error(t_table *t);

/*==================================*/
/*			LIST_ACTIONS			*/
/*==================================*/

t_circular	*find_beginning(t_circular *l);
void		remove_node(t_circular **l);
int			insert_beginning(t_circular **l, t_circular *new);
int			insert_back(t_circular **l, t_circular *new);
t_circular	*new_node(int value);

/*==================================*/
/*				PUSH_SWAP			*/
/*==================================*/

void		push_swap(t_table *t, int argc);
int			main(int argc, char **argv);

/*==================================*/
/*				TABLE				*/
/*==================================*/

t_table		*t_init(t_table *t, int size, char **argv);

/*==================================*/
/*			SOLVE_SMALL				*/
/*==================================*/

void	sort_small(t_table *t);

#endif