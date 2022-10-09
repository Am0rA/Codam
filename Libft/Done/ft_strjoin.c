<<<<<<< HEAD
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen(s1) + ft_strlen(s2) == NULL)
		return (NULL);
	*ret = (*char)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while(s1[i++])
		ret[i] = s1[i];
	while (s2[j++])
		ret[i + j] = s2[j];
	ret[i + j] = '/0';
	return (ret);
=======
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen(s1) + ft_strlen(s2) == NULL)
		return (NULL);
	*ret = (*char)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while(s1[i++])
		ret[i] = s1[i];
	while (s2[j++])
		ret[i + j] = s2[j];
	ret[i + j] = '/0';
	return (ret);
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}