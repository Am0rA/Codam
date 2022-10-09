char *ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == c)
			return (s[count]);
		count++;
	}
	return (0);
}
