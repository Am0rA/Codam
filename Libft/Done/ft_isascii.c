int	ft_isascii(int c)
{
	int	ret;

	ret = 0;
	if (c >= 0 & c <= 177)
		ret = 1;
	return (ret);
}