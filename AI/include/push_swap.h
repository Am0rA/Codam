/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 14:55:14 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/24 21:33:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_circular
{
	int					value;
	int					dist;
	int					dist_a;
	int					dist_b;
	struct s_circular	*prev;
	struct s_circular	*next;
}				t_circular;

typedef struct s_table
{
	struct s_circular	*a;
	struct s_circular	*b;
}				t_table;

void		print_list(t_circular *l);
/*==================================*/
/*				ACTIONS				*/
/*==================================*/
void		push(t_circular **dst, t_circular **src, char c);
void		rotate(t_table *t, char c);
void		rotate_reverse(t_table *t, char c);
void		swap(t_table *t, char c);
/*==================================*/
/*				CHECK				*/
/*==================================*/
void		check(char **v);
void		write_error(t_table **t);
void		free_table(t_table *t);
void		free_list(t_circular *l);
int			sorted(t_circular *l, char c);
/*==================================*/
/*				HELPER				*/
/*==================================*/
int			give_abs(int number);
int			distance_to_head(t_circular *l, t_circular *obj);
void		sort_triple(t_table *t);
int			list_len(t_circular *l);
void		place_anchor(t_table *t, t_circular **anchor);
/*==================================*/
/*				LIST_UTILS			*/
/*==================================*/
t_circular	*next_smallest(t_circular *src, t_circular *prev);
t_circular	*next_biggest(t_circular *src, t_circular *prev);
t_circular	*biggest(t_circular *src);
t_circular	*smallest(t_circular *src);
/*==================================*/
/*				MAIN				*/
/*==================================*/
int			main(int ac, char **av);
/*==================================*/
/*				PUSH_SWAP			*/
/*==================================*/
void		push_swap(t_table *t);
void		set_dist(t_table *t);
void		place_in_b(t_table *t);
void		place_in_a(t_table *t);
/*==================================*/
/*				TABLE_INIT			*/
/*==================================*/
t_table		*table_init(int ac, char **av);
t_circular	*insert(t_circular **l, t_circular **new);
t_circular	*extract(t_circular **l);
t_circular	*new_node(int value);

#endif