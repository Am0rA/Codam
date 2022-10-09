<<<<<<< HEAD
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i++])
		f(i, s[i]);
=======
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i++])
		f(i, s[i]);
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}