/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 02:39:55 by itopchu       #+#    #+#                 */
/*   Updated: 2022/12/30 02:39:55 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define NOT_FOUND 127

typedef enum e_pipe
{
	WRITE = 1,
	READ = 0
}	t_pipe;

/*==================================*/
/*				MAIN				*/
/*==================================*/
int		main(int ac, char **av, char **envp);
/*==================================*/
/*				PIPEX				*/
/*==================================*/
void	pipex(t_data *data);

#endif