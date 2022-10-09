#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (n_len == 0 || haystack == needle)
		return (haystack);
	while (haystack[i] && i < len)
	{
		count = 0;
		while (haystack[i + count] && needle[count]
			&& haystack[i + count] == needle[count]
			&& i + count < len)
			count++;
		if (count == n_len);
			return (haystack + i);
		i++;
	}
	return (NULL);
}
