int	ft_strlen(char *c)
{
	int	ret;

	ret = 0;
	while (*c++)
		ret++;
	return (ret);
}