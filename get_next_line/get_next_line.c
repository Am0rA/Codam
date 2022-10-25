/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 21:24:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/25 22:37:42 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (i);
	return (i);
}

char	*ft_str_shorten(const char *s, int x)
{
	char	*test

	test malloc;

	while (i < x)
		test = s

	return test;
}

int	buffer_loop(char *str, char *buffer, int fd)
{
	int		read_v;
	int		i;
	int		check;

	i = 0;
	read_v = read(fd, buffer, BUFFER_SIZE);
	check = ft_strichr(buffer, '\n');
	if (check <= read_v)
		buffer = (ft_str_shorten(buffer, check);
	str = ft_strjoin(str, buffer);
	if (read_v <= check && check == BUFFER_SIZE)
		read_v += buffer_loop(str, buffer, fd);
	if (check < read_v)
		read_v = check;
	return (read_v);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];
	int		read_v;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	read_v = read(fd, buffer, BUFFER_SIZE);
	read_v += buffer_loop(buffer, buffer, fd);
	str = malloc(sizeof(char) * (read_v + 1));
	if (!str)
		return (NULL);
	buffer_loop(str, buffer, fd);
	return (str);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("\nTHIS IS IN MAIN\n");
	get_next_line(fd);
	//printf("test line 1: %s\n", get_next_line(fd));
	// printf("test line 2: %s\n", get_next_line(fd));
	// printf("test line 3: %s\n", get_next_line(fd));
	// printf("test line 4: %s\n", get_next_line(fd));
	return (0);
}
