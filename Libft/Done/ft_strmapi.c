<<<<<<< HEAD
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char	*ret;

	i = 0;
	if (!s || !f)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i++])
		ret = f(i, s[i]);
	return (ret);
=======
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char	*ret;

	i = 0;
	if (!s || !f)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[i++])
		ret = f(i, s[i]);
	return (ret);
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}