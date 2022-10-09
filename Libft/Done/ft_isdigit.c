int	ft_isdigit(int c)
{
	int	ret;

	ret = 0;
	if (c >= '0' & c <= '9')
		ret = 1;
	return (ret);
}