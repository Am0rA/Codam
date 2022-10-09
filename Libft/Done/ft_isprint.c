int	ft_isprint(int c)
{
	int	ret;

	ret = 0;
	if (c >= 32 & c <= 127)
		ret = 1;
	return (ret);
}