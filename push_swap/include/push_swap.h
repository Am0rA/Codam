/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 14:55:14 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/19 22:58:37 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_tail
{
	int				value;
	int				dist;
	int				dist_a;
	int				dist_b;
	struct s_tail	*prev;
	struct s_tail	*next;
}				t_tail;

typedef struct s_table
{
	struct s_tail	*a_head;
	struct s_tail	*b_head;
}				t_table;

/*==================================*/
/*				ACTIONS				*/
/*==================================*/
void	push(t_tail **dst, t_tail **src, char c);
void	rotate(t_table *t, char c);
void	rotate_reverse(t_table *t, char c);
void	swap(t_table *t, char c);
void	table_init(t_table *t, int size, char **argv);
/*==================================*/
/*				CHECK				*/
/*==================================*/
void	check_input(char **v);
void	write_error(t_table *t);
int		sorted(t_tail *l, char c);
void	free_list(t_tail *l);
void	free_table(t_table *t);
/*==================================*/
/*				LIST_UTILS			*/
/*==================================*/
int		list_len(t_tail *lst);
t_tail	*insert_back(t_tail *l, t_tail *new);
t_tail	*insert_front(t_tail *l, t_tail *new);
t_tail	*new_node(int i);
void	printlist(t_tail *head);
t_tail	*next_biggest(t_tail *src, t_tail *prev);
t_tail	*next_smallest(t_tail *src, t_tail *prev);
t_tail	*delete_node(t_tail *l);
/*==================================*/
/*				MAIN				*/
/*==================================*/
int		main(int ac, char **av);
/*==================================*/
/*				PATH_UTILS			*/
/*==================================*/
int		path_in_a(t_tail *l, t_tail *prev);
int		path_in_b(t_tail *l, t_tail *obj);
void	path_assign(t_table	*t);
void	place_anchor(t_table *t, t_tail **anchor);
/*==================================*/
/*				PUSH_SWAP			*/
/*==================================*/
void	push_swap(t_table *t);

#endif