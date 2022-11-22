/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 19:24:10 by itopchu       #+#    #+#                 */
/*   Updated: 2022/11/22 17:52:13 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

size_t	ft_strlen(const char *c, int var)
{
	size_t	ret;

	ret = 0;
	while (c[ret] != (char)var)
		ret++;
	return (ret);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(src, '\0');
	if (dstsize == 0)
		return (s_len);
	while (i < dstsize - 1 && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (s_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*rtn;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen((char *)s1, '\0');
	s2_len = ft_strlen((char *)s2, '\0');
	rtn = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!rtn)
		return (free((char *)s1), NULL);
	ft_strlcpy(rtn, s1, s1_len + 1);
	ft_strlcpy(rtn + s1_len, s2, s2_len + 1);
	free((char *)s1);
	return (rtn);
}

char	*ft_strdup(char const *s1)
{
	char	*rtn;
	size_t	s1_len;

	s1_len = ft_strlen(s1, '\0');
	rtn = (char *)malloc(s1_len + 1);
	if (!rtn)
		return (NULL);
	ft_strlcpy(rtn, s1, s1_len + 1);
	return (rtn);
}
