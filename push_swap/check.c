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

static void	check_limits(char **v)
{
	int			i;
	int			j;
	long int	check;

	i = 0;
	check = 0;
	while (v[i])
	{
		j = 0;
		if (v[i][j] == '-')
			j++;
		while (v[i][j])
		{
			check = check * 10 + v[i][j] - '0';
			j++;
		}
		i++;
	}
	if (check < 2147483648 || check > 2147483647)
		write_error(NULL);
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
	int			i;
	int			j;

	i = 1;
	while (v[i])
	{
		j = 0;
		if (v[i][j] == '-')
			j++;
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
	check_ints(v);
	check_limits(v);
	check_singularity(v);
}

int	sorted(t_table *t)
{
	t_circular	*tmp;

	tmp = t->a_head;
	while (tmp->content < tmp->next->content && tmp->next != t->a_head)
			tmp = tmp->next;
	if (t->b_head == NULL)
		if (tmp->next != t->a_head && tmp != next_biggest(tmp, NULL))
			return (0);
	return (1);
}
