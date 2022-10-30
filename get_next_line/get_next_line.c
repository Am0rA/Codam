/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 21:24:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/28 04:56:49 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	st_strchri(char *m, char c)
{
	int	i;

	i = 0;
	while (m[i])
		if (m[i++] == c)
			return (i);
	return (-1);
}

static char	*buffer_loop(char *r, char *b, char *m, int fd)
{
	int		check;
	size_t	bytes_read;

	check = st_strchri(m, '\n');
	if (check == -1)
	{
		bytes_read = read(fd, b, BUFFER_SIZE);
		b[bytes_read] = '\0';
		m = ft_strjoin(m, b);
		r = buffer_loop(r, b, m, fd);
	}
	else
	{
		r = ft_substr(m, 0, check);
		m = ft_substr(m, check, ft_strlen(m));
	}
	return (r);
}

char	*get_next_line(int fd)
{
	char		*rtn;
	char		buffer[BUFFER_SIZE + 1];
	static char	*mem;

	rtn = NULL;
	if (!mem)
	{
		mem = ft_strdup("");
		if (!mem)
			return (NULL);
	}
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	rtn = buffer_loop(rtn, buffer, mem, fd);
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
	close(fd);
	return (0);
}
