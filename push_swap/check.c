/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 16:35:03 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/02 21:34:28 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_table *t)
{
	if (!t || !t->a)
		return (0);
	while (t->a->next->head != 1)
	{
		if (t->a->next->content < t->a->content)
			return (0);
		t->a = t->a->next;
	}
	return (1);
}

static void	check_singularity(char **v)
{
	int	i;
	int	j;

	i = 1;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			if (ft_atoi(v[i]) == ft_atoi(v[j]))
				write_error(NULL);
			j++;
		}
		i++;
	}
}

static void	check_ints(char **v)
{
	long int	tmp;
	int			i;
	int			j;

	i = 1;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			tmp = ft_atoi(v[j]);
			if (tmp <= -2147483648 || tmp >= 2147483647)
				write_error(NULL);
			j++;
		}
		i++;
	}
}

static void	check_chars(char **v)
{
	int	i;
	int	j;

	i = 1;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (!ft_isdigit(v[i][j]))
				write_error(NULL);
			j++;
		}
		i++;
	}
}

void	check_input(char **v)
{
	check_chars(v);
	check_ints(v);
	check_singularity(v);
}
