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

static char *waste(char **m, size_t line_size)
{
	size_t	remainder_size;
	char	*remainder_str;

	remainder_size = ft_strlen(*m, '\0') - line_size;
	if (remainder_size == 0 || !ft_strchr(*m, '\n'))
	{
		free(*m);
		return (NULL);
	}
	remainder_str = ft_strdup(*m + line_size);
	free(*m);
	return (remainder_str);
}

static char	*read_line(int fd, char **m)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		if (!*m)
			*m = ft_strdup(buffer);
		else
			*m = ft_strjoin(*m, buffer);
		if (ft_strchr(*m, '\n'))
			return (*m);
	}
	return (*m);
}

static char	*give_line(char **m)
{
	ssize_t	line_size;
	char	*line;

	if (ft_strchr(*m, '\n'))
		line_size = ft_strlen(*m, '\n') + 1;
	else
		line_size = ft_strlen(*m, '\0');
	line = malloc(line_size + 1);
	if (line == NULL)
	{
		free(*m);
		return (line);
	}
	ft_strlcpy(line, *m, line_size + 1);
	*m = waste(m, line_size);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*rtn;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	mem = read_line(fd, &mem);
	if (!mem)
		return (NULL);
	rtn = give_line(&mem);
	return (rtn);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);

	for(int i = 0; i < 15; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
