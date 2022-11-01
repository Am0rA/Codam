/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 21:24:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/01 23:29:35 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	st_strchri(char *m, int c, size_t bytes)
{
	size_t	i;

	i = bytes - BUFFER_SIZE;
	if (bytes - BUFFER_SIZE <= 0)
		i = 0;
	while (m[i])
		if (m[i++] == (char)c)
			return (i);
	return (-1);
}

static char	*buffer_loop(char *b, char **m, int fd, size_t bytes)
{
	int		check;
	char	*r;
	size_t	bytes_read;
	char	*tmp;

	check = st_strchri(*m, '\n', bytes);
	if (check == -1)
	{
		bytes_read = read(fd, b, BUFFER_SIZE);
		if (bytes_read == 0)
			return (NULL);
		b[bytes_read] = '\0';
		tmp = ft_strjoin(*m, b);
		free(*m);
		*m = tmp;
		r = buffer_loop(b, m, fd, bytes + bytes_read);
	}
	else
	{
		r = ft_substr(*m, 0, check);
		tmp = ft_substr(*m + check, 0, bytes);
		free(*m);
		*m = tmp;
	}
	return (r);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	char		buffer[BUFFER_SIZE + 1];
	static char	*mem;
	size_t		bytes;

	if (!mem)
	{
		mem = malloc(BUFFER_SIZE + 1);
		if (!mem)
			return (NULL);
		bytes = read(fd, mem, BUFFER_SIZE);
		mem[bytes] = '\0';
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rtn = buffer_loop(buffer, &mem, fd, bytes);
	free(mem);
	return (rtn);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("\033[0;31mtest line 1: %s\033[0;31m", get_next_line(fd));
	printf("\033[0;32mtest line 2: %s\033[0;32m", get_next_line(fd));
	printf("\033[0;33mtest line 3: %s\033[0;33m", get_next_line(fd));
	printf("\033[0;34mtest line 4: %s\033[0;34m", get_next_line(fd));
	printf("\033[0;35mtest line 5: %s\033[0;35m", get_next_line(fd));
	printf("\033[0;36mtest line 6: %s\033[0;36m", get_next_line(fd));
	printf("\033[0;37mtest line 7: %s\033[0;37m", get_next_line(fd));
	printf("\033[0;38mtest line 8: %s\033[0;38m", get_next_line(fd));
	printf("\033[0;39mtest line 9: %s\033[0;39m", get_next_line(fd));
	close(fd);
	return (0);
}
