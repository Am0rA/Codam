/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 14:55:14 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/17 17:21:48 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "include/libft/libft.h"
# include "include/printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_circular
{
	int					content;
	int					dist;
	int					dist_a;
	int					dist_b;
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
void		push(t_circular **dst, t_circular **src, char c);
void		rotate_reverse(t_circular **l, char c);
void		rotate(t_circular **l, char c);
void		swap(t_table *t, char c);

/*==================================*/
/*			LIST_ACTIONS			*/
/*==================================*/
t_circular	*next_biggest(t_circular *src, t_circular *prev);
t_circular	*next_smallest(t_circular *src, t_circular *prev);
/*UTILS*/
int			list_len(t_circular *l);
void		remove_node(t_circular **l);
int			insert_front(t_circular **l, t_circular **n);
int			insert_back(t_circular **l, t_circular **n);
t_circular	*new_node(int value);

/*==================================*/
/*			PATH_FINDER				*/
/*==================================*/
void		path_assign(t_table	*t);
void		place_in_a(t_table *t);
/*PATH_UTILS*/
int			path_in_a(t_circular *l, t_circular *prev);
int			path_in_b(t_circular *l, t_circular *obj);

/*==================================*/
/*			RETURN_CONDITIONS		*/
/*==================================*/
void		check_input(char **v);
int			sorted(t_circular *l, char c);
/*CLEAN*/
void		free_table(t_table *t);
void		free_table(t_table *t);
/*ERROR*/
void		write_error(t_table *t);

/*==================================*/
/*				TABLE				*/
/*==================================*/
t_table		*t_init(t_table *t, int size, char **argv);

#endif