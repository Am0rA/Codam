/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 21:26:31 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/16 15:04:10 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

//get_next_line_utils
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c, int var);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char const *s1);
//get_next_line
char	*get_next_line(int fd);

#endif