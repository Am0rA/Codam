/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/30 16:35:03 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/30 16:35:03 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_table *t)
{
	t_list *tmp;
	if (!tmp)
		return (0);
	while (t->a->num)
	{
		tmp = t->a;
		if (tmp->num > t->a->num)
			return (0);
		t->a = t->a->next;
	}
	return (1);
}

static void	check_singularity(t_table *t, char **v)
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
				write_error(t);
			j++;
		}
		i++;
	}
}

static void	check_ints(t_table *t, char **v)
{
	long int	tmp;
	int	i;
	int	j;

	i = 1;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			tmp = ft_atoi(v[j]);
			if (tmp < -2147483648 || tmp > 2147483647)
				write_error(t);
			j++;
		}
		i++;
	}
}

static void	check_chars(t_table *t, char **v)
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
				write_error(t);
			j++;
		}
		i++;
	}
}

int	check_input(t_table *t, char **v)
{
	check_chars(t, v);
	check_ints(t, v);
	check_singularity(t, v);
	return (is_sorted(t));
}
