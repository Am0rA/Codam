#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 2000;
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];
	int	bytes_read;
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (i <= bytes_read)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
			break;
		i++;
	}
	str = malloc(sizeof(char) * bytes_read);
	while (j <= i)
	{
		str[j] = buffer[j];
		j++;
	}
	str[j] = '\0';
	printf("%s",str);
	return (str);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("test1: %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
