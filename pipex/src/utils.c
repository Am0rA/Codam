/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/31 04:46:42 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/31 04:46:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_vector(char **obj)
{
	int	i;

	i = 0;
	while(obj[i])
		free(obj[i++]);
	free(obj);
}

