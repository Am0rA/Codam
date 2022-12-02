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

typedef struct s_int_l
{
	long int		num;
	struct s_int_l	*next;
	struct s_int_l	*prev;
}				t_int_l;

typedef struct s_table
{
	struct s_int_l	*a;
	struct s_int_l	*b;
}				t_table;

/*==================================*/
/*				ACTIONS				*/
/*==================================*/

void	ft_s(t_table *t, int i);
void	ft_p(t_table *t, int i);
void	ft_r(t_table *t, int i);
void	ft_rr(t_table *t, int i);

/*==================================*/
/*				CHECK				*/
/*==================================*/

int		check_input(t_table *t, char **v);
int		is_sorted(t_table *t);

/*==================================*/
/*				ERROR				*/
/*==================================*/

void	free_list(t_int_l *l);
void	free_table(t_table *t);
void	write_error(t_table *t);

/*==================================*/
/*				PUSH_SWAP			*/
/*==================================*/

t_table	*get_table(int size, char **args);
void	push_swap(int c, char **v);
int		main(int argc, char **argv);

/*==================================*/
/*				TABLE				*/
/*==================================*/

void	fill_list(t_table *t, char **args, int size);
t_table	*t_init(void);

/*==================================*/
/*				LIST				*/
/*==================================*/

void	list_del_front(t_int_l *l);
int		list_add_front(t_int_l *l, long int var);

#endif