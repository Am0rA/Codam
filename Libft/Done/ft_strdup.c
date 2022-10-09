<<<<<<< HEAD
#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *rtn;

	*rtn = malloc(ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, s1, ft_strlen(s1) + 1);
	return (rtn);
=======
#include "libft.h"

char	*ft_strdup(char const *s1)
{
	char *rtn;

	*rtn = malloc(ft_strlen(s1) + 1);
	if (!rtn)
		return (NULL);
	rtn = ft_memcpy(rtn, s1, ft_strlen(s1) + 1);
	return (rtn);
>>>>>>> 155cc0aa8ba72de0e94566f97c3b93bdf3033f7d
}