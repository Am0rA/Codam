/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:06:16 by itopchu       #+#    #+#                 */
/*   Updated: 2022/10/08 17:06:16 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen((char *)needle);
	if (n_len == 0 || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		count = 0;
		while (haystack[i + count] && needle[count]
			&& haystack[i + count] == needle[count]
			&& i + count < len)
			count++;
		if (count == n_len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
