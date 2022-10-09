#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char 	*str;
	size_t	i;
	size_t	j;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
	{
		i++;
		j++;
		str[j] = s[i];
	}
	str[j] = '\0';
	return (str);
}