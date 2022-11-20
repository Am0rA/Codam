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
		return (free(*m), NULL);
	remainder_str = ft_strdup(*m + line_size);
	free(*m);
	return (remainder_str);
}

static char *read_recur(int fd, char **m)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(m), NULL);
	buffer[bytes_read] = '\0';
	if (!*m)
		*m = ft_strdup(buffer);
	else
		*m = ft_strjoin(*m, buffer);
	if (*m && ft_strchr(*m, '\n') || bytes_read == 0)
		return (*m);
	return (read_recur(fd, m));
}

static char *give_line(char **m)
{
	char	*line;
	int		length;

	if (ft_strchr(*m, '\n'))
		length = ft_strlen(*m, '\n') + 1;
	else
		length = ft_strlen(*m, '\0') ;
	line = malloc((length + 1)*sizeof(char));
	if (!line)
		return (free(*m), NULL);
	ft_strlcpy(line, *m, length + 1);
	*m = waste(m, length);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*rtn;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	mem = read_recur(fd, &mem);
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
