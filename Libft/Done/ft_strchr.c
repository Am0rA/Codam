<<<<<<< HEAD
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
=======
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
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
