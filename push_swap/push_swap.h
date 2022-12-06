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

void		ft_s(t_table *t, int i);
void		ft_p(t_table *t, int i);
void		ft_r(t_table *t, int i);
void		ft_rr(t_table *t, int i);

/*==================================*/
/*				CHECK				*/
/*==================================*/

void		check_input(char **v);
int			is_sorted(t_table *t);

/*==================================*/
/*				ERROR				*/
/*==================================*/

void		free_list(t_circular *l);
void		free_table(t_table *t);
void		write_error(t_table *t);

/*==================================*/
/*			LIST_ACTIONS			*/
/*==================================*/

t_circular	*find_beginning(t_circular *l);
int			insert_beginning(t_circular **l, t_circular *new);
int			insert_back(t_circular **l, t_circular *new);
t_circular	*new_node(int value);

/*==================================*/
/*				PUSH_SWAP			*/
/*==================================*/

void		push_swap(int c, char **v);
int			main(int argc, char **argv);

/*==================================*/
/*				TABLE				*/
/*==================================*/

int			t_init(t_table *t, int size, char **argv);

#endif