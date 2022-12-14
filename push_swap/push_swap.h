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
# include "printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_circular
{
	int					desired_i;
	int					content;
	int					distance;
	struct s_circular	*prev;
	struct s_circular	*next;
}				t_circular;

typedef struct s_table
{
	struct s_circular	*a_head;
	struct s_circular	*b_head;
}				t_table;

/*==================================*/
/*				ACTIONS				*/
/*==================================*/

void		ft_s(t_circular **l);
void		ft_r(t_circular **l);
void		ft_rr(t_circular **l);
void		ft_p(t_circular **dst, t_circular **src);
void		apply_double(t_circular **a, t_circular **b, int type);

/*==================================*/
/*				CHECK				*/
/*==================================*/

void		check_input(char **v);
int			sorted(t_table *t);

/*==================================*/
/*				ERROR				*/
/*==================================*/

void		free_list(t_circular **l);
void		free_table(t_table *t);
void		write_error(t_table *t);

/*==================================*/
/*			LIST_ACTIONS			*/
/*==================================*/

int			list_len(t_circular *l);
void		remove_node(t_circular **l);
int			insert_front(t_circular **l, t_circular **n);
int			insert_back(t_circular **l, t_circular **n);
t_circular	*new_node(int value);

/*==================================*/
/*				MAIN				*/
/*==================================*/

int			main(int ac, char **av);

/*==================================*/
/*				NEXT_S-B			*/
/*==================================*/

t_circular	*next_smallest(t_circular *src, t_circular *prev);
t_circular	*next_biggest(t_circular *src, t_circular *prev);

/*==================================*/
/*				PATH_FINDER			*/
/*==================================*/

int			path_len(t_circular	*l, t_circular *obj);
void		path_assign(t_table	*t);
void		path_put(t_table *t);
void		put(t_table *t, t_circular *closest, int c);

/*==================================*/
/*				PUSH_SWAP			*/
/*==================================*/

void		push_swap(t_table *t);

/*==================================*/
/*				TABLE				*/
/*==================================*/

t_table		*t_init(t_table *t, int size, char **argv);

#endif